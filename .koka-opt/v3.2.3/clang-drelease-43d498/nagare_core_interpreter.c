// Koka generated module: nagare/core/interpreter, koka version: 3.2.3, platform: 64-bit
#include "nagare_core_interpreter.h"

kk_nagare_core_interpreter__compile_scope kk_nagare_core_interpreter_compile_scope_fs__copy(kk_nagare_core_interpreter__compile_scope _this, kk_std_core_types__optional source, kk_context_t* _ctx) { /* forall<a,e> (compile-scope<a,e>, source : ? (nagare/core/types/nstream<a,<io|e>>)) -> compile-scope<a,e> */ 
  kk_nagare_core_types__nstream _x_x436;
  if (kk_std_core_types__is_Optional(source, _ctx)) {
    kk_box_t _box_x0 = source._cons._Optional.value;
    kk_nagare_core_types__nstream _uniq_source_468 = kk_nagare_core_types__nstream_unbox(_box_x0, KK_BORROWED, _ctx);
    kk_nagare_core_types__nstream_dup(_uniq_source_468, _ctx);
    kk_std_core_types__optional_drop(source, _ctx);
    kk_nagare_core_interpreter__compile_scope_drop(_this, _ctx);
    _x_x436 = _uniq_source_468; /*nagare/core/types/nstream<490,<io|491>>*/
  }
  else {
    kk_std_core_types__optional_drop(source, _ctx);
    {
      kk_nagare_core_types__nstream _x = _this.source;
      _x_x436 = _x; /*nagare/core/types/nstream<490,<io|491>>*/
    }
  }
  return kk_nagare_core_interpreter__new_Compile(_x_x436, _ctx);
}

kk_nagare_core_interpreter__runtime kk_nagare_core_interpreter_runtime_fs__copy(kk_nagare_core_interpreter__runtime _this, kk_std_core_types__optional step, kk_std_core_types__optional finalizers, kk_context_t* _ctx) { /* forall<a,e> (runtime<a,e>, step : ? (nagare/core/types/pull<a,<io|e>>), finalizers : ? (ref<global,list<() -> <io|e> ()>>)) -> runtime<a,e> */ 
  kk_nagare_core_types__pull _x_x439;
  if (kk_std_core_types__is_Optional(step, _ctx)) {
    kk_box_t _box_x1 = step._cons._Optional.value;
    kk_nagare_core_types__pull _uniq_step_574 = kk_nagare_core_types__pull_unbox(_box_x1, KK_BORROWED, _ctx);
    kk_nagare_core_types__pull_dup(_uniq_step_574, _ctx);
    kk_std_core_types__optional_drop(step, _ctx);
    _x_x439 = _uniq_step_574; /*nagare/core/types/pull<611,<io|612>>*/
  }
  else {
    kk_std_core_types__optional_drop(step, _ctx);
    {
      struct kk_nagare_core_interpreter_Runtime* _con_x440 = kk_nagare_core_interpreter__as_Runtime(_this, _ctx);
      kk_nagare_core_types__pull _x = _con_x440->step;
      kk_nagare_core_types__pull_dup(_x, _ctx);
      _x_x439 = _x; /*nagare/core/types/pull<611,<io|612>>*/
    }
  }
  kk_ref_t _x_x441;
  if (kk_std_core_types__is_Optional(finalizers, _ctx)) {
    kk_box_t _box_x2 = finalizers._cons._Optional.value;
    kk_ref_t _uniq_finalizers_588 = kk_ref_unbox(_box_x2, _ctx);
    kk_ref_dup(_uniq_finalizers_588, _ctx);
    kk_std_core_types__optional_drop(finalizers, _ctx);
    kk_datatype_ptr_dropn(_this, (KK_I32(2)), _ctx);
    _x_x441 = _uniq_finalizers_588; /*ref<global,list<() -> <io|612> ()>>*/
  }
  else {
    kk_std_core_types__optional_drop(finalizers, _ctx);
    {
      struct kk_nagare_core_interpreter_Runtime* _con_x442 = kk_nagare_core_interpreter__as_Runtime(_this, _ctx);
      kk_nagare_core_types__pull _pat_0_1 = _con_x442->step;
      kk_ref_t _x_0 = _con_x442->finalizers;
      if kk_likely(kk_datatype_ptr_is_unique(_this, _ctx)) {
        kk_nagare_core_types__pull_drop(_pat_0_1, _ctx);
        kk_datatype_ptr_free(_this, _ctx);
      }
      else {
        kk_ref_dup(_x_0, _ctx);
        kk_datatype_ptr_decref(_this, _ctx);
      }
      _x_x441 = _x_0; /*ref<global,list<() -> <io|612> ()>>*/
    }
  }
  return kk_nagare_core_interpreter__new_Runtime(kk_reuse_null, 0, _x_x439, _x_x441, _ctx);
}
 
// lifted local: listReverse, go

kk_std_core_types__list kk_nagare_core_interpreter__unroll_lift_listReverse_2558_10000(kk_std_core_types__list rest, kk_std_core_types__list acc, kk_context_t* _ctx) { /* forall<a> (rest : list<a>, acc : list<a>) -> list<a> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Nil(rest, _ctx)) {
    return acc;
  }
  {
    struct kk_std_core_types_Cons* _con_x443 = kk_std_core_types__as_Cons(rest, _ctx);
    kk_box_t x = _con_x443->head;
    kk_std_core_types__list xt = _con_x443->tail;
    kk_reuse_t _ru_x404 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(rest, _ctx)) {
      _ru_x404 = (kk_datatype_ptr_reuse(rest, _ctx));
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xt, _ctx);
      kk_datatype_ptr_decref(rest, _ctx);
    }
    { // tailcall
      kk_std_core_types__list _x_x444 = kk_std_core_types__new_Cons(_ru_x404, 0, x, acc, _ctx); /*list<10021>*/
      rest = xt;
      acc = _x_x444;
      goto kk__tailcall;
    }
  }
}
 
// Prepend all elements of a list onto an accumulator in reverse order.

kk_std_core_types__list kk_nagare_core_interpreter__unroll_consAllRev_10001(kk_std_core_types__list xs, kk_std_core_types__list accRev, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, accRev : list<a>) -> list<a> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    return accRev;
  }
  {
    struct kk_std_core_types_Cons* _con_x445 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x445->head;
    kk_std_core_types__list xt = _con_x445->tail;
    kk_reuse_t _ru_x405 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      _ru_x405 = (kk_datatype_ptr_reuse(xs, _ctx));
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xt, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    { // tailcall
      kk_std_core_types__list _x_x446 = kk_std_core_types__new_Cons(_ru_x405, 0, x, accRev, _ctx); /*list<10021>*/
      xs = xt;
      accRev = _x_x446;
      goto kk__tailcall;
    }
  }
}
 
// Get the last element of a list, or fallback if empty.

kk_std_core_types__maybe kk_nagare_core_interpreter__unroll_lastInList_10002(kk_std_core_types__list xs, kk_std_core_types__maybe fallback, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, fallback : maybe<a>) -> maybe<a> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    return fallback;
  }
  {
    struct kk_std_core_types_Cons* _con_x447 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x447->head;
    kk_std_core_types__list xt = _con_x447->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xt, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    kk_std_core_types__maybe_drop(fallback, _ctx);
    { // tailcall
      kk_std_core_types__maybe _x_x448 = kk_std_core_types__new_Just(x, _ctx); /*maybe<10024>*/
      xs = xt;
      fallback = _x_x448;
      goto kk__tailcall;
    }
  }
}
 
// Strict left fold over a list.

kk_box_t kk_nagare_core_interpreter__unroll_foldList_10003(kk_std_core_types__list xs, kk_box_t init, kk_function_t step, kk_context_t* _ctx) { /* forall<a,b> (xs : list<a>, init : b, step : (b, a) -> b) -> b */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_function_drop(step, _ctx);
    return init;
  }
  {
    struct kk_std_core_types_Cons* _con_x449 = kk_std_core_types__as_Cons(xs, _ctx);
    kk_box_t x = _con_x449->head;
    kk_std_core_types__list xt = _con_x449->tail;
    if kk_likely(kk_datatype_ptr_is_unique(xs, _ctx)) {
      kk_datatype_ptr_free(xs, _ctx);
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xt, _ctx);
      kk_datatype_ptr_decref(xs, _ctx);
    }
    { // tailcall
      kk_box_t _x_x450;
      kk_function_t _x_x451 = kk_function_dup(step, _ctx); /*(806, 805) -> 806*/
      _x_x450 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_box_t, kk_context_t*), _x_x451, (_x_x451, init, x, _ctx), _ctx); /*806*/
      xs = xt;
      init = _x_x450;
      goto kk__tailcall;
    }
  }
}
 
// monadic lift

kk_unit_t kk_nagare_core_interpreter__mlift_unroll_runFinalizersRev_10004_10328(kk_std_core_types__list rest, kk_unit_t wild__, kk_context_t* _ctx) { /* forall<e> (rest : list<() -> <io|e> ()>, wild_ : ()) -> <io|e> () */ 
  kk_nagare_core_interpreter__unroll_runFinalizersRev_10004(rest, _ctx); return kk_Unit;
}
 
// Run finalizers in LIFO order.


// lift anonymous function
struct kk_nagare_core_interpreter__unroll_runFinalizersRev_10004_fun456__t {
  struct kk_function_s _base;
  kk_std_core_types__list rest_0;
};
static kk_box_t kk_nagare_core_interpreter__unroll_runFinalizersRev_10004_fun456(kk_function_t _fself, kk_box_t _b_x7, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_interpreter__new_unroll_runFinalizersRev_10004_fun456(kk_std_core_types__list rest_0, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter__unroll_runFinalizersRev_10004_fun456__t* _self = kk_function_alloc_as(struct kk_nagare_core_interpreter__unroll_runFinalizersRev_10004_fun456__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_interpreter__unroll_runFinalizersRev_10004_fun456, kk_context());
  _self->rest_0 = rest_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_core_interpreter__unroll_runFinalizersRev_10004_fun456(kk_function_t _fself, kk_box_t _b_x7, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter__unroll_runFinalizersRev_10004_fun456__t* _self = kk_function_as(struct kk_nagare_core_interpreter__unroll_runFinalizersRev_10004_fun456__t*, _fself, _ctx);
  kk_std_core_types__list rest_0 = _self->rest_0; /* list<() -> <io|839> ()> */
  kk_drop_match(_self, {kk_std_core_types__list_dup(rest_0, _ctx);}, {}, _ctx)
  kk_unit_t wild___0_9 = kk_Unit;
  kk_unit_unbox(_b_x7);
  kk_unit_t _x_x457 = kk_Unit;
  kk_nagare_core_interpreter__mlift_unroll_runFinalizersRev_10004_10328(rest_0, wild___0_9, _ctx);
  return kk_unit_box(_x_x457);
}

kk_unit_t kk_nagare_core_interpreter__unroll_runFinalizersRev_10004(kk_std_core_types__list finalizersRev, kk_context_t* _ctx) { /* forall<e> (finalizersRev : list<() -> <io|e> ()>) -> <io|e> () */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Nil(finalizersRev, _ctx)) {
    kk_Unit; return kk_Unit;
  }
  {
    struct kk_std_core_types_Cons* _con_x452 = kk_std_core_types__as_Cons(finalizersRev, _ctx);
    kk_box_t _fun_unbox_x4 = _con_x452->head;
    kk_std_core_types__list rest_0 = _con_x452->tail;
    if kk_likely(kk_datatype_ptr_is_unique(finalizersRev, _ctx)) {
      kk_datatype_ptr_free(finalizersRev, _ctx);
    }
    else {
      kk_box_dup(_fun_unbox_x4, _ctx);
      kk_std_core_types__list_dup(rest_0, _ctx);
      kk_datatype_ptr_decref(finalizersRev, _ctx);
    }
    kk_unit_t x_10353 = kk_Unit;
    kk_box_t _x_x453;
    kk_function_t _x_x454 = kk_function_unbox(_fun_unbox_x4, _ctx); /*() -> <io|839> 5*/
    _x_x453 = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), _x_x454, (_x_x454, _ctx), _ctx); /*5*/
    kk_unit_unbox(_x_x453);
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x455 = kk_std_core_hnd_yield_extend(kk_nagare_core_interpreter__new_unroll_runFinalizersRev_10004_fun456(rest_0, _ctx), _ctx); /*10001*/
      kk_unit_unbox(_x_x455); return kk_Unit;
    }
    { // tailcall
      finalizersRev = rest_0;
      goto kk__tailcall;
    }
  }
}
 
// Run all currently registered finalizers in LIFO order, clearing the stack.
// Safe to call multiple times: subsequent calls see an empty stack and no-op.

kk_unit_t kk_nagare_core_interpreter_closeRuntime(kk_nagare_core_interpreter__runtime state, kk_context_t* _ctx) { /* forall<a,e> (state : runtime<a,e>) -> <io|e> () */ 
  {
    struct kk_nagare_core_interpreter_Runtime* _con_x460 = kk_nagare_core_interpreter__as_Runtime(state, _ctx);
    kk_nagare_core_types__pull _pat_0 = _con_x460->step;
    kk_ref_t finalizers = _con_x460->finalizers;
    if kk_likely(kk_datatype_ptr_is_unique(state, _ctx)) {
      kk_nagare_core_types__pull_drop(_pat_0, _ctx);
      kk_datatype_ptr_free(state, _ctx);
    }
    else {
      kk_ref_dup(finalizers, _ctx);
      kk_datatype_ptr_decref(state, _ctx);
    }
    kk_std_core_types__list pending;
    kk_box_t _x_x461;
    kk_ref_t _x_x462 = kk_ref_dup(finalizers, _ctx); /*ref<global,list<() -> <io|962> ()>>*/
    _x_x461 = kk_ref_get(_x_x462,kk_context()); /*10000*/
    pending = kk_std_core_types__list_unbox(_x_x461, KK_OWNED, _ctx); /*list<() -> <io|962> ()>*/
    kk_unit_t __ = kk_Unit;
    kk_unit_t _brw_x400 = kk_Unit;
    kk_ref_set_borrow(finalizers,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context());
    kk_ref_drop(finalizers, _ctx);
    _brw_x400;
    if (kk_std_core_types__is_Nil(pending, _ctx)) {
      kk_Unit; return kk_Unit;
    }
    {
      kk_nagare_core_interpreter__unroll_runFinalizersRev_10004(pending, _ctx); return kk_Unit;
    }
  }
}
 
// monadic lift


