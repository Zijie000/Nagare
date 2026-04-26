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

## Test coverage

The test suite (`tests/run_all.kk`) maps directly onto the four design claims. 138 tests across 9 suites.

**Compositional.** `effect_e2e_test` verifies row polymorphism at both the type level and at runtime. Type-level: helper functions `pureTransform`, `polymorphicPipe`, and `polymorphicSource` are parameterised over an arbitrary row `e` — they only type-check if every combinator they use is row-polymorphic. Runtime: a user-defined `logger` effect crosses `eval`, `evalMap`, and `flatMap` boundaries and is discharged by a handler installed *outside* the sink.

**Effectful.** `effect_e2e_test` and `state_exn_test` demonstrate that multiple user-defined effects (`logger`, `counter`, `parseExn`) thread through the same pipeline simultaneously, that handlers may be installed in any order without interference, and that an exception raised mid-stream aborts the pipeline while preserving state accumulated up to the abort point.

**Streaming (lazy, pull-based).** `core_infinite_test` verifies that unbounded sources terminate correctly under downstream early-stop combinators. It covers `iterate`, `repeat`, and `repeatEval` (all typed `nstream<a, <div|e>>`), and checks that `take(n)`, `takeWhile`, `map`, and `filter` all terminate on them — termination is the test. It also exercises `zipWith` with one or both sides infinite, bounded externally by `take`. `io_file_test` covers the same laziness property on `readAllStreaming`: `take(1)` on a multi-chunk mock file returns only the first chunk and still closes the handle.

**Resource-safe.** `core_resource_test` uses `managed` streams with acquire/release callbacks logged to a ref. It asserts that `take` and `takeWhile` trigger the finalizer on early termination, and that nested resources opened inside `flatMap` are all released — every acquire has a matching release. `io_file_test` independently checks that the file handle is closed even when the consumer stops early, and that nested `PAcquire` nodes are released in LIFO order.

## Quick start 🐣

> [!NOTE]
> **Early stage.** This project is still in its initial phase and under active development—APIs, structure, and behavior may change without notice.

### Run the examples

**Getting started** — stream construction, basic combinators, and sinks:

`koka -e --builddir=.koka -isrc examples/hello_stream.kk`

**Row-polymorphic effects** — user-defined effects flow through combinators and are discharged externally:

`koka -e --builddir=.koka -isrc examples/effect_pipeline.kk`

**Lazy infinite streams** — pull-based evaluation; `iterate` is unbounded until bounded by `take` or `takeWhile`:

`koka -e --builddir=.koka -isrc examples/lazy_infinite.kk`

**File IO with capability split** — `fileRead`, `fileWrite`, and `fileSystem` are separate effects; streaming read is resource-safe:

`koka -e --builddir=.koka -isrc examples/file_pipeline.kk`

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