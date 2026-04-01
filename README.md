# Nagare

## Abstract

<img src="docs/image/img1.png" alt="Nagare" align="right" width="300" />

Nagare is a compositional, effectful, and resource-safe streaming abstraction for the Koka programming language, designed to model structured, long-lived computations over time. The name "Nagare" (流れ) is derived from the Japanese word for “Stream”, chosen in harmony with Koka’s naming (効果, meaning “effect”), to reflect the continuous flow of effectful processes.

This project is inspired by Typelevel’s FS2, which is built on Cats Effect; since Koka has effect semantics baked into the language, it is a natural fit for exploring an FS2-style streaming abstraction.

## Quick start

Run the example:

- `koka -e --builddir=.koka -isrc examples/logging_effects_example.kk`

## Project layout

- `src/nagare/core/types.kk`: core types (`chunk` / `pull` / `nstream`) and bridge (`toPull` / `fromPull`)
- `src/nagare/core/pull.kk`: internal pull/chunk operators (`pullMap` / `pullFlatMap` / ...)
- `src/nagare/core/stream.kk`: user-facing constructors & combinators (`emit` / `map` / `flatMap` / ...)
- `src/nagare/interpreter.kk`: execution layer (interpreters)
- `examples/logging_effects_example.kk`: runnable example (same stream with io + trace interpreters)

## Core types

- `chunk<a>`: batched output container (`Chunk(list<a>)`)
- `pull<a>`: pull program (`PDone` / `POutput(chunk, tail)` / `PEval(next)` / `PAcquire(acquire, release, tail)`)
- `nstream<a>`: user-facing stream wrapper (`Stream(pull<a>)`)
- `pipe<a,b> = nstream<a> -> nstream<b>`: a reusable stream transformation
- `trace-event<a>`: trace interpreter event (`TraceEval` / `TraceEmit(a)`)


## Transformations

- `map<a,b>(source : nstream<a>, f : a -> b) : nstream<b>`
- `filter<a>(source : nstream<a>, pred : a -> bool) : nstream<a>`
- `flatMap<a,b>(source : nstream<a>, f : a -> nstream<b>) : nstream<b>`
- `managed<a>(source, acquire, release) : nstream<a>` (register resource lifecycle on compile runtime)

## Execution interpreters

These functions live in `nagare/interpreter` and interpret a stream description.

Independent executable suffixes (sinks):

- `toListSink<a>() : sink<a,list<a>>`
- `drainSink<a>() : sink<a,()>`
- `lastSink<a>() : sink<a,maybe<a>>`
- `foldSink<a,b>(init, step) : sink<a,b>`
- `traceSink<a>() : sink<a,(list<a>, list<trace-event<a>>)>`

Run a stream with a sink:

- `run<a,b>(source : nstream<a>, s : sink<a,b>) : io b`

Compile scope (fs2-style separation):

- `compile<a>(source : nstream<a>) : compile-scope<a>`

Compile methods:

- `source.compile.toList()`
- `source.compile.drain()`
- `source.compile.last()`
- `source.compile.fold(init, step)`
- `source.compile.trace()`

Runtime note:

- compile runtime owns pull stepping and finalizer stack execution (LIFO)
- `PAcquire` registrations are released when compilation finishes

Sink composition helpers:

- `mapResult<a,b,c>(s, f) : sink<a,c>`
- `zipSinks<a,b,c>(left, right) : sink<a,(b,c)>` (runs source twice)
