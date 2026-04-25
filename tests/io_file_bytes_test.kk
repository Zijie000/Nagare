module io_file_bytes_test

import std/os/path
import nagare/core/types
import nagare/core/stream
import nagare/core/interpreter
import nagare/io/file_effect
import nagare/io/file
import test_harness

extern null-fd() : intptr_t
  c inline "0"

// Mock that serves fixed byte chunks from a list of vector<int8>.
fun mockReadBytes(
  log    : ref<global, list<string>>,
  chunks : ref<global, list<bytes>>,
  action : () -> <fileRead|io> a
) : io a
  with handler
    fun openRead(_p)
      log := Cons("open", !log)
      ReadHandle(null-fd())
    fun closeRead(_h)
      log := Cons("close", !log)
    fun readChunk(_h, _size) ""
    fun readChunkBytes(_h, _size)
      match !chunks
        []            -> vector(0, 0.int8)
        Cons(c, rest) -> { chunks := rest; c }
    fun readTextFileOp(_p) ""
  action()

// Mock that captures written byte chunks.
fun mockWriteBytes(
  buf : ref<global, list<bytes>>,
  log : ref<global, list<string>>,
  action : () -> <fileWrite|io> a
) : io a
  with handler
    fun openWrite(_p)
      log := Cons("open", !log)
      WriteHandle(null-fd())
    fun closeWrite(_h)
      log := Cons("close", !log)
    fun writeChunk(_h, content) content.count
    fun writeChunkBytes(_h, content)
      buf := Cons(content, !buf)
      content.length
  action()

fun mkBytes(xs : list<int>) : bytes
  xs.map(fn(x) x.int8).vector

pub fun suiteBody() : <test-ctx,io> ()
  // ---- (1) readAllStreamingBytes: open+close run ----
  val log1   = ref([])
  val data1  = ref([mkBytes([104, 101, 108, 108, 111])])  // "hello"
  mockReadBytes(log1, data1)
    readAllStreamingBytes("fake.bin".path).compile.drain()
  checkStrListEq("readAllStreamingBytes: open+close ran",
    ["open", "close"], (!log1).reverse)

  // ---- (2) readAllStreamingBytes: collects all chunks ----
  val log2  = ref([])
  val chunk2a = mkBytes([1, 2, 3])
  val chunk2b = mkBytes([4, 5, 6])
  val data2   = ref([chunk2a, chunk2b])
  val out2 = mockReadBytes(log2, data2)
    readAllStreamingBytes("fake.bin".path).compile.toList()
  checkIntEq("readAllStreamingBytes: two chunks collected", 2, out2.length)
  checkIntEq("readAllStreamingBytes: first chunk length", 3, out2.head.default(vector(0, 0.int8)).length)

  // ---- (3) readAllStreamingBytes take(1): close still runs ----
  val log3  = ref([])
  val data3 = ref([mkBytes([10, 20]), mkBytes([30, 40])])
  val out3 = mockReadBytes(log3, data3)
    readAllStreamingBytes("fake.bin".path).take(1).compile.toList()
  checkIntEq("readAllStreamingBytes take(1): only first chunk", 1, out3.length)
  checkStrListEq("readAllStreamingBytes take(1): close ran", ["open", "close"], (!log3).reverse)

  // ---- (4) writeAllBytes: open+close run and chunks captured ----
  val buf4 = ref([])
  val log4 = ref([])
  mockWriteBytes(buf4, log4)
    emits([mkBytes([65, 66, 67]), mkBytes([68, 69])]).through(writeAllBytes("out.bin".path)).compile.drain()
  checkStrListEq("writeAllBytes: open+close ran",
    ["open", "close"], (!log4).filter(fn(s) s == "open" || s == "close").reverse)
  checkIntEq("writeAllBytes: two chunks written", 2, (!buf4).length)

  // ---- (5) decodeUtf8: ASCII bytes round-trip ----
  val ascii = mkBytes([72, 101, 108, 108, 111])  // "Hello"
  val decoded = emits([ascii]).decodeUtf8.compile.toList()
  checkStrListEq("decodeUtf8: ASCII round-trip", ["Hello"], decoded)

  // ---- (6) decodeUtf8: empty stream ----
  val emptyDecoded = (empty() : nstream<bytes, _>).decodeUtf8.compile.toList()
  checkStrListEq("decodeUtf8: empty stream", [], emptyDecoded)

pub fun main() : io ()
  val (passed, total) = runSuite("io/file-bytes", suiteBody)
  if passed == total then ()
  else throw("io_file_bytes_test: " ++ show(total - passed) ++ " failed")
