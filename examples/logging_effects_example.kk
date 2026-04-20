module logging_effects_example

import nagare/core/types
import nagare/core/stream
import nagare/core/interpreter

fun enrichWithLog(x : int)
  println("[effectful step] enrich " ++ show(x))
  x + 100

fun expand(x : int)
  x * 5

fun tapExpanded(x : int)
  println("[evalTap] observed " ++ show(x))

// Core combinator showcase: chaining evalMap, evalTap, map, and filter.
fun transform(source : iostream<int>) : iostream<int>
  source
    .evalMap(enrichWithLog)
    .evalTap(tapExpanded)
    .map(expand)
    .filter(fn(x) (x % 2) == 0)

fun showTraceEvent(ev : trace-event<int>) : string
  match ev
    TraceEval -> "eval"
    TraceEmit(x) -> "emit(" ++ show(x) ++ ")"

fun main() : io ()
  // Pure source values only; effects are expressed in transform steps.
  val mockSource = emits([40, 41, 1, 2, 3, 42, 43, 44, 45, 46, 47, 48])
  val transformed = mockSource.through(transform)

  println("== compile interpreter: compile.toList() ==")
  val out = transformed.compile.toList()
  println("[result] " ++ show(out))

  println("== compile interpreter: compile.last() ==")
  val lastVal = transformed.compile.last()
  println("[last] " ++ show(lastVal))

  // compile.trace() is for debugging this example only; it has no other role here.
  println("== compile interpreter: compile.trace() ==")
  val traceRun = transformed.compile.trace()
  match traceRun
    (vals, events) ->
      println("[trace values] " ++ show(vals))
      println("[trace events] " ++ show(events.map(showTraceEvent)))
