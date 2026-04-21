module row_polymorphism_example

// This example demonstrates the three properties that distinguish Nagare from FS2:
//
//   1. Row-polymorphic effects — a user-defined `pipeline` effect flows through
//      combinators (evalMap, flatMap, take) and is discharged by a handler
//      installed *outside* compile/run, without any lifting or wrapping.
//
//   2. streamOf DSL — sources are written in an imperative style using
//      yieldOne / yieldAll; the handler compiles each call into a lazy POutput
//      node while preserving the pull ADT as the internal IR.
//
//   3. Resource safety via managed — acquire/release finalizers are embedded
//      directly in the stream graph and executed LIFO by the interpreter,
//      with no typeclass constraint required.

import nagare/core/types
import nagare/core/stream
import nagare/core/interpreter

// ---------------------------------------------------------------------------
// A user-defined effect: structured pipeline logging.
// In FS2 this would require a monad transformer or a custom F[_].
// Here it is a plain Koka effect — open, composable, zero boilerplate.
// ---------------------------------------------------------------------------

effect pipeline
  fun step( stage : string, msg : string ) : ()

// Discharge the effect by printing structured log lines.
fun withPipelineLogger( action : () -> <pipeline|io> a ) : io a
  with handler
    fun step(stage, msg)
      println("[" ++ stage ++ "] " ++ msg)
  action()

// ---------------------------------------------------------------------------
// Example 1: streamOf — imperative source authoring
//
// Compare with FS2:  Stream(1,2,3) ++ Stream.emits(List(4,5))
// ---------------------------------------------------------------------------

fun demoStreamOf() : <pipeline|io> ()
  println("\n== 1. streamOf: imperative source ==")
  val source = streamOf
    yieldOne(1)
    yieldOne(2)
    yieldAll([3, 4, 5])
  val result = source.compile.toList()
  step("source", "emitted: " ++ show(result))

// ---------------------------------------------------------------------------
// Example 2: user effect crossing combinator boundaries
//
// The `pipeline` effect is introduced inside evalMap — a combinator boundary.
// The handler is installed outside compile/run, not inside each lambda.
// In FS2 this pattern requires the effect to be threaded through F[_] or
// handled with EitherT / WriterT stacks. Here it is structural.
// ---------------------------------------------------------------------------

fun demoEffectAcrossBoundaries() : <pipeline|io> ()
  println("\n== 2. user effect crossing combinator boundaries ==")
  val result =
    streamOf { yieldAll([1, 2, 3, 4, 5]) }
      .evalMap(fn(x)
        step("filter-stage", "evaluating " ++ show(x))
        x * 10
      )
      .filter(fn(x) x > 15)
      .evalMap(fn(x)
        step("map-stage", "keeping " ++ show(x))
        x
      )
      .compile.toList()
  step("result", show(result))

// ---------------------------------------------------------------------------
// Example 3: managed resources + user effect + early termination
//
// The `pipeline` effect flows through managed, flatMap, and take together.
// Finalizers run LIFO regardless of early termination — no MonadCancel needed.
// ---------------------------------------------------------------------------

fun demoManagedWithEffect() : <pipeline|io> ()
  println("\n== 3. managed resources with user effect and take ==")
  val log = ref([])
  fun record(msg : string) : <read<global>,write<global>> ()
    log := Cons(msg, !log)
  val source =
    managed(
      streamOf { yieldAll([10, 20, 30, 40, 50]) },
      fn() { record("acquire"); step("resource", "file opened") },
      fn() { record("release"); step("resource", "file closed") }
    )
  // take(3) triggers early termination — finalizer must still run.
  val result = source.take(3).compile.toList()
  step("result", show(result))
  val events = (!log).reverse
  step("finalizer-order", show(events))

// ---------------------------------------------------------------------------
// Example 4: streamOf as a transformation — combining DSL with pipeline effect
// ---------------------------------------------------------------------------

fun demoStreamOfWithEffect() : <pipeline|io> ()
  println("\n== 4. streamOf source piped through effectful combinators ==")
  val result =
    streamOf
      yieldOne("alpha")
      yieldOne("beta")
      yieldAll(["gamma", "delta"])
    .evalMap(fn(s)
      step("enrich", s)
      s ++ "-enriched"
    )
    .take(3)
    .compile.toList()
  step("result", show(result))

// ---------------------------------------------------------------------------
// Entry point: all demos run under a single handler installed here.
// The `pipeline` effect is discharged once, outside all stream operations.
// ---------------------------------------------------------------------------

pub fun main() : io ()
  withPipelineLogger
    demoStreamOf()
    demoEffectAcrossBoundaries()
    demoManagedWithEffect()
    demoStreamOfWithEffect()
  println("\n== done ==")
