// Koka generated module: nagare/io/file, koka version: 3.2.3, platform: 64-bit
#include "nagare_io_file.h"
 
// monadic lift


// lift anonymous function
struct kk_nagare_io_file__mlift_readPullBytes_10655_fun1149__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_io_file__mlift_readPullBytes_10655_fun1149(kk_function_t _fself, kk_box_t _b_x5, kk_box_t _b_x6, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__new_mlift_readPullBytes_10655_fun1149(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file__mlift_readPullBytes_10655_fun1149, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_io_file__mlift_readPullBytes_10655_fun1149(kk_function_t _fself, kk_box_t _b_x5, kk_box_t _b_x6, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_nagare_core_types__pull _x_x1150;
  kk_nagare_io_file__effect__read_handle _x_x1151 = kk_nagare_io_file__effect__read_handle_unbox(_b_x5, KK_OWNED, _ctx); /*nagare/io/file_effect/read-handle*/
  kk_integer_t _x_x1152 = kk_integer_unbox(_b_x6, _ctx); /*int*/
  _x_x1150 = kk_nagare_io_file_readPullBytes(_x_x1151, _x_x1152, _ctx); /*nagare/core/types/pull<nagare/io/file/bytes,<nagare/io/file_effect/fileRead|io>>*/
  return kk_nagare_core_types__pull_box(_x_x1150, _ctx);
}

kk_nagare_core_types__pull kk_nagare_io_file__mlift_readPullBytes_10655(kk_integer_t chunkSize, kk_nagare_io_file__effect__read_handle h, kk_vector_t chunk, kk_context_t* _ctx) { /* (chunkSize : int, h : nagare/io/file_effect/read-handle, chunk : vector<int8>) -> <nagare/io/file_effect/fileRead,div,alloc<global>,console/console,exn,fsys,ndet,net,read<global>,ui,write<global>> nagare/core/types/pull<bytes,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileRead,fsys,ndet,net,read<global>,ui,write<global>>> */ 
  bool _match_x1083;
  kk_integer_t _brw_x1084;
  kk_ssize_t _x_x1144 = kk_vector_len_borrow(chunk,kk_context()); /*ssize_t*/
  _brw_x1084 = kk_integer_from_ssize_t(_x_x1144,kk_context()); /*int*/
  bool _brw_x1085 = kk_integer_eq_borrow(_brw_x1084,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x1084, _ctx);
  _match_x1083 = _brw_x1085; /*bool*/
  if (_match_x1083) {
    kk_integer_drop(chunkSize, _ctx);
    kk_vector_drop(chunk, _ctx);
    return kk_nagare_core_types__new_PDone(_ctx);
  }
  {
    kk_nagare_core_types__chunk _x_x1145;
    kk_std_core_types__list _x_x1146 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_vector_box(chunk, _ctx), kk_std_core_types__new_Nil(_ctx), _ctx); /*list<10021>*/
    _x_x1145 = kk_nagare_core_types__new_Chunk(_x_x1146, _ctx); /*nagare/core/types/chunk<4>*/
    kk_nagare_core_types__pull _x_x1147;
    kk_box_t _x_x1148 = kk_std_core_hnd__open_none2(kk_nagare_io_file__new_mlift_readPullBytes_10655_fun1149(_ctx), kk_nagare_io_file__effect__read_handle_box(h, _ctx), kk_integer_box(chunkSize, _ctx), _ctx); /*10002*/
    _x_x1147 = kk_nagare_core_types__pull_unbox(_x_x1148, KK_OWNED, _ctx); /*nagare/core/types/pull<nagare/io/file/bytes,<nagare/io/file_effect/fileRead|io>>*/
    return kk_nagare_core_types__new_POutput(kk_reuse_null, 0, _x_x1145, _x_x1147, _ctx);
  }
}
 
// Loop reading byte chunks from an open read-handle until EOF.


// lift anonymous function
struct kk_nagare_io_file_readPullBytes_fun1153__t {
  struct kk_function_s _base;
  kk_integer_t chunkSize_0;
  kk_nagare_io_file__effect__read_handle h_0;
};
static kk_nagare_core_types__pull kk_nagare_io_file_readPullBytes_fun1153(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_readPullBytes_fun1153(kk_integer_t chunkSize_0, kk_nagare_io_file__effect__read_handle h_0, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readPullBytes_fun1153__t* _self = kk_function_alloc_as(struct kk_nagare_io_file_readPullBytes_fun1153__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file_readPullBytes_fun1153, kk_context());
  _self->chunkSize_0 = chunkSize_0;
  _self->h_0 = h_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_io_file_readPullBytes_fun1159__t {
  struct kk_function_s _base;
  kk_ssize_t i_10695;
};
static kk_box_t kk_nagare_io_file_readPullBytes_fun1159(kk_function_t _fself, kk_function_t _b_x27, kk_box_t _b_x28, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_readPullBytes_fun1159(kk_ssize_t i_10695, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readPullBytes_fun1159__t* _self = kk_function_alloc_as(struct kk_nagare_io_file_readPullBytes_fun1159__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file_readPullBytes_fun1159, kk_context());
  _self->i_10695 = i_10695;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file_readPullBytes_fun1159(kk_function_t _fself, kk_function_t _b_x27, kk_box_t _b_x28, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readPullBytes_fun1159__t* _self = kk_function_as(struct kk_nagare_io_file_readPullBytes_fun1159__t*, _fself, _ctx);
  kk_ssize_t i_10695 = _self->i_10695; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_10695, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_10695, _b_x27, _b_x28, _ctx);
}


// lift anonymous function
struct kk_nagare_io_file_readPullBytes_fun1161__t {
  struct kk_function_s _base;
  kk_integer_t chunkSize_0;
  kk_nagare_io_file__effect__read_handle h_0;
};
static kk_box_t kk_nagare_io_file_readPullBytes_fun1161(kk_function_t _fself, kk_box_t _b_x37, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_readPullBytes_fun1161(kk_integer_t chunkSize_0, kk_nagare_io_file__effect__read_handle h_0, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readPullBytes_fun1161__t* _self = kk_function_alloc_as(struct kk_nagare_io_file_readPullBytes_fun1161__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file_readPullBytes_fun1161, kk_context());
  _self->chunkSize_0 = chunkSize_0;
  _self->h_0 = h_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file_readPullBytes_fun1161(kk_function_t _fself, kk_box_t _b_x37, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readPullBytes_fun1161__t* _self = kk_function_as(struct kk_nagare_io_file_readPullBytes_fun1161__t*, _fself, _ctx);
  kk_integer_t chunkSize_0 = _self->chunkSize_0; /* int */
  kk_nagare_io_file__effect__read_handle h_0 = _self->h_0; /* nagare/io/file_effect/read-handle */
  kk_drop_match(_self, {kk_integer_dup(chunkSize_0, _ctx);kk_nagare_io_file__effect__read_handle_dup(h_0, _ctx);}, {}, _ctx)
  kk_vector_t chunk_0_40 = kk_vector_unbox(_b_x37, _ctx); /*vector<int8>*/;
  kk_nagare_core_types__pull _x_x1162 = kk_nagare_io_file__mlift_readPullBytes_10655(chunkSize_0, h_0, chunk_0_40, _ctx); /*nagare/core/types/pull<nagare/io/file/bytes,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileRead,fsys,ndet,net,read<global>,ui,write<global>>>*/
  return kk_nagare_core_types__pull_box(_x_x1162, _ctx);
}
static kk_nagare_core_types__pull kk_nagare_io_file_readPullBytes_fun1153(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readPullBytes_fun1153__t* _self = kk_function_as(struct kk_nagare_io_file_readPullBytes_fun1153__t*, _fself, _ctx);
  kk_integer_t chunkSize_0 = _self->chunkSize_0; /* int */
  kk_nagare_io_file__effect__read_handle h_0 = _self->h_0; /* nagare/io/file_effect/read-handle */
  kk_drop_match(_self, {kk_integer_dup(chunkSize_0, _ctx);kk_nagare_io_file__effect__read_handle_dup(h_0, _ctx);}, {}, _ctx)
  kk_ssize_t i_10695 = (KK_IZ(1)); /*hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_10695,kk_context()); /*hnd/evv<<nagare/io/file_effect/fileRead,div,alloc<global>,console/console,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_std_core_hnd__ev evx_10699 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<nagare/io/file_effect/fileRead>*/;
  kk_vector_t y;
  kk_box_t _x_x1154;
  {
    struct kk_std_core_hnd_Ev* _con_x1155 = kk_std_core_hnd__as_Ev(evx_10699, _ctx);
    kk_box_t _box_x12 = _con_x1155->hnd;
    int32_t m = _con_x1155->marker;
    kk_nagare_io_file__effect__fileRead h_1 = kk_nagare_io_file__effect__fileRead_unbox(_box_x12, KK_BORROWED, _ctx);
    kk_nagare_io_file__effect__fileRead_dup(h_1, _ctx);
    kk_std_core_hnd__clause2 _match_x1081;
    kk_std_core_hnd__clause2 _brw_x1082 = kk_nagare_io_file__effect_readChunkBytes_fs__select(h_1, _ctx); /*hnd/clause2<nagare/io/file_effect/read-handle,int,vector<int8>,nagare/io/file_effect/fileRead,1017,1018>*/;
    kk_datatype_ptr_dropn(h_1, (KK_I32(6)), _ctx);
    _match_x1081 = _brw_x1082; /*hnd/clause2<nagare/io/file_effect/read-handle,int,vector<int8>,nagare/io/file_effect/fileRead,1017,1018>*/
    {
      kk_function_t _fun_unbox_x17 = _match_x1081.clause;
      kk_box_t _x_x1156;
      kk_integer_t _x_x1157 = kk_integer_dup(chunkSize_0, _ctx); /*int*/
      _x_x1156 = kk_integer_box(_x_x1157, _ctx); /*10015*/
      _x_x1154 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_box_t, kk_context_t*), _fun_unbox_x17, (_fun_unbox_x17, m, evx_10699, kk_nagare_io_file__effect__read_handle_box(h_0, _ctx), _x_x1156, _ctx), _ctx); /*10016*/
    }
  }
  y = kk_vector_unbox(_x_x1154, _ctx); /*vector<int8>*/
  kk_evv_set(w,kk_context());
  kk_vector_t x_10693;
  if (kk_yielding(kk_context())) {
    kk_vector_drop(y, _ctx);
    kk_box_t _x_x1158 = kk_std_core_hnd_yield_cont(kk_nagare_io_file_new_readPullBytes_fun1159(i_10695, _ctx), _ctx); /*10002*/
    x_10693 = kk_vector_unbox(_x_x1158, _ctx); /*vector<int8>*/
  }
  else {
    x_10693 = y; /*vector<int8>*/
  }
  if (kk_yielding(kk_context())) {
    kk_vector_drop(x_10693, _ctx);
    kk_box_t _x_x1160 = kk_std_core_hnd_yield_extend(kk_nagare_io_file_new_readPullBytes_fun1161(chunkSize_0, h_0, _ctx), _ctx); /*10001*/
    return kk_nagare_core_types__pull_unbox(_x_x1160, KK_OWNED, _ctx);
  }
  {
    return kk_nagare_io_file__mlift_readPullBytes_10655(chunkSize_0, h_0, x_10693, _ctx);
  }
}

kk_nagare_core_types__pull kk_nagare_io_file_readPullBytes(kk_nagare_io_file__effect__read_handle h_0, kk_integer_t chunkSize_0, kk_context_t* _ctx) { /* (h : nagare/io/file_effect/read-handle, chunkSize : int) -> div nagare/core/types/pull<bytes,<nagare/io/file_effect/fileRead|io>> */ 
  return kk_nagare_core_types__new_PEval(kk_reuse_null, 0, kk_nagare_io_file_new_readPullBytes_fun1153(chunkSize_0, h_0, _ctx), _ctx);
}
 
// Read a file as a truly lazy stream of byte chunks (resource-safe, one chunk at a time).


// lift anonymous function
struct kk_nagare_io_file_readAllStreamingBytes_fun1166__t {
  struct kk_function_s _base;
  kk_std_core_types__optional chunkSize;
  kk_std_os_path__path filepath;
};
static kk_nagare_core_types__pull kk_nagare_io_file_readAllStreamingBytes_fun1166(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_readAllStreamingBytes_fun1166(kk_std_core_types__optional chunkSize, kk_std_os_path__path filepath, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readAllStreamingBytes_fun1166__t* _self = kk_function_alloc_as(struct kk_nagare_io_file_readAllStreamingBytes_fun1166__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file_readAllStreamingBytes_fun1166, kk_context());
  _self->chunkSize = chunkSize;
  _self->filepath = filepath;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_io_file_readAllStreamingBytes_fun1168__t {
  struct kk_function_s _base;
  kk_std_os_path__path filepath;
  kk_ref_t hRef;
};
static kk_unit_t kk_nagare_io_file_readAllStreamingBytes_fun1168(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_readAllStreamingBytes_fun1168(kk_std_os_path__path filepath, kk_ref_t hRef, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readAllStreamingBytes_fun1168__t* _self = kk_function_alloc_as(struct kk_nagare_io_file_readAllStreamingBytes_fun1168__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file_readAllStreamingBytes_fun1168, kk_context());
  _self->filepath = filepath;
  _self->hRef = hRef;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_io_file_readAllStreamingBytes_fun1170__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_io_file_readAllStreamingBytes_fun1170(kk_function_t _fself, kk_box_t _b_x51, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_readAllStreamingBytes_fun1170(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file_readAllStreamingBytes_fun1170, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_io_file_readAllStreamingBytes_fun1170(kk_function_t _fself, kk_box_t _b_x51, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1171;
  kk_std_os_path__path _x_x1172 = kk_std_os_path__path_unbox(_b_x51, KK_OWNED, _ctx); /*std/os/path/path*/
  _x_x1171 = kk_std_os_path_string(_x_x1172, _ctx); /*string*/
  return kk_string_box(_x_x1171);
}


// lift anonymous function
struct kk_nagare_io_file_readAllStreamingBytes_fun1176__t {
  struct kk_function_s _base;
  kk_ssize_t i_10705;
};
static kk_box_t kk_nagare_io_file_readAllStreamingBytes_fun1176(kk_function_t _fself, kk_function_t _b_x67, kk_box_t _b_x68, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_readAllStreamingBytes_fun1176(kk_ssize_t i_10705, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readAllStreamingBytes_fun1176__t* _self = kk_function_alloc_as(struct kk_nagare_io_file_readAllStreamingBytes_fun1176__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file_readAllStreamingBytes_fun1176, kk_context());
  _self->i_10705 = i_10705;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file_readAllStreamingBytes_fun1176(kk_function_t _fself, kk_function_t _b_x67, kk_box_t _b_x68, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readAllStreamingBytes_fun1176__t* _self = kk_function_as(struct kk_nagare_io_file_readAllStreamingBytes_fun1176__t*, _fself, _ctx);
  kk_ssize_t i_10705 = _self->i_10705; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_10705, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_10705, _b_x67, _b_x68, _ctx);
}


// lift anonymous function
struct kk_nagare_io_file_readAllStreamingBytes_fun1177__t {
  struct kk_function_s _base;
  kk_ref_t hRef;
};
static kk_unit_t kk_nagare_io_file_readAllStreamingBytes_fun1177(kk_function_t _fself, kk_nagare_io_file__effect__read_handle _y_x10422, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_readAllStreamingBytes_fun1177(kk_ref_t hRef, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readAllStreamingBytes_fun1177__t* _self = kk_function_alloc_as(struct kk_nagare_io_file_readAllStreamingBytes_fun1177__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file_readAllStreamingBytes_fun1177, kk_context());
  _self->hRef = hRef;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_unit_t kk_nagare_io_file_readAllStreamingBytes_fun1177(kk_function_t _fself, kk_nagare_io_file__effect__read_handle _y_x10422, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readAllStreamingBytes_fun1177__t* _self = kk_function_as(struct kk_nagare_io_file_readAllStreamingBytes_fun1177__t*, _fself, _ctx);
  kk_ref_t hRef = _self->hRef; /* ref<global,maybe<nagare/io/file_effect/read-handle>> */
  kk_drop_match(_self, {kk_ref_dup(hRef, _ctx);}, {}, _ctx)
  kk_unit_t _brw_x1074 = kk_Unit;
  kk_box_t _x_x1178;
  kk_std_core_types__maybe _x_x1179 = kk_std_core_types__new_Just(kk_nagare_io_file__effect__read_handle_box(_y_x10422, _ctx), _ctx); /*maybe<10024>*/
  _x_x1178 = kk_std_core_types__maybe_box(_x_x1179, _ctx); /*10000*/
  kk_ref_set_borrow(hRef,_x_x1178,kk_context());
  kk_ref_drop(hRef, _ctx);
  _brw_x1074; return kk_Unit;
}


// lift anonymous function
struct kk_nagare_io_file_readAllStreamingBytes_fun1181__t {
  struct kk_function_s _base;
  kk_function_t next_10704;
};
static kk_box_t kk_nagare_io_file_readAllStreamingBytes_fun1181(kk_function_t _fself, kk_box_t _b_x83, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_readAllStreamingBytes_fun1181(kk_function_t next_10704, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readAllStreamingBytes_fun1181__t* _self = kk_function_alloc_as(struct kk_nagare_io_file_readAllStreamingBytes_fun1181__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file_readAllStreamingBytes_fun1181, kk_context());
  _self->next_10704 = next_10704;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file_readAllStreamingBytes_fun1181(kk_function_t _fself, kk_box_t _b_x83, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readAllStreamingBytes_fun1181__t* _self = kk_function_as(struct kk_nagare_io_file_readAllStreamingBytes_fun1181__t*, _fself, _ctx);
  kk_function_t next_10704 = _self->next_10704; /* (nagare/io/file_effect/read-handle) -> <nagare/io/file_effect/fileRead,write<global>,alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui> () */
  kk_drop_match(_self, {kk_function_dup(next_10704, _ctx);}, {}, _ctx)
  kk_unit_t _x_x1182 = kk_Unit;
  kk_nagare_io_file__effect__read_handle _x_x1183 = kk_nagare_io_file__effect__read_handle_unbox(_b_x83, KK_OWNED, _ctx); /*nagare/io/file_effect/read-handle*/
  kk_function_call(kk_unit_t, (kk_function_t, kk_nagare_io_file__effect__read_handle, kk_context_t*), next_10704, (next_10704, _x_x1183, _ctx), _ctx);
  return kk_unit_box(_x_x1182);
}
static kk_unit_t kk_nagare_io_file_readAllStreamingBytes_fun1168(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readAllStreamingBytes_fun1168__t* _self = kk_function_as(struct kk_nagare_io_file_readAllStreamingBytes_fun1168__t*, _fself, _ctx);
  kk_std_os_path__path filepath = _self->filepath; /* std/os/path/path */
  kk_ref_t hRef = _self->hRef; /* ref<global,maybe<nagare/io/file_effect/read-handle>> */
  kk_drop_match(_self, {kk_std_os_path__path_dup(filepath, _ctx);kk_ref_dup(hRef, _ctx);}, {}, _ctx)
  kk_string_t _x_x1_10597;
  kk_box_t _x_x1169 = kk_std_core_hnd__open_none1(kk_nagare_io_file_new_readAllStreamingBytes_fun1170(_ctx), kk_std_os_path__path_box(filepath, _ctx), _ctx); /*10001*/
  _x_x1_10597 = kk_string_unbox(_x_x1169); /*string*/
  kk_ssize_t i_10705 = (KK_IZ(1)); /*hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_10705,kk_context()); /*hnd/evv<<nagare/io/file_effect/fileRead,write<global>,alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui>>*/;
  kk_std_core_hnd__ev ev_10708 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<nagare/io/file_effect/fileRead>*/;
  kk_nagare_io_file__effect__read_handle y;
  kk_box_t _x_x1173;
  {
    struct kk_std_core_hnd_Ev* _con_x1174 = kk_std_core_hnd__as_Ev(ev_10708, _ctx);
    kk_box_t _box_x54 = _con_x1174->hnd;
    int32_t m = _con_x1174->marker;
    kk_nagare_io_file__effect__fileRead h = kk_nagare_io_file__effect__fileRead_unbox(_box_x54, KK_BORROWED, _ctx);
    kk_nagare_io_file__effect__fileRead_dup(h, _ctx);
    kk_std_core_hnd__clause1 _match_x1076;
    kk_std_core_hnd__clause1 _brw_x1077 = kk_nagare_io_file__effect_openRead_fs__select(h, _ctx); /*hnd/clause1<string,nagare/io/file_effect/read-handle,nagare/io/file_effect/fileRead,692,693>*/;
    kk_datatype_ptr_dropn(h, (KK_I32(6)), _ctx);
    _match_x1076 = _brw_x1077; /*hnd/clause1<string,nagare/io/file_effect/read-handle,nagare/io/file_effect/fileRead,692,693>*/
    {
      kk_function_t _fun_unbox_x58 = _match_x1076.clause;
      _x_x1173 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x58, (_fun_unbox_x58, m, ev_10708, kk_string_box(_x_x1_10597), _ctx), _ctx); /*10010*/
    }
  }
  y = kk_nagare_io_file__effect__read_handle_unbox(_x_x1173, KK_OWNED, _ctx); /*nagare/io/file_effect/read-handle*/
  kk_evv_set(w,kk_context());
  kk_nagare_io_file__effect__read_handle x_10703;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1175 = kk_std_core_hnd_yield_cont(kk_nagare_io_file_new_readAllStreamingBytes_fun1176(i_10705, _ctx), _ctx); /*10002*/
    x_10703 = kk_nagare_io_file__effect__read_handle_unbox(_x_x1175, KK_OWNED, _ctx); /*nagare/io/file_effect/read-handle*/
  }
  else {
    x_10703 = y; /*nagare/io/file_effect/read-handle*/
  }
  kk_function_t next_10704 = kk_nagare_io_file_new_readAllStreamingBytes_fun1177(hRef, _ctx); /*(nagare/io/file_effect/read-handle) -> <nagare/io/file_effect/fileRead,write<global>,alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui> ()*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1180 = kk_std_core_hnd_yield_extend(kk_nagare_io_file_new_readAllStreamingBytes_fun1181(next_10704, _ctx), _ctx); /*10001*/
    kk_unit_unbox(_x_x1180); return kk_Unit;
  }
  {
    kk_function_call(kk_unit_t, (kk_function_t, kk_nagare_io_file__effect__read_handle, kk_context_t*), next_10704, (next_10704, x_10703, _ctx), _ctx); return kk_Unit;
  }
}


// lift anonymous function
struct kk_nagare_io_file_readAllStreamingBytes_fun1185__t {
  struct kk_function_s _base;
  kk_ref_t hRef;
};
static kk_unit_t kk_nagare_io_file_readAllStreamingBytes_fun1185(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_readAllStreamingBytes_fun1185(kk_ref_t hRef, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readAllStreamingBytes_fun1185__t* _self = kk_function_alloc_as(struct kk_nagare_io_file_readAllStreamingBytes_fun1185__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file_readAllStreamingBytes_fun1185, kk_context());
  _self->hRef = hRef;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_io_file_readAllStreamingBytes_fun1190__t {
  struct kk_function_s _base;
  kk_ssize_t i_0_10713;
};
static kk_box_t kk_nagare_io_file_readAllStreamingBytes_fun1190(kk_function_t _fself, kk_function_t _b_x100, kk_box_t _b_x101, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_readAllStreamingBytes_fun1190(kk_ssize_t i_0_10713, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readAllStreamingBytes_fun1190__t* _self = kk_function_alloc_as(struct kk_nagare_io_file_readAllStreamingBytes_fun1190__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file_readAllStreamingBytes_fun1190, kk_context());
  _self->i_0_10713 = i_0_10713;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_io_file_readAllStreamingBytes_fun1191__t {
  struct kk_function_s _base;
  kk_function_t _b_x100;
};
static kk_unit_t kk_nagare_io_file_readAllStreamingBytes_fun1191(kk_function_t _fself, kk_box_t _b_x102, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_readAllStreamingBytes_fun1191(kk_function_t _b_x100, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readAllStreamingBytes_fun1191__t* _self = kk_function_alloc_as(struct kk_nagare_io_file_readAllStreamingBytes_fun1191__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file_readAllStreamingBytes_fun1191, kk_context());
  _self->_b_x100 = _b_x100;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_unit_t kk_nagare_io_file_readAllStreamingBytes_fun1191(kk_function_t _fself, kk_box_t _b_x102, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readAllStreamingBytes_fun1191__t* _self = kk_function_as(struct kk_nagare_io_file_readAllStreamingBytes_fun1191__t*, _fself, _ctx);
  kk_function_t _b_x100 = _self->_b_x100; /* (10003) -> 10001 10000 */
  kk_drop_match(_self, {kk_function_dup(_b_x100, _ctx);}, {}, _ctx)
  kk_box_t _x_x1192 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _b_x100, (_b_x100, _b_x102, _ctx), _ctx); /*10000*/
  kk_unit_unbox(_x_x1192); return kk_Unit;
}


// lift anonymous function
struct kk_nagare_io_file_readAllStreamingBytes_fun1193__t {
  struct kk_function_s _base;
  kk_function_t _b_x96_113;
};
static kk_box_t kk_nagare_io_file_readAllStreamingBytes_fun1193(kk_function_t _fself, kk_box_t _b_x98, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_readAllStreamingBytes_fun1193(kk_function_t _b_x96_113, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readAllStreamingBytes_fun1193__t* _self = kk_function_alloc_as(struct kk_nagare_io_file_readAllStreamingBytes_fun1193__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file_readAllStreamingBytes_fun1193, kk_context());
  _self->_b_x96_113 = _b_x96_113;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file_readAllStreamingBytes_fun1193(kk_function_t _fself, kk_box_t _b_x98, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readAllStreamingBytes_fun1193__t* _self = kk_function_as(struct kk_nagare_io_file_readAllStreamingBytes_fun1193__t*, _fself, _ctx);
  kk_function_t _b_x96_113 = _self->_b_x96_113; /* (10011) -> <nagare/io/file_effect/fileRead,read<global>,alloc<global>,console/console,div,exn,fsys,ndet,net,ui,write<global>> () */
  kk_drop_match(_self, {kk_function_dup(_b_x96_113, _ctx);}, {}, _ctx)
  kk_unit_t _x_x1194 = kk_Unit;
  kk_function_call(kk_unit_t, (kk_function_t, kk_box_t, kk_context_t*), _b_x96_113, (_b_x96_113, _b_x98, _ctx), _ctx);
  return kk_unit_box(_x_x1194);
}
static kk_box_t kk_nagare_io_file_readAllStreamingBytes_fun1190(kk_function_t _fself, kk_function_t _b_x100, kk_box_t _b_x101, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readAllStreamingBytes_fun1190__t* _self = kk_function_as(struct kk_nagare_io_file_readAllStreamingBytes_fun1190__t*, _fself, _ctx);
  kk_ssize_t i_0_10713 = _self->i_0_10713; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_0_10713, _ctx);}, {}, _ctx)
  kk_function_t cont_0_117 = kk_nagare_io_file_new_readAllStreamingBytes_fun1191(_b_x100, _ctx); /*(10011) -> <nagare/io/file_effect/fileRead,read<global>,alloc<global>,console/console,div,exn,fsys,ndet,net,ui,write<global>> ()*/;
  kk_box_t res_0_118 = _b_x101; /*10011*/;
  kk_ssize_t _b_x95_112 = i_0_10713; /*hnd/ev-index*/;
  kk_function_t _b_x96_113 = cont_0_117; /*(10011) -> <nagare/io/file_effect/fileRead,read<global>,alloc<global>,console/console,div,exn,fsys,ndet,net,ui,write<global>> ()*/;
  kk_box_t _b_x97_114 = res_0_118; /*10011*/;
  return kk_std_core_hnd_open_at1(_b_x95_112, kk_nagare_io_file_new_readAllStreamingBytes_fun1193(_b_x96_113, _ctx), _b_x97_114, _ctx);
}
static kk_unit_t kk_nagare_io_file_readAllStreamingBytes_fun1185(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readAllStreamingBytes_fun1185__t* _self = kk_function_as(struct kk_nagare_io_file_readAllStreamingBytes_fun1185__t*, _fself, _ctx);
  kk_ref_t hRef = _self->hRef; /* ref<global,maybe<nagare/io/file_effect/read-handle>> */
  kk_drop_match(_self, {kk_ref_dup(hRef, _ctx);}, {}, _ctx)
  kk_std_core_types__maybe _match_x1069;
  kk_box_t _x_x1186 = kk_ref_get(hRef,kk_context()); /*10000*/
  _match_x1069 = kk_std_core_types__maybe_unbox(_x_x1186, KK_OWNED, _ctx); /*maybe<nagare/io/file_effect/read-handle>*/
  if (kk_std_core_types__is_Just(_match_x1069, _ctx)) {
    kk_box_t _box_x86 = _match_x1069._cons.Just.value;
    kk_nagare_io_file__effect__read_handle h_0 = kk_nagare_io_file__effect__read_handle_unbox(_box_x86, KK_BORROWED, _ctx);
    kk_std_core_types__maybe_drop(_match_x1069, _ctx);
    kk_ssize_t i_0_10713 = (KK_IZ(1)); /*hnd/ev-index*/;
    kk_evv_t w_0 = kk_evv_swap_create1(i_0_10713,kk_context()); /*hnd/evv<<nagare/io/file_effect/fileRead,read<global>,alloc<global>,console/console,div,exn,fsys,ndet,net,ui,write<global>>>*/;
    kk_std_core_hnd__ev ev_0_10716 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<nagare/io/file_effect/fileRead>*/;
    kk_unit_t y_0 = kk_Unit;
    kk_box_t _x_x1187;
    {
      struct kk_std_core_hnd_Ev* _con_x1188 = kk_std_core_hnd__as_Ev(ev_0_10716, _ctx);
      kk_box_t _box_x87 = _con_x1188->hnd;
      int32_t m_0 = _con_x1188->marker;
      kk_nagare_io_file__effect__fileRead h_1 = kk_nagare_io_file__effect__fileRead_unbox(_box_x87, KK_BORROWED, _ctx);
      kk_nagare_io_file__effect__fileRead_dup(h_1, _ctx);
      kk_std_core_hnd__clause1 _match_x1071;
      kk_std_core_hnd__clause1 _brw_x1072 = kk_nagare_io_file__effect_closeRead_fs__select(h_1, _ctx); /*hnd/clause1<nagare/io/file_effect/read-handle,(),nagare/io/file_effect/fileRead,799,800>*/;
      kk_datatype_ptr_dropn(h_1, (KK_I32(6)), _ctx);
      _match_x1071 = _brw_x1072; /*hnd/clause1<nagare/io/file_effect/read-handle,(),nagare/io/file_effect/fileRead,799,800>*/
      {
        kk_function_t _fun_unbox_x91 = _match_x1071.clause;
        _x_x1187 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x91, (_fun_unbox_x91, m_0, ev_0_10716, kk_nagare_io_file__effect__read_handle_box(h_0, _ctx), _ctx), _ctx); /*10010*/
      }
    }
    kk_unit_unbox(_x_x1187);
    kk_evv_set(w_0,kk_context());
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x1189 = kk_std_core_hnd_yield_cont(kk_nagare_io_file_new_readAllStreamingBytes_fun1190(i_0_10713, _ctx), _ctx); /*10002*/
      kk_unit_unbox(_x_x1189); return kk_Unit;
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
struct kk_nagare_io_file_readAllStreamingBytes_fun1196__t {
  struct kk_function_s _base;
  kk_std_core_types__optional chunkSize;
  kk_ref_t hRef;
};
static kk_nagare_core_types__pull kk_nagare_io_file_readAllStreamingBytes_fun1196(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_readAllStreamingBytes_fun1196(kk_std_core_types__optional chunkSize, kk_ref_t hRef, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readAllStreamingBytes_fun1196__t* _self = kk_function_alloc_as(struct kk_nagare_io_file_readAllStreamingBytes_fun1196__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file_readAllStreamingBytes_fun1196, kk_context());
  _self->chunkSize = chunkSize;
  _self->hRef = hRef;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_nagare_core_types__pull kk_nagare_io_file_readAllStreamingBytes_fun1196(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readAllStreamingBytes_fun1196__t* _self = kk_function_as(struct kk_nagare_io_file_readAllStreamingBytes_fun1196__t*, _fself, _ctx);
  kk_std_core_types__optional chunkSize = _self->chunkSize; /* ? int */
  kk_ref_t hRef = _self->hRef; /* ref<global,maybe<nagare/io/file_effect/read-handle>> */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(chunkSize, _ctx);kk_ref_dup(hRef, _ctx);}, {}, _ctx)
  kk_std_core_types__maybe _match_x1068;
  kk_box_t _x_x1197 = kk_ref_get(hRef,kk_context()); /*10000*/
  _match_x1068 = kk_std_core_types__maybe_unbox(_x_x1197, KK_OWNED, _ctx); /*maybe<nagare/io/file_effect/read-handle>*/
  if (kk_std_core_types__is_Just(_match_x1068, _ctx)) {
    kk_box_t _box_x105 = _match_x1068._cons.Just.value;
    kk_nagare_io_file__effect__read_handle h_0_0_0 = kk_nagare_io_file__effect__read_handle_unbox(_box_x105, KK_BORROWED, _ctx);
    kk_std_core_types__maybe_drop(_match_x1068, _ctx);
    kk_evv_t w_1 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<div,read<global>,alloc<global>,console/console,exn,nagare/io/file_effect/fileRead,fsys,ndet,net,ui,write<global>>>*/;
    kk_nagare_core_types__pull x_4;
    kk_integer_t _x_x1198;
    if (kk_std_core_types__is_Optional(chunkSize, _ctx)) {
      kk_box_t _box_x106 = chunkSize._cons._Optional.value;
      kk_integer_t _uniq_chunkSize_331 = kk_integer_unbox(_box_x106, _ctx);
      kk_integer_dup(_uniq_chunkSize_331, _ctx);
      kk_std_core_types__optional_drop(chunkSize, _ctx);
      _x_x1198 = _uniq_chunkSize_331; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(chunkSize, _ctx);
      _x_x1198 = kk_integer_from_small(4096); /*int*/
    }
    x_4 = kk_nagare_io_file_readPullBytes(h_0_0_0, _x_x1198, _ctx); /*nagare/core/types/pull<nagare/io/file/bytes,<nagare/io/file_effect/fileRead|io>>*/
    kk_unit_t keep = kk_Unit;
    kk_evv_set(w_1,kk_context());
    return x_4;
  }
  {
    kk_std_core_types__optional_drop(chunkSize, _ctx);
    return kk_nagare_core_types__new_PDone(_ctx);
  }
}
static kk_nagare_core_types__pull kk_nagare_io_file_readAllStreamingBytes_fun1166(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readAllStreamingBytes_fun1166__t* _self = kk_function_as(struct kk_nagare_io_file_readAllStreamingBytes_fun1166__t*, _fself, _ctx);
  kk_std_core_types__optional chunkSize = _self->chunkSize; /* ? int */
  kk_std_os_path__path filepath = _self->filepath; /* std/os/path/path */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(chunkSize, _ctx);kk_std_os_path__path_dup(filepath, _ctx);}, {}, _ctx)
  kk_ref_t hRef = kk_ref_alloc((kk_std_core_types__maybe_box(kk_std_core_types__new_Nothing(_ctx), _ctx)),kk_context()); /*ref<global,maybe<nagare/io/file_effect/read-handle>>*/;
  kk_function_t _x_x1167;
  kk_ref_dup(hRef, _ctx);
  _x_x1167 = kk_nagare_io_file_new_readAllStreamingBytes_fun1168(filepath, hRef, _ctx); /*() -> <alloc<global>,console/console,div,exn,nagare/io/file_effect/fileRead,fsys,ndet,net,read<global>,ui,write<global>> ()*/
  kk_function_t _x_x1184;
  kk_ref_dup(hRef, _ctx);
  _x_x1184 = kk_nagare_io_file_new_readAllStreamingBytes_fun1185(hRef, _ctx); /*() -> <alloc<global>,console/console,div,exn,nagare/io/file_effect/fileRead,fsys,ndet,net,read<global>,ui,write<global>> ()*/
  kk_nagare_core_types__pull _x_x1195 = kk_nagare_core_types__new_PEval(kk_reuse_null, 0, kk_nagare_io_file_new_readAllStreamingBytes_fun1196(chunkSize, hRef, _ctx), _ctx); /*nagare/core/types/pull<19,20>*/
  return kk_nagare_core_types__new_PAcquire(kk_reuse_null, 0, _x_x1167, _x_x1184, _x_x1195, _ctx);
}

kk_nagare_core_types__nstream kk_nagare_io_file_readAllStreamingBytes(kk_std_os_path__path filepath, kk_std_core_types__optional chunkSize, kk_context_t* _ctx) { /* (filepath : std/os/path/path, chunkSize : ? int) -> nagare/io/file_effect/readStream<bytes> */ 
  kk_nagare_core_types__pull _x_x1165 = kk_nagare_core_types__new_PEval(kk_reuse_null, 0, kk_nagare_io_file_new_readAllStreamingBytes_fun1166(chunkSize, filepath, _ctx), _ctx); /*nagare/core/types/pull<19,20>*/
  return kk_nagare_core_types__new_Stream(_x_x1165, _ctx);
}
 
// monadic lift

kk_std_core_types__list kk_nagare_io_file__mlift_readAllChunksBytes_10657(kk_std_core_types__list acc, kk_integer_t chunkSize, kk_nagare_io_file__effect__read_handle h, kk_vector_t chunk, kk_context_t* _ctx) { /* (acc : list<bytes>, chunkSize : int, h : nagare/io/file_effect/read-handle, chunk : vector<int8>) -> <nagare/io/file_effect/fileRead,alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> list<bytes> */ 
  bool _match_x1065;
  kk_integer_t _brw_x1066;
  kk_ssize_t _x_x1199 = kk_vector_len_borrow(chunk,kk_context()); /*ssize_t*/
  _brw_x1066 = kk_integer_from_ssize_t(_x_x1199,kk_context()); /*int*/
  bool _brw_x1067 = kk_integer_eq_borrow(_brw_x1066,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x1066, _ctx);
  _match_x1065 = _brw_x1067; /*bool*/
  if (_match_x1065) {
    kk_integer_drop(chunkSize, _ctx);
    kk_vector_drop(chunk, _ctx);
    kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileRead,fsys,ndet,net,read<global>,ui,write<global>>>*/;
    kk_std_core_types__list x;
    if (kk_std_core_types__is_Nil(acc, _ctx)) {
      x = kk_std_core_types__new_Nil(_ctx); /*list<nagare/io/file/bytes>*/
    }
    else {
      x = kk_std_core_list__unroll_reverse_acc_10003(kk_std_core_types__new_Nil(_ctx), acc, _ctx); /*list<nagare/io/file/bytes>*/
    }
    kk_unit_t keep = kk_Unit;
    kk_evv_set(w,kk_context());
    return x;
  }
  {
    kk_std_core_types__list _x_x1200 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_vector_box(chunk, _ctx), acc, _ctx); /*list<10021>*/
    return kk_nagare_io_file_readAllChunksBytes(h, chunkSize, _x_x1200, _ctx);
  }
}
 
// Helper: drain the read-handle into a list of byte chunks.


// lift anonymous function
struct kk_nagare_io_file_readAllChunksBytes_fun1206__t {
  struct kk_function_s _base;
  kk_ssize_t i_10727;
};
static kk_box_t kk_nagare_io_file_readAllChunksBytes_fun1206(kk_function_t _fself, kk_function_t _b_x138, kk_box_t _b_x139, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_readAllChunksBytes_fun1206(kk_ssize_t i_10727, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readAllChunksBytes_fun1206__t* _self = kk_function_alloc_as(struct kk_nagare_io_file_readAllChunksBytes_fun1206__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file_readAllChunksBytes_fun1206, kk_context());
  _self->i_10727 = i_10727;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file_readAllChunksBytes_fun1206(kk_function_t _fself, kk_function_t _b_x138, kk_box_t _b_x139, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readAllChunksBytes_fun1206__t* _self = kk_function_as(struct kk_nagare_io_file_readAllChunksBytes_fun1206__t*, _fself, _ctx);
  kk_ssize_t i_10727 = _self->i_10727; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_10727, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_10727, _b_x138, _b_x139, _ctx);
}


// lift anonymous function
struct kk_nagare_io_file_readAllChunksBytes_fun1208__t {
  struct kk_function_s _base;
  kk_std_core_types__list acc_0;
  kk_integer_t chunkSize_0;
  kk_nagare_io_file__effect__read_handle h_0;
};
static kk_box_t kk_nagare_io_file_readAllChunksBytes_fun1208(kk_function_t _fself, kk_box_t _b_x148, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_readAllChunksBytes_fun1208(kk_std_core_types__list acc_0, kk_integer_t chunkSize_0, kk_nagare_io_file__effect__read_handle h_0, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readAllChunksBytes_fun1208__t* _self = kk_function_alloc_as(struct kk_nagare_io_file_readAllChunksBytes_fun1208__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file_readAllChunksBytes_fun1208, kk_context());
  _self->acc_0 = acc_0;
  _self->chunkSize_0 = chunkSize_0;
  _self->h_0 = h_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file_readAllChunksBytes_fun1208(kk_function_t _fself, kk_box_t _b_x148, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readAllChunksBytes_fun1208__t* _self = kk_function_as(struct kk_nagare_io_file_readAllChunksBytes_fun1208__t*, _fself, _ctx);
  kk_std_core_types__list acc_0 = _self->acc_0; /* list<nagare/io/file/bytes> */
  kk_integer_t chunkSize_0 = _self->chunkSize_0; /* int */
  kk_nagare_io_file__effect__read_handle h_0 = _self->h_0; /* nagare/io/file_effect/read-handle */
  kk_drop_match(_self, {kk_std_core_types__list_dup(acc_0, _ctx);kk_integer_dup(chunkSize_0, _ctx);kk_nagare_io_file__effect__read_handle_dup(h_0, _ctx);}, {}, _ctx)
  kk_vector_t chunk_0_155 = kk_vector_unbox(_b_x148, _ctx); /*vector<int8>*/;
  kk_std_core_types__list _x_x1209 = kk_nagare_io_file__mlift_readAllChunksBytes_10657(acc_0, chunkSize_0, h_0, chunk_0_155, _ctx); /*list<nagare/io/file/bytes>*/
  return kk_std_core_types__list_box(_x_x1209, _ctx);
}

kk_std_core_types__list kk_nagare_io_file_readAllChunksBytes(kk_nagare_io_file__effect__read_handle h_0, kk_integer_t chunkSize_0, kk_std_core_types__list acc_0, kk_context_t* _ctx) { /* (h : nagare/io/file_effect/read-handle, chunkSize : int, acc : list<bytes>) -> <io,nagare/io/file_effect/fileRead> list<bytes> */ 
  kk__tailcall: ;
  kk_ssize_t i_10727 = (KK_IZ(1)); /*hnd/ev-index*/;
  kk_evv_t w_0 = kk_evv_swap_create1(i_10727,kk_context()); /*hnd/evv<<nagare/io/file_effect/fileRead,alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_std_core_hnd__ev evx_10731 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<nagare/io/file_effect/fileRead>*/;
  kk_vector_t y;
  kk_box_t _x_x1201;
  {
    struct kk_std_core_hnd_Ev* _con_x1202 = kk_std_core_hnd__as_Ev(evx_10731, _ctx);
    kk_box_t _box_x123 = _con_x1202->hnd;
    int32_t m = _con_x1202->marker;
    kk_nagare_io_file__effect__fileRead h_1 = kk_nagare_io_file__effect__fileRead_unbox(_box_x123, KK_BORROWED, _ctx);
    kk_nagare_io_file__effect__fileRead_dup(h_1, _ctx);
    kk_std_core_hnd__clause2 _match_x1063;
    kk_std_core_hnd__clause2 _brw_x1064 = kk_nagare_io_file__effect_readChunkBytes_fs__select(h_1, _ctx); /*hnd/clause2<nagare/io/file_effect/read-handle,int,vector<int8>,nagare/io/file_effect/fileRead,1017,1018>*/;
    kk_datatype_ptr_dropn(h_1, (KK_I32(6)), _ctx);
    _match_x1063 = _brw_x1064; /*hnd/clause2<nagare/io/file_effect/read-handle,int,vector<int8>,nagare/io/file_effect/fileRead,1017,1018>*/
    {
      kk_function_t _fun_unbox_x128 = _match_x1063.clause;
      kk_box_t _x_x1203;
      kk_integer_t _x_x1204 = kk_integer_dup(chunkSize_0, _ctx); /*int*/
      _x_x1203 = kk_integer_box(_x_x1204, _ctx); /*10015*/
      _x_x1201 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_box_t, kk_context_t*), _fun_unbox_x128, (_fun_unbox_x128, m, evx_10731, kk_nagare_io_file__effect__read_handle_box(h_0, _ctx), _x_x1203, _ctx), _ctx); /*10016*/
    }
  }
  y = kk_vector_unbox(_x_x1201, _ctx); /*vector<int8>*/
  kk_evv_set(w_0,kk_context());
  kk_vector_t x_0_10724;
  if (kk_yielding(kk_context())) {
    kk_vector_drop(y, _ctx);
    kk_box_t _x_x1205 = kk_std_core_hnd_yield_cont(kk_nagare_io_file_new_readAllChunksBytes_fun1206(i_10727, _ctx), _ctx); /*10002*/
    x_0_10724 = kk_vector_unbox(_x_x1205, _ctx); /*vector<int8>*/
  }
  else {
    x_0_10724 = y; /*vector<int8>*/
  }
  if (kk_yielding(kk_context())) {
    kk_vector_drop(x_0_10724, _ctx);
    kk_box_t _x_x1207 = kk_std_core_hnd_yield_extend(kk_nagare_io_file_new_readAllChunksBytes_fun1208(acc_0, chunkSize_0, h_0, _ctx), _ctx); /*10001*/
    return kk_std_core_types__list_unbox(_x_x1207, KK_OWNED, _ctx);
  }
  {
    bool _match_x1059;
    kk_integer_t _brw_x1060;
    kk_ssize_t _x_x1210 = kk_vector_len_borrow(x_0_10724,kk_context()); /*ssize_t*/
    _brw_x1060 = kk_integer_from_ssize_t(_x_x1210,kk_context()); /*int*/
    bool _brw_x1061 = kk_integer_eq_borrow(_brw_x1060,(kk_integer_from_small(0)),kk_context()); /*bool*/;
    kk_integer_drop(_brw_x1060, _ctx);
    _match_x1059 = _brw_x1061; /*bool*/
    if (_match_x1059) {
      kk_vector_drop(x_0_10724, _ctx);
      kk_integer_drop(chunkSize_0, _ctx);
      kk_evv_t w_1 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileRead,fsys,ndet,net,read<global>,ui,write<global>>>*/;
      kk_std_core_types__list x_2;
      if (kk_std_core_types__is_Nil(acc_0, _ctx)) {
        x_2 = kk_std_core_types__new_Nil(_ctx); /*list<nagare/io/file/bytes>*/
      }
      else {
        x_2 = kk_std_core_list__unroll_reverse_acc_10003(kk_std_core_types__new_Nil(_ctx), acc_0, _ctx); /*list<nagare/io/file/bytes>*/
      }
      kk_unit_t keep_0 = kk_Unit;
      kk_evv_set(w_1,kk_context());
      return x_2;
    }
    { // tailcall
      kk_std_core_types__list _x_x1211 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_vector_box(x_0_10724, _ctx), acc_0, _ctx); /*list<10021>*/
      acc_0 = _x_x1211;
      goto kk__tailcall;
    }
  }
}
 
// Read a file eagerly into byte chunks (not lazy — use readAllStreamingBytes for large files).


// lift anonymous function
struct kk_nagare_io_file_readAllBytes_fun1214__t {
  struct kk_function_s _base;
  kk_std_core_types__optional chunkSize;
  kk_std_os_path__path filepath;
};
static kk_nagare_core_types__pull kk_nagare_io_file_readAllBytes_fun1214(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_readAllBytes_fun1214(kk_std_core_types__optional chunkSize, kk_std_os_path__path filepath, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readAllBytes_fun1214__t* _self = kk_function_alloc_as(struct kk_nagare_io_file_readAllBytes_fun1214__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file_readAllBytes_fun1214, kk_context());
  _self->chunkSize = chunkSize;
  _self->filepath = filepath;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_io_file_readAllBytes_fun1216__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_io_file_readAllBytes_fun1216(kk_function_t _fself, kk_box_t _b_x158, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_readAllBytes_fun1216(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file_readAllBytes_fun1216, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_io_file_readAllBytes_fun1216(kk_function_t _fself, kk_box_t _b_x158, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1217;
  kk_std_os_path__path _x_x1218 = kk_std_os_path__path_unbox(_b_x158, KK_OWNED, _ctx); /*std/os/path/path*/
  _x_x1217 = kk_std_os_path_string(_x_x1218, _ctx); /*string*/
  return kk_string_box(_x_x1217);
}


// lift anonymous function
struct kk_nagare_io_file_readAllBytes_fun1220__t {
  struct kk_function_s _base;
  kk_std_core_types__optional chunkSize;
};
static kk_box_t kk_nagare_io_file_readAllBytes_fun1220(kk_function_t _fself, kk_nagare_io_file__effect__read_handle _b_x164, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_readAllBytes_fun1220(kk_std_core_types__optional chunkSize, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readAllBytes_fun1220__t* _self = kk_function_alloc_as(struct kk_nagare_io_file_readAllBytes_fun1220__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file_readAllBytes_fun1220, kk_context());
  _self->chunkSize = chunkSize;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_io_file_readAllBytes_fun1224__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_io_file_readAllBytes_fun1224(kk_function_t _fself, kk_box_t _b_x161, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_readAllBytes_fun1224(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file_readAllBytes_fun1224, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_io_file_readAllBytes_fun1224(kk_function_t _fself, kk_box_t _b_x161, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_nagare_core_types__pull _x_x1225;
  kk_std_core_types__list _x_x1226 = kk_std_core_types__list_unbox(_b_x161, KK_OWNED, _ctx); /*list<nagare/io/file/bytes>*/
  _x_x1225 = kk_nagare_io_file__mlift_readAllBytes_10658(_x_x1226, _ctx); /*nagare/core/types/pull<nagare/io/file/bytes,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileRead,fsys,ndet,net,read<global>,ui,write<global>>>*/
  return kk_nagare_core_types__pull_box(_x_x1225, _ctx);
}
static kk_box_t kk_nagare_io_file_readAllBytes_fun1220(kk_function_t _fself, kk_nagare_io_file__effect__read_handle _b_x164, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readAllBytes_fun1220__t* _self = kk_function_as(struct kk_nagare_io_file_readAllBytes_fun1220__t*, _fself, _ctx);
  kk_std_core_types__optional chunkSize = _self->chunkSize; /* ? int */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(chunkSize, _ctx);}, {}, _ctx)
  kk_nagare_io_file__effect__read_handle h_170 = _b_x164; /*nagare/io/file_effect/read-handle*/;
  kk_std_core_types__list x_10737;
  kk_integer_t _x_x1221;
  if (kk_std_core_types__is_Optional(chunkSize, _ctx)) {
    kk_box_t _box_x159 = chunkSize._cons._Optional.value;
    kk_integer_t _uniq_chunkSize_685 = kk_integer_unbox(_box_x159, _ctx);
    kk_integer_dup(_uniq_chunkSize_685, _ctx);
    kk_std_core_types__optional_drop(chunkSize, _ctx);
    _x_x1221 = _uniq_chunkSize_685; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(chunkSize, _ctx);
    _x_x1221 = kk_integer_from_small(4096); /*int*/
  }
  x_10737 = kk_nagare_io_file_readAllChunksBytes(h_170, _x_x1221, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<nagare/io/file/bytes>*/
  kk_nagare_core_types__pull _x_x1222;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_10737, _ctx);
    kk_box_t _x_x1223 = kk_std_core_hnd_yield_extend(kk_nagare_io_file_new_readAllBytes_fun1224(_ctx), _ctx); /*10001*/
    _x_x1222 = kk_nagare_core_types__pull_unbox(_x_x1223, KK_OWNED, _ctx); /*nagare/core/types/pull<nagare/io/file/bytes,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileRead,fsys,ndet,net,read<global>,ui,write<global>>>*/
  }
  else {
    kk_nagare_core_types__chunk _x_x1227 = kk_nagare_core_types__new_Chunk(x_10737, _ctx); /*nagare/core/types/chunk<4>*/
    _x_x1222 = kk_nagare_core_types__new_POutput(kk_reuse_null, 0, _x_x1227, kk_nagare_core_types__new_PDone(_ctx), _ctx); /*nagare/core/types/pull<nagare/io/file/bytes,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileRead,fsys,ndet,net,read<global>,ui,write<global>>>*/
  }
  return kk_nagare_core_types__pull_box(_x_x1222, _ctx);
}
static kk_nagare_core_types__pull kk_nagare_io_file_readAllBytes_fun1214(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readAllBytes_fun1214__t* _self = kk_function_as(struct kk_nagare_io_file_readAllBytes_fun1214__t*, _fself, _ctx);
  kk_std_core_types__optional chunkSize = _self->chunkSize; /* ? int */
  kk_std_os_path__path filepath = _self->filepath; /* std/os/path/path */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(chunkSize, _ctx);kk_std_os_path__path_dup(filepath, _ctx);}, {}, _ctx)
  kk_string_t _b_x162_165;
  kk_box_t _x_x1215 = kk_std_core_hnd__open_none1(kk_nagare_io_file_new_readAllBytes_fun1216(_ctx), kk_std_os_path__path_box(filepath, _ctx), _ctx); /*10001*/
  _b_x162_165 = kk_string_unbox(_x_x1215); /*string*/
  kk_box_t _x_x1219 = kk_nagare_io_file__effect_with_read_file(_b_x162_165, kk_nagare_io_file_new_readAllBytes_fun1220(chunkSize, _ctx), _ctx); /*2157*/
  return kk_nagare_core_types__pull_unbox(_x_x1219, KK_OWNED, _ctx);
}

kk_nagare_core_types__nstream kk_nagare_io_file_readAllBytes(kk_std_os_path__path filepath, kk_std_core_types__optional chunkSize, kk_context_t* _ctx) { /* (filepath : std/os/path/path, chunkSize : ? int) -> nagare/io/file_effect/readStream<bytes> */ 
  kk_nagare_core_types__pull _x_x1213 = kk_nagare_core_types__new_PEval(kk_reuse_null, 0, kk_nagare_io_file_new_readAllBytes_fun1214(chunkSize, filepath, _ctx), _ctx); /*nagare/core/types/pull<19,20>*/
  return kk_nagare_core_types__new_Stream(_x_x1213, _ctx);
}
 
// monadic lift

kk_unit_t kk_nagare_io_file__mlift_lift_unroll_writeAllChunksBytes_10000_10368_10659(kk_std_core_types__list _uniq_xx_10154, kk_nagare_io_file__effect__write_handle h, kk_integer_t wild__, kk_context_t* _ctx) { /* (list<bytes>, h : nagare/io/file_effect/write-handle, wild_ : int) -> <nagare/io/file_effect/fileWrite,alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> () */ 
  kk_integer_drop(wild__, _ctx);
  kk_nagare_io_file__lift_unroll_writeAllChunksBytes_10000_10368(h, _uniq_xx_10154, _ctx); return kk_Unit;
}
 
// lifted local: @lift-unroll-writeAllChunksBytes@10000@10367, @unroll-writeAllChunksBytes@10000, @spec-x10156
// specialized: std/core/list/@unroll-foreach@10017, on parameters @uniq-action@10151, using:
// @uniq-action@10151 = fn<<(nagare/io/file_effect/fileWrite :: (E, V) -> V),(alloc :: H -> X)<(global :: H)>,(console/console :: X),(div :: X),(exn :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>>>(b: nagare/io/file/bytes){
//   val _ : int
//         = std/core/types/@open<(nagare/io/file_effect/fileWrite :: (E, V) -> V),<(nagare/io/file_effect/fileWrite :: (E, V) -> V),(alloc :: H -> X)<(global :: H)>,(console/console :: X),(div :: X),(exn :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>>,(h : nagare/io/file_effect/write-handle, content : (vector :: V -> V)<int8>) -> (nagare/io/file_effect/fileWrite :: (E, V) -> V) int,(h : nagare/io/file_effect/write-handle, content : (vector :: V -> V)<int8>) -> <(nagare/io/file_effect/fileWrite :: (E, V) -> V),(alloc :: H -> X)<(global :: H)>,(console/console :: X),(div :: X),(exn :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>> int>((fn<(nagare/io/file_effect/fileWrite :: (E, V) -> V)>(h@0: nagare/io/file_effect/write-handle, content: (vector :: V -> V)<int8>){
//           (std/core/hnd/@perform2<nagare/io/file_effect/write-handle,(vector :: V -> V)<int8>,int,(nagare/io/file_effect/fileWrite :: (E, V) -> V),(nagare/io/file_effect/fileWrite :: (E, V) -> V)>((std/core/types/@open<(total :: E),(nagare/io/file_effect/fileWrite :: (E, V) -> V),(i : hnd/ev-index) -> (hnd/ev :: ((E, V) -> V) -> V)<(nagare/io/file_effect/fileWrite :: (E, V) -> V)>,(i : hnd/ev-index) -> (nagare/io/file_effect/fileWrite :: (E, V) -> V) (hnd/ev :: ((E, V) -> V) -> V)<(nagare/io/file_effect/fileWrite :: (E, V) -> V)>>((std/core/hnd/@evv-at<(nagare/io/file_effect/fileWrite :: (E, V) -> V)>))((std/core/types/@open<(total :: E),(nagare/io/file_effect/fileWrite :: (E, V) -> V),(i : int) -> ssize_t,(i : int) -> (nagare/io/file_effect/fileWrite :: (E, V) -> V) ssize_t>(std/core/types/@make-ssize_t)(0)))), nagare/io/file_effect/writeChunkBytes/@select, h@0, content));
//         }))(h, b);
//   std/core/types/Unit;
// }


// lift anonymous function
struct kk_nagare_io_file__lift_unroll_writeAllChunksBytes_10000_10368_fun1232__t {
  struct kk_function_s _base;
  kk_ssize_t i_10742;
};
static kk_box_t kk_nagare_io_file__lift_unroll_writeAllChunksBytes_10000_10368_fun1232(kk_function_t _fself, kk_function_t _b_x187, kk_box_t _b_x188, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__new_lift_unroll_writeAllChunksBytes_10000_10368_fun1232(kk_ssize_t i_10742, kk_context_t* _ctx) {
  struct kk_nagare_io_file__lift_unroll_writeAllChunksBytes_10000_10368_fun1232__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__lift_unroll_writeAllChunksBytes_10000_10368_fun1232__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__lift_unroll_writeAllChunksBytes_10000_10368_fun1232, kk_context());
  _self->i_10742 = i_10742;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file__lift_unroll_writeAllChunksBytes_10000_10368_fun1232(kk_function_t _fself, kk_function_t _b_x187, kk_box_t _b_x188, kk_context_t* _ctx) {
  struct kk_nagare_io_file__lift_unroll_writeAllChunksBytes_10000_10368_fun1232__t* _self = kk_function_as(struct kk_nagare_io_file__lift_unroll_writeAllChunksBytes_10000_10368_fun1232__t*, _fself, _ctx);
  kk_ssize_t i_10742 = _self->i_10742; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_10742, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_10742, _b_x187, _b_x188, _ctx);
}


// lift anonymous function
struct kk_nagare_io_file__lift_unroll_writeAllChunksBytes_10000_10368_fun1234__t {
  struct kk_function_s _base;
  kk_std_core_types__list _uniq_xx_10154_0;
  kk_nagare_io_file__effect__write_handle h_0;
};
static kk_box_t kk_nagare_io_file__lift_unroll_writeAllChunksBytes_10000_10368_fun1234(kk_function_t _fself, kk_box_t _b_x197, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__new_lift_unroll_writeAllChunksBytes_10000_10368_fun1234(kk_std_core_types__list _uniq_xx_10154_0, kk_nagare_io_file__effect__write_handle h_0, kk_context_t* _ctx) {
  struct kk_nagare_io_file__lift_unroll_writeAllChunksBytes_10000_10368_fun1234__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__lift_unroll_writeAllChunksBytes_10000_10368_fun1234__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__lift_unroll_writeAllChunksBytes_10000_10368_fun1234, kk_context());
  _self->_uniq_xx_10154_0 = _uniq_xx_10154_0;
  _self->h_0 = h_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file__lift_unroll_writeAllChunksBytes_10000_10368_fun1234(kk_function_t _fself, kk_box_t _b_x197, kk_context_t* _ctx) {
  struct kk_nagare_io_file__lift_unroll_writeAllChunksBytes_10000_10368_fun1234__t* _self = kk_function_as(struct kk_nagare_io_file__lift_unroll_writeAllChunksBytes_10000_10368_fun1234__t*, _fself, _ctx);
  kk_std_core_types__list _uniq_xx_10154_0 = _self->_uniq_xx_10154_0; /* list<nagare/io/file/bytes> */
  kk_nagare_io_file__effect__write_handle h_0 = _self->h_0; /* nagare/io/file_effect/write-handle */
  kk_drop_match(_self, {kk_std_core_types__list_dup(_uniq_xx_10154_0, _ctx);kk_nagare_io_file__effect__write_handle_dup(h_0, _ctx);}, {}, _ctx)
  kk_integer_t wild___0_200 = kk_integer_unbox(_b_x197, _ctx); /*int*/;
  kk_unit_t _x_x1235 = kk_Unit;
  kk_nagare_io_file__mlift_lift_unroll_writeAllChunksBytes_10000_10368_10659(_uniq_xx_10154_0, h_0, wild___0_200, _ctx);
  return kk_unit_box(_x_x1235);
}

kk_unit_t kk_nagare_io_file__lift_unroll_writeAllChunksBytes_10000_10368(kk_nagare_io_file__effect__write_handle h_0, kk_std_core_types__list _uniq_xs_10150, kk_context_t* _ctx) { /* (h : nagare/io/file_effect/write-handle, list<bytes>) -> <nagare/io/file_effect/fileWrite,alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> () */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_xs_10150, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1228 = kk_std_core_types__as_Cons(_uniq_xs_10150, _ctx);
    kk_box_t _box_x171 = _con_x1228->head;
    kk_std_core_types__list _uniq_xx_10154_0 = _con_x1228->tail;
    kk_vector_t _uniq_x_10153 = kk_vector_unbox(_box_x171, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10150, _ctx)) {
      kk_datatype_ptr_free(_uniq_xs_10150, _ctx);
    }
    else {
      kk_vector_dup(_uniq_x_10153, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10154_0, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10150, _ctx);
    }
    kk_ssize_t i_10742 = (KK_IZ(1)); /*hnd/ev-index*/;
    kk_evv_t w = kk_evv_swap_create1(i_10742,kk_context()); /*hnd/evv<<nagare/io/file_effect/fileWrite,alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
    kk_std_core_hnd__ev evx_10746 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<nagare/io/file_effect/fileWrite>*/;
    kk_integer_t y;
    kk_box_t _x_x1229;
    {
      struct kk_std_core_hnd_Ev* _con_x1230 = kk_std_core_hnd__as_Ev(evx_10746, _ctx);
      kk_box_t _box_x172 = _con_x1230->hnd;
      int32_t m = _con_x1230->marker;
      kk_nagare_io_file__effect__fileWrite h_1 = kk_nagare_io_file__effect__fileWrite_unbox(_box_x172, KK_BORROWED, _ctx);
      kk_nagare_io_file__effect__fileWrite_dup(h_1, _ctx);
      kk_std_core_hnd__clause2 _match_x1055;
      kk_std_core_hnd__clause2 _brw_x1056 = kk_nagare_io_file__effect_writeChunkBytes_fs__select(h_1, _ctx); /*hnd/clause2<nagare/io/file_effect/write-handle,vector<int8>,int,nagare/io/file_effect/fileWrite,1647,1648>*/;
      kk_datatype_ptr_dropn(h_1, (KK_I32(5)), _ctx);
      _match_x1055 = _brw_x1056; /*hnd/clause2<nagare/io/file_effect/write-handle,vector<int8>,int,nagare/io/file_effect/fileWrite,1647,1648>*/
      {
        kk_function_t _fun_unbox_x177 = _match_x1055.clause;
        _x_x1229 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_box_t, kk_context_t*), _fun_unbox_x177, (_fun_unbox_x177, m, evx_10746, kk_nagare_io_file__effect__write_handle_box(h_0, _ctx), kk_vector_box(_uniq_x_10153, _ctx), _ctx), _ctx); /*10016*/
      }
    }
    y = kk_integer_unbox(_x_x1229, _ctx); /*int*/
    kk_evv_set(w,kk_context());
    kk_integer_t x_10739;
    if (kk_yielding(kk_context())) {
      kk_integer_drop(y, _ctx);
      kk_box_t _x_x1231 = kk_std_core_hnd_yield_cont(kk_nagare_io_file__new_lift_unroll_writeAllChunksBytes_10000_10368_fun1232(i_10742, _ctx), _ctx); /*10002*/
      x_10739 = kk_integer_unbox(_x_x1231, _ctx); /*int*/
    }
    else {
      x_10739 = y; /*int*/
    }
    kk_integer_drop(x_10739, _ctx);
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x1233 = kk_std_core_hnd_yield_extend(kk_nagare_io_file__new_lift_unroll_writeAllChunksBytes_10000_10368_fun1234(_uniq_xx_10154_0, h_0, _ctx), _ctx); /*10001*/
      kk_unit_unbox(_x_x1233); return kk_Unit;
    }
    { // tailcall
      _uniq_xs_10150 = _uniq_xx_10154_0;
      goto kk__tailcall;
    }
  }
  {
    kk_Unit; return kk_Unit;
  }
}
 
// lifted local: @unroll-writeAllChunksBytes@10000, @spec-x10149
// specialized: std/core/list/foreach, on parameters @uniq-action@10146, using:
// @uniq-action@10146 = fn<<(nagare/io/file_effect/fileWrite :: (E, V) -> V),(alloc :: H -> X)<(global :: H)>,(console/console :: X),(div :: X),(exn :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>>>(b: nagare/io/file/bytes){
//   val _ : int
//         = std/core/types/@open<(nagare/io/file_effect/fileWrite :: (E, V) -> V),<(nagare/io/file_effect/fileWrite :: (E, V) -> V),(alloc :: H -> X)<(global :: H)>,(console/console :: X),(div :: X),(exn :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>>,(h : nagare/io/file_effect/write-handle, content : (vector :: V -> V)<int8>) -> (nagare/io/file_effect/fileWrite :: (E, V) -> V) int,(h : nagare/io/file_effect/write-handle, content : (vector :: V -> V)<int8>) -> <(nagare/io/file_effect/fileWrite :: (E, V) -> V),(alloc :: H -> X)<(global :: H)>,(console/console :: X),(div :: X),(exn :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>> int>((fn<(nagare/io/file_effect/fileWrite :: (E, V) -> V)>(h@0: nagare/io/file_effect/write-handle, content: (vector :: V -> V)<int8>){
//           (std/core/hnd/@perform2<nagare/io/file_effect/write-handle,(vector :: V -> V)<int8>,int,(nagare/io/file_effect/fileWrite :: (E, V) -> V),(nagare/io/file_effect/fileWrite :: (E, V) -> V)>((std/core/types/@open<(total :: E),(nagare/io/file_effect/fileWrite :: (E, V) -> V),(i : hnd/ev-index) -> (hnd/ev :: ((E, V) -> V) -> V)<(nagare/io/file_effect/fileWrite :: (E, V) -> V)>,(i : hnd/ev-index) -> (nagare/io/file_effect/fileWrite :: (E, V) -> V) (hnd/ev :: ((E, V) -> V) -> V)<(nagare/io/file_effect/fileWrite :: (E, V) -> V)>>((std/core/hnd/@evv-at<(nagare/io/file_effect/fileWrite :: (E, V) -> V)>))((std/core/types/@open<(total :: E),(nagare/io/file_effect/fileWrite :: (E, V) -> V),(i : int) -> ssize_t,(i : int) -> (nagare/io/file_effect/fileWrite :: (E, V) -> V) ssize_t>(std/core/types/@make-ssize_t)(0)))), nagare/io/file_effect/writeChunkBytes/@select, h@0, content));
//         }))(h, b);
//   std/core/types/Unit;
// }

kk_unit_t kk_nagare_io_file__lift_unroll_writeAllChunksBytes_10000_10367(kk_nagare_io_file__effect__write_handle h, kk_std_core_types__list _uniq_xs_10145, kk_context_t* _ctx) { /* (h : nagare/io/file_effect/write-handle, list<bytes>) -> <nagare/io/file_effect/fileWrite,alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> () */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10145, _ctx)) {
    kk_Unit; return kk_Unit;
  }
  {
    kk_nagare_io_file__lift_unroll_writeAllChunksBytes_10000_10368(h, _uniq_xs_10145, _ctx); return kk_Unit;
  }
}
 
// monadic lift

kk_unit_t kk_nagare_io_file__mlift_unroll_writeAllChunksBytes_10000_10660(kk_nagare_io_file__effect__write_handle h, kk_nagare_core_types__pull tail, kk_unit_t wild___0, kk_context_t* _ctx) { /* (h : nagare/io/file_effect/write-handle, tail : nagare/core/types/pull<bytes,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>>>, wild_@0 : ()) -> <nagare/io/file_effect/fileWrite,alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> () */ 
  kk_nagare_io_file__unroll_writeAllChunksBytes_10000(tail, h, _ctx); return kk_Unit;
}
 
// monadic lift

kk_unit_t kk_nagare_io_file__mlift_unroll_writeAllChunksBytes_10000_10661(kk_nagare_io_file__effect__write_handle h_0, kk_nagare_core_types__pull _y_x10442, kk_context_t* _ctx) { /* (h : nagare/io/file_effect/write-handle, nagare/core/types/pull<bytes,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>>>) -> <alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>> () */ 
  kk_nagare_io_file__unroll_writeAllChunksBytes_10000(_y_x10442, h_0, _ctx); return kk_Unit;
}
 
// monadic lift

kk_unit_t kk_nagare_io_file__mlift_unroll_writeAllChunksBytes_10000_10662(kk_nagare_io_file__effect__write_handle h_1, kk_function_t release, kk_nagare_core_types__pull tail_0, kk_unit_t wild___1, kk_context_t* _ctx) { /* (h : nagare/io/file_effect/write-handle, release : () -> <alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>> (), tail@0 : nagare/core/types/pull<bytes,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>>>, wild_@1 : ()) -> <alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>> () */ 
  kk_unit_t _b_x202_204 = kk_Unit;
  kk_nagare_io_file__unroll_writeAllChunksBytes_10000(tail_0, h_1, _ctx);
  kk_box_t _x_x1236 = kk_std_core_hnd_finally_prompt(release, kk_unit_box(_b_x202_204), _ctx); /*10000*/
  kk_unit_unbox(_x_x1236); return kk_Unit;
}


// lift anonymous function
struct kk_nagare_io_file__unroll_writeAllChunksBytes_10000_fun1239__t {
  struct kk_function_s _base;
  kk_nagare_core_types__pull tail_1;
  kk_nagare_io_file__effect__write_handle h_2;
};
static kk_box_t kk_nagare_io_file__unroll_writeAllChunksBytes_10000_fun1239(kk_function_t _fself, kk_box_t _b_x206, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__new_unroll_writeAllChunksBytes_10000_fun1239(kk_nagare_core_types__pull tail_1, kk_nagare_io_file__effect__write_handle h_2, kk_context_t* _ctx) {
  struct kk_nagare_io_file__unroll_writeAllChunksBytes_10000_fun1239__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__unroll_writeAllChunksBytes_10000_fun1239__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__unroll_writeAllChunksBytes_10000_fun1239, kk_context());
  _self->tail_1 = tail_1;
  _self->h_2 = h_2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file__unroll_writeAllChunksBytes_10000_fun1239(kk_function_t _fself, kk_box_t _b_x206, kk_context_t* _ctx) {
  struct kk_nagare_io_file__unroll_writeAllChunksBytes_10000_fun1239__t* _self = kk_function_as(struct kk_nagare_io_file__unroll_writeAllChunksBytes_10000_fun1239__t*, _fself, _ctx);
  kk_nagare_core_types__pull tail_1 = _self->tail_1; /* nagare/core/types/pull<nagare/io/file/bytes,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>>> */
  kk_nagare_io_file__effect__write_handle h_2 = _self->h_2; /* nagare/io/file_effect/write-handle */
  kk_drop_match(_self, {kk_nagare_core_types__pull_dup(tail_1, _ctx);kk_nagare_io_file__effect__write_handle_dup(h_2, _ctx);}, {}, _ctx)
  kk_unit_t wild___0_0_218 = kk_Unit;
  kk_unit_unbox(_b_x206);
  kk_unit_t _x_x1240 = kk_Unit;
  kk_nagare_io_file__mlift_unroll_writeAllChunksBytes_10000_10660(h_2, tail_1, wild___0_0_218, _ctx);
  return kk_unit_box(_x_x1240);
}


// lift anonymous function
struct kk_nagare_io_file__unroll_writeAllChunksBytes_10000_fun1243__t {
  struct kk_function_s _base;
  kk_nagare_io_file__effect__write_handle h_2;
};
static kk_box_t kk_nagare_io_file__unroll_writeAllChunksBytes_10000_fun1243(kk_function_t _fself, kk_box_t _b_x208, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__new_unroll_writeAllChunksBytes_10000_fun1243(kk_nagare_io_file__effect__write_handle h_2, kk_context_t* _ctx) {
  struct kk_nagare_io_file__unroll_writeAllChunksBytes_10000_fun1243__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__unroll_writeAllChunksBytes_10000_fun1243__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__unroll_writeAllChunksBytes_10000_fun1243, kk_context());
  _self->h_2 = h_2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file__unroll_writeAllChunksBytes_10000_fun1243(kk_function_t _fself, kk_box_t _b_x208, kk_context_t* _ctx) {
  struct kk_nagare_io_file__unroll_writeAllChunksBytes_10000_fun1243__t* _self = kk_function_as(struct kk_nagare_io_file__unroll_writeAllChunksBytes_10000_fun1243__t*, _fself, _ctx);
  kk_nagare_io_file__effect__write_handle h_2 = _self->h_2; /* nagare/io/file_effect/write-handle */
  kk_drop_match(_self, {kk_nagare_io_file__effect__write_handle_dup(h_2, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull _y_x10442_0_219 = kk_nagare_core_types__pull_unbox(_b_x208, KK_OWNED, _ctx); /*nagare/core/types/pull<nagare/io/file/bytes,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_unit_t _x_x1244 = kk_Unit;
  kk_nagare_io_file__mlift_unroll_writeAllChunksBytes_10000_10661(h_2, _y_x10442_0_219, _ctx);
  return kk_unit_box(_x_x1244);
}


// lift anonymous function
struct kk_nagare_io_file__unroll_writeAllChunksBytes_10000_fun1247__t {
  struct kk_function_s _base;
  kk_function_t release_0;
  kk_nagare_core_types__pull tail_0_0;
  kk_nagare_io_file__effect__write_handle h_2;
};
static kk_box_t kk_nagare_io_file__unroll_writeAllChunksBytes_10000_fun1247(kk_function_t _fself, kk_box_t _b_x210, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__new_unroll_writeAllChunksBytes_10000_fun1247(kk_function_t release_0, kk_nagare_core_types__pull tail_0_0, kk_nagare_io_file__effect__write_handle h_2, kk_context_t* _ctx) {
  struct kk_nagare_io_file__unroll_writeAllChunksBytes_10000_fun1247__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__unroll_writeAllChunksBytes_10000_fun1247__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__unroll_writeAllChunksBytes_10000_fun1247, kk_context());
  _self->release_0 = release_0;
  _self->tail_0_0 = tail_0_0;
  _self->h_2 = h_2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file__unroll_writeAllChunksBytes_10000_fun1247(kk_function_t _fself, kk_box_t _b_x210, kk_context_t* _ctx) {
  struct kk_nagare_io_file__unroll_writeAllChunksBytes_10000_fun1247__t* _self = kk_function_as(struct kk_nagare_io_file__unroll_writeAllChunksBytes_10000_fun1247__t*, _fself, _ctx);
  kk_function_t release_0 = _self->release_0; /* () -> <alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>> () */
  kk_nagare_core_types__pull tail_0_0 = _self->tail_0_0; /* nagare/core/types/pull<nagare/io/file/bytes,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>>> */
  kk_nagare_io_file__effect__write_handle h_2 = _self->h_2; /* nagare/io/file_effect/write-handle */
  kk_drop_match(_self, {kk_function_dup(release_0, _ctx);kk_nagare_core_types__pull_dup(tail_0_0, _ctx);kk_nagare_io_file__effect__write_handle_dup(h_2, _ctx);}, {}, _ctx)
  kk_unit_t wild___1_0_220 = kk_Unit;
  kk_unit_unbox(_b_x210);
  kk_unit_t _x_x1248 = kk_Unit;
  kk_nagare_io_file__mlift_unroll_writeAllChunksBytes_10000_10662(h_2, release_0, tail_0_0, wild___1_0_220, _ctx);
  return kk_unit_box(_x_x1248);
}

kk_unit_t kk_nagare_io_file__unroll_writeAllChunksBytes_10000(kk_nagare_core_types__pull source, kk_nagare_io_file__effect__write_handle h_2, kk_context_t* _ctx) { /* (source : nagare/core/types/pull<bytes,<nagare/io/file_effect/fileWrite|io>>, h : nagare/io/file_effect/write-handle) -> <io,nagare/io/file_effect/fileWrite> () */ 
  kk__tailcall: ;
  if (kk_nagare_core_types__is_PDone(source, _ctx)) {
    kk_Unit; return kk_Unit;
  }
  if (kk_nagare_core_types__is_POutput(source, _ctx)) {
    struct kk_nagare_core_types_POutput* _con_x1237 = kk_nagare_core_types__as_POutput(source, _ctx);
    kk_nagare_core_types__chunk out = _con_x1237->out;
    kk_nagare_core_types__pull tail_1 = _con_x1237->tail;
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
      kk_unit_t x_10752 = kk_Unit;
      kk_nagare_io_file__lift_unroll_writeAllChunksBytes_10000_10367(h_2, values, _ctx);
      if (kk_yielding(kk_context())) {
        kk_box_t _x_x1238 = kk_std_core_hnd_yield_extend(kk_nagare_io_file__new_unroll_writeAllChunksBytes_10000_fun1239(tail_1, h_2, _ctx), _ctx); /*10001*/
        kk_unit_unbox(_x_x1238); return kk_Unit;
      }
      { // tailcall
        source = tail_1;
        goto kk__tailcall;
      }
    }
  }
  if (kk_nagare_core_types__is_PEval(source, _ctx)) {
    struct kk_nagare_core_types_PEval* _con_x1241 = kk_nagare_core_types__as_PEval(source, _ctx);
    kk_function_t next_0 = _con_x1241->next;
    if kk_likely(kk_datatype_ptr_is_unique(source, _ctx)) {
      kk_datatype_ptr_free(source, _ctx);
    }
    else {
      kk_function_dup(next_0, _ctx);
      kk_datatype_ptr_decref(source, _ctx);
    }
    kk_nagare_core_types__pull x_0_10755 = kk_function_call(kk_nagare_core_types__pull, (kk_function_t, kk_context_t*), next_0, (next_0, _ctx), _ctx); /*nagare/core/types/pull<nagare/io/file/bytes,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>>>*/;
    if (kk_yielding(kk_context())) {
      kk_nagare_core_types__pull_drop(x_0_10755, _ctx);
      kk_box_t _x_x1242 = kk_std_core_hnd_yield_extend(kk_nagare_io_file__new_unroll_writeAllChunksBytes_10000_fun1243(h_2, _ctx), _ctx); /*10001*/
      kk_unit_unbox(_x_x1242); return kk_Unit;
    }
    { // tailcall
      source = x_0_10755;
      goto kk__tailcall;
    }
  }
  {
    struct kk_nagare_core_types_PAcquire* _con_x1245 = kk_nagare_core_types__as_PAcquire(source, _ctx);
    kk_function_t acquire = _con_x1245->acquire;
    kk_function_t release_0 = _con_x1245->release;
    kk_nagare_core_types__pull tail_0_0 = _con_x1245->tail;
    if kk_likely(kk_datatype_ptr_is_unique(source, _ctx)) {
      kk_datatype_ptr_free(source, _ctx);
    }
    else {
      kk_function_dup(acquire, _ctx);
      kk_function_dup(release_0, _ctx);
      kk_nagare_core_types__pull_dup(tail_0_0, _ctx);
      kk_datatype_ptr_decref(source, _ctx);
    }
    kk_unit_t x_1_10758 = kk_Unit;
    kk_function_call(kk_unit_t, (kk_function_t, kk_context_t*), acquire, (acquire, _ctx), _ctx);
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x1246 = kk_std_core_hnd_yield_extend(kk_nagare_io_file__new_unroll_writeAllChunksBytes_10000_fun1247(release_0, tail_0_0, h_2, _ctx), _ctx); /*10001*/
      kk_unit_unbox(_x_x1246); return kk_Unit;
    }
    {
      kk_unit_t _b_x212_217 = kk_Unit;
      kk_nagare_io_file__unroll_writeAllChunksBytes_10000(tail_0_0, h_2, _ctx);
      kk_box_t _x_x1249 = kk_std_core_hnd_finally_prompt(release_0, kk_unit_box(_b_x212_217), _ctx); /*10000*/
      kk_unit_unbox(_x_x1249); return kk_Unit;
    }
  }
}
 
// Write a stream of byte chunks to a file.


// lift anonymous function
struct kk_nagare_io_file_writeAllBytes_fun1252__t {
  struct kk_function_s _base;
  kk_std_os_path__path filepath;
};
static kk_nagare_core_types__nstream kk_nagare_io_file_writeAllBytes_fun1252(kk_function_t _fself, kk_nagare_core_types__nstream source, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_writeAllBytes_fun1252(kk_std_os_path__path filepath, kk_context_t* _ctx) {
  struct kk_nagare_io_file_writeAllBytes_fun1252__t* _self = kk_function_alloc_as(struct kk_nagare_io_file_writeAllBytes_fun1252__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file_writeAllBytes_fun1252, kk_context());
  _self->filepath = filepath;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_io_file_writeAllBytes_fun1254__t {
  struct kk_function_s _base;
  kk_std_os_path__path filepath;
  kk_nagare_core_types__nstream source;
};
static kk_nagare_core_types__pull kk_nagare_io_file_writeAllBytes_fun1254(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_writeAllBytes_fun1254(kk_std_os_path__path filepath, kk_nagare_core_types__nstream source, kk_context_t* _ctx) {
  struct kk_nagare_io_file_writeAllBytes_fun1254__t* _self = kk_function_alloc_as(struct kk_nagare_io_file_writeAllBytes_fun1254__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file_writeAllBytes_fun1254, kk_context());
  _self->filepath = filepath;
  _self->source = source;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_io_file_writeAllBytes_fun1256__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_io_file_writeAllBytes_fun1256(kk_function_t _fself, kk_box_t _b_x227, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_writeAllBytes_fun1256(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file_writeAllBytes_fun1256, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_io_file_writeAllBytes_fun1256(kk_function_t _fself, kk_box_t _b_x227, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1257;
  kk_std_os_path__path _x_x1258 = kk_std_os_path__path_unbox(_b_x227, KK_OWNED, _ctx); /*std/os/path/path*/
  _x_x1257 = kk_std_os_path_string(_x_x1258, _ctx); /*string*/
  return kk_string_box(_x_x1257);
}


// lift anonymous function
struct kk_nagare_io_file_writeAllBytes_fun1260__t {
  struct kk_function_s _base;
  kk_nagare_core_types__nstream source;
};
static kk_box_t kk_nagare_io_file_writeAllBytes_fun1260(kk_function_t _fself, kk_nagare_io_file__effect__write_handle _b_x234, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_writeAllBytes_fun1260(kk_nagare_core_types__nstream source, kk_context_t* _ctx) {
  struct kk_nagare_io_file_writeAllBytes_fun1260__t* _self = kk_function_alloc_as(struct kk_nagare_io_file_writeAllBytes_fun1260__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file_writeAllBytes_fun1260, kk_context());
  _self->source = source;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_io_file_writeAllBytes_fun1264__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_io_file_writeAllBytes_fun1264(kk_function_t _fself, kk_box_t _b_x229, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_writeAllBytes_fun1264(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file_writeAllBytes_fun1264, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_io_file_writeAllBytes_fun1264(kk_function_t _fself, kk_box_t _b_x229, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_nagare_core_types__pull _x_x1265;
  kk_unit_t _x_x1266 = kk_Unit;
  kk_unit_unbox(_b_x229);
  _x_x1265 = kk_nagare_io_file__mlift_writeAllBytes_10663(_x_x1266, _ctx); /*nagare/core/types/pull<(),<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>>>*/
  return kk_nagare_core_types__pull_box(_x_x1265, _ctx);
}
static kk_box_t kk_nagare_io_file_writeAllBytes_fun1260(kk_function_t _fself, kk_nagare_io_file__effect__write_handle _b_x234, kk_context_t* _ctx) {
  struct kk_nagare_io_file_writeAllBytes_fun1260__t* _self = kk_function_as(struct kk_nagare_io_file_writeAllBytes_fun1260__t*, _fself, _ctx);
  kk_nagare_core_types__nstream source = _self->source; /* nagare/core/types/nstream<nagare/io/file/bytes,<nagare/io/file_effect/fileWrite|io>> */
  kk_drop_match(_self, {kk_nagare_core_types__nstream_dup(source, _ctx);}, {}, _ctx)
  kk_nagare_io_file__effect__write_handle h_242 = _b_x234; /*nagare/io/file_effect/write-handle*/;
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  kk_unit_t x_0_10765 = kk_Unit;
  {
    kk_nagare_core_types__pull step = source.step;
    kk_nagare_core_types__pull_dup(step, _ctx);
    if (kk_nagare_core_types__is_PDone(step, _ctx)) {
      kk_nagare_core_types__nstream_drop(source, _ctx);
    }
    else {
      kk_nagare_core_types__pull_drop(step, _ctx);
      kk_nagare_core_types__pull _x_x1261;
      {
        kk_nagare_core_types__pull step_0 = source.step;
        _x_x1261 = step_0; /*nagare/core/types/pull<nagare/io/file/bytes,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>>>*/
      }
      kk_nagare_io_file__unroll_writeAllChunksBytes_10000(_x_x1261, h_242, _ctx);
    }
  }
  kk_nagare_core_types__pull _x_x1262;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1263 = kk_std_core_hnd_yield_extend(kk_nagare_io_file_new_writeAllBytes_fun1264(_ctx), _ctx); /*10001*/
    _x_x1262 = kk_nagare_core_types__pull_unbox(_x_x1263, KK_OWNED, _ctx); /*nagare/core/types/pull<(),<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>>>*/
  }
  else {
    kk_unit_t _b_x230_240 = kk_Unit;
    kk_std_core_types__list _b_x231_241 = kk_std_core_types__new_Nil(_ctx); /*list<()>*/;
    kk_nagare_core_types__chunk _x_x1267;
    kk_std_core_types__list _x_x1268 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_unit_box(_b_x230_240), _b_x231_241, _ctx); /*list<10021>*/
    _x_x1267 = kk_nagare_core_types__new_Chunk(_x_x1268, _ctx); /*nagare/core/types/chunk<4>*/
    _x_x1262 = kk_nagare_core_types__new_POutput(kk_reuse_null, 0, _x_x1267, kk_nagare_core_types__new_PDone(_ctx), _ctx); /*nagare/core/types/pull<(),<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>>>*/
  }
  return kk_nagare_core_types__pull_box(_x_x1262, _ctx);
}
static kk_nagare_core_types__pull kk_nagare_io_file_writeAllBytes_fun1254(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_io_file_writeAllBytes_fun1254__t* _self = kk_function_as(struct kk_nagare_io_file_writeAllBytes_fun1254__t*, _fself, _ctx);
  kk_std_os_path__path filepath = _self->filepath; /* std/os/path/path */
  kk_nagare_core_types__nstream source = _self->source; /* nagare/core/types/nstream<nagare/io/file/bytes,<nagare/io/file_effect/fileWrite|io>> */
  kk_drop_match(_self, {kk_std_os_path__path_dup(filepath, _ctx);kk_nagare_core_types__nstream_dup(source, _ctx);}, {}, _ctx)
  kk_string_t _b_x232_235;
  kk_box_t _x_x1255 = kk_std_core_hnd__open_none1(kk_nagare_io_file_new_writeAllBytes_fun1256(_ctx), kk_std_os_path__path_box(filepath, _ctx), _ctx); /*10001*/
  _b_x232_235 = kk_string_unbox(_x_x1255); /*string*/
  kk_box_t _x_x1259 = kk_nagare_io_file__effect_with_write_file(_b_x232_235, kk_nagare_io_file_new_writeAllBytes_fun1260(source, _ctx), _ctx); /*2199*/
  return kk_nagare_core_types__pull_unbox(_x_x1259, KK_OWNED, _ctx);
}
static kk_nagare_core_types__nstream kk_nagare_io_file_writeAllBytes_fun1252(kk_function_t _fself, kk_nagare_core_types__nstream source, kk_context_t* _ctx) {
  struct kk_nagare_io_file_writeAllBytes_fun1252__t* _self = kk_function_as(struct kk_nagare_io_file_writeAllBytes_fun1252__t*, _fself, _ctx);
  kk_std_os_path__path filepath = _self->filepath; /* std/os/path/path */
  kk_drop_match(_self, {kk_std_os_path__path_dup(filepath, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull _x_x1253 = kk_nagare_core_types__new_PEval(kk_reuse_null, 0, kk_nagare_io_file_new_writeAllBytes_fun1254(filepath, source, _ctx), _ctx); /*nagare/core/types/pull<19,20>*/
  return kk_nagare_core_types__new_Stream(_x_x1253, _ctx);
}

kk_function_t kk_nagare_io_file_writeAllBytes(kk_std_os_path__path filepath, kk_context_t* _ctx) { /* (filepath : std/os/path/path) -> nagare/io/file_effect/writePipe<bytes,()> */ 
  return kk_nagare_io_file_new_writeAllBytes_fun1252(filepath, _ctx);
}
 
// Decode as many complete UTF-8 codepoints as possible from a byte list.
// Returns (decoded-string, leftover-incomplete-bytes).
// We pass the full buffer to the C FFI which handles UTF-8 reconstruction;
// any trailing incomplete sequence is returned as leftover for the next chunk.

kk_std_core_types__tuple2 kk_nagare_io_file_trydecode_utf8_partial(kk_std_core_types__list buf, kk_context_t* _ctx) { /* (buf : list<int8>) -> (string, list<int8>) */ 
  if (kk_std_core_types__is_Nil(buf, _ctx)) {
    kk_box_t _x_x1269;
    kk_string_t _x_x1270 = kk_string_empty(); /*string*/
    _x_x1269 = kk_string_box(_x_x1270); /*10037*/
    return kk_std_core_types__new_Tuple2(_x_x1269, kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx), _ctx);
  }
  {
    kk_vector_t vec;
    kk_std_core_types__list _x_x1272 = kk_std_core_types__list_dup(buf, _ctx); /*list<int8>*/
    vec = kk_std_core_vector_unvlist(_x_x1272, _ctx); /*vector<int8>*/
    kk_string_t s = kk_nagare_io_file__effect_nagare_bytes_to_string(vec, _ctx); /*string*/;
    kk_std_core_types__list xs_1_10008;
    kk_vector_t _x_x1273;
    kk_string_t _x_x1274 = kk_string_dup(s, _ctx); /*string*/
    _x_x1273 = kk_nagare_io_file__effect_nagare_string_to_bytes(_x_x1274, _ctx); /*vector<int8>*/
    xs_1_10008 = kk_std_core_vector_vlist(_x_x1273, kk_std_core_types__new_None(_ctx), _ctx); /*list<int8>*/
    kk_integer_t consumed;
    if (kk_std_core_types__is_Nil(xs_1_10008, _ctx)) {
      consumed = kk_integer_from_small(0); /*int*/
    }
    else {
      consumed = kk_std_core_list__unroll_lift_length_6003_10000(xs_1_10008, kk_integer_from_small(0), _ctx); /*int*/
    }
    kk_std_core_types__list rest = kk_std_core_list_drop(buf, consumed, _ctx); /*list<int8>*/;
    return kk_std_core_types__new_Tuple2(kk_string_box(s), kk_std_core_types__list_box(rest, _ctx), _ctx);
  }
}
 
// lifted local: @lift-unroll-decodeUtf8Pull@10001@10369, @unroll-decodeUtf8Pull@10001, @spec-x10171
// specialized: std/core/list/@unroll-foldl@10005, on parameters @uniq-f@10166, using:
// @uniq-f@10166 = fn(acc: (list :: V -> V)<int8>, b: nagare/io/file/bytes){
//   val ys@10011 : (list :: V -> V)<int8>
//         = std/core/vector/vlist<int8>(b, (std/core/types/@None<(list :: V -> V)<int8>>));
//   match (acc) {
//     ((std/core/types/Nil() : (list :: V -> V)<int8> ) as @pat@0@2: ((list :: V -> V)<int8>))
//        -> ys@10011;
//     (@pat@4: ((list :: V -> V)<int8>))
//        -> std/core/list/@unroll-append@10004<int8>(acc, ys@10011);
//   };
// }

kk_std_core_types__list kk_nagare_io_file__lift_unroll_decodeUtf8Pull_10001_10370(kk_std_core_types__list _uniq_xs_10164, kk_std_core_types__list _uniq_z_10165, kk_context_t* _ctx) { /* (list<bytes>, list<int8>) -> list<int8> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_xs_10164, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1275 = kk_std_core_types__as_Cons(_uniq_xs_10164, _ctx);
    kk_box_t _box_x251 = _con_x1275->head;
    kk_std_core_types__list _uniq_xx_10169 = _con_x1275->tail;
    kk_vector_t _uniq_x_10168 = kk_vector_unbox(_box_x251, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10164, _ctx)) {
      kk_datatype_ptr_free(_uniq_xs_10164, _ctx);
    }
    else {
      kk_vector_dup(_uniq_x_10168, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10169, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10164, _ctx);
    }
    kk_std_core_types__list ys_10011 = kk_std_core_vector_vlist(_uniq_x_10168, kk_std_core_types__new_None(_ctx), _ctx); /*list<int8>*/;
    { // tailcall
      kk_std_core_types__list _x_x1276;
      if (kk_std_core_types__is_Nil(_uniq_z_10165, _ctx)) {
        _x_x1276 = ys_10011; /*list<int8>*/
      }
      else {
        _x_x1276 = kk_std_core_list__unroll_append_10004(_uniq_z_10165, ys_10011, _ctx); /*list<int8>*/
      }
      _uniq_xs_10164 = _uniq_xx_10169;
      _uniq_z_10165 = _x_x1276;
      goto kk__tailcall;
    }
  }
  {
    return _uniq_z_10165;
  }
}
 
// lifted local: @unroll-decodeUtf8Pull@10001, @spec-x10163
// specialized: std/core/list/foldl, on parameters @uniq-f@10160, using:
// @uniq-f@10160 = fn(acc: (list :: V -> V)<int8>, b: nagare/io/file/bytes){
//   val ys@10011 : (list :: V -> V)<int8>
//         = std/core/vector/vlist<int8>(b, (std/core/types/@None<(list :: V -> V)<int8>>));
//   match (acc) {
//     ((std/core/types/Nil() : (list :: V -> V)<int8> ) as @pat@0@2: ((list :: V -> V)<int8>))
//        -> ys@10011;
//     (@pat@4: ((list :: V -> V)<int8>))
//        -> std/core/list/@unroll-append@10004<int8>(acc, ys@10011);
//   };
// }

kk_std_core_types__list kk_nagare_io_file__lift_unroll_decodeUtf8Pull_10001_10369(kk_std_core_types__list _uniq_xs_10158, kk_std_core_types__list _uniq_z_10159, kk_context_t* _ctx) { /* (list<bytes>, list<int8>) -> list<int8> */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10158, _ctx)) {
    return _uniq_z_10159;
  }
  {
    return kk_nagare_io_file__lift_unroll_decodeUtf8Pull_10001_10370(_uniq_xs_10158, _uniq_z_10159, _ctx);
  }
}
 
// monadic lift

kk_nagare_core_types__pull kk_nagare_io_file__mlift_trmc_unroll_decodeUtf8Pull_10001_10664(kk_std_core_types__list leftover, kk_nagare_core_types__pull _y_x10457, kk_context_t* _ctx) { /* forall<e> (leftover : list<int8>, nagare/core/types/pull<bytes,e>) -> e nagare/core/types/pull<string,e> */ 
  return kk_nagare_io_file__unroll_decodeUtf8Pull_10001(_y_x10457, leftover, _ctx);
}


// lift anonymous function
struct kk_nagare_io_file__trmc_unroll_decodeUtf8Pull_10001_fun1294__t {
  struct kk_function_s _base;
  kk_std_core_types__list leftover_0;
  kk_function_t next;
};
static kk_nagare_core_types__pull kk_nagare_io_file__trmc_unroll_decodeUtf8Pull_10001_fun1294(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__new_trmc_unroll_decodeUtf8Pull_10001_fun1294(kk_std_core_types__list leftover_0, kk_function_t next, kk_context_t* _ctx) {
  struct kk_nagare_io_file__trmc_unroll_decodeUtf8Pull_10001_fun1294__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__trmc_unroll_decodeUtf8Pull_10001_fun1294__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__trmc_unroll_decodeUtf8Pull_10001_fun1294, kk_context());
  _self->leftover_0 = leftover_0;
  _self->next = next;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_io_file__trmc_unroll_decodeUtf8Pull_10001_fun1296__t {
  struct kk_function_s _base;
  kk_std_core_types__list leftover_0;
};
static kk_box_t kk_nagare_io_file__trmc_unroll_decodeUtf8Pull_10001_fun1296(kk_function_t _fself, kk_box_t _b_x271, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__new_trmc_unroll_decodeUtf8Pull_10001_fun1296(kk_std_core_types__list leftover_0, kk_context_t* _ctx) {
  struct kk_nagare_io_file__trmc_unroll_decodeUtf8Pull_10001_fun1296__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__trmc_unroll_decodeUtf8Pull_10001_fun1296__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__trmc_unroll_decodeUtf8Pull_10001_fun1296, kk_context());
  _self->leftover_0 = leftover_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file__trmc_unroll_decodeUtf8Pull_10001_fun1296(kk_function_t _fself, kk_box_t _b_x271, kk_context_t* _ctx) {
  struct kk_nagare_io_file__trmc_unroll_decodeUtf8Pull_10001_fun1296__t* _self = kk_function_as(struct kk_nagare_io_file__trmc_unroll_decodeUtf8Pull_10001_fun1296__t*, _fself, _ctx);
  kk_std_core_types__list leftover_0 = _self->leftover_0; /* list<int8> */
  kk_drop_match(_self, {kk_std_core_types__list_dup(leftover_0, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull _y_x10457_0_301 = kk_nagare_core_types__pull_unbox(_b_x271, KK_OWNED, _ctx); /*nagare/core/types/pull<nagare/io/file/bytes,1287>*/;
  kk_nagare_core_types__pull _x_x1297 = kk_nagare_io_file__mlift_trmc_unroll_decodeUtf8Pull_10001_10664(leftover_0, _y_x10457_0_301, _ctx); /*nagare/core/types/pull<string,1287>*/
  return kk_nagare_core_types__pull_box(_x_x1297, _ctx);
}
static kk_nagare_core_types__pull kk_nagare_io_file__trmc_unroll_decodeUtf8Pull_10001_fun1294(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_io_file__trmc_unroll_decodeUtf8Pull_10001_fun1294__t* _self = kk_function_as(struct kk_nagare_io_file__trmc_unroll_decodeUtf8Pull_10001_fun1294__t*, _fself, _ctx);
  kk_std_core_types__list leftover_0 = _self->leftover_0; /* list<int8> */
  kk_function_t next = _self->next; /* () -> 1287 nagare/core/types/pull<nagare/io/file/bytes,1287> */
  kk_drop_match(_self, {kk_std_core_types__list_dup(leftover_0, _ctx);kk_function_dup(next, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull x_10767 = kk_function_call(kk_nagare_core_types__pull, (kk_function_t, kk_context_t*), next, (next, _ctx), _ctx); /*nagare/core/types/pull<nagare/io/file/bytes,1287>*/;
  if (kk_yielding(kk_context())) {
    kk_nagare_core_types__pull_drop(x_10767, _ctx);
    kk_box_t _x_x1295 = kk_std_core_hnd_yield_extend(kk_nagare_io_file__new_trmc_unroll_decodeUtf8Pull_10001_fun1296(leftover_0, _ctx), _ctx); /*10001*/
    return kk_nagare_core_types__pull_unbox(_x_x1295, KK_OWNED, _ctx);
  }
  {
    return kk_nagare_io_file__mlift_trmc_unroll_decodeUtf8Pull_10001_10664(leftover_0, x_10767, _ctx);
  }
}

kk_nagare_core_types__pull kk_nagare_io_file__trmc_unroll_decodeUtf8Pull_10001(kk_nagare_core_types__pull source, kk_std_core_types__list leftover_0, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* forall<e> (source : nagare/core/types/pull<bytes,e>, leftover : list<int8>, ctx<nagare/core/types/pull<string,e>>) -> nagare/core/types/pull<string,e> */ 
  kk__tailcall: ;
  if (kk_nagare_core_types__is_PDone(source, _ctx)) {
    kk_box_t _x_x1277;
    if (kk_std_core_types__is_Nil(leftover_0, _ctx)) {
      _x_x1277 = kk_cctx_apply_linear(_acc,(kk_nagare_core_types__pull_box(kk_nagare_core_types__new_PDone(_ctx), _ctx)),kk_context()); /*-1*/
    }
    else {
      kk_std_core_types__list_drop(leftover_0, _ctx);
      kk_box_t _x_x1278;
      kk_nagare_core_types__pull _x_x1279;
      kk_string_t _b_x254_284;
      kk_define_string_literal(static, _s_x1280, 3, "" "\xEF\xBF\xBD" "", _ctx)
      _b_x254_284 = kk_string_dup(_s_x1280, _ctx); /*string*/
      kk_std_core_types__list _b_x255_285 = kk_std_core_types__new_Nil(_ctx); /*list<string>*/;
      kk_nagare_core_types__chunk _x_x1281;
      kk_std_core_types__list _x_x1282 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_string_box(_b_x254_284), _b_x255_285, _ctx); /*list<10021>*/
      _x_x1281 = kk_nagare_core_types__new_Chunk(_x_x1282, _ctx); /*nagare/core/types/chunk<4>*/
      _x_x1279 = kk_nagare_core_types__new_POutput(kk_reuse_null, 0, _x_x1281, kk_nagare_core_types__new_PDone(_ctx), _ctx); /*nagare/core/types/pull<19,20>*/
      _x_x1278 = kk_nagare_core_types__pull_box(_x_x1279, _ctx); /*-1*/
      _x_x1277 = kk_cctx_apply_linear(_acc,_x_x1278,kk_context()); /*-1*/
    }
    return kk_nagare_core_types__pull_unbox(_x_x1277, KK_OWNED, _ctx);
  }
  if (kk_nagare_core_types__is_POutput(source, _ctx)) {
    struct kk_nagare_core_types_POutput* _con_x1283 = kk_nagare_core_types__as_POutput(source, _ctx);
    kk_nagare_core_types__chunk out = _con_x1283->out;
    kk_nagare_core_types__pull tail = _con_x1283->tail;
    kk_reuse_t _ru_x1096 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(source, _ctx)) {
      _ru_x1096 = (kk_datatype_ptr_reuse(source, _ctx));
    }
    else {
      kk_nagare_core_types__chunk_dup(out, _ctx);
      kk_nagare_core_types__pull_dup(tail, _ctx);
      kk_datatype_ptr_decref(source, _ctx);
    }
    {
      kk_std_core_types__list chunks = out.values;
      kk_std_core_types__list combined = kk_nagare_io_file__lift_unroll_decodeUtf8Pull_10001_10369(chunks, leftover_0, _ctx); /*list<int8>*/;
      kk_std_core_types__tuple2 _match_x1047 = kk_nagare_io_file_trydecode_utf8_partial(combined, _ctx); /*(string, list<int8>)*/;
      {
        kk_box_t _box_x258 = _match_x1047.fst;
        kk_box_t _box_x259 = _match_x1047.snd;
        kk_string_t text = kk_string_unbox(_box_x258);
        kk_std_core_types__list rest = kk_std_core_types__list_unbox(_box_x259, KK_BORROWED, _ctx);
        kk_std_core_types__list_dup(rest, _ctx);
        kk_string_dup(text, _ctx);
        kk_std_core_types__tuple2_drop(_match_x1047, _ctx);
        bool _match_x1048;
        kk_string_t _x_x1284 = kk_string_dup(text, _ctx); /*string*/
        kk_string_t _x_x1285 = kk_string_empty(); /*string*/
        _match_x1048 = kk_string_is_eq(_x_x1284,_x_x1285,kk_context()); /*bool*/
        if (_match_x1048) {
          kk_reuse_drop(_ru_x1096,kk_context());
          kk_string_drop(text, _ctx);
          { // tailcall
            source = tail;
            leftover_0 = rest;
            goto kk__tailcall;
          }
        }
        {
          kk_nagare_core_types__pull _trmc_x10402 = kk_datatype_null(); /*nagare/core/types/pull<string,1287>*/;
          kk_nagare_core_types__pull _trmc_x10403;
          kk_nagare_core_types__chunk _x_x1287;
          kk_std_core_types__list _x_x1288 = kk_std_core_types__new_Cons(_ru_x1096, 0, kk_string_box(text), kk_std_core_types__new_Nil(_ctx), _ctx); /*list<10021>*/
          _x_x1287 = kk_nagare_core_types__new_Chunk(_x_x1288, _ctx); /*nagare/core/types/chunk<4>*/
          _trmc_x10403 = kk_nagare_core_types__new_POutput(kk_reuse_null, 0, _x_x1287, _trmc_x10402, _ctx); /*nagare/core/types/pull<string,1287>*/
          kk_field_addr_t _b_x269_288 = kk_field_addr_create(&kk_nagare_core_types__as_POutput(_trmc_x10403, _ctx)->tail, _ctx); /*@field-addr<nagare/core/types/pull<string,1287>>*/;
          { // tailcall
            kk_std_core_types__cctx _x_x1289 = kk_cctx_extend_linear(_acc,(kk_nagare_core_types__pull_box(_trmc_x10403, _ctx)),_b_x269_288,kk_context()); /*ctx<0>*/
            source = tail;
            leftover_0 = rest;
            _acc = _x_x1289;
            goto kk__tailcall;
          }
        }
      }
    }
  }
  if (kk_nagare_core_types__is_PEval(source, _ctx)) {
    struct kk_nagare_core_types_PEval* _con_x1290 = kk_nagare_core_types__as_PEval(source, _ctx);
    kk_function_t next = _con_x1290->next;
    kk_reuse_t _ru_x1097 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(source, _ctx)) {
      _ru_x1097 = (kk_datatype_ptr_reuse(source, _ctx));
    }
    else {
      kk_function_dup(next, _ctx);
      kk_datatype_ptr_decref(source, _ctx);
    }
    kk_box_t _x_x1291;
    kk_box_t _x_x1292;
    kk_nagare_core_types__pull _x_x1293 = kk_nagare_core_types__new_PEval(_ru_x1097, 0, kk_nagare_io_file__new_trmc_unroll_decodeUtf8Pull_10001_fun1294(leftover_0, next, _ctx), _ctx); /*nagare/core/types/pull<19,20>*/
    _x_x1292 = kk_nagare_core_types__pull_box(_x_x1293, _ctx); /*-1*/
    _x_x1291 = kk_cctx_apply_linear(_acc,_x_x1292,kk_context()); /*-1*/
    return kk_nagare_core_types__pull_unbox(_x_x1291, KK_OWNED, _ctx);
  }
  {
    struct kk_nagare_core_types_PAcquire* _con_x1298 = kk_nagare_core_types__as_PAcquire(source, _ctx);
    kk_function_t acquire = _con_x1298->acquire;
    kk_function_t release = _con_x1298->release;
    kk_nagare_core_types__pull tail_0 = _con_x1298->tail;
    kk_reuse_t _ru_x1098 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(source, _ctx)) {
      _ru_x1098 = (kk_datatype_ptr_reuse(source, _ctx));
    }
    else {
      kk_function_dup(acquire, _ctx);
      kk_function_dup(release, _ctx);
      kk_nagare_core_types__pull_dup(tail_0, _ctx);
      kk_datatype_ptr_decref(source, _ctx);
    }
    kk_nagare_core_types__pull _trmc_x10404 = kk_datatype_null(); /*nagare/core/types/pull<string,1287>*/;
    kk_nagare_core_types__pull _trmc_x10405 = kk_nagare_core_types__new_PAcquire(_ru_x1098, 0, acquire, release, _trmc_x10404, _ctx); /*nagare/core/types/pull<string,1287>*/;
    kk_field_addr_t _b_x279_297 = kk_field_addr_create(&kk_nagare_core_types__as_PAcquire(_trmc_x10405, _ctx)->tail, _ctx); /*@field-addr<nagare/core/types/pull<string,1287>>*/;
    { // tailcall
      kk_std_core_types__cctx _x_x1299 = kk_cctx_extend_linear(_acc,(kk_nagare_core_types__pull_box(_trmc_x10405, _ctx)),_b_x279_297,kk_context()); /*ctx<0>*/
      source = tail_0;
      _acc = _x_x1299;
      goto kk__tailcall;
    }
  }
}

kk_nagare_core_types__pull kk_nagare_io_file__unroll_decodeUtf8Pull_10001(kk_nagare_core_types__pull source_0, kk_std_core_types__list leftover_1, kk_context_t* _ctx) { /* forall<e> (source : nagare/core/types/pull<bytes,e>, leftover : list<int8>) -> nagare/core/types/pull<string,e> */ 
  kk_std_core_types__cctx _x_x1300 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_nagare_io_file__trmc_unroll_decodeUtf8Pull_10001(source_0, leftover_1, _x_x1300, _ctx);
}
 
// Decode a stream of byte chunks into UTF-8 strings.
// Handles multi-byte codepoints split across chunk boundaries by carrying
// incomplete leading bytes in a per-step leftover list.


// lift anonymous function
struct kk_nagare_io_file_decodeUtf8_fun1307__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_io_file_decodeUtf8_fun1307(kk_function_t _fself, kk_box_t _b_x311, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_decodeUtf8_fun1307(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file_decodeUtf8_fun1307, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_io_file_decodeUtf8_fun1307(kk_function_t _fself, kk_box_t _b_x311, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_nagare_core_types__pull _c_x10462_313 = kk_nagare_core_types__pull_unbox(_b_x311, KK_OWNED, _ctx); /*nagare/core/types/pull<string,1328>*/;
  kk_nagare_core_types__nstream _x_x1308 = kk_nagare_core_types__new_Stream(_c_x10462_313, _ctx); /*nagare/core/types/nstream<27,28>*/
  return kk_nagare_core_types__nstream_box(_x_x1308, _ctx);
}

kk_nagare_core_types__nstream kk_nagare_io_file_decodeUtf8(kk_nagare_core_types__nstream source, kk_context_t* _ctx) { /* forall<e> (source : nagare/core/types/nstream<bytes,e>) -> nagare/core/types/nstream<string,e> */ 
  {
    kk_nagare_core_types__pull step = source.step;
    kk_nagare_core_types__pull x_10771;
    if (kk_nagare_core_types__is_PDone(step, _ctx)) {
      x_10771 = kk_nagare_core_types__new_PDone(_ctx); /*nagare/core/types/pull<string,1328>*/
    }
    else {
      kk_std_core_types__cctx _x_x1305 = kk_cctx_empty(kk_context()); /*ctx<0>*/
      x_10771 = kk_nagare_io_file__trmc_unroll_decodeUtf8Pull_10001(step, kk_std_core_types__new_Nil(_ctx), _x_x1305, _ctx); /*nagare/core/types/pull<string,1328>*/
    }
    if (kk_yielding(kk_context())) {
      kk_nagare_core_types__pull_drop(x_10771, _ctx);
      kk_box_t _x_x1306 = kk_std_core_hnd_yield_extend(kk_nagare_io_file_new_decodeUtf8_fun1307(_ctx), _ctx); /*10001*/
      return kk_nagare_core_types__nstream_unbox(_x_x1306, KK_OWNED, _ctx);
    }
    {
      return kk_nagare_core_types__new_Stream(x_10771, _ctx);
    }
  }
}
 
// monadic lift


// lift anonymous function
struct kk_nagare_io_file__mlift_readPull_10666_fun1316__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_io_file__mlift_readPull_10666_fun1316(kk_function_t _fself, kk_box_t _b_x319, kk_box_t _b_x320, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__new_mlift_readPull_10666_fun1316(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file__mlift_readPull_10666_fun1316, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_io_file__mlift_readPull_10666_fun1316(kk_function_t _fself, kk_box_t _b_x319, kk_box_t _b_x320, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_nagare_core_types__pull _x_x1317;
  kk_nagare_io_file__effect__read_handle _x_x1318 = kk_nagare_io_file__effect__read_handle_unbox(_b_x319, KK_OWNED, _ctx); /*nagare/io/file_effect/read-handle*/
  kk_integer_t _x_x1319 = kk_integer_unbox(_b_x320, _ctx); /*int*/
  _x_x1317 = kk_nagare_io_file_readPull(_x_x1318, _x_x1319, _ctx); /*nagare/core/types/pull<string,<nagare/io/file_effect/fileRead|io>>*/
  return kk_nagare_core_types__pull_box(_x_x1317, _ctx);
}

kk_nagare_core_types__pull kk_nagare_io_file__mlift_readPull_10666(kk_integer_t chunkSize, kk_nagare_io_file__effect__read_handle h, kk_string_t chunk, kk_context_t* _ctx) { /* (chunkSize : int, h : nagare/io/file_effect/read-handle, chunk : string) -> <nagare/io/file_effect/fileRead,div,alloc<global>,console/console,exn,fsys,ndet,net,read<global>,ui,write<global>> nagare/core/types/pull<string,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileRead,fsys,ndet,net,read<global>,ui,write<global>>> */ 
  bool _match_x1044;
  kk_string_t _x_x1309 = kk_string_dup(chunk, _ctx); /*string*/
  kk_string_t _x_x1310 = kk_string_empty(); /*string*/
  _match_x1044 = kk_string_is_eq(_x_x1309,_x_x1310,kk_context()); /*bool*/
  if (_match_x1044) {
    kk_integer_drop(chunkSize, _ctx);
    kk_string_drop(chunk, _ctx);
    return kk_nagare_core_types__new_PDone(_ctx);
  }
  {
    kk_nagare_core_types__chunk _x_x1312;
    kk_std_core_types__list _x_x1313 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_string_box(chunk), kk_std_core_types__new_Nil(_ctx), _ctx); /*list<10021>*/
    _x_x1312 = kk_nagare_core_types__new_Chunk(_x_x1313, _ctx); /*nagare/core/types/chunk<4>*/
    kk_nagare_core_types__pull _x_x1314;
    kk_box_t _x_x1315 = kk_std_core_hnd__open_none2(kk_nagare_io_file__new_mlift_readPull_10666_fun1316(_ctx), kk_nagare_io_file__effect__read_handle_box(h, _ctx), kk_integer_box(chunkSize, _ctx), _ctx); /*10002*/
    _x_x1314 = kk_nagare_core_types__pull_unbox(_x_x1315, KK_OWNED, _ctx); /*nagare/core/types/pull<string,<nagare/io/file_effect/fileRead|io>>*/
    return kk_nagare_core_types__new_POutput(kk_reuse_null, 0, _x_x1312, _x_x1314, _ctx);
  }
}
 
// Loop reading chunks from an open read-handle until EOF.


// lift anonymous function
struct kk_nagare_io_file_readPull_fun1320__t {
  struct kk_function_s _base;
  kk_integer_t chunkSize_0;
  kk_nagare_io_file__effect__read_handle h_0;
};
static kk_nagare_core_types__pull kk_nagare_io_file_readPull_fun1320(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_readPull_fun1320(kk_integer_t chunkSize_0, kk_nagare_io_file__effect__read_handle h_0, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readPull_fun1320__t* _self = kk_function_alloc_as(struct kk_nagare_io_file_readPull_fun1320__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file_readPull_fun1320, kk_context());
  _self->chunkSize_0 = chunkSize_0;
  _self->h_0 = h_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_io_file_readPull_fun1326__t {
  struct kk_function_s _base;
  kk_ssize_t i_10779;
};
static kk_box_t kk_nagare_io_file_readPull_fun1326(kk_function_t _fself, kk_function_t _b_x341, kk_box_t _b_x342, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_readPull_fun1326(kk_ssize_t i_10779, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readPull_fun1326__t* _self = kk_function_alloc_as(struct kk_nagare_io_file_readPull_fun1326__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file_readPull_fun1326, kk_context());
  _self->i_10779 = i_10779;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file_readPull_fun1326(kk_function_t _fself, kk_function_t _b_x341, kk_box_t _b_x342, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readPull_fun1326__t* _self = kk_function_as(struct kk_nagare_io_file_readPull_fun1326__t*, _fself, _ctx);
  kk_ssize_t i_10779 = _self->i_10779; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_10779, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_10779, _b_x341, _b_x342, _ctx);
}


// lift anonymous function
struct kk_nagare_io_file_readPull_fun1328__t {
  struct kk_function_s _base;
  kk_integer_t chunkSize_0;
  kk_nagare_io_file__effect__read_handle h_0;
};
static kk_box_t kk_nagare_io_file_readPull_fun1328(kk_function_t _fself, kk_box_t _b_x351, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_readPull_fun1328(kk_integer_t chunkSize_0, kk_nagare_io_file__effect__read_handle h_0, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readPull_fun1328__t* _self = kk_function_alloc_as(struct kk_nagare_io_file_readPull_fun1328__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file_readPull_fun1328, kk_context());
  _self->chunkSize_0 = chunkSize_0;
  _self->h_0 = h_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file_readPull_fun1328(kk_function_t _fself, kk_box_t _b_x351, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readPull_fun1328__t* _self = kk_function_as(struct kk_nagare_io_file_readPull_fun1328__t*, _fself, _ctx);
  kk_integer_t chunkSize_0 = _self->chunkSize_0; /* int */
  kk_nagare_io_file__effect__read_handle h_0 = _self->h_0; /* nagare/io/file_effect/read-handle */
  kk_drop_match(_self, {kk_integer_dup(chunkSize_0, _ctx);kk_nagare_io_file__effect__read_handle_dup(h_0, _ctx);}, {}, _ctx)
  kk_string_t chunk_0_354 = kk_string_unbox(_b_x351); /*string*/;
  kk_nagare_core_types__pull _x_x1329 = kk_nagare_io_file__mlift_readPull_10666(chunkSize_0, h_0, chunk_0_354, _ctx); /*nagare/core/types/pull<string,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileRead,fsys,ndet,net,read<global>,ui,write<global>>>*/
  return kk_nagare_core_types__pull_box(_x_x1329, _ctx);
}
static kk_nagare_core_types__pull kk_nagare_io_file_readPull_fun1320(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readPull_fun1320__t* _self = kk_function_as(struct kk_nagare_io_file_readPull_fun1320__t*, _fself, _ctx);
  kk_integer_t chunkSize_0 = _self->chunkSize_0; /* int */
  kk_nagare_io_file__effect__read_handle h_0 = _self->h_0; /* nagare/io/file_effect/read-handle */
  kk_drop_match(_self, {kk_integer_dup(chunkSize_0, _ctx);kk_nagare_io_file__effect__read_handle_dup(h_0, _ctx);}, {}, _ctx)
  kk_ssize_t i_10779 = (KK_IZ(1)); /*hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_10779,kk_context()); /*hnd/evv<<nagare/io/file_effect/fileRead,div,alloc<global>,console/console,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_std_core_hnd__ev evx_10783 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<nagare/io/file_effect/fileRead>*/;
  kk_string_t y;
  kk_box_t _x_x1321;
  {
    struct kk_std_core_hnd_Ev* _con_x1322 = kk_std_core_hnd__as_Ev(evx_10783, _ctx);
    kk_box_t _box_x326 = _con_x1322->hnd;
    int32_t m = _con_x1322->marker;
    kk_nagare_io_file__effect__fileRead h_1 = kk_nagare_io_file__effect__fileRead_unbox(_box_x326, KK_BORROWED, _ctx);
    kk_nagare_io_file__effect__fileRead_dup(h_1, _ctx);
    kk_std_core_hnd__clause2 _match_x1042;
    kk_std_core_hnd__clause2 _brw_x1043 = kk_nagare_io_file__effect_readChunk_fs__select(h_1, _ctx); /*hnd/clause2<nagare/io/file_effect/read-handle,int,string,nagare/io/file_effect/fileRead,906,907>*/;
    kk_datatype_ptr_dropn(h_1, (KK_I32(6)), _ctx);
    _match_x1042 = _brw_x1043; /*hnd/clause2<nagare/io/file_effect/read-handle,int,string,nagare/io/file_effect/fileRead,906,907>*/
    {
      kk_function_t _fun_unbox_x331 = _match_x1042.clause;
      kk_box_t _x_x1323;
      kk_integer_t _x_x1324 = kk_integer_dup(chunkSize_0, _ctx); /*int*/
      _x_x1323 = kk_integer_box(_x_x1324, _ctx); /*10015*/
      _x_x1321 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_box_t, kk_context_t*), _fun_unbox_x331, (_fun_unbox_x331, m, evx_10783, kk_nagare_io_file__effect__read_handle_box(h_0, _ctx), _x_x1323, _ctx), _ctx); /*10016*/
    }
  }
  y = kk_string_unbox(_x_x1321); /*string*/
  kk_evv_set(w,kk_context());
  kk_string_t x_10777;
  if (kk_yielding(kk_context())) {
    kk_string_drop(y, _ctx);
    kk_box_t _x_x1325 = kk_std_core_hnd_yield_cont(kk_nagare_io_file_new_readPull_fun1326(i_10779, _ctx), _ctx); /*10002*/
    x_10777 = kk_string_unbox(_x_x1325); /*string*/
  }
  else {
    x_10777 = y; /*string*/
  }
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_10777, _ctx);
    kk_box_t _x_x1327 = kk_std_core_hnd_yield_extend(kk_nagare_io_file_new_readPull_fun1328(chunkSize_0, h_0, _ctx), _ctx); /*10001*/
    return kk_nagare_core_types__pull_unbox(_x_x1327, KK_OWNED, _ctx);
  }
  {
    return kk_nagare_io_file__mlift_readPull_10666(chunkSize_0, h_0, x_10777, _ctx);
  }
}

kk_nagare_core_types__pull kk_nagare_io_file_readPull(kk_nagare_io_file__effect__read_handle h_0, kk_integer_t chunkSize_0, kk_context_t* _ctx) { /* (h : nagare/io/file_effect/read-handle, chunkSize : int) -> div nagare/core/types/pull<string,<nagare/io/file_effect/fileRead|io>> */ 
  return kk_nagare_core_types__new_PEval(kk_reuse_null, 0, kk_nagare_io_file_new_readPull_fun1320(chunkSize_0, h_0, _ctx), _ctx);
}
 
// Split a string by newlines, returning (complete-lines, leftover).

kk_std_core_types__tuple2 kk_nagare_io_file_splitByNewline(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> (list<string>, string) */ 
  kk_vector_t v_10019;
  kk_string_t _x_x1330;
  kk_define_string_literal(static, _s_x1331, 1, "\n", _ctx)
  _x_x1330 = kk_string_dup(_s_x1331, _ctx); /*string*/
  v_10019 = kk_string_splitv(s,_x_x1330,kk_context()); /*vector<string>*/
  kk_std_core_types__list parts = kk_std_core_vector_vlist(v_10019, kk_std_core_types__new_None(_ctx), _ctx); /*list<string>*/;
  if (kk_std_core_types__is_Nil(parts, _ctx)) {
    kk_box_t _x_x1332;
    kk_string_t _x_x1333 = kk_string_empty(); /*string*/
    _x_x1332 = kk_string_box(_x_x1333); /*10038*/
    return kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx), _x_x1332, _ctx);
  }
  {
    struct kk_std_core_types_Cons* _con_x1335 = kk_std_core_types__as_Cons(parts, _ctx);
    kk_box_t _box_x357 = _con_x1335->head;
    kk_std_core_types__list _pat_1 = _con_x1335->tail;
    if (kk_std_core_types__is_Nil(_pat_1, _ctx)) {
      kk_string_t single = kk_string_unbox(_box_x357);
      if kk_likely(kk_datatype_ptr_is_unique(parts, _ctx)) {
        kk_datatype_ptr_free(parts, _ctx);
      }
      else {
        kk_string_dup(single, _ctx);
        kk_datatype_ptr_decref(parts, _ctx);
      }
      return kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx), kk_string_box(single), _ctx);
    }
  }
  {
    kk_std_core_types__list init;
    kk_std_core_types__list _x_x1336 = kk_std_core_types__list_dup(parts, _ctx); /*list<string>*/
    init = kk_std_core_list_init(_x_x1336, _ctx); /*list<string>*/
    kk_std_core_types__maybe m_10019 = kk_std_core_list_last(parts, _ctx); /*maybe<string>*/;
    kk_box_t _x_x1337;
    kk_string_t _x_x1338;
    if (kk_std_core_types__is_Nothing(m_10019, _ctx)) {
      _x_x1338 = kk_string_empty(); /*string*/
    }
    else {
      kk_box_t _box_x360 = m_10019._cons.Just.value;
      kk_string_t x = kk_string_unbox(_box_x360);
      kk_string_dup(x, _ctx);
      kk_std_core_types__maybe_drop(m_10019, _ctx);
      _x_x1338 = x; /*string*/
    }
    _x_x1337 = kk_string_box(_x_x1338); /*10038*/
    return kk_std_core_types__new_Tuple2(kk_std_core_types__list_box(init, _ctx), _x_x1337, _ctx);
  }
}
 
// monadic lift

kk_nagare_core_types__pull kk_nagare_io_file__mlift_trmc_unroll_splitLinesPull_10002_10667(kk_string_t buffer, kk_nagare_core_types__pull _y_x10471, kk_context_t* _ctx) { /* forall<e> (buffer : string, nagare/core/types/pull<string,e>) -> e nagare/core/types/pull<string,e> */ 
  return kk_nagare_io_file__unroll_splitLinesPull_10002(_y_x10471, buffer, _ctx);
}
 
// Build a pull that splits incoming string chunks into lines.


// lift anonymous function
struct kk_nagare_io_file__trmc_unroll_splitLinesPull_10002_fun1368__t {
  struct kk_function_s _base;
  kk_string_t buffer_0;
  kk_function_t next;
};
static kk_nagare_core_types__pull kk_nagare_io_file__trmc_unroll_splitLinesPull_10002_fun1368(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__new_trmc_unroll_splitLinesPull_10002_fun1368(kk_string_t buffer_0, kk_function_t next, kk_context_t* _ctx) {
  struct kk_nagare_io_file__trmc_unroll_splitLinesPull_10002_fun1368__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__trmc_unroll_splitLinesPull_10002_fun1368__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__trmc_unroll_splitLinesPull_10002_fun1368, kk_context());
  _self->buffer_0 = buffer_0;
  _self->next = next;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_io_file__trmc_unroll_splitLinesPull_10002_fun1370__t {
  struct kk_function_s _base;
  kk_string_t buffer_0;
};
static kk_box_t kk_nagare_io_file__trmc_unroll_splitLinesPull_10002_fun1370(kk_function_t _fself, kk_box_t _b_x387, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__new_trmc_unroll_splitLinesPull_10002_fun1370(kk_string_t buffer_0, kk_context_t* _ctx) {
  struct kk_nagare_io_file__trmc_unroll_splitLinesPull_10002_fun1370__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__trmc_unroll_splitLinesPull_10002_fun1370__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__trmc_unroll_splitLinesPull_10002_fun1370, kk_context());
  _self->buffer_0 = buffer_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file__trmc_unroll_splitLinesPull_10002_fun1370(kk_function_t _fself, kk_box_t _b_x387, kk_context_t* _ctx) {
  struct kk_nagare_io_file__trmc_unroll_splitLinesPull_10002_fun1370__t* _self = kk_function_as(struct kk_nagare_io_file__trmc_unroll_splitLinesPull_10002_fun1370__t*, _fself, _ctx);
  kk_string_t buffer_0 = _self->buffer_0; /* string */
  kk_drop_match(_self, {kk_string_dup(buffer_0, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull _y_x10471_0_417 = kk_nagare_core_types__pull_unbox(_b_x387, KK_OWNED, _ctx); /*nagare/core/types/pull<string,1714>*/;
  kk_nagare_core_types__pull _x_x1371 = kk_nagare_io_file__mlift_trmc_unroll_splitLinesPull_10002_10667(buffer_0, _y_x10471_0_417, _ctx); /*nagare/core/types/pull<string,1714>*/
  return kk_nagare_core_types__pull_box(_x_x1371, _ctx);
}
static kk_nagare_core_types__pull kk_nagare_io_file__trmc_unroll_splitLinesPull_10002_fun1368(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_io_file__trmc_unroll_splitLinesPull_10002_fun1368__t* _self = kk_function_as(struct kk_nagare_io_file__trmc_unroll_splitLinesPull_10002_fun1368__t*, _fself, _ctx);
  kk_string_t buffer_0 = _self->buffer_0; /* string */
  kk_function_t next = _self->next; /* () -> 1714 nagare/core/types/pull<string,1714> */
  kk_drop_match(_self, {kk_string_dup(buffer_0, _ctx);kk_function_dup(next, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull x_1_10787 = kk_function_call(kk_nagare_core_types__pull, (kk_function_t, kk_context_t*), next, (next, _ctx), _ctx); /*nagare/core/types/pull<string,1714>*/;
  if (kk_yielding(kk_context())) {
    kk_nagare_core_types__pull_drop(x_1_10787, _ctx);
    kk_box_t _x_x1369 = kk_std_core_hnd_yield_extend(kk_nagare_io_file__new_trmc_unroll_splitLinesPull_10002_fun1370(buffer_0, _ctx), _ctx); /*10001*/
    return kk_nagare_core_types__pull_unbox(_x_x1369, KK_OWNED, _ctx);
  }
  {
    return kk_nagare_io_file__mlift_trmc_unroll_splitLinesPull_10002_10667(buffer_0, x_1_10787, _ctx);
  }
}

kk_nagare_core_types__pull kk_nagare_io_file__trmc_unroll_splitLinesPull_10002(kk_nagare_core_types__pull source, kk_string_t buffer_0, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* forall<e> (source : nagare/core/types/pull<string,e>, buffer : string, ctx<nagare/core/types/pull<string,e>>) -> nagare/core/types/pull<string,e> */ 
  kk__tailcall: ;
  if (kk_nagare_core_types__is_PDone(source, _ctx)) {
    kk_box_t _x_x1340;
    bool _match_x1039;
    kk_string_t _x_x1341 = kk_string_dup(buffer_0, _ctx); /*string*/
    kk_string_t _x_x1342 = kk_string_empty(); /*string*/
    _match_x1039 = kk_string_is_eq(_x_x1341,_x_x1342,kk_context()); /*bool*/
    if (_match_x1039) {
      kk_string_drop(buffer_0, _ctx);
      _x_x1340 = kk_cctx_apply_linear(_acc,(kk_nagare_core_types__pull_box(kk_nagare_core_types__new_PDone(_ctx), _ctx)),kk_context()); /*-1*/
    }
    else {
      kk_box_t _x_x1344;
      kk_nagare_core_types__pull _x_x1345;
      kk_string_t _b_x371_400 = buffer_0; /*string*/;
      kk_std_core_types__list _b_x372_401 = kk_std_core_types__new_Nil(_ctx); /*list<string>*/;
      kk_nagare_core_types__chunk _x_x1346;
      kk_std_core_types__list _x_x1347 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_string_box(_b_x371_400), _b_x372_401, _ctx); /*list<10021>*/
      _x_x1346 = kk_nagare_core_types__new_Chunk(_x_x1347, _ctx); /*nagare/core/types/chunk<4>*/
      _x_x1345 = kk_nagare_core_types__new_POutput(kk_reuse_null, 0, _x_x1346, kk_nagare_core_types__new_PDone(_ctx), _ctx); /*nagare/core/types/pull<19,20>*/
      _x_x1344 = kk_nagare_core_types__pull_box(_x_x1345, _ctx); /*-1*/
      _x_x1340 = kk_cctx_apply_linear(_acc,_x_x1344,kk_context()); /*-1*/
    }
    return kk_nagare_core_types__pull_unbox(_x_x1340, KK_OWNED, _ctx);
  }
  if (kk_nagare_core_types__is_POutput(source, _ctx)) {
    struct kk_nagare_core_types_POutput* _con_x1348 = kk_nagare_core_types__as_POutput(source, _ctx);
    kk_nagare_core_types__chunk out = _con_x1348->out;
    kk_nagare_core_types__pull tail = _con_x1348->tail;
    kk_reuse_t _ru_x1101 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(source, _ctx)) {
      _ru_x1101 = (kk_datatype_ptr_reuse(source, _ctx));
    }
    else {
      kk_nagare_core_types__chunk_dup(out, _ctx);
      kk_nagare_core_types__pull_dup(tail, _ctx);
      kk_datatype_ptr_decref(source, _ctx);
    }
    {
      kk_std_core_types__list values = out.values;
      kk_string_t combined;
      kk_string_t _x_x1349;
      if (kk_std_core_types__is_Nil(values, _ctx)) {
        _x_x1349 = kk_string_empty(); /*string*/
        goto _match_x1350;
      }
      {
        struct kk_std_core_types_Cons* _con_x1352 = kk_std_core_types__as_Cons(values, _ctx);
        kk_box_t _box_x375 = _con_x1352->head;
        kk_std_core_types__list _pat_1_0 = _con_x1352->tail;
        if (kk_std_core_types__is_Nil(_pat_1_0, _ctx)) {
          kk_string_t x = kk_string_unbox(_box_x375);
          if kk_likely(kk_datatype_ptr_is_unique(values, _ctx)) {
            kk_datatype_ptr_free(values, _ctx);
          }
          else {
            kk_string_dup(x, _ctx);
            kk_datatype_ptr_decref(values, _ctx);
          }
          _x_x1349 = x; /*string*/
          goto _match_x1350;
        }
      }
      if (kk_std_core_types__is_Cons(values, _ctx)) {
        struct kk_std_core_types_Cons* _con_x1353 = kk_std_core_types__as_Cons(values, _ctx);
        kk_box_t _box_x376 = _con_x1353->head;
        kk_std_core_types__list _pat_3_0 = _con_x1353->tail;
        if (kk_std_core_types__is_Cons(_pat_3_0, _ctx)) {
          struct kk_std_core_types_Cons* _con_x1354 = kk_std_core_types__as_Cons(_pat_3_0, _ctx);
          kk_box_t _box_x377 = _con_x1354->head;
          kk_std_core_types__list _pat_4_0 = _con_x1354->tail;
          if (kk_std_core_types__is_Nil(_pat_4_0, _ctx)) {
            kk_string_t _x_x1355 = kk_string_empty(); /*string*/
            kk_string_t _x_x1357 = kk_string_empty(); /*string*/
            if (kk_string_is_eq(_x_x1355,_x_x1357,kk_context())) {
              kk_string_t x_0 = kk_string_unbox(_box_x376);
              kk_string_t y = kk_string_unbox(_box_x377);
              if kk_likely(kk_datatype_ptr_is_unique(values, _ctx)) {
                if kk_likely(kk_datatype_ptr_is_unique(_pat_3_0, _ctx)) {
                  kk_datatype_ptr_free(_pat_3_0, _ctx);
                }
                else {
                  kk_string_dup(y, _ctx);
                  kk_datatype_ptr_decref(_pat_3_0, _ctx);
                }
                kk_datatype_ptr_free(values, _ctx);
              }
              else {
                kk_string_dup(x_0, _ctx);
                kk_string_dup(y, _ctx);
                kk_datatype_ptr_decref(values, _ctx);
              }
              _x_x1349 = kk_std_core_types__lp__plus__plus__rp_(x_0, y, _ctx); /*string*/
              goto _match_x1350;
            }
          }
        }
      }
      {
        kk_vector_t _x_x1359 = kk_std_core_vector_unvlist(values, _ctx); /*vector<10000>*/
        kk_string_t _x_x1360 = kk_string_empty(); /*string*/
        _x_x1349 = kk_string_join_with(_x_x1359,_x_x1360,kk_context()); /*string*/
      }
      _match_x1350: ;
      combined = kk_std_core_types__lp__plus__plus__rp_(buffer_0, _x_x1349, _ctx); /*string*/
      kk_std_core_types__tuple2 _match_x1038 = kk_nagare_io_file_splitByNewline(combined, _ctx); /*(list<string>, string)*/;
      {
        kk_box_t _box_x378 = _match_x1038.fst;
        kk_box_t _box_x379 = _match_x1038.snd;
        kk_std_core_types__list lines = kk_std_core_types__list_unbox(_box_x378, KK_BORROWED, _ctx);
        kk_string_t leftover = kk_string_unbox(_box_x379);
        kk_string_dup(leftover, _ctx);
        kk_std_core_types__list_dup(lines, _ctx);
        kk_std_core_types__tuple2_drop(_match_x1038, _ctx);
        if (kk_std_core_types__is_Nil(lines, _ctx)) {
          kk_reuse_drop(_ru_x1101,kk_context());
          { // tailcall
            source = tail;
            buffer_0 = leftover;
            goto kk__tailcall;
          }
        }
        {
          kk_nagare_core_types__pull _trmc_x10406 = kk_datatype_null(); /*nagare/core/types/pull<string,1714>*/;
          kk_nagare_core_types__pull _trmc_x10407;
          kk_nagare_core_types__chunk _x_x1362 = kk_nagare_core_types__new_Chunk(lines, _ctx); /*nagare/core/types/chunk<4>*/
          _trmc_x10407 = kk_nagare_core_types__new_POutput(_ru_x1101, 0, _x_x1362, _trmc_x10406, _ctx); /*nagare/core/types/pull<string,1714>*/
          kk_field_addr_t _b_x385_404 = kk_field_addr_create(&kk_nagare_core_types__as_POutput(_trmc_x10407, _ctx)->tail, _ctx); /*@field-addr<nagare/core/types/pull<string,1714>>*/;
          { // tailcall
            kk_std_core_types__cctx _x_x1363 = kk_cctx_extend_linear(_acc,(kk_nagare_core_types__pull_box(_trmc_x10407, _ctx)),_b_x385_404,kk_context()); /*ctx<0>*/
            source = tail;
            buffer_0 = leftover;
            _acc = _x_x1363;
            goto kk__tailcall;
          }
        }
      }
    }
  }
  if (kk_nagare_core_types__is_PEval(source, _ctx)) {
    struct kk_nagare_core_types_PEval* _con_x1364 = kk_nagare_core_types__as_PEval(source, _ctx);
    kk_function_t next = _con_x1364->next;
    kk_reuse_t _ru_x1105 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(source, _ctx)) {
      _ru_x1105 = (kk_datatype_ptr_reuse(source, _ctx));
    }
    else {
      kk_function_dup(next, _ctx);
      kk_datatype_ptr_decref(source, _ctx);
    }
    kk_box_t _x_x1365;
    kk_box_t _x_x1366;
    kk_nagare_core_types__pull _x_x1367 = kk_nagare_core_types__new_PEval(_ru_x1105, 0, kk_nagare_io_file__new_trmc_unroll_splitLinesPull_10002_fun1368(buffer_0, next, _ctx), _ctx); /*nagare/core/types/pull<19,20>*/
    _x_x1366 = kk_nagare_core_types__pull_box(_x_x1367, _ctx); /*-1*/
    _x_x1365 = kk_cctx_apply_linear(_acc,_x_x1366,kk_context()); /*-1*/
    return kk_nagare_core_types__pull_unbox(_x_x1365, KK_OWNED, _ctx);
  }
  {
    struct kk_nagare_core_types_PAcquire* _con_x1372 = kk_nagare_core_types__as_PAcquire(source, _ctx);
    kk_function_t acquire = _con_x1372->acquire;
    kk_function_t release = _con_x1372->release;
    kk_nagare_core_types__pull tail_0 = _con_x1372->tail;
    kk_reuse_t _ru_x1106 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(source, _ctx)) {
      _ru_x1106 = (kk_datatype_ptr_reuse(source, _ctx));
    }
    else {
      kk_function_dup(acquire, _ctx);
      kk_function_dup(release, _ctx);
      kk_nagare_core_types__pull_dup(tail_0, _ctx);
      kk_datatype_ptr_decref(source, _ctx);
    }
    kk_nagare_core_types__pull _trmc_x10408 = kk_datatype_null(); /*nagare/core/types/pull<string,1714>*/;
    kk_nagare_core_types__pull _trmc_x10409 = kk_nagare_core_types__new_PAcquire(_ru_x1106, 0, acquire, release, _trmc_x10408, _ctx); /*nagare/core/types/pull<string,1714>*/;
    kk_field_addr_t _b_x395_413 = kk_field_addr_create(&kk_nagare_core_types__as_PAcquire(_trmc_x10409, _ctx)->tail, _ctx); /*@field-addr<nagare/core/types/pull<string,1714>>*/;
    { // tailcall
      kk_std_core_types__cctx _x_x1373 = kk_cctx_extend_linear(_acc,(kk_nagare_core_types__pull_box(_trmc_x10409, _ctx)),_b_x395_413,kk_context()); /*ctx<0>*/
      source = tail_0;
      _acc = _x_x1373;
      goto kk__tailcall;
    }
  }
}
 
// Build a pull that splits incoming string chunks into lines.

kk_nagare_core_types__pull kk_nagare_io_file__unroll_splitLinesPull_10002(kk_nagare_core_types__pull source_0, kk_string_t buffer_1, kk_context_t* _ctx) { /* forall<e> (source : nagare/core/types/pull<string,e>, buffer : string) -> nagare/core/types/pull<string,e> */ 
  kk_std_core_types__cctx _x_x1374 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_nagare_io_file__trmc_unroll_splitLinesPull_10002(source_0, buffer_1, _x_x1374, _ctx);
}
 
// monadic lift

kk_std_core_types__list kk_nagare_io_file__mlift_readAllChunks_10668(kk_std_core_types__list acc, kk_integer_t chunkSize, kk_nagare_io_file__effect__read_handle h, kk_string_t chunk, kk_context_t* _ctx) { /* (acc : list<string>, chunkSize : int, h : nagare/io/file_effect/read-handle, chunk : string) -> <nagare/io/file_effect/fileRead,alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> list<string> */ 
  bool _match_x1035;
  kk_string_t _x_x1381 = kk_string_dup(chunk, _ctx); /*string*/
  kk_string_t _x_x1382 = kk_string_empty(); /*string*/
  _match_x1035 = kk_string_is_eq(_x_x1381,_x_x1382,kk_context()); /*bool*/
  if (_match_x1035) {
    kk_integer_drop(chunkSize, _ctx);
    kk_string_drop(chunk, _ctx);
    kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileRead,fsys,ndet,net,read<global>,ui,write<global>>>*/;
    kk_std_core_types__list x;
    if (kk_std_core_types__is_Nil(acc, _ctx)) {
      x = kk_std_core_types__new_Nil(_ctx); /*list<string>*/
    }
    else {
      x = kk_std_core_list__unroll_reverse_acc_10003(kk_std_core_types__new_Nil(_ctx), acc, _ctx); /*list<string>*/
    }
    kk_unit_t keep = kk_Unit;
    kk_evv_set(w,kk_context());
    return x;
  }
  {
    kk_std_core_types__list _x_x1384 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_string_box(chunk), acc, _ctx); /*list<10021>*/
    return kk_nagare_io_file_readAllChunks(h, chunkSize, _x_x1384, _ctx);
  }
}
 
// Helper: drain the read-handle into a list of chunks.


// lift anonymous function
struct kk_nagare_io_file_readAllChunks_fun1390__t {
  struct kk_function_s _base;
  kk_ssize_t i_10796;
};
static kk_box_t kk_nagare_io_file_readAllChunks_fun1390(kk_function_t _fself, kk_function_t _b_x441, kk_box_t _b_x442, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_readAllChunks_fun1390(kk_ssize_t i_10796, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readAllChunks_fun1390__t* _self = kk_function_alloc_as(struct kk_nagare_io_file_readAllChunks_fun1390__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file_readAllChunks_fun1390, kk_context());
  _self->i_10796 = i_10796;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file_readAllChunks_fun1390(kk_function_t _fself, kk_function_t _b_x441, kk_box_t _b_x442, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readAllChunks_fun1390__t* _self = kk_function_as(struct kk_nagare_io_file_readAllChunks_fun1390__t*, _fself, _ctx);
  kk_ssize_t i_10796 = _self->i_10796; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_10796, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_10796, _b_x441, _b_x442, _ctx);
}


// lift anonymous function
struct kk_nagare_io_file_readAllChunks_fun1392__t {
  struct kk_function_s _base;
  kk_std_core_types__list acc_0;
  kk_integer_t chunkSize_0;
  kk_nagare_io_file__effect__read_handle h_0;
};
static kk_box_t kk_nagare_io_file_readAllChunks_fun1392(kk_function_t _fself, kk_box_t _b_x451, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_readAllChunks_fun1392(kk_std_core_types__list acc_0, kk_integer_t chunkSize_0, kk_nagare_io_file__effect__read_handle h_0, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readAllChunks_fun1392__t* _self = kk_function_alloc_as(struct kk_nagare_io_file_readAllChunks_fun1392__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file_readAllChunks_fun1392, kk_context());
  _self->acc_0 = acc_0;
  _self->chunkSize_0 = chunkSize_0;
  _self->h_0 = h_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file_readAllChunks_fun1392(kk_function_t _fself, kk_box_t _b_x451, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readAllChunks_fun1392__t* _self = kk_function_as(struct kk_nagare_io_file_readAllChunks_fun1392__t*, _fself, _ctx);
  kk_std_core_types__list acc_0 = _self->acc_0; /* list<string> */
  kk_integer_t chunkSize_0 = _self->chunkSize_0; /* int */
  kk_nagare_io_file__effect__read_handle h_0 = _self->h_0; /* nagare/io/file_effect/read-handle */
  kk_drop_match(_self, {kk_std_core_types__list_dup(acc_0, _ctx);kk_integer_dup(chunkSize_0, _ctx);kk_nagare_io_file__effect__read_handle_dup(h_0, _ctx);}, {}, _ctx)
  kk_string_t chunk_0_458 = kk_string_unbox(_b_x451); /*string*/;
  kk_std_core_types__list _x_x1393 = kk_nagare_io_file__mlift_readAllChunks_10668(acc_0, chunkSize_0, h_0, chunk_0_458, _ctx); /*list<string>*/
  return kk_std_core_types__list_box(_x_x1393, _ctx);
}

kk_std_core_types__list kk_nagare_io_file_readAllChunks(kk_nagare_io_file__effect__read_handle h_0, kk_integer_t chunkSize_0, kk_std_core_types__list acc_0, kk_context_t* _ctx) { /* (h : nagare/io/file_effect/read-handle, chunkSize : int, acc : list<string>) -> <io,nagare/io/file_effect/fileRead> list<string> */ 
  kk__tailcall: ;
  kk_ssize_t i_10796 = (KK_IZ(1)); /*hnd/ev-index*/;
  kk_evv_t w_0 = kk_evv_swap_create1(i_10796,kk_context()); /*hnd/evv<<nagare/io/file_effect/fileRead,alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_std_core_hnd__ev evx_10800 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<nagare/io/file_effect/fileRead>*/;
  kk_string_t y;
  kk_box_t _x_x1385;
  {
    struct kk_std_core_hnd_Ev* _con_x1386 = kk_std_core_hnd__as_Ev(evx_10800, _ctx);
    kk_box_t _box_x426 = _con_x1386->hnd;
    int32_t m = _con_x1386->marker;
    kk_nagare_io_file__effect__fileRead h_1 = kk_nagare_io_file__effect__fileRead_unbox(_box_x426, KK_BORROWED, _ctx);
    kk_nagare_io_file__effect__fileRead_dup(h_1, _ctx);
    kk_std_core_hnd__clause2 _match_x1033;
    kk_std_core_hnd__clause2 _brw_x1034 = kk_nagare_io_file__effect_readChunk_fs__select(h_1, _ctx); /*hnd/clause2<nagare/io/file_effect/read-handle,int,string,nagare/io/file_effect/fileRead,906,907>*/;
    kk_datatype_ptr_dropn(h_1, (KK_I32(6)), _ctx);
    _match_x1033 = _brw_x1034; /*hnd/clause2<nagare/io/file_effect/read-handle,int,string,nagare/io/file_effect/fileRead,906,907>*/
    {
      kk_function_t _fun_unbox_x431 = _match_x1033.clause;
      kk_box_t _x_x1387;
      kk_integer_t _x_x1388 = kk_integer_dup(chunkSize_0, _ctx); /*int*/
      _x_x1387 = kk_integer_box(_x_x1388, _ctx); /*10015*/
      _x_x1385 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_box_t, kk_context_t*), _fun_unbox_x431, (_fun_unbox_x431, m, evx_10800, kk_nagare_io_file__effect__read_handle_box(h_0, _ctx), _x_x1387, _ctx), _ctx); /*10016*/
    }
  }
  y = kk_string_unbox(_x_x1385); /*string*/
  kk_evv_set(w_0,kk_context());
  kk_string_t x_0_10793;
  if (kk_yielding(kk_context())) {
    kk_string_drop(y, _ctx);
    kk_box_t _x_x1389 = kk_std_core_hnd_yield_cont(kk_nagare_io_file_new_readAllChunks_fun1390(i_10796, _ctx), _ctx); /*10002*/
    x_0_10793 = kk_string_unbox(_x_x1389); /*string*/
  }
  else {
    x_0_10793 = y; /*string*/
  }
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_0_10793, _ctx);
    kk_box_t _x_x1391 = kk_std_core_hnd_yield_extend(kk_nagare_io_file_new_readAllChunks_fun1392(acc_0, chunkSize_0, h_0, _ctx), _ctx); /*10001*/
    return kk_std_core_types__list_unbox(_x_x1391, KK_OWNED, _ctx);
  }
  {
    bool _match_x1031;
    kk_string_t _x_x1394 = kk_string_dup(x_0_10793, _ctx); /*string*/
    kk_string_t _x_x1395 = kk_string_empty(); /*string*/
    _match_x1031 = kk_string_is_eq(_x_x1394,_x_x1395,kk_context()); /*bool*/
    if (_match_x1031) {
      kk_string_drop(x_0_10793, _ctx);
      kk_integer_drop(chunkSize_0, _ctx);
      kk_evv_t w_1 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileRead,fsys,ndet,net,read<global>,ui,write<global>>>*/;
      kk_std_core_types__list x_2;
      if (kk_std_core_types__is_Nil(acc_0, _ctx)) {
        x_2 = kk_std_core_types__new_Nil(_ctx); /*list<string>*/
      }
      else {
        x_2 = kk_std_core_list__unroll_reverse_acc_10003(kk_std_core_types__new_Nil(_ctx), acc_0, _ctx); /*list<string>*/
      }
      kk_unit_t keep_0 = kk_Unit;
      kk_evv_set(w_1,kk_context());
      return x_2;
    }
    { // tailcall
      kk_std_core_types__list _x_x1397 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_string_box(x_0_10793), acc_0, _ctx); /*list<10021>*/
      acc_0 = _x_x1397;
      goto kk__tailcall;
    }
  }
}
 
// Read a file as a stream of string chunks.
// `with-read-file` owns open+close; `readChunk` operates on the open handle.


// lift anonymous function
struct kk_nagare_io_file_readAll_fun1400__t {
  struct kk_function_s _base;
  kk_std_core_types__optional chunkSize;
  kk_std_os_path__path filepath;
};
static kk_nagare_core_types__pull kk_nagare_io_file_readAll_fun1400(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_readAll_fun1400(kk_std_core_types__optional chunkSize, kk_std_os_path__path filepath, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readAll_fun1400__t* _self = kk_function_alloc_as(struct kk_nagare_io_file_readAll_fun1400__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file_readAll_fun1400, kk_context());
  _self->chunkSize = chunkSize;
  _self->filepath = filepath;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_io_file_readAll_fun1402__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_io_file_readAll_fun1402(kk_function_t _fself, kk_box_t _b_x461, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_readAll_fun1402(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file_readAll_fun1402, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_io_file_readAll_fun1402(kk_function_t _fself, kk_box_t _b_x461, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1403;
  kk_std_os_path__path _x_x1404 = kk_std_os_path__path_unbox(_b_x461, KK_OWNED, _ctx); /*std/os/path/path*/
  _x_x1403 = kk_std_os_path_string(_x_x1404, _ctx); /*string*/
  return kk_string_box(_x_x1403);
}


// lift anonymous function
struct kk_nagare_io_file_readAll_fun1406__t {
  struct kk_function_s _base;
  kk_std_core_types__optional chunkSize;
};
static kk_box_t kk_nagare_io_file_readAll_fun1406(kk_function_t _fself, kk_nagare_io_file__effect__read_handle _b_x467, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_readAll_fun1406(kk_std_core_types__optional chunkSize, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readAll_fun1406__t* _self = kk_function_alloc_as(struct kk_nagare_io_file_readAll_fun1406__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file_readAll_fun1406, kk_context());
  _self->chunkSize = chunkSize;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_io_file_readAll_fun1410__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_io_file_readAll_fun1410(kk_function_t _fself, kk_box_t _b_x464, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_readAll_fun1410(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file_readAll_fun1410, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_io_file_readAll_fun1410(kk_function_t _fself, kk_box_t _b_x464, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_nagare_core_types__pull _x_x1411;
  kk_std_core_types__list _x_x1412 = kk_std_core_types__list_unbox(_b_x464, KK_OWNED, _ctx); /*list<string>*/
  _x_x1411 = kk_nagare_io_file__mlift_readAll_10669(_x_x1412, _ctx); /*nagare/core/types/pull<string,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileRead,fsys,ndet,net,read<global>,ui,write<global>>>*/
  return kk_nagare_core_types__pull_box(_x_x1411, _ctx);
}
static kk_box_t kk_nagare_io_file_readAll_fun1406(kk_function_t _fself, kk_nagare_io_file__effect__read_handle _b_x467, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readAll_fun1406__t* _self = kk_function_as(struct kk_nagare_io_file_readAll_fun1406__t*, _fself, _ctx);
  kk_std_core_types__optional chunkSize = _self->chunkSize; /* ? int */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(chunkSize, _ctx);}, {}, _ctx)
  kk_nagare_io_file__effect__read_handle h_473 = _b_x467; /*nagare/io/file_effect/read-handle*/;
  kk_std_core_types__list x_10806;
  kk_integer_t _x_x1407;
  if (kk_std_core_types__is_Optional(chunkSize, _ctx)) {
    kk_box_t _box_x462 = chunkSize._cons._Optional.value;
    kk_integer_t _uniq_chunkSize_1768 = kk_integer_unbox(_box_x462, _ctx);
    kk_integer_dup(_uniq_chunkSize_1768, _ctx);
    kk_std_core_types__optional_drop(chunkSize, _ctx);
    _x_x1407 = _uniq_chunkSize_1768; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(chunkSize, _ctx);
    _x_x1407 = kk_integer_from_small(4096); /*int*/
  }
  x_10806 = kk_nagare_io_file_readAllChunks(h_473, _x_x1407, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<string>*/
  kk_nagare_core_types__pull _x_x1408;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_10806, _ctx);
    kk_box_t _x_x1409 = kk_std_core_hnd_yield_extend(kk_nagare_io_file_new_readAll_fun1410(_ctx), _ctx); /*10001*/
    _x_x1408 = kk_nagare_core_types__pull_unbox(_x_x1409, KK_OWNED, _ctx); /*nagare/core/types/pull<string,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileRead,fsys,ndet,net,read<global>,ui,write<global>>>*/
  }
  else {
    kk_nagare_core_types__chunk _x_x1413 = kk_nagare_core_types__new_Chunk(x_10806, _ctx); /*nagare/core/types/chunk<4>*/
    _x_x1408 = kk_nagare_core_types__new_POutput(kk_reuse_null, 0, _x_x1413, kk_nagare_core_types__new_PDone(_ctx), _ctx); /*nagare/core/types/pull<string,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileRead,fsys,ndet,net,read<global>,ui,write<global>>>*/
  }
  return kk_nagare_core_types__pull_box(_x_x1408, _ctx);
}
static kk_nagare_core_types__pull kk_nagare_io_file_readAll_fun1400(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readAll_fun1400__t* _self = kk_function_as(struct kk_nagare_io_file_readAll_fun1400__t*, _fself, _ctx);
  kk_std_core_types__optional chunkSize = _self->chunkSize; /* ? int */
  kk_std_os_path__path filepath = _self->filepath; /* std/os/path/path */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(chunkSize, _ctx);kk_std_os_path__path_dup(filepath, _ctx);}, {}, _ctx)
  kk_string_t _b_x465_468;
  kk_box_t _x_x1401 = kk_std_core_hnd__open_none1(kk_nagare_io_file_new_readAll_fun1402(_ctx), kk_std_os_path__path_box(filepath, _ctx), _ctx); /*10001*/
  _b_x465_468 = kk_string_unbox(_x_x1401); /*string*/
  kk_box_t _x_x1405 = kk_nagare_io_file__effect_with_read_file(_b_x465_468, kk_nagare_io_file_new_readAll_fun1406(chunkSize, _ctx), _ctx); /*2157*/
  return kk_nagare_core_types__pull_unbox(_x_x1405, KK_OWNED, _ctx);
}

kk_nagare_core_types__nstream kk_nagare_io_file_readAll(kk_std_os_path__path filepath, kk_std_core_types__optional chunkSize, kk_context_t* _ctx) { /* (filepath : std/os/path/path, chunkSize : ? int) -> nagare/io/file_effect/readStream<string> */ 
  kk_nagare_core_types__pull _x_x1399 = kk_nagare_core_types__new_PEval(kk_reuse_null, 0, kk_nagare_io_file_new_readAll_fun1400(chunkSize, filepath, _ctx), _ctx); /*nagare/core/types/pull<19,20>*/
  return kk_nagare_core_types__new_Stream(_x_x1399, _ctx);
}
 
// Split a stream of string chunks into a stream of lines.


// lift anonymous function
struct kk_nagare_io_file_splitLines_fun1427__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_io_file_splitLines_fun1427(kk_function_t _fself, kk_box_t _b_x479, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_splitLines_fun1427(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file_splitLines_fun1427, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_io_file_splitLines_fun1427(kk_function_t _fself, kk_box_t _b_x479, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_nagare_core_types__pull _c_x10482_481 = kk_nagare_core_types__pull_unbox(_b_x479, KK_OWNED, _ctx); /*nagare/core/types/pull<string,1875>*/;
  kk_nagare_core_types__nstream _x_x1428 = kk_nagare_core_types__new_Stream(_c_x10482_481, _ctx); /*nagare/core/types/nstream<27,28>*/
  return kk_nagare_core_types__nstream_box(_x_x1428, _ctx);
}

kk_nagare_core_types__nstream kk_nagare_io_file_splitLines(kk_nagare_core_types__nstream source, kk_context_t* _ctx) { /* forall<e> (source : nagare/core/types/nstream<string,e>) -> nagare/core/types/nstream<string,e> */ 
  {
    kk_nagare_core_types__pull step = source.step;
    kk_nagare_core_types__pull x_10808;
    if (kk_nagare_core_types__is_PDone(step, _ctx)) {
      bool _match_x1028;
      kk_string_t _x_x1414 = kk_string_empty(); /*string*/
      kk_string_t _x_x1416 = kk_string_empty(); /*string*/
      _match_x1028 = kk_string_is_eq(_x_x1414,_x_x1416,kk_context()); /*bool*/
      if (_match_x1028) {
        x_10808 = kk_nagare_core_types__new_PDone(_ctx); /*nagare/core/types/pull<string,1875>*/
      }
      else {
        kk_nagare_core_types__chunk _x_x1418;
        kk_std_core_types__list _x_x1419;
        kk_box_t _x_x1420;
        kk_string_t _x_x1421 = kk_string_empty(); /*string*/
        _x_x1420 = kk_string_box(_x_x1421); /*10021*/
        _x_x1419 = kk_std_core_types__new_Cons(kk_reuse_null, 0, _x_x1420, kk_std_core_types__new_Nil(_ctx), _ctx); /*list<10021>*/
        _x_x1418 = kk_nagare_core_types__new_Chunk(_x_x1419, _ctx); /*nagare/core/types/chunk<4>*/
        x_10808 = kk_nagare_core_types__new_POutput(kk_reuse_null, 0, _x_x1418, kk_nagare_core_types__new_PDone(_ctx), _ctx); /*nagare/core/types/pull<string,1875>*/
      }
    }
    else {
      kk_string_t _x_x1423 = kk_string_empty(); /*string*/
      kk_std_core_types__cctx _x_x1425 = kk_cctx_empty(kk_context()); /*ctx<0>*/
      x_10808 = kk_nagare_io_file__trmc_unroll_splitLinesPull_10002(step, _x_x1423, _x_x1425, _ctx); /*nagare/core/types/pull<string,1875>*/
    }
    if (kk_yielding(kk_context())) {
      kk_nagare_core_types__pull_drop(x_10808, _ctx);
      kk_box_t _x_x1426 = kk_std_core_hnd_yield_extend(kk_nagare_io_file_new_splitLines_fun1427(_ctx), _ctx); /*10001*/
      return kk_nagare_core_types__nstream_unbox(_x_x1426, KK_OWNED, _ctx);
    }
    {
      return kk_nagare_core_types__new_Stream(x_10808, _ctx);
    }
  }
}
 
// Read a file as a truly lazy stream of chunks: the handle is opened once,
// held by PAcquire for its lifetime, and closed by the interpreter when the
// stream finishes or is truncated by take/takeWhile. Only one chunk lives in
// memory at a time — this is the streaming-safe alternative to readAll.


// lift anonymous function
struct kk_nagare_io_file_readAllStreaming_fun1432__t {
  struct kk_function_s _base;
  kk_std_core_types__optional chunkSize;
  kk_std_os_path__path filepath;
};
static kk_nagare_core_types__pull kk_nagare_io_file_readAllStreaming_fun1432(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_readAllStreaming_fun1432(kk_std_core_types__optional chunkSize, kk_std_os_path__path filepath, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readAllStreaming_fun1432__t* _self = kk_function_alloc_as(struct kk_nagare_io_file_readAllStreaming_fun1432__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file_readAllStreaming_fun1432, kk_context());
  _self->chunkSize = chunkSize;
  _self->filepath = filepath;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_io_file_readAllStreaming_fun1434__t {
  struct kk_function_s _base;
  kk_std_os_path__path filepath;
  kk_ref_t hRef;
};
static kk_unit_t kk_nagare_io_file_readAllStreaming_fun1434(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_readAllStreaming_fun1434(kk_std_os_path__path filepath, kk_ref_t hRef, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readAllStreaming_fun1434__t* _self = kk_function_alloc_as(struct kk_nagare_io_file_readAllStreaming_fun1434__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file_readAllStreaming_fun1434, kk_context());
  _self->filepath = filepath;
  _self->hRef = hRef;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_io_file_readAllStreaming_fun1436__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_io_file_readAllStreaming_fun1436(kk_function_t _fself, kk_box_t _b_x492, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_readAllStreaming_fun1436(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file_readAllStreaming_fun1436, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_io_file_readAllStreaming_fun1436(kk_function_t _fself, kk_box_t _b_x492, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1437;
  kk_std_os_path__path _x_x1438 = kk_std_os_path__path_unbox(_b_x492, KK_OWNED, _ctx); /*std/os/path/path*/
  _x_x1437 = kk_std_os_path_string(_x_x1438, _ctx); /*string*/
  return kk_string_box(_x_x1437);
}


// lift anonymous function
struct kk_nagare_io_file_readAllStreaming_fun1442__t {
  struct kk_function_s _base;
  kk_ssize_t i_10816;
};
static kk_box_t kk_nagare_io_file_readAllStreaming_fun1442(kk_function_t _fself, kk_function_t _b_x508, kk_box_t _b_x509, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_readAllStreaming_fun1442(kk_ssize_t i_10816, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readAllStreaming_fun1442__t* _self = kk_function_alloc_as(struct kk_nagare_io_file_readAllStreaming_fun1442__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file_readAllStreaming_fun1442, kk_context());
  _self->i_10816 = i_10816;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file_readAllStreaming_fun1442(kk_function_t _fself, kk_function_t _b_x508, kk_box_t _b_x509, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readAllStreaming_fun1442__t* _self = kk_function_as(struct kk_nagare_io_file_readAllStreaming_fun1442__t*, _fself, _ctx);
  kk_ssize_t i_10816 = _self->i_10816; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_10816, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_10816, _b_x508, _b_x509, _ctx);
}


// lift anonymous function
struct kk_nagare_io_file_readAllStreaming_fun1443__t {
  struct kk_function_s _base;
  kk_ref_t hRef;
};
static kk_unit_t kk_nagare_io_file_readAllStreaming_fun1443(kk_function_t _fself, kk_nagare_io_file__effect__read_handle _y_x10485, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_readAllStreaming_fun1443(kk_ref_t hRef, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readAllStreaming_fun1443__t* _self = kk_function_alloc_as(struct kk_nagare_io_file_readAllStreaming_fun1443__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file_readAllStreaming_fun1443, kk_context());
  _self->hRef = hRef;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_unit_t kk_nagare_io_file_readAllStreaming_fun1443(kk_function_t _fself, kk_nagare_io_file__effect__read_handle _y_x10485, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readAllStreaming_fun1443__t* _self = kk_function_as(struct kk_nagare_io_file_readAllStreaming_fun1443__t*, _fself, _ctx);
  kk_ref_t hRef = _self->hRef; /* ref<global,maybe<nagare/io/file_effect/read-handle>> */
  kk_drop_match(_self, {kk_ref_dup(hRef, _ctx);}, {}, _ctx)
  kk_unit_t _brw_x1022 = kk_Unit;
  kk_box_t _x_x1444;
  kk_std_core_types__maybe _x_x1445 = kk_std_core_types__new_Just(kk_nagare_io_file__effect__read_handle_box(_y_x10485, _ctx), _ctx); /*maybe<10024>*/
  _x_x1444 = kk_std_core_types__maybe_box(_x_x1445, _ctx); /*10000*/
  kk_ref_set_borrow(hRef,_x_x1444,kk_context());
  kk_ref_drop(hRef, _ctx);
  _brw_x1022; return kk_Unit;
}


// lift anonymous function
struct kk_nagare_io_file_readAllStreaming_fun1447__t {
  struct kk_function_s _base;
  kk_function_t next_10815;
};
static kk_box_t kk_nagare_io_file_readAllStreaming_fun1447(kk_function_t _fself, kk_box_t _b_x524, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_readAllStreaming_fun1447(kk_function_t next_10815, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readAllStreaming_fun1447__t* _self = kk_function_alloc_as(struct kk_nagare_io_file_readAllStreaming_fun1447__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file_readAllStreaming_fun1447, kk_context());
  _self->next_10815 = next_10815;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file_readAllStreaming_fun1447(kk_function_t _fself, kk_box_t _b_x524, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readAllStreaming_fun1447__t* _self = kk_function_as(struct kk_nagare_io_file_readAllStreaming_fun1447__t*, _fself, _ctx);
  kk_function_t next_10815 = _self->next_10815; /* (nagare/io/file_effect/read-handle) -> <nagare/io/file_effect/fileRead,write<global>,alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui> () */
  kk_drop_match(_self, {kk_function_dup(next_10815, _ctx);}, {}, _ctx)
  kk_unit_t _x_x1448 = kk_Unit;
  kk_nagare_io_file__effect__read_handle _x_x1449 = kk_nagare_io_file__effect__read_handle_unbox(_b_x524, KK_OWNED, _ctx); /*nagare/io/file_effect/read-handle*/
  kk_function_call(kk_unit_t, (kk_function_t, kk_nagare_io_file__effect__read_handle, kk_context_t*), next_10815, (next_10815, _x_x1449, _ctx), _ctx);
  return kk_unit_box(_x_x1448);
}
static kk_unit_t kk_nagare_io_file_readAllStreaming_fun1434(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readAllStreaming_fun1434__t* _self = kk_function_as(struct kk_nagare_io_file_readAllStreaming_fun1434__t*, _fself, _ctx);
  kk_std_os_path__path filepath = _self->filepath; /* std/os/path/path */
  kk_ref_t hRef = _self->hRef; /* ref<global,maybe<nagare/io/file_effect/read-handle>> */
  kk_drop_match(_self, {kk_std_os_path__path_dup(filepath, _ctx);kk_ref_dup(hRef, _ctx);}, {}, _ctx)
  kk_string_t _x_x1_10618;
  kk_box_t _x_x1435 = kk_std_core_hnd__open_none1(kk_nagare_io_file_new_readAllStreaming_fun1436(_ctx), kk_std_os_path__path_box(filepath, _ctx), _ctx); /*10001*/
  _x_x1_10618 = kk_string_unbox(_x_x1435); /*string*/
  kk_ssize_t i_10816 = (KK_IZ(1)); /*hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_10816,kk_context()); /*hnd/evv<<nagare/io/file_effect/fileRead,write<global>,alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui>>*/;
  kk_std_core_hnd__ev ev_10819 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<nagare/io/file_effect/fileRead>*/;
  kk_nagare_io_file__effect__read_handle y;
  kk_box_t _x_x1439;
  {
    struct kk_std_core_hnd_Ev* _con_x1440 = kk_std_core_hnd__as_Ev(ev_10819, _ctx);
    kk_box_t _box_x495 = _con_x1440->hnd;
    int32_t m = _con_x1440->marker;
    kk_nagare_io_file__effect__fileRead h = kk_nagare_io_file__effect__fileRead_unbox(_box_x495, KK_BORROWED, _ctx);
    kk_nagare_io_file__effect__fileRead_dup(h, _ctx);
    kk_std_core_hnd__clause1 _match_x1024;
    kk_std_core_hnd__clause1 _brw_x1025 = kk_nagare_io_file__effect_openRead_fs__select(h, _ctx); /*hnd/clause1<string,nagare/io/file_effect/read-handle,nagare/io/file_effect/fileRead,692,693>*/;
    kk_datatype_ptr_dropn(h, (KK_I32(6)), _ctx);
    _match_x1024 = _brw_x1025; /*hnd/clause1<string,nagare/io/file_effect/read-handle,nagare/io/file_effect/fileRead,692,693>*/
    {
      kk_function_t _fun_unbox_x499 = _match_x1024.clause;
      _x_x1439 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x499, (_fun_unbox_x499, m, ev_10819, kk_string_box(_x_x1_10618), _ctx), _ctx); /*10010*/
    }
  }
  y = kk_nagare_io_file__effect__read_handle_unbox(_x_x1439, KK_OWNED, _ctx); /*nagare/io/file_effect/read-handle*/
  kk_evv_set(w,kk_context());
  kk_nagare_io_file__effect__read_handle x_10814;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1441 = kk_std_core_hnd_yield_cont(kk_nagare_io_file_new_readAllStreaming_fun1442(i_10816, _ctx), _ctx); /*10002*/
    x_10814 = kk_nagare_io_file__effect__read_handle_unbox(_x_x1441, KK_OWNED, _ctx); /*nagare/io/file_effect/read-handle*/
  }
  else {
    x_10814 = y; /*nagare/io/file_effect/read-handle*/
  }
  kk_function_t next_10815 = kk_nagare_io_file_new_readAllStreaming_fun1443(hRef, _ctx); /*(nagare/io/file_effect/read-handle) -> <nagare/io/file_effect/fileRead,write<global>,alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui> ()*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1446 = kk_std_core_hnd_yield_extend(kk_nagare_io_file_new_readAllStreaming_fun1447(next_10815, _ctx), _ctx); /*10001*/
    kk_unit_unbox(_x_x1446); return kk_Unit;
  }
  {
    kk_function_call(kk_unit_t, (kk_function_t, kk_nagare_io_file__effect__read_handle, kk_context_t*), next_10815, (next_10815, x_10814, _ctx), _ctx); return kk_Unit;
  }
}


// lift anonymous function
struct kk_nagare_io_file_readAllStreaming_fun1451__t {
  struct kk_function_s _base;
  kk_ref_t hRef;
};
static kk_unit_t kk_nagare_io_file_readAllStreaming_fun1451(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_readAllStreaming_fun1451(kk_ref_t hRef, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readAllStreaming_fun1451__t* _self = kk_function_alloc_as(struct kk_nagare_io_file_readAllStreaming_fun1451__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file_readAllStreaming_fun1451, kk_context());
  _self->hRef = hRef;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_io_file_readAllStreaming_fun1456__t {
  struct kk_function_s _base;
  kk_ssize_t i_0_10824;
};
static kk_box_t kk_nagare_io_file_readAllStreaming_fun1456(kk_function_t _fself, kk_function_t _b_x541, kk_box_t _b_x542, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_readAllStreaming_fun1456(kk_ssize_t i_0_10824, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readAllStreaming_fun1456__t* _self = kk_function_alloc_as(struct kk_nagare_io_file_readAllStreaming_fun1456__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file_readAllStreaming_fun1456, kk_context());
  _self->i_0_10824 = i_0_10824;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_io_file_readAllStreaming_fun1457__t {
  struct kk_function_s _base;
  kk_function_t _b_x541;
};
static kk_unit_t kk_nagare_io_file_readAllStreaming_fun1457(kk_function_t _fself, kk_box_t _b_x543, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_readAllStreaming_fun1457(kk_function_t _b_x541, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readAllStreaming_fun1457__t* _self = kk_function_alloc_as(struct kk_nagare_io_file_readAllStreaming_fun1457__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file_readAllStreaming_fun1457, kk_context());
  _self->_b_x541 = _b_x541;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_unit_t kk_nagare_io_file_readAllStreaming_fun1457(kk_function_t _fself, kk_box_t _b_x543, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readAllStreaming_fun1457__t* _self = kk_function_as(struct kk_nagare_io_file_readAllStreaming_fun1457__t*, _fself, _ctx);
  kk_function_t _b_x541 = _self->_b_x541; /* (10003) -> 10001 10000 */
  kk_drop_match(_self, {kk_function_dup(_b_x541, _ctx);}, {}, _ctx)
  kk_box_t _x_x1458 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _b_x541, (_b_x541, _b_x543, _ctx), _ctx); /*10000*/
  kk_unit_unbox(_x_x1458); return kk_Unit;
}


// lift anonymous function
struct kk_nagare_io_file_readAllStreaming_fun1459__t {
  struct kk_function_s _base;
  kk_function_t _b_x537_554;
};
static kk_box_t kk_nagare_io_file_readAllStreaming_fun1459(kk_function_t _fself, kk_box_t _b_x539, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_readAllStreaming_fun1459(kk_function_t _b_x537_554, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readAllStreaming_fun1459__t* _self = kk_function_alloc_as(struct kk_nagare_io_file_readAllStreaming_fun1459__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file_readAllStreaming_fun1459, kk_context());
  _self->_b_x537_554 = _b_x537_554;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file_readAllStreaming_fun1459(kk_function_t _fself, kk_box_t _b_x539, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readAllStreaming_fun1459__t* _self = kk_function_as(struct kk_nagare_io_file_readAllStreaming_fun1459__t*, _fself, _ctx);
  kk_function_t _b_x537_554 = _self->_b_x537_554; /* (10011) -> <nagare/io/file_effect/fileRead,read<global>,alloc<global>,console/console,div,exn,fsys,ndet,net,ui,write<global>> () */
  kk_drop_match(_self, {kk_function_dup(_b_x537_554, _ctx);}, {}, _ctx)
  kk_unit_t _x_x1460 = kk_Unit;
  kk_function_call(kk_unit_t, (kk_function_t, kk_box_t, kk_context_t*), _b_x537_554, (_b_x537_554, _b_x539, _ctx), _ctx);
  return kk_unit_box(_x_x1460);
}
static kk_box_t kk_nagare_io_file_readAllStreaming_fun1456(kk_function_t _fself, kk_function_t _b_x541, kk_box_t _b_x542, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readAllStreaming_fun1456__t* _self = kk_function_as(struct kk_nagare_io_file_readAllStreaming_fun1456__t*, _fself, _ctx);
  kk_ssize_t i_0_10824 = _self->i_0_10824; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_0_10824, _ctx);}, {}, _ctx)
  kk_function_t cont_0_558 = kk_nagare_io_file_new_readAllStreaming_fun1457(_b_x541, _ctx); /*(10011) -> <nagare/io/file_effect/fileRead,read<global>,alloc<global>,console/console,div,exn,fsys,ndet,net,ui,write<global>> ()*/;
  kk_box_t res_0_559 = _b_x542; /*10011*/;
  kk_ssize_t _b_x536_553 = i_0_10824; /*hnd/ev-index*/;
  kk_function_t _b_x537_554 = cont_0_558; /*(10011) -> <nagare/io/file_effect/fileRead,read<global>,alloc<global>,console/console,div,exn,fsys,ndet,net,ui,write<global>> ()*/;
  kk_box_t _b_x538_555 = res_0_559; /*10011*/;
  return kk_std_core_hnd_open_at1(_b_x536_553, kk_nagare_io_file_new_readAllStreaming_fun1459(_b_x537_554, _ctx), _b_x538_555, _ctx);
}
static kk_unit_t kk_nagare_io_file_readAllStreaming_fun1451(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readAllStreaming_fun1451__t* _self = kk_function_as(struct kk_nagare_io_file_readAllStreaming_fun1451__t*, _fself, _ctx);
  kk_ref_t hRef = _self->hRef; /* ref<global,maybe<nagare/io/file_effect/read-handle>> */
  kk_drop_match(_self, {kk_ref_dup(hRef, _ctx);}, {}, _ctx)
  kk_std_core_types__maybe _match_x1017;
  kk_box_t _x_x1452 = kk_ref_get(hRef,kk_context()); /*10000*/
  _match_x1017 = kk_std_core_types__maybe_unbox(_x_x1452, KK_OWNED, _ctx); /*maybe<nagare/io/file_effect/read-handle>*/
  if (kk_std_core_types__is_Just(_match_x1017, _ctx)) {
    kk_box_t _box_x527 = _match_x1017._cons.Just.value;
    kk_nagare_io_file__effect__read_handle h_0 = kk_nagare_io_file__effect__read_handle_unbox(_box_x527, KK_BORROWED, _ctx);
    kk_std_core_types__maybe_drop(_match_x1017, _ctx);
    kk_ssize_t i_0_10824 = (KK_IZ(1)); /*hnd/ev-index*/;
    kk_evv_t w_0 = kk_evv_swap_create1(i_0_10824,kk_context()); /*hnd/evv<<nagare/io/file_effect/fileRead,read<global>,alloc<global>,console/console,div,exn,fsys,ndet,net,ui,write<global>>>*/;
    kk_std_core_hnd__ev ev_0_10827 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<nagare/io/file_effect/fileRead>*/;
    kk_unit_t y_0 = kk_Unit;
    kk_box_t _x_x1453;
    {
      struct kk_std_core_hnd_Ev* _con_x1454 = kk_std_core_hnd__as_Ev(ev_0_10827, _ctx);
      kk_box_t _box_x528 = _con_x1454->hnd;
      int32_t m_0 = _con_x1454->marker;
      kk_nagare_io_file__effect__fileRead h_1 = kk_nagare_io_file__effect__fileRead_unbox(_box_x528, KK_BORROWED, _ctx);
      kk_nagare_io_file__effect__fileRead_dup(h_1, _ctx);
      kk_std_core_hnd__clause1 _match_x1019;
      kk_std_core_hnd__clause1 _brw_x1020 = kk_nagare_io_file__effect_closeRead_fs__select(h_1, _ctx); /*hnd/clause1<nagare/io/file_effect/read-handle,(),nagare/io/file_effect/fileRead,799,800>*/;
      kk_datatype_ptr_dropn(h_1, (KK_I32(6)), _ctx);
      _match_x1019 = _brw_x1020; /*hnd/clause1<nagare/io/file_effect/read-handle,(),nagare/io/file_effect/fileRead,799,800>*/
      {
        kk_function_t _fun_unbox_x532 = _match_x1019.clause;
        _x_x1453 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x532, (_fun_unbox_x532, m_0, ev_0_10827, kk_nagare_io_file__effect__read_handle_box(h_0, _ctx), _ctx), _ctx); /*10010*/
      }
    }
    kk_unit_unbox(_x_x1453);
    kk_evv_set(w_0,kk_context());
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x1455 = kk_std_core_hnd_yield_cont(kk_nagare_io_file_new_readAllStreaming_fun1456(i_0_10824, _ctx), _ctx); /*10002*/
      kk_unit_unbox(_x_x1455); return kk_Unit;
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
struct kk_nagare_io_file_readAllStreaming_fun1462__t {
  struct kk_function_s _base;
  kk_std_core_types__optional chunkSize;
  kk_ref_t hRef;
};
static kk_nagare_core_types__pull kk_nagare_io_file_readAllStreaming_fun1462(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_readAllStreaming_fun1462(kk_std_core_types__optional chunkSize, kk_ref_t hRef, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readAllStreaming_fun1462__t* _self = kk_function_alloc_as(struct kk_nagare_io_file_readAllStreaming_fun1462__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file_readAllStreaming_fun1462, kk_context());
  _self->chunkSize = chunkSize;
  _self->hRef = hRef;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_nagare_core_types__pull kk_nagare_io_file_readAllStreaming_fun1462(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readAllStreaming_fun1462__t* _self = kk_function_as(struct kk_nagare_io_file_readAllStreaming_fun1462__t*, _fself, _ctx);
  kk_std_core_types__optional chunkSize = _self->chunkSize; /* ? int */
  kk_ref_t hRef = _self->hRef; /* ref<global,maybe<nagare/io/file_effect/read-handle>> */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(chunkSize, _ctx);kk_ref_dup(hRef, _ctx);}, {}, _ctx)
  kk_std_core_types__maybe _match_x1016;
  kk_box_t _x_x1463 = kk_ref_get(hRef,kk_context()); /*10000*/
  _match_x1016 = kk_std_core_types__maybe_unbox(_x_x1463, KK_OWNED, _ctx); /*maybe<nagare/io/file_effect/read-handle>*/
  if (kk_std_core_types__is_Just(_match_x1016, _ctx)) {
    kk_box_t _box_x546 = _match_x1016._cons.Just.value;
    kk_nagare_io_file__effect__read_handle h_0_0_0 = kk_nagare_io_file__effect__read_handle_unbox(_box_x546, KK_BORROWED, _ctx);
    kk_std_core_types__maybe_drop(_match_x1016, _ctx);
    kk_evv_t w_1 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<div,read<global>,alloc<global>,console/console,exn,nagare/io/file_effect/fileRead,fsys,ndet,net,ui,write<global>>>*/;
    kk_nagare_core_types__pull x_4;
    kk_integer_t _x_x1464;
    if (kk_std_core_types__is_Optional(chunkSize, _ctx)) {
      kk_box_t _box_x547 = chunkSize._cons._Optional.value;
      kk_integer_t _uniq_chunkSize_1883 = kk_integer_unbox(_box_x547, _ctx);
      kk_integer_dup(_uniq_chunkSize_1883, _ctx);
      kk_std_core_types__optional_drop(chunkSize, _ctx);
      _x_x1464 = _uniq_chunkSize_1883; /*int*/
    }
    else {
      kk_std_core_types__optional_drop(chunkSize, _ctx);
      _x_x1464 = kk_integer_from_small(4096); /*int*/
    }
    x_4 = kk_nagare_io_file_readPull(h_0_0_0, _x_x1464, _ctx); /*nagare/core/types/pull<string,<nagare/io/file_effect/fileRead|io>>*/
    kk_unit_t keep = kk_Unit;
    kk_evv_set(w_1,kk_context());
    return x_4;
  }
  {
    kk_std_core_types__optional_drop(chunkSize, _ctx);
    return kk_nagare_core_types__new_PDone(_ctx);
  }
}
static kk_nagare_core_types__pull kk_nagare_io_file_readAllStreaming_fun1432(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readAllStreaming_fun1432__t* _self = kk_function_as(struct kk_nagare_io_file_readAllStreaming_fun1432__t*, _fself, _ctx);
  kk_std_core_types__optional chunkSize = _self->chunkSize; /* ? int */
  kk_std_os_path__path filepath = _self->filepath; /* std/os/path/path */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(chunkSize, _ctx);kk_std_os_path__path_dup(filepath, _ctx);}, {}, _ctx)
  kk_ref_t hRef = kk_ref_alloc((kk_std_core_types__maybe_box(kk_std_core_types__new_Nothing(_ctx), _ctx)),kk_context()); /*ref<global,maybe<nagare/io/file_effect/read-handle>>*/;
  kk_function_t _x_x1433;
  kk_ref_dup(hRef, _ctx);
  _x_x1433 = kk_nagare_io_file_new_readAllStreaming_fun1434(filepath, hRef, _ctx); /*() -> <alloc<global>,console/console,div,exn,nagare/io/file_effect/fileRead,fsys,ndet,net,read<global>,ui,write<global>> ()*/
  kk_function_t _x_x1450;
  kk_ref_dup(hRef, _ctx);
  _x_x1450 = kk_nagare_io_file_new_readAllStreaming_fun1451(hRef, _ctx); /*() -> <alloc<global>,console/console,div,exn,nagare/io/file_effect/fileRead,fsys,ndet,net,read<global>,ui,write<global>> ()*/
  kk_nagare_core_types__pull _x_x1461 = kk_nagare_core_types__new_PEval(kk_reuse_null, 0, kk_nagare_io_file_new_readAllStreaming_fun1462(chunkSize, hRef, _ctx), _ctx); /*nagare/core/types/pull<19,20>*/
  return kk_nagare_core_types__new_PAcquire(kk_reuse_null, 0, _x_x1433, _x_x1450, _x_x1461, _ctx);
}

kk_nagare_core_types__nstream kk_nagare_io_file_readAllStreaming(kk_std_os_path__path filepath, kk_std_core_types__optional chunkSize, kk_context_t* _ctx) { /* (filepath : std/os/path/path, chunkSize : ? int) -> nagare/io/file_effect/readStream<string> */ 
  kk_nagare_core_types__pull _x_x1431 = kk_nagare_core_types__new_PEval(kk_reuse_null, 0, kk_nagare_io_file_new_readAllStreaming_fun1432(chunkSize, filepath, _ctx), _ctx); /*nagare/core/types/pull<19,20>*/
  return kk_nagare_core_types__new_Stream(_x_x1431, _ctx);
}
 
// Read a file as a stream of lines (splits on newline boundaries).

kk_nagare_core_types__nstream kk_nagare_io_file_readLines(kk_std_os_path__path filepath, kk_std_core_types__optional chunkSize, kk_context_t* _ctx) { /* (filepath : std/os/path/path, chunkSize : ? int) -> nagare/io/file_effect/readStream<string> */ 
  kk_nagare_core_types__nstream source_10028;
  kk_std_core_types__optional _x_x1465;
  kk_box_t _x_x1466;
  kk_integer_t _x_x1467;
  if (kk_std_core_types__is_Optional(chunkSize, _ctx)) {
    kk_box_t _box_x560 = chunkSize._cons._Optional.value;
    kk_integer_t _uniq_chunkSize_2063 = kk_integer_unbox(_box_x560, _ctx);
    kk_integer_dup(_uniq_chunkSize_2063, _ctx);
    kk_std_core_types__optional_drop(chunkSize, _ctx);
    _x_x1467 = _uniq_chunkSize_2063; /*int*/
  }
  else {
    kk_std_core_types__optional_drop(chunkSize, _ctx);
    _x_x1467 = kk_integer_from_small(4096); /*int*/
  }
  _x_x1466 = kk_integer_box(_x_x1467, _ctx); /*10003*/
  _x_x1465 = kk_std_core_types__new_Optional(_x_x1466, _ctx); /*? 10003*/
  source_10028 = kk_nagare_io_file_readAllStreaming(filepath, _x_x1465, _ctx); /*nagare/io/file_effect/readStream<string>*/
  return kk_nagare_io_file_splitLines(source_10028, _ctx);
}
 
// Read entire file content as a single string element.


// lift anonymous function
struct kk_nagare_io_file_readUtf8_fun1471__t {
  struct kk_function_s _base;
  kk_std_os_path__path filepath;
};
static kk_nagare_core_types__pull kk_nagare_io_file_readUtf8_fun1471(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_readUtf8_fun1471(kk_std_os_path__path filepath, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readUtf8_fun1471__t* _self = kk_function_alloc_as(struct kk_nagare_io_file_readUtf8_fun1471__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file_readUtf8_fun1471, kk_context());
  _self->filepath = filepath;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_io_file_readUtf8_fun1473__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_io_file_readUtf8_fun1473(kk_function_t _fself, kk_box_t _b_x569, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_readUtf8_fun1473(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file_readUtf8_fun1473, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_io_file_readUtf8_fun1473(kk_function_t _fself, kk_box_t _b_x569, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1474;
  kk_std_os_path__path _x_x1475 = kk_std_os_path__path_unbox(_b_x569, KK_OWNED, _ctx); /*std/os/path/path*/
  _x_x1474 = kk_std_os_path_string(_x_x1475, _ctx); /*string*/
  return kk_string_box(_x_x1474);
}


// lift anonymous function
struct kk_nagare_io_file_readUtf8_fun1479__t {
  struct kk_function_s _base;
  kk_ssize_t i_10835;
};
static kk_box_t kk_nagare_io_file_readUtf8_fun1479(kk_function_t _fself, kk_function_t _b_x585, kk_box_t _b_x586, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_readUtf8_fun1479(kk_ssize_t i_10835, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readUtf8_fun1479__t* _self = kk_function_alloc_as(struct kk_nagare_io_file_readUtf8_fun1479__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file_readUtf8_fun1479, kk_context());
  _self->i_10835 = i_10835;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file_readUtf8_fun1479(kk_function_t _fself, kk_function_t _b_x585, kk_box_t _b_x586, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readUtf8_fun1479__t* _self = kk_function_as(struct kk_nagare_io_file_readUtf8_fun1479__t*, _fself, _ctx);
  kk_ssize_t i_10835 = _self->i_10835; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_10835, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_10835, _b_x585, _b_x586, _ctx);
}


// lift anonymous function
struct kk_nagare_io_file_readUtf8_fun1481__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_io_file_readUtf8_fun1481(kk_function_t _fself, kk_box_t _b_x595, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_readUtf8_fun1481(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file_readUtf8_fun1481, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_io_file_readUtf8_fun1481(kk_function_t _fself, kk_box_t _b_x595, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_nagare_core_types__pull _x_x1482;
  kk_string_t _x_x1483 = kk_string_unbox(_b_x595); /*string*/
  _x_x1482 = kk_nagare_io_file__mlift_readUtf8_10672(_x_x1483, _ctx); /*nagare/core/types/pull<string,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileRead,fsys,ndet,net,read<global>,ui,write<global>>>*/
  return kk_nagare_core_types__pull_box(_x_x1482, _ctx);
}
static kk_nagare_core_types__pull kk_nagare_io_file_readUtf8_fun1471(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_io_file_readUtf8_fun1471__t* _self = kk_function_as(struct kk_nagare_io_file_readUtf8_fun1471__t*, _fself, _ctx);
  kk_std_os_path__path filepath = _self->filepath; /* std/os/path/path */
  kk_drop_match(_self, {kk_std_os_path__path_dup(filepath, _ctx);}, {}, _ctx)
  kk_string_t _x_x1_10623;
  kk_box_t _x_x1472 = kk_std_core_hnd__open_none1(kk_nagare_io_file_new_readUtf8_fun1473(_ctx), kk_std_os_path__path_box(filepath, _ctx), _ctx); /*10001*/
  _x_x1_10623 = kk_string_unbox(_x_x1472); /*string*/
  kk_ssize_t i_10835 = (KK_IZ(1)); /*hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_10835,kk_context()); /*hnd/evv<<nagare/io/file_effect/fileRead,alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_std_core_hnd__ev ev_10838 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<nagare/io/file_effect/fileRead>*/;
  kk_string_t y;
  kk_box_t _x_x1476;
  {
    struct kk_std_core_hnd_Ev* _con_x1477 = kk_std_core_hnd__as_Ev(ev_10838, _ctx);
    kk_box_t _box_x572 = _con_x1477->hnd;
    int32_t m = _con_x1477->marker;
    kk_nagare_io_file__effect__fileRead h = kk_nagare_io_file__effect__fileRead_unbox(_box_x572, KK_BORROWED, _ctx);
    kk_nagare_io_file__effect__fileRead_dup(h, _ctx);
    kk_std_core_hnd__clause1 _match_x1014;
    kk_std_core_hnd__clause1 _brw_x1015 = kk_nagare_io_file__effect_readTextFileOp_fs__select(h, _ctx); /*hnd/clause1<string,string,nagare/io/file_effect/fileRead,1128,1129>*/;
    kk_datatype_ptr_dropn(h, (KK_I32(6)), _ctx);
    _match_x1014 = _brw_x1015; /*hnd/clause1<string,string,nagare/io/file_effect/fileRead,1128,1129>*/
    {
      kk_function_t _fun_unbox_x576 = _match_x1014.clause;
      _x_x1476 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x576, (_fun_unbox_x576, m, ev_10838, kk_string_box(_x_x1_10623), _ctx), _ctx); /*10010*/
    }
  }
  y = kk_string_unbox(_x_x1476); /*string*/
  kk_evv_set(w,kk_context());
  kk_string_t x_10833;
  if (kk_yielding(kk_context())) {
    kk_string_drop(y, _ctx);
    kk_box_t _x_x1478 = kk_std_core_hnd_yield_cont(kk_nagare_io_file_new_readUtf8_fun1479(i_10835, _ctx), _ctx); /*10002*/
    x_10833 = kk_string_unbox(_x_x1478); /*string*/
  }
  else {
    x_10833 = y; /*string*/
  }
  if (kk_yielding(kk_context())) {
    kk_string_drop(x_10833, _ctx);
    kk_box_t _x_x1480 = kk_std_core_hnd_yield_extend(kk_nagare_io_file_new_readUtf8_fun1481(_ctx), _ctx); /*10001*/
    return kk_nagare_core_types__pull_unbox(_x_x1480, KK_OWNED, _ctx);
  }
  {
    kk_string_t _b_x596_600 = x_10833; /*string*/;
    kk_std_core_types__list _b_x597_601 = kk_std_core_types__new_Nil(_ctx); /*list<string>*/;
    kk_nagare_core_types__chunk _x_x1484;
    kk_std_core_types__list _x_x1485 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_string_box(_b_x596_600), _b_x597_601, _ctx); /*list<10021>*/
    _x_x1484 = kk_nagare_core_types__new_Chunk(_x_x1485, _ctx); /*nagare/core/types/chunk<4>*/
    return kk_nagare_core_types__new_POutput(kk_reuse_null, 0, _x_x1484, kk_nagare_core_types__new_PDone(_ctx), _ctx);
  }
}

kk_nagare_core_types__nstream kk_nagare_io_file_readUtf8(kk_std_os_path__path filepath, kk_context_t* _ctx) { /* (filepath : std/os/path/path) -> nagare/io/file_effect/readStream<string> */ 
  kk_nagare_core_types__pull _x_x1470 = kk_nagare_core_types__new_PEval(kk_reuse_null, 0, kk_nagare_io_file_new_readUtf8_fun1471(filepath, _ctx), _ctx); /*nagare/core/types/pull<19,20>*/
  return kk_nagare_core_types__new_Stream(_x_x1470, _ctx);
}
 
// monadic lift

kk_unit_t kk_nagare_io_file__mlift_lift_unroll_writeAllChunks_10003_10372_10673(kk_std_core_types__list _uniq_xx_10183, kk_nagare_io_file__effect__write_handle h, kk_integer_t wild__, kk_context_t* _ctx) { /* (list<string>, h : nagare/io/file_effect/write-handle, wild_ : int) -> <nagare/io/file_effect/fileWrite,alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> () */ 
  kk_integer_drop(wild__, _ctx);
  kk_nagare_io_file__lift_unroll_writeAllChunks_10003_10372(h, _uniq_xx_10183, _ctx); return kk_Unit;
}
 
// lifted local: @lift-unroll-writeAllChunks@10003@10371, @unroll-writeAllChunks@10003, @spec-x10185
// specialized: std/core/list/@unroll-foreach@10017, on parameters @uniq-action@10180, using:
// @uniq-action@10180 = fn<<(nagare/io/file_effect/fileWrite :: (E, V) -> V),(alloc :: H -> X)<(global :: H)>,(console/console :: X),(div :: X),(exn :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>>>(s: string){
//   val _ : int
//         = std/core/types/@open<(nagare/io/file_effect/fileWrite :: (E, V) -> V),<(nagare/io/file_effect/fileWrite :: (E, V) -> V),(alloc :: H -> X)<(global :: H)>,(console/console :: X),(div :: X),(exn :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>>,(h : nagare/io/file_effect/write-handle, content : string) -> (nagare/io/file_effect/fileWrite :: (E, V) -> V) int,(h : nagare/io/file_effect/write-handle, content : string) -> <(nagare/io/file_effect/fileWrite :: (E, V) -> V),(alloc :: H -> X)<(global :: H)>,(console/console :: X),(div :: X),(exn :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>> int>((fn<(nagare/io/file_effect/fileWrite :: (E, V) -> V)>(h@0: nagare/io/file_effect/write-handle, content: string){
//           (std/core/hnd/@perform2<nagare/io/file_effect/write-handle,string,int,(nagare/io/file_effect/fileWrite :: (E, V) -> V),(nagare/io/file_effect/fileWrite :: (E, V) -> V)>((std/core/types/@open<(total :: E),(nagare/io/file_effect/fileWrite :: (E, V) -> V),(i : hnd/ev-index) -> (hnd/ev :: ((E, V) -> V) -> V)<(nagare/io/file_effect/fileWrite :: (E, V) -> V)>,(i : hnd/ev-index) -> (nagare/io/file_effect/fileWrite :: (E, V) -> V) (hnd/ev :: ((E, V) -> V) -> V)<(nagare/io/file_effect/fileWrite :: (E, V) -> V)>>((std/core/hnd/@evv-at<(nagare/io/file_effect/fileWrite :: (E, V) -> V)>))((std/core/types/@open<(total :: E),(nagare/io/file_effect/fileWrite :: (E, V) -> V),(i : int) -> ssize_t,(i : int) -> (nagare/io/file_effect/fileWrite :: (E, V) -> V) ssize_t>(std/core/types/@make-ssize_t)(0)))), nagare/io/file_effect/writeChunk/@select, h@0, content));
//         }))(h, s);
//   std/core/types/Unit;
// }


// lift anonymous function
struct kk_nagare_io_file__lift_unroll_writeAllChunks_10003_10372_fun1490__t {
  struct kk_function_s _base;
  kk_ssize_t i_10844;
};
static kk_box_t kk_nagare_io_file__lift_unroll_writeAllChunks_10003_10372_fun1490(kk_function_t _fself, kk_function_t _b_x618, kk_box_t _b_x619, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__new_lift_unroll_writeAllChunks_10003_10372_fun1490(kk_ssize_t i_10844, kk_context_t* _ctx) {
  struct kk_nagare_io_file__lift_unroll_writeAllChunks_10003_10372_fun1490__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__lift_unroll_writeAllChunks_10003_10372_fun1490__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__lift_unroll_writeAllChunks_10003_10372_fun1490, kk_context());
  _self->i_10844 = i_10844;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file__lift_unroll_writeAllChunks_10003_10372_fun1490(kk_function_t _fself, kk_function_t _b_x618, kk_box_t _b_x619, kk_context_t* _ctx) {
  struct kk_nagare_io_file__lift_unroll_writeAllChunks_10003_10372_fun1490__t* _self = kk_function_as(struct kk_nagare_io_file__lift_unroll_writeAllChunks_10003_10372_fun1490__t*, _fself, _ctx);
  kk_ssize_t i_10844 = _self->i_10844; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_10844, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_10844, _b_x618, _b_x619, _ctx);
}


// lift anonymous function
struct kk_nagare_io_file__lift_unroll_writeAllChunks_10003_10372_fun1492__t {
  struct kk_function_s _base;
  kk_std_core_types__list _uniq_xx_10183_0;
  kk_nagare_io_file__effect__write_handle h_0;
};
static kk_box_t kk_nagare_io_file__lift_unroll_writeAllChunks_10003_10372_fun1492(kk_function_t _fself, kk_box_t _b_x628, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__new_lift_unroll_writeAllChunks_10003_10372_fun1492(kk_std_core_types__list _uniq_xx_10183_0, kk_nagare_io_file__effect__write_handle h_0, kk_context_t* _ctx) {
  struct kk_nagare_io_file__lift_unroll_writeAllChunks_10003_10372_fun1492__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__lift_unroll_writeAllChunks_10003_10372_fun1492__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__lift_unroll_writeAllChunks_10003_10372_fun1492, kk_context());
  _self->_uniq_xx_10183_0 = _uniq_xx_10183_0;
  _self->h_0 = h_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file__lift_unroll_writeAllChunks_10003_10372_fun1492(kk_function_t _fself, kk_box_t _b_x628, kk_context_t* _ctx) {
  struct kk_nagare_io_file__lift_unroll_writeAllChunks_10003_10372_fun1492__t* _self = kk_function_as(struct kk_nagare_io_file__lift_unroll_writeAllChunks_10003_10372_fun1492__t*, _fself, _ctx);
  kk_std_core_types__list _uniq_xx_10183_0 = _self->_uniq_xx_10183_0; /* list<string> */
  kk_nagare_io_file__effect__write_handle h_0 = _self->h_0; /* nagare/io/file_effect/write-handle */
  kk_drop_match(_self, {kk_std_core_types__list_dup(_uniq_xx_10183_0, _ctx);kk_nagare_io_file__effect__write_handle_dup(h_0, _ctx);}, {}, _ctx)
  kk_integer_t wild___0_631 = kk_integer_unbox(_b_x628, _ctx); /*int*/;
  kk_unit_t _x_x1493 = kk_Unit;
  kk_nagare_io_file__mlift_lift_unroll_writeAllChunks_10003_10372_10673(_uniq_xx_10183_0, h_0, wild___0_631, _ctx);
  return kk_unit_box(_x_x1493);
}

kk_unit_t kk_nagare_io_file__lift_unroll_writeAllChunks_10003_10372(kk_nagare_io_file__effect__write_handle h_0, kk_std_core_types__list _uniq_xs_10179, kk_context_t* _ctx) { /* (h : nagare/io/file_effect/write-handle, list<string>) -> <nagare/io/file_effect/fileWrite,alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> () */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_xs_10179, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1486 = kk_std_core_types__as_Cons(_uniq_xs_10179, _ctx);
    kk_box_t _box_x602 = _con_x1486->head;
    kk_std_core_types__list _uniq_xx_10183_0 = _con_x1486->tail;
    kk_string_t _uniq_x_10182 = kk_string_unbox(_box_x602);
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10179, _ctx)) {
      kk_datatype_ptr_free(_uniq_xs_10179, _ctx);
    }
    else {
      kk_string_dup(_uniq_x_10182, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10183_0, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10179, _ctx);
    }
    kk_ssize_t i_10844 = (KK_IZ(1)); /*hnd/ev-index*/;
    kk_evv_t w = kk_evv_swap_create1(i_10844,kk_context()); /*hnd/evv<<nagare/io/file_effect/fileWrite,alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
    kk_std_core_hnd__ev evx_10848 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<nagare/io/file_effect/fileWrite>*/;
    kk_integer_t y;
    kk_box_t _x_x1487;
    {
      struct kk_std_core_hnd_Ev* _con_x1488 = kk_std_core_hnd__as_Ev(evx_10848, _ctx);
      kk_box_t _box_x603 = _con_x1488->hnd;
      int32_t m = _con_x1488->marker;
      kk_nagare_io_file__effect__fileWrite h_1 = kk_nagare_io_file__effect__fileWrite_unbox(_box_x603, KK_BORROWED, _ctx);
      kk_nagare_io_file__effect__fileWrite_dup(h_1, _ctx);
      kk_std_core_hnd__clause2 _match_x1010;
      kk_std_core_hnd__clause2 _brw_x1011 = kk_nagare_io_file__effect_writeChunk_fs__select(h_1, _ctx); /*hnd/clause2<nagare/io/file_effect/write-handle,string,int,nagare/io/file_effect/fileWrite,1536,1537>*/;
      kk_datatype_ptr_dropn(h_1, (KK_I32(5)), _ctx);
      _match_x1010 = _brw_x1011; /*hnd/clause2<nagare/io/file_effect/write-handle,string,int,nagare/io/file_effect/fileWrite,1536,1537>*/
      {
        kk_function_t _fun_unbox_x608 = _match_x1010.clause;
        _x_x1487 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_box_t, kk_context_t*), _fun_unbox_x608, (_fun_unbox_x608, m, evx_10848, kk_nagare_io_file__effect__write_handle_box(h_0, _ctx), kk_string_box(_uniq_x_10182), _ctx), _ctx); /*10016*/
      }
    }
    y = kk_integer_unbox(_x_x1487, _ctx); /*int*/
    kk_evv_set(w,kk_context());
    kk_integer_t x_10841;
    if (kk_yielding(kk_context())) {
      kk_integer_drop(y, _ctx);
      kk_box_t _x_x1489 = kk_std_core_hnd_yield_cont(kk_nagare_io_file__new_lift_unroll_writeAllChunks_10003_10372_fun1490(i_10844, _ctx), _ctx); /*10002*/
      x_10841 = kk_integer_unbox(_x_x1489, _ctx); /*int*/
    }
    else {
      x_10841 = y; /*int*/
    }
    kk_integer_drop(x_10841, _ctx);
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x1491 = kk_std_core_hnd_yield_extend(kk_nagare_io_file__new_lift_unroll_writeAllChunks_10003_10372_fun1492(_uniq_xx_10183_0, h_0, _ctx), _ctx); /*10001*/
      kk_unit_unbox(_x_x1491); return kk_Unit;
    }
    { // tailcall
      _uniq_xs_10179 = _uniq_xx_10183_0;
      goto kk__tailcall;
    }
  }
  {
    kk_Unit; return kk_Unit;
  }
}
 
// lifted local: @unroll-writeAllChunks@10003, @spec-x10178
// specialized: std/core/list/foreach, on parameters @uniq-action@10175, using:
// @uniq-action@10175 = fn<<(nagare/io/file_effect/fileWrite :: (E, V) -> V),(alloc :: H -> X)<(global :: H)>,(console/console :: X),(div :: X),(exn :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>>>(s: string){
//   val _ : int
//         = std/core/types/@open<(nagare/io/file_effect/fileWrite :: (E, V) -> V),<(nagare/io/file_effect/fileWrite :: (E, V) -> V),(alloc :: H -> X)<(global :: H)>,(console/console :: X),(div :: X),(exn :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>>,(h : nagare/io/file_effect/write-handle, content : string) -> (nagare/io/file_effect/fileWrite :: (E, V) -> V) int,(h : nagare/io/file_effect/write-handle, content : string) -> <(nagare/io/file_effect/fileWrite :: (E, V) -> V),(alloc :: H -> X)<(global :: H)>,(console/console :: X),(div :: X),(exn :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>> int>((fn<(nagare/io/file_effect/fileWrite :: (E, V) -> V)>(h@0: nagare/io/file_effect/write-handle, content: string){
//           (std/core/hnd/@perform2<nagare/io/file_effect/write-handle,string,int,(nagare/io/file_effect/fileWrite :: (E, V) -> V),(nagare/io/file_effect/fileWrite :: (E, V) -> V)>((std/core/types/@open<(total :: E),(nagare/io/file_effect/fileWrite :: (E, V) -> V),(i : hnd/ev-index) -> (hnd/ev :: ((E, V) -> V) -> V)<(nagare/io/file_effect/fileWrite :: (E, V) -> V)>,(i : hnd/ev-index) -> (nagare/io/file_effect/fileWrite :: (E, V) -> V) (hnd/ev :: ((E, V) -> V) -> V)<(nagare/io/file_effect/fileWrite :: (E, V) -> V)>>((std/core/hnd/@evv-at<(nagare/io/file_effect/fileWrite :: (E, V) -> V)>))((std/core/types/@open<(total :: E),(nagare/io/file_effect/fileWrite :: (E, V) -> V),(i : int) -> ssize_t,(i : int) -> (nagare/io/file_effect/fileWrite :: (E, V) -> V) ssize_t>(std/core/types/@make-ssize_t)(0)))), nagare/io/file_effect/writeChunk/@select, h@0, content));
//         }))(h, s);
//   std/core/types/Unit;
// }

kk_unit_t kk_nagare_io_file__lift_unroll_writeAllChunks_10003_10371(kk_nagare_io_file__effect__write_handle h, kk_std_core_types__list _uniq_xs_10174, kk_context_t* _ctx) { /* (h : nagare/io/file_effect/write-handle, list<string>) -> <nagare/io/file_effect/fileWrite,alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> () */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10174, _ctx)) {
    kk_Unit; return kk_Unit;
  }
  {
    kk_nagare_io_file__lift_unroll_writeAllChunks_10003_10372(h, _uniq_xs_10174, _ctx); return kk_Unit;
  }
}
 
// monadic lift

kk_unit_t kk_nagare_io_file__mlift_unroll_writeAllChunks_10003_10674(kk_nagare_io_file__effect__write_handle h, kk_nagare_core_types__pull tail, kk_unit_t wild___0, kk_context_t* _ctx) { /* (h : nagare/io/file_effect/write-handle, tail : nagare/core/types/pull<string,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>>>, wild_@0 : ()) -> <nagare/io/file_effect/fileWrite,alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> () */ 
  kk_nagare_io_file__unroll_writeAllChunks_10003(tail, h, _ctx); return kk_Unit;
}
 
// monadic lift

kk_unit_t kk_nagare_io_file__mlift_unroll_writeAllChunks_10003_10675(kk_nagare_io_file__effect__write_handle h_0, kk_nagare_core_types__pull _y_x10501, kk_context_t* _ctx) { /* (h : nagare/io/file_effect/write-handle, nagare/core/types/pull<string,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>>>) -> <alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>> () */ 
  kk_nagare_io_file__unroll_writeAllChunks_10003(_y_x10501, h_0, _ctx); return kk_Unit;
}
 
// monadic lift

kk_unit_t kk_nagare_io_file__mlift_unroll_writeAllChunks_10003_10676(kk_nagare_io_file__effect__write_handle h_1, kk_function_t release, kk_nagare_core_types__pull tail_0, kk_unit_t wild___1, kk_context_t* _ctx) { /* (h : nagare/io/file_effect/write-handle, release : () -> <alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>> (), tail@0 : nagare/core/types/pull<string,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>>>, wild_@1 : ()) -> <alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>> () */ 
  kk_unit_t _b_x633_635 = kk_Unit;
  kk_nagare_io_file__unroll_writeAllChunks_10003(tail_0, h_1, _ctx);
  kk_box_t _x_x1494 = kk_std_core_hnd_finally_prompt(release, kk_unit_box(_b_x633_635), _ctx); /*10000*/
  kk_unit_unbox(_x_x1494); return kk_Unit;
}
 
// Drain the source pull, writing every emitted string to the handle.
// We let the outer runtime handle PAcquire bookkeeping when possible; here
// we simply run acquire/release inline around the recursive call.


// lift anonymous function
struct kk_nagare_io_file__unroll_writeAllChunks_10003_fun1497__t {
  struct kk_function_s _base;
  kk_nagare_core_types__pull tail_1;
  kk_nagare_io_file__effect__write_handle h_2;
};
static kk_box_t kk_nagare_io_file__unroll_writeAllChunks_10003_fun1497(kk_function_t _fself, kk_box_t _b_x637, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__new_unroll_writeAllChunks_10003_fun1497(kk_nagare_core_types__pull tail_1, kk_nagare_io_file__effect__write_handle h_2, kk_context_t* _ctx) {
  struct kk_nagare_io_file__unroll_writeAllChunks_10003_fun1497__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__unroll_writeAllChunks_10003_fun1497__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__unroll_writeAllChunks_10003_fun1497, kk_context());
  _self->tail_1 = tail_1;
  _self->h_2 = h_2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file__unroll_writeAllChunks_10003_fun1497(kk_function_t _fself, kk_box_t _b_x637, kk_context_t* _ctx) {
  struct kk_nagare_io_file__unroll_writeAllChunks_10003_fun1497__t* _self = kk_function_as(struct kk_nagare_io_file__unroll_writeAllChunks_10003_fun1497__t*, _fself, _ctx);
  kk_nagare_core_types__pull tail_1 = _self->tail_1; /* nagare/core/types/pull<string,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>>> */
  kk_nagare_io_file__effect__write_handle h_2 = _self->h_2; /* nagare/io/file_effect/write-handle */
  kk_drop_match(_self, {kk_nagare_core_types__pull_dup(tail_1, _ctx);kk_nagare_io_file__effect__write_handle_dup(h_2, _ctx);}, {}, _ctx)
  kk_unit_t wild___0_0_649 = kk_Unit;
  kk_unit_unbox(_b_x637);
  kk_unit_t _x_x1498 = kk_Unit;
  kk_nagare_io_file__mlift_unroll_writeAllChunks_10003_10674(h_2, tail_1, wild___0_0_649, _ctx);
  return kk_unit_box(_x_x1498);
}


// lift anonymous function
struct kk_nagare_io_file__unroll_writeAllChunks_10003_fun1501__t {
  struct kk_function_s _base;
  kk_nagare_io_file__effect__write_handle h_2;
};
static kk_box_t kk_nagare_io_file__unroll_writeAllChunks_10003_fun1501(kk_function_t _fself, kk_box_t _b_x639, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__new_unroll_writeAllChunks_10003_fun1501(kk_nagare_io_file__effect__write_handle h_2, kk_context_t* _ctx) {
  struct kk_nagare_io_file__unroll_writeAllChunks_10003_fun1501__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__unroll_writeAllChunks_10003_fun1501__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__unroll_writeAllChunks_10003_fun1501, kk_context());
  _self->h_2 = h_2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file__unroll_writeAllChunks_10003_fun1501(kk_function_t _fself, kk_box_t _b_x639, kk_context_t* _ctx) {
  struct kk_nagare_io_file__unroll_writeAllChunks_10003_fun1501__t* _self = kk_function_as(struct kk_nagare_io_file__unroll_writeAllChunks_10003_fun1501__t*, _fself, _ctx);
  kk_nagare_io_file__effect__write_handle h_2 = _self->h_2; /* nagare/io/file_effect/write-handle */
  kk_drop_match(_self, {kk_nagare_io_file__effect__write_handle_dup(h_2, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull _y_x10501_0_650 = kk_nagare_core_types__pull_unbox(_b_x639, KK_OWNED, _ctx); /*nagare/core/types/pull<string,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_unit_t _x_x1502 = kk_Unit;
  kk_nagare_io_file__mlift_unroll_writeAllChunks_10003_10675(h_2, _y_x10501_0_650, _ctx);
  return kk_unit_box(_x_x1502);
}


// lift anonymous function
struct kk_nagare_io_file__unroll_writeAllChunks_10003_fun1505__t {
  struct kk_function_s _base;
  kk_function_t release_0;
  kk_nagare_core_types__pull tail_0_0;
  kk_nagare_io_file__effect__write_handle h_2;
};
static kk_box_t kk_nagare_io_file__unroll_writeAllChunks_10003_fun1505(kk_function_t _fself, kk_box_t _b_x641, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__new_unroll_writeAllChunks_10003_fun1505(kk_function_t release_0, kk_nagare_core_types__pull tail_0_0, kk_nagare_io_file__effect__write_handle h_2, kk_context_t* _ctx) {
  struct kk_nagare_io_file__unroll_writeAllChunks_10003_fun1505__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__unroll_writeAllChunks_10003_fun1505__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__unroll_writeAllChunks_10003_fun1505, kk_context());
  _self->release_0 = release_0;
  _self->tail_0_0 = tail_0_0;
  _self->h_2 = h_2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file__unroll_writeAllChunks_10003_fun1505(kk_function_t _fself, kk_box_t _b_x641, kk_context_t* _ctx) {
  struct kk_nagare_io_file__unroll_writeAllChunks_10003_fun1505__t* _self = kk_function_as(struct kk_nagare_io_file__unroll_writeAllChunks_10003_fun1505__t*, _fself, _ctx);
  kk_function_t release_0 = _self->release_0; /* () -> <alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>> () */
  kk_nagare_core_types__pull tail_0_0 = _self->tail_0_0; /* nagare/core/types/pull<string,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>>> */
  kk_nagare_io_file__effect__write_handle h_2 = _self->h_2; /* nagare/io/file_effect/write-handle */
  kk_drop_match(_self, {kk_function_dup(release_0, _ctx);kk_nagare_core_types__pull_dup(tail_0_0, _ctx);kk_nagare_io_file__effect__write_handle_dup(h_2, _ctx);}, {}, _ctx)
  kk_unit_t wild___1_0_651 = kk_Unit;
  kk_unit_unbox(_b_x641);
  kk_unit_t _x_x1506 = kk_Unit;
  kk_nagare_io_file__mlift_unroll_writeAllChunks_10003_10676(h_2, release_0, tail_0_0, wild___1_0_651, _ctx);
  return kk_unit_box(_x_x1506);
}

kk_unit_t kk_nagare_io_file__unroll_writeAllChunks_10003(kk_nagare_core_types__pull source, kk_nagare_io_file__effect__write_handle h_2, kk_context_t* _ctx) { /* (source : nagare/core/types/pull<string,<nagare/io/file_effect/fileWrite|io>>, h : nagare/io/file_effect/write-handle) -> <io,nagare/io/file_effect/fileWrite> () */ 
  kk__tailcall: ;
  if (kk_nagare_core_types__is_PDone(source, _ctx)) {
    kk_Unit; return kk_Unit;
  }
  if (kk_nagare_core_types__is_POutput(source, _ctx)) {
    struct kk_nagare_core_types_POutput* _con_x1495 = kk_nagare_core_types__as_POutput(source, _ctx);
    kk_nagare_core_types__chunk out = _con_x1495->out;
    kk_nagare_core_types__pull tail_1 = _con_x1495->tail;
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
      kk_unit_t x_10854 = kk_Unit;
      kk_nagare_io_file__lift_unroll_writeAllChunks_10003_10371(h_2, values, _ctx);
      if (kk_yielding(kk_context())) {
        kk_box_t _x_x1496 = kk_std_core_hnd_yield_extend(kk_nagare_io_file__new_unroll_writeAllChunks_10003_fun1497(tail_1, h_2, _ctx), _ctx); /*10001*/
        kk_unit_unbox(_x_x1496); return kk_Unit;
      }
      { // tailcall
        source = tail_1;
        goto kk__tailcall;
      }
    }
  }
  if (kk_nagare_core_types__is_PEval(source, _ctx)) {
    struct kk_nagare_core_types_PEval* _con_x1499 = kk_nagare_core_types__as_PEval(source, _ctx);
    kk_function_t next_0 = _con_x1499->next;
    if kk_likely(kk_datatype_ptr_is_unique(source, _ctx)) {
      kk_datatype_ptr_free(source, _ctx);
    }
    else {
      kk_function_dup(next_0, _ctx);
      kk_datatype_ptr_decref(source, _ctx);
    }
    kk_nagare_core_types__pull x_0_10857 = kk_function_call(kk_nagare_core_types__pull, (kk_function_t, kk_context_t*), next_0, (next_0, _ctx), _ctx); /*nagare/core/types/pull<string,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>>>*/;
    if (kk_yielding(kk_context())) {
      kk_nagare_core_types__pull_drop(x_0_10857, _ctx);
      kk_box_t _x_x1500 = kk_std_core_hnd_yield_extend(kk_nagare_io_file__new_unroll_writeAllChunks_10003_fun1501(h_2, _ctx), _ctx); /*10001*/
      kk_unit_unbox(_x_x1500); return kk_Unit;
    }
    { // tailcall
      source = x_0_10857;
      goto kk__tailcall;
    }
  }
  {
    struct kk_nagare_core_types_PAcquire* _con_x1503 = kk_nagare_core_types__as_PAcquire(source, _ctx);
    kk_function_t acquire = _con_x1503->acquire;
    kk_function_t release_0 = _con_x1503->release;
    kk_nagare_core_types__pull tail_0_0 = _con_x1503->tail;
    if kk_likely(kk_datatype_ptr_is_unique(source, _ctx)) {
      kk_datatype_ptr_free(source, _ctx);
    }
    else {
      kk_function_dup(acquire, _ctx);
      kk_function_dup(release_0, _ctx);
      kk_nagare_core_types__pull_dup(tail_0_0, _ctx);
      kk_datatype_ptr_decref(source, _ctx);
    }
    kk_unit_t x_1_10860 = kk_Unit;
    kk_function_call(kk_unit_t, (kk_function_t, kk_context_t*), acquire, (acquire, _ctx), _ctx);
    if (kk_yielding(kk_context())) {
      kk_box_t _x_x1504 = kk_std_core_hnd_yield_extend(kk_nagare_io_file__new_unroll_writeAllChunks_10003_fun1505(release_0, tail_0_0, h_2, _ctx), _ctx); /*10001*/
      kk_unit_unbox(_x_x1504); return kk_Unit;
    }
    {
      kk_unit_t _b_x643_648 = kk_Unit;
      kk_nagare_io_file__unroll_writeAllChunks_10003(tail_0_0, h_2, _ctx);
      kk_box_t _x_x1507 = kk_std_core_hnd_finally_prompt(release_0, kk_unit_box(_b_x643_648), _ctx); /*10000*/
      kk_unit_unbox(_x_x1507); return kk_Unit;
    }
  }
}
 
// Write a stream of string chunks to a file.


// lift anonymous function
struct kk_nagare_io_file_writeAll_fun1510__t {
  struct kk_function_s _base;
  kk_std_os_path__path filepath;
};
static kk_nagare_core_types__nstream kk_nagare_io_file_writeAll_fun1510(kk_function_t _fself, kk_nagare_core_types__nstream source, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_writeAll_fun1510(kk_std_os_path__path filepath, kk_context_t* _ctx) {
  struct kk_nagare_io_file_writeAll_fun1510__t* _self = kk_function_alloc_as(struct kk_nagare_io_file_writeAll_fun1510__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file_writeAll_fun1510, kk_context());
  _self->filepath = filepath;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_io_file_writeAll_fun1512__t {
  struct kk_function_s _base;
  kk_std_os_path__path filepath;
  kk_nagare_core_types__nstream source;
};
static kk_nagare_core_types__pull kk_nagare_io_file_writeAll_fun1512(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_writeAll_fun1512(kk_std_os_path__path filepath, kk_nagare_core_types__nstream source, kk_context_t* _ctx) {
  struct kk_nagare_io_file_writeAll_fun1512__t* _self = kk_function_alloc_as(struct kk_nagare_io_file_writeAll_fun1512__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file_writeAll_fun1512, kk_context());
  _self->filepath = filepath;
  _self->source = source;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_io_file_writeAll_fun1514__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_io_file_writeAll_fun1514(kk_function_t _fself, kk_box_t _b_x658, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_writeAll_fun1514(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file_writeAll_fun1514, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_io_file_writeAll_fun1514(kk_function_t _fself, kk_box_t _b_x658, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1515;
  kk_std_os_path__path _x_x1516 = kk_std_os_path__path_unbox(_b_x658, KK_OWNED, _ctx); /*std/os/path/path*/
  _x_x1515 = kk_std_os_path_string(_x_x1516, _ctx); /*string*/
  return kk_string_box(_x_x1515);
}


// lift anonymous function
struct kk_nagare_io_file_writeAll_fun1518__t {
  struct kk_function_s _base;
  kk_nagare_core_types__nstream source;
};
static kk_box_t kk_nagare_io_file_writeAll_fun1518(kk_function_t _fself, kk_nagare_io_file__effect__write_handle _b_x665, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_writeAll_fun1518(kk_nagare_core_types__nstream source, kk_context_t* _ctx) {
  struct kk_nagare_io_file_writeAll_fun1518__t* _self = kk_function_alloc_as(struct kk_nagare_io_file_writeAll_fun1518__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file_writeAll_fun1518, kk_context());
  _self->source = source;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_io_file_writeAll_fun1522__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_io_file_writeAll_fun1522(kk_function_t _fself, kk_box_t _b_x660, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_writeAll_fun1522(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file_writeAll_fun1522, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_io_file_writeAll_fun1522(kk_function_t _fself, kk_box_t _b_x660, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_nagare_core_types__pull _x_x1523;
  kk_unit_t _x_x1524 = kk_Unit;
  kk_unit_unbox(_b_x660);
  _x_x1523 = kk_nagare_io_file__mlift_writeAll_10677(_x_x1524, _ctx); /*nagare/core/types/pull<(),<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>>>*/
  return kk_nagare_core_types__pull_box(_x_x1523, _ctx);
}
static kk_box_t kk_nagare_io_file_writeAll_fun1518(kk_function_t _fself, kk_nagare_io_file__effect__write_handle _b_x665, kk_context_t* _ctx) {
  struct kk_nagare_io_file_writeAll_fun1518__t* _self = kk_function_as(struct kk_nagare_io_file_writeAll_fun1518__t*, _fself, _ctx);
  kk_nagare_core_types__nstream source = _self->source; /* nagare/core/types/nstream<string,<nagare/io/file_effect/fileWrite|io>> */
  kk_drop_match(_self, {kk_nagare_core_types__nstream_dup(source, _ctx);}, {}, _ctx)
  kk_nagare_io_file__effect__write_handle h_673 = _b_x665; /*nagare/io/file_effect/write-handle*/;
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  kk_unit_t x_0_10867 = kk_Unit;
  {
    kk_nagare_core_types__pull step = source.step;
    kk_nagare_core_types__pull_dup(step, _ctx);
    if (kk_nagare_core_types__is_PDone(step, _ctx)) {
      kk_nagare_core_types__nstream_drop(source, _ctx);
    }
    else {
      kk_nagare_core_types__pull_drop(step, _ctx);
      kk_nagare_core_types__pull _x_x1519;
      {
        kk_nagare_core_types__pull step_0 = source.step;
        _x_x1519 = step_0; /*nagare/core/types/pull<string,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>>>*/
      }
      kk_nagare_io_file__unroll_writeAllChunks_10003(_x_x1519, h_673, _ctx);
    }
  }
  kk_nagare_core_types__pull _x_x1520;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1521 = kk_std_core_hnd_yield_extend(kk_nagare_io_file_new_writeAll_fun1522(_ctx), _ctx); /*10001*/
    _x_x1520 = kk_nagare_core_types__pull_unbox(_x_x1521, KK_OWNED, _ctx); /*nagare/core/types/pull<(),<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>>>*/
  }
  else {
    kk_unit_t _b_x661_671 = kk_Unit;
    kk_std_core_types__list _b_x662_672 = kk_std_core_types__new_Nil(_ctx); /*list<()>*/;
    kk_nagare_core_types__chunk _x_x1525;
    kk_std_core_types__list _x_x1526 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_unit_box(_b_x661_671), _b_x662_672, _ctx); /*list<10021>*/
    _x_x1525 = kk_nagare_core_types__new_Chunk(_x_x1526, _ctx); /*nagare/core/types/chunk<4>*/
    _x_x1520 = kk_nagare_core_types__new_POutput(kk_reuse_null, 0, _x_x1525, kk_nagare_core_types__new_PDone(_ctx), _ctx); /*nagare/core/types/pull<(),<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>>>*/
  }
  return kk_nagare_core_types__pull_box(_x_x1520, _ctx);
}
static kk_nagare_core_types__pull kk_nagare_io_file_writeAll_fun1512(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_io_file_writeAll_fun1512__t* _self = kk_function_as(struct kk_nagare_io_file_writeAll_fun1512__t*, _fself, _ctx);
  kk_std_os_path__path filepath = _self->filepath; /* std/os/path/path */
  kk_nagare_core_types__nstream source = _self->source; /* nagare/core/types/nstream<string,<nagare/io/file_effect/fileWrite|io>> */
  kk_drop_match(_self, {kk_std_os_path__path_dup(filepath, _ctx);kk_nagare_core_types__nstream_dup(source, _ctx);}, {}, _ctx)
  kk_string_t _b_x663_666;
  kk_box_t _x_x1513 = kk_std_core_hnd__open_none1(kk_nagare_io_file_new_writeAll_fun1514(_ctx), kk_std_os_path__path_box(filepath, _ctx), _ctx); /*10001*/
  _b_x663_666 = kk_string_unbox(_x_x1513); /*string*/
  kk_box_t _x_x1517 = kk_nagare_io_file__effect_with_write_file(_b_x663_666, kk_nagare_io_file_new_writeAll_fun1518(source, _ctx), _ctx); /*2199*/
  return kk_nagare_core_types__pull_unbox(_x_x1517, KK_OWNED, _ctx);
}
static kk_nagare_core_types__nstream kk_nagare_io_file_writeAll_fun1510(kk_function_t _fself, kk_nagare_core_types__nstream source, kk_context_t* _ctx) {
  struct kk_nagare_io_file_writeAll_fun1510__t* _self = kk_function_as(struct kk_nagare_io_file_writeAll_fun1510__t*, _fself, _ctx);
  kk_std_os_path__path filepath = _self->filepath; /* std/os/path/path */
  kk_drop_match(_self, {kk_std_os_path__path_dup(filepath, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull _x_x1511 = kk_nagare_core_types__new_PEval(kk_reuse_null, 0, kk_nagare_io_file_new_writeAll_fun1512(filepath, source, _ctx), _ctx); /*nagare/core/types/pull<19,20>*/
  return kk_nagare_core_types__new_Stream(_x_x1511, _ctx);
}

kk_function_t kk_nagare_io_file_writeAll(kk_std_os_path__path filepath, kk_context_t* _ctx) { /* (filepath : std/os/path/path) -> nagare/io/file_effect/writePipe<string,()> */ 
  return kk_nagare_io_file_new_writeAll_fun1510(filepath, _ctx);
}
 
// lifted local: @lift-writeLines@10376, @lift-writeLines@10375, @lift-writeLines@10374, @lift-writeLines@10373, writeLines, @spec-x10223
// specialized: std/core/list/@unroll-map@10010, on parameters @uniq-f@10218, using:
// @uniq-f@10218 = fn(line: string){
//   std/core/types/(++)(line, "\x0A");
// }

kk_std_core_types__list kk_nagare_io_file__trmc_lift_writeLines_10377(kk_std_core_types__list _uniq_xs_10217, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* (list<string>, ctx<list<string>>) -> list<string> */ 
  if (kk_std_core_types__is_Cons(_uniq_xs_10217, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1527 = kk_std_core_types__as_Cons(_uniq_xs_10217, _ctx);
    kk_box_t _box_x674 = _con_x1527->head;
    kk_std_core_types__list _uniq_xx_10221 = _con_x1527->tail;
    kk_string_t _uniq_x_10220 = kk_string_unbox(_box_x674);
    kk_reuse_t _ru_x1116 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10217, _ctx)) {
      _ru_x1116 = (kk_datatype_ptr_reuse(_uniq_xs_10217, _ctx));
    }
    else {
      kk_string_dup(_uniq_x_10220, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10221, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10217, _ctx);
    }
    kk_string_t _trmc_x10410;
    kk_string_t _x_x1528;
    kk_define_string_literal(static, _s_x1529, 1, "\n", _ctx)
    _x_x1528 = kk_string_dup(_s_x1529, _ctx); /*string*/
    _trmc_x10410 = kk_std_core_types__lp__plus__plus__rp_(_uniq_x_10220, _x_x1528, _ctx); /*string*/
    kk_std_core_types__list _trmc_x10411 = kk_datatype_null(); /*list<string>*/;
    kk_std_core_types__list _trmc_x10412 = kk_std_core_types__new_Cons(_ru_x1116, 0, kk_string_box(_trmc_x10410), _trmc_x10411, _ctx); /*list<string>*/;
    kk_field_addr_t _b_x684_689 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10412, _ctx)->tail, _ctx); /*@field-addr<list<string>>*/;
    kk_std_core_types__cctx _brw_x1002;
    kk_std_core_types__cctx _x_x1530 = kk_std_core_types__cctx_dup(_acc, _ctx); /*ctx<list<string>>*/
    _brw_x1002 = kk_cctx_extend_linear(_x_x1530,(kk_std_core_types__list_box(_trmc_x10412, _ctx)),_b_x684_689,kk_context()); /*ctx<0>*/
    kk_std_core_types__list _brw_x1003 = kk_nagare_io_file__trmc_lift_writeLines_10377(_uniq_xx_10221, _brw_x1002, _ctx); /*list<string>*/;
    kk_std_core_types__cctx_drop(_brw_x1002, _ctx);
    return _brw_x1003;
  }
  {
    kk_box_t _x_x1531;
    kk_std_core_types__cctx _x_x1532 = kk_std_core_types__cctx_dup(_acc, _ctx); /*ctx<list<string>>*/
    _x_x1531 = kk_cctx_apply_linear(_x_x1532,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1531, KK_OWNED, _ctx);
  }
}
 
// lifted local: @lift-writeLines@10376, @lift-writeLines@10375, @lift-writeLines@10374, @lift-writeLines@10373, writeLines, @spec-x10223
// specialized: std/core/list/@unroll-map@10010, on parameters @uniq-f@10218, using:
// @uniq-f@10218 = fn(line: string){
//   std/core/types/(++)(line, "\x0A");
// }

kk_std_core_types__list kk_nagare_io_file__lift_writeLines_10377(kk_std_core_types__list _uniq_xs_10217_0, kk_context_t* _ctx) { /* (list<string>) -> list<string> */ 
  kk_std_core_types__cctx _brw_x1000 = kk_cctx_empty(kk_context()); /*ctx<0>*/;
  kk_std_core_types__list _brw_x1001 = kk_nagare_io_file__trmc_lift_writeLines_10377(_uniq_xs_10217_0, _brw_x1000, _ctx); /*list<string>*/;
  kk_std_core_types__cctx_drop(_brw_x1000, _ctx);
  return _brw_x1001;
}
 
// lifted local: @lift-writeLines@10375, @lift-writeLines@10374, @lift-writeLines@10373, writeLines, @spec-x10216
// specialized: std/core/list/map, on parameters @uniq-f@10213, using:
// @uniq-f@10213 = fn(line: string){
//   std/core/types/(++)(line, "\x0A");
// }

kk_std_core_types__list kk_nagare_io_file__lift_writeLines_10376(kk_std_core_types__list _uniq_xs_10212, kk_context_t* _ctx) { /* (list<string>) -> list<string> */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10212, _ctx)) {
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    kk_std_core_types__cctx _brw_x998 = kk_cctx_empty(kk_context()); /*ctx<0>*/;
    kk_std_core_types__list _brw_x999 = kk_nagare_io_file__trmc_lift_writeLines_10377(_uniq_xs_10212, _brw_x998, _ctx); /*list<string>*/;
    kk_std_core_types__cctx_drop(_brw_x998, _ctx);
    return _brw_x999;
  }
}
 
// monadic lift


// lift anonymous function
struct kk_nagare_io_file__mlift_trmc_lift_writeLines_10375_10678_fun1533__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_io_file__mlift_trmc_lift_writeLines_10375_10678_fun1533(kk_function_t _fself, kk_box_t _b_x697, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__new_mlift_trmc_lift_writeLines_10375_10678_fun1533(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file__mlift_trmc_lift_writeLines_10375_10678_fun1533, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_io_file__mlift_trmc_lift_writeLines_10375_10678_fun1533(kk_function_t _fself, kk_box_t _b_x697, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1534;
  kk_string_t _x_x1535 = kk_string_unbox(_b_x697); /*string*/
  kk_string_t _x_x1536;
  kk_define_string_literal(static, _s_x1537, 1, "\n", _ctx)
  _x_x1536 = kk_string_dup(_s_x1537, _ctx); /*string*/
  _x_x1534 = kk_std_core_types__lp__plus__plus__rp_(_x_x1535, _x_x1536, _ctx); /*string*/
  return kk_string_box(_x_x1534);
}

kk_nagare_core_types__pull kk_nagare_io_file__mlift_trmc_lift_writeLines_10375_10678(kk_nagare_core_types__pull _y_x10512, kk_context_t* _ctx) { /* (nagare/core/types/pull<string,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>>>) -> <alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>> nagare/core/types/pull<string,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>>> */ 
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_nagare_core_types__pull x = kk_nagare_core_pull__unroll_pullMap_10008(_y_x10512, kk_nagare_io_file__new_mlift_trmc_lift_writeLines_10375_10678_fun1533(_ctx), _ctx); /*nagare/core/types/pull<string,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  return x;
}
 
// lifted local: @lift-writeLines@10374, @lift-writeLines@10373, writeLines, @spec-x10211
// specialized: nagare/core/pull/@unroll-pullMap@10008, on parameters @uniq-f@10198, using:
// @uniq-f@10198 = fn(line: string){
//   std/core/types/(++)(line, "\x0A");
// }


// lift anonymous function
struct kk_nagare_io_file__trmc_lift_writeLines_10375_fun1546__t {
  struct kk_function_s _base;
  kk_function_t _uniq_next_10206;
};
static kk_nagare_core_types__pull kk_nagare_io_file__trmc_lift_writeLines_10375_fun1546(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__new_trmc_lift_writeLines_10375_fun1546(kk_function_t _uniq_next_10206, kk_context_t* _ctx) {
  struct kk_nagare_io_file__trmc_lift_writeLines_10375_fun1546__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__trmc_lift_writeLines_10375_fun1546__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__trmc_lift_writeLines_10375_fun1546, kk_context());
  _self->_uniq_next_10206 = _uniq_next_10206;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_io_file__trmc_lift_writeLines_10375_fun1548__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_io_file__trmc_lift_writeLines_10375_fun1548(kk_function_t _fself, kk_box_t _b_x710, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__new_trmc_lift_writeLines_10375_fun1548(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file__trmc_lift_writeLines_10375_fun1548, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_io_file__trmc_lift_writeLines_10375_fun1548(kk_function_t _fself, kk_box_t _b_x710, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_nagare_core_types__pull _x_x1549;
  kk_nagare_core_types__pull _x_x1550 = kk_nagare_core_types__pull_unbox(_b_x710, KK_OWNED, _ctx); /*nagare/core/types/pull<string,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>>>*/
  _x_x1549 = kk_nagare_io_file__mlift_trmc_lift_writeLines_10375_10678(_x_x1550, _ctx); /*nagare/core/types/pull<string,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>>>*/
  return kk_nagare_core_types__pull_box(_x_x1549, _ctx);
}
static kk_nagare_core_types__pull kk_nagare_io_file__trmc_lift_writeLines_10375_fun1546(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_io_file__trmc_lift_writeLines_10375_fun1546__t* _self = kk_function_as(struct kk_nagare_io_file__trmc_lift_writeLines_10375_fun1546__t*, _fself, _ctx);
  kk_function_t _uniq_next_10206 = _self->_uniq_next_10206; /* () -> <alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>> nagare/core/types/pull<string,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>>> */
  kk_drop_match(_self, {kk_function_dup(_uniq_next_10206, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull x_0_10873 = kk_function_call(kk_nagare_core_types__pull, (kk_function_t, kk_context_t*), _uniq_next_10206, (_uniq_next_10206, _ctx), _ctx); /*nagare/core/types/pull<string,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  if (kk_yielding(kk_context())) {
    kk_nagare_core_types__pull_drop(x_0_10873, _ctx);
    kk_box_t _x_x1547 = kk_std_core_hnd_yield_extend(kk_nagare_io_file__new_trmc_lift_writeLines_10375_fun1548(_ctx), _ctx); /*10001*/
    return kk_nagare_core_types__pull_unbox(_x_x1547, KK_OWNED, _ctx);
  }
  {
    return kk_nagare_io_file__mlift_trmc_lift_writeLines_10375_10678(x_0_10873, _ctx);
  }
}

kk_nagare_core_types__pull kk_nagare_io_file__trmc_lift_writeLines_10375(kk_nagare_core_types__pull _uniq_source_10197, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* (nagare/core/types/pull<string,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>>>, ctx<nagare/core/types/pull<string,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>>>>) -> nagare/core/types/pull<string,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>>> */ 
  kk__tailcall: ;
  if (kk_nagare_core_types__is_PDone(_uniq_source_10197, _ctx)) {
    kk_box_t _x_x1538 = kk_cctx_apply_linear(_acc,(kk_nagare_core_types__pull_box(kk_nagare_core_types__new_PDone(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_nagare_core_types__pull_unbox(_x_x1538, KK_OWNED, _ctx);
  }
  if (kk_nagare_core_types__is_POutput(_uniq_source_10197, _ctx)) {
    struct kk_nagare_core_types_POutput* _con_x1539 = kk_nagare_core_types__as_POutput(_uniq_source_10197, _ctx);
    kk_nagare_core_types__chunk _uniq_out_10201 = _con_x1539->out;
    kk_nagare_core_types__pull _uniq_tail_10202 = _con_x1539->tail;
    kk_reuse_t _ru_x1117 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_source_10197, _ctx)) {
      _ru_x1117 = (kk_datatype_ptr_reuse(_uniq_source_10197, _ctx));
    }
    else {
      kk_nagare_core_types__chunk_dup(_uniq_out_10201, _ctx);
      kk_nagare_core_types__pull_dup(_uniq_tail_10202, _ctx);
      kk_datatype_ptr_decref(_uniq_source_10197, _ctx);
    }
    kk_nagare_core_types__chunk _trmc_x10413;
    {
      kk_std_core_types__list _uniq_values_10204 = _uniq_out_10201.values;
      kk_std_core_types__list _x_x1540 = kk_nagare_io_file__lift_writeLines_10376(_uniq_values_10204, _ctx); /*list<string>*/
      _trmc_x10413 = kk_nagare_core_types__new_Chunk(_x_x1540, _ctx); /*nagare/core/types/chunk<string>*/
    }
    kk_nagare_core_types__pull _trmc_x10414 = kk_datatype_null(); /*nagare/core/types/pull<string,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>>>*/;
    kk_nagare_core_types__pull _trmc_x10415 = kk_nagare_core_types__new_POutput(_ru_x1117, 0, _trmc_x10413, _trmc_x10414, _ctx); /*nagare/core/types/pull<string,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>>>*/;
    kk_field_addr_t _b_x708_723 = kk_field_addr_create(&kk_nagare_core_types__as_POutput(_trmc_x10415, _ctx)->tail, _ctx); /*@field-addr<nagare/core/types/pull<string,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>>>>*/;
    { // tailcall
      kk_std_core_types__cctx _x_x1541 = kk_cctx_extend_linear(_acc,(kk_nagare_core_types__pull_box(_trmc_x10415, _ctx)),_b_x708_723,kk_context()); /*ctx<0>*/
      _uniq_source_10197 = _uniq_tail_10202;
      _acc = _x_x1541;
      goto kk__tailcall;
    }
  }
  if (kk_nagare_core_types__is_PEval(_uniq_source_10197, _ctx)) {
    struct kk_nagare_core_types_PEval* _con_x1542 = kk_nagare_core_types__as_PEval(_uniq_source_10197, _ctx);
    kk_function_t _uniq_next_10206 = _con_x1542->next;
    kk_reuse_t _ru_x1118 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_source_10197, _ctx)) {
      _ru_x1118 = (kk_datatype_ptr_reuse(_uniq_source_10197, _ctx));
    }
    else {
      kk_function_dup(_uniq_next_10206, _ctx);
      kk_datatype_ptr_decref(_uniq_source_10197, _ctx);
    }
    kk_box_t _x_x1543;
    kk_box_t _x_x1544;
    kk_nagare_core_types__pull _x_x1545 = kk_nagare_core_types__new_PEval(_ru_x1118, 0, kk_nagare_io_file__new_trmc_lift_writeLines_10375_fun1546(_uniq_next_10206, _ctx), _ctx); /*nagare/core/types/pull<19,20>*/
    _x_x1544 = kk_nagare_core_types__pull_box(_x_x1545, _ctx); /*-1*/
    _x_x1543 = kk_cctx_apply_linear(_acc,_x_x1544,kk_context()); /*-1*/
    return kk_nagare_core_types__pull_unbox(_x_x1543, KK_OWNED, _ctx);
  }
  {
    struct kk_nagare_core_types_PAcquire* _con_x1551 = kk_nagare_core_types__as_PAcquire(_uniq_source_10197, _ctx);
    kk_function_t _uniq_acquire_10208 = _con_x1551->acquire;
    kk_function_t _uniq_release_10209 = _con_x1551->release;
    kk_nagare_core_types__pull _uniq_tail_0_10210 = _con_x1551->tail;
    kk_reuse_t _ru_x1119 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_source_10197, _ctx)) {
      _ru_x1119 = (kk_datatype_ptr_reuse(_uniq_source_10197, _ctx));
    }
    else {
      kk_function_dup(_uniq_acquire_10208, _ctx);
      kk_function_dup(_uniq_release_10209, _ctx);
      kk_nagare_core_types__pull_dup(_uniq_tail_0_10210, _ctx);
      kk_datatype_ptr_decref(_uniq_source_10197, _ctx);
    }
    kk_nagare_core_types__pull _trmc_x10416 = kk_datatype_null(); /*nagare/core/types/pull<string,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>>>*/;
    kk_nagare_core_types__pull _trmc_x10417 = kk_nagare_core_types__new_PAcquire(_ru_x1119, 0, _uniq_acquire_10208, _uniq_release_10209, _trmc_x10416, _ctx); /*nagare/core/types/pull<string,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>>>*/;
    kk_field_addr_t _b_x718_732 = kk_field_addr_create(&kk_nagare_core_types__as_PAcquire(_trmc_x10417, _ctx)->tail, _ctx); /*@field-addr<nagare/core/types/pull<string,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>>>>*/;
    { // tailcall
      kk_std_core_types__cctx _x_x1552 = kk_cctx_extend_linear(_acc,(kk_nagare_core_types__pull_box(_trmc_x10417, _ctx)),_b_x718_732,kk_context()); /*ctx<0>*/
      _uniq_source_10197 = _uniq_tail_0_10210;
      _acc = _x_x1552;
      goto kk__tailcall;
    }
  }
}
 
// lifted local: @lift-writeLines@10374, @lift-writeLines@10373, writeLines, @spec-x10211
// specialized: nagare/core/pull/@unroll-pullMap@10008, on parameters @uniq-f@10198, using:
// @uniq-f@10198 = fn(line: string){
//   std/core/types/(++)(line, "\x0A");
// }

kk_nagare_core_types__pull kk_nagare_io_file__lift_writeLines_10375(kk_nagare_core_types__pull _uniq_source_10197_0, kk_context_t* _ctx) { /* (nagare/core/types/pull<string,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>>>) -> nagare/core/types/pull<string,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>>> */ 
  kk_std_core_types__cctx _x_x1553 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_nagare_io_file__trmc_lift_writeLines_10375(_uniq_source_10197_0, _x_x1553, _ctx);
}
 
// lifted local: @lift-writeLines@10373, writeLines, @spec-x10196
// specialized: nagare/core/pull/pullMap, on parameters @uniq-f@10193, using:
// @uniq-f@10193 = fn(line: string){
//   std/core/types/(++)(line, "\x0A");
// }

kk_nagare_core_types__pull kk_nagare_io_file__lift_writeLines_10374(kk_nagare_core_types__pull _uniq_source_10192, kk_context_t* _ctx) { /* (nagare/core/types/pull<string,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>>>) -> nagare/core/types/pull<string,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>>> */ 
  if (kk_nagare_core_types__is_PDone(_uniq_source_10192, _ctx)) {
    return kk_nagare_core_types__new_PDone(_ctx);
  }
  {
    kk_std_core_types__cctx _x_x1554 = kk_cctx_empty(kk_context()); /*ctx<0>*/
    return kk_nagare_io_file__trmc_lift_writeLines_10375(_uniq_source_10192, _x_x1554, _ctx);
  }
}
 
// lifted local: writeLines, @spec-x10191
// specialized: nagare/core/stream/map, on parameters @uniq-f@10188, using:
// @uniq-f@10188 = fn(line: string){
//   std/core/types/(++)(line, "\x0A");
// }

kk_nagare_core_types__nstream kk_nagare_io_file__lift_writeLines_10373(kk_nagare_core_types__nstream _uniq_source_10187, kk_context_t* _ctx) { /* (nagare/core/types/nstream<string,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>>>) -> nagare/core/types/nstream<string,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>>> */ 
  {
    kk_nagare_core_types__pull _uniq_step_10190 = _uniq_source_10187.step;
    kk_nagare_core_types__pull _x_x1555 = kk_nagare_io_file__lift_writeLines_10374(_uniq_step_10190, _ctx); /*nagare/core/types/pull<string,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>>>*/
    return kk_nagare_core_types__new_Stream(_x_x1555, _ctx);
  }
}
extern kk_nagare_core_types__nstream kk_nagare_io_file_writeLines_fun1556(kk_function_t _fself, kk_nagare_core_types__nstream source, kk_context_t* _ctx) {
  struct kk_nagare_io_file_writeLines_fun1556__t* _self = kk_function_as(struct kk_nagare_io_file_writeLines_fun1556__t*, _fself, _ctx);
  kk_std_os_path__path filepath = _self->filepath; /* std/os/path/path */
  kk_drop_match(_self, {kk_std_os_path__path_dup(filepath, _ctx);}, {}, _ctx)
  kk_nagare_core_types__nstream source_0_10033 = kk_nagare_io_file__lift_writeLines_10373(source, _ctx); /*nagare/core/types/nstream<string,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_function_t p_10034 = kk_nagare_io_file_writeAll(filepath, _ctx); /*nagare/io/file_effect/writePipe<string,()>*/;
  return kk_function_call(kk_nagare_core_types__nstream, (kk_function_t, kk_nagare_core_types__nstream, kk_context_t*), p_10034, (p_10034, source_0_10033, _ctx), _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_nagare_io_file__mlift_lift_listDir_10382_10679_fun1557__t {
  struct kk_function_s _base;
  kk_std_core_types__list _uniq_xt_10264;
};
static kk_nagare_core_types__pull kk_nagare_io_file__mlift_lift_listDir_10382_10679_fun1557(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__new_mlift_lift_listDir_10382_10679_fun1557(kk_std_core_types__list _uniq_xt_10264, kk_context_t* _ctx) {
  struct kk_nagare_io_file__mlift_lift_listDir_10382_10679_fun1557__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__mlift_lift_listDir_10382_10679_fun1557__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__mlift_lift_listDir_10382_10679_fun1557, kk_context());
  _self->_uniq_xt_10264 = _uniq_xt_10264;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_nagare_core_types__pull kk_nagare_io_file__mlift_lift_listDir_10382_10679_fun1557(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_io_file__mlift_lift_listDir_10382_10679_fun1557__t* _self = kk_function_as(struct kk_nagare_io_file__mlift_lift_listDir_10382_10679_fun1557__t*, _fself, _ctx);
  kk_std_core_types__list _uniq_xt_10264 = _self->_uniq_xt_10264; /* list<list<std/os/path/path>> */
  kk_drop_match(_self, {kk_std_core_types__list_dup(_uniq_xt_10264, _ctx);}, {}, _ctx)
  return kk_nagare_io_file__lift_listDir_10381(_uniq_xt_10264, _ctx);
}

kk_nagare_core_types__pull kk_nagare_io_file__mlift_lift_listDir_10382_10679(kk_std_core_types__list _uniq_xt_10264, kk_nagare_core_types__pull _y_x10516, kk_context_t* _ctx) { /* (list<list<std/os/path/path>>, nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>) -> <alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>> nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>> */ 
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_nagare_core_types__pull x = kk_nagare_core_pull__unroll_pullAppend_10007(_y_x10516, kk_nagare_io_file__new_mlift_lift_listDir_10382_10679_fun1557(_uniq_xt_10264, _ctx), _ctx); /*nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  return x;
}
 
// lifted local: @lift-listDir@10381, @uniq-left@10057@10249, @lift-listDir@10380, @lift-listDir@10379, @lift-listDir@10378, listDir, @spec-x10282
// specialized: nagare/core/pull/@unroll-pullAppend@10007, on parameters @uniq-right@10271, using:
// @uniq-right@10271 = fn(){
//   @spec-x10268(@uniq-xt@10264);
// }


// lift anonymous function
struct kk_nagare_io_file__lift_listDir_10382_fun1561__t {
  struct kk_function_s _base;
  kk_function_t _uniq_next_10277;
  kk_std_core_types__list _uniq_xt_10264_0;
};
static kk_nagare_core_types__pull kk_nagare_io_file__lift_listDir_10382_fun1561(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__new_lift_listDir_10382_fun1561(kk_function_t _uniq_next_10277, kk_std_core_types__list _uniq_xt_10264_0, kk_context_t* _ctx) {
  struct kk_nagare_io_file__lift_listDir_10382_fun1561__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__lift_listDir_10382_fun1561__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__lift_listDir_10382_fun1561, kk_context());
  _self->_uniq_next_10277 = _uniq_next_10277;
  _self->_uniq_xt_10264_0 = _uniq_xt_10264_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_io_file__lift_listDir_10382_fun1563__t {
  struct kk_function_s _base;
  kk_std_core_types__list _uniq_xt_10264_0;
};
static kk_box_t kk_nagare_io_file__lift_listDir_10382_fun1563(kk_function_t _fself, kk_box_t _b_x737, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__new_lift_listDir_10382_fun1563(kk_std_core_types__list _uniq_xt_10264_0, kk_context_t* _ctx) {
  struct kk_nagare_io_file__lift_listDir_10382_fun1563__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__lift_listDir_10382_fun1563__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__lift_listDir_10382_fun1563, kk_context());
  _self->_uniq_xt_10264_0 = _uniq_xt_10264_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file__lift_listDir_10382_fun1563(kk_function_t _fself, kk_box_t _b_x737, kk_context_t* _ctx) {
  struct kk_nagare_io_file__lift_listDir_10382_fun1563__t* _self = kk_function_as(struct kk_nagare_io_file__lift_listDir_10382_fun1563__t*, _fself, _ctx);
  kk_std_core_types__list _uniq_xt_10264_0 = _self->_uniq_xt_10264_0; /* list<list<std/os/path/path>> */
  kk_drop_match(_self, {kk_std_core_types__list_dup(_uniq_xt_10264_0, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull _y_x10516_0_739 = kk_nagare_core_types__pull_unbox(_b_x737, KK_OWNED, _ctx); /*nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_nagare_core_types__pull _x_x1564 = kk_nagare_io_file__mlift_lift_listDir_10382_10679(_uniq_xt_10264_0, _y_x10516_0_739, _ctx); /*nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>*/
  return kk_nagare_core_types__pull_box(_x_x1564, _ctx);
}
static kk_nagare_core_types__pull kk_nagare_io_file__lift_listDir_10382_fun1561(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_io_file__lift_listDir_10382_fun1561__t* _self = kk_function_as(struct kk_nagare_io_file__lift_listDir_10382_fun1561__t*, _fself, _ctx);
  kk_function_t _uniq_next_10277 = _self->_uniq_next_10277; /* () -> <alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>> nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>> */
  kk_std_core_types__list _uniq_xt_10264_0 = _self->_uniq_xt_10264_0; /* list<list<std/os/path/path>> */
  kk_drop_match(_self, {kk_function_dup(_uniq_next_10277, _ctx);kk_std_core_types__list_dup(_uniq_xt_10264_0, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull x_0_10879 = kk_function_call(kk_nagare_core_types__pull, (kk_function_t, kk_context_t*), _uniq_next_10277, (_uniq_next_10277, _ctx), _ctx); /*nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  if (kk_yielding(kk_context())) {
    kk_nagare_core_types__pull_drop(x_0_10879, _ctx);
    kk_box_t _x_x1562 = kk_std_core_hnd_yield_extend(kk_nagare_io_file__new_lift_listDir_10382_fun1563(_uniq_xt_10264_0, _ctx), _ctx); /*10001*/
    return kk_nagare_core_types__pull_unbox(_x_x1562, KK_OWNED, _ctx);
  }
  {
    return kk_nagare_io_file__mlift_lift_listDir_10382_10679(_uniq_xt_10264_0, x_0_10879, _ctx);
  }
}

kk_nagare_core_types__pull kk_nagare_io_file__lift_listDir_10382(kk_std_core_types__list _uniq_xt_10264_0, kk_nagare_core_types__pull _uniq_left_10270, kk_context_t* _ctx) { /* (list<list<std/os/path/path>>, nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>) -> nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>> */ 
  if (kk_nagare_core_types__is_PDone(_uniq_left_10270, _ctx)) {
    return kk_nagare_io_file__lift_listDir_10381(_uniq_xt_10264_0, _ctx);
  }
  if (kk_nagare_core_types__is_POutput(_uniq_left_10270, _ctx)) {
    struct kk_nagare_core_types_POutput* _con_x1558 = kk_nagare_core_types__as_POutput(_uniq_left_10270, _ctx);
    kk_nagare_core_types__chunk _uniq_out_10274 = _con_x1558->out;
    kk_nagare_core_types__pull _uniq_tail_10275 = _con_x1558->tail;
    kk_reuse_t _ru_x1120 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_left_10270, _ctx)) {
      _ru_x1120 = (kk_datatype_ptr_reuse(_uniq_left_10270, _ctx));
    }
    else {
      kk_nagare_core_types__chunk_dup(_uniq_out_10274, _ctx);
      kk_nagare_core_types__pull_dup(_uniq_tail_10275, _ctx);
      kk_datatype_ptr_decref(_uniq_left_10270, _ctx);
    }
    kk_nagare_core_types__pull _x_x1559 = kk_nagare_io_file__lift_listDir_10382(_uniq_xt_10264_0, _uniq_tail_10275, _ctx); /*nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>*/
    return kk_nagare_core_types__new_POutput(_ru_x1120, 0, _uniq_out_10274, _x_x1559, _ctx);
  }
  if (kk_nagare_core_types__is_PEval(_uniq_left_10270, _ctx)) {
    struct kk_nagare_core_types_PEval* _con_x1560 = kk_nagare_core_types__as_PEval(_uniq_left_10270, _ctx);
    kk_function_t _uniq_next_10277 = _con_x1560->next;
    kk_reuse_t _ru_x1121 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_left_10270, _ctx)) {
      _ru_x1121 = (kk_datatype_ptr_reuse(_uniq_left_10270, _ctx));
    }
    else {
      kk_function_dup(_uniq_next_10277, _ctx);
      kk_datatype_ptr_decref(_uniq_left_10270, _ctx);
    }
    return kk_nagare_core_types__new_PEval(_ru_x1121, 0, kk_nagare_io_file__new_lift_listDir_10382_fun1561(_uniq_next_10277, _uniq_xt_10264_0, _ctx), _ctx);
  }
  {
    struct kk_nagare_core_types_PAcquire* _con_x1565 = kk_nagare_core_types__as_PAcquire(_uniq_left_10270, _ctx);
    kk_function_t _uniq_acquire_10279 = _con_x1565->acquire;
    kk_function_t _uniq_release_10280 = _con_x1565->release;
    kk_nagare_core_types__pull _uniq_tail_0_10281 = _con_x1565->tail;
    kk_reuse_t _ru_x1122 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_left_10270, _ctx)) {
      _ru_x1122 = (kk_datatype_ptr_reuse(_uniq_left_10270, _ctx));
    }
    else {
      kk_function_dup(_uniq_acquire_10279, _ctx);
      kk_function_dup(_uniq_release_10280, _ctx);
      kk_nagare_core_types__pull_dup(_uniq_tail_0_10281, _ctx);
      kk_datatype_ptr_decref(_uniq_left_10270, _ctx);
    }
    kk_nagare_core_types__pull _x_x1566 = kk_nagare_io_file__lift_listDir_10382(_uniq_xt_10264_0, _uniq_tail_0_10281, _ctx); /*nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>*/
    return kk_nagare_core_types__new_PAcquire(_ru_x1122, 0, _uniq_acquire_10279, _uniq_release_10280, _x_x1566, _ctx);
  }
}
 
// lifted local: @uniq-left@10057@10249, @lift-listDir@10380, @lift-listDir@10379, @lift-listDir@10378, listDir, @spec-x10268
// specialized: nagare/core/pull/@unroll-flatMapChunk@10010, on parameters @uniq-f@10260, using:
// @uniq-f@10260 = fn(@uniq-x@10229: (list :: V -> V)<std/os/path/path>){
//   nagare/core/types/POutput<std/os/path/path,<(alloc :: H -> X)<(global :: H)>,(console/console :: X),(div :: X),(exn :: (E, V) -> V),(nagare/io/file_effect/fileSystem :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>>>((nagare/core/types/Chunk<std/os/path/path>(@uniq-x@10229)), (nagare/core/types/PDone<std/os/path/path,<(alloc :: H -> X)<(global :: H)>,(console/console :: X),(div :: X),(exn :: (E, V) -> V),(nagare/io/file_effect/fileSystem :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>>>));
// }

kk_nagare_core_types__pull kk_nagare_io_file__lift_listDir_10381(kk_std_core_types__list _uniq_values_10259, kk_context_t* _ctx) { /* (list<list<std/os/path/path>>) -> nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Nil(_uniq_values_10259, _ctx)) {
    return kk_nagare_core_types__new_PDone(_ctx);
  }
  {
    struct kk_std_core_types_Cons* _con_x1567 = kk_std_core_types__as_Cons(_uniq_values_10259, _ctx);
    kk_box_t _box_x740 = _con_x1567->head;
    kk_std_core_types__list _uniq_xt_10264_1 = _con_x1567->tail;
    kk_std_core_types__list _uniq_x_10263 = kk_std_core_types__list_unbox(_box_x740, KK_BORROWED, _ctx);
    kk_reuse_t _ru_x1123 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_values_10259, _ctx)) {
      _ru_x1123 = (kk_datatype_ptr_reuse(_uniq_values_10259, _ctx));
    }
    else {
      kk_std_core_types__list_dup(_uniq_x_10263, _ctx);
      kk_std_core_types__list_dup(_uniq_xt_10264_1, _ctx);
      kk_datatype_ptr_decref(_uniq_values_10259, _ctx);
    }
    kk_nagare_core_types__pull _uniq_left_10055_10265;
    kk_nagare_core_types__chunk _x_x1568 = kk_nagare_core_types__new_Chunk(_uniq_x_10263, _ctx); /*nagare/core/types/chunk<4>*/
    _uniq_left_10055_10265 = kk_nagare_core_types__new_POutput(_ru_x1123, 0, _x_x1568, kk_nagare_core_types__new_PDone(_ctx), _ctx); /*nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>*/
    if (kk_nagare_core_types__is_PDone(_uniq_left_10055_10265, _ctx)) { // tailcall
                                                                        _uniq_values_10259 = _uniq_xt_10264_1;
                                                                        goto kk__tailcall;
    }
    {
      return kk_nagare_io_file__lift_listDir_10382(_uniq_xt_10264_1, _uniq_left_10055_10265, _ctx);
    }
  }
}
 
// monadic lift


// lift anonymous function
struct kk_nagare_io_file__mlift_lift_listDir_10383_10680_fun1569__t {
  struct kk_function_s _base;
  kk_nagare_core_types__pull _uniq_tail_10244;
};
static kk_nagare_core_types__pull kk_nagare_io_file__mlift_lift_listDir_10383_10680_fun1569(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__new_mlift_lift_listDir_10383_10680_fun1569(kk_nagare_core_types__pull _uniq_tail_10244, kk_context_t* _ctx) {
  struct kk_nagare_io_file__mlift_lift_listDir_10383_10680_fun1569__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__mlift_lift_listDir_10383_10680_fun1569__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__mlift_lift_listDir_10383_10680_fun1569, kk_context());
  _self->_uniq_tail_10244 = _uniq_tail_10244;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_nagare_core_types__pull kk_nagare_io_file__mlift_lift_listDir_10383_10680_fun1569(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_io_file__mlift_lift_listDir_10383_10680_fun1569__t* _self = kk_function_as(struct kk_nagare_io_file__mlift_lift_listDir_10383_10680_fun1569__t*, _fself, _ctx);
  kk_nagare_core_types__pull _uniq_tail_10244 = _self->_uniq_tail_10244; /* nagare/core/types/pull<list<std/os/path/path>,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>> */
  kk_drop_match(_self, {kk_nagare_core_types__pull_dup(_uniq_tail_10244, _ctx);}, {}, _ctx)
  return kk_nagare_io_file__lift_listDir_10380(_uniq_tail_10244, _ctx);
}

kk_nagare_core_types__pull kk_nagare_io_file__mlift_lift_listDir_10383_10680(kk_nagare_core_types__pull _uniq_tail_10244, kk_nagare_core_types__pull _y_x10519, kk_context_t* _ctx) { /* (nagare/core/types/pull<list<std/os/path/path>,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>, nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>) -> <alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>> nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>> */ 
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_nagare_core_types__pull x = kk_nagare_core_pull__unroll_pullAppend_10007(_y_x10519, kk_nagare_io_file__new_mlift_lift_listDir_10383_10680_fun1569(_uniq_tail_10244, _ctx), _ctx); /*nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  return x;
}
 
// monadic lift

kk_nagare_core_types__pull kk_nagare_io_file__mlift_lift_listDir_10380_10681(kk_nagare_core_types__pull _uniq_tail_10244_0, kk_nagare_core_types__pull _c_x10521, kk_context_t* _ctx) { /* (nagare/core/types/pull<list<std/os/path/path>,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>, nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>) -> nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>> */ 
  if (kk_nagare_core_types__is_PDone(_c_x10521, _ctx)) {
    return kk_nagare_io_file__lift_listDir_10380(_uniq_tail_10244_0, _ctx);
  }
  {
    return kk_nagare_io_file__lift_listDir_10383(_uniq_tail_10244_0, _c_x10521, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_nagare_io_file__mlift_lift_listDir_10380_10682_fun1570__t {
  struct kk_function_s _base;
};
static kk_nagare_core_types__pull kk_nagare_io_file__mlift_lift_listDir_10380_10682_fun1570(kk_function_t _fself, kk_box_t _b_x743, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__new_mlift_lift_listDir_10380_10682_fun1570(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file__mlift_lift_listDir_10380_10682_fun1570, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_nagare_core_types__pull kk_nagare_io_file__mlift_lift_listDir_10380_10682_fun1570(kk_function_t _fself, kk_box_t _b_x743, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_nagare_core_types__chunk _x_x1571;
  kk_std_core_types__list _x_x1572 = kk_std_core_types__list_unbox(_b_x743, KK_OWNED, _ctx); /*list<std/os/path/path>*/
  _x_x1571 = kk_nagare_core_types__new_Chunk(_x_x1572, _ctx); /*nagare/core/types/chunk<4>*/
  return kk_nagare_core_types__new_POutput(kk_reuse_null, 0, _x_x1571, kk_nagare_core_types__new_PDone(_ctx), _ctx);
}

kk_nagare_core_types__pull kk_nagare_io_file__mlift_lift_listDir_10380_10682(kk_nagare_core_types__pull _y_x10523, kk_context_t* _ctx) { /* (nagare/core/types/pull<list<std/os/path/path>,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>) -> <alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>> nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>> */ 
  kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_nagare_core_types__pull x_0 = kk_nagare_core_pull__unroll_pullFlatMap_10011(_y_x10523, kk_nagare_io_file__new_mlift_lift_listDir_10380_10682_fun1570(_ctx), _ctx); /*nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_unit_t keep_0 = kk_Unit;
  kk_evv_set(w_0,kk_context());
  return x_0;
}
 
// lifted local: @lift-listDir@10380, @lift-listDir@10379, @lift-listDir@10378, listDir, @spec-x10295
// specialized: nagare/core/pull/@unroll-pullAppend@10007, on parameters @uniq-right@10284, using:
// @uniq-right@10284 = fn(){
//   @spec-x10258(@uniq-tail@10244);
// }


// lift anonymous function
struct kk_nagare_io_file__lift_listDir_10383_fun1576__t {
  struct kk_function_s _base;
  kk_function_t _uniq_next_10290;
  kk_nagare_core_types__pull _uniq_tail_10244_1;
};
static kk_nagare_core_types__pull kk_nagare_io_file__lift_listDir_10383_fun1576(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__new_lift_listDir_10383_fun1576(kk_function_t _uniq_next_10290, kk_nagare_core_types__pull _uniq_tail_10244_1, kk_context_t* _ctx) {
  struct kk_nagare_io_file__lift_listDir_10383_fun1576__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__lift_listDir_10383_fun1576__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__lift_listDir_10383_fun1576, kk_context());
  _self->_uniq_next_10290 = _uniq_next_10290;
  _self->_uniq_tail_10244_1 = _uniq_tail_10244_1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_io_file__lift_listDir_10383_fun1578__t {
  struct kk_function_s _base;
  kk_nagare_core_types__pull _uniq_tail_10244_1;
};
static kk_box_t kk_nagare_io_file__lift_listDir_10383_fun1578(kk_function_t _fself, kk_box_t _b_x748, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__new_lift_listDir_10383_fun1578(kk_nagare_core_types__pull _uniq_tail_10244_1, kk_context_t* _ctx) {
  struct kk_nagare_io_file__lift_listDir_10383_fun1578__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__lift_listDir_10383_fun1578__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__lift_listDir_10383_fun1578, kk_context());
  _self->_uniq_tail_10244_1 = _uniq_tail_10244_1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file__lift_listDir_10383_fun1578(kk_function_t _fself, kk_box_t _b_x748, kk_context_t* _ctx) {
  struct kk_nagare_io_file__lift_listDir_10383_fun1578__t* _self = kk_function_as(struct kk_nagare_io_file__lift_listDir_10383_fun1578__t*, _fself, _ctx);
  kk_nagare_core_types__pull _uniq_tail_10244_1 = _self->_uniq_tail_10244_1; /* nagare/core/types/pull<list<std/os/path/path>,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>> */
  kk_drop_match(_self, {kk_nagare_core_types__pull_dup(_uniq_tail_10244_1, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull _y_x10519_0_750 = kk_nagare_core_types__pull_unbox(_b_x748, KK_OWNED, _ctx); /*nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_nagare_core_types__pull _x_x1579 = kk_nagare_io_file__mlift_lift_listDir_10383_10680(_uniq_tail_10244_1, _y_x10519_0_750, _ctx); /*nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>*/
  return kk_nagare_core_types__pull_box(_x_x1579, _ctx);
}
static kk_nagare_core_types__pull kk_nagare_io_file__lift_listDir_10383_fun1576(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_io_file__lift_listDir_10383_fun1576__t* _self = kk_function_as(struct kk_nagare_io_file__lift_listDir_10383_fun1576__t*, _fself, _ctx);
  kk_function_t _uniq_next_10290 = _self->_uniq_next_10290; /* () -> <alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>> nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>> */
  kk_nagare_core_types__pull _uniq_tail_10244_1 = _self->_uniq_tail_10244_1; /* nagare/core/types/pull<list<std/os/path/path>,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>> */
  kk_drop_match(_self, {kk_function_dup(_uniq_next_10290, _ctx);kk_nagare_core_types__pull_dup(_uniq_tail_10244_1, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull x_1_10887 = kk_function_call(kk_nagare_core_types__pull, (kk_function_t, kk_context_t*), _uniq_next_10290, (_uniq_next_10290, _ctx), _ctx); /*nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  if (kk_yielding(kk_context())) {
    kk_nagare_core_types__pull_drop(x_1_10887, _ctx);
    kk_box_t _x_x1577 = kk_std_core_hnd_yield_extend(kk_nagare_io_file__new_lift_listDir_10383_fun1578(_uniq_tail_10244_1, _ctx), _ctx); /*10001*/
    return kk_nagare_core_types__pull_unbox(_x_x1577, KK_OWNED, _ctx);
  }
  {
    return kk_nagare_io_file__mlift_lift_listDir_10383_10680(_uniq_tail_10244_1, x_1_10887, _ctx);
  }
}

kk_nagare_core_types__pull kk_nagare_io_file__lift_listDir_10383(kk_nagare_core_types__pull _uniq_tail_10244_1, kk_nagare_core_types__pull _uniq_left_10283, kk_context_t* _ctx) { /* (nagare/core/types/pull<list<std/os/path/path>,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>, nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>) -> nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>> */ 
  if (kk_nagare_core_types__is_PDone(_uniq_left_10283, _ctx)) {
    return kk_nagare_io_file__lift_listDir_10380(_uniq_tail_10244_1, _ctx);
  }
  if (kk_nagare_core_types__is_POutput(_uniq_left_10283, _ctx)) {
    struct kk_nagare_core_types_POutput* _con_x1573 = kk_nagare_core_types__as_POutput(_uniq_left_10283, _ctx);
    kk_nagare_core_types__chunk _uniq_out_10287 = _con_x1573->out;
    kk_nagare_core_types__pull _uniq_tail_10288 = _con_x1573->tail;
    kk_reuse_t _ru_x1124 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_left_10283, _ctx)) {
      _ru_x1124 = (kk_datatype_ptr_reuse(_uniq_left_10283, _ctx));
    }
    else {
      kk_nagare_core_types__chunk_dup(_uniq_out_10287, _ctx);
      kk_nagare_core_types__pull_dup(_uniq_tail_10288, _ctx);
      kk_datatype_ptr_decref(_uniq_left_10283, _ctx);
    }
    kk_nagare_core_types__pull _x_x1574 = kk_nagare_io_file__lift_listDir_10383(_uniq_tail_10244_1, _uniq_tail_10288, _ctx); /*nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>*/
    return kk_nagare_core_types__new_POutput(_ru_x1124, 0, _uniq_out_10287, _x_x1574, _ctx);
  }
  if (kk_nagare_core_types__is_PEval(_uniq_left_10283, _ctx)) {
    struct kk_nagare_core_types_PEval* _con_x1575 = kk_nagare_core_types__as_PEval(_uniq_left_10283, _ctx);
    kk_function_t _uniq_next_10290 = _con_x1575->next;
    kk_reuse_t _ru_x1125 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_left_10283, _ctx)) {
      _ru_x1125 = (kk_datatype_ptr_reuse(_uniq_left_10283, _ctx));
    }
    else {
      kk_function_dup(_uniq_next_10290, _ctx);
      kk_datatype_ptr_decref(_uniq_left_10283, _ctx);
    }
    return kk_nagare_core_types__new_PEval(_ru_x1125, 0, kk_nagare_io_file__new_lift_listDir_10383_fun1576(_uniq_next_10290, _uniq_tail_10244_1, _ctx), _ctx);
  }
  {
    struct kk_nagare_core_types_PAcquire* _con_x1580 = kk_nagare_core_types__as_PAcquire(_uniq_left_10283, _ctx);
    kk_function_t _uniq_acquire_10292 = _con_x1580->acquire;
    kk_function_t _uniq_release_10293 = _con_x1580->release;
    kk_nagare_core_types__pull _uniq_tail_0_10294 = _con_x1580->tail;
    kk_reuse_t _ru_x1126 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_left_10283, _ctx)) {
      _ru_x1126 = (kk_datatype_ptr_reuse(_uniq_left_10283, _ctx));
    }
    else {
      kk_function_dup(_uniq_acquire_10292, _ctx);
      kk_function_dup(_uniq_release_10293, _ctx);
      kk_nagare_core_types__pull_dup(_uniq_tail_0_10294, _ctx);
      kk_datatype_ptr_decref(_uniq_left_10283, _ctx);
    }
    kk_nagare_core_types__pull _x_x1581 = kk_nagare_io_file__lift_listDir_10383(_uniq_tail_10244_1, _uniq_tail_0_10294, _ctx); /*nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>*/
    return kk_nagare_core_types__new_PAcquire(_ru_x1126, 0, _uniq_acquire_10292, _uniq_release_10293, _x_x1581, _ctx);
  }
}
 
// lifted local: @lift-listDir@10379, @lift-listDir@10378, listDir, @spec-x10258
// specialized: nagare/core/pull/@unroll-pullFlatMap@10011, on parameters @uniq-f@10240, using:
// @uniq-f@10240 = fn(@uniq-x@10229: (list :: V -> V)<std/os/path/path>){
//   val @uniq-nextStep@10231 : (nagare/core/types/pull :: (V, E) -> V)<std/os/path/path,<(alloc :: H -> X)<(global :: H)>,(console/console :: X),(div :: X),(exn :: (E, V) -> V),(nagare/io/file_effect/fileSystem :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>>>
//         = nagare/core/types/POutput<std/os/path/path,<(alloc :: H -> X)<(global :: H)>,(console/console :: X),(div :: X),(exn :: (E, V) -> V),(nagare/io/file_effect/fileSystem :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>>>((nagare/core/types/Chunk<std/os/path/path>(@uniq-x@10229)), (nagare/core/types/PDone<std/os/path/path,<(alloc :: H -> X)<(global :: H)>,(console/console :: X),(div :: X),(exn :: (E, V) -> V),(nagare/io/file_effect/fileSystem :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>>>));
//   @uniq-nextStep@10231;
// }


// lift anonymous function
struct kk_nagare_io_file__lift_listDir_10380_fun1584__t {
  struct kk_function_s _base;
  kk_nagare_core_types__pull _uniq_tail_10244_2;
};
static kk_box_t kk_nagare_io_file__lift_listDir_10380_fun1584(kk_function_t _fself, kk_box_t _b_x752, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__new_lift_listDir_10380_fun1584(kk_nagare_core_types__pull _uniq_tail_10244_2, kk_context_t* _ctx) {
  struct kk_nagare_io_file__lift_listDir_10380_fun1584__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__lift_listDir_10380_fun1584__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__lift_listDir_10380_fun1584, kk_context());
  _self->_uniq_tail_10244_2 = _uniq_tail_10244_2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file__lift_listDir_10380_fun1584(kk_function_t _fself, kk_box_t _b_x752, kk_context_t* _ctx) {
  struct kk_nagare_io_file__lift_listDir_10380_fun1584__t* _self = kk_function_as(struct kk_nagare_io_file__lift_listDir_10380_fun1584__t*, _fself, _ctx);
  kk_nagare_core_types__pull _uniq_tail_10244_2 = _self->_uniq_tail_10244_2; /* nagare/core/types/pull<list<std/os/path/path>,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>> */
  kk_drop_match(_self, {kk_nagare_core_types__pull_dup(_uniq_tail_10244_2, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull _c_x10521_0_757 = kk_nagare_core_types__pull_unbox(_b_x752, KK_OWNED, _ctx); /*nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_nagare_core_types__pull _x_x1585 = kk_nagare_io_file__mlift_lift_listDir_10380_10681(_uniq_tail_10244_2, _c_x10521_0_757, _ctx); /*nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>*/
  return kk_nagare_core_types__pull_box(_x_x1585, _ctx);
}


// lift anonymous function
struct kk_nagare_io_file__lift_listDir_10380_fun1587__t {
  struct kk_function_s _base;
  kk_function_t _uniq_next_10253;
};
static kk_nagare_core_types__pull kk_nagare_io_file__lift_listDir_10380_fun1587(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__new_lift_listDir_10380_fun1587(kk_function_t _uniq_next_10253, kk_context_t* _ctx) {
  struct kk_nagare_io_file__lift_listDir_10380_fun1587__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__lift_listDir_10380_fun1587__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__lift_listDir_10380_fun1587, kk_context());
  _self->_uniq_next_10253 = _uniq_next_10253;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_io_file__lift_listDir_10380_fun1589__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_io_file__lift_listDir_10380_fun1589(kk_function_t _fself, kk_box_t _b_x754, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__new_lift_listDir_10380_fun1589(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file__lift_listDir_10380_fun1589, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_io_file__lift_listDir_10380_fun1589(kk_function_t _fself, kk_box_t _b_x754, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_nagare_core_types__pull _x_x1590;
  kk_nagare_core_types__pull _x_x1591 = kk_nagare_core_types__pull_unbox(_b_x754, KK_OWNED, _ctx); /*nagare/core/types/pull<list<std/os/path/path>,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>*/
  _x_x1590 = kk_nagare_io_file__mlift_lift_listDir_10380_10682(_x_x1591, _ctx); /*nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>*/
  return kk_nagare_core_types__pull_box(_x_x1590, _ctx);
}
static kk_nagare_core_types__pull kk_nagare_io_file__lift_listDir_10380_fun1587(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_io_file__lift_listDir_10380_fun1587__t* _self = kk_function_as(struct kk_nagare_io_file__lift_listDir_10380_fun1587__t*, _fself, _ctx);
  kk_function_t _uniq_next_10253 = _self->_uniq_next_10253; /* () -> <alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>> nagare/core/types/pull<list<std/os/path/path>,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>> */
  kk_drop_match(_self, {kk_function_dup(_uniq_next_10253, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull x_3_10892 = kk_function_call(kk_nagare_core_types__pull, (kk_function_t, kk_context_t*), _uniq_next_10253, (_uniq_next_10253, _ctx), _ctx); /*nagare/core/types/pull<list<std/os/path/path>,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  if (kk_yielding(kk_context())) {
    kk_nagare_core_types__pull_drop(x_3_10892, _ctx);
    kk_box_t _x_x1588 = kk_std_core_hnd_yield_extend(kk_nagare_io_file__new_lift_listDir_10380_fun1589(_ctx), _ctx); /*10001*/
    return kk_nagare_core_types__pull_unbox(_x_x1588, KK_OWNED, _ctx);
  }
  {
    return kk_nagare_io_file__mlift_lift_listDir_10380_10682(x_3_10892, _ctx);
  }
}

kk_nagare_core_types__pull kk_nagare_io_file__lift_listDir_10380(kk_nagare_core_types__pull _uniq_source_10239, kk_context_t* _ctx) { /* (nagare/core/types/pull<list<std/os/path/path>,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>) -> nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>> */ 
  kk__tailcall: ;
  if (kk_nagare_core_types__is_PDone(_uniq_source_10239, _ctx)) {
    return kk_nagare_core_types__new_PDone(_ctx);
  }
  if (kk_nagare_core_types__is_POutput(_uniq_source_10239, _ctx)) {
    struct kk_nagare_core_types_POutput* _con_x1582 = kk_nagare_core_types__as_POutput(_uniq_source_10239, _ctx);
    kk_nagare_core_types__chunk _uniq_out_10243 = _con_x1582->out;
    kk_nagare_core_types__pull _uniq_tail_10244_2 = _con_x1582->tail;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_source_10239, _ctx)) {
      kk_datatype_ptr_free(_uniq_source_10239, _ctx);
    }
    else {
      kk_nagare_core_types__chunk_dup(_uniq_out_10243, _ctx);
      kk_nagare_core_types__pull_dup(_uniq_tail_10244_2, _ctx);
      kk_datatype_ptr_decref(_uniq_source_10239, _ctx);
    }
    {
      kk_std_core_types__list _uniq_values_10246 = _uniq_out_10243.values;
      kk_nagare_core_types__pull x_2_10889;
      if (kk_std_core_types__is_Nil(_uniq_values_10246, _ctx)) {
        x_2_10889 = kk_nagare_core_types__new_PDone(_ctx); /*nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>*/
      }
      else {
        x_2_10889 = kk_nagare_io_file__lift_listDir_10381(_uniq_values_10246, _ctx); /*nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>*/
      }
      if (kk_yielding(kk_context())) {
        kk_nagare_core_types__pull_drop(x_2_10889, _ctx);
        kk_box_t _x_x1583 = kk_std_core_hnd_yield_extend(kk_nagare_io_file__new_lift_listDir_10380_fun1584(_uniq_tail_10244_2, _ctx), _ctx); /*10001*/
        return kk_nagare_core_types__pull_unbox(_x_x1583, KK_OWNED, _ctx);
      }
      if (kk_nagare_core_types__is_PDone(x_2_10889, _ctx)) { // tailcall
                                                             _uniq_source_10239 = _uniq_tail_10244_2;
                                                             goto kk__tailcall;
      }
      {
        return kk_nagare_io_file__lift_listDir_10383(_uniq_tail_10244_2, x_2_10889, _ctx);
      }
    }
  }
  if (kk_nagare_core_types__is_PEval(_uniq_source_10239, _ctx)) {
    struct kk_nagare_core_types_PEval* _con_x1586 = kk_nagare_core_types__as_PEval(_uniq_source_10239, _ctx);
    kk_function_t _uniq_next_10253 = _con_x1586->next;
    kk_reuse_t _ru_x1128 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_source_10239, _ctx)) {
      _ru_x1128 = (kk_datatype_ptr_reuse(_uniq_source_10239, _ctx));
    }
    else {
      kk_function_dup(_uniq_next_10253, _ctx);
      kk_datatype_ptr_decref(_uniq_source_10239, _ctx);
    }
    return kk_nagare_core_types__new_PEval(_ru_x1128, 0, kk_nagare_io_file__new_lift_listDir_10380_fun1587(_uniq_next_10253, _ctx), _ctx);
  }
  {
    struct kk_nagare_core_types_PAcquire* _con_x1592 = kk_nagare_core_types__as_PAcquire(_uniq_source_10239, _ctx);
    kk_function_t _uniq_acquire_10255 = _con_x1592->acquire;
    kk_function_t _uniq_release_10256 = _con_x1592->release;
    kk_nagare_core_types__pull _uniq_tail_0_10257 = _con_x1592->tail;
    kk_reuse_t _ru_x1129 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_source_10239, _ctx)) {
      _ru_x1129 = (kk_datatype_ptr_reuse(_uniq_source_10239, _ctx));
    }
    else {
      kk_function_dup(_uniq_acquire_10255, _ctx);
      kk_function_dup(_uniq_release_10256, _ctx);
      kk_nagare_core_types__pull_dup(_uniq_tail_0_10257, _ctx);
      kk_datatype_ptr_decref(_uniq_source_10239, _ctx);
    }
    kk_nagare_core_types__pull _x_x1593 = kk_nagare_io_file__lift_listDir_10380(_uniq_tail_0_10257, _ctx); /*nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>*/
    return kk_nagare_core_types__new_PAcquire(_ru_x1129, 0, _uniq_acquire_10255, _uniq_release_10256, _x_x1593, _ctx);
  }
}
 
// lifted local: @lift-listDir@10378, listDir, @spec-x10238
// specialized: nagare/core/pull/pullFlatMap, on parameters @uniq-f@10235, using:
// @uniq-f@10235 = fn(@uniq-x@10229: (list :: V -> V)<std/os/path/path>){
//   val entries@10233 : (list :: V -> V)<std/os/path/path>;
//   val @uniq-nextStep@10231 : (nagare/core/types/pull :: (V, E) -> V)<std/os/path/path,<(alloc :: H -> X)<(global :: H)>,(console/console :: X),(div :: X),(exn :: (E, V) -> V),(nagare/io/file_effect/fileSystem :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>>>;
//   val @uniq-pat@0@10230 : (nagare/core/types/nstream :: (V, E) -> V)<std/os/path/path,<(alloc :: H -> X)<(global :: H)>,(console/console :: X),(div :: X),(exn :: (E, V) -> V),(nagare/io/file_effect/fileSystem :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>>>;
//   val @scrut : (nagare/core/types/nstream :: (V, E) -> V)<std/os/path/path,<(alloc :: H -> X)<(global :: H)>,(console/console :: X),(div :: X),(exn :: (E, V) -> V),(nagare/io/file_effect/fileSystem :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>>>;
//   @uniq-nextStep@10231;
// }

kk_nagare_core_types__pull kk_nagare_io_file__lift_listDir_10379(kk_nagare_core_types__pull _uniq_source_10234, kk_context_t* _ctx) { /* (nagare/core/types/pull<list<std/os/path/path>,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>) -> nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>> */ 
  if (kk_nagare_core_types__is_PDone(_uniq_source_10234, _ctx)) {
    return kk_nagare_core_types__new_PDone(_ctx);
  }
  {
    return kk_nagare_io_file__lift_listDir_10380(_uniq_source_10234, _ctx);
  }
}
 
// lifted local: listDir, @spec-x10232
// specialized: nagare/core/stream/flatMap, on parameters @uniq-f@10226, using:
// @uniq-f@10226 = fn(entries: (list :: V -> V)<std/os/path/path>){
//   nagare/core/types/Stream<std/os/path/path,<(alloc :: H -> X)<(global :: H)>,(console/console :: X),(div :: X),(exn :: (E, V) -> V),(nagare/io/file_effect/fileSystem :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>>>((nagare/core/types/POutput<std/os/path/path,<(alloc :: H -> X)<(global :: H)>,(console/console :: X),(div :: X),(exn :: (E, V) -> V),(nagare/io/file_effect/fileSystem :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>>>((nagare/core/types/Chunk<std/os/path/path>(entries)), (nagare/core/types/PDone<std/os/path/path,<(alloc :: H -> X)<(global :: H)>,(console/console :: X),(div :: X),(exn :: (E, V) -> V),(nagare/io/file_effect/fileSystem :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>>>))));
// }

kk_nagare_core_types__nstream kk_nagare_io_file__lift_listDir_10378(kk_nagare_core_types__nstream _uniq_source_10225, kk_context_t* _ctx) { /* (nagare/core/types/nstream<list<std/os/path/path>,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>) -> nagare/core/types/nstream<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>> */ 
  {
    kk_nagare_core_types__pull _uniq_step_10228 = _uniq_source_10225.step;
    kk_nagare_core_types__pull _x_x1594 = kk_nagare_io_file__lift_listDir_10379(_uniq_step_10228, _ctx); /*nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>*/
    return kk_nagare_core_types__new_Stream(_x_x1594, _ctx);
  }
}


// lift anonymous function
struct kk_nagare_io_file_listDir_fun1599__t {
  struct kk_function_s _base;
  kk_std_os_path__path dir;
};
static kk_nagare_core_types__pull kk_nagare_io_file_listDir_fun1599(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_listDir_fun1599(kk_std_os_path__path dir, kk_context_t* _ctx) {
  struct kk_nagare_io_file_listDir_fun1599__t* _self = kk_function_alloc_as(struct kk_nagare_io_file_listDir_fun1599__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file_listDir_fun1599, kk_context());
  _self->dir = dir;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_io_file_listDir_fun1601__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_io_file_listDir_fun1601(kk_function_t _fself, kk_box_t _b_x764, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_listDir_fun1601(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file_listDir_fun1601, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_io_file_listDir_fun1601(kk_function_t _fself, kk_box_t _b_x764, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1602;
  kk_std_os_path__path _x_x1603 = kk_std_os_path__path_unbox(_b_x764, KK_OWNED, _ctx); /*std/os/path/path*/
  _x_x1602 = kk_std_os_path_string(_x_x1603, _ctx); /*string*/
  return kk_string_box(_x_x1602);
}


// lift anonymous function
struct kk_nagare_io_file_listDir_fun1609__t {
  struct kk_function_s _base;
  kk_ssize_t i_10896;
};
static kk_box_t kk_nagare_io_file_listDir_fun1609(kk_function_t _fself, kk_function_t _b_x786, kk_box_t _b_x787, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_listDir_fun1609(kk_ssize_t i_10896, kk_context_t* _ctx) {
  struct kk_nagare_io_file_listDir_fun1609__t* _self = kk_function_alloc_as(struct kk_nagare_io_file_listDir_fun1609__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file_listDir_fun1609, kk_context());
  _self->i_10896 = i_10896;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file_listDir_fun1609(kk_function_t _fself, kk_function_t _b_x786, kk_box_t _b_x787, kk_context_t* _ctx) {
  struct kk_nagare_io_file_listDir_fun1609__t* _self = kk_function_as(struct kk_nagare_io_file_listDir_fun1609__t*, _fself, _ctx);
  kk_ssize_t i_10896 = _self->i_10896; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_10896, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_10896, _b_x786, _b_x787, _ctx);
}


// lift anonymous function
struct kk_nagare_io_file_listDir_fun1611__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_io_file_listDir_fun1611(kk_function_t _fself, kk_box_t _b_x796, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_listDir_fun1611(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file_listDir_fun1611, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_io_file_listDir_fun1611(kk_function_t _fself, kk_box_t _b_x796, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_nagare_core_types__pull _x_x1612;
  kk_std_core_types__list _x_x1613 = kk_std_core_types__list_unbox(_b_x796, KK_OWNED, _ctx); /*list<std/os/path/path>*/
  _x_x1612 = kk_nagare_io_file__mlift_listDir_10683(_x_x1613, _ctx); /*nagare/core/types/pull<list<std/os/path/path>,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>*/
  return kk_nagare_core_types__pull_box(_x_x1612, _ctx);
}
static kk_nagare_core_types__pull kk_nagare_io_file_listDir_fun1599(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_io_file_listDir_fun1599__t* _self = kk_function_as(struct kk_nagare_io_file_listDir_fun1599__t*, _fself, _ctx);
  kk_std_os_path__path dir = _self->dir; /* std/os/path/path */
  kk_drop_match(_self, {kk_std_os_path__path_dup(dir, _ctx);}, {}, _ctx)
  kk_string_t _x_x1_10637;
  kk_box_t _x_x1600 = kk_std_core_hnd__open_none1(kk_nagare_io_file_new_listDir_fun1601(_ctx), kk_std_os_path__path_box(dir, _ctx), _ctx); /*10001*/
  _x_x1_10637 = kk_string_unbox(_x_x1600); /*string*/
  kk_ssize_t i_10896 = (KK_IZ(1)); /*hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_10896,kk_context()); /*hnd/evv<<nagare/io/file_effect/fileSystem,alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_std_core_hnd__ev ev_10901 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<nagare/io/file_effect/fileSystem>*/;
  kk_std_core_types__list y;
  kk_box_t _x_x1604;
  {
    struct kk_std_core_hnd_Ev* _con_x1605 = kk_std_core_hnd__as_Ev(ev_10901, _ctx);
    kk_box_t _box_x767 = _con_x1605->hnd;
    int32_t m = _con_x1605->marker;
    kk_nagare_io_file__effect__fileSystem h = kk_nagare_io_file__effect__fileSystem_unbox(_box_x767, KK_BORROWED, _ctx);
    kk_nagare_io_file__effect__fileSystem_dup(h, _ctx);
    kk_std_core_hnd__clause1 _match_x991;
    kk_std_core_hnd__clause1 _brw_x992 = kk_nagare_io_file__effect_listChildren_fs__select(h, _ctx); /*hnd/clause1<(string, bool, int),list<std/os/path/path>,nagare/io/file_effect/fileSystem,2059,2060>*/;
    kk_datatype_ptr_dropn(h, (KK_I32(4)), _ctx);
    _match_x991 = _brw_x992; /*hnd/clause1<(string, bool, int),list<std/os/path/path>,nagare/io/file_effect/fileSystem,2059,2060>*/
    {
      kk_function_t _fun_unbox_x771 = _match_x991.clause;
      kk_box_t _x_x1606;
      kk_std_core_types__tuple3 _x_x1607 = kk_std_core_types__new_Tuple3(kk_string_box(_x_x1_10637), kk_bool_box(false), kk_integer_box(kk_integer_from_small(1), _ctx), _ctx); /*(10041, 10042, 10043)*/
      _x_x1606 = kk_std_core_types__tuple3_box(_x_x1607, _ctx); /*10009*/
      _x_x1604 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x771, (_fun_unbox_x771, m, ev_10901, _x_x1606, _ctx), _ctx); /*10010*/
    }
  }
  y = kk_std_core_types__list_unbox(_x_x1604, KK_OWNED, _ctx); /*list<std/os/path/path>*/
  kk_evv_set(w,kk_context());
  kk_std_core_types__list x_10894;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(y, _ctx);
    kk_box_t _x_x1608 = kk_std_core_hnd_yield_cont(kk_nagare_io_file_new_listDir_fun1609(i_10896, _ctx), _ctx); /*10002*/
    x_10894 = kk_std_core_types__list_unbox(_x_x1608, KK_OWNED, _ctx); /*list<std/os/path/path>*/
  }
  else {
    x_10894 = y; /*list<std/os/path/path>*/
  }
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_10894, _ctx);
    kk_box_t _x_x1610 = kk_std_core_hnd_yield_extend(kk_nagare_io_file_new_listDir_fun1611(_ctx), _ctx); /*10001*/
    return kk_nagare_core_types__pull_unbox(_x_x1610, KK_OWNED, _ctx);
  }
  {
    kk_std_core_types__list _b_x797_801 = x_10894; /*list<std/os/path/path>*/;
    kk_std_core_types__list _b_x798_802 = kk_std_core_types__new_Nil(_ctx); /*list<list<std/os/path/path>>*/;
    kk_nagare_core_types__chunk _x_x1614;
    kk_std_core_types__list _x_x1615 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_std_core_types__list_box(_b_x797_801, _ctx), _b_x798_802, _ctx); /*list<10021>*/
    _x_x1614 = kk_nagare_core_types__new_Chunk(_x_x1615, _ctx); /*nagare/core/types/chunk<4>*/
    return kk_nagare_core_types__new_POutput(kk_reuse_null, 0, _x_x1614, kk_nagare_core_types__new_PDone(_ctx), _ctx);
  }
}

kk_nagare_core_types__nstream kk_nagare_io_file_listDir(kk_std_os_path__path dir, kk_context_t* _ctx) { /* (dir : std/os/path/path) -> nagare/io/file_effect/fsStream<std/os/path/path> */ 
  kk_nagare_core_types__nstream _x_x1597;
  kk_nagare_core_types__pull _x_x1598 = kk_nagare_core_types__new_PEval(kk_reuse_null, 0, kk_nagare_io_file_new_listDir_fun1599(dir, _ctx), _ctx); /*nagare/core/types/pull<19,20>*/
  _x_x1597 = kk_nagare_core_types__new_Stream(_x_x1598, _ctx); /*nagare/core/types/nstream<27,28>*/
  return kk_nagare_io_file__lift_listDir_10378(_x_x1597, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_nagare_io_file__mlift_lift_walk_10388_10684_fun1616__t {
  struct kk_function_s _base;
  kk_std_core_types__list _uniq_xt_10335;
};
static kk_nagare_core_types__pull kk_nagare_io_file__mlift_lift_walk_10388_10684_fun1616(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__new_mlift_lift_walk_10388_10684_fun1616(kk_std_core_types__list _uniq_xt_10335, kk_context_t* _ctx) {
  struct kk_nagare_io_file__mlift_lift_walk_10388_10684_fun1616__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__mlift_lift_walk_10388_10684_fun1616__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__mlift_lift_walk_10388_10684_fun1616, kk_context());
  _self->_uniq_xt_10335 = _uniq_xt_10335;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_nagare_core_types__pull kk_nagare_io_file__mlift_lift_walk_10388_10684_fun1616(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_io_file__mlift_lift_walk_10388_10684_fun1616__t* _self = kk_function_as(struct kk_nagare_io_file__mlift_lift_walk_10388_10684_fun1616__t*, _fself, _ctx);
  kk_std_core_types__list _uniq_xt_10335 = _self->_uniq_xt_10335; /* list<list<std/os/path/path>> */
  kk_drop_match(_self, {kk_std_core_types__list_dup(_uniq_xt_10335, _ctx);}, {}, _ctx)
  return kk_nagare_io_file__lift_walk_10387(_uniq_xt_10335, _ctx);
}

kk_nagare_core_types__pull kk_nagare_io_file__mlift_lift_walk_10388_10684(kk_std_core_types__list _uniq_xt_10335, kk_nagare_core_types__pull _y_x10529, kk_context_t* _ctx) { /* (list<list<std/os/path/path>>, nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>) -> <alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>> nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>> */ 
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_nagare_core_types__pull x = kk_nagare_core_pull__unroll_pullAppend_10007(_y_x10529, kk_nagare_io_file__new_mlift_lift_walk_10388_10684_fun1616(_uniq_xt_10335, _ctx), _ctx); /*nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  return x;
}
 
// lifted local: @lift-walk@10387, @uniq-left@10057@10320, @lift-walk@10386, @lift-walk@10385, @lift-walk@10384, walk, @spec-x10353
// specialized: nagare/core/pull/@unroll-pullAppend@10007, on parameters @uniq-right@10342, using:
// @uniq-right@10342 = fn(){
//   @spec-x10339(@uniq-xt@10335);
// }


// lift anonymous function
struct kk_nagare_io_file__lift_walk_10388_fun1620__t {
  struct kk_function_s _base;
  kk_function_t _uniq_next_10348;
  kk_std_core_types__list _uniq_xt_10335_0;
};
static kk_nagare_core_types__pull kk_nagare_io_file__lift_walk_10388_fun1620(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__new_lift_walk_10388_fun1620(kk_function_t _uniq_next_10348, kk_std_core_types__list _uniq_xt_10335_0, kk_context_t* _ctx) {
  struct kk_nagare_io_file__lift_walk_10388_fun1620__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__lift_walk_10388_fun1620__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__lift_walk_10388_fun1620, kk_context());
  _self->_uniq_next_10348 = _uniq_next_10348;
  _self->_uniq_xt_10335_0 = _uniq_xt_10335_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_io_file__lift_walk_10388_fun1622__t {
  struct kk_function_s _base;
  kk_std_core_types__list _uniq_xt_10335_0;
};
static kk_box_t kk_nagare_io_file__lift_walk_10388_fun1622(kk_function_t _fself, kk_box_t _b_x804, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__new_lift_walk_10388_fun1622(kk_std_core_types__list _uniq_xt_10335_0, kk_context_t* _ctx) {
  struct kk_nagare_io_file__lift_walk_10388_fun1622__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__lift_walk_10388_fun1622__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__lift_walk_10388_fun1622, kk_context());
  _self->_uniq_xt_10335_0 = _uniq_xt_10335_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file__lift_walk_10388_fun1622(kk_function_t _fself, kk_box_t _b_x804, kk_context_t* _ctx) {
  struct kk_nagare_io_file__lift_walk_10388_fun1622__t* _self = kk_function_as(struct kk_nagare_io_file__lift_walk_10388_fun1622__t*, _fself, _ctx);
  kk_std_core_types__list _uniq_xt_10335_0 = _self->_uniq_xt_10335_0; /* list<list<std/os/path/path>> */
  kk_drop_match(_self, {kk_std_core_types__list_dup(_uniq_xt_10335_0, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull _y_x10529_0_806 = kk_nagare_core_types__pull_unbox(_b_x804, KK_OWNED, _ctx); /*nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_nagare_core_types__pull _x_x1623 = kk_nagare_io_file__mlift_lift_walk_10388_10684(_uniq_xt_10335_0, _y_x10529_0_806, _ctx); /*nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>*/
  return kk_nagare_core_types__pull_box(_x_x1623, _ctx);
}
static kk_nagare_core_types__pull kk_nagare_io_file__lift_walk_10388_fun1620(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_io_file__lift_walk_10388_fun1620__t* _self = kk_function_as(struct kk_nagare_io_file__lift_walk_10388_fun1620__t*, _fself, _ctx);
  kk_function_t _uniq_next_10348 = _self->_uniq_next_10348; /* () -> <alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>> nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>> */
  kk_std_core_types__list _uniq_xt_10335_0 = _self->_uniq_xt_10335_0; /* list<list<std/os/path/path>> */
  kk_drop_match(_self, {kk_function_dup(_uniq_next_10348, _ctx);kk_std_core_types__list_dup(_uniq_xt_10335_0, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull x_0_10909 = kk_function_call(kk_nagare_core_types__pull, (kk_function_t, kk_context_t*), _uniq_next_10348, (_uniq_next_10348, _ctx), _ctx); /*nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  if (kk_yielding(kk_context())) {
    kk_nagare_core_types__pull_drop(x_0_10909, _ctx);
    kk_box_t _x_x1621 = kk_std_core_hnd_yield_extend(kk_nagare_io_file__new_lift_walk_10388_fun1622(_uniq_xt_10335_0, _ctx), _ctx); /*10001*/
    return kk_nagare_core_types__pull_unbox(_x_x1621, KK_OWNED, _ctx);
  }
  {
    return kk_nagare_io_file__mlift_lift_walk_10388_10684(_uniq_xt_10335_0, x_0_10909, _ctx);
  }
}

kk_nagare_core_types__pull kk_nagare_io_file__lift_walk_10388(kk_std_core_types__list _uniq_xt_10335_0, kk_nagare_core_types__pull _uniq_left_10341, kk_context_t* _ctx) { /* (list<list<std/os/path/path>>, nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>) -> nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>> */ 
  if (kk_nagare_core_types__is_PDone(_uniq_left_10341, _ctx)) {
    return kk_nagare_io_file__lift_walk_10387(_uniq_xt_10335_0, _ctx);
  }
  if (kk_nagare_core_types__is_POutput(_uniq_left_10341, _ctx)) {
    struct kk_nagare_core_types_POutput* _con_x1617 = kk_nagare_core_types__as_POutput(_uniq_left_10341, _ctx);
    kk_nagare_core_types__chunk _uniq_out_10345 = _con_x1617->out;
    kk_nagare_core_types__pull _uniq_tail_10346 = _con_x1617->tail;
    kk_reuse_t _ru_x1131 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_left_10341, _ctx)) {
      _ru_x1131 = (kk_datatype_ptr_reuse(_uniq_left_10341, _ctx));
    }
    else {
      kk_nagare_core_types__chunk_dup(_uniq_out_10345, _ctx);
      kk_nagare_core_types__pull_dup(_uniq_tail_10346, _ctx);
      kk_datatype_ptr_decref(_uniq_left_10341, _ctx);
    }
    kk_nagare_core_types__pull _x_x1618 = kk_nagare_io_file__lift_walk_10388(_uniq_xt_10335_0, _uniq_tail_10346, _ctx); /*nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>*/
    return kk_nagare_core_types__new_POutput(_ru_x1131, 0, _uniq_out_10345, _x_x1618, _ctx);
  }
  if (kk_nagare_core_types__is_PEval(_uniq_left_10341, _ctx)) {
    struct kk_nagare_core_types_PEval* _con_x1619 = kk_nagare_core_types__as_PEval(_uniq_left_10341, _ctx);
    kk_function_t _uniq_next_10348 = _con_x1619->next;
    kk_reuse_t _ru_x1132 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_left_10341, _ctx)) {
      _ru_x1132 = (kk_datatype_ptr_reuse(_uniq_left_10341, _ctx));
    }
    else {
      kk_function_dup(_uniq_next_10348, _ctx);
      kk_datatype_ptr_decref(_uniq_left_10341, _ctx);
    }
    return kk_nagare_core_types__new_PEval(_ru_x1132, 0, kk_nagare_io_file__new_lift_walk_10388_fun1620(_uniq_next_10348, _uniq_xt_10335_0, _ctx), _ctx);
  }
  {
    struct kk_nagare_core_types_PAcquire* _con_x1624 = kk_nagare_core_types__as_PAcquire(_uniq_left_10341, _ctx);
    kk_function_t _uniq_acquire_10350 = _con_x1624->acquire;
    kk_function_t _uniq_release_10351 = _con_x1624->release;
    kk_nagare_core_types__pull _uniq_tail_0_10352 = _con_x1624->tail;
    kk_reuse_t _ru_x1133 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_left_10341, _ctx)) {
      _ru_x1133 = (kk_datatype_ptr_reuse(_uniq_left_10341, _ctx));
    }
    else {
      kk_function_dup(_uniq_acquire_10350, _ctx);
      kk_function_dup(_uniq_release_10351, _ctx);
      kk_nagare_core_types__pull_dup(_uniq_tail_0_10352, _ctx);
      kk_datatype_ptr_decref(_uniq_left_10341, _ctx);
    }
    kk_nagare_core_types__pull _x_x1625 = kk_nagare_io_file__lift_walk_10388(_uniq_xt_10335_0, _uniq_tail_0_10352, _ctx); /*nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>*/
    return kk_nagare_core_types__new_PAcquire(_ru_x1133, 0, _uniq_acquire_10350, _uniq_release_10351, _x_x1625, _ctx);
  }
}
 
// lifted local: @uniq-left@10057@10320, @lift-walk@10386, @lift-walk@10385, @lift-walk@10384, walk, @spec-x10339
// specialized: nagare/core/pull/@unroll-flatMapChunk@10010, on parameters @uniq-f@10331, using:
// @uniq-f@10331 = fn(@uniq-x@10300: (list :: V -> V)<std/os/path/path>){
//   nagare/core/types/POutput<std/os/path/path,<(alloc :: H -> X)<(global :: H)>,(console/console :: X),(div :: X),(exn :: (E, V) -> V),(nagare/io/file_effect/fileSystem :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>>>((nagare/core/types/Chunk<std/os/path/path>(@uniq-x@10300)), (nagare/core/types/PDone<std/os/path/path,<(alloc :: H -> X)<(global :: H)>,(console/console :: X),(div :: X),(exn :: (E, V) -> V),(nagare/io/file_effect/fileSystem :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>>>));
// }

kk_nagare_core_types__pull kk_nagare_io_file__lift_walk_10387(kk_std_core_types__list _uniq_values_10330, kk_context_t* _ctx) { /* (list<list<std/os/path/path>>) -> nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Nil(_uniq_values_10330, _ctx)) {
    return kk_nagare_core_types__new_PDone(_ctx);
  }
  {
    struct kk_std_core_types_Cons* _con_x1626 = kk_std_core_types__as_Cons(_uniq_values_10330, _ctx);
    kk_box_t _box_x807 = _con_x1626->head;
    kk_std_core_types__list _uniq_xt_10335_1 = _con_x1626->tail;
    kk_std_core_types__list _uniq_x_10334 = kk_std_core_types__list_unbox(_box_x807, KK_BORROWED, _ctx);
    kk_reuse_t _ru_x1134 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_values_10330, _ctx)) {
      _ru_x1134 = (kk_datatype_ptr_reuse(_uniq_values_10330, _ctx));
    }
    else {
      kk_std_core_types__list_dup(_uniq_x_10334, _ctx);
      kk_std_core_types__list_dup(_uniq_xt_10335_1, _ctx);
      kk_datatype_ptr_decref(_uniq_values_10330, _ctx);
    }
    kk_nagare_core_types__pull _uniq_left_10055_10336;
    kk_nagare_core_types__chunk _x_x1627 = kk_nagare_core_types__new_Chunk(_uniq_x_10334, _ctx); /*nagare/core/types/chunk<4>*/
    _uniq_left_10055_10336 = kk_nagare_core_types__new_POutput(_ru_x1134, 0, _x_x1627, kk_nagare_core_types__new_PDone(_ctx), _ctx); /*nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>*/
    if (kk_nagare_core_types__is_PDone(_uniq_left_10055_10336, _ctx)) { // tailcall
                                                                        _uniq_values_10330 = _uniq_xt_10335_1;
                                                                        goto kk__tailcall;
    }
    {
      return kk_nagare_io_file__lift_walk_10388(_uniq_xt_10335_1, _uniq_left_10055_10336, _ctx);
    }
  }
}
 
// monadic lift


// lift anonymous function
struct kk_nagare_io_file__mlift_lift_walk_10389_10685_fun1628__t {
  struct kk_function_s _base;
  kk_nagare_core_types__pull _uniq_tail_10315;
};
static kk_nagare_core_types__pull kk_nagare_io_file__mlift_lift_walk_10389_10685_fun1628(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__new_mlift_lift_walk_10389_10685_fun1628(kk_nagare_core_types__pull _uniq_tail_10315, kk_context_t* _ctx) {
  struct kk_nagare_io_file__mlift_lift_walk_10389_10685_fun1628__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__mlift_lift_walk_10389_10685_fun1628__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__mlift_lift_walk_10389_10685_fun1628, kk_context());
  _self->_uniq_tail_10315 = _uniq_tail_10315;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_nagare_core_types__pull kk_nagare_io_file__mlift_lift_walk_10389_10685_fun1628(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_io_file__mlift_lift_walk_10389_10685_fun1628__t* _self = kk_function_as(struct kk_nagare_io_file__mlift_lift_walk_10389_10685_fun1628__t*, _fself, _ctx);
  kk_nagare_core_types__pull _uniq_tail_10315 = _self->_uniq_tail_10315; /* nagare/core/types/pull<list<std/os/path/path>,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>> */
  kk_drop_match(_self, {kk_nagare_core_types__pull_dup(_uniq_tail_10315, _ctx);}, {}, _ctx)
  return kk_nagare_io_file__lift_walk_10386(_uniq_tail_10315, _ctx);
}

kk_nagare_core_types__pull kk_nagare_io_file__mlift_lift_walk_10389_10685(kk_nagare_core_types__pull _uniq_tail_10315, kk_nagare_core_types__pull _y_x10532, kk_context_t* _ctx) { /* (nagare/core/types/pull<list<std/os/path/path>,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>, nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>) -> <alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>> nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>> */ 
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_nagare_core_types__pull x = kk_nagare_core_pull__unroll_pullAppend_10007(_y_x10532, kk_nagare_io_file__new_mlift_lift_walk_10389_10685_fun1628(_uniq_tail_10315, _ctx), _ctx); /*nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  return x;
}
 
// monadic lift

kk_nagare_core_types__pull kk_nagare_io_file__mlift_lift_walk_10386_10686(kk_nagare_core_types__pull _uniq_tail_10315_0, kk_nagare_core_types__pull _c_x10534, kk_context_t* _ctx) { /* (nagare/core/types/pull<list<std/os/path/path>,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>, nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>) -> nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>> */ 
  if (kk_nagare_core_types__is_PDone(_c_x10534, _ctx)) {
    return kk_nagare_io_file__lift_walk_10386(_uniq_tail_10315_0, _ctx);
  }
  {
    return kk_nagare_io_file__lift_walk_10389(_uniq_tail_10315_0, _c_x10534, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_nagare_io_file__mlift_lift_walk_10386_10687_fun1629__t {
  struct kk_function_s _base;
};
static kk_nagare_core_types__pull kk_nagare_io_file__mlift_lift_walk_10386_10687_fun1629(kk_function_t _fself, kk_box_t _b_x810, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__new_mlift_lift_walk_10386_10687_fun1629(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file__mlift_lift_walk_10386_10687_fun1629, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_nagare_core_types__pull kk_nagare_io_file__mlift_lift_walk_10386_10687_fun1629(kk_function_t _fself, kk_box_t _b_x810, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_nagare_core_types__chunk _x_x1630;
  kk_std_core_types__list _x_x1631 = kk_std_core_types__list_unbox(_b_x810, KK_OWNED, _ctx); /*list<std/os/path/path>*/
  _x_x1630 = kk_nagare_core_types__new_Chunk(_x_x1631, _ctx); /*nagare/core/types/chunk<4>*/
  return kk_nagare_core_types__new_POutput(kk_reuse_null, 0, _x_x1630, kk_nagare_core_types__new_PDone(_ctx), _ctx);
}

kk_nagare_core_types__pull kk_nagare_io_file__mlift_lift_walk_10386_10687(kk_nagare_core_types__pull _y_x10536, kk_context_t* _ctx) { /* (nagare/core/types/pull<list<std/os/path/path>,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>) -> <alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>> nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>> */ 
  kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_nagare_core_types__pull x_0 = kk_nagare_core_pull__unroll_pullFlatMap_10011(_y_x10536, kk_nagare_io_file__new_mlift_lift_walk_10386_10687_fun1629(_ctx), _ctx); /*nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_unit_t keep_0 = kk_Unit;
  kk_evv_set(w_0,kk_context());
  return x_0;
}
 
// lifted local: @lift-walk@10386, @lift-walk@10385, @lift-walk@10384, walk, @spec-x10366
// specialized: nagare/core/pull/@unroll-pullAppend@10007, on parameters @uniq-right@10355, using:
// @uniq-right@10355 = fn(){
//   @spec-x10329(@uniq-tail@10315);
// }


// lift anonymous function
struct kk_nagare_io_file__lift_walk_10389_fun1635__t {
  struct kk_function_s _base;
  kk_function_t _uniq_next_10361;
  kk_nagare_core_types__pull _uniq_tail_10315_1;
};
static kk_nagare_core_types__pull kk_nagare_io_file__lift_walk_10389_fun1635(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__new_lift_walk_10389_fun1635(kk_function_t _uniq_next_10361, kk_nagare_core_types__pull _uniq_tail_10315_1, kk_context_t* _ctx) {
  struct kk_nagare_io_file__lift_walk_10389_fun1635__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__lift_walk_10389_fun1635__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__lift_walk_10389_fun1635, kk_context());
  _self->_uniq_next_10361 = _uniq_next_10361;
  _self->_uniq_tail_10315_1 = _uniq_tail_10315_1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_io_file__lift_walk_10389_fun1637__t {
  struct kk_function_s _base;
  kk_nagare_core_types__pull _uniq_tail_10315_1;
};
static kk_box_t kk_nagare_io_file__lift_walk_10389_fun1637(kk_function_t _fself, kk_box_t _b_x815, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__new_lift_walk_10389_fun1637(kk_nagare_core_types__pull _uniq_tail_10315_1, kk_context_t* _ctx) {
  struct kk_nagare_io_file__lift_walk_10389_fun1637__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__lift_walk_10389_fun1637__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__lift_walk_10389_fun1637, kk_context());
  _self->_uniq_tail_10315_1 = _uniq_tail_10315_1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file__lift_walk_10389_fun1637(kk_function_t _fself, kk_box_t _b_x815, kk_context_t* _ctx) {
  struct kk_nagare_io_file__lift_walk_10389_fun1637__t* _self = kk_function_as(struct kk_nagare_io_file__lift_walk_10389_fun1637__t*, _fself, _ctx);
  kk_nagare_core_types__pull _uniq_tail_10315_1 = _self->_uniq_tail_10315_1; /* nagare/core/types/pull<list<std/os/path/path>,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>> */
  kk_drop_match(_self, {kk_nagare_core_types__pull_dup(_uniq_tail_10315_1, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull _y_x10532_0_817 = kk_nagare_core_types__pull_unbox(_b_x815, KK_OWNED, _ctx); /*nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_nagare_core_types__pull _x_x1638 = kk_nagare_io_file__mlift_lift_walk_10389_10685(_uniq_tail_10315_1, _y_x10532_0_817, _ctx); /*nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>*/
  return kk_nagare_core_types__pull_box(_x_x1638, _ctx);
}
static kk_nagare_core_types__pull kk_nagare_io_file__lift_walk_10389_fun1635(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_io_file__lift_walk_10389_fun1635__t* _self = kk_function_as(struct kk_nagare_io_file__lift_walk_10389_fun1635__t*, _fself, _ctx);
  kk_function_t _uniq_next_10361 = _self->_uniq_next_10361; /* () -> <alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>> nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>> */
  kk_nagare_core_types__pull _uniq_tail_10315_1 = _self->_uniq_tail_10315_1; /* nagare/core/types/pull<list<std/os/path/path>,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>> */
  kk_drop_match(_self, {kk_function_dup(_uniq_next_10361, _ctx);kk_nagare_core_types__pull_dup(_uniq_tail_10315_1, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull x_1_10917 = kk_function_call(kk_nagare_core_types__pull, (kk_function_t, kk_context_t*), _uniq_next_10361, (_uniq_next_10361, _ctx), _ctx); /*nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  if (kk_yielding(kk_context())) {
    kk_nagare_core_types__pull_drop(x_1_10917, _ctx);
    kk_box_t _x_x1636 = kk_std_core_hnd_yield_extend(kk_nagare_io_file__new_lift_walk_10389_fun1637(_uniq_tail_10315_1, _ctx), _ctx); /*10001*/
    return kk_nagare_core_types__pull_unbox(_x_x1636, KK_OWNED, _ctx);
  }
  {
    return kk_nagare_io_file__mlift_lift_walk_10389_10685(_uniq_tail_10315_1, x_1_10917, _ctx);
  }
}

kk_nagare_core_types__pull kk_nagare_io_file__lift_walk_10389(kk_nagare_core_types__pull _uniq_tail_10315_1, kk_nagare_core_types__pull _uniq_left_10354, kk_context_t* _ctx) { /* (nagare/core/types/pull<list<std/os/path/path>,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>, nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>) -> nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>> */ 
  if (kk_nagare_core_types__is_PDone(_uniq_left_10354, _ctx)) {
    return kk_nagare_io_file__lift_walk_10386(_uniq_tail_10315_1, _ctx);
  }
  if (kk_nagare_core_types__is_POutput(_uniq_left_10354, _ctx)) {
    struct kk_nagare_core_types_POutput* _con_x1632 = kk_nagare_core_types__as_POutput(_uniq_left_10354, _ctx);
    kk_nagare_core_types__chunk _uniq_out_10358 = _con_x1632->out;
    kk_nagare_core_types__pull _uniq_tail_10359 = _con_x1632->tail;
    kk_reuse_t _ru_x1135 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_left_10354, _ctx)) {
      _ru_x1135 = (kk_datatype_ptr_reuse(_uniq_left_10354, _ctx));
    }
    else {
      kk_nagare_core_types__chunk_dup(_uniq_out_10358, _ctx);
      kk_nagare_core_types__pull_dup(_uniq_tail_10359, _ctx);
      kk_datatype_ptr_decref(_uniq_left_10354, _ctx);
    }
    kk_nagare_core_types__pull _x_x1633 = kk_nagare_io_file__lift_walk_10389(_uniq_tail_10315_1, _uniq_tail_10359, _ctx); /*nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>*/
    return kk_nagare_core_types__new_POutput(_ru_x1135, 0, _uniq_out_10358, _x_x1633, _ctx);
  }
  if (kk_nagare_core_types__is_PEval(_uniq_left_10354, _ctx)) {
    struct kk_nagare_core_types_PEval* _con_x1634 = kk_nagare_core_types__as_PEval(_uniq_left_10354, _ctx);
    kk_function_t _uniq_next_10361 = _con_x1634->next;
    kk_reuse_t _ru_x1136 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_left_10354, _ctx)) {
      _ru_x1136 = (kk_datatype_ptr_reuse(_uniq_left_10354, _ctx));
    }
    else {
      kk_function_dup(_uniq_next_10361, _ctx);
      kk_datatype_ptr_decref(_uniq_left_10354, _ctx);
    }
    return kk_nagare_core_types__new_PEval(_ru_x1136, 0, kk_nagare_io_file__new_lift_walk_10389_fun1635(_uniq_next_10361, _uniq_tail_10315_1, _ctx), _ctx);
  }
  {
    struct kk_nagare_core_types_PAcquire* _con_x1639 = kk_nagare_core_types__as_PAcquire(_uniq_left_10354, _ctx);
    kk_function_t _uniq_acquire_10363 = _con_x1639->acquire;
    kk_function_t _uniq_release_10364 = _con_x1639->release;
    kk_nagare_core_types__pull _uniq_tail_0_10365 = _con_x1639->tail;
    kk_reuse_t _ru_x1137 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_left_10354, _ctx)) {
      _ru_x1137 = (kk_datatype_ptr_reuse(_uniq_left_10354, _ctx));
    }
    else {
      kk_function_dup(_uniq_acquire_10363, _ctx);
      kk_function_dup(_uniq_release_10364, _ctx);
      kk_nagare_core_types__pull_dup(_uniq_tail_0_10365, _ctx);
      kk_datatype_ptr_decref(_uniq_left_10354, _ctx);
    }
    kk_nagare_core_types__pull _x_x1640 = kk_nagare_io_file__lift_walk_10389(_uniq_tail_10315_1, _uniq_tail_0_10365, _ctx); /*nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>*/
    return kk_nagare_core_types__new_PAcquire(_ru_x1137, 0, _uniq_acquire_10363, _uniq_release_10364, _x_x1640, _ctx);
  }
}
 
// lifted local: @lift-walk@10385, @lift-walk@10384, walk, @spec-x10329
// specialized: nagare/core/pull/@unroll-pullFlatMap@10011, on parameters @uniq-f@10311, using:
// @uniq-f@10311 = fn(@uniq-x@10300: (list :: V -> V)<std/os/path/path>){
//   val @uniq-nextStep@10302 : (nagare/core/types/pull :: (V, E) -> V)<std/os/path/path,<(alloc :: H -> X)<(global :: H)>,(console/console :: X),(div :: X),(exn :: (E, V) -> V),(nagare/io/file_effect/fileSystem :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>>>
//         = nagare/core/types/POutput<std/os/path/path,<(alloc :: H -> X)<(global :: H)>,(console/console :: X),(div :: X),(exn :: (E, V) -> V),(nagare/io/file_effect/fileSystem :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>>>((nagare/core/types/Chunk<std/os/path/path>(@uniq-x@10300)), (nagare/core/types/PDone<std/os/path/path,<(alloc :: H -> X)<(global :: H)>,(console/console :: X),(div :: X),(exn :: (E, V) -> V),(nagare/io/file_effect/fileSystem :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>>>));
//   @uniq-nextStep@10302;
// }


// lift anonymous function
struct kk_nagare_io_file__lift_walk_10386_fun1643__t {
  struct kk_function_s _base;
  kk_nagare_core_types__pull _uniq_tail_10315_2;
};
static kk_box_t kk_nagare_io_file__lift_walk_10386_fun1643(kk_function_t _fself, kk_box_t _b_x819, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__new_lift_walk_10386_fun1643(kk_nagare_core_types__pull _uniq_tail_10315_2, kk_context_t* _ctx) {
  struct kk_nagare_io_file__lift_walk_10386_fun1643__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__lift_walk_10386_fun1643__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__lift_walk_10386_fun1643, kk_context());
  _self->_uniq_tail_10315_2 = _uniq_tail_10315_2;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file__lift_walk_10386_fun1643(kk_function_t _fself, kk_box_t _b_x819, kk_context_t* _ctx) {
  struct kk_nagare_io_file__lift_walk_10386_fun1643__t* _self = kk_function_as(struct kk_nagare_io_file__lift_walk_10386_fun1643__t*, _fself, _ctx);
  kk_nagare_core_types__pull _uniq_tail_10315_2 = _self->_uniq_tail_10315_2; /* nagare/core/types/pull<list<std/os/path/path>,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>> */
  kk_drop_match(_self, {kk_nagare_core_types__pull_dup(_uniq_tail_10315_2, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull _c_x10534_0_824 = kk_nagare_core_types__pull_unbox(_b_x819, KK_OWNED, _ctx); /*nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_nagare_core_types__pull _x_x1644 = kk_nagare_io_file__mlift_lift_walk_10386_10686(_uniq_tail_10315_2, _c_x10534_0_824, _ctx); /*nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>*/
  return kk_nagare_core_types__pull_box(_x_x1644, _ctx);
}


// lift anonymous function
struct kk_nagare_io_file__lift_walk_10386_fun1646__t {
  struct kk_function_s _base;
  kk_function_t _uniq_next_10324;
};
static kk_nagare_core_types__pull kk_nagare_io_file__lift_walk_10386_fun1646(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__new_lift_walk_10386_fun1646(kk_function_t _uniq_next_10324, kk_context_t* _ctx) {
  struct kk_nagare_io_file__lift_walk_10386_fun1646__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__lift_walk_10386_fun1646__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__lift_walk_10386_fun1646, kk_context());
  _self->_uniq_next_10324 = _uniq_next_10324;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_io_file__lift_walk_10386_fun1648__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_io_file__lift_walk_10386_fun1648(kk_function_t _fself, kk_box_t _b_x821, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__new_lift_walk_10386_fun1648(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file__lift_walk_10386_fun1648, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_io_file__lift_walk_10386_fun1648(kk_function_t _fself, kk_box_t _b_x821, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_nagare_core_types__pull _x_x1649;
  kk_nagare_core_types__pull _x_x1650 = kk_nagare_core_types__pull_unbox(_b_x821, KK_OWNED, _ctx); /*nagare/core/types/pull<list<std/os/path/path>,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>*/
  _x_x1649 = kk_nagare_io_file__mlift_lift_walk_10386_10687(_x_x1650, _ctx); /*nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>*/
  return kk_nagare_core_types__pull_box(_x_x1649, _ctx);
}
static kk_nagare_core_types__pull kk_nagare_io_file__lift_walk_10386_fun1646(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_io_file__lift_walk_10386_fun1646__t* _self = kk_function_as(struct kk_nagare_io_file__lift_walk_10386_fun1646__t*, _fself, _ctx);
  kk_function_t _uniq_next_10324 = _self->_uniq_next_10324; /* () -> <alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>> nagare/core/types/pull<list<std/os/path/path>,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>> */
  kk_drop_match(_self, {kk_function_dup(_uniq_next_10324, _ctx);}, {}, _ctx)
  kk_nagare_core_types__pull x_3_10922 = kk_function_call(kk_nagare_core_types__pull, (kk_function_t, kk_context_t*), _uniq_next_10324, (_uniq_next_10324, _ctx), _ctx); /*nagare/core/types/pull<list<std/os/path/path>,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  if (kk_yielding(kk_context())) {
    kk_nagare_core_types__pull_drop(x_3_10922, _ctx);
    kk_box_t _x_x1647 = kk_std_core_hnd_yield_extend(kk_nagare_io_file__new_lift_walk_10386_fun1648(_ctx), _ctx); /*10001*/
    return kk_nagare_core_types__pull_unbox(_x_x1647, KK_OWNED, _ctx);
  }
  {
    return kk_nagare_io_file__mlift_lift_walk_10386_10687(x_3_10922, _ctx);
  }
}

kk_nagare_core_types__pull kk_nagare_io_file__lift_walk_10386(kk_nagare_core_types__pull _uniq_source_10310, kk_context_t* _ctx) { /* (nagare/core/types/pull<list<std/os/path/path>,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>) -> nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>> */ 
  kk__tailcall: ;
  if (kk_nagare_core_types__is_PDone(_uniq_source_10310, _ctx)) {
    return kk_nagare_core_types__new_PDone(_ctx);
  }
  if (kk_nagare_core_types__is_POutput(_uniq_source_10310, _ctx)) {
    struct kk_nagare_core_types_POutput* _con_x1641 = kk_nagare_core_types__as_POutput(_uniq_source_10310, _ctx);
    kk_nagare_core_types__chunk _uniq_out_10314 = _con_x1641->out;
    kk_nagare_core_types__pull _uniq_tail_10315_2 = _con_x1641->tail;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_source_10310, _ctx)) {
      kk_datatype_ptr_free(_uniq_source_10310, _ctx);
    }
    else {
      kk_nagare_core_types__chunk_dup(_uniq_out_10314, _ctx);
      kk_nagare_core_types__pull_dup(_uniq_tail_10315_2, _ctx);
      kk_datatype_ptr_decref(_uniq_source_10310, _ctx);
    }
    {
      kk_std_core_types__list _uniq_values_10317 = _uniq_out_10314.values;
      kk_nagare_core_types__pull x_2_10919;
      if (kk_std_core_types__is_Nil(_uniq_values_10317, _ctx)) {
        x_2_10919 = kk_nagare_core_types__new_PDone(_ctx); /*nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>*/
      }
      else {
        x_2_10919 = kk_nagare_io_file__lift_walk_10387(_uniq_values_10317, _ctx); /*nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>*/
      }
      if (kk_yielding(kk_context())) {
        kk_nagare_core_types__pull_drop(x_2_10919, _ctx);
        kk_box_t _x_x1642 = kk_std_core_hnd_yield_extend(kk_nagare_io_file__new_lift_walk_10386_fun1643(_uniq_tail_10315_2, _ctx), _ctx); /*10001*/
        return kk_nagare_core_types__pull_unbox(_x_x1642, KK_OWNED, _ctx);
      }
      if (kk_nagare_core_types__is_PDone(x_2_10919, _ctx)) { // tailcall
                                                             _uniq_source_10310 = _uniq_tail_10315_2;
                                                             goto kk__tailcall;
      }
      {
        return kk_nagare_io_file__lift_walk_10389(_uniq_tail_10315_2, x_2_10919, _ctx);
      }
    }
  }
  if (kk_nagare_core_types__is_PEval(_uniq_source_10310, _ctx)) {
    struct kk_nagare_core_types_PEval* _con_x1645 = kk_nagare_core_types__as_PEval(_uniq_source_10310, _ctx);
    kk_function_t _uniq_next_10324 = _con_x1645->next;
    kk_reuse_t _ru_x1139 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_source_10310, _ctx)) {
      _ru_x1139 = (kk_datatype_ptr_reuse(_uniq_source_10310, _ctx));
    }
    else {
      kk_function_dup(_uniq_next_10324, _ctx);
      kk_datatype_ptr_decref(_uniq_source_10310, _ctx);
    }
    return kk_nagare_core_types__new_PEval(_ru_x1139, 0, kk_nagare_io_file__new_lift_walk_10386_fun1646(_uniq_next_10324, _ctx), _ctx);
  }
  {
    struct kk_nagare_core_types_PAcquire* _con_x1651 = kk_nagare_core_types__as_PAcquire(_uniq_source_10310, _ctx);
    kk_function_t _uniq_acquire_10326 = _con_x1651->acquire;
    kk_function_t _uniq_release_10327 = _con_x1651->release;
    kk_nagare_core_types__pull _uniq_tail_0_10328 = _con_x1651->tail;
    kk_reuse_t _ru_x1140 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_source_10310, _ctx)) {
      _ru_x1140 = (kk_datatype_ptr_reuse(_uniq_source_10310, _ctx));
    }
    else {
      kk_function_dup(_uniq_acquire_10326, _ctx);
      kk_function_dup(_uniq_release_10327, _ctx);
      kk_nagare_core_types__pull_dup(_uniq_tail_0_10328, _ctx);
      kk_datatype_ptr_decref(_uniq_source_10310, _ctx);
    }
    kk_nagare_core_types__pull _x_x1652 = kk_nagare_io_file__lift_walk_10386(_uniq_tail_0_10328, _ctx); /*nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>*/
    return kk_nagare_core_types__new_PAcquire(_ru_x1140, 0, _uniq_acquire_10326, _uniq_release_10327, _x_x1652, _ctx);
  }
}
 
// lifted local: @lift-walk@10384, walk, @spec-x10309
// specialized: nagare/core/pull/pullFlatMap, on parameters @uniq-f@10306, using:
// @uniq-f@10306 = fn(@uniq-x@10300: (list :: V -> V)<std/os/path/path>){
//   val entries@10304 : (list :: V -> V)<std/os/path/path>;
//   val @uniq-nextStep@10302 : (nagare/core/types/pull :: (V, E) -> V)<std/os/path/path,<(alloc :: H -> X)<(global :: H)>,(console/console :: X),(div :: X),(exn :: (E, V) -> V),(nagare/io/file_effect/fileSystem :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>>>;
//   val @uniq-pat@0@10301 : (nagare/core/types/nstream :: (V, E) -> V)<std/os/path/path,<(alloc :: H -> X)<(global :: H)>,(console/console :: X),(div :: X),(exn :: (E, V) -> V),(nagare/io/file_effect/fileSystem :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>>>;
//   val @scrut : (nagare/core/types/nstream :: (V, E) -> V)<std/os/path/path,<(alloc :: H -> X)<(global :: H)>,(console/console :: X),(div :: X),(exn :: (E, V) -> V),(nagare/io/file_effect/fileSystem :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>>>;
//   @uniq-nextStep@10302;
// }

kk_nagare_core_types__pull kk_nagare_io_file__lift_walk_10385(kk_nagare_core_types__pull _uniq_source_10305, kk_context_t* _ctx) { /* (nagare/core/types/pull<list<std/os/path/path>,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>) -> nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>> */ 
  if (kk_nagare_core_types__is_PDone(_uniq_source_10305, _ctx)) {
    return kk_nagare_core_types__new_PDone(_ctx);
  }
  {
    return kk_nagare_io_file__lift_walk_10386(_uniq_source_10305, _ctx);
  }
}
 
// lifted local: walk, @spec-x10303
// specialized: nagare/core/stream/flatMap, on parameters @uniq-f@10297, using:
// @uniq-f@10297 = fn(entries: (list :: V -> V)<std/os/path/path>){
//   nagare/core/types/Stream<std/os/path/path,<(alloc :: H -> X)<(global :: H)>,(console/console :: X),(div :: X),(exn :: (E, V) -> V),(nagare/io/file_effect/fileSystem :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>>>((nagare/core/types/POutput<std/os/path/path,<(alloc :: H -> X)<(global :: H)>,(console/console :: X),(div :: X),(exn :: (E, V) -> V),(nagare/io/file_effect/fileSystem :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>>>((nagare/core/types/Chunk<std/os/path/path>(entries)), (nagare/core/types/PDone<std/os/path/path,<(alloc :: H -> X)<(global :: H)>,(console/console :: X),(div :: X),(exn :: (E, V) -> V),(nagare/io/file_effect/fileSystem :: (E, V) -> V),(fsys :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>>>))));
// }

kk_nagare_core_types__nstream kk_nagare_io_file__lift_walk_10384(kk_nagare_core_types__nstream _uniq_source_10296, kk_context_t* _ctx) { /* (nagare/core/types/nstream<list<std/os/path/path>,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>) -> nagare/core/types/nstream<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>> */ 
  {
    kk_nagare_core_types__pull _uniq_step_10299 = _uniq_source_10296.step;
    kk_nagare_core_types__pull _x_x1653 = kk_nagare_io_file__lift_walk_10385(_uniq_step_10299, _ctx); /*nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>*/
    return kk_nagare_core_types__new_Stream(_x_x1653, _ctx);
  }
}


// lift anonymous function
struct kk_nagare_io_file_walk_fun1658__t {
  struct kk_function_s _base;
  kk_std_os_path__path dir;
  kk_std_core_types__optional maxDepth;
};
static kk_nagare_core_types__pull kk_nagare_io_file_walk_fun1658(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_walk_fun1658(kk_std_os_path__path dir, kk_std_core_types__optional maxDepth, kk_context_t* _ctx) {
  struct kk_nagare_io_file_walk_fun1658__t* _self = kk_function_alloc_as(struct kk_nagare_io_file_walk_fun1658__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file_walk_fun1658, kk_context());
  _self->dir = dir;
  _self->maxDepth = maxDepth;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_io_file_walk_fun1660__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_io_file_walk_fun1660(kk_function_t _fself, kk_box_t _b_x831, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_walk_fun1660(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file_walk_fun1660, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_io_file_walk_fun1660(kk_function_t _fself, kk_box_t _b_x831, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1661;
  kk_std_os_path__path _x_x1662 = kk_std_os_path__path_unbox(_b_x831, KK_OWNED, _ctx); /*std/os/path/path*/
  _x_x1661 = kk_std_os_path_string(_x_x1662, _ctx); /*string*/
  return kk_string_box(_x_x1661);
}


// lift anonymous function
struct kk_nagare_io_file_walk_fun1670__t {
  struct kk_function_s _base;
  kk_ssize_t i_10926;
};
static kk_box_t kk_nagare_io_file_walk_fun1670(kk_function_t _fself, kk_function_t _b_x854, kk_box_t _b_x855, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_walk_fun1670(kk_ssize_t i_10926, kk_context_t* _ctx) {
  struct kk_nagare_io_file_walk_fun1670__t* _self = kk_function_alloc_as(struct kk_nagare_io_file_walk_fun1670__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file_walk_fun1670, kk_context());
  _self->i_10926 = i_10926;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file_walk_fun1670(kk_function_t _fself, kk_function_t _b_x854, kk_box_t _b_x855, kk_context_t* _ctx) {
  struct kk_nagare_io_file_walk_fun1670__t* _self = kk_function_as(struct kk_nagare_io_file_walk_fun1670__t*, _fself, _ctx);
  kk_ssize_t i_10926 = _self->i_10926; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_10926, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_10926, _b_x854, _b_x855, _ctx);
}


// lift anonymous function
struct kk_nagare_io_file_walk_fun1672__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_io_file_walk_fun1672(kk_function_t _fself, kk_box_t _b_x864, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_walk_fun1672(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file_walk_fun1672, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_io_file_walk_fun1672(kk_function_t _fself, kk_box_t _b_x864, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_nagare_core_types__pull _x_x1673;
  kk_std_core_types__list _x_x1674 = kk_std_core_types__list_unbox(_b_x864, KK_OWNED, _ctx); /*list<std/os/path/path>*/
  _x_x1673 = kk_nagare_io_file__mlift_walk_10688(_x_x1674, _ctx); /*nagare/core/types/pull<list<std/os/path/path>,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>*/
  return kk_nagare_core_types__pull_box(_x_x1673, _ctx);
}
static kk_nagare_core_types__pull kk_nagare_io_file_walk_fun1658(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_io_file_walk_fun1658__t* _self = kk_function_as(struct kk_nagare_io_file_walk_fun1658__t*, _fself, _ctx);
  kk_std_os_path__path dir = _self->dir; /* std/os/path/path */
  kk_std_core_types__optional maxDepth = _self->maxDepth; /* ? int */
  kk_drop_match(_self, {kk_std_os_path__path_dup(dir, _ctx);kk_std_core_types__optional_dup(maxDepth, _ctx);}, {}, _ctx)
  kk_string_t _x_x1_10647;
  kk_box_t _x_x1659 = kk_std_core_hnd__open_none1(kk_nagare_io_file_new_walk_fun1660(_ctx), kk_std_os_path__path_box(dir, _ctx), _ctx); /*10001*/
  _x_x1_10647 = kk_string_unbox(_x_x1659); /*string*/
  kk_ssize_t i_10926 = (KK_IZ(1)); /*hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_10926,kk_context()); /*hnd/evv<<nagare/io/file_effect/fileSystem,alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_std_core_hnd__ev ev_10931 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<nagare/io/file_effect/fileSystem>*/;
  kk_std_core_types__list y;
  kk_box_t _x_x1663;
  {
    struct kk_std_core_hnd_Ev* _con_x1664 = kk_std_core_hnd__as_Ev(ev_10931, _ctx);
    kk_box_t _box_x834 = _con_x1664->hnd;
    int32_t m = _con_x1664->marker;
    kk_nagare_io_file__effect__fileSystem h = kk_nagare_io_file__effect__fileSystem_unbox(_box_x834, KK_BORROWED, _ctx);
    kk_nagare_io_file__effect__fileSystem_dup(h, _ctx);
    kk_std_core_hnd__clause1 _match_x983;
    kk_std_core_hnd__clause1 _brw_x984 = kk_nagare_io_file__effect_listChildren_fs__select(h, _ctx); /*hnd/clause1<(string, bool, int),list<std/os/path/path>,nagare/io/file_effect/fileSystem,2059,2060>*/;
    kk_datatype_ptr_dropn(h, (KK_I32(4)), _ctx);
    _match_x983 = _brw_x984; /*hnd/clause1<(string, bool, int),list<std/os/path/path>,nagare/io/file_effect/fileSystem,2059,2060>*/
    {
      kk_function_t _fun_unbox_x838 = _match_x983.clause;
      kk_box_t _x_x1665;
      kk_std_core_types__tuple3 _x_x1666;
      kk_box_t _x_x1667;
      kk_integer_t _x_x1668;
      if (kk_std_core_types__is_Optional(maxDepth, _ctx)) {
        kk_box_t _box_x842 = maxDepth._cons._Optional.value;
        kk_integer_t _uniq_maxDepth_2475 = kk_integer_unbox(_box_x842, _ctx);
        kk_integer_dup(_uniq_maxDepth_2475, _ctx);
        kk_std_core_types__optional_drop(maxDepth, _ctx);
        _x_x1668 = _uniq_maxDepth_2475; /*int*/
      }
      else {
        kk_std_core_types__optional_drop(maxDepth, _ctx);
        _x_x1668 = kk_integer_from_small(1000); /*int*/
      }
      _x_x1667 = kk_integer_box(_x_x1668, _ctx); /*10043*/
      _x_x1666 = kk_std_core_types__new_Tuple3(kk_string_box(_x_x1_10647), kk_bool_box(true), _x_x1667, _ctx); /*(10041, 10042, 10043)*/
      _x_x1665 = kk_std_core_types__tuple3_box(_x_x1666, _ctx); /*10009*/
      _x_x1663 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x838, (_fun_unbox_x838, m, ev_10931, _x_x1665, _ctx), _ctx); /*10010*/
    }
  }
  y = kk_std_core_types__list_unbox(_x_x1663, KK_OWNED, _ctx); /*list<std/os/path/path>*/
  kk_evv_set(w,kk_context());
  kk_std_core_types__list x_10924;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(y, _ctx);
    kk_box_t _x_x1669 = kk_std_core_hnd_yield_cont(kk_nagare_io_file_new_walk_fun1670(i_10926, _ctx), _ctx); /*10002*/
    x_10924 = kk_std_core_types__list_unbox(_x_x1669, KK_OWNED, _ctx); /*list<std/os/path/path>*/
  }
  else {
    x_10924 = y; /*list<std/os/path/path>*/
  }
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_10924, _ctx);
    kk_box_t _x_x1671 = kk_std_core_hnd_yield_extend(kk_nagare_io_file_new_walk_fun1672(_ctx), _ctx); /*10001*/
    return kk_nagare_core_types__pull_unbox(_x_x1671, KK_OWNED, _ctx);
  }
  {
    kk_std_core_types__list _b_x865_869 = x_10924; /*list<std/os/path/path>*/;
    kk_std_core_types__list _b_x866_870 = kk_std_core_types__new_Nil(_ctx); /*list<list<std/os/path/path>>*/;
    kk_nagare_core_types__chunk _x_x1675;
    kk_std_core_types__list _x_x1676 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_std_core_types__list_box(_b_x865_869, _ctx), _b_x866_870, _ctx); /*list<10021>*/
    _x_x1675 = kk_nagare_core_types__new_Chunk(_x_x1676, _ctx); /*nagare/core/types/chunk<4>*/
    return kk_nagare_core_types__new_POutput(kk_reuse_null, 0, _x_x1675, kk_nagare_core_types__new_PDone(_ctx), _ctx);
  }
}

kk_nagare_core_types__nstream kk_nagare_io_file_walk(kk_std_os_path__path dir, kk_std_core_types__optional maxDepth, kk_context_t* _ctx) { /* (dir : std/os/path/path, maxDepth : ? int) -> nagare/io/file_effect/fsStream<std/os/path/path> */ 
  kk_nagare_core_types__nstream _x_x1656;
  kk_nagare_core_types__pull _x_x1657 = kk_nagare_core_types__new_PEval(kk_reuse_null, 0, kk_nagare_io_file_new_walk_fun1658(dir, maxDepth, _ctx), _ctx); /*nagare/core/types/pull<19,20>*/
  _x_x1656 = kk_nagare_core_types__new_Stream(_x_x1657, _ctx); /*nagare/core/types/nstream<27,28>*/
  return kk_nagare_io_file__lift_walk_10384(_x_x1656, _ctx);
}


// lift anonymous function
struct kk_nagare_io_file_pathExists_fun1680__t {
  struct kk_function_s _base;
  kk_std_os_path__path filepath;
};
static kk_nagare_core_types__pull kk_nagare_io_file_pathExists_fun1680(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_pathExists_fun1680(kk_std_os_path__path filepath, kk_context_t* _ctx) {
  struct kk_nagare_io_file_pathExists_fun1680__t* _self = kk_function_alloc_as(struct kk_nagare_io_file_pathExists_fun1680__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file_pathExists_fun1680, kk_context());
  _self->filepath = filepath;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_io_file_pathExists_fun1682__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_io_file_pathExists_fun1682(kk_function_t _fself, kk_box_t _b_x877, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_pathExists_fun1682(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file_pathExists_fun1682, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_io_file_pathExists_fun1682(kk_function_t _fself, kk_box_t _b_x877, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1683;
  kk_std_os_path__path _x_x1684 = kk_std_os_path__path_unbox(_b_x877, KK_OWNED, _ctx); /*std/os/path/path*/
  _x_x1683 = kk_std_os_path_string(_x_x1684, _ctx); /*string*/
  return kk_string_box(_x_x1683);
}


// lift anonymous function
struct kk_nagare_io_file_pathExists_fun1688__t {
  struct kk_function_s _base;
  kk_ssize_t i_10938;
};
static kk_box_t kk_nagare_io_file_pathExists_fun1688(kk_function_t _fself, kk_function_t _b_x893, kk_box_t _b_x894, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_pathExists_fun1688(kk_ssize_t i_10938, kk_context_t* _ctx) {
  struct kk_nagare_io_file_pathExists_fun1688__t* _self = kk_function_alloc_as(struct kk_nagare_io_file_pathExists_fun1688__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file_pathExists_fun1688, kk_context());
  _self->i_10938 = i_10938;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file_pathExists_fun1688(kk_function_t _fself, kk_function_t _b_x893, kk_box_t _b_x894, kk_context_t* _ctx) {
  struct kk_nagare_io_file_pathExists_fun1688__t* _self = kk_function_as(struct kk_nagare_io_file_pathExists_fun1688__t*, _fself, _ctx);
  kk_ssize_t i_10938 = _self->i_10938; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_10938, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_10938, _b_x893, _b_x894, _ctx);
}


// lift anonymous function
struct kk_nagare_io_file_pathExists_fun1690__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_io_file_pathExists_fun1690(kk_function_t _fself, kk_box_t _b_x903, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_pathExists_fun1690(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file_pathExists_fun1690, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_io_file_pathExists_fun1690(kk_function_t _fself, kk_box_t _b_x903, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_nagare_core_types__pull _x_x1691;
  bool _x_x1692 = kk_bool_unbox(_b_x903); /*bool*/
  _x_x1691 = kk_nagare_io_file__mlift_pathExists_10689(_x_x1692, _ctx); /*nagare/core/types/pull<bool,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>*/
  return kk_nagare_core_types__pull_box(_x_x1691, _ctx);
}
static kk_nagare_core_types__pull kk_nagare_io_file_pathExists_fun1680(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_io_file_pathExists_fun1680__t* _self = kk_function_as(struct kk_nagare_io_file_pathExists_fun1680__t*, _fself, _ctx);
  kk_std_os_path__path filepath = _self->filepath; /* std/os/path/path */
  kk_drop_match(_self, {kk_std_os_path__path_dup(filepath, _ctx);}, {}, _ctx)
  kk_string_t _x_x1_10651;
  kk_box_t _x_x1681 = kk_std_core_hnd__open_none1(kk_nagare_io_file_new_pathExists_fun1682(_ctx), kk_std_os_path__path_box(filepath, _ctx), _ctx); /*10001*/
  _x_x1_10651 = kk_string_unbox(_x_x1681); /*string*/
  kk_ssize_t i_10938 = (KK_IZ(1)); /*hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_10938,kk_context()); /*hnd/evv<<nagare/io/file_effect/fileSystem,alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_std_core_hnd__ev ev_10941 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<nagare/io/file_effect/fileSystem>*/;
  bool y;
  kk_box_t _x_x1685;
  {
    struct kk_std_core_hnd_Ev* _con_x1686 = kk_std_core_hnd__as_Ev(ev_10941, _ctx);
    kk_box_t _box_x880 = _con_x1686->hnd;
    int32_t m = _con_x1686->marker;
    kk_nagare_io_file__effect__fileSystem h = kk_nagare_io_file__effect__fileSystem_unbox(_box_x880, KK_BORROWED, _ctx);
    kk_nagare_io_file__effect__fileSystem_dup(h, _ctx);
    kk_std_core_hnd__clause1 _match_x979;
    kk_std_core_hnd__clause1 _brw_x980 = kk_nagare_io_file__effect_fileExistsOp_fs__select(h, _ctx); /*hnd/clause1<string,bool,nagare/io/file_effect/fileSystem,1845,1846>*/;
    kk_datatype_ptr_dropn(h, (KK_I32(4)), _ctx);
    _match_x979 = _brw_x980; /*hnd/clause1<string,bool,nagare/io/file_effect/fileSystem,1845,1846>*/
    {
      kk_function_t _fun_unbox_x884 = _match_x979.clause;
      _x_x1685 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x884, (_fun_unbox_x884, m, ev_10941, kk_string_box(_x_x1_10651), _ctx), _ctx); /*10010*/
    }
  }
  y = kk_bool_unbox(_x_x1685); /*bool*/
  kk_evv_set(w,kk_context());
  bool x_10936;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1687 = kk_std_core_hnd_yield_cont(kk_nagare_io_file_new_pathExists_fun1688(i_10938, _ctx), _ctx); /*10002*/
    x_10936 = kk_bool_unbox(_x_x1687); /*bool*/
  }
  else {
    x_10936 = y; /*bool*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1689 = kk_std_core_hnd_yield_extend(kk_nagare_io_file_new_pathExists_fun1690(_ctx), _ctx); /*10001*/
    return kk_nagare_core_types__pull_unbox(_x_x1689, KK_OWNED, _ctx);
  }
  {
    bool _b_x904_908 = x_10936; /*bool*/;
    kk_std_core_types__list _b_x905_909 = kk_std_core_types__new_Nil(_ctx); /*list<bool>*/;
    kk_nagare_core_types__chunk _x_x1693;
    kk_std_core_types__list _x_x1694 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_bool_box(_b_x904_908), _b_x905_909, _ctx); /*list<10021>*/
    _x_x1693 = kk_nagare_core_types__new_Chunk(_x_x1694, _ctx); /*nagare/core/types/chunk<4>*/
    return kk_nagare_core_types__new_POutput(kk_reuse_null, 0, _x_x1693, kk_nagare_core_types__new_PDone(_ctx), _ctx);
  }
}

kk_nagare_core_types__nstream kk_nagare_io_file_pathExists(kk_std_os_path__path filepath, kk_context_t* _ctx) { /* (filepath : std/os/path/path) -> nagare/io/file_effect/fsStream<bool> */ 
  kk_nagare_core_types__pull _x_x1679 = kk_nagare_core_types__new_PEval(kk_reuse_null, 0, kk_nagare_io_file_new_pathExists_fun1680(filepath, _ctx), _ctx); /*nagare/core/types/pull<19,20>*/
  return kk_nagare_core_types__new_Stream(_x_x1679, _ctx);
}


// lift anonymous function
struct kk_nagare_io_file_createDir_fun1698__t {
  struct kk_function_s _base;
  kk_std_os_path__path dir;
};
static kk_nagare_core_types__pull kk_nagare_io_file_createDir_fun1698(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_createDir_fun1698(kk_std_os_path__path dir, kk_context_t* _ctx) {
  struct kk_nagare_io_file_createDir_fun1698__t* _self = kk_function_alloc_as(struct kk_nagare_io_file_createDir_fun1698__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file_createDir_fun1698, kk_context());
  _self->dir = dir;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_io_file_createDir_fun1700__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_io_file_createDir_fun1700(kk_function_t _fself, kk_box_t _b_x915, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_createDir_fun1700(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file_createDir_fun1700, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_io_file_createDir_fun1700(kk_function_t _fself, kk_box_t _b_x915, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_nagare_core_types__pull _x_x1701;
  kk_unit_t _x_x1702 = kk_Unit;
  kk_unit_unbox(_b_x915);
  _x_x1701 = kk_nagare_io_file__mlift_createDir_10690(_x_x1702, _ctx); /*nagare/core/types/pull<(),io>*/
  return kk_nagare_core_types__pull_box(_x_x1701, _ctx);
}
static kk_nagare_core_types__pull kk_nagare_io_file_createDir_fun1698(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_io_file_createDir_fun1698__t* _self = kk_function_as(struct kk_nagare_io_file_createDir_fun1698__t*, _fself, _ctx);
  kk_std_os_path__path dir = _self->dir; /* std/os/path/path */
  kk_drop_match(_self, {kk_std_os_path__path_dup(dir, _ctx);}, {}, _ctx)
  kk_unit_t x_10944 = kk_Unit;
  kk_std_os_dir_ensure_dir(dir, _ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1699 = kk_std_core_hnd_yield_extend(kk_nagare_io_file_new_createDir_fun1700(_ctx), _ctx); /*10001*/
    return kk_nagare_core_types__pull_unbox(_x_x1699, KK_OWNED, _ctx);
  }
  {
    kk_unit_t _b_x916_919 = kk_Unit;
    x_10944;
    kk_std_core_types__list _b_x917_920 = kk_std_core_types__new_Nil(_ctx); /*list<()>*/;
    kk_nagare_core_types__chunk _x_x1703;
    kk_std_core_types__list _x_x1704 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_unit_box(_b_x916_919), _b_x917_920, _ctx); /*list<10021>*/
    _x_x1703 = kk_nagare_core_types__new_Chunk(_x_x1704, _ctx); /*nagare/core/types/chunk<4>*/
    return kk_nagare_core_types__new_POutput(kk_reuse_null, 0, _x_x1703, kk_nagare_core_types__new_PDone(_ctx), _ctx);
  }
}

kk_nagare_core_types__nstream kk_nagare_io_file_createDir(kk_std_os_path__path dir, kk_context_t* _ctx) { /* (dir : std/os/path/path) -> nagare/core/types/iostream<()> */ 
  kk_nagare_core_types__pull _x_x1697 = kk_nagare_core_types__new_PEval(kk_reuse_null, 0, kk_nagare_io_file_new_createDir_fun1698(dir, _ctx), _ctx); /*nagare/core/types/pull<19,20>*/
  return kk_nagare_core_types__new_Stream(_x_x1697, _ctx);
}


// lift anonymous function
struct kk_nagare_io_file_fileCopy_fun1708__t {
  struct kk_function_s _base;
  kk_std_os_path__path from;
  kk_std_os_path__path to;
};
static kk_nagare_core_types__pull kk_nagare_io_file_fileCopy_fun1708(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_fileCopy_fun1708(kk_std_os_path__path from, kk_std_os_path__path to, kk_context_t* _ctx) {
  struct kk_nagare_io_file_fileCopy_fun1708__t* _self = kk_function_alloc_as(struct kk_nagare_io_file_fileCopy_fun1708__t, 5, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file_fileCopy_fun1708, kk_context());
  _self->from = from;
  _self->to = to;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_io_file_fileCopy_fun1710__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_io_file_fileCopy_fun1710(kk_function_t _fself, kk_box_t _b_x926, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_fileCopy_fun1710(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file_fileCopy_fun1710, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_io_file_fileCopy_fun1710(kk_function_t _fself, kk_box_t _b_x926, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_nagare_core_types__pull _x_x1711;
  kk_unit_t _x_x1712 = kk_Unit;
  kk_unit_unbox(_b_x926);
  _x_x1711 = kk_nagare_io_file__mlift_fileCopy_10691(_x_x1712, _ctx); /*nagare/core/types/pull<(),io>*/
  return kk_nagare_core_types__pull_box(_x_x1711, _ctx);
}
static kk_nagare_core_types__pull kk_nagare_io_file_fileCopy_fun1708(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_io_file_fileCopy_fun1708__t* _self = kk_function_as(struct kk_nagare_io_file_fileCopy_fun1708__t*, _fself, _ctx);
  kk_std_os_path__path from = _self->from; /* std/os/path/path */
  kk_std_os_path__path to = _self->to; /* std/os/path/path */
  kk_drop_match(_self, {kk_std_os_path__path_dup(from, _ctx);kk_std_os_path__path_dup(to, _ctx);}, {}, _ctx)
  kk_unit_t x_10946 = kk_Unit;
  kk_std_os_dir_copy_file(from, to, kk_std_core_types__new_None(_ctx), _ctx);
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1709 = kk_std_core_hnd_yield_extend(kk_nagare_io_file_new_fileCopy_fun1710(_ctx), _ctx); /*10001*/
    return kk_nagare_core_types__pull_unbox(_x_x1709, KK_OWNED, _ctx);
  }
  {
    kk_unit_t _b_x927_930 = kk_Unit;
    x_10946;
    kk_std_core_types__list _b_x928_931 = kk_std_core_types__new_Nil(_ctx); /*list<()>*/;
    kk_nagare_core_types__chunk _x_x1713;
    kk_std_core_types__list _x_x1714 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_unit_box(_b_x927_930), _b_x928_931, _ctx); /*list<10021>*/
    _x_x1713 = kk_nagare_core_types__new_Chunk(_x_x1714, _ctx); /*nagare/core/types/chunk<4>*/
    return kk_nagare_core_types__new_POutput(kk_reuse_null, 0, _x_x1713, kk_nagare_core_types__new_PDone(_ctx), _ctx);
  }
}

kk_nagare_core_types__nstream kk_nagare_io_file_fileCopy(kk_std_os_path__path from, kk_std_os_path__path to, kk_context_t* _ctx) { /* (from : std/os/path/path, to : std/os/path/path) -> nagare/core/types/iostream<()> */ 
  kk_nagare_core_types__pull _x_x1707 = kk_nagare_core_types__new_PEval(kk_reuse_null, 0, kk_nagare_io_file_new_fileCopy_fun1708(from, to, _ctx), _ctx); /*nagare/core/types/pull<19,20>*/
  return kk_nagare_core_types__new_Stream(_x_x1707, _ctx);
}


// lift anonymous function
struct kk_nagare_io_file_deleteFile_fun1718__t {
  struct kk_function_s _base;
  kk_std_os_path__path filepath;
};
static kk_nagare_core_types__pull kk_nagare_io_file_deleteFile_fun1718(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_deleteFile_fun1718(kk_std_os_path__path filepath, kk_context_t* _ctx) {
  struct kk_nagare_io_file_deleteFile_fun1718__t* _self = kk_function_alloc_as(struct kk_nagare_io_file_deleteFile_fun1718__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file_deleteFile_fun1718, kk_context());
  _self->filepath = filepath;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_io_file_deleteFile_fun1720__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_io_file_deleteFile_fun1720(kk_function_t _fself, kk_box_t _b_x938, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_deleteFile_fun1720(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file_deleteFile_fun1720, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_io_file_deleteFile_fun1720(kk_function_t _fself, kk_box_t _b_x938, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1721;
  kk_std_os_path__path _x_x1722 = kk_std_os_path__path_unbox(_b_x938, KK_OWNED, _ctx); /*std/os/path/path*/
  _x_x1721 = kk_std_os_path_string(_x_x1722, _ctx); /*string*/
  return kk_string_box(_x_x1721);
}


// lift anonymous function
struct kk_nagare_io_file_deleteFile_fun1726__t {
  struct kk_function_s _base;
  kk_ssize_t i_10950;
};
static kk_box_t kk_nagare_io_file_deleteFile_fun1726(kk_function_t _fself, kk_function_t _b_x954, kk_box_t _b_x955, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_deleteFile_fun1726(kk_ssize_t i_10950, kk_context_t* _ctx) {
  struct kk_nagare_io_file_deleteFile_fun1726__t* _self = kk_function_alloc_as(struct kk_nagare_io_file_deleteFile_fun1726__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file_deleteFile_fun1726, kk_context());
  _self->i_10950 = i_10950;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file_deleteFile_fun1726(kk_function_t _fself, kk_function_t _b_x954, kk_box_t _b_x955, kk_context_t* _ctx) {
  struct kk_nagare_io_file_deleteFile_fun1726__t* _self = kk_function_as(struct kk_nagare_io_file_deleteFile_fun1726__t*, _fself, _ctx);
  kk_ssize_t i_10950 = _self->i_10950; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_10950, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_10950, _b_x954, _b_x955, _ctx);
}


// lift anonymous function
struct kk_nagare_io_file_deleteFile_fun1728__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_io_file_deleteFile_fun1728(kk_function_t _fself, kk_box_t _b_x964, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file_new_deleteFile_fun1728(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file_deleteFile_fun1728, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_io_file_deleteFile_fun1728(kk_function_t _fself, kk_box_t _b_x964, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_nagare_core_types__pull _x_x1729;
  kk_unit_t _x_x1730 = kk_Unit;
  kk_unit_unbox(_b_x964);
  _x_x1729 = kk_nagare_io_file__mlift_deleteFile_10692(_x_x1730, _ctx); /*nagare/core/types/pull<(),<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>*/
  return kk_nagare_core_types__pull_box(_x_x1729, _ctx);
}
static kk_nagare_core_types__pull kk_nagare_io_file_deleteFile_fun1718(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_io_file_deleteFile_fun1718__t* _self = kk_function_as(struct kk_nagare_io_file_deleteFile_fun1718__t*, _fself, _ctx);
  kk_std_os_path__path filepath = _self->filepath; /* std/os/path/path */
  kk_drop_match(_self, {kk_std_os_path__path_dup(filepath, _ctx);}, {}, _ctx)
  kk_string_t _x_x1_10653;
  kk_box_t _x_x1719 = kk_std_core_hnd__open_none1(kk_nagare_io_file_new_deleteFile_fun1720(_ctx), kk_std_os_path__path_box(filepath, _ctx), _ctx); /*10001*/
  _x_x1_10653 = kk_string_unbox(_x_x1719); /*string*/
  kk_ssize_t i_10950 = (KK_IZ(1)); /*hnd/ev-index*/;
  kk_evv_t w = kk_evv_swap_create1(i_10950,kk_context()); /*hnd/evv<<nagare/io/file_effect/fileSystem,alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_std_core_hnd__ev ev_10953 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<nagare/io/file_effect/fileSystem>*/;
  kk_unit_t y = kk_Unit;
  kk_box_t _x_x1723;
  {
    struct kk_std_core_hnd_Ev* _con_x1724 = kk_std_core_hnd__as_Ev(ev_10953, _ctx);
    kk_box_t _box_x941 = _con_x1724->hnd;
    int32_t m = _con_x1724->marker;
    kk_nagare_io_file__effect__fileSystem h = kk_nagare_io_file__effect__fileSystem_unbox(_box_x941, KK_BORROWED, _ctx);
    kk_nagare_io_file__effect__fileSystem_dup(h, _ctx);
    kk_std_core_hnd__clause1 _match_x973;
    kk_std_core_hnd__clause1 _brw_x974 = kk_nagare_io_file__effect_removeFileOp_fs__select(h, _ctx); /*hnd/clause1<string,(),nagare/io/file_effect/fileSystem,1952,1953>*/;
    kk_datatype_ptr_dropn(h, (KK_I32(4)), _ctx);
    _match_x973 = _brw_x974; /*hnd/clause1<string,(),nagare/io/file_effect/fileSystem,1952,1953>*/
    {
      kk_function_t _fun_unbox_x945 = _match_x973.clause;
      _x_x1723 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x945, (_fun_unbox_x945, m, ev_10953, kk_string_box(_x_x1_10653), _ctx), _ctx); /*10010*/
    }
  }
  kk_unit_unbox(_x_x1723);
  kk_evv_set(w,kk_context());
  kk_unit_t x_10948 = kk_Unit;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1725 = kk_std_core_hnd_yield_cont(kk_nagare_io_file_new_deleteFile_fun1726(i_10950, _ctx), _ctx); /*10002*/
    kk_unit_unbox(_x_x1725);
  }
  else {
    y;
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1727 = kk_std_core_hnd_yield_extend(kk_nagare_io_file_new_deleteFile_fun1728(_ctx), _ctx); /*10001*/
    return kk_nagare_core_types__pull_unbox(_x_x1727, KK_OWNED, _ctx);
  }
  {
    kk_unit_t _b_x965_969 = kk_Unit;
    x_10948;
    kk_std_core_types__list _b_x966_970 = kk_std_core_types__new_Nil(_ctx); /*list<()>*/;
    kk_nagare_core_types__chunk _x_x1731;
    kk_std_core_types__list _x_x1732 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_unit_box(_b_x965_969), _b_x966_970, _ctx); /*list<10021>*/
    _x_x1731 = kk_nagare_core_types__new_Chunk(_x_x1732, _ctx); /*nagare/core/types/chunk<4>*/
    return kk_nagare_core_types__new_POutput(kk_reuse_null, 0, _x_x1731, kk_nagare_core_types__new_PDone(_ctx), _ctx);
  }
}

kk_nagare_core_types__nstream kk_nagare_io_file_deleteFile(kk_std_os_path__path filepath, kk_context_t* _ctx) { /* (filepath : std/os/path/path) -> nagare/io/file_effect/fsStream<()> */ 
  kk_nagare_core_types__pull _x_x1717 = kk_nagare_core_types__new_PEval(kk_reuse_null, 0, kk_nagare_io_file_new_deleteFile_fun1718(filepath, _ctx), _ctx); /*nagare/core/types/pull<19,20>*/
  return kk_nagare_core_types__new_Stream(_x_x1717, _ctx);
}

// initialization
void kk_nagare_io_file__init(kk_context_t* _ctx){
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
  kk_std_os_file__init(_ctx);
  kk_nagare_core_types__init(_ctx);
  kk_nagare_core_stream__init(_ctx);
  kk_nagare_io_file__effect__init(_ctx);
  kk_nagare_core_pull__init(_ctx);
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
}

// termination
void kk_nagare_io_file__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_nagare_core_pull__done(_ctx);
  kk_nagare_io_file__effect__done(_ctx);
  kk_nagare_core_stream__done(_ctx);
  kk_nagare_core_types__done(_ctx);
  kk_std_os_file__done(_ctx);
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
