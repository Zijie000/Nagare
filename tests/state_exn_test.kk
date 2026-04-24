module state_exn_test

import nagare/core/types
import nagare/core/stream
import nagare/core/interpreter
import test_harness

// ---------------------------------------------------------------------------
// Verify state + exn effects flow through combinators, and that an exception
// raised inside evalMap aborts the pipeline while state accumulated before
// the abort survives (handlers are installed outside the sink).
// ---------------------------------------------------------------------------

effect counter
  fun tick( by : int ) : ()
  fun total() : int

effect parseExn
  ctl parseFail( input : string, reason : string ) : int

fun withCounter( action : () -> <counter|e> a ) : e (a, int)
  var n := 0
  with handler
    fun tick(by) { n := n + by }
    fun total()  n
  val result = action()
  (result, n)

fun catchParse( action : () -> <parseExn|e> a ) : e either<string, a>
  with handler
    ctl parseFail(input, reason)
      Left("parse failed on " ++ input ++ ": " ++ reason)
  Right(action())

fun parsePipeline( inputs : list<string> ) : <counter, parseExn, io> list<int>
  emits(inputs)
    .evalMap(fn(s)
      match s.parse-int
        Just(n) -> { tick(1); n }
        Nothing -> parseFail(s, "bad")
    )
    .compile.toList()

pub fun suiteBody() : <test-ctx,io> ()
  // ---- (1) clean run: no exn, state threaded through ----
  val (r1, c1) = withCounter(fn() catchParse(fn() parsePipeline(["1","2","3"])))
  match r1
    Right(xs) -> checkIntListEq("clean run: values", [1,2,3], xs)
    Left(_)   -> check("clean run: unexpected error", False)
  checkIntEq("clean run: counter = 3 ticks", 3, c1)

  // ---- (2) abort run: exn partway through, state preserved up to abort ----
  val (r2, c2) = withCounter(fn() catchParse(fn() parsePipeline(["10","20","oops","40"])))
  match r2
    Right(_) -> check("abort run: should have failed", False)
    Left(_)  -> check("abort run: caught exception", True)
  checkIntEq("abort run: counter ticked twice before abort", 2, c2)

  // ---- (3) multi-effect row: effects discharge independently ----
  // Swap handler order to verify the two effects don't interfere.
  val r3 = catchParse(fn()
    val (xs, n) = withCounter(fn() parsePipeline(["5", "6"]))
    (xs, n)
  )
  match r3
    Right((xs, n)) ->
      checkIntListEq("swapped order: values", [5, 6], xs)
      checkIntEq("swapped order: counter", 2, n)
    Left(_) ->
      check("swapped order: unexpected error", False)

pub fun main() : io ()
  val (passed, total) = runSuite("effect/state+exn", suiteBody)
  if passed == total then ()
  else throw("state_exn_test: " ++ show(total - passed) ++ " failed")
