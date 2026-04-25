#pragma once
#ifndef kk_nagare_core_interpreter_H
#define kk_nagare_core_interpreter_H
// Koka generated module: nagare/core/interpreter, koka version: 3.2.3, platform: 64-bit
#include <kklib.h>
#include "std_core_types.h"
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
#include "std_core_hnd.h"
#include "nagare_core_types.h"

// type declarations

// value type nagare/core/interpreter/compile-scope
struct kk_nagare_core_interpreter_Compile {
  kk_nagare_core_types__nstream source;
};
typedef struct kk_nagare_core_interpreter_Compile kk_nagare_core_interpreter__compile_scope;
static inline kk_nagare_core_interpreter__compile_scope kk_nagare_core_interpreter__new_Compile(kk_nagare_core_types__nstream source, kk_context_t* _ctx) {
  kk_nagare_core_interpreter__compile_scope _con = { source };
  return _con;
}
static inline bool kk_nagare_core_interpreter__is_Compile(kk_nagare_core_interpreter__compile_scope x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_nagare_core_interpreter__compile_scope kk_nagare_core_interpreter__compile_scope_dup(kk_nagare_core_interpreter__compile_scope _x, kk_context_t* _ctx) {
  kk_nagare_core_types__nstream_dup(_x.source, _ctx);
  return _x;
}
static inline void kk_nagare_core_interpreter__compile_scope_drop(kk_nagare_core_interpreter__compile_scope _x, kk_context_t* _ctx) {
  kk_nagare_core_types__nstream_drop(_x.source, _ctx);
}
static inline kk_box_t kk_nagare_core_interpreter__compile_scope_box(kk_nagare_core_interpreter__compile_scope _x, kk_context_t* _ctx) {
  return kk_nagare_core_types__nstream_box(_x.source, _ctx);
}
static inline kk_nagare_core_interpreter__compile_scope kk_nagare_core_interpreter__compile_scope_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_nagare_core_interpreter__new_Compile(kk_nagare_core_types__nstream_unbox(_x, _borrow, _ctx), _ctx);
}

// type nagare/core/interpreter/runtime
struct kk_nagare_core_interpreter__runtime_s {
  kk_block_t _block;
};
typedef kk_datatype_ptr_t kk_nagare_core_interpreter__runtime;
struct kk_nagare_core_interpreter_Runtime {
  struct kk_nagare_core_interpreter__runtime_s _base;
  kk_nagare_core_types__pull step;
  kk_ref_t finalizers;
};
static inline kk_nagare_core_interpreter__runtime kk_nagare_core_interpreter__base_Runtime(struct kk_nagare_core_interpreter_Runtime* _x, kk_context_t* _ctx) {
  return kk_datatype_from_base(&_x->_base, _ctx);
}
static inline kk_nagare_core_interpreter__runtime kk_nagare_core_interpreter__new_Runtime(kk_reuse_t _at, int32_t _cpath, kk_nagare_core_types__pull step, kk_ref_t finalizers, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter_Runtime* _con = kk_block_alloc_at_as(struct kk_nagare_core_interpreter_Runtime, _at, 2 /* scan count */, _cpath, (kk_tag_t)(1), _ctx);
  _con->step = step;
  _con->finalizers = finalizers;
  return kk_nagare_core_interpreter__base_Runtime(_con, _ctx);
}
static inline struct kk_nagare_core_interpreter_Runtime* kk_nagare_core_interpreter__as_Runtime(kk_nagare_core_interpreter__runtime x, kk_context_t* _ctx) {
  return kk_datatype_as_assert(struct kk_nagare_core_interpreter_Runtime*, x, (kk_tag_t)(1), _ctx);
}
static inline bool kk_nagare_core_interpreter__is_Runtime(kk_nagare_core_interpreter__runtime x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_nagare_core_interpreter__runtime kk_nagare_core_interpreter__runtime_dup(kk_nagare_core_interpreter__runtime _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_dup(_x, _ctx);
}
static inline void kk_nagare_core_interpreter__runtime_drop(kk_nagare_core_interpreter__runtime _x, kk_context_t* _ctx) {
  kk_datatype_ptr_drop(_x, _ctx);
}
static inline kk_box_t kk_nagare_core_interpreter__runtime_box(kk_nagare_core_interpreter__runtime _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_box(_x);
}
static inline kk_nagare_core_interpreter__runtime kk_nagare_core_interpreter__runtime_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_datatype_ptr_unbox(_x);
}

