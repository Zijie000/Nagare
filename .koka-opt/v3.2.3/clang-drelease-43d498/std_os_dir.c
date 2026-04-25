// Koka generated module: std/os/dir, koka version: 3.2.3, platform: 64-bit
#include "std_os_dir.h"
/*---------------------------------------------------------------------------
  Copyright 2020-2021, Microsoft Research, Daan Leijen.

  This is free software; you can redistribute it and/or modify it under the
  terms of the Apache License, Version 2.0. A copy of the License can be
  found in the LICENSE file at the root of this distribution.
---------------------------------------------------------------------------*/

static kk_std_core_exn__error kk_os_ensure_dir_error( kk_string_t path, kk_integer_t mode, kk_context_t* ctx ) {
  int m  = kk_integer_clamp32(mode,ctx);
  const int err = kk_os_ensure_dir(path,m,ctx);
  if (err != 0) return kk_error_from_errno(err,ctx);
           else return kk_error_ok(kk_unit_box(kk_Unit),ctx);
}

static kk_std_core_exn__error kk_os_copy_file_error( kk_string_t from, kk_string_t to, bool preserve_mtime, kk_context_t* ctx ) {
  const int err = kk_os_copy_file(from,to,preserve_mtime,ctx);
  if (err != 0) return kk_error_from_errno(err,ctx);
           else return kk_error_ok(kk_unit_box(kk_Unit),ctx);
}

static kk_std_core_exn__error kk_os_list_directory_prim( kk_string_t dir, kk_context_t* ctx ) {
  kk_vector_t contents;
  const int err = kk_os_list_directory(dir,&contents,ctx);
  if (err != 0) return kk_error_from_errno(err,ctx);
           else return kk_error_ok(kk_vector_box(contents,ctx),ctx);
}


kk_std_core_exn__error kk_std_os_dir_prim_copy_file(kk_string_t from, kk_string_t to, bool preserve_mtime, kk_context_t* _ctx) { /* (from : string, to : string, preserve-mtime : bool) -> fsys error<()> */ 
  return kk_os_copy_file_error(from,to,preserve_mtime,kk_context());
}
 
// Copy a file.


