// effect_pipeline.kk — Row-polymorphic effects in Nagare
//
// Run: koka -e --builddir=.koka -isrc examples/effect_pipeline.kk
//
// Nagare streams carry an open effect row `e`.  A pipeline typed
// `nstream<a, <logger|io>>` promises exactly which effects it may perform —
// no monad transformer stacks, no lifting.  Handlers are installed *outside*
// compile/run, which means:
//   • any combinator (evalMap, flatMap, through) can pass user effects through
//   • the handler site determines *when* the effect is discharged
//   • two independent effects can be threaded simultaneously

module effect_pipeline

import nagare/core/types
import nagare/core/stream
import nagare/core/interpreter

// ── User-defined effects ──────────────────────────────────────────────────

pub effect logger
  fun log( msg : string ) : ()

pub effect counter
  fun tick() : ()
  fun total() : int

// ── Handlers ──────────────────────────────────────────────────────────────

fun withLogger( msgs : ref<global, list<string>>, action : () -> <logger,read<global>,write<global>|e> a ) : <read<global>,write<global>|e> a
  with handler
    fun log(msg) { msgs := Cons(msg, !msgs) }
  action()

fun withCounter( action : () -> <counter|e> a ) : e (a, int)
  var n := 0
  with handler
    fun tick()   { n := n + 1 }
    fun total()  n
  val result = action()
  (result, n)

// ── Example pipeline ──────────────────────────────────────────────────────

// A pipe that logs and counts every element it sees.
// Its type `pipe<int,int,<logger,counter|e>>` precisely documents the side
// effects — no surprises for the caller.
fun auditPipe<e>() : pipe<int, int, <logger,counter|e>>
  fn(source)
    source.evalMap(fn(x)
      log("visiting " ++ show(x))
      tick()
      x
    )

pub fun main() : io ()
  // ── 1. streamOf source that directly performs user effects ───────────────
  // Inside a `streamOf` block you can call `log` (a user-defined effect) right
  // next to `yieldOne` — no `eval` / `evalMap` wrapping needed.  The DSL
  // handler weaves each yield into a lazy POutput while user effects flow out
  // into the surrounding row, ready to be discharged by `withLogger`.
  val msgs1 = ref([])
  val result1 =
    withLogger(msgs1)
      val src = streamOf
        log("emit 1")
        yieldOne(1)
        log("emit 2")
        yieldOne(2)
        log("emit 3")
        yieldOne(3)
      src.map(fn(x) x * 2).compile.toList()
  println("doubled:  " ++ show(result1))
  println("log:      " ++ show((!msgs1).reverse))
  println("")

  // ── 2. Two effects threaded simultaneously ────────────────────────────────
  // `withLogger` and `withCounter` are nested — neither knows about the other.
  val msgs2 = ref([])
  val (result2, count2) =
    withCounter(fn()
      withLogger(msgs2)
        emits([10, 20, 30])
          .through(auditPipe())
          .filter(fn(x) x > 15)
          .compile.toList()
    )
  println("filtered:  " ++ show(result2))
  println("visited:   " ++ show(count2) ++ " elements")
  println("log:       " ++ show((!msgs2).reverse))
  println("")

  // ── 3. Effect survives flatMap boundaries ─────────────────────────────────
  // Each inner `emits` is expanded by flatMap; the outer logger effect reaches
  // *inside* the expansion because the row is open all the way down.
  val msgs3 = ref([])
  val result3 =
    withLogger(msgs3)
      emits([1, 2])
        .flatMap(fn(x)
          eval(fn()
            log("outer-" ++ show(x))
            x
          ).flatMap(fn(v)
            emits([v, v * 10]).evalMap(fn(y)
              log("inner-" ++ show(y))
              y
            )
          )
        )
        .compile.toList()
  println("flatMap:  " ++ show(result3))
  println("log:      " ++ show((!msgs3).reverse))
