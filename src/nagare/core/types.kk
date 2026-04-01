module nagare/core/types

pub type chunk<a>
  con Chunk( values : list<a> )

pub type pull<a>
  con PDone
  con POutput( out : chunk<a>, tail : pull<a> )
  con PEval( next : () -> io pull<a> )
  con PAcquire( acquire : () -> io (), release : () -> io (), tail : pull<a> )

pub type nstream<a>
  con Stream( step : pull<a> )

pub alias pipe<a,b> = nstream<a> -> nstream<b>

pub fun toPull<a>(source : nstream<a>) : pull<a>
  match source
    Stream(step) -> step

pub fun fromPull<a>(step : pull<a>) : nstream<a>
  Stream(step)

