// Koka generated module: examples/image_pipeline, koka version: 3.2.3, platform: 64-bit
#include "examples_image__pipeline.h"
 
// lifted local: @lift-flattenBytes@10185, flattenBytes, @spec-x10140
// specialized: std/core/list/@lift-flatmap@6013, on parameters @uniq-f@10128, using:
// @uniq-f@10128 = fn(c: nagare/io/file/bytes){
//   std/core/vector/vlist<int8>(c, (std/core/types/@None<(list :: V -> V)<int8>>));
// }

kk_std_core_types__list kk_examples_image__pipeline__trmc_lift_flattenBytes_10186(kk_std_core_types__list _uniq_ys_10129, kk_std_core_types__list _uniq_zs_10130, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* (list<int8>, list<nagare/io/file/bytes>, ctx<list<int8>>) -> list<int8> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_ys_10129, _ctx)) {
    struct kk_std_core_types_Cons* _con_x504 = kk_std_core_types__as_Cons(_uniq_ys_10129, _ctx);
    kk_box_t _box_x0 = _con_x504->head;
    kk_std_core_types__list _uniq_yy_10133 = _con_x504->tail;
    int8_t _uniq_y_10132 = kk_int8_unbox(_box_x0, KK_BORROWED, _ctx);
    kk_reuse_t _ru_x496 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_ys_10129, _ctx)) {
      _ru_x496 = (kk_datatype_ptr_reuse(_uniq_ys_10129, _ctx));
    }
    else {
      kk_std_core_types__list_dup(_uniq_yy_10133, _ctx);
      kk_datatype_ptr_decref(_uniq_ys_10129, _ctx);
    }
    kk_std_core_types__list _trmc_x10193 = kk_datatype_null(); /*list<int8>*/;
    kk_std_core_types__list _trmc_x10194 = kk_std_core_types__new_Cons(_ru_x496, 0, kk_int8_box(_uniq_y_10132, _ctx), _trmc_x10193, _ctx); /*list<int8>*/;
    kk_field_addr_t _b_x10_16 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10194, _ctx)->tail, _ctx); /*@field-addr<list<int8>>*/;
    { // tailcall
      kk_std_core_types__cctx _x_x505 = kk_cctx_extend_linear(_acc,(kk_std_core_types__list_box(_trmc_x10194, _ctx)),_b_x10_16,kk_context()); /*ctx<0>*/
      _uniq_ys_10129 = _uniq_yy_10133;
      _acc = _x_x505;
      goto kk__tailcall;
    }
  }
  if (kk_std_core_types__is_Cons(_uniq_zs_10130, _ctx)) {
    struct kk_std_core_types_Cons* _con_x506 = kk_std_core_types__as_Cons(_uniq_zs_10130, _ctx);
    kk_box_t _box_x11 = _con_x506->head;
    kk_std_core_types__list _uniq_zz_10137 = _con_x506->tail;
    kk_vector_t _uniq_z_10136 = kk_vector_unbox(_box_x11, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_zs_10130, _ctx)) {
      kk_datatype_ptr_free(_uniq_zs_10130, _ctx);
    }
    else {
      kk_vector_dup(_uniq_z_10136, _ctx);
      kk_std_core_types__list_dup(_uniq_zz_10137, _ctx);
      kk_datatype_ptr_decref(_uniq_zs_10130, _ctx);
    }
    kk_std_core_types__list _uniq_ys_1_10132_10138 = kk_std_core_vector_vlist(_uniq_z_10136, kk_std_core_types__new_None(_ctx), _ctx); /*list<int8>*/;
    { // tailcall
      _uniq_ys_10129 = _uniq_ys_1_10132_10138;
      _uniq_zs_10130 = _uniq_zz_10137;
      goto kk__tailcall;
    }
  }
  {
    kk_box_t _x_x507 = kk_cctx_apply_linear(_acc,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x507, KK_OWNED, _ctx);
  }
}
 
// lifted local: @lift-flattenBytes@10185, flattenBytes, @spec-x10140
// specialized: std/core/list/@lift-flatmap@6013, on parameters @uniq-f@10128, using:
// @uniq-f@10128 = fn(c: nagare/io/file/bytes){
//   std/core/vector/vlist<int8>(c, (std/core/types/@None<(list :: V -> V)<int8>>));
// }

kk_std_core_types__list kk_examples_image__pipeline__lift_flattenBytes_10186(kk_std_core_types__list _uniq_ys_10129_0, kk_std_core_types__list _uniq_zs_10130_0, kk_context_t* _ctx) { /* (list<int8>, list<nagare/io/file/bytes>) -> list<int8> */ 
  kk_std_core_types__cctx _x_x508 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_examples_image__pipeline__trmc_lift_flattenBytes_10186(_uniq_ys_10129_0, _uniq_zs_10130_0, _x_x508, _ctx);
}
 
// lifted local: flattenBytes, @spec-x10127
// specialized: std/core/list/flatmap, on parameters @uniq-f@10126, using:
// @uniq-f@10126 = fn(c: nagare/io/file/bytes){
//   std/core/vector/vlist<int8>(c, (std/core/types/@None<(list :: V -> V)<int8>>));
// }

kk_std_core_types__list kk_examples_image__pipeline__lift_flattenBytes_10185(kk_std_core_types__list _uniq_xs_10125, kk_context_t* _ctx) { /* (list<nagare/io/file/bytes>) -> list<int8> */ 
  kk_std_core_types__cctx _x_x509 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_examples_image__pipeline__trmc_lift_flattenBytes_10186(kk_std_core_types__new_Nil(_ctx), _uniq_xs_10125, _x_x509, _ctx);
}
 
// lifted local: @lift-decodeOne@10187, bytes, decodeOne, @spec-x10157
// specialized: std/core/list/@lift-flatmap@6013, on parameters @uniq-f@10145, using:
// @uniq-f@10145 = fn(c@0: nagare/io/file/bytes){
//   std/core/vector/vlist<int8>(c@0, (std/core/types/@None<(list :: V -> V)<int8>>));
// }

kk_std_core_types__list kk_examples_image__pipeline__trmc_lift_decodeOne_10188(kk_std_core_types__list _uniq_ys_10146, kk_std_core_types__list _uniq_zs_10147, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* (list<int8>, list<nagare/io/file/bytes>, ctx<list<int8>>) -> list<int8> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_ys_10146, _ctx)) {
    struct kk_std_core_types_Cons* _con_x510 = kk_std_core_types__as_Cons(_uniq_ys_10146, _ctx);
    kk_box_t _box_x22 = _con_x510->head;
    kk_std_core_types__list _uniq_yy_10150 = _con_x510->tail;
    int8_t _uniq_y_10149 = kk_int8_unbox(_box_x22, KK_BORROWED, _ctx);
    kk_reuse_t _ru_x498 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_ys_10146, _ctx)) {
      _ru_x498 = (kk_datatype_ptr_reuse(_uniq_ys_10146, _ctx));
    }
    else {
      kk_std_core_types__list_dup(_uniq_yy_10150, _ctx);
      kk_datatype_ptr_decref(_uniq_ys_10146, _ctx);
    }
    kk_std_core_types__list _trmc_x10195 = kk_datatype_null(); /*list<int8>*/;
    kk_std_core_types__list _trmc_x10196 = kk_std_core_types__new_Cons(_ru_x498, 0, kk_int8_box(_uniq_y_10149, _ctx), _trmc_x10195, _ctx); /*list<int8>*/;
    kk_field_addr_t _b_x32_38 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10196, _ctx)->tail, _ctx); /*@field-addr<list<int8>>*/;
    { // tailcall
      kk_std_core_types__cctx _x_x511 = kk_cctx_extend_linear(_acc,(kk_std_core_types__list_box(_trmc_x10196, _ctx)),_b_x32_38,kk_context()); /*ctx<0>*/
      _uniq_ys_10146 = _uniq_yy_10150;
      _acc = _x_x511;
      goto kk__tailcall;
    }
  }
  if (kk_std_core_types__is_Cons(_uniq_zs_10147, _ctx)) {
    struct kk_std_core_types_Cons* _con_x512 = kk_std_core_types__as_Cons(_uniq_zs_10147, _ctx);
    kk_box_t _box_x33 = _con_x512->head;
    kk_std_core_types__list _uniq_zz_10154 = _con_x512->tail;
    kk_vector_t _uniq_z_10153 = kk_vector_unbox(_box_x33, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_zs_10147, _ctx)) {
      kk_datatype_ptr_free(_uniq_zs_10147, _ctx);
    }
    else {
      kk_vector_dup(_uniq_z_10153, _ctx);
      kk_std_core_types__list_dup(_uniq_zz_10154, _ctx);
      kk_datatype_ptr_decref(_uniq_zs_10147, _ctx);
    }
    kk_std_core_types__list _uniq_ys_1_10132_10155 = kk_std_core_vector_vlist(_uniq_z_10153, kk_std_core_types__new_None(_ctx), _ctx); /*list<int8>*/;
    { // tailcall
      _uniq_ys_10146 = _uniq_ys_1_10132_10155;
      _uniq_zs_10147 = _uniq_zz_10154;
      goto kk__tailcall;
    }
  }
  {
    kk_box_t _x_x513 = kk_cctx_apply_linear(_acc,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x513, KK_OWNED, _ctx);
  }
}
 
// lifted local: @lift-decodeOne@10187, bytes, decodeOne, @spec-x10157
// specialized: std/core/list/@lift-flatmap@6013, on parameters @uniq-f@10145, using:
// @uniq-f@10145 = fn(c@0: nagare/io/file/bytes){
//   std/core/vector/vlist<int8>(c@0, (std/core/types/@None<(list :: V -> V)<int8>>));
// }

kk_std_core_types__list kk_examples_image__pipeline__lift_decodeOne_10188(kk_std_core_types__list _uniq_ys_10146_0, kk_std_core_types__list _uniq_zs_10147_0, kk_context_t* _ctx) { /* (list<int8>, list<nagare/io/file/bytes>) -> list<int8> */ 
  kk_std_core_types__cctx _x_x514 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_examples_image__pipeline__trmc_lift_decodeOne_10188(_uniq_ys_10146_0, _uniq_zs_10147_0, _x_x514, _ctx);
}
 
// lifted local: bytes, decodeOne, @spec-x10144
// specialized: std/core/list/flatmap, on parameters @uniq-f@10143, using:
// @uniq-f@10143 = fn(c@0: nagare/io/file/bytes){
//   std/core/vector/vlist<int8>(c@0, (std/core/types/@None<(list :: V -> V)<int8>>));
// }

