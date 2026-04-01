module nagare/core/stream

import nagare/core/types
import nagare/core/pull

fun fromListPull<a>(xs : list<a>) : pull<a>
  POutput(Chunk(xs), PDone)

fun fromEvalsPull<a>(thunks : list<() -> io a>) : pull<a>
  match thunks
    []            -> PDone
    Cons(th, tt)  -> PEval(fn() POutput(Chunk([th()]), fromEvalsPull(tt)))

fun concatList<a>(streams : list<nstream<a>>) : nstream<a>
  match streams
    []            -> Stream(PDone)
    Cons(s, st)   -> append(s, concatList(st))

pub fun empty<a>() : nstream<a>
  Stream(PDone)

pub fun emit<a>(value : a) : nstream<a>
  Stream(POutput(Chunk([value]), PDone))

pub fun pure<a>(value : a) : nstream<a>
  emit(value)

pub fun eval<a>(thunk : () -> io a) : nstream<a>
  Stream(PEval(fn() POutput(Chunk([thunk()]), PDone)))

// Register acquire/release lifecycle for this stream.
// Finalizers are executed by the compile runtime in LIFO order.
pub fun managed<a>(source : nstream<a>, acquire : () -> io (), release : () -> io ()) : nstream<a>
  match source
    Stream(step) -> Stream(PAcquire(acquire, release, step))

pub fun emits<a>(values : list<a>) : nstream<a>
  Stream(fromListPull(values))

pub fun evals<a>(thunks : list<() -> io a>) : nstream<a>
  Stream(fromEvalsPull(thunks))

pub fun concat<a>(streams : list<nstream<a>>) : nstream<a>
  concatList(streams)

pub fun append<a>(left : nstream<a>, right : nstream<a>) : nstream<a>
  match left
    Stream(leftPull) ->
      match right
        Stream(rightPull) ->
          Stream(pullAppend(leftPull, fn() rightPull))

pub fun map<a,b>(source : nstream<a>, f : a -> b) : nstream<b>
  match source
    Stream(step) -> Stream(pullMap(step, f))

pub fun filter<a>(source : nstream<a>, pred : a -> bool) : nstream<a>
  match source
    Stream(step) -> Stream(pullFilter(step, pred))

pub fun flatMap<a,b>(source : nstream<a>, f : a -> nstream<b>) : nstream<b>
  match source
    Stream(step) ->
      Stream(pullFlatMap(step, fn(x)
        match f(x)
          Stream(nextStep) -> nextStep
      ))

pub fun through<a,b>(source : nstream<a>, p : pipe<a,b>) : nstream<b>
  p(source)

