module file_io_example

import nagare/core/types
import nagare/core/stream
import nagare/core/interpreter
import nagare/io/file
import nagare/io/file_effect
import std/os/path

fun main() : io ()
  with defaultFileIO
  // Example 1: Read lines, filter for ERROR lines, print them.
  println("== Example 1: readLines + filter ==")
  readLines("examples/test_input.txt".path)
    .filter(fn(line) line.contains("ERROR"))
    .evalTap(fn(line) println("  " ++ line))
    .compile.drain()

  // Example 2: Count lines in a file.
  println("\n== Example 2: readLines + fold (count lines) ==")
  val count = readLines("examples/test_input.txt".path)
    .compile.fold(0, fn(acc, _) acc + 1)
  println("  Line count: " ++ count.show)

  // Example 3: Read first 3 lines only (test early termination + resource safety).
  println("\n== Example 3: readLines + take(3) ==")
  val first3 = readLines("examples/test_input.txt".path)
    .take(3)
    .compile.toList()
  println("  First 3 lines: " ++ first3.show)

  // Example 4: Read file, transform lines, write to output.
  println("\n== Example 4: readLines -> map -> writeLines (file copy with transform) ==")
  readLines("examples/test_input.txt".path)
    .map(fn(line) "[processed] " ++ line)
    .through(writeLines("examples/test_output.txt".path))
    .compile.drain()
  println("  Written to examples/test_output.txt")

  // Verify the written file by reading it back.
  println("\n== Verify: read back output file ==")
  readLines("examples/test_output.txt".path)
    .evalTap(fn(line) println("  " ++ line))
    .compile.drain()

  // Example 5: Streaming file copy via readAll + writeAll (binary-safe chunked copy).
  println("\n== Example 5: readAll -> writeAll (chunked file copy) ==")
  readAll("examples/test_input.txt".path, 16)
    .through(writeAll("examples/test_copy.txt".path))
    .compile.drain()
  println("  Copied to examples/test_copy.txt")

  // Example 6: List directory contents.
  println("\n== Example 6: listDir ==")
  listDir("examples".path)
    .evalTap(fn(p) println("  " ++ p.string))
    .compile.drain()

  // Example 7: Batch lines into groups of 3 (chunkN), process each batch.
  println("\n== Example 7: readLines + chunkN(3) — batch processing ==")
  readLines("examples/test_input.txt".path)
    .chunkN(3)
    .evalMap(fn(batch)
      match batch
        Chunk(lines) ->
          val joined = lines.join(" | ")
          println("  batch: [" ++ joined ++ "]")
          batch
    )
    .compile.drain()

  // Example 8: chunkN + unchunks round-trip — regroup then flatten back.
  println("\n== Example 8: readLines + chunkN(2) + unchunks — regroup and flatten ==")
  val regrouped = readLines("examples/test_input.txt".path)
    .chunkN(2)
    .unchunks()
    .compile.toList()
  println("  element count: " ++ regrouped.length.show)
  println("  elements: " ++ regrouped.show)

  // Cleanup output files.
  deleteFile("examples/test_output.txt".path).compile.drain()
  deleteFile("examples/test_copy.txt".path).compile.drain()
  println("\n== Done (cleaned up output files) ==")
