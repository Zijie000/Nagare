#pragma once
#ifndef kk_nagare_core_pull_H
#define kk_nagare_core_pull_H
// Koka generated module: nagare/core/pull, koka version: 3.2.3, platform: 64-bit
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

// type declarations

// value declarations

kk_std_core_types__list kk_nagare_core_pull__trmc_unroll_listAppend_10000(kk_std_core_types__list xs, kk_std_core_types__list ys, kk_std_core_types__cctx _acc, kk_context_t* _ctx); /* forall<a> (xs : list<a>, ys : list<a>, ctx<list<a>>) -> list<a> */ 

kk_std_core_types__list kk_nagare_core_pull__unroll_listAppend_10000(kk_std_core_types__list xs_0, kk_std_core_types__list ys_0, kk_context_t* _ctx); /* forall<a> (xs : list<a>, ys : list<a>) -> list<a> */ 
 
// unrolling of singleton matches of nagare/core/pull/@unroll-listAppend@10000

static inline kk_std_core_types__list kk_nagare_core_pull_listAppend(kk_std_core_types__list xs, kk_std_core_types__list ys, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, ys : list<a>) -> list<a> */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    return ys;
  }
  {
    kk_std_core_types__cctx _x_x464 = kk_cctx_empty(kk_context()); /*ctx<0>*/
    return kk_nagare_core_pull__trmc_unroll_listAppend_10000(xs, ys, _x_x464, _ctx);
  }
}

kk_integer_t kk_nagare_core_pull__unroll_listLength_10001(kk_std_core_types__list xs, kk_context_t* _ctx); /* forall<a> (xs : list<a>) -> int */ 
 
// unrolling of singleton matches of nagare/core/pull/@unroll-listLength@10001

static inline kk_integer_t kk_nagare_core_pull_listLength(kk_std_core_types__list xs, kk_context_t* _ctx) { /* forall<a> (xs : list<a>) -> int */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    return kk_integer_from_small(0);
  }
  {
    return kk_nagare_core_pull__unroll_listLength_10001(xs, _ctx);
  }
}

kk_std_core_types__list kk_nagare_core_pull__trmc_listTakeN(kk_std_core_types__list xs, kk_integer_t n, kk_std_core_types__cctx _acc, kk_context_t* _ctx); /* forall<a> (xs : list<a>, n : int, ctx<list<a>>) -> list<a> */ 

kk_std_core_types__list kk_nagare_core_pull_listTakeN(kk_std_core_types__list xs_0, kk_integer_t n_0, kk_context_t* _ctx); /* forall<a> (xs : list<a>, n : int) -> list<a> */ 

kk_std_core_types__list kk_nagare_core_pull_listDropN(kk_std_core_types__list xs, kk_integer_t n, kk_context_t* _ctx); /* forall<a> (xs : list<a>, n : int) -> list<a> */ 

kk_std_core_types__list kk_nagare_core_pull__trmc_unroll_listTakeWhile_10002(kk_std_core_types__list xs, kk_function_t pred, kk_std_core_types__cctx _acc, kk_context_t* _ctx); /* forall<a> (xs : list<a>, pred : (a) -> bool, ctx<list<a>>) -> list<a> */ 

kk_std_core_types__list kk_nagare_core_pull__unroll_listTakeWhile_10002(kk_std_core_types__list xs_0, kk_function_t pred_0, kk_context_t* _ctx); /* forall<a> (xs : list<a>, pred : (a) -> bool) -> list<a> */ 
 
// unrolling of singleton matches of nagare/core/pull/@unroll-listTakeWhile@10002

static inline kk_std_core_types__list kk_nagare_core_pull_listTakeWhile(kk_std_core_types__list xs, kk_function_t pred, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, pred : (a) -> bool) -> list<a> */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_function_drop(pred, _ctx);
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    kk_std_core_types__cctx _x_x481 = kk_cctx_empty(kk_context()); /*ctx<0>*/
    return kk_nagare_core_pull__trmc_unroll_listTakeWhile_10002(xs, pred, _x_x481, _ctx);
  }
}

kk_std_core_types__list kk_nagare_core_pull__unroll_listDropWhile_10003(kk_std_core_types__list xs, kk_function_t pred, kk_context_t* _ctx); /* forall<a> (xs : list<a>, pred : (a) -> bool) -> list<a> */ 
 
