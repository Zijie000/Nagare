module core_interpreter_test

import nagare/core/types
import nagare/core/stream
import nagare/core/interpreter
import test_harness

pub fun suiteBody() : <test-ctx,io> ()
  // toList: basic collection.
  checkIntListEq("toList: collects in order",
    [1, 2, 3],
    emits([1, 2, 3]).compile.toList())

  // drain: returns unit on empty.
  emits([1, 2, 3]).compile.drain()
  check("drain: completes", True)

  // last: last element of non-empty.
  val lastOf123 = emits([1, 2, 3]).compile.last()
  match lastOf123
    Just(v) -> checkIntEq("last: non-empty", 3, v)
    Nothing -> check("last: non-empty (got Nothing)", False)

  // last: Nothing on empty.
  val lastOfEmpty = empty().compile.last()
  match lastOfEmpty
    Nothing -> check("last: empty returns Nothing", True)
    Just(_) -> check("last: empty returned Just (should be Nothing)", False)

  // fold: sum.
  checkIntEq("fold: sum",
    15,
    emits([1, 2, 3, 4, 5]).compile.fold(0, fn(acc, x) acc + x))

  // fold: on empty returns init.
  checkIntEq("fold: empty returns init",
    100,
    empty().compile.fold(100, fn(acc, x : int) acc + x))

  // Resource finalizers run in LIFO order.
  val logRef = ref([])
  fun logEvent(msg : string) : <read<global>,write<global>> ()
    logRef := Cons(msg, !logRef)
  val managedSource =
    managed(
      managed(emits([1, 2]), fn() logEvent("acq-inner"), fn() logEvent("rel-inner")),
      fn() logEvent("acq-outer"),
      fn() logEvent("rel-outer"))
  val _result = managedSource.compile.toList()
  val eventsInOrder =
    match !logRef
      [] -> []
      xs -> xs.reverse
  // Acquire runs outer-before-inner (as scopes are entered); release runs LIFO (inner-before-outer).
  checkStrListEq("managed: acquire/release ordering (LIFO release)",
    ["acq-outer", "acq-inner", "rel-inner", "rel-outer"],
    eventsInOrder)

  // trace: emits TraceEval for PEval and TraceEmit for each value.
  val traced = emits([1, 2]).evalMap(fn(x) x + 10).compile.trace()
  match traced
    (values, events) ->
      checkIntListEq("trace: values collected", [11, 12], values)
      // Per evalMap impl: each element produces one eval + one emit event.
      checkIntEq("trace: event count", 4, events.length)

  // mapResult: post-process sink output.
  val doubledSum = runCompile(
    emits([1, 2, 3]).compile,
    mapResult(foldSink(0, fn(a, b) a + b), fn(x) x * 2))
  checkIntEq("mapResult: double the fold result", 12, doubledSum)

  // zipSinks: runs both sinks (note: traverses source twice — only safe for pure sources).
  val zipped = runCompile(
    emits([1, 2, 3]).compile,
    zipSinks(foldSink(0, fn(a, b) a + b), toListSink()))
  match zipped
    (sum, xs) ->
      checkIntEq("zipSinks: sum side", 6, sum)
      checkIntListEq("zipSinks: list side", [1, 2, 3], xs)

  // take + drop interplay through interpreter.
  checkIntListEq("take + drop: drop(1).take(2) of [1..5]",
    [2, 3],
    emits([1, 2, 3, 4, 5]).drop(1).take(2).compile.toList())

pub fun main() : io ()
  val (passed, total) = runSuite("core/interpreter", suiteBody)
  if passed == total then ()
  else throw("core_interpreter_test: " ++ show(total - passed) ++ " failed")
