module nagare/interpreter

import nagare/core/types

pub value type trace-event<a>
  con TraceEval
  con TraceEmit( value : a )

pub alias sink<a,b> = nstream<a> -> io b
pub type compile-scope<a>
  con Compile( source : nstream<a> )

type runtime<a>
  con Runtime( step : pull<a>, finalizersRev : list<() -> io ()> )

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
fun runFinalizersRev(finalizersRev : list<() -> io ()>) : io ()
  match finalizersRev
    [] -> ()
    Cons(release, rest) ->
      release()
      runFinalizersRev(rest)

// Initialize runtime state for a stream (no finalizers registered yet).
fun runtimeFromStream<a>(source : nstream<a>) : runtime<a>
  Runtime(source.toPull, [])

// Record TraceEmit events for values, accumulating in reverse.
fun pushTraceEventsRev<a>(values : list<a>, eventsRev : list<trace-event<a>>) : list<trace-event<a>>
  match values
    []            -> eventsRev
    Cons(x, xt)   -> pushTraceEventsRev(xt, Cons(TraceEmit(x), eventsRev))

// Take next element from a chunk, returning remaining pull state.
fun nextFromChunk<a>(values : list<a>, tail : pull<a>) : maybe2<a,pull<a>>
  match values
    [] ->
      Nothing2
    Cons(x, xt) ->
      match xt
        [] -> Just2(x, tail)
        _  -> Just2(x, POutput(Chunk(xt), tail))

// Step runtime to produce the next element, running finalizers on completion.
fun nextItemRuntime<a>(state : runtime<a>) : io maybe2<a,runtime<a>>
  match state
    Runtime(PDone, finalizersRev) ->
      runFinalizersRev(finalizersRev)
      Nothing2
    Runtime(POutput(out, tail), finalizersRev) ->
      match out
        Chunk(values) ->
          match nextFromChunk(values, tail)
            Nothing2 ->
              nextItemRuntime(Runtime(tail, finalizersRev))
            Just2(x, rem) ->
              Just2(x, Runtime(rem, finalizersRev))
    Runtime(PEval(next), finalizersRev) ->
      nextItemRuntime(Runtime(next(), finalizersRev))
    Runtime(PAcquire(acquire, release, tail), finalizersRev) ->
      acquire()
      nextItemRuntime(Runtime(tail, Cons(release, finalizersRev)))

// Collect all elements into a list.
fun collectRuntime<a>(state : runtime<a>, accRev : list<a>) : io list<a>
  match nextItemRuntime(state)
    Nothing2 ->
      listReverse(accRev)
    Just2(x, nextState) ->
      collectRuntime(nextState, Cons(x, accRev))

// Consume all elements, discarding outputs.
fun drainRuntime<a>(state : runtime<a>) : io ()
  match nextItemRuntime(state)
    Nothing2 ->
      ()
    Just2(_, nextState) ->
      drainRuntime(nextState)

// Consume all elements and return the last (or Nothing).
fun lastRuntime<a>(state : runtime<a>, current : maybe<a>) : io maybe<a>
  match nextItemRuntime(state)
    Nothing2 ->
      current
    Just2(x, nextState) ->
      lastRuntime(nextState, Just(x))

// Fold all elements using an accumulator.
fun foldRuntime<a,b>(state : runtime<a>, init : b, step : (b, a) -> b) : io b
  match nextItemRuntime(state)
    Nothing2 ->
      init
    Just2(x, nextState) ->
      foldRuntime(nextState, step(init, x), step)

// Interpret a pull, collecting emitted values and trace events.
fun traceCompileGoPull<a>(
  state : pull<a>,
  finalizersRev : list<() -> io ()>,
  valuesRev : list<a>,
  eventsRev : list<trace-event<a>>
) : io (list<a>, list<trace-event<a>>)
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
pub fun toListSink<a>() : sink<a,list<a>>
  fn(source) collectRuntime(runtimeFromStream(source), [])

// Sink that drains a stream for its effects only.
pub fun drainSink<a>() : sink<a,()>
  fn(source) drainRuntime(runtimeFromStream(source))

// Sink that returns the last element (or Nothing).
pub fun lastSink<a>() : sink<a,maybe<a>>
  fn(source) lastRuntime(runtimeFromStream(source), Nothing)

// Sink that folds outputs with an initial value and step function.
pub fun foldSink<a,b>(init : b, step : (b, a) -> b) : sink<a,b>
  fn(source) foldRuntime(runtimeFromStream(source), init, step)

// Sink that returns both outputs and a trace of eval/emit events.
pub fun traceSink<a>() : sink<a,(list<a>, list<trace-event<a>>)>
  fn(source) traceCompileGoPull(source.toPull, [], [], [])

// Execute a stream description with a sink interpreter.
pub fun run<a,b>(source : nstream<a>, s : sink<a,b>) : io b
  s(source)

// Create a compile scope for chain-style execution.
pub fun compile<a>(source : nstream<a>) : compile-scope<a>
  Compile(source)

// Execute a compile scope with a sink.
pub fun runCompile<a,b>(c : compile-scope<a>, s : sink<a,b>) : io b
  match c
    Compile(source) -> run(source, s)

// Convenience: run with toListSink.
pub fun toList<a>(c : compile-scope<a>) : io list<a>
  runCompile(c, toListSink())

// Convenience: run with drainSink.
pub fun drain<a>(c : compile-scope<a>) : io ()
  runCompile(c, drainSink())

// Convenience: run with lastSink.
pub fun last<a>(c : compile-scope<a>) : io maybe<a>
  runCompile(c, lastSink())

// Convenience: run with foldSink.
pub fun fold<a,b>(c : compile-scope<a>, init : b, step : (b, a) -> b) : io b
  runCompile(c, foldSink(init, step))

// Convenience: run with traceSink.
pub fun trace<a>(c : compile-scope<a>) : io (list<a>, list<trace-event<a>>)
  runCompile(c, traceSink())

// Transform the result of a sink.
pub fun mapResult<a,b,c>(s : sink<a,b>, f : b -> c) : sink<a,c>
  fn(source) f(s(source))

// Zip two sinks by running both and pairing results.
// Note: this traverses the source twice.
pub fun zipSinks<a,b,c>(left : sink<a,b>, right : sink<a,c>) : sink<a,(b,c)>
  fn(source) (left(source), right(source))
