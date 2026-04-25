module nagare/core/pull

import nagare/core/types

// Append two lists (internal helper).
fun listAppend<a>(xs : list<a>, ys : list<a>) : list<a>
  match xs
    []            -> ys
    Cons(x, xt)   -> Cons(x, listAppend(xt, ys))

// Length of a list.
fun listLength<a>(xs : list<a>) : int
  match xs
    []            -> 0
    Cons(_, xt)   -> 1 + listLength(xt)

// Keep first n elements from a list.
fun listTakeN<a>(xs : list<a>, n : int) : list<a>
  if n <= 0 then []
  else
    match xs
      []            -> []
      Cons(x, xt)   -> Cons(x, listTakeN(xt, n - 1))

// Drop first n elements from a list.
fun listDropN<a>(xs : list<a>, n : int) : list<a>
  if n <= 0 then xs
  else
    match xs
      []            -> []
      Cons(_, xt)   -> listDropN(xt, n - 1)

// Keep longest prefix while predicate holds.
fun listTakeWhile<a>(xs : list<a>, pred : a -> bool) : list<a>
  match xs
    []            -> []
    Cons(x, xt)   ->
      if pred(x) then Cons(x, listTakeWhile(xt, pred))
      else []

// Drop longest prefix while predicate holds.
fun listDropWhile<a>(xs : list<a>, pred : a -> bool) : list<a>
  match xs
    []            -> []
    Cons(x, xt)   ->
      if pred(x) then listDropWhile(xt, pred)
      else xs

// Reverse a list.
fun listReverse<a>(xs : list<a>) : list<a>
  fun go(rest : list<a>, acc : list<a>) : list<a>
    match rest
      []            -> acc
      Cons(x, xt)   -> go(xt, Cons(x, acc))
  go(xs, [])

// Flatten a list of chunks into one list of values.
fun flattenChunks<a>(chunks : list<chunk<a>>) : list<a>
  match chunks
    [] -> []
    Cons(ch, ct) ->
      match ch
        Chunk(values) -> listAppend(values, flattenChunks(ct))

// Split a list into chunks of size n (last chunk may be smaller).
fun listChunkN<a>(values : list<a>, n : int) : list<chunk<a>>
  fun go(rest : list<a>, curRev : list<a>, curLen : int, chunksRev : list<chunk<a>>) : list<chunk<a>>
    match rest
      [] ->
        match curRev
          [] -> listReverse(chunksRev)
          _  -> listReverse(Cons(Chunk(listReverse(curRev)), chunksRev))
      Cons(x, xt) ->
        val nextRev = Cons(x, curRev)
        val nextLen = curLen + 1
        if nextLen >= n then
          go(xt, [], 0, Cons(Chunk(listReverse(nextRev)), chunksRev))
        else
          go(xt, nextRev, nextLen, chunksRev)
  if n <= 0 then []
  else go(values, [], 0, [])

// Map over all elements in a chunk.
fun chunkMap<a,b>(c : chunk<a>, f : a -> b) : chunk<b>
  match c
    Chunk(values) -> Chunk(values.map(f))

// Filter elements inside a chunk (may produce empty chunk).
fun chunkFilter<a>(c : chunk<a>, pred : a -> bool) : chunk<a>
  match c
    Chunk(values) -> Chunk(values.filter(pred))

// Sequence two pulls, evaluating the right pull only when the left is done.
pub fun pullAppend<a,e>(left : pull<a,e>, right : () -> pull<a,e>) : pull<a,e>
  match left
    PDone                -> right()
    POutput(out, tail)   -> POutput(out, pullAppend(tail, right))
    PEval(next)          -> PEval(fn() pullAppend(next(), right))
    PAcquire(acquire, release, tail) ->
      PAcquire(acquire, release, pullAppend(tail, right))

// Map a function over all outputs of a pull (preserves eval/acquire structure).
pub fun pullMap<a,b,e>(source : pull<a,e>, f : a -> b) : pull<b,e>
  match source
    PDone                -> PDone
    POutput(out, tail)   -> POutput(chunkMap(out, f), pullMap(tail, f))
    PEval(next)          -> PEval(fn() pullMap(next(), f))
    PAcquire(acquire, release, tail) ->
      PAcquire(acquire, release, pullMap(tail, f))

// Filter outputs of a pull (preserves eval/acquire structure).
pub fun pullFilter<a,e>(source : pull<a,e>, pred : a -> bool) : pull<a,e>
  match source
    PDone                -> PDone
    POutput(out, tail)   -> POutput(chunkFilter(out, pred), pullFilter(tail, pred))
    PEval(next)          -> PEval(fn() pullFilter(next(), pred))
    PAcquire(acquire, release, tail) ->
      PAcquire(acquire, release, pullFilter(tail, pred))

