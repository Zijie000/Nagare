#pragma once
#ifndef kk_nagare_core_stream_H
#define kk_nagare_core_stream_H
// Koka generated module: nagare/core/stream, koka version: 3.2.3, platform: 64-bit
#include <kklib.h>
#include "std_core_types.h"
#include "std_core_hnd.h"
#include "std_core_exn.h"
#include "std_core_bool.h"
#include "std_core_order.h"
#include "std_core_char.h"
#include "std_core_int.h"
#include "std_core_vector.h"
#include "std_core_string.h"
#include "std_core_sslice.h"
#include "std_core_list.h"
#include "std_core_maybe.h"
#include "std_core_maybe2.h"
#include "std_core_either.h"
#include "std_core_tuple.h"
#include "std_core_lazy.h"
#include "std_core_show.h"
#include "std_core_debug.h"
#include "std_core_delayed.h"
#include "std_core_console.h"
#include "std_core.h"
#include "nagare_core_types.h"
#include "nagare_core_pull.h"

// type declarations

// type nagare/core/stream/emitter
struct kk_nagare_core_stream__emitter_s {
  kk_block_t _block;
};
typedef kk_datatype_ptr_t kk_nagare_core_stream__emitter;
struct kk_nagare_core_stream__Hnd_emitter {
  struct kk_nagare_core_stream__emitter_s _base;
  kk_integer_t _cfc;
  kk_std_core_hnd__clause1 _ctl_yieldAll;
  kk_std_core_hnd__clause1 _ctl_yieldOne;
};
static inline kk_nagare_core_stream__emitter kk_nagare_core_stream__base_Hnd_emitter(struct kk_nagare_core_stream__Hnd_emitter* _x, kk_context_t* _ctx) {
  return kk_datatype_from_base(&_x->_base, _ctx);
}
static inline kk_nagare_core_stream__emitter kk_nagare_core_stream__new_Hnd_emitter(kk_reuse_t _at, int32_t _cpath, kk_integer_t _cfc, kk_std_core_hnd__clause1 _ctl_yieldAll, kk_std_core_hnd__clause1 _ctl_yieldOne, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__Hnd_emitter* _con = kk_block_alloc_at_as(struct kk_nagare_core_stream__Hnd_emitter, _at, 3 /* scan count */, _cpath, (kk_tag_t)(1), _ctx);
  _con->_cfc = _cfc;
  _con->_ctl_yieldAll = _ctl_yieldAll;
  _con->_ctl_yieldOne = _ctl_yieldOne;
  return kk_nagare_core_stream__base_Hnd_emitter(_con, _ctx);
}
static inline struct kk_nagare_core_stream__Hnd_emitter* kk_nagare_core_stream__as_Hnd_emitter(kk_nagare_core_stream__emitter x, kk_context_t* _ctx) {
  return kk_datatype_as_assert(struct kk_nagare_core_stream__Hnd_emitter*, x, (kk_tag_t)(1), _ctx);
}
static inline bool kk_nagare_core_stream__is_Hnd_emitter(kk_nagare_core_stream__emitter x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_nagare_core_stream__emitter kk_nagare_core_stream__emitter_dup(kk_nagare_core_stream__emitter _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_dup(_x, _ctx);
}
static inline void kk_nagare_core_stream__emitter_drop(kk_nagare_core_stream__emitter _x, kk_context_t* _ctx) {
  kk_datatype_ptr_drop(_x, _ctx);
}
static inline kk_box_t kk_nagare_core_stream__emitter_box(kk_nagare_core_stream__emitter _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_box(_x);
}
static inline kk_nagare_core_stream__emitter kk_nagare_core_stream__emitter_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_datatype_ptr_unbox(_x);
}

// value declarations
 
// Create a pull that outputs a single chunk from a list.

static inline kk_nagare_core_types__pull kk_nagare_core_stream_fromListPull(kk_std_core_types__list xs, kk_context_t* _ctx) { /* forall<a,e> (xs : list<a>) -> nagare/core/types/pull<a,e> */ 
  kk_nagare_core_types__chunk _x_x279 = kk_nagare_core_types__new_Chunk(xs, _ctx); /*nagare/core/types/chunk<4>*/
  return kk_nagare_core_types__new_POutput(kk_reuse_null, 0, _x_x279, kk_nagare_core_types__new_PDone(_ctx), _ctx);
}

kk_nagare_core_types__pull kk_nagare_core_stream__mlift_unroll_fromEvalsPull_10000_10417(kk_std_core_types__list tt, kk_box_t _y_x10346, kk_context_t* _ctx); /* forall<a,e> (tt : list<() -> e a>, a) -> e nagare/core/types/pull<a,e> */ 

kk_nagare_core_types__pull kk_nagare_core_stream__unroll_fromEvalsPull_10000(kk_std_core_types__list thunks, kk_context_t* _ctx); /* forall<a,e> (thunks : list<() -> e a>) -> nagare/core/types/pull<a,e> */ 
 
// unrolling of singleton matches of nagare/core/stream/@unroll-fromEvalsPull@10000

static inline kk_nagare_core_types__pull kk_nagare_core_stream_fromEvalsPull(kk_std_core_types__list thunks, kk_context_t* _ctx) { /* forall<a,e> (thunks : list<() -> e a>) -> nagare/core/types/pull<a,e> */ 
  if (kk_std_core_types__is_Nil(thunks, _ctx)) {
    return kk_nagare_core_types__new_PDone(_ctx);
  }
  {
    return kk_nagare_core_stream__unroll_fromEvalsPull_10000(thunks, _ctx);
  }
}

kk_nagare_core_types__pull kk_nagare_core_stream__mlift_trmc_lift_append_10292_10418(kk_nagare_core_types__pull rightPull, kk_nagare_core_types__pull _y_x10349, kk_context_t* _ctx); /* forall<a,e> (rightPull : nagare/core/types/pull<a,e>, nagare/core/types/pull<a,e>) -> e nagare/core/types/pull<a,e> */ 

kk_nagare_core_types__pull kk_nagare_core_stream__trmc_lift_append_10292(kk_nagare_core_types__pull rightPull_0, kk_nagare_core_types__pull _uniq_left_10122, kk_std_core_types__cctx _acc, kk_context_t* _ctx); /* forall<a,e> (rightPull : nagare/core/types/pull<a,e>, nagare/core/types/pull<a,e>, ctx<nagare/core/types/pull<a,e>>) -> nagare/core/types/pull<a,e> */ 

kk_nagare_core_types__pull kk_nagare_core_stream__lift_append_10292(kk_nagare_core_types__pull rightPull_1, kk_nagare_core_types__pull _uniq_left_10122_0, kk_context_t* _ctx); /* forall<a,e> (rightPull : nagare/core/types/pull<a,e>, nagare/core/types/pull<a,e>) -> nagare/core/types/pull<a,e> */ 

kk_nagare_core_types__pull kk_nagare_core_stream__lift_append_10291(kk_nagare_core_types__pull rightPull, kk_nagare_core_types__pull _uniq_left_10117, kk_context_t* _ctx); /* forall<a,e> (rightPull : nagare/core/types/pull<a,e>, nagare/core/types/pull<a,e>) -> nagare/core/types/pull<a,e> */ 
 
// Append two streams (right stream is delayed until left completes).

static inline kk_nagare_core_types__nstream kk_nagare_core_stream_append(kk_nagare_core_types__nstream left, kk_nagare_core_types__nstream right, kk_context_t* _ctx) { /* forall<a,e> (left : nagare/core/types/nstream<a,e>, right : nagare/core/types/nstream<a,e>) -> nagare/core/types/nstream<a,e> */ 
  {
    kk_nagare_core_types__pull leftPull = left.step;
    {
      kk_nagare_core_types__pull rightPull = right.step;
      kk_nagare_core_types__pull _x_x305 = kk_nagare_core_stream__lift_append_10291(rightPull, leftPull, _ctx); /*nagare/core/types/pull<535,536>*/
      return kk_nagare_core_types__new_Stream(_x_x305, _ctx);
    }
  }
}

kk_nagare_core_types__pull kk_nagare_core_stream__mlift_trmc_lift_unroll_concatList_10001_10294_10419(kk_nagare_core_types__pull rightPull, kk_nagare_core_types__pull _y_x10354, kk_context_t* _ctx); /* forall<a,e> (rightPull : nagare/core/types/pull<a,e>, nagare/core/types/pull<a,e>) -> e nagare/core/types/pull<a,e> */ 

kk_nagare_core_types__pull kk_nagare_core_stream__trmc_lift_unroll_concatList_10001_10294(kk_nagare_core_types__pull rightPull_0, kk_nagare_core_types__pull _uniq_left_10140, kk_std_core_types__cctx _acc, kk_context_t* _ctx); /* forall<a,e> (rightPull : nagare/core/types/pull<a,e>, nagare/core/types/pull<a,e>, ctx<nagare/core/types/pull<a,e>>) -> nagare/core/types/pull<a,e> */ 

kk_nagare_core_types__pull kk_nagare_core_stream__lift_unroll_concatList_10001_10294(kk_nagare_core_types__pull rightPull_1, kk_nagare_core_types__pull _uniq_left_10140_0, kk_context_t* _ctx); /* forall<a,e> (rightPull : nagare/core/types/pull<a,e>, nagare/core/types/pull<a,e>) -> nagare/core/types/pull<a,e> */ 

kk_nagare_core_types__pull kk_nagare_core_stream__lift_unroll_concatList_10001_10293(kk_nagare_core_types__pull rightPull, kk_nagare_core_types__pull _uniq_left_10135, kk_context_t* _ctx); /* forall<a,e> (rightPull : nagare/core/types/pull<a,e>, nagare/core/types/pull<a,e>) -> nagare/core/types/pull<a,e> */ 

kk_nagare_core_types__nstream kk_nagare_core_stream__unroll_concatList_10001(kk_std_core_types__list streams, kk_context_t* _ctx); /* forall<a,e> (streams : list<nagare/core/types/nstream<a,e>>) -> nagare/core/types/nstream<a,e> */ 
 
// unrolling of singleton matches of nagare/core/stream/@unroll-concatList@10001

static inline kk_nagare_core_types__nstream kk_nagare_core_stream_concatList(kk_std_core_types__list streams, kk_context_t* _ctx) { /* forall<a,e> (streams : list<nagare/core/types/nstream<a,e>>) -> nagare/core/types/nstream<a,e> */ 
  if (kk_std_core_types__is_Nil(streams, _ctx)) {
    return kk_nagare_core_types__new_Stream(kk_nagare_core_types__new_PDone(_ctx), _ctx);
  }
  {
    return kk_nagare_core_stream__unroll_concatList_10001(streams, _ctx);
  }
}
 
// A stream with no output.

static inline kk_nagare_core_types__nstream kk_nagare_core_stream_empty(kk_context_t* _ctx) { /* forall<a,e> () -> nagare/core/types/nstream<a,e> */ 
  return kk_nagare_core_types__new_Stream(kk_nagare_core_types__new_PDone(_ctx), _ctx);
}
 
// Emit a single value as a stream.

