module effect_e2e_test

// End-to-end test: verifies that a user-defined effect (`logger`) can flow
// through stream combinators and be discharged by an *external* handler
// before the sink runs — the runtime payoff of row-polymorphic sink<a,b,e>.
//
// Prior architecture (sink<a,b> = nstream<a,io> -> io b) made this impossible:
// a `<logger|io>` source could not cross combinator boundaries into a sink.
// The widened signature (sink<a,b,e> = nstream<a,<io|e>> -> <io|e> b) removes
// that barrier. This suite is the proof.

import nagare/core/types
import nagare/core/stream
import nagare/core/interpreter
import test_harness

// ---------------------------------------------------------------------------
// User-defined effect: logger
// ---------------------------------------------------------------------------

pub effect logger
  fun logMsg( msg : string ) : ()

// Discharge logger by appending to a ref list.
fun withLogger(
  log : ref<global, list<string>>,
  action : () -> <logger|io> a
) : io a
  with handler
    fun logMsg(msg)
      log := Cons(msg, !log)
  action()

// ---------------------------------------------------------------------------
// Streams that use the logger effect directly (not inside eval lambdas)
// ---------------------------------------------------------------------------

// A source that logs each emit as it flows through the stream graph.
fun loggedSource(xs : list<int>) : nstream<int, <logger|io>>
  concat(xs.map(fn(x)
    eval(fn()
      logMsg("emit-" ++ show(x))
      x
    )
  ))

// A pipe that logs each element it transforms.
fun loggedDouble<e>() : pipe<int, int, <logger|e>>
  fn(source)
    source.evalMap(fn(x)
      logMsg("double-" ++ show(x))
      x * 2
    )

pub fun suiteBody() : <test-ctx,io> ()
  // ---- (1) User effect flows through eval and is discharged externally ----
  // The logger effect is introduced inside `eval` thunks in the source.
  // The handler is installed *outside* compile/run — verifying that the effect
  // truly crosses the sink boundary rather than being trapped inside a lambda.
  val log1 = ref([])
  val result1 =
    withLogger(log1)
      loggedSource([1, 2, 3]).compile.toList()
  checkIntListEq("e2e logger: correct values emitted", [1, 2, 3], result1)
  checkStrListEq("e2e logger: emit events recorded",
    ["emit-1", "emit-2", "emit-3"], (!log1).reverse)

  // ---- (2) User effect flows through a pipe combinator ----
  // loggedDouble introduces logger inside evalMap — a combinator boundary.
  // The handler is still outside compile/run.
  val log2 = ref([])
  val result2 =
    withLogger(log2)
      emits([10, 20]).through(loggedDouble()).compile.toList()
  checkIntListEq("e2e logger through pipe: doubled values", [20, 40], result2)
  checkStrListEq("e2e logger through pipe: double events recorded",
    ["double-10", "double-20"], (!log2).reverse)

  // ---- (3) Effect survives flatMap (combinator nesting) ----
  val log3 = ref([])
  val result3 =
    withLogger(log3)
      emits([1, 2]).flatMap(fn(x)
        eval(fn()
          logMsg("inner-" ++ show(x))
          x * 10
        )
      ).compile.toList()
  checkIntListEq("e2e logger through flatMap: values", [10, 20], result3)
  check("e2e logger through flatMap: inner events recorded",
    (!log3).length == 2)

pub fun main() : io ()
  val (passed, total) = runSuite("effect/e2e row-polymorphism", suiteBody)
  if passed == total then ()
  else throw("effect_e2e_test: " ++ show(total - passed) ++ " failed")
