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

fun listReverse<a>(xs : list<a>) : list<a>
  fun go(rest : list<a>, acc : list<a>) : list<a>
    match rest
      []            -> acc
      Cons(x, xt)   -> go(xt, Cons(x, acc))
  go(xs, [])

fun consAllRev<a>(xs : list<a>, accRev : list<a>) : list<a>
  match xs
    []            -> accRev
    Cons(x, xt)   -> consAllRev(xt, Cons(x, accRev))

fun lastInList<a>(xs : list<a>, fallback : maybe<a>) : maybe<a>
  match xs
    []            -> fallback
    Cons(x, xt)   -> lastInList(xt, Just(x))

fun foldList<a,b>(xs : list<a>, init : b, step : (b, a) -> b) : b
  match xs
    []            -> init
    Cons(x, xt)   -> foldList(xt, step(init, x), step)

fun runFinalizersRev(finalizersRev : list<() -> io ()>) : io ()
  match finalizersRev
    [] -> ()
    Cons(release, rest) ->
      release()
      runFinalizersRev(rest)

fun runtimeFromStream<a>(source : nstream<a>) : runtime<a>
  Runtime(source.toPull, [])

fun pushTraceEventsRev<a>(values : list<a>, eventsRev : list<trace-event<a>>) : list<trace-event<a>>
  match values
    []            -> eventsRev
    Cons(x, xt)   -> pushTraceEventsRev(xt, Cons(TraceEmit(x), eventsRev))

fun nextFromChunk<a>(values : list<a>, tail : pull<a>) : maybe2<a,pull<a>>
  match values
    [] ->
      Nothing2
    Cons(x, xt) ->
      match xt
        [] -> Just2(x, tail)
        _  -> Just2(x, POutput(Chunk(xt), tail))

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

fun collectRuntime<a>(state : runtime<a>, accRev : list<a>) : io list<a>
  match nextItemRuntime(state)
    Nothing2 ->
      listReverse(accRev)
    Just2(x, nextState) ->
      collectRuntime(nextState, Cons(x, accRev))

fun drainRuntime<a>(state : runtime<a>) : io ()
  match nextItemRuntime(state)
    Nothing2 ->
      ()
    Just2(_, nextState) ->
      drainRuntime(nextState)

fun lastRuntime<a>(state : runtime<a>, current : maybe<a>) : io maybe<a>
  match nextItemRuntime(state)
    Nothing2 ->
      current
    Just2(x, nextState) ->
      lastRuntime(nextState, Just(x))

fun foldRuntime<a,b>(state : runtime<a>, init : b, step : (b, a) -> b) : io b
  match nextItemRuntime(state)
    Nothing2 ->
      init
    Just2(x, nextState) ->
      foldRuntime(nextState, step(init, x), step)

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

pub fun toListSink<a>() : sink<a,list<a>>
  fn(source) collectRuntime(runtimeFromStream(source), [])

pub fun drainSink<a>() : sink<a,()>
  fn(source) drainRuntime(runtimeFromStream(source))

pub fun lastSink<a>() : sink<a,maybe<a>>
  fn(source) lastRuntime(runtimeFromStream(source), Nothing)

pub fun foldSink<a,b>(init : b, step : (b, a) -> b) : sink<a,b>
  fn(source) foldRuntime(runtimeFromStream(source), init, step)

pub fun traceSink<a>() : sink<a,(list<a>, list<trace-event<a>>)>
  fn(source) traceCompileGoPull(source.toPull, [], [], [])

pub fun run<a,b>(source : nstream<a>, s : sink<a,b>) : io b
  s(source)

pub fun compile<a>(source : nstream<a>) : compile-scope<a>
  Compile(source)

pub fun runCompile<a,b>(c : compile-scope<a>, s : sink<a,b>) : io b
  match c
    Compile(source) -> run(source, s)

pub fun toList<a>(c : compile-scope<a>) : io list<a>
  runCompile(c, toListSink())

pub fun drain<a>(c : compile-scope<a>) : io ()
  runCompile(c, drainSink())

pub fun last<a>(c : compile-scope<a>) : io maybe<a>
  runCompile(c, lastSink())

pub fun fold<a,b>(c : compile-scope<a>, init : b, step : (b, a) -> b) : io b
  runCompile(c, foldSink(init, step))

pub fun trace<a>(c : compile-scope<a>) : io (list<a>, list<trace-event<a>>)
  runCompile(c, traceSink())

pub fun mapResult<a,b,c>(s : sink<a,b>, f : b -> c) : sink<a,c>
  fn(source) f(s(source))

// Zip two sinks by running both and pairing results.
// Note: this traverses the source twice.
pub fun zipSinks<a,b,c>(left : sink<a,b>, right : sink<a,c>) : sink<a,(b,c)>
  fn(source) (left(source), right(source))
