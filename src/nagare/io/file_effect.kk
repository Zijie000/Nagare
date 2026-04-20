module nagare/io/file_effect

import std/os/path
import std/os/dir
import std/os/file
import nagare/core/types

extern import
  c file "file-inline.c"

// ---------------------------------------------------------------------------
// Raw C FFI. Kept local to this module — the rest of the codebase uses
// the `fileIO` effect below instead of calling these directly.
// ---------------------------------------------------------------------------

extern nagare-fopen-read(p : string) : io intptr_t
  c "nagare_fopen_read"

extern nagare-fopen-write(p : string) : io intptr_t
  c "nagare_fopen_write"

extern nagare-fread-chunk(h : intptr_t, size : int) : io string
  c "nagare_fread_chunk"

extern nagare-fwrite-chunk(h : intptr_t, content : string) : io int
  c "nagare_fwrite_chunk"

extern nagare-fclose(h : intptr_t) : io ()
  c "nagare_fclose"

extern nagare-remove(p : string) : io ()
  c "nagare_remove"

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
// The fileIO effect.
//
// `withReadFile`/`withWriteFile` are resource-scoped — they own the open/close
// pairing so the handle cannot escape. `readChunk`/`writeChunk` operate on an
// already-open handle. Filesystem ops (`fileExists`, `removeFile`, ...) don't
// need a handle and are plain `fun`.
// ---------------------------------------------------------------------------

// Flat primitive ops: handler-scoped bracket is implemented in `with-read-file`
// and `with-write-file` helpers below (as plain Koka functions, not effect ops),
// using `finally` for pairing. This keeps the effect signature simple — every
// op is `fun`, no `ctl`/continuation gymnastics.
pub effect fileIO
  fun openRead( path : string ) : read-handle
  fun openWrite( path : string ) : write-handle
  fun closeRead( h : read-handle ) : ()
  fun closeWrite( h : write-handle ) : ()
  fun readChunk( h : read-handle, size : int ) : string
  fun writeChunk( h : write-handle, content : string ) : int
  fun fileExistsOp( p : string ) : bool
  fun removeFileOp( p : string ) : ()
  fun listChildren( p : string, recursive : bool, maxDepth : int ) : list<path>
  fun readTextFileOp( p : string ) : string

// Convenience aliases: tell readers which effects a file stream carries.
// `fileStream<a>` — a stream that reads/writes files and performs io.
// `filePipe<a,b>` — a file-IO transformation segment.
pub alias fileStream<a> = nstream<a, <fileIO|io>>
pub alias filePipe<a,b> = pipe<a, b, <fileIO|io>>

// Resource-scoped read: guarantees close even if body raises.
pub fun with-read-file( path : string, body : read-handle -> <fileIO|e> a ) : <fileIO|e> a
  val h = openRead(path)
  finally({ closeRead(h) }, { body(h) })

// Resource-scoped write: guarantees close even if body raises.
pub fun with-write-file( path : string, body : write-handle -> <fileIO|e> a ) : <fileIO|e> a
  val h = openWrite(path)
  finally({ closeWrite(h) }, { body(h) })

// ---------------------------------------------------------------------------
// Default handler: bridges ops back to the C FFI. This is the handler that
// `readAll`/`writeAll`/etc. install internally so the public API stays
// `iostream<string>`.
// ---------------------------------------------------------------------------

pub fun defaultFileIO( action : () -> <fileIO|io> a ) : io a
  with handler
    fun openRead(p)
      ReadHandle(nagare-fopen-read(p))
    fun openWrite(p)
      WriteHandle(nagare-fopen-write(p))
    fun closeRead(h)
      nagare-fclose(h.fd)
    fun closeWrite(h)
      nagare-fclose(h.fd)
    fun readChunk(h, size)
      nagare-fread-chunk(h.fd, size)
    fun writeChunk(h, content)
      nagare-fwrite-chunk(h.fd, content)
    fun fileExistsOp(p)
      is-file(p.path) || is-directory(p.path)
    fun removeFileOp(p)
      nagare-remove(p)
    fun listChildren(p, recursive, maxDepth)
      if recursive then list-directory-recursive(p.path, maxDepth)
      else list-directory(p.path)
    fun readTextFileOp(p)
      read-text-file(p.path)
  action()
