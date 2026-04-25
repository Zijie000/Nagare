// Koka generated module: std/os/file, koka version: 3.2.3, platform: 64-bit
#include "std_os_file.h"
/*---------------------------------------------------------------------------
  Copyright 2020-2021, Microsoft Research, Daan Leijen.

  This is free software; you can redistribute it and/or modify it under the
  terms of the Apache License, Version 2.0. A copy of the License can be
  found in the LICENSE file at the root of this distribution.
---------------------------------------------------------------------------*/

static kk_std_core_exn__error kk_os_read_text_file_error( kk_string_t path, kk_context_t* ctx ) {
  kk_string_t content;
  const int err = kk_os_read_text_file(path,&content,ctx);
  if (err != 0) return kk_error_from_errno(err,ctx);
           else return kk_error_ok(kk_string_box(content),ctx);
}

static kk_std_core_exn__error kk_os_write_text_file_error( kk_string_t path, kk_string_t content, kk_context_t* ctx ) {
  const int err = kk_os_write_text_file(path,content,ctx);
  if (err != 0) return kk_error_from_errno(err,ctx);
           else return kk_error_ok(kk_unit_box(kk_Unit),ctx);
}


kk_std_core_exn__error kk_std_os_file_read_text_file_err(kk_string_t path, kk_context_t* _ctx) { /* (path : string) -> fsys error<string> */ 
  return kk_os_read_text_file_error(path,kk_context());
}
 
// Read a text file synchronously (using UTF8 encoding)


