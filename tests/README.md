# Tests

Regression tests for the core combinators and interpreter. No external
dependencies — uses a tiny custom harness ([test_harness.kk](test_harness.kk)).

## Layout

- [test_harness.kk](test_harness.kk) — `check*` assertions and `runSuite`
- [core_pull_test.kk](core_pull_test.kk) — low-level `pull` combinators
- [core_stream_test.kk](core_stream_test.kk) — user-facing `stream` API
- [core_interpreter_test.kk](core_interpreter_test.kk) — sinks, `compile`, finalizer LIFO
- [core_resource_test.kk](core_resource_test.kk) — early-stop finalizer release (`take`, `takeWhile`, nested `flatMap+take`)
- [core_infinite_test.kk](core_infinite_test.kk) — infinite streams (`cycle`, `iterate`, `repeat`)
- [effect_polymorphism_test.kk](effect_polymorphism_test.kk) — **type-level only**: row parameter surfaces correctly in API signatures
- [effect_e2e_test.kk](effect_e2e_test.kk) — end-to-end row-polymorphism discharge through a handler
- [state_exn_test.kk](state_exn_test.kk) — combined `state` + `exn` effect handling
- [io_file_write_test.kk](io_file_write_test.kk) — file write capability
- [io_file_streaming_test.kk](io_file_streaming_test.kk) — file read streaming
- [io_file_bytes_test.kk](io_file_bytes_test.kk) — binary byte-stream file I/O
- [io_capability_split_test.kk](io_capability_split_test.kk) — split read/write/filesystem capabilities
- [run_all.kk](run_all.kk) — aggregate entry point

## Coverage gaps (honest disclosure)

- **Exception-path finalizer release.** Not covered. The sink interface is bound
  to the `io` row, and Koka's `io` alias does not include `exn`. Widening sink
  to `<io,exn|e>` is follow-up work.
- **Runtime discharge of user-defined effects.** The type-level suite confirms
  row polymorphism is expressible in signatures, but does *not* exercise a
  handler that intercepts a user effect before the sink runs. Same root cause:
  `compile`/sink is pinned to `io`.

## Run

All suites:

```sh
koka -e --builddir=.koka -isrc -itests tests/run_all.kk
```

A single suite:

```sh
koka -e --builddir=.koka -isrc -itests tests/core_pull_test.kk
```

Any failure causes a non-zero exit code via `throw`.
