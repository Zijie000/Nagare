# Tests

Regression tests for the core combinators and interpreter. No external
dependencies — uses a tiny custom harness ([test_harness.kk](test_harness.kk)).

## Layout

| File | What it covers | Tests |
|---|---|---|
| [test_harness.kk](test_harness.kk) | `check*` assertions and `runSuite` | — |
| [core_pull_test.kk](core_pull_test.kk) | Low-level `pull` IR combinators (`pullAppend`, `pullMap`, `pullFilter`, `pullFlatMap`, `pullTake`, `pullDrop`, `pullTakeWhile`, `pullChunkN`, `pullUnchunks`) | 22 |
| [core_stream_test.kk](core_stream_test.kk) | User-facing `stream` API: sources, `map`/`filter`/`flatMap`/`take`/`drop`/`takeWhile`/`dropWhile`, `scan`, `zip`/`zipWith`, `exec`, `chunkN`/`unchunks`, `streamOf` DSL | 44 |
| [core_interpreter_test.kk](core_interpreter_test.kk) | Sinks (`toList`, `drain`, `fold`, `last`), `compile` scope, `mapResult`, finalizer LIFO ordering via `managed` | 8 |
| [core_resource_test.kk](core_resource_test.kk) | Early-stop finalizer release: `take`, `takeWhile`, and nested `flatMap+take` with `managed` streams | 9 |
| [core_infinite_test.kk](core_infinite_test.kk) | Infinite/unbounded sources: `iterate`, `repeat`, `repeatEval`; lazy termination with `take`/`takeWhile`; `zipWith` with one or both sides infinite | 16 |
| [effect_e2e_test.kk](effect_e2e_test.kk) | Row polymorphism (type-level: `pureTransform`, `polymorphicPipe`, `polymorphicSource`) and end-to-end user-effect discharge: `logger` effect flowing through `eval`, `evalMap`, `flatMap`, discharged by a handler installed outside `compile` | 10 |
| [state_exn_test.kk](state_exn_test.kk) | Combined `state` + `exn` effect row: values, counter state, exception abort, and handler-order independence | 6 |
| [io_file_test.kk](io_file_test.kk) | File I/O with mock handlers: `readAllStreaming` (normal + early-stop resource safety), `writeAll` (normal + nested `PAcquire` LIFO), `readAllStreamingBytes`, `writeAllBytes`, `decodeUtf8` | 19 |
| [io_capability_split_test.kk](io_capability_split_test.kk) | `fileRead` / `fileWrite` / `fileSystem` as separate capabilities; narrow pipelines that only require one capability type-check under the minimal row | 4 |
| [run_all.kk](run_all.kk) | Aggregate entry point; exits non-zero on any failure | — |

**Total: 138 tests across 9 suites.**

## Coverage gaps

- **Exception-path finalizer release.** Not tested. The sink is pinned to the
  `io` row; a stream that raises mid-pipeline has its finalizers run by
  `withRuntime`'s `finally`, but there is no suite asserting this specifically.
- **Error handling combinators.** `handleErrorWith`, `attempt`, and `rethrow`
  are not yet implemented — no pull-IR error node exists.

## Run

All suites:

```sh
koka -e --builddir=.koka -isrc tests/run_all.kk
```

A single suite:

```sh
koka -e --builddir=.koka -isrc tests/core_pull_test.kk
```

Any failure exits non-zero via `throw`.
