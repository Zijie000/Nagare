module nagare/io/file

import std/os/path
import std/os/dir
import std/os/file
import nagare/core/types
import nagare/core/stream
import nagare/io/file_effect

// ---------------------------------------------------------------------------
// All file/fs operations are expressed in the `fileIO` effect. Users install
// a handler (e.g. `defaultFileIO`) before compiling a stream:
//
//     with defaultFileIO
//     readLines("foo.txt".path).compile.drain()
//
// Tests/mocks can install their own handler that intercepts `readChunk`,
// `with-read-file`, etc. without touching the filesystem.
// ---------------------------------------------------------------------------

// Raw byte sequence: a chunk of arbitrary binary data.
pub alias bytes = vector<int8>

// ---------------------------------------------------------------------------
// Binary (bytes) read/write
// ---------------------------------------------------------------------------

// Loop reading byte chunks from an open read-handle until EOF.
fun readPullBytes(h : read-handle, chunkSize : int) : div pull<bytes, <fileRead|io>>
  PEval(fn()
    val chunk = readChunkBytes(h, chunkSize)
    if chunk.length == 0 then PDone
    else POutput(Chunk([chunk]), readPullBytes(h, chunkSize))
  )

// Read a file as a truly lazy stream of byte chunks (resource-safe, one chunk at a time).
pub fun readAllStreamingBytes(filepath : path, chunkSize : int = 4096) : readStream<bytes>
  Stream(PEval(fn()
    val hRef : ref<global, maybe<read-handle>> = ref(Nothing)
    PAcquire(
      fn() { hRef := Just(openRead(filepath.string)) },
      fn() { match !hRef { Just(h) -> closeRead(h); Nothing -> () } },
      PEval(fn() { match !hRef { Just(h) -> readPullBytes(h, chunkSize); Nothing -> PDone } })
    )
  ))

// Helper: drain the read-handle into a list of byte chunks.
fun readAllChunksBytes(h : read-handle, chunkSize : int, acc : list<bytes>) : <fileRead|io> list<bytes>
  val chunk = readChunkBytes(h, chunkSize)
  if chunk.length == 0 then acc.reverse
  else readAllChunksBytes(h, chunkSize, Cons(chunk, acc))

// Read a file eagerly into byte chunks (not lazy — use readAllStreamingBytes for large files).
pub fun readAllBytes(filepath : path, chunkSize : int = 4096) : readStream<bytes>
  Stream(PEval(fn()
    with-read-file(filepath.string, fn(h)
      val chunks = readAllChunksBytes(h, chunkSize, [])
      POutput(Chunk(chunks), PDone)
    )
  ))

// Write a stream of byte chunks to a file.
pub fun writeAllBytes(filepath : path) : writePipe<bytes, ()>
  fn(source)
    Stream(PEval(fn()
      with-write-file(filepath.string, fn(h)
        writeAllChunksBytes(source.toPull, h)
        POutput(Chunk([()]), PDone)
      )
    ))

fun writeAllChunksBytes(source : pull<bytes, <fileWrite|io>>, h : write-handle) : <fileWrite|io> ()
  match source
    PDone -> ()
    POutput(out, tail) ->
      match out
        Chunk(values) ->
          values.foreach(fn(b) { writeChunkBytes(h, b); () })
          writeAllChunksBytes(tail, h)
    PEval(next) ->
      writeAllChunksBytes(next(), h)
    PAcquire(acquire, release, tail) ->
      acquire()
      finally(release, { writeAllChunksBytes(tail, h) })

// ---------------------------------------------------------------------------
// Text ↔ bytes bridge
// ---------------------------------------------------------------------------

// Decode a stream of byte chunks into UTF-8 strings.
// Handles multi-byte codepoints split across chunk boundaries by carrying
// incomplete leading bytes in a per-step leftover list.
pub fun decodeUtf8<e>(source : nstream<bytes,e>) : nstream<string,e>
  match source
    Stream(step) -> Stream(decodeUtf8Pull(step, []))

fun decodeUtf8Pull<e>(source : pull<bytes,e>, leftover : list<int8>) : pull<string,e>
  match source
    PDone ->
      if leftover.is-empty then PDone
      else POutput(Chunk(["�"]), PDone)
    POutput(out, tail) ->
      match out
        Chunk(chunks) ->
          val combined = chunks.foldl(leftover, fn(acc, b) acc ++ b.vlist)
          val (text, rest) = trydecode-utf8-partial(combined)
          if text.is-empty
          then decodeUtf8Pull(tail, rest)
          else POutput(Chunk([text]), decodeUtf8Pull(tail, rest))
    PEval(next) ->
      PEval(fn() decodeUtf8Pull(next(), leftover))
    PAcquire(acquire, release, tail) ->
      PAcquire(acquire, release, decodeUtf8Pull(tail, leftover))

// Decode as many complete UTF-8 codepoints as possible from a byte list.
// Returns (decoded-string, leftover-incomplete-bytes).
// We pass the full buffer to the C FFI which handles UTF-8 reconstruction;
// any trailing incomplete sequence is returned as leftover for the next chunk.
fun trydecode-utf8-partial(buf : list<int8>) : (string, list<int8>)
  if buf.is-empty then ("", [])
  else
    val vec = buf.vector
    val s   = nagare-bytes-to-string(vec)
    val consumed = nagare-string-to-bytes(s).vlist.length
    val rest = buf.drop(consumed)
    (s, rest)

// Loop reading chunks from an open read-handle until EOF.
fun readPull(h : read-handle, chunkSize : int) : div pull<string, <fileRead|io>>
  PEval(fn()
    val chunk = readChunk(h, chunkSize)
    if chunk.is-empty then PDone
    else POutput(Chunk([chunk]), readPull(h, chunkSize))
  )

// Split a string by newlines, returning (complete-lines, leftover).
fun splitByNewline(s : string) : (list<string>, string)
  val parts = s.split("\n")
  match parts
    [] -> ([], "")
    [single] -> ([], single)
    _ ->
      val init = parts.init
      val last = parts.last.default("")
      (init, last)

// Build a pull that splits incoming string chunks into lines.
fun splitLinesPull<e>(source : pull<string,e>, buffer : string) : pull<string,e>
  match source
    PDone ->
      if buffer.is-empty then PDone
      else POutput(Chunk([buffer]), PDone)
    POutput(out, tail) ->
      match out
        Chunk(values) ->
          val combined = buffer ++ values.join("")
          val (lines, leftover) = splitByNewline(combined)
          match lines
            [] -> splitLinesPull(tail, leftover)
            _  -> POutput(Chunk(lines), splitLinesPull(tail, leftover))
    PEval(next) ->
      PEval(fn() splitLinesPull(next(), buffer))
    PAcquire(acquire, release, tail) ->
      PAcquire(acquire, release, splitLinesPull(tail, buffer))

// ---------------------------------------------------------------------------
// Read operations
// ---------------------------------------------------------------------------

// Read a file as a stream of string chunks.
// `with-read-file` owns open+close; `readChunk` operates on the open handle.
pub fun readAll(filepath : path, chunkSize : int = 4096) : readStream<string>
  Stream(PEval(fn()
    with-read-file(filepath.string, fn(h)
      // Drain the handle eagerly into a single chunk pull. This is the simplest
      // correct shape under resource-scoped `with-read-file`: the handler closes
      // the file as soon as this body returns, so we can't leave a lazy PEval
      // tail holding `h`. For true chunked streaming, use `readAllStreaming`.
      val chunks = readAllChunks(h, chunkSize, [])
      POutput(Chunk(chunks), PDone)
    )
  ))

// Helper: drain the read-handle into a list of chunks.
fun readAllChunks(h : read-handle, chunkSize : int, acc : list<string>) : <fileRead|io> list<string>
  val chunk = readChunk(h, chunkSize)
  if chunk.is-empty then acc.reverse
  else readAllChunks(h, chunkSize, Cons(chunk, acc))

// Read a file as a stream of lines (splits on newline boundaries).
pub fun readLines(filepath : path, chunkSize : int = 4096) : readStream<string>
  readAllStreaming(filepath, chunkSize).through(splitLines)

// Split a stream of string chunks into a stream of lines.
pub fun splitLines<e>(source : nstream<string,e>) : nstream<string,e>
  match source
    Stream(step) -> Stream(splitLinesPull(step, ""))

// Read a file as a truly lazy stream of chunks: the handle is opened once,
// held by PAcquire for its lifetime, and closed by the interpreter when the
// stream finishes or is truncated by take/takeWhile. Only one chunk lives in
// memory at a time — this is the streaming-safe alternative to readAll.
pub fun readAllStreaming(filepath : path, chunkSize : int = 4096) : readStream<string>
  // A ref lets the three lambdas (acquire, release, tail) share the handle
  // without it escaping the PAcquire bracket.
  Stream(PEval(fn()
    val hRef : ref<global, maybe<read-handle>> = ref(Nothing)
    PAcquire(
      fn() { hRef := Just(openRead(filepath.string)) },
      fn() { match !hRef { Just(h) -> closeRead(h); Nothing -> () } },
      PEval(fn() { match !hRef { Just(h) -> readPull(h, chunkSize); Nothing -> PDone } })
    )
  ))

// Read entire file content as a single string element.
pub fun readUtf8(filepath : path) : readStream<string>
  eval(fn() readTextFileOp(filepath.string))

// ---------------------------------------------------------------------------
// Write operations
// ---------------------------------------------------------------------------

// Write a stream of string chunks to a file.
pub fun writeAll(filepath : path) : writePipe<string, ()>
  fn(source)
    Stream(PEval(fn()
      with-write-file(filepath.string, fn(h)
        writeAllChunks(source.toPull, h)
        POutput(Chunk([()]), PDone)
      )
    ))

// Drain the source pull, writing every emitted string to the handle.
// We let the outer runtime handle PAcquire bookkeeping when possible; here
// we simply run acquire/release inline around the recursive call.
fun writeAllChunks(source : pull<string, <fileWrite|io>>, h : write-handle) : <fileWrite|io> ()
  match source
    PDone -> ()
    POutput(out, tail) ->
      match out
        Chunk(values) ->
          values.foreach(fn(s) { writeChunk(h, s); () })
          writeAllChunks(tail, h)
    PEval(next) ->
      writeAllChunks(next(), h)
    PAcquire(acquire, release, tail) ->
      acquire()
      finally(release, { writeAllChunks(tail, h) })

// Write a stream of strings as lines (appends newline to each element).
pub fun writeLines(filepath : path) : writePipe<string, ()>
  fn(source)
    source.map(fn(line) line ++ "\n").through(writeAll(filepath))

// Alias for writeAll (Koka strings are UTF-8).
pub fun writeUtf8(filepath : path) : writePipe<string, ()>
  writeAll(filepath)

// ---------------------------------------------------------------------------
// Filesystem operations
// ---------------------------------------------------------------------------

pub fun listDir(dir : path) : fsStream<path>
  eval(fn() listChildren(dir.string, False, 1)).flatMap(fn(entries) emits(entries))

pub fun walk(dir : path, maxDepth : int = 1000) : fsStream<path>
  eval(fn() listChildren(dir.string, True, maxDepth)).flatMap(fn(entries) emits(entries))

pub fun pathExists(filepath : path) : fsStream<bool>
  eval(fn() fileExistsOp(filepath.string))

pub fun createDir(dir : path) : iostream<()>
  // `ensure-dir` is a plain std/os op — no file capability needed.
  eval(fn() std/os/dir/ensure-dir(dir))

pub fun fileCopy(from : path, to : path) : iostream<()>
  eval(fn() std/os/dir/copy-file(from, to))

pub fun deleteFile(filepath : path) : fsStream<()>
  eval(fn() removeFileOp(filepath.string))