static inline kk_nagare_core_types__nstream kk_nagare_core_stream_emit(kk_box_t value, kk_context_t* _ctx) { /* forall<a,e> (value : a) -> nagare/core/types/nstream<a,e> */ 
  kk_nagare_core_types__pull _x_x324;
  kk_nagare_core_types__chunk _x_x325;
  kk_std_core_types__list _x_x326 = kk_std_core_types__new_Cons(kk_reuse_null, 0, value, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<10021>*/
  _x_x325 = kk_nagare_core_types__new_Chunk(_x_x326, _ctx); /*nagare/core/types/chunk<4>*/
  _x_x324 = kk_nagare_core_types__new_POutput(kk_reuse_null, 0, _x_x325, kk_nagare_core_types__new_PDone(_ctx), _ctx); /*nagare/core/types/pull<19,20>*/
  return kk_nagare_core_types__new_Stream(_x_x324, _ctx);
}
 
// Alias of emit (pure value into a stream).

static inline kk_nagare_core_types__nstream kk_nagare_core_stream_pure(kk_box_t value, kk_context_t* _ctx) { /* forall<a,e> (value : a) -> nagare/core/types/nstream<a,e> */ 
  kk_nagare_core_types__pull _x_x327;
  kk_nagare_core_types__chunk _x_x328;
  kk_std_core_types__list _x_x329 = kk_std_core_types__new_Cons(kk_reuse_null, 0, value, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<10021>*/
  _x_x328 = kk_nagare_core_types__new_Chunk(_x_x329, _ctx); /*nagare/core/types/chunk<4>*/
  _x_x327 = kk_nagare_core_types__new_POutput(kk_reuse_null, 0, _x_x328, kk_nagare_core_types__new_PDone(_ctx), _ctx); /*nagare/core/types/pull<19,20>*/
  return kk_nagare_core_types__new_Stream(_x_x327, _ctx);
}
 
// monadic lift

static inline kk_nagare_core_types__pull kk_nagare_core_stream__mlift_eval_10420(kk_box_t _y_x10361, kk_context_t* _ctx) { /* forall<a,e> (a) -> e nagare/core/types/pull<a,e> */ 
  kk_nagare_core_types__chunk _x_x330;
  kk_std_core_types__list _x_x331 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _y_x10361, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<10021>*/
  _x_x330 = kk_nagare_core_types__new_Chunk(_x_x331, _ctx); /*nagare/core/types/chunk<4>*/
  return kk_nagare_core_types__new_POutput(kk_reuse_null, 0, _x_x330, kk_nagare_core_types__new_PDone(_ctx), _ctx);
}

kk_nagare_core_types__nstream kk_nagare_core_stream_eval(kk_function_t thunk, kk_context_t* _ctx); /* forall<a,e> (thunk : () -> e a) -> nagare/core/types/nstream<a,e> */ 
 
// Attach acquire/release finalizers to a stream (executed LIFO by the runtime).

static inline kk_nagare_core_types__nstream kk_nagare_core_stream_managed(kk_nagare_core_types__nstream source, kk_function_t acquire, kk_function_t release, kk_context_t* _ctx) { /* forall<a,e> (source : nagare/core/types/nstream<a,e>, acquire : () -> e (), release : () -> e ()) -> nagare/core/types/nstream<a,e> */ 
  {
    kk_nagare_core_types__pull step = source.step;
    kk_nagare_core_types__pull _x_x340 = kk_nagare_core_types__new_PAcquire(kk_reuse_null, 0, acquire, release, step, _ctx); /*nagare/core/types/pull<19,20>*/
    return kk_nagare_core_types__new_Stream(_x_x340, _ctx);
  }
}
 
// Emit all values from a list as one chunk.

static inline kk_nagare_core_types__nstream kk_nagare_core_stream_emits(kk_std_core_types__list values, kk_context_t* _ctx) { /* forall<a,e> (values : list<a>) -> nagare/core/types/nstream<a,e> */ 
  kk_nagare_core_types__pull _x_x341;
  kk_nagare_core_types__chunk _x_x342 = kk_nagare_core_types__new_Chunk(values, _ctx); /*nagare/core/types/chunk<4>*/
  _x_x341 = kk_nagare_core_types__new_POutput(kk_reuse_null, 0, _x_x342, kk_nagare_core_types__new_PDone(_ctx), _ctx); /*nagare/core/types/pull<19,20>*/
  return kk_nagare_core_types__new_Stream(_x_x341, _ctx);
}
 
// monadic lift

static inline kk_nagare_core_types__nstream kk_nagare_core_stream__mlift_evals_10421(kk_nagare_core_types__pull _c_x10363, kk_context_t* _ctx) { /* forall<a,e> (nagare/core/types/pull<a,e>) -> nagare/core/types/nstream<a,e> */ 
  return kk_nagare_core_types__new_Stream(_c_x10363, _ctx);
}

kk_nagare_core_types__nstream kk_nagare_core_stream_evals(kk_std_core_types__list thunks, kk_context_t* _ctx); /* forall<a,e> (thunks : list<() -> e a>) -> nagare/core/types/nstream<a,e> */ 

kk_nagare_core_types__pull kk_nagare_core_stream_iteratePull(kk_box_t seed, kk_function_t f, kk_context_t* _ctx); /* forall<a,e> (seed : a, f : (a) -> a) -> div nagare/core/types/pull<a,<div|e>> */ 
 
// Unbounded source: emits seed, f(seed), f(f(seed)), ... one per step.
// Each step is wrapped in PEval so the pull stays lazy — only consumed
// elements are materialised. Safe under `take(n)` and other early-stop
// combinators; consuming without a bound will not terminate.
// Unbounded source: emits seed, f(seed), f(f(seed)), ... one per step.
// Each step is wrapped in PEval so the pull stays lazy — only consumed
// elements are materialised. Safe under `take(n)` and other early-stop
// combinators; consuming without a bound will not terminate.
//
// The `div` effect on the resulting stream's row reflects that fact: any
// pipeline that drains an `iterate` without bounding it is divergent, and
// Koka tracks that statically. Bound it with `take`/`takeWhile` to use it
// in an `io`-only context (handlers can mask `div` once a bound is proven).

static inline kk_nagare_core_types__nstream kk_nagare_core_stream_iterate(kk_box_t seed, kk_function_t f, kk_context_t* _ctx) { /* forall<a,e> (seed : a, f : (a) -> a) -> div nagare/core/types/nstream<a,<div|e>> */ 
  kk_nagare_core_types__pull _x_x353 = kk_nagare_core_stream_iteratePull(seed, f, _ctx); /*nagare/core/types/pull<1038,<div|1039>>*/
  return kk_nagare_core_types__new_Stream(_x_x353, _ctx);
}
 
// Concatenate multiple streams.

static inline kk_nagare_core_types__nstream kk_nagare_core_stream_concat(kk_std_core_types__list streams, kk_context_t* _ctx) { /* forall<a,e> (streams : list<nagare/core/types/nstream<a,e>>) -> nagare/core/types/nstream<a,e> */ 
  if (kk_std_core_types__is_Nil(streams, _ctx)) {
    return kk_nagare_core_types__new_Stream(kk_nagare_core_types__new_PDone(_ctx), _ctx);
  }
  {
    return kk_nagare_core_stream__unroll_concatList_10001(streams, _ctx);
  }
}
 
// Transform each emitted value with a pure function.

static inline kk_nagare_core_types__nstream kk_nagare_core_stream_map(kk_nagare_core_types__nstream source, kk_function_t f, kk_context_t* _ctx) { /* forall<a,b,e> (source : nagare/core/types/nstream<a,e>, f : (a) -> b) -> nagare/core/types/nstream<b,e> */ 
  {
    kk_nagare_core_types__pull step = source.step;
    kk_nagare_core_types__pull _x_x354 = kk_nagare_core_pull_pullMap(step, f, _ctx); /*nagare/core/types/pull<1291,1292>*/
    return kk_nagare_core_types__new_Stream(_x_x354, _ctx);
  }
}
 
// Drop the first n emitted values.

static inline kk_nagare_core_types__nstream kk_nagare_core_stream_drop(kk_nagare_core_types__nstream source, kk_integer_t n, kk_context_t* _ctx) { /* forall<a,e> (source : nagare/core/types/nstream<a,e>, n : int) -> nagare/core/types/nstream<a,e> */ 
  {
    kk_nagare_core_types__pull step = source.step;
    kk_nagare_core_types__pull _x_x355 = kk_nagare_core_pull_pullDrop(step, n, _ctx); /*nagare/core/types/pull<2195,2196>*/
    return kk_nagare_core_types__new_Stream(_x_x355, _ctx);
  }
}
 
// Re-chunk the stream into fixed-size chunks.

static inline kk_nagare_core_types__nstream kk_nagare_core_stream_chunkN(kk_nagare_core_types__nstream source, kk_integer_t n, kk_context_t* _ctx) { /* forall<a,e> (source : nagare/core/types/nstream<a,e>, n : int) -> nagare/core/types/nstream<nagare/core/types/chunk<a>,e> */ 
  {
    kk_nagare_core_types__pull step = source.step;
    kk_nagare_core_types__pull _x_x356 = kk_nagare_core_pull_pullChunkN(step, n, _ctx); /*nagare/core/types/pull<nagare/core/types/chunk<2613>,2614>*/
    return kk_nagare_core_types__new_Stream(_x_x356, _ctx);
  }
}

kk_nagare_core_types__pull kk_nagare_core_stream__mlift_lift_flatMap_10298_10422(kk_std_core_types__list _uniq_xt_10183, kk_function_t f, kk_nagare_core_types__pull _y_x10369, kk_context_t* _ctx); /* forall<a,b,e> (list<a>, f : (a) -> nagare/core/types/nstream<b,e>, nagare/core/types/pull<b,e>) -> e nagare/core/types/pull<b,e> */ 

kk_nagare_core_types__pull kk_nagare_core_stream__lift_flatMap_10298(kk_std_core_types__list _uniq_xt_10183_0, kk_function_t f_0, kk_nagare_core_types__pull _uniq_left_10189, kk_context_t* _ctx); /* forall<a,b,e> (list<a>, f : (a) -> nagare/core/types/nstream<b,e>, nagare/core/types/pull<b,e>) -> nagare/core/types/pull<b,e> */ 

kk_nagare_core_types__pull kk_nagare_core_stream__lift_flatMap_10297(kk_function_t f_1, kk_std_core_types__list _uniq_values_10178, kk_context_t* _ctx); /* forall<a,b,e> (f : (a) -> nagare/core/types/nstream<b,e>, list<a>) -> nagare/core/types/pull<b,e> */ 

kk_nagare_core_types__pull kk_nagare_core_stream__mlift_lift_flatMap_10299_10423(kk_nagare_core_types__pull _uniq_tail_10163, kk_function_t f, kk_nagare_core_types__pull _y_x10373, kk_context_t* _ctx); /* forall<a,b,e> (nagare/core/types/pull<a,e>, f : (a) -> nagare/core/types/nstream<b,e>, nagare/core/types/pull<b,e>) -> e nagare/core/types/pull<b,e> */ 

kk_nagare_core_types__pull kk_nagare_core_stream__mlift_lift_flatMap_10296_10424(kk_nagare_core_types__pull _uniq_tail_10163_0, kk_function_t f_0, kk_nagare_core_types__pull _c_x10375, kk_context_t* _ctx); /* forall<a,b,e> (nagare/core/types/pull<a,e>, f : (a) -> nagare/core/types/nstream<b,e>, nagare/core/types/pull<b,e>) -> nagare/core/types/pull<b,e> */ 

kk_nagare_core_types__pull kk_nagare_core_stream__mlift_lift_flatMap_10296_10425(kk_function_t f_1, kk_nagare_core_types__pull _y_x10378, kk_context_t* _ctx); /* forall<a,b,e> (f : (a) -> nagare/core/types/nstream<b,e>, nagare/core/types/pull<a,e>) -> e nagare/core/types/pull<b,e> */ 

kk_nagare_core_types__pull kk_nagare_core_stream__lift_flatMap_10299(kk_nagare_core_types__pull _uniq_tail_10163_1, kk_function_t f_2, kk_nagare_core_types__pull _uniq_left_10202, kk_context_t* _ctx); /* forall<a,b,e> (nagare/core/types/pull<a,e>, f : (a) -> nagare/core/types/nstream<b,e>, nagare/core/types/pull<b,e>) -> nagare/core/types/pull<b,e> */ 

kk_nagare_core_types__pull kk_nagare_core_stream__lift_flatMap_10296(kk_function_t f_3, kk_nagare_core_types__pull _uniq_source_10158, kk_context_t* _ctx); /* forall<a,b,e> (f : (a) -> nagare/core/types/nstream<b,e>, nagare/core/types/pull<a,e>) -> nagare/core/types/pull<b,e> */ 

kk_nagare_core_types__pull kk_nagare_core_stream__lift_flatMap_10295(kk_function_t f, kk_nagare_core_types__pull _uniq_source_10153, kk_context_t* _ctx); /* forall<a,b,e> (f : (a) -> nagare/core/types/nstream<b,e>, nagare/core/types/pull<a,e>) -> nagare/core/types/pull<b,e> */ 
 
// Expand each value into a stream and concatenate results.

static inline kk_nagare_core_types__nstream kk_nagare_core_stream_flatMap(kk_nagare_core_types__nstream source, kk_function_t f, kk_context_t* _ctx) { /* forall<a,b,e> (source : nagare/core/types/nstream<a,e>, f : (a) -> nagare/core/types/nstream<b,e>) -> nagare/core/types/nstream<b,e> */ 
  {
    kk_nagare_core_types__pull step = source.step;
    kk_nagare_core_types__pull _x_x392 = kk_nagare_core_stream__lift_flatMap_10295(f, step, _ctx); /*nagare/core/types/pull<1356,1357>*/
    return kk_nagare_core_types__new_Stream(_x_x392, _ctx);
  }
}

kk_nagare_core_types__pull kk_nagare_core_stream__mlift_lift_evalMap_10302_10426(kk_nagare_core_types__pull _uniq_tail_10225, kk_function_t f, kk_nagare_core_types__pull _y_x10382, kk_context_t* _ctx); /* forall<a,b,e> (nagare/core/types/pull<a,e>, f : (a) -> e b, nagare/core/types/pull<b,e>) -> e nagare/core/types/pull<b,e> */ 

kk_nagare_core_types__pull kk_nagare_core_stream__mlift_lift_evalMap_10301_10427(kk_box_t _y_x10384, kk_context_t* _ctx); /* forall<a,e> (a) -> e nagare/core/types/pull<a,e> */ 

kk_nagare_core_types__pull kk_nagare_core_stream__mlift_lift_evalMap_10301_10428(kk_nagare_core_types__pull _uniq_tail_10225_0, kk_function_t f_0, kk_nagare_core_types__pull _c_x10385, kk_context_t* _ctx); /* forall<a,b,e> (nagare/core/types/pull<a,e>, f : (a) -> e b, nagare/core/types/pull<b,e>) -> nagare/core/types/pull<b,e> */ 

kk_nagare_core_types__pull kk_nagare_core_stream__mlift_lift_evalMap_10301_10429(kk_function_t _uniq_f_10221, kk_nagare_core_types__pull _y_x10388, kk_context_t* _ctx); /* forall<a,b,e> ((a) -> nagare/core/types/pull<b,e>, nagare/core/types/pull<a,e>) -> e nagare/core/types/pull<b,e> */ 

kk_nagare_core_types__pull kk_nagare_core_stream__lift_evalMap_10302(kk_nagare_core_types__pull _uniq_tail_10225_1, kk_function_t f_1, kk_nagare_core_types__pull _uniq_left_10240, kk_context_t* _ctx); /* forall<a,b,e> (nagare/core/types/pull<a,e>, f : (a) -> e b, nagare/core/types/pull<b,e>) -> nagare/core/types/pull<b,e> */ 

kk_nagare_core_types__pull kk_nagare_core_stream__lift_evalMap_10301(kk_function_t f_2, kk_nagare_core_types__pull _uniq_source_10220, kk_context_t* _ctx); /* forall<a,b,e> (f : (a) -> e b, nagare/core/types/pull<a,e>) -> nagare/core/types/pull<b,e> */ 

kk_nagare_core_types__pull kk_nagare_core_stream__lift_evalMap_10300(kk_function_t f, kk_nagare_core_types__pull _uniq_source_10215, kk_context_t* _ctx); /* forall<a,b,e> (f : (a) -> e b, nagare/core/types/pull<a,e>) -> nagare/core/types/pull<b,e> */ 
 
// Transform each emitted value with an effectful function.

static inline kk_nagare_core_types__nstream kk_nagare_core_stream_evalMap(kk_nagare_core_types__nstream source, kk_function_t f, kk_context_t* _ctx) { /* forall<a,b,e> (source : nagare/core/types/nstream<a,e>, f : (a) -> e b) -> nagare/core/types/nstream<b,e> */ 
  {
    kk_nagare_core_types__pull step = source.step;
    kk_nagare_core_types__pull _x_x421 = kk_nagare_core_stream__lift_evalMap_10300(f, step, _ctx); /*nagare/core/types/pull<1419,1420>*/
    return kk_nagare_core_types__new_Stream(_x_x421, _ctx);
  }
}

kk_nagare_core_types__pull kk_nagare_core_stream__mlift_lift_evalTap_10305_10430(kk_nagare_core_types__pull _uniq_tail_10263, kk_function_t f, kk_nagare_core_types__pull _y_x10392, kk_context_t* _ctx); /* forall<a,e> (nagare/core/types/pull<a,e>, f : (a) -> e (), nagare/core/types/pull<a,e>) -> e nagare/core/types/pull<a,e> */ 

kk_nagare_core_types__pull kk_nagare_core_stream__mlift_lift_evalTap_10304_10431(kk_box_t x, kk_unit_t wild__, kk_context_t* _ctx); /* forall<a,e> (x : a, wild_ : ()) -> e nagare/core/types/pull<a,e> */ 

kk_nagare_core_types__pull kk_nagare_core_stream__mlift_lift_evalTap_10304_10432(kk_nagare_core_types__pull _uniq_tail_10263_0, kk_function_t f_0, kk_nagare_core_types__pull _c_x10395, kk_context_t* _ctx); /* forall<a,e> (nagare/core/types/pull<a,e>, f : (a) -> e (), nagare/core/types/pull<a,e>) -> nagare/core/types/pull<a,e> */ 

kk_nagare_core_types__pull kk_nagare_core_stream__mlift_lift_evalTap_10304_10433(kk_function_t _uniq_f_10259, kk_nagare_core_types__pull _y_x10398, kk_context_t* _ctx); /* forall<a,e> ((a) -> nagare/core/types/pull<a,e>, nagare/core/types/pull<a,e>) -> e nagare/core/types/pull<a,e> */ 

kk_nagare_core_types__pull kk_nagare_core_stream__lift_evalTap_10305(kk_nagare_core_types__pull _uniq_tail_10263_1, kk_function_t f_1, kk_nagare_core_types__pull _uniq_left_10278, kk_context_t* _ctx); /* forall<a,e> (nagare/core/types/pull<a,e>, f : (a) -> e (), nagare/core/types/pull<a,e>) -> nagare/core/types/pull<a,e> */ 

kk_nagare_core_types__pull kk_nagare_core_stream__lift_evalTap_10304(kk_function_t f_2, kk_nagare_core_types__pull _uniq_source_10258, kk_context_t* _ctx); /* forall<a,e> (f : (a) -> e (), nagare/core/types/pull<a,e>) -> nagare/core/types/pull<a,e> */ 

kk_nagare_core_types__pull kk_nagare_core_stream__lift_evalTap_10303(kk_function_t f, kk_nagare_core_types__pull _uniq_source_10253, kk_context_t* _ctx); /* forall<a,e> (f : (a) -> e (), nagare/core/types/pull<a,e>) -> nagare/core/types/pull<a,e> */ 
 
// Run an effect for each emitted value, preserving the original value.

static inline kk_nagare_core_types__nstream kk_nagare_core_stream_evalTap(kk_nagare_core_types__nstream source, kk_function_t f, kk_context_t* _ctx) { /* forall<a,e> (source : nagare/core/types/nstream<a,e>, f : (a) -> e ()) -> nagare/core/types/nstream<a,e> */ 
  {
    kk_nagare_core_types__pull step = source.step;
    kk_nagare_core_types__pull _x_x452 = kk_nagare_core_stream__lift_evalTap_10303(f, step, _ctx); /*nagare/core/types/pull<1477,1478>*/
    return kk_nagare_core_types__new_Stream(_x_x452, _ctx);
  }
}
 
// Keep only the first n emitted values.

static inline kk_nagare_core_types__nstream kk_nagare_core_stream_take(kk_nagare_core_types__nstream source, kk_integer_t n, kk_context_t* _ctx) { /* forall<a,e> (source : nagare/core/types/nstream<a,e>, n : int) -> nagare/core/types/nstream<a,e> */ 
  {
    kk_nagare_core_types__pull step = source.step;
    kk_nagare_core_types__pull _x_x453 = kk_nagare_core_pull_pullTake(step, n, _ctx); /*nagare/core/types/pull<1953,1954>*/
    return kk_nagare_core_types__new_Stream(_x_x453, _ctx);
  }
}
 
// Keep values while predicate holds; stop at first failure.

static inline kk_nagare_core_types__nstream kk_nagare_core_stream_takeWhile(kk_nagare_core_types__nstream source, kk_function_t pred, kk_context_t* _ctx) { /* forall<a,e> (source : nagare/core/types/nstream<a,e>, pred : (a) -> bool) -> nagare/core/types/nstream<a,e> */ 
  {
    kk_nagare_core_types__pull step = source.step;
    kk_nagare_core_types__pull _x_x454 = kk_nagare_core_pull_pullTakeWhile(step, pred, _ctx); /*nagare/core/types/pull<2402,2403>*/
    return kk_nagare_core_types__new_Stream(_x_x454, _ctx);
  }
}
 
// monadic lift

static inline kk_nagare_core_types__nstream kk_nagare_core_stream__mlift_unchunks_10434(kk_nagare_core_types__pull _c_x10404, kk_context_t* _ctx) { /* forall<a,e> (nagare/core/types/pull<a,e>) -> nagare/core/types/nstream<a,e> */ 
  return kk_nagare_core_types__new_Stream(_c_x10404, _ctx);
}

kk_nagare_core_types__nstream kk_nagare_core_stream_unchunks(kk_nagare_core_types__nstream source, kk_context_t* _ctx); /* forall<a,e> (source : nagare/core/types/nstream<nagare/core/types/chunk<a>,e>) -> nagare/core/types/nstream<a,e> */ 
 
// Keep only values that satisfy a predicate.

static inline kk_nagare_core_types__nstream kk_nagare_core_stream_filter(kk_nagare_core_types__nstream source, kk_function_t pred, kk_context_t* _ctx) { /* forall<a,e> (source : nagare/core/types/nstream<a,e>, pred : (a) -> bool) -> nagare/core/types/nstream<a,e> */ 
  {
    kk_nagare_core_types__pull step = source.step;
    kk_nagare_core_types__pull _x_x458 = kk_nagare_core_pull_pullFilter(step, pred, _ctx); /*nagare/core/types/pull<1434,1435>*/
    return kk_nagare_core_types__new_Stream(_x_x458, _ctx);
  }
}
 
// Pipe a stream through a reusable transformation.

static inline kk_nagare_core_types__nstream kk_nagare_core_stream_through(kk_nagare_core_types__nstream source, kk_function_t p, kk_context_t* _ctx) { /* forall<a,b,e> (source : nagare/core/types/nstream<a,e>, p : nagare/core/types/pipe<a,b,e>) -> nagare/core/types/nstream<b,e> */ 
  return kk_function_call(kk_nagare_core_types__nstream, (kk_function_t, kk_nagare_core_types__nstream, kk_context_t*), p, (p, source, _ctx), _ctx);
}
 
// Automatically generated. Retrieves the `@cfc` constructor field of the `:emitter` type.

static inline kk_integer_t kk_nagare_core_stream_emitter_fs__cfc(kk_nagare_core_stream__emitter emitter, kk_context_t* _ctx) { /* forall<a,e,b> (emitter : emitter<a,e,b>) -> int */ 
  {
    struct kk_nagare_core_stream__Hnd_emitter* _con_x459 = kk_nagare_core_stream__as_Hnd_emitter(emitter, _ctx);
    kk_integer_t _x = _con_x459->_cfc;
    return kk_integer_dup(_x, _ctx);
  }
}

extern kk_std_core_hnd__htag kk_nagare_core_stream_emitter_fs__tag;

kk_box_t kk_nagare_core_stream_emitter_fs__handle(kk_nagare_core_stream__emitter hnd, kk_function_t ret, kk_function_t action, kk_context_t* _ctx); /* forall<a,b,e,c> (hnd : emitter<a,e,c>, ret : (res : b) -> e c, action : () -> <emitter<a>|e> b) -> e c */ 
 
// Automatically generated. Retrieves the `@ctl-yieldOne` constructor field of the `:emitter` type.

static inline kk_std_core_hnd__clause1 kk_nagare_core_stream_emitter_fs__ctl_yieldOne(kk_nagare_core_stream__emitter emitter, kk_context_t* _ctx) { /* forall<a,e,b> (emitter : emitter<a,e,b>) -> hnd/clause1<a,(),emitter<a>,e,b> */ 
  {
    struct kk_nagare_core_stream__Hnd_emitter* _con_x463 = kk_nagare_core_stream__as_Hnd_emitter(emitter, _ctx);
    kk_std_core_hnd__clause1 _x = _con_x463->_ctl_yieldOne;
    return kk_std_core_hnd__clause1_dup(_x, _ctx);
  }
}
 
// select `yieldOne` operation out of effect `:emitter`

static inline kk_std_core_hnd__clause1 kk_nagare_core_stream_yieldOne_fs__select(kk_nagare_core_stream__emitter hnd, kk_context_t* _ctx) { /* forall<a,e,b> (hnd : emitter<a,e,b>) -> hnd/clause1<a,(),emitter<a>,e,b> */ 
  {
    struct kk_nagare_core_stream__Hnd_emitter* _con_x464 = kk_nagare_core_stream__as_Hnd_emitter(hnd, _ctx);
    kk_std_core_hnd__clause1 _ctl_yieldOne = _con_x464->_ctl_yieldOne;
    return kk_std_core_hnd__clause1_dup(_ctl_yieldOne, _ctx);
  }
}
 
// Call the `ctl yieldOne` operation of the effect `:emitter`

static inline kk_unit_t kk_nagare_core_stream_yieldOne(kk_box_t x, kk_context_t* _ctx) { /* forall<a> (x : a) -> (emitter<a>) () */ 
  kk_std_core_hnd__ev ev_10486 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<nagare/core/stream/emitter<1982>>*/;
  kk_box_t _x_x465;
  {
    struct kk_std_core_hnd_Ev* _con_x466 = kk_std_core_hnd__as_Ev(ev_10486, _ctx);
    kk_box_t _box_x147 = _con_x466->hnd;
    int32_t m = _con_x466->marker;
    kk_nagare_core_stream__emitter h = kk_nagare_core_stream__emitter_unbox(_box_x147, KK_BORROWED, _ctx);
    kk_nagare_core_stream__emitter_dup(h, _ctx);
    {
      struct kk_nagare_core_stream__Hnd_emitter* _con_x467 = kk_nagare_core_stream__as_Hnd_emitter(h, _ctx);
      kk_integer_t _pat_0_0 = _con_x467->_cfc;
      kk_std_core_hnd__clause1 _pat_1_0 = _con_x467->_ctl_yieldAll;
      kk_std_core_hnd__clause1 _ctl_yieldOne = _con_x467->_ctl_yieldOne;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause1_drop(_pat_1_0, _ctx);
        kk_integer_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_ctl_yieldOne, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x151 = _ctl_yieldOne.clause;
        _x_x465 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x151, (_fun_unbox_x151, m, ev_10486, x, _ctx), _ctx); /*10010*/
      }
    }
  }
  kk_unit_unbox(_x_x465); return kk_Unit;
}
 
