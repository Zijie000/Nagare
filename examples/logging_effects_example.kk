module logging_effects_example

import nagare/core/types
import nagare/core/stream
import nagare/interpreter

fun sourceValue(n : int) : io int
  println("[eval] producing " ++ show(n))
  n

fun expand(x : int)
  eval(fn()
    println("[flatMap] expanding " ++ show(x))
    x * 10
  )

fun transform(source : nstream<int>) : nstream<int>
  source
    .map(fn(x) x + 100)
    .flatMap(expand)
    .filter(fn(x) (x % 2) == 0)

fun showTraceEvent(ev : trace-event<int>) : string
  match ev
    TraceEval -> "eval"
    TraceEmit(x) -> "emit(" ++ show(x) ++ ")"

fun main() : io ()
  val mockSource = concat([
    emits([40, 41]),
    evals([fn() sourceValue(1), fn() sourceValue(2), fn() sourceValue(3)]),
    emits([42])
  ])
  val transformed = mockSource.through(transform)

  println("== compile interpreter: compile.toList() ==")
  val out = transformed.compile.toList()
  println("[result] " ++ show(out))

  println("== compile interpreter: compile.last() ==")
  val lastVal = transformed.compile.last()
  println("[last] " ++ show(lastVal))

  println("== compile interpreter: compile.trace() ==")
  val traceRun = transformed.compile.trace()
  match traceRun
    (vals, events) ->
      println("[trace values] " ++ show(vals))
      println("[trace events] " ++ show(events.map(showTraceEvent)))
