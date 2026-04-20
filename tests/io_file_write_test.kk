module io_file_write_test

import std/os/path
import nagare/core/types
import nagare/core/stream
import nagare/core/interpreter
import nagare/io/file_effect
import nagare/io/file
import test_harness

extern null-fd() : intptr_t
  c inline "0"

// Mock fileIO handler: writes go into `buf`, open/close events into `log`.
fun mockFileIO(
  buf : ref<global, list<string>>,
  log : ref<global, list<string>>,
  action : () -> <fileIO|io> a
) : io a
  with handler
    fun openRead(_p)   ReadHandle(null-fd())
    fun openWrite(_p)
      log := Cons("open", !log)
      WriteHandle(null-fd())
    fun closeRead(_h)  ()
    fun closeWrite(_h)
      log := Cons("close", !log)
    fun readChunk(_h, _size) ""
    fun writeChunk(_h, content)
      buf := Cons(content, !buf)
      content.count
    fun fileExistsOp(_p) False
    fun removeFileOp(_p) ()
    fun listChildren(_p, _r, _d) []
    fun readTextFileOp(_p) ""
  action()

pub fun suiteBody() : <test-ctx,io> ()
  // ---- (1) writeAll normal path: PAcquire acquire+release both run ----
  val log1 = ref([])
  val buf1 = ref([])
  val written1 = ref(False)
  mockFileIO(buf1, log1)
    val src = managed(
      emits(["hello", " world"]),
      fn() { log1 := Cons("acq", !log1) },
      fn() { log1 := Cons("rel", !log1) }
    )
    src.through(writeAll("out.txt".path)).compile.drain()
    written1 := True
  check("writeAll normal: completed", !written1)
  checkStrListEq("writeAll normal: open+close ran",
    ["open", "close"], (!log1).filter(fn(s) s == "open" || s == "close").reverse)
  checkStrListEq("writeAll normal: acquire+release ran",
    ["acq", "rel"], (!log1).filter(fn(s) s == "acq" || s == "rel").reverse)
  checkStrListEq("writeAll normal: chunks written",
    ["hello", " world"], (!buf1).reverse)

  // ---- (2) writeAll nested PAcquire: inner release runs before outer ----
  val log2 = ref([])
  val buf2 = ref([])
  mockFileIO(buf2, log2)
    fun evt(msg : string) : io ()
      log2 := Cons(msg, !log2)
    val inner = managed(emit("inner"), fn() evt("acq-inner"), fn() evt("rel-inner"))
    val outer = managed(inner.flatMap(fn(x) emit(x)), fn() evt("acq-outer"), fn() evt("rel-outer"))
    outer.through(writeAll("out2.txt".path)).compile.drain()
  val events2 = (!log2).filter(fn(s) s.starts-with("acq").bool || s.starts-with("rel").bool).reverse
  val acqs2  = events2.filter(fn(s) s.starts-with("acq").bool)
  val rels2  = events2.filter(fn(s) s.starts-with("rel").bool)
  checkIntEq("writeAll nested: acquire count matches release count",
    acqs2.length, rels2.length)

pub fun main() : io ()
  val (passed, total) = runSuite("io/file-write", suiteBody)
  if passed == total then ()
  else throw("io_file_write_test: " ++ show(total - passed) ++ " failed")
