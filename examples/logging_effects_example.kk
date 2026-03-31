module logging_effects_example

import nagare/core

fun sourceValue(n : int) : io int
  println("[eval] producing " ++ show(n))
  n

fun expandWithLog(x : int)
  eval(fn()
    println("[flatMap] expanding " ++ show(x))
    x * 10
  )

fun transform(source : nstream<int>) : nstream<int>
  source
    .map(fn(x) x + 100)
    .flatMap(expandWithLog)
    .filter(fn(x) (x % 2) == 0)

fun main() : io ()
  val source = concat([
    emits([40, 41]),
    evals([fn() sourceValue(1), fn() sourceValue(2), fn() sourceValue(3)]),
    emits([42])
  ])
  val transformed = source.through(transform)

  println("== first run: compileDrain ==")
  transformed.compileDrain

  println("== second run: compileToList ==")
  val out = transformed.compileToList
  println("[result] " ++ show(out))
