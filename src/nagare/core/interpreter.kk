module nagare/core/interpreter

import std/core/hnd
import nagare/core/types

pub value type trace-event<a>
  con TraceEval
  con TraceEmit( value : a )

// Sinks consume streams at any row containing `io`. Pure streams (e = <>)
// coerce into `<io|e>` automatically. User effects (e.g. `fileIO`) flow
// through the sink and must be discharged by an ambient handler.
pub alias sink<a,b,e> = nstream<a,<io|e>> -> <io|e> b
pub type compile-scope<a,e>
  con Compile( source : nstream<a,<io|e>> )

// Runtime carries the current pull state plus a shared finalizer stack.
// The stack lives in a ref so that `finally` can release resources even when
// a sink returns early or an exception unwinds the stream.
type runtime<a,e>
  con Runtime( step : pull<a,<io|e>>, finalizers : ref<global, list<() -> <io|e> ()>> )

// Reverse a list (internal helper).
fun listReverse<a>(xs : list<a>) : list<a>
  fun go(rest : list<a>, acc : list<a>) : list<a>
    match rest
      []            -> acc
      Cons(x, xt)   -> go(xt, Cons(x, acc))
  go(xs, [])

// Prepend all elements of a list onto an accumulator in reverse order.
fun consAllRev<a>(xs : list<a>, accRev : list<a>) : list<a>
  match xs
    []            -> accRev
    Cons(x, xt)   -> consAllRev(xt, Cons(x, accRev))

// Get the last element of a list, or fallback if empty.
fun lastInList<a>(xs : list<a>, fallback : maybe<a>) : maybe<a>
  match xs
    []            -> fallback
    Cons(x, xt)   -> lastInList(xt, Just(x))

// Strict left fold over a list.
fun foldList<a,b>(xs : list<a>, init : b, step : (b, a) -> b) : b
  match xs
    []            -> init
    Cons(x, xt)   -> foldList(xt, step(init, x), step)

// Run finalizers in LIFO order.
fun runFinalizersRev<e>(finalizersRev : list<() -> <io|e> ()>) : <io|e> ()
  match finalizersRev
    [] -> ()
    Cons(release, rest) ->
      release()
      runFinalizersRev(rest)

// Initialize runtime state for a stream (no finalizers registered yet).
fun runtimeFromStream<a,e>(source : nstream<a,<io|e>>) : <io|e> runtime<a,e>
  Runtime(source.toPull, ref([]))

// Run all currently registered finalizers in LIFO order, clearing the stack.
// Safe to call multiple times: subsequent calls see an empty stack and no-op.
fun closeRuntime<a,e>(state : runtime<a,e>) : <io|e> ()
  match state
    Runtime(_, finalizers) ->
      val pending = !finalizers
      finalizers := []
      runFinalizersRev(pending)

// Bracket a sink body so finalizers always run, even on early return or exception.
fun withRuntime<a,b,e>(source : nstream<a,<io|e>>, body : runtime<a,e> -> <io|e> b) : <io|e> b
  val state = runtimeFromStream(source)
  finally({ closeRuntime(state) }, { body(state) })

// Record TraceEmit events for values, accumulating in reverse.
fun pushTraceEventsRev<a>(values : list<a>, eventsRev : list<trace-event<a>>) : list<trace-event<a>>
  match values
    []            -> eventsRev
    Cons(x, xt)   -> pushTraceEventsRev(xt, Cons(TraceEmit(x), eventsRev))

// Take next element from a chunk, returning remaining pull state.
fun nextFromChunk<a,e>(values : list<a>, tail : pull<a,<io|e>>) : maybe2<a,pull<a,<io|e>>>
  match values
    [] ->
      Nothing2
    Cons(x, xt) ->
      match xt
        [] -> Just2(x, tail)
        _  -> Just2(x, POutput(Chunk(xt), tail))

// Step runtime to produce the next element. Finalizers are released by the
// outer `withRuntime` bracket, not here, so early-return sinks stay safe.
fun nextItemRuntime<a,e>(state : runtime<a,e>) : <io|e> maybe2<a,runtime<a,e>>
  match state
    Runtime(PDone, _) ->
      Nothing2
    Runtime(POutput(out, tail), finalizers) ->
      match out
        Chunk(values) ->
          match nextFromChunk(values, tail)
            Nothing2 ->
              nextItemRuntime(Runtime(tail, finalizers))
            Just2(x, rem) ->
              Just2(x, Runtime(rem, finalizers))
    Runtime(PEval(next), finalizers) ->
      nextItemRuntime(Runtime(next(), finalizers))
    Runtime(PAcquire(acquire, release, tail), finalizers) ->
      acquire()
      finalizers := Cons(release, !finalizers)
      nextItemRuntime(Runtime(tail, finalizers))

// Collect all elements into a list.
fun collectRuntime<a,e>(state : runtime<a,e>, accRev : list<a>) : <io|e> list<a>
  match nextItemRuntime(state)
    Nothing2 ->
      listReverse(accRev)
    Just2(x, nextState) ->
      collectRuntime(nextState, Cons(x, accRev))

