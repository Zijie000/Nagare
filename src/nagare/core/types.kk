module nagare/core/types

// A batch of emitted values; streams output chunks rather than single elements only.
pub type chunk<a>

  con Chunk( values : list<a> ) // Finite list of values emitted in one step.

// Pull program: the internal state machine stepped by the interpreter (FS2-style).
// The row variable `e` records the effects required to step the program.
// Pure pulls instantiate `e` to `<>`; effectful pulls keep `<io>` (or any user-defined row).
pub type pull<a,e>

  con PDone // Stream finished; no more output.
  con POutput( out : chunk<a>, tail : pull<a,e> ) // Emit a chunk, then continue with `tail`.
  con PEval( next : () -> e pull<a,e> ) // Defer the next pull to an effectful thunk.
  con PAcquire( acquire : () -> e (), release : () -> e (), tail : pull<a,e> ) // Bracket `tail` with acquire/release; finalizers run LIFO.

// User-facing stream: a thin wrapper around one pull program.
pub type nstream<a,e>
  con Stream( step : pull<a,e> )

// Reusable stream-to-stream transformation (pipeline segment).
pub alias pipe<a,b,e> = nstream<a,e> -> nstream<b,e>

// Convenience aliases. Most users want `iostream`/`iopipe`.
pub alias iostream<a> = nstream<a,io>
pub alias iopipe<a,b> = pipe<a,b,io>

// Unwrap a stream into its underlying pull program.
pub fun toPull<a,e>(source : nstream<a,e>) : pull<a,e>
  match source
    Stream(step) -> step

// Wrap a pull program back into a user-facing stream.
pub fun fromPull<a,e>(step : pull<a,e>) : nstream<a,e>
  Stream(step)