// unrolling of singleton matches of nagare/core/pull/@unroll-listDropWhile@10003

static inline kk_std_core_types__list kk_nagare_core_pull_listDropWhile(kk_std_core_types__list xs, kk_function_t pred, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, pred : (a) -> bool) -> list<a> */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_function_drop(pred, _ctx);
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    return kk_nagare_core_pull__unroll_listDropWhile_10003(xs, pred, _ctx);
  }
}

kk_std_core_types__list kk_nagare_core_pull__unroll_lift_listReverse_2782_10004(kk_std_core_types__list rest, kk_std_core_types__list acc, kk_context_t* _ctx); /* forall<a> (rest : list<a>, acc : list<a>) -> list<a> */ 
 
// unrolling of singleton matches of nagare/core/pull/@unroll-lift-listReverse@2782@10004

static inline kk_std_core_types__list kk_nagare_core_pull__lift_listReverse_2782(kk_std_core_types__list rest, kk_std_core_types__list acc, kk_context_t* _ctx) { /* forall<a> (rest : list<a>, acc : list<a>) -> list<a> */ 
  if (kk_std_core_types__is_Nil(rest, _ctx)) {
    return acc;
  }
  {
    return kk_nagare_core_pull__unroll_lift_listReverse_2782_10004(rest, acc, _ctx);
  }
}
 
// Reverse a list.

static inline kk_std_core_types__list kk_nagare_core_pull_listReverse(kk_std_core_types__list xs, kk_context_t* _ctx) { /* forall<a> (xs : list<a>) -> list<a> */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    return kk_nagare_core_pull__unroll_lift_listReverse_2782_10004(xs, kk_std_core_types__new_Nil(_ctx), _ctx);
  }
}

kk_std_core_types__list kk_nagare_core_pull__unroll_flattenChunks_10005(kk_std_core_types__list chunks, kk_context_t* _ctx); /* forall<a> (chunks : list<nagare/core/types/chunk<a>>) -> list<a> */ 
 
// unrolling of singleton matches of nagare/core/pull/@unroll-flattenChunks@10005

static inline kk_std_core_types__list kk_nagare_core_pull_flattenChunks(kk_std_core_types__list chunks, kk_context_t* _ctx) { /* forall<a> (chunks : list<nagare/core/types/chunk<a>>) -> list<a> */ 
  if (kk_std_core_types__is_Nil(chunks, _ctx)) {
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    return kk_nagare_core_pull__unroll_flattenChunks_10005(chunks, _ctx);
  }
}

kk_std_core_types__list kk_nagare_core_pull__unroll_lift_listChunkN_2783_10006(kk_integer_t n, kk_std_core_types__list rest, kk_std_core_types__list curRev, kk_integer_t curLen, kk_std_core_types__list chunksRev, kk_context_t* _ctx); /* forall<a> (n : int, rest : list<a>, curRev : list<a>, curLen : int, chunksRev : list<nagare/core/types/chunk<a>>) -> list<nagare/core/types/chunk<a>> */ 
 
// unrolling of singleton matches of nagare/core/pull/@unroll-lift-listChunkN@2783@10006

static inline kk_std_core_types__list kk_nagare_core_pull__lift_listChunkN_2783(kk_integer_t n, kk_std_core_types__list rest, kk_std_core_types__list curRev, kk_integer_t curLen, kk_std_core_types__list chunksRev, kk_context_t* _ctx) { /* forall<a> (n : int, rest : list<a>, curRev : list<a>, curLen : int, chunksRev : list<nagare/core/types/chunk<a>>) -> list<nagare/core/types/chunk<a>> */ 
  if (kk_std_core_types__is_Nil(rest, _ctx)) {
    kk_integer_drop(n, _ctx);
    kk_integer_drop(curLen, _ctx);
    if (kk_std_core_types__is_Nil(curRev, _ctx)) {
      if (kk_std_core_types__is_Nil(chunksRev, _ctx)) {
        return kk_std_core_types__new_Nil(_ctx);
      }
      {
        return kk_nagare_core_pull__unroll_lift_listReverse_2782_10004(chunksRev, kk_std_core_types__new_Nil(_ctx), _ctx);
      }
    }
    {
      kk_nagare_core_types__chunk _b_x65_67;
      kk_std_core_types__list _x_x494;
      if (kk_std_core_types__is_Nil(curRev, _ctx)) {
        _x_x494 = kk_std_core_types__new_Nil(_ctx); /*forall<a> list<a>*/
      }
      else {
        _x_x494 = kk_nagare_core_pull__unroll_lift_listReverse_2782_10004(curRev, kk_std_core_types__new_Nil(_ctx), _ctx); /*forall<a> list<a>*/
      }
      _b_x65_67 = kk_nagare_core_types__new_Chunk(_x_x494, _ctx); /*nagare/core/types/chunk<825>*/
      kk_std_core_types__list xs_0_10037 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_nagare_core_types__chunk_box(_b_x65_67, _ctx), chunksRev, _ctx); /*list<nagare/core/types/chunk<825>>*/;
      if (kk_std_core_types__is_Nil(xs_0_10037, _ctx)) {
        return kk_std_core_types__new_Nil(_ctx);
      }
      {
        return kk_nagare_core_pull__unroll_lift_listReverse_2782_10004(xs_0_10037, kk_std_core_types__new_Nil(_ctx), _ctx);
      }
    }
  }
  {
    return kk_nagare_core_pull__unroll_lift_listChunkN_2783_10006(n, rest, curRev, curLen, chunksRev, _ctx);
  }
}

kk_std_core_types__list kk_nagare_core_pull_listChunkN(kk_std_core_types__list values, kk_integer_t n, kk_context_t* _ctx); /* forall<a> (values : list<a>, n : int) -> list<nagare/core/types/chunk<a>> */ 
 
// Map over all elements in a chunk.

static inline kk_nagare_core_types__chunk kk_nagare_core_pull_chunkMap(kk_nagare_core_types__chunk c, kk_function_t f, kk_context_t* _ctx) { /* forall<a,b> (c : nagare/core/types/chunk<a>, f : (a) -> b) -> nagare/core/types/chunk<b> */ 
  {
    kk_std_core_types__list values = c.values;
    kk_std_core_types__list _x_x495;
    kk_std_core_types__list _brw_x410 = kk_std_core_list_map(values, f, _ctx); /*list<10002>*/;
    kk_function_drop(f, _ctx);
    _x_x495 = _brw_x410; /*list<10002>*/
    return kk_nagare_core_types__new_Chunk(_x_x495, _ctx);
  }
}
 
// Filter elements inside a chunk (may produce empty chunk).

static inline kk_nagare_core_types__chunk kk_nagare_core_pull_chunkFilter(kk_nagare_core_types__chunk c, kk_function_t pred, kk_context_t* _ctx) { /* forall<a> (c : nagare/core/types/chunk<a>, pred : (a) -> bool) -> nagare/core/types/chunk<a> */ 
  {
    kk_std_core_types__list values = c.values;
    kk_std_core_types__list _x_x496 = kk_std_core_list_filter(values, pred, _ctx); /*list<10001>*/
    return kk_nagare_core_types__new_Chunk(_x_x496, _ctx);
  }
}

kk_nagare_core_types__pull kk_nagare_core_pull__mlift_trmc_unroll_pullAppend_10007_10312(kk_function_t right, kk_nagare_core_types__pull _y_x10264, kk_context_t* _ctx); /* forall<a,e> (right : () -> nagare/core/types/pull<a,e>, nagare/core/types/pull<a,e>) -> e nagare/core/types/pull<a,e> */ 

kk_nagare_core_types__pull kk_nagare_core_pull__trmc_unroll_pullAppend_10007(kk_nagare_core_types__pull left, kk_function_t right_0, kk_std_core_types__cctx _acc, kk_context_t* _ctx); /* forall<a,e> (left : nagare/core/types/pull<a,e>, right : () -> nagare/core/types/pull<a,e>, ctx<nagare/core/types/pull<a,e>>) -> nagare/core/types/pull<a,e> */ 

kk_nagare_core_types__pull kk_nagare_core_pull__unroll_pullAppend_10007(kk_nagare_core_types__pull left_0, kk_function_t right_1, kk_context_t* _ctx); /* forall<a,e> (left : nagare/core/types/pull<a,e>, right : () -> nagare/core/types/pull<a,e>) -> nagare/core/types/pull<a,e> */ 
 
// unrolling of singleton matches of nagare/core/pull/@unroll-pullAppend@10007

