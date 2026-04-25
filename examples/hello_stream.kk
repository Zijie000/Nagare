// hello_stream.kk — Getting started with Nagare
//
// Run: koka -e --builddir=.koka -isrc examples/hello_stream.kk
//
// This example introduces the three ways to build a Nagare stream and
// the basic combinators that transform and consume it.

module hello_stream

import nagare/core/types
import nagare/core/stream
import nagare/core/interpreter

pub fun main() : io ()
  // ── 1. streamOf: imperative DSL ──────────────────────────────────────────
  // yieldOne / yieldAll inside a `streamOf` block compile into lazy POutput
  // nodes.  The pull ADT is built once; nothing runs until compile.toList().
  val s1 = streamOf
    yieldOne(1)
    yieldAll([2, 3, 4])
    yieldOne(5)
  val xs1 = s1.compile.toList()
  println("streamOf DSL:      " ++ show(xs1))          // [1, 2, 3, 4, 5]

  // ── 2. emits: lift a plain list into a stream ─────────────────────────────
  val xs2 = emits([1, 2, 3, 4, 5, 6])
    .map(fn(x) x * x)
    .filter(fn(x) x % 2 == 0)
    .compile.toList()
  println("emits+map+filter:  " ++ show(xs2))          // [4, 16, 36]

  // ── 3. concat: splice multiple streams together ───────────────────────────
  val xs3 = concat([ emits([1, 2]), emits([3, 4]), emits([5]) ])
    .compile.toList()
  println("concat:            " ++ show(xs3))          // [1, 2, 3, 4, 5]

  // ── 4. take / drop / takeWhile ────────────────────────────────────────────
  val xs4 = emits([1, 2, 3, 4, 5, 6])
    .drop(1)
    .takeWhile(fn(x) x <= 4)
    .compile.toList()
  println("drop+takeWhile:    " ++ show(xs4))          // [2, 3, 4]

  // ── 5. flatMap: expand each element into a sub-stream ─────────────────────
  val xs5 = emits([1, 2, 3])
    .flatMap(fn(x) emits([x, x * 10]))
    .compile.toList()
  println("flatMap:           " ++ show(xs5))          // [1, 10, 2, 20, 3, 30]

  // ── 6. fold: reduce the whole stream to one value ────────────────────────
  val sum = emits([1, 2, 3, 4, 5]).compile.fold(0, fn(acc, x) acc + x)
  println("fold (sum):        " ++ show(sum))          // 15

  // ── 7. last: just the final element ──────────────────────────────────────
  val l = emits([10, 20, 30]).compile.last()
  match l
    Just(v) -> println("last:              " ++ show(v))     // 30
    Nothing -> println("last:              (empty)")