// lift anonymous function
struct kk_std_os_dir_copy_file_fun271__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir_copy_file_fun271(kk_function_t _fself, kk_box_t _b_x2, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_copy_file_fun271(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir_copy_file_fun271, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_dir_copy_file_fun271(kk_function_t _fself, kk_box_t _b_x2, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x272;
  kk_std_os_path__path _x_x273 = kk_std_os_path__path_unbox(_b_x2, KK_OWNED, _ctx); /*std/os/path/path*/
  _x_x272 = kk_std_os_path_string(_x_x273, _ctx); /*string*/
  return kk_string_box(_x_x272);
}


// lift anonymous function
struct kk_std_os_dir_copy_file_fun277__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir_copy_file_fun277(kk_function_t _fself, kk_box_t _b_x7, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_copy_file_fun277(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir_copy_file_fun277, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_dir_copy_file_fun277(kk_function_t _fself, kk_box_t _b_x7, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x278;
  kk_std_os_path__path _x_x279 = kk_std_os_path__path_unbox(_b_x7, KK_OWNED, _ctx); /*std/os/path/path*/
  _x_x278 = kk_std_os_path_string(_x_x279, _ctx); /*string*/
  return kk_string_box(_x_x278);
}

kk_unit_t kk_std_os_dir_copy_file(kk_std_os_path__path from, kk_std_os_path__path to, kk_std_core_types__optional preserve_mtime, kk_context_t* _ctx) { /* (from : std/os/path/path, to : std/os/path/path, preserve-mtime : ? bool) -> <exn,fsys> () */ 
  kk_string_t _x_x1_10265;
  kk_box_t _x_x270;
  kk_box_t _x_x274;
  kk_std_os_path__path _x_x275 = kk_std_os_path__path_dup(from, _ctx); /*std/os/path/path*/
  _x_x274 = kk_std_os_path__path_box(_x_x275, _ctx); /*9923*/
  _x_x270 = kk_std_core_hnd__open_none1(kk_std_os_dir_new_copy_file_fun271(_ctx), _x_x274, _ctx); /*9924*/
  _x_x1_10265 = kk_string_unbox(_x_x270); /*string*/
  kk_string_t _x_x2_10266;
  kk_box_t _x_x276;
  kk_box_t _x_x280;
  kk_std_os_path__path _x_x281 = kk_std_os_path__path_dup(to, _ctx); /*std/os/path/path*/
  _x_x280 = kk_std_os_path__path_box(_x_x281, _ctx); /*9923*/
  _x_x276 = kk_std_core_hnd__open_none1(kk_std_os_dir_new_copy_file_fun277(_ctx), _x_x280, _ctx); /*9924*/
  _x_x2_10266 = kk_string_unbox(_x_x276); /*string*/
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<fsys,exn>>*/;
  kk_std_core_exn__error x;
  bool _x_x282;
  if (kk_std_core_types__is_Optional(preserve_mtime, _ctx)) {
    kk_box_t _box_x10 = preserve_mtime._cons._Optional.value;
    bool _uniq_preserve_mtime_65 = kk_bool_unbox(_box_x10);
    kk_std_core_types__optional_drop(preserve_mtime, _ctx);
    _x_x282 = _uniq_preserve_mtime_65; /*bool*/
  }
  else {
    kk_std_core_types__optional_drop(preserve_mtime, _ctx);
    _x_x282 = true; /*bool*/
  }
  x = kk_std_os_dir_prim_copy_file(_x_x1_10265, _x_x2_10266, _x_x282, _ctx); /*error<()>*/
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_std_core_exn__is_Error(x, _ctx)) {
    kk_std_core_exn__exception exn = x._cons.Error.exception;
    kk_std_core_exn__exception_dup(exn, _ctx);
    kk_std_core_exn__error_drop(x, _ctx);
    kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<exn,fsys>>*/;
    kk_string_t x_0;
    kk_string_t _x_x283 = kk_std_os_path_string(from, _ctx); /*string*/
    x_0 = kk_std_core_show_string_fs_show(_x_x283, _ctx); /*string*/
    kk_unit_t keep_0 = kk_Unit;
    kk_evv_set(w_0,kk_context());
    kk_evv_t w_1 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<exn,fsys>>*/;
    kk_string_t x_1;
    kk_string_t _x_x284 = kk_std_os_path_string(to, _ctx); /*string*/
    x_1 = kk_std_core_show_string_fs_show(_x_x284, _ctx); /*string*/
    kk_unit_t keep_1 = kk_Unit;
    kk_evv_set(w_1,kk_context());
    kk_string_t _x_x2_0_10271;
    kk_string_t _x_x285;
    kk_define_string_literal(static, _s_x286, 15, "unable to copy ", _ctx)
    _x_x285 = kk_string_dup(_s_x286, _ctx); /*string*/
    kk_string_t _x_x287;
    kk_string_t _x_x288;
    kk_string_t _x_x289;
    kk_define_string_literal(static, _s_x290, 4, " to ", _ctx)
    _x_x289 = kk_string_dup(_s_x290, _ctx); /*string*/
    _x_x288 = kk_std_core_types__lp__plus__plus__rp_(_x_x289, x_1, _ctx); /*string*/
    _x_x287 = kk_std_core_types__lp__plus__plus__rp_(x_0, _x_x288, _ctx); /*string*/
    _x_x2_0_10271 = kk_std_core_types__lp__plus__plus__rp_(_x_x285, _x_x287, _ctx); /*string*/
    kk_evv_t w_1_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<exn,fsys>>*/;
    kk_std_core_exn__exception x_1_0;
    kk_string_t _x_x291;
    kk_string_t _x_x292;
    kk_string_t _x_x293;
    kk_define_string_literal(static, _s_x294, 2, ": ", _ctx)
    _x_x293 = kk_string_dup(_s_x294, _ctx); /*string*/
    kk_string_t _x_x295;
    {
      kk_string_t _x = exn.message;
      kk_string_dup(_x, _ctx);
      _x_x295 = _x; /*string*/
    }
    _x_x292 = kk_std_core_types__lp__plus__plus__rp_(_x_x293, _x_x295, _ctx); /*string*/
    _x_x291 = kk_std_core_types__lp__plus__plus__rp_(_x_x2_0_10271, _x_x292, _ctx); /*string*/
    kk_std_core_exn__exception_info _x_x296;
    {
      kk_std_core_exn__exception_info _x_0 = exn.info;
      kk_std_core_exn__exception_info_dup(_x_0, _ctx);
      kk_std_core_exn__exception_drop(exn, _ctx);
      _x_x296 = _x_0; /*exception-info*/
    }
    x_1_0 = kk_std_core_exn__new_Exception(_x_x291, _x_x296, _ctx); /*exception*/
    kk_unit_t keep_1_0 = kk_Unit;
    kk_evv_set(w_1_0,kk_context());
    kk_std_core_hnd__ev ev_10316 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<exn>*/;
    kk_box_t _x_x297;
    {
      struct kk_std_core_hnd_Ev* _con_x298 = kk_std_core_hnd__as_Ev(ev_10316, _ctx);
      kk_box_t _box_x11 = _con_x298->hnd;
      int32_t m = _con_x298->marker;
      kk_std_core_exn__exn h = kk_std_core_exn__exn_unbox(_box_x11, KK_BORROWED, _ctx);
      kk_std_core_exn__exn_dup(h, _ctx);
      kk_std_core_hnd__clause1 _match_x260;
      kk_std_core_hnd__clause1 _brw_x261 = kk_std_core_exn_throw_exn_fs__select(h, _ctx); /*hnd/clause1<exception,277,exn,278,279>*/;
      kk_datatype_ptr_dropn(h, (KK_I32(2)), _ctx);
      _match_x260 = _brw_x261; /*hnd/clause1<exception,277,exn,278,279>*/
      {
        kk_function_t _fun_unbox_x15 = _match_x260.clause;
        _x_x297 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x15, (_fun_unbox_x15, m, ev_10316, kk_std_core_exn__exception_box(x_1_0, _ctx), _ctx), _ctx); /*46*/
      }
    }
    kk_unit_unbox(_x_x297); return kk_Unit;
  }
  {
    kk_std_core_exn__error_drop(x, _ctx);
    kk_std_os_path__path_drop(to, _ctx);
    kk_std_os_path__path_drop(from, _ctx);
    kk_Unit; return kk_Unit;
  }
}

kk_std_core_exn__error kk_std_os_dir_ensure_dir_err(kk_string_t path, kk_integer_t mode, kk_context_t* _ctx) { /* (path : string, mode : int) -> fsys error<()> */ 
  return kk_os_ensure_dir_error(path,mode,kk_context());
}
 
// Ensure a directory path exists


// lift anonymous function
struct kk_std_os_dir_ensure_dir_fun300__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir_ensure_dir_fun300(kk_function_t _fself, kk_box_t _b_x21, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_ensure_dir_fun300(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir_ensure_dir_fun300, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_dir_ensure_dir_fun300(kk_function_t _fself, kk_box_t _b_x21, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x301;
  kk_std_os_path__path _x_x302 = kk_std_os_path__path_unbox(_b_x21, KK_OWNED, _ctx); /*std/os/path/path*/
  _x_x301 = kk_std_os_path_string(_x_x302, _ctx); /*string*/
  return kk_string_box(_x_x301);
}

kk_unit_t kk_std_os_dir_ensure_dir(kk_std_os_path__path dir, kk_context_t* _ctx) { /* (dir : std/os/path/path) -> <exn,fsys> () */ 
  kk_string_t _x_x1_10274;
  kk_box_t _x_x299;
  kk_box_t _x_x303;
  kk_std_os_path__path _x_x304 = kk_std_os_path__path_dup(dir, _ctx); /*std/os/path/path*/
  _x_x303 = kk_std_os_path__path_box(_x_x304, _ctx); /*9923*/
  _x_x299 = kk_std_core_hnd__open_none1(kk_std_os_dir_new_ensure_dir_fun300(_ctx), _x_x303, _ctx); /*9924*/
  _x_x1_10274 = kk_string_unbox(_x_x299); /*string*/
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<fsys,exn>>*/;
  kk_std_core_exn__error x = kk_std_os_dir_ensure_dir_err(_x_x1_10274, kk_integer_from_small(-1), _ctx); /*error<()>*/;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  if (kk_std_core_exn__is_Error(x, _ctx)) {
    kk_std_core_exn__exception exn = x._cons.Error.exception;
    kk_std_core_exn__exception_dup(exn, _ctx);
    kk_std_core_exn__error_drop(x, _ctx);
    kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<exn,fsys>>*/;
    kk_string_t x_0;
    kk_string_t _x_x305 = kk_std_os_path_string(dir, _ctx); /*string*/
    x_0 = kk_std_core_show_string_fs_show(_x_x305, _ctx); /*string*/
    kk_unit_t keep_0 = kk_Unit;
    kk_evv_set(w_0,kk_context());
    kk_string_t _x_x2_0_10278;
    kk_string_t _x_x306;
    kk_define_string_literal(static, _s_x307, 27, "unable to create directory ", _ctx)
    _x_x306 = kk_string_dup(_s_x307, _ctx); /*string*/
    _x_x2_0_10278 = kk_std_core_types__lp__plus__plus__rp_(_x_x306, x_0, _ctx); /*string*/
    kk_evv_t w_1 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<exn,fsys>>*/;
    kk_std_core_exn__exception x_1;
    kk_string_t _x_x308;
    kk_string_t _x_x309;
    kk_string_t _x_x310;
    kk_define_string_literal(static, _s_x311, 2, ": ", _ctx)
    _x_x310 = kk_string_dup(_s_x311, _ctx); /*string*/
    kk_string_t _x_x312;
    {
      kk_string_t _x = exn.message;
      kk_string_dup(_x, _ctx);
      _x_x312 = _x; /*string*/
    }
    _x_x309 = kk_std_core_types__lp__plus__plus__rp_(_x_x310, _x_x312, _ctx); /*string*/
    _x_x308 = kk_std_core_types__lp__plus__plus__rp_(_x_x2_0_10278, _x_x309, _ctx); /*string*/
    kk_std_core_exn__exception_info _x_x313;
    {
      kk_std_core_exn__exception_info _x_0 = exn.info;
      kk_std_core_exn__exception_info_dup(_x_0, _ctx);
      kk_std_core_exn__exception_drop(exn, _ctx);
      _x_x313 = _x_0; /*exception-info*/
    }
    x_1 = kk_std_core_exn__new_Exception(_x_x308, _x_x313, _ctx); /*exception*/
    kk_unit_t keep_1 = kk_Unit;
    kk_evv_set(w_1,kk_context());
    kk_std_core_hnd__ev ev_10327 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<exn>*/;
    kk_box_t _x_x314;
    {
      struct kk_std_core_hnd_Ev* _con_x315 = kk_std_core_hnd__as_Ev(ev_10327, _ctx);
      kk_box_t _box_x24 = _con_x315->hnd;
      int32_t m = _con_x315->marker;
      kk_std_core_exn__exn h = kk_std_core_exn__exn_unbox(_box_x24, KK_BORROWED, _ctx);
      kk_std_core_exn__exn_dup(h, _ctx);
      kk_std_core_hnd__clause1 _match_x258;
      kk_std_core_hnd__clause1 _brw_x259 = kk_std_core_exn_throw_exn_fs__select(h, _ctx); /*hnd/clause1<exception,277,exn,278,279>*/;
      kk_datatype_ptr_dropn(h, (KK_I32(2)), _ctx);
      _match_x258 = _brw_x259; /*hnd/clause1<exception,277,exn,278,279>*/
      {
        kk_function_t _fun_unbox_x28 = _match_x258.clause;
        _x_x314 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x28, (_fun_unbox_x28, m, ev_10327, kk_std_core_exn__exception_box(x_1, _ctx), _ctx), _ctx); /*46*/
      }
    }
    kk_unit_unbox(_x_x314); return kk_Unit;
  }
  {
    kk_box_t _box_x32 = x._cons.Ok.result;
    kk_unit_t _pat_3_0 = kk_unit_unbox(_box_x32);
    kk_std_core_exn__error_drop(x, _ctx);
    kk_std_os_path__path_drop(dir, _ctx);
    kk_Unit; return kk_Unit;
  }
}

bool kk_std_os_dir_prim_is_dir(kk_string_t dir, kk_context_t* _ctx) { /* (dir : string) -> fsys bool */ 
  return kk_os_is_directory(dir,kk_context());
}

kk_std_core_exn__error kk_std_os_dir_prim_list_dir(kk_string_t dir, kk_context_t* _ctx) { /* (dir : string) -> fsys error<vector<string>> */ 
  return kk_os_list_directory_prim(dir,kk_context());
}
 
// lifted local: @lift-list-directory@10173, list-directory, @spec-x10114
// specialized: std/core/list/@unroll-map@10010, on parameters @uniq-f@10109, using:
// @uniq-f@10109 = fn<<(exn :: (E, V) -> V),(fsys :: X)>>(name: string){
//   std/core/types/@open<(total :: E),<(exn :: (E, V) -> V),(fsys :: X)>,(p1 : std/os/path/path, p2 : std/os/path/path) -> std/os/path/path,(p1 : std/os/path/path, p2 : std/os/path/path) -> <(exn :: (E, V) -> V),(fsys :: X)> std/os/path/path>((fn(p1: std/os/path/path, p2: std/os/path/path){
//     val parts@0@10093 : ((list :: V -> V)<string>);
//     val parts@10091 : ? ((list :: V -> V)<string>);
//     (std/os/path/Path((match (p1) {
//         ((@skip std/os/path/Path((@x: string) : string, (@pat@0@0: (list :: V -> V)<string>) : (list :: V -> V)<string>) : std/os/path/path ) as @pat@3: std/os/path/path)
//            -> @x;
//       }), (match (parts@10091) {
//         ((std/core/types/@Optional((@uniq-parts@95: (list :: V -> V)<string>) : (list :: V -> V)<string>) : ? ((list :: V -> V)<string>) ) as @pat@1@0: ? ((list :: V -> V)<string>))
//            -> @uniq-parts@95;
//         ((@skip std/core/types/@None() : ? ((list :: V -> V)<string>) ) as @pat@2@0: ? ((list :: V -> V)<string>))
//            -> std/core/types/Nil<string>;
//       })));
//   }))(dir, (std/core/types/@open<(total :: E),<(exn :: (E, V) -> V),(fsys :: X)>,(s : string) -> std/os/path/path,(s : string) -> <(exn :: (E, V) -> V),(fsys :: X)> std/os/path/path>(std/os/path/path)(name)));
// }


// lift anonymous function
struct kk_std_os_dir__trmc_lift_list_directory_10174_fun319__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir__trmc_lift_list_directory_10174_fun319(kk_function_t _fself, kk_box_t _b_x36, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir__new_trmc_lift_list_directory_10174_fun319(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir__trmc_lift_list_directory_10174_fun319, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_dir__trmc_lift_list_directory_10174_fun319(kk_function_t _fself, kk_box_t _b_x36, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_os_path__path _x_x320;
  kk_string_t _x_x321 = kk_string_unbox(_b_x36); /*string*/
  _x_x320 = kk_std_os_path_path(_x_x321, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x_x320, _ctx);
}

kk_std_core_types__list kk_std_os_dir__trmc_lift_list_directory_10174(kk_std_os_path__path dir, kk_std_core_types__list _uniq_xs_10108, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* (dir : std/os/path/path, list<string>, ctx<list<std/os/path/path>>) -> <exn,fsys> list<std/os/path/path> */ 
  if (kk_std_core_types__is_Cons(_uniq_xs_10108, _ctx)) {
    struct kk_std_core_types_Cons* _con_x317 = kk_std_core_types__as_Cons(_uniq_xs_10108, _ctx);
    kk_box_t _box_x33 = _con_x317->head;
    kk_std_core_types__list _uniq_xx_10112 = _con_x317->tail;
    kk_string_t _uniq_x_10111 = kk_string_unbox(_box_x33);
    kk_reuse_t _ru_x264 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10108, _ctx)) {
      _ru_x264 = (kk_datatype_ptr_reuse(_uniq_xs_10108, _ctx));
    }
    else {
      kk_string_dup(_uniq_x_10111, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10112, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10108, _ctx);
    }
    kk_std_os_path__path _x_x2_10281;
    kk_box_t _x_x318 = kk_std_core_hnd__open_none1(kk_std_os_dir__new_trmc_lift_list_directory_10174_fun319(_ctx), kk_string_box(_uniq_x_10111), _ctx); /*9924*/
    _x_x2_10281 = kk_std_os_path__path_unbox(_x_x318, KK_OWNED, _ctx); /*std/os/path/path*/
    kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<exn,fsys>>*/;
    kk_std_core_types__list parts_0_10093;
    {
      kk_std_core_types__list _x_0 = _x_x2_10281.parts;
      kk_std_core_types__list_dup(_x_0, _ctx);
      if (kk_std_core_types__is_Nil(_x_0, _ctx)) {
        kk_std_os_path__path_drop(_x_x2_10281, _ctx);
        parts_0_10093 = kk_std_core_types__new_Nil(_ctx); /*list<string>*/
      }
      else {
        kk_std_core_types__list_drop(_x_0, _ctx);
        kk_std_core_types__list _x_x322;
        {
          kk_std_core_types__list _x_0_0 = _x_x2_10281.parts;
          kk_std_core_types__list_dup(_x_0_0, _ctx);
          kk_std_os_path__path_drop(_x_x2_10281, _ctx);
          _x_x322 = _x_0_0; /*list<string>*/
        }
        parts_0_10093 = kk_std_core_list__unroll_reverse_acc_10003(kk_std_core_types__new_Nil(_ctx), _x_x322, _ctx); /*list<string>*/
      }
    }
    kk_std_core_types__list _b_x39_40;
    if (kk_std_core_types__is_Nil(parts_0_10093, _ctx)) {
      kk_std_core_types__list _x_1 = dir.parts;
      kk_std_core_types__list_dup(_x_1, _ctx);
      _b_x39_40 = _x_1; /*list<string>*/
    }
    else {
      kk_std_core_types__list _x_x323;
      {
        kk_std_core_types__list _x_1_0 = dir.parts;
        kk_std_core_types__list_dup(_x_1_0, _ctx);
        _x_x323 = _x_1_0; /*list<string>*/
      }
      _b_x39_40 = kk_std_os_path__unroll_push_parts_10000(parts_0_10093, _x_x323, _ctx); /*list<string>*/
    }
    kk_unit_t keep = kk_Unit;
    kk_evv_set(w,kk_context());
    kk_std_core_types__list _trmc_x10194 = kk_datatype_null(); /*list<std/os/path/path>*/;
    kk_std_core_types__list _trmc_x10195;
    kk_box_t _x_x324;
    kk_std_os_path__path _x_x325;
    kk_string_t _x_x326;
    {
      kk_string_t _x = dir.root;
      kk_string_dup(_x, _ctx);
      _x_x326 = _x; /*string*/
    }
    kk_std_core_types__list _x_x327;
    kk_std_core_types__optional _match_x257 = kk_std_core_types__new_Optional(kk_std_core_types__list_box(_b_x39_40, _ctx), _ctx); /*? 7*/;
    if (kk_std_core_types__is_Optional(_match_x257, _ctx)) {
      kk_box_t _box_x41 = _match_x257._cons._Optional.value;
      kk_std_core_types__list _uniq_parts_95 = kk_std_core_types__list_unbox(_box_x41, KK_BORROWED, _ctx);
      kk_std_core_types__list_dup(_uniq_parts_95, _ctx);
      kk_std_core_types__optional_drop(_match_x257, _ctx);
      _x_x327 = _uniq_parts_95; /*list<string>*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x257, _ctx);
      _x_x327 = kk_std_core_types__new_Nil(_ctx); /*list<string>*/
    }
    _x_x325 = kk_std_os_path__new_Path(_x_x326, _x_x327, _ctx); /*std/os/path/path*/
    _x_x324 = kk_std_os_path__path_box(_x_x325, _ctx); /*79*/
    _trmc_x10195 = kk_std_core_types__new_Cons(_ru_x264, 0, _x_x324, _trmc_x10194, _ctx); /*list<std/os/path/path>*/
    kk_field_addr_t _b_x51_56 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10195, _ctx)->tail, _ctx); /*@field-addr<list<std/os/path/path>>*/;
    kk_std_core_types__cctx _brw_x255;
    kk_std_core_types__cctx _x_x328 = kk_std_core_types__cctx_dup(_acc, _ctx); /*ctx<list<std/os/path/path>>*/
    _brw_x255 = kk_cctx_extend_linear(_x_x328,(kk_std_core_types__list_box(_trmc_x10195, _ctx)),_b_x51_56,kk_context()); /*ctx<0>*/
    kk_std_core_types__list _brw_x256 = kk_std_os_dir__trmc_lift_list_directory_10174(dir, _uniq_xx_10112, _brw_x255, _ctx); /*list<std/os/path/path>*/;
    kk_std_core_types__cctx_drop(_brw_x255, _ctx);
    return _brw_x256;
  }
  {
    kk_std_os_path__path_drop(dir, _ctx);
    kk_box_t _x_x329;
    kk_std_core_types__cctx _x_x330 = kk_std_core_types__cctx_dup(_acc, _ctx); /*ctx<list<std/os/path/path>>*/
    _x_x329 = kk_cctx_apply_linear(_x_x330,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x329, KK_OWNED, _ctx);
  }
}
 
// lifted local: @lift-list-directory@10173, list-directory, @spec-x10114
// specialized: std/core/list/@unroll-map@10010, on parameters @uniq-f@10109, using:
// @uniq-f@10109 = fn<<(exn :: (E, V) -> V),(fsys :: X)>>(name: string){
//   std/core/types/@open<(total :: E),<(exn :: (E, V) -> V),(fsys :: X)>,(p1 : std/os/path/path, p2 : std/os/path/path) -> std/os/path/path,(p1 : std/os/path/path, p2 : std/os/path/path) -> <(exn :: (E, V) -> V),(fsys :: X)> std/os/path/path>((fn(p1: std/os/path/path, p2: std/os/path/path){
//     val parts@0@10093 : ((list :: V -> V)<string>);
//     val parts@10091 : ? ((list :: V -> V)<string>);
//     (std/os/path/Path((match (p1) {
//         ((@skip std/os/path/Path((@x: string) : string, (@pat@0@0: (list :: V -> V)<string>) : (list :: V -> V)<string>) : std/os/path/path ) as @pat@3: std/os/path/path)
//            -> @x;
//       }), (match (parts@10091) {
//         ((std/core/types/@Optional((@uniq-parts@95: (list :: V -> V)<string>) : (list :: V -> V)<string>) : ? ((list :: V -> V)<string>) ) as @pat@1@0: ? ((list :: V -> V)<string>))
//            -> @uniq-parts@95;
//         ((@skip std/core/types/@None() : ? ((list :: V -> V)<string>) ) as @pat@2@0: ? ((list :: V -> V)<string>))
//            -> std/core/types/Nil<string>;
//       })));
//   }))(dir, (std/core/types/@open<(total :: E),<(exn :: (E, V) -> V),(fsys :: X)>,(s : string) -> std/os/path/path,(s : string) -> <(exn :: (E, V) -> V),(fsys :: X)> std/os/path/path>(std/os/path/path)(name)));
// }

kk_std_core_types__list kk_std_os_dir__lift_list_directory_10174(kk_std_os_path__path dir_0, kk_std_core_types__list _uniq_xs_10108_0, kk_context_t* _ctx) { /* (dir : std/os/path/path, list<string>) -> <exn,fsys> list<std/os/path/path> */ 
  kk_std_core_types__cctx _brw_x253 = kk_cctx_empty(kk_context()); /*ctx<0>*/;
  kk_std_core_types__list _brw_x254 = kk_std_os_dir__trmc_lift_list_directory_10174(dir_0, _uniq_xs_10108_0, _brw_x253, _ctx); /*list<std/os/path/path>*/;
  kk_std_core_types__cctx_drop(_brw_x253, _ctx);
  return _brw_x254;
}
 
// lifted local: list-directory, @spec-x10107
// specialized: std/core/list/map, on parameters @uniq-f@10104, using:
// @uniq-f@10104 = fn<<(exn :: (E, V) -> V),(fsys :: X)>>(name: string){
//   std/core/types/@open<(total :: E),<(exn :: (E, V) -> V),(fsys :: X)>,(p1 : std/os/path/path, p2 : std/os/path/path) -> std/os/path/path,(p1 : std/os/path/path, p2 : std/os/path/path) -> <(exn :: (E, V) -> V),(fsys :: X)> std/os/path/path>((fn(p1: std/os/path/path, p2: std/os/path/path){
//     val parts@0@10093 : ((list :: V -> V)<string>);
//     val parts@10091 : ? ((list :: V -> V)<string>);
//     (std/os/path/Path((match (p1) {
//         ((@skip std/os/path/Path((@x: string) : string, (@pat@0@0: (list :: V -> V)<string>) : (list :: V -> V)<string>) : std/os/path/path ) as @pat@3: std/os/path/path)
//            -> @x;
//       }), (match (parts@10091) {
//         ((std/core/types/@Optional((@uniq-parts@95: (list :: V -> V)<string>) : (list :: V -> V)<string>) : ? ((list :: V -> V)<string>) ) as @pat@1@0: ? ((list :: V -> V)<string>))
//            -> @uniq-parts@95;
//         ((@skip std/core/types/@None() : ? ((list :: V -> V)<string>) ) as @pat@2@0: ? ((list :: V -> V)<string>))
//            -> std/core/types/Nil<string>;
//       })));
//   }))(dir, (std/core/types/@open<(total :: E),<(exn :: (E, V) -> V),(fsys :: X)>,(s : string) -> std/os/path/path,(s : string) -> <(exn :: (E, V) -> V),(fsys :: X)> std/os/path/path>(std/os/path/path)(name)));
// }

kk_std_core_types__list kk_std_os_dir__lift_list_directory_10173(kk_std_os_path__path dir, kk_std_core_types__list _uniq_xs_10103, kk_context_t* _ctx) { /* (dir : std/os/path/path, list<string>) -> <exn,fsys> list<std/os/path/path> */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10103, _ctx)) {
    kk_std_os_path__path_drop(dir, _ctx);
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    kk_std_core_types__cctx _brw_x251 = kk_cctx_empty(kk_context()); /*ctx<0>*/;
    kk_std_core_types__list _brw_x252 = kk_std_os_dir__trmc_lift_list_directory_10174(dir, _uniq_xs_10103, _brw_x251, _ctx); /*list<std/os/path/path>*/;
    kk_std_core_types__cctx_drop(_brw_x251, _ctx);
    return _brw_x252;
  }
}
 
// List directory contents (excluding `.` and `..`).
// Returns a list of full paths (not just the names in the directory).


