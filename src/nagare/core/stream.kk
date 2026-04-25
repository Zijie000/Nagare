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

// Unbounded source: emits seed, f(seed), f(f(seed)), ... one per step.
// Each step is wrapped in PEval so the pull stays lazy — only consumed
// elements are materialised. Safe under `take(n)` and other early-stop
// combinators; consuming without a bound will not terminate.
// Unbounded source: emits seed, f(seed), f(f(seed)), ... one per step.
// Each step is wrapped in PEval so the pull stays lazy — only consumed
// elements are materialised. Safe under `take(n)` and other early-stop
// combinators; consuming without a bound will not terminate.
//
// The `div` effect on the resulting stream's row reflects that fact: any
// pipeline that drains an `iterate` without bounding it is divergent, and
// Koka tracks that statically. Bound it with `take`/`takeWhile` to use it
// in an `io`-only context (handlers can mask `div` once a bound is proven).
pub fun iterate<a,e>(seed : a, f : a -> a) : div nstream<a,<div|e>>
  Stream(iteratePull(seed, f))

fun iteratePull<a,e>(seed : a, f : a -> a) : div pull<a,<div|e>>
  POutput(Chunk([seed]), PEval(fn() iteratePull(f(seed), f)))

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

// Drop the longest prefix while predicate holds; emit everything afterwards.
// Once an element fails the predicate, all subsequent elements are forwarded
// even if they would have satisfied it.
pub fun dropWhile<a,e>(source : nstream<a,e>, pred : a -> bool) : nstream<a,e>
  match source
    Stream(step) -> Stream(pullDropWhile(step, pred))

// Emit `init`, then `step(init, x1)`, then `step(step(init, x1), x2)`, ...
// The seed is always the first emitted value, even on an empty source.
pub fun scan<a,b,e>(source : nstream<a,e>, init : b, step : (b, a) -> b) : nstream<b,e>
  match source
    Stream(s) -> Stream(pullScan(s, init, step))

// Combine two streams element-wise with `f`. The result terminates as soon as
// either side terminates; finalizers from the side that produced data are
// preserved on the resulting stream so resource safety is maintained.
//
// Carries `div` because zipWith is implemented by repeatedly stepping both
// pulls — Koka cannot prove termination structurally.
pub fun zipWith<a,b,c,e>(left : nstream<a,<div|e>>, right : nstream<b,<div|e>>, f : (a, b) -> c) : div nstream<c,<div|e>>
  match left
    Stream(ls) ->
      match right
        Stream(rs) -> Stream(pullZipWith(ls, rs, f))

// Combine two streams into a stream of pairs.
pub fun zip<a,b,e>(left : nstream<a,<div|e>>, right : nstream<b,<div|e>>) : div nstream<(a,b),<div|e>>
  zipWith(left, right, fn(x, y) (x, y))

// Repeat a finite stream forever. Like `iterate`, the result is divergent in
// the type system; bound it with `take`/`takeWhile` to consume.
pub fun repeat<a,e>(source : nstream<a,<div|e>>) : div nstream<a,<div|e>>
  match source
    Stream(s) -> Stream(repeatPull(s, s))

fun repeatPull<a,e>(original : pull<a,<div|e>>, current : pull<a,<div|e>>) : div pull<a,<div|e>>
  match current
    PDone ->
      PEval(fn() repeatPull(original, original))
    POutput(out, tail) ->
      POutput(out, repeatPull(original, tail))
    PEval(next) ->
      PEval(fn() repeatPull(original, next()))
    PAcquire(acquire, release, tail) ->
      PAcquire(acquire, release, repeatPull(original, tail))

// Re-evaluate an effectful thunk forever, emitting one value per step.
// Each emission is wrapped in `PEval` so the pull stays lazy: the thunk
// only runs when the consumer actually pulls a value.
//
// The thunk's row already includes `div` because the resulting stream is
// unbounded — callers must supply a thunk typed at `<div|e>`. In practice
// this is a no-op (an `io` thunk is happy to inhabit `<div|io>`), and it
// dodges Koka's reluctance to subsume `e` into `<div|e>` at lambda
// boundaries.
pub fun repeatEval<a,e>(thunk : () -> <div|e> a) : div nstream<a,<div|e>>
  iterate((), fn(_) ()).evalMap(fn(_) thunk())

// Run an effectful action once for its side effect; emit nothing.
// Useful for sequencing setup/teardown into a pipeline without producing data.
pub fun exec<a,e>(action : () -> e ()) : nstream<a,e>
  Stream(PEval(fn()
    action()
    PDone
  ))

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