// FlatMap a list of values into pulls and concatenate results.
fun flatMapChunk<a,b,e>(values : list<a>, f : a -> pull<b,e>) : pull<b,e>
  match values
    []            -> PDone
    Cons(x, xt)   -> pullAppend(f(x), fn() flatMapChunk(xt, f))

// FlatMap a pull by expanding each emitted value into a pull and concatenating.
pub fun pullFlatMap<a,b,e>(source : pull<a,e>, f : a -> pull<b,e>) : pull<b,e>
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

// Keep only first n outputs from a pull.
pub fun pullTake<a,e>(source : pull<a,e>, n : int) : pull<a,e>
  if n <= 0 then PDone
  else
    match source
      PDone ->
        PDone
      POutput(out, tail) ->
        match out
          Chunk(values) ->
            val len = listLength(values)
            if len <= n then POutput(Chunk(values), pullTake(tail, n - len))
            else POutput(Chunk(listTakeN(values, n)), PDone)
      PEval(next) ->
        PEval(fn() pullTake(next(), n))
      PAcquire(acquire, release, tail) ->
        PAcquire(acquire, release, pullTake(tail, n))

// Drop first n outputs from a pull.
pub fun pullDrop<a,e>(source : pull<a,e>, n : int) : pull<a,e>
  if n <= 0 then source
  else
    match source
      PDone ->
        PDone
      POutput(out, tail) ->
        match out
          Chunk(values) ->
            val len = listLength(values)
            if n >= len then pullDrop(tail, n - len)
            else POutput(Chunk(listDropN(values, n)), tail)
      PEval(next) ->
        PEval(fn() pullDrop(next(), n))
      PAcquire(acquire, release, tail) ->
        PAcquire(acquire, release, pullDrop(tail, n))

// Keep longest prefix satisfying pred; stop at first failure.
pub fun pullTakeWhile<a,e>(source : pull<a,e>, pred : a -> bool) : pull<a,e>
  match source
    PDone ->
      PDone
    POutput(out, tail) ->
      match out
        Chunk(values) ->
          val kept = listTakeWhile(values, pred)
          val rest = listDropWhile(values, pred)
          match kept
            [] -> PDone
            _  ->
              match rest
                [] -> POutput(Chunk(kept), pullTakeWhile(tail, pred))
                _  -> POutput(Chunk(kept), PDone)
    PEval(next) ->
      PEval(fn() pullTakeWhile(next(), pred))
    PAcquire(acquire, release, tail) ->
      PAcquire(acquire, release, pullTakeWhile(tail, pred))

// Re-chunk a pull into fixed-size chunks (last chunk may be smaller).
pub fun pullChunkN<a,e>(source : pull<a,e>, n : int) : pull<chunk<a>,e>
  if n <= 0 then PDone
  else
    match source
      PDone ->
        PDone
      POutput(out, tail) ->
        match out
          Chunk(values) ->
            val chunks = listChunkN(values, n)
            match chunks
              [] -> pullChunkN(tail, n)
              _  -> POutput(Chunk(chunks), pullChunkN(tail, n))
      PEval(next) ->
        PEval(fn() pullChunkN(next(), n))
      PAcquire(acquire, release, tail) ->
        PAcquire(acquire, release, pullChunkN(tail, n))

// Flatten a pull of chunks back into a pull of values.
pub fun pullUnchunks<a,e>(source : pull<chunk<a>,e>) : pull<a,e>
  match source
    PDone ->
      PDone
    POutput(out, tail) ->
      match out
        Chunk(chunks) ->
          val flat = flattenChunks(chunks)
          match flat
            [] -> pullUnchunks(tail)
            _  -> POutput(Chunk(flat), pullUnchunks(tail))
    PEval(next) ->
      PEval(fn() pullUnchunks(next()))
    PAcquire(acquire, release, tail) ->
      PAcquire(acquire, release, pullUnchunks(tail))

// Drop the longest prefix while predicate holds, then emit the rest unchanged.
// Once an element fails the predicate, every subsequent element is forwarded.
pub fun pullDropWhile<a,e>(source : pull<a,e>, pred : a -> bool) : pull<a,e>
  match source
    PDone ->
      PDone
    POutput(out, tail) ->
      match out
        Chunk(values) ->
          val rest = listDropWhile(values, pred)
          match rest
            [] -> pullDropWhile(tail, pred)
            _  -> POutput(Chunk(rest), tail)
    PEval(next) ->
      PEval(fn() pullDropWhile(next(), pred))
    PAcquire(acquire, release, tail) ->
      PAcquire(acquire, release, pullDropWhile(tail, pred))

