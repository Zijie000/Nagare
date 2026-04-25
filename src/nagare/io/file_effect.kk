module nagare/io/file_effect

import std/os/path
import std/os/dir
import std/os/file
import nagare/core/types

extern import
  c file "file-inline.c"

// ---------------------------------------------------------------------------
// Raw C FFI. Kept local to this module — the rest of the codebase uses
// the capability effects (`fileRead`, `fileWrite`, `fileSystem`) below instead
// of calling these directly.
// ---------------------------------------------------------------------------

extern nagare-fopen-read(p : string) : io intptr_t
  c "nagare_fopen_read"

extern nagare-fopen-write(p : string) : io intptr_t
  c "nagare_fopen_write"

extern nagare-fread-chunk(h : intptr_t, size : int) : io string
  c "nagare_fread_chunk"

extern nagare-fread-chunk-bytes(h : intptr_t, size : int) : io vector<int8>
  c "nagare_fread_chunk_bytes"

extern nagare-fwrite-chunk(h : intptr_t, content : string) : io int
  c "nagare_fwrite_chunk"

extern nagare-fwrite-chunk-bytes(h : intptr_t, content : vector<int8>) : io int
  c "nagare_fwrite_chunk_bytes"

extern nagare-fclose(h : intptr_t) : io ()
  c "nagare_fclose"

extern nagare-remove(p : string) : io ()
  c "nagare_remove"

pub extern nagare-bytes-to-string(v : vector<int8>) : string
  c "nagare_bytes_to_string"

pub extern nagare-string-to-bytes(s : string) : vector<int8>
  c "nagare_string_to_bytes"

// ---------------------------------------------------------------------------
// Abstract handle types. Users cannot construct these — the only way to get
// one is through `withReadFile` / `withWriteFile`, which pair open+close.
// This prevents the `intptr_t`-ref hack that used to live in file.kk.
// ---------------------------------------------------------------------------

pub value type read-handle
  con ReadHandle( fd : intptr_t )

pub value type write-handle
  con WriteHandle( fd : intptr_t )

// ---------------------------------------------------------------------------
// Capability effects.
//
// The file surface is split into three orthogonal capabilities so stream
// signatures convey exactly which privileges they require:
//
//   - `fileRead`    — open/close/read a file + read its text
//   - `fileWrite`   — open/close/write a file
//   - `fileSystem`  — existence, removal, directory listing
//
// A read-only pipeline carries `<fileRead|io>`; it cannot even type-check a
// call to `writeChunk`. This is row polymorphism doing real work: capability
// minimisation at the type level with zero runtime overhead.
//
// `fileIO` is kept as an alias that unions the three — any code that used to
// depend on the combined effect keeps working unchanged.
// ---------------------------------------------------------------------------

pub effect fileRead
  fun openRead( path : string ) : read-handle
  fun closeRead( h : read-handle ) : ()
  fun readChunk( h : read-handle, size : int ) : string
  fun readChunkBytes( h : read-handle, size : int ) : vector<int8>
  fun readTextFileOp( p : string ) : string

pub effect fileWrite
  fun openWrite( path : string ) : write-handle
  fun closeWrite( h : write-handle ) : ()
  fun writeChunk( h : write-handle, content : string ) : int
  fun writeChunkBytes( h : write-handle, content : vector<int8> ) : int

pub effect fileSystem
  fun fileExistsOp( p : string ) : bool
  fun removeFileOp( p : string ) : ()
  fun listChildren( p : string, recursive : bool, maxDepth : int ) : list<path>

// Legacy combined alias — `fileIO` now means "all three capabilities".
// Existing code written against `<fileIO|io>` continues to compile.
pub alias fileIO = <fileRead,fileWrite,fileSystem>

// ---------------------------------------------------------------------------
// Row aliases: tell readers which capabilities a stream carries.
// ---------------------------------------------------------------------------

// Read-only stream: opens/reads files, nothing else.
pub alias readStream<a> = nstream<a, <fileRead|io>>
pub alias readPipe<a,b> = pipe<a, b, <fileRead|io>>

// Write-only stream: consumes values and writes them.
pub alias writeStream<a> = nstream<a, <fileWrite|io>>
pub alias writePipe<a,b> = pipe<a, b, <fileWrite|io>>

// Filesystem metadata stream: lists, exists, remove.
pub alias fsStream<a> = nstream<a, <fileSystem|io>>

// Legacy combined aliases — a stream that may exercise any file capability.
pub alias fileStream<a> = nstream<a, <fileIO|io>>
pub alias filePipe<a,b> = pipe<a, b, <fileIO|io>>

// ---------------------------------------------------------------------------
// Resource-scoped bracket helpers (unchanged API).
// ---------------------------------------------------------------------------

pub fun with-read-file( path : string, body : read-handle -> <fileRead|e> a ) : <fileRead|e> a
  val h = openRead(path)
  finally({ closeRead(h) }, { body(h) })

pub fun with-write-file( path : string, body : write-handle -> <fileWrite|e> a ) : <fileWrite|e> a
  val h = openWrite(path)
  finally({ closeWrite(h) }, { body(h) })

// ---------------------------------------------------------------------------
// Default handlers. Each capability has its own handler; the combined
// `defaultFileIO` installs all three so existing call sites keep working.
// ---------------------------------------------------------------------------

pub fun defaultFileRead( action : () -> <fileRead|io> a ) : io a
  with handler
    fun openRead(p)
      ReadHandle(nagare-fopen-read(p))
    fun closeRead(h)
      nagare-fclose(h.fd)
    fun readChunk(h, size)
      nagare-fread-chunk(h.fd, size)
    fun readChunkBytes(h, size)
      nagare-fread-chunk-bytes(h.fd, size)
    fun readTextFileOp(p)
      read-text-file(p.path)
  action()

pub fun defaultFileWrite( action : () -> <fileWrite|io> a ) : io a
  with handler
    fun openWrite(p)
      WriteHandle(nagare-fopen-write(p))
    fun closeWrite(h)
      nagare-fclose(h.fd)
    fun writeChunk(h, content)
      nagare-fwrite-chunk(h.fd, content)
    fun writeChunkBytes(h, content)
      nagare-fwrite-chunk-bytes(h.fd, content)
  action()

pub fun defaultFileSystem( action : () -> <fileSystem|io> a ) : io a
  with handler
    fun fileExistsOp(p)
      is-file(p.path) || is-directory(p.path)
    fun removeFileOp(p)
      nagare-remove(p)
    fun listChildren(p, recursive, maxDepth)
      if recursive then list-directory-recursive(p.path, maxDepth)
      else list-directory(p.path)
  action()

// Combined handler: installs all three capabilities. Call sites that only
// need one of them should prefer the narrower handler.
pub fun defaultFileIO( action : () -> <fileIO|io> a ) : io a
  with handler
    fun openRead(p)
      ReadHandle(nagare-fopen-read(p))
    fun closeRead(h)
      nagare-fclose(h.fd)
    fun readChunk(h, size)
      nagare-fread-chunk(h.fd, size)
    fun readChunkBytes(h, size)
      nagare-fread-chunk-bytes(h.fd, size)
    fun readTextFileOp(p)
      read-text-file(p.path)
  with handler
    fun openWrite(p)
      WriteHandle(nagare-fopen-write(p))
    fun closeWrite(h)
      nagare-fclose(h.fd)
    fun writeChunk(h, content)
      nagare-fwrite-chunk(h.fd, content)
    fun writeChunkBytes(h, content)
      nagare-fwrite-chunk-bytes(h.fd, content)
  with handler
    fun fileExistsOp(p)
      is-file(p.path) || is-directory(p.path)
    fun removeFileOp(p)
      nagare-remove(p)
    fun listChildren(p, recursive, maxDepth)
      if recursive then list-directory-recursive(p.path, maxDepth)
      else list-directory(p.path)
  action()
