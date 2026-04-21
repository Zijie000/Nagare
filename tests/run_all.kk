module run_all

import nagare/core/types
import nagare/core/pull
import nagare/core/stream
import nagare/core/interpreter
import test_harness
import core_pull_test
import core_stream_test
import core_interpreter_test
import core_resource_test
import effect_polymorphism_test
import io_file_write_test
import effect_e2e_test
import io_file_streaming_test

// Aggregate entry point: runs every suite, then exits non-zero on any failure.
pub fun main() : io ()
  val (p1, t1) = runSuite("core/pull", core_pull_test/suiteBody)
  val (p2, t2) = runSuite("core/stream", core_stream_test/suiteBody)
  val (p3, t3) = runSuite("core/interpreter", core_interpreter_test/suiteBody)
  val (p4, t4) = runSuite("core/resource", core_resource_test/suiteBody)
  val (p5, t5) = runSuite("effect/polymorphism (type-level)", effect_polymorphism_test/suiteBody)
  val (p6, t6) = runSuite("io/file-write", io_file_write_test/suiteBody)
  val (p7, t7) = runSuite("effect/e2e row-polymorphism", effect_e2e_test/suiteBody)
  val (p8, t8) = runSuite("io/file-streaming", io_file_streaming_test/suiteBody)
  val passed = p1 + p2 + p3 + p4 + p5 + p6 + p7 + p8
  val total = t1 + t2 + t3 + t4 + t5 + t6 + t7 + t8
  println("\n== total ==")
  println("  " ++ show(passed) ++ "/" ++ show(total) ++ " passed")
  if passed == total then ()
  else throw("run_all: " ++ show(total - passed) ++ " tests failed")
