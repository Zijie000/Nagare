# Nagare

## Abstract

<img src="docs/image/img1.png" alt="Nagare" align="right" width="300" />

Nagare is a compositional, effectful, and resource-safe streaming abstraction for the Koka programming language, designed to model structured, long-lived computations over time. The name "Nagare" (流れ) is derived from the Japanese word for “Stream”, chosen in harmony with Koka’s naming (効果, meaning “effect”), to reflect the continuous flow of effectful processes.

This project is inspired by Typelevel’s FS2, which is built on Cats Effect; since Koka has effect semantics baked into the language, it is a natural fit for exploring an FS2-style streaming abstraction.

## Quick start 🐣

> [!NOTE]
> **Early stage.** This project is still in its initial phase and under active development—APIs, structure, and behavior may change without notice.

### Run the example

- `koka -e --builddir=.koka -isrc examples/logging_effects_example.kk`

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