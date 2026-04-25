// Koka generated module: std/os/path, koka version: 3.2.3, platform: 64-bit
#include "std_os_path.h"

kk_std_os_path__path kk_std_os_path_path_fs__copy(kk_std_os_path__path _this, kk_std_core_types__optional root, kk_std_core_types__optional parts, kk_context_t* _ctx) { /* (path, root : ? string, parts : ? (list<string>)) -> path */ 
  kk_string_t _x_x580;
  if (kk_std_core_types__is_Optional(root, _ctx)) {
    kk_box_t _box_x2 = root._cons._Optional.value;
    kk_string_t _uniq_root_128 = kk_string_unbox(_box_x2);
    kk_string_dup(_uniq_root_128, _ctx);
    kk_std_core_types__optional_drop(root, _ctx);
    _x_x580 = _uniq_root_128; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(root, _ctx);
    {
      kk_string_t _x = _this.root;
      kk_string_dup(_x, _ctx);
      _x_x580 = _x; /*string*/
    }
  }
  kk_std_core_types__list _x_x581;
  if (kk_std_core_types__is_Optional(parts, _ctx)) {
    kk_box_t _box_x3 = parts._cons._Optional.value;
    kk_std_core_types__list _uniq_parts_136 = kk_std_core_types__list_unbox(_box_x3, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(_uniq_parts_136, _ctx);
    kk_std_core_types__optional_drop(parts, _ctx);
    kk_std_os_path__path_drop(_this, _ctx);
    _x_x581 = _uniq_parts_136; /*list<string>*/
  }
  else {
    kk_std_core_types__optional_drop(parts, _ctx);
    {
      kk_std_core_types__list _x_0 = _this.parts;
      kk_std_core_types__list_dup(_x_0, _ctx);
      kk_std_os_path__path_drop(_this, _ctx);
      _x_x581 = _x_0; /*list<string>*/
    }
  }
  return kk_std_os_path__new_Path(_x_x580, _x_x581, _ctx);
}
 
// Return the base name of a path (stem name + extension)
// `"/foo/bar.txt".path.basename === "bar.txt"`
// `"/foo".path.basename === "foo"`

kk_string_t kk_std_os_path_basename(kk_std_os_path__path p, kk_context_t* _ctx) { /* (p : path) -> string */ 
  {
    kk_std_core_types__list _x = p.parts;
    kk_std_core_types__list_dup(_x, _ctx);
    kk_std_os_path__path_drop(p, _ctx);
    if (kk_std_core_types__is_Cons(_x, _ctx)) {
      struct kk_std_core_types_Cons* _con_x582 = kk_std_core_types__as_Cons(_x, _ctx);
      kk_box_t _box_x4 = _con_x582->head;
      kk_std_core_types__list _pat_0_0 = _con_x582->tail;
      kk_string_t x_0 = kk_string_unbox(_box_x4);
      if kk_likely(kk_datatype_ptr_is_unique(_x, _ctx)) {
        kk_std_core_types__list_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(_x, _ctx);
      }
      else {
        kk_string_dup(x_0, _ctx);
        kk_datatype_ptr_decref(_x, _ctx);
      }
      return x_0;
    }
    {
      return kk_string_empty();
    }
  }
}
 
// Return the directory part of a path (including the rootname)
// `"/foo/bar.txt".path.dirname === "/foo"`
// `"/foo".path.dirname === "/"`

kk_string_t kk_std_os_path_dirname(kk_std_os_path__path p, kk_context_t* _ctx) { /* (p : path) -> string */ 
  kk_std_core_types__list xs_10008;
  {
    kk_std_core_types__list _x_0 = p.parts;
    kk_std_core_types__list_dup(_x_0, _ctx);
    if (kk_std_core_types__is_Cons(_x_0, _ctx)) {
      struct kk_std_core_types_Cons* _con_x584 = kk_std_core_types__as_Cons(_x_0, _ctx);
      kk_box_t _box_x6 = _con_x584->head;
      kk_std_core_types__list xx = _con_x584->tail;
      kk_string_t _pat_0_1 = kk_string_unbox(_box_x6);
      if kk_likely(kk_datatype_ptr_is_unique(_x_0, _ctx)) {
        kk_string_drop(_pat_0_1, _ctx);
        kk_datatype_ptr_free(_x_0, _ctx);
      }
      else {
        kk_std_core_types__list_dup(xx, _ctx);
        kk_datatype_ptr_decref(_x_0, _ctx);
      }
      if (kk_std_core_types__is_Nil(xx, _ctx)) {
        xs_10008 = kk_std_core_types__new_Nil(_ctx); /*list<string>*/
      }
      else {
        kk_std_core_types__list_drop(xx, _ctx);
        kk_std_core_types__list _x_x585;
        {
          kk_std_core_types__list _x_0_0 = p.parts;
          kk_std_core_types__list_dup(_x_0_0, _ctx);
          if (kk_std_core_types__is_Cons(_x_0_0, _ctx)) {
            struct kk_std_core_types_Cons* _con_x586 = kk_std_core_types__as_Cons(_x_0_0, _ctx);
            kk_box_t _box_x7 = _con_x586->head;
            kk_std_core_types__list xx_0 = _con_x586->tail;
            kk_string_t _pat_0_1_0 = kk_string_unbox(_box_x7);
            if kk_likely(kk_datatype_ptr_is_unique(_x_0_0, _ctx)) {
              kk_string_drop(_pat_0_1_0, _ctx);
              kk_datatype_ptr_free(_x_0_0, _ctx);
            }
            else {
              kk_std_core_types__list_dup(xx_0, _ctx);
              kk_datatype_ptr_decref(_x_0_0, _ctx);
            }
            _x_x585 = xx_0; /*list<string>*/
          }
          else {
            _x_x585 = kk_std_core_types__new_Nil(_ctx); /*list<string>*/
          }
        }
        xs_10008 = kk_std_core_list__unroll_reverse_acc_10003(kk_std_core_types__new_Nil(_ctx), _x_x585, _ctx); /*list<string>*/
      }
    }
    else {
      xs_10008 = kk_std_core_types__new_Nil(_ctx); /*list<string>*/
    }
  }
  kk_string_t _x_x587;
  {
    kk_string_t _x = p.root;
    kk_string_dup(_x, _ctx);
    kk_std_os_path__path_drop(p, _ctx);
    _x_x587 = _x; /*string*/
  }
  kk_string_t _x_x588;
  if (kk_std_core_types__is_Nil(xs_10008, _ctx)) {
    _x_x588 = kk_string_empty(); /*string*/
    goto _match_x589;
  }
  {
    struct kk_std_core_types_Cons* _con_x591 = kk_std_core_types__as_Cons(xs_10008, _ctx);
    kk_box_t _box_x8 = _con_x591->head;
    kk_std_core_types__list _pat_1_1 = _con_x591->tail;
    if (kk_std_core_types__is_Nil(_pat_1_1, _ctx)) {
      kk_string_t x = kk_string_unbox(_box_x8);
      if kk_likely(kk_datatype_ptr_is_unique(xs_10008, _ctx)) {
        kk_datatype_ptr_free(xs_10008, _ctx);
      }
      else {
        kk_string_dup(x, _ctx);
        kk_datatype_ptr_decref(xs_10008, _ctx);
      }
      _x_x588 = x; /*string*/
      goto _match_x589;
    }
  }
  if (kk_std_core_types__is_Cons(xs_10008, _ctx)) {
    struct kk_std_core_types_Cons* _con_x592 = kk_std_core_types__as_Cons(xs_10008, _ctx);
    kk_box_t _box_x9 = _con_x592->head;
    kk_std_core_types__list _pat_3_0_0 = _con_x592->tail;
    if (kk_std_core_types__is_Cons(_pat_3_0_0, _ctx)) {
      struct kk_std_core_types_Cons* _con_x593 = kk_std_core_types__as_Cons(_pat_3_0_0, _ctx);
      kk_box_t _box_x10 = _con_x593->head;
      kk_std_core_types__list _pat_4_0 = _con_x593->tail;
      if (kk_std_core_types__is_Nil(_pat_4_0, _ctx)) {
        kk_string_t _x_x594;
        kk_define_string_literal(static, _s_x595, 1, "/", _ctx)
        _x_x594 = kk_string_dup(_s_x595, _ctx); /*string*/
        kk_string_t _x_x596 = kk_string_empty(); /*string*/
        if (kk_string_is_eq(_x_x594,_x_x596,kk_context())) {
          kk_string_t x_0 = kk_string_unbox(_box_x9);
          kk_string_t y = kk_string_unbox(_box_x10);
          if kk_likely(kk_datatype_ptr_is_unique(xs_10008, _ctx)) {
            if kk_likely(kk_datatype_ptr_is_unique(_pat_3_0_0, _ctx)) {
              kk_datatype_ptr_free(_pat_3_0_0, _ctx);
            }
            else {
              kk_string_dup(y, _ctx);
              kk_datatype_ptr_decref(_pat_3_0_0, _ctx);
            }
            kk_datatype_ptr_free(xs_10008, _ctx);
          }
          else {
            kk_string_dup(x_0, _ctx);
            kk_string_dup(y, _ctx);
            kk_datatype_ptr_decref(xs_10008, _ctx);
          }
          _x_x588 = kk_std_core_types__lp__plus__plus__rp_(x_0, y, _ctx); /*string*/
          goto _match_x589;
        }
      }
    }
  }
  {
    kk_vector_t _x_x598 = kk_std_core_vector_unvlist(xs_10008, _ctx); /*vector<978>*/
    kk_string_t _x_x599;
    kk_define_string_literal(static, _s_x600, 1, "/", _ctx)
    _x_x599 = kk_string_dup(_s_x600, _ctx); /*string*/
    _x_x588 = kk_string_join_with(_x_x598,_x_x599,kk_context()); /*string*/
  }
  _match_x589: ;
  return kk_std_core_types__lp__plus__plus__rp_(_x_x587, _x_x588, _ctx);
}
 
// Is a path empty?

bool kk_std_os_path_is_empty(kk_std_os_path__path p, kk_context_t* _ctx) { /* (p : path) -> bool */ 
  bool _match_x528;
  kk_string_t _x_x601;
  {
    kk_string_t _x = p.root;
    kk_string_dup(_x, _ctx);
    _x_x601 = _x; /*string*/
  }
  kk_string_t _x_x602 = kk_string_empty(); /*string*/
  _match_x528 = kk_string_is_eq(_x_x601,_x_x602,kk_context()); /*bool*/
  if (_match_x528) {
    kk_std_core_types__list _x_0 = p.parts;
    kk_std_core_types__list_dup(_x_0, _ctx);
    kk_std_os_path__path_drop(p, _ctx);
    if (kk_std_core_types__is_Nil(_x_0, _ctx)) {
      return true;
    }
    {
      kk_std_core_types__list_drop(_x_0, _ctx);
      return false;
    }
  }
  {
    kk_std_os_path__path_drop(p, _ctx);
    return false;
  }
}
 
// Convert a `:path` to a normalized `:string` path.
// If this results in an empty string, the current directory path `"."` is returned.
// `"c:/foo/test.txt".path.string -> "c:/foo/test.txt"`
// `"c:\\foo\\test.txt".path.string -> "c:/foo/test.txt"`
// `"/foo//./bar/../test.txt".path.string -> "/foo/test.txt"`

kk_string_t kk_std_os_path_string(kk_std_os_path__path p, kk_context_t* _ctx) { /* (p : path) -> string */ 
  kk_std_core_types__list xs_10018;
  {
    kk_std_core_types__list _x_0 = p.parts;
    kk_std_core_types__list_dup(_x_0, _ctx);
    if (kk_std_core_types__is_Nil(_x_0, _ctx)) {
      xs_10018 = kk_std_core_types__new_Nil(_ctx); /*list<string>*/
    }
    else {
      kk_std_core_types__list_drop(_x_0, _ctx);
      kk_std_core_types__list _x_x604;
      {
        kk_std_core_types__list _x_0_0 = p.parts;
        kk_std_core_types__list_dup(_x_0_0, _ctx);
        _x_x604 = _x_0_0; /*list<string>*/
      }
      xs_10018 = kk_std_core_list__unroll_reverse_acc_10003(kk_std_core_types__new_Nil(_ctx), _x_x604, _ctx); /*list<string>*/
    }
  }
  kk_string_t s;
  kk_string_t _x_x605;
  {
    kk_string_t _x = p.root;
    kk_string_dup(_x, _ctx);
    kk_std_os_path__path_drop(p, _ctx);
    _x_x605 = _x; /*string*/
  }
  kk_string_t _x_x606;
  if (kk_std_core_types__is_Nil(xs_10018, _ctx)) {
    _x_x606 = kk_string_empty(); /*string*/
    goto _match_x607;
  }
  {
    struct kk_std_core_types_Cons* _con_x609 = kk_std_core_types__as_Cons(xs_10018, _ctx);
    kk_box_t _box_x11 = _con_x609->head;
    kk_std_core_types__list _pat_1_0 = _con_x609->tail;
    if (kk_std_core_types__is_Nil(_pat_1_0, _ctx)) {
      kk_string_t x = kk_string_unbox(_box_x11);
      if kk_likely(kk_datatype_ptr_is_unique(xs_10018, _ctx)) {
        kk_datatype_ptr_free(xs_10018, _ctx);
      }
      else {
        kk_string_dup(x, _ctx);
        kk_datatype_ptr_decref(xs_10018, _ctx);
      }
      _x_x606 = x; /*string*/
      goto _match_x607;
    }
  }
  if (kk_std_core_types__is_Cons(xs_10018, _ctx)) {
    struct kk_std_core_types_Cons* _con_x610 = kk_std_core_types__as_Cons(xs_10018, _ctx);
    kk_box_t _box_x12 = _con_x610->head;
    kk_std_core_types__list _pat_3_0 = _con_x610->tail;
    if (kk_std_core_types__is_Cons(_pat_3_0, _ctx)) {
      struct kk_std_core_types_Cons* _con_x611 = kk_std_core_types__as_Cons(_pat_3_0, _ctx);
      kk_box_t _box_x13 = _con_x611->head;
      kk_std_core_types__list _pat_4 = _con_x611->tail;
      if (kk_std_core_types__is_Nil(_pat_4, _ctx)) {
        kk_string_t _x_x612;
        kk_define_string_literal(static, _s_x613, 1, "/", _ctx)
        _x_x612 = kk_string_dup(_s_x613, _ctx); /*string*/
        kk_string_t _x_x614 = kk_string_empty(); /*string*/
        if (kk_string_is_eq(_x_x612,_x_x614,kk_context())) {
          kk_string_t x_0 = kk_string_unbox(_box_x12);
          kk_string_t y = kk_string_unbox(_box_x13);
          if kk_likely(kk_datatype_ptr_is_unique(xs_10018, _ctx)) {
            if kk_likely(kk_datatype_ptr_is_unique(_pat_3_0, _ctx)) {
              kk_datatype_ptr_free(_pat_3_0, _ctx);
            }
            else {
              kk_string_dup(y, _ctx);
              kk_datatype_ptr_decref(_pat_3_0, _ctx);
            }
            kk_datatype_ptr_free(xs_10018, _ctx);
          }
          else {
            kk_string_dup(x_0, _ctx);
            kk_string_dup(y, _ctx);
            kk_datatype_ptr_decref(xs_10018, _ctx);
          }
          _x_x606 = kk_std_core_types__lp__plus__plus__rp_(x_0, y, _ctx); /*string*/
          goto _match_x607;
        }
      }
    }
  }
  {
    kk_vector_t _x_x616 = kk_std_core_vector_unvlist(xs_10018, _ctx); /*vector<978>*/
    kk_string_t _x_x617;
    kk_define_string_literal(static, _s_x618, 1, "/", _ctx)
    _x_x617 = kk_string_dup(_s_x618, _ctx); /*string*/
    _x_x606 = kk_string_join_with(_x_x616,_x_x617,kk_context()); /*string*/
  }
  _match_x607: ;
  s = kk_std_core_types__lp__plus__plus__rp_(_x_x605, _x_x606, _ctx); /*string*/
  bool _match_x527;
  kk_string_t _x_x619 = kk_string_dup(s, _ctx); /*string*/
  kk_string_t _x_x620 = kk_string_empty(); /*string*/
  _match_x527 = kk_string_is_eq(_x_x619,_x_x620,kk_context()); /*bool*/
  if (_match_x527) {
    kk_string_drop(s, _ctx);
    kk_define_string_literal(static, _s_x622, 1, ".", _ctx)
    return kk_string_dup(_s_x622, _ctx);
  }
  {
    return s;
  }
}

kk_std_core_types__tuple2 kk_std_os_path_split_base(kk_string_t basename_0, kk_context_t* _ctx) { /* (basename : string) -> (string, string) */ 
  kk_integer_t i;
  kk_ssize_t _x_x623;
  kk_string_t _x_x624 = kk_string_dup(basename_0, _ctx); /*string*/
  kk_string_t _x_x625;
  kk_define_string_literal(static, _s_x626, 1, ".", _ctx)
  _x_x625 = kk_string_dup(_s_x626, _ctx); /*string*/
  _x_x623 = kk_string_last_index_of1(_x_x624,_x_x625,kk_context()); /*ssize_t*/
  i = kk_integer_from_ssize_t(_x_x623,kk_context()); /*int*/
  bool _match_x525 = kk_integer_is_zero_borrow(i); /*bool*/;
  if (_match_x525) {
    kk_integer_drop(i, _ctx);
    kk_std_core_types__maybe _match_x526 = kk_std_core_types__new_Nothing(_ctx); /*forall<a> maybe<a>*/;
    if (kk_std_core_types__is_Just(_match_x526, _ctx)) {
      kk_box_t _box_x14 = _match_x526._cons.Just.value;
      kk_std_core_sslice__sslice slice = kk_std_core_sslice__sslice_unbox(_box_x14, KK_BORROWED, _ctx);
      kk_string_drop(basename_0, _ctx);
      kk_std_core_sslice__sslice_dup(slice, _ctx);
      kk_std_core_types__maybe_drop(_match_x526, _ctx);
      kk_string_t _b_x15_21;
      kk_std_core_sslice__sslice _x_x627;
      {
        kk_string_t s_0 = slice.str;
        kk_integer_t start = slice.start;
        kk_string_dup(s_0, _ctx);
        kk_integer_dup(start, _ctx);
        _x_x627 = kk_std_core_sslice__new_Sslice(s_0, kk_integer_from_small(0), start, _ctx); /*sslice/sslice*/
      }
      _b_x15_21 = kk_std_core_sslice_string(_x_x627, _ctx); /*string*/
      kk_string_t _b_x16_22;
      kk_std_core_sslice__sslice _x_x628 = kk_std_core_sslice_after(slice, _ctx); /*sslice/sslice*/
      _b_x16_22 = kk_std_core_sslice_string(_x_x628, _ctx); /*string*/
      return kk_std_core_types__new_Tuple2(kk_string_box(_b_x15_21), kk_string_box(_b_x16_22), _ctx);
    }
    {
      kk_box_t _x_x629;
      kk_string_t _x_x630 = kk_string_empty(); /*string*/
      _x_x629 = kk_string_box(_x_x630); /*135*/
      return kk_std_core_types__new_Tuple2(kk_string_box(basename_0), _x_x629, _ctx);
    }
  }
  {
    kk_integer_t _pat_1_0_0 = kk_integer_add_small_const(i, -1, _ctx); /*int*/;
    kk_integer_t _pat_2_0;
    kk_string_t _x_x632;
    kk_define_string_literal(static, _s_x633, 1, ".", _ctx)
    _x_x632 = kk_string_dup(_s_x633, _ctx); /*string*/
    _pat_2_0 = kk_string_len_int(_x_x632,kk_context()); /*int*/
    kk_std_core_sslice__sslice slice_0 = kk_std_core_sslice__new_Sslice(basename_0, _pat_1_0_0, _pat_2_0, _ctx); /*sslice/sslice*/;
    kk_string_t _b_x19_25;
    kk_std_core_sslice__sslice _x_x634;
    {
      kk_string_t s_0_0 = slice_0.str;
      kk_integer_t start_0 = slice_0.start;
      kk_string_dup(s_0_0, _ctx);
      kk_integer_dup(start_0, _ctx);
      _x_x634 = kk_std_core_sslice__new_Sslice(s_0_0, kk_integer_from_small(0), start_0, _ctx); /*sslice/sslice*/
    }
    _b_x19_25 = kk_std_core_sslice_string(_x_x634, _ctx); /*string*/
    kk_string_t _b_x20_26;
    kk_std_core_sslice__sslice _x_x635 = kk_std_core_sslice_after(slice_0, _ctx); /*sslice/sslice*/
    _b_x20_26 = kk_std_core_sslice_string(_x_x635, _ctx); /*string*/
    return kk_std_core_types__new_Tuple2(kk_string_box(_b_x19_25), kk_string_box(_b_x20_26), _ctx);
  }
}
 
// Return the extension of path (without the preceding dot (`'.'`))
// `"/foo/bar.svg.txt".path.extname === "txt"`

kk_string_t kk_std_os_path_extname(kk_std_os_path__path p, kk_context_t* _ctx) { /* (p : path) -> string */ 
  kk_integer_t i;
  kk_ssize_t _x_x636;
  kk_string_t _x_x637;
  {
    kk_std_core_types__list _x = p.parts;
    kk_std_core_types__list_dup(_x, _ctx);
    if (kk_std_core_types__is_Cons(_x, _ctx)) {
      struct kk_std_core_types_Cons* _con_x638 = kk_std_core_types__as_Cons(_x, _ctx);
      kk_box_t _box_x27 = _con_x638->head;
      kk_std_core_types__list _pat_0_0 = _con_x638->tail;
      kk_string_t x_0 = kk_string_unbox(_box_x27);
      if kk_likely(kk_datatype_ptr_is_unique(_x, _ctx)) {
        kk_std_core_types__list_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(_x, _ctx);
      }
      else {
        kk_string_dup(x_0, _ctx);
        kk_datatype_ptr_decref(_x, _ctx);
      }
      _x_x637 = x_0; /*string*/
    }
    else {
      _x_x637 = kk_string_empty(); /*string*/
    }
  }
  kk_string_t _x_x640;
  kk_define_string_literal(static, _s_x641, 1, ".", _ctx)
  _x_x640 = kk_string_dup(_s_x641, _ctx); /*string*/
  _x_x636 = kk_string_last_index_of1(_x_x637,_x_x640,kk_context()); /*ssize_t*/
  i = kk_integer_from_ssize_t(_x_x636,kk_context()); /*int*/
  kk_std_core_types__tuple2 tuple2_10026;
  bool _match_x523 = kk_integer_is_zero_borrow(i); /*bool*/;
  if (_match_x523) {
    kk_integer_drop(i, _ctx);
    kk_std_core_types__maybe _match_x524 = kk_std_core_types__new_Nothing(_ctx); /*forall<a> maybe<a>*/;
    if (kk_std_core_types__is_Just(_match_x524, _ctx)) {
      kk_box_t _box_x29 = _match_x524._cons.Just.value;
      kk_std_core_sslice__sslice slice = kk_std_core_sslice__sslice_unbox(_box_x29, KK_BORROWED, _ctx);
      kk_std_os_path__path_drop(p, _ctx);
      kk_std_core_sslice__sslice_dup(slice, _ctx);
      kk_std_core_types__maybe_drop(_match_x524, _ctx);
      kk_string_t _b_x30_40;
      kk_std_core_sslice__sslice _x_x642;
      {
        kk_string_t s_0 = slice.str;
        kk_integer_t start = slice.start;
        kk_string_dup(s_0, _ctx);
        kk_integer_dup(start, _ctx);
        _x_x642 = kk_std_core_sslice__new_Sslice(s_0, kk_integer_from_small(0), start, _ctx); /*sslice/sslice*/
      }
      _b_x30_40 = kk_std_core_sslice_string(_x_x642, _ctx); /*string*/
      kk_string_t _b_x31_41;
      kk_std_core_sslice__sslice _x_x643 = kk_std_core_sslice_after(slice, _ctx); /*sslice/sslice*/
      _b_x31_41 = kk_std_core_sslice_string(_x_x643, _ctx); /*string*/
      tuple2_10026 = kk_std_core_types__new_Tuple2(kk_string_box(_b_x30_40), kk_string_box(_b_x31_41), _ctx); /*(string, string)*/
    }
    else {
      kk_box_t _x_x644;
      kk_string_t _x_x645;
      {
        kk_std_core_types__list _x_0 = p.parts;
        kk_std_core_types__list_dup(_x_0, _ctx);
        kk_std_os_path__path_drop(p, _ctx);
        if (kk_std_core_types__is_Cons(_x_0, _ctx)) {
          struct kk_std_core_types_Cons* _con_x646 = kk_std_core_types__as_Cons(_x_0, _ctx);
          kk_box_t _box_x32 = _con_x646->head;
          kk_std_core_types__list _pat_0_0_0 = _con_x646->tail;
          kk_string_t x_0_0 = kk_string_unbox(_box_x32);
          if kk_likely(kk_datatype_ptr_is_unique(_x_0, _ctx)) {
            kk_std_core_types__list_drop(_pat_0_0_0, _ctx);
            kk_datatype_ptr_free(_x_0, _ctx);
          }
          else {
            kk_string_dup(x_0_0, _ctx);
            kk_datatype_ptr_decref(_x_0, _ctx);
          }
          _x_x645 = x_0_0; /*string*/
        }
        else {
          _x_x645 = kk_string_empty(); /*string*/
        }
      }
      _x_x644 = kk_string_box(_x_x645); /*134*/
      kk_box_t _x_x648;
      kk_string_t _x_x649 = kk_string_empty(); /*string*/
      _x_x648 = kk_string_box(_x_x649); /*135*/
      tuple2_10026 = kk_std_core_types__new_Tuple2(_x_x644, _x_x648, _ctx); /*(string, string)*/
    }
  }
  else {
    kk_integer_t _pat_1_0_1_0 = kk_integer_add_small_const(i, -1, _ctx); /*int*/;
    kk_integer_t _pat_2_0_1;
    kk_string_t _x_x651;
    kk_define_string_literal(static, _s_x652, 1, ".", _ctx)
    _x_x651 = kk_string_dup(_s_x652, _ctx); /*string*/
    _pat_2_0_1 = kk_string_len_int(_x_x651,kk_context()); /*int*/
    kk_std_core_sslice__sslice slice_0;
    kk_string_t _x_x653;
    {
      kk_std_core_types__list _x_1 = p.parts;
      kk_std_core_types__list_dup(_x_1, _ctx);
      kk_std_os_path__path_drop(p, _ctx);
      if (kk_std_core_types__is_Cons(_x_1, _ctx)) {
        struct kk_std_core_types_Cons* _con_x654 = kk_std_core_types__as_Cons(_x_1, _ctx);
        kk_box_t _box_x36 = _con_x654->head;
        kk_std_core_types__list _pat_0_0_1 = _con_x654->tail;
        kk_string_t x_0_1 = kk_string_unbox(_box_x36);
        if kk_likely(kk_datatype_ptr_is_unique(_x_1, _ctx)) {
          kk_std_core_types__list_drop(_pat_0_0_1, _ctx);
          kk_datatype_ptr_free(_x_1, _ctx);
        }
        else {
          kk_string_dup(x_0_1, _ctx);
          kk_datatype_ptr_decref(_x_1, _ctx);
        }
        _x_x653 = x_0_1; /*string*/
      }
      else {
        _x_x653 = kk_string_empty(); /*string*/
      }
    }
    slice_0 = kk_std_core_sslice__new_Sslice(_x_x653, _pat_1_0_1_0, _pat_2_0_1, _ctx); /*sslice/sslice*/
    kk_string_t _b_x38_44;
    kk_std_core_sslice__sslice _x_x656;
    {
      kk_string_t s_0_0 = slice_0.str;
      kk_integer_t start_0 = slice_0.start;
      kk_string_dup(s_0_0, _ctx);
      kk_integer_dup(start_0, _ctx);
      _x_x656 = kk_std_core_sslice__new_Sslice(s_0_0, kk_integer_from_small(0), start_0, _ctx); /*sslice/sslice*/
    }
    _b_x38_44 = kk_std_core_sslice_string(_x_x656, _ctx); /*string*/
    kk_string_t _b_x39_45;
    kk_std_core_sslice__sslice _x_x657 = kk_std_core_sslice_after(slice_0, _ctx); /*sslice/sslice*/
    _b_x39_45 = kk_std_core_sslice_string(_x_x657, _ctx); /*string*/
    tuple2_10026 = kk_std_core_types__new_Tuple2(kk_string_box(_b_x38_44), kk_string_box(_b_x39_45), _ctx); /*(string, string)*/
  }
  {
    kk_box_t _box_x46 = tuple2_10026.fst;
    kk_box_t _box_x47 = tuple2_10026.snd;
    kk_string_t _x_0_0 = kk_string_unbox(_box_x47);
    kk_string_dup(_x_0_0, _ctx);
    kk_std_core_types__tuple2_drop(tuple2_10026, _ctx);
    return _x_0_0;
  }
}
 
// Return the stem name of path.
// `"/foo/bar.svg.txt".path.extname === "foo.svg"`

kk_string_t kk_std_os_path_stemname(kk_std_os_path__path p, kk_context_t* _ctx) { /* (p : path) -> string */ 
  kk_integer_t i;
  kk_ssize_t _x_x658;
  kk_string_t _x_x659;
  {
    kk_std_core_types__list _x = p.parts;
    kk_std_core_types__list_dup(_x, _ctx);
    if (kk_std_core_types__is_Cons(_x, _ctx)) {
      struct kk_std_core_types_Cons* _con_x660 = kk_std_core_types__as_Cons(_x, _ctx);
      kk_box_t _box_x48 = _con_x660->head;
      kk_std_core_types__list _pat_0_0 = _con_x660->tail;
      kk_string_t x_0 = kk_string_unbox(_box_x48);
      if kk_likely(kk_datatype_ptr_is_unique(_x, _ctx)) {
        kk_std_core_types__list_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(_x, _ctx);
      }
      else {
        kk_string_dup(x_0, _ctx);
        kk_datatype_ptr_decref(_x, _ctx);
      }
      _x_x659 = x_0; /*string*/
    }
    else {
      _x_x659 = kk_string_empty(); /*string*/
    }
  }
  kk_string_t _x_x662;
  kk_define_string_literal(static, _s_x663, 1, ".", _ctx)
  _x_x662 = kk_string_dup(_s_x663, _ctx); /*string*/
  _x_x658 = kk_string_last_index_of1(_x_x659,_x_x662,kk_context()); /*ssize_t*/
  i = kk_integer_from_ssize_t(_x_x658,kk_context()); /*int*/
  kk_std_core_types__tuple2 tuple2_10031;
  bool _match_x521 = kk_integer_is_zero_borrow(i); /*bool*/;
  if (_match_x521) {
    kk_integer_drop(i, _ctx);
    kk_std_core_types__maybe _match_x522 = kk_std_core_types__new_Nothing(_ctx); /*forall<a> maybe<a>*/;
    if (kk_std_core_types__is_Just(_match_x522, _ctx)) {
      kk_box_t _box_x50 = _match_x522._cons.Just.value;
      kk_std_core_sslice__sslice slice = kk_std_core_sslice__sslice_unbox(_box_x50, KK_BORROWED, _ctx);
      kk_std_os_path__path_drop(p, _ctx);
      kk_std_core_sslice__sslice_dup(slice, _ctx);
      kk_std_core_types__maybe_drop(_match_x522, _ctx);
      kk_string_t _b_x51_61;
      kk_std_core_sslice__sslice _x_x664;
      {
        kk_string_t s_0 = slice.str;
        kk_integer_t start = slice.start;
        kk_string_dup(s_0, _ctx);
        kk_integer_dup(start, _ctx);
        _x_x664 = kk_std_core_sslice__new_Sslice(s_0, kk_integer_from_small(0), start, _ctx); /*sslice/sslice*/
      }
      _b_x51_61 = kk_std_core_sslice_string(_x_x664, _ctx); /*string*/
      kk_string_t _b_x52_62;
      kk_std_core_sslice__sslice _x_x665 = kk_std_core_sslice_after(slice, _ctx); /*sslice/sslice*/
      _b_x52_62 = kk_std_core_sslice_string(_x_x665, _ctx); /*string*/
      tuple2_10031 = kk_std_core_types__new_Tuple2(kk_string_box(_b_x51_61), kk_string_box(_b_x52_62), _ctx); /*(string, string)*/
    }
    else {
      kk_box_t _x_x666;
      kk_string_t _x_x667;
      {
        kk_std_core_types__list _x_0 = p.parts;
        kk_std_core_types__list_dup(_x_0, _ctx);
        kk_std_os_path__path_drop(p, _ctx);
        if (kk_std_core_types__is_Cons(_x_0, _ctx)) {
          struct kk_std_core_types_Cons* _con_x668 = kk_std_core_types__as_Cons(_x_0, _ctx);
          kk_box_t _box_x53 = _con_x668->head;
          kk_std_core_types__list _pat_0_0_0 = _con_x668->tail;
          kk_string_t x_0_0 = kk_string_unbox(_box_x53);
          if kk_likely(kk_datatype_ptr_is_unique(_x_0, _ctx)) {
            kk_std_core_types__list_drop(_pat_0_0_0, _ctx);
            kk_datatype_ptr_free(_x_0, _ctx);
          }
          else {
            kk_string_dup(x_0_0, _ctx);
            kk_datatype_ptr_decref(_x_0, _ctx);
          }
          _x_x667 = x_0_0; /*string*/
        }
        else {
          _x_x667 = kk_string_empty(); /*string*/
        }
      }
      _x_x666 = kk_string_box(_x_x667); /*134*/
      kk_box_t _x_x670;
      kk_string_t _x_x671 = kk_string_empty(); /*string*/
      _x_x670 = kk_string_box(_x_x671); /*135*/
      tuple2_10031 = kk_std_core_types__new_Tuple2(_x_x666, _x_x670, _ctx); /*(string, string)*/
    }
  }
  else {
    kk_integer_t _pat_1_0_1_0 = kk_integer_add_small_const(i, -1, _ctx); /*int*/;
    kk_integer_t _pat_2_0_1;
    kk_string_t _x_x673;
    kk_define_string_literal(static, _s_x674, 1, ".", _ctx)
    _x_x673 = kk_string_dup(_s_x674, _ctx); /*string*/
    _pat_2_0_1 = kk_string_len_int(_x_x673,kk_context()); /*int*/
    kk_std_core_sslice__sslice slice_0;
    kk_string_t _x_x675;
    {
      kk_std_core_types__list _x_1 = p.parts;
      kk_std_core_types__list_dup(_x_1, _ctx);
      kk_std_os_path__path_drop(p, _ctx);
      if (kk_std_core_types__is_Cons(_x_1, _ctx)) {
        struct kk_std_core_types_Cons* _con_x676 = kk_std_core_types__as_Cons(_x_1, _ctx);
        kk_box_t _box_x57 = _con_x676->head;
        kk_std_core_types__list _pat_0_0_1 = _con_x676->tail;
        kk_string_t x_0_1 = kk_string_unbox(_box_x57);
        if kk_likely(kk_datatype_ptr_is_unique(_x_1, _ctx)) {
          kk_std_core_types__list_drop(_pat_0_0_1, _ctx);
          kk_datatype_ptr_free(_x_1, _ctx);
        }
        else {
          kk_string_dup(x_0_1, _ctx);
          kk_datatype_ptr_decref(_x_1, _ctx);
        }
        _x_x675 = x_0_1; /*string*/
      }
      else {
        _x_x675 = kk_string_empty(); /*string*/
      }
    }
    slice_0 = kk_std_core_sslice__new_Sslice(_x_x675, _pat_1_0_1_0, _pat_2_0_1, _ctx); /*sslice/sslice*/
    kk_string_t _b_x59_65;
    kk_std_core_sslice__sslice _x_x678;
    {
      kk_string_t s_0_0 = slice_0.str;
      kk_integer_t start_0 = slice_0.start;
      kk_string_dup(s_0_0, _ctx);
      kk_integer_dup(start_0, _ctx);
      _x_x678 = kk_std_core_sslice__new_Sslice(s_0_0, kk_integer_from_small(0), start_0, _ctx); /*sslice/sslice*/
    }
    _b_x59_65 = kk_std_core_sslice_string(_x_x678, _ctx); /*string*/
    kk_string_t _b_x60_66;
    kk_std_core_sslice__sslice _x_x679 = kk_std_core_sslice_after(slice_0, _ctx); /*sslice/sslice*/
    _b_x60_66 = kk_std_core_sslice_string(_x_x679, _ctx); /*string*/
    tuple2_10031 = kk_std_core_types__new_Tuple2(kk_string_box(_b_x59_65), kk_string_box(_b_x60_66), _ctx); /*(string, string)*/
  }
  {
    kk_box_t _box_x67 = tuple2_10031.fst;
    kk_box_t _box_x68 = tuple2_10031.snd;
    kk_string_t _x_0_0 = kk_string_unbox(_box_x67);
    kk_string_dup(_x_0_0, _ctx);
    kk_std_core_types__tuple2_drop(tuple2_10031, _ctx);
    return _x_0_0;
  }
}

kk_std_core_types__tuple2 kk_std_os_path_split_parts(kk_std_core_types__list parts, kk_context_t* _ctx) { /* (parts : list<string>) -> (string, list<string>) */ 
  kk_box_t _x_x680;
  kk_string_t _x_x681;
  if (kk_std_core_types__is_Cons(parts, _ctx)) {
    struct kk_std_core_types_Cons* _con_x682 = kk_std_core_types__as_Cons(parts, _ctx);
    kk_box_t _box_x69 = _con_x682->head;
    kk_string_t x_0 = kk_string_unbox(_box_x69);
    kk_string_dup(x_0, _ctx);
    _x_x681 = x_0; /*string*/
  }
  else {
    _x_x681 = kk_string_empty(); /*string*/
  }
  _x_x680 = kk_string_box(_x_x681); /*134*/
  kk_box_t _x_x684;
  kk_std_core_types__list _x_x685;
  if (kk_std_core_types__is_Cons(parts, _ctx)) {
    struct kk_std_core_types_Cons* _con_x686 = kk_std_core_types__as_Cons(parts, _ctx);
    kk_box_t _box_x71 = _con_x686->head;
    kk_std_core_types__list xx = _con_x686->tail;
    kk_string_t _pat_0_1_0 = kk_string_unbox(_box_x71);
    if kk_likely(kk_datatype_ptr_is_unique(parts, _ctx)) {
      kk_string_drop(_pat_0_1_0, _ctx);
      kk_datatype_ptr_free(parts, _ctx);
    }
    else {
      kk_std_core_types__list_dup(xx, _ctx);
      kk_datatype_ptr_decref(parts, _ctx);
    }
    _x_x685 = xx; /*list<string>*/
  }
  else {
    _x_x685 = kk_std_core_types__new_Nil(_ctx); /*list<string>*/
  }
  _x_x684 = kk_std_core_types__list_box(_x_x685, _ctx); /*135*/
  return kk_std_core_types__new_Tuple2(_x_x680, _x_x684, _ctx);
}
 
// Return the first path if it is not empty, otherwise return the second one.

kk_std_os_path__path kk_std_os_path__lp__bar__bar__rp_(kk_std_os_path__path p1, kk_std_os_path__path p2, kk_context_t* _ctx) { /* (p1 : path, p2 : path) -> path */ 
  bool _match_x520;
  kk_string_t _x_x694;
  {
    kk_string_t _x = p1.root;
    kk_string_dup(_x, _ctx);
    _x_x694 = _x; /*string*/
  }
  kk_string_t _x_x695 = kk_string_empty(); /*string*/
  _match_x520 = kk_string_is_eq(_x_x694,_x_x695,kk_context()); /*bool*/
  if (_match_x520) {
    kk_std_core_types__list _x_0 = p1.parts;
    kk_std_core_types__list_dup(_x_0, _ctx);
    if (kk_std_core_types__is_Nil(_x_0, _ctx)) {
      kk_std_os_path__path_drop(p1, _ctx);
      return p2;
    }
    {
      kk_std_os_path__path_drop(p2, _ctx);
      kk_std_core_types__list_drop(_x_0, _ctx);
      return p1;
    }
  }
  {
    kk_std_os_path__path_drop(p2, _ctx);
    return p1;
  }
}

kk_std_core_types__list kk_std_os_path_push_part(kk_string_t dir, kk_std_core_types__list dirs, kk_context_t* _ctx) { /* (dir : string, dirs : list<string>) -> list<string> */ 
  bool _match_x517;
  kk_string_t _x_x697 = kk_string_dup(dir, _ctx); /*string*/
  kk_string_t _x_x698;
  kk_define_string_literal(static, _s_x699, 1, ".", _ctx)
  _x_x698 = kk_string_dup(_s_x699, _ctx); /*string*/
  _match_x517 = kk_string_is_eq(_x_x697,_x_x698,kk_context()); /*bool*/
  if (_match_x517) {
    kk_string_drop(dir, _ctx);
    return dirs;
  }
  {
    bool _match_x518;
    kk_string_t _x_x700 = kk_string_dup(dir, _ctx); /*string*/
    kk_string_t _x_x701 = kk_string_empty(); /*string*/
    _match_x518 = kk_string_is_eq(_x_x700,_x_x701,kk_context()); /*bool*/
    if (_match_x518) {
      kk_string_drop(dir, _ctx);
      return dirs;
    }
    {
      bool _match_x519;
      kk_string_t _x_x703 = kk_string_dup(dir, _ctx); /*string*/
      kk_string_t _x_x704;
      kk_define_string_literal(static, _s_x705, 2, "..", _ctx)
      _x_x704 = kk_string_dup(_s_x705, _ctx); /*string*/
      _match_x519 = kk_string_is_eq(_x_x703,_x_x704,kk_context()); /*bool*/
      if (_match_x519) {
        if (kk_std_core_types__is_Cons(dirs, _ctx)) {
          struct kk_std_core_types_Cons* _con_x706 = kk_std_core_types__as_Cons(dirs, _ctx);
          kk_box_t _box_x76 = _con_x706->head;
          kk_string_drop(dir, _ctx);
          if (kk_std_core_types__is_Cons(dirs, _ctx)) {
            struct kk_std_core_types_Cons* _con_x707 = kk_std_core_types__as_Cons(dirs, _ctx);
            kk_box_t _box_x77 = _con_x707->head;
            kk_std_core_types__list xx = _con_x707->tail;
            kk_string_t _pat_0_1 = kk_string_unbox(_box_x77);
            if kk_likely(kk_datatype_ptr_is_unique(dirs, _ctx)) {
              kk_string_drop(_pat_0_1, _ctx);
              kk_datatype_ptr_free(dirs, _ctx);
            }
            else {
              kk_std_core_types__list_dup(xx, _ctx);
              kk_datatype_ptr_decref(dirs, _ctx);
            }
            return xx;
          }
          {
            return kk_std_core_types__new_Nil(_ctx);
          }
        }
        {
          return kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_string_box(dir), dirs, _ctx);
        }
      }
      {
        return kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_string_box(dir), dirs, _ctx);
      }
    }
  }
}

