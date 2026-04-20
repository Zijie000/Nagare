module core_stream_test

import nagare/core/types
import nagare/core/stream
import nagare/core/interpreter
import test_harness

pub fun suiteBody() : <test-ctx,io> ()
  // empty: yields nothing.
  checkIntListEq("empty: no output",
    [],
    empty().compile.toList())

  // emit: single value.
  checkIntListEq("emit: one value",
    [42],
    emit(42).compile.toList())

  // emits: multi value.
  checkIntListEq("emits: list",
    [1, 2, 3],
    emits([1, 2, 3]).compile.toList())

  // map: transforms values.
  checkIntListEq("map",
    [10, 20, 30],
    emits([1, 2, 3]).map(fn(x) x * 10).compile.toList())

  // filter: keeps matches.
  checkIntListEq("filter",
    [2, 4],
    emits([1, 2, 3, 4, 5]).filter(fn(x) (x % 2) == 0).compile.toList())

  // append: sequential.
  checkIntListEq("append",
    [1, 2, 3, 4],
    append(emits([1, 2]), emits([3, 4])).compile.toList())

  // concat: many.
  checkIntListEq("concat: three streams",
    [1, 2, 3, 4, 5, 6],
    concat([emits([1, 2]), emits([3, 4]), emits([5, 6])]).compile.toList())

  // concat: empty list yields empty.
  checkIntListEq("concat: empty list",
    [],
    concat([]).compile.toList())

  // flatMap: expand each.
  checkIntListEq("flatMap",
    [1, 1, 2, 2, 3, 3],
    emits([1, 2, 3]).flatMap(fn(x) emits([x, x])).compile.toList())

  // take.
  checkIntListEq("take",
    [1, 2, 3],
    emits([1, 2, 3, 4, 5]).take(3).compile.toList())

  // drop.
  checkIntListEq("drop",
    [4, 5],
    emits([1, 2, 3, 4, 5]).drop(3).compile.toList())

  // takeWhile.
  checkIntListEq("takeWhile",
    [1, 2, 3],
    emits([1, 2, 3, 4, 1, 2]).takeWhile(fn(x) x < 4).compile.toList())

  // eval: runs effectful thunk once.
  checkIntListEq("eval",
    [99],
    eval(fn() 99).compile.toList())

  // evalMap: per-element effectful map.
  checkIntListEq("evalMap",
    [2, 3, 4],
    emits([1, 2, 3]).evalMap(fn(x) x + 1).compile.toList())

  // evalTap: preserves values.
  checkIntListEq("evalTap: values unchanged",
    [1, 2, 3],
    emits([1, 2, 3]).evalTap(fn(_) ()).compile.toList())

  // through: pipe.
  checkIntListEq("through",
    [10, 20],
    emits([1, 2]).through(fn(s) s.map(fn(x) x * 10)).compile.toList())

  // chunkN + unchunks round-trip.
  checkIntListEq("chunkN + unchunks round-trip",
    [1, 2, 3, 4, 5],
    emits([1, 2, 3, 4, 5]).chunkN(2).unchunks().compile.toList())

  // pure alias of emit.
  checkIntListEq("pure",
    [7],
    pure(7).compile.toList())

  // Composition: filter then map.
  checkIntListEq("filter then map",
    [20, 40],
    emits([1, 2, 3, 4, 5])
      .filter(fn(x) (x % 2) == 0)
      .map(fn(x) x * 10)
      .compile.toList())

  // streamOf: imperative-style source with yieldOne.
  checkIntListEq("streamOf: yieldOne sequence",
    [1, 2, 3],
    streamOf({ yieldOne(1); yieldOne(2); yieldOne(3) }).compile.toList())

  // streamOf: yieldAll emits a batch in one step.
  checkIntListEq("streamOf: yieldAll",
    [10, 20, 30],
    streamOf({ yieldAll([10, 20, 30]) }).compile.toList())

  // streamOf: mix of yieldOne and yieldAll.
  checkIntListEq("streamOf: mixed yieldOne and yieldAll",
    [1, 2, 3, 4, 5],
    streamOf({ yieldOne(1); yieldAll([2, 3, 4]); yieldOne(5) }).compile.toList())

pub fun main() : io ()
  val (passed, total) = runSuite("core/stream", suiteBody)
  if passed == total then ()
  else throw("core_stream_test: " ++ show(total - passed) ++ " failed")
