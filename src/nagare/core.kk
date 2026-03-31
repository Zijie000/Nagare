module nagare/core

pub type nstream<a>
  con SEmpty
  con SEmit( head : a, tail : nstream<a> )
  con SEval( next : () -> io nstream<a> )

pub alias pipe<a,b> = nstream<a> -> nstream<b>

fun listAppend<a>(xs : list<a>, ys : list<a>) : list<a>
  match xs
    []            -> ys
    Cons(x, xt)   -> Cons(x, listAppend(xt, ys))

fun listReverse<a>(xs : list<a>) : list<a>
  fun go(rest : list<a>, acc : list<a>) : list<a>
    match rest
      []            -> acc
      Cons(x, xt)   -> go(xt, Cons(x, acc))
  go(xs, [])

fun compileToListRev<a>(source : nstream<a>, accRev : list<a>) : io list<a>
  match source
    SEmpty           -> listReverse(accRev)
    SEmit(x, tail)   -> compileToListRev(tail, Cons(x, accRev))
    SEval(next)      -> compileToListRev(next(), accRev)

fun compileLastGo<a>(source : nstream<a>, last : maybe<a>) : io maybe<a>
  match source
    SEmpty           -> last
    SEmit(x, tail)   -> compileLastGo(tail, Just(x))
    SEval(next)      -> compileLastGo(next(), last)

fun streamMap<a,b>(source : nstream<a>, f : a -> b) : nstream<b>
  match source
    SEmpty           -> SEmpty
    SEmit(x, tail)   -> SEmit(f(x), streamMap(tail, f))
    SEval(next)      -> SEval(fn() streamMap(next(), f))

fun streamFilter<a>(source : nstream<a>, pred : a -> bool) : nstream<a>
  match source
    SEmpty           -> SEmpty
    SEmit(x, tail)   ->
      if pred(x) then SEmit(x, streamFilter(tail, pred))
      else streamFilter(tail, pred)
    SEval(next)      -> SEval(fn() streamFilter(next(), pred))

fun streamFold<a,b>(source : nstream<a>, init : b, step : (b, a) -> b) : io b
  match source
    SEmpty           -> init
    SEmit(x, tail)   -> streamFold(tail, step(init, x), step)
    SEval(next)      -> streamFold(next(), init, step)

fun streamDrain<a>(source : nstream<a>) : io ()
  match source
    SEmpty           -> ()
    SEmit(_, tail)   -> streamDrain(tail)
    SEval(next)      -> streamDrain(next())

fun fromList<a>(xs : list<a>) : nstream<a>
  match xs
    []            -> SEmpty
    Cons(x, xt)   -> SEmit(x, fromList(xt))

fun fromEvals<a>(thunks : list<() -> io a>) : nstream<a>
  match thunks
    []            -> SEmpty
    Cons(th, tt)  -> SEval(fn() SEmit(th(), fromEvals(tt)))

fun concatList<a>(streams : list<nstream<a>>) : nstream<a>
  match streams
    []            -> SEmpty
    Cons(s, st)   -> append(s, concatList(st))

pub fun empty<a>() : nstream<a>
  SEmpty

pub fun emit<a>(value : a) : nstream<a>
  SEmit(value, SEmpty)

pub fun pure<a>(value : a) : nstream<a>
  emit(value)

pub fun eval<a>(thunk : () -> io a) : nstream<a>
  SEval(fn() SEmit(thunk(), SEmpty))

pub fun emits<a>(values : list<a>) : nstream<a>
  fromList(values)

pub fun evals<a>(thunks : list<() -> io a>) : nstream<a>
  fromEvals(thunks)

pub fun concat<a>(streams : list<nstream<a>>) : nstream<a>
  concatList(streams)

pub fun append<a>(left : nstream<a>, right : nstream<a>) : nstream<a>
  match left
    SEmpty           -> right
    SEmit(x, tail)   -> SEmit(x, append(tail, right))
    SEval(next)      -> SEval(fn() append(next(), right))

pub fun map<a,b>(source : nstream<a>, f : a -> b) : nstream<b>
  streamMap(source, f)

pub fun filter<a>(source : nstream<a>, pred : a -> bool) : nstream<a>
  streamFilter(source, pred)

pub fun flatMap<a,b>(source : nstream<a>, f : a -> nstream<b>) : nstream<b>
  match source
    SEmpty           -> SEmpty
    SEmit(x, tail)   -> append(f(x), flatMap(tail, f))
    SEval(next)      -> SEval(fn() flatMap(next(), f))

pub fun through<a,b>(source : nstream<a>, p : pipe<a,b>) : nstream<b>
  p(source)

pub fun fold<a,b>(source : nstream<a>, init : b, step : (b, a) -> b) : io b
  streamFold(source, init, step)

pub fun compileToList<a>(source : nstream<a>) : io list<a>
  compileToListRev(source, [])

pub fun compileDrain<a>(source : nstream<a>) : io ()
  streamDrain(source)

pub fun compileLast<a>(source : nstream<a>) : io maybe<a>
  compileLastGo(source, Nothing)
