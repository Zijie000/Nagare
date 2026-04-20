module effect_polymorphism_test

import nagare/core/types
import nagare/core/stream
import nagare/core/interpreter
import test_harness

// ============================================================================
// SCOPE
// ============================================================================
// This suite verifies that the row parameter `e` is visible and usable in API
// signatures and that generic row variables flow through pure combinators.
//
// The prior architectural limit — sink bound to `nstream<a, io>`, blocking
// user effects from crossing combinator boundaries — has been resolved.
// `sink<a,b,e> = nstream<a,<io|e>> -> <io|e> b` is now the live definition.
// End-to-end runtime payoff is covered in effect_e2e_test.kk.
// ============================================================================

// A pure-transform stream parameterised only by `io` (demonstrates that pure
// combinators don't force any effect of their own — they compose at any row
// that the caller chooses).
fun pureTransform<e>(xs : list<int>) : nstream<int,e>
  emits(xs).map(fn(x) x * 2).filter(fn(x) x > 2)

// A row-polymorphic pipe built out of pure combinators. Its row parameter `e`
// is free — this compiles only because every combinator involved is
// row-polymorphic. If any combinator hard-coded `io`, this signature would fail
// to type-check.
fun polymorphicPipe<e>() : pipe<int, int, e>
  fn(source) source.map(fn(x) x + 1).filter(fn(x) x > 0).take(5)

// Row-polymorphic stream construction. Again, the fact that this *type-checks*
// at arbitrary `e` is the property under test.
fun polymorphicSource<e>(xs : list<int>) : nstream<int, e>
  emits(xs)

pub fun suiteBody() : <test-ctx,io> ()
  // (1) Pure combinator pipeline runs correctly when instantiated at `io`.
  //     This is a sanity check; the real signal is that `pureTransform` has
  //     type `iostream<int>` without forcing any particular effect in its body.
  checkIntListEq("pure combinators run at io",
    [4, 6],
    pureTransform([1, 2, 3]).compile.toList())

  // (2) A row-polymorphic pipe can be instantiated at `io` and plugged into a
  //     pipeline. The interesting check is compile-time: `polymorphicPipe<io>`
  //     unifies cleanly with an `iostream<int>` source.
  checkIntListEq("row-polymorphic pipe instantiated at io",
    [2, 3, 4, 5, 6],
    emits([1, 2, 3, 4, 5, 6, 7]).through(polymorphicPipe()).compile.toList())

  // (3) Row-polymorphic source can be instantiated at `io` by the sink's
  //     demand. Demonstrates that the row stays free until something pins it.
  checkIntListEq("row-polymorphic source instantiated at io",
    [10, 20, 30],
    polymorphicSource([10, 20, 30]).compile.toList())

pub fun main() : io ()
  val (passed, total) = runSuite("effect/polymorphism (type-level)", suiteBody)
  if passed == total then ()
  else throw("effect_polymorphism_test: " ++ show(total - passed) ++ " failed")
