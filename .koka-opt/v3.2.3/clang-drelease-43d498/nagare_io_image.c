// Koka generated module: nagare/io/image, koka version: 3.2.3, platform: 64-bit
#include "nagare_io_image.h"
 
// lifted local: @lift-unroll-collectBytesPull@10000@10122, @unroll-collectBytesPull@10000, @spec-x10119
// specialized: std/core/list/@unroll-foldl@10005, on parameters @uniq-f@10114, using:
// @uniq-f@10114 = fn<<(nagare/io/image_effect/imageDecode :: (E, V) -> V)|(e :: E)>>(b: nagare/io/file/bytes, c: nagare/io/file/bytes){
//   std/core/types/@open<(total :: E),<(nagare/io/image_effect/imageDecode :: (E, V) -> V)|(e :: E)>,(a : nagare/io/file/bytes, b : nagare/io/file/bytes) -> nagare/io/file/bytes,(a : nagare/io/file/bytes, b : nagare/io/file/bytes) -> <(nagare/io/image_effect/imageDecode :: (E, V) -> V)|(e :: E)> nagare/io/file/bytes>(nagare/io/image/concatBytes)(b, c);
// }


// lift anonymous function
struct kk_nagare_io_image__lift_unroll_collectBytesPull_10000_10123_fun238__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_io_image__lift_unroll_collectBytesPull_10000_10123_fun238(kk_function_t _fself, kk_box_t _b_x4, kk_box_t _b_x5, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_image__new_lift_unroll_collectBytesPull_10000_10123_fun238(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_image__lift_unroll_collectBytesPull_10000_10123_fun238, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_io_image__lift_unroll_collectBytesPull_10000_10123_fun238(kk_function_t _fself, kk_box_t _b_x4, kk_box_t _b_x5, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_vector_t _x_x239;
  kk_vector_t _x_x240 = kk_vector_unbox(_b_x4, _ctx); /*nagare/io/file/bytes*/
  kk_vector_t _x_x241 = kk_vector_unbox(_b_x5, _ctx); /*nagare/io/file/bytes*/
  _x_x239 = kk_nagare_io_image_concatBytes(_x_x240, _x_x241, _ctx); /*nagare/io/file/bytes*/
  return kk_vector_box(_x_x239, _ctx);
}

kk_vector_t kk_nagare_io_image__lift_unroll_collectBytesPull_10000_10123(kk_std_core_types__list _uniq_xs_10112, kk_vector_t _uniq_z_10113, kk_context_t* _ctx) { /* forall<e> (list<nagare/io/file/bytes>, nagare/io/file/bytes) -> <nagare/io/image_effect/imageDecode|e> nagare/io/file/bytes */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_xs_10112, _ctx)) {
    struct kk_std_core_types_Cons* _con_x236 = kk_std_core_types__as_Cons(_uniq_xs_10112, _ctx);
    kk_box_t _box_x0 = _con_x236->head;
    kk_std_core_types__list _uniq_xx_10117 = _con_x236->tail;
    kk_vector_t _uniq_x_10116 = kk_vector_unbox(_box_x0, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10112, _ctx)) {
      kk_datatype_ptr_free(_uniq_xs_10112, _ctx);
    }
    else {
      kk_vector_dup(_uniq_x_10116, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10117, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10112, _ctx);
    }
    kk_vector_t _uniq_z_10113_0_10125;
    kk_box_t _x_x237 = kk_std_core_hnd__open_none2(kk_nagare_io_image__new_lift_unroll_collectBytesPull_10000_10123_fun238(_ctx), kk_vector_box(_uniq_z_10113, _ctx), kk_vector_box(_uniq_x_10116, _ctx), _ctx); /*10002*/
    _uniq_z_10113_0_10125 = kk_vector_unbox(_x_x237, _ctx); /*nagare/io/file/bytes*/
    { // tailcall
      _uniq_xs_10112 = _uniq_xx_10117;
      _uniq_z_10113 = _uniq_z_10113_0_10125;
      goto kk__tailcall;
    }
  }
  {
    return _uniq_z_10113;
  }
}
 
// lifted local: @unroll-collectBytesPull@10000, @spec-x10111
// specialized: std/core/list/foldl, on parameters @uniq-f@10108, using:
// @uniq-f@10108 = fn<<(nagare/io/image_effect/imageDecode :: (E, V) -> V)|(e :: E)>>(b: nagare/io/file/bytes, c: nagare/io/file/bytes){
//   std/core/types/@open<(total :: E),<(nagare/io/image_effect/imageDecode :: (E, V) -> V)|(e :: E)>,(a : nagare/io/file/bytes, b : nagare/io/file/bytes) -> nagare/io/file/bytes,(a : nagare/io/file/bytes, b : nagare/io/file/bytes) -> <(nagare/io/image_effect/imageDecode :: (E, V) -> V)|(e :: E)> nagare/io/file/bytes>(nagare/io/image/concatBytes)(b, c);
// }

kk_vector_t kk_nagare_io_image__lift_unroll_collectBytesPull_10000_10122(kk_std_core_types__list _uniq_xs_10106, kk_vector_t _uniq_z_10107, kk_context_t* _ctx) { /* forall<e> (list<nagare/io/file/bytes>, nagare/io/file/bytes) -> <nagare/io/image_effect/imageDecode|e> nagare/io/file/bytes */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10106, _ctx)) {
    return _uniq_z_10107;
  }
  {
    return kk_nagare_io_image__lift_unroll_collectBytesPull_10000_10123(_uniq_xs_10106, _uniq_z_10107, _ctx);
  }
}
 
// monadic lift

kk_vector_t kk_nagare_io_image__mlift_unroll_collectBytesPull_10000_10182(kk_nagare_core_types__pull tail, kk_vector_t next, kk_context_t* _ctx) { /* forall<e> (tail : nagare/core/types/pull<nagare/io/file/bytes,<nagare/io/image_effect/imageDecode|e>>, next : nagare/io/file/bytes) -> <nagare/io/image_effect/imageDecode|e> nagare/io/file/bytes */ 
  return kk_nagare_io_image__unroll_collectBytesPull_10000(tail, next, _ctx);
}
 
// monadic lift

kk_vector_t kk_nagare_io_image__mlift_unroll_collectBytesPull_10000_10183(kk_vector_t acc, kk_nagare_core_types__pull _y_x10135, kk_context_t* _ctx) { /* forall<e> (acc : nagare/io/file/bytes, nagare/core/types/pull<nagare/io/file/bytes,<nagare/io/image_effect/imageDecode|e>>) -> <nagare/io/image_effect/imageDecode|e> nagare/io/file/bytes */ 
  return kk_nagare_io_image__unroll_collectBytesPull_10000(_y_x10135, acc, _ctx);
}
 
// monadic lift

kk_vector_t kk_nagare_io_image__mlift_unroll_collectBytesPull_10000_10184(kk_vector_t acc_0, kk_function_t release, kk_nagare_core_types__pull tail_0, kk_unit_t wild__, kk_context_t* _ctx) { /* forall<e> (acc : nagare/io/file/bytes, release : () -> <nagare/io/image_effect/imageDecode|e> (), tail@0 : nagare/core/types/pull<nagare/io/file/bytes,<nagare/io/image_effect/imageDecode|e>>, wild_ : ()) -> <nagare/io/image_effect/imageDecode|e> nagare/io/file/bytes */ 
  kk_vector_t _b_x10_12 = kk_nagare_io_image__unroll_collectBytesPull_10000(tail_0, acc_0, _ctx); /*nagare/io/file/bytes*/;
  kk_box_t _x_x242 = kk_std_core_hnd_finally_prompt(release, kk_vector_box(_b_x10_12, _ctx), _ctx); /*10000*/
  return kk_vector_unbox(_x_x242, _ctx);
}
 
// Drain an upstream byte pull into a single bytes buffer.


