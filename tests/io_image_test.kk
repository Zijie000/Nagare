module io_image_test

import nagare/core/types
import nagare/core/stream
import nagare/core/interpreter
import nagare/io/file
import nagare/io/image_effect
import nagare/io/image
import test_harness

fun mkBytes(xs : list<int>) : vector<int8>
  xs.map(fn(x) x.int8).vector

// Mock that records every call to decodeImageBytes and returns a synthetic
// image whose width/height encode the input length. Lets us verify the
// streaming shape (one image per pipeline run, regardless of upstream
// chunking) without depending on stb_image at all.
fun mockImageDecode(
  log    : ref<global, list<int>>,
  action : () -> <imageDecode|io> a
) : io a
  with handler
    fun decodeImageBytes(input)
      log := Cons(input.length, !log)
      Image(input.length, 1, 4, input)
  action()

// Hand-crafted 2x1 24-bit BMP fixture, run through the real stb_image FFI
// under the default handler. Lives outside `suiteBody` so the handler can be
// installed at an `io`-only call site (the suite's row carries `test-ctx`,
// which can't be discharged before stripping `imageDecode`).
fun decodeBmpFixture() : io image
  val bmp = mkBytes([
    // BITMAPFILEHEADER (14 bytes)
    0x42, 0x4D,                   // 'BM'
    0x3A, 0x00, 0x00, 0x00,       // file size = 58
    0x00, 0x00, 0x00, 0x00,       // reserved
    0x36, 0x00, 0x00, 0x00,       // pixel data offset = 54
    // BITMAPINFOHEADER (40 bytes)
    0x28, 0x00, 0x00, 0x00,       // header size = 40
    0x02, 0x00, 0x00, 0x00,       // width = 2
    0x01, 0x00, 0x00, 0x00,       // height = 1
    0x01, 0x00,                   // planes = 1
    0x18, 0x00,                   // bpp = 24
    0x00, 0x00, 0x00, 0x00,       // compression = none
    0x04, 0x00, 0x00, 0x00,       // image size = 4 (with padding)
    0x13, 0x0B, 0x00, 0x00,       // x ppm
    0x13, 0x0B, 0x00, 0x00,       // y ppm
    0x00, 0x00, 0x00, 0x00,       // colors used
    0x00, 0x00, 0x00, 0x00,       // important colors
    // pixel data: 2 BGR pixels + 2 bytes padding to reach 4-byte row
    0xFF, 0x00, 0x00,             // pixel 0: blue
    0x00, 0xFF, 0x00,             // pixel 1: green
    0x00, 0x00                    // padding
  ])
  with defaultImageDecode
  decodeImageBytes(bmp)

pub fun suiteBody() : <test-ctx,io> ()
  // ---- (1) decodeImageAll: collects all upstream chunks into one decode call ----
  // Three byte chunks of total length 7 should result in exactly one decode
  // call with a 7-byte input — proving the pipe is "all-at-once" and that
  // chunk boundaries on the upstream are erased before decode runs.
  val log1 = ref([])
  val out1 = mockImageDecode(log1)
    emits([mkBytes([1,2,3]), mkBytes([4,5]), mkBytes([6,7])])
      .decodeImageAll
      .compile.toList()
  checkIntEq("decodeImageAll: one image emitted", 1, out1.length)
  checkIntListEq("decodeImageAll: single decode call sees concat'd bytes",
    [7], !log1)
  match out1
    Cons(img, _) ->
      checkIntEq("decodeImageAll: image width carries full byte length",
        7, img.width)
    [] -> check("decodeImageAll: image present", False)

  // ---- (2) decodeImageAll: empty upstream emits no image ----
  // No bytes at all means no decode call and no output — the pipe should
  // recognise an empty source and short-circuit to PDone.
  val log2 = ref([])
  val out2 = mockImageDecode(log2)
    (empty() : nstream<bytes, _>).decodeImageAll.compile.toList()
  checkIntEq("decodeImageAll: empty stream yields no image", 0, out2.length)
  checkIntEq("decodeImageAll: empty stream skips decode", 0, (!log2).length)

  // ---- (3) Real BMP round-trip via stb_image ----
  // A hand-crafted 2x1 24-bit BMP. BMP is the simplest format stb_image
  // supports — easy to construct inline, exercises the full FFI path:
  // input vector -> stb_image -> output vector + metadata slot.
  val img3 = decodeBmpFixture()
  checkIntEq("real BMP decode: width", 2, img3.width)
  checkIntEq("real BMP decode: height", 1, img3.height)
  // pixels are normalised to RGBA, so 2 pixels * 4 channels = 8 bytes
  checkIntEq("real BMP decode: pixel buffer length is w*h*4",
    8, img3.pixels.length)
  check("real BMP decode: is-valid", img3.is-valid)

pub fun main() : io ()
  val (passed, total) = runSuite("io/image", suiteBody)
  if passed == total then ()
  else throw("io_image_test: " ++ show(total - passed) ++ " failed")
