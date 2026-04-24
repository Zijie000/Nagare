module capability_effects_example

// ---------------------------------------------------------------------------
// Capability-minimised file IO.
//
// This example demonstrates the split of `fileIO` into three orthogonal
// capability effects (`fileRead`, `fileWrite`, `fileSystem`). Each pipeline
// declares *exactly* the privileges it needs; calling an operation outside
// that set is a compile-time error.
//
//   - `readPipeline`  carries `<fileRead|io>` — cannot write or list dirs.
//   - `writePipeline` carries `<fileWrite|io>` — cannot read.
//   - `scanPipeline`  carries `<fileSystem|io>` — cannot read or write file
//     contents, only list directory entries.
//
// Compare with FS2: `F[_]` is monolithic — a read-only pipeline is only
// enforced by convention, not by the type. Here, capability minimisation is
// a static property of the row.
//
// After the sink returns, results are combined under user-defined state and
// audit-log effects — showing that multiple effects still compose cleanly
// at the call site, even though the streaming row is closed over `io`.
// ---------------------------------------------------------------------------

import nagare/core/types
import nagare/core/stream
import nagare/core/interpreter
import nagare/io/file_effect
import nagare/io/file
import std/os/path

// ---------------------------------------------------------------------------
// User-defined effects — exercised outside the stream pipeline to show
// multi-effect composition at the call site.
// ---------------------------------------------------------------------------

effect counter
  fun tick() : ()
  fun snapshot() : int

effect auditLog
  fun audit( stage : string, msg : string ) : ()

fun withCounter( action : () -> <counter|e> a ) : e a
  var n := 0
  with handler
    fun tick()     { n := n + 1 }
    fun snapshot() n
  action()

fun withAuditLog( action : () -> <auditLog,console|e> a ) : <console|e> a
  with handler
    fun audit(stage, msg)
      println("[audit:" ++ stage ++ "] " ++ msg)
  action()

// ---------------------------------------------------------------------------
// Pipeline 1: read-only. Signature carries only `fileRead`.
// Attempting to call `writeChunk(...)` here would fail at compile time
// because `fileWrite` is not in the row.
// ---------------------------------------------------------------------------

fun readErrorLines( filepath : path ) : <fileRead|io> list<string>
  readLines(filepath)
    .filter(fn(line) line.contains("ERROR"))
    .take(5)
    .compile.toList()

// ---------------------------------------------------------------------------
// Pipeline 2: write-only. Signature carries only `fileWrite`.
// Attempting to call `readChunk(...)` here would fail at compile time.
// ---------------------------------------------------------------------------

fun writeReport( filepath : path, lines : list<string> ) : <fileWrite|io> ()
  emits(lines)
    .through(writeLines(filepath))
    .compile.drain()

// ---------------------------------------------------------------------------
// Pipeline 3: filesystem metadata only.
// ---------------------------------------------------------------------------

fun listExamples( dir : path ) : <fileSystem|io> list<path>
  listDir(dir)
    .compile.toList()

// ---------------------------------------------------------------------------
// Entry point. Each capability is discharged by a narrow handler — the read
// phase has no access to write operations, the write phase has no access to
// read operations, and the scan phase has access to neither.
//
// `counter` and `auditLog` are user effects that flow through the overall
// orchestration (not inside the pipelines). This demonstrates multi-effect
// composition: three user/capability effects active together.
// ---------------------------------------------------------------------------

pub fun main() : io ()
  with withCounter
  with withAuditLog

  audit("start", "capability-minimised demo")

  // Phase 1: read only — fileWrite + fileSystem are NOT in scope.
  val errors = (fn()
    with defaultFileRead
    readErrorLines("examples/test_input.txt".path)
  )()
  tick()
  audit("read", "error lines found: " ++ show(errors.length))

  // Phase 2: write only — fileRead + fileSystem are NOT in scope.
  (fn()
    with defaultFileWrite
    writeReport("examples/test_errors.txt".path, errors)
  )()
  tick()
  audit("write", "report written to test_errors.txt")

  // Phase 3: filesystem only — cannot open, read, or write files.
  val entries = (fn()
    with defaultFileSystem
    listExamples("examples".path)
  )()
  tick()
  audit("scan", "examples/ contains " ++ show(entries.length) ++ " entries")

  audit("done", "phases completed: " ++ show(snapshot()))

  // Cleanup: only needs fileSystem capability (deleteFile).
  with defaultFileSystem
  deleteFile("examples/test_errors.txt".path).compile.drain()