kk_std_core_types__list kk_examples_image__pipeline__lift_decodeOne_10187(kk_std_core_types__list _uniq_xs_10142, kk_context_t* _ctx) { /* (list<nagare/io/file/bytes>) -> list<int8> */ 
  kk_std_core_types__cctx _x_x515 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_examples_image__pipeline__trmc_lift_decodeOne_10188(kk_std_core_types__new_Nil(_ctx), _uniq_xs_10142, _x_x515, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_examples_image__pipeline__mlift_decodeOne_10302_fun517__t {
  struct kk_function_s _base;
  kk_integer_t h;
  kk_vector_t px;
  kk_integer_t w;
};
static kk_box_t kk_examples_image__pipeline__mlift_decodeOne_10302_fun517(kk_function_t _fself, kk_box_t _b_x45, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline__new_mlift_decodeOne_10302_fun517(kk_integer_t h, kk_vector_t px, kk_integer_t w, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline__mlift_decodeOne_10302_fun517__t* _self = kk_function_alloc_as(struct kk_examples_image__pipeline__mlift_decodeOne_10302_fun517__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_examples_image__pipeline__mlift_decodeOne_10302_fun517, kk_context());
  _self->h = h;
  _self->px = px;
  _self->w = w;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_examples_image__pipeline__mlift_decodeOne_10302_fun517(kk_function_t _fself, kk_box_t _b_x45, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline__mlift_decodeOne_10302_fun517__t* _self = kk_function_as(struct kk_examples_image__pipeline__mlift_decodeOne_10302_fun517__t*, _fself, _ctx);
  kk_integer_t h = _self->h; /* int */
  kk_vector_t px = _self->px; /* vector<int8> */
  kk_integer_t w = _self->w; /* int */
  kk_drop_match(_self, {kk_integer_dup(h, _ctx);kk_vector_dup(px, _ctx);kk_integer_dup(w, _ctx);}, {}, _ctx)
  kk_integer_t c_1_47 = kk_integer_unbox(_b_x45, _ctx); /*int*/;
  kk_nagare_io_image__effect__image _x_x518 = kk_nagare_io_image__effect__new_Image(w, h, c_1_47, px, _ctx); /*nagare/io/image_effect/image*/
  return kk_nagare_io_image__effect__image_box(_x_x518, _ctx);
}

kk_nagare_io_image__effect__image kk_examples_image__pipeline__mlift_decodeOne_10302(kk_vector_t px, kk_integer_t w, kk_integer_t h, kk_context_t* _ctx) { /* (px : vector<int8>, w : int, h : int) -> io nagare/io/image_effect/image */ 
  kk_integer_t x_10324 = kk_nagare_io_image__effect_nagare_image_last_channels(kk_Unit, _ctx); /*int*/;
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_10324, _ctx);
    kk_box_t _x_x516 = kk_std_core_hnd_yield_extend(kk_examples_image__pipeline__new_mlift_decodeOne_10302_fun517(h, px, w, _ctx), _ctx); /*10001*/
    return kk_nagare_io_image__effect__image_unbox(_x_x516, KK_OWNED, _ctx);
  }
  {
    return kk_nagare_io_image__effect__new_Image(w, h, x_10324, px, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_examples_image__pipeline__mlift_decodeOne_10303_fun520__t {
  struct kk_function_s _base;
  kk_vector_t px;
  kk_integer_t w;
};
static kk_box_t kk_examples_image__pipeline__mlift_decodeOne_10303_fun520(kk_function_t _fself, kk_box_t _b_x49, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline__new_mlift_decodeOne_10303_fun520(kk_vector_t px, kk_integer_t w, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline__mlift_decodeOne_10303_fun520__t* _self = kk_function_alloc_as(struct kk_examples_image__pipeline__mlift_decodeOne_10303_fun520__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_examples_image__pipeline__mlift_decodeOne_10303_fun520, kk_context());
  _self->px = px;
  _self->w = w;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_examples_image__pipeline__mlift_decodeOne_10303_fun520(kk_function_t _fself, kk_box_t _b_x49, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline__mlift_decodeOne_10303_fun520__t* _self = kk_function_as(struct kk_examples_image__pipeline__mlift_decodeOne_10303_fun520__t*, _fself, _ctx);
  kk_vector_t px = _self->px; /* vector<int8> */
  kk_integer_t w = _self->w; /* int */
  kk_drop_match(_self, {kk_vector_dup(px, _ctx);kk_integer_dup(w, _ctx);}, {}, _ctx)
  kk_integer_t h_51 = kk_integer_unbox(_b_x49, _ctx); /*int*/;
  kk_nagare_io_image__effect__image _x_x521 = kk_examples_image__pipeline__mlift_decodeOne_10302(px, w, h_51, _ctx); /*nagare/io/image_effect/image*/
  return kk_nagare_io_image__effect__image_box(_x_x521, _ctx);
}

kk_nagare_io_image__effect__image kk_examples_image__pipeline__mlift_decodeOne_10303(kk_vector_t px, kk_integer_t w, kk_context_t* _ctx) { /* (px : vector<int8>, w : int) -> io nagare/io/image_effect/image */ 
  kk_integer_t x_10330 = kk_nagare_io_image__effect_nagare_image_last_height(kk_Unit, _ctx); /*int*/;
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_10330, _ctx);
    kk_box_t _x_x519 = kk_std_core_hnd_yield_extend(kk_examples_image__pipeline__new_mlift_decodeOne_10303_fun520(px, w, _ctx), _ctx); /*10001*/
    return kk_nagare_io_image__effect__image_unbox(_x_x519, KK_OWNED, _ctx);
  }
  {
    return kk_examples_image__pipeline__mlift_decodeOne_10302(px, w, x_10330, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_examples_image__pipeline__mlift_decodeOne_10304_fun523__t {
  struct kk_function_s _base;
  kk_vector_t px;
};
static kk_box_t kk_examples_image__pipeline__mlift_decodeOne_10304_fun523(kk_function_t _fself, kk_box_t _b_x53, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline__new_mlift_decodeOne_10304_fun523(kk_vector_t px, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline__mlift_decodeOne_10304_fun523__t* _self = kk_function_alloc_as(struct kk_examples_image__pipeline__mlift_decodeOne_10304_fun523__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_examples_image__pipeline__mlift_decodeOne_10304_fun523, kk_context());
  _self->px = px;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_examples_image__pipeline__mlift_decodeOne_10304_fun523(kk_function_t _fself, kk_box_t _b_x53, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline__mlift_decodeOne_10304_fun523__t* _self = kk_function_as(struct kk_examples_image__pipeline__mlift_decodeOne_10304_fun523__t*, _fself, _ctx);
  kk_vector_t px = _self->px; /* vector<int8> */
  kk_drop_match(_self, {kk_vector_dup(px, _ctx);}, {}, _ctx)
  kk_integer_t w_55 = kk_integer_unbox(_b_x53, _ctx); /*int*/;
  kk_nagare_io_image__effect__image _x_x524 = kk_examples_image__pipeline__mlift_decodeOne_10303(px, w_55, _ctx); /*nagare/io/image_effect/image*/
  return kk_nagare_io_image__effect__image_box(_x_x524, _ctx);
}

kk_nagare_io_image__effect__image kk_examples_image__pipeline__mlift_decodeOne_10304(kk_vector_t px, kk_context_t* _ctx) { /* (px : vector<int8>) -> io nagare/io/image_effect/image */ 
  kk_integer_t x_10332 = kk_nagare_io_image__effect_nagare_image_last_width(kk_Unit, _ctx); /*int*/;
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_10332, _ctx);
    kk_box_t _x_x522 = kk_std_core_hnd_yield_extend(kk_examples_image__pipeline__new_mlift_decodeOne_10304_fun523(px, _ctx), _ctx); /*10001*/
    return kk_nagare_io_image__effect__image_unbox(_x_x522, KK_OWNED, _ctx);
  }
  {
    return kk_examples_image__pipeline__mlift_decodeOne_10303(px, x_10332, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_examples_image__pipeline__mlift_decodeOne_10306_fun527__t {
  struct kk_function_s _base;
  kk_nagare_core_interpreter__runtime state;
};
static kk_unit_t kk_examples_image__pipeline__mlift_decodeOne_10306_fun527(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline__new_mlift_decodeOne_10306_fun527(kk_nagare_core_interpreter__runtime state, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline__mlift_decodeOne_10306_fun527__t* _self = kk_function_alloc_as(struct kk_examples_image__pipeline__mlift_decodeOne_10306_fun527__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_examples_image__pipeline__mlift_decodeOne_10306_fun527, kk_context());
  _self->state = state;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_unit_t kk_examples_image__pipeline__mlift_decodeOne_10306_fun527(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline__mlift_decodeOne_10306_fun527__t* _self = kk_function_as(struct kk_examples_image__pipeline__mlift_decodeOne_10306_fun527__t*, _fself, _ctx);
  kk_nagare_core_interpreter__runtime state = _self->state; /* nagare/core/interpreter/runtime<nagare/io/file/bytes,nagare/io/file_effect/fileRead> */
  kk_drop_match(_self, {kk_nagare_core_interpreter__runtime_dup(state, _ctx);}, {}, _ctx)
  kk_nagare_core_interpreter_closeRuntime(state, _ctx); return kk_Unit;
}

kk_std_core_types__list kk_examples_image__pipeline__mlift_decodeOne_10306(kk_nagare_core_interpreter__runtime state, kk_context_t* _ctx) { /* (state : nagare/core/interpreter/runtime<nagare/io/file/bytes,nagare/io/file_effect/fileRead>) -> <io,nagare/io/file_effect/fileRead> list<nagare/io/file/bytes> */ 
  kk_std_core_types__list _b_x59_61;
  kk_nagare_core_interpreter__runtime _x_x525 = kk_nagare_core_interpreter__runtime_dup(state, _ctx); /*nagare/core/interpreter/runtime<nagare/io/file/bytes,nagare/io/file_effect/fileRead>*/
  _b_x59_61 = kk_nagare_core_interpreter_collectRuntime(_x_x525, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<nagare/io/file/bytes>*/
  kk_box_t _x_x526 = kk_std_core_hnd_finally_prompt(kk_examples_image__pipeline__new_mlift_decodeOne_10306_fun527(state, _ctx), kk_std_core_types__list_box(_b_x59_61, _ctx), _ctx); /*10000*/
  return kk_std_core_types__list_unbox(_x_x526, KK_OWNED, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_examples_image__pipeline__mlift_decodeOne_10307_fun530__t {
  struct kk_function_s _base;
};
static kk_box_t kk_examples_image__pipeline__mlift_decodeOne_10307_fun530(kk_function_t _fself, kk_box_t _b_x65, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline__new_mlift_decodeOne_10307_fun530(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_examples_image__pipeline__mlift_decodeOne_10307_fun530, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_examples_image__pipeline__mlift_decodeOne_10307_fun533__t {
  struct kk_function_s _base;
};
static kk_box_t kk_examples_image__pipeline__mlift_decodeOne_10307_fun533(kk_function_t _fself, kk_box_t _b_x63, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline__new_mlift_decodeOne_10307_fun533(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_examples_image__pipeline__mlift_decodeOne_10307_fun533, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_examples_image__pipeline__mlift_decodeOne_10307_fun533(kk_function_t _fself, kk_box_t _b_x63, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_nagare_io_image__effect__image _x_x534;
  kk_vector_t _x_x535 = kk_vector_unbox(_b_x63, _ctx); /*vector<int8>*/
  _x_x534 = kk_examples_image__pipeline__mlift_decodeOne_10304(_x_x535, _ctx); /*nagare/io/image_effect/image*/
  return kk_nagare_io_image__effect__image_box(_x_x534, _ctx);
}
static kk_box_t kk_examples_image__pipeline__mlift_decodeOne_10307_fun530(kk_function_t _fself, kk_box_t _b_x65, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_nagare_io_image__effect__image _x_x531;
  kk_vector_t input_104 = kk_vector_unbox(_b_x65, _ctx); /*vector<int8>*/;
  kk_vector_t x_0_10338 = kk_nagare_io_image__effect_nagare_image_decode_bytes(input_104, _ctx); /*vector<int8>*/;
  if (kk_yielding(kk_context())) {
    kk_vector_drop(x_0_10338, _ctx);
    kk_box_t _x_x532 = kk_std_core_hnd_yield_extend(kk_examples_image__pipeline__new_mlift_decodeOne_10307_fun533(_ctx), _ctx); /*10001*/
    _x_x531 = kk_nagare_io_image__effect__image_unbox(_x_x532, KK_OWNED, _ctx); /*nagare/io/image_effect/image*/
  }
  else {
    _x_x531 = kk_examples_image__pipeline__mlift_decodeOne_10304(x_0_10338, _ctx); /*nagare/io/image_effect/image*/
  }
  return kk_nagare_io_image__effect__image_box(_x_x531, _ctx);
}


// lift anonymous function
struct kk_examples_image__pipeline__mlift_decodeOne_10307_fun537__t {
  struct kk_function_s _base;
};
static kk_box_t kk_examples_image__pipeline__mlift_decodeOne_10307_fun537(kk_function_t _fself, kk_box_t _b_x94, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline__new_mlift_decodeOne_10307_fun537(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_examples_image__pipeline__mlift_decodeOne_10307_fun537, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_examples_image__pipeline__mlift_decodeOne_10307_fun537(kk_function_t _fself, kk_box_t _b_x94, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__maybe _res_103 = kk_std_core_types__maybe_unbox(_b_x94, KK_OWNED, _ctx); /*maybe<nagare/io/image_effect/image>*/;
  return kk_std_core_types__maybe_box(_res_103, _ctx);
}


// lift anonymous function
struct kk_examples_image__pipeline__mlift_decodeOne_10307_fun538__t {
  struct kk_function_s _base;
  kk_vector_t x;
};
static kk_box_t kk_examples_image__pipeline__mlift_decodeOne_10307_fun538(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline__new_mlift_decodeOne_10307_fun538(kk_vector_t x, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline__mlift_decodeOne_10307_fun538__t* _self = kk_function_alloc_as(struct kk_examples_image__pipeline__mlift_decodeOne_10307_fun538__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_examples_image__pipeline__mlift_decodeOne_10307_fun538, kk_context());
  _self->x = x;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_examples_image__pipeline__mlift_decodeOne_10307_fun542__t {
  struct kk_function_s _base;
  kk_ssize_t i_10342;
};
static kk_box_t kk_examples_image__pipeline__mlift_decodeOne_10307_fun542(kk_function_t _fself, kk_function_t _b_x79, kk_box_t _b_x80, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline__new_mlift_decodeOne_10307_fun542(kk_ssize_t i_10342, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline__mlift_decodeOne_10307_fun542__t* _self = kk_function_alloc_as(struct kk_examples_image__pipeline__mlift_decodeOne_10307_fun542__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_examples_image__pipeline__mlift_decodeOne_10307_fun542, kk_context());
  _self->i_10342 = i_10342;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_examples_image__pipeline__mlift_decodeOne_10307_fun542(kk_function_t _fself, kk_function_t _b_x79, kk_box_t _b_x80, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline__mlift_decodeOne_10307_fun542__t* _self = kk_function_as(struct kk_examples_image__pipeline__mlift_decodeOne_10307_fun542__t*, _fself, _ctx);
  kk_ssize_t i_10342 = _self->i_10342; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_10342, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_10342, _b_x79, _b_x80, _ctx);
}


// lift anonymous function
struct kk_examples_image__pipeline__mlift_decodeOne_10307_fun545__t {
  struct kk_function_s _base;
};
static kk_box_t kk_examples_image__pipeline__mlift_decodeOne_10307_fun545(kk_function_t _fself, kk_box_t _b_x89, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline__new_mlift_decodeOne_10307_fun545(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_examples_image__pipeline__mlift_decodeOne_10307_fun545, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_examples_image__pipeline__mlift_decodeOne_10307_fun545(kk_function_t _fself, kk_box_t _b_x89, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__maybe _x_x546;
  kk_nagare_io_image__effect__image _x_x547 = kk_nagare_io_image__effect__image_unbox(_b_x89, KK_OWNED, _ctx); /*nagare/io/image_effect/image*/
  _x_x546 = kk_examples_image__pipeline__mlift_decodeOne_10305(_x_x547, _ctx); /*maybe<nagare/io/image_effect/image>*/
  return kk_std_core_types__maybe_box(_x_x546, _ctx);
}
static kk_box_t kk_examples_image__pipeline__mlift_decodeOne_10307_fun538(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline__mlift_decodeOne_10307_fun538__t* _self = kk_function_as(struct kk_examples_image__pipeline__mlift_decodeOne_10307_fun538__t*, _fself, _ctx);
  kk_vector_t x = _self->x; /* nagare/io/file/bytes */
  kk_drop_match(_self, {kk_vector_dup(x, _ctx);}, {}, _ctx)
  kk_ssize_t i_10342 = (KK_IZ(1)); /*hnd/ev-index*/;
  kk_evv_t w_0 = kk_evv_swap_create1(i_10342,kk_context()); /*hnd/evv<<nagare/io/image_effect/imageDecode,alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_std_core_hnd__ev ev_10345 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<nagare/io/image_effect/imageDecode>*/;
  kk_nagare_io_image__effect__image y;
  kk_box_t _x_x539;
  {
    struct kk_std_core_hnd_Ev* _con_x540 = kk_std_core_hnd__as_Ev(ev_10345, _ctx);
    kk_box_t _box_x66 = _con_x540->hnd;
    int32_t m = _con_x540->marker;
    kk_nagare_io_image__effect__imageDecode h = kk_nagare_io_image__effect__imageDecode_unbox(_box_x66, KK_BORROWED, _ctx);
    kk_nagare_io_image__effect__imageDecode_dup(h, _ctx);
    kk_std_core_hnd__clause1 _match_x488;
    kk_std_core_hnd__clause1 _brw_x489 = kk_nagare_io_image__effect_decodeImageBytes_fs__select(h, _ctx); /*hnd/clause1<vector<int8>,nagare/io/image_effect/image,nagare/io/image_effect/imageDecode,465,466>*/;
    kk_datatype_ptr_dropn(h, (KK_I32(2)), _ctx);
    _match_x488 = _brw_x489; /*hnd/clause1<vector<int8>,nagare/io/image_effect/image,nagare/io/image_effect/imageDecode,465,466>*/
    {
      kk_function_t _fun_unbox_x70 = _match_x488.clause;
      _x_x539 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x70, (_fun_unbox_x70, m, ev_10345, kk_vector_box(x, _ctx), _ctx), _ctx); /*10010*/
    }
  }
  y = kk_nagare_io_image__effect__image_unbox(_x_x539, KK_OWNED, _ctx); /*nagare/io/image_effect/image*/
  kk_evv_set(w_0,kk_context());
  kk_nagare_io_image__effect__image x_1_10340;
  if (kk_yielding(kk_context())) {
    kk_nagare_io_image__effect__image_drop(y, _ctx);
    kk_box_t _x_x541 = kk_std_core_hnd_yield_cont(kk_examples_image__pipeline__new_mlift_decodeOne_10307_fun542(i_10342, _ctx), _ctx); /*10002*/
    x_1_10340 = kk_nagare_io_image__effect__image_unbox(_x_x541, KK_OWNED, _ctx); /*nagare/io/image_effect/image*/
  }
  else {
    x_1_10340 = y; /*nagare/io/image_effect/image*/
  }
  kk_std_core_types__maybe _x_x543;
  if (kk_yielding(kk_context())) {
    kk_nagare_io_image__effect__image_drop(x_1_10340, _ctx);
    kk_box_t _x_x544 = kk_std_core_hnd_yield_extend(kk_examples_image__pipeline__new_mlift_decodeOne_10307_fun545(_ctx), _ctx); /*10001*/
    _x_x543 = kk_std_core_types__maybe_unbox(_x_x544, KK_OWNED, _ctx); /*maybe<nagare/io/image_effect/image>*/
  }
  else {
    _x_x543 = kk_std_core_types__new_Just(kk_nagare_io_image__effect__image_box(x_1_10340, _ctx), _ctx); /*maybe<nagare/io/image_effect/image>*/
  }
  return kk_std_core_types__maybe_box(_x_x543, _ctx);
}

kk_std_core_types__maybe kk_examples_image__pipeline__mlift_decodeOne_10307(kk_std_core_types__list chunks, kk_context_t* _ctx) { /* (chunks : list<nagare/io/file/bytes>) -> io maybe<nagare/io/image_effect/image> */ 
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_std_core_types__list xs_10002 = kk_examples_image__pipeline__lift_decodeOne_10187(chunks, _ctx); /*list<int8>*/;
  kk_vector_t x = kk_std_core_vector_unvlist(xs_10002, _ctx); /*nagare/io/file/bytes*/;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  bool _match_x485;
  kk_integer_t _brw_x491;
  kk_ssize_t _x_x528 = kk_vector_len_borrow(x,kk_context()); /*ssize_t*/
  _brw_x491 = kk_integer_from_ssize_t(_x_x528,kk_context()); /*int*/
  bool _brw_x492 = kk_integer_eq_borrow(_brw_x491,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x491, _ctx);
  _match_x485 = _brw_x492; /*bool*/
  if (_match_x485) {
    kk_vector_drop(x, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
  {
    kk_nagare_io_image__effect__imageDecode _b_x91_95;
    kk_std_core_hnd__clause1 _x_x529 = kk_std_core_hnd_clause_tail1(kk_examples_image__pipeline__new_mlift_decodeOne_10307_fun530(_ctx), _ctx); /*hnd/clause1<10003,10004,10002,10000,10001>*/
    _b_x91_95 = kk_nagare_io_image__effect__new_Hnd_imageDecode(kk_reuse_null, 0, kk_integer_from_small(1), _x_x529, _ctx); /*nagare/io/image_effect/imageDecode<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>,maybe<nagare/io/image_effect/image>>*/
    kk_box_t _x_x536 = kk_nagare_io_image__effect_imageDecode_fs__handle(_b_x91_95, kk_examples_image__pipeline__new_mlift_decodeOne_10307_fun537(_ctx), kk_examples_image__pipeline__new_mlift_decodeOne_10307_fun538(x, _ctx), _ctx); /*404*/
    return kk_std_core_types__maybe_unbox(_x_x536, KK_OWNED, _ctx);
  }
}
 
// Read + decode a single image, with each capability discharged locally.
// We split the read and decode phases so that each `with` block sees only
// one capability — the library's default handlers each pin their action's
// row to a single `<X|io>`, so they can't be stacked at the same site.
//
// Phase 1: under `defaultFileRead`, collect all byte chunks into a list and
//          flatten them into one buffer.
// Phase 2: under `defaultImageDecode`, run the decoder on those bytes.
//
// The outer pipeline sees only `io`, so it composes with any combinator.


// lift anonymous function
struct kk_examples_image__pipeline_decodeOne_fun549__t {
  struct kk_function_s _base;
  kk_std_os_path__path p;
};
static kk_box_t kk_examples_image__pipeline_decodeOne_fun549(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline_new_decodeOne_fun549(kk_std_os_path__path p, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline_decodeOne_fun549__t* _self = kk_function_alloc_as(struct kk_examples_image__pipeline_decodeOne_fun549__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_examples_image__pipeline_decodeOne_fun549, kk_context());
  _self->p = p;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_examples_image__pipeline_decodeOne_fun552__t {
  struct kk_function_s _base;
};
static kk_box_t kk_examples_image__pipeline_decodeOne_fun552(kk_function_t _fself, kk_box_t _b_x106, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline_new_decodeOne_fun552(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_examples_image__pipeline_decodeOne_fun552, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_examples_image__pipeline_decodeOne_fun552(kk_function_t _fself, kk_box_t _b_x106, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__list _x_x553;
  kk_nagare_core_interpreter__runtime _x_x554 = kk_nagare_core_interpreter__runtime_unbox(_b_x106, KK_OWNED, _ctx); /*nagare/core/interpreter/runtime<nagare/io/file/bytes,nagare/io/file_effect/fileRead>*/
  _x_x553 = kk_examples_image__pipeline__mlift_decodeOne_10306(_x_x554, _ctx); /*list<nagare/io/file/bytes>*/
  return kk_std_core_types__list_box(_x_x553, _ctx);
}


// lift anonymous function
struct kk_examples_image__pipeline_decodeOne_fun557__t {
  struct kk_function_s _base;
  kk_nagare_core_interpreter__runtime x_2_10355;
};
static kk_unit_t kk_examples_image__pipeline_decodeOne_fun557(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline_new_decodeOne_fun557(kk_nagare_core_interpreter__runtime x_2_10355, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline_decodeOne_fun557__t* _self = kk_function_alloc_as(struct kk_examples_image__pipeline_decodeOne_fun557__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_examples_image__pipeline_decodeOne_fun557, kk_context());
  _self->x_2_10355 = x_2_10355;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_unit_t kk_examples_image__pipeline_decodeOne_fun557(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline_decodeOne_fun557__t* _self = kk_function_as(struct kk_examples_image__pipeline_decodeOne_fun557__t*, _fself, _ctx);
  kk_nagare_core_interpreter__runtime x_2_10355 = _self->x_2_10355; /* nagare/core/interpreter/runtime<nagare/io/file/bytes,nagare/io/file_effect/fileRead> */
  kk_drop_match(_self, {kk_nagare_core_interpreter__runtime_dup(x_2_10355, _ctx);}, {}, _ctx)
  kk_nagare_core_interpreter_closeRuntime(x_2_10355, _ctx); return kk_Unit;
}
static kk_box_t kk_examples_image__pipeline_decodeOne_fun549(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline_decodeOne_fun549__t* _self = kk_function_as(struct kk_examples_image__pipeline_decodeOne_fun549__t*, _fself, _ctx);
  kk_std_os_path__path p = _self->p; /* std/os/path/path */
  kk_drop_match(_self, {kk_std_os_path__path_dup(p, _ctx);}, {}, _ctx)
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileRead,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_nagare_core_types__nstream x_0 = kk_nagare_io_file_readAllStreamingBytes(p, kk_std_core_types__new_None(_ctx), _ctx); /*nagare/io/file_effect/readStream<nagare/io/file/bytes>*/;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>,nagare/io/file_effect/fileRead>>*/;
  kk_unit_t keep_0 = kk_Unit;
  kk_evv_set(w_0,kk_context());
  kk_nagare_core_interpreter__runtime x_2_10355 = kk_nagare_core_interpreter_runtimeFromStream(x_0, _ctx); /*nagare/core/interpreter/runtime<nagare/io/file/bytes,nagare/io/file_effect/fileRead>*/;
  kk_std_core_types__list _x_x550;
  if (kk_yielding(kk_context())) {
    kk_datatype_ptr_dropn(x_2_10355, (KK_I32(2)), _ctx);
    kk_box_t _x_x551 = kk_std_core_hnd_yield_extend(kk_examples_image__pipeline_new_decodeOne_fun552(_ctx), _ctx); /*10001*/
    _x_x550 = kk_std_core_types__list_unbox(_x_x551, KK_OWNED, _ctx); /*list<nagare/io/file/bytes>*/
  }
  else {
    kk_std_core_types__list _b_x108_113;
    kk_nagare_core_interpreter__runtime _x_x555 = kk_nagare_core_interpreter__runtime_dup(x_2_10355, _ctx); /*nagare/core/interpreter/runtime<nagare/io/file/bytes,nagare/io/file_effect/fileRead>*/
    _b_x108_113 = kk_nagare_core_interpreter_collectRuntime(_x_x555, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<nagare/io/file/bytes>*/
    kk_box_t _x_x556 = kk_std_core_hnd_finally_prompt(kk_examples_image__pipeline_new_decodeOne_fun557(x_2_10355, _ctx), kk_std_core_types__list_box(_b_x108_113, _ctx), _ctx); /*10000*/
    _x_x550 = kk_std_core_types__list_unbox(_x_x556, KK_OWNED, _ctx); /*list<nagare/io/file/bytes>*/
  }
  return kk_std_core_types__list_box(_x_x550, _ctx);
}


// lift anonymous function
struct kk_examples_image__pipeline_decodeOne_fun559__t {
  struct kk_function_s _base;
};
static kk_box_t kk_examples_image__pipeline_decodeOne_fun559(kk_function_t _fself, kk_box_t _b_x115, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline_new_decodeOne_fun559(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_examples_image__pipeline_decodeOne_fun559, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_examples_image__pipeline_decodeOne_fun559(kk_function_t _fself, kk_box_t _b_x115, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__maybe _x_x560;
  kk_std_core_types__list _x_x561 = kk_std_core_types__list_unbox(_b_x115, KK_OWNED, _ctx); /*list<nagare/io/file/bytes>*/
  _x_x560 = kk_examples_image__pipeline__mlift_decodeOne_10307(_x_x561, _ctx); /*maybe<nagare/io/image_effect/image>*/
  return kk_std_core_types__maybe_box(_x_x560, _ctx);
}


// lift anonymous function
struct kk_examples_image__pipeline_decodeOne_fun564__t {
  struct kk_function_s _base;
};
static kk_box_t kk_examples_image__pipeline_decodeOne_fun564(kk_function_t _fself, kk_box_t _b_x119, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline_new_decodeOne_fun564(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_examples_image__pipeline_decodeOne_fun564, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_examples_image__pipeline_decodeOne_fun567__t {
  struct kk_function_s _base;
};
static kk_box_t kk_examples_image__pipeline_decodeOne_fun567(kk_function_t _fself, kk_box_t _b_x117, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline_new_decodeOne_fun567(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_examples_image__pipeline_decodeOne_fun567, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_examples_image__pipeline_decodeOne_fun567(kk_function_t _fself, kk_box_t _b_x117, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_nagare_io_image__effect__image _x_x568;
  kk_vector_t _x_x569 = kk_vector_unbox(_b_x117, _ctx); /*vector<int8>*/
  _x_x568 = kk_examples_image__pipeline__mlift_decodeOne_10304(_x_x569, _ctx); /*nagare/io/image_effect/image*/
  return kk_nagare_io_image__effect__image_box(_x_x568, _ctx);
}
static kk_box_t kk_examples_image__pipeline_decodeOne_fun564(kk_function_t _fself, kk_box_t _b_x119, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_nagare_io_image__effect__image _x_x565;
  kk_vector_t input_159 = kk_vector_unbox(_b_x119, _ctx); /*vector<int8>*/;
  kk_vector_t x_4_10359 = kk_nagare_io_image__effect_nagare_image_decode_bytes(input_159, _ctx); /*vector<int8>*/;
  if (kk_yielding(kk_context())) {
    kk_vector_drop(x_4_10359, _ctx);
    kk_box_t _x_x566 = kk_std_core_hnd_yield_extend(kk_examples_image__pipeline_new_decodeOne_fun567(_ctx), _ctx); /*10001*/
    _x_x565 = kk_nagare_io_image__effect__image_unbox(_x_x566, KK_OWNED, _ctx); /*nagare/io/image_effect/image*/
  }
  else {
    _x_x565 = kk_examples_image__pipeline__mlift_decodeOne_10304(x_4_10359, _ctx); /*nagare/io/image_effect/image*/
  }
  return kk_nagare_io_image__effect__image_box(_x_x565, _ctx);
}


// lift anonymous function
struct kk_examples_image__pipeline_decodeOne_fun571__t {
  struct kk_function_s _base;
};
static kk_box_t kk_examples_image__pipeline_decodeOne_fun571(kk_function_t _fself, kk_box_t _b_x148, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline_new_decodeOne_fun571(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_examples_image__pipeline_decodeOne_fun571, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_examples_image__pipeline_decodeOne_fun571(kk_function_t _fself, kk_box_t _b_x148, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__maybe _res_158 = kk_std_core_types__maybe_unbox(_b_x148, KK_OWNED, _ctx); /*maybe<nagare/io/image_effect/image>*/;
  return kk_std_core_types__maybe_box(_res_158, _ctx);
}


// lift anonymous function
struct kk_examples_image__pipeline_decodeOne_fun572__t {
  struct kk_function_s _base;
  kk_vector_t x_3;
};
static kk_box_t kk_examples_image__pipeline_decodeOne_fun572(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline_new_decodeOne_fun572(kk_vector_t x_3, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline_decodeOne_fun572__t* _self = kk_function_alloc_as(struct kk_examples_image__pipeline_decodeOne_fun572__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_examples_image__pipeline_decodeOne_fun572, kk_context());
  _self->x_3 = x_3;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_examples_image__pipeline_decodeOne_fun576__t {
  struct kk_function_s _base;
  kk_ssize_t i_10363;
};
static kk_box_t kk_examples_image__pipeline_decodeOne_fun576(kk_function_t _fself, kk_function_t _b_x133, kk_box_t _b_x134, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline_new_decodeOne_fun576(kk_ssize_t i_10363, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline_decodeOne_fun576__t* _self = kk_function_alloc_as(struct kk_examples_image__pipeline_decodeOne_fun576__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_examples_image__pipeline_decodeOne_fun576, kk_context());
  _self->i_10363 = i_10363;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_examples_image__pipeline_decodeOne_fun576(kk_function_t _fself, kk_function_t _b_x133, kk_box_t _b_x134, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline_decodeOne_fun576__t* _self = kk_function_as(struct kk_examples_image__pipeline_decodeOne_fun576__t*, _fself, _ctx);
  kk_ssize_t i_10363 = _self->i_10363; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_10363, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_10363, _b_x133, _b_x134, _ctx);
}


// lift anonymous function
struct kk_examples_image__pipeline_decodeOne_fun579__t {
  struct kk_function_s _base;
};
static kk_box_t kk_examples_image__pipeline_decodeOne_fun579(kk_function_t _fself, kk_box_t _b_x143, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline_new_decodeOne_fun579(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_examples_image__pipeline_decodeOne_fun579, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_examples_image__pipeline_decodeOne_fun579(kk_function_t _fself, kk_box_t _b_x143, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__maybe _x_x580;
  kk_nagare_io_image__effect__image _x_x581 = kk_nagare_io_image__effect__image_unbox(_b_x143, KK_OWNED, _ctx); /*nagare/io/image_effect/image*/
  _x_x580 = kk_examples_image__pipeline__mlift_decodeOne_10305(_x_x581, _ctx); /*maybe<nagare/io/image_effect/image>*/
  return kk_std_core_types__maybe_box(_x_x580, _ctx);
}
static kk_box_t kk_examples_image__pipeline_decodeOne_fun572(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline_decodeOne_fun572__t* _self = kk_function_as(struct kk_examples_image__pipeline_decodeOne_fun572__t*, _fself, _ctx);
  kk_vector_t x_3 = _self->x_3; /* nagare/io/file/bytes */
  kk_drop_match(_self, {kk_vector_dup(x_3, _ctx);}, {}, _ctx)
  kk_ssize_t i_10363 = (KK_IZ(1)); /*hnd/ev-index*/;
  kk_evv_t w_2 = kk_evv_swap_create1(i_10363,kk_context()); /*hnd/evv<<nagare/io/image_effect/imageDecode,alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_std_core_hnd__ev ev_10366 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<nagare/io/image_effect/imageDecode>*/;
  kk_nagare_io_image__effect__image y;
  kk_box_t _x_x573;
  {
    struct kk_std_core_hnd_Ev* _con_x574 = kk_std_core_hnd__as_Ev(ev_10366, _ctx);
    kk_box_t _box_x120 = _con_x574->hnd;
    int32_t m = _con_x574->marker;
    kk_nagare_io_image__effect__imageDecode h = kk_nagare_io_image__effect__imageDecode_unbox(_box_x120, KK_BORROWED, _ctx);
    kk_nagare_io_image__effect__imageDecode_dup(h, _ctx);
    kk_std_core_hnd__clause1 _match_x479;
    kk_std_core_hnd__clause1 _brw_x480 = kk_nagare_io_image__effect_decodeImageBytes_fs__select(h, _ctx); /*hnd/clause1<vector<int8>,nagare/io/image_effect/image,nagare/io/image_effect/imageDecode,465,466>*/;
    kk_datatype_ptr_dropn(h, (KK_I32(2)), _ctx);
    _match_x479 = _brw_x480; /*hnd/clause1<vector<int8>,nagare/io/image_effect/image,nagare/io/image_effect/imageDecode,465,466>*/
    {
      kk_function_t _fun_unbox_x124 = _match_x479.clause;
      _x_x573 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x124, (_fun_unbox_x124, m, ev_10366, kk_vector_box(x_3, _ctx), _ctx), _ctx); /*10010*/
    }
  }
  y = kk_nagare_io_image__effect__image_unbox(_x_x573, KK_OWNED, _ctx); /*nagare/io/image_effect/image*/
  kk_evv_set(w_2,kk_context());
  kk_nagare_io_image__effect__image x_5_10361;
  if (kk_yielding(kk_context())) {
    kk_nagare_io_image__effect__image_drop(y, _ctx);
    kk_box_t _x_x575 = kk_std_core_hnd_yield_cont(kk_examples_image__pipeline_new_decodeOne_fun576(i_10363, _ctx), _ctx); /*10002*/
    x_5_10361 = kk_nagare_io_image__effect__image_unbox(_x_x575, KK_OWNED, _ctx); /*nagare/io/image_effect/image*/
  }
  else {
    x_5_10361 = y; /*nagare/io/image_effect/image*/
  }
  kk_std_core_types__maybe _x_x577;
  if (kk_yielding(kk_context())) {
    kk_nagare_io_image__effect__image_drop(x_5_10361, _ctx);
    kk_box_t _x_x578 = kk_std_core_hnd_yield_extend(kk_examples_image__pipeline_new_decodeOne_fun579(_ctx), _ctx); /*10001*/
    _x_x577 = kk_std_core_types__maybe_unbox(_x_x578, KK_OWNED, _ctx); /*maybe<nagare/io/image_effect/image>*/
  }
  else {
    _x_x577 = kk_std_core_types__new_Just(kk_nagare_io_image__effect__image_box(x_5_10361, _ctx), _ctx); /*maybe<nagare/io/image_effect/image>*/
  }
  return kk_std_core_types__maybe_box(_x_x577, _ctx);
}

kk_std_core_types__maybe kk_examples_image__pipeline_decodeOne(kk_std_os_path__path p, kk_context_t* _ctx) { /* (p : std/os/path/path) -> io maybe<nagare/io/image_effect/image> */ 
  kk_std_core_types__list x_10348;
  kk_box_t _x_x548 = kk_nagare_io_file__effect_defaultFileRead(kk_examples_image__pipeline_new_decodeOne_fun549(p, _ctx), _ctx); /*2420*/
  x_10348 = kk_std_core_types__list_unbox(_x_x548, KK_OWNED, _ctx); /*list<nagare/io/file/bytes>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_10348, _ctx);
    kk_box_t _x_x558 = kk_std_core_hnd_yield_extend(kk_examples_image__pipeline_new_decodeOne_fun559(_ctx), _ctx); /*10001*/
    return kk_std_core_types__maybe_unbox(_x_x558, KK_OWNED, _ctx);
  }
  {
    kk_evv_t w_1 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
    kk_std_core_types__list xs_10002 = kk_examples_image__pipeline__lift_decodeOne_10187(x_10348, _ctx); /*list<int8>*/;
    kk_vector_t x_3 = kk_std_core_vector_unvlist(xs_10002, _ctx); /*nagare/io/file/bytes*/;
    kk_unit_t keep_1 = kk_Unit;
    kk_evv_set(w_1,kk_context());
    bool _match_x476;
    kk_integer_t _brw_x482;
    kk_ssize_t _x_x562 = kk_vector_len_borrow(x_3,kk_context()); /*ssize_t*/
    _brw_x482 = kk_integer_from_ssize_t(_x_x562,kk_context()); /*int*/
    bool _brw_x483 = kk_integer_eq_borrow(_brw_x482,(kk_integer_from_small(0)),kk_context()); /*bool*/;
    kk_integer_drop(_brw_x482, _ctx);
    _match_x476 = _brw_x483; /*bool*/
    if (_match_x476) {
      kk_vector_drop(x_3, _ctx);
      return kk_std_core_types__new_Nothing(_ctx);
    }
    {
      kk_nagare_io_image__effect__imageDecode _b_x145_150;
      kk_std_core_hnd__clause1 _x_x563 = kk_std_core_hnd_clause_tail1(kk_examples_image__pipeline_new_decodeOne_fun564(_ctx), _ctx); /*hnd/clause1<10003,10004,10002,10000,10001>*/
      _b_x145_150 = kk_nagare_io_image__effect__new_Hnd_imageDecode(kk_reuse_null, 0, kk_integer_from_small(1), _x_x563, _ctx); /*nagare/io/image_effect/imageDecode<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>,maybe<nagare/io/image_effect/image>>*/
      kk_box_t _x_x570 = kk_nagare_io_image__effect_imageDecode_fs__handle(_b_x145_150, kk_examples_image__pipeline_new_decodeOne_fun571(_ctx), kk_examples_image__pipeline_new_decodeOne_fun572(x_3, _ctx), _ctx); /*404*/
      return kk_std_core_types__maybe_unbox(_x_x570, KK_OWNED, _ctx);
    }
  }
}
 
// Format a one-line summary for an image.

kk_string_t kk_examples_image__pipeline_describe(kk_std_os_path__path p, kk_nagare_io_image__effect__image img, kk_context_t* _ctx) { /* (p : std/os/path/path, img : nagare/io/image_effect/image) -> string */ 
  kk_string_t _x_x582 = kk_std_os_path_string(p, _ctx); /*string*/
  kk_string_t _x_x583;
  kk_string_t _x_x584;
  kk_define_string_literal(static, _s_x585, 5, " " "\xE2\x80\x94" " ", _ctx)
  _x_x584 = kk_string_dup(_s_x585, _ctx); /*string*/
  kk_string_t _x_x586;
  kk_string_t _x_x587;
  kk_integer_t _x_x588;
  {
    kk_integer_t _x = img.width;
    kk_integer_dup(_x, _ctx);
    _x_x588 = _x; /*int*/
  }
  _x_x587 = kk_std_core_int_show(_x_x588, _ctx); /*string*/
  kk_string_t _x_x589;
  kk_string_t _x_x590;
  kk_define_string_literal(static, _s_x591, 1, "x", _ctx)
  _x_x590 = kk_string_dup(_s_x591, _ctx); /*string*/
  kk_string_t _x_x592;
  kk_string_t _x_x593;
  kk_integer_t _x_x594;
  {
    kk_integer_t _x_0 = img.height;
    kk_integer_dup(_x_0, _ctx);
    _x_x594 = _x_0; /*int*/
  }
  _x_x593 = kk_std_core_int_show(_x_x594, _ctx); /*string*/
  kk_string_t _x_x595;
  kk_string_t _x_x596;
  kk_define_string_literal(static, _s_x597, 2, " (", _ctx)
  _x_x596 = kk_string_dup(_s_x597, _ctx); /*string*/
  kk_string_t _x_x598;
  kk_string_t _x_x599;
  kk_integer_t _x_x600;
  {
    kk_integer_t _x_1 = img.channels;
    kk_integer_dup(_x_1, _ctx);
    _x_x600 = _x_1; /*int*/
  }
  _x_x599 = kk_std_core_int_show(_x_x600, _ctx); /*string*/
  kk_string_t _x_x601;
  kk_string_t _x_x602;
  kk_define_string_literal(static, _s_x603, 5, " ch, ", _ctx)
  _x_x602 = kk_string_dup(_s_x603, _ctx); /*string*/
  kk_string_t _x_x604;
  kk_string_t _x_x605;
  kk_integer_t _x_x606;
  kk_ssize_t _x_x607;
  kk_vector_t _brw_x473;
  {
    kk_vector_t _x_2 = img.pixels;
    kk_vector_dup(_x_2, _ctx);
    kk_nagare_io_image__effect__image_drop(img, _ctx);
    _brw_x473 = _x_2; /*vector<int8>*/
  }
  kk_ssize_t _brw_x474 = kk_vector_len_borrow(_brw_x473,kk_context()); /*ssize_t*/;
  kk_vector_drop(_brw_x473, _ctx);
  _x_x607 = _brw_x474; /*ssize_t*/
  _x_x606 = kk_integer_from_ssize_t(_x_x607,kk_context()); /*int*/
  _x_x605 = kk_std_core_int_show(_x_x606, _ctx); /*string*/
  kk_string_t _x_x608;
  kk_define_string_literal(static, _s_x609, 8, " B RGBA)", _ctx)
  _x_x608 = kk_string_dup(_s_x609, _ctx); /*string*/
  _x_x604 = kk_std_core_types__lp__plus__plus__rp_(_x_x605, _x_x608, _ctx); /*string*/
  _x_x601 = kk_std_core_types__lp__plus__plus__rp_(_x_x602, _x_x604, _ctx); /*string*/
  _x_x598 = kk_std_core_types__lp__plus__plus__rp_(_x_x599, _x_x601, _ctx); /*string*/
  _x_x595 = kk_std_core_types__lp__plus__plus__rp_(_x_x596, _x_x598, _ctx); /*string*/
  _x_x592 = kk_std_core_types__lp__plus__plus__rp_(_x_x593, _x_x595, _ctx); /*string*/
  _x_x589 = kk_std_core_types__lp__plus__plus__rp_(_x_x590, _x_x592, _ctx); /*string*/
  _x_x586 = kk_std_core_types__lp__plus__plus__rp_(_x_x587, _x_x589, _ctx); /*string*/
  _x_x583 = kk_std_core_types__lp__plus__plus__rp_(_x_x584, _x_x586, _ctx); /*string*/
  return kk_std_core_types__lp__plus__plus__rp_(_x_x582, _x_x583, _ctx);
}
 
// lifted local: @lift-main@10189, main, @spec-x10170
// specialized: std/core/list/@unroll-foreach@10017, on parameters @uniq-action@10165, using:
// @uniq-action@10165 = fn<<(console/console :: X),(alloc :: H -> X)<(global :: H)>,(div :: X),(exn :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>>>(s@2: string){
//   std/core/types/@open<(console/console :: X),<(console/console :: X),(alloc :: H -> X)<(global :: H)>,(div :: X),(exn :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>>,(s : string) -> (console/console :: X) (),(s : string) -> <(console/console :: X),(alloc :: H -> X)<(global :: H)>,(div :: X),(exn :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>> ()>(std/core/console/printsln)((std/core/types/@open<(total :: E),<(console/console :: X),(alloc :: H -> X)<(global :: H)>,(div :: X),(exn :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>>,(x : string, y : string) -> string,(x : string, y : string) -> <(console/console :: X),(alloc :: H -> X)<(global :: H)>,(div :: X),(exn :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>> string>(std/core/types/(++))("  ", s@2)));
// }

kk_unit_t kk_examples_image__pipeline__lift_main_10190(kk_std_core_types__list _uniq_xs_10164, kk_context_t* _ctx) { /* (list<string>) -> <console/console,alloc<global>,div,exn,fsys,ndet,net,read<global>,ui,write<global>> () */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_xs_10164, _ctx)) {
    struct kk_std_core_types_Cons* _con_x610 = kk_std_core_types__as_Cons(_uniq_xs_10164, _ctx);
    kk_box_t _box_x160 = _con_x610->head;
    kk_std_core_types__list _uniq_xx_10168 = _con_x610->tail;
    kk_string_t _uniq_x_10167 = kk_string_unbox(_box_x160);
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10164, _ctx)) {
      kk_datatype_ptr_free(_uniq_xs_10164, _ctx);
    }
    else {
      kk_string_dup(_uniq_x_10167, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10168, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10164, _ctx);
    }
    kk_string_t _x_x611;
    kk_string_t _x_x612;
    kk_define_string_literal(static, _s_x613, 2, "  ", _ctx)
    _x_x612 = kk_string_dup(_s_x613, _ctx); /*string*/
    _x_x611 = kk_std_core_types__lp__plus__plus__rp_(_x_x612, _uniq_x_10167, _ctx); /*string*/
    kk_std_core_console_printsln(_x_x611, _ctx);
    { // tailcall
      _uniq_xs_10164 = _uniq_xx_10168;
      goto kk__tailcall;
    }
  }
  {
    kk_Unit; return kk_Unit;
  }
}
 
// lifted local: main, @spec-x10163
// specialized: std/core/list/foreach, on parameters @uniq-action@10160, using:
// @uniq-action@10160 = fn<<(console/console :: X),(alloc :: H -> X)<(global :: H)>,(div :: X),(exn :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>>>(s@2: string){
//   std/core/types/@open<(console/console :: X),<(console/console :: X),(alloc :: H -> X)<(global :: H)>,(div :: X),(exn :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>>,(s : string) -> (console/console :: X) (),(s : string) -> <(console/console :: X),(alloc :: H -> X)<(global :: H)>,(div :: X),(exn :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>> ()>(std/core/console/printsln)((std/core/types/@open<(total :: E),<(console/console :: X),(alloc :: H -> X)<(global :: H)>,(div :: X),(exn :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>>,(x : string, y : string) -> string,(x : string, y : string) -> <(console/console :: X),(alloc :: H -> X)<(global :: H)>,(div :: X),(exn :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>> string>(std/core/types/(++))("  ", s@2)));
// }

kk_unit_t kk_examples_image__pipeline__lift_main_10189(kk_std_core_types__list _uniq_xs_10159, kk_context_t* _ctx) { /* (list<string>) -> <console/console,alloc<global>,div,exn,fsys,ndet,net,read<global>,ui,write<global>> () */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10159, _ctx)) {
    kk_Unit; return kk_Unit;
  }
  {
    kk_examples_image__pipeline__lift_main_10190(_uniq_xs_10159, _ctx); return kk_Unit;
  }
}
 
// lifted local: @lift-main@10191, main, @spec-x10183
// specialized: std/core/list/@unroll-foreach@10017, on parameters @uniq-action@10178, using:
// @uniq-action@10178 = fn<<(console/console :: X),(alloc :: H -> X)<(global :: H)>,(div :: X),(exn :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>>>(s@0@0: string){
//   std/core/types/@open<(console/console :: X),<(console/console :: X),(alloc :: H -> X)<(global :: H)>,(div :: X),(exn :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>>,(s : string) -> (console/console :: X) (),(s : string) -> <(console/console :: X),(alloc :: H -> X)<(global :: H)>,(div :: X),(exn :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>> ()>(std/core/console/printsln)((std/core/types/@open<(total :: E),<(console/console :: X),(alloc :: H -> X)<(global :: H)>,(div :: X),(exn :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>>,(x : string, y : string) -> string,(x : string, y : string) -> <(console/console :: X),(alloc :: H -> X)<(global :: H)>,(div :: X),(exn :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>> string>(std/core/types/(++))("  ", s@0@0)));
// }

kk_unit_t kk_examples_image__pipeline__lift_main_10192(kk_std_core_types__list _uniq_xs_10177, kk_context_t* _ctx) { /* (list<string>) -> <console/console,alloc<global>,div,exn,fsys,ndet,net,read<global>,ui,write<global>> () */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_xs_10177, _ctx)) {
    struct kk_std_core_types_Cons* _con_x614 = kk_std_core_types__as_Cons(_uniq_xs_10177, _ctx);
    kk_box_t _box_x161 = _con_x614->head;
    kk_std_core_types__list _uniq_xx_10181 = _con_x614->tail;
    kk_string_t _uniq_x_10180 = kk_string_unbox(_box_x161);
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10177, _ctx)) {
      kk_datatype_ptr_free(_uniq_xs_10177, _ctx);
    }
    else {
      kk_string_dup(_uniq_x_10180, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10181, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10177, _ctx);
    }
    kk_string_t _x_x615;
    kk_string_t _x_x616;
    kk_define_string_literal(static, _s_x617, 2, "  ", _ctx)
    _x_x616 = kk_string_dup(_s_x617, _ctx); /*string*/
    _x_x615 = kk_std_core_types__lp__plus__plus__rp_(_x_x616, _uniq_x_10180, _ctx); /*string*/
    kk_std_core_console_printsln(_x_x615, _ctx);
    { // tailcall
      _uniq_xs_10177 = _uniq_xx_10181;
      goto kk__tailcall;
    }
  }
  {
    kk_Unit; return kk_Unit;
  }
}
 
// lifted local: main, @spec-x10176
// specialized: std/core/list/foreach, on parameters @uniq-action@10173, using:
// @uniq-action@10173 = fn<<(console/console :: X),(alloc :: H -> X)<(global :: H)>,(div :: X),(exn :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>>>(s@0@0: string){
//   std/core/types/@open<(console/console :: X),<(console/console :: X),(alloc :: H -> X)<(global :: H)>,(div :: X),(exn :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>>,(s : string) -> (console/console :: X) (),(s : string) -> <(console/console :: X),(alloc :: H -> X)<(global :: H)>,(div :: X),(exn :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>> ()>(std/core/console/printsln)((std/core/types/@open<(total :: E),<(console/console :: X),(alloc :: H -> X)<(global :: H)>,(div :: X),(exn :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>>,(x : string, y : string) -> string,(x : string, y : string) -> <(console/console :: X),(alloc :: H -> X)<(global :: H)>,(div :: X),(exn :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>> string>(std/core/types/(++))("  ", s@0@0)));
// }

kk_unit_t kk_examples_image__pipeline__lift_main_10191(kk_std_core_types__list _uniq_xs_10172, kk_context_t* _ctx) { /* (list<string>) -> <console/console,alloc<global>,div,exn,fsys,ndet,net,read<global>,ui,write<global>> () */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10172, _ctx)) {
    kk_Unit; return kk_Unit;
  }
  {
    kk_examples_image__pipeline__lift_main_10192(_uniq_xs_10172, _ctx); return kk_Unit;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_examples_image__pipeline__mlift_main_10308_fun619__t {
  struct kk_function_s _base;
};
static kk_box_t kk_examples_image__pipeline__mlift_main_10308_fun619(kk_function_t _fself, kk_box_t _b_x166, kk_box_t _b_x167, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline__new_mlift_main_10308_fun619(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_examples_image__pipeline__mlift_main_10308_fun619, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_examples_image__pipeline__mlift_main_10308_fun619(kk_function_t _fself, kk_box_t _b_x166, kk_box_t _b_x167, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x620;
  kk_std_os_path__path _x_x621 = kk_std_os_path__path_unbox(_b_x166, KK_OWNED, _ctx); /*std/os/path/path*/
  kk_nagare_io_image__effect__image _x_x622 = kk_nagare_io_image__effect__image_unbox(_b_x167, KK_OWNED, _ctx); /*nagare/io/image_effect/image*/
  _x_x620 = kk_examples_image__pipeline_describe(_x_x621, _x_x622, _ctx); /*string*/
  return kk_string_box(_x_x620);
}


// lift anonymous function
struct kk_examples_image__pipeline__mlift_main_10308_fun625__t {
  struct kk_function_s _base;
};
static kk_box_t kk_examples_image__pipeline__mlift_main_10308_fun625(kk_function_t _fself, kk_box_t _b_x170, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline__new_mlift_main_10308_fun625(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_examples_image__pipeline__mlift_main_10308_fun625, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_examples_image__pipeline__mlift_main_10308_fun625(kk_function_t _fself, kk_box_t _b_x170, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x626;
  kk_std_os_path__path _x_x627 = kk_std_os_path__path_unbox(_b_x170, KK_OWNED, _ctx); /*std/os/path/path*/
  _x_x626 = kk_std_os_path_string(_x_x627, _ctx); /*string*/
  return kk_string_box(_x_x626);
}

kk_string_t kk_examples_image__pipeline__mlift_main_10308(kk_std_os_path__path p_0, kk_std_core_types__maybe _y_x10225, kk_context_t* _ctx) { /* (p@0 : std/os/path/path, maybe<nagare/io/image_effect/image>) -> io string */ 
  if (kk_std_core_types__is_Just(_y_x10225, _ctx)) {
    kk_box_t _box_x162 = _y_x10225._cons.Just.value;
    kk_nagare_io_image__effect__image img = kk_nagare_io_image__effect__image_unbox(_box_x162, KK_BORROWED, _ctx);
    kk_nagare_io_image__effect__image_dup(img, _ctx);
    kk_std_core_types__maybe_drop(_y_x10225, _ctx);
    kk_box_t _x_x618 = kk_std_core_hnd__open_none2(kk_examples_image__pipeline__new_mlift_main_10308_fun619(_ctx), kk_std_os_path__path_box(p_0, _ctx), kk_nagare_io_image__effect__image_box(img, _ctx), _ctx); /*10002*/
    return kk_string_unbox(_x_x618);
  }
  {
    kk_string_t _x_x623;
    kk_box_t _x_x624 = kk_std_core_hnd__open_none1(kk_examples_image__pipeline__new_mlift_main_10308_fun625(_ctx), kk_std_os_path__path_box(p_0, _ctx), _ctx); /*10001*/
    _x_x623 = kk_string_unbox(_x_x624); /*string*/
    kk_string_t _x_x628;
    kk_define_string_literal(static, _s_x629, 23, " " "\xE2\x80\x94" " (could not decode)", _ctx)
    _x_x628 = kk_string_dup(_s_x629, _ctx); /*string*/
    return kk_std_core_types__lp__plus__plus__rp_(_x_x623, _x_x628, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_examples_image__pipeline__mlift_main_10309_fun632__t {
  struct kk_function_s _base;
  kk_nagare_core_interpreter__runtime state_0;
};
static kk_unit_t kk_examples_image__pipeline__mlift_main_10309_fun632(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline__new_mlift_main_10309_fun632(kk_nagare_core_interpreter__runtime state_0, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline__mlift_main_10309_fun632__t* _self = kk_function_alloc_as(struct kk_examples_image__pipeline__mlift_main_10309_fun632__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_examples_image__pipeline__mlift_main_10309_fun632, kk_context());
  _self->state_0 = state_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_unit_t kk_examples_image__pipeline__mlift_main_10309_fun632(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline__mlift_main_10309_fun632__t* _self = kk_function_as(struct kk_examples_image__pipeline__mlift_main_10309_fun632__t*, _fself, _ctx);
  kk_nagare_core_interpreter__runtime state_0 = _self->state_0; /* nagare/core/interpreter/runtime<string,total> */
  kk_drop_match(_self, {kk_nagare_core_interpreter__runtime_dup(state_0, _ctx);}, {}, _ctx)
  kk_nagare_core_interpreter_closeRuntime(state_0, _ctx); return kk_Unit;
}

kk_std_core_types__list kk_examples_image__pipeline__mlift_main_10309(kk_nagare_core_interpreter__runtime state_0, kk_context_t* _ctx) { /* (state@0 : nagare/core/interpreter/runtime<string,total>) -> io list<string> */ 
  kk_std_core_types__list _b_x177_179;
  kk_nagare_core_interpreter__runtime _x_x630 = kk_nagare_core_interpreter__runtime_dup(state_0, _ctx); /*nagare/core/interpreter/runtime<string,total>*/
  _b_x177_179 = kk_nagare_core_interpreter_collectRuntime(_x_x630, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<string>*/
  kk_box_t _x_x631 = kk_std_core_hnd_finally_prompt(kk_examples_image__pipeline__new_mlift_main_10309_fun632(state_0, _ctx), kk_std_core_types__list_box(_b_x177_179, _ctx), _ctx); /*10000*/
  return kk_std_core_types__list_unbox(_x_x631, KK_OWNED, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_examples_image__pipeline__mlift_main_10310_fun634__t {
  struct kk_function_s _base;
};
static kk_box_t kk_examples_image__pipeline__mlift_main_10310_fun634(kk_function_t _fself, kk_box_t _b_x184, kk_box_t _b_x185, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline__new_mlift_main_10310_fun634(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_examples_image__pipeline__mlift_main_10310_fun634, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_examples_image__pipeline__mlift_main_10310_fun634(kk_function_t _fself, kk_box_t _b_x184, kk_box_t _b_x185, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x635;
  kk_std_os_path__path _x_x636 = kk_std_os_path__path_unbox(_b_x184, KK_OWNED, _ctx); /*std/os/path/path*/
  kk_nagare_io_image__effect__image _x_x637 = kk_nagare_io_image__effect__image_unbox(_b_x185, KK_OWNED, _ctx); /*nagare/io/image_effect/image*/
  _x_x635 = kk_examples_image__pipeline_describe(_x_x636, _x_x637, _ctx); /*string*/
  return kk_string_box(_x_x635);
}


// lift anonymous function
struct kk_examples_image__pipeline__mlift_main_10310_fun640__t {
  struct kk_function_s _base;
};
static kk_box_t kk_examples_image__pipeline__mlift_main_10310_fun640(kk_function_t _fself, kk_box_t _b_x188, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline__new_mlift_main_10310_fun640(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_examples_image__pipeline__mlift_main_10310_fun640, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_examples_image__pipeline__mlift_main_10310_fun640(kk_function_t _fself, kk_box_t _b_x188, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x641;
  kk_std_os_path__path _x_x642 = kk_std_os_path__path_unbox(_b_x188, KK_OWNED, _ctx); /*std/os/path/path*/
  _x_x641 = kk_std_os_path_string(_x_x642, _ctx); /*string*/
  return kk_string_box(_x_x641);
}

kk_string_t kk_examples_image__pipeline__mlift_main_10310(kk_std_os_path__path p_1, kk_std_core_types__maybe _y_x10234, kk_context_t* _ctx) { /* (p@1 : std/os/path/path, maybe<nagare/io/image_effect/image>) -> io string */ 
  if (kk_std_core_types__is_Just(_y_x10234, _ctx)) {
    kk_box_t _box_x180 = _y_x10234._cons.Just.value;
    kk_nagare_io_image__effect__image img_0 = kk_nagare_io_image__effect__image_unbox(_box_x180, KK_BORROWED, _ctx);
    kk_nagare_io_image__effect__image_dup(img_0, _ctx);
    kk_std_core_types__maybe_drop(_y_x10234, _ctx);
    kk_box_t _x_x633 = kk_std_core_hnd__open_none2(kk_examples_image__pipeline__new_mlift_main_10310_fun634(_ctx), kk_std_os_path__path_box(p_1, _ctx), kk_nagare_io_image__effect__image_box(img_0, _ctx), _ctx); /*10002*/
    return kk_string_unbox(_x_x633);
  }
  {
    kk_string_t _x_x638;
    kk_box_t _x_x639 = kk_std_core_hnd__open_none1(kk_examples_image__pipeline__new_mlift_main_10310_fun640(_ctx), kk_std_os_path__path_box(p_1, _ctx), _ctx); /*10001*/
    _x_x638 = kk_string_unbox(_x_x639); /*string*/
    kk_string_t _x_x643;
    kk_define_string_literal(static, _s_x644, 23, " " "\xE2\x80\x94" " (could not decode)", _ctx)
    _x_x643 = kk_string_dup(_s_x644, _ctx); /*string*/
    return kk_std_core_types__lp__plus__plus__rp_(_x_x638, _x_x643, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_examples_image__pipeline__mlift_main_10311_fun647__t {
  struct kk_function_s _base;
  kk_nagare_core_interpreter__runtime state_1;
};
static kk_unit_t kk_examples_image__pipeline__mlift_main_10311_fun647(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline__new_mlift_main_10311_fun647(kk_nagare_core_interpreter__runtime state_1, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline__mlift_main_10311_fun647__t* _self = kk_function_alloc_as(struct kk_examples_image__pipeline__mlift_main_10311_fun647__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_examples_image__pipeline__mlift_main_10311_fun647, kk_context());
  _self->state_1 = state_1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_unit_t kk_examples_image__pipeline__mlift_main_10311_fun647(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline__mlift_main_10311_fun647__t* _self = kk_function_as(struct kk_examples_image__pipeline__mlift_main_10311_fun647__t*, _fself, _ctx);
  kk_nagare_core_interpreter__runtime state_1 = _self->state_1; /* nagare/core/interpreter/runtime<string,total> */
  kk_drop_match(_self, {kk_nagare_core_interpreter__runtime_dup(state_1, _ctx);}, {}, _ctx)
  kk_nagare_core_interpreter_closeRuntime(state_1, _ctx); return kk_Unit;
}

kk_std_core_types__list kk_examples_image__pipeline__mlift_main_10311(kk_nagare_core_interpreter__runtime state_1, kk_context_t* _ctx) { /* (state@1 : nagare/core/interpreter/runtime<string,total>) -> io list<string> */ 
  kk_std_core_types__list _b_x195_197;
  kk_nagare_core_interpreter__runtime _x_x645 = kk_nagare_core_interpreter__runtime_dup(state_1, _ctx); /*nagare/core/interpreter/runtime<string,total>*/
  _b_x195_197 = kk_nagare_core_interpreter_collectRuntime(_x_x645, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<string>*/
  kk_box_t _x_x646 = kk_std_core_hnd_finally_prompt(kk_examples_image__pipeline__new_mlift_main_10311_fun647(state_1, _ctx), kk_std_core_types__list_box(_b_x195_197, _ctx), _ctx); /*10000*/
  return kk_std_core_types__list_unbox(_x_x646, KK_OWNED, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_examples_image__pipeline__mlift_main_10312_fun650__t {
  struct kk_function_s _base;
  kk_function_t step_0_0;
};
static kk_box_t kk_examples_image__pipeline__mlift_main_10312_fun650(kk_function_t _fself, kk_box_t _b_x201, kk_box_t _b_x202, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline__new_mlift_main_10312_fun650(kk_function_t step_0_0, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline__mlift_main_10312_fun650__t* _self = kk_function_alloc_as(struct kk_examples_image__pipeline__mlift_main_10312_fun650__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_examples_image__pipeline__mlift_main_10312_fun650, kk_context());
  _self->step_0_0 = step_0_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_examples_image__pipeline__mlift_main_10312_fun650(kk_function_t _fself, kk_box_t _b_x201, kk_box_t _b_x202, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline__mlift_main_10312_fun650__t* _self = kk_function_as(struct kk_examples_image__pipeline__mlift_main_10312_fun650__t*, _fself, _ctx);
  kk_function_t step_0_0 = _self->step_0_0; /* (int, maybe<nagare/io/image_effect/image>) -> int */
  kk_drop_match(_self, {kk_function_dup(step_0_0, _ctx);}, {}, _ctx)
  kk_integer_t _x_x651;
  kk_integer_t _x_x652 = kk_integer_unbox(_b_x201, _ctx); /*int*/
  kk_std_core_types__maybe _x_x653 = kk_std_core_types__maybe_unbox(_b_x202, KK_OWNED, _ctx); /*maybe<nagare/io/image_effect/image>*/
  _x_x651 = kk_function_call(kk_integer_t, (kk_function_t, kk_integer_t, kk_std_core_types__maybe, kk_context_t*), step_0_0, (step_0_0, _x_x652, _x_x653, _ctx), _ctx); /*int*/
  return kk_integer_box(_x_x651, _ctx);
}


// lift anonymous function
struct kk_examples_image__pipeline__mlift_main_10312_fun655__t {
  struct kk_function_s _base;
  kk_nagare_core_interpreter__runtime state_2;
};
static kk_unit_t kk_examples_image__pipeline__mlift_main_10312_fun655(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline__new_mlift_main_10312_fun655(kk_nagare_core_interpreter__runtime state_2, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline__mlift_main_10312_fun655__t* _self = kk_function_alloc_as(struct kk_examples_image__pipeline__mlift_main_10312_fun655__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_examples_image__pipeline__mlift_main_10312_fun655, kk_context());
  _self->state_2 = state_2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_unit_t kk_examples_image__pipeline__mlift_main_10312_fun655(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline__mlift_main_10312_fun655__t* _self = kk_function_as(struct kk_examples_image__pipeline__mlift_main_10312_fun655__t*, _fself, _ctx);
  kk_nagare_core_interpreter__runtime state_2 = _self->state_2; /* nagare/core/interpreter/runtime<maybe<nagare/io/image_effect/image>,total> */
  kk_drop_match(_self, {kk_nagare_core_interpreter__runtime_dup(state_2, _ctx);}, {}, _ctx)
  kk_nagare_core_interpreter_closeRuntime(state_2, _ctx); return kk_Unit;
}

kk_integer_t kk_examples_image__pipeline__mlift_main_10312(kk_integer_t init_0, kk_function_t step_0_0, kk_nagare_core_interpreter__runtime state_2, kk_context_t* _ctx) { /* (init@0 : int, step@0@0 : (int, maybe<nagare/io/image_effect/image>) -> int, state@2 : nagare/core/interpreter/runtime<maybe<nagare/io/image_effect/image>,total>) -> io int */ 
  kk_integer_t _b_x204_206;
  kk_box_t _x_x648;
  kk_nagare_core_interpreter__runtime _x_x649 = kk_nagare_core_interpreter__runtime_dup(state_2, _ctx); /*nagare/core/interpreter/runtime<maybe<nagare/io/image_effect/image>,total>*/
  _x_x648 = kk_nagare_core_interpreter_foldRuntime(_x_x649, kk_integer_box(init_0, _ctx), kk_examples_image__pipeline__new_mlift_main_10312_fun650(step_0_0, _ctx), _ctx); /*1696*/
  _b_x204_206 = kk_integer_unbox(_x_x648, _ctx); /*int*/
  kk_box_t _x_x654 = kk_std_core_hnd_finally_prompt(kk_examples_image__pipeline__new_mlift_main_10312_fun655(state_2, _ctx), kk_integer_box(_b_x204_206, _ctx), _ctx); /*10000*/
  return kk_integer_unbox(_x_x654, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_examples_image__pipeline__mlift_main_10314_fun667__t {
  struct kk_function_s _base;
};
static kk_box_t kk_examples_image__pipeline__mlift_main_10314_fun667(kk_function_t _fself, kk_box_t _b_x212, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline__new_mlift_main_10314_fun667(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_examples_image__pipeline__mlift_main_10314_fun667, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_examples_image__pipeline__mlift_main_10314_fun667(kk_function_t _fself, kk_box_t _b_x212, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__maybe _x_x668;
  kk_std_os_path__path _x_x669 = kk_std_os_path__path_unbox(_b_x212, KK_OWNED, _ctx); /*std/os/path/path*/
  _x_x668 = kk_examples_image__pipeline_decodeOne(_x_x669, _ctx); /*maybe<nagare/io/image_effect/image>*/
  return kk_std_core_types__maybe_box(_x_x668, _ctx);
}


// lift anonymous function
struct kk_examples_image__pipeline__mlift_main_10314_fun670__t {
  struct kk_function_s _base;
};
static kk_integer_t kk_examples_image__pipeline__mlift_main_10314_fun670(kk_function_t _fself, kk_nagare_core_interpreter__runtime state_2, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline__new_mlift_main_10314_fun670(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_examples_image__pipeline__mlift_main_10314_fun670, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_examples_image__pipeline__mlift_main_10314_fun673__t {
  struct kk_function_s _base;
};
static kk_box_t kk_examples_image__pipeline__mlift_main_10314_fun673(kk_function_t _fself, kk_box_t _b_x219, kk_box_t _b_x220, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline__new_mlift_main_10314_fun673(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_examples_image__pipeline__mlift_main_10314_fun673, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_examples_image__pipeline__mlift_main_10314_fun673(kk_function_t _fself, kk_box_t _b_x219, kk_box_t _b_x220, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x674;
  kk_std_core_types__maybe _match_x472 = kk_std_core_types__maybe_unbox(_b_x220, KK_OWNED, _ctx); /*maybe<nagare/io/image_effect/image>*/;
  if (kk_std_core_types__is_Just(_match_x472, _ctx)) {
    kk_box_t _box_x215 = _match_x472._cons.Just.value;
    kk_nagare_io_image__effect__image img_1 = kk_nagare_io_image__effect__image_unbox(_box_x215, KK_BORROWED, _ctx);
    kk_nagare_io_image__effect__image_dup(img_1, _ctx);
    kk_std_core_types__maybe_drop(_match_x472, _ctx);
    kk_integer_t y_10022;
    kk_integer_t _x_x675;
    {
      kk_integer_t _x = img_1.width;
      kk_integer_dup(_x, _ctx);
      _x_x675 = _x; /*int*/
    }
    kk_integer_t _x_x676;
    {
      kk_integer_t _x_0 = img_1.height;
      kk_integer_dup(_x_0, _ctx);
      kk_nagare_io_image__effect__image_drop(img_1, _ctx);
      _x_x676 = _x_0; /*int*/
    }
    y_10022 = kk_integer_mul(_x_x675,_x_x676,kk_context()); /*int*/
    kk_integer_t _x_x677 = kk_integer_unbox(_b_x219, _ctx); /*int*/
    _x_x674 = kk_integer_add(_x_x677,y_10022,kk_context()); /*int*/
  }
  else {
    _x_x674 = kk_integer_unbox(_b_x219, _ctx); /*int*/
  }
  return kk_integer_box(_x_x674, _ctx);
}


// lift anonymous function
struct kk_examples_image__pipeline__mlift_main_10314_fun679__t {
  struct kk_function_s _base;
  kk_nagare_core_interpreter__runtime state_2;
};
static kk_unit_t kk_examples_image__pipeline__mlift_main_10314_fun679(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline__new_mlift_main_10314_fun679(kk_nagare_core_interpreter__runtime state_2, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline__mlift_main_10314_fun679__t* _self = kk_function_alloc_as(struct kk_examples_image__pipeline__mlift_main_10314_fun679__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_examples_image__pipeline__mlift_main_10314_fun679, kk_context());
  _self->state_2 = state_2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_unit_t kk_examples_image__pipeline__mlift_main_10314_fun679(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline__mlift_main_10314_fun679__t* _self = kk_function_as(struct kk_examples_image__pipeline__mlift_main_10314_fun679__t*, _fself, _ctx);
  kk_nagare_core_interpreter__runtime state_2 = _self->state_2; /* nagare/core/interpreter/runtime<maybe<nagare/io/image_effect/image>,total> */
  kk_drop_match(_self, {kk_nagare_core_interpreter__runtime_dup(state_2, _ctx);}, {}, _ctx)
  kk_nagare_core_interpreter_closeRuntime(state_2, _ctx); return kk_Unit;
}
static kk_integer_t kk_examples_image__pipeline__mlift_main_10314_fun670(kk_function_t _fself, kk_nagare_core_interpreter__runtime state_2, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _b_x222_224;
  kk_box_t _x_x671;
  kk_nagare_core_interpreter__runtime _x_x672 = kk_nagare_core_interpreter__runtime_dup(state_2, _ctx); /*nagare/core/interpreter/runtime<maybe<nagare/io/image_effect/image>,total>*/
  _x_x671 = kk_nagare_core_interpreter_foldRuntime(_x_x672, kk_integer_box(kk_integer_from_small(0), _ctx), kk_examples_image__pipeline__new_mlift_main_10314_fun673(_ctx), _ctx); /*1696*/
  _b_x222_224 = kk_integer_unbox(_x_x671, _ctx); /*int*/
  kk_box_t _x_x678 = kk_std_core_hnd_finally_prompt(kk_examples_image__pipeline__new_mlift_main_10314_fun679(state_2, _ctx), kk_integer_box(_b_x222_224, _ctx), _ctx); /*10000*/
  return kk_integer_unbox(_x_x678, _ctx);
}


// lift anonymous function
struct kk_examples_image__pipeline__mlift_main_10314_fun681__t {
  struct kk_function_s _base;
  kk_function_t next_10382;
};
static kk_box_t kk_examples_image__pipeline__mlift_main_10314_fun681(kk_function_t _fself, kk_box_t _b_x231, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline__new_mlift_main_10314_fun681(kk_function_t next_10382, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline__mlift_main_10314_fun681__t* _self = kk_function_alloc_as(struct kk_examples_image__pipeline__mlift_main_10314_fun681__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_examples_image__pipeline__mlift_main_10314_fun681, kk_context());
  _self->next_10382 = next_10382;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_examples_image__pipeline__mlift_main_10314_fun681(kk_function_t _fself, kk_box_t _b_x231, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline__mlift_main_10314_fun681__t* _self = kk_function_as(struct kk_examples_image__pipeline__mlift_main_10314_fun681__t*, _fself, _ctx);
  kk_function_t next_10382 = _self->next_10382; /* (nagare/core/interpreter/runtime<maybe<nagare/io/image_effect/image>,total>) -> io int */
  kk_drop_match(_self, {kk_function_dup(next_10382, _ctx);}, {}, _ctx)
  kk_integer_t _x_x682;
  kk_nagare_core_interpreter__runtime _x_x683 = kk_nagare_core_interpreter__runtime_unbox(_b_x231, KK_OWNED, _ctx); /*nagare/core/interpreter/runtime<maybe<nagare/io/image_effect/image>,total>*/
  _x_x682 = kk_function_call(kk_integer_t, (kk_function_t, kk_nagare_core_interpreter__runtime, kk_context_t*), next_10382, (next_10382, _x_x683, _ctx), _ctx); /*int*/
  return kk_integer_box(_x_x682, _ctx);
}


// lift anonymous function
struct kk_examples_image__pipeline__mlift_main_10314_fun685__t {
  struct kk_function_s _base;
};
static kk_box_t kk_examples_image__pipeline__mlift_main_10314_fun685(kk_function_t _fself, kk_box_t _b_x234, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline__new_mlift_main_10314_fun685(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_examples_image__pipeline__mlift_main_10314_fun685, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_examples_image__pipeline__mlift_main_10314_fun685(kk_function_t _fself, kk_box_t _b_x234, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x686 = kk_Unit;
  kk_integer_t _x_x687 = kk_integer_unbox(_b_x234, _ctx); /*int*/
  kk_examples_image__pipeline__mlift_main_10313(_x_x687, _ctx);
  return kk_unit_box(_x_x686);
}

kk_unit_t kk_examples_image__pipeline__mlift_main_10314(kk_std_core_types__list pics, kk_unit_t wild___4, kk_context_t* _ctx) { /* (pics : list<std/os/path/path>, wild_@4 : ()) -> <console/console,alloc<global>,div,exn,fsys,ndet,net,read<global>,ui,write<global>> () */ 
  kk_unit_t ___5 = kk_Unit;
  kk_string_t _x_x660 = kk_string_empty(); /*string*/
  kk_std_core_console_printsln(_x_x660, _ctx);
  kk_unit_t ___6 = kk_Unit;
  kk_string_t _x_x662;
  kk_define_string_literal(static, _s_x663, 34, "=== folding: total pixel count ===", _ctx)
  _x_x662 = kk_string_dup(_s_x663, _ctx); /*string*/
  kk_std_core_console_printsln(_x_x662, _ctx);
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_nagare_core_types__nstream x;
  kk_nagare_core_types__nstream _x_x664;
  kk_nagare_core_types__pull _x_x665;
  kk_nagare_core_types__chunk _x_x666 = kk_nagare_core_types__new_Chunk(pics, _ctx); /*nagare/core/types/chunk<4>*/
  _x_x665 = kk_nagare_core_types__new_POutput(kk_reuse_null, 0, _x_x666, kk_nagare_core_types__new_PDone(_ctx), _ctx); /*nagare/core/types/pull<19,20>*/
  _x_x664 = kk_nagare_core_types__new_Stream(_x_x665, _ctx); /*nagare/core/types/nstream<27,28>*/
  x = kk_nagare_core_stream_evalMap(_x_x664, kk_examples_image__pipeline__new_mlift_main_10314_fun667(_ctx), _ctx); /*nagare/core/types/nstream<maybe<nagare/io/image_effect/image>,<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_unit_t keep_0 = kk_Unit;
  kk_evv_set(w_0,kk_context());
  kk_nagare_core_interpreter__runtime x_1_10381 = kk_nagare_core_interpreter_runtimeFromStream(x, _ctx); /*nagare/core/interpreter/runtime<maybe<nagare/io/image_effect/image>,total>*/;
  kk_function_t next_10382 = kk_examples_image__pipeline__new_mlift_main_10314_fun670(_ctx); /*(nagare/core/interpreter/runtime<maybe<nagare/io/image_effect/image>,total>) -> io int*/;
  kk_integer_t x_2_10383;
  if (kk_yielding(kk_context())) {
    kk_datatype_ptr_dropn(x_1_10381, (KK_I32(2)), _ctx);
    kk_box_t _x_x680 = kk_std_core_hnd_yield_extend(kk_examples_image__pipeline__new_mlift_main_10314_fun681(next_10382, _ctx), _ctx); /*10001*/
    x_2_10383 = kk_integer_unbox(_x_x680, _ctx); /*int*/
  }
  else {
    x_2_10383 = kk_function_call(kk_integer_t, (kk_function_t, kk_nagare_core_interpreter__runtime, kk_context_t*), next_10382, (next_10382, x_1_10381, _ctx), _ctx); /*int*/
  }
  if (kk_yielding(kk_context())) {
    kk_integer_drop(x_2_10383, _ctx);
    kk_box_t _x_x684 = kk_std_core_hnd_yield_extend(kk_examples_image__pipeline__new_mlift_main_10314_fun685(_ctx), _ctx); /*10001*/
    kk_unit_unbox(_x_x684); return kk_Unit;
  }
  {
    kk_string_t _x_x688;
    kk_string_t _x_x689;
    kk_define_string_literal(static, _s_x690, 32, "total pixels across all images: ", _ctx)
    _x_x689 = kk_string_dup(_s_x690, _ctx); /*string*/
    kk_string_t _x_x691 = kk_std_core_int_show(x_2_10383, _ctx); /*string*/
    _x_x688 = kk_std_core_types__lp__plus__plus__rp_(_x_x689, _x_x691, _ctx); /*string*/
    kk_std_core_console_printsln(_x_x688, _ctx); return kk_Unit;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_examples_image__pipeline__mlift_main_10315_fun693__t {
  struct kk_function_s _base;
  kk_std_core_types__list pics;
};
static kk_box_t kk_examples_image__pipeline__mlift_main_10315_fun693(kk_function_t _fself, kk_box_t _b_x237, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline__new_mlift_main_10315_fun693(kk_std_core_types__list pics, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline__mlift_main_10315_fun693__t* _self = kk_function_alloc_as(struct kk_examples_image__pipeline__mlift_main_10315_fun693__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_examples_image__pipeline__mlift_main_10315_fun693, kk_context());
  _self->pics = pics;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_examples_image__pipeline__mlift_main_10315_fun693(kk_function_t _fself, kk_box_t _b_x237, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline__mlift_main_10315_fun693__t* _self = kk_function_as(struct kk_examples_image__pipeline__mlift_main_10315_fun693__t*, _fself, _ctx);
  kk_std_core_types__list pics = _self->pics; /* list<std/os/path/path> */
  kk_drop_match(_self, {kk_std_core_types__list_dup(pics, _ctx);}, {}, _ctx)
  kk_unit_t wild___4_239 = kk_Unit;
  kk_unit_unbox(_b_x237);
  kk_unit_t _x_x694 = kk_Unit;
  kk_examples_image__pipeline__mlift_main_10314(pics, wild___4_239, _ctx);
  return kk_unit_box(_x_x694);
}

kk_unit_t kk_examples_image__pipeline__mlift_main_10315(kk_std_core_types__list pics, kk_std_core_types__list firstTwo, kk_context_t* _ctx) { /* (pics : list<std/os/path/path>, firstTwo : list<string>) -> io () */ 
  kk_unit_t x_10385 = kk_Unit;
  kk_examples_image__pipeline__lift_main_10191(firstTwo, _ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x692 = kk_std_core_hnd_yield_extend(kk_examples_image__pipeline__new_mlift_main_10315_fun693(pics, _ctx), _ctx); /*10001*/
    kk_unit_unbox(_x_x692); return kk_Unit;
  }
  {
    kk_examples_image__pipeline__mlift_main_10314(pics, x_10385, _ctx); return kk_Unit;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_examples_image__pipeline__mlift_main_10316_fun710__t {
  struct kk_function_s _base;
};
static kk_box_t kk_examples_image__pipeline__mlift_main_10316_fun710(kk_function_t _fself, kk_box_t _b_x258, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline__new_mlift_main_10316_fun710(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_examples_image__pipeline__mlift_main_10316_fun710, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_examples_image__pipeline__mlift_main_10316_fun713__t {
  struct kk_function_s _base;
  kk_box_t _b_x258;
};
static kk_string_t kk_examples_image__pipeline__mlift_main_10316_fun713(kk_function_t _fself, kk_std_core_types__maybe _y_x10234, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline__new_mlift_main_10316_fun713(kk_box_t _b_x258, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline__mlift_main_10316_fun713__t* _self = kk_function_alloc_as(struct kk_examples_image__pipeline__mlift_main_10316_fun713__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_examples_image__pipeline__mlift_main_10316_fun713, kk_context());
  _self->_b_x258 = _b_x258;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_examples_image__pipeline__mlift_main_10316_fun715__t {
  struct kk_function_s _base;
};
static kk_box_t kk_examples_image__pipeline__mlift_main_10316_fun715(kk_function_t _fself, kk_box_t _b_x244, kk_box_t _b_x245, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline__new_mlift_main_10316_fun715(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_examples_image__pipeline__mlift_main_10316_fun715, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_examples_image__pipeline__mlift_main_10316_fun715(kk_function_t _fself, kk_box_t _b_x244, kk_box_t _b_x245, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x716;
  kk_std_os_path__path _x_x717 = kk_std_os_path__path_unbox(_b_x244, KK_OWNED, _ctx); /*std/os/path/path*/
  kk_nagare_io_image__effect__image _x_x718 = kk_nagare_io_image__effect__image_unbox(_b_x245, KK_OWNED, _ctx); /*nagare/io/image_effect/image*/
  _x_x716 = kk_examples_image__pipeline_describe(_x_x717, _x_x718, _ctx); /*string*/
  return kk_string_box(_x_x716);
}


// lift anonymous function
struct kk_examples_image__pipeline__mlift_main_10316_fun721__t {
  struct kk_function_s _base;
};
static kk_box_t kk_examples_image__pipeline__mlift_main_10316_fun721(kk_function_t _fself, kk_box_t _b_x248, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline__new_mlift_main_10316_fun721(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_examples_image__pipeline__mlift_main_10316_fun721, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_examples_image__pipeline__mlift_main_10316_fun721(kk_function_t _fself, kk_box_t _b_x248, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x722;
  kk_std_os_path__path _x_x723 = kk_std_os_path__path_unbox(_b_x248, KK_OWNED, _ctx); /*std/os/path/path*/
  _x_x722 = kk_std_os_path_string(_x_x723, _ctx); /*string*/
  return kk_string_box(_x_x722);
}
static kk_string_t kk_examples_image__pipeline__mlift_main_10316_fun713(kk_function_t _fself, kk_std_core_types__maybe _y_x10234, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline__mlift_main_10316_fun713__t* _self = kk_function_as(struct kk_examples_image__pipeline__mlift_main_10316_fun713__t*, _fself, _ctx);
  kk_box_t _b_x258 = _self->_b_x258; /* 1418 */
  kk_drop_match(_self, {kk_box_dup(_b_x258, _ctx);}, {}, _ctx)
  if (kk_std_core_types__is_Just(_y_x10234, _ctx)) {
    kk_box_t _box_x240 = _y_x10234._cons.Just.value;
    kk_nagare_io_image__effect__image img_0 = kk_nagare_io_image__effect__image_unbox(_box_x240, KK_BORROWED, _ctx);
    kk_nagare_io_image__effect__image_dup(img_0, _ctx);
    kk_std_core_types__maybe_drop(_y_x10234, _ctx);
    kk_box_t _x_x714 = kk_std_core_hnd__open_none2(kk_examples_image__pipeline__new_mlift_main_10316_fun715(_ctx), _b_x258, kk_nagare_io_image__effect__image_box(img_0, _ctx), _ctx); /*10002*/
    return kk_string_unbox(_x_x714);
  }
  {
    kk_string_t _x_x719;
    kk_box_t _x_x720 = kk_std_core_hnd__open_none1(kk_examples_image__pipeline__new_mlift_main_10316_fun721(_ctx), _b_x258, _ctx); /*10001*/
    _x_x719 = kk_string_unbox(_x_x720); /*string*/
    kk_string_t _x_x724;
    kk_define_string_literal(static, _s_x725, 23, " " "\xE2\x80\x94" " (could not decode)", _ctx)
    _x_x724 = kk_string_dup(_s_x725, _ctx); /*string*/
    return kk_std_core_types__lp__plus__plus__rp_(_x_x719, _x_x724, _ctx);
  }
}


// lift anonymous function
struct kk_examples_image__pipeline__mlift_main_10316_fun728__t {
  struct kk_function_s _base;
  kk_function_t next_10391;
};
static kk_box_t kk_examples_image__pipeline__mlift_main_10316_fun728(kk_function_t _fself, kk_box_t _b_x255, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline__new_mlift_main_10316_fun728(kk_function_t next_10391, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline__mlift_main_10316_fun728__t* _self = kk_function_alloc_as(struct kk_examples_image__pipeline__mlift_main_10316_fun728__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_examples_image__pipeline__mlift_main_10316_fun728, kk_context());
  _self->next_10391 = next_10391;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_examples_image__pipeline__mlift_main_10316_fun728(kk_function_t _fself, kk_box_t _b_x255, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline__mlift_main_10316_fun728__t* _self = kk_function_as(struct kk_examples_image__pipeline__mlift_main_10316_fun728__t*, _fself, _ctx);
  kk_function_t next_10391 = _self->next_10391; /* (maybe<nagare/io/image_effect/image>) -> io string */
  kk_drop_match(_self, {kk_function_dup(next_10391, _ctx);}, {}, _ctx)
  kk_string_t _x_x729;
  kk_std_core_types__maybe _x_x730 = kk_std_core_types__maybe_unbox(_b_x255, KK_OWNED, _ctx); /*maybe<nagare/io/image_effect/image>*/
  _x_x729 = kk_function_call(kk_string_t, (kk_function_t, kk_std_core_types__maybe, kk_context_t*), next_10391, (next_10391, _x_x730, _ctx), _ctx); /*string*/
  return kk_string_box(_x_x729);
}
static kk_box_t kk_examples_image__pipeline__mlift_main_10316_fun710(kk_function_t _fself, kk_box_t _b_x258, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__maybe x_0_10390;
  kk_std_os_path__path _x_x711;
  kk_box_t _x_x712 = kk_box_dup(_b_x258, _ctx); /*1418*/
  _x_x711 = kk_std_os_path__path_unbox(_x_x712, KK_OWNED, _ctx); /*std/os/path/path*/
  x_0_10390 = kk_examples_image__pipeline_decodeOne(_x_x711, _ctx); /*maybe<nagare/io/image_effect/image>*/
  kk_function_t next_10391 = kk_examples_image__pipeline__new_mlift_main_10316_fun713(_b_x258, _ctx); /*(maybe<nagare/io/image_effect/image>) -> io string*/;
  kk_string_t _x_x726;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__maybe_drop(x_0_10390, _ctx);
    kk_box_t _x_x727 = kk_std_core_hnd_yield_extend(kk_examples_image__pipeline__new_mlift_main_10316_fun728(next_10391, _ctx), _ctx); /*10001*/
    _x_x726 = kk_string_unbox(_x_x727); /*string*/
  }
  else {
    _x_x726 = kk_function_call(kk_string_t, (kk_function_t, kk_std_core_types__maybe, kk_context_t*), next_10391, (next_10391, x_0_10390, _ctx), _ctx); /*string*/
  }
  return kk_string_box(_x_x726);
}


// lift anonymous function
struct kk_examples_image__pipeline__mlift_main_10316_fun733__t {
  struct kk_function_s _base;
};
static kk_box_t kk_examples_image__pipeline__mlift_main_10316_fun733(kk_function_t _fself, kk_box_t _b_x264, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline__new_mlift_main_10316_fun733(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_examples_image__pipeline__mlift_main_10316_fun733, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_examples_image__pipeline__mlift_main_10316_fun733(kk_function_t _fself, kk_box_t _b_x264, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__list _x_x734;
  kk_nagare_core_interpreter__runtime _x_x735 = kk_nagare_core_interpreter__runtime_unbox(_b_x264, KK_OWNED, _ctx); /*nagare/core/interpreter/runtime<string,total>*/
  _x_x734 = kk_examples_image__pipeline__mlift_main_10311(_x_x735, _ctx); /*list<string>*/
  return kk_std_core_types__list_box(_x_x734, _ctx);
}


// lift anonymous function
struct kk_examples_image__pipeline__mlift_main_10316_fun738__t {
  struct kk_function_s _base;
  kk_nagare_core_interpreter__runtime x_3_10398;
};
static kk_unit_t kk_examples_image__pipeline__mlift_main_10316_fun738(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline__new_mlift_main_10316_fun738(kk_nagare_core_interpreter__runtime x_3_10398, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline__mlift_main_10316_fun738__t* _self = kk_function_alloc_as(struct kk_examples_image__pipeline__mlift_main_10316_fun738__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_examples_image__pipeline__mlift_main_10316_fun738, kk_context());
  _self->x_3_10398 = x_3_10398;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_unit_t kk_examples_image__pipeline__mlift_main_10316_fun738(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline__mlift_main_10316_fun738__t* _self = kk_function_as(struct kk_examples_image__pipeline__mlift_main_10316_fun738__t*, _fself, _ctx);
  kk_nagare_core_interpreter__runtime x_3_10398 = _self->x_3_10398; /* nagare/core/interpreter/runtime<string,total> */
  kk_drop_match(_self, {kk_nagare_core_interpreter__runtime_dup(x_3_10398, _ctx);}, {}, _ctx)
  kk_nagare_core_interpreter_closeRuntime(x_3_10398, _ctx); return kk_Unit;
}


// lift anonymous function
struct kk_examples_image__pipeline__mlift_main_10316_fun740__t {
  struct kk_function_s _base;
  kk_std_core_types__list pics;
};
static kk_box_t kk_examples_image__pipeline__mlift_main_10316_fun740(kk_function_t _fself, kk_box_t _b_x271, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline__new_mlift_main_10316_fun740(kk_std_core_types__list pics, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline__mlift_main_10316_fun740__t* _self = kk_function_alloc_as(struct kk_examples_image__pipeline__mlift_main_10316_fun740__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_examples_image__pipeline__mlift_main_10316_fun740, kk_context());
  _self->pics = pics;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_examples_image__pipeline__mlift_main_10316_fun740(kk_function_t _fself, kk_box_t _b_x271, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline__mlift_main_10316_fun740__t* _self = kk_function_as(struct kk_examples_image__pipeline__mlift_main_10316_fun740__t*, _fself, _ctx);
  kk_std_core_types__list pics = _self->pics; /* list<std/os/path/path> */
  kk_drop_match(_self, {kk_std_core_types__list_dup(pics, _ctx);}, {}, _ctx)
  kk_std_core_types__list firstTwo_273 = kk_std_core_types__list_unbox(_b_x271, KK_OWNED, _ctx); /*list<string>*/;
  kk_unit_t _x_x741 = kk_Unit;
  kk_examples_image__pipeline__mlift_main_10315(pics, firstTwo_273, _ctx);
  return kk_unit_box(_x_x741);
}

kk_unit_t kk_examples_image__pipeline__mlift_main_10316(kk_std_core_types__list pics, kk_std_core_types__list summaries, kk_unit_t wild___0, kk_context_t* _ctx) { /* (pics : list<std/os/path/path>, summaries : list<string>, wild_@0 : ()) -> <console/console,alloc<global>,div,exn,fsys,ndet,net,read<global>,ui,write<global>> () */ 
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<console/console,alloc<global>,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_integer_t x;
  if (kk_std_core_types__is_Nil(summaries, _ctx)) {
    x = kk_integer_from_small(0); /*int*/
  }
  else {
    x = kk_std_core_list__unroll_lift_length_6003_10000(summaries, kk_integer_from_small(0), _ctx); /*int*/
  }
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  kk_unit_t ___1 = kk_Unit;
  kk_string_t _x_x695;
  kk_string_t _x_x696;
  kk_define_string_literal(static, _s_x697, 8, "decoded ", _ctx)
  _x_x696 = kk_string_dup(_s_x697, _ctx); /*string*/
  kk_string_t _x_x698;
  kk_string_t _x_x699 = kk_std_core_int_show(x, _ctx); /*string*/
  kk_string_t _x_x700;
  kk_define_string_literal(static, _s_x701, 7, " images", _ctx)
  _x_x700 = kk_string_dup(_s_x701, _ctx); /*string*/
  _x_x698 = kk_std_core_types__lp__plus__plus__rp_(_x_x699, _x_x700, _ctx); /*string*/
  _x_x695 = kk_std_core_types__lp__plus__plus__rp_(_x_x696, _x_x698, _ctx); /*string*/
  kk_std_core_console_printsln(_x_x695, _ctx);
  kk_unit_t ___2 = kk_Unit;
  kk_string_t _x_x702 = kk_string_empty(); /*string*/
  kk_std_core_console_printsln(_x_x702, _ctx);
  kk_unit_t ___3 = kk_Unit;
  kk_string_t _x_x704;
  kk_define_string_literal(static, _s_x705, 37, "=== take(2): stop after 2 decodes ===", _ctx)
  _x_x704 = kk_string_dup(_s_x705, _ctx); /*string*/
  kk_std_core_console_printsln(_x_x704, _ctx);
  kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_nagare_core_types__nstream x_0;
  kk_nagare_core_types__nstream _x_x706;
  kk_nagare_core_types__pull _x_x707;
  kk_nagare_core_types__chunk _x_x708;
  kk_std_core_types__list _x_x709 = kk_std_core_types__list_dup(pics, _ctx); /*list<std/os/path/path>*/
  _x_x708 = kk_nagare_core_types__new_Chunk(_x_x709, _ctx); /*nagare/core/types/chunk<4>*/
  _x_x707 = kk_nagare_core_types__new_POutput(kk_reuse_null, 0, _x_x708, kk_nagare_core_types__new_PDone(_ctx), _ctx); /*nagare/core/types/pull<19,20>*/
  _x_x706 = kk_nagare_core_types__new_Stream(_x_x707, _ctx); /*nagare/core/types/nstream<27,28>*/
  x_0 = kk_nagare_core_stream_evalMap(_x_x706, kk_examples_image__pipeline__new_mlift_main_10316_fun710(_ctx), _ctx); /*nagare/core/types/nstream<string,<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/
  kk_unit_t keep_0 = kk_Unit;
  kk_evv_set(w_0,kk_context());
  kk_evv_t w_0_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_nagare_core_types__nstream x_1;
  {
    kk_nagare_core_types__pull step = x_0.step;
    kk_nagare_core_types__pull _x_x731 = kk_nagare_core_pull_pullTake(step, kk_integer_from_small(2), _ctx); /*nagare/core/types/pull<1953,1954>*/
    x_1 = kk_nagare_core_types__new_Stream(_x_x731, _ctx); /*nagare/core/types/nstream<string,<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/
  }
  kk_unit_t keep_0_0 = kk_Unit;
  kk_evv_set(w_0_0,kk_context());
  kk_evv_t w_1 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_unit_t keep_1 = kk_Unit;
  kk_evv_set(w_1,kk_context());
  kk_nagare_core_interpreter__runtime x_3_10398 = kk_nagare_core_interpreter_runtimeFromStream(x_1, _ctx); /*nagare/core/interpreter/runtime<string,total>*/;
  kk_std_core_types__list x_4_10400;
  if (kk_yielding(kk_context())) {
    kk_datatype_ptr_dropn(x_3_10398, (KK_I32(2)), _ctx);
    kk_box_t _x_x732 = kk_std_core_hnd_yield_extend(kk_examples_image__pipeline__new_mlift_main_10316_fun733(_ctx), _ctx); /*10001*/
    x_4_10400 = kk_std_core_types__list_unbox(_x_x732, KK_OWNED, _ctx); /*list<string>*/
  }
  else {
    kk_std_core_types__list _b_x266_269;
    kk_nagare_core_interpreter__runtime _x_x736 = kk_nagare_core_interpreter__runtime_dup(x_3_10398, _ctx); /*nagare/core/interpreter/runtime<string,total>*/
    _b_x266_269 = kk_nagare_core_interpreter_collectRuntime(_x_x736, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<string>*/
    kk_box_t _x_x737 = kk_std_core_hnd_finally_prompt(kk_examples_image__pipeline__new_mlift_main_10316_fun738(x_3_10398, _ctx), kk_std_core_types__list_box(_b_x266_269, _ctx), _ctx); /*10000*/
    x_4_10400 = kk_std_core_types__list_unbox(_x_x737, KK_OWNED, _ctx); /*list<string>*/
  }
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_4_10400, _ctx);
    kk_box_t _x_x739 = kk_std_core_hnd_yield_extend(kk_examples_image__pipeline__new_mlift_main_10316_fun740(pics, _ctx), _ctx); /*10001*/
    kk_unit_unbox(_x_x739); return kk_Unit;
  }
  {
    kk_examples_image__pipeline__mlift_main_10315(pics, x_4_10400, _ctx); return kk_Unit;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_examples_image__pipeline__mlift_main_10317_fun744__t {
  struct kk_function_s _base;
  kk_std_core_types__list pics;
  kk_std_core_types__list summaries;
};
static kk_box_t kk_examples_image__pipeline__mlift_main_10317_fun744(kk_function_t _fself, kk_box_t _b_x275, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline__new_mlift_main_10317_fun744(kk_std_core_types__list pics, kk_std_core_types__list summaries, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline__mlift_main_10317_fun744__t* _self = kk_function_alloc_as(struct kk_examples_image__pipeline__mlift_main_10317_fun744__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_examples_image__pipeline__mlift_main_10317_fun744, kk_context());
  _self->pics = pics;
  _self->summaries = summaries;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_examples_image__pipeline__mlift_main_10317_fun744(kk_function_t _fself, kk_box_t _b_x275, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline__mlift_main_10317_fun744__t* _self = kk_function_as(struct kk_examples_image__pipeline__mlift_main_10317_fun744__t*, _fself, _ctx);
  kk_std_core_types__list pics = _self->pics; /* list<std/os/path/path> */
  kk_std_core_types__list summaries = _self->summaries; /* list<string> */
  kk_drop_match(_self, {kk_std_core_types__list_dup(pics, _ctx);kk_std_core_types__list_dup(summaries, _ctx);}, {}, _ctx)
  kk_unit_t wild___0_277 = kk_Unit;
  kk_unit_unbox(_b_x275);
  kk_unit_t _x_x745 = kk_Unit;
  kk_examples_image__pipeline__mlift_main_10316(pics, summaries, wild___0_277, _ctx);
  return kk_unit_box(_x_x745);
}

kk_unit_t kk_examples_image__pipeline__mlift_main_10317(kk_std_core_types__list pics, kk_std_core_types__list summaries, kk_context_t* _ctx) { /* (pics : list<std/os/path/path>, summaries : list<string>) -> io () */ 
  kk_unit_t x_10402 = kk_Unit;
  kk_std_core_types__list _x_x742 = kk_std_core_types__list_dup(summaries, _ctx); /*list<string>*/
  kk_examples_image__pipeline__lift_main_10189(_x_x742, _ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x743 = kk_std_core_hnd_yield_extend(kk_examples_image__pipeline__new_mlift_main_10317_fun744(pics, summaries, _ctx), _ctx); /*10001*/
    kk_unit_unbox(_x_x743); return kk_Unit;
  }
  {
    kk_examples_image__pipeline__mlift_main_10316(pics, summaries, x_10402, _ctx); return kk_Unit;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_examples_image__pipeline__mlift_main_10318_fun748__t {
  struct kk_function_s _base;
  kk_nagare_core_interpreter__runtime state;
};
static kk_unit_t kk_examples_image__pipeline__mlift_main_10318_fun748(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline__new_mlift_main_10318_fun748(kk_nagare_core_interpreter__runtime state, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline__mlift_main_10318_fun748__t* _self = kk_function_alloc_as(struct kk_examples_image__pipeline__mlift_main_10318_fun748__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_examples_image__pipeline__mlift_main_10318_fun748, kk_context());
  _self->state = state;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_unit_t kk_examples_image__pipeline__mlift_main_10318_fun748(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline__mlift_main_10318_fun748__t* _self = kk_function_as(struct kk_examples_image__pipeline__mlift_main_10318_fun748__t*, _fself, _ctx);
  kk_nagare_core_interpreter__runtime state = _self->state; /* nagare/core/interpreter/runtime<std/os/path/path,nagare/io/file_effect/fileSystem> */
  kk_drop_match(_self, {kk_nagare_core_interpreter__runtime_dup(state, _ctx);}, {}, _ctx)
  kk_nagare_core_interpreter_closeRuntime(state, _ctx); return kk_Unit;
}

kk_std_core_types__list kk_examples_image__pipeline__mlift_main_10318(kk_nagare_core_interpreter__runtime state, kk_context_t* _ctx) { /* (state : nagare/core/interpreter/runtime<std/os/path/path,nagare/io/file_effect/fileSystem>) -> <io,nagare/io/file_effect/fileSystem> list<std/os/path/path> */ 
  kk_std_core_types__list _b_x279_281;
  kk_nagare_core_interpreter__runtime _x_x746 = kk_nagare_core_interpreter__runtime_dup(state, _ctx); /*nagare/core/interpreter/runtime<std/os/path/path,nagare/io/file_effect/fileSystem>*/
  _b_x279_281 = kk_nagare_core_interpreter_collectRuntime(_x_x746, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<std/os/path/path>*/
  kk_box_t _x_x747 = kk_std_core_hnd_finally_prompt(kk_examples_image__pipeline__new_mlift_main_10318_fun748(state, _ctx), kk_std_core_types__list_box(_b_x279_281, _ctx), _ctx); /*10000*/
  return kk_std_core_types__list_unbox(_x_x747, KK_OWNED, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_examples_image__pipeline__mlift_main_10319_fun755__t {
  struct kk_function_s _base;
};
static kk_box_t kk_examples_image__pipeline__mlift_main_10319_fun755(kk_function_t _fself, kk_box_t _b_x300, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline__new_mlift_main_10319_fun755(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_examples_image__pipeline__mlift_main_10319_fun755, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_examples_image__pipeline__mlift_main_10319_fun758__t {
  struct kk_function_s _base;
  kk_box_t _b_x300;
};
static kk_string_t kk_examples_image__pipeline__mlift_main_10319_fun758(kk_function_t _fself, kk_std_core_types__maybe _y_x10225, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline__new_mlift_main_10319_fun758(kk_box_t _b_x300, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline__mlift_main_10319_fun758__t* _self = kk_function_alloc_as(struct kk_examples_image__pipeline__mlift_main_10319_fun758__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_examples_image__pipeline__mlift_main_10319_fun758, kk_context());
  _self->_b_x300 = _b_x300;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_examples_image__pipeline__mlift_main_10319_fun760__t {
  struct kk_function_s _base;
};
static kk_box_t kk_examples_image__pipeline__mlift_main_10319_fun760(kk_function_t _fself, kk_box_t _b_x286, kk_box_t _b_x287, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline__new_mlift_main_10319_fun760(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_examples_image__pipeline__mlift_main_10319_fun760, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_examples_image__pipeline__mlift_main_10319_fun760(kk_function_t _fself, kk_box_t _b_x286, kk_box_t _b_x287, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x761;
  kk_std_os_path__path _x_x762 = kk_std_os_path__path_unbox(_b_x286, KK_OWNED, _ctx); /*std/os/path/path*/
  kk_nagare_io_image__effect__image _x_x763 = kk_nagare_io_image__effect__image_unbox(_b_x287, KK_OWNED, _ctx); /*nagare/io/image_effect/image*/
  _x_x761 = kk_examples_image__pipeline_describe(_x_x762, _x_x763, _ctx); /*string*/
  return kk_string_box(_x_x761);
}


// lift anonymous function
struct kk_examples_image__pipeline__mlift_main_10319_fun766__t {
  struct kk_function_s _base;
};
static kk_box_t kk_examples_image__pipeline__mlift_main_10319_fun766(kk_function_t _fself, kk_box_t _b_x290, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline__new_mlift_main_10319_fun766(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_examples_image__pipeline__mlift_main_10319_fun766, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_examples_image__pipeline__mlift_main_10319_fun766(kk_function_t _fself, kk_box_t _b_x290, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x767;
  kk_std_os_path__path _x_x768 = kk_std_os_path__path_unbox(_b_x290, KK_OWNED, _ctx); /*std/os/path/path*/
  _x_x767 = kk_std_os_path_string(_x_x768, _ctx); /*string*/
  return kk_string_box(_x_x767);
}
static kk_string_t kk_examples_image__pipeline__mlift_main_10319_fun758(kk_function_t _fself, kk_std_core_types__maybe _y_x10225, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline__mlift_main_10319_fun758__t* _self = kk_function_as(struct kk_examples_image__pipeline__mlift_main_10319_fun758__t*, _fself, _ctx);
  kk_box_t _b_x300 = _self->_b_x300; /* 1418 */
  kk_drop_match(_self, {kk_box_dup(_b_x300, _ctx);}, {}, _ctx)
  if (kk_std_core_types__is_Just(_y_x10225, _ctx)) {
    kk_box_t _box_x282 = _y_x10225._cons.Just.value;
    kk_nagare_io_image__effect__image img = kk_nagare_io_image__effect__image_unbox(_box_x282, KK_BORROWED, _ctx);
    kk_nagare_io_image__effect__image_dup(img, _ctx);
    kk_std_core_types__maybe_drop(_y_x10225, _ctx);
    kk_box_t _x_x759 = kk_std_core_hnd__open_none2(kk_examples_image__pipeline__new_mlift_main_10319_fun760(_ctx), _b_x300, kk_nagare_io_image__effect__image_box(img, _ctx), _ctx); /*10002*/
    return kk_string_unbox(_x_x759);
  }
  {
    kk_string_t _x_x764;
    kk_box_t _x_x765 = kk_std_core_hnd__open_none1(kk_examples_image__pipeline__new_mlift_main_10319_fun766(_ctx), _b_x300, _ctx); /*10001*/
    _x_x764 = kk_string_unbox(_x_x765); /*string*/
    kk_string_t _x_x769;
    kk_define_string_literal(static, _s_x770, 23, " " "\xE2\x80\x94" " (could not decode)", _ctx)
    _x_x769 = kk_string_dup(_s_x770, _ctx); /*string*/
    return kk_std_core_types__lp__plus__plus__rp_(_x_x764, _x_x769, _ctx);
  }
}


// lift anonymous function
struct kk_examples_image__pipeline__mlift_main_10319_fun773__t {
  struct kk_function_s _base;
  kk_function_t next_10410;
};
static kk_box_t kk_examples_image__pipeline__mlift_main_10319_fun773(kk_function_t _fself, kk_box_t _b_x297, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline__new_mlift_main_10319_fun773(kk_function_t next_10410, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline__mlift_main_10319_fun773__t* _self = kk_function_alloc_as(struct kk_examples_image__pipeline__mlift_main_10319_fun773__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_examples_image__pipeline__mlift_main_10319_fun773, kk_context());
  _self->next_10410 = next_10410;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_examples_image__pipeline__mlift_main_10319_fun773(kk_function_t _fself, kk_box_t _b_x297, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline__mlift_main_10319_fun773__t* _self = kk_function_as(struct kk_examples_image__pipeline__mlift_main_10319_fun773__t*, _fself, _ctx);
  kk_function_t next_10410 = _self->next_10410; /* (maybe<nagare/io/image_effect/image>) -> io string */
  kk_drop_match(_self, {kk_function_dup(next_10410, _ctx);}, {}, _ctx)
  kk_string_t _x_x774;
  kk_std_core_types__maybe _x_x775 = kk_std_core_types__maybe_unbox(_b_x297, KK_OWNED, _ctx); /*maybe<nagare/io/image_effect/image>*/
  _x_x774 = kk_function_call(kk_string_t, (kk_function_t, kk_std_core_types__maybe, kk_context_t*), next_10410, (next_10410, _x_x775, _ctx), _ctx); /*string*/
  return kk_string_box(_x_x774);
}
static kk_box_t kk_examples_image__pipeline__mlift_main_10319_fun755(kk_function_t _fself, kk_box_t _b_x300, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__maybe x_0_10409;
  kk_std_os_path__path _x_x756;
  kk_box_t _x_x757 = kk_box_dup(_b_x300, _ctx); /*1418*/
  _x_x756 = kk_std_os_path__path_unbox(_x_x757, KK_OWNED, _ctx); /*std/os/path/path*/
  x_0_10409 = kk_examples_image__pipeline_decodeOne(_x_x756, _ctx); /*maybe<nagare/io/image_effect/image>*/
  kk_function_t next_10410 = kk_examples_image__pipeline__new_mlift_main_10319_fun758(_b_x300, _ctx); /*(maybe<nagare/io/image_effect/image>) -> io string*/;
  kk_string_t _x_x771;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__maybe_drop(x_0_10409, _ctx);
    kk_box_t _x_x772 = kk_std_core_hnd_yield_extend(kk_examples_image__pipeline__new_mlift_main_10319_fun773(next_10410, _ctx), _ctx); /*10001*/
    _x_x771 = kk_string_unbox(_x_x772); /*string*/
  }
  else {
    _x_x771 = kk_function_call(kk_string_t, (kk_function_t, kk_std_core_types__maybe, kk_context_t*), next_10410, (next_10410, x_0_10409, _ctx), _ctx); /*string*/
  }
  return kk_string_box(_x_x771);
}


// lift anonymous function
struct kk_examples_image__pipeline__mlift_main_10319_fun777__t {
  struct kk_function_s _base;
};
static kk_box_t kk_examples_image__pipeline__mlift_main_10319_fun777(kk_function_t _fself, kk_box_t _b_x306, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline__new_mlift_main_10319_fun777(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_examples_image__pipeline__mlift_main_10319_fun777, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_examples_image__pipeline__mlift_main_10319_fun777(kk_function_t _fself, kk_box_t _b_x306, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__list _x_x778;
  kk_nagare_core_interpreter__runtime _x_x779 = kk_nagare_core_interpreter__runtime_unbox(_b_x306, KK_OWNED, _ctx); /*nagare/core/interpreter/runtime<string,total>*/
  _x_x778 = kk_examples_image__pipeline__mlift_main_10309(_x_x779, _ctx); /*list<string>*/
  return kk_std_core_types__list_box(_x_x778, _ctx);
}


// lift anonymous function
struct kk_examples_image__pipeline__mlift_main_10319_fun782__t {
  struct kk_function_s _base;
  kk_nagare_core_interpreter__runtime x_2_10414;
};
static kk_unit_t kk_examples_image__pipeline__mlift_main_10319_fun782(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline__new_mlift_main_10319_fun782(kk_nagare_core_interpreter__runtime x_2_10414, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline__mlift_main_10319_fun782__t* _self = kk_function_alloc_as(struct kk_examples_image__pipeline__mlift_main_10319_fun782__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_examples_image__pipeline__mlift_main_10319_fun782, kk_context());
  _self->x_2_10414 = x_2_10414;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_unit_t kk_examples_image__pipeline__mlift_main_10319_fun782(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline__mlift_main_10319_fun782__t* _self = kk_function_as(struct kk_examples_image__pipeline__mlift_main_10319_fun782__t*, _fself, _ctx);
  kk_nagare_core_interpreter__runtime x_2_10414 = _self->x_2_10414; /* nagare/core/interpreter/runtime<string,total> */
  kk_drop_match(_self, {kk_nagare_core_interpreter__runtime_dup(x_2_10414, _ctx);}, {}, _ctx)
  kk_nagare_core_interpreter_closeRuntime(x_2_10414, _ctx); return kk_Unit;
}


// lift anonymous function
struct kk_examples_image__pipeline__mlift_main_10319_fun784__t {
  struct kk_function_s _base;
  kk_std_core_types__list pics;
};
static kk_box_t kk_examples_image__pipeline__mlift_main_10319_fun784(kk_function_t _fself, kk_box_t _b_x313, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline__new_mlift_main_10319_fun784(kk_std_core_types__list pics, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline__mlift_main_10319_fun784__t* _self = kk_function_alloc_as(struct kk_examples_image__pipeline__mlift_main_10319_fun784__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_examples_image__pipeline__mlift_main_10319_fun784, kk_context());
  _self->pics = pics;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_examples_image__pipeline__mlift_main_10319_fun784(kk_function_t _fself, kk_box_t _b_x313, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline__mlift_main_10319_fun784__t* _self = kk_function_as(struct kk_examples_image__pipeline__mlift_main_10319_fun784__t*, _fself, _ctx);
  kk_std_core_types__list pics = _self->pics; /* list<std/os/path/path> */
  kk_drop_match(_self, {kk_std_core_types__list_dup(pics, _ctx);}, {}, _ctx)
  kk_std_core_types__list summaries_315 = kk_std_core_types__list_unbox(_b_x313, KK_OWNED, _ctx); /*list<string>*/;
  kk_unit_t _x_x785 = kk_Unit;
  kk_examples_image__pipeline__mlift_main_10317(pics, summaries_315, _ctx);
  return kk_unit_box(_x_x785);
}

kk_unit_t kk_examples_image__pipeline__mlift_main_10319(kk_std_core_types__list pics, kk_context_t* _ctx) { /* (pics : list<std/os/path/path>) -> io () */ 
  kk_unit_t __ = kk_Unit;
  kk_string_t _x_x749;
  kk_define_string_literal(static, _s_x750, 26, "=== decoding directory ===", _ctx)
  _x_x749 = kk_string_dup(_s_x750, _ctx); /*string*/
  kk_std_core_console_printsln(_x_x749, _ctx);
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_nagare_core_types__nstream x;
  kk_nagare_core_types__nstream _x_x751;
  kk_nagare_core_types__pull _x_x752;
  kk_nagare_core_types__chunk _x_x753;
  kk_std_core_types__list _x_x754 = kk_std_core_types__list_dup(pics, _ctx); /*list<std/os/path/path>*/
  _x_x753 = kk_nagare_core_types__new_Chunk(_x_x754, _ctx); /*nagare/core/types/chunk<4>*/
  _x_x752 = kk_nagare_core_types__new_POutput(kk_reuse_null, 0, _x_x753, kk_nagare_core_types__new_PDone(_ctx), _ctx); /*nagare/core/types/pull<19,20>*/
  _x_x751 = kk_nagare_core_types__new_Stream(_x_x752, _ctx); /*nagare/core/types/nstream<27,28>*/
  x = kk_nagare_core_stream_evalMap(_x_x751, kk_examples_image__pipeline__new_mlift_main_10319_fun755(_ctx), _ctx); /*nagare/core/types/nstream<string,<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_unit_t keep_0 = kk_Unit;
  kk_evv_set(w_0,kk_context());
  kk_nagare_core_interpreter__runtime x_2_10414 = kk_nagare_core_interpreter_runtimeFromStream(x, _ctx); /*nagare/core/interpreter/runtime<string,total>*/;
  kk_std_core_types__list x_3_10416;
  if (kk_yielding(kk_context())) {
    kk_datatype_ptr_dropn(x_2_10414, (KK_I32(2)), _ctx);
    kk_box_t _x_x776 = kk_std_core_hnd_yield_extend(kk_examples_image__pipeline__new_mlift_main_10319_fun777(_ctx), _ctx); /*10001*/
    x_3_10416 = kk_std_core_types__list_unbox(_x_x776, KK_OWNED, _ctx); /*list<string>*/
  }
  else {
    kk_std_core_types__list _b_x308_311;
    kk_nagare_core_interpreter__runtime _x_x780 = kk_nagare_core_interpreter__runtime_dup(x_2_10414, _ctx); /*nagare/core/interpreter/runtime<string,total>*/
    _b_x308_311 = kk_nagare_core_interpreter_collectRuntime(_x_x780, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<string>*/
    kk_box_t _x_x781 = kk_std_core_hnd_finally_prompt(kk_examples_image__pipeline__new_mlift_main_10319_fun782(x_2_10414, _ctx), kk_std_core_types__list_box(_b_x308_311, _ctx), _ctx); /*10000*/
    x_3_10416 = kk_std_core_types__list_unbox(_x_x781, KK_OWNED, _ctx); /*list<string>*/
  }
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_3_10416, _ctx);
    kk_box_t _x_x783 = kk_std_core_hnd_yield_extend(kk_examples_image__pipeline__new_mlift_main_10319_fun784(pics, _ctx), _ctx); /*10001*/
    kk_unit_unbox(_x_x783); return kk_Unit;
  }
  {
    kk_examples_image__pipeline__mlift_main_10317(pics, x_3_10416, _ctx); return kk_Unit;
  }
}


// lift anonymous function
struct kk_examples_image__pipeline_main_fun789__t {
  struct kk_function_s _base;
  kk_std_os_path__path x;
};
static kk_box_t kk_examples_image__pipeline_main_fun789(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline_new_main_fun789(kk_std_os_path__path x, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline_main_fun789__t* _self = kk_function_alloc_as(struct kk_examples_image__pipeline_main_fun789__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_examples_image__pipeline_main_fun789, kk_context());
  _self->x = x;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_examples_image__pipeline_main_fun791__t {
  struct kk_function_s _base;
};
static kk_box_t kk_examples_image__pipeline_main_fun791(kk_function_t _fself, kk_box_t _b_x318, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline_new_main_fun791(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_examples_image__pipeline_main_fun791, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_examples_image__pipeline_main_fun791(kk_function_t _fself, kk_box_t _b_x318, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_nagare_core_types__nstream _x_x792;
  kk_std_os_path__path _x_x793 = kk_std_os_path__path_unbox(_b_x318, KK_OWNED, _ctx); /*std/os/path/path*/
  _x_x792 = kk_nagare_io_file_listDir(_x_x793, _ctx); /*nagare/io/file_effect/fsStream<std/os/path/path>*/
  return kk_nagare_core_types__nstream_box(_x_x792, _ctx);
}


// lift anonymous function
struct kk_examples_image__pipeline_main_fun794__t {
  struct kk_function_s _base;
};
static bool kk_examples_image__pipeline_main_fun794(kk_function_t _fself, kk_box_t _b_x329, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline_new_main_fun794(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_examples_image__pipeline_main_fun794, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static bool kk_examples_image__pipeline_main_fun794(kk_function_t _fself, kk_box_t _b_x329, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t s_10011;
  kk_std_os_path__path _x_x795;
  kk_box_t _x_x796 = kk_box_dup(_b_x329, _ctx); /*1684*/
  _x_x795 = kk_std_os_path__path_unbox(_x_x796, KK_OWNED, _ctx); /*std/os/path/path*/
  s_10011 = kk_std_os_path_string(_x_x795, _ctx); /*string*/
  kk_std_core_types__maybe mb_10010;
  bool _match_x461;
  kk_string_t _x_x797 = kk_string_dup(s_10011, _ctx); /*string*/
  kk_string_t _x_x798;
  kk_define_string_literal(static, _s_x799, 4, ".jpg", _ctx)
  _x_x798 = kk_string_dup(_s_x799, _ctx); /*string*/
  _match_x461 = kk_std_core_sslice_xends_with(_x_x797, _x_x798, _ctx); /*bool*/
  if (_match_x461) {
    kk_integer_t x_10083;
    kk_string_t _x_x800 = kk_string_dup(s_10011, _ctx); /*string*/
    x_10083 = kk_string_len_int(_x_x800,kk_context()); /*int*/
    kk_integer_t y_10084;
    kk_string_t _x_x801;
    kk_define_string_literal(static, _s_x802, 4, ".jpg", _ctx)
    _x_x801 = kk_string_dup(_s_x802, _ctx); /*string*/
    y_10084 = kk_string_len_int(_x_x801,kk_context()); /*int*/
    kk_std_core_sslice__sslice _b_x321_322;
    kk_integer_t _x_x803 = kk_integer_sub(x_10083,y_10084,kk_context()); /*int*/
    _b_x321_322 = kk_std_core_sslice__new_Sslice(s_10011, kk_integer_from_small(0), _x_x803, _ctx); /*sslice/sslice*/
    mb_10010 = kk_std_core_types__new_Just(kk_std_core_sslice__sslice_box(_b_x321_322, _ctx), _ctx); /*maybe<sslice/sslice>*/
  }
  else {
    kk_string_drop(s_10011, _ctx);
    mb_10010 = kk_std_core_types__new_Nothing(_ctx); /*maybe<sslice/sslice>*/
  }
  if (kk_std_core_types__is_Just(mb_10010, _ctx)) {
    kk_box_t _box_x323 = mb_10010._cons.Just.value;
    kk_std_core_types__maybe_drop(mb_10010, _ctx);
    kk_box_drop(_b_x329, _ctx);
    return true;
  }
  {
    kk_string_t s_0_10014;
    kk_std_os_path__path _x_x804 = kk_std_os_path__path_unbox(_b_x329, KK_OWNED, _ctx); /*std/os/path/path*/
    s_0_10014 = kk_std_os_path_string(_x_x804, _ctx); /*string*/
    kk_std_core_types__maybe mb_0_10013;
    bool _match_x460;
    kk_string_t _x_x805 = kk_string_dup(s_0_10014, _ctx); /*string*/
    kk_string_t _x_x806;
    kk_define_string_literal(static, _s_x807, 4, ".png", _ctx)
    _x_x806 = kk_string_dup(_s_x807, _ctx); /*string*/
    _match_x460 = kk_std_core_sslice_xends_with(_x_x805, _x_x806, _ctx); /*bool*/
    if (_match_x460) {
      kk_integer_t x_10083_0;
      kk_string_t _x_x808 = kk_string_dup(s_0_10014, _ctx); /*string*/
      x_10083_0 = kk_string_len_int(_x_x808,kk_context()); /*int*/
      kk_integer_t y_10084_0;
      kk_string_t _x_x809;
      kk_define_string_literal(static, _s_x810, 4, ".png", _ctx)
      _x_x809 = kk_string_dup(_s_x810, _ctx); /*string*/
      y_10084_0 = kk_string_len_int(_x_x809,kk_context()); /*int*/
      kk_std_core_sslice__sslice _b_x324_325;
      kk_integer_t _x_x811 = kk_integer_sub(x_10083_0,y_10084_0,kk_context()); /*int*/
      _b_x324_325 = kk_std_core_sslice__new_Sslice(s_0_10014, kk_integer_from_small(0), _x_x811, _ctx); /*sslice/sslice*/
      mb_0_10013 = kk_std_core_types__new_Just(kk_std_core_sslice__sslice_box(_b_x324_325, _ctx), _ctx); /*maybe<sslice/sslice>*/
    }
    else {
      kk_string_drop(s_0_10014, _ctx);
      mb_0_10013 = kk_std_core_types__new_Nothing(_ctx); /*maybe<sslice/sslice>*/
    }
    if (kk_std_core_types__is_Just(mb_0_10013, _ctx)) {
      kk_box_t _box_x326 = mb_0_10013._cons.Just.value;
      kk_std_core_types__maybe_drop(mb_0_10013, _ctx);
      return true;
    }
    {
      return false;
    }
  }
}


// lift anonymous function
struct kk_examples_image__pipeline_main_fun814__t {
  struct kk_function_s _base;
};
static kk_box_t kk_examples_image__pipeline_main_fun814(kk_function_t _fself, kk_box_t _b_x334, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline_new_main_fun814(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_examples_image__pipeline_main_fun814, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_examples_image__pipeline_main_fun814(kk_function_t _fself, kk_box_t _b_x334, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__list _x_x815;
  kk_nagare_core_interpreter__runtime _x_x816 = kk_nagare_core_interpreter__runtime_unbox(_b_x334, KK_OWNED, _ctx); /*nagare/core/interpreter/runtime<std/os/path/path,nagare/io/file_effect/fileSystem>*/
  _x_x815 = kk_examples_image__pipeline__mlift_main_10318(_x_x816, _ctx); /*list<std/os/path/path>*/
  return kk_std_core_types__list_box(_x_x815, _ctx);
}


// lift anonymous function
struct kk_examples_image__pipeline_main_fun819__t {
  struct kk_function_s _base;
  kk_nagare_core_interpreter__runtime x_3_10427;
};
static kk_unit_t kk_examples_image__pipeline_main_fun819(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline_new_main_fun819(kk_nagare_core_interpreter__runtime x_3_10427, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline_main_fun819__t* _self = kk_function_alloc_as(struct kk_examples_image__pipeline_main_fun819__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_examples_image__pipeline_main_fun819, kk_context());
  _self->x_3_10427 = x_3_10427;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_unit_t kk_examples_image__pipeline_main_fun819(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline_main_fun819__t* _self = kk_function_as(struct kk_examples_image__pipeline_main_fun819__t*, _fself, _ctx);
  kk_nagare_core_interpreter__runtime x_3_10427 = _self->x_3_10427; /* nagare/core/interpreter/runtime<std/os/path/path,nagare/io/file_effect/fileSystem> */
  kk_drop_match(_self, {kk_nagare_core_interpreter__runtime_dup(x_3_10427, _ctx);}, {}, _ctx)
  kk_nagare_core_interpreter_closeRuntime(x_3_10427, _ctx); return kk_Unit;
}
static kk_box_t kk_examples_image__pipeline_main_fun789(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline_main_fun789__t* _self = kk_function_as(struct kk_examples_image__pipeline_main_fun789__t*, _fself, _ctx);
  kk_std_os_path__path x = _self->x; /* std/os/path/path */
  kk_drop_match(_self, {kk_std_os_path__path_dup(x, _ctx);}, {}, _ctx)
  kk_nagare_core_types__nstream _x_x1_0_10281;
  kk_box_t _x_x790 = kk_std_core_hnd__open_none1(kk_examples_image__pipeline_new_main_fun791(_ctx), kk_std_os_path__path_box(x, _ctx), _ctx); /*10001*/
  _x_x1_0_10281 = kk_nagare_core_types__nstream_unbox(_x_x790, KK_OWNED, _ctx); /*nagare/core/types/nstream<std/os/path/path,<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>,nagare/io/file_effect/fileSystem>>*/
  kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_nagare_core_types__nstream x_1 = kk_nagare_core_stream_filter(_x_x1_0_10281, kk_examples_image__pipeline_new_main_fun794(_ctx), _ctx); /*nagare/core/types/nstream<std/os/path/path,<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>,nagare/io/file_effect/fileSystem>>*/;
  kk_unit_t keep_0 = kk_Unit;
  kk_evv_set(w_0,kk_context());
  kk_evv_t w_1 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>,nagare/io/file_effect/fileSystem>>*/;
  kk_unit_t keep_1 = kk_Unit;
  kk_evv_set(w_1,kk_context());
  kk_nagare_core_interpreter__runtime x_3_10427 = kk_nagare_core_interpreter_runtimeFromStream(x_1, _ctx); /*nagare/core/interpreter/runtime<std/os/path/path,nagare/io/file_effect/fileSystem>*/;
  kk_std_core_types__list _x_x812;
  if (kk_yielding(kk_context())) {
    kk_datatype_ptr_dropn(x_3_10427, (KK_I32(2)), _ctx);
    kk_box_t _x_x813 = kk_std_core_hnd_yield_extend(kk_examples_image__pipeline_new_main_fun814(_ctx), _ctx); /*10001*/
    _x_x812 = kk_std_core_types__list_unbox(_x_x813, KK_OWNED, _ctx); /*list<std/os/path/path>*/
  }
  else {
    kk_std_core_types__list _b_x336_341;
    kk_nagare_core_interpreter__runtime _x_x817 = kk_nagare_core_interpreter__runtime_dup(x_3_10427, _ctx); /*nagare/core/interpreter/runtime<std/os/path/path,nagare/io/file_effect/fileSystem>*/
    _b_x336_341 = kk_nagare_core_interpreter_collectRuntime(_x_x817, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<std/os/path/path>*/
    kk_box_t _x_x818 = kk_std_core_hnd_finally_prompt(kk_examples_image__pipeline_new_main_fun819(x_3_10427, _ctx), kk_std_core_types__list_box(_b_x336_341, _ctx), _ctx); /*10000*/
    _x_x812 = kk_std_core_types__list_unbox(_x_x818, KK_OWNED, _ctx); /*list<std/os/path/path>*/
  }
  return kk_std_core_types__list_box(_x_x812, _ctx);
}


// lift anonymous function
struct kk_examples_image__pipeline_main_fun821__t {
  struct kk_function_s _base;
};
static kk_box_t kk_examples_image__pipeline_main_fun821(kk_function_t _fself, kk_box_t _b_x343, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline_new_main_fun821(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_examples_image__pipeline_main_fun821, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_examples_image__pipeline_main_fun821(kk_function_t _fself, kk_box_t _b_x343, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x822 = kk_Unit;
  kk_std_core_types__list _x_x823 = kk_std_core_types__list_unbox(_b_x343, KK_OWNED, _ctx); /*list<std/os/path/path>*/
  kk_examples_image__pipeline__mlift_main_10319(_x_x823, _ctx);
  return kk_unit_box(_x_x822);
}


// lift anonymous function
struct kk_examples_image__pipeline_main_fun830__t {
  struct kk_function_s _base;
};
static kk_box_t kk_examples_image__pipeline_main_fun830(kk_function_t _fself, kk_box_t _b_x362, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline_new_main_fun830(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_examples_image__pipeline_main_fun830, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_examples_image__pipeline_main_fun833__t {
  struct kk_function_s _base;
  kk_box_t _b_x362;
};
static kk_string_t kk_examples_image__pipeline_main_fun833(kk_function_t _fself, kk_std_core_types__maybe _y_x10225, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline_new_main_fun833(kk_box_t _b_x362, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline_main_fun833__t* _self = kk_function_alloc_as(struct kk_examples_image__pipeline_main_fun833__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_examples_image__pipeline_main_fun833, kk_context());
  _self->_b_x362 = _b_x362;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_examples_image__pipeline_main_fun835__t {
  struct kk_function_s _base;
};
static kk_box_t kk_examples_image__pipeline_main_fun835(kk_function_t _fself, kk_box_t _b_x348, kk_box_t _b_x349, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline_new_main_fun835(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_examples_image__pipeline_main_fun835, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_examples_image__pipeline_main_fun835(kk_function_t _fself, kk_box_t _b_x348, kk_box_t _b_x349, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x836;
  kk_std_os_path__path _x_x837 = kk_std_os_path__path_unbox(_b_x348, KK_OWNED, _ctx); /*std/os/path/path*/
  kk_nagare_io_image__effect__image _x_x838 = kk_nagare_io_image__effect__image_unbox(_b_x349, KK_OWNED, _ctx); /*nagare/io/image_effect/image*/
  _x_x836 = kk_examples_image__pipeline_describe(_x_x837, _x_x838, _ctx); /*string*/
  return kk_string_box(_x_x836);
}


// lift anonymous function
struct kk_examples_image__pipeline_main_fun841__t {
  struct kk_function_s _base;
};
static kk_box_t kk_examples_image__pipeline_main_fun841(kk_function_t _fself, kk_box_t _b_x352, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline_new_main_fun841(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_examples_image__pipeline_main_fun841, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_examples_image__pipeline_main_fun841(kk_function_t _fself, kk_box_t _b_x352, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x842;
  kk_std_os_path__path _x_x843 = kk_std_os_path__path_unbox(_b_x352, KK_OWNED, _ctx); /*std/os/path/path*/
  _x_x842 = kk_std_os_path_string(_x_x843, _ctx); /*string*/
  return kk_string_box(_x_x842);
}
static kk_string_t kk_examples_image__pipeline_main_fun833(kk_function_t _fself, kk_std_core_types__maybe _y_x10225, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline_main_fun833__t* _self = kk_function_as(struct kk_examples_image__pipeline_main_fun833__t*, _fself, _ctx);
  kk_box_t _b_x362 = _self->_b_x362; /* 1418 */
  kk_drop_match(_self, {kk_box_dup(_b_x362, _ctx);}, {}, _ctx)
  if (kk_std_core_types__is_Just(_y_x10225, _ctx)) {
    kk_box_t _box_x344 = _y_x10225._cons.Just.value;
    kk_nagare_io_image__effect__image img = kk_nagare_io_image__effect__image_unbox(_box_x344, KK_BORROWED, _ctx);
    kk_nagare_io_image__effect__image_dup(img, _ctx);
    kk_std_core_types__maybe_drop(_y_x10225, _ctx);
    kk_box_t _x_x834 = kk_std_core_hnd__open_none2(kk_examples_image__pipeline_new_main_fun835(_ctx), _b_x362, kk_nagare_io_image__effect__image_box(img, _ctx), _ctx); /*10002*/
    return kk_string_unbox(_x_x834);
  }
  {
    kk_string_t _x_x839;
    kk_box_t _x_x840 = kk_std_core_hnd__open_none1(kk_examples_image__pipeline_new_main_fun841(_ctx), _b_x362, _ctx); /*10001*/
    _x_x839 = kk_string_unbox(_x_x840); /*string*/
    kk_string_t _x_x844;
    kk_define_string_literal(static, _s_x845, 23, " " "\xE2\x80\x94" " (could not decode)", _ctx)
    _x_x844 = kk_string_dup(_s_x845, _ctx); /*string*/
    return kk_std_core_types__lp__plus__plus__rp_(_x_x839, _x_x844, _ctx);
  }
}


// lift anonymous function
struct kk_examples_image__pipeline_main_fun848__t {
  struct kk_function_s _base;
  kk_function_t next_1_10433;
};
static kk_box_t kk_examples_image__pipeline_main_fun848(kk_function_t _fself, kk_box_t _b_x359, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline_new_main_fun848(kk_function_t next_1_10433, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline_main_fun848__t* _self = kk_function_alloc_as(struct kk_examples_image__pipeline_main_fun848__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_examples_image__pipeline_main_fun848, kk_context());
  _self->next_1_10433 = next_1_10433;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_examples_image__pipeline_main_fun848(kk_function_t _fself, kk_box_t _b_x359, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline_main_fun848__t* _self = kk_function_as(struct kk_examples_image__pipeline_main_fun848__t*, _fself, _ctx);
  kk_function_t next_1_10433 = _self->next_1_10433; /* (maybe<nagare/io/image_effect/image>) -> io string */
  kk_drop_match(_self, {kk_function_dup(next_1_10433, _ctx);}, {}, _ctx)
  kk_string_t _x_x849;
  kk_std_core_types__maybe _x_x850 = kk_std_core_types__maybe_unbox(_b_x359, KK_OWNED, _ctx); /*maybe<nagare/io/image_effect/image>*/
  _x_x849 = kk_function_call(kk_string_t, (kk_function_t, kk_std_core_types__maybe, kk_context_t*), next_1_10433, (next_1_10433, _x_x850, _ctx), _ctx); /*string*/
  return kk_string_box(_x_x849);
}
static kk_box_t kk_examples_image__pipeline_main_fun830(kk_function_t _fself, kk_box_t _b_x362, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__maybe x_5_10432;
  kk_std_os_path__path _x_x831;
  kk_box_t _x_x832 = kk_box_dup(_b_x362, _ctx); /*1418*/
  _x_x831 = kk_std_os_path__path_unbox(_x_x832, KK_OWNED, _ctx); /*std/os/path/path*/
  x_5_10432 = kk_examples_image__pipeline_decodeOne(_x_x831, _ctx); /*maybe<nagare/io/image_effect/image>*/
  kk_function_t next_1_10433 = kk_examples_image__pipeline_new_main_fun833(_b_x362, _ctx); /*(maybe<nagare/io/image_effect/image>) -> io string*/;
  kk_string_t _x_x846;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__maybe_drop(x_5_10432, _ctx);
    kk_box_t _x_x847 = kk_std_core_hnd_yield_extend(kk_examples_image__pipeline_new_main_fun848(next_1_10433, _ctx), _ctx); /*10001*/
    _x_x846 = kk_string_unbox(_x_x847); /*string*/
  }
  else {
    _x_x846 = kk_function_call(kk_string_t, (kk_function_t, kk_std_core_types__maybe, kk_context_t*), next_1_10433, (next_1_10433, x_5_10432, _ctx), _ctx); /*string*/
  }
  return kk_string_box(_x_x846);
}


// lift anonymous function
struct kk_examples_image__pipeline_main_fun852__t {
  struct kk_function_s _base;
};
static kk_box_t kk_examples_image__pipeline_main_fun852(kk_function_t _fself, kk_box_t _b_x368, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline_new_main_fun852(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_examples_image__pipeline_main_fun852, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_examples_image__pipeline_main_fun852(kk_function_t _fself, kk_box_t _b_x368, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__list _x_x853;
  kk_nagare_core_interpreter__runtime _x_x854 = kk_nagare_core_interpreter__runtime_unbox(_b_x368, KK_OWNED, _ctx); /*nagare/core/interpreter/runtime<string,total>*/
  _x_x853 = kk_examples_image__pipeline__mlift_main_10309(_x_x854, _ctx); /*list<string>*/
  return kk_std_core_types__list_box(_x_x853, _ctx);
}


// lift anonymous function
struct kk_examples_image__pipeline_main_fun857__t {
  struct kk_function_s _base;
  kk_nagare_core_interpreter__runtime x_7_10437;
};
static kk_unit_t kk_examples_image__pipeline_main_fun857(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline_new_main_fun857(kk_nagare_core_interpreter__runtime x_7_10437, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline_main_fun857__t* _self = kk_function_alloc_as(struct kk_examples_image__pipeline_main_fun857__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_examples_image__pipeline_main_fun857, kk_context());
  _self->x_7_10437 = x_7_10437;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_unit_t kk_examples_image__pipeline_main_fun857(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline_main_fun857__t* _self = kk_function_as(struct kk_examples_image__pipeline_main_fun857__t*, _fself, _ctx);
  kk_nagare_core_interpreter__runtime x_7_10437 = _self->x_7_10437; /* nagare/core/interpreter/runtime<string,total> */
  kk_drop_match(_self, {kk_nagare_core_interpreter__runtime_dup(x_7_10437, _ctx);}, {}, _ctx)
  kk_nagare_core_interpreter_closeRuntime(x_7_10437, _ctx); return kk_Unit;
}


// lift anonymous function
struct kk_examples_image__pipeline_main_fun859__t {
  struct kk_function_s _base;
  kk_std_core_types__list x_0_10420;
};
static kk_box_t kk_examples_image__pipeline_main_fun859(kk_function_t _fself, kk_box_t _b_x375, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline_new_main_fun859(kk_std_core_types__list x_0_10420, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline_main_fun859__t* _self = kk_function_alloc_as(struct kk_examples_image__pipeline_main_fun859__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_examples_image__pipeline_main_fun859, kk_context());
  _self->x_0_10420 = x_0_10420;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_examples_image__pipeline_main_fun859(kk_function_t _fself, kk_box_t _b_x375, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline_main_fun859__t* _self = kk_function_as(struct kk_examples_image__pipeline_main_fun859__t*, _fself, _ctx);
  kk_std_core_types__list x_0_10420 = _self->x_0_10420; /* list<std/os/path/path> */
  kk_drop_match(_self, {kk_std_core_types__list_dup(x_0_10420, _ctx);}, {}, _ctx)
  kk_std_core_types__list summaries_443 = kk_std_core_types__list_unbox(_b_x375, KK_OWNED, _ctx); /*list<string>*/;
  kk_unit_t _x_x860 = kk_Unit;
  kk_examples_image__pipeline__mlift_main_10317(x_0_10420, summaries_443, _ctx);
  return kk_unit_box(_x_x860);
}


// lift anonymous function
struct kk_examples_image__pipeline_main_fun863__t {
  struct kk_function_s _base;
  kk_std_core_types__list x_0_10420;
  kk_std_core_types__list x_8_10439;
};
static kk_box_t kk_examples_image__pipeline_main_fun863(kk_function_t _fself, kk_box_t _b_x377, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline_new_main_fun863(kk_std_core_types__list x_0_10420, kk_std_core_types__list x_8_10439, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline_main_fun863__t* _self = kk_function_alloc_as(struct kk_examples_image__pipeline_main_fun863__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_examples_image__pipeline_main_fun863, kk_context());
  _self->x_0_10420 = x_0_10420;
  _self->x_8_10439 = x_8_10439;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_examples_image__pipeline_main_fun863(kk_function_t _fself, kk_box_t _b_x377, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline_main_fun863__t* _self = kk_function_as(struct kk_examples_image__pipeline_main_fun863__t*, _fself, _ctx);
  kk_std_core_types__list x_0_10420 = _self->x_0_10420; /* list<std/os/path/path> */
  kk_std_core_types__list x_8_10439 = _self->x_8_10439; /* list<string> */
  kk_drop_match(_self, {kk_std_core_types__list_dup(x_0_10420, _ctx);kk_std_core_types__list_dup(x_8_10439, _ctx);}, {}, _ctx)
  kk_unit_t wild___0_444 = kk_Unit;
  kk_unit_unbox(_b_x377);
  kk_unit_t _x_x864 = kk_Unit;
  kk_examples_image__pipeline__mlift_main_10316(x_0_10420, x_8_10439, wild___0_444, _ctx);
  return kk_unit_box(_x_x864);
}


// lift anonymous function
struct kk_examples_image__pipeline_main_fun880__t {
  struct kk_function_s _base;
};
static kk_box_t kk_examples_image__pipeline_main_fun880(kk_function_t _fself, kk_box_t _b_x396, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline_new_main_fun880(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_examples_image__pipeline_main_fun880, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_examples_image__pipeline_main_fun883__t {
  struct kk_function_s _base;
  kk_box_t _b_x396;
};
static kk_string_t kk_examples_image__pipeline_main_fun883(kk_function_t _fself, kk_std_core_types__maybe _y_x10234, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline_new_main_fun883(kk_box_t _b_x396, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline_main_fun883__t* _self = kk_function_alloc_as(struct kk_examples_image__pipeline_main_fun883__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_examples_image__pipeline_main_fun883, kk_context());
  _self->_b_x396 = _b_x396;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_examples_image__pipeline_main_fun885__t {
  struct kk_function_s _base;
};
static kk_box_t kk_examples_image__pipeline_main_fun885(kk_function_t _fself, kk_box_t _b_x382, kk_box_t _b_x383, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline_new_main_fun885(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_examples_image__pipeline_main_fun885, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_examples_image__pipeline_main_fun885(kk_function_t _fself, kk_box_t _b_x382, kk_box_t _b_x383, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x886;
  kk_std_os_path__path _x_x887 = kk_std_os_path__path_unbox(_b_x382, KK_OWNED, _ctx); /*std/os/path/path*/
  kk_nagare_io_image__effect__image _x_x888 = kk_nagare_io_image__effect__image_unbox(_b_x383, KK_OWNED, _ctx); /*nagare/io/image_effect/image*/
  _x_x886 = kk_examples_image__pipeline_describe(_x_x887, _x_x888, _ctx); /*string*/
  return kk_string_box(_x_x886);
}


// lift anonymous function
struct kk_examples_image__pipeline_main_fun891__t {
  struct kk_function_s _base;
};
static kk_box_t kk_examples_image__pipeline_main_fun891(kk_function_t _fself, kk_box_t _b_x386, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline_new_main_fun891(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_examples_image__pipeline_main_fun891, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_examples_image__pipeline_main_fun891(kk_function_t _fself, kk_box_t _b_x386, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x892;
  kk_std_os_path__path _x_x893 = kk_std_os_path__path_unbox(_b_x386, KK_OWNED, _ctx); /*std/os/path/path*/
  _x_x892 = kk_std_os_path_string(_x_x893, _ctx); /*string*/
  return kk_string_box(_x_x892);
}
static kk_string_t kk_examples_image__pipeline_main_fun883(kk_function_t _fself, kk_std_core_types__maybe _y_x10234, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline_main_fun883__t* _self = kk_function_as(struct kk_examples_image__pipeline_main_fun883__t*, _fself, _ctx);
  kk_box_t _b_x396 = _self->_b_x396; /* 1418 */
  kk_drop_match(_self, {kk_box_dup(_b_x396, _ctx);}, {}, _ctx)
  if (kk_std_core_types__is_Just(_y_x10234, _ctx)) {
    kk_box_t _box_x378 = _y_x10234._cons.Just.value;
    kk_nagare_io_image__effect__image img_0 = kk_nagare_io_image__effect__image_unbox(_box_x378, KK_BORROWED, _ctx);
    kk_nagare_io_image__effect__image_dup(img_0, _ctx);
    kk_std_core_types__maybe_drop(_y_x10234, _ctx);
    kk_box_t _x_x884 = kk_std_core_hnd__open_none2(kk_examples_image__pipeline_new_main_fun885(_ctx), _b_x396, kk_nagare_io_image__effect__image_box(img_0, _ctx), _ctx); /*10002*/
    return kk_string_unbox(_x_x884);
  }
  {
    kk_string_t _x_x889;
    kk_box_t _x_x890 = kk_std_core_hnd__open_none1(kk_examples_image__pipeline_new_main_fun891(_ctx), _b_x396, _ctx); /*10001*/
    _x_x889 = kk_string_unbox(_x_x890); /*string*/
    kk_string_t _x_x894;
    kk_define_string_literal(static, _s_x895, 23, " " "\xE2\x80\x94" " (could not decode)", _ctx)
    _x_x894 = kk_string_dup(_s_x895, _ctx); /*string*/
    return kk_std_core_types__lp__plus__plus__rp_(_x_x889, _x_x894, _ctx);
  }
}


// lift anonymous function
struct kk_examples_image__pipeline_main_fun898__t {
  struct kk_function_s _base;
  kk_function_t next_5_10449;
};
static kk_box_t kk_examples_image__pipeline_main_fun898(kk_function_t _fself, kk_box_t _b_x393, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline_new_main_fun898(kk_function_t next_5_10449, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline_main_fun898__t* _self = kk_function_alloc_as(struct kk_examples_image__pipeline_main_fun898__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_examples_image__pipeline_main_fun898, kk_context());
  _self->next_5_10449 = next_5_10449;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_examples_image__pipeline_main_fun898(kk_function_t _fself, kk_box_t _b_x393, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline_main_fun898__t* _self = kk_function_as(struct kk_examples_image__pipeline_main_fun898__t*, _fself, _ctx);
  kk_function_t next_5_10449 = _self->next_5_10449; /* (maybe<nagare/io/image_effect/image>) -> io string */
  kk_drop_match(_self, {kk_function_dup(next_5_10449, _ctx);}, {}, _ctx)
  kk_string_t _x_x899;
  kk_std_core_types__maybe _x_x900 = kk_std_core_types__maybe_unbox(_b_x393, KK_OWNED, _ctx); /*maybe<nagare/io/image_effect/image>*/
  _x_x899 = kk_function_call(kk_string_t, (kk_function_t, kk_std_core_types__maybe, kk_context_t*), next_5_10449, (next_5_10449, _x_x900, _ctx), _ctx); /*string*/
  return kk_string_box(_x_x899);
}
static kk_box_t kk_examples_image__pipeline_main_fun880(kk_function_t _fself, kk_box_t _b_x396, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__maybe x_11_10448;
  kk_std_os_path__path _x_x881;
  kk_box_t _x_x882 = kk_box_dup(_b_x396, _ctx); /*1418*/
  _x_x881 = kk_std_os_path__path_unbox(_x_x882, KK_OWNED, _ctx); /*std/os/path/path*/
  x_11_10448 = kk_examples_image__pipeline_decodeOne(_x_x881, _ctx); /*maybe<nagare/io/image_effect/image>*/
  kk_function_t next_5_10449 = kk_examples_image__pipeline_new_main_fun883(_b_x396, _ctx); /*(maybe<nagare/io/image_effect/image>) -> io string*/;
  kk_string_t _x_x896;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__maybe_drop(x_11_10448, _ctx);
    kk_box_t _x_x897 = kk_std_core_hnd_yield_extend(kk_examples_image__pipeline_new_main_fun898(next_5_10449, _ctx), _ctx); /*10001*/
    _x_x896 = kk_string_unbox(_x_x897); /*string*/
  }
  else {
    _x_x896 = kk_function_call(kk_string_t, (kk_function_t, kk_std_core_types__maybe, kk_context_t*), next_5_10449, (next_5_10449, x_11_10448, _ctx), _ctx); /*string*/
  }
  return kk_string_box(_x_x896);
}


// lift anonymous function
struct kk_examples_image__pipeline_main_fun903__t {
  struct kk_function_s _base;
};
static kk_box_t kk_examples_image__pipeline_main_fun903(kk_function_t _fself, kk_box_t _b_x402, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline_new_main_fun903(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_examples_image__pipeline_main_fun903, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_examples_image__pipeline_main_fun903(kk_function_t _fself, kk_box_t _b_x402, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__list _x_x904;
  kk_nagare_core_interpreter__runtime _x_x905 = kk_nagare_core_interpreter__runtime_unbox(_b_x402, KK_OWNED, _ctx); /*nagare/core/interpreter/runtime<string,total>*/
  _x_x904 = kk_examples_image__pipeline__mlift_main_10311(_x_x905, _ctx); /*list<string>*/
  return kk_std_core_types__list_box(_x_x904, _ctx);
}


// lift anonymous function
struct kk_examples_image__pipeline_main_fun908__t {
  struct kk_function_s _base;
  kk_nagare_core_interpreter__runtime x_14_10456;
};
static kk_unit_t kk_examples_image__pipeline_main_fun908(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline_new_main_fun908(kk_nagare_core_interpreter__runtime x_14_10456, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline_main_fun908__t* _self = kk_function_alloc_as(struct kk_examples_image__pipeline_main_fun908__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_examples_image__pipeline_main_fun908, kk_context());
  _self->x_14_10456 = x_14_10456;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_unit_t kk_examples_image__pipeline_main_fun908(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline_main_fun908__t* _self = kk_function_as(struct kk_examples_image__pipeline_main_fun908__t*, _fself, _ctx);
  kk_nagare_core_interpreter__runtime x_14_10456 = _self->x_14_10456; /* nagare/core/interpreter/runtime<string,total> */
  kk_drop_match(_self, {kk_nagare_core_interpreter__runtime_dup(x_14_10456, _ctx);}, {}, _ctx)
  kk_nagare_core_interpreter_closeRuntime(x_14_10456, _ctx); return kk_Unit;
}


// lift anonymous function
struct kk_examples_image__pipeline_main_fun910__t {
  struct kk_function_s _base;
  kk_std_core_types__list x_0_10420;
};
static kk_box_t kk_examples_image__pipeline_main_fun910(kk_function_t _fself, kk_box_t _b_x409, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline_new_main_fun910(kk_std_core_types__list x_0_10420, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline_main_fun910__t* _self = kk_function_alloc_as(struct kk_examples_image__pipeline_main_fun910__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_examples_image__pipeline_main_fun910, kk_context());
  _self->x_0_10420 = x_0_10420;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_examples_image__pipeline_main_fun910(kk_function_t _fself, kk_box_t _b_x409, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline_main_fun910__t* _self = kk_function_as(struct kk_examples_image__pipeline_main_fun910__t*, _fself, _ctx);
  kk_std_core_types__list x_0_10420 = _self->x_0_10420; /* list<std/os/path/path> */
  kk_drop_match(_self, {kk_std_core_types__list_dup(x_0_10420, _ctx);}, {}, _ctx)
  kk_std_core_types__list firstTwo_445 = kk_std_core_types__list_unbox(_b_x409, KK_OWNED, _ctx); /*list<string>*/;
  kk_unit_t _x_x911 = kk_Unit;
  kk_examples_image__pipeline__mlift_main_10315(x_0_10420, firstTwo_445, _ctx);
  return kk_unit_box(_x_x911);
}


// lift anonymous function
struct kk_examples_image__pipeline_main_fun913__t {
  struct kk_function_s _base;
  kk_std_core_types__list x_0_10420;
};
static kk_box_t kk_examples_image__pipeline_main_fun913(kk_function_t _fself, kk_box_t _b_x411, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline_new_main_fun913(kk_std_core_types__list x_0_10420, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline_main_fun913__t* _self = kk_function_alloc_as(struct kk_examples_image__pipeline_main_fun913__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_examples_image__pipeline_main_fun913, kk_context());
  _self->x_0_10420 = x_0_10420;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_examples_image__pipeline_main_fun913(kk_function_t _fself, kk_box_t _b_x411, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline_main_fun913__t* _self = kk_function_as(struct kk_examples_image__pipeline_main_fun913__t*, _fself, _ctx);
  kk_std_core_types__list x_0_10420 = _self->x_0_10420; /* list<std/os/path/path> */
  kk_drop_match(_self, {kk_std_core_types__list_dup(x_0_10420, _ctx);}, {}, _ctx)
  kk_unit_t wild___4_446 = kk_Unit;
  kk_unit_unbox(_b_x411);
  kk_unit_t _x_x914 = kk_Unit;
  kk_examples_image__pipeline__mlift_main_10314(x_0_10420, wild___4_446, _ctx);
  return kk_unit_box(_x_x914);
}


// lift anonymous function
struct kk_examples_image__pipeline_main_fun922__t {
  struct kk_function_s _base;
};
static kk_box_t kk_examples_image__pipeline_main_fun922(kk_function_t _fself, kk_box_t _b_x414, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline_new_main_fun922(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_examples_image__pipeline_main_fun922, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_examples_image__pipeline_main_fun922(kk_function_t _fself, kk_box_t _b_x414, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__maybe _x_x923;
  kk_std_os_path__path _x_x924 = kk_std_os_path__path_unbox(_b_x414, KK_OWNED, _ctx); /*std/os/path/path*/
  _x_x923 = kk_examples_image__pipeline_decodeOne(_x_x924, _ctx); /*maybe<nagare/io/image_effect/image>*/
  return kk_std_core_types__maybe_box(_x_x923, _ctx);
}


// lift anonymous function
struct kk_examples_image__pipeline_main_fun925__t {
  struct kk_function_s _base;
};
static kk_integer_t kk_examples_image__pipeline_main_fun925(kk_function_t _fself, kk_nagare_core_interpreter__runtime state_2, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline_new_main_fun925(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_examples_image__pipeline_main_fun925, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_examples_image__pipeline_main_fun928__t {
  struct kk_function_s _base;
};
static kk_box_t kk_examples_image__pipeline_main_fun928(kk_function_t _fself, kk_box_t _b_x421, kk_box_t _b_x422, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline_new_main_fun928(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_examples_image__pipeline_main_fun928, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_examples_image__pipeline_main_fun928(kk_function_t _fself, kk_box_t _b_x421, kk_box_t _b_x422, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x929;
  kk_std_core_types__maybe _match_x454 = kk_std_core_types__maybe_unbox(_b_x422, KK_OWNED, _ctx); /*maybe<nagare/io/image_effect/image>*/;
  if (kk_std_core_types__is_Just(_match_x454, _ctx)) {
    kk_box_t _box_x417 = _match_x454._cons.Just.value;
    kk_nagare_io_image__effect__image img_1 = kk_nagare_io_image__effect__image_unbox(_box_x417, KK_BORROWED, _ctx);
    kk_nagare_io_image__effect__image_dup(img_1, _ctx);
    kk_std_core_types__maybe_drop(_match_x454, _ctx);
    kk_integer_t y_10022;
    kk_integer_t _x_x930;
    {
      kk_integer_t _x = img_1.width;
      kk_integer_dup(_x, _ctx);
      _x_x930 = _x; /*int*/
    }
    kk_integer_t _x_x931;
    {
      kk_integer_t _x_0 = img_1.height;
      kk_integer_dup(_x_0, _ctx);
      kk_nagare_io_image__effect__image_drop(img_1, _ctx);
      _x_x931 = _x_0; /*int*/
    }
    y_10022 = kk_integer_mul(_x_x930,_x_x931,kk_context()); /*int*/
    kk_integer_t _x_x932 = kk_integer_unbox(_b_x421, _ctx); /*int*/
    _x_x929 = kk_integer_add(_x_x932,y_10022,kk_context()); /*int*/
  }
  else {
    _x_x929 = kk_integer_unbox(_b_x421, _ctx); /*int*/
  }
  return kk_integer_box(_x_x929, _ctx);
}


// lift anonymous function
struct kk_examples_image__pipeline_main_fun934__t {
  struct kk_function_s _base;
  kk_nagare_core_interpreter__runtime state_2;
};
static kk_unit_t kk_examples_image__pipeline_main_fun934(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline_new_main_fun934(kk_nagare_core_interpreter__runtime state_2, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline_main_fun934__t* _self = kk_function_alloc_as(struct kk_examples_image__pipeline_main_fun934__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_examples_image__pipeline_main_fun934, kk_context());
  _self->state_2 = state_2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_unit_t kk_examples_image__pipeline_main_fun934(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline_main_fun934__t* _self = kk_function_as(struct kk_examples_image__pipeline_main_fun934__t*, _fself, _ctx);
  kk_nagare_core_interpreter__runtime state_2 = _self->state_2; /* nagare/core/interpreter/runtime<maybe<nagare/io/image_effect/image>,total> */
  kk_drop_match(_self, {kk_nagare_core_interpreter__runtime_dup(state_2, _ctx);}, {}, _ctx)
  kk_nagare_core_interpreter_closeRuntime(state_2, _ctx); return kk_Unit;
}
static kk_integer_t kk_examples_image__pipeline_main_fun925(kk_function_t _fself, kk_nagare_core_interpreter__runtime state_2, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _b_x424_426;
  kk_box_t _x_x926;
  kk_nagare_core_interpreter__runtime _x_x927 = kk_nagare_core_interpreter__runtime_dup(state_2, _ctx); /*nagare/core/interpreter/runtime<maybe<nagare/io/image_effect/image>,total>*/
  _x_x926 = kk_nagare_core_interpreter_foldRuntime(_x_x927, kk_integer_box(kk_integer_from_small(0), _ctx), kk_examples_image__pipeline_new_main_fun928(_ctx), _ctx); /*1696*/
  _b_x424_426 = kk_integer_unbox(_x_x926, _ctx); /*int*/
  kk_box_t _x_x933 = kk_std_core_hnd_finally_prompt(kk_examples_image__pipeline_new_main_fun934(state_2, _ctx), kk_integer_box(_b_x424_426, _ctx), _ctx); /*10000*/
  return kk_integer_unbox(_x_x933, _ctx);
}


// lift anonymous function
struct kk_examples_image__pipeline_main_fun936__t {
  struct kk_function_s _base;
  kk_function_t next_9_10471;
};
static kk_box_t kk_examples_image__pipeline_main_fun936(kk_function_t _fself, kk_box_t _b_x433, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline_new_main_fun936(kk_function_t next_9_10471, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline_main_fun936__t* _self = kk_function_alloc_as(struct kk_examples_image__pipeline_main_fun936__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_examples_image__pipeline_main_fun936, kk_context());
  _self->next_9_10471 = next_9_10471;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_examples_image__pipeline_main_fun936(kk_function_t _fself, kk_box_t _b_x433, kk_context_t* _ctx) {
  struct kk_examples_image__pipeline_main_fun936__t* _self = kk_function_as(struct kk_examples_image__pipeline_main_fun936__t*, _fself, _ctx);
  kk_function_t next_9_10471 = _self->next_9_10471; /* (nagare/core/interpreter/runtime<maybe<nagare/io/image_effect/image>,total>) -> io int */
  kk_drop_match(_self, {kk_function_dup(next_9_10471, _ctx);}, {}, _ctx)
  kk_integer_t _x_x937;
  kk_nagare_core_interpreter__runtime _x_x938 = kk_nagare_core_interpreter__runtime_unbox(_b_x433, KK_OWNED, _ctx); /*nagare/core/interpreter/runtime<maybe<nagare/io/image_effect/image>,total>*/
  _x_x937 = kk_function_call(kk_integer_t, (kk_function_t, kk_nagare_core_interpreter__runtime, kk_context_t*), next_9_10471, (next_9_10471, _x_x938, _ctx), _ctx); /*int*/
  return kk_integer_box(_x_x937, _ctx);
}


// lift anonymous function
struct kk_examples_image__pipeline_main_fun940__t {
  struct kk_function_s _base;
};
static kk_box_t kk_examples_image__pipeline_main_fun940(kk_function_t _fself, kk_box_t _b_x436, kk_context_t* _ctx);
static kk_function_t kk_examples_image__pipeline_new_main_fun940(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_examples_image__pipeline_main_fun940, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_examples_image__pipeline_main_fun940(kk_function_t _fself, kk_box_t _b_x436, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x941 = kk_Unit;
  kk_integer_t _x_x942 = kk_integer_unbox(_b_x436, _ctx); /*int*/
  kk_examples_image__pipeline__mlift_main_10313(_x_x942, _ctx);
  return kk_unit_box(_x_x941);
}

kk_unit_t kk_examples_image__pipeline_main(kk_context_t* _ctx) { /* () -> io () */ 
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_std_os_path__path x;
  kk_string_t _x_x786;
  kk_define_string_literal(static, _s_x787, 17, "examples/pictures", _ctx)
  _x_x786 = kk_string_dup(_s_x787, _ctx); /*string*/
  x = kk_std_os_path_path(_x_x786, _ctx); /*std/os/path/path*/
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  kk_std_core_types__list x_0_10420;
  kk_box_t _x_x788 = kk_nagare_io_file__effect_defaultFileSystem(kk_examples_image__pipeline_new_main_fun789(x, _ctx), _ctx); /*2795*/
  x_0_10420 = kk_std_core_types__list_unbox(_x_x788, KK_OWNED, _ctx); /*list<std/os/path/path>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_0_10420, _ctx);
    kk_box_t _x_x820 = kk_std_core_hnd_yield_extend(kk_examples_image__pipeline_new_main_fun821(_ctx), _ctx); /*10001*/
    kk_unit_unbox(_x_x820); return kk_Unit;
  }
  {
    kk_unit_t __ = kk_Unit;
    kk_string_t _x_x824;
    kk_define_string_literal(static, _s_x825, 26, "=== decoding directory ===", _ctx)
    _x_x824 = kk_string_dup(_s_x825, _ctx); /*string*/
    kk_std_core_console_printsln(_x_x824, _ctx);
    kk_evv_t w_2 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
    kk_nagare_core_types__nstream x_4;
    kk_nagare_core_types__nstream _x_x826;
    kk_nagare_core_types__pull _x_x827;
    kk_nagare_core_types__chunk _x_x828;
    kk_std_core_types__list _x_x829 = kk_std_core_types__list_dup(x_0_10420, _ctx); /*list<std/os/path/path>*/
    _x_x828 = kk_nagare_core_types__new_Chunk(_x_x829, _ctx); /*nagare/core/types/chunk<4>*/
    _x_x827 = kk_nagare_core_types__new_POutput(kk_reuse_null, 0, _x_x828, kk_nagare_core_types__new_PDone(_ctx), _ctx); /*nagare/core/types/pull<19,20>*/
    _x_x826 = kk_nagare_core_types__new_Stream(_x_x827, _ctx); /*nagare/core/types/nstream<27,28>*/
    x_4 = kk_nagare_core_stream_evalMap(_x_x826, kk_examples_image__pipeline_new_main_fun830(_ctx), _ctx); /*nagare/core/types/nstream<string,<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/
    kk_unit_t keep_2 = kk_Unit;
    kk_evv_set(w_2,kk_context());
    kk_evv_t w_3 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
    kk_unit_t keep_3 = kk_Unit;
    kk_evv_set(w_3,kk_context());
    kk_nagare_core_interpreter__runtime x_7_10437 = kk_nagare_core_interpreter_runtimeFromStream(x_4, _ctx); /*nagare/core/interpreter/runtime<string,total>*/;
    kk_std_core_types__list x_8_10439;
    if (kk_yielding(kk_context())) {
      kk_datatype_ptr_dropn(x_7_10437, (KK_I32(2)), _ctx);
      kk_box_t _x_x851 = kk_std_core_hnd_yield_extend(kk_examples_image__pipeline_new_main_fun852(_ctx), _ctx); /*10001*/
      x_8_10439 = kk_std_core_types__list_unbox(_x_x851, KK_OWNED, _ctx); /*list<string>*/
    }
    else {
      kk_std_core_types__list _b_x370_373;
      kk_nagare_core_interpreter__runtime _x_x855 = kk_nagare_core_interpreter__runtime_dup(x_7_10437, _ctx); /*nagare/core/interpreter/runtime<string,total>*/
      _b_x370_373 = kk_nagare_core_interpreter_collectRuntime(_x_x855, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<string>*/
      kk_box_t _x_x856 = kk_std_core_hnd_finally_prompt(kk_examples_image__pipeline_new_main_fun857(x_7_10437, _ctx), kk_std_core_types__list_box(_b_x370_373, _ctx), _ctx); /*10000*/
      x_8_10439 = kk_std_core_types__list_unbox(_x_x856, KK_OWNED, _ctx); /*list<string>*/
    }
    if (kk_yielding(kk_context())) {
      kk_std_core_types__list_drop(x_8_10439, _ctx);
      kk_box_t _x_x858 = kk_std_core_hnd_yield_extend(kk_examples_image__pipeline_new_main_fun859(x_0_10420, _ctx), _ctx); /*10001*/
      kk_unit_unbox(_x_x858); return kk_Unit;
    }
    {
      kk_unit_t x_9_10442 = kk_Unit;
      kk_std_core_types__list _x_x861 = kk_std_core_types__list_dup(x_8_10439, _ctx); /*list<string>*/
      kk_examples_image__pipeline__lift_main_10189(_x_x861, _ctx);
      if (kk_yielding(kk_context())) {
        kk_box_t _x_x862 = kk_std_core_hnd_yield_extend(kk_examples_image__pipeline_new_main_fun863(x_0_10420, x_8_10439, _ctx), _ctx); /*10001*/
        kk_unit_unbox(_x_x862); return kk_Unit;
      }
      {
        kk_evv_t w_4 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<console/console,alloc<global>,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
        kk_integer_t x_0;
        if (kk_std_core_types__is_Nil(x_8_10439, _ctx)) {
          x_0 = kk_integer_from_small(0); /*int*/
        }
        else {
          x_0 = kk_std_core_list__unroll_lift_length_6003_10000(x_8_10439, kk_integer_from_small(0), _ctx); /*int*/
        }
        kk_unit_t keep_4 = kk_Unit;
        kk_evv_set(w_4,kk_context());
        kk_unit_t ___1 = kk_Unit;
        kk_string_t _x_x865;
        kk_string_t _x_x866;
        kk_define_string_literal(static, _s_x867, 8, "decoded ", _ctx)
        _x_x866 = kk_string_dup(_s_x867, _ctx); /*string*/
        kk_string_t _x_x868;
        kk_string_t _x_x869 = kk_std_core_int_show(x_0, _ctx); /*string*/
        kk_string_t _x_x870;
        kk_define_string_literal(static, _s_x871, 7, " images", _ctx)
        _x_x870 = kk_string_dup(_s_x871, _ctx); /*string*/
        _x_x868 = kk_std_core_types__lp__plus__plus__rp_(_x_x869, _x_x870, _ctx); /*string*/
        _x_x865 = kk_std_core_types__lp__plus__plus__rp_(_x_x866, _x_x868, _ctx); /*string*/
        kk_std_core_console_printsln(_x_x865, _ctx);
        kk_unit_t ___2 = kk_Unit;
        kk_string_t _x_x872 = kk_string_empty(); /*string*/
        kk_std_core_console_printsln(_x_x872, _ctx);
        kk_unit_t ___3 = kk_Unit;
        kk_string_t _x_x874;
        kk_define_string_literal(static, _s_x875, 37, "=== take(2): stop after 2 decodes ===", _ctx)
        _x_x874 = kk_string_dup(_s_x875, _ctx); /*string*/
        kk_std_core_console_printsln(_x_x874, _ctx);
        kk_evv_t w_4_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
        kk_nagare_core_types__nstream x_10;
        kk_nagare_core_types__nstream _x_x876;
        kk_nagare_core_types__pull _x_x877;
        kk_nagare_core_types__chunk _x_x878;
        kk_std_core_types__list _x_x879 = kk_std_core_types__list_dup(x_0_10420, _ctx); /*list<std/os/path/path>*/
        _x_x878 = kk_nagare_core_types__new_Chunk(_x_x879, _ctx); /*nagare/core/types/chunk<4>*/
        _x_x877 = kk_nagare_core_types__new_POutput(kk_reuse_null, 0, _x_x878, kk_nagare_core_types__new_PDone(_ctx), _ctx); /*nagare/core/types/pull<19,20>*/
        _x_x876 = kk_nagare_core_types__new_Stream(_x_x877, _ctx); /*nagare/core/types/nstream<27,28>*/
        x_10 = kk_nagare_core_stream_evalMap(_x_x876, kk_examples_image__pipeline_new_main_fun880(_ctx), _ctx); /*nagare/core/types/nstream<string,<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/
        kk_unit_t keep_4_0 = kk_Unit;
        kk_evv_set(w_4_0,kk_context());
        kk_evv_t w_5 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
        kk_nagare_core_types__nstream x_12;
        {
          kk_nagare_core_types__pull step = x_10.step;
          kk_nagare_core_types__pull _x_x901 = kk_nagare_core_pull_pullTake(step, kk_integer_from_small(2), _ctx); /*nagare/core/types/pull<1953,1954>*/
          x_12 = kk_nagare_core_types__new_Stream(_x_x901, _ctx); /*nagare/core/types/nstream<string,<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/
        }
        kk_unit_t keep_5 = kk_Unit;
        kk_evv_set(w_5,kk_context());
        kk_evv_t w_6 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
        kk_unit_t keep_6 = kk_Unit;
        kk_evv_set(w_6,kk_context());
        kk_nagare_core_interpreter__runtime x_14_10456 = kk_nagare_core_interpreter_runtimeFromStream(x_12, _ctx); /*nagare/core/interpreter/runtime<string,total>*/;
        kk_std_core_types__list x_15_10458;
        if (kk_yielding(kk_context())) {
          kk_datatype_ptr_dropn(x_14_10456, (KK_I32(2)), _ctx);
          kk_box_t _x_x902 = kk_std_core_hnd_yield_extend(kk_examples_image__pipeline_new_main_fun903(_ctx), _ctx); /*10001*/
          x_15_10458 = kk_std_core_types__list_unbox(_x_x902, KK_OWNED, _ctx); /*list<string>*/
        }
        else {
          kk_std_core_types__list _b_x404_407;
          kk_nagare_core_interpreter__runtime _x_x906 = kk_nagare_core_interpreter__runtime_dup(x_14_10456, _ctx); /*nagare/core/interpreter/runtime<string,total>*/
          _b_x404_407 = kk_nagare_core_interpreter_collectRuntime(_x_x906, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<string>*/
          kk_box_t _x_x907 = kk_std_core_hnd_finally_prompt(kk_examples_image__pipeline_new_main_fun908(x_14_10456, _ctx), kk_std_core_types__list_box(_b_x404_407, _ctx), _ctx); /*10000*/
          x_15_10458 = kk_std_core_types__list_unbox(_x_x907, KK_OWNED, _ctx); /*list<string>*/
        }
        if (kk_yielding(kk_context())) {
          kk_std_core_types__list_drop(x_15_10458, _ctx);
          kk_box_t _x_x909 = kk_std_core_hnd_yield_extend(kk_examples_image__pipeline_new_main_fun910(x_0_10420, _ctx), _ctx); /*10001*/
          kk_unit_unbox(_x_x909); return kk_Unit;
        }
        {
          kk_unit_t x_16_10461 = kk_Unit;
          kk_examples_image__pipeline__lift_main_10191(x_15_10458, _ctx);
          if (kk_yielding(kk_context())) {
            kk_box_t _x_x912 = kk_std_core_hnd_yield_extend(kk_examples_image__pipeline_new_main_fun913(x_0_10420, _ctx), _ctx); /*10001*/
            kk_unit_unbox(_x_x912); return kk_Unit;
          }
          {
            kk_unit_t ___5 = kk_Unit;
            kk_string_t _x_x915 = kk_string_empty(); /*string*/
            kk_std_core_console_printsln(_x_x915, _ctx);
            kk_unit_t ___6 = kk_Unit;
            kk_string_t _x_x917;
            kk_define_string_literal(static, _s_x918, 34, "=== folding: total pixel count ===", _ctx)
            _x_x917 = kk_string_dup(_s_x918, _ctx); /*string*/
            kk_std_core_console_printsln(_x_x917, _ctx);
            kk_evv_t w_7 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
            kk_nagare_core_types__nstream x_17;
            kk_nagare_core_types__nstream _x_x919;
            kk_nagare_core_types__pull _x_x920;
            kk_nagare_core_types__chunk _x_x921 = kk_nagare_core_types__new_Chunk(x_0_10420, _ctx); /*nagare/core/types/chunk<4>*/
            _x_x920 = kk_nagare_core_types__new_POutput(kk_reuse_null, 0, _x_x921, kk_nagare_core_types__new_PDone(_ctx), _ctx); /*nagare/core/types/pull<19,20>*/
            _x_x919 = kk_nagare_core_types__new_Stream(_x_x920, _ctx); /*nagare/core/types/nstream<27,28>*/
            x_17 = kk_nagare_core_stream_evalMap(_x_x919, kk_examples_image__pipeline_new_main_fun922(_ctx), _ctx); /*nagare/core/types/nstream<maybe<nagare/io/image_effect/image>,<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/
            kk_unit_t keep_7 = kk_Unit;
            kk_evv_set(w_7,kk_context());
            kk_evv_t w_8 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
            kk_unit_t keep_8 = kk_Unit;
            kk_evv_set(w_8,kk_context());
            kk_nagare_core_interpreter__runtime x_19_10470 = kk_nagare_core_interpreter_runtimeFromStream(x_17, _ctx); /*nagare/core/interpreter/runtime<maybe<nagare/io/image_effect/image>,total>*/;
            kk_function_t next_9_10471 = kk_examples_image__pipeline_new_main_fun925(_ctx); /*(nagare/core/interpreter/runtime<maybe<nagare/io/image_effect/image>,total>) -> io int*/;
            kk_integer_t x_20_10472;
            if (kk_yielding(kk_context())) {
              kk_datatype_ptr_dropn(x_19_10470, (KK_I32(2)), _ctx);
              kk_box_t _x_x935 = kk_std_core_hnd_yield_extend(kk_examples_image__pipeline_new_main_fun936(next_9_10471, _ctx), _ctx); /*10001*/
              x_20_10472 = kk_integer_unbox(_x_x935, _ctx); /*int*/
            }
            else {
              x_20_10472 = kk_function_call(kk_integer_t, (kk_function_t, kk_nagare_core_interpreter__runtime, kk_context_t*), next_9_10471, (next_9_10471, x_19_10470, _ctx), _ctx); /*int*/
            }
            if (kk_yielding(kk_context())) {
              kk_integer_drop(x_20_10472, _ctx);
              kk_box_t _x_x939 = kk_std_core_hnd_yield_extend(kk_examples_image__pipeline_new_main_fun940(_ctx), _ctx); /*10001*/
              kk_unit_unbox(_x_x939); return kk_Unit;
            }
            {
              kk_string_t _x_x943;
              kk_string_t _x_x944;
              kk_define_string_literal(static, _s_x945, 32, "total pixels across all images: ", _ctx)
              _x_x944 = kk_string_dup(_s_x945, _ctx); /*string*/
              kk_string_t _x_x946 = kk_std_core_int_show(x_20_10472, _ctx); /*string*/
              _x_x943 = kk_std_core_types__lp__plus__plus__rp_(_x_x944, _x_x946, _ctx); /*string*/
              kk_std_core_console_printsln(_x_x943, _ctx); return kk_Unit;
            }
          }
        }
      }
    }
  }
}

// initialization
void kk_examples_image__pipeline__init(kk_context_t* _ctx){
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
  kk_nagare_core_interpreter__init(_ctx);
  kk_nagare_io_file__init(_ctx);
  kk_nagare_io_file__effect__init(_ctx);
  kk_nagare_io_image__init(_ctx);
  kk_nagare_io_image__effect__init(_ctx);
  kk_nagare_core_pull__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
}

// termination
void kk_examples_image__pipeline__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_nagare_core_pull__done(_ctx);
  kk_nagare_io_image__effect__done(_ctx);
  kk_nagare_io_image__done(_ctx);
  kk_nagare_io_file__effect__done(_ctx);
  kk_nagare_io_file__done(_ctx);
  kk_nagare_core_interpreter__done(_ctx);
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