static inline kk_nagare_core_types__pull kk_nagare_core_pull_pullAppend(kk_nagare_core_types__pull left, kk_function_t right, kk_context_t* _ctx) { /* forall<a,e> (left : nagare/core/types/pull<a,e>, right : () -> nagare/core/types/pull<a,e>) -> nagare/core/types/pull<a,e> */ 
  if (kk_nagare_core_types__is_PDone(left, _ctx)) {
    return kk_function_call(kk_nagare_core_types__pull, (kk_function_t, kk_context_t*), right, (right, _ctx), _ctx);
  }
  {
    kk_std_core_types__cctx _x_x511 = kk_cctx_empty(kk_context()); /*ctx<0>*/
    return kk_nagare_core_pull__trmc_unroll_pullAppend_10007(left, right, _x_x511, _ctx);
  }
}

kk_nagare_core_types__pull kk_nagare_core_pull__mlift_trmc_unroll_pullMap_10008_10313(kk_function_t f, kk_nagare_core_types__pull _y_x10267, kk_context_t* _ctx); /* forall<a,b,e> (f : (a) -> b, nagare/core/types/pull<a,e>) -> e nagare/core/types/pull<b,e> */ 

kk_nagare_core_types__pull kk_nagare_core_pull__trmc_unroll_pullMap_10008(kk_nagare_core_types__pull source, kk_function_t f_0, kk_std_core_types__cctx _acc, kk_context_t* _ctx); /* forall<a,b,e> (source : nagare/core/types/pull<a,e>, f : (a) -> b, ctx<nagare/core/types/pull<b,e>>) -> nagare/core/types/pull<b,e> */ 

kk_nagare_core_types__pull kk_nagare_core_pull__unroll_pullMap_10008(kk_nagare_core_types__pull source_0, kk_function_t f_1, kk_context_t* _ctx); /* forall<a,b,e> (source : nagare/core/types/pull<a,e>, f : (a) -> b) -> nagare/core/types/pull<b,e> */ 
 
// unrolling of singleton matches of nagare/core/pull/@unroll-pullMap@10008

static inline kk_nagare_core_types__pull kk_nagare_core_pull_pullMap(kk_nagare_core_types__pull source, kk_function_t f, kk_context_t* _ctx) { /* forall<a,b,e> (source : nagare/core/types/pull<a,e>, f : (a) -> b) -> nagare/core/types/pull<b,e> */ 
  if (kk_nagare_core_types__is_PDone(source, _ctx)) {
    kk_function_drop(f, _ctx);
    return kk_nagare_core_types__new_PDone(_ctx);
  }
  {
    kk_std_core_types__cctx _x_x527 = kk_cctx_empty(kk_context()); /*ctx<0>*/
    return kk_nagare_core_pull__trmc_unroll_pullMap_10008(source, f, _x_x527, _ctx);
  }
}

kk_nagare_core_types__pull kk_nagare_core_pull__mlift_trmc_unroll_pullFilter_10009_10314(kk_function_t pred, kk_nagare_core_types__pull _y_x10270, kk_context_t* _ctx); /* forall<a,e> (pred : (a) -> bool, nagare/core/types/pull<a,e>) -> e nagare/core/types/pull<a,e> */ 

kk_nagare_core_types__pull kk_nagare_core_pull__trmc_unroll_pullFilter_10009(kk_nagare_core_types__pull source, kk_function_t pred_0, kk_std_core_types__cctx _acc, kk_context_t* _ctx); /* forall<a,e> (source : nagare/core/types/pull<a,e>, pred : (a) -> bool, ctx<nagare/core/types/pull<a,e>>) -> nagare/core/types/pull<a,e> */ 

kk_nagare_core_types__pull kk_nagare_core_pull__unroll_pullFilter_10009(kk_nagare_core_types__pull source_0, kk_function_t pred_1, kk_context_t* _ctx); /* forall<a,e> (source : nagare/core/types/pull<a,e>, pred : (a) -> bool) -> nagare/core/types/pull<a,e> */ 
 
// unrolling of singleton matches of nagare/core/pull/@unroll-pullFilter@10009

