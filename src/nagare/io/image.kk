module nagare/io/image

import std/os/path
import nagare/core/types
import nagare/core/stream
import nagare/io/file_effect
import nagare/io/file
import nagare/io/image_effect

// ---------------------------------------------------------------------------
// Image decoding.
//
// PNG / JPEG / BMP / GIF / TGA / PSD all require the full file in memory
// before they can be decoded — there is no chunk-by-chunk decoder for them
// (DEFLATE windows, Huffman tables, and inter-row filters all forbid it).
//
// We follow fs2's naming convention to advertise this honestly:
//
//   `readAll`             — eager, buffers the file
//   `readAllStreaming`    — lazy, chunk-by-chunk
//   `decodeImageAll`      — consumes the entire upstream byte stream,
//                           then emits exactly one `image`
//
// The `All` suffix is the signal: "this operator collects its input before
// producing output". Streaming benefits show up at the *batch* level
// (decoding a directory of images is streaming over the *file list*,
// even though each individual file is decoded all-at-once).
// ---------------------------------------------------------------------------

// Concatenate two byte vectors. Used to accumulate chunks before decoding.
fun concatBytes( a : bytes, b : bytes ) : bytes
  (a.vlist ++ b.vlist).vector

// Drain an upstream byte pull into a single bytes buffer.
fun collectBytesPull<e>( source : pull<bytes,<imageDecode|e>>, acc : bytes ) : <imageDecode|e> bytes
  match source
    PDone -> acc
    POutput(out, tail) ->
      match out
        Chunk(values) ->
          val next = values.foldl(acc, fn(b, c) concatBytes(b, c))
          collectBytesPull(tail, next)
    PEval(next) ->
      collectBytesPull(next(), acc)
    PAcquire(acquire, release, tail) ->
      acquire()
      finally(release, { collectBytesPull(tail, acc) })

// ---------------------------------------------------------------------------
// `decodeImageAll`: the "all-at-once" decode pipe.
//
// Mirrors the shape of `decodeUtf8` so the two compose interchangeably with
// any byte source — but the `All` suffix flags that this one is *not*
// incremental. The whole upstream is consumed before the single `image` is
// emitted.
// ---------------------------------------------------------------------------

pub fun decodeImageAll<e>( source : nstream<bytes, <imageDecode|e>> ) : nstream<image, <imageDecode|e>>
  match source
    Stream(step) ->
      Stream(PEval(fn()
        val all = collectBytesPull(step, vector(0, 0.int8))
        if all.length == 0 then PDone
        else
          val img = decodeImageBytes(all)
          POutput(Chunk([img]), PDone)
      ))

// ---------------------------------------------------------------------------
// File-system convenience wrappers.
// ---------------------------------------------------------------------------

// Pull bytes from an open read-handle until EOF. Row-polymorphic so it can
// be lifted into pipelines that also carry `imageDecode` (or any other
// capability) — `readAllStreamingBytes` from `file.kk` pins its row to
// `<fileRead|io>`, which can't be widened at a call site.
fun readImageBytesPull( h : read-handle, chunkSize : int ) : div pull<bytes, <fileRead, imageDecode|io>>
  PEval(fn()
    val chunk = readChunkBytes(h, chunkSize)
    if chunk.length == 0 then PDone
    else POutput(Chunk([chunk]), readImageBytesPull(h, chunkSize))
  )

// Lazy byte-chunk source over a file. The row is `<fileRead, imageDecode|io>`
// so it composes directly with `decodeImageAll` — `readAllStreamingBytes`
// from `file.kk` pins its row to `<fileRead|io>` (no imageDecode), and Koka
// can't widen a fixed row at the call site.
fun readImageBytes( filepath : path, chunkSize : int = 4096 ) : nstream<bytes, <fileRead, imageDecode|io>>
  Stream(PEval(fn()
    val hRef : ref<global, maybe<read-handle>> = ref(Nothing)
    PAcquire(
      fn() { hRef := Just(openRead(filepath.string)) },
      fn() { match !hRef { Just(h) -> closeRead(h); Nothing -> () } },
      PEval(fn() { match !hRef { Just(h) -> readImageBytesPull(h, chunkSize); Nothing -> PDone } })
    )
  ))

// Read one image file and decode it. The result stream emits exactly one
// `image` (or zero if the file was empty / undecodable).
pub fun readImage( filepath : path ) : nstream<image, <fileRead, imageDecode|io>>
  readImageBytes(filepath).decodeImageAll