// Map a chunk through a stateful step, threading the accumulator and emitting
// the post-step accumulator for each input value. Returns (new chunk, new acc).
fun chunkScan<a,b>(values : list<a>, acc : b, step : (b, a) -> b) : (list<b>, b)
  chunkScanGo(values, acc, step, [])

fun chunkScanGo<a,b>(rest : list<a>, cur : b, step : (b, a) -> b, outRev : list<b>) : (list<b>, b)
  match rest
    []            -> (listReverse(outRev), cur)
    Cons(x, xt)   ->
      val next = step(cur, x)
      chunkScanGo(xt, next, step, Cons(next, outRev))

// scan: emits init, then init `step` x1, then (init `step` x1) `step` x2, ...
// The seed is emitted first, before any input is consumed.
pub fun pullScan<a,b,e>(source : pull<a,e>, init : b, step : (b, a) -> b) : pull<b,e>
  POutput(Chunk([init]), pullScanGo(source, init, step))

fun pullScanGo<a,b,e>(source : pull<a,e>, acc : b, step : (b, a) -> b) : pull<b,e>
  match source
    PDone ->
      PDone
    POutput(out, tail) ->
      match out
        Chunk(values) ->
          val (outs, nextAcc) = chunkScan(values, acc, step)
          match outs
            [] -> pullScanGo(tail, nextAcc, step)
            _  -> POutput(Chunk(outs), pullScanGo(tail, nextAcc, step))
    PEval(next) ->
      PEval(fn() pullScanGo(next(), acc, step))
    PAcquire(acquire, release, tail) ->
      PAcquire(acquire, release, pullScanGo(tail, acc, step))

// Step a pull until it produces the next value or terminates. Returns
// `Just2(value, remainingPull)` or `Nothing2` at end-of-stream. Finalizers
// from `PAcquire` nodes encountered while stepping are returned as a list
// (LIFO order) so the caller can install them on its outer scope.
fun unconsPull<a,e>(source : pull<a,e>, fins : list<() -> e ()>) : e maybe2<(a, pull<a,e>), list<() -> e ()>>
  match source
    PDone ->
      Nothing2
    POutput(out, tail) ->
      match out
        Chunk(values) ->
          match values
            [] -> unconsPull(tail, fins)
            Cons(x, xt) ->
              match xt
                [] -> Just2((x, tail), fins)
                _  -> Just2((x, POutput(Chunk(xt), tail)), fins)
    PEval(next) ->
      unconsPull(next(), fins)
    PAcquire(acquire, release, tail) ->
      acquire()
      unconsPull(tail, Cons(release, fins))

// Re-attach a list of finalizers (already in LIFO order) to a pull, so they
// will be released by the interpreter's outer `withRuntime` bracket.
fun reattachFinalizers<a,e>(fins : list<() -> e ()>, tail : pull<a,e>) : pull<a,e>
  match fins
    []            -> tail
    Cons(f, ft)   -> reattachFinalizers(ft, PAcquire(fn() (), f, tail))

// Combine two pulls element-wise with `f`. Stops as soon as either side
// terminates. Stepping each side is effectful, so the result pull defers
// every combine through `PEval`. Carries `div` because the recursion is not
// structurally decreasing — each combine step produces a new `PEval` thunk
// whose body recursively calls back into `pullZipWith`.
pub fun pullZipWith<a,b,c,e>(left : pull<a,<div|e>>, right : pull<b,<div|e>>, f : (a, b) -> c) : div pull<c,<div|e>>
  PEval(fn() pullZipWithStep(left, right, f))

fun pullZipWithStep<a,b,c,e>(left : pull<a,<div|e>>, right : pull<b,<div|e>>, f : (a, b) -> c) : <div|e> pull<c,<div|e>>
  match unconsPull(left, [])
    Nothing2 ->
      PDone
    Just2((x, leftTail), leftFins) ->
      match unconsPull(right, [])
        Nothing2 ->
          reattachFinalizers(leftFins, PDone)
        Just2((y, rightTail), rightFins) ->
          val combined = listAppend(rightFins, leftFins)
          reattachFinalizers(combined,
            POutput(Chunk([f(x, y)]), pullZipWith(leftTail, rightTail, f)))

