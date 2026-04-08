module nagare/core/types

// A batch of emitted values; streams output chunks rather than single elements only.
pub type chunk<a>
  
  con Chunk( values : list<a> ) // Finite list of values emitted in one step.

// Pull program: the internal state machine stepped by the interpreter (FS2-style).
pub type pull<a>
  
  con PDone // Stream finished; no more output.
  con POutput( out : chunk<a>, tail : pull<a> ) // Emit a chunk, then continue with `tail`.
  con PEval( next : () -> io pull<a> ) // Defer the next pull to an IO thunk (effects / laziness live here).
  con PAcquire( acquire : () -> io (), release : () -> io (), tail : pull<a> ) // Register acquire/release around `tail`; finalizers run LIFO when compile ends.

// User-facing stream: a thin wrapper around one pull program.
pub type nstream<a>
  con Stream( step : pull<a> )

// Reusable stream-to-stream transformation (pipeline segment).
pub alias pipe<a,b> = nstream<a> -> nstream<b>

// Unwrap a stream into its underlying pull program.
pub fun toPull<a>(source : nstream<a>) : pull<a>
  match source
    Stream(step) -> step

// Wrap a pull program back into a user-facing stream.
pub fun fromPull<a>(step : pull<a>) : nstream<a>
  Stream(step)