// lift anonymous function
struct kk_nagare_core_interpreter__mlift_withRuntime_10329_fun464__t {
  struct kk_function_s _base;
  kk_nagare_core_interpreter__runtime state;
};
static kk_unit_t kk_nagare_core_interpreter__mlift_withRuntime_10329_fun464(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_interpreter__new_mlift_withRuntime_10329_fun464(kk_nagare_core_interpreter__runtime state, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter__mlift_withRuntime_10329_fun464__t* _self = kk_function_alloc_as(struct kk_nagare_core_interpreter__mlift_withRuntime_10329_fun464__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_interpreter__mlift_withRuntime_10329_fun464, kk_context());
  _self->state = state;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_unit_t kk_nagare_core_interpreter__mlift_withRuntime_10329_fun464(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter__mlift_withRuntime_10329_fun464__t* _self = kk_function_as(struct kk_nagare_core_interpreter__mlift_withRuntime_10329_fun464__t*, _fself, _ctx);
  kk_nagare_core_interpreter__runtime state = _self->state; /* nagare/core/interpreter/runtime<1016,1018> */
  kk_drop_match(_self, {kk_nagare_core_interpreter__runtime_dup(state, _ctx);}, {}, _ctx)
  {
    struct kk_nagare_core_interpreter_Runtime* _con_x465 = kk_nagare_core_interpreter__as_Runtime(state, _ctx);
    kk_nagare_core_types__pull _pat_0 = _con_x465->step;
    kk_ref_t finalizers = _con_x465->finalizers;
    if kk_likely(kk_datatype_ptr_is_unique(state, _ctx)) {
      kk_nagare_core_types__pull_drop(_pat_0, _ctx);
      kk_datatype_ptr_free(state, _ctx);
    }
    else {
      kk_ref_dup(finalizers, _ctx);
      kk_datatype_ptr_decref(state, _ctx);
    }
    kk_std_core_types__list pending;
    kk_box_t _x_x466;
    kk_ref_t _x_x467 = kk_ref_dup(finalizers, _ctx); /*ref<global,list<() -> <io|1018> ()>>*/
    _x_x466 = kk_ref_get(_x_x467,kk_context()); /*10000*/
    pending = kk_std_core_types__list_unbox(_x_x466, KK_OWNED, _ctx); /*list<() -> <io|1018> ()>*/
    kk_unit_t __ = kk_Unit;
    kk_unit_t _brw_x399 = kk_Unit;
    kk_ref_set_borrow(finalizers,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context());
    kk_ref_drop(finalizers, _ctx);
    _brw_x399;
    if (kk_std_core_types__is_Nil(pending, _ctx)) {
      kk_Unit; return kk_Unit;
    }
    {
      kk_nagare_core_interpreter__unroll_runFinalizersRev_10004(pending, _ctx); return kk_Unit;
    }
  }
}

kk_box_t kk_nagare_core_interpreter__mlift_withRuntime_10329(kk_function_t body, kk_nagare_core_interpreter__runtime state, kk_context_t* _ctx) { /* forall<a,b,e> (body : (runtime<a,e>) -> <io|e> b, state : runtime<a,e>) -> <io|e> b */ 
  kk_function_t _x_x463;
  kk_nagare_core_interpreter__runtime_dup(state, _ctx);
  _x_x463 = kk_nagare_core_interpreter__new_mlift_withRuntime_10329_fun464(state, _ctx); /*() -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>|1018> ()*/
  kk_box_t _x_x468 = kk_function_call(kk_box_t, (kk_function_t, kk_nagare_core_interpreter__runtime, kk_context_t*), body, (body, state, _ctx), _ctx); /*1017*/
  return kk_std_core_hnd_finally_prompt(_x_x463, _x_x468, _ctx);
}
 
// Bracket a sink body so finalizers always run, even on early return or exception.


// lift anonymous function
struct kk_nagare_core_interpreter_withRuntime_fun469__t {
  struct kk_function_s _base;
  kk_function_t body;
};
static kk_box_t kk_nagare_core_interpreter_withRuntime_fun469(kk_function_t _fself, kk_box_t _b_x29, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_interpreter_new_withRuntime_fun469(kk_function_t body, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter_withRuntime_fun469__t* _self = kk_function_alloc_as(struct kk_nagare_core_interpreter_withRuntime_fun469__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_interpreter_withRuntime_fun469, kk_context());
  _self->body = body;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_core_interpreter_withRuntime_fun469(kk_function_t _fself, kk_box_t _b_x29, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter_withRuntime_fun469__t* _self = kk_function_as(struct kk_nagare_core_interpreter_withRuntime_fun469__t*, _fself, _ctx);
  kk_function_t body = _self->body; /* (nagare/core/interpreter/runtime<1016,1018>) -> <io|1018> 1017 */
  kk_drop_match(_self, {kk_function_dup(body, _ctx);}, {}, _ctx)
  kk_nagare_core_interpreter__runtime _x_x470 = kk_nagare_core_interpreter__runtime_unbox(_b_x29, KK_OWNED, _ctx); /*nagare/core/interpreter/runtime<1016,1018>*/
  return kk_nagare_core_interpreter__mlift_withRuntime_10329(body, _x_x470, _ctx);
}


// lift anonymous function
struct kk_nagare_core_interpreter_withRuntime_fun472__t {
  struct kk_function_s _base;
  kk_nagare_core_interpreter__runtime x_10361;
};
static kk_unit_t kk_nagare_core_interpreter_withRuntime_fun472(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_interpreter_new_withRuntime_fun472(kk_nagare_core_interpreter__runtime x_10361, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter_withRuntime_fun472__t* _self = kk_function_alloc_as(struct kk_nagare_core_interpreter_withRuntime_fun472__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_interpreter_withRuntime_fun472, kk_context());
  _self->x_10361 = x_10361;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_unit_t kk_nagare_core_interpreter_withRuntime_fun472(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter_withRuntime_fun472__t* _self = kk_function_as(struct kk_nagare_core_interpreter_withRuntime_fun472__t*, _fself, _ctx);
  kk_nagare_core_interpreter__runtime x_10361 = _self->x_10361; /* nagare/core/interpreter/runtime<1016,1018> */
  kk_drop_match(_self, {kk_nagare_core_interpreter__runtime_dup(x_10361, _ctx);}, {}, _ctx)
  {
    struct kk_nagare_core_interpreter_Runtime* _con_x473 = kk_nagare_core_interpreter__as_Runtime(x_10361, _ctx);
    kk_nagare_core_types__pull _pat_0_0 = _con_x473->step;
    kk_ref_t finalizers = _con_x473->finalizers;
    if kk_likely(kk_datatype_ptr_is_unique(x_10361, _ctx)) {
      kk_nagare_core_types__pull_drop(_pat_0_0, _ctx);
      kk_datatype_ptr_free(x_10361, _ctx);
    }
    else {
      kk_ref_dup(finalizers, _ctx);
      kk_datatype_ptr_decref(x_10361, _ctx);
    }
    kk_std_core_types__list pending;
    kk_box_t _x_x474;
    kk_ref_t _x_x475 = kk_ref_dup(finalizers, _ctx); /*ref<global,list<() -> <io|1018> ()>>*/
    _x_x474 = kk_ref_get(_x_x475,kk_context()); /*10000*/
    pending = kk_std_core_types__list_unbox(_x_x474, KK_OWNED, _ctx); /*list<() -> <io|1018> ()>*/
    kk_unit_t __ = kk_Unit;
    kk_unit_t _brw_x398 = kk_Unit;
    kk_ref_set_borrow(finalizers,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context());
    kk_ref_drop(finalizers, _ctx);
    _brw_x398;
    if (kk_std_core_types__is_Nil(pending, _ctx)) {
      kk_Unit; return kk_Unit;
    }
    {
      kk_nagare_core_interpreter__unroll_runFinalizersRev_10004(pending, _ctx); return kk_Unit;
    }
  }
}

kk_box_t kk_nagare_core_interpreter_withRuntime(kk_nagare_core_types__nstream source, kk_function_t body, kk_context_t* _ctx) { /* forall<a,b,e> (source : nagare/core/types/nstream<a,<io|e>>, body : (runtime<a,e>) -> <io|e> b) -> <io|e> b */ 
  kk_nagare_core_interpreter__runtime x_10361 = kk_nagare_core_interpreter_runtimeFromStream(source, _ctx); /*nagare/core/interpreter/runtime<1016,1018>*/;
  if (kk_yielding(kk_context())) {
    kk_datatype_ptr_dropn(x_10361, (KK_I32(2)), _ctx);
    return kk_std_core_hnd_yield_extend(kk_nagare_core_interpreter_new_withRuntime_fun469(body, _ctx), _ctx);
  }
  {
    kk_function_t _x_x471;
    kk_nagare_core_interpreter__runtime_dup(x_10361, _ctx);
    _x_x471 = kk_nagare_core_interpreter_new_withRuntime_fun472(x_10361, _ctx); /*() -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>|1018> ()*/
    kk_box_t _x_x476 = kk_function_call(kk_box_t, (kk_function_t, kk_nagare_core_interpreter__runtime, kk_context_t*), body, (body, x_10361, _ctx), _ctx); /*1017*/
    return kk_std_core_hnd_finally_prompt(_x_x471, _x_x476, _ctx);
  }
}
 
// Record TraceEmit events for values, accumulating in reverse.

kk_std_core_types__list kk_nagare_core_interpreter__unroll_pushTraceEventsRev_10005(kk_std_core_types__list values, kk_std_core_types__list eventsRev, kk_context_t* _ctx) { /* forall<a> (values : list<a>, eventsRev : list<trace-event<a>>) -> list<trace-event<a>> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Nil(values, _ctx)) {
    return eventsRev;
  }
  {
    struct kk_std_core_types_Cons* _con_x477 = kk_std_core_types__as_Cons(values, _ctx);
    kk_box_t x = _con_x477->head;
    kk_std_core_types__list xt = _con_x477->tail;
    kk_reuse_t _ru_x412 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(values, _ctx)) {
      _ru_x412 = (kk_datatype_ptr_reuse(values, _ctx));
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xt, _ctx);
      kk_datatype_ptr_decref(values, _ctx);
    }
    { // tailcall
      kk_std_core_types__list _x_x478;
      kk_box_t _x_x479;
      kk_nagare_core_interpreter__trace_event _x_x480 = kk_nagare_core_interpreter__new_TraceEmit(x, _ctx); /*nagare/core/interpreter/trace-event<39>*/
      _x_x479 = kk_nagare_core_interpreter__trace_event_box(_x_x480, _ctx); /*10021*/
      _x_x478 = kk_std_core_types__new_Cons(_ru_x412, 0, _x_x479, eventsRev, _ctx); /*list<10021>*/
      values = xt;
      eventsRev = _x_x478;
      goto kk__tailcall;
    }
  }
}
 
// Take next element from a chunk, returning remaining pull state.

kk_std_core_types__maybe2 kk_nagare_core_interpreter_nextFromChunk(kk_std_core_types__list values, kk_nagare_core_types__pull tail, kk_context_t* _ctx) { /* forall<a,e> (values : list<a>, tail : nagare/core/types/pull<a,<io|e>>) -> maybe2<a,nagare/core/types/pull<a,<io|e>>> */ 
  if (kk_std_core_types__is_Nil(values, _ctx)) {
    kk_nagare_core_types__pull_drop(tail, _ctx);
    return kk_std_core_types__new_Nothing2(_ctx);
  }
  {
    struct kk_std_core_types_Cons* _con_x481 = kk_std_core_types__as_Cons(values, _ctx);
    kk_box_t x = _con_x481->head;
    kk_std_core_types__list xt = _con_x481->tail;
    kk_reuse_t _ru_x413 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(values, _ctx)) {
      _ru_x413 = (kk_datatype_ptr_reuse(values, _ctx));
    }
    else {
      kk_box_dup(x, _ctx);
      kk_std_core_types__list_dup(xt, _ctx);
      kk_datatype_ptr_decref(values, _ctx);
    }
    if (kk_std_core_types__is_Nil(xt, _ctx)) {
      kk_reuse_drop(_ru_x413,kk_context());
      return kk_std_core_types__new_Just2(x, kk_nagare_core_types__pull_box(tail, _ctx), _ctx);
    }
    {
      kk_box_t _x_x482;
      kk_nagare_core_types__pull _x_x483;
      kk_nagare_core_types__chunk _x_x484 = kk_nagare_core_types__new_Chunk(xt, _ctx); /*nagare/core/types/chunk<4>*/
      _x_x483 = kk_nagare_core_types__new_POutput(_ru_x413, 0, _x_x484, tail, _ctx); /*nagare/core/types/pull<19,20>*/
      _x_x482 = kk_nagare_core_types__pull_box(_x_x483, _ctx); /*10028*/
      return kk_std_core_types__new_Just2(x, _x_x482, _ctx);
    }
  }
}
 
// monadic lift

kk_std_core_types__maybe2 kk_nagare_core_interpreter__mlift_nextItemRuntime_10330(kk_ref_t finalizers_0, kk_nagare_core_types__pull _y_x10203, kk_context_t* _ctx) { /* forall<a,e> (finalizers@0 : ref<global,list<() -> <io|e> ()>>, nagare/core/types/pull<a,<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>|e>>) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>|e> maybe2<a,runtime<a,e>> */ 
  kk_nagare_core_interpreter__runtime _x_x485 = kk_nagare_core_interpreter__new_Runtime(kk_reuse_null, 0, _y_x10203, finalizers_0, _ctx); /*nagare/core/interpreter/runtime<21,22>*/
  return kk_nagare_core_interpreter_nextItemRuntime(_x_x485, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_nagare_core_interpreter__mlift_nextItemRuntime_10331_fun490__t {
  struct kk_function_s _base;
  kk_function_t release;
};
static kk_box_t kk_nagare_core_interpreter__mlift_nextItemRuntime_10331_fun490(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_interpreter__new_mlift_nextItemRuntime_10331_fun490(kk_function_t release, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter__mlift_nextItemRuntime_10331_fun490__t* _self = kk_function_alloc_as(struct kk_nagare_core_interpreter__mlift_nextItemRuntime_10331_fun490__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_interpreter__mlift_nextItemRuntime_10331_fun490, kk_context());
  _self->release = release;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_core_interpreter__mlift_nextItemRuntime_10331_fun490(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter__mlift_nextItemRuntime_10331_fun490__t* _self = kk_function_as(struct kk_nagare_core_interpreter__mlift_nextItemRuntime_10331_fun490__t*, _fself, _ctx);
  kk_function_t release = _self->release; /* () -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>|1394> () */
  kk_drop_match(_self, {kk_function_dup(release, _ctx);}, {}, _ctx)
  kk_unit_t _x_x491 = kk_Unit;
  kk_function_call(kk_unit_t, (kk_function_t, kk_context_t*), release, (release, _ctx), _ctx);
  return kk_unit_box(_x_x491);
}

kk_std_core_types__maybe2 kk_nagare_core_interpreter__mlift_nextItemRuntime_10331(kk_ref_t finalizers_1, kk_function_t release, kk_nagare_core_types__pull tail_0, kk_unit_t wild__, kk_context_t* _ctx) { /* forall<a,e> (finalizers@1 : ref<global,list<() -> <io|e> ()>>, release : () -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>|e> (), tail@0 : nagare/core/types/pull<a,<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>|e>>, wild_ : ()) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>|e> maybe2<a,runtime<a,e>> */ 
  kk_std_core_types__list _b_x55_62;
  kk_box_t _x_x486;
  kk_ref_t _x_x487 = kk_ref_dup(finalizers_1, _ctx); /*ref<global,list<() -> <io|1394> ()>>*/
  _x_x486 = kk_ref_get(_x_x487,kk_context()); /*10000*/
  _b_x55_62 = kk_std_core_types__list_unbox(_x_x486, KK_OWNED, _ctx); /*list<() -> <io|1394> ()>*/
  kk_unit_t ___0 = kk_Unit;
  kk_box_t _x_x488;
  kk_std_core_types__list _x_x489 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_function_box(kk_nagare_core_interpreter__new_mlift_nextItemRuntime_10331_fun490(release, _ctx), _ctx), _b_x55_62, _ctx); /*list<10021>*/
  _x_x488 = kk_std_core_types__list_box(_x_x489, _ctx); /*10000*/
  kk_ref_set_borrow(finalizers_1,_x_x488,kk_context());
  kk_nagare_core_interpreter__runtime _x_x492 = kk_nagare_core_interpreter__new_Runtime(kk_reuse_null, 0, tail_0, finalizers_1, _ctx); /*nagare/core/interpreter/runtime<21,22>*/
  return kk_nagare_core_interpreter_nextItemRuntime(_x_x492, _ctx);
}
 
// Step runtime to produce the next element. Finalizers are released by the
// outer `withRuntime` bracket, not here, so early-return sinks stay safe.


// lift anonymous function
struct kk_nagare_core_interpreter_nextItemRuntime_fun503__t {
  struct kk_function_s _base;
  kk_ref_t finalizers_0_0;
};
static kk_box_t kk_nagare_core_interpreter_nextItemRuntime_fun503(kk_function_t _fself, kk_box_t _b_x69, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_interpreter_new_nextItemRuntime_fun503(kk_ref_t finalizers_0_0, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter_nextItemRuntime_fun503__t* _self = kk_function_alloc_as(struct kk_nagare_core_interpreter_nextItemRuntime_fun503__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_interpreter_nextItemRuntime_fun503, kk_context());
  _self->finalizers_0_0 = finalizers_0_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_core_interpreter_nextItemRuntime_fun503(kk_function_t _fself, kk_box_t _b_x69, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter_nextItemRuntime_fun503__t* _self = kk_function_as(struct kk_nagare_core_interpreter_nextItemRuntime_fun503__t*, _fself, _ctx);
  kk_ref_t finalizers_0_0 = _self->finalizers_0_0; /* ref<global,list<() -> <io|1394> ()>> */
  kk_drop_match(_self, {kk_ref_dup(finalizers_0_0, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull _y_x10203_0_89 = kk_nagare_core_types__pull_unbox(_b_x69, KK_OWNED, _ctx); /*nagare/core/types/pull<1393,<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>|1394>>*/;
  kk_std_core_types__maybe2 _x_x504 = kk_nagare_core_interpreter__mlift_nextItemRuntime_10330(finalizers_0_0, _y_x10203_0_89, _ctx); /*maybe2<1393,nagare/core/interpreter/runtime<1393,1394>>*/
  return kk_std_core_types__maybe2_box(_x_x504, _ctx);
}


// lift anonymous function
struct kk_nagare_core_interpreter_nextItemRuntime_fun509__t {
  struct kk_function_s _base;
  kk_ref_t finalizers_1_0;
  kk_function_t release_0;
  kk_nagare_core_types__pull tail_0_0;
};
static kk_box_t kk_nagare_core_interpreter_nextItemRuntime_fun509(kk_function_t _fself, kk_box_t _b_x71, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_interpreter_new_nextItemRuntime_fun509(kk_ref_t finalizers_1_0, kk_function_t release_0, kk_nagare_core_types__pull tail_0_0, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter_nextItemRuntime_fun509__t* _self = kk_function_alloc_as(struct kk_nagare_core_interpreter_nextItemRuntime_fun509__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_interpreter_nextItemRuntime_fun509, kk_context());
  _self->finalizers_1_0 = finalizers_1_0;
  _self->release_0 = release_0;
  _self->tail_0_0 = tail_0_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_core_interpreter_nextItemRuntime_fun509(kk_function_t _fself, kk_box_t _b_x71, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter_nextItemRuntime_fun509__t* _self = kk_function_as(struct kk_nagare_core_interpreter_nextItemRuntime_fun509__t*, _fself, _ctx);
  kk_ref_t finalizers_1_0 = _self->finalizers_1_0; /* ref<global,list<() -> <io|1394> ()>> */
  kk_function_t release_0 = _self->release_0; /* () -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>|1394> () */
  kk_nagare_core_types__pull tail_0_0 = _self->tail_0_0; /* nagare/core/types/pull<1393,<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>|1394>> */
  kk_drop_match(_self, {kk_ref_dup(finalizers_1_0, _ctx);kk_function_dup(release_0, _ctx);kk_nagare_core_types__pull_dup(tail_0_0, _ctx);}, {}, _ctx)
  kk_unit_t wild___0_90 = kk_Unit;
  kk_unit_unbox(_b_x71);
  kk_std_core_types__maybe2 _x_x510 = kk_nagare_core_interpreter__mlift_nextItemRuntime_10331(finalizers_1_0, release_0, tail_0_0, wild___0_90, _ctx); /*maybe2<1393,nagare/core/interpreter/runtime<1393,1394>>*/
  return kk_std_core_types__maybe2_box(_x_x510, _ctx);
}


// lift anonymous function
struct kk_nagare_core_interpreter_nextItemRuntime_fun515__t {
  struct kk_function_s _base;
  kk_function_t release_0;
};
static kk_box_t kk_nagare_core_interpreter_nextItemRuntime_fun515(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_interpreter_new_nextItemRuntime_fun515(kk_function_t release_0, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter_nextItemRuntime_fun515__t* _self = kk_function_alloc_as(struct kk_nagare_core_interpreter_nextItemRuntime_fun515__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_interpreter_nextItemRuntime_fun515, kk_context());
  _self->release_0 = release_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_core_interpreter_nextItemRuntime_fun515(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter_nextItemRuntime_fun515__t* _self = kk_function_as(struct kk_nagare_core_interpreter_nextItemRuntime_fun515__t*, _fself, _ctx);
  kk_function_t release_0 = _self->release_0; /* () -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>|1394> () */
  kk_drop_match(_self, {kk_function_dup(release_0, _ctx);}, {}, _ctx)
  kk_unit_t _x_x516 = kk_Unit;
  kk_function_call(kk_unit_t, (kk_function_t, kk_context_t*), release_0, (release_0, _ctx), _ctx);
  return kk_unit_box(_x_x516);
}

kk_std_core_types__maybe2 kk_nagare_core_interpreter_nextItemRuntime(kk_nagare_core_interpreter__runtime state, kk_context_t* _ctx) { /* forall<a,e> (state : runtime<a,e>) -> <io|e> maybe2<a,runtime<a,e>> */ 
  kk__tailcall: ;
  {
    struct kk_nagare_core_interpreter_Runtime* _con_x493 = kk_nagare_core_interpreter__as_Runtime(state, _ctx);
    kk_nagare_core_types__pull _pat_0 = _con_x493->step;
    if (kk_nagare_core_types__is_PDone(_pat_0, _ctx)) {
      kk_ref_t _pat_1 = _con_x493->finalizers;
      if kk_likely(kk_datatype_ptr_is_unique(state, _ctx)) {
        kk_ref_drop(_pat_1, _ctx);
        kk_datatype_ptr_free(state, _ctx);
      }
      else {
        kk_datatype_ptr_decref(state, _ctx);
      }
      return kk_std_core_types__new_Nothing2(_ctx);
    }
  }
  {
    struct kk_nagare_core_interpreter_Runtime* _con_x494 = kk_nagare_core_interpreter__as_Runtime(state, _ctx);
    kk_nagare_core_types__pull _pat_3 = _con_x494->step;
    if (kk_nagare_core_types__is_POutput(_pat_3, _ctx)) {
      struct kk_nagare_core_types_POutput* _con_x495 = kk_nagare_core_types__as_POutput(_pat_3, _ctx);
      kk_ref_t finalizers = _con_x494->finalizers;
      kk_nagare_core_types__chunk out = _con_x495->out;
      kk_nagare_core_types__pull tail = _con_x495->tail;
      kk_reuse_t _ru_x416 = kk_reuse_null; /*@reuse*/;
      if kk_likely(kk_datatype_ptr_is_unique(state, _ctx)) {
        if kk_likely(kk_datatype_ptr_is_unique(_pat_3, _ctx)) {
          kk_datatype_ptr_free(_pat_3, _ctx);
        }
        else {
          kk_nagare_core_types__chunk_dup(out, _ctx);
          kk_nagare_core_types__pull_dup(tail, _ctx);
          kk_datatype_ptr_decref(_pat_3, _ctx);
        }
        _ru_x416 = (kk_datatype_ptr_reuse(state, _ctx));
      }
      else {
        kk_ref_dup(finalizers, _ctx);
        kk_nagare_core_types__chunk_dup(out, _ctx);
        kk_nagare_core_types__pull_dup(tail, _ctx);
        kk_datatype_ptr_decref(state, _ctx);
      }
      {
        kk_std_core_types__list values = out.values;
        kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>|1394>>*/;
        kk_std_core_types__maybe2 x;
        kk_nagare_core_types__pull _x_x496 = kk_nagare_core_types__pull_dup(tail, _ctx); /*nagare/core/types/pull<1393,<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>|1394>>*/
        x = kk_nagare_core_interpreter_nextFromChunk(values, _x_x496, _ctx); /*maybe2<1393,nagare/core/types/pull<1393,<io|1394>>>*/
        kk_unit_t keep = kk_Unit;
        kk_evv_set(w,kk_context());
        if (kk_std_core_types__is_Nothing2(x, _ctx)) { // tailcall
                                                       kk_nagare_core_interpreter__runtime _x_x497 = kk_nagare_core_interpreter__new_Runtime(_ru_x416, 0, tail, finalizers, _ctx); /*nagare/core/interpreter/runtime<21,22>*/
                                                       state = _x_x497;
                                                       goto kk__tailcall;
        }
        {
          kk_box_t _box_x65 = x._cons.Just2.snd;
          kk_box_t x_0 = x._cons.Just2.fst;
          kk_nagare_core_types__pull rem = kk_nagare_core_types__pull_unbox(_box_x65, KK_BORROWED, _ctx);
          kk_nagare_core_types__pull_dup(rem, _ctx);
          kk_box_dup(x_0, _ctx);
          kk_std_core_types__maybe2_drop(x, _ctx);
          kk_nagare_core_types__pull_drop(tail, _ctx);
          kk_box_t _x_x498;
          kk_nagare_core_interpreter__runtime _x_x499 = kk_nagare_core_interpreter__new_Runtime(_ru_x416, 0, rem, finalizers, _ctx); /*nagare/core/interpreter/runtime<21,22>*/
          _x_x498 = kk_nagare_core_interpreter__runtime_box(_x_x499, _ctx); /*10028*/
          return kk_std_core_types__new_Just2(x_0, _x_x498, _ctx);
        }
      }
    }
  }
  {
    struct kk_nagare_core_interpreter_Runtime* _con_x500 = kk_nagare_core_interpreter__as_Runtime(state, _ctx);
    kk_nagare_core_types__pull _pat_8 = _con_x500->step;
    if (kk_nagare_core_types__is_PEval(_pat_8, _ctx)) {
      struct kk_nagare_core_types_PEval* _con_x501 = kk_nagare_core_types__as_PEval(_pat_8, _ctx);
      kk_ref_t finalizers_0_0 = _con_x500->finalizers;
      kk_function_t next = _con_x501->next;
      kk_reuse_t _ru_x418 = kk_reuse_null; /*@reuse*/;
      if kk_likely(kk_datatype_ptr_is_unique(state, _ctx)) {
        if kk_likely(kk_datatype_ptr_is_unique(_pat_8, _ctx)) {
          kk_datatype_ptr_free(_pat_8, _ctx);
        }
        else {
          kk_function_dup(next, _ctx);
          kk_datatype_ptr_decref(_pat_8, _ctx);
        }
        _ru_x418 = (kk_datatype_ptr_reuse(state, _ctx));
      }
      else {
        kk_ref_dup(finalizers_0_0, _ctx);
        kk_function_dup(next, _ctx);
        kk_datatype_ptr_decref(state, _ctx);
      }
      kk_nagare_core_types__pull x_1_10370 = kk_function_call(kk_nagare_core_types__pull, (kk_function_t, kk_context_t*), next, (next, _ctx), _ctx); /*nagare/core/types/pull<1393,<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>|1394>>*/;
      if (kk_yielding(kk_context())) {
        kk_reuse_drop(_ru_x418,kk_context());
        kk_nagare_core_types__pull_drop(x_1_10370, _ctx);
        kk_box_t _x_x502 = kk_std_core_hnd_yield_extend(kk_nagare_core_interpreter_new_nextItemRuntime_fun503(finalizers_0_0, _ctx), _ctx); /*10001*/
        return kk_std_core_types__maybe2_unbox(_x_x502, KK_OWNED, _ctx);
      }
      { // tailcall
        kk_nagare_core_interpreter__runtime _x_x505 = kk_nagare_core_interpreter__new_Runtime(_ru_x418, 0, x_1_10370, finalizers_0_0, _ctx); /*nagare/core/interpreter/runtime<21,22>*/
        state = _x_x505;
        goto kk__tailcall;
      }
    }
  }
  {
    struct kk_nagare_core_interpreter_Runtime* _con_x506 = kk_nagare_core_interpreter__as_Runtime(state, _ctx);
    kk_nagare_core_types__pull _pat_10 = _con_x506->step;
    struct kk_nagare_core_types_PAcquire* _con_x507 = kk_nagare_core_types__as_PAcquire(_pat_10, _ctx);
    kk_ref_t finalizers_1_0 = _con_x506->finalizers;
    kk_function_t acquire = _con_x507->acquire;
    kk_function_t release_0 = _con_x507->release;
    kk_nagare_core_types__pull tail_0_0 = _con_x507->tail;
    kk_reuse_t _ru_x420 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(state, _ctx)) {
      if kk_likely(kk_datatype_ptr_is_unique(_pat_10, _ctx)) {
        kk_datatype_ptr_free(_pat_10, _ctx);
      }
      else {
        kk_function_dup(acquire, _ctx);
        kk_function_dup(release_0, _ctx);
        kk_nagare_core_types__pull_dup(tail_0_0, _ctx);
        kk_datatype_ptr_decref(_pat_10, _ctx);
      }
      _ru_x420 = (kk_datatype_ptr_reuse(state, _ctx));
    }
    else {
      kk_function_dup(acquire, _ctx);
      kk_ref_dup(finalizers_1_0, _ctx);
      kk_function_dup(release_0, _ctx);
      kk_nagare_core_types__pull_dup(tail_0_0, _ctx);
      kk_datatype_ptr_decref(state, _ctx);
    }
    kk_unit_t x_2_10373 = kk_Unit;
    kk_function_call(kk_unit_t, (kk_function_t, kk_context_t*), acquire, (acquire, _ctx), _ctx);
    if (kk_yielding(kk_context())) {
      kk_reuse_drop(_ru_x420,kk_context());
      kk_box_t _x_x508 = kk_std_core_hnd_yield_extend(kk_nagare_core_interpreter_new_nextItemRuntime_fun509(finalizers_1_0, release_0, tail_0_0, _ctx), _ctx); /*10001*/
      return kk_std_core_types__maybe2_unbox(_x_x508, KK_OWNED, _ctx);
    }
    {
      kk_std_core_types__list _b_x75_82;
      kk_box_t _x_x511;
      kk_ref_t _x_x512 = kk_ref_dup(finalizers_1_0, _ctx); /*ref<global,list<() -> <io|1394> ()>>*/
      _x_x511 = kk_ref_get(_x_x512,kk_context()); /*10000*/
      _b_x75_82 = kk_std_core_types__list_unbox(_x_x511, KK_OWNED, _ctx); /*list<() -> <io|1394> ()>*/
      kk_unit_t ___0_0 = kk_Unit;
      kk_box_t _x_x513;
      kk_std_core_types__list _x_x514 = kk_std_core_types__new_Cons(_ru_x420, 0, kk_function_box(kk_nagare_core_interpreter_new_nextItemRuntime_fun515(release_0, _ctx), _ctx), _b_x75_82, _ctx); /*list<10021>*/
      _x_x513 = kk_std_core_types__list_box(_x_x514, _ctx); /*10000*/
      kk_ref_set_borrow(finalizers_1_0,_x_x513,kk_context());
      { // tailcall
        kk_nagare_core_interpreter__runtime _x_x517 = kk_nagare_core_interpreter__new_Runtime(kk_reuse_null, 0, tail_0_0, finalizers_1_0, _ctx); /*nagare/core/interpreter/runtime<21,22>*/
        state = _x_x517;
        goto kk__tailcall;
      }
    }
  }
}
 
// monadic lift

kk_std_core_types__list kk_nagare_core_interpreter__mlift_collectRuntime_10332(kk_std_core_types__list accRev, kk_std_core_types__maybe2 _y_x10208, kk_context_t* _ctx) { /* forall<a,e> (accRev : list<a>, maybe2<a,runtime<a,e>>) -> <io|e> list<a> */ 
  if (kk_std_core_types__is_Nothing2(_y_x10208, _ctx)) {
    kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>|1474>>*/;
    kk_std_core_types__list x;
    if (kk_std_core_types__is_Nil(accRev, _ctx)) {
      x = kk_std_core_types__new_Nil(_ctx); /*list<1473>*/
    }
    else {
      x = kk_nagare_core_interpreter__unroll_lift_listReverse_2558_10000(accRev, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<1473>*/
    }
    kk_unit_t keep = kk_Unit;
    kk_evv_set(w,kk_context());
    return x;
  }
  {
    kk_box_t _box_x91 = _y_x10208._cons.Just2.snd;
    kk_box_t x_0 = _y_x10208._cons.Just2.fst;
    kk_nagare_core_interpreter__runtime nextState = kk_nagare_core_interpreter__runtime_unbox(_box_x91, KK_BORROWED, _ctx);
    kk_nagare_core_interpreter__runtime_dup(nextState, _ctx);
    kk_box_dup(x_0, _ctx);
    kk_std_core_types__maybe2_drop(_y_x10208, _ctx);
    kk_std_core_types__list _x_x518 = kk_std_core_types__new_Cons(kk_reuse_null, 0, x_0, accRev, _ctx); /*list<10021>*/
    return kk_nagare_core_interpreter_collectRuntime(nextState, _x_x518, _ctx);
  }
}
 
// Collect all elements into a list.


// lift anonymous function
struct kk_nagare_core_interpreter_collectRuntime_fun520__t {
  struct kk_function_s _base;
  kk_std_core_types__list accRev_0;
};
static kk_box_t kk_nagare_core_interpreter_collectRuntime_fun520(kk_function_t _fself, kk_box_t _b_x93, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_interpreter_new_collectRuntime_fun520(kk_std_core_types__list accRev_0, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter_collectRuntime_fun520__t* _self = kk_function_alloc_as(struct kk_nagare_core_interpreter_collectRuntime_fun520__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_interpreter_collectRuntime_fun520, kk_context());
  _self->accRev_0 = accRev_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_core_interpreter_collectRuntime_fun520(kk_function_t _fself, kk_box_t _b_x93, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter_collectRuntime_fun520__t* _self = kk_function_as(struct kk_nagare_core_interpreter_collectRuntime_fun520__t*, _fself, _ctx);
  kk_std_core_types__list accRev_0 = _self->accRev_0; /* list<1473> */
  kk_drop_match(_self, {kk_std_core_types__list_dup(accRev_0, _ctx);}, {}, _ctx)
  kk_std_core_types__maybe2 _y_x10208_0_96 = kk_std_core_types__maybe2_unbox(_b_x93, KK_OWNED, _ctx); /*maybe2<1473,nagare/core/interpreter/runtime<1473,1474>>*/;
  kk_std_core_types__list _x_x521 = kk_nagare_core_interpreter__mlift_collectRuntime_10332(accRev_0, _y_x10208_0_96, _ctx); /*list<1473>*/
  return kk_std_core_types__list_box(_x_x521, _ctx);
}

kk_std_core_types__list kk_nagare_core_interpreter_collectRuntime(kk_nagare_core_interpreter__runtime state, kk_std_core_types__list accRev_0, kk_context_t* _ctx) { /* forall<a,e> (state : runtime<a,e>, accRev : list<a>) -> <io|e> list<a> */ 
  kk__tailcall: ;
  kk_std_core_types__maybe2 x_1_10378 = kk_nagare_core_interpreter_nextItemRuntime(state, _ctx); /*maybe2<1473,nagare/core/interpreter/runtime<1473,1474>>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__maybe2_drop(x_1_10378, _ctx);
    kk_box_t _x_x519 = kk_std_core_hnd_yield_extend(kk_nagare_core_interpreter_new_collectRuntime_fun520(accRev_0, _ctx), _ctx); /*10001*/
    return kk_std_core_types__list_unbox(_x_x519, KK_OWNED, _ctx);
  }
  if (kk_std_core_types__is_Nothing2(x_1_10378, _ctx)) {
    kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>|1474>>*/;
    kk_std_core_types__list x_2;
    if (kk_std_core_types__is_Nil(accRev_0, _ctx)) {
      x_2 = kk_std_core_types__new_Nil(_ctx); /*list<1473>*/
    }
    else {
      x_2 = kk_nagare_core_interpreter__unroll_lift_listReverse_2558_10000(accRev_0, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<1473>*/
    }
    kk_unit_t keep_0 = kk_Unit;
    kk_evv_set(w_0,kk_context());
    return x_2;
  }
  {
    kk_box_t _box_x94 = x_1_10378._cons.Just2.snd;
    kk_box_t x_3 = x_1_10378._cons.Just2.fst;
    kk_nagare_core_interpreter__runtime nextState_0 = kk_nagare_core_interpreter__runtime_unbox(_box_x94, KK_BORROWED, _ctx);
    kk_nagare_core_interpreter__runtime_dup(nextState_0, _ctx);
    kk_box_dup(x_3, _ctx);
    kk_std_core_types__maybe2_drop(x_1_10378, _ctx);
    { // tailcall
      kk_std_core_types__list _x_x522 = kk_std_core_types__new_Cons(kk_reuse_null, 0, x_3, accRev_0, _ctx); /*list<10021>*/
      state = nextState_0;
      accRev_0 = _x_x522;
      goto kk__tailcall;
    }
  }
}
 
// monadic lift

kk_unit_t kk_nagare_core_interpreter__mlift_drainRuntime_10333(kk_std_core_types__maybe2 _y_x10211, kk_context_t* _ctx) { /* forall<a,e> (maybe2<a,runtime<a,e>>) -> <io|e> () */ 
  if (kk_std_core_types__is_Nothing2(_y_x10211, _ctx)) {
    kk_Unit; return kk_Unit;
  }
  {
    kk_box_t _box_x97 = _y_x10211._cons.Just2.snd;
    kk_nagare_core_interpreter__runtime nextState = kk_nagare_core_interpreter__runtime_unbox(_box_x97, KK_BORROWED, _ctx);
    kk_nagare_core_interpreter__runtime_dup(nextState, _ctx);
    kk_std_core_types__maybe2_drop(_y_x10211, _ctx);
    kk_nagare_core_interpreter_drainRuntime(nextState, _ctx); return kk_Unit;
  }
}
 
// Consume all elements, discarding outputs.


// lift anonymous function
struct kk_nagare_core_interpreter_drainRuntime_fun524__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_core_interpreter_drainRuntime_fun524(kk_function_t _fself, kk_box_t _b_x99, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_interpreter_new_drainRuntime_fun524(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_core_interpreter_drainRuntime_fun524, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_core_interpreter_drainRuntime_fun524(kk_function_t _fself, kk_box_t _b_x99, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__maybe2 _y_x10211_0_102 = kk_std_core_types__maybe2_unbox(_b_x99, KK_OWNED, _ctx); /*maybe2<1537,nagare/core/interpreter/runtime<1537,1538>>*/;
  kk_unit_t _x_x525 = kk_Unit;
  kk_nagare_core_interpreter__mlift_drainRuntime_10333(_y_x10211_0_102, _ctx);
  return kk_unit_box(_x_x525);
}

kk_unit_t kk_nagare_core_interpreter_drainRuntime(kk_nagare_core_interpreter__runtime state, kk_context_t* _ctx) { /* forall<a,e> (state : runtime<a,e>) -> <io|e> () */ 
  kk__tailcall: ;
  kk_std_core_types__maybe2 x_10383 = kk_nagare_core_interpreter_nextItemRuntime(state, _ctx); /*maybe2<1537,nagare/core/interpreter/runtime<1537,1538>>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__maybe2_drop(x_10383, _ctx);
    kk_box_t _x_x523 = kk_std_core_hnd_yield_extend(kk_nagare_core_interpreter_new_drainRuntime_fun524(_ctx), _ctx); /*10001*/
    kk_unit_unbox(_x_x523); return kk_Unit;
  }
  if (kk_std_core_types__is_Nothing2(x_10383, _ctx)) {
    kk_Unit; return kk_Unit;
  }
  {
    kk_box_t _box_x100 = x_10383._cons.Just2.snd;
    kk_nagare_core_interpreter__runtime nextState_0 = kk_nagare_core_interpreter__runtime_unbox(_box_x100, KK_BORROWED, _ctx);
    kk_nagare_core_interpreter__runtime_dup(nextState_0, _ctx);
    kk_std_core_types__maybe2_drop(x_10383, _ctx);
    { // tailcall
      state = nextState_0;
      goto kk__tailcall;
    }
  }
}
 
// monadic lift

kk_std_core_types__maybe kk_nagare_core_interpreter__mlift_lastRuntime_10334(kk_std_core_types__maybe current, kk_std_core_types__maybe2 _y_x10214, kk_context_t* _ctx) { /* forall<a,e> (current : maybe<a>, maybe2<a,runtime<a,e>>) -> <io|e> maybe<a> */ 
  if (kk_std_core_types__is_Nothing2(_y_x10214, _ctx)) {
    return current;
  }
  {
    kk_box_t _box_x103 = _y_x10214._cons.Just2.snd;
    kk_box_t x = _y_x10214._cons.Just2.fst;
    kk_nagare_core_interpreter__runtime nextState = kk_nagare_core_interpreter__runtime_unbox(_box_x103, KK_BORROWED, _ctx);
    kk_std_core_types__maybe_drop(current, _ctx);
    kk_nagare_core_interpreter__runtime_dup(nextState, _ctx);
    kk_box_dup(x, _ctx);
    kk_std_core_types__maybe2_drop(_y_x10214, _ctx);
    kk_std_core_types__maybe _x_x526 = kk_std_core_types__new_Just(x, _ctx); /*maybe<10024>*/
    return kk_nagare_core_interpreter_lastRuntime(nextState, _x_x526, _ctx);
  }
}
 
// Consume all elements and return the last (or Nothing).


// lift anonymous function
struct kk_nagare_core_interpreter_lastRuntime_fun528__t {
  struct kk_function_s _base;
  kk_std_core_types__maybe current_0;
};
static kk_box_t kk_nagare_core_interpreter_lastRuntime_fun528(kk_function_t _fself, kk_box_t _b_x105, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_interpreter_new_lastRuntime_fun528(kk_std_core_types__maybe current_0, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter_lastRuntime_fun528__t* _self = kk_function_alloc_as(struct kk_nagare_core_interpreter_lastRuntime_fun528__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_interpreter_lastRuntime_fun528, kk_context());
  _self->current_0 = current_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_core_interpreter_lastRuntime_fun528(kk_function_t _fself, kk_box_t _b_x105, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter_lastRuntime_fun528__t* _self = kk_function_as(struct kk_nagare_core_interpreter_lastRuntime_fun528__t*, _fself, _ctx);
  kk_std_core_types__maybe current_0 = _self->current_0; /* maybe<1609> */
  kk_drop_match(_self, {kk_std_core_types__maybe_dup(current_0, _ctx);}, {}, _ctx)
  kk_std_core_types__maybe2 _y_x10214_0_108 = kk_std_core_types__maybe2_unbox(_b_x105, KK_OWNED, _ctx); /*maybe2<1609,nagare/core/interpreter/runtime<1609,1610>>*/;
  kk_std_core_types__maybe _x_x529 = kk_nagare_core_interpreter__mlift_lastRuntime_10334(current_0, _y_x10214_0_108, _ctx); /*maybe<1609>*/
  return kk_std_core_types__maybe_box(_x_x529, _ctx);
}

kk_std_core_types__maybe kk_nagare_core_interpreter_lastRuntime(kk_nagare_core_interpreter__runtime state, kk_std_core_types__maybe current_0, kk_context_t* _ctx) { /* forall<a,e> (state : runtime<a,e>, current : maybe<a>) -> <io|e> maybe<a> */ 
  kk__tailcall: ;
  kk_std_core_types__maybe2 x_0_10386 = kk_nagare_core_interpreter_nextItemRuntime(state, _ctx); /*maybe2<1609,nagare/core/interpreter/runtime<1609,1610>>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__maybe2_drop(x_0_10386, _ctx);
    kk_box_t _x_x527 = kk_std_core_hnd_yield_extend(kk_nagare_core_interpreter_new_lastRuntime_fun528(current_0, _ctx), _ctx); /*10001*/
    return kk_std_core_types__maybe_unbox(_x_x527, KK_OWNED, _ctx);
  }
  if (kk_std_core_types__is_Nothing2(x_0_10386, _ctx)) {
    return current_0;
  }
  {
    kk_box_t _box_x106 = x_0_10386._cons.Just2.snd;
    kk_box_t x_1 = x_0_10386._cons.Just2.fst;
    kk_nagare_core_interpreter__runtime nextState_0 = kk_nagare_core_interpreter__runtime_unbox(_box_x106, KK_BORROWED, _ctx);
    kk_nagare_core_interpreter__runtime_dup(nextState_0, _ctx);
    kk_box_dup(x_1, _ctx);
    kk_std_core_types__maybe2_drop(x_0_10386, _ctx);
    kk_std_core_types__maybe_drop(current_0, _ctx);
    { // tailcall
      kk_std_core_types__maybe _x_x530 = kk_std_core_types__new_Just(x_1, _ctx); /*maybe<10024>*/
      state = nextState_0;
      current_0 = _x_x530;
      goto kk__tailcall;
    }
  }
}
 
// monadic lift

kk_box_t kk_nagare_core_interpreter__mlift_foldRuntime_10335(kk_box_t init, kk_function_t step, kk_std_core_types__maybe2 _y_x10217, kk_context_t* _ctx) { /* forall<a,b,e> (init : b, step : (b, a) -> b, maybe2<a,runtime<a,e>>) -> <io|e> b */ 
  if (kk_std_core_types__is_Nothing2(_y_x10217, _ctx)) {
    kk_function_drop(step, _ctx);
    return init;
  }
  {
    kk_box_t _box_x109 = _y_x10217._cons.Just2.snd;
    kk_box_t x = _y_x10217._cons.Just2.fst;
    kk_nagare_core_interpreter__runtime nextState = kk_nagare_core_interpreter__runtime_unbox(_box_x109, KK_BORROWED, _ctx);
    kk_nagare_core_interpreter__runtime_dup(nextState, _ctx);
    kk_box_dup(x, _ctx);
    kk_std_core_types__maybe2_drop(_y_x10217, _ctx);
    kk_box_t _x_x531;
    kk_function_t _x_x532 = kk_function_dup(step, _ctx); /*(1696, 1695) -> 1696*/
    _x_x531 = kk_std_core_hnd__open_none2(_x_x532, init, x, _ctx); /*10002*/
    return kk_nagare_core_interpreter_foldRuntime(nextState, _x_x531, step, _ctx);
  }
}
 
// Fold all elements using an accumulator.


// lift anonymous function
struct kk_nagare_core_interpreter_foldRuntime_fun533__t {
  struct kk_function_s _base;
  kk_box_t init_0;
  kk_function_t step_0;
};
static kk_box_t kk_nagare_core_interpreter_foldRuntime_fun533(kk_function_t _fself, kk_box_t _b_x111, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_interpreter_new_foldRuntime_fun533(kk_box_t init_0, kk_function_t step_0, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter_foldRuntime_fun533__t* _self = kk_function_alloc_as(struct kk_nagare_core_interpreter_foldRuntime_fun533__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_interpreter_foldRuntime_fun533, kk_context());
  _self->init_0 = init_0;
  _self->step_0 = step_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_core_interpreter_foldRuntime_fun533(kk_function_t _fself, kk_box_t _b_x111, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter_foldRuntime_fun533__t* _self = kk_function_as(struct kk_nagare_core_interpreter_foldRuntime_fun533__t*, _fself, _ctx);
  kk_box_t init_0 = _self->init_0; /* 1696 */
  kk_function_t step_0 = _self->step_0; /* (1696, 1695) -> 1696 */
  kk_drop_match(_self, {kk_box_dup(init_0, _ctx);kk_function_dup(step_0, _ctx);}, {}, _ctx)
  kk_std_core_types__maybe2 _x_x534 = kk_std_core_types__maybe2_unbox(_b_x111, KK_OWNED, _ctx); /*maybe2<1695,nagare/core/interpreter/runtime<1695,1697>>*/
  return kk_nagare_core_interpreter__mlift_foldRuntime_10335(init_0, step_0, _x_x534, _ctx);
}

kk_box_t kk_nagare_core_interpreter_foldRuntime(kk_nagare_core_interpreter__runtime state, kk_box_t init_0, kk_function_t step_0, kk_context_t* _ctx) { /* forall<a,b,e> (state : runtime<a,e>, init : b, step : (b, a) -> b) -> <io|e> b */ 
  kk__tailcall: ;
  kk_std_core_types__maybe2 x_0_10389 = kk_nagare_core_interpreter_nextItemRuntime(state, _ctx); /*maybe2<1695,nagare/core/interpreter/runtime<1695,1697>>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__maybe2_drop(x_0_10389, _ctx);
    return kk_std_core_hnd_yield_extend(kk_nagare_core_interpreter_new_foldRuntime_fun533(init_0, step_0, _ctx), _ctx);
  }
  if (kk_std_core_types__is_Nothing2(x_0_10389, _ctx)) {
    kk_function_drop(step_0, _ctx);
    return init_0;
  }
  {
    kk_box_t _box_x112 = x_0_10389._cons.Just2.snd;
    kk_box_t x_1 = x_0_10389._cons.Just2.fst;
    kk_nagare_core_interpreter__runtime nextState_0 = kk_nagare_core_interpreter__runtime_unbox(_box_x112, KK_BORROWED, _ctx);
    kk_nagare_core_interpreter__runtime_dup(nextState_0, _ctx);
    kk_box_dup(x_1, _ctx);
    kk_std_core_types__maybe2_drop(x_0_10389, _ctx);
    { // tailcall
      kk_box_t _x_x535;
      kk_function_t _x_x536 = kk_function_dup(step_0, _ctx); /*(1696, 1695) -> 1696*/
      _x_x535 = kk_std_core_hnd__open_none2(_x_x536, init_0, x_1, _ctx); /*10002*/
      state = nextState_0;
      init_0 = _x_x535;
      goto kk__tailcall;
    }
  }
}
 
// monadic lift

kk_std_core_types__tuple2 kk_nagare_core_interpreter__mlift_unroll_traceCompileGoPull_10006_10336(kk_std_core_types__list eventsRev, kk_std_core_types__list valuesRev, kk_unit_t _c_x10221, kk_context_t* _ctx) { /* forall<a,e> (eventsRev : list<trace-event<a>>, valuesRev : list<a>, ()) -> (list<a>, list<trace-event<a>>) */ 
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>|1857>>*/;
  kk_std_core_types__list x;
  if (kk_std_core_types__is_Nil(valuesRev, _ctx)) {
    x = kk_std_core_types__new_Nil(_ctx); /*list<1856>*/
  }
  else {
    x = kk_nagare_core_interpreter__unroll_lift_listReverse_2558_10000(valuesRev, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<1856>*/
  }
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>|1857>>*/;
  kk_std_core_types__list x_0;
  if (kk_std_core_types__is_Nil(eventsRev, _ctx)) {
    x_0 = kk_std_core_types__new_Nil(_ctx); /*list<nagare/core/interpreter/trace-event<1856>>*/
  }
  else {
    x_0 = kk_nagare_core_interpreter__unroll_lift_listReverse_2558_10000(eventsRev, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<nagare/core/interpreter/trace-event<1856>>*/
  }
  kk_unit_t keep_0 = kk_Unit;
  kk_evv_set(w_0,kk_context());
  return kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(x, _ctx), kk_std_core_types__list_box(x_0, _ctx), _ctx);
}
 
// monadic lift

kk_std_core_types__tuple2 kk_nagare_core_interpreter__mlift_unroll_traceCompileGoPull_10006_10337(kk_std_core_types__list eventsRev_0, kk_std_core_types__list finalizersRev, kk_std_core_types__list valuesRev_0, kk_nagare_core_types__pull _y_x10224, kk_context_t* _ctx) { /* forall<a,e> (eventsRev : list<trace-event<a>>, finalizersRev : list<() -> <io|e> ()>, valuesRev : list<a>, nagare/core/types/pull<a,<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>|e>>) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>|e> (list<a>, list<trace-event<a>>) */ 
  kk_std_core_types__list _x_x537 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_nagare_core_interpreter__trace_event_box(kk_nagare_core_interpreter__new_TraceEval(_ctx), _ctx), eventsRev_0, _ctx); /*list<10021>*/
  return kk_nagare_core_interpreter__unroll_traceCompileGoPull_10006(_y_x10224, finalizersRev, valuesRev_0, _x_x537, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_nagare_core_interpreter__mlift_unroll_traceCompileGoPull_10006_10338_fun539__t {
  struct kk_function_s _base;
  kk_function_t release;
};
static kk_box_t kk_nagare_core_interpreter__mlift_unroll_traceCompileGoPull_10006_10338_fun539(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_interpreter__new_mlift_unroll_traceCompileGoPull_10006_10338_fun539(kk_function_t release, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter__mlift_unroll_traceCompileGoPull_10006_10338_fun539__t* _self = kk_function_alloc_as(struct kk_nagare_core_interpreter__mlift_unroll_traceCompileGoPull_10006_10338_fun539__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_interpreter__mlift_unroll_traceCompileGoPull_10006_10338_fun539, kk_context());
  _self->release = release;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_core_interpreter__mlift_unroll_traceCompileGoPull_10006_10338_fun539(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter__mlift_unroll_traceCompileGoPull_10006_10338_fun539__t* _self = kk_function_as(struct kk_nagare_core_interpreter__mlift_unroll_traceCompileGoPull_10006_10338_fun539__t*, _fself, _ctx);
  kk_function_t release = _self->release; /* () -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>|1857> () */
  kk_drop_match(_self, {kk_function_dup(release, _ctx);}, {}, _ctx)
  kk_unit_t _x_x540 = kk_Unit;
  kk_function_call(kk_unit_t, (kk_function_t, kk_context_t*), release, (release, _ctx), _ctx);
  return kk_unit_box(_x_x540);
}

kk_std_core_types__tuple2 kk_nagare_core_interpreter__mlift_unroll_traceCompileGoPull_10006_10338(kk_std_core_types__list eventsRev_1, kk_std_core_types__list finalizersRev_0, kk_function_t release, kk_nagare_core_types__pull tail_0, kk_std_core_types__list valuesRev_1, kk_unit_t wild___0, kk_context_t* _ctx) { /* forall<a,e> (eventsRev : list<trace-event<a>>, finalizersRev : list<() -> <io|e> ()>, release : () -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>|e> (), tail@0 : nagare/core/types/pull<a,<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>|e>>, valuesRev : list<a>, wild_@0 : ()) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>|e> (list<a>, list<trace-event<a>>) */ 
  kk_std_core_types__list _x_x538 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_function_box(kk_nagare_core_interpreter__new_mlift_unroll_traceCompileGoPull_10006_10338_fun539(release, _ctx), _ctx), finalizersRev_0, _ctx); /*list<10021>*/
  return kk_nagare_core_interpreter__unroll_traceCompileGoPull_10006(tail_0, _x_x538, valuesRev_1, eventsRev_1, _ctx);
}
 
// Interpret a pull, collecting emitted values and trace events.


// lift anonymous function
struct kk_nagare_core_interpreter__unroll_traceCompileGoPull_10006_fun542__t {
  struct kk_function_s _base;
  kk_std_core_types__list eventsRev_2;
  kk_std_core_types__list valuesRev_2;
};
static kk_box_t kk_nagare_core_interpreter__unroll_traceCompileGoPull_10006_fun542(kk_function_t _fself, kk_box_t _b_x129, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_interpreter__new_unroll_traceCompileGoPull_10006_fun542(kk_std_core_types__list eventsRev_2, kk_std_core_types__list valuesRev_2, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter__unroll_traceCompileGoPull_10006_fun542__t* _self = kk_function_alloc_as(struct kk_nagare_core_interpreter__unroll_traceCompileGoPull_10006_fun542__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_interpreter__unroll_traceCompileGoPull_10006_fun542, kk_context());
  _self->eventsRev_2 = eventsRev_2;
  _self->valuesRev_2 = valuesRev_2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_core_interpreter__unroll_traceCompileGoPull_10006_fun542(kk_function_t _fself, kk_box_t _b_x129, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter__unroll_traceCompileGoPull_10006_fun542__t* _self = kk_function_as(struct kk_nagare_core_interpreter__unroll_traceCompileGoPull_10006_fun542__t*, _fself, _ctx);
  kk_std_core_types__list eventsRev_2 = _self->eventsRev_2; /* list<nagare/core/interpreter/trace-event<1856>> */
  kk_std_core_types__list valuesRev_2 = _self->valuesRev_2; /* list<1856> */
  kk_drop_match(_self, {kk_std_core_types__list_dup(eventsRev_2, _ctx);kk_std_core_types__list_dup(valuesRev_2, _ctx);}, {}, _ctx)
  kk_unit_t _c_x10221_0_150 = kk_Unit;
  kk_unit_unbox(_b_x129);
  kk_std_core_types__tuple2 _x_x543 = kk_nagare_core_interpreter__mlift_unroll_traceCompileGoPull_10006_10336(eventsRev_2, valuesRev_2, _c_x10221_0_150, _ctx); /*(list<1856>, list<nagare/core/interpreter/trace-event<1856>>)*/
  return kk_std_core_types__tuple2_box(_x_x543, _ctx);
}


// lift anonymous function
struct kk_nagare_core_interpreter__unroll_traceCompileGoPull_10006_fun548__t {
  struct kk_function_s _base;
  kk_std_core_types__list eventsRev_2;
  kk_std_core_types__list finalizersRev_1;
  kk_std_core_types__list valuesRev_2;
};
static kk_box_t kk_nagare_core_interpreter__unroll_traceCompileGoPull_10006_fun548(kk_function_t _fself, kk_box_t _b_x133, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_interpreter__new_unroll_traceCompileGoPull_10006_fun548(kk_std_core_types__list eventsRev_2, kk_std_core_types__list finalizersRev_1, kk_std_core_types__list valuesRev_2, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter__unroll_traceCompileGoPull_10006_fun548__t* _self = kk_function_alloc_as(struct kk_nagare_core_interpreter__unroll_traceCompileGoPull_10006_fun548__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_interpreter__unroll_traceCompileGoPull_10006_fun548, kk_context());
  _self->eventsRev_2 = eventsRev_2;
  _self->finalizersRev_1 = finalizersRev_1;
  _self->valuesRev_2 = valuesRev_2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_core_interpreter__unroll_traceCompileGoPull_10006_fun548(kk_function_t _fself, kk_box_t _b_x133, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter__unroll_traceCompileGoPull_10006_fun548__t* _self = kk_function_as(struct kk_nagare_core_interpreter__unroll_traceCompileGoPull_10006_fun548__t*, _fself, _ctx);
  kk_std_core_types__list eventsRev_2 = _self->eventsRev_2; /* list<nagare/core/interpreter/trace-event<1856>> */
  kk_std_core_types__list finalizersRev_1 = _self->finalizersRev_1; /* list<() -> <io|1857> ()> */
  kk_std_core_types__list valuesRev_2 = _self->valuesRev_2; /* list<1856> */
  kk_drop_match(_self, {kk_std_core_types__list_dup(eventsRev_2, _ctx);kk_std_core_types__list_dup(finalizersRev_1, _ctx);kk_std_core_types__list_dup(valuesRev_2, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull _y_x10224_0_151 = kk_nagare_core_types__pull_unbox(_b_x133, KK_OWNED, _ctx); /*nagare/core/types/pull<1856,<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>|1857>>*/;
  kk_std_core_types__tuple2 _x_x549 = kk_nagare_core_interpreter__mlift_unroll_traceCompileGoPull_10006_10337(eventsRev_2, finalizersRev_1, valuesRev_2, _y_x10224_0_151, _ctx); /*(list<1856>, list<nagare/core/interpreter/trace-event<1856>>)*/
  return kk_std_core_types__tuple2_box(_x_x549, _ctx);
}


// lift anonymous function
struct kk_nagare_core_interpreter__unroll_traceCompileGoPull_10006_fun553__t {
  struct kk_function_s _base;
  kk_std_core_types__list eventsRev_2;
  kk_std_core_types__list finalizersRev_1;
  kk_function_t release_0;
  kk_nagare_core_types__pull tail_0_0;
  kk_std_core_types__list valuesRev_2;
};
static kk_box_t kk_nagare_core_interpreter__unroll_traceCompileGoPull_10006_fun553(kk_function_t _fself, kk_box_t _b_x137, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_interpreter__new_unroll_traceCompileGoPull_10006_fun553(kk_std_core_types__list eventsRev_2, kk_std_core_types__list finalizersRev_1, kk_function_t release_0, kk_nagare_core_types__pull tail_0_0, kk_std_core_types__list valuesRev_2, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter__unroll_traceCompileGoPull_10006_fun553__t* _self = kk_function_alloc_as(struct kk_nagare_core_interpreter__unroll_traceCompileGoPull_10006_fun553__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_interpreter__unroll_traceCompileGoPull_10006_fun553, kk_context());
  _self->eventsRev_2 = eventsRev_2;
  _self->finalizersRev_1 = finalizersRev_1;
  _self->release_0 = release_0;
  _self->tail_0_0 = tail_0_0;
  _self->valuesRev_2 = valuesRev_2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_core_interpreter__unroll_traceCompileGoPull_10006_fun553(kk_function_t _fself, kk_box_t _b_x137, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter__unroll_traceCompileGoPull_10006_fun553__t* _self = kk_function_as(struct kk_nagare_core_interpreter__unroll_traceCompileGoPull_10006_fun553__t*, _fself, _ctx);
  kk_std_core_types__list eventsRev_2 = _self->eventsRev_2; /* list<nagare/core/interpreter/trace-event<1856>> */
  kk_std_core_types__list finalizersRev_1 = _self->finalizersRev_1; /* list<() -> <io|1857> ()> */
  kk_function_t release_0 = _self->release_0; /* () -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>|1857> () */
  kk_nagare_core_types__pull tail_0_0 = _self->tail_0_0; /* nagare/core/types/pull<1856,<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>|1857>> */
  kk_std_core_types__list valuesRev_2 = _self->valuesRev_2; /* list<1856> */
  kk_drop_match(_self, {kk_std_core_types__list_dup(eventsRev_2, _ctx);kk_std_core_types__list_dup(finalizersRev_1, _ctx);kk_function_dup(release_0, _ctx);kk_nagare_core_types__pull_dup(tail_0_0, _ctx);kk_std_core_types__list_dup(valuesRev_2, _ctx);}, {}, _ctx)
  kk_unit_t wild___0_0_152 = kk_Unit;
  kk_unit_unbox(_b_x137);
  kk_std_core_types__tuple2 _x_x554 = kk_nagare_core_interpreter__mlift_unroll_traceCompileGoPull_10006_10338(eventsRev_2, finalizersRev_1, release_0, tail_0_0, valuesRev_2, wild___0_0_152, _ctx); /*(list<1856>, list<nagare/core/interpreter/trace-event<1856>>)*/
  return kk_std_core_types__tuple2_box(_x_x554, _ctx);
}


// lift anonymous function
struct kk_nagare_core_interpreter__unroll_traceCompileGoPull_10006_fun556__t {
  struct kk_function_s _base;
  kk_function_t release_0;
};
static kk_box_t kk_nagare_core_interpreter__unroll_traceCompileGoPull_10006_fun556(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_interpreter__new_unroll_traceCompileGoPull_10006_fun556(kk_function_t release_0, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter__unroll_traceCompileGoPull_10006_fun556__t* _self = kk_function_alloc_as(struct kk_nagare_core_interpreter__unroll_traceCompileGoPull_10006_fun556__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_interpreter__unroll_traceCompileGoPull_10006_fun556, kk_context());
  _self->release_0 = release_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_core_interpreter__unroll_traceCompileGoPull_10006_fun556(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter__unroll_traceCompileGoPull_10006_fun556__t* _self = kk_function_as(struct kk_nagare_core_interpreter__unroll_traceCompileGoPull_10006_fun556__t*, _fself, _ctx);
  kk_function_t release_0 = _self->release_0; /* () -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>|1857> () */
  kk_drop_match(_self, {kk_function_dup(release_0, _ctx);}, {}, _ctx)
  kk_unit_t _x_x557 = kk_Unit;
  kk_function_call(kk_unit_t, (kk_function_t, kk_context_t*), release_0, (release_0, _ctx), _ctx);
  return kk_unit_box(_x_x557);
}

kk_std_core_types__tuple2 kk_nagare_core_interpreter__unroll_traceCompileGoPull_10006(kk_nagare_core_types__pull state, kk_std_core_types__list finalizersRev_1, kk_std_core_types__list valuesRev_2, kk_std_core_types__list eventsRev_2, kk_context_t* _ctx) { /* forall<a,e> (state : nagare/core/types/pull<a,<io|e>>, finalizersRev : list<() -> <io|e> ()>, valuesRev : list<a>, eventsRev : list<trace-event<a>>) -> <io|e> (list<a>, list<trace-event<a>>) */ 
  kk__tailcall: ;
  if (kk_nagare_core_types__is_PDone(state, _ctx)) {
    kk_unit_t x_1_10396 = kk_Unit;
    if (kk_std_core_types__is_Nil(finalizersRev_1, _ctx)) {
      
    }
    else {
      kk_nagare_core_interpreter__unroll_runFinalizersRev_10004(finalizersRev_1, _ctx);
    }
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x541 = kk_std_core_hnd_yield_extend(kk_nagare_core_interpreter__new_unroll_traceCompileGoPull_10006_fun542(eventsRev_2, valuesRev_2, _ctx), _ctx); /*10001*/
      return kk_std_core_types__tuple2_unbox(_x_x541, KK_OWNED, _ctx);
    }
    {
      kk_evv_t w_1 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>|1857>>*/;
      kk_std_core_types__list x_2;
      if (kk_std_core_types__is_Nil(valuesRev_2, _ctx)) {
        x_2 = kk_std_core_types__new_Nil(_ctx); /*list<1856>*/
      }
      else {
        x_2 = kk_nagare_core_interpreter__unroll_lift_listReverse_2558_10000(valuesRev_2, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<1856>*/
      }
      kk_unit_t keep_1 = kk_Unit;
      kk_evv_set(w_1,kk_context());
      kk_evv_t w_2 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>|1857>>*/;
      kk_std_core_types__list x_3;
      if (kk_std_core_types__is_Nil(eventsRev_2, _ctx)) {
        x_3 = kk_std_core_types__new_Nil(_ctx); /*list<nagare/core/interpreter/trace-event<1856>>*/
      }
      else {
        x_3 = kk_nagare_core_interpreter__unroll_lift_listReverse_2558_10000(eventsRev_2, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<nagare/core/interpreter/trace-event<1856>>*/
      }
      kk_unit_t keep_2 = kk_Unit;
      kk_evv_set(w_2,kk_context());
      return kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(x_2, _ctx), kk_std_core_types__list_box(x_3, _ctx), _ctx);
    }
  }
  if (kk_nagare_core_types__is_POutput(state, _ctx)) {
    struct kk_nagare_core_types_POutput* _con_x544 = kk_nagare_core_types__as_POutput(state, _ctx);
    kk_nagare_core_types__chunk out = _con_x544->out;
    kk_nagare_core_types__pull tail = _con_x544->tail;
    if kk_likely(kk_datatype_ptr_is_unique(state, _ctx)) {
      kk_datatype_ptr_free(state, _ctx);
    }
    else {
      kk_nagare_core_types__chunk_dup(out, _ctx);
      kk_nagare_core_types__pull_dup(tail, _ctx);
      kk_datatype_ptr_decref(state, _ctx);
    }
    {
      kk_std_core_types__list values = out.values;
      kk_evv_t w_3 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>|1857>>*/;
      kk_std_core_types__list x_4;
      if (kk_std_core_types__is_Nil(values, _ctx)) {
        x_4 = valuesRev_2; /*list<1856>*/
      }
      else {
        kk_std_core_types__list _x_x545 = kk_std_core_types__list_dup(values, _ctx); /*list<1856>*/
        x_4 = kk_nagare_core_interpreter__unroll_consAllRev_10001(_x_x545, valuesRev_2, _ctx); /*list<1856>*/
      }
      kk_unit_t keep_3 = kk_Unit;
      kk_evv_set(w_3,kk_context());
      kk_evv_t w_4 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>|1857>>*/;
      kk_std_core_types__list x_5;
      if (kk_std_core_types__is_Nil(values, _ctx)) {
        x_5 = eventsRev_2; /*list<nagare/core/interpreter/trace-event<1856>>*/
      }
      else {
        x_5 = kk_nagare_core_interpreter__unroll_pushTraceEventsRev_10005(values, eventsRev_2, _ctx); /*list<nagare/core/interpreter/trace-event<1856>>*/
      }
      kk_unit_t keep_4 = kk_Unit;
      kk_evv_set(w_4,kk_context());
      { // tailcall
        state = tail;
        valuesRev_2 = x_4;
        eventsRev_2 = x_5;
        goto kk__tailcall;
      }
    }
  }
  if (kk_nagare_core_types__is_PEval(state, _ctx)) {
    struct kk_nagare_core_types_PEval* _con_x546 = kk_nagare_core_types__as_PEval(state, _ctx);
    kk_function_t next_0 = _con_x546->next;
    if kk_likely(kk_datatype_ptr_is_unique(state, _ctx)) {
      kk_datatype_ptr_free(state, _ctx);
    }
    else {
      kk_function_dup(next_0, _ctx);
      kk_datatype_ptr_decref(state, _ctx);
    }
    kk_nagare_core_types__pull x_6_10409 = kk_function_call(kk_nagare_core_types__pull, (kk_function_t, kk_context_t*), next_0, (next_0, _ctx), _ctx); /*nagare/core/types/pull<1856,<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>|1857>>*/;
    if (kk_yielding(kk_context())) {
      kk_nagare_core_types__pull_drop(x_6_10409, _ctx);
      kk_box_t _x_x547 = kk_std_core_hnd_yield_extend(kk_nagare_core_interpreter__new_unroll_traceCompileGoPull_10006_fun548(eventsRev_2, finalizersRev_1, valuesRev_2, _ctx), _ctx); /*10001*/
      return kk_std_core_types__tuple2_unbox(_x_x547, KK_OWNED, _ctx);
    }
    { // tailcall
      kk_std_core_types__list _x_x550 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_nagare_core_interpreter__trace_event_box(kk_nagare_core_interpreter__new_TraceEval(_ctx), _ctx), eventsRev_2, _ctx); /*list<10021>*/
      state = x_6_10409;
      eventsRev_2 = _x_x550;
      goto kk__tailcall;
    }
  }
  {
    struct kk_nagare_core_types_PAcquire* _con_x551 = kk_nagare_core_types__as_PAcquire(state, _ctx);
    kk_function_t acquire = _con_x551->acquire;
    kk_function_t release_0 = _con_x551->release;
    kk_nagare_core_types__pull tail_0_0 = _con_x551->tail;
    if kk_likely(kk_datatype_ptr_is_unique(state, _ctx)) {
      kk_datatype_ptr_free(state, _ctx);
    }
    else {
      kk_function_dup(acquire, _ctx);
      kk_function_dup(release_0, _ctx);
      kk_nagare_core_types__pull_dup(tail_0_0, _ctx);
      kk_datatype_ptr_decref(state, _ctx);
    }
    kk_unit_t x_7_10412 = kk_Unit;
    kk_function_call(kk_unit_t, (kk_function_t, kk_context_t*), acquire, (acquire, _ctx), _ctx);
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x552 = kk_std_core_hnd_yield_extend(kk_nagare_core_interpreter__new_unroll_traceCompileGoPull_10006_fun553(eventsRev_2, finalizersRev_1, release_0, tail_0_0, valuesRev_2, _ctx), _ctx); /*10001*/
      return kk_std_core_types__tuple2_unbox(_x_x552, KK_OWNED, _ctx);
    }
    { // tailcall
      kk_std_core_types__list _x_x555 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_function_box(kk_nagare_core_interpreter__new_unroll_traceCompileGoPull_10006_fun556(release_0, _ctx), _ctx), finalizersRev_1, _ctx); /*list<10021>*/
      state = tail_0_0;
      finalizersRev_1 = _x_x555;
      goto kk__tailcall;
    }
  }
}
 
// monadic lift

kk_std_core_types__tuple2 kk_nagare_core_interpreter__mlift_traceCompileGoPull_10339(kk_std_core_types__list eventsRev, kk_std_core_types__list valuesRev, kk_unit_t _c_x10230, kk_context_t* _ctx) { /* forall<a,e> (eventsRev : list<trace-event<a>>, valuesRev : list<a>, ()) -> (list<a>, list<trace-event<a>>) */ 
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>|1857>>*/;
  kk_std_core_types__list x;
  if (kk_std_core_types__is_Nil(valuesRev, _ctx)) {
    x = kk_std_core_types__new_Nil(_ctx); /*list<1856>*/
  }
  else {
    x = kk_nagare_core_interpreter__unroll_lift_listReverse_2558_10000(valuesRev, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<1856>*/
  }
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>|1857>>*/;
  kk_std_core_types__list x_0;
  if (kk_std_core_types__is_Nil(eventsRev, _ctx)) {
    x_0 = kk_std_core_types__new_Nil(_ctx); /*list<nagare/core/interpreter/trace-event<1856>>*/
  }
  else {
    x_0 = kk_nagare_core_interpreter__unroll_lift_listReverse_2558_10000(eventsRev, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<nagare/core/interpreter/trace-event<1856>>*/
  }
  kk_unit_t keep_0 = kk_Unit;
  kk_evv_set(w_0,kk_context());
  return kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(x, _ctx), kk_std_core_types__list_box(x_0, _ctx), _ctx);
}
extern kk_box_t kk_nagare_core_interpreter_traceCompileGoPull_fun559(kk_function_t _fself, kk_box_t _b_x158, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter_traceCompileGoPull_fun559__t* _self = kk_function_as(struct kk_nagare_core_interpreter_traceCompileGoPull_fun559__t*, _fself, _ctx);
  kk_std_core_types__list eventsRev = _self->eventsRev; /* list<nagare/core/interpreter/trace-event<1856>> */
  kk_std_core_types__list valuesRev = _self->valuesRev; /* list<1856> */
  kk_drop_match(_self, {kk_std_core_types__list_dup(eventsRev, _ctx);kk_std_core_types__list_dup(valuesRev, _ctx);}, {}, _ctx)
  kk_unit_t _c_x10230_164 = kk_Unit;
  kk_unit_unbox(_b_x158);
  kk_std_core_types__tuple2 _x_x560 = kk_nagare_core_interpreter__mlift_traceCompileGoPull_10339(eventsRev, valuesRev, _c_x10230_164, _ctx); /*(list<1856>, list<nagare/core/interpreter/trace-event<1856>>)*/
  return kk_std_core_types__tuple2_box(_x_x560, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_nagare_core_interpreter__mlift_toListSink_10340_fun563__t {
  struct kk_function_s _base;
  kk_nagare_core_interpreter__runtime state;
};
static kk_unit_t kk_nagare_core_interpreter__mlift_toListSink_10340_fun563(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_interpreter__new_mlift_toListSink_10340_fun563(kk_nagare_core_interpreter__runtime state, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter__mlift_toListSink_10340_fun563__t* _self = kk_function_alloc_as(struct kk_nagare_core_interpreter__mlift_toListSink_10340_fun563__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_interpreter__mlift_toListSink_10340_fun563, kk_context());
  _self->state = state;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_unit_t kk_nagare_core_interpreter__mlift_toListSink_10340_fun563(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter__mlift_toListSink_10340_fun563__t* _self = kk_function_as(struct kk_nagare_core_interpreter__mlift_toListSink_10340_fun563__t*, _fself, _ctx);
  kk_nagare_core_interpreter__runtime state = _self->state; /* nagare/core/interpreter/runtime<1902,1903> */
  kk_drop_match(_self, {kk_nagare_core_interpreter__runtime_dup(state, _ctx);}, {}, _ctx)
  {
    struct kk_nagare_core_interpreter_Runtime* _con_x564 = kk_nagare_core_interpreter__as_Runtime(state, _ctx);
    kk_nagare_core_types__pull _pat_0 = _con_x564->step;
    kk_ref_t finalizers = _con_x564->finalizers;
    if kk_likely(kk_datatype_ptr_is_unique(state, _ctx)) {
      kk_nagare_core_types__pull_drop(_pat_0, _ctx);
      kk_datatype_ptr_free(state, _ctx);
    }
    else {
      kk_ref_dup(finalizers, _ctx);
      kk_datatype_ptr_decref(state, _ctx);
    }
    kk_std_core_types__list pending;
    kk_box_t _x_x565;
    kk_ref_t _x_x566 = kk_ref_dup(finalizers, _ctx); /*ref<global,list<() -> <io|1903> ()>>*/
    _x_x565 = kk_ref_get(_x_x566,kk_context()); /*10000*/
    pending = kk_std_core_types__list_unbox(_x_x565, KK_OWNED, _ctx); /*list<() -> <io|1903> ()>*/
    kk_unit_t __ = kk_Unit;
    kk_unit_t _brw_x386 = kk_Unit;
    kk_ref_set_borrow(finalizers,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context());
    kk_ref_drop(finalizers, _ctx);
    _brw_x386;
    if (kk_std_core_types__is_Nil(pending, _ctx)) {
      kk_Unit; return kk_Unit;
    }
    {
      kk_nagare_core_interpreter__unroll_runFinalizersRev_10004(pending, _ctx); return kk_Unit;
    }
  }
}

kk_std_core_types__list kk_nagare_core_interpreter__mlift_toListSink_10340(kk_nagare_core_interpreter__runtime state, kk_context_t* _ctx) { /* forall<a,e> (state : runtime<a,e>) -> <io|e> list<a> */ 
  kk_std_core_types__list _b_x174_176;
  kk_nagare_core_interpreter__runtime _x_x561 = kk_nagare_core_interpreter__runtime_dup(state, _ctx); /*nagare/core/interpreter/runtime<1902,1903>*/
  _b_x174_176 = kk_nagare_core_interpreter_collectRuntime(_x_x561, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<1902>*/
  kk_box_t _x_x562 = kk_std_core_hnd_finally_prompt(kk_nagare_core_interpreter__new_mlift_toListSink_10340_fun563(state, _ctx), kk_std_core_types__list_box(_b_x174_176, _ctx), _ctx); /*10000*/
  return kk_std_core_types__list_unbox(_x_x562, KK_OWNED, _ctx);
}
 
// Sink that collects all outputs into a list.


// lift anonymous function
struct kk_nagare_core_interpreter_toListSink_fun567__t {
  struct kk_function_s _base;
};
static kk_std_core_types__list kk_nagare_core_interpreter_toListSink_fun567(kk_function_t _fself, kk_nagare_core_types__nstream source, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_interpreter_new_toListSink_fun567(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_core_interpreter_toListSink_fun567, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_nagare_core_interpreter_toListSink_fun569__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_core_interpreter_toListSink_fun569(kk_function_t _fself, kk_box_t _b_x178, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_interpreter_new_toListSink_fun569(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_core_interpreter_toListSink_fun569, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_core_interpreter_toListSink_fun569(kk_function_t _fself, kk_box_t _b_x178, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_nagare_core_interpreter__runtime state_192 = kk_nagare_core_interpreter__runtime_unbox(_b_x178, KK_OWNED, _ctx); /*nagare/core/interpreter/runtime<1902,1903>*/;
  kk_std_core_types__list _x_x570 = kk_nagare_core_interpreter__mlift_toListSink_10340(state_192, _ctx); /*list<1902>*/
  return kk_std_core_types__list_box(_x_x570, _ctx);
}


// lift anonymous function
struct kk_nagare_core_interpreter_toListSink_fun573__t {
  struct kk_function_s _base;
  kk_nagare_core_interpreter__runtime x_10429;
};
static kk_unit_t kk_nagare_core_interpreter_toListSink_fun573(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_interpreter_new_toListSink_fun573(kk_nagare_core_interpreter__runtime x_10429, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter_toListSink_fun573__t* _self = kk_function_alloc_as(struct kk_nagare_core_interpreter_toListSink_fun573__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_interpreter_toListSink_fun573, kk_context());
  _self->x_10429 = x_10429;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_unit_t kk_nagare_core_interpreter_toListSink_fun573(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter_toListSink_fun573__t* _self = kk_function_as(struct kk_nagare_core_interpreter_toListSink_fun573__t*, _fself, _ctx);
  kk_nagare_core_interpreter__runtime x_10429 = _self->x_10429; /* nagare/core/interpreter/runtime<1902,1903> */
  kk_drop_match(_self, {kk_nagare_core_interpreter__runtime_dup(x_10429, _ctx);}, {}, _ctx)
  {
    struct kk_nagare_core_interpreter_Runtime* _con_x574 = kk_nagare_core_interpreter__as_Runtime(x_10429, _ctx);
    kk_nagare_core_types__pull _pat_0_0 = _con_x574->step;
    kk_ref_t finalizers = _con_x574->finalizers;
    if kk_likely(kk_datatype_ptr_is_unique(x_10429, _ctx)) {
      kk_nagare_core_types__pull_drop(_pat_0_0, _ctx);
      kk_datatype_ptr_free(x_10429, _ctx);
    }
    else {
      kk_ref_dup(finalizers, _ctx);
      kk_datatype_ptr_decref(x_10429, _ctx);
    }
    kk_std_core_types__list pending;
    kk_box_t _x_x575;
    kk_ref_t _x_x576 = kk_ref_dup(finalizers, _ctx); /*ref<global,list<() -> <io|1903> ()>>*/
    _x_x575 = kk_ref_get(_x_x576,kk_context()); /*10000*/
    pending = kk_std_core_types__list_unbox(_x_x575, KK_OWNED, _ctx); /*list<() -> <io|1903> ()>*/
    kk_unit_t __ = kk_Unit;
    kk_unit_t _brw_x385 = kk_Unit;
    kk_ref_set_borrow(finalizers,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context());
    kk_ref_drop(finalizers, _ctx);
    _brw_x385;
    if (kk_std_core_types__is_Nil(pending, _ctx)) {
      kk_Unit; return kk_Unit;
    }
    {
      kk_nagare_core_interpreter__unroll_runFinalizersRev_10004(pending, _ctx); return kk_Unit;
    }
  }
}
static kk_std_core_types__list kk_nagare_core_interpreter_toListSink_fun567(kk_function_t _fself, kk_nagare_core_types__nstream source, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_nagare_core_interpreter__runtime x_10429 = kk_nagare_core_interpreter_runtimeFromStream(source, _ctx); /*nagare/core/interpreter/runtime<1902,1903>*/;
  if (kk_yielding(kk_context())) {
    kk_datatype_ptr_dropn(x_10429, (KK_I32(2)), _ctx);
    kk_box_t _x_x568 = kk_std_core_hnd_yield_extend(kk_nagare_core_interpreter_new_toListSink_fun569(_ctx), _ctx); /*10001*/
    return kk_std_core_types__list_unbox(_x_x568, KK_OWNED, _ctx);
  }
  {
    kk_std_core_types__list _b_x188_191;
    kk_nagare_core_interpreter__runtime _x_x571 = kk_nagare_core_interpreter__runtime_dup(x_10429, _ctx); /*nagare/core/interpreter/runtime<1902,1903>*/
    _b_x188_191 = kk_nagare_core_interpreter_collectRuntime(_x_x571, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<1902>*/
    kk_box_t _x_x572 = kk_std_core_hnd_finally_prompt(kk_nagare_core_interpreter_new_toListSink_fun573(x_10429, _ctx), kk_std_core_types__list_box(_b_x188_191, _ctx), _ctx); /*10000*/
    return kk_std_core_types__list_unbox(_x_x572, KK_OWNED, _ctx);
  }
}

kk_function_t kk_nagare_core_interpreter_toListSink(kk_context_t* _ctx) { /* forall<a,e> () -> sink<a,list<a>,e> */ 
  return kk_nagare_core_interpreter_new_toListSink_fun567(_ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_nagare_core_interpreter__mlift_drainSink_10341_fun579__t {
  struct kk_function_s _base;
  kk_nagare_core_interpreter__runtime state;
};
static kk_unit_t kk_nagare_core_interpreter__mlift_drainSink_10341_fun579(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_interpreter__new_mlift_drainSink_10341_fun579(kk_nagare_core_interpreter__runtime state, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter__mlift_drainSink_10341_fun579__t* _self = kk_function_alloc_as(struct kk_nagare_core_interpreter__mlift_drainSink_10341_fun579__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_interpreter__mlift_drainSink_10341_fun579, kk_context());
  _self->state = state;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_unit_t kk_nagare_core_interpreter__mlift_drainSink_10341_fun579(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter__mlift_drainSink_10341_fun579__t* _self = kk_function_as(struct kk_nagare_core_interpreter__mlift_drainSink_10341_fun579__t*, _fself, _ctx);
  kk_nagare_core_interpreter__runtime state = _self->state; /* nagare/core/interpreter/runtime<1946,1947> */
  kk_drop_match(_self, {kk_nagare_core_interpreter__runtime_dup(state, _ctx);}, {}, _ctx)
  {
    struct kk_nagare_core_interpreter_Runtime* _con_x580 = kk_nagare_core_interpreter__as_Runtime(state, _ctx);
    kk_nagare_core_types__pull _pat_0 = _con_x580->step;
    kk_ref_t finalizers = _con_x580->finalizers;
    if kk_likely(kk_datatype_ptr_is_unique(state, _ctx)) {
      kk_nagare_core_types__pull_drop(_pat_0, _ctx);
      kk_datatype_ptr_free(state, _ctx);
    }
    else {
      kk_ref_dup(finalizers, _ctx);
      kk_datatype_ptr_decref(state, _ctx);
    }
    kk_std_core_types__list pending;
    kk_box_t _x_x581;
    kk_ref_t _x_x582 = kk_ref_dup(finalizers, _ctx); /*ref<global,list<() -> <io|1947> ()>>*/
    _x_x581 = kk_ref_get(_x_x582,kk_context()); /*10000*/
    pending = kk_std_core_types__list_unbox(_x_x581, KK_OWNED, _ctx); /*list<() -> <io|1947> ()>*/
    kk_unit_t __ = kk_Unit;
    kk_unit_t _brw_x383 = kk_Unit;
    kk_ref_set_borrow(finalizers,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context());
    kk_ref_drop(finalizers, _ctx);
    _brw_x383;
    if (kk_std_core_types__is_Nil(pending, _ctx)) {
      kk_Unit; return kk_Unit;
    }
    {
      kk_nagare_core_interpreter__unroll_runFinalizersRev_10004(pending, _ctx); return kk_Unit;
    }
  }
}

kk_unit_t kk_nagare_core_interpreter__mlift_drainSink_10341(kk_nagare_core_interpreter__runtime state, kk_context_t* _ctx) { /* forall<a,e> (state : runtime<a,e>) -> <io|e> () */ 
  kk_unit_t _b_x202_204 = kk_Unit;
  kk_nagare_core_interpreter__runtime _x_x577 = kk_nagare_core_interpreter__runtime_dup(state, _ctx); /*nagare/core/interpreter/runtime<1946,1947>*/
  kk_nagare_core_interpreter_drainRuntime(_x_x577, _ctx);
  kk_box_t _x_x578 = kk_std_core_hnd_finally_prompt(kk_nagare_core_interpreter__new_mlift_drainSink_10341_fun579(state, _ctx), kk_unit_box(_b_x202_204), _ctx); /*10000*/
  kk_unit_unbox(_x_x578); return kk_Unit;
}
 
// Sink that drains a stream for its effects only.


// lift anonymous function
struct kk_nagare_core_interpreter_drainSink_fun583__t {
  struct kk_function_s _base;
};
static kk_unit_t kk_nagare_core_interpreter_drainSink_fun583(kk_function_t _fself, kk_nagare_core_types__nstream source, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_interpreter_new_drainSink_fun583(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_core_interpreter_drainSink_fun583, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_nagare_core_interpreter_drainSink_fun585__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_core_interpreter_drainSink_fun585(kk_function_t _fself, kk_box_t _b_x206, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_interpreter_new_drainSink_fun585(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_core_interpreter_drainSink_fun585, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_core_interpreter_drainSink_fun585(kk_function_t _fself, kk_box_t _b_x206, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_nagare_core_interpreter__runtime state_220 = kk_nagare_core_interpreter__runtime_unbox(_b_x206, KK_OWNED, _ctx); /*nagare/core/interpreter/runtime<1946,1947>*/;
  kk_unit_t _x_x586 = kk_Unit;
  kk_nagare_core_interpreter__mlift_drainSink_10341(state_220, _ctx);
  return kk_unit_box(_x_x586);
}


// lift anonymous function
struct kk_nagare_core_interpreter_drainSink_fun589__t {
  struct kk_function_s _base;
  kk_nagare_core_interpreter__runtime x_10438;
};
static kk_unit_t kk_nagare_core_interpreter_drainSink_fun589(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_interpreter_new_drainSink_fun589(kk_nagare_core_interpreter__runtime x_10438, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter_drainSink_fun589__t* _self = kk_function_alloc_as(struct kk_nagare_core_interpreter_drainSink_fun589__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_interpreter_drainSink_fun589, kk_context());
  _self->x_10438 = x_10438;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_unit_t kk_nagare_core_interpreter_drainSink_fun589(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter_drainSink_fun589__t* _self = kk_function_as(struct kk_nagare_core_interpreter_drainSink_fun589__t*, _fself, _ctx);
  kk_nagare_core_interpreter__runtime x_10438 = _self->x_10438; /* nagare/core/interpreter/runtime<1946,1947> */
  kk_drop_match(_self, {kk_nagare_core_interpreter__runtime_dup(x_10438, _ctx);}, {}, _ctx)
  {
    struct kk_nagare_core_interpreter_Runtime* _con_x590 = kk_nagare_core_interpreter__as_Runtime(x_10438, _ctx);
    kk_nagare_core_types__pull _pat_0_0 = _con_x590->step;
    kk_ref_t finalizers = _con_x590->finalizers;
    if kk_likely(kk_datatype_ptr_is_unique(x_10438, _ctx)) {
      kk_nagare_core_types__pull_drop(_pat_0_0, _ctx);
      kk_datatype_ptr_free(x_10438, _ctx);
    }
    else {
      kk_ref_dup(finalizers, _ctx);
      kk_datatype_ptr_decref(x_10438, _ctx);
    }
    kk_std_core_types__list pending;
    kk_box_t _x_x591;
    kk_ref_t _x_x592 = kk_ref_dup(finalizers, _ctx); /*ref<global,list<() -> <io|1947> ()>>*/
    _x_x591 = kk_ref_get(_x_x592,kk_context()); /*10000*/
    pending = kk_std_core_types__list_unbox(_x_x591, KK_OWNED, _ctx); /*list<() -> <io|1947> ()>*/
    kk_unit_t __ = kk_Unit;
    kk_unit_t _brw_x382 = kk_Unit;
    kk_ref_set_borrow(finalizers,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context());
    kk_ref_drop(finalizers, _ctx);
    _brw_x382;
    if (kk_std_core_types__is_Nil(pending, _ctx)) {
      kk_Unit; return kk_Unit;
    }
    {
      kk_nagare_core_interpreter__unroll_runFinalizersRev_10004(pending, _ctx); return kk_Unit;
    }
  }
}
static kk_unit_t kk_nagare_core_interpreter_drainSink_fun583(kk_function_t _fself, kk_nagare_core_types__nstream source, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_nagare_core_interpreter__runtime x_10438 = kk_nagare_core_interpreter_runtimeFromStream(source, _ctx); /*nagare/core/interpreter/runtime<1946,1947>*/;
  if (kk_yielding(kk_context())) {
    kk_datatype_ptr_dropn(x_10438, (KK_I32(2)), _ctx);
    kk_box_t _x_x584 = kk_std_core_hnd_yield_extend(kk_nagare_core_interpreter_new_drainSink_fun585(_ctx), _ctx); /*10001*/
    kk_unit_unbox(_x_x584); return kk_Unit;
  }
  {
    kk_unit_t _b_x216_219 = kk_Unit;
    kk_nagare_core_interpreter__runtime _x_x587 = kk_nagare_core_interpreter__runtime_dup(x_10438, _ctx); /*nagare/core/interpreter/runtime<1946,1947>*/
    kk_nagare_core_interpreter_drainRuntime(_x_x587, _ctx);
    kk_box_t _x_x588 = kk_std_core_hnd_finally_prompt(kk_nagare_core_interpreter_new_drainSink_fun589(x_10438, _ctx), kk_unit_box(_b_x216_219), _ctx); /*10000*/
    kk_unit_unbox(_x_x588); return kk_Unit;
  }
}

kk_function_t kk_nagare_core_interpreter_drainSink(kk_context_t* _ctx) { /* forall<a,e> () -> sink<a,(),e> */ 
  return kk_nagare_core_interpreter_new_drainSink_fun583(_ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_nagare_core_interpreter__mlift_lastSink_10342_fun595__t {
  struct kk_function_s _base;
  kk_nagare_core_interpreter__runtime state;
};
static kk_unit_t kk_nagare_core_interpreter__mlift_lastSink_10342_fun595(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_interpreter__new_mlift_lastSink_10342_fun595(kk_nagare_core_interpreter__runtime state, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter__mlift_lastSink_10342_fun595__t* _self = kk_function_alloc_as(struct kk_nagare_core_interpreter__mlift_lastSink_10342_fun595__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_interpreter__mlift_lastSink_10342_fun595, kk_context());
  _self->state = state;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_unit_t kk_nagare_core_interpreter__mlift_lastSink_10342_fun595(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter__mlift_lastSink_10342_fun595__t* _self = kk_function_as(struct kk_nagare_core_interpreter__mlift_lastSink_10342_fun595__t*, _fself, _ctx);
  kk_nagare_core_interpreter__runtime state = _self->state; /* nagare/core/interpreter/runtime<1993,1994> */
  kk_drop_match(_self, {kk_nagare_core_interpreter__runtime_dup(state, _ctx);}, {}, _ctx)
  {
    struct kk_nagare_core_interpreter_Runtime* _con_x596 = kk_nagare_core_interpreter__as_Runtime(state, _ctx);
    kk_nagare_core_types__pull _pat_0 = _con_x596->step;
    kk_ref_t finalizers = _con_x596->finalizers;
    if kk_likely(kk_datatype_ptr_is_unique(state, _ctx)) {
      kk_nagare_core_types__pull_drop(_pat_0, _ctx);
      kk_datatype_ptr_free(state, _ctx);
    }
    else {
      kk_ref_dup(finalizers, _ctx);
      kk_datatype_ptr_decref(state, _ctx);
    }
    kk_std_core_types__list pending;
    kk_box_t _x_x597;
    kk_ref_t _x_x598 = kk_ref_dup(finalizers, _ctx); /*ref<global,list<() -> <io|1994> ()>>*/
    _x_x597 = kk_ref_get(_x_x598,kk_context()); /*10000*/
    pending = kk_std_core_types__list_unbox(_x_x597, KK_OWNED, _ctx); /*list<() -> <io|1994> ()>*/
    kk_unit_t __ = kk_Unit;
    kk_unit_t _brw_x380 = kk_Unit;
    kk_ref_set_borrow(finalizers,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context());
    kk_ref_drop(finalizers, _ctx);
    _brw_x380;
    if (kk_std_core_types__is_Nil(pending, _ctx)) {
      kk_Unit; return kk_Unit;
    }
    {
      kk_nagare_core_interpreter__unroll_runFinalizersRev_10004(pending, _ctx); return kk_Unit;
    }
  }
}

kk_std_core_types__maybe kk_nagare_core_interpreter__mlift_lastSink_10342(kk_nagare_core_interpreter__runtime state, kk_context_t* _ctx) { /* forall<a,e> (state : runtime<a,e>) -> <io|e> maybe<a> */ 
  kk_std_core_types__maybe _b_x230_232;
  kk_nagare_core_interpreter__runtime _x_x593 = kk_nagare_core_interpreter__runtime_dup(state, _ctx); /*nagare/core/interpreter/runtime<1993,1994>*/
  _b_x230_232 = kk_nagare_core_interpreter_lastRuntime(_x_x593, kk_std_core_types__new_Nothing(_ctx), _ctx); /*maybe<1993>*/
  kk_box_t _x_x594 = kk_std_core_hnd_finally_prompt(kk_nagare_core_interpreter__new_mlift_lastSink_10342_fun595(state, _ctx), kk_std_core_types__maybe_box(_b_x230_232, _ctx), _ctx); /*10000*/
  return kk_std_core_types__maybe_unbox(_x_x594, KK_OWNED, _ctx);
}
 
// Sink that returns the last element (or Nothing).


// lift anonymous function
struct kk_nagare_core_interpreter_lastSink_fun599__t {
  struct kk_function_s _base;
};
static kk_std_core_types__maybe kk_nagare_core_interpreter_lastSink_fun599(kk_function_t _fself, kk_nagare_core_types__nstream source, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_interpreter_new_lastSink_fun599(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_core_interpreter_lastSink_fun599, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_nagare_core_interpreter_lastSink_fun601__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_core_interpreter_lastSink_fun601(kk_function_t _fself, kk_box_t _b_x234, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_interpreter_new_lastSink_fun601(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_core_interpreter_lastSink_fun601, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_core_interpreter_lastSink_fun601(kk_function_t _fself, kk_box_t _b_x234, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_nagare_core_interpreter__runtime state_248 = kk_nagare_core_interpreter__runtime_unbox(_b_x234, KK_OWNED, _ctx); /*nagare/core/interpreter/runtime<1993,1994>*/;
  kk_std_core_types__maybe _x_x602 = kk_nagare_core_interpreter__mlift_lastSink_10342(state_248, _ctx); /*maybe<1993>*/
  return kk_std_core_types__maybe_box(_x_x602, _ctx);
}


// lift anonymous function
struct kk_nagare_core_interpreter_lastSink_fun605__t {
  struct kk_function_s _base;
  kk_nagare_core_interpreter__runtime x_10447;
};
static kk_unit_t kk_nagare_core_interpreter_lastSink_fun605(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_interpreter_new_lastSink_fun605(kk_nagare_core_interpreter__runtime x_10447, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter_lastSink_fun605__t* _self = kk_function_alloc_as(struct kk_nagare_core_interpreter_lastSink_fun605__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_interpreter_lastSink_fun605, kk_context());
  _self->x_10447 = x_10447;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_unit_t kk_nagare_core_interpreter_lastSink_fun605(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter_lastSink_fun605__t* _self = kk_function_as(struct kk_nagare_core_interpreter_lastSink_fun605__t*, _fself, _ctx);
  kk_nagare_core_interpreter__runtime x_10447 = _self->x_10447; /* nagare/core/interpreter/runtime<1993,1994> */
  kk_drop_match(_self, {kk_nagare_core_interpreter__runtime_dup(x_10447, _ctx);}, {}, _ctx)
  {
    struct kk_nagare_core_interpreter_Runtime* _con_x606 = kk_nagare_core_interpreter__as_Runtime(x_10447, _ctx);
    kk_nagare_core_types__pull _pat_0_0 = _con_x606->step;
    kk_ref_t finalizers = _con_x606->finalizers;
    if kk_likely(kk_datatype_ptr_is_unique(x_10447, _ctx)) {
      kk_nagare_core_types__pull_drop(_pat_0_0, _ctx);
      kk_datatype_ptr_free(x_10447, _ctx);
    }
    else {
      kk_ref_dup(finalizers, _ctx);
      kk_datatype_ptr_decref(x_10447, _ctx);
    }
    kk_std_core_types__list pending;
    kk_box_t _x_x607;
    kk_ref_t _x_x608 = kk_ref_dup(finalizers, _ctx); /*ref<global,list<() -> <io|1994> ()>>*/
    _x_x607 = kk_ref_get(_x_x608,kk_context()); /*10000*/
    pending = kk_std_core_types__list_unbox(_x_x607, KK_OWNED, _ctx); /*list<() -> <io|1994> ()>*/
    kk_unit_t __ = kk_Unit;
    kk_unit_t _brw_x379 = kk_Unit;
    kk_ref_set_borrow(finalizers,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context());
    kk_ref_drop(finalizers, _ctx);
    _brw_x379;
    if (kk_std_core_types__is_Nil(pending, _ctx)) {
      kk_Unit; return kk_Unit;
    }
    {
      kk_nagare_core_interpreter__unroll_runFinalizersRev_10004(pending, _ctx); return kk_Unit;
    }
  }
}
static kk_std_core_types__maybe kk_nagare_core_interpreter_lastSink_fun599(kk_function_t _fself, kk_nagare_core_types__nstream source, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_nagare_core_interpreter__runtime x_10447 = kk_nagare_core_interpreter_runtimeFromStream(source, _ctx); /*nagare/core/interpreter/runtime<1993,1994>*/;
  if (kk_yielding(kk_context())) {
    kk_datatype_ptr_dropn(x_10447, (KK_I32(2)), _ctx);
    kk_box_t _x_x600 = kk_std_core_hnd_yield_extend(kk_nagare_core_interpreter_new_lastSink_fun601(_ctx), _ctx); /*10001*/
    return kk_std_core_types__maybe_unbox(_x_x600, KK_OWNED, _ctx);
  }
  {
    kk_std_core_types__maybe _b_x244_247;
    kk_nagare_core_interpreter__runtime _x_x603 = kk_nagare_core_interpreter__runtime_dup(x_10447, _ctx); /*nagare/core/interpreter/runtime<1993,1994>*/
    _b_x244_247 = kk_nagare_core_interpreter_lastRuntime(_x_x603, kk_std_core_types__new_Nothing(_ctx), _ctx); /*maybe<1993>*/
    kk_box_t _x_x604 = kk_std_core_hnd_finally_prompt(kk_nagare_core_interpreter_new_lastSink_fun605(x_10447, _ctx), kk_std_core_types__maybe_box(_b_x244_247, _ctx), _ctx); /*10000*/
    return kk_std_core_types__maybe_unbox(_x_x604, KK_OWNED, _ctx);
  }
}

kk_function_t kk_nagare_core_interpreter_lastSink(kk_context_t* _ctx) { /* forall<a,e> () -> sink<a,maybe<a>,e> */ 
  return kk_nagare_core_interpreter_new_lastSink_fun599(_ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_nagare_core_interpreter__mlift_foldSink_10343_fun610__t {
  struct kk_function_s _base;
  kk_nagare_core_interpreter__runtime state;
};
static kk_unit_t kk_nagare_core_interpreter__mlift_foldSink_10343_fun610(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_interpreter__new_mlift_foldSink_10343_fun610(kk_nagare_core_interpreter__runtime state, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter__mlift_foldSink_10343_fun610__t* _self = kk_function_alloc_as(struct kk_nagare_core_interpreter__mlift_foldSink_10343_fun610__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_interpreter__mlift_foldSink_10343_fun610, kk_context());
  _self->state = state;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_unit_t kk_nagare_core_interpreter__mlift_foldSink_10343_fun610(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter__mlift_foldSink_10343_fun610__t* _self = kk_function_as(struct kk_nagare_core_interpreter__mlift_foldSink_10343_fun610__t*, _fself, _ctx);
  kk_nagare_core_interpreter__runtime state = _self->state; /* nagare/core/interpreter/runtime<2049,2051> */
  kk_drop_match(_self, {kk_nagare_core_interpreter__runtime_dup(state, _ctx);}, {}, _ctx)
  {
    struct kk_nagare_core_interpreter_Runtime* _con_x611 = kk_nagare_core_interpreter__as_Runtime(state, _ctx);
    kk_nagare_core_types__pull _pat_0 = _con_x611->step;
    kk_ref_t finalizers = _con_x611->finalizers;
    if kk_likely(kk_datatype_ptr_is_unique(state, _ctx)) {
      kk_nagare_core_types__pull_drop(_pat_0, _ctx);
      kk_datatype_ptr_free(state, _ctx);
    }
    else {
      kk_ref_dup(finalizers, _ctx);
      kk_datatype_ptr_decref(state, _ctx);
    }
    kk_std_core_types__list pending;
    kk_box_t _x_x612;
    kk_ref_t _x_x613 = kk_ref_dup(finalizers, _ctx); /*ref<global,list<() -> <io|2051> ()>>*/
    _x_x612 = kk_ref_get(_x_x613,kk_context()); /*10000*/
    pending = kk_std_core_types__list_unbox(_x_x612, KK_OWNED, _ctx); /*list<() -> <io|2051> ()>*/
    kk_unit_t __ = kk_Unit;
    kk_unit_t _brw_x377 = kk_Unit;
    kk_ref_set_borrow(finalizers,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context());
    kk_ref_drop(finalizers, _ctx);
    _brw_x377;
    if (kk_std_core_types__is_Nil(pending, _ctx)) {
      kk_Unit; return kk_Unit;
    }
    {
      kk_nagare_core_interpreter__unroll_runFinalizersRev_10004(pending, _ctx); return kk_Unit;
    }
  }
}

kk_box_t kk_nagare_core_interpreter__mlift_foldSink_10343(kk_box_t init, kk_function_t step, kk_nagare_core_interpreter__runtime state, kk_context_t* _ctx) { /* forall<a,b,e> (init : b, step : (b, a) -> b, state : runtime<a,e>) -> <io|e> b */ 
  kk_function_t _x_x609;
  kk_nagare_core_interpreter__runtime_dup(state, _ctx);
  _x_x609 = kk_nagare_core_interpreter__new_mlift_foldSink_10343_fun610(state, _ctx); /*() -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>|2051> ()*/
  kk_box_t _x_x614 = kk_nagare_core_interpreter_foldRuntime(state, init, step, _ctx); /*1696*/
  return kk_std_core_hnd_finally_prompt(_x_x609, _x_x614, _ctx);
}
 
// Sink that folds outputs with an initial value and step function.


// lift anonymous function
struct kk_nagare_core_interpreter_foldSink_fun615__t {
  struct kk_function_s _base;
  kk_box_t init;
  kk_function_t step;
};
static kk_box_t kk_nagare_core_interpreter_foldSink_fun615(kk_function_t _fself, kk_nagare_core_types__nstream source, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_interpreter_new_foldSink_fun615(kk_box_t init, kk_function_t step, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter_foldSink_fun615__t* _self = kk_function_alloc_as(struct kk_nagare_core_interpreter_foldSink_fun615__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_interpreter_foldSink_fun615, kk_context());
  _self->init = init;
  _self->step = step;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_core_interpreter_foldSink_fun616__t {
  struct kk_function_s _base;
  kk_box_t init;
  kk_function_t step;
};
static kk_box_t kk_nagare_core_interpreter_foldSink_fun616(kk_function_t _fself, kk_box_t _b_x258, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_interpreter_new_foldSink_fun616(kk_box_t init, kk_function_t step, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter_foldSink_fun616__t* _self = kk_function_alloc_as(struct kk_nagare_core_interpreter_foldSink_fun616__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_interpreter_foldSink_fun616, kk_context());
  _self->init = init;
  _self->step = step;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_core_interpreter_foldSink_fun616(kk_function_t _fself, kk_box_t _b_x258, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter_foldSink_fun616__t* _self = kk_function_as(struct kk_nagare_core_interpreter_foldSink_fun616__t*, _fself, _ctx);
  kk_box_t init = _self->init; /* 2050 */
  kk_function_t step = _self->step; /* (2050, 2049) -> 2050 */
  kk_drop_match(_self, {kk_box_dup(init, _ctx);kk_function_dup(step, _ctx);}, {}, _ctx)
  kk_nagare_core_interpreter__runtime _x_x617 = kk_nagare_core_interpreter__runtime_unbox(_b_x258, KK_OWNED, _ctx); /*nagare/core/interpreter/runtime<2049,2051>*/
  return kk_nagare_core_interpreter__mlift_foldSink_10343(init, step, _x_x617, _ctx);
}


// lift anonymous function
struct kk_nagare_core_interpreter_foldSink_fun619__t {
  struct kk_function_s _base;
  kk_nagare_core_interpreter__runtime x_10456;
};
static kk_unit_t kk_nagare_core_interpreter_foldSink_fun619(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_interpreter_new_foldSink_fun619(kk_nagare_core_interpreter__runtime x_10456, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter_foldSink_fun619__t* _self = kk_function_alloc_as(struct kk_nagare_core_interpreter_foldSink_fun619__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_interpreter_foldSink_fun619, kk_context());
  _self->x_10456 = x_10456;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_unit_t kk_nagare_core_interpreter_foldSink_fun619(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter_foldSink_fun619__t* _self = kk_function_as(struct kk_nagare_core_interpreter_foldSink_fun619__t*, _fself, _ctx);
  kk_nagare_core_interpreter__runtime x_10456 = _self->x_10456; /* nagare/core/interpreter/runtime<2049,2051> */
  kk_drop_match(_self, {kk_nagare_core_interpreter__runtime_dup(x_10456, _ctx);}, {}, _ctx)
  {
    struct kk_nagare_core_interpreter_Runtime* _con_x620 = kk_nagare_core_interpreter__as_Runtime(x_10456, _ctx);
    kk_nagare_core_types__pull _pat_0_0 = _con_x620->step;
    kk_ref_t finalizers = _con_x620->finalizers;
    if kk_likely(kk_datatype_ptr_is_unique(x_10456, _ctx)) {
      kk_nagare_core_types__pull_drop(_pat_0_0, _ctx);
      kk_datatype_ptr_free(x_10456, _ctx);
    }
    else {
      kk_ref_dup(finalizers, _ctx);
      kk_datatype_ptr_decref(x_10456, _ctx);
    }
    kk_std_core_types__list pending;
    kk_box_t _x_x621;
    kk_ref_t _x_x622 = kk_ref_dup(finalizers, _ctx); /*ref<global,list<() -> <io|2051> ()>>*/
    _x_x621 = kk_ref_get(_x_x622,kk_context()); /*10000*/
    pending = kk_std_core_types__list_unbox(_x_x621, KK_OWNED, _ctx); /*list<() -> <io|2051> ()>*/
    kk_unit_t __ = kk_Unit;
    kk_unit_t _brw_x376 = kk_Unit;
    kk_ref_set_borrow(finalizers,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context());
    kk_ref_drop(finalizers, _ctx);
    _brw_x376;
    if (kk_std_core_types__is_Nil(pending, _ctx)) {
      kk_Unit; return kk_Unit;
    }
    {
      kk_nagare_core_interpreter__unroll_runFinalizersRev_10004(pending, _ctx); return kk_Unit;
    }
  }
}
static kk_box_t kk_nagare_core_interpreter_foldSink_fun615(kk_function_t _fself, kk_nagare_core_types__nstream source, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter_foldSink_fun615__t* _self = kk_function_as(struct kk_nagare_core_interpreter_foldSink_fun615__t*, _fself, _ctx);
  kk_box_t init = _self->init; /* 2050 */
  kk_function_t step = _self->step; /* (2050, 2049) -> 2050 */
  kk_drop_match(_self, {kk_box_dup(init, _ctx);kk_function_dup(step, _ctx);}, {}, _ctx)
  kk_nagare_core_interpreter__runtime x_10456 = kk_nagare_core_interpreter_runtimeFromStream(source, _ctx); /*nagare/core/interpreter/runtime<2049,2051>*/;
  if (kk_yielding(kk_context())) {
    kk_datatype_ptr_dropn(x_10456, (KK_I32(2)), _ctx);
    return kk_std_core_hnd_yield_extend(kk_nagare_core_interpreter_new_foldSink_fun616(init, step, _ctx), _ctx);
  }
  {
    kk_function_t _x_x618;
    kk_nagare_core_interpreter__runtime_dup(x_10456, _ctx);
    _x_x618 = kk_nagare_core_interpreter_new_foldSink_fun619(x_10456, _ctx); /*() -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>|2051> ()*/
    kk_box_t _x_x623 = kk_nagare_core_interpreter_foldRuntime(x_10456, init, step, _ctx); /*1696*/
    return kk_std_core_hnd_finally_prompt(_x_x618, _x_x623, _ctx);
  }
}

kk_function_t kk_nagare_core_interpreter_foldSink(kk_box_t init, kk_function_t step, kk_context_t* _ctx) { /* forall<a,b,e> (init : b, step : (b, a) -> b) -> sink<a,b,e> */ 
  return kk_nagare_core_interpreter_new_foldSink_fun615(init, step, _ctx);
}
 
// monadic lift

kk_std_core_types__tuple2 kk_nagare_core_interpreter__mlift_traceSink_10344(kk_unit_t _c_x10250, kk_context_t* _ctx) { /* forall<a,e> (()) -> (list<a>, list<trace-event<a>>) */ 
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>|2104>>*/;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>|2104>>*/;
  kk_unit_t keep_0 = kk_Unit;
  kk_evv_set(w_0,kk_context());
  return kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx), kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx), _ctx);
}
 
// Sink that returns both outputs and a trace of eval/emit events.


// lift anonymous function
struct kk_nagare_core_interpreter_traceSink_fun624__t {
  struct kk_function_s _base;
};
static kk_std_core_types__tuple2 kk_nagare_core_interpreter_traceSink_fun624(kk_function_t _fself, kk_nagare_core_types__nstream source, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_interpreter_new_traceSink_fun624(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_core_interpreter_traceSink_fun624, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_nagare_core_interpreter_traceSink_fun626__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_core_interpreter_traceSink_fun626(kk_function_t _fself, kk_box_t _b_x274, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_interpreter_new_traceSink_fun626(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_core_interpreter_traceSink_fun626, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_core_interpreter_traceSink_fun626(kk_function_t _fself, kk_box_t _b_x274, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _c_x10250_280 = kk_Unit;
  kk_unit_unbox(_b_x274);
  kk_std_core_types__tuple2 _x_x627 = kk_nagare_core_interpreter__mlift_traceSink_10344(_c_x10250_280, _ctx); /*(list<2103>, list<nagare/core/interpreter/trace-event<2103>>)*/
  return kk_std_core_types__tuple2_box(_x_x627, _ctx);
}
static kk_std_core_types__tuple2 kk_nagare_core_interpreter_traceSink_fun624(kk_function_t _fself, kk_nagare_core_types__nstream source, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>|2104>>*/;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  {
    kk_nagare_core_types__pull step = source.step;
    kk_nagare_core_types__pull_dup(step, _ctx);
    if (kk_nagare_core_types__is_PDone(step, _ctx)) {
      kk_nagare_core_types__nstream_drop(source, _ctx);
      if (kk_yielding(kk_context())) {
        kk_box_t _x_x625 = kk_std_core_hnd_yield_extend(kk_nagare_core_interpreter_new_traceSink_fun626(_ctx), _ctx); /*10001*/
        return kk_std_core_types__tuple2_unbox(_x_x625, KK_OWNED, _ctx);
      }
      {
        kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>|2104>>*/;
        kk_unit_t keep_0 = kk_Unit;
        kk_evv_set(w_0,kk_context());
        kk_evv_t w_1 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>|2104>>*/;
        kk_unit_t keep_1 = kk_Unit;
        kk_evv_set(w_1,kk_context());
        return kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx), kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx), _ctx);
      }
    }
    {
      kk_nagare_core_types__pull_drop(step, _ctx);
      kk_nagare_core_types__pull _x_x628;
      {
        kk_nagare_core_types__pull step_0 = source.step;
        _x_x628 = step_0; /*nagare/core/types/pull<2103,<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>|2104>>*/
      }
      return kk_nagare_core_interpreter__unroll_traceCompileGoPull_10006(_x_x628, kk_std_core_types__new_Nil(_ctx), kk_std_core_types__new_Nil(_ctx), kk_std_core_types__new_Nil(_ctx), _ctx);
    }
  }
}

kk_function_t kk_nagare_core_interpreter_traceSink(kk_context_t* _ctx) { /* forall<a,e> () -> sink<a,(list<a>, list<trace-event<a>>),e> */ 
  return kk_nagare_core_interpreter_new_traceSink_fun624(_ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_nagare_core_interpreter__mlift_toList_10345_fun632__t {
  struct kk_function_s _base;
  kk_nagare_core_interpreter__runtime state;
};
static kk_unit_t kk_nagare_core_interpreter__mlift_toList_10345_fun632(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_interpreter__new_mlift_toList_10345_fun632(kk_nagare_core_interpreter__runtime state, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter__mlift_toList_10345_fun632__t* _self = kk_function_alloc_as(struct kk_nagare_core_interpreter__mlift_toList_10345_fun632__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_interpreter__mlift_toList_10345_fun632, kk_context());
  _self->state = state;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_unit_t kk_nagare_core_interpreter__mlift_toList_10345_fun632(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter__mlift_toList_10345_fun632__t* _self = kk_function_as(struct kk_nagare_core_interpreter__mlift_toList_10345_fun632__t*, _fself, _ctx);
  kk_nagare_core_interpreter__runtime state = _self->state; /* nagare/core/interpreter/runtime<2261,2262> */
  kk_drop_match(_self, {kk_nagare_core_interpreter__runtime_dup(state, _ctx);}, {}, _ctx)
  {
    struct kk_nagare_core_interpreter_Runtime* _con_x633 = kk_nagare_core_interpreter__as_Runtime(state, _ctx);
    kk_nagare_core_types__pull _pat_0 = _con_x633->step;
    kk_ref_t finalizers = _con_x633->finalizers;
    if kk_likely(kk_datatype_ptr_is_unique(state, _ctx)) {
      kk_nagare_core_types__pull_drop(_pat_0, _ctx);
      kk_datatype_ptr_free(state, _ctx);
    }
    else {
      kk_ref_dup(finalizers, _ctx);
      kk_datatype_ptr_decref(state, _ctx);
    }
    kk_std_core_types__list pending;
    kk_box_t _x_x634;
    kk_ref_t _x_x635 = kk_ref_dup(finalizers, _ctx); /*ref<global,list<() -> <io|2262> ()>>*/
    _x_x634 = kk_ref_get(_x_x635,kk_context()); /*10000*/
    pending = kk_std_core_types__list_unbox(_x_x634, KK_OWNED, _ctx); /*list<() -> <io|2262> ()>*/
    kk_unit_t __ = kk_Unit;
    kk_unit_t _brw_x373 = kk_Unit;
    kk_ref_set_borrow(finalizers,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context());
    kk_ref_drop(finalizers, _ctx);
    _brw_x373;
    if (kk_std_core_types__is_Nil(pending, _ctx)) {
      kk_Unit; return kk_Unit;
    }
    {
      kk_nagare_core_interpreter__unroll_runFinalizersRev_10004(pending, _ctx); return kk_Unit;
    }
  }
}

kk_std_core_types__list kk_nagare_core_interpreter__mlift_toList_10345(kk_nagare_core_interpreter__runtime state, kk_context_t* _ctx) { /* forall<a,e> (state : runtime<a,e>) -> <io|e> list<a> */ 
  kk_std_core_types__list _b_x290_292;
  kk_nagare_core_interpreter__runtime _x_x630 = kk_nagare_core_interpreter__runtime_dup(state, _ctx); /*nagare/core/interpreter/runtime<2261,2262>*/
  _b_x290_292 = kk_nagare_core_interpreter_collectRuntime(_x_x630, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<2261>*/
  kk_box_t _x_x631 = kk_std_core_hnd_finally_prompt(kk_nagare_core_interpreter__new_mlift_toList_10345_fun632(state, _ctx), kk_std_core_types__list_box(_b_x290_292, _ctx), _ctx); /*10000*/
  return kk_std_core_types__list_unbox(_x_x631, KK_OWNED, _ctx);
}
 
// Convenience: run with toListSink.


// lift anonymous function
struct kk_nagare_core_interpreter_toList_fun638__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_core_interpreter_toList_fun638(kk_function_t _fself, kk_box_t _b_x294, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_interpreter_new_toList_fun638(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_core_interpreter_toList_fun638, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_core_interpreter_toList_fun638(kk_function_t _fself, kk_box_t _b_x294, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_nagare_core_interpreter__runtime state_296 = kk_nagare_core_interpreter__runtime_unbox(_b_x294, KK_OWNED, _ctx); /*nagare/core/interpreter/runtime<2261,2262>*/;
  kk_std_core_types__list _x_x639 = kk_nagare_core_interpreter__mlift_toList_10345(state_296, _ctx); /*list<2261>*/
  return kk_std_core_types__list_box(_x_x639, _ctx);
}

kk_std_core_types__list kk_nagare_core_interpreter_toList(kk_nagare_core_interpreter__compile_scope c, kk_context_t* _ctx) { /* forall<a,e> (c : compile-scope<a,e>) -> <io|e> list<a> */ 
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>|2262>>*/;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  kk_nagare_core_interpreter__runtime x_0_10479;
  kk_nagare_core_types__nstream _x_x636;
  {
    kk_nagare_core_types__nstream source = c.source;
    _x_x636 = source; /*nagare/core/types/nstream<2261,<io|2262>>*/
  }
  x_0_10479 = kk_nagare_core_interpreter_runtimeFromStream(_x_x636, _ctx); /*nagare/core/interpreter/runtime<2261,2262>*/
  if (kk_yielding(kk_context())) {
    kk_datatype_ptr_dropn(x_0_10479, (KK_I32(2)), _ctx);
    kk_box_t _x_x637 = kk_std_core_hnd_yield_extend(kk_nagare_core_interpreter_new_toList_fun638(_ctx), _ctx); /*10001*/
    return kk_std_core_types__list_unbox(_x_x637, KK_OWNED, _ctx);
  }
  {
    return kk_nagare_core_interpreter__mlift_toList_10345(x_0_10479, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_nagare_core_interpreter__mlift_drain_10346_fun642__t {
  struct kk_function_s _base;
  kk_nagare_core_interpreter__runtime state;
};
static kk_unit_t kk_nagare_core_interpreter__mlift_drain_10346_fun642(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_interpreter__new_mlift_drain_10346_fun642(kk_nagare_core_interpreter__runtime state, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter__mlift_drain_10346_fun642__t* _self = kk_function_alloc_as(struct kk_nagare_core_interpreter__mlift_drain_10346_fun642__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_interpreter__mlift_drain_10346_fun642, kk_context());
  _self->state = state;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_unit_t kk_nagare_core_interpreter__mlift_drain_10346_fun642(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter__mlift_drain_10346_fun642__t* _self = kk_function_as(struct kk_nagare_core_interpreter__mlift_drain_10346_fun642__t*, _fself, _ctx);
  kk_nagare_core_interpreter__runtime state = _self->state; /* nagare/core/interpreter/runtime<2304,2305> */
  kk_drop_match(_self, {kk_nagare_core_interpreter__runtime_dup(state, _ctx);}, {}, _ctx)
  {
    struct kk_nagare_core_interpreter_Runtime* _con_x643 = kk_nagare_core_interpreter__as_Runtime(state, _ctx);
    kk_nagare_core_types__pull _pat_0 = _con_x643->step;
    kk_ref_t finalizers = _con_x643->finalizers;
    if kk_likely(kk_datatype_ptr_is_unique(state, _ctx)) {
      kk_nagare_core_types__pull_drop(_pat_0, _ctx);
      kk_datatype_ptr_free(state, _ctx);
    }
    else {
      kk_ref_dup(finalizers, _ctx);
      kk_datatype_ptr_decref(state, _ctx);
    }
    kk_std_core_types__list pending;
    kk_box_t _x_x644;
    kk_ref_t _x_x645 = kk_ref_dup(finalizers, _ctx); /*ref<global,list<() -> <io|2305> ()>>*/
    _x_x644 = kk_ref_get(_x_x645,kk_context()); /*10000*/
    pending = kk_std_core_types__list_unbox(_x_x644, KK_OWNED, _ctx); /*list<() -> <io|2305> ()>*/
    kk_unit_t __ = kk_Unit;
    kk_unit_t _brw_x371 = kk_Unit;
    kk_ref_set_borrow(finalizers,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context());
    kk_ref_drop(finalizers, _ctx);
    _brw_x371;
    if (kk_std_core_types__is_Nil(pending, _ctx)) {
      kk_Unit; return kk_Unit;
    }
    {
      kk_nagare_core_interpreter__unroll_runFinalizersRev_10004(pending, _ctx); return kk_Unit;
    }
  }
}

kk_unit_t kk_nagare_core_interpreter__mlift_drain_10346(kk_nagare_core_interpreter__runtime state, kk_context_t* _ctx) { /* forall<a,e> (state : runtime<a,e>) -> <io|e> () */ 
  kk_unit_t _b_x306_308 = kk_Unit;
  kk_nagare_core_interpreter__runtime _x_x640 = kk_nagare_core_interpreter__runtime_dup(state, _ctx); /*nagare/core/interpreter/runtime<2304,2305>*/
  kk_nagare_core_interpreter_drainRuntime(_x_x640, _ctx);
  kk_box_t _x_x641 = kk_std_core_hnd_finally_prompt(kk_nagare_core_interpreter__new_mlift_drain_10346_fun642(state, _ctx), kk_unit_box(_b_x306_308), _ctx); /*10000*/
  kk_unit_unbox(_x_x641); return kk_Unit;
}
 
// Convenience: run with drainSink.


// lift anonymous function
struct kk_nagare_core_interpreter_drain_fun648__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_core_interpreter_drain_fun648(kk_function_t _fself, kk_box_t _b_x310, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_interpreter_new_drain_fun648(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_core_interpreter_drain_fun648, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_core_interpreter_drain_fun648(kk_function_t _fself, kk_box_t _b_x310, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_nagare_core_interpreter__runtime state_312 = kk_nagare_core_interpreter__runtime_unbox(_b_x310, KK_OWNED, _ctx); /*nagare/core/interpreter/runtime<2304,2305>*/;
  kk_unit_t _x_x649 = kk_Unit;
  kk_nagare_core_interpreter__mlift_drain_10346(state_312, _ctx);
  return kk_unit_box(_x_x649);
}

kk_unit_t kk_nagare_core_interpreter_drain(kk_nagare_core_interpreter__compile_scope c, kk_context_t* _ctx) { /* forall<a,e> (c : compile-scope<a,e>) -> <io|e> () */ 
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>|2305>>*/;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  kk_nagare_core_interpreter__runtime x_0_10485;
  kk_nagare_core_types__nstream _x_x646;
  {
    kk_nagare_core_types__nstream source = c.source;
    _x_x646 = source; /*nagare/core/types/nstream<2304,<io|2305>>*/
  }
  x_0_10485 = kk_nagare_core_interpreter_runtimeFromStream(_x_x646, _ctx); /*nagare/core/interpreter/runtime<2304,2305>*/
  if (kk_yielding(kk_context())) {
    kk_datatype_ptr_dropn(x_0_10485, (KK_I32(2)), _ctx);
    kk_box_t _x_x647 = kk_std_core_hnd_yield_extend(kk_nagare_core_interpreter_new_drain_fun648(_ctx), _ctx); /*10001*/
    kk_unit_unbox(_x_x647); return kk_Unit;
  }
  {
    kk_nagare_core_interpreter__mlift_drain_10346(x_0_10485, _ctx); return kk_Unit;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_nagare_core_interpreter__mlift_last_10347_fun652__t {
  struct kk_function_s _base;
  kk_nagare_core_interpreter__runtime state;
};
static kk_unit_t kk_nagare_core_interpreter__mlift_last_10347_fun652(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_interpreter__new_mlift_last_10347_fun652(kk_nagare_core_interpreter__runtime state, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter__mlift_last_10347_fun652__t* _self = kk_function_alloc_as(struct kk_nagare_core_interpreter__mlift_last_10347_fun652__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_interpreter__mlift_last_10347_fun652, kk_context());
  _self->state = state;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_unit_t kk_nagare_core_interpreter__mlift_last_10347_fun652(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter__mlift_last_10347_fun652__t* _self = kk_function_as(struct kk_nagare_core_interpreter__mlift_last_10347_fun652__t*, _fself, _ctx);
  kk_nagare_core_interpreter__runtime state = _self->state; /* nagare/core/interpreter/runtime<2347,2348> */
  kk_drop_match(_self, {kk_nagare_core_interpreter__runtime_dup(state, _ctx);}, {}, _ctx)
  {
    struct kk_nagare_core_interpreter_Runtime* _con_x653 = kk_nagare_core_interpreter__as_Runtime(state, _ctx);
    kk_nagare_core_types__pull _pat_0 = _con_x653->step;
    kk_ref_t finalizers = _con_x653->finalizers;
    if kk_likely(kk_datatype_ptr_is_unique(state, _ctx)) {
      kk_nagare_core_types__pull_drop(_pat_0, _ctx);
      kk_datatype_ptr_free(state, _ctx);
    }
    else {
      kk_ref_dup(finalizers, _ctx);
      kk_datatype_ptr_decref(state, _ctx);
    }
    kk_std_core_types__list pending;
    kk_box_t _x_x654;
    kk_ref_t _x_x655 = kk_ref_dup(finalizers, _ctx); /*ref<global,list<() -> <io|2348> ()>>*/
    _x_x654 = kk_ref_get(_x_x655,kk_context()); /*10000*/
    pending = kk_std_core_types__list_unbox(_x_x654, KK_OWNED, _ctx); /*list<() -> <io|2348> ()>*/
    kk_unit_t __ = kk_Unit;
    kk_unit_t _brw_x369 = kk_Unit;
    kk_ref_set_borrow(finalizers,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context());
    kk_ref_drop(finalizers, _ctx);
    _brw_x369;
    if (kk_std_core_types__is_Nil(pending, _ctx)) {
      kk_Unit; return kk_Unit;
    }
    {
      kk_nagare_core_interpreter__unroll_runFinalizersRev_10004(pending, _ctx); return kk_Unit;
    }
  }
}

kk_std_core_types__maybe kk_nagare_core_interpreter__mlift_last_10347(kk_nagare_core_interpreter__runtime state, kk_context_t* _ctx) { /* forall<a,e> (state : runtime<a,e>) -> <io|e> maybe<a> */ 
  kk_std_core_types__maybe _b_x322_324;
  kk_nagare_core_interpreter__runtime _x_x650 = kk_nagare_core_interpreter__runtime_dup(state, _ctx); /*nagare/core/interpreter/runtime<2347,2348>*/
  _b_x322_324 = kk_nagare_core_interpreter_lastRuntime(_x_x650, kk_std_core_types__new_Nothing(_ctx), _ctx); /*maybe<2347>*/
  kk_box_t _x_x651 = kk_std_core_hnd_finally_prompt(kk_nagare_core_interpreter__new_mlift_last_10347_fun652(state, _ctx), kk_std_core_types__maybe_box(_b_x322_324, _ctx), _ctx); /*10000*/
  return kk_std_core_types__maybe_unbox(_x_x651, KK_OWNED, _ctx);
}
 
// Convenience: run with lastSink.


// lift anonymous function
struct kk_nagare_core_interpreter_last_fun658__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_core_interpreter_last_fun658(kk_function_t _fself, kk_box_t _b_x326, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_interpreter_new_last_fun658(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_core_interpreter_last_fun658, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_core_interpreter_last_fun658(kk_function_t _fself, kk_box_t _b_x326, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_nagare_core_interpreter__runtime state_328 = kk_nagare_core_interpreter__runtime_unbox(_b_x326, KK_OWNED, _ctx); /*nagare/core/interpreter/runtime<2347,2348>*/;
  kk_std_core_types__maybe _x_x659 = kk_nagare_core_interpreter__mlift_last_10347(state_328, _ctx); /*maybe<2347>*/
  return kk_std_core_types__maybe_box(_x_x659, _ctx);
}

kk_std_core_types__maybe kk_nagare_core_interpreter_last(kk_nagare_core_interpreter__compile_scope c, kk_context_t* _ctx) { /* forall<a,e> (c : compile-scope<a,e>) -> <io|e> maybe<a> */ 
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>|2348>>*/;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  kk_nagare_core_interpreter__runtime x_0_10491;
  kk_nagare_core_types__nstream _x_x656;
  {
    kk_nagare_core_types__nstream source = c.source;
    _x_x656 = source; /*nagare/core/types/nstream<2347,<io|2348>>*/
  }
  x_0_10491 = kk_nagare_core_interpreter_runtimeFromStream(_x_x656, _ctx); /*nagare/core/interpreter/runtime<2347,2348>*/
  if (kk_yielding(kk_context())) {
    kk_datatype_ptr_dropn(x_0_10491, (KK_I32(2)), _ctx);
    kk_box_t _x_x657 = kk_std_core_hnd_yield_extend(kk_nagare_core_interpreter_new_last_fun658(_ctx), _ctx); /*10001*/
    return kk_std_core_types__maybe_unbox(_x_x657, KK_OWNED, _ctx);
  }
  {
    return kk_nagare_core_interpreter__mlift_last_10347(x_0_10491, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_nagare_core_interpreter__mlift_fold_10348_fun661__t {
  struct kk_function_s _base;
  kk_nagare_core_interpreter__runtime state;
};
static kk_unit_t kk_nagare_core_interpreter__mlift_fold_10348_fun661(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_interpreter__new_mlift_fold_10348_fun661(kk_nagare_core_interpreter__runtime state, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter__mlift_fold_10348_fun661__t* _self = kk_function_alloc_as(struct kk_nagare_core_interpreter__mlift_fold_10348_fun661__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_interpreter__mlift_fold_10348_fun661, kk_context());
  _self->state = state;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_unit_t kk_nagare_core_interpreter__mlift_fold_10348_fun661(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter__mlift_fold_10348_fun661__t* _self = kk_function_as(struct kk_nagare_core_interpreter__mlift_fold_10348_fun661__t*, _fself, _ctx);
  kk_nagare_core_interpreter__runtime state = _self->state; /* nagare/core/interpreter/runtime<2400,2402> */
  kk_drop_match(_self, {kk_nagare_core_interpreter__runtime_dup(state, _ctx);}, {}, _ctx)
  {
    struct kk_nagare_core_interpreter_Runtime* _con_x662 = kk_nagare_core_interpreter__as_Runtime(state, _ctx);
    kk_nagare_core_types__pull _pat_0 = _con_x662->step;
    kk_ref_t finalizers = _con_x662->finalizers;
    if kk_likely(kk_datatype_ptr_is_unique(state, _ctx)) {
      kk_nagare_core_types__pull_drop(_pat_0, _ctx);
      kk_datatype_ptr_free(state, _ctx);
    }
    else {
      kk_ref_dup(finalizers, _ctx);
      kk_datatype_ptr_decref(state, _ctx);
    }
    kk_std_core_types__list pending;
    kk_box_t _x_x663;
    kk_ref_t _x_x664 = kk_ref_dup(finalizers, _ctx); /*ref<global,list<() -> <io|2402> ()>>*/
    _x_x663 = kk_ref_get(_x_x664,kk_context()); /*10000*/
    pending = kk_std_core_types__list_unbox(_x_x663, KK_OWNED, _ctx); /*list<() -> <io|2402> ()>*/
    kk_unit_t __ = kk_Unit;
    kk_unit_t _brw_x367 = kk_Unit;
    kk_ref_set_borrow(finalizers,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context());
    kk_ref_drop(finalizers, _ctx);
    _brw_x367;
    if (kk_std_core_types__is_Nil(pending, _ctx)) {
      kk_Unit; return kk_Unit;
    }
    {
      kk_nagare_core_interpreter__unroll_runFinalizersRev_10004(pending, _ctx); return kk_Unit;
    }
  }
}

kk_box_t kk_nagare_core_interpreter__mlift_fold_10348(kk_box_t init_0, kk_function_t step_0, kk_nagare_core_interpreter__runtime state, kk_context_t* _ctx) { /* forall<a,b,e> (init@0 : b, step@0 : (b, a) -> b, state : runtime<a,e>) -> <io|e> b */ 
  kk_function_t _x_x660;
  kk_nagare_core_interpreter__runtime_dup(state, _ctx);
  _x_x660 = kk_nagare_core_interpreter__new_mlift_fold_10348_fun661(state, _ctx); /*() -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>|2402> ()*/
  kk_box_t _x_x665 = kk_nagare_core_interpreter_foldRuntime(state, init_0, step_0, _ctx); /*1696*/
  return kk_std_core_hnd_finally_prompt(_x_x660, _x_x665, _ctx);
}
 
// Convenience: run with foldSink.


// lift anonymous function
struct kk_nagare_core_interpreter_fold_fun667__t {
  struct kk_function_s _base;
  kk_box_t init;
  kk_function_t step;
};
static kk_box_t kk_nagare_core_interpreter_fold_fun667(kk_function_t _fself, kk_box_t _b_x338, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_interpreter_new_fold_fun667(kk_box_t init, kk_function_t step, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter_fold_fun667__t* _self = kk_function_alloc_as(struct kk_nagare_core_interpreter_fold_fun667__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_interpreter_fold_fun667, kk_context());
  _self->init = init;
  _self->step = step;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_core_interpreter_fold_fun667(kk_function_t _fself, kk_box_t _b_x338, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter_fold_fun667__t* _self = kk_function_as(struct kk_nagare_core_interpreter_fold_fun667__t*, _fself, _ctx);
  kk_box_t init = _self->init; /* 2401 */
  kk_function_t step = _self->step; /* (2401, 2400) -> 2401 */
  kk_drop_match(_self, {kk_box_dup(init, _ctx);kk_function_dup(step, _ctx);}, {}, _ctx)
  kk_nagare_core_interpreter__runtime _x_x668 = kk_nagare_core_interpreter__runtime_unbox(_b_x338, KK_OWNED, _ctx); /*nagare/core/interpreter/runtime<2400,2402>*/
  return kk_nagare_core_interpreter__mlift_fold_10348(init, step, _x_x668, _ctx);
}

kk_box_t kk_nagare_core_interpreter_fold(kk_nagare_core_interpreter__compile_scope c, kk_box_t init, kk_function_t step, kk_context_t* _ctx) { /* forall<a,b,e> (c : compile-scope<a,e>, init : b, step : (b, a) -> b) -> <io|e> b */ 
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>|2402>>*/;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  kk_nagare_core_interpreter__runtime x_0_10499;
  kk_nagare_core_types__nstream _x_x666;
  {
    kk_nagare_core_types__nstream source_0 = c.source;
    _x_x666 = source_0; /*nagare/core/types/nstream<2400,<io|2402>>*/
  }
  x_0_10499 = kk_nagare_core_interpreter_runtimeFromStream(_x_x666, _ctx); /*nagare/core/interpreter/runtime<2400,2402>*/
  if (kk_yielding(kk_context())) {
    kk_datatype_ptr_dropn(x_0_10499, (KK_I32(2)), _ctx);
    return kk_std_core_hnd_yield_extend(kk_nagare_core_interpreter_new_fold_fun667(init, step, _ctx), _ctx);
  }
  {
    return kk_nagare_core_interpreter__mlift_fold_10348(init, step, x_0_10499, _ctx);
  }
}
 
// monadic lift

kk_std_core_types__tuple2 kk_nagare_core_interpreter__mlift_trace_10349(kk_unit_t _c_x10276, kk_context_t* _ctx) { /* forall<a,e> (()) -> (list<a>, list<trace-event<a>>) */ 
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>|2448>>*/;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>|2448>>*/;
  kk_unit_t keep_0 = kk_Unit;
  kk_evv_set(w_0,kk_context());
  return kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx), kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx), _ctx);
}
 
// Convenience: run with traceSink.


// lift anonymous function
struct kk_nagare_core_interpreter_trace_fun670__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_core_interpreter_trace_fun670(kk_function_t _fself, kk_box_t _b_x346, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_interpreter_new_trace_fun670(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_core_interpreter_trace_fun670, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_core_interpreter_trace_fun670(kk_function_t _fself, kk_box_t _b_x346, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _c_x10276_348 = kk_Unit;
  kk_unit_unbox(_b_x346);
  kk_std_core_types__tuple2 _x_x671 = kk_nagare_core_interpreter__mlift_trace_10349(_c_x10276_348, _ctx); /*(list<2447>, list<nagare/core/interpreter/trace-event<2447>>)*/
  return kk_std_core_types__tuple2_box(_x_x671, _ctx);
}

kk_std_core_types__tuple2 kk_nagare_core_interpreter_trace(kk_nagare_core_interpreter__compile_scope c, kk_context_t* _ctx) { /* forall<a,e> (c : compile-scope<a,e>) -> <io|e> (list<a>, list<trace-event<a>>) */ 
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>|2448>>*/;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>|2448>>*/;
  kk_unit_t keep_0 = kk_Unit;
  kk_evv_set(w_0,kk_context());
  {
    kk_nagare_core_types__nstream source = c.source;
    kk_nagare_core_types__nstream_dup(source, _ctx);
    {
      kk_nagare_core_types__pull step = source.step;
      if (kk_nagare_core_types__is_PDone(step, _ctx)) {
        kk_nagare_core_interpreter__compile_scope_drop(c, _ctx);
        if (kk_yielding(kk_context())) {
          kk_box_t _x_x669 = kk_std_core_hnd_yield_extend(kk_nagare_core_interpreter_new_trace_fun670(_ctx), _ctx); /*10001*/
          return kk_std_core_types__tuple2_unbox(_x_x669, KK_OWNED, _ctx);
        }
        {
          return kk_nagare_core_interpreter__mlift_trace_10349(kk_Unit, _ctx);
        }
      }
      {
        kk_nagare_core_types__pull_drop(step, _ctx);
        kk_nagare_core_types__pull _x_x672;
        {
          kk_nagare_core_types__nstream source_0 = c.source;
          {
            kk_nagare_core_types__pull step_0 = source_0.step;
            _x_x672 = step_0; /*nagare/core/types/pull<2447,<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>|2448>>*/
          }
        }
        return kk_nagare_core_interpreter__unroll_traceCompileGoPull_10006(_x_x672, kk_std_core_types__new_Nil(_ctx), kk_std_core_types__new_Nil(_ctx), kk_std_core_types__new_Nil(_ctx), _ctx);
      }
    }
  }
}
 
// Transform the result of a sink.


// lift anonymous function
struct kk_nagare_core_interpreter_mapResult_fun673__t {
  struct kk_function_s _base;
  kk_function_t f;
  kk_function_t s;
};
static kk_box_t kk_nagare_core_interpreter_mapResult_fun673(kk_function_t _fself, kk_nagare_core_types__nstream source, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_interpreter_new_mapResult_fun673(kk_function_t f, kk_function_t s, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter_mapResult_fun673__t* _self = kk_function_alloc_as(struct kk_nagare_core_interpreter_mapResult_fun673__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_interpreter_mapResult_fun673, kk_context());
  _self->f = f;
  _self->s = s;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_core_interpreter_mapResult_fun674__t {
  struct kk_function_s _base;
  kk_function_t f;
};
static kk_box_t kk_nagare_core_interpreter_mapResult_fun674(kk_function_t _fself, kk_box_t _y_x10280, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_interpreter_new_mapResult_fun674(kk_function_t f, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter_mapResult_fun674__t* _self = kk_function_alloc_as(struct kk_nagare_core_interpreter_mapResult_fun674__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_interpreter_mapResult_fun674, kk_context());
  _self->f = f;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_core_interpreter_mapResult_fun674(kk_function_t _fself, kk_box_t _y_x10280, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter_mapResult_fun674__t* _self = kk_function_as(struct kk_nagare_core_interpreter_mapResult_fun674__t*, _fself, _ctx);
  kk_function_t f = _self->f; /* (2486) -> 2487 */
  kk_drop_match(_self, {kk_function_dup(f, _ctx);}, {}, _ctx)
  return kk_std_core_hnd__open_none1(f, _y_x10280, _ctx);
}
static kk_box_t kk_nagare_core_interpreter_mapResult_fun673(kk_function_t _fself, kk_nagare_core_types__nstream source, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter_mapResult_fun673__t* _self = kk_function_as(struct kk_nagare_core_interpreter_mapResult_fun673__t*, _fself, _ctx);
  kk_function_t f = _self->f; /* (2486) -> 2487 */
  kk_function_t s = _self->s; /* nagare/core/interpreter/sink<2485,2486,2488> */
  kk_drop_match(_self, {kk_function_dup(f, _ctx);kk_function_dup(s, _ctx);}, {}, _ctx)
  kk_box_t x_10510 = kk_function_call(kk_box_t, (kk_function_t, kk_nagare_core_types__nstream, kk_context_t*), s, (s, source, _ctx), _ctx); /*2486*/;
  if (kk_yielding(kk_context())) {
    kk_box_drop(x_10510, _ctx);
    return kk_std_core_hnd_yield_extend(kk_nagare_core_interpreter_new_mapResult_fun674(f, _ctx), _ctx);
  }
  {
    return kk_std_core_hnd__open_none1(f, x_10510, _ctx);
  }
}

kk_function_t kk_nagare_core_interpreter_mapResult(kk_function_t s, kk_function_t f, kk_context_t* _ctx) { /* forall<a,b,c,e> (s : sink<a,b,e>, f : (b) -> c) -> sink<a,c,e> */ 
  return kk_nagare_core_interpreter_new_mapResult_fun673(f, s, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_nagare_core_interpreter__mlift_zipSinks_10352_fun676__t {
  struct kk_function_s _base;
  kk_box_t _y_x10281;
};
static kk_box_t kk_nagare_core_interpreter__mlift_zipSinks_10352_fun676(kk_function_t _fself, kk_box_t _b_x350, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_interpreter__new_mlift_zipSinks_10352_fun676(kk_box_t _y_x10281, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter__mlift_zipSinks_10352_fun676__t* _self = kk_function_alloc_as(struct kk_nagare_core_interpreter__mlift_zipSinks_10352_fun676__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_interpreter__mlift_zipSinks_10352_fun676, kk_context());
  _self->_y_x10281 = _y_x10281;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_core_interpreter__mlift_zipSinks_10352_fun676(kk_function_t _fself, kk_box_t _b_x350, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter__mlift_zipSinks_10352_fun676__t* _self = kk_function_as(struct kk_nagare_core_interpreter__mlift_zipSinks_10352_fun676__t*, _fself, _ctx);
  kk_box_t _y_x10281 = _self->_y_x10281; /* 2542 */
  kk_drop_match(_self, {kk_box_dup(_y_x10281, _ctx);}, {}, _ctx)
  kk_box_t _y_x10282_352 = _b_x350; /*2543*/;
  kk_std_core_types__tuple2 _x_x677 = kk_std_core_types__new_Tuple2(_y_x10281, _y_x10282_352, _ctx); /*(10037, 10038)*/
  return kk_std_core_types__tuple2_box(_x_x677, _ctx);
}

kk_std_core_types__tuple2 kk_nagare_core_interpreter__mlift_zipSinks_10352(kk_function_t right, kk_nagare_core_types__nstream source, kk_box_t _y_x10281, kk_context_t* _ctx) { /* forall<a,b,c,e> (right : sink<a,c,e>, source : nagare/core/types/nstream<a,<io|e>>, b) -> <io|e> (b, c) */ 
  kk_box_t x_10515 = kk_function_call(kk_box_t, (kk_function_t, kk_nagare_core_types__nstream, kk_context_t*), right, (right, source, _ctx), _ctx); /*2543*/;
  if (kk_yielding(kk_context())) {
    kk_box_drop(x_10515, _ctx);
    kk_box_t _x_x675 = kk_std_core_hnd_yield_extend(kk_nagare_core_interpreter__new_mlift_zipSinks_10352_fun676(_y_x10281, _ctx), _ctx); /*10001*/
    return kk_std_core_types__tuple2_unbox(_x_x675, KK_OWNED, _ctx);
  }
  {
    return kk_std_core_types__new_Tuple2(_y_x10281, x_10515, _ctx);
  }
}
 
// Run two sinks over the same source. Traverses the source twice — only safe
// for pure sources with idempotent effects.


// lift anonymous function
struct kk_nagare_core_interpreter_zipSinks_fun678__t {
  struct kk_function_s _base;
  kk_function_t left;
  kk_function_t right;
};
static kk_std_core_types__tuple2 kk_nagare_core_interpreter_zipSinks_fun678(kk_function_t _fself, kk_nagare_core_types__nstream source, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_interpreter_new_zipSinks_fun678(kk_function_t left, kk_function_t right, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter_zipSinks_fun678__t* _self = kk_function_alloc_as(struct kk_nagare_core_interpreter_zipSinks_fun678__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_interpreter_zipSinks_fun678, kk_context());
  _self->left = left;
  _self->right = right;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_core_interpreter_zipSinks_fun681__t {
  struct kk_function_s _base;
  kk_function_t right;
  kk_nagare_core_types__nstream source;
};
static kk_box_t kk_nagare_core_interpreter_zipSinks_fun681(kk_function_t _fself, kk_box_t _b_x354, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_interpreter_new_zipSinks_fun681(kk_function_t right, kk_nagare_core_types__nstream source, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter_zipSinks_fun681__t* _self = kk_function_alloc_as(struct kk_nagare_core_interpreter_zipSinks_fun681__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_interpreter_zipSinks_fun681, kk_context());
  _self->right = right;
  _self->source = source;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_core_interpreter_zipSinks_fun681(kk_function_t _fself, kk_box_t _b_x354, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter_zipSinks_fun681__t* _self = kk_function_as(struct kk_nagare_core_interpreter_zipSinks_fun681__t*, _fself, _ctx);
  kk_function_t right = _self->right; /* nagare/core/interpreter/sink<2541,2543,2544> */
  kk_nagare_core_types__nstream source = _self->source; /* nagare/core/types/nstream<2541,<io|2544>> */
  kk_drop_match(_self, {kk_function_dup(right, _ctx);kk_nagare_core_types__nstream_dup(source, _ctx);}, {}, _ctx)
  kk_box_t _y_x10281_359 = _b_x354; /*2542*/;
  kk_std_core_types__tuple2 _x_x682 = kk_nagare_core_interpreter__mlift_zipSinks_10352(right, source, _y_x10281_359, _ctx); /*(2542, 2543)*/
  return kk_std_core_types__tuple2_box(_x_x682, _ctx);
}


// lift anonymous function
struct kk_nagare_core_interpreter_zipSinks_fun684__t {
  struct kk_function_s _base;
  kk_box_t x_10519;
};
static kk_box_t kk_nagare_core_interpreter_zipSinks_fun684(kk_function_t _fself, kk_box_t _b_x356, kk_context_t* _ctx);
static kk_function_t kk_nagare_core_interpreter_new_zipSinks_fun684(kk_box_t x_10519, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter_zipSinks_fun684__t* _self = kk_function_alloc_as(struct kk_nagare_core_interpreter_zipSinks_fun684__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_interpreter_zipSinks_fun684, kk_context());
  _self->x_10519 = x_10519;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_core_interpreter_zipSinks_fun684(kk_function_t _fself, kk_box_t _b_x356, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter_zipSinks_fun684__t* _self = kk_function_as(struct kk_nagare_core_interpreter_zipSinks_fun684__t*, _fself, _ctx);
  kk_box_t x_10519 = _self->x_10519; /* 2542 */
  kk_drop_match(_self, {kk_box_dup(x_10519, _ctx);}, {}, _ctx)
  kk_box_t _y_x10282_360 = _b_x356; /*2543*/;
  kk_std_core_types__tuple2 _x_x685 = kk_std_core_types__new_Tuple2(x_10519, _y_x10282_360, _ctx); /*(10037, 10038)*/
  return kk_std_core_types__tuple2_box(_x_x685, _ctx);
}
static kk_std_core_types__tuple2 kk_nagare_core_interpreter_zipSinks_fun678(kk_function_t _fself, kk_nagare_core_types__nstream source, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter_zipSinks_fun678__t* _self = kk_function_as(struct kk_nagare_core_interpreter_zipSinks_fun678__t*, _fself, _ctx);
  kk_function_t left = _self->left; /* nagare/core/interpreter/sink<2541,2542,2544> */
  kk_function_t right = _self->right; /* nagare/core/interpreter/sink<2541,2543,2544> */
  kk_drop_match(_self, {kk_function_dup(left, _ctx);kk_function_dup(right, _ctx);}, {}, _ctx)
  kk_box_t x_10519;
  kk_nagare_core_types__nstream _x_x679 = kk_nagare_core_types__nstream_dup(source, _ctx); /*nagare/core/types/nstream<2541,<io|2544>>*/
  x_10519 = kk_function_call(kk_box_t, (kk_function_t, kk_nagare_core_types__nstream, kk_context_t*), left, (left, _x_x679, _ctx), _ctx); /*2542*/
  if (kk_yielding(kk_context())) {
    kk_box_drop(x_10519, _ctx);
    kk_box_t _x_x680 = kk_std_core_hnd_yield_extend(kk_nagare_core_interpreter_new_zipSinks_fun681(right, source, _ctx), _ctx); /*10001*/
    return kk_std_core_types__tuple2_unbox(_x_x680, KK_OWNED, _ctx);
  }
  {
    kk_box_t x_0_10522 = kk_function_call(kk_box_t, (kk_function_t, kk_nagare_core_types__nstream, kk_context_t*), right, (right, source, _ctx), _ctx); /*2543*/;
    if (kk_yielding(kk_context())) {
      kk_box_drop(x_0_10522, _ctx);
      kk_box_t _x_x683 = kk_std_core_hnd_yield_extend(kk_nagare_core_interpreter_new_zipSinks_fun684(x_10519, _ctx), _ctx); /*10001*/
      return kk_std_core_types__tuple2_unbox(_x_x683, KK_OWNED, _ctx);
    }
    {
      return kk_std_core_types__new_Tuple2(x_10519, x_0_10522, _ctx);
    }
  }
}

kk_function_t kk_nagare_core_interpreter_zipSinks(kk_function_t left, kk_function_t right, kk_context_t* _ctx) { /* forall<a,b,c,e> (left : sink<a,b,e>, right : sink<a,c,e>) -> sink<a,(b, c),e> */ 
  return kk_nagare_core_interpreter_new_zipSinks_fun678(left, right, _ctx);
}

// initialization
void kk_nagare_core_interpreter__init(kk_context_t* _ctx){
  static bool _kk_initialized = false;
  if (_kk_initialized) return;
  _kk_initialized = true;
  kk_std_core_types__init(_ctx);
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
  kk_std_core_hnd__init(_ctx);
  kk_nagare_core_types__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
}

// termination
void kk_nagare_core_interpreter__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_nagare_core_types__done(_ctx);
  kk_std_core_hnd__done(_ctx);
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
  kk_std_core_types__done(_ctx);
}