static inline kk_nagare_core_types__pull kk_nagare_core_pull_pullFilter(kk_nagare_core_types__pull source, kk_function_t pred, kk_context_t* _ctx) { /* forall<a,e> (source : nagare/core/types/pull<a,e>, pred : (a) -> bool) -> nagare/core/types/pull<a,e> */ 
  if (kk_nagare_core_types__is_PDone(source, _ctx)) {
    kk_function_drop(pred, _ctx);
    return kk_nagare_core_types__new_PDone(_ctx);
  }
  {
    kk_std_core_types__cctx _x_x544 = kk_cctx_empty(kk_context()); /*ctx<0>*/
    return kk_nagare_core_pull__trmc_unroll_pullFilter_10009(source, pred, _x_x544, _ctx);
  }
}

kk_nagare_core_types__pull kk_nagare_core_pull__mlift_lift_unroll_flatMapChunk_10010_10220_10315(kk_function_t f, kk_std_core_types__list xt, kk_nagare_core_types__pull _y_x10273, kk_context_t* _ctx); /* forall<a,b,e> (f : (a) -> nagare/core/types/pull<b,e>, xt : list<a>, nagare/core/types/pull<b,e>) -> e nagare/core/types/pull<b,e> */ 

kk_nagare_core_types__pull kk_nagare_core_pull__lift_unroll_flatMapChunk_10010_10220(kk_function_t f_0, kk_std_core_types__list xt_0, kk_nagare_core_types__pull _uniq_left_10194, kk_context_t* _ctx); /* forall<a,b,e> (f : (a) -> nagare/core/types/pull<b,e>, xt : list<a>, nagare/core/types/pull<b,e>) -> nagare/core/types/pull<b,e> */ 

kk_nagare_core_types__pull kk_nagare_core_pull__unroll_flatMapChunk_10010(kk_std_core_types__list values, kk_function_t f_1, kk_context_t* _ctx); /* forall<a,b,e> (values : list<a>, f : (a) -> nagare/core/types/pull<b,e>) -> nagare/core/types/pull<b,e> */ 
 
// unrolling of singleton matches of nagare/core/pull/@unroll-flatMapChunk@10010

static inline kk_nagare_core_types__pull kk_nagare_core_pull_flatMapChunk(kk_std_core_types__list values, kk_function_t f, kk_context_t* _ctx) { /* forall<a,b,e> (values : list<a>, f : (a) -> nagare/core/types/pull<b,e>) -> nagare/core/types/pull<b,e> */ 
  if (kk_std_core_types__is_Nil(values, _ctx)) {
    kk_function_drop(f, _ctx);
    return kk_nagare_core_types__new_PDone(_ctx);
  }
  {
    return kk_nagare_core_pull__unroll_flatMapChunk_10010(values, f, _ctx);
  }
}

kk_nagare_core_types__pull kk_nagare_core_pull__mlift_lift_unroll_pullFlatMap_10011_10221_10316(kk_function_t f, kk_nagare_core_types__pull tail, kk_nagare_core_types__pull _y_x10278, kk_context_t* _ctx); /* forall<a,b,e> (f : (a) -> nagare/core/types/pull<b,e>, tail : nagare/core/types/pull<a,e>, nagare/core/types/pull<b,e>) -> e nagare/core/types/pull<b,e> */ 

kk_nagare_core_types__pull kk_nagare_core_pull__mlift_unroll_pullFlatMap_10011_10317(kk_function_t f_0, kk_nagare_core_types__pull tail_0, kk_nagare_core_types__pull _c_x10280, kk_context_t* _ctx); /* forall<a,b,e> (f : (a) -> nagare/core/types/pull<b,e>, tail : nagare/core/types/pull<a,e>, nagare/core/types/pull<b,e>) -> nagare/core/types/pull<b,e> */ 

kk_nagare_core_types__pull kk_nagare_core_pull__mlift_unroll_pullFlatMap_10011_10318(kk_function_t f_1, kk_nagare_core_types__pull _y_x10283, kk_context_t* _ctx); /* forall<a,b,e> (f : (a) -> nagare/core/types/pull<b,e>, nagare/core/types/pull<a,e>) -> e nagare/core/types/pull<b,e> */ 

kk_nagare_core_types__pull kk_nagare_core_pull__lift_unroll_pullFlatMap_10011_10221(kk_function_t f_2, kk_nagare_core_types__pull tail_1, kk_nagare_core_types__pull _uniq_left_10207, kk_context_t* _ctx); /* forall<a,b,e> (f : (a) -> nagare/core/types/pull<b,e>, tail : nagare/core/types/pull<a,e>, nagare/core/types/pull<b,e>) -> nagare/core/types/pull<b,e> */ 

