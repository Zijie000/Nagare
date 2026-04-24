module state_exn_example

// ---------------------------------------------------------------------------
// State + Exception effects flowing through a stream pipeline.
//
// This example demonstrates two user-defined effects threaded through a
// single stream of values:
//
//   1. `counter` — a stateful effect that accumulates counts (tick + total).
//   2. `parseExn` — a user-defined exception effect raised inside evalMap
//                   when a value cannot be parsed.
//
// Both effects appear in the stream row at the combinator boundary:
//
//   nstream<int, <counter, parseExn, io>>
//
// and are discharged by handlers installed *outside* the sink. No monad
// transformer stacks, no EitherT/WriterT gymnastics — the effect row just
// carries them, and combinators stay row-polymorphic.
//
// Compare with FS2: threading state through `F[_]` requires either `StateT`
// or explicit `Ref`; threading typed errors requires `EitherT` or a custom
// `MonadError`. Here both are structural.
// ---------------------------------------------------------------------------

import nagare/core/types
import nagare/core/stream
import nagare/core/interpreter

// ---------------------------------------------------------------------------
// User-defined effects.
// ---------------------------------------------------------------------------

// Stateful: tick advances the counter; total reads the current value.
effect counter
  fun tick( by : int ) : ()
  fun total() : int

// Typed exception: `parseFail` aborts the current pipeline with a reason.
// `ctl` rather than `fun` so the handler can decide whether to resume —
// here we never resume, making it a true exception.
effect parseExn
  ctl parseFail( input : string, reason : string ) : int

// ---------------------------------------------------------------------------
// Handlers. Installed outside the sink; the stream row is discharged here.
// ---------------------------------------------------------------------------

// `counter` threaded by a local `var` — no Ref, no io pollution.
fun withCounter( action : () -> <counter|e> a ) : e (a, int)
  var n := 0
  with handler
    fun tick(by) { n := n + by }
    fun total()  n
  val result = action()
  (result, n)

// `parseExn` discharged to `either<string, a>` — left holds the error reason.
fun catchParse( action : () -> <parseExn|e> a ) : e either<string, a>
  with handler
    ctl parseFail(input, reason)
      Left("failed to parse \"" ++ input ++ "\": " ++ reason)
  Right(action())

// ---------------------------------------------------------------------------
// A pipeline that both threads state and may raise typed errors.
//
// Source: a list of decimal strings, some invalid.
// evalMap: parse each — valid ones call `tick` and emit the int;
//          invalid ones call `parseFail`, which aborts the whole pipeline.
// ---------------------------------------------------------------------------

fun parseInt(s : string) : maybe<int>
  s.parse-int

fun parsePipeline( inputs : list<string> ) : <counter, parseExn, io> list<int>
  emits(inputs)
    .evalMap(fn(s)
      match parseInt(s)
        Just(n) ->
          tick(1)
          n
        Nothing ->
          parseFail(s, "not a decimal integer")
    )
    .evalTap(fn(n)
      tick(n)  // second state update: accumulate sum into counter
    )
    .compile.toList()

// ---------------------------------------------------------------------------
// Entry point. Run twice: once with clean input (no exn), once with a bad
// token (forces parseFail). Both runs thread state; the second run ends
// via the exn handler returning `Left`.
// ---------------------------------------------------------------------------

pub fun main() : io ()
  println("== run 1: all valid inputs ==")
  val (result1, count1) = withCounter(fn()
    catchParse(fn()
      parsePipeline(["1", "2", "3", "4", "5"])
    )
  )
  match result1
    Right(xs) -> println("  values: " ++ show(xs))
    Left(err) -> println("  error: " ++ err)
  println("  counter total (count + sum): " ++ show(count1))

  println("\n== run 2: input contains an unparseable token ==")
  val (result2, count2) = withCounter(fn()
    catchParse(fn()
      parsePipeline(["10", "20", "oops", "40"])
    )
  )
  match result2
    Right(xs) -> println("  values: " ++ show(xs))
    Left(err) -> println("  error: " ++ err)
  // Counter reflects only the values processed before the exception aborted.
  println("  counter total before abort: " ++ show(count2))

  println("\n== done ==")