// value type nagare/core/interpreter/trace-event
struct kk_nagare_core_interpreter_TraceEval {
  kk_box_t _unused;
};
struct kk_nagare_core_interpreter_TraceEmit {
  kk_box_t value;
};
struct kk_nagare_core_interpreter_trace_event_s {
  kk_value_tag_t _tag;
  union {
    struct kk_nagare_core_interpreter_TraceEval TraceEval;
    struct kk_nagare_core_interpreter_TraceEmit TraceEmit;
    kk_box_t _fields[1];
  } _cons;
};
typedef struct kk_nagare_core_interpreter_trace_event_s kk_nagare_core_interpreter__trace_event;
static inline kk_nagare_core_interpreter__trace_event kk_nagare_core_interpreter__new_TraceEval(kk_context_t* _ctx) {
  kk_nagare_core_interpreter__trace_event _con;
  _con._tag = kk_value_tag(1);
  _con._cons._fields[0] = kk_box_null();
  return _con;
}
static inline kk_nagare_core_interpreter__trace_event kk_nagare_core_interpreter__new_TraceEmit(kk_box_t value, kk_context_t* _ctx) {
  kk_nagare_core_interpreter__trace_event _con;
  _con._tag = kk_value_tag(2);
  _con._cons.TraceEmit.value = value;
  return _con;
}
static inline bool kk_nagare_core_interpreter__is_TraceEval(kk_nagare_core_interpreter__trace_event x, kk_context_t* _ctx) {
  return (kk_value_tag_eq(x._tag, kk_value_tag(1)));
}
static inline bool kk_nagare_core_interpreter__is_TraceEmit(kk_nagare_core_interpreter__trace_event x, kk_context_t* _ctx) {
  return (kk_value_tag_eq(x._tag, kk_value_tag(2)));
}
static inline kk_nagare_core_interpreter__trace_event kk_nagare_core_interpreter__trace_event_dup(kk_nagare_core_interpreter__trace_event _x, kk_context_t* _ctx) {
  if (kk_nagare_core_interpreter__is_TraceEmit(_x, _ctx)) { kk_box_dup(_x._cons.TraceEmit.value, _ctx); }
  return _x;
}
static inline void kk_nagare_core_interpreter__trace_event_drop(kk_nagare_core_interpreter__trace_event _x, kk_context_t* _ctx) {
  if (kk_nagare_core_interpreter__is_TraceEmit(_x, _ctx)) { kk_box_drop(_x._cons.TraceEmit.value, _ctx); }
}
static inline kk_box_t kk_nagare_core_interpreter__trace_event_box(kk_nagare_core_interpreter__trace_event _x, kk_context_t* _ctx) {
  if (kk_nagare_core_interpreter__is_TraceEval(_x, _ctx)) { return kk_box_Nothing(); }
    else { return kk_box_Just(kk_box_box(_x._cons.TraceEmit.value, _ctx), _ctx); }
}
static inline kk_nagare_core_interpreter__trace_event kk_nagare_core_interpreter__trace_event_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  if (kk_box_is_Nothing(_x)) { return kk_nagare_core_interpreter__new_TraceEval(_ctx); }
    else { return kk_nagare_core_interpreter__new_TraceEmit(kk_box_unbox(kk_unbox_Just(_x, _borrow, _ctx), _ctx), _ctx); };
}

// value declarations
 
// Automatically generated. Tests for the `TraceEval` constructor of the `:trace-event` type.