// lift anonymous function
struct kk_std_os_file_read_text_file_fun88__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_file_read_text_file_fun88(kk_function_t _fself, kk_box_t _b_x2, kk_context_t* _ctx);
static kk_function_t kk_std_os_file_new_read_text_file_fun88(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_file_read_text_file_fun88, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_file_read_text_file_fun88(kk_function_t _fself, kk_box_t _b_x2, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x89;
  kk_std_os_path__path _x_x90 = kk_std_os_path__path_unbox(_b_x2, KK_OWNED, _ctx); /*std/os/path/path*/
  _x_x89 = kk_std_os_path_string(_x_x90, _ctx); /*string*/
  return kk_string_box(_x_x89);
}


// lift anonymous function
struct kk_std_os_file_read_text_file_fun94__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_file_read_text_file_fun94(kk_function_t _fself, kk_box_t _b_x7, kk_context_t* _ctx);
static kk_function_t kk_std_os_file_new_read_text_file_fun94(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_file_read_text_file_fun94, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_file_read_text_file_fun94(kk_function_t _fself, kk_box_t _b_x7, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_exn__error _x_x95;
  kk_string_t _x_x96 = kk_string_unbox(_b_x7); /*string*/
  _x_x95 = kk_std_os_file_read_text_file_err(_x_x96, _ctx); /*error<string>*/
  return kk_std_core_exn__error_box(_x_x95, _ctx);
}

kk_string_t kk_std_os_file_read_text_file(kk_std_os_path__path path, kk_context_t* _ctx) { /* (path : std/os/path/path) -> <exn,fsys> string */ 
  kk_string_t _x_x1_10120;
  kk_box_t _x_x87;
  kk_box_t _x_x91;
  kk_std_os_path__path _x_x92 = kk_std_os_path__path_dup(path, _ctx); /*std/os/path/path*/
  _x_x91 = kk_std_os_path__path_box(_x_x92, _ctx); /*10000*/
  _x_x87 = kk_std_core_hnd__open_none1(kk_std_os_file_new_read_text_file_fun88(_ctx), _x_x91, _ctx); /*10001*/
  _x_x1_10120 = kk_string_unbox(_x_x87); /*string*/
  kk_std_core_exn__error _match_x79;
  kk_box_t _x_x93 = kk_std_core_hnd__open_none1(kk_std_os_file_new_read_text_file_fun94(_ctx), kk_string_box(_x_x1_10120), _ctx); /*10001*/
  _match_x79 = kk_std_core_exn__error_unbox(_x_x93, KK_OWNED, _ctx); /*error<string>*/
  if (kk_std_core_exn__is_Error(_match_x79, _ctx)) {
    kk_std_core_exn__exception exn = _match_x79._cons.Error.exception;
    kk_std_core_exn__exception_dup(exn, _ctx);
    kk_std_core_exn__error_drop(_match_x79, _ctx);
    kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<exn,fsys>>*/;
    kk_string_t x;
    kk_string_t _x_x97 = kk_std_os_path_string(path, _ctx); /*string*/
    x = kk_std_core_show_string_fs_show(_x_x97, _ctx); /*string*/
    kk_unit_t keep = kk_Unit;
    kk_evv_set(w,kk_context());
    kk_string_t _x_x2_10123;
    kk_string_t _x_x98;
    kk_define_string_literal(static, _s_x99, 25, "unable to read text file ", _ctx)
    _x_x98 = kk_string_dup(_s_x99, _ctx); /*string*/
    _x_x2_10123 = kk_std_core_types__lp__plus__plus__rp_(_x_x98, x, _ctx); /*string*/
    kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<exn,fsys>>*/;
    kk_std_core_exn__exception x_0;
    kk_string_t _x_x100;
    kk_string_t _x_x101;
    kk_string_t _x_x102;
    kk_define_string_literal(static, _s_x103, 2, ": ", _ctx)
    _x_x102 = kk_string_dup(_s_x103, _ctx); /*string*/
    kk_string_t _x_x104;
    {
      kk_string_t _x = exn.message;
      kk_string_dup(_x, _ctx);
      _x_x104 = _x; /*string*/
    }
    _x_x101 = kk_std_core_types__lp__plus__plus__rp_(_x_x102, _x_x104, _ctx); /*string*/
    _x_x100 = kk_std_core_types__lp__plus__plus__rp_(_x_x2_10123, _x_x101, _ctx); /*string*/
    kk_std_core_exn__exception_info _x_x105;
    {
      kk_std_core_exn__exception_info _x_0 = exn.info;
      kk_std_core_exn__exception_info_dup(_x_0, _ctx);
      kk_std_core_exn__exception_drop(exn, _ctx);
      _x_x105 = _x_0; /*exception-info*/
    }
    x_0 = kk_std_core_exn__new_Exception(_x_x100, _x_x105, _ctx); /*exception*/
    kk_unit_t keep_0 = kk_Unit;
    kk_evv_set(w_0,kk_context());
    kk_std_core_hnd__ev ev_10139 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<exn>*/;
    kk_box_t _x_x106;
    {
      struct kk_std_core_hnd_Ev* _con_x107 = kk_std_core_hnd__as_Ev(ev_10139, _ctx);
      kk_box_t _box_x8 = _con_x107->hnd;
      int32_t m = _con_x107->marker;
      kk_std_core_exn__exn h = kk_std_core_exn__exn_unbox(_box_x8, KK_BORROWED, _ctx);
      kk_std_core_exn__exn_dup(h, _ctx);
      kk_std_core_hnd__clause1 _match_x80;
      kk_std_core_hnd__clause1 _brw_x81 = kk_std_core_exn_throw_exn_fs__select(h, _ctx); /*hnd/clause1<exception,10000,exn,10001,10002>*/;
      kk_datatype_ptr_dropn(h, (KK_I32(2)), _ctx);
      _match_x80 = _brw_x81; /*hnd/clause1<exception,10000,exn,10001,10002>*/
      {
        kk_function_t _fun_unbox_x12 = _match_x80.clause;
        _x_x106 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x12, (_fun_unbox_x12, m, ev_10139, kk_std_core_exn__exception_box(x_0, _ctx), _ctx), _ctx); /*10010*/
      }
    }
    return kk_string_unbox(_x_x106);
  }
  {
    kk_box_t _box_x16 = _match_x79._cons.Ok.result;
    kk_string_t content = kk_string_unbox(_box_x16);
    kk_std_os_path__path_drop(path, _ctx);
    kk_string_dup(content, _ctx);
    kk_std_core_exn__error_drop(_match_x79, _ctx);
    return content;
  }
}

kk_std_core_exn__error kk_std_os_file_write_text_file_err(kk_string_t path, kk_string_t content, kk_context_t* _ctx) { /* (path : string, content : string) -> fsys error<()> */ 
  return kk_os_write_text_file_error(path,content,kk_context());
}
 
// monadic lift


// lift anonymous function
struct kk_std_os_file__mlift_write_text_file_10133_fun109__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_file__mlift_write_text_file_10133_fun109(kk_function_t _fself, kk_box_t _b_x21, kk_context_t* _ctx);
static kk_function_t kk_std_os_file__new_mlift_write_text_file_10133_fun109(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_file__mlift_write_text_file_10133_fun109, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_file__mlift_write_text_file_10133_fun109(kk_function_t _fself, kk_box_t _b_x21, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x110;
  kk_std_os_path__path _x_x111 = kk_std_os_path__path_unbox(_b_x21, KK_OWNED, _ctx); /*std/os/path/path*/
  _x_x110 = kk_std_os_path_string(_x_x111, _ctx); /*string*/
  return kk_string_box(_x_x110);
}


// lift anonymous function
struct kk_std_os_file__mlift_write_text_file_10133_fun115__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_file__mlift_write_text_file_10133_fun115(kk_function_t _fself, kk_box_t _b_x27, kk_box_t _b_x28, kk_context_t* _ctx);
static kk_function_t kk_std_os_file__new_mlift_write_text_file_10133_fun115(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_file__mlift_write_text_file_10133_fun115, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_file__mlift_write_text_file_10133_fun115(kk_function_t _fself, kk_box_t _b_x27, kk_box_t _b_x28, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_exn__error _x_x116;
  kk_string_t _x_x117 = kk_string_unbox(_b_x27); /*string*/
  kk_string_t _x_x118 = kk_string_unbox(_b_x28); /*string*/
  _x_x116 = kk_std_os_file_write_text_file_err(_x_x117, _x_x118, _ctx); /*error<()>*/
  return kk_std_core_exn__error_box(_x_x116, _ctx);
}

kk_unit_t kk_std_os_file__mlift_write_text_file_10133(kk_string_t content, kk_std_os_path__path path, kk_unit_t _c_x10107, kk_context_t* _ctx) { /* (content : string, path : std/os/path/path, ()) -> () */ 
  kk_string_t _x_x1_1_10127;
  kk_box_t _x_x108;
  kk_box_t _x_x112;
  kk_std_os_path__path _x_x113 = kk_std_os_path__path_dup(path, _ctx); /*std/os/path/path*/
  _x_x112 = kk_std_os_path__path_box(_x_x113, _ctx); /*10000*/
  _x_x108 = kk_std_core_hnd__open_none1(kk_std_os_file__new_mlift_write_text_file_10133_fun109(_ctx), _x_x112, _ctx); /*10001*/
  _x_x1_1_10127 = kk_string_unbox(_x_x108); /*string*/
  kk_std_core_exn__error _match_x76;
  kk_box_t _x_x114 = kk_std_core_hnd__open_none2(kk_std_os_file__new_mlift_write_text_file_10133_fun115(_ctx), kk_string_box(_x_x1_1_10127), kk_string_box(content), _ctx); /*10002*/
  _match_x76 = kk_std_core_exn__error_unbox(_x_x114, KK_OWNED, _ctx); /*error<()>*/
  if (kk_std_core_exn__is_Error(_match_x76, _ctx)) {
    kk_std_core_exn__exception exn = _match_x76._cons.Error.exception;
    kk_std_core_exn__exception_dup(exn, _ctx);
    kk_std_core_exn__error_drop(_match_x76, _ctx);
    kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<exn,fsys>>*/;
    kk_string_t x;
    kk_string_t _x_x119 = kk_std_os_path_string(path, _ctx); /*string*/
    x = kk_std_core_show_string_fs_show(_x_x119, _ctx); /*string*/
    kk_unit_t keep = kk_Unit;
    kk_evv_set(w,kk_context());
    kk_string_t _x_x2_0_10131;
    kk_string_t _x_x120;
    kk_define_string_literal(static, _s_x121, 26, "unable to write text file ", _ctx)
    _x_x120 = kk_string_dup(_s_x121, _ctx); /*string*/
    _x_x2_0_10131 = kk_std_core_types__lp__plus__plus__rp_(_x_x120, x, _ctx); /*string*/
    kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<exn,fsys>>*/;
    kk_std_core_exn__exception x_0;
    kk_string_t _x_x122;
    kk_string_t _x_x123;
    kk_string_t _x_x124;
    kk_define_string_literal(static, _s_x125, 2, ": ", _ctx)
    _x_x124 = kk_string_dup(_s_x125, _ctx); /*string*/
    kk_string_t _x_x126;
    {
      kk_string_t _x_2 = exn.message;
      kk_string_dup(_x_2, _ctx);
      _x_x126 = _x_2; /*string*/
    }
    _x_x123 = kk_std_core_types__lp__plus__plus__rp_(_x_x124, _x_x126, _ctx); /*string*/
    _x_x122 = kk_std_core_types__lp__plus__plus__rp_(_x_x2_0_10131, _x_x123, _ctx); /*string*/
    kk_std_core_exn__exception_info _x_x127;
    {
      kk_std_core_exn__exception_info _x_0_1 = exn.info;
      kk_std_core_exn__exception_info_dup(_x_0_1, _ctx);
      kk_std_core_exn__exception_drop(exn, _ctx);
      _x_x127 = _x_0_1; /*exception-info*/
    }
    x_0 = kk_std_core_exn__new_Exception(_x_x122, _x_x127, _ctx); /*exception*/
    kk_unit_t keep_0 = kk_Unit;
    kk_evv_set(w_0,kk_context());
    kk_std_core_hnd__ev ev_10147 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<exn>*/;
    kk_box_t _x_x128;
    {
      struct kk_std_core_hnd_Ev* _con_x129 = kk_std_core_hnd__as_Ev(ev_10147, _ctx);
      kk_box_t _box_x29 = _con_x129->hnd;
      int32_t m = _con_x129->marker;
      kk_std_core_exn__exn h = kk_std_core_exn__exn_unbox(_box_x29, KK_BORROWED, _ctx);
      kk_std_core_exn__exn_dup(h, _ctx);
      kk_std_core_hnd__clause1 _match_x77;
      kk_std_core_hnd__clause1 _brw_x78 = kk_std_core_exn_throw_exn_fs__select(h, _ctx); /*hnd/clause1<exception,10000,exn,10001,10002>*/;
      kk_datatype_ptr_dropn(h, (KK_I32(2)), _ctx);
      _match_x77 = _brw_x78; /*hnd/clause1<exception,10000,exn,10001,10002>*/
      {
        kk_function_t _fun_unbox_x33 = _match_x77.clause;
        _x_x128 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x33, (_fun_unbox_x33, m, ev_10147, kk_std_core_exn__exception_box(x_0, _ctx), _ctx), _ctx); /*10010*/
      }
    }
    kk_unit_unbox(_x_x128); return kk_Unit;
  }
  {
    kk_std_os_path__path_drop(path, _ctx);
    kk_std_core_exn__error_drop(_match_x76, _ctx);
    kk_Unit; return kk_Unit;
  }
}
 
// Write a text file synchronously (using UTF8 encoding)


// lift anonymous function
struct kk_std_os_file_write_text_file_fun139__t {
  struct kk_function_s _base;
  kk_string_t content;
  kk_std_os_path__path path;
};
static kk_box_t kk_std_os_file_write_text_file_fun139(kk_function_t _fself, kk_box_t _b_x46, kk_context_t* _ctx);
static kk_function_t kk_std_os_file_new_write_text_file_fun139(kk_string_t content, kk_std_os_path__path path, kk_context_t* _ctx) {
  struct kk_std_os_file_write_text_file_fun139__t* _self = kk_function_alloc_as(struct kk_std_os_file_write_text_file_fun139__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_os_file_write_text_file_fun139, kk_context());
  _self->content = content;
  _self->path = path;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_os_file_write_text_file_fun139(kk_function_t _fself, kk_box_t _b_x46, kk_context_t* _ctx) {
  struct kk_std_os_file_write_text_file_fun139__t* _self = kk_function_as(struct kk_std_os_file_write_text_file_fun139__t*, _fself, _ctx);
  kk_string_t content = _self->content; /* string */
  kk_std_os_path__path path = _self->path; /* std/os/path/path */
  kk_drop_match(_self, {kk_string_dup(content, _ctx);kk_std_os_path__path_dup(path, _ctx);}, {}, _ctx)
  kk_unit_t _c_x10107_69 = kk_Unit;
  kk_unit_unbox(_b_x46);
  kk_unit_t _x_x140 = kk_Unit;
  kk_std_os_file__mlift_write_text_file_10133(content, path, _c_x10107_69, _ctx);
  return kk_unit_box(_x_x140);
}


// lift anonymous function
struct kk_std_os_file_write_text_file_fun142__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_file_write_text_file_fun142(kk_function_t _fself, kk_box_t _b_x49, kk_context_t* _ctx);
static kk_function_t kk_std_os_file_new_write_text_file_fun142(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_file_write_text_file_fun142, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_file_write_text_file_fun142(kk_function_t _fself, kk_box_t _b_x49, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x143;
  kk_std_os_path__path _x_x144 = kk_std_os_path__path_unbox(_b_x49, KK_OWNED, _ctx); /*std/os/path/path*/
  _x_x143 = kk_std_os_path_string(_x_x144, _ctx); /*string*/
  return kk_string_box(_x_x143);
}


// lift anonymous function
struct kk_std_os_file_write_text_file_fun148__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_file_write_text_file_fun148(kk_function_t _fself, kk_box_t _b_x55, kk_box_t _b_x56, kk_context_t* _ctx);
static kk_function_t kk_std_os_file_new_write_text_file_fun148(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_file_write_text_file_fun148, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_file_write_text_file_fun148(kk_function_t _fself, kk_box_t _b_x55, kk_box_t _b_x56, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_exn__error _x_x149;
  kk_string_t _x_x150 = kk_string_unbox(_b_x55); /*string*/
  kk_string_t _x_x151 = kk_string_unbox(_b_x56); /*string*/
  _x_x149 = kk_std_os_file_write_text_file_err(_x_x150, _x_x151, _ctx); /*error<()>*/
  return kk_std_core_exn__error_box(_x_x149, _ctx);
}

kk_unit_t kk_std_os_file_write_text_file(kk_std_os_path__path path, kk_string_t content, kk_std_core_types__optional create_dir, kk_context_t* _ctx) { /* (path : std/os/path/path, content : string, create-dir : ? bool) -> <exn,fsys> () */ 
  kk_unit_t x_10150 = kk_Unit;
  if (kk_std_core_types__is_Optional(create_dir, _ctx)) {
    kk_box_t _box_x40 = create_dir._cons._Optional.value;
    bool _uniq_create_dir_153 = kk_bool_unbox(_box_x40);
    kk_std_core_types__optional_drop(create_dir, _ctx);
    if (_uniq_create_dir_153) {
      kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<exn,fsys>>*/;
      kk_unit_t keep = kk_Unit;
      kk_evv_set(w,kk_context());
      kk_std_os_path__path _x_x130;
      kk_string_t _x_x131;
      kk_std_core_types__optional _match_x75 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
      if (kk_std_core_types__is_Optional(_match_x75, _ctx)) {
        kk_box_t _box_x41 = _match_x75._cons._Optional.value;
        kk_string_t _uniq_root_128 = kk_string_unbox(_box_x41);
        kk_string_dup(_uniq_root_128, _ctx);
        kk_std_core_types__optional_drop(_match_x75, _ctx);
        _x_x131 = _uniq_root_128; /*string*/
      }
      else {
        kk_std_core_types__optional_drop(_match_x75, _ctx);
        {
          kk_string_t _x_0 = path.root;
          kk_string_dup(_x_0, _ctx);
          _x_x131 = _x_0; /*string*/
        }
      }
      kk_std_core_types__list _x_x132;
      {
        kk_std_core_types__list _x = path.parts;
        kk_std_core_types__list_dup(_x, _ctx);
        if (kk_std_core_types__is_Cons(_x, _ctx)) {
          struct kk_std_core_types_Cons* _con_x133 = kk_std_core_types__as_Cons(_x, _ctx);
          kk_box_t _box_x42 = _con_x133->head;
          kk_std_core_types__list xx = _con_x133->tail;
          kk_string_t _pat_0_3_0 = kk_string_unbox(_box_x42);
          if kk_likely(kk_datatype_ptr_is_unique(_x, _ctx)) {
            kk_string_drop(_pat_0_3_0, _ctx);
            kk_datatype_ptr_free(_x, _ctx);
          }
          else {
            kk_std_core_types__list_dup(xx, _ctx);
            kk_datatype_ptr_decref(_x, _ctx);
          }
          _x_x132 = xx; /*list<string>*/
        }
        else {
          _x_x132 = kk_std_core_types__new_Nil(_ctx); /*list<string>*/
        }
      }
      _x_x130 = kk_std_os_path__new_Path(_x_x131, _x_x132, _ctx); /*std/os/path/path*/
      kk_std_os_dir_ensure_dir(_x_x130, _ctx);
    }
    else {
      
    }
  }
  else {
    kk_std_core_types__optional_drop(create_dir, _ctx);
    kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<exn,fsys>>*/;
    kk_unit_t keep_0 = kk_Unit;
    kk_evv_set(w_0,kk_context());
    kk_std_os_path__path _x_x134;
    kk_string_t _x_x135;
    kk_std_core_types__optional _match_x74 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x74, _ctx)) {
      kk_box_t _box_x43 = _match_x74._cons._Optional.value;
      kk_string_t _uniq_root_128_0 = kk_string_unbox(_box_x43);
      kk_string_dup(_uniq_root_128_0, _ctx);
      kk_std_core_types__optional_drop(_match_x74, _ctx);
      _x_x135 = _uniq_root_128_0; /*string*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x74, _ctx);
      {
        kk_string_t _x_0_0 = path.root;
        kk_string_dup(_x_0_0, _ctx);
        _x_x135 = _x_0_0; /*string*/
      }
    }
    kk_std_core_types__list _x_x136;
    {
      kk_std_core_types__list _x_1 = path.parts;
      kk_std_core_types__list_dup(_x_1, _ctx);
      if (kk_std_core_types__is_Cons(_x_1, _ctx)) {
        struct kk_std_core_types_Cons* _con_x137 = kk_std_core_types__as_Cons(_x_1, _ctx);
        kk_box_t _box_x44 = _con_x137->head;
        kk_std_core_types__list xx_0 = _con_x137->tail;
        kk_string_t _pat_0_5 = kk_string_unbox(_box_x44);
        if kk_likely(kk_datatype_ptr_is_unique(_x_1, _ctx)) {
          kk_string_drop(_pat_0_5, _ctx);
          kk_datatype_ptr_free(_x_1, _ctx);
        }
        else {
          kk_std_core_types__list_dup(xx_0, _ctx);
          kk_datatype_ptr_decref(_x_1, _ctx);
        }
        _x_x136 = xx_0; /*list<string>*/
      }
      else {
        _x_x136 = kk_std_core_types__new_Nil(_ctx); /*list<string>*/
      }
    }
    _x_x134 = kk_std_os_path__new_Path(_x_x135, _x_x136, _ctx); /*std/os/path/path*/
    kk_std_os_dir_ensure_dir(_x_x134, _ctx);
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x138 = kk_std_core_hnd_yield_extend(kk_std_os_file_new_write_text_file_fun139(content, path, _ctx), _ctx); /*10001*/
    kk_unit_unbox(_x_x138); return kk_Unit;
  }
  {
    kk_string_t _x_x1_1_10127;
    kk_box_t _x_x141;
    kk_box_t _x_x145;
    kk_std_os_path__path _x_x146 = kk_std_os_path__path_dup(path, _ctx); /*std/os/path/path*/
    _x_x145 = kk_std_os_path__path_box(_x_x146, _ctx); /*10000*/
    _x_x141 = kk_std_core_hnd__open_none1(kk_std_os_file_new_write_text_file_fun142(_ctx), _x_x145, _ctx); /*10001*/
    _x_x1_1_10127 = kk_string_unbox(_x_x141); /*string*/
    kk_std_core_exn__error _match_x71;
    kk_box_t _x_x147 = kk_std_core_hnd__open_none2(kk_std_os_file_new_write_text_file_fun148(_ctx), kk_string_box(_x_x1_1_10127), kk_string_box(content), _ctx); /*10002*/
    _match_x71 = kk_std_core_exn__error_unbox(_x_x147, KK_OWNED, _ctx); /*error<()>*/
    if (kk_std_core_exn__is_Error(_match_x71, _ctx)) {
      kk_std_core_exn__exception exn = _match_x71._cons.Error.exception;
      kk_std_core_exn__exception_dup(exn, _ctx);
      kk_std_core_exn__error_drop(_match_x71, _ctx);
      kk_evv_t w_1 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<exn,fsys>>*/;
      kk_string_t x_2;
      kk_string_t _x_x152 = kk_std_os_path_string(path, _ctx); /*string*/
      x_2 = kk_std_core_show_string_fs_show(_x_x152, _ctx); /*string*/
      kk_unit_t keep_1 = kk_Unit;
      kk_evv_set(w_1,kk_context());
      kk_string_t _x_x2_0_10131;
      kk_string_t _x_x153;
      kk_define_string_literal(static, _s_x154, 26, "unable to write text file ", _ctx)
      _x_x153 = kk_string_dup(_s_x154, _ctx); /*string*/
      _x_x2_0_10131 = kk_std_core_types__lp__plus__plus__rp_(_x_x153, x_2, _ctx); /*string*/
      kk_evv_t w_2 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<exn,fsys>>*/;
      kk_std_core_exn__exception x_3;
      kk_string_t _x_x155;
      kk_string_t _x_x156;
      kk_string_t _x_x157;
      kk_define_string_literal(static, _s_x158, 2, ": ", _ctx)
      _x_x157 = kk_string_dup(_s_x158, _ctx); /*string*/
      kk_string_t _x_x159;
      {
        kk_string_t _x_2 = exn.message;
        kk_string_dup(_x_2, _ctx);
        _x_x159 = _x_2; /*string*/
      }
      _x_x156 = kk_std_core_types__lp__plus__plus__rp_(_x_x157, _x_x159, _ctx); /*string*/
      _x_x155 = kk_std_core_types__lp__plus__plus__rp_(_x_x2_0_10131, _x_x156, _ctx); /*string*/
      kk_std_core_exn__exception_info _x_x160;
      {
        kk_std_core_exn__exception_info _x_0_1 = exn.info;
        kk_std_core_exn__exception_info_dup(_x_0_1, _ctx);
        kk_std_core_exn__exception_drop(exn, _ctx);
        _x_x160 = _x_0_1; /*exception-info*/
      }
      x_3 = kk_std_core_exn__new_Exception(_x_x155, _x_x160, _ctx); /*exception*/
      kk_unit_t keep_2 = kk_Unit;
      kk_evv_set(w_2,kk_context());
      kk_std_core_hnd__ev ev_10162 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<exn>*/;
      kk_box_t _x_x161;
      {
        struct kk_std_core_hnd_Ev* _con_x162 = kk_std_core_hnd__as_Ev(ev_10162, _ctx);
        kk_box_t _box_x57 = _con_x162->hnd;
        int32_t m = _con_x162->marker;
        kk_std_core_exn__exn h = kk_std_core_exn__exn_unbox(_box_x57, KK_BORROWED, _ctx);
        kk_std_core_exn__exn_dup(h, _ctx);
        kk_std_core_hnd__clause1 _match_x72;
        kk_std_core_hnd__clause1 _brw_x73 = kk_std_core_exn_throw_exn_fs__select(h, _ctx); /*hnd/clause1<exception,10000,exn,10001,10002>*/;
        kk_datatype_ptr_dropn(h, (KK_I32(2)), _ctx);
        _match_x72 = _brw_x73; /*hnd/clause1<exception,10000,exn,10001,10002>*/
        {
          kk_function_t _fun_unbox_x61 = _match_x72.clause;
          _x_x161 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x61, (_fun_unbox_x61, m, ev_10162, kk_std_core_exn__exception_box(x_3, _ctx), _ctx), _ctx); /*10010*/
        }
      }
      kk_unit_unbox(_x_x161); return kk_Unit;
    }
    {
      kk_std_os_path__path_drop(path, _ctx);
      kk_std_core_exn__error_drop(_match_x71, _ctx);
      kk_Unit; return kk_Unit;
    }
  }
}

// initialization
void kk_std_os_file__init(kk_context_t* _ctx){
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
  kk_std_os_dir__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
}

// termination
void kk_std_os_file__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_std_os_dir__done(_ctx);
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