kk_nagare_core_types__pull kk_nagare_core_pull__unroll_pullFlatMap_10011(kk_nagare_core_types__pull source, kk_function_t f_3, kk_context_t* _ctx); /* forall<a,b,e> (source : nagare/core/types/pull<a,e>, f : (a) -> nagare/core/types/pull<b,e>) -> nagare/core/types/pull<b,e> */ 
 
// unrolling of singleton matches of nagare/core/pull/@unroll-pullFlatMap@10011

static inline kk_nagare_core_types__pull kk_nagare_core_pull_pullFlatMap(kk_nagare_core_types__pull source, kk_function_t f, kk_context_t* _ctx) { /* forall<a,b,e> (source : nagare/core/types/pull<a,e>, f : (a) -> nagare/core/types/pull<b,e>) -> nagare/core/types/pull<b,e> */ 
  if (kk_nagare_core_types__is_PDone(source, _ctx)) {
    kk_function_drop(f, _ctx);
    return kk_nagare_core_types__new_PDone(_ctx);
  }
  {
    return kk_nagare_core_pull__unroll_pullFlatMap_10011(source, f, _ctx);
  }
}

kk_nagare_core_types__pull kk_nagare_core_pull__mlift_trmc_pullTake_10319(kk_integer_t n, kk_nagare_core_types__pull _y_x10288, kk_context_t* _ctx); /* forall<a,e> (n : int, nagare/core/types/pull<a,e>) -> e nagare/core/types/pull<a,e> */ 

kk_nagare_core_types__pull kk_nagare_core_pull__trmc_pullTake(kk_nagare_core_types__pull source, kk_integer_t n_0, kk_std_core_types__cctx _acc, kk_context_t* _ctx); /* forall<a,e> (source : nagare/core/types/pull<a,e>, n : int, ctx<nagare/core/types/pull<a,e>>) -> nagare/core/types/pull<a,e> */ 

kk_nagare_core_types__pull kk_nagare_core_pull_pullTake(kk_nagare_core_types__pull source_0, kk_integer_t n_2, kk_context_t* _ctx); /* forall<a,e> (source : nagare/core/types/pull<a,e>, n : int) -> nagare/core/types/pull<a,e> */ 

kk_nagare_core_types__pull kk_nagare_core_pull__mlift_trmc_pullDrop_10320(kk_integer_t n, kk_nagare_core_types__pull _y_x10293, kk_context_t* _ctx); /* forall<a,e> (n : int, nagare/core/types/pull<a,e>) -> e nagare/core/types/pull<a,e> */ 

kk_nagare_core_types__pull kk_nagare_core_pull__trmc_pullDrop(kk_nagare_core_types__pull source, kk_integer_t n_0, kk_std_core_types__cctx _acc, kk_context_t* _ctx); /* forall<a,e> (source : nagare/core/types/pull<a,e>, n : int, ctx<nagare/core/types/pull<a,e>>) -> nagare/core/types/pull<a,e> */ 

kk_nagare_core_types__pull kk_nagare_core_pull_pullDrop(kk_nagare_core_types__pull source_0, kk_integer_t n_1, kk_context_t* _ctx); /* forall<a,e> (source : nagare/core/types/pull<a,e>, n : int) -> nagare/core/types/pull<a,e> */ 

kk_nagare_core_types__pull kk_nagare_core_pull__mlift_trmc_unroll_pullTakeWhile_10012_10321(kk_function_t pred, kk_nagare_core_types__pull _y_x10299, kk_context_t* _ctx); /* forall<a,e> (pred : (a) -> bool, nagare/core/types/pull<a,e>) -> e nagare/core/types/pull<a,e> */ 

kk_nagare_core_types__pull kk_nagare_core_pull__trmc_unroll_pullTakeWhile_10012(kk_nagare_core_types__pull source, kk_function_t pred_0, kk_std_core_types__cctx _acc, kk_context_t* _ctx); /* forall<a,e> (source : nagare/core/types/pull<a,e>, pred : (a) -> bool, ctx<nagare/core/types/pull<a,e>>) -> nagare/core/types/pull<a,e> */ 

kk_nagare_core_types__pull kk_nagare_core_pull__unroll_pullTakeWhile_10012(kk_nagare_core_types__pull source_0, kk_function_t pred_2, kk_context_t* _ctx); /* forall<a,e> (source : nagare/core/types/pull<a,e>, pred : (a) -> bool) -> nagare/core/types/pull<a,e> */ 
 
