module io_file_streaming_test

import std/os/path
import nagare/core/types
import nagare/core/stream
import nagare/core/interpreter
import nagare/io/file_effect
import nagare/io/file
import test_harness

extern null-fd() : intptr_t
  c inline "0"

// Mock that simulates a file with fixed chunks. openRead/closeRead events are
// recorded in `log`; readChunk cycles through `chunks` then returns "".
// Installs three capability handlers to cover the full `<fileIO|io>` alias.
fun mockReadFileIO(
  log   : ref<global, list<string>>,
  chunks : ref<global, list<string>>,
  action : () -> <fileRead|io> a
) : io a
  with handler
    fun openRead(_p)
      log := Cons("open", !log)
      ReadHandle(null-fd())
    fun closeRead(_h)
      log := Cons("close", !log)
    fun readChunk(_h, _size)
      match !chunks
        []           -> ""
        Cons(c, rest) ->
          chunks := rest
          c
    fun readChunkBytes(_h, _size) vector(0, 0.int8)
    fun readTextFileOp(_p) ""
  action()

pub fun suiteBody() : <test-ctx,io> ()
  // ---- (1) normal drain: open and close both run ----
  val log1  = ref([])
  val data1 = ref(["hello", " world"])
  mockReadFileIO(log1, data1)
    readAllStreaming("fake.txt".path).compile.drain()
  checkStrListEq("readAllStreaming normal: open+close ran",
    ["open", "close"], (!log1).reverse)

  // ---- (2) take(1) early termination: close still runs ----
  val log2  = ref([])
  val data2 = ref(["chunk-a", "chunk-b", "chunk-c"])
  val out2  = mockReadFileIO(log2, data2)
    readAllStreaming("fake.txt".path).take(1).compile.toList()
  checkStrListEq("readAllStreaming take(1): emits only first chunk",
    ["chunk-a"], out2)
  checkStrListEq("readAllStreaming take(1): close ran despite early stop",
    ["open", "close"], (!log2).reverse)

  // ---- (3) toList collects all chunks ----
  val log3  = ref([])
  val data3 = ref(["a", "b", "c"])
  val out3  = mockReadFileIO(log3, data3)
    readAllStreaming("fake.txt".path).compile.toList()
  checkStrListEq("readAllStreaming toList: all chunks collected",
    ["a", "b", "c"], out3)
  checkStrListEq("readAllStreaming toList: open+close ran",
    ["open", "close"], (!log3).reverse)

pub fun main() : io ()
  val (passed, total) = runSuite("io/file-streaming", suiteBody)
  if passed == total then ()
  else throw("io_file_streaming_test: " ++ show(total - passed) ++ " failed")
