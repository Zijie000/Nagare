module test_harness

// Minimal zero-dependency test harness for Nagare.
// Each test calls a `checkX` helper inside a `runSuite` body.

pub effect test-ctx
  fun record( passed : bool, name : string ) : ()

// Assert a boolean condition; logs pass/fail with the given name.
pub fun check(name : string, cond : bool) : <test-ctx,io> ()
  record(cond, name)

// Assert two ints are equal.
pub fun checkIntEq(name : string, expected : int, actual : int) : <test-ctx,io> ()
  if expected == actual then record(True, name)
  else
    println("  [FAIL] " ++ name ++ " expected=" ++ show(expected) ++ " actual=" ++ show(actual))
    record(False, name)

// Assert two strings are equal.
pub fun checkStrEq(name : string, expected : string, actual : string) : <test-ctx,io> ()
  if expected == actual then record(True, name)
  else
    println("  [FAIL] " ++ name ++ " expected=\"" ++ expected ++ "\" actual=\"" ++ actual ++ "\"")
    record(False, name)

// Assert two int lists are equal.
pub fun checkIntListEq(name : string, expected : list<int>, actual : list<int>) : <test-ctx,io> ()
  if expected == actual then record(True, name)
  else
    println("  [FAIL] " ++ name ++ " expected=" ++ show(expected) ++ " actual=" ++ show(actual))
    record(False, name)

// Assert two string lists are equal.
pub fun checkStrListEq(name : string, expected : list<string>, actual : list<string>) : <test-ctx,io> ()
  if expected == actual then record(True, name)
  else
    println("  [FAIL] " ++ name ++ " expected=" ++ show(expected) ++ " actual=" ++ show(actual))
    record(False, name)

// Run a test suite; prints summary and returns (passed, total).
// Uses a local heap ref to aggregate counts without incurring `div`.
pub fun runSuite(name : string, body : () -> <test-ctx,io> ()) : io (int, int)
  val passedRef = ref(0)
  val totalRef = ref(0)
  println("\n== " ++ name ++ " ==")
  with fun record(ok, tname)
    totalRef := !totalRef + 1
    if ok then
      passedRef := !passedRef + 1
      println("  [ok] " ++ tname)
  body()
  val p = !passedRef
  val t = !totalRef
  println("  -> " ++ show(p) ++ "/" ++ show(t) ++ " passed")
  (p, t)

// Not a runnable entry point; imported by test modules only.
pub fun main() : io ()
  ()
