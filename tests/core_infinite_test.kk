module core_infinite_test

import std/core/undiv
import nagare/core/types
import nagare/core/stream
import nagare/core/interpreter
import test_harness

// ---------------------------------------------------------------------------
// SCOPE
// ---------------------------------------------------------------------------
// Verifies that `iterate` produces a genuinely unbounded source and that
// downstream early-stop combinators (`take`, `takeWhile`) terminate it.
//
// If pull semantics were eager — or if `take` failed to propagate stop into
// the `PEval` thunk that wraps each iteration step — these tests would not
// terminate and the suite would time out. Termination is the test.
//
// This is the strongest available falsifier for "streaming": only consumed
// elements are materialised. If anything in the pipeline forces the tail,
// `compile.toList()` on an infinite source diverges.
// ---------------------------------------------------------------------------

// We bound every `iterate` with `take`/`takeWhile`, so the consumed pipeline
// is finite even though the source carries `div` in its row. `pretend-no-div`
// is Koka's escape hatch: it asserts to the type system that the enclosed
// computation does in fact terminate. Using it is honest here — that's the
// very property under test (and a non-terminating bug would show up as a
// CI timeout, not a wrong type).
pub fun suiteBody() : <test-ctx,io> ()
  // ---- (1) iterate + take terminates and yields the right prefix ----
  checkIntListEq("iterate+take(5): first five naturals",
    [0, 1, 2, 3, 4],
    pretend-no-div(fn() iterate(0, fn(x) x + 1).take(5).compile.toList()))

  // ---- (2) take(0) on an infinite source yields nothing and terminates ----
  // Guards against a regression where take(0) tries to peek the source.
  checkIntListEq("iterate+take(0): empty without forcing the source",
    [],
    pretend-no-div(fn() iterate(0, fn(x) x + 1).take(0).compile.toList()))

  // ---- (3) takeWhile bounds an infinite source ----
  checkIntListEq("iterate+takeWhile: stops at predicate failure",
    [0, 1, 2, 3, 4],
    pretend-no-div(fn() iterate(0, fn(x) x + 1).takeWhile(fn(x) x < 5).compile.toList()))

  // ---- (4) Pure transforms compose with infinite sources under take ----
  // map and filter must not eagerly traverse; take must still cut.
  checkIntListEq("iterate.map.filter.take: composed pipeline terminates",
    [0, 4, 16, 36, 64],
    pretend-no-div(fn() iterate(0, fn(x) x + 1).map(fn(x) x * x).filter(fn(x) x % 2 == 0).take(5).compile.toList()))

  // ---- (5) Geometric iterate (different f) ----
  checkIntListEq("iterate(1, *2)+take(6): powers of two",
    [1, 2, 4, 8, 16, 32],
    pretend-no-div(fn() iterate(1, fn(x) x * 2).take(6).compile.toList()))

  // ---- (6) Drain-counted: take(n) emits exactly n elements ----
  val xs = pretend-no-div(fn() iterate(0, fn(x) x + 1).take(100).compile.toList())
  checkIntEq("iterate+take(100): length is exactly 100", 100, xs.length)

pub fun main() : io ()
  val (passed, total) = runSuite("core/infinite", suiteBody)
  if passed == total then ()
  else throw("core_infinite_test: " ++ show(total - passed) ++ " failed")