// Automatically generated. Retrieves the `@ctl-yieldAll` constructor field of the `:emitter` type.

static inline kk_std_core_hnd__clause1 kk_nagare_core_stream_emitter_fs__ctl_yieldAll(kk_nagare_core_stream__emitter emitter, kk_context_t* _ctx) { /* forall<a,e,b> (emitter : emitter<a,e,b>) -> hnd/clause1<list<a>,(),emitter<a>,e,b> */ 
  {
    struct kk_nagare_core_stream__Hnd_emitter* _con_x468 = kk_nagare_core_stream__as_Hnd_emitter(emitter, _ctx);
    kk_std_core_hnd__clause1 _x = _con_x468->_ctl_yieldAll;
    return kk_std_core_hnd__clause1_dup(_x, _ctx);
  }
}
 
// select `yieldAll` operation out of effect `:emitter`

static inline kk_std_core_hnd__clause1 kk_nagare_core_stream_yieldAll_fs__select(kk_nagare_core_stream__emitter hnd, kk_context_t* _ctx) { /* forall<a,e,b> (hnd : emitter<a,e,b>) -> hnd/clause1<list<a>,(),emitter<a>,e,b> */ 
  {
    struct kk_nagare_core_stream__Hnd_emitter* _con_x469 = kk_nagare_core_stream__as_Hnd_emitter(hnd, _ctx);
    kk_std_core_hnd__clause1 _ctl_yieldAll = _con_x469->_ctl_yieldAll;
    return kk_std_core_hnd__clause1_dup(_ctl_yieldAll, _ctx);
  }
}
 