static inline bool kk_nagare_core_interpreter_is_traceEval(kk_nagare_core_interpreter__trace_event trace_event, kk_context_t* _ctx) { /* forall<a> (trace-event : trace-event<a>) -> bool */ 
  if (kk_nagare_core_interpreter__is_TraceEval(trace_event, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `TraceEmit` constructor of the `:trace-event` type.

static inline bool kk_nagare_core_interpreter_is_traceEmit(kk_nagare_core_interpreter__trace_event trace_event, kk_context_t* _ctx) { /* forall<a> (trace-event : trace-event<a>) -> bool */ 
  if (kk_nagare_core_interpreter__is_TraceEmit(trace_event, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Retrieves the `source` constructor field of the `:compile-scope` type.

static inline kk_nagare_core_types__nstream kk_nagare_core_interpreter_compile_scope_fs_source(kk_nagare_core_interpreter__compile_scope _this, kk_context_t* _ctx) { /* forall<a,e> (compile-scope<a,e>) -> nagare/core/types/nstream<a,<io|e>> */ 
  {
    kk_nagare_core_types__nstream _x = _this.source;
    return kk_nagare_core_types__nstream_dup(_x, _ctx);
  }
}

kk_nagare_core_interpreter__compile_scope kk_nagare_core_interpreter_compile_scope_fs__copy(kk_nagare_core_interpreter__compile_scope _this, kk_std_core_types__optional source, kk_context_t* _ctx); /* forall<a,e> (compile-scope<a,e>, source : ? (nagare/core/types/nstream<a,<io|e>>)) -> compile-scope<a,e> */ 
 
// Automatically generated. Retrieves the `finalizers` constructor field of the `:runtime` type.

static inline kk_ref_t kk_nagare_core_interpreter_runtime_fs_finalizers(kk_nagare_core_interpreter__runtime runtime, kk_context_t* _ctx) { /* forall<a,e> (runtime : runtime<a,e>) -> ref<global,list<() -> <io|e> ()>> */ 
  {
    struct kk_nagare_core_interpreter_Runtime* _con_x437 = kk_nagare_core_interpreter__as_Runtime(runtime, _ctx);
    kk_ref_t _x = _con_x437->finalizers;
    return kk_ref_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `step` constructor field of the `:runtime` type.

static inline kk_nagare_core_types__pull kk_nagare_core_interpreter_runtime_fs_step(kk_nagare_core_interpreter__runtime runtime, kk_context_t* _ctx) { /* forall<a,e> (runtime : runtime<a,e>) -> nagare/core/types/pull<a,<io|e>> */ 
  {
    struct kk_nagare_core_interpreter_Runtime* _con_x438 = kk_nagare_core_interpreter__as_Runtime(runtime, _ctx);
    kk_nagare_core_types__pull _x = _con_x438->step;
    return kk_nagare_core_types__pull_dup(_x, _ctx);
  }
}

kk_nagare_core_interpreter__runtime kk_nagare_core_interpreter_runtime_fs__copy(kk_nagare_core_interpreter__runtime _this, kk_std_core_types__optional step, kk_std_core_types__optional finalizers, kk_context_t* _ctx); /* forall<a,e> (runtime<a,e>, step : ? (nagare/core/types/pull<a,<io|e>>), finalizers : ? (ref<global,list<() -> <io|e> ()>>)) -> runtime<a,e> */ 

kk_std_core_types__list kk_nagare_core_interpreter__unroll_lift_listReverse_2558_10000(kk_std_core_types__list rest, kk_std_core_types__list acc, kk_context_t* _ctx); /* forall<a> (rest : list<a>, acc : list<a>) -> list<a> */ 
 
// unrolling of singleton matches of nagare/core/interpreter/@unroll-lift-listReverse@2558@10000

static inline kk_std_core_types__list kk_nagare_core_interpreter__lift_listReverse_2558(kk_std_core_types__list rest, kk_std_core_types__list acc, kk_context_t* _ctx) { /* forall<a> (rest : list<a>, acc : list<a>) -> list<a> */ 
  if (kk_std_core_types__is_Nil(rest, _ctx)) {
    return acc;
  }
  {
    return kk_nagare_core_interpreter__unroll_lift_listReverse_2558_10000(rest, acc, _ctx);
  }
}
 
// Reverse a list (internal helper).

static inline kk_std_core_types__list kk_nagare_core_interpreter_listReverse(kk_std_core_types__list xs, kk_context_t* _ctx) { /* forall<a> (xs : list<a>) -> list<a> */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    return kk_nagare_core_interpreter__unroll_lift_listReverse_2558_10000(xs, kk_std_core_types__new_Nil(_ctx), _ctx);
  }
}

kk_std_core_types__list kk_nagare_core_interpreter__unroll_consAllRev_10001(kk_std_core_types__list xs, kk_std_core_types__list accRev, kk_context_t* _ctx); /* forall<a> (xs : list<a>, accRev : list<a>) -> list<a> */ 
 
// unrolling of singleton matches of nagare/core/interpreter/@unroll-consAllRev@10001

static inline kk_std_core_types__list kk_nagare_core_interpreter_consAllRev(kk_std_core_types__list xs, kk_std_core_types__list accRev, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, accRev : list<a>) -> list<a> */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    return accRev;
  }
  {
    return kk_nagare_core_interpreter__unroll_consAllRev_10001(xs, accRev, _ctx);
  }
}

kk_std_core_types__maybe kk_nagare_core_interpreter__unroll_lastInList_10002(kk_std_core_types__list xs, kk_std_core_types__maybe fallback, kk_context_t* _ctx); /* forall<a> (xs : list<a>, fallback : maybe<a>) -> maybe<a> */ 
 
// unrolling of singleton matches of nagare/core/interpreter/@unroll-lastInList@10002

static inline kk_std_core_types__maybe kk_nagare_core_interpreter_lastInList(kk_std_core_types__list xs, kk_std_core_types__maybe fallback, kk_context_t* _ctx) { /* forall<a> (xs : list<a>, fallback : maybe<a>) -> maybe<a> */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    return fallback;
  }
  {
    return kk_nagare_core_interpreter__unroll_lastInList_10002(xs, fallback, _ctx);
  }
}

kk_box_t kk_nagare_core_interpreter__unroll_foldList_10003(kk_std_core_types__list xs, kk_box_t init, kk_function_t step, kk_context_t* _ctx); /* forall<a,b> (xs : list<a>, init : b, step : (b, a) -> b) -> b */ 
 
// unrolling of singleton matches of nagare/core/interpreter/@unroll-foldList@10003

static inline kk_box_t kk_nagare_core_interpreter_foldList(kk_std_core_types__list xs, kk_box_t init, kk_function_t step, kk_context_t* _ctx) { /* forall<a,b> (xs : list<a>, init : b, step : (b, a) -> b) -> b */ 
  if (kk_std_core_types__is_Nil(xs, _ctx)) {
    kk_function_drop(step, _ctx);
    return init;
  }
  {
    return kk_nagare_core_interpreter__unroll_foldList_10003(xs, init, step, _ctx);
  }
}

kk_unit_t kk_nagare_core_interpreter__mlift_unroll_runFinalizersRev_10004_10328(kk_std_core_types__list rest, kk_unit_t wild__, kk_context_t* _ctx); /* forall<e> (rest : list<() -> <io|e> ()>, wild_ : ()) -> <io|e> () */ 

kk_unit_t kk_nagare_core_interpreter__unroll_runFinalizersRev_10004(kk_std_core_types__list finalizersRev, kk_context_t* _ctx); /* forall<e> (finalizersRev : list<() -> <io|e> ()>) -> <io|e> () */ 
 
// unrolling of singleton matches of nagare/core/interpreter/@unroll-runFinalizersRev@10004

static inline kk_unit_t kk_nagare_core_interpreter_runFinalizersRev(kk_std_core_types__list finalizersRev, kk_context_t* _ctx) { /* forall<e> (finalizersRev : list<() -> <io|e> ()>) -> <io|e> () */ 
  if (kk_std_core_types__is_Nil(finalizersRev, _ctx)) {
    kk_Unit; return kk_Unit;
  }
  {
    kk_nagare_core_interpreter__unroll_runFinalizersRev_10004(finalizersRev, _ctx); return kk_Unit;
  }
}
 
// Initialize runtime state for a stream (no finalizers registered yet).

static inline kk_nagare_core_interpreter__runtime kk_nagare_core_interpreter_runtimeFromStream(kk_nagare_core_types__nstream source, kk_context_t* _ctx) { /* forall<a,e> (source : nagare/core/types/nstream<a,<io|e>>) -> <io|e> runtime<a,e> */ 
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>|890>>*/;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  kk_nagare_core_types__pull _x_x458;
  {
    kk_nagare_core_types__pull step = source.step;
    _x_x458 = step; /*nagare/core/types/pull<889,<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>|890>>*/
  }
  kk_ref_t _x_x459 = kk_ref_alloc((kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*ref<10001,10000>*/
  return kk_nagare_core_interpreter__new_Runtime(kk_reuse_null, 0, _x_x458, _x_x459, _ctx);
}

kk_unit_t kk_nagare_core_interpreter_closeRuntime(kk_nagare_core_interpreter__runtime state, kk_context_t* _ctx); /* forall<a,e> (state : runtime<a,e>) -> <io|e> () */ 

kk_box_t kk_nagare_core_interpreter__mlift_withRuntime_10329(kk_function_t body, kk_nagare_core_interpreter__runtime state, kk_context_t* _ctx); /* forall<a,b,e> (body : (runtime<a,e>) -> <io|e> b, state : runtime<a,e>) -> <io|e> b */ 

kk_box_t kk_nagare_core_interpreter_withRuntime(kk_nagare_core_types__nstream source, kk_function_t body, kk_context_t* _ctx); /* forall<a,b,e> (source : nagare/core/types/nstream<a,<io|e>>, body : (runtime<a,e>) -> <io|e> b) -> <io|e> b */ 

kk_std_core_types__list kk_nagare_core_interpreter__unroll_pushTraceEventsRev_10005(kk_std_core_types__list values, kk_std_core_types__list eventsRev, kk_context_t* _ctx); /* forall<a> (values : list<a>, eventsRev : list<trace-event<a>>) -> list<trace-event<a>> */ 
 
// unrolling of singleton matches of nagare/core/interpreter/@unroll-pushTraceEventsRev@10005

static inline kk_std_core_types__list kk_nagare_core_interpreter_pushTraceEventsRev(kk_std_core_types__list values, kk_std_core_types__list eventsRev, kk_context_t* _ctx) { /* forall<a> (values : list<a>, eventsRev : list<trace-event<a>>) -> list<trace-event<a>> */ 
  if (kk_std_core_types__is_Nil(values, _ctx)) {
    return eventsRev;
  }
  {
    return kk_nagare_core_interpreter__unroll_pushTraceEventsRev_10005(values, eventsRev, _ctx);
  }
}

kk_std_core_types__maybe2 kk_nagare_core_interpreter_nextFromChunk(kk_std_core_types__list values, kk_nagare_core_types__pull tail, kk_context_t* _ctx); /* forall<a,e> (values : list<a>, tail : nagare/core/types/pull<a,<io|e>>) -> maybe2<a,nagare/core/types/pull<a,<io|e>>> */ 

kk_std_core_types__maybe2 kk_nagare_core_interpreter__mlift_nextItemRuntime_10330(kk_ref_t finalizers_0, kk_nagare_core_types__pull _y_x10203, kk_context_t* _ctx); /* forall<a,e> (finalizers@0 : ref<global,list<() -> <io|e> ()>>, nagare/core/types/pull<a,<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>|e>>) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>|e> maybe2<a,runtime<a,e>> */ 

kk_std_core_types__maybe2 kk_nagare_core_interpreter__mlift_nextItemRuntime_10331(kk_ref_t finalizers_1, kk_function_t release, kk_nagare_core_types__pull tail_0, kk_unit_t wild__, kk_context_t* _ctx); /* forall<a,e> (finalizers@1 : ref<global,list<() -> <io|e> ()>>, release : () -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>|e> (), tail@0 : nagare/core/types/pull<a,<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>|e>>, wild_ : ()) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>|e> maybe2<a,runtime<a,e>> */ 

kk_std_core_types__maybe2 kk_nagare_core_interpreter_nextItemRuntime(kk_nagare_core_interpreter__runtime state, kk_context_t* _ctx); /* forall<a,e> (state : runtime<a,e>) -> <io|e> maybe2<a,runtime<a,e>> */ 

kk_std_core_types__list kk_nagare_core_interpreter__mlift_collectRuntime_10332(kk_std_core_types__list accRev, kk_std_core_types__maybe2 _y_x10208, kk_context_t* _ctx); /* forall<a,e> (accRev : list<a>, maybe2<a,runtime<a,e>>) -> <io|e> list<a> */ 

kk_std_core_types__list kk_nagare_core_interpreter_collectRuntime(kk_nagare_core_interpreter__runtime state, kk_std_core_types__list accRev_0, kk_context_t* _ctx); /* forall<a,e> (state : runtime<a,e>, accRev : list<a>) -> <io|e> list<a> */ 

kk_unit_t kk_nagare_core_interpreter__mlift_drainRuntime_10333(kk_std_core_types__maybe2 _y_x10211, kk_context_t* _ctx); /* forall<a,e> (maybe2<a,runtime<a,e>>) -> <io|e> () */ 

kk_unit_t kk_nagare_core_interpreter_drainRuntime(kk_nagare_core_interpreter__runtime state, kk_context_t* _ctx); /* forall<a,e> (state : runtime<a,e>) -> <io|e> () */ 

kk_std_core_types__maybe kk_nagare_core_interpreter__mlift_lastRuntime_10334(kk_std_core_types__maybe current, kk_std_core_types__maybe2 _y_x10214, kk_context_t* _ctx); /* forall<a,e> (current : maybe<a>, maybe2<a,runtime<a,e>>) -> <io|e> maybe<a> */ 

kk_std_core_types__maybe kk_nagare_core_interpreter_lastRuntime(kk_nagare_core_interpreter__runtime state, kk_std_core_types__maybe current_0, kk_context_t* _ctx); /* forall<a,e> (state : runtime<a,e>, current : maybe<a>) -> <io|e> maybe<a> */ 

kk_box_t kk_nagare_core_interpreter__mlift_foldRuntime_10335(kk_box_t init, kk_function_t step, kk_std_core_types__maybe2 _y_x10217, kk_context_t* _ctx); /* forall<a,b,e> (init : b, step : (b, a) -> b, maybe2<a,runtime<a,e>>) -> <io|e> b */ 

kk_box_t kk_nagare_core_interpreter_foldRuntime(kk_nagare_core_interpreter__runtime state, kk_box_t init_0, kk_function_t step_0, kk_context_t* _ctx); /* forall<a,b,e> (state : runtime<a,e>, init : b, step : (b, a) -> b) -> <io|e> b */ 

kk_std_core_types__tuple2 kk_nagare_core_interpreter__mlift_unroll_traceCompileGoPull_10006_10336(kk_std_core_types__list eventsRev, kk_std_core_types__list valuesRev, kk_unit_t _c_x10221, kk_context_t* _ctx); /* forall<a,e> (eventsRev : list<trace-event<a>>, valuesRev : list<a>, ()) -> (list<a>, list<trace-event<a>>) */ 

kk_std_core_types__tuple2 kk_nagare_core_interpreter__mlift_unroll_traceCompileGoPull_10006_10337(kk_std_core_types__list eventsRev_0, kk_std_core_types__list finalizersRev, kk_std_core_types__list valuesRev_0, kk_nagare_core_types__pull _y_x10224, kk_context_t* _ctx); /* forall<a,e> (eventsRev : list<trace-event<a>>, finalizersRev : list<() -> <io|e> ()>, valuesRev : list<a>, nagare/core/types/pull<a,<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>|e>>) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>|e> (list<a>, list<trace-event<a>>) */ 

kk_std_core_types__tuple2 kk_nagare_core_interpreter__mlift_unroll_traceCompileGoPull_10006_10338(kk_std_core_types__list eventsRev_1, kk_std_core_types__list finalizersRev_0, kk_function_t release, kk_nagare_core_types__pull tail_0, kk_std_core_types__list valuesRev_1, kk_unit_t wild___0, kk_context_t* _ctx); /* forall<a,e> (eventsRev : list<trace-event<a>>, finalizersRev : list<() -> <io|e> ()>, release : () -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>|e> (), tail@0 : nagare/core/types/pull<a,<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>|e>>, valuesRev : list<a>, wild_@0 : ()) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>|e> (list<a>, list<trace-event<a>>) */ 

kk_std_core_types__tuple2 kk_nagare_core_interpreter__unroll_traceCompileGoPull_10006(kk_nagare_core_types__pull state, kk_std_core_types__list finalizersRev_1, kk_std_core_types__list valuesRev_2, kk_std_core_types__list eventsRev_2, kk_context_t* _ctx); /* forall<a,e> (state : nagare/core/types/pull<a,<io|e>>, finalizersRev : list<() -> <io|e> ()>, valuesRev : list<a>, eventsRev : list<trace-event<a>>) -> <io|e> (list<a>, list<trace-event<a>>) */ 

kk_std_core_types__tuple2 kk_nagare_core_interpreter__mlift_traceCompileGoPull_10339(kk_std_core_types__list eventsRev, kk_std_core_types__list valuesRev, kk_unit_t _c_x10230, kk_context_t* _ctx); /* forall<a,e> (eventsRev : list<trace-event<a>>, valuesRev : list<a>, ()) -> (list<a>, list<trace-event<a>>) */ 
 
// unrolling of singleton matches of nagare/core/interpreter/@unroll-traceCompileGoPull@10006


// lift anonymous function
struct kk_nagare_core_interpreter_traceCompileGoPull_fun559__t {
  struct kk_function_s _base;
  kk_std_core_types__list eventsRev;
  kk_std_core_types__list valuesRev;
};
extern kk_box_t kk_nagare_core_interpreter_traceCompileGoPull_fun559(kk_function_t _fself, kk_box_t _b_x158, kk_context_t* _ctx);
static inline kk_function_t kk_nagare_core_interpreter_new_traceCompileGoPull_fun559(kk_std_core_types__list eventsRev, kk_std_core_types__list valuesRev, kk_context_t* _ctx) {
  struct kk_nagare_core_interpreter_traceCompileGoPull_fun559__t* _self = kk_function_alloc_as(struct kk_nagare_core_interpreter_traceCompileGoPull_fun559__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_core_interpreter_traceCompileGoPull_fun559, kk_context());
  _self->eventsRev = eventsRev;
  _self->valuesRev = valuesRev;
  return kk_datatype_from_base(&_self->_base, kk_context());
}


static inline kk_std_core_types__tuple2 kk_nagare_core_interpreter_traceCompileGoPull(kk_nagare_core_types__pull state, kk_std_core_types__list finalizersRev, kk_std_core_types__list valuesRev, kk_std_core_types__list eventsRev, kk_context_t* _ctx) { /* forall<a,e> (state : nagare/core/types/pull<a,<io|e>>, finalizersRev : list<() -> <io|e> ()>, valuesRev : list<a>, eventsRev : list<trace-event<a>>) -> <io|e> (list<a>, list<trace-event<a>>) */ 
  if (kk_nagare_core_types__is_PDone(state, _ctx)) {
    kk_unit_t x_10419 = kk_Unit;
    if (kk_std_core_types__is_Nil(finalizersRev, _ctx)) {
      
    }
    else {
      kk_nagare_core_interpreter__unroll_runFinalizersRev_10004(finalizersRev, _ctx);
    }
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x558 = kk_std_core_hnd_yield_extend(kk_nagare_core_interpreter_new_traceCompileGoPull_fun559(eventsRev, valuesRev, _ctx), _ctx); /*10001*/
      return kk_std_core_types__tuple2_unbox(_x_x558, KK_OWNED, _ctx);
    }
    {
      kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>|1857>>*/;
      kk_std_core_types__list x_0;
      if (kk_std_core_types__is_Nil(valuesRev, _ctx)) {
        x_0 = kk_std_core_types__new_Nil(_ctx); /*list<1856>*/
      }
      else {
        x_0 = kk_nagare_core_interpreter__unroll_lift_listReverse_2558_10000(valuesRev, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<1856>*/
      }
      kk_unit_t keep = kk_Unit;
      kk_evv_set(w,kk_context());
      kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>|1857>>*/;
      kk_std_core_types__list x_1;
      if (kk_std_core_types__is_Nil(eventsRev, _ctx)) {
        x_1 = kk_std_core_types__new_Nil(_ctx); /*list<nagare/core/interpreter/trace-event<1856>>*/
      }
      else {
        x_1 = kk_nagare_core_interpreter__unroll_lift_listReverse_2558_10000(eventsRev, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<nagare/core/interpreter/trace-event<1856>>*/
      }
      kk_unit_t keep_0 = kk_Unit;
      kk_evv_set(w_0,kk_context());
      return kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(x_0, _ctx), kk_std_core_types__list_box(x_1, _ctx), _ctx);
    }
  }
  {
    return kk_nagare_core_interpreter__unroll_traceCompileGoPull_10006(state, finalizersRev, valuesRev, eventsRev, _ctx);
  }
}

kk_std_core_types__list kk_nagare_core_interpreter__mlift_toListSink_10340(kk_nagare_core_interpreter__runtime state, kk_context_t* _ctx); /* forall<a,e> (state : runtime<a,e>) -> <io|e> list<a> */ 

kk_function_t kk_nagare_core_interpreter_toListSink(kk_context_t* _ctx); /* forall<a,e> () -> sink<a,list<a>,e> */ 

kk_unit_t kk_nagare_core_interpreter__mlift_drainSink_10341(kk_nagare_core_interpreter__runtime state, kk_context_t* _ctx); /* forall<a,e> (state : runtime<a,e>) -> <io|e> () */ 

kk_function_t kk_nagare_core_interpreter_drainSink(kk_context_t* _ctx); /* forall<a,e> () -> sink<a,(),e> */ 

kk_std_core_types__maybe kk_nagare_core_interpreter__mlift_lastSink_10342(kk_nagare_core_interpreter__runtime state, kk_context_t* _ctx); /* forall<a,e> (state : runtime<a,e>) -> <io|e> maybe<a> */ 

kk_function_t kk_nagare_core_interpreter_lastSink(kk_context_t* _ctx); /* forall<a,e> () -> sink<a,maybe<a>,e> */ 

kk_box_t kk_nagare_core_interpreter__mlift_foldSink_10343(kk_box_t init, kk_function_t step, kk_nagare_core_interpreter__runtime state, kk_context_t* _ctx); /* forall<a,b,e> (init : b, step : (b, a) -> b, state : runtime<a,e>) -> <io|e> b */ 

kk_function_t kk_nagare_core_interpreter_foldSink(kk_box_t init, kk_function_t step, kk_context_t* _ctx); /* forall<a,b,e> (init : b, step : (b, a) -> b) -> sink<a,b,e> */ 

kk_std_core_types__tuple2 kk_nagare_core_interpreter__mlift_traceSink_10344(kk_unit_t _c_x10250, kk_context_t* _ctx); /* forall<a,e> (()) -> (list<a>, list<trace-event<a>>) */ 

kk_function_t kk_nagare_core_interpreter_traceSink(kk_context_t* _ctx); /* forall<a,e> () -> sink<a,(list<a>, list<trace-event<a>>),e> */ 
 
// Execute a stream description with a sink interpreter.

static inline kk_box_t kk_nagare_core_interpreter_run(kk_nagare_core_types__nstream source, kk_function_t s, kk_context_t* _ctx) { /* forall<a,b,e> (source : nagare/core/types/nstream<a,<io|e>>, s : sink<a,b,e>) -> <io|e> b */ 
  return kk_function_call(kk_box_t, (kk_function_t, kk_nagare_core_types__nstream, kk_context_t*), s, (s, source, _ctx), _ctx);
}
 
// Create a compile scope for chain-style execution.

static inline kk_nagare_core_interpreter__compile_scope kk_nagare_core_interpreter_compile(kk_nagare_core_types__nstream source, kk_context_t* _ctx) { /* forall<a,e> (source : nagare/core/types/nstream<a,<io|e>>) -> compile-scope<a,e> */ 
  return kk_nagare_core_interpreter__new_Compile(source, _ctx);
}
 
// Execute a compile scope with a sink.

static inline kk_box_t kk_nagare_core_interpreter_runCompile(kk_nagare_core_interpreter__compile_scope c, kk_function_t s, kk_context_t* _ctx) { /* forall<a,b,e> (c : compile-scope<a,e>, s : sink<a,b,e>) -> <io|e> b */ 
  kk_nagare_core_types__nstream _x_x629;
  {
    kk_nagare_core_types__nstream source = c.source;
    _x_x629 = source; /*nagare/core/types/nstream<2214,<io|2216>>*/
  }
  return kk_function_call(kk_box_t, (kk_function_t, kk_nagare_core_types__nstream, kk_context_t*), s, (s, _x_x629, _ctx), _ctx);
}

kk_std_core_types__list kk_nagare_core_interpreter__mlift_toList_10345(kk_nagare_core_interpreter__runtime state, kk_context_t* _ctx); /* forall<a,e> (state : runtime<a,e>) -> <io|e> list<a> */ 

kk_std_core_types__list kk_nagare_core_interpreter_toList(kk_nagare_core_interpreter__compile_scope c, kk_context_t* _ctx); /* forall<a,e> (c : compile-scope<a,e>) -> <io|e> list<a> */ 

kk_unit_t kk_nagare_core_interpreter__mlift_drain_10346(kk_nagare_core_interpreter__runtime state, kk_context_t* _ctx); /* forall<a,e> (state : runtime<a,e>) -> <io|e> () */ 

kk_unit_t kk_nagare_core_interpreter_drain(kk_nagare_core_interpreter__compile_scope c, kk_context_t* _ctx); /* forall<a,e> (c : compile-scope<a,e>) -> <io|e> () */ 

kk_std_core_types__maybe kk_nagare_core_interpreter__mlift_last_10347(kk_nagare_core_interpreter__runtime state, kk_context_t* _ctx); /* forall<a,e> (state : runtime<a,e>) -> <io|e> maybe<a> */ 

kk_std_core_types__maybe kk_nagare_core_interpreter_last(kk_nagare_core_interpreter__compile_scope c, kk_context_t* _ctx); /* forall<a,e> (c : compile-scope<a,e>) -> <io|e> maybe<a> */ 

kk_box_t kk_nagare_core_interpreter__mlift_fold_10348(kk_box_t init_0, kk_function_t step_0, kk_nagare_core_interpreter__runtime state, kk_context_t* _ctx); /* forall<a,b,e> (init@0 : b, step@0 : (b, a) -> b, state : runtime<a,e>) -> <io|e> b */ 

kk_box_t kk_nagare_core_interpreter_fold(kk_nagare_core_interpreter__compile_scope c, kk_box_t init, kk_function_t step, kk_context_t* _ctx); /* forall<a,b,e> (c : compile-scope<a,e>, init : b, step : (b, a) -> b) -> <io|e> b */ 

kk_std_core_types__tuple2 kk_nagare_core_interpreter__mlift_trace_10349(kk_unit_t _c_x10276, kk_context_t* _ctx); /* forall<a,e> (()) -> (list<a>, list<trace-event<a>>) */ 

kk_std_core_types__tuple2 kk_nagare_core_interpreter_trace(kk_nagare_core_interpreter__compile_scope c, kk_context_t* _ctx); /* forall<a,e> (c : compile-scope<a,e>) -> <io|e> (list<a>, list<trace-event<a>>) */ 
 
// monadic lift

static inline kk_box_t kk_nagare_core_interpreter__mlift_mapResult_10350(kk_function_t f, kk_box_t _y_x10280, kk_context_t* _ctx) { /* forall<a,b,e> (f : (a) -> b, a) -> <io|e> b */ 
  return kk_std_core_hnd__open_none1(f, _y_x10280, _ctx);
}

kk_function_t kk_nagare_core_interpreter_mapResult(kk_function_t s, kk_function_t f, kk_context_t* _ctx); /* forall<a,b,c,e> (s : sink<a,b,e>, f : (b) -> c) -> sink<a,c,e> */ 
 
// monadic lift

static inline kk_std_core_types__tuple2 kk_nagare_core_interpreter__mlift_zipSinks_10351(kk_box_t _y_x10281, kk_box_t _y_x10282, kk_context_t* _ctx) { /* forall<a,b,e> (a, b) -> <io|e> (a, b) */ 
  return kk_std_core_types__new_Tuple2(_y_x10281, _y_x10282, _ctx);
}

kk_std_core_types__tuple2 kk_nagare_core_interpreter__mlift_zipSinks_10352(kk_function_t right, kk_nagare_core_types__nstream source, kk_box_t _y_x10281, kk_context_t* _ctx); /* forall<a,b,c,e> (right : sink<a,c,e>, source : nagare/core/types/nstream<a,<io|e>>, b) -> <io|e> (b, c) */ 

kk_function_t kk_nagare_core_interpreter_zipSinks(kk_function_t left, kk_function_t right, kk_context_t* _ctx); /* forall<a,b,c,e> (left : sink<a,b,e>, right : sink<a,c,e>) -> sink<a,(b, c),e> */ 

void kk_nagare_core_interpreter__init(kk_context_t* _ctx);


void kk_nagare_core_interpreter__done(kk_context_t* _ctx);

#endif // header
