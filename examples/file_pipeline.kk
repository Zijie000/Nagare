// file_pipeline.kk — File IO with capability-split effects
//
// Run: koka -e --builddir=.koka -isrc examples/file_pipeline.kk
//
// Nagare splits file access into three orthogonal capabilities:
//
//   fileRead   — open/read/close a file
//   fileWrite  — open/write/close a file
//   fileSystem — listDir, pathExists, deleteFile
//
// A read-only pipeline is typed `nstream<a, <fileRead|io>>` — it cannot even
// type-check a call to `writeChunk`, so misuse is caught at compile time.
//
// This example shows the capability-aware aliases in action:
//   readStream<a>  = nstream<a, <fileRead|io>>
//   writePipe<a,b> = pipe<a, b, <fileWrite|io>>
//   fsStream<a>    = nstream<a, <fileSystem|io>>

module file_pipeline

import std/os/path
import nagare/core/types
import nagare/core/stream
import nagare/core/interpreter
import nagare/io/file
import nagare/io/file_effect

pub fun main() : io ()
  val inFile  = "tests/test_input.txt".path
  val outFile = "/tmp/nagare_out.txt".path

  // ── 1. Read lines, count and print ───────────────────────────────────────
  // `readLines` returns a `readStream<string>` — the `<fileRead|io>` row makes
  // the capability requirement visible in the type.  `defaultFileRead` is the
  // only handler that discharges it.
  println("=== reading lines ===")
  val lineCount =
    with defaultFileRead
    readLines(inFile)
      .evalTap(fn(line) println("  " ++ line))
      .compile.fold(0, fn(acc, _) acc + 1)
  println("total lines: " ++ show(lineCount))
  println("")

  // ── 2. Lazy streaming read: take stops after the first chunk ──────────────
  // `readAllStreaming` holds the file handle in a `PAcquire` bracket.
  // `take(1)` stops the pull early; the interpreter's finalizer closes
  // the handle even though the file is not fully drained.
  println("=== streaming read (take 1 chunk) ===")
  with defaultFileRead
  readAllStreaming(inFile, 32)
    .take(1)
    .compile.drain()
  println("handle closed after take(1) — no leak")
  println("")

  // ── 3. Transform and write ────────────────────────────────────────────────
  // The read and write capabilities are separate.  `defaultFileIO` installs
  // both (plus `fileSystem`), so the pipeline can read *and* write.
  println("=== transform and write ===")
  val lines =
    with defaultFileRead
    readLines(inFile).compile.toList()
  with defaultFileWrite
  emits(lines.map(fn(line) line ++ " [processed]"))
    .through(writeAll(outFile))
    .compile.drain()
  println("processed lines written to " ++ outFile.string)
  println("")

  // ── 4. Directory listing ──────────────────────────────────────────────────
  // `listDir` returns a `fsStream<path>` — no read or write capability needed.
  println("=== directory listing ===")
  with defaultFileSystem
  listDir("src".path)
    .compile.drain()
  println("(listing complete)")
  println("")

  // ── 5. Copy: read then write (capabilities discharged separately) ─────────
  // `readStream` and `writeStream` carry different capability rows, so they
  // are each run with their own handler rather than composed end-to-end.
  val copyFile = "/tmp/nagare_copy.txt".path
  println("=== copy file ===")
  val chunks =
    with defaultFileRead
    readAllStreaming(inFile).compile.toList()
  with defaultFileWrite
  emits(chunks).through(writeAll(copyFile)).compile.drain()
  println("copied to " ++ copyFile.string)
