# Nagare

## Abstract

<img src="docs/image/img1.png" alt="Nagare" align="right" width="300" />

Nagare is a compositional, effectful, and resource-safe streaming abstraction for the Koka programming language, designed to model structured, long-lived computations over time. The name "Nagare" (流れ) is derived from the Japanese word for “Stream”, chosen in harmony with Koka’s naming (効果, meaning “effect”), to reflect the continuous flow of effectful processes.

This project is inspired by Typelevel’s FS2, which is built on Cats Effect; since Koka has effect semantics baked into the language, it is a natural fit for exploring an FS2-style streaming abstraction.

## What makes Nagare different from FS2

FS2 encodes effects through a type parameter `F[_]` and relies on Cats Effect’s typeclass hierarchy to abstract over IO monads. Nagare takes a different approach by leveraging Koka’s native row-polymorphic effect system, which yields three structural differences:

**Effect rows instead of effect monads.** In FS2, a stream’s effect type is a single `F[_]` — switching from `IO` to a custom effect requires monad transformer stacks or newtype wrappers. In Nagare, the effect row `e` is open: a stream typed `nstream<a, <logger|io>>` precisely states which effects it may perform. User-defined effects (such as `logger`) flow through combinators like `evalMap` and `flatMap` and are discharged by an ambient handler outside the sink — no lifting, no wrapping.

**Imperative source DSL via algebraic effects.** FS2 builds sources from `Stream.emit` / `Stream.emits` / `Stream.eval`. Nagare adds `streamOf`, a thin DSL powered by the `emitter` effect that lets users write sources in a direct, imperative style — `streamOf { yieldOne(1); yieldAll([2,3,4]) }` — while the handler compiles each yield into a lazy `POutput` node. The pull ADT is preserved as an internal IR, keeping optimization and interpretation separate from authoring.

**Resource safety without a runtime typeclass.** FS2 relies on `Cats Effect`’s `Resource` and bracket combinators, which require an `F` satisfying `MonadCancel`. Nagare encodes resource lifetimes directly in the pull ADT via `PAcquire` nodes, with finalizers executed LIFO by the interpreter’s `withRuntime` bracket. No typeclass constraint is needed — resource safety is a property of the interpreter, not of the effect type.

## Quick start 🐣

> [!NOTE]
> **Early stage.** This project is still in its initial phase and under active development—APIs, structure, and behavior may change without notice.

### Run the examples

Row polymorphism, `streamOf` DSL, and resource safety in one place:

`koka -e --builddir=.koka -isrc examples/row_polymorphism_example.kk`

File IO (read / write / copy / listDir):

`koka -e --builddir=.koka -isrc examples/file_io_example.kk`

Combinator chains (`evalMap`, `evalTap`, `trace`):

`koka -e --builddir=.koka -isrc examples/logging_effects_example.kk`

### Installing Koka

You need the [Koka](https://koka-lang.github.io/koka/) compiler. Official **binary installers** cover **Windows (x64)**, **macOS (x64 and Apple Silicon)**, and **Linux (x64)**; see **Section 1.1 — Installing the compiler** in the [Koka language book](https://koka-lang.github.io/koka/doc/book.html).

**macOS / Linux**:

```sh
curl -sSL https://github.com/koka-lang/koka/releases/latest/download/install.sh | sh
```

**Windows** (Command Prompt):

```bat
curl -sSL -o %tmp%\install-koka.bat https://github.com/koka-lang/koka/releases/latest/download/install.bat && %tmp%\install-koka.bat
```

On other platforms, build **from source** as described in the [Koka repository](https://github.com/koka-lang/koka#build-from-source).

The [Koka VS Code extension](https://marketplace.visualstudio.com/items?itemName=koka.language-koka) can also download and install the latest compiler for you (see the book for the walkthrough).

Verify: `koka --version`.