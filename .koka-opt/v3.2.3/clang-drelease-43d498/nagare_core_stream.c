// Koka generated module: nagare/core/stream, koka version: 3.2.3, platform: 64-bit
#include "nagare_core_stream.h"
 
// monadic lift

kk_nagare_core_types__pull kk_nagare_core_stream__mlift_unroll_fromEvalsPull_10000_10417(kk_std_core_types__list tt, kk_box_t _y_x10346, kk_context_t* _ctx) { /* forall<a,e> (tt : list<() -> e a>, a) -> e nagare/core/types/pull<a,e> */ 
  kk_nagare_core_types__chunk _x_x280;
  kk_std_core_types__list _x_x281 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _y_x10346, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<10021>*/
  _x_x280 = kk_nagare_core_types__new_Chunk(_x_x281, _ctx); /*nagare/core/types/chunk<4>*/
  kk_nagare_core_types__pull _x_x282 = kk_nagare_core_stream__unroll_fromEvalsPull_10000(tt, _ctx); /*nagare/core/types/pull<474,475>*/
  return kk_nagare_core_types__new_POutput(kk_reuse_null, 0, _x_x280, _x_x282, _ctx);
}
 
// Create a pull that evaluates thunks lazily, one element per chunk.


// lift anonymous function
struct kk_nagare_core_stream__unroll_fromEvalsPull_10000_fun284__t {
  struct kk_function_s _base;
  kk_box_t _fun_unbox_x1;
  kk_std_core_types__list tt_0;
};
static kk_nagare_core_types__pull kk_nagare_core_stream__unroll_fromEvalsPull_10000_fun284(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_stream__new_unroll_fromEvalsPull_10000_fun284(kk_box_t _fun_unbox_x1, kk_std_core_types__list tt_0, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__unroll_fromEvalsPull_10000_fun284__t* _self = kk_function_alloc_as(struct kk_nagare_core_stream__unroll_fromEvalsPull_10000_fun284__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_stream__unroll_fromEvalsPull_10000_fun284, kk_context());
  _self->_fun_unbox_x1 = _fun_unbox_x1;
  _self->tt_0 = tt_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_core_stream__unroll_fromEvalsPull_10000_fun287__t {
  struct kk_function_s _base;
  kk_std_core_types__list tt_0;
};
static kk_box_t kk_nagare_core_stream__unroll_fromEvalsPull_10000_fun287(kk_function_t _fself, kk_box_t _b_x4, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_stream__new_unroll_fromEvalsPull_10000_fun287(kk_std_core_types__list tt_0, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__unroll_fromEvalsPull_10000_fun287__t* _self = kk_function_alloc_as(struct kk_nagare_core_stream__unroll_fromEvalsPull_10000_fun287__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_stream__unroll_fromEvalsPull_10000_fun287, kk_context());
  _self->tt_0 = tt_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_core_stream__unroll_fromEvalsPull_10000_fun287(kk_function_t _fself, kk_box_t _b_x4, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__unroll_fromEvalsPull_10000_fun287__t* _self = kk_function_as(struct kk_nagare_core_stream__unroll_fromEvalsPull_10000_fun287__t*, _fself, _ctx);
  kk_std_core_types__list tt_0 = _self->tt_0; /* list<() -> 475 474> */
  kk_drop_match(_self, {kk_std_core_types__list_dup(tt_0, _ctx);}, {}, _ctx)
  kk_box_t _y_x10346_0_6 = _b_x4; /*474*/;
  kk_nagare_core_types__pull _x_x288 = kk_nagare_core_stream__mlift_unroll_fromEvalsPull_10000_10417(tt_0, _y_x10346_0_6, _ctx); /*nagare/core/types/pull<474,475>*/
  return kk_nagare_core_types__pull_box(_x_x288, _ctx);
}
static kk_nagare_core_types__pull kk_nagare_core_stream__unroll_fromEvalsPull_10000_fun284(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__unroll_fromEvalsPull_10000_fun284__t* _self = kk_function_as(struct kk_nagare_core_stream__unroll_fromEvalsPull_10000_fun284__t*, _fself, _ctx);
  kk_box_t _fun_unbox_x1 = _self->_fun_unbox_x1; /* 10018 */
  kk_std_core_types__list tt_0 = _self->tt_0; /* list<() -> 475 474> */
  kk_drop_match(_self, {kk_box_dup(_fun_unbox_x1, _ctx);kk_std_core_types__list_dup(tt_0, _ctx);}, {}, _ctx)
  kk_box_t x_10437;
  kk_function_t _x_x285 = kk_function_unbox(_fun_unbox_x1, _ctx); /*() -> 475 2*/
  x_10437 = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), _x_x285, (_x_x285, _ctx), _ctx); /*474*/
  if (kk_yielding(kk_context())) {
    kk_box_drop(x_10437, _ctx);
    kk_box_t _x_x286 = kk_std_core_hnd_yield_extend(kk_nagare_core_stream__new_unroll_fromEvalsPull_10000_fun287(tt_0, _ctx), _ctx); /*10001*/
    return kk_nagare_core_types__pull_unbox(_x_x286, KK_OWNED, _ctx);
  }
  {
    return kk_nagare_core_stream__mlift_unroll_fromEvalsPull_10000_10417(tt_0, x_10437, _ctx);
  }
}

kk_nagare_core_types__pull kk_nagare_core_stream__unroll_fromEvalsPull_10000(kk_std_core_types__list thunks, kk_context_t* _ctx) { /* forall<a,e> (thunks : list<() -> e a>) -> nagare/core/types/pull<a,e> */ 
  if (kk_std_core_types__is_Nil(thunks, _ctx)) {
    return kk_nagare_core_types__new_PDone(_ctx);
  }
  {
    struct kk_std_core_types_Cons* _con_x283 = kk_std_core_types__as_Cons(thunks, _ctx);
    kk_box_t _fun_unbox_x1 = _con_x283->head;
    kk_std_core_types__list tt_0 = _con_x283->tail;
    if kk_likely(kk_datatype_ptr_is_unique(thunks, _ctx)) {
      kk_datatype_ptr_free(thunks, _ctx);
    }
    else {
      kk_box_dup(_fun_unbox_x1, _ctx);
      kk_std_core_types__list_dup(tt_0, _ctx);
      kk_datatype_ptr_decref(thunks, _ctx);
    }
    return kk_nagare_core_types__new_PEval(kk_reuse_null, 0, kk_nagare_core_stream__new_unroll_fromEvalsPull_10000_fun284(_fun_unbox_x1, tt_0, _ctx), _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_nagare_core_stream__mlift_trmc_lift_append_10292_10418_fun289__t {
  struct kk_function_s _base;
  kk_nagare_core_types__pull rightPull;
};
static kk_nagare_core_types__pull kk_nagare_core_stream__mlift_trmc_lift_append_10292_10418_fun289(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_stream__new_mlift_trmc_lift_append_10292_10418_fun289(kk_nagare_core_types__pull rightPull, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__mlift_trmc_lift_append_10292_10418_fun289__t* _self = kk_function_alloc_as(struct kk_nagare_core_stream__mlift_trmc_lift_append_10292_10418_fun289__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_stream__mlift_trmc_lift_append_10292_10418_fun289, kk_context());
  _self->rightPull = rightPull;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_nagare_core_types__pull kk_nagare_core_stream__mlift_trmc_lift_append_10292_10418_fun289(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__mlift_trmc_lift_append_10292_10418_fun289__t* _self = kk_function_as(struct kk_nagare_core_stream__mlift_trmc_lift_append_10292_10418_fun289__t*, _fself, _ctx);
  kk_nagare_core_types__pull rightPull = _self->rightPull; /* nagare/core/types/pull<535,536> */
  kk_drop_match(_self, {kk_nagare_core_types__pull_dup(rightPull, _ctx);}, {}, _ctx)
  return rightPull;
}

kk_nagare_core_types__pull kk_nagare_core_stream__mlift_trmc_lift_append_10292_10418(kk_nagare_core_types__pull rightPull, kk_nagare_core_types__pull _y_x10349, kk_context_t* _ctx) { /* forall<a,e> (rightPull : nagare/core/types/pull<a,e>, nagare/core/types/pull<a,e>) -> e nagare/core/types/pull<a,e> */ 
  return kk_nagare_core_pull__unroll_pullAppend_10007(_y_x10349, kk_nagare_core_stream__new_mlift_trmc_lift_append_10292_10418_fun289(rightPull, _ctx), _ctx);
}
 
// lifted local: @lift-append@10291, append, @spec-x10134
// specialized: nagare/core/pull/@unroll-pullAppend@10007, on parameters @uniq-right@10123, using:
// @uniq-right@10123 = fn(){
//   rightPull;
// }


// lift anonymous function
struct kk_nagare_core_stream__trmc_lift_append_10292_fun297__t {
  struct kk_function_s _base;
  kk_function_t _uniq_next_10129;
  kk_nagare_core_types__pull rightPull_0;
};
static kk_nagare_core_types__pull kk_nagare_core_stream__trmc_lift_append_10292_fun297(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_stream__new_trmc_lift_append_10292_fun297(kk_function_t _uniq_next_10129, kk_nagare_core_types__pull rightPull_0, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__trmc_lift_append_10292_fun297__t* _self = kk_function_alloc_as(struct kk_nagare_core_stream__trmc_lift_append_10292_fun297__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_stream__trmc_lift_append_10292_fun297, kk_context());
  _self->_uniq_next_10129 = _uniq_next_10129;
  _self->rightPull_0 = rightPull_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_core_stream__trmc_lift_append_10292_fun299__t {
  struct kk_function_s _base;
  kk_nagare_core_types__pull rightPull_0;
};
static kk_box_t kk_nagare_core_stream__trmc_lift_append_10292_fun299(kk_function_t _fself, kk_box_t _b_x16, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_stream__new_trmc_lift_append_10292_fun299(kk_nagare_core_types__pull rightPull_0, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__trmc_lift_append_10292_fun299__t* _self = kk_function_alloc_as(struct kk_nagare_core_stream__trmc_lift_append_10292_fun299__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_stream__trmc_lift_append_10292_fun299, kk_context());
  _self->rightPull_0 = rightPull_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_core_stream__trmc_lift_append_10292_fun299(kk_function_t _fself, kk_box_t _b_x16, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__trmc_lift_append_10292_fun299__t* _self = kk_function_as(struct kk_nagare_core_stream__trmc_lift_append_10292_fun299__t*, _fself, _ctx);
  kk_nagare_core_types__pull rightPull_0 = _self->rightPull_0; /* nagare/core/types/pull<535,536> */
  kk_drop_match(_self, {kk_nagare_core_types__pull_dup(rightPull_0, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull _y_x10349_0_42 = kk_nagare_core_types__pull_unbox(_b_x16, KK_OWNED, _ctx); /*nagare/core/types/pull<535,536>*/;
  kk_nagare_core_types__pull _x_x300 = kk_nagare_core_stream__mlift_trmc_lift_append_10292_10418(rightPull_0, _y_x10349_0_42, _ctx); /*nagare/core/types/pull<535,536>*/
  return kk_nagare_core_types__pull_box(_x_x300, _ctx);
}
static kk_nagare_core_types__pull kk_nagare_core_stream__trmc_lift_append_10292_fun297(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__trmc_lift_append_10292_fun297__t* _self = kk_function_as(struct kk_nagare_core_stream__trmc_lift_append_10292_fun297__t*, _fself, _ctx);
  kk_function_t _uniq_next_10129 = _self->_uniq_next_10129; /* () -> 536 nagare/core/types/pull<535,536> */
  kk_nagare_core_types__pull rightPull_0 = _self->rightPull_0; /* nagare/core/types/pull<535,536> */
  kk_drop_match(_self, {kk_function_dup(_uniq_next_10129, _ctx);kk_nagare_core_types__pull_dup(rightPull_0, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull x_10439 = kk_function_call(kk_nagare_core_types__pull, (kk_function_t, kk_context_t*), _uniq_next_10129, (_uniq_next_10129, _ctx), _ctx); /*nagare/core/types/pull<535,536>*/;
  if (kk_yielding(kk_context())) {
    kk_nagare_core_types__pull_drop(x_10439, _ctx);
    kk_box_t _x_x298 = kk_std_core_hnd_yield_extend(kk_nagare_core_stream__new_trmc_lift_append_10292_fun299(rightPull_0, _ctx), _ctx); /*10001*/
    return kk_nagare_core_types__pull_unbox(_x_x298, KK_OWNED, _ctx);
  }
  {
    return kk_nagare_core_stream__mlift_trmc_lift_append_10292_10418(rightPull_0, x_10439, _ctx);
  }
}

kk_nagare_core_types__pull kk_nagare_core_stream__trmc_lift_append_10292(kk_nagare_core_types__pull rightPull_0, kk_nagare_core_types__pull _uniq_left_10122, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* forall<a,e> (rightPull : nagare/core/types/pull<a,e>, nagare/core/types/pull<a,e>, ctx<nagare/core/types/pull<a,e>>) -> nagare/core/types/pull<a,e> */ 
  kk__tailcall: ;
  if (kk_nagare_core_types__is_PDone(_uniq_left_10122, _ctx)) {
    kk_box_t _x_x290 = kk_cctx_apply_linear(_acc,(kk_nagare_core_types__pull_box(rightPull_0, _ctx)),kk_context()); /*-1*/
    return kk_nagare_core_types__pull_unbox(_x_x290, KK_OWNED, _ctx);
  }
  if (kk_nagare_core_types__is_POutput(_uniq_left_10122, _ctx)) {
    struct kk_nagare_core_types_POutput* _con_x291 = kk_nagare_core_types__as_POutput(_uniq_left_10122, _ctx);
    kk_nagare_core_types__chunk _uniq_out_10126 = _con_x291->out;
    kk_nagare_core_types__pull _uniq_tail_10127 = _con_x291->tail;
    kk_reuse_t _ru_x246 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_left_10122, _ctx)) {
      _ru_x246 = (kk_datatype_ptr_reuse(_uniq_left_10122, _ctx));
    }
    else {
      kk_nagare_core_types__chunk_dup(_uniq_out_10126, _ctx);
      kk_nagare_core_types__pull_dup(_uniq_tail_10127, _ctx);
      kk_datatype_ptr_decref(_uniq_left_10122, _ctx);
    }
    kk_nagare_core_types__pull _trmc_x10338 = kk_datatype_null(); /*nagare/core/types/pull<535,536>*/;
    kk_nagare_core_types__pull _trmc_x10339 = kk_nagare_core_types__new_POutput(_ru_x246, 0, _uniq_out_10126, _trmc_x10338, _ctx); /*nagare/core/types/pull<535,536>*/;
    kk_field_addr_t _b_x14_29 = kk_field_addr_create(&kk_nagare_core_types__as_POutput(_trmc_x10339, _ctx)->tail, _ctx); /*@field-addr<nagare/core/types/pull<535,536>>*/;
    { // tailcall
      kk_std_core_types__cctx _x_x292 = kk_cctx_extend_linear(_acc,(kk_nagare_core_types__pull_box(_trmc_x10339, _ctx)),_b_x14_29,kk_context()); /*ctx<0>*/
      _uniq_left_10122 = _uniq_tail_10127;
      _acc = _x_x292;
      goto kk__tailcall;
    }
  }
  if (kk_nagare_core_types__is_PEval(_uniq_left_10122, _ctx)) {
    struct kk_nagare_core_types_PEval* _con_x293 = kk_nagare_core_types__as_PEval(_uniq_left_10122, _ctx);
    kk_function_t _uniq_next_10129 = _con_x293->next;
    kk_reuse_t _ru_x247 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_left_10122, _ctx)) {
      _ru_x247 = (kk_datatype_ptr_reuse(_uniq_left_10122, _ctx));
    }
    else {
      kk_function_dup(_uniq_next_10129, _ctx);
      kk_datatype_ptr_decref(_uniq_left_10122, _ctx);
    }
    kk_box_t _x_x294;
    kk_box_t _x_x295;
    kk_nagare_core_types__pull _x_x296 = kk_nagare_core_types__new_PEval(_ru_x247, 0, kk_nagare_core_stream__new_trmc_lift_append_10292_fun297(_uniq_next_10129, rightPull_0, _ctx), _ctx); /*nagare/core/types/pull<19,20>*/
    _x_x295 = kk_nagare_core_types__pull_box(_x_x296, _ctx); /*-1*/
    _x_x294 = kk_cctx_apply_linear(_acc,_x_x295,kk_context()); /*-1*/
    return kk_nagare_core_types__pull_unbox(_x_x294, KK_OWNED, _ctx);
  }
  {
    struct kk_nagare_core_types_PAcquire* _con_x301 = kk_nagare_core_types__as_PAcquire(_uniq_left_10122, _ctx);
    kk_function_t _uniq_acquire_10131 = _con_x301->acquire;
    kk_function_t _uniq_release_10132 = _con_x301->release;
    kk_nagare_core_types__pull _uniq_tail_0_10133 = _con_x301->tail;
    kk_reuse_t _ru_x248 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_left_10122, _ctx)) {
      _ru_x248 = (kk_datatype_ptr_reuse(_uniq_left_10122, _ctx));
    }
    else {
      kk_function_dup(_uniq_acquire_10131, _ctx);
      kk_function_dup(_uniq_release_10132, _ctx);
      kk_nagare_core_types__pull_dup(_uniq_tail_0_10133, _ctx);
      kk_datatype_ptr_decref(_uniq_left_10122, _ctx);
    }
    kk_nagare_core_types__pull _trmc_x10340 = kk_datatype_null(); /*nagare/core/types/pull<535,536>*/;
    kk_nagare_core_types__pull _trmc_x10341 = kk_nagare_core_types__new_PAcquire(_ru_x248, 0, _uniq_acquire_10131, _uniq_release_10132, _trmc_x10340, _ctx); /*nagare/core/types/pull<535,536>*/;
    kk_field_addr_t _b_x24_38 = kk_field_addr_create(&kk_nagare_core_types__as_PAcquire(_trmc_x10341, _ctx)->tail, _ctx); /*@field-addr<nagare/core/types/pull<535,536>>*/;
    { // tailcall
      kk_std_core_types__cctx _x_x302 = kk_cctx_extend_linear(_acc,(kk_nagare_core_types__pull_box(_trmc_x10341, _ctx)),_b_x24_38,kk_context()); /*ctx<0>*/
      _uniq_left_10122 = _uniq_tail_0_10133;
      _acc = _x_x302;
      goto kk__tailcall;
    }
  }
}
 
// lifted local: @lift-append@10291, append, @spec-x10134
// specialized: nagare/core/pull/@unroll-pullAppend@10007, on parameters @uniq-right@10123, using:
// @uniq-right@10123 = fn(){
//   rightPull;
// }

kk_nagare_core_types__pull kk_nagare_core_stream__lift_append_10292(kk_nagare_core_types__pull rightPull_1, kk_nagare_core_types__pull _uniq_left_10122_0, kk_context_t* _ctx) { /* forall<a,e> (rightPull : nagare/core/types/pull<a,e>, nagare/core/types/pull<a,e>) -> nagare/core/types/pull<a,e> */ 
  kk_std_core_types__cctx _x_x303 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_nagare_core_stream__trmc_lift_append_10292(rightPull_1, _uniq_left_10122_0, _x_x303, _ctx);
}
 
// lifted local: append, @spec-x10121
// specialized: nagare/core/pull/pullAppend, on parameters @uniq-right@10118, using:
// @uniq-right@10118 = fn(){
//   rightPull;
// }

kk_nagare_core_types__pull kk_nagare_core_stream__lift_append_10291(kk_nagare_core_types__pull rightPull, kk_nagare_core_types__pull _uniq_left_10117, kk_context_t* _ctx) { /* forall<a,e> (rightPull : nagare/core/types/pull<a,e>, nagare/core/types/pull<a,e>) -> nagare/core/types/pull<a,e> */ 
  if (kk_nagare_core_types__is_PDone(_uniq_left_10117, _ctx)) {
    return rightPull;
  }
  {
    kk_std_core_types__cctx _x_x304 = kk_cctx_empty(kk_context()); /*ctx<0>*/
    return kk_nagare_core_stream__trmc_lift_append_10292(rightPull, _uniq_left_10117, _x_x304, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_nagare_core_stream__mlift_trmc_lift_unroll_concatList_10001_10294_10419_fun306__t {
  struct kk_function_s _base;
  kk_nagare_core_types__pull rightPull;
};
static kk_nagare_core_types__pull kk_nagare_core_stream__mlift_trmc_lift_unroll_concatList_10001_10294_10419_fun306(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_stream__new_mlift_trmc_lift_unroll_concatList_10001_10294_10419_fun306(kk_nagare_core_types__pull rightPull, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__mlift_trmc_lift_unroll_concatList_10001_10294_10419_fun306__t* _self = kk_function_alloc_as(struct kk_nagare_core_stream__mlift_trmc_lift_unroll_concatList_10001_10294_10419_fun306__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_stream__mlift_trmc_lift_unroll_concatList_10001_10294_10419_fun306, kk_context());
  _self->rightPull = rightPull;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_nagare_core_types__pull kk_nagare_core_stream__mlift_trmc_lift_unroll_concatList_10001_10294_10419_fun306(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__mlift_trmc_lift_unroll_concatList_10001_10294_10419_fun306__t* _self = kk_function_as(struct kk_nagare_core_stream__mlift_trmc_lift_unroll_concatList_10001_10294_10419_fun306__t*, _fself, _ctx);
  kk_nagare_core_types__pull rightPull = _self->rightPull; /* nagare/core/types/pull<604,605> */
  kk_drop_match(_self, {kk_nagare_core_types__pull_dup(rightPull, _ctx);}, {}, _ctx)
  return rightPull;
}

kk_nagare_core_types__pull kk_nagare_core_stream__mlift_trmc_lift_unroll_concatList_10001_10294_10419(kk_nagare_core_types__pull rightPull, kk_nagare_core_types__pull _y_x10354, kk_context_t* _ctx) { /* forall<a,e> (rightPull : nagare/core/types/pull<a,e>, nagare/core/types/pull<a,e>) -> e nagare/core/types/pull<a,e> */ 
  return kk_nagare_core_pull__unroll_pullAppend_10007(_y_x10354, kk_nagare_core_stream__new_mlift_trmc_lift_unroll_concatList_10001_10294_10419_fun306(rightPull, _ctx), _ctx);
}
 
// lifted local: @lift-unroll-concatList@10001@10293, @unroll-concatList@10001, @spec-x10152
// specialized: nagare/core/pull/@unroll-pullAppend@10007, on parameters @uniq-right@10141, using:
// @uniq-right@10141 = fn(){
//   rightPull;
// }


// lift anonymous function
struct kk_nagare_core_stream__trmc_lift_unroll_concatList_10001_10294_fun314__t {
  struct kk_function_s _base;
  kk_function_t _uniq_next_10147;
  kk_nagare_core_types__pull rightPull_0;
};
static kk_nagare_core_types__pull kk_nagare_core_stream__trmc_lift_unroll_concatList_10001_10294_fun314(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_stream__new_trmc_lift_unroll_concatList_10001_10294_fun314(kk_function_t _uniq_next_10147, kk_nagare_core_types__pull rightPull_0, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__trmc_lift_unroll_concatList_10001_10294_fun314__t* _self = kk_function_alloc_as(struct kk_nagare_core_stream__trmc_lift_unroll_concatList_10001_10294_fun314__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_stream__trmc_lift_unroll_concatList_10001_10294_fun314, kk_context());
  _self->_uniq_next_10147 = _uniq_next_10147;
  _self->rightPull_0 = rightPull_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_core_stream__trmc_lift_unroll_concatList_10001_10294_fun316__t {
  struct kk_function_s _base;
  kk_nagare_core_types__pull rightPull_0;
};
static kk_box_t kk_nagare_core_stream__trmc_lift_unroll_concatList_10001_10294_fun316(kk_function_t _fself, kk_box_t _b_x52, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_stream__new_trmc_lift_unroll_concatList_10001_10294_fun316(kk_nagare_core_types__pull rightPull_0, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__trmc_lift_unroll_concatList_10001_10294_fun316__t* _self = kk_function_alloc_as(struct kk_nagare_core_stream__trmc_lift_unroll_concatList_10001_10294_fun316__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_stream__trmc_lift_unroll_concatList_10001_10294_fun316, kk_context());
  _self->rightPull_0 = rightPull_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_core_stream__trmc_lift_unroll_concatList_10001_10294_fun316(kk_function_t _fself, kk_box_t _b_x52, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__trmc_lift_unroll_concatList_10001_10294_fun316__t* _self = kk_function_as(struct kk_nagare_core_stream__trmc_lift_unroll_concatList_10001_10294_fun316__t*, _fself, _ctx);
  kk_nagare_core_types__pull rightPull_0 = _self->rightPull_0; /* nagare/core/types/pull<604,605> */
  kk_drop_match(_self, {kk_nagare_core_types__pull_dup(rightPull_0, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull _y_x10354_0_78 = kk_nagare_core_types__pull_unbox(_b_x52, KK_OWNED, _ctx); /*nagare/core/types/pull<604,605>*/;
  kk_nagare_core_types__pull _x_x317 = kk_nagare_core_stream__mlift_trmc_lift_unroll_concatList_10001_10294_10419(rightPull_0, _y_x10354_0_78, _ctx); /*nagare/core/types/pull<604,605>*/
  return kk_nagare_core_types__pull_box(_x_x317, _ctx);
}
static kk_nagare_core_types__pull kk_nagare_core_stream__trmc_lift_unroll_concatList_10001_10294_fun314(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__trmc_lift_unroll_concatList_10001_10294_fun314__t* _self = kk_function_as(struct kk_nagare_core_stream__trmc_lift_unroll_concatList_10001_10294_fun314__t*, _fself, _ctx);
  kk_function_t _uniq_next_10147 = _self->_uniq_next_10147; /* () -> 605 nagare/core/types/pull<604,605> */
  kk_nagare_core_types__pull rightPull_0 = _self->rightPull_0; /* nagare/core/types/pull<604,605> */
  kk_drop_match(_self, {kk_function_dup(_uniq_next_10147, _ctx);kk_nagare_core_types__pull_dup(rightPull_0, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull x_10443 = kk_function_call(kk_nagare_core_types__pull, (kk_function_t, kk_context_t*), _uniq_next_10147, (_uniq_next_10147, _ctx), _ctx); /*nagare/core/types/pull<604,605>*/;
  if (kk_yielding(kk_context())) {
    kk_nagare_core_types__pull_drop(x_10443, _ctx);
    kk_box_t _x_x315 = kk_std_core_hnd_yield_extend(kk_nagare_core_stream__new_trmc_lift_unroll_concatList_10001_10294_fun316(rightPull_0, _ctx), _ctx); /*10001*/
    return kk_nagare_core_types__pull_unbox(_x_x315, KK_OWNED, _ctx);
  }
  {
    return kk_nagare_core_stream__mlift_trmc_lift_unroll_concatList_10001_10294_10419(rightPull_0, x_10443, _ctx);
  }
}

kk_nagare_core_types__pull kk_nagare_core_stream__trmc_lift_unroll_concatList_10001_10294(kk_nagare_core_types__pull rightPull_0, kk_nagare_core_types__pull _uniq_left_10140, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* forall<a,e> (rightPull : nagare/core/types/pull<a,e>, nagare/core/types/pull<a,e>, ctx<nagare/core/types/pull<a,e>>) -> nagare/core/types/pull<a,e> */ 
  kk__tailcall: ;
  if (kk_nagare_core_types__is_PDone(_uniq_left_10140, _ctx)) {
    kk_box_t _x_x307 = kk_cctx_apply_linear(_acc,(kk_nagare_core_types__pull_box(rightPull_0, _ctx)),kk_context()); /*-1*/
    return kk_nagare_core_types__pull_unbox(_x_x307, KK_OWNED, _ctx);
  }
  if (kk_nagare_core_types__is_POutput(_uniq_left_10140, _ctx)) {
    struct kk_nagare_core_types_POutput* _con_x308 = kk_nagare_core_types__as_POutput(_uniq_left_10140, _ctx);
    kk_nagare_core_types__chunk _uniq_out_10144 = _con_x308->out;
    kk_nagare_core_types__pull _uniq_tail_10145 = _con_x308->tail;
    kk_reuse_t _ru_x249 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_left_10140, _ctx)) {
      _ru_x249 = (kk_datatype_ptr_reuse(_uniq_left_10140, _ctx));
    }
    else {
      kk_nagare_core_types__chunk_dup(_uniq_out_10144, _ctx);
      kk_nagare_core_types__pull_dup(_uniq_tail_10145, _ctx);
      kk_datatype_ptr_decref(_uniq_left_10140, _ctx);
    }
    kk_nagare_core_types__pull _trmc_x10342 = kk_datatype_null(); /*nagare/core/types/pull<604,605>*/;
    kk_nagare_core_types__pull _trmc_x10343 = kk_nagare_core_types__new_POutput(_ru_x249, 0, _uniq_out_10144, _trmc_x10342, _ctx); /*nagare/core/types/pull<604,605>*/;
    kk_field_addr_t _b_x50_65 = kk_field_addr_create(&kk_nagare_core_types__as_POutput(_trmc_x10343, _ctx)->tail, _ctx); /*@field-addr<nagare/core/types/pull<604,605>>*/;
    { // tailcall
      kk_std_core_types__cctx _x_x309 = kk_cctx_extend_linear(_acc,(kk_nagare_core_types__pull_box(_trmc_x10343, _ctx)),_b_x50_65,kk_context()); /*ctx<0>*/
      _uniq_left_10140 = _uniq_tail_10145;
      _acc = _x_x309;
      goto kk__tailcall;
    }
  }
  if (kk_nagare_core_types__is_PEval(_uniq_left_10140, _ctx)) {
    struct kk_nagare_core_types_PEval* _con_x310 = kk_nagare_core_types__as_PEval(_uniq_left_10140, _ctx);
    kk_function_t _uniq_next_10147 = _con_x310->next;
    kk_reuse_t _ru_x250 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_left_10140, _ctx)) {
      _ru_x250 = (kk_datatype_ptr_reuse(_uniq_left_10140, _ctx));
    }
    else {
      kk_function_dup(_uniq_next_10147, _ctx);
      kk_datatype_ptr_decref(_uniq_left_10140, _ctx);
    }
    kk_box_t _x_x311;
    kk_box_t _x_x312;
    kk_nagare_core_types__pull _x_x313 = kk_nagare_core_types__new_PEval(_ru_x250, 0, kk_nagare_core_stream__new_trmc_lift_unroll_concatList_10001_10294_fun314(_uniq_next_10147, rightPull_0, _ctx), _ctx); /*nagare/core/types/pull<19,20>*/
    _x_x312 = kk_nagare_core_types__pull_box(_x_x313, _ctx); /*-1*/
    _x_x311 = kk_cctx_apply_linear(_acc,_x_x312,kk_context()); /*-1*/
    return kk_nagare_core_types__pull_unbox(_x_x311, KK_OWNED, _ctx);
  }
  {
    struct kk_nagare_core_types_PAcquire* _con_x318 = kk_nagare_core_types__as_PAcquire(_uniq_left_10140, _ctx);
    kk_function_t _uniq_acquire_10149 = _con_x318->acquire;
    kk_function_t _uniq_release_10150 = _con_x318->release;
    kk_nagare_core_types__pull _uniq_tail_0_10151 = _con_x318->tail;
    kk_reuse_t _ru_x251 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_left_10140, _ctx)) {
      _ru_x251 = (kk_datatype_ptr_reuse(_uniq_left_10140, _ctx));
    }
    else {
      kk_function_dup(_uniq_acquire_10149, _ctx);
      kk_function_dup(_uniq_release_10150, _ctx);
      kk_nagare_core_types__pull_dup(_uniq_tail_0_10151, _ctx);
      kk_datatype_ptr_decref(_uniq_left_10140, _ctx);
    }
    kk_nagare_core_types__pull _trmc_x10344 = kk_datatype_null(); /*nagare/core/types/pull<604,605>*/;
    kk_nagare_core_types__pull _trmc_x10345 = kk_nagare_core_types__new_PAcquire(_ru_x251, 0, _uniq_acquire_10149, _uniq_release_10150, _trmc_x10344, _ctx); /*nagare/core/types/pull<604,605>*/;
    kk_field_addr_t _b_x60_74 = kk_field_addr_create(&kk_nagare_core_types__as_PAcquire(_trmc_x10345, _ctx)->tail, _ctx); /*@field-addr<nagare/core/types/pull<604,605>>*/;
    { // tailcall
      kk_std_core_types__cctx _x_x319 = kk_cctx_extend_linear(_acc,(kk_nagare_core_types__pull_box(_trmc_x10345, _ctx)),_b_x60_74,kk_context()); /*ctx<0>*/
      _uniq_left_10140 = _uniq_tail_0_10151;
      _acc = _x_x319;
      goto kk__tailcall;
    }
  }
}
 
// lifted local: @lift-unroll-concatList@10001@10293, @unroll-concatList@10001, @spec-x10152
// specialized: nagare/core/pull/@unroll-pullAppend@10007, on parameters @uniq-right@10141, using:
// @uniq-right@10141 = fn(){
//   rightPull;
// }

kk_nagare_core_types__pull kk_nagare_core_stream__lift_unroll_concatList_10001_10294(kk_nagare_core_types__pull rightPull_1, kk_nagare_core_types__pull _uniq_left_10140_0, kk_context_t* _ctx) { /* forall<a,e> (rightPull : nagare/core/types/pull<a,e>, nagare/core/types/pull<a,e>) -> nagare/core/types/pull<a,e> */ 
  kk_std_core_types__cctx _x_x320 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_nagare_core_stream__trmc_lift_unroll_concatList_10001_10294(rightPull_1, _uniq_left_10140_0, _x_x320, _ctx);
}
 
// lifted local: @unroll-concatList@10001, @spec-x10139
// specialized: nagare/core/pull/pullAppend, on parameters @uniq-right@10136, using:
// @uniq-right@10136 = fn(){
//   rightPull;
// }

kk_nagare_core_types__pull kk_nagare_core_stream__lift_unroll_concatList_10001_10293(kk_nagare_core_types__pull rightPull, kk_nagare_core_types__pull _uniq_left_10135, kk_context_t* _ctx) { /* forall<a,e> (rightPull : nagare/core/types/pull<a,e>, nagare/core/types/pull<a,e>) -> nagare/core/types/pull<a,e> */ 
  if (kk_nagare_core_types__is_PDone(_uniq_left_10135, _ctx)) {
    return rightPull;
  }
  {
    kk_std_core_types__cctx _x_x321 = kk_cctx_empty(kk_context()); /*ctx<0>*/
    return kk_nagare_core_stream__trmc_lift_unroll_concatList_10001_10294(rightPull, _uniq_left_10135, _x_x321, _ctx);
  }
}
 
// Concatenate a list of streams into one stream.

kk_nagare_core_types__nstream kk_nagare_core_stream__unroll_concatList_10001(kk_std_core_types__list streams, kk_context_t* _ctx) { /* forall<a,e> (streams : list<nagare/core/types/nstream<a,e>>) -> nagare/core/types/nstream<a,e> */ 
  if (kk_std_core_types__is_Nil(streams, _ctx)) {
    return kk_nagare_core_types__new_Stream(kk_nagare_core_types__new_PDone(_ctx), _ctx);
  }
  {
    struct kk_std_core_types_Cons* _con_x322 = kk_std_core_types__as_Cons(streams, _ctx);
    kk_box_t _box_x79 = _con_x322->head;
    kk_std_core_types__list st = _con_x322->tail;
    kk_nagare_core_types__nstream s = kk_nagare_core_types__nstream_unbox(_box_x79, KK_BORROWED, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(streams, _ctx)) {
      kk_nagare_core_types__nstream_dup(s, _ctx);
      kk_box_drop(_box_x79, _ctx);
      kk_datatype_ptr_free(streams, _ctx);
    }
    else {
      kk_nagare_core_types__nstream_dup(s, _ctx);
      kk_std_core_types__list_dup(st, _ctx);
      kk_datatype_ptr_decref(streams, _ctx);
    }
    kk_nagare_core_types__nstream right_10003 = kk_nagare_core_stream__unroll_concatList_10001(st, _ctx); /*nagare/core/types/nstream<604,605>*/;
    {
      kk_nagare_core_types__pull leftPull = s.step;
      {
        kk_nagare_core_types__pull rightPull = right_10003.step;
        kk_nagare_core_types__pull _x_x323 = kk_nagare_core_stream__lift_unroll_concatList_10001_10293(rightPull, leftPull, _ctx); /*nagare/core/types/pull<604,605>*/
        return kk_nagare_core_types__new_Stream(_x_x323, _ctx);
      }
    }
  }
}
 
// Lazily evaluate an effectful thunk to emit one value.
// The row `e` is whatever effects the thunk performs.


// lift anonymous function
struct kk_nagare_core_stream_eval_fun333__t {
  struct kk_function_s _base;
  kk_function_t thunk;
};
static kk_nagare_core_types__pull kk_nagare_core_stream_eval_fun333(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_stream_new_eval_fun333(kk_function_t thunk, kk_context_t* _ctx) {
  struct kk_nagare_core_stream_eval_fun333__t* _self = kk_function_alloc_as(struct kk_nagare_core_stream_eval_fun333__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_stream_eval_fun333, kk_context());
  _self->thunk = thunk;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_core_stream_eval_fun334__t {
  struct kk_function_s _base;
};
static kk_nagare_core_types__pull kk_nagare_core_stream_eval_fun334(kk_function_t _fself, kk_box_t _y_x10361, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_stream_new_eval_fun334(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_core_stream_eval_fun334, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_nagare_core_types__pull kk_nagare_core_stream_eval_fun334(kk_function_t _fself, kk_box_t _y_x10361, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_nagare_core_types__chunk _x_x335;
  kk_std_core_types__list _x_x336 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _y_x10361, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<10021>*/
  _x_x335 = kk_nagare_core_types__new_Chunk(_x_x336, _ctx); /*nagare/core/types/chunk<4>*/
  return kk_nagare_core_types__new_POutput(kk_reuse_null, 0, _x_x335, kk_nagare_core_types__new_PDone(_ctx), _ctx);
}


// lift anonymous function
struct kk_nagare_core_stream_eval_fun338__t {
  struct kk_function_s _base;
  kk_function_t next_10448;
};
static kk_box_t kk_nagare_core_stream_eval_fun338(kk_function_t _fself, kk_box_t _b_x81, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_stream_new_eval_fun338(kk_function_t next_10448, kk_context_t* _ctx) {
  struct kk_nagare_core_stream_eval_fun338__t* _self = kk_function_alloc_as(struct kk_nagare_core_stream_eval_fun338__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_stream_eval_fun338, kk_context());
  _self->next_10448 = next_10448;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_core_stream_eval_fun338(kk_function_t _fself, kk_box_t _b_x81, kk_context_t* _ctx) {
  struct kk_nagare_core_stream_eval_fun338__t* _self = kk_function_as(struct kk_nagare_core_stream_eval_fun338__t*, _fself, _ctx);
  kk_function_t next_10448 = _self->next_10448; /* (812) -> 813 nagare/core/types/pull<812,813> */
  kk_drop_match(_self, {kk_function_dup(next_10448, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull _x_x339 = kk_function_call(kk_nagare_core_types__pull, (kk_function_t, kk_box_t, kk_context_t*), next_10448, (next_10448, _b_x81, _ctx), _ctx); /*nagare/core/types/pull<812,813>*/
  return kk_nagare_core_types__pull_box(_x_x339, _ctx);
}
static kk_nagare_core_types__pull kk_nagare_core_stream_eval_fun333(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_core_stream_eval_fun333__t* _self = kk_function_as(struct kk_nagare_core_stream_eval_fun333__t*, _fself, _ctx);
  kk_function_t thunk = _self->thunk; /* () -> 813 812 */
  kk_drop_match(_self, {kk_function_dup(thunk, _ctx);}, {}, _ctx)
  kk_box_t x_10447 = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), thunk, (thunk, _ctx), _ctx); /*812*/;
  kk_function_t next_10448 = kk_nagare_core_stream_new_eval_fun334(_ctx); /*(812) -> 813 nagare/core/types/pull<812,813>*/;
  if (kk_yielding(kk_context())) {
    kk_box_drop(x_10447, _ctx);
    kk_box_t _x_x337 = kk_std_core_hnd_yield_extend(kk_nagare_core_stream_new_eval_fun338(next_10448, _ctx), _ctx); /*10001*/
    return kk_nagare_core_types__pull_unbox(_x_x337, KK_OWNED, _ctx);
  }
  {
    return kk_function_call(kk_nagare_core_types__pull, (kk_function_t, kk_box_t, kk_context_t*), next_10448, (next_10448, x_10447, _ctx), _ctx);
  }
}

kk_nagare_core_types__nstream kk_nagare_core_stream_eval(kk_function_t thunk, kk_context_t* _ctx) { /* forall<a,e> (thunk : () -> e a) -> nagare/core/types/nstream<a,e> */ 
  kk_nagare_core_types__pull _x_x332 = kk_nagare_core_types__new_PEval(kk_reuse_null, 0, kk_nagare_core_stream_new_eval_fun333(thunk, _ctx), _ctx); /*nagare/core/types/pull<19,20>*/
  return kk_nagare_core_types__new_Stream(_x_x332, _ctx);
}
 
// Lazily evaluate a list of thunks into a stream of values.


// lift anonymous function
struct kk_nagare_core_stream_evals_fun344__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_core_stream_evals_fun344(kk_function_t _fself, kk_box_t _b_x84, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_stream_new_evals_fun344(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_core_stream_evals_fun344, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_core_stream_evals_fun344(kk_function_t _fself, kk_box_t _b_x84, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_nagare_core_types__pull _c_x10363_86 = kk_nagare_core_types__pull_unbox(_b_x84, KK_OWNED, _ctx); /*nagare/core/types/pull<948,949>*/;
  kk_nagare_core_types__nstream _x_x345 = kk_nagare_core_types__new_Stream(_c_x10363_86, _ctx); /*nagare/core/types/nstream<27,28>*/
  return kk_nagare_core_types__nstream_box(_x_x345, _ctx);
}

kk_nagare_core_types__nstream kk_nagare_core_stream_evals(kk_std_core_types__list thunks, kk_context_t* _ctx) { /* forall<a,e> (thunks : list<() -> e a>) -> nagare/core/types/nstream<a,e> */ 
  kk_nagare_core_types__pull x_10450;
  if (kk_std_core_types__is_Nil(thunks, _ctx)) {
    x_10450 = kk_nagare_core_types__new_PDone(_ctx); /*nagare/core/types/pull<948,949>*/
  }
  else {
    x_10450 = kk_nagare_core_stream__unroll_fromEvalsPull_10000(thunks, _ctx); /*nagare/core/types/pull<948,949>*/
  }
  if (kk_yielding(kk_context())) {
    kk_nagare_core_types__pull_drop(x_10450, _ctx);
    kk_box_t _x_x343 = kk_std_core_hnd_yield_extend(kk_nagare_core_stream_new_evals_fun344(_ctx), _ctx); /*10001*/
    return kk_nagare_core_types__nstream_unbox(_x_x343, KK_OWNED, _ctx);
  }
  {
    return kk_nagare_core_types__new_Stream(x_10450, _ctx);
  }
}


// lift anonymous function
struct kk_nagare_core_stream_iteratePull_fun350__t {
  struct kk_function_s _base;
  kk_function_t f;
  kk_box_t seed;
};
static kk_nagare_core_types__pull kk_nagare_core_stream_iteratePull_fun350(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_stream_new_iteratePull_fun350(kk_function_t f, kk_box_t seed, kk_context_t* _ctx) {
  struct kk_nagare_core_stream_iteratePull_fun350__t* _self = kk_function_alloc_as(struct kk_nagare_core_stream_iteratePull_fun350__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_stream_iteratePull_fun350, kk_context());
  _self->f = f;
  _self->seed = seed;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_nagare_core_types__pull kk_nagare_core_stream_iteratePull_fun350(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_core_stream_iteratePull_fun350__t* _self = kk_function_as(struct kk_nagare_core_stream_iteratePull_fun350__t*, _fself, _ctx);
  kk_function_t f = _self->f; /* (1038) -> 1038 */
  kk_box_t seed = _self->seed; /* 1038 */
  kk_drop_match(_self, {kk_function_dup(f, _ctx);kk_box_dup(seed, _ctx);}, {}, _ctx)
  kk_box_t _x_x351;
  kk_function_t _x_x352 = kk_function_dup(f, _ctx); /*(1038) -> 1038*/
  _x_x351 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x352, (_x_x352, seed, _ctx), _ctx); /*1038*/
  return kk_nagare_core_stream_iteratePull(_x_x351, f, _ctx);
}

kk_nagare_core_types__pull kk_nagare_core_stream_iteratePull(kk_box_t seed, kk_function_t f, kk_context_t* _ctx) { /* forall<a,e> (seed : a, f : (a) -> a) -> div nagare/core/types/pull<a,<div|e>> */ 
  kk_nagare_core_types__chunk _x_x346;
  kk_std_core_types__list _x_x347;
  kk_box_t _x_x348 = kk_box_dup(seed, _ctx); /*1038*/
  _x_x347 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x348, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<10021>*/
  _x_x346 = kk_nagare_core_types__new_Chunk(_x_x347, _ctx); /*nagare/core/types/chunk<4>*/
  kk_nagare_core_types__pull _x_x349 = kk_nagare_core_types__new_PEval(kk_reuse_null, 0, kk_nagare_core_stream_new_iteratePull_fun350(f, seed, _ctx), _ctx); /*nagare/core/types/pull<19,20>*/
  return kk_nagare_core_types__new_POutput(kk_reuse_null, 0, _x_x346, _x_x349, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_nagare_core_stream__mlift_lift_flatMap_10298_10422_fun357__t {
  struct kk_function_s _base;
  kk_std_core_types__list _uniq_xt_10183;
  kk_function_t f;
};
static kk_nagare_core_types__pull kk_nagare_core_stream__mlift_lift_flatMap_10298_10422_fun357(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_stream__new_mlift_lift_flatMap_10298_10422_fun357(kk_std_core_types__list _uniq_xt_10183, kk_function_t f, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__mlift_lift_flatMap_10298_10422_fun357__t* _self = kk_function_alloc_as(struct kk_nagare_core_stream__mlift_lift_flatMap_10298_10422_fun357__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_stream__mlift_lift_flatMap_10298_10422_fun357, kk_context());
  _self->_uniq_xt_10183 = _uniq_xt_10183;
  _self->f = f;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_nagare_core_types__pull kk_nagare_core_stream__mlift_lift_flatMap_10298_10422_fun357(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__mlift_lift_flatMap_10298_10422_fun357__t* _self = kk_function_as(struct kk_nagare_core_stream__mlift_lift_flatMap_10298_10422_fun357__t*, _fself, _ctx);
  kk_std_core_types__list _uniq_xt_10183 = _self->_uniq_xt_10183; /* list<1355> */
  kk_function_t f = _self->f; /* (1355) -> nagare/core/types/nstream<1356,1357> */
  kk_drop_match(_self, {kk_std_core_types__list_dup(_uniq_xt_10183, _ctx);kk_function_dup(f, _ctx);}, {}, _ctx)
  return kk_nagare_core_stream__lift_flatMap_10297(f, _uniq_xt_10183, _ctx);
}

kk_nagare_core_types__pull kk_nagare_core_stream__mlift_lift_flatMap_10298_10422(kk_std_core_types__list _uniq_xt_10183, kk_function_t f, kk_nagare_core_types__pull _y_x10369, kk_context_t* _ctx) { /* forall<a,b,e> (list<a>, f : (a) -> nagare/core/types/nstream<b,e>, nagare/core/types/pull<b,e>) -> e nagare/core/types/pull<b,e> */ 
  return kk_nagare_core_pull__unroll_pullAppend_10007(_y_x10369, kk_nagare_core_stream__new_mlift_lift_flatMap_10298_10422_fun357(_uniq_xt_10183, f, _ctx), _ctx);
}
 
// lifted local: @lift-flatMap@10297, @uniq-left@10057@10168, @lift-flatMap@10296, @lift-flatMap@10295, flatMap, @spec-x10201
// specialized: nagare/core/pull/@unroll-pullAppend@10007, on parameters @uniq-right@10190, using:
// @uniq-right@10190 = fn(){
//   @spec-x10187(@uniq-xt@10183);
// }


// lift anonymous function
struct kk_nagare_core_stream__lift_flatMap_10298_fun361__t {
  struct kk_function_s _base;
  kk_function_t _uniq_next_10196;
  kk_std_core_types__list _uniq_xt_10183_0;
  kk_function_t f_0;
};
static kk_nagare_core_types__pull kk_nagare_core_stream__lift_flatMap_10298_fun361(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_stream__new_lift_flatMap_10298_fun361(kk_function_t _uniq_next_10196, kk_std_core_types__list _uniq_xt_10183_0, kk_function_t f_0, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__lift_flatMap_10298_fun361__t* _self = kk_function_alloc_as(struct kk_nagare_core_stream__lift_flatMap_10298_fun361__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_stream__lift_flatMap_10298_fun361, kk_context());
  _self->_uniq_next_10196 = _uniq_next_10196;
  _self->_uniq_xt_10183_0 = _uniq_xt_10183_0;
  _self->f_0 = f_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_core_stream__lift_flatMap_10298_fun363__t {
  struct kk_function_s _base;
  kk_std_core_types__list _uniq_xt_10183_0;
  kk_function_t f_0;
};
static kk_box_t kk_nagare_core_stream__lift_flatMap_10298_fun363(kk_function_t _fself, kk_box_t _b_x88, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_stream__new_lift_flatMap_10298_fun363(kk_std_core_types__list _uniq_xt_10183_0, kk_function_t f_0, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__lift_flatMap_10298_fun363__t* _self = kk_function_alloc_as(struct kk_nagare_core_stream__lift_flatMap_10298_fun363__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_stream__lift_flatMap_10298_fun363, kk_context());
  _self->_uniq_xt_10183_0 = _uniq_xt_10183_0;
  _self->f_0 = f_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_core_stream__lift_flatMap_10298_fun363(kk_function_t _fself, kk_box_t _b_x88, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__lift_flatMap_10298_fun363__t* _self = kk_function_as(struct kk_nagare_core_stream__lift_flatMap_10298_fun363__t*, _fself, _ctx);
  kk_std_core_types__list _uniq_xt_10183_0 = _self->_uniq_xt_10183_0; /* list<1355> */
  kk_function_t f_0 = _self->f_0; /* (1355) -> nagare/core/types/nstream<1356,1357> */
  kk_drop_match(_self, {kk_std_core_types__list_dup(_uniq_xt_10183_0, _ctx);kk_function_dup(f_0, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull _y_x10369_0_90 = kk_nagare_core_types__pull_unbox(_b_x88, KK_OWNED, _ctx); /*nagare/core/types/pull<1356,1357>*/;
  kk_nagare_core_types__pull _x_x364 = kk_nagare_core_stream__mlift_lift_flatMap_10298_10422(_uniq_xt_10183_0, f_0, _y_x10369_0_90, _ctx); /*nagare/core/types/pull<1356,1357>*/
  return kk_nagare_core_types__pull_box(_x_x364, _ctx);
}
static kk_nagare_core_types__pull kk_nagare_core_stream__lift_flatMap_10298_fun361(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__lift_flatMap_10298_fun361__t* _self = kk_function_as(struct kk_nagare_core_stream__lift_flatMap_10298_fun361__t*, _fself, _ctx);
  kk_function_t _uniq_next_10196 = _self->_uniq_next_10196; /* () -> 1357 nagare/core/types/pull<1356,1357> */
  kk_std_core_types__list _uniq_xt_10183_0 = _self->_uniq_xt_10183_0; /* list<1355> */
  kk_function_t f_0 = _self->f_0; /* (1355) -> nagare/core/types/nstream<1356,1357> */
  kk_drop_match(_self, {kk_function_dup(_uniq_next_10196, _ctx);kk_std_core_types__list_dup(_uniq_xt_10183_0, _ctx);kk_function_dup(f_0, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull x_10454 = kk_function_call(kk_nagare_core_types__pull, (kk_function_t, kk_context_t*), _uniq_next_10196, (_uniq_next_10196, _ctx), _ctx); /*nagare/core/types/pull<1356,1357>*/;
  if (kk_yielding(kk_context())) {
    kk_nagare_core_types__pull_drop(x_10454, _ctx);
    kk_box_t _x_x362 = kk_std_core_hnd_yield_extend(kk_nagare_core_stream__new_lift_flatMap_10298_fun363(_uniq_xt_10183_0, f_0, _ctx), _ctx); /*10001*/
    return kk_nagare_core_types__pull_unbox(_x_x362, KK_OWNED, _ctx);
  }
  {
    return kk_nagare_core_stream__mlift_lift_flatMap_10298_10422(_uniq_xt_10183_0, f_0, x_10454, _ctx);
  }
}

kk_nagare_core_types__pull kk_nagare_core_stream__lift_flatMap_10298(kk_std_core_types__list _uniq_xt_10183_0, kk_function_t f_0, kk_nagare_core_types__pull _uniq_left_10189, kk_context_t* _ctx) { /* forall<a,b,e> (list<a>, f : (a) -> nagare/core/types/nstream<b,e>, nagare/core/types/pull<b,e>) -> nagare/core/types/pull<b,e> */ 
  if (kk_nagare_core_types__is_PDone(_uniq_left_10189, _ctx)) {
    return kk_nagare_core_stream__lift_flatMap_10297(f_0, _uniq_xt_10183_0, _ctx);
  }
  if (kk_nagare_core_types__is_POutput(_uniq_left_10189, _ctx)) {
    struct kk_nagare_core_types_POutput* _con_x358 = kk_nagare_core_types__as_POutput(_uniq_left_10189, _ctx);
    kk_nagare_core_types__chunk _uniq_out_10193 = _con_x358->out;
    kk_nagare_core_types__pull _uniq_tail_10194 = _con_x358->tail;
    kk_reuse_t _ru_x253 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_left_10189, _ctx)) {
      _ru_x253 = (kk_datatype_ptr_reuse(_uniq_left_10189, _ctx));
    }
    else {
      kk_nagare_core_types__chunk_dup(_uniq_out_10193, _ctx);
      kk_nagare_core_types__pull_dup(_uniq_tail_10194, _ctx);
      kk_datatype_ptr_decref(_uniq_left_10189, _ctx);
    }
    kk_nagare_core_types__pull _x_x359 = kk_nagare_core_stream__lift_flatMap_10298(_uniq_xt_10183_0, f_0, _uniq_tail_10194, _ctx); /*nagare/core/types/pull<1356,1357>*/
    return kk_nagare_core_types__new_POutput(_ru_x253, 0, _uniq_out_10193, _x_x359, _ctx);
  }
  if (kk_nagare_core_types__is_PEval(_uniq_left_10189, _ctx)) {
    struct kk_nagare_core_types_PEval* _con_x360 = kk_nagare_core_types__as_PEval(_uniq_left_10189, _ctx);
    kk_function_t _uniq_next_10196 = _con_x360->next;
    kk_reuse_t _ru_x254 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_left_10189, _ctx)) {
      _ru_x254 = (kk_datatype_ptr_reuse(_uniq_left_10189, _ctx));
    }
    else {
      kk_function_dup(_uniq_next_10196, _ctx);
      kk_datatype_ptr_decref(_uniq_left_10189, _ctx);
    }
    return kk_nagare_core_types__new_PEval(_ru_x254, 0, kk_nagare_core_stream__new_lift_flatMap_10298_fun361(_uniq_next_10196, _uniq_xt_10183_0, f_0, _ctx), _ctx);
  }
  {
    struct kk_nagare_core_types_PAcquire* _con_x365 = kk_nagare_core_types__as_PAcquire(_uniq_left_10189, _ctx);
    kk_function_t _uniq_acquire_10198 = _con_x365->acquire;
    kk_function_t _uniq_release_10199 = _con_x365->release;
    kk_nagare_core_types__pull _uniq_tail_0_10200 = _con_x365->tail;
    kk_reuse_t _ru_x255 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_left_10189, _ctx)) {
      _ru_x255 = (kk_datatype_ptr_reuse(_uniq_left_10189, _ctx));
    }
    else {
      kk_function_dup(_uniq_acquire_10198, _ctx);
      kk_function_dup(_uniq_release_10199, _ctx);
      kk_nagare_core_types__pull_dup(_uniq_tail_0_10200, _ctx);
      kk_datatype_ptr_decref(_uniq_left_10189, _ctx);
    }
    kk_nagare_core_types__pull _x_x366 = kk_nagare_core_stream__lift_flatMap_10298(_uniq_xt_10183_0, f_0, _uniq_tail_0_10200, _ctx); /*nagare/core/types/pull<1356,1357>*/
    return kk_nagare_core_types__new_PAcquire(_ru_x255, 0, _uniq_acquire_10198, _uniq_release_10199, _x_x366, _ctx);
  }
}
 
// lifted local: @uniq-left@10057@10168, @lift-flatMap@10296, @lift-flatMap@10295, flatMap, @spec-x10187
// specialized: nagare/core/pull/@unroll-flatMapChunk@10010, on parameters @uniq-f@10179, using:
// @uniq-f@10179 = fn(x: 1355){
//   match ((f(x))) {
//     ((@skip nagare/core/types/Stream((nextStep: (nagare/core/types/pull :: (V, E) -> V)<1356,(1357 :: E)>) : (nagare/core/types/pull :: (V, E) -> V)<a,(e :: E)>) : (nagare/core/types/nstream :: (V, E) -> V)<a,(e :: E)> ) as @pat@0: ((nagare/core/types/nstream :: (V, E) -> V)<1356,(1357 :: E)>))
//        -> nextStep;
//   };
// }

kk_nagare_core_types__pull kk_nagare_core_stream__lift_flatMap_10297(kk_function_t f_1, kk_std_core_types__list _uniq_values_10178, kk_context_t* _ctx) { /* forall<a,b,e> (f : (a) -> nagare/core/types/nstream<b,e>, list<a>) -> nagare/core/types/pull<b,e> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Nil(_uniq_values_10178, _ctx)) {
    kk_function_drop(f_1, _ctx);
    return kk_nagare_core_types__new_PDone(_ctx);
  }
  {
    struct kk_std_core_types_Cons* _con_x367 = kk_std_core_types__as_Cons(_uniq_values_10178, _ctx);
    kk_box_t _uniq_x_10182 = _con_x367->head;
    kk_std_core_types__list _uniq_xt_10183_1 = _con_x367->tail;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_values_10178, _ctx)) {
      kk_datatype_ptr_free(_uniq_values_10178, _ctx);
    }
    else {
      kk_box_dup(_uniq_x_10182, _ctx);
      kk_std_core_types__list_dup(_uniq_xt_10183_1, _ctx);
      kk_datatype_ptr_decref(_uniq_values_10178, _ctx);
    }
    kk_nagare_core_types__pull _uniq_left_10055_10184;
    kk_nagare_core_types__nstream _match_x238;
    kk_function_t _x_x368 = kk_function_dup(f_1, _ctx); /*(1355) -> nagare/core/types/nstream<1356,1357>*/
    _match_x238 = kk_function_call(kk_nagare_core_types__nstream, (kk_function_t, kk_box_t, kk_context_t*), _x_x368, (_x_x368, _uniq_x_10182, _ctx), _ctx); /*nagare/core/types/nstream<1356,1357>*/
    {
      kk_nagare_core_types__pull nextStep = _match_x238.step;
      _uniq_left_10055_10184 = nextStep; /*nagare/core/types/pull<1356,1357>*/
    }
    if (kk_nagare_core_types__is_PDone(_uniq_left_10055_10184, _ctx)) { // tailcall
                                                                        _uniq_values_10178 = _uniq_xt_10183_1;
                                                                        goto kk__tailcall;
    }
    {
      return kk_nagare_core_stream__lift_flatMap_10298(_uniq_xt_10183_1, f_1, _uniq_left_10055_10184, _ctx);
    }
  }
}
 
// monadic lift


// lift anonymous function
struct kk_nagare_core_stream__mlift_lift_flatMap_10299_10423_fun369__t {
  struct kk_function_s _base;
  kk_nagare_core_types__pull _uniq_tail_10163;
  kk_function_t f;
};
static kk_nagare_core_types__pull kk_nagare_core_stream__mlift_lift_flatMap_10299_10423_fun369(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_stream__new_mlift_lift_flatMap_10299_10423_fun369(kk_nagare_core_types__pull _uniq_tail_10163, kk_function_t f, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__mlift_lift_flatMap_10299_10423_fun369__t* _self = kk_function_alloc_as(struct kk_nagare_core_stream__mlift_lift_flatMap_10299_10423_fun369__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_stream__mlift_lift_flatMap_10299_10423_fun369, kk_context());
  _self->_uniq_tail_10163 = _uniq_tail_10163;
  _self->f = f;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_nagare_core_types__pull kk_nagare_core_stream__mlift_lift_flatMap_10299_10423_fun369(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__mlift_lift_flatMap_10299_10423_fun369__t* _self = kk_function_as(struct kk_nagare_core_stream__mlift_lift_flatMap_10299_10423_fun369__t*, _fself, _ctx);
  kk_nagare_core_types__pull _uniq_tail_10163 = _self->_uniq_tail_10163; /* nagare/core/types/pull<1355,1357> */
  kk_function_t f = _self->f; /* (1355) -> nagare/core/types/nstream<1356,1357> */
  kk_drop_match(_self, {kk_nagare_core_types__pull_dup(_uniq_tail_10163, _ctx);kk_function_dup(f, _ctx);}, {}, _ctx)
  return kk_nagare_core_stream__lift_flatMap_10296(f, _uniq_tail_10163, _ctx);
}

kk_nagare_core_types__pull kk_nagare_core_stream__mlift_lift_flatMap_10299_10423(kk_nagare_core_types__pull _uniq_tail_10163, kk_function_t f, kk_nagare_core_types__pull _y_x10373, kk_context_t* _ctx) { /* forall<a,b,e> (nagare/core/types/pull<a,e>, f : (a) -> nagare/core/types/nstream<b,e>, nagare/core/types/pull<b,e>) -> e nagare/core/types/pull<b,e> */ 
  return kk_nagare_core_pull__unroll_pullAppend_10007(_y_x10373, kk_nagare_core_stream__new_mlift_lift_flatMap_10299_10423_fun369(_uniq_tail_10163, f, _ctx), _ctx);
}
 
// monadic lift

kk_nagare_core_types__pull kk_nagare_core_stream__mlift_lift_flatMap_10296_10424(kk_nagare_core_types__pull _uniq_tail_10163_0, kk_function_t f_0, kk_nagare_core_types__pull _c_x10375, kk_context_t* _ctx) { /* forall<a,b,e> (nagare/core/types/pull<a,e>, f : (a) -> nagare/core/types/nstream<b,e>, nagare/core/types/pull<b,e>) -> nagare/core/types/pull<b,e> */ 
  if (kk_nagare_core_types__is_PDone(_c_x10375, _ctx)) {
    return kk_nagare_core_stream__lift_flatMap_10296(f_0, _uniq_tail_10163_0, _ctx);
  }
  {
    return kk_nagare_core_stream__lift_flatMap_10299(_uniq_tail_10163_0, f_0, _c_x10375, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_nagare_core_stream__mlift_lift_flatMap_10296_10425_fun370__t {
  struct kk_function_s _base;
  kk_function_t f_1;
};
static kk_nagare_core_types__pull kk_nagare_core_stream__mlift_lift_flatMap_10296_10425_fun370(kk_function_t _fself, kk_box_t x, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_stream__new_mlift_lift_flatMap_10296_10425_fun370(kk_function_t f_1, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__mlift_lift_flatMap_10296_10425_fun370__t* _self = kk_function_alloc_as(struct kk_nagare_core_stream__mlift_lift_flatMap_10296_10425_fun370__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_stream__mlift_lift_flatMap_10296_10425_fun370, kk_context());
  _self->f_1 = f_1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_nagare_core_types__pull kk_nagare_core_stream__mlift_lift_flatMap_10296_10425_fun370(kk_function_t _fself, kk_box_t x, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__mlift_lift_flatMap_10296_10425_fun370__t* _self = kk_function_as(struct kk_nagare_core_stream__mlift_lift_flatMap_10296_10425_fun370__t*, _fself, _ctx);
  kk_function_t f_1 = _self->f_1; /* (1355) -> nagare/core/types/nstream<1356,1357> */
  kk_drop_match(_self, {kk_function_dup(f_1, _ctx);}, {}, _ctx)
  kk_nagare_core_types__nstream _match_x237 = kk_function_call(kk_nagare_core_types__nstream, (kk_function_t, kk_box_t, kk_context_t*), f_1, (f_1, x, _ctx), _ctx); /*nagare/core/types/nstream<1356,1357>*/;
  {
    kk_nagare_core_types__pull nextStep_0 = _match_x237.step;
    return nextStep_0;
  }
}

kk_nagare_core_types__pull kk_nagare_core_stream__mlift_lift_flatMap_10296_10425(kk_function_t f_1, kk_nagare_core_types__pull _y_x10378, kk_context_t* _ctx) { /* forall<a,b,e> (f : (a) -> nagare/core/types/nstream<b,e>, nagare/core/types/pull<a,e>) -> e nagare/core/types/pull<b,e> */ 
  return kk_nagare_core_pull__unroll_pullFlatMap_10011(_y_x10378, kk_nagare_core_stream__new_mlift_lift_flatMap_10296_10425_fun370(f_1, _ctx), _ctx);
}
 
// lifted local: @lift-flatMap@10296, @lift-flatMap@10295, flatMap, @spec-x10214
// specialized: nagare/core/pull/@unroll-pullAppend@10007, on parameters @uniq-right@10203, using:
// @uniq-right@10203 = fn(){
//   @spec-x10177(@uniq-tail@10163);
// }


// lift anonymous function
struct kk_nagare_core_stream__lift_flatMap_10299_fun374__t {
  struct kk_function_s _base;
  kk_function_t _uniq_next_10209;
  kk_nagare_core_types__pull _uniq_tail_10163_1;
  kk_function_t f_2;
};
static kk_nagare_core_types__pull kk_nagare_core_stream__lift_flatMap_10299_fun374(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_stream__new_lift_flatMap_10299_fun374(kk_function_t _uniq_next_10209, kk_nagare_core_types__pull _uniq_tail_10163_1, kk_function_t f_2, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__lift_flatMap_10299_fun374__t* _self = kk_function_alloc_as(struct kk_nagare_core_stream__lift_flatMap_10299_fun374__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_stream__lift_flatMap_10299_fun374, kk_context());
  _self->_uniq_next_10209 = _uniq_next_10209;
  _self->_uniq_tail_10163_1 = _uniq_tail_10163_1;
  _self->f_2 = f_2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_core_stream__lift_flatMap_10299_fun376__t {
  struct kk_function_s _base;
  kk_nagare_core_types__pull _uniq_tail_10163_1;
  kk_function_t f_2;
};
static kk_box_t kk_nagare_core_stream__lift_flatMap_10299_fun376(kk_function_t _fself, kk_box_t _b_x92, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_stream__new_lift_flatMap_10299_fun376(kk_nagare_core_types__pull _uniq_tail_10163_1, kk_function_t f_2, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__lift_flatMap_10299_fun376__t* _self = kk_function_alloc_as(struct kk_nagare_core_stream__lift_flatMap_10299_fun376__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_stream__lift_flatMap_10299_fun376, kk_context());
  _self->_uniq_tail_10163_1 = _uniq_tail_10163_1;
  _self->f_2 = f_2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_core_stream__lift_flatMap_10299_fun376(kk_function_t _fself, kk_box_t _b_x92, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__lift_flatMap_10299_fun376__t* _self = kk_function_as(struct kk_nagare_core_stream__lift_flatMap_10299_fun376__t*, _fself, _ctx);
  kk_nagare_core_types__pull _uniq_tail_10163_1 = _self->_uniq_tail_10163_1; /* nagare/core/types/pull<1355,1357> */
  kk_function_t f_2 = _self->f_2; /* (1355) -> nagare/core/types/nstream<1356,1357> */
  kk_drop_match(_self, {kk_nagare_core_types__pull_dup(_uniq_tail_10163_1, _ctx);kk_function_dup(f_2, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull _y_x10373_0_94 = kk_nagare_core_types__pull_unbox(_b_x92, KK_OWNED, _ctx); /*nagare/core/types/pull<1356,1357>*/;
  kk_nagare_core_types__pull _x_x377 = kk_nagare_core_stream__mlift_lift_flatMap_10299_10423(_uniq_tail_10163_1, f_2, _y_x10373_0_94, _ctx); /*nagare/core/types/pull<1356,1357>*/
  return kk_nagare_core_types__pull_box(_x_x377, _ctx);
}
static kk_nagare_core_types__pull kk_nagare_core_stream__lift_flatMap_10299_fun374(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__lift_flatMap_10299_fun374__t* _self = kk_function_as(struct kk_nagare_core_stream__lift_flatMap_10299_fun374__t*, _fself, _ctx);
  kk_function_t _uniq_next_10209 = _self->_uniq_next_10209; /* () -> 1357 nagare/core/types/pull<1356,1357> */
  kk_nagare_core_types__pull _uniq_tail_10163_1 = _self->_uniq_tail_10163_1; /* nagare/core/types/pull<1355,1357> */
  kk_function_t f_2 = _self->f_2; /* (1355) -> nagare/core/types/nstream<1356,1357> */
  kk_drop_match(_self, {kk_function_dup(_uniq_next_10209, _ctx);kk_nagare_core_types__pull_dup(_uniq_tail_10163_1, _ctx);kk_function_dup(f_2, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull x_0_10456 = kk_function_call(kk_nagare_core_types__pull, (kk_function_t, kk_context_t*), _uniq_next_10209, (_uniq_next_10209, _ctx), _ctx); /*nagare/core/types/pull<1356,1357>*/;
  if (kk_yielding(kk_context())) {
    kk_nagare_core_types__pull_drop(x_0_10456, _ctx);
    kk_box_t _x_x375 = kk_std_core_hnd_yield_extend(kk_nagare_core_stream__new_lift_flatMap_10299_fun376(_uniq_tail_10163_1, f_2, _ctx), _ctx); /*10001*/
    return kk_nagare_core_types__pull_unbox(_x_x375, KK_OWNED, _ctx);
  }
  {
    return kk_nagare_core_stream__mlift_lift_flatMap_10299_10423(_uniq_tail_10163_1, f_2, x_0_10456, _ctx);
  }
}

kk_nagare_core_types__pull kk_nagare_core_stream__lift_flatMap_10299(kk_nagare_core_types__pull _uniq_tail_10163_1, kk_function_t f_2, kk_nagare_core_types__pull _uniq_left_10202, kk_context_t* _ctx) { /* forall<a,b,e> (nagare/core/types/pull<a,e>, f : (a) -> nagare/core/types/nstream<b,e>, nagare/core/types/pull<b,e>) -> nagare/core/types/pull<b,e> */ 
  if (kk_nagare_core_types__is_PDone(_uniq_left_10202, _ctx)) {
    return kk_nagare_core_stream__lift_flatMap_10296(f_2, _uniq_tail_10163_1, _ctx);
  }
  if (kk_nagare_core_types__is_POutput(_uniq_left_10202, _ctx)) {
    struct kk_nagare_core_types_POutput* _con_x371 = kk_nagare_core_types__as_POutput(_uniq_left_10202, _ctx);
    kk_nagare_core_types__chunk _uniq_out_10206 = _con_x371->out;
    kk_nagare_core_types__pull _uniq_tail_10207 = _con_x371->tail;
    kk_reuse_t _ru_x257 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_left_10202, _ctx)) {
      _ru_x257 = (kk_datatype_ptr_reuse(_uniq_left_10202, _ctx));
    }
    else {
      kk_nagare_core_types__chunk_dup(_uniq_out_10206, _ctx);
      kk_nagare_core_types__pull_dup(_uniq_tail_10207, _ctx);
      kk_datatype_ptr_decref(_uniq_left_10202, _ctx);
    }
    kk_nagare_core_types__pull _x_x372 = kk_nagare_core_stream__lift_flatMap_10299(_uniq_tail_10163_1, f_2, _uniq_tail_10207, _ctx); /*nagare/core/types/pull<1356,1357>*/
    return kk_nagare_core_types__new_POutput(_ru_x257, 0, _uniq_out_10206, _x_x372, _ctx);
  }
  if (kk_nagare_core_types__is_PEval(_uniq_left_10202, _ctx)) {
    struct kk_nagare_core_types_PEval* _con_x373 = kk_nagare_core_types__as_PEval(_uniq_left_10202, _ctx);
    kk_function_t _uniq_next_10209 = _con_x373->next;
    kk_reuse_t _ru_x258 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_left_10202, _ctx)) {
      _ru_x258 = (kk_datatype_ptr_reuse(_uniq_left_10202, _ctx));
    }
    else {
      kk_function_dup(_uniq_next_10209, _ctx);
      kk_datatype_ptr_decref(_uniq_left_10202, _ctx);
    }
    return kk_nagare_core_types__new_PEval(_ru_x258, 0, kk_nagare_core_stream__new_lift_flatMap_10299_fun374(_uniq_next_10209, _uniq_tail_10163_1, f_2, _ctx), _ctx);
  }
  {
    struct kk_nagare_core_types_PAcquire* _con_x378 = kk_nagare_core_types__as_PAcquire(_uniq_left_10202, _ctx);
    kk_function_t _uniq_acquire_10211 = _con_x378->acquire;
    kk_function_t _uniq_release_10212 = _con_x378->release;
    kk_nagare_core_types__pull _uniq_tail_0_10213 = _con_x378->tail;
    kk_reuse_t _ru_x259 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_left_10202, _ctx)) {
      _ru_x259 = (kk_datatype_ptr_reuse(_uniq_left_10202, _ctx));
    }
    else {
      kk_function_dup(_uniq_acquire_10211, _ctx);
      kk_function_dup(_uniq_release_10212, _ctx);
      kk_nagare_core_types__pull_dup(_uniq_tail_0_10213, _ctx);
      kk_datatype_ptr_decref(_uniq_left_10202, _ctx);
    }
    kk_nagare_core_types__pull _x_x379 = kk_nagare_core_stream__lift_flatMap_10299(_uniq_tail_10163_1, f_2, _uniq_tail_0_10213, _ctx); /*nagare/core/types/pull<1356,1357>*/
    return kk_nagare_core_types__new_PAcquire(_ru_x259, 0, _uniq_acquire_10211, _uniq_release_10212, _x_x379, _ctx);
  }
}
 
// lifted local: @lift-flatMap@10295, flatMap, @spec-x10177
// specialized: nagare/core/pull/@unroll-pullFlatMap@10011, on parameters @uniq-f@10159, using:
// @uniq-f@10159 = fn(x: 1355){
//   match ((f(x))) {
//     ((@skip nagare/core/types/Stream((nextStep: (nagare/core/types/pull :: (V, E) -> V)<1356,(1357 :: E)>) : (nagare/core/types/pull :: (V, E) -> V)<a,(e :: E)>) : (nagare/core/types/nstream :: (V, E) -> V)<a,(e :: E)> ) as @pat@0: ((nagare/core/types/nstream :: (V, E) -> V)<1356,(1357 :: E)>))
//        -> nextStep;
//   };
// }


// lift anonymous function
struct kk_nagare_core_stream__lift_flatMap_10296_fun383__t {
  struct kk_function_s _base;
  kk_nagare_core_types__pull _uniq_tail_10163_2;
  kk_function_t f_3;
};
static kk_box_t kk_nagare_core_stream__lift_flatMap_10296_fun383(kk_function_t _fself, kk_box_t _b_x96, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_stream__new_lift_flatMap_10296_fun383(kk_nagare_core_types__pull _uniq_tail_10163_2, kk_function_t f_3, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__lift_flatMap_10296_fun383__t* _self = kk_function_alloc_as(struct kk_nagare_core_stream__lift_flatMap_10296_fun383__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_stream__lift_flatMap_10296_fun383, kk_context());
  _self->_uniq_tail_10163_2 = _uniq_tail_10163_2;
  _self->f_3 = f_3;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_core_stream__lift_flatMap_10296_fun383(kk_function_t _fself, kk_box_t _b_x96, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__lift_flatMap_10296_fun383__t* _self = kk_function_as(struct kk_nagare_core_stream__lift_flatMap_10296_fun383__t*, _fself, _ctx);
  kk_nagare_core_types__pull _uniq_tail_10163_2 = _self->_uniq_tail_10163_2; /* nagare/core/types/pull<1355,1357> */
  kk_function_t f_3 = _self->f_3; /* (1355) -> nagare/core/types/nstream<1356,1357> */
  kk_drop_match(_self, {kk_nagare_core_types__pull_dup(_uniq_tail_10163_2, _ctx);kk_function_dup(f_3, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull _c_x10375_0_101 = kk_nagare_core_types__pull_unbox(_b_x96, KK_OWNED, _ctx); /*nagare/core/types/pull<1356,1357>*/;
  kk_nagare_core_types__pull _x_x384 = kk_nagare_core_stream__mlift_lift_flatMap_10296_10424(_uniq_tail_10163_2, f_3, _c_x10375_0_101, _ctx); /*nagare/core/types/pull<1356,1357>*/
  return kk_nagare_core_types__pull_box(_x_x384, _ctx);
}


// lift anonymous function
struct kk_nagare_core_stream__lift_flatMap_10296_fun386__t {
  struct kk_function_s _base;
  kk_function_t _uniq_next_10172;
  kk_function_t f_3;
};
static kk_nagare_core_types__pull kk_nagare_core_stream__lift_flatMap_10296_fun386(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_stream__new_lift_flatMap_10296_fun386(kk_function_t _uniq_next_10172, kk_function_t f_3, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__lift_flatMap_10296_fun386__t* _self = kk_function_alloc_as(struct kk_nagare_core_stream__lift_flatMap_10296_fun386__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_stream__lift_flatMap_10296_fun386, kk_context());
  _self->_uniq_next_10172 = _uniq_next_10172;
  _self->f_3 = f_3;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_core_stream__lift_flatMap_10296_fun388__t {
  struct kk_function_s _base;
  kk_function_t f_3;
};
static kk_box_t kk_nagare_core_stream__lift_flatMap_10296_fun388(kk_function_t _fself, kk_box_t _b_x98, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_stream__new_lift_flatMap_10296_fun388(kk_function_t f_3, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__lift_flatMap_10296_fun388__t* _self = kk_function_alloc_as(struct kk_nagare_core_stream__lift_flatMap_10296_fun388__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_stream__lift_flatMap_10296_fun388, kk_context());
  _self->f_3 = f_3;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_core_stream__lift_flatMap_10296_fun388(kk_function_t _fself, kk_box_t _b_x98, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__lift_flatMap_10296_fun388__t* _self = kk_function_as(struct kk_nagare_core_stream__lift_flatMap_10296_fun388__t*, _fself, _ctx);
  kk_function_t f_3 = _self->f_3; /* (1355) -> nagare/core/types/nstream<1356,1357> */
  kk_drop_match(_self, {kk_function_dup(f_3, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull _y_x10378_0_102 = kk_nagare_core_types__pull_unbox(_b_x98, KK_OWNED, _ctx); /*nagare/core/types/pull<1355,1357>*/;
  kk_nagare_core_types__pull _x_x389 = kk_nagare_core_stream__mlift_lift_flatMap_10296_10425(f_3, _y_x10378_0_102, _ctx); /*nagare/core/types/pull<1356,1357>*/
  return kk_nagare_core_types__pull_box(_x_x389, _ctx);
}
static kk_nagare_core_types__pull kk_nagare_core_stream__lift_flatMap_10296_fun386(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__lift_flatMap_10296_fun386__t* _self = kk_function_as(struct kk_nagare_core_stream__lift_flatMap_10296_fun386__t*, _fself, _ctx);
  kk_function_t _uniq_next_10172 = _self->_uniq_next_10172; /* () -> 1357 nagare/core/types/pull<1355,1357> */
  kk_function_t f_3 = _self->f_3; /* (1355) -> nagare/core/types/nstream<1356,1357> */
  kk_drop_match(_self, {kk_function_dup(_uniq_next_10172, _ctx);kk_function_dup(f_3, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull x_2_10461 = kk_function_call(kk_nagare_core_types__pull, (kk_function_t, kk_context_t*), _uniq_next_10172, (_uniq_next_10172, _ctx), _ctx); /*nagare/core/types/pull<1355,1357>*/;
  if (kk_yielding(kk_context())) {
    kk_nagare_core_types__pull_drop(x_2_10461, _ctx);
    kk_box_t _x_x387 = kk_std_core_hnd_yield_extend(kk_nagare_core_stream__new_lift_flatMap_10296_fun388(f_3, _ctx), _ctx); /*10001*/
    return kk_nagare_core_types__pull_unbox(_x_x387, KK_OWNED, _ctx);
  }
  {
    return kk_nagare_core_stream__mlift_lift_flatMap_10296_10425(f_3, x_2_10461, _ctx);
  }
}

kk_nagare_core_types__pull kk_nagare_core_stream__lift_flatMap_10296(kk_function_t f_3, kk_nagare_core_types__pull _uniq_source_10158, kk_context_t* _ctx) { /* forall<a,b,e> (f : (a) -> nagare/core/types/nstream<b,e>, nagare/core/types/pull<a,e>) -> nagare/core/types/pull<b,e> */ 
  kk__tailcall: ;
  if (kk_nagare_core_types__is_PDone(_uniq_source_10158, _ctx)) {
    kk_function_drop(f_3, _ctx);
    return kk_nagare_core_types__new_PDone(_ctx);
  }
  if (kk_nagare_core_types__is_POutput(_uniq_source_10158, _ctx)) {
    struct kk_nagare_core_types_POutput* _con_x380 = kk_nagare_core_types__as_POutput(_uniq_source_10158, _ctx);
    kk_nagare_core_types__chunk _uniq_out_10162 = _con_x380->out;
    kk_nagare_core_types__pull _uniq_tail_10163_2 = _con_x380->tail;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_source_10158, _ctx)) {
      kk_datatype_ptr_free(_uniq_source_10158, _ctx);
    }
    else {
      kk_nagare_core_types__chunk_dup(_uniq_out_10162, _ctx);
      kk_nagare_core_types__pull_dup(_uniq_tail_10163_2, _ctx);
      kk_datatype_ptr_decref(_uniq_source_10158, _ctx);
    }
    {
      kk_std_core_types__list _uniq_values_10165 = _uniq_out_10162.values;
      kk_nagare_core_types__pull x_1_10458;
      if (kk_std_core_types__is_Nil(_uniq_values_10165, _ctx)) {
        x_1_10458 = kk_nagare_core_types__new_PDone(_ctx); /*nagare/core/types/pull<1356,1357>*/
      }
      else {
        kk_function_t _x_x381 = kk_function_dup(f_3, _ctx); /*(1355) -> nagare/core/types/nstream<1356,1357>*/
        x_1_10458 = kk_nagare_core_stream__lift_flatMap_10297(_x_x381, _uniq_values_10165, _ctx); /*nagare/core/types/pull<1356,1357>*/
      }
      if (kk_yielding(kk_context())) {
        kk_nagare_core_types__pull_drop(x_1_10458, _ctx);
        kk_box_t _x_x382 = kk_std_core_hnd_yield_extend(kk_nagare_core_stream__new_lift_flatMap_10296_fun383(_uniq_tail_10163_2, f_3, _ctx), _ctx); /*10001*/
        return kk_nagare_core_types__pull_unbox(_x_x382, KK_OWNED, _ctx);
      }
      if (kk_nagare_core_types__is_PDone(x_1_10458, _ctx)) { // tailcall
                                                             _uniq_source_10158 = _uniq_tail_10163_2;
                                                             goto kk__tailcall;
      }
      {
        return kk_nagare_core_stream__lift_flatMap_10299(_uniq_tail_10163_2, f_3, x_1_10458, _ctx);
      }
    }
  }
  if (kk_nagare_core_types__is_PEval(_uniq_source_10158, _ctx)) {
    struct kk_nagare_core_types_PEval* _con_x385 = kk_nagare_core_types__as_PEval(_uniq_source_10158, _ctx);
    kk_function_t _uniq_next_10172 = _con_x385->next;
    kk_reuse_t _ru_x261 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_source_10158, _ctx)) {
      _ru_x261 = (kk_datatype_ptr_reuse(_uniq_source_10158, _ctx));
    }
    else {
      kk_function_dup(_uniq_next_10172, _ctx);
      kk_datatype_ptr_decref(_uniq_source_10158, _ctx);
    }
    return kk_nagare_core_types__new_PEval(_ru_x261, 0, kk_nagare_core_stream__new_lift_flatMap_10296_fun386(_uniq_next_10172, f_3, _ctx), _ctx);
  }
  {
    struct kk_nagare_core_types_PAcquire* _con_x390 = kk_nagare_core_types__as_PAcquire(_uniq_source_10158, _ctx);
    kk_function_t _uniq_acquire_10174 = _con_x390->acquire;
    kk_function_t _uniq_release_10175 = _con_x390->release;
    kk_nagare_core_types__pull _uniq_tail_0_10176 = _con_x390->tail;
    kk_reuse_t _ru_x262 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_source_10158, _ctx)) {
      _ru_x262 = (kk_datatype_ptr_reuse(_uniq_source_10158, _ctx));
    }
    else {
      kk_function_dup(_uniq_acquire_10174, _ctx);
      kk_function_dup(_uniq_release_10175, _ctx);
      kk_nagare_core_types__pull_dup(_uniq_tail_0_10176, _ctx);
      kk_datatype_ptr_decref(_uniq_source_10158, _ctx);
    }
    kk_nagare_core_types__pull _x_x391 = kk_nagare_core_stream__lift_flatMap_10296(f_3, _uniq_tail_0_10176, _ctx); /*nagare/core/types/pull<1356,1357>*/
    return kk_nagare_core_types__new_PAcquire(_ru_x262, 0, _uniq_acquire_10174, _uniq_release_10175, _x_x391, _ctx);
  }
}
 
// lifted local: flatMap, @spec-x10157
// specialized: nagare/core/pull/pullFlatMap, on parameters @uniq-f@10154, using:
// @uniq-f@10154 = fn(x: 1355){
//   match ((f(x))) {
//     ((@skip nagare/core/types/Stream((nextStep: (nagare/core/types/pull :: (V, E) -> V)<1356,(1357 :: E)>) : (nagare/core/types/pull :: (V, E) -> V)<a,(e :: E)>) : (nagare/core/types/nstream :: (V, E) -> V)<a,(e :: E)> ) as @pat@0: ((nagare/core/types/nstream :: (V, E) -> V)<1356,(1357 :: E)>))
//        -> nextStep;
//   };
// }

kk_nagare_core_types__pull kk_nagare_core_stream__lift_flatMap_10295(kk_function_t f, kk_nagare_core_types__pull _uniq_source_10153, kk_context_t* _ctx) { /* forall<a,b,e> (f : (a) -> nagare/core/types/nstream<b,e>, nagare/core/types/pull<a,e>) -> nagare/core/types/pull<b,e> */ 
  if (kk_nagare_core_types__is_PDone(_uniq_source_10153, _ctx)) {
    kk_function_drop(f, _ctx);
    return kk_nagare_core_types__new_PDone(_ctx);
  }
  {
    return kk_nagare_core_stream__lift_flatMap_10296(f, _uniq_source_10153, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_nagare_core_stream__mlift_lift_evalMap_10302_10426_fun393__t {
  struct kk_function_s _base;
  kk_nagare_core_types__pull _uniq_tail_10225;
  kk_function_t f;
};
static kk_nagare_core_types__pull kk_nagare_core_stream__mlift_lift_evalMap_10302_10426_fun393(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_stream__new_mlift_lift_evalMap_10302_10426_fun393(kk_nagare_core_types__pull _uniq_tail_10225, kk_function_t f, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__mlift_lift_evalMap_10302_10426_fun393__t* _self = kk_function_alloc_as(struct kk_nagare_core_stream__mlift_lift_evalMap_10302_10426_fun393__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_stream__mlift_lift_evalMap_10302_10426_fun393, kk_context());
  _self->_uniq_tail_10225 = _uniq_tail_10225;
  _self->f = f;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_nagare_core_types__pull kk_nagare_core_stream__mlift_lift_evalMap_10302_10426_fun393(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__mlift_lift_evalMap_10302_10426_fun393__t* _self = kk_function_as(struct kk_nagare_core_stream__mlift_lift_evalMap_10302_10426_fun393__t*, _fself, _ctx);
  kk_nagare_core_types__pull _uniq_tail_10225 = _self->_uniq_tail_10225; /* nagare/core/types/pull<1418,1420> */
  kk_function_t f = _self->f; /* (1418) -> 1420 1419 */
  kk_drop_match(_self, {kk_nagare_core_types__pull_dup(_uniq_tail_10225, _ctx);kk_function_dup(f, _ctx);}, {}, _ctx)
  return kk_nagare_core_stream__lift_evalMap_10301(f, _uniq_tail_10225, _ctx);
}

kk_nagare_core_types__pull kk_nagare_core_stream__mlift_lift_evalMap_10302_10426(kk_nagare_core_types__pull _uniq_tail_10225, kk_function_t f, kk_nagare_core_types__pull _y_x10382, kk_context_t* _ctx) { /* forall<a,b,e> (nagare/core/types/pull<a,e>, f : (a) -> e b, nagare/core/types/pull<b,e>) -> e nagare/core/types/pull<b,e> */ 
  return kk_nagare_core_pull__unroll_pullAppend_10007(_y_x10382, kk_nagare_core_stream__new_mlift_lift_evalMap_10302_10426_fun393(_uniq_tail_10225, f, _ctx), _ctx);
}
 
// monadic lift

kk_nagare_core_types__pull kk_nagare_core_stream__mlift_lift_evalMap_10301_10427(kk_box_t _y_x10384, kk_context_t* _ctx) { /* forall<a,e> (a) -> e nagare/core/types/pull<a,e> */ 
  kk_nagare_core_types__chunk _x_x394;
  kk_std_core_types__list _x_x395 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _y_x10384, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<10021>*/
  _x_x394 = kk_nagare_core_types__new_Chunk(_x_x395, _ctx); /*nagare/core/types/chunk<4>*/
  return kk_nagare_core_types__new_POutput(kk_reuse_null, 0, _x_x394, kk_nagare_core_types__new_PDone(_ctx), _ctx);
}
 
// monadic lift

kk_nagare_core_types__pull kk_nagare_core_stream__mlift_lift_evalMap_10301_10428(kk_nagare_core_types__pull _uniq_tail_10225_0, kk_function_t f_0, kk_nagare_core_types__pull _c_x10385, kk_context_t* _ctx) { /* forall<a,b,e> (nagare/core/types/pull<a,e>, f : (a) -> e b, nagare/core/types/pull<b,e>) -> nagare/core/types/pull<b,e> */ 
  if (kk_nagare_core_types__is_PDone(_c_x10385, _ctx)) {
    return kk_nagare_core_stream__lift_evalMap_10301(f_0, _uniq_tail_10225_0, _ctx);
  }
  {
    return kk_nagare_core_stream__lift_evalMap_10302(_uniq_tail_10225_0, f_0, _c_x10385, _ctx);
  }
}
 
// monadic lift

kk_nagare_core_types__pull kk_nagare_core_stream__mlift_lift_evalMap_10301_10429(kk_function_t _uniq_f_10221, kk_nagare_core_types__pull _y_x10388, kk_context_t* _ctx) { /* forall<a,b,e> ((a) -> nagare/core/types/pull<b,e>, nagare/core/types/pull<a,e>) -> e nagare/core/types/pull<b,e> */ 
  return kk_nagare_core_pull__unroll_pullFlatMap_10011(_y_x10388, _uniq_f_10221, _ctx);
}
 
// lifted local: @lift-evalMap@10301, @lift-evalMap@10300, evalMap, @spec-x10252
// specialized: nagare/core/pull/@unroll-pullAppend@10007, on parameters @uniq-right@10241, using:
// @uniq-right@10241 = fn(){
//   @spec-x10239(@uniq-tail@10225);
// }


// lift anonymous function
struct kk_nagare_core_stream__lift_evalMap_10302_fun399__t {
  struct kk_function_s _base;
  kk_function_t _uniq_next_10247;
  kk_nagare_core_types__pull _uniq_tail_10225_1;
  kk_function_t f_1;
};
static kk_nagare_core_types__pull kk_nagare_core_stream__lift_evalMap_10302_fun399(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_stream__new_lift_evalMap_10302_fun399(kk_function_t _uniq_next_10247, kk_nagare_core_types__pull _uniq_tail_10225_1, kk_function_t f_1, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__lift_evalMap_10302_fun399__t* _self = kk_function_alloc_as(struct kk_nagare_core_stream__lift_evalMap_10302_fun399__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_stream__lift_evalMap_10302_fun399, kk_context());
  _self->_uniq_next_10247 = _uniq_next_10247;
  _self->_uniq_tail_10225_1 = _uniq_tail_10225_1;
  _self->f_1 = f_1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_core_stream__lift_evalMap_10302_fun401__t {
  struct kk_function_s _base;
  kk_nagare_core_types__pull _uniq_tail_10225_1;
  kk_function_t f_1;
};
static kk_box_t kk_nagare_core_stream__lift_evalMap_10302_fun401(kk_function_t _fself, kk_box_t _b_x104, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_stream__new_lift_evalMap_10302_fun401(kk_nagare_core_types__pull _uniq_tail_10225_1, kk_function_t f_1, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__lift_evalMap_10302_fun401__t* _self = kk_function_alloc_as(struct kk_nagare_core_stream__lift_evalMap_10302_fun401__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_stream__lift_evalMap_10302_fun401, kk_context());
  _self->_uniq_tail_10225_1 = _uniq_tail_10225_1;
  _self->f_1 = f_1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_core_stream__lift_evalMap_10302_fun401(kk_function_t _fself, kk_box_t _b_x104, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__lift_evalMap_10302_fun401__t* _self = kk_function_as(struct kk_nagare_core_stream__lift_evalMap_10302_fun401__t*, _fself, _ctx);
  kk_nagare_core_types__pull _uniq_tail_10225_1 = _self->_uniq_tail_10225_1; /* nagare/core/types/pull<1418,1420> */
  kk_function_t f_1 = _self->f_1; /* (1418) -> 1420 1419 */
  kk_drop_match(_self, {kk_nagare_core_types__pull_dup(_uniq_tail_10225_1, _ctx);kk_function_dup(f_1, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull _y_x10382_0_106 = kk_nagare_core_types__pull_unbox(_b_x104, KK_OWNED, _ctx); /*nagare/core/types/pull<1419,1420>*/;
  kk_nagare_core_types__pull _x_x402 = kk_nagare_core_stream__mlift_lift_evalMap_10302_10426(_uniq_tail_10225_1, f_1, _y_x10382_0_106, _ctx); /*nagare/core/types/pull<1419,1420>*/
  return kk_nagare_core_types__pull_box(_x_x402, _ctx);
}
static kk_nagare_core_types__pull kk_nagare_core_stream__lift_evalMap_10302_fun399(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__lift_evalMap_10302_fun399__t* _self = kk_function_as(struct kk_nagare_core_stream__lift_evalMap_10302_fun399__t*, _fself, _ctx);
  kk_function_t _uniq_next_10247 = _self->_uniq_next_10247; /* () -> 1420 nagare/core/types/pull<1419,1420> */
  kk_nagare_core_types__pull _uniq_tail_10225_1 = _self->_uniq_tail_10225_1; /* nagare/core/types/pull<1418,1420> */
  kk_function_t f_1 = _self->f_1; /* (1418) -> 1420 1419 */
  kk_drop_match(_self, {kk_function_dup(_uniq_next_10247, _ctx);kk_nagare_core_types__pull_dup(_uniq_tail_10225_1, _ctx);kk_function_dup(f_1, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull x_10463 = kk_function_call(kk_nagare_core_types__pull, (kk_function_t, kk_context_t*), _uniq_next_10247, (_uniq_next_10247, _ctx), _ctx); /*nagare/core/types/pull<1419,1420>*/;
  if (kk_yielding(kk_context())) {
    kk_nagare_core_types__pull_drop(x_10463, _ctx);
    kk_box_t _x_x400 = kk_std_core_hnd_yield_extend(kk_nagare_core_stream__new_lift_evalMap_10302_fun401(_uniq_tail_10225_1, f_1, _ctx), _ctx); /*10001*/
    return kk_nagare_core_types__pull_unbox(_x_x400, KK_OWNED, _ctx);
  }
  {
    return kk_nagare_core_stream__mlift_lift_evalMap_10302_10426(_uniq_tail_10225_1, f_1, x_10463, _ctx);
  }
}

kk_nagare_core_types__pull kk_nagare_core_stream__lift_evalMap_10302(kk_nagare_core_types__pull _uniq_tail_10225_1, kk_function_t f_1, kk_nagare_core_types__pull _uniq_left_10240, kk_context_t* _ctx) { /* forall<a,b,e> (nagare/core/types/pull<a,e>, f : (a) -> e b, nagare/core/types/pull<b,e>) -> nagare/core/types/pull<b,e> */ 
  if (kk_nagare_core_types__is_PDone(_uniq_left_10240, _ctx)) {
    return kk_nagare_core_stream__lift_evalMap_10301(f_1, _uniq_tail_10225_1, _ctx);
  }
  if (kk_nagare_core_types__is_POutput(_uniq_left_10240, _ctx)) {
    struct kk_nagare_core_types_POutput* _con_x396 = kk_nagare_core_types__as_POutput(_uniq_left_10240, _ctx);
    kk_nagare_core_types__chunk _uniq_out_10244 = _con_x396->out;
    kk_nagare_core_types__pull _uniq_tail_10245 = _con_x396->tail;
    kk_reuse_t _ru_x263 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_left_10240, _ctx)) {
      _ru_x263 = (kk_datatype_ptr_reuse(_uniq_left_10240, _ctx));
    }
    else {
      kk_nagare_core_types__chunk_dup(_uniq_out_10244, _ctx);
      kk_nagare_core_types__pull_dup(_uniq_tail_10245, _ctx);
      kk_datatype_ptr_decref(_uniq_left_10240, _ctx);
    }
    kk_nagare_core_types__pull _x_x397 = kk_nagare_core_stream__lift_evalMap_10302(_uniq_tail_10225_1, f_1, _uniq_tail_10245, _ctx); /*nagare/core/types/pull<1419,1420>*/
    return kk_nagare_core_types__new_POutput(_ru_x263, 0, _uniq_out_10244, _x_x397, _ctx);
  }
  if (kk_nagare_core_types__is_PEval(_uniq_left_10240, _ctx)) {
    struct kk_nagare_core_types_PEval* _con_x398 = kk_nagare_core_types__as_PEval(_uniq_left_10240, _ctx);
    kk_function_t _uniq_next_10247 = _con_x398->next;
    kk_reuse_t _ru_x264 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_left_10240, _ctx)) {
      _ru_x264 = (kk_datatype_ptr_reuse(_uniq_left_10240, _ctx));
    }
    else {
      kk_function_dup(_uniq_next_10247, _ctx);
      kk_datatype_ptr_decref(_uniq_left_10240, _ctx);
    }
    return kk_nagare_core_types__new_PEval(_ru_x264, 0, kk_nagare_core_stream__new_lift_evalMap_10302_fun399(_uniq_next_10247, _uniq_tail_10225_1, f_1, _ctx), _ctx);
  }
  {
    struct kk_nagare_core_types_PAcquire* _con_x403 = kk_nagare_core_types__as_PAcquire(_uniq_left_10240, _ctx);
    kk_function_t _uniq_acquire_10249 = _con_x403->acquire;
    kk_function_t _uniq_release_10250 = _con_x403->release;
    kk_nagare_core_types__pull _uniq_tail_0_10251 = _con_x403->tail;
    kk_reuse_t _ru_x265 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_left_10240, _ctx)) {
      _ru_x265 = (kk_datatype_ptr_reuse(_uniq_left_10240, _ctx));
    }
    else {
      kk_function_dup(_uniq_acquire_10249, _ctx);
      kk_function_dup(_uniq_release_10250, _ctx);
      kk_nagare_core_types__pull_dup(_uniq_tail_0_10251, _ctx);
      kk_datatype_ptr_decref(_uniq_left_10240, _ctx);
    }
    kk_nagare_core_types__pull _x_x404 = kk_nagare_core_stream__lift_evalMap_10302(_uniq_tail_10225_1, f_1, _uniq_tail_0_10251, _ctx); /*nagare/core/types/pull<1419,1420>*/
    return kk_nagare_core_types__new_PAcquire(_ru_x265, 0, _uniq_acquire_10249, _uniq_release_10250, _x_x404, _ctx);
  }
}
 
// lifted local: @lift-evalMap@10300, evalMap, @spec-x10239
// specialized: nagare/core/pull/@unroll-pullFlatMap@10011, on parameters @uniq-f@10221, using:
// @uniq-f@10221 = fn(x: 1418){
//   nagare/core/types/PEval<a,(e :: E)>((fn<(e :: E)>(){
//     (nagare/core/types/POutput<a,(e :: E)>((nagare/core/types/Chunk<a>((std/core/types/Cons<a>((f(x)), (std/core/types/Nil<a>))))), (nagare/core/types/PDone<a,(e :: E)>)));
//   }));
// }


// lift anonymous function
struct kk_nagare_core_stream__lift_evalMap_10301_fun405__t {
  struct kk_function_s _base;
  kk_function_t f_2;
};
static kk_nagare_core_types__pull kk_nagare_core_stream__lift_evalMap_10301_fun405(kk_function_t _fself, kk_box_t x_0, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_stream__new_lift_evalMap_10301_fun405(kk_function_t f_2, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__lift_evalMap_10301_fun405__t* _self = kk_function_alloc_as(struct kk_nagare_core_stream__lift_evalMap_10301_fun405__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_stream__lift_evalMap_10301_fun405, kk_context());
  _self->f_2 = f_2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_core_stream__lift_evalMap_10301_fun406__t {
  struct kk_function_s _base;
  kk_function_t f_2;
  kk_box_t x_0;
};
static kk_nagare_core_types__pull kk_nagare_core_stream__lift_evalMap_10301_fun406(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_stream__new_lift_evalMap_10301_fun406(kk_function_t f_2, kk_box_t x_0, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__lift_evalMap_10301_fun406__t* _self = kk_function_alloc_as(struct kk_nagare_core_stream__lift_evalMap_10301_fun406__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_stream__lift_evalMap_10301_fun406, kk_context());
  _self->f_2 = f_2;
  _self->x_0 = x_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_core_stream__lift_evalMap_10301_fun408__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_core_stream__lift_evalMap_10301_fun408(kk_function_t _fself, kk_box_t _b_x108, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_stream__new_lift_evalMap_10301_fun408(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_core_stream__lift_evalMap_10301_fun408, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_core_stream__lift_evalMap_10301_fun408(kk_function_t _fself, kk_box_t _b_x108, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_nagare_core_types__pull _x_x409 = kk_nagare_core_stream__mlift_lift_evalMap_10301_10427(_b_x108, _ctx); /*nagare/core/types/pull<1419,1420>*/
  return kk_nagare_core_types__pull_box(_x_x409, _ctx);
}
static kk_nagare_core_types__pull kk_nagare_core_stream__lift_evalMap_10301_fun406(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__lift_evalMap_10301_fun406__t* _self = kk_function_as(struct kk_nagare_core_stream__lift_evalMap_10301_fun406__t*, _fself, _ctx);
  kk_function_t f_2 = _self->f_2; /* (1418) -> 1420 1419 */
  kk_box_t x_0 = _self->x_0; /* 1418 */
  kk_drop_match(_self, {kk_function_dup(f_2, _ctx);kk_box_dup(x_0, _ctx);}, {}, _ctx)
  kk_box_t x_1_10465 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), f_2, (f_2, x_0, _ctx), _ctx); /*1419*/;
  if (kk_yielding(kk_context())) {
    kk_box_drop(x_1_10465, _ctx);
    kk_box_t _x_x407 = kk_std_core_hnd_yield_extend(kk_nagare_core_stream__new_lift_evalMap_10301_fun408(_ctx), _ctx); /*10001*/
    return kk_nagare_core_types__pull_unbox(_x_x407, KK_OWNED, _ctx);
  }
  {
    return kk_nagare_core_stream__mlift_lift_evalMap_10301_10427(x_1_10465, _ctx);
  }
}
static kk_nagare_core_types__pull kk_nagare_core_stream__lift_evalMap_10301_fun405(kk_function_t _fself, kk_box_t x_0, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__lift_evalMap_10301_fun405__t* _self = kk_function_as(struct kk_nagare_core_stream__lift_evalMap_10301_fun405__t*, _fself, _ctx);
  kk_function_t f_2 = _self->f_2; /* (1418) -> 1420 1419 */
  kk_drop_match(_self, {kk_function_dup(f_2, _ctx);}, {}, _ctx)
  return kk_nagare_core_types__new_PEval(kk_reuse_null, 0, kk_nagare_core_stream__new_lift_evalMap_10301_fun406(f_2, x_0, _ctx), _ctx);
}


// lift anonymous function
struct kk_nagare_core_stream__lift_evalMap_10301_fun412__t {
  struct kk_function_s _base;
  kk_nagare_core_types__pull _uniq_tail_10225_2;
  kk_function_t f_2;
};
static kk_box_t kk_nagare_core_stream__lift_evalMap_10301_fun412(kk_function_t _fself, kk_box_t _b_x112, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_stream__new_lift_evalMap_10301_fun412(kk_nagare_core_types__pull _uniq_tail_10225_2, kk_function_t f_2, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__lift_evalMap_10301_fun412__t* _self = kk_function_alloc_as(struct kk_nagare_core_stream__lift_evalMap_10301_fun412__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_stream__lift_evalMap_10301_fun412, kk_context());
  _self->_uniq_tail_10225_2 = _uniq_tail_10225_2;
  _self->f_2 = f_2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_core_stream__lift_evalMap_10301_fun412(kk_function_t _fself, kk_box_t _b_x112, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__lift_evalMap_10301_fun412__t* _self = kk_function_as(struct kk_nagare_core_stream__lift_evalMap_10301_fun412__t*, _fself, _ctx);
  kk_nagare_core_types__pull _uniq_tail_10225_2 = _self->_uniq_tail_10225_2; /* nagare/core/types/pull<1418,1420> */
  kk_function_t f_2 = _self->f_2; /* (1418) -> 1420 1419 */
  kk_drop_match(_self, {kk_nagare_core_types__pull_dup(_uniq_tail_10225_2, _ctx);kk_function_dup(f_2, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull _c_x10385_0_117 = kk_nagare_core_types__pull_unbox(_b_x112, KK_OWNED, _ctx); /*nagare/core/types/pull<1419,1420>*/;
  kk_nagare_core_types__pull _x_x413 = kk_nagare_core_stream__mlift_lift_evalMap_10301_10428(_uniq_tail_10225_2, f_2, _c_x10385_0_117, _ctx); /*nagare/core/types/pull<1419,1420>*/
  return kk_nagare_core_types__pull_box(_x_x413, _ctx);
}


// lift anonymous function
struct kk_nagare_core_stream__lift_evalMap_10301_fun415__t {
  struct kk_function_s _base;
  kk_function_t _uniq_f_10221_0;
  kk_function_t _uniq_next_10234;
};
static kk_nagare_core_types__pull kk_nagare_core_stream__lift_evalMap_10301_fun415(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_stream__new_lift_evalMap_10301_fun415(kk_function_t _uniq_f_10221_0, kk_function_t _uniq_next_10234, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__lift_evalMap_10301_fun415__t* _self = kk_function_alloc_as(struct kk_nagare_core_stream__lift_evalMap_10301_fun415__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_stream__lift_evalMap_10301_fun415, kk_context());
  _self->_uniq_f_10221_0 = _uniq_f_10221_0;
  _self->_uniq_next_10234 = _uniq_next_10234;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_core_stream__lift_evalMap_10301_fun417__t {
  struct kk_function_s _base;
  kk_function_t _uniq_f_10221_0;
};
static kk_box_t kk_nagare_core_stream__lift_evalMap_10301_fun417(kk_function_t _fself, kk_box_t _b_x114, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_stream__new_lift_evalMap_10301_fun417(kk_function_t _uniq_f_10221_0, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__lift_evalMap_10301_fun417__t* _self = kk_function_alloc_as(struct kk_nagare_core_stream__lift_evalMap_10301_fun417__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_stream__lift_evalMap_10301_fun417, kk_context());
  _self->_uniq_f_10221_0 = _uniq_f_10221_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_core_stream__lift_evalMap_10301_fun417(kk_function_t _fself, kk_box_t _b_x114, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__lift_evalMap_10301_fun417__t* _self = kk_function_as(struct kk_nagare_core_stream__lift_evalMap_10301_fun417__t*, _fself, _ctx);
  kk_function_t _uniq_f_10221_0 = _self->_uniq_f_10221_0; /* (1418) -> nagare/core/types/pull<1419,1420> */
  kk_drop_match(_self, {kk_function_dup(_uniq_f_10221_0, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull _y_x10388_0_118 = kk_nagare_core_types__pull_unbox(_b_x114, KK_OWNED, _ctx); /*nagare/core/types/pull<1418,1420>*/;
  kk_nagare_core_types__pull _x_x418 = kk_nagare_core_stream__mlift_lift_evalMap_10301_10429(_uniq_f_10221_0, _y_x10388_0_118, _ctx); /*nagare/core/types/pull<1419,1420>*/
  return kk_nagare_core_types__pull_box(_x_x418, _ctx);
}
static kk_nagare_core_types__pull kk_nagare_core_stream__lift_evalMap_10301_fun415(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__lift_evalMap_10301_fun415__t* _self = kk_function_as(struct kk_nagare_core_stream__lift_evalMap_10301_fun415__t*, _fself, _ctx);
  kk_function_t _uniq_f_10221_0 = _self->_uniq_f_10221_0; /* (1418) -> nagare/core/types/pull<1419,1420> */
  kk_function_t _uniq_next_10234 = _self->_uniq_next_10234; /* () -> 1420 nagare/core/types/pull<1418,1420> */
  kk_drop_match(_self, {kk_function_dup(_uniq_f_10221_0, _ctx);kk_function_dup(_uniq_next_10234, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull x_3_10470 = kk_function_call(kk_nagare_core_types__pull, (kk_function_t, kk_context_t*), _uniq_next_10234, (_uniq_next_10234, _ctx), _ctx); /*nagare/core/types/pull<1418,1420>*/;
  if (kk_yielding(kk_context())) {
    kk_nagare_core_types__pull_drop(x_3_10470, _ctx);
    kk_box_t _x_x416 = kk_std_core_hnd_yield_extend(kk_nagare_core_stream__new_lift_evalMap_10301_fun417(_uniq_f_10221_0, _ctx), _ctx); /*10001*/
    return kk_nagare_core_types__pull_unbox(_x_x416, KK_OWNED, _ctx);
  }
  {
    return kk_nagare_core_stream__mlift_lift_evalMap_10301_10429(_uniq_f_10221_0, x_3_10470, _ctx);
  }
}

kk_nagare_core_types__pull kk_nagare_core_stream__lift_evalMap_10301(kk_function_t f_2, kk_nagare_core_types__pull _uniq_source_10220, kk_context_t* _ctx) { /* forall<a,b,e> (f : (a) -> e b, nagare/core/types/pull<a,e>) -> nagare/core/types/pull<b,e> */ 
  kk__tailcall: ;
  kk_function_t _uniq_f_10221_0;
  kk_function_dup(f_2, _ctx);
  _uniq_f_10221_0 = kk_nagare_core_stream__new_lift_evalMap_10301_fun405(f_2, _ctx); /*(x : 1418) -> nagare/core/types/pull<1419,1420>*/
  if (kk_nagare_core_types__is_PDone(_uniq_source_10220, _ctx)) {
    kk_function_drop(f_2, _ctx);
    kk_function_drop(_uniq_f_10221_0, _ctx);
    return kk_nagare_core_types__new_PDone(_ctx);
  }
  if (kk_nagare_core_types__is_POutput(_uniq_source_10220, _ctx)) {
    struct kk_nagare_core_types_POutput* _con_x410 = kk_nagare_core_types__as_POutput(_uniq_source_10220, _ctx);
    kk_nagare_core_types__chunk _uniq_out_10224 = _con_x410->out;
    kk_nagare_core_types__pull _uniq_tail_10225_2 = _con_x410->tail;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_source_10220, _ctx)) {
      kk_datatype_ptr_free(_uniq_source_10220, _ctx);
    }
    else {
      kk_nagare_core_types__chunk_dup(_uniq_out_10224, _ctx);
      kk_nagare_core_types__pull_dup(_uniq_tail_10225_2, _ctx);
      kk_datatype_ptr_decref(_uniq_source_10220, _ctx);
    }
    {
      kk_std_core_types__list _uniq_values_10227 = _uniq_out_10224.values;
      kk_nagare_core_types__pull x_2_10467;
      if (kk_std_core_types__is_Nil(_uniq_values_10227, _ctx)) {
        kk_function_drop(_uniq_f_10221_0, _ctx);
        x_2_10467 = kk_nagare_core_types__new_PDone(_ctx); /*nagare/core/types/pull<1419,1420>*/
      }
      else {
        x_2_10467 = kk_nagare_core_pull__unroll_flatMapChunk_10010(_uniq_values_10227, _uniq_f_10221_0, _ctx); /*nagare/core/types/pull<1419,1420>*/
      }
      if (kk_yielding(kk_context())) {
        kk_nagare_core_types__pull_drop(x_2_10467, _ctx);
        kk_box_t _x_x411 = kk_std_core_hnd_yield_extend(kk_nagare_core_stream__new_lift_evalMap_10301_fun412(_uniq_tail_10225_2, f_2, _ctx), _ctx); /*10001*/
        return kk_nagare_core_types__pull_unbox(_x_x411, KK_OWNED, _ctx);
      }
      if (kk_nagare_core_types__is_PDone(x_2_10467, _ctx)) { // tailcall
                                                             _uniq_source_10220 = _uniq_tail_10225_2;
                                                             goto kk__tailcall;
      }
      {
        return kk_nagare_core_stream__lift_evalMap_10302(_uniq_tail_10225_2, f_2, x_2_10467, _ctx);
      }
    }
  }
  if (kk_nagare_core_types__is_PEval(_uniq_source_10220, _ctx)) {
    struct kk_nagare_core_types_PEval* _con_x414 = kk_nagare_core_types__as_PEval(_uniq_source_10220, _ctx);
    kk_function_t _uniq_next_10234 = _con_x414->next;
    kk_function_drop(f_2, _ctx);
    kk_reuse_t _ru_x267 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_source_10220, _ctx)) {
      _ru_x267 = (kk_datatype_ptr_reuse(_uniq_source_10220, _ctx));
    }
    else {
      kk_function_dup(_uniq_next_10234, _ctx);
      kk_datatype_ptr_decref(_uniq_source_10220, _ctx);
    }
    return kk_nagare_core_types__new_PEval(_ru_x267, 0, kk_nagare_core_stream__new_lift_evalMap_10301_fun415(_uniq_f_10221_0, _uniq_next_10234, _ctx), _ctx);
  }
  {
    struct kk_nagare_core_types_PAcquire* _con_x419 = kk_nagare_core_types__as_PAcquire(_uniq_source_10220, _ctx);
    kk_function_t _uniq_acquire_10236 = _con_x419->acquire;
    kk_function_t _uniq_release_10237 = _con_x419->release;
    kk_nagare_core_types__pull _uniq_tail_0_10238 = _con_x419->tail;
    kk_reuse_t _ru_x268 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_source_10220, _ctx)) {
      _ru_x268 = (kk_datatype_ptr_reuse(_uniq_source_10220, _ctx));
    }
    else {
      kk_function_dup(_uniq_acquire_10236, _ctx);
      kk_function_dup(_uniq_release_10237, _ctx);
      kk_nagare_core_types__pull_dup(_uniq_tail_0_10238, _ctx);
      kk_datatype_ptr_decref(_uniq_source_10220, _ctx);
    }
    kk_function_drop(_uniq_f_10221_0, _ctx);
    kk_nagare_core_types__pull _x_x420 = kk_nagare_core_stream__lift_evalMap_10301(f_2, _uniq_tail_0_10238, _ctx); /*nagare/core/types/pull<1419,1420>*/
    return kk_nagare_core_types__new_PAcquire(_ru_x268, 0, _uniq_acquire_10236, _uniq_release_10237, _x_x420, _ctx);
  }
}
 
// lifted local: evalMap, @spec-x10219
// specialized: nagare/core/pull/pullFlatMap, on parameters @uniq-f@10216, using:
// @uniq-f@10216 = fn(x: 1418){
//   nagare/core/types/PEval<a,(e :: E)>((fn<(e :: E)>(){
//     (nagare/core/types/POutput<a,(e :: E)>((nagare/core/types/Chunk<a>((std/core/types/Cons<a>((f(x)), (std/core/types/Nil<a>))))), (nagare/core/types/PDone<a,(e :: E)>)));
//   }));
// }

kk_nagare_core_types__pull kk_nagare_core_stream__lift_evalMap_10300(kk_function_t f, kk_nagare_core_types__pull _uniq_source_10215, kk_context_t* _ctx) { /* forall<a,b,e> (f : (a) -> e b, nagare/core/types/pull<a,e>) -> nagare/core/types/pull<b,e> */ 
  if (kk_nagare_core_types__is_PDone(_uniq_source_10215, _ctx)) {
    kk_function_drop(f, _ctx);
    return kk_nagare_core_types__new_PDone(_ctx);
  }
  {
    return kk_nagare_core_stream__lift_evalMap_10301(f, _uniq_source_10215, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_nagare_core_stream__mlift_lift_evalTap_10305_10430_fun422__t {
  struct kk_function_s _base;
  kk_nagare_core_types__pull _uniq_tail_10263;
  kk_function_t f;
};
static kk_nagare_core_types__pull kk_nagare_core_stream__mlift_lift_evalTap_10305_10430_fun422(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_stream__new_mlift_lift_evalTap_10305_10430_fun422(kk_nagare_core_types__pull _uniq_tail_10263, kk_function_t f, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__mlift_lift_evalTap_10305_10430_fun422__t* _self = kk_function_alloc_as(struct kk_nagare_core_stream__mlift_lift_evalTap_10305_10430_fun422__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_stream__mlift_lift_evalTap_10305_10430_fun422, kk_context());
  _self->_uniq_tail_10263 = _uniq_tail_10263;
  _self->f = f;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_nagare_core_types__pull kk_nagare_core_stream__mlift_lift_evalTap_10305_10430_fun422(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__mlift_lift_evalTap_10305_10430_fun422__t* _self = kk_function_as(struct kk_nagare_core_stream__mlift_lift_evalTap_10305_10430_fun422__t*, _fself, _ctx);
  kk_nagare_core_types__pull _uniq_tail_10263 = _self->_uniq_tail_10263; /* nagare/core/types/pull<1477,1478> */
  kk_function_t f = _self->f; /* (1477) -> 1478 () */
  kk_drop_match(_self, {kk_nagare_core_types__pull_dup(_uniq_tail_10263, _ctx);kk_function_dup(f, _ctx);}, {}, _ctx)
  return kk_nagare_core_stream__lift_evalTap_10304(f, _uniq_tail_10263, _ctx);
}

kk_nagare_core_types__pull kk_nagare_core_stream__mlift_lift_evalTap_10305_10430(kk_nagare_core_types__pull _uniq_tail_10263, kk_function_t f, kk_nagare_core_types__pull _y_x10392, kk_context_t* _ctx) { /* forall<a,e> (nagare/core/types/pull<a,e>, f : (a) -> e (), nagare/core/types/pull<a,e>) -> e nagare/core/types/pull<a,e> */ 
  return kk_nagare_core_pull__unroll_pullAppend_10007(_y_x10392, kk_nagare_core_stream__new_mlift_lift_evalTap_10305_10430_fun422(_uniq_tail_10263, f, _ctx), _ctx);
}
 
// monadic lift

kk_nagare_core_types__pull kk_nagare_core_stream__mlift_lift_evalTap_10304_10431(kk_box_t x, kk_unit_t wild__, kk_context_t* _ctx) { /* forall<a,e> (x : a, wild_ : ()) -> e nagare/core/types/pull<a,e> */ 
  kk_nagare_core_types__chunk _x_x423;
  kk_std_core_types__list _x_x424 = kk_std_core_types__new_Cons(kk_reuse_null, 0, x, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<10021>*/
  _x_x423 = kk_nagare_core_types__new_Chunk(_x_x424, _ctx); /*nagare/core/types/chunk<4>*/
  return kk_nagare_core_types__new_POutput(kk_reuse_null, 0, _x_x423, kk_nagare_core_types__new_PDone(_ctx), _ctx);
}
 
// monadic lift

kk_nagare_core_types__pull kk_nagare_core_stream__mlift_lift_evalTap_10304_10432(kk_nagare_core_types__pull _uniq_tail_10263_0, kk_function_t f_0, kk_nagare_core_types__pull _c_x10395, kk_context_t* _ctx) { /* forall<a,e> (nagare/core/types/pull<a,e>, f : (a) -> e (), nagare/core/types/pull<a,e>) -> nagare/core/types/pull<a,e> */ 
  if (kk_nagare_core_types__is_PDone(_c_x10395, _ctx)) {
    return kk_nagare_core_stream__lift_evalTap_10304(f_0, _uniq_tail_10263_0, _ctx);
  }
  {
    return kk_nagare_core_stream__lift_evalTap_10305(_uniq_tail_10263_0, f_0, _c_x10395, _ctx);
  }
}
 
// monadic lift

kk_nagare_core_types__pull kk_nagare_core_stream__mlift_lift_evalTap_10304_10433(kk_function_t _uniq_f_10259, kk_nagare_core_types__pull _y_x10398, kk_context_t* _ctx) { /* forall<a,e> ((a) -> nagare/core/types/pull<a,e>, nagare/core/types/pull<a,e>) -> e nagare/core/types/pull<a,e> */ 
  return kk_nagare_core_pull__unroll_pullFlatMap_10011(_y_x10398, _uniq_f_10259, _ctx);
}
 
// lifted local: @lift-evalTap@10304, @lift-evalTap@10303, evalTap, @spec-x10290
// specialized: nagare/core/pull/@unroll-pullAppend@10007, on parameters @uniq-right@10279, using:
// @uniq-right@10279 = fn(){
//   @spec-x10277(@uniq-tail@10263);
// }


// lift anonymous function
struct kk_nagare_core_stream__lift_evalTap_10305_fun428__t {
  struct kk_function_s _base;
  kk_function_t _uniq_next_10285;
  kk_nagare_core_types__pull _uniq_tail_10263_1;
  kk_function_t f_1;
};
static kk_nagare_core_types__pull kk_nagare_core_stream__lift_evalTap_10305_fun428(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_stream__new_lift_evalTap_10305_fun428(kk_function_t _uniq_next_10285, kk_nagare_core_types__pull _uniq_tail_10263_1, kk_function_t f_1, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__lift_evalTap_10305_fun428__t* _self = kk_function_alloc_as(struct kk_nagare_core_stream__lift_evalTap_10305_fun428__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_stream__lift_evalTap_10305_fun428, kk_context());
  _self->_uniq_next_10285 = _uniq_next_10285;
  _self->_uniq_tail_10263_1 = _uniq_tail_10263_1;
  _self->f_1 = f_1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_core_stream__lift_evalTap_10305_fun430__t {
  struct kk_function_s _base;
  kk_nagare_core_types__pull _uniq_tail_10263_1;
  kk_function_t f_1;
};
static kk_box_t kk_nagare_core_stream__lift_evalTap_10305_fun430(kk_function_t _fself, kk_box_t _b_x120, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_stream__new_lift_evalTap_10305_fun430(kk_nagare_core_types__pull _uniq_tail_10263_1, kk_function_t f_1, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__lift_evalTap_10305_fun430__t* _self = kk_function_alloc_as(struct kk_nagare_core_stream__lift_evalTap_10305_fun430__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_stream__lift_evalTap_10305_fun430, kk_context());
  _self->_uniq_tail_10263_1 = _uniq_tail_10263_1;
  _self->f_1 = f_1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_core_stream__lift_evalTap_10305_fun430(kk_function_t _fself, kk_box_t _b_x120, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__lift_evalTap_10305_fun430__t* _self = kk_function_as(struct kk_nagare_core_stream__lift_evalTap_10305_fun430__t*, _fself, _ctx);
  kk_nagare_core_types__pull _uniq_tail_10263_1 = _self->_uniq_tail_10263_1; /* nagare/core/types/pull<1477,1478> */
  kk_function_t f_1 = _self->f_1; /* (1477) -> 1478 () */
  kk_drop_match(_self, {kk_nagare_core_types__pull_dup(_uniq_tail_10263_1, _ctx);kk_function_dup(f_1, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull _y_x10392_0_122 = kk_nagare_core_types__pull_unbox(_b_x120, KK_OWNED, _ctx); /*nagare/core/types/pull<1477,1478>*/;
  kk_nagare_core_types__pull _x_x431 = kk_nagare_core_stream__mlift_lift_evalTap_10305_10430(_uniq_tail_10263_1, f_1, _y_x10392_0_122, _ctx); /*nagare/core/types/pull<1477,1478>*/
  return kk_nagare_core_types__pull_box(_x_x431, _ctx);
}
static kk_nagare_core_types__pull kk_nagare_core_stream__lift_evalTap_10305_fun428(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__lift_evalTap_10305_fun428__t* _self = kk_function_as(struct kk_nagare_core_stream__lift_evalTap_10305_fun428__t*, _fself, _ctx);
  kk_function_t _uniq_next_10285 = _self->_uniq_next_10285; /* () -> 1478 nagare/core/types/pull<1477,1478> */
  kk_nagare_core_types__pull _uniq_tail_10263_1 = _self->_uniq_tail_10263_1; /* nagare/core/types/pull<1477,1478> */
  kk_function_t f_1 = _self->f_1; /* (1477) -> 1478 () */
  kk_drop_match(_self, {kk_function_dup(_uniq_next_10285, _ctx);kk_nagare_core_types__pull_dup(_uniq_tail_10263_1, _ctx);kk_function_dup(f_1, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull x_0_10472 = kk_function_call(kk_nagare_core_types__pull, (kk_function_t, kk_context_t*), _uniq_next_10285, (_uniq_next_10285, _ctx), _ctx); /*nagare/core/types/pull<1477,1478>*/;
  if (kk_yielding(kk_context())) {
    kk_nagare_core_types__pull_drop(x_0_10472, _ctx);
    kk_box_t _x_x429 = kk_std_core_hnd_yield_extend(kk_nagare_core_stream__new_lift_evalTap_10305_fun430(_uniq_tail_10263_1, f_1, _ctx), _ctx); /*10001*/
    return kk_nagare_core_types__pull_unbox(_x_x429, KK_OWNED, _ctx);
  }
  {
    return kk_nagare_core_stream__mlift_lift_evalTap_10305_10430(_uniq_tail_10263_1, f_1, x_0_10472, _ctx);
  }
}

kk_nagare_core_types__pull kk_nagare_core_stream__lift_evalTap_10305(kk_nagare_core_types__pull _uniq_tail_10263_1, kk_function_t f_1, kk_nagare_core_types__pull _uniq_left_10278, kk_context_t* _ctx) { /* forall<a,e> (nagare/core/types/pull<a,e>, f : (a) -> e (), nagare/core/types/pull<a,e>) -> nagare/core/types/pull<a,e> */ 
  if (kk_nagare_core_types__is_PDone(_uniq_left_10278, _ctx)) {
    return kk_nagare_core_stream__lift_evalTap_10304(f_1, _uniq_tail_10263_1, _ctx);
  }
  if (kk_nagare_core_types__is_POutput(_uniq_left_10278, _ctx)) {
    struct kk_nagare_core_types_POutput* _con_x425 = kk_nagare_core_types__as_POutput(_uniq_left_10278, _ctx);
    kk_nagare_core_types__chunk _uniq_out_10282 = _con_x425->out;
    kk_nagare_core_types__pull _uniq_tail_10283 = _con_x425->tail;
    kk_reuse_t _ru_x269 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_left_10278, _ctx)) {
      _ru_x269 = (kk_datatype_ptr_reuse(_uniq_left_10278, _ctx));
    }
    else {
      kk_nagare_core_types__chunk_dup(_uniq_out_10282, _ctx);
      kk_nagare_core_types__pull_dup(_uniq_tail_10283, _ctx);
      kk_datatype_ptr_decref(_uniq_left_10278, _ctx);
    }
    kk_nagare_core_types__pull _x_x426 = kk_nagare_core_stream__lift_evalTap_10305(_uniq_tail_10263_1, f_1, _uniq_tail_10283, _ctx); /*nagare/core/types/pull<1477,1478>*/
    return kk_nagare_core_types__new_POutput(_ru_x269, 0, _uniq_out_10282, _x_x426, _ctx);
  }
  if (kk_nagare_core_types__is_PEval(_uniq_left_10278, _ctx)) {
    struct kk_nagare_core_types_PEval* _con_x427 = kk_nagare_core_types__as_PEval(_uniq_left_10278, _ctx);
    kk_function_t _uniq_next_10285 = _con_x427->next;
    kk_reuse_t _ru_x270 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_left_10278, _ctx)) {
      _ru_x270 = (kk_datatype_ptr_reuse(_uniq_left_10278, _ctx));
    }
    else {
      kk_function_dup(_uniq_next_10285, _ctx);
      kk_datatype_ptr_decref(_uniq_left_10278, _ctx);
    }
    return kk_nagare_core_types__new_PEval(_ru_x270, 0, kk_nagare_core_stream__new_lift_evalTap_10305_fun428(_uniq_next_10285, _uniq_tail_10263_1, f_1, _ctx), _ctx);
  }
  {
    struct kk_nagare_core_types_PAcquire* _con_x432 = kk_nagare_core_types__as_PAcquire(_uniq_left_10278, _ctx);
    kk_function_t _uniq_acquire_10287 = _con_x432->acquire;
    kk_function_t _uniq_release_10288 = _con_x432->release;
    kk_nagare_core_types__pull _uniq_tail_0_10289 = _con_x432->tail;
    kk_reuse_t _ru_x271 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_left_10278, _ctx)) {
      _ru_x271 = (kk_datatype_ptr_reuse(_uniq_left_10278, _ctx));
    }
    else {
      kk_function_dup(_uniq_acquire_10287, _ctx);
      kk_function_dup(_uniq_release_10288, _ctx);
      kk_nagare_core_types__pull_dup(_uniq_tail_0_10289, _ctx);
      kk_datatype_ptr_decref(_uniq_left_10278, _ctx);
    }
    kk_nagare_core_types__pull _x_x433 = kk_nagare_core_stream__lift_evalTap_10305(_uniq_tail_10263_1, f_1, _uniq_tail_0_10289, _ctx); /*nagare/core/types/pull<1477,1478>*/
    return kk_nagare_core_types__new_PAcquire(_ru_x271, 0, _uniq_acquire_10287, _uniq_release_10288, _x_x433, _ctx);
  }
}
 
// lifted local: @lift-evalTap@10303, evalTap, @spec-x10277
// specialized: nagare/core/pull/@unroll-pullFlatMap@10011, on parameters @uniq-f@10259, using:
// @uniq-f@10259 = fn(x: 1477){
//   nagare/core/types/PEval<a,(e :: E)>((fn<(e :: E)>(){
//     val _ : ()
//           = (f(x));
//     (nagare/core/types/POutput<a,(e :: E)>((nagare/core/types/Chunk<a>((std/core/types/Cons<a>(x, (std/core/types/Nil<a>))))), (nagare/core/types/PDone<a,(e :: E)>)));
//   }));
// }


// lift anonymous function
struct kk_nagare_core_stream__lift_evalTap_10304_fun434__t {
  struct kk_function_s _base;
  kk_function_t f_2;
};
static kk_nagare_core_types__pull kk_nagare_core_stream__lift_evalTap_10304_fun434(kk_function_t _fself, kk_box_t x_1, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_stream__new_lift_evalTap_10304_fun434(kk_function_t f_2, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__lift_evalTap_10304_fun434__t* _self = kk_function_alloc_as(struct kk_nagare_core_stream__lift_evalTap_10304_fun434__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_stream__lift_evalTap_10304_fun434, kk_context());
  _self->f_2 = f_2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_core_stream__lift_evalTap_10304_fun435__t {
  struct kk_function_s _base;
  kk_function_t f_2;
  kk_box_t x_1;
};
static kk_nagare_core_types__pull kk_nagare_core_stream__lift_evalTap_10304_fun435(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_stream__new_lift_evalTap_10304_fun435(kk_function_t f_2, kk_box_t x_1, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__lift_evalTap_10304_fun435__t* _self = kk_function_alloc_as(struct kk_nagare_core_stream__lift_evalTap_10304_fun435__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_stream__lift_evalTap_10304_fun435, kk_context());
  _self->f_2 = f_2;
  _self->x_1 = x_1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_core_stream__lift_evalTap_10304_fun438__t {
  struct kk_function_s _base;
  kk_box_t x_1;
};
static kk_box_t kk_nagare_core_stream__lift_evalTap_10304_fun438(kk_function_t _fself, kk_box_t _b_x124, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_stream__new_lift_evalTap_10304_fun438(kk_box_t x_1, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__lift_evalTap_10304_fun438__t* _self = kk_function_alloc_as(struct kk_nagare_core_stream__lift_evalTap_10304_fun438__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_stream__lift_evalTap_10304_fun438, kk_context());
  _self->x_1 = x_1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_core_stream__lift_evalTap_10304_fun438(kk_function_t _fself, kk_box_t _b_x124, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__lift_evalTap_10304_fun438__t* _self = kk_function_as(struct kk_nagare_core_stream__lift_evalTap_10304_fun438__t*, _fself, _ctx);
  kk_box_t x_1 = _self->x_1; /* 1477 */
  kk_drop_match(_self, {kk_box_dup(x_1, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull _x_x439;
  kk_unit_t _x_x440 = kk_Unit;
  kk_unit_unbox(_b_x124);
  _x_x439 = kk_nagare_core_stream__mlift_lift_evalTap_10304_10431(x_1, _x_x440, _ctx); /*nagare/core/types/pull<1477,1478>*/
  return kk_nagare_core_types__pull_box(_x_x439, _ctx);
}
static kk_nagare_core_types__pull kk_nagare_core_stream__lift_evalTap_10304_fun435(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__lift_evalTap_10304_fun435__t* _self = kk_function_as(struct kk_nagare_core_stream__lift_evalTap_10304_fun435__t*, _fself, _ctx);
  kk_function_t f_2 = _self->f_2; /* (1477) -> 1478 () */
  kk_box_t x_1 = _self->x_1; /* 1477 */
  kk_drop_match(_self, {kk_function_dup(f_2, _ctx);kk_box_dup(x_1, _ctx);}, {}, _ctx)
  kk_unit_t x_2_10474 = kk_Unit;
  kk_box_t _x_x436 = kk_box_dup(x_1, _ctx); /*1477*/
  kk_function_call(kk_unit_t, (kk_function_t, kk_box_t, kk_context_t*), f_2, (f_2, _x_x436, _ctx), _ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x437 = kk_std_core_hnd_yield_extend(kk_nagare_core_stream__new_lift_evalTap_10304_fun438(x_1, _ctx), _ctx); /*10001*/
    return kk_nagare_core_types__pull_unbox(_x_x437, KK_OWNED, _ctx);
  }
  {
    return kk_nagare_core_stream__mlift_lift_evalTap_10304_10431(x_1, x_2_10474, _ctx);
  }
}
static kk_nagare_core_types__pull kk_nagare_core_stream__lift_evalTap_10304_fun434(kk_function_t _fself, kk_box_t x_1, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__lift_evalTap_10304_fun434__t* _self = kk_function_as(struct kk_nagare_core_stream__lift_evalTap_10304_fun434__t*, _fself, _ctx);
  kk_function_t f_2 = _self->f_2; /* (1477) -> 1478 () */
  kk_drop_match(_self, {kk_function_dup(f_2, _ctx);}, {}, _ctx)
  return kk_nagare_core_types__new_PEval(kk_reuse_null, 0, kk_nagare_core_stream__new_lift_evalTap_10304_fun435(f_2, x_1, _ctx), _ctx);
}


// lift anonymous function
struct kk_nagare_core_stream__lift_evalTap_10304_fun443__t {
  struct kk_function_s _base;
  kk_nagare_core_types__pull _uniq_tail_10263_2;
  kk_function_t f_2;
};
static kk_box_t kk_nagare_core_stream__lift_evalTap_10304_fun443(kk_function_t _fself, kk_box_t _b_x128, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_stream__new_lift_evalTap_10304_fun443(kk_nagare_core_types__pull _uniq_tail_10263_2, kk_function_t f_2, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__lift_evalTap_10304_fun443__t* _self = kk_function_alloc_as(struct kk_nagare_core_stream__lift_evalTap_10304_fun443__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_stream__lift_evalTap_10304_fun443, kk_context());
  _self->_uniq_tail_10263_2 = _uniq_tail_10263_2;
  _self->f_2 = f_2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_core_stream__lift_evalTap_10304_fun443(kk_function_t _fself, kk_box_t _b_x128, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__lift_evalTap_10304_fun443__t* _self = kk_function_as(struct kk_nagare_core_stream__lift_evalTap_10304_fun443__t*, _fself, _ctx);
  kk_nagare_core_types__pull _uniq_tail_10263_2 = _self->_uniq_tail_10263_2; /* nagare/core/types/pull<1477,1478> */
  kk_function_t f_2 = _self->f_2; /* (1477) -> 1478 () */
  kk_drop_match(_self, {kk_nagare_core_types__pull_dup(_uniq_tail_10263_2, _ctx);kk_function_dup(f_2, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull _c_x10395_0_133 = kk_nagare_core_types__pull_unbox(_b_x128, KK_OWNED, _ctx); /*nagare/core/types/pull<1477,1478>*/;
  kk_nagare_core_types__pull _x_x444 = kk_nagare_core_stream__mlift_lift_evalTap_10304_10432(_uniq_tail_10263_2, f_2, _c_x10395_0_133, _ctx); /*nagare/core/types/pull<1477,1478>*/
  return kk_nagare_core_types__pull_box(_x_x444, _ctx);
}


// lift anonymous function
struct kk_nagare_core_stream__lift_evalTap_10304_fun446__t {
  struct kk_function_s _base;
  kk_function_t _uniq_f_10259_0;
  kk_function_t _uniq_next_10272;
};
static kk_nagare_core_types__pull kk_nagare_core_stream__lift_evalTap_10304_fun446(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_stream__new_lift_evalTap_10304_fun446(kk_function_t _uniq_f_10259_0, kk_function_t _uniq_next_10272, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__lift_evalTap_10304_fun446__t* _self = kk_function_alloc_as(struct kk_nagare_core_stream__lift_evalTap_10304_fun446__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_stream__lift_evalTap_10304_fun446, kk_context());
  _self->_uniq_f_10259_0 = _uniq_f_10259_0;
  _self->_uniq_next_10272 = _uniq_next_10272;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_core_stream__lift_evalTap_10304_fun448__t {
  struct kk_function_s _base;
  kk_function_t _uniq_f_10259_0;
};
static kk_box_t kk_nagare_core_stream__lift_evalTap_10304_fun448(kk_function_t _fself, kk_box_t _b_x130, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_stream__new_lift_evalTap_10304_fun448(kk_function_t _uniq_f_10259_0, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__lift_evalTap_10304_fun448__t* _self = kk_function_alloc_as(struct kk_nagare_core_stream__lift_evalTap_10304_fun448__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_stream__lift_evalTap_10304_fun448, kk_context());
  _self->_uniq_f_10259_0 = _uniq_f_10259_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_core_stream__lift_evalTap_10304_fun448(kk_function_t _fself, kk_box_t _b_x130, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__lift_evalTap_10304_fun448__t* _self = kk_function_as(struct kk_nagare_core_stream__lift_evalTap_10304_fun448__t*, _fself, _ctx);
  kk_function_t _uniq_f_10259_0 = _self->_uniq_f_10259_0; /* (1477) -> nagare/core/types/pull<1477,1478> */
  kk_drop_match(_self, {kk_function_dup(_uniq_f_10259_0, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull _y_x10398_0_134 = kk_nagare_core_types__pull_unbox(_b_x130, KK_OWNED, _ctx); /*nagare/core/types/pull<1477,1478>*/;
  kk_nagare_core_types__pull _x_x449 = kk_nagare_core_stream__mlift_lift_evalTap_10304_10433(_uniq_f_10259_0, _y_x10398_0_134, _ctx); /*nagare/core/types/pull<1477,1478>*/
  return kk_nagare_core_types__pull_box(_x_x449, _ctx);
}
static kk_nagare_core_types__pull kk_nagare_core_stream__lift_evalTap_10304_fun446(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_core_stream__lift_evalTap_10304_fun446__t* _self = kk_function_as(struct kk_nagare_core_stream__lift_evalTap_10304_fun446__t*, _fself, _ctx);
  kk_function_t _uniq_f_10259_0 = _self->_uniq_f_10259_0; /* (1477) -> nagare/core/types/pull<1477,1478> */
  kk_function_t _uniq_next_10272 = _self->_uniq_next_10272; /* () -> 1478 nagare/core/types/pull<1477,1478> */
  kk_drop_match(_self, {kk_function_dup(_uniq_f_10259_0, _ctx);kk_function_dup(_uniq_next_10272, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull x_4_10479 = kk_function_call(kk_nagare_core_types__pull, (kk_function_t, kk_context_t*), _uniq_next_10272, (_uniq_next_10272, _ctx), _ctx); /*nagare/core/types/pull<1477,1478>*/;
  if (kk_yielding(kk_context())) {
    kk_nagare_core_types__pull_drop(x_4_10479, _ctx);
    kk_box_t _x_x447 = kk_std_core_hnd_yield_extend(kk_nagare_core_stream__new_lift_evalTap_10304_fun448(_uniq_f_10259_0, _ctx), _ctx); /*10001*/
    return kk_nagare_core_types__pull_unbox(_x_x447, KK_OWNED, _ctx);
  }
  {
    return kk_nagare_core_stream__mlift_lift_evalTap_10304_10433(_uniq_f_10259_0, x_4_10479, _ctx);
  }
}

kk_nagare_core_types__pull kk_nagare_core_stream__lift_evalTap_10304(kk_function_t f_2, kk_nagare_core_types__pull _uniq_source_10258, kk_context_t* _ctx) { /* forall<a,e> (f : (a) -> e (), nagare/core/types/pull<a,e>) -> nagare/core/types/pull<a,e> */ 
  kk__tailcall: ;
  kk_function_t _uniq_f_10259_0;
  kk_function_dup(f_2, _ctx);
  _uniq_f_10259_0 = kk_nagare_core_stream__new_lift_evalTap_10304_fun434(f_2, _ctx); /*(x : 1477) -> nagare/core/types/pull<1477,1478>*/
  if (kk_nagare_core_types__is_PDone(_uniq_source_10258, _ctx)) {
    kk_function_drop(f_2, _ctx);
    kk_function_drop(_uniq_f_10259_0, _ctx);
    return kk_nagare_core_types__new_PDone(_ctx);
  }
  if (kk_nagare_core_types__is_POutput(_uniq_source_10258, _ctx)) {
    struct kk_nagare_core_types_POutput* _con_x441 = kk_nagare_core_types__as_POutput(_uniq_source_10258, _ctx);
    kk_nagare_core_types__chunk _uniq_out_10262 = _con_x441->out;
    kk_nagare_core_types__pull _uniq_tail_10263_2 = _con_x441->tail;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_source_10258, _ctx)) {
      kk_datatype_ptr_free(_uniq_source_10258, _ctx);
    }
    else {
      kk_nagare_core_types__chunk_dup(_uniq_out_10262, _ctx);
      kk_nagare_core_types__pull_dup(_uniq_tail_10263_2, _ctx);
      kk_datatype_ptr_decref(_uniq_source_10258, _ctx);
    }
    {
      kk_std_core_types__list _uniq_values_10265 = _uniq_out_10262.values;
      kk_nagare_core_types__pull x_3_10476;
      if (kk_std_core_types__is_Nil(_uniq_values_10265, _ctx)) {
        kk_function_drop(_uniq_f_10259_0, _ctx);
        x_3_10476 = kk_nagare_core_types__new_PDone(_ctx); /*nagare/core/types/pull<1477,1478>*/
      }
      else {
        x_3_10476 = kk_nagare_core_pull__unroll_flatMapChunk_10010(_uniq_values_10265, _uniq_f_10259_0, _ctx); /*nagare/core/types/pull<1477,1478>*/
      }
      if (kk_yielding(kk_context())) {
        kk_nagare_core_types__pull_drop(x_3_10476, _ctx);
        kk_box_t _x_x442 = kk_std_core_hnd_yield_extend(kk_nagare_core_stream__new_lift_evalTap_10304_fun443(_uniq_tail_10263_2, f_2, _ctx), _ctx); /*10001*/
        return kk_nagare_core_types__pull_unbox(_x_x442, KK_OWNED, _ctx);
      }
      if (kk_nagare_core_types__is_PDone(x_3_10476, _ctx)) { // tailcall
                                                             _uniq_source_10258 = _uniq_tail_10263_2;
                                                             goto kk__tailcall;
      }
      {
        return kk_nagare_core_stream__lift_evalTap_10305(_uniq_tail_10263_2, f_2, x_3_10476, _ctx);
      }
    }
  }
  if (kk_nagare_core_types__is_PEval(_uniq_source_10258, _ctx)) {
    struct kk_nagare_core_types_PEval* _con_x445 = kk_nagare_core_types__as_PEval(_uniq_source_10258, _ctx);
    kk_function_t _uniq_next_10272 = _con_x445->next;
    kk_function_drop(f_2, _ctx);
    kk_reuse_t _ru_x273 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_source_10258, _ctx)) {
      _ru_x273 = (kk_datatype_ptr_reuse(_uniq_source_10258, _ctx));
    }
    else {
      kk_function_dup(_uniq_next_10272, _ctx);
      kk_datatype_ptr_decref(_uniq_source_10258, _ctx);
    }
    return kk_nagare_core_types__new_PEval(_ru_x273, 0, kk_nagare_core_stream__new_lift_evalTap_10304_fun446(_uniq_f_10259_0, _uniq_next_10272, _ctx), _ctx);
  }
  {
    struct kk_nagare_core_types_PAcquire* _con_x450 = kk_nagare_core_types__as_PAcquire(_uniq_source_10258, _ctx);
    kk_function_t _uniq_acquire_10274 = _con_x450->acquire;
    kk_function_t _uniq_release_10275 = _con_x450->release;
    kk_nagare_core_types__pull _uniq_tail_0_10276 = _con_x450->tail;
    kk_reuse_t _ru_x274 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_source_10258, _ctx)) {
      _ru_x274 = (kk_datatype_ptr_reuse(_uniq_source_10258, _ctx));
    }
    else {
      kk_function_dup(_uniq_acquire_10274, _ctx);
      kk_function_dup(_uniq_release_10275, _ctx);
      kk_nagare_core_types__pull_dup(_uniq_tail_0_10276, _ctx);
      kk_datatype_ptr_decref(_uniq_source_10258, _ctx);
    }
    kk_function_drop(_uniq_f_10259_0, _ctx);
    kk_nagare_core_types__pull _x_x451 = kk_nagare_core_stream__lift_evalTap_10304(f_2, _uniq_tail_0_10276, _ctx); /*nagare/core/types/pull<1477,1478>*/
    return kk_nagare_core_types__new_PAcquire(_ru_x274, 0, _uniq_acquire_10274, _uniq_release_10275, _x_x451, _ctx);
  }
}
 
// lifted local: evalTap, @spec-x10257
// specialized: nagare/core/pull/pullFlatMap, on parameters @uniq-f@10254, using:
// @uniq-f@10254 = fn(x: 1477){
//   nagare/core/types/PEval<a,(e :: E)>((fn<(e :: E)>(){
//     val _ : ()
//           = (f(x));
//     (nagare/core/types/POutput<a,(e :: E)>((nagare/core/types/Chunk<a>((std/core/types/Cons<a>(x, (std/core/types/Nil<a>))))), (nagare/core/types/PDone<a,(e :: E)>)));
//   }));
// }

kk_nagare_core_types__pull kk_nagare_core_stream__lift_evalTap_10303(kk_function_t f, kk_nagare_core_types__pull _uniq_source_10253, kk_context_t* _ctx) { /* forall<a,e> (f : (a) -> e (), nagare/core/types/pull<a,e>) -> nagare/core/types/pull<a,e> */ 
  if (kk_nagare_core_types__is_PDone(_uniq_source_10253, _ctx)) {
    kk_function_drop(f, _ctx);
    return kk_nagare_core_types__new_PDone(_ctx);
  }
  {
    return kk_nagare_core_stream__lift_evalTap_10304(f, _uniq_source_10253, _ctx);
  }
}
 
// Flatten a stream of chunks back into a stream of values.


// lift anonymous function
struct kk_nagare_core_stream_unchunks_fun456__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_core_stream_unchunks_fun456(kk_function_t _fself, kk_box_t _b_x136, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_stream_new_unchunks_fun456(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_core_stream_unchunks_fun456, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_core_stream_unchunks_fun456(kk_function_t _fself, kk_box_t _b_x136, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_nagare_core_types__pull _c_x10404_138 = kk_nagare_core_types__pull_unbox(_b_x136, KK_OWNED, _ctx); /*nagare/core/types/pull<1631,1632>*/;
  kk_nagare_core_types__nstream _x_x457 = kk_nagare_core_types__new_Stream(_c_x10404_138, _ctx); /*nagare/core/types/nstream<27,28>*/
  return kk_nagare_core_types__nstream_box(_x_x457, _ctx);
}

kk_nagare_core_types__nstream kk_nagare_core_stream_unchunks(kk_nagare_core_types__nstream source, kk_context_t* _ctx) { /* forall<a,e> (source : nagare/core/types/nstream<nagare/core/types/chunk<a>,e>) -> nagare/core/types/nstream<a,e> */ 
  {
    kk_nagare_core_types__pull step = source.step;
    kk_nagare_core_types__pull x_10481;
    if (kk_nagare_core_types__is_PDone(step, _ctx)) {
      x_10481 = kk_nagare_core_types__new_PDone(_ctx); /*nagare/core/types/pull<1631,1632>*/
    }
    else {
      x_10481 = kk_nagare_core_pull__unroll_pullUnchunks_10013(step, _ctx); /*nagare/core/types/pull<1631,1632>*/
    }
    if (kk_yielding(kk_context())) {
      kk_nagare_core_types__pull_drop(x_10481, _ctx);
      kk_box_t _x_x455 = kk_std_core_hnd_yield_extend(kk_nagare_core_stream_new_unchunks_fun456(_ctx), _ctx); /*10001*/
      return kk_nagare_core_types__nstream_unbox(_x_x455, KK_OWNED, _ctx);
    }
    {
      return kk_nagare_core_types__new_Stream(x_10481, _ctx);
    }
  }
}
 
// runtime tag for the effect `:emitter`

kk_std_core_hnd__htag kk_nagare_core_stream_emitter_fs__tag;
 
// handler for the effect `:emitter`

kk_box_t kk_nagare_core_stream_emitter_fs__handle(kk_nagare_core_stream__emitter hnd, kk_function_t ret, kk_function_t action, kk_context_t* _ctx) { /* forall<a,b,e,c> (hnd : emitter<a,e,c>, ret : (res : b) -> e c, action : () -> <emitter<a>|e> b) -> e c */ 
  kk_std_core_hnd__htag _x_x462 = kk_std_core_hnd__htag_dup(kk_nagare_core_stream_emitter_fs__tag, _ctx); /*forall<a> hnd/htag<nagare/core/stream/emitter<a>>*/
  return kk_std_core_hnd__hhandle(_x_x462, kk_nagare_core_stream__emitter_box(hnd, _ctx), ret, action, _ctx);
}


// lift anonymous function
struct kk_nagare_core_stream_streamOfPull_fun474__t {
  struct kk_function_s _base;
};
static kk_unit_t kk_nagare_core_stream_streamOfPull_fun474(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x639__16, kk_std_core_types__list x, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_stream_new_streamOfPull_fun474(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_core_stream_streamOfPull_fun474, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_nagare_core_stream_streamOfPull_fun476__t {
  struct kk_function_s _base;
  kk_std_core_types__list x;
};
static kk_box_t kk_nagare_core_stream_streamOfPull_fun476(kk_function_t _fself, kk_function_t _b_x172, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_stream_new_streamOfPull_fun476(kk_std_core_types__list x, kk_context_t* _ctx) {
  struct kk_nagare_core_stream_streamOfPull_fun476__t* _self = kk_function_alloc_as(struct kk_nagare_core_stream_streamOfPull_fun476__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_stream_streamOfPull_fun476, kk_context());
  _self->x = x;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_core_stream_streamOfPull_fun477__t {
  struct kk_function_s _base;
  kk_function_t _b_x172;
};
static kk_nagare_core_types__pull kk_nagare_core_stream_streamOfPull_fun477(kk_function_t _fself, kk_std_core_hnd__resume_result _b_x173, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_stream_new_streamOfPull_fun477(kk_function_t _b_x172, kk_context_t* _ctx) {
  struct kk_nagare_core_stream_streamOfPull_fun477__t* _self = kk_function_alloc_as(struct kk_nagare_core_stream_streamOfPull_fun477__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_stream_streamOfPull_fun477, kk_context());
  _self->_b_x172 = _b_x172;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_nagare_core_types__pull kk_nagare_core_stream_streamOfPull_fun477(kk_function_t _fself, kk_std_core_hnd__resume_result _b_x173, kk_context_t* _ctx) {
  struct kk_nagare_core_stream_streamOfPull_fun477__t* _self = kk_function_as(struct kk_nagare_core_stream_streamOfPull_fun477__t*, _fself, _ctx);
  kk_function_t _b_x172 = _self->_b_x172; /* (hnd/resume-result<10000,10002>) -> 10001 10002 */
  kk_drop_match(_self, {kk_function_dup(_b_x172, _ctx);}, {}, _ctx)
  kk_box_t _x_x478 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__resume_result, kk_context_t*), _b_x172, (_b_x172, _b_x173, _ctx), _ctx); /*10002*/
  return kk_nagare_core_types__pull_unbox(_x_x478, KK_OWNED, _ctx);
}


// lift anonymous function
struct kk_nagare_core_stream_streamOfPull_fun479__t {
  struct kk_function_s _base;
};
static kk_nagare_core_types__pull kk_nagare_core_stream_streamOfPull_fun479(kk_function_t _fself, kk_std_core_types__list xs, kk_function_t resume, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_stream_new_streamOfPull_fun479(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_core_stream_streamOfPull_fun479, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_nagare_core_stream_streamOfPull_fun482__t {
  struct kk_function_s _base;
  kk_function_t resume;
};
static kk_nagare_core_types__pull kk_nagare_core_stream_streamOfPull_fun482(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_stream_new_streamOfPull_fun482(kk_function_t resume, kk_context_t* _ctx) {
  struct kk_nagare_core_stream_streamOfPull_fun482__t* _self = kk_function_alloc_as(struct kk_nagare_core_stream_streamOfPull_fun482__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_stream_streamOfPull_fun482, kk_context());
  _self->resume = resume;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_nagare_core_types__pull kk_nagare_core_stream_streamOfPull_fun482(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_core_stream_streamOfPull_fun482__t* _self = kk_function_as(struct kk_nagare_core_stream_streamOfPull_fun482__t*, _fself, _ctx);
  kk_function_t resume = _self->resume; /* (()) -> 2323 nagare/core/types/pull<2322,2323> */
  kk_drop_match(_self, {kk_function_dup(resume, _ctx);}, {}, _ctx)
  return kk_function_call(kk_nagare_core_types__pull, (kk_function_t, kk_unit_t, kk_context_t*), resume, (resume, kk_Unit, _ctx), _ctx);
}
static kk_nagare_core_types__pull kk_nagare_core_stream_streamOfPull_fun479(kk_function_t _fself, kk_std_core_types__list xs, kk_function_t resume, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    return kk_function_call(kk_nagare_core_types__pull, (kk_function_t, kk_unit_t, kk_context_t*), resume, (resume, kk_Unit, _ctx), _ctx);
  }
  {
    kk_nagare_core_types__chunk _x_x480 = kk_nagare_core_types__new_Chunk(xs, _ctx); /*nagare/core/types/chunk<4>*/
    kk_nagare_core_types__pull _x_x481 = kk_nagare_core_types__new_PEval(kk_reuse_null, 0, kk_nagare_core_stream_new_streamOfPull_fun482(resume, _ctx), _ctx); /*nagare/core/types/pull<19,20>*/
    return kk_nagare_core_types__new_POutput(kk_reuse_null, 0, _x_x480, _x_x481, _ctx);
  }
}


// lift anonymous function
struct kk_nagare_core_stream_streamOfPull_fun483__t {
  struct kk_function_s _base;
  kk_function_t _b_x164_206;
};
static kk_box_t kk_nagare_core_stream_streamOfPull_fun483(kk_function_t _fself, kk_box_t _b_x166, kk_function_t _b_x167, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_stream_new_streamOfPull_fun483(kk_function_t _b_x164_206, kk_context_t* _ctx) {
  struct kk_nagare_core_stream_streamOfPull_fun483__t* _self = kk_function_alloc_as(struct kk_nagare_core_stream_streamOfPull_fun483__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_stream_streamOfPull_fun483, kk_context());
  _self->_b_x164_206 = _b_x164_206;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_core_stream_streamOfPull_fun486__t {
  struct kk_function_s _base;
  kk_function_t _b_x167;
};
static kk_nagare_core_types__pull kk_nagare_core_stream_streamOfPull_fun486(kk_function_t _fself, kk_unit_t _b_x168, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_stream_new_streamOfPull_fun486(kk_function_t _b_x167, kk_context_t* _ctx) {
  struct kk_nagare_core_stream_streamOfPull_fun486__t* _self = kk_function_alloc_as(struct kk_nagare_core_stream_streamOfPull_fun486__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_stream_streamOfPull_fun486, kk_context());
  _self->_b_x167 = _b_x167;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_nagare_core_types__pull kk_nagare_core_stream_streamOfPull_fun486(kk_function_t _fself, kk_unit_t _b_x168, kk_context_t* _ctx) {
  struct kk_nagare_core_stream_streamOfPull_fun486__t* _self = kk_function_as(struct kk_nagare_core_stream_streamOfPull_fun486__t*, _fself, _ctx);
  kk_function_t _b_x167 = _self->_b_x167; /* (10001) -> 10002 10003 */
  kk_drop_match(_self, {kk_function_dup(_b_x167, _ctx);}, {}, _ctx)
  kk_box_t _x_x487 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _b_x167, (_b_x167, kk_unit_box(_b_x168), _ctx), _ctx); /*10003*/
  return kk_nagare_core_types__pull_unbox(_x_x487, KK_OWNED, _ctx);
}
static kk_box_t kk_nagare_core_stream_streamOfPull_fun483(kk_function_t _fself, kk_box_t _b_x166, kk_function_t _b_x167, kk_context_t* _ctx) {
  struct kk_nagare_core_stream_streamOfPull_fun483__t* _self = kk_function_as(struct kk_nagare_core_stream_streamOfPull_fun483__t*, _fself, _ctx);
  kk_function_t _b_x164_206 = _self->_b_x164_206; /* (xs : list<2322>, resume : (()) -> 2323 nagare/core/types/pull<2322,2323>) -> 2323 nagare/core/types/pull<2322,2323> */
  kk_drop_match(_self, {kk_function_dup(_b_x164_206, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull _x_x484;
  kk_std_core_types__list _x_x485 = kk_std_core_types__list_unbox(_b_x166, KK_OWNED, _ctx); /*list<2322>*/
  _x_x484 = kk_function_call(kk_nagare_core_types__pull, (kk_function_t, kk_std_core_types__list, kk_function_t, kk_context_t*), _b_x164_206, (_b_x164_206, _x_x485, kk_nagare_core_stream_new_streamOfPull_fun486(_b_x167, _ctx), _ctx), _ctx); /*nagare/core/types/pull<2322,2323>*/
  return kk_nagare_core_types__pull_box(_x_x484, _ctx);
}


// lift anonymous function
struct kk_nagare_core_stream_streamOfPull_fun488__t {
  struct kk_function_s _base;
  kk_function_t _b_x165_207;
};
static kk_box_t kk_nagare_core_stream_streamOfPull_fun488(kk_function_t _fself, kk_std_core_hnd__resume_result _b_x169, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_stream_new_streamOfPull_fun488(kk_function_t _b_x165_207, kk_context_t* _ctx) {
  struct kk_nagare_core_stream_streamOfPull_fun488__t* _self = kk_function_alloc_as(struct kk_nagare_core_stream_streamOfPull_fun488__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_stream_streamOfPull_fun488, kk_context());
  _self->_b_x165_207 = _b_x165_207;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_core_stream_streamOfPull_fun488(kk_function_t _fself, kk_std_core_hnd__resume_result _b_x169, kk_context_t* _ctx) {
  struct kk_nagare_core_stream_streamOfPull_fun488__t* _self = kk_function_as(struct kk_nagare_core_stream_streamOfPull_fun488__t*, _fself, _ctx);
  kk_function_t _b_x165_207 = _self->_b_x165_207; /* (hnd/resume-result<(),nagare/core/types/pull<2322,2323>>) -> 2323 nagare/core/types/pull<2322,2323> */
  kk_drop_match(_self, {kk_function_dup(_b_x165_207, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull _x_x489 = kk_function_call(kk_nagare_core_types__pull, (kk_function_t, kk_std_core_hnd__resume_result, kk_context_t*), _b_x165_207, (_b_x165_207, _b_x169, _ctx), _ctx); /*nagare/core/types/pull<2322,2323>*/
  return kk_nagare_core_types__pull_box(_x_x489, _ctx);
}
static kk_box_t kk_nagare_core_stream_streamOfPull_fun476(kk_function_t _fself, kk_function_t _b_x172, kk_context_t* _ctx) {
  struct kk_nagare_core_stream_streamOfPull_fun476__t* _self = kk_function_as(struct kk_nagare_core_stream_streamOfPull_fun476__t*, _fself, _ctx);
  kk_std_core_types__list x = _self->x; /* list<2322> */
  kk_drop_match(_self, {kk_std_core_types__list_dup(x, _ctx);}, {}, _ctx)
  kk_function_t k_215 = kk_nagare_core_stream_new_streamOfPull_fun477(_b_x172, _ctx); /*(hnd/resume-result<(),nagare/core/types/pull<2322,2323>>) -> 2323 nagare/core/types/pull<2322,2323>*/;
  kk_std_core_types__list _b_x163_205 = x; /*list<2322>*/;
  kk_function_t _b_x164_206 = kk_nagare_core_stream_new_streamOfPull_fun479(_ctx); /*(xs : list<2322>, resume : (()) -> 2323 nagare/core/types/pull<2322,2323>) -> 2323 nagare/core/types/pull<2322,2323>*/;
  kk_function_t _b_x165_207 = k_215; /*(hnd/resume-result<(),nagare/core/types/pull<2322,2323>>) -> 2323 nagare/core/types/pull<2322,2323>*/;
  return kk_std_core_hnd_protect(kk_std_core_types__list_box(_b_x163_205, _ctx), kk_nagare_core_stream_new_streamOfPull_fun483(_b_x164_206, _ctx), kk_nagare_core_stream_new_streamOfPull_fun488(_b_x165_207, _ctx), _ctx);
}
static kk_unit_t kk_nagare_core_stream_streamOfPull_fun474(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ___wildcard_x639__16, kk_std_core_types__list x, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_datatype_ptr_dropn(___wildcard_x639__16, (KK_I32(3)), _ctx);
  kk_box_t _x_x475 = kk_std_core_hnd_yield_to(m, kk_nagare_core_stream_new_streamOfPull_fun476(x, _ctx), _ctx); /*10000*/
  kk_unit_unbox(_x_x475); return kk_Unit;
}


// lift anonymous function
struct kk_nagare_core_stream_streamOfPull_fun490__t {
  struct kk_function_s _base;
};
static kk_unit_t kk_nagare_core_stream_streamOfPull_fun490(kk_function_t _fself, int32_t m_0, kk_std_core_hnd__ev ___wildcard_x639__16_0, kk_box_t x_0, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_stream_new_streamOfPull_fun490(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_core_stream_streamOfPull_fun490, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_nagare_core_stream_streamOfPull_fun492__t {
  struct kk_function_s _base;
  kk_box_t x_0;
};
static kk_box_t kk_nagare_core_stream_streamOfPull_fun492(kk_function_t _fself, kk_function_t _b_x187, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_stream_new_streamOfPull_fun492(kk_box_t x_0, kk_context_t* _ctx) {
  struct kk_nagare_core_stream_streamOfPull_fun492__t* _self = kk_function_alloc_as(struct kk_nagare_core_stream_streamOfPull_fun492__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_stream_streamOfPull_fun492, kk_context());
  _self->x_0 = x_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_core_stream_streamOfPull_fun493__t {
  struct kk_function_s _base;
  kk_function_t _b_x187;
};
static kk_nagare_core_types__pull kk_nagare_core_stream_streamOfPull_fun493(kk_function_t _fself, kk_std_core_hnd__resume_result _b_x188, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_stream_new_streamOfPull_fun493(kk_function_t _b_x187, kk_context_t* _ctx) {
  struct kk_nagare_core_stream_streamOfPull_fun493__t* _self = kk_function_alloc_as(struct kk_nagare_core_stream_streamOfPull_fun493__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_stream_streamOfPull_fun493, kk_context());
  _self->_b_x187 = _b_x187;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_nagare_core_types__pull kk_nagare_core_stream_streamOfPull_fun493(kk_function_t _fself, kk_std_core_hnd__resume_result _b_x188, kk_context_t* _ctx) {
  struct kk_nagare_core_stream_streamOfPull_fun493__t* _self = kk_function_as(struct kk_nagare_core_stream_streamOfPull_fun493__t*, _fself, _ctx);
  kk_function_t _b_x187 = _self->_b_x187; /* (hnd/resume-result<10000,10002>) -> 10001 10002 */
  kk_drop_match(_self, {kk_function_dup(_b_x187, _ctx);}, {}, _ctx)
  kk_box_t _x_x494 = kk_function_call(kk_box_t, (kk_function_t, kk_std_core_hnd__resume_result, kk_context_t*), _b_x187, (_b_x187, _b_x188, _ctx), _ctx); /*10002*/
  return kk_nagare_core_types__pull_unbox(_x_x494, KK_OWNED, _ctx);
}


// lift anonymous function
struct kk_nagare_core_stream_streamOfPull_fun495__t {
  struct kk_function_s _base;
};
static kk_nagare_core_types__pull kk_nagare_core_stream_streamOfPull_fun495(kk_function_t _fself, kk_box_t x_1, kk_function_t resume_0, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_stream_new_streamOfPull_fun495(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_core_stream_streamOfPull_fun495, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_nagare_core_stream_streamOfPull_fun499__t {
  struct kk_function_s _base;
  kk_function_t resume_0;
};
static kk_nagare_core_types__pull kk_nagare_core_stream_streamOfPull_fun499(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_stream_new_streamOfPull_fun499(kk_function_t resume_0, kk_context_t* _ctx) {
  struct kk_nagare_core_stream_streamOfPull_fun499__t* _self = kk_function_alloc_as(struct kk_nagare_core_stream_streamOfPull_fun499__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_stream_streamOfPull_fun499, kk_context());
  _self->resume_0 = resume_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_nagare_core_types__pull kk_nagare_core_stream_streamOfPull_fun499(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_core_stream_streamOfPull_fun499__t* _self = kk_function_as(struct kk_nagare_core_stream_streamOfPull_fun499__t*, _fself, _ctx);
  kk_function_t resume_0 = _self->resume_0; /* (()) -> 2323 nagare/core/types/pull<2322,2323> */
  kk_drop_match(_self, {kk_function_dup(resume_0, _ctx);}, {}, _ctx)
  return kk_function_call(kk_nagare_core_types__pull, (kk_function_t, kk_unit_t, kk_context_t*), resume_0, (resume_0, kk_Unit, _ctx), _ctx);
}
static kk_nagare_core_types__pull kk_nagare_core_stream_streamOfPull_fun495(kk_function_t _fself, kk_box_t x_1, kk_function_t resume_0, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_nagare_core_types__chunk _x_x496;
  kk_std_core_types__list _x_x497 = kk_std_core_types__new_Cons(kk_reuse_null, 0, x_1, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<10021>*/
  _x_x496 = kk_nagare_core_types__new_Chunk(_x_x497, _ctx); /*nagare/core/types/chunk<4>*/
  kk_nagare_core_types__pull _x_x498 = kk_nagare_core_types__new_PEval(kk_reuse_null, 0, kk_nagare_core_stream_new_streamOfPull_fun499(resume_0, _ctx), _ctx); /*nagare/core/types/pull<19,20>*/
  return kk_nagare_core_types__new_POutput(kk_reuse_null, 0, _x_x496, _x_x498, _ctx);
}


// lift anonymous function
struct kk_nagare_core_stream_streamOfPull_fun500__t {
  struct kk_function_s _base;
  kk_function_t _b_x179_212;
};
static kk_box_t kk_nagare_core_stream_streamOfPull_fun500(kk_function_t _fself, kk_box_t _b_x181, kk_function_t _b_x182, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_stream_new_streamOfPull_fun500(kk_function_t _b_x179_212, kk_context_t* _ctx) {
  struct kk_nagare_core_stream_streamOfPull_fun500__t* _self = kk_function_alloc_as(struct kk_nagare_core_stream_streamOfPull_fun500__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_stream_streamOfPull_fun500, kk_context());
  _self->_b_x179_212 = _b_x179_212;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_core_stream_streamOfPull_fun502__t {
  struct kk_function_s _base;
  kk_function_t _b_x182;
};
static kk_nagare_core_types__pull kk_nagare_core_stream_streamOfPull_fun502(kk_function_t _fself, kk_unit_t _b_x183, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_stream_new_streamOfPull_fun502(kk_function_t _b_x182, kk_context_t* _ctx) {
  struct kk_nagare_core_stream_streamOfPull_fun502__t* _self = kk_function_alloc_as(struct kk_nagare_core_stream_streamOfPull_fun502__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_stream_streamOfPull_fun502, kk_context());
  _self->_b_x182 = _b_x182;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_nagare_core_types__pull kk_nagare_core_stream_streamOfPull_fun502(kk_function_t _fself, kk_unit_t _b_x183, kk_context_t* _ctx) {
  struct kk_nagare_core_stream_streamOfPull_fun502__t* _self = kk_function_as(struct kk_nagare_core_stream_streamOfPull_fun502__t*, _fself, _ctx);
  kk_function_t _b_x182 = _self->_b_x182; /* (10001) -> 10002 10003 */
  kk_drop_match(_self, {kk_function_dup(_b_x182, _ctx);}, {}, _ctx)
  kk_box_t _x_x503 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _b_x182, (_b_x182, kk_unit_box(_b_x183), _ctx), _ctx); /*10003*/
  return kk_nagare_core_types__pull_unbox(_x_x503, KK_OWNED, _ctx);
}
static kk_box_t kk_nagare_core_stream_streamOfPull_fun500(kk_function_t _fself, kk_box_t _b_x181, kk_function_t _b_x182, kk_context_t* _ctx) {
  struct kk_nagare_core_stream_streamOfPull_fun500__t* _self = kk_function_as(struct kk_nagare_core_stream_streamOfPull_fun500__t*, _fself, _ctx);
  kk_function_t _b_x179_212 = _self->_b_x179_212; /* (x@1 : 2322, resume@0 : (()) -> 2323 nagare/core/types/pull<2322,2323>) -> 2323 nagare/core/types/pull<2322,2323> */
  kk_drop_match(_self, {kk_function_dup(_b_x179_212, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull _x_x501 = kk_function_call(kk_nagare_core_types__pull, (kk_function_t, kk_box_t, kk_function_t, kk_context_t*), _b_x179_212, (_b_x179_212, _b_x181, kk_nagare_core_stream_new_streamOfPull_fun502(_b_x182, _ctx), _ctx), _ctx); /*nagare/core/types/pull<2322,2323>*/
  return kk_nagare_core_types__pull_box(_x_x501, _ctx);
}


// lift anonymous function
struct kk_nagare_core_stream_streamOfPull_fun504__t {
  struct kk_function_s _base;
  kk_function_t _b_x180_213;
};
static kk_box_t kk_nagare_core_stream_streamOfPull_fun504(kk_function_t _fself, kk_std_core_hnd__resume_result _b_x184, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_stream_new_streamOfPull_fun504(kk_function_t _b_x180_213, kk_context_t* _ctx) {
  struct kk_nagare_core_stream_streamOfPull_fun504__t* _self = kk_function_alloc_as(struct kk_nagare_core_stream_streamOfPull_fun504__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_stream_streamOfPull_fun504, kk_context());
  _self->_b_x180_213 = _b_x180_213;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_core_stream_streamOfPull_fun504(kk_function_t _fself, kk_std_core_hnd__resume_result _b_x184, kk_context_t* _ctx) {
  struct kk_nagare_core_stream_streamOfPull_fun504__t* _self = kk_function_as(struct kk_nagare_core_stream_streamOfPull_fun504__t*, _fself, _ctx);
  kk_function_t _b_x180_213 = _self->_b_x180_213; /* (hnd/resume-result<(),nagare/core/types/pull<2322,2323>>) -> 2323 nagare/core/types/pull<2322,2323> */
  kk_drop_match(_self, {kk_function_dup(_b_x180_213, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull _x_x505 = kk_function_call(kk_nagare_core_types__pull, (kk_function_t, kk_std_core_hnd__resume_result, kk_context_t*), _b_x180_213, (_b_x180_213, _b_x184, _ctx), _ctx); /*nagare/core/types/pull<2322,2323>*/
  return kk_nagare_core_types__pull_box(_x_x505, _ctx);
}
static kk_box_t kk_nagare_core_stream_streamOfPull_fun492(kk_function_t _fself, kk_function_t _b_x187, kk_context_t* _ctx) {
  struct kk_nagare_core_stream_streamOfPull_fun492__t* _self = kk_function_as(struct kk_nagare_core_stream_streamOfPull_fun492__t*, _fself, _ctx);
  kk_box_t x_0 = _self->x_0; /* 2322 */
  kk_drop_match(_self, {kk_box_dup(x_0, _ctx);}, {}, _ctx)
  kk_function_t k_0_216 = kk_nagare_core_stream_new_streamOfPull_fun493(_b_x187, _ctx); /*(hnd/resume-result<(),nagare/core/types/pull<2322,2323>>) -> 2323 nagare/core/types/pull<2322,2323>*/;
  kk_box_t _b_x178_211 = x_0; /*2322*/;
  kk_function_t _b_x179_212 = kk_nagare_core_stream_new_streamOfPull_fun495(_ctx); /*(x@1 : 2322, resume@0 : (()) -> 2323 nagare/core/types/pull<2322,2323>) -> 2323 nagare/core/types/pull<2322,2323>*/;
  kk_function_t _b_x180_213 = k_0_216; /*(hnd/resume-result<(),nagare/core/types/pull<2322,2323>>) -> 2323 nagare/core/types/pull<2322,2323>*/;
  return kk_std_core_hnd_protect(_b_x178_211, kk_nagare_core_stream_new_streamOfPull_fun500(_b_x179_212, _ctx), kk_nagare_core_stream_new_streamOfPull_fun504(_b_x180_213, _ctx), _ctx);
}
static kk_unit_t kk_nagare_core_stream_streamOfPull_fun490(kk_function_t _fself, int32_t m_0, kk_std_core_hnd__ev ___wildcard_x639__16_0, kk_box_t x_0, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_datatype_ptr_dropn(___wildcard_x639__16_0, (KK_I32(3)), _ctx);
  kk_box_t _x_x491 = kk_std_core_hnd_yield_to(m_0, kk_nagare_core_stream_new_streamOfPull_fun492(x_0, _ctx), _ctx); /*10000*/
  kk_unit_unbox(_x_x491); return kk_Unit;
}


// lift anonymous function
struct kk_nagare_core_stream_streamOfPull_fun508__t {
  struct kk_function_s _base;
  kk_function_t _b_x174_202;
};
static kk_box_t kk_nagare_core_stream_streamOfPull_fun508(kk_function_t _fself, int32_t _b_x175, kk_std_core_hnd__ev _b_x176, kk_box_t _b_x177, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_stream_new_streamOfPull_fun508(kk_function_t _b_x174_202, kk_context_t* _ctx) {
  struct kk_nagare_core_stream_streamOfPull_fun508__t* _self = kk_function_alloc_as(struct kk_nagare_core_stream_streamOfPull_fun508__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_stream_streamOfPull_fun508, kk_context());
  _self->_b_x174_202 = _b_x174_202;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_core_stream_streamOfPull_fun508(kk_function_t _fself, int32_t _b_x175, kk_std_core_hnd__ev _b_x176, kk_box_t _b_x177, kk_context_t* _ctx) {
  struct kk_nagare_core_stream_streamOfPull_fun508__t* _self = kk_function_as(struct kk_nagare_core_stream_streamOfPull_fun508__t*, _fself, _ctx);
  kk_function_t _b_x174_202 = _self->_b_x174_202; /* (m : hnd/marker<2323,nagare/core/types/pull<2322,2323>>, hnd/ev<nagare/core/stream/emitter<2322>>, x : list<2322>) -> 2323 () */
  kk_drop_match(_self, {kk_function_dup(_b_x174_202, _ctx);}, {}, _ctx)
  kk_unit_t _x_x509 = kk_Unit;
  kk_std_core_types__list _x_x510 = kk_std_core_types__list_unbox(_b_x177, KK_OWNED, _ctx); /*list<2322>*/
  kk_function_call(kk_unit_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_std_core_types__list, kk_context_t*), _b_x174_202, (_b_x174_202, _b_x175, _b_x176, _x_x510, _ctx), _ctx);
  return kk_unit_box(_x_x509);
}


// lift anonymous function
struct kk_nagare_core_stream_streamOfPull_fun512__t {
  struct kk_function_s _base;
  kk_function_t _b_x189_208;
};
static kk_box_t kk_nagare_core_stream_streamOfPull_fun512(kk_function_t _fself, int32_t _b_x190, kk_std_core_hnd__ev _b_x191, kk_box_t _b_x192, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_stream_new_streamOfPull_fun512(kk_function_t _b_x189_208, kk_context_t* _ctx) {
  struct kk_nagare_core_stream_streamOfPull_fun512__t* _self = kk_function_alloc_as(struct kk_nagare_core_stream_streamOfPull_fun512__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_stream_streamOfPull_fun512, kk_context());
  _self->_b_x189_208 = _b_x189_208;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_core_stream_streamOfPull_fun512(kk_function_t _fself, int32_t _b_x190, kk_std_core_hnd__ev _b_x191, kk_box_t _b_x192, kk_context_t* _ctx) {
  struct kk_nagare_core_stream_streamOfPull_fun512__t* _self = kk_function_as(struct kk_nagare_core_stream_streamOfPull_fun512__t*, _fself, _ctx);
  kk_function_t _b_x189_208 = _self->_b_x189_208; /* (m@0 : hnd/marker<2323,nagare/core/types/pull<2322,2323>>, hnd/ev<nagare/core/stream/emitter<2322>>, x@0 : 2322) -> 2323 () */
  kk_drop_match(_self, {kk_function_dup(_b_x189_208, _ctx);}, {}, _ctx)
  kk_unit_t _x_x513 = kk_Unit;
  kk_function_call(kk_unit_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _b_x189_208, (_b_x189_208, _b_x190, _b_x191, _b_x192, _ctx), _ctx);
  return kk_unit_box(_x_x513);
}


// lift anonymous function
struct kk_nagare_core_stream_streamOfPull_fun514__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_core_stream_streamOfPull_fun514(kk_function_t _fself, kk_box_t _b_x198, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_stream_new_streamOfPull_fun514(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_core_stream_streamOfPull_fun514, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_core_stream_streamOfPull_fun514(kk_function_t _fself, kk_box_t _b_x198, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_nagare_core_types__pull _res_217 = kk_nagare_core_types__pull_unbox(_b_x198, KK_OWNED, _ctx); /*nagare/core/types/pull<2322,2323>*/;
  return kk_nagare_core_types__pull_box(_res_217, _ctx);
}


// lift anonymous function
struct kk_nagare_core_stream_streamOfPull_fun515__t {
  struct kk_function_s _base;
  kk_function_t body;
};
static kk_box_t kk_nagare_core_stream_streamOfPull_fun515(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_stream_new_streamOfPull_fun515(kk_function_t body, kk_context_t* _ctx) {
  struct kk_nagare_core_stream_streamOfPull_fun515__t* _self = kk_function_alloc_as(struct kk_nagare_core_stream_streamOfPull_fun515__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_stream_streamOfPull_fun515, kk_context());
  _self->body = body;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_core_stream_streamOfPull_fun518__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_core_stream_streamOfPull_fun518(kk_function_t _fself, kk_box_t _b_x194, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_stream_new_streamOfPull_fun518(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_core_stream_streamOfPull_fun518, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_core_stream_streamOfPull_fun518(kk_function_t _fself, kk_box_t _b_x194, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t wild___218 = kk_Unit;
  kk_unit_unbox(_b_x194);
  return kk_nagare_core_types__pull_box(kk_nagare_core_types__new_PDone(_ctx), _ctx);
}
static kk_box_t kk_nagare_core_stream_streamOfPull_fun515(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_core_stream_streamOfPull_fun515__t* _self = kk_function_as(struct kk_nagare_core_stream_streamOfPull_fun515__t*, _fself, _ctx);
  kk_function_t body = _self->body; /* () -> <nagare/core/stream/emitter<2322>|2323> () */
  kk_drop_match(_self, {kk_function_dup(body, _ctx);}, {}, _ctx)
  kk_unit_t x_2_10494 = kk_Unit;
  kk_function_call(kk_unit_t, (kk_function_t, kk_context_t*), body, (body, _ctx), _ctx);
  kk_nagare_core_types__pull _x_x516;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x517 = kk_std_core_hnd_yield_extend(kk_nagare_core_stream_new_streamOfPull_fun518(_ctx), _ctx); /*10001*/
    _x_x516 = kk_nagare_core_types__pull_unbox(_x_x517, KK_OWNED, _ctx); /*nagare/core/types/pull<2322,2323>*/
  }
  else {
    _x_x516 = kk_nagare_core_types__new_PDone(_ctx); /*nagare/core/types/pull<2322,2323>*/
  }
  return kk_nagare_core_types__pull_box(_x_x516, _ctx);
}

kk_nagare_core_types__pull kk_nagare_core_stream_streamOfPull(kk_function_t body, kk_context_t* _ctx) { /* forall<a,e> (body : () -> <emitter<a>|e> ()) -> e nagare/core/types/pull<a,e> */ 
  kk_box_t _x_x473;
  kk_function_t _b_x174_202 = kk_nagare_core_stream_new_streamOfPull_fun474(_ctx); /*(m : hnd/marker<2323,nagare/core/types/pull<2322,2323>>, hnd/ev<nagare/core/stream/emitter<2322>>, x : list<2322>) -> 2323 ()*/;
  kk_function_t _b_x189_208 = kk_nagare_core_stream_new_streamOfPull_fun490(_ctx); /*(m@0 : hnd/marker<2323,nagare/core/types/pull<2322,2323>>, hnd/ev<nagare/core/stream/emitter<2322>>, x@0 : 2322) -> 2323 ()*/;
  kk_nagare_core_stream__emitter _x_x506;
  kk_std_core_hnd__clause1 _x_x507 = kk_std_core_hnd__new_Clause1(kk_nagare_core_stream_new_streamOfPull_fun508(_b_x174_202, _ctx), _ctx); /*hnd/clause1<10015,10016,10017,10018,10019>*/
  kk_std_core_hnd__clause1 _x_x511 = kk_std_core_hnd__new_Clause1(kk_nagare_core_stream_new_streamOfPull_fun512(_b_x189_208, _ctx), _ctx); /*hnd/clause1<10015,10016,10017,10018,10019>*/
  _x_x506 = kk_nagare_core_stream__new_Hnd_emitter(kk_reuse_null, 0, kk_integer_from_small(3), _x_x507, _x_x511, _ctx); /*nagare/core/stream/emitter<16,17,18>*/
  _x_x473 = kk_nagare_core_stream_emitter_fs__handle(_x_x506, kk_nagare_core_stream_new_streamOfPull_fun514(_ctx), kk_nagare_core_stream_new_streamOfPull_fun515(body, _ctx), _ctx); /*1834*/
  return kk_nagare_core_types__pull_unbox(_x_x473, KK_OWNED, _ctx);
}
 
// Build a stream from an imperative body that calls yieldOne/yieldAll.


// lift anonymous function
struct kk_nagare_core_stream_streamOf_fun520__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_core_stream_streamOf_fun520(kk_function_t _fself, kk_box_t _b_x220, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_stream_new_streamOf_fun520(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_core_stream_streamOf_fun520, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_core_stream_streamOf_fun520(kk_function_t _fself, kk_box_t _b_x220, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_nagare_core_types__pull _y_x10416_222 = kk_nagare_core_types__pull_unbox(_b_x220, KK_OWNED, _ctx); /*nagare/core/types/pull<2360,2361>*/;
  kk_nagare_core_types__nstream _x_x521 = kk_nagare_core_types__new_Stream(_y_x10416_222, _ctx); /*nagare/core/types/nstream<27,28>*/
  return kk_nagare_core_types__nstream_box(_x_x521, _ctx);
}

kk_nagare_core_types__nstream kk_nagare_core_stream_streamOf(kk_function_t body, kk_context_t* _ctx) { /* forall<a,e> (body : () -> <emitter<a>|e> ()) -> e nagare/core/types/nstream<a,e> */ 
  kk_nagare_core_types__pull x_10497 = kk_nagare_core_stream_streamOfPull(body, _ctx); /*nagare/core/types/pull<2360,2361>*/;
  if (kk_yielding(kk_context())) {
    kk_nagare_core_types__pull_drop(x_10497, _ctx);
    kk_box_t _x_x519 = kk_std_core_hnd_yield_extend(kk_nagare_core_stream_new_streamOf_fun520(_ctx), _ctx); /*10001*/
    return kk_nagare_core_types__nstream_unbox(_x_x519, KK_OWNED, _ctx);
  }
  {
    return kk_nagare_core_types__new_Stream(x_10497, _ctx);
  }
}

// initialization
void kk_nagare_core_stream__init(kk_context_t* _ctx){
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
  kk_nagare_core_pull__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
  {
    kk_string_t _x_x460;
    kk_define_string_literal(static, _s_x461, 14, "emitter@stream", _ctx)
    _x_x460 = kk_string_dup(_s_x461, _ctx); /*string*/
    kk_nagare_core_stream_emitter_fs__tag = kk_std_core_hnd__new_Htag(_x_x460, _ctx); /*forall<a> hnd/htag<nagare/core/stream/emitter<a>>*/
  }
}

// termination
void kk_nagare_core_stream__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_std_core_hnd__htag_drop(kk_nagare_core_stream_emitter_fs__tag, _ctx);
  kk_nagare_core_pull__done(_ctx);
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
