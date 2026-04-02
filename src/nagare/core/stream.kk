module nagare/core/stream

import nagare/core/types
import nagare/core/pull

// Create a pull that outputs a single chunk from a list.
fun fromListPull<a>(xs : list<a>) : pull<a>
  POutput(Chunk(xs), PDone)

// Create a pull that evaluates thunks lazily, one element per chunk.
fun fromEvalsPull<a>(thunks : list<() -> io a>) : pull<a>
  match thunks
    []            -> PDone
    Cons(th, tt)  -> PEval(fn() POutput(Chunk([th()]), fromEvalsPull(tt)))

// Concatenate a list of streams into one stream.
fun concatList<a>(streams : list<nstream<a>>) : nstream<a>
  match streams
    []            -> Stream(PDone)
    Cons(s, st)   -> append(s, concatList(st))

// A stream with no output.
pub fun empty<a>() : nstream<a>
  Stream(PDone)

// Emit a single value as a stream.
pub fun emit<a>(value : a) : nstream<a>
  Stream(POutput(Chunk([value]), PDone))

// Alias of emit (pure value into a stream).
pub fun pure<a>(value : a) : nstream<a>
  emit(value)

// Lazily evaluate an effectful thunk to emit one value.
pub fun eval<a>(thunk : () -> io a) : nstream<a>
  Stream(PEval(fn() POutput(Chunk([thunk()]), PDone)))

// Attach acquire/release finalizers to a stream (executed LIFO by the runtime).
pub fun managed<a>(source : nstream<a>, acquire : () -> io (), release : () -> io ()) : nstream<a>
  match source
    Stream(step) -> Stream(PAcquire(acquire, release, step))

// Emit all values from a list as one chunk.
pub fun emits<a>(values : list<a>) : nstream<a>
  Stream(fromListPull(values))

// Lazily evaluate a list of thunks into a stream of values.
pub fun evals<a>(thunks : list<() -> io a>) : nstream<a>
  Stream(fromEvalsPull(thunks))

// Concatenate multiple streams.
pub fun concat<a>(streams : list<nstream<a>>) : nstream<a>
  concatList(streams)

// Append two streams (right stream is delayed until left completes).
pub fun append<a>(left : nstream<a>, right : nstream<a>) : nstream<a>
  match left
    Stream(leftPull) ->
      match right
        Stream(rightPull) ->
          Stream(pullAppend(leftPull, fn() rightPull))

// Transform each emitted value with a pure function.
pub fun map<a,b>(source : nstream<a>, f : a -> b) : nstream<b>
  match source
    Stream(step) -> Stream(pullMap(step, f))

// Keep only values that satisfy a predicate.
pub fun filter<a>(source : nstream<a>, pred : a -> bool) : nstream<a>
  match source
    Stream(step) -> Stream(pullFilter(step, pred))

// Expand each value into a stream and concatenate results.
pub fun flatMap<a,b>(source : nstream<a>, f : a -> nstream<b>) : nstream<b>
  match source
    Stream(step) ->
      Stream(pullFlatMap(step, fn(x)
        match f(x)
          Stream(nextStep) -> nextStep
      ))

// Pipe a stream through a reusable transformation.
pub fun through<a,b>(source : nstream<a>, p : pipe<a,b>) : nstream<b>
  p(source)

