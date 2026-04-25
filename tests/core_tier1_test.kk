module core_tier1_test

import std/core/undiv
import nagare/core/types
import nagare/core/stream
import nagare/core/interpreter
import test_harness

// ---------------------------------------------------------------------------
// SCOPE
// ---------------------------------------------------------------------------
// Tier-1 combinators added on top of the core algebra:
//   dropWhile, scan, zip / zipWith, repeat / repeatEval, exec.
//
// Each section asserts the combinator's defining law plus at least one
// edge case (empty input, mismatched lengths, early termination, etc.).
// ---------------------------------------------------------------------------

pub fun suiteBody() : <test-ctx,io> ()
  // ---- dropWhile ----------------------------------------------------------

  checkIntListEq("dropWhile: drops prefix, then forwards rest",
    [4, 1, 2],
    emits([1, 2, 3, 4, 1, 2]).dropWhile(fn(x) x < 4).compile.toList())

  // Predicate never holds: nothing is dropped.
  checkIntListEq("dropWhile: predicate false from start keeps everything",
    [1, 2, 3],
    emits([1, 2, 3]).dropWhile(fn(x) x > 100).compile.toList())

  // Predicate always holds: result empty.
  checkIntListEq("dropWhile: predicate always true drops everything",
    [],
    emits([1, 2, 3]).dropWhile(fn(_) True).compile.toList())

  // After the first failure, *all* subsequent values pass through, even
  // those that would have satisfied the predicate. This is what
  // distinguishes dropWhile from filter.
  checkIntListEq("dropWhile: after first failure, all values forwarded",
    [4, 1, 5, 2],
    emits([1, 2, 3, 4, 1, 5, 2]).dropWhile(fn(x) x < 4).compile.toList())

  // Empty source: empty output, no divergence.
  checkIntListEq("dropWhile: empty source",
    [],
    empty().dropWhile(fn(_) True).compile.toList())

  // ---- scan ---------------------------------------------------------------

  // Seed is emitted first, before any input is consumed.
  checkIntListEq("scan: emits seed then running sums",
    [0, 1, 3, 6, 10],
    emits([1, 2, 3, 4]).scan(0, fn(acc, x) acc + x).compile.toList())

  // Empty source still emits the seed.
  checkIntListEq("scan: empty source still emits seed",
    [42],
    empty().scan(42, fn(acc, x : int) acc + x).compile.toList())

  // Running max example.
  checkIntListEq("scan: running maximum",
    [0, 3, 3, 5, 5, 9],
    emits([3, 1, 5, 2, 9]).scan(0, fn(acc, x) if x > acc then x else acc).compile.toList())

  // Composes with take: only the prefix we ask for is computed.
  checkIntListEq("scan + take: bounded prefix",
    [0, 1, 3],
    emits([1, 2, 3, 4, 5]).scan(0, fn(acc, x) acc + x).take(3).compile.toList())

  // ---- zipWith / zip ------------------------------------------------------

  // Equal lengths: pointwise combine.
  checkIntListEq("zipWith: equal lengths sum",
    [11, 22, 33],
    pretend-no-div(fn() zipWith(emits([1, 2, 3]), emits([10, 20, 30]), fn(a, b) a + b).compile.toList()))

  // Left shorter: stops at left's end.
  checkIntListEq("zipWith: left shorter, stops at min",
    [11, 22],
    pretend-no-div(fn() zipWith(emits([1, 2]), emits([10, 20, 30, 40]), fn(a, b) a + b).compile.toList()))

  // Right shorter: stops at right's end.
  checkIntListEq("zipWith: right shorter, stops at min",
    [11, 22],
    pretend-no-div(fn() zipWith(emits([1, 2, 3, 4]), emits([10, 20]), fn(a, b) a + b).compile.toList()))

  // Empty side: empty result.
  checkIntListEq("zipWith: empty left",
    [],
    pretend-no-div(fn() zipWith(empty(), emits([1, 2, 3]), fn(a : int, b : int) a + b).compile.toList()))

  checkIntListEq("zipWith: empty right",
    [],
    pretend-no-div(fn() zipWith(emits([1, 2, 3]), empty(), fn(a : int, b : int) a + b).compile.toList()))

  // zip is the pair-forming specialisation of zipWith.
  val pairs = pretend-no-div(fn() zip(emits([1, 2, 3]), emits([10, 20, 30])).compile.toList())
  checkIntEq("zip: length matches", 3, pairs.length)
  checkIntListEq("zip: first components",
    [1, 2, 3],
    pairs.map(fn(p) p.fst))
  checkIntListEq("zip: second components",
    [10, 20, 30],
    pairs.map(fn(p) p.snd))

  // zip with infinite source on one side bounded by finite on the other:
  // finite side controls the length.
  checkIntListEq("zipWith: finite left bounds infinite right",
    [10, 21, 32, 43, 54],
    pretend-no-div(fn() zipWith(emits([10, 20, 30, 40, 50]), iterate(0, fn(x) x + 1), fn(a, b) a + b).compile.toList()))

  // zip with infinite on both sides, bounded externally by take.
  checkIntListEq("zipWith: both infinite, bounded by take",
    [0, 11, 22, 33, 44],
    pretend-no-div(fn() zipWith(iterate(0, fn(x) x + 1), iterate(0, fn(x) x + 10), fn(a, b) a + b).take(5).compile.toList()))

  // ---- repeat -------------------------------------------------------------

  // Repeating a finite stream tiles its values; bound with take.
  checkIntListEq("repeat: tiles a finite stream",
    [1, 2, 3, 1, 2, 3, 1],
    pretend-no-div(fn() emits([1, 2, 3]).repeat().take(7).compile.toList()))

  // repeat of a singleton equals constant stream of that value.
  checkIntListEq("repeat: singleton becomes constant",
    [7, 7, 7, 7, 7],
    pretend-no-div(fn() emit(7).repeat().take(5).compile.toList()))

  // take(0) on a repeated source terminates without forcing anything.
  checkIntListEq("repeat + take(0): empty without divergence",
    [],
    pretend-no-div(fn() emits([1, 2, 3]).repeat().take(0).compile.toList()))

  // ---- repeatEval ---------------------------------------------------------

  // Each pull invokes the thunk. We thread a counter through a ref to
  // observe call count and per-call value.
  val r = ref(0)
  val xs = pretend-no-div(fn() repeatEval(fn()
    r := !r + 1
    !r
  ).take(4).compile.toList())
  checkIntListEq("repeatEval: thunk runs once per pulled value",
    [1, 2, 3, 4],
    xs)
  checkIntEq("repeatEval: ref incremented exactly 4 times", 4, !r)

  // repeatEval is lazy: take(0) does not run the thunk at all.
  val r2 = ref(0)
  val ys = pretend-no-div(fn() repeatEval(fn()
    r2 := !r2 + 1
    !r2
  ).take(0).compile.toList())
  checkIntListEq("repeatEval + take(0): emits nothing", [], ys)
  checkIntEq("repeatEval + take(0): thunk never ran", 0, !r2)

  // ---- exec ---------------------------------------------------------------

  // exec runs an action once for its side effect and emits no value.
  val r3 = ref(0)
  val zs : list<int> = exec(fn() r3 := !r3 + 100).compile.toList()
  checkIntListEq("exec: emits nothing", [], zs)
  checkIntEq("exec: side effect happened exactly once", 100, !r3)

  // exec composes: prepend setup before a producer.
  val r4 = ref(0)
  val ws = append(
    exec(fn() r4 := 1),
    emits([10, 20, 30])
  ).compile.toList()
  checkIntListEq("exec + append: setup runs, then values flow",
    [10, 20, 30],
    ws)
  checkIntEq("exec + append: side effect observed", 1, !r4)

pub fun main() : io ()
  val (passed, total) = runSuite("core/tier1", suiteBody)
  if passed == total then ()
  else throw("core_tier1_test: " ++ show(total - passed) ++ " failed")
