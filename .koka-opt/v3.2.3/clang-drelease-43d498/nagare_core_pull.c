// Koka generated module: nagare/core/pull, koka version: 3.2.3, platform: 64-bit
#include "nagare_core_pull.h"
 
// Append two lists (internal helper).

kk_std_core_types__list kk_nagare_core_pull__trmc_unroll_listAppend_10000(kk_std_core_types__list xs, kk_std_core_types__list ys, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, ys : list<a>, ctx<list<a>>) -> list<a> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_box_t _x_x460 = kk_cctx_apply_linear(_acc,(kk_std_core_types__list_box(ys, _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x460, KK_OWNED, _ctx);
  }
  {
    struct kk_std_core_types_Cons* _con_x461 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x461->head;
    kk_std_core_types__list xt = _con_x461->tail;
    kk_reuse_t _ru_x417 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      _ru_x417 = (kk_datatype_ptr_reuse(xs, _ctx));
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xt, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    kk_std_core_types__list _trmc_x10226 = kk_datatype_null(); /*list<232>*/;
    kk_std_core_types__list _trmc_x10227 = kk_std_core_types__new_Cons(_ru_x417, 0, x, _trmc_x10226, _ctx); /*list<232>*/;
    kk_field_addr_t _b_x7_12 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10227, _ctx)->tail, _ctx); /*@field-addr<list<232>>*/;
    { // tailcall
      kk_std_core_types__cctx _x_x462 = kk_cctx_extend_linear(_acc,(kk_std_core_types__list_box(_trmc_x10227, _ctx)),_b_x7_12,kk_context()); /*ctx<0>*/
      xs = xt;
      _acc = _x_x462;
      goto kk__tailcall;
    }
  }
}
 
// Append two lists (internal helper).

kk_std_core_types__list kk_nagare_core_pull__unroll_listAppend_10000(kk_std_core_types__list xs_0, kk_std_core_types__list ys_0, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, ys : list<a>) -> list<a> */ 
  kk_std_core_types__cctx _x_x463 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_nagare_core_pull__trmc_unroll_listAppend_10000(xs_0, ys_0, _x_x463, _ctx);
}
 
// Length of a list.

kk_integer_t kk_nagare_core_pull__unroll_listLength_10001(kk_std_core_types__list xs, kk_context_t* _ctx) { /* forall<a> (xs : list<a>) -> int */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    return kk_integer_from_small(0);
  }
  {
    struct kk_std_core_types_Cons* _con_x465 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t _pat_1 = _con_x465->head;
    kk_std_core_types__list xt = _con_x465->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_box_drop(_pat_1, _ctx);
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_std_core_types__list_dup(xt, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    kk_integer_t y_10015 = kk_nagare_core_pull__unroll_listLength_10001(xt, _ctx); /*int*/;
    return kk_integer_add_small_const(y_10015, 1, _ctx);
  }
}
 
// Keep first n elements from a list.

kk_std_core_types__list kk_nagare_core_pull__trmc_listTakeN(kk_std_core_types__list xs, kk_integer_t n, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, n : int, ctx<list<a>>) -> list<a> */ 
  kk__tailcall: ;
  bool _match_x416 = kk_integer_lte_borrow(n,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x416) {
    kk_std_core_types__list_drop(xs, _ctx);
    kk_integer_drop(n, _ctx);
    kk_box_t _x_x466 = kk_cctx_apply_linear(_acc,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x466, KK_OWNED, _ctx);
  }
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_integer_drop(n, _ctx);
    kk_box_t _x_x467 = kk_cctx_apply_linear(_acc,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x467, KK_OWNED, _ctx);
  }
  {
    struct kk_std_core_types_Cons* _con_x468 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x468->head;
    kk_std_core_types__list xt = _con_x468->tail;
    kk_reuse_t _ru_x419 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      _ru_x419 = (kk_datatype_ptr_reuse(xs, _ctx));
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xt, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    kk_std_core_types__list _trmc_x10228 = kk_datatype_null(); /*list<359>*/;
    kk_std_core_types__list _trmc_x10229 = kk_std_core_types__new_Cons(_ru_x419, 0, x, _trmc_x10228, _ctx); /*list<359>*/;
    kk_field_addr_t _b_x25_32 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10229, _ctx)->tail, _ctx); /*@field-addr<list<359>>*/;
    { // tailcall
      kk_integer_t _x_x469 = kk_integer_add_small_const(n, -1, _ctx); /*int*/
      kk_std_core_types__cctx _x_x470 = kk_cctx_extend_linear(_acc,(kk_std_core_types__list_box(_trmc_x10229, _ctx)),_b_x25_32,kk_context()); /*ctx<0>*/
      xs = xt;
      n = _x_x469;
      _acc = _x_x470;
      goto kk__tailcall;
    }
  }
}
 
// Keep first n elements from a list.

kk_std_core_types__list kk_nagare_core_pull_listTakeN(kk_std_core_types__list xs_0, kk_integer_t n_0, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, n : int) -> list<a> */ 
  kk_std_core_types__cctx _x_x471 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_nagare_core_pull__trmc_listTakeN(xs_0, n_0, _x_x471, _ctx);
}
 
// Drop first n elements from a list.

kk_std_core_types__list kk_nagare_core_pull_listDropN(kk_std_core_types__list xs, kk_integer_t n, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, n : int) -> list<a> */ 
  kk__tailcall: ;
  bool _match_x415 = kk_integer_lte_borrow(n,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x415) {
    kk_integer_drop(n, _ctx);
    return xs;
  }
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_integer_drop(n, _ctx);
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    struct kk_std_core_types_Cons* _con_x472 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t _pat_3 = _con_x472->head;
    kk_std_core_types__list xt = _con_x472->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_box_drop(_pat_3, _ctx);
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_std_core_types__list_dup(xt, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    { // tailcall
      kk_integer_t _x_x473 = kk_integer_add_small_const(n, -1, _ctx); /*int*/
      xs = xt;
      n = _x_x473;
      goto kk__tailcall;
    }
  }
}
 
// Keep longest prefix while predicate holds.

kk_std_core_types__list kk_nagare_core_pull__trmc_unroll_listTakeWhile_10002(kk_std_core_types__list xs, kk_function_t pred, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, pred : (a) -> bool, ctx<list<a>>) -> list<a> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_function_drop(pred, _ctx);
    kk_box_t _x_x474 = kk_cctx_apply_linear(_acc,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x474, KK_OWNED, _ctx);
  }
  {
    struct kk_std_core_types_Cons* _con_x475 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x475->head;
    kk_std_core_types__list xt = _con_x475->tail;
    kk_reuse_t _ru_x421 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      _ru_x421 = (kk_datatype_ptr_reuse(xs, _ctx));
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xt, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    bool _match_x414;
    kk_function_t _x_x477 = kk_function_dup(pred, _ctx); /*(495) -> bool*/
    kk_box_t _x_x476 = kk_box_dup(x, _ctx); /*495*/
    _match_x414 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), _x_x477, (_x_x477, _x_x476, _ctx), _ctx); /*bool*/
    if (_match_x414) {
      kk_std_core_types__list _trmc_x10230 = kk_datatype_null(); /*list<495>*/;
      kk_std_core_types__list _trmc_x10231 = kk_std_core_types__new_Cons(_ru_x421, 0, x, _trmc_x10230, _ctx); /*list<495>*/;
      kk_field_addr_t _b_x43_50 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10231, _ctx)->tail, _ctx); /*@field-addr<list<495>>*/;
      { // tailcall
        kk_std_core_types__cctx _x_x478 = kk_cctx_extend_linear(_acc,(kk_std_core_types__list_box(_trmc_x10231, _ctx)),_b_x43_50,kk_context()); /*ctx<0>*/
        xs = xt;
        _acc = _x_x478;
        goto kk__tailcall;
      }
    }
    {
      kk_reuse_drop(_ru_x421,kk_context());
      kk_std_core_types__list_drop(xt, _ctx);
      kk_box_drop(x, _ctx);
      kk_function_drop(pred, _ctx);
      kk_box_t _x_x479 = kk_cctx_apply_linear(_acc,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
      return kk_std_core_types__list_unbox(_x_x479, KK_OWNED, _ctx);
    }
  }
}
 
// Keep longest prefix while predicate holds.

kk_std_core_types__list kk_nagare_core_pull__unroll_listTakeWhile_10002(kk_std_core_types__list xs_0, kk_function_t pred_0, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, pred : (a) -> bool) -> list<a> */ 
  kk_std_core_types__cctx _x_x480 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_nagare_core_pull__trmc_unroll_listTakeWhile_10002(xs_0, pred_0, _x_x480, _ctx);
}
 
// Drop longest prefix while predicate holds.

kk_std_core_types__list kk_nagare_core_pull__unroll_listDropWhile_10003(kk_std_core_types__list xs, kk_function_t pred, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, pred : (a) -> bool) -> list<a> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_function_drop(pred, _ctx);
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    struct kk_std_core_types_Cons* _con_x482 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x482->head;
    kk_std_core_types__list xt = _con_x482->tail;
    kk_box_dup(x, _ctx);
    kk_std_core_types__list_dup(xt, _ctx);
    bool _match_x413;
    kk_function_t _x_x483 = kk_function_dup(pred, _ctx); /*(540) -> bool*/
    _match_x413 = kk_function_call(bool, (kk_function_t, kk_box_t, kk_context_t*), _x_x483, (_x_x483, x, _ctx), _ctx); /*bool*/
    if (_match_x413) {
      if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
        kk_std_core_types__list_drop(xt, _ctx);
        kk_box_drop(x, _ctx);
        kk_datatype_ptr_free(xs, _ctx);
      }
      else {
        kk_datatype_ptr_decref(xs, _ctx);
      }
      { // tailcall
        xs = xt;
        goto kk__tailcall;
      }
    }
    {
      kk_std_core_types__list_drop(xt, _ctx);
      kk_function_drop(pred, _ctx);
      return xs;
    }
  }
}
 
// lifted local: listReverse, go

kk_std_core_types__list kk_nagare_core_pull__unroll_lift_listReverse_2782_10004(kk_std_core_types__list rest, kk_std_core_types__list acc, kk_context_t* _ctx) { /* forall<a> (rest : list<a>, acc : list<a>) -> list<a> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Nil(rest, _ctx)) {
    return acc;
  }
  {
    struct kk_std_core_types_Cons* _con_x484 = kk_std_core_types__as_Cons(rest, _ctx);
    kk_box_t x = _con_x484->head;
    kk_std_core_types__list xt = _con_x484->tail;
    kk_reuse_t _ru_x423 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(rest, _ctx)) {
      _ru_x423 = (kk_datatype_ptr_reuse(rest, _ctx));
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xt, _ctx);
      kk_datatype_ptr_decref(rest, _ctx);
    }
    { // tailcall
      kk_std_core_types__list _x_x485 = kk_std_core_types__new_Cons(_ru_x423, 0, x, acc, _ctx); /*list<10021>*/
      rest = xt;
      acc = _x_x485;
      goto kk__tailcall;
    }
  }
}
 
// Flatten a list of chunks into one list of values.

kk_std_core_types__list kk_nagare_core_pull__unroll_flattenChunks_10005(kk_std_core_types__list chunks, kk_context_t* _ctx) { /* forall<a> (chunks : list<nagare/core/types/chunk<a>>) -> list<a> */ 
  if (kk_std_core_types__is_Nil(chunks, _ctx)) {
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    struct kk_std_core_types_Cons* _con_x486 = kk_std_core_types__as_Cons(chunks, _ctx);
    kk_box_t _box_x56 = _con_x486->head;
    kk_std_core_types__list ct = _con_x486->tail;
    kk_nagare_core_types__chunk ch = kk_nagare_core_types__chunk_unbox(_box_x56, KK_BORROWED, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(chunks, _ctx)) {
      kk_nagare_core_types__chunk_dup(ch, _ctx);
      kk_box_drop(_box_x56, _ctx);
      kk_datatype_ptr_free(chunks, _ctx);
    }
    else {
      kk_nagare_core_types__chunk_dup(ch, _ctx);
      kk_std_core_types__list_dup(ct, _ctx);
      kk_datatype_ptr_decref(chunks, _ctx);
    }
    {
      kk_std_core_types__list values = ch.values;
      kk_std_core_types__list ys_10021 = kk_nagare_core_pull__unroll_flattenChunks_10005(ct, _ctx); /*list<650>*/;
      if (kk_std_core_types__is_Nil(values, _ctx)) {
        return ys_10021;
      }
      {
        kk_std_core_types__cctx _x_x487 = kk_cctx_empty(kk_context()); /*ctx<0>*/
        return kk_nagare_core_pull__trmc_unroll_listAppend_10000(values, ys_10021, _x_x487, _ctx);
      }
    }
  }
}
 
// lifted local: listChunkN, go

kk_std_core_types__list kk_nagare_core_pull__unroll_lift_listChunkN_2783_10006(kk_integer_t n, kk_std_core_types__list rest, kk_std_core_types__list curRev, kk_integer_t curLen, kk_std_core_types__list chunksRev, kk_context_t* _ctx) { /* forall<a> (n : int, rest : list<a>, curRev : list<a>, curLen : int, chunksRev : list<nagare/core/types/chunk<a>>) -> list<nagare/core/types/chunk<a>> */ 
  kk__tailcall: ;
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
      kk_nagare_core_types__chunk _b_x57_59;
      kk_std_core_types__list _x_x488;
      if (kk_std_core_types__is_Nil(curRev, _ctx)) {
        _x_x488 = kk_std_core_types__new_Nil(_ctx); /*forall<a> list<a>*/
      }
      else {
        _x_x488 = kk_nagare_core_pull__unroll_lift_listReverse_2782_10004(curRev, kk_std_core_types__new_Nil(_ctx), _ctx); /*forall<a> list<a>*/
      }
      _b_x57_59 = kk_nagare_core_types__new_Chunk(_x_x488, _ctx); /*nagare/core/types/chunk<825>*/
      kk_std_core_types__list xs_0_10023 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_nagare_core_types__chunk_box(_b_x57_59, _ctx), chunksRev, _ctx); /*list<nagare/core/types/chunk<825>>*/;
      if (kk_std_core_types__is_Nil(xs_0_10023, _ctx)) {
        return kk_std_core_types__new_Nil(_ctx);
      }
      {
        return kk_nagare_core_pull__unroll_lift_listReverse_2782_10004(xs_0_10023, kk_std_core_types__new_Nil(_ctx), _ctx);
      }
    }
  }
  {
    struct kk_std_core_types_Cons* _con_x489 = kk_std_core_types__as_Cons(rest, _ctx);
    kk_box_t x = _con_x489->head;
    kk_std_core_types__list xt = _con_x489->tail;
    kk_reuse_t _ru_x425 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(rest, _ctx)) {
      _ru_x425 = (kk_datatype_ptr_reuse(rest, _ctx));
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xt, _ctx);
      kk_datatype_ptr_decref(rest, _ctx);
    }
    kk_std_core_types__list nextRev = kk_std_core_types__new_Cons(_ru_x425, 0, x, curRev, _ctx); /*list<825>*/;
    kk_integer_t nextLen = kk_integer_add_small_const(curLen, 1, _ctx); /*int*/;
    bool _match_x412 = kk_integer_gte_borrow(nextLen,n,kk_context()); /*bool*/;
    if (_match_x412) {
      kk_integer_drop(nextLen, _ctx);
      kk_nagare_core_types__chunk _b_x61_63;
      kk_std_core_types__list _x_x490;
      if (kk_std_core_types__is_Nil(nextRev, _ctx)) {
        _x_x490 = kk_std_core_types__new_Nil(_ctx); /*forall<a> list<a>*/
      }
      else {
        _x_x490 = kk_nagare_core_pull__unroll_lift_listReverse_2782_10004(nextRev, kk_std_core_types__new_Nil(_ctx), _ctx); /*forall<a> list<a>*/
      }
      _b_x61_63 = kk_nagare_core_types__new_Chunk(_x_x490, _ctx); /*nagare/core/types/chunk<825>*/
      { // tailcall
        kk_std_core_types__list _x_x491 = kk_std_core_types__new_Nil(_ctx); /*forall<a> list<a>*/
        kk_integer_t _x_x492 = kk_integer_from_small(0); /*int*/
        kk_std_core_types__list _x_x493 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_nagare_core_types__chunk_box(_b_x61_63, _ctx), chunksRev, _ctx); /*list<10021>*/
        rest = xt;
        curRev = _x_x491;
        curLen = _x_x492;
        chunksRev = _x_x493;
        goto kk__tailcall;
      }
    }
    { // tailcall
      rest = xt;
      curRev = nextRev;
      curLen = nextLen;
      goto kk__tailcall;
    }
  }
}
 
// Split a list into chunks of size n (last chunk may be smaller).

kk_std_core_types__list kk_nagare_core_pull_listChunkN(kk_std_core_types__list values, kk_integer_t n, kk_context_t* _ctx) { /* forall<a> (values : list<a>, n : int) -> list<nagare/core/types/chunk<a>> */ 
  bool _match_x411 = kk_integer_lte_borrow(n,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x411) {
    kk_std_core_types__list_drop(values, _ctx);
    kk_integer_drop(n, _ctx);
    return kk_std_core_types__new_Nil(_ctx);
  }
  if (kk_std_core_types__is_Nil(values, _ctx)) {
    kk_integer_drop(n, _ctx);
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    return kk_nagare_core_pull__unroll_lift_listChunkN_2783_10006(n, values, kk_std_core_types__new_Nil(_ctx), kk_integer_from_small(0), kk_std_core_types__new_Nil(_ctx), _ctx);
  }
}
 
// monadic lift

kk_nagare_core_types__pull kk_nagare_core_pull__mlift_trmc_unroll_pullAppend_10007_10312(kk_function_t right, kk_nagare_core_types__pull _y_x10264, kk_context_t* _ctx) { /* forall<a,e> (right : () -> nagare/core/types/pull<a,e>, nagare/core/types/pull<a,e>) -> e nagare/core/types/pull<a,e> */ 
  return kk_nagare_core_pull__unroll_pullAppend_10007(_y_x10264, right, _ctx);
}
 
// Sequence two pulls, evaluating the right pull only when the left is done.


// lift anonymous function
struct kk_nagare_core_pull__trmc_unroll_pullAppend_10007_fun504__t {
  struct kk_function_s _base;
  kk_function_t next;
  kk_function_t right_0;
};
static kk_nagare_core_types__pull kk_nagare_core_pull__trmc_unroll_pullAppend_10007_fun504(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_pull__new_trmc_unroll_pullAppend_10007_fun504(kk_function_t next, kk_function_t right_0, kk_context_t* _ctx) {
  struct kk_nagare_core_pull__trmc_unroll_pullAppend_10007_fun504__t* _self = kk_function_alloc_as(struct kk_nagare_core_pull__trmc_unroll_pullAppend_10007_fun504__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_pull__trmc_unroll_pullAppend_10007_fun504, kk_context());
  _self->next = next;
  _self->right_0 = right_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_core_pull__trmc_unroll_pullAppend_10007_fun506__t {
  struct kk_function_s _base;
  kk_function_t right_0;
};
static kk_box_t kk_nagare_core_pull__trmc_unroll_pullAppend_10007_fun506(kk_function_t _fself, kk_box_t _b_x82, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_pull__new_trmc_unroll_pullAppend_10007_fun506(kk_function_t right_0, kk_context_t* _ctx) {
  struct kk_nagare_core_pull__trmc_unroll_pullAppend_10007_fun506__t* _self = kk_function_alloc_as(struct kk_nagare_core_pull__trmc_unroll_pullAppend_10007_fun506__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_pull__trmc_unroll_pullAppend_10007_fun506, kk_context());
  _self->right_0 = right_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_core_pull__trmc_unroll_pullAppend_10007_fun506(kk_function_t _fself, kk_box_t _b_x82, kk_context_t* _ctx) {
  struct kk_nagare_core_pull__trmc_unroll_pullAppend_10007_fun506__t* _self = kk_function_as(struct kk_nagare_core_pull__trmc_unroll_pullAppend_10007_fun506__t*, _fself, _ctx);
  kk_function_t right_0 = _self->right_0; /* () -> nagare/core/types/pull<1133,1134> */
  kk_drop_match(_self, {kk_function_dup(right_0, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull _y_x10264_0_108 = kk_nagare_core_types__pull_unbox(_b_x82, KK_OWNED, _ctx); /*nagare/core/types/pull<1133,1134>*/;
  kk_nagare_core_types__pull _x_x507 = kk_nagare_core_pull__mlift_trmc_unroll_pullAppend_10007_10312(right_0, _y_x10264_0_108, _ctx); /*nagare/core/types/pull<1133,1134>*/
  return kk_nagare_core_types__pull_box(_x_x507, _ctx);
}
static kk_nagare_core_types__pull kk_nagare_core_pull__trmc_unroll_pullAppend_10007_fun504(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_core_pull__trmc_unroll_pullAppend_10007_fun504__t* _self = kk_function_as(struct kk_nagare_core_pull__trmc_unroll_pullAppend_10007_fun504__t*, _fself, _ctx);
  kk_function_t next = _self->next; /* () -> 1134 nagare/core/types/pull<1133,1134> */
  kk_function_t right_0 = _self->right_0; /* () -> nagare/core/types/pull<1133,1134> */
  kk_drop_match(_self, {kk_function_dup(next, _ctx);kk_function_dup(right_0, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull x_10330 = kk_function_call(kk_nagare_core_types__pull, (kk_function_t, kk_context_t*), next, (next, _ctx), _ctx); /*nagare/core/types/pull<1133,1134>*/;
  if (kk_yielding(kk_context())) {
    kk_nagare_core_types__pull_drop(x_10330, _ctx);
    kk_box_t _x_x505 = kk_std_core_hnd_yield_extend(kk_nagare_core_pull__new_trmc_unroll_pullAppend_10007_fun506(right_0, _ctx), _ctx); /*10001*/
    return kk_nagare_core_types__pull_unbox(_x_x505, KK_OWNED, _ctx);
  }
  {
    return kk_nagare_core_pull__mlift_trmc_unroll_pullAppend_10007_10312(right_0, x_10330, _ctx);
  }
}

kk_nagare_core_types__pull kk_nagare_core_pull__trmc_unroll_pullAppend_10007(kk_nagare_core_types__pull left, kk_function_t right_0, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* forall<a,e> (left : nagare/core/types/pull<a,e>, right : () -> nagare/core/types/pull<a,e>, ctx<nagare/core/types/pull<a,e>>) -> nagare/core/types/pull<a,e> */ 
  kk__tailcall: ;
  if (kk_nagare_core_types__is_PDone(left, _ctx)) {
    kk_nagare_core_types__pull _b_x74_92 = kk_function_call(kk_nagare_core_types__pull, (kk_function_t, kk_context_t*), right_0, (right_0, _ctx), _ctx); /*nagare/core/types/pull<1133,1134>*/;
    kk_box_t _x_x497 = kk_cctx_apply_linear(_acc,(kk_nagare_core_types__pull_box(_b_x74_92, _ctx)),kk_context()); /*-1*/
    return kk_nagare_core_types__pull_unbox(_x_x497, KK_OWNED, _ctx);
  }
  if (kk_nagare_core_types__is_POutput(left, _ctx)) {
    struct kk_nagare_core_types_POutput* _con_x498 = kk_nagare_core_types__as_POutput(left, _ctx);
    kk_nagare_core_types__chunk out = _con_x498->out;
    kk_nagare_core_types__pull tail = _con_x498->tail;
    kk_reuse_t _ru_x426 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(left, _ctx)) {
      _ru_x426 = (kk_datatype_ptr_reuse(left, _ctx));
    }
    else {
      kk_nagare_core_types__chunk_dup(out, _ctx);
      kk_nagare_core_types__pull_dup(tail, _ctx);
      kk_datatype_ptr_decref(left, _ctx);
    }
    kk_nagare_core_types__pull _trmc_x10232 = kk_datatype_null(); /*nagare/core/types/pull<1133,1134>*/;
    kk_nagare_core_types__pull _trmc_x10233 = kk_nagare_core_types__new_POutput(_ru_x426, 0, out, _trmc_x10232, _ctx); /*nagare/core/types/pull<1133,1134>*/;
    kk_field_addr_t _b_x80_95 = kk_field_addr_create(&kk_nagare_core_types__as_POutput(_trmc_x10233, _ctx)->tail, _ctx); /*@field-addr<nagare/core/types/pull<1133,1134>>*/;
    { // tailcall
      kk_std_core_types__cctx _x_x499 = kk_cctx_extend_linear(_acc,(kk_nagare_core_types__pull_box(_trmc_x10233, _ctx)),_b_x80_95,kk_context()); /*ctx<0>*/
      left = tail;
      _acc = _x_x499;
      goto kk__tailcall;
    }
  }
  if (kk_nagare_core_types__is_PEval(left, _ctx)) {
    struct kk_nagare_core_types_PEval* _con_x500 = kk_nagare_core_types__as_PEval(left, _ctx);
    kk_function_t next = _con_x500->next;
    kk_reuse_t _ru_x427 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(left, _ctx)) {
      _ru_x427 = (kk_datatype_ptr_reuse(left, _ctx));
    }
    else {
      kk_function_dup(next, _ctx);
      kk_datatype_ptr_decref(left, _ctx);
    }
    kk_box_t _x_x501;
    kk_box_t _x_x502;
    kk_nagare_core_types__pull _x_x503 = kk_nagare_core_types__new_PEval(_ru_x427, 0, kk_nagare_core_pull__new_trmc_unroll_pullAppend_10007_fun504(next, right_0, _ctx), _ctx); /*nagare/core/types/pull<19,20>*/
    _x_x502 = kk_nagare_core_types__pull_box(_x_x503, _ctx); /*-1*/
    _x_x501 = kk_cctx_apply_linear(_acc,_x_x502,kk_context()); /*-1*/
    return kk_nagare_core_types__pull_unbox(_x_x501, KK_OWNED, _ctx);
  }
  {
    struct kk_nagare_core_types_PAcquire* _con_x508 = kk_nagare_core_types__as_PAcquire(left, _ctx);
    kk_function_t acquire = _con_x508->acquire;
    kk_function_t release = _con_x508->release;
    kk_nagare_core_types__pull tail_0 = _con_x508->tail;
    kk_reuse_t _ru_x428 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(left, _ctx)) {
      _ru_x428 = (kk_datatype_ptr_reuse(left, _ctx));
    }
    else {
      kk_function_dup(acquire, _ctx);
      kk_function_dup(release, _ctx);
      kk_nagare_core_types__pull_dup(tail_0, _ctx);
      kk_datatype_ptr_decref(left, _ctx);
    }
    kk_nagare_core_types__pull _trmc_x10234 = kk_datatype_null(); /*nagare/core/types/pull<1133,1134>*/;
    kk_nagare_core_types__pull _trmc_x10235 = kk_nagare_core_types__new_PAcquire(_ru_x428, 0, acquire, release, _trmc_x10234, _ctx); /*nagare/core/types/pull<1133,1134>*/;
    kk_field_addr_t _b_x90_104 = kk_field_addr_create(&kk_nagare_core_types__as_PAcquire(_trmc_x10235, _ctx)->tail, _ctx); /*@field-addr<nagare/core/types/pull<1133,1134>>*/;
    { // tailcall
      kk_std_core_types__cctx _x_x509 = kk_cctx_extend_linear(_acc,(kk_nagare_core_types__pull_box(_trmc_x10235, _ctx)),_b_x90_104,kk_context()); /*ctx<0>*/
      left = tail_0;
      _acc = _x_x509;
      goto kk__tailcall;
    }
  }
}
 
// Sequence two pulls, evaluating the right pull only when the left is done.

kk_nagare_core_types__pull kk_nagare_core_pull__unroll_pullAppend_10007(kk_nagare_core_types__pull left_0, kk_function_t right_1, kk_context_t* _ctx) { /* forall<a,e> (left : nagare/core/types/pull<a,e>, right : () -> nagare/core/types/pull<a,e>) -> nagare/core/types/pull<a,e> */ 
  kk_std_core_types__cctx _x_x510 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_nagare_core_pull__trmc_unroll_pullAppend_10007(left_0, right_1, _x_x510, _ctx);
}
 
// monadic lift

kk_nagare_core_types__pull kk_nagare_core_pull__mlift_trmc_unroll_pullMap_10008_10313(kk_function_t f, kk_nagare_core_types__pull _y_x10267, kk_context_t* _ctx) { /* forall<a,b,e> (f : (a) -> b, nagare/core/types/pull<a,e>) -> e nagare/core/types/pull<b,e> */ 
  return kk_nagare_core_pull__unroll_pullMap_10008(_y_x10267, f, _ctx);
}
 
// Map a function over all outputs of a pull (preserves eval/acquire structure).


// lift anonymous function
struct kk_nagare_core_pull__trmc_unroll_pullMap_10008_fun520__t {
  struct kk_function_s _base;
  kk_function_t f_0;
  kk_function_t next;
};
static kk_nagare_core_types__pull kk_nagare_core_pull__trmc_unroll_pullMap_10008_fun520(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_pull__new_trmc_unroll_pullMap_10008_fun520(kk_function_t f_0, kk_function_t next, kk_context_t* _ctx) {
  struct kk_nagare_core_pull__trmc_unroll_pullMap_10008_fun520__t* _self = kk_function_alloc_as(struct kk_nagare_core_pull__trmc_unroll_pullMap_10008_fun520__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_pull__trmc_unroll_pullMap_10008_fun520, kk_context());
  _self->f_0 = f_0;
  _self->next = next;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_core_pull__trmc_unroll_pullMap_10008_fun522__t {
  struct kk_function_s _base;
  kk_function_t f_0;
};
static kk_box_t kk_nagare_core_pull__trmc_unroll_pullMap_10008_fun522(kk_function_t _fself, kk_box_t _b_x118, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_pull__new_trmc_unroll_pullMap_10008_fun522(kk_function_t f_0, kk_context_t* _ctx) {
  struct kk_nagare_core_pull__trmc_unroll_pullMap_10008_fun522__t* _self = kk_function_alloc_as(struct kk_nagare_core_pull__trmc_unroll_pullMap_10008_fun522__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_pull__trmc_unroll_pullMap_10008_fun522, kk_context());
  _self->f_0 = f_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_core_pull__trmc_unroll_pullMap_10008_fun522(kk_function_t _fself, kk_box_t _b_x118, kk_context_t* _ctx) {
  struct kk_nagare_core_pull__trmc_unroll_pullMap_10008_fun522__t* _self = kk_function_as(struct kk_nagare_core_pull__trmc_unroll_pullMap_10008_fun522__t*, _fself, _ctx);
  kk_function_t f_0 = _self->f_0; /* (1290) -> 1291 */
  kk_drop_match(_self, {kk_function_dup(f_0, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull _y_x10267_0_144 = kk_nagare_core_types__pull_unbox(_b_x118, KK_OWNED, _ctx); /*nagare/core/types/pull<1290,1292>*/;
  kk_nagare_core_types__pull _x_x523 = kk_nagare_core_pull__mlift_trmc_unroll_pullMap_10008_10313(f_0, _y_x10267_0_144, _ctx); /*nagare/core/types/pull<1291,1292>*/
  return kk_nagare_core_types__pull_box(_x_x523, _ctx);
}
static kk_nagare_core_types__pull kk_nagare_core_pull__trmc_unroll_pullMap_10008_fun520(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_core_pull__trmc_unroll_pullMap_10008_fun520__t* _self = kk_function_as(struct kk_nagare_core_pull__trmc_unroll_pullMap_10008_fun520__t*, _fself, _ctx);
  kk_function_t f_0 = _self->f_0; /* (1290) -> 1291 */
  kk_function_t next = _self->next; /* () -> 1292 nagare/core/types/pull<1290,1292> */
  kk_drop_match(_self, {kk_function_dup(f_0, _ctx);kk_function_dup(next, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull x_10334 = kk_function_call(kk_nagare_core_types__pull, (kk_function_t, kk_context_t*), next, (next, _ctx), _ctx); /*nagare/core/types/pull<1290,1292>*/;
  if (kk_yielding(kk_context())) {
    kk_nagare_core_types__pull_drop(x_10334, _ctx);
    kk_box_t _x_x521 = kk_std_core_hnd_yield_extend(kk_nagare_core_pull__new_trmc_unroll_pullMap_10008_fun522(f_0, _ctx), _ctx); /*10001*/
    return kk_nagare_core_types__pull_unbox(_x_x521, KK_OWNED, _ctx);
  }
  {
    return kk_nagare_core_pull__mlift_trmc_unroll_pullMap_10008_10313(f_0, x_10334, _ctx);
  }
}

kk_nagare_core_types__pull kk_nagare_core_pull__trmc_unroll_pullMap_10008(kk_nagare_core_types__pull source, kk_function_t f_0, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* forall<a,b,e> (source : nagare/core/types/pull<a,e>, f : (a) -> b, ctx<nagare/core/types/pull<b,e>>) -> nagare/core/types/pull<b,e> */ 
  kk__tailcall: ;
  if (kk_nagare_core_types__is_PDone(source, _ctx)) {
    kk_function_drop(f_0, _ctx);
    kk_box_t _x_x512 = kk_cctx_apply_linear(_acc,(kk_nagare_core_types__pull_box(kk_nagare_core_types__new_PDone(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_nagare_core_types__pull_unbox(_x_x512, KK_OWNED, _ctx);
  }
  if (kk_nagare_core_types__is_POutput(source, _ctx)) {
    struct kk_nagare_core_types_POutput* _con_x513 = kk_nagare_core_types__as_POutput(source, _ctx);
    kk_nagare_core_types__chunk out = _con_x513->out;
    kk_nagare_core_types__pull tail = _con_x513->tail;
    kk_reuse_t _ru_x429 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(source, _ctx)) {
      _ru_x429 = (kk_datatype_ptr_reuse(source, _ctx));
    }
    else {
      kk_nagare_core_types__chunk_dup(out, _ctx);
      kk_nagare_core_types__pull_dup(tail, _ctx);
      kk_datatype_ptr_decref(source, _ctx);
    }
    kk_nagare_core_types__chunk _trmc_x10236;
    {
      kk_std_core_types__list values = out.values;
      kk_std_core_types__list _x_x514 = kk_std_core_list_map(values, f_0, _ctx); /*list<10002>*/
      _trmc_x10236 = kk_nagare_core_types__new_Chunk(_x_x514, _ctx); /*nagare/core/types/chunk<1291>*/
    }
    kk_nagare_core_types__pull _trmc_x10237 = kk_datatype_null(); /*nagare/core/types/pull<1291,1292>*/;
    kk_nagare_core_types__pull _trmc_x10238 = kk_nagare_core_types__new_POutput(_ru_x429, 0, _trmc_x10236, _trmc_x10237, _ctx); /*nagare/core/types/pull<1291,1292>*/;
    kk_field_addr_t _b_x116_131 = kk_field_addr_create(&kk_nagare_core_types__as_POutput(_trmc_x10238, _ctx)->tail, _ctx); /*@field-addr<nagare/core/types/pull<1291,1292>>*/;
    { // tailcall
      kk_std_core_types__cctx _x_x515 = kk_cctx_extend_linear(_acc,(kk_nagare_core_types__pull_box(_trmc_x10238, _ctx)),_b_x116_131,kk_context()); /*ctx<0>*/
      source = tail;
      _acc = _x_x515;
      goto kk__tailcall;
    }
  }
  if (kk_nagare_core_types__is_PEval(source, _ctx)) {
    struct kk_nagare_core_types_PEval* _con_x516 = kk_nagare_core_types__as_PEval(source, _ctx);
    kk_function_t next = _con_x516->next;
    kk_reuse_t _ru_x430 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(source, _ctx)) {
      _ru_x430 = (kk_datatype_ptr_reuse(source, _ctx));
    }
    else {
      kk_function_dup(next, _ctx);
      kk_datatype_ptr_decref(source, _ctx);
    }
    kk_box_t _x_x517;
    kk_box_t _x_x518;
    kk_nagare_core_types__pull _x_x519 = kk_nagare_core_types__new_PEval(_ru_x430, 0, kk_nagare_core_pull__new_trmc_unroll_pullMap_10008_fun520(f_0, next, _ctx), _ctx); /*nagare/core/types/pull<19,20>*/
    _x_x518 = kk_nagare_core_types__pull_box(_x_x519, _ctx); /*-1*/
    _x_x517 = kk_cctx_apply_linear(_acc,_x_x518,kk_context()); /*-1*/
    return kk_nagare_core_types__pull_unbox(_x_x517, KK_OWNED, _ctx);
  }
  {
    struct kk_nagare_core_types_PAcquire* _con_x524 = kk_nagare_core_types__as_PAcquire(source, _ctx);
    kk_function_t acquire = _con_x524->acquire;
    kk_function_t release = _con_x524->release;
    kk_nagare_core_types__pull tail_0 = _con_x524->tail;
    kk_reuse_t _ru_x431 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(source, _ctx)) {
      _ru_x431 = (kk_datatype_ptr_reuse(source, _ctx));
    }
    else {
      kk_function_dup(acquire, _ctx);
      kk_function_dup(release, _ctx);
      kk_nagare_core_types__pull_dup(tail_0, _ctx);
      kk_datatype_ptr_decref(source, _ctx);
    }
    kk_nagare_core_types__pull _trmc_x10239 = kk_datatype_null(); /*nagare/core/types/pull<1291,1292>*/;
    kk_nagare_core_types__pull _trmc_x10240 = kk_nagare_core_types__new_PAcquire(_ru_x431, 0, acquire, release, _trmc_x10239, _ctx); /*nagare/core/types/pull<1291,1292>*/;
    kk_field_addr_t _b_x126_140 = kk_field_addr_create(&kk_nagare_core_types__as_PAcquire(_trmc_x10240, _ctx)->tail, _ctx); /*@field-addr<nagare/core/types/pull<1291,1292>>*/;
    { // tailcall
      kk_std_core_types__cctx _x_x525 = kk_cctx_extend_linear(_acc,(kk_nagare_core_types__pull_box(_trmc_x10240, _ctx)),_b_x126_140,kk_context()); /*ctx<0>*/
      source = tail_0;
      _acc = _x_x525;
      goto kk__tailcall;
    }
  }
}
 
// Map a function over all outputs of a pull (preserves eval/acquire structure).

kk_nagare_core_types__pull kk_nagare_core_pull__unroll_pullMap_10008(kk_nagare_core_types__pull source_0, kk_function_t f_1, kk_context_t* _ctx) { /* forall<a,b,e> (source : nagare/core/types/pull<a,e>, f : (a) -> b) -> nagare/core/types/pull<b,e> */ 
  kk_std_core_types__cctx _x_x526 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_nagare_core_pull__trmc_unroll_pullMap_10008(source_0, f_1, _x_x526, _ctx);
}
 
// monadic lift

kk_nagare_core_types__pull kk_nagare_core_pull__mlift_trmc_unroll_pullFilter_10009_10314(kk_function_t pred, kk_nagare_core_types__pull _y_x10270, kk_context_t* _ctx) { /* forall<a,e> (pred : (a) -> bool, nagare/core/types/pull<a,e>) -> e nagare/core/types/pull<a,e> */ 
  return kk_nagare_core_pull__unroll_pullFilter_10009(_y_x10270, pred, _ctx);
}
 
// Filter outputs of a pull (preserves eval/acquire structure).


// lift anonymous function
struct kk_nagare_core_pull__trmc_unroll_pullFilter_10009_fun537__t {
  struct kk_function_s _base;
  kk_function_t next;
  kk_function_t pred_0;
};
static kk_nagare_core_types__pull kk_nagare_core_pull__trmc_unroll_pullFilter_10009_fun537(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_pull__new_trmc_unroll_pullFilter_10009_fun537(kk_function_t next, kk_function_t pred_0, kk_context_t* _ctx) {
  struct kk_nagare_core_pull__trmc_unroll_pullFilter_10009_fun537__t* _self = kk_function_alloc_as(struct kk_nagare_core_pull__trmc_unroll_pullFilter_10009_fun537__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_pull__trmc_unroll_pullFilter_10009_fun537, kk_context());
  _self->next = next;
  _self->pred_0 = pred_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_core_pull__trmc_unroll_pullFilter_10009_fun539__t {
  struct kk_function_s _base;
  kk_function_t pred_0;
};
static kk_box_t kk_nagare_core_pull__trmc_unroll_pullFilter_10009_fun539(kk_function_t _fself, kk_box_t _b_x154, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_pull__new_trmc_unroll_pullFilter_10009_fun539(kk_function_t pred_0, kk_context_t* _ctx) {
  struct kk_nagare_core_pull__trmc_unroll_pullFilter_10009_fun539__t* _self = kk_function_alloc_as(struct kk_nagare_core_pull__trmc_unroll_pullFilter_10009_fun539__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_pull__trmc_unroll_pullFilter_10009_fun539, kk_context());
  _self->pred_0 = pred_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_core_pull__trmc_unroll_pullFilter_10009_fun539(kk_function_t _fself, kk_box_t _b_x154, kk_context_t* _ctx) {
  struct kk_nagare_core_pull__trmc_unroll_pullFilter_10009_fun539__t* _self = kk_function_as(struct kk_nagare_core_pull__trmc_unroll_pullFilter_10009_fun539__t*, _fself, _ctx);
  kk_function_t pred_0 = _self->pred_0; /* (1434) -> bool */
  kk_drop_match(_self, {kk_function_dup(pred_0, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull _y_x10270_0_180 = kk_nagare_core_types__pull_unbox(_b_x154, KK_OWNED, _ctx); /*nagare/core/types/pull<1434,1435>*/;
  kk_nagare_core_types__pull _x_x540 = kk_nagare_core_pull__mlift_trmc_unroll_pullFilter_10009_10314(pred_0, _y_x10270_0_180, _ctx); /*nagare/core/types/pull<1434,1435>*/
  return kk_nagare_core_types__pull_box(_x_x540, _ctx);
}
static kk_nagare_core_types__pull kk_nagare_core_pull__trmc_unroll_pullFilter_10009_fun537(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_core_pull__trmc_unroll_pullFilter_10009_fun537__t* _self = kk_function_as(struct kk_nagare_core_pull__trmc_unroll_pullFilter_10009_fun537__t*, _fself, _ctx);
  kk_function_t next = _self->next; /* () -> 1435 nagare/core/types/pull<1434,1435> */
  kk_function_t pred_0 = _self->pred_0; /* (1434) -> bool */
  kk_drop_match(_self, {kk_function_dup(next, _ctx);kk_function_dup(pred_0, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull x_10338 = kk_function_call(kk_nagare_core_types__pull, (kk_function_t, kk_context_t*), next, (next, _ctx), _ctx); /*nagare/core/types/pull<1434,1435>*/;
  if (kk_yielding(kk_context())) {
    kk_nagare_core_types__pull_drop(x_10338, _ctx);
    kk_box_t _x_x538 = kk_std_core_hnd_yield_extend(kk_nagare_core_pull__new_trmc_unroll_pullFilter_10009_fun539(pred_0, _ctx), _ctx); /*10001*/
    return kk_nagare_core_types__pull_unbox(_x_x538, KK_OWNED, _ctx);
  }
  {
    return kk_nagare_core_pull__mlift_trmc_unroll_pullFilter_10009_10314(pred_0, x_10338, _ctx);
  }
}

kk_nagare_core_types__pull kk_nagare_core_pull__trmc_unroll_pullFilter_10009(kk_nagare_core_types__pull source, kk_function_t pred_0, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* forall<a,e> (source : nagare/core/types/pull<a,e>, pred : (a) -> bool, ctx<nagare/core/types/pull<a,e>>) -> nagare/core/types/pull<a,e> */ 
  kk__tailcall: ;
  if (kk_nagare_core_types__is_PDone(source, _ctx)) {
    kk_function_drop(pred_0, _ctx);
    kk_box_t _x_x528 = kk_cctx_apply_linear(_acc,(kk_nagare_core_types__pull_box(kk_nagare_core_types__new_PDone(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_nagare_core_types__pull_unbox(_x_x528, KK_OWNED, _ctx);
  }
  if (kk_nagare_core_types__is_POutput(source, _ctx)) {
    struct kk_nagare_core_types_POutput* _con_x529 = kk_nagare_core_types__as_POutput(source, _ctx);
    kk_nagare_core_types__chunk out = _con_x529->out;
    kk_nagare_core_types__pull tail = _con_x529->tail;
    kk_reuse_t _ru_x432 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(source, _ctx)) {
      _ru_x432 = (kk_datatype_ptr_reuse(source, _ctx));
    }
    else {
      kk_nagare_core_types__chunk_dup(out, _ctx);
      kk_nagare_core_types__pull_dup(tail, _ctx);
      kk_datatype_ptr_decref(source, _ctx);
    }
    kk_nagare_core_types__chunk _trmc_x10241;
    {
      kk_std_core_types__list values = out.values;
      kk_std_core_types__list _x_x530;
      kk_function_t _x_x531 = kk_function_dup(pred_0, _ctx); /*(1434) -> bool*/
      _x_x530 = kk_std_core_list_filter(values, _x_x531, _ctx); /*list<10001>*/
      _trmc_x10241 = kk_nagare_core_types__new_Chunk(_x_x530, _ctx); /*nagare/core/types/chunk<1434>*/
    }
    kk_nagare_core_types__pull _trmc_x10242 = kk_datatype_null(); /*nagare/core/types/pull<1434,1435>*/;
    kk_nagare_core_types__pull _trmc_x10243 = kk_nagare_core_types__new_POutput(_ru_x432, 0, _trmc_x10241, _trmc_x10242, _ctx); /*nagare/core/types/pull<1434,1435>*/;
    kk_field_addr_t _b_x152_167 = kk_field_addr_create(&kk_nagare_core_types__as_POutput(_trmc_x10243, _ctx)->tail, _ctx); /*@field-addr<nagare/core/types/pull<1434,1435>>*/;
    { // tailcall
      kk_std_core_types__cctx _x_x532 = kk_cctx_extend_linear(_acc,(kk_nagare_core_types__pull_box(_trmc_x10243, _ctx)),_b_x152_167,kk_context()); /*ctx<0>*/
      source = tail;
      _acc = _x_x532;
      goto kk__tailcall;
    }
  }
  if (kk_nagare_core_types__is_PEval(source, _ctx)) {
    struct kk_nagare_core_types_PEval* _con_x533 = kk_nagare_core_types__as_PEval(source, _ctx);
    kk_function_t next = _con_x533->next;
    kk_reuse_t _ru_x433 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(source, _ctx)) {
      _ru_x433 = (kk_datatype_ptr_reuse(source, _ctx));
    }
    else {
      kk_function_dup(next, _ctx);
      kk_datatype_ptr_decref(source, _ctx);
    }
    kk_box_t _x_x534;
    kk_box_t _x_x535;
    kk_nagare_core_types__pull _x_x536 = kk_nagare_core_types__new_PEval(_ru_x433, 0, kk_nagare_core_pull__new_trmc_unroll_pullFilter_10009_fun537(next, pred_0, _ctx), _ctx); /*nagare/core/types/pull<19,20>*/
    _x_x535 = kk_nagare_core_types__pull_box(_x_x536, _ctx); /*-1*/
    _x_x534 = kk_cctx_apply_linear(_acc,_x_x535,kk_context()); /*-1*/
    return kk_nagare_core_types__pull_unbox(_x_x534, KK_OWNED, _ctx);
  }
  {
    struct kk_nagare_core_types_PAcquire* _con_x541 = kk_nagare_core_types__as_PAcquire(source, _ctx);
    kk_function_t acquire = _con_x541->acquire;
    kk_function_t release = _con_x541->release;
    kk_nagare_core_types__pull tail_0 = _con_x541->tail;
    kk_reuse_t _ru_x434 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(source, _ctx)) {
      _ru_x434 = (kk_datatype_ptr_reuse(source, _ctx));
    }
    else {
      kk_function_dup(acquire, _ctx);
      kk_function_dup(release, _ctx);
      kk_nagare_core_types__pull_dup(tail_0, _ctx);
      kk_datatype_ptr_decref(source, _ctx);
    }
    kk_nagare_core_types__pull _trmc_x10244 = kk_datatype_null(); /*nagare/core/types/pull<1434,1435>*/;
    kk_nagare_core_types__pull _trmc_x10245 = kk_nagare_core_types__new_PAcquire(_ru_x434, 0, acquire, release, _trmc_x10244, _ctx); /*nagare/core/types/pull<1434,1435>*/;
    kk_field_addr_t _b_x162_176 = kk_field_addr_create(&kk_nagare_core_types__as_PAcquire(_trmc_x10245, _ctx)->tail, _ctx); /*@field-addr<nagare/core/types/pull<1434,1435>>*/;
    { // tailcall
      kk_std_core_types__cctx _x_x542 = kk_cctx_extend_linear(_acc,(kk_nagare_core_types__pull_box(_trmc_x10245, _ctx)),_b_x162_176,kk_context()); /*ctx<0>*/
      source = tail_0;
      _acc = _x_x542;
      goto kk__tailcall;
    }
  }
}
 
// Filter outputs of a pull (preserves eval/acquire structure).

kk_nagare_core_types__pull kk_nagare_core_pull__unroll_pullFilter_10009(kk_nagare_core_types__pull source_0, kk_function_t pred_1, kk_context_t* _ctx) { /* forall<a,e> (source : nagare/core/types/pull<a,e>, pred : (a) -> bool) -> nagare/core/types/pull<a,e> */ 
  kk_std_core_types__cctx _x_x543 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_nagare_core_pull__trmc_unroll_pullFilter_10009(source_0, pred_1, _x_x543, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_nagare_core_pull__mlift_lift_unroll_flatMapChunk_10010_10220_10315_fun545__t {
  struct kk_function_s _base;
  kk_function_t f;
  kk_std_core_types__list xt;
};
static kk_nagare_core_types__pull kk_nagare_core_pull__mlift_lift_unroll_flatMapChunk_10010_10220_10315_fun545(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_pull__new_mlift_lift_unroll_flatMapChunk_10010_10220_10315_fun545(kk_function_t f, kk_std_core_types__list xt, kk_context_t* _ctx) {
  struct kk_nagare_core_pull__mlift_lift_unroll_flatMapChunk_10010_10220_10315_fun545__t* _self = kk_function_alloc_as(struct kk_nagare_core_pull__mlift_lift_unroll_flatMapChunk_10010_10220_10315_fun545__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_pull__mlift_lift_unroll_flatMapChunk_10010_10220_10315_fun545, kk_context());
  _self->f = f;
  _self->xt = xt;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_nagare_core_types__pull kk_nagare_core_pull__mlift_lift_unroll_flatMapChunk_10010_10220_10315_fun545(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_core_pull__mlift_lift_unroll_flatMapChunk_10010_10220_10315_fun545__t* _self = kk_function_as(struct kk_nagare_core_pull__mlift_lift_unroll_flatMapChunk_10010_10220_10315_fun545__t*, _fself, _ctx);
  kk_function_t f = _self->f; /* (1509) -> nagare/core/types/pull<1510,1511> */
  kk_std_core_types__list xt = _self->xt; /* list<1509> */
  kk_drop_match(_self, {kk_function_dup(f, _ctx);kk_std_core_types__list_dup(xt, _ctx);}, {}, _ctx)
  return kk_nagare_core_pull__unroll_flatMapChunk_10010(xt, f, _ctx);
}

kk_nagare_core_types__pull kk_nagare_core_pull__mlift_lift_unroll_flatMapChunk_10010_10220_10315(kk_function_t f, kk_std_core_types__list xt, kk_nagare_core_types__pull _y_x10273, kk_context_t* _ctx) { /* forall<a,b,e> (f : (a) -> nagare/core/types/pull<b,e>, xt : list<a>, nagare/core/types/pull<b,e>) -> e nagare/core/types/pull<b,e> */ 
  kk_std_core_types__cctx _x_x546 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_nagare_core_pull__trmc_unroll_pullAppend_10007(_y_x10273, kk_nagare_core_pull__new_mlift_lift_unroll_flatMapChunk_10010_10220_10315_fun545(f, xt, _ctx), _x_x546, _ctx);
}
 
// lifted local: @unroll-flatMapChunk@10010, @spec-x10206
// specialized: nagare/core/pull/@unroll-pullAppend@10007, on parameters @uniq-right@10195, using:
// @uniq-right@10195 = fn(){
//   nagare/core/pull/@unroll-flatMapChunk@10010<a,a,(e :: E)>(xt, f);
// }


// lift anonymous function
struct kk_nagare_core_pull__lift_unroll_flatMapChunk_10010_10220_fun550__t {
  struct kk_function_s _base;
  kk_function_t _uniq_next_10201;
  kk_function_t f_0;
  kk_std_core_types__list xt_0;
};
static kk_nagare_core_types__pull kk_nagare_core_pull__lift_unroll_flatMapChunk_10010_10220_fun550(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_pull__new_lift_unroll_flatMapChunk_10010_10220_fun550(kk_function_t _uniq_next_10201, kk_function_t f_0, kk_std_core_types__list xt_0, kk_context_t* _ctx) {
  struct kk_nagare_core_pull__lift_unroll_flatMapChunk_10010_10220_fun550__t* _self = kk_function_alloc_as(struct kk_nagare_core_pull__lift_unroll_flatMapChunk_10010_10220_fun550__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_pull__lift_unroll_flatMapChunk_10010_10220_fun550, kk_context());
  _self->_uniq_next_10201 = _uniq_next_10201;
  _self->f_0 = f_0;
  _self->xt_0 = xt_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_core_pull__lift_unroll_flatMapChunk_10010_10220_fun552__t {
  struct kk_function_s _base;
  kk_function_t f_0;
  kk_std_core_types__list xt_0;
};
static kk_box_t kk_nagare_core_pull__lift_unroll_flatMapChunk_10010_10220_fun552(kk_function_t _fself, kk_box_t _b_x182, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_pull__new_lift_unroll_flatMapChunk_10010_10220_fun552(kk_function_t f_0, kk_std_core_types__list xt_0, kk_context_t* _ctx) {
  struct kk_nagare_core_pull__lift_unroll_flatMapChunk_10010_10220_fun552__t* _self = kk_function_alloc_as(struct kk_nagare_core_pull__lift_unroll_flatMapChunk_10010_10220_fun552__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_pull__lift_unroll_flatMapChunk_10010_10220_fun552, kk_context());
  _self->f_0 = f_0;
  _self->xt_0 = xt_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_core_pull__lift_unroll_flatMapChunk_10010_10220_fun552(kk_function_t _fself, kk_box_t _b_x182, kk_context_t* _ctx) {
  struct kk_nagare_core_pull__lift_unroll_flatMapChunk_10010_10220_fun552__t* _self = kk_function_as(struct kk_nagare_core_pull__lift_unroll_flatMapChunk_10010_10220_fun552__t*, _fself, _ctx);
  kk_function_t f_0 = _self->f_0; /* (1509) -> nagare/core/types/pull<1510,1511> */
  kk_std_core_types__list xt_0 = _self->xt_0; /* list<1509> */
  kk_drop_match(_self, {kk_function_dup(f_0, _ctx);kk_std_core_types__list_dup(xt_0, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull _y_x10273_0_184 = kk_nagare_core_types__pull_unbox(_b_x182, KK_OWNED, _ctx); /*nagare/core/types/pull<1510,1511>*/;
  kk_nagare_core_types__pull _x_x553 = kk_nagare_core_pull__mlift_lift_unroll_flatMapChunk_10010_10220_10315(f_0, xt_0, _y_x10273_0_184, _ctx); /*nagare/core/types/pull<1510,1511>*/
  return kk_nagare_core_types__pull_box(_x_x553, _ctx);
}
static kk_nagare_core_types__pull kk_nagare_core_pull__lift_unroll_flatMapChunk_10010_10220_fun550(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_core_pull__lift_unroll_flatMapChunk_10010_10220_fun550__t* _self = kk_function_as(struct kk_nagare_core_pull__lift_unroll_flatMapChunk_10010_10220_fun550__t*, _fself, _ctx);
  kk_function_t _uniq_next_10201 = _self->_uniq_next_10201; /* () -> 1511 nagare/core/types/pull<1510,1511> */
  kk_function_t f_0 = _self->f_0; /* (1509) -> nagare/core/types/pull<1510,1511> */
  kk_std_core_types__list xt_0 = _self->xt_0; /* list<1509> */
  kk_drop_match(_self, {kk_function_dup(_uniq_next_10201, _ctx);kk_function_dup(f_0, _ctx);kk_std_core_types__list_dup(xt_0, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull x_10344 = kk_function_call(kk_nagare_core_types__pull, (kk_function_t, kk_context_t*), _uniq_next_10201, (_uniq_next_10201, _ctx), _ctx); /*nagare/core/types/pull<1510,1511>*/;
  if (kk_yielding(kk_context())) {
    kk_nagare_core_types__pull_drop(x_10344, _ctx);
    kk_box_t _x_x551 = kk_std_core_hnd_yield_extend(kk_nagare_core_pull__new_lift_unroll_flatMapChunk_10010_10220_fun552(f_0, xt_0, _ctx), _ctx); /*10001*/
    return kk_nagare_core_types__pull_unbox(_x_x551, KK_OWNED, _ctx);
  }
  {
    return kk_nagare_core_pull__mlift_lift_unroll_flatMapChunk_10010_10220_10315(f_0, xt_0, x_10344, _ctx);
  }
}

kk_nagare_core_types__pull kk_nagare_core_pull__lift_unroll_flatMapChunk_10010_10220(kk_function_t f_0, kk_std_core_types__list xt_0, kk_nagare_core_types__pull _uniq_left_10194, kk_context_t* _ctx) { /* forall<a,b,e> (f : (a) -> nagare/core/types/pull<b,e>, xt : list<a>, nagare/core/types/pull<b,e>) -> nagare/core/types/pull<b,e> */ 
  if (kk_nagare_core_types__is_PDone(_uniq_left_10194, _ctx)) {
    return kk_nagare_core_pull__unroll_flatMapChunk_10010(xt_0, f_0, _ctx);
  }
  if (kk_nagare_core_types__is_POutput(_uniq_left_10194, _ctx)) {
    struct kk_nagare_core_types_POutput* _con_x547 = kk_nagare_core_types__as_POutput(_uniq_left_10194, _ctx);
    kk_nagare_core_types__chunk _uniq_out_10198 = _con_x547->out;
    kk_nagare_core_types__pull _uniq_tail_10199 = _con_x547->tail;
    kk_reuse_t _ru_x435 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_left_10194, _ctx)) {
      _ru_x435 = (kk_datatype_ptr_reuse(_uniq_left_10194, _ctx));
    }
    else {
      kk_nagare_core_types__chunk_dup(_uniq_out_10198, _ctx);
      kk_nagare_core_types__pull_dup(_uniq_tail_10199, _ctx);
      kk_datatype_ptr_decref(_uniq_left_10194, _ctx);
    }
    kk_nagare_core_types__pull _x_x548 = kk_nagare_core_pull__lift_unroll_flatMapChunk_10010_10220(f_0, xt_0, _uniq_tail_10199, _ctx); /*nagare/core/types/pull<1510,1511>*/
    return kk_nagare_core_types__new_POutput(_ru_x435, 0, _uniq_out_10198, _x_x548, _ctx);
  }
  if (kk_nagare_core_types__is_PEval(_uniq_left_10194, _ctx)) {
    struct kk_nagare_core_types_PEval* _con_x549 = kk_nagare_core_types__as_PEval(_uniq_left_10194, _ctx);
    kk_function_t _uniq_next_10201 = _con_x549->next;
    kk_reuse_t _ru_x436 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_left_10194, _ctx)) {
      _ru_x436 = (kk_datatype_ptr_reuse(_uniq_left_10194, _ctx));
    }
    else {
      kk_function_dup(_uniq_next_10201, _ctx);
      kk_datatype_ptr_decref(_uniq_left_10194, _ctx);
    }
    return kk_nagare_core_types__new_PEval(_ru_x436, 0, kk_nagare_core_pull__new_lift_unroll_flatMapChunk_10010_10220_fun550(_uniq_next_10201, f_0, xt_0, _ctx), _ctx);
  }
  {
    struct kk_nagare_core_types_PAcquire* _con_x554 = kk_nagare_core_types__as_PAcquire(_uniq_left_10194, _ctx);
    kk_function_t _uniq_acquire_10203 = _con_x554->acquire;
    kk_function_t _uniq_release_10204 = _con_x554->release;
    kk_nagare_core_types__pull _uniq_tail_0_10205 = _con_x554->tail;
    kk_reuse_t _ru_x437 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_left_10194, _ctx)) {
      _ru_x437 = (kk_datatype_ptr_reuse(_uniq_left_10194, _ctx));
    }
    else {
      kk_function_dup(_uniq_acquire_10203, _ctx);
      kk_function_dup(_uniq_release_10204, _ctx);
      kk_nagare_core_types__pull_dup(_uniq_tail_0_10205, _ctx);
      kk_datatype_ptr_decref(_uniq_left_10194, _ctx);
    }
    kk_nagare_core_types__pull _x_x555 = kk_nagare_core_pull__lift_unroll_flatMapChunk_10010_10220(f_0, xt_0, _uniq_tail_0_10205, _ctx); /*nagare/core/types/pull<1510,1511>*/
    return kk_nagare_core_types__new_PAcquire(_ru_x437, 0, _uniq_acquire_10203, _uniq_release_10204, _x_x555, _ctx);
  }
}
 
// FlatMap a list of values into pulls and concatenate results.

kk_nagare_core_types__pull kk_nagare_core_pull__unroll_flatMapChunk_10010(kk_std_core_types__list values, kk_function_t f_1, kk_context_t* _ctx) { /* forall<a,b,e> (values : list<a>, f : (a) -> nagare/core/types/pull<b,e>) -> nagare/core/types/pull<b,e> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Nil(values, _ctx)) {
    kk_function_drop(f_1, _ctx);
    return kk_nagare_core_types__new_PDone(_ctx);
  }
  {
    struct kk_std_core_types_Cons* _con_x556 = kk_std_core_types__as_Cons(values, _ctx);
    kk_box_t x_0 = _con_x556->head;
    kk_std_core_types__list xt_1 = _con_x556->tail;
    if kk_likely(kk_datatype_ptr_is_unique(values, _ctx)) {
      kk_datatype_ptr_free(values, _ctx);
    }
    else {
      kk_box_dup(x_0, _ctx);
      kk_std_core_types__list_dup(xt_1, _ctx);
      kk_datatype_ptr_decref(values, _ctx);
    }
    kk_nagare_core_types__pull left_10055;
    kk_function_t _x_x557 = kk_function_dup(f_1, _ctx); /*(1509) -> nagare/core/types/pull<1510,1511>*/
    left_10055 = kk_function_call(kk_nagare_core_types__pull, (kk_function_t, kk_box_t, kk_context_t*), _x_x557, (_x_x557, x_0, _ctx), _ctx); /*nagare/core/types/pull<1510,1511>*/
    if (kk_nagare_core_types__is_PDone(left_10055, _ctx)) { // tailcall
                                                            values = xt_1;
                                                            goto kk__tailcall;
    }
    {
      return kk_nagare_core_pull__lift_unroll_flatMapChunk_10010_10220(f_1, xt_1, left_10055, _ctx);
    }
  }
}
 
// monadic lift


// lift anonymous function
struct kk_nagare_core_pull__mlift_lift_unroll_pullFlatMap_10011_10221_10316_fun558__t {
  struct kk_function_s _base;
  kk_function_t f;
  kk_nagare_core_types__pull tail;
};
static kk_nagare_core_types__pull kk_nagare_core_pull__mlift_lift_unroll_pullFlatMap_10011_10221_10316_fun558(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_pull__new_mlift_lift_unroll_pullFlatMap_10011_10221_10316_fun558(kk_function_t f, kk_nagare_core_types__pull tail, kk_context_t* _ctx) {
  struct kk_nagare_core_pull__mlift_lift_unroll_pullFlatMap_10011_10221_10316_fun558__t* _self = kk_function_alloc_as(struct kk_nagare_core_pull__mlift_lift_unroll_pullFlatMap_10011_10221_10316_fun558__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_pull__mlift_lift_unroll_pullFlatMap_10011_10221_10316_fun558, kk_context());
  _self->f = f;
  _self->tail = tail;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_nagare_core_types__pull kk_nagare_core_pull__mlift_lift_unroll_pullFlatMap_10011_10221_10316_fun558(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_core_pull__mlift_lift_unroll_pullFlatMap_10011_10221_10316_fun558__t* _self = kk_function_as(struct kk_nagare_core_pull__mlift_lift_unroll_pullFlatMap_10011_10221_10316_fun558__t*, _fself, _ctx);
  kk_function_t f = _self->f; /* (1681) -> nagare/core/types/pull<1682,1683> */
  kk_nagare_core_types__pull tail = _self->tail; /* nagare/core/types/pull<1681,1683> */
  kk_drop_match(_self, {kk_function_dup(f, _ctx);kk_nagare_core_types__pull_dup(tail, _ctx);}, {}, _ctx)
  return kk_nagare_core_pull__unroll_pullFlatMap_10011(tail, f, _ctx);
}

kk_nagare_core_types__pull kk_nagare_core_pull__mlift_lift_unroll_pullFlatMap_10011_10221_10316(kk_function_t f, kk_nagare_core_types__pull tail, kk_nagare_core_types__pull _y_x10278, kk_context_t* _ctx) { /* forall<a,b,e> (f : (a) -> nagare/core/types/pull<b,e>, tail : nagare/core/types/pull<a,e>, nagare/core/types/pull<b,e>) -> e nagare/core/types/pull<b,e> */ 
  kk_std_core_types__cctx _x_x559 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_nagare_core_pull__trmc_unroll_pullAppend_10007(_y_x10278, kk_nagare_core_pull__new_mlift_lift_unroll_pullFlatMap_10011_10221_10316_fun558(f, tail, _ctx), _x_x559, _ctx);
}
 
// monadic lift

kk_nagare_core_types__pull kk_nagare_core_pull__mlift_unroll_pullFlatMap_10011_10317(kk_function_t f_0, kk_nagare_core_types__pull tail_0, kk_nagare_core_types__pull _c_x10280, kk_context_t* _ctx) { /* forall<a,b,e> (f : (a) -> nagare/core/types/pull<b,e>, tail : nagare/core/types/pull<a,e>, nagare/core/types/pull<b,e>) -> nagare/core/types/pull<b,e> */ 
  if (kk_nagare_core_types__is_PDone(_c_x10280, _ctx)) {
    return kk_nagare_core_pull__unroll_pullFlatMap_10011(tail_0, f_0, _ctx);
  }
  {
    return kk_nagare_core_pull__lift_unroll_pullFlatMap_10011_10221(f_0, tail_0, _c_x10280, _ctx);
  }
}
 
// monadic lift

kk_nagare_core_types__pull kk_nagare_core_pull__mlift_unroll_pullFlatMap_10011_10318(kk_function_t f_1, kk_nagare_core_types__pull _y_x10283, kk_context_t* _ctx) { /* forall<a,b,e> (f : (a) -> nagare/core/types/pull<b,e>, nagare/core/types/pull<a,e>) -> e nagare/core/types/pull<b,e> */ 
  return kk_nagare_core_pull__unroll_pullFlatMap_10011(_y_x10283, f_1, _ctx);
}
 
// lifted local: @unroll-pullFlatMap@10011, @spec-x10219
// specialized: nagare/core/pull/@unroll-pullAppend@10007, on parameters @uniq-right@10208, using:
// @uniq-right@10208 = fn(){
//   nagare/core/pull/@unroll-pullFlatMap@10011<a,a,(e :: E)>(tail, f);
// }


// lift anonymous function
struct kk_nagare_core_pull__lift_unroll_pullFlatMap_10011_10221_fun563__t {
  struct kk_function_s _base;
  kk_function_t _uniq_next_10214;
  kk_function_t f_2;
  kk_nagare_core_types__pull tail_1;
};
static kk_nagare_core_types__pull kk_nagare_core_pull__lift_unroll_pullFlatMap_10011_10221_fun563(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_pull__new_lift_unroll_pullFlatMap_10011_10221_fun563(kk_function_t _uniq_next_10214, kk_function_t f_2, kk_nagare_core_types__pull tail_1, kk_context_t* _ctx) {
  struct kk_nagare_core_pull__lift_unroll_pullFlatMap_10011_10221_fun563__t* _self = kk_function_alloc_as(struct kk_nagare_core_pull__lift_unroll_pullFlatMap_10011_10221_fun563__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_pull__lift_unroll_pullFlatMap_10011_10221_fun563, kk_context());
  _self->_uniq_next_10214 = _uniq_next_10214;
  _self->f_2 = f_2;
  _self->tail_1 = tail_1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_core_pull__lift_unroll_pullFlatMap_10011_10221_fun565__t {
  struct kk_function_s _base;
  kk_function_t f_2;
  kk_nagare_core_types__pull tail_1;
};
static kk_box_t kk_nagare_core_pull__lift_unroll_pullFlatMap_10011_10221_fun565(kk_function_t _fself, kk_box_t _b_x186, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_pull__new_lift_unroll_pullFlatMap_10011_10221_fun565(kk_function_t f_2, kk_nagare_core_types__pull tail_1, kk_context_t* _ctx) {
  struct kk_nagare_core_pull__lift_unroll_pullFlatMap_10011_10221_fun565__t* _self = kk_function_alloc_as(struct kk_nagare_core_pull__lift_unroll_pullFlatMap_10011_10221_fun565__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_pull__lift_unroll_pullFlatMap_10011_10221_fun565, kk_context());
  _self->f_2 = f_2;
  _self->tail_1 = tail_1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_core_pull__lift_unroll_pullFlatMap_10011_10221_fun565(kk_function_t _fself, kk_box_t _b_x186, kk_context_t* _ctx) {
  struct kk_nagare_core_pull__lift_unroll_pullFlatMap_10011_10221_fun565__t* _self = kk_function_as(struct kk_nagare_core_pull__lift_unroll_pullFlatMap_10011_10221_fun565__t*, _fself, _ctx);
  kk_function_t f_2 = _self->f_2; /* (1681) -> nagare/core/types/pull<1682,1683> */
  kk_nagare_core_types__pull tail_1 = _self->tail_1; /* nagare/core/types/pull<1681,1683> */
  kk_drop_match(_self, {kk_function_dup(f_2, _ctx);kk_nagare_core_types__pull_dup(tail_1, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull _y_x10278_0_188 = kk_nagare_core_types__pull_unbox(_b_x186, KK_OWNED, _ctx); /*nagare/core/types/pull<1682,1683>*/;
  kk_nagare_core_types__pull _x_x566 = kk_nagare_core_pull__mlift_lift_unroll_pullFlatMap_10011_10221_10316(f_2, tail_1, _y_x10278_0_188, _ctx); /*nagare/core/types/pull<1682,1683>*/
  return kk_nagare_core_types__pull_box(_x_x566, _ctx);
}
static kk_nagare_core_types__pull kk_nagare_core_pull__lift_unroll_pullFlatMap_10011_10221_fun563(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_core_pull__lift_unroll_pullFlatMap_10011_10221_fun563__t* _self = kk_function_as(struct kk_nagare_core_pull__lift_unroll_pullFlatMap_10011_10221_fun563__t*, _fself, _ctx);
  kk_function_t _uniq_next_10214 = _self->_uniq_next_10214; /* () -> 1683 nagare/core/types/pull<1682,1683> */
  kk_function_t f_2 = _self->f_2; /* (1681) -> nagare/core/types/pull<1682,1683> */
  kk_nagare_core_types__pull tail_1 = _self->tail_1; /* nagare/core/types/pull<1681,1683> */
  kk_drop_match(_self, {kk_function_dup(_uniq_next_10214, _ctx);kk_function_dup(f_2, _ctx);kk_nagare_core_types__pull_dup(tail_1, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull x_10348 = kk_function_call(kk_nagare_core_types__pull, (kk_function_t, kk_context_t*), _uniq_next_10214, (_uniq_next_10214, _ctx), _ctx); /*nagare/core/types/pull<1682,1683>*/;
  if (kk_yielding(kk_context())) {
    kk_nagare_core_types__pull_drop(x_10348, _ctx);
    kk_box_t _x_x564 = kk_std_core_hnd_yield_extend(kk_nagare_core_pull__new_lift_unroll_pullFlatMap_10011_10221_fun565(f_2, tail_1, _ctx), _ctx); /*10001*/
    return kk_nagare_core_types__pull_unbox(_x_x564, KK_OWNED, _ctx);
  }
  {
    return kk_nagare_core_pull__mlift_lift_unroll_pullFlatMap_10011_10221_10316(f_2, tail_1, x_10348, _ctx);
  }
}

kk_nagare_core_types__pull kk_nagare_core_pull__lift_unroll_pullFlatMap_10011_10221(kk_function_t f_2, kk_nagare_core_types__pull tail_1, kk_nagare_core_types__pull _uniq_left_10207, kk_context_t* _ctx) { /* forall<a,b,e> (f : (a) -> nagare/core/types/pull<b,e>, tail : nagare/core/types/pull<a,e>, nagare/core/types/pull<b,e>) -> nagare/core/types/pull<b,e> */ 
  if (kk_nagare_core_types__is_PDone(_uniq_left_10207, _ctx)) {
    return kk_nagare_core_pull__unroll_pullFlatMap_10011(tail_1, f_2, _ctx);
  }
  if (kk_nagare_core_types__is_POutput(_uniq_left_10207, _ctx)) {
    struct kk_nagare_core_types_POutput* _con_x560 = kk_nagare_core_types__as_POutput(_uniq_left_10207, _ctx);
    kk_nagare_core_types__chunk _uniq_out_10211 = _con_x560->out;
    kk_nagare_core_types__pull _uniq_tail_10212 = _con_x560->tail;
    kk_reuse_t _ru_x439 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_left_10207, _ctx)) {
      _ru_x439 = (kk_datatype_ptr_reuse(_uniq_left_10207, _ctx));
    }
    else {
      kk_nagare_core_types__chunk_dup(_uniq_out_10211, _ctx);
      kk_nagare_core_types__pull_dup(_uniq_tail_10212, _ctx);
      kk_datatype_ptr_decref(_uniq_left_10207, _ctx);
    }
    kk_nagare_core_types__pull _x_x561 = kk_nagare_core_pull__lift_unroll_pullFlatMap_10011_10221(f_2, tail_1, _uniq_tail_10212, _ctx); /*nagare/core/types/pull<1682,1683>*/
    return kk_nagare_core_types__new_POutput(_ru_x439, 0, _uniq_out_10211, _x_x561, _ctx);
  }
  if (kk_nagare_core_types__is_PEval(_uniq_left_10207, _ctx)) {
    struct kk_nagare_core_types_PEval* _con_x562 = kk_nagare_core_types__as_PEval(_uniq_left_10207, _ctx);
    kk_function_t _uniq_next_10214 = _con_x562->next;
    kk_reuse_t _ru_x440 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_left_10207, _ctx)) {
      _ru_x440 = (kk_datatype_ptr_reuse(_uniq_left_10207, _ctx));
    }
    else {
      kk_function_dup(_uniq_next_10214, _ctx);
      kk_datatype_ptr_decref(_uniq_left_10207, _ctx);
    }
    return kk_nagare_core_types__new_PEval(_ru_x440, 0, kk_nagare_core_pull__new_lift_unroll_pullFlatMap_10011_10221_fun563(_uniq_next_10214, f_2, tail_1, _ctx), _ctx);
  }
  {
    struct kk_nagare_core_types_PAcquire* _con_x567 = kk_nagare_core_types__as_PAcquire(_uniq_left_10207, _ctx);
    kk_function_t _uniq_acquire_10216 = _con_x567->acquire;
    kk_function_t _uniq_release_10217 = _con_x567->release;
    kk_nagare_core_types__pull _uniq_tail_0_10218 = _con_x567->tail;
    kk_reuse_t _ru_x441 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_left_10207, _ctx)) {
      _ru_x441 = (kk_datatype_ptr_reuse(_uniq_left_10207, _ctx));
    }
    else {
      kk_function_dup(_uniq_acquire_10216, _ctx);
      kk_function_dup(_uniq_release_10217, _ctx);
      kk_nagare_core_types__pull_dup(_uniq_tail_0_10218, _ctx);
      kk_datatype_ptr_decref(_uniq_left_10207, _ctx);
    }
    kk_nagare_core_types__pull _x_x568 = kk_nagare_core_pull__lift_unroll_pullFlatMap_10011_10221(f_2, tail_1, _uniq_tail_0_10218, _ctx); /*nagare/core/types/pull<1682,1683>*/
    return kk_nagare_core_types__new_PAcquire(_ru_x441, 0, _uniq_acquire_10216, _uniq_release_10217, _x_x568, _ctx);
  }
}
 
// FlatMap a pull by expanding each emitted value into a pull and concatenating.


// lift anonymous function
struct kk_nagare_core_pull__unroll_pullFlatMap_10011_fun572__t {
  struct kk_function_s _base;
  kk_function_t f_3;
  kk_nagare_core_types__pull tail_2;
};
static kk_box_t kk_nagare_core_pull__unroll_pullFlatMap_10011_fun572(kk_function_t _fself, kk_box_t _b_x190, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_pull__new_unroll_pullFlatMap_10011_fun572(kk_function_t f_3, kk_nagare_core_types__pull tail_2, kk_context_t* _ctx) {
  struct kk_nagare_core_pull__unroll_pullFlatMap_10011_fun572__t* _self = kk_function_alloc_as(struct kk_nagare_core_pull__unroll_pullFlatMap_10011_fun572__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_pull__unroll_pullFlatMap_10011_fun572, kk_context());
  _self->f_3 = f_3;
  _self->tail_2 = tail_2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_core_pull__unroll_pullFlatMap_10011_fun572(kk_function_t _fself, kk_box_t _b_x190, kk_context_t* _ctx) {
  struct kk_nagare_core_pull__unroll_pullFlatMap_10011_fun572__t* _self = kk_function_as(struct kk_nagare_core_pull__unroll_pullFlatMap_10011_fun572__t*, _fself, _ctx);
  kk_function_t f_3 = _self->f_3; /* (1681) -> nagare/core/types/pull<1682,1683> */
  kk_nagare_core_types__pull tail_2 = _self->tail_2; /* nagare/core/types/pull<1681,1683> */
  kk_drop_match(_self, {kk_function_dup(f_3, _ctx);kk_nagare_core_types__pull_dup(tail_2, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull _c_x10280_0_195 = kk_nagare_core_types__pull_unbox(_b_x190, KK_OWNED, _ctx); /*nagare/core/types/pull<1682,1683>*/;
  kk_nagare_core_types__pull _x_x573 = kk_nagare_core_pull__mlift_unroll_pullFlatMap_10011_10317(f_3, tail_2, _c_x10280_0_195, _ctx); /*nagare/core/types/pull<1682,1683>*/
  return kk_nagare_core_types__pull_box(_x_x573, _ctx);
}


// lift anonymous function
struct kk_nagare_core_pull__unroll_pullFlatMap_10011_fun575__t {
  struct kk_function_s _base;
  kk_function_t f_3;
  kk_function_t next_1;
};
static kk_nagare_core_types__pull kk_nagare_core_pull__unroll_pullFlatMap_10011_fun575(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_pull__new_unroll_pullFlatMap_10011_fun575(kk_function_t f_3, kk_function_t next_1, kk_context_t* _ctx) {
  struct kk_nagare_core_pull__unroll_pullFlatMap_10011_fun575__t* _self = kk_function_alloc_as(struct kk_nagare_core_pull__unroll_pullFlatMap_10011_fun575__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_pull__unroll_pullFlatMap_10011_fun575, kk_context());
  _self->f_3 = f_3;
  _self->next_1 = next_1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_core_pull__unroll_pullFlatMap_10011_fun577__t {
  struct kk_function_s _base;
  kk_function_t f_3;
};
static kk_box_t kk_nagare_core_pull__unroll_pullFlatMap_10011_fun577(kk_function_t _fself, kk_box_t _b_x192, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_pull__new_unroll_pullFlatMap_10011_fun577(kk_function_t f_3, kk_context_t* _ctx) {
  struct kk_nagare_core_pull__unroll_pullFlatMap_10011_fun577__t* _self = kk_function_alloc_as(struct kk_nagare_core_pull__unroll_pullFlatMap_10011_fun577__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_pull__unroll_pullFlatMap_10011_fun577, kk_context());
  _self->f_3 = f_3;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_core_pull__unroll_pullFlatMap_10011_fun577(kk_function_t _fself, kk_box_t _b_x192, kk_context_t* _ctx) {
  struct kk_nagare_core_pull__unroll_pullFlatMap_10011_fun577__t* _self = kk_function_as(struct kk_nagare_core_pull__unroll_pullFlatMap_10011_fun577__t*, _fself, _ctx);
  kk_function_t f_3 = _self->f_3; /* (1681) -> nagare/core/types/pull<1682,1683> */
  kk_drop_match(_self, {kk_function_dup(f_3, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull _y_x10283_0_196 = kk_nagare_core_types__pull_unbox(_b_x192, KK_OWNED, _ctx); /*nagare/core/types/pull<1681,1683>*/;
  kk_nagare_core_types__pull _x_x578 = kk_nagare_core_pull__mlift_unroll_pullFlatMap_10011_10318(f_3, _y_x10283_0_196, _ctx); /*nagare/core/types/pull<1682,1683>*/
  return kk_nagare_core_types__pull_box(_x_x578, _ctx);
}
static kk_nagare_core_types__pull kk_nagare_core_pull__unroll_pullFlatMap_10011_fun575(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_core_pull__unroll_pullFlatMap_10011_fun575__t* _self = kk_function_as(struct kk_nagare_core_pull__unroll_pullFlatMap_10011_fun575__t*, _fself, _ctx);
  kk_function_t f_3 = _self->f_3; /* (1681) -> nagare/core/types/pull<1682,1683> */
  kk_function_t next_1 = _self->next_1; /* () -> 1683 nagare/core/types/pull<1681,1683> */
  kk_drop_match(_self, {kk_function_dup(f_3, _ctx);kk_function_dup(next_1, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull x_1_10353 = kk_function_call(kk_nagare_core_types__pull, (kk_function_t, kk_context_t*), next_1, (next_1, _ctx), _ctx); /*nagare/core/types/pull<1681,1683>*/;
  if (kk_yielding(kk_context())) {
    kk_nagare_core_types__pull_drop(x_1_10353, _ctx);
    kk_box_t _x_x576 = kk_std_core_hnd_yield_extend(kk_nagare_core_pull__new_unroll_pullFlatMap_10011_fun577(f_3, _ctx), _ctx); /*10001*/
    return kk_nagare_core_types__pull_unbox(_x_x576, KK_OWNED, _ctx);
  }
  {
    return kk_nagare_core_pull__mlift_unroll_pullFlatMap_10011_10318(f_3, x_1_10353, _ctx);
  }
}

kk_nagare_core_types__pull kk_nagare_core_pull__unroll_pullFlatMap_10011(kk_nagare_core_types__pull source, kk_function_t f_3, kk_context_t* _ctx) { /* forall<a,b,e> (source : nagare/core/types/pull<a,e>, f : (a) -> nagare/core/types/pull<b,e>) -> nagare/core/types/pull<b,e> */ 
  kk__tailcall: ;
  if (kk_nagare_core_types__is_PDone(source, _ctx)) {
    kk_function_drop(f_3, _ctx);
    return kk_nagare_core_types__new_PDone(_ctx);
  }
  if (kk_nagare_core_types__is_POutput(source, _ctx)) {
    struct kk_nagare_core_types_POutput* _con_x569 = kk_nagare_core_types__as_POutput(source, _ctx);
    kk_nagare_core_types__chunk out = _con_x569->out;
    kk_nagare_core_types__pull tail_2 = _con_x569->tail;
    if kk_likely(kk_datatype_ptr_is_unique(source, _ctx)) {
      kk_datatype_ptr_free(source, _ctx);
    }
    else {
      kk_nagare_core_types__chunk_dup(out, _ctx);
      kk_nagare_core_types__pull_dup(tail_2, _ctx);
      kk_datatype_ptr_decref(source, _ctx);
    }
    {
      kk_std_core_types__list values = out.values;
      kk_nagare_core_types__pull x_0_10350;
      if (kk_std_core_types__is_Nil(values, _ctx)) {
        x_0_10350 = kk_nagare_core_types__new_PDone(_ctx); /*nagare/core/types/pull<1682,1683>*/
      }
      else {
        kk_function_t _x_x570 = kk_function_dup(f_3, _ctx); /*(1681) -> nagare/core/types/pull<1682,1683>*/
        x_0_10350 = kk_nagare_core_pull__unroll_flatMapChunk_10010(values, _x_x570, _ctx); /*nagare/core/types/pull<1682,1683>*/
      }
      if (kk_yielding(kk_context())) {
        kk_nagare_core_types__pull_drop(x_0_10350, _ctx);
        kk_box_t _x_x571 = kk_std_core_hnd_yield_extend(kk_nagare_core_pull__new_unroll_pullFlatMap_10011_fun572(f_3, tail_2, _ctx), _ctx); /*10001*/
        return kk_nagare_core_types__pull_unbox(_x_x571, KK_OWNED, _ctx);
      }
      if (kk_nagare_core_types__is_PDone(x_0_10350, _ctx)) { // tailcall
                                                             source = tail_2;
                                                             goto kk__tailcall;
      }
      {
        return kk_nagare_core_pull__lift_unroll_pullFlatMap_10011_10221(f_3, tail_2, x_0_10350, _ctx);
      }
    }
  }
  if (kk_nagare_core_types__is_PEval(source, _ctx)) {
    struct kk_nagare_core_types_PEval* _con_x574 = kk_nagare_core_types__as_PEval(source, _ctx);
    kk_function_t next_1 = _con_x574->next;
    kk_reuse_t _ru_x443 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(source, _ctx)) {
      _ru_x443 = (kk_datatype_ptr_reuse(source, _ctx));
    }
    else {
      kk_function_dup(next_1, _ctx);
      kk_datatype_ptr_decref(source, _ctx);
    }
    return kk_nagare_core_types__new_PEval(_ru_x443, 0, kk_nagare_core_pull__new_unroll_pullFlatMap_10011_fun575(f_3, next_1, _ctx), _ctx);
  }
  {
    struct kk_nagare_core_types_PAcquire* _con_x579 = kk_nagare_core_types__as_PAcquire(source, _ctx);
    kk_function_t acquire = _con_x579->acquire;
    kk_function_t release = _con_x579->release;
    kk_nagare_core_types__pull tail_0_0 = _con_x579->tail;
    kk_reuse_t _ru_x444 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(source, _ctx)) {
      _ru_x444 = (kk_datatype_ptr_reuse(source, _ctx));
    }
    else {
      kk_function_dup(acquire, _ctx);
      kk_function_dup(release, _ctx);
      kk_nagare_core_types__pull_dup(tail_0_0, _ctx);
      kk_datatype_ptr_decref(source, _ctx);
    }
    kk_nagare_core_types__pull _x_x580 = kk_nagare_core_pull__unroll_pullFlatMap_10011(tail_0_0, f_3, _ctx); /*nagare/core/types/pull<1682,1683>*/
    return kk_nagare_core_types__new_PAcquire(_ru_x444, 0, acquire, release, _x_x580, _ctx);
  }
}
 
// monadic lift

kk_nagare_core_types__pull kk_nagare_core_pull__mlift_trmc_pullTake_10319(kk_integer_t n, kk_nagare_core_types__pull _y_x10288, kk_context_t* _ctx) { /* forall<a,e> (n : int, nagare/core/types/pull<a,e>) -> e nagare/core/types/pull<a,e> */ 
  return kk_nagare_core_pull_pullTake(_y_x10288, n, _ctx);
}
 
// Keep only first n outputs from a pull.


// lift anonymous function
struct kk_nagare_core_pull__trmc_pullTake_fun596__t {
  struct kk_function_s _base;
  kk_integer_t n_0;
  kk_function_t next;
};
static kk_nagare_core_types__pull kk_nagare_core_pull__trmc_pullTake_fun596(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_pull__new_trmc_pullTake_fun596(kk_integer_t n_0, kk_function_t next, kk_context_t* _ctx) {
  struct kk_nagare_core_pull__trmc_pullTake_fun596__t* _self = kk_function_alloc_as(struct kk_nagare_core_pull__trmc_pullTake_fun596__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_pull__trmc_pullTake_fun596, kk_context());
  _self->n_0 = n_0;
  _self->next = next;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_core_pull__trmc_pullTake_fun598__t {
  struct kk_function_s _base;
  kk_integer_t n_0;
};
static kk_box_t kk_nagare_core_pull__trmc_pullTake_fun598(kk_function_t _fself, kk_box_t _b_x210, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_pull__new_trmc_pullTake_fun598(kk_integer_t n_0, kk_context_t* _ctx) {
  struct kk_nagare_core_pull__trmc_pullTake_fun598__t* _self = kk_function_alloc_as(struct kk_nagare_core_pull__trmc_pullTake_fun598__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_pull__trmc_pullTake_fun598, kk_context());
  _self->n_0 = n_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_core_pull__trmc_pullTake_fun598(kk_function_t _fself, kk_box_t _b_x210, kk_context_t* _ctx) {
  struct kk_nagare_core_pull__trmc_pullTake_fun598__t* _self = kk_function_as(struct kk_nagare_core_pull__trmc_pullTake_fun598__t*, _fself, _ctx);
  kk_integer_t n_0 = _self->n_0; /* int */
  kk_drop_match(_self, {kk_integer_dup(n_0, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull _y_x10288_0_240 = kk_nagare_core_types__pull_unbox(_b_x210, KK_OWNED, _ctx); /*nagare/core/types/pull<1953,1954>*/;
  kk_nagare_core_types__pull _x_x599 = kk_nagare_core_pull__mlift_trmc_pullTake_10319(n_0, _y_x10288_0_240, _ctx); /*nagare/core/types/pull<1953,1954>*/
  return kk_nagare_core_types__pull_box(_x_x599, _ctx);
}
static kk_nagare_core_types__pull kk_nagare_core_pull__trmc_pullTake_fun596(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_core_pull__trmc_pullTake_fun596__t* _self = kk_function_as(struct kk_nagare_core_pull__trmc_pullTake_fun596__t*, _fself, _ctx);
  kk_integer_t n_0 = _self->n_0; /* int */
  kk_function_t next = _self->next; /* () -> 1954 nagare/core/types/pull<1953,1954> */
  kk_drop_match(_self, {kk_integer_dup(n_0, _ctx);kk_function_dup(next, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull x_10357 = kk_function_call(kk_nagare_core_types__pull, (kk_function_t, kk_context_t*), next, (next, _ctx), _ctx); /*nagare/core/types/pull<1953,1954>*/;
  if (kk_yielding(kk_context())) {
    kk_nagare_core_types__pull_drop(x_10357, _ctx);
    kk_box_t _x_x597 = kk_std_core_hnd_yield_extend(kk_nagare_core_pull__new_trmc_pullTake_fun598(n_0, _ctx), _ctx); /*10001*/
    return kk_nagare_core_types__pull_unbox(_x_x597, KK_OWNED, _ctx);
  }
  {
    return kk_nagare_core_pull__mlift_trmc_pullTake_10319(n_0, x_10357, _ctx);
  }
}

kk_nagare_core_types__pull kk_nagare_core_pull__trmc_pullTake(kk_nagare_core_types__pull source, kk_integer_t n_0, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* forall<a,e> (source : nagare/core/types/pull<a,e>, n : int, ctx<nagare/core/types/pull<a,e>>) -> nagare/core/types/pull<a,e> */ 
  kk__tailcall: ;
  bool _match_x400 = kk_integer_lte_borrow(n_0,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x400) {
    kk_nagare_core_types__pull_drop(source, _ctx);
    kk_integer_drop(n_0, _ctx);
    kk_box_t _x_x581 = kk_cctx_apply_linear(_acc,(kk_nagare_core_types__pull_box(kk_nagare_core_types__new_PDone(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_nagare_core_types__pull_unbox(_x_x581, KK_OWNED, _ctx);
  }
  if (kk_nagare_core_types__is_PDone(source, _ctx)) {
    kk_integer_drop(n_0, _ctx);
    kk_box_t _x_x582 = kk_cctx_apply_linear(_acc,(kk_nagare_core_types__pull_box(kk_nagare_core_types__new_PDone(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_nagare_core_types__pull_unbox(_x_x582, KK_OWNED, _ctx);
  }
  if (kk_nagare_core_types__is_POutput(source, _ctx)) {
    struct kk_nagare_core_types_POutput* _con_x583 = kk_nagare_core_types__as_POutput(source, _ctx);
    kk_nagare_core_types__chunk out = _con_x583->out;
    kk_nagare_core_types__pull tail = _con_x583->tail;
    kk_reuse_t _ru_x445 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(source, _ctx)) {
      _ru_x445 = (kk_datatype_ptr_reuse(source, _ctx));
    }
    else {
      kk_nagare_core_types__chunk_dup(out, _ctx);
      kk_nagare_core_types__pull_dup(tail, _ctx);
      kk_datatype_ptr_decref(source, _ctx);
    }
    {
      kk_std_core_types__list values = out.values;
      kk_integer_t len;
      if (kk_std_core_types__is_Nil(values, _ctx)) {
        len = kk_integer_from_small(0); /*int*/
      }
      else {
        kk_std_core_types__list _x_x584 = kk_std_core_types__list_dup(values, _ctx); /*list<1953>*/
        len = kk_nagare_core_pull__unroll_listLength_10001(_x_x584, _ctx); /*int*/
      }
      bool _match_x402 = kk_integer_lte_borrow(len,n_0,kk_context()); /*bool*/;
      if (_match_x402) {
        kk_nagare_core_types__pull _trmc_x10246 = kk_datatype_null(); /*nagare/core/types/pull<1953,1954>*/;
        kk_nagare_core_types__pull _trmc_x10247;
        kk_nagare_core_types__chunk _x_x585 = kk_nagare_core_types__new_Chunk(values, _ctx); /*nagare/core/types/chunk<4>*/
        _trmc_x10247 = kk_nagare_core_types__new_POutput(_ru_x445, 0, _x_x585, _trmc_x10246, _ctx); /*nagare/core/types/pull<1953,1954>*/
        kk_field_addr_t _b_x206_225 = kk_field_addr_create(&kk_nagare_core_types__as_POutput(_trmc_x10247, _ctx)->tail, _ctx); /*@field-addr<nagare/core/types/pull<1953,1954>>*/;
        { // tailcall
          kk_integer_t _x_x586 = kk_integer_sub(n_0,len,kk_context()); /*int*/
          kk_std_core_types__cctx _x_x587 = kk_cctx_extend_linear(_acc,(kk_nagare_core_types__pull_box(_trmc_x10247, _ctx)),_b_x206_225,kk_context()); /*ctx<0>*/
          source = tail;
          n_0 = _x_x586;
          _acc = _x_x587;
          goto kk__tailcall;
        }
      }
      {
        kk_nagare_core_types__pull_drop(tail, _ctx);
        kk_integer_drop(len, _ctx);
        kk_nagare_core_types__pull _b_x208_230;
        kk_nagare_core_types__chunk _x_x588;
        kk_std_core_types__list _x_x589;
        kk_std_core_types__cctx _x_x590 = kk_cctx_empty(kk_context()); /*ctx<0>*/
        _x_x589 = kk_nagare_core_pull__trmc_listTakeN(values, n_0, _x_x590, _ctx); /*list<359>*/
        _x_x588 = kk_nagare_core_types__new_Chunk(_x_x589, _ctx); /*nagare/core/types/chunk<4>*/
        _b_x208_230 = kk_nagare_core_types__new_POutput(_ru_x445, 0, _x_x588, kk_nagare_core_types__new_PDone(_ctx), _ctx); /*nagare/core/types/pull<1953,1954>*/
        kk_box_t _x_x591 = kk_cctx_apply_linear(_acc,(kk_nagare_core_types__pull_box(_b_x208_230, _ctx)),kk_context()); /*-1*/
        return kk_nagare_core_types__pull_unbox(_x_x591, KK_OWNED, _ctx);
      }
    }
  }
  if (kk_nagare_core_types__is_PEval(source, _ctx)) {
    struct kk_nagare_core_types_PEval* _con_x592 = kk_nagare_core_types__as_PEval(source, _ctx);
    kk_function_t next = _con_x592->next;
    kk_reuse_t _ru_x446 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(source, _ctx)) {
      _ru_x446 = (kk_datatype_ptr_reuse(source, _ctx));
    }
    else {
      kk_function_dup(next, _ctx);
      kk_datatype_ptr_decref(source, _ctx);
    }
    kk_box_t _x_x593;
    kk_box_t _x_x594;
    kk_nagare_core_types__pull _x_x595 = kk_nagare_core_types__new_PEval(_ru_x446, 0, kk_nagare_core_pull__new_trmc_pullTake_fun596(n_0, next, _ctx), _ctx); /*nagare/core/types/pull<19,20>*/
    _x_x594 = kk_nagare_core_types__pull_box(_x_x595, _ctx); /*-1*/
    _x_x593 = kk_cctx_apply_linear(_acc,_x_x594,kk_context()); /*-1*/
    return kk_nagare_core_types__pull_unbox(_x_x593, KK_OWNED, _ctx);
  }
  {
    struct kk_nagare_core_types_PAcquire* _con_x600 = kk_nagare_core_types__as_PAcquire(source, _ctx);
    kk_function_t acquire = _con_x600->acquire;
    kk_function_t release = _con_x600->release;
    kk_nagare_core_types__pull tail_0 = _con_x600->tail;
    kk_reuse_t _ru_x447 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(source, _ctx)) {
      _ru_x447 = (kk_datatype_ptr_reuse(source, _ctx));
    }
    else {
      kk_function_dup(acquire, _ctx);
      kk_function_dup(release, _ctx);
      kk_nagare_core_types__pull_dup(tail_0, _ctx);
      kk_datatype_ptr_decref(source, _ctx);
    }
    kk_nagare_core_types__pull _trmc_x10248 = kk_datatype_null(); /*nagare/core/types/pull<1953,1954>*/;
    kk_nagare_core_types__pull _trmc_x10249 = kk_nagare_core_types__new_PAcquire(_ru_x447, 0, acquire, release, _trmc_x10248, _ctx); /*nagare/core/types/pull<1953,1954>*/;
    kk_field_addr_t _b_x218_236 = kk_field_addr_create(&kk_nagare_core_types__as_PAcquire(_trmc_x10249, _ctx)->tail, _ctx); /*@field-addr<nagare/core/types/pull<1953,1954>>*/;
    { // tailcall
      kk_std_core_types__cctx _x_x601 = kk_cctx_extend_linear(_acc,(kk_nagare_core_types__pull_box(_trmc_x10249, _ctx)),_b_x218_236,kk_context()); /*ctx<0>*/
      source = tail_0;
      _acc = _x_x601;
      goto kk__tailcall;
    }
  }
}
 
// Keep only first n outputs from a pull.

kk_nagare_core_types__pull kk_nagare_core_pull_pullTake(kk_nagare_core_types__pull source_0, kk_integer_t n_2, kk_context_t* _ctx) { /* forall<a,e> (source : nagare/core/types/pull<a,e>, n : int) -> nagare/core/types/pull<a,e> */ 
  kk_std_core_types__cctx _x_x602 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_nagare_core_pull__trmc_pullTake(source_0, n_2, _x_x602, _ctx);
}
 
// monadic lift

kk_nagare_core_types__pull kk_nagare_core_pull__mlift_trmc_pullDrop_10320(kk_integer_t n, kk_nagare_core_types__pull _y_x10293, kk_context_t* _ctx) { /* forall<a,e> (n : int, nagare/core/types/pull<a,e>) -> e nagare/core/types/pull<a,e> */ 
  return kk_nagare_core_pull_pullDrop(_y_x10293, n, _ctx);
}
 
// Drop first n outputs from a pull.


// lift anonymous function
struct kk_nagare_core_pull__trmc_pullDrop_fun615__t {
  struct kk_function_s _base;
  kk_integer_t n_0;
  kk_function_t next;
};
static kk_nagare_core_types__pull kk_nagare_core_pull__trmc_pullDrop_fun615(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_pull__new_trmc_pullDrop_fun615(kk_integer_t n_0, kk_function_t next, kk_context_t* _ctx) {
  struct kk_nagare_core_pull__trmc_pullDrop_fun615__t* _self = kk_function_alloc_as(struct kk_nagare_core_pull__trmc_pullDrop_fun615__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_pull__trmc_pullDrop_fun615, kk_context());
  _self->n_0 = n_0;
  _self->next = next;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_core_pull__trmc_pullDrop_fun617__t {
  struct kk_function_s _base;
  kk_integer_t n_0;
};
static kk_box_t kk_nagare_core_pull__trmc_pullDrop_fun617(kk_function_t _fself, kk_box_t _b_x248, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_pull__new_trmc_pullDrop_fun617(kk_integer_t n_0, kk_context_t* _ctx) {
  struct kk_nagare_core_pull__trmc_pullDrop_fun617__t* _self = kk_function_alloc_as(struct kk_nagare_core_pull__trmc_pullDrop_fun617__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_pull__trmc_pullDrop_fun617, kk_context());
  _self->n_0 = n_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_core_pull__trmc_pullDrop_fun617(kk_function_t _fself, kk_box_t _b_x248, kk_context_t* _ctx) {
  struct kk_nagare_core_pull__trmc_pullDrop_fun617__t* _self = kk_function_as(struct kk_nagare_core_pull__trmc_pullDrop_fun617__t*, _fself, _ctx);
  kk_integer_t n_0 = _self->n_0; /* int */
  kk_drop_match(_self, {kk_integer_dup(n_0, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull _y_x10293_0_272 = kk_nagare_core_types__pull_unbox(_b_x248, KK_OWNED, _ctx); /*nagare/core/types/pull<2195,2196>*/;
  kk_nagare_core_types__pull _x_x618 = kk_nagare_core_pull__mlift_trmc_pullDrop_10320(n_0, _y_x10293_0_272, _ctx); /*nagare/core/types/pull<2195,2196>*/
  return kk_nagare_core_types__pull_box(_x_x618, _ctx);
}
static kk_nagare_core_types__pull kk_nagare_core_pull__trmc_pullDrop_fun615(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_core_pull__trmc_pullDrop_fun615__t* _self = kk_function_as(struct kk_nagare_core_pull__trmc_pullDrop_fun615__t*, _fself, _ctx);
  kk_integer_t n_0 = _self->n_0; /* int */
  kk_function_t next = _self->next; /* () -> 2196 nagare/core/types/pull<2195,2196> */
  kk_drop_match(_self, {kk_integer_dup(n_0, _ctx);kk_function_dup(next, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull x_10359 = kk_function_call(kk_nagare_core_types__pull, (kk_function_t, kk_context_t*), next, (next, _ctx), _ctx); /*nagare/core/types/pull<2195,2196>*/;
  if (kk_yielding(kk_context())) {
    kk_nagare_core_types__pull_drop(x_10359, _ctx);
    kk_box_t _x_x616 = kk_std_core_hnd_yield_extend(kk_nagare_core_pull__new_trmc_pullDrop_fun617(n_0, _ctx), _ctx); /*10001*/
    return kk_nagare_core_types__pull_unbox(_x_x616, KK_OWNED, _ctx);
  }
  {
    return kk_nagare_core_pull__mlift_trmc_pullDrop_10320(n_0, x_10359, _ctx);
  }
}

kk_nagare_core_types__pull kk_nagare_core_pull__trmc_pullDrop(kk_nagare_core_types__pull source, kk_integer_t n_0, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* forall<a,e> (source : nagare/core/types/pull<a,e>, n : int, ctx<nagare/core/types/pull<a,e>>) -> nagare/core/types/pull<a,e> */ 
  kk__tailcall: ;
  bool _match_x397 = kk_integer_lte_borrow(n_0,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x397) {
    kk_integer_drop(n_0, _ctx);
    kk_box_t _x_x603 = kk_cctx_apply_linear(_acc,(kk_nagare_core_types__pull_box(source, _ctx)),kk_context()); /*-1*/
    return kk_nagare_core_types__pull_unbox(_x_x603, KK_OWNED, _ctx);
  }
  if (kk_nagare_core_types__is_PDone(source, _ctx)) {
    kk_integer_drop(n_0, _ctx);
    kk_box_t _x_x604 = kk_cctx_apply_linear(_acc,(kk_nagare_core_types__pull_box(kk_nagare_core_types__new_PDone(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_nagare_core_types__pull_unbox(_x_x604, KK_OWNED, _ctx);
  }
  if (kk_nagare_core_types__is_POutput(source, _ctx)) {
    struct kk_nagare_core_types_POutput* _con_x605 = kk_nagare_core_types__as_POutput(source, _ctx);
    kk_nagare_core_types__chunk out = _con_x605->out;
    kk_nagare_core_types__pull tail = _con_x605->tail;
    kk_reuse_t _ru_x448 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(source, _ctx)) {
      _ru_x448 = (kk_datatype_ptr_reuse(source, _ctx));
    }
    else {
      kk_nagare_core_types__chunk_dup(out, _ctx);
      kk_nagare_core_types__pull_dup(tail, _ctx);
      kk_datatype_ptr_decref(source, _ctx);
    }
    {
      kk_std_core_types__list values = out.values;
      kk_integer_t len;
      if (kk_std_core_types__is_Nil(values, _ctx)) {
        len = kk_integer_from_small(0); /*int*/
      }
      else {
        kk_std_core_types__list _x_x606 = kk_std_core_types__list_dup(values, _ctx); /*list<2195>*/
        len = kk_nagare_core_pull__unroll_listLength_10001(_x_x606, _ctx); /*int*/
      }
      bool _match_x399 = kk_integer_gte_borrow(n_0,len,kk_context()); /*bool*/;
      if (_match_x399) {
        kk_reuse_drop(_ru_x448,kk_context());
        kk_std_core_types__list_drop(values, _ctx);
        { // tailcall
          kk_integer_t _x_x607 = kk_integer_sub(n_0,len,kk_context()); /*int*/
          source = tail;
          n_0 = _x_x607;
          goto kk__tailcall;
        }
      }
      {
        kk_integer_drop(len, _ctx);
        kk_nagare_core_types__pull _b_x246_262;
        kk_nagare_core_types__chunk _x_x608;
        kk_std_core_types__list _x_x609 = kk_nagare_core_pull_listDropN(values, n_0, _ctx); /*list<440>*/
        _x_x608 = kk_nagare_core_types__new_Chunk(_x_x609, _ctx); /*nagare/core/types/chunk<4>*/
        _b_x246_262 = kk_nagare_core_types__new_POutput(_ru_x448, 0, _x_x608, tail, _ctx); /*nagare/core/types/pull<2195,2196>*/
        kk_box_t _x_x610 = kk_cctx_apply_linear(_acc,(kk_nagare_core_types__pull_box(_b_x246_262, _ctx)),kk_context()); /*-1*/
        return kk_nagare_core_types__pull_unbox(_x_x610, KK_OWNED, _ctx);
      }
    }
  }
  if (kk_nagare_core_types__is_PEval(source, _ctx)) {
    struct kk_nagare_core_types_PEval* _con_x611 = kk_nagare_core_types__as_PEval(source, _ctx);
    kk_function_t next = _con_x611->next;
    kk_reuse_t _ru_x449 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(source, _ctx)) {
      _ru_x449 = (kk_datatype_ptr_reuse(source, _ctx));
    }
    else {
      kk_function_dup(next, _ctx);
      kk_datatype_ptr_decref(source, _ctx);
    }
    kk_box_t _x_x612;
    kk_box_t _x_x613;
    kk_nagare_core_types__pull _x_x614 = kk_nagare_core_types__new_PEval(_ru_x449, 0, kk_nagare_core_pull__new_trmc_pullDrop_fun615(n_0, next, _ctx), _ctx); /*nagare/core/types/pull<19,20>*/
    _x_x613 = kk_nagare_core_types__pull_box(_x_x614, _ctx); /*-1*/
    _x_x612 = kk_cctx_apply_linear(_acc,_x_x613,kk_context()); /*-1*/
    return kk_nagare_core_types__pull_unbox(_x_x612, KK_OWNED, _ctx);
  }
  {
    struct kk_nagare_core_types_PAcquire* _con_x619 = kk_nagare_core_types__as_PAcquire(source, _ctx);
    kk_function_t acquire = _con_x619->acquire;
    kk_function_t release = _con_x619->release;
    kk_nagare_core_types__pull tail_0 = _con_x619->tail;
    kk_reuse_t _ru_x450 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(source, _ctx)) {
      _ru_x450 = (kk_datatype_ptr_reuse(source, _ctx));
    }
    else {
      kk_function_dup(acquire, _ctx);
      kk_function_dup(release, _ctx);
      kk_nagare_core_types__pull_dup(tail_0, _ctx);
      kk_datatype_ptr_decref(source, _ctx);
    }
    kk_nagare_core_types__pull _trmc_x10250 = kk_datatype_null(); /*nagare/core/types/pull<2195,2196>*/;
    kk_nagare_core_types__pull _trmc_x10251 = kk_nagare_core_types__new_PAcquire(_ru_x450, 0, acquire, release, _trmc_x10250, _ctx); /*nagare/core/types/pull<2195,2196>*/;
    kk_field_addr_t _b_x256_268 = kk_field_addr_create(&kk_nagare_core_types__as_PAcquire(_trmc_x10251, _ctx)->tail, _ctx); /*@field-addr<nagare/core/types/pull<2195,2196>>*/;
    { // tailcall
      kk_std_core_types__cctx _x_x620 = kk_cctx_extend_linear(_acc,(kk_nagare_core_types__pull_box(_trmc_x10251, _ctx)),_b_x256_268,kk_context()); /*ctx<0>*/
      source = tail_0;
      _acc = _x_x620;
      goto kk__tailcall;
    }
  }
}
 
// Drop first n outputs from a pull.

kk_nagare_core_types__pull kk_nagare_core_pull_pullDrop(kk_nagare_core_types__pull source_0, kk_integer_t n_1, kk_context_t* _ctx) { /* forall<a,e> (source : nagare/core/types/pull<a,e>, n : int) -> nagare/core/types/pull<a,e> */ 
  kk_std_core_types__cctx _x_x621 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_nagare_core_pull__trmc_pullDrop(source_0, n_1, _x_x621, _ctx);
}
 
// monadic lift

kk_nagare_core_types__pull kk_nagare_core_pull__mlift_trmc_unroll_pullTakeWhile_10012_10321(kk_function_t pred, kk_nagare_core_types__pull _y_x10299, kk_context_t* _ctx) { /* forall<a,e> (pred : (a) -> bool, nagare/core/types/pull<a,e>) -> e nagare/core/types/pull<a,e> */ 
  return kk_nagare_core_pull__unroll_pullTakeWhile_10012(_y_x10299, pred, _ctx);
}
 
// Keep longest prefix satisfying pred; stop at first failure.


// lift anonymous function
struct kk_nagare_core_pull__trmc_unroll_pullTakeWhile_10012_fun639__t {
  struct kk_function_s _base;
  kk_function_t next;
  kk_function_t pred_0;
};
static kk_nagare_core_types__pull kk_nagare_core_pull__trmc_unroll_pullTakeWhile_10012_fun639(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_pull__new_trmc_unroll_pullTakeWhile_10012_fun639(kk_function_t next, kk_function_t pred_0, kk_context_t* _ctx) {
  struct kk_nagare_core_pull__trmc_unroll_pullTakeWhile_10012_fun639__t* _self = kk_function_alloc_as(struct kk_nagare_core_pull__trmc_unroll_pullTakeWhile_10012_fun639__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_pull__trmc_unroll_pullTakeWhile_10012_fun639, kk_context());
  _self->next = next;
  _self->pred_0 = pred_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_core_pull__trmc_unroll_pullTakeWhile_10012_fun641__t {
  struct kk_function_s _base;
  kk_function_t pred_0;
};
static kk_box_t kk_nagare_core_pull__trmc_unroll_pullTakeWhile_10012_fun641(kk_function_t _fself, kk_box_t _b_x286, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_pull__new_trmc_unroll_pullTakeWhile_10012_fun641(kk_function_t pred_0, kk_context_t* _ctx) {
  struct kk_nagare_core_pull__trmc_unroll_pullTakeWhile_10012_fun641__t* _self = kk_function_alloc_as(struct kk_nagare_core_pull__trmc_unroll_pullTakeWhile_10012_fun641__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_pull__trmc_unroll_pullTakeWhile_10012_fun641, kk_context());
  _self->pred_0 = pred_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_core_pull__trmc_unroll_pullTakeWhile_10012_fun641(kk_function_t _fself, kk_box_t _b_x286, kk_context_t* _ctx) {
  struct kk_nagare_core_pull__trmc_unroll_pullTakeWhile_10012_fun641__t* _self = kk_function_as(struct kk_nagare_core_pull__trmc_unroll_pullTakeWhile_10012_fun641__t*, _fself, _ctx);
  kk_function_t pred_0 = _self->pred_0; /* (2402) -> bool */
  kk_drop_match(_self, {kk_function_dup(pred_0, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull _y_x10299_0_316 = kk_nagare_core_types__pull_unbox(_b_x286, KK_OWNED, _ctx); /*nagare/core/types/pull<2402,2403>*/;
  kk_nagare_core_types__pull _x_x642 = kk_nagare_core_pull__mlift_trmc_unroll_pullTakeWhile_10012_10321(pred_0, _y_x10299_0_316, _ctx); /*nagare/core/types/pull<2402,2403>*/
  return kk_nagare_core_types__pull_box(_x_x642, _ctx);
}
static kk_nagare_core_types__pull kk_nagare_core_pull__trmc_unroll_pullTakeWhile_10012_fun639(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_core_pull__trmc_unroll_pullTakeWhile_10012_fun639__t* _self = kk_function_as(struct kk_nagare_core_pull__trmc_unroll_pullTakeWhile_10012_fun639__t*, _fself, _ctx);
  kk_function_t next = _self->next; /* () -> 2403 nagare/core/types/pull<2402,2403> */
  kk_function_t pred_0 = _self->pred_0; /* (2402) -> bool */
  kk_drop_match(_self, {kk_function_dup(next, _ctx);kk_function_dup(pred_0, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull x_10363 = kk_function_call(kk_nagare_core_types__pull, (kk_function_t, kk_context_t*), next, (next, _ctx), _ctx); /*nagare/core/types/pull<2402,2403>*/;
  if (kk_yielding(kk_context())) {
    kk_nagare_core_types__pull_drop(x_10363, _ctx);
    kk_box_t _x_x640 = kk_std_core_hnd_yield_extend(kk_nagare_core_pull__new_trmc_unroll_pullTakeWhile_10012_fun641(pred_0, _ctx), _ctx); /*10001*/
    return kk_nagare_core_types__pull_unbox(_x_x640, KK_OWNED, _ctx);
  }
  {
    return kk_nagare_core_pull__mlift_trmc_unroll_pullTakeWhile_10012_10321(pred_0, x_10363, _ctx);
  }
}

kk_nagare_core_types__pull kk_nagare_core_pull__trmc_unroll_pullTakeWhile_10012(kk_nagare_core_types__pull source, kk_function_t pred_0, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* forall<a,e> (source : nagare/core/types/pull<a,e>, pred : (a) -> bool, ctx<nagare/core/types/pull<a,e>>) -> nagare/core/types/pull<a,e> */ 
  kk__tailcall: ;
  if (kk_nagare_core_types__is_PDone(source, _ctx)) {
    kk_function_drop(pred_0, _ctx);
    kk_box_t _x_x622 = kk_cctx_apply_linear(_acc,(kk_nagare_core_types__pull_box(kk_nagare_core_types__new_PDone(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_nagare_core_types__pull_unbox(_x_x622, KK_OWNED, _ctx);
  }
  if (kk_nagare_core_types__is_POutput(source, _ctx)) {
    struct kk_nagare_core_types_POutput* _con_x623 = kk_nagare_core_types__as_POutput(source, _ctx);
    kk_nagare_core_types__chunk out = _con_x623->out;
    kk_nagare_core_types__pull tail = _con_x623->tail;
    kk_reuse_t _ru_x451 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(source, _ctx)) {
      _ru_x451 = (kk_datatype_ptr_reuse(source, _ctx));
    }
    else {
      kk_nagare_core_types__chunk_dup(out, _ctx);
      kk_nagare_core_types__pull_dup(tail, _ctx);
      kk_datatype_ptr_decref(source, _ctx);
    }
    {
      kk_std_core_types__list values = out.values;
      kk_std_core_types__list kept;
      if (kk_std_core_types__is_Nil(values, _ctx)) {
        kept = kk_std_core_types__new_Nil(_ctx); /*list<2402>*/
      }
      else {
        kk_std_core_types__list _x_x624 = kk_std_core_types__list_dup(values, _ctx); /*list<2402>*/
        kk_function_t _x_x625 = kk_function_dup(pred_0, _ctx); /*(2402) -> bool*/
        kk_std_core_types__cctx _x_x626 = kk_cctx_empty(kk_context()); /*ctx<0>*/
        kept = kk_nagare_core_pull__trmc_unroll_listTakeWhile_10002(_x_x624, _x_x625, _x_x626, _ctx); /*list<2402>*/
      }
      kk_std_core_types__list rest;
      if (kk_std_core_types__is_Nil(values, _ctx)) {
        rest = kk_std_core_types__new_Nil(_ctx); /*list<2402>*/
      }
      else {
        kk_function_t _x_x627 = kk_function_dup(pred_0, _ctx); /*(2402) -> bool*/
        rest = kk_nagare_core_pull__unroll_listDropWhile_10003(values, _x_x627, _ctx); /*list<2402>*/
      }
      if (kk_std_core_types__is_Nil(kept, _ctx)) {
        kk_reuse_drop(_ru_x451,kk_context());
        kk_nagare_core_types__pull_drop(tail, _ctx);
        kk_std_core_types__list_drop(rest, _ctx);
        kk_function_drop(pred_0, _ctx);
        kk_box_t _x_x628 = kk_cctx_apply_linear(_acc,(kk_nagare_core_types__pull_box(kk_nagare_core_types__new_PDone(_ctx), _ctx)),kk_context()); /*-1*/
        return kk_nagare_core_types__pull_unbox(_x_x628, KK_OWNED, _ctx);
      }
      if (kk_std_core_types__is_Nil(rest, _ctx)) {
        kk_nagare_core_types__pull _trmc_x10252 = kk_datatype_null(); /*nagare/core/types/pull<2402,2403>*/;
        kk_nagare_core_types__pull _trmc_x10253;
        kk_nagare_core_types__chunk _x_x629 = kk_nagare_core_types__new_Chunk(kept, _ctx); /*nagare/core/types/chunk<4>*/
        _trmc_x10253 = kk_nagare_core_types__new_POutput(_ru_x451, 0, _x_x629, _trmc_x10252, _ctx); /*nagare/core/types/pull<2402,2403>*/
        kk_field_addr_t _b_x282_301 = kk_field_addr_create(&kk_nagare_core_types__as_POutput(_trmc_x10253, _ctx)->tail, _ctx); /*@field-addr<nagare/core/types/pull<2402,2403>>*/;
        { // tailcall
          kk_std_core_types__cctx _x_x630 = kk_cctx_extend_linear(_acc,(kk_nagare_core_types__pull_box(_trmc_x10253, _ctx)),_b_x282_301,kk_context()); /*ctx<0>*/
          source = tail;
          _acc = _x_x630;
          goto kk__tailcall;
        }
      }
      {
        kk_nagare_core_types__pull_drop(tail, _ctx);
        kk_std_core_types__list_drop(rest, _ctx);
        kk_function_drop(pred_0, _ctx);
        kk_box_t _x_x631;
        kk_box_t _x_x632;
        kk_nagare_core_types__pull _x_x633;
        kk_nagare_core_types__chunk _x_x634 = kk_nagare_core_types__new_Chunk(kept, _ctx); /*nagare/core/types/chunk<4>*/
        _x_x633 = kk_nagare_core_types__new_POutput(_ru_x451, 0, _x_x634, kk_nagare_core_types__new_PDone(_ctx), _ctx); /*nagare/core/types/pull<19,20>*/
        _x_x632 = kk_nagare_core_types__pull_box(_x_x633, _ctx); /*-1*/
        _x_x631 = kk_cctx_apply_linear(_acc,_x_x632,kk_context()); /*-1*/
        return kk_nagare_core_types__pull_unbox(_x_x631, KK_OWNED, _ctx);
      }
    }
  }
  if (kk_nagare_core_types__is_PEval(source, _ctx)) {
    struct kk_nagare_core_types_PEval* _con_x635 = kk_nagare_core_types__as_PEval(source, _ctx);
    kk_function_t next = _con_x635->next;
    kk_reuse_t _ru_x452 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(source, _ctx)) {
      _ru_x452 = (kk_datatype_ptr_reuse(source, _ctx));
    }
    else {
      kk_function_dup(next, _ctx);
      kk_datatype_ptr_decref(source, _ctx);
    }
    kk_box_t _x_x636;
    kk_box_t _x_x637;
    kk_nagare_core_types__pull _x_x638 = kk_nagare_core_types__new_PEval(_ru_x452, 0, kk_nagare_core_pull__new_trmc_unroll_pullTakeWhile_10012_fun639(next, pred_0, _ctx), _ctx); /*nagare/core/types/pull<19,20>*/
    _x_x637 = kk_nagare_core_types__pull_box(_x_x638, _ctx); /*-1*/
    _x_x636 = kk_cctx_apply_linear(_acc,_x_x637,kk_context()); /*-1*/
    return kk_nagare_core_types__pull_unbox(_x_x636, KK_OWNED, _ctx);
  }
  {
    struct kk_nagare_core_types_PAcquire* _con_x643 = kk_nagare_core_types__as_PAcquire(source, _ctx);
    kk_function_t acquire = _con_x643->acquire;
    kk_function_t release = _con_x643->release;
    kk_nagare_core_types__pull tail_0 = _con_x643->tail;
    kk_reuse_t _ru_x453 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(source, _ctx)) {
      _ru_x453 = (kk_datatype_ptr_reuse(source, _ctx));
    }
    else {
      kk_function_dup(acquire, _ctx);
      kk_function_dup(release, _ctx);
      kk_nagare_core_types__pull_dup(tail_0, _ctx);
      kk_datatype_ptr_decref(source, _ctx);
    }
    kk_nagare_core_types__pull _trmc_x10254 = kk_datatype_null(); /*nagare/core/types/pull<2402,2403>*/;
    kk_nagare_core_types__pull _trmc_x10255 = kk_nagare_core_types__new_PAcquire(_ru_x453, 0, acquire, release, _trmc_x10254, _ctx); /*nagare/core/types/pull<2402,2403>*/;
    kk_field_addr_t _b_x294_312 = kk_field_addr_create(&kk_nagare_core_types__as_PAcquire(_trmc_x10255, _ctx)->tail, _ctx); /*@field-addr<nagare/core/types/pull<2402,2403>>*/;
    { // tailcall
      kk_std_core_types__cctx _x_x644 = kk_cctx_extend_linear(_acc,(kk_nagare_core_types__pull_box(_trmc_x10255, _ctx)),_b_x294_312,kk_context()); /*ctx<0>*/
      source = tail_0;
      _acc = _x_x644;
      goto kk__tailcall;
    }
  }
}
 
// Keep longest prefix satisfying pred; stop at first failure.

kk_nagare_core_types__pull kk_nagare_core_pull__unroll_pullTakeWhile_10012(kk_nagare_core_types__pull source_0, kk_function_t pred_2, kk_context_t* _ctx) { /* forall<a,e> (source : nagare/core/types/pull<a,e>, pred : (a) -> bool) -> nagare/core/types/pull<a,e> */ 
  kk_std_core_types__cctx _x_x645 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_nagare_core_pull__trmc_unroll_pullTakeWhile_10012(source_0, pred_2, _x_x645, _ctx);
}
 
// monadic lift

kk_nagare_core_types__pull kk_nagare_core_pull__mlift_trmc_pullChunkN_10322(kk_integer_t n, kk_nagare_core_types__pull _y_x10304, kk_context_t* _ctx) { /* forall<a,e> (n : int, nagare/core/types/pull<a,e>) -> e nagare/core/types/pull<nagare/core/types/chunk<a>,e> */ 
  return kk_nagare_core_pull_pullChunkN(_y_x10304, n, _ctx);
}
 
// Re-chunk a pull into fixed-size chunks (last chunk may be smaller).


// lift anonymous function
struct kk_nagare_core_pull__trmc_pullChunkN_fun657__t {
  struct kk_function_s _base;
  kk_integer_t n_0;
  kk_function_t next;
};
static kk_nagare_core_types__pull kk_nagare_core_pull__trmc_pullChunkN_fun657(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_pull__new_trmc_pullChunkN_fun657(kk_integer_t n_0, kk_function_t next, kk_context_t* _ctx) {
  struct kk_nagare_core_pull__trmc_pullChunkN_fun657__t* _self = kk_function_alloc_as(struct kk_nagare_core_pull__trmc_pullChunkN_fun657__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_pull__trmc_pullChunkN_fun657, kk_context());
  _self->n_0 = n_0;
  _self->next = next;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_core_pull__trmc_pullChunkN_fun659__t {
  struct kk_function_s _base;
  kk_integer_t n_0;
};
static kk_box_t kk_nagare_core_pull__trmc_pullChunkN_fun659(kk_function_t _fself, kk_box_t _b_x328, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_pull__new_trmc_pullChunkN_fun659(kk_integer_t n_0, kk_context_t* _ctx) {
  struct kk_nagare_core_pull__trmc_pullChunkN_fun659__t* _self = kk_function_alloc_as(struct kk_nagare_core_pull__trmc_pullChunkN_fun659__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_pull__trmc_pullChunkN_fun659, kk_context());
  _self->n_0 = n_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_core_pull__trmc_pullChunkN_fun659(kk_function_t _fself, kk_box_t _b_x328, kk_context_t* _ctx) {
  struct kk_nagare_core_pull__trmc_pullChunkN_fun659__t* _self = kk_function_as(struct kk_nagare_core_pull__trmc_pullChunkN_fun659__t*, _fself, _ctx);
  kk_integer_t n_0 = _self->n_0; /* int */
  kk_drop_match(_self, {kk_integer_dup(n_0, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull _y_x10304_0_356 = kk_nagare_core_types__pull_unbox(_b_x328, KK_OWNED, _ctx); /*nagare/core/types/pull<2613,2614>*/;
  kk_nagare_core_types__pull _x_x660 = kk_nagare_core_pull__mlift_trmc_pullChunkN_10322(n_0, _y_x10304_0_356, _ctx); /*nagare/core/types/pull<nagare/core/types/chunk<2613>,2614>*/
  return kk_nagare_core_types__pull_box(_x_x660, _ctx);
}
static kk_nagare_core_types__pull kk_nagare_core_pull__trmc_pullChunkN_fun657(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_core_pull__trmc_pullChunkN_fun657__t* _self = kk_function_as(struct kk_nagare_core_pull__trmc_pullChunkN_fun657__t*, _fself, _ctx);
  kk_integer_t n_0 = _self->n_0; /* int */
  kk_function_t next = _self->next; /* () -> 2614 nagare/core/types/pull<2613,2614> */
  kk_drop_match(_self, {kk_integer_dup(n_0, _ctx);kk_function_dup(next, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull x_10367 = kk_function_call(kk_nagare_core_types__pull, (kk_function_t, kk_context_t*), next, (next, _ctx), _ctx); /*nagare/core/types/pull<2613,2614>*/;
  if (kk_yielding(kk_context())) {
    kk_nagare_core_types__pull_drop(x_10367, _ctx);
    kk_box_t _x_x658 = kk_std_core_hnd_yield_extend(kk_nagare_core_pull__new_trmc_pullChunkN_fun659(n_0, _ctx), _ctx); /*10001*/
    return kk_nagare_core_types__pull_unbox(_x_x658, KK_OWNED, _ctx);
  }
  {
    return kk_nagare_core_pull__mlift_trmc_pullChunkN_10322(n_0, x_10367, _ctx);
  }
}

kk_nagare_core_types__pull kk_nagare_core_pull__trmc_pullChunkN(kk_nagare_core_types__pull source, kk_integer_t n_0, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* forall<a,e> (source : nagare/core/types/pull<a,e>, n : int, ctx<nagare/core/types/pull<nagare/core/types/chunk<a>,e>>) -> nagare/core/types/pull<nagare/core/types/chunk<a>,e> */ 
  kk__tailcall: ;
  bool _match_x394 = kk_integer_lte_borrow(n_0,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x394) {
    kk_nagare_core_types__pull_drop(source, _ctx);
    kk_integer_drop(n_0, _ctx);
    kk_box_t _x_x647 = kk_cctx_apply_linear(_acc,(kk_nagare_core_types__pull_box(kk_nagare_core_types__new_PDone(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_nagare_core_types__pull_unbox(_x_x647, KK_OWNED, _ctx);
  }
  if (kk_nagare_core_types__is_PDone(source, _ctx)) {
    kk_integer_drop(n_0, _ctx);
    kk_box_t _x_x648 = kk_cctx_apply_linear(_acc,(kk_nagare_core_types__pull_box(kk_nagare_core_types__new_PDone(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_nagare_core_types__pull_unbox(_x_x648, KK_OWNED, _ctx);
  }
  if (kk_nagare_core_types__is_POutput(source, _ctx)) {
    struct kk_nagare_core_types_POutput* _con_x649 = kk_nagare_core_types__as_POutput(source, _ctx);
    kk_nagare_core_types__chunk out = _con_x649->out;
    kk_nagare_core_types__pull tail = _con_x649->tail;
    kk_reuse_t _ru_x454 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(source, _ctx)) {
      _ru_x454 = (kk_datatype_ptr_reuse(source, _ctx));
    }
    else {
      kk_nagare_core_types__chunk_dup(out, _ctx);
      kk_nagare_core_types__pull_dup(tail, _ctx);
      kk_datatype_ptr_decref(source, _ctx);
    }
    {
      kk_std_core_types__list values = out.values;
      kk_std_core_types__list chunks;
      kk_integer_t _x_x650 = kk_integer_dup(n_0, _ctx); /*int*/
      chunks = kk_nagare_core_pull_listChunkN(values, _x_x650, _ctx); /*list<nagare/core/types/chunk<2613>>*/
      if (kk_std_core_types__is_Nil(chunks, _ctx)) {
        kk_reuse_drop(_ru_x454,kk_context());
        { // tailcall
          source = tail;
          goto kk__tailcall;
        }
      }
      {
        kk_nagare_core_types__pull _trmc_x10256 = kk_datatype_null(); /*nagare/core/types/pull<nagare/core/types/chunk<2613>,2614>*/;
        kk_nagare_core_types__pull _trmc_x10257;
        kk_nagare_core_types__chunk _x_x651 = kk_nagare_core_types__new_Chunk(chunks, _ctx); /*nagare/core/types/chunk<4>*/
        _trmc_x10257 = kk_nagare_core_types__new_POutput(_ru_x454, 0, _x_x651, _trmc_x10256, _ctx); /*nagare/core/types/pull<nagare/core/types/chunk<2613>,2614>*/
        kk_field_addr_t _b_x326_343 = kk_field_addr_create(&kk_nagare_core_types__as_POutput(_trmc_x10257, _ctx)->tail, _ctx); /*@field-addr<nagare/core/types/pull<nagare/core/types/chunk<2613>,2614>>*/;
        { // tailcall
          kk_std_core_types__cctx _x_x652 = kk_cctx_extend_linear(_acc,(kk_nagare_core_types__pull_box(_trmc_x10257, _ctx)),_b_x326_343,kk_context()); /*ctx<0>*/
          source = tail;
          _acc = _x_x652;
          goto kk__tailcall;
        }
      }
    }
  }
  if (kk_nagare_core_types__is_PEval(source, _ctx)) {
    struct kk_nagare_core_types_PEval* _con_x653 = kk_nagare_core_types__as_PEval(source, _ctx);
    kk_function_t next = _con_x653->next;
    kk_reuse_t _ru_x455 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(source, _ctx)) {
      _ru_x455 = (kk_datatype_ptr_reuse(source, _ctx));
    }
    else {
      kk_function_dup(next, _ctx);
      kk_datatype_ptr_decref(source, _ctx);
    }
    kk_box_t _x_x654;
    kk_box_t _x_x655;
    kk_nagare_core_types__pull _x_x656 = kk_nagare_core_types__new_PEval(_ru_x455, 0, kk_nagare_core_pull__new_trmc_pullChunkN_fun657(n_0, next, _ctx), _ctx); /*nagare/core/types/pull<19,20>*/
    _x_x655 = kk_nagare_core_types__pull_box(_x_x656, _ctx); /*-1*/
    _x_x654 = kk_cctx_apply_linear(_acc,_x_x655,kk_context()); /*-1*/
    return kk_nagare_core_types__pull_unbox(_x_x654, KK_OWNED, _ctx);
  }
  {
    struct kk_nagare_core_types_PAcquire* _con_x661 = kk_nagare_core_types__as_PAcquire(source, _ctx);
    kk_function_t acquire = _con_x661->acquire;
    kk_function_t release = _con_x661->release;
    kk_nagare_core_types__pull tail_0 = _con_x661->tail;
    kk_reuse_t _ru_x456 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(source, _ctx)) {
      _ru_x456 = (kk_datatype_ptr_reuse(source, _ctx));
    }
    else {
      kk_function_dup(acquire, _ctx);
      kk_function_dup(release, _ctx);
      kk_nagare_core_types__pull_dup(tail_0, _ctx);
      kk_datatype_ptr_decref(source, _ctx);
    }
    kk_nagare_core_types__pull _trmc_x10258 = kk_datatype_null(); /*nagare/core/types/pull<nagare/core/types/chunk<2613>,2614>*/;
    kk_nagare_core_types__pull _trmc_x10259 = kk_nagare_core_types__new_PAcquire(_ru_x456, 0, acquire, release, _trmc_x10258, _ctx); /*nagare/core/types/pull<nagare/core/types/chunk<2613>,2614>*/;
    kk_field_addr_t _b_x336_352 = kk_field_addr_create(&kk_nagare_core_types__as_PAcquire(_trmc_x10259, _ctx)->tail, _ctx); /*@field-addr<nagare/core/types/pull<nagare/core/types/chunk<2613>,2614>>*/;
    { // tailcall
      kk_std_core_types__cctx _x_x662 = kk_cctx_extend_linear(_acc,(kk_nagare_core_types__pull_box(_trmc_x10259, _ctx)),_b_x336_352,kk_context()); /*ctx<0>*/
      source = tail_0;
      _acc = _x_x662;
      goto kk__tailcall;
    }
  }
}
 
// Re-chunk a pull into fixed-size chunks (last chunk may be smaller).

kk_nagare_core_types__pull kk_nagare_core_pull_pullChunkN(kk_nagare_core_types__pull source_0, kk_integer_t n_1, kk_context_t* _ctx) { /* forall<a,e> (source : nagare/core/types/pull<a,e>, n : int) -> nagare/core/types/pull<nagare/core/types/chunk<a>,e> */ 
  kk_std_core_types__cctx _x_x663 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_nagare_core_pull__trmc_pullChunkN(source_0, n_1, _x_x663, _ctx);
}
 
// monadic lift

kk_nagare_core_types__pull kk_nagare_core_pull__mlift_trmc_unroll_pullUnchunks_10013_10323(kk_nagare_core_types__pull _y_x10309, kk_context_t* _ctx) { /* forall<a,e> (nagare/core/types/pull<nagare/core/types/chunk<a>,e>) -> e nagare/core/types/pull<a,e> */ 
  return kk_nagare_core_pull__unroll_pullUnchunks_10013(_y_x10309, _ctx);
}
 
// Flatten a pull of chunks back into a pull of values.


// lift anonymous function
struct kk_nagare_core_pull__trmc_unroll_pullUnchunks_10013_fun672__t {
  struct kk_function_s _base;
  kk_function_t next;
};
static kk_nagare_core_types__pull kk_nagare_core_pull__trmc_unroll_pullUnchunks_10013_fun672(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_pull__new_trmc_unroll_pullUnchunks_10013_fun672(kk_function_t next, kk_context_t* _ctx) {
  struct kk_nagare_core_pull__trmc_unroll_pullUnchunks_10013_fun672__t* _self = kk_function_alloc_as(struct kk_nagare_core_pull__trmc_unroll_pullUnchunks_10013_fun672__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_pull__trmc_unroll_pullUnchunks_10013_fun672, kk_context());
  _self->next = next;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_core_pull__trmc_unroll_pullUnchunks_10013_fun674__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_core_pull__trmc_unroll_pullUnchunks_10013_fun674(kk_function_t _fself, kk_box_t _b_x366, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_pull__new_trmc_unroll_pullUnchunks_10013_fun674(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_core_pull__trmc_unroll_pullUnchunks_10013_fun674, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_core_pull__trmc_unroll_pullUnchunks_10013_fun674(kk_function_t _fself, kk_box_t _b_x366, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_nagare_core_types__pull _y_x10309_0_392 = kk_nagare_core_types__pull_unbox(_b_x366, KK_OWNED, _ctx); /*nagare/core/types/pull<nagare/core/types/chunk<2773>,2774>*/;
  kk_nagare_core_types__pull _x_x675 = kk_nagare_core_pull__mlift_trmc_unroll_pullUnchunks_10013_10323(_y_x10309_0_392, _ctx); /*nagare/core/types/pull<2773,2774>*/
  return kk_nagare_core_types__pull_box(_x_x675, _ctx);
}
static kk_nagare_core_types__pull kk_nagare_core_pull__trmc_unroll_pullUnchunks_10013_fun672(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_core_pull__trmc_unroll_pullUnchunks_10013_fun672__t* _self = kk_function_as(struct kk_nagare_core_pull__trmc_unroll_pullUnchunks_10013_fun672__t*, _fself, _ctx);
  kk_function_t next = _self->next; /* () -> 2774 nagare/core/types/pull<nagare/core/types/chunk<2773>,2774> */
  kk_drop_match(_self, {kk_function_dup(next, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull x_10369 = kk_function_call(kk_nagare_core_types__pull, (kk_function_t, kk_context_t*), next, (next, _ctx), _ctx); /*nagare/core/types/pull<nagare/core/types/chunk<2773>,2774>*/;
  if (kk_yielding(kk_context())) {
    kk_nagare_core_types__pull_drop(x_10369, _ctx);
    kk_box_t _x_x673 = kk_std_core_hnd_yield_extend(kk_nagare_core_pull__new_trmc_unroll_pullUnchunks_10013_fun674(_ctx), _ctx); /*10001*/
    return kk_nagare_core_types__pull_unbox(_x_x673, KK_OWNED, _ctx);
  }
  {
    return kk_nagare_core_pull__mlift_trmc_unroll_pullUnchunks_10013_10323(x_10369, _ctx);
  }
}

kk_nagare_core_types__pull kk_nagare_core_pull__trmc_unroll_pullUnchunks_10013(kk_nagare_core_types__pull source, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* forall<a,e> (source : nagare/core/types/pull<nagare/core/types/chunk<a>,e>, ctx<nagare/core/types/pull<a,e>>) -> nagare/core/types/pull<a,e> */ 
  kk__tailcall: ;
  if (kk_nagare_core_types__is_PDone(source, _ctx)) {
    kk_box_t _x_x664 = kk_cctx_apply_linear(_acc,(kk_nagare_core_types__pull_box(kk_nagare_core_types__new_PDone(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_nagare_core_types__pull_unbox(_x_x664, KK_OWNED, _ctx);
  }
  if (kk_nagare_core_types__is_POutput(source, _ctx)) {
    struct kk_nagare_core_types_POutput* _con_x665 = kk_nagare_core_types__as_POutput(source, _ctx);
    kk_nagare_core_types__chunk out = _con_x665->out;
    kk_nagare_core_types__pull tail = _con_x665->tail;
    kk_reuse_t _ru_x457 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(source, _ctx)) {
      _ru_x457 = (kk_datatype_ptr_reuse(source, _ctx));
    }
    else {
      kk_nagare_core_types__chunk_dup(out, _ctx);
      kk_nagare_core_types__pull_dup(tail, _ctx);
      kk_datatype_ptr_decref(source, _ctx);
    }
    {
      kk_std_core_types__list chunks = out.values;
      kk_std_core_types__list flat;
      if (kk_std_core_types__is_Nil(chunks, _ctx)) {
        flat = kk_std_core_types__new_Nil(_ctx); /*list<2773>*/
      }
      else {
        flat = kk_nagare_core_pull__unroll_flattenChunks_10005(chunks, _ctx); /*list<2773>*/
      }
      if (kk_std_core_types__is_Nil(flat, _ctx)) {
        kk_reuse_drop(_ru_x457,kk_context());
        { // tailcall
          source = tail;
          goto kk__tailcall;
        }
      }
      {
        kk_nagare_core_types__pull _trmc_x10260 = kk_datatype_null(); /*nagare/core/types/pull<2773,2774>*/;
        kk_nagare_core_types__pull _trmc_x10261;
        kk_nagare_core_types__chunk _x_x666 = kk_nagare_core_types__new_Chunk(flat, _ctx); /*nagare/core/types/chunk<4>*/
        _trmc_x10261 = kk_nagare_core_types__new_POutput(_ru_x457, 0, _x_x666, _trmc_x10260, _ctx); /*nagare/core/types/pull<2773,2774>*/
        kk_field_addr_t _b_x364_379 = kk_field_addr_create(&kk_nagare_core_types__as_POutput(_trmc_x10261, _ctx)->tail, _ctx); /*@field-addr<nagare/core/types/pull<2773,2774>>*/;
        { // tailcall
          kk_std_core_types__cctx _x_x667 = kk_cctx_extend_linear(_acc,(kk_nagare_core_types__pull_box(_trmc_x10261, _ctx)),_b_x364_379,kk_context()); /*ctx<0>*/
          source = tail;
          _acc = _x_x667;
          goto kk__tailcall;
        }
      }
    }
  }
  if (kk_nagare_core_types__is_PEval(source, _ctx)) {
    struct kk_nagare_core_types_PEval* _con_x668 = kk_nagare_core_types__as_PEval(source, _ctx);
    kk_function_t next = _con_x668->next;
    kk_reuse_t _ru_x458 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(source, _ctx)) {
      _ru_x458 = (kk_datatype_ptr_reuse(source, _ctx));
    }
    else {
      kk_function_dup(next, _ctx);
      kk_datatype_ptr_decref(source, _ctx);
    }
    kk_box_t _x_x669;
    kk_box_t _x_x670;
    kk_nagare_core_types__pull _x_x671 = kk_nagare_core_types__new_PEval(_ru_x458, 0, kk_nagare_core_pull__new_trmc_unroll_pullUnchunks_10013_fun672(next, _ctx), _ctx); /*nagare/core/types/pull<19,20>*/
    _x_x670 = kk_nagare_core_types__pull_box(_x_x671, _ctx); /*-1*/
    _x_x669 = kk_cctx_apply_linear(_acc,_x_x670,kk_context()); /*-1*/
    return kk_nagare_core_types__pull_unbox(_x_x669, KK_OWNED, _ctx);
  }
  {
    struct kk_nagare_core_types_PAcquire* _con_x676 = kk_nagare_core_types__as_PAcquire(source, _ctx);
    kk_function_t acquire = _con_x676->acquire;
    kk_function_t release = _con_x676->release;
    kk_nagare_core_types__pull tail_0 = _con_x676->tail;
    kk_reuse_t _ru_x459 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(source, _ctx)) {
      _ru_x459 = (kk_datatype_ptr_reuse(source, _ctx));
    }
    else {
      kk_function_dup(acquire, _ctx);
      kk_function_dup(release, _ctx);
      kk_nagare_core_types__pull_dup(tail_0, _ctx);
      kk_datatype_ptr_decref(source, _ctx);
    }
    kk_nagare_core_types__pull _trmc_x10262 = kk_datatype_null(); /*nagare/core/types/pull<2773,2774>*/;
    kk_nagare_core_types__pull _trmc_x10263 = kk_nagare_core_types__new_PAcquire(_ru_x459, 0, acquire, release, _trmc_x10262, _ctx); /*nagare/core/types/pull<2773,2774>*/;
    kk_field_addr_t _b_x374_388 = kk_field_addr_create(&kk_nagare_core_types__as_PAcquire(_trmc_x10263, _ctx)->tail, _ctx); /*@field-addr<nagare/core/types/pull<2773,2774>>*/;
    { // tailcall
      kk_std_core_types__cctx _x_x677 = kk_cctx_extend_linear(_acc,(kk_nagare_core_types__pull_box(_trmc_x10263, _ctx)),_b_x374_388,kk_context()); /*ctx<0>*/
      source = tail_0;
      _acc = _x_x677;
      goto kk__tailcall;
    }
  }
}
 
// Flatten a pull of chunks back into a pull of values.

kk_nagare_core_types__pull kk_nagare_core_pull__unroll_pullUnchunks_10013(kk_nagare_core_types__pull source_0, kk_context_t* _ctx) { /* forall<a,e> (source : nagare/core/types/pull<nagare/core/types/chunk<a>,e>) -> nagare/core/types/pull<a,e> */ 
  kk_std_core_types__cctx _x_x678 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_nagare_core_pull__trmc_unroll_pullUnchunks_10013(source_0, _x_x678, _ctx);
}

// initialization
void kk_nagare_core_pull__init(kk_context_t* _ctx){
  static bool _kk_initialized = false;
  if (_kk_initialized) return;
  _kk_initialized = true;
  kk_std_core_types__init(_ctx);
  kk_std_core_hnd__init(_ctx);
  kk_std_core_exn__init(_ctx);
  kk_std_core_bool__init(_ctx);
  kk_std_core_order__init(_ctx);
  kk_std_core_char__init(_ctx);
  kk_std_core_int__init(_ctx);
  kk_std_core_vector__init(_ctx);
  kk_std_core_string__init(_ctx);
  kk_std_core_sslice__init(_ctx);
  kk_std_core_list__init(_ctx);
  kk_std_core_maybe__init(_ctx);
  kk_std_core_maybe2__init(_ctx);
  kk_std_core_either__init(_ctx);
  kk_std_core_tuple__init(_ctx);
  kk_std_core_lazy__init(_ctx);
  kk_std_core_show__init(_ctx);
  kk_std_core_debug__init(_ctx);
  kk_std_core_delayed__init(_ctx);
  kk_std_core_console__init(_ctx);
  kk_std_core__init(_ctx);
  kk_nagare_core_types__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
}

// termination
void kk_nagare_core_pull__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_nagare_core_types__done(_ctx);
  kk_std_core__done(_ctx);
  kk_std_core_console__done(_ctx);
  kk_std_core_delayed__done(_ctx);
  kk_std_core_debug__done(_ctx);
  kk_std_core_show__done(_ctx);
  kk_std_core_lazy__done(_ctx);
  kk_std_core_tuple__done(_ctx);
  kk_std_core_either__done(_ctx);
  kk_std_core_maybe2__done(_ctx);
  kk_std_core_maybe__done(_ctx);
  kk_std_core_list__done(_ctx);
  kk_std_core_sslice__done(_ctx);
  kk_std_core_string__done(_ctx);
  kk_std_core_vector__done(_ctx);
  kk_std_core_int__done(_ctx);
  kk_std_core_char__done(_ctx);
  kk_std_core_order__done(_ctx);
  kk_std_core_bool__done(_ctx);
  kk_std_core_exn__done(_ctx);
  kk_std_core_hnd__done(_ctx);
  kk_std_core_types__done(_ctx);
}
