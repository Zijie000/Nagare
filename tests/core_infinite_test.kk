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

  // ---- repeat -------------------------------------------------------------
  // repeat tiles a finite stream; termination is guaranteed only when
  // bounded by take/takeWhile, so these all live here beside `iterate`.

  checkIntListEq("repeat: tiles a finite stream",
    [1, 2, 3, 1, 2, 3, 1],
    pretend-no-div(fn() emits([1, 2, 3]).repeat().take(7).compile.toList()))

  checkIntListEq("repeat: singleton becomes constant stream",
    [7, 7, 7, 7, 7],
    pretend-no-div(fn() emit(7).repeat().take(5).compile.toList()))

  checkIntListEq("repeat + take(0): terminates without forcing the source",
    [],
    pretend-no-div(fn() emits([1, 2, 3]).repeat().take(0).compile.toList()))

  // ---- repeatEval ---------------------------------------------------------

  // Each pull invokes the thunk; thread a ref to observe call count.
  val r1 = ref(0)
  val re1 = pretend-no-div(fn() repeatEval(fn()
    r1 := !r1 + 1
    !r1
  ).take(4).compile.toList())
  checkIntListEq("repeatEval: thunk runs once per pulled value", [1, 2, 3, 4], re1)
  checkIntEq("repeatEval: ref incremented exactly 4 times", 4, !r1)

  // Laziness: take(0) must not run the thunk at all.
  val r2 = ref(0)
  val re2 = pretend-no-div(fn() repeatEval(fn()
    r2 := !r2 + 1
    !r2
  ).take(0).compile.toList())
  checkIntListEq("repeatEval + take(0): emits nothing", [], re2)
  checkIntEq("repeatEval + take(0): thunk never ran", 0, !r2)

  // ---- zipWith with infinite sources --------------------------------------

  // Finite side controls the length when paired with an infinite source.
  checkIntListEq("zipWith: finite left bounds infinite right",
    [10, 21, 32, 43, 54],
    pretend-no-div(fn() zipWith(emits([10, 20, 30, 40, 50]), iterate(0, fn(x) x + 1), fn(a, b) a + b).compile.toList()))

  // Both sides infinite; external take controls termination.
  checkIntListEq("zipWith: both infinite, bounded by take",
    [0, 11, 22, 33, 44],
    pretend-no-div(fn() zipWith(iterate(0, fn(x) x + 1), iterate(0, fn(x) x + 10), fn(a, b) a + b).take(5).compile.toList()))

pub fun main() : io ()
  val (passed, total) = runSuite("core/infinite", suiteBody)
  if passed == total then ()
  else throw("core_infinite_test: " ++ show(total - passed) ++ " failed")