// unrolling of singleton matches of nagare/core/pull/@unroll-pullTakeWhile@10012

static inline kk_nagare_core_types__pull kk_nagare_core_pull_pullTakeWhile(kk_nagare_core_types__pull source, kk_function_t pred, kk_context_t* _ctx) { /* forall<a,e> (source : nagare/core/types/pull<a,e>, pred : (a) -> bool) -> nagare/core/types/pull<a,e> */ 
  if (kk_nagare_core_types__is_PDone(source, _ctx)) {
    kk_function_drop(pred, _ctx);
    return kk_nagare_core_types__new_PDone(_ctx);
  }
  {
    kk_std_core_types__cctx _x_x646 = kk_cctx_empty(kk_context()); /*ctx<0>*/
    return kk_nagare_core_pull__trmc_unroll_pullTakeWhile_10012(source, pred, _x_x646, _ctx);
  }
}

kk_nagare_core_types__pull kk_nagare_core_pull__mlift_trmc_pullChunkN_10322(kk_integer_t n, kk_nagare_core_types__pull _y_x10304, kk_context_t* _ctx); /* forall<a,e> (n : int, nagare/core/types/pull<a,e>) -> e nagare/core/types/pull<nagare/core/types/chunk<a>,e> */ 

kk_nagare_core_types__pull kk_nagare_core_pull__trmc_pullChunkN(kk_nagare_core_types__pull source, kk_integer_t n_0, kk_std_core_types__cctx _acc, kk_context_t* _ctx); /* forall<a,e> (source : nagare/core/types/pull<a,e>, n : int, ctx<nagare/core/types/pull<nagare/core/types/chunk<a>,e>>) -> nagare/core/types/pull<nagare/core/types/chunk<a>,e> */ 

kk_nagare_core_types__pull kk_nagare_core_pull_pullChunkN(kk_nagare_core_types__pull source_0, kk_integer_t n_1, kk_context_t* _ctx); /* forall<a,e> (source : nagare/core/types/pull<a,e>, n : int) -> nagare/core/types/pull<nagare/core/types/chunk<a>,e> */ 

kk_nagare_core_types__pull kk_nagare_core_pull__mlift_trmc_unroll_pullUnchunks_10013_10323(kk_nagare_core_types__pull _y_x10309, kk_context_t* _ctx); /* forall<a,e> (nagare/core/types/pull<nagare/core/types/chunk<a>,e>) -> e nagare/core/types/pull<a,e> */ 

kk_nagare_core_types__pull kk_nagare_core_pull__trmc_unroll_pullUnchunks_10013(kk_nagare_core_types__pull source, kk_std_core_types__cctx _acc, kk_context_t* _ctx); /* forall<a,e> (source : nagare/core/types/pull<nagare/core/types/chunk<a>,e>, ctx<nagare/core/types/pull<a,e>>) -> nagare/core/types/pull<a,e> */ 

kk_nagare_core_types__pull kk_nagare_core_pull__unroll_pullUnchunks_10013(kk_nagare_core_types__pull source_0, kk_context_t* _ctx); /* forall<a,e> (source : nagare/core/types/pull<nagare/core/types/chunk<a>,e>) -> nagare/core/types/pull<a,e> */ 
 
// unrolling of singleton matches of nagare/core/pull/@unroll-pullUnchunks@10013

static inline kk_nagare_core_types__pull kk_nagare_core_pull_pullUnchunks(kk_nagare_core_types__pull source, kk_context_t* _ctx) { /* forall<a,e> (source : nagare/core/types/pull<nagare/core/types/chunk<a>,e>) -> nagare/core/types/pull<a,e> */ 
  if (kk_nagare_core_types__is_PDone(source, _ctx)) {
    return kk_nagare_core_types__new_PDone(_ctx);
  }
  {
    kk_std_core_types__cctx _x_x679 = kk_cctx_empty(kk_context()); /*ctx<0>*/
    return kk_nagare_core_pull__trmc_unroll_pullUnchunks_10013(source, _x_x679, _ctx);
  }
}

void kk_nagare_core_pull__init(kk_context_t* _ctx);


void kk_nagare_core_pull__done(kk_context_t* _ctx);

#endif // header
