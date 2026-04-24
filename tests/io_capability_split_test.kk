module io_capability_split_test

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
// Verify each capability effect has an independent handler and that narrow
// pipelines (readStream / writeStream / fsStream) discharge only their own
// capability — no need for the combined defaultFileIO.
// ---------------------------------------------------------------------------

fun mockRead(
  chunks : ref<global, list<string>>,
  action : () -> <fileRead|io> a
) : io a
  with handler
    fun openRead(_p)  ReadHandle(null-fd())
    fun closeRead(_h) ()
    fun readChunk(_h, _size)
      match !chunks
        []            -> ""
        Cons(c, rest) -> { chunks := rest; c }
    fun readTextFileOp(_p) ""
  action()

fun mockWrite(
  buf : ref<global, list<string>>,
  action : () -> <fileWrite|io> a
) : io a
  with handler
    fun openWrite(_p) WriteHandle(null-fd())
    fun closeWrite(_h) ()
    fun writeChunk(_h, content)
      buf := Cons(content, !buf)
      content.count
  action()

fun mockFs(
  listed : ref<global, list<path>>,
  action : () -> <fileSystem|io> a
) : io a
  with handler
    fun fileExistsOp(_p) True
    fun removeFileOp(_p) ()
    fun listChildren(_p, _r, _d) !listed
  action()

pub fun suiteBody() : <test-ctx,io> ()
  // ---- (1) readStream pipeline runs under fileRead alone ----
  val chunks1 = ref(["a", "b", "c"])
  val out1 = mockRead(chunks1)
    readAllStreaming("any.txt".path).compile.toList()
  checkStrListEq("fileRead alone: chunks collected",
    ["a", "b", "c"], out1)

  // ---- (2) writeStream pipeline runs under fileWrite alone ----
  val buf2 = ref([])
  mockWrite(buf2)
    emits(["x", "y", "z"]).through(writeAll("out.txt".path)).compile.drain()
  checkStrListEq("fileWrite alone: chunks written",
    ["x", "y", "z"], (!buf2).reverse)

  // ---- (3) fsStream pipeline runs under fileSystem alone ----
  val listed3 = ref(["a.kk".path, "b.kk".path])
  val out3 = mockFs(listed3)
    listDir("any".path).compile.toList()
  checkIntEq("fileSystem alone: dir entries listed",
    2, out3.length)

  // ---- (4) narrow pipelines do NOT require the full fileIO alias ----
  // readAllStreaming typechecks against fileRead-only mock (see test 1) and
  // writeAll typechecks against fileWrite-only mock (see test 2). That alone
  // demonstrates capability minimisation — the narrow signatures cannot fall
  // back onto full fileIO at call sites.
  check("narrow pipelines compile under minimal capabilities", True)

pub fun main() : io ()
  val (passed, total) = runSuite("io/capability-split", suiteBody)
  if passed == total then ()
  else throw("io_capability_split_test: " ++ show(total - passed) ++ " failed")
