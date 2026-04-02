# Nagare

## Abstract

<img src="docs/image/img1.png" alt="Nagare" align="right" width="300" />

Nagare is a compositional, effectful, and resource-safe streaming abstraction for the Koka programming language, designed to model structured, long-lived computations over time. The name "Nagare" (流れ) is derived from the Japanese word for “Stream”, chosen in harmony with Koka’s naming (効果, meaning “effect”), to reflect the continuous flow of effectful processes.

This project is inspired by Typelevel’s FS2, which is built on Cats Effect; since Koka has effect semantics baked into the language, it is a natural fit for exploring an FS2-style streaming abstraction.

## Quick start 🐣

Run the example:

- `koka -e --builddir=.koka -isrc examples/logging_effects_example.kk`