module io_file_test

// File I/O tests: resource safety (open/close pairing), streaming semantics,
// read/write for strings and bytes, and UTF-8 decode.
//
// All tests use in-process mock handlers so no real files are touched.

import std/os/path
import nagare/core/types
import nagare/core/stream
import nagare/core/interpreter
import nagare/io/file_effect
import nagare/io/file
import test_harness

extern null-fd() : intptr_t
  c inline "0"

// ---------------------------------------------------------------------------
// Mock handlers
// ---------------------------------------------------------------------------

// String-chunk reader: cycles through `chunks`, recording open/close in `log`.
fun mockReadFile(
  log    : ref<global, list<string>>,
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
        []            -> ""
        Cons(c, rest) -> { chunks := rest; c }
    fun readChunkBytes(_h, _size) vector(0, 0.int8)
    fun readTextFileOp(_p) ""
  action()

// String writer: captures chunks in `buf`, records open/close in `log`.
fun mockWriteFile(
  buf : ref<global, list<string>>,
  log : ref<global, list<string>>,
  action : () -> <fileWrite|io> a
) : io a
  with handler
    fun openWrite(_p)
      log := Cons("open", !log)
      WriteHandle(null-fd())
    fun closeWrite(_h)
      log := Cons("close", !log)
    fun writeChunk(_h, content)
      buf := Cons(content, !buf)
      content.count
    fun writeChunkBytes(_h, content) content.length
  action()

// Byte reader: cycles through `chunks` (vector<int8>).
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

// Byte writer: captures written chunks in `buf`.
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

// ---------------------------------------------------------------------------
// Suite
// ---------------------------------------------------------------------------

pub fun suiteBody() : <test-ctx,io> ()
  // ---- readAllStreaming: resource safety -----------------------------------

  val log1  = ref([])
  val data1 = ref(["hello", " world"])
  mockReadFile(log1, data1)
    readAllStreaming("fake.txt".path).compile.drain()
  checkStrListEq("readAllStreaming normal: open+close ran",
    ["open", "close"], (!log1).reverse)

  // take(1) early termination: close must still run.
  val log2  = ref([])
  val data2 = ref(["chunk-a", "chunk-b", "chunk-c"])
  val out2  = mockReadFile(log2, data2)
    readAllStreaming("fake.txt".path).take(1).compile.toList()
  checkStrListEq("readAllStreaming take(1): emits only first chunk",
    ["chunk-a"], out2)
  checkStrListEq("readAllStreaming take(1): close ran despite early stop",
    ["open", "close"], (!log2).reverse)

  val log3  = ref([])
  val data3 = ref(["a", "b", "c"])
  val out3  = mockReadFile(log3, data3)
    readAllStreaming("fake.txt".path).compile.toList()
  checkStrListEq("readAllStreaming toList: all chunks collected",
    ["a", "b", "c"], out3)
  checkStrListEq("readAllStreaming toList: open+close ran",
    ["open", "close"], (!log3).reverse)

  // ---- writeAll: resource safety + PAcquire --------------------------------

  val log4 = ref([])
  val buf4 = ref([])
  val written4 = ref(False)
  mockWriteFile(buf4, log4)
    val src = managed(
      emits(["hello", " world"]),
      fn() { log4 := Cons("acq", !log4) },
      fn() { log4 := Cons("rel", !log4) }
    )
    src.through(writeAll("out.txt".path)).compile.drain()
    written4 := True
  check("writeAll normal: completed", !written4)
  checkStrListEq("writeAll normal: open+close ran",
    ["open", "close"], (!log4).filter(fn(s) s == "open" || s == "close").reverse)
  checkStrListEq("writeAll normal: acquire+release ran",
    ["acq", "rel"], (!log4).filter(fn(s) s == "acq" || s == "rel").reverse)
  checkStrListEq("writeAll normal: chunks written",
    ["hello", " world"], (!buf4).reverse)

  // Nested PAcquire: inner release must run before outer (LIFO).
  val log5 = ref([])
  val buf5 = ref([])
  mockWriteFile(buf5, log5)
    fun evt(msg : string) : io ()
      log5 := Cons(msg, !log5)
    val inner = managed(emit("inner"), fn() evt("acq-inner"), fn() evt("rel-inner"))
    val outer = managed(inner.flatMap(fn(x) emit(x)), fn() evt("acq-outer"), fn() evt("rel-outer"))
    outer.through(writeAll("out2.txt".path)).compile.drain()
  val events5 = (!log5).filter(fn(s) s.starts-with("acq").bool || s.starts-with("rel").bool).reverse
  val acqs5   = events5.filter(fn(s) s.starts-with("acq").bool)
  val rels5   = events5.filter(fn(s) s.starts-with("rel").bool)
  checkIntEq("writeAll nested: acquire count matches release count",
    acqs5.length, rels5.length)

  // ---- readAllStreamingBytes -----------------------------------------------

  val log6  = ref([])
  val data6 = ref([mkBytes([104, 101, 108, 108, 111])])  // "hello"
  mockReadBytes(log6, data6)
    readAllStreamingBytes("fake.bin".path).compile.drain()
  checkStrListEq("readAllStreamingBytes: open+close ran",
    ["open", "close"], (!log6).reverse)

  val log7    = ref([])
  val data7   = ref([mkBytes([1, 2, 3]), mkBytes([4, 5, 6])])
  val out7    = mockReadBytes(log7, data7)
    readAllStreamingBytes("fake.bin".path).compile.toList()
  checkIntEq("readAllStreamingBytes: two chunks collected", 2, out7.length)
  checkIntEq("readAllStreamingBytes: first chunk length",
    3, out7.head.default(vector(0, 0.int8)).length)

  val log8  = ref([])
  val data8 = ref([mkBytes([10, 20]), mkBytes([30, 40])])
  val out8  = mockReadBytes(log8, data8)
    readAllStreamingBytes("fake.bin".path).take(1).compile.toList()
  checkIntEq("readAllStreamingBytes take(1): only first chunk", 1, out8.length)
  checkStrListEq("readAllStreamingBytes take(1): close ran",
    ["open", "close"], (!log8).reverse)

  // ---- writeAllBytes -------------------------------------------------------

  val buf9 = ref([])
  val log9 = ref([])
  mockWriteBytes(buf9, log9)
    emits([mkBytes([65, 66, 67]), mkBytes([68, 69])]).through(writeAllBytes("out.bin".path)).compile.drain()
  checkStrListEq("writeAllBytes: open+close ran",
    ["open", "close"], (!log9).filter(fn(s) s == "open" || s == "close").reverse)
  checkIntEq("writeAllBytes: two chunks written", 2, (!buf9).length)

  // ---- decodeUtf8 ----------------------------------------------------------

  val ascii   = mkBytes([72, 101, 108, 108, 111])  // "Hello"
  val decoded = emits([ascii]).decodeUtf8.compile.toList()
  checkStrListEq("decodeUtf8: ASCII round-trip", ["Hello"], decoded)

  val emptyDecoded = (empty() : nstream<bytes, _>).decodeUtf8.compile.toList()
  checkStrListEq("decodeUtf8: empty stream", [], emptyDecoded)

pub fun main() : io ()
  val (passed, total) = runSuite("io/file", suiteBody)
  if passed == total then ()
  else throw("io_file_test: " ++ show(total - passed) ++ " failed")
