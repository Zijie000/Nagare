#pragma once
#ifndef kk_nagare_core_types_H
#define kk_nagare_core_types_H
// Koka generated module: nagare/core/types, koka version: 3.2.3, platform: 64-bit
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

// type declarations

// value type nagare/core/types/chunk
struct kk_nagare_core_types_Chunk {
  kk_std_core_types__list values;
};
typedef struct kk_nagare_core_types_Chunk kk_nagare_core_types__chunk;
static inline kk_nagare_core_types__chunk kk_nagare_core_types__new_Chunk(kk_std_core_types__list values, kk_context_t* _ctx) {
  kk_nagare_core_types__chunk _con = { values };
  return _con;
}
static inline bool kk_nagare_core_types__is_Chunk(kk_nagare_core_types__chunk x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_nagare_core_types__chunk kk_nagare_core_types__chunk_dup(kk_nagare_core_types__chunk _x, kk_context_t* _ctx) {
  kk_std_core_types__list_dup(_x.values, _ctx);
  return _x;
}
static inline void kk_nagare_core_types__chunk_drop(kk_nagare_core_types__chunk _x, kk_context_t* _ctx) {
  kk_std_core_types__list_drop(_x.values, _ctx);
}
static inline kk_box_t kk_nagare_core_types__chunk_box(kk_nagare_core_types__chunk _x, kk_context_t* _ctx) {
  return kk_std_core_types__list_box(_x.values, _ctx);
}
static inline kk_nagare_core_types__chunk kk_nagare_core_types__chunk_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_nagare_core_types__new_Chunk(kk_std_core_types__list_unbox(_x, _borrow, _ctx), _ctx);
}

