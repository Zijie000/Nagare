module nagare/core/pull

import nagare/core/types

fun listAppend<a>(xs : list<a>, ys : list<a>) : list<a>
  match xs
    []            -> ys
    Cons(x, xt)   -> Cons(x, listAppend(xt, ys))

fun chunkMap<a,b>(c : chunk<a>, f : a -> b) : chunk<b>
  match c
    Chunk(values) -> Chunk(values.map(f))

fun chunkFilter<a>(c : chunk<a>, pred : a -> bool) : chunk<a>
  match c
    Chunk(values) -> Chunk(values.filter(pred))

pub fun pullAppend<a>(left : pull<a>, right : () -> pull<a>) : pull<a>
  match left
    PDone                -> right()
    POutput(out, tail)   -> POutput(out, pullAppend(tail, right))
    PEval(next)          -> PEval(fn() pullAppend(next(), right))
    PAcquire(acquire, release, tail) ->
      PAcquire(acquire, release, pullAppend(tail, right))

pub fun pullMap<a,b>(source : pull<a>, f : a -> b) : pull<b>
  match source
    PDone                -> PDone
    POutput(out, tail)   -> POutput(chunkMap(out, f), pullMap(tail, f))
    PEval(next)          -> PEval(fn() pullMap(next(), f))
    PAcquire(acquire, release, tail) ->
      PAcquire(acquire, release, pullMap(tail, f))

pub fun pullFilter<a>(source : pull<a>, pred : a -> bool) : pull<a>
  match source
    PDone                -> PDone
    POutput(out, tail)   -> POutput(chunkFilter(out, pred), pullFilter(tail, pred))
    PEval(next)          -> PEval(fn() pullFilter(next(), pred))
    PAcquire(acquire, release, tail) ->
      PAcquire(acquire, release, pullFilter(tail, pred))

fun flatMapChunk<a,b>(values : list<a>, f : a -> pull<b>) : pull<b>
  match values
    []            -> PDone
    Cons(x, xt)   -> pullAppend(f(x), fn() flatMapChunk(xt, f))

pub fun pullFlatMap<a,b>(source : pull<a>, f : a -> pull<b>) : pull<b>
  match source
    PDone ->
      PDone
    POutput(out, tail) ->
      match out
        Chunk(values) ->
          pullAppend(flatMapChunk(values, f), fn() pullFlatMap(tail, f))
    PEval(next) ->
      PEval(fn() pullFlatMap(next(), f))
    PAcquire(acquire, release, tail) ->
      PAcquire(acquire, release, pullFlatMap(tail, f))

