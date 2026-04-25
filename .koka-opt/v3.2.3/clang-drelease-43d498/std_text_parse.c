// Koka generated module: std/text/parse, koka version: 3.2.3, platform: 64-bit
#include "std_text_parse.h"
 
// runtime tag for the effect `:parse`

kk_std_core_hnd__htag kk_std_text_parse_parse_fs__tag;
 
// handler for the effect `:parse`

kk_box_t kk_std_text_parse_parse_fs__handle(kk_std_text_parse__parse hnd, kk_function_t ret, kk_function_t action, kk_context_t* _ctx) { /* forall<a,e,b> (hnd : parse<e,b>, ret : (res : a) -> e b, action : () -> <parse|e> a) -> e b */ 
  kk_std_core_hnd__htag _x_x2037 = kk_std_core_hnd__htag_dup(kk_std_text_parse_parse_fs__tag, _ctx); /*hnd/htag<std/text/parse/parse>*/
  return kk_std_core_hnd__hhandle(_x_x2037, kk_std_text_parse__parse_box(hnd, _ctx), ret, action, _ctx);
}
extern kk_box_t kk_std_text_parse_satisfy_fun2043(kk_function_t _fself, kk_box_t _b_x21, kk_context_t* _ctx) {
  struct kk_std_text_parse_satisfy_fun2043__t* _self = kk_function_as(struct kk_std_text_parse_satisfy_fun2043__t*, _fself, _ctx);
  kk_function_t pred = _self->pred; /* (sslice/sslice) -> maybe<(533, sslice/sslice)> */
  kk_drop_match(_self, {kk_function_dup(pred, _ctx);}, {}, _ctx)
  kk_std_core_types__maybe _x_x2044;
  kk_std_core_sslice__sslice _x_x2045 = kk_std_core_sslice__sslice_unbox(_b_x21, KK_OWNED, _ctx); /*sslice/sslice*/
  _x_x2044 = kk_function_call(kk_std_core_types__maybe, (kk_function_t, kk_std_core_sslice__sslice, kk_context_t*), pred, (pred, _x_x2045, _ctx), _ctx); /*maybe<(533, sslice/sslice)>*/
  return kk_std_core_types__maybe_box(_x_x2044, _ctx);
}

kk_std_core_types__either kk_std_text_parse_either(kk_std_text_parse__parse_error perr, kk_context_t* _ctx) { /* forall<a> (perr : parse-error<a>) -> either<string,a> */ 
  if (kk_std_text_parse__is_ParseOk(perr, _ctx)) {
    struct kk_std_text_parse_ParseOk* _con_x2064 = kk_std_text_parse__as_ParseOk(perr, _ctx);
    kk_std_core_sslice__sslice _pat_0 = _con_x2064->rest;
    kk_box_t x = _con_x2064->result;
    if kk_likely(kk_datatype_ptr_is_unique(perr, _ctx)) {
      kk_std_core_sslice__sslice_drop(_pat_0, _ctx);
      kk_datatype_ptr_free(perr, _ctx);
    }
    else {
      kk_box_dup(x, _ctx);
      kk_datatype_ptr_decref(perr, _ctx);
    }
    return kk_std_core_types__new_Right(x, _ctx);
  }
  {
    struct kk_std_text_parse_ParseError* _con_x2065 = kk_std_text_parse__as_ParseError(perr, _ctx);
    kk_std_core_sslice__sslice _pat_5 = _con_x2065->rest;
    kk_string_t msg = _con_x2065->msg;
    if kk_likely(kk_datatype_ptr_is_unique(perr, _ctx)) {
      kk_std_core_sslice__sslice_drop(_pat_5, _ctx);
      kk_datatype_ptr_free(perr, _ctx);
    }
    else {
      kk_string_dup(msg, _ctx);
      kk_datatype_ptr_decref(perr, _ctx);
    }
    return kk_std_core_types__new_Left(kk_string_box(msg), _ctx);
  }
}

kk_std_core_types__maybe kk_std_text_parse_maybe(kk_std_text_parse__parse_error perr, kk_context_t* _ctx) { /* forall<a> (perr : parse-error<a>) -> maybe<a> */ 
  if (kk_std_text_parse__is_ParseOk(perr, _ctx)) {
    struct kk_std_text_parse_ParseOk* _con_x2066 = kk_std_text_parse__as_ParseOk(perr, _ctx);
    kk_std_core_sslice__sslice _pat_0_0 = _con_x2066->rest;
    kk_box_t x_0 = _con_x2066->result;
    if kk_likely(kk_datatype_ptr_is_unique(perr, _ctx)) {
      kk_std_core_sslice__sslice_drop(_pat_0_0, _ctx);
      kk_datatype_ptr_free(perr, _ctx);
    }
    else {
      kk_box_dup(x_0, _ctx);
      kk_datatype_ptr_decref(perr, _ctx);
    }
    return kk_std_core_types__new_Just(x_0, _ctx);
  }
  {
    struct kk_std_text_parse_ParseError* _con_x2067 = kk_std_text_parse__as_ParseError(perr, _ctx);
    kk_std_core_sslice__sslice _pat_5 = _con_x2067->rest;
    kk_string_t msg = _con_x2067->msg;
    if kk_likely(kk_datatype_ptr_is_unique(perr, _ctx)) {
      kk_string_drop(msg, _ctx);
      kk_std_core_sslice__sslice_drop(_pat_5, _ctx);
      kk_datatype_ptr_free(perr, _ctx);
    }
    else {
      kk_datatype_ptr_decref(perr, _ctx);
    }
    return kk_std_core_types__new_Nothing(_ctx);
  }
}
 
// monadic lift

kk_std_text_parse__parse_error kk_std_text_parse__mlift_parse_10547(kk_std_text_parse__parse_error err1, kk_std_text_parse__parse_error _y_x10375, kk_context_t* _ctx) { /* forall<h,a,e> (err1 : parse-error<a>, parse-error<a>) -> <local<h>|e> parse-error<a> */ 
  if (kk_std_text_parse__is_ParseOk(_y_x10375, _ctx)) {
    struct kk_std_text_parse_ParseOk* _con_x2068 = kk_std_text_parse__as_ParseOk(_y_x10375, _ctx);
    kk_std_core_sslice__sslice rest2 = _con_x2068->rest;
    kk_box_t x2 = _con_x2068->result;
    kk_std_text_parse__parse_error_drop(err1, _ctx);
    kk_reuse_t _ru_x1933 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_y_x10375, _ctx)) {
      _ru_x1933 = (kk_datatype_ptr_reuse(_y_x10375, _ctx));
    }
    else {
      kk_std_core_sslice__sslice_dup(rest2, _ctx);
      kk_box_dup(x2, _ctx);
      kk_datatype_ptr_decref(_y_x10375, _ctx);
    }
    return kk_std_text_parse__new_ParseOk(_ru_x1933, 0, x2, rest2, _ctx);
  }
  {
    kk_std_text_parse__parse_error_drop(_y_x10375, _ctx);
    return err1;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_text_parse__mlift_parse_10548_fun2070__t {
  struct kk_function_s _base;
  kk_std_text_parse__parse_error err1;
};
static kk_box_t kk_std_text_parse__mlift_parse_10548_fun2070(kk_function_t _fself, kk_box_t _b_x45, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse__new_mlift_parse_10548_fun2070(kk_std_text_parse__parse_error err1, kk_context_t* _ctx) {
  struct kk_std_text_parse__mlift_parse_10548_fun2070__t* _self = kk_function_alloc_as(struct kk_std_text_parse__mlift_parse_10548_fun2070__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_text_parse__mlift_parse_10548_fun2070, kk_context());
  _self->err1 = err1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_text_parse__mlift_parse_10548_fun2070(kk_function_t _fself, kk_box_t _b_x45, kk_context_t* _ctx) {
  struct kk_std_text_parse__mlift_parse_10548_fun2070__t* _self = kk_function_as(struct kk_std_text_parse__mlift_parse_10548_fun2070__t*, _fself, _ctx);
  kk_std_text_parse__parse_error err1 = _self->err1; /* std/text/parse/parse-error<1455> */
  kk_drop_match(_self, {kk_std_text_parse__parse_error_dup(err1, _ctx);}, {}, _ctx)
  kk_std_text_parse__parse_error _x_x2071;
  kk_std_text_parse__parse_error _y_x10375_47 = kk_std_text_parse__parse_error_unbox(_b_x45, KK_OWNED, _ctx); /*std/text/parse/parse-error<1455>*/;
  if (kk_std_text_parse__is_ParseOk(_y_x10375_47, _ctx)) {
    struct kk_std_text_parse_ParseOk* _con_x2072 = kk_std_text_parse__as_ParseOk(_y_x10375_47, _ctx);
    kk_std_core_sslice__sslice rest2 = _con_x2072->rest;
    kk_box_t x2 = _con_x2072->result;
    kk_std_text_parse__parse_error_drop(err1, _ctx);
    kk_reuse_t _ru_x1935 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_y_x10375_47, _ctx)) {
      _ru_x1935 = (kk_datatype_ptr_reuse(_y_x10375_47, _ctx));
    }
    else {
      kk_std_core_sslice__sslice_dup(rest2, _ctx);
      kk_box_dup(x2, _ctx);
      kk_datatype_ptr_decref(_y_x10375_47, _ctx);
    }
    _x_x2071 = kk_std_text_parse__new_ParseOk(_ru_x1935, 0, x2, rest2, _ctx); /*std/text/parse/parse-error<33>*/
  }
  else {
    kk_std_text_parse__parse_error_drop(_y_x10375_47, _ctx);
    _x_x2071 = err1; /*std/text/parse/parse-error<33>*/
  }
  return kk_std_text_parse__parse_error_box(_x_x2071, _ctx);
}

kk_std_text_parse__parse_error kk_std_text_parse__mlift_parse_10548(kk_std_text_parse__parse_error err1, kk_function_t resume, kk_unit_t wild__, kk_context_t* _ctx) { /* forall<h,a,e> (err1 : parse-error<a>, resume : (bool) -> <local<h>|e> parse-error<a>, wild_ : ()) -> <local<h>|e> parse-error<a> */ 
  kk_std_text_parse__parse_error x_10613 = kk_function_call(kk_std_text_parse__parse_error, (kk_function_t, bool, kk_context_t*), resume, (resume, false, _ctx), _ctx); /*std/text/parse/parse-error<1455>*/;
  if (kk_yielding(kk_context())) {
    kk_std_text_parse__parse_error_drop(x_10613, _ctx);
    kk_box_t _x_x2069 = kk_std_core_hnd_yield_extend(kk_std_text_parse__new_mlift_parse_10548_fun2070(err1, _ctx), _ctx); /*2419*/
    return kk_std_text_parse__parse_error_unbox(_x_x2069, KK_OWNED, _ctx);
  }
  {
    kk_std_text_parse__parse_error _y_x10375_48 = x_10613; /*std/text/parse/parse-error<1455>*/;
    if (kk_std_text_parse__is_ParseOk(_y_x10375_48, _ctx)) {
      struct kk_std_text_parse_ParseOk* _con_x2073 = kk_std_text_parse__as_ParseOk(_y_x10375_48, _ctx);
      kk_std_core_sslice__sslice rest2 = _con_x2073->rest;
      kk_box_t x2 = _con_x2073->result;
      kk_std_text_parse__parse_error_drop(err1, _ctx);
      kk_reuse_t _ru_x1938 = kk_reuse_null; /*@reuse*/;
      if kk_likely(kk_datatype_ptr_is_unique(_y_x10375_48, _ctx)) {
        _ru_x1938 = (kk_datatype_ptr_reuse(_y_x10375_48, _ctx));
      }
      else {
        kk_std_core_sslice__sslice_dup(rest2, _ctx);
        kk_box_dup(x2, _ctx);
        kk_datatype_ptr_decref(_y_x10375_48, _ctx);
      }
      return kk_std_text_parse__new_ParseOk(_ru_x1938, 0, x2, rest2, _ctx);
    }
    {
      kk_std_text_parse__parse_error_drop(_y_x10375_48, _ctx);
      return err1;
    }
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_text_parse__mlift_parse_10549_fun2076__t {
  struct kk_function_s _base;
  kk_std_text_parse__parse_error _y_x10373;
  kk_function_t resume;
};
static kk_box_t kk_std_text_parse__mlift_parse_10549_fun2076(kk_function_t _fself, kk_box_t _b_x54, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse__new_mlift_parse_10549_fun2076(kk_std_text_parse__parse_error _y_x10373, kk_function_t resume, kk_context_t* _ctx) {
  struct kk_std_text_parse__mlift_parse_10549_fun2076__t* _self = kk_function_alloc_as(struct kk_std_text_parse__mlift_parse_10549_fun2076__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_text_parse__mlift_parse_10549_fun2076, kk_context());
  _self->_y_x10373 = _y_x10373;
  _self->resume = resume;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_text_parse__mlift_parse_10549_fun2076(kk_function_t _fself, kk_box_t _b_x54, kk_context_t* _ctx) {
  struct kk_std_text_parse__mlift_parse_10549_fun2076__t* _self = kk_function_as(struct kk_std_text_parse__mlift_parse_10549_fun2076__t*, _fself, _ctx);
  kk_std_text_parse__parse_error _y_x10373 = _self->_y_x10373; /* std/text/parse/parse-error<1455> */
  kk_function_t resume = _self->resume; /* (bool) -> <local<1445>|1456> std/text/parse/parse-error<1455> */
  kk_drop_match(_self, {kk_std_text_parse__parse_error_dup(_y_x10373, _ctx);kk_function_dup(resume, _ctx);}, {}, _ctx)
  kk_unit_t wild___56 = kk_Unit;
  kk_unit_unbox(_b_x54);
  kk_std_text_parse__parse_error _x_x2077 = kk_std_text_parse__mlift_parse_10548(_y_x10373, resume, wild___56, _ctx); /*std/text/parse/parse-error<1455>*/
  return kk_std_text_parse__parse_error_box(_x_x2077, _ctx);
}

kk_std_text_parse__parse_error kk_std_text_parse__mlift_parse_10549(kk_ref_t input, kk_function_t resume, kk_std_core_sslice__sslice save, kk_std_text_parse__parse_error _y_x10373, kk_context_t* _ctx) { /* forall<h,a,e> (input : local-var<h,sslice/sslice>, resume : (bool) -> <local<h>|e> parse-error<a>, save : sslice/sslice, parse-error<a>) -> <local<h>|e> parse-error<a> */ 
  if (kk_std_text_parse__is_ParseOk(_y_x10373, _ctx)) {
    struct kk_std_text_parse_ParseOk* _con_x2074 = kk_std_text_parse__as_ParseOk(_y_x10373, _ctx);
    kk_std_core_sslice__sslice rest1 = _con_x2074->rest;
    kk_box_t x1 = _con_x2074->result;
    kk_std_core_sslice__sslice_drop(save, _ctx);
    kk_function_drop(resume, _ctx);
    kk_ref_drop(input, _ctx);
    kk_reuse_t _ru_x1941 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_y_x10373, _ctx)) {
      _ru_x1941 = (kk_datatype_ptr_reuse(_y_x10373, _ctx));
    }
    else {
      kk_std_core_sslice__sslice_dup(rest1, _ctx);
      kk_box_dup(x1, _ctx);
      kk_datatype_ptr_decref(_y_x10373, _ctx);
    }
    return kk_std_text_parse__new_ParseOk(_ru_x1941, 0, x1, rest1, _ctx);
  }
  {
    kk_unit_t x_10617 = kk_Unit;
    kk_unit_t _brw_x1922 = kk_Unit;
    kk_ref_set_borrow(input,(kk_std_core_sslice__sslice_box(save, _ctx)),kk_context());
    kk_ref_drop(input, _ctx);
    _brw_x1922;
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x2075 = kk_std_core_hnd_yield_extend(kk_std_text_parse__new_mlift_parse_10549_fun2076(_y_x10373, resume, _ctx), _ctx); /*2419*/
      return kk_std_text_parse__parse_error_unbox(_x_x2075, KK_OWNED, _ctx);
    }
    {
      return kk_std_text_parse__mlift_parse_10548(_y_x10373, resume, x_10617, _ctx);
    }
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_text_parse__mlift_parse_10550_fun2080__t {
  struct kk_function_s _base;
  kk_ref_t input;
  kk_function_t resume;
  kk_std_core_sslice__sslice save;
};
static kk_box_t kk_std_text_parse__mlift_parse_10550_fun2080(kk_function_t _fself, kk_box_t _b_x58, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse__new_mlift_parse_10550_fun2080(kk_ref_t input, kk_function_t resume, kk_std_core_sslice__sslice save, kk_context_t* _ctx) {
  struct kk_std_text_parse__mlift_parse_10550_fun2080__t* _self = kk_function_alloc_as(struct kk_std_text_parse__mlift_parse_10550_fun2080__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_text_parse__mlift_parse_10550_fun2080, kk_context());
  _self->input = input;
  _self->resume = resume;
  _self->save = save;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_text_parse__mlift_parse_10550_fun2080(kk_function_t _fself, kk_box_t _b_x58, kk_context_t* _ctx) {
  struct kk_std_text_parse__mlift_parse_10550_fun2080__t* _self = kk_function_as(struct kk_std_text_parse__mlift_parse_10550_fun2080__t*, _fself, _ctx);
  kk_ref_t input = _self->input; /* local-var<1445,sslice/sslice> */
  kk_function_t resume = _self->resume; /* (bool) -> <local<1445>|1456> std/text/parse/parse-error<1455> */
  kk_std_core_sslice__sslice save = _self->save; /* sslice/sslice */
  kk_drop_match(_self, {kk_ref_dup(input, _ctx);kk_function_dup(resume, _ctx);kk_std_core_sslice__sslice_dup(save, _ctx);}, {}, _ctx)
  kk_std_text_parse__parse_error _y_x10373_60 = kk_std_text_parse__parse_error_unbox(_b_x58, KK_OWNED, _ctx); /*std/text/parse/parse-error<1455>*/;
  kk_std_text_parse__parse_error _x_x2081 = kk_std_text_parse__mlift_parse_10549(input, resume, save, _y_x10373_60, _ctx); /*std/text/parse/parse-error<1455>*/
  return kk_std_text_parse__parse_error_box(_x_x2081, _ctx);
}

kk_std_text_parse__parse_error kk_std_text_parse__mlift_parse_10550(kk_ref_t input, kk_function_t resume, kk_std_core_sslice__sslice save, kk_context_t* _ctx) { /* forall<h,a,e> (input : local-var<h,sslice/sslice>, resume : (bool) -> <local<h>|e> parse-error<a>, save : sslice/sslice) -> <local<h>|e> parse-error<a> */ 
  kk_std_text_parse__parse_error x_10619;
  kk_function_t _x_x2078 = kk_function_dup(resume, _ctx); /*(bool) -> <local<1445>|1456> std/text/parse/parse-error<1455>*/
  x_10619 = kk_function_call(kk_std_text_parse__parse_error, (kk_function_t, bool, kk_context_t*), _x_x2078, (_x_x2078, true, _ctx), _ctx); /*std/text/parse/parse-error<1455>*/
  if (kk_yielding(kk_context())) {
    kk_std_text_parse__parse_error_drop(x_10619, _ctx);
    kk_box_t _x_x2079 = kk_std_core_hnd_yield_extend(kk_std_text_parse__new_mlift_parse_10550_fun2080(input, resume, save, _ctx), _ctx); /*2419*/
    return kk_std_text_parse__parse_error_unbox(_x_x2079, KK_OWNED, _ctx);
  }
  {
    return kk_std_text_parse__mlift_parse_10549(input, resume, save, x_10619, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_text_parse__mlift_parse_10552_fun2083__t {
  struct kk_function_s _base;
  kk_box_t x;
};
static kk_box_t kk_std_text_parse__mlift_parse_10552_fun2083(kk_function_t _fself, kk_box_t _b_x68, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse__new_mlift_parse_10552_fun2083(kk_box_t x, kk_context_t* _ctx) {
  struct kk_std_text_parse__mlift_parse_10552_fun2083__t* _self = kk_function_alloc_as(struct kk_std_text_parse__mlift_parse_10552_fun2083__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_text_parse__mlift_parse_10552_fun2083, kk_context());
  _self->x = x;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_text_parse__mlift_parse_10552_fun2083(kk_function_t _fself, kk_box_t _b_x68, kk_context_t* _ctx) {
  struct kk_std_text_parse__mlift_parse_10552_fun2083__t* _self = kk_function_as(struct kk_std_text_parse__mlift_parse_10552_fun2083__t*, _fself, _ctx);
  kk_box_t x = _self->x; /* 1394 */
  kk_drop_match(_self, {kk_box_dup(x, _ctx);}, {}, _ctx)
  kk_unit_t wild___0_70 = kk_Unit;
  kk_unit_unbox(_b_x68);
  kk_std_core_types__maybe _x_x2084 = kk_std_core_types__new_Just(x, _ctx); /*maybe<88>*/
  return kk_std_core_types__maybe_box(_x_x2084, _ctx);
}

kk_std_core_types__maybe kk_std_text_parse__mlift_parse_10552(kk_ref_t input, kk_function_t pred, kk_std_core_sslice__sslice inp, kk_context_t* _ctx) { /* forall<a,h,e> (input : local-var<h,sslice/sslice>, pred : (sslice/sslice) -> maybe<(a, sslice/sslice)>, inp : sslice/sslice) -> <local<h>|e> maybe<a> */ 
  kk_std_core_types__maybe _match_x1917 = kk_function_call(kk_std_core_types__maybe, (kk_function_t, kk_std_core_sslice__sslice, kk_context_t*), pred, (pred, inp, _ctx), _ctx); /*maybe<(1394, sslice/sslice)>*/;
  if (kk_std_core_types__is_Just(_match_x1917, _ctx)) {
    kk_box_t _box_x61 = _match_x1917._cons.Just.value;
    kk_std_core_types__tuple2 _pat_9 = kk_std_core_types__tuple2_unbox(_box_x61, KK_BORROWED, _ctx);
    kk_box_t _box_x62 = _pat_9.snd;
    kk_std_core_sslice__sslice cap = kk_std_core_sslice__sslice_unbox(_box_x62, KK_BORROWED, _ctx);
    kk_box_t x = _pat_9.fst;
    kk_std_core_sslice__sslice_dup(cap, _ctx);
    kk_box_dup(x, _ctx);
    kk_std_core_types__maybe_drop(_match_x1917, _ctx);
    kk_unit_t x_0_10621 = kk_Unit;
    kk_unit_t _brw_x1919 = kk_Unit;
    kk_ref_set_borrow(input,(kk_std_core_sslice__sslice_box(cap, _ctx)),kk_context());
    kk_ref_drop(input, _ctx);
    _brw_x1919;
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x2082 = kk_std_core_hnd_yield_extend(kk_std_text_parse__new_mlift_parse_10552_fun2083(x, _ctx), _ctx); /*2419*/
      return kk_std_core_types__maybe_unbox(_x_x2082, KK_OWNED, _ctx);
    }
    {
      return kk_std_core_types__new_Just(x, _ctx);
    }
  }
  {
    kk_ref_drop(input, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
}
 
// Parses `input0` with `p`.
//
// This implements the `pick` ctl using a depth-first search,
//   short-circuiting if the `True` branch succeeds.
// If both alternatives of a `pick` invoke `fail`,
//   the first error will be returned.


// lift anonymous function
struct kk_std_text_parse_parse_fun2087__t {
  struct kk_function_s _base;
  kk_ref_t loc;
};
static kk_box_t kk_std_text_parse_parse_fun2087(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_parse_fun2087(kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_std_text_parse_parse_fun2087__t* _self = kk_function_alloc_as(struct kk_std_text_parse_parse_fun2087__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_text_parse_parse_fun2087, kk_context());
  _self->loc = loc;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_text_parse_parse_fun2087(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_text_parse_parse_fun2087__t* _self = kk_function_as(struct kk_std_text_parse_parse_fun2087__t*, _fself, _ctx);
  kk_ref_t loc = _self->loc; /* local-var<1445,sslice/sslice> */
  kk_drop_match(_self, {kk_ref_dup(loc, _ctx);}, {}, _ctx)
  return kk_ref_get(loc,kk_context());
}


// lift anonymous function
struct kk_std_text_parse_parse_fun2090__t {
  struct kk_function_s _base;
  kk_ref_t loc;
};
static kk_box_t kk_std_text_parse_parse_fun2090(kk_function_t _fself, int32_t _b_x87, kk_std_core_hnd__ev _b_x88, kk_box_t _b_x89, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_parse_fun2090(kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_std_text_parse_parse_fun2090__t* _self = kk_function_alloc_as(struct kk_std_text_parse_parse_fun2090__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_text_parse_parse_fun2090, kk_context());
  _self->loc = loc;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_text_parse_parse_fun2091__t {
  struct kk_function_s _base;
  kk_box_t _b_x89;
  kk_ref_t loc;
};
static kk_box_t kk_std_text_parse_parse_fun2091(kk_function_t _fself, kk_function_t _b_x84, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_parse_fun2091(kk_box_t _b_x89, kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_std_text_parse_parse_fun2091__t* _self = kk_function_alloc_as(struct kk_std_text_parse_parse_fun2091__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_text_parse_parse_fun2091, kk_context());
  _self->_b_x89 = _b_x89;
  _self->loc = loc;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_text_parse_parse_fun2095__t {
  struct kk_function_s _base;
  kk_box_t _b_x89;
};
static kk_box_t kk_std_text_parse_parse_fun2095(kk_function_t _fself, kk_box_t _b_x81, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_parse_fun2095(kk_box_t _b_x89, kk_context_t* _ctx) {
  struct kk_std_text_parse_parse_fun2095__t* _self = kk_function_alloc_as(struct kk_std_text_parse_parse_fun2095__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_text_parse_parse_fun2095, kk_context());
  _self->_b_x89 = _b_x89;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_text_parse_parse_fun2095(kk_function_t _fself, kk_box_t _b_x81, kk_context_t* _ctx) {
  struct kk_std_text_parse_parse_fun2095__t* _self = kk_function_as(struct kk_std_text_parse_parse_fun2095__t*, _fself, _ctx);
  kk_box_t _b_x89 = _self->_b_x89; /* 45 */
  kk_drop_match(_self, {kk_box_dup(_b_x89, _ctx);}, {}, _ctx)
  kk_std_text_parse__parse_error _x_x2096;
  kk_string_t _x_x2097 = kk_string_unbox(_b_x89); /*string*/
  kk_std_core_sslice__sslice _x_x2098 = kk_std_core_sslice__sslice_unbox(_b_x81, KK_OWNED, _ctx); /*sslice/sslice*/
  _x_x2096 = kk_std_text_parse__new_ParseError(kk_reuse_null, 0, _x_x2097, _x_x2098, _ctx); /*std/text/parse/parse-error<33>*/
  return kk_std_text_parse__parse_error_box(_x_x2096, _ctx);
}
static kk_box_t kk_std_text_parse_parse_fun2091(kk_function_t _fself, kk_function_t _b_x84, kk_context_t* _ctx) {
  struct kk_std_text_parse_parse_fun2091__t* _self = kk_function_as(struct kk_std_text_parse_parse_fun2091__t*, _fself, _ctx);
  kk_box_t _b_x89 = _self->_b_x89; /* 45 */
  kk_ref_t loc = _self->loc; /* local-var<1445,sslice/sslice> */
  kk_drop_match(_self, {kk_box_dup(_b_x89, _ctx);kk_ref_dup(loc, _ctx);}, {}, _ctx)
  kk_function_drop(_b_x84, _ctx);
  kk_std_core_sslice__sslice x_0_10628;
  kk_box_t _x_x2092 = kk_ref_get(loc,kk_context()); /*298*/
  x_0_10628 = kk_std_core_sslice__sslice_unbox(_x_x2092, KK_OWNED, _ctx); /*sslice/sslice*/
  kk_std_text_parse__parse_error _x_x2093;
  if (kk_yielding(kk_context())) {
    kk_std_core_sslice__sslice_drop(x_0_10628, _ctx);
    kk_box_t _x_x2094 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_parse_fun2095(_b_x89, _ctx), _ctx); /*2419*/
    _x_x2093 = kk_std_text_parse__parse_error_unbox(_x_x2094, KK_OWNED, _ctx); /*std/text/parse/parse-error<1455>*/
  }
  else {
    kk_string_t _x_x2099 = kk_string_unbox(_b_x89); /*string*/
    _x_x2093 = kk_std_text_parse__new_ParseError(kk_reuse_null, 0, _x_x2099, x_0_10628, _ctx); /*std/text/parse/parse-error<1455>*/
  }
  return kk_std_text_parse__parse_error_box(_x_x2093, _ctx);
}
static kk_box_t kk_std_text_parse_parse_fun2090(kk_function_t _fself, int32_t _b_x87, kk_std_core_hnd__ev _b_x88, kk_box_t _b_x89, kk_context_t* _ctx) {
  struct kk_std_text_parse_parse_fun2090__t* _self = kk_function_as(struct kk_std_text_parse_parse_fun2090__t*, _fself, _ctx);
  kk_ref_t loc = _self->loc; /* local-var<1445,sslice/sslice> */
  kk_drop_match(_self, {kk_ref_dup(loc, _ctx);}, {}, _ctx)
  kk_datatype_ptr_dropn(_b_x88, (KK_I32(3)), _ctx);
  return kk_std_core_hnd_yield_to_final(_b_x87, kk_std_text_parse_new_parse_fun2091(_b_x89, loc, _ctx), _ctx);
}


// lift anonymous function
struct kk_std_text_parse_parse_fun2102__t {
  struct kk_function_s _base;
  kk_ref_t loc;
};
static kk_box_t kk_std_text_parse_parse_fun2102(kk_function_t _fself, kk_function_t _b_x97, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_parse_fun2102(kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_std_text_parse_parse_fun2102__t* _self = kk_function_alloc_as(struct kk_std_text_parse_parse_fun2102__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_text_parse_parse_fun2102, kk_context());
  _self->loc = loc;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_text_parse_parse_fun2103__t {
  struct kk_function_s _base;
  kk_function_t _b_x97;
};
static kk_std_text_parse__parse_error kk_std_text_parse_parse_fun2103(kk_function_t _fself, bool _b_x98, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_parse_fun2103(kk_function_t _b_x97, kk_context_t* _ctx) {
  struct kk_std_text_parse_parse_fun2103__t* _self = kk_function_alloc_as(struct kk_std_text_parse_parse_fun2103__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_text_parse_parse_fun2103, kk_context());
  _self->_b_x97 = _b_x97;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_text_parse__parse_error kk_std_text_parse_parse_fun2103(kk_function_t _fself, bool _b_x98, kk_context_t* _ctx) {
  struct kk_std_text_parse_parse_fun2103__t* _self = kk_function_as(struct kk_std_text_parse_parse_fun2103__t*, _fself, _ctx);
  kk_function_t _b_x97 = _self->_b_x97; /* (6896) -> 6897 6899 */
  kk_drop_match(_self, {kk_function_dup(_b_x97, _ctx);}, {}, _ctx)
  kk_box_t _x_x2104 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _b_x97, (_b_x97, kk_bool_box(_b_x98), _ctx), _ctx); /*6899*/
  return kk_std_text_parse__parse_error_unbox(_x_x2104, KK_OWNED, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_parse_fun2109__t {
  struct kk_function_s _base;
  kk_ref_t loc;
  kk_function_t resume_144;
};
static kk_box_t kk_std_text_parse_parse_fun2109(kk_function_t _fself, kk_box_t _b_x95, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_parse_fun2109(kk_ref_t loc, kk_function_t resume_144, kk_context_t* _ctx) {
  struct kk_std_text_parse_parse_fun2109__t* _self = kk_function_alloc_as(struct kk_std_text_parse_parse_fun2109__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_text_parse_parse_fun2109, kk_context());
  _self->loc = loc;
  _self->resume_144 = resume_144;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_text_parse_parse_fun2109(kk_function_t _fself, kk_box_t _b_x95, kk_context_t* _ctx) {
  struct kk_std_text_parse_parse_fun2109__t* _self = kk_function_as(struct kk_std_text_parse_parse_fun2109__t*, _fself, _ctx);
  kk_ref_t loc = _self->loc; /* local-var<1445,sslice/sslice> */
  kk_function_t resume_144 = _self->resume_144; /* (bool) -> <local<1445>|1456> std/text/parse/parse-error<1455> */
  kk_drop_match(_self, {kk_ref_dup(loc, _ctx);kk_function_dup(resume_144, _ctx);}, {}, _ctx)
  kk_std_text_parse__parse_error _x_x2110;
  kk_std_core_sslice__sslice _x_x2111 = kk_std_core_sslice__sslice_unbox(_b_x95, KK_OWNED, _ctx); /*sslice/sslice*/
  _x_x2110 = kk_std_text_parse__mlift_parse_10550(loc, resume_144, _x_x2111, _ctx); /*std/text/parse/parse-error<1455>*/
  return kk_std_text_parse__parse_error_box(_x_x2110, _ctx);
}
static kk_box_t kk_std_text_parse_parse_fun2102(kk_function_t _fself, kk_function_t _b_x97, kk_context_t* _ctx) {
  struct kk_std_text_parse_parse_fun2102__t* _self = kk_function_as(struct kk_std_text_parse_parse_fun2102__t*, _fself, _ctx);
  kk_ref_t loc = _self->loc; /* local-var<1445,sslice/sslice> */
  kk_drop_match(_self, {kk_ref_dup(loc, _ctx);}, {}, _ctx)
  kk_function_t resume_144 = kk_std_text_parse_new_parse_fun2103(_b_x97, _ctx); /*(bool) -> <local<1445>|1456> std/text/parse/parse-error<1455>*/;
  kk_std_core_sslice__sslice x_1_10632;
  kk_box_t _x_x2105;
  kk_ref_t _x_x2106 = kk_ref_dup(loc, _ctx); /*local-var<1445,sslice/sslice>*/
  _x_x2105 = kk_ref_get(_x_x2106,kk_context()); /*298*/
  x_1_10632 = kk_std_core_sslice__sslice_unbox(_x_x2105, KK_OWNED, _ctx); /*sslice/sslice*/
  kk_std_text_parse__parse_error _x_x2107;
  if (kk_yielding(kk_context())) {
    kk_std_core_sslice__sslice_drop(x_1_10632, _ctx);
    kk_box_t _x_x2108 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_parse_fun2109(loc, resume_144, _ctx), _ctx); /*2419*/
    _x_x2107 = kk_std_text_parse__parse_error_unbox(_x_x2108, KK_OWNED, _ctx); /*std/text/parse/parse-error<1455>*/
  }
  else {
    _x_x2107 = kk_std_text_parse__mlift_parse_10550(loc, resume_144, x_1_10632, _ctx); /*std/text/parse/parse-error<1455>*/
  }
  return kk_std_text_parse__parse_error_box(_x_x2107, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_parse_fun2114__t {
  struct kk_function_s _base;
  kk_ref_t loc;
};
static kk_box_t kk_std_text_parse_parse_fun2114(kk_function_t _fself, kk_box_t _b_x106, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_parse_fun2114(kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_std_text_parse_parse_fun2114__t* _self = kk_function_alloc_as(struct kk_std_text_parse_parse_fun2114__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_text_parse_parse_fun2114, kk_context());
  _self->loc = loc;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_text_parse_parse_fun2115__t {
  struct kk_function_s _base;
  kk_box_t _b_x106;
};
static kk_std_core_types__maybe kk_std_text_parse_parse_fun2115(kk_function_t _fself, kk_std_core_sslice__sslice _b_x109, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_parse_fun2115(kk_box_t _b_x106, kk_context_t* _ctx) {
  struct kk_std_text_parse_parse_fun2115__t* _self = kk_function_alloc_as(struct kk_std_text_parse_parse_fun2115__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_text_parse_parse_fun2115, kk_context());
  _self->_b_x106 = _b_x106;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_core_types__maybe kk_std_text_parse_parse_fun2115(kk_function_t _fself, kk_std_core_sslice__sslice _b_x109, kk_context_t* _ctx) {
  struct kk_std_text_parse_parse_fun2115__t* _self = kk_function_as(struct kk_std_text_parse_parse_fun2115__t*, _fself, _ctx);
  kk_box_t _b_x106 = _self->_b_x106; /* 6236 */
  kk_drop_match(_self, {kk_box_dup(_b_x106, _ctx);}, {}, _ctx)
  kk_box_t _x_x2116;
  kk_function_t _x_x2117 = kk_function_unbox(_b_x106, _ctx); /*(107) -> 108*/
  _x_x2116 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _x_x2117, (_x_x2117, kk_std_core_sslice__sslice_box(_b_x109, _ctx), _ctx), _ctx); /*108*/
  return kk_std_core_types__maybe_unbox(_x_x2116, KK_OWNED, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_parse_fun2122__t {
  struct kk_function_s _base;
  kk_ref_t loc;
  kk_function_t pred_145;
};
static kk_box_t kk_std_text_parse_parse_fun2122(kk_function_t _fself, kk_box_t _b_x104, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_parse_fun2122(kk_ref_t loc, kk_function_t pred_145, kk_context_t* _ctx) {
  struct kk_std_text_parse_parse_fun2122__t* _self = kk_function_alloc_as(struct kk_std_text_parse_parse_fun2122__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_text_parse_parse_fun2122, kk_context());
  _self->loc = loc;
  _self->pred_145 = pred_145;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_text_parse_parse_fun2122(kk_function_t _fself, kk_box_t _b_x104, kk_context_t* _ctx) {
  struct kk_std_text_parse_parse_fun2122__t* _self = kk_function_as(struct kk_std_text_parse_parse_fun2122__t*, _fself, _ctx);
  kk_ref_t loc = _self->loc; /* local-var<1445,sslice/sslice> */
  kk_function_t pred_145 = _self->pred_145; /* (sslice/sslice) -> maybe<(1394, sslice/sslice)> */
  kk_drop_match(_self, {kk_ref_dup(loc, _ctx);kk_function_dup(pred_145, _ctx);}, {}, _ctx)
  kk_std_core_types__maybe _x_x2123;
  kk_std_core_sslice__sslice _x_x2124 = kk_std_core_sslice__sslice_unbox(_b_x104, KK_OWNED, _ctx); /*sslice/sslice*/
  _x_x2123 = kk_std_text_parse__mlift_parse_10552(loc, pred_145, _x_x2124, _ctx); /*maybe<1394>*/
  return kk_std_core_types__maybe_box(_x_x2123, _ctx);
}
static kk_box_t kk_std_text_parse_parse_fun2114(kk_function_t _fself, kk_box_t _b_x106, kk_context_t* _ctx) {
  struct kk_std_text_parse_parse_fun2114__t* _self = kk_function_as(struct kk_std_text_parse_parse_fun2114__t*, _fself, _ctx);
  kk_ref_t loc = _self->loc; /* local-var<1445,sslice/sslice> */
  kk_drop_match(_self, {kk_ref_dup(loc, _ctx);}, {}, _ctx)
  kk_function_t pred_145 = kk_std_text_parse_new_parse_fun2115(_b_x106, _ctx); /*(sslice/sslice) -> maybe<(1394, sslice/sslice)>*/;
  kk_std_core_sslice__sslice x_2_10634;
  kk_box_t _x_x2118;
  kk_ref_t _x_x2119 = kk_ref_dup(loc, _ctx); /*local-var<1445,sslice/sslice>*/
  _x_x2118 = kk_ref_get(_x_x2119,kk_context()); /*298*/
  x_2_10634 = kk_std_core_sslice__sslice_unbox(_x_x2118, KK_OWNED, _ctx); /*sslice/sslice*/
  kk_std_core_types__maybe _x_x2120;
  if (kk_yielding(kk_context())) {
    kk_std_core_sslice__sslice_drop(x_2_10634, _ctx);
    kk_box_t _x_x2121 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_parse_fun2122(loc, pred_145, _ctx), _ctx); /*2419*/
    _x_x2120 = kk_std_core_types__maybe_unbox(_x_x2121, KK_OWNED, _ctx); /*maybe<1394>*/
  }
  else {
    _x_x2120 = kk_std_text_parse__mlift_parse_10552(loc, pred_145, x_2_10634, _ctx); /*maybe<1394>*/
  }
  return kk_std_core_types__maybe_box(_x_x2120, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_parse_fun2127__t {
  struct kk_function_s _base;
  kk_ref_t loc;
};
static kk_box_t kk_std_text_parse_parse_fun2127(kk_function_t _fself, kk_box_t _b_x119, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_parse_fun2127(kk_ref_t loc, kk_context_t* _ctx) {
  struct kk_std_text_parse_parse_fun2127__t* _self = kk_function_alloc_as(struct kk_std_text_parse_parse_fun2127__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_text_parse_parse_fun2127, kk_context());
  _self->loc = loc;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_text_parse_parse_fun2131__t {
  struct kk_function_s _base;
  kk_box_t _b_x119;
};
static kk_box_t kk_std_text_parse_parse_fun2131(kk_function_t _fself, kk_box_t _b_x115, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_parse_fun2131(kk_box_t _b_x119, kk_context_t* _ctx) {
  struct kk_std_text_parse_parse_fun2131__t* _self = kk_function_alloc_as(struct kk_std_text_parse_parse_fun2131__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_text_parse_parse_fun2131, kk_context());
  _self->_b_x119 = _b_x119;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_text_parse_parse_fun2131(kk_function_t _fself, kk_box_t _b_x115, kk_context_t* _ctx) {
  struct kk_std_text_parse_parse_fun2131__t* _self = kk_function_as(struct kk_std_text_parse_parse_fun2131__t*, _fself, _ctx);
  kk_box_t _b_x119 = _self->_b_x119; /* 384 */
  kk_drop_match(_self, {kk_box_dup(_b_x119, _ctx);}, {}, _ctx)
  kk_std_text_parse__parse_error _x_x2132;
  kk_std_core_sslice__sslice _x_x2133 = kk_std_core_sslice__sslice_unbox(_b_x115, KK_OWNED, _ctx); /*sslice/sslice*/
  _x_x2132 = kk_std_text_parse__new_ParseOk(kk_reuse_null, 0, _b_x119, _x_x2133, _ctx); /*std/text/parse/parse-error<33>*/
  return kk_std_text_parse__parse_error_box(_x_x2132, _ctx);
}
static kk_box_t kk_std_text_parse_parse_fun2127(kk_function_t _fself, kk_box_t _b_x119, kk_context_t* _ctx) {
  struct kk_std_text_parse_parse_fun2127__t* _self = kk_function_as(struct kk_std_text_parse_parse_fun2127__t*, _fself, _ctx);
  kk_ref_t loc = _self->loc; /* local-var<1445,sslice/sslice> */
  kk_drop_match(_self, {kk_ref_dup(loc, _ctx);}, {}, _ctx)
  kk_std_core_sslice__sslice x_3_10636;
  kk_box_t _x_x2128 = kk_ref_get(loc,kk_context()); /*298*/
  x_3_10636 = kk_std_core_sslice__sslice_unbox(_x_x2128, KK_OWNED, _ctx); /*sslice/sslice*/
  kk_std_text_parse__parse_error _x_x2129;
  if (kk_yielding(kk_context())) {
    kk_std_core_sslice__sslice_drop(x_3_10636, _ctx);
    kk_box_t _x_x2130 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_parse_fun2131(_b_x119, _ctx), _ctx); /*2419*/
    _x_x2129 = kk_std_text_parse__parse_error_unbox(_x_x2130, KK_OWNED, _ctx); /*std/text/parse/parse-error<1455>*/
  }
  else {
    _x_x2129 = kk_std_text_parse__new_ParseOk(kk_reuse_null, 0, _b_x119, x_3_10636, _ctx); /*std/text/parse/parse-error<1455>*/
  }
  return kk_std_text_parse__parse_error_box(_x_x2129, _ctx);
}

kk_std_text_parse__parse_error kk_std_text_parse_parse(kk_std_core_sslice__sslice input0, kk_function_t p, kk_context_t* _ctx) { /* forall<a,e> (input0 : sslice/sslice, p : () -> <parse|e> a) -> e parse-error<a> */ 
  kk_ref_t loc = kk_ref_alloc((kk_std_core_sslice__sslice_box(input0, _ctx)),kk_context()); /*local-var<1445,sslice/sslice>*/;
  kk_std_text_parse__parse _b_x116_120;
  kk_std_core_hnd__clause0 _x_x2085;
  kk_function_t _x_x2086;
  kk_ref_dup(loc, _ctx);
  _x_x2086 = kk_std_text_parse_new_parse_fun2087(loc, _ctx); /*() -> 6965 298*/
  _x_x2085 = kk_std_core_hnd_clause_tail0(_x_x2086, _ctx); /*hnd/clause0<6968,6967,6965,6966>*/
  kk_std_core_hnd__clause1 _x_x2088;
  kk_function_t _x_x2089;
  kk_ref_dup(loc, _ctx);
  _x_x2089 = kk_std_text_parse_new_parse_fun2090(loc, _ctx); /*(hnd/marker<48,49>, hnd/ev<47>, 45) -> 48 2716*/
  _x_x2088 = kk_std_core_hnd__new_Clause1(_x_x2089, _ctx); /*hnd/clause1<45,46,47,48,49>*/
  kk_std_core_hnd__clause0 _x_x2100;
  kk_function_t _x_x2101;
  kk_ref_dup(loc, _ctx);
  _x_x2101 = kk_std_text_parse_new_parse_fun2102(loc, _ctx); /*((6896) -> 6897 6899) -> 6897 6899*/
  _x_x2100 = kk_std_core_hnd_clause_control0(_x_x2101, _ctx); /*hnd/clause0<6896,6898,6897,6899>*/
  kk_std_core_hnd__clause1 _x_x2112;
  kk_function_t _x_x2113;
  kk_ref_dup(loc, _ctx);
  _x_x2113 = kk_std_text_parse_new_parse_fun2114(loc, _ctx); /*(6236) -> 6233 6237*/
  _x_x2112 = kk_std_core_hnd_clause_tail1(_x_x2113, _ctx); /*hnd/clause1<6236,6237,6235,6233,6234>*/
  _b_x116_120 = kk_std_text_parse__new_Hnd_parse(kk_reuse_null, 0, kk_integer_from_small(3), _x_x2085, _x_x2088, _x_x2100, _x_x2112, _ctx); /*std/text/parse/parse<<local<1445>|1456>,std/text/parse/parse-error<1455>>*/
  kk_std_text_parse__parse_error res;
  kk_box_t _x_x2125;
  kk_function_t _x_x2126;
  kk_ref_dup(loc, _ctx);
  _x_x2126 = kk_std_text_parse_new_parse_fun2127(loc, _ctx); /*(384) -> 385 386*/
  _x_x2125 = kk_std_text_parse_parse_fs__handle(_b_x116_120, _x_x2126, p, _ctx); /*386*/
  res = kk_std_text_parse__parse_error_unbox(_x_x2125, KK_OWNED, _ctx); /*std/text/parse/parse-error<1455>*/
  kk_box_t _x_x2134 = kk_std_core_hnd_prompt_local_var(loc, kk_std_text_parse__parse_error_box(res, _ctx), _ctx); /*4162*/
  return kk_std_text_parse__parse_error_unbox(_x_x2134, KK_OWNED, _ctx);
}

kk_std_core_types__maybe kk_std_text_parse_starts_with(kk_string_t s, kk_function_t p, kk_context_t* _ctx) { /* forall<a> (s : string, p : () -> parse a) -> maybe<(a, sslice/sslice)> */ 
  kk_std_text_parse__parse_error _match_x1912;
  kk_std_core_sslice__sslice _x_x2135;
  kk_string_t _x_x2136 = kk_string_dup(s, _ctx); /*string*/
  kk_integer_t _x_x2137 = kk_string_len_int(s,kk_context()); /*int*/
  _x_x2135 = kk_std_core_sslice__new_Sslice(_x_x2136, kk_integer_from_small(0), _x_x2137, _ctx); /*sslice/sslice*/
  _match_x1912 = kk_std_text_parse_parse(_x_x2135, p, _ctx); /*std/text/parse/parse-error<1455>*/
  if (kk_std_text_parse__is_ParseOk(_match_x1912, _ctx)) {
    struct kk_std_text_parse_ParseOk* _con_x2138 = kk_std_text_parse__as_ParseOk(_match_x1912, _ctx);
    kk_std_core_sslice__sslice rest = _con_x2138->rest;
    kk_box_t x = _con_x2138->result;
    if kk_likely(kk_datatype_ptr_is_unique(_match_x1912, _ctx)) {
      kk_datatype_ptr_free(_match_x1912, _ctx);
    }
    else {
      kk_std_core_sslice__sslice_dup(rest, _ctx);
      kk_box_dup(x, _ctx);
      kk_datatype_ptr_decref(_match_x1912, _ctx);
    }
    kk_box_t _x_x2139;
    kk_std_core_types__tuple2 _x_x2140 = kk_std_core_types__new_Tuple2(x, kk_std_core_sslice__sslice_box(rest, _ctx), _ctx); /*(134, 135)*/
    _x_x2139 = kk_std_core_types__tuple2_box(_x_x2140, _ctx); /*88*/
    return kk_std_core_types__new_Just(_x_x2139, _ctx);
  }
  {
    kk_std_text_parse__parse_error_drop(_match_x1912, _ctx);
    return kk_std_core_types__new_Nothing(_ctx);
  }
}


// lift anonymous function
struct kk_std_text_parse__lp__at_x_fun2146__t_bar__bar__rp_ {
  struct kk_function_s _base;
  kk_ssize_t i_10644;
};
static kk_box_t kk_std_text_parse__lp__at_x_fun2146_bar__bar__rp_(kk_function_t _fself, kk_function_t _b_x167, kk_box_t _b_x168, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse__lp__at_new_x_fun2146_bar__bar__rp_(kk_ssize_t i_10644, kk_context_t* _ctx) {
  struct kk_std_text_parse__lp__at_x_fun2146__t_bar__bar__rp_* _self = kk_function_alloc_as(struct kk_std_text_parse__lp__at_x_fun2146__t_bar__bar__rp_, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_text_parse__lp__at_x_fun2146_bar__bar__rp_, kk_context());
  _self->i_10644 = i_10644;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_text_parse__lp__at_x_fun2146_bar__bar__rp_(kk_function_t _fself, kk_function_t _b_x167, kk_box_t _b_x168, kk_context_t* _ctx) {
  struct kk_std_text_parse__lp__at_x_fun2146__t_bar__bar__rp_* _self = kk_function_as(struct kk_std_text_parse__lp__at_x_fun2146__t_bar__bar__rp_*, _fself, _ctx);
  kk_ssize_t i_10644 = _self->i_10644; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_10644, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_10644, _b_x167, _b_x168, _ctx);
}


// lift anonymous function
struct kk_std_text_parse__lp__at_x_fun2147__t_bar__bar__rp_ {
  struct kk_function_s _base;
  kk_function_t p1;
  kk_function_t p2;
};
static kk_box_t kk_std_text_parse__lp__at_x_fun2147_bar__bar__rp_(kk_function_t _fself, kk_box_t _b_x177, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse__lp__at_new_x_fun2147_bar__bar__rp_(kk_function_t p1, kk_function_t p2, kk_context_t* _ctx) {
  struct kk_std_text_parse__lp__at_x_fun2147__t_bar__bar__rp_* _self = kk_function_alloc_as(struct kk_std_text_parse__lp__at_x_fun2147__t_bar__bar__rp_, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_text_parse__lp__at_x_fun2147_bar__bar__rp_, kk_context());
  _self->p1 = p1;
  _self->p2 = p2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_text_parse__lp__at_x_fun2147_bar__bar__rp_(kk_function_t _fself, kk_box_t _b_x177, kk_context_t* _ctx) {
  struct kk_std_text_parse__lp__at_x_fun2147__t_bar__bar__rp_* _self = kk_function_as(struct kk_std_text_parse__lp__at_x_fun2147__t_bar__bar__rp_*, _fself, _ctx);
  kk_function_t p1 = _self->p1; /* std/text/parse/parser<1543,1542> */
  kk_function_t p2 = _self->p2; /* std/text/parse/parser<1543,1542> */
  kk_drop_match(_self, {kk_function_dup(p1, _ctx);kk_function_dup(p2, _ctx);}, {}, _ctx)
  bool _match_x1910 = kk_bool_unbox(_b_x177); /*bool*/;
  if (_match_x1910) {
    kk_function_drop(p2, _ctx);
    return kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), p1, (p1, _ctx), _ctx);
  }
  {
    kk_function_drop(p1, _ctx);
    return kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), p2, (p2, _ctx), _ctx);
  }
}

kk_box_t kk_std_text_parse__lp__bar__bar__rp_(kk_function_t p1, kk_function_t p2, kk_context_t* _ctx) { /* forall<a,e> (p1 : parser<e,a>, p2 : parser<e,a>) -> <parse|e> a */ 
  kk_ssize_t i_10644;
  kk_std_core_hnd__htag _x_x2141 = kk_std_core_hnd__htag_dup(kk_std_text_parse_parse_fs__tag, _ctx); /*hnd/htag<std/text/parse/parse>*/
  i_10644 = kk_std_core_hnd__evv_index(_x_x2141, _ctx); /*hnd/ev-index*/
  kk_evv_t w = kk_evv_swap_create1(i_10644,kk_context()); /*hnd/evv<<std/text/parse/parse|1543>>*/;
  kk_std_core_hnd__ev ev_10646 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
  bool y;
  kk_box_t _x_x2142;
  {
    struct kk_std_core_hnd_Ev* _con_x2143 = kk_std_core_hnd__as_Ev(ev_10646, _ctx);
    kk_box_t _box_x156 = _con_x2143->hnd;
    int32_t m = _con_x2143->marker;
    kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x156, KK_BORROWED, _ctx);
    kk_std_text_parse__parse_dup(h, _ctx);
    {
      struct kk_std_text_parse__Hnd_parse* _con_x2144 = kk_std_text_parse__as_Hnd_parse(h, _ctx);
      kk_integer_t _pat_0 = _con_x2144->_cfc;
      kk_std_core_hnd__clause0 _pat_1 = _con_x2144->_fun_current_input;
      kk_std_core_hnd__clause1 _pat_2_0 = _con_x2144->_brk_fail;
      kk_std_core_hnd__clause0 _ctl_pick = _con_x2144->_ctl_pick;
      kk_std_core_hnd__clause1 _pat_3 = _con_x2144->_fun_satisfy;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause1_drop(_pat_3, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_2_0, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_1, _ctx);
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause0_dup(_ctl_pick, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x159 = _ctl_pick.clause;
        _x_x2142 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x159, (_fun_unbox_x159, m, ev_10646, _ctx), _ctx); /*35*/
      }
    }
  }
  y = kk_bool_unbox(_x_x2142); /*bool*/
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w,kk_context());
  bool x_10641;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2145 = kk_std_core_hnd_yield_cont(kk_std_text_parse__lp__at_new_x_fun2146_bar__bar__rp_(i_10644, _ctx), _ctx); /*2568*/
    x_10641 = kk_bool_unbox(_x_x2145); /*bool*/
  }
  else {
    x_10641 = y; /*bool*/
  }
  if (kk_yielding(kk_context())) {
    return kk_std_core_hnd_yield_extend(kk_std_text_parse__lp__at_new_x_fun2147_bar__bar__rp_(p1, p2, _ctx), _ctx);
  }
  if (x_10641) {
    kk_function_drop(p2, _ctx);
    return kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), p1, (p1, _ctx), _ctx);
  }
  {
    kk_function_drop(p1, _ctx);
    return kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), p2, (p2, _ctx), _ctx);
  }
}


// lift anonymous function
struct kk_std_text_parse_optional_fun2153__t {
  struct kk_function_s _base;
  kk_ssize_t i_10654;
};
static kk_box_t kk_std_text_parse_optional_fun2153(kk_function_t _fself, kk_function_t _b_x192, kk_box_t _b_x193, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_optional_fun2153(kk_ssize_t i_10654, kk_context_t* _ctx) {
  struct kk_std_text_parse_optional_fun2153__t* _self = kk_function_alloc_as(struct kk_std_text_parse_optional_fun2153__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_text_parse_optional_fun2153, kk_context());
  _self->i_10654 = i_10654;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_text_parse_optional_fun2153(kk_function_t _fself, kk_function_t _b_x192, kk_box_t _b_x193, kk_context_t* _ctx) {
  struct kk_std_text_parse_optional_fun2153__t* _self = kk_function_as(struct kk_std_text_parse_optional_fun2153__t*, _fself, _ctx);
  kk_ssize_t i_10654 = _self->i_10654; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_10654, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_10654, _b_x192, _b_x193, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_optional_fun2154__t {
  struct kk_function_s _base;
  kk_box_t kkloc_default;
  kk_function_t p;
};
static kk_box_t kk_std_text_parse_optional_fun2154(kk_function_t _fself, kk_box_t _b_x202, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_optional_fun2154(kk_box_t kkloc_default, kk_function_t p, kk_context_t* _ctx) {
  struct kk_std_text_parse_optional_fun2154__t* _self = kk_function_alloc_as(struct kk_std_text_parse_optional_fun2154__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_text_parse_optional_fun2154, kk_context());
  _self->kkloc_default = kkloc_default;
  _self->p = p;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_text_parse_optional_fun2154(kk_function_t _fself, kk_box_t _b_x202, kk_context_t* _ctx) {
  struct kk_std_text_parse_optional_fun2154__t* _self = kk_function_as(struct kk_std_text_parse_optional_fun2154__t*, _fself, _ctx);
  kk_box_t kkloc_default = _self->kkloc_default; /* 1575 */
  kk_function_t p = _self->p; /* std/text/parse/parser<1576,1575> */
  kk_drop_match(_self, {kk_box_dup(kkloc_default, _ctx);kk_function_dup(p, _ctx);}, {}, _ctx)
  bool _match_x1907 = kk_bool_unbox(_b_x202); /*bool*/;
  if (_match_x1907) {
    kk_box_drop(kkloc_default, _ctx);
    return kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), p, (p, _ctx), _ctx);
  }
  {
    kk_function_drop(p, _ctx);
    return kkloc_default;
  }
}

kk_box_t kk_std_text_parse_optional(kk_box_t kkloc_default, kk_function_t p, kk_context_t* _ctx) { /* forall<a,e> (default : a, p : parser<e,a>) -> <parse|e> a */ 
  kk_ssize_t i_10654;
  kk_std_core_hnd__htag _x_x2148 = kk_std_core_hnd__htag_dup(kk_std_text_parse_parse_fs__tag, _ctx); /*hnd/htag<std/text/parse/parse>*/
  i_10654 = kk_std_core_hnd__evv_index(_x_x2148, _ctx); /*hnd/ev-index*/
  kk_evv_t w = kk_evv_swap_create1(i_10654,kk_context()); /*hnd/evv<<std/text/parse/parse|1576>>*/;
  kk_std_core_hnd__ev ev_10656 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
  bool y;
  kk_box_t _x_x2149;
  {
    struct kk_std_core_hnd_Ev* _con_x2150 = kk_std_core_hnd__as_Ev(ev_10656, _ctx);
    kk_box_t _box_x181 = _con_x2150->hnd;
    int32_t m = _con_x2150->marker;
    kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x181, KK_BORROWED, _ctx);
    kk_std_text_parse__parse_dup(h, _ctx);
    {
      struct kk_std_text_parse__Hnd_parse* _con_x2151 = kk_std_text_parse__as_Hnd_parse(h, _ctx);
      kk_integer_t _pat_0 = _con_x2151->_cfc;
      kk_std_core_hnd__clause0 _pat_1 = _con_x2151->_fun_current_input;
      kk_std_core_hnd__clause1 _pat_2_0 = _con_x2151->_brk_fail;
      kk_std_core_hnd__clause0 _ctl_pick = _con_x2151->_ctl_pick;
      kk_std_core_hnd__clause1 _pat_3 = _con_x2151->_fun_satisfy;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause1_drop(_pat_3, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_2_0, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_1, _ctx);
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause0_dup(_ctl_pick, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x184 = _ctl_pick.clause;
        _x_x2149 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x184, (_fun_unbox_x184, m, ev_10656, _ctx), _ctx); /*35*/
      }
    }
  }
  y = kk_bool_unbox(_x_x2149); /*bool*/
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w,kk_context());
  bool x_10651;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2152 = kk_std_core_hnd_yield_cont(kk_std_text_parse_new_optional_fun2153(i_10654, _ctx), _ctx); /*2568*/
    x_10651 = kk_bool_unbox(_x_x2152); /*bool*/
  }
  else {
    x_10651 = y; /*bool*/
  }
  if (kk_yielding(kk_context())) {
    return kk_std_core_hnd_yield_extend(kk_std_text_parse_new_optional_fun2154(kkloc_default, p, _ctx), _ctx);
  }
  if (x_10651) {
    kk_box_drop(kkloc_default, _ctx);
    return kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), p, (p, _ctx), _ctx);
  }
  {
    kk_function_drop(p, _ctx);
    return kkloc_default;
  }
}
 
// monadic lift

kk_box_t kk_std_text_parse__mlift_unroll_choose_10000_10556(kk_function_t p_0, kk_std_core_types__list pp, bool _y_x10398, kk_context_t* _ctx) { /* forall<a,e> (p@0 : parser<e,a>, pp : list<parser<e,a>>, bool) -> <parse|e> a */ 
  if (_y_x10398) {
    kk_std_core_types__list_drop(pp, _ctx);
    return kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), p_0, (p_0, _ctx), _ctx);
  }
  {
    kk_function_drop(p_0, _ctx);
    return kk_std_text_parse__unroll_choose_10000(pp, _ctx);
  }
}


// lift anonymous function
struct kk_std_text_parse__unroll_choose_10000_fun2161__t {
  struct kk_function_s _base;
  kk_ssize_t i_10661;
};
static kk_box_t kk_std_text_parse__unroll_choose_10000_fun2161(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse__new_unroll_choose_10000_fun2161(kk_ssize_t i_10661, kk_context_t* _ctx) {
  struct kk_std_text_parse__unroll_choose_10000_fun2161__t* _self = kk_function_alloc_as(struct kk_std_text_parse__unroll_choose_10000_fun2161__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_text_parse__unroll_choose_10000_fun2161, kk_context());
  _self->i_10661 = i_10661;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_text_parse__unroll_choose_10000_fun2161(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_text_parse__unroll_choose_10000_fun2161__t* _self = kk_function_as(struct kk_std_text_parse__unroll_choose_10000_fun2161__t*, _fself, _ctx);
  kk_ssize_t i_10661 = _self->i_10661; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_10661, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_10661, cont, res, _ctx);
}


// lift anonymous function
struct kk_std_text_parse__unroll_choose_10000_fun2170__t {
  struct kk_function_s _base;
  kk_ssize_t i_0_10670;
};
static kk_box_t kk_std_text_parse__unroll_choose_10000_fun2170(kk_function_t _fself, kk_function_t _b_x231, kk_box_t _b_x232, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse__new_unroll_choose_10000_fun2170(kk_ssize_t i_0_10670, kk_context_t* _ctx) {
  struct kk_std_text_parse__unroll_choose_10000_fun2170__t* _self = kk_function_alloc_as(struct kk_std_text_parse__unroll_choose_10000_fun2170__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_text_parse__unroll_choose_10000_fun2170, kk_context());
  _self->i_0_10670 = i_0_10670;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_text_parse__unroll_choose_10000_fun2170(kk_function_t _fself, kk_function_t _b_x231, kk_box_t _b_x232, kk_context_t* _ctx) {
  struct kk_std_text_parse__unroll_choose_10000_fun2170__t* _self = kk_function_as(struct kk_std_text_parse__unroll_choose_10000_fun2170__t*, _fself, _ctx);
  kk_ssize_t i_0_10670 = _self->i_0_10670; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_0_10670, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_0_10670, _b_x231, _b_x232, _ctx);
}


// lift anonymous function
struct kk_std_text_parse__unroll_choose_10000_fun2171__t {
  struct kk_function_s _base;
  kk_function_t p_0_0;
  kk_std_core_types__list pp_0;
};
static kk_box_t kk_std_text_parse__unroll_choose_10000_fun2171(kk_function_t _fself, kk_box_t _b_x241, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse__new_unroll_choose_10000_fun2171(kk_function_t p_0_0, kk_std_core_types__list pp_0, kk_context_t* _ctx) {
  struct kk_std_text_parse__unroll_choose_10000_fun2171__t* _self = kk_function_alloc_as(struct kk_std_text_parse__unroll_choose_10000_fun2171__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_text_parse__unroll_choose_10000_fun2171, kk_context());
  _self->p_0_0 = p_0_0;
  _self->pp_0 = pp_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_text_parse__unroll_choose_10000_fun2171(kk_function_t _fself, kk_box_t _b_x241, kk_context_t* _ctx) {
  struct kk_std_text_parse__unroll_choose_10000_fun2171__t* _self = kk_function_as(struct kk_std_text_parse__unroll_choose_10000_fun2171__t*, _fself, _ctx);
  kk_function_t p_0_0 = _self->p_0_0; /* std/text/parse/parser<1640,1639> */
  kk_std_core_types__list pp_0 = _self->pp_0; /* list<std/text/parse/parser<1640,1639>> */
  kk_drop_match(_self, {kk_function_dup(p_0_0, _ctx);kk_std_core_types__list_dup(pp_0, _ctx);}, {}, _ctx)
  bool _x_x2172 = kk_bool_unbox(_b_x241); /*bool*/
  return kk_std_text_parse__mlift_unroll_choose_10000_10556(p_0_0, pp_0, _x_x2172, _ctx);
}

kk_box_t kk_std_text_parse__unroll_choose_10000(kk_std_core_types__list ps, kk_context_t* _ctx) { /* forall<a,e> (ps : list<parser<e,a>>) -> <parse|e> a */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Nil(ps, _ctx)) {
    kk_ssize_t i_10661;
    kk_std_core_hnd__htag _x_x2155 = kk_std_core_hnd__htag_dup(kk_std_text_parse_parse_fs__tag, _ctx); /*hnd/htag<std/text/parse/parse>*/
    i_10661 = kk_std_core_hnd__evv_index(_x_x2155, _ctx); /*hnd/ev-index*/
    kk_evv_t w = kk_evv_swap_create1(i_10661,kk_context()); /*hnd/evv<<std/text/parse/parse|1640>>*/;
    kk_std_core_hnd__ev ev_10664 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
    kk_box_t y;
    {
      struct kk_std_core_hnd_Ev* _con_x2156 = kk_std_core_hnd__as_Ev(ev_10664, _ctx);
      kk_box_t _box_x206 = _con_x2156->hnd;
      int32_t m = _con_x2156->marker;
      kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x206, KK_BORROWED, _ctx);
      kk_std_text_parse__parse_dup(h, _ctx);
      {
        struct kk_std_text_parse__Hnd_parse* _con_x2157 = kk_std_text_parse__as_Hnd_parse(h, _ctx);
        kk_integer_t _pat_0_0 = _con_x2157->_cfc;
        kk_std_core_hnd__clause0 _pat_1_1 = _con_x2157->_fun_current_input;
        kk_std_core_hnd__clause1 _brk_fail = _con_x2157->_brk_fail;
        kk_std_core_hnd__clause0 _pat_2 = _con_x2157->_ctl_pick;
        kk_std_core_hnd__clause1 _pat_3_0 = _con_x2157->_fun_satisfy;
        if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
          kk_std_core_hnd__clause1_drop(_pat_3_0, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_2, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_1_1, _ctx);
          kk_integer_drop(_pat_0_0, _ctx);
          kk_datatype_ptr_free(h, _ctx);
        }
        else {
          kk_std_core_hnd__clause1_dup(_brk_fail, _ctx);
          kk_datatype_ptr_decref(h, _ctx);
        }
        {
          kk_function_t _fun_unbox_x210 = _brk_fail.clause;
          kk_box_t _x_x2158;
          kk_string_t _x_x2159;
          kk_define_string_literal(static, _s_x2160, 23, "no further alternatives", _ctx)
          _x_x2159 = kk_string_dup(_s_x2160, _ctx); /*string*/
          _x_x2158 = kk_string_box(_x_x2159); /*45*/
          y = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x210, (_fun_unbox_x210, m, ev_10664, _x_x2158, _ctx), _ctx); /*1639*/
        }
      }
    }
    kk_unit_t __ = kk_Unit;
    kk_evv_set(w,kk_context());
    if (kk_yielding(kk_context())) {
      kk_box_drop(y, _ctx);
      return kk_std_core_hnd_yield_cont(kk_std_text_parse__new_unroll_choose_10000_fun2161(i_10661, _ctx), _ctx);
    }
    {
      return y;
    }
  }
  {
    struct kk_std_core_types_Cons* _con_x2162 = kk_std_core_types__as_Cons(ps, _ctx);
    kk_std_core_types__list _pat_1_1_0 = _con_x2162->tail;
    if (kk_std_core_types__is_Nil(_pat_1_1_0, _ctx)) {
      kk_box_t _fun_unbox_x215 = _con_x2162->head;
      if kk_likely(kk_datatype_ptr_is_unique(ps, _ctx)) {
        kk_datatype_ptr_free(ps, _ctx);
      }
      else {
        kk_box_dup(_fun_unbox_x215, _ctx);
        kk_datatype_ptr_decref(ps, _ctx);
      }
      kk_function_t _x_x2163 = kk_function_unbox(_fun_unbox_x215, _ctx); /*() -> <std/text/parse/parse|1640> 216*/
      return kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), _x_x2163, (_x_x2163, _ctx), _ctx);
    }
  }
  {
    struct kk_std_core_types_Cons* _con_x2164 = kk_std_core_types__as_Cons(ps, _ctx);
    kk_box_t _fun_unbox_x218 = _con_x2164->head;
    kk_std_core_types__list pp_0 = _con_x2164->tail;
    if kk_likely(kk_datatype_ptr_is_unique(ps, _ctx)) {
      kk_datatype_ptr_free(ps, _ctx);
    }
    else {
      kk_box_dup(_fun_unbox_x218, _ctx);
      kk_std_core_types__list_dup(pp_0, _ctx);
      kk_datatype_ptr_decref(ps, _ctx);
    }
    kk_function_t p_0_0 = kk_function_unbox(_fun_unbox_x218, _ctx); /*std/text/parse/parser<1640,1639>*/;
    kk_ssize_t i_0_10670;
    kk_std_core_hnd__htag _x_x2165 = kk_std_core_hnd__htag_dup(kk_std_text_parse_parse_fs__tag, _ctx); /*hnd/htag<std/text/parse/parse>*/
    i_0_10670 = kk_std_core_hnd__evv_index(_x_x2165, _ctx); /*hnd/ev-index*/
    kk_evv_t w_0 = kk_evv_swap_create1(i_0_10670,kk_context()); /*hnd/evv<<std/text/parse/parse|1640>>*/;
    kk_std_core_hnd__ev ev_0_10672 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
    bool y_0;
    kk_box_t _x_x2166;
    {
      struct kk_std_core_hnd_Ev* _con_x2167 = kk_std_core_hnd__as_Ev(ev_0_10672, _ctx);
      kk_box_t _box_x220 = _con_x2167->hnd;
      int32_t m_0 = _con_x2167->marker;
      kk_std_text_parse__parse h_0 = kk_std_text_parse__parse_unbox(_box_x220, KK_BORROWED, _ctx);
      kk_std_text_parse__parse_dup(h_0, _ctx);
      {
        struct kk_std_text_parse__Hnd_parse* _con_x2168 = kk_std_text_parse__as_Hnd_parse(h_0, _ctx);
        kk_integer_t _pat_0_3 = _con_x2168->_cfc;
        kk_std_core_hnd__clause0 _pat_1_3 = _con_x2168->_fun_current_input;
        kk_std_core_hnd__clause1 _pat_2_1 = _con_x2168->_brk_fail;
        kk_std_core_hnd__clause0 _ctl_pick = _con_x2168->_ctl_pick;
        kk_std_core_hnd__clause1 _pat_3_1 = _con_x2168->_fun_satisfy;
        if kk_likely(kk_datatype_ptr_is_unique(h_0, _ctx)) {
          kk_std_core_hnd__clause1_drop(_pat_3_1, _ctx);
          kk_std_core_hnd__clause1_drop(_pat_2_1, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_1_3, _ctx);
          kk_integer_drop(_pat_0_3, _ctx);
          kk_datatype_ptr_free(h_0, _ctx);
        }
        else {
          kk_std_core_hnd__clause0_dup(_ctl_pick, _ctx);
          kk_datatype_ptr_decref(h_0, _ctx);
        }
        {
          kk_function_t _fun_unbox_x223 = _ctl_pick.clause;
          _x_x2166 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x223, (_fun_unbox_x223, m_0, ev_0_10672, _ctx), _ctx); /*35*/
        }
      }
    }
    y_0 = kk_bool_unbox(_x_x2166); /*bool*/
    kk_unit_t ___0 = kk_Unit;
    kk_evv_set(w_0,kk_context());
    bool x_1_10667;
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x2169 = kk_std_core_hnd_yield_cont(kk_std_text_parse__new_unroll_choose_10000_fun2170(i_0_10670, _ctx), _ctx); /*2568*/
      x_1_10667 = kk_bool_unbox(_x_x2169); /*bool*/
    }
    else {
      x_1_10667 = y_0; /*bool*/
    }
    if (kk_yielding(kk_context())) {
      return kk_std_core_hnd_yield_extend(kk_std_text_parse__new_unroll_choose_10000_fun2171(p_0_0, pp_0, _ctx), _ctx);
    }
    if (x_1_10667) {
      kk_std_core_types__list_drop(pp_0, _ctx);
      return kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), p_0_0, (p_0_0, _ctx), _ctx);
    }
    {
      kk_function_drop(p_0_0, _ctx);
      { // tailcall
        ps = pp_0;
        goto kk__tailcall;
      }
    }
  }
}
extern kk_box_t kk_std_text_parse_choose_fun2179(kk_function_t _fself, kk_function_t cont, kk_box_t res, kk_context_t* _ctx) {
  struct kk_std_text_parse_choose_fun2179__t* _self = kk_function_as(struct kk_std_text_parse_choose_fun2179__t*, _fself, _ctx);
  kk_ssize_t i_10674 = _self->i_10674; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_10674, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_10674, cont, res, _ctx);
}
 
// monadic lift

kk_box_t kk_std_text_parse__mlift_satisfy_fail_10557(kk_string_t msg, kk_std_core_types__maybe _y_x10407, kk_context_t* _ctx) { /* forall<a> (msg : string, maybe<a>) -> parse a */ 
  if (kk_std_core_types__is_Nothing(_y_x10407, _ctx)) {
    kk_std_core_hnd__ev ev_10680 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
    {
      struct kk_std_core_hnd_Ev* _con_x2180 = kk_std_core_hnd__as_Ev(ev_10680, _ctx);
      kk_box_t _box_x253 = _con_x2180->hnd;
      int32_t m = _con_x2180->marker;
      kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x253, KK_BORROWED, _ctx);
      kk_std_text_parse__parse_dup(h, _ctx);
      {
        struct kk_std_text_parse__Hnd_parse* _con_x2181 = kk_std_text_parse__as_Hnd_parse(h, _ctx);
        kk_integer_t _pat_0_1 = _con_x2181->_cfc;
        kk_std_core_hnd__clause0 _pat_1_0 = _con_x2181->_fun_current_input;
        kk_std_core_hnd__clause1 _brk_fail = _con_x2181->_brk_fail;
        kk_std_core_hnd__clause0 _pat_2_0 = _con_x2181->_ctl_pick;
        kk_std_core_hnd__clause1 _pat_3 = _con_x2181->_fun_satisfy;
        if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
          kk_std_core_hnd__clause1_drop(_pat_3, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_2_0, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_1_0, _ctx);
          kk_integer_drop(_pat_0_1, _ctx);
          kk_datatype_ptr_free(h, _ctx);
        }
        else {
          kk_std_core_hnd__clause1_dup(_brk_fail, _ctx);
          kk_datatype_ptr_decref(h, _ctx);
        }
        {
          kk_function_t _fun_unbox_x257 = _brk_fail.clause;
          return kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x257, (_fun_unbox_x257, m, ev_10680, kk_string_box(msg), _ctx), _ctx);
        }
      }
    }
  }
  {
    kk_box_t x_0 = _y_x10407._cons.Just.value;
    kk_string_drop(msg, _ctx);
    return x_0;
  }
}


// lift anonymous function
struct kk_std_text_parse_satisfy_fail_fun2185__t {
  struct kk_function_s _base;
  kk_function_t pred;
};
static kk_box_t kk_std_text_parse_satisfy_fail_fun2185(kk_function_t _fself, kk_box_t _b_x274, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_satisfy_fail_fun2185(kk_function_t pred, kk_context_t* _ctx) {
  struct kk_std_text_parse_satisfy_fail_fun2185__t* _self = kk_function_alloc_as(struct kk_std_text_parse_satisfy_fail_fun2185__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_text_parse_satisfy_fail_fun2185, kk_context());
  _self->pred = pred;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_text_parse_satisfy_fail_fun2185(kk_function_t _fself, kk_box_t _b_x274, kk_context_t* _ctx) {
  struct kk_std_text_parse_satisfy_fail_fun2185__t* _self = kk_function_as(struct kk_std_text_parse_satisfy_fail_fun2185__t*, _fself, _ctx);
  kk_function_t pred = _self->pred; /* (sslice/sslice) -> maybe<(1682, sslice/sslice)> */
  kk_drop_match(_self, {kk_function_dup(pred, _ctx);}, {}, _ctx)
  kk_std_core_types__maybe _x_x2186;
  kk_std_core_sslice__sslice _x_x2187 = kk_std_core_sslice__sslice_unbox(_b_x274, KK_OWNED, _ctx); /*sslice/sslice*/
  _x_x2186 = kk_function_call(kk_std_core_types__maybe, (kk_function_t, kk_std_core_sslice__sslice, kk_context_t*), pred, (pred, _x_x2187, _ctx), _ctx); /*maybe<(1682, sslice/sslice)>*/
  return kk_std_core_types__maybe_box(_x_x2186, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_satisfy_fail_fun2188__t {
  struct kk_function_s _base;
  kk_string_t msg;
};
static kk_box_t kk_std_text_parse_satisfy_fail_fun2188(kk_function_t _fself, kk_box_t _b_x276, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_satisfy_fail_fun2188(kk_string_t msg, kk_context_t* _ctx) {
  struct kk_std_text_parse_satisfy_fail_fun2188__t* _self = kk_function_alloc_as(struct kk_std_text_parse_satisfy_fail_fun2188__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_text_parse_satisfy_fail_fun2188, kk_context());
  _self->msg = msg;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_text_parse_satisfy_fail_fun2188(kk_function_t _fself, kk_box_t _b_x276, kk_context_t* _ctx) {
  struct kk_std_text_parse_satisfy_fail_fun2188__t* _self = kk_function_as(struct kk_std_text_parse_satisfy_fail_fun2188__t*, _fself, _ctx);
  kk_string_t msg = _self->msg; /* string */
  kk_drop_match(_self, {kk_string_dup(msg, _ctx);}, {}, _ctx)
  kk_std_core_types__maybe _x_x2189 = kk_std_core_types__maybe_unbox(_b_x276, KK_OWNED, _ctx); /*maybe<1682>*/
  return kk_std_text_parse__mlift_satisfy_fail_10557(msg, _x_x2189, _ctx);
}

kk_box_t kk_std_text_parse_satisfy_fail(kk_string_t msg, kk_function_t pred, kk_context_t* _ctx) { /* forall<a> (msg : string, pred : (sslice/sslice) -> maybe<(a, sslice/sslice)>) -> parse a */ 
  kk_std_core_hnd__ev ev_10686 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
  kk_std_core_types__maybe x_10683;
  kk_box_t _x_x2182;
  {
    struct kk_std_core_hnd_Ev* _con_x2183 = kk_std_core_hnd__as_Ev(ev_10686, _ctx);
    kk_box_t _box_x261 = _con_x2183->hnd;
    int32_t m = _con_x2183->marker;
    kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x261, KK_BORROWED, _ctx);
    kk_std_text_parse__parse_dup(h, _ctx);
    {
      struct kk_std_text_parse__Hnd_parse* _con_x2184 = kk_std_text_parse__as_Hnd_parse(h, _ctx);
      kk_integer_t _pat_0 = _con_x2184->_cfc;
      kk_std_core_hnd__clause0 _pat_1_1 = _con_x2184->_fun_current_input;
      kk_std_core_hnd__clause1 _pat_2 = _con_x2184->_brk_fail;
      kk_std_core_hnd__clause0 _pat_3 = _con_x2184->_ctl_pick;
      kk_std_core_hnd__clause1 _fun_satisfy = _con_x2184->_fun_satisfy;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause0_drop(_pat_3, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_2, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_1_1, _ctx);
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_fun_satisfy, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x268 = _fun_satisfy.clause;
        _x_x2182 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x268, (_fun_unbox_x268, m, ev_10686, kk_function_box(kk_std_text_parse_new_satisfy_fail_fun2185(pred, _ctx), _ctx), _ctx), _ctx); /*46*/
      }
    }
  }
  x_10683 = kk_std_core_types__maybe_unbox(_x_x2182, KK_OWNED, _ctx); /*maybe<1682>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__maybe_drop(x_10683, _ctx);
    return kk_std_core_hnd_yield_extend(kk_std_text_parse_new_satisfy_fail_fun2188(msg, _ctx), _ctx);
  }
  if (kk_std_core_types__is_Nothing(x_10683, _ctx)) {
    kk_std_core_hnd__ev ev_0_10689 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
    {
      struct kk_std_core_hnd_Ev* _con_x2190 = kk_std_core_hnd__as_Ev(ev_0_10689, _ctx);
      kk_box_t _box_x277 = _con_x2190->hnd;
      int32_t m_0 = _con_x2190->marker;
      kk_std_text_parse__parse h_0 = kk_std_text_parse__parse_unbox(_box_x277, KK_BORROWED, _ctx);
      kk_std_text_parse__parse_dup(h_0, _ctx);
      {
        struct kk_std_text_parse__Hnd_parse* _con_x2191 = kk_std_text_parse__as_Hnd_parse(h_0, _ctx);
        kk_integer_t _pat_0_2 = _con_x2191->_cfc;
        kk_std_core_hnd__clause0 _pat_1_2 = _con_x2191->_fun_current_input;
        kk_std_core_hnd__clause1 _brk_fail = _con_x2191->_brk_fail;
        kk_std_core_hnd__clause0 _pat_2_1 = _con_x2191->_ctl_pick;
        kk_std_core_hnd__clause1 _pat_3_1 = _con_x2191->_fun_satisfy;
        if kk_likely(kk_datatype_ptr_is_unique(h_0, _ctx)) {
          kk_std_core_hnd__clause1_drop(_pat_3_1, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_2_1, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_1_2, _ctx);
          kk_integer_drop(_pat_0_2, _ctx);
          kk_datatype_ptr_free(h_0, _ctx);
        }
        else {
          kk_std_core_hnd__clause1_dup(_brk_fail, _ctx);
          kk_datatype_ptr_decref(h_0, _ctx);
        }
        {
          kk_function_t _fun_unbox_x281 = _brk_fail.clause;
          return kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x281, (_fun_unbox_x281, m_0, ev_0_10689, kk_string_box(msg), _ctx), _ctx);
        }
      }
    }
  }
  {
    kk_box_t x_2 = x_10683._cons.Just.value;
    kk_string_drop(msg, _ctx);
    return x_2;
  }
}
 
// monadic lift

kk_unit_t kk_std_text_parse__mlift_eof_10558(kk_std_core_types__maybe _y_x10410, kk_context_t* _ctx) { /* (maybe<()>) -> parse () */ 
  if (kk_std_core_types__is_Nothing(_y_x10410, _ctx)) {
    kk_std_core_hnd__ev ev_10692 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
    kk_box_t _x_x2192;
    {
      struct kk_std_core_hnd_Ev* _con_x2193 = kk_std_core_hnd__as_Ev(ev_10692, _ctx);
      kk_box_t _box_x287 = _con_x2193->hnd;
      int32_t m = _con_x2193->marker;
      kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x287, KK_BORROWED, _ctx);
      kk_std_text_parse__parse_dup(h, _ctx);
      {
        struct kk_std_text_parse__Hnd_parse* _con_x2194 = kk_std_text_parse__as_Hnd_parse(h, _ctx);
        kk_integer_t _pat_0_0 = _con_x2194->_cfc;
        kk_std_core_hnd__clause0 _pat_1_0 = _con_x2194->_fun_current_input;
        kk_std_core_hnd__clause1 _brk_fail = _con_x2194->_brk_fail;
        kk_std_core_hnd__clause0 _pat_2_0 = _con_x2194->_ctl_pick;
        kk_std_core_hnd__clause1 _pat_3 = _con_x2194->_fun_satisfy;
        if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
          kk_std_core_hnd__clause1_drop(_pat_3, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_2_0, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_1_0, _ctx);
          kk_integer_drop(_pat_0_0, _ctx);
          kk_datatype_ptr_free(h, _ctx);
        }
        else {
          kk_std_core_hnd__clause1_dup(_brk_fail, _ctx);
          kk_datatype_ptr_decref(h, _ctx);
        }
        {
          kk_function_t _fun_unbox_x291 = _brk_fail.clause;
          kk_box_t _x_x2195;
          kk_string_t _x_x2196;
          kk_define_string_literal(static, _s_x2197, 22, "expecting end-of-input", _ctx)
          _x_x2196 = kk_string_dup(_s_x2197, _ctx); /*string*/
          _x_x2195 = kk_string_box(_x_x2196); /*45*/
          _x_x2192 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x291, (_fun_unbox_x291, m, ev_10692, _x_x2195, _ctx), _ctx); /*46*/
        }
      }
    }
    kk_unit_unbox(_x_x2192); return kk_Unit;
  }
  {
    kk_box_t _box_x295 = _y_x10410._cons.Just.value;
    kk_unit_t _pat_3_0 = kk_unit_unbox(_box_x295);
    kk_std_core_types__maybe_drop(_y_x10410, _ctx);
    kk_Unit; return kk_Unit;
  }
}


// lift anonymous function
struct kk_std_text_parse_eof_fun2201__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_eof_fun2201(kk_function_t _fself, kk_box_t _b_x309, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_eof_fun2201(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_eof_fun2201, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_text_parse_eof_fun2201(kk_function_t _fself, kk_box_t _b_x309, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  bool b_10032;
  kk_integer_t _brw_x1899;
  kk_std_core_sslice__sslice _match_x1898;
  kk_box_t _x_x2202 = kk_box_dup(_b_x309, _ctx); /*307*/
  _match_x1898 = kk_std_core_sslice__sslice_unbox(_x_x2202, KK_OWNED, _ctx); /*sslice/sslice*/
  {
    kk_integer_t _x = _match_x1898.len;
    kk_integer_dup(_x, _ctx);
    kk_std_core_sslice__sslice_drop(_match_x1898, _ctx);
    _brw_x1899 = _x; /*int*/
  }
  bool _brw_x1900 = kk_integer_gt_borrow(_brw_x1899,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x1899, _ctx);
  b_10032 = _brw_x1900; /*bool*/
  kk_std_core_types__maybe _x_x2203;
  if (b_10032) {
    kk_box_drop(_b_x309, _ctx);
    _x_x2203 = kk_std_core_types__new_Nothing(_ctx); /*forall<a> maybe<a>*/
  }
  else {
    kk_box_t _x_x2204;
    kk_std_core_types__tuple2 _x_x2205 = kk_std_core_types__new_Tuple2(kk_unit_box(kk_Unit), _b_x309, _ctx); /*(134, 135)*/
    _x_x2204 = kk_std_core_types__tuple2_box(_x_x2205, _ctx); /*88*/
    _x_x2203 = kk_std_core_types__new_Just(_x_x2204, _ctx); /*forall<a> maybe<a>*/
  }
  return kk_std_core_types__maybe_box(_x_x2203, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_eof_fun2207__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_eof_fun2207(kk_function_t _fself, kk_box_t _b_x318, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_eof_fun2207(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_eof_fun2207, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_text_parse_eof_fun2207(kk_function_t _fself, kk_box_t _b_x318, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x2208 = kk_Unit;
  kk_std_core_types__maybe _x_x2209 = kk_std_core_types__maybe_unbox(_b_x318, KK_OWNED, _ctx); /*maybe<()>*/
  kk_std_text_parse__mlift_eof_10558(_x_x2209, _ctx);
  return kk_unit_box(_x_x2208);
}

kk_unit_t kk_std_text_parse_eof(kk_context_t* _ctx) { /* () -> parse () */ 
  kk_std_core_hnd__ev ev_10698 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
  kk_std_core_types__maybe x_10695;
  kk_box_t _x_x2198;
  {
    struct kk_std_core_hnd_Ev* _con_x2199 = kk_std_core_hnd__as_Ev(ev_10698, _ctx);
    kk_box_t _box_x296 = _con_x2199->hnd;
    int32_t m = _con_x2199->marker;
    kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x296, KK_BORROWED, _ctx);
    kk_std_text_parse__parse_dup(h, _ctx);
    {
      struct kk_std_text_parse__Hnd_parse* _con_x2200 = kk_std_text_parse__as_Hnd_parse(h, _ctx);
      kk_integer_t _pat_0 = _con_x2200->_cfc;
      kk_std_core_hnd__clause0 _pat_1_1 = _con_x2200->_fun_current_input;
      kk_std_core_hnd__clause1 _pat_2 = _con_x2200->_brk_fail;
      kk_std_core_hnd__clause0 _pat_3 = _con_x2200->_ctl_pick;
      kk_std_core_hnd__clause1 _fun_satisfy = _con_x2200->_fun_satisfy;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause0_drop(_pat_3, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_2, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_1_1, _ctx);
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_fun_satisfy, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x303 = _fun_satisfy.clause;
        _x_x2198 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x303, (_fun_unbox_x303, m, ev_10698, kk_function_box(kk_std_text_parse_new_eof_fun2201(_ctx), _ctx), _ctx), _ctx); /*46*/
      }
    }
  }
  x_10695 = kk_std_core_types__maybe_unbox(_x_x2198, KK_OWNED, _ctx); /*maybe<()>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__maybe_drop(x_10695, _ctx);
    kk_box_t _x_x2206 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_eof_fun2207(_ctx), _ctx); /*2419*/
    kk_unit_unbox(_x_x2206); return kk_Unit;
  }
  if (kk_std_core_types__is_Nothing(x_10695, _ctx)) {
    kk_std_core_hnd__ev ev_0_10701 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
    kk_box_t _x_x2210;
    {
      struct kk_std_core_hnd_Ev* _con_x2211 = kk_std_core_hnd__as_Ev(ev_0_10701, _ctx);
      kk_box_t _box_x319 = _con_x2211->hnd;
      int32_t m_0 = _con_x2211->marker;
      kk_std_text_parse__parse h_0 = kk_std_text_parse__parse_unbox(_box_x319, KK_BORROWED, _ctx);
      kk_std_text_parse__parse_dup(h_0, _ctx);
      {
        struct kk_std_text_parse__Hnd_parse* _con_x2212 = kk_std_text_parse__as_Hnd_parse(h_0, _ctx);
        kk_integer_t _pat_0_3 = _con_x2212->_cfc;
        kk_std_core_hnd__clause0 _pat_1_3 = _con_x2212->_fun_current_input;
        kk_std_core_hnd__clause1 _brk_fail = _con_x2212->_brk_fail;
        kk_std_core_hnd__clause0 _pat_2_1 = _con_x2212->_ctl_pick;
        kk_std_core_hnd__clause1 _pat_3_1 = _con_x2212->_fun_satisfy;
        if kk_likely(kk_datatype_ptr_is_unique(h_0, _ctx)) {
          kk_std_core_hnd__clause1_drop(_pat_3_1, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_2_1, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_1_3, _ctx);
          kk_integer_drop(_pat_0_3, _ctx);
          kk_datatype_ptr_free(h_0, _ctx);
        }
        else {
          kk_std_core_hnd__clause1_dup(_brk_fail, _ctx);
          kk_datatype_ptr_decref(h_0, _ctx);
        }
        {
          kk_function_t _fun_unbox_x323 = _brk_fail.clause;
          kk_box_t _x_x2213;
          kk_string_t _x_x2214;
          kk_define_string_literal(static, _s_x2215, 22, "expecting end-of-input", _ctx)
          _x_x2214 = kk_string_dup(_s_x2215, _ctx); /*string*/
          _x_x2213 = kk_string_box(_x_x2214); /*45*/
          _x_x2210 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x323, (_fun_unbox_x323, m_0, ev_0_10701, _x_x2213, _ctx), _ctx); /*46*/
        }
      }
    }
    kk_unit_unbox(_x_x2210); return kk_Unit;
  }
  {
    kk_box_t _box_x327 = x_10695._cons.Just.value;
    kk_unit_t _pat_3_0_0 = kk_unit_unbox(_box_x327);
    kk_std_core_types__maybe_drop(x_10695, _ctx);
    kk_Unit; return kk_Unit;
  }
}
 
// monadic lift

kk_unit_t kk_std_text_parse__mlift_parse_eof_10559(kk_std_core_types__maybe _y_x10414, kk_context_t* _ctx) { /* (maybe<()>) -> parse () */ 
  if (kk_std_core_types__is_Nothing(_y_x10414, _ctx)) {
    kk_std_core_hnd__ev ev_10704 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
    kk_box_t _x_x2216;
    {
      struct kk_std_core_hnd_Ev* _con_x2217 = kk_std_core_hnd__as_Ev(ev_10704, _ctx);
      kk_box_t _box_x329 = _con_x2217->hnd;
      int32_t m = _con_x2217->marker;
      kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x329, KK_BORROWED, _ctx);
      kk_std_text_parse__parse_dup(h, _ctx);
      {
        struct kk_std_text_parse__Hnd_parse* _con_x2218 = kk_std_text_parse__as_Hnd_parse(h, _ctx);
        kk_integer_t _pat_0_0 = _con_x2218->_cfc;
        kk_std_core_hnd__clause0 _pat_1_0 = _con_x2218->_fun_current_input;
        kk_std_core_hnd__clause1 _brk_fail = _con_x2218->_brk_fail;
        kk_std_core_hnd__clause0 _pat_2_0 = _con_x2218->_ctl_pick;
        kk_std_core_hnd__clause1 _pat_3 = _con_x2218->_fun_satisfy;
        if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
          kk_std_core_hnd__clause1_drop(_pat_3, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_2_0, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_1_0, _ctx);
          kk_integer_drop(_pat_0_0, _ctx);
          kk_datatype_ptr_free(h, _ctx);
        }
        else {
          kk_std_core_hnd__clause1_dup(_brk_fail, _ctx);
          kk_datatype_ptr_decref(h, _ctx);
        }
        {
          kk_function_t _fun_unbox_x333 = _brk_fail.clause;
          kk_box_t _x_x2219;
          kk_string_t _x_x2220;
          kk_define_string_literal(static, _s_x2221, 22, "expecting end-of-input", _ctx)
          _x_x2220 = kk_string_dup(_s_x2221, _ctx); /*string*/
          _x_x2219 = kk_string_box(_x_x2220); /*45*/
          _x_x2216 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x333, (_fun_unbox_x333, m, ev_10704, _x_x2219, _ctx), _ctx); /*46*/
        }
      }
    }
    kk_unit_unbox(_x_x2216); return kk_Unit;
  }
  {
    kk_box_t _box_x337 = _y_x10414._cons.Just.value;
    kk_unit_t _pat_3_0 = kk_unit_unbox(_box_x337);
    kk_std_core_types__maybe_drop(_y_x10414, _ctx);
    kk_Unit; return kk_Unit;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_text_parse__mlift_parse_eof_10561_fun2226__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse__mlift_parse_eof_10561_fun2226(kk_function_t _fself, kk_box_t _b_x351, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse__new_mlift_parse_eof_10561_fun2226(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse__mlift_parse_eof_10561_fun2226, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_text_parse__mlift_parse_eof_10561_fun2226(kk_function_t _fself, kk_box_t _b_x351, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  bool b_10032;
  kk_integer_t _brw_x1895;
  kk_std_core_sslice__sslice _match_x1894;
  kk_box_t _x_x2227 = kk_box_dup(_b_x351, _ctx); /*349*/
  _match_x1894 = kk_std_core_sslice__sslice_unbox(_x_x2227, KK_OWNED, _ctx); /*sslice/sslice*/
  {
    kk_integer_t _x = _match_x1894.len;
    kk_integer_dup(_x, _ctx);
    kk_std_core_sslice__sslice_drop(_match_x1894, _ctx);
    _brw_x1895 = _x; /*int*/
  }
  bool _brw_x1896 = kk_integer_gt_borrow(_brw_x1895,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x1895, _ctx);
  b_10032 = _brw_x1896; /*bool*/
  kk_std_core_types__maybe _x_x2228;
  if (b_10032) {
    kk_box_drop(_b_x351, _ctx);
    _x_x2228 = kk_std_core_types__new_Nothing(_ctx); /*forall<a> maybe<a>*/
  }
  else {
    kk_box_t _x_x2229;
    kk_std_core_types__tuple2 _x_x2230 = kk_std_core_types__new_Tuple2(kk_unit_box(kk_Unit), _b_x351, _ctx); /*(134, 135)*/
    _x_x2229 = kk_std_core_types__tuple2_box(_x_x2230, _ctx); /*88*/
    _x_x2228 = kk_std_core_types__new_Just(_x_x2229, _ctx); /*forall<a> maybe<a>*/
  }
  return kk_std_core_types__maybe_box(_x_x2228, _ctx);
}


// lift anonymous function
struct kk_std_text_parse__mlift_parse_eof_10561_fun2232__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse__mlift_parse_eof_10561_fun2232(kk_function_t _fself, kk_box_t _b_x360, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse__new_mlift_parse_eof_10561_fun2232(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse__mlift_parse_eof_10561_fun2232, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_text_parse__mlift_parse_eof_10561_fun2232(kk_function_t _fself, kk_box_t _b_x360, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x2233 = kk_Unit;
  kk_std_core_types__maybe _x_x2234 = kk_std_core_types__maybe_unbox(_b_x360, KK_OWNED, _ctx); /*maybe<()>*/
  kk_std_text_parse__mlift_parse_eof_10559(_x_x2234, _ctx);
  return kk_unit_box(_x_x2233);
}


// lift anonymous function
struct kk_std_text_parse__mlift_parse_eof_10561_fun2236__t {
  struct kk_function_s _base;
  kk_ssize_t i_10709;
};
static kk_box_t kk_std_text_parse__mlift_parse_eof_10561_fun2236(kk_function_t _fself, kk_function_t _b_x367, kk_box_t _b_x368, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse__new_mlift_parse_eof_10561_fun2236(kk_ssize_t i_10709, kk_context_t* _ctx) {
  struct kk_std_text_parse__mlift_parse_eof_10561_fun2236__t* _self = kk_function_alloc_as(struct kk_std_text_parse__mlift_parse_eof_10561_fun2236__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_text_parse__mlift_parse_eof_10561_fun2236, kk_context());
  _self->i_10709 = i_10709;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_text_parse__mlift_parse_eof_10561_fun2236(kk_function_t _fself, kk_function_t _b_x367, kk_box_t _b_x368, kk_context_t* _ctx) {
  struct kk_std_text_parse__mlift_parse_eof_10561_fun2236__t* _self = kk_function_as(struct kk_std_text_parse__mlift_parse_eof_10561_fun2236__t*, _fself, _ctx);
  kk_ssize_t i_10709 = _self->i_10709; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_10709, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_10709, _b_x367, _b_x368, _ctx);
}


// lift anonymous function
struct kk_std_text_parse__mlift_parse_eof_10561_fun2237__t {
  struct kk_function_s _base;
  kk_box_t x;
};
static kk_box_t kk_std_text_parse__mlift_parse_eof_10561_fun2237(kk_function_t _fself, kk_box_t _b_x377, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse__new_mlift_parse_eof_10561_fun2237(kk_box_t x, kk_context_t* _ctx) {
  struct kk_std_text_parse__mlift_parse_eof_10561_fun2237__t* _self = kk_function_alloc_as(struct kk_std_text_parse__mlift_parse_eof_10561_fun2237__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_text_parse__mlift_parse_eof_10561_fun2237, kk_context());
  _self->x = x;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_text_parse__mlift_parse_eof_10561_fun2237(kk_function_t _fself, kk_box_t _b_x377, kk_context_t* _ctx) {
  struct kk_std_text_parse__mlift_parse_eof_10561_fun2237__t* _self = kk_function_as(struct kk_std_text_parse__mlift_parse_eof_10561_fun2237__t*, _fself, _ctx);
  kk_box_t x = _self->x; /* 1779 */
  kk_drop_match(_self, {kk_box_dup(x, _ctx);}, {}, _ctx)
  kk_box_drop(_b_x377, _ctx);
  return x;
}

kk_box_t kk_std_text_parse__mlift_parse_eof_10561(kk_box_t x, kk_context_t* _ctx) { /* forall<a,e> (x : a) -> <parse|e> a */ 
  kk_ssize_t i_10709;
  kk_std_core_hnd__htag _x_x2222 = kk_std_core_hnd__htag_dup(kk_std_text_parse_parse_fs__tag, _ctx); /*hnd/htag<std/text/parse/parse>*/
  i_10709 = kk_std_core_hnd__evv_index(_x_x2222, _ctx); /*hnd/ev-index*/
  kk_evv_t w = kk_evv_swap_create1(i_10709,kk_context()); /*hnd/evv<<std/text/parse/parse|1780>>*/;
  kk_std_core_hnd__ev ev_10713 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
  kk_std_core_types__maybe x_1_10711;
  kk_box_t _x_x2223;
  {
    struct kk_std_core_hnd_Ev* _con_x2224 = kk_std_core_hnd__as_Ev(ev_10713, _ctx);
    kk_box_t _box_x338 = _con_x2224->hnd;
    int32_t m = _con_x2224->marker;
    kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x338, KK_BORROWED, _ctx);
    kk_std_text_parse__parse_dup(h, _ctx);
    {
      struct kk_std_text_parse__Hnd_parse* _con_x2225 = kk_std_text_parse__as_Hnd_parse(h, _ctx);
      kk_integer_t _pat_0 = _con_x2225->_cfc;
      kk_std_core_hnd__clause0 _pat_1 = _con_x2225->_fun_current_input;
      kk_std_core_hnd__clause1 _pat_2 = _con_x2225->_brk_fail;
      kk_std_core_hnd__clause0 _pat_3_0 = _con_x2225->_ctl_pick;
      kk_std_core_hnd__clause1 _fun_satisfy = _con_x2225->_fun_satisfy;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause0_drop(_pat_3_0, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_2, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_1, _ctx);
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_fun_satisfy, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x345 = _fun_satisfy.clause;
        _x_x2223 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x345, (_fun_unbox_x345, m, ev_10713, kk_function_box(kk_std_text_parse__new_mlift_parse_eof_10561_fun2226(_ctx), _ctx), _ctx), _ctx); /*46*/
      }
    }
  }
  x_1_10711 = kk_std_core_types__maybe_unbox(_x_x2223, KK_OWNED, _ctx); /*maybe<()>*/
  kk_unit_t y = kk_Unit;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__maybe_drop(x_1_10711, _ctx);
    kk_box_t _x_x2231 = kk_std_core_hnd_yield_extend(kk_std_text_parse__new_mlift_parse_eof_10561_fun2232(_ctx), _ctx); /*2419*/
    kk_unit_unbox(_x_x2231);
  }
  else {
    kk_std_text_parse__mlift_parse_eof_10559(x_1_10711, _ctx);
  }
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w,kk_context());
  kk_unit_t x_0_10707 = kk_Unit;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2235 = kk_std_core_hnd_yield_cont(kk_std_text_parse__new_mlift_parse_eof_10561_fun2236(i_10709, _ctx), _ctx); /*2568*/
    kk_unit_unbox(_x_x2235);
  }
  else {
    y;
  }
  if (kk_yielding(kk_context())) {
    return kk_std_core_hnd_yield_extend(kk_std_text_parse__new_mlift_parse_eof_10561_fun2237(x, _ctx), _ctx);
  }
  {
    return x;
  }
}


// lift anonymous function
struct kk_std_text_parse_parse_eof_fun2238__t {
  struct kk_function_s _base;
  kk_function_t p;
};
static kk_box_t kk_std_text_parse_parse_eof_fun2238(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_parse_eof_fun2238(kk_function_t p, kk_context_t* _ctx) {
  struct kk_std_text_parse_parse_eof_fun2238__t* _self = kk_function_alloc_as(struct kk_std_text_parse_parse_eof_fun2238__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_text_parse_parse_eof_fun2238, kk_context());
  _self->p = p;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_text_parse_parse_eof_fun2240__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_parse_eof_fun2240(kk_function_t _fself, kk_box_t _x1_x2239, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_parse_eof_fun2240(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_parse_eof_fun2240, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_text_parse_parse_eof_fun2240(kk_function_t _fself, kk_box_t _x1_x2239, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_text_parse__mlift_parse_eof_10561(_x1_x2239, _ctx);
}
static kk_box_t kk_std_text_parse_parse_eof_fun2238(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_text_parse_parse_eof_fun2238__t* _self = kk_function_as(struct kk_std_text_parse_parse_eof_fun2238__t*, _fself, _ctx);
  kk_function_t p = _self->p; /* () -> <std/text/parse/parse|1780> 1779 */
  kk_drop_match(_self, {kk_function_dup(p, _ctx);}, {}, _ctx)
  kk_box_t x_10718 = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), p, (p, _ctx), _ctx); /*1779*/;
  if (kk_yielding(kk_context())) {
    kk_box_drop(x_10718, _ctx);
    return kk_std_core_hnd_yield_extend(kk_std_text_parse_new_parse_eof_fun2240(_ctx), _ctx);
  }
  {
    return kk_std_text_parse__mlift_parse_eof_10561(x_10718, _ctx);
  }
}

kk_std_text_parse__parse_error kk_std_text_parse_parse_eof(kk_std_core_sslice__sslice input, kk_function_t p, kk_context_t* _ctx) { /* forall<a,e> (input : sslice/sslice, p : () -> <parse|e> a) -> e parse-error<a> */ 
  return kk_std_text_parse_parse(input, kk_std_text_parse_new_parse_eof_fun2238(p, _ctx), _ctx);
}
 
// monadic lift

kk_char_t kk_std_text_parse__mlift_char_is_10562(kk_string_t msg, kk_std_core_types__maybe _y_x10419, kk_context_t* _ctx) { /* (msg : string, maybe<char>) -> parse char */ 
  if (kk_std_core_types__is_Nothing(_y_x10419, _ctx)) {
    kk_std_core_hnd__ev ev_10720 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
    kk_box_t _x_x2241;
    {
      struct kk_std_core_hnd_Ev* _con_x2242 = kk_std_core_hnd__as_Ev(ev_10720, _ctx);
      kk_box_t _box_x381 = _con_x2242->hnd;
      int32_t m = _con_x2242->marker;
      kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x381, KK_BORROWED, _ctx);
      kk_std_text_parse__parse_dup(h, _ctx);
      {
        struct kk_std_text_parse__Hnd_parse* _con_x2243 = kk_std_text_parse__as_Hnd_parse(h, _ctx);
        kk_integer_t _pat_0_1 = _con_x2243->_cfc;
        kk_std_core_hnd__clause0 _pat_1_0 = _con_x2243->_fun_current_input;
        kk_std_core_hnd__clause1 _brk_fail = _con_x2243->_brk_fail;
        kk_std_core_hnd__clause0 _pat_2_0 = _con_x2243->_ctl_pick;
        kk_std_core_hnd__clause1 _pat_3 = _con_x2243->_fun_satisfy;
        if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
          kk_std_core_hnd__clause1_drop(_pat_3, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_2_0, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_1_0, _ctx);
          kk_integer_drop(_pat_0_1, _ctx);
          kk_datatype_ptr_free(h, _ctx);
        }
        else {
          kk_std_core_hnd__clause1_dup(_brk_fail, _ctx);
          kk_datatype_ptr_decref(h, _ctx);
        }
        {
          kk_function_t _fun_unbox_x385 = _brk_fail.clause;
          _x_x2241 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x385, (_fun_unbox_x385, m, ev_10720, kk_string_box(msg), _ctx), _ctx); /*46*/
        }
      }
    }
    return kk_char_unbox(_x_x2241, KK_OWNED, _ctx);
  }
  {
    kk_box_t _box_x389 = _y_x10419._cons.Just.value;
    kk_char_t x_0 = kk_char_unbox(_box_x389, KK_BORROWED, _ctx);
    kk_string_drop(msg, _ctx);
    kk_std_core_types__maybe_drop(_y_x10419, _ctx);
    return x_0;
  }
}


// lift anonymous function
struct kk_std_text_parse_char_is_fun2247__t {
  struct kk_function_s _base;
  kk_function_t pred;
};
static kk_box_t kk_std_text_parse_char_is_fun2247(kk_function_t _fself, kk_box_t _b_x403, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_char_is_fun2247(kk_function_t pred, kk_context_t* _ctx) {
  struct kk_std_text_parse_char_is_fun2247__t* _self = kk_function_alloc_as(struct kk_std_text_parse_char_is_fun2247__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_text_parse_char_is_fun2247, kk_context());
  _self->pred = pred;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_text_parse_char_is_fun2247(kk_function_t _fself, kk_box_t _b_x403, kk_context_t* _ctx) {
  struct kk_std_text_parse_char_is_fun2247__t* _self = kk_function_as(struct kk_std_text_parse_char_is_fun2247__t*, _fself, _ctx);
  kk_function_t pred = _self->pred; /* (char) -> bool */
  kk_drop_match(_self, {kk_function_dup(pred, _ctx);}, {}, _ctx)
  kk_std_core_types__maybe _x_x2248;
  kk_std_core_types__maybe _match_x1889;
  kk_std_core_sslice__sslice _x_x2249 = kk_std_core_sslice__sslice_unbox(_b_x403, KK_OWNED, _ctx); /*sslice/sslice*/
  _match_x1889 = kk_std_core_sslice_next(_x_x2249, _ctx); /*maybe<(char, sslice/sslice)>*/
  if (kk_std_core_types__is_Just(_match_x1889, _ctx)) {
    kk_box_t _box_x404 = _match_x1889._cons.Just.value;
    kk_std_core_types__tuple2 _pat_0_0_0 = kk_std_core_types__tuple2_unbox(_box_x404, KK_BORROWED, _ctx);
    if (kk_std_core_types__is_Tuple2(_pat_0_0_0, _ctx)) {
      kk_box_t _box_x405 = _pat_0_0_0.fst;
      kk_box_t _box_x406 = _pat_0_0_0.snd;
      kk_char_t c = kk_char_unbox(_box_x405, KK_BORROWED, _ctx);
      kk_function_t _x_x2251 = kk_function_dup(pred, _ctx); /*(char) -> bool*/
      if (kk_function_call(bool, (kk_function_t, kk_char_t, kk_context_t*), _x_x2251, (_x_x2251, c, _ctx), _ctx)) {
        kk_std_core_sslice__sslice rest = kk_std_core_sslice__sslice_unbox(_box_x406, KK_BORROWED, _ctx);
        kk_function_drop(pred, _ctx);
        kk_std_core_sslice__sslice_dup(rest, _ctx);
        kk_std_core_types__maybe_drop(_match_x1889, _ctx);
        kk_box_t _x_x2252;
        kk_std_core_types__tuple2 _x_x2253 = kk_std_core_types__new_Tuple2(kk_char_box(c, _ctx), kk_std_core_sslice__sslice_box(rest, _ctx), _ctx); /*(134, 135)*/
        _x_x2252 = kk_std_core_types__tuple2_box(_x_x2253, _ctx); /*88*/
        _x_x2248 = kk_std_core_types__new_Just(_x_x2252, _ctx); /*maybe<88>*/
        goto _match_x2250;
      }
    }
  }
  {
    kk_function_drop(pred, _ctx);
    kk_std_core_types__maybe_drop(_match_x1889, _ctx);
    _x_x2248 = kk_std_core_types__new_Nothing(_ctx); /*maybe<88>*/
  }
  _match_x2250: ;
  return kk_std_core_types__maybe_box(_x_x2248, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_char_is_fun2255__t {
  struct kk_function_s _base;
  kk_string_t msg;
};
static kk_box_t kk_std_text_parse_char_is_fun2255(kk_function_t _fself, kk_box_t _b_x415, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_char_is_fun2255(kk_string_t msg, kk_context_t* _ctx) {
  struct kk_std_text_parse_char_is_fun2255__t* _self = kk_function_alloc_as(struct kk_std_text_parse_char_is_fun2255__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_text_parse_char_is_fun2255, kk_context());
  _self->msg = msg;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_text_parse_char_is_fun2255(kk_function_t _fself, kk_box_t _b_x415, kk_context_t* _ctx) {
  struct kk_std_text_parse_char_is_fun2255__t* _self = kk_function_as(struct kk_std_text_parse_char_is_fun2255__t*, _fself, _ctx);
  kk_string_t msg = _self->msg; /* string */
  kk_drop_match(_self, {kk_string_dup(msg, _ctx);}, {}, _ctx)
  kk_std_core_types__maybe _y_x10419_426 = kk_std_core_types__maybe_unbox(_b_x415, KK_OWNED, _ctx); /*maybe<char>*/;
  kk_char_t _x_x2256 = kk_std_text_parse__mlift_char_is_10562(msg, _y_x10419_426, _ctx); /*char*/
  return kk_char_box(_x_x2256, _ctx);
}

kk_char_t kk_std_text_parse_char_is(kk_string_t msg, kk_function_t pred, kk_context_t* _ctx) { /* (msg : string, pred : (char) -> bool) -> parse char */ 
  kk_std_core_hnd__ev ev_10726 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
  kk_std_core_types__maybe x_10723;
  kk_box_t _x_x2244;
  {
    struct kk_std_core_hnd_Ev* _con_x2245 = kk_std_core_hnd__as_Ev(ev_10726, _ctx);
    kk_box_t _box_x390 = _con_x2245->hnd;
    int32_t m = _con_x2245->marker;
    kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x390, KK_BORROWED, _ctx);
    kk_std_text_parse__parse_dup(h, _ctx);
    {
      struct kk_std_text_parse__Hnd_parse* _con_x2246 = kk_std_text_parse__as_Hnd_parse(h, _ctx);
      kk_integer_t _pat_0 = _con_x2246->_cfc;
      kk_std_core_hnd__clause0 _pat_1_1 = _con_x2246->_fun_current_input;
      kk_std_core_hnd__clause1 _pat_2 = _con_x2246->_brk_fail;
      kk_std_core_hnd__clause0 _pat_3 = _con_x2246->_ctl_pick;
      kk_std_core_hnd__clause1 _fun_satisfy = _con_x2246->_fun_satisfy;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause0_drop(_pat_3, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_2, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_1_1, _ctx);
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_fun_satisfy, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x397 = _fun_satisfy.clause;
        _x_x2244 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x397, (_fun_unbox_x397, m, ev_10726, kk_function_box(kk_std_text_parse_new_char_is_fun2247(pred, _ctx), _ctx), _ctx), _ctx); /*46*/
      }
    }
  }
  x_10723 = kk_std_core_types__maybe_unbox(_x_x2244, KK_OWNED, _ctx); /*maybe<char>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__maybe_drop(x_10723, _ctx);
    kk_box_t _x_x2254 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_char_is_fun2255(msg, _ctx), _ctx); /*2419*/
    return kk_char_unbox(_x_x2254, KK_OWNED, _ctx);
  }
  if (kk_std_core_types__is_Nothing(x_10723, _ctx)) {
    kk_std_core_hnd__ev ev_0_10729 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
    kk_box_t _x_x2257;
    {
      struct kk_std_core_hnd_Ev* _con_x2258 = kk_std_core_hnd__as_Ev(ev_0_10729, _ctx);
      kk_box_t _box_x416 = _con_x2258->hnd;
      int32_t m_0 = _con_x2258->marker;
      kk_std_text_parse__parse h_0 = kk_std_text_parse__parse_unbox(_box_x416, KK_BORROWED, _ctx);
      kk_std_text_parse__parse_dup(h_0, _ctx);
      {
        struct kk_std_text_parse__Hnd_parse* _con_x2259 = kk_std_text_parse__as_Hnd_parse(h_0, _ctx);
        kk_integer_t _pat_0_2 = _con_x2259->_cfc;
        kk_std_core_hnd__clause0 _pat_1_3 = _con_x2259->_fun_current_input;
        kk_std_core_hnd__clause1 _brk_fail = _con_x2259->_brk_fail;
        kk_std_core_hnd__clause0 _pat_2_1 = _con_x2259->_ctl_pick;
        kk_std_core_hnd__clause1 _pat_3_1 = _con_x2259->_fun_satisfy;
        if kk_likely(kk_datatype_ptr_is_unique(h_0, _ctx)) {
          kk_std_core_hnd__clause1_drop(_pat_3_1, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_2_1, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_1_3, _ctx);
          kk_integer_drop(_pat_0_2, _ctx);
          kk_datatype_ptr_free(h_0, _ctx);
        }
        else {
          kk_std_core_hnd__clause1_dup(_brk_fail, _ctx);
          kk_datatype_ptr_decref(h_0, _ctx);
        }
        {
          kk_function_t _fun_unbox_x420 = _brk_fail.clause;
          _x_x2257 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x420, (_fun_unbox_x420, m_0, ev_0_10729, kk_string_box(msg), _ctx), _ctx); /*46*/
        }
      }
    }
    return kk_char_unbox(_x_x2257, KK_OWNED, _ctx);
  }
  {
    kk_box_t _box_x424 = x_10723._cons.Just.value;
    kk_char_t x_2 = kk_char_unbox(_box_x424, KK_BORROWED, _ctx);
    kk_std_core_types__maybe_drop(x_10723, _ctx);
    kk_string_drop(msg, _ctx);
    return x_2;
  }
}

kk_std_core_types__tuple2 kk_std_text_parse_next_while0(kk_std_core_sslice__sslice slice, kk_function_t pred, kk_std_core_types__list acc, kk_context_t* _ctx) { /* (slice : sslice/sslice, pred : (char) -> bool, acc : list<char>) -> (list<char>, sslice/sslice) */ 
  kk__tailcall: ;
  kk_std_core_types__maybe _match_x1887;
  kk_std_core_sslice__sslice _x_x2260 = kk_std_core_sslice__sslice_dup(slice, _ctx); /*sslice/sslice*/
  _match_x1887 = kk_std_core_sslice_next(_x_x2260, _ctx); /*maybe<(char, sslice/sslice)>*/
  if (kk_std_core_types__is_Just(_match_x1887, _ctx)) {
    kk_box_t _box_x427 = _match_x1887._cons.Just.value;
    kk_std_core_types__tuple2 _pat_0 = kk_std_core_types__tuple2_unbox(_box_x427, KK_BORROWED, _ctx);
    if (kk_std_core_types__is_Tuple2(_pat_0, _ctx)) {
      kk_box_t _box_x428 = _pat_0.fst;
      kk_box_t _box_x429 = _pat_0.snd;
      kk_char_t c = kk_char_unbox(_box_x428, KK_BORROWED, _ctx);
      kk_function_t _x_x2261 = kk_function_dup(pred, _ctx); /*(char) -> bool*/
      if (kk_function_call(bool, (kk_function_t, kk_char_t, kk_context_t*), _x_x2261, (_x_x2261, c, _ctx), _ctx)) {
        kk_std_core_sslice__sslice rest = kk_std_core_sslice__sslice_unbox(_box_x429, KK_BORROWED, _ctx);
        kk_std_core_sslice__sslice_drop(slice, _ctx);
        kk_std_core_sslice__sslice_dup(rest, _ctx);
        kk_std_core_types__maybe_drop(_match_x1887, _ctx);
        { // tailcall
          kk_std_core_types__list _x_x2262 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_char_box(c, _ctx), acc, _ctx); /*list<79>*/
          slice = rest;
          acc = _x_x2262;
          goto kk__tailcall;
        }
      }
    }
  }
  {
    kk_function_drop(pred, _ctx);
    kk_std_core_types__maybe_drop(_match_x1887, _ctx);
    kk_std_core_types__list _b_x432_436;
    if (kk_std_core_types__is_Nil(acc, _ctx)) {
      _b_x432_436 = kk_std_core_types__new_Nil(_ctx); /*list<char>*/
    }
    else {
      _b_x432_436 = kk_std_core_list__unroll_reverse_acc_10003(kk_std_core_types__new_Nil(_ctx), acc, _ctx); /*list<char>*/
    }
    return kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(_b_x432_436, _ctx), kk_std_core_sslice__sslice_box(slice, _ctx), _ctx);
  }
}
 
// monadic lift

kk_std_core_types__list kk_std_text_parse__mlift_chars_are_10563(kk_string_t msg, kk_std_core_types__maybe _y_x10422, kk_context_t* _ctx) { /* (msg : string, maybe<list<char>>) -> parse list<char> */ 
  if (kk_std_core_types__is_Nothing(_y_x10422, _ctx)) {
    kk_std_core_hnd__ev ev_10732 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
    kk_box_t _x_x2263;
    {
      struct kk_std_core_hnd_Ev* _con_x2264 = kk_std_core_hnd__as_Ev(ev_10732, _ctx);
      kk_box_t _box_x438 = _con_x2264->hnd;
      int32_t m = _con_x2264->marker;
      kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x438, KK_BORROWED, _ctx);
      kk_std_text_parse__parse_dup(h, _ctx);
      {
        struct kk_std_text_parse__Hnd_parse* _con_x2265 = kk_std_text_parse__as_Hnd_parse(h, _ctx);
        kk_integer_t _pat_0_1 = _con_x2265->_cfc;
        kk_std_core_hnd__clause0 _pat_1_0 = _con_x2265->_fun_current_input;
        kk_std_core_hnd__clause1 _brk_fail = _con_x2265->_brk_fail;
        kk_std_core_hnd__clause0 _pat_2_0 = _con_x2265->_ctl_pick;
        kk_std_core_hnd__clause1 _pat_3 = _con_x2265->_fun_satisfy;
        if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
          kk_std_core_hnd__clause1_drop(_pat_3, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_2_0, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_1_0, _ctx);
          kk_integer_drop(_pat_0_1, _ctx);
          kk_datatype_ptr_free(h, _ctx);
        }
        else {
          kk_std_core_hnd__clause1_dup(_brk_fail, _ctx);
          kk_datatype_ptr_decref(h, _ctx);
        }
        {
          kk_function_t _fun_unbox_x442 = _brk_fail.clause;
          _x_x2263 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x442, (_fun_unbox_x442, m, ev_10732, kk_string_box(msg), _ctx), _ctx); /*46*/
        }
      }
    }
    return kk_std_core_types__list_unbox(_x_x2263, KK_OWNED, _ctx);
  }
  {
    kk_box_t _box_x446 = _y_x10422._cons.Just.value;
    kk_std_core_types__list x_0 = kk_std_core_types__list_unbox(_box_x446, KK_BORROWED, _ctx);
    kk_string_drop(msg, _ctx);
    kk_std_core_types__list_dup(x_0, _ctx);
    kk_std_core_types__maybe_drop(_y_x10422, _ctx);
    return x_0;
  }
}


// lift anonymous function
struct kk_std_text_parse_chars_are_fun2269__t {
  struct kk_function_s _base;
  kk_function_t pred;
};
static kk_box_t kk_std_text_parse_chars_are_fun2269(kk_function_t _fself, kk_box_t _b_x460, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_chars_are_fun2269(kk_function_t pred, kk_context_t* _ctx) {
  struct kk_std_text_parse_chars_are_fun2269__t* _self = kk_function_alloc_as(struct kk_std_text_parse_chars_are_fun2269__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_text_parse_chars_are_fun2269, kk_context());
  _self->pred = pred;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_text_parse_chars_are_fun2269(kk_function_t _fself, kk_box_t _b_x460, kk_context_t* _ctx) {
  struct kk_std_text_parse_chars_are_fun2269__t* _self = kk_function_as(struct kk_std_text_parse_chars_are_fun2269__t*, _fself, _ctx);
  kk_function_t pred = _self->pred; /* (char) -> bool */
  kk_drop_match(_self, {kk_function_dup(pred, _ctx);}, {}, _ctx)
  kk_std_core_types__maybe _x_x2270;
  kk_std_core_types__tuple2 _match_x1886;
  kk_std_core_sslice__sslice _x_x2271 = kk_std_core_sslice__sslice_unbox(_b_x460, KK_OWNED, _ctx); /*sslice/sslice*/
  _match_x1886 = kk_std_text_parse_next_while0(_x_x2271, pred, kk_std_core_types__new_Nil(_ctx), _ctx); /*(list<char>, sslice/sslice)*/
  {
    kk_box_t _box_x461 = _match_x1886.fst;
    kk_box_t _box_x462 = _match_x1886.snd;
    kk_std_core_types__list _pat_0_0_0 = kk_std_core_types__list_unbox(_box_x461, KK_BORROWED, _ctx);
    kk_std_core_sslice__sslice _pat_1_0_0 = kk_std_core_sslice__sslice_unbox(_box_x462, KK_BORROWED, _ctx);
    if (kk_std_core_types__is_Nil(_pat_0_0_0, _ctx)) {
      kk_std_core_types__tuple2_drop(_match_x1886, _ctx);
      _x_x2270 = kk_std_core_types__new_Nothing(_ctx); /*forall<a> maybe<a>*/
      goto _match_x2272;
    }
  }
  {
    kk_box_t _box_x463 = _match_x1886.fst;
    kk_box_t _box_x464 = _match_x1886.snd;
    kk_std_core_sslice__sslice rest = kk_std_core_sslice__sslice_unbox(_box_x464, KK_BORROWED, _ctx);
    kk_std_core_types__list xs = kk_std_core_types__list_unbox(_box_x463, KK_BORROWED, _ctx);
    kk_std_core_sslice__sslice_dup(rest, _ctx);
    kk_std_core_types__list_dup(xs, _ctx);
    kk_std_core_types__tuple2_drop(_match_x1886, _ctx);
    kk_box_t _x_x2273;
    kk_std_core_types__tuple2 _x_x2274 = kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(xs, _ctx), kk_std_core_sslice__sslice_box(rest, _ctx), _ctx); /*(134, 135)*/
    _x_x2273 = kk_std_core_types__tuple2_box(_x_x2274, _ctx); /*88*/
    _x_x2270 = kk_std_core_types__new_Just(_x_x2273, _ctx); /*forall<a> maybe<a>*/
  }
  _match_x2272: ;
  return kk_std_core_types__maybe_box(_x_x2270, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_chars_are_fun2276__t {
  struct kk_function_s _base;
  kk_string_t msg;
};
static kk_box_t kk_std_text_parse_chars_are_fun2276(kk_function_t _fself, kk_box_t _b_x473, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_chars_are_fun2276(kk_string_t msg, kk_context_t* _ctx) {
  struct kk_std_text_parse_chars_are_fun2276__t* _self = kk_function_alloc_as(struct kk_std_text_parse_chars_are_fun2276__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_text_parse_chars_are_fun2276, kk_context());
  _self->msg = msg;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_text_parse_chars_are_fun2276(kk_function_t _fself, kk_box_t _b_x473, kk_context_t* _ctx) {
  struct kk_std_text_parse_chars_are_fun2276__t* _self = kk_function_as(struct kk_std_text_parse_chars_are_fun2276__t*, _fself, _ctx);
  kk_string_t msg = _self->msg; /* string */
  kk_drop_match(_self, {kk_string_dup(msg, _ctx);}, {}, _ctx)
  kk_std_core_types__maybe _y_x10422_484 = kk_std_core_types__maybe_unbox(_b_x473, KK_OWNED, _ctx); /*maybe<list<char>>*/;
  kk_std_core_types__list _x_x2277 = kk_std_text_parse__mlift_chars_are_10563(msg, _y_x10422_484, _ctx); /*list<char>*/
  return kk_std_core_types__list_box(_x_x2277, _ctx);
}

kk_std_core_types__list kk_std_text_parse_chars_are(kk_string_t msg, kk_function_t pred, kk_context_t* _ctx) { /* (msg : string, pred : (char) -> bool) -> parse list<char> */ 
  kk_std_core_hnd__ev ev_10738 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
  kk_std_core_types__maybe x_10735;
  kk_box_t _x_x2266;
  {
    struct kk_std_core_hnd_Ev* _con_x2267 = kk_std_core_hnd__as_Ev(ev_10738, _ctx);
    kk_box_t _box_x447 = _con_x2267->hnd;
    int32_t m = _con_x2267->marker;
    kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x447, KK_BORROWED, _ctx);
    kk_std_text_parse__parse_dup(h, _ctx);
    {
      struct kk_std_text_parse__Hnd_parse* _con_x2268 = kk_std_text_parse__as_Hnd_parse(h, _ctx);
      kk_integer_t _pat_0 = _con_x2268->_cfc;
      kk_std_core_hnd__clause0 _pat_1_1 = _con_x2268->_fun_current_input;
      kk_std_core_hnd__clause1 _pat_2 = _con_x2268->_brk_fail;
      kk_std_core_hnd__clause0 _pat_3 = _con_x2268->_ctl_pick;
      kk_std_core_hnd__clause1 _fun_satisfy = _con_x2268->_fun_satisfy;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause0_drop(_pat_3, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_2, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_1_1, _ctx);
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_fun_satisfy, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x454 = _fun_satisfy.clause;
        _x_x2266 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x454, (_fun_unbox_x454, m, ev_10738, kk_function_box(kk_std_text_parse_new_chars_are_fun2269(pred, _ctx), _ctx), _ctx), _ctx); /*46*/
      }
    }
  }
  x_10735 = kk_std_core_types__maybe_unbox(_x_x2266, KK_OWNED, _ctx); /*maybe<list<char>>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__maybe_drop(x_10735, _ctx);
    kk_box_t _x_x2275 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_chars_are_fun2276(msg, _ctx), _ctx); /*2419*/
    return kk_std_core_types__list_unbox(_x_x2275, KK_OWNED, _ctx);
  }
  if (kk_std_core_types__is_Nothing(x_10735, _ctx)) {
    kk_std_core_hnd__ev ev_0_10741 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
    kk_box_t _x_x2278;
    {
      struct kk_std_core_hnd_Ev* _con_x2279 = kk_std_core_hnd__as_Ev(ev_0_10741, _ctx);
      kk_box_t _box_x474 = _con_x2279->hnd;
      int32_t m_0 = _con_x2279->marker;
      kk_std_text_parse__parse h_0 = kk_std_text_parse__parse_unbox(_box_x474, KK_BORROWED, _ctx);
      kk_std_text_parse__parse_dup(h_0, _ctx);
      {
        struct kk_std_text_parse__Hnd_parse* _con_x2280 = kk_std_text_parse__as_Hnd_parse(h_0, _ctx);
        kk_integer_t _pat_0_2 = _con_x2280->_cfc;
        kk_std_core_hnd__clause0 _pat_1_3 = _con_x2280->_fun_current_input;
        kk_std_core_hnd__clause1 _brk_fail = _con_x2280->_brk_fail;
        kk_std_core_hnd__clause0 _pat_2_1 = _con_x2280->_ctl_pick;
        kk_std_core_hnd__clause1 _pat_3_1 = _con_x2280->_fun_satisfy;
        if kk_likely(kk_datatype_ptr_is_unique(h_0, _ctx)) {
          kk_std_core_hnd__clause1_drop(_pat_3_1, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_2_1, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_1_3, _ctx);
          kk_integer_drop(_pat_0_2, _ctx);
          kk_datatype_ptr_free(h_0, _ctx);
        }
        else {
          kk_std_core_hnd__clause1_dup(_brk_fail, _ctx);
          kk_datatype_ptr_decref(h_0, _ctx);
        }
        {
          kk_function_t _fun_unbox_x478 = _brk_fail.clause;
          _x_x2278 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x478, (_fun_unbox_x478, m_0, ev_0_10741, kk_string_box(msg), _ctx), _ctx); /*46*/
        }
      }
    }
    return kk_std_core_types__list_unbox(_x_x2278, KK_OWNED, _ctx);
  }
  {
    kk_box_t _box_x482 = x_10735._cons.Just.value;
    kk_std_core_types__list x_2 = kk_std_core_types__list_unbox(_box_x482, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(x_2, _ctx);
    kk_std_core_types__maybe_drop(x_10735, _ctx);
    kk_string_drop(msg, _ctx);
    return x_2;
  }
}

kk_std_core_types__maybe kk_std_text_parse__unroll_next_match_10001(kk_std_core_sslice__sslice slice, kk_std_core_types__list cs, kk_context_t* _ctx) { /* (slice : sslice/sslice, cs : list<char>) -> maybe<sslice/sslice> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Nil(cs, _ctx)) {
    return kk_std_core_types__new_Just(kk_std_core_sslice__sslice_box(slice, _ctx), _ctx);
  }
  {
    struct kk_std_core_types_Cons* _con_x2281 = kk_std_core_types__as_Cons(cs, _ctx);
    kk_box_t _box_x486 = _con_x2281->head;
    kk_std_core_types__list cc = _con_x2281->tail;
    kk_char_t c = kk_char_unbox(_box_x486, KK_BORROWED, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(cs, _ctx)) {
      kk_datatype_ptr_free(cs, _ctx);
    }
    else {
      kk_std_core_types__list_dup(cc, _ctx);
      kk_datatype_ptr_decref(cs, _ctx);
    }
    kk_std_core_types__maybe _match_x1884 = kk_std_core_sslice_next(slice, _ctx); /*maybe<(char, sslice/sslice)>*/;
    if (kk_std_core_types__is_Just(_match_x1884, _ctx)) {
      kk_box_t _box_x487 = _match_x1884._cons.Just.value;
      kk_std_core_types__tuple2 _pat_2 = kk_std_core_types__tuple2_unbox(_box_x487, KK_BORROWED, _ctx);
      if (kk_std_core_types__is_Tuple2(_pat_2, _ctx)) {
        kk_box_t _box_x488 = _pat_2.fst;
        kk_box_t _box_x489 = _pat_2.snd;
        kk_char_t d = kk_char_unbox(_box_x488, KK_BORROWED, _ctx);
        if (c == d) {
          kk_std_core_sslice__sslice rest = kk_std_core_sslice__sslice_unbox(_box_x489, KK_BORROWED, _ctx);
          kk_std_core_sslice__sslice_dup(rest, _ctx);
          kk_std_core_types__maybe_drop(_match_x1884, _ctx);
          { // tailcall
            slice = rest;
            cs = cc;
            goto kk__tailcall;
          }
        }
      }
    }
    {
      kk_std_core_types__list_drop(cc, _ctx);
      kk_std_core_types__maybe_drop(_match_x1884, _ctx);
      return kk_std_core_types__new_Nothing(_ctx);
    }
  }
}
 
// monadic lift

kk_string_t kk_std_text_parse__mlift_pstring_10564(kk_string_t s, kk_std_core_types__maybe _y_x10425, kk_context_t* _ctx) { /* (s : string, maybe<string>) -> parse string */ 
  if (kk_std_core_types__is_Nothing(_y_x10425, _ctx)) {
    kk_std_core_hnd__ev ev_10744 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
    kk_box_t _x_x2282;
    {
      struct kk_std_core_hnd_Ev* _con_x2283 = kk_std_core_hnd__as_Ev(ev_10744, _ctx);
      kk_box_t _box_x493 = _con_x2283->hnd;
      int32_t m = _con_x2283->marker;
      kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x493, KK_BORROWED, _ctx);
      kk_std_text_parse__parse_dup(h, _ctx);
      {
        struct kk_std_text_parse__Hnd_parse* _con_x2284 = kk_std_text_parse__as_Hnd_parse(h, _ctx);
        kk_integer_t _pat_0_1 = _con_x2284->_cfc;
        kk_std_core_hnd__clause0 _pat_1_0 = _con_x2284->_fun_current_input;
        kk_std_core_hnd__clause1 _brk_fail = _con_x2284->_brk_fail;
        kk_std_core_hnd__clause0 _pat_2_0 = _con_x2284->_ctl_pick;
        kk_std_core_hnd__clause1 _pat_3 = _con_x2284->_fun_satisfy;
        if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
          kk_std_core_hnd__clause1_drop(_pat_3, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_2_0, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_1_0, _ctx);
          kk_integer_drop(_pat_0_1, _ctx);
          kk_datatype_ptr_free(h, _ctx);
        }
        else {
          kk_std_core_hnd__clause1_dup(_brk_fail, _ctx);
          kk_datatype_ptr_decref(h, _ctx);
        }
        {
          kk_function_t _fun_unbox_x497 = _brk_fail.clause;
          _x_x2282 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x497, (_fun_unbox_x497, m, ev_10744, kk_string_box(s), _ctx), _ctx); /*46*/
        }
      }
    }
    return kk_string_unbox(_x_x2282);
  }
  {
    kk_box_t _box_x501 = _y_x10425._cons.Just.value;
    kk_string_t x_0 = kk_string_unbox(_box_x501);
    kk_string_drop(s, _ctx);
    kk_string_dup(x_0, _ctx);
    kk_std_core_types__maybe_drop(_y_x10425, _ctx);
    return x_0;
  }
}


// lift anonymous function
struct kk_std_text_parse_pstring_fun2290__t {
  struct kk_function_s _base;
  kk_string_t s;
};
static kk_box_t kk_std_text_parse_pstring_fun2290(kk_function_t _fself, kk_box_t _b_x515, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_pstring_fun2290(kk_string_t s, kk_context_t* _ctx) {
  struct kk_std_text_parse_pstring_fun2290__t* _self = kk_function_alloc_as(struct kk_std_text_parse_pstring_fun2290__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_text_parse_pstring_fun2290, kk_context());
  _self->s = s;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_text_parse_pstring_fun2290(kk_function_t _fself, kk_box_t _b_x515, kk_context_t* _ctx) {
  struct kk_std_text_parse_pstring_fun2290__t* _self = kk_function_as(struct kk_std_text_parse_pstring_fun2290__t*, _fself, _ctx);
  kk_string_t s = _self->s; /* string */
  kk_drop_match(_self, {kk_string_dup(s, _ctx);}, {}, _ctx)
  kk_std_core_types__list cs_10028;
  kk_string_t _x_x2291 = kk_string_dup(s, _ctx); /*string*/
  cs_10028 = kk_std_core_string_list(_x_x2291, _ctx); /*list<char>*/
  kk_std_core_types__maybe _x_x2292;
  kk_std_core_types__maybe _match_x1883;
  if (kk_std_core_types__is_Nil(cs_10028, _ctx)) {
    _match_x1883 = kk_std_core_types__new_Just(_b_x515, _ctx); /*maybe<88>*/
  }
  else {
    kk_std_core_sslice__sslice _x_x2293 = kk_std_core_sslice__sslice_unbox(_b_x515, KK_OWNED, _ctx); /*sslice/sslice*/
    _match_x1883 = kk_std_text_parse__unroll_next_match_10001(_x_x2293, cs_10028, _ctx); /*maybe<88>*/
  }
  if (kk_std_core_types__is_Just(_match_x1883, _ctx)) {
    kk_box_t _box_x517 = _match_x1883._cons.Just.value;
    kk_std_core_sslice__sslice rest = kk_std_core_sslice__sslice_unbox(_box_x517, KK_BORROWED, _ctx);
    kk_std_core_sslice__sslice_dup(rest, _ctx);
    kk_std_core_types__maybe_drop(_match_x1883, _ctx);
    kk_box_t _x_x2294;
    kk_std_core_types__tuple2 _x_x2295 = kk_std_core_types__new_Tuple2(kk_string_box(s), kk_std_core_sslice__sslice_box(rest, _ctx), _ctx); /*(134, 135)*/
    _x_x2294 = kk_std_core_types__tuple2_box(_x_x2295, _ctx); /*88*/
    _x_x2292 = kk_std_core_types__new_Just(_x_x2294, _ctx); /*maybe<88>*/
  }
  else {
    kk_string_drop(s, _ctx);
    _x_x2292 = kk_std_core_types__new_Nothing(_ctx); /*maybe<88>*/
  }
  return kk_std_core_types__maybe_box(_x_x2292, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_pstring_fun2297__t {
  struct kk_function_s _base;
  kk_string_t s;
};
static kk_box_t kk_std_text_parse_pstring_fun2297(kk_function_t _fself, kk_box_t _b_x527, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_pstring_fun2297(kk_string_t s, kk_context_t* _ctx) {
  struct kk_std_text_parse_pstring_fun2297__t* _self = kk_function_alloc_as(struct kk_std_text_parse_pstring_fun2297__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_text_parse_pstring_fun2297, kk_context());
  _self->s = s;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_text_parse_pstring_fun2297(kk_function_t _fself, kk_box_t _b_x527, kk_context_t* _ctx) {
  struct kk_std_text_parse_pstring_fun2297__t* _self = kk_function_as(struct kk_std_text_parse_pstring_fun2297__t*, _fself, _ctx);
  kk_string_t s = _self->s; /* string */
  kk_drop_match(_self, {kk_string_dup(s, _ctx);}, {}, _ctx)
  kk_std_core_types__maybe _y_x10425_538 = kk_std_core_types__maybe_unbox(_b_x527, KK_OWNED, _ctx); /*maybe<string>*/;
  kk_string_t _x_x2298 = kk_std_text_parse__mlift_pstring_10564(s, _y_x10425_538, _ctx); /*string*/
  return kk_string_box(_x_x2298);
}

kk_string_t kk_std_text_parse_pstring(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> parse string */ 
  kk_std_core_hnd__ev ev_10750 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
  kk_std_core_types__maybe x_10747;
  kk_box_t _x_x2285;
  {
    struct kk_std_core_hnd_Ev* _con_x2286 = kk_std_core_hnd__as_Ev(ev_10750, _ctx);
    kk_box_t _box_x502 = _con_x2286->hnd;
    int32_t m = _con_x2286->marker;
    kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x502, KK_BORROWED, _ctx);
    kk_std_text_parse__parse_dup(h, _ctx);
    {
      struct kk_std_text_parse__Hnd_parse* _con_x2287 = kk_std_text_parse__as_Hnd_parse(h, _ctx);
      kk_integer_t _pat_0 = _con_x2287->_cfc;
      kk_std_core_hnd__clause0 _pat_1_1 = _con_x2287->_fun_current_input;
      kk_std_core_hnd__clause1 _pat_2 = _con_x2287->_brk_fail;
      kk_std_core_hnd__clause0 _pat_3 = _con_x2287->_ctl_pick;
      kk_std_core_hnd__clause1 _fun_satisfy = _con_x2287->_fun_satisfy;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause0_drop(_pat_3, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_2, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_1_1, _ctx);
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_fun_satisfy, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x509 = _fun_satisfy.clause;
        kk_box_t _x_x2288;
        kk_function_t _x_x2289;
        kk_string_dup(s, _ctx);
        _x_x2289 = kk_std_text_parse_new_pstring_fun2290(s, _ctx); /*(513) -> 514*/
        _x_x2288 = kk_function_box(_x_x2289, _ctx); /*45*/
        _x_x2285 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x509, (_fun_unbox_x509, m, ev_10750, _x_x2288, _ctx), _ctx); /*46*/
      }
    }
  }
  x_10747 = kk_std_core_types__maybe_unbox(_x_x2285, KK_OWNED, _ctx); /*maybe<string>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__maybe_drop(x_10747, _ctx);
    kk_box_t _x_x2296 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_pstring_fun2297(s, _ctx), _ctx); /*2419*/
    return kk_string_unbox(_x_x2296);
  }
  if (kk_std_core_types__is_Nothing(x_10747, _ctx)) {
    kk_std_core_hnd__ev ev_0_10753 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
    kk_box_t _x_x2299;
    {
      struct kk_std_core_hnd_Ev* _con_x2300 = kk_std_core_hnd__as_Ev(ev_0_10753, _ctx);
      kk_box_t _box_x528 = _con_x2300->hnd;
      int32_t m_0 = _con_x2300->marker;
      kk_std_text_parse__parse h_0 = kk_std_text_parse__parse_unbox(_box_x528, KK_BORROWED, _ctx);
      kk_std_text_parse__parse_dup(h_0, _ctx);
      {
        struct kk_std_text_parse__Hnd_parse* _con_x2301 = kk_std_text_parse__as_Hnd_parse(h_0, _ctx);
        kk_integer_t _pat_0_2 = _con_x2301->_cfc;
        kk_std_core_hnd__clause0 _pat_1_3 = _con_x2301->_fun_current_input;
        kk_std_core_hnd__clause1 _brk_fail = _con_x2301->_brk_fail;
        kk_std_core_hnd__clause0 _pat_2_1 = _con_x2301->_ctl_pick;
        kk_std_core_hnd__clause1 _pat_3_1 = _con_x2301->_fun_satisfy;
        if kk_likely(kk_datatype_ptr_is_unique(h_0, _ctx)) {
          kk_std_core_hnd__clause1_drop(_pat_3_1, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_2_1, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_1_3, _ctx);
          kk_integer_drop(_pat_0_2, _ctx);
          kk_datatype_ptr_free(h_0, _ctx);
        }
        else {
          kk_std_core_hnd__clause1_dup(_brk_fail, _ctx);
          kk_datatype_ptr_decref(h_0, _ctx);
        }
        {
          kk_function_t _fun_unbox_x532 = _brk_fail.clause;
          _x_x2299 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x532, (_fun_unbox_x532, m_0, ev_0_10753, kk_string_box(s), _ctx), _ctx); /*46*/
        }
      }
    }
    return kk_string_unbox(_x_x2299);
  }
  {
    kk_box_t _box_x536 = x_10747._cons.Just.value;
    kk_string_t x_2 = kk_string_unbox(_box_x536);
    kk_string_dup(x_2, _ctx);
    kk_std_core_types__maybe_drop(x_10747, _ctx);
    kk_string_drop(s, _ctx);
    return x_2;
  }
}
 
// monadic lift

kk_char_t kk_std_text_parse__mlift_char_10565(kk_string_t msg_10031, kk_std_core_types__maybe _y_x10428, kk_context_t* _ctx) { /* (msg@10031 : string, maybe<char>) -> parse char */ 
  if (kk_std_core_types__is_Nothing(_y_x10428, _ctx)) {
    kk_std_core_hnd__ev ev_10756 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
    kk_box_t _x_x2302;
    {
      struct kk_std_core_hnd_Ev* _con_x2303 = kk_std_core_hnd__as_Ev(ev_10756, _ctx);
      kk_box_t _box_x539 = _con_x2303->hnd;
      int32_t m = _con_x2303->marker;
      kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x539, KK_BORROWED, _ctx);
      kk_std_text_parse__parse_dup(h, _ctx);
      {
        struct kk_std_text_parse__Hnd_parse* _con_x2304 = kk_std_text_parse__as_Hnd_parse(h, _ctx);
        kk_integer_t _pat_0_1 = _con_x2304->_cfc;
        kk_std_core_hnd__clause0 _pat_1_0 = _con_x2304->_fun_current_input;
        kk_std_core_hnd__clause1 _brk_fail = _con_x2304->_brk_fail;
        kk_std_core_hnd__clause0 _pat_2_0 = _con_x2304->_ctl_pick;
        kk_std_core_hnd__clause1 _pat_3 = _con_x2304->_fun_satisfy;
        if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
          kk_std_core_hnd__clause1_drop(_pat_3, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_2_0, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_1_0, _ctx);
          kk_integer_drop(_pat_0_1, _ctx);
          kk_datatype_ptr_free(h, _ctx);
        }
        else {
          kk_std_core_hnd__clause1_dup(_brk_fail, _ctx);
          kk_datatype_ptr_decref(h, _ctx);
        }
        {
          kk_function_t _fun_unbox_x543 = _brk_fail.clause;
          _x_x2302 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x543, (_fun_unbox_x543, m, ev_10756, kk_string_box(msg_10031), _ctx), _ctx); /*46*/
        }
      }
    }
    return kk_char_unbox(_x_x2302, KK_OWNED, _ctx);
  }
  {
    kk_box_t _box_x547 = _y_x10428._cons.Just.value;
    kk_char_t x_0 = kk_char_unbox(_box_x547, KK_BORROWED, _ctx);
    kk_string_drop(msg_10031, _ctx);
    kk_std_core_types__maybe_drop(_y_x10428, _ctx);
    return x_0;
  }
}


// lift anonymous function
struct kk_std_text_parse_char_fun2314__t {
  struct kk_function_s _base;
  kk_char_t c;
};
static kk_box_t kk_std_text_parse_char_fun2314(kk_function_t _fself, kk_box_t _b_x561, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_char_fun2314(kk_char_t c, kk_context_t* _ctx) {
  struct kk_std_text_parse_char_fun2314__t* _self = kk_function_alloc_as(struct kk_std_text_parse_char_fun2314__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_text_parse_char_fun2314, kk_context());
  _self->c = c;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_text_parse_char_fun2314(kk_function_t _fself, kk_box_t _b_x561, kk_context_t* _ctx) {
  struct kk_std_text_parse_char_fun2314__t* _self = kk_function_as(struct kk_std_text_parse_char_fun2314__t*, _fself, _ctx);
  kk_char_t c = _self->c; /* char */
  kk_drop_match(_self, {kk_skip_dup(c, _ctx);}, {}, _ctx)
  kk_std_core_types__maybe _x_x2315;
  kk_std_core_types__maybe _match_x1881;
  kk_std_core_sslice__sslice _x_x2316 = kk_std_core_sslice__sslice_unbox(_b_x561, KK_OWNED, _ctx); /*sslice/sslice*/
  _match_x1881 = kk_std_core_sslice_next(_x_x2316, _ctx); /*maybe<(char, sslice/sslice)>*/
  if (kk_std_core_types__is_Just(_match_x1881, _ctx)) {
    kk_box_t _box_x562 = _match_x1881._cons.Just.value;
    kk_std_core_types__tuple2 _pat_0_0_0 = kk_std_core_types__tuple2_unbox(_box_x562, KK_BORROWED, _ctx);
    if (kk_std_core_types__is_Tuple2(_pat_0_0_0, _ctx)) {
      kk_box_t _box_x563 = _pat_0_0_0.fst;
      kk_box_t _box_x564 = _pat_0_0_0.snd;
      kk_char_t c_0 = kk_char_unbox(_box_x563, KK_BORROWED, _ctx);
      if (c == c_0) {
        kk_std_core_sslice__sslice rest = kk_std_core_sslice__sslice_unbox(_box_x564, KK_BORROWED, _ctx);
        kk_std_core_sslice__sslice_dup(rest, _ctx);
        kk_std_core_types__maybe_drop(_match_x1881, _ctx);
        kk_box_t _x_x2318;
        kk_std_core_types__tuple2 _x_x2319 = kk_std_core_types__new_Tuple2(kk_char_box(c_0, _ctx), kk_std_core_sslice__sslice_box(rest, _ctx), _ctx); /*(134, 135)*/
        _x_x2318 = kk_std_core_types__tuple2_box(_x_x2319, _ctx); /*88*/
        _x_x2315 = kk_std_core_types__new_Just(_x_x2318, _ctx); /*maybe<88>*/
        goto _match_x2317;
      }
    }
  }
  {
    kk_std_core_types__maybe_drop(_match_x1881, _ctx);
    _x_x2315 = kk_std_core_types__new_Nothing(_ctx); /*maybe<88>*/
  }
  _match_x2317: ;
  return kk_std_core_types__maybe_box(_x_x2315, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_char_fun2321__t {
  struct kk_function_s _base;
  kk_string_t msg_10031;
};
static kk_box_t kk_std_text_parse_char_fun2321(kk_function_t _fself, kk_box_t _b_x573, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_char_fun2321(kk_string_t msg_10031, kk_context_t* _ctx) {
  struct kk_std_text_parse_char_fun2321__t* _self = kk_function_alloc_as(struct kk_std_text_parse_char_fun2321__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_text_parse_char_fun2321, kk_context());
  _self->msg_10031 = msg_10031;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_text_parse_char_fun2321(kk_function_t _fself, kk_box_t _b_x573, kk_context_t* _ctx) {
  struct kk_std_text_parse_char_fun2321__t* _self = kk_function_as(struct kk_std_text_parse_char_fun2321__t*, _fself, _ctx);
  kk_string_t msg_10031 = _self->msg_10031; /* string */
  kk_drop_match(_self, {kk_string_dup(msg_10031, _ctx);}, {}, _ctx)
  kk_std_core_types__maybe _y_x10428_584 = kk_std_core_types__maybe_unbox(_b_x573, KK_OWNED, _ctx); /*maybe<char>*/;
  kk_char_t _x_x2322 = kk_std_text_parse__mlift_char_10565(msg_10031, _y_x10428_584, _ctx); /*char*/
  return kk_char_box(_x_x2322, _ctx);
}

kk_char_t kk_std_text_parse_char(kk_char_t c, kk_context_t* _ctx) { /* (c : char) -> parse char */ 
  kk_string_t msg_10031;
  kk_string_t _x_x2305;
  kk_define_string_literal(static, _s_x2306, 1, "\'", _ctx)
  _x_x2305 = kk_string_dup(_s_x2306, _ctx); /*string*/
  kk_string_t _x_x2307;
  kk_string_t _x_x2308 = kk_std_core_show_show_char(c, _ctx); /*string*/
  kk_string_t _x_x2309;
  kk_define_string_literal(static, _s_x2310, 1, "\'", _ctx)
  _x_x2309 = kk_string_dup(_s_x2310, _ctx); /*string*/
  _x_x2307 = kk_std_core_types__lp__plus__plus__rp_(_x_x2308, _x_x2309, _ctx); /*string*/
  msg_10031 = kk_std_core_types__lp__plus__plus__rp_(_x_x2305, _x_x2307, _ctx); /*string*/
  kk_std_core_hnd__ev ev_10762 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
  kk_std_core_types__maybe x_10759;
  kk_box_t _x_x2311;
  {
    struct kk_std_core_hnd_Ev* _con_x2312 = kk_std_core_hnd__as_Ev(ev_10762, _ctx);
    kk_box_t _box_x548 = _con_x2312->hnd;
    int32_t m = _con_x2312->marker;
    kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x548, KK_BORROWED, _ctx);
    kk_std_text_parse__parse_dup(h, _ctx);
    {
      struct kk_std_text_parse__Hnd_parse* _con_x2313 = kk_std_text_parse__as_Hnd_parse(h, _ctx);
      kk_integer_t _pat_0 = _con_x2313->_cfc;
      kk_std_core_hnd__clause0 _pat_1_1 = _con_x2313->_fun_current_input;
      kk_std_core_hnd__clause1 _pat_2 = _con_x2313->_brk_fail;
      kk_std_core_hnd__clause0 _pat_3 = _con_x2313->_ctl_pick;
      kk_std_core_hnd__clause1 _fun_satisfy = _con_x2313->_fun_satisfy;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause0_drop(_pat_3, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_2, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_1_1, _ctx);
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_fun_satisfy, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x555 = _fun_satisfy.clause;
        _x_x2311 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x555, (_fun_unbox_x555, m, ev_10762, kk_function_box(kk_std_text_parse_new_char_fun2314(c, _ctx), _ctx), _ctx), _ctx); /*46*/
      }
    }
  }
  x_10759 = kk_std_core_types__maybe_unbox(_x_x2311, KK_OWNED, _ctx); /*maybe<char>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__maybe_drop(x_10759, _ctx);
    kk_box_t _x_x2320 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_char_fun2321(msg_10031, _ctx), _ctx); /*2419*/
    return kk_char_unbox(_x_x2320, KK_OWNED, _ctx);
  }
  if (kk_std_core_types__is_Nothing(x_10759, _ctx)) {
    kk_std_core_hnd__ev ev_0_10765 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
    kk_box_t _x_x2323;
    {
      struct kk_std_core_hnd_Ev* _con_x2324 = kk_std_core_hnd__as_Ev(ev_0_10765, _ctx);
      kk_box_t _box_x574 = _con_x2324->hnd;
      int32_t m_0 = _con_x2324->marker;
      kk_std_text_parse__parse h_0 = kk_std_text_parse__parse_unbox(_box_x574, KK_BORROWED, _ctx);
      kk_std_text_parse__parse_dup(h_0, _ctx);
      {
        struct kk_std_text_parse__Hnd_parse* _con_x2325 = kk_std_text_parse__as_Hnd_parse(h_0, _ctx);
        kk_integer_t _pat_0_2 = _con_x2325->_cfc;
        kk_std_core_hnd__clause0 _pat_1_3 = _con_x2325->_fun_current_input;
        kk_std_core_hnd__clause1 _brk_fail = _con_x2325->_brk_fail;
        kk_std_core_hnd__clause0 _pat_2_1 = _con_x2325->_ctl_pick;
        kk_std_core_hnd__clause1 _pat_3_1 = _con_x2325->_fun_satisfy;
        if kk_likely(kk_datatype_ptr_is_unique(h_0, _ctx)) {
          kk_std_core_hnd__clause1_drop(_pat_3_1, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_2_1, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_1_3, _ctx);
          kk_integer_drop(_pat_0_2, _ctx);
          kk_datatype_ptr_free(h_0, _ctx);
        }
        else {
          kk_std_core_hnd__clause1_dup(_brk_fail, _ctx);
          kk_datatype_ptr_decref(h_0, _ctx);
        }
        {
          kk_function_t _fun_unbox_x578 = _brk_fail.clause;
          _x_x2323 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x578, (_fun_unbox_x578, m_0, ev_0_10765, kk_string_box(msg_10031), _ctx), _ctx); /*46*/
        }
      }
    }
    return kk_char_unbox(_x_x2323, KK_OWNED, _ctx);
  }
  {
    kk_box_t _box_x582 = x_10759._cons.Just.value;
    kk_char_t x_2 = kk_char_unbox(_box_x582, KK_BORROWED, _ctx);
    kk_std_core_types__maybe_drop(x_10759, _ctx);
    kk_string_drop(msg_10031, _ctx);
    return x_2;
  }
}
 
// monadic lift

kk_char_t kk_std_text_parse__mlift_no_digit_10566(kk_std_core_types__maybe _y_x10431, kk_context_t* _ctx) { /* (maybe<char>) -> parse char */ 
  if (kk_std_core_types__is_Nothing(_y_x10431, _ctx)) {
    kk_std_core_hnd__ev ev_10768 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
    kk_box_t _x_x2326;
    {
      struct kk_std_core_hnd_Ev* _con_x2327 = kk_std_core_hnd__as_Ev(ev_10768, _ctx);
      kk_box_t _box_x585 = _con_x2327->hnd;
      int32_t m = _con_x2327->marker;
      kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x585, KK_BORROWED, _ctx);
      kk_std_text_parse__parse_dup(h, _ctx);
      {
        struct kk_std_text_parse__Hnd_parse* _con_x2328 = kk_std_text_parse__as_Hnd_parse(h, _ctx);
        kk_integer_t _pat_0_1 = _con_x2328->_cfc;
        kk_std_core_hnd__clause0 _pat_1_0 = _con_x2328->_fun_current_input;
        kk_std_core_hnd__clause1 _brk_fail = _con_x2328->_brk_fail;
        kk_std_core_hnd__clause0 _pat_2_0 = _con_x2328->_ctl_pick;
        kk_std_core_hnd__clause1 _pat_3 = _con_x2328->_fun_satisfy;
        if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
          kk_std_core_hnd__clause1_drop(_pat_3, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_2_0, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_1_0, _ctx);
          kk_integer_drop(_pat_0_1, _ctx);
          kk_datatype_ptr_free(h, _ctx);
        }
        else {
          kk_std_core_hnd__clause1_dup(_brk_fail, _ctx);
          kk_datatype_ptr_decref(h, _ctx);
        }
        {
          kk_function_t _fun_unbox_x589 = _brk_fail.clause;
          kk_box_t _x_x2329;
          kk_string_t _x_x2330;
          kk_define_string_literal(static, _s_x2331, 11, "not a digit", _ctx)
          _x_x2330 = kk_string_dup(_s_x2331, _ctx); /*string*/
          _x_x2329 = kk_string_box(_x_x2330); /*45*/
          _x_x2326 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x589, (_fun_unbox_x589, m, ev_10768, _x_x2329, _ctx), _ctx); /*46*/
        }
      }
    }
    return kk_char_unbox(_x_x2326, KK_OWNED, _ctx);
  }
  {
    kk_box_t _box_x593 = _y_x10431._cons.Just.value;
    kk_char_t x_0 = kk_char_unbox(_box_x593, KK_BORROWED, _ctx);
    kk_std_core_types__maybe_drop(_y_x10431, _ctx);
    return x_0;
  }
}


// lift anonymous function
struct kk_std_text_parse_no_digit_fun2335__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_no_digit_fun2335(kk_function_t _fself, kk_box_t _b_x607, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_no_digit_fun2335(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_no_digit_fun2335, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_text_parse_no_digit_fun2335(kk_function_t _fself, kk_box_t _b_x607, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__maybe _x_x2336;
  kk_std_core_types__maybe _match_x1878;
  kk_std_core_sslice__sslice _x_x2337 = kk_std_core_sslice__sslice_unbox(_b_x607, KK_OWNED, _ctx); /*sslice/sslice*/
  _match_x1878 = kk_std_core_sslice_next(_x_x2337, _ctx); /*maybe<(char, sslice/sslice)>*/
  if (kk_std_core_types__is_Just(_match_x1878, _ctx)) {
    kk_box_t _box_x608 = _match_x1878._cons.Just.value;
    kk_std_core_types__tuple2 _pat_0_0_0 = kk_std_core_types__tuple2_unbox(_box_x608, KK_BORROWED, _ctx);
    if (kk_std_core_types__is_Tuple2(_pat_0_0_0, _ctx)) {
      kk_box_t _box_x609 = _pat_0_0_0.fst;
      kk_box_t _box_x610 = _pat_0_0_0.snd;
      kk_char_t c = kk_char_unbox(_box_x609, KK_BORROWED, _ctx);
      bool b_10039;
      bool _match_x1879 = (c >= ('0')); /*bool*/;
      if (_match_x1879) {
        b_10039 = (c <= ('9')); /*bool*/
      }
      else {
        b_10039 = false; /*bool*/
      }
      bool _x_x2339;
      if (b_10039) {
        _x_x2339 = false; /*bool*/
      }
      else {
        _x_x2339 = true; /*bool*/
      }
      if (_x_x2339) {
        kk_std_core_sslice__sslice rest = kk_std_core_sslice__sslice_unbox(_box_x610, KK_BORROWED, _ctx);
        kk_std_core_sslice__sslice_dup(rest, _ctx);
        kk_std_core_types__maybe_drop(_match_x1878, _ctx);
        kk_box_t _x_x2340;
        kk_std_core_types__tuple2 _x_x2341 = kk_std_core_types__new_Tuple2(kk_char_box(c, _ctx), kk_std_core_sslice__sslice_box(rest, _ctx), _ctx); /*(134, 135)*/
        _x_x2340 = kk_std_core_types__tuple2_box(_x_x2341, _ctx); /*88*/
        _x_x2336 = kk_std_core_types__new_Just(_x_x2340, _ctx); /*maybe<88>*/
        goto _match_x2338;
      }
    }
  }
  {
    kk_std_core_types__maybe_drop(_match_x1878, _ctx);
    _x_x2336 = kk_std_core_types__new_Nothing(_ctx); /*maybe<88>*/
  }
  _match_x2338: ;
  return kk_std_core_types__maybe_box(_x_x2336, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_no_digit_fun2343__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_no_digit_fun2343(kk_function_t _fself, kk_box_t _b_x619, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_no_digit_fun2343(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_no_digit_fun2343, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_text_parse_no_digit_fun2343(kk_function_t _fself, kk_box_t _b_x619, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t _x_x2344;
  kk_std_core_types__maybe _x_x2345 = kk_std_core_types__maybe_unbox(_b_x619, KK_OWNED, _ctx); /*maybe<char>*/
  _x_x2344 = kk_std_text_parse__mlift_no_digit_10566(_x_x2345, _ctx); /*char*/
  return kk_char_box(_x_x2344, _ctx);
}

kk_char_t kk_std_text_parse_no_digit(kk_context_t* _ctx) { /* () -> parse char */ 
  kk_std_core_hnd__ev ev_10774 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
  kk_std_core_types__maybe x_10771;
  kk_box_t _x_x2332;
  {
    struct kk_std_core_hnd_Ev* _con_x2333 = kk_std_core_hnd__as_Ev(ev_10774, _ctx);
    kk_box_t _box_x594 = _con_x2333->hnd;
    int32_t m = _con_x2333->marker;
    kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x594, KK_BORROWED, _ctx);
    kk_std_text_parse__parse_dup(h, _ctx);
    {
      struct kk_std_text_parse__Hnd_parse* _con_x2334 = kk_std_text_parse__as_Hnd_parse(h, _ctx);
      kk_integer_t _pat_0 = _con_x2334->_cfc;
      kk_std_core_hnd__clause0 _pat_1_1 = _con_x2334->_fun_current_input;
      kk_std_core_hnd__clause1 _pat_2 = _con_x2334->_brk_fail;
      kk_std_core_hnd__clause0 _pat_3 = _con_x2334->_ctl_pick;
      kk_std_core_hnd__clause1 _fun_satisfy = _con_x2334->_fun_satisfy;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause0_drop(_pat_3, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_2, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_1_1, _ctx);
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_fun_satisfy, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x601 = _fun_satisfy.clause;
        _x_x2332 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x601, (_fun_unbox_x601, m, ev_10774, kk_function_box(kk_std_text_parse_new_no_digit_fun2335(_ctx), _ctx), _ctx), _ctx); /*46*/
      }
    }
  }
  x_10771 = kk_std_core_types__maybe_unbox(_x_x2332, KK_OWNED, _ctx); /*maybe<char>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__maybe_drop(x_10771, _ctx);
    kk_box_t _x_x2342 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_no_digit_fun2343(_ctx), _ctx); /*2419*/
    return kk_char_unbox(_x_x2342, KK_OWNED, _ctx);
  }
  if (kk_std_core_types__is_Nothing(x_10771, _ctx)) {
    kk_std_core_hnd__ev ev_0_10777 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
    kk_box_t _x_x2346;
    {
      struct kk_std_core_hnd_Ev* _con_x2347 = kk_std_core_hnd__as_Ev(ev_0_10777, _ctx);
      kk_box_t _box_x620 = _con_x2347->hnd;
      int32_t m_0 = _con_x2347->marker;
      kk_std_text_parse__parse h_0 = kk_std_text_parse__parse_unbox(_box_x620, KK_BORROWED, _ctx);
      kk_std_text_parse__parse_dup(h_0, _ctx);
      {
        struct kk_std_text_parse__Hnd_parse* _con_x2348 = kk_std_text_parse__as_Hnd_parse(h_0, _ctx);
        kk_integer_t _pat_0_4 = _con_x2348->_cfc;
        kk_std_core_hnd__clause0 _pat_1_3 = _con_x2348->_fun_current_input;
        kk_std_core_hnd__clause1 _brk_fail = _con_x2348->_brk_fail;
        kk_std_core_hnd__clause0 _pat_2_1 = _con_x2348->_ctl_pick;
        kk_std_core_hnd__clause1 _pat_3_1 = _con_x2348->_fun_satisfy;
        if kk_likely(kk_datatype_ptr_is_unique(h_0, _ctx)) {
          kk_std_core_hnd__clause1_drop(_pat_3_1, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_2_1, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_1_3, _ctx);
          kk_integer_drop(_pat_0_4, _ctx);
          kk_datatype_ptr_free(h_0, _ctx);
        }
        else {
          kk_std_core_hnd__clause1_dup(_brk_fail, _ctx);
          kk_datatype_ptr_decref(h_0, _ctx);
        }
        {
          kk_function_t _fun_unbox_x624 = _brk_fail.clause;
          kk_box_t _x_x2349;
          kk_string_t _x_x2350;
          kk_define_string_literal(static, _s_x2351, 11, "not a digit", _ctx)
          _x_x2350 = kk_string_dup(_s_x2351, _ctx); /*string*/
          _x_x2349 = kk_string_box(_x_x2350); /*45*/
          _x_x2346 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x624, (_fun_unbox_x624, m_0, ev_0_10777, _x_x2349, _ctx), _ctx); /*46*/
        }
      }
    }
    return kk_char_unbox(_x_x2346, KK_OWNED, _ctx);
  }
  {
    kk_box_t _box_x628 = x_10771._cons.Just.value;
    kk_char_t x_2 = kk_char_unbox(_box_x628, KK_BORROWED, _ctx);
    kk_std_core_types__maybe_drop(x_10771, _ctx);
    return x_2;
  }
}
 
// monadic lift

kk_integer_t kk_std_text_parse__mlift_digit_10567(kk_char_t _c_x10436, kk_context_t* _ctx) { /* (char) -> int */ 
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
  kk_integer_t x_10002 = kk_integer_from_int(_c_x10436,kk_context()); /*int*/;
  kk_integer_t y_10003 = kk_integer_from_int(('0'),kk_context()); /*int*/;
  kk_char_t x;
  kk_integer_t _x_x2352 = kk_integer_sub(x_10002,y_10003,kk_context()); /*int*/
  x = kk_integer_clamp32(_x_x2352,kk_context()); /*char*/
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  return kk_integer_from_int(x,kk_context());
}
 
// monadic lift


// lift anonymous function
struct kk_std_text_parse__mlift_digit_10568_fun2360__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse__mlift_digit_10568_fun2360(kk_function_t _fself, kk_box_t _b_x640, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse__new_mlift_digit_10568_fun2360(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse__mlift_digit_10568_fun2360, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_text_parse__mlift_digit_10568_fun2360(kk_function_t _fself, kk_box_t _b_x640, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x2361;
  kk_char_t _x_x2362 = kk_char_unbox(_b_x640, KK_OWNED, _ctx); /*char*/
  _x_x2361 = kk_std_text_parse__mlift_digit_10567(_x_x2362, _ctx); /*int*/
  return kk_integer_box(_x_x2361, _ctx);
}

kk_integer_t kk_std_text_parse__mlift_digit_10568(kk_std_core_types__maybe _y_x10434, kk_context_t* _ctx) { /* (maybe<char>) -> parse int */ 
  kk_char_t x_10783;
  if (kk_std_core_types__is_Nothing(_y_x10434, _ctx)) {
    kk_std_core_hnd__ev ev_10785 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
    kk_box_t _x_x2353;
    {
      struct kk_std_core_hnd_Ev* _con_x2354 = kk_std_core_hnd__as_Ev(ev_10785, _ctx);
      kk_box_t _box_x630 = _con_x2354->hnd;
      int32_t m = _con_x2354->marker;
      kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x630, KK_BORROWED, _ctx);
      kk_std_text_parse__parse_dup(h, _ctx);
      {
        struct kk_std_text_parse__Hnd_parse* _con_x2355 = kk_std_text_parse__as_Hnd_parse(h, _ctx);
        kk_integer_t _pat_0 = _con_x2355->_cfc;
        kk_std_core_hnd__clause0 _pat_1_1 = _con_x2355->_fun_current_input;
        kk_std_core_hnd__clause1 _brk_fail = _con_x2355->_brk_fail;
        kk_std_core_hnd__clause0 _pat_2_0 = _con_x2355->_ctl_pick;
        kk_std_core_hnd__clause1 _pat_3 = _con_x2355->_fun_satisfy;
        if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
          kk_std_core_hnd__clause1_drop(_pat_3, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_2_0, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_1_1, _ctx);
          kk_integer_drop(_pat_0, _ctx);
          kk_datatype_ptr_free(h, _ctx);
        }
        else {
          kk_std_core_hnd__clause1_dup(_brk_fail, _ctx);
          kk_datatype_ptr_decref(h, _ctx);
        }
        {
          kk_function_t _fun_unbox_x634 = _brk_fail.clause;
          kk_box_t _x_x2356;
          kk_string_t _x_x2357;
          kk_define_string_literal(static, _s_x2358, 5, "digit", _ctx)
          _x_x2357 = kk_string_dup(_s_x2358, _ctx); /*string*/
          _x_x2356 = kk_string_box(_x_x2357); /*45*/
          _x_x2353 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x634, (_fun_unbox_x634, m, ev_10785, _x_x2356, _ctx), _ctx); /*46*/
        }
      }
    }
    x_10783 = kk_char_unbox(_x_x2353, KK_OWNED, _ctx); /*char*/
  }
  else {
    kk_box_t _box_x638 = _y_x10434._cons.Just.value;
    kk_char_t x_1 = kk_char_unbox(_box_x638, KK_BORROWED, _ctx);
    kk_std_core_types__maybe_drop(_y_x10434, _ctx);
    x_10783 = x_1; /*char*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2359 = kk_std_core_hnd_yield_extend(kk_std_text_parse__new_mlift_digit_10568_fun2360(_ctx), _ctx); /*2419*/
    return kk_integer_unbox(_x_x2359, _ctx);
  }
  {
    return kk_std_text_parse__mlift_digit_10567(x_10783, _ctx);
  }
}


// lift anonymous function
struct kk_std_text_parse_digit_fun2366__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_digit_fun2366(kk_function_t _fself, kk_box_t _b_x655, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_digit_fun2366(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_digit_fun2366, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_text_parse_digit_fun2366(kk_function_t _fself, kk_box_t _b_x655, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__maybe _x_x2367;
  kk_std_core_types__maybe _match_x1874;
  kk_std_core_sslice__sslice _x_x2368 = kk_std_core_sslice__sslice_unbox(_b_x655, KK_OWNED, _ctx); /*sslice/sslice*/
  _match_x1874 = kk_std_core_sslice_next(_x_x2368, _ctx); /*maybe<(char, sslice/sslice)>*/
  if (kk_std_core_types__is_Just(_match_x1874, _ctx)) {
    kk_box_t _box_x656 = _match_x1874._cons.Just.value;
    kk_std_core_types__tuple2 _pat_0_0_0 = kk_std_core_types__tuple2_unbox(_box_x656, KK_BORROWED, _ctx);
    if (kk_std_core_types__is_Tuple2(_pat_0_0_0, _ctx)) {
      kk_box_t _box_x657 = _pat_0_0_0.fst;
      kk_box_t _box_x658 = _pat_0_0_0.snd;
      kk_char_t c = kk_char_unbox(_box_x657, KK_BORROWED, _ctx);
      bool _match_x1875 = (c >= ('0')); /*bool*/;
      bool _x_x2370;
      if (_match_x1875) {
        _x_x2370 = (c <= ('9')); /*bool*/
      }
      else {
        _x_x2370 = false; /*bool*/
      }
      if (_x_x2370) {
        kk_std_core_sslice__sslice rest = kk_std_core_sslice__sslice_unbox(_box_x658, KK_BORROWED, _ctx);
        kk_std_core_sslice__sslice_dup(rest, _ctx);
        kk_std_core_types__maybe_drop(_match_x1874, _ctx);
        kk_box_t _x_x2371;
        kk_std_core_types__tuple2 _x_x2372 = kk_std_core_types__new_Tuple2(kk_char_box(c, _ctx), kk_std_core_sslice__sslice_box(rest, _ctx), _ctx); /*(134, 135)*/
        _x_x2371 = kk_std_core_types__tuple2_box(_x_x2372, _ctx); /*88*/
        _x_x2367 = kk_std_core_types__new_Just(_x_x2371, _ctx); /*maybe<88>*/
        goto _match_x2369;
      }
    }
  }
  {
    kk_std_core_types__maybe_drop(_match_x1874, _ctx);
    _x_x2367 = kk_std_core_types__new_Nothing(_ctx); /*maybe<88>*/
  }
  _match_x2369: ;
  return kk_std_core_types__maybe_box(_x_x2367, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_digit_fun2374__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_digit_fun2374(kk_function_t _fself, kk_box_t _b_x667, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_digit_fun2374(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_digit_fun2374, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_text_parse_digit_fun2374(kk_function_t _fself, kk_box_t _b_x667, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x2375;
  kk_std_core_types__maybe _x_x2376 = kk_std_core_types__maybe_unbox(_b_x667, KK_OWNED, _ctx); /*maybe<char>*/
  _x_x2375 = kk_std_text_parse__mlift_digit_10568(_x_x2376, _ctx); /*int*/
  return kk_integer_box(_x_x2375, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_digit_fun2384__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_digit_fun2384(kk_function_t _fself, kk_box_t _b_x678, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_digit_fun2384(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_digit_fun2384, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_text_parse_digit_fun2384(kk_function_t _fself, kk_box_t _b_x678, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x2385;
  kk_char_t _x_x2386 = kk_char_unbox(_b_x678, KK_OWNED, _ctx); /*char*/
  _x_x2385 = kk_std_text_parse__mlift_digit_10567(_x_x2386, _ctx); /*int*/
  return kk_integer_box(_x_x2385, _ctx);
}

kk_integer_t kk_std_text_parse_digit(kk_context_t* _ctx) { /* () -> parse int */ 
  kk_std_core_hnd__ev ev_10791 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
  kk_std_core_types__maybe x_10788;
  kk_box_t _x_x2363;
  {
    struct kk_std_core_hnd_Ev* _con_x2364 = kk_std_core_hnd__as_Ev(ev_10791, _ctx);
    kk_box_t _box_x642 = _con_x2364->hnd;
    int32_t m = _con_x2364->marker;
    kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x642, KK_BORROWED, _ctx);
    kk_std_text_parse__parse_dup(h, _ctx);
    {
      struct kk_std_text_parse__Hnd_parse* _con_x2365 = kk_std_text_parse__as_Hnd_parse(h, _ctx);
      kk_integer_t _pat_0 = _con_x2365->_cfc;
      kk_std_core_hnd__clause0 _pat_1_1 = _con_x2365->_fun_current_input;
      kk_std_core_hnd__clause1 _pat_2 = _con_x2365->_brk_fail;
      kk_std_core_hnd__clause0 _pat_3 = _con_x2365->_ctl_pick;
      kk_std_core_hnd__clause1 _fun_satisfy = _con_x2365->_fun_satisfy;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause0_drop(_pat_3, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_2, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_1_1, _ctx);
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_fun_satisfy, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x649 = _fun_satisfy.clause;
        _x_x2363 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x649, (_fun_unbox_x649, m, ev_10791, kk_function_box(kk_std_text_parse_new_digit_fun2366(_ctx), _ctx), _ctx), _ctx); /*46*/
      }
    }
  }
  x_10788 = kk_std_core_types__maybe_unbox(_x_x2363, KK_OWNED, _ctx); /*maybe<char>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__maybe_drop(x_10788, _ctx);
    kk_box_t _x_x2373 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_digit_fun2374(_ctx), _ctx); /*2419*/
    return kk_integer_unbox(_x_x2373, _ctx);
  }
  {
    kk_char_t x_1_10794;
    if (kk_std_core_types__is_Nothing(x_10788, _ctx)) {
      kk_std_core_hnd__ev ev_0_10797 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
      kk_box_t _x_x2377;
      {
        struct kk_std_core_hnd_Ev* _con_x2378 = kk_std_core_hnd__as_Ev(ev_0_10797, _ctx);
        kk_box_t _box_x668 = _con_x2378->hnd;
        int32_t m_0 = _con_x2378->marker;
        kk_std_text_parse__parse h_0 = kk_std_text_parse__parse_unbox(_box_x668, KK_BORROWED, _ctx);
        kk_std_text_parse__parse_dup(h_0, _ctx);
        {
          struct kk_std_text_parse__Hnd_parse* _con_x2379 = kk_std_text_parse__as_Hnd_parse(h_0, _ctx);
          kk_integer_t _pat_0_4 = _con_x2379->_cfc;
          kk_std_core_hnd__clause0 _pat_1_3 = _con_x2379->_fun_current_input;
          kk_std_core_hnd__clause1 _brk_fail = _con_x2379->_brk_fail;
          kk_std_core_hnd__clause0 _pat_2_1 = _con_x2379->_ctl_pick;
          kk_std_core_hnd__clause1 _pat_3_1 = _con_x2379->_fun_satisfy;
          if kk_likely(kk_datatype_ptr_is_unique(h_0, _ctx)) {
            kk_std_core_hnd__clause1_drop(_pat_3_1, _ctx);
            kk_std_core_hnd__clause0_drop(_pat_2_1, _ctx);
            kk_std_core_hnd__clause0_drop(_pat_1_3, _ctx);
            kk_integer_drop(_pat_0_4, _ctx);
            kk_datatype_ptr_free(h_0, _ctx);
          }
          else {
            kk_std_core_hnd__clause1_dup(_brk_fail, _ctx);
            kk_datatype_ptr_decref(h_0, _ctx);
          }
          {
            kk_function_t _fun_unbox_x672 = _brk_fail.clause;
            kk_box_t _x_x2380;
            kk_string_t _x_x2381;
            kk_define_string_literal(static, _s_x2382, 5, "digit", _ctx)
            _x_x2381 = kk_string_dup(_s_x2382, _ctx); /*string*/
            _x_x2380 = kk_string_box(_x_x2381); /*45*/
            _x_x2377 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x672, (_fun_unbox_x672, m_0, ev_0_10797, _x_x2380, _ctx), _ctx); /*46*/
          }
        }
      }
      x_1_10794 = kk_char_unbox(_x_x2377, KK_OWNED, _ctx); /*char*/
    }
    else {
      kk_box_t _box_x676 = x_10788._cons.Just.value;
      kk_char_t x_3 = kk_char_unbox(_box_x676, KK_BORROWED, _ctx);
      kk_std_core_types__maybe_drop(x_10788, _ctx);
      x_1_10794 = x_3; /*char*/
    }
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x2383 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_digit_fun2384(_ctx), _ctx); /*2419*/
      return kk_integer_unbox(_x_x2383, _ctx);
    }
    {
      kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
      kk_integer_t x_10002 = kk_integer_from_int(x_1_10794,kk_context()); /*int*/;
      kk_integer_t y_10003 = kk_integer_from_int(('0'),kk_context()); /*int*/;
      kk_char_t x_4;
      kk_integer_t _x_x2387 = kk_integer_sub(x_10002,y_10003,kk_context()); /*int*/
      x_4 = kk_integer_clamp32(_x_x2387,kk_context()); /*char*/
      kk_unit_t keep = kk_Unit;
      kk_evv_set(w,kk_context());
      return kk_integer_from_int(x_4,kk_context());
    }
  }
}
 
// monadic lift

kk_char_t kk_std_text_parse__mlift_alpha_10569(kk_std_core_types__maybe _y_x10437, kk_context_t* _ctx) { /* (maybe<char>) -> parse char */ 
  if (kk_std_core_types__is_Nothing(_y_x10437, _ctx)) {
    kk_std_core_hnd__ev ev_10803 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
    kk_box_t _x_x2388;
    {
      struct kk_std_core_hnd_Ev* _con_x2389 = kk_std_core_hnd__as_Ev(ev_10803, _ctx);
      kk_box_t _box_x681 = _con_x2389->hnd;
      int32_t m = _con_x2389->marker;
      kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x681, KK_BORROWED, _ctx);
      kk_std_text_parse__parse_dup(h, _ctx);
      {
        struct kk_std_text_parse__Hnd_parse* _con_x2390 = kk_std_text_parse__as_Hnd_parse(h, _ctx);
        kk_integer_t _pat_0_1 = _con_x2390->_cfc;
        kk_std_core_hnd__clause0 _pat_1_0 = _con_x2390->_fun_current_input;
        kk_std_core_hnd__clause1 _brk_fail = _con_x2390->_brk_fail;
        kk_std_core_hnd__clause0 _pat_2_0 = _con_x2390->_ctl_pick;
        kk_std_core_hnd__clause1 _pat_3 = _con_x2390->_fun_satisfy;
        if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
          kk_std_core_hnd__clause1_drop(_pat_3, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_2_0, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_1_0, _ctx);
          kk_integer_drop(_pat_0_1, _ctx);
          kk_datatype_ptr_free(h, _ctx);
        }
        else {
          kk_std_core_hnd__clause1_dup(_brk_fail, _ctx);
          kk_datatype_ptr_decref(h, _ctx);
        }
        {
          kk_function_t _fun_unbox_x685 = _brk_fail.clause;
          kk_box_t _x_x2391;
          kk_string_t _x_x2392;
          kk_define_string_literal(static, _s_x2393, 5, "alpha", _ctx)
          _x_x2392 = kk_string_dup(_s_x2393, _ctx); /*string*/
          _x_x2391 = kk_string_box(_x_x2392); /*45*/
          _x_x2388 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x685, (_fun_unbox_x685, m, ev_10803, _x_x2391, _ctx), _ctx); /*46*/
        }
      }
    }
    return kk_char_unbox(_x_x2388, KK_OWNED, _ctx);
  }
  {
    kk_box_t _box_x689 = _y_x10437._cons.Just.value;
    kk_char_t x_0 = kk_char_unbox(_box_x689, KK_BORROWED, _ctx);
    kk_std_core_types__maybe_drop(_y_x10437, _ctx);
    return x_0;
  }
}


// lift anonymous function
struct kk_std_text_parse_alpha_fun2397__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_alpha_fun2397(kk_function_t _fself, kk_box_t _b_x703, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_alpha_fun2397(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_alpha_fun2397, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_text_parse_alpha_fun2397(kk_function_t _fself, kk_box_t _b_x703, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__maybe _x_x2398;
  kk_std_core_types__maybe _match_x1871;
  kk_std_core_sslice__sslice _x_x2399 = kk_std_core_sslice__sslice_unbox(_b_x703, KK_OWNED, _ctx); /*sslice/sslice*/
  _match_x1871 = kk_std_core_sslice_next(_x_x2399, _ctx); /*maybe<(char, sslice/sslice)>*/
  if (kk_std_core_types__is_Just(_match_x1871, _ctx)) {
    kk_box_t _box_x704 = _match_x1871._cons.Just.value;
    kk_std_core_types__tuple2 _pat_0_0_0 = kk_std_core_types__tuple2_unbox(_box_x704, KK_BORROWED, _ctx);
    if (kk_std_core_types__is_Tuple2(_pat_0_0_0, _ctx)) {
      kk_box_t _box_x705 = _pat_0_0_0.fst;
      kk_box_t _box_x706 = _pat_0_0_0.snd;
      kk_char_t c = kk_char_unbox(_box_x705, KK_BORROWED, _ctx);
      if (kk_std_core_char_is_alpha(c, _ctx)) {
        kk_std_core_sslice__sslice rest = kk_std_core_sslice__sslice_unbox(_box_x706, KK_BORROWED, _ctx);
        kk_std_core_sslice__sslice_dup(rest, _ctx);
        kk_std_core_types__maybe_drop(_match_x1871, _ctx);
        kk_box_t _x_x2401;
        kk_std_core_types__tuple2 _x_x2402 = kk_std_core_types__new_Tuple2(kk_char_box(c, _ctx), kk_std_core_sslice__sslice_box(rest, _ctx), _ctx); /*(134, 135)*/
        _x_x2401 = kk_std_core_types__tuple2_box(_x_x2402, _ctx); /*88*/
        _x_x2398 = kk_std_core_types__new_Just(_x_x2401, _ctx); /*maybe<88>*/
        goto _match_x2400;
      }
    }
  }
  {
    kk_std_core_types__maybe_drop(_match_x1871, _ctx);
    _x_x2398 = kk_std_core_types__new_Nothing(_ctx); /*maybe<88>*/
  }
  _match_x2400: ;
  return kk_std_core_types__maybe_box(_x_x2398, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_alpha_fun2404__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_alpha_fun2404(kk_function_t _fself, kk_box_t _b_x715, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_alpha_fun2404(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_alpha_fun2404, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_text_parse_alpha_fun2404(kk_function_t _fself, kk_box_t _b_x715, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t _x_x2405;
  kk_std_core_types__maybe _x_x2406 = kk_std_core_types__maybe_unbox(_b_x715, KK_OWNED, _ctx); /*maybe<char>*/
  _x_x2405 = kk_std_text_parse__mlift_alpha_10569(_x_x2406, _ctx); /*char*/
  return kk_char_box(_x_x2405, _ctx);
}

kk_char_t kk_std_text_parse_alpha(kk_context_t* _ctx) { /* () -> parse char */ 
  kk_std_core_hnd__ev ev_10809 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
  kk_std_core_types__maybe x_10806;
  kk_box_t _x_x2394;
  {
    struct kk_std_core_hnd_Ev* _con_x2395 = kk_std_core_hnd__as_Ev(ev_10809, _ctx);
    kk_box_t _box_x690 = _con_x2395->hnd;
    int32_t m = _con_x2395->marker;
    kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x690, KK_BORROWED, _ctx);
    kk_std_text_parse__parse_dup(h, _ctx);
    {
      struct kk_std_text_parse__Hnd_parse* _con_x2396 = kk_std_text_parse__as_Hnd_parse(h, _ctx);
      kk_integer_t _pat_0 = _con_x2396->_cfc;
      kk_std_core_hnd__clause0 _pat_1_1 = _con_x2396->_fun_current_input;
      kk_std_core_hnd__clause1 _pat_2 = _con_x2396->_brk_fail;
      kk_std_core_hnd__clause0 _pat_3 = _con_x2396->_ctl_pick;
      kk_std_core_hnd__clause1 _fun_satisfy = _con_x2396->_fun_satisfy;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause0_drop(_pat_3, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_2, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_1_1, _ctx);
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_fun_satisfy, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x697 = _fun_satisfy.clause;
        _x_x2394 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x697, (_fun_unbox_x697, m, ev_10809, kk_function_box(kk_std_text_parse_new_alpha_fun2397(_ctx), _ctx), _ctx), _ctx); /*46*/
      }
    }
  }
  x_10806 = kk_std_core_types__maybe_unbox(_x_x2394, KK_OWNED, _ctx); /*maybe<char>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__maybe_drop(x_10806, _ctx);
    kk_box_t _x_x2403 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_alpha_fun2404(_ctx), _ctx); /*2419*/
    return kk_char_unbox(_x_x2403, KK_OWNED, _ctx);
  }
  if (kk_std_core_types__is_Nothing(x_10806, _ctx)) {
    kk_std_core_hnd__ev ev_0_10812 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
    kk_box_t _x_x2407;
    {
      struct kk_std_core_hnd_Ev* _con_x2408 = kk_std_core_hnd__as_Ev(ev_0_10812, _ctx);
      kk_box_t _box_x716 = _con_x2408->hnd;
      int32_t m_0 = _con_x2408->marker;
      kk_std_text_parse__parse h_0 = kk_std_text_parse__parse_unbox(_box_x716, KK_BORROWED, _ctx);
      kk_std_text_parse__parse_dup(h_0, _ctx);
      {
        struct kk_std_text_parse__Hnd_parse* _con_x2409 = kk_std_text_parse__as_Hnd_parse(h_0, _ctx);
        kk_integer_t _pat_0_2 = _con_x2409->_cfc;
        kk_std_core_hnd__clause0 _pat_1_3 = _con_x2409->_fun_current_input;
        kk_std_core_hnd__clause1 _brk_fail = _con_x2409->_brk_fail;
        kk_std_core_hnd__clause0 _pat_2_1 = _con_x2409->_ctl_pick;
        kk_std_core_hnd__clause1 _pat_3_1 = _con_x2409->_fun_satisfy;
        if kk_likely(kk_datatype_ptr_is_unique(h_0, _ctx)) {
          kk_std_core_hnd__clause1_drop(_pat_3_1, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_2_1, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_1_3, _ctx);
          kk_integer_drop(_pat_0_2, _ctx);
          kk_datatype_ptr_free(h_0, _ctx);
        }
        else {
          kk_std_core_hnd__clause1_dup(_brk_fail, _ctx);
          kk_datatype_ptr_decref(h_0, _ctx);
        }
        {
          kk_function_t _fun_unbox_x720 = _brk_fail.clause;
          kk_box_t _x_x2410;
          kk_string_t _x_x2411;
          kk_define_string_literal(static, _s_x2412, 5, "alpha", _ctx)
          _x_x2411 = kk_string_dup(_s_x2412, _ctx); /*string*/
          _x_x2410 = kk_string_box(_x_x2411); /*45*/
          _x_x2407 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x720, (_fun_unbox_x720, m_0, ev_0_10812, _x_x2410, _ctx), _ctx); /*46*/
        }
      }
    }
    return kk_char_unbox(_x_x2407, KK_OWNED, _ctx);
  }
  {
    kk_box_t _box_x724 = x_10806._cons.Just.value;
    kk_char_t x_2 = kk_char_unbox(_box_x724, KK_BORROWED, _ctx);
    kk_std_core_types__maybe_drop(x_10806, _ctx);
    return x_2;
  }
}
 
// monadic lift

kk_char_t kk_std_text_parse__mlift_alpha_num_10570(kk_std_core_types__maybe _y_x10440, kk_context_t* _ctx) { /* (maybe<char>) -> parse char */ 
  if (kk_std_core_types__is_Nothing(_y_x10440, _ctx)) {
    kk_std_core_hnd__ev ev_10815 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
    kk_box_t _x_x2413;
    {
      struct kk_std_core_hnd_Ev* _con_x2414 = kk_std_core_hnd__as_Ev(ev_10815, _ctx);
      kk_box_t _box_x726 = _con_x2414->hnd;
      int32_t m = _con_x2414->marker;
      kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x726, KK_BORROWED, _ctx);
      kk_std_text_parse__parse_dup(h, _ctx);
      {
        struct kk_std_text_parse__Hnd_parse* _con_x2415 = kk_std_text_parse__as_Hnd_parse(h, _ctx);
        kk_integer_t _pat_0_1 = _con_x2415->_cfc;
        kk_std_core_hnd__clause0 _pat_1_0 = _con_x2415->_fun_current_input;
        kk_std_core_hnd__clause1 _brk_fail = _con_x2415->_brk_fail;
        kk_std_core_hnd__clause0 _pat_2_0 = _con_x2415->_ctl_pick;
        kk_std_core_hnd__clause1 _pat_3 = _con_x2415->_fun_satisfy;
        if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
          kk_std_core_hnd__clause1_drop(_pat_3, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_2_0, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_1_0, _ctx);
          kk_integer_drop(_pat_0_1, _ctx);
          kk_datatype_ptr_free(h, _ctx);
        }
        else {
          kk_std_core_hnd__clause1_dup(_brk_fail, _ctx);
          kk_datatype_ptr_decref(h, _ctx);
        }
        {
          kk_function_t _fun_unbox_x730 = _brk_fail.clause;
          kk_box_t _x_x2416;
          kk_string_t _x_x2417;
          kk_define_string_literal(static, _s_x2418, 9, "alpha-num", _ctx)
          _x_x2417 = kk_string_dup(_s_x2418, _ctx); /*string*/
          _x_x2416 = kk_string_box(_x_x2417); /*45*/
          _x_x2413 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x730, (_fun_unbox_x730, m, ev_10815, _x_x2416, _ctx), _ctx); /*46*/
        }
      }
    }
    return kk_char_unbox(_x_x2413, KK_OWNED, _ctx);
  }
  {
    kk_box_t _box_x734 = _y_x10440._cons.Just.value;
    kk_char_t x_0 = kk_char_unbox(_box_x734, KK_BORROWED, _ctx);
    kk_std_core_types__maybe_drop(_y_x10440, _ctx);
    return x_0;
  }
}


// lift anonymous function
struct kk_std_text_parse_alpha_num_fun2422__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_alpha_num_fun2422(kk_function_t _fself, kk_box_t _b_x748, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_alpha_num_fun2422(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_alpha_num_fun2422, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_text_parse_alpha_num_fun2422(kk_function_t _fself, kk_box_t _b_x748, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__maybe _x_x2423;
  kk_std_core_types__maybe _match_x1869;
  kk_std_core_sslice__sslice _x_x2424 = kk_std_core_sslice__sslice_unbox(_b_x748, KK_OWNED, _ctx); /*sslice/sslice*/
  _match_x1869 = kk_std_core_sslice_next(_x_x2424, _ctx); /*maybe<(char, sslice/sslice)>*/
  if (kk_std_core_types__is_Just(_match_x1869, _ctx)) {
    kk_box_t _box_x749 = _match_x1869._cons.Just.value;
    kk_std_core_types__tuple2 _pat_0_0_0 = kk_std_core_types__tuple2_unbox(_box_x749, KK_BORROWED, _ctx);
    if (kk_std_core_types__is_Tuple2(_pat_0_0_0, _ctx)) {
      kk_box_t _box_x750 = _pat_0_0_0.fst;
      kk_box_t _box_x751 = _pat_0_0_0.snd;
      kk_char_t c = kk_char_unbox(_box_x750, KK_BORROWED, _ctx);
      if (kk_std_core_char_is_alpha_num(c, _ctx)) {
        kk_std_core_sslice__sslice rest = kk_std_core_sslice__sslice_unbox(_box_x751, KK_BORROWED, _ctx);
        kk_std_core_sslice__sslice_dup(rest, _ctx);
        kk_std_core_types__maybe_drop(_match_x1869, _ctx);
        kk_box_t _x_x2426;
        kk_std_core_types__tuple2 _x_x2427 = kk_std_core_types__new_Tuple2(kk_char_box(c, _ctx), kk_std_core_sslice__sslice_box(rest, _ctx), _ctx); /*(134, 135)*/
        _x_x2426 = kk_std_core_types__tuple2_box(_x_x2427, _ctx); /*88*/
        _x_x2423 = kk_std_core_types__new_Just(_x_x2426, _ctx); /*maybe<88>*/
        goto _match_x2425;
      }
    }
  }
  {
    kk_std_core_types__maybe_drop(_match_x1869, _ctx);
    _x_x2423 = kk_std_core_types__new_Nothing(_ctx); /*maybe<88>*/
  }
  _match_x2425: ;
  return kk_std_core_types__maybe_box(_x_x2423, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_alpha_num_fun2429__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_alpha_num_fun2429(kk_function_t _fself, kk_box_t _b_x760, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_alpha_num_fun2429(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_alpha_num_fun2429, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_text_parse_alpha_num_fun2429(kk_function_t _fself, kk_box_t _b_x760, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t _x_x2430;
  kk_std_core_types__maybe _x_x2431 = kk_std_core_types__maybe_unbox(_b_x760, KK_OWNED, _ctx); /*maybe<char>*/
  _x_x2430 = kk_std_text_parse__mlift_alpha_num_10570(_x_x2431, _ctx); /*char*/
  return kk_char_box(_x_x2430, _ctx);
}

kk_char_t kk_std_text_parse_alpha_num(kk_context_t* _ctx) { /* () -> parse char */ 
  kk_std_core_hnd__ev ev_10821 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
  kk_std_core_types__maybe x_10818;
  kk_box_t _x_x2419;
  {
    struct kk_std_core_hnd_Ev* _con_x2420 = kk_std_core_hnd__as_Ev(ev_10821, _ctx);
    kk_box_t _box_x735 = _con_x2420->hnd;
    int32_t m = _con_x2420->marker;
    kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x735, KK_BORROWED, _ctx);
    kk_std_text_parse__parse_dup(h, _ctx);
    {
      struct kk_std_text_parse__Hnd_parse* _con_x2421 = kk_std_text_parse__as_Hnd_parse(h, _ctx);
      kk_integer_t _pat_0 = _con_x2421->_cfc;
      kk_std_core_hnd__clause0 _pat_1_1 = _con_x2421->_fun_current_input;
      kk_std_core_hnd__clause1 _pat_2 = _con_x2421->_brk_fail;
      kk_std_core_hnd__clause0 _pat_3 = _con_x2421->_ctl_pick;
      kk_std_core_hnd__clause1 _fun_satisfy = _con_x2421->_fun_satisfy;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause0_drop(_pat_3, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_2, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_1_1, _ctx);
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_fun_satisfy, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x742 = _fun_satisfy.clause;
        _x_x2419 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x742, (_fun_unbox_x742, m, ev_10821, kk_function_box(kk_std_text_parse_new_alpha_num_fun2422(_ctx), _ctx), _ctx), _ctx); /*46*/
      }
    }
  }
  x_10818 = kk_std_core_types__maybe_unbox(_x_x2419, KK_OWNED, _ctx); /*maybe<char>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__maybe_drop(x_10818, _ctx);
    kk_box_t _x_x2428 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_alpha_num_fun2429(_ctx), _ctx); /*2419*/
    return kk_char_unbox(_x_x2428, KK_OWNED, _ctx);
  }
  if (kk_std_core_types__is_Nothing(x_10818, _ctx)) {
    kk_std_core_hnd__ev ev_0_10824 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
    kk_box_t _x_x2432;
    {
      struct kk_std_core_hnd_Ev* _con_x2433 = kk_std_core_hnd__as_Ev(ev_0_10824, _ctx);
      kk_box_t _box_x761 = _con_x2433->hnd;
      int32_t m_0 = _con_x2433->marker;
      kk_std_text_parse__parse h_0 = kk_std_text_parse__parse_unbox(_box_x761, KK_BORROWED, _ctx);
      kk_std_text_parse__parse_dup(h_0, _ctx);
      {
        struct kk_std_text_parse__Hnd_parse* _con_x2434 = kk_std_text_parse__as_Hnd_parse(h_0, _ctx);
        kk_integer_t _pat_0_2 = _con_x2434->_cfc;
        kk_std_core_hnd__clause0 _pat_1_3 = _con_x2434->_fun_current_input;
        kk_std_core_hnd__clause1 _brk_fail = _con_x2434->_brk_fail;
        kk_std_core_hnd__clause0 _pat_2_1 = _con_x2434->_ctl_pick;
        kk_std_core_hnd__clause1 _pat_3_1 = _con_x2434->_fun_satisfy;
        if kk_likely(kk_datatype_ptr_is_unique(h_0, _ctx)) {
          kk_std_core_hnd__clause1_drop(_pat_3_1, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_2_1, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_1_3, _ctx);
          kk_integer_drop(_pat_0_2, _ctx);
          kk_datatype_ptr_free(h_0, _ctx);
        }
        else {
          kk_std_core_hnd__clause1_dup(_brk_fail, _ctx);
          kk_datatype_ptr_decref(h_0, _ctx);
        }
        {
          kk_function_t _fun_unbox_x765 = _brk_fail.clause;
          kk_box_t _x_x2435;
          kk_string_t _x_x2436;
          kk_define_string_literal(static, _s_x2437, 9, "alpha-num", _ctx)
          _x_x2436 = kk_string_dup(_s_x2437, _ctx); /*string*/
          _x_x2435 = kk_string_box(_x_x2436); /*45*/
          _x_x2432 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x765, (_fun_unbox_x765, m_0, ev_0_10824, _x_x2435, _ctx), _ctx); /*46*/
        }
      }
    }
    return kk_char_unbox(_x_x2432, KK_OWNED, _ctx);
  }
  {
    kk_box_t _box_x769 = x_10818._cons.Just.value;
    kk_char_t x_2 = kk_char_unbox(_box_x769, KK_BORROWED, _ctx);
    kk_std_core_types__maybe_drop(x_10818, _ctx);
    return x_2;
  }
}
 
// monadic lift

kk_char_t kk_std_text_parse__mlift_white_10571(kk_std_core_types__maybe _y_x10443, kk_context_t* _ctx) { /* (maybe<char>) -> parse char */ 
  if (kk_std_core_types__is_Nothing(_y_x10443, _ctx)) {
    kk_std_core_hnd__ev ev_10827 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
    kk_box_t _x_x2438;
    {
      struct kk_std_core_hnd_Ev* _con_x2439 = kk_std_core_hnd__as_Ev(ev_10827, _ctx);
      kk_box_t _box_x771 = _con_x2439->hnd;
      int32_t m = _con_x2439->marker;
      kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x771, KK_BORROWED, _ctx);
      kk_std_text_parse__parse_dup(h, _ctx);
      {
        struct kk_std_text_parse__Hnd_parse* _con_x2440 = kk_std_text_parse__as_Hnd_parse(h, _ctx);
        kk_integer_t _pat_0_1 = _con_x2440->_cfc;
        kk_std_core_hnd__clause0 _pat_1_0 = _con_x2440->_fun_current_input;
        kk_std_core_hnd__clause1 _brk_fail = _con_x2440->_brk_fail;
        kk_std_core_hnd__clause0 _pat_2_0 = _con_x2440->_ctl_pick;
        kk_std_core_hnd__clause1 _pat_3 = _con_x2440->_fun_satisfy;
        if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
          kk_std_core_hnd__clause1_drop(_pat_3, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_2_0, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_1_0, _ctx);
          kk_integer_drop(_pat_0_1, _ctx);
          kk_datatype_ptr_free(h, _ctx);
        }
        else {
          kk_std_core_hnd__clause1_dup(_brk_fail, _ctx);
          kk_datatype_ptr_decref(h, _ctx);
        }
        {
          kk_function_t _fun_unbox_x775 = _brk_fail.clause;
          kk_box_t _x_x2441;
          kk_string_t _x_x2442 = kk_string_empty(); /*string*/
          _x_x2441 = kk_string_box(_x_x2442); /*45*/
          _x_x2438 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x775, (_fun_unbox_x775, m, ev_10827, _x_x2441, _ctx), _ctx); /*46*/
        }
      }
    }
    return kk_char_unbox(_x_x2438, KK_OWNED, _ctx);
  }
  {
    kk_box_t _box_x779 = _y_x10443._cons.Just.value;
    kk_char_t x_0 = kk_char_unbox(_box_x779, KK_BORROWED, _ctx);
    kk_std_core_types__maybe_drop(_y_x10443, _ctx);
    return x_0;
  }
}


// lift anonymous function
struct kk_std_text_parse_white_fun2447__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_white_fun2447(kk_function_t _fself, kk_box_t _b_x793, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_white_fun2447(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_white_fun2447, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_text_parse_white_fun2447(kk_function_t _fself, kk_box_t _b_x793, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__maybe _x_x2448;
  kk_std_core_types__maybe _match_x1867;
  kk_std_core_sslice__sslice _x_x2449 = kk_std_core_sslice__sslice_unbox(_b_x793, KK_OWNED, _ctx); /*sslice/sslice*/
  _match_x1867 = kk_std_core_sslice_next(_x_x2449, _ctx); /*maybe<(char, sslice/sslice)>*/
  if (kk_std_core_types__is_Just(_match_x1867, _ctx)) {
    kk_box_t _box_x794 = _match_x1867._cons.Just.value;
    kk_std_core_types__tuple2 _pat_0_0_0 = kk_std_core_types__tuple2_unbox(_box_x794, KK_BORROWED, _ctx);
    if (kk_std_core_types__is_Tuple2(_pat_0_0_0, _ctx)) {
      kk_box_t _box_x795 = _pat_0_0_0.fst;
      kk_box_t _box_x796 = _pat_0_0_0.snd;
      kk_char_t c = kk_char_unbox(_box_x795, KK_BORROWED, _ctx);
      if (kk_std_core_char_is_white(c, _ctx)) {
        kk_std_core_sslice__sslice rest = kk_std_core_sslice__sslice_unbox(_box_x796, KK_BORROWED, _ctx);
        kk_std_core_sslice__sslice_dup(rest, _ctx);
        kk_std_core_types__maybe_drop(_match_x1867, _ctx);
        kk_box_t _x_x2451;
        kk_std_core_types__tuple2 _x_x2452 = kk_std_core_types__new_Tuple2(kk_char_box(c, _ctx), kk_std_core_sslice__sslice_box(rest, _ctx), _ctx); /*(134, 135)*/
        _x_x2451 = kk_std_core_types__tuple2_box(_x_x2452, _ctx); /*88*/
        _x_x2448 = kk_std_core_types__new_Just(_x_x2451, _ctx); /*maybe<88>*/
        goto _match_x2450;
      }
    }
  }
  {
    kk_std_core_types__maybe_drop(_match_x1867, _ctx);
    _x_x2448 = kk_std_core_types__new_Nothing(_ctx); /*maybe<88>*/
  }
  _match_x2450: ;
  return kk_std_core_types__maybe_box(_x_x2448, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_white_fun2454__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_white_fun2454(kk_function_t _fself, kk_box_t _b_x805, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_white_fun2454(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_white_fun2454, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_text_parse_white_fun2454(kk_function_t _fself, kk_box_t _b_x805, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t _x_x2455;
  kk_std_core_types__maybe _x_x2456 = kk_std_core_types__maybe_unbox(_b_x805, KK_OWNED, _ctx); /*maybe<char>*/
  _x_x2455 = kk_std_text_parse__mlift_white_10571(_x_x2456, _ctx); /*char*/
  return kk_char_box(_x_x2455, _ctx);
}

kk_char_t kk_std_text_parse_white(kk_context_t* _ctx) { /* () -> parse char */ 
  kk_std_core_hnd__ev ev_10833 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
  kk_std_core_types__maybe x_10830;
  kk_box_t _x_x2444;
  {
    struct kk_std_core_hnd_Ev* _con_x2445 = kk_std_core_hnd__as_Ev(ev_10833, _ctx);
    kk_box_t _box_x780 = _con_x2445->hnd;
    int32_t m = _con_x2445->marker;
    kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x780, KK_BORROWED, _ctx);
    kk_std_text_parse__parse_dup(h, _ctx);
    {
      struct kk_std_text_parse__Hnd_parse* _con_x2446 = kk_std_text_parse__as_Hnd_parse(h, _ctx);
      kk_integer_t _pat_0 = _con_x2446->_cfc;
      kk_std_core_hnd__clause0 _pat_1_1 = _con_x2446->_fun_current_input;
      kk_std_core_hnd__clause1 _pat_2 = _con_x2446->_brk_fail;
      kk_std_core_hnd__clause0 _pat_3 = _con_x2446->_ctl_pick;
      kk_std_core_hnd__clause1 _fun_satisfy = _con_x2446->_fun_satisfy;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause0_drop(_pat_3, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_2, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_1_1, _ctx);
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_fun_satisfy, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x787 = _fun_satisfy.clause;
        _x_x2444 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x787, (_fun_unbox_x787, m, ev_10833, kk_function_box(kk_std_text_parse_new_white_fun2447(_ctx), _ctx), _ctx), _ctx); /*46*/
      }
    }
  }
  x_10830 = kk_std_core_types__maybe_unbox(_x_x2444, KK_OWNED, _ctx); /*maybe<char>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__maybe_drop(x_10830, _ctx);
    kk_box_t _x_x2453 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_white_fun2454(_ctx), _ctx); /*2419*/
    return kk_char_unbox(_x_x2453, KK_OWNED, _ctx);
  }
  if (kk_std_core_types__is_Nothing(x_10830, _ctx)) {
    kk_std_core_hnd__ev ev_0_10836 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
    kk_box_t _x_x2457;
    {
      struct kk_std_core_hnd_Ev* _con_x2458 = kk_std_core_hnd__as_Ev(ev_0_10836, _ctx);
      kk_box_t _box_x806 = _con_x2458->hnd;
      int32_t m_0 = _con_x2458->marker;
      kk_std_text_parse__parse h_0 = kk_std_text_parse__parse_unbox(_box_x806, KK_BORROWED, _ctx);
      kk_std_text_parse__parse_dup(h_0, _ctx);
      {
        struct kk_std_text_parse__Hnd_parse* _con_x2459 = kk_std_text_parse__as_Hnd_parse(h_0, _ctx);
        kk_integer_t _pat_0_2 = _con_x2459->_cfc;
        kk_std_core_hnd__clause0 _pat_1_3 = _con_x2459->_fun_current_input;
        kk_std_core_hnd__clause1 _brk_fail = _con_x2459->_brk_fail;
        kk_std_core_hnd__clause0 _pat_2_1 = _con_x2459->_ctl_pick;
        kk_std_core_hnd__clause1 _pat_3_1 = _con_x2459->_fun_satisfy;
        if kk_likely(kk_datatype_ptr_is_unique(h_0, _ctx)) {
          kk_std_core_hnd__clause1_drop(_pat_3_1, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_2_1, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_1_3, _ctx);
          kk_integer_drop(_pat_0_2, _ctx);
          kk_datatype_ptr_free(h_0, _ctx);
        }
        else {
          kk_std_core_hnd__clause1_dup(_brk_fail, _ctx);
          kk_datatype_ptr_decref(h_0, _ctx);
        }
        {
          kk_function_t _fun_unbox_x810 = _brk_fail.clause;
          kk_box_t _x_x2460;
          kk_string_t _x_x2461 = kk_string_empty(); /*string*/
          _x_x2460 = kk_string_box(_x_x2461); /*45*/
          _x_x2457 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x810, (_fun_unbox_x810, m_0, ev_0_10836, _x_x2460, _ctx), _ctx); /*46*/
        }
      }
    }
    return kk_char_unbox(_x_x2457, KK_OWNED, _ctx);
  }
  {
    kk_box_t _box_x814 = x_10830._cons.Just.value;
    kk_char_t x_2 = kk_char_unbox(_box_x814, KK_BORROWED, _ctx);
    kk_std_core_types__maybe_drop(x_10830, _ctx);
    return x_2;
  }
}
 
// lifted local: whitespace, @spec-x10274
// specialized: std/text/parse/next-while0, on parameters @uniq-pred@10265, using:
// @uniq-pred@10265 = std/core/char/is-white

kk_std_core_types__tuple2 kk_std_text_parse__lift_whitespace_10353(kk_std_core_sslice__sslice _uniq_slice_10264, kk_std_core_types__list _uniq_acc_10266, kk_context_t* _ctx) { /* (sslice/sslice, list<char>) -> (list<char>, sslice/sslice) */ 
  kk__tailcall: ;
  kk_std_core_types__maybe _match_x1865;
  kk_std_core_sslice__sslice _x_x2463 = kk_std_core_sslice__sslice_dup(_uniq_slice_10264, _ctx); /*sslice/sslice*/
  _match_x1865 = kk_std_core_sslice_next(_x_x2463, _ctx); /*maybe<(char, sslice/sslice)>*/
  if (kk_std_core_types__is_Just(_match_x1865, _ctx)) {
    kk_box_t _box_x816 = _match_x1865._cons.Just.value;
    kk_std_core_types__tuple2 _uniq_pat_0_10268 = kk_std_core_types__tuple2_unbox(_box_x816, KK_BORROWED, _ctx);
    if (kk_std_core_types__is_Tuple2(_uniq_pat_0_10268, _ctx)) {
      kk_box_t _box_x817 = _uniq_pat_0_10268.fst;
      kk_box_t _box_x818 = _uniq_pat_0_10268.snd;
      kk_char_t _uniq_c_10269 = kk_char_unbox(_box_x817, KK_BORROWED, _ctx);
      if (kk_std_core_char_is_white(_uniq_c_10269, _ctx)) {
        kk_std_core_sslice__sslice _uniq_rest_10270 = kk_std_core_sslice__sslice_unbox(_box_x818, KK_BORROWED, _ctx);
        kk_std_core_sslice__sslice_drop(_uniq_slice_10264, _ctx);
        kk_std_core_sslice__sslice_dup(_uniq_rest_10270, _ctx);
        kk_std_core_types__maybe_drop(_match_x1865, _ctx);
        { // tailcall
          kk_std_core_types__list _x_x2464 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_char_box(_uniq_c_10269, _ctx), _uniq_acc_10266, _ctx); /*list<79>*/
          _uniq_slice_10264 = _uniq_rest_10270;
          _uniq_acc_10266 = _x_x2464;
          goto kk__tailcall;
        }
      }
    }
  }
  {
    kk_std_core_types__maybe_drop(_match_x1865, _ctx);
    kk_std_core_types__list _b_x821_825;
    if (kk_std_core_types__is_Nil(_uniq_acc_10266, _ctx)) {
      _b_x821_825 = kk_std_core_types__new_Nil(_ctx); /*list<char>*/
    }
    else {
      _b_x821_825 = kk_std_core_list__unroll_reverse_acc_10003(kk_std_core_types__new_Nil(_ctx), _uniq_acc_10266, _ctx); /*list<char>*/
    }
    return kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(_b_x821_825, _ctx), kk_std_core_sslice__sslice_box(_uniq_slice_10264, _ctx), _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_text_parse__mlift_whitespace_10572_fun2472__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse__mlift_whitespace_10572_fun2472(kk_function_t _fself, kk_box_t _b_x837, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse__new_mlift_whitespace_10572_fun2472(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse__mlift_whitespace_10572_fun2472, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_text_parse__mlift_whitespace_10572_fun2472(kk_function_t _fself, kk_box_t _b_x837, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2473;
  kk_std_core_types__list _x_x2474 = kk_std_core_types__list_unbox(_b_x837, KK_OWNED, _ctx); /*list<char>*/
  _x_x2473 = kk_std_core_string_listchar_fs_string(_x_x2474, _ctx); /*string*/
  return kk_string_box(_x_x2473);
}

kk_string_t kk_std_text_parse__mlift_whitespace_10572(kk_std_core_types__maybe _y_x10446, kk_context_t* _ctx) { /* (maybe<list<char>>) -> parse string */ 
  kk_std_core_types__list x_10839;
  if (kk_std_core_types__is_Nothing(_y_x10446, _ctx)) {
    kk_std_core_hnd__ev ev_10841 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
    kk_box_t _x_x2465;
    {
      struct kk_std_core_hnd_Ev* _con_x2466 = kk_std_core_hnd__as_Ev(ev_10841, _ctx);
      kk_box_t _box_x827 = _con_x2466->hnd;
      int32_t m = _con_x2466->marker;
      kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x827, KK_BORROWED, _ctx);
      kk_std_text_parse__parse_dup(h, _ctx);
      {
        struct kk_std_text_parse__Hnd_parse* _con_x2467 = kk_std_text_parse__as_Hnd_parse(h, _ctx);
        kk_integer_t _pat_0 = _con_x2467->_cfc;
        kk_std_core_hnd__clause0 _pat_1_1 = _con_x2467->_fun_current_input;
        kk_std_core_hnd__clause1 _brk_fail = _con_x2467->_brk_fail;
        kk_std_core_hnd__clause0 _pat_2_0 = _con_x2467->_ctl_pick;
        kk_std_core_hnd__clause1 _pat_3 = _con_x2467->_fun_satisfy;
        if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
          kk_std_core_hnd__clause1_drop(_pat_3, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_2_0, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_1_1, _ctx);
          kk_integer_drop(_pat_0, _ctx);
          kk_datatype_ptr_free(h, _ctx);
        }
        else {
          kk_std_core_hnd__clause1_dup(_brk_fail, _ctx);
          kk_datatype_ptr_decref(h, _ctx);
        }
        {
          kk_function_t _fun_unbox_x831 = _brk_fail.clause;
          kk_box_t _x_x2468;
          kk_string_t _x_x2469 = kk_string_empty(); /*string*/
          _x_x2468 = kk_string_box(_x_x2469); /*45*/
          _x_x2465 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x831, (_fun_unbox_x831, m, ev_10841, _x_x2468, _ctx), _ctx); /*46*/
        }
      }
    }
    x_10839 = kk_std_core_types__list_unbox(_x_x2465, KK_OWNED, _ctx); /*list<char>*/
  }
  else {
    kk_box_t _box_x835 = _y_x10446._cons.Just.value;
    kk_std_core_types__list x_1 = kk_std_core_types__list_unbox(_box_x835, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(x_1, _ctx);
    kk_std_core_types__maybe_drop(_y_x10446, _ctx);
    x_10839 = x_1; /*list<char>*/
  }
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_10839, _ctx);
    kk_box_t _x_x2471 = kk_std_core_hnd_yield_extend(kk_std_text_parse__new_mlift_whitespace_10572_fun2472(_ctx), _ctx); /*2419*/
    return kk_string_unbox(_x_x2471);
  }
  {
    return kk_std_core_string_listchar_fs_string(x_10839, _ctx);
  }
}


// lift anonymous function
struct kk_std_text_parse_whitespace_fun2478__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_whitespace_fun2478(kk_function_t _fself, kk_box_t _b_x852, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_whitespace_fun2478(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_whitespace_fun2478, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_text_parse_whitespace_fun2478(kk_function_t _fself, kk_box_t _b_x852, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__maybe _x_x2479;
  kk_std_core_types__tuple2 _match_x1863;
  kk_std_core_sslice__sslice _x_x2480 = kk_std_core_sslice__sslice_unbox(_b_x852, KK_OWNED, _ctx); /*sslice/sslice*/
  _match_x1863 = kk_std_text_parse__lift_whitespace_10353(_x_x2480, kk_std_core_types__new_Nil(_ctx), _ctx); /*(list<char>, sslice/sslice)*/
  {
    kk_box_t _box_x853 = _match_x1863.fst;
    kk_box_t _box_x854 = _match_x1863.snd;
    kk_std_core_types__list _pat_0_0_0 = kk_std_core_types__list_unbox(_box_x853, KK_BORROWED, _ctx);
    kk_std_core_sslice__sslice _pat_1_0_0 = kk_std_core_sslice__sslice_unbox(_box_x854, KK_BORROWED, _ctx);
    if (kk_std_core_types__is_Nil(_pat_0_0_0, _ctx)) {
      kk_std_core_types__tuple2_drop(_match_x1863, _ctx);
      _x_x2479 = kk_std_core_types__new_Nothing(_ctx); /*forall<a> maybe<a>*/
      goto _match_x2481;
    }
  }
  {
    kk_box_t _box_x855 = _match_x1863.fst;
    kk_box_t _box_x856 = _match_x1863.snd;
    kk_std_core_sslice__sslice rest = kk_std_core_sslice__sslice_unbox(_box_x856, KK_BORROWED, _ctx);
    kk_std_core_types__list xs = kk_std_core_types__list_unbox(_box_x855, KK_BORROWED, _ctx);
    kk_std_core_sslice__sslice_dup(rest, _ctx);
    kk_std_core_types__list_dup(xs, _ctx);
    kk_std_core_types__tuple2_drop(_match_x1863, _ctx);
    kk_box_t _x_x2482;
    kk_std_core_types__tuple2 _x_x2483 = kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(xs, _ctx), kk_std_core_sslice__sslice_box(rest, _ctx), _ctx); /*(134, 135)*/
    _x_x2482 = kk_std_core_types__tuple2_box(_x_x2483, _ctx); /*88*/
    _x_x2479 = kk_std_core_types__new_Just(_x_x2482, _ctx); /*forall<a> maybe<a>*/
  }
  _match_x2481: ;
  return kk_std_core_types__maybe_box(_x_x2479, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_whitespace_fun2485__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_whitespace_fun2485(kk_function_t _fself, kk_box_t _b_x865, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_whitespace_fun2485(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_whitespace_fun2485, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_text_parse_whitespace_fun2485(kk_function_t _fself, kk_box_t _b_x865, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2486;
  kk_std_core_types__maybe _x_x2487 = kk_std_core_types__maybe_unbox(_b_x865, KK_OWNED, _ctx); /*maybe<list<char>>*/
  _x_x2486 = kk_std_text_parse__mlift_whitespace_10572(_x_x2487, _ctx); /*string*/
  return kk_string_box(_x_x2486);
}


// lift anonymous function
struct kk_std_text_parse_whitespace_fun2495__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_whitespace_fun2495(kk_function_t _fself, kk_box_t _b_x876, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_whitespace_fun2495(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_whitespace_fun2495, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_text_parse_whitespace_fun2495(kk_function_t _fself, kk_box_t _b_x876, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2496;
  kk_std_core_types__list _x_x2497 = kk_std_core_types__list_unbox(_b_x876, KK_OWNED, _ctx); /*list<char>*/
  _x_x2496 = kk_std_core_string_listchar_fs_string(_x_x2497, _ctx); /*string*/
  return kk_string_box(_x_x2496);
}

kk_string_t kk_std_text_parse_whitespace(kk_context_t* _ctx) { /* () -> parse string */ 
  kk_std_core_hnd__ev ev_10847 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
  kk_std_core_types__maybe x_10844;
  kk_box_t _x_x2475;
  {
    struct kk_std_core_hnd_Ev* _con_x2476 = kk_std_core_hnd__as_Ev(ev_10847, _ctx);
    kk_box_t _box_x839 = _con_x2476->hnd;
    int32_t m = _con_x2476->marker;
    kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x839, KK_BORROWED, _ctx);
    kk_std_text_parse__parse_dup(h, _ctx);
    {
      struct kk_std_text_parse__Hnd_parse* _con_x2477 = kk_std_text_parse__as_Hnd_parse(h, _ctx);
      kk_integer_t _pat_0 = _con_x2477->_cfc;
      kk_std_core_hnd__clause0 _pat_1_1 = _con_x2477->_fun_current_input;
      kk_std_core_hnd__clause1 _pat_2 = _con_x2477->_brk_fail;
      kk_std_core_hnd__clause0 _pat_3 = _con_x2477->_ctl_pick;
      kk_std_core_hnd__clause1 _fun_satisfy = _con_x2477->_fun_satisfy;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause0_drop(_pat_3, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_2, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_1_1, _ctx);
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_fun_satisfy, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x846 = _fun_satisfy.clause;
        _x_x2475 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x846, (_fun_unbox_x846, m, ev_10847, kk_function_box(kk_std_text_parse_new_whitespace_fun2478(_ctx), _ctx), _ctx), _ctx); /*46*/
      }
    }
  }
  x_10844 = kk_std_core_types__maybe_unbox(_x_x2475, KK_OWNED, _ctx); /*maybe<list<char>>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__maybe_drop(x_10844, _ctx);
    kk_box_t _x_x2484 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_whitespace_fun2485(_ctx), _ctx); /*2419*/
    return kk_string_unbox(_x_x2484);
  }
  {
    kk_std_core_types__list x_1_10850;
    if (kk_std_core_types__is_Nothing(x_10844, _ctx)) {
      kk_std_core_hnd__ev ev_0_10852 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
      kk_box_t _x_x2488;
      {
        struct kk_std_core_hnd_Ev* _con_x2489 = kk_std_core_hnd__as_Ev(ev_0_10852, _ctx);
        kk_box_t _box_x866 = _con_x2489->hnd;
        int32_t m_0 = _con_x2489->marker;
        kk_std_text_parse__parse h_0 = kk_std_text_parse__parse_unbox(_box_x866, KK_BORROWED, _ctx);
        kk_std_text_parse__parse_dup(h_0, _ctx);
        {
          struct kk_std_text_parse__Hnd_parse* _con_x2490 = kk_std_text_parse__as_Hnd_parse(h_0, _ctx);
          kk_integer_t _pat_0_3 = _con_x2490->_cfc;
          kk_std_core_hnd__clause0 _pat_1_3 = _con_x2490->_fun_current_input;
          kk_std_core_hnd__clause1 _brk_fail = _con_x2490->_brk_fail;
          kk_std_core_hnd__clause0 _pat_2_1 = _con_x2490->_ctl_pick;
          kk_std_core_hnd__clause1 _pat_3_1 = _con_x2490->_fun_satisfy;
          if kk_likely(kk_datatype_ptr_is_unique(h_0, _ctx)) {
            kk_std_core_hnd__clause1_drop(_pat_3_1, _ctx);
            kk_std_core_hnd__clause0_drop(_pat_2_1, _ctx);
            kk_std_core_hnd__clause0_drop(_pat_1_3, _ctx);
            kk_integer_drop(_pat_0_3, _ctx);
            kk_datatype_ptr_free(h_0, _ctx);
          }
          else {
            kk_std_core_hnd__clause1_dup(_brk_fail, _ctx);
            kk_datatype_ptr_decref(h_0, _ctx);
          }
          {
            kk_function_t _fun_unbox_x870 = _brk_fail.clause;
            kk_box_t _x_x2491;
            kk_string_t _x_x2492 = kk_string_empty(); /*string*/
            _x_x2491 = kk_string_box(_x_x2492); /*45*/
            _x_x2488 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x870, (_fun_unbox_x870, m_0, ev_0_10852, _x_x2491, _ctx), _ctx); /*46*/
          }
        }
      }
      x_1_10850 = kk_std_core_types__list_unbox(_x_x2488, KK_OWNED, _ctx); /*list<char>*/
    }
    else {
      kk_box_t _box_x874 = x_10844._cons.Just.value;
      kk_std_core_types__list x_3 = kk_std_core_types__list_unbox(_box_x874, KK_BORROWED, _ctx);
      kk_std_core_types__list_dup(x_3, _ctx);
      kk_std_core_types__maybe_drop(x_10844, _ctx);
      x_1_10850 = x_3; /*list<char>*/
    }
    if (kk_yielding(kk_context())) {
      kk_std_core_types__list_drop(x_1_10850, _ctx);
      kk_box_t _x_x2494 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_whitespace_fun2495(_ctx), _ctx); /*2419*/
      return kk_string_unbox(_x_x2494);
    }
    {
      return kk_std_core_string_listchar_fs_string(x_1_10850, _ctx);
    }
  }
}
 
// lifted local: whitespace0, @spec-x10285
// specialized: std/text/parse/next-while0, on parameters @uniq-pred@10276, using:
// @uniq-pred@10276 = std/core/char/is-white

kk_std_core_types__tuple2 kk_std_text_parse__lift_whitespace0_10354(kk_std_core_sslice__sslice _uniq_slice_10275, kk_std_core_types__list _uniq_acc_10277, kk_context_t* _ctx) { /* (sslice/sslice, list<char>) -> (list<char>, sslice/sslice) */ 
  kk__tailcall: ;
  kk_std_core_types__maybe _match_x1860;
  kk_std_core_sslice__sslice _x_x2498 = kk_std_core_sslice__sslice_dup(_uniq_slice_10275, _ctx); /*sslice/sslice*/
  _match_x1860 = kk_std_core_sslice_next(_x_x2498, _ctx); /*maybe<(char, sslice/sslice)>*/
  if (kk_std_core_types__is_Just(_match_x1860, _ctx)) {
    kk_box_t _box_x879 = _match_x1860._cons.Just.value;
    kk_std_core_types__tuple2 _uniq_pat_0_10279 = kk_std_core_types__tuple2_unbox(_box_x879, KK_BORROWED, _ctx);
    if (kk_std_core_types__is_Tuple2(_uniq_pat_0_10279, _ctx)) {
      kk_box_t _box_x880 = _uniq_pat_0_10279.fst;
      kk_box_t _box_x881 = _uniq_pat_0_10279.snd;
      kk_char_t _uniq_c_10280 = kk_char_unbox(_box_x880, KK_BORROWED, _ctx);
      if (kk_std_core_char_is_white(_uniq_c_10280, _ctx)) {
        kk_std_core_sslice__sslice _uniq_rest_10281 = kk_std_core_sslice__sslice_unbox(_box_x881, KK_BORROWED, _ctx);
        kk_std_core_sslice__sslice_drop(_uniq_slice_10275, _ctx);
        kk_std_core_sslice__sslice_dup(_uniq_rest_10281, _ctx);
        kk_std_core_types__maybe_drop(_match_x1860, _ctx);
        { // tailcall
          kk_std_core_types__list _x_x2499 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_char_box(_uniq_c_10280, _ctx), _uniq_acc_10277, _ctx); /*list<79>*/
          _uniq_slice_10275 = _uniq_rest_10281;
          _uniq_acc_10277 = _x_x2499;
          goto kk__tailcall;
        }
      }
    }
  }
  {
    kk_std_core_types__maybe_drop(_match_x1860, _ctx);
    kk_std_core_types__list _b_x884_888;
    if (kk_std_core_types__is_Nil(_uniq_acc_10277, _ctx)) {
      _b_x884_888 = kk_std_core_types__new_Nil(_ctx); /*list<char>*/
    }
    else {
      _b_x884_888 = kk_std_core_list__unroll_reverse_acc_10003(kk_std_core_types__new_Nil(_ctx), _uniq_acc_10277, _ctx); /*list<char>*/
    }
    return kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(_b_x884_888, _ctx), kk_std_core_sslice__sslice_box(_uniq_slice_10275, _ctx), _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_text_parse__mlift_whitespace0_10573_fun2507__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse__mlift_whitespace0_10573_fun2507(kk_function_t _fself, kk_box_t _b_x900, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse__new_mlift_whitespace0_10573_fun2507(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse__mlift_whitespace0_10573_fun2507, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_text_parse__mlift_whitespace0_10573_fun2507(kk_function_t _fself, kk_box_t _b_x900, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2508;
  kk_std_core_types__list _x_x2509 = kk_std_core_types__list_unbox(_b_x900, KK_OWNED, _ctx); /*list<char>*/
  _x_x2508 = kk_std_core_string_listchar_fs_string(_x_x2509, _ctx); /*string*/
  return kk_string_box(_x_x2508);
}

kk_string_t kk_std_text_parse__mlift_whitespace0_10573(kk_std_core_types__maybe _y_x10450, kk_context_t* _ctx) { /* (maybe<list<char>>) -> parse string */ 
  kk_std_core_types__list x_10855;
  if (kk_std_core_types__is_Nothing(_y_x10450, _ctx)) {
    kk_std_core_hnd__ev ev_10857 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
    kk_box_t _x_x2500;
    {
      struct kk_std_core_hnd_Ev* _con_x2501 = kk_std_core_hnd__as_Ev(ev_10857, _ctx);
      kk_box_t _box_x890 = _con_x2501->hnd;
      int32_t m = _con_x2501->marker;
      kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x890, KK_BORROWED, _ctx);
      kk_std_text_parse__parse_dup(h, _ctx);
      {
        struct kk_std_text_parse__Hnd_parse* _con_x2502 = kk_std_text_parse__as_Hnd_parse(h, _ctx);
        kk_integer_t _pat_0 = _con_x2502->_cfc;
        kk_std_core_hnd__clause0 _pat_1_1 = _con_x2502->_fun_current_input;
        kk_std_core_hnd__clause1 _brk_fail = _con_x2502->_brk_fail;
        kk_std_core_hnd__clause0 _pat_2_0 = _con_x2502->_ctl_pick;
        kk_std_core_hnd__clause1 _pat_3 = _con_x2502->_fun_satisfy;
        if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
          kk_std_core_hnd__clause1_drop(_pat_3, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_2_0, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_1_1, _ctx);
          kk_integer_drop(_pat_0, _ctx);
          kk_datatype_ptr_free(h, _ctx);
        }
        else {
          kk_std_core_hnd__clause1_dup(_brk_fail, _ctx);
          kk_datatype_ptr_decref(h, _ctx);
        }
        {
          kk_function_t _fun_unbox_x894 = _brk_fail.clause;
          kk_box_t _x_x2503;
          kk_string_t _x_x2504 = kk_string_empty(); /*string*/
          _x_x2503 = kk_string_box(_x_x2504); /*45*/
          _x_x2500 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x894, (_fun_unbox_x894, m, ev_10857, _x_x2503, _ctx), _ctx); /*46*/
        }
      }
    }
    x_10855 = kk_std_core_types__list_unbox(_x_x2500, KK_OWNED, _ctx); /*list<char>*/
  }
  else {
    kk_box_t _box_x898 = _y_x10450._cons.Just.value;
    kk_std_core_types__list x_1 = kk_std_core_types__list_unbox(_box_x898, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(x_1, _ctx);
    kk_std_core_types__maybe_drop(_y_x10450, _ctx);
    x_10855 = x_1; /*list<char>*/
  }
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_10855, _ctx);
    kk_box_t _x_x2506 = kk_std_core_hnd_yield_extend(kk_std_text_parse__new_mlift_whitespace0_10573_fun2507(_ctx), _ctx); /*2419*/
    return kk_string_unbox(_x_x2506);
  }
  {
    return kk_std_core_string_listchar_fs_string(x_10855, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_text_parse__mlift_whitespace0_10574_fun2513__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse__mlift_whitespace0_10574_fun2513(kk_function_t _fself, kk_box_t _b_x915, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse__new_mlift_whitespace0_10574_fun2513(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse__mlift_whitespace0_10574_fun2513, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_text_parse__mlift_whitespace0_10574_fun2513(kk_function_t _fself, kk_box_t _b_x915, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__maybe _x_x2514;
  kk_std_core_types__tuple2 _match_x1858;
  kk_std_core_sslice__sslice _x_x2515 = kk_std_core_sslice__sslice_unbox(_b_x915, KK_OWNED, _ctx); /*sslice/sslice*/
  _match_x1858 = kk_std_text_parse__lift_whitespace0_10354(_x_x2515, kk_std_core_types__new_Nil(_ctx), _ctx); /*(list<char>, sslice/sslice)*/
  {
    kk_box_t _box_x916 = _match_x1858.fst;
    kk_box_t _box_x917 = _match_x1858.snd;
    kk_std_core_types__list _pat_0_1_0 = kk_std_core_types__list_unbox(_box_x916, KK_BORROWED, _ctx);
    kk_std_core_sslice__sslice _pat_1_0_0 = kk_std_core_sslice__sslice_unbox(_box_x917, KK_BORROWED, _ctx);
    if (kk_std_core_types__is_Nil(_pat_0_1_0, _ctx)) {
      kk_std_core_types__tuple2_drop(_match_x1858, _ctx);
      _x_x2514 = kk_std_core_types__new_Nothing(_ctx); /*forall<a> maybe<a>*/
      goto _match_x2516;
    }
  }
  {
    kk_box_t _box_x918 = _match_x1858.fst;
    kk_box_t _box_x919 = _match_x1858.snd;
    kk_std_core_sslice__sslice rest = kk_std_core_sslice__sslice_unbox(_box_x919, KK_BORROWED, _ctx);
    kk_std_core_types__list xs = kk_std_core_types__list_unbox(_box_x918, KK_BORROWED, _ctx);
    kk_std_core_sslice__sslice_dup(rest, _ctx);
    kk_std_core_types__list_dup(xs, _ctx);
    kk_std_core_types__tuple2_drop(_match_x1858, _ctx);
    kk_box_t _x_x2517;
    kk_std_core_types__tuple2 _x_x2518 = kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(xs, _ctx), kk_std_core_sslice__sslice_box(rest, _ctx), _ctx); /*(134, 135)*/
    _x_x2517 = kk_std_core_types__tuple2_box(_x_x2518, _ctx); /*88*/
    _x_x2514 = kk_std_core_types__new_Just(_x_x2517, _ctx); /*forall<a> maybe<a>*/
  }
  _match_x2516: ;
  return kk_std_core_types__maybe_box(_x_x2514, _ctx);
}


// lift anonymous function
struct kk_std_text_parse__mlift_whitespace0_10574_fun2520__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse__mlift_whitespace0_10574_fun2520(kk_function_t _fself, kk_box_t _b_x928, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse__new_mlift_whitespace0_10574_fun2520(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse__mlift_whitespace0_10574_fun2520, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_text_parse__mlift_whitespace0_10574_fun2520(kk_function_t _fself, kk_box_t _b_x928, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2521;
  kk_std_core_types__maybe _x_x2522 = kk_std_core_types__maybe_unbox(_b_x928, KK_OWNED, _ctx); /*maybe<list<char>>*/
  _x_x2521 = kk_std_text_parse__mlift_whitespace0_10573(_x_x2522, _ctx); /*string*/
  return kk_string_box(_x_x2521);
}

kk_string_t kk_std_text_parse__mlift_whitespace0_10574(bool _y_x10449, kk_context_t* _ctx) { /* (bool) -> parse string */ 
  if (_y_x10449) {
    kk_std_core_hnd__ev ev_10862 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
    kk_std_core_types__maybe x_10860;
    kk_box_t _x_x2510;
    {
      struct kk_std_core_hnd_Ev* _con_x2511 = kk_std_core_hnd__as_Ev(ev_10862, _ctx);
      kk_box_t _box_x902 = _con_x2511->hnd;
      int32_t m = _con_x2511->marker;
      kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x902, KK_BORROWED, _ctx);
      kk_std_text_parse__parse_dup(h, _ctx);
      {
        struct kk_std_text_parse__Hnd_parse* _con_x2512 = kk_std_text_parse__as_Hnd_parse(h, _ctx);
        kk_integer_t _pat_0_0 = _con_x2512->_cfc;
        kk_std_core_hnd__clause0 _pat_1_1 = _con_x2512->_fun_current_input;
        kk_std_core_hnd__clause1 _pat_2 = _con_x2512->_brk_fail;
        kk_std_core_hnd__clause0 _pat_3 = _con_x2512->_ctl_pick;
        kk_std_core_hnd__clause1 _fun_satisfy = _con_x2512->_fun_satisfy;
        if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
          kk_std_core_hnd__clause0_drop(_pat_3, _ctx);
          kk_std_core_hnd__clause1_drop(_pat_2, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_1_1, _ctx);
          kk_integer_drop(_pat_0_0, _ctx);
          kk_datatype_ptr_free(h, _ctx);
        }
        else {
          kk_std_core_hnd__clause1_dup(_fun_satisfy, _ctx);
          kk_datatype_ptr_decref(h, _ctx);
        }
        {
          kk_function_t _fun_unbox_x909 = _fun_satisfy.clause;
          _x_x2510 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x909, (_fun_unbox_x909, m, ev_10862, kk_function_box(kk_std_text_parse__new_mlift_whitespace0_10574_fun2513(_ctx), _ctx), _ctx), _ctx); /*46*/
        }
      }
    }
    x_10860 = kk_std_core_types__maybe_unbox(_x_x2510, KK_OWNED, _ctx); /*maybe<list<char>>*/
    if (kk_yielding(kk_context())) {
      kk_std_core_types__maybe_drop(x_10860, _ctx);
      kk_box_t _x_x2519 = kk_std_core_hnd_yield_extend(kk_std_text_parse__new_mlift_whitespace0_10574_fun2520(_ctx), _ctx); /*2419*/
      return kk_string_unbox(_x_x2519);
    }
    {
      return kk_std_text_parse__mlift_whitespace0_10573(x_10860, _ctx);
    }
  }
  {
    return kk_string_empty();
  }
}


// lift anonymous function
struct kk_std_text_parse_whitespace0_fun2528__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_whitespace0_fun2528(kk_function_t _fself, kk_box_t _b_x937, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_whitespace0_fun2528(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_whitespace0_fun2528, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_text_parse_whitespace0_fun2528(kk_function_t _fself, kk_box_t _b_x937, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2529;
  bool _x_x2530 = kk_bool_unbox(_b_x937); /*bool*/
  _x_x2529 = kk_std_text_parse__mlift_whitespace0_10574(_x_x2530, _ctx); /*string*/
  return kk_string_box(_x_x2529);
}


// lift anonymous function
struct kk_std_text_parse_whitespace0_fun2534__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_whitespace0_fun2534(kk_function_t _fself, kk_box_t _b_x951, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_whitespace0_fun2534(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_whitespace0_fun2534, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_text_parse_whitespace0_fun2534(kk_function_t _fself, kk_box_t _b_x951, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__maybe _x_x2535;
  kk_std_core_types__tuple2 _match_x1856;
  kk_std_core_sslice__sslice _x_x2536 = kk_std_core_sslice__sslice_unbox(_b_x951, KK_OWNED, _ctx); /*sslice/sslice*/
  _match_x1856 = kk_std_text_parse__lift_whitespace0_10354(_x_x2536, kk_std_core_types__new_Nil(_ctx), _ctx); /*(list<char>, sslice/sslice)*/
  {
    kk_box_t _box_x952 = _match_x1856.fst;
    kk_box_t _box_x953 = _match_x1856.snd;
    kk_std_core_types__list _pat_0_1_0 = kk_std_core_types__list_unbox(_box_x952, KK_BORROWED, _ctx);
    kk_std_core_sslice__sslice _pat_1_0_0 = kk_std_core_sslice__sslice_unbox(_box_x953, KK_BORROWED, _ctx);
    if (kk_std_core_types__is_Nil(_pat_0_1_0, _ctx)) {
      kk_std_core_types__tuple2_drop(_match_x1856, _ctx);
      _x_x2535 = kk_std_core_types__new_Nothing(_ctx); /*forall<a> maybe<a>*/
      goto _match_x2537;
    }
  }
  {
    kk_box_t _box_x954 = _match_x1856.fst;
    kk_box_t _box_x955 = _match_x1856.snd;
    kk_std_core_sslice__sslice rest = kk_std_core_sslice__sslice_unbox(_box_x955, KK_BORROWED, _ctx);
    kk_std_core_types__list xs = kk_std_core_types__list_unbox(_box_x954, KK_BORROWED, _ctx);
    kk_std_core_sslice__sslice_dup(rest, _ctx);
    kk_std_core_types__list_dup(xs, _ctx);
    kk_std_core_types__tuple2_drop(_match_x1856, _ctx);
    kk_box_t _x_x2538;
    kk_std_core_types__tuple2 _x_x2539 = kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(xs, _ctx), kk_std_core_sslice__sslice_box(rest, _ctx), _ctx); /*(134, 135)*/
    _x_x2538 = kk_std_core_types__tuple2_box(_x_x2539, _ctx); /*88*/
    _x_x2535 = kk_std_core_types__new_Just(_x_x2538, _ctx); /*forall<a> maybe<a>*/
  }
  _match_x2537: ;
  return kk_std_core_types__maybe_box(_x_x2535, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_whitespace0_fun2541__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_whitespace0_fun2541(kk_function_t _fself, kk_box_t _b_x964, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_whitespace0_fun2541(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_whitespace0_fun2541, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_text_parse_whitespace0_fun2541(kk_function_t _fself, kk_box_t _b_x964, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2542;
  kk_std_core_types__maybe _x_x2543 = kk_std_core_types__maybe_unbox(_b_x964, KK_OWNED, _ctx); /*maybe<list<char>>*/
  _x_x2542 = kk_std_text_parse__mlift_whitespace0_10573(_x_x2543, _ctx); /*string*/
  return kk_string_box(_x_x2542);
}


// lift anonymous function
struct kk_std_text_parse_whitespace0_fun2551__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_whitespace0_fun2551(kk_function_t _fself, kk_box_t _b_x975, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_whitespace0_fun2551(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_whitespace0_fun2551, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_text_parse_whitespace0_fun2551(kk_function_t _fself, kk_box_t _b_x975, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2552;
  kk_std_core_types__list _x_x2553 = kk_std_core_types__list_unbox(_b_x975, KK_OWNED, _ctx); /*list<char>*/
  _x_x2552 = kk_std_core_string_listchar_fs_string(_x_x2553, _ctx); /*string*/
  return kk_string_box(_x_x2552);
}

kk_string_t kk_std_text_parse_whitespace0(kk_context_t* _ctx) { /* () -> parse string */ 
  kk_std_core_hnd__ev ev_10868 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
  bool x_10865;
  kk_box_t _x_x2524;
  {
    struct kk_std_core_hnd_Ev* _con_x2525 = kk_std_core_hnd__as_Ev(ev_10868, _ctx);
    kk_box_t _box_x930 = _con_x2525->hnd;
    int32_t m = _con_x2525->marker;
    kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x930, KK_BORROWED, _ctx);
    kk_std_text_parse__parse_dup(h, _ctx);
    {
      struct kk_std_text_parse__Hnd_parse* _con_x2526 = kk_std_text_parse__as_Hnd_parse(h, _ctx);
      kk_integer_t _pat_0 = _con_x2526->_cfc;
      kk_std_core_hnd__clause0 _pat_1_1 = _con_x2526->_fun_current_input;
      kk_std_core_hnd__clause1 _pat_2 = _con_x2526->_brk_fail;
      kk_std_core_hnd__clause0 _ctl_pick = _con_x2526->_ctl_pick;
      kk_std_core_hnd__clause1 _pat_3 = _con_x2526->_fun_satisfy;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause1_drop(_pat_3, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_2, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_1_1, _ctx);
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause0_dup(_ctl_pick, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x933 = _ctl_pick.clause;
        _x_x2524 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x933, (_fun_unbox_x933, m, ev_10868, _ctx), _ctx); /*35*/
      }
    }
  }
  x_10865 = kk_bool_unbox(_x_x2524); /*bool*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2527 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_whitespace0_fun2528(_ctx), _ctx); /*2419*/
    return kk_string_unbox(_x_x2527);
  }
  if (x_10865) {
    kk_std_core_hnd__ev ev_0_10873 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
    kk_std_core_types__maybe x_0_10870;
    kk_box_t _x_x2531;
    {
      struct kk_std_core_hnd_Ev* _con_x2532 = kk_std_core_hnd__as_Ev(ev_0_10873, _ctx);
      kk_box_t _box_x938 = _con_x2532->hnd;
      int32_t m_0 = _con_x2532->marker;
      kk_std_text_parse__parse h_0 = kk_std_text_parse__parse_unbox(_box_x938, KK_BORROWED, _ctx);
      kk_std_text_parse__parse_dup(h_0, _ctx);
      {
        struct kk_std_text_parse__Hnd_parse* _con_x2533 = kk_std_text_parse__as_Hnd_parse(h_0, _ctx);
        kk_integer_t _pat_0_3 = _con_x2533->_cfc;
        kk_std_core_hnd__clause0 _pat_1_2 = _con_x2533->_fun_current_input;
        kk_std_core_hnd__clause1 _pat_2_1 = _con_x2533->_brk_fail;
        kk_std_core_hnd__clause0 _pat_3_1 = _con_x2533->_ctl_pick;
        kk_std_core_hnd__clause1 _fun_satisfy = _con_x2533->_fun_satisfy;
        if kk_likely(kk_datatype_ptr_is_unique(h_0, _ctx)) {
          kk_std_core_hnd__clause0_drop(_pat_3_1, _ctx);
          kk_std_core_hnd__clause1_drop(_pat_2_1, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_1_2, _ctx);
          kk_integer_drop(_pat_0_3, _ctx);
          kk_datatype_ptr_free(h_0, _ctx);
        }
        else {
          kk_std_core_hnd__clause1_dup(_fun_satisfy, _ctx);
          kk_datatype_ptr_decref(h_0, _ctx);
        }
        {
          kk_function_t _fun_unbox_x945 = _fun_satisfy.clause;
          _x_x2531 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x945, (_fun_unbox_x945, m_0, ev_0_10873, kk_function_box(kk_std_text_parse_new_whitespace0_fun2534(_ctx), _ctx), _ctx), _ctx); /*46*/
        }
      }
    }
    x_0_10870 = kk_std_core_types__maybe_unbox(_x_x2531, KK_OWNED, _ctx); /*maybe<list<char>>*/
    if (kk_yielding(kk_context())) {
      kk_std_core_types__maybe_drop(x_0_10870, _ctx);
      kk_box_t _x_x2540 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_whitespace0_fun2541(_ctx), _ctx); /*2419*/
      return kk_string_unbox(_x_x2540);
    }
    {
      kk_std_core_types__list x_2_10876;
      if (kk_std_core_types__is_Nothing(x_0_10870, _ctx)) {
        kk_std_core_hnd__ev ev_1_10878 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
        kk_box_t _x_x2544;
        {
          struct kk_std_core_hnd_Ev* _con_x2545 = kk_std_core_hnd__as_Ev(ev_1_10878, _ctx);
          kk_box_t _box_x965 = _con_x2545->hnd;
          int32_t m_1 = _con_x2545->marker;
          kk_std_text_parse__parse h_1 = kk_std_text_parse__parse_unbox(_box_x965, KK_BORROWED, _ctx);
          kk_std_text_parse__parse_dup(h_1, _ctx);
          {
            struct kk_std_text_parse__Hnd_parse* _con_x2546 = kk_std_text_parse__as_Hnd_parse(h_1, _ctx);
            kk_integer_t _pat_0_5 = _con_x2546->_cfc;
            kk_std_core_hnd__clause0 _pat_1_4 = _con_x2546->_fun_current_input;
            kk_std_core_hnd__clause1 _brk_fail = _con_x2546->_brk_fail;
            kk_std_core_hnd__clause0 _pat_2_2 = _con_x2546->_ctl_pick;
            kk_std_core_hnd__clause1 _pat_3_2 = _con_x2546->_fun_satisfy;
            if kk_likely(kk_datatype_ptr_is_unique(h_1, _ctx)) {
              kk_std_core_hnd__clause1_drop(_pat_3_2, _ctx);
              kk_std_core_hnd__clause0_drop(_pat_2_2, _ctx);
              kk_std_core_hnd__clause0_drop(_pat_1_4, _ctx);
              kk_integer_drop(_pat_0_5, _ctx);
              kk_datatype_ptr_free(h_1, _ctx);
            }
            else {
              kk_std_core_hnd__clause1_dup(_brk_fail, _ctx);
              kk_datatype_ptr_decref(h_1, _ctx);
            }
            {
              kk_function_t _fun_unbox_x969 = _brk_fail.clause;
              kk_box_t _x_x2547;
              kk_string_t _x_x2548 = kk_string_empty(); /*string*/
              _x_x2547 = kk_string_box(_x_x2548); /*45*/
              _x_x2544 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x969, (_fun_unbox_x969, m_1, ev_1_10878, _x_x2547, _ctx), _ctx); /*46*/
            }
          }
        }
        x_2_10876 = kk_std_core_types__list_unbox(_x_x2544, KK_OWNED, _ctx); /*list<char>*/
      }
      else {
        kk_box_t _box_x973 = x_0_10870._cons.Just.value;
        kk_std_core_types__list x_4 = kk_std_core_types__list_unbox(_box_x973, KK_BORROWED, _ctx);
        kk_std_core_types__list_dup(x_4, _ctx);
        kk_std_core_types__maybe_drop(x_0_10870, _ctx);
        x_2_10876 = x_4; /*list<char>*/
      }
      if (kk_yielding(kk_context())) {
        kk_std_core_types__list_drop(x_2_10876, _ctx);
        kk_box_t _x_x2550 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_whitespace0_fun2551(_ctx), _ctx); /*2419*/
        return kk_string_unbox(_x_x2550);
      }
      {
        return kk_std_core_string_listchar_fs_string(x_2_10876, _ctx);
      }
    }
  }
  {
    return kk_string_empty();
  }
}
 
// lifted local: digits, @spec-x10296
// specialized: std/text/parse/next-while0, on parameters @uniq-pred@10287, using:
// @uniq-pred@10287 = std/core/char/is-digit

kk_std_core_types__tuple2 kk_std_text_parse__lift_digits_10355(kk_std_core_sslice__sslice _uniq_slice_10286, kk_std_core_types__list _uniq_acc_10288, kk_context_t* _ctx) { /* (sslice/sslice, list<char>) -> (list<char>, sslice/sslice) */ 
  kk__tailcall: ;
  kk_std_core_types__maybe _match_x1852;
  kk_std_core_sslice__sslice _x_x2555 = kk_std_core_sslice__sslice_dup(_uniq_slice_10286, _ctx); /*sslice/sslice*/
  _match_x1852 = kk_std_core_sslice_next(_x_x2555, _ctx); /*maybe<(char, sslice/sslice)>*/
  if (kk_std_core_types__is_Just(_match_x1852, _ctx)) {
    kk_box_t _box_x979 = _match_x1852._cons.Just.value;
    kk_std_core_types__tuple2 _uniq_pat_0_10290 = kk_std_core_types__tuple2_unbox(_box_x979, KK_BORROWED, _ctx);
    if (kk_std_core_types__is_Tuple2(_uniq_pat_0_10290, _ctx)) {
      kk_box_t _box_x980 = _uniq_pat_0_10290.fst;
      kk_box_t _box_x981 = _uniq_pat_0_10290.snd;
      kk_char_t _uniq_c_10291 = kk_char_unbox(_box_x980, KK_BORROWED, _ctx);
      if (kk_std_core_char_is_digit(_uniq_c_10291, _ctx)) {
        kk_std_core_sslice__sslice _uniq_rest_10292 = kk_std_core_sslice__sslice_unbox(_box_x981, KK_BORROWED, _ctx);
        kk_std_core_sslice__sslice_drop(_uniq_slice_10286, _ctx);
        kk_std_core_sslice__sslice_dup(_uniq_rest_10292, _ctx);
        kk_std_core_types__maybe_drop(_match_x1852, _ctx);
        { // tailcall
          kk_std_core_types__list _x_x2556 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_char_box(_uniq_c_10291, _ctx), _uniq_acc_10288, _ctx); /*list<79>*/
          _uniq_slice_10286 = _uniq_rest_10292;
          _uniq_acc_10288 = _x_x2556;
          goto kk__tailcall;
        }
      }
    }
  }
  {
    kk_std_core_types__maybe_drop(_match_x1852, _ctx);
    kk_std_core_types__list _b_x984_988;
    if (kk_std_core_types__is_Nil(_uniq_acc_10288, _ctx)) {
      _b_x984_988 = kk_std_core_types__new_Nil(_ctx); /*list<char>*/
    }
    else {
      _b_x984_988 = kk_std_core_list__unroll_reverse_acc_10003(kk_std_core_types__new_Nil(_ctx), _uniq_acc_10288, _ctx); /*list<char>*/
    }
    return kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(_b_x984_988, _ctx), kk_std_core_sslice__sslice_box(_uniq_slice_10286, _ctx), _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_text_parse__mlift_digits_10575_fun2564__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse__mlift_digits_10575_fun2564(kk_function_t _fself, kk_box_t _b_x1000, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse__new_mlift_digits_10575_fun2564(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse__mlift_digits_10575_fun2564, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_text_parse__mlift_digits_10575_fun2564(kk_function_t _fself, kk_box_t _b_x1000, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2565;
  kk_std_core_types__list _x_x2566 = kk_std_core_types__list_unbox(_b_x1000, KK_OWNED, _ctx); /*list<char>*/
  _x_x2565 = kk_std_core_string_listchar_fs_string(_x_x2566, _ctx); /*string*/
  return kk_string_box(_x_x2565);
}

kk_string_t kk_std_text_parse__mlift_digits_10575(kk_std_core_types__maybe _y_x10454, kk_context_t* _ctx) { /* (maybe<list<char>>) -> parse string */ 
  kk_std_core_types__list x_10881;
  if (kk_std_core_types__is_Nothing(_y_x10454, _ctx)) {
    kk_std_core_hnd__ev ev_10883 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
    kk_box_t _x_x2557;
    {
      struct kk_std_core_hnd_Ev* _con_x2558 = kk_std_core_hnd__as_Ev(ev_10883, _ctx);
      kk_box_t _box_x990 = _con_x2558->hnd;
      int32_t m = _con_x2558->marker;
      kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x990, KK_BORROWED, _ctx);
      kk_std_text_parse__parse_dup(h, _ctx);
      {
        struct kk_std_text_parse__Hnd_parse* _con_x2559 = kk_std_text_parse__as_Hnd_parse(h, _ctx);
        kk_integer_t _pat_0 = _con_x2559->_cfc;
        kk_std_core_hnd__clause0 _pat_1_1 = _con_x2559->_fun_current_input;
        kk_std_core_hnd__clause1 _brk_fail = _con_x2559->_brk_fail;
        kk_std_core_hnd__clause0 _pat_2_0 = _con_x2559->_ctl_pick;
        kk_std_core_hnd__clause1 _pat_3 = _con_x2559->_fun_satisfy;
        if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
          kk_std_core_hnd__clause1_drop(_pat_3, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_2_0, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_1_1, _ctx);
          kk_integer_drop(_pat_0, _ctx);
          kk_datatype_ptr_free(h, _ctx);
        }
        else {
          kk_std_core_hnd__clause1_dup(_brk_fail, _ctx);
          kk_datatype_ptr_decref(h, _ctx);
        }
        {
          kk_function_t _fun_unbox_x994 = _brk_fail.clause;
          kk_box_t _x_x2560;
          kk_string_t _x_x2561;
          kk_define_string_literal(static, _s_x2562, 5, "digit", _ctx)
          _x_x2561 = kk_string_dup(_s_x2562, _ctx); /*string*/
          _x_x2560 = kk_string_box(_x_x2561); /*45*/
          _x_x2557 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x994, (_fun_unbox_x994, m, ev_10883, _x_x2560, _ctx), _ctx); /*46*/
        }
      }
    }
    x_10881 = kk_std_core_types__list_unbox(_x_x2557, KK_OWNED, _ctx); /*list<char>*/
  }
  else {
    kk_box_t _box_x998 = _y_x10454._cons.Just.value;
    kk_std_core_types__list x_1 = kk_std_core_types__list_unbox(_box_x998, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(x_1, _ctx);
    kk_std_core_types__maybe_drop(_y_x10454, _ctx);
    x_10881 = x_1; /*list<char>*/
  }
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_10881, _ctx);
    kk_box_t _x_x2563 = kk_std_core_hnd_yield_extend(kk_std_text_parse__new_mlift_digits_10575_fun2564(_ctx), _ctx); /*2419*/
    return kk_string_unbox(_x_x2563);
  }
  {
    return kk_std_core_string_listchar_fs_string(x_10881, _ctx);
  }
}


// lift anonymous function
struct kk_std_text_parse_digits_fun2570__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_digits_fun2570(kk_function_t _fself, kk_box_t _b_x1015, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_digits_fun2570(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_digits_fun2570, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_text_parse_digits_fun2570(kk_function_t _fself, kk_box_t _b_x1015, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__maybe _x_x2571;
  kk_std_core_types__tuple2 _match_x1850;
  kk_std_core_sslice__sslice _x_x2572 = kk_std_core_sslice__sslice_unbox(_b_x1015, KK_OWNED, _ctx); /*sslice/sslice*/
  _match_x1850 = kk_std_text_parse__lift_digits_10355(_x_x2572, kk_std_core_types__new_Nil(_ctx), _ctx); /*(list<char>, sslice/sslice)*/
  {
    kk_box_t _box_x1016 = _match_x1850.fst;
    kk_box_t _box_x1017 = _match_x1850.snd;
    kk_std_core_types__list _pat_0_0_0 = kk_std_core_types__list_unbox(_box_x1016, KK_BORROWED, _ctx);
    kk_std_core_sslice__sslice _pat_1_0_0 = kk_std_core_sslice__sslice_unbox(_box_x1017, KK_BORROWED, _ctx);
    if (kk_std_core_types__is_Nil(_pat_0_0_0, _ctx)) {
      kk_std_core_types__tuple2_drop(_match_x1850, _ctx);
      _x_x2571 = kk_std_core_types__new_Nothing(_ctx); /*forall<a> maybe<a>*/
      goto _match_x2573;
    }
  }
  {
    kk_box_t _box_x1018 = _match_x1850.fst;
    kk_box_t _box_x1019 = _match_x1850.snd;
    kk_std_core_sslice__sslice rest = kk_std_core_sslice__sslice_unbox(_box_x1019, KK_BORROWED, _ctx);
    kk_std_core_types__list xs = kk_std_core_types__list_unbox(_box_x1018, KK_BORROWED, _ctx);
    kk_std_core_sslice__sslice_dup(rest, _ctx);
    kk_std_core_types__list_dup(xs, _ctx);
    kk_std_core_types__tuple2_drop(_match_x1850, _ctx);
    kk_box_t _x_x2574;
    kk_std_core_types__tuple2 _x_x2575 = kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(xs, _ctx), kk_std_core_sslice__sslice_box(rest, _ctx), _ctx); /*(134, 135)*/
    _x_x2574 = kk_std_core_types__tuple2_box(_x_x2575, _ctx); /*88*/
    _x_x2571 = kk_std_core_types__new_Just(_x_x2574, _ctx); /*forall<a> maybe<a>*/
  }
  _match_x2573: ;
  return kk_std_core_types__maybe_box(_x_x2571, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_digits_fun2577__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_digits_fun2577(kk_function_t _fself, kk_box_t _b_x1028, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_digits_fun2577(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_digits_fun2577, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_text_parse_digits_fun2577(kk_function_t _fself, kk_box_t _b_x1028, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2578;
  kk_std_core_types__maybe _x_x2579 = kk_std_core_types__maybe_unbox(_b_x1028, KK_OWNED, _ctx); /*maybe<list<char>>*/
  _x_x2578 = kk_std_text_parse__mlift_digits_10575(_x_x2579, _ctx); /*string*/
  return kk_string_box(_x_x2578);
}


// lift anonymous function
struct kk_std_text_parse_digits_fun2587__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_digits_fun2587(kk_function_t _fself, kk_box_t _b_x1039, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_digits_fun2587(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_digits_fun2587, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_text_parse_digits_fun2587(kk_function_t _fself, kk_box_t _b_x1039, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2588;
  kk_std_core_types__list _x_x2589 = kk_std_core_types__list_unbox(_b_x1039, KK_OWNED, _ctx); /*list<char>*/
  _x_x2588 = kk_std_core_string_listchar_fs_string(_x_x2589, _ctx); /*string*/
  return kk_string_box(_x_x2588);
}

kk_string_t kk_std_text_parse_digits(kk_context_t* _ctx) { /* () -> parse string */ 
  kk_std_core_hnd__ev ev_10889 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
  kk_std_core_types__maybe x_10886;
  kk_box_t _x_x2567;
  {
    struct kk_std_core_hnd_Ev* _con_x2568 = kk_std_core_hnd__as_Ev(ev_10889, _ctx);
    kk_box_t _box_x1002 = _con_x2568->hnd;
    int32_t m = _con_x2568->marker;
    kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x1002, KK_BORROWED, _ctx);
    kk_std_text_parse__parse_dup(h, _ctx);
    {
      struct kk_std_text_parse__Hnd_parse* _con_x2569 = kk_std_text_parse__as_Hnd_parse(h, _ctx);
      kk_integer_t _pat_0 = _con_x2569->_cfc;
      kk_std_core_hnd__clause0 _pat_1_1 = _con_x2569->_fun_current_input;
      kk_std_core_hnd__clause1 _pat_2 = _con_x2569->_brk_fail;
      kk_std_core_hnd__clause0 _pat_3 = _con_x2569->_ctl_pick;
      kk_std_core_hnd__clause1 _fun_satisfy = _con_x2569->_fun_satisfy;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause0_drop(_pat_3, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_2, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_1_1, _ctx);
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_fun_satisfy, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x1009 = _fun_satisfy.clause;
        _x_x2567 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x1009, (_fun_unbox_x1009, m, ev_10889, kk_function_box(kk_std_text_parse_new_digits_fun2570(_ctx), _ctx), _ctx), _ctx); /*46*/
      }
    }
  }
  x_10886 = kk_std_core_types__maybe_unbox(_x_x2567, KK_OWNED, _ctx); /*maybe<list<char>>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__maybe_drop(x_10886, _ctx);
    kk_box_t _x_x2576 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_digits_fun2577(_ctx), _ctx); /*2419*/
    return kk_string_unbox(_x_x2576);
  }
  {
    kk_std_core_types__list x_1_10892;
    if (kk_std_core_types__is_Nothing(x_10886, _ctx)) {
      kk_std_core_hnd__ev ev_0_10894 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
      kk_box_t _x_x2580;
      {
        struct kk_std_core_hnd_Ev* _con_x2581 = kk_std_core_hnd__as_Ev(ev_0_10894, _ctx);
        kk_box_t _box_x1029 = _con_x2581->hnd;
        int32_t m_0 = _con_x2581->marker;
        kk_std_text_parse__parse h_0 = kk_std_text_parse__parse_unbox(_box_x1029, KK_BORROWED, _ctx);
        kk_std_text_parse__parse_dup(h_0, _ctx);
        {
          struct kk_std_text_parse__Hnd_parse* _con_x2582 = kk_std_text_parse__as_Hnd_parse(h_0, _ctx);
          kk_integer_t _pat_0_3 = _con_x2582->_cfc;
          kk_std_core_hnd__clause0 _pat_1_3 = _con_x2582->_fun_current_input;
          kk_std_core_hnd__clause1 _brk_fail = _con_x2582->_brk_fail;
          kk_std_core_hnd__clause0 _pat_2_1 = _con_x2582->_ctl_pick;
          kk_std_core_hnd__clause1 _pat_3_1 = _con_x2582->_fun_satisfy;
          if kk_likely(kk_datatype_ptr_is_unique(h_0, _ctx)) {
            kk_std_core_hnd__clause1_drop(_pat_3_1, _ctx);
            kk_std_core_hnd__clause0_drop(_pat_2_1, _ctx);
            kk_std_core_hnd__clause0_drop(_pat_1_3, _ctx);
            kk_integer_drop(_pat_0_3, _ctx);
            kk_datatype_ptr_free(h_0, _ctx);
          }
          else {
            kk_std_core_hnd__clause1_dup(_brk_fail, _ctx);
            kk_datatype_ptr_decref(h_0, _ctx);
          }
          {
            kk_function_t _fun_unbox_x1033 = _brk_fail.clause;
            kk_box_t _x_x2583;
            kk_string_t _x_x2584;
            kk_define_string_literal(static, _s_x2585, 5, "digit", _ctx)
            _x_x2584 = kk_string_dup(_s_x2585, _ctx); /*string*/
            _x_x2583 = kk_string_box(_x_x2584); /*45*/
            _x_x2580 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x1033, (_fun_unbox_x1033, m_0, ev_0_10894, _x_x2583, _ctx), _ctx); /*46*/
          }
        }
      }
      x_1_10892 = kk_std_core_types__list_unbox(_x_x2580, KK_OWNED, _ctx); /*list<char>*/
    }
    else {
      kk_box_t _box_x1037 = x_10886._cons.Just.value;
      kk_std_core_types__list x_3 = kk_std_core_types__list_unbox(_box_x1037, KK_BORROWED, _ctx);
      kk_std_core_types__list_dup(x_3, _ctx);
      kk_std_core_types__maybe_drop(x_10886, _ctx);
      x_1_10892 = x_3; /*list<char>*/
    }
    if (kk_yielding(kk_context())) {
      kk_std_core_types__list_drop(x_1_10892, _ctx);
      kk_box_t _x_x2586 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_digits_fun2587(_ctx), _ctx); /*2419*/
      return kk_string_unbox(_x_x2586);
    }
    {
      return kk_std_core_string_listchar_fs_string(x_1_10892, _ctx);
    }
  }
}
 
// lifted local: digits0, @spec-x10307
// specialized: std/text/parse/next-while0, on parameters @uniq-pred@10298, using:
// @uniq-pred@10298 = std/core/char/is-digit

kk_std_core_types__tuple2 kk_std_text_parse__lift_digits0_10356(kk_std_core_sslice__sslice _uniq_slice_10297, kk_std_core_types__list _uniq_acc_10299, kk_context_t* _ctx) { /* (sslice/sslice, list<char>) -> (list<char>, sslice/sslice) */ 
  kk__tailcall: ;
  kk_std_core_types__maybe _match_x1847;
  kk_std_core_sslice__sslice _x_x2590 = kk_std_core_sslice__sslice_dup(_uniq_slice_10297, _ctx); /*sslice/sslice*/
  _match_x1847 = kk_std_core_sslice_next(_x_x2590, _ctx); /*maybe<(char, sslice/sslice)>*/
  if (kk_std_core_types__is_Just(_match_x1847, _ctx)) {
    kk_box_t _box_x1042 = _match_x1847._cons.Just.value;
    kk_std_core_types__tuple2 _uniq_pat_0_10301 = kk_std_core_types__tuple2_unbox(_box_x1042, KK_BORROWED, _ctx);
    if (kk_std_core_types__is_Tuple2(_uniq_pat_0_10301, _ctx)) {
      kk_box_t _box_x1043 = _uniq_pat_0_10301.fst;
      kk_box_t _box_x1044 = _uniq_pat_0_10301.snd;
      kk_char_t _uniq_c_10302 = kk_char_unbox(_box_x1043, KK_BORROWED, _ctx);
      if (kk_std_core_char_is_digit(_uniq_c_10302, _ctx)) {
        kk_std_core_sslice__sslice _uniq_rest_10303 = kk_std_core_sslice__sslice_unbox(_box_x1044, KK_BORROWED, _ctx);
        kk_std_core_sslice__sslice_drop(_uniq_slice_10297, _ctx);
        kk_std_core_sslice__sslice_dup(_uniq_rest_10303, _ctx);
        kk_std_core_types__maybe_drop(_match_x1847, _ctx);
        { // tailcall
          kk_std_core_types__list _x_x2591 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_char_box(_uniq_c_10302, _ctx), _uniq_acc_10299, _ctx); /*list<79>*/
          _uniq_slice_10297 = _uniq_rest_10303;
          _uniq_acc_10299 = _x_x2591;
          goto kk__tailcall;
        }
      }
    }
  }
  {
    kk_std_core_types__maybe_drop(_match_x1847, _ctx);
    kk_std_core_types__list _b_x1047_1051;
    if (kk_std_core_types__is_Nil(_uniq_acc_10299, _ctx)) {
      _b_x1047_1051 = kk_std_core_types__new_Nil(_ctx); /*list<char>*/
    }
    else {
      _b_x1047_1051 = kk_std_core_list__unroll_reverse_acc_10003(kk_std_core_types__new_Nil(_ctx), _uniq_acc_10299, _ctx); /*list<char>*/
    }
    return kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(_b_x1047_1051, _ctx), kk_std_core_sslice__sslice_box(_uniq_slice_10297, _ctx), _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_text_parse__mlift_digits0_10576_fun2599__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse__mlift_digits0_10576_fun2599(kk_function_t _fself, kk_box_t _b_x1063, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse__new_mlift_digits0_10576_fun2599(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse__mlift_digits0_10576_fun2599, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_text_parse__mlift_digits0_10576_fun2599(kk_function_t _fself, kk_box_t _b_x1063, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2600;
  kk_std_core_types__list _x_x2601 = kk_std_core_types__list_unbox(_b_x1063, KK_OWNED, _ctx); /*list<char>*/
  _x_x2600 = kk_std_core_string_listchar_fs_string(_x_x2601, _ctx); /*string*/
  return kk_string_box(_x_x2600);
}

kk_string_t kk_std_text_parse__mlift_digits0_10576(kk_std_core_types__maybe _y_x10458, kk_context_t* _ctx) { /* (maybe<list<char>>) -> parse string */ 
  kk_std_core_types__list x_10897;
  if (kk_std_core_types__is_Nothing(_y_x10458, _ctx)) {
    kk_std_core_hnd__ev ev_10899 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
    kk_box_t _x_x2592;
    {
      struct kk_std_core_hnd_Ev* _con_x2593 = kk_std_core_hnd__as_Ev(ev_10899, _ctx);
      kk_box_t _box_x1053 = _con_x2593->hnd;
      int32_t m = _con_x2593->marker;
      kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x1053, KK_BORROWED, _ctx);
      kk_std_text_parse__parse_dup(h, _ctx);
      {
        struct kk_std_text_parse__Hnd_parse* _con_x2594 = kk_std_text_parse__as_Hnd_parse(h, _ctx);
        kk_integer_t _pat_0 = _con_x2594->_cfc;
        kk_std_core_hnd__clause0 _pat_1_1 = _con_x2594->_fun_current_input;
        kk_std_core_hnd__clause1 _brk_fail = _con_x2594->_brk_fail;
        kk_std_core_hnd__clause0 _pat_2_0 = _con_x2594->_ctl_pick;
        kk_std_core_hnd__clause1 _pat_3 = _con_x2594->_fun_satisfy;
        if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
          kk_std_core_hnd__clause1_drop(_pat_3, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_2_0, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_1_1, _ctx);
          kk_integer_drop(_pat_0, _ctx);
          kk_datatype_ptr_free(h, _ctx);
        }
        else {
          kk_std_core_hnd__clause1_dup(_brk_fail, _ctx);
          kk_datatype_ptr_decref(h, _ctx);
        }
        {
          kk_function_t _fun_unbox_x1057 = _brk_fail.clause;
          kk_box_t _x_x2595;
          kk_string_t _x_x2596;
          kk_define_string_literal(static, _s_x2597, 5, "digit", _ctx)
          _x_x2596 = kk_string_dup(_s_x2597, _ctx); /*string*/
          _x_x2595 = kk_string_box(_x_x2596); /*45*/
          _x_x2592 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x1057, (_fun_unbox_x1057, m, ev_10899, _x_x2595, _ctx), _ctx); /*46*/
        }
      }
    }
    x_10897 = kk_std_core_types__list_unbox(_x_x2592, KK_OWNED, _ctx); /*list<char>*/
  }
  else {
    kk_box_t _box_x1061 = _y_x10458._cons.Just.value;
    kk_std_core_types__list x_1 = kk_std_core_types__list_unbox(_box_x1061, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(x_1, _ctx);
    kk_std_core_types__maybe_drop(_y_x10458, _ctx);
    x_10897 = x_1; /*list<char>*/
  }
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_10897, _ctx);
    kk_box_t _x_x2598 = kk_std_core_hnd_yield_extend(kk_std_text_parse__new_mlift_digits0_10576_fun2599(_ctx), _ctx); /*2419*/
    return kk_string_unbox(_x_x2598);
  }
  {
    return kk_std_core_string_listchar_fs_string(x_10897, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_text_parse__mlift_digits0_10577_fun2605__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse__mlift_digits0_10577_fun2605(kk_function_t _fself, kk_box_t _b_x1078, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse__new_mlift_digits0_10577_fun2605(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse__mlift_digits0_10577_fun2605, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_text_parse__mlift_digits0_10577_fun2605(kk_function_t _fself, kk_box_t _b_x1078, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__maybe _x_x2606;
  kk_std_core_types__tuple2 _match_x1845;
  kk_std_core_sslice__sslice _x_x2607 = kk_std_core_sslice__sslice_unbox(_b_x1078, KK_OWNED, _ctx); /*sslice/sslice*/
  _match_x1845 = kk_std_text_parse__lift_digits0_10356(_x_x2607, kk_std_core_types__new_Nil(_ctx), _ctx); /*(list<char>, sslice/sslice)*/
  {
    kk_box_t _box_x1079 = _match_x1845.fst;
    kk_box_t _box_x1080 = _match_x1845.snd;
    kk_std_core_types__list _pat_0_1_0 = kk_std_core_types__list_unbox(_box_x1079, KK_BORROWED, _ctx);
    kk_std_core_sslice__sslice _pat_1_0_0 = kk_std_core_sslice__sslice_unbox(_box_x1080, KK_BORROWED, _ctx);
    if (kk_std_core_types__is_Nil(_pat_0_1_0, _ctx)) {
      kk_std_core_types__tuple2_drop(_match_x1845, _ctx);
      _x_x2606 = kk_std_core_types__new_Nothing(_ctx); /*forall<a> maybe<a>*/
      goto _match_x2608;
    }
  }
  {
    kk_box_t _box_x1081 = _match_x1845.fst;
    kk_box_t _box_x1082 = _match_x1845.snd;
    kk_std_core_sslice__sslice rest = kk_std_core_sslice__sslice_unbox(_box_x1082, KK_BORROWED, _ctx);
    kk_std_core_types__list xs = kk_std_core_types__list_unbox(_box_x1081, KK_BORROWED, _ctx);
    kk_std_core_sslice__sslice_dup(rest, _ctx);
    kk_std_core_types__list_dup(xs, _ctx);
    kk_std_core_types__tuple2_drop(_match_x1845, _ctx);
    kk_box_t _x_x2609;
    kk_std_core_types__tuple2 _x_x2610 = kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(xs, _ctx), kk_std_core_sslice__sslice_box(rest, _ctx), _ctx); /*(134, 135)*/
    _x_x2609 = kk_std_core_types__tuple2_box(_x_x2610, _ctx); /*88*/
    _x_x2606 = kk_std_core_types__new_Just(_x_x2609, _ctx); /*forall<a> maybe<a>*/
  }
  _match_x2608: ;
  return kk_std_core_types__maybe_box(_x_x2606, _ctx);
}


// lift anonymous function
struct kk_std_text_parse__mlift_digits0_10577_fun2612__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse__mlift_digits0_10577_fun2612(kk_function_t _fself, kk_box_t _b_x1091, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse__new_mlift_digits0_10577_fun2612(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse__mlift_digits0_10577_fun2612, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_text_parse__mlift_digits0_10577_fun2612(kk_function_t _fself, kk_box_t _b_x1091, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2613;
  kk_std_core_types__maybe _x_x2614 = kk_std_core_types__maybe_unbox(_b_x1091, KK_OWNED, _ctx); /*maybe<list<char>>*/
  _x_x2613 = kk_std_text_parse__mlift_digits0_10576(_x_x2614, _ctx); /*string*/
  return kk_string_box(_x_x2613);
}

kk_string_t kk_std_text_parse__mlift_digits0_10577(bool _y_x10457, kk_context_t* _ctx) { /* (bool) -> parse string */ 
  if (_y_x10457) {
    kk_std_core_hnd__ev ev_10904 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
    kk_std_core_types__maybe x_10902;
    kk_box_t _x_x2602;
    {
      struct kk_std_core_hnd_Ev* _con_x2603 = kk_std_core_hnd__as_Ev(ev_10904, _ctx);
      kk_box_t _box_x1065 = _con_x2603->hnd;
      int32_t m = _con_x2603->marker;
      kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x1065, KK_BORROWED, _ctx);
      kk_std_text_parse__parse_dup(h, _ctx);
      {
        struct kk_std_text_parse__Hnd_parse* _con_x2604 = kk_std_text_parse__as_Hnd_parse(h, _ctx);
        kk_integer_t _pat_0_0 = _con_x2604->_cfc;
        kk_std_core_hnd__clause0 _pat_1_1 = _con_x2604->_fun_current_input;
        kk_std_core_hnd__clause1 _pat_2 = _con_x2604->_brk_fail;
        kk_std_core_hnd__clause0 _pat_3 = _con_x2604->_ctl_pick;
        kk_std_core_hnd__clause1 _fun_satisfy = _con_x2604->_fun_satisfy;
        if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
          kk_std_core_hnd__clause0_drop(_pat_3, _ctx);
          kk_std_core_hnd__clause1_drop(_pat_2, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_1_1, _ctx);
          kk_integer_drop(_pat_0_0, _ctx);
          kk_datatype_ptr_free(h, _ctx);
        }
        else {
          kk_std_core_hnd__clause1_dup(_fun_satisfy, _ctx);
          kk_datatype_ptr_decref(h, _ctx);
        }
        {
          kk_function_t _fun_unbox_x1072 = _fun_satisfy.clause;
          _x_x2602 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x1072, (_fun_unbox_x1072, m, ev_10904, kk_function_box(kk_std_text_parse__new_mlift_digits0_10577_fun2605(_ctx), _ctx), _ctx), _ctx); /*46*/
        }
      }
    }
    x_10902 = kk_std_core_types__maybe_unbox(_x_x2602, KK_OWNED, _ctx); /*maybe<list<char>>*/
    if (kk_yielding(kk_context())) {
      kk_std_core_types__maybe_drop(x_10902, _ctx);
      kk_box_t _x_x2611 = kk_std_core_hnd_yield_extend(kk_std_text_parse__new_mlift_digits0_10577_fun2612(_ctx), _ctx); /*2419*/
      return kk_string_unbox(_x_x2611);
    }
    {
      return kk_std_text_parse__mlift_digits0_10576(x_10902, _ctx);
    }
  }
  {
    kk_define_string_literal(static, _s_x2615, 1, "0", _ctx)
    return kk_string_dup(_s_x2615, _ctx);
  }
}


// lift anonymous function
struct kk_std_text_parse_digits0_fun2620__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_digits0_fun2620(kk_function_t _fself, kk_box_t _b_x1100, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_digits0_fun2620(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_digits0_fun2620, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_text_parse_digits0_fun2620(kk_function_t _fself, kk_box_t _b_x1100, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2621;
  bool _x_x2622 = kk_bool_unbox(_b_x1100); /*bool*/
  _x_x2621 = kk_std_text_parse__mlift_digits0_10577(_x_x2622, _ctx); /*string*/
  return kk_string_box(_x_x2621);
}


// lift anonymous function
struct kk_std_text_parse_digits0_fun2626__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_digits0_fun2626(kk_function_t _fself, kk_box_t _b_x1114, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_digits0_fun2626(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_digits0_fun2626, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_text_parse_digits0_fun2626(kk_function_t _fself, kk_box_t _b_x1114, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__maybe _x_x2627;
  kk_std_core_types__tuple2 _match_x1843;
  kk_std_core_sslice__sslice _x_x2628 = kk_std_core_sslice__sslice_unbox(_b_x1114, KK_OWNED, _ctx); /*sslice/sslice*/
  _match_x1843 = kk_std_text_parse__lift_digits0_10356(_x_x2628, kk_std_core_types__new_Nil(_ctx), _ctx); /*(list<char>, sslice/sslice)*/
  {
    kk_box_t _box_x1115 = _match_x1843.fst;
    kk_box_t _box_x1116 = _match_x1843.snd;
    kk_std_core_types__list _pat_0_1_0 = kk_std_core_types__list_unbox(_box_x1115, KK_BORROWED, _ctx);
    kk_std_core_sslice__sslice _pat_1_0_0 = kk_std_core_sslice__sslice_unbox(_box_x1116, KK_BORROWED, _ctx);
    if (kk_std_core_types__is_Nil(_pat_0_1_0, _ctx)) {
      kk_std_core_types__tuple2_drop(_match_x1843, _ctx);
      _x_x2627 = kk_std_core_types__new_Nothing(_ctx); /*forall<a> maybe<a>*/
      goto _match_x2629;
    }
  }
  {
    kk_box_t _box_x1117 = _match_x1843.fst;
    kk_box_t _box_x1118 = _match_x1843.snd;
    kk_std_core_sslice__sslice rest = kk_std_core_sslice__sslice_unbox(_box_x1118, KK_BORROWED, _ctx);
    kk_std_core_types__list xs = kk_std_core_types__list_unbox(_box_x1117, KK_BORROWED, _ctx);
    kk_std_core_sslice__sslice_dup(rest, _ctx);
    kk_std_core_types__list_dup(xs, _ctx);
    kk_std_core_types__tuple2_drop(_match_x1843, _ctx);
    kk_box_t _x_x2630;
    kk_std_core_types__tuple2 _x_x2631 = kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(xs, _ctx), kk_std_core_sslice__sslice_box(rest, _ctx), _ctx); /*(134, 135)*/
    _x_x2630 = kk_std_core_types__tuple2_box(_x_x2631, _ctx); /*88*/
    _x_x2627 = kk_std_core_types__new_Just(_x_x2630, _ctx); /*forall<a> maybe<a>*/
  }
  _match_x2629: ;
  return kk_std_core_types__maybe_box(_x_x2627, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_digits0_fun2633__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_digits0_fun2633(kk_function_t _fself, kk_box_t _b_x1127, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_digits0_fun2633(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_digits0_fun2633, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_text_parse_digits0_fun2633(kk_function_t _fself, kk_box_t _b_x1127, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2634;
  kk_std_core_types__maybe _x_x2635 = kk_std_core_types__maybe_unbox(_b_x1127, KK_OWNED, _ctx); /*maybe<list<char>>*/
  _x_x2634 = kk_std_text_parse__mlift_digits0_10576(_x_x2635, _ctx); /*string*/
  return kk_string_box(_x_x2634);
}


// lift anonymous function
struct kk_std_text_parse_digits0_fun2643__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_digits0_fun2643(kk_function_t _fself, kk_box_t _b_x1138, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_digits0_fun2643(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_digits0_fun2643, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_text_parse_digits0_fun2643(kk_function_t _fself, kk_box_t _b_x1138, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2644;
  kk_std_core_types__list _x_x2645 = kk_std_core_types__list_unbox(_b_x1138, KK_OWNED, _ctx); /*list<char>*/
  _x_x2644 = kk_std_core_string_listchar_fs_string(_x_x2645, _ctx); /*string*/
  return kk_string_box(_x_x2644);
}

kk_string_t kk_std_text_parse_digits0(kk_context_t* _ctx) { /* () -> parse string */ 
  kk_std_core_hnd__ev ev_10910 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
  bool x_10907;
  kk_box_t _x_x2616;
  {
    struct kk_std_core_hnd_Ev* _con_x2617 = kk_std_core_hnd__as_Ev(ev_10910, _ctx);
    kk_box_t _box_x1093 = _con_x2617->hnd;
    int32_t m = _con_x2617->marker;
    kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x1093, KK_BORROWED, _ctx);
    kk_std_text_parse__parse_dup(h, _ctx);
    {
      struct kk_std_text_parse__Hnd_parse* _con_x2618 = kk_std_text_parse__as_Hnd_parse(h, _ctx);
      kk_integer_t _pat_0 = _con_x2618->_cfc;
      kk_std_core_hnd__clause0 _pat_1_1 = _con_x2618->_fun_current_input;
      kk_std_core_hnd__clause1 _pat_2 = _con_x2618->_brk_fail;
      kk_std_core_hnd__clause0 _ctl_pick = _con_x2618->_ctl_pick;
      kk_std_core_hnd__clause1 _pat_3 = _con_x2618->_fun_satisfy;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause1_drop(_pat_3, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_2, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_1_1, _ctx);
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause0_dup(_ctl_pick, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x1096 = _ctl_pick.clause;
        _x_x2616 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x1096, (_fun_unbox_x1096, m, ev_10910, _ctx), _ctx); /*35*/
      }
    }
  }
  x_10907 = kk_bool_unbox(_x_x2616); /*bool*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2619 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_digits0_fun2620(_ctx), _ctx); /*2419*/
    return kk_string_unbox(_x_x2619);
  }
  if (x_10907) {
    kk_std_core_hnd__ev ev_0_10915 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
    kk_std_core_types__maybe x_0_10912;
    kk_box_t _x_x2623;
    {
      struct kk_std_core_hnd_Ev* _con_x2624 = kk_std_core_hnd__as_Ev(ev_0_10915, _ctx);
      kk_box_t _box_x1101 = _con_x2624->hnd;
      int32_t m_0 = _con_x2624->marker;
      kk_std_text_parse__parse h_0 = kk_std_text_parse__parse_unbox(_box_x1101, KK_BORROWED, _ctx);
      kk_std_text_parse__parse_dup(h_0, _ctx);
      {
        struct kk_std_text_parse__Hnd_parse* _con_x2625 = kk_std_text_parse__as_Hnd_parse(h_0, _ctx);
        kk_integer_t _pat_0_3 = _con_x2625->_cfc;
        kk_std_core_hnd__clause0 _pat_1_2 = _con_x2625->_fun_current_input;
        kk_std_core_hnd__clause1 _pat_2_1 = _con_x2625->_brk_fail;
        kk_std_core_hnd__clause0 _pat_3_1 = _con_x2625->_ctl_pick;
        kk_std_core_hnd__clause1 _fun_satisfy = _con_x2625->_fun_satisfy;
        if kk_likely(kk_datatype_ptr_is_unique(h_0, _ctx)) {
          kk_std_core_hnd__clause0_drop(_pat_3_1, _ctx);
          kk_std_core_hnd__clause1_drop(_pat_2_1, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_1_2, _ctx);
          kk_integer_drop(_pat_0_3, _ctx);
          kk_datatype_ptr_free(h_0, _ctx);
        }
        else {
          kk_std_core_hnd__clause1_dup(_fun_satisfy, _ctx);
          kk_datatype_ptr_decref(h_0, _ctx);
        }
        {
          kk_function_t _fun_unbox_x1108 = _fun_satisfy.clause;
          _x_x2623 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x1108, (_fun_unbox_x1108, m_0, ev_0_10915, kk_function_box(kk_std_text_parse_new_digits0_fun2626(_ctx), _ctx), _ctx), _ctx); /*46*/
        }
      }
    }
    x_0_10912 = kk_std_core_types__maybe_unbox(_x_x2623, KK_OWNED, _ctx); /*maybe<list<char>>*/
    if (kk_yielding(kk_context())) {
      kk_std_core_types__maybe_drop(x_0_10912, _ctx);
      kk_box_t _x_x2632 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_digits0_fun2633(_ctx), _ctx); /*2419*/
      return kk_string_unbox(_x_x2632);
    }
    {
      kk_std_core_types__list x_2_10918;
      if (kk_std_core_types__is_Nothing(x_0_10912, _ctx)) {
        kk_std_core_hnd__ev ev_1_10920 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
        kk_box_t _x_x2636;
        {
          struct kk_std_core_hnd_Ev* _con_x2637 = kk_std_core_hnd__as_Ev(ev_1_10920, _ctx);
          kk_box_t _box_x1128 = _con_x2637->hnd;
          int32_t m_1 = _con_x2637->marker;
          kk_std_text_parse__parse h_1 = kk_std_text_parse__parse_unbox(_box_x1128, KK_BORROWED, _ctx);
          kk_std_text_parse__parse_dup(h_1, _ctx);
          {
            struct kk_std_text_parse__Hnd_parse* _con_x2638 = kk_std_text_parse__as_Hnd_parse(h_1, _ctx);
            kk_integer_t _pat_0_5 = _con_x2638->_cfc;
            kk_std_core_hnd__clause0 _pat_1_4 = _con_x2638->_fun_current_input;
            kk_std_core_hnd__clause1 _brk_fail = _con_x2638->_brk_fail;
            kk_std_core_hnd__clause0 _pat_2_2 = _con_x2638->_ctl_pick;
            kk_std_core_hnd__clause1 _pat_3_2 = _con_x2638->_fun_satisfy;
            if kk_likely(kk_datatype_ptr_is_unique(h_1, _ctx)) {
              kk_std_core_hnd__clause1_drop(_pat_3_2, _ctx);
              kk_std_core_hnd__clause0_drop(_pat_2_2, _ctx);
              kk_std_core_hnd__clause0_drop(_pat_1_4, _ctx);
              kk_integer_drop(_pat_0_5, _ctx);
              kk_datatype_ptr_free(h_1, _ctx);
            }
            else {
              kk_std_core_hnd__clause1_dup(_brk_fail, _ctx);
              kk_datatype_ptr_decref(h_1, _ctx);
            }
            {
              kk_function_t _fun_unbox_x1132 = _brk_fail.clause;
              kk_box_t _x_x2639;
              kk_string_t _x_x2640;
              kk_define_string_literal(static, _s_x2641, 5, "digit", _ctx)
              _x_x2640 = kk_string_dup(_s_x2641, _ctx); /*string*/
              _x_x2639 = kk_string_box(_x_x2640); /*45*/
              _x_x2636 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x1132, (_fun_unbox_x1132, m_1, ev_1_10920, _x_x2639, _ctx), _ctx); /*46*/
            }
          }
        }
        x_2_10918 = kk_std_core_types__list_unbox(_x_x2636, KK_OWNED, _ctx); /*list<char>*/
      }
      else {
        kk_box_t _box_x1136 = x_0_10912._cons.Just.value;
        kk_std_core_types__list x_4 = kk_std_core_types__list_unbox(_box_x1136, KK_BORROWED, _ctx);
        kk_std_core_types__list_dup(x_4, _ctx);
        kk_std_core_types__maybe_drop(x_0_10912, _ctx);
        x_2_10918 = x_4; /*list<char>*/
      }
      if (kk_yielding(kk_context())) {
        kk_std_core_types__list_drop(x_2_10918, _ctx);
        kk_box_t _x_x2642 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_digits0_fun2643(_ctx), _ctx); /*2419*/
        return kk_string_unbox(_x_x2642);
      }
      {
        return kk_std_core_string_listchar_fs_string(x_2_10918, _ctx);
      }
    }
  }
  {
    kk_define_string_literal(static, _s_x2646, 1, "0", _ctx)
    return kk_string_dup(_s_x2646, _ctx);
  }
}
 
// lifted local: pnat, @spec-x10318
// specialized: std/text/parse/next-while0, on parameters @uniq-pred@10309, using:
// @uniq-pred@10309 = std/core/char/is-digit

kk_std_core_types__tuple2 kk_std_text_parse__lift_pnat_10357(kk_std_core_sslice__sslice _uniq_slice_10308, kk_std_core_types__list _uniq_acc_10310, kk_context_t* _ctx) { /* (sslice/sslice, list<char>) -> (list<char>, sslice/sslice) */ 
  kk__tailcall: ;
  kk_std_core_types__maybe _match_x1839;
  kk_std_core_sslice__sslice _x_x2647 = kk_std_core_sslice__sslice_dup(_uniq_slice_10308, _ctx); /*sslice/sslice*/
  _match_x1839 = kk_std_core_sslice_next(_x_x2647, _ctx); /*maybe<(char, sslice/sslice)>*/
  if (kk_std_core_types__is_Just(_match_x1839, _ctx)) {
    kk_box_t _box_x1142 = _match_x1839._cons.Just.value;
    kk_std_core_types__tuple2 _uniq_pat_0_10312 = kk_std_core_types__tuple2_unbox(_box_x1142, KK_BORROWED, _ctx);
    if (kk_std_core_types__is_Tuple2(_uniq_pat_0_10312, _ctx)) {
      kk_box_t _box_x1143 = _uniq_pat_0_10312.fst;
      kk_box_t _box_x1144 = _uniq_pat_0_10312.snd;
      kk_char_t _uniq_c_10313 = kk_char_unbox(_box_x1143, KK_BORROWED, _ctx);
      if (kk_std_core_char_is_digit(_uniq_c_10313, _ctx)) {
        kk_std_core_sslice__sslice _uniq_rest_10314 = kk_std_core_sslice__sslice_unbox(_box_x1144, KK_BORROWED, _ctx);
        kk_std_core_sslice__sslice_drop(_uniq_slice_10308, _ctx);
        kk_std_core_sslice__sslice_dup(_uniq_rest_10314, _ctx);
        kk_std_core_types__maybe_drop(_match_x1839, _ctx);
        { // tailcall
          kk_std_core_types__list _x_x2648 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_char_box(_uniq_c_10313, _ctx), _uniq_acc_10310, _ctx); /*list<79>*/
          _uniq_slice_10308 = _uniq_rest_10314;
          _uniq_acc_10310 = _x_x2648;
          goto kk__tailcall;
        }
      }
    }
  }
  {
    kk_std_core_types__maybe_drop(_match_x1839, _ctx);
    kk_std_core_types__list _b_x1147_1151;
    if (kk_std_core_types__is_Nil(_uniq_acc_10310, _ctx)) {
      _b_x1147_1151 = kk_std_core_types__new_Nil(_ctx); /*list<char>*/
    }
    else {
      _b_x1147_1151 = kk_std_core_list__unroll_reverse_acc_10003(kk_std_core_types__new_Nil(_ctx), _uniq_acc_10310, _ctx); /*list<char>*/
    }
    return kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(_b_x1147_1151, _ctx), kk_std_core_sslice__sslice_box(_uniq_slice_10308, _ctx), _ctx);
  }
}
 
// monadic lift

kk_integer_t kk_std_text_parse__mlift_pnat_10578(kk_std_core_types__list _c_x10464, kk_context_t* _ctx) { /* (list<char>) -> int */ 
  kk_string_t _x_x1_0_10538 = kk_std_core_string_listchar_fs_string(_c_x10464, _ctx); /*string*/;
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
  kk_std_core_types__maybe x;
  bool _x_x2649;
  kk_std_core_types__optional _match_x1838 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x1838, _ctx)) {
    kk_box_t _box_x1153 = _match_x1838._cons._Optional.value;
    bool _uniq_hex_581 = kk_bool_unbox(_box_x1153);
    kk_std_core_types__optional_drop(_match_x1838, _ctx);
    _x_x2649 = _uniq_hex_581; /*bool*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x1838, _ctx);
    _x_x2649 = false; /*bool*/
  }
  x = kk_std_core_int_xparse(_x_x1_0_10538, _x_x2649, _ctx); /*maybe<int>*/
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
  kk_unit_t keep_0 = kk_Unit;
  kk_evv_set(w_0,kk_context());
  if (kk_std_core_types__is_Nothing(x, _ctx)) {
    return kk_integer_from_small(0);
  }
  {
    kk_box_t _box_x1154 = x._cons.Just.value;
    kk_integer_t x_1 = kk_integer_unbox(_box_x1154, _ctx);
    kk_integer_dup(x_1, _ctx);
    kk_std_core_types__maybe_drop(x, _ctx);
    return x_1;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_text_parse__mlift_pnat_10579_fun2657__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse__mlift_pnat_10579_fun2657(kk_function_t _fself, kk_box_t _b_x1165, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse__new_mlift_pnat_10579_fun2657(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse__mlift_pnat_10579_fun2657, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_text_parse__mlift_pnat_10579_fun2657(kk_function_t _fself, kk_box_t _b_x1165, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x2658;
  kk_std_core_types__list _x_x2659 = kk_std_core_types__list_unbox(_b_x1165, KK_OWNED, _ctx); /*list<char>*/
  _x_x2658 = kk_std_text_parse__mlift_pnat_10578(_x_x2659, _ctx); /*int*/
  return kk_integer_box(_x_x2658, _ctx);
}

kk_integer_t kk_std_text_parse__mlift_pnat_10579(kk_std_core_types__maybe _y_x10462, kk_context_t* _ctx) { /* (maybe<list<char>>) -> parse int */ 
  kk_std_core_types__list x_10929;
  if (kk_std_core_types__is_Nothing(_y_x10462, _ctx)) {
    kk_std_core_hnd__ev ev_10931 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
    kk_box_t _x_x2650;
    {
      struct kk_std_core_hnd_Ev* _con_x2651 = kk_std_core_hnd__as_Ev(ev_10931, _ctx);
      kk_box_t _box_x1155 = _con_x2651->hnd;
      int32_t m = _con_x2651->marker;
      kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x1155, KK_BORROWED, _ctx);
      kk_std_text_parse__parse_dup(h, _ctx);
      {
        struct kk_std_text_parse__Hnd_parse* _con_x2652 = kk_std_text_parse__as_Hnd_parse(h, _ctx);
        kk_integer_t _pat_0 = _con_x2652->_cfc;
        kk_std_core_hnd__clause0 _pat_1_1 = _con_x2652->_fun_current_input;
        kk_std_core_hnd__clause1 _brk_fail = _con_x2652->_brk_fail;
        kk_std_core_hnd__clause0 _pat_2_0 = _con_x2652->_ctl_pick;
        kk_std_core_hnd__clause1 _pat_3 = _con_x2652->_fun_satisfy;
        if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
          kk_std_core_hnd__clause1_drop(_pat_3, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_2_0, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_1_1, _ctx);
          kk_integer_drop(_pat_0, _ctx);
          kk_datatype_ptr_free(h, _ctx);
        }
        else {
          kk_std_core_hnd__clause1_dup(_brk_fail, _ctx);
          kk_datatype_ptr_decref(h, _ctx);
        }
        {
          kk_function_t _fun_unbox_x1159 = _brk_fail.clause;
          kk_box_t _x_x2653;
          kk_string_t _x_x2654;
          kk_define_string_literal(static, _s_x2655, 5, "digit", _ctx)
          _x_x2654 = kk_string_dup(_s_x2655, _ctx); /*string*/
          _x_x2653 = kk_string_box(_x_x2654); /*45*/
          _x_x2650 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x1159, (_fun_unbox_x1159, m, ev_10931, _x_x2653, _ctx), _ctx); /*46*/
        }
      }
    }
    x_10929 = kk_std_core_types__list_unbox(_x_x2650, KK_OWNED, _ctx); /*list<char>*/
  }
  else {
    kk_box_t _box_x1163 = _y_x10462._cons.Just.value;
    kk_std_core_types__list x_0_0 = kk_std_core_types__list_unbox(_box_x1163, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(x_0_0, _ctx);
    kk_std_core_types__maybe_drop(_y_x10462, _ctx);
    x_10929 = x_0_0; /*list<char>*/
  }
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_10929, _ctx);
    kk_box_t _x_x2656 = kk_std_core_hnd_yield_extend(kk_std_text_parse__new_mlift_pnat_10579_fun2657(_ctx), _ctx); /*2419*/
    return kk_integer_unbox(_x_x2656, _ctx);
  }
  {
    return kk_std_text_parse__mlift_pnat_10578(x_10929, _ctx);
  }
}


// lift anonymous function
struct kk_std_text_parse_pnat_fun2663__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_pnat_fun2663(kk_function_t _fself, kk_box_t _b_x1180, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_pnat_fun2663(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_pnat_fun2663, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_text_parse_pnat_fun2663(kk_function_t _fself, kk_box_t _b_x1180, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__maybe _x_x2664;
  kk_std_core_types__tuple2 _match_x1836;
  kk_std_core_sslice__sslice _x_x2665 = kk_std_core_sslice__sslice_unbox(_b_x1180, KK_OWNED, _ctx); /*sslice/sslice*/
  _match_x1836 = kk_std_text_parse__lift_pnat_10357(_x_x2665, kk_std_core_types__new_Nil(_ctx), _ctx); /*(list<char>, sslice/sslice)*/
  {
    kk_box_t _box_x1181 = _match_x1836.fst;
    kk_box_t _box_x1182 = _match_x1836.snd;
    kk_std_core_types__list _pat_0_2 = kk_std_core_types__list_unbox(_box_x1181, KK_BORROWED, _ctx);
    kk_std_core_sslice__sslice _pat_1_0_0 = kk_std_core_sslice__sslice_unbox(_box_x1182, KK_BORROWED, _ctx);
    if (kk_std_core_types__is_Nil(_pat_0_2, _ctx)) {
      kk_std_core_types__tuple2_drop(_match_x1836, _ctx);
      _x_x2664 = kk_std_core_types__new_Nothing(_ctx); /*forall<a> maybe<a>*/
      goto _match_x2666;
    }
  }
  {
    kk_box_t _box_x1183 = _match_x1836.fst;
    kk_box_t _box_x1184 = _match_x1836.snd;
    kk_std_core_sslice__sslice rest = kk_std_core_sslice__sslice_unbox(_box_x1184, KK_BORROWED, _ctx);
    kk_std_core_types__list xs = kk_std_core_types__list_unbox(_box_x1183, KK_BORROWED, _ctx);
    kk_std_core_sslice__sslice_dup(rest, _ctx);
    kk_std_core_types__list_dup(xs, _ctx);
    kk_std_core_types__tuple2_drop(_match_x1836, _ctx);
    kk_box_t _x_x2667;
    kk_std_core_types__tuple2 _x_x2668 = kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(xs, _ctx), kk_std_core_sslice__sslice_box(rest, _ctx), _ctx); /*(134, 135)*/
    _x_x2667 = kk_std_core_types__tuple2_box(_x_x2668, _ctx); /*88*/
    _x_x2664 = kk_std_core_types__new_Just(_x_x2667, _ctx); /*forall<a> maybe<a>*/
  }
  _match_x2666: ;
  return kk_std_core_types__maybe_box(_x_x2664, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_pnat_fun2670__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_pnat_fun2670(kk_function_t _fself, kk_box_t _b_x1193, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_pnat_fun2670(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_pnat_fun2670, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_text_parse_pnat_fun2670(kk_function_t _fself, kk_box_t _b_x1193, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x2671;
  kk_std_core_types__maybe _x_x2672 = kk_std_core_types__maybe_unbox(_b_x1193, KK_OWNED, _ctx); /*maybe<list<char>>*/
  _x_x2671 = kk_std_text_parse__mlift_pnat_10579(_x_x2672, _ctx); /*int*/
  return kk_integer_box(_x_x2671, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_pnat_fun2680__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_pnat_fun2680(kk_function_t _fself, kk_box_t _b_x1204, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_pnat_fun2680(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_pnat_fun2680, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_text_parse_pnat_fun2680(kk_function_t _fself, kk_box_t _b_x1204, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x2681;
  kk_std_core_types__list _x_x2682 = kk_std_core_types__list_unbox(_b_x1204, KK_OWNED, _ctx); /*list<char>*/
  _x_x2681 = kk_std_text_parse__mlift_pnat_10578(_x_x2682, _ctx); /*int*/
  return kk_integer_box(_x_x2681, _ctx);
}

kk_integer_t kk_std_text_parse_pnat(kk_context_t* _ctx) { /* () -> parse int */ 
  kk_std_core_hnd__ev ev_10937 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
  kk_std_core_types__maybe x_10934;
  kk_box_t _x_x2660;
  {
    struct kk_std_core_hnd_Ev* _con_x2661 = kk_std_core_hnd__as_Ev(ev_10937, _ctx);
    kk_box_t _box_x1167 = _con_x2661->hnd;
    int32_t m = _con_x2661->marker;
    kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x1167, KK_BORROWED, _ctx);
    kk_std_text_parse__parse_dup(h, _ctx);
    {
      struct kk_std_text_parse__Hnd_parse* _con_x2662 = kk_std_text_parse__as_Hnd_parse(h, _ctx);
      kk_integer_t _pat_0 = _con_x2662->_cfc;
      kk_std_core_hnd__clause0 _pat_1_1 = _con_x2662->_fun_current_input;
      kk_std_core_hnd__clause1 _pat_2 = _con_x2662->_brk_fail;
      kk_std_core_hnd__clause0 _pat_3 = _con_x2662->_ctl_pick;
      kk_std_core_hnd__clause1 _fun_satisfy = _con_x2662->_fun_satisfy;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause0_drop(_pat_3, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_2, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_1_1, _ctx);
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_fun_satisfy, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x1174 = _fun_satisfy.clause;
        _x_x2660 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x1174, (_fun_unbox_x1174, m, ev_10937, kk_function_box(kk_std_text_parse_new_pnat_fun2663(_ctx), _ctx), _ctx), _ctx); /*46*/
      }
    }
  }
  x_10934 = kk_std_core_types__maybe_unbox(_x_x2660, KK_OWNED, _ctx); /*maybe<list<char>>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__maybe_drop(x_10934, _ctx);
    kk_box_t _x_x2669 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_pnat_fun2670(_ctx), _ctx); /*2419*/
    return kk_integer_unbox(_x_x2669, _ctx);
  }
  {
    kk_std_core_types__list x_1_10940;
    if (kk_std_core_types__is_Nothing(x_10934, _ctx)) {
      kk_std_core_hnd__ev ev_0_10943 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
      kk_box_t _x_x2673;
      {
        struct kk_std_core_hnd_Ev* _con_x2674 = kk_std_core_hnd__as_Ev(ev_0_10943, _ctx);
        kk_box_t _box_x1194 = _con_x2674->hnd;
        int32_t m_0 = _con_x2674->marker;
        kk_std_text_parse__parse h_0 = kk_std_text_parse__parse_unbox(_box_x1194, KK_BORROWED, _ctx);
        kk_std_text_parse__parse_dup(h_0, _ctx);
        {
          struct kk_std_text_parse__Hnd_parse* _con_x2675 = kk_std_text_parse__as_Hnd_parse(h_0, _ctx);
          kk_integer_t _pat_0_4 = _con_x2675->_cfc;
          kk_std_core_hnd__clause0 _pat_1_2 = _con_x2675->_fun_current_input;
          kk_std_core_hnd__clause1 _brk_fail = _con_x2675->_brk_fail;
          kk_std_core_hnd__clause0 _pat_2_2 = _con_x2675->_ctl_pick;
          kk_std_core_hnd__clause1 _pat_3_1 = _con_x2675->_fun_satisfy;
          if kk_likely(kk_datatype_ptr_is_unique(h_0, _ctx)) {
            kk_std_core_hnd__clause1_drop(_pat_3_1, _ctx);
            kk_std_core_hnd__clause0_drop(_pat_2_2, _ctx);
            kk_std_core_hnd__clause0_drop(_pat_1_2, _ctx);
            kk_integer_drop(_pat_0_4, _ctx);
            kk_datatype_ptr_free(h_0, _ctx);
          }
          else {
            kk_std_core_hnd__clause1_dup(_brk_fail, _ctx);
            kk_datatype_ptr_decref(h_0, _ctx);
          }
          {
            kk_function_t _fun_unbox_x1198 = _brk_fail.clause;
            kk_box_t _x_x2676;
            kk_string_t _x_x2677;
            kk_define_string_literal(static, _s_x2678, 5, "digit", _ctx)
            _x_x2677 = kk_string_dup(_s_x2678, _ctx); /*string*/
            _x_x2676 = kk_string_box(_x_x2677); /*45*/
            _x_x2673 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x1198, (_fun_unbox_x1198, m_0, ev_0_10943, _x_x2676, _ctx), _ctx); /*46*/
          }
        }
      }
      x_1_10940 = kk_std_core_types__list_unbox(_x_x2673, KK_OWNED, _ctx); /*list<char>*/
    }
    else {
      kk_box_t _box_x1202 = x_10934._cons.Just.value;
      kk_std_core_types__list x_0_0 = kk_std_core_types__list_unbox(_box_x1202, KK_BORROWED, _ctx);
      kk_std_core_types__list_dup(x_0_0, _ctx);
      kk_std_core_types__maybe_drop(x_10934, _ctx);
      x_1_10940 = x_0_0; /*list<char>*/
    }
    if (kk_yielding(kk_context())) {
      kk_std_core_types__list_drop(x_1_10940, _ctx);
      kk_box_t _x_x2679 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_pnat_fun2680(_ctx), _ctx); /*2419*/
      return kk_integer_unbox(_x_x2679, _ctx);
    }
    {
      kk_string_t _x_x1_0_10538 = kk_std_core_string_listchar_fs_string(x_1_10940, _ctx); /*string*/;
      kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
      kk_std_core_types__maybe x_3;
      bool _x_x2683;
      kk_std_core_types__optional _match_x1835 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
      if (kk_std_core_types__is_Optional(_match_x1835, _ctx)) {
        kk_box_t _box_x1205 = _match_x1835._cons._Optional.value;
        bool _uniq_hex_581 = kk_bool_unbox(_box_x1205);
        kk_std_core_types__optional_drop(_match_x1835, _ctx);
        _x_x2683 = _uniq_hex_581; /*bool*/
      }
      else {
        kk_std_core_types__optional_drop(_match_x1835, _ctx);
        _x_x2683 = false; /*bool*/
      }
      x_3 = kk_std_core_int_xparse(_x_x1_0_10538, _x_x2683, _ctx); /*maybe<int>*/
      kk_unit_t keep = kk_Unit;
      kk_evv_set(w,kk_context());
      kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
      kk_unit_t keep_0 = kk_Unit;
      kk_evv_set(w_0,kk_context());
      if (kk_std_core_types__is_Nothing(x_3, _ctx)) {
        return kk_integer_from_small(0);
      }
      {
        kk_box_t _box_x1206 = x_3._cons.Just.value;
        kk_integer_t x_5 = kk_integer_unbox(_box_x1206, _ctx);
        kk_integer_dup(x_5, _ctx);
        kk_std_core_types__maybe_drop(x_3, _ctx);
        return x_5;
      }
    }
  }
}
 
// monadic lift

kk_char_t kk_std_text_parse__mlift_none_of_10580(kk_std_core_types__maybe _y_x10465, kk_context_t* _ctx) { /* (maybe<char>) -> parse char */ 
  if (kk_std_core_types__is_Nothing(_y_x10465, _ctx)) {
    kk_std_core_hnd__ev ev_10952 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
    kk_box_t _x_x2684;
    {
      struct kk_std_core_hnd_Ev* _con_x2685 = kk_std_core_hnd__as_Ev(ev_10952, _ctx);
      kk_box_t _box_x1209 = _con_x2685->hnd;
      int32_t m = _con_x2685->marker;
      kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x1209, KK_BORROWED, _ctx);
      kk_std_text_parse__parse_dup(h, _ctx);
      {
        struct kk_std_text_parse__Hnd_parse* _con_x2686 = kk_std_text_parse__as_Hnd_parse(h, _ctx);
        kk_integer_t _pat_0_1 = _con_x2686->_cfc;
        kk_std_core_hnd__clause0 _pat_1_0 = _con_x2686->_fun_current_input;
        kk_std_core_hnd__clause1 _brk_fail = _con_x2686->_brk_fail;
        kk_std_core_hnd__clause0 _pat_2_0 = _con_x2686->_ctl_pick;
        kk_std_core_hnd__clause1 _pat_3 = _con_x2686->_fun_satisfy;
        if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
          kk_std_core_hnd__clause1_drop(_pat_3, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_2_0, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_1_0, _ctx);
          kk_integer_drop(_pat_0_1, _ctx);
          kk_datatype_ptr_free(h, _ctx);
        }
        else {
          kk_std_core_hnd__clause1_dup(_brk_fail, _ctx);
          kk_datatype_ptr_decref(h, _ctx);
        }
        {
          kk_function_t _fun_unbox_x1213 = _brk_fail.clause;
          kk_box_t _x_x2687;
          kk_string_t _x_x2688 = kk_string_empty(); /*string*/
          _x_x2687 = kk_string_box(_x_x2688); /*45*/
          _x_x2684 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x1213, (_fun_unbox_x1213, m, ev_10952, _x_x2687, _ctx), _ctx); /*46*/
        }
      }
    }
    return kk_char_unbox(_x_x2684, KK_OWNED, _ctx);
  }
  {
    kk_box_t _box_x1217 = _y_x10465._cons.Just.value;
    kk_char_t x_0 = kk_char_unbox(_box_x1217, KK_BORROWED, _ctx);
    kk_std_core_types__maybe_drop(_y_x10465, _ctx);
    return x_0;
  }
}


// lift anonymous function
struct kk_std_text_parse_none_of_fun2693__t {
  struct kk_function_s _base;
  kk_string_t chars;
};
static kk_box_t kk_std_text_parse_none_of_fun2693(kk_function_t _fself, kk_box_t _b_x1231, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_none_of_fun2693(kk_string_t chars, kk_context_t* _ctx) {
  struct kk_std_text_parse_none_of_fun2693__t* _self = kk_function_alloc_as(struct kk_std_text_parse_none_of_fun2693__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_text_parse_none_of_fun2693, kk_context());
  _self->chars = chars;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_text_parse_none_of_fun2693(kk_function_t _fself, kk_box_t _b_x1231, kk_context_t* _ctx) {
  struct kk_std_text_parse_none_of_fun2693__t* _self = kk_function_as(struct kk_std_text_parse_none_of_fun2693__t*, _fself, _ctx);
  kk_string_t chars = _self->chars; /* string */
  kk_drop_match(_self, {kk_string_dup(chars, _ctx);}, {}, _ctx)
  kk_std_core_types__maybe _x_x2694;
  kk_std_core_types__maybe _match_x1832;
  kk_std_core_sslice__sslice _x_x2695 = kk_std_core_sslice__sslice_unbox(_b_x1231, KK_OWNED, _ctx); /*sslice/sslice*/
  _match_x1832 = kk_std_core_sslice_next(_x_x2695, _ctx); /*maybe<(char, sslice/sslice)>*/
  if (kk_std_core_types__is_Just(_match_x1832, _ctx)) {
    kk_box_t _box_x1232 = _match_x1832._cons.Just.value;
    kk_std_core_types__tuple2 _pat_0_0_0 = kk_std_core_types__tuple2_unbox(_box_x1232, KK_BORROWED, _ctx);
    if (kk_std_core_types__is_Tuple2(_pat_0_0_0, _ctx)) {
      kk_box_t _box_x1233 = _pat_0_0_0.fst;
      kk_box_t _box_x1234 = _pat_0_0_0.snd;
      kk_char_t c = kk_char_unbox(_box_x1233, KK_BORROWED, _ctx);
      bool b_10109;
      kk_string_t _x_x2697 = kk_string_dup(chars, _ctx); /*string*/
      kk_string_t _x_x2698 = kk_std_core_string_char_fs_string(c, _ctx); /*string*/
      b_10109 = kk_string_contains(_x_x2697,_x_x2698,kk_context()); /*bool*/
      bool _x_x2699;
      if (b_10109) {
        _x_x2699 = false; /*bool*/
      }
      else {
        _x_x2699 = true; /*bool*/
      }
      if (_x_x2699) {
        kk_std_core_sslice__sslice rest = kk_std_core_sslice__sslice_unbox(_box_x1234, KK_BORROWED, _ctx);
        kk_string_drop(chars, _ctx);
        kk_std_core_sslice__sslice_dup(rest, _ctx);
        kk_std_core_types__maybe_drop(_match_x1832, _ctx);
        kk_box_t _x_x2700;
        kk_std_core_types__tuple2 _x_x2701 = kk_std_core_types__new_Tuple2(kk_char_box(c, _ctx), kk_std_core_sslice__sslice_box(rest, _ctx), _ctx); /*(134, 135)*/
        _x_x2700 = kk_std_core_types__tuple2_box(_x_x2701, _ctx); /*88*/
        _x_x2694 = kk_std_core_types__new_Just(_x_x2700, _ctx); /*maybe<88>*/
        goto _match_x2696;
      }
    }
  }
  {
    kk_string_drop(chars, _ctx);
    kk_std_core_types__maybe_drop(_match_x1832, _ctx);
    _x_x2694 = kk_std_core_types__new_Nothing(_ctx); /*maybe<88>*/
  }
  _match_x2696: ;
  return kk_std_core_types__maybe_box(_x_x2694, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_none_of_fun2703__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_none_of_fun2703(kk_function_t _fself, kk_box_t _b_x1243, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_none_of_fun2703(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_none_of_fun2703, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_text_parse_none_of_fun2703(kk_function_t _fself, kk_box_t _b_x1243, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t _x_x2704;
  kk_std_core_types__maybe _x_x2705 = kk_std_core_types__maybe_unbox(_b_x1243, KK_OWNED, _ctx); /*maybe<char>*/
  _x_x2704 = kk_std_text_parse__mlift_none_of_10580(_x_x2705, _ctx); /*char*/
  return kk_char_box(_x_x2704, _ctx);
}

kk_char_t kk_std_text_parse_none_of(kk_string_t chars, kk_context_t* _ctx) { /* (chars : string) -> parse char */ 
  kk_std_core_hnd__ev ev_10958 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
  kk_std_core_types__maybe x_10955;
  kk_box_t _x_x2690;
  {
    struct kk_std_core_hnd_Ev* _con_x2691 = kk_std_core_hnd__as_Ev(ev_10958, _ctx);
    kk_box_t _box_x1218 = _con_x2691->hnd;
    int32_t m = _con_x2691->marker;
    kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x1218, KK_BORROWED, _ctx);
    kk_std_text_parse__parse_dup(h, _ctx);
    {
      struct kk_std_text_parse__Hnd_parse* _con_x2692 = kk_std_text_parse__as_Hnd_parse(h, _ctx);
      kk_integer_t _pat_0 = _con_x2692->_cfc;
      kk_std_core_hnd__clause0 _pat_1_1 = _con_x2692->_fun_current_input;
      kk_std_core_hnd__clause1 _pat_2 = _con_x2692->_brk_fail;
      kk_std_core_hnd__clause0 _pat_3 = _con_x2692->_ctl_pick;
      kk_std_core_hnd__clause1 _fun_satisfy = _con_x2692->_fun_satisfy;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause0_drop(_pat_3, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_2, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_1_1, _ctx);
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_fun_satisfy, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x1225 = _fun_satisfy.clause;
        _x_x2690 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x1225, (_fun_unbox_x1225, m, ev_10958, kk_function_box(kk_std_text_parse_new_none_of_fun2693(chars, _ctx), _ctx), _ctx), _ctx); /*46*/
      }
    }
  }
  x_10955 = kk_std_core_types__maybe_unbox(_x_x2690, KK_OWNED, _ctx); /*maybe<char>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__maybe_drop(x_10955, _ctx);
    kk_box_t _x_x2702 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_none_of_fun2703(_ctx), _ctx); /*2419*/
    return kk_char_unbox(_x_x2702, KK_OWNED, _ctx);
  }
  if (kk_std_core_types__is_Nothing(x_10955, _ctx)) {
    kk_std_core_hnd__ev ev_0_10961 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
    kk_box_t _x_x2706;
    {
      struct kk_std_core_hnd_Ev* _con_x2707 = kk_std_core_hnd__as_Ev(ev_0_10961, _ctx);
      kk_box_t _box_x1244 = _con_x2707->hnd;
      int32_t m_0 = _con_x2707->marker;
      kk_std_text_parse__parse h_0 = kk_std_text_parse__parse_unbox(_box_x1244, KK_BORROWED, _ctx);
      kk_std_text_parse__parse_dup(h_0, _ctx);
      {
        struct kk_std_text_parse__Hnd_parse* _con_x2708 = kk_std_text_parse__as_Hnd_parse(h_0, _ctx);
        kk_integer_t _pat_0_3 = _con_x2708->_cfc;
        kk_std_core_hnd__clause0 _pat_1_3 = _con_x2708->_fun_current_input;
        kk_std_core_hnd__clause1 _brk_fail = _con_x2708->_brk_fail;
        kk_std_core_hnd__clause0 _pat_2_1 = _con_x2708->_ctl_pick;
        kk_std_core_hnd__clause1 _pat_3_1 = _con_x2708->_fun_satisfy;
        if kk_likely(kk_datatype_ptr_is_unique(h_0, _ctx)) {
          kk_std_core_hnd__clause1_drop(_pat_3_1, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_2_1, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_1_3, _ctx);
          kk_integer_drop(_pat_0_3, _ctx);
          kk_datatype_ptr_free(h_0, _ctx);
        }
        else {
          kk_std_core_hnd__clause1_dup(_brk_fail, _ctx);
          kk_datatype_ptr_decref(h_0, _ctx);
        }
        {
          kk_function_t _fun_unbox_x1248 = _brk_fail.clause;
          kk_box_t _x_x2709;
          kk_string_t _x_x2710 = kk_string_empty(); /*string*/
          _x_x2709 = kk_string_box(_x_x2710); /*45*/
          _x_x2706 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x1248, (_fun_unbox_x1248, m_0, ev_0_10961, _x_x2709, _ctx), _ctx); /*46*/
        }
      }
    }
    return kk_char_unbox(_x_x2706, KK_OWNED, _ctx);
  }
  {
    kk_box_t _box_x1252 = x_10955._cons.Just.value;
    kk_char_t x_2 = kk_char_unbox(_box_x1252, KK_BORROWED, _ctx);
    kk_std_core_types__maybe_drop(x_10955, _ctx);
    return x_2;
  }
}
 
// lifted local: none-of-many1, @spec-x10329
// specialized: std/text/parse/next-while0, on parameters @uniq-pred@10320, using:
// @uniq-pred@10320 = fn(c: char){
//   val b@10116 : bool
//         = std/core/string/contains(chars, (std/core/string/char/string(c)));
//   match (b@10116) {
//     ((std/core/types/True() : bool ) as @pat@9: bool)
//        -> std/core/types/False;
//     ((@skip std/core/types/False() : bool ) as @pat@0@1: bool)
//        -> std/core/types/True;
//   };
// }

kk_std_core_types__tuple2 kk_std_text_parse__lift_none_of_many1_10358(kk_string_t chars, kk_std_core_sslice__sslice _uniq_slice_10319, kk_std_core_types__list _uniq_acc_10321, kk_context_t* _ctx) { /* (chars : string, sslice/sslice, list<char>) -> (list<char>, sslice/sslice) */ 
  kk__tailcall: ;
  kk_std_core_types__maybe _match_x1830;
  kk_std_core_sslice__sslice _x_x2712 = kk_std_core_sslice__sslice_dup(_uniq_slice_10319, _ctx); /*sslice/sslice*/
  _match_x1830 = kk_std_core_sslice_next(_x_x2712, _ctx); /*maybe<(char, sslice/sslice)>*/
  if (kk_std_core_types__is_Just(_match_x1830, _ctx)) {
    kk_box_t _box_x1254 = _match_x1830._cons.Just.value;
    kk_std_core_types__tuple2 _uniq_pat_0_10323 = kk_std_core_types__tuple2_unbox(_box_x1254, KK_BORROWED, _ctx);
    if (kk_std_core_types__is_Tuple2(_uniq_pat_0_10323, _ctx)) {
      kk_box_t _box_x1255 = _uniq_pat_0_10323.fst;
      kk_box_t _box_x1256 = _uniq_pat_0_10323.snd;
      kk_char_t _uniq_c_10324 = kk_char_unbox(_box_x1255, KK_BORROWED, _ctx);
      bool b_10116;
      kk_string_t _x_x2713 = kk_string_dup(chars, _ctx); /*string*/
      kk_string_t _x_x2714 = kk_std_core_string_char_fs_string(_uniq_c_10324, _ctx); /*string*/
      b_10116 = kk_string_contains(_x_x2713,_x_x2714,kk_context()); /*bool*/
      bool _x_x2715;
      if (b_10116) {
        _x_x2715 = false; /*bool*/
      }
      else {
        _x_x2715 = true; /*bool*/
      }
      if (_x_x2715) {
        kk_std_core_sslice__sslice _uniq_rest_10325 = kk_std_core_sslice__sslice_unbox(_box_x1256, KK_BORROWED, _ctx);
        kk_std_core_sslice__sslice_drop(_uniq_slice_10319, _ctx);
        kk_std_core_sslice__sslice_dup(_uniq_rest_10325, _ctx);
        kk_std_core_types__maybe_drop(_match_x1830, _ctx);
        { // tailcall
          kk_std_core_types__list _x_x2716 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_char_box(_uniq_c_10324, _ctx), _uniq_acc_10321, _ctx); /*list<79>*/
          _uniq_slice_10319 = _uniq_rest_10325;
          _uniq_acc_10321 = _x_x2716;
          goto kk__tailcall;
        }
      }
    }
  }
  {
    kk_string_drop(chars, _ctx);
    kk_std_core_types__maybe_drop(_match_x1830, _ctx);
    kk_std_core_types__list _b_x1259_1263;
    if (kk_std_core_types__is_Nil(_uniq_acc_10321, _ctx)) {
      _b_x1259_1263 = kk_std_core_types__new_Nil(_ctx); /*list<char>*/
    }
    else {
      _b_x1259_1263 = kk_std_core_list__unroll_reverse_acc_10003(kk_std_core_types__new_Nil(_ctx), _uniq_acc_10321, _ctx); /*list<char>*/
    }
    return kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(_b_x1259_1263, _ctx), kk_std_core_sslice__sslice_box(_uniq_slice_10319, _ctx), _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_text_parse__mlift_none_of_many1_10581_fun2724__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse__mlift_none_of_many1_10581_fun2724(kk_function_t _fself, kk_box_t _b_x1275, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse__new_mlift_none_of_many1_10581_fun2724(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse__mlift_none_of_many1_10581_fun2724, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_text_parse__mlift_none_of_many1_10581_fun2724(kk_function_t _fself, kk_box_t _b_x1275, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2725;
  kk_std_core_types__list _x_x2726 = kk_std_core_types__list_unbox(_b_x1275, KK_OWNED, _ctx); /*list<char>*/
  _x_x2725 = kk_std_core_string_listchar_fs_string(_x_x2726, _ctx); /*string*/
  return kk_string_box(_x_x2725);
}

kk_string_t kk_std_text_parse__mlift_none_of_many1_10581(kk_std_core_types__maybe _y_x10468, kk_context_t* _ctx) { /* (maybe<list<char>>) -> parse string */ 
  kk_std_core_types__list x_10964;
  if (kk_std_core_types__is_Nothing(_y_x10468, _ctx)) {
    kk_std_core_hnd__ev ev_10966 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
    kk_box_t _x_x2717;
    {
      struct kk_std_core_hnd_Ev* _con_x2718 = kk_std_core_hnd__as_Ev(ev_10966, _ctx);
      kk_box_t _box_x1265 = _con_x2718->hnd;
      int32_t m = _con_x2718->marker;
      kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x1265, KK_BORROWED, _ctx);
      kk_std_text_parse__parse_dup(h, _ctx);
      {
        struct kk_std_text_parse__Hnd_parse* _con_x2719 = kk_std_text_parse__as_Hnd_parse(h, _ctx);
        kk_integer_t _pat_0 = _con_x2719->_cfc;
        kk_std_core_hnd__clause0 _pat_1_1 = _con_x2719->_fun_current_input;
        kk_std_core_hnd__clause1 _brk_fail = _con_x2719->_brk_fail;
        kk_std_core_hnd__clause0 _pat_2_0 = _con_x2719->_ctl_pick;
        kk_std_core_hnd__clause1 _pat_3 = _con_x2719->_fun_satisfy;
        if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
          kk_std_core_hnd__clause1_drop(_pat_3, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_2_0, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_1_1, _ctx);
          kk_integer_drop(_pat_0, _ctx);
          kk_datatype_ptr_free(h, _ctx);
        }
        else {
          kk_std_core_hnd__clause1_dup(_brk_fail, _ctx);
          kk_datatype_ptr_decref(h, _ctx);
        }
        {
          kk_function_t _fun_unbox_x1269 = _brk_fail.clause;
          kk_box_t _x_x2720;
          kk_string_t _x_x2721 = kk_string_empty(); /*string*/
          _x_x2720 = kk_string_box(_x_x2721); /*45*/
          _x_x2717 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x1269, (_fun_unbox_x1269, m, ev_10966, _x_x2720, _ctx), _ctx); /*46*/
        }
      }
    }
    x_10964 = kk_std_core_types__list_unbox(_x_x2717, KK_OWNED, _ctx); /*list<char>*/
  }
  else {
    kk_box_t _box_x1273 = _y_x10468._cons.Just.value;
    kk_std_core_types__list x_1 = kk_std_core_types__list_unbox(_box_x1273, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(x_1, _ctx);
    kk_std_core_types__maybe_drop(_y_x10468, _ctx);
    x_10964 = x_1; /*list<char>*/
  }
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_10964, _ctx);
    kk_box_t _x_x2723 = kk_std_core_hnd_yield_extend(kk_std_text_parse__new_mlift_none_of_many1_10581_fun2724(_ctx), _ctx); /*2419*/
    return kk_string_unbox(_x_x2723);
  }
  {
    return kk_std_core_string_listchar_fs_string(x_10964, _ctx);
  }
}


// lift anonymous function
struct kk_std_text_parse_none_of_many1_fun2730__t {
  struct kk_function_s _base;
  kk_string_t chars;
};
static kk_box_t kk_std_text_parse_none_of_many1_fun2730(kk_function_t _fself, kk_box_t _b_x1290, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_none_of_many1_fun2730(kk_string_t chars, kk_context_t* _ctx) {
  struct kk_std_text_parse_none_of_many1_fun2730__t* _self = kk_function_alloc_as(struct kk_std_text_parse_none_of_many1_fun2730__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_text_parse_none_of_many1_fun2730, kk_context());
  _self->chars = chars;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_text_parse_none_of_many1_fun2730(kk_function_t _fself, kk_box_t _b_x1290, kk_context_t* _ctx) {
  struct kk_std_text_parse_none_of_many1_fun2730__t* _self = kk_function_as(struct kk_std_text_parse_none_of_many1_fun2730__t*, _fself, _ctx);
  kk_string_t chars = _self->chars; /* string */
  kk_drop_match(_self, {kk_string_dup(chars, _ctx);}, {}, _ctx)
  kk_std_core_types__maybe _x_x2731;
  kk_std_core_types__tuple2 _match_x1828;
  kk_std_core_sslice__sslice _x_x2732 = kk_std_core_sslice__sslice_unbox(_b_x1290, KK_OWNED, _ctx); /*sslice/sslice*/
  _match_x1828 = kk_std_text_parse__lift_none_of_many1_10358(chars, _x_x2732, kk_std_core_types__new_Nil(_ctx), _ctx); /*(list<char>, sslice/sslice)*/
  {
    kk_box_t _box_x1291 = _match_x1828.fst;
    kk_box_t _box_x1292 = _match_x1828.snd;
    kk_std_core_types__list _pat_0_0_0 = kk_std_core_types__list_unbox(_box_x1291, KK_BORROWED, _ctx);
    kk_std_core_sslice__sslice _pat_1_0_0 = kk_std_core_sslice__sslice_unbox(_box_x1292, KK_BORROWED, _ctx);
    if (kk_std_core_types__is_Nil(_pat_0_0_0, _ctx)) {
      kk_std_core_types__tuple2_drop(_match_x1828, _ctx);
      _x_x2731 = kk_std_core_types__new_Nothing(_ctx); /*forall<a> maybe<a>*/
      goto _match_x2733;
    }
  }
  {
    kk_box_t _box_x1293 = _match_x1828.fst;
    kk_box_t _box_x1294 = _match_x1828.snd;
    kk_std_core_sslice__sslice rest = kk_std_core_sslice__sslice_unbox(_box_x1294, KK_BORROWED, _ctx);
    kk_std_core_types__list xs = kk_std_core_types__list_unbox(_box_x1293, KK_BORROWED, _ctx);
    kk_std_core_sslice__sslice_dup(rest, _ctx);
    kk_std_core_types__list_dup(xs, _ctx);
    kk_std_core_types__tuple2_drop(_match_x1828, _ctx);
    kk_box_t _x_x2734;
    kk_std_core_types__tuple2 _x_x2735 = kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(xs, _ctx), kk_std_core_sslice__sslice_box(rest, _ctx), _ctx); /*(134, 135)*/
    _x_x2734 = kk_std_core_types__tuple2_box(_x_x2735, _ctx); /*88*/
    _x_x2731 = kk_std_core_types__new_Just(_x_x2734, _ctx); /*forall<a> maybe<a>*/
  }
  _match_x2733: ;
  return kk_std_core_types__maybe_box(_x_x2731, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_none_of_many1_fun2737__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_none_of_many1_fun2737(kk_function_t _fself, kk_box_t _b_x1303, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_none_of_many1_fun2737(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_none_of_many1_fun2737, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_text_parse_none_of_many1_fun2737(kk_function_t _fself, kk_box_t _b_x1303, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2738;
  kk_std_core_types__maybe _x_x2739 = kk_std_core_types__maybe_unbox(_b_x1303, KK_OWNED, _ctx); /*maybe<list<char>>*/
  _x_x2738 = kk_std_text_parse__mlift_none_of_many1_10581(_x_x2739, _ctx); /*string*/
  return kk_string_box(_x_x2738);
}


// lift anonymous function
struct kk_std_text_parse_none_of_many1_fun2747__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_none_of_many1_fun2747(kk_function_t _fself, kk_box_t _b_x1314, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_none_of_many1_fun2747(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_none_of_many1_fun2747, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_text_parse_none_of_many1_fun2747(kk_function_t _fself, kk_box_t _b_x1314, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x2748;
  kk_std_core_types__list _x_x2749 = kk_std_core_types__list_unbox(_b_x1314, KK_OWNED, _ctx); /*list<char>*/
  _x_x2748 = kk_std_core_string_listchar_fs_string(_x_x2749, _ctx); /*string*/
  return kk_string_box(_x_x2748);
}

kk_string_t kk_std_text_parse_none_of_many1(kk_string_t chars, kk_context_t* _ctx) { /* (chars : string) -> parse string */ 
  kk_std_core_hnd__ev ev_10972 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
  kk_std_core_types__maybe x_10969;
  kk_box_t _x_x2727;
  {
    struct kk_std_core_hnd_Ev* _con_x2728 = kk_std_core_hnd__as_Ev(ev_10972, _ctx);
    kk_box_t _box_x1277 = _con_x2728->hnd;
    int32_t m = _con_x2728->marker;
    kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x1277, KK_BORROWED, _ctx);
    kk_std_text_parse__parse_dup(h, _ctx);
    {
      struct kk_std_text_parse__Hnd_parse* _con_x2729 = kk_std_text_parse__as_Hnd_parse(h, _ctx);
      kk_integer_t _pat_0 = _con_x2729->_cfc;
      kk_std_core_hnd__clause0 _pat_1_1 = _con_x2729->_fun_current_input;
      kk_std_core_hnd__clause1 _pat_2 = _con_x2729->_brk_fail;
      kk_std_core_hnd__clause0 _pat_3 = _con_x2729->_ctl_pick;
      kk_std_core_hnd__clause1 _fun_satisfy = _con_x2729->_fun_satisfy;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause0_drop(_pat_3, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_2, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_1_1, _ctx);
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_fun_satisfy, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x1284 = _fun_satisfy.clause;
        _x_x2727 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x1284, (_fun_unbox_x1284, m, ev_10972, kk_function_box(kk_std_text_parse_new_none_of_many1_fun2730(chars, _ctx), _ctx), _ctx), _ctx); /*46*/
      }
    }
  }
  x_10969 = kk_std_core_types__maybe_unbox(_x_x2727, KK_OWNED, _ctx); /*maybe<list<char>>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__maybe_drop(x_10969, _ctx);
    kk_box_t _x_x2736 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_none_of_many1_fun2737(_ctx), _ctx); /*2419*/
    return kk_string_unbox(_x_x2736);
  }
  {
    kk_std_core_types__list x_1_10975;
    if (kk_std_core_types__is_Nothing(x_10969, _ctx)) {
      kk_std_core_hnd__ev ev_0_10977 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
      kk_box_t _x_x2740;
      {
        struct kk_std_core_hnd_Ev* _con_x2741 = kk_std_core_hnd__as_Ev(ev_0_10977, _ctx);
        kk_box_t _box_x1304 = _con_x2741->hnd;
        int32_t m_0 = _con_x2741->marker;
        kk_std_text_parse__parse h_0 = kk_std_text_parse__parse_unbox(_box_x1304, KK_BORROWED, _ctx);
        kk_std_text_parse__parse_dup(h_0, _ctx);
        {
          struct kk_std_text_parse__Hnd_parse* _con_x2742 = kk_std_text_parse__as_Hnd_parse(h_0, _ctx);
          kk_integer_t _pat_0_3 = _con_x2742->_cfc;
          kk_std_core_hnd__clause0 _pat_1_3 = _con_x2742->_fun_current_input;
          kk_std_core_hnd__clause1 _brk_fail = _con_x2742->_brk_fail;
          kk_std_core_hnd__clause0 _pat_2_1 = _con_x2742->_ctl_pick;
          kk_std_core_hnd__clause1 _pat_3_1 = _con_x2742->_fun_satisfy;
          if kk_likely(kk_datatype_ptr_is_unique(h_0, _ctx)) {
            kk_std_core_hnd__clause1_drop(_pat_3_1, _ctx);
            kk_std_core_hnd__clause0_drop(_pat_2_1, _ctx);
            kk_std_core_hnd__clause0_drop(_pat_1_3, _ctx);
            kk_integer_drop(_pat_0_3, _ctx);
            kk_datatype_ptr_free(h_0, _ctx);
          }
          else {
            kk_std_core_hnd__clause1_dup(_brk_fail, _ctx);
            kk_datatype_ptr_decref(h_0, _ctx);
          }
          {
            kk_function_t _fun_unbox_x1308 = _brk_fail.clause;
            kk_box_t _x_x2743;
            kk_string_t _x_x2744 = kk_string_empty(); /*string*/
            _x_x2743 = kk_string_box(_x_x2744); /*45*/
            _x_x2740 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x1308, (_fun_unbox_x1308, m_0, ev_0_10977, _x_x2743, _ctx), _ctx); /*46*/
          }
        }
      }
      x_1_10975 = kk_std_core_types__list_unbox(_x_x2740, KK_OWNED, _ctx); /*list<char>*/
    }
    else {
      kk_box_t _box_x1312 = x_10969._cons.Just.value;
      kk_std_core_types__list x_3 = kk_std_core_types__list_unbox(_box_x1312, KK_BORROWED, _ctx);
      kk_std_core_types__list_dup(x_3, _ctx);
      kk_std_core_types__maybe_drop(x_10969, _ctx);
      x_1_10975 = x_3; /*list<char>*/
    }
    if (kk_yielding(kk_context())) {
      kk_std_core_types__list_drop(x_1_10975, _ctx);
      kk_box_t _x_x2746 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_none_of_many1_fun2747(_ctx), _ctx); /*2419*/
      return kk_string_unbox(_x_x2746);
    }
    {
      return kk_std_core_string_listchar_fs_string(x_1_10975, _ctx);
    }
  }
}
 
// monadic lift

kk_char_t kk_std_text_parse__mlift_one_of_10582(kk_string_t chars, kk_std_core_types__maybe _y_x10471, kk_context_t* _ctx) { /* (chars : string, maybe<char>) -> parse char */ 
  if (kk_std_core_types__is_Nothing(_y_x10471, _ctx)) {
    kk_std_core_hnd__ev ev_10980 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
    kk_box_t _x_x2750;
    {
      struct kk_std_core_hnd_Ev* _con_x2751 = kk_std_core_hnd__as_Ev(ev_10980, _ctx);
      kk_box_t _box_x1317 = _con_x2751->hnd;
      int32_t m = _con_x2751->marker;
      kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x1317, KK_BORROWED, _ctx);
      kk_std_text_parse__parse_dup(h, _ctx);
      {
        struct kk_std_text_parse__Hnd_parse* _con_x2752 = kk_std_text_parse__as_Hnd_parse(h, _ctx);
        kk_integer_t _pat_0_1 = _con_x2752->_cfc;
        kk_std_core_hnd__clause0 _pat_1_0 = _con_x2752->_fun_current_input;
        kk_std_core_hnd__clause1 _brk_fail = _con_x2752->_brk_fail;
        kk_std_core_hnd__clause0 _pat_2_0 = _con_x2752->_ctl_pick;
        kk_std_core_hnd__clause1 _pat_3 = _con_x2752->_fun_satisfy;
        if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
          kk_std_core_hnd__clause1_drop(_pat_3, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_2_0, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_1_0, _ctx);
          kk_integer_drop(_pat_0_1, _ctx);
          kk_datatype_ptr_free(h, _ctx);
        }
        else {
          kk_std_core_hnd__clause1_dup(_brk_fail, _ctx);
          kk_datatype_ptr_decref(h, _ctx);
        }
        {
          kk_function_t _fun_unbox_x1321 = _brk_fail.clause;
          _x_x2750 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x1321, (_fun_unbox_x1321, m, ev_10980, kk_string_box(chars), _ctx), _ctx); /*46*/
        }
      }
    }
    return kk_char_unbox(_x_x2750, KK_OWNED, _ctx);
  }
  {
    kk_box_t _box_x1325 = _y_x10471._cons.Just.value;
    kk_char_t x_0 = kk_char_unbox(_box_x1325, KK_BORROWED, _ctx);
    kk_string_drop(chars, _ctx);
    kk_std_core_types__maybe_drop(_y_x10471, _ctx);
    return x_0;
  }
}


// lift anonymous function
struct kk_std_text_parse_one_of_fun2758__t {
  struct kk_function_s _base;
  kk_string_t chars;
};
static kk_box_t kk_std_text_parse_one_of_fun2758(kk_function_t _fself, kk_box_t _b_x1339, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_one_of_fun2758(kk_string_t chars, kk_context_t* _ctx) {
  struct kk_std_text_parse_one_of_fun2758__t* _self = kk_function_alloc_as(struct kk_std_text_parse_one_of_fun2758__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_text_parse_one_of_fun2758, kk_context());
  _self->chars = chars;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_text_parse_one_of_fun2758(kk_function_t _fself, kk_box_t _b_x1339, kk_context_t* _ctx) {
  struct kk_std_text_parse_one_of_fun2758__t* _self = kk_function_as(struct kk_std_text_parse_one_of_fun2758__t*, _fself, _ctx);
  kk_string_t chars = _self->chars; /* string */
  kk_drop_match(_self, {kk_string_dup(chars, _ctx);}, {}, _ctx)
  kk_std_core_types__maybe _x_x2759;
  kk_std_core_types__maybe _match_x1825;
  kk_std_core_sslice__sslice _x_x2760 = kk_std_core_sslice__sslice_unbox(_b_x1339, KK_OWNED, _ctx); /*sslice/sslice*/
  _match_x1825 = kk_std_core_sslice_next(_x_x2760, _ctx); /*maybe<(char, sslice/sslice)>*/
  if (kk_std_core_types__is_Just(_match_x1825, _ctx)) {
    kk_box_t _box_x1340 = _match_x1825._cons.Just.value;
    kk_std_core_types__tuple2 _pat_0_0_0 = kk_std_core_types__tuple2_unbox(_box_x1340, KK_BORROWED, _ctx);
    if (kk_std_core_types__is_Tuple2(_pat_0_0_0, _ctx)) {
      kk_box_t _box_x1341 = _pat_0_0_0.fst;
      kk_box_t _box_x1342 = _pat_0_0_0.snd;
      kk_char_t c = kk_char_unbox(_box_x1341, KK_BORROWED, _ctx);
      kk_string_t _x_x2762 = kk_string_dup(chars, _ctx); /*string*/
      kk_string_t _x_x2763 = kk_std_core_string_char_fs_string(c, _ctx); /*string*/
      if (kk_string_contains(_x_x2762,_x_x2763,kk_context())) {
        kk_std_core_sslice__sslice rest = kk_std_core_sslice__sslice_unbox(_box_x1342, KK_BORROWED, _ctx);
        kk_string_drop(chars, _ctx);
        kk_std_core_sslice__sslice_dup(rest, _ctx);
        kk_std_core_types__maybe_drop(_match_x1825, _ctx);
        kk_box_t _x_x2764;
        kk_std_core_types__tuple2 _x_x2765 = kk_std_core_types__new_Tuple2(kk_char_box(c, _ctx), kk_std_core_sslice__sslice_box(rest, _ctx), _ctx); /*(134, 135)*/
        _x_x2764 = kk_std_core_types__tuple2_box(_x_x2765, _ctx); /*88*/
        _x_x2759 = kk_std_core_types__new_Just(_x_x2764, _ctx); /*maybe<88>*/
        goto _match_x2761;
      }
    }
  }
  {
    kk_string_drop(chars, _ctx);
    kk_std_core_types__maybe_drop(_match_x1825, _ctx);
    _x_x2759 = kk_std_core_types__new_Nothing(_ctx); /*maybe<88>*/
  }
  _match_x2761: ;
  return kk_std_core_types__maybe_box(_x_x2759, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_one_of_fun2767__t {
  struct kk_function_s _base;
  kk_string_t chars;
};
static kk_box_t kk_std_text_parse_one_of_fun2767(kk_function_t _fself, kk_box_t _b_x1351, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_one_of_fun2767(kk_string_t chars, kk_context_t* _ctx) {
  struct kk_std_text_parse_one_of_fun2767__t* _self = kk_function_alloc_as(struct kk_std_text_parse_one_of_fun2767__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_text_parse_one_of_fun2767, kk_context());
  _self->chars = chars;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_text_parse_one_of_fun2767(kk_function_t _fself, kk_box_t _b_x1351, kk_context_t* _ctx) {
  struct kk_std_text_parse_one_of_fun2767__t* _self = kk_function_as(struct kk_std_text_parse_one_of_fun2767__t*, _fself, _ctx);
  kk_string_t chars = _self->chars; /* string */
  kk_drop_match(_self, {kk_string_dup(chars, _ctx);}, {}, _ctx)
  kk_std_core_types__maybe _y_x10471_1362 = kk_std_core_types__maybe_unbox(_b_x1351, KK_OWNED, _ctx); /*maybe<char>*/;
  kk_char_t _x_x2768 = kk_std_text_parse__mlift_one_of_10582(chars, _y_x10471_1362, _ctx); /*char*/
  return kk_char_box(_x_x2768, _ctx);
}

kk_char_t kk_std_text_parse_one_of(kk_string_t chars, kk_context_t* _ctx) { /* (chars : string) -> parse char */ 
  kk_std_core_hnd__ev ev_10986 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
  kk_std_core_types__maybe x_10983;
  kk_box_t _x_x2753;
  {
    struct kk_std_core_hnd_Ev* _con_x2754 = kk_std_core_hnd__as_Ev(ev_10986, _ctx);
    kk_box_t _box_x1326 = _con_x2754->hnd;
    int32_t m = _con_x2754->marker;
    kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x1326, KK_BORROWED, _ctx);
    kk_std_text_parse__parse_dup(h, _ctx);
    {
      struct kk_std_text_parse__Hnd_parse* _con_x2755 = kk_std_text_parse__as_Hnd_parse(h, _ctx);
      kk_integer_t _pat_0 = _con_x2755->_cfc;
      kk_std_core_hnd__clause0 _pat_1_1 = _con_x2755->_fun_current_input;
      kk_std_core_hnd__clause1 _pat_2 = _con_x2755->_brk_fail;
      kk_std_core_hnd__clause0 _pat_3 = _con_x2755->_ctl_pick;
      kk_std_core_hnd__clause1 _fun_satisfy = _con_x2755->_fun_satisfy;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause0_drop(_pat_3, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_2, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_1_1, _ctx);
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_fun_satisfy, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x1333 = _fun_satisfy.clause;
        kk_box_t _x_x2756;
        kk_function_t _x_x2757;
        kk_string_dup(chars, _ctx);
        _x_x2757 = kk_std_text_parse_new_one_of_fun2758(chars, _ctx); /*(1337) -> 1338*/
        _x_x2756 = kk_function_box(_x_x2757, _ctx); /*45*/
        _x_x2753 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x1333, (_fun_unbox_x1333, m, ev_10986, _x_x2756, _ctx), _ctx); /*46*/
      }
    }
  }
  x_10983 = kk_std_core_types__maybe_unbox(_x_x2753, KK_OWNED, _ctx); /*maybe<char>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__maybe_drop(x_10983, _ctx);
    kk_box_t _x_x2766 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_one_of_fun2767(chars, _ctx), _ctx); /*2419*/
    return kk_char_unbox(_x_x2766, KK_OWNED, _ctx);
  }
  if (kk_std_core_types__is_Nothing(x_10983, _ctx)) {
    kk_std_core_hnd__ev ev_0_10989 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
    kk_box_t _x_x2769;
    {
      struct kk_std_core_hnd_Ev* _con_x2770 = kk_std_core_hnd__as_Ev(ev_0_10989, _ctx);
      kk_box_t _box_x1352 = _con_x2770->hnd;
      int32_t m_0 = _con_x2770->marker;
      kk_std_text_parse__parse h_0 = kk_std_text_parse__parse_unbox(_box_x1352, KK_BORROWED, _ctx);
      kk_std_text_parse__parse_dup(h_0, _ctx);
      {
        struct kk_std_text_parse__Hnd_parse* _con_x2771 = kk_std_text_parse__as_Hnd_parse(h_0, _ctx);
        kk_integer_t _pat_0_2 = _con_x2771->_cfc;
        kk_std_core_hnd__clause0 _pat_1_3 = _con_x2771->_fun_current_input;
        kk_std_core_hnd__clause1 _brk_fail = _con_x2771->_brk_fail;
        kk_std_core_hnd__clause0 _pat_2_1 = _con_x2771->_ctl_pick;
        kk_std_core_hnd__clause1 _pat_3_1 = _con_x2771->_fun_satisfy;
        if kk_likely(kk_datatype_ptr_is_unique(h_0, _ctx)) {
          kk_std_core_hnd__clause1_drop(_pat_3_1, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_2_1, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_1_3, _ctx);
          kk_integer_drop(_pat_0_2, _ctx);
          kk_datatype_ptr_free(h_0, _ctx);
        }
        else {
          kk_std_core_hnd__clause1_dup(_brk_fail, _ctx);
          kk_datatype_ptr_decref(h_0, _ctx);
        }
        {
          kk_function_t _fun_unbox_x1356 = _brk_fail.clause;
          _x_x2769 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x1356, (_fun_unbox_x1356, m_0, ev_0_10989, kk_string_box(chars), _ctx), _ctx); /*46*/
        }
      }
    }
    return kk_char_unbox(_x_x2769, KK_OWNED, _ctx);
  }
  {
    kk_box_t _box_x1360 = x_10983._cons.Just.value;
    kk_char_t x_2 = kk_char_unbox(_box_x1360, KK_BORROWED, _ctx);
    kk_std_core_types__maybe_drop(x_10983, _ctx);
    kk_string_drop(chars, _ctx);
    return x_2;
  }
}
 
// monadic lift

kk_std_core_types__list kk_std_text_parse__mlift_many_acc_10583(kk_std_core_types__list acc, kk_function_t p, kk_box_t x, kk_context_t* _ctx) { /* forall<a,e> (acc : list<a>, p : parser<e,a>, x : a) -> <parse|e> list<a> */ 
  kk_std_core_types__list _x_x2772 = kk_std_core_types__new_Cons(kk_reuse_null, 0, x, acc, _ctx); /*list<79>*/
  return kk_std_text_parse_many_acc(p, _x_x2772, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_text_parse__mlift_many_acc_10584_fun2775__t {
  struct kk_function_s _base;
  kk_std_core_types__list acc_0;
  kk_function_t p_0;
};
static kk_box_t kk_std_text_parse__mlift_many_acc_10584_fun2775(kk_function_t _fself, kk_box_t _b_x1364, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse__new_mlift_many_acc_10584_fun2775(kk_std_core_types__list acc_0, kk_function_t p_0, kk_context_t* _ctx) {
  struct kk_std_text_parse__mlift_many_acc_10584_fun2775__t* _self = kk_function_alloc_as(struct kk_std_text_parse__mlift_many_acc_10584_fun2775__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_text_parse__mlift_many_acc_10584_fun2775, kk_context());
  _self->acc_0 = acc_0;
  _self->p_0 = p_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_text_parse__mlift_many_acc_10584_fun2775(kk_function_t _fself, kk_box_t _b_x1364, kk_context_t* _ctx) {
  struct kk_std_text_parse__mlift_many_acc_10584_fun2775__t* _self = kk_function_as(struct kk_std_text_parse__mlift_many_acc_10584_fun2775__t*, _fself, _ctx);
  kk_std_core_types__list acc_0 = _self->acc_0; /* list<2723> */
  kk_function_t p_0 = _self->p_0; /* std/text/parse/parser<2724,2723> */
  kk_drop_match(_self, {kk_std_core_types__list_dup(acc_0, _ctx);kk_function_dup(p_0, _ctx);}, {}, _ctx)
  kk_box_t x_1_1366 = _b_x1364; /*2723*/;
  kk_std_core_types__list _x_x2776 = kk_std_text_parse__mlift_many_acc_10583(acc_0, p_0, x_1_1366, _ctx); /*list<2723>*/
  return kk_std_core_types__list_box(_x_x2776, _ctx);
}

kk_std_core_types__list kk_std_text_parse__mlift_many_acc_10584(kk_std_core_types__list acc_0, kk_function_t p_0, bool _y_x10475, kk_context_t* _ctx) { /* forall<a,e> (acc : list<a>, p : parser<e,a>, bool) -> <parse|e> list<a> */ 
  if (_y_x10475) {
    kk_box_t x_0_10992;
    kk_function_t _x_x2773 = kk_function_dup(p_0, _ctx); /*std/text/parse/parser<2724,2723>*/
    x_0_10992 = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), _x_x2773, (_x_x2773, _ctx), _ctx); /*2723*/
    if (kk_yielding(kk_context())) {
      kk_box_drop(x_0_10992, _ctx);
      kk_box_t _x_x2774 = kk_std_core_hnd_yield_extend(kk_std_text_parse__new_mlift_many_acc_10584_fun2775(acc_0, p_0, _ctx), _ctx); /*2419*/
      return kk_std_core_types__list_unbox(_x_x2774, KK_OWNED, _ctx);
    }
    {
      return kk_std_text_parse__mlift_many_acc_10583(acc_0, p_0, x_0_10992, _ctx);
    }
  }
  {
    kk_function_drop(p_0, _ctx);
    kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<std/text/parse/parse|2724>>*/;
    kk_std_core_types__list x_2;
    if (kk_std_core_types__is_Nil(acc_0, _ctx)) {
      x_2 = kk_std_core_types__new_Nil(_ctx); /*list<2723>*/
    }
    else {
      x_2 = kk_std_core_list__unroll_reverse_acc_10003(kk_std_core_types__new_Nil(_ctx), acc_0, _ctx); /*list<2723>*/
    }
    kk_unit_t keep = kk_Unit;
    kk_evv_set(w,kk_context());
    return x_2;
  }
}


// lift anonymous function
struct kk_std_text_parse_many_acc_fun2782__t {
  struct kk_function_s _base;
  kk_ssize_t i_10999;
};
static kk_box_t kk_std_text_parse_many_acc_fun2782(kk_function_t _fself, kk_function_t _b_x1378, kk_box_t _b_x1379, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_many_acc_fun2782(kk_ssize_t i_10999, kk_context_t* _ctx) {
  struct kk_std_text_parse_many_acc_fun2782__t* _self = kk_function_alloc_as(struct kk_std_text_parse_many_acc_fun2782__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_text_parse_many_acc_fun2782, kk_context());
  _self->i_10999 = i_10999;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_text_parse_many_acc_fun2782(kk_function_t _fself, kk_function_t _b_x1378, kk_box_t _b_x1379, kk_context_t* _ctx) {
  struct kk_std_text_parse_many_acc_fun2782__t* _self = kk_function_as(struct kk_std_text_parse_many_acc_fun2782__t*, _fself, _ctx);
  kk_ssize_t i_10999 = _self->i_10999; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_10999, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_10999, _b_x1378, _b_x1379, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_many_acc_fun2784__t {
  struct kk_function_s _base;
  kk_std_core_types__list acc_1;
  kk_function_t p_1;
};
static kk_box_t kk_std_text_parse_many_acc_fun2784(kk_function_t _fself, kk_box_t _b_x1388, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_many_acc_fun2784(kk_std_core_types__list acc_1, kk_function_t p_1, kk_context_t* _ctx) {
  struct kk_std_text_parse_many_acc_fun2784__t* _self = kk_function_alloc_as(struct kk_std_text_parse_many_acc_fun2784__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_text_parse_many_acc_fun2784, kk_context());
  _self->acc_1 = acc_1;
  _self->p_1 = p_1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_text_parse_many_acc_fun2784(kk_function_t _fself, kk_box_t _b_x1388, kk_context_t* _ctx) {
  struct kk_std_text_parse_many_acc_fun2784__t* _self = kk_function_as(struct kk_std_text_parse_many_acc_fun2784__t*, _fself, _ctx);
  kk_std_core_types__list acc_1 = _self->acc_1; /* list<2723> */
  kk_function_t p_1 = _self->p_1; /* std/text/parse/parser<2724,2723> */
  kk_drop_match(_self, {kk_std_core_types__list_dup(acc_1, _ctx);kk_function_dup(p_1, _ctx);}, {}, _ctx)
  bool _y_x10475_0_1394 = kk_bool_unbox(_b_x1388); /*bool*/;
  kk_std_core_types__list _x_x2785 = kk_std_text_parse__mlift_many_acc_10584(acc_1, p_1, _y_x10475_0_1394, _ctx); /*list<2723>*/
  return kk_std_core_types__list_box(_x_x2785, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_many_acc_fun2788__t {
  struct kk_function_s _base;
  kk_std_core_types__list acc_1;
  kk_function_t p_1;
};
static kk_box_t kk_std_text_parse_many_acc_fun2788(kk_function_t _fself, kk_box_t _b_x1390, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_many_acc_fun2788(kk_std_core_types__list acc_1, kk_function_t p_1, kk_context_t* _ctx) {
  struct kk_std_text_parse_many_acc_fun2788__t* _self = kk_function_alloc_as(struct kk_std_text_parse_many_acc_fun2788__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_text_parse_many_acc_fun2788, kk_context());
  _self->acc_1 = acc_1;
  _self->p_1 = p_1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_text_parse_many_acc_fun2788(kk_function_t _fself, kk_box_t _b_x1390, kk_context_t* _ctx) {
  struct kk_std_text_parse_many_acc_fun2788__t* _self = kk_function_as(struct kk_std_text_parse_many_acc_fun2788__t*, _fself, _ctx);
  kk_std_core_types__list acc_1 = _self->acc_1; /* list<2723> */
  kk_function_t p_1 = _self->p_1; /* std/text/parse/parser<2724,2723> */
  kk_drop_match(_self, {kk_std_core_types__list_dup(acc_1, _ctx);kk_function_dup(p_1, _ctx);}, {}, _ctx)
  kk_box_t x_5_1395 = _b_x1390; /*2723*/;
  kk_std_core_types__list _x_x2789 = kk_std_text_parse__mlift_many_acc_10583(acc_1, p_1, x_5_1395, _ctx); /*list<2723>*/
  return kk_std_core_types__list_box(_x_x2789, _ctx);
}

kk_std_core_types__list kk_std_text_parse_many_acc(kk_function_t p_1, kk_std_core_types__list acc_1, kk_context_t* _ctx) { /* forall<a,e> (p : parser<e,a>, acc : list<a>) -> <parse|e> list<a> */ 
  kk__tailcall: ;
  kk_ssize_t i_10999;
  kk_std_core_hnd__htag _x_x2777 = kk_std_core_hnd__htag_dup(kk_std_text_parse_parse_fs__tag, _ctx); /*hnd/htag<std/text/parse/parse>*/
  i_10999 = kk_std_core_hnd__evv_index(_x_x2777, _ctx); /*hnd/ev-index*/
  kk_evv_t w_0 = kk_evv_swap_create1(i_10999,kk_context()); /*hnd/evv<<std/text/parse/parse|2724>>*/;
  kk_std_core_hnd__ev ev_11001 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
  bool y;
  kk_box_t _x_x2778;
  {
    struct kk_std_core_hnd_Ev* _con_x2779 = kk_std_core_hnd__as_Ev(ev_11001, _ctx);
    kk_box_t _box_x1367 = _con_x2779->hnd;
    int32_t m = _con_x2779->marker;
    kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x1367, KK_BORROWED, _ctx);
    kk_std_text_parse__parse_dup(h, _ctx);
    {
      struct kk_std_text_parse__Hnd_parse* _con_x2780 = kk_std_text_parse__as_Hnd_parse(h, _ctx);
      kk_integer_t _pat_0_2 = _con_x2780->_cfc;
      kk_std_core_hnd__clause0 _pat_1_1 = _con_x2780->_fun_current_input;
      kk_std_core_hnd__clause1 _pat_2_0 = _con_x2780->_brk_fail;
      kk_std_core_hnd__clause0 _ctl_pick = _con_x2780->_ctl_pick;
      kk_std_core_hnd__clause1 _pat_3 = _con_x2780->_fun_satisfy;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause1_drop(_pat_3, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_2_0, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_1_1, _ctx);
        kk_integer_drop(_pat_0_2, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause0_dup(_ctl_pick, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x1370 = _ctl_pick.clause;
        _x_x2778 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x1370, (_fun_unbox_x1370, m, ev_11001, _ctx), _ctx); /*35*/
      }
    }
  }
  y = kk_bool_unbox(_x_x2778); /*bool*/
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w_0,kk_context());
  bool x_3_10996;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2781 = kk_std_core_hnd_yield_cont(kk_std_text_parse_new_many_acc_fun2782(i_10999, _ctx), _ctx); /*2568*/
    x_3_10996 = kk_bool_unbox(_x_x2781); /*bool*/
  }
  else {
    x_3_10996 = y; /*bool*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2783 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_many_acc_fun2784(acc_1, p_1, _ctx), _ctx); /*2419*/
    return kk_std_core_types__list_unbox(_x_x2783, KK_OWNED, _ctx);
  }
  if (x_3_10996) {
    kk_box_t x_4_11003;
    kk_function_t _x_x2786 = kk_function_dup(p_1, _ctx); /*std/text/parse/parser<2724,2723>*/
    x_4_11003 = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), _x_x2786, (_x_x2786, _ctx), _ctx); /*2723*/
    if (kk_yielding(kk_context())) {
      kk_box_drop(x_4_11003, _ctx);
      kk_box_t _x_x2787 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_many_acc_fun2788(acc_1, p_1, _ctx), _ctx); /*2419*/
      return kk_std_core_types__list_unbox(_x_x2787, KK_OWNED, _ctx);
    }
    { // tailcall
      kk_std_core_types__list _x_x2790 = kk_std_core_types__new_Cons(kk_reuse_null, 0, x_4_11003, acc_1, _ctx); /*list<79>*/
      acc_1 = _x_x2790;
      goto kk__tailcall;
    }
  }
  {
    kk_function_drop(p_1, _ctx);
    kk_evv_t w_1 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<std/text/parse/parse|2724>>*/;
    kk_std_core_types__list x_7;
    if (kk_std_core_types__is_Nil(acc_1, _ctx)) {
      x_7 = kk_std_core_types__new_Nil(_ctx); /*list<2723>*/
    }
    else {
      x_7 = kk_std_core_list__unroll_reverse_acc_10003(kk_std_core_types__new_Nil(_ctx), acc_1, _ctx); /*list<2723>*/
    }
    kk_unit_t keep_0 = kk_Unit;
    kk_evv_set(w_1,kk_context());
    return x_7;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_text_parse__mlift_many1_10586_fun2792__t {
  struct kk_function_s _base;
  kk_box_t _y_x10480;
};
static kk_box_t kk_std_text_parse__mlift_many1_10586_fun2792(kk_function_t _fself, kk_box_t _b_x1397, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse__new_mlift_many1_10586_fun2792(kk_box_t _y_x10480, kk_context_t* _ctx) {
  struct kk_std_text_parse__mlift_many1_10586_fun2792__t* _self = kk_function_alloc_as(struct kk_std_text_parse__mlift_many1_10586_fun2792__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_text_parse__mlift_many1_10586_fun2792, kk_context());
  _self->_y_x10480 = _y_x10480;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_text_parse__mlift_many1_10586_fun2792(kk_function_t _fself, kk_box_t _b_x1397, kk_context_t* _ctx) {
  struct kk_std_text_parse__mlift_many1_10586_fun2792__t* _self = kk_function_as(struct kk_std_text_parse__mlift_many1_10586_fun2792__t*, _fself, _ctx);
  kk_box_t _y_x10480 = _self->_y_x10480; /* 2791 */
  kk_drop_match(_self, {kk_box_dup(_y_x10480, _ctx);}, {}, _ctx)
  kk_std_core_types__list _y_x10481_1399 = kk_std_core_types__list_unbox(_b_x1397, KK_OWNED, _ctx); /*list<2791>*/;
  kk_std_core_types__list _x_x2793 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _y_x10480, _y_x10481_1399, _ctx); /*list<79>*/
  return kk_std_core_types__list_box(_x_x2793, _ctx);
}

kk_std_core_types__list kk_std_text_parse__mlift_many1_10586(kk_function_t p, kk_box_t _y_x10480, kk_context_t* _ctx) { /* forall<a,e> (p : parser<e,a>, a) -> <parse|e> list<a> */ 
  kk_std_core_types__list x_11008 = kk_std_text_parse_many_acc(p, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<2791>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_11008, _ctx);
    kk_box_t _x_x2791 = kk_std_core_hnd_yield_extend(kk_std_text_parse__new_mlift_many1_10586_fun2792(_y_x10480, _ctx), _ctx); /*2419*/
    return kk_std_core_types__list_unbox(_x_x2791, KK_OWNED, _ctx);
  }
  {
    return kk_std_core_types__new_Cons(kk_reuse_null, 0, _y_x10480, x_11008, _ctx);
  }
}
 
// The `many1` combinator parses `p` at least once and then until it fails, returning a list of the results of `p`.
// The `many1` combinator is non-divergent only when `p` always consumes input or `fail`s.


// lift anonymous function
struct kk_std_text_parse_many1_fun2796__t {
  struct kk_function_s _base;
  kk_function_t p;
};
static kk_box_t kk_std_text_parse_many1_fun2796(kk_function_t _fself, kk_box_t _b_x1401, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_many1_fun2796(kk_function_t p, kk_context_t* _ctx) {
  struct kk_std_text_parse_many1_fun2796__t* _self = kk_function_alloc_as(struct kk_std_text_parse_many1_fun2796__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_text_parse_many1_fun2796, kk_context());
  _self->p = p;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_text_parse_many1_fun2796(kk_function_t _fself, kk_box_t _b_x1401, kk_context_t* _ctx) {
  struct kk_std_text_parse_many1_fun2796__t* _self = kk_function_as(struct kk_std_text_parse_many1_fun2796__t*, _fself, _ctx);
  kk_function_t p = _self->p; /* std/text/parse/parser<2792,2791> */
  kk_drop_match(_self, {kk_function_dup(p, _ctx);}, {}, _ctx)
  kk_box_t _y_x10480_1406 = _b_x1401; /*2791*/;
  kk_std_core_types__list _x_x2797 = kk_std_text_parse__mlift_many1_10586(p, _y_x10480_1406, _ctx); /*list<2791>*/
  return kk_std_core_types__list_box(_x_x2797, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_many1_fun2799__t {
  struct kk_function_s _base;
  kk_box_t x_11012;
};
static kk_box_t kk_std_text_parse_many1_fun2799(kk_function_t _fself, kk_box_t _b_x1403, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_many1_fun2799(kk_box_t x_11012, kk_context_t* _ctx) {
  struct kk_std_text_parse_many1_fun2799__t* _self = kk_function_alloc_as(struct kk_std_text_parse_many1_fun2799__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_text_parse_many1_fun2799, kk_context());
  _self->x_11012 = x_11012;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_text_parse_many1_fun2799(kk_function_t _fself, kk_box_t _b_x1403, kk_context_t* _ctx) {
  struct kk_std_text_parse_many1_fun2799__t* _self = kk_function_as(struct kk_std_text_parse_many1_fun2799__t*, _fself, _ctx);
  kk_box_t x_11012 = _self->x_11012; /* 2791 */
  kk_drop_match(_self, {kk_box_dup(x_11012, _ctx);}, {}, _ctx)
  kk_std_core_types__list _y_x10481_1407 = kk_std_core_types__list_unbox(_b_x1403, KK_OWNED, _ctx); /*list<2791>*/;
  kk_std_core_types__list _x_x2800 = kk_std_core_types__new_Cons(kk_reuse_null, 0, x_11012, _y_x10481_1407, _ctx); /*list<79>*/
  return kk_std_core_types__list_box(_x_x2800, _ctx);
}

kk_std_core_types__list kk_std_text_parse_many1(kk_function_t p, kk_context_t* _ctx) { /* forall<a,e> (p : parser<e,a>) -> <parse|e> list<a> */ 
  kk_box_t x_11012;
  kk_function_t _x_x2794 = kk_function_dup(p, _ctx); /*std/text/parse/parser<2792,2791>*/
  x_11012 = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), _x_x2794, (_x_x2794, _ctx), _ctx); /*2791*/
  if (kk_yielding(kk_context())) {
    kk_box_drop(x_11012, _ctx);
    kk_box_t _x_x2795 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_many1_fun2796(p, _ctx), _ctx); /*2419*/
    return kk_std_core_types__list_unbox(_x_x2795, KK_OWNED, _ctx);
  }
  {
    kk_std_core_types__list x_0_11015 = kk_std_text_parse_many_acc(p, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<2791>*/;
    if (kk_yielding(kk_context())) {
      kk_std_core_types__list_drop(x_0_11015, _ctx);
      kk_box_t _x_x2798 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_many1_fun2799(x_11012, _ctx), _ctx); /*2419*/
      return kk_std_core_types__list_unbox(_x_x2798, KK_OWNED, _ctx);
    }
    {
      return kk_std_core_types__new_Cons(kk_reuse_null, 0, x_11012, x_0_11015, _ctx);
    }
  }
}
 
// monadic lift

kk_std_core_types__list kk_std_text_parse__mlift_count_acc_10587(kk_std_core_types__list acc, kk_integer_t n, kk_function_t p, kk_box_t x, kk_context_t* _ctx) { /* forall<a,e> (acc : list<a>, n : int, p : parser<e,a>, x : a) -> <parse|e> list<a> */ 
  kk_integer_t _x_x2801 = kk_integer_add_small_const(n, -1, _ctx); /*int*/
  kk_std_core_types__list _x_x2802 = kk_std_core_types__new_Cons(kk_reuse_null, 0, x, acc, _ctx); /*list<79>*/
  return kk_std_text_parse_count_acc(_x_x2801, _x_x2802, p, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_count_acc_fun2805__t {
  struct kk_function_s _base;
  kk_std_core_types__list acc_0;
  kk_integer_t n_0;
  kk_function_t p_0;
};
static kk_box_t kk_std_text_parse_count_acc_fun2805(kk_function_t _fself, kk_box_t _b_x1409, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_count_acc_fun2805(kk_std_core_types__list acc_0, kk_integer_t n_0, kk_function_t p_0, kk_context_t* _ctx) {
  struct kk_std_text_parse_count_acc_fun2805__t* _self = kk_function_alloc_as(struct kk_std_text_parse_count_acc_fun2805__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_text_parse_count_acc_fun2805, kk_context());
  _self->acc_0 = acc_0;
  _self->n_0 = n_0;
  _self->p_0 = p_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_text_parse_count_acc_fun2805(kk_function_t _fself, kk_box_t _b_x1409, kk_context_t* _ctx) {
  struct kk_std_text_parse_count_acc_fun2805__t* _self = kk_function_as(struct kk_std_text_parse_count_acc_fun2805__t*, _fself, _ctx);
  kk_std_core_types__list acc_0 = _self->acc_0; /* list<2892> */
  kk_integer_t n_0 = _self->n_0; /* int */
  kk_function_t p_0 = _self->p_0; /* std/text/parse/parser<2893,2892> */
  kk_drop_match(_self, {kk_std_core_types__list_dup(acc_0, _ctx);kk_integer_dup(n_0, _ctx);kk_function_dup(p_0, _ctx);}, {}, _ctx)
  kk_box_t x_2_1411 = _b_x1409; /*2892*/;
  kk_std_core_types__list _x_x2806 = kk_std_text_parse__mlift_count_acc_10587(acc_0, n_0, p_0, x_2_1411, _ctx); /*list<2892>*/
  return kk_std_core_types__list_box(_x_x2806, _ctx);
}

kk_std_core_types__list kk_std_text_parse_count_acc(kk_integer_t n_0, kk_std_core_types__list acc_0, kk_function_t p_0, kk_context_t* _ctx) { /* forall<a,e> (n : int, acc : list<a>, p : parser<e,a>) -> <parse|e> list<a> */ 
  kk__tailcall: ;
  bool _match_x1815 = kk_integer_lte_borrow(n_0,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  if (_match_x1815) {
    kk_function_drop(p_0, _ctx);
    kk_integer_drop(n_0, _ctx);
    kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<std/text/parse/parse|2893>>*/;
    kk_std_core_types__list x_0;
    if (kk_std_core_types__is_Nil(acc_0, _ctx)) {
      x_0 = kk_std_core_types__new_Nil(_ctx); /*list<2892>*/
    }
    else {
      x_0 = kk_std_core_list__unroll_reverse_acc_10003(kk_std_core_types__new_Nil(_ctx), acc_0, _ctx); /*list<2892>*/
    }
    kk_unit_t keep = kk_Unit;
    kk_evv_set(w,kk_context());
    return x_0;
  }
  {
    kk_box_t x_1_11022;
    kk_function_t _x_x2803 = kk_function_dup(p_0, _ctx); /*std/text/parse/parser<2893,2892>*/
    x_1_11022 = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), _x_x2803, (_x_x2803, _ctx), _ctx); /*2892*/
    if (kk_yielding(kk_context())) {
      kk_box_drop(x_1_11022, _ctx);
      kk_box_t _x_x2804 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_count_acc_fun2805(acc_0, n_0, p_0, _ctx), _ctx); /*2419*/
      return kk_std_core_types__list_unbox(_x_x2804, KK_OWNED, _ctx);
    }
    { // tailcall
      kk_integer_t _x_x2807 = kk_integer_add_small_const(n_0, -1, _ctx); /*int*/
      kk_std_core_types__list _x_x2808 = kk_std_core_types__new_Cons(kk_reuse_null, 0, x_1_11022, acc_0, _ctx); /*list<79>*/
      n_0 = _x_x2807;
      acc_0 = _x_x2808;
      goto kk__tailcall;
    }
  }
}


// lift anonymous function
struct kk_std_text_parse_one_of_or_fun2813__t {
  struct kk_function_s _base;
  kk_string_t chars;
  kk_char_t kkloc_default;
};
static kk_box_t kk_std_text_parse_one_of_or_fun2813(kk_function_t _fself, kk_box_t _b_x1419, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_one_of_or_fun2813(kk_string_t chars, kk_char_t kkloc_default, kk_context_t* _ctx) {
  struct kk_std_text_parse_one_of_or_fun2813__t* _self = kk_function_alloc_as(struct kk_std_text_parse_one_of_or_fun2813__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_text_parse_one_of_or_fun2813, kk_context());
  _self->chars = chars;
  _self->kkloc_default = kkloc_default;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_text_parse_one_of_or_fun2813(kk_function_t _fself, kk_box_t _b_x1419, kk_context_t* _ctx) {
  struct kk_std_text_parse_one_of_or_fun2813__t* _self = kk_function_as(struct kk_std_text_parse_one_of_or_fun2813__t*, _fself, _ctx);
  kk_string_t chars = _self->chars; /* string */
  kk_char_t kkloc_default = _self->kkloc_default; /* char */
  kk_drop_match(_self, {kk_string_dup(chars, _ctx);kk_skip_dup(kkloc_default, _ctx);}, {}, _ctx)
  bool _y_x10486_1421 = kk_bool_unbox(_b_x1419); /*bool*/;
  kk_char_t _x_x2814;
  if (_y_x10486_1421) {
    _x_x2814 = kk_std_text_parse_one_of(chars, _ctx); /*char*/
  }
  else {
    kk_string_drop(chars, _ctx);
    _x_x2814 = kkloc_default; /*char*/
  }
  return kk_char_box(_x_x2814, _ctx);
}

kk_char_t kk_std_text_parse_one_of_or(kk_string_t chars, kk_char_t kkloc_default, kk_context_t* _ctx) { /* (chars : string, default : char) -> parse char */ 
  kk_std_core_hnd__ev ev_11028 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
  bool x_11025;
  kk_box_t _x_x2809;
  {
    struct kk_std_core_hnd_Ev* _con_x2810 = kk_std_core_hnd__as_Ev(ev_11028, _ctx);
    kk_box_t _box_x1412 = _con_x2810->hnd;
    int32_t m = _con_x2810->marker;
    kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x1412, KK_BORROWED, _ctx);
    kk_std_text_parse__parse_dup(h, _ctx);
    {
      struct kk_std_text_parse__Hnd_parse* _con_x2811 = kk_std_text_parse__as_Hnd_parse(h, _ctx);
      kk_integer_t _pat_0 = _con_x2811->_cfc;
      kk_std_core_hnd__clause0 _pat_1_1 = _con_x2811->_fun_current_input;
      kk_std_core_hnd__clause1 _pat_2 = _con_x2811->_brk_fail;
      kk_std_core_hnd__clause0 _ctl_pick = _con_x2811->_ctl_pick;
      kk_std_core_hnd__clause1 _pat_3 = _con_x2811->_fun_satisfy;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause1_drop(_pat_3, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_2, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_1_1, _ctx);
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause0_dup(_ctl_pick, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x1415 = _ctl_pick.clause;
        _x_x2809 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x1415, (_fun_unbox_x1415, m, ev_11028, _ctx), _ctx); /*35*/
      }
    }
  }
  x_11025 = kk_bool_unbox(_x_x2809); /*bool*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2812 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_one_of_or_fun2813(chars, kkloc_default, _ctx), _ctx); /*2419*/
    return kk_char_unbox(_x_x2812, KK_OWNED, _ctx);
  }
  if (x_11025) {
    return kk_std_text_parse_one_of(chars, _ctx);
  }
  {
    kk_string_drop(chars, _ctx);
    return kkloc_default;
  }
}
 
// monadic lift

kk_char_t kk_std_text_parse__mlift_sign_10589(kk_std_core_types__maybe _y_x10490, kk_context_t* _ctx) { /* (maybe<char>) -> parse char */ 
  if (kk_std_core_types__is_Nothing(_y_x10490, _ctx)) {
    kk_std_core_hnd__ev ev_11033 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
    kk_box_t _x_x2815;
    {
      struct kk_std_core_hnd_Ev* _con_x2816 = kk_std_core_hnd__as_Ev(ev_11033, _ctx);
      kk_box_t _box_x1422 = _con_x2816->hnd;
      int32_t m = _con_x2816->marker;
      kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x1422, KK_BORROWED, _ctx);
      kk_std_text_parse__parse_dup(h, _ctx);
      {
        struct kk_std_text_parse__Hnd_parse* _con_x2817 = kk_std_text_parse__as_Hnd_parse(h, _ctx);
        kk_integer_t _pat_0_1 = _con_x2817->_cfc;
        kk_std_core_hnd__clause0 _pat_1_0 = _con_x2817->_fun_current_input;
        kk_std_core_hnd__clause1 _brk_fail = _con_x2817->_brk_fail;
        kk_std_core_hnd__clause0 _pat_2_0 = _con_x2817->_ctl_pick;
        kk_std_core_hnd__clause1 _pat_3 = _con_x2817->_fun_satisfy;
        if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
          kk_std_core_hnd__clause1_drop(_pat_3, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_2_0, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_1_0, _ctx);
          kk_integer_drop(_pat_0_1, _ctx);
          kk_datatype_ptr_free(h, _ctx);
        }
        else {
          kk_std_core_hnd__clause1_dup(_brk_fail, _ctx);
          kk_datatype_ptr_decref(h, _ctx);
        }
        {
          kk_function_t _fun_unbox_x1426 = _brk_fail.clause;
          kk_box_t _x_x2818;
          kk_string_t _x_x2819;
          kk_define_string_literal(static, _s_x2820, 2, "+-", _ctx)
          _x_x2819 = kk_string_dup(_s_x2820, _ctx); /*string*/
          _x_x2818 = kk_string_box(_x_x2819); /*45*/
          _x_x2815 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x1426, (_fun_unbox_x1426, m, ev_11033, _x_x2818, _ctx), _ctx); /*46*/
        }
      }
    }
    return kk_char_unbox(_x_x2815, KK_OWNED, _ctx);
  }
  {
    kk_box_t _box_x1430 = _y_x10490._cons.Just.value;
    kk_char_t x_0 = kk_char_unbox(_box_x1430, KK_BORROWED, _ctx);
    kk_std_core_types__maybe_drop(_y_x10490, _ctx);
    return x_0;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_text_parse__mlift_sign_10591_fun2824__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse__mlift_sign_10591_fun2824(kk_function_t _fself, kk_box_t _b_x1444, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse__new_mlift_sign_10591_fun2824(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse__mlift_sign_10591_fun2824, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_text_parse__mlift_sign_10591_fun2824(kk_function_t _fself, kk_box_t _b_x1444, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__maybe _x_x2825;
  kk_std_core_types__maybe _match_x1813;
  kk_std_core_sslice__sslice _x_x2826 = kk_std_core_sslice__sslice_unbox(_b_x1444, KK_OWNED, _ctx); /*sslice/sslice*/
  _match_x1813 = kk_std_core_sslice_next(_x_x2826, _ctx); /*maybe<(char, sslice/sslice)>*/
  if (kk_std_core_types__is_Just(_match_x1813, _ctx)) {
    kk_box_t _box_x1445 = _match_x1813._cons.Just.value;
    kk_std_core_types__tuple2 _pat_0_0_0 = kk_std_core_types__tuple2_unbox(_box_x1445, KK_BORROWED, _ctx);
    if (kk_std_core_types__is_Tuple2(_pat_0_0_0, _ctx)) {
      kk_box_t _box_x1446 = _pat_0_0_0.fst;
      kk_box_t _box_x1447 = _pat_0_0_0.snd;
      kk_char_t c = kk_char_unbox(_box_x1446, KK_BORROWED, _ctx);
      kk_string_t _x_x2828;
      kk_define_string_literal(static, _s_x2829, 2, "+-", _ctx)
      _x_x2828 = kk_string_dup(_s_x2829, _ctx); /*string*/
      kk_string_t _x_x2830 = kk_std_core_string_char_fs_string(c, _ctx); /*string*/
      if (kk_string_contains(_x_x2828,_x_x2830,kk_context())) {
        kk_std_core_sslice__sslice rest = kk_std_core_sslice__sslice_unbox(_box_x1447, KK_BORROWED, _ctx);
        kk_std_core_sslice__sslice_dup(rest, _ctx);
        kk_std_core_types__maybe_drop(_match_x1813, _ctx);
        kk_box_t _x_x2831;
        kk_std_core_types__tuple2 _x_x2832 = kk_std_core_types__new_Tuple2(kk_char_box(c, _ctx), kk_std_core_sslice__sslice_box(rest, _ctx), _ctx); /*(134, 135)*/
        _x_x2831 = kk_std_core_types__tuple2_box(_x_x2832, _ctx); /*88*/
        _x_x2825 = kk_std_core_types__new_Just(_x_x2831, _ctx); /*maybe<88>*/
        goto _match_x2827;
      }
    }
  }
  {
    kk_std_core_types__maybe_drop(_match_x1813, _ctx);
    _x_x2825 = kk_std_core_types__new_Nothing(_ctx); /*maybe<88>*/
  }
  _match_x2827: ;
  return kk_std_core_types__maybe_box(_x_x2825, _ctx);
}


// lift anonymous function
struct kk_std_text_parse__mlift_sign_10591_fun2834__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse__mlift_sign_10591_fun2834(kk_function_t _fself, kk_box_t _b_x1456, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse__new_mlift_sign_10591_fun2834(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse__mlift_sign_10591_fun2834, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_text_parse__mlift_sign_10591_fun2834(kk_function_t _fself, kk_box_t _b_x1456, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t _x_x2835;
  kk_std_core_types__maybe _x_x2836 = kk_std_core_types__maybe_unbox(_b_x1456, KK_OWNED, _ctx); /*maybe<char>*/
  _x_x2835 = kk_std_text_parse__mlift_sign_10589(_x_x2836, _ctx); /*char*/
  return kk_char_box(_x_x2835, _ctx);
}


// lift anonymous function
struct kk_std_text_parse__mlift_sign_10591_fun2838__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse__mlift_sign_10591_fun2838(kk_function_t _fself, kk_box_t _b_x1459, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse__new_mlift_sign_10591_fun2838(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse__mlift_sign_10591_fun2838, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_text_parse__mlift_sign_10591_fun2838(kk_function_t _fself, kk_box_t _b_x1459, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  bool _x_x2839;
  kk_char_t _x_x2840 = kk_char_unbox(_b_x1459, KK_OWNED, _ctx); /*char*/
  _x_x2839 = kk_std_text_parse__mlift_sign_10590(_x_x2840, _ctx); /*bool*/
  return kk_bool_box(_x_x2839);
}

bool kk_std_text_parse__mlift_sign_10591(bool _y_x10489, kk_context_t* _ctx) { /* (bool) -> parse bool */ 
  kk_char_t x_11036;
  if (_y_x10489) {
    kk_std_core_hnd__ev ev_11040 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
    kk_std_core_types__maybe x_0_11038;
    kk_box_t _x_x2821;
    {
      struct kk_std_core_hnd_Ev* _con_x2822 = kk_std_core_hnd__as_Ev(ev_11040, _ctx);
      kk_box_t _box_x1431 = _con_x2822->hnd;
      int32_t m = _con_x2822->marker;
      kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x1431, KK_BORROWED, _ctx);
      kk_std_text_parse__parse_dup(h, _ctx);
      {
        struct kk_std_text_parse__Hnd_parse* _con_x2823 = kk_std_text_parse__as_Hnd_parse(h, _ctx);
        kk_integer_t _pat_0 = _con_x2823->_cfc;
        kk_std_core_hnd__clause0 _pat_1_1 = _con_x2823->_fun_current_input;
        kk_std_core_hnd__clause1 _pat_2 = _con_x2823->_brk_fail;
        kk_std_core_hnd__clause0 _pat_3_0 = _con_x2823->_ctl_pick;
        kk_std_core_hnd__clause1 _fun_satisfy = _con_x2823->_fun_satisfy;
        if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
          kk_std_core_hnd__clause0_drop(_pat_3_0, _ctx);
          kk_std_core_hnd__clause1_drop(_pat_2, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_1_1, _ctx);
          kk_integer_drop(_pat_0, _ctx);
          kk_datatype_ptr_free(h, _ctx);
        }
        else {
          kk_std_core_hnd__clause1_dup(_fun_satisfy, _ctx);
          kk_datatype_ptr_decref(h, _ctx);
        }
        {
          kk_function_t _fun_unbox_x1438 = _fun_satisfy.clause;
          _x_x2821 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x1438, (_fun_unbox_x1438, m, ev_11040, kk_function_box(kk_std_text_parse__new_mlift_sign_10591_fun2824(_ctx), _ctx), _ctx), _ctx); /*46*/
        }
      }
    }
    x_0_11038 = kk_std_core_types__maybe_unbox(_x_x2821, KK_OWNED, _ctx); /*maybe<char>*/
    if (kk_yielding(kk_context())) {
      kk_std_core_types__maybe_drop(x_0_11038, _ctx);
      kk_box_t _x_x2833 = kk_std_core_hnd_yield_extend(kk_std_text_parse__new_mlift_sign_10591_fun2834(_ctx), _ctx); /*2419*/
      x_11036 = kk_char_unbox(_x_x2833, KK_OWNED, _ctx); /*char*/
    }
    else {
      x_11036 = kk_std_text_parse__mlift_sign_10589(x_0_11038, _ctx); /*char*/
    }
  }
  else {
    x_11036 = '+'; /*char*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2837 = kk_std_core_hnd_yield_extend(kk_std_text_parse__new_mlift_sign_10591_fun2838(_ctx), _ctx); /*2419*/
    return kk_bool_unbox(_x_x2837);
  }
  {
    return (x_11036 == ('-'));
  }
}


// lift anonymous function
struct kk_std_text_parse_sign_fun2845__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_sign_fun2845(kk_function_t _fself, kk_box_t _b_x1468, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_sign_fun2845(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_sign_fun2845, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_text_parse_sign_fun2845(kk_function_t _fself, kk_box_t _b_x1468, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  bool _x_x2846;
  bool _x_x2847 = kk_bool_unbox(_b_x1468); /*bool*/
  _x_x2846 = kk_std_text_parse__mlift_sign_10591(_x_x2847, _ctx); /*bool*/
  return kk_bool_box(_x_x2846);
}


// lift anonymous function
struct kk_std_text_parse_sign_fun2851__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_sign_fun2851(kk_function_t _fself, kk_box_t _b_x1482, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_sign_fun2851(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_sign_fun2851, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_text_parse_sign_fun2851(kk_function_t _fself, kk_box_t _b_x1482, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__maybe _x_x2852;
  kk_std_core_types__maybe _match_x1810;
  kk_std_core_sslice__sslice _x_x2853 = kk_std_core_sslice__sslice_unbox(_b_x1482, KK_OWNED, _ctx); /*sslice/sslice*/
  _match_x1810 = kk_std_core_sslice_next(_x_x2853, _ctx); /*maybe<(char, sslice/sslice)>*/
  if (kk_std_core_types__is_Just(_match_x1810, _ctx)) {
    kk_box_t _box_x1483 = _match_x1810._cons.Just.value;
    kk_std_core_types__tuple2 _pat_0_0_0 = kk_std_core_types__tuple2_unbox(_box_x1483, KK_BORROWED, _ctx);
    if (kk_std_core_types__is_Tuple2(_pat_0_0_0, _ctx)) {
      kk_box_t _box_x1484 = _pat_0_0_0.fst;
      kk_box_t _box_x1485 = _pat_0_0_0.snd;
      kk_char_t c = kk_char_unbox(_box_x1484, KK_BORROWED, _ctx);
      kk_string_t _x_x2855;
      kk_define_string_literal(static, _s_x2856, 2, "+-", _ctx)
      _x_x2855 = kk_string_dup(_s_x2856, _ctx); /*string*/
      kk_string_t _x_x2857 = kk_std_core_string_char_fs_string(c, _ctx); /*string*/
      if (kk_string_contains(_x_x2855,_x_x2857,kk_context())) {
        kk_std_core_sslice__sslice rest = kk_std_core_sslice__sslice_unbox(_box_x1485, KK_BORROWED, _ctx);
        kk_std_core_sslice__sslice_dup(rest, _ctx);
        kk_std_core_types__maybe_drop(_match_x1810, _ctx);
        kk_box_t _x_x2858;
        kk_std_core_types__tuple2 _x_x2859 = kk_std_core_types__new_Tuple2(kk_char_box(c, _ctx), kk_std_core_sslice__sslice_box(rest, _ctx), _ctx); /*(134, 135)*/
        _x_x2858 = kk_std_core_types__tuple2_box(_x_x2859, _ctx); /*88*/
        _x_x2852 = kk_std_core_types__new_Just(_x_x2858, _ctx); /*maybe<88>*/
        goto _match_x2854;
      }
    }
  }
  {
    kk_std_core_types__maybe_drop(_match_x1810, _ctx);
    _x_x2852 = kk_std_core_types__new_Nothing(_ctx); /*maybe<88>*/
  }
  _match_x2854: ;
  return kk_std_core_types__maybe_box(_x_x2852, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_sign_fun2861__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_sign_fun2861(kk_function_t _fself, kk_box_t _b_x1494, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_sign_fun2861(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_sign_fun2861, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_text_parse_sign_fun2861(kk_function_t _fself, kk_box_t _b_x1494, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t _x_x2862;
  kk_std_core_types__maybe _x_x2863 = kk_std_core_types__maybe_unbox(_b_x1494, KK_OWNED, _ctx); /*maybe<char>*/
  _x_x2862 = kk_std_text_parse__mlift_sign_10589(_x_x2863, _ctx); /*char*/
  return kk_char_box(_x_x2862, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_sign_fun2865__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_sign_fun2865(kk_function_t _fself, kk_box_t _b_x1497, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_sign_fun2865(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_sign_fun2865, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_text_parse_sign_fun2865(kk_function_t _fself, kk_box_t _b_x1497, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  bool _x_x2866;
  kk_char_t _x_x2867 = kk_char_unbox(_b_x1497, KK_OWNED, _ctx); /*char*/
  _x_x2866 = kk_std_text_parse__mlift_sign_10590(_x_x2867, _ctx); /*bool*/
  return kk_bool_box(_x_x2866);
}

bool kk_std_text_parse_sign(kk_context_t* _ctx) { /* () -> parse bool */ 
  kk_std_core_hnd__ev ev_11046 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
  bool x_11043;
  kk_box_t _x_x2841;
  {
    struct kk_std_core_hnd_Ev* _con_x2842 = kk_std_core_hnd__as_Ev(ev_11046, _ctx);
    kk_box_t _box_x1461 = _con_x2842->hnd;
    int32_t m = _con_x2842->marker;
    kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x1461, KK_BORROWED, _ctx);
    kk_std_text_parse__parse_dup(h, _ctx);
    {
      struct kk_std_text_parse__Hnd_parse* _con_x2843 = kk_std_text_parse__as_Hnd_parse(h, _ctx);
      kk_integer_t _pat_0 = _con_x2843->_cfc;
      kk_std_core_hnd__clause0 _pat_1_1 = _con_x2843->_fun_current_input;
      kk_std_core_hnd__clause1 _pat_2 = _con_x2843->_brk_fail;
      kk_std_core_hnd__clause0 _ctl_pick = _con_x2843->_ctl_pick;
      kk_std_core_hnd__clause1 _pat_3 = _con_x2843->_fun_satisfy;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause1_drop(_pat_3, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_2, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_1_1, _ctx);
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause0_dup(_ctl_pick, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x1464 = _ctl_pick.clause;
        _x_x2841 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x1464, (_fun_unbox_x1464, m, ev_11046, _ctx), _ctx); /*35*/
      }
    }
  }
  x_11043 = kk_bool_unbox(_x_x2841); /*bool*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2844 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_sign_fun2845(_ctx), _ctx); /*2419*/
    return kk_bool_unbox(_x_x2844);
  }
  {
    kk_char_t x_0_11048;
    if (x_11043) {
      kk_std_core_hnd__ev ev_0_11053 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
      kk_std_core_types__maybe x_1_11051;
      kk_box_t _x_x2848;
      {
        struct kk_std_core_hnd_Ev* _con_x2849 = kk_std_core_hnd__as_Ev(ev_0_11053, _ctx);
        kk_box_t _box_x1469 = _con_x2849->hnd;
        int32_t m_0 = _con_x2849->marker;
        kk_std_text_parse__parse h_0 = kk_std_text_parse__parse_unbox(_box_x1469, KK_BORROWED, _ctx);
        kk_std_text_parse__parse_dup(h_0, _ctx);
        {
          struct kk_std_text_parse__Hnd_parse* _con_x2850 = kk_std_text_parse__as_Hnd_parse(h_0, _ctx);
          kk_integer_t _pat_0_2 = _con_x2850->_cfc;
          kk_std_core_hnd__clause0 _pat_1_2 = _con_x2850->_fun_current_input;
          kk_std_core_hnd__clause1 _pat_2_1 = _con_x2850->_brk_fail;
          kk_std_core_hnd__clause0 _pat_3_0 = _con_x2850->_ctl_pick;
          kk_std_core_hnd__clause1 _fun_satisfy = _con_x2850->_fun_satisfy;
          if kk_likely(kk_datatype_ptr_is_unique(h_0, _ctx)) {
            kk_std_core_hnd__clause0_drop(_pat_3_0, _ctx);
            kk_std_core_hnd__clause1_drop(_pat_2_1, _ctx);
            kk_std_core_hnd__clause0_drop(_pat_1_2, _ctx);
            kk_integer_drop(_pat_0_2, _ctx);
            kk_datatype_ptr_free(h_0, _ctx);
          }
          else {
            kk_std_core_hnd__clause1_dup(_fun_satisfy, _ctx);
            kk_datatype_ptr_decref(h_0, _ctx);
          }
          {
            kk_function_t _fun_unbox_x1476 = _fun_satisfy.clause;
            _x_x2848 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x1476, (_fun_unbox_x1476, m_0, ev_0_11053, kk_function_box(kk_std_text_parse_new_sign_fun2851(_ctx), _ctx), _ctx), _ctx); /*46*/
          }
        }
      }
      x_1_11051 = kk_std_core_types__maybe_unbox(_x_x2848, KK_OWNED, _ctx); /*maybe<char>*/
      if (kk_yielding(kk_context())) {
        kk_std_core_types__maybe_drop(x_1_11051, _ctx);
        kk_box_t _x_x2860 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_sign_fun2861(_ctx), _ctx); /*2419*/
        x_0_11048 = kk_char_unbox(_x_x2860, KK_OWNED, _ctx); /*char*/
      }
      else {
        x_0_11048 = kk_std_text_parse__mlift_sign_10589(x_1_11051, _ctx); /*char*/
      }
    }
    else {
      x_0_11048 = '+'; /*char*/
    }
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x2864 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_sign_fun2865(_ctx), _ctx); /*2419*/
      return kk_bool_unbox(_x_x2864);
    }
    {
      return (x_0_11048 == ('-'));
    }
  }
}
 
// lifted local: i, pint, @spec-x10341
// specialized: std/text/parse/next-while0, on parameters @uniq-pred@10332, using:
// @uniq-pred@10332 = std/core/char/is-digit

kk_std_core_types__tuple2 kk_std_text_parse__lift_pint_10359(kk_std_core_sslice__sslice _uniq_slice_10331, kk_std_core_types__list _uniq_acc_10333, kk_context_t* _ctx) { /* (sslice/sslice, list<char>) -> (list<char>, sslice/sslice) */ 
  kk__tailcall: ;
  kk_std_core_types__maybe _match_x1806;
  kk_std_core_sslice__sslice _x_x2868 = kk_std_core_sslice__sslice_dup(_uniq_slice_10331, _ctx); /*sslice/sslice*/
  _match_x1806 = kk_std_core_sslice_next(_x_x2868, _ctx); /*maybe<(char, sslice/sslice)>*/
  if (kk_std_core_types__is_Just(_match_x1806, _ctx)) {
    kk_box_t _box_x1500 = _match_x1806._cons.Just.value;
    kk_std_core_types__tuple2 _uniq_pat_0_10335 = kk_std_core_types__tuple2_unbox(_box_x1500, KK_BORROWED, _ctx);
    if (kk_std_core_types__is_Tuple2(_uniq_pat_0_10335, _ctx)) {
      kk_box_t _box_x1501 = _uniq_pat_0_10335.fst;
      kk_box_t _box_x1502 = _uniq_pat_0_10335.snd;
      kk_char_t _uniq_c_10336 = kk_char_unbox(_box_x1501, KK_BORROWED, _ctx);
      if (kk_std_core_char_is_digit(_uniq_c_10336, _ctx)) {
        kk_std_core_sslice__sslice _uniq_rest_10337 = kk_std_core_sslice__sslice_unbox(_box_x1502, KK_BORROWED, _ctx);
        kk_std_core_sslice__sslice_drop(_uniq_slice_10331, _ctx);
        kk_std_core_sslice__sslice_dup(_uniq_rest_10337, _ctx);
        kk_std_core_types__maybe_drop(_match_x1806, _ctx);
        { // tailcall
          kk_std_core_types__list _x_x2869 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_char_box(_uniq_c_10336, _ctx), _uniq_acc_10333, _ctx); /*list<79>*/
          _uniq_slice_10331 = _uniq_rest_10337;
          _uniq_acc_10333 = _x_x2869;
          goto kk__tailcall;
        }
      }
    }
  }
  {
    kk_std_core_types__maybe_drop(_match_x1806, _ctx);
    kk_std_core_types__list _b_x1505_1509;
    if (kk_std_core_types__is_Nil(_uniq_acc_10333, _ctx)) {
      _b_x1505_1509 = kk_std_core_types__new_Nil(_ctx); /*list<char>*/
    }
    else {
      _b_x1505_1509 = kk_std_core_list__unroll_reverse_acc_10003(kk_std_core_types__new_Nil(_ctx), _uniq_acc_10333, _ctx); /*list<char>*/
    }
    return kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(_b_x1505_1509, _ctx), kk_std_core_sslice__sslice_box(_uniq_slice_10331, _ctx), _ctx);
  }
}
 
// monadic lift

kk_integer_t kk_std_text_parse__mlift_pint_10592(bool neg, kk_std_core_types__list _c_x10501, kk_context_t* _ctx) { /* (neg : bool, list<char>) -> int */ 
  kk_string_t _x_x1_0_10544 = kk_std_core_string_listchar_fs_string(_c_x10501, _ctx); /*string*/;
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
  kk_std_core_types__maybe x;
  bool _x_x2870;
  kk_std_core_types__optional _match_x1805 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x1805, _ctx)) {
    kk_box_t _box_x1511 = _match_x1805._cons._Optional.value;
    bool _uniq_hex_581 = kk_bool_unbox(_box_x1511);
    kk_std_core_types__optional_drop(_match_x1805, _ctx);
    _x_x2870 = _uniq_hex_581; /*bool*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x1805, _ctx);
    _x_x2870 = false; /*bool*/
  }
  x = kk_std_core_int_xparse(_x_x1_0_10544, _x_x2870, _ctx); /*maybe<int>*/
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
  kk_unit_t keep_0 = kk_Unit;
  kk_evv_set(w_0,kk_context());
  if (neg) {
    kk_integer_t _x_x2871;
    if (kk_std_core_types__is_Nothing(x, _ctx)) {
      _x_x2871 = kk_integer_from_small(0); /*int*/
    }
    else {
      kk_box_t _box_x1512 = x._cons.Just.value;
      kk_integer_t x_0_0 = kk_integer_unbox(_box_x1512, _ctx);
      kk_integer_dup(x_0_0, _ctx);
      kk_std_core_types__maybe_drop(x, _ctx);
      _x_x2871 = x_0_0; /*int*/
    }
    return kk_integer_neg(_x_x2871,kk_context());
  }
  if (kk_std_core_types__is_Nothing(x, _ctx)) {
    return kk_integer_from_small(0);
  }
  {
    kk_box_t _box_x1513 = x._cons.Just.value;
    kk_integer_t x_0_0_0 = kk_integer_unbox(_box_x1513, _ctx);
    kk_integer_dup(x_0_0_0, _ctx);
    kk_std_core_types__maybe_drop(x, _ctx);
    return x_0_0_0;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_text_parse__mlift_pint_10593_fun2879__t {
  struct kk_function_s _base;
  bool neg;
};
static kk_box_t kk_std_text_parse__mlift_pint_10593_fun2879(kk_function_t _fself, kk_box_t _b_x1524, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse__new_mlift_pint_10593_fun2879(bool neg, kk_context_t* _ctx) {
  struct kk_std_text_parse__mlift_pint_10593_fun2879__t* _self = kk_function_alloc_as(struct kk_std_text_parse__mlift_pint_10593_fun2879__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_text_parse__mlift_pint_10593_fun2879, kk_context());
  _self->neg = neg;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_text_parse__mlift_pint_10593_fun2879(kk_function_t _fself, kk_box_t _b_x1524, kk_context_t* _ctx) {
  struct kk_std_text_parse__mlift_pint_10593_fun2879__t* _self = kk_function_as(struct kk_std_text_parse__mlift_pint_10593_fun2879__t*, _fself, _ctx);
  bool neg = _self->neg; /* bool */
  kk_drop_match(_self, {kk_skip_dup(neg, _ctx);}, {}, _ctx)
  kk_std_core_types__list _c_x10501_1526 = kk_std_core_types__list_unbox(_b_x1524, KK_OWNED, _ctx); /*list<char>*/;
  kk_integer_t _x_x2880 = kk_std_text_parse__mlift_pint_10592(neg, _c_x10501_1526, _ctx); /*int*/
  return kk_integer_box(_x_x2880, _ctx);
}

kk_integer_t kk_std_text_parse__mlift_pint_10593(bool neg, kk_std_core_types__maybe _y_x10499, kk_context_t* _ctx) { /* (neg : bool, maybe<list<char>>) -> parse int */ 
  kk_std_core_types__list x_11062;
  if (kk_std_core_types__is_Nothing(_y_x10499, _ctx)) {
    kk_std_core_hnd__ev ev_11064 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
    kk_box_t _x_x2872;
    {
      struct kk_std_core_hnd_Ev* _con_x2873 = kk_std_core_hnd__as_Ev(ev_11064, _ctx);
      kk_box_t _box_x1514 = _con_x2873->hnd;
      int32_t m = _con_x2873->marker;
      kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x1514, KK_BORROWED, _ctx);
      kk_std_text_parse__parse_dup(h, _ctx);
      {
        struct kk_std_text_parse__Hnd_parse* _con_x2874 = kk_std_text_parse__as_Hnd_parse(h, _ctx);
        kk_integer_t _pat_0 = _con_x2874->_cfc;
        kk_std_core_hnd__clause0 _pat_1_1 = _con_x2874->_fun_current_input;
        kk_std_core_hnd__clause1 _brk_fail = _con_x2874->_brk_fail;
        kk_std_core_hnd__clause0 _pat_2 = _con_x2874->_ctl_pick;
        kk_std_core_hnd__clause1 _pat_3 = _con_x2874->_fun_satisfy;
        if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
          kk_std_core_hnd__clause1_drop(_pat_3, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_2, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_1_1, _ctx);
          kk_integer_drop(_pat_0, _ctx);
          kk_datatype_ptr_free(h, _ctx);
        }
        else {
          kk_std_core_hnd__clause1_dup(_brk_fail, _ctx);
          kk_datatype_ptr_decref(h, _ctx);
        }
        {
          kk_function_t _fun_unbox_x1518 = _brk_fail.clause;
          kk_box_t _x_x2875;
          kk_string_t _x_x2876;
          kk_define_string_literal(static, _s_x2877, 5, "digit", _ctx)
          _x_x2876 = kk_string_dup(_s_x2877, _ctx); /*string*/
          _x_x2875 = kk_string_box(_x_x2876); /*45*/
          _x_x2872 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x1518, (_fun_unbox_x1518, m, ev_11064, _x_x2875, _ctx), _ctx); /*46*/
        }
      }
    }
    x_11062 = kk_std_core_types__list_unbox(_x_x2872, KK_OWNED, _ctx); /*list<char>*/
  }
  else {
    kk_box_t _box_x1522 = _y_x10499._cons.Just.value;
    kk_std_core_types__list x_0_0 = kk_std_core_types__list_unbox(_box_x1522, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(x_0_0, _ctx);
    kk_std_core_types__maybe_drop(_y_x10499, _ctx);
    x_11062 = x_0_0; /*list<char>*/
  }
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_11062, _ctx);
    kk_box_t _x_x2878 = kk_std_core_hnd_yield_extend(kk_std_text_parse__new_mlift_pint_10593_fun2879(neg, _ctx), _ctx); /*2419*/
    return kk_integer_unbox(_x_x2878, _ctx);
  }
  {
    return kk_std_text_parse__mlift_pint_10592(neg, x_11062, _ctx);
  }
}
 
// monadic lift

kk_char_t kk_std_text_parse__mlift_pint_10594(kk_std_core_types__maybe _y_x10495, kk_context_t* _ctx) { /* (maybe<char>) -> parse char */ 
  if (kk_std_core_types__is_Nothing(_y_x10495, _ctx)) {
    kk_std_core_hnd__ev ev_11067 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
    kk_box_t _x_x2881;
    {
      struct kk_std_core_hnd_Ev* _con_x2882 = kk_std_core_hnd__as_Ev(ev_11067, _ctx);
      kk_box_t _box_x1527 = _con_x2882->hnd;
      int32_t m = _con_x2882->marker;
      kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x1527, KK_BORROWED, _ctx);
      kk_std_text_parse__parse_dup(h, _ctx);
      {
        struct kk_std_text_parse__Hnd_parse* _con_x2883 = kk_std_text_parse__as_Hnd_parse(h, _ctx);
        kk_integer_t _pat_0_1 = _con_x2883->_cfc;
        kk_std_core_hnd__clause0 _pat_1_0 = _con_x2883->_fun_current_input;
        kk_std_core_hnd__clause1 _brk_fail = _con_x2883->_brk_fail;
        kk_std_core_hnd__clause0 _pat_2_0 = _con_x2883->_ctl_pick;
        kk_std_core_hnd__clause1 _pat_3 = _con_x2883->_fun_satisfy;
        if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
          kk_std_core_hnd__clause1_drop(_pat_3, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_2_0, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_1_0, _ctx);
          kk_integer_drop(_pat_0_1, _ctx);
          kk_datatype_ptr_free(h, _ctx);
        }
        else {
          kk_std_core_hnd__clause1_dup(_brk_fail, _ctx);
          kk_datatype_ptr_decref(h, _ctx);
        }
        {
          kk_function_t _fun_unbox_x1531 = _brk_fail.clause;
          kk_box_t _x_x2884;
          kk_string_t _x_x2885;
          kk_define_string_literal(static, _s_x2886, 2, "+-", _ctx)
          _x_x2885 = kk_string_dup(_s_x2886, _ctx); /*string*/
          _x_x2884 = kk_string_box(_x_x2885); /*45*/
          _x_x2881 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x1531, (_fun_unbox_x1531, m, ev_11067, _x_x2884, _ctx), _ctx); /*46*/
        }
      }
    }
    return kk_char_unbox(_x_x2881, KK_OWNED, _ctx);
  }
  {
    kk_box_t _box_x1535 = _y_x10495._cons.Just.value;
    kk_char_t x_0 = kk_char_unbox(_box_x1535, KK_BORROWED, _ctx);
    kk_std_core_types__maybe_drop(_y_x10495, _ctx);
    return x_0;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_text_parse__mlift_pint_10595_fun2890__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse__mlift_pint_10595_fun2890(kk_function_t _fself, kk_box_t _b_x1549, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse__new_mlift_pint_10595_fun2890(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse__mlift_pint_10595_fun2890, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_text_parse__mlift_pint_10595_fun2890(kk_function_t _fself, kk_box_t _b_x1549, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__maybe _x_x2891;
  kk_std_core_types__tuple2 _match_x1803;
  kk_std_core_sslice__sslice _x_x2892 = kk_std_core_sslice__sslice_unbox(_b_x1549, KK_OWNED, _ctx); /*sslice/sslice*/
  _match_x1803 = kk_std_text_parse__lift_pint_10359(_x_x2892, kk_std_core_types__new_Nil(_ctx), _ctx); /*(list<char>, sslice/sslice)*/
  {
    kk_box_t _box_x1550 = _match_x1803.fst;
    kk_box_t _box_x1551 = _match_x1803.snd;
    kk_std_core_types__list _pat_0_2_0 = kk_std_core_types__list_unbox(_box_x1550, KK_BORROWED, _ctx);
    kk_std_core_sslice__sslice _pat_1_0_0 = kk_std_core_sslice__sslice_unbox(_box_x1551, KK_BORROWED, _ctx);
    if (kk_std_core_types__is_Nil(_pat_0_2_0, _ctx)) {
      kk_std_core_types__tuple2_drop(_match_x1803, _ctx);
      _x_x2891 = kk_std_core_types__new_Nothing(_ctx); /*forall<a> maybe<a>*/
      goto _match_x2893;
    }
  }
  {
    kk_box_t _box_x1552 = _match_x1803.fst;
    kk_box_t _box_x1553 = _match_x1803.snd;
    kk_std_core_sslice__sslice rest_0 = kk_std_core_sslice__sslice_unbox(_box_x1553, KK_BORROWED, _ctx);
    kk_std_core_types__list xs = kk_std_core_types__list_unbox(_box_x1552, KK_BORROWED, _ctx);
    kk_std_core_sslice__sslice_dup(rest_0, _ctx);
    kk_std_core_types__list_dup(xs, _ctx);
    kk_std_core_types__tuple2_drop(_match_x1803, _ctx);
    kk_box_t _x_x2894;
    kk_std_core_types__tuple2 _x_x2895 = kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(xs, _ctx), kk_std_core_sslice__sslice_box(rest_0, _ctx), _ctx); /*(134, 135)*/
    _x_x2894 = kk_std_core_types__tuple2_box(_x_x2895, _ctx); /*88*/
    _x_x2891 = kk_std_core_types__new_Just(_x_x2894, _ctx); /*forall<a> maybe<a>*/
  }
  _match_x2893: ;
  return kk_std_core_types__maybe_box(_x_x2891, _ctx);
}


// lift anonymous function
struct kk_std_text_parse__mlift_pint_10595_fun2897__t {
  struct kk_function_s _base;
  bool neg;
};
static kk_box_t kk_std_text_parse__mlift_pint_10595_fun2897(kk_function_t _fself, kk_box_t _b_x1562, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse__new_mlift_pint_10595_fun2897(bool neg, kk_context_t* _ctx) {
  struct kk_std_text_parse__mlift_pint_10595_fun2897__t* _self = kk_function_alloc_as(struct kk_std_text_parse__mlift_pint_10595_fun2897__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_text_parse__mlift_pint_10595_fun2897, kk_context());
  _self->neg = neg;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_text_parse__mlift_pint_10595_fun2897(kk_function_t _fself, kk_box_t _b_x1562, kk_context_t* _ctx) {
  struct kk_std_text_parse__mlift_pint_10595_fun2897__t* _self = kk_function_as(struct kk_std_text_parse__mlift_pint_10595_fun2897__t*, _fself, _ctx);
  bool neg = _self->neg; /* bool */
  kk_drop_match(_self, {kk_skip_dup(neg, _ctx);}, {}, _ctx)
  kk_std_core_types__maybe _y_x10499_1564 = kk_std_core_types__maybe_unbox(_b_x1562, KK_OWNED, _ctx); /*maybe<list<char>>*/;
  kk_integer_t _x_x2898 = kk_std_text_parse__mlift_pint_10593(neg, _y_x10499_1564, _ctx); /*int*/
  return kk_integer_box(_x_x2898, _ctx);
}

kk_integer_t kk_std_text_parse__mlift_pint_10595(kk_char_t _c_x10498, kk_context_t* _ctx) { /* (char) -> int */ 
  bool neg = (_c_x10498 == ('-')); /*bool*/;
  kk_std_core_hnd__ev ev_11072 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
  kk_std_core_types__maybe x_11070;
  kk_box_t _x_x2887;
  {
    struct kk_std_core_hnd_Ev* _con_x2888 = kk_std_core_hnd__as_Ev(ev_11072, _ctx);
    kk_box_t _box_x1536 = _con_x2888->hnd;
    int32_t m = _con_x2888->marker;
    kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x1536, KK_BORROWED, _ctx);
    kk_std_text_parse__parse_dup(h, _ctx);
    {
      struct kk_std_text_parse__Hnd_parse* _con_x2889 = kk_std_text_parse__as_Hnd_parse(h, _ctx);
      kk_integer_t _pat_0 = _con_x2889->_cfc;
      kk_std_core_hnd__clause0 _pat_1_1 = _con_x2889->_fun_current_input;
      kk_std_core_hnd__clause1 _pat_2 = _con_x2889->_brk_fail;
      kk_std_core_hnd__clause0 _pat_3 = _con_x2889->_ctl_pick;
      kk_std_core_hnd__clause1 _fun_satisfy = _con_x2889->_fun_satisfy;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause0_drop(_pat_3, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_2, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_1_1, _ctx);
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_fun_satisfy, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x1543 = _fun_satisfy.clause;
        _x_x2887 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x1543, (_fun_unbox_x1543, m, ev_11072, kk_function_box(kk_std_text_parse__new_mlift_pint_10595_fun2890(_ctx), _ctx), _ctx), _ctx); /*46*/
      }
    }
  }
  x_11070 = kk_std_core_types__maybe_unbox(_x_x2887, KK_OWNED, _ctx); /*maybe<list<char>>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__maybe_drop(x_11070, _ctx);
    kk_box_t _x_x2896 = kk_std_core_hnd_yield_extend(kk_std_text_parse__new_mlift_pint_10595_fun2897(neg, _ctx), _ctx); /*2419*/
    return kk_integer_unbox(_x_x2896, _ctx);
  }
  {
    return kk_std_text_parse__mlift_pint_10593(neg, x_11070, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_text_parse__mlift_pint_10596_fun2902__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse__mlift_pint_10596_fun2902(kk_function_t _fself, kk_box_t _b_x1578, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse__new_mlift_pint_10596_fun2902(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse__mlift_pint_10596_fun2902, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_text_parse__mlift_pint_10596_fun2902(kk_function_t _fself, kk_box_t _b_x1578, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__maybe _x_x2903;
  kk_std_core_types__maybe _match_x1801;
  kk_std_core_sslice__sslice _x_x2904 = kk_std_core_sslice__sslice_unbox(_b_x1578, KK_OWNED, _ctx); /*sslice/sslice*/
  _match_x1801 = kk_std_core_sslice_next(_x_x2904, _ctx); /*maybe<(char, sslice/sslice)>*/
  if (kk_std_core_types__is_Just(_match_x1801, _ctx)) {
    kk_box_t _box_x1579 = _match_x1801._cons.Just.value;
    kk_std_core_types__tuple2 _pat_0_0_0 = kk_std_core_types__tuple2_unbox(_box_x1579, KK_BORROWED, _ctx);
    if (kk_std_core_types__is_Tuple2(_pat_0_0_0, _ctx)) {
      kk_box_t _box_x1580 = _pat_0_0_0.fst;
      kk_box_t _box_x1581 = _pat_0_0_0.snd;
      kk_char_t c = kk_char_unbox(_box_x1580, KK_BORROWED, _ctx);
      kk_string_t _x_x2906;
      kk_define_string_literal(static, _s_x2907, 2, "+-", _ctx)
      _x_x2906 = kk_string_dup(_s_x2907, _ctx); /*string*/
      kk_string_t _x_x2908 = kk_std_core_string_char_fs_string(c, _ctx); /*string*/
      if (kk_string_contains(_x_x2906,_x_x2908,kk_context())) {
        kk_std_core_sslice__sslice rest = kk_std_core_sslice__sslice_unbox(_box_x1581, KK_BORROWED, _ctx);
        kk_std_core_sslice__sslice_dup(rest, _ctx);
        kk_std_core_types__maybe_drop(_match_x1801, _ctx);
        kk_box_t _x_x2909;
        kk_std_core_types__tuple2 _x_x2910 = kk_std_core_types__new_Tuple2(kk_char_box(c, _ctx), kk_std_core_sslice__sslice_box(rest, _ctx), _ctx); /*(134, 135)*/
        _x_x2909 = kk_std_core_types__tuple2_box(_x_x2910, _ctx); /*88*/
        _x_x2903 = kk_std_core_types__new_Just(_x_x2909, _ctx); /*maybe<88>*/
        goto _match_x2905;
      }
    }
  }
  {
    kk_std_core_types__maybe_drop(_match_x1801, _ctx);
    _x_x2903 = kk_std_core_types__new_Nothing(_ctx); /*maybe<88>*/
  }
  _match_x2905: ;
  return kk_std_core_types__maybe_box(_x_x2903, _ctx);
}


// lift anonymous function
struct kk_std_text_parse__mlift_pint_10596_fun2912__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse__mlift_pint_10596_fun2912(kk_function_t _fself, kk_box_t _b_x1590, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse__new_mlift_pint_10596_fun2912(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse__mlift_pint_10596_fun2912, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_text_parse__mlift_pint_10596_fun2912(kk_function_t _fself, kk_box_t _b_x1590, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t _x_x2913;
  kk_std_core_types__maybe _x_x2914 = kk_std_core_types__maybe_unbox(_b_x1590, KK_OWNED, _ctx); /*maybe<char>*/
  _x_x2913 = kk_std_text_parse__mlift_pint_10594(_x_x2914, _ctx); /*char*/
  return kk_char_box(_x_x2913, _ctx);
}


// lift anonymous function
struct kk_std_text_parse__mlift_pint_10596_fun2916__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse__mlift_pint_10596_fun2916(kk_function_t _fself, kk_box_t _b_x1593, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse__new_mlift_pint_10596_fun2916(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse__mlift_pint_10596_fun2916, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_text_parse__mlift_pint_10596_fun2916(kk_function_t _fself, kk_box_t _b_x1593, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x2917;
  kk_char_t _x_x2918 = kk_char_unbox(_b_x1593, KK_OWNED, _ctx); /*char*/
  _x_x2917 = kk_std_text_parse__mlift_pint_10595(_x_x2918, _ctx); /*int*/
  return kk_integer_box(_x_x2917, _ctx);
}

kk_integer_t kk_std_text_parse__mlift_pint_10596(bool _y_x10494, kk_context_t* _ctx) { /* (bool) -> parse int */ 
  kk_char_t x_11075;
  if (_y_x10494) {
    kk_std_core_hnd__ev ev_11079 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
    kk_std_core_types__maybe x_0_11077;
    kk_box_t _x_x2899;
    {
      struct kk_std_core_hnd_Ev* _con_x2900 = kk_std_core_hnd__as_Ev(ev_11079, _ctx);
      kk_box_t _box_x1565 = _con_x2900->hnd;
      int32_t m = _con_x2900->marker;
      kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x1565, KK_BORROWED, _ctx);
      kk_std_text_parse__parse_dup(h, _ctx);
      {
        struct kk_std_text_parse__Hnd_parse* _con_x2901 = kk_std_text_parse__as_Hnd_parse(h, _ctx);
        kk_integer_t _pat_0 = _con_x2901->_cfc;
        kk_std_core_hnd__clause0 _pat_1_1 = _con_x2901->_fun_current_input;
        kk_std_core_hnd__clause1 _pat_2 = _con_x2901->_brk_fail;
        kk_std_core_hnd__clause0 _pat_3_0 = _con_x2901->_ctl_pick;
        kk_std_core_hnd__clause1 _fun_satisfy = _con_x2901->_fun_satisfy;
        if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
          kk_std_core_hnd__clause0_drop(_pat_3_0, _ctx);
          kk_std_core_hnd__clause1_drop(_pat_2, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_1_1, _ctx);
          kk_integer_drop(_pat_0, _ctx);
          kk_datatype_ptr_free(h, _ctx);
        }
        else {
          kk_std_core_hnd__clause1_dup(_fun_satisfy, _ctx);
          kk_datatype_ptr_decref(h, _ctx);
        }
        {
          kk_function_t _fun_unbox_x1572 = _fun_satisfy.clause;
          _x_x2899 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x1572, (_fun_unbox_x1572, m, ev_11079, kk_function_box(kk_std_text_parse__new_mlift_pint_10596_fun2902(_ctx), _ctx), _ctx), _ctx); /*46*/
        }
      }
    }
    x_0_11077 = kk_std_core_types__maybe_unbox(_x_x2899, KK_OWNED, _ctx); /*maybe<char>*/
    if (kk_yielding(kk_context())) {
      kk_std_core_types__maybe_drop(x_0_11077, _ctx);
      kk_box_t _x_x2911 = kk_std_core_hnd_yield_extend(kk_std_text_parse__new_mlift_pint_10596_fun2912(_ctx), _ctx); /*2419*/
      x_11075 = kk_char_unbox(_x_x2911, KK_OWNED, _ctx); /*char*/
    }
    else {
      x_11075 = kk_std_text_parse__mlift_pint_10594(x_0_11077, _ctx); /*char*/
    }
  }
  else {
    x_11075 = '+'; /*char*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2915 = kk_std_core_hnd_yield_extend(kk_std_text_parse__new_mlift_pint_10596_fun2916(_ctx), _ctx); /*2419*/
    return kk_integer_unbox(_x_x2915, _ctx);
  }
  {
    return kk_std_text_parse__mlift_pint_10595(x_11075, _ctx);
  }
}


// lift anonymous function
struct kk_std_text_parse_pint_fun2923__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_pint_fun2923(kk_function_t _fself, kk_box_t _b_x1602, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_pint_fun2923(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_pint_fun2923, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_text_parse_pint_fun2923(kk_function_t _fself, kk_box_t _b_x1602, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x2924;
  bool _x_x2925 = kk_bool_unbox(_b_x1602); /*bool*/
  _x_x2924 = kk_std_text_parse__mlift_pint_10596(_x_x2925, _ctx); /*int*/
  return kk_integer_box(_x_x2924, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_pint_fun2929__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_pint_fun2929(kk_function_t _fself, kk_box_t _b_x1616, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_pint_fun2929(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_pint_fun2929, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_text_parse_pint_fun2929(kk_function_t _fself, kk_box_t _b_x1616, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__maybe _x_x2930;
  kk_std_core_types__maybe _match_x1798;
  kk_std_core_sslice__sslice _x_x2931 = kk_std_core_sslice__sslice_unbox(_b_x1616, KK_OWNED, _ctx); /*sslice/sslice*/
  _match_x1798 = kk_std_core_sslice_next(_x_x2931, _ctx); /*maybe<(char, sslice/sslice)>*/
  if (kk_std_core_types__is_Just(_match_x1798, _ctx)) {
    kk_box_t _box_x1617 = _match_x1798._cons.Just.value;
    kk_std_core_types__tuple2 _pat_0_0_0 = kk_std_core_types__tuple2_unbox(_box_x1617, KK_BORROWED, _ctx);
    if (kk_std_core_types__is_Tuple2(_pat_0_0_0, _ctx)) {
      kk_box_t _box_x1618 = _pat_0_0_0.fst;
      kk_box_t _box_x1619 = _pat_0_0_0.snd;
      kk_char_t c = kk_char_unbox(_box_x1618, KK_BORROWED, _ctx);
      kk_string_t _x_x2933;
      kk_define_string_literal(static, _s_x2934, 2, "+-", _ctx)
      _x_x2933 = kk_string_dup(_s_x2934, _ctx); /*string*/
      kk_string_t _x_x2935 = kk_std_core_string_char_fs_string(c, _ctx); /*string*/
      if (kk_string_contains(_x_x2933,_x_x2935,kk_context())) {
        kk_std_core_sslice__sslice rest = kk_std_core_sslice__sslice_unbox(_box_x1619, KK_BORROWED, _ctx);
        kk_std_core_sslice__sslice_dup(rest, _ctx);
        kk_std_core_types__maybe_drop(_match_x1798, _ctx);
        kk_box_t _x_x2936;
        kk_std_core_types__tuple2 _x_x2937 = kk_std_core_types__new_Tuple2(kk_char_box(c, _ctx), kk_std_core_sslice__sslice_box(rest, _ctx), _ctx); /*(134, 135)*/
        _x_x2936 = kk_std_core_types__tuple2_box(_x_x2937, _ctx); /*88*/
        _x_x2930 = kk_std_core_types__new_Just(_x_x2936, _ctx); /*maybe<88>*/
        goto _match_x2932;
      }
    }
  }
  {
    kk_std_core_types__maybe_drop(_match_x1798, _ctx);
    _x_x2930 = kk_std_core_types__new_Nothing(_ctx); /*maybe<88>*/
  }
  _match_x2932: ;
  return kk_std_core_types__maybe_box(_x_x2930, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_pint_fun2939__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_pint_fun2939(kk_function_t _fself, kk_box_t _b_x1628, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_pint_fun2939(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_pint_fun2939, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_text_parse_pint_fun2939(kk_function_t _fself, kk_box_t _b_x1628, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t _x_x2940;
  kk_std_core_types__maybe _x_x2941 = kk_std_core_types__maybe_unbox(_b_x1628, KK_OWNED, _ctx); /*maybe<char>*/
  _x_x2940 = kk_std_text_parse__mlift_pint_10594(_x_x2941, _ctx); /*char*/
  return kk_char_box(_x_x2940, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_pint_fun2943__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_pint_fun2943(kk_function_t _fself, kk_box_t _b_x1631, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_pint_fun2943(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_pint_fun2943, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_text_parse_pint_fun2943(kk_function_t _fself, kk_box_t _b_x1631, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_integer_t _x_x2944;
  kk_char_t _x_x2945 = kk_char_unbox(_b_x1631, KK_OWNED, _ctx); /*char*/
  _x_x2944 = kk_std_text_parse__mlift_pint_10595(_x_x2945, _ctx); /*int*/
  return kk_integer_box(_x_x2944, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_pint_fun2949__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_pint_fun2949(kk_function_t _fself, kk_box_t _b_x1645, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_pint_fun2949(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_pint_fun2949, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_text_parse_pint_fun2949(kk_function_t _fself, kk_box_t _b_x1645, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__maybe _x_x2950;
  kk_std_core_types__tuple2 _match_x1796;
  kk_std_core_sslice__sslice _x_x2951 = kk_std_core_sslice__sslice_unbox(_b_x1645, KK_OWNED, _ctx); /*sslice/sslice*/
  _match_x1796 = kk_std_text_parse__lift_pint_10359(_x_x2951, kk_std_core_types__new_Nil(_ctx), _ctx); /*(list<char>, sslice/sslice)*/
  {
    kk_box_t _box_x1646 = _match_x1796.fst;
    kk_box_t _box_x1647 = _match_x1796.snd;
    kk_std_core_types__list _pat_0_2_0_0_0 = kk_std_core_types__list_unbox(_box_x1646, KK_BORROWED, _ctx);
    kk_std_core_sslice__sslice _pat_1_0_0_0 = kk_std_core_sslice__sslice_unbox(_box_x1647, KK_BORROWED, _ctx);
    if (kk_std_core_types__is_Nil(_pat_0_2_0_0_0, _ctx)) {
      kk_std_core_types__tuple2_drop(_match_x1796, _ctx);
      _x_x2950 = kk_std_core_types__new_Nothing(_ctx); /*forall<a> maybe<a>*/
      goto _match_x2952;
    }
  }
  {
    kk_box_t _box_x1648 = _match_x1796.fst;
    kk_box_t _box_x1649 = _match_x1796.snd;
    kk_std_core_sslice__sslice rest_0 = kk_std_core_sslice__sslice_unbox(_box_x1649, KK_BORROWED, _ctx);
    kk_std_core_types__list xs = kk_std_core_types__list_unbox(_box_x1648, KK_BORROWED, _ctx);
    kk_std_core_sslice__sslice_dup(rest_0, _ctx);
    kk_std_core_types__list_dup(xs, _ctx);
    kk_std_core_types__tuple2_drop(_match_x1796, _ctx);
    kk_box_t _x_x2953;
    kk_std_core_types__tuple2 _x_x2954 = kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(xs, _ctx), kk_std_core_sslice__sslice_box(rest_0, _ctx), _ctx); /*(134, 135)*/
    _x_x2953 = kk_std_core_types__tuple2_box(_x_x2954, _ctx); /*88*/
    _x_x2950 = kk_std_core_types__new_Just(_x_x2953, _ctx); /*forall<a> maybe<a>*/
  }
  _match_x2952: ;
  return kk_std_core_types__maybe_box(_x_x2950, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_pint_fun2956__t {
  struct kk_function_s _base;
  bool neg;
};
static kk_box_t kk_std_text_parse_pint_fun2956(kk_function_t _fself, kk_box_t _b_x1658, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_pint_fun2956(bool neg, kk_context_t* _ctx) {
  struct kk_std_text_parse_pint_fun2956__t* _self = kk_function_alloc_as(struct kk_std_text_parse_pint_fun2956__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_text_parse_pint_fun2956, kk_context());
  _self->neg = neg;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_text_parse_pint_fun2956(kk_function_t _fself, kk_box_t _b_x1658, kk_context_t* _ctx) {
  struct kk_std_text_parse_pint_fun2956__t* _self = kk_function_as(struct kk_std_text_parse_pint_fun2956__t*, _fself, _ctx);
  bool neg = _self->neg; /* bool */
  kk_drop_match(_self, {kk_skip_dup(neg, _ctx);}, {}, _ctx)
  kk_std_core_types__maybe _y_x10499_1677 = kk_std_core_types__maybe_unbox(_b_x1658, KK_OWNED, _ctx); /*maybe<list<char>>*/;
  kk_integer_t _x_x2957 = kk_std_text_parse__mlift_pint_10593(neg, _y_x10499_1677, _ctx); /*int*/
  return kk_integer_box(_x_x2957, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_pint_fun2965__t {
  struct kk_function_s _base;
  bool neg;
};
static kk_box_t kk_std_text_parse_pint_fun2965(kk_function_t _fself, kk_box_t _b_x1669, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_pint_fun2965(bool neg, kk_context_t* _ctx) {
  struct kk_std_text_parse_pint_fun2965__t* _self = kk_function_alloc_as(struct kk_std_text_parse_pint_fun2965__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_text_parse_pint_fun2965, kk_context());
  _self->neg = neg;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_text_parse_pint_fun2965(kk_function_t _fself, kk_box_t _b_x1669, kk_context_t* _ctx) {
  struct kk_std_text_parse_pint_fun2965__t* _self = kk_function_as(struct kk_std_text_parse_pint_fun2965__t*, _fself, _ctx);
  bool neg = _self->neg; /* bool */
  kk_drop_match(_self, {kk_skip_dup(neg, _ctx);}, {}, _ctx)
  kk_std_core_types__list _c_x10501_1678 = kk_std_core_types__list_unbox(_b_x1669, KK_OWNED, _ctx); /*list<char>*/;
  kk_integer_t _x_x2966 = kk_std_text_parse__mlift_pint_10592(neg, _c_x10501_1678, _ctx); /*int*/
  return kk_integer_box(_x_x2966, _ctx);
}

kk_integer_t kk_std_text_parse_pint(kk_context_t* _ctx) { /* () -> parse int */ 
  kk_std_core_hnd__ev ev_11085 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
  bool x_11082;
  kk_box_t _x_x2919;
  {
    struct kk_std_core_hnd_Ev* _con_x2920 = kk_std_core_hnd__as_Ev(ev_11085, _ctx);
    kk_box_t _box_x1595 = _con_x2920->hnd;
    int32_t m = _con_x2920->marker;
    kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x1595, KK_BORROWED, _ctx);
    kk_std_text_parse__parse_dup(h, _ctx);
    {
      struct kk_std_text_parse__Hnd_parse* _con_x2921 = kk_std_text_parse__as_Hnd_parse(h, _ctx);
      kk_integer_t _pat_0 = _con_x2921->_cfc;
      kk_std_core_hnd__clause0 _pat_1_1 = _con_x2921->_fun_current_input;
      kk_std_core_hnd__clause1 _pat_2 = _con_x2921->_brk_fail;
      kk_std_core_hnd__clause0 _ctl_pick = _con_x2921->_ctl_pick;
      kk_std_core_hnd__clause1 _pat_3 = _con_x2921->_fun_satisfy;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause1_drop(_pat_3, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_2, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_1_1, _ctx);
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause0_dup(_ctl_pick, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x1598 = _ctl_pick.clause;
        _x_x2919 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x1598, (_fun_unbox_x1598, m, ev_11085, _ctx), _ctx); /*35*/
      }
    }
  }
  x_11082 = kk_bool_unbox(_x_x2919); /*bool*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2922 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_pint_fun2923(_ctx), _ctx); /*2419*/
    return kk_integer_unbox(_x_x2922, _ctx);
  }
  {
    kk_char_t x_0_11087;
    if (x_11082) {
      kk_std_core_hnd__ev ev_0_11092 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
      kk_std_core_types__maybe x_1_11090;
      kk_box_t _x_x2926;
      {
        struct kk_std_core_hnd_Ev* _con_x2927 = kk_std_core_hnd__as_Ev(ev_0_11092, _ctx);
        kk_box_t _box_x1603 = _con_x2927->hnd;
        int32_t m_0 = _con_x2927->marker;
        kk_std_text_parse__parse h_0 = kk_std_text_parse__parse_unbox(_box_x1603, KK_BORROWED, _ctx);
        kk_std_text_parse__parse_dup(h_0, _ctx);
        {
          struct kk_std_text_parse__Hnd_parse* _con_x2928 = kk_std_text_parse__as_Hnd_parse(h_0, _ctx);
          kk_integer_t _pat_0_2 = _con_x2928->_cfc;
          kk_std_core_hnd__clause0 _pat_1_2 = _con_x2928->_fun_current_input;
          kk_std_core_hnd__clause1 _pat_2_1 = _con_x2928->_brk_fail;
          kk_std_core_hnd__clause0 _pat_3_0 = _con_x2928->_ctl_pick;
          kk_std_core_hnd__clause1 _fun_satisfy = _con_x2928->_fun_satisfy;
          if kk_likely(kk_datatype_ptr_is_unique(h_0, _ctx)) {
            kk_std_core_hnd__clause0_drop(_pat_3_0, _ctx);
            kk_std_core_hnd__clause1_drop(_pat_2_1, _ctx);
            kk_std_core_hnd__clause0_drop(_pat_1_2, _ctx);
            kk_integer_drop(_pat_0_2, _ctx);
            kk_datatype_ptr_free(h_0, _ctx);
          }
          else {
            kk_std_core_hnd__clause1_dup(_fun_satisfy, _ctx);
            kk_datatype_ptr_decref(h_0, _ctx);
          }
          {
            kk_function_t _fun_unbox_x1610 = _fun_satisfy.clause;
            _x_x2926 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x1610, (_fun_unbox_x1610, m_0, ev_0_11092, kk_function_box(kk_std_text_parse_new_pint_fun2929(_ctx), _ctx), _ctx), _ctx); /*46*/
          }
        }
      }
      x_1_11090 = kk_std_core_types__maybe_unbox(_x_x2926, KK_OWNED, _ctx); /*maybe<char>*/
      if (kk_yielding(kk_context())) {
        kk_std_core_types__maybe_drop(x_1_11090, _ctx);
        kk_box_t _x_x2938 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_pint_fun2939(_ctx), _ctx); /*2419*/
        x_0_11087 = kk_char_unbox(_x_x2938, KK_OWNED, _ctx); /*char*/
      }
      else {
        x_0_11087 = kk_std_text_parse__mlift_pint_10594(x_1_11090, _ctx); /*char*/
      }
    }
    else {
      x_0_11087 = '+'; /*char*/
    }
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x2942 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_pint_fun2943(_ctx), _ctx); /*2419*/
      return kk_integer_unbox(_x_x2942, _ctx);
    }
    {
      bool neg = (x_0_11087 == ('-')); /*bool*/;
      kk_std_core_hnd__ev ev_1_11098 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
      kk_std_core_types__maybe x_3_11095;
      kk_box_t _x_x2946;
      {
        struct kk_std_core_hnd_Ev* _con_x2947 = kk_std_core_hnd__as_Ev(ev_1_11098, _ctx);
        kk_box_t _box_x1632 = _con_x2947->hnd;
        int32_t m_1 = _con_x2947->marker;
        kk_std_text_parse__parse h_1 = kk_std_text_parse__parse_unbox(_box_x1632, KK_BORROWED, _ctx);
        kk_std_text_parse__parse_dup(h_1, _ctx);
        {
          struct kk_std_text_parse__Hnd_parse* _con_x2948 = kk_std_text_parse__as_Hnd_parse(h_1, _ctx);
          kk_integer_t _pat_0_4 = _con_x2948->_cfc;
          kk_std_core_hnd__clause0 _pat_1_4 = _con_x2948->_fun_current_input;
          kk_std_core_hnd__clause1 _pat_2_2 = _con_x2948->_brk_fail;
          kk_std_core_hnd__clause0 _pat_3_2 = _con_x2948->_ctl_pick;
          kk_std_core_hnd__clause1 _fun_satisfy_0 = _con_x2948->_fun_satisfy;
          if kk_likely(kk_datatype_ptr_is_unique(h_1, _ctx)) {
            kk_std_core_hnd__clause0_drop(_pat_3_2, _ctx);
            kk_std_core_hnd__clause1_drop(_pat_2_2, _ctx);
            kk_std_core_hnd__clause0_drop(_pat_1_4, _ctx);
            kk_integer_drop(_pat_0_4, _ctx);
            kk_datatype_ptr_free(h_1, _ctx);
          }
          else {
            kk_std_core_hnd__clause1_dup(_fun_satisfy_0, _ctx);
            kk_datatype_ptr_decref(h_1, _ctx);
          }
          {
            kk_function_t _fun_unbox_x1639 = _fun_satisfy_0.clause;
            _x_x2946 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x1639, (_fun_unbox_x1639, m_1, ev_1_11098, kk_function_box(kk_std_text_parse_new_pint_fun2949(_ctx), _ctx), _ctx), _ctx); /*46*/
          }
        }
      }
      x_3_11095 = kk_std_core_types__maybe_unbox(_x_x2946, KK_OWNED, _ctx); /*maybe<list<char>>*/
      if (kk_yielding(kk_context())) {
        kk_std_core_types__maybe_drop(x_3_11095, _ctx);
        kk_box_t _x_x2955 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_pint_fun2956(neg, _ctx), _ctx); /*2419*/
        return kk_integer_unbox(_x_x2955, _ctx);
      }
      {
        kk_std_core_types__list x_5_11101;
        if (kk_std_core_types__is_Nothing(x_3_11095, _ctx)) {
          kk_std_core_hnd__ev ev_2_11104 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
          kk_box_t _x_x2958;
          {
            struct kk_std_core_hnd_Ev* _con_x2959 = kk_std_core_hnd__as_Ev(ev_2_11104, _ctx);
            kk_box_t _box_x1659 = _con_x2959->hnd;
            int32_t m_2 = _con_x2959->marker;
            kk_std_text_parse__parse h_2 = kk_std_text_parse__parse_unbox(_box_x1659, KK_BORROWED, _ctx);
            kk_std_text_parse__parse_dup(h_2, _ctx);
            {
              struct kk_std_text_parse__Hnd_parse* _con_x2960 = kk_std_text_parse__as_Hnd_parse(h_2, _ctx);
              kk_integer_t _pat_0_6 = _con_x2960->_cfc;
              kk_std_core_hnd__clause0 _pat_1_5 = _con_x2960->_fun_current_input;
              kk_std_core_hnd__clause1 _brk_fail = _con_x2960->_brk_fail;
              kk_std_core_hnd__clause0 _pat_2_3 = _con_x2960->_ctl_pick;
              kk_std_core_hnd__clause1 _pat_3_3 = _con_x2960->_fun_satisfy;
              if kk_likely(kk_datatype_ptr_is_unique(h_2, _ctx)) {
                kk_std_core_hnd__clause1_drop(_pat_3_3, _ctx);
                kk_std_core_hnd__clause0_drop(_pat_2_3, _ctx);
                kk_std_core_hnd__clause0_drop(_pat_1_5, _ctx);
                kk_integer_drop(_pat_0_6, _ctx);
                kk_datatype_ptr_free(h_2, _ctx);
              }
              else {
                kk_std_core_hnd__clause1_dup(_brk_fail, _ctx);
                kk_datatype_ptr_decref(h_2, _ctx);
              }
              {
                kk_function_t _fun_unbox_x1663 = _brk_fail.clause;
                kk_box_t _x_x2961;
                kk_string_t _x_x2962;
                kk_define_string_literal(static, _s_x2963, 5, "digit", _ctx)
                _x_x2962 = kk_string_dup(_s_x2963, _ctx); /*string*/
                _x_x2961 = kk_string_box(_x_x2962); /*45*/
                _x_x2958 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x1663, (_fun_unbox_x1663, m_2, ev_2_11104, _x_x2961, _ctx), _ctx); /*46*/
              }
            }
          }
          x_5_11101 = kk_std_core_types__list_unbox(_x_x2958, KK_OWNED, _ctx); /*list<char>*/
        }
        else {
          kk_box_t _box_x1667 = x_3_11095._cons.Just.value;
          kk_std_core_types__list x_0_0 = kk_std_core_types__list_unbox(_box_x1667, KK_BORROWED, _ctx);
          kk_std_core_types__list_dup(x_0_0, _ctx);
          kk_std_core_types__maybe_drop(x_3_11095, _ctx);
          x_5_11101 = x_0_0; /*list<char>*/
        }
        if (kk_yielding(kk_context())) {
          kk_std_core_types__list_drop(x_5_11101, _ctx);
          kk_box_t _x_x2964 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_pint_fun2965(neg, _ctx), _ctx); /*2419*/
          return kk_integer_unbox(_x_x2964, _ctx);
        }
        {
          kk_string_t _x_x1_0_10544 = kk_std_core_string_listchar_fs_string(x_5_11101, _ctx); /*string*/;
          kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
          kk_std_core_types__maybe x_7;
          bool _x_x2967;
          kk_std_core_types__optional _match_x1795 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
          if (kk_std_core_types__is_Optional(_match_x1795, _ctx)) {
            kk_box_t _box_x1670 = _match_x1795._cons._Optional.value;
            bool _uniq_hex_581 = kk_bool_unbox(_box_x1670);
            kk_std_core_types__optional_drop(_match_x1795, _ctx);
            _x_x2967 = _uniq_hex_581; /*bool*/
          }
          else {
            kk_std_core_types__optional_drop(_match_x1795, _ctx);
            _x_x2967 = false; /*bool*/
          }
          x_7 = kk_std_core_int_xparse(_x_x1_0_10544, _x_x2967, _ctx); /*maybe<int>*/
          kk_unit_t keep = kk_Unit;
          kk_evv_set(w,kk_context());
          kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<std/text/parse/parse>*/;
          kk_unit_t keep_0 = kk_Unit;
          kk_evv_set(w_0,kk_context());
          if (neg) {
            kk_integer_t _x_x2968;
            if (kk_std_core_types__is_Nothing(x_7, _ctx)) {
              _x_x2968 = kk_integer_from_small(0); /*int*/
            }
            else {
              kk_box_t _box_x1671 = x_7._cons.Just.value;
              kk_integer_t x_0_1 = kk_integer_unbox(_box_x1671, _ctx);
              kk_integer_dup(x_0_1, _ctx);
              kk_std_core_types__maybe_drop(x_7, _ctx);
              _x_x2968 = x_0_1; /*int*/
            }
            return kk_integer_neg(_x_x2968,kk_context());
          }
          if (kk_std_core_types__is_Nothing(x_7, _ctx)) {
            return kk_integer_from_small(0);
          }
          {
            kk_box_t _box_x1672 = x_7._cons.Just.value;
            kk_integer_t x_0_1_0 = kk_integer_unbox(_box_x1672, _ctx);
            kk_integer_dup(x_0_1_0, _ctx);
            kk_std_core_types__maybe_drop(x_7, _ctx);
            return x_0_1_0;
          }
        }
      }
    }
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_text_parse__mlift_sep_by1_10599_fun2969__t {
  struct kk_function_s _base;
  kk_function_t p;
  kk_function_t sep;
};
static kk_box_t kk_std_text_parse__mlift_sep_by1_10599_fun2969(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse__new_mlift_sep_by1_10599_fun2969(kk_function_t p, kk_function_t sep, kk_context_t* _ctx) {
  struct kk_std_text_parse__mlift_sep_by1_10599_fun2969__t* _self = kk_function_alloc_as(struct kk_std_text_parse__mlift_sep_by1_10599_fun2969__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_text_parse__mlift_sep_by1_10599_fun2969, kk_context());
  _self->p = p;
  _self->sep = sep;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_text_parse__mlift_sep_by1_10599_fun2970__t {
  struct kk_function_s _base;
  kk_function_t p;
};
static kk_box_t kk_std_text_parse__mlift_sep_by1_10599_fun2970(kk_function_t _fself, kk_box_t wild__, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse__new_mlift_sep_by1_10599_fun2970(kk_function_t p, kk_context_t* _ctx) {
  struct kk_std_text_parse__mlift_sep_by1_10599_fun2970__t* _self = kk_function_alloc_as(struct kk_std_text_parse__mlift_sep_by1_10599_fun2970__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_text_parse__mlift_sep_by1_10599_fun2970, kk_context());
  _self->p = p;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_text_parse__mlift_sep_by1_10599_fun2970(kk_function_t _fself, kk_box_t wild__, kk_context_t* _ctx) {
  struct kk_std_text_parse__mlift_sep_by1_10599_fun2970__t* _self = kk_function_as(struct kk_std_text_parse__mlift_sep_by1_10599_fun2970__t*, _fself, _ctx);
  kk_function_t p = _self->p; /* std/text/parse/parser<3145,3143> */
  kk_drop_match(_self, {kk_function_dup(p, _ctx);}, {}, _ctx)
  kk_box_drop(wild__, _ctx);
  return kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), p, (p, _ctx), _ctx);
}
static kk_box_t kk_std_text_parse__mlift_sep_by1_10599_fun2969(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_text_parse__mlift_sep_by1_10599_fun2969__t* _self = kk_function_as(struct kk_std_text_parse__mlift_sep_by1_10599_fun2969__t*, _fself, _ctx);
  kk_function_t p = _self->p; /* std/text/parse/parser<3145,3143> */
  kk_function_t sep = _self->sep; /* std/text/parse/parser<3145,3144> */
  kk_drop_match(_self, {kk_function_dup(p, _ctx);kk_function_dup(sep, _ctx);}, {}, _ctx)
  kk_box_t x_0_11115 = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), sep, (sep, _ctx), _ctx); /*3144*/;
  kk_box_drop(x_0_11115, _ctx);
  if (kk_yielding(kk_context())) {
    return kk_std_core_hnd_yield_extend(kk_std_text_parse__new_mlift_sep_by1_10599_fun2970(p, _ctx), _ctx);
  }
  {
    return kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), p, (p, _ctx), _ctx);
  }
}


// lift anonymous function
struct kk_std_text_parse__mlift_sep_by1_10599_fun2972__t {
  struct kk_function_s _base;
  kk_box_t _y_x10503;
};
static kk_box_t kk_std_text_parse__mlift_sep_by1_10599_fun2972(kk_function_t _fself, kk_box_t _b_x1680, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse__new_mlift_sep_by1_10599_fun2972(kk_box_t _y_x10503, kk_context_t* _ctx) {
  struct kk_std_text_parse__mlift_sep_by1_10599_fun2972__t* _self = kk_function_alloc_as(struct kk_std_text_parse__mlift_sep_by1_10599_fun2972__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_text_parse__mlift_sep_by1_10599_fun2972, kk_context());
  _self->_y_x10503 = _y_x10503;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_text_parse__mlift_sep_by1_10599_fun2972(kk_function_t _fself, kk_box_t _b_x1680, kk_context_t* _ctx) {
  struct kk_std_text_parse__mlift_sep_by1_10599_fun2972__t* _self = kk_function_as(struct kk_std_text_parse__mlift_sep_by1_10599_fun2972__t*, _fself, _ctx);
  kk_box_t _y_x10503 = _self->_y_x10503; /* 3143 */
  kk_drop_match(_self, {kk_box_dup(_y_x10503, _ctx);}, {}, _ctx)
  kk_std_core_types__list _y_x10506_1682 = kk_std_core_types__list_unbox(_b_x1680, KK_OWNED, _ctx); /*list<3143>*/;
  kk_std_core_types__list _x_x2973 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _y_x10503, _y_x10506_1682, _ctx); /*list<79>*/
  return kk_std_core_types__list_box(_x_x2973, _ctx);
}

kk_std_core_types__list kk_std_text_parse__mlift_sep_by1_10599(kk_function_t p, kk_function_t sep, kk_box_t _y_x10503, kk_context_t* _ctx) { /* forall<a,b,e> (p : parser<e,a>, sep : parser<e,b>, a) -> <parse|e> list<a> */ 
  kk_std_core_types__list x_11113 = kk_std_text_parse_many_acc(kk_std_text_parse__new_mlift_sep_by1_10599_fun2969(p, sep, _ctx), kk_std_core_types__new_Nil(_ctx), _ctx); /*list<3143>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_11113, _ctx);
    kk_box_t _x_x2971 = kk_std_core_hnd_yield_extend(kk_std_text_parse__new_mlift_sep_by1_10599_fun2972(_y_x10503, _ctx), _ctx); /*2419*/
    return kk_std_core_types__list_unbox(_x_x2971, KK_OWNED, _ctx);
  }
  {
    return kk_std_core_types__new_Cons(kk_reuse_null, 0, _y_x10503, x_11113, _ctx);
  }
}
 
// The `sep-by1` parses one or more occurrences of `p`, separated by `sep`. Returns a list of the results of `p`.
// The `sep-by1` combinator is non-divergent only when `p` always consumes input or `fail`s.


// lift anonymous function
struct kk_std_text_parse_sep_by1_fun2976__t {
  struct kk_function_s _base;
  kk_function_t p;
  kk_function_t sep;
};
static kk_box_t kk_std_text_parse_sep_by1_fun2976(kk_function_t _fself, kk_box_t _b_x1684, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_sep_by1_fun2976(kk_function_t p, kk_function_t sep, kk_context_t* _ctx) {
  struct kk_std_text_parse_sep_by1_fun2976__t* _self = kk_function_alloc_as(struct kk_std_text_parse_sep_by1_fun2976__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_text_parse_sep_by1_fun2976, kk_context());
  _self->p = p;
  _self->sep = sep;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_text_parse_sep_by1_fun2976(kk_function_t _fself, kk_box_t _b_x1684, kk_context_t* _ctx) {
  struct kk_std_text_parse_sep_by1_fun2976__t* _self = kk_function_as(struct kk_std_text_parse_sep_by1_fun2976__t*, _fself, _ctx);
  kk_function_t p = _self->p; /* std/text/parse/parser<3145,3143> */
  kk_function_t sep = _self->sep; /* std/text/parse/parser<3145,3144> */
  kk_drop_match(_self, {kk_function_dup(p, _ctx);kk_function_dup(sep, _ctx);}, {}, _ctx)
  kk_box_t _y_x10503_1689 = _b_x1684; /*3143*/;
  kk_std_core_types__list _x_x2977 = kk_std_text_parse__mlift_sep_by1_10599(p, sep, _y_x10503_1689, _ctx); /*list<3143>*/
  return kk_std_core_types__list_box(_x_x2977, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_sep_by1_fun2978__t {
  struct kk_function_s _base;
  kk_function_t p;
  kk_function_t sep;
};
static kk_box_t kk_std_text_parse_sep_by1_fun2978(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_sep_by1_fun2978(kk_function_t p, kk_function_t sep, kk_context_t* _ctx) {
  struct kk_std_text_parse_sep_by1_fun2978__t* _self = kk_function_alloc_as(struct kk_std_text_parse_sep_by1_fun2978__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_text_parse_sep_by1_fun2978, kk_context());
  _self->p = p;
  _self->sep = sep;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_std_text_parse_sep_by1_fun2979__t {
  struct kk_function_s _base;
  kk_function_t p;
};
static kk_box_t kk_std_text_parse_sep_by1_fun2979(kk_function_t _fself, kk_box_t wild__, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_sep_by1_fun2979(kk_function_t p, kk_context_t* _ctx) {
  struct kk_std_text_parse_sep_by1_fun2979__t* _self = kk_function_alloc_as(struct kk_std_text_parse_sep_by1_fun2979__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_text_parse_sep_by1_fun2979, kk_context());
  _self->p = p;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_text_parse_sep_by1_fun2979(kk_function_t _fself, kk_box_t wild__, kk_context_t* _ctx) {
  struct kk_std_text_parse_sep_by1_fun2979__t* _self = kk_function_as(struct kk_std_text_parse_sep_by1_fun2979__t*, _fself, _ctx);
  kk_function_t p = _self->p; /* std/text/parse/parser<3145,3143> */
  kk_drop_match(_self, {kk_function_dup(p, _ctx);}, {}, _ctx)
  kk_box_drop(wild__, _ctx);
  return kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), p, (p, _ctx), _ctx);
}
static kk_box_t kk_std_text_parse_sep_by1_fun2978(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_std_text_parse_sep_by1_fun2978__t* _self = kk_function_as(struct kk_std_text_parse_sep_by1_fun2978__t*, _fself, _ctx);
  kk_function_t p = _self->p; /* std/text/parse/parser<3145,3143> */
  kk_function_t sep = _self->sep; /* std/text/parse/parser<3145,3144> */
  kk_drop_match(_self, {kk_function_dup(p, _ctx);kk_function_dup(sep, _ctx);}, {}, _ctx)
  kk_box_t x_1_11127 = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), sep, (sep, _ctx), _ctx); /*3144*/;
  kk_box_drop(x_1_11127, _ctx);
  if (kk_yielding(kk_context())) {
    return kk_std_core_hnd_yield_extend(kk_std_text_parse_new_sep_by1_fun2979(p, _ctx), _ctx);
  }
  {
    return kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), p, (p, _ctx), _ctx);
  }
}


// lift anonymous function
struct kk_std_text_parse_sep_by1_fun2981__t {
  struct kk_function_s _base;
  kk_box_t x_11121;
};
static kk_box_t kk_std_text_parse_sep_by1_fun2981(kk_function_t _fself, kk_box_t _b_x1686, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_sep_by1_fun2981(kk_box_t x_11121, kk_context_t* _ctx) {
  struct kk_std_text_parse_sep_by1_fun2981__t* _self = kk_function_alloc_as(struct kk_std_text_parse_sep_by1_fun2981__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_text_parse_sep_by1_fun2981, kk_context());
  _self->x_11121 = x_11121;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_text_parse_sep_by1_fun2981(kk_function_t _fself, kk_box_t _b_x1686, kk_context_t* _ctx) {
  struct kk_std_text_parse_sep_by1_fun2981__t* _self = kk_function_as(struct kk_std_text_parse_sep_by1_fun2981__t*, _fself, _ctx);
  kk_box_t x_11121 = _self->x_11121; /* 3143 */
  kk_drop_match(_self, {kk_box_dup(x_11121, _ctx);}, {}, _ctx)
  kk_std_core_types__list _y_x10506_1690 = kk_std_core_types__list_unbox(_b_x1686, KK_OWNED, _ctx); /*list<3143>*/;
  kk_std_core_types__list _x_x2982 = kk_std_core_types__new_Cons(kk_reuse_null, 0, x_11121, _y_x10506_1690, _ctx); /*list<79>*/
  return kk_std_core_types__list_box(_x_x2982, _ctx);
}

kk_std_core_types__list kk_std_text_parse_sep_by1(kk_function_t p, kk_function_t sep, kk_context_t* _ctx) { /* forall<a,b,e> (p : parser<e,a>, sep : parser<e,b>) -> <parse|e> list<a> */ 
  kk_box_t x_11121;
  kk_function_t _x_x2974 = kk_function_dup(p, _ctx); /*std/text/parse/parser<3145,3143>*/
  x_11121 = kk_function_call(kk_box_t, (kk_function_t, kk_context_t*), _x_x2974, (_x_x2974, _ctx), _ctx); /*3143*/
  if (kk_yielding(kk_context())) {
    kk_box_drop(x_11121, _ctx);
    kk_box_t _x_x2975 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_sep_by1_fun2976(p, sep, _ctx), _ctx); /*2419*/
    return kk_std_core_types__list_unbox(_x_x2975, KK_OWNED, _ctx);
  }
  {
    kk_std_core_types__list x_0_11124 = kk_std_text_parse_many_acc(kk_std_text_parse_new_sep_by1_fun2978(p, sep, _ctx), kk_std_core_types__new_Nil(_ctx), _ctx); /*list<3143>*/;
    if (kk_yielding(kk_context())) {
      kk_std_core_types__list_drop(x_0_11124, _ctx);
      kk_box_t _x_x2980 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_sep_by1_fun2981(x_11121, _ctx), _ctx); /*2419*/
      return kk_std_core_types__list_unbox(_x_x2980, KK_OWNED, _ctx);
    }
    {
      return kk_std_core_types__new_Cons(kk_reuse_null, 0, x_11121, x_0_11124, _ctx);
    }
  }
}
 
// The `sep-by` parses zero or more occurrences of `p`, separated by `sep`. Returns a list of the results of `p`.
// The `sep-by` combinator is non-divergent only when `p` always consumes input or `fail`s.


// lift anonymous function
struct kk_std_text_parse_sep_by_fun2988__t {
  struct kk_function_s _base;
  kk_ssize_t i_11136;
};
static kk_box_t kk_std_text_parse_sep_by_fun2988(kk_function_t _fself, kk_function_t _b_x1702, kk_box_t _b_x1703, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_sep_by_fun2988(kk_ssize_t i_11136, kk_context_t* _ctx) {
  struct kk_std_text_parse_sep_by_fun2988__t* _self = kk_function_alloc_as(struct kk_std_text_parse_sep_by_fun2988__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_text_parse_sep_by_fun2988, kk_context());
  _self->i_11136 = i_11136;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_text_parse_sep_by_fun2988(kk_function_t _fself, kk_function_t _b_x1702, kk_box_t _b_x1703, kk_context_t* _ctx) {
  struct kk_std_text_parse_sep_by_fun2988__t* _self = kk_function_as(struct kk_std_text_parse_sep_by_fun2988__t*, _fself, _ctx);
  kk_ssize_t i_11136 = _self->i_11136; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_11136, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_11136, _b_x1702, _b_x1703, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_sep_by_fun2990__t {
  struct kk_function_s _base;
  kk_function_t p;
  kk_function_t sep;
};
static kk_box_t kk_std_text_parse_sep_by_fun2990(kk_function_t _fself, kk_box_t _b_x1712, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_sep_by_fun2990(kk_function_t p, kk_function_t sep, kk_context_t* _ctx) {
  struct kk_std_text_parse_sep_by_fun2990__t* _self = kk_function_alloc_as(struct kk_std_text_parse_sep_by_fun2990__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_text_parse_sep_by_fun2990, kk_context());
  _self->p = p;
  _self->sep = sep;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_text_parse_sep_by_fun2990(kk_function_t _fself, kk_box_t _b_x1712, kk_context_t* _ctx) {
  struct kk_std_text_parse_sep_by_fun2990__t* _self = kk_function_as(struct kk_std_text_parse_sep_by_fun2990__t*, _fself, _ctx);
  kk_function_t p = _self->p; /* std/text/parse/parser<3198,3196> */
  kk_function_t sep = _self->sep; /* std/text/parse/parser<3198,3197> */
  kk_drop_match(_self, {kk_function_dup(p, _ctx);kk_function_dup(sep, _ctx);}, {}, _ctx)
  bool _y_x10508_1715 = kk_bool_unbox(_b_x1712); /*bool*/;
  kk_std_core_types__list _x_x2991;
  if (_y_x10508_1715) {
    _x_x2991 = kk_std_text_parse_sep_by1(p, sep, _ctx); /*list<3143>*/
  }
  else {
    kk_function_drop(sep, _ctx);
    kk_function_drop(p, _ctx);
    _x_x2991 = kk_std_core_types__new_Nil(_ctx); /*list<3143>*/
  }
  return kk_std_core_types__list_box(_x_x2991, _ctx);
}

kk_std_core_types__list kk_std_text_parse_sep_by(kk_function_t p, kk_function_t sep, kk_context_t* _ctx) { /* forall<a,b,e> (p : parser<e,a>, sep : parser<e,b>) -> <parse|e> list<a> */ 
  kk_ssize_t i_11136;
  kk_std_core_hnd__htag _x_x2983 = kk_std_core_hnd__htag_dup(kk_std_text_parse_parse_fs__tag, _ctx); /*hnd/htag<std/text/parse/parse>*/
  i_11136 = kk_std_core_hnd__evv_index(_x_x2983, _ctx); /*hnd/ev-index*/
  kk_evv_t w = kk_evv_swap_create1(i_11136,kk_context()); /*hnd/evv<<std/text/parse/parse|3198>>*/;
  kk_std_core_hnd__ev ev_11138 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
  bool y;
  kk_box_t _x_x2984;
  {
    struct kk_std_core_hnd_Ev* _con_x2985 = kk_std_core_hnd__as_Ev(ev_11138, _ctx);
    kk_box_t _box_x1691 = _con_x2985->hnd;
    int32_t m = _con_x2985->marker;
    kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x1691, KK_BORROWED, _ctx);
    kk_std_text_parse__parse_dup(h, _ctx);
    {
      struct kk_std_text_parse__Hnd_parse* _con_x2986 = kk_std_text_parse__as_Hnd_parse(h, _ctx);
      kk_integer_t _pat_0 = _con_x2986->_cfc;
      kk_std_core_hnd__clause0 _pat_1 = _con_x2986->_fun_current_input;
      kk_std_core_hnd__clause1 _pat_2_0 = _con_x2986->_brk_fail;
      kk_std_core_hnd__clause0 _ctl_pick = _con_x2986->_ctl_pick;
      kk_std_core_hnd__clause1 _pat_3 = _con_x2986->_fun_satisfy;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause1_drop(_pat_3, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_2_0, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_1, _ctx);
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause0_dup(_ctl_pick, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x1694 = _ctl_pick.clause;
        _x_x2984 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x1694, (_fun_unbox_x1694, m, ev_11138, _ctx), _ctx); /*35*/
      }
    }
  }
  y = kk_bool_unbox(_x_x2984); /*bool*/
  kk_unit_t __ = kk_Unit;
  kk_evv_set(w,kk_context());
  bool x_11133;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2987 = kk_std_core_hnd_yield_cont(kk_std_text_parse_new_sep_by_fun2988(i_11136, _ctx), _ctx); /*2568*/
    x_11133 = kk_bool_unbox(_x_x2987); /*bool*/
  }
  else {
    x_11133 = y; /*bool*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x2989 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_sep_by_fun2990(p, sep, _ctx), _ctx); /*2419*/
    return kk_std_core_types__list_unbox(_x_x2989, KK_OWNED, _ctx);
  }
  if (x_11133) {
    return kk_std_text_parse_sep_by1(p, sep, _ctx);
  }
  {
    kk_function_drop(sep, _ctx);
    kk_function_drop(p, _ctx);
    return kk_std_core_types__new_Nil(_ctx);
  }
}
 
// lifted local: hex-digits, @spec-x10352
// specialized: std/text/parse/next-while0, on parameters @uniq-pred@10343, using:
// @uniq-pred@10343 = std/core/char/is-hex-digit

kk_std_core_types__tuple2 kk_std_text_parse__lift_hex_digits_10360(kk_std_core_sslice__sslice _uniq_slice_10342, kk_std_core_types__list _uniq_acc_10344, kk_context_t* _ctx) { /* (sslice/sslice, list<char>) -> (list<char>, sslice/sslice) */ 
  kk__tailcall: ;
  kk_std_core_types__maybe _match_x1783;
  kk_std_core_sslice__sslice _x_x2992 = kk_std_core_sslice__sslice_dup(_uniq_slice_10342, _ctx); /*sslice/sslice*/
  _match_x1783 = kk_std_core_sslice_next(_x_x2992, _ctx); /*maybe<(char, sslice/sslice)>*/
  if (kk_std_core_types__is_Just(_match_x1783, _ctx)) {
    kk_box_t _box_x1716 = _match_x1783._cons.Just.value;
    kk_std_core_types__tuple2 _uniq_pat_0_10346 = kk_std_core_types__tuple2_unbox(_box_x1716, KK_BORROWED, _ctx);
    if (kk_std_core_types__is_Tuple2(_uniq_pat_0_10346, _ctx)) {
      kk_box_t _box_x1717 = _uniq_pat_0_10346.fst;
      kk_box_t _box_x1718 = _uniq_pat_0_10346.snd;
      kk_char_t _uniq_c_10347 = kk_char_unbox(_box_x1717, KK_BORROWED, _ctx);
      if (kk_std_core_char_is_hex_digit(_uniq_c_10347, _ctx)) {
        kk_std_core_sslice__sslice _uniq_rest_10348 = kk_std_core_sslice__sslice_unbox(_box_x1718, KK_BORROWED, _ctx);
        kk_std_core_sslice__sslice_drop(_uniq_slice_10342, _ctx);
        kk_std_core_sslice__sslice_dup(_uniq_rest_10348, _ctx);
        kk_std_core_types__maybe_drop(_match_x1783, _ctx);
        { // tailcall
          kk_std_core_types__list _x_x2993 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_char_box(_uniq_c_10347, _ctx), _uniq_acc_10344, _ctx); /*list<79>*/
          _uniq_slice_10342 = _uniq_rest_10348;
          _uniq_acc_10344 = _x_x2993;
          goto kk__tailcall;
        }
      }
    }
  }
  {
    kk_std_core_types__maybe_drop(_match_x1783, _ctx);
    kk_std_core_types__list _b_x1721_1725;
    if (kk_std_core_types__is_Nil(_uniq_acc_10344, _ctx)) {
      _b_x1721_1725 = kk_std_core_types__new_Nil(_ctx); /*list<char>*/
    }
    else {
      _b_x1721_1725 = kk_std_core_list__unroll_reverse_acc_10003(kk_std_core_types__new_Nil(_ctx), _uniq_acc_10344, _ctx); /*list<char>*/
    }
    return kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(_b_x1721_1725, _ctx), kk_std_core_sslice__sslice_box(_uniq_slice_10342, _ctx), _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_text_parse__mlift_hex_digits_10601_fun3001__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse__mlift_hex_digits_10601_fun3001(kk_function_t _fself, kk_box_t _b_x1737, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse__new_mlift_hex_digits_10601_fun3001(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse__mlift_hex_digits_10601_fun3001, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_text_parse__mlift_hex_digits_10601_fun3001(kk_function_t _fself, kk_box_t _b_x1737, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x3002;
  kk_std_core_types__list _x_x3003 = kk_std_core_types__list_unbox(_b_x1737, KK_OWNED, _ctx); /*list<char>*/
  _x_x3002 = kk_std_core_string_listchar_fs_string(_x_x3003, _ctx); /*string*/
  return kk_string_box(_x_x3002);
}

kk_string_t kk_std_text_parse__mlift_hex_digits_10601(kk_std_core_types__maybe _y_x10511, kk_context_t* _ctx) { /* (maybe<list<char>>) -> parse string */ 
  kk_std_core_types__list x_11143;
  if (kk_std_core_types__is_Nothing(_y_x10511, _ctx)) {
    kk_std_core_hnd__ev ev_11145 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
    kk_box_t _x_x2994;
    {
      struct kk_std_core_hnd_Ev* _con_x2995 = kk_std_core_hnd__as_Ev(ev_11145, _ctx);
      kk_box_t _box_x1727 = _con_x2995->hnd;
      int32_t m = _con_x2995->marker;
      kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x1727, KK_BORROWED, _ctx);
      kk_std_text_parse__parse_dup(h, _ctx);
      {
        struct kk_std_text_parse__Hnd_parse* _con_x2996 = kk_std_text_parse__as_Hnd_parse(h, _ctx);
        kk_integer_t _pat_0 = _con_x2996->_cfc;
        kk_std_core_hnd__clause0 _pat_1_1 = _con_x2996->_fun_current_input;
        kk_std_core_hnd__clause1 _brk_fail = _con_x2996->_brk_fail;
        kk_std_core_hnd__clause0 _pat_2_0 = _con_x2996->_ctl_pick;
        kk_std_core_hnd__clause1 _pat_3 = _con_x2996->_fun_satisfy;
        if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
          kk_std_core_hnd__clause1_drop(_pat_3, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_2_0, _ctx);
          kk_std_core_hnd__clause0_drop(_pat_1_1, _ctx);
          kk_integer_drop(_pat_0, _ctx);
          kk_datatype_ptr_free(h, _ctx);
        }
        else {
          kk_std_core_hnd__clause1_dup(_brk_fail, _ctx);
          kk_datatype_ptr_decref(h, _ctx);
        }
        {
          kk_function_t _fun_unbox_x1731 = _brk_fail.clause;
          kk_box_t _x_x2997;
          kk_string_t _x_x2998;
          kk_define_string_literal(static, _s_x2999, 5, "digit", _ctx)
          _x_x2998 = kk_string_dup(_s_x2999, _ctx); /*string*/
          _x_x2997 = kk_string_box(_x_x2998); /*45*/
          _x_x2994 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x1731, (_fun_unbox_x1731, m, ev_11145, _x_x2997, _ctx), _ctx); /*46*/
        }
      }
    }
    x_11143 = kk_std_core_types__list_unbox(_x_x2994, KK_OWNED, _ctx); /*list<char>*/
  }
  else {
    kk_box_t _box_x1735 = _y_x10511._cons.Just.value;
    kk_std_core_types__list x_1 = kk_std_core_types__list_unbox(_box_x1735, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(x_1, _ctx);
    kk_std_core_types__maybe_drop(_y_x10511, _ctx);
    x_11143 = x_1; /*list<char>*/
  }
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_11143, _ctx);
    kk_box_t _x_x3000 = kk_std_core_hnd_yield_extend(kk_std_text_parse__new_mlift_hex_digits_10601_fun3001(_ctx), _ctx); /*2419*/
    return kk_string_unbox(_x_x3000);
  }
  {
    return kk_std_core_string_listchar_fs_string(x_11143, _ctx);
  }
}


// lift anonymous function
struct kk_std_text_parse_hex_digits_fun3007__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_hex_digits_fun3007(kk_function_t _fself, kk_box_t _b_x1752, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_hex_digits_fun3007(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_hex_digits_fun3007, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_text_parse_hex_digits_fun3007(kk_function_t _fself, kk_box_t _b_x1752, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_types__maybe _x_x3008;
  kk_std_core_types__tuple2 _match_x1781;
  kk_std_core_sslice__sslice _x_x3009 = kk_std_core_sslice__sslice_unbox(_b_x1752, KK_OWNED, _ctx); /*sslice/sslice*/
  _match_x1781 = kk_std_text_parse__lift_hex_digits_10360(_x_x3009, kk_std_core_types__new_Nil(_ctx), _ctx); /*(list<char>, sslice/sslice)*/
  {
    kk_box_t _box_x1753 = _match_x1781.fst;
    kk_box_t _box_x1754 = _match_x1781.snd;
    kk_std_core_types__list _pat_0_0_0 = kk_std_core_types__list_unbox(_box_x1753, KK_BORROWED, _ctx);
    kk_std_core_sslice__sslice _pat_1_0_0 = kk_std_core_sslice__sslice_unbox(_box_x1754, KK_BORROWED, _ctx);
    if (kk_std_core_types__is_Nil(_pat_0_0_0, _ctx)) {
      kk_std_core_types__tuple2_drop(_match_x1781, _ctx);
      _x_x3008 = kk_std_core_types__new_Nothing(_ctx); /*forall<a> maybe<a>*/
      goto _match_x3010;
    }
  }
  {
    kk_box_t _box_x1755 = _match_x1781.fst;
    kk_box_t _box_x1756 = _match_x1781.snd;
    kk_std_core_sslice__sslice rest = kk_std_core_sslice__sslice_unbox(_box_x1756, KK_BORROWED, _ctx);
    kk_std_core_types__list xs = kk_std_core_types__list_unbox(_box_x1755, KK_BORROWED, _ctx);
    kk_std_core_sslice__sslice_dup(rest, _ctx);
    kk_std_core_types__list_dup(xs, _ctx);
    kk_std_core_types__tuple2_drop(_match_x1781, _ctx);
    kk_box_t _x_x3011;
    kk_std_core_types__tuple2 _x_x3012 = kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(xs, _ctx), kk_std_core_sslice__sslice_box(rest, _ctx), _ctx); /*(134, 135)*/
    _x_x3011 = kk_std_core_types__tuple2_box(_x_x3012, _ctx); /*88*/
    _x_x3008 = kk_std_core_types__new_Just(_x_x3011, _ctx); /*forall<a> maybe<a>*/
  }
  _match_x3010: ;
  return kk_std_core_types__maybe_box(_x_x3008, _ctx);
}


// lift anonymous function
struct kk_std_text_parse_hex_digits_fun3014__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_hex_digits_fun3014(kk_function_t _fself, kk_box_t _b_x1765, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_hex_digits_fun3014(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_hex_digits_fun3014, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_text_parse_hex_digits_fun3014(kk_function_t _fself, kk_box_t _b_x1765, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x3015;
  kk_std_core_types__maybe _x_x3016 = kk_std_core_types__maybe_unbox(_b_x1765, KK_OWNED, _ctx); /*maybe<list<char>>*/
  _x_x3015 = kk_std_text_parse__mlift_hex_digits_10601(_x_x3016, _ctx); /*string*/
  return kk_string_box(_x_x3015);
}


// lift anonymous function
struct kk_std_text_parse_hex_digits_fun3024__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_text_parse_hex_digits_fun3024(kk_function_t _fself, kk_box_t _b_x1776, kk_context_t* _ctx);
static kk_function_t kk_std_text_parse_new_hex_digits_fun3024(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_text_parse_hex_digits_fun3024, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_text_parse_hex_digits_fun3024(kk_function_t _fself, kk_box_t _b_x1776, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x3025;
  kk_std_core_types__list _x_x3026 = kk_std_core_types__list_unbox(_b_x1776, KK_OWNED, _ctx); /*list<char>*/
  _x_x3025 = kk_std_core_string_listchar_fs_string(_x_x3026, _ctx); /*string*/
  return kk_string_box(_x_x3025);
}

kk_string_t kk_std_text_parse_hex_digits(kk_context_t* _ctx) { /* () -> parse string */ 
  kk_std_core_hnd__ev ev_11151 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
  kk_std_core_types__maybe x_11148;
  kk_box_t _x_x3004;
  {
    struct kk_std_core_hnd_Ev* _con_x3005 = kk_std_core_hnd__as_Ev(ev_11151, _ctx);
    kk_box_t _box_x1739 = _con_x3005->hnd;
    int32_t m = _con_x3005->marker;
    kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x1739, KK_BORROWED, _ctx);
    kk_std_text_parse__parse_dup(h, _ctx);
    {
      struct kk_std_text_parse__Hnd_parse* _con_x3006 = kk_std_text_parse__as_Hnd_parse(h, _ctx);
      kk_integer_t _pat_0 = _con_x3006->_cfc;
      kk_std_core_hnd__clause0 _pat_1_1 = _con_x3006->_fun_current_input;
      kk_std_core_hnd__clause1 _pat_2 = _con_x3006->_brk_fail;
      kk_std_core_hnd__clause0 _pat_3 = _con_x3006->_ctl_pick;
      kk_std_core_hnd__clause1 _fun_satisfy = _con_x3006->_fun_satisfy;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause0_drop(_pat_3, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_2, _ctx);
        kk_std_core_hnd__clause0_drop(_pat_1_1, _ctx);
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_fun_satisfy, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x1746 = _fun_satisfy.clause;
        _x_x3004 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x1746, (_fun_unbox_x1746, m, ev_11151, kk_function_box(kk_std_text_parse_new_hex_digits_fun3007(_ctx), _ctx), _ctx), _ctx); /*46*/
      }
    }
  }
  x_11148 = kk_std_core_types__maybe_unbox(_x_x3004, KK_OWNED, _ctx); /*maybe<list<char>>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__maybe_drop(x_11148, _ctx);
    kk_box_t _x_x3013 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_hex_digits_fun3014(_ctx), _ctx); /*2419*/
    return kk_string_unbox(_x_x3013);
  }
  {
    kk_std_core_types__list x_1_11154;
    if (kk_std_core_types__is_Nothing(x_11148, _ctx)) {
      kk_std_core_hnd__ev ev_0_11156 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
      kk_box_t _x_x3017;
      {
        struct kk_std_core_hnd_Ev* _con_x3018 = kk_std_core_hnd__as_Ev(ev_0_11156, _ctx);
        kk_box_t _box_x1766 = _con_x3018->hnd;
        int32_t m_0 = _con_x3018->marker;
        kk_std_text_parse__parse h_0 = kk_std_text_parse__parse_unbox(_box_x1766, KK_BORROWED, _ctx);
        kk_std_text_parse__parse_dup(h_0, _ctx);
        {
          struct kk_std_text_parse__Hnd_parse* _con_x3019 = kk_std_text_parse__as_Hnd_parse(h_0, _ctx);
          kk_integer_t _pat_0_3 = _con_x3019->_cfc;
          kk_std_core_hnd__clause0 _pat_1_3 = _con_x3019->_fun_current_input;
          kk_std_core_hnd__clause1 _brk_fail = _con_x3019->_brk_fail;
          kk_std_core_hnd__clause0 _pat_2_1 = _con_x3019->_ctl_pick;
          kk_std_core_hnd__clause1 _pat_3_1 = _con_x3019->_fun_satisfy;
          if kk_likely(kk_datatype_ptr_is_unique(h_0, _ctx)) {
            kk_std_core_hnd__clause1_drop(_pat_3_1, _ctx);
            kk_std_core_hnd__clause0_drop(_pat_2_1, _ctx);
            kk_std_core_hnd__clause0_drop(_pat_1_3, _ctx);
            kk_integer_drop(_pat_0_3, _ctx);
            kk_datatype_ptr_free(h_0, _ctx);
          }
          else {
            kk_std_core_hnd__clause1_dup(_brk_fail, _ctx);
            kk_datatype_ptr_decref(h_0, _ctx);
          }
          {
            kk_function_t _fun_unbox_x1770 = _brk_fail.clause;
            kk_box_t _x_x3020;
            kk_string_t _x_x3021;
            kk_define_string_literal(static, _s_x3022, 5, "digit", _ctx)
            _x_x3021 = kk_string_dup(_s_x3022, _ctx); /*string*/
            _x_x3020 = kk_string_box(_x_x3021); /*45*/
            _x_x3017 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x1770, (_fun_unbox_x1770, m_0, ev_0_11156, _x_x3020, _ctx), _ctx); /*46*/
          }
        }
      }
      x_1_11154 = kk_std_core_types__list_unbox(_x_x3017, KK_OWNED, _ctx); /*list<char>*/
    }
    else {
      kk_box_t _box_x1774 = x_11148._cons.Just.value;
      kk_std_core_types__list x_3 = kk_std_core_types__list_unbox(_box_x1774, KK_BORROWED, _ctx);
      kk_std_core_types__list_dup(x_3, _ctx);
      kk_std_core_types__maybe_drop(x_11148, _ctx);
      x_1_11154 = x_3; /*list<char>*/
    }
    if (kk_yielding(kk_context())) {
      kk_std_core_types__list_drop(x_1_11154, _ctx);
      kk_box_t _x_x3023 = kk_std_core_hnd_yield_extend(kk_std_text_parse_new_hex_digits_fun3024(_ctx), _ctx); /*2419*/
      return kk_string_unbox(_x_x3023);
    }
    {
      return kk_std_core_string_listchar_fs_string(x_1_11154, _ctx);
    }
  }
}

// initialization
void kk_std_text_parse__init(kk_context_t* _ctx){
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
  kk_std_core_undiv__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
  {
    kk_string_t _x_x2035;
    kk_define_string_literal(static, _s_x2036, 11, "parse@parse", _ctx)
    _x_x2035 = kk_string_dup(_s_x2036, _ctx); /*string*/
    kk_std_text_parse_parse_fs__tag = kk_std_core_hnd__new_Htag(_x_x2035, _ctx); /*hnd/htag<std/text/parse/parse>*/
  }
}

// termination
void kk_std_text_parse__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_std_core_hnd__htag_drop(kk_std_text_parse_parse_fs__tag, _ctx);
  kk_std_core_undiv__done(_ctx);
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
