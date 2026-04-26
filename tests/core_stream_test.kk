module core_stream_test

import std/core/undiv
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

  // ---- dropWhile ----------------------------------------------------------

  checkIntListEq("dropWhile: drops prefix, then forwards rest",
    [4, 1, 2],
    emits([1, 2, 3, 4, 1, 2]).dropWhile(fn(x) x < 4).compile.toList())

  checkIntListEq("dropWhile: predicate false from start keeps everything",
    [1, 2, 3],
    emits([1, 2, 3]).dropWhile(fn(x) x > 100).compile.toList())

  checkIntListEq("dropWhile: predicate always true drops everything",
    [],
    emits([1, 2, 3]).dropWhile(fn(_) True).compile.toList())

  // After the first failure all subsequent values pass through, even those
  // that would satisfy the predicate — this distinguishes dropWhile from filter.
  checkIntListEq("dropWhile: after first failure, all values forwarded",
    [4, 1, 5, 2],
    emits([1, 2, 3, 4, 1, 5, 2]).dropWhile(fn(x) x < 4).compile.toList())

  checkIntListEq("dropWhile: empty source",
    [],
    empty().dropWhile(fn(_) True).compile.toList())

  // ---- scan ---------------------------------------------------------------

  // Seed is emitted first, before any input is consumed.
  checkIntListEq("scan: emits seed then running sums",
    [0, 1, 3, 6, 10],
    emits([1, 2, 3, 4]).scan(0, fn(acc, x) acc + x).compile.toList())

  checkIntListEq("scan: empty source still emits seed",
    [42],
    empty().scan(42, fn(acc, x : int) acc + x).compile.toList())

  checkIntListEq("scan: running maximum",
    [0, 3, 3, 5, 5, 9],
    emits([3, 1, 5, 2, 9]).scan(0, fn(acc, x) if x > acc then x else acc).compile.toList())

  checkIntListEq("scan + take: bounded prefix",
    [0, 1, 3],
    emits([1, 2, 3, 4, 5]).scan(0, fn(acc, x) acc + x).take(3).compile.toList())

  // ---- zipWith / zip (finite sources) -------------------------------------

  checkIntListEq("zipWith: equal lengths sum",
    [11, 22, 33],
    pretend-no-div(fn() zipWith(emits([1, 2, 3]), emits([10, 20, 30]), fn(a, b) a + b).compile.toList()))

  checkIntListEq("zipWith: left shorter stops at min",
    [11, 22],
    pretend-no-div(fn() zipWith(emits([1, 2]), emits([10, 20, 30, 40]), fn(a, b) a + b).compile.toList()))

  checkIntListEq("zipWith: right shorter stops at min",
    [11, 22],
    pretend-no-div(fn() zipWith(emits([1, 2, 3, 4]), emits([10, 20]), fn(a, b) a + b).compile.toList()))

  checkIntListEq("zipWith: empty left",
    [],
    pretend-no-div(fn() zipWith(empty(), emits([1, 2, 3]), fn(a : int, b : int) a + b).compile.toList()))

  checkIntListEq("zipWith: empty right",
    [],
    pretend-no-div(fn() zipWith(emits([1, 2, 3]), empty(), fn(a : int, b : int) a + b).compile.toList()))

  val pairs = pretend-no-div(fn() zip(emits([1, 2, 3]), emits([10, 20, 30])).compile.toList())
  checkIntEq("zip: length matches", 3, pairs.length)
  checkIntListEq("zip: first components",  [1, 2, 3],      pairs.map(fn(p) p.fst))
  checkIntListEq("zip: second components", [10, 20, 30],   pairs.map(fn(p) p.snd))

  // ---- exec ---------------------------------------------------------------

  val r1 = ref(0)
  val zs : list<int> = exec(fn() r1 := !r1 + 100).compile.toList()
  checkIntListEq("exec: emits nothing", [], zs)
  checkIntEq("exec: side effect ran once", 100, !r1)

  val r2 = ref(0)
  val ws = append(exec(fn() r2 := 1), emits([10, 20, 30])).compile.toList()
  checkIntListEq("exec + append: values flow after setup", [10, 20, 30], ws)
  checkIntEq("exec + append: side effect observed", 1, !r2)

pub fun main() : io ()
  val (passed, total) = runSuite("core/stream", suiteBody)
  if passed == total then ()
  else throw("core_stream_test: " ++ show(total - passed) ++ " failed")
