// Koka generated module: nagare/core/types, koka version: 3.2.3, platform: 64-bit
#include "nagare_core_types.h"

kk_nagare_core_types__chunk kk_nagare_core_types_chunk_fs__copy(kk_nagare_core_types__chunk _this, kk_std_core_types__optional values, kk_context_t* _ctx) { /* forall<a> (chunk<a>, values : ? (list<a>)) -> chunk<a> */ 
  kk_std_core_types__list _x_x2;
  if (kk_std_core_types__is_Optional(values, _ctx)) {
    kk_box_t _box_x0 = values._cons._Optional.value;
    kk_std_core_types__list _uniq_values_115 = kk_std_core_types__list_unbox(_box_x0, KK_BORROWED, _ctx);
    kk_std_core_types__list_dup(_uniq_values_115, _ctx);
    kk_std_core_types__optional_drop(values, _ctx);
    kk_nagare_core_types__chunk_drop(_this, _ctx);
    _x_x2 = _uniq_values_115; /*list<130>*/
  }
  else {
    kk_std_core_types__optional_drop(values, _ctx);
    {
      kk_std_core_types__list _x = _this.values;
      _x_x2 = _x; /*list<130>*/
    }
  }
  return kk_nagare_core_types__new_Chunk(_x_x2, _ctx);
}

kk_nagare_core_types__nstream kk_nagare_core_types_nstream_fs__copy(kk_nagare_core_types__nstream _this, kk_std_core_types__optional step, kk_context_t* _ctx) { /* forall<a,e> (nstream<a,e>, step : ? (pull<a,e>)) -> nstream<a,e> */ 
  kk_nagare_core_types__pull _x_x6;
  if (kk_std_core_types__is_Optional(step, _ctx)) {
    kk_box_t _box_x1 = step._cons._Optional.value;
    kk_nagare_core_types__pull _uniq_step_277 = kk_nagare_core_types__pull_unbox(_box_x1, KK_BORROWED, _ctx);
    kk_nagare_core_types__pull_dup(_uniq_step_277, _ctx);
    kk_std_core_types__optional_drop(step, _ctx);
    kk_nagare_core_types__nstream_drop(_this, _ctx);
    _x_x6 = _uniq_step_277; /*nagare/core/types/pull<299,300>*/
  }
  else {
    kk_std_core_types__optional_drop(step, _ctx);
    {
      kk_nagare_core_types__pull _x = _this.step;
      _x_x6 = _x; /*nagare/core/types/pull<299,300>*/
    }
  }
  return kk_nagare_core_types__new_Stream(_x_x6, _ctx);
}

// initialization
void kk_nagare_core_types__init(kk_context_t* _ctx){
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
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
}

// termination
void kk_nagare_core_types__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
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
