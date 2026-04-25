// lazy_infinite.kk — Pull-based laziness and infinite streams
//
// Run: koka -e --builddir=.koka -isrc examples/lazy_infinite.kk
//
// Nagare streams are pull-based: elements are materialised only on demand.
// `iterate` produces an unbounded source; downstream combinators like `take`
// and `takeWhile` stop the pull without ever evaluating the rest.
//
// Koka's effect system makes the invariant explicit: `iterate` carries `div`
// in its row because an unbounded drain would diverge.  Bounding it with
// `take`/`takeWhile` is the proof of termination — `pretend-no-div` asserts
// that proof to the type checker.

module lazy_infinite

import std/core/undiv
import nagare/core/types
import nagare/core/stream
import nagare/core/interpreter

pub fun main() : io ()
  // ── 1. First n naturals ───────────────────────────────────────────────────
  val nats5 = pretend-no-div(fn()
    iterate(0, fn(x) x + 1).take(5).compile.toList()
  )
  println("first 5 naturals:    " ++ show(nats5))       // [0, 1, 2, 3, 4]

  // ── 2. Geometric sequence ─────────────────────────────────────────────────
  val powers = pretend-no-div(fn()
    iterate(1, fn(x) x * 2).take(8).compile.toList()
  )
  println("powers of 2 (×8):    " ++ show(powers))      // [1, 2, 4, 8, 16, 32, 64, 128]

  // ── 3. takeWhile: bound by a predicate ────────────────────────────────────
  val below100 = pretend-no-div(fn()
    iterate(1, fn(x) x * 2).takeWhile(fn(x) x < 100).compile.toList()
  )
  println("powers of 2 < 100:   " ++ show(below100))    // [1, 2, 4, 8, 16, 32, 64]

  // ── 4. Pipelines compose with infinite sources ────────────────────────────
  // map + filter + take: none of these force more than take(n) elements.
  val evens = pretend-no-div(fn()
    iterate(0, fn(x) x + 1)
      .map(fn(x) x * x)         // squares: 0 1 4 9 16 25 …
      .filter(fn(x) x % 2 == 0) // even squares: 0 4 16 36 64 …
      .take(5)
      .compile.toList()
  )
  println("first 5 even squares:" ++ show(evens))       // [0, 4, 16, 36, 64]

  // ── 5. flatMap on an infinite source ─────────────────────────────────────
  // Each natural number expands into [n, -n]; take(6) pulls exactly 3 outer
  // elements before the source is cut.
  val mirrored = pretend-no-div(fn()
    iterate(1, fn(x) x + 1)
      .flatMap(fn(x) emits([x, 0 - x]))
      .take(6)
      .compile.toList()
  )
  println("mirrored naturals:   " ++ show(mirrored))    // [1, -1, 2, -2, 3, -3]

  // ── 6. Fibonacci via iterate on pairs ─────────────────────────────────────
  val fibs = pretend-no-div(fn()
    iterate((0, 1), fn(p) match p { (a, b) -> (b, a + b) })
      .map(fn(p) match p { (a, _) -> a })
      .take(10)
      .compile.toList()
  )
  println("first 10 Fibonacci:  " ++ show(fibs))        // [0, 1, 1, 2, 3, 5, 8, 13, 21, 34]