// Call the `ctl yieldAll` operation of the effect `:emitter`

static inline kk_unit_t kk_nagare_core_stream_yieldAll(kk_std_core_types__list xs, kk_context_t* _ctx) { /* forall<a> (xs : list<a>) -> (emitter<a>) () */ 
  kk_std_core_hnd__ev ev_10489 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<nagare/core/stream/emitter<2122>>*/;
  kk_box_t _x_x470;
  {
    struct kk_std_core_hnd_Ev* _con_x471 = kk_std_core_hnd__as_Ev(ev_10489, _ctx);
    kk_box_t _box_x155 = _con_x471->hnd;
    int32_t m = _con_x471->marker;
    kk_nagare_core_stream__emitter h = kk_nagare_core_stream__emitter_unbox(_box_x155, KK_BORROWED, _ctx);
    kk_nagare_core_stream__emitter_dup(h, _ctx);
    {
      struct kk_nagare_core_stream__Hnd_emitter* _con_x472 = kk_nagare_core_stream__as_Hnd_emitter(h, _ctx);
      kk_integer_t _pat_0_0 = _con_x472->_cfc;
      kk_std_core_hnd__clause1 _ctl_yieldAll = _con_x472->_ctl_yieldAll;
      kk_std_core_hnd__clause1 _pat_1_0 = _con_x472->_ctl_yieldOne;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause1_drop(_pat_1_0, _ctx);
        kk_integer_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_ctl_yieldAll, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x159 = _ctl_yieldAll.clause;
        _x_x470 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x159, (_fun_unbox_x159, m, ev_10489, kk_std_core_types__list_box(xs, _ctx), _ctx), _ctx); /*10010*/
      }
    }
  }
  kk_unit_unbox(_x_x470); return kk_Unit;
}
 
