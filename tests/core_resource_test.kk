module core_resource_test

import nagare/core/types
import nagare/core/stream
import nagare/core/interpreter
import test_harness

// Build a managed stream over `xs` that records acquire/release events
// into the given log ref.
fun tracked(
  log : ref<global, list<string>>,
  tag : string,
  xs : list<int>
) : nstream<int,_>
  fun event(msg : string) : <read<global>,write<global>> ()
    log := Cons(msg, !log)
  managed(emits(xs), fn() event("acq-" ++ tag), fn() event("rel-" ++ tag))

fun snapshot(log : ref<global, list<string>>) : <read<global>> list<string>
  (!log).reverse

pub fun suiteBody() : <test-ctx,io> ()
  // ---- (1) take(n) early termination releases the finalizer. ----
  val log1 = ref([])
  val out1 = tracked(log1, "src", [1, 2, 3, 4, 5]).take(2).compile.toList()
  checkIntListEq("take early-stop: only first 2 emitted", [1, 2], out1)
  checkStrListEq("take early-stop: acquire+release both ran",
    ["acq-src", "rel-src"], snapshot(log1))

  // ---- (2) takeWhile early termination releases the finalizer. ----
  val log2 = ref([])
  val out2 = tracked(log2, "src", [1, 2, 3, 4, 5])
              .takeWhile(fn(x) x < 3).compile.toList()
  checkIntListEq("takeWhile early-stop: prefix only", [1, 2], out2)
  checkStrListEq("takeWhile early-stop: acquire+release both ran",
    ["acq-src", "rel-src"], snapshot(log2))

  // ---- (3) Nested resources via flatMap with outer take: inner releases. ----
  // Outer stream is managed; each element opens an inner managed stream;
  // outer take(3) cuts the pipeline before all elements are consumed.
  val log3 = ref([])
  fun event3(msg : string) : <read<global>,write<global>> ()
    log3 := Cons(msg, !log3)
  val outer : nstream<int,_> =
    managed(emits([10, 20, 30]),
      fn() event3("acq-outer"),
      fn() event3("rel-outer"))
  fun innerStream(x : int) : nstream<int,_>
    managed(emits([x, x + 1]),
      fn() event3("acq-inner-" ++ show(x)),
      fn() event3("rel-inner-" ++ show(x)))
  val nested : nstream<int,_> = outer.flatMap(innerStream)
  val out3 = nested.take(3).compile.toList()
  checkIntListEq("nested+take: first 3 values", [10, 11, 20], out3)
  // We don't pin the exact interleaving — the contract is: every acquire that
  // ran must have a matching release after the sink completes. Count pairs.
  val events3 = snapshot(log3)
  val acquires = events3.filter(fn(s) s.starts-with("acq-").bool)
  val releases = events3.filter(fn(s) s.starts-with("rel-").bool)
  checkIntEq("nested+take: every acquire has a matching release",
    acquires.length, releases.length)
  check("nested+take: at least outer acquired", acquires.length >= 1)
  check("nested+take: at least one release ran", releases.length >= 1)

  // ---- (4) Exception unwind: NOT COVERED. ----
  // The sink interface is currently bound to the `io` row, and Koka's `io`
  // alias does not include `exn`. To test exception-driven finalizer release
  // (e.g. `evalMap` running a function that throws), the sink contract must
  // first be widened to `<io,exn|e>` row polymorphism. Tracking as future work.

pub fun main() : io ()
  val (passed, total) = runSuite("core/resource", suiteBody)
  if passed == total then ()
  else throw("core_resource_test: " ++ show(total - passed) ++ " failed")
