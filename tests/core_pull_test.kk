module core_pull_test

import nagare/core/types
import nagare/core/pull
import nagare/core/stream
import nagare/core/interpreter
import test_harness

// Helper: collect a pull into a list via the interpreter.
fun collect(p : pull<int,io>) : io list<int>
  fromPull(p).compile.toList()

pub fun suiteBody() : <test-ctx,io> ()
  // pullAppend: sequences two pulls in order.
  checkIntListEq("pullAppend: in-order concatenation",
    [1, 2, 3, 4],
    collect(pullAppend(toPull(emits([1, 2])), fn() toPull(emits([3, 4])))))

  // pullAppend: empty left.
  checkIntListEq("pullAppend: empty left",
    [5, 6],
    collect(pullAppend(PDone, fn() toPull(emits([5, 6])))))

  // pullAppend: empty right.
  checkIntListEq("pullAppend: empty right",
    [7, 8],
    collect(pullAppend(toPull(emits([7, 8])), fn() PDone)))

  // pullMap: applies f to every output.
  checkIntListEq("pullMap: maps all values",
    [2, 4, 6],
    collect(pullMap(toPull(emits([1, 2, 3])), fn(x) x * 2)))

  // pullMap: preserves empty pulls.
  checkIntListEq("pullMap: empty",
    [],
    collect(pullMap(PDone, fn(x : int) x + 1)))

  // pullFilter: drops values failing predicate.
  checkIntListEq("pullFilter: keeps matches",
    [2, 4],
    collect(pullFilter(toPull(emits([1, 2, 3, 4, 5])), fn(x) (x % 2) == 0)))

  // pullFilter: all filtered -> empty.
  checkIntListEq("pullFilter: none match",
    [],
    collect(pullFilter(toPull(emits([1, 3, 5])), fn(x) (x % 2) == 0)))

  // pullFlatMap: expands each element.
  checkIntListEq("pullFlatMap: expand and concat",
    [1, 10, 2, 20, 3, 30],
    collect(pullFlatMap(toPull(emits([1, 2, 3])), fn(x) toPull(emits([x, x * 10])))))

  // pullFlatMap: empty expansion.
  checkIntListEq("pullFlatMap: expansion to empty",
    [],
    collect(pullFlatMap(toPull(emits([1, 2, 3])), fn(_) PDone)))

  // pullTake: n < length.
  checkIntListEq("pullTake: n < length",
    [1, 2, 3],
    collect(pullTake(toPull(emits([1, 2, 3, 4, 5])), 3)))

  // pullTake: n >= length.
  checkIntListEq("pullTake: n >= length",
    [1, 2],
    collect(pullTake(toPull(emits([1, 2])), 10)))

  // pullTake: n = 0.
  checkIntListEq("pullTake: n = 0",
    [],
    collect(pullTake(toPull(emits([1, 2, 3])), 0)))

  // pullTake: n < 0.
  checkIntListEq("pullTake: n < 0",
    [],
    collect(pullTake(toPull(emits([1, 2, 3])), -5)))

  // pullDrop: n < length.
  checkIntListEq("pullDrop: n < length",
    [4, 5],
    collect(pullDrop(toPull(emits([1, 2, 3, 4, 5])), 3)))

  // pullDrop: n >= length.
  checkIntListEq("pullDrop: n >= length",
    [],
    collect(pullDrop(toPull(emits([1, 2])), 10)))

  // pullDrop: n = 0 -> identity.
  checkIntListEq("pullDrop: n = 0",
    [1, 2, 3],
    collect(pullDrop(toPull(emits([1, 2, 3])), 0)))

  // pullTakeWhile: stops at first failure.
  checkIntListEq("pullTakeWhile: prefix",
    [1, 2, 3],
    collect(pullTakeWhile(toPull(emits([1, 2, 3, 4, 1, 2])), fn(x) x < 4)))

  // pullTakeWhile: first fails -> empty.
  checkIntListEq("pullTakeWhile: first fails",
    [],
    collect(pullTakeWhile(toPull(emits([10, 1, 2])), fn(x) x < 5)))

  // pullTakeWhile: all pass -> full.
  checkIntListEq("pullTakeWhile: all pass",
    [1, 2, 3],
    collect(pullTakeWhile(toPull(emits([1, 2, 3])), fn(x) x < 100)))

  // pullChunkN + pullUnchunks round-trip preserves values.
  checkIntListEq("pullChunkN + pullUnchunks: round-trip",
    [1, 2, 3, 4, 5],
    collect(pullUnchunks(pullChunkN(toPull(emits([1, 2, 3, 4, 5])), 2))))

  // pullChunkN: n <= 0 yields empty.
  checkIntListEq("pullChunkN: n <= 0",
    [],
    collect(pullUnchunks(pullChunkN(toPull(emits([1, 2, 3])), 0))))

pub fun main() : io ()
  val (passed, total) = runSuite("core/pull", suiteBody)
  if passed == total then ()
  else throw("core_pull_test: " ++ show(total - passed) ++ " failed")