// lift anonymous function
struct kk_nagare_io_image__unroll_collectBytesPull_10000_fun245__t {
  struct kk_function_s _base;
  kk_nagare_core_types__pull tail_1;
};
static kk_box_t kk_nagare_io_image__unroll_collectBytesPull_10000_fun245(kk_function_t _fself, kk_box_t _b_x14, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_image__new_unroll_collectBytesPull_10000_fun245(kk_nagare_core_types__pull tail_1, kk_context_t* _ctx) {
  struct kk_nagare_io_image__unroll_collectBytesPull_10000_fun245__t* _self = kk_function_alloc_as(struct kk_nagare_io_image__unroll_collectBytesPull_10000_fun245__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_image__unroll_collectBytesPull_10000_fun245, kk_context());
  _self->tail_1 = tail_1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_image__unroll_collectBytesPull_10000_fun245(kk_function_t _fself, kk_box_t _b_x14, kk_context_t* _ctx) {
  struct kk_nagare_io_image__unroll_collectBytesPull_10000_fun245__t* _self = kk_function_as(struct kk_nagare_io_image__unroll_collectBytesPull_10000_fun245__t*, _fself, _ctx);
  kk_nagare_core_types__pull tail_1 = _self->tail_1; /* nagare/core/types/pull<nagare/io/file/bytes,<nagare/io/image_effect/imageDecode|184>> */
  kk_drop_match(_self, {kk_nagare_core_types__pull_dup(tail_1, _ctx);}, {}, _ctx)
  kk_vector_t next_1_26 = kk_vector_unbox(_b_x14, _ctx); /*nagare/io/file/bytes*/;
  kk_vector_t _x_x246 = kk_nagare_io_image__mlift_unroll_collectBytesPull_10000_10182(tail_1, next_1_26, _ctx); /*nagare/io/file/bytes*/
  return kk_vector_box(_x_x246, _ctx);
}


// lift anonymous function
struct kk_nagare_io_image__unroll_collectBytesPull_10000_fun249__t {
  struct kk_function_s _base;
  kk_vector_t acc_1;
};
static kk_box_t kk_nagare_io_image__unroll_collectBytesPull_10000_fun249(kk_function_t _fself, kk_box_t _b_x16, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_image__new_unroll_collectBytesPull_10000_fun249(kk_vector_t acc_1, kk_context_t* _ctx) {
  struct kk_nagare_io_image__unroll_collectBytesPull_10000_fun249__t* _self = kk_function_alloc_as(struct kk_nagare_io_image__unroll_collectBytesPull_10000_fun249__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_image__unroll_collectBytesPull_10000_fun249, kk_context());
  _self->acc_1 = acc_1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_image__unroll_collectBytesPull_10000_fun249(kk_function_t _fself, kk_box_t _b_x16, kk_context_t* _ctx) {
  struct kk_nagare_io_image__unroll_collectBytesPull_10000_fun249__t* _self = kk_function_as(struct kk_nagare_io_image__unroll_collectBytesPull_10000_fun249__t*, _fself, _ctx);
  kk_vector_t acc_1 = _self->acc_1; /* nagare/io/file/bytes */
  kk_drop_match(_self, {kk_vector_dup(acc_1, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull _y_x10135_0_27 = kk_nagare_core_types__pull_unbox(_b_x16, KK_OWNED, _ctx); /*nagare/core/types/pull<nagare/io/file/bytes,<nagare/io/image_effect/imageDecode|184>>*/;
  kk_vector_t _x_x250 = kk_nagare_io_image__mlift_unroll_collectBytesPull_10000_10183(acc_1, _y_x10135_0_27, _ctx); /*nagare/io/file/bytes*/
  return kk_vector_box(_x_x250, _ctx);
}


// lift anonymous function
struct kk_nagare_io_image__unroll_collectBytesPull_10000_fun253__t {
  struct kk_function_s _base;
  kk_vector_t acc_1;
  kk_function_t release_0;
  kk_nagare_core_types__pull tail_0_0;
};
static kk_box_t kk_nagare_io_image__unroll_collectBytesPull_10000_fun253(kk_function_t _fself, kk_box_t _b_x18, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_image__new_unroll_collectBytesPull_10000_fun253(kk_vector_t acc_1, kk_function_t release_0, kk_nagare_core_types__pull tail_0_0, kk_context_t* _ctx) {
  struct kk_nagare_io_image__unroll_collectBytesPull_10000_fun253__t* _self = kk_function_alloc_as(struct kk_nagare_io_image__unroll_collectBytesPull_10000_fun253__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_image__unroll_collectBytesPull_10000_fun253, kk_context());
  _self->acc_1 = acc_1;
  _self->release_0 = release_0;
  _self->tail_0_0 = tail_0_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_image__unroll_collectBytesPull_10000_fun253(kk_function_t _fself, kk_box_t _b_x18, kk_context_t* _ctx) {
  struct kk_nagare_io_image__unroll_collectBytesPull_10000_fun253__t* _self = kk_function_as(struct kk_nagare_io_image__unroll_collectBytesPull_10000_fun253__t*, _fself, _ctx);
  kk_vector_t acc_1 = _self->acc_1; /* nagare/io/file/bytes */
  kk_function_t release_0 = _self->release_0; /* () -> <nagare/io/image_effect/imageDecode|184> () */
  kk_nagare_core_types__pull tail_0_0 = _self->tail_0_0; /* nagare/core/types/pull<nagare/io/file/bytes,<nagare/io/image_effect/imageDecode|184>> */
  kk_drop_match(_self, {kk_vector_dup(acc_1, _ctx);kk_function_dup(release_0, _ctx);kk_nagare_core_types__pull_dup(tail_0_0, _ctx);}, {}, _ctx)
  kk_unit_t wild___0_28 = kk_Unit;
  kk_unit_unbox(_b_x18);
  kk_vector_t _x_x254 = kk_nagare_io_image__mlift_unroll_collectBytesPull_10000_10184(acc_1, release_0, tail_0_0, wild___0_28, _ctx); /*nagare/io/file/bytes*/
  return kk_vector_box(_x_x254, _ctx);
}

kk_vector_t kk_nagare_io_image__unroll_collectBytesPull_10000(kk_nagare_core_types__pull source, kk_vector_t acc_1, kk_context_t* _ctx) { /* forall<e> (source : nagare/core/types/pull<nagare/io/file/bytes,<nagare/io/image_effect/imageDecode|e>>, acc : nagare/io/file/bytes) -> <nagare/io/image_effect/imageDecode|e> nagare/io/file/bytes */ 
  kk__tailcall: ;
  if (kk_nagare_core_types__is_PDone(source, _ctx)) {
    return acc_1;
  }
  if (kk_nagare_core_types__is_POutput(source, _ctx)) {
    struct kk_nagare_core_types_POutput* _con_x243 = kk_nagare_core_types__as_POutput(source, _ctx);
    kk_nagare_core_types__chunk out = _con_x243->out;
    kk_nagare_core_types__pull tail_1 = _con_x243->tail;
    if kk_likely(kk_datatype_ptr_is_unique(source, _ctx)) {
      kk_datatype_ptr_free(source, _ctx);
    }
    else {
      kk_nagare_core_types__chunk_dup(out, _ctx);
      kk_nagare_core_types__pull_dup(tail_1, _ctx);
      kk_datatype_ptr_decref(source, _ctx);
    }
    {
      kk_std_core_types__list values = out.values;
      kk_vector_t x_10191 = kk_nagare_io_image__lift_unroll_collectBytesPull_10000_10122(values, acc_1, _ctx); /*nagare/io/file/bytes*/;
      if (kk_yielding(kk_context())) {
        kk_vector_drop(x_10191, _ctx);
        kk_box_t _x_x244 = kk_std_core_hnd_yield_extend(kk_nagare_io_image__new_unroll_collectBytesPull_10000_fun245(tail_1, _ctx), _ctx); /*10001*/
        return kk_vector_unbox(_x_x244, _ctx);
      }
      { // tailcall
        source = tail_1;
        acc_1 = x_10191;
        goto kk__tailcall;
      }
    }
  }
  if (kk_nagare_core_types__is_PEval(source, _ctx)) {
    struct kk_nagare_core_types_PEval* _con_x247 = kk_nagare_core_types__as_PEval(source, _ctx);
    kk_function_t next_0_0 = _con_x247->next;
    if kk_likely(kk_datatype_ptr_is_unique(source, _ctx)) {
      kk_datatype_ptr_free(source, _ctx);
    }
    else {
      kk_function_dup(next_0_0, _ctx);
      kk_datatype_ptr_decref(source, _ctx);
    }
    kk_nagare_core_types__pull x_0_10194 = kk_function_call(kk_nagare_core_types__pull, (kk_function_t, kk_context_t*), next_0_0, (next_0_0, _ctx), _ctx); /*nagare/core/types/pull<nagare/io/file/bytes,<nagare/io/image_effect/imageDecode|184>>*/;
    if (kk_yielding(kk_context())) {
      kk_nagare_core_types__pull_drop(x_0_10194, _ctx);
      kk_box_t _x_x248 = kk_std_core_hnd_yield_extend(kk_nagare_io_image__new_unroll_collectBytesPull_10000_fun249(acc_1, _ctx), _ctx); /*10001*/
      return kk_vector_unbox(_x_x248, _ctx);
    }
    { // tailcall
      source = x_0_10194;
      goto kk__tailcall;
    }
  }
  {
    struct kk_nagare_core_types_PAcquire* _con_x251 = kk_nagare_core_types__as_PAcquire(source, _ctx);
    kk_function_t acquire = _con_x251->acquire;
    kk_function_t release_0 = _con_x251->release;
    kk_nagare_core_types__pull tail_0_0 = _con_x251->tail;
    if kk_likely(kk_datatype_ptr_is_unique(source, _ctx)) {
      kk_datatype_ptr_free(source, _ctx);
    }
    else {
      kk_function_dup(acquire, _ctx);
      kk_function_dup(release_0, _ctx);
      kk_nagare_core_types__pull_dup(tail_0_0, _ctx);
      kk_datatype_ptr_decref(source, _ctx);
    }
    kk_unit_t x_1_10197 = kk_Unit;
    kk_function_call(kk_unit_t, (kk_function_t, kk_context_t*), acquire, (acquire, _ctx), _ctx);
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x252 = kk_std_core_hnd_yield_extend(kk_nagare_io_image__new_unroll_collectBytesPull_10000_fun253(acc_1, release_0, tail_0_0, _ctx), _ctx); /*10001*/
      return kk_vector_unbox(_x_x252, _ctx);
    }
    {
      kk_vector_t _b_x20_25 = kk_nagare_io_image__unroll_collectBytesPull_10000(tail_0_0, acc_1, _ctx); /*nagare/io/file/bytes*/;
      kk_box_t _x_x255 = kk_std_core_hnd_finally_prompt(release_0, kk_vector_box(_b_x20_25, _ctx), _ctx); /*10000*/
      return kk_vector_unbox(_x_x255, _ctx);
    }
  }
}
 
// monadic lift


// lift anonymous function
struct kk_nagare_io_image__mlift_decodeImageAll_10186_fun263__t {
  struct kk_function_s _base;
  kk_ssize_t i_10204;
};
static kk_box_t kk_nagare_io_image__mlift_decodeImageAll_10186_fun263(kk_function_t _fself, kk_function_t _b_x46, kk_box_t _b_x47, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_image__new_mlift_decodeImageAll_10186_fun263(kk_ssize_t i_10204, kk_context_t* _ctx) {
  struct kk_nagare_io_image__mlift_decodeImageAll_10186_fun263__t* _self = kk_function_alloc_as(struct kk_nagare_io_image__mlift_decodeImageAll_10186_fun263__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_image__mlift_decodeImageAll_10186_fun263, kk_context());
  _self->i_10204 = i_10204;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_image__mlift_decodeImageAll_10186_fun263(kk_function_t _fself, kk_function_t _b_x46, kk_box_t _b_x47, kk_context_t* _ctx) {
  struct kk_nagare_io_image__mlift_decodeImageAll_10186_fun263__t* _self = kk_function_as(struct kk_nagare_io_image__mlift_decodeImageAll_10186_fun263__t*, _fself, _ctx);
  kk_ssize_t i_10204 = _self->i_10204; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_10204, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_10204, _b_x46, _b_x47, _ctx);
}


// lift anonymous function
struct kk_nagare_io_image__mlift_decodeImageAll_10186_fun264__t {
  struct kk_function_s _base;
};
static kk_nagare_core_types__pull kk_nagare_io_image__mlift_decodeImageAll_10186_fun264(kk_function_t _fself, kk_nagare_io_image__effect__image img, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_image__new_mlift_decodeImageAll_10186_fun264(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_image__mlift_decodeImageAll_10186_fun264, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_nagare_core_types__pull kk_nagare_io_image__mlift_decodeImageAll_10186_fun264(kk_function_t _fself, kk_nagare_io_image__effect__image img, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_nagare_core_types__chunk _x_x265;
  kk_std_core_types__list _x_x266 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_nagare_io_image__effect__image_box(img, _ctx), kk_std_core_types__new_Nil(_ctx), _ctx); /*list<10021>*/
  _x_x265 = kk_nagare_core_types__new_Chunk(_x_x266, _ctx); /*nagare/core/types/chunk<4>*/
  return kk_nagare_core_types__new_POutput(kk_reuse_null, 0, _x_x265, kk_nagare_core_types__new_PDone(_ctx), _ctx);
}


// lift anonymous function
struct kk_nagare_io_image__mlift_decodeImageAll_10186_fun268__t {
  struct kk_function_s _base;
  kk_function_t next_10203;
};
static kk_box_t kk_nagare_io_image__mlift_decodeImageAll_10186_fun268(kk_function_t _fself, kk_box_t _b_x60, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_image__new_mlift_decodeImageAll_10186_fun268(kk_function_t next_10203, kk_context_t* _ctx) {
  struct kk_nagare_io_image__mlift_decodeImageAll_10186_fun268__t* _self = kk_function_alloc_as(struct kk_nagare_io_image__mlift_decodeImageAll_10186_fun268__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_image__mlift_decodeImageAll_10186_fun268, kk_context());
  _self->next_10203 = next_10203;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_image__mlift_decodeImageAll_10186_fun268(kk_function_t _fself, kk_box_t _b_x60, kk_context_t* _ctx) {
  struct kk_nagare_io_image__mlift_decodeImageAll_10186_fun268__t* _self = kk_function_as(struct kk_nagare_io_image__mlift_decodeImageAll_10186_fun268__t*, _fself, _ctx);
  kk_function_t next_10203 = _self->next_10203; /* (nagare/io/image_effect/image) -> <nagare/io/image_effect/imageDecode|426> nagare/core/types/pull<nagare/io/image_effect/image,<nagare/io/image_effect/imageDecode|426>> */
  kk_drop_match(_self, {kk_function_dup(next_10203, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull _x_x269;
  kk_nagare_io_image__effect__image _x_x270 = kk_nagare_io_image__effect__image_unbox(_b_x60, KK_OWNED, _ctx); /*nagare/io/image_effect/image*/
  _x_x269 = kk_function_call(kk_nagare_core_types__pull, (kk_function_t, kk_nagare_io_image__effect__image, kk_context_t*), next_10203, (next_10203, _x_x270, _ctx), _ctx); /*nagare/core/types/pull<nagare/io/image_effect/image,<nagare/io/image_effect/imageDecode|426>>*/
  return kk_nagare_core_types__pull_box(_x_x269, _ctx);
}

kk_nagare_core_types__pull kk_nagare_io_image__mlift_decodeImageAll_10186(kk_vector_t _c_x10144, kk_context_t* _ctx) { /* forall<e> (nagare/io/file/bytes) -> nagare/core/types/pull<nagare/io/image_effect/image,<nagare/io/image_effect/imageDecode|e>> */ 
  bool _match_x218;
  kk_integer_t _brw_x223;
  kk_ssize_t _x_x258 = kk_vector_len_borrow(_c_x10144,kk_context()); /*ssize_t*/
  _brw_x223 = kk_integer_from_ssize_t(_x_x258,kk_context()); /*int*/
  bool _brw_x224 = kk_integer_eq_borrow(_brw_x223,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x223, _ctx);
  _match_x218 = _brw_x224; /*bool*/
  if (_match_x218) {
    kk_vector_drop(_c_x10144, _ctx);
    return kk_nagare_core_types__new_PDone(_ctx);
  }
  {
    kk_ssize_t i_10204;
    kk_std_core_hnd__htag _x_x259 = kk_std_core_hnd__htag_dup(kk_nagare_io_image__effect_imageDecode_fs__tag, _ctx); /*hnd/htag<nagare/io/image_effect/imageDecode>*/
    i_10204 = kk_std_core_hnd__evv_index(_x_x259, _ctx); /*hnd/ev-index*/
    kk_evv_t w = kk_evv_swap_create1(i_10204,kk_context()); /*hnd/evv<<nagare/io/image_effect/imageDecode|426>>*/;
    kk_std_core_hnd__ev ev_10207 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<nagare/io/image_effect/imageDecode>*/;
    kk_nagare_io_image__effect__image y;
    kk_box_t _x_x260;
    {
      struct kk_std_core_hnd_Ev* _con_x261 = kk_std_core_hnd__as_Ev(ev_10207, _ctx);
      kk_box_t _box_x33 = _con_x261->hnd;
      int32_t m = _con_x261->marker;
      kk_nagare_io_image__effect__imageDecode h = kk_nagare_io_image__effect__imageDecode_unbox(_box_x33, KK_BORROWED, _ctx);
      kk_nagare_io_image__effect__imageDecode_dup(h, _ctx);
      kk_std_core_hnd__clause1 _match_x221;
      kk_std_core_hnd__clause1 _brw_x222 = kk_nagare_io_image__effect_decodeImageBytes_fs__select(h, _ctx); /*hnd/clause1<vector<int8>,nagare/io/image_effect/image,nagare/io/image_effect/imageDecode,465,466>*/;
      kk_datatype_ptr_dropn(h, (KK_I32(2)), _ctx);
      _match_x221 = _brw_x222; /*hnd/clause1<vector<int8>,nagare/io/image_effect/image,nagare/io/image_effect/imageDecode,465,466>*/
      {
        kk_function_t _fun_unbox_x37 = _match_x221.clause;
        _x_x260 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x37, (_fun_unbox_x37, m, ev_10207, kk_vector_box(_c_x10144, _ctx), _ctx), _ctx); /*10010*/
      }
    }
    y = kk_nagare_io_image__effect__image_unbox(_x_x260, KK_OWNED, _ctx); /*nagare/io/image_effect/image*/
    kk_evv_set(w,kk_context());
    kk_nagare_io_image__effect__image x_10202;
    if (kk_yielding(kk_context())) {
      kk_nagare_io_image__effect__image_drop(y, _ctx);
      kk_box_t _x_x262 = kk_std_core_hnd_yield_cont(kk_nagare_io_image__new_mlift_decodeImageAll_10186_fun263(i_10204, _ctx), _ctx); /*10002*/
      x_10202 = kk_nagare_io_image__effect__image_unbox(_x_x262, KK_OWNED, _ctx); /*nagare/io/image_effect/image*/
    }
    else {
      x_10202 = y; /*nagare/io/image_effect/image*/
    }
    kk_function_t next_10203 = kk_nagare_io_image__new_mlift_decodeImageAll_10186_fun264(_ctx); /*(nagare/io/image_effect/image) -> <nagare/io/image_effect/imageDecode|426> nagare/core/types/pull<nagare/io/image_effect/image,<nagare/io/image_effect/imageDecode|426>>*/;
    if (kk_yielding(kk_context())) {
      kk_nagare_io_image__effect__image_drop(x_10202, _ctx);
      kk_box_t _x_x267 = kk_std_core_hnd_yield_extend(kk_nagare_io_image__new_mlift_decodeImageAll_10186_fun268(next_10203, _ctx), _ctx); /*10001*/
      return kk_nagare_core_types__pull_unbox(_x_x267, KK_OWNED, _ctx);
    }
    {
      return kk_function_call(kk_nagare_core_types__pull, (kk_function_t, kk_nagare_io_image__effect__image, kk_context_t*), next_10203, (next_10203, x_10202, _ctx), _ctx);
    }
  }
}


// lift anonymous function
struct kk_nagare_io_image_decodeImageAll_fun272__t {
  struct kk_function_s _base;
  kk_nagare_core_types__pull step;
};
static kk_nagare_core_types__pull kk_nagare_io_image_decodeImageAll_fun272(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_image_new_decodeImageAll_fun272(kk_nagare_core_types__pull step, kk_context_t* _ctx) {
  struct kk_nagare_io_image_decodeImageAll_fun272__t* _self = kk_function_alloc_as(struct kk_nagare_io_image_decodeImageAll_fun272__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_image_decodeImageAll_fun272, kk_context());
  _self->step = step;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_io_image_decodeImageAll_fun274__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_io_image_decodeImageAll_fun274(kk_function_t _fself, kk_box_t _b_x68, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_image_new_decodeImageAll_fun274(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_image_decodeImageAll_fun274, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_io_image_decodeImageAll_fun274(kk_function_t _fself, kk_box_t _b_x68, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_vector_t _c_x10144_70 = kk_vector_unbox(_b_x68, _ctx); /*nagare/io/file/bytes*/;
  kk_nagare_core_types__pull _x_x275 = kk_nagare_io_image__mlift_decodeImageAll_10186(_c_x10144_70, _ctx); /*nagare/core/types/pull<nagare/io/image_effect/image,<nagare/io/image_effect/imageDecode|426>>*/
  return kk_nagare_core_types__pull_box(_x_x275, _ctx);
}
static kk_nagare_core_types__pull kk_nagare_io_image_decodeImageAll_fun272(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_io_image_decodeImageAll_fun272__t* _self = kk_function_as(struct kk_nagare_io_image_decodeImageAll_fun272__t*, _fself, _ctx);
  kk_nagare_core_types__pull step = _self->step; /* nagare/core/types/pull<nagare/io/file/bytes,<nagare/io/image_effect/imageDecode|426>> */
  kk_drop_match(_self, {kk_nagare_core_types__pull_dup(step, _ctx);}, {}, _ctx)
  int8_t default_10160 = kk_std_core_int_int8(kk_integer_from_small(0), _ctx); /*int8*/;
  kk_ssize_t _b_x63_65 = (KK_IZ(0)); /*ssize_t*/;
  kk_vector_t acc_10005 = kk_std_core_vector_vector_alloc(_b_x63_65, kk_int8_box(default_10160, _ctx), _ctx); /*vector<int8>*/;
  kk_vector_t x_10211;
  if (kk_nagare_core_types__is_PDone(step, _ctx)) {
    x_10211 = acc_10005; /*nagare/io/file/bytes*/
  }
  else {
    x_10211 = kk_nagare_io_image__unroll_collectBytesPull_10000(step, acc_10005, _ctx); /*nagare/io/file/bytes*/
  }
  if (kk_yielding(kk_context())) {
    kk_vector_drop(x_10211, _ctx);
    kk_box_t _x_x273 = kk_std_core_hnd_yield_extend(kk_nagare_io_image_new_decodeImageAll_fun274(_ctx), _ctx); /*10001*/
    return kk_nagare_core_types__pull_unbox(_x_x273, KK_OWNED, _ctx);
  }
  {
    return kk_nagare_io_image__mlift_decodeImageAll_10186(x_10211, _ctx);
  }
}

kk_nagare_core_types__nstream kk_nagare_io_image_decodeImageAll(kk_nagare_core_types__nstream source, kk_context_t* _ctx) { /* forall<e> (source : nagare/core/types/nstream<nagare/io/file/bytes,<nagare/io/image_effect/imageDecode|e>>) -> nagare/core/types/nstream<nagare/io/image_effect/image,<nagare/io/image_effect/imageDecode|e>> */ 
  {
    kk_nagare_core_types__pull step = source.step;
    kk_nagare_core_types__pull _x_x271 = kk_nagare_core_types__new_PEval(kk_reuse_null, 0, kk_nagare_io_image_new_decodeImageAll_fun272(step, _ctx), _ctx); /*nagare/core/types/pull<19,20>*/
    return kk_nagare_core_types__new_Stream(_x_x271, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_nagare_io_image__mlift_readImageBytesPull_10187_fun281__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_io_image__mlift_readImageBytesPull_10187_fun281(kk_function_t _fself, kk_box_t _b_x76, kk_box_t _b_x77, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_image__new_mlift_readImageBytesPull_10187_fun281(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_image__mlift_readImageBytesPull_10187_fun281, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_io_image__mlift_readImageBytesPull_10187_fun281(kk_function_t _fself, kk_box_t _b_x76, kk_box_t _b_x77, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_nagare_core_types__pull _x_x282;
  kk_nagare_io_file__effect__read_handle _x_x283 = kk_nagare_io_file__effect__read_handle_unbox(_b_x76, KK_OWNED, _ctx); /*nagare/io/file_effect/read-handle*/
  kk_integer_t _x_x284 = kk_integer_unbox(_b_x77, _ctx); /*int*/
  _x_x282 = kk_nagare_io_image_readImageBytesPull(_x_x283, _x_x284, _ctx); /*nagare/core/types/pull<nagare/io/file/bytes,<nagare/io/file_effect/fileRead,nagare/io/image_effect/imageDecode|io>>*/
  return kk_nagare_core_types__pull_box(_x_x282, _ctx);
}

kk_nagare_core_types__pull kk_nagare_io_image__mlift_readImageBytesPull_10187(kk_integer_t chunkSize, kk_nagare_io_file__effect__read_handle h, kk_vector_t chunk, kk_context_t* _ctx) { /* (chunkSize : int, h : nagare/io/file_effect/read-handle, chunk : vector<int8>) -> <nagare/io/file_effect/fileRead,div,alloc<global>,console/console,exn,fsys,nagare/io/image_effect/imageDecode,ndet,net,read<global>,ui,write<global>> nagare/core/types/pull<nagare/io/file/bytes,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileRead,fsys,nagare/io/image_effect/imageDecode,ndet,net,read<global>,ui,write<global>>> */ 
  bool _match_x214;
  kk_integer_t _brw_x215;
  kk_ssize_t _x_x276 = kk_vector_len_borrow(chunk,kk_context()); /*ssize_t*/
  _brw_x215 = kk_integer_from_ssize_t(_x_x276,kk_context()); /*int*/
  bool _brw_x216 = kk_integer_eq_borrow(_brw_x215,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x215, _ctx);
  _match_x214 = _brw_x216; /*bool*/
  if (_match_x214) {
    kk_integer_drop(chunkSize, _ctx);
    kk_vector_drop(chunk, _ctx);
    return kk_nagare_core_types__new_PDone(_ctx);
  }
  {
    kk_nagare_core_types__chunk _x_x277;
    kk_std_core_types__list _x_x278 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_vector_box(chunk, _ctx), kk_std_core_types__new_Nil(_ctx), _ctx); /*list<10021>*/
    _x_x277 = kk_nagare_core_types__new_Chunk(_x_x278, _ctx); /*nagare/core/types/chunk<4>*/
    kk_nagare_core_types__pull _x_x279;
    kk_box_t _x_x280 = kk_std_core_hnd__open_none2(kk_nagare_io_image__new_mlift_readImageBytesPull_10187_fun281(_ctx), kk_nagare_io_file__effect__read_handle_box(h, _ctx), kk_integer_box(chunkSize, _ctx), _ctx); /*10002*/
    _x_x279 = kk_nagare_core_types__pull_unbox(_x_x280, KK_OWNED, _ctx); /*nagare/core/types/pull<nagare/io/file/bytes,<nagare/io/file_effect/fileRead,nagare/io/image_effect/imageDecode|io>>*/
    return kk_nagare_core_types__new_POutput(kk_reuse_null, 0, _x_x277, _x_x279, _ctx);
  }
}
 
// Pull bytes from an open read-handle until EOF. Row-polymorphic so it can
// be lifted into pipelines that also carry `imageDecode` (or any other
// capability) — `readAllStreamingBytes` from `file.kk` pins its row to
// `<fileRead|io>`, which can't be widened at a call site.


// lift anonymous function
struct kk_nagare_io_image_readImageBytesPull_fun285__t {
  struct kk_function_s _base;
  kk_integer_t chunkSize_0;
  kk_nagare_io_file__effect__read_handle h_0;
};
static kk_nagare_core_types__pull kk_nagare_io_image_readImageBytesPull_fun285(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_image_new_readImageBytesPull_fun285(kk_integer_t chunkSize_0, kk_nagare_io_file__effect__read_handle h_0, kk_context_t* _ctx) {
  struct kk_nagare_io_image_readImageBytesPull_fun285__t* _self = kk_function_alloc_as(struct kk_nagare_io_image_readImageBytesPull_fun285__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_image_readImageBytesPull_fun285, kk_context());
  _self->chunkSize_0 = chunkSize_0;
  _self->h_0 = h_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_io_image_readImageBytesPull_fun291__t {
  struct kk_function_s _base;
  kk_ssize_t i_10215;
};
static kk_box_t kk_nagare_io_image_readImageBytesPull_fun291(kk_function_t _fself, kk_function_t _b_x98, kk_box_t _b_x99, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_image_new_readImageBytesPull_fun291(kk_ssize_t i_10215, kk_context_t* _ctx) {
  struct kk_nagare_io_image_readImageBytesPull_fun291__t* _self = kk_function_alloc_as(struct kk_nagare_io_image_readImageBytesPull_fun291__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_image_readImageBytesPull_fun291, kk_context());
  _self->i_10215 = i_10215;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_image_readImageBytesPull_fun291(kk_function_t _fself, kk_function_t _b_x98, kk_box_t _b_x99, kk_context_t* _ctx) {
  struct kk_nagare_io_image_readImageBytesPull_fun291__t* _self = kk_function_as(struct kk_nagare_io_image_readImageBytesPull_fun291__t*, _fself, _ctx);
  kk_ssize_t i_10215 = _self->i_10215; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_10215, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_10215, _b_x98, _b_x99, _ctx);
}


// lift anonymous function
struct kk_nagare_io_image_readImageBytesPull_fun293__t {
  struct kk_function_s _base;
  kk_integer_t chunkSize_0;
  kk_nagare_io_file__effect__read_handle h_0;
};
static kk_box_t kk_nagare_io_image_readImageBytesPull_fun293(kk_function_t _fself, kk_box_t _b_x108, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_image_new_readImageBytesPull_fun293(kk_integer_t chunkSize_0, kk_nagare_io_file__effect__read_handle h_0, kk_context_t* _ctx) {
  struct kk_nagare_io_image_readImageBytesPull_fun293__t* _self = kk_function_alloc_as(struct kk_nagare_io_image_readImageBytesPull_fun293__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_image_readImageBytesPull_fun293, kk_context());
  _self->chunkSize_0 = chunkSize_0;
  _self->h_0 = h_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_image_readImageBytesPull_fun293(kk_function_t _fself, kk_box_t _b_x108, kk_context_t* _ctx) {
  struct kk_nagare_io_image_readImageBytesPull_fun293__t* _self = kk_function_as(struct kk_nagare_io_image_readImageBytesPull_fun293__t*, _fself, _ctx);
  kk_integer_t chunkSize_0 = _self->chunkSize_0; /* int */
  kk_nagare_io_file__effect__read_handle h_0 = _self->h_0; /* nagare/io/file_effect/read-handle */
  kk_drop_match(_self, {kk_integer_dup(chunkSize_0, _ctx);kk_nagare_io_file__effect__read_handle_dup(h_0, _ctx);}, {}, _ctx)
  kk_vector_t chunk_0_111 = kk_vector_unbox(_b_x108, _ctx); /*vector<int8>*/;
  kk_nagare_core_types__pull _x_x294 = kk_nagare_io_image__mlift_readImageBytesPull_10187(chunkSize_0, h_0, chunk_0_111, _ctx); /*nagare/core/types/pull<nagare/io/file/bytes,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileRead,fsys,nagare/io/image_effect/imageDecode,ndet,net,read<global>,ui,write<global>>>*/
  return kk_nagare_core_types__pull_box(_x_x294, _ctx);
}
static kk_nagare_core_types__pull kk_nagare_io_image_readImageBytesPull_fun285(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_io_image_readImageBytesPull_fun285__t* _self = kk_function_as(struct kk_nagare_io_image_readImageBytesPull_fun285__t*, _fself, _ctx);
  kk_integer_t chunkSize_0 = _self->chunkSize_0; /* int */
  kk_nagare_io_file__effect__read_handle h_0 = _self->h_0; /* nagare/io/file_effect/read-handle */
  kk_drop_match(_self, {kk_integer_dup(chunkSize_0, _ctx);kk_nagare_io_file__effect__read_handle_dup(h_0, _ctx);}, {}, _ctx)
  kk_ssize_t i_10215 = (KK_IZ(1)); /*hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_10215,kk_context()); /*hnd/evv<<nagare/io/file_effect/fileRead,div,alloc<global>,console/console,exn,fsys,nagare/io/image_effect/imageDecode,ndet,net,read<global>,ui,write<global>>>*/;
  kk_std_core_hnd__ev evx_10219 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<nagare/io/file_effect/fileRead>*/;
  kk_vector_t y;
  kk_box_t _x_x286;
  {
    struct kk_std_core_hnd_Ev* _con_x287 = kk_std_core_hnd__as_Ev(evx_10219, _ctx);
    kk_box_t _box_x83 = _con_x287->hnd;
    int32_t m = _con_x287->marker;
    kk_nagare_io_file__effect__fileRead h_1 = kk_nagare_io_file__effect__fileRead_unbox(_box_x83, KK_BORROWED, _ctx);
    kk_nagare_io_file__effect__fileRead_dup(h_1, _ctx);
    kk_std_core_hnd__clause2 _match_x212;
    kk_std_core_hnd__clause2 _brw_x213 = kk_nagare_io_file__effect_readChunkBytes_fs__select(h_1, _ctx); /*hnd/clause2<nagare/io/file_effect/read-handle,int,vector<int8>,nagare/io/file_effect/fileRead,1017,1018>*/;
    kk_datatype_ptr_dropn(h_1, (KK_I32(6)), _ctx);
    _match_x212 = _brw_x213; /*hnd/clause2<nagare/io/file_effect/read-handle,int,vector<int8>,nagare/io/file_effect/fileRead,1017,1018>*/
    {
      kk_function_t _fun_unbox_x88 = _match_x212.clause;
      kk_box_t _x_x288;
      kk_integer_t _x_x289 = kk_integer_dup(chunkSize_0, _ctx); /*int*/
      _x_x288 = kk_integer_box(_x_x289, _ctx); /*10015*/
      _x_x286 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_box_t, kk_context_t*), _fun_unbox_x88, (_fun_unbox_x88, m, evx_10219, kk_nagare_io_file__effect__read_handle_box(h_0, _ctx), _x_x288, _ctx), _ctx); /*10016*/
    }
  }
  y = kk_vector_unbox(_x_x286, _ctx); /*vector<int8>*/
  kk_evv_set(w,kk_context());
  kk_vector_t x_10213;
  if (kk_yielding(kk_context())) {
    kk_vector_drop(y, _ctx);
    kk_box_t _x_x290 = kk_std_core_hnd_yield_cont(kk_nagare_io_image_new_readImageBytesPull_fun291(i_10215, _ctx), _ctx); /*10002*/
    x_10213 = kk_vector_unbox(_x_x290, _ctx); /*vector<int8>*/
  }
  else {
    x_10213 = y; /*vector<int8>*/
  }
  if (kk_yielding(kk_context())) {
    kk_vector_drop(x_10213, _ctx);
    kk_box_t _x_x292 = kk_std_core_hnd_yield_extend(kk_nagare_io_image_new_readImageBytesPull_fun293(chunkSize_0, h_0, _ctx), _ctx); /*10001*/
    return kk_nagare_core_types__pull_unbox(_x_x292, KK_OWNED, _ctx);
  }
  {
    return kk_nagare_io_image__mlift_readImageBytesPull_10187(chunkSize_0, h_0, x_10213, _ctx);
  }
}

kk_nagare_core_types__pull kk_nagare_io_image_readImageBytesPull(kk_nagare_io_file__effect__read_handle h_0, kk_integer_t chunkSize_0, kk_context_t* _ctx) { /* (h : nagare/io/file_effect/read-handle, chunkSize : int) -> div nagare/core/types/pull<nagare/io/file/bytes,<nagare/io/file_effect/fileRead,nagare/io/image_effect/imageDecode|io>> */ 
  return kk_nagare_core_types__new_PEval(kk_reuse_null, 0, kk_nagare_io_image_new_readImageBytesPull_fun285(chunkSize_0, h_0, _ctx), _ctx);
}
 
// Lazy byte-chunk source over a file. The row is `<fileRead, imageDecode|io>`
// so it composes directly with `decodeImageAll` — `readAllStreamingBytes`
// from `file.kk` pins its row to `<fileRead|io>` (no imageDecode), and Koka
// can't widen a fixed row at the call site.


// lift anonymous function
struct kk_nagare_io_image_readImageBytes_fun298__t {
  struct kk_function_s _base;
  kk_std_core_types__optional chunkSize;
  kk_std_os_path__path filepath;
};
static kk_nagare_core_types__pull kk_nagare_io_image_readImageBytes_fun298(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_image_new_readImageBytes_fun298(kk_std_core_types__optional chunkSize, kk_std_os_path__path filepath, kk_context_t* _ctx) {
  struct kk_nagare_io_image_readImageBytes_fun298__t* _self = kk_function_alloc_as(struct kk_nagare_io_image_readImageBytes_fun298__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_image_readImageBytes_fun298, kk_context());
  _self->chunkSize = chunkSize;
  _self->filepath = filepath;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_io_image_readImageBytes_fun300__t {
  struct kk_function_s _base;
  kk_std_os_path__path filepath;
  kk_ref_t hRef;
};
static kk_unit_t kk_nagare_io_image_readImageBytes_fun300(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_image_new_readImageBytes_fun300(kk_std_os_path__path filepath, kk_ref_t hRef, kk_context_t* _ctx) {
  struct kk_nagare_io_image_readImageBytes_fun300__t* _self = kk_function_alloc_as(struct kk_nagare_io_image_readImageBytes_fun300__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_image_readImageBytes_fun300, kk_context());
  _self->filepath = filepath;
  _self->hRef = hRef;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_io_image_readImageBytes_fun302__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_io_image_readImageBytes_fun302(kk_function_t _fself, kk_box_t _b_x122, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_image_new_readImageBytes_fun302(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_image_readImageBytes_fun302, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_io_image_readImageBytes_fun302(kk_function_t _fself, kk_box_t _b_x122, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x303;
  kk_std_os_path__path _x_x304 = kk_std_os_path__path_unbox(_b_x122, KK_OWNED, _ctx); /*std/os/path/path*/
  _x_x303 = kk_std_os_path_string(_x_x304, _ctx); /*string*/
  return kk_string_box(_x_x303);
}


// lift anonymous function
struct kk_nagare_io_image_readImageBytes_fun308__t {
  struct kk_function_s _base;
  kk_ssize_t i_10225;
};
static kk_box_t kk_nagare_io_image_readImageBytes_fun308(kk_function_t _fself, kk_function_t _b_x138, kk_box_t _b_x139, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_image_new_readImageBytes_fun308(kk_ssize_t i_10225, kk_context_t* _ctx) {
  struct kk_nagare_io_image_readImageBytes_fun308__t* _self = kk_function_alloc_as(struct kk_nagare_io_image_readImageBytes_fun308__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_image_readImageBytes_fun308, kk_context());
  _self->i_10225 = i_10225;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_image_readImageBytes_fun308(kk_function_t _fself, kk_function_t _b_x138, kk_box_t _b_x139, kk_context_t* _ctx) {
  struct kk_nagare_io_image_readImageBytes_fun308__t* _self = kk_function_as(struct kk_nagare_io_image_readImageBytes_fun308__t*, _fself, _ctx);
  kk_ssize_t i_10225 = _self->i_10225; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_10225, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_10225, _b_x138, _b_x139, _ctx);
}


// lift anonymous function
struct kk_nagare_io_image_readImageBytes_fun309__t {
  struct kk_function_s _base;
  kk_ref_t hRef;
};
static kk_unit_t kk_nagare_io_image_readImageBytes_fun309(kk_function_t _fself, kk_nagare_io_file__effect__read_handle _y_x10153, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_image_new_readImageBytes_fun309(kk_ref_t hRef, kk_context_t* _ctx) {
  struct kk_nagare_io_image_readImageBytes_fun309__t* _self = kk_function_alloc_as(struct kk_nagare_io_image_readImageBytes_fun309__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_image_readImageBytes_fun309, kk_context());
  _self->hRef = hRef;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_unit_t kk_nagare_io_image_readImageBytes_fun309(kk_function_t _fself, kk_nagare_io_file__effect__read_handle _y_x10153, kk_context_t* _ctx) {
  struct kk_nagare_io_image_readImageBytes_fun309__t* _self = kk_function_as(struct kk_nagare_io_image_readImageBytes_fun309__t*, _fself, _ctx);
  kk_ref_t hRef = _self->hRef; /* ref<global,maybe<nagare/io/file_effect/read-handle>> */
  kk_drop_match(_self, {kk_ref_dup(hRef, _ctx);}, {}, _ctx)
  kk_unit_t _brw_x205 = kk_Unit;
  kk_box_t _x_x310;
  kk_std_core_types__maybe _x_x311 = kk_std_core_types__new_Just(kk_nagare_io_file__effect__read_handle_box(_y_x10153, _ctx), _ctx); /*maybe<10024>*/
  _x_x310 = kk_std_core_types__maybe_box(_x_x311, _ctx); /*10000*/
  kk_ref_set_borrow(hRef,_x_x310,kk_context());
  kk_ref_drop(hRef, _ctx);
  _brw_x205; return kk_Unit;
}


// lift anonymous function
struct kk_nagare_io_image_readImageBytes_fun313__t {
  struct kk_function_s _base;
  kk_function_t next_10224;
};
static kk_box_t kk_nagare_io_image_readImageBytes_fun313(kk_function_t _fself, kk_box_t _b_x154, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_image_new_readImageBytes_fun313(kk_function_t next_10224, kk_context_t* _ctx) {
  struct kk_nagare_io_image_readImageBytes_fun313__t* _self = kk_function_alloc_as(struct kk_nagare_io_image_readImageBytes_fun313__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_image_readImageBytes_fun313, kk_context());
  _self->next_10224 = next_10224;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_image_readImageBytes_fun313(kk_function_t _fself, kk_box_t _b_x154, kk_context_t* _ctx) {
  struct kk_nagare_io_image_readImageBytes_fun313__t* _self = kk_function_as(struct kk_nagare_io_image_readImageBytes_fun313__t*, _fself, _ctx);
  kk_function_t next_10224 = _self->next_10224; /* (nagare/io/file_effect/read-handle) -> <nagare/io/file_effect/fileRead,write<global>,alloc<global>,console/console,div,exn,fsys,nagare/io/image_effect/imageDecode,ndet,net,read<global>,ui> () */
  kk_drop_match(_self, {kk_function_dup(next_10224, _ctx);}, {}, _ctx)
  kk_unit_t _x_x314 = kk_Unit;
  kk_nagare_io_file__effect__read_handle _x_x315 = kk_nagare_io_file__effect__read_handle_unbox(_b_x154, KK_OWNED, _ctx); /*nagare/io/file_effect/read-handle*/
  kk_function_call(kk_unit_t, (kk_function_t, kk_nagare_io_file__effect__read_handle, kk_context_t*), next_10224, (next_10224, _x_x315, _ctx), _ctx);
  return kk_unit_box(_x_x314);
}
static kk_unit_t kk_nagare_io_image_readImageBytes_fun300(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_io_image_readImageBytes_fun300__t* _self = kk_function_as(struct kk_nagare_io_image_readImageBytes_fun300__t*, _fself, _ctx);
  kk_std_os_path__path filepath = _self->filepath; /* std/os/path/path */
  kk_ref_t hRef = _self->hRef; /* ref<global,maybe<nagare/io/file_effect/read-handle>> */
  kk_drop_match(_self, {kk_std_os_path__path_dup(filepath, _ctx);kk_ref_dup(hRef, _ctx);}, {}, _ctx)
  kk_string_t _x_x1_10177;
  kk_box_t _x_x301 = kk_std_core_hnd__open_none1(kk_nagare_io_image_new_readImageBytes_fun302(_ctx), kk_std_os_path__path_box(filepath, _ctx), _ctx); /*10001*/
  _x_x1_10177 = kk_string_unbox(_x_x301); /*string*/
  kk_ssize_t i_10225 = (KK_IZ(1)); /*hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_10225,kk_context()); /*hnd/evv<<nagare/io/file_effect/fileRead,write<global>,alloc<global>,console/console,div,exn,fsys,nagare/io/image_effect/imageDecode,ndet,net,read<global>,ui>>*/;
  kk_std_core_hnd__ev ev_10228 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<nagare/io/file_effect/fileRead>*/;
  kk_nagare_io_file__effect__read_handle y;
  kk_box_t _x_x305;
  {
    struct kk_std_core_hnd_Ev* _con_x306 = kk_std_core_hnd__as_Ev(ev_10228, _ctx);
    kk_box_t _box_x125 = _con_x306->hnd;
    int32_t m = _con_x306->marker;
    kk_nagare_io_file__effect__fileRead h = kk_nagare_io_file__effect__fileRead_unbox(_box_x125, KK_BORROWED, _ctx);
    kk_nagare_io_file__effect__fileRead_dup(h, _ctx);
    kk_std_core_hnd__clause1 _match_x207;
    kk_std_core_hnd__clause1 _brw_x208 = kk_nagare_io_file__effect_openRead_fs__select(h, _ctx); /*hnd/clause1<string,nagare/io/file_effect/read-handle,nagare/io/file_effect/fileRead,692,693>*/;
    kk_datatype_ptr_dropn(h, (KK_I32(6)), _ctx);
    _match_x207 = _brw_x208; /*hnd/clause1<string,nagare/io/file_effect/read-handle,nagare/io/file_effect/fileRead,692,693>*/
    {
      kk_function_t _fun_unbox_x129 = _match_x207.clause;
      _x_x305 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x129, (_fun_unbox_x129, m, ev_10228, kk_string_box(_x_x1_10177), _ctx), _ctx); /*10010*/
    }
  }
  y = kk_nagare_io_file__effect__read_handle_unbox(_x_x305, KK_OWNED, _ctx); /*nagare/io/file_effect/read-handle*/
  kk_evv_set(w,kk_context());
  kk_nagare_io_file__effect__read_handle x_10223;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x307 = kk_std_core_hnd_yield_cont(kk_nagare_io_image_new_readImageBytes_fun308(i_10225, _ctx), _ctx); /*10002*/
    x_10223 = kk_nagare_io_file__effect__read_handle_unbox(_x_x307, KK_OWNED, _ctx); /*nagare/io/file_effect/read-handle*/
  }
  else {
    x_10223 = y; /*nagare/io/file_effect/read-handle*/
  }
  kk_function_t next_10224 = kk_nagare_io_image_new_readImageBytes_fun309(hRef, _ctx); /*(nagare/io/file_effect/read-handle) -> <nagare/io/file_effect/fileRead,write<global>,alloc<global>,console/console,div,exn,fsys,nagare/io/image_effect/imageDecode,ndet,net,read<global>,ui> ()*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x312 = kk_std_core_hnd_yield_extend(kk_nagare_io_image_new_readImageBytes_fun313(next_10224, _ctx), _ctx); /*10001*/
    kk_unit_unbox(_x_x312); return kk_Unit;
  }
  {
    kk_function_call(kk_unit_t, (kk_function_t, kk_nagare_io_file__effect__read_handle, kk_context_t*), next_10224, (next_10224, x_10223, _ctx), _ctx); return kk_Unit;
  }
}


// lift anonymous function
struct kk_nagare_io_image_readImageBytes_fun317__t {
  struct kk_function_s _base;
  kk_ref_t hRef;
};
static kk_unit_t kk_nagare_io_image_readImageBytes_fun317(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_image_new_readImageBytes_fun317(kk_ref_t hRef, kk_context_t* _ctx) {
  struct kk_nagare_io_image_readImageBytes_fun317__t* _self = kk_function_alloc_as(struct kk_nagare_io_image_readImageBytes_fun317__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_image_readImageBytes_fun317, kk_context());
  _self->hRef = hRef;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_io_image_readImageBytes_fun322__t {
  struct kk_function_s _base;
  kk_ssize_t i_0_10233;
};
static kk_box_t kk_nagare_io_image_readImageBytes_fun322(kk_function_t _fself, kk_function_t _b_x171, kk_box_t _b_x172, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_image_new_readImageBytes_fun322(kk_ssize_t i_0_10233, kk_context_t* _ctx) {
  struct kk_nagare_io_image_readImageBytes_fun322__t* _self = kk_function_alloc_as(struct kk_nagare_io_image_readImageBytes_fun322__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_image_readImageBytes_fun322, kk_context());
  _self->i_0_10233 = i_0_10233;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_io_image_readImageBytes_fun323__t {
  struct kk_function_s _base;
  kk_function_t _b_x171;
};
static kk_unit_t kk_nagare_io_image_readImageBytes_fun323(kk_function_t _fself, kk_box_t _b_x173, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_image_new_readImageBytes_fun323(kk_function_t _b_x171, kk_context_t* _ctx) {
  struct kk_nagare_io_image_readImageBytes_fun323__t* _self = kk_function_alloc_as(struct kk_nagare_io_image_readImageBytes_fun323__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_image_readImageBytes_fun323, kk_context());
  _self->_b_x171 = _b_x171;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_unit_t kk_nagare_io_image_readImageBytes_fun323(kk_function_t _fself, kk_box_t _b_x173, kk_context_t* _ctx) {
  struct kk_nagare_io_image_readImageBytes_fun323__t* _self = kk_function_as(struct kk_nagare_io_image_readImageBytes_fun323__t*, _fself, _ctx);
  kk_function_t _b_x171 = _self->_b_x171; /* (10003) -> 10001 10000 */
  kk_drop_match(_self, {kk_function_dup(_b_x171, _ctx);}, {}, _ctx)
  kk_box_t _x_x324 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _b_x171, (_b_x171, _b_x173, _ctx), _ctx); /*10000*/
  kk_unit_unbox(_x_x324); return kk_Unit;
}


// lift anonymous function
struct kk_nagare_io_image_readImageBytes_fun325__t {
  struct kk_function_s _base;
  kk_function_t _b_x167_184;
};
static kk_box_t kk_nagare_io_image_readImageBytes_fun325(kk_function_t _fself, kk_box_t _b_x169, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_image_new_readImageBytes_fun325(kk_function_t _b_x167_184, kk_context_t* _ctx) {
  struct kk_nagare_io_image_readImageBytes_fun325__t* _self = kk_function_alloc_as(struct kk_nagare_io_image_readImageBytes_fun325__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_image_readImageBytes_fun325, kk_context());
  _self->_b_x167_184 = _b_x167_184;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_image_readImageBytes_fun325(kk_function_t _fself, kk_box_t _b_x169, kk_context_t* _ctx) {
  struct kk_nagare_io_image_readImageBytes_fun325__t* _self = kk_function_as(struct kk_nagare_io_image_readImageBytes_fun325__t*, _fself, _ctx);
  kk_function_t _b_x167_184 = _self->_b_x167_184; /* (10011) -> <nagare/io/file_effect/fileRead,read<global>,alloc<global>,console/console,div,exn,fsys,nagare/io/image_effect/imageDecode,ndet,net,ui,write<global>> () */
  kk_drop_match(_self, {kk_function_dup(_b_x167_184, _ctx);}, {}, _ctx)
  kk_unit_t _x_x326 = kk_Unit;
  kk_function_call(kk_unit_t, (kk_function_t, kk_box_t, kk_context_t*), _b_x167_184, (_b_x167_184, _b_x169, _ctx), _ctx);
  return kk_unit_box(_x_x326);
}
static kk_box_t kk_nagare_io_image_readImageBytes_fun322(kk_function_t _fself, kk_function_t _b_x171, kk_box_t _b_x172, kk_context_t* _ctx) {
  struct kk_nagare_io_image_readImageBytes_fun322__t* _self = kk_function_as(struct kk_nagare_io_image_readImageBytes_fun322__t*, _fself, _ctx);
  kk_ssize_t i_0_10233 = _self->i_0_10233; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_0_10233, _ctx);}, {}, _ctx)
  kk_function_t cont_0_188 = kk_nagare_io_image_new_readImageBytes_fun323(_b_x171, _ctx); /*(10011) -> <nagare/io/file_effect/fileRead,read<global>,alloc<global>,console/console,div,exn,fsys,nagare/io/image_effect/imageDecode,ndet,net,ui,write<global>> ()*/;
  kk_box_t res_0_189 = _b_x172; /*10011*/;
  kk_ssize_t _b_x166_183 = i_0_10233; /*hnd/ev-index*/;
  kk_function_t _b_x167_184 = cont_0_188; /*(10011) -> <nagare/io/file_effect/fileRead,read<global>,alloc<global>,console/console,div,exn,fsys,nagare/io/image_effect/imageDecode,ndet,net,ui,write<global>> ()*/;
  kk_box_t _b_x168_185 = res_0_189; /*10011*/;
  return kk_std_core_hnd_open_at1(_b_x166_183, kk_nagare_io_image_new_readImageBytes_fun325(_b_x167_184, _ctx), _b_x168_185, _ctx);
}
static kk_unit_t kk_nagare_io_image_readImageBytes_fun317(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_io_image_readImageBytes_fun317__t* _self = kk_function_as(struct kk_nagare_io_image_readImageBytes_fun317__t*, _fself, _ctx);
  kk_ref_t hRef = _self->hRef; /* ref<global,maybe<nagare/io/file_effect/read-handle>> */
  kk_drop_match(_self, {kk_ref_dup(hRef, _ctx);}, {}, _ctx)
  kk_std_core_types__maybe _match_x200;
  kk_box_t _x_x318 = kk_ref_get(hRef,kk_context()); /*10000*/
  _match_x200 = kk_std_core_types__maybe_unbox(_x_x318, KK_OWNED, _ctx); /*maybe<nagare/io/file_effect/read-handle>*/
  if (kk_std_core_types__is_Just(_match_x200, _ctx)) {
    kk_box_t _box_x157 = _match_x200._cons.Just.value;
    kk_nagare_io_file__effect__read_handle h_0 = kk_nagare_io_file__effect__read_handle_unbox(_box_x157, KK_BORROWED, _ctx);
    kk_std_core_types__maybe_drop(_match_x200, _ctx);
    kk_ssize_t i_0_10233 = (KK_IZ(1)); /*hnd/ev-index*/;
    kk_evv_t w_0 = kk_evv_swap_create1(i_0_10233,kk_context()); /*hnd/evv<<nagare/io/file_effect/fileRead,read<global>,alloc<global>,console/console,div,exn,fsys,nagare/io/image_effect/imageDecode,ndet,net,ui,write<global>>>*/;
    kk_std_core_hnd__ev ev_0_10236 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<nagare/io/file_effect/fileRead>*/;
    kk_unit_t y_0 = kk_Unit;
    kk_box_t _x_x319;
    {
      struct kk_std_core_hnd_Ev* _con_x320 = kk_std_core_hnd__as_Ev(ev_0_10236, _ctx);
      kk_box_t _box_x158 = _con_x320->hnd;
      int32_t m_0 = _con_x320->marker;
      kk_nagare_io_file__effect__fileRead h_1 = kk_nagare_io_file__effect__fileRead_unbox(_box_x158, KK_BORROWED, _ctx);
      kk_nagare_io_file__effect__fileRead_dup(h_1, _ctx);
      kk_std_core_hnd__clause1 _match_x202;
      kk_std_core_hnd__clause1 _brw_x203 = kk_nagare_io_file__effect_closeRead_fs__select(h_1, _ctx); /*hnd/clause1<nagare/io/file_effect/read-handle,(),nagare/io/file_effect/fileRead,799,800>*/;
      kk_datatype_ptr_dropn(h_1, (KK_I32(6)), _ctx);
      _match_x202 = _brw_x203; /*hnd/clause1<nagare/io/file_effect/read-handle,(),nagare/io/file_effect/fileRead,799,800>*/
      {
        kk_function_t _fun_unbox_x162 = _match_x202.clause;
        _x_x319 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x162, (_fun_unbox_x162, m_0, ev_0_10236, kk_nagare_io_file__effect__read_handle_box(h_0, _ctx), _ctx), _ctx); /*10010*/
      }
    }
    kk_unit_unbox(_x_x319);
    kk_evv_set(w_0,kk_context());
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x321 = kk_std_core_hnd_yield_cont(kk_nagare_io_image_new_readImageBytes_fun322(i_0_10233, _ctx), _ctx); /*10002*/
      kk_unit_unbox(_x_x321); return kk_Unit;
    }
    {
      y_0; return kk_Unit;
    }
  }
  {
    kk_Unit; return kk_Unit;
  }
}


// lift anonymous function
struct kk_nagare_io_image_readImageBytes_fun328__t {
  struct kk_function_s _base;
  kk_std_core_types__optional chunkSize;
  kk_ref_t hRef;
};
static kk_nagare_core_types__pull kk_nagare_io_image_readImageBytes_fun328(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_image_new_readImageBytes_fun328(kk_std_core_types__optional chunkSize, kk_ref_t hRef, kk_context_t* _ctx) {
  struct kk_nagare_io_image_readImageBytes_fun328__t* _self = kk_function_alloc_as(struct kk_nagare_io_image_readImageBytes_fun328__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_image_readImageBytes_fun328, kk_context());
  _self->chunkSize = chunkSize;
  _self->hRef = hRef;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_nagare_core_types__pull kk_nagare_io_image_readImageBytes_fun328(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_io_image_readImageBytes_fun328__t* _self = kk_function_as(struct kk_nagare_io_image_readImageBytes_fun328__t*, _fself, _ctx);
  kk_std_core_types__optional chunkSize = _self->chunkSize; /* ? int */
  kk_ref_t hRef = _self->hRef; /* ref<global,maybe<nagare/io/file_effect/read-handle>> */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(chunkSize, _ctx);kk_ref_dup(hRef, _ctx);}, {}, _ctx)
  kk_std_core_types__maybe _match_x199;
  kk_box_t _x_x329 = kk_ref_get(hRef,kk_context()); /*10000*/
  _match_x199 = kk_std_core_types__maybe_unbox(_x_x329, KK_OWNED, _ctx); /*maybe<nagare/io/file_effect/read-handle>*/
  if (kk_std_core_types__is_Just(_match_x199, _ctx)) {
    kk_box_t _box_x176 = _match_x199._cons.Just.value;
    kk_nagare_io_file__effect__read_handle h_0_0_0 = kk_nagare_io_file__effect__read_handle_unbox(_box_x176, KK_BORROWED, _ctx);
    kk_std_core_types__maybe_drop(_match_x199, _ctx);
    kk_evv_t w_1 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<div,read<global>,alloc<global>,console/console,exn,nagare/io/file_effect/fileRead,fsys,nagare/io/image_effect/imageDecode,ndet,net,ui,write<global>>>*/;
    kk_nagare_core_types__pull x_4;
    kk_integer_t _x_x330;
    if (kk_std_core_types__is_Optional(chunkSize, _ctx)) {
      kk_box_t _box_x177 = chunkSize._cons._Optional.value;
      kk_integer_t _uniq_chunkSize_637 = kk_integer_unbox(_box_x177, _ctx);
      kk_integer_dup(_uniq_chunkSize_637, _ctx);
      kk_std_core_types__optional_drop(chunkSize, _ctx);
      _x_x330 = _uniq_chunkSize_637; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(chunkSize, _ctx);
      _x_x330 = kk_integer_from_small(4096); /*int*/
    }
    x_4 = kk_nagare_io_image_readImageBytesPull(h_0_0_0, _x_x330, _ctx); /*nagare/core/types/pull<nagare/io/file/bytes,<nagare/io/file_effect/fileRead,nagare/io/image_effect/imageDecode|io>>*/
    kk_unit_t keep = kk_Unit;
    kk_evv_set(w_1,kk_context());
    return x_4;
  }
  {
    kk_std_core_types__optional_drop(chunkSize, _ctx);
    return kk_nagare_core_types__new_PDone(_ctx);
  }
}
static kk_nagare_core_types__pull kk_nagare_io_image_readImageBytes_fun298(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_io_image_readImageBytes_fun298__t* _self = kk_function_as(struct kk_nagare_io_image_readImageBytes_fun298__t*, _fself, _ctx);
  kk_std_core_types__optional chunkSize = _self->chunkSize; /* ? int */
  kk_std_os_path__path filepath = _self->filepath; /* std/os/path/path */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(chunkSize, _ctx);kk_std_os_path__path_dup(filepath, _ctx);}, {}, _ctx)
  kk_ref_t hRef = kk_ref_alloc((kk_std_core_types__maybe_box(kk_std_core_types__new_Nothing(_ctx), _ctx)),kk_context()); /*ref<global,maybe<nagare/io/file_effect/read-handle>>*/;
  kk_function_t _x_x299;
  kk_ref_dup(hRef, _ctx);
  _x_x299 = kk_nagare_io_image_new_readImageBytes_fun300(filepath, hRef, _ctx); /*() -> <alloc<global>,console/console,div,exn,nagare/io/file_effect/fileRead,fsys,nagare/io/image_effect/imageDecode,ndet,net,read<global>,ui,write<global>> ()*/
  kk_function_t _x_x316;
  kk_ref_dup(hRef, _ctx);
  _x_x316 = kk_nagare_io_image_new_readImageBytes_fun317(hRef, _ctx); /*() -> <alloc<global>,console/console,div,exn,nagare/io/file_effect/fileRead,fsys,nagare/io/image_effect/imageDecode,ndet,net,read<global>,ui,write<global>> ()*/
  kk_nagare_core_types__pull _x_x327 = kk_nagare_core_types__new_PEval(kk_reuse_null, 0, kk_nagare_io_image_new_readImageBytes_fun328(chunkSize, hRef, _ctx), _ctx); /*nagare/core/types/pull<19,20>*/
  return kk_nagare_core_types__new_PAcquire(kk_reuse_null, 0, _x_x299, _x_x316, _x_x327, _ctx);
}

kk_nagare_core_types__nstream kk_nagare_io_image_readImageBytes(kk_std_os_path__path filepath, kk_std_core_types__optional chunkSize, kk_context_t* _ctx) { /* (filepath : std/os/path/path, chunkSize : ? int) -> nagare/core/types/nstream<nagare/io/file/bytes,<nagare/io/file_effect/fileRead,nagare/io/image_effect/imageDecode|io>> */ 
  kk_nagare_core_types__pull _x_x297 = kk_nagare_core_types__new_PEval(kk_reuse_null, 0, kk_nagare_io_image_new_readImageBytes_fun298(chunkSize, filepath, _ctx), _ctx); /*nagare/core/types/pull<19,20>*/
  return kk_nagare_core_types__new_Stream(_x_x297, _ctx);
}
 
// Read one image file and decode it. The result stream emits exactly one
// `image` (or zero if the file was empty / undecodable).


// lift anonymous function
struct kk_nagare_io_image_readImage_fun332__t {
  struct kk_function_s _base;
  kk_nagare_core_types__pull step;
};
static kk_nagare_core_types__pull kk_nagare_io_image_readImage_fun332(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_image_new_readImage_fun332(kk_nagare_core_types__pull step, kk_context_t* _ctx) {
  struct kk_nagare_io_image_readImage_fun332__t* _self = kk_function_alloc_as(struct kk_nagare_io_image_readImage_fun332__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_image_readImage_fun332, kk_context());
  _self->step = step;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_io_image_readImage_fun334__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_io_image_readImage_fun334(kk_function_t _fself, kk_box_t _b_x195, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_image_new_readImage_fun334(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_image_readImage_fun334, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_io_image_readImage_fun334(kk_function_t _fself, kk_box_t _b_x195, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_vector_t _c_x10144_197 = kk_vector_unbox(_b_x195, _ctx); /*nagare/io/file/bytes*/;
  kk_nagare_core_types__pull _x_x335 = kk_nagare_io_image__mlift_decodeImageAll_10186(_c_x10144_197, _ctx); /*nagare/core/types/pull<nagare/io/image_effect/image,<nagare/io/image_effect/imageDecode|426>>*/
  return kk_nagare_core_types__pull_box(_x_x335, _ctx);
}
static kk_nagare_core_types__pull kk_nagare_io_image_readImage_fun332(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_io_image_readImage_fun332__t* _self = kk_function_as(struct kk_nagare_io_image_readImage_fun332__t*, _fself, _ctx);
  kk_nagare_core_types__pull step = _self->step; /* nagare/core/types/pull<nagare/io/file/bytes,<nagare/io/image_effect/imageDecode,alloc<global>,console/console,div,exn,nagare/io/file_effect/fileRead,fsys,ndet,net,read<global>,ui,write<global>>> */
  kk_drop_match(_self, {kk_nagare_core_types__pull_dup(step, _ctx);}, {}, _ctx)
  int8_t default_10160 = kk_std_core_int_int8(kk_integer_from_small(0), _ctx); /*int8*/;
  kk_ssize_t _b_x190_192 = (KK_IZ(0)); /*ssize_t*/;
  kk_vector_t acc_10005 = kk_std_core_vector_vector_alloc(_b_x190_192, kk_int8_box(default_10160, _ctx), _ctx); /*vector<int8>*/;
  kk_vector_t x_10243;
  if (kk_nagare_core_types__is_PDone(step, _ctx)) {
    x_10243 = acc_10005; /*nagare/io/file/bytes*/
  }
  else {
    x_10243 = kk_nagare_io_image__unroll_collectBytesPull_10000(step, acc_10005, _ctx); /*nagare/io/file/bytes*/
  }
  if (kk_yielding(kk_context())) {
    kk_vector_drop(x_10243, _ctx);
    kk_box_t _x_x333 = kk_std_core_hnd_yield_extend(kk_nagare_io_image_new_readImage_fun334(_ctx), _ctx); /*10001*/
    return kk_nagare_core_types__pull_unbox(_x_x333, KK_OWNED, _ctx);
  }
  {
    return kk_nagare_io_image__mlift_decodeImageAll_10186(x_10243, _ctx);
  }
}

kk_nagare_core_types__nstream kk_nagare_io_image_readImage(kk_std_os_path__path filepath, kk_context_t* _ctx) { /* (filepath : std/os/path/path) -> nagare/core/types/nstream<nagare/io/image_effect/image,<nagare/io/file_effect/fileRead,nagare/io/image_effect/imageDecode|io>> */ 
  kk_nagare_core_types__nstream source_10242 = kk_nagare_io_image_readImageBytes(filepath, kk_std_core_types__new_None(_ctx), _ctx); /*nagare/core/types/nstream<nagare/io/file/bytes,<nagare/io/image_effect/imageDecode,alloc<global>,console/console,div,exn,nagare/io/file_effect/fileRead,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  {
    kk_nagare_core_types__pull step = source_10242.step;
    kk_nagare_core_types__pull _x_x331 = kk_nagare_core_types__new_PEval(kk_reuse_null, 0, kk_nagare_io_image_new_readImage_fun332(step, _ctx), _ctx); /*nagare/core/types/pull<19,20>*/
    return kk_nagare_core_types__new_Stream(_x_x331, _ctx);
  }
}

// initialization
void kk_nagare_io_image__init(kk_context_t* _ctx){
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
  kk_std_os_path__init(_ctx);
  kk_nagare_core_types__init(_ctx);
  kk_nagare_core_stream__init(_ctx);
  kk_nagare_io_file__effect__init(_ctx);
  kk_nagare_io_file__init(_ctx);
  kk_nagare_io_image__effect__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
}

// termination
void kk_nagare_io_image__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_nagare_io_image__effect__done(_ctx);
  kk_nagare_io_file__done(_ctx);
  kk_nagare_io_file__effect__done(_ctx);
  kk_nagare_core_stream__done(_ctx);
  kk_nagare_core_types__done(_ctx);
  kk_std_os_path__done(_ctx);
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