// lift anonymous function
struct kk_std_os_dir_list_directory_fun332__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir_list_directory_fun332(kk_function_t _fself, kk_box_t _b_x64, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_list_directory_fun332(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir_list_directory_fun332, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_dir_list_directory_fun332(kk_function_t _fself, kk_box_t _b_x64, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x333;
  kk_std_os_path__path _x_x334 = kk_std_os_path__path_unbox(_b_x64, KK_OWNED, _ctx); /*std/os/path/path*/
  _x_x333 = kk_std_os_path_string(_x_x334, _ctx); /*string*/
  return kk_string_box(_x_x333);
}


// lift anonymous function
struct kk_std_os_dir_list_directory_fun338__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir_list_directory_fun338(kk_function_t _fself, kk_box_t _b_x69, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_list_directory_fun338(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir_list_directory_fun338, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_dir_list_directory_fun338(kk_function_t _fself, kk_box_t _b_x69, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_exn__error _x_x339;
  kk_string_t _x_x340 = kk_string_unbox(_b_x69); /*string*/
  _x_x339 = kk_std_os_dir_prim_list_dir(_x_x340, _ctx); /*error<vector<string>>*/
  return kk_std_core_exn__error_box(_x_x339, _ctx);
}

kk_std_core_types__list kk_std_os_dir_list_directory(kk_std_os_path__path dir, kk_context_t* _ctx) { /* (dir : std/os/path/path) -> <exn,fsys> list<std/os/path/path> */ 
  kk_string_t _x_x1_10283;
  kk_box_t _x_x331;
  kk_box_t _x_x335;
  kk_std_os_path__path _x_x336 = kk_std_os_path__path_dup(dir, _ctx); /*std/os/path/path*/
  _x_x335 = kk_std_os_path__path_box(_x_x336, _ctx); /*9923*/
  _x_x331 = kk_std_core_hnd__open_none1(kk_std_os_dir_new_list_directory_fun332(_ctx), _x_x335, _ctx); /*9924*/
  _x_x1_10283 = kk_string_unbox(_x_x331); /*string*/
  kk_std_core_exn__error _match_x248;
  kk_box_t _x_x337 = kk_std_core_hnd__open_none1(kk_std_os_dir_new_list_directory_fun338(_ctx), kk_string_box(_x_x1_10283), _ctx); /*9924*/
  _match_x248 = kk_std_core_exn__error_unbox(_x_x337, KK_OWNED, _ctx); /*error<vector<string>>*/
  if (kk_std_core_exn__is_Error(_match_x248, _ctx)) {
    kk_std_core_exn__exception exn = _match_x248._cons.Error.exception;
    kk_std_os_path__path_drop(dir, _ctx);
    kk_std_core_exn__exception_dup(exn, _ctx);
    kk_std_core_exn__error_drop(_match_x248, _ctx);
    kk_std_core_hnd__ev ev_10335 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<exn>*/;
    kk_box_t _x_x341;
    {
      struct kk_std_core_hnd_Ev* _con_x342 = kk_std_core_hnd__as_Ev(ev_10335, _ctx);
      kk_box_t _box_x70 = _con_x342->hnd;
      int32_t m = _con_x342->marker;
      kk_std_core_exn__exn h = kk_std_core_exn__exn_unbox(_box_x70, KK_BORROWED, _ctx);
      kk_std_core_exn__exn_dup(h, _ctx);
      kk_std_core_hnd__clause1 _match_x249;
      kk_std_core_hnd__clause1 _brw_x250 = kk_std_core_exn_throw_exn_fs__select(h, _ctx); /*hnd/clause1<exception,277,exn,278,279>*/;
      kk_datatype_ptr_dropn(h, (KK_I32(2)), _ctx);
      _match_x249 = _brw_x250; /*hnd/clause1<exception,277,exn,278,279>*/
      {
        kk_function_t _fun_unbox_x74 = _match_x249.clause;
        _x_x341 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x74, (_fun_unbox_x74, m, ev_10335, kk_std_core_exn__exception_box(exn, _ctx), _ctx), _ctx); /*46*/
      }
    }
    return kk_std_core_types__list_unbox(_x_x341, KK_OWNED, _ctx);
  }
  {
    kk_box_t _box_x78 = _match_x248._cons.Ok.result;
    kk_vector_t contents = kk_vector_unbox(_box_x78, _ctx);
    kk_vector_dup(contents, _ctx);
    kk_std_core_exn__error_drop(_match_x248, _ctx);
    kk_std_core_types__list _uniq_xs_10103 = kk_std_core_vector_vlist(contents, kk_std_core_types__new_None(_ctx), _ctx); /*list<string>*/;
    return kk_std_os_dir__lift_list_directory_10173(dir, _uniq_xs_10103, _ctx);
  }
}
 
// lifted local: list-directory-recursive, @spec-x10120
// specialized: std/core/list/filter, on parameters @uniq-pred@10117, using:
// @uniq-pred@10117 = std/core/types/@open<(fsys :: X),<(fsys :: X),(div :: X),(exn :: (E, V) -> V)>,(dir : std/os/path/path) -> (fsys :: X) bool,(dir : std/os/path/path) -> <(fsys :: X),(div :: X),(exn :: (E, V) -> V)> bool>(std/os/dir/is-directory)


// lift anonymous function
struct kk_std_os_dir__lift_list_directory_recursive_10175_fun343__t {
  struct kk_function_s _base;
};
static bool kk_std_os_dir__lift_list_directory_recursive_10175_fun343(kk_function_t _fself, kk_box_t _b_x86, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir__new_lift_list_directory_recursive_10175_fun343(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir__lift_list_directory_recursive_10175_fun343, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_os_dir__lift_list_directory_recursive_10175_fun345__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir__lift_list_directory_recursive_10175_fun345(kk_function_t _fself, kk_box_t _b_x83, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir__new_lift_list_directory_recursive_10175_fun345(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir__lift_list_directory_recursive_10175_fun345, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_dir__lift_list_directory_recursive_10175_fun345(kk_function_t _fself, kk_box_t _b_x83, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  bool _x_x346;
  kk_std_os_path__path _x_x347 = kk_std_os_path__path_unbox(_b_x83, KK_OWNED, _ctx); /*std/os/path/path*/
  _x_x346 = kk_std_os_dir_is_directory(_x_x347, _ctx); /*bool*/
  return kk_bool_box(_x_x346);
}
static bool kk_std_os_dir__lift_list_directory_recursive_10175_fun343(kk_function_t _fself, kk_box_t _b_x86, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_box_t _x_x344 = kk_std_core_hnd__open_none1(kk_std_os_dir__new_lift_list_directory_recursive_10175_fun345(_ctx), _b_x86, _ctx); /*9924*/
  return kk_bool_unbox(_x_x344);
}

kk_std_core_types__list kk_std_os_dir__lift_list_directory_recursive_10175(kk_std_core_types__list _uniq_xs_10116, kk_context_t* _ctx) { /* (list<std/os/path/path>) -> <fsys,div,exn> list<std/os/path/path> */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10116, _ctx)) {
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    return kk_std_core_list__unroll_filter_10007(_uniq_xs_10116, kk_std_os_dir__new_lift_list_directory_recursive_10175_fun343(_ctx), _ctx);
  }
}
 
// lifted local: list-directory-recursive, @spec-x10123
// specialized: std/core/list/flatmap, on parameters @uniq-f@10122, using:
// @uniq-f@10122 = fn<<(div :: X),(exn :: (E, V) -> V),(fsys :: X)>>(sub: std/os/path/path){
//   std/os/dir/list-directory-recursive(sub, (std/core/types/@Optional<int>((std/core/types/@open<(total :: E),<(div :: X),(exn :: (E, V) -> V),(fsys :: X)>,(x : int, y : int) -> int,(x : int, y : int) -> <(div :: X),(exn :: (E, V) -> V),(fsys :: X)> int>((fn(x: int, y: int){
//       (std/core/int/int-sub(x, y));
//     }))((match (max-depth) {
//         ((std/core/types/@Optional((@uniq-max-depth@509: int) : int) : ? int ) as @pat: ? int)
//            -> @uniq-max-depth@509;
//         ((@skip std/core/types/@None() : ? int ) as @pat@0: ? int)
//            -> 1000;
//       }), 1)))));
// }

kk_std_core_types__list kk_std_os_dir__lift_list_directory_recursive_10176(kk_std_core_types__optional max_depth, kk_std_core_types__list _uniq_xs_10121, kk_context_t* _ctx) { /* (max-depth : ? int, list<std/os/path/path>) -> <div,exn,fsys> list<std/os/path/path> */ 
  return kk_std_os_dir__lift_list_directory_recursive_10177(max_depth, kk_std_core_types__new_Nil(_ctx), _uniq_xs_10121, _ctx);
}
 
// monadic lift

kk_std_core_types__list kk_std_os_dir__mlift_lift_list_directory_recursive_10177_10296(kk_std_os_path__path _uniq_y_10128, kk_std_core_types__list _y_x10211, kk_context_t* _ctx) { /* (std/os/path/path, list<std/os/path/path>) -> <div,exn,fsys> list<std/os/path/path> */ 
  return kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_std_os_path__path_box(_uniq_y_10128, _ctx), _y_x10211, _ctx);
}
 
// monadic lift

kk_std_core_types__list kk_std_os_dir__mlift_lift_list_directory_recursive_10177_10297(kk_std_core_types__list _uniq_zz_10133, kk_std_core_types__optional max_depth, kk_std_core_types__list _uniq_ys_1_10132_10134, kk_context_t* _ctx) { /* (list<std/os/path/path>, max-depth : ? int, list<std/os/path/path>) -> <pure,fsys> list<std/os/path/path> */ 
  return kk_std_os_dir__lift_list_directory_recursive_10177(max_depth, _uniq_ys_1_10132_10134, _uniq_zz_10133, _ctx);
}
 
// monadic lift

kk_std_core_types__list kk_std_os_dir__mlift_list_directory_recursive_10298(kk_std_core_types__list all, kk_std_core_types__list _y_x10218, kk_context_t* _ctx) { /* (all : list<std/os/path/path>, list<std/os/path/path>) -> <div,exn,fsys> list<std/os/path/path> */ 
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<div,exn,fsys>>*/;
  kk_std_core_types__list x;
  if (kk_std_core_types__is_Nil(all, _ctx)) {
    x = _y_x10218; /*list<std/os/path/path>*/
  }
  else {
    x = kk_std_core_list__unroll_append_10004(all, _y_x10218, _ctx); /*list<std/os/path/path>*/
  }
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  return x;
}
 
// monadic lift


// lift anonymous function
struct kk_std_os_dir__mlift_list_directory_recursive_10299_fun349__t {
  struct kk_function_s _base;
  kk_std_core_types__list all_0;
};
static kk_box_t kk_std_os_dir__mlift_list_directory_recursive_10299_fun349(kk_function_t _fself, kk_box_t _b_x97, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir__new_mlift_list_directory_recursive_10299_fun349(kk_std_core_types__list all_0, kk_context_t* _ctx) {
  struct kk_std_os_dir__mlift_list_directory_recursive_10299_fun349__t* _self = kk_function_alloc_as(struct kk_std_os_dir__mlift_list_directory_recursive_10299_fun349__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_os_dir__mlift_list_directory_recursive_10299_fun349, kk_context());
  _self->all_0 = all_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_os_dir__mlift_list_directory_recursive_10299_fun349(kk_function_t _fself, kk_box_t _b_x97, kk_context_t* _ctx) {
  struct kk_std_os_dir__mlift_list_directory_recursive_10299_fun349__t* _self = kk_function_as(struct kk_std_os_dir__mlift_list_directory_recursive_10299_fun349__t*, _fself, _ctx);
  kk_std_core_types__list all_0 = _self->all_0; /* list<std/os/path/path> */
  kk_drop_match(_self, {kk_std_core_types__list_dup(all_0, _ctx);}, {}, _ctx)
  kk_std_core_types__list _y_x10218_0_99 = kk_std_core_types__list_unbox(_b_x97, KK_OWNED, _ctx); /*list<std/os/path/path>*/;
  kk_std_core_types__list _x_x350 = kk_std_os_dir__mlift_list_directory_recursive_10298(all_0, _y_x10218_0_99, _ctx); /*list<std/os/path/path>*/
  return kk_std_core_types__list_box(_x_x350, _ctx);
}

kk_std_core_types__list kk_std_os_dir__mlift_list_directory_recursive_10299(kk_std_core_types__list all_0, kk_std_core_types__optional max_depth_0, kk_std_core_types__list dirs, kk_context_t* _ctx) { /* (all : list<std/os/path/path>, max-depth : ? int, dirs : list<std/os/path/path>) -> <fsys,div,exn> list<std/os/path/path> */ 
  kk_std_core_types__list x_0_10341 = kk_std_os_dir__lift_list_directory_recursive_10176(max_depth_0, dirs, _ctx); /*list<std/os/path/path>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_0_10341, _ctx);
    kk_box_t _x_x348 = kk_std_core_hnd_yield_extend(kk_std_os_dir__new_mlift_list_directory_recursive_10299_fun349(all_0, _ctx), _ctx); /*2419*/
    return kk_std_core_types__list_unbox(_x_x348, KK_OWNED, _ctx);
  }
  {
    return kk_std_os_dir__mlift_list_directory_recursive_10298(all_0, x_0_10341, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_os_dir__mlift_list_directory_recursive_10300_fun353__t {
  struct kk_function_s _base;
  kk_std_core_types__list all_1;
  kk_std_core_types__optional max_depth_1;
};
static kk_box_t kk_std_os_dir__mlift_list_directory_recursive_10300_fun353(kk_function_t _fself, kk_box_t _b_x101, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir__new_mlift_list_directory_recursive_10300_fun353(kk_std_core_types__list all_1, kk_std_core_types__optional max_depth_1, kk_context_t* _ctx) {
  struct kk_std_os_dir__mlift_list_directory_recursive_10300_fun353__t* _self = kk_function_alloc_as(struct kk_std_os_dir__mlift_list_directory_recursive_10300_fun353__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_os_dir__mlift_list_directory_recursive_10300_fun353, kk_context());
  _self->all_1 = all_1;
  _self->max_depth_1 = max_depth_1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_os_dir__mlift_list_directory_recursive_10300_fun353(kk_function_t _fself, kk_box_t _b_x101, kk_context_t* _ctx) {
  struct kk_std_os_dir__mlift_list_directory_recursive_10300_fun353__t* _self = kk_function_as(struct kk_std_os_dir__mlift_list_directory_recursive_10300_fun353__t*, _fself, _ctx);
  kk_std_core_types__list all_1 = _self->all_1; /* list<std/os/path/path> */
  kk_std_core_types__optional max_depth_1 = _self->max_depth_1; /* ? int */
  kk_drop_match(_self, {kk_std_core_types__list_dup(all_1, _ctx);kk_std_core_types__optional_dup(max_depth_1, _ctx);}, {}, _ctx)
  kk_std_core_types__list dirs_0_103 = kk_std_core_types__list_unbox(_b_x101, KK_OWNED, _ctx); /*list<std/os/path/path>*/;
  kk_std_core_types__list _x_x354 = kk_std_os_dir__mlift_list_directory_recursive_10299(all_1, max_depth_1, dirs_0_103, _ctx); /*list<std/os/path/path>*/
  return kk_std_core_types__list_box(_x_x354, _ctx);
}

kk_std_core_types__list kk_std_os_dir__mlift_list_directory_recursive_10300(kk_std_core_types__optional max_depth_1, kk_std_core_types__list all_1, kk_context_t* _ctx) { /* (max-depth : ? int, all : list<std/os/path/path>) -> <exn,fsys> list<std/os/path/path> */ 
  kk_std_core_types__list x_1_10343;
  kk_std_core_types__list _x_x351 = kk_std_core_types__list_dup(all_1, _ctx); /*list<std/os/path/path>*/
  x_1_10343 = kk_std_os_dir__lift_list_directory_recursive_10175(_x_x351, _ctx); /*list<std/os/path/path>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_1_10343, _ctx);
    kk_box_t _x_x352 = kk_std_core_hnd_yield_extend(kk_std_os_dir__new_mlift_list_directory_recursive_10300_fun353(all_1, max_depth_1, _ctx), _ctx); /*2419*/
    return kk_std_core_types__list_unbox(_x_x352, KK_OWNED, _ctx);
  }
  {
    return kk_std_os_dir__mlift_list_directory_recursive_10299(all_1, max_depth_1, x_1_10343, _ctx);
  }
}
 
// lifted local: @lift-list-directory-recursive@10176, list-directory-recursive, @spec-x10136
// specialized: std/core/list/@lift-flatmap@6013, on parameters @uniq-f@10124, using:
// @uniq-f@10124 = fn<<(div :: X),(exn :: (E, V) -> V),(fsys :: X)>>(sub: std/os/path/path){
//   std/os/dir/list-directory-recursive(sub, (std/core/types/@Optional<int>((std/core/types/@open<(total :: E),<(div :: X),(exn :: (E, V) -> V),(fsys :: X)>,(x : int, y : int) -> int,(x : int, y : int) -> <(div :: X),(exn :: (E, V) -> V),(fsys :: X)> int>((fn(x: int, y: int){
//       (std/core/int/int-sub(x, y));
//     }))((match (max-depth) {
//         ((std/core/types/@Optional((@uniq-max-depth@509: int) : int) : ? int ) as @pat: ? int)
//            -> @uniq-max-depth@509;
//         ((@skip std/core/types/@None() : ? int ) as @pat@0: ? int)
//            -> 1000;
//       }), 1)))));
// }


// lift anonymous function
struct kk_std_os_dir__lift_list_directory_recursive_10177_fun357__t {
  struct kk_function_s _base;
  kk_std_os_path__path _uniq_y_10128_0;
};
static kk_box_t kk_std_os_dir__lift_list_directory_recursive_10177_fun357(kk_function_t _fself, kk_box_t _b_x106, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir__new_lift_list_directory_recursive_10177_fun357(kk_std_os_path__path _uniq_y_10128_0, kk_context_t* _ctx) {
  struct kk_std_os_dir__lift_list_directory_recursive_10177_fun357__t* _self = kk_function_alloc_as(struct kk_std_os_dir__lift_list_directory_recursive_10177_fun357__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_os_dir__lift_list_directory_recursive_10177_fun357, kk_context());
  _self->_uniq_y_10128_0 = _uniq_y_10128_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_os_dir__lift_list_directory_recursive_10177_fun357(kk_function_t _fself, kk_box_t _b_x106, kk_context_t* _ctx) {
  struct kk_std_os_dir__lift_list_directory_recursive_10177_fun357__t* _self = kk_function_as(struct kk_std_os_dir__lift_list_directory_recursive_10177_fun357__t*, _fself, _ctx);
  kk_std_os_path__path _uniq_y_10128_0 = _self->_uniq_y_10128_0; /* std/os/path/path */
  kk_drop_match(_self, {kk_std_os_path__path_dup(_uniq_y_10128_0, _ctx);}, {}, _ctx)
  kk_std_core_types__list _y_x10211_0_119 = kk_std_core_types__list_unbox(_b_x106, KK_OWNED, _ctx); /*list<std/os/path/path>*/;
  kk_std_core_types__list _x_x358 = kk_std_os_dir__mlift_lift_list_directory_recursive_10177_10296(_uniq_y_10128_0, _y_x10211_0_119, _ctx); /*list<std/os/path/path>*/
  return kk_std_core_types__list_box(_x_x358, _ctx);
}


// lift anonymous function
struct kk_std_os_dir__lift_list_directory_recursive_10177_fun363__t {
  struct kk_function_s _base;
  kk_std_core_types__list _uniq_zz_10133_0;
  kk_std_core_types__optional max_depth_2;
};
static kk_box_t kk_std_os_dir__lift_list_directory_recursive_10177_fun363(kk_function_t _fself, kk_box_t _b_x114, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir__new_lift_list_directory_recursive_10177_fun363(kk_std_core_types__list _uniq_zz_10133_0, kk_std_core_types__optional max_depth_2, kk_context_t* _ctx) {
  struct kk_std_os_dir__lift_list_directory_recursive_10177_fun363__t* _self = kk_function_alloc_as(struct kk_std_os_dir__lift_list_directory_recursive_10177_fun363__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_os_dir__lift_list_directory_recursive_10177_fun363, kk_context());
  _self->_uniq_zz_10133_0 = _uniq_zz_10133_0;
  _self->max_depth_2 = max_depth_2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_os_dir__lift_list_directory_recursive_10177_fun363(kk_function_t _fself, kk_box_t _b_x114, kk_context_t* _ctx) {
  struct kk_std_os_dir__lift_list_directory_recursive_10177_fun363__t* _self = kk_function_as(struct kk_std_os_dir__lift_list_directory_recursive_10177_fun363__t*, _fself, _ctx);
  kk_std_core_types__list _uniq_zz_10133_0 = _self->_uniq_zz_10133_0; /* list<std/os/path/path> */
  kk_std_core_types__optional max_depth_2 = _self->max_depth_2; /* ? int */
  kk_drop_match(_self, {kk_std_core_types__list_dup(_uniq_zz_10133_0, _ctx);kk_std_core_types__optional_dup(max_depth_2, _ctx);}, {}, _ctx)
  kk_std_core_types__list _uniq_ys_1_10132_10134_0_120 = kk_std_core_types__list_unbox(_b_x114, KK_OWNED, _ctx); /*list<std/os/path/path>*/;
  kk_std_core_types__list _x_x364 = kk_std_os_dir__mlift_lift_list_directory_recursive_10177_10297(_uniq_zz_10133_0, max_depth_2, _uniq_ys_1_10132_10134_0_120, _ctx); /*list<std/os/path/path>*/
  return kk_std_core_types__list_box(_x_x364, _ctx);
}

kk_std_core_types__list kk_std_os_dir__lift_list_directory_recursive_10177(kk_std_core_types__optional max_depth_2, kk_std_core_types__list _uniq_ys_10125, kk_std_core_types__list _uniq_zs_10126, kk_context_t* _ctx) { /* (max-depth : ? int, list<std/os/path/path>, list<std/os/path/path>) -> <div,exn,fsys> list<std/os/path/path> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_ys_10125, _ctx)) {
    struct kk_std_core_types_Cons* _con_x355 = kk_std_core_types__as_Cons(_uniq_ys_10125, _ctx);
    kk_box_t _box_x104 = _con_x355->head;
    kk_std_core_types__list _uniq_yy_10129 = _con_x355->tail;
    kk_std_os_path__path _uniq_y_10128_0 = kk_std_os_path__path_unbox(_box_x104, KK_BORROWED, _ctx);
    kk_reuse_t _ru_x266 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_ys_10125, _ctx)) {
      kk_std_os_path__path_dup(_uniq_y_10128_0, _ctx);
      kk_box_drop(_box_x104, _ctx);
      _ru_x266 = (kk_datatype_ptr_reuse(_uniq_ys_10125, _ctx));
    }
    else {
      kk_std_os_path__path_dup(_uniq_y_10128_0, _ctx);
      kk_std_core_types__list_dup(_uniq_yy_10129, _ctx);
      kk_datatype_ptr_decref(_uniq_ys_10125, _ctx);
    }
    kk_std_core_types__list x_2_10345 = kk_std_os_dir__lift_list_directory_recursive_10177(max_depth_2, _uniq_yy_10129, _uniq_zs_10126, _ctx); /*list<std/os/path/path>*/;
    if (kk_yielding(kk_context())) {
      kk_reuse_drop(_ru_x266,kk_context());
      kk_std_core_types__list_drop(x_2_10345, _ctx);
      kk_box_t _x_x356 = kk_std_core_hnd_yield_extend(kk_std_os_dir__new_lift_list_directory_recursive_10177_fun357(_uniq_y_10128_0, _ctx), _ctx); /*2419*/
      return kk_std_core_types__list_unbox(_x_x356, KK_OWNED, _ctx);
    }
    {
      return kk_std_core_types__new_Cons(_ru_x266, 0, kk_std_os_path__path_box(_uniq_y_10128_0, _ctx), x_2_10345, _ctx);
    }
  }
  if (kk_std_core_types__is_Cons(_uniq_zs_10126, _ctx)) {
    struct kk_std_core_types_Cons* _con_x359 = kk_std_core_types__as_Cons(_uniq_zs_10126, _ctx);
    kk_box_t _box_x109 = _con_x359->head;
    kk_std_core_types__list _uniq_zz_10133_0 = _con_x359->tail;
    kk_std_os_path__path _uniq_z_10132 = kk_std_os_path__path_unbox(_box_x109, KK_BORROWED, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_zs_10126, _ctx)) {
      kk_std_os_path__path_dup(_uniq_z_10132, _ctx);
      kk_box_drop(_box_x109, _ctx);
      kk_datatype_ptr_free(_uniq_zs_10126, _ctx);
    }
    else {
      kk_std_os_path__path_dup(_uniq_z_10132, _ctx);
      kk_std_core_types__list_dup(_uniq_zz_10133_0, _ctx);
      kk_datatype_ptr_decref(_uniq_zs_10126, _ctx);
    }
    kk_integer_t _b_x111_112;
    kk_integer_t _x_x360;
    if (kk_std_core_types__is_Optional(max_depth_2, _ctx)) {
      kk_box_t _box_x110 = max_depth_2._cons._Optional.value;
      kk_integer_t _uniq_max_depth_509_0 = kk_integer_unbox(_box_x110, _ctx);
      kk_integer_dup(_uniq_max_depth_509_0, _ctx);
      _x_x360 = _uniq_max_depth_509_0; /*int*/
    }
    else {
      _x_x360 = kk_integer_from_small(1000); /*int*/
    }
    _b_x111_112 = kk_integer_add_small_const(_x_x360, -1, _ctx); /*int*/
    kk_std_core_types__list x_3_10348;
    kk_std_core_types__optional _x_x361 = kk_std_core_types__new_Optional(kk_integer_box(_b_x111_112, _ctx), _ctx); /*? 7*/
    x_3_10348 = kk_std_os_dir_list_directory_recursive(_uniq_z_10132, _x_x361, _ctx); /*list<std/os/path/path>*/
    if (kk_yielding(kk_context())) {
      kk_std_core_types__list_drop(x_3_10348, _ctx);
      kk_box_t _x_x362 = kk_std_core_hnd_yield_extend(kk_std_os_dir__new_lift_list_directory_recursive_10177_fun363(_uniq_zz_10133_0, max_depth_2, _ctx), _ctx); /*2419*/
      return kk_std_core_types__list_unbox(_x_x362, KK_OWNED, _ctx);
    }
    { // tailcall
      _uniq_ys_10125 = x_3_10348;
      _uniq_zs_10126 = _uniq_zz_10133_0;
      goto kk__tailcall;
    }
  }
  {
    kk_std_core_types__optional_drop(max_depth_2, _ctx);
    return kk_std_core_types__new_Nil(_ctx);
  }
}
 
// Recursively list all the entries under a directory.


// lift anonymous function
struct kk_std_os_dir_list_directory_recursive_fun366__t {
  struct kk_function_s _base;
  kk_std_core_types__optional max_depth_3;
};
static kk_box_t kk_std_os_dir_list_directory_recursive_fun366(kk_function_t _fself, kk_box_t _b_x123, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_list_directory_recursive_fun366(kk_std_core_types__optional max_depth_3, kk_context_t* _ctx) {
  struct kk_std_os_dir_list_directory_recursive_fun366__t* _self = kk_function_alloc_as(struct kk_std_os_dir_list_directory_recursive_fun366__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_os_dir_list_directory_recursive_fun366, kk_context());
  _self->max_depth_3 = max_depth_3;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_os_dir_list_directory_recursive_fun366(kk_function_t _fself, kk_box_t _b_x123, kk_context_t* _ctx) {
  struct kk_std_os_dir_list_directory_recursive_fun366__t* _self = kk_function_as(struct kk_std_os_dir_list_directory_recursive_fun366__t*, _fself, _ctx);
  kk_std_core_types__optional max_depth_3 = _self->max_depth_3; /* ? int */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(max_depth_3, _ctx);}, {}, _ctx)
  kk_std_core_types__list all_2_131 = kk_std_core_types__list_unbox(_b_x123, KK_OWNED, _ctx); /*list<std/os/path/path>*/;
  kk_std_core_types__list _x_x367 = kk_std_os_dir__mlift_list_directory_recursive_10300(max_depth_3, all_2_131, _ctx); /*list<std/os/path/path>*/
  return kk_std_core_types__list_box(_x_x367, _ctx);
}


// lift anonymous function
struct kk_std_os_dir_list_directory_recursive_fun370__t {
  struct kk_function_s _base;
  kk_std_core_types__optional max_depth_3;
  kk_std_core_types__list x_4_10351;
};
static kk_box_t kk_std_os_dir_list_directory_recursive_fun370(kk_function_t _fself, kk_box_t _b_x125, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_list_directory_recursive_fun370(kk_std_core_types__optional max_depth_3, kk_std_core_types__list x_4_10351, kk_context_t* _ctx) {
  struct kk_std_os_dir_list_directory_recursive_fun370__t* _self = kk_function_alloc_as(struct kk_std_os_dir_list_directory_recursive_fun370__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_os_dir_list_directory_recursive_fun370, kk_context());
  _self->max_depth_3 = max_depth_3;
  _self->x_4_10351 = x_4_10351;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_os_dir_list_directory_recursive_fun370(kk_function_t _fself, kk_box_t _b_x125, kk_context_t* _ctx) {
  struct kk_std_os_dir_list_directory_recursive_fun370__t* _self = kk_function_as(struct kk_std_os_dir_list_directory_recursive_fun370__t*, _fself, _ctx);
  kk_std_core_types__optional max_depth_3 = _self->max_depth_3; /* ? int */
  kk_std_core_types__list x_4_10351 = _self->x_4_10351; /* list<std/os/path/path> */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(max_depth_3, _ctx);kk_std_core_types__list_dup(x_4_10351, _ctx);}, {}, _ctx)
  kk_std_core_types__list dirs_1_132 = kk_std_core_types__list_unbox(_b_x125, KK_OWNED, _ctx); /*list<std/os/path/path>*/;
  kk_std_core_types__list _x_x371 = kk_std_os_dir__mlift_list_directory_recursive_10299(x_4_10351, max_depth_3, dirs_1_132, _ctx); /*list<std/os/path/path>*/
  return kk_std_core_types__list_box(_x_x371, _ctx);
}


// lift anonymous function
struct kk_std_os_dir_list_directory_recursive_fun373__t {
  struct kk_function_s _base;
  kk_std_core_types__list x_4_10351;
};
static kk_box_t kk_std_os_dir_list_directory_recursive_fun373(kk_function_t _fself, kk_box_t _b_x127, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_list_directory_recursive_fun373(kk_std_core_types__list x_4_10351, kk_context_t* _ctx) {
  struct kk_std_os_dir_list_directory_recursive_fun373__t* _self = kk_function_alloc_as(struct kk_std_os_dir_list_directory_recursive_fun373__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_os_dir_list_directory_recursive_fun373, kk_context());
  _self->x_4_10351 = x_4_10351;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_os_dir_list_directory_recursive_fun373(kk_function_t _fself, kk_box_t _b_x127, kk_context_t* _ctx) {
  struct kk_std_os_dir_list_directory_recursive_fun373__t* _self = kk_function_as(struct kk_std_os_dir_list_directory_recursive_fun373__t*, _fself, _ctx);
  kk_std_core_types__list x_4_10351 = _self->x_4_10351; /* list<std/os/path/path> */
  kk_drop_match(_self, {kk_std_core_types__list_dup(x_4_10351, _ctx);}, {}, _ctx)
  kk_std_core_types__list _y_x10218_1_133 = kk_std_core_types__list_unbox(_b_x127, KK_OWNED, _ctx); /*list<std/os/path/path>*/;
  kk_std_core_types__list _x_x374 = kk_std_os_dir__mlift_list_directory_recursive_10298(x_4_10351, _y_x10218_1_133, _ctx); /*list<std/os/path/path>*/
  return kk_std_core_types__list_box(_x_x374, _ctx);
}

kk_std_core_types__list kk_std_os_dir_list_directory_recursive(kk_std_os_path__path dir, kk_std_core_types__optional max_depth_3, kk_context_t* _ctx) { /* (dir : std/os/path/path, max-depth : ? int) -> <pure,fsys> list<std/os/path/path> */ 
  bool _match_x238;
  kk_integer_t _brw_x242;
  if (kk_std_core_types__is_Optional(max_depth_3, _ctx)) {
    kk_box_t _box_x121 = max_depth_3._cons._Optional.value;
    kk_integer_t _uniq_max_depth_509 = kk_integer_unbox(_box_x121, _ctx);
    kk_integer_dup(_uniq_max_depth_509, _ctx);
    _brw_x242 = _uniq_max_depth_509; /*int*/
  }
  else {
    _brw_x242 = kk_integer_from_small(1000); /*int*/
  }
  bool _brw_x243 = kk_integer_lt_borrow(_brw_x242,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x242, _ctx);
  _match_x238 = _brw_x243; /*bool*/
  if (_match_x238) {
    kk_std_core_types__optional_drop(max_depth_3, _ctx);
    kk_std_os_path__path_drop(dir, _ctx);
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    kk_std_core_types__list x_4_10351 = kk_std_os_dir_list_directory(dir, _ctx); /*list<std/os/path/path>*/;
    if (kk_yielding(kk_context())) {
      kk_std_core_types__list_drop(x_4_10351, _ctx);
      kk_box_t _x_x365 = kk_std_core_hnd_yield_extend(kk_std_os_dir_new_list_directory_recursive_fun366(max_depth_3, _ctx), _ctx); /*2419*/
      return kk_std_core_types__list_unbox(_x_x365, KK_OWNED, _ctx);
    }
    {
      kk_std_core_types__list x_5_10354;
      kk_std_core_types__list _x_x368 = kk_std_core_types__list_dup(x_4_10351, _ctx); /*list<std/os/path/path>*/
      x_5_10354 = kk_std_os_dir__lift_list_directory_recursive_10175(_x_x368, _ctx); /*list<std/os/path/path>*/
      if (kk_yielding(kk_context())) {
        kk_std_core_types__list_drop(x_5_10354, _ctx);
        kk_box_t _x_x369 = kk_std_core_hnd_yield_extend(kk_std_os_dir_new_list_directory_recursive_fun370(max_depth_3, x_4_10351, _ctx), _ctx); /*2419*/
        return kk_std_core_types__list_unbox(_x_x369, KK_OWNED, _ctx);
      }
      {
        kk_std_core_types__list x_6_10357 = kk_std_os_dir__lift_list_directory_recursive_10176(max_depth_3, x_5_10354, _ctx); /*list<std/os/path/path>*/;
        if (kk_yielding(kk_context())) {
          kk_std_core_types__list_drop(x_6_10357, _ctx);
          kk_box_t _x_x372 = kk_std_core_hnd_yield_extend(kk_std_os_dir_new_list_directory_recursive_fun373(x_4_10351, _ctx), _ctx); /*2419*/
          return kk_std_core_types__list_unbox(_x_x372, KK_OWNED, _ctx);
        }
        {
          kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<div,exn,fsys>>*/;
          kk_std_core_types__list x_7;
          if (kk_std_core_types__is_Nil(x_4_10351, _ctx)) {
            x_7 = x_6_10357; /*list<std/os/path/path>*/
          }
          else {
            x_7 = kk_std_core_list__unroll_append_10004(x_4_10351, x_6_10357, _ctx); /*list<std/os/path/path>*/
          }
          kk_unit_t keep_0 = kk_Unit;
          kk_evv_set(w_0,kk_context());
          return x_7;
        }
      }
    }
  }
}
 
// lifted local: copy-directory, @spec-x10144
// specialized: std/core/list/partition, on parameters @uniq-pred@10139, using:
// @uniq-pred@10139 = std/core/types/@open<(fsys :: X),<(fsys :: X),(div :: X),(exn :: (E, V) -> V)>,(dir : std/os/path/path) -> (fsys :: X) bool,(dir : std/os/path/path) -> <(fsys :: X),(div :: X),(exn :: (E, V) -> V)> bool>(std/os/dir/is-directory)


// lift anonymous function
struct kk_std_os_dir__lift_copy_directory_10178_fun377__t {
  struct kk_function_s _base;
};
static bool kk_std_os_dir__lift_copy_directory_10178_fun377(kk_function_t _fself, kk_box_t _b_x147, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir__new_lift_copy_directory_10178_fun377(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir__lift_copy_directory_10178_fun377, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_os_dir__lift_copy_directory_10178_fun379__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_dir__lift_copy_directory_10178_fun379(kk_function_t _fself, kk_box_t _b_x142, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir__new_lift_copy_directory_10178_fun379(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_dir__lift_copy_directory_10178_fun379, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_dir__lift_copy_directory_10178_fun379(kk_function_t _fself, kk_box_t _b_x142, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  bool _x_x380;
  kk_std_os_path__path _x_x381 = kk_std_os_path__path_unbox(_b_x142, KK_OWNED, _ctx); /*std/os/path/path*/
  _x_x380 = kk_std_os_dir_is_directory(_x_x381, _ctx); /*bool*/
  return kk_bool_box(_x_x380);
}
static bool kk_std_os_dir__lift_copy_directory_10178_fun377(kk_function_t _fself, kk_box_t _b_x147, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_box_t _x_x378 = kk_std_core_hnd__open_none1(kk_std_os_dir__new_lift_copy_directory_10178_fun379(_ctx), _b_x147, _ctx); /*9924*/
  return kk_bool_unbox(_x_x378);
}

kk_std_core_types__tuple2 kk_std_os_dir__lift_copy_directory_10178(kk_std_core_types__list _uniq_xs_10138, kk_context_t* _ctx) { /* (list<std/os/path/path>) -> <fsys,div,exn> (list<std/os/path/path>, list<std/os/path/path>) */ 
  kk_std_core_types__cctx _uniq_acc1_10095_10140 = kk_cctx_empty(kk_context()); /*ctx<list<std/os/path/path>>*/;
  kk_std_core_types__cctx _uniq_acc2_10096_10141 = kk_cctx_empty(kk_context()); /*ctx<list<std/os/path/path>>*/;
  if (kk_std_core_types__is_Nil(_uniq_xs_10138, _ctx)) {
    kk_std_core_types__list _b_x138_148;
    kk_box_t _x_x375 = kk_cctx_apply(_uniq_acc1_10095_10140,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*382*/
    _b_x138_148 = kk_std_core_types__list_unbox(_x_x375, KK_OWNED, _ctx); /*list<std/os/path/path>*/
    kk_std_core_types__list _b_x139_149;
    kk_box_t _x_x376 = kk_cctx_apply(_uniq_acc2_10096_10141,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*382*/
    _b_x139_149 = kk_std_core_types__list_unbox(_x_x376, KK_OWNED, _ctx); /*list<std/os/path/path>*/
    return kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(_b_x138_148, _ctx), kk_std_core_types__list_box(_b_x139_149, _ctx), _ctx);
  }
  {
    kk_function_t _brw_x236 = kk_std_os_dir__new_lift_copy_directory_10178_fun377(_ctx); /*(2984) -> 2985 bool*/;
    kk_std_core_types__tuple2 _brw_x237 = kk_std_core_list__unroll_partition_acc_10015(_uniq_xs_10138, _brw_x236, _uniq_acc1_10095_10140, _uniq_acc2_10096_10141, _ctx); /*(list<2984>, list<2984>)*/;
    kk_function_drop(_brw_x236, _ctx);
    return _brw_x237;
  }
}
 
// monadic lift

kk_unit_t kk_std_os_dir__mlift_lift_copy_directory_10180_10301(kk_std_core_types__list _uniq_xx_10154, kk_std_os_path__path to, kk_unit_t _uniq_x___10155, kk_context_t* _ctx) { /* (list<std/os/path/path>, to : std/os/path/path, ()) -> <exn,fsys> () */ 
  kk_std_os_dir__lift_copy_directory_10180(to, _uniq_xx_10154, _ctx); return kk_Unit;
}
 
// lifted local: @lift-copy-directory@10179, copy-directory, @spec-x10157
// specialized: std/core/list/@unroll-foreach@10017, on parameters @uniq-action@10151, using:
// @uniq-action@10151 = fn<<(exn :: (E, V) -> V),(fsys :: X),(div :: X)>>(f: std/os/path/path){
//   std/os/dir/copy-file(f, (std/core/types/@open<(total :: E),<(exn :: (E, V) -> V),(fsys :: X),(div :: X)>,(p1 : std/os/path/path, p2 : std/os/path/path) -> std/os/path/path,(p1 : std/os/path/path, p2 : std/os/path/path) -> <(exn :: (E, V) -> V),(fsys :: X),(div :: X)> std/os/path/path>((fn(p1: std/os/path/path, p2: std/os/path/path){
//       val parts@0@10093 : ((list :: V -> V)<string>);
//       val parts@10091 : ? ((list :: V -> V)<string>);
//       (std/os/path/Path((match (p1) {
//           ((@skip std/os/path/Path((@x: string) : string, (@pat@0@0: (list :: V -> V)<string>) : (list :: V -> V)<string>) : std/os/path/path ) as @pat@3: std/os/path/path)
//              -> @x;
//         }), (match (parts@10091) {
//           ((std/core/types/@Optional((@uniq-parts@95: (list :: V -> V)<string>) : (list :: V -> V)<string>) : ? ((list :: V -> V)<string>) ) as @pat@1: ? ((list :: V -> V)<string>))
//              -> @uniq-parts@95;
//           ((@skip std/core/types/@None() : ? ((list :: V -> V)<string>) ) as @pat@2: ? ((list :: V -> V)<string>))
//              -> std/core/types/Nil<string>;
//         })));
//     }))(to, (std/core/types/@open<(total :: E),<(exn :: (E, V) -> V),(fsys :: X),(div :: X)>,(p : std/os/path/path) -> std/os/path/path,(p : std/os/path/path) -> <(exn :: (E, V) -> V),(fsys :: X),(div :: X)> std/os/path/path>((fn(p: std/os/path/path){
//         val parts@10122 : ? ((list :: V -> V)<string>)
//               = (std/core/types/@Optional<(list :: V -> V)<string>>((std/core/list/take<string>((match (p) {
//                   ((@skip std/os/path/Path((@pat@0@3@1: string) : string, (@x@1@1: (list :: V -> V)<string>) : (list :: V -> V)<string>) : std/os/path/path ) as @pat@5@0: std/os/path/path)
//                      -> @x@1@1;
//                 }), 1))));
//         (std/os/path/Path("", (match (parts@10122) {
//             ((std/core/types/@Optional((@uniq-parts@136: (list :: V -> V)<string>) : (list :: V -> V)<string>) : ? ((list :: V -> V)<string>) ) as @pat@1@0: ? ((list :: V -> V)<string>))
//                -> @uniq-parts@136;
//             ((@skip std/core/types/@None() : ? ((list :: V -> V)<string>) ) as @pat@2@0: ? ((list :: V -> V)<string>))
//                -> (match (p) {
//                 ((@skip std/os/path/Path((@pat@0@1@0: string) : string, (@x@0@1: (list :: V -> V)<string>) : (list :: V -> V)<string>) : std/os/path/path ) as @pat@3@0: std/os/path/path)
//                    -> @x@0@1;
//               });
//           })));
//       }))(f)))), (std/core/types/@None<bool>));
// }


// lift anonymous function
struct kk_std_os_dir__lift_copy_directory_10180_fun393__t {
  struct kk_function_s _base;
  kk_std_core_types__list _uniq_xx_10154_0;
  kk_std_os_path__path to_0;
};
static kk_box_t kk_std_os_dir__lift_copy_directory_10180_fun393(kk_function_t _fself, kk_box_t _b_x169, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir__new_lift_copy_directory_10180_fun393(kk_std_core_types__list _uniq_xx_10154_0, kk_std_os_path__path to_0, kk_context_t* _ctx) {
  struct kk_std_os_dir__lift_copy_directory_10180_fun393__t* _self = kk_function_alloc_as(struct kk_std_os_dir__lift_copy_directory_10180_fun393__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_os_dir__lift_copy_directory_10180_fun393, kk_context());
  _self->_uniq_xx_10154_0 = _uniq_xx_10154_0;
  _self->to_0 = to_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_os_dir__lift_copy_directory_10180_fun393(kk_function_t _fself, kk_box_t _b_x169, kk_context_t* _ctx) {
  struct kk_std_os_dir__lift_copy_directory_10180_fun393__t* _self = kk_function_as(struct kk_std_os_dir__lift_copy_directory_10180_fun393__t*, _fself, _ctx);
  kk_std_core_types__list _uniq_xx_10154_0 = _self->_uniq_xx_10154_0; /* list<std/os/path/path> */
  kk_std_os_path__path to_0 = _self->to_0; /* std/os/path/path */
  kk_drop_match(_self, {kk_std_core_types__list_dup(_uniq_xx_10154_0, _ctx);kk_std_os_path__path_dup(to_0, _ctx);}, {}, _ctx)
  kk_unit_t _uniq_x___10155_0_171 = kk_Unit;
  kk_unit_unbox(_b_x169);
  kk_unit_t _x_x394 = kk_Unit;
  kk_std_os_dir__mlift_lift_copy_directory_10180_10301(_uniq_xx_10154_0, to_0, _uniq_x___10155_0_171, _ctx);
  return kk_unit_box(_x_x394);
}

kk_unit_t kk_std_os_dir__lift_copy_directory_10180(kk_std_os_path__path to_0, kk_std_core_types__list _uniq_xs_10150, kk_context_t* _ctx) { /* (to : std/os/path/path, list<std/os/path/path>) -> <exn,fsys,div> () */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_xs_10150, _ctx)) {
    struct kk_std_core_types_Cons* _con_x382 = kk_std_core_types__as_Cons(_uniq_xs_10150, _ctx);
    kk_box_t _box_x161 = _con_x382->head;
    kk_std_core_types__list _uniq_xx_10154_0 = _con_x382->tail;
    kk_std_os_path__path _uniq_x_10153 = kk_std_os_path__path_unbox(_box_x161, KK_BORROWED, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10150, _ctx)) {
      kk_std_os_path__path_dup(_uniq_x_10153, _ctx);
      kk_box_drop(_box_x161, _ctx);
      kk_datatype_ptr_free(_uniq_xs_10150, _ctx);
    }
    else {
      kk_std_os_path__path_dup(_uniq_x_10153, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10154_0, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10150, _ctx);
    }
    kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<exn,fsys,div>>*/;
    kk_std_core_types__list _b_x162_163;
    kk_std_core_types__list _x_x383;
    {
      kk_std_core_types__list _x_1_1 = _uniq_x_10153.parts;
      kk_std_core_types__list_dup(_x_1_1, _ctx);
      _x_x383 = _x_1_1; /*list<string>*/
    }
    _b_x162_163 = kk_std_core_list_take(_x_x383, kk_integer_from_small(1), _ctx); /*list<string>*/
    kk_unit_t keep = kk_Unit;
    kk_evv_set(w,kk_context());
    kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<exn,fsys,div>>*/;
    kk_std_os_path__path p2;
    kk_string_t _x_x384 = kk_string_empty(); /*string*/
    kk_std_core_types__list _x_x386;
    kk_std_core_types__optional _match_x235 = kk_std_core_types__new_Optional(kk_std_core_types__list_box(_b_x162_163, _ctx), _ctx); /*? 7*/;
    if (kk_std_core_types__is_Optional(_match_x235, _ctx)) {
      kk_box_t _box_x164 = _match_x235._cons._Optional.value;
      kk_std_core_types__list _uniq_parts_136 = kk_std_core_types__list_unbox(_box_x164, KK_BORROWED, _ctx);
      kk_std_core_types__list_dup(_uniq_parts_136, _ctx);
      kk_std_core_types__optional_drop(_match_x235, _ctx);
      _x_x386 = _uniq_parts_136; /*list<string>*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x235, _ctx);
      {
        kk_std_core_types__list _x_0_1 = _uniq_x_10153.parts;
        kk_std_core_types__list_dup(_x_0_1, _ctx);
        _x_x386 = _x_0_1; /*list<string>*/
      }
    }
    p2 = kk_std_os_path__new_Path(_x_x384, _x_x386, _ctx); /*std/os/path/path*/
    kk_std_core_types__list parts_0_10093;
    {
      kk_std_core_types__list _x_0 = p2.parts;
      kk_std_core_types__list_dup(_x_0, _ctx);
      if (kk_std_core_types__is_Nil(_x_0, _ctx)) {
        kk_std_os_path__path_drop(p2, _ctx);
        parts_0_10093 = kk_std_core_types__new_Nil(_ctx); /*list<string>*/
      }
      else {
        kk_std_core_types__list_drop(_x_0, _ctx);
        kk_std_core_types__list _x_x387;
        {
          kk_std_core_types__list _x_0_0 = p2.parts;
          kk_std_core_types__list_dup(_x_0_0, _ctx);
          kk_std_os_path__path_drop(p2, _ctx);
          _x_x387 = _x_0_0; /*list<string>*/
        }
        parts_0_10093 = kk_std_core_list__unroll_reverse_acc_10003(kk_std_core_types__new_Nil(_ctx), _x_x387, _ctx); /*list<string>*/
      }
    }
    kk_std_core_types__list _b_x165_166;
    if (kk_std_core_types__is_Nil(parts_0_10093, _ctx)) {
      kk_std_core_types__list _x_1 = to_0.parts;
      kk_std_core_types__list_dup(_x_1, _ctx);
      _b_x165_166 = _x_1; /*list<string>*/
    }
    else {
      kk_std_core_types__list _x_x388;
      {
        kk_std_core_types__list _x_1_0 = to_0.parts;
        kk_std_core_types__list_dup(_x_1_0, _ctx);
        _x_x388 = _x_1_0; /*list<string>*/
      }
      _b_x165_166 = kk_std_os_path__unroll_push_parts_10000(parts_0_10093, _x_x388, _ctx); /*list<string>*/
    }
    kk_unit_t keep_0 = kk_Unit;
    kk_evv_set(w_0,kk_context());
    kk_unit_t x_0_10365 = kk_Unit;
    kk_std_os_path__path _x_x389;
    kk_string_t _x_x390;
    {
      kk_string_t _x = to_0.root;
      kk_string_dup(_x, _ctx);
      _x_x390 = _x; /*string*/
    }
    kk_std_core_types__list _x_x391;
    kk_std_core_types__optional _match_x234 = kk_std_core_types__new_Optional(kk_std_core_types__list_box(_b_x165_166, _ctx), _ctx); /*? 7*/;
    if (kk_std_core_types__is_Optional(_match_x234, _ctx)) {
      kk_box_t _box_x167 = _match_x234._cons._Optional.value;
      kk_std_core_types__list _uniq_parts_95 = kk_std_core_types__list_unbox(_box_x167, KK_BORROWED, _ctx);
      kk_std_core_types__list_dup(_uniq_parts_95, _ctx);
      kk_std_core_types__optional_drop(_match_x234, _ctx);
      _x_x391 = _uniq_parts_95; /*list<string>*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x234, _ctx);
      _x_x391 = kk_std_core_types__new_Nil(_ctx); /*list<string>*/
    }
    _x_x389 = kk_std_os_path__new_Path(_x_x390, _x_x391, _ctx); /*std/os/path/path*/
    kk_std_os_dir_copy_file(_uniq_x_10153, _x_x389, kk_std_core_types__new_None(_ctx), _ctx);
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x392 = kk_std_core_hnd_yield_extend(kk_std_os_dir__new_lift_copy_directory_10180_fun393(_uniq_xx_10154_0, to_0, _ctx), _ctx); /*2419*/
      kk_unit_unbox(_x_x392); return kk_Unit;
    }
    { // tailcall
      _uniq_xs_10150 = _uniq_xx_10154_0;
      goto kk__tailcall;
    }
  }
  {
    kk_std_os_path__path_drop(to_0, _ctx);
    kk_Unit; return kk_Unit;
  }
}
 
// lifted local: copy-directory, @spec-x10149
// specialized: std/core/list/foreach, on parameters @uniq-action@10146, using:
// @uniq-action@10146 = fn<<(exn :: (E, V) -> V),(fsys :: X),(div :: X)>>(f: std/os/path/path){
//   std/os/dir/copy-file(f, (std/core/types/@open<(total :: E),<(exn :: (E, V) -> V),(fsys :: X),(div :: X)>,(p1 : std/os/path/path, p2 : std/os/path/path) -> std/os/path/path,(p1 : std/os/path/path, p2 : std/os/path/path) -> <(exn :: (E, V) -> V),(fsys :: X),(div :: X)> std/os/path/path>((fn(p1: std/os/path/path, p2: std/os/path/path){
//       val parts@0@10093 : ((list :: V -> V)<string>);
//       val parts@10091 : ? ((list :: V -> V)<string>);
//       (std/os/path/Path((match (p1) {
//           ((@skip std/os/path/Path((@x: string) : string, (@pat@0@0: (list :: V -> V)<string>) : (list :: V -> V)<string>) : std/os/path/path ) as @pat@3: std/os/path/path)
//              -> @x;
//         }), (match (parts@10091) {
//           ((std/core/types/@Optional((@uniq-parts@95: (list :: V -> V)<string>) : (list :: V -> V)<string>) : ? ((list :: V -> V)<string>) ) as @pat@1: ? ((list :: V -> V)<string>))
//              -> @uniq-parts@95;
//           ((@skip std/core/types/@None() : ? ((list :: V -> V)<string>) ) as @pat@2: ? ((list :: V -> V)<string>))
//              -> std/core/types/Nil<string>;
//         })));
//     }))(to, (std/core/types/@open<(total :: E),<(exn :: (E, V) -> V),(fsys :: X),(div :: X)>,(p : std/os/path/path) -> std/os/path/path,(p : std/os/path/path) -> <(exn :: (E, V) -> V),(fsys :: X),(div :: X)> std/os/path/path>((fn(p: std/os/path/path){
//         val parts@10122 : ? ((list :: V -> V)<string>)
//               = (std/core/types/@Optional<(list :: V -> V)<string>>((std/core/list/take<string>((match (p) {
//                   ((@skip std/os/path/Path((@pat@0@3@1: string) : string, (@x@1@1: (list :: V -> V)<string>) : (list :: V -> V)<string>) : std/os/path/path ) as @pat@5@0: std/os/path/path)
//                      -> @x@1@1;
//                 }), 1))));
//         (std/os/path/Path("", (match (parts@10122) {
//             ((std/core/types/@Optional((@uniq-parts@136: (list :: V -> V)<string>) : (list :: V -> V)<string>) : ? ((list :: V -> V)<string>) ) as @pat@1@0: ? ((list :: V -> V)<string>))
//                -> @uniq-parts@136;
//             ((@skip std/core/types/@None() : ? ((list :: V -> V)<string>) ) as @pat@2@0: ? ((list :: V -> V)<string>))
//                -> (match (p) {
//                 ((@skip std/os/path/Path((@pat@0@1@0: string) : string, (@x@0@1: (list :: V -> V)<string>) : (list :: V -> V)<string>) : std/os/path/path ) as @pat@3@0: std/os/path/path)
//                    -> @x@0@1;
//               });
//           })));
//       }))(f)))), (std/core/types/@None<bool>));
// }

kk_unit_t kk_std_os_dir__lift_copy_directory_10179(kk_std_os_path__path to, kk_std_core_types__list _uniq_xs_10145, kk_context_t* _ctx) { /* (to : std/os/path/path, list<std/os/path/path>) -> <exn,fsys,div> () */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10145, _ctx)) {
    kk_std_os_path__path_drop(to, _ctx);
    kk_Unit; return kk_Unit;
  }
  {
    kk_std_os_dir__lift_copy_directory_10180(to, _uniq_xs_10145, _ctx); return kk_Unit;
  }
}
 
// lifted local: copy-directory, @spec-x10163
// specialized: std/core/list/foreach, on parameters @uniq-action@10160, using:
// @uniq-action@10160 = fn<<(div :: X),(exn :: (E, V) -> V),(fsys :: X)>>(d: std/os/path/path){
//   std/os/dir/copy-directory(d, (std/core/types/@open<(total :: E),<(div :: X),(exn :: (E, V) -> V),(fsys :: X)>,(p1 : std/os/path/path, p2 : std/os/path/path) -> std/os/path/path,(p1 : std/os/path/path, p2 : std/os/path/path) -> <(div :: X),(exn :: (E, V) -> V),(fsys :: X)> std/os/path/path>((fn(p1@0: std/os/path/path, p2@0: std/os/path/path){
//       val parts@0@10093@0 : ((list :: V -> V)<string>);
//       val parts@10091@0 : ? ((list :: V -> V)<string>);
//       (std/os/path/Path((match (p1@0) {
//           ((@skip std/os/path/Path((@x@2: string) : string, (@pat@0@0@0: (list :: V -> V)<string>) : (list :: V -> V)<string>) : std/os/path/path ) as @pat@3@1: std/os/path/path)
//              -> @x@2;
//         }), (match (parts@10091@0) {
//           ((std/core/types/@Optional((@uniq-parts@95@0: (list :: V -> V)<string>) : (list :: V -> V)<string>) : ? ((list :: V -> V)<string>) ) as @pat@1@1: ? ((list :: V -> V)<string>))
//              -> @uniq-parts@95@0;
//           ((@skip std/core/types/@None() : ? ((list :: V -> V)<string>) ) as @pat@2@1: ? ((list :: V -> V)<string>))
//              -> std/core/types/Nil<string>;
//         })));
//     }))(to, (std/core/types/@open<(total :: E),<(div :: X),(exn :: (E, V) -> V),(fsys :: X)>,(p : std/os/path/path) -> std/os/path/path,(p : std/os/path/path) -> <(div :: X),(exn :: (E, V) -> V),(fsys :: X)> std/os/path/path>((fn(p@0: std/os/path/path){
//         val parts@10122@0 : ? ((list :: V -> V)<string>)
//               = (std/core/types/@Optional<(list :: V -> V)<string>>((std/core/list/take<string>((match (p@0) {
//                   ((@skip std/os/path/Path((@pat@0@3@3: string) : string, (@x@1@3: (list :: V -> V)<string>) : (list :: V -> V)<string>) : std/os/path/path ) as @pat@5@2: std/os/path/path)
//                      -> @x@1@3;
//                 }), 1))));
//         (std/os/path/Path("", (match (parts@10122@0) {
//             ((std/core/types/@Optional((@uniq-parts@136@0: (list :: V -> V)<string>) : (list :: V -> V)<string>) : ? ((list :: V -> V)<string>) ) as @pat@1@0@0: ? ((list :: V -> V)<string>))
//                -> @uniq-parts@136@0;
//             ((@skip std/core/types/@None() : ? ((list :: V -> V)<string>) ) as @pat@2@2: ? ((list :: V -> V)<string>))
//                -> (match (p@0) {
//                 ((@skip std/os/path/Path((@pat@0@1@2: string) : string, (@x@0@3: (list :: V -> V)<string>) : (list :: V -> V)<string>) : std/os/path/path ) as @pat@3@2: std/os/path/path)
//                    -> @x@0@3;
//               });
//           })));
//       }))(d)))));
// }

kk_unit_t kk_std_os_dir__lift_copy_directory_10181(kk_std_os_path__path to, kk_std_core_types__list _uniq_xs_10159, kk_context_t* _ctx) { /* (to : std/os/path/path, list<std/os/path/path>) -> <div,exn,fsys> () */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10159, _ctx)) {
    kk_std_os_path__path_drop(to, _ctx);
    kk_Unit; return kk_Unit;
  }
  {
    kk_std_os_dir__lift_copy_directory_10182(to, _uniq_xs_10159, _ctx); return kk_Unit;
  }
}
 
// monadic lift

kk_unit_t kk_std_os_dir__mlift_lift_copy_directory_10182_10302(kk_std_core_types__list _uniq_xx_10168, kk_std_os_path__path to, kk_unit_t _uniq_x___10169, kk_context_t* _ctx) { /* (list<std/os/path/path>, to : std/os/path/path, ()) -> <pure,fsys> () */ 
  kk_std_os_dir__lift_copy_directory_10182(to, _uniq_xx_10168, _ctx); return kk_Unit;
}
 
// monadic lift

kk_unit_t kk_std_os_dir__mlift_copy_directory_10303(kk_std_core_types__list dirs, kk_std_os_path__path to_0, kk_unit_t wild___0, kk_context_t* _ctx) { /* (dirs : list<std/os/path/path>, to : std/os/path/path, wild_@0 : ()) -> <exn,fsys,div> () */ 
  kk_std_os_dir__lift_copy_directory_10181(to_0, dirs, _ctx); return kk_Unit;
}
 
// monadic lift


// lift anonymous function
struct kk_std_os_dir__mlift_copy_directory_10304_fun397__t {
  struct kk_function_s _base;
  kk_std_core_types__list dirs_0;
  kk_std_os_path__path to_1;
};
static kk_box_t kk_std_os_dir__mlift_copy_directory_10304_fun397(kk_function_t _fself, kk_box_t _b_x175, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir__new_mlift_copy_directory_10304_fun397(kk_std_core_types__list dirs_0, kk_std_os_path__path to_1, kk_context_t* _ctx) {
  struct kk_std_os_dir__mlift_copy_directory_10304_fun397__t* _self = kk_function_alloc_as(struct kk_std_os_dir__mlift_copy_directory_10304_fun397__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_os_dir__mlift_copy_directory_10304_fun397, kk_context());
  _self->dirs_0 = dirs_0;
  _self->to_1 = to_1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_os_dir__mlift_copy_directory_10304_fun397(kk_function_t _fself, kk_box_t _b_x175, kk_context_t* _ctx) {
  struct kk_std_os_dir__mlift_copy_directory_10304_fun397__t* _self = kk_function_as(struct kk_std_os_dir__mlift_copy_directory_10304_fun397__t*, _fself, _ctx);
  kk_std_core_types__list dirs_0 = _self->dirs_0; /* list<std/os/path/path> */
  kk_std_os_path__path to_1 = _self->to_1; /* std/os/path/path */
  kk_drop_match(_self, {kk_std_core_types__list_dup(dirs_0, _ctx);kk_std_os_path__path_dup(to_1, _ctx);}, {}, _ctx)
  kk_unit_t wild___0_0_177 = kk_Unit;
  kk_unit_unbox(_b_x175);
  kk_unit_t _x_x398 = kk_Unit;
  kk_std_os_dir__mlift_copy_directory_10303(dirs_0, to_1, wild___0_0_177, _ctx);
  return kk_unit_box(_x_x398);
}

kk_unit_t kk_std_os_dir__mlift_copy_directory_10304(kk_std_os_path__path to_1, kk_std_core_types__tuple2 _y_x10234, kk_context_t* _ctx) { /* (to : std/os/path/path, (list<std/os/path/path>, list<std/os/path/path>)) -> <fsys,div,exn> () */ 
  {
    kk_box_t _box_x172 = _y_x10234.fst;
    kk_box_t _box_x173 = _y_x10234.snd;
    kk_std_core_types__list dirs_0 = kk_std_core_types__list_unbox(_box_x172, KK_BORROWED, _ctx);
    kk_std_core_types__list files = kk_std_core_types__list_unbox(_box_x173, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(dirs_0, _ctx);
    kk_std_core_types__list_dup(files, _ctx);
    kk_std_core_types__tuple2_drop(_y_x10234, _ctx);
    kk_unit_t x_10371 = kk_Unit;
    kk_std_os_path__path _x_x395 = kk_std_os_path__path_dup(to_1, _ctx); /*std/os/path/path*/
    kk_std_os_dir__lift_copy_directory_10179(_x_x395, files, _ctx);
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x396 = kk_std_core_hnd_yield_extend(kk_std_os_dir__new_mlift_copy_directory_10304_fun397(dirs_0, to_1, _ctx), _ctx); /*2419*/
      kk_unit_unbox(_x_x396); return kk_Unit;
    }
    {
      kk_std_os_dir__mlift_copy_directory_10303(dirs_0, to_1, x_10371, _ctx); return kk_Unit;
    }
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_os_dir__mlift_copy_directory_10305_fun400__t {
  struct kk_function_s _base;
  kk_std_os_path__path to_2;
};
static kk_box_t kk_std_os_dir__mlift_copy_directory_10305_fun400(kk_function_t _fself, kk_box_t _b_x179, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir__new_mlift_copy_directory_10305_fun400(kk_std_os_path__path to_2, kk_context_t* _ctx) {
  struct kk_std_os_dir__mlift_copy_directory_10305_fun400__t* _self = kk_function_alloc_as(struct kk_std_os_dir__mlift_copy_directory_10305_fun400__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_os_dir__mlift_copy_directory_10305_fun400, kk_context());
  _self->to_2 = to_2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_os_dir__mlift_copy_directory_10305_fun400(kk_function_t _fself, kk_box_t _b_x179, kk_context_t* _ctx) {
  struct kk_std_os_dir__mlift_copy_directory_10305_fun400__t* _self = kk_function_as(struct kk_std_os_dir__mlift_copy_directory_10305_fun400__t*, _fself, _ctx);
  kk_std_os_path__path to_2 = _self->to_2; /* std/os/path/path */
  kk_drop_match(_self, {kk_std_os_path__path_dup(to_2, _ctx);}, {}, _ctx)
  kk_std_core_types__tuple2 _y_x10234_0_181 = kk_std_core_types__tuple2_unbox(_b_x179, KK_OWNED, _ctx); /*(list<std/os/path/path>, list<std/os/path/path>)*/;
  kk_unit_t _x_x401 = kk_Unit;
  kk_std_os_dir__mlift_copy_directory_10304(to_2, _y_x10234_0_181, _ctx);
  return kk_unit_box(_x_x401);
}

kk_unit_t kk_std_os_dir__mlift_copy_directory_10305(kk_std_os_path__path to_2, kk_std_core_types__list all, kk_context_t* _ctx) { /* (to : std/os/path/path, all : list<std/os/path/path>) -> <exn,fsys> () */ 
  kk_std_core_types__tuple2 x_0_10373 = kk_std_os_dir__lift_copy_directory_10178(all, _ctx); /*(list<std/os/path/path>, list<std/os/path/path>)*/;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__tuple2_drop(x_0_10373, _ctx);
    kk_box_t _x_x399 = kk_std_core_hnd_yield_extend(kk_std_os_dir__new_mlift_copy_directory_10305_fun400(to_2, _ctx), _ctx); /*2419*/
    kk_unit_unbox(_x_x399); return kk_Unit;
  }
  {
    kk_std_os_dir__mlift_copy_directory_10304(to_2, x_0_10373, _ctx); return kk_Unit;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_os_dir__mlift_copy_directory_10306_fun403__t {
  struct kk_function_s _base;
  kk_std_os_path__path to_3;
};
static kk_box_t kk_std_os_dir__mlift_copy_directory_10306_fun403(kk_function_t _fself, kk_box_t _b_x183, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir__new_mlift_copy_directory_10306_fun403(kk_std_os_path__path to_3, kk_context_t* _ctx) {
  struct kk_std_os_dir__mlift_copy_directory_10306_fun403__t* _self = kk_function_alloc_as(struct kk_std_os_dir__mlift_copy_directory_10306_fun403__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_os_dir__mlift_copy_directory_10306_fun403, kk_context());
  _self->to_3 = to_3;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_os_dir__mlift_copy_directory_10306_fun403(kk_function_t _fself, kk_box_t _b_x183, kk_context_t* _ctx) {
  struct kk_std_os_dir__mlift_copy_directory_10306_fun403__t* _self = kk_function_as(struct kk_std_os_dir__mlift_copy_directory_10306_fun403__t*, _fself, _ctx);
  kk_std_os_path__path to_3 = _self->to_3; /* std/os/path/path */
  kk_drop_match(_self, {kk_std_os_path__path_dup(to_3, _ctx);}, {}, _ctx)
  kk_std_core_types__list all_0_185 = kk_std_core_types__list_unbox(_b_x183, KK_OWNED, _ctx); /*list<std/os/path/path>*/;
  kk_unit_t _x_x404 = kk_Unit;
  kk_std_os_dir__mlift_copy_directory_10305(to_3, all_0_185, _ctx);
  return kk_unit_box(_x_x404);
}

kk_unit_t kk_std_os_dir__mlift_copy_directory_10306(kk_std_os_path__path dir, kk_std_os_path__path to_3, kk_unit_t wild__, kk_context_t* _ctx) { /* (dir : std/os/path/path, to : std/os/path/path, wild_ : ()) -> <exn,fsys> () */ 
  kk_std_core_types__list x_1_10375 = kk_std_os_dir_list_directory(dir, _ctx); /*list<std/os/path/path>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_1_10375, _ctx);
    kk_box_t _x_x402 = kk_std_core_hnd_yield_extend(kk_std_os_dir__new_mlift_copy_directory_10306_fun403(to_3, _ctx), _ctx); /*2419*/
    kk_unit_unbox(_x_x402); return kk_Unit;
  }
  {
    kk_std_os_dir__mlift_copy_directory_10305(to_3, x_1_10375, _ctx); return kk_Unit;
  }
}
 
// lifted local: @lift-copy-directory@10181, copy-directory, @spec-x10171
// specialized: std/core/list/@unroll-foreach@10017, on parameters @uniq-action@10165, using:
// @uniq-action@10165 = fn<<(div :: X),(exn :: (E, V) -> V),(fsys :: X)>>(d: std/os/path/path){
//   std/os/dir/copy-directory(d, (std/core/types/@open<(total :: E),<(div :: X),(exn :: (E, V) -> V),(fsys :: X)>,(p1 : std/os/path/path, p2 : std/os/path/path) -> std/os/path/path,(p1 : std/os/path/path, p2 : std/os/path/path) -> <(div :: X),(exn :: (E, V) -> V),(fsys :: X)> std/os/path/path>((fn(p1@0: std/os/path/path, p2@0: std/os/path/path){
//       val parts@0@10093@0 : ((list :: V -> V)<string>);
//       val parts@10091@0 : ? ((list :: V -> V)<string>);
//       (std/os/path/Path((match (p1@0) {
//           ((@skip std/os/path/Path((@x@2: string) : string, (@pat@0@0@0: (list :: V -> V)<string>) : (list :: V -> V)<string>) : std/os/path/path ) as @pat@3@1: std/os/path/path)
//              -> @x@2;
//         }), (match (parts@10091@0) {
//           ((std/core/types/@Optional((@uniq-parts@95@0: (list :: V -> V)<string>) : (list :: V -> V)<string>) : ? ((list :: V -> V)<string>) ) as @pat@1@1: ? ((list :: V -> V)<string>))
//              -> @uniq-parts@95@0;
//           ((@skip std/core/types/@None() : ? ((list :: V -> V)<string>) ) as @pat@2@1: ? ((list :: V -> V)<string>))
//              -> std/core/types/Nil<string>;
//         })));
//     }))(to, (std/core/types/@open<(total :: E),<(div :: X),(exn :: (E, V) -> V),(fsys :: X)>,(p : std/os/path/path) -> std/os/path/path,(p : std/os/path/path) -> <(div :: X),(exn :: (E, V) -> V),(fsys :: X)> std/os/path/path>((fn(p@0: std/os/path/path){
//         val parts@10122@0 : ? ((list :: V -> V)<string>)
//               = (std/core/types/@Optional<(list :: V -> V)<string>>((std/core/list/take<string>((match (p@0) {
//                   ((@skip std/os/path/Path((@pat@0@3@3: string) : string, (@x@1@3: (list :: V -> V)<string>) : (list :: V -> V)<string>) : std/os/path/path ) as @pat@5@2: std/os/path/path)
//                      -> @x@1@3;
//                 }), 1))));
//         (std/os/path/Path("", (match (parts@10122@0) {
//             ((std/core/types/@Optional((@uniq-parts@136@0: (list :: V -> V)<string>) : (list :: V -> V)<string>) : ? ((list :: V -> V)<string>) ) as @pat@1@0@0: ? ((list :: V -> V)<string>))
//                -> @uniq-parts@136@0;
//             ((@skip std/core/types/@None() : ? ((list :: V -> V)<string>) ) as @pat@2@2: ? ((list :: V -> V)<string>))
//                -> (match (p@0) {
//                 ((@skip std/os/path/Path((@pat@0@1@2: string) : string, (@x@0@3: (list :: V -> V)<string>) : (list :: V -> V)<string>) : std/os/path/path ) as @pat@3@2: std/os/path/path)
//                    -> @x@0@3;
//               });
//           })));
//       }))(d)))));
// }


// lift anonymous function
struct kk_std_os_dir__lift_copy_directory_10182_fun416__t {
  struct kk_function_s _base;
  kk_std_core_types__list _uniq_xx_10168_0;
  kk_std_os_path__path to_4;
};
static kk_box_t kk_std_os_dir__lift_copy_directory_10182_fun416(kk_function_t _fself, kk_box_t _b_x194, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir__new_lift_copy_directory_10182_fun416(kk_std_core_types__list _uniq_xx_10168_0, kk_std_os_path__path to_4, kk_context_t* _ctx) {
  struct kk_std_os_dir__lift_copy_directory_10182_fun416__t* _self = kk_function_alloc_as(struct kk_std_os_dir__lift_copy_directory_10182_fun416__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_os_dir__lift_copy_directory_10182_fun416, kk_context());
  _self->_uniq_xx_10168_0 = _uniq_xx_10168_0;
  _self->to_4 = to_4;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_os_dir__lift_copy_directory_10182_fun416(kk_function_t _fself, kk_box_t _b_x194, kk_context_t* _ctx) {
  struct kk_std_os_dir__lift_copy_directory_10182_fun416__t* _self = kk_function_as(struct kk_std_os_dir__lift_copy_directory_10182_fun416__t*, _fself, _ctx);
  kk_std_core_types__list _uniq_xx_10168_0 = _self->_uniq_xx_10168_0; /* list<std/os/path/path> */
  kk_std_os_path__path to_4 = _self->to_4; /* std/os/path/path */
  kk_drop_match(_self, {kk_std_core_types__list_dup(_uniq_xx_10168_0, _ctx);kk_std_os_path__path_dup(to_4, _ctx);}, {}, _ctx)
  kk_unit_t _uniq_x___10169_0_196 = kk_Unit;
  kk_unit_unbox(_b_x194);
  kk_unit_t _x_x417 = kk_Unit;
  kk_std_os_dir__mlift_lift_copy_directory_10182_10302(_uniq_xx_10168_0, to_4, _uniq_x___10169_0_196, _ctx);
  return kk_unit_box(_x_x417);
}

kk_unit_t kk_std_os_dir__lift_copy_directory_10182(kk_std_os_path__path to_4, kk_std_core_types__list _uniq_xs_10164, kk_context_t* _ctx) { /* (to : std/os/path/path, list<std/os/path/path>) -> <div,exn,fsys> () */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_xs_10164, _ctx)) {
    struct kk_std_core_types_Cons* _con_x405 = kk_std_core_types__as_Cons(_uniq_xs_10164, _ctx);
    kk_box_t _box_x186 = _con_x405->head;
    kk_std_core_types__list _uniq_xx_10168_0 = _con_x405->tail;
    kk_std_os_path__path _uniq_x_10167 = kk_std_os_path__path_unbox(_box_x186, KK_BORROWED, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10164, _ctx)) {
      kk_std_os_path__path_dup(_uniq_x_10167, _ctx);
      kk_box_drop(_box_x186, _ctx);
      kk_datatype_ptr_free(_uniq_xs_10164, _ctx);
    }
    else {
      kk_std_os_path__path_dup(_uniq_x_10167, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10168_0, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10164, _ctx);
    }
    kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<div,exn,fsys>>*/;
    kk_std_core_types__list _b_x187_188;
    kk_std_core_types__list _x_x406;
    {
      kk_std_core_types__list _x_1_3 = _uniq_x_10167.parts;
      kk_std_core_types__list_dup(_x_1_3, _ctx);
      _x_x406 = _x_1_3; /*list<string>*/
    }
    _b_x187_188 = kk_std_core_list_take(_x_x406, kk_integer_from_small(1), _ctx); /*list<string>*/
    kk_unit_t keep = kk_Unit;
    kk_evv_set(w,kk_context());
    kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<div,exn,fsys>>*/;
    kk_std_os_path__path p2_0;
    kk_string_t _x_x407 = kk_string_empty(); /*string*/
    kk_std_core_types__list _x_x409;
    kk_std_core_types__optional _match_x229 = kk_std_core_types__new_Optional(kk_std_core_types__list_box(_b_x187_188, _ctx), _ctx); /*? 7*/;
    if (kk_std_core_types__is_Optional(_match_x229, _ctx)) {
      kk_box_t _box_x189 = _match_x229._cons._Optional.value;
      kk_std_core_types__list _uniq_parts_136_0 = kk_std_core_types__list_unbox(_box_x189, KK_BORROWED, _ctx);
      kk_std_core_types__list_dup(_uniq_parts_136_0, _ctx);
      kk_std_core_types__optional_drop(_match_x229, _ctx);
      _x_x409 = _uniq_parts_136_0; /*list<string>*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x229, _ctx);
      {
        kk_std_core_types__list _x_0_3 = _uniq_x_10167.parts;
        kk_std_core_types__list_dup(_x_0_3, _ctx);
        _x_x409 = _x_0_3; /*list<string>*/
      }
    }
    p2_0 = kk_std_os_path__new_Path(_x_x407, _x_x409, _ctx); /*std/os/path/path*/
    kk_std_core_types__list parts_0_10093_0;
    {
      kk_std_core_types__list _x_0_2 = p2_0.parts;
      kk_std_core_types__list_dup(_x_0_2, _ctx);
      if (kk_std_core_types__is_Nil(_x_0_2, _ctx)) {
        kk_std_os_path__path_drop(p2_0, _ctx);
        parts_0_10093_0 = kk_std_core_types__new_Nil(_ctx); /*list<string>*/
      }
      else {
        kk_std_core_types__list_drop(_x_0_2, _ctx);
        kk_std_core_types__list _x_x410;
        {
          kk_std_core_types__list _x_0_0_0 = p2_0.parts;
          kk_std_core_types__list_dup(_x_0_0_0, _ctx);
          kk_std_os_path__path_drop(p2_0, _ctx);
          _x_x410 = _x_0_0_0; /*list<string>*/
        }
        parts_0_10093_0 = kk_std_core_list__unroll_reverse_acc_10003(kk_std_core_types__new_Nil(_ctx), _x_x410, _ctx); /*list<string>*/
      }
    }
    kk_std_core_types__list _b_x190_191;
    if (kk_std_core_types__is_Nil(parts_0_10093_0, _ctx)) {
      kk_std_core_types__list _x_1_2 = to_4.parts;
      kk_std_core_types__list_dup(_x_1_2, _ctx);
      _b_x190_191 = _x_1_2; /*list<string>*/
    }
    else {
      kk_std_core_types__list _x_x411;
      {
        kk_std_core_types__list _x_1_0_0 = to_4.parts;
        kk_std_core_types__list_dup(_x_1_0_0, _ctx);
        _x_x411 = _x_1_0_0; /*list<string>*/
      }
      _b_x190_191 = kk_std_os_path__unroll_push_parts_10000(parts_0_10093_0, _x_x411, _ctx); /*list<string>*/
    }
    kk_unit_t keep_0 = kk_Unit;
    kk_evv_set(w_0,kk_context());
    kk_unit_t x_3_10379 = kk_Unit;
    kk_std_os_path__path _x_x412;
    kk_string_t _x_x413;
    {
      kk_string_t _x_2 = to_4.root;
      kk_string_dup(_x_2, _ctx);
      _x_x413 = _x_2; /*string*/
    }
    kk_std_core_types__list _x_x414;
    kk_std_core_types__optional _match_x228 = kk_std_core_types__new_Optional(kk_std_core_types__list_box(_b_x190_191, _ctx), _ctx); /*? 7*/;
    if (kk_std_core_types__is_Optional(_match_x228, _ctx)) {
      kk_box_t _box_x192 = _match_x228._cons._Optional.value;
      kk_std_core_types__list _uniq_parts_95_0 = kk_std_core_types__list_unbox(_box_x192, KK_BORROWED, _ctx);
      kk_std_core_types__list_dup(_uniq_parts_95_0, _ctx);
      kk_std_core_types__optional_drop(_match_x228, _ctx);
      _x_x414 = _uniq_parts_95_0; /*list<string>*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x228, _ctx);
      _x_x414 = kk_std_core_types__new_Nil(_ctx); /*list<string>*/
    }
    _x_x412 = kk_std_os_path__new_Path(_x_x413, _x_x414, _ctx); /*std/os/path/path*/
    kk_std_os_dir_copy_directory(_uniq_x_10167, _x_x412, _ctx);
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x415 = kk_std_core_hnd_yield_extend(kk_std_os_dir__new_lift_copy_directory_10182_fun416(_uniq_xx_10168_0, to_4, _ctx), _ctx); /*2419*/
      kk_unit_unbox(_x_x415); return kk_Unit;
    }
    { // tailcall
      _uniq_xs_10164 = _uniq_xx_10168_0;
      goto kk__tailcall;
    }
  }
  {
    kk_std_os_path__path_drop(to_4, _ctx);
    kk_Unit; return kk_Unit;
  }
}


// lift anonymous function
struct kk_std_os_dir_copy_directory_fun420__t {
  struct kk_function_s _base;
  kk_std_os_path__path dir_0;
  kk_std_os_path__path to_5;
};
static kk_box_t kk_std_os_dir_copy_directory_fun420(kk_function_t _fself, kk_box_t _b_x198, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_copy_directory_fun420(kk_std_os_path__path dir_0, kk_std_os_path__path to_5, kk_context_t* _ctx) {
  struct kk_std_os_dir_copy_directory_fun420__t* _self = kk_function_alloc_as(struct kk_std_os_dir_copy_directory_fun420__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_os_dir_copy_directory_fun420, kk_context());
  _self->dir_0 = dir_0;
  _self->to_5 = to_5;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_os_dir_copy_directory_fun420(kk_function_t _fself, kk_box_t _b_x198, kk_context_t* _ctx) {
  struct kk_std_os_dir_copy_directory_fun420__t* _self = kk_function_as(struct kk_std_os_dir_copy_directory_fun420__t*, _fself, _ctx);
  kk_std_os_path__path dir_0 = _self->dir_0; /* std/os/path/path */
  kk_std_os_path__path to_5 = _self->to_5; /* std/os/path/path */
  kk_drop_match(_self, {kk_std_os_path__path_dup(dir_0, _ctx);kk_std_os_path__path_dup(to_5, _ctx);}, {}, _ctx)
  kk_unit_t wild___1_211 = kk_Unit;
  kk_unit_unbox(_b_x198);
  kk_unit_t _x_x421 = kk_Unit;
  kk_std_os_dir__mlift_copy_directory_10306(dir_0, to_5, wild___1_211, _ctx);
  return kk_unit_box(_x_x421);
}


// lift anonymous function
struct kk_std_os_dir_copy_directory_fun423__t {
  struct kk_function_s _base;
  kk_std_os_path__path to_5;
};
static kk_box_t kk_std_os_dir_copy_directory_fun423(kk_function_t _fself, kk_box_t _b_x200, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_copy_directory_fun423(kk_std_os_path__path to_5, kk_context_t* _ctx) {
  struct kk_std_os_dir_copy_directory_fun423__t* _self = kk_function_alloc_as(struct kk_std_os_dir_copy_directory_fun423__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_os_dir_copy_directory_fun423, kk_context());
  _self->to_5 = to_5;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_os_dir_copy_directory_fun423(kk_function_t _fself, kk_box_t _b_x200, kk_context_t* _ctx) {
  struct kk_std_os_dir_copy_directory_fun423__t* _self = kk_function_as(struct kk_std_os_dir_copy_directory_fun423__t*, _fself, _ctx);
  kk_std_os_path__path to_5 = _self->to_5; /* std/os/path/path */
  kk_drop_match(_self, {kk_std_os_path__path_dup(to_5, _ctx);}, {}, _ctx)
  kk_std_core_types__list all_1_212 = kk_std_core_types__list_unbox(_b_x200, KK_OWNED, _ctx); /*list<std/os/path/path>*/;
  kk_unit_t _x_x424 = kk_Unit;
  kk_std_os_dir__mlift_copy_directory_10305(to_5, all_1_212, _ctx);
  return kk_unit_box(_x_x424);
}


// lift anonymous function
struct kk_std_os_dir_copy_directory_fun426__t {
  struct kk_function_s _base;
  kk_std_os_path__path to_5;
};
static kk_box_t kk_std_os_dir_copy_directory_fun426(kk_function_t _fself, kk_box_t _b_x202, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_copy_directory_fun426(kk_std_os_path__path to_5, kk_context_t* _ctx) {
  struct kk_std_os_dir_copy_directory_fun426__t* _self = kk_function_alloc_as(struct kk_std_os_dir_copy_directory_fun426__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_os_dir_copy_directory_fun426, kk_context());
  _self->to_5 = to_5;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_os_dir_copy_directory_fun426(kk_function_t _fself, kk_box_t _b_x202, kk_context_t* _ctx) {
  struct kk_std_os_dir_copy_directory_fun426__t* _self = kk_function_as(struct kk_std_os_dir_copy_directory_fun426__t*, _fself, _ctx);
  kk_std_os_path__path to_5 = _self->to_5; /* std/os/path/path */
  kk_drop_match(_self, {kk_std_os_path__path_dup(to_5, _ctx);}, {}, _ctx)
  kk_std_core_types__tuple2 _y_x10234_1_213 = kk_std_core_types__tuple2_unbox(_b_x202, KK_OWNED, _ctx); /*(list<std/os/path/path>, list<std/os/path/path>)*/;
  kk_unit_t _x_x427 = kk_Unit;
  kk_std_os_dir__mlift_copy_directory_10304(to_5, _y_x10234_1_213, _ctx);
  return kk_unit_box(_x_x427);
}


// lift anonymous function
struct kk_std_os_dir_copy_directory_fun430__t {
  struct kk_function_s _base;
  kk_std_core_types__list dirs_1;
  kk_std_os_path__path to_5;
};
static kk_box_t kk_std_os_dir_copy_directory_fun430(kk_function_t _fself, kk_box_t _b_x206, kk_context_t* _ctx);
static kk_function_t kk_std_os_dir_new_copy_directory_fun430(kk_std_core_types__list dirs_1, kk_std_os_path__path to_5, kk_context_t* _ctx) {
  struct kk_std_os_dir_copy_directory_fun430__t* _self = kk_function_alloc_as(struct kk_std_os_dir_copy_directory_fun430__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_std_os_dir_copy_directory_fun430, kk_context());
  _self->dirs_1 = dirs_1;
  _self->to_5 = to_5;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_std_os_dir_copy_directory_fun430(kk_function_t _fself, kk_box_t _b_x206, kk_context_t* _ctx) {
  struct kk_std_os_dir_copy_directory_fun430__t* _self = kk_function_as(struct kk_std_os_dir_copy_directory_fun430__t*, _fself, _ctx);
  kk_std_core_types__list dirs_1 = _self->dirs_1; /* list<std/os/path/path> */
  kk_std_os_path__path to_5 = _self->to_5; /* std/os/path/path */
  kk_drop_match(_self, {kk_std_core_types__list_dup(dirs_1, _ctx);kk_std_os_path__path_dup(to_5, _ctx);}, {}, _ctx)
  kk_unit_t wild___0_1_214 = kk_Unit;
  kk_unit_unbox(_b_x206);
  kk_unit_t _x_x431 = kk_Unit;
  kk_std_os_dir__mlift_copy_directory_10303(dirs_1, to_5, wild___0_1_214, _ctx);
  return kk_unit_box(_x_x431);
}

kk_unit_t kk_std_os_dir_copy_directory(kk_std_os_path__path dir_0, kk_std_os_path__path to_5, kk_context_t* _ctx) { /* (dir : std/os/path/path, to : std/os/path/path) -> <pure,fsys> () */ 
  kk_unit_t x_5_10385 = kk_Unit;
  kk_std_os_path__path _x_x418 = kk_std_os_path__path_dup(to_5, _ctx); /*std/os/path/path*/
  kk_std_os_dir_ensure_dir(_x_x418, _ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x419 = kk_std_core_hnd_yield_extend(kk_std_os_dir_new_copy_directory_fun420(dir_0, to_5, _ctx), _ctx); /*2419*/
    kk_unit_unbox(_x_x419); return kk_Unit;
  }
  {
    kk_std_core_types__list x_6_10388 = kk_std_os_dir_list_directory(dir_0, _ctx); /*list<std/os/path/path>*/;
    if (kk_yielding(kk_context())) {
      kk_std_core_types__list_drop(x_6_10388, _ctx);
      kk_box_t _x_x422 = kk_std_core_hnd_yield_extend(kk_std_os_dir_new_copy_directory_fun423(to_5, _ctx), _ctx); /*2419*/
      kk_unit_unbox(_x_x422); return kk_Unit;
    }
    {
      kk_std_core_types__tuple2 x_7_10391 = kk_std_os_dir__lift_copy_directory_10178(x_6_10388, _ctx); /*(list<std/os/path/path>, list<std/os/path/path>)*/;
      if (kk_yielding(kk_context())) {
        kk_std_core_types__tuple2_drop(x_7_10391, _ctx);
        kk_box_t _x_x425 = kk_std_core_hnd_yield_extend(kk_std_os_dir_new_copy_directory_fun426(to_5, _ctx), _ctx); /*2419*/
        kk_unit_unbox(_x_x425); return kk_Unit;
      }
      {
        kk_box_t _box_x203 = x_7_10391.fst;
        kk_box_t _box_x204 = x_7_10391.snd;
        kk_std_core_types__list dirs_1 = kk_std_core_types__list_unbox(_box_x203, KK_BORROWED, _ctx);
        kk_std_core_types__list files_0 = kk_std_core_types__list_unbox(_box_x204, KK_BORROWED, _ctx);
        kk_std_core_types__list_dup(dirs_1, _ctx);
        kk_std_core_types__list_dup(files_0, _ctx);
        kk_std_core_types__tuple2_drop(x_7_10391, _ctx);
        kk_unit_t x_8_10394 = kk_Unit;
        kk_std_os_path__path _x_x428 = kk_std_os_path__path_dup(to_5, _ctx); /*std/os/path/path*/
        kk_std_os_dir__lift_copy_directory_10179(_x_x428, files_0, _ctx);
        if (kk_yielding(kk_context())) {
          kk_box_t _x_x429 = kk_std_core_hnd_yield_extend(kk_std_os_dir_new_copy_directory_fun430(dirs_1, to_5, _ctx), _ctx); /*2419*/
          kk_unit_unbox(_x_x429); return kk_Unit;
        }
        {
          kk_std_os_dir__lift_copy_directory_10181(to_5, dirs_1, _ctx); return kk_Unit;
        }
      }
    }
  }
}
 
// Copy a file to a directory

kk_unit_t kk_std_os_dir_copy_file_to_dir(kk_std_os_path__path from, kk_std_os_path__path dir, kk_context_t* _ctx) { /* (from : std/os/path/path, dir : std/os/path/path) -> <exn,fsys> () */ 
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<exn,fsys>>*/;
  kk_std_core_types__list _b_x215_216;
  kk_std_core_types__list _x_x432;
  {
    kk_std_core_types__list _x_1_1 = from.parts;
    kk_std_core_types__list_dup(_x_1_1, _ctx);
    _x_x432 = _x_1_1; /*list<string>*/
  }
  _b_x215_216 = kk_std_core_list_take(_x_x432, kk_integer_from_small(1), _ctx); /*list<string>*/
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<exn,fsys>>*/;
  kk_std_os_path__path p2;
  kk_string_t _x_x433 = kk_string_empty(); /*string*/
  kk_std_core_types__list _x_x435;
  kk_std_core_types__optional _match_x222 = kk_std_core_types__new_Optional(kk_std_core_types__list_box(_b_x215_216, _ctx), _ctx); /*? 7*/;
  if (kk_std_core_types__is_Optional(_match_x222, _ctx)) {
    kk_box_t _box_x217 = _match_x222._cons._Optional.value;
    kk_std_core_types__list _uniq_parts_136 = kk_std_core_types__list_unbox(_box_x217, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(_uniq_parts_136, _ctx);
    kk_std_core_types__optional_drop(_match_x222, _ctx);
    _x_x435 = _uniq_parts_136; /*list<string>*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x222, _ctx);
    {
      kk_std_core_types__list _x_0_1 = from.parts;
      kk_std_core_types__list_dup(_x_0_1, _ctx);
      _x_x435 = _x_0_1; /*list<string>*/
    }
  }
  p2 = kk_std_os_path__new_Path(_x_x433, _x_x435, _ctx); /*std/os/path/path*/
  kk_std_core_types__list parts_0_10093;
  {
    kk_std_core_types__list _x_0 = p2.parts;
    kk_std_core_types__list_dup(_x_0, _ctx);
    if (kk_std_core_types__is_Nil(_x_0, _ctx)) {
      kk_std_os_path__path_drop(p2, _ctx);
      parts_0_10093 = kk_std_core_types__new_Nil(_ctx); /*list<string>*/
    }
    else {
      kk_std_core_types__list_drop(_x_0, _ctx);
      kk_std_core_types__list _x_x436;
      {
        kk_std_core_types__list _x_0_0 = p2.parts;
        kk_std_core_types__list_dup(_x_0_0, _ctx);
        kk_std_os_path__path_drop(p2, _ctx);
        _x_x436 = _x_0_0; /*list<string>*/
      }
      parts_0_10093 = kk_std_core_list__unroll_reverse_acc_10003(kk_std_core_types__new_Nil(_ctx), _x_x436, _ctx); /*list<string>*/
    }
  }
  kk_std_core_types__list _b_x218_219;
  if (kk_std_core_types__is_Nil(parts_0_10093, _ctx)) {
    kk_std_core_types__list _x_1 = dir.parts;
    kk_std_core_types__list_dup(_x_1, _ctx);
    _b_x218_219 = _x_1; /*list<string>*/
  }
  else {
    kk_std_core_types__list _x_x437;
    {
      kk_std_core_types__list _x_1_0 = dir.parts;
      kk_std_core_types__list_dup(_x_1_0, _ctx);
      _x_x437 = _x_1_0; /*list<string>*/
    }
    _b_x218_219 = kk_std_os_path__unroll_push_parts_10000(parts_0_10093, _x_x437, _ctx); /*list<string>*/
  }
  kk_unit_t keep_0 = kk_Unit;
  kk_evv_set(w_0,kk_context());
  kk_std_os_path__path _x_x438;
  kk_string_t _x_x439;
  {
    kk_string_t _x = dir.root;
    kk_string_dup(_x, _ctx);
    kk_std_os_path__path_drop(dir, _ctx);
    _x_x439 = _x; /*string*/
  }
  kk_std_core_types__list _x_x440;
  kk_std_core_types__optional _match_x221 = kk_std_core_types__new_Optional(kk_std_core_types__list_box(_b_x218_219, _ctx), _ctx); /*? 7*/;
  if (kk_std_core_types__is_Optional(_match_x221, _ctx)) {
    kk_box_t _box_x220 = _match_x221._cons._Optional.value;
    kk_std_core_types__list _uniq_parts_95 = kk_std_core_types__list_unbox(_box_x220, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(_uniq_parts_95, _ctx);
    kk_std_core_types__optional_drop(_match_x221, _ctx);
    _x_x440 = _uniq_parts_95; /*list<string>*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x221, _ctx);
    _x_x440 = kk_std_core_types__new_Nil(_ctx); /*list<string>*/
  }
  _x_x438 = kk_std_os_path__new_Path(_x_x439, _x_x440, _ctx); /*std/os/path/path*/
  kk_std_os_dir_copy_file(from, _x_x438, kk_std_core_types__new_None(_ctx), _ctx); return kk_Unit;
}

bool kk_std_os_dir_prim_is_file(kk_string_t path, kk_context_t* _ctx) { /* (path : string) -> fsys bool */ 
  return kk_os_is_file(path,kk_context());
}

// initialization
void kk_std_os_dir__init(kk_context_t* _ctx){
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
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
}

// termination
void kk_std_os_dir__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
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