kk_std_core_types__list kk_std_os_path__unroll_push_parts_10000(kk_std_core_types__list parts, kk_std_core_types__list dirs, kk_context_t* _ctx) { /* (parts : list<string>, dirs : list<string>) -> list<string> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(parts, _ctx)) {
    struct kk_std_core_types_Cons* _con_x708 = kk_std_core_types__as_Cons(parts, _ctx);
    kk_box_t _box_x86 = _con_x708->head;
    kk_std_core_types__list rest = _con_x708->tail;
    kk_string_t part = kk_string_unbox(_box_x86);
    if kk_likely(kk_datatype_ptr_is_unique(parts, _ctx)) {
      kk_datatype_ptr_free(parts, _ctx);
    }
    else {
      kk_string_dup(part, _ctx);
      kk_std_core_types__list_dup(rest, _ctx);
      kk_datatype_ptr_decref(parts, _ctx);
    }
    { // tailcall
      kk_std_core_types__list _x_x709 = kk_std_os_path_push_part(part, dirs, _ctx); /*list<string>*/
      parts = rest;
      dirs = _x_x709;
      goto kk__tailcall;
    }
  }
  {
    return dirs;
  }
}

kk_std_os_path__path kk_std_os_path_path_parts(kk_string_t root, kk_string_t s, kk_std_core_types__optional dirs, kk_context_t* _ctx) { /* (root : string, s : string, dirs : ? (list<string>)) -> path */ 
  kk_vector_t v_10019;
  kk_string_t _x_x710;
  kk_define_string_literal(static, _s_x711, 1, "/", _ctx)
  _x_x710 = kk_string_dup(_s_x711, _ctx); /*string*/
  v_10019 = kk_string_splitv(s,_x_x710,kk_context()); /*vector<string>*/
  kk_std_core_types__list parts_10049 = kk_std_core_vector_vlist(v_10019, kk_std_core_types__new_None(_ctx), _ctx); /*list<string>*/;
  kk_std_core_types__list parts_0;
  if (kk_std_core_types__is_Nil(parts_10049, _ctx)) {
    if (kk_std_core_types__is_Optional(dirs, _ctx)) {
      kk_box_t _box_x87 = dirs._cons._Optional.value;
      kk_std_core_types__list _uniq_dirs_1153 = kk_std_core_types__list_unbox(_box_x87, KK_BORROWED, _ctx);
      kk_std_core_types__list_dup(_uniq_dirs_1153, _ctx);
      kk_std_core_types__optional_drop(dirs, _ctx);
      parts_0 = _uniq_dirs_1153; /*list<string>*/
    }
    else {
      kk_std_core_types__optional_drop(dirs, _ctx);
      parts_0 = kk_std_core_types__new_Nil(_ctx); /*list<string>*/
    }
  }
  else {
    kk_std_core_types__list _x_x712;
    if (kk_std_core_types__is_Optional(dirs, _ctx)) {
      kk_box_t _box_x88 = dirs._cons._Optional.value;
      kk_std_core_types__list _uniq_dirs_1153_0 = kk_std_core_types__list_unbox(_box_x88, KK_BORROWED, _ctx);
      kk_std_core_types__list_dup(_uniq_dirs_1153_0, _ctx);
      kk_std_core_types__optional_drop(dirs, _ctx);
      _x_x712 = _uniq_dirs_1153_0; /*list<string>*/
    }
    else {
      kk_std_core_types__optional_drop(dirs, _ctx);
      _x_x712 = kk_std_core_types__new_Nil(_ctx); /*list<string>*/
    }
    parts_0 = kk_std_os_path__unroll_push_parts_10000(parts_10049, _x_x712, _ctx); /*list<string>*/
  }
  return kk_std_os_path__new_Path(root, parts_0, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_os_path__mlift_proot_10386_fun714__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path__mlift_proot_10386_fun714(kk_function_t _fself, kk_box_t _b_x90, kk_context_t* _ctx);
static kk_function_t kk_std_os_path__new_mlift_proot_10386_fun714(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path__mlift_proot_10386_fun714, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_path__mlift_proot_10386_fun714(kk_function_t _fself, kk_box_t _b_x90, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  bool _x_x715;
  kk_char_t _x_x716 = kk_char_unbox(_b_x90, KK_OWNED, _ctx); /*char*/
  _x_x715 = kk_std_os_path__mlift_proot_10384(_x_x716, _ctx); /*bool*/
  return kk_bool_box(_x_x715);
}


// lift anonymous function
struct kk_std_os_path__mlift_proot_10386_fun718__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path__mlift_proot_10386_fun718(kk_function_t _fself, kk_box_t _b_x92, kk_context_t* _ctx);
static kk_function_t kk_std_os_path__new_mlift_proot_10386_fun718(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path__mlift_proot_10386_fun718, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_path__mlift_proot_10386_fun718(kk_function_t _fself, kk_box_t _b_x92, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  bool _x_x719;
  kk_unit_t _x_x720 = kk_Unit;
  kk_unit_unbox(_b_x92);
  _x_x719 = kk_std_os_path__mlift_proot_10385(_x_x720, _ctx); /*bool*/
  return kk_bool_box(_x_x719);
}

bool kk_std_os_path__mlift_proot_10386(bool _y_x10328, kk_context_t* _ctx) { /* (bool) -> std/text/parse/parse bool */ 
  if (_y_x10328) {
    kk_char_t x_10411 = kk_std_text_parse_char('/', _ctx); /*char*/;
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x713 = kk_std_core_hnd_yield_extend(kk_std_os_path__new_mlift_proot_10386_fun714(_ctx), _ctx); /*2419*/
      return kk_bool_unbox(_x_x713);
    }
    {
      return false;
    }
  }
  {
    kk_unit_t x_0_10413 = kk_Unit;
    kk_std_text_parse_eof(_ctx);
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x717 = kk_std_core_hnd_yield_extend(kk_std_os_path__new_mlift_proot_10386_fun718(_ctx), _ctx); /*2419*/
      return kk_bool_unbox(_x_x717);
    }
    {
      return true;
    }
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_os_path__mlift_proot_10388_fun722__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path__mlift_proot_10388_fun722(kk_function_t _fself, kk_box_t _b_x96, kk_context_t* _ctx);
static kk_function_t kk_std_os_path__new_mlift_proot_10388_fun722(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path__mlift_proot_10388_fun722, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_path__mlift_proot_10388_fun722(kk_function_t _fself, kk_box_t _b_x96, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x723 = kk_Unit;
  kk_char_t _x_x724 = kk_char_unbox(_b_x96, KK_OWNED, _ctx); /*char*/
  kk_std_os_path__mlift_proot_10387(_x_x724, _ctx);
  return kk_unit_box(_x_x723);
}

kk_unit_t kk_std_os_path__mlift_proot_10388(kk_char_t wild__, kk_context_t* _ctx) { /* (wild_ : char) -> std/text/parse/parse () */ 
  kk_char_t x_10415 = kk_std_text_parse_char(':', _ctx); /*char*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x721 = kk_std_core_hnd_yield_extend(kk_std_os_path__new_mlift_proot_10388_fun722(_ctx), _ctx); /*2419*/
    kk_unit_unbox(_x_x721); return kk_Unit;
  }
  {
    kk_Unit; return kk_Unit;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_os_path__mlift_proot_10390_fun725__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path__mlift_proot_10390_fun725(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_os_path__new_mlift_proot_10390_fun725(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path__mlift_proot_10390_fun725, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_path__mlift_proot_10390_fun725(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t _x_x726;
  kk_string_t _x_x727;
  kk_define_string_literal(static, _s_x728, 1, "/", _ctx)
  _x_x727 = kk_string_dup(_s_x728, _ctx); /*string*/
  _x_x726 = kk_std_text_parse_none_of(_x_x727, _ctx); /*char*/
  return kk_char_box(_x_x726, _ctx);
}


// lift anonymous function
struct kk_std_os_path__mlift_proot_10390_fun730__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path__mlift_proot_10390_fun730(kk_function_t _fself, kk_box_t _b_x103, kk_context_t* _ctx);
static kk_function_t kk_std_os_path__new_mlift_proot_10390_fun730(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path__mlift_proot_10390_fun730, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_path__mlift_proot_10390_fun730(kk_function_t _fself, kk_box_t _b_x103, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x731 = kk_Unit;
  kk_std_core_types__list _x_x732 = kk_std_core_types__list_unbox(_b_x103, KK_OWNED, _ctx); /*list<char>*/
  kk_std_os_path__mlift_proot_10389(_x_x732, _ctx);
  return kk_unit_box(_x_x731);
}

kk_unit_t kk_std_os_path__mlift_proot_10390(kk_char_t _y_x10324, kk_context_t* _ctx) { /* (char) -> std/text/parse/parse () */ 
  kk_std_core_types__list x_10417 = kk_std_text_parse_many_acc(kk_std_os_path__new_mlift_proot_10390_fun725(_ctx), kk_std_core_types__new_Nil(_ctx), _ctx); /*list<char>*/;
  kk_std_core_types__list_drop(x_10417, _ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x729 = kk_std_core_hnd_yield_extend(kk_std_os_path__new_mlift_proot_10390_fun730(_ctx), _ctx); /*2419*/
    kk_unit_unbox(_x_x729); return kk_Unit;
  }
  {
    kk_Unit; return kk_Unit;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_os_path__mlift_proot_10391_fun736__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path__mlift_proot_10391_fun736(kk_function_t _fself, kk_box_t _b_x106, kk_context_t* _ctx);
static kk_function_t kk_std_os_path__new_mlift_proot_10391_fun736(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path__mlift_proot_10391_fun736, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_path__mlift_proot_10391_fun736(kk_function_t _fself, kk_box_t _b_x106, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x737 = kk_Unit;
  kk_char_t _x_x738 = kk_char_unbox(_b_x106, KK_OWNED, _ctx); /*char*/
  kk_std_os_path__mlift_proot_10390(_x_x738, _ctx);
  return kk_unit_box(_x_x737);
}

kk_unit_t kk_std_os_path__mlift_proot_10391(kk_char_t wild___1, kk_context_t* _ctx) { /* (wild_@1 : char) -> std/text/parse/parse () */ 
  kk_char_t x_10419;
  kk_string_t _x_x733;
  kk_define_string_literal(static, _s_x734, 1, "/", _ctx)
  _x_x733 = kk_string_dup(_s_x734, _ctx); /*string*/
  x_10419 = kk_std_text_parse_none_of(_x_x733, _ctx); /*char*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x735 = kk_std_core_hnd_yield_extend(kk_std_os_path__new_mlift_proot_10391_fun736(_ctx), _ctx); /*2419*/
    kk_unit_unbox(_x_x735); return kk_Unit;
  }
  {
    kk_std_os_path__mlift_proot_10390(x_10419, _ctx); return kk_Unit;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_os_path__mlift_proot_10392_fun742__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path__mlift_proot_10392_fun742(kk_function_t _fself, kk_box_t _b_x115, kk_context_t* _ctx);
static kk_function_t kk_std_os_path__new_mlift_proot_10392_fun742(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path__mlift_proot_10392_fun742, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_path__mlift_proot_10392_fun742(kk_function_t _fself, kk_box_t _b_x115, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  bool _x_x743;
  bool _x_x744 = kk_bool_unbox(_b_x115); /*bool*/
  _x_x743 = kk_std_os_path__mlift_proot_10386(_x_x744, _ctx); /*bool*/
  return kk_bool_box(_x_x743);
}

bool kk_std_os_path__mlift_proot_10392(kk_unit_t _c_x10327, kk_context_t* _ctx) { /* (()) -> bool */ 
  kk_std_core_hnd__ev ev_10423 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
  bool x_10421;
  kk_box_t _x_x739;
  {
    struct kk_std_core_hnd_Ev* _con_x740 = kk_std_core_hnd__as_Ev(ev_10423, _ctx);
    kk_box_t _box_x108 = _con_x740->hnd;
    int32_t m = _con_x740->marker;
    kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x108, KK_BORROWED, _ctx);
    kk_std_text_parse__parse_dup(h, _ctx);
    kk_std_core_hnd__clause0 _match_x510;
    kk_std_core_hnd__clause0 _brw_x511 = kk_std_text_parse_pick_fs__select(h, _ctx); /*hnd/clause0<bool,std/text/parse/parse,729,730>*/;
    kk_datatype_ptr_dropn(h, (KK_I32(5)), _ctx);
    _match_x510 = _brw_x511; /*hnd/clause0<bool,std/text/parse/parse,729,730>*/
    {
      kk_function_t _fun_unbox_x111 = _match_x510.clause;
      _x_x739 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x111, (_fun_unbox_x111, m, ev_10423, _ctx), _ctx); /*35*/
    }
  }
  x_10421 = kk_bool_unbox(_x_x739); /*bool*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x741 = kk_std_core_hnd_yield_extend(kk_std_os_path__new_mlift_proot_10392_fun742(_ctx), _ctx); /*2419*/
    return kk_bool_unbox(_x_x741);
  }
  {
    return kk_std_os_path__mlift_proot_10386(x_10421, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_os_path__mlift_proot_10393_fun746__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path__mlift_proot_10393_fun746(kk_function_t _fself, kk_box_t _b_x118, kk_context_t* _ctx);
static kk_function_t kk_std_os_path__new_mlift_proot_10393_fun746(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path__mlift_proot_10393_fun746, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_path__mlift_proot_10393_fun746(kk_function_t _fself, kk_box_t _b_x118, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x747 = kk_Unit;
  kk_char_t _x_x748 = kk_char_unbox(_b_x118, KK_OWNED, _ctx); /*char*/
  kk_std_os_path__mlift_proot_10388(_x_x748, _ctx);
  return kk_unit_box(_x_x747);
}


// lift anonymous function
struct kk_std_os_path__mlift_proot_10393_fun750__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path__mlift_proot_10393_fun750(kk_function_t _fself, kk_box_t _b_x120, kk_context_t* _ctx);
static kk_function_t kk_std_os_path__new_mlift_proot_10393_fun750(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path__mlift_proot_10393_fun750, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_path__mlift_proot_10393_fun750(kk_function_t _fself, kk_box_t _b_x120, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x751 = kk_Unit;
  kk_char_t _x_x752 = kk_char_unbox(_b_x120, KK_OWNED, _ctx); /*char*/
  kk_std_os_path__mlift_proot_10391(_x_x752, _ctx);
  return kk_unit_box(_x_x751);
}


// lift anonymous function
struct kk_std_os_path__mlift_proot_10393_fun754__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path__mlift_proot_10393_fun754(kk_function_t _fself, kk_box_t _b_x124, kk_context_t* _ctx);
static kk_function_t kk_std_os_path__new_mlift_proot_10393_fun754(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path__mlift_proot_10393_fun754, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_path__mlift_proot_10393_fun754(kk_function_t _fself, kk_box_t _b_x124, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  bool _x_x755;
  kk_unit_t _x_x756 = kk_Unit;
  kk_unit_unbox(_b_x124);
  _x_x755 = kk_std_os_path__mlift_proot_10392(_x_x756, _ctx); /*bool*/
  return kk_bool_box(_x_x755);
}

bool kk_std_os_path__mlift_proot_10393(bool _y_x10320, kk_context_t* _ctx) { /* (bool) -> std/text/parse/parse bool */ 
  kk_unit_t x_10425 = kk_Unit;
  if (_y_x10320) {
    kk_char_t x_0_10427 = kk_std_text_parse_alpha(_ctx); /*char*/;
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x745 = kk_std_core_hnd_yield_extend(kk_std_os_path__new_mlift_proot_10393_fun746(_ctx), _ctx); /*2419*/
      kk_unit_unbox(_x_x745);
    }
    else {
      kk_std_os_path__mlift_proot_10388(x_0_10427, _ctx);
    }
  }
  else {
    kk_char_t x_1_10429 = kk_std_text_parse_char('/', _ctx); /*char*/;
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x749 = kk_std_core_hnd_yield_extend(kk_std_os_path__new_mlift_proot_10393_fun750(_ctx), _ctx); /*2419*/
      kk_unit_unbox(_x_x749);
    }
    else {
      kk_std_os_path__mlift_proot_10391(x_1_10429, _ctx);
    }
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x753 = kk_std_core_hnd_yield_extend(kk_std_os_path__new_mlift_proot_10393_fun754(_ctx), _ctx); /*2419*/
    return kk_bool_unbox(_x_x753);
  }
  {
    return kk_std_os_path__mlift_proot_10392(x_10425, _ctx);
  }
}


// lift anonymous function
struct kk_std_os_path_proot_fun760__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_proot_fun760(kk_function_t _fself, kk_box_t _b_x133, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_proot_fun760(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_proot_fun760, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_path_proot_fun760(kk_function_t _fself, kk_box_t _b_x133, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  bool _x_x761;
  bool _x_x762 = kk_bool_unbox(_b_x133); /*bool*/
  _x_x761 = kk_std_os_path__mlift_proot_10393(_x_x762, _ctx); /*bool*/
  return kk_bool_box(_x_x761);
}


// lift anonymous function
struct kk_std_os_path_proot_fun764__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_proot_fun764(kk_function_t _fself, kk_box_t _b_x135, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_proot_fun764(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_proot_fun764, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_path_proot_fun764(kk_function_t _fself, kk_box_t _b_x135, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x765 = kk_Unit;
  kk_char_t _x_x766 = kk_char_unbox(_b_x135, KK_OWNED, _ctx); /*char*/
  kk_std_os_path__mlift_proot_10388(_x_x766, _ctx);
  return kk_unit_box(_x_x765);
}


// lift anonymous function
struct kk_std_os_path_proot_fun768__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_proot_fun768(kk_function_t _fself, kk_box_t _b_x137, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_proot_fun768(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_proot_fun768, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_path_proot_fun768(kk_function_t _fself, kk_box_t _b_x137, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x769 = kk_Unit;
  kk_char_t _x_x770 = kk_char_unbox(_b_x137, KK_OWNED, _ctx); /*char*/
  kk_std_os_path__mlift_proot_10391(_x_x770, _ctx);
  return kk_unit_box(_x_x769);
}


// lift anonymous function
struct kk_std_os_path_proot_fun772__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_proot_fun772(kk_function_t _fself, kk_box_t _b_x141, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_proot_fun772(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_proot_fun772, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_path_proot_fun772(kk_function_t _fself, kk_box_t _b_x141, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  bool _x_x773;
  kk_unit_t _x_x774 = kk_Unit;
  kk_unit_unbox(_b_x141);
  _x_x773 = kk_std_os_path__mlift_proot_10392(_x_x774, _ctx); /*bool*/
  return kk_bool_box(_x_x773);
}


// lift anonymous function
struct kk_std_os_path_proot_fun778__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_proot_fun778(kk_function_t _fself, kk_box_t _b_x149, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_proot_fun778(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_proot_fun778, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_path_proot_fun778(kk_function_t _fself, kk_box_t _b_x149, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  bool _x_x779;
  bool _x_x780 = kk_bool_unbox(_b_x149); /*bool*/
  _x_x779 = kk_std_os_path__mlift_proot_10386(_x_x780, _ctx); /*bool*/
  return kk_bool_box(_x_x779);
}


// lift anonymous function
struct kk_std_os_path_proot_fun782__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_proot_fun782(kk_function_t _fself, kk_box_t _b_x151, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_proot_fun782(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_proot_fun782, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_path_proot_fun782(kk_function_t _fself, kk_box_t _b_x151, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  bool _x_x783;
  kk_char_t _x_x784 = kk_char_unbox(_b_x151, KK_OWNED, _ctx); /*char*/
  _x_x783 = kk_std_os_path__mlift_proot_10384(_x_x784, _ctx); /*bool*/
  return kk_bool_box(_x_x783);
}


// lift anonymous function
struct kk_std_os_path_proot_fun786__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_proot_fun786(kk_function_t _fself, kk_box_t _b_x153, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_proot_fun786(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_proot_fun786, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_path_proot_fun786(kk_function_t _fself, kk_box_t _b_x153, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  bool _x_x787;
  kk_unit_t _x_x788 = kk_Unit;
  kk_unit_unbox(_b_x153);
  _x_x787 = kk_std_os_path__mlift_proot_10385(_x_x788, _ctx); /*bool*/
  return kk_bool_box(_x_x787);
}

bool kk_std_os_path_proot(kk_context_t* _ctx) { /* () -> std/text/parse/parse bool */ 
  kk_std_core_hnd__ev ev_10434 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
  bool x_10431;
  kk_box_t _x_x757;
  {
    struct kk_std_core_hnd_Ev* _con_x758 = kk_std_core_hnd__as_Ev(ev_10434, _ctx);
    kk_box_t _box_x126 = _con_x758->hnd;
    int32_t m = _con_x758->marker;
    kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x126, KK_BORROWED, _ctx);
    kk_std_text_parse__parse_dup(h, _ctx);
    kk_std_core_hnd__clause0 _match_x504;
    kk_std_core_hnd__clause0 _brw_x505 = kk_std_text_parse_pick_fs__select(h, _ctx); /*hnd/clause0<bool,std/text/parse/parse,729,730>*/;
    kk_datatype_ptr_dropn(h, (KK_I32(5)), _ctx);
    _match_x504 = _brw_x505; /*hnd/clause0<bool,std/text/parse/parse,729,730>*/
    {
      kk_function_t _fun_unbox_x129 = _match_x504.clause;
      _x_x757 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x129, (_fun_unbox_x129, m, ev_10434, _ctx), _ctx); /*35*/
    }
  }
  x_10431 = kk_bool_unbox(_x_x757); /*bool*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x759 = kk_std_core_hnd_yield_extend(kk_std_os_path_new_proot_fun760(_ctx), _ctx); /*2419*/
    return kk_bool_unbox(_x_x759);
  }
  {
    kk_unit_t x_0_10436 = kk_Unit;
    if (x_10431) {
      kk_char_t x_1_10439 = kk_std_text_parse_alpha(_ctx); /*char*/;
      if (kk_yielding(kk_context())) {
        kk_box_t _x_x763 = kk_std_core_hnd_yield_extend(kk_std_os_path_new_proot_fun764(_ctx), _ctx); /*2419*/
        kk_unit_unbox(_x_x763);
      }
      else {
        kk_std_os_path__mlift_proot_10388(x_1_10439, _ctx);
      }
    }
    else {
      kk_char_t x_2_10441 = kk_std_text_parse_char('/', _ctx); /*char*/;
      if (kk_yielding(kk_context())) {
        kk_box_t _x_x767 = kk_std_core_hnd_yield_extend(kk_std_os_path_new_proot_fun768(_ctx), _ctx); /*2419*/
        kk_unit_unbox(_x_x767);
      }
      else {
        kk_std_os_path__mlift_proot_10391(x_2_10441, _ctx);
      }
    }
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x771 = kk_std_core_hnd_yield_extend(kk_std_os_path_new_proot_fun772(_ctx), _ctx); /*2419*/
      return kk_bool_unbox(_x_x771);
    }
    {
      kk_std_core_hnd__ev ev_0_10446 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
      bool x_3_10443;
      kk_box_t _x_x775;
      {
        struct kk_std_core_hnd_Ev* _con_x776 = kk_std_core_hnd__as_Ev(ev_0_10446, _ctx);
        kk_box_t _box_x142 = _con_x776->hnd;
        int32_t m_0 = _con_x776->marker;
        kk_std_text_parse__parse h_0 = kk_std_text_parse__parse_unbox(_box_x142, KK_BORROWED, _ctx);
        kk_std_text_parse__parse_dup(h_0, _ctx);
        kk_std_core_hnd__clause0 _match_x500;
        kk_std_core_hnd__clause0 _brw_x501 = kk_std_text_parse_pick_fs__select(h_0, _ctx); /*hnd/clause0<bool,std/text/parse/parse,729,730>*/;
        kk_datatype_ptr_dropn(h_0, (KK_I32(5)), _ctx);
        _match_x500 = _brw_x501; /*hnd/clause0<bool,std/text/parse/parse,729,730>*/
        {
          kk_function_t _fun_unbox_x145 = _match_x500.clause;
          _x_x775 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x145, (_fun_unbox_x145, m_0, ev_0_10446, _ctx), _ctx); /*35*/
        }
      }
      x_3_10443 = kk_bool_unbox(_x_x775); /*bool*/
      if (kk_yielding(kk_context())) {
        kk_box_t _x_x777 = kk_std_core_hnd_yield_extend(kk_std_os_path_new_proot_fun778(_ctx), _ctx); /*2419*/
        return kk_bool_unbox(_x_x777);
      }
      if (x_3_10443) {
        kk_char_t x_4_10448 = kk_std_text_parse_char('/', _ctx); /*char*/;
        if (kk_yielding(kk_context())) {
          kk_box_t _x_x781 = kk_std_core_hnd_yield_extend(kk_std_os_path_new_proot_fun782(_ctx), _ctx); /*2419*/
          return kk_bool_unbox(_x_x781);
        }
        {
          return false;
        }
      }
      {
        kk_unit_t x_5_10451 = kk_Unit;
        kk_std_text_parse_eof(_ctx);
        if (kk_yielding(kk_context())) {
          kk_box_t _x_x785 = kk_std_core_hnd_yield_extend(kk_std_os_path_new_proot_fun786(_ctx), _ctx); /*2419*/
          return kk_bool_unbox(_x_x785);
        }
        {
          return true;
        }
      }
    }
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_os_path__mlift_path_10396_fun790__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path__mlift_path_10396_fun790(kk_function_t _fself, kk_box_t _b_x160, kk_context_t* _ctx);
static kk_function_t kk_std_os_path__new_mlift_path_10396_fun790(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path__mlift_path_10396_fun790, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_path__mlift_path_10396_fun790(kk_function_t _fself, kk_box_t _b_x160, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  bool _x_x791;
  kk_char_t _x_x792 = kk_char_unbox(_b_x160, KK_OWNED, _ctx); /*char*/
  _x_x791 = kk_std_os_path__mlift_path_10394(_x_x792, _ctx); /*bool*/
  return kk_bool_box(_x_x791);
}


// lift anonymous function
struct kk_std_os_path__mlift_path_10396_fun794__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path__mlift_path_10396_fun794(kk_function_t _fself, kk_box_t _b_x162, kk_context_t* _ctx);
static kk_function_t kk_std_os_path__new_mlift_path_10396_fun794(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path__mlift_path_10396_fun794, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_path__mlift_path_10396_fun794(kk_function_t _fself, kk_box_t _b_x162, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  bool _x_x795;
  kk_unit_t _x_x796 = kk_Unit;
  kk_unit_unbox(_b_x162);
  _x_x795 = kk_std_os_path__mlift_path_10395(_x_x796, _ctx); /*bool*/
  return kk_bool_box(_x_x795);
}

bool kk_std_os_path__mlift_path_10396(bool _y_x10340, kk_context_t* _ctx) { /* (bool) -> std/text/parse/parse bool */ 
  if (_y_x10340) {
    kk_char_t x_10454 = kk_std_text_parse_char('/', _ctx); /*char*/;
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x789 = kk_std_core_hnd_yield_extend(kk_std_os_path__new_mlift_path_10396_fun790(_ctx), _ctx); /*2419*/
      return kk_bool_unbox(_x_x789);
    }
    {
      return false;
    }
  }
  {
    kk_unit_t x_0_10456 = kk_Unit;
    kk_std_text_parse_eof(_ctx);
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x793 = kk_std_core_hnd_yield_extend(kk_std_os_path__new_mlift_path_10396_fun794(_ctx), _ctx); /*2419*/
      return kk_bool_unbox(_x_x793);
    }
    {
      return true;
    }
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_os_path__mlift_path_10398_fun798__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path__mlift_path_10398_fun798(kk_function_t _fself, kk_box_t _b_x166, kk_context_t* _ctx);
static kk_function_t kk_std_os_path__new_mlift_path_10398_fun798(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path__mlift_path_10398_fun798, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_path__mlift_path_10398_fun798(kk_function_t _fself, kk_box_t _b_x166, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x799 = kk_Unit;
  kk_char_t _x_x800 = kk_char_unbox(_b_x166, KK_OWNED, _ctx); /*char*/
  kk_std_os_path__mlift_path_10397(_x_x800, _ctx);
  return kk_unit_box(_x_x799);
}

kk_unit_t kk_std_os_path__mlift_path_10398(kk_char_t wild__, kk_context_t* _ctx) { /* (wild_ : char) -> std/text/parse/parse () */ 
  kk_char_t x_10458 = kk_std_text_parse_char(':', _ctx); /*char*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x797 = kk_std_core_hnd_yield_extend(kk_std_os_path__new_mlift_path_10398_fun798(_ctx), _ctx); /*2419*/
    kk_unit_unbox(_x_x797); return kk_Unit;
  }
  {
    kk_Unit; return kk_Unit;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_os_path__mlift_path_10400_fun801__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path__mlift_path_10400_fun801(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_os_path__new_mlift_path_10400_fun801(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path__mlift_path_10400_fun801, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_path__mlift_path_10400_fun801(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_char_t _x_x802;
  kk_string_t _x_x803;
  kk_define_string_literal(static, _s_x804, 1, "/", _ctx)
  _x_x803 = kk_string_dup(_s_x804, _ctx); /*string*/
  _x_x802 = kk_std_text_parse_none_of(_x_x803, _ctx); /*char*/
  return kk_char_box(_x_x802, _ctx);
}


// lift anonymous function
struct kk_std_os_path__mlift_path_10400_fun806__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path__mlift_path_10400_fun806(kk_function_t _fself, kk_box_t _b_x173, kk_context_t* _ctx);
static kk_function_t kk_std_os_path__new_mlift_path_10400_fun806(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path__mlift_path_10400_fun806, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_path__mlift_path_10400_fun806(kk_function_t _fself, kk_box_t _b_x173, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x807 = kk_Unit;
  kk_std_core_types__list _x_x808 = kk_std_core_types__list_unbox(_b_x173, KK_OWNED, _ctx); /*list<char>*/
  kk_std_os_path__mlift_path_10399(_x_x808, _ctx);
  return kk_unit_box(_x_x807);
}

kk_unit_t kk_std_os_path__mlift_path_10400(kk_char_t _y_x10336, kk_context_t* _ctx) { /* (char) -> std/text/parse/parse () */ 
  kk_std_core_types__list x_10460 = kk_std_text_parse_many_acc(kk_std_os_path__new_mlift_path_10400_fun801(_ctx), kk_std_core_types__new_Nil(_ctx), _ctx); /*list<char>*/;
  kk_std_core_types__list_drop(x_10460, _ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x805 = kk_std_core_hnd_yield_extend(kk_std_os_path__new_mlift_path_10400_fun806(_ctx), _ctx); /*2419*/
    kk_unit_unbox(_x_x805); return kk_Unit;
  }
  {
    kk_Unit; return kk_Unit;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_os_path__mlift_path_10401_fun812__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path__mlift_path_10401_fun812(kk_function_t _fself, kk_box_t _b_x176, kk_context_t* _ctx);
static kk_function_t kk_std_os_path__new_mlift_path_10401_fun812(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path__mlift_path_10401_fun812, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_path__mlift_path_10401_fun812(kk_function_t _fself, kk_box_t _b_x176, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x813 = kk_Unit;
  kk_char_t _x_x814 = kk_char_unbox(_b_x176, KK_OWNED, _ctx); /*char*/
  kk_std_os_path__mlift_path_10400(_x_x814, _ctx);
  return kk_unit_box(_x_x813);
}

kk_unit_t kk_std_os_path__mlift_path_10401(kk_char_t wild___1, kk_context_t* _ctx) { /* (wild_@1 : char) -> std/text/parse/parse () */ 
  kk_char_t x_10462;
  kk_string_t _x_x809;
  kk_define_string_literal(static, _s_x810, 1, "/", _ctx)
  _x_x809 = kk_string_dup(_s_x810, _ctx); /*string*/
  x_10462 = kk_std_text_parse_none_of(_x_x809, _ctx); /*char*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x811 = kk_std_core_hnd_yield_extend(kk_std_os_path__new_mlift_path_10401_fun812(_ctx), _ctx); /*2419*/
    kk_unit_unbox(_x_x811); return kk_Unit;
  }
  {
    kk_std_os_path__mlift_path_10400(x_10462, _ctx); return kk_Unit;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_os_path__mlift_path_10402_fun818__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path__mlift_path_10402_fun818(kk_function_t _fself, kk_box_t _b_x185, kk_context_t* _ctx);
static kk_function_t kk_std_os_path__new_mlift_path_10402_fun818(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path__mlift_path_10402_fun818, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_path__mlift_path_10402_fun818(kk_function_t _fself, kk_box_t _b_x185, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  bool _x_x819;
  bool _x_x820 = kk_bool_unbox(_b_x185); /*bool*/
  _x_x819 = kk_std_os_path__mlift_path_10396(_x_x820, _ctx); /*bool*/
  return kk_bool_box(_x_x819);
}

bool kk_std_os_path__mlift_path_10402(kk_unit_t _c_x10339, kk_context_t* _ctx) { /* (()) -> bool */ 
  kk_std_core_hnd__ev ev_10466 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
  bool x_10464;
  kk_box_t _x_x815;
  {
    struct kk_std_core_hnd_Ev* _con_x816 = kk_std_core_hnd__as_Ev(ev_10466, _ctx);
    kk_box_t _box_x178 = _con_x816->hnd;
    int32_t m = _con_x816->marker;
    kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x178, KK_BORROWED, _ctx);
    kk_std_text_parse__parse_dup(h, _ctx);
    kk_std_core_hnd__clause0 _match_x488;
    kk_std_core_hnd__clause0 _brw_x489 = kk_std_text_parse_pick_fs__select(h, _ctx); /*hnd/clause0<bool,std/text/parse/parse,729,730>*/;
    kk_datatype_ptr_dropn(h, (KK_I32(5)), _ctx);
    _match_x488 = _brw_x489; /*hnd/clause0<bool,std/text/parse/parse,729,730>*/
    {
      kk_function_t _fun_unbox_x181 = _match_x488.clause;
      _x_x815 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x181, (_fun_unbox_x181, m, ev_10466, _ctx), _ctx); /*35*/
    }
  }
  x_10464 = kk_bool_unbox(_x_x815); /*bool*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x817 = kk_std_core_hnd_yield_extend(kk_std_os_path__new_mlift_path_10402_fun818(_ctx), _ctx); /*2419*/
    return kk_bool_unbox(_x_x817);
  }
  {
    return kk_std_os_path__mlift_path_10396(x_10464, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_std_os_path__mlift_path_10403_fun822__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path__mlift_path_10403_fun822(kk_function_t _fself, kk_box_t _b_x188, kk_context_t* _ctx);
static kk_function_t kk_std_os_path__new_mlift_path_10403_fun822(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path__mlift_path_10403_fun822, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_path__mlift_path_10403_fun822(kk_function_t _fself, kk_box_t _b_x188, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x823 = kk_Unit;
  kk_char_t _x_x824 = kk_char_unbox(_b_x188, KK_OWNED, _ctx); /*char*/
  kk_std_os_path__mlift_path_10398(_x_x824, _ctx);
  return kk_unit_box(_x_x823);
}


// lift anonymous function
struct kk_std_os_path__mlift_path_10403_fun826__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path__mlift_path_10403_fun826(kk_function_t _fself, kk_box_t _b_x190, kk_context_t* _ctx);
static kk_function_t kk_std_os_path__new_mlift_path_10403_fun826(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path__mlift_path_10403_fun826, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_path__mlift_path_10403_fun826(kk_function_t _fself, kk_box_t _b_x190, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_unit_t _x_x827 = kk_Unit;
  kk_char_t _x_x828 = kk_char_unbox(_b_x190, KK_OWNED, _ctx); /*char*/
  kk_std_os_path__mlift_path_10401(_x_x828, _ctx);
  return kk_unit_box(_x_x827);
}


// lift anonymous function
struct kk_std_os_path__mlift_path_10403_fun830__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path__mlift_path_10403_fun830(kk_function_t _fself, kk_box_t _b_x194, kk_context_t* _ctx);
static kk_function_t kk_std_os_path__new_mlift_path_10403_fun830(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path__mlift_path_10403_fun830, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_path__mlift_path_10403_fun830(kk_function_t _fself, kk_box_t _b_x194, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  bool _x_x831;
  kk_unit_t _x_x832 = kk_Unit;
  kk_unit_unbox(_b_x194);
  _x_x831 = kk_std_os_path__mlift_path_10402(_x_x832, _ctx); /*bool*/
  return kk_bool_box(_x_x831);
}

bool kk_std_os_path__mlift_path_10403(bool _y_x10332, kk_context_t* _ctx) { /* (bool) -> std/text/parse/parse bool */ 
  kk_unit_t x_10468 = kk_Unit;
  if (_y_x10332) {
    kk_char_t x_0_10470 = kk_std_text_parse_alpha(_ctx); /*char*/;
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x821 = kk_std_core_hnd_yield_extend(kk_std_os_path__new_mlift_path_10403_fun822(_ctx), _ctx); /*2419*/
      kk_unit_unbox(_x_x821);
    }
    else {
      kk_std_os_path__mlift_path_10398(x_0_10470, _ctx);
    }
  }
  else {
    kk_char_t x_1_10472 = kk_std_text_parse_char('/', _ctx); /*char*/;
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x825 = kk_std_core_hnd_yield_extend(kk_std_os_path__new_mlift_path_10403_fun826(_ctx), _ctx); /*2419*/
      kk_unit_unbox(_x_x825);
    }
    else {
      kk_std_os_path__mlift_path_10401(x_1_10472, _ctx);
    }
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x829 = kk_std_core_hnd_yield_extend(kk_std_os_path__new_mlift_path_10403_fun830(_ctx), _ctx); /*2419*/
    return kk_bool_unbox(_x_x829);
  }
  {
    return kk_std_os_path__mlift_path_10402(x_10468, _ctx);
  }
}
 
// Create a normalized `:path` from a path string.


// lift anonymous function
struct kk_std_os_path_path_fun843__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_path_fun843(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_path_fun843(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_path_fun843, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_std_os_path_path_fun848__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_path_fun848(kk_function_t _fself, kk_box_t _b_x203, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_path_fun848(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_path_fun848, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_path_path_fun848(kk_function_t _fself, kk_box_t _b_x203, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  bool _x_x849;
  bool _x_x850 = kk_bool_unbox(_b_x203); /*bool*/
  _x_x849 = kk_std_os_path__mlift_path_10403(_x_x850, _ctx); /*bool*/
  return kk_bool_box(_x_x849);
}
static kk_box_t kk_std_os_path_path_fun843(kk_function_t _fself, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  bool _x_x844;
  kk_std_core_hnd__ev ev_10476 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<std/text/parse/parse>*/;
  bool x_10474;
  kk_box_t _x_x845;
  {
    struct kk_std_core_hnd_Ev* _con_x846 = kk_std_core_hnd__as_Ev(ev_10476, _ctx);
    kk_box_t _box_x196 = _con_x846->hnd;
    int32_t m = _con_x846->marker;
    kk_std_text_parse__parse h = kk_std_text_parse__parse_unbox(_box_x196, KK_BORROWED, _ctx);
    kk_std_text_parse__parse_dup(h, _ctx);
    kk_std_core_hnd__clause0 _match_x482;
    kk_std_core_hnd__clause0 _brw_x483 = kk_std_text_parse_pick_fs__select(h, _ctx); /*hnd/clause0<bool,std/text/parse/parse,729,730>*/;
    kk_datatype_ptr_dropn(h, (KK_I32(5)), _ctx);
    _match_x482 = _brw_x483; /*hnd/clause0<bool,std/text/parse/parse,729,730>*/
    {
      kk_function_t _fun_unbox_x199 = _match_x482.clause;
      _x_x845 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_context_t*), _fun_unbox_x199, (_fun_unbox_x199, m, ev_10476, _ctx), _ctx); /*35*/
    }
  }
  x_10474 = kk_bool_unbox(_x_x845); /*bool*/
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x847 = kk_std_core_hnd_yield_extend(kk_std_os_path_new_path_fun848(_ctx), _ctx); /*2419*/
    _x_x844 = kk_bool_unbox(_x_x847); /*bool*/
  }
  else {
    _x_x844 = kk_std_os_path__mlift_path_10403(x_10474, _ctx); /*bool*/
  }
  return kk_bool_box(_x_x844);
}

kk_std_os_path__path kk_std_os_path_path(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> path */ 
  bool _match_x475;
  kk_string_t _x_x833 = kk_string_dup(s, _ctx); /*string*/
  kk_string_t _x_x834 = kk_string_empty(); /*string*/
  _match_x475 = kk_string_is_eq(_x_x833,_x_x834,kk_context()); /*bool*/
  if (_match_x475) {
    kk_string_drop(s, _ctx);
    kk_string_t _x_x836 = kk_string_empty(); /*string*/
    return kk_std_os_path__new_Path(_x_x836, kk_std_core_types__new_Nil(_ctx), _ctx);
  }
  {
    kk_string_t t;
    kk_string_t _x_x838;
    kk_define_string_literal(static, _s_x839, 1, "\\", _ctx)
    _x_x838 = kk_string_dup(_s_x839, _ctx); /*string*/
    kk_string_t _x_x840;
    kk_define_string_literal(static, _s_x841, 1, "/", _ctx)
    _x_x840 = kk_string_dup(_s_x841, _ctx); /*string*/
    t = kk_string_replace_all(s,_x_x838,_x_x840,kk_context()); /*string*/
    kk_std_core_types__maybe _match_x476;
    kk_string_t _x_x842 = kk_string_dup(t, _ctx); /*string*/
    _match_x476 = kk_std_text_parse_starts_with(_x_x842, kk_std_os_path_new_path_fun843(_ctx), _ctx); /*maybe<(1515, sslice/sslice)>*/
    if (kk_std_core_types__is_Nothing(_match_x476, _ctx)) {
      kk_vector_t v_10019;
      kk_string_t _x_x851;
      kk_define_string_literal(static, _s_x852, 1, "/", _ctx)
      _x_x851 = kk_string_dup(_s_x852, _ctx); /*string*/
      v_10019 = kk_string_splitv(t,_x_x851,kk_context()); /*vector<string>*/
      kk_std_core_types__list parts_0_10066 = kk_std_core_vector_vlist(v_10019, kk_std_core_types__new_None(_ctx), _ctx); /*list<string>*/;
      kk_std_core_types__list parts_1;
      if (kk_std_core_types__is_Nil(parts_0_10066, _ctx)) {
        kk_std_core_types__optional _match_x480 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
        if (kk_std_core_types__is_Optional(_match_x480, _ctx)) {
          kk_box_t _box_x206 = _match_x480._cons._Optional.value;
          kk_std_core_types__list _uniq_dirs_1153 = kk_std_core_types__list_unbox(_box_x206, KK_BORROWED, _ctx);
          kk_std_core_types__list_dup(_uniq_dirs_1153, _ctx);
          kk_std_core_types__optional_drop(_match_x480, _ctx);
          parts_1 = _uniq_dirs_1153; /*list<string>*/
        }
        else {
          kk_std_core_types__optional_drop(_match_x480, _ctx);
          parts_1 = kk_std_core_types__new_Nil(_ctx); /*list<string>*/
        }
      }
      else {
        kk_std_core_types__list _x_x853;
        kk_std_core_types__optional _match_x479 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
        if (kk_std_core_types__is_Optional(_match_x479, _ctx)) {
          kk_box_t _box_x207 = _match_x479._cons._Optional.value;
          kk_std_core_types__list _uniq_dirs_1153_0 = kk_std_core_types__list_unbox(_box_x207, KK_BORROWED, _ctx);
          kk_std_core_types__list_dup(_uniq_dirs_1153_0, _ctx);
          kk_std_core_types__optional_drop(_match_x479, _ctx);
          _x_x853 = _uniq_dirs_1153_0; /*list<string>*/
        }
        else {
          kk_std_core_types__optional_drop(_match_x479, _ctx);
          _x_x853 = kk_std_core_types__new_Nil(_ctx); /*list<string>*/
        }
        parts_1 = kk_std_os_path__unroll_push_parts_10000(parts_0_10066, _x_x853, _ctx); /*list<string>*/
      }
      kk_string_t _x_x854 = kk_string_empty(); /*string*/
      return kk_std_os_path__new_Path(_x_x854, parts_1, _ctx);
    }
    {
      kk_box_t _box_x208 = _match_x476._cons.Just.value;
      kk_std_core_types__tuple2 _pat_3_0 = kk_std_core_types__tuple2_unbox(_box_x208, KK_BORROWED, _ctx);
      kk_box_t _box_x209 = _pat_3_0.fst;
      kk_box_t _box_x210 = _pat_3_0.snd;
      kk_std_core_sslice__sslice rest = kk_std_core_sslice__sslice_unbox(_box_x210, KK_BORROWED, _ctx);
      bool eof = kk_bool_unbox(_box_x209);
      kk_string_drop(t, _ctx);
      kk_std_core_sslice__sslice_dup(rest, _ctx);
      kk_std_core_types__maybe_drop(_match_x476, _ctx);
      kk_string_t root_2_10072;
      kk_string_t _x_x856;
      kk_std_core_sslice__sslice _x_x857;
      {
        kk_string_t s_5 = rest.str;
        kk_integer_t start = rest.start;
        kk_string_dup(s_5, _ctx);
        kk_integer_dup(start, _ctx);
        _x_x857 = kk_std_core_sslice__new_Sslice(s_5, kk_integer_from_small(0), start, _ctx); /*sslice/sslice*/
      }
      _x_x856 = kk_std_core_sslice_string(_x_x857, _ctx); /*string*/
      kk_string_t _x_x858;
      if (eof) {
        kk_define_string_literal(static, _s_x859, 1, "/", _ctx)
        _x_x858 = kk_string_dup(_s_x859, _ctx); /*string*/
      }
      else {
        _x_x858 = kk_string_empty(); /*string*/
      }
      root_2_10072 = kk_std_core_types__lp__plus__plus__rp_(_x_x856, _x_x858, _ctx); /*string*/
      kk_string_t s_3_10073 = kk_std_core_sslice_string(rest, _ctx); /*string*/;
      kk_vector_t v_10019_0;
      kk_string_t _x_x861;
      kk_define_string_literal(static, _s_x862, 1, "/", _ctx)
      _x_x861 = kk_string_dup(_s_x862, _ctx); /*string*/
      v_10019_0 = kk_string_splitv(s_3_10073,_x_x861,kk_context()); /*vector<string>*/
      kk_std_core_types__list parts_3_10076 = kk_std_core_vector_vlist(v_10019_0, kk_std_core_types__new_None(_ctx), _ctx); /*list<string>*/;
      kk_std_core_types__list parts_4;
      if (kk_std_core_types__is_Nil(parts_3_10076, _ctx)) {
        kk_std_core_types__optional _match_x478 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
        if (kk_std_core_types__is_Optional(_match_x478, _ctx)) {
          kk_box_t _box_x211 = _match_x478._cons._Optional.value;
          kk_std_core_types__list _uniq_dirs_1153_0_0 = kk_std_core_types__list_unbox(_box_x211, KK_BORROWED, _ctx);
          kk_std_core_types__list_dup(_uniq_dirs_1153_0_0, _ctx);
          kk_std_core_types__optional_drop(_match_x478, _ctx);
          parts_4 = _uniq_dirs_1153_0_0; /*list<string>*/
        }
        else {
          kk_std_core_types__optional_drop(_match_x478, _ctx);
          parts_4 = kk_std_core_types__new_Nil(_ctx); /*list<string>*/
        }
      }
      else {
        kk_std_core_types__list _x_x863;
        kk_std_core_types__optional _match_x477 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
        if (kk_std_core_types__is_Optional(_match_x477, _ctx)) {
          kk_box_t _box_x212 = _match_x477._cons._Optional.value;
          kk_std_core_types__list _uniq_dirs_1153_0_1 = kk_std_core_types__list_unbox(_box_x212, KK_BORROWED, _ctx);
          kk_std_core_types__list_dup(_uniq_dirs_1153_0_1, _ctx);
          kk_std_core_types__optional_drop(_match_x477, _ctx);
          _x_x863 = _uniq_dirs_1153_0_1; /*list<string>*/
        }
        else {
          kk_std_core_types__optional_drop(_match_x477, _ctx);
          _x_x863 = kk_std_core_types__new_Nil(_ctx); /*list<string>*/
        }
        parts_4 = kk_std_os_path__unroll_push_parts_10000(parts_3_10076, _x_x863, _ctx); /*list<string>*/
      }
      return kk_std_os_path__new_Path(root_2_10072, parts_4, _ctx);
    }
  }
}


// lift anonymous function
struct kk_std_os_path__trmc_paths_collect_fun872__t {
  struct kk_function_s _base;
};
static kk_std_core_types__maybe kk_std_os_path__trmc_paths_collect_fun872(kk_function_t _fself, kk_char_t _b_x218, kk_context_t* _ctx);
static kk_function_t kk_std_os_path__new_trmc_paths_collect_fun872(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path__trmc_paths_collect_fun872, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_std_core_types__maybe kk_std_os_path__trmc_paths_collect_fun872(kk_function_t _fself, kk_char_t _b_x218, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return kk_std_core_types__new_Just(kk_char_box(_b_x218, _ctx), _ctx);
}

kk_std_core_types__list kk_std_os_path__trmc_paths_collect(kk_std_core_types__list ps, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* (ps : list<string>, ctx<list<path>>) -> list<path> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(ps, _ctx)) {
    struct kk_std_core_types_Cons* _con_x864 = kk_std_core_types__as_Cons(ps, _ctx);
    kk_box_t _box_x216 = _con_x864->head;
    kk_std_core_types__list _pat_0 = _con_x864->tail;
    if (kk_std_core_types__is_Cons(_pat_0, _ctx)) {
      struct kk_std_core_types_Cons* _con_x865 = kk_std_core_types__as_Cons(_pat_0, _ctx);
      kk_box_t _box_x217 = _con_x865->head;
      kk_string_t root = kk_string_unbox(_box_x216);
      kk_string_t part = kk_string_unbox(_box_x217);
      bool _match_x467;
      kk_integer_t _brw_x473;
      kk_string_t _x_x866 = kk_string_dup(root, _ctx); /*string*/
      _brw_x473 = kk_std_core_string_chars_fs_count(_x_x866, _ctx); /*int*/
      bool _brw_x474 = kk_integer_eq_borrow(_brw_x473,(kk_integer_from_small(1)),kk_context()); /*bool*/;
      kk_integer_drop(_brw_x473, _ctx);
      _match_x467 = _brw_x474; /*bool*/
      bool _x_x867;
      if (_match_x467) {
        kk_std_core_types__maybe m_10083;
        kk_std_core_sslice__sslice _x_x868;
        kk_string_t _x_x869 = kk_string_dup(root, _ctx); /*string*/
        kk_integer_t _x_x870;
        kk_string_t _x_x871 = kk_string_dup(root, _ctx); /*string*/
        _x_x870 = kk_string_len_int(_x_x871,kk_context()); /*int*/
        _x_x868 = kk_std_core_sslice__new_Sslice(_x_x869, kk_integer_from_small(0), _x_x870, _ctx); /*sslice/sslice*/
        m_10083 = kk_std_core_sslice_slice_fs_foreach_while(_x_x868, kk_std_os_path__new_trmc_paths_collect_fun872(_ctx), _ctx); /*maybe<char>*/
        bool _match_x468;
        bool _match_x469;
        kk_char_t _x_x873;
        if (kk_std_core_types__is_Nothing(m_10083, _ctx)) {
          _x_x873 = ' '; /*char*/
        }
        else {
          kk_box_t _box_x219 = m_10083._cons.Just.value;
          kk_char_t x = kk_char_unbox(_box_x219, KK_BORROWED, _ctx);
          _x_x873 = x; /*char*/
        }
        _match_x469 = (_x_x873 >= ('a')); /*bool*/
        if (_match_x469) {
          bool _match_x471;
          kk_char_t _x_x874;
          if (kk_std_core_types__is_Nothing(m_10083, _ctx)) {
            _x_x874 = ' '; /*char*/
          }
          else {
            kk_box_t _box_x220 = m_10083._cons.Just.value;
            kk_char_t x_0 = kk_char_unbox(_box_x220, KK_BORROWED, _ctx);
            _x_x874 = x_0; /*char*/
          }
          _match_x471 = (_x_x874 <= ('z')); /*bool*/
          if (_match_x471) {
            kk_std_core_types__maybe_drop(m_10083, _ctx);
            _match_x468 = true; /*bool*/
          }
          else {
            bool _match_x472;
            kk_char_t _x_x875;
            if (kk_std_core_types__is_Nothing(m_10083, _ctx)) {
              _x_x875 = ' '; /*char*/
            }
            else {
              kk_box_t _box_x221 = m_10083._cons.Just.value;
              kk_char_t x_1 = kk_char_unbox(_box_x221, KK_BORROWED, _ctx);
              _x_x875 = x_1; /*char*/
            }
            _match_x472 = (_x_x875 >= ('A')); /*bool*/
            if (_match_x472) {
              kk_char_t _x_x876;
              if (kk_std_core_types__is_Nothing(m_10083, _ctx)) {
                _x_x876 = ' '; /*char*/
              }
              else {
                kk_box_t _box_x222 = m_10083._cons.Just.value;
                kk_char_t x_2 = kk_char_unbox(_box_x222, KK_BORROWED, _ctx);
                kk_std_core_types__maybe_drop(m_10083, _ctx);
                _x_x876 = x_2; /*char*/
              }
              _match_x468 = (_x_x876 <= ('Z')); /*bool*/
            }
            else {
              kk_std_core_types__maybe_drop(m_10083, _ctx);
              _match_x468 = false; /*bool*/
            }
          }
        }
        else {
          bool _match_x470;
          kk_char_t _x_x877;
          if (kk_std_core_types__is_Nothing(m_10083, _ctx)) {
            _x_x877 = ' '; /*char*/
          }
          else {
            kk_box_t _box_x223 = m_10083._cons.Just.value;
            kk_char_t x_3 = kk_char_unbox(_box_x223, KK_BORROWED, _ctx);
            _x_x877 = x_3; /*char*/
          }
          _match_x470 = (_x_x877 >= ('A')); /*bool*/
          if (_match_x470) {
            kk_char_t _x_x878;
            if (kk_std_core_types__is_Nothing(m_10083, _ctx)) {
              _x_x878 = ' '; /*char*/
            }
            else {
              kk_box_t _box_x224 = m_10083._cons.Just.value;
              kk_char_t x_4 = kk_char_unbox(_box_x224, KK_BORROWED, _ctx);
              kk_std_core_types__maybe_drop(m_10083, _ctx);
              _x_x878 = x_4; /*char*/
            }
            _match_x468 = (_x_x878 <= ('Z')); /*bool*/
          }
          else {
            kk_std_core_types__maybe_drop(m_10083, _ctx);
            _match_x468 = false; /*bool*/
          }
        }
        if (_match_x468) {
          bool b_10086;
          kk_string_t _x_x879 = kk_string_dup(part, _ctx); /*string*/
          kk_string_t _x_x880 = kk_string_empty(); /*string*/
          b_10086 = kk_string_is_eq(_x_x879,_x_x880,kk_context()); /*bool*/
          if (b_10086) {
            _x_x867 = false; /*bool*/
          }
          else {
            kk_string_t _x_x882;
            kk_define_string_literal(static, _s_x883, 2, "/\\", _ctx)
            _x_x882 = kk_string_dup(_s_x883, _ctx); /*string*/
            kk_string_t _x_x884;
            kk_string_t _x_x885 = kk_string_dup(part, _ctx); /*string*/
            _x_x884 = kk_std_core_sslice_head(_x_x885, _ctx); /*string*/
            _x_x867 = kk_string_contains(_x_x882,_x_x884,kk_context()); /*bool*/
          }
        }
        else {
          _x_x867 = false; /*bool*/
        }
      }
      else {
        _x_x867 = false; /*bool*/
      }
      if (_x_x867) {
        kk_std_core_types__list rest = _con_x865->tail;
        kk_reuse_t _ru_x553 = kk_reuse_null; /*@reuse*/;
        if kk_likely(kk_datatype_ptr_is_unique(ps, _ctx)) {
          if kk_likely(kk_datatype_ptr_is_unique(_pat_0, _ctx)) {
            kk_datatype_ptr_free(_pat_0, _ctx);
          }
          else {
            kk_string_dup(part, _ctx);
            kk_std_core_types__list_dup(rest, _ctx);
            kk_datatype_ptr_decref(_pat_0, _ctx);
          }
          _ru_x553 = (kk_datatype_ptr_reuse(ps, _ctx));
        }
        else {
          kk_string_dup(part, _ctx);
          kk_std_core_types__list_dup(rest, _ctx);
          kk_string_dup(root, _ctx);
          kk_datatype_ptr_decref(ps, _ctx);
        }
        kk_std_os_path__path _trmc_x10314;
        kk_string_t _x_x886;
        kk_string_t _x_x887;
        kk_string_t _x_x888;
        kk_define_string_literal(static, _s_x889, 1, ":", _ctx)
        _x_x888 = kk_string_dup(_s_x889, _ctx); /*string*/
        _x_x887 = kk_std_core_types__lp__plus__plus__rp_(_x_x888, part, _ctx); /*string*/
        _x_x886 = kk_std_core_types__lp__plus__plus__rp_(root, _x_x887, _ctx); /*string*/
        _trmc_x10314 = kk_std_os_path_path(_x_x886, _ctx); /*std/os/path/path*/
        kk_std_core_types__list _trmc_x10315 = kk_datatype_null(); /*list<std/os/path/path>*/;
        kk_std_core_types__list _trmc_x10316 = kk_std_core_types__new_Cons(_ru_x553, 0, kk_std_os_path__path_box(_trmc_x10314, _ctx), _trmc_x10315, _ctx); /*list<std/os/path/path>*/;
        kk_field_addr_t _b_x234_250 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10316, _ctx)->tail, _ctx); /*@field-addr<list<std/os/path/path>>*/;
        { // tailcall
          kk_std_core_types__cctx _x_x890 = kk_cctx_extend_linear(_acc,(kk_std_core_types__list_box(_trmc_x10316, _ctx)),_b_x234_250,kk_context()); /*ctx<0>*/
          ps = rest;
          _acc = _x_x890;
          goto kk__tailcall;
        }
      }
    }
  }
  if (kk_std_core_types__is_Cons(ps, _ctx)) {
    struct kk_std_core_types_Cons* _con_x891 = kk_std_core_types__as_Cons(ps, _ctx);
    kk_box_t _box_x235 = _con_x891->head;
    kk_std_core_types__list rest_0 = _con_x891->tail;
    kk_string_t part_0 = kk_string_unbox(_box_x235);
    kk_reuse_t _ru_x554 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(ps, _ctx)) {
      _ru_x554 = (kk_datatype_ptr_reuse(ps, _ctx));
    }
    else {
      kk_string_dup(part_0, _ctx);
      kk_std_core_types__list_dup(rest_0, _ctx);
      kk_datatype_ptr_decref(ps, _ctx);
    }
    kk_std_os_path__path _trmc_x10317 = kk_std_os_path_path(part_0, _ctx); /*std/os/path/path*/;
    kk_std_core_types__list _trmc_x10318 = kk_datatype_null(); /*list<std/os/path/path>*/;
    kk_std_core_types__list _trmc_x10319 = kk_std_core_types__new_Cons(_ru_x554, 0, kk_std_os_path__path_box(_trmc_x10317, _ctx), _trmc_x10318, _ctx); /*list<std/os/path/path>*/;
    kk_field_addr_t _b_x245_256 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10319, _ctx)->tail, _ctx); /*@field-addr<list<std/os/path/path>>*/;
    { // tailcall
      kk_std_core_types__cctx _x_x892 = kk_cctx_extend_linear(_acc,(kk_std_core_types__list_box(_trmc_x10319, _ctx)),_b_x245_256,kk_context()); /*ctx<0>*/
      ps = rest_0;
      _acc = _x_x892;
      goto kk__tailcall;
    }
  }
  {
    kk_box_t _x_x893 = kk_cctx_apply_linear(_acc,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x893, KK_OWNED, _ctx);
  }
}

kk_std_core_types__list kk_std_os_path_paths_collect(kk_std_core_types__list ps_0, kk_context_t* _ctx) { /* (ps : list<string>) -> list<path> */ 
  kk_std_core_types__cctx _x_x894 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_std_os_path__trmc_paths_collect(ps_0, _x_x894, _ctx);
}
 
// Add two paths together using left-associative operator `(/)`.
// Keeps the root of `p1` and discards the root name of `p2`.
// `"/a/" / "b/foo.txt"          === "/a/b/foo.txt"`
// `"/a/foo.txt" / "/b/bar.txt"  === "/a/foo.txt/b/bar.txt"`
// `"c:/foo" / "d:/bar"          === "c:/foo/bar"`

kk_std_os_path__path kk_std_os_path__lp__fs__rp_(kk_std_os_path__path p1, kk_std_os_path__path p2, kk_context_t* _ctx) { /* (p1 : path, p2 : path) -> path */ 
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
      kk_std_core_types__list _x_x902;
      {
        kk_std_core_types__list _x_0_0 = p2.parts;
        kk_std_core_types__list_dup(_x_0_0, _ctx);
        kk_std_os_path__path_drop(p2, _ctx);
        _x_x902 = _x_0_0; /*list<string>*/
      }
      parts_0_10093 = kk_std_core_list__unroll_reverse_acc_10003(kk_std_core_types__new_Nil(_ctx), _x_x902, _ctx); /*list<string>*/
    }
  }
  kk_std_core_types__list _b_x262_263;
  if (kk_std_core_types__is_Nil(parts_0_10093, _ctx)) {
    kk_std_core_types__list _x_1 = p1.parts;
    kk_std_core_types__list_dup(_x_1, _ctx);
    _b_x262_263 = _x_1; /*list<string>*/
  }
  else {
    kk_std_core_types__list _x_x903;
    {
      kk_std_core_types__list _x_1_0 = p1.parts;
      kk_std_core_types__list_dup(_x_1_0, _ctx);
      _x_x903 = _x_1_0; /*list<string>*/
    }
    _b_x262_263 = kk_std_os_path__unroll_push_parts_10000(parts_0_10093, _x_x903, _ctx); /*list<string>*/
  }
  kk_string_t _x_x904;
  {
    kk_string_t _x = p1.root;
    kk_string_dup(_x, _ctx);
    kk_std_os_path__path_drop(p1, _ctx);
    _x_x904 = _x; /*string*/
  }
  kk_std_core_types__list _x_x905;
  kk_std_core_types__optional _match_x466 = kk_std_core_types__new_Optional(kk_std_core_types__list_box(_b_x262_263, _ctx), _ctx); /*? 7*/;
  if (kk_std_core_types__is_Optional(_match_x466, _ctx)) {
    kk_box_t _box_x264 = _match_x466._cons._Optional.value;
    kk_std_core_types__list _uniq_parts_95 = kk_std_core_types__list_unbox(_box_x264, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(_uniq_parts_95, _ctx);
    kk_std_core_types__optional_drop(_match_x466, _ctx);
    _x_x905 = _uniq_parts_95; /*list<string>*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x466, _ctx);
    _x_x905 = kk_std_core_types__new_Nil(_ctx); /*list<string>*/
  }
  return kk_std_os_path__new_Path(_x_x904, _x_x905, _ctx);
}
 
// Convenience function that adds a string path.

kk_std_os_path__path kk_std_os_path_pathstring_fs__lp__fs__rp_(kk_std_os_path__path p1, kk_string_t p2, kk_context_t* _ctx) { /* (p1 : path, p2 : string) -> path */ 
  kk_std_os_path__path p2_0_10099 = kk_std_os_path_path(p2, _ctx); /*std/os/path/path*/;
  kk_std_core_types__list parts_0_10103;
  {
    kk_std_core_types__list _x_0 = p2_0_10099.parts;
    kk_std_core_types__list_dup(_x_0, _ctx);
    if (kk_std_core_types__is_Nil(_x_0, _ctx)) {
      kk_std_os_path__path_drop(p2_0_10099, _ctx);
      parts_0_10103 = kk_std_core_types__new_Nil(_ctx); /*list<string>*/
    }
    else {
      kk_std_core_types__list_drop(_x_0, _ctx);
      kk_std_core_types__list _x_x906;
      {
        kk_std_core_types__list _x_0_0 = p2_0_10099.parts;
        kk_std_core_types__list_dup(_x_0_0, _ctx);
        kk_std_os_path__path_drop(p2_0_10099, _ctx);
        _x_x906 = _x_0_0; /*list<string>*/
      }
      parts_0_10103 = kk_std_core_list__unroll_reverse_acc_10003(kk_std_core_types__new_Nil(_ctx), _x_x906, _ctx); /*list<string>*/
    }
  }
  kk_std_core_types__list _b_x265_266;
  if (kk_std_core_types__is_Nil(parts_0_10103, _ctx)) {
    kk_std_core_types__list _x_1 = p1.parts;
    kk_std_core_types__list_dup(_x_1, _ctx);
    _b_x265_266 = _x_1; /*list<string>*/
  }
  else {
    kk_std_core_types__list _x_x907;
    {
      kk_std_core_types__list _x_1_0 = p1.parts;
      kk_std_core_types__list_dup(_x_1_0, _ctx);
      _x_x907 = _x_1_0; /*list<string>*/
    }
    _b_x265_266 = kk_std_os_path__unroll_push_parts_10000(parts_0_10103, _x_x907, _ctx); /*list<string>*/
  }
  kk_string_t _x_x908;
  {
    kk_string_t _x = p1.root;
    kk_string_dup(_x, _ctx);
    kk_std_os_path__path_drop(p1, _ctx);
    _x_x908 = _x; /*string*/
  }
  kk_std_core_types__list _x_x909;
  kk_std_core_types__optional _match_x465 = kk_std_core_types__new_Optional(kk_std_core_types__list_box(_b_x265_266, _ctx), _ctx); /*? 7*/;
  if (kk_std_core_types__is_Optional(_match_x465, _ctx)) {
    kk_box_t _box_x267 = _match_x465._cons._Optional.value;
    kk_std_core_types__list _uniq_parts_95 = kk_std_core_types__list_unbox(_box_x267, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(_uniq_parts_95, _ctx);
    kk_std_core_types__optional_drop(_match_x465, _ctx);
    _x_x909 = _uniq_parts_95; /*list<string>*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x465, _ctx);
    _x_x909 = kk_std_core_types__new_Nil(_ctx); /*list<string>*/
  }
  return kk_std_os_path__new_Path(_x_x908, _x_x909, _ctx);
}
 
// Convenience function that adds two strings into a path.

kk_std_os_path__path kk_std_os_path_string_fs__lp__fs__rp_(kk_string_t p1, kk_string_t p2, kk_context_t* _ctx) { /* (p1 : string, p2 : string) -> path */ 
  kk_std_os_path__path p1_0_10108 = kk_std_os_path_path(p1, _ctx); /*std/os/path/path*/;
  kk_std_os_path__path p2_0_10109 = kk_std_os_path_path(p2, _ctx); /*std/os/path/path*/;
  kk_std_core_types__list parts_0_10113;
  {
    kk_std_core_types__list _x_0 = p2_0_10109.parts;
    kk_std_core_types__list_dup(_x_0, _ctx);
    if (kk_std_core_types__is_Nil(_x_0, _ctx)) {
      kk_std_os_path__path_drop(p2_0_10109, _ctx);
      parts_0_10113 = kk_std_core_types__new_Nil(_ctx); /*list<string>*/
    }
    else {
      kk_std_core_types__list_drop(_x_0, _ctx);
      kk_std_core_types__list _x_x910;
      {
        kk_std_core_types__list _x_0_0 = p2_0_10109.parts;
        kk_std_core_types__list_dup(_x_0_0, _ctx);
        kk_std_os_path__path_drop(p2_0_10109, _ctx);
        _x_x910 = _x_0_0; /*list<string>*/
      }
      parts_0_10113 = kk_std_core_list__unroll_reverse_acc_10003(kk_std_core_types__new_Nil(_ctx), _x_x910, _ctx); /*list<string>*/
    }
  }
  kk_std_core_types__list _b_x268_269;
  if (kk_std_core_types__is_Nil(parts_0_10113, _ctx)) {
    kk_std_core_types__list _x_1 = p1_0_10108.parts;
    kk_std_core_types__list_dup(_x_1, _ctx);
    _b_x268_269 = _x_1; /*list<string>*/
  }
  else {
    kk_std_core_types__list _x_x911;
    {
      kk_std_core_types__list _x_1_0 = p1_0_10108.parts;
      kk_std_core_types__list_dup(_x_1_0, _ctx);
      _x_x911 = _x_1_0; /*list<string>*/
    }
    _b_x268_269 = kk_std_os_path__unroll_push_parts_10000(parts_0_10113, _x_x911, _ctx); /*list<string>*/
  }
  kk_string_t _x_x912;
  {
    kk_string_t _x = p1_0_10108.root;
    kk_string_dup(_x, _ctx);
    kk_std_os_path__path_drop(p1_0_10108, _ctx);
    _x_x912 = _x; /*string*/
  }
  kk_std_core_types__list _x_x913;
  kk_std_core_types__optional _match_x464 = kk_std_core_types__new_Optional(kk_std_core_types__list_box(_b_x268_269, _ctx), _ctx); /*? 7*/;
  if (kk_std_core_types__is_Optional(_match_x464, _ctx)) {
    kk_box_t _box_x270 = _match_x464._cons._Optional.value;
    kk_std_core_types__list _uniq_parts_95 = kk_std_core_types__list_unbox(_box_x270, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(_uniq_parts_95, _ctx);
    kk_std_core_types__optional_drop(_match_x464, _ctx);
    _x_x913 = _uniq_parts_95; /*list<string>*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x464, _ctx);
    _x_x913 = kk_std_core_types__new_Nil(_ctx); /*list<string>*/
  }
  return kk_std_os_path__new_Path(_x_x912, _x_x913, _ctx);
}
 
// lifted local: @lift-combine@10312, combine, @spec-x10311
// specialized: std/core/list/@unroll-foldl@10005, on parameters @uniq-f@10306, using:
// @uniq-f@10306 = std/os/path/(/)

kk_std_os_path__path kk_std_os_path__lift_combine_10313(kk_std_core_types__list _uniq_xs_10304, kk_std_os_path__path _uniq_z_10305, kk_context_t* _ctx) { /* (list<path>, path) -> path */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_xs_10304, _ctx)) {
    struct kk_std_core_types_Cons* _con_x914 = kk_std_core_types__as_Cons(_uniq_xs_10304, _ctx);
    kk_box_t _box_x271 = _con_x914->head;
    kk_std_core_types__list _uniq_xx_10309 = _con_x914->tail;
    kk_std_os_path__path _uniq_x_10308 = kk_std_os_path__path_unbox(_box_x271, KK_BORROWED, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10304, _ctx)) {
      kk_std_os_path__path_dup(_uniq_x_10308, _ctx);
      kk_box_drop(_box_x271, _ctx);
      kk_datatype_ptr_free(_uniq_xs_10304, _ctx);
    }
    else {
      kk_std_os_path__path_dup(_uniq_x_10308, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10309, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10304, _ctx);
    }
    { // tailcall
      kk_std_os_path__path _x_x915 = kk_std_os_path__lp__fs__rp_(_uniq_z_10305, _uniq_x_10308, _ctx); /*std/os/path/path*/
      _uniq_xs_10304 = _uniq_xx_10309;
      _uniq_z_10305 = _x_x915;
      goto kk__tailcall;
    }
  }
  {
    return _uniq_z_10305;
  }
}
 
// lifted local: combine, @spec-x10303
// specialized: std/core/list/foldl, on parameters @uniq-f@10300, using:
// @uniq-f@10300 = std/os/path/(/)

kk_std_os_path__path kk_std_os_path__lift_combine_10312(kk_std_core_types__list _uniq_xs_10298, kk_std_os_path__path _uniq_z_10299, kk_context_t* _ctx) { /* (list<path>, path) -> path */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10298, _ctx)) {
    return _uniq_z_10299;
  }
  {
    return kk_std_os_path__lift_combine_10313(_uniq_xs_10298, _uniq_z_10299, _ctx);
  }
}
 
// Combine multiple paths using `(/)`.

kk_std_os_path__path kk_std_os_path_combine(kk_std_core_types__list ps, kk_context_t* _ctx) { /* (ps : list<path>) -> path */ 
  if (kk_std_core_types__is_Nil(ps, _ctx)) {
    kk_string_t _x_x916;
    kk_std_core_types__optional _match_x463 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x463, _ctx)) {
      kk_box_t _box_x272 = _match_x463._cons._Optional.value;
      kk_string_t _uniq_root_89 = kk_string_unbox(_box_x272);
      kk_string_dup(_uniq_root_89, _ctx);
      kk_std_core_types__optional_drop(_match_x463, _ctx);
      _x_x916 = _uniq_root_89; /*string*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x463, _ctx);
      _x_x916 = kk_string_empty(); /*string*/
    }
    kk_std_core_types__list _x_x918;
    kk_std_core_types__optional _match_x462 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x462, _ctx)) {
      kk_box_t _box_x273 = _match_x462._cons._Optional.value;
      kk_std_core_types__list _uniq_parts_95 = kk_std_core_types__list_unbox(_box_x273, KK_BORROWED, _ctx);
      kk_std_core_types__list_dup(_uniq_parts_95, _ctx);
      kk_std_core_types__optional_drop(_match_x462, _ctx);
      _x_x918 = _uniq_parts_95; /*list<string>*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x462, _ctx);
      _x_x918 = kk_std_core_types__new_Nil(_ctx); /*list<string>*/
    }
    return kk_std_os_path__new_Path(_x_x916, _x_x918, _ctx);
  }
  {
    struct kk_std_core_types_Cons* _con_x919 = kk_std_core_types__as_Cons(ps, _ctx);
    kk_box_t _box_x274 = _con_x919->head;
    kk_std_os_path__path p = kk_std_os_path__path_unbox(_box_x274, KK_BORROWED, _ctx);
    kk_std_core_types__list pp = _con_x919->tail;
    if kk_likely(kk_datatype_ptr_is_unique(ps, _ctx)) {
      kk_std_os_path__path_dup(p, _ctx);
      kk_box_drop(_box_x274, _ctx);
      kk_datatype_ptr_free(ps, _ctx);
    }
    else {
      kk_std_os_path__path_dup(p, _ctx);
      kk_std_core_types__list_dup(pp, _ctx);
      kk_datatype_ptr_decref(ps, _ctx);
    }
    return kk_std_os_path__lift_combine_10312(pp, p, _ctx);
  }
}
 
// Remove the directory and root and only keep the base name (file name) portion of the path.
// `nodir("foo/bar.ext".path) === "bar.ext"`

kk_std_os_path__path kk_std_os_path_nodir(kk_std_os_path__path p, kk_context_t* _ctx) { /* (p : path) -> path */ 
  kk_std_core_types__list _b_x275_276;
  kk_std_core_types__list _x_x920;
  {
    kk_std_core_types__list _x_1 = p.parts;
    kk_std_core_types__list_dup(_x_1, _ctx);
    _x_x920 = _x_1; /*list<string>*/
  }
  _b_x275_276 = kk_std_core_list_take(_x_x920, kk_integer_from_small(1), _ctx); /*list<string>*/
  kk_string_t _x_x921 = kk_string_empty(); /*string*/
  kk_std_core_types__list _x_x923;
  kk_std_core_types__optional _match_x461 = kk_std_core_types__new_Optional(kk_std_core_types__list_box(_b_x275_276, _ctx), _ctx); /*? 7*/;
  if (kk_std_core_types__is_Optional(_match_x461, _ctx)) {
    kk_box_t _box_x277 = _match_x461._cons._Optional.value;
    kk_std_core_types__list _uniq_parts_136 = kk_std_core_types__list_unbox(_box_x277, KK_BORROWED, _ctx);
    kk_std_os_path__path_drop(p, _ctx);
    kk_std_core_types__list_dup(_uniq_parts_136, _ctx);
    kk_std_core_types__optional_drop(_match_x461, _ctx);
    _x_x923 = _uniq_parts_136; /*list<string>*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x461, _ctx);
    {
      kk_std_core_types__list _x_0 = p.parts;
      kk_std_core_types__list_dup(_x_0, _ctx);
      kk_std_os_path__path_drop(p, _ctx);
      _x_x923 = _x_0; /*list<string>*/
    }
  }
  return kk_std_os_path__new_Path(_x_x921, _x_x923, _ctx);
}
 
// Remove the basename and only keep the root and directory name portion of the path.
// `nobase("foo/bar.ext".path) == "foo")`

kk_std_os_path__path kk_std_os_path_nobase(kk_std_os_path__path p, kk_context_t* _ctx) { /* (p : path) -> path */ 
  kk_string_t _x_x924;
  kk_std_core_types__optional _match_x460 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x460, _ctx)) {
    kk_box_t _box_x278 = _match_x460._cons._Optional.value;
    kk_string_t _uniq_root_128 = kk_string_unbox(_box_x278);
    kk_string_dup(_uniq_root_128, _ctx);
    kk_std_core_types__optional_drop(_match_x460, _ctx);
    _x_x924 = _uniq_root_128; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x460, _ctx);
    {
      kk_string_t _x_0 = p.root;
      kk_string_dup(_x_0, _ctx);
      _x_x924 = _x_0; /*string*/
    }
  }
  kk_std_core_types__list _x_x925;
  {
    kk_std_core_types__list _x = p.parts;
    kk_std_core_types__list_dup(_x, _ctx);
    kk_std_os_path__path_drop(p, _ctx);
    if (kk_std_core_types__is_Cons(_x, _ctx)) {
      struct kk_std_core_types_Cons* _con_x926 = kk_std_core_types__as_Cons(_x, _ctx);
      kk_box_t _box_x279 = _con_x926->head;
      kk_std_core_types__list xx = _con_x926->tail;
      kk_string_t _pat_0 = kk_string_unbox(_box_x279);
      if kk_likely(kk_datatype_ptr_is_unique(_x, _ctx)) {
        kk_string_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(_x, _ctx);
      }
      else {
        kk_std_core_types__list_dup(xx, _ctx);
        kk_datatype_ptr_decref(_x, _ctx);
      }
      _x_x925 = xx; /*list<string>*/
    }
    else {
      _x_x925 = kk_std_core_types__new_Nil(_ctx); /*list<string>*/
    }
  }
  return kk_std_os_path__new_Path(_x_x924, _x_x925, _ctx);
}
 
// Change the extension of a path.
// Only adds a dot if the extname does not already start with a dot.

kk_std_os_path__path kk_std_os_path_change_ext(kk_std_os_path__path p, kk_string_t extname_0, kk_context_t* _ctx) { /* (p : path, extname : string) -> path */ 
  kk_integer_t i;
  kk_ssize_t _x_x927;
  kk_string_t _x_x928;
  {
    kk_std_core_types__list _x = p.parts;
    kk_std_core_types__list_dup(_x, _ctx);
    if (kk_std_core_types__is_Cons(_x, _ctx)) {
      struct kk_std_core_types_Cons* _con_x929 = kk_std_core_types__as_Cons(_x, _ctx);
      kk_box_t _box_x280 = _con_x929->head;
      kk_std_core_types__list _pat_0_0_0 = _con_x929->tail;
      kk_string_t x_0 = kk_string_unbox(_box_x280);
      if kk_likely(kk_datatype_ptr_is_unique(_x, _ctx)) {
        kk_std_core_types__list_drop(_pat_0_0_0, _ctx);
        kk_datatype_ptr_free(_x, _ctx);
      }
      else {
        kk_string_dup(x_0, _ctx);
        kk_datatype_ptr_decref(_x, _ctx);
      }
      _x_x928 = x_0; /*string*/
    }
    else {
      _x_x928 = kk_string_empty(); /*string*/
    }
  }
  kk_string_t _x_x931;
  kk_define_string_literal(static, _s_x932, 1, ".", _ctx)
  _x_x931 = kk_string_dup(_s_x932, _ctx); /*string*/
  _x_x927 = kk_string_last_index_of1(_x_x928,_x_x931,kk_context()); /*ssize_t*/
  i = kk_integer_from_ssize_t(_x_x927,kk_context()); /*int*/
  bool _match_x455 = kk_integer_is_zero_borrow(i); /*bool*/;
  if (_match_x455) {
    kk_integer_drop(i, _ctx);
    kk_std_core_types__maybe _match_x457 = kk_std_core_types__new_Nothing(_ctx); /*forall<a> maybe<a>*/;
    if (kk_std_core_types__is_Just(_match_x457, _ctx)) {
      kk_box_t _box_x282 = _match_x457._cons.Just.value;
      kk_std_core_sslice__sslice slice = kk_std_core_sslice__sslice_unbox(_box_x282, KK_BORROWED, _ctx);
      kk_std_core_sslice__sslice_dup(slice, _ctx);
      kk_std_core_types__maybe_drop(_match_x457, _ctx);
      kk_string_t stemname_0;
      kk_std_core_sslice__sslice _x_x933;
      {
        kk_string_t s_0 = slice.str;
        kk_integer_t start = slice.start;
        kk_string_dup(s_0, _ctx);
        kk_integer_dup(start, _ctx);
        _x_x933 = kk_std_core_sslice__new_Sslice(s_0, kk_integer_from_small(0), start, _ctx); /*sslice/sslice*/
      }
      stemname_0 = kk_std_core_sslice_string(_x_x933, _ctx); /*string*/
      kk_string_t _pat_1_2;
      kk_std_core_sslice__sslice _x_x934 = kk_std_core_sslice_after(slice, _ctx); /*sslice/sslice*/
      _pat_1_2 = kk_std_core_sslice_string(_x_x934, _ctx); /*string*/
      kk_string_drop(_pat_1_2, _ctx);
      kk_std_core_types__maybe maybe_10138;
      bool _match_x459;
      kk_string_t _x_x935 = kk_string_dup(extname_0, _ctx); /*string*/
      kk_string_t _x_x936;
      kk_define_string_literal(static, _s_x937, 1, ".", _ctx)
      _x_x936 = kk_string_dup(_s_x937, _ctx); /*string*/
      _match_x459 = kk_string_starts_with(_x_x935,_x_x936,kk_context()); /*bool*/
      if (_match_x459) {
        kk_integer_t x_10081;
        kk_string_t _x_x938 = kk_string_dup(extname_0, _ctx); /*string*/
        x_10081 = kk_string_len_int(_x_x938,kk_context()); /*int*/
        kk_integer_t y_10082;
        kk_string_t _x_x939;
        kk_define_string_literal(static, _s_x940, 1, ".", _ctx)
        _x_x939 = kk_string_dup(_s_x940, _ctx); /*string*/
        y_10082 = kk_string_len_int(_x_x939,kk_context()); /*int*/
        kk_std_core_sslice__sslice _b_x283_284;
        kk_string_t _x_x941 = kk_string_dup(extname_0, _ctx); /*string*/
        kk_integer_t _x_x942;
        kk_string_t _x_x943;
        kk_define_string_literal(static, _s_x944, 1, ".", _ctx)
        _x_x943 = kk_string_dup(_s_x944, _ctx); /*string*/
        _x_x942 = kk_string_len_int(_x_x943,kk_context()); /*int*/
        kk_integer_t _x_x945 = kk_integer_sub(x_10081,y_10082,kk_context()); /*int*/
        _b_x283_284 = kk_std_core_sslice__new_Sslice(_x_x941, _x_x942, _x_x945, _ctx); /*sslice/sslice*/
        maybe_10138 = kk_std_core_types__new_Just(kk_std_core_sslice__sslice_box(_b_x283_284, _ctx), _ctx); /*maybe<sslice/sslice>*/
      }
      else {
        maybe_10138 = kk_std_core_types__new_Nothing(_ctx); /*maybe<sslice/sslice>*/
      }
      kk_string_t newext;
      if (kk_std_core_types__is_Just(maybe_10138, _ctx)) {
        kk_box_t _box_x285 = maybe_10138._cons.Just.value;
        kk_std_core_types__maybe_drop(maybe_10138, _ctx);
        newext = extname_0; /*string*/
      }
      else {
        kk_string_t _x_x946;
        kk_define_string_literal(static, _s_x947, 1, ".", _ctx)
        _x_x946 = kk_string_dup(_s_x947, _ctx); /*string*/
        newext = kk_std_core_types__lp__plus__plus__rp_(_x_x946, extname_0, _ctx); /*string*/
      }
      kk_string_t s_0_10142 = kk_std_core_types__lp__plus__plus__rp_(stemname_0, newext, _ctx); /*string*/;
      kk_vector_t v_10019;
      kk_string_t _x_x948;
      kk_define_string_literal(static, _s_x949, 1, "/", _ctx)
      _x_x948 = kk_string_dup(_s_x949, _ctx); /*string*/
      v_10019 = kk_string_splitv(s_0_10142,_x_x948,kk_context()); /*vector<string>*/
      kk_std_core_types__list parts_0_10145 = kk_std_core_vector_vlist(v_10019, kk_std_core_types__new_None(_ctx), _ctx); /*list<string>*/;
      kk_std_core_types__list parts_1;
      if (kk_std_core_types__is_Nil(parts_0_10145, _ctx)) {
        kk_std_core_types__list _x_0 = p.parts;
        kk_std_core_types__list_dup(_x_0, _ctx);
        if (kk_std_core_types__is_Cons(_x_0, _ctx)) {
          struct kk_std_core_types_Cons* _con_x950 = kk_std_core_types__as_Cons(_x_0, _ctx);
          kk_box_t _box_x286 = _con_x950->head;
          kk_std_core_types__list xx = _con_x950->tail;
          kk_string_t _pat_0_1_1 = kk_string_unbox(_box_x286);
          if kk_likely(kk_datatype_ptr_is_unique(_x_0, _ctx)) {
            kk_string_drop(_pat_0_1_1, _ctx);
            kk_datatype_ptr_free(_x_0, _ctx);
          }
          else {
            kk_std_core_types__list_dup(xx, _ctx);
            kk_datatype_ptr_decref(_x_0, _ctx);
          }
          parts_1 = xx; /*list<string>*/
        }
        else {
          parts_1 = kk_std_core_types__new_Nil(_ctx); /*list<string>*/
        }
      }
      else {
        kk_std_core_types__list _x_x951;
        {
          kk_std_core_types__list _x_0_0 = p.parts;
          kk_std_core_types__list_dup(_x_0_0, _ctx);
          if (kk_std_core_types__is_Cons(_x_0_0, _ctx)) {
            struct kk_std_core_types_Cons* _con_x952 = kk_std_core_types__as_Cons(_x_0_0, _ctx);
            kk_box_t _box_x287 = _con_x952->head;
            kk_std_core_types__list xx_0 = _con_x952->tail;
            kk_string_t _pat_0_1_1_0 = kk_string_unbox(_box_x287);
            if kk_likely(kk_datatype_ptr_is_unique(_x_0_0, _ctx)) {
              kk_string_drop(_pat_0_1_1_0, _ctx);
              kk_datatype_ptr_free(_x_0_0, _ctx);
            }
            else {
              kk_std_core_types__list_dup(xx_0, _ctx);
              kk_datatype_ptr_decref(_x_0_0, _ctx);
            }
            _x_x951 = xx_0; /*list<string>*/
          }
          else {
            _x_x951 = kk_std_core_types__new_Nil(_ctx); /*list<string>*/
          }
        }
        parts_1 = kk_std_os_path__unroll_push_parts_10000(parts_0_10145, _x_x951, _ctx); /*list<string>*/
      }
      kk_string_t _x_x953;
      {
        kk_string_t _x_0_0_0 = p.root;
        kk_string_dup(_x_0_0_0, _ctx);
        kk_std_os_path__path_drop(p, _ctx);
        _x_x953 = _x_0_0_0; /*string*/
      }
      return kk_std_os_path__new_Path(_x_x953, parts_1, _ctx);
    }
    {
      kk_std_core_types__maybe maybe_10138_0;
      bool _match_x458;
      kk_string_t _x_x954 = kk_string_dup(extname_0, _ctx); /*string*/
      kk_string_t _x_x955;
      kk_define_string_literal(static, _s_x956, 1, ".", _ctx)
      _x_x955 = kk_string_dup(_s_x956, _ctx); /*string*/
      _match_x458 = kk_string_starts_with(_x_x954,_x_x955,kk_context()); /*bool*/
      if (_match_x458) {
        kk_integer_t x_10081_0;
        kk_string_t _x_x957 = kk_string_dup(extname_0, _ctx); /*string*/
        x_10081_0 = kk_string_len_int(_x_x957,kk_context()); /*int*/
        kk_integer_t y_10082_0;
        kk_string_t _x_x958;
        kk_define_string_literal(static, _s_x959, 1, ".", _ctx)
        _x_x958 = kk_string_dup(_s_x959, _ctx); /*string*/
        y_10082_0 = kk_string_len_int(_x_x958,kk_context()); /*int*/
        kk_std_core_sslice__sslice _b_x288_289;
        kk_string_t _x_x960 = kk_string_dup(extname_0, _ctx); /*string*/
        kk_integer_t _x_x961;
        kk_string_t _x_x962;
        kk_define_string_literal(static, _s_x963, 1, ".", _ctx)
        _x_x962 = kk_string_dup(_s_x963, _ctx); /*string*/
        _x_x961 = kk_string_len_int(_x_x962,kk_context()); /*int*/
        kk_integer_t _x_x964 = kk_integer_sub(x_10081_0,y_10082_0,kk_context()); /*int*/
        _b_x288_289 = kk_std_core_sslice__new_Sslice(_x_x960, _x_x961, _x_x964, _ctx); /*sslice/sslice*/
        maybe_10138_0 = kk_std_core_types__new_Just(kk_std_core_sslice__sslice_box(_b_x288_289, _ctx), _ctx); /*maybe<sslice/sslice>*/
      }
      else {
        maybe_10138_0 = kk_std_core_types__new_Nothing(_ctx); /*maybe<sslice/sslice>*/
      }
      kk_string_t newext_0;
      if (kk_std_core_types__is_Just(maybe_10138_0, _ctx)) {
        kk_box_t _box_x290 = maybe_10138_0._cons.Just.value;
        kk_std_core_types__maybe_drop(maybe_10138_0, _ctx);
        newext_0 = extname_0; /*string*/
      }
      else {
        kk_string_t _x_x965;
        kk_define_string_literal(static, _s_x966, 1, ".", _ctx)
        _x_x965 = kk_string_dup(_s_x966, _ctx); /*string*/
        newext_0 = kk_std_core_types__lp__plus__plus__rp_(_x_x965, extname_0, _ctx); /*string*/
      }
      kk_string_t s_0_10142_0;
      kk_string_t _x_x967;
      {
        kk_std_core_types__list _x_1 = p.parts;
        kk_std_core_types__list_dup(_x_1, _ctx);
        if (kk_std_core_types__is_Cons(_x_1, _ctx)) {
          struct kk_std_core_types_Cons* _con_x968 = kk_std_core_types__as_Cons(_x_1, _ctx);
          kk_box_t _box_x291 = _con_x968->head;
          kk_std_core_types__list _pat_0_0_0_0 = _con_x968->tail;
          kk_string_t x_0_0 = kk_string_unbox(_box_x291);
          if kk_likely(kk_datatype_ptr_is_unique(_x_1, _ctx)) {
            kk_std_core_types__list_drop(_pat_0_0_0_0, _ctx);
            kk_datatype_ptr_free(_x_1, _ctx);
          }
          else {
            kk_string_dup(x_0_0, _ctx);
            kk_datatype_ptr_decref(_x_1, _ctx);
          }
          _x_x967 = x_0_0; /*string*/
        }
        else {
          _x_x967 = kk_string_empty(); /*string*/
        }
      }
      s_0_10142_0 = kk_std_core_types__lp__plus__plus__rp_(_x_x967, newext_0, _ctx); /*string*/
      kk_vector_t v_10019_0;
      kk_string_t _x_x970;
      kk_define_string_literal(static, _s_x971, 1, "/", _ctx)
      _x_x970 = kk_string_dup(_s_x971, _ctx); /*string*/
      v_10019_0 = kk_string_splitv(s_0_10142_0,_x_x970,kk_context()); /*vector<string>*/
      kk_std_core_types__list parts_0_10145_0 = kk_std_core_vector_vlist(v_10019_0, kk_std_core_types__new_None(_ctx), _ctx); /*list<string>*/;
      kk_std_core_types__list parts_1_0;
      if (kk_std_core_types__is_Nil(parts_0_10145_0, _ctx)) {
        kk_std_core_types__list _x_0_1 = p.parts;
        kk_std_core_types__list_dup(_x_0_1, _ctx);
        if (kk_std_core_types__is_Cons(_x_0_1, _ctx)) {
          struct kk_std_core_types_Cons* _con_x972 = kk_std_core_types__as_Cons(_x_0_1, _ctx);
          kk_box_t _box_x293 = _con_x972->head;
          kk_std_core_types__list xx_1 = _con_x972->tail;
          kk_string_t _pat_0_1_1_1 = kk_string_unbox(_box_x293);
          if kk_likely(kk_datatype_ptr_is_unique(_x_0_1, _ctx)) {
            kk_string_drop(_pat_0_1_1_1, _ctx);
            kk_datatype_ptr_free(_x_0_1, _ctx);
          }
          else {
            kk_std_core_types__list_dup(xx_1, _ctx);
            kk_datatype_ptr_decref(_x_0_1, _ctx);
          }
          parts_1_0 = xx_1; /*list<string>*/
        }
        else {
          parts_1_0 = kk_std_core_types__new_Nil(_ctx); /*list<string>*/
        }
      }
      else {
        kk_std_core_types__list _x_x973;
        {
          kk_std_core_types__list _x_1_0 = p.parts;
          kk_std_core_types__list_dup(_x_1_0, _ctx);
          if (kk_std_core_types__is_Cons(_x_1_0, _ctx)) {
            struct kk_std_core_types_Cons* _con_x974 = kk_std_core_types__as_Cons(_x_1_0, _ctx);
            kk_box_t _box_x294 = _con_x974->head;
            kk_std_core_types__list xx_0_0 = _con_x974->tail;
            kk_string_t _pat_0_1_1_0_0 = kk_string_unbox(_box_x294);
            if kk_likely(kk_datatype_ptr_is_unique(_x_1_0, _ctx)) {
              kk_string_drop(_pat_0_1_1_0_0, _ctx);
              kk_datatype_ptr_free(_x_1_0, _ctx);
            }
            else {
              kk_std_core_types__list_dup(xx_0_0, _ctx);
              kk_datatype_ptr_decref(_x_1_0, _ctx);
            }
            _x_x973 = xx_0_0; /*list<string>*/
          }
          else {
            _x_x973 = kk_std_core_types__new_Nil(_ctx); /*list<string>*/
          }
        }
        parts_1_0 = kk_std_os_path__unroll_push_parts_10000(parts_0_10145_0, _x_x973, _ctx); /*list<string>*/
      }
      kk_string_t _x_x975;
      {
        kk_string_t _x_0_0_1 = p.root;
        kk_string_dup(_x_0_0_1, _ctx);
        kk_std_os_path__path_drop(p, _ctx);
        _x_x975 = _x_0_0_1; /*string*/
      }
      return kk_std_os_path__new_Path(_x_x975, parts_1_0, _ctx);
    }
  }
  {
    kk_integer_t _pat_1_0_0 = kk_integer_add_small_const(i, -1, _ctx); /*int*/;
    kk_integer_t _pat_2_0;
    kk_string_t _x_x976;
    kk_define_string_literal(static, _s_x977, 1, ".", _ctx)
    _x_x976 = kk_string_dup(_s_x977, _ctx); /*string*/
    _pat_2_0 = kk_string_len_int(_x_x976,kk_context()); /*int*/
    kk_std_core_sslice__sslice slice_0;
    kk_string_t _x_x978;
    {
      kk_std_core_types__list _x_2 = p.parts;
      kk_std_core_types__list_dup(_x_2, _ctx);
      if (kk_std_core_types__is_Cons(_x_2, _ctx)) {
        struct kk_std_core_types_Cons* _con_x979 = kk_std_core_types__as_Cons(_x_2, _ctx);
        kk_box_t _box_x295 = _con_x979->head;
        kk_std_core_types__list _pat_0_0_0_1 = _con_x979->tail;
        kk_string_t x_0_1 = kk_string_unbox(_box_x295);
        if kk_likely(kk_datatype_ptr_is_unique(_x_2, _ctx)) {
          kk_std_core_types__list_drop(_pat_0_0_0_1, _ctx);
          kk_datatype_ptr_free(_x_2, _ctx);
        }
        else {
          kk_string_dup(x_0_1, _ctx);
          kk_datatype_ptr_decref(_x_2, _ctx);
        }
        _x_x978 = x_0_1; /*string*/
      }
      else {
        _x_x978 = kk_string_empty(); /*string*/
      }
    }
    slice_0 = kk_std_core_sslice__new_Sslice(_x_x978, _pat_1_0_0, _pat_2_0, _ctx); /*sslice/sslice*/
    kk_string_t stemname_0_0;
    kk_std_core_sslice__sslice _x_x981;
    {
      kk_string_t s_0_0 = slice_0.str;
      kk_integer_t start_0 = slice_0.start;
      kk_string_dup(s_0_0, _ctx);
      kk_integer_dup(start_0, _ctx);
      _x_x981 = kk_std_core_sslice__new_Sslice(s_0_0, kk_integer_from_small(0), start_0, _ctx); /*sslice/sslice*/
    }
    stemname_0_0 = kk_std_core_sslice_string(_x_x981, _ctx); /*string*/
    kk_string_t _pat_1_2_0;
    kk_std_core_sslice__sslice _x_x982 = kk_std_core_sslice_after(slice_0, _ctx); /*sslice/sslice*/
    _pat_1_2_0 = kk_std_core_sslice_string(_x_x982, _ctx); /*string*/
    kk_string_drop(_pat_1_2_0, _ctx);
    kk_std_core_types__maybe maybe_10138_1;
    bool _match_x456;
    kk_string_t _x_x983 = kk_string_dup(extname_0, _ctx); /*string*/
    kk_string_t _x_x984;
    kk_define_string_literal(static, _s_x985, 1, ".", _ctx)
    _x_x984 = kk_string_dup(_s_x985, _ctx); /*string*/
    _match_x456 = kk_string_starts_with(_x_x983,_x_x984,kk_context()); /*bool*/
    if (_match_x456) {
      kk_integer_t x_10081_1;
      kk_string_t _x_x986 = kk_string_dup(extname_0, _ctx); /*string*/
      x_10081_1 = kk_string_len_int(_x_x986,kk_context()); /*int*/
      kk_integer_t y_10082_1;
      kk_string_t _x_x987;
      kk_define_string_literal(static, _s_x988, 1, ".", _ctx)
      _x_x987 = kk_string_dup(_s_x988, _ctx); /*string*/
      y_10082_1 = kk_string_len_int(_x_x987,kk_context()); /*int*/
      kk_std_core_sslice__sslice _b_x297_298;
      kk_string_t _x_x989 = kk_string_dup(extname_0, _ctx); /*string*/
      kk_integer_t _x_x990;
      kk_string_t _x_x991;
      kk_define_string_literal(static, _s_x992, 1, ".", _ctx)
      _x_x991 = kk_string_dup(_s_x992, _ctx); /*string*/
      _x_x990 = kk_string_len_int(_x_x991,kk_context()); /*int*/
      kk_integer_t _x_x993 = kk_integer_sub(x_10081_1,y_10082_1,kk_context()); /*int*/
      _b_x297_298 = kk_std_core_sslice__new_Sslice(_x_x989, _x_x990, _x_x993, _ctx); /*sslice/sslice*/
      maybe_10138_1 = kk_std_core_types__new_Just(kk_std_core_sslice__sslice_box(_b_x297_298, _ctx), _ctx); /*maybe<sslice/sslice>*/
    }
    else {
      maybe_10138_1 = kk_std_core_types__new_Nothing(_ctx); /*maybe<sslice/sslice>*/
    }
    kk_string_t newext_1;
    if (kk_std_core_types__is_Just(maybe_10138_1, _ctx)) {
      kk_box_t _box_x299 = maybe_10138_1._cons.Just.value;
      kk_std_core_types__maybe_drop(maybe_10138_1, _ctx);
      newext_1 = extname_0; /*string*/
    }
    else {
      kk_string_t _x_x994;
      kk_define_string_literal(static, _s_x995, 1, ".", _ctx)
      _x_x994 = kk_string_dup(_s_x995, _ctx); /*string*/
      newext_1 = kk_std_core_types__lp__plus__plus__rp_(_x_x994, extname_0, _ctx); /*string*/
    }
    kk_string_t s_0_10142_1 = kk_std_core_types__lp__plus__plus__rp_(stemname_0_0, newext_1, _ctx); /*string*/;
    kk_vector_t v_10019_1;
    kk_string_t _x_x996;
    kk_define_string_literal(static, _s_x997, 1, "/", _ctx)
    _x_x996 = kk_string_dup(_s_x997, _ctx); /*string*/
    v_10019_1 = kk_string_splitv(s_0_10142_1,_x_x996,kk_context()); /*vector<string>*/
    kk_std_core_types__list parts_0_10145_1 = kk_std_core_vector_vlist(v_10019_1, kk_std_core_types__new_None(_ctx), _ctx); /*list<string>*/;
    kk_std_core_types__list parts_1_1;
    if (kk_std_core_types__is_Nil(parts_0_10145_1, _ctx)) {
      kk_std_core_types__list _x_3 = p.parts;
      kk_std_core_types__list_dup(_x_3, _ctx);
      if (kk_std_core_types__is_Cons(_x_3, _ctx)) {
        struct kk_std_core_types_Cons* _con_x998 = kk_std_core_types__as_Cons(_x_3, _ctx);
        kk_box_t _box_x300 = _con_x998->head;
        kk_std_core_types__list xx_2 = _con_x998->tail;
        kk_string_t _pat_0_1_1_2 = kk_string_unbox(_box_x300);
        if kk_likely(kk_datatype_ptr_is_unique(_x_3, _ctx)) {
          kk_string_drop(_pat_0_1_1_2, _ctx);
          kk_datatype_ptr_free(_x_3, _ctx);
        }
        else {
          kk_std_core_types__list_dup(xx_2, _ctx);
          kk_datatype_ptr_decref(_x_3, _ctx);
        }
        parts_1_1 = xx_2; /*list<string>*/
      }
      else {
        parts_1_1 = kk_std_core_types__new_Nil(_ctx); /*list<string>*/
      }
    }
    else {
      kk_std_core_types__list _x_x999;
      {
        kk_std_core_types__list _x_0_2 = p.parts;
        kk_std_core_types__list_dup(_x_0_2, _ctx);
        if (kk_std_core_types__is_Cons(_x_0_2, _ctx)) {
          struct kk_std_core_types_Cons* _con_x1000 = kk_std_core_types__as_Cons(_x_0_2, _ctx);
          kk_box_t _box_x301 = _con_x1000->head;
          kk_std_core_types__list xx_0_1 = _con_x1000->tail;
          kk_string_t _pat_0_1_1_0_1 = kk_string_unbox(_box_x301);
          if kk_likely(kk_datatype_ptr_is_unique(_x_0_2, _ctx)) {
            kk_string_drop(_pat_0_1_1_0_1, _ctx);
            kk_datatype_ptr_free(_x_0_2, _ctx);
          }
          else {
            kk_std_core_types__list_dup(xx_0_1, _ctx);
            kk_datatype_ptr_decref(_x_0_2, _ctx);
          }
          _x_x999 = xx_0_1; /*list<string>*/
        }
        else {
          _x_x999 = kk_std_core_types__new_Nil(_ctx); /*list<string>*/
        }
      }
      parts_1_1 = kk_std_os_path__unroll_push_parts_10000(parts_0_10145_1, _x_x999, _ctx); /*list<string>*/
    }
    kk_string_t _x_x1001;
    {
      kk_string_t _x_0_0_2 = p.root;
      kk_string_dup(_x_0_0_2, _ctx);
      kk_std_os_path__path_drop(p, _ctx);
      _x_x1001 = _x_0_0_2; /*string*/
    }
    return kk_std_os_path__new_Path(_x_x1001, parts_1_1, _ctx);
  }
}
 
// If a path has no extension, set it to the provided one.

kk_std_os_path__path kk_std_os_path_default_ext(kk_std_os_path__path p, kk_string_t newext, kk_context_t* _ctx) { /* (p : path, newext : string) -> path */ 
  kk_string_t s_10151;
  kk_std_os_path__path _x_x1004 = kk_std_os_path__path_dup(p, _ctx); /*std/os/path/path*/
  s_10151 = kk_std_os_path_extname(_x_x1004, _ctx); /*string*/
  bool _match_x454;
  kk_string_t _x_x1005 = kk_string_empty(); /*string*/
  _match_x454 = kk_string_is_eq(s_10151,_x_x1005,kk_context()); /*bool*/
  if (_match_x454) {
    return kk_std_os_path_change_ext(p, newext, _ctx);
  }
  {
    kk_string_drop(newext, _ctx);
    return p;
  }
}
 
// Change the base name of a path

kk_std_os_path__path kk_std_os_path_change_base(kk_std_os_path__path p, kk_string_t basename_0, kk_context_t* _ctx) { /* (p : path, basename : string) -> path */ 
  kk_std_os_path__path q;
  kk_string_t _x_x1007;
  kk_std_core_types__optional _match_x453 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x453, _ctx)) {
    kk_box_t _box_x302 = _match_x453._cons._Optional.value;
    kk_string_t _uniq_root_128 = kk_string_unbox(_box_x302);
    kk_string_dup(_uniq_root_128, _ctx);
    kk_std_core_types__optional_drop(_match_x453, _ctx);
    _x_x1007 = _uniq_root_128; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x453, _ctx);
    {
      kk_string_t _x_0 = p.root;
      kk_string_dup(_x_0, _ctx);
      _x_x1007 = _x_0; /*string*/
    }
  }
  kk_std_core_types__list _x_x1008;
  {
    kk_std_core_types__list _x = p.parts;
    kk_std_core_types__list_dup(_x, _ctx);
    kk_std_os_path__path_drop(p, _ctx);
    if (kk_std_core_types__is_Cons(_x, _ctx)) {
      struct kk_std_core_types_Cons* _con_x1009 = kk_std_core_types__as_Cons(_x, _ctx);
      kk_box_t _box_x303 = _con_x1009->head;
      kk_std_core_types__list xx = _con_x1009->tail;
      kk_string_t _pat_0 = kk_string_unbox(_box_x303);
      if kk_likely(kk_datatype_ptr_is_unique(_x, _ctx)) {
        kk_string_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(_x, _ctx);
      }
      else {
        kk_std_core_types__list_dup(xx, _ctx);
        kk_datatype_ptr_decref(_x, _ctx);
      }
      _x_x1008 = xx; /*list<string>*/
    }
    else {
      _x_x1008 = kk_std_core_types__new_Nil(_ctx); /*list<string>*/
    }
  }
  q = kk_std_os_path__new_Path(_x_x1007, _x_x1008, _ctx); /*std/os/path/path*/
  kk_vector_t v_10019;
  kk_string_t _x_x1010;
  kk_define_string_literal(static, _s_x1011, 1, "/", _ctx)
  _x_x1010 = kk_string_dup(_s_x1011, _ctx); /*string*/
  v_10019 = kk_string_splitv(basename_0,_x_x1010,kk_context()); /*vector<string>*/
  kk_std_core_types__list parts_10157 = kk_std_core_vector_vlist(v_10019, kk_std_core_types__new_None(_ctx), _ctx); /*list<string>*/;
  kk_std_core_types__list parts_0;
  if (kk_std_core_types__is_Nil(parts_10157, _ctx)) {
    kk_std_core_types__list _x_0_0 = q.parts;
    kk_std_core_types__list_dup(_x_0_0, _ctx);
    parts_0 = _x_0_0; /*list<string>*/
  }
  else {
    kk_std_core_types__list _x_x1012;
    {
      kk_std_core_types__list _x_0_0_0 = q.parts;
      kk_std_core_types__list_dup(_x_0_0_0, _ctx);
      _x_x1012 = _x_0_0_0; /*list<string>*/
    }
    parts_0 = kk_std_os_path__unroll_push_parts_10000(parts_10157, _x_x1012, _ctx); /*list<string>*/
  }
  kk_string_t _x_x1013;
  {
    kk_string_t _x_1 = q.root;
    kk_string_dup(_x_1, _ctx);
    kk_std_os_path__path_drop(q, _ctx);
    _x_x1013 = _x_1; /*string*/
  }
  return kk_std_os_path__new_Path(_x_x1013, parts_0, _ctx);
}
 
// Change the stem name of a path

kk_std_os_path__path kk_std_os_path_change_stem(kk_std_os_path__path p, kk_string_t stemname_0, kk_context_t* _ctx) { /* (p : path, stemname : string) -> path */ 
  kk_string_t ext;
  kk_std_os_path__path _x_x1014 = kk_std_os_path__path_dup(p, _ctx); /*std/os/path/path*/
  ext = kk_std_os_path_extname(_x_x1014, _ctx); /*string*/
  kk_string_t basename_0_10164;
  kk_string_t _x_x1015;
  bool _match_x452;
  kk_string_t _x_x1016 = kk_string_dup(ext, _ctx); /*string*/
  kk_string_t _x_x1017 = kk_string_empty(); /*string*/
  _match_x452 = kk_string_is_eq(_x_x1016,_x_x1017,kk_context()); /*bool*/
  if (_match_x452) {
    kk_string_drop(ext, _ctx);
    _x_x1015 = kk_string_empty(); /*string*/
  }
  else {
    kk_string_t _x_x1020;
    kk_define_string_literal(static, _s_x1021, 1, ".", _ctx)
    _x_x1020 = kk_string_dup(_s_x1021, _ctx); /*string*/
    _x_x1015 = kk_std_core_types__lp__plus__plus__rp_(_x_x1020, ext, _ctx); /*string*/
  }
  basename_0_10164 = kk_std_core_types__lp__plus__plus__rp_(stemname_0, _x_x1015, _ctx); /*string*/
  kk_std_os_path__path q;
  kk_string_t _x_x1022;
  kk_std_core_types__optional _match_x451 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x451, _ctx)) {
    kk_box_t _box_x304 = _match_x451._cons._Optional.value;
    kk_string_t _uniq_root_128 = kk_string_unbox(_box_x304);
    kk_string_dup(_uniq_root_128, _ctx);
    kk_std_core_types__optional_drop(_match_x451, _ctx);
    _x_x1022 = _uniq_root_128; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x451, _ctx);
    {
      kk_string_t _x_0 = p.root;
      kk_string_dup(_x_0, _ctx);
      _x_x1022 = _x_0; /*string*/
    }
  }
  kk_std_core_types__list _x_x1023;
  {
    kk_std_core_types__list _x = p.parts;
    kk_std_core_types__list_dup(_x, _ctx);
    kk_std_os_path__path_drop(p, _ctx);
    if (kk_std_core_types__is_Cons(_x, _ctx)) {
      struct kk_std_core_types_Cons* _con_x1024 = kk_std_core_types__as_Cons(_x, _ctx);
      kk_box_t _box_x305 = _con_x1024->head;
      kk_std_core_types__list xx = _con_x1024->tail;
      kk_string_t _pat_0 = kk_string_unbox(_box_x305);
      if kk_likely(kk_datatype_ptr_is_unique(_x, _ctx)) {
        kk_string_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(_x, _ctx);
      }
      else {
        kk_std_core_types__list_dup(xx, _ctx);
        kk_datatype_ptr_decref(_x, _ctx);
      }
      _x_x1023 = xx; /*list<string>*/
    }
    else {
      _x_x1023 = kk_std_core_types__new_Nil(_ctx); /*list<string>*/
    }
  }
  q = kk_std_os_path__new_Path(_x_x1022, _x_x1023, _ctx); /*std/os/path/path*/
  kk_vector_t v_10019;
  kk_string_t _x_x1025;
  kk_define_string_literal(static, _s_x1026, 1, "/", _ctx)
  _x_x1025 = kk_string_dup(_s_x1026, _ctx); /*string*/
  v_10019 = kk_string_splitv(basename_0_10164,_x_x1025,kk_context()); /*vector<string>*/
  kk_std_core_types__list parts_10171 = kk_std_core_vector_vlist(v_10019, kk_std_core_types__new_None(_ctx), _ctx); /*list<string>*/;
  kk_std_core_types__list parts_0;
  if (kk_std_core_types__is_Nil(parts_10171, _ctx)) {
    kk_std_core_types__list _x_0_0 = q.parts;
    kk_std_core_types__list_dup(_x_0_0, _ctx);
    parts_0 = _x_0_0; /*list<string>*/
  }
  else {
    kk_std_core_types__list _x_x1027;
    {
      kk_std_core_types__list _x_0_0_0 = q.parts;
      kk_std_core_types__list_dup(_x_0_0_0, _ctx);
      _x_x1027 = _x_0_0_0; /*list<string>*/
    }
    parts_0 = kk_std_os_path__unroll_push_parts_10000(parts_10171, _x_x1027, _ctx); /*list<string>*/
  }
  kk_string_t _x_x1028;
  {
    kk_string_t _x_1 = q.root;
    kk_string_dup(_x_1, _ctx);
    kk_std_os_path__path_drop(q, _ctx);
    _x_x1028 = _x_1; /*string*/
  }
  return kk_std_os_path__new_Path(_x_x1028, parts_0, _ctx);
}
 
// Return a list of all directory components (excluding the root but including the basename).
// `"/foo/bar/test.txt".path.dirparts === ["foo","bar","test.txt"]`

kk_std_core_types__list kk_std_os_path_dirparts(kk_std_os_path__path p, kk_context_t* _ctx) { /* (p : path) -> list<string> */ 
  {
    kk_std_core_types__list _x = p.parts;
    kk_std_core_types__list_dup(_x, _ctx);
    if (kk_std_core_types__is_Nil(_x, _ctx)) {
      kk_std_os_path__path_drop(p, _ctx);
      return kk_std_core_types__new_Nil(_ctx);
    }
    {
      kk_std_core_types__list_drop(_x, _ctx);
      kk_std_core_types__list _x_x1029;
      {
        kk_std_core_types__list _x_0 = p.parts;
        kk_std_core_types__list_dup(_x_0, _ctx);
        kk_std_os_path__path_drop(p, _ctx);
        _x_x1029 = _x_0; /*list<string>*/
      }
      return kk_std_core_list__unroll_reverse_acc_10003(kk_std_core_types__new_Nil(_ctx), _x_x1029, _ctx);
    }
  }
}
 
// Return the last directory component name (or the empty string).
// `"c:/foo/bar/tst.txt".path.parentname === "bar"

kk_string_t kk_std_os_path_parentname(kk_std_os_path__path p, kk_context_t* _ctx) { /* (p : path) -> string */ 
  {
    kk_std_core_types__list _x = p.parts;
    kk_std_core_types__list_dup(_x, _ctx);
    kk_std_os_path__path_drop(p, _ctx);
    kk_std_core_types__list _match_x450;
    if (kk_std_core_types__is_Cons(_x, _ctx)) {
      struct kk_std_core_types_Cons* _con_x1030 = kk_std_core_types__as_Cons(_x, _ctx);
      kk_box_t _box_x306 = _con_x1030->head;
      kk_std_core_types__list xx = _con_x1030->tail;
      kk_string_t _pat_0_1 = kk_string_unbox(_box_x306);
      if kk_likely(kk_datatype_ptr_is_unique(_x, _ctx)) {
        kk_string_drop(_pat_0_1, _ctx);
        kk_datatype_ptr_free(_x, _ctx);
      }
      else {
        kk_std_core_types__list_dup(xx, _ctx);
        kk_datatype_ptr_decref(_x, _ctx);
      }
      _match_x450 = xx; /*list<string>*/
    }
    else {
      _match_x450 = kk_std_core_types__new_Nil(_ctx); /*list<string>*/
    }
    if (kk_std_core_types__is_Cons(_match_x450, _ctx)) {
      struct kk_std_core_types_Cons* _con_x1031 = kk_std_core_types__as_Cons(_match_x450, _ctx);
      kk_box_t _box_x307 = _con_x1031->head;
      kk_std_core_types__list _pat_0_0 = _con_x1031->tail;
      kk_string_t x_0 = kk_string_unbox(_box_x307);
      if kk_likely(kk_datatype_ptr_is_unique(_match_x450, _ctx)) {
        kk_std_core_types__list_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(_match_x450, _ctx);
      }
      else {
        kk_string_dup(x_0, _ctx);
        kk_datatype_ptr_decref(_match_x450, _ctx);
      }
      return x_0;
    }
    {
      return kk_string_empty();
    }
  }
}

kk_string_t kk_std_os_path_xrealpath(kk_string_t p, kk_context_t* _ctx) { /* (p : string) -> io string */ 
  return kk_os_realpath(p,kk_context());
}
 
// monadic lift


// lift anonymous function
struct kk_std_os_path_string_fs__mlift_realpath_10404_fun1034__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_string_fs__mlift_realpath_10404_fun1034(kk_function_t _fself, kk_box_t _b_x311, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_string_fs__new_mlift_realpath_10404_fun1034(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_string_fs__mlift_realpath_10404_fun1034, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_path_string_fs__mlift_realpath_10404_fun1034(kk_function_t _fself, kk_box_t _b_x311, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_os_path__path _x_x1035;
  kk_string_t _x_x1036 = kk_string_unbox(_b_x311); /*string*/
  _x_x1035 = kk_std_os_path_path(_x_x1036, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x_x1035, _ctx);
}

kk_std_os_path__path kk_std_os_path_string_fs__mlift_realpath_10404(kk_string_t _y_x10346, kk_context_t* _ctx) { /* (string) -> io path */ 
  kk_box_t _x_x1033 = kk_std_core_hnd__open_none1(kk_std_os_path_string_fs__new_mlift_realpath_10404_fun1034(_ctx), kk_string_box(_y_x10346), _ctx); /*9924*/
  return kk_std_os_path__path_unbox(_x_x1033, KK_OWNED, _ctx);
}
 
// Convert a path to the absolute path on the file system.
// The overload on a plain string is necessary as it allows
// for unnormalized paths with `".."` parts. For example
// `"/foo/symlink/../test.txt"` may resolve to `"/bar/test.txt"` if
// ``symlink`` is a symbolic link to a sub directory of `"/bar"`.


// lift anonymous function
struct kk_std_os_path_string_fs_realpath_fun1038__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_string_fs_realpath_fun1038(kk_function_t _fself, kk_box_t _b_x315, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_string_fs_new_realpath_fun1038(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_string_fs_realpath_fun1038, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_path_string_fs_realpath_fun1038(kk_function_t _fself, kk_box_t _b_x315, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_os_path__path _x_x1039;
  kk_string_t _x_x1040 = kk_string_unbox(_b_x315); /*string*/
  _x_x1039 = kk_std_os_path_string_fs__mlift_realpath_10404(_x_x1040, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x_x1039, _ctx);
}


// lift anonymous function
struct kk_std_os_path_string_fs_realpath_fun1041__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_string_fs_realpath_fun1041(kk_function_t _fself, kk_box_t _b_x318, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_string_fs_new_realpath_fun1041(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_string_fs_realpath_fun1041, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_path_string_fs_realpath_fun1041(kk_function_t _fself, kk_box_t _b_x318, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_os_path__path _x_x1042;
  kk_string_t _x_x1043 = kk_string_unbox(_b_x318); /*string*/
  _x_x1042 = kk_std_os_path_path(_x_x1043, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x_x1042, _ctx);
}

kk_std_os_path__path kk_std_os_path_string_fs_realpath(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> io path */ 
  kk_string_t x_10481 = kk_std_os_path_xrealpath(s, _ctx); /*string*/;
  kk_box_t _x_x1037;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_10481, _ctx);
    _x_x1037 = kk_std_core_hnd_yield_extend(kk_std_os_path_string_fs_new_realpath_fun1038(_ctx), _ctx); /*2419*/
  }
  else {
    _x_x1037 = kk_std_core_hnd__open_none1(kk_std_os_path_string_fs_new_realpath_fun1041(_ctx), kk_string_box(x_10481), _ctx); /*2419*/
  }
  return kk_std_os_path__path_unbox(_x_x1037, KK_OWNED, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_os_path__mlift_realpath_10405_fun1045__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path__mlift_realpath_10405_fun1045(kk_function_t _fself, kk_box_t _b_x324, kk_context_t* _ctx);
static kk_function_t kk_std_os_path__new_mlift_realpath_10405_fun1045(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path__mlift_realpath_10405_fun1045, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_path__mlift_realpath_10405_fun1045(kk_function_t _fself, kk_box_t _b_x324, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_os_path__path _x_x1046;
  kk_string_t _x_x1047 = kk_string_unbox(_b_x324); /*string*/
  _x_x1046 = kk_std_os_path_path(_x_x1047, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x_x1046, _ctx);
}

kk_std_os_path__path kk_std_os_path__mlift_realpath_10405(kk_string_t _y_x10347, kk_context_t* _ctx) { /* (string) -> io path */ 
  kk_box_t _x_x1044 = kk_std_core_hnd__open_none1(kk_std_os_path__new_mlift_realpath_10405_fun1045(_ctx), kk_string_box(_y_x10347), _ctx); /*9924*/
  return kk_std_os_path__path_unbox(_x_x1044, KK_OWNED, _ctx);
}
 
// Convert a path to the absolute path on the file system.
// The path is not required to exist on disk. However, if it
// exists any permissions and symbolic links are resolved fully.
// `".".realpath` (to get the current working directory)
// `"/foo".realpath` (to resolve the full root, like `"c:/foo"` on windows)


// lift anonymous function
struct kk_std_os_path_realpath_fun1049__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_realpath_fun1049(kk_function_t _fself, kk_box_t _b_x329, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_realpath_fun1049(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_realpath_fun1049, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_path_realpath_fun1049(kk_function_t _fself, kk_box_t _b_x329, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1050;
  kk_std_os_path__path _x_x1051 = kk_std_os_path__path_unbox(_b_x329, KK_OWNED, _ctx); /*std/os/path/path*/
  _x_x1050 = kk_std_os_path_string(_x_x1051, _ctx); /*string*/
  return kk_string_box(_x_x1050);
}


// lift anonymous function
struct kk_std_os_path_realpath_fun1053__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_realpath_fun1053(kk_function_t _fself, kk_box_t _b_x333, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_realpath_fun1053(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_realpath_fun1053, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_path_realpath_fun1053(kk_function_t _fself, kk_box_t _b_x333, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_os_path__path _x_x1054;
  kk_string_t _x_x1055 = kk_string_unbox(_b_x333); /*string*/
  _x_x1054 = kk_std_os_path__mlift_realpath_10405(_x_x1055, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x_x1054, _ctx);
}


// lift anonymous function
struct kk_std_os_path_realpath_fun1056__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_realpath_fun1056(kk_function_t _fself, kk_box_t _b_x336, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_realpath_fun1056(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_realpath_fun1056, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_path_realpath_fun1056(kk_function_t _fself, kk_box_t _b_x336, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_os_path__path _x_x1057;
  kk_string_t _x_x1058 = kk_string_unbox(_b_x336); /*string*/
  _x_x1057 = kk_std_os_path_path(_x_x1058, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x_x1057, _ctx);
}

kk_std_os_path__path kk_std_os_path_realpath(kk_std_os_path__path p, kk_context_t* _ctx) { /* (p : path) -> io path */ 
  kk_string_t s_10184;
  kk_box_t _x_x1048 = kk_std_core_hnd__open_none1(kk_std_os_path_new_realpath_fun1049(_ctx), kk_std_os_path__path_box(p, _ctx), _ctx); /*9924*/
  s_10184 = kk_string_unbox(_x_x1048); /*string*/
  kk_string_t x_10484 = kk_std_os_path_xrealpath(s_10184, _ctx); /*string*/;
  kk_box_t _x_x1052;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_10484, _ctx);
    _x_x1052 = kk_std_core_hnd_yield_extend(kk_std_os_path_new_realpath_fun1053(_ctx), _ctx); /*2419*/
  }
  else {
    _x_x1052 = kk_std_core_hnd__open_none1(kk_std_os_path_new_realpath_fun1056(_ctx), kk_string_box(x_10484), _ctx); /*2419*/
  }
  return kk_std_os_path__path_unbox(_x_x1052, KK_OWNED, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_os_path__mlift_cwd_10406_fun1060__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path__mlift_cwd_10406_fun1060(kk_function_t _fself, kk_box_t _b_x342, kk_context_t* _ctx);
static kk_function_t kk_std_os_path__new_mlift_cwd_10406_fun1060(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path__mlift_cwd_10406_fun1060, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_path__mlift_cwd_10406_fun1060(kk_function_t _fself, kk_box_t _b_x342, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_os_path__path _x_x1061;
  kk_string_t _x_x1062 = kk_string_unbox(_b_x342); /*string*/
  _x_x1061 = kk_std_os_path_path(_x_x1062, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x_x1061, _ctx);
}

kk_std_os_path__path kk_std_os_path__mlift_cwd_10406(kk_string_t _y_x10348, kk_context_t* _ctx) { /* (string) -> io path */ 
  kk_box_t _x_x1059 = kk_std_core_hnd__open_none1(kk_std_os_path__new_mlift_cwd_10406_fun1060(_ctx), kk_string_box(_y_x10348), _ctx); /*9924*/
  return kk_std_os_path__path_unbox(_x_x1059, KK_OWNED, _ctx);
}
 
// Returns the current working directory.
// Equal to `".".realpath`.


// lift anonymous function
struct kk_std_os_path_cwd_fun1066__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_cwd_fun1066(kk_function_t _fself, kk_box_t _b_x346, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_cwd_fun1066(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_cwd_fun1066, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_path_cwd_fun1066(kk_function_t _fself, kk_box_t _b_x346, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_os_path__path _x_x1067;
  kk_string_t _x_x1068 = kk_string_unbox(_b_x346); /*string*/
  _x_x1067 = kk_std_os_path__mlift_cwd_10406(_x_x1068, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x_x1067, _ctx);
}


// lift anonymous function
struct kk_std_os_path_cwd_fun1069__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_cwd_fun1069(kk_function_t _fself, kk_box_t _b_x349, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_cwd_fun1069(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_cwd_fun1069, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_path_cwd_fun1069(kk_function_t _fself, kk_box_t _b_x349, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_os_path__path _x_x1070;
  kk_string_t _x_x1071 = kk_string_unbox(_b_x349); /*string*/
  _x_x1070 = kk_std_os_path_path(_x_x1071, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x_x1070, _ctx);
}

kk_std_os_path__path kk_std_os_path_cwd(kk_context_t* _ctx) { /* () -> io path */ 
  kk_string_t x_10487;
  kk_string_t _x_x1063;
  kk_define_string_literal(static, _s_x1064, 1, ".", _ctx)
  _x_x1063 = kk_string_dup(_s_x1064, _ctx); /*string*/
  x_10487 = kk_std_os_path_xrealpath(_x_x1063, _ctx); /*string*/
  kk_box_t _x_x1065;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_10487, _ctx);
    _x_x1065 = kk_std_core_hnd_yield_extend(kk_std_os_path_new_cwd_fun1066(_ctx), _ctx); /*2419*/
  }
  else {
    _x_x1065 = kk_std_core_hnd__open_none1(kk_std_os_path_new_cwd_fun1069(_ctx), kk_string_box(x_10487), _ctx); /*2419*/
  }
  return kk_std_os_path__path_unbox(_x_x1065, KK_OWNED, _ctx);
}
 
// Return the OS specific directory separator (`"/"` or `"\\"`)

kk_string_t kk_std_os_path_partsep(kk_context_t* _ctx) { /* () -> ndet string */ 
  return kk_os_dir_sep(kk_context());
}
 
// Return the OS specific path separator (`';'` or `':'`)

kk_string_t kk_std_os_path_pathsep(kk_context_t* _ctx) { /* () -> ndet string */ 
  return kk_os_path_sep(kk_context());
}

kk_string_t kk_std_os_path_xapp_path(kk_context_t* _ctx) { /* () -> io string */ 
  return kk_os_app_path(kk_context());
}
 
// monadic lift


// lift anonymous function
struct kk_std_os_path__mlift_app_path_10407_fun1073__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path__mlift_app_path_10407_fun1073(kk_function_t _fself, kk_box_t _b_x355, kk_context_t* _ctx);
static kk_function_t kk_std_os_path__new_mlift_app_path_10407_fun1073(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path__mlift_app_path_10407_fun1073, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_path__mlift_app_path_10407_fun1073(kk_function_t _fself, kk_box_t _b_x355, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_os_path__path _x_x1074;
  kk_string_t _x_x1075 = kk_string_unbox(_b_x355); /*string*/
  _x_x1074 = kk_std_os_path_path(_x_x1075, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x_x1074, _ctx);
}

kk_std_os_path__path kk_std_os_path__mlift_app_path_10407(kk_string_t _y_x10350, kk_context_t* _ctx) { /* (string) -> io path */ 
  kk_box_t _x_x1072 = kk_std_core_hnd__open_none1(kk_std_os_path__new_mlift_app_path_10407_fun1073(_ctx), kk_string_box(_y_x10350), _ctx); /*9924*/
  return kk_std_os_path__path_unbox(_x_x1072, KK_OWNED, _ctx);
}
 
// Return the path to the currently executing application.


// lift anonymous function
struct kk_std_os_path_app_path_fun1077__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_app_path_fun1077(kk_function_t _fself, kk_box_t _b_x359, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_app_path_fun1077(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_app_path_fun1077, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_path_app_path_fun1077(kk_function_t _fself, kk_box_t _b_x359, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_os_path__path _x_x1078;
  kk_string_t _x_x1079 = kk_string_unbox(_b_x359); /*string*/
  _x_x1078 = kk_std_os_path__mlift_app_path_10407(_x_x1079, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x_x1078, _ctx);
}


// lift anonymous function
struct kk_std_os_path_app_path_fun1080__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_app_path_fun1080(kk_function_t _fself, kk_box_t _b_x362, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_app_path_fun1080(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_app_path_fun1080, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_path_app_path_fun1080(kk_function_t _fself, kk_box_t _b_x362, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_os_path__path _x_x1081;
  kk_string_t _x_x1082 = kk_string_unbox(_b_x362); /*string*/
  _x_x1081 = kk_std_os_path_path(_x_x1082, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x_x1081, _ctx);
}

kk_std_os_path__path kk_std_os_path_app_path(kk_context_t* _ctx) { /* () -> io path */ 
  kk_string_t x_10490 = kk_std_os_path_xapp_path(_ctx); /*string*/;
  kk_box_t _x_x1076;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_10490, _ctx);
    _x_x1076 = kk_std_core_hnd_yield_extend(kk_std_os_path_new_app_path_fun1077(_ctx), _ctx); /*2419*/
  }
  else {
    _x_x1076 = kk_std_core_hnd__open_none1(kk_std_os_path_new_app_path_fun1080(_ctx), kk_string_box(x_10490), _ctx); /*2419*/
  }
  return kk_std_os_path__path_unbox(_x_x1076, KK_OWNED, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_std_os_path__mlift_appdir_10408_fun1084__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path__mlift_appdir_10408_fun1084(kk_function_t _fself, kk_box_t _b_x368, kk_context_t* _ctx);
static kk_function_t kk_std_os_path__new_mlift_appdir_10408_fun1084(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path__mlift_appdir_10408_fun1084, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_path__mlift_appdir_10408_fun1084(kk_function_t _fself, kk_box_t _b_x368, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_os_path__path _x_x1085;
  kk_string_t _x_x1086 = kk_string_unbox(_b_x368); /*string*/
  _x_x1085 = kk_std_os_path_path(_x_x1086, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x_x1085, _ctx);
}


// lift anonymous function
struct kk_std_os_path__mlift_appdir_10408_fun1096__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path__mlift_appdir_10408_fun1096(kk_function_t _fself, kk_box_t _b_x377, kk_context_t* _ctx);
static kk_function_t kk_std_os_path__new_mlift_appdir_10408_fun1096(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path__mlift_appdir_10408_fun1096, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_path__mlift_appdir_10408_fun1096(kk_function_t _fself, kk_box_t _b_x377, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_os_path__path _x_x1097;
  kk_std_os_path__path _x_x1098 = kk_std_os_path__path_unbox(_b_x377, KK_OWNED, _ctx); /*std/os/path/path*/
  _x_x1097 = kk_std_os_path_nobase(_x_x1098, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x_x1097, _ctx);
}


// lift anonymous function
struct kk_std_os_path__mlift_appdir_10408_fun1105__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path__mlift_appdir_10408_fun1105(kk_function_t _fself, kk_box_t _b_x382, kk_context_t* _ctx);
static kk_function_t kk_std_os_path__new_mlift_appdir_10408_fun1105(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path__mlift_appdir_10408_fun1105, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_path__mlift_appdir_10408_fun1105(kk_function_t _fself, kk_box_t _b_x382, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_os_path__path _x_x1106;
  kk_std_os_path__path _x_x1107 = kk_std_os_path__path_unbox(_b_x382, KK_OWNED, _ctx); /*std/os/path/path*/
  _x_x1106 = kk_std_os_path_nobase(_x_x1107, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x_x1106, _ctx);
}

kk_std_os_path__path kk_std_os_path__mlift_appdir_10408(kk_string_t _y_x10351, kk_context_t* _ctx) { /* (string) -> io path */ 
  kk_std_os_path__path _x_x1_10376;
  kk_box_t _x_x1083 = kk_std_core_hnd__open_none1(kk_std_os_path__new_mlift_appdir_10408_fun1084(_ctx), kk_string_box(_y_x10351), _ctx); /*9924*/
  _x_x1_10376 = kk_std_os_path__path_unbox(_x_x1083, KK_OWNED, _ctx); /*std/os/path/path*/
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_std_os_path__path x;
  kk_string_t _x_x1087;
  kk_std_core_types__optional _match_x445 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
  if (kk_std_core_types__is_Optional(_match_x445, _ctx)) {
    kk_box_t _box_x371 = _match_x445._cons._Optional.value;
    kk_string_t _uniq_root_128 = kk_string_unbox(_box_x371);
    kk_string_dup(_uniq_root_128, _ctx);
    kk_std_core_types__optional_drop(_match_x445, _ctx);
    _x_x1087 = _uniq_root_128; /*string*/
  }
  else {
    kk_std_core_types__optional_drop(_match_x445, _ctx);
    {
      kk_string_t _x_0 = _x_x1_10376.root;
      kk_string_dup(_x_0, _ctx);
      _x_x1087 = _x_0; /*string*/
    }
  }
  kk_std_core_types__list _x_x1088;
  {
    kk_std_core_types__list _x = _x_x1_10376.parts;
    kk_std_core_types__list_dup(_x, _ctx);
    kk_std_os_path__path_drop(_x_x1_10376, _ctx);
    if (kk_std_core_types__is_Cons(_x, _ctx)) {
      struct kk_std_core_types_Cons* _con_x1089 = kk_std_core_types__as_Cons(_x, _ctx);
      kk_box_t _box_x372 = _con_x1089->head;
      kk_std_core_types__list xx = _con_x1089->tail;
      kk_string_t _pat_0 = kk_string_unbox(_box_x372);
      if kk_likely(kk_datatype_ptr_is_unique(_x, _ctx)) {
        kk_string_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(_x, _ctx);
      }
      else {
        kk_std_core_types__list_dup(xx, _ctx);
        kk_datatype_ptr_decref(_x, _ctx);
      }
      _x_x1088 = xx; /*list<string>*/
    }
    else {
      _x_x1088 = kk_std_core_types__new_Nil(_ctx); /*list<string>*/
    }
  }
  x = kk_std_os_path__new_Path(_x_x1087, _x_x1088, _ctx); /*std/os/path/path*/
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_unit_t keep_0 = kk_Unit;
  kk_evv_set(w_0,kk_context());
  bool _match_x443;
  kk_string_t _x_x1090;
  {
    kk_std_core_types__list _x_1 = x.parts;
    kk_std_core_types__list_dup(_x_1, _ctx);
    if (kk_std_core_types__is_Cons(_x_1, _ctx)) {
      struct kk_std_core_types_Cons* _con_x1091 = kk_std_core_types__as_Cons(_x_1, _ctx);
      kk_box_t _box_x373 = _con_x1091->head;
      kk_std_core_types__list _pat_0_0_0 = _con_x1091->tail;
      kk_string_t x_0_0 = kk_string_unbox(_box_x373);
      if kk_likely(kk_datatype_ptr_is_unique(_x_1, _ctx)) {
        kk_std_core_types__list_drop(_pat_0_0_0, _ctx);
        kk_datatype_ptr_free(_x_1, _ctx);
      }
      else {
        kk_string_dup(x_0_0, _ctx);
        kk_datatype_ptr_decref(_x_1, _ctx);
      }
      _x_x1090 = x_0_0; /*string*/
    }
    else {
      _x_x1090 = kk_string_empty(); /*string*/
    }
  }
  kk_string_t _x_x1093;
  kk_define_string_literal(static, _s_x1094, 3, "bin", _ctx)
  _x_x1093 = kk_string_dup(_s_x1094, _ctx); /*string*/
  _match_x443 = kk_string_is_eq(_x_x1090,_x_x1093,kk_context()); /*bool*/
  if (_match_x443) {
    kk_box_t _x_x1095 = kk_std_core_hnd__open_none1(kk_std_os_path__new_mlift_appdir_10408_fun1096(_ctx), kk_std_os_path__path_box(x, _ctx), _ctx); /*9924*/
    return kk_std_os_path__path_unbox(_x_x1095, KK_OWNED, _ctx);
  }
  {
    kk_evv_t w_1 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
    kk_unit_t keep_1 = kk_Unit;
    kk_evv_set(w_1,kk_context());
    bool _match_x444;
    kk_string_t _x_x1099;
    {
      kk_std_core_types__list _x_2 = x.parts;
      kk_std_core_types__list_dup(_x_2, _ctx);
      if (kk_std_core_types__is_Cons(_x_2, _ctx)) {
        struct kk_std_core_types_Cons* _con_x1100 = kk_std_core_types__as_Cons(_x_2, _ctx);
        kk_box_t _box_x378 = _con_x1100->head;
        kk_std_core_types__list _pat_0_0_1 = _con_x1100->tail;
        kk_string_t x_0_0_0 = kk_string_unbox(_box_x378);
        if kk_likely(kk_datatype_ptr_is_unique(_x_2, _ctx)) {
          kk_std_core_types__list_drop(_pat_0_0_1, _ctx);
          kk_datatype_ptr_free(_x_2, _ctx);
        }
        else {
          kk_string_dup(x_0_0_0, _ctx);
          kk_datatype_ptr_decref(_x_2, _ctx);
        }
        _x_x1099 = x_0_0_0; /*string*/
      }
      else {
        _x_x1099 = kk_string_empty(); /*string*/
      }
    }
    kk_string_t _x_x1102;
    kk_define_string_literal(static, _s_x1103, 3, "exe", _ctx)
    _x_x1102 = kk_string_dup(_s_x1103, _ctx); /*string*/
    _match_x444 = kk_string_is_eq(_x_x1099,_x_x1102,kk_context()); /*bool*/
    if (_match_x444) {
      kk_box_t _x_x1104 = kk_std_core_hnd__open_none1(kk_std_os_path__new_mlift_appdir_10408_fun1105(_ctx), kk_std_os_path__path_box(x, _ctx), _ctx); /*9924*/
      return kk_std_os_path__path_unbox(_x_x1104, KK_OWNED, _ctx);
    }
    {
      return x;
    }
  }
}
 
// Return the base directory that contains the currently running application.
// First tries `app-path().nobase`; if that ends in the ``bin`` or ``exe`` directory it
// returns the parent of that directory.


// lift anonymous function
struct kk_std_os_path_appdir_fun1109__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_appdir_fun1109(kk_function_t _fself, kk_box_t _b_x388, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_appdir_fun1109(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_appdir_fun1109, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_path_appdir_fun1109(kk_function_t _fself, kk_box_t _b_x388, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_os_path__path _x_x1110;
  kk_string_t _x_x1111 = kk_string_unbox(_b_x388); /*string*/
  _x_x1110 = kk_std_os_path__mlift_appdir_10408(_x_x1111, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x_x1110, _ctx);
}


// lift anonymous function
struct kk_std_os_path_appdir_fun1113__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_appdir_fun1113(kk_function_t _fself, kk_box_t _b_x391, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_appdir_fun1113(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_appdir_fun1113, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_path_appdir_fun1113(kk_function_t _fself, kk_box_t _b_x391, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_os_path__path _x_x1114;
  kk_string_t _x_x1115 = kk_string_unbox(_b_x391); /*string*/
  _x_x1114 = kk_std_os_path_path(_x_x1115, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x_x1114, _ctx);
}


// lift anonymous function
struct kk_std_os_path_appdir_fun1125__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_appdir_fun1125(kk_function_t _fself, kk_box_t _b_x400, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_appdir_fun1125(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_appdir_fun1125, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_path_appdir_fun1125(kk_function_t _fself, kk_box_t _b_x400, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_os_path__path _x_x1126;
  kk_std_os_path__path _x_x1127 = kk_std_os_path__path_unbox(_b_x400, KK_OWNED, _ctx); /*std/os/path/path*/
  _x_x1126 = kk_std_os_path_nobase(_x_x1127, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x_x1126, _ctx);
}


// lift anonymous function
struct kk_std_os_path_appdir_fun1134__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_appdir_fun1134(kk_function_t _fself, kk_box_t _b_x405, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_appdir_fun1134(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_appdir_fun1134, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_path_appdir_fun1134(kk_function_t _fself, kk_box_t _b_x405, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_os_path__path _x_x1135;
  kk_std_os_path__path _x_x1136 = kk_std_os_path__path_unbox(_b_x405, KK_OWNED, _ctx); /*std/os/path/path*/
  _x_x1135 = kk_std_os_path_nobase(_x_x1136, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x_x1135, _ctx);
}

kk_std_os_path__path kk_std_os_path_appdir(kk_context_t* _ctx) { /* () -> io path */ 
  kk_string_t x_10499 = kk_std_os_path_xapp_path(_ctx); /*string*/;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_10499, _ctx);
    kk_box_t _x_x1108 = kk_std_core_hnd_yield_extend(kk_std_os_path_new_appdir_fun1109(_ctx), _ctx); /*2419*/
    return kk_std_os_path__path_unbox(_x_x1108, KK_OWNED, _ctx);
  }
  {
    kk_std_os_path__path _x_x1_10376;
    kk_box_t _x_x1112 = kk_std_core_hnd__open_none1(kk_std_os_path_new_appdir_fun1113(_ctx), kk_string_box(x_10499), _ctx); /*9924*/
    _x_x1_10376 = kk_std_os_path__path_unbox(_x_x1112, KK_OWNED, _ctx); /*std/os/path/path*/
    kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
    kk_std_os_path__path x_0;
    kk_string_t _x_x1116;
    kk_std_core_types__optional _match_x442 = kk_std_core_types__new_None(_ctx); /*forall<a> ? a*/;
    if (kk_std_core_types__is_Optional(_match_x442, _ctx)) {
      kk_box_t _box_x394 = _match_x442._cons._Optional.value;
      kk_string_t _uniq_root_128 = kk_string_unbox(_box_x394);
      kk_string_dup(_uniq_root_128, _ctx);
      kk_std_core_types__optional_drop(_match_x442, _ctx);
      _x_x1116 = _uniq_root_128; /*string*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x442, _ctx);
      {
        kk_string_t _x_0 = _x_x1_10376.root;
        kk_string_dup(_x_0, _ctx);
        _x_x1116 = _x_0; /*string*/
      }
    }
    kk_std_core_types__list _x_x1117;
    {
      kk_std_core_types__list _x = _x_x1_10376.parts;
      kk_std_core_types__list_dup(_x, _ctx);
      kk_std_os_path__path_drop(_x_x1_10376, _ctx);
      if (kk_std_core_types__is_Cons(_x, _ctx)) {
        struct kk_std_core_types_Cons* _con_x1118 = kk_std_core_types__as_Cons(_x, _ctx);
        kk_box_t _box_x395 = _con_x1118->head;
        kk_std_core_types__list xx = _con_x1118->tail;
        kk_string_t _pat_0_3 = kk_string_unbox(_box_x395);
        if kk_likely(kk_datatype_ptr_is_unique(_x, _ctx)) {
          kk_string_drop(_pat_0_3, _ctx);
          kk_datatype_ptr_free(_x, _ctx);
        }
        else {
          kk_std_core_types__list_dup(xx, _ctx);
          kk_datatype_ptr_decref(_x, _ctx);
        }
        _x_x1117 = xx; /*list<string>*/
      }
      else {
        _x_x1117 = kk_std_core_types__new_Nil(_ctx); /*list<string>*/
      }
    }
    x_0 = kk_std_os_path__new_Path(_x_x1116, _x_x1117, _ctx); /*std/os/path/path*/
    kk_unit_t keep = kk_Unit;
    kk_evv_set(w,kk_context());
    kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
    kk_unit_t keep_0 = kk_Unit;
    kk_evv_set(w_0,kk_context());
    bool _match_x440;
    kk_string_t _x_x1119;
    {
      kk_std_core_types__list _x_1 = x_0.parts;
      kk_std_core_types__list_dup(_x_1, _ctx);
      if (kk_std_core_types__is_Cons(_x_1, _ctx)) {
        struct kk_std_core_types_Cons* _con_x1120 = kk_std_core_types__as_Cons(_x_1, _ctx);
        kk_box_t _box_x396 = _con_x1120->head;
        kk_std_core_types__list _pat_0_0_0 = _con_x1120->tail;
        kk_string_t x_0_0 = kk_string_unbox(_box_x396);
        if kk_likely(kk_datatype_ptr_is_unique(_x_1, _ctx)) {
          kk_std_core_types__list_drop(_pat_0_0_0, _ctx);
          kk_datatype_ptr_free(_x_1, _ctx);
        }
        else {
          kk_string_dup(x_0_0, _ctx);
          kk_datatype_ptr_decref(_x_1, _ctx);
        }
        _x_x1119 = x_0_0; /*string*/
      }
      else {
        _x_x1119 = kk_string_empty(); /*string*/
      }
    }
    kk_string_t _x_x1122;
    kk_define_string_literal(static, _s_x1123, 3, "bin", _ctx)
    _x_x1122 = kk_string_dup(_s_x1123, _ctx); /*string*/
    _match_x440 = kk_string_is_eq(_x_x1119,_x_x1122,kk_context()); /*bool*/
    if (_match_x440) {
      kk_box_t _x_x1124 = kk_std_core_hnd__open_none1(kk_std_os_path_new_appdir_fun1125(_ctx), kk_std_os_path__path_box(x_0, _ctx), _ctx); /*9924*/
      return kk_std_os_path__path_unbox(_x_x1124, KK_OWNED, _ctx);
    }
    {
      kk_evv_t w_1 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
      kk_unit_t keep_1 = kk_Unit;
      kk_evv_set(w_1,kk_context());
      bool _match_x441;
      kk_string_t _x_x1128;
      {
        kk_std_core_types__list _x_2 = x_0.parts;
        kk_std_core_types__list_dup(_x_2, _ctx);
        if (kk_std_core_types__is_Cons(_x_2, _ctx)) {
          struct kk_std_core_types_Cons* _con_x1129 = kk_std_core_types__as_Cons(_x_2, _ctx);
          kk_box_t _box_x401 = _con_x1129->head;
          kk_std_core_types__list _pat_0_0_1 = _con_x1129->tail;
          kk_string_t x_0_0_0 = kk_string_unbox(_box_x401);
          if kk_likely(kk_datatype_ptr_is_unique(_x_2, _ctx)) {
            kk_std_core_types__list_drop(_pat_0_0_1, _ctx);
            kk_datatype_ptr_free(_x_2, _ctx);
          }
          else {
            kk_string_dup(x_0_0_0, _ctx);
            kk_datatype_ptr_decref(_x_2, _ctx);
          }
          _x_x1128 = x_0_0_0; /*string*/
        }
        else {
          _x_x1128 = kk_string_empty(); /*string*/
        }
      }
      kk_string_t _x_x1131;
      kk_define_string_literal(static, _s_x1132, 3, "exe", _ctx)
      _x_x1131 = kk_string_dup(_s_x1132, _ctx); /*string*/
      _match_x441 = kk_string_is_eq(_x_x1128,_x_x1131,kk_context()); /*bool*/
      if (_match_x441) {
        kk_box_t _x_x1133 = kk_std_core_hnd__open_none1(kk_std_os_path_new_appdir_fun1134(_ctx), kk_std_os_path__path_box(x_0, _ctx), _ctx); /*9924*/
        return kk_std_os_path__path_unbox(_x_x1133, KK_OWNED, _ctx);
      }
      {
        return x_0;
      }
    }
  }
}

kk_string_t kk_std_os_path_xhomedir(kk_context_t* _ctx) { /* () -> io string */ 
  return kk_os_home_dir(kk_context());
}
 
// monadic lift


// lift anonymous function
struct kk_std_os_path__mlift_homedir_10409_fun1138__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path__mlift_homedir_10409_fun1138(kk_function_t _fself, kk_box_t _b_x413, kk_context_t* _ctx);
static kk_function_t kk_std_os_path__new_mlift_homedir_10409_fun1138(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path__mlift_homedir_10409_fun1138, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_path__mlift_homedir_10409_fun1138(kk_function_t _fself, kk_box_t _b_x413, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_os_path__path _x_x1139;
  kk_string_t _x_x1140 = kk_string_unbox(_b_x413); /*string*/
  _x_x1139 = kk_std_os_path_path(_x_x1140, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x_x1139, _ctx);
}

kk_std_os_path__path kk_std_os_path__mlift_homedir_10409(kk_string_t _y_x10355, kk_context_t* _ctx) { /* (string) -> io path */ 
  kk_box_t _x_x1137 = kk_std_core_hnd__open_none1(kk_std_os_path__new_mlift_homedir_10409_fun1138(_ctx), kk_string_box(_y_x10355), _ctx); /*9924*/
  return kk_std_os_path__path_unbox(_x_x1137, KK_OWNED, _ctx);
}
 
// Return the home directory of the current user.


// lift anonymous function
struct kk_std_os_path_homedir_fun1142__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_homedir_fun1142(kk_function_t _fself, kk_box_t _b_x417, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_homedir_fun1142(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_homedir_fun1142, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_path_homedir_fun1142(kk_function_t _fself, kk_box_t _b_x417, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_os_path__path _x_x1143;
  kk_string_t _x_x1144 = kk_string_unbox(_b_x417); /*string*/
  _x_x1143 = kk_std_os_path__mlift_homedir_10409(_x_x1144, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x_x1143, _ctx);
}


// lift anonymous function
struct kk_std_os_path_homedir_fun1145__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_homedir_fun1145(kk_function_t _fself, kk_box_t _b_x420, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_homedir_fun1145(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_homedir_fun1145, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_path_homedir_fun1145(kk_function_t _fself, kk_box_t _b_x420, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_os_path__path _x_x1146;
  kk_string_t _x_x1147 = kk_string_unbox(_b_x420); /*string*/
  _x_x1146 = kk_std_os_path_path(_x_x1147, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x_x1146, _ctx);
}

kk_std_os_path__path kk_std_os_path_homedir(kk_context_t* _ctx) { /* () -> io path */ 
  kk_string_t x_10508 = kk_std_os_path_xhomedir(_ctx); /*string*/;
  kk_box_t _x_x1141;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_10508, _ctx);
    _x_x1141 = kk_std_core_hnd_yield_extend(kk_std_os_path_new_homedir_fun1142(_ctx), _ctx); /*2419*/
  }
  else {
    _x_x1141 = kk_std_core_hnd__open_none1(kk_std_os_path_new_homedir_fun1145(_ctx), kk_string_box(x_10508), _ctx); /*2419*/
  }
  return kk_std_os_path__path_unbox(_x_x1141, KK_OWNED, _ctx);
}

kk_string_t kk_std_os_path_xtempdir(kk_context_t* _ctx) { /* () -> io string */ 
  return kk_os_temp_dir(kk_context());
}
 
// monadic lift


// lift anonymous function
struct kk_std_os_path__mlift_tempdir_10410_fun1149__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path__mlift_tempdir_10410_fun1149(kk_function_t _fself, kk_box_t _b_x426, kk_context_t* _ctx);
static kk_function_t kk_std_os_path__new_mlift_tempdir_10410_fun1149(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path__mlift_tempdir_10410_fun1149, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_path__mlift_tempdir_10410_fun1149(kk_function_t _fself, kk_box_t _b_x426, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_os_path__path _x_x1150;
  kk_string_t _x_x1151 = kk_string_unbox(_b_x426); /*string*/
  _x_x1150 = kk_std_os_path_path(_x_x1151, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x_x1150, _ctx);
}

kk_std_os_path__path kk_std_os_path__mlift_tempdir_10410(kk_string_t _y_x10357, kk_context_t* _ctx) { /* (string) -> io path */ 
  kk_box_t _x_x1148 = kk_std_core_hnd__open_none1(kk_std_os_path__new_mlift_tempdir_10410_fun1149(_ctx), kk_string_box(_y_x10357), _ctx); /*9924*/
  return kk_std_os_path__path_unbox(_x_x1148, KK_OWNED, _ctx);
}
 
// Return the temporary directory for the current user.


// lift anonymous function
struct kk_std_os_path_tempdir_fun1153__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_tempdir_fun1153(kk_function_t _fself, kk_box_t _b_x430, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_tempdir_fun1153(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_tempdir_fun1153, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_path_tempdir_fun1153(kk_function_t _fself, kk_box_t _b_x430, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_os_path__path _x_x1154;
  kk_string_t _x_x1155 = kk_string_unbox(_b_x430); /*string*/
  _x_x1154 = kk_std_os_path__mlift_tempdir_10410(_x_x1155, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x_x1154, _ctx);
}


// lift anonymous function
struct kk_std_os_path_tempdir_fun1156__t {
  struct kk_function_s _base;
};
static kk_box_t kk_std_os_path_tempdir_fun1156(kk_function_t _fself, kk_box_t _b_x433, kk_context_t* _ctx);
static kk_function_t kk_std_os_path_new_tempdir_fun1156(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_std_os_path_tempdir_fun1156, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_std_os_path_tempdir_fun1156(kk_function_t _fself, kk_box_t _b_x433, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_os_path__path _x_x1157;
  kk_string_t _x_x1158 = kk_string_unbox(_b_x433); /*string*/
  _x_x1157 = kk_std_os_path_path(_x_x1158, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x_x1157, _ctx);
}

kk_std_os_path__path kk_std_os_path_tempdir(kk_context_t* _ctx) { /* () -> io path */ 
  kk_string_t x_10511 = kk_std_os_path_xtempdir(_ctx); /*string*/;
  kk_box_t _x_x1152;
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_10511, _ctx);
    _x_x1152 = kk_std_core_hnd_yield_extend(kk_std_os_path_new_tempdir_fun1153(_ctx), _ctx); /*2419*/
  }
  else {
    _x_x1152 = kk_std_core_hnd__open_none1(kk_std_os_path_new_tempdir_fun1156(_ctx), kk_string_box(x_10511), _ctx); /*2419*/
  }
  return kk_std_os_path__path_unbox(_x_x1152, KK_OWNED, _ctx);
}

// initialization
void kk_std_os_path__init(kk_context_t* _ctx){
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
  kk_std_text_parse__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
}

// termination
void kk_std_os_path__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_std_text_parse__done(_ctx);
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
