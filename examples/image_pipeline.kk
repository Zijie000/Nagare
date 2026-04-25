// image_pipeline.kk — Streaming over a directory of images
//
// Run: koka -e --builddir=.koka -isrc examples/image_pipeline.kk
//
// Streaming granularity: this pipeline is *batch-level* streaming. The list
// of files flows through `evalMap` lazily — at any instant only one image
// is held in memory, and `take(n)` will stop opening files after the n-th
// decode.  But each individual image is decoded all-at-once: PNG / JPEG /
// BMP / GIF have no chunk-by-chunk decoder (DEFLATE windows, Huffman tables,
// and inter-row filters all forbid it), so `decodeImageAll` collects every
// byte chunk before producing exactly one `image`.
//
// The `All` suffix in `decodeImageAll` / `readAll` is the API's way of being
// honest about this — borrowed from fs2's naming convention.
//
// Capability handling: `defaultFileRead` and `defaultImageDecode` are each
// scoped to a single `<X|io>` row, so they cannot stack at the pipeline
// level.  We localise them to a per-file helper `decodeOne` whose result row
// is plain `io`; the top-level pipeline carries `<io>` and stays composable
// with every other Nagare combinator.

module image_pipeline

import std/os/path
import nagare/core/types
import nagare/core/stream
import nagare/core/interpreter
import nagare/io/file
import nagare/io/file_effect
import nagare/io/image
import nagare/io/image_effect

// Flatten a list of byte chunks into one vector — done once, at the end of
// the read phase, so the cost is O(total bytes) rather than O(n²) from
// repeatedly concatenating into a growing accumulator inside `fold`.
fun flattenBytes( chunks : list<bytes> ) : bytes
  chunks.flatmap(fn(c) c.vlist).vector

// Read + decode a single image, with each capability discharged locally.
// We split the read and decode phases so that each `with` block sees only
// one capability — the library's default handlers each pin their action's
// row to a single `<X|io>`, so they can't be stacked at the same site.
//
// Phase 1: under `defaultFileRead`, collect all byte chunks into a list and
//          flatten them into one buffer.
// Phase 2: under `defaultImageDecode`, run the decoder on those bytes.
//
// The outer pipeline sees only `io`, so it composes with any combinator.
fun decodeOne( p : path ) : io maybe<image>
  val chunks =
    with defaultFileRead
    readAllStreamingBytes(p).compile.toList()
  val bytes = flattenBytes(chunks)
  if bytes.length == 0 then Nothing
  else
    with defaultImageDecode
    Just(decodeImageBytes(bytes))

// Format a one-line summary for an image.
fun describe( p : path, img : image ) : string
  p.string ++ " — " ++ show(img.width) ++ "x" ++ show(img.height)
    ++ " (" ++ show(img.channels) ++ " ch, "
    ++ show(img.pixels.length) ++ " B RGBA)"

pub fun main() : io ()
  val dir = "examples/pictures".path

  // Discover the picture files under `defaultFileSystem`.  The list of
  // paths is the bridge between the directory-listing capability and the
  // image-decoding capability.
  val pics =
    with defaultFileSystem
    listDir(dir)
      .filter(fn(p) p.string.ends-with(".jpg").bool
                 || p.string.ends-with(".png").bool)
      .compile.toList()

  // ── 1. Decode every image in the directory ───────────────────────────────
  // `evalMap` opens, decodes, and releases one file per element.  At any
  // instant only one image lives in memory — the previous one is dropped
  // before the next file is opened.
  println("=== decoding directory ===")
  val summaries =
    emits(pics)
      .evalMap(fn(p)
        match decodeOne(p)
          Just(img) -> describe(p, img)
          Nothing   -> p.string ++ " — (could not decode)"
      )
      .compile.toList()
  summaries.foreach(fn(s) println("  " ++ s))
  println("decoded " ++ show(summaries.length) ++ " images")
  println("")

  // ── 2. Early termination: take(2) stops after the second decode ──────────
  // Pull-based: `take(2)` cuts the path stream before the third file is
  // ever opened.  decodeOne is never called for files past the bound.
  println("=== take(2): stop after 2 decodes ===")
  val firstTwo =
    emits(pics)
      .evalMap(fn(p)
        match decodeOne(p)
          Just(img) -> describe(p, img)
          Nothing   -> p.string ++ " — (could not decode)"
      )
      .take(2)
      .compile.toList()
  firstTwo.foreach(fn(s) println("  " ++ s))
  println("")

  // ── 3. Fold over the stream: total pixel count without buffering ─────────
  // `fold` consumes one image at a time; the `image` value is alive only
  // for the duration of the step function before being dropped.  For a
  // directory of large images this is the difference between O(1) and O(n)
  // memory.
  println("=== folding: total pixel count ===")
  val totalPixels =
    emits(pics)
      .evalMap(decodeOne)
      .compile.fold(0, fn(acc, m)
        match m
          Just(img) -> acc + img.width * img.height
          Nothing   -> acc
      )
  println("total pixels across all images: " ++ show(totalPixels))
