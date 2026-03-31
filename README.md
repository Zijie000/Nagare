# Nagare

## Abstract

<img src="docs/image/img1.png" alt="Nagare" align="right" width="320" />

Nagare is a compositional, effectful, and resource-safe streaming abstraction for the Koka programming language, designed to model structured, long-lived computations over time. The name "Nagare" (流れ) is derived from the Japanese word for “Stream”, chosen in harmony with Koka’s naming (効果, meaning “effect”), to reflect the continuous flow of effectful processes.

## Quick start

Run the example:

- `koka -e --builddir=.koka -isrc examples/logging_effects_example.kk`

## Project layout

- `src/nagare/core.kk`: core stream abstraction (`nstream<a>`) and operators
- `examples/logging_effects_example.kk`: runnable usage example (shows evaluation + `flatMap` logging)

## Core types

- `nstream<a>`: a (possibly effectful) stream of `a`
- `pipe<a,b> = nstream<a> -> nstream<b>`: a reusable stream transformation


## Transformations

- `map<a,b>(source : nstream<a>, f : a -> b) : nstream<b>`
- `filter<a>(source : nstream<a>, pred : a -> bool) : nstream<a>`
- `flatMap<a,b>(source : nstream<a>, f : a -> nstream<b>) : nstream<b>`

## Compilation / execution

These functions interpret the stream and run its effects.

- `compileToList<a>(source : nstream<a>) : io list<a>`
- `compileDrain<a>(source : nstream<a>) : io ()`
- `compileLast<a>(source : nstream<a>) : io maybe<a>`
- `fold<a,b>(source : nstream<a>, init : b, step : (b, a) -> b) : io b`