// Consume all elements, discarding outputs.
fun drainRuntime<a,e>(state : runtime<a,e>) : <io|e> ()
  match nextItemRuntime(state)
    Nothing2 ->
      ()
    Just2(_, nextState) ->
      drainRuntime(nextState)

// Consume all elements and return the last (or Nothing).
fun lastRuntime<a,e>(state : runtime<a,e>, current : maybe<a>) : <io|e> maybe<a>
  match nextItemRuntime(state)
    Nothing2 ->
      current
    Just2(x, nextState) ->
      lastRuntime(nextState, Just(x))

// Fold all elements using an accumulator.
fun foldRuntime<a,b,e>(state : runtime<a,e>, init : b, step : (b, a) -> b) : <io|e> b
  match nextItemRuntime(state)
    Nothing2 ->
      init
    Just2(x, nextState) ->
      foldRuntime(nextState, step(init, x), step)

// Interpret a pull, collecting emitted values and trace events.
fun traceCompileGoPull<a,e>(
  state : pull<a,<io|e>>,
  finalizersRev : list<() -> <io|e> ()>,
  valuesRev : list<a>,
  eventsRev : list<trace-event<a>>
) : <io|e> (list<a>, list<trace-event<a>>)
  match state
    PDone ->
      runFinalizersRev(finalizersRev)
      (listReverse(valuesRev), listReverse(eventsRev))
    POutput(out, tail) ->
      match out
        Chunk(values) ->
          traceCompileGoPull(tail, finalizersRev, consAllRev(values, valuesRev), pushTraceEventsRev(values, eventsRev))
    PEval(next) ->
      traceCompileGoPull(next(), finalizersRev, valuesRev, Cons(TraceEval, eventsRev))
    PAcquire(acquire, release, tail) ->
      acquire()
      traceCompileGoPull(tail, Cons(release, finalizersRev), valuesRev, eventsRev)

// Sink that collects all outputs into a list.
pub fun toListSink<a,e>() : sink<a,list<a>,e>
  fn(source) withRuntime(source, fn(state) collectRuntime(state, []))

// Sink that drains a stream for its effects only.
pub fun drainSink<a,e>() : sink<a,(),e>
  fn(source) withRuntime(source, fn(state) drainRuntime(state))

// Sink that returns the last element (or Nothing).
pub fun lastSink<a,e>() : sink<a,maybe<a>,e>
  fn(source) withRuntime(source, fn(state) lastRuntime(state, Nothing))

// Sink that folds outputs with an initial value and step function.
pub fun foldSink<a,b,e>(init : b, step : (b, a) -> b) : sink<a,b,e>
  fn(source) withRuntime(source, fn(state) foldRuntime(state, init, step))

// Sink that returns both outputs and a trace of eval/emit events.
pub fun traceSink<a,e>() : sink<a,(list<a>, list<trace-event<a>>),e>
  fn(source) traceCompileGoPull(source.toPull, [], [], [])

// Execute a stream description with a sink interpreter.
pub fun run<a,b,e>(source : nstream<a,<io|e>>, s : sink<a,b,e>) : <io|e> b
  s(source)

// Create a compile scope for chain-style execution.
pub fun compile<a,e>(source : nstream<a,<io|e>>) : compile-scope<a,e>
  Compile(source)

// Execute a compile scope with a sink.
pub fun runCompile<a,b,e>(c : compile-scope<a,e>, s : sink<a,b,e>) : <io|e> b
  match c
    Compile(source) -> run(source, s)

// Convenience: run with toListSink.
pub fun toList<a,e>(c : compile-scope<a,e>) : <io|e> list<a>
  runCompile(c, toListSink())

// Convenience: run with drainSink.
pub fun drain<a,e>(c : compile-scope<a,e>) : <io|e> ()
  runCompile(c, drainSink())

// Convenience: run with lastSink.
pub fun last<a,e>(c : compile-scope<a,e>) : <io|e> maybe<a>
  runCompile(c, lastSink())

// Convenience: run with foldSink.
pub fun fold<a,b,e>(c : compile-scope<a,e>, init : b, step : (b, a) -> b) : <io|e> b
  runCompile(c, foldSink(init, step))

// Convenience: run with traceSink.
pub fun trace<a,e>(c : compile-scope<a,e>) : <io|e> (list<a>, list<trace-event<a>>)
  runCompile(c, traceSink())

// Transform the result of a sink.
pub fun mapResult<a,b,c,e>(s : sink<a,b,e>, f : b -> c) : sink<a,c,e>
  fn(source) f(s(source))

// Run two sinks over the same source. Traverses the source twice — only safe
// for pure sources with idempotent effects.
pub fun zipSinks<a,b,c,e>(left : sink<a,b,e>, right : sink<a,c,e>) : sink<a,(b,c),e>
  fn(source) (left(source), right(source))
