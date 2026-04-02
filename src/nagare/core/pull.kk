module nagare/core/pull

import nagare/core/types

// Append two lists (internal helper).
fun listAppend<a>(xs : list<a>, ys : list<a>) : list<a>
  match xs
    []            -> ys
    Cons(x, xt)   -> Cons(x, listAppend(xt, ys))

// Map over all elements in a chunk.
fun chunkMap<a,b>(c : chunk<a>, f : a -> b) : chunk<b>
  match c
    Chunk(values) -> Chunk(values.map(f))

// Filter elements inside a chunk (may produce empty chunk).
fun chunkFilter<a>(c : chunk<a>, pred : a -> bool) : chunk<a>
  match c
    Chunk(values) -> Chunk(values.filter(pred))

// Sequence two pulls, evaluating the right pull only when the left is done.
pub fun pullAppend<a>(left : pull<a>, right : () -> pull<a>) : pull<a>
  match left
    PDone                -> right()
    POutput(out, tail)   -> POutput(out, pullAppend(tail, right))
    PEval(next)          -> PEval(fn() pullAppend(next(), right))
    PAcquire(acquire, release, tail) ->
      PAcquire(acquire, release, pullAppend(tail, right))

// Map a function over all outputs of a pull (preserves eval/acquire structure).
pub fun pullMap<a,b>(source : pull<a>, f : a -> b) : pull<b>
  match source
    PDone                -> PDone
    POutput(out, tail)   -> POutput(chunkMap(out, f), pullMap(tail, f))
    PEval(next)          -> PEval(fn() pullMap(next(), f))
    PAcquire(acquire, release, tail) ->
      PAcquire(acquire, release, pullMap(tail, f))

// Filter outputs of a pull (preserves eval/acquire structure).
pub fun pullFilter<a>(source : pull<a>, pred : a -> bool) : pull<a>
  match source
    PDone                -> PDone
    POutput(out, tail)   -> POutput(chunkFilter(out, pred), pullFilter(tail, pred))
    PEval(next)          -> PEval(fn() pullFilter(next(), pred))
    PAcquire(acquire, release, tail) ->
      PAcquire(acquire, release, pullFilter(tail, pred))

// FlatMap a list of values into pulls and concatenate results.
fun flatMapChunk<a,b>(values : list<a>, f : a -> pull<b>) : pull<b>
  match values
    []            -> PDone
    Cons(x, xt)   -> pullAppend(f(x), fn() flatMapChunk(xt, f))

// FlatMap a pull by expanding each emitted value into a pull and concatenating.
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

