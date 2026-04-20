module nagare/core/stream

import nagare/core/types
import nagare/core/pull

// Create a pull that outputs a single chunk from a list.
fun fromListPull<a,e>(xs : list<a>) : pull<a,e>
  POutput(Chunk(xs), PDone)

// Create a pull that evaluates thunks lazily, one element per chunk.
fun fromEvalsPull<a,e>(thunks : list<() -> e a>) : pull<a,e>
  match thunks
    []            -> PDone
    Cons(th, tt)  -> PEval(fn() POutput(Chunk([th()]), fromEvalsPull(tt)))

// Concatenate a list of streams into one stream.
fun concatList<a,e>(streams : list<nstream<a,e>>) : nstream<a,e>
  match streams
    []            -> Stream(PDone)
    Cons(s, st)   -> append(s, concatList(st))

// A stream with no output.
pub fun empty<a,e>() : nstream<a,e>
  Stream(PDone)

// Emit a single value as a stream.
pub fun emit<a,e>(value : a) : nstream<a,e>
  Stream(POutput(Chunk([value]), PDone))

// Alias of emit (pure value into a stream).
pub fun pure<a,e>(value : a) : nstream<a,e>
  emit(value)

// Lazily evaluate an effectful thunk to emit one value.
// The row `e` is whatever effects the thunk performs.
pub fun eval<a,e>(thunk : () -> e a) : nstream<a,e>
  Stream(PEval(fn() POutput(Chunk([thunk()]), PDone)))

// Attach acquire/release finalizers to a stream (executed LIFO by the runtime).
pub fun managed<a,e>(source : nstream<a,e>, acquire : () -> e (), release : () -> e ()) : nstream<a,e>
  match source
    Stream(step) -> Stream(PAcquire(acquire, release, step))

// Emit all values from a list as one chunk.
pub fun emits<a,e>(values : list<a>) : nstream<a,e>
  Stream(fromListPull(values))

// Lazily evaluate a list of thunks into a stream of values.
pub fun evals<a,e>(thunks : list<() -> e a>) : nstream<a,e>
  Stream(fromEvalsPull(thunks))

// Concatenate multiple streams.
pub fun concat<a,e>(streams : list<nstream<a,e>>) : nstream<a,e>
  concatList(streams)

// Append two streams (right stream is delayed until left completes).
pub fun append<a,e>(left : nstream<a,e>, right : nstream<a,e>) : nstream<a,e>
  match left
    Stream(leftPull) ->
      match right
        Stream(rightPull) ->
          Stream(pullAppend(leftPull, fn() rightPull))

// Transform each emitted value with a pure function.
pub fun map<a,b,e>(source : nstream<a,e>, f : a -> b) : nstream<b,e>
  match source
    Stream(step) -> Stream(pullMap(step, f))

// Transform each emitted value with an effectful function.
pub fun evalMap<a,b,e>(source : nstream<a,e>, f : a -> e b) : nstream<b,e>
  flatMap(source, fn(x)
    eval(fn() f(x))
  )

// Run an effect for each emitted value, preserving the original value.
pub fun evalTap<a,e>(source : nstream<a,e>, f : a -> e ()) : nstream<a,e>
  flatMap(source, fn(x)
    eval(fn()
      f(x)
      x
    )
  )

// Keep only the first n emitted values.
pub fun take<a,e>(source : nstream<a,e>, n : int) : nstream<a,e>
  match source
    Stream(step) -> Stream(pullTake(step, n))

// Drop the first n emitted values.
pub fun drop<a,e>(source : nstream<a,e>, n : int) : nstream<a,e>
  match source
    Stream(step) -> Stream(pullDrop(step, n))

// Keep values while predicate holds; stop at first failure.
pub fun takeWhile<a,e>(source : nstream<a,e>, pred : a -> bool) : nstream<a,e>
  match source
    Stream(step) -> Stream(pullTakeWhile(step, pred))

// Re-chunk the stream into fixed-size chunks.
pub fun chunkN<a,e>(source : nstream<a,e>, n : int) : nstream<chunk<a>,e>
  match source
    Stream(step) -> Stream(pullChunkN(step, n))

// Flatten a stream of chunks back into a stream of values.
pub fun unchunks<a,e>(source : nstream<chunk<a>,e>) : nstream<a,e>
  match source
    Stream(step) -> Stream(pullUnchunks(step))

// Keep only values that satisfy a predicate.
pub fun filter<a,e>(source : nstream<a,e>, pred : a -> bool) : nstream<a,e>
  match source
    Stream(step) -> Stream(pullFilter(step, pred))

// Expand each value into a stream and concatenate results.
pub fun flatMap<a,b,e>(source : nstream<a,e>, f : a -> nstream<b,e>) : nstream<b,e>
  match source
    Stream(step) ->
      Stream(pullFlatMap(step, fn(x)
        match f(x)
          Stream(nextStep) -> nextStep
      ))

// Pipe a stream through a reusable transformation.
pub fun through<a,b,e>(source : nstream<a,e>, p : pipe<a,b,e>) : nstream<b,e>
  p(source)

// ---------------------------------------------------------------------------
// Emitter DSL
//
// Users write imperative-style stream producers with `streamOf`:
//
//   streamOf { emit(1); emit(2); emitAll([3,4,5]) }
//
// The handler compiles each `emit`/`emitAll` call into a `POutput` node,
// with the continuation suspended in a `PEval` so the pull remains lazy.
// The pull ADT is preserved as the IR; this is purely a front-end convenience.
// ---------------------------------------------------------------------------

pub effect emitter<a>
  ctl yieldOne( x : a ) : ()
  ctl yieldAll( xs : list<a> ) : ()

// Build a stream from an imperative body that calls yieldOne/yieldAll.
pub fun streamOf<a,e>( body : () -> <emitter<a>|e> () ) : e nstream<a,e>
  Stream(streamOfPull(body))

fun streamOfPull<a,e>( body : () -> <emitter<a>|e> () ) : e pull<a,e>
  with handler
    ctl yieldOne(x)
      POutput(Chunk([x]), PEval(fn() resume(())))
    ctl yieldAll(xs)
      match xs
        [] -> resume(())
        _  -> POutput(Chunk(xs), PEval(fn() resume(())))
  body()
  PDone