// monadic lift

static inline kk_nagare_core_types__pull kk_nagare_core_stream__mlift_streamOfPull_10435(kk_unit_t wild__, kk_context_t* _ctx) { /* forall<a,e> (wild_ : ()) -> <emitter<a>|e> nagare/core/types/pull<a,e> */ 
  return kk_nagare_core_types__new_PDone(_ctx);
}

kk_nagare_core_types__pull kk_nagare_core_stream_streamOfPull(kk_function_t body, kk_context_t* _ctx); /* forall<a,e> (body : () -> <emitter<a>|e> ()) -> e nagare/core/types/pull<a,e> */ 
 
// monadic lift

static inline kk_nagare_core_types__nstream kk_nagare_core_stream__mlift_streamOf_10436(kk_nagare_core_types__pull _y_x10416, kk_context_t* _ctx) { /* forall<a,e> (nagare/core/types/pull<a,e>) -> e nagare/core/types/nstream<a,e> */ 
  return kk_nagare_core_types__new_Stream(_y_x10416, _ctx);
}

kk_nagare_core_types__nstream kk_nagare_core_stream_streamOf(kk_function_t body, kk_context_t* _ctx); /* forall<a,e> (body : () -> <emitter<a>|e> ()) -> e nagare/core/types/nstream<a,e> */ 

void kk_nagare_core_stream__init(kk_context_t* _ctx);


void kk_nagare_core_stream__done(kk_context_t* _ctx);

#endif // header