// type nagare/core/types/pull
struct kk_nagare_core_types__pull_s {
  kk_block_t _block;
};
typedef kk_datatype_t kk_nagare_core_types__pull;
struct kk_nagare_core_types_POutput {
  struct kk_nagare_core_types__pull_s _base;
  kk_nagare_core_types__chunk out;
  kk_nagare_core_types__pull tail;
};
struct kk_nagare_core_types_PEval {
  struct kk_nagare_core_types__pull_s _base;
  kk_function_t next;
};
struct kk_nagare_core_types_PAcquire {
  struct kk_nagare_core_types__pull_s _base;
  kk_function_t acquire;
  kk_function_t release;
  kk_nagare_core_types__pull tail;
};
static inline kk_nagare_core_types__pull kk_nagare_core_types__new_PDone(kk_context_t* _ctx) {
  return kk_datatype_from_tag((kk_tag_t)(1));
}
static inline kk_nagare_core_types__pull kk_nagare_core_types__base_PEval(struct kk_nagare_core_types_PEval* _x, kk_context_t* _ctx) {
  return kk_datatype_from_base(&_x->_base, _ctx);
}
static inline kk_nagare_core_types__pull kk_nagare_core_types__new_PEval(kk_reuse_t _at, int32_t _cpath, kk_function_t next, kk_context_t* _ctx) {
  struct kk_nagare_core_types_PEval* _con = kk_block_alloc_at_as(struct kk_nagare_core_types_PEval, _at, 1 /* scan count */, _cpath, (kk_tag_t)(3), _ctx);
  _con->next = next;
  return kk_nagare_core_types__base_PEval(_con, _ctx);
}
static inline struct kk_nagare_core_types_PEval* kk_nagare_core_types__as_PEval(kk_nagare_core_types__pull x, kk_context_t* _ctx) {
  return kk_datatype_as_assert(struct kk_nagare_core_types_PEval*, x, (kk_tag_t)(3), _ctx);
}
static inline kk_nagare_core_types__pull kk_nagare_core_types__base_POutput(struct kk_nagare_core_types_POutput* _x, kk_context_t* _ctx) {
  return kk_datatype_from_base(&_x->_base, _ctx);
}
static inline kk_nagare_core_types__pull kk_nagare_core_types__new_POutput(kk_reuse_t _at, int32_t _cpath, kk_nagare_core_types__chunk out, kk_nagare_core_types__pull tail, kk_context_t* _ctx) {
  struct kk_nagare_core_types_POutput* _con = kk_block_alloc_at_as(struct kk_nagare_core_types_POutput, _at, 2 /* scan count */, _cpath, (kk_tag_t)(2), _ctx);
  _con->out = out;
  _con->tail = tail;
  return kk_nagare_core_types__base_POutput(_con, _ctx);
}
static inline struct kk_nagare_core_types_POutput* kk_nagare_core_types__as_POutput(kk_nagare_core_types__pull x, kk_context_t* _ctx) {
  return kk_datatype_as_assert(struct kk_nagare_core_types_POutput*, x, (kk_tag_t)(2), _ctx);
}
static inline kk_nagare_core_types__pull kk_nagare_core_types__base_PAcquire(struct kk_nagare_core_types_PAcquire* _x, kk_context_t* _ctx) {
  return kk_datatype_from_base(&_x->_base, _ctx);
}
static inline kk_nagare_core_types__pull kk_nagare_core_types__new_PAcquire(kk_reuse_t _at, int32_t _cpath, kk_function_t acquire, kk_function_t release, kk_nagare_core_types__pull tail, kk_context_t* _ctx) {
  struct kk_nagare_core_types_PAcquire* _con = kk_block_alloc_at_as(struct kk_nagare_core_types_PAcquire, _at, 3 /* scan count */, _cpath, (kk_tag_t)(4), _ctx);
  _con->acquire = acquire;
  _con->release = release;
  _con->tail = tail;
  return kk_nagare_core_types__base_PAcquire(_con, _ctx);
}
static inline struct kk_nagare_core_types_PAcquire* kk_nagare_core_types__as_PAcquire(kk_nagare_core_types__pull x, kk_context_t* _ctx) {
  return kk_datatype_as_assert(struct kk_nagare_core_types_PAcquire*, x, (kk_tag_t)(4), _ctx);
}
static inline bool kk_nagare_core_types__is_PDone(kk_nagare_core_types__pull x, kk_context_t* _ctx) {
  return (kk_datatype_has_singleton_tag(x, (kk_tag_t)(1)));
}
static inline bool kk_nagare_core_types__is_PEval(kk_nagare_core_types__pull x, kk_context_t* _ctx) {
  return (kk_datatype_has_ptr_tag(x, (kk_tag_t)(3), _ctx));
}
static inline bool kk_nagare_core_types__is_POutput(kk_nagare_core_types__pull x, kk_context_t* _ctx) {
  return (kk_datatype_has_ptr_tag(x, (kk_tag_t)(2), _ctx));
}
static inline bool kk_nagare_core_types__is_PAcquire(kk_nagare_core_types__pull x, kk_context_t* _ctx) {
  return (kk_datatype_has_ptr_tag(x, (kk_tag_t)(4), _ctx));
}
static inline kk_nagare_core_types__pull kk_nagare_core_types__pull_dup(kk_nagare_core_types__pull _x, kk_context_t* _ctx) {
  return kk_datatype_dup(_x, _ctx);
}
static inline void kk_nagare_core_types__pull_drop(kk_nagare_core_types__pull _x, kk_context_t* _ctx) {
  kk_datatype_drop(_x, _ctx);
}
static inline kk_box_t kk_nagare_core_types__pull_box(kk_nagare_core_types__pull _x, kk_context_t* _ctx) {
  return kk_datatype_box(_x);
}
static inline kk_nagare_core_types__pull kk_nagare_core_types__pull_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_datatype_unbox(_x);
}

// value type nagare/core/types/nstream
struct kk_nagare_core_types_Stream {
  kk_nagare_core_types__pull step;
};
typedef struct kk_nagare_core_types_Stream kk_nagare_core_types__nstream;
static inline kk_nagare_core_types__nstream kk_nagare_core_types__new_Stream(kk_nagare_core_types__pull step, kk_context_t* _ctx) {
  kk_nagare_core_types__nstream _con = { step };
  return _con;
}
static inline bool kk_nagare_core_types__is_Stream(kk_nagare_core_types__nstream x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_nagare_core_types__nstream kk_nagare_core_types__nstream_dup(kk_nagare_core_types__nstream _x, kk_context_t* _ctx) {
  kk_nagare_core_types__pull_dup(_x.step, _ctx);
  return _x;
}
static inline void kk_nagare_core_types__nstream_drop(kk_nagare_core_types__nstream _x, kk_context_t* _ctx) {
  kk_nagare_core_types__pull_drop(_x.step, _ctx);
}
static inline kk_box_t kk_nagare_core_types__nstream_box(kk_nagare_core_types__nstream _x, kk_context_t* _ctx) {
  return kk_nagare_core_types__pull_box(_x.step, _ctx);
}
static inline kk_nagare_core_types__nstream kk_nagare_core_types__nstream_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_nagare_core_types__new_Stream(kk_nagare_core_types__pull_unbox(_x, _borrow, _ctx), _ctx);
}

// value declarations
 
// Automatically generated. Retrieves the `values` constructor field of the `:chunk` type.

static inline kk_std_core_types__list kk_nagare_core_types_chunk_fs_values(kk_nagare_core_types__chunk chunk, kk_context_t* _ctx) { /* forall<a> (chunk : chunk<a>) -> list<a> */ 
  {
    kk_std_core_types__list _x = chunk.values;
    return kk_std_core_types__list_dup(_x, _ctx);
  }
}

kk_nagare_core_types__chunk kk_nagare_core_types_chunk_fs__copy(kk_nagare_core_types__chunk _this, kk_std_core_types__optional values, kk_context_t* _ctx); /* forall<a> (chunk<a>, values : ? (list<a>)) -> chunk<a> */ 
 
// Automatically generated. Tests for the `PDone` constructor of the `:pull` type.

static inline bool kk_nagare_core_types_is_pdone(kk_nagare_core_types__pull pull, kk_context_t* _ctx) { /* forall<a,e> (pull : pull<a,e>) -> bool */ 
  if (kk_nagare_core_types__is_PDone(pull, _ctx)) {
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `POutput` constructor of the `:pull` type.

static inline bool kk_nagare_core_types_is_poutput(kk_nagare_core_types__pull pull, kk_context_t* _ctx) { /* forall<a,e> (pull : pull<a,e>) -> bool */ 
  if (kk_nagare_core_types__is_POutput(pull, _ctx)) {
    struct kk_nagare_core_types_POutput* _con_x3 = kk_nagare_core_types__as_POutput(pull, _ctx);
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `PEval` constructor of the `:pull` type.

static inline bool kk_nagare_core_types_is_peval(kk_nagare_core_types__pull pull, kk_context_t* _ctx) { /* forall<a,e> (pull : pull<a,e>) -> bool */ 
  if (kk_nagare_core_types__is_PEval(pull, _ctx)) {
    struct kk_nagare_core_types_PEval* _con_x4 = kk_nagare_core_types__as_PEval(pull, _ctx);
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Tests for the `PAcquire` constructor of the `:pull` type.

static inline bool kk_nagare_core_types_is_pacquire(kk_nagare_core_types__pull pull, kk_context_t* _ctx) { /* forall<a,e> (pull : pull<a,e>) -> bool */ 
  if (kk_nagare_core_types__is_PAcquire(pull, _ctx)) {
    struct kk_nagare_core_types_PAcquire* _con_x5 = kk_nagare_core_types__as_PAcquire(pull, _ctx);
    return true;
  }
  {
    return false;
  }
}
 
// Automatically generated. Retrieves the `step` constructor field of the `:nstream` type.

static inline kk_nagare_core_types__pull kk_nagare_core_types_nstream_fs_step(kk_nagare_core_types__nstream nstream, kk_context_t* _ctx) { /* forall<a,e> (nstream : nstream<a,e>) -> pull<a,e> */ 
  {
    kk_nagare_core_types__pull _x = nstream.step;
    return kk_nagare_core_types__pull_dup(_x, _ctx);
  }
}

kk_nagare_core_types__nstream kk_nagare_core_types_nstream_fs__copy(kk_nagare_core_types__nstream _this, kk_std_core_types__optional step, kk_context_t* _ctx); /* forall<a,e> (nstream<a,e>, step : ? (pull<a,e>)) -> nstream<a,e> */ 
 
// Unwrap a stream into its underlying pull program.

static inline kk_nagare_core_types__pull kk_nagare_core_types_toPull(kk_nagare_core_types__nstream source, kk_context_t* _ctx) { /* forall<a,e> (source : nstream<a,e>) -> pull<a,e> */ 
  {
    kk_nagare_core_types__pull step = source.step;
    return step;
  }
}
 
// Wrap a pull program back into a user-facing stream.

static inline kk_nagare_core_types__nstream kk_nagare_core_types_fromPull(kk_nagare_core_types__pull step, kk_context_t* _ctx) { /* forall<a,e> (step : pull<a,e>) -> nstream<a,e> */ 
  return kk_nagare_core_types__new_Stream(step, _ctx);
}

void kk_nagare_core_types__init(kk_context_t* _ctx);


void kk_nagare_core_types__done(kk_context_t* _ctx);

#endif // header
