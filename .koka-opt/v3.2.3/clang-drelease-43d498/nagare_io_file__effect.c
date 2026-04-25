// Koka generated module: nagare/io/file_effect, koka version: 3.2.3, platform: 64-bit
#include "nagare_io_file__effect.h"
/*---------------------------------------------------------------------------
  Nagare File I/O — C FFI layer
  Provides handle-based file operations for streaming reads and writes.
---------------------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

// Open a file for reading. Returns FILE* cast to intptr_t (0 on failure).
static intptr_t nagare_fopen_read(kk_string_t path) {
  kk_context_t* ctx = kk_get_context();
  FILE* f = NULL;
  kk_with_string_as_qutf8_borrow(path, cpath, ctx) {
    f = fopen(cpath, "rb");
  }
  kk_string_drop(path, ctx);
  return (intptr_t)f;
}

// Open a file for writing (truncate). Returns FILE* cast to intptr_t (0 on failure).
static intptr_t nagare_fopen_write(kk_string_t path) {
  kk_context_t* ctx = kk_get_context();
  FILE* f = NULL;
  kk_with_string_as_qutf8_borrow(path, cpath, ctx) {
    f = fopen(cpath, "wb");
  }
  kk_string_drop(path, ctx);
  return (intptr_t)f;
}

// Read up to `n` bytes from a file handle. Returns a kk_string_t (empty on EOF).
static kk_string_t nagare_fread_chunk(intptr_t fh, kk_integer_t n) {
  kk_context_t* ctx = kk_get_context();
  FILE* f = (FILE*)fh;
  if (f == NULL) return kk_string_empty();
  kk_ssize_t size = kk_integer_clamp_ssize_t(n, ctx);
  if (size <= 0) return kk_string_empty();
  uint8_t* buf = (uint8_t*)kk_malloc(size, ctx);
  if (buf == NULL) return kk_string_empty();
  size_t nread = fread(buf, 1, (size_t)size, f);
  if (nread == 0) {
    kk_free(buf, ctx);
    return kk_string_empty();
  }
  kk_string_t result = kk_string_alloc_from_qutf8n((kk_ssize_t)nread, (const char*)buf, ctx);
  kk_free(buf, ctx);
  return result;
}

// Read up to `n` bytes from a file handle. Returns a kk_vector_t of int8 (empty on EOF).
static kk_vector_t nagare_fread_chunk_bytes(intptr_t fh, kk_integer_t n) {
  kk_context_t* ctx = kk_get_context();
  FILE* f = (FILE*)fh;
  kk_ssize_t size = kk_integer_clamp_ssize_t(n, ctx);
  kk_integer_drop(n, ctx);
  if (f == NULL || size <= 0) return kk_vector_empty();
  uint8_t* buf = (uint8_t*)kk_malloc((size_t)size, ctx);
  if (buf == NULL) return kk_vector_empty();
  size_t nread = fread(buf, 1, (size_t)size, f);
  if (nread == 0) {
    kk_free(buf, ctx);
    return kk_vector_empty();
  }
  kk_vector_t vec = kk_vector_alloc((kk_ssize_t)nread, kk_int8_box(0, ctx), ctx);
  kk_box_t* elems = kk_vector_buf_borrow(vec, NULL, ctx);
  for (size_t i = 0; i < nread; i++) {
    elems[i] = kk_int8_box((int8_t)buf[i], ctx);
  }
  kk_free(buf, ctx);
  return vec;
}

// Write a string to a file handle. Returns the number of bytes written.
static kk_integer_t nagare_fwrite_chunk(intptr_t fh, kk_string_t content) {
  kk_context_t* ctx = kk_get_context();
  FILE* f = (FILE*)fh;
  if (f == NULL) {
    kk_string_drop(content, ctx);
    return kk_integer_from_int(0, ctx);
  }
  kk_ssize_t len;
  const uint8_t* buf = kk_string_buf_borrow(content, &len, ctx);
  size_t nwritten = 0;
  if (len > 0) {
    nwritten = fwrite(buf, 1, (size_t)len, f);
  }
  kk_string_drop(content, ctx);
  return kk_integer_from_ssize_t((kk_ssize_t)nwritten, ctx);
}

// Write a vector<int8> to a file handle. Returns the number of bytes written.
static kk_integer_t nagare_fwrite_chunk_bytes(intptr_t fh, kk_vector_t content) {
  kk_context_t* ctx = kk_get_context();
  FILE* f = (FILE*)fh;
  kk_ssize_t len;
  kk_box_t* elems = kk_vector_buf_borrow(content, &len, ctx);
  size_t nwritten = 0;
  if (f != NULL && len > 0) {
    uint8_t* buf = (uint8_t*)kk_malloc((size_t)len, ctx);
    if (buf != NULL) {
      for (kk_ssize_t i = 0; i < len; i++) {
        buf[i] = (uint8_t)kk_int8_unbox(elems[i], KK_OWNED, ctx);
      }
      nwritten = fwrite(buf, 1, (size_t)len, f);
      kk_free(buf, ctx);
    }
  }
  kk_vector_drop(content, ctx);
  return kk_integer_from_ssize_t((kk_ssize_t)nwritten, ctx);
}

// Close a file handle.
static kk_unit_t nagare_fclose(intptr_t fh) {
  if (fh != 0) {
    fclose((FILE*)fh);
  }
  return kk_Unit;
}

// Convert a vector<int8> (bytes) to a kk_string_t (UTF-8, replacing invalid sequences).
static kk_string_t nagare_bytes_to_string(kk_vector_t vec) {
  kk_context_t* ctx = kk_get_context();
  kk_ssize_t len;
  kk_box_t* elems = kk_vector_buf_borrow(vec, &len, ctx);
  if (len <= 0) {
    kk_vector_drop(vec, ctx);
    return kk_string_empty();
  }
  uint8_t* buf = (uint8_t*)kk_malloc((size_t)len, ctx);
  if (buf == NULL) {
    kk_vector_drop(vec, ctx);
    return kk_string_empty();
  }
  for (kk_ssize_t i = 0; i < len; i++) {
    buf[i] = (uint8_t)kk_int8_unbox(elems[i], KK_OWNED, ctx);
  }
  kk_string_t result = kk_string_alloc_from_qutf8n(len, (const char*)buf, ctx);
  kk_free(buf, ctx);
  kk_vector_drop(vec, ctx);
  return result;
}

// Convert a kk_string_t to a vector<int8> (raw UTF-8 bytes).
static kk_vector_t nagare_string_to_bytes(kk_string_t s) {
  kk_context_t* ctx = kk_get_context();
  kk_ssize_t len;
  const uint8_t* buf = kk_string_buf_borrow(s, &len, ctx);
  kk_vector_t vec = kk_vector_alloc(len, kk_int8_box(0, ctx), ctx);
  kk_box_t* elems = kk_vector_buf_borrow(vec, NULL, ctx);
  for (kk_ssize_t i = 0; i < len; i++) {
    elems[i] = kk_int8_box((int8_t)buf[i], ctx);
  }
  kk_string_drop(s, ctx);
  return vec;
}

// Delete a file.
static kk_unit_t nagare_remove(kk_string_t path) {
  kk_context_t* ctx = kk_get_context();
  kk_with_string_as_qutf8_borrow(path, cpath, ctx) {
    remove(cpath);
  }
  kk_string_drop(path, ctx);
  return kk_Unit;
}


intptr_t kk_nagare_io_file__effect_nagare_fopen_read(kk_string_t p, kk_context_t* _ctx) { /* (p : string) -> io intptr_t */ 
  return nagare_fopen_read(p);
}

intptr_t kk_nagare_io_file__effect_nagare_fopen_write(kk_string_t p, kk_context_t* _ctx) { /* (p : string) -> io intptr_t */ 
  return nagare_fopen_write(p);
}

kk_string_t kk_nagare_io_file__effect_nagare_fread_chunk(intptr_t h, kk_integer_t size, kk_context_t* _ctx) { /* (h : intptr_t, size : int) -> io string */ 
  return nagare_fread_chunk(h,size);
}

kk_vector_t kk_nagare_io_file__effect_nagare_fread_chunk_bytes(intptr_t h, kk_integer_t size, kk_context_t* _ctx) { /* (h : intptr_t, size : int) -> io vector<int8> */ 
  return nagare_fread_chunk_bytes(h,size);
}

kk_integer_t kk_nagare_io_file__effect_nagare_fwrite_chunk(intptr_t h, kk_string_t content, kk_context_t* _ctx) { /* (h : intptr_t, content : string) -> io int */ 
  return nagare_fwrite_chunk(h,content);
}

kk_integer_t kk_nagare_io_file__effect_nagare_fwrite_chunk_bytes(intptr_t h, kk_vector_t content, kk_context_t* _ctx) { /* (h : intptr_t, content : vector<int8>) -> io int */ 
  return nagare_fwrite_chunk_bytes(h,content);
}

kk_unit_t kk_nagare_io_file__effect_nagare_fclose(intptr_t h, kk_context_t* _ctx) { /* (h : intptr_t) -> io () */ 
  nagare_fclose(h); return kk_Unit;
}

kk_unit_t kk_nagare_io_file__effect_nagare_remove(kk_string_t p, kk_context_t* _ctx) { /* (p : string) -> io () */ 
  nagare_remove(p); return kk_Unit;
}

kk_string_t kk_nagare_io_file__effect_nagare_bytes_to_string(kk_vector_t v, kk_context_t* _ctx) { /* (v : vector<int8>) -> string */ 
  return nagare_bytes_to_string(v);
}

kk_vector_t kk_nagare_io_file__effect_nagare_string_to_bytes(kk_string_t s, kk_context_t* _ctx) { /* (s : string) -> vector<int8> */ 
  return nagare_string_to_bytes(s);
}
 
// runtime tag for the effect `:fileRead`

kk_std_core_hnd__htag kk_nagare_io_file__effect_fileRead_fs__tag;
 
// handler for the effect `:fileRead`

kk_box_t kk_nagare_io_file__effect_fileRead_fs__handle(kk_nagare_io_file__effect__fileRead hnd, kk_function_t ret, kk_function_t action, kk_context_t* _ctx) { /* forall<a,e,b> (hnd : fileRead<e,b>, ret : (res : a) -> e b, action : () -> <fileRead|e> a) -> e b */ 
  kk_std_core_hnd__htag _x_x813 = kk_std_core_hnd__htag_dup(kk_nagare_io_file__effect_fileRead_fs__tag, _ctx); /*hnd/htag<nagare/io/file_effect/fileRead>*/
  return kk_std_core_hnd__hhandle(_x_x813, kk_nagare_io_file__effect__fileRead_box(hnd, _ctx), ret, action, _ctx);
}
 
// runtime tag for the effect `:fileWrite`

kk_std_core_hnd__htag kk_nagare_io_file__effect_fileWrite_fs__tag;
 
// handler for the effect `:fileWrite`

kk_box_t kk_nagare_io_file__effect_fileWrite_fs__handle(kk_nagare_io_file__effect__fileWrite hnd, kk_function_t ret, kk_function_t action, kk_context_t* _ctx) { /* forall<a,e,b> (hnd : fileWrite<e,b>, ret : (res : a) -> e b, action : () -> <fileWrite|e> a) -> e b */ 
  kk_std_core_hnd__htag _x_x842 = kk_std_core_hnd__htag_dup(kk_nagare_io_file__effect_fileWrite_fs__tag, _ctx); /*hnd/htag<nagare/io/file_effect/fileWrite>*/
  return kk_std_core_hnd__hhandle(_x_x842, kk_nagare_io_file__effect__fileWrite_box(hnd, _ctx), ret, action, _ctx);
}
 
// runtime tag for the effect `:fileSystem`

kk_std_core_hnd__htag kk_nagare_io_file__effect_fileSystem_fs__tag;
 
// handler for the effect `:fileSystem`

kk_box_t kk_nagare_io_file__effect_fileSystem_fs__handle(kk_nagare_io_file__effect__fileSystem hnd, kk_function_t ret, kk_function_t action, kk_context_t* _ctx) { /* forall<a,e,b> (hnd : fileSystem<e,b>, ret : (res : a) -> e b, action : () -> <fileSystem|e> a) -> e b */ 
  kk_std_core_hnd__htag _x_x866 = kk_std_core_hnd__htag_dup(kk_nagare_io_file__effect_fileSystem_fs__tag, _ctx); /*hnd/htag<nagare/io/file_effect/fileSystem>*/
  return kk_std_core_hnd__hhandle(_x_x866, kk_nagare_io_file__effect__fileSystem_box(hnd, _ctx), ret, action, _ctx);
}
 
// monadic lift


// lift anonymous function
struct kk_nagare_io_file__effect__mlift_with_read_file_10393_fun884__t {
  struct kk_function_s _base;
  kk_nagare_io_file__effect__read_handle h;
};
static kk_unit_t kk_nagare_io_file__effect__mlift_with_read_file_10393_fun884(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect__new_mlift_with_read_file_10393_fun884(kk_nagare_io_file__effect__read_handle h, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect__mlift_with_read_file_10393_fun884__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect__mlift_with_read_file_10393_fun884__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect__mlift_with_read_file_10393_fun884, kk_context());
  _self->h = h;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_io_file__effect__mlift_with_read_file_10393_fun890__t {
  struct kk_function_s _base;
  kk_ssize_t i_10450;
};
static kk_box_t kk_nagare_io_file__effect__mlift_with_read_file_10393_fun890(kk_function_t _fself, kk_function_t _b_x149, kk_box_t _b_x150, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect__new_mlift_with_read_file_10393_fun890(kk_ssize_t i_10450, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect__mlift_with_read_file_10393_fun890__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect__mlift_with_read_file_10393_fun890__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect__mlift_with_read_file_10393_fun890, kk_context());
  _self->i_10450 = i_10450;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_io_file__effect__mlift_with_read_file_10393_fun891__t {
  struct kk_function_s _base;
  kk_function_t _b_x149;
};
static kk_unit_t kk_nagare_io_file__effect__mlift_with_read_file_10393_fun891(kk_function_t _fself, kk_box_t _b_x151, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect__new_mlift_with_read_file_10393_fun891(kk_function_t _b_x149, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect__mlift_with_read_file_10393_fun891__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect__mlift_with_read_file_10393_fun891__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect__mlift_with_read_file_10393_fun891, kk_context());
  _self->_b_x149 = _b_x149;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_unit_t kk_nagare_io_file__effect__mlift_with_read_file_10393_fun891(kk_function_t _fself, kk_box_t _b_x151, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect__mlift_with_read_file_10393_fun891__t* _self = kk_function_as(struct kk_nagare_io_file__effect__mlift_with_read_file_10393_fun891__t*, _fself, _ctx);
  kk_function_t _b_x149 = _self->_b_x149; /* (10003) -> 10001 10000 */
  kk_drop_match(_self, {kk_function_dup(_b_x149, _ctx);}, {}, _ctx)
  kk_box_t _x_x892 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _b_x149, (_b_x149, _b_x151, _ctx), _ctx); /*10000*/
  kk_unit_unbox(_x_x892); return kk_Unit;
}


// lift anonymous function
struct kk_nagare_io_file__effect__mlift_with_read_file_10393_fun893__t {
  struct kk_function_s _base;
  kk_function_t _b_x145_154;
};
static kk_box_t kk_nagare_io_file__effect__mlift_with_read_file_10393_fun893(kk_function_t _fself, kk_box_t _b_x147, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect__new_mlift_with_read_file_10393_fun893(kk_function_t _b_x145_154, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect__mlift_with_read_file_10393_fun893__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect__mlift_with_read_file_10393_fun893__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect__mlift_with_read_file_10393_fun893, kk_context());
  _self->_b_x145_154 = _b_x145_154;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file__effect__mlift_with_read_file_10393_fun893(kk_function_t _fself, kk_box_t _b_x147, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect__mlift_with_read_file_10393_fun893__t* _self = kk_function_as(struct kk_nagare_io_file__effect__mlift_with_read_file_10393_fun893__t*, _fself, _ctx);
  kk_function_t _b_x145_154 = _self->_b_x145_154; /* (10011) -> <nagare/io/file_effect/fileRead|2158> () */
  kk_drop_match(_self, {kk_function_dup(_b_x145_154, _ctx);}, {}, _ctx)
  kk_unit_t _x_x894 = kk_Unit;
  kk_function_call(kk_unit_t, (kk_function_t, kk_box_t, kk_context_t*), _b_x145_154, (_b_x145_154, _b_x147, _ctx), _ctx);
  return kk_unit_box(_x_x894);
}
static kk_box_t kk_nagare_io_file__effect__mlift_with_read_file_10393_fun890(kk_function_t _fself, kk_function_t _b_x149, kk_box_t _b_x150, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect__mlift_with_read_file_10393_fun890__t* _self = kk_function_as(struct kk_nagare_io_file__effect__mlift_with_read_file_10393_fun890__t*, _fself, _ctx);
  kk_ssize_t i_10450 = _self->i_10450; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_10450, _ctx);}, {}, _ctx)
  kk_function_t cont_156 = kk_nagare_io_file__effect__new_mlift_with_read_file_10393_fun891(_b_x149, _ctx); /*(10011) -> <nagare/io/file_effect/fileRead|2158> ()*/;
  kk_box_t res_157 = _b_x150; /*10011*/;
  kk_ssize_t _b_x144_153 = i_10450; /*hnd/ev-index*/;
  kk_function_t _b_x145_154 = cont_156; /*(10011) -> <nagare/io/file_effect/fileRead|2158> ()*/;
  kk_box_t _b_x146_155 = res_157; /*10011*/;
  return kk_std_core_hnd_open_at1(_b_x144_153, kk_nagare_io_file__effect__new_mlift_with_read_file_10393_fun893(_b_x145_154, _ctx), _b_x146_155, _ctx);
}
static kk_unit_t kk_nagare_io_file__effect__mlift_with_read_file_10393_fun884(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect__mlift_with_read_file_10393_fun884__t* _self = kk_function_as(struct kk_nagare_io_file__effect__mlift_with_read_file_10393_fun884__t*, _fself, _ctx);
  kk_nagare_io_file__effect__read_handle h = _self->h; /* nagare/io/file_effect/read-handle */
  kk_drop_match(_self, {kk_nagare_io_file__effect__read_handle_dup(h, _ctx);}, {}, _ctx)
  kk_ssize_t i_10450;
  kk_std_core_hnd__htag _x_x885 = kk_std_core_hnd__htag_dup(kk_nagare_io_file__effect_fileRead_fs__tag, _ctx); /*hnd/htag<nagare/io/file_effect/fileRead>*/
  i_10450 = kk_std_core_hnd__evv_index(_x_x885, _ctx); /*hnd/ev-index*/
  kk_evv_t w = kk_evv_swap_create1(i_10450,kk_context()); /*hnd/evv<<nagare/io/file_effect/fileRead|2158>>*/;
  kk_std_core_hnd__ev ev_10453 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<nagare/io/file_effect/fileRead>*/;
  kk_unit_t y = kk_Unit;
  kk_box_t _x_x886;
  {
    struct kk_std_core_hnd_Ev* _con_x887 = kk_std_core_hnd__as_Ev(ev_10453, _ctx);
    kk_box_t _box_x136 = _con_x887->hnd;
    int32_t m = _con_x887->marker;
    kk_nagare_io_file__effect__fileRead h_1 = kk_nagare_io_file__effect__fileRead_unbox(_box_x136, KK_BORROWED, _ctx);
    kk_nagare_io_file__effect__fileRead_dup(h_1, _ctx);
    {
      struct kk_nagare_io_file__effect__Hnd_fileRead* _con_x888 = kk_nagare_io_file__effect__as_Hnd_fileRead(h_1, _ctx);
      kk_integer_t _pat_0 = _con_x888->_cfc;
      kk_std_core_hnd__clause1 _fun_closeRead = _con_x888->_fun_closeRead;
      kk_std_core_hnd__clause1 _pat_1_1 = _con_x888->_fun_openRead;
      kk_std_core_hnd__clause2 _pat_2 = _con_x888->_fun_readChunk;
      kk_std_core_hnd__clause2 _pat_3 = _con_x888->_fun_readChunkBytes;
      kk_std_core_hnd__clause1 _pat_4 = _con_x888->_fun_readTextFileOp;
      if kk_likely(kk_datatype_ptr_is_unique(h_1, _ctx)) {
        kk_std_core_hnd__clause1_drop(_pat_4, _ctx);
        kk_std_core_hnd__clause2_drop(_pat_3, _ctx);
        kk_std_core_hnd__clause2_drop(_pat_2, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_1_1, _ctx);
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(h_1, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_fun_closeRead, _ctx);
        kk_datatype_ptr_decref(h_1, _ctx);
      }
      {
        kk_function_t _fun_unbox_x140 = _fun_closeRead.clause;
        _x_x886 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x140, (_fun_unbox_x140, m, ev_10453, kk_nagare_io_file__effect__read_handle_box(h, _ctx), _ctx), _ctx); /*10010*/
      }
    }
  }
  kk_unit_unbox(_x_x886);
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x889 = kk_std_core_hnd_yield_cont(kk_nagare_io_file__effect__new_mlift_with_read_file_10393_fun890(i_10450, _ctx), _ctx); /*10002*/
    kk_unit_unbox(_x_x889); return kk_Unit;
  }
  {
    y; return kk_Unit;
  }
}

kk_box_t kk_nagare_io_file__effect__mlift_with_read_file_10393(kk_function_t body, kk_nagare_io_file__effect__read_handle h, kk_context_t* _ctx) { /* forall<a,e> (body : (read-handle) -> <fileRead|e> a, h : read-handle) -> <fileRead|e> a */ 
  kk_box_t _x_x895 = kk_function_call(kk_box_t, (kk_function_t, kk_nagare_io_file__effect__read_handle, kk_context_t*), body, (body, h, _ctx), _ctx); /*2157*/
  return kk_std_core_hnd_finally_prompt(kk_nagare_io_file__effect__new_mlift_with_read_file_10393_fun884(h, _ctx), _x_x895, _ctx);
}


// lift anonymous function
struct kk_nagare_io_file__effect_with_read_file_fun901__t {
  struct kk_function_s _base;
  kk_ssize_t i_10459;
};
static kk_box_t kk_nagare_io_file__effect_with_read_file_fun901(kk_function_t _fself, kk_function_t _b_x171, kk_box_t _b_x172, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_with_read_file_fun901(kk_ssize_t i_10459, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_with_read_file_fun901__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect_with_read_file_fun901__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect_with_read_file_fun901, kk_context());
  _self->i_10459 = i_10459;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file__effect_with_read_file_fun901(kk_function_t _fself, kk_function_t _b_x171, kk_box_t _b_x172, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_with_read_file_fun901__t* _self = kk_function_as(struct kk_nagare_io_file__effect_with_read_file_fun901__t*, _fself, _ctx);
  kk_ssize_t i_10459 = _self->i_10459; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_10459, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_10459, _b_x171, _b_x172, _ctx);
}


// lift anonymous function
struct kk_nagare_io_file__effect_with_read_file_fun902__t {
  struct kk_function_s _base;
  kk_function_t body;
};
static kk_box_t kk_nagare_io_file__effect_with_read_file_fun902(kk_function_t _fself, kk_box_t _b_x181, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_with_read_file_fun902(kk_function_t body, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_with_read_file_fun902__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect_with_read_file_fun902__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect_with_read_file_fun902, kk_context());
  _self->body = body;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file__effect_with_read_file_fun902(kk_function_t _fself, kk_box_t _b_x181, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_with_read_file_fun902__t* _self = kk_function_as(struct kk_nagare_io_file__effect_with_read_file_fun902__t*, _fself, _ctx);
  kk_function_t body = _self->body; /* (nagare/io/file_effect/read-handle) -> <nagare/io/file_effect/fileRead|2158> 2157 */
  kk_drop_match(_self, {kk_function_dup(body, _ctx);}, {}, _ctx)
  kk_nagare_io_file__effect__read_handle _x_x903 = kk_nagare_io_file__effect__read_handle_unbox(_b_x181, KK_OWNED, _ctx); /*nagare/io/file_effect/read-handle*/
  return kk_nagare_io_file__effect__mlift_with_read_file_10393(body, _x_x903, _ctx);
}


// lift anonymous function
struct kk_nagare_io_file__effect_with_read_file_fun904__t {
  struct kk_function_s _base;
  kk_nagare_io_file__effect__read_handle x_10456;
};
static kk_unit_t kk_nagare_io_file__effect_with_read_file_fun904(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_with_read_file_fun904(kk_nagare_io_file__effect__read_handle x_10456, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_with_read_file_fun904__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect_with_read_file_fun904__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect_with_read_file_fun904, kk_context());
  _self->x_10456 = x_10456;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_io_file__effect_with_read_file_fun910__t {
  struct kk_function_s _base;
  kk_ssize_t i_0_10467;
};
static kk_box_t kk_nagare_io_file__effect_with_read_file_fun910(kk_function_t _fself, kk_function_t _b_x195, kk_box_t _b_x196, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_with_read_file_fun910(kk_ssize_t i_0_10467, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_with_read_file_fun910__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect_with_read_file_fun910__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect_with_read_file_fun910, kk_context());
  _self->i_0_10467 = i_0_10467;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_io_file__effect_with_read_file_fun911__t {
  struct kk_function_s _base;
  kk_function_t _b_x195;
};
static kk_unit_t kk_nagare_io_file__effect_with_read_file_fun911(kk_function_t _fself, kk_box_t _b_x197, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_with_read_file_fun911(kk_function_t _b_x195, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_with_read_file_fun911__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect_with_read_file_fun911__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect_with_read_file_fun911, kk_context());
  _self->_b_x195 = _b_x195;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_unit_t kk_nagare_io_file__effect_with_read_file_fun911(kk_function_t _fself, kk_box_t _b_x197, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_with_read_file_fun911__t* _self = kk_function_as(struct kk_nagare_io_file__effect_with_read_file_fun911__t*, _fself, _ctx);
  kk_function_t _b_x195 = _self->_b_x195; /* (10003) -> 10001 10000 */
  kk_drop_match(_self, {kk_function_dup(_b_x195, _ctx);}, {}, _ctx)
  kk_box_t _x_x912 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _b_x195, (_b_x195, _b_x197, _ctx), _ctx); /*10000*/
  kk_unit_unbox(_x_x912); return kk_Unit;
}


// lift anonymous function
struct kk_nagare_io_file__effect_with_read_file_fun913__t {
  struct kk_function_s _base;
  kk_function_t _b_x191_202;
};
static kk_box_t kk_nagare_io_file__effect_with_read_file_fun913(kk_function_t _fself, kk_box_t _b_x193, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_with_read_file_fun913(kk_function_t _b_x191_202, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_with_read_file_fun913__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect_with_read_file_fun913__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect_with_read_file_fun913, kk_context());
  _self->_b_x191_202 = _b_x191_202;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file__effect_with_read_file_fun913(kk_function_t _fself, kk_box_t _b_x193, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_with_read_file_fun913__t* _self = kk_function_as(struct kk_nagare_io_file__effect_with_read_file_fun913__t*, _fself, _ctx);
  kk_function_t _b_x191_202 = _self->_b_x191_202; /* (10011) -> <nagare/io/file_effect/fileRead|2158> () */
  kk_drop_match(_self, {kk_function_dup(_b_x191_202, _ctx);}, {}, _ctx)
  kk_unit_t _x_x914 = kk_Unit;
  kk_function_call(kk_unit_t, (kk_function_t, kk_box_t, kk_context_t*), _b_x191_202, (_b_x191_202, _b_x193, _ctx), _ctx);
  return kk_unit_box(_x_x914);
}
static kk_box_t kk_nagare_io_file__effect_with_read_file_fun910(kk_function_t _fself, kk_function_t _b_x195, kk_box_t _b_x196, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_with_read_file_fun910__t* _self = kk_function_as(struct kk_nagare_io_file__effect_with_read_file_fun910__t*, _fself, _ctx);
  kk_ssize_t i_0_10467 = _self->i_0_10467; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_0_10467, _ctx);}, {}, _ctx)
  kk_function_t cont_0_205 = kk_nagare_io_file__effect_new_with_read_file_fun911(_b_x195, _ctx); /*(10011) -> <nagare/io/file_effect/fileRead|2158> ()*/;
  kk_box_t res_0_206 = _b_x196; /*10011*/;
  kk_ssize_t _b_x190_201 = i_0_10467; /*hnd/ev-index*/;
  kk_function_t _b_x191_202 = cont_0_205; /*(10011) -> <nagare/io/file_effect/fileRead|2158> ()*/;
  kk_box_t _b_x192_203 = res_0_206; /*10011*/;
  return kk_std_core_hnd_open_at1(_b_x190_201, kk_nagare_io_file__effect_new_with_read_file_fun913(_b_x191_202, _ctx), _b_x192_203, _ctx);
}
static kk_unit_t kk_nagare_io_file__effect_with_read_file_fun904(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_with_read_file_fun904__t* _self = kk_function_as(struct kk_nagare_io_file__effect_with_read_file_fun904__t*, _fself, _ctx);
  kk_nagare_io_file__effect__read_handle x_10456 = _self->x_10456; /* nagare/io/file_effect/read-handle */
  kk_drop_match(_self, {kk_nagare_io_file__effect__read_handle_dup(x_10456, _ctx);}, {}, _ctx)
  kk_ssize_t i_0_10467;
  kk_std_core_hnd__htag _x_x905 = kk_std_core_hnd__htag_dup(kk_nagare_io_file__effect_fileRead_fs__tag, _ctx); /*hnd/htag<nagare/io/file_effect/fileRead>*/
  i_0_10467 = kk_std_core_hnd__evv_index(_x_x905, _ctx); /*hnd/ev-index*/
  kk_evv_t w_0 = kk_evv_swap_create1(i_0_10467,kk_context()); /*hnd/evv<<nagare/io/file_effect/fileRead|2158>>*/;
  kk_std_core_hnd__ev ev_0_10470 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<nagare/io/file_effect/fileRead>*/;
  kk_unit_t y_0 = kk_Unit;
  kk_box_t _x_x906;
  {
    struct kk_std_core_hnd_Ev* _con_x907 = kk_std_core_hnd__as_Ev(ev_0_10470, _ctx);
    kk_box_t _box_x182 = _con_x907->hnd;
    int32_t m_0 = _con_x907->marker;
    kk_nagare_io_file__effect__fileRead h_2 = kk_nagare_io_file__effect__fileRead_unbox(_box_x182, KK_BORROWED, _ctx);
    kk_nagare_io_file__effect__fileRead_dup(h_2, _ctx);
    {
      struct kk_nagare_io_file__effect__Hnd_fileRead* _con_x908 = kk_nagare_io_file__effect__as_Hnd_fileRead(h_2, _ctx);
      kk_integer_t _pat_0_4 = _con_x908->_cfc;
      kk_std_core_hnd__clause1 _fun_closeRead = _con_x908->_fun_closeRead;
      kk_std_core_hnd__clause1 _pat_1_2 = _con_x908->_fun_openRead;
      kk_std_core_hnd__clause2 _pat_2_1 = _con_x908->_fun_readChunk;
      kk_std_core_hnd__clause2 _pat_3_0 = _con_x908->_fun_readChunkBytes;
      kk_std_core_hnd__clause1 _pat_4_1 = _con_x908->_fun_readTextFileOp;
      if kk_likely(kk_datatype_ptr_is_unique(h_2, _ctx)) {
        kk_std_core_hnd__clause1_drop(_pat_4_1, _ctx);
        kk_std_core_hnd__clause2_drop(_pat_3_0, _ctx);
        kk_std_core_hnd__clause2_drop(_pat_2_1, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_1_2, _ctx);
        kk_integer_drop(_pat_0_4, _ctx);
        kk_datatype_ptr_free(h_2, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_fun_closeRead, _ctx);
        kk_datatype_ptr_decref(h_2, _ctx);
      }
      {
        kk_function_t _fun_unbox_x186 = _fun_closeRead.clause;
        _x_x906 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x186, (_fun_unbox_x186, m_0, ev_0_10470, kk_nagare_io_file__effect__read_handle_box(x_10456, _ctx), _ctx), _ctx); /*10010*/
      }
    }
  }
  kk_unit_unbox(_x_x906);
  kk_evv_set(w_0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x909 = kk_std_core_hnd_yield_cont(kk_nagare_io_file__effect_new_with_read_file_fun910(i_0_10467, _ctx), _ctx); /*10002*/
    kk_unit_unbox(_x_x909); return kk_Unit;
  }
  {
    y_0; return kk_Unit;
  }
}

kk_box_t kk_nagare_io_file__effect_with_read_file(kk_string_t path, kk_function_t body, kk_context_t* _ctx) { /* forall<a,e> (path : string, body : (read-handle) -> <fileRead|e> a) -> <fileRead|e> a */ 
  kk_ssize_t i_10459;
  kk_std_core_hnd__htag _x_x896 = kk_std_core_hnd__htag_dup(kk_nagare_io_file__effect_fileRead_fs__tag, _ctx); /*hnd/htag<nagare/io/file_effect/fileRead>*/
  i_10459 = kk_std_core_hnd__evv_index(_x_x896, _ctx); /*hnd/ev-index*/
  kk_evv_t w = kk_evv_swap_create1(i_10459,kk_context()); /*hnd/evv<<nagare/io/file_effect/fileRead|2158>>*/;
  kk_std_core_hnd__ev ev_10462 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<nagare/io/file_effect/fileRead>*/;
  kk_nagare_io_file__effect__read_handle y;
  kk_box_t _x_x897;
  {
    struct kk_std_core_hnd_Ev* _con_x898 = kk_std_core_hnd__as_Ev(ev_10462, _ctx);
    kk_box_t _box_x158 = _con_x898->hnd;
    int32_t m = _con_x898->marker;
    kk_nagare_io_file__effect__fileRead h = kk_nagare_io_file__effect__fileRead_unbox(_box_x158, KK_BORROWED, _ctx);
    kk_nagare_io_file__effect__fileRead_dup(h, _ctx);
    {
      struct kk_nagare_io_file__effect__Hnd_fileRead* _con_x899 = kk_nagare_io_file__effect__as_Hnd_fileRead(h, _ctx);
      kk_integer_t _pat_0 = _con_x899->_cfc;
      kk_std_core_hnd__clause1 _pat_1 = _con_x899->_fun_closeRead;
      kk_std_core_hnd__clause1 _fun_openRead = _con_x899->_fun_openRead;
      kk_std_core_hnd__clause2 _pat_2_0 = _con_x899->_fun_readChunk;
      kk_std_core_hnd__clause2 _pat_3 = _con_x899->_fun_readChunkBytes;
      kk_std_core_hnd__clause1 _pat_4 = _con_x899->_fun_readTextFileOp;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause1_drop(_pat_4, _ctx);
        kk_std_core_hnd__clause2_drop(_pat_3, _ctx);
        kk_std_core_hnd__clause2_drop(_pat_2_0, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_1, _ctx);
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_fun_openRead, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x162 = _fun_openRead.clause;
        _x_x897 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x162, (_fun_unbox_x162, m, ev_10462, kk_string_box(path), _ctx), _ctx); /*10010*/
      }
    }
  }
  y = kk_nagare_io_file__effect__read_handle_unbox(_x_x897, KK_OWNED, _ctx); /*nagare/io/file_effect/read-handle*/
  kk_evv_set(w,kk_context());
  kk_nagare_io_file__effect__read_handle x_10456;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x900 = kk_std_core_hnd_yield_cont(kk_nagare_io_file__effect_new_with_read_file_fun901(i_10459, _ctx), _ctx); /*10002*/
    x_10456 = kk_nagare_io_file__effect__read_handle_unbox(_x_x900, KK_OWNED, _ctx); /*nagare/io/file_effect/read-handle*/
  }
  else {
    x_10456 = y; /*nagare/io/file_effect/read-handle*/
  }
  if (kk_yielding(kk_context())) {
    return kk_std_core_hnd_yield_extend(kk_nagare_io_file__effect_new_with_read_file_fun902(body, _ctx), _ctx);
  }
  {
    kk_box_t _x_x915 = kk_function_call(kk_box_t, (kk_function_t, kk_nagare_io_file__effect__read_handle, kk_context_t*), body, (body, x_10456, _ctx), _ctx); /*2157*/
    return kk_std_core_hnd_finally_prompt(kk_nagare_io_file__effect_new_with_read_file_fun904(x_10456, _ctx), _x_x915, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_nagare_io_file__effect__mlift_with_write_file_10394_fun916__t {
  struct kk_function_s _base;
  kk_nagare_io_file__effect__write_handle h;
};
static kk_unit_t kk_nagare_io_file__effect__mlift_with_write_file_10394_fun916(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect__new_mlift_with_write_file_10394_fun916(kk_nagare_io_file__effect__write_handle h, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect__mlift_with_write_file_10394_fun916__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect__mlift_with_write_file_10394_fun916__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect__mlift_with_write_file_10394_fun916, kk_context());
  _self->h = h;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_io_file__effect__mlift_with_write_file_10394_fun922__t {
  struct kk_function_s _base;
  kk_ssize_t i_10475;
};
static kk_box_t kk_nagare_io_file__effect__mlift_with_write_file_10394_fun922(kk_function_t _fself, kk_function_t _b_x220, kk_box_t _b_x221, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect__new_mlift_with_write_file_10394_fun922(kk_ssize_t i_10475, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect__mlift_with_write_file_10394_fun922__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect__mlift_with_write_file_10394_fun922__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect__mlift_with_write_file_10394_fun922, kk_context());
  _self->i_10475 = i_10475;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_io_file__effect__mlift_with_write_file_10394_fun923__t {
  struct kk_function_s _base;
  kk_function_t _b_x220;
};
static kk_unit_t kk_nagare_io_file__effect__mlift_with_write_file_10394_fun923(kk_function_t _fself, kk_box_t _b_x222, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect__new_mlift_with_write_file_10394_fun923(kk_function_t _b_x220, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect__mlift_with_write_file_10394_fun923__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect__mlift_with_write_file_10394_fun923__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect__mlift_with_write_file_10394_fun923, kk_context());
  _self->_b_x220 = _b_x220;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_unit_t kk_nagare_io_file__effect__mlift_with_write_file_10394_fun923(kk_function_t _fself, kk_box_t _b_x222, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect__mlift_with_write_file_10394_fun923__t* _self = kk_function_as(struct kk_nagare_io_file__effect__mlift_with_write_file_10394_fun923__t*, _fself, _ctx);
  kk_function_t _b_x220 = _self->_b_x220; /* (10003) -> 10001 10000 */
  kk_drop_match(_self, {kk_function_dup(_b_x220, _ctx);}, {}, _ctx)
  kk_box_t _x_x924 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _b_x220, (_b_x220, _b_x222, _ctx), _ctx); /*10000*/
  kk_unit_unbox(_x_x924); return kk_Unit;
}


// lift anonymous function
struct kk_nagare_io_file__effect__mlift_with_write_file_10394_fun925__t {
  struct kk_function_s _base;
  kk_function_t _b_x216_225;
};
static kk_box_t kk_nagare_io_file__effect__mlift_with_write_file_10394_fun925(kk_function_t _fself, kk_box_t _b_x218, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect__new_mlift_with_write_file_10394_fun925(kk_function_t _b_x216_225, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect__mlift_with_write_file_10394_fun925__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect__mlift_with_write_file_10394_fun925__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect__mlift_with_write_file_10394_fun925, kk_context());
  _self->_b_x216_225 = _b_x216_225;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file__effect__mlift_with_write_file_10394_fun925(kk_function_t _fself, kk_box_t _b_x218, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect__mlift_with_write_file_10394_fun925__t* _self = kk_function_as(struct kk_nagare_io_file__effect__mlift_with_write_file_10394_fun925__t*, _fself, _ctx);
  kk_function_t _b_x216_225 = _self->_b_x216_225; /* (10011) -> <nagare/io/file_effect/fileWrite|2200> () */
  kk_drop_match(_self, {kk_function_dup(_b_x216_225, _ctx);}, {}, _ctx)
  kk_unit_t _x_x926 = kk_Unit;
  kk_function_call(kk_unit_t, (kk_function_t, kk_box_t, kk_context_t*), _b_x216_225, (_b_x216_225, _b_x218, _ctx), _ctx);
  return kk_unit_box(_x_x926);
}
static kk_box_t kk_nagare_io_file__effect__mlift_with_write_file_10394_fun922(kk_function_t _fself, kk_function_t _b_x220, kk_box_t _b_x221, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect__mlift_with_write_file_10394_fun922__t* _self = kk_function_as(struct kk_nagare_io_file__effect__mlift_with_write_file_10394_fun922__t*, _fself, _ctx);
  kk_ssize_t i_10475 = _self->i_10475; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_10475, _ctx);}, {}, _ctx)
  kk_function_t cont_227 = kk_nagare_io_file__effect__new_mlift_with_write_file_10394_fun923(_b_x220, _ctx); /*(10011) -> <nagare/io/file_effect/fileWrite|2200> ()*/;
  kk_box_t res_228 = _b_x221; /*10011*/;
  kk_ssize_t _b_x215_224 = i_10475; /*hnd/ev-index*/;
  kk_function_t _b_x216_225 = cont_227; /*(10011) -> <nagare/io/file_effect/fileWrite|2200> ()*/;
  kk_box_t _b_x217_226 = res_228; /*10011*/;
  return kk_std_core_hnd_open_at1(_b_x215_224, kk_nagare_io_file__effect__new_mlift_with_write_file_10394_fun925(_b_x216_225, _ctx), _b_x217_226, _ctx);
}
static kk_unit_t kk_nagare_io_file__effect__mlift_with_write_file_10394_fun916(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect__mlift_with_write_file_10394_fun916__t* _self = kk_function_as(struct kk_nagare_io_file__effect__mlift_with_write_file_10394_fun916__t*, _fself, _ctx);
  kk_nagare_io_file__effect__write_handle h = _self->h; /* nagare/io/file_effect/write-handle */
  kk_drop_match(_self, {kk_nagare_io_file__effect__write_handle_dup(h, _ctx);}, {}, _ctx)
  kk_ssize_t i_10475;
  kk_std_core_hnd__htag _x_x917 = kk_std_core_hnd__htag_dup(kk_nagare_io_file__effect_fileWrite_fs__tag, _ctx); /*hnd/htag<nagare/io/file_effect/fileWrite>*/
  i_10475 = kk_std_core_hnd__evv_index(_x_x917, _ctx); /*hnd/ev-index*/
  kk_evv_t w = kk_evv_swap_create1(i_10475,kk_context()); /*hnd/evv<<nagare/io/file_effect/fileWrite|2200>>*/;
  kk_std_core_hnd__ev ev_10478 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<nagare/io/file_effect/fileWrite>*/;
  kk_unit_t y = kk_Unit;
  kk_box_t _x_x918;
  {
    struct kk_std_core_hnd_Ev* _con_x919 = kk_std_core_hnd__as_Ev(ev_10478, _ctx);
    kk_box_t _box_x207 = _con_x919->hnd;
    int32_t m = _con_x919->marker;
    kk_nagare_io_file__effect__fileWrite h_1 = kk_nagare_io_file__effect__fileWrite_unbox(_box_x207, KK_BORROWED, _ctx);
    kk_nagare_io_file__effect__fileWrite_dup(h_1, _ctx);
    {
      struct kk_nagare_io_file__effect__Hnd_fileWrite* _con_x920 = kk_nagare_io_file__effect__as_Hnd_fileWrite(h_1, _ctx);
      kk_integer_t _pat_0 = _con_x920->_cfc;
      kk_std_core_hnd__clause1 _fun_closeWrite = _con_x920->_fun_closeWrite;
      kk_std_core_hnd__clause1 _pat_1_1 = _con_x920->_fun_openWrite;
      kk_std_core_hnd__clause2 _pat_2 = _con_x920->_fun_writeChunk;
      kk_std_core_hnd__clause2 _pat_3 = _con_x920->_fun_writeChunkBytes;
      if kk_likely(kk_datatype_ptr_is_unique(h_1, _ctx)) {
        kk_std_core_hnd__clause2_drop(_pat_3, _ctx);
        kk_std_core_hnd__clause2_drop(_pat_2, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_1_1, _ctx);
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(h_1, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_fun_closeWrite, _ctx);
        kk_datatype_ptr_decref(h_1, _ctx);
      }
      {
        kk_function_t _fun_unbox_x211 = _fun_closeWrite.clause;
        _x_x918 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x211, (_fun_unbox_x211, m, ev_10478, kk_nagare_io_file__effect__write_handle_box(h, _ctx), _ctx), _ctx); /*10010*/
      }
    }
  }
  kk_unit_unbox(_x_x918);
  kk_evv_set(w,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x921 = kk_std_core_hnd_yield_cont(kk_nagare_io_file__effect__new_mlift_with_write_file_10394_fun922(i_10475, _ctx), _ctx); /*10002*/
    kk_unit_unbox(_x_x921); return kk_Unit;
  }
  {
    y; return kk_Unit;
  }
}

kk_box_t kk_nagare_io_file__effect__mlift_with_write_file_10394(kk_function_t body, kk_nagare_io_file__effect__write_handle h, kk_context_t* _ctx) { /* forall<a,e> (body : (write-handle) -> <fileWrite|e> a, h : write-handle) -> <fileWrite|e> a */ 
  kk_box_t _x_x927 = kk_function_call(kk_box_t, (kk_function_t, kk_nagare_io_file__effect__write_handle, kk_context_t*), body, (body, h, _ctx), _ctx); /*2199*/
  return kk_std_core_hnd_finally_prompt(kk_nagare_io_file__effect__new_mlift_with_write_file_10394_fun916(h, _ctx), _x_x927, _ctx);
}


// lift anonymous function
struct kk_nagare_io_file__effect_with_write_file_fun933__t {
  struct kk_function_s _base;
  kk_ssize_t i_10484;
};
static kk_box_t kk_nagare_io_file__effect_with_write_file_fun933(kk_function_t _fself, kk_function_t _b_x242, kk_box_t _b_x243, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_with_write_file_fun933(kk_ssize_t i_10484, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_with_write_file_fun933__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect_with_write_file_fun933__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect_with_write_file_fun933, kk_context());
  _self->i_10484 = i_10484;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file__effect_with_write_file_fun933(kk_function_t _fself, kk_function_t _b_x242, kk_box_t _b_x243, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_with_write_file_fun933__t* _self = kk_function_as(struct kk_nagare_io_file__effect_with_write_file_fun933__t*, _fself, _ctx);
  kk_ssize_t i_10484 = _self->i_10484; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_10484, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_10484, _b_x242, _b_x243, _ctx);
}


// lift anonymous function
struct kk_nagare_io_file__effect_with_write_file_fun934__t {
  struct kk_function_s _base;
  kk_function_t body;
};
static kk_box_t kk_nagare_io_file__effect_with_write_file_fun934(kk_function_t _fself, kk_box_t _b_x252, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_with_write_file_fun934(kk_function_t body, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_with_write_file_fun934__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect_with_write_file_fun934__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect_with_write_file_fun934, kk_context());
  _self->body = body;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file__effect_with_write_file_fun934(kk_function_t _fself, kk_box_t _b_x252, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_with_write_file_fun934__t* _self = kk_function_as(struct kk_nagare_io_file__effect_with_write_file_fun934__t*, _fself, _ctx);
  kk_function_t body = _self->body; /* (nagare/io/file_effect/write-handle) -> <nagare/io/file_effect/fileWrite|2200> 2199 */
  kk_drop_match(_self, {kk_function_dup(body, _ctx);}, {}, _ctx)
  kk_nagare_io_file__effect__write_handle _x_x935 = kk_nagare_io_file__effect__write_handle_unbox(_b_x252, KK_OWNED, _ctx); /*nagare/io/file_effect/write-handle*/
  return kk_nagare_io_file__effect__mlift_with_write_file_10394(body, _x_x935, _ctx);
}


// lift anonymous function
struct kk_nagare_io_file__effect_with_write_file_fun936__t {
  struct kk_function_s _base;
  kk_nagare_io_file__effect__write_handle x_10481;
};
static kk_unit_t kk_nagare_io_file__effect_with_write_file_fun936(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_with_write_file_fun936(kk_nagare_io_file__effect__write_handle x_10481, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_with_write_file_fun936__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect_with_write_file_fun936__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect_with_write_file_fun936, kk_context());
  _self->x_10481 = x_10481;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_io_file__effect_with_write_file_fun942__t {
  struct kk_function_s _base;
  kk_ssize_t i_0_10492;
};
static kk_box_t kk_nagare_io_file__effect_with_write_file_fun942(kk_function_t _fself, kk_function_t _b_x266, kk_box_t _b_x267, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_with_write_file_fun942(kk_ssize_t i_0_10492, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_with_write_file_fun942__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect_with_write_file_fun942__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect_with_write_file_fun942, kk_context());
  _self->i_0_10492 = i_0_10492;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_io_file__effect_with_write_file_fun943__t {
  struct kk_function_s _base;
  kk_function_t _b_x266;
};
static kk_unit_t kk_nagare_io_file__effect_with_write_file_fun943(kk_function_t _fself, kk_box_t _b_x268, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_with_write_file_fun943(kk_function_t _b_x266, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_with_write_file_fun943__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect_with_write_file_fun943__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect_with_write_file_fun943, kk_context());
  _self->_b_x266 = _b_x266;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_unit_t kk_nagare_io_file__effect_with_write_file_fun943(kk_function_t _fself, kk_box_t _b_x268, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_with_write_file_fun943__t* _self = kk_function_as(struct kk_nagare_io_file__effect_with_write_file_fun943__t*, _fself, _ctx);
  kk_function_t _b_x266 = _self->_b_x266; /* (10003) -> 10001 10000 */
  kk_drop_match(_self, {kk_function_dup(_b_x266, _ctx);}, {}, _ctx)
  kk_box_t _x_x944 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _b_x266, (_b_x266, _b_x268, _ctx), _ctx); /*10000*/
  kk_unit_unbox(_x_x944); return kk_Unit;
}


// lift anonymous function
struct kk_nagare_io_file__effect_with_write_file_fun945__t {
  struct kk_function_s _base;
  kk_function_t _b_x262_273;
};
static kk_box_t kk_nagare_io_file__effect_with_write_file_fun945(kk_function_t _fself, kk_box_t _b_x264, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_with_write_file_fun945(kk_function_t _b_x262_273, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_with_write_file_fun945__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect_with_write_file_fun945__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect_with_write_file_fun945, kk_context());
  _self->_b_x262_273 = _b_x262_273;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file__effect_with_write_file_fun945(kk_function_t _fself, kk_box_t _b_x264, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_with_write_file_fun945__t* _self = kk_function_as(struct kk_nagare_io_file__effect_with_write_file_fun945__t*, _fself, _ctx);
  kk_function_t _b_x262_273 = _self->_b_x262_273; /* (10011) -> <nagare/io/file_effect/fileWrite|2200> () */
  kk_drop_match(_self, {kk_function_dup(_b_x262_273, _ctx);}, {}, _ctx)
  kk_unit_t _x_x946 = kk_Unit;
  kk_function_call(kk_unit_t, (kk_function_t, kk_box_t, kk_context_t*), _b_x262_273, (_b_x262_273, _b_x264, _ctx), _ctx);
  return kk_unit_box(_x_x946);
}
static kk_box_t kk_nagare_io_file__effect_with_write_file_fun942(kk_function_t _fself, kk_function_t _b_x266, kk_box_t _b_x267, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_with_write_file_fun942__t* _self = kk_function_as(struct kk_nagare_io_file__effect_with_write_file_fun942__t*, _fself, _ctx);
  kk_ssize_t i_0_10492 = _self->i_0_10492; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_0_10492, _ctx);}, {}, _ctx)
  kk_function_t cont_0_276 = kk_nagare_io_file__effect_new_with_write_file_fun943(_b_x266, _ctx); /*(10011) -> <nagare/io/file_effect/fileWrite|2200> ()*/;
  kk_box_t res_0_277 = _b_x267; /*10011*/;
  kk_ssize_t _b_x261_272 = i_0_10492; /*hnd/ev-index*/;
  kk_function_t _b_x262_273 = cont_0_276; /*(10011) -> <nagare/io/file_effect/fileWrite|2200> ()*/;
  kk_box_t _b_x263_274 = res_0_277; /*10011*/;
  return kk_std_core_hnd_open_at1(_b_x261_272, kk_nagare_io_file__effect_new_with_write_file_fun945(_b_x262_273, _ctx), _b_x263_274, _ctx);
}
static kk_unit_t kk_nagare_io_file__effect_with_write_file_fun936(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_with_write_file_fun936__t* _self = kk_function_as(struct kk_nagare_io_file__effect_with_write_file_fun936__t*, _fself, _ctx);
  kk_nagare_io_file__effect__write_handle x_10481 = _self->x_10481; /* nagare/io/file_effect/write-handle */
  kk_drop_match(_self, {kk_nagare_io_file__effect__write_handle_dup(x_10481, _ctx);}, {}, _ctx)
  kk_ssize_t i_0_10492;
  kk_std_core_hnd__htag _x_x937 = kk_std_core_hnd__htag_dup(kk_nagare_io_file__effect_fileWrite_fs__tag, _ctx); /*hnd/htag<nagare/io/file_effect/fileWrite>*/
  i_0_10492 = kk_std_core_hnd__evv_index(_x_x937, _ctx); /*hnd/ev-index*/
  kk_evv_t w_0 = kk_evv_swap_create1(i_0_10492,kk_context()); /*hnd/evv<<nagare/io/file_effect/fileWrite|2200>>*/;
  kk_std_core_hnd__ev ev_0_10495 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<nagare/io/file_effect/fileWrite>*/;
  kk_unit_t y_0 = kk_Unit;
  kk_box_t _x_x938;
  {
    struct kk_std_core_hnd_Ev* _con_x939 = kk_std_core_hnd__as_Ev(ev_0_10495, _ctx);
    kk_box_t _box_x253 = _con_x939->hnd;
    int32_t m_0 = _con_x939->marker;
    kk_nagare_io_file__effect__fileWrite h_2 = kk_nagare_io_file__effect__fileWrite_unbox(_box_x253, KK_BORROWED, _ctx);
    kk_nagare_io_file__effect__fileWrite_dup(h_2, _ctx);
    {
      struct kk_nagare_io_file__effect__Hnd_fileWrite* _con_x940 = kk_nagare_io_file__effect__as_Hnd_fileWrite(h_2, _ctx);
      kk_integer_t _pat_0_4 = _con_x940->_cfc;
      kk_std_core_hnd__clause1 _fun_closeWrite = _con_x940->_fun_closeWrite;
      kk_std_core_hnd__clause1 _pat_1_2 = _con_x940->_fun_openWrite;
      kk_std_core_hnd__clause2 _pat_2_1 = _con_x940->_fun_writeChunk;
      kk_std_core_hnd__clause2 _pat_3_0 = _con_x940->_fun_writeChunkBytes;
      if kk_likely(kk_datatype_ptr_is_unique(h_2, _ctx)) {
        kk_std_core_hnd__clause2_drop(_pat_3_0, _ctx);
        kk_std_core_hnd__clause2_drop(_pat_2_1, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_1_2, _ctx);
        kk_integer_drop(_pat_0_4, _ctx);
        kk_datatype_ptr_free(h_2, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_fun_closeWrite, _ctx);
        kk_datatype_ptr_decref(h_2, _ctx);
      }
      {
        kk_function_t _fun_unbox_x257 = _fun_closeWrite.clause;
        _x_x938 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x257, (_fun_unbox_x257, m_0, ev_0_10495, kk_nagare_io_file__effect__write_handle_box(x_10481, _ctx), _ctx), _ctx); /*10010*/
      }
    }
  }
  kk_unit_unbox(_x_x938);
  kk_evv_set(w_0,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x941 = kk_std_core_hnd_yield_cont(kk_nagare_io_file__effect_new_with_write_file_fun942(i_0_10492, _ctx), _ctx); /*10002*/
    kk_unit_unbox(_x_x941); return kk_Unit;
  }
  {
    y_0; return kk_Unit;
  }
}

kk_box_t kk_nagare_io_file__effect_with_write_file(kk_string_t path, kk_function_t body, kk_context_t* _ctx) { /* forall<a,e> (path : string, body : (write-handle) -> <fileWrite|e> a) -> <fileWrite|e> a */ 
  kk_ssize_t i_10484;
  kk_std_core_hnd__htag _x_x928 = kk_std_core_hnd__htag_dup(kk_nagare_io_file__effect_fileWrite_fs__tag, _ctx); /*hnd/htag<nagare/io/file_effect/fileWrite>*/
  i_10484 = kk_std_core_hnd__evv_index(_x_x928, _ctx); /*hnd/ev-index*/
  kk_evv_t w = kk_evv_swap_create1(i_10484,kk_context()); /*hnd/evv<<nagare/io/file_effect/fileWrite|2200>>*/;
  kk_std_core_hnd__ev ev_10487 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<nagare/io/file_effect/fileWrite>*/;
  kk_nagare_io_file__effect__write_handle y;
  kk_box_t _x_x929;
  {
    struct kk_std_core_hnd_Ev* _con_x930 = kk_std_core_hnd__as_Ev(ev_10487, _ctx);
    kk_box_t _box_x229 = _con_x930->hnd;
    int32_t m = _con_x930->marker;
    kk_nagare_io_file__effect__fileWrite h = kk_nagare_io_file__effect__fileWrite_unbox(_box_x229, KK_BORROWED, _ctx);
    kk_nagare_io_file__effect__fileWrite_dup(h, _ctx);
    {
      struct kk_nagare_io_file__effect__Hnd_fileWrite* _con_x931 = kk_nagare_io_file__effect__as_Hnd_fileWrite(h, _ctx);
      kk_integer_t _pat_0 = _con_x931->_cfc;
      kk_std_core_hnd__clause1 _pat_1 = _con_x931->_fun_closeWrite;
      kk_std_core_hnd__clause1 _fun_openWrite = _con_x931->_fun_openWrite;
      kk_std_core_hnd__clause2 _pat_2_0 = _con_x931->_fun_writeChunk;
      kk_std_core_hnd__clause2 _pat_3 = _con_x931->_fun_writeChunkBytes;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause2_drop(_pat_3, _ctx);
        kk_std_core_hnd__clause2_drop(_pat_2_0, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_1, _ctx);
        kk_integer_drop(_pat_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_fun_openWrite, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x233 = _fun_openWrite.clause;
        _x_x929 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x233, (_fun_unbox_x233, m, ev_10487, kk_string_box(path), _ctx), _ctx); /*10010*/
      }
    }
  }
  y = kk_nagare_io_file__effect__write_handle_unbox(_x_x929, KK_OWNED, _ctx); /*nagare/io/file_effect/write-handle*/
  kk_evv_set(w,kk_context());
  kk_nagare_io_file__effect__write_handle x_10481;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x932 = kk_std_core_hnd_yield_cont(kk_nagare_io_file__effect_new_with_write_file_fun933(i_10484, _ctx), _ctx); /*10002*/
    x_10481 = kk_nagare_io_file__effect__write_handle_unbox(_x_x932, KK_OWNED, _ctx); /*nagare/io/file_effect/write-handle*/
  }
  else {
    x_10481 = y; /*nagare/io/file_effect/write-handle*/
  }
  if (kk_yielding(kk_context())) {
    return kk_std_core_hnd_yield_extend(kk_nagare_io_file__effect_new_with_write_file_fun934(body, _ctx), _ctx);
  }
  {
    kk_box_t _x_x947 = kk_function_call(kk_box_t, (kk_function_t, kk_nagare_io_file__effect__write_handle, kk_context_t*), body, (body, x_10481, _ctx), _ctx); /*2199*/
    return kk_std_core_hnd_finally_prompt(kk_nagare_io_file__effect_new_with_write_file_fun936(x_10481, _ctx), _x_x947, _ctx);
  }
}


// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileRead_fun948__t {
  struct kk_function_s _base;
};
static kk_unit_t kk_nagare_io_file__effect_defaultFileRead_fun948(kk_function_t _fself, kk_nagare_io_file__effect__read_handle h, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileRead_fun948(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file__effect_defaultFileRead_fun948, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_unit_t kk_nagare_io_file__effect_defaultFileRead_fun948(kk_function_t _fself, kk_nagare_io_file__effect__read_handle h, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  intptr_t _x_x949;
  {
    intptr_t _x = h.fd;
    _x_x949 = _x; /*intptr_t*/
  }
  kk_nagare_io_file__effect_nagare_fclose(_x_x949, _ctx); return kk_Unit;
}


// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileRead_fun950__t {
  struct kk_function_s _base;
};
static kk_nagare_io_file__effect__read_handle kk_nagare_io_file__effect_defaultFileRead_fun950(kk_function_t _fself, kk_string_t p, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileRead_fun950(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file__effect_defaultFileRead_fun950, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileRead_fun952__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_io_file__effect_defaultFileRead_fun952(kk_function_t _fself, kk_box_t _b_x281, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileRead_fun952(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file__effect_defaultFileRead_fun952, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_io_file__effect_defaultFileRead_fun952(kk_function_t _fself, kk_box_t _b_x281, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_nagare_io_file__effect__read_handle _x_x953;
  intptr_t _x_x954 = kk_intptr_unbox(_b_x281, KK_OWNED, _ctx); /*intptr_t*/
  _x_x953 = kk_nagare_io_file__effect__mlift_defaultFileRead_10395(_x_x954, _ctx); /*nagare/io/file_effect/read-handle*/
  return kk_nagare_io_file__effect__read_handle_box(_x_x953, _ctx);
}
static kk_nagare_io_file__effect__read_handle kk_nagare_io_file__effect_defaultFileRead_fun950(kk_function_t _fself, kk_string_t p, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  intptr_t x_0_10500 = kk_nagare_io_file__effect_nagare_fopen_read(p, _ctx); /*intptr_t*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x951 = kk_std_core_hnd_yield_extend(kk_nagare_io_file__effect_new_defaultFileRead_fun952(_ctx), _ctx); /*10001*/
    return kk_nagare_io_file__effect__read_handle_unbox(_x_x951, KK_OWNED, _ctx);
  }
  {
    return kk_nagare_io_file__effect__new_ReadHandle(x_0_10500, _ctx);
  }
}


// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileRead_fun955__t {
  struct kk_function_s _base;
};
static kk_string_t kk_nagare_io_file__effect_defaultFileRead_fun955(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ev, kk_nagare_io_file__effect__read_handle x1_0, kk_integer_t x2, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileRead_fun955(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file__effect_defaultFileRead_fun955, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileRead_fun957__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_io_file__effect_defaultFileRead_fun957(kk_function_t _fself, kk_box_t _b_x288, kk_box_t _b_x289, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileRead_fun957(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file__effect_defaultFileRead_fun957, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_io_file__effect_defaultFileRead_fun957(kk_function_t _fself, kk_box_t _b_x288, kk_box_t _b_x289, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_nagare_io_file__effect__read_handle h_0_327 = kk_nagare_io_file__effect__read_handle_unbox(_b_x288, KK_OWNED, _ctx); /*nagare/io/file_effect/read-handle*/;
  kk_integer_t size_328 = kk_integer_unbox(_b_x289, _ctx); /*int*/;
  kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_unit_t keep_0 = kk_Unit;
  kk_evv_set(w_0,kk_context());
  kk_string_t _x_x958;
  intptr_t _x_x959;
  {
    intptr_t _x_0 = h_0_327.fd;
    _x_x959 = _x_0; /*intptr_t*/
  }
  _x_x958 = kk_nagare_io_file__effect_nagare_fread_chunk(_x_x959, size_328, _ctx); /*string*/
  return kk_string_box(_x_x958);
}
static kk_string_t kk_nagare_io_file__effect_defaultFileRead_fun955(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ev, kk_nagare_io_file__effect__read_handle x1_0, kk_integer_t x2, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_box_t _x_x956 = kk_std_core_hnd_under2(ev, kk_nagare_io_file__effect_new_defaultFileRead_fun957(_ctx), kk_nagare_io_file__effect__read_handle_box(x1_0, _ctx), kk_integer_box(x2, _ctx), _ctx); /*10002*/
  return kk_string_unbox(_x_x956);
}


// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileRead_fun960__t {
  struct kk_function_s _base;
};
static kk_vector_t kk_nagare_io_file__effect_defaultFileRead_fun960(kk_function_t _fself, int32_t m_0, kk_std_core_hnd__ev ev_0, kk_nagare_io_file__effect__read_handle x1_2, kk_integer_t x2_0, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileRead_fun960(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file__effect_defaultFileRead_fun960, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileRead_fun962__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_io_file__effect_defaultFileRead_fun962(kk_function_t _fself, kk_box_t _b_x299, kk_box_t _b_x300, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileRead_fun962(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file__effect_defaultFileRead_fun962, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_io_file__effect_defaultFileRead_fun962(kk_function_t _fself, kk_box_t _b_x299, kk_box_t _b_x300, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_nagare_io_file__effect__read_handle h_1_329 = kk_nagare_io_file__effect__read_handle_unbox(_b_x299, KK_OWNED, _ctx); /*nagare/io/file_effect/read-handle*/;
  kk_integer_t size_0_330 = kk_integer_unbox(_b_x300, _ctx); /*int*/;
  kk_evv_t w_1 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_unit_t keep_1 = kk_Unit;
  kk_evv_set(w_1,kk_context());
  kk_vector_t _x_x963;
  intptr_t _x_x964;
  {
    intptr_t _x_1 = h_1_329.fd;
    _x_x964 = _x_1; /*intptr_t*/
  }
  _x_x963 = kk_nagare_io_file__effect_nagare_fread_chunk_bytes(_x_x964, size_0_330, _ctx); /*vector<int8>*/
  return kk_vector_box(_x_x963, _ctx);
}
static kk_vector_t kk_nagare_io_file__effect_defaultFileRead_fun960(kk_function_t _fself, int32_t m_0, kk_std_core_hnd__ev ev_0, kk_nagare_io_file__effect__read_handle x1_2, kk_integer_t x2_0, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_box_t _x_x961 = kk_std_core_hnd_under2(ev_0, kk_nagare_io_file__effect_new_defaultFileRead_fun962(_ctx), kk_nagare_io_file__effect__read_handle_box(x1_2, _ctx), kk_integer_box(x2_0, _ctx), _ctx); /*10002*/
  return kk_vector_unbox(_x_x961, _ctx);
}


// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileRead_fun965__t {
  struct kk_function_s _base;
};
static kk_string_t kk_nagare_io_file__effect_defaultFileRead_fun965(kk_function_t _fself, kk_string_t p_0, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileRead_fun965(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file__effect_defaultFileRead_fun965, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileRead_fun968__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_io_file__effect_defaultFileRead_fun968(kk_function_t _fself, kk_box_t _b_x308, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileRead_fun968(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file__effect_defaultFileRead_fun968, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_io_file__effect_defaultFileRead_fun968(kk_function_t _fself, kk_box_t _b_x308, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_os_path__path _x_x969;
  kk_string_t _x_x970 = kk_string_unbox(_b_x308); /*string*/
  _x_x969 = kk_std_os_path_path(_x_x970, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x_x969, _ctx);
}
static kk_string_t kk_nagare_io_file__effect_defaultFileRead_fun965(kk_function_t _fself, kk_string_t p_0, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_os_path__path _x_x966;
  kk_box_t _x_x967 = kk_std_core_hnd__open_none1(kk_nagare_io_file__effect_new_defaultFileRead_fun968(_ctx), kk_string_box(p_0), _ctx); /*10001*/
  _x_x966 = kk_std_os_path__path_unbox(_x_x967, KK_OWNED, _ctx); /*std/os/path/path*/
  return kk_std_os_file_read_text_file(_x_x966, _ctx);
}


// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileRead_fun973__t {
  struct kk_function_s _base;
  kk_function_t _b_x278_311;
};
static kk_box_t kk_nagare_io_file__effect_defaultFileRead_fun973(kk_function_t _fself, kk_box_t _b_x279, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileRead_fun973(kk_function_t _b_x278_311, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileRead_fun973__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect_defaultFileRead_fun973__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect_defaultFileRead_fun973, kk_context());
  _self->_b_x278_311 = _b_x278_311;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file__effect_defaultFileRead_fun973(kk_function_t _fself, kk_box_t _b_x279, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileRead_fun973__t* _self = kk_function_as(struct kk_nagare_io_file__effect_defaultFileRead_fun973__t*, _fself, _ctx);
  kk_function_t _b_x278_311 = _self->_b_x278_311; /* (h : nagare/io/file_effect/read-handle) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> () */
  kk_drop_match(_self, {kk_function_dup(_b_x278_311, _ctx);}, {}, _ctx)
  kk_unit_t _x_x974 = kk_Unit;
  kk_nagare_io_file__effect__read_handle _x_x975 = kk_nagare_io_file__effect__read_handle_unbox(_b_x279, KK_OWNED, _ctx); /*nagare/io/file_effect/read-handle*/
  kk_function_call(kk_unit_t, (kk_function_t, kk_nagare_io_file__effect__read_handle, kk_context_t*), _b_x278_311, (_b_x278_311, _x_x975, _ctx), _ctx);
  return kk_unit_box(_x_x974);
}


// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileRead_fun977__t {
  struct kk_function_s _base;
  kk_function_t _b_x282_312;
};
static kk_box_t kk_nagare_io_file__effect_defaultFileRead_fun977(kk_function_t _fself, kk_box_t _b_x283, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileRead_fun977(kk_function_t _b_x282_312, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileRead_fun977__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect_defaultFileRead_fun977__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect_defaultFileRead_fun977, kk_context());
  _self->_b_x282_312 = _b_x282_312;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file__effect_defaultFileRead_fun977(kk_function_t _fself, kk_box_t _b_x283, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileRead_fun977__t* _self = kk_function_as(struct kk_nagare_io_file__effect_defaultFileRead_fun977__t*, _fself, _ctx);
  kk_function_t _b_x282_312 = _self->_b_x282_312; /* (p : string) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> nagare/io/file_effect/read-handle */
  kk_drop_match(_self, {kk_function_dup(_b_x282_312, _ctx);}, {}, _ctx)
  kk_nagare_io_file__effect__read_handle _x_x978;
  kk_string_t _x_x979 = kk_string_unbox(_b_x283); /*string*/
  _x_x978 = kk_function_call(kk_nagare_io_file__effect__read_handle, (kk_function_t, kk_string_t, kk_context_t*), _b_x282_312, (_b_x282_312, _x_x979, _ctx), _ctx); /*nagare/io/file_effect/read-handle*/
  return kk_nagare_io_file__effect__read_handle_box(_x_x978, _ctx);
}


// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileRead_fun981__t {
  struct kk_function_s _base;
  kk_function_t _b_x290_314;
};
static kk_box_t kk_nagare_io_file__effect_defaultFileRead_fun981(kk_function_t _fself, int32_t _b_x291, kk_std_core_hnd__ev _b_x292, kk_box_t _b_x293, kk_box_t _b_x294, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileRead_fun981(kk_function_t _b_x290_314, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileRead_fun981__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect_defaultFileRead_fun981__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect_defaultFileRead_fun981, kk_context());
  _self->_b_x290_314 = _b_x290_314;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file__effect_defaultFileRead_fun981(kk_function_t _fself, int32_t _b_x291, kk_std_core_hnd__ev _b_x292, kk_box_t _b_x293, kk_box_t _b_x294, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileRead_fun981__t* _self = kk_function_as(struct kk_nagare_io_file__effect_defaultFileRead_fun981__t*, _fself, _ctx);
  kk_function_t _b_x290_314 = _self->_b_x290_314; /* (m : hnd/marker<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>,2420>, ev : hnd/ev<nagare/io/file_effect/fileRead>, x1@0 : nagare/io/file_effect/read-handle, x2 : int) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> string */
  kk_drop_match(_self, {kk_function_dup(_b_x290_314, _ctx);}, {}, _ctx)
  kk_string_t _x_x982;
  kk_nagare_io_file__effect__read_handle _x_x983 = kk_nagare_io_file__effect__read_handle_unbox(_b_x293, KK_OWNED, _ctx); /*nagare/io/file_effect/read-handle*/
  kk_integer_t _x_x984 = kk_integer_unbox(_b_x294, _ctx); /*int*/
  _x_x982 = kk_function_call(kk_string_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_nagare_io_file__effect__read_handle, kk_integer_t, kk_context_t*), _b_x290_314, (_b_x290_314, _b_x291, _b_x292, _x_x983, _x_x984, _ctx), _ctx); /*string*/
  return kk_string_box(_x_x982);
}


// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileRead_fun986__t {
  struct kk_function_s _base;
  kk_function_t _b_x301_319;
};
static kk_box_t kk_nagare_io_file__effect_defaultFileRead_fun986(kk_function_t _fself, int32_t _b_x302, kk_std_core_hnd__ev _b_x303, kk_box_t _b_x304, kk_box_t _b_x305, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileRead_fun986(kk_function_t _b_x301_319, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileRead_fun986__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect_defaultFileRead_fun986__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect_defaultFileRead_fun986, kk_context());
  _self->_b_x301_319 = _b_x301_319;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file__effect_defaultFileRead_fun986(kk_function_t _fself, int32_t _b_x302, kk_std_core_hnd__ev _b_x303, kk_box_t _b_x304, kk_box_t _b_x305, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileRead_fun986__t* _self = kk_function_as(struct kk_nagare_io_file__effect_defaultFileRead_fun986__t*, _fself, _ctx);
  kk_function_t _b_x301_319 = _self->_b_x301_319; /* (m@0 : hnd/marker<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>,2420>, ev@0 : hnd/ev<nagare/io/file_effect/fileRead>, x1@2 : nagare/io/file_effect/read-handle, x2@0 : int) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> vector<int8> */
  kk_drop_match(_self, {kk_function_dup(_b_x301_319, _ctx);}, {}, _ctx)
  kk_vector_t _x_x987;
  kk_nagare_io_file__effect__read_handle _x_x988 = kk_nagare_io_file__effect__read_handle_unbox(_b_x304, KK_OWNED, _ctx); /*nagare/io/file_effect/read-handle*/
  kk_integer_t _x_x989 = kk_integer_unbox(_b_x305, _ctx); /*int*/
  _x_x987 = kk_function_call(kk_vector_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_nagare_io_file__effect__read_handle, kk_integer_t, kk_context_t*), _b_x301_319, (_b_x301_319, _b_x302, _b_x303, _x_x988, _x_x989, _ctx), _ctx); /*vector<int8>*/
  return kk_vector_box(_x_x987, _ctx);
}


// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileRead_fun991__t {
  struct kk_function_s _base;
  kk_function_t _b_x309_324;
};
static kk_box_t kk_nagare_io_file__effect_defaultFileRead_fun991(kk_function_t _fself, kk_box_t _b_x310, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileRead_fun991(kk_function_t _b_x309_324, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileRead_fun991__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect_defaultFileRead_fun991__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect_defaultFileRead_fun991, kk_context());
  _self->_b_x309_324 = _b_x309_324;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file__effect_defaultFileRead_fun991(kk_function_t _fself, kk_box_t _b_x310, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileRead_fun991__t* _self = kk_function_as(struct kk_nagare_io_file__effect_defaultFileRead_fun991__t*, _fself, _ctx);
  kk_function_t _b_x309_324 = _self->_b_x309_324; /* (p@0 : string) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> string */
  kk_drop_match(_self, {kk_function_dup(_b_x309_324, _ctx);}, {}, _ctx)
  kk_string_t _x_x992;
  kk_string_t _x_x993 = kk_string_unbox(_b_x310); /*string*/
  _x_x992 = kk_function_call(kk_string_t, (kk_function_t, kk_string_t, kk_context_t*), _b_x309_324, (_b_x309_324, _x_x993, _ctx), _ctx); /*string*/
  return kk_string_box(_x_x992);
}


// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileRead_fun994__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_io_file__effect_defaultFileRead_fun994(kk_function_t _fself, kk_box_t _res, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileRead_fun994(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file__effect_defaultFileRead_fun994, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_io_file__effect_defaultFileRead_fun994(kk_function_t _fself, kk_box_t _res, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return _res;
}

kk_box_t kk_nagare_io_file__effect_defaultFileRead(kk_function_t action, kk_context_t* _ctx) { /* forall<a> (action : () -> <fileRead|io> a) -> io a */ 
  kk_function_t _b_x278_311 = kk_nagare_io_file__effect_new_defaultFileRead_fun948(_ctx); /*(h : nagare/io/file_effect/read-handle) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> ()*/;
  kk_function_t _b_x282_312 = kk_nagare_io_file__effect_new_defaultFileRead_fun950(_ctx); /*(p : string) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> nagare/io/file_effect/read-handle*/;
  kk_function_t _b_x290_314 = kk_nagare_io_file__effect_new_defaultFileRead_fun955(_ctx); /*(m : hnd/marker<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>,2420>, ev : hnd/ev<nagare/io/file_effect/fileRead>, x1@0 : nagare/io/file_effect/read-handle, x2 : int) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> string*/;
  kk_function_t _b_x301_319 = kk_nagare_io_file__effect_new_defaultFileRead_fun960(_ctx); /*(m@0 : hnd/marker<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>,2420>, ev@0 : hnd/ev<nagare/io/file_effect/fileRead>, x1@2 : nagare/io/file_effect/read-handle, x2@0 : int) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> vector<int8>*/;
  kk_function_t _b_x309_324 = kk_nagare_io_file__effect_new_defaultFileRead_fun965(_ctx); /*(p@0 : string) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> string*/;
  kk_nagare_io_file__effect__fileRead _x_x971;
  kk_std_core_hnd__clause1 _x_x972 = kk_std_core_hnd_clause_tail1(kk_nagare_io_file__effect_new_defaultFileRead_fun973(_b_x278_311, _ctx), _ctx); /*hnd/clause1<10003,10004,10002,10000,10001>*/
  kk_std_core_hnd__clause1 _x_x976 = kk_std_core_hnd_clause_tail1(kk_nagare_io_file__effect_new_defaultFileRead_fun977(_b_x282_312, _ctx), _ctx); /*hnd/clause1<10003,10004,10002,10000,10001>*/
  kk_std_core_hnd__clause2 _x_x980 = kk_std_core_hnd__new_Clause2(kk_nagare_io_file__effect_new_defaultFileRead_fun981(_b_x290_314, _ctx), _ctx); /*hnd/clause2<10021,10022,10023,10024,10025,10026>*/
  kk_std_core_hnd__clause2 _x_x985 = kk_std_core_hnd__new_Clause2(kk_nagare_io_file__effect_new_defaultFileRead_fun986(_b_x301_319, _ctx), _ctx); /*hnd/clause2<10021,10022,10023,10024,10025,10026>*/
  kk_std_core_hnd__clause1 _x_x990 = kk_std_core_hnd_clause_tail1(kk_nagare_io_file__effect_new_defaultFileRead_fun991(_b_x309_324, _ctx), _ctx); /*hnd/clause1<10003,10004,10002,10000,10001>*/
  _x_x971 = kk_nagare_io_file__effect__new_Hnd_fileRead(kk_reuse_null, 0, kk_integer_from_small(1), _x_x972, _x_x976, _x_x980, _x_x985, _x_x990, _ctx); /*nagare/io/file_effect/fileRead<31,32>*/
  return kk_nagare_io_file__effect_fileRead_fs__handle(_x_x971, kk_nagare_io_file__effect_new_defaultFileRead_fun994(_ctx), action, _ctx);
}


// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileWrite_fun995__t {
  struct kk_function_s _base;
};
static kk_unit_t kk_nagare_io_file__effect_defaultFileWrite_fun995(kk_function_t _fself, kk_nagare_io_file__effect__write_handle h, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileWrite_fun995(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file__effect_defaultFileWrite_fun995, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_unit_t kk_nagare_io_file__effect_defaultFileWrite_fun995(kk_function_t _fself, kk_nagare_io_file__effect__write_handle h, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  intptr_t _x_x996;
  {
    intptr_t _x = h.fd;
    _x_x996 = _x; /*intptr_t*/
  }
  kk_nagare_io_file__effect_nagare_fclose(_x_x996, _ctx); return kk_Unit;
}


// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileWrite_fun997__t {
  struct kk_function_s _base;
};
static kk_nagare_io_file__effect__write_handle kk_nagare_io_file__effect_defaultFileWrite_fun997(kk_function_t _fself, kk_string_t p, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileWrite_fun997(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file__effect_defaultFileWrite_fun997, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileWrite_fun999__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_io_file__effect_defaultFileWrite_fun999(kk_function_t _fself, kk_box_t _b_x334, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileWrite_fun999(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file__effect_defaultFileWrite_fun999, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_io_file__effect_defaultFileWrite_fun999(kk_function_t _fself, kk_box_t _b_x334, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_nagare_io_file__effect__write_handle _x_x1000;
  intptr_t _x_x1001 = kk_intptr_unbox(_b_x334, KK_OWNED, _ctx); /*intptr_t*/
  _x_x1000 = kk_nagare_io_file__effect__mlift_defaultFileWrite_10396(_x_x1001, _ctx); /*nagare/io/file_effect/write-handle*/
  return kk_nagare_io_file__effect__write_handle_box(_x_x1000, _ctx);
}
static kk_nagare_io_file__effect__write_handle kk_nagare_io_file__effect_defaultFileWrite_fun997(kk_function_t _fself, kk_string_t p, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  intptr_t x_0_10510 = kk_nagare_io_file__effect_nagare_fopen_write(p, _ctx); /*intptr_t*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x998 = kk_std_core_hnd_yield_extend(kk_nagare_io_file__effect_new_defaultFileWrite_fun999(_ctx), _ctx); /*10001*/
    return kk_nagare_io_file__effect__write_handle_unbox(_x_x998, KK_OWNED, _ctx);
  }
  {
    return kk_nagare_io_file__effect__new_WriteHandle(x_0_10510, _ctx);
  }
}


// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileWrite_fun1002__t {
  struct kk_function_s _base;
};
static kk_integer_t kk_nagare_io_file__effect_defaultFileWrite_fun1002(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ev, kk_nagare_io_file__effect__write_handle x1_0, kk_string_t x2, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileWrite_fun1002(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file__effect_defaultFileWrite_fun1002, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileWrite_fun1004__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_io_file__effect_defaultFileWrite_fun1004(kk_function_t _fself, kk_box_t _b_x341, kk_box_t _b_x342, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileWrite_fun1004(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file__effect_defaultFileWrite_fun1004, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_io_file__effect_defaultFileWrite_fun1004(kk_function_t _fself, kk_box_t _b_x341, kk_box_t _b_x342, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_nagare_io_file__effect__write_handle h_0_372 = kk_nagare_io_file__effect__write_handle_unbox(_b_x341, KK_OWNED, _ctx); /*nagare/io/file_effect/write-handle*/;
  kk_string_t content_373 = kk_string_unbox(_b_x342); /*string*/;
  kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_unit_t keep_0 = kk_Unit;
  kk_evv_set(w_0,kk_context());
  kk_integer_t _x_x1005;
  intptr_t _x_x1006;
  {
    intptr_t _x_0 = h_0_372.fd;
    _x_x1006 = _x_0; /*intptr_t*/
  }
  _x_x1005 = kk_nagare_io_file__effect_nagare_fwrite_chunk(_x_x1006, content_373, _ctx); /*int*/
  return kk_integer_box(_x_x1005, _ctx);
}
static kk_integer_t kk_nagare_io_file__effect_defaultFileWrite_fun1002(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ev, kk_nagare_io_file__effect__write_handle x1_0, kk_string_t x2, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_box_t _x_x1003 = kk_std_core_hnd_under2(ev, kk_nagare_io_file__effect_new_defaultFileWrite_fun1004(_ctx), kk_nagare_io_file__effect__write_handle_box(x1_0, _ctx), kk_string_box(x2), _ctx); /*10002*/
  return kk_integer_unbox(_x_x1003, _ctx);
}


// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileWrite_fun1007__t {
  struct kk_function_s _base;
};
static kk_integer_t kk_nagare_io_file__effect_defaultFileWrite_fun1007(kk_function_t _fself, int32_t m_0, kk_std_core_hnd__ev ev_0, kk_nagare_io_file__effect__write_handle x1_2, kk_vector_t x2_0, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileWrite_fun1007(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file__effect_defaultFileWrite_fun1007, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileWrite_fun1009__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_io_file__effect_defaultFileWrite_fun1009(kk_function_t _fself, kk_box_t _b_x352, kk_box_t _b_x353, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileWrite_fun1009(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file__effect_defaultFileWrite_fun1009, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_io_file__effect_defaultFileWrite_fun1009(kk_function_t _fself, kk_box_t _b_x352, kk_box_t _b_x353, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_nagare_io_file__effect__write_handle h_1_374 = kk_nagare_io_file__effect__write_handle_unbox(_b_x352, KK_OWNED, _ctx); /*nagare/io/file_effect/write-handle*/;
  kk_vector_t content_0_375 = kk_vector_unbox(_b_x353, _ctx); /*vector<int8>*/;
  kk_evv_t w_1 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_unit_t keep_1 = kk_Unit;
  kk_evv_set(w_1,kk_context());
  kk_integer_t _x_x1010;
  intptr_t _x_x1011;
  {
    intptr_t _x_1 = h_1_374.fd;
    _x_x1011 = _x_1; /*intptr_t*/
  }
  _x_x1010 = kk_nagare_io_file__effect_nagare_fwrite_chunk_bytes(_x_x1011, content_0_375, _ctx); /*int*/
  return kk_integer_box(_x_x1010, _ctx);
}
static kk_integer_t kk_nagare_io_file__effect_defaultFileWrite_fun1007(kk_function_t _fself, int32_t m_0, kk_std_core_hnd__ev ev_0, kk_nagare_io_file__effect__write_handle x1_2, kk_vector_t x2_0, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_box_t _x_x1008 = kk_std_core_hnd_under2(ev_0, kk_nagare_io_file__effect_new_defaultFileWrite_fun1009(_ctx), kk_nagare_io_file__effect__write_handle_box(x1_2, _ctx), kk_vector_box(x2_0, _ctx), _ctx); /*10002*/
  return kk_integer_unbox(_x_x1008, _ctx);
}


// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileWrite_fun1014__t {
  struct kk_function_s _base;
  kk_function_t _b_x331_359;
};
static kk_box_t kk_nagare_io_file__effect_defaultFileWrite_fun1014(kk_function_t _fself, kk_box_t _b_x332, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileWrite_fun1014(kk_function_t _b_x331_359, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileWrite_fun1014__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect_defaultFileWrite_fun1014__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect_defaultFileWrite_fun1014, kk_context());
  _self->_b_x331_359 = _b_x331_359;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file__effect_defaultFileWrite_fun1014(kk_function_t _fself, kk_box_t _b_x332, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileWrite_fun1014__t* _self = kk_function_as(struct kk_nagare_io_file__effect_defaultFileWrite_fun1014__t*, _fself, _ctx);
  kk_function_t _b_x331_359 = _self->_b_x331_359; /* (h : nagare/io/file_effect/write-handle) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> () */
  kk_drop_match(_self, {kk_function_dup(_b_x331_359, _ctx);}, {}, _ctx)
  kk_unit_t _x_x1015 = kk_Unit;
  kk_nagare_io_file__effect__write_handle _x_x1016 = kk_nagare_io_file__effect__write_handle_unbox(_b_x332, KK_OWNED, _ctx); /*nagare/io/file_effect/write-handle*/
  kk_function_call(kk_unit_t, (kk_function_t, kk_nagare_io_file__effect__write_handle, kk_context_t*), _b_x331_359, (_b_x331_359, _x_x1016, _ctx), _ctx);
  return kk_unit_box(_x_x1015);
}


// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileWrite_fun1018__t {
  struct kk_function_s _base;
  kk_function_t _b_x335_360;
};
static kk_box_t kk_nagare_io_file__effect_defaultFileWrite_fun1018(kk_function_t _fself, kk_box_t _b_x336, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileWrite_fun1018(kk_function_t _b_x335_360, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileWrite_fun1018__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect_defaultFileWrite_fun1018__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect_defaultFileWrite_fun1018, kk_context());
  _self->_b_x335_360 = _b_x335_360;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file__effect_defaultFileWrite_fun1018(kk_function_t _fself, kk_box_t _b_x336, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileWrite_fun1018__t* _self = kk_function_as(struct kk_nagare_io_file__effect_defaultFileWrite_fun1018__t*, _fself, _ctx);
  kk_function_t _b_x335_360 = _self->_b_x335_360; /* (p : string) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> nagare/io/file_effect/write-handle */
  kk_drop_match(_self, {kk_function_dup(_b_x335_360, _ctx);}, {}, _ctx)
  kk_nagare_io_file__effect__write_handle _x_x1019;
  kk_string_t _x_x1020 = kk_string_unbox(_b_x336); /*string*/
  _x_x1019 = kk_function_call(kk_nagare_io_file__effect__write_handle, (kk_function_t, kk_string_t, kk_context_t*), _b_x335_360, (_b_x335_360, _x_x1020, _ctx), _ctx); /*nagare/io/file_effect/write-handle*/
  return kk_nagare_io_file__effect__write_handle_box(_x_x1019, _ctx);
}


// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileWrite_fun1022__t {
  struct kk_function_s _base;
  kk_function_t _b_x343_362;
};
static kk_box_t kk_nagare_io_file__effect_defaultFileWrite_fun1022(kk_function_t _fself, int32_t _b_x344, kk_std_core_hnd__ev _b_x345, kk_box_t _b_x346, kk_box_t _b_x347, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileWrite_fun1022(kk_function_t _b_x343_362, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileWrite_fun1022__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect_defaultFileWrite_fun1022__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect_defaultFileWrite_fun1022, kk_context());
  _self->_b_x343_362 = _b_x343_362;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file__effect_defaultFileWrite_fun1022(kk_function_t _fself, int32_t _b_x344, kk_std_core_hnd__ev _b_x345, kk_box_t _b_x346, kk_box_t _b_x347, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileWrite_fun1022__t* _self = kk_function_as(struct kk_nagare_io_file__effect_defaultFileWrite_fun1022__t*, _fself, _ctx);
  kk_function_t _b_x343_362 = _self->_b_x343_362; /* (m : hnd/marker<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>,2606>, ev : hnd/ev<nagare/io/file_effect/fileWrite>, x1@0 : nagare/io/file_effect/write-handle, x2 : string) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> int */
  kk_drop_match(_self, {kk_function_dup(_b_x343_362, _ctx);}, {}, _ctx)
  kk_integer_t _x_x1023;
  kk_nagare_io_file__effect__write_handle _x_x1024 = kk_nagare_io_file__effect__write_handle_unbox(_b_x346, KK_OWNED, _ctx); /*nagare/io/file_effect/write-handle*/
  kk_string_t _x_x1025 = kk_string_unbox(_b_x347); /*string*/
  _x_x1023 = kk_function_call(kk_integer_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_nagare_io_file__effect__write_handle, kk_string_t, kk_context_t*), _b_x343_362, (_b_x343_362, _b_x344, _b_x345, _x_x1024, _x_x1025, _ctx), _ctx); /*int*/
  return kk_integer_box(_x_x1023, _ctx);
}


// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileWrite_fun1027__t {
  struct kk_function_s _base;
  kk_function_t _b_x354_367;
};
static kk_box_t kk_nagare_io_file__effect_defaultFileWrite_fun1027(kk_function_t _fself, int32_t _b_x355, kk_std_core_hnd__ev _b_x356, kk_box_t _b_x357, kk_box_t _b_x358, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileWrite_fun1027(kk_function_t _b_x354_367, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileWrite_fun1027__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect_defaultFileWrite_fun1027__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect_defaultFileWrite_fun1027, kk_context());
  _self->_b_x354_367 = _b_x354_367;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file__effect_defaultFileWrite_fun1027(kk_function_t _fself, int32_t _b_x355, kk_std_core_hnd__ev _b_x356, kk_box_t _b_x357, kk_box_t _b_x358, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileWrite_fun1027__t* _self = kk_function_as(struct kk_nagare_io_file__effect_defaultFileWrite_fun1027__t*, _fself, _ctx);
  kk_function_t _b_x354_367 = _self->_b_x354_367; /* (m@0 : hnd/marker<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>,2606>, ev@0 : hnd/ev<nagare/io/file_effect/fileWrite>, x1@2 : nagare/io/file_effect/write-handle, x2@0 : vector<int8>) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> int */
  kk_drop_match(_self, {kk_function_dup(_b_x354_367, _ctx);}, {}, _ctx)
  kk_integer_t _x_x1028;
  kk_nagare_io_file__effect__write_handle _x_x1029 = kk_nagare_io_file__effect__write_handle_unbox(_b_x357, KK_OWNED, _ctx); /*nagare/io/file_effect/write-handle*/
  kk_vector_t _x_x1030 = kk_vector_unbox(_b_x358, _ctx); /*vector<int8>*/
  _x_x1028 = kk_function_call(kk_integer_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_nagare_io_file__effect__write_handle, kk_vector_t, kk_context_t*), _b_x354_367, (_b_x354_367, _b_x355, _b_x356, _x_x1029, _x_x1030, _ctx), _ctx); /*int*/
  return kk_integer_box(_x_x1028, _ctx);
}


// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileWrite_fun1031__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_io_file__effect_defaultFileWrite_fun1031(kk_function_t _fself, kk_box_t _res, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileWrite_fun1031(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file__effect_defaultFileWrite_fun1031, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_io_file__effect_defaultFileWrite_fun1031(kk_function_t _fself, kk_box_t _res, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return _res;
}

kk_box_t kk_nagare_io_file__effect_defaultFileWrite(kk_function_t action, kk_context_t* _ctx) { /* forall<a> (action : () -> <fileWrite|io> a) -> io a */ 
  kk_function_t _b_x331_359 = kk_nagare_io_file__effect_new_defaultFileWrite_fun995(_ctx); /*(h : nagare/io/file_effect/write-handle) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> ()*/;
  kk_function_t _b_x335_360 = kk_nagare_io_file__effect_new_defaultFileWrite_fun997(_ctx); /*(p : string) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> nagare/io/file_effect/write-handle*/;
  kk_function_t _b_x343_362 = kk_nagare_io_file__effect_new_defaultFileWrite_fun1002(_ctx); /*(m : hnd/marker<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>,2606>, ev : hnd/ev<nagare/io/file_effect/fileWrite>, x1@0 : nagare/io/file_effect/write-handle, x2 : string) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> int*/;
  kk_function_t _b_x354_367 = kk_nagare_io_file__effect_new_defaultFileWrite_fun1007(_ctx); /*(m@0 : hnd/marker<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>,2606>, ev@0 : hnd/ev<nagare/io/file_effect/fileWrite>, x1@2 : nagare/io/file_effect/write-handle, x2@0 : vector<int8>) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> int*/;
  kk_nagare_io_file__effect__fileWrite _x_x1012;
  kk_std_core_hnd__clause1 _x_x1013 = kk_std_core_hnd_clause_tail1(kk_nagare_io_file__effect_new_defaultFileWrite_fun1014(_b_x331_359, _ctx), _ctx); /*hnd/clause1<10003,10004,10002,10000,10001>*/
  kk_std_core_hnd__clause1 _x_x1017 = kk_std_core_hnd_clause_tail1(kk_nagare_io_file__effect_new_defaultFileWrite_fun1018(_b_x335_360, _ctx), _ctx); /*hnd/clause1<10003,10004,10002,10000,10001>*/
  kk_std_core_hnd__clause2 _x_x1021 = kk_std_core_hnd__new_Clause2(kk_nagare_io_file__effect_new_defaultFileWrite_fun1022(_b_x343_362, _ctx), _ctx); /*hnd/clause2<10021,10022,10023,10024,10025,10026>*/
  kk_std_core_hnd__clause2 _x_x1026 = kk_std_core_hnd__new_Clause2(kk_nagare_io_file__effect_new_defaultFileWrite_fun1027(_b_x354_367, _ctx), _ctx); /*hnd/clause2<10021,10022,10023,10024,10025,10026>*/
  _x_x1012 = kk_nagare_io_file__effect__new_Hnd_fileWrite(kk_reuse_null, 0, kk_integer_from_small(1), _x_x1013, _x_x1017, _x_x1021, _x_x1026, _ctx); /*nagare/io/file_effect/fileWrite<81,82>*/
  return kk_nagare_io_file__effect_fileWrite_fs__handle(_x_x1012, kk_nagare_io_file__effect_new_defaultFileWrite_fun1031(_ctx), action, _ctx);
}
 
// lifted local: @lift-defaultFileSystem@10193, defaultFileSystem, @spec-x10126
// specialized: std/core/list/filter, on parameters @uniq-pred@10123, using:
// @uniq-pred@10123 = std/core/types/@open<(fsys :: X),<(fsys :: X),(div :: X),(exn :: (E, V) -> V)>,(dir : std/os/path/path) -> (fsys :: X) bool,(dir : std/os/path/path) -> <(fsys :: X),(div :: X),(exn :: (E, V) -> V)> bool>(std/os/dir/is-directory)


// lift anonymous function
struct kk_nagare_io_file__effect__lift_defaultFileSystem_10194_fun1032__t {
  struct kk_function_s _base;
};
static bool kk_nagare_io_file__effect__lift_defaultFileSystem_10194_fun1032(kk_function_t _fself, kk_box_t _b_x381, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect__new_lift_defaultFileSystem_10194_fun1032(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file__effect__lift_defaultFileSystem_10194_fun1032, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_nagare_io_file__effect__lift_defaultFileSystem_10194_fun1034__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_io_file__effect__lift_defaultFileSystem_10194_fun1034(kk_function_t _fself, kk_box_t _b_x378, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect__new_lift_defaultFileSystem_10194_fun1034(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file__effect__lift_defaultFileSystem_10194_fun1034, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_io_file__effect__lift_defaultFileSystem_10194_fun1034(kk_function_t _fself, kk_box_t _b_x378, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  bool _x_x1035;
  kk_std_os_path__path _x_x1036 = kk_std_os_path__path_unbox(_b_x378, KK_OWNED, _ctx); /*std/os/path/path*/
  _x_x1035 = kk_std_os_dir_is_directory(_x_x1036, _ctx); /*bool*/
  return kk_bool_box(_x_x1035);
}
static bool kk_nagare_io_file__effect__lift_defaultFileSystem_10194_fun1032(kk_function_t _fself, kk_box_t _b_x381, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_box_t _x_x1033 = kk_std_core_hnd__open_none1(kk_nagare_io_file__effect__new_lift_defaultFileSystem_10194_fun1034(_ctx), _b_x381, _ctx); /*10001*/
  return kk_bool_unbox(_x_x1033);
}

kk_std_core_types__list kk_nagare_io_file__effect__lift_defaultFileSystem_10194(kk_std_core_types__list _uniq_xs_10122, kk_context_t* _ctx) { /* (list<std/os/path/path>) -> <fsys,div,exn> list<std/os/path/path> */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10122, _ctx)) {
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    return kk_std_core_list__unroll_filter_10007(_uniq_xs_10122, kk_nagare_io_file__effect__new_lift_defaultFileSystem_10194_fun1032(_ctx), _ctx);
  }
}
 
// monadic lift

kk_std_core_types__list kk_nagare_io_file__effect__mlift_trmc_lift_defaultFileSystem_10196_10397(kk_std_core_types__cctx _acc, kk_std_core_types__optional _uniq_max_depth_10103, kk_std_core_types__list _uniq_zz_10139, kk_std_core_types__list _uniq_ys_1_10132_10140, kk_context_t* _ctx) { /* (ctx<list<std/os/path/path>>, ? int, list<std/os/path/path>, list<std/os/path/path>) -> <pure,fsys> list<std/os/path/path> */ 
  return kk_nagare_io_file__effect__trmc_lift_defaultFileSystem_10196(_uniq_max_depth_10103, _uniq_ys_1_10132_10140, _uniq_zz_10139, _acc, _ctx);
}
 
// lifted local: @lift-defaultFileSystem@10195, @lift-defaultFileSystem@10193, defaultFileSystem, @spec-x10142
// specialized: std/core/list/@lift-flatmap@6013, on parameters @uniq-f@10130, using:
// @uniq-f@10130 = fn<<(div :: X),(exn :: (E, V) -> V),(fsys :: X)>>(@uniq-sub@10115: std/os/path/path){
//   std/os/dir/list-directory-recursive(@uniq-sub@10115, (std/core/types/@Optional<int>((std/core/types/@open<(total :: E),<(div :: X),(exn :: (E, V) -> V),(fsys :: X)>,(x : int, y : int) -> int,(x : int, y : int) -> <(div :: X),(exn :: (E, V) -> V),(fsys :: X)> int>((fn(@uniq-x@10116: int, @uniq-y@10117: int){
//       (std/core/int/int-sub(@uniq-x@10116, @uniq-y@10117));
//     }))((match (@uniq-max-depth@10103) {
//         ((std/core/types/@Optional((@uniq-uniq-max-depth@509@10119: int) : int) : ? int ) as @uniq-pat@10118: ? int)
//            -> @uniq-uniq-max-depth@509@10119;
//         ((@skip std/core/types/@None() : ? int ) as @uniq-pat@0@10120: ? int)
//            -> 1000;
//       }), 1)))));
// }


// lift anonymous function
struct kk_nagare_io_file__effect__trmc_lift_defaultFileSystem_10196_fun1043__t {
  struct kk_function_s _base;
  kk_std_core_types__cctx _acc_0;
  kk_std_core_types__optional _uniq_max_depth_10103_0;
  kk_std_core_types__list _uniq_zz_10139_0;
};
static kk_box_t kk_nagare_io_file__effect__trmc_lift_defaultFileSystem_10196_fun1043(kk_function_t _fself, kk_box_t _b_x403, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect__new_trmc_lift_defaultFileSystem_10196_fun1043(kk_std_core_types__cctx _acc_0, kk_std_core_types__optional _uniq_max_depth_10103_0, kk_std_core_types__list _uniq_zz_10139_0, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect__trmc_lift_defaultFileSystem_10196_fun1043__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect__trmc_lift_defaultFileSystem_10196_fun1043__t, 6, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect__trmc_lift_defaultFileSystem_10196_fun1043, kk_context());
  _self->_acc_0 = _acc_0;
  _self->_uniq_max_depth_10103_0 = _uniq_max_depth_10103_0;
  _self->_uniq_zz_10139_0 = _uniq_zz_10139_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file__effect__trmc_lift_defaultFileSystem_10196_fun1043(kk_function_t _fself, kk_box_t _b_x403, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect__trmc_lift_defaultFileSystem_10196_fun1043__t* _self = kk_function_as(struct kk_nagare_io_file__effect__trmc_lift_defaultFileSystem_10196_fun1043__t*, _fself, _ctx);
  kk_std_core_types__cctx _acc_0 = _self->_acc_0; /* ctx<list<std/os/path/path>> */
  kk_std_core_types__optional _uniq_max_depth_10103_0 = _self->_uniq_max_depth_10103_0; /* ? int */
  kk_std_core_types__list _uniq_zz_10139_0 = _self->_uniq_zz_10139_0; /* list<std/os/path/path> */
  kk_drop_match(_self, {kk_std_core_types__cctx_dup(_acc_0, _ctx);kk_std_core_types__optional_dup(_uniq_max_depth_10103_0, _ctx);kk_std_core_types__list_dup(_uniq_zz_10139_0, _ctx);}, {}, _ctx)
  kk_std_core_types__list _uniq_ys_1_10132_10140_0_415 = kk_std_core_types__list_unbox(_b_x403, KK_OWNED, _ctx); /*list<std/os/path/path>*/;
  kk_std_core_types__list _x_x1044 = kk_nagare_io_file__effect__mlift_trmc_lift_defaultFileSystem_10196_10397(_acc_0, _uniq_max_depth_10103_0, _uniq_zz_10139_0, _uniq_ys_1_10132_10140_0_415, _ctx); /*list<std/os/path/path>*/
  return kk_std_core_types__list_box(_x_x1044, _ctx);
}

kk_std_core_types__list kk_nagare_io_file__effect__trmc_lift_defaultFileSystem_10196(kk_std_core_types__optional _uniq_max_depth_10103_0, kk_std_core_types__list _uniq_ys_10131, kk_std_core_types__list _uniq_zs_10132, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx) { /* (? int, list<std/os/path/path>, list<std/os/path/path>, ctx<list<std/os/path/path>>) -> <div,exn,fsys> list<std/os/path/path> */ 
  kk__tailcall: ;
  if (kk_std_core_types__is_Cons(_uniq_ys_10131, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1037 = kk_std_core_types__as_Cons(_uniq_ys_10131, _ctx);
    kk_box_t _box_x387 = _con_x1037->head;
    kk_std_core_types__list _uniq_yy_10135 = _con_x1037->tail;
    kk_std_os_path__path _uniq_y_10134 = kk_std_os_path__path_unbox(_box_x387, KK_BORROWED, _ctx);
    kk_reuse_t _ru_x804 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_ys_10131, _ctx)) {
      kk_std_os_path__path_dup(_uniq_y_10134, _ctx);
      kk_box_drop(_box_x387, _ctx);
      _ru_x804 = (kk_datatype_ptr_reuse(_uniq_ys_10131, _ctx));
    }
    else {
      kk_std_os_path__path_dup(_uniq_y_10134, _ctx);
      kk_std_core_types__list_dup(_uniq_yy_10135, _ctx);
      kk_datatype_ptr_decref(_uniq_ys_10131, _ctx);
    }
    kk_std_core_types__list _trmc_x10206 = kk_datatype_null(); /*list<std/os/path/path>*/;
    kk_std_core_types__list _trmc_x10207 = kk_std_core_types__new_Cons(_ru_x804, 0, kk_std_os_path__path_box(_uniq_y_10134, _ctx), _trmc_x10206, _ctx); /*list<std/os/path/path>*/;
    kk_field_addr_t _b_x397_408 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10207, _ctx)->tail, _ctx); /*@field-addr<list<std/os/path/path>>*/;
    { // tailcall
      kk_std_core_types__cctx _x_x1038 = kk_cctx_extend_linear(_acc_0,(kk_std_core_types__list_box(_trmc_x10207, _ctx)),_b_x397_408,kk_context()); /*ctx<0>*/
      _uniq_ys_10131 = _uniq_yy_10135;
      _acc_0 = _x_x1038;
      goto kk__tailcall;
    }
  }
  if (kk_std_core_types__is_Cons(_uniq_zs_10132, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1039 = kk_std_core_types__as_Cons(_uniq_zs_10132, _ctx);
    kk_box_t _box_x398 = _con_x1039->head;
    kk_std_core_types__list _uniq_zz_10139_0 = _con_x1039->tail;
    kk_std_os_path__path _uniq_z_10138 = kk_std_os_path__path_unbox(_box_x398, KK_BORROWED, _ctx);
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_zs_10132, _ctx)) {
      kk_std_os_path__path_dup(_uniq_z_10138, _ctx);
      kk_box_drop(_box_x398, _ctx);
      kk_datatype_ptr_free(_uniq_zs_10132, _ctx);
    }
    else {
      kk_std_os_path__path_dup(_uniq_z_10138, _ctx);
      kk_std_core_types__list_dup(_uniq_zz_10139_0, _ctx);
      kk_datatype_ptr_decref(_uniq_zs_10132, _ctx);
    }
    kk_integer_t _b_x400_401;
    kk_integer_t _x_x1040;
    if (kk_std_core_types__is_Optional(_uniq_max_depth_10103_0, _ctx)) {
      kk_box_t _box_x399 = _uniq_max_depth_10103_0._cons._Optional.value;
      kk_integer_t _uniq_uniq_max_depth_509_10119 = kk_integer_unbox(_box_x399, _ctx);
      kk_integer_dup(_uniq_uniq_max_depth_509_10119, _ctx);
      _x_x1040 = _uniq_uniq_max_depth_509_10119; /*int*/
    }
    else {
      _x_x1040 = kk_integer_from_small(1000); /*int*/
    }
    _b_x400_401 = kk_integer_add_small_const(_x_x1040, -1, _ctx); /*int*/
    kk_std_core_types__list x_10518;
    kk_std_core_types__optional _x_x1041 = kk_std_core_types__new_Optional(kk_integer_box(_b_x400_401, _ctx), _ctx); /*? 10003*/
    x_10518 = kk_std_os_dir_list_directory_recursive(_uniq_z_10138, _x_x1041, _ctx); /*list<std/os/path/path>*/
    if (kk_yielding(kk_context())) {
      kk_std_core_types__list_drop(x_10518, _ctx);
      kk_box_t _x_x1042 = kk_std_core_hnd_yield_extend(kk_nagare_io_file__effect__new_trmc_lift_defaultFileSystem_10196_fun1043(_acc_0, _uniq_max_depth_10103_0, _uniq_zz_10139_0, _ctx), _ctx); /*10001*/
      return kk_std_core_types__list_unbox(_x_x1042, KK_OWNED, _ctx);
    }
    { // tailcall
      _uniq_ys_10131 = x_10518;
      _uniq_zs_10132 = _uniq_zz_10139_0;
      goto kk__tailcall;
    }
  }
  {
    kk_std_core_types__optional_drop(_uniq_max_depth_10103_0, _ctx);
    kk_box_t _x_x1045 = kk_cctx_apply_linear(_acc_0,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1045, KK_OWNED, _ctx);
  }
}
 
// lifted local: @lift-defaultFileSystem@10195, @lift-defaultFileSystem@10193, defaultFileSystem, @spec-x10142
// specialized: std/core/list/@lift-flatmap@6013, on parameters @uniq-f@10130, using:
// @uniq-f@10130 = fn<<(div :: X),(exn :: (E, V) -> V),(fsys :: X)>>(@uniq-sub@10115: std/os/path/path){
//   std/os/dir/list-directory-recursive(@uniq-sub@10115, (std/core/types/@Optional<int>((std/core/types/@open<(total :: E),<(div :: X),(exn :: (E, V) -> V),(fsys :: X)>,(x : int, y : int) -> int,(x : int, y : int) -> <(div :: X),(exn :: (E, V) -> V),(fsys :: X)> int>((fn(@uniq-x@10116: int, @uniq-y@10117: int){
//       (std/core/int/int-sub(@uniq-x@10116, @uniq-y@10117));
//     }))((match (@uniq-max-depth@10103) {
//         ((std/core/types/@Optional((@uniq-uniq-max-depth@509@10119: int) : int) : ? int ) as @uniq-pat@10118: ? int)
//            -> @uniq-uniq-max-depth@509@10119;
//         ((@skip std/core/types/@None() : ? int ) as @uniq-pat@0@10120: ? int)
//            -> 1000;
//       }), 1)))));
// }

kk_std_core_types__list kk_nagare_io_file__effect__lift_defaultFileSystem_10196(kk_std_core_types__optional _uniq_max_depth_10103_1, kk_std_core_types__list _uniq_ys_10131_0, kk_std_core_types__list _uniq_zs_10132_0, kk_context_t* _ctx) { /* (? int, list<std/os/path/path>, list<std/os/path/path>) -> <div,exn,fsys> list<std/os/path/path> */ 
  kk_std_core_types__cctx _x_x1046 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_nagare_io_file__effect__trmc_lift_defaultFileSystem_10196(_uniq_max_depth_10103_1, _uniq_ys_10131_0, _uniq_zs_10132_0, _x_x1046, _ctx);
}
 
// lifted local: @lift-defaultFileSystem@10193, defaultFileSystem, @spec-x10129
// specialized: std/core/list/flatmap, on parameters @uniq-f@10128, using:
// @uniq-f@10128 = fn<<(div :: X),(exn :: (E, V) -> V),(fsys :: X)>>(@uniq-sub@10115: std/os/path/path){
//   std/os/dir/list-directory-recursive(@uniq-sub@10115, (std/core/types/@Optional<int>((std/core/types/@open<(total :: E),<(div :: X),(exn :: (E, V) -> V),(fsys :: X)>,(x : int, y : int) -> int,(x : int, y : int) -> <(div :: X),(exn :: (E, V) -> V),(fsys :: X)> int>((fn(@uniq-x@10116: int, @uniq-y@10117: int){
//       (std/core/int/int-sub(@uniq-x@10116, @uniq-y@10117));
//     }))((match (@uniq-max-depth@10103) {
//         ((std/core/types/@Optional((@uniq-uniq-max-depth@509@10119: int) : int) : ? int ) as @uniq-pat@10118: ? int)
//            -> @uniq-uniq-max-depth@509@10119;
//         ((@skip std/core/types/@None() : ? int ) as @uniq-pat@0@10120: ? int)
//            -> 1000;
//       }), 1)))));
// }

kk_std_core_types__list kk_nagare_io_file__effect__lift_defaultFileSystem_10195(kk_std_core_types__optional _uniq_max_depth_10103, kk_std_core_types__list _uniq_xs_10127, kk_context_t* _ctx) { /* (? int, list<std/os/path/path>) -> <div,exn,fsys> list<std/os/path/path> */ 
  kk_std_core_types__cctx _x_x1047 = kk_cctx_empty(kk_context()); /*ctx<0>*/
  return kk_nagare_io_file__effect__trmc_lift_defaultFileSystem_10196(_uniq_max_depth_10103, kk_std_core_types__new_Nil(_ctx), _uniq_xs_10127, _x_x1047, _ctx);
}
 
// monadic lift

kk_std_core_types__list kk_nagare_io_file__effect__mlift_lift_defaultFileSystem_10193_10398(kk_std_core_types__list _uniq_all_10109, kk_std_core_types__list _y_x10268, kk_context_t* _ctx) { /* (list<std/os/path/path>, list<std/os/path/path>) -> <div,exn,fsys> list<std/os/path/path> */ 
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<div,exn,fsys>>*/;
  kk_std_core_types__list x;
  if (kk_std_core_types__is_Nil(_uniq_all_10109, _ctx)) {
    x = _y_x10268; /*list<std/os/path/path>*/
  }
  else {
    x = kk_std_core_list__unroll_append_10004(_uniq_all_10109, _y_x10268, _ctx); /*list<std/os/path/path>*/
  }
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  return x;
}
 
// monadic lift


// lift anonymous function
struct kk_nagare_io_file__effect__mlift_lift_defaultFileSystem_10193_10399_fun1049__t {
  struct kk_function_s _base;
  kk_std_core_types__list _uniq_all_10109_0;
};
static kk_box_t kk_nagare_io_file__effect__mlift_lift_defaultFileSystem_10193_10399_fun1049(kk_function_t _fself, kk_box_t _b_x417, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect__new_mlift_lift_defaultFileSystem_10193_10399_fun1049(kk_std_core_types__list _uniq_all_10109_0, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect__mlift_lift_defaultFileSystem_10193_10399_fun1049__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect__mlift_lift_defaultFileSystem_10193_10399_fun1049__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect__mlift_lift_defaultFileSystem_10193_10399_fun1049, kk_context());
  _self->_uniq_all_10109_0 = _uniq_all_10109_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file__effect__mlift_lift_defaultFileSystem_10193_10399_fun1049(kk_function_t _fself, kk_box_t _b_x417, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect__mlift_lift_defaultFileSystem_10193_10399_fun1049__t* _self = kk_function_as(struct kk_nagare_io_file__effect__mlift_lift_defaultFileSystem_10193_10399_fun1049__t*, _fself, _ctx);
  kk_std_core_types__list _uniq_all_10109_0 = _self->_uniq_all_10109_0; /* list<std/os/path/path> */
  kk_drop_match(_self, {kk_std_core_types__list_dup(_uniq_all_10109_0, _ctx);}, {}, _ctx)
  kk_std_core_types__list _y_x10268_0_419 = kk_std_core_types__list_unbox(_b_x417, KK_OWNED, _ctx); /*list<std/os/path/path>*/;
  kk_std_core_types__list _x_x1050 = kk_nagare_io_file__effect__mlift_lift_defaultFileSystem_10193_10398(_uniq_all_10109_0, _y_x10268_0_419, _ctx); /*list<std/os/path/path>*/
  return kk_std_core_types__list_box(_x_x1050, _ctx);
}

kk_std_core_types__list kk_nagare_io_file__effect__mlift_lift_defaultFileSystem_10193_10399(kk_std_core_types__list _uniq_all_10109_0, kk_std_core_types__optional _uniq_max_depth_10103, kk_std_core_types__list _uniq_dirs_10110, kk_context_t* _ctx) { /* (list<std/os/path/path>, ? int, list<std/os/path/path>) -> <fsys,div,exn> list<std/os/path/path> */ 
  kk_std_core_types__list x_0_10527 = kk_nagare_io_file__effect__lift_defaultFileSystem_10195(_uniq_max_depth_10103, _uniq_dirs_10110, _ctx); /*list<std/os/path/path>*/;
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_0_10527, _ctx);
    kk_box_t _x_x1048 = kk_std_core_hnd_yield_extend(kk_nagare_io_file__effect__new_mlift_lift_defaultFileSystem_10193_10399_fun1049(_uniq_all_10109_0, _ctx), _ctx); /*10001*/
    return kk_std_core_types__list_unbox(_x_x1048, KK_OWNED, _ctx);
  }
  {
    return kk_nagare_io_file__effect__mlift_lift_defaultFileSystem_10193_10398(_uniq_all_10109_0, x_0_10527, _ctx);
  }
}
 
// monadic lift


// lift anonymous function
struct kk_nagare_io_file__effect__mlift_lift_defaultFileSystem_10193_10400_fun1053__t {
  struct kk_function_s _base;
  kk_std_core_types__list _uniq_all_10109_1;
  kk_std_core_types__optional _uniq_max_depth_10103_0;
};
static kk_box_t kk_nagare_io_file__effect__mlift_lift_defaultFileSystem_10193_10400_fun1053(kk_function_t _fself, kk_box_t _b_x421, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect__new_mlift_lift_defaultFileSystem_10193_10400_fun1053(kk_std_core_types__list _uniq_all_10109_1, kk_std_core_types__optional _uniq_max_depth_10103_0, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect__mlift_lift_defaultFileSystem_10193_10400_fun1053__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect__mlift_lift_defaultFileSystem_10193_10400_fun1053__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect__mlift_lift_defaultFileSystem_10193_10400_fun1053, kk_context());
  _self->_uniq_all_10109_1 = _uniq_all_10109_1;
  _self->_uniq_max_depth_10103_0 = _uniq_max_depth_10103_0;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file__effect__mlift_lift_defaultFileSystem_10193_10400_fun1053(kk_function_t _fself, kk_box_t _b_x421, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect__mlift_lift_defaultFileSystem_10193_10400_fun1053__t* _self = kk_function_as(struct kk_nagare_io_file__effect__mlift_lift_defaultFileSystem_10193_10400_fun1053__t*, _fself, _ctx);
  kk_std_core_types__list _uniq_all_10109_1 = _self->_uniq_all_10109_1; /* list<std/os/path/path> */
  kk_std_core_types__optional _uniq_max_depth_10103_0 = _self->_uniq_max_depth_10103_0; /* ? int */
  kk_drop_match(_self, {kk_std_core_types__list_dup(_uniq_all_10109_1, _ctx);kk_std_core_types__optional_dup(_uniq_max_depth_10103_0, _ctx);}, {}, _ctx)
  kk_std_core_types__list _uniq_dirs_10110_0_423 = kk_std_core_types__list_unbox(_b_x421, KK_OWNED, _ctx); /*list<std/os/path/path>*/;
  kk_std_core_types__list _x_x1054 = kk_nagare_io_file__effect__mlift_lift_defaultFileSystem_10193_10399(_uniq_all_10109_1, _uniq_max_depth_10103_0, _uniq_dirs_10110_0_423, _ctx); /*list<std/os/path/path>*/
  return kk_std_core_types__list_box(_x_x1054, _ctx);
}

kk_std_core_types__list kk_nagare_io_file__effect__mlift_lift_defaultFileSystem_10193_10400(kk_std_core_types__optional _uniq_max_depth_10103_0, kk_std_core_types__list _uniq_all_10109_1, kk_context_t* _ctx) { /* (? int, list<std/os/path/path>) -> <exn,fsys> list<std/os/path/path> */ 
  kk_std_core_types__list x_1_10529;
  kk_std_core_types__list _x_x1051 = kk_std_core_types__list_dup(_uniq_all_10109_1, _ctx); /*list<std/os/path/path>*/
  x_1_10529 = kk_nagare_io_file__effect__lift_defaultFileSystem_10194(_x_x1051, _ctx); /*list<std/os/path/path>*/
  if (kk_yielding(kk_context())) {
    kk_std_core_types__list_drop(x_1_10529, _ctx);
    kk_box_t _x_x1052 = kk_std_core_hnd_yield_extend(kk_nagare_io_file__effect__new_mlift_lift_defaultFileSystem_10193_10400_fun1053(_uniq_all_10109_1, _uniq_max_depth_10103_0, _ctx), _ctx); /*10001*/
    return kk_std_core_types__list_unbox(_x_x1052, KK_OWNED, _ctx);
  }
  {
    return kk_nagare_io_file__effect__mlift_lift_defaultFileSystem_10193_10399(_uniq_all_10109_1, _uniq_max_depth_10103_0, x_1_10529, _ctx);
  }
}
 
// lifted local: defaultFileSystem, @spec-x10121
// specialized: std/os/dir/list-directory-recursive, on parameters @uniq-dir@10102, using:
// @uniq-dir@10102 = std/core/types/@open<(total :: E),<(div :: X),(exn :: (E, V) -> V),(fsys :: X),(alloc :: H -> X)<(global :: H)>,(console/console :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>>,(s : string) -> std/os/path/path,(s : string) -> <(div :: X),(exn :: (E, V) -> V),(fsys :: X),(alloc :: H -> X)<(global :: H)>,(console/console :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>> std/os/path/path>(std/os/path/path)(p@0)


// lift anonymous function
struct kk_nagare_io_file__effect__lift_defaultFileSystem_10193_fun1056__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_io_file__effect__lift_defaultFileSystem_10193_fun1056(kk_function_t _fself, kk_box_t _b_x426, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect__new_lift_defaultFileSystem_10193_fun1056(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file__effect__lift_defaultFileSystem_10193_fun1056, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_io_file__effect__lift_defaultFileSystem_10193_fun1056(kk_function_t _fself, kk_box_t _b_x426, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_os_path__path _x_x1057;
  kk_string_t _x_x1058 = kk_string_unbox(_b_x426); /*string*/
  _x_x1057 = kk_std_os_path_path(_x_x1058, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x_x1057, _ctx);
}


// lift anonymous function
struct kk_nagare_io_file__effect__lift_defaultFileSystem_10193_fun1060__t {
  struct kk_function_s _base;
  kk_std_core_types__optional _uniq_max_depth_10103_1;
};
static kk_box_t kk_nagare_io_file__effect__lift_defaultFileSystem_10193_fun1060(kk_function_t _fself, kk_box_t _b_x431, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect__new_lift_defaultFileSystem_10193_fun1060(kk_std_core_types__optional _uniq_max_depth_10103_1, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect__lift_defaultFileSystem_10193_fun1060__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect__lift_defaultFileSystem_10193_fun1060__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect__lift_defaultFileSystem_10193_fun1060, kk_context());
  _self->_uniq_max_depth_10103_1 = _uniq_max_depth_10103_1;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file__effect__lift_defaultFileSystem_10193_fun1060(kk_function_t _fself, kk_box_t _b_x431, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect__lift_defaultFileSystem_10193_fun1060__t* _self = kk_function_as(struct kk_nagare_io_file__effect__lift_defaultFileSystem_10193_fun1060__t*, _fself, _ctx);
  kk_std_core_types__optional _uniq_max_depth_10103_1 = _self->_uniq_max_depth_10103_1; /* ? int */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(_uniq_max_depth_10103_1, _ctx);}, {}, _ctx)
  kk_std_core_types__list _uniq_all_10109_2_439 = kk_std_core_types__list_unbox(_b_x431, KK_OWNED, _ctx); /*list<std/os/path/path>*/;
  kk_std_core_types__list _x_x1061 = kk_nagare_io_file__effect__mlift_lift_defaultFileSystem_10193_10400(_uniq_max_depth_10103_1, _uniq_all_10109_2_439, _ctx); /*list<std/os/path/path>*/
  return kk_std_core_types__list_box(_x_x1061, _ctx);
}


// lift anonymous function
struct kk_nagare_io_file__effect__lift_defaultFileSystem_10193_fun1064__t {
  struct kk_function_s _base;
  kk_std_core_types__optional _uniq_max_depth_10103_1;
  kk_std_core_types__list x_2_10531;
};
static kk_box_t kk_nagare_io_file__effect__lift_defaultFileSystem_10193_fun1064(kk_function_t _fself, kk_box_t _b_x433, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect__new_lift_defaultFileSystem_10193_fun1064(kk_std_core_types__optional _uniq_max_depth_10103_1, kk_std_core_types__list x_2_10531, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect__lift_defaultFileSystem_10193_fun1064__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect__lift_defaultFileSystem_10193_fun1064__t, 4, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect__lift_defaultFileSystem_10193_fun1064, kk_context());
  _self->_uniq_max_depth_10103_1 = _uniq_max_depth_10103_1;
  _self->x_2_10531 = x_2_10531;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file__effect__lift_defaultFileSystem_10193_fun1064(kk_function_t _fself, kk_box_t _b_x433, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect__lift_defaultFileSystem_10193_fun1064__t* _self = kk_function_as(struct kk_nagare_io_file__effect__lift_defaultFileSystem_10193_fun1064__t*, _fself, _ctx);
  kk_std_core_types__optional _uniq_max_depth_10103_1 = _self->_uniq_max_depth_10103_1; /* ? int */
  kk_std_core_types__list x_2_10531 = _self->x_2_10531; /* list<std/os/path/path> */
  kk_drop_match(_self, {kk_std_core_types__optional_dup(_uniq_max_depth_10103_1, _ctx);kk_std_core_types__list_dup(x_2_10531, _ctx);}, {}, _ctx)
  kk_std_core_types__list _uniq_dirs_10110_1_440 = kk_std_core_types__list_unbox(_b_x433, KK_OWNED, _ctx); /*list<std/os/path/path>*/;
  kk_std_core_types__list _x_x1065 = kk_nagare_io_file__effect__mlift_lift_defaultFileSystem_10193_10399(x_2_10531, _uniq_max_depth_10103_1, _uniq_dirs_10110_1_440, _ctx); /*list<std/os/path/path>*/
  return kk_std_core_types__list_box(_x_x1065, _ctx);
}


// lift anonymous function
struct kk_nagare_io_file__effect__lift_defaultFileSystem_10193_fun1067__t {
  struct kk_function_s _base;
  kk_std_core_types__list x_2_10531;
};
static kk_box_t kk_nagare_io_file__effect__lift_defaultFileSystem_10193_fun1067(kk_function_t _fself, kk_box_t _b_x435, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect__new_lift_defaultFileSystem_10193_fun1067(kk_std_core_types__list x_2_10531, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect__lift_defaultFileSystem_10193_fun1067__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect__lift_defaultFileSystem_10193_fun1067__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect__lift_defaultFileSystem_10193_fun1067, kk_context());
  _self->x_2_10531 = x_2_10531;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file__effect__lift_defaultFileSystem_10193_fun1067(kk_function_t _fself, kk_box_t _b_x435, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect__lift_defaultFileSystem_10193_fun1067__t* _self = kk_function_as(struct kk_nagare_io_file__effect__lift_defaultFileSystem_10193_fun1067__t*, _fself, _ctx);
  kk_std_core_types__list x_2_10531 = _self->x_2_10531; /* list<std/os/path/path> */
  kk_drop_match(_self, {kk_std_core_types__list_dup(x_2_10531, _ctx);}, {}, _ctx)
  kk_std_core_types__list _y_x10268_1_441 = kk_std_core_types__list_unbox(_b_x435, KK_OWNED, _ctx); /*list<std/os/path/path>*/;
  kk_std_core_types__list _x_x1068 = kk_nagare_io_file__effect__mlift_lift_defaultFileSystem_10193_10398(x_2_10531, _y_x10268_1_441, _ctx); /*list<std/os/path/path>*/
  return kk_std_core_types__list_box(_x_x1068, _ctx);
}

kk_std_core_types__list kk_nagare_io_file__effect__lift_defaultFileSystem_10193(kk_string_t p_0, kk_std_core_types__optional _uniq_max_depth_10103_1, kk_context_t* _ctx) { /* (p@0 : string, ? int) -> <fsys,pure> list<std/os/path/path> */ 
  kk_std_os_path__path _uniq_dir_10102;
  kk_box_t _x_x1055 = kk_std_core_hnd__open_none1(kk_nagare_io_file__effect__new_lift_defaultFileSystem_10193_fun1056(_ctx), kk_string_box(p_0), _ctx); /*10001*/
  _uniq_dir_10102 = kk_std_os_path__path_unbox(_x_x1055, KK_OWNED, _ctx); /*std/os/path/path*/
  bool _match_x767;
  kk_integer_t _brw_x771;
  if (kk_std_core_types__is_Optional(_uniq_max_depth_10103_1, _ctx)) {
    kk_box_t _box_x429 = _uniq_max_depth_10103_1._cons._Optional.value;
    kk_integer_t _uniq_uniq_max_depth_509_10105 = kk_integer_unbox(_box_x429, _ctx);
    kk_integer_dup(_uniq_uniq_max_depth_509_10105, _ctx);
    _brw_x771 = _uniq_uniq_max_depth_509_10105; /*int*/
  }
  else {
    _brw_x771 = kk_integer_from_small(1000); /*int*/
  }
  bool _brw_x772 = kk_integer_lt_borrow(_brw_x771,(kk_integer_from_small(0)),kk_context()); /*bool*/;
  kk_integer_drop(_brw_x771, _ctx);
  _match_x767 = _brw_x772; /*bool*/
  if (_match_x767) {
    kk_std_core_types__optional_drop(_uniq_max_depth_10103_1, _ctx);
    kk_std_os_path__path_drop(_uniq_dir_10102, _ctx);
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    kk_std_core_types__list x_2_10531 = kk_std_os_dir_list_directory(_uniq_dir_10102, _ctx); /*list<std/os/path/path>*/;
    if (kk_yielding(kk_context())) {
      kk_std_core_types__list_drop(x_2_10531, _ctx);
      kk_box_t _x_x1059 = kk_std_core_hnd_yield_extend(kk_nagare_io_file__effect__new_lift_defaultFileSystem_10193_fun1060(_uniq_max_depth_10103_1, _ctx), _ctx); /*10001*/
      return kk_std_core_types__list_unbox(_x_x1059, KK_OWNED, _ctx);
    }
    {
      kk_std_core_types__list x_3_10534;
      kk_std_core_types__list _x_x1062 = kk_std_core_types__list_dup(x_2_10531, _ctx); /*list<std/os/path/path>*/
      x_3_10534 = kk_nagare_io_file__effect__lift_defaultFileSystem_10194(_x_x1062, _ctx); /*list<std/os/path/path>*/
      if (kk_yielding(kk_context())) {
        kk_std_core_types__list_drop(x_3_10534, _ctx);
        kk_box_t _x_x1063 = kk_std_core_hnd_yield_extend(kk_nagare_io_file__effect__new_lift_defaultFileSystem_10193_fun1064(_uniq_max_depth_10103_1, x_2_10531, _ctx), _ctx); /*10001*/
        return kk_std_core_types__list_unbox(_x_x1063, KK_OWNED, _ctx);
      }
      {
        kk_std_core_types__list x_4_10537 = kk_nagare_io_file__effect__lift_defaultFileSystem_10195(_uniq_max_depth_10103_1, x_3_10534, _ctx); /*list<std/os/path/path>*/;
        if (kk_yielding(kk_context())) {
          kk_std_core_types__list_drop(x_4_10537, _ctx);
          kk_box_t _x_x1066 = kk_std_core_hnd_yield_extend(kk_nagare_io_file__effect__new_lift_defaultFileSystem_10193_fun1067(x_2_10531, _ctx), _ctx); /*10001*/
          return kk_std_core_types__list_unbox(_x_x1066, KK_OWNED, _ctx);
        }
        {
          kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<div,exn,fsys>>*/;
          kk_std_core_types__list x_5;
          if (kk_std_core_types__is_Nil(x_2_10531, _ctx)) {
            x_5 = x_4_10537; /*list<std/os/path/path>*/
          }
          else {
            x_5 = kk_std_core_list__unroll_append_10004(x_2_10531, x_4_10537, _ctx); /*list<std/os/path/path>*/
          }
          kk_unit_t keep_0 = kk_Unit;
          kk_evv_set(w_0,kk_context());
          return x_5;
        }
      }
    }
  }
}
 
// lifted local: @lift-defaultFileSystem@10198, @lift-defaultFileSystem@10197, defaultFileSystem, @spec-x10191
// specialized: std/core/list/@unroll-map@10010, on parameters @uniq-f@10186, using:
// @uniq-f@10186 = fn<<(exn :: (E, V) -> V),(fsys :: X)>>(@uniq-name@10152: string){
//   std/core/types/@open<(total :: E),<(exn :: (E, V) -> V),(fsys :: X)>,(p1 : std/os/path/path, p2 : std/os/path/path) -> std/os/path/path,(p1 : std/os/path/path, p2 : std/os/path/path) -> <(exn :: (E, V) -> V),(fsys :: X)> std/os/path/path>((fn(@uniq-p1@10153: std/os/path/path, @uniq-p2@10154: std/os/path/path){
//     val @uniq-parts@0@10093@10163 : ((list :: V -> V)<string>);
//     val @uniq-parts@10091@10172 : ? ((list :: V -> V)<string>);
//     (std/os/path/Path((match (@uniq-p1@10153) {
//         ((@skip std/os/path/Path((@uniq-x@10174: string) : string, (@uniq-pat@0@0@10175: (list :: V -> V)<string>) : (list :: V -> V)<string>) : std/os/path/path ) as @uniq-pat@3@10173: std/os/path/path)
//            -> @uniq-x@10174;
//       }), (match (@uniq-parts@10091@10172) {
//         ((std/core/types/@Optional((@uniq-uniq-parts@95@10177: (list :: V -> V)<string>) : (list :: V -> V)<string>) : ? ((list :: V -> V)<string>) ) as @uniq-pat@1@0@10176: ? ((list :: V -> V)<string>))
//            -> @uniq-uniq-parts@95@10177;
//         ((@skip std/core/types/@None() : ? ((list :: V -> V)<string>) ) as @uniq-pat@2@0@10178: ? ((list :: V -> V)<string>))
//            -> std/core/types/Nil<string>;
//       })));
//   }))(@uniq-dir@10144, (std/core/types/@open<(total :: E),<(exn :: (E, V) -> V),(fsys :: X)>,(s : string) -> std/os/path/path,(s : string) -> <(exn :: (E, V) -> V),(fsys :: X)> std/os/path/path>(std/os/path/path)(@uniq-name@10152)));
// }


// lift anonymous function
struct kk_nagare_io_file__effect__trmc_lift_defaultFileSystem_10199_fun1071__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_io_file__effect__trmc_lift_defaultFileSystem_10199_fun1071(kk_function_t _fself, kk_box_t _b_x445, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect__new_trmc_lift_defaultFileSystem_10199_fun1071(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file__effect__trmc_lift_defaultFileSystem_10199_fun1071, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_io_file__effect__trmc_lift_defaultFileSystem_10199_fun1071(kk_function_t _fself, kk_box_t _b_x445, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_os_path__path _x_x1072;
  kk_string_t _x_x1073 = kk_string_unbox(_b_x445); /*string*/
  _x_x1072 = kk_std_os_path_path(_x_x1073, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x_x1072, _ctx);
}

kk_std_core_types__list kk_nagare_io_file__effect__trmc_lift_defaultFileSystem_10199(kk_std_os_path__path _uniq_dir_10144, kk_std_core_types__list _uniq_xs_10185, kk_std_core_types__cctx _acc, kk_context_t* _ctx) { /* (std/os/path/path, list<string>, ctx<list<std/os/path/path>>) -> <exn,fsys> list<std/os/path/path> */ 
  if (kk_std_core_types__is_Cons(_uniq_xs_10185, _ctx)) {
    struct kk_std_core_types_Cons* _con_x1069 = kk_std_core_types__as_Cons(_uniq_xs_10185, _ctx);
    kk_box_t _box_x442 = _con_x1069->head;
    kk_std_core_types__list _uniq_xx_10189 = _con_x1069->tail;
    kk_string_t _uniq_x_10188 = kk_string_unbox(_box_x442);
    kk_reuse_t _ru_x806 = kk_reuse_null; /*@reuse*/;
    if kk_likely(kk_datatype_ptr_is_unique(_uniq_xs_10185, _ctx)) {
      _ru_x806 = (kk_datatype_ptr_reuse(_uniq_xs_10185, _ctx));
    }
    else {
      kk_string_dup(_uniq_x_10188, _ctx);
      kk_std_core_types__list_dup(_uniq_xx_10189, _ctx);
      kk_datatype_ptr_decref(_uniq_xs_10185, _ctx);
    }
    kk_std_os_path__path _x_x2_10361;
    kk_box_t _x_x1070 = kk_std_core_hnd__open_none1(kk_nagare_io_file__effect__new_trmc_lift_defaultFileSystem_10199_fun1071(_ctx), kk_string_box(_uniq_x_10188), _ctx); /*10001*/
    _x_x2_10361 = kk_std_os_path__path_unbox(_x_x1070, KK_OWNED, _ctx); /*std/os/path/path*/
    kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<exn,fsys>>*/;
    kk_std_core_types__list _uniq_parts_0_10093_10163;
    {
      kk_std_core_types__list _uniq_x_0_10157 = _x_x2_10361.parts;
      kk_std_core_types__list_dup(_uniq_x_0_10157, _ctx);
      if (kk_std_core_types__is_Nil(_uniq_x_0_10157, _ctx)) {
        kk_std_os_path__path_drop(_x_x2_10361, _ctx);
        _uniq_parts_0_10093_10163 = kk_std_core_types__new_Nil(_ctx); /*list<string>*/
      }
      else {
        kk_std_core_types__list_drop(_uniq_x_0_10157, _ctx);
        kk_std_core_types__list _x_x1074;
        {
          kk_std_core_types__list _uniq_x_0_0_10162 = _x_x2_10361.parts;
          kk_std_core_types__list_dup(_uniq_x_0_0_10162, _ctx);
          kk_std_os_path__path_drop(_x_x2_10361, _ctx);
          _x_x1074 = _uniq_x_0_0_10162; /*list<string>*/
        }
        _uniq_parts_0_10093_10163 = kk_std_core_list__unroll_reverse_acc_10003(kk_std_core_types__new_Nil(_ctx), _x_x1074, _ctx); /*list<string>*/
      }
    }
    kk_std_core_types__list _b_x448_449;
    if (kk_std_core_types__is_Nil(_uniq_parts_0_10093_10163, _ctx)) {
      kk_std_core_types__list _uniq_x_1_10167 = _uniq_dir_10144.parts;
      kk_std_core_types__list_dup(_uniq_x_1_10167, _ctx);
      _b_x448_449 = _uniq_x_1_10167; /*list<string>*/
    }
    else {
      kk_std_core_types__list _x_x1075;
      {
        kk_std_core_types__list _uniq_x_1_0_10171 = _uniq_dir_10144.parts;
        kk_std_core_types__list_dup(_uniq_x_1_0_10171, _ctx);
        _x_x1075 = _uniq_x_1_0_10171; /*list<string>*/
      }
      _b_x448_449 = kk_std_os_path__unroll_push_parts_10000(_uniq_parts_0_10093_10163, _x_x1075, _ctx); /*list<string>*/
    }
    kk_unit_t keep = kk_Unit;
    kk_evv_set(w,kk_context());
    kk_std_core_types__list _trmc_x10209 = kk_datatype_null(); /*list<std/os/path/path>*/;
    kk_std_core_types__list _trmc_x10210;
    kk_box_t _x_x1076;
    kk_std_os_path__path _x_x1077;
    kk_string_t _x_x1078;
    {
      kk_string_t _uniq_x_10174 = _uniq_dir_10144.root;
      kk_string_dup(_uniq_x_10174, _ctx);
      _x_x1078 = _uniq_x_10174; /*string*/
    }
    kk_std_core_types__list _x_x1079;
    kk_std_core_types__optional _match_x766 = kk_std_core_types__new_Optional(kk_std_core_types__list_box(_b_x448_449, _ctx), _ctx); /*? 10003*/;
    if (kk_std_core_types__is_Optional(_match_x766, _ctx)) {
      kk_box_t _box_x450 = _match_x766._cons._Optional.value;
      kk_std_core_types__list _uniq_uniq_parts_95_10177 = kk_std_core_types__list_unbox(_box_x450, KK_BORROWED, _ctx);
      kk_std_core_types__list_dup(_uniq_uniq_parts_95_10177, _ctx);
      kk_std_core_types__optional_drop(_match_x766, _ctx);
      _x_x1079 = _uniq_uniq_parts_95_10177; /*list<string>*/
    }
    else {
      kk_std_core_types__optional_drop(_match_x766, _ctx);
      _x_x1079 = kk_std_core_types__new_Nil(_ctx); /*list<string>*/
    }
    _x_x1077 = kk_std_os_path__new_Path(_x_x1078, _x_x1079, _ctx); /*std/os/path/path*/
    _x_x1076 = kk_std_os_path__path_box(_x_x1077, _ctx); /*10021*/
    _trmc_x10210 = kk_std_core_types__new_Cons(_ru_x806, 0, _x_x1076, _trmc_x10209, _ctx); /*list<std/os/path/path>*/
    kk_field_addr_t _b_x460_465 = kk_field_addr_create(&kk_std_core_types__as_Cons(_trmc_x10210, _ctx)->tail, _ctx); /*@field-addr<list<std/os/path/path>>*/;
    kk_std_core_types__cctx _brw_x764;
    kk_std_core_types__cctx _x_x1080 = kk_std_core_types__cctx_dup(_acc, _ctx); /*ctx<list<std/os/path/path>>*/
    _brw_x764 = kk_cctx_extend_linear(_x_x1080,(kk_std_core_types__list_box(_trmc_x10210, _ctx)),_b_x460_465,kk_context()); /*ctx<0>*/
    kk_std_core_types__list _brw_x765 = kk_nagare_io_file__effect__trmc_lift_defaultFileSystem_10199(_uniq_dir_10144, _uniq_xx_10189, _brw_x764, _ctx); /*list<std/os/path/path>*/;
    kk_std_core_types__cctx_drop(_brw_x764, _ctx);
    return _brw_x765;
  }
  {
    kk_std_os_path__path_drop(_uniq_dir_10144, _ctx);
    kk_box_t _x_x1081;
    kk_std_core_types__cctx _x_x1082 = kk_std_core_types__cctx_dup(_acc, _ctx); /*ctx<list<std/os/path/path>>*/
    _x_x1081 = kk_cctx_apply_linear(_x_x1082,(kk_std_core_types__list_box(kk_std_core_types__new_Nil(_ctx), _ctx)),kk_context()); /*-1*/
    return kk_std_core_types__list_unbox(_x_x1081, KK_OWNED, _ctx);
  }
}
 
// lifted local: @lift-defaultFileSystem@10198, @lift-defaultFileSystem@10197, defaultFileSystem, @spec-x10191
// specialized: std/core/list/@unroll-map@10010, on parameters @uniq-f@10186, using:
// @uniq-f@10186 = fn<<(exn :: (E, V) -> V),(fsys :: X)>>(@uniq-name@10152: string){
//   std/core/types/@open<(total :: E),<(exn :: (E, V) -> V),(fsys :: X)>,(p1 : std/os/path/path, p2 : std/os/path/path) -> std/os/path/path,(p1 : std/os/path/path, p2 : std/os/path/path) -> <(exn :: (E, V) -> V),(fsys :: X)> std/os/path/path>((fn(@uniq-p1@10153: std/os/path/path, @uniq-p2@10154: std/os/path/path){
//     val @uniq-parts@0@10093@10163 : ((list :: V -> V)<string>);
//     val @uniq-parts@10091@10172 : ? ((list :: V -> V)<string>);
//     (std/os/path/Path((match (@uniq-p1@10153) {
//         ((@skip std/os/path/Path((@uniq-x@10174: string) : string, (@uniq-pat@0@0@10175: (list :: V -> V)<string>) : (list :: V -> V)<string>) : std/os/path/path ) as @uniq-pat@3@10173: std/os/path/path)
//            -> @uniq-x@10174;
//       }), (match (@uniq-parts@10091@10172) {
//         ((std/core/types/@Optional((@uniq-uniq-parts@95@10177: (list :: V -> V)<string>) : (list :: V -> V)<string>) : ? ((list :: V -> V)<string>) ) as @uniq-pat@1@0@10176: ? ((list :: V -> V)<string>))
//            -> @uniq-uniq-parts@95@10177;
//         ((@skip std/core/types/@None() : ? ((list :: V -> V)<string>) ) as @uniq-pat@2@0@10178: ? ((list :: V -> V)<string>))
//            -> std/core/types/Nil<string>;
//       })));
//   }))(@uniq-dir@10144, (std/core/types/@open<(total :: E),<(exn :: (E, V) -> V),(fsys :: X)>,(s : string) -> std/os/path/path,(s : string) -> <(exn :: (E, V) -> V),(fsys :: X)> std/os/path/path>(std/os/path/path)(@uniq-name@10152)));
// }

kk_std_core_types__list kk_nagare_io_file__effect__lift_defaultFileSystem_10199(kk_std_os_path__path _uniq_dir_10144_0, kk_std_core_types__list _uniq_xs_10185_0, kk_context_t* _ctx) { /* (std/os/path/path, list<string>) -> <exn,fsys> list<std/os/path/path> */ 
  kk_std_core_types__cctx _brw_x762 = kk_cctx_empty(kk_context()); /*ctx<0>*/;
  kk_std_core_types__list _brw_x763 = kk_nagare_io_file__effect__trmc_lift_defaultFileSystem_10199(_uniq_dir_10144_0, _uniq_xs_10185_0, _brw_x762, _ctx); /*list<std/os/path/path>*/;
  kk_std_core_types__cctx_drop(_brw_x762, _ctx);
  return _brw_x763;
}
 
// lifted local: @lift-defaultFileSystem@10197, defaultFileSystem, @spec-x10184
// specialized: std/core/list/map, on parameters @uniq-f@10181, using:
// @uniq-f@10181 = fn<<(exn :: (E, V) -> V),(fsys :: X)>>(@uniq-name@10152: string){
//   std/core/types/@open<(total :: E),<(exn :: (E, V) -> V),(fsys :: X)>,(p1 : std/os/path/path, p2 : std/os/path/path) -> std/os/path/path,(p1 : std/os/path/path, p2 : std/os/path/path) -> <(exn :: (E, V) -> V),(fsys :: X)> std/os/path/path>((fn(@uniq-p1@10153: std/os/path/path, @uniq-p2@10154: std/os/path/path){
//     val @uniq-parts@0@10093@10163 : ((list :: V -> V)<string>);
//     val @uniq-parts@10091@10172 : ? ((list :: V -> V)<string>);
//     (std/os/path/Path((match (@uniq-p1@10153) {
//         ((@skip std/os/path/Path((@uniq-x@10174: string) : string, (@uniq-pat@0@0@10175: (list :: V -> V)<string>) : (list :: V -> V)<string>) : std/os/path/path ) as @uniq-pat@3@10173: std/os/path/path)
//            -> @uniq-x@10174;
//       }), (match (@uniq-parts@10091@10172) {
//         ((std/core/types/@Optional((@uniq-uniq-parts@95@10177: (list :: V -> V)<string>) : (list :: V -> V)<string>) : ? ((list :: V -> V)<string>) ) as @uniq-pat@1@0@10176: ? ((list :: V -> V)<string>))
//            -> @uniq-uniq-parts@95@10177;
//         ((@skip std/core/types/@None() : ? ((list :: V -> V)<string>) ) as @uniq-pat@2@0@10178: ? ((list :: V -> V)<string>))
//            -> std/core/types/Nil<string>;
//       })));
//   }))(@uniq-dir@10144, (std/core/types/@open<(total :: E),<(exn :: (E, V) -> V),(fsys :: X)>,(s : string) -> std/os/path/path,(s : string) -> <(exn :: (E, V) -> V),(fsys :: X)> std/os/path/path>(std/os/path/path)(@uniq-name@10152)));
// }

kk_std_core_types__list kk_nagare_io_file__effect__lift_defaultFileSystem_10198(kk_std_os_path__path _uniq_dir_10144, kk_std_core_types__list _uniq_xs_10180, kk_context_t* _ctx) { /* (std/os/path/path, list<string>) -> <exn,fsys> list<std/os/path/path> */ 
  if (kk_std_core_types__is_Nil(_uniq_xs_10180, _ctx)) {
    kk_std_os_path__path_drop(_uniq_dir_10144, _ctx);
    return kk_std_core_types__new_Nil(_ctx);
  }
  {
    kk_std_core_types__cctx _brw_x760 = kk_cctx_empty(kk_context()); /*ctx<0>*/;
    kk_std_core_types__list _brw_x761 = kk_nagare_io_file__effect__trmc_lift_defaultFileSystem_10199(_uniq_dir_10144, _uniq_xs_10180, _brw_x760, _ctx); /*list<std/os/path/path>*/;
    kk_std_core_types__cctx_drop(_brw_x760, _ctx);
    return _brw_x761;
  }
}
 
// lifted local: defaultFileSystem, @spec-x10179
// specialized: std/os/dir/list-directory, on parameters @uniq-dir@10144, using:
// @uniq-dir@10144 = std/core/types/@open<(total :: E),<(exn :: (E, V) -> V),(fsys :: X),(div :: X),(alloc :: H -> X)<(global :: H)>,(console/console :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>>,(s : string) -> std/os/path/path,(s : string) -> <(exn :: (E, V) -> V),(fsys :: X),(div :: X),(alloc :: H -> X)<(global :: H)>,(console/console :: X),(ndet :: X),(net :: X),(read :: H -> X)<(global :: H)>,(ui :: X),(write :: H -> X)<(global :: H)>> std/os/path/path>(std/os/path/path)(p@0)


// lift anonymous function
struct kk_nagare_io_file__effect__lift_defaultFileSystem_10197_fun1084__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_io_file__effect__lift_defaultFileSystem_10197_fun1084(kk_function_t _fself, kk_box_t _b_x473, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect__new_lift_defaultFileSystem_10197_fun1084(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file__effect__lift_defaultFileSystem_10197_fun1084, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_io_file__effect__lift_defaultFileSystem_10197_fun1084(kk_function_t _fself, kk_box_t _b_x473, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_os_path__path _x_x1085;
  kk_string_t _x_x1086 = kk_string_unbox(_b_x473); /*string*/
  _x_x1085 = kk_std_os_path_path(_x_x1086, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x_x1085, _ctx);
}


// lift anonymous function
struct kk_nagare_io_file__effect__lift_defaultFileSystem_10197_fun1088__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_io_file__effect__lift_defaultFileSystem_10197_fun1088(kk_function_t _fself, kk_box_t _b_x478, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect__new_lift_defaultFileSystem_10197_fun1088(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file__effect__lift_defaultFileSystem_10197_fun1088, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_io_file__effect__lift_defaultFileSystem_10197_fun1088(kk_function_t _fself, kk_box_t _b_x478, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_string_t _x_x1089;
  kk_std_os_path__path _x_x1090 = kk_std_os_path__path_unbox(_b_x478, KK_OWNED, _ctx); /*std/os/path/path*/
  _x_x1089 = kk_std_os_path_string(_x_x1090, _ctx); /*string*/
  return kk_string_box(_x_x1089);
}


// lift anonymous function
struct kk_nagare_io_file__effect__lift_defaultFileSystem_10197_fun1094__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_io_file__effect__lift_defaultFileSystem_10197_fun1094(kk_function_t _fself, kk_box_t _b_x483, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect__new_lift_defaultFileSystem_10197_fun1094(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file__effect__lift_defaultFileSystem_10197_fun1094, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_io_file__effect__lift_defaultFileSystem_10197_fun1094(kk_function_t _fself, kk_box_t _b_x483, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_core_exn__error _x_x1095;
  kk_string_t _x_x1096 = kk_string_unbox(_b_x483); /*string*/
  _x_x1095 = kk_std_os_dir_prim_list_dir(_x_x1096, _ctx); /*error<vector<string>>*/
  return kk_std_core_exn__error_box(_x_x1095, _ctx);
}

kk_std_core_types__list kk_nagare_io_file__effect__lift_defaultFileSystem_10197(kk_string_t p_0, kk_context_t* _ctx) { /* (p@0 : string) -> <fsys,exn> list<std/os/path/path> */ 
  kk_std_os_path__path _uniq_dir_10144;
  kk_box_t _x_x1083 = kk_std_core_hnd__open_none1(kk_nagare_io_file__effect__new_lift_defaultFileSystem_10197_fun1084(_ctx), kk_string_box(p_0), _ctx); /*10001*/
  _uniq_dir_10144 = kk_std_os_path__path_unbox(_x_x1083, KK_OWNED, _ctx); /*std/os/path/path*/
  kk_string_t _x_x1_0_10364;
  kk_box_t _x_x1087;
  kk_box_t _x_x1091;
  kk_std_os_path__path _x_x1092 = kk_std_os_path__path_dup(_uniq_dir_10144, _ctx); /*std/os/path/path*/
  _x_x1091 = kk_std_os_path__path_box(_x_x1092, _ctx); /*10000*/
  _x_x1087 = kk_std_core_hnd__open_none1(kk_nagare_io_file__effect__new_lift_defaultFileSystem_10197_fun1088(_ctx), _x_x1091, _ctx); /*10001*/
  _x_x1_0_10364 = kk_string_unbox(_x_x1087); /*string*/
  kk_std_core_exn__error _match_x757;
  kk_box_t _x_x1093 = kk_std_core_hnd__open_none1(kk_nagare_io_file__effect__new_lift_defaultFileSystem_10197_fun1094(_ctx), kk_string_box(_x_x1_0_10364), _ctx); /*10001*/
  _match_x757 = kk_std_core_exn__error_unbox(_x_x1093, KK_OWNED, _ctx); /*error<vector<string>>*/
  if (kk_std_core_exn__is_Error(_match_x757, _ctx)) {
    kk_std_core_exn__exception _uniq_exn_10146 = _match_x757._cons.Error.exception;
    kk_std_os_path__path_drop(_uniq_dir_10144, _ctx);
    kk_std_core_exn__exception_dup(_uniq_exn_10146, _ctx);
    kk_std_core_exn__error_drop(_match_x757, _ctx);
    kk_std_core_hnd__ev ev_10548 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<exn>*/;
    kk_box_t _x_x1097;
    {
      struct kk_std_core_hnd_Ev* _con_x1098 = kk_std_core_hnd__as_Ev(ev_10548, _ctx);
      kk_box_t _box_x484 = _con_x1098->hnd;
      int32_t m = _con_x1098->marker;
      kk_std_core_exn__exn h = kk_std_core_exn__exn_unbox(_box_x484, KK_BORROWED, _ctx);
      kk_std_core_exn__exn_dup(h, _ctx);
      kk_std_core_hnd__clause1 _match_x758;
      kk_std_core_hnd__clause1 _brw_x759 = kk_std_core_exn_throw_exn_fs__select(h, _ctx); /*hnd/clause1<exception,10000,exn,10001,10002>*/;
      kk_datatype_ptr_dropn(h, (KK_I32(2)), _ctx);
      _match_x758 = _brw_x759; /*hnd/clause1<exception,10000,exn,10001,10002>*/
      {
        kk_function_t _fun_unbox_x488 = _match_x758.clause;
        _x_x1097 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x488, (_fun_unbox_x488, m, ev_10548, kk_std_core_exn__exception_box(_uniq_exn_10146, _ctx), _ctx), _ctx); /*10010*/
      }
    }
    return kk_std_core_types__list_unbox(_x_x1097, KK_OWNED, _ctx);
  }
  {
    kk_box_t _box_x492 = _match_x757._cons.Ok.result;
    kk_vector_t _uniq_contents_10150 = kk_vector_unbox(_box_x492, _ctx);
    kk_vector_dup(_uniq_contents_10150, _ctx);
    kk_std_core_exn__error_drop(_match_x757, _ctx);
    kk_std_core_types__list _uniq_xs_10180 = kk_std_core_vector_vlist(_uniq_contents_10150, kk_std_core_types__new_None(_ctx), _ctx); /*list<string>*/;
    return kk_nagare_io_file__effect__lift_defaultFileSystem_10198(_uniq_dir_10144, _uniq_xs_10180, _ctx);
  }
}


// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileSystem_fun1099__t {
  struct kk_function_s _base;
};
static bool kk_nagare_io_file__effect_defaultFileSystem_fun1099(kk_function_t _fself, kk_string_t p, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileSystem_fun1099(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file__effect_defaultFileSystem_fun1099, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileSystem_fun1101__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_io_file__effect_defaultFileSystem_fun1101(kk_function_t _fself, kk_box_t _b_x497, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileSystem_fun1101(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file__effect_defaultFileSystem_fun1101, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_io_file__effect_defaultFileSystem_fun1101(kk_function_t _fself, kk_box_t _b_x497, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_os_path__path _x_x1102;
  kk_string_t _x_x1103 = kk_string_unbox(_b_x497); /*string*/
  _x_x1102 = kk_std_os_path_path(_x_x1103, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x_x1102, _ctx);
}


// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileSystem_fun1108__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_io_file__effect_defaultFileSystem_fun1108(kk_function_t _fself, kk_box_t _b_x502, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileSystem_fun1108(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file__effect_defaultFileSystem_fun1108, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_io_file__effect_defaultFileSystem_fun1108(kk_function_t _fself, kk_box_t _b_x502, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_os_path__path _x_x1109;
  kk_string_t _x_x1110 = kk_string_unbox(_b_x502); /*string*/
  _x_x1109 = kk_std_os_path_path(_x_x1110, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x_x1109, _ctx);
}
static bool kk_nagare_io_file__effect_defaultFileSystem_fun1099(kk_function_t _fself, kk_string_t p, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_os_path__path _x_x1_10366;
  kk_box_t _x_x1100;
  kk_box_t _x_x1104;
  kk_string_t _x_x1105 = kk_string_dup(p, _ctx); /*string*/
  _x_x1104 = kk_string_box(_x_x1105); /*10000*/
  _x_x1100 = kk_std_core_hnd__open_none1(kk_nagare_io_file__effect_new_defaultFileSystem_fun1101(_ctx), _x_x1104, _ctx); /*10001*/
  _x_x1_10366 = kk_std_os_path__path_unbox(_x_x1100, KK_OWNED, _ctx); /*std/os/path/path*/
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<fsys,div,exn,alloc<global>,console/console,ndet,net,read<global>,ui,write<global>>>*/;
  bool x;
  kk_string_t _x_x1106 = kk_std_os_path_string(_x_x1_10366, _ctx); /*string*/
  x = kk_std_os_dir_prim_is_file(_x_x1106, _ctx); /*bool*/
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  if (x) {
    kk_string_drop(p, _ctx);
    return true;
  }
  {
    kk_std_os_path__path _x_x1_1_10368;
    kk_box_t _x_x1107 = kk_std_core_hnd__open_none1(kk_nagare_io_file__effect_new_defaultFileSystem_fun1108(_ctx), kk_string_box(p), _ctx); /*10001*/
    _x_x1_1_10368 = kk_std_os_path__path_unbox(_x_x1107, KK_OWNED, _ctx); /*std/os/path/path*/
    kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<fsys,div,exn,alloc<global>,console/console,ndet,net,read<global>,ui,write<global>>>*/;
    bool x_0;
    kk_string_t _x_x1111 = kk_std_os_path_string(_x_x1_1_10368, _ctx); /*string*/
    x_0 = kk_std_os_dir_prim_is_dir(_x_x1111, _ctx); /*bool*/
    kk_unit_t keep_0 = kk_Unit;
    kk_evv_set(w_0,kk_context());
    return x_0;
  }
}


// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileSystem_fun1112__t {
  struct kk_function_s _base;
};
static kk_std_core_types__list kk_nagare_io_file__effect_defaultFileSystem_fun1112(kk_function_t _fself, kk_string_t p_0, bool recursive, kk_integer_t maxDepth, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileSystem_fun1112(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file__effect_defaultFileSystem_fun1112, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_std_core_types__list kk_nagare_io_file__effect_defaultFileSystem_fun1112(kk_function_t _fself, kk_string_t p_0, bool recursive, kk_integer_t maxDepth, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  if (recursive) {
    kk_std_core_types__optional _x_x1113 = kk_std_core_types__new_Optional(kk_integer_box(maxDepth, _ctx), _ctx); /*? 10003*/
    return kk_nagare_io_file__effect__lift_defaultFileSystem_10193(p_0, _x_x1113, _ctx);
  }
  {
    kk_integer_drop(maxDepth, _ctx);
    return kk_nagare_io_file__effect__lift_defaultFileSystem_10197(p_0, _ctx);
  }
}


// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileSystem_fun1115__t {
  struct kk_function_s _base;
};
static kk_unit_t kk_nagare_io_file__effect_defaultFileSystem_fun1115(kk_function_t _fself, kk_string_t _x1_x1114, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileSystem_fun1115(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file__effect_defaultFileSystem_fun1115, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_unit_t kk_nagare_io_file__effect_defaultFileSystem_fun1115(kk_function_t _fself, kk_string_t _x1_x1114, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_nagare_io_file__effect_nagare_remove(_x1_x1114, _ctx); return kk_Unit;
}


// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileSystem_fun1118__t {
  struct kk_function_s _base;
  kk_function_t _b_x505_514;
};
static kk_box_t kk_nagare_io_file__effect_defaultFileSystem_fun1118(kk_function_t _fself, kk_box_t _b_x506, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileSystem_fun1118(kk_function_t _b_x505_514, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileSystem_fun1118__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect_defaultFileSystem_fun1118__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect_defaultFileSystem_fun1118, kk_context());
  _self->_b_x505_514 = _b_x505_514;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file__effect_defaultFileSystem_fun1118(kk_function_t _fself, kk_box_t _b_x506, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileSystem_fun1118__t* _self = kk_function_as(struct kk_nagare_io_file__effect_defaultFileSystem_fun1118__t*, _fself, _ctx);
  kk_function_t _b_x505_514 = _self->_b_x505_514; /* (p : string) -> <fsys,div,exn,alloc<global>,console/console,ndet,net,read<global>,ui,write<global>> bool */
  kk_drop_match(_self, {kk_function_dup(_b_x505_514, _ctx);}, {}, _ctx)
  bool _x_x1119;
  kk_string_t _x_x1120 = kk_string_unbox(_b_x506); /*string*/
  _x_x1119 = kk_function_call(bool, (kk_function_t, kk_string_t, kk_context_t*), _b_x505_514, (_b_x505_514, _x_x1120, _ctx), _ctx); /*bool*/
  return kk_bool_box(_x_x1119);
}


// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileSystem_fun1122__t {
  struct kk_function_s _base;
  kk_function_t _b_x508_515;
};
static kk_box_t kk_nagare_io_file__effect_defaultFileSystem_fun1122(kk_function_t _fself, kk_box_t _b_x509, kk_box_t _b_x510, kk_box_t _b_x511, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileSystem_fun1122(kk_function_t _b_x508_515, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileSystem_fun1122__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect_defaultFileSystem_fun1122__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect_defaultFileSystem_fun1122, kk_context());
  _self->_b_x508_515 = _b_x508_515;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file__effect_defaultFileSystem_fun1122(kk_function_t _fself, kk_box_t _b_x509, kk_box_t _b_x510, kk_box_t _b_x511, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileSystem_fun1122__t* _self = kk_function_as(struct kk_nagare_io_file__effect_defaultFileSystem_fun1122__t*, _fself, _ctx);
  kk_function_t _b_x508_515 = _self->_b_x508_515; /* (p@0 : string, recursive : bool, maxDepth : int) -> <fsys,div,exn,alloc<global>,console/console,ndet,net,read<global>,ui,write<global>> list<std/os/path/path> */
  kk_drop_match(_self, {kk_function_dup(_b_x508_515, _ctx);}, {}, _ctx)
  kk_std_core_types__list _x_x1123;
  kk_string_t _x_x1124 = kk_string_unbox(_b_x509); /*string*/
  bool _x_x1125 = kk_bool_unbox(_b_x510); /*bool*/
  kk_integer_t _x_x1126 = kk_integer_unbox(_b_x511, _ctx); /*int*/
  _x_x1123 = kk_function_call(kk_std_core_types__list, (kk_function_t, kk_string_t, bool, kk_integer_t, kk_context_t*), _b_x508_515, (_b_x508_515, _x_x1124, _x_x1125, _x_x1126, _ctx), _ctx); /*list<std/os/path/path>*/
  return kk_std_core_types__list_box(_x_x1123, _ctx);
}


// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileSystem_fun1128__t {
  struct kk_function_s _base;
  kk_function_t _b_x512_517;
};
static kk_box_t kk_nagare_io_file__effect_defaultFileSystem_fun1128(kk_function_t _fself, kk_box_t _b_x513, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileSystem_fun1128(kk_function_t _b_x512_517, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileSystem_fun1128__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect_defaultFileSystem_fun1128__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect_defaultFileSystem_fun1128, kk_context());
  _self->_b_x512_517 = _b_x512_517;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file__effect_defaultFileSystem_fun1128(kk_function_t _fself, kk_box_t _b_x513, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileSystem_fun1128__t* _self = kk_function_as(struct kk_nagare_io_file__effect_defaultFileSystem_fun1128__t*, _fself, _ctx);
  kk_function_t _b_x512_517 = _self->_b_x512_517; /* (p : string) -> io () */
  kk_drop_match(_self, {kk_function_dup(_b_x512_517, _ctx);}, {}, _ctx)
  kk_unit_t _x_x1129 = kk_Unit;
  kk_string_t _x_x1130 = kk_string_unbox(_b_x513); /*string*/
  kk_function_call(kk_unit_t, (kk_function_t, kk_string_t, kk_context_t*), _b_x512_517, (_b_x512_517, _x_x1130, _ctx), _ctx);
  return kk_unit_box(_x_x1129);
}


// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileSystem_fun1131__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_io_file__effect_defaultFileSystem_fun1131(kk_function_t _fself, kk_box_t _res, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileSystem_fun1131(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file__effect_defaultFileSystem_fun1131, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_io_file__effect_defaultFileSystem_fun1131(kk_function_t _fself, kk_box_t _res, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return _res;
}

kk_box_t kk_nagare_io_file__effect_defaultFileSystem(kk_function_t action, kk_context_t* _ctx) { /* forall<a> (action : () -> <fileSystem|io> a) -> io a */ 
  kk_function_t _b_x505_514 = kk_nagare_io_file__effect_new_defaultFileSystem_fun1099(_ctx); /*(p : string) -> <fsys,div,exn,alloc<global>,console/console,ndet,net,read<global>,ui,write<global>> bool*/;
  kk_function_t _b_x508_515 = kk_nagare_io_file__effect_new_defaultFileSystem_fun1112(_ctx); /*(p@0 : string, recursive : bool, maxDepth : int) -> <fsys,div,exn,alloc<global>,console/console,ndet,net,read<global>,ui,write<global>> list<std/os/path/path>*/;
  kk_function_t _b_x512_517 = kk_nagare_io_file__effect_new_defaultFileSystem_fun1115(_ctx); /*(p : string) -> io ()*/;
  kk_nagare_io_file__effect__fileSystem _x_x1116;
  kk_std_core_hnd__clause1 _x_x1117 = kk_std_core_hnd_clause_tail1(kk_nagare_io_file__effect_new_defaultFileSystem_fun1118(_b_x505_514, _ctx), _ctx); /*hnd/clause1<10003,10004,10002,10000,10001>*/
  kk_std_core_hnd__clause1 _x_x1121 = kk_std_core_hnd_clause_tail3(kk_nagare_io_file__effect_new_defaultFileSystem_fun1122(_b_x508_515, _ctx), _ctx); /*hnd/clause1<(10003, 10004, 10005),10006,10002,10000,10001>*/
  kk_std_core_hnd__clause1 _x_x1127 = kk_std_core_hnd_clause_tail1(kk_nagare_io_file__effect_new_defaultFileSystem_fun1128(_b_x512_517, _ctx), _ctx); /*hnd/clause1<10003,10004,10002,10000,10001>*/
  _x_x1116 = kk_nagare_io_file__effect__new_Hnd_fileSystem(kk_reuse_null, 0, kk_integer_from_small(1), _x_x1117, _x_x1121, _x_x1127, _ctx); /*nagare/io/file_effect/fileSystem<53,54>*/
  return kk_nagare_io_file__effect_fileSystem_fs__handle(_x_x1116, kk_nagare_io_file__effect_new_defaultFileSystem_fun1131(_ctx), action, _ctx);
}
 
// Combined handler: installs all three capabilities. Call sites that only
// need one of them should prefer the narrower handler.


// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileIO_fun1132__t {
  struct kk_function_s _base;
};
static kk_unit_t kk_nagare_io_file__effect_defaultFileIO_fun1132(kk_function_t _fself, kk_nagare_io_file__effect__read_handle h, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileIO_fun1132(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file__effect_defaultFileIO_fun1132, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_unit_t kk_nagare_io_file__effect_defaultFileIO_fun1132(kk_function_t _fself, kk_nagare_io_file__effect__read_handle h, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_evv_t w = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_unit_t keep = kk_Unit;
  kk_evv_set(w,kk_context());
  intptr_t _x_x1133;
  {
    intptr_t _x = h.fd;
    _x_x1133 = _x; /*intptr_t*/
  }
  kk_nagare_io_file__effect_nagare_fclose(_x_x1133, _ctx); return kk_Unit;
}


// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileIO_fun1134__t {
  struct kk_function_s _base;
};
static kk_nagare_io_file__effect__read_handle kk_nagare_io_file__effect_defaultFileIO_fun1134(kk_function_t _fself, kk_string_t p, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileIO_fun1134(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file__effect_defaultFileIO_fun1134, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileIO_fun1136__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1136(kk_function_t _fself, kk_box_t _b_x521, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileIO_fun1136(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file__effect_defaultFileIO_fun1136, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1136(kk_function_t _fself, kk_box_t _b_x521, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_nagare_io_file__effect__read_handle _x_x1137;
  intptr_t _x_x1138 = kk_intptr_unbox(_b_x521, KK_OWNED, _ctx); /*intptr_t*/
  _x_x1137 = kk_nagare_io_file__effect__mlift_defaultFileIO_10401(_x_x1138, _ctx); /*nagare/io/file_effect/read-handle*/
  return kk_nagare_io_file__effect__read_handle_box(_x_x1137, _ctx);
}
static kk_nagare_io_file__effect__read_handle kk_nagare_io_file__effect_defaultFileIO_fun1134(kk_function_t _fself, kk_string_t p, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  intptr_t x_0_10557 = kk_nagare_io_file__effect_nagare_fopen_read(p, _ctx); /*intptr_t*/;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1135 = kk_std_core_hnd_yield_extend(kk_nagare_io_file__effect_new_defaultFileIO_fun1136(_ctx), _ctx); /*10001*/
    return kk_nagare_io_file__effect__read_handle_unbox(_x_x1135, KK_OWNED, _ctx);
  }
  {
    return kk_nagare_io_file__effect__new_ReadHandle(x_0_10557, _ctx);
  }
}


// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileIO_fun1139__t {
  struct kk_function_s _base;
};
static kk_string_t kk_nagare_io_file__effect_defaultFileIO_fun1139(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ev, kk_nagare_io_file__effect__read_handle x1_0, kk_integer_t x2, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileIO_fun1139(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file__effect_defaultFileIO_fun1139, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileIO_fun1141__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1141(kk_function_t _fself, kk_box_t _b_x528, kk_box_t _b_x529, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileIO_fun1141(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file__effect_defaultFileIO_fun1141, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1141(kk_function_t _fself, kk_box_t _b_x528, kk_box_t _b_x529, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_nagare_io_file__effect__read_handle h_0_728 = kk_nagare_io_file__effect__read_handle_unbox(_b_x528, KK_OWNED, _ctx); /*nagare/io/file_effect/read-handle*/;
  kk_integer_t size_729 = kk_integer_unbox(_b_x529, _ctx); /*int*/;
  kk_evv_t w_0 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_unit_t keep_0 = kk_Unit;
  kk_evv_set(w_0,kk_context());
  kk_string_t _x_x1142;
  intptr_t _x_x1143;
  {
    intptr_t _x_0 = h_0_728.fd;
    _x_x1143 = _x_0; /*intptr_t*/
  }
  _x_x1142 = kk_nagare_io_file__effect_nagare_fread_chunk(_x_x1143, size_729, _ctx); /*string*/
  return kk_string_box(_x_x1142);
}
static kk_string_t kk_nagare_io_file__effect_defaultFileIO_fun1139(kk_function_t _fself, int32_t m, kk_std_core_hnd__ev ev, kk_nagare_io_file__effect__read_handle x1_0, kk_integer_t x2, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_box_t _x_x1140 = kk_std_core_hnd_under2(ev, kk_nagare_io_file__effect_new_defaultFileIO_fun1141(_ctx), kk_nagare_io_file__effect__read_handle_box(x1_0, _ctx), kk_integer_box(x2, _ctx), _ctx); /*10002*/
  return kk_string_unbox(_x_x1140);
}


// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileIO_fun1144__t {
  struct kk_function_s _base;
};
static kk_vector_t kk_nagare_io_file__effect_defaultFileIO_fun1144(kk_function_t _fself, int32_t m_0, kk_std_core_hnd__ev ev_0, kk_nagare_io_file__effect__read_handle x1_2, kk_integer_t x2_0, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileIO_fun1144(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file__effect_defaultFileIO_fun1144, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileIO_fun1146__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1146(kk_function_t _fself, kk_box_t _b_x539, kk_box_t _b_x540, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileIO_fun1146(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file__effect_defaultFileIO_fun1146, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1146(kk_function_t _fself, kk_box_t _b_x539, kk_box_t _b_x540, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_nagare_io_file__effect__read_handle h_1_730 = kk_nagare_io_file__effect__read_handle_unbox(_b_x539, KK_OWNED, _ctx); /*nagare/io/file_effect/read-handle*/;
  kk_integer_t size_0_731 = kk_integer_unbox(_b_x540, _ctx); /*int*/;
  kk_evv_t w_1 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>>*/;
  kk_unit_t keep_1 = kk_Unit;
  kk_evv_set(w_1,kk_context());
  kk_vector_t _x_x1147;
  intptr_t _x_x1148;
  {
    intptr_t _x_1 = h_1_730.fd;
    _x_x1148 = _x_1; /*intptr_t*/
  }
  _x_x1147 = kk_nagare_io_file__effect_nagare_fread_chunk_bytes(_x_x1148, size_0_731, _ctx); /*vector<int8>*/
  return kk_vector_box(_x_x1147, _ctx);
}
static kk_vector_t kk_nagare_io_file__effect_defaultFileIO_fun1144(kk_function_t _fself, int32_t m_0, kk_std_core_hnd__ev ev_0, kk_nagare_io_file__effect__read_handle x1_2, kk_integer_t x2_0, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_box_t _x_x1145 = kk_std_core_hnd_under2(ev_0, kk_nagare_io_file__effect_new_defaultFileIO_fun1146(_ctx), kk_nagare_io_file__effect__read_handle_box(x1_2, _ctx), kk_integer_box(x2_0, _ctx), _ctx); /*10002*/
  return kk_vector_unbox(_x_x1145, _ctx);
}


// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileIO_fun1149__t {
  struct kk_function_s _base;
};
static kk_string_t kk_nagare_io_file__effect_defaultFileIO_fun1149(kk_function_t _fself, kk_string_t p_0, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileIO_fun1149(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file__effect_defaultFileIO_fun1149, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileIO_fun1152__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1152(kk_function_t _fself, kk_box_t _b_x548, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileIO_fun1152(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file__effect_defaultFileIO_fun1152, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1152(kk_function_t _fself, kk_box_t _b_x548, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_os_path__path _x_x1153;
  kk_string_t _x_x1154 = kk_string_unbox(_b_x548); /*string*/
  _x_x1153 = kk_std_os_path_path(_x_x1154, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x_x1153, _ctx);
}
static kk_string_t kk_nagare_io_file__effect_defaultFileIO_fun1149(kk_function_t _fself, kk_string_t p_0, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_os_path__path _x_x1150;
  kk_box_t _x_x1151 = kk_std_core_hnd__open_none1(kk_nagare_io_file__effect_new_defaultFileIO_fun1152(_ctx), kk_string_box(p_0), _ctx); /*10001*/
  _x_x1150 = kk_std_os_path__path_unbox(_x_x1151, KK_OWNED, _ctx); /*std/os/path/path*/
  return kk_std_os_file_read_text_file(_x_x1150, _ctx);
}


// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileIO_fun1157__t {
  struct kk_function_s _base;
  kk_function_t _b_x518_671;
};
static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1157(kk_function_t _fself, kk_box_t _b_x519, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileIO_fun1157(kk_function_t _b_x518_671, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileIO_fun1157__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect_defaultFileIO_fun1157__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect_defaultFileIO_fun1157, kk_context());
  _self->_b_x518_671 = _b_x518_671;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1157(kk_function_t _fself, kk_box_t _b_x519, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileIO_fun1157__t* _self = kk_function_as(struct kk_nagare_io_file__effect_defaultFileIO_fun1157__t*, _fself, _ctx);
  kk_function_t _b_x518_671 = _self->_b_x518_671; /* (h : nagare/io/file_effect/read-handle) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> () */
  kk_drop_match(_self, {kk_function_dup(_b_x518_671, _ctx);}, {}, _ctx)
  kk_unit_t _x_x1158 = kk_Unit;
  kk_nagare_io_file__effect__read_handle _x_x1159 = kk_nagare_io_file__effect__read_handle_unbox(_b_x519, KK_OWNED, _ctx); /*nagare/io/file_effect/read-handle*/
  kk_function_call(kk_unit_t, (kk_function_t, kk_nagare_io_file__effect__read_handle, kk_context_t*), _b_x518_671, (_b_x518_671, _x_x1159, _ctx), _ctx);
  return kk_unit_box(_x_x1158);
}


// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileIO_fun1161__t {
  struct kk_function_s _base;
  kk_function_t _b_x522_672;
};
static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1161(kk_function_t _fself, kk_box_t _b_x523, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileIO_fun1161(kk_function_t _b_x522_672, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileIO_fun1161__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect_defaultFileIO_fun1161__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect_defaultFileIO_fun1161, kk_context());
  _self->_b_x522_672 = _b_x522_672;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1161(kk_function_t _fself, kk_box_t _b_x523, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileIO_fun1161__t* _self = kk_function_as(struct kk_nagare_io_file__effect_defaultFileIO_fun1161__t*, _fself, _ctx);
  kk_function_t _b_x522_672 = _self->_b_x522_672; /* (p : string) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> nagare/io/file_effect/read-handle */
  kk_drop_match(_self, {kk_function_dup(_b_x522_672, _ctx);}, {}, _ctx)
  kk_nagare_io_file__effect__read_handle _x_x1162;
  kk_string_t _x_x1163 = kk_string_unbox(_b_x523); /*string*/
  _x_x1162 = kk_function_call(kk_nagare_io_file__effect__read_handle, (kk_function_t, kk_string_t, kk_context_t*), _b_x522_672, (_b_x522_672, _x_x1163, _ctx), _ctx); /*nagare/io/file_effect/read-handle*/
  return kk_nagare_io_file__effect__read_handle_box(_x_x1162, _ctx);
}


// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileIO_fun1165__t {
  struct kk_function_s _base;
  kk_function_t _b_x530_674;
};
static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1165(kk_function_t _fself, int32_t _b_x531, kk_std_core_hnd__ev _b_x532, kk_box_t _b_x533, kk_box_t _b_x534, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileIO_fun1165(kk_function_t _b_x530_674, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileIO_fun1165__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect_defaultFileIO_fun1165__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect_defaultFileIO_fun1165, kk_context());
  _self->_b_x530_674 = _b_x530_674;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1165(kk_function_t _fself, int32_t _b_x531, kk_std_core_hnd__ev _b_x532, kk_box_t _b_x533, kk_box_t _b_x534, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileIO_fun1165__t* _self = kk_function_as(struct kk_nagare_io_file__effect_defaultFileIO_fun1165__t*, _fself, _ctx);
  kk_function_t _b_x530_674 = _self->_b_x530_674; /* (m : hnd/marker<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>,3358>, ev : hnd/ev<nagare/io/file_effect/fileRead>, x1@0 : nagare/io/file_effect/read-handle, x2 : int) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> string */
  kk_drop_match(_self, {kk_function_dup(_b_x530_674, _ctx);}, {}, _ctx)
  kk_string_t _x_x1166;
  kk_nagare_io_file__effect__read_handle _x_x1167 = kk_nagare_io_file__effect__read_handle_unbox(_b_x533, KK_OWNED, _ctx); /*nagare/io/file_effect/read-handle*/
  kk_integer_t _x_x1168 = kk_integer_unbox(_b_x534, _ctx); /*int*/
  _x_x1166 = kk_function_call(kk_string_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_nagare_io_file__effect__read_handle, kk_integer_t, kk_context_t*), _b_x530_674, (_b_x530_674, _b_x531, _b_x532, _x_x1167, _x_x1168, _ctx), _ctx); /*string*/
  return kk_string_box(_x_x1166);
}


// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileIO_fun1170__t {
  struct kk_function_s _base;
  kk_function_t _b_x541_679;
};
static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1170(kk_function_t _fself, int32_t _b_x542, kk_std_core_hnd__ev _b_x543, kk_box_t _b_x544, kk_box_t _b_x545, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileIO_fun1170(kk_function_t _b_x541_679, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileIO_fun1170__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect_defaultFileIO_fun1170__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect_defaultFileIO_fun1170, kk_context());
  _self->_b_x541_679 = _b_x541_679;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1170(kk_function_t _fself, int32_t _b_x542, kk_std_core_hnd__ev _b_x543, kk_box_t _b_x544, kk_box_t _b_x545, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileIO_fun1170__t* _self = kk_function_as(struct kk_nagare_io_file__effect_defaultFileIO_fun1170__t*, _fself, _ctx);
  kk_function_t _b_x541_679 = _self->_b_x541_679; /* (m@0 : hnd/marker<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>,3358>, ev@0 : hnd/ev<nagare/io/file_effect/fileRead>, x1@2 : nagare/io/file_effect/read-handle, x2@0 : int) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> vector<int8> */
  kk_drop_match(_self, {kk_function_dup(_b_x541_679, _ctx);}, {}, _ctx)
  kk_vector_t _x_x1171;
  kk_nagare_io_file__effect__read_handle _x_x1172 = kk_nagare_io_file__effect__read_handle_unbox(_b_x544, KK_OWNED, _ctx); /*nagare/io/file_effect/read-handle*/
  kk_integer_t _x_x1173 = kk_integer_unbox(_b_x545, _ctx); /*int*/
  _x_x1171 = kk_function_call(kk_vector_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_nagare_io_file__effect__read_handle, kk_integer_t, kk_context_t*), _b_x541_679, (_b_x541_679, _b_x542, _b_x543, _x_x1172, _x_x1173, _ctx), _ctx); /*vector<int8>*/
  return kk_vector_box(_x_x1171, _ctx);
}


// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileIO_fun1175__t {
  struct kk_function_s _base;
  kk_function_t _b_x549_684;
};
static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1175(kk_function_t _fself, kk_box_t _b_x550, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileIO_fun1175(kk_function_t _b_x549_684, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileIO_fun1175__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect_defaultFileIO_fun1175__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect_defaultFileIO_fun1175, kk_context());
  _self->_b_x549_684 = _b_x549_684;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1175(kk_function_t _fself, kk_box_t _b_x550, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileIO_fun1175__t* _self = kk_function_as(struct kk_nagare_io_file__effect_defaultFileIO_fun1175__t*, _fself, _ctx);
  kk_function_t _b_x549_684 = _self->_b_x549_684; /* (p@0 : string) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> string */
  kk_drop_match(_self, {kk_function_dup(_b_x549_684, _ctx);}, {}, _ctx)
  kk_string_t _x_x1176;
  kk_string_t _x_x1177 = kk_string_unbox(_b_x550); /*string*/
  _x_x1176 = kk_function_call(kk_string_t, (kk_function_t, kk_string_t, kk_context_t*), _b_x549_684, (_b_x549_684, _x_x1177, _ctx), _ctx); /*string*/
  return kk_string_box(_x_x1176);
}


// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileIO_fun1178__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1178(kk_function_t _fself, kk_box_t _res, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileIO_fun1178(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file__effect_defaultFileIO_fun1178, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1178(kk_function_t _fself, kk_box_t _res, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return _res;
}


// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileIO_fun1179__t {
  struct kk_function_s _base;
  kk_function_t action;
};
static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1179(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileIO_fun1179(kk_function_t action, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileIO_fun1179__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect_defaultFileIO_fun1179__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect_defaultFileIO_fun1179, kk_context());
  _self->action = action;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileIO_fun1180__t {
  struct kk_function_s _base;
};
static kk_unit_t kk_nagare_io_file__effect_defaultFileIO_fun1180(kk_function_t _fself, kk_nagare_io_file__effect__write_handle h_2, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileIO_fun1180(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file__effect_defaultFileIO_fun1180, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileIO_fun1183__t {
  struct kk_function_s _base;
  kk_ssize_t i_10567;
};
static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1183(kk_function_t _fself, kk_function_t _b_x556, kk_box_t _b_x557, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileIO_fun1183(kk_ssize_t i_10567, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileIO_fun1183__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect_defaultFileIO_fun1183__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect_defaultFileIO_fun1183, kk_context());
  _self->i_10567 = i_10567;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileIO_fun1184__t {
  struct kk_function_s _base;
  kk_function_t _b_x556;
};
static kk_unit_t kk_nagare_io_file__effect_defaultFileIO_fun1184(kk_function_t _fself, kk_box_t _b_x558, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileIO_fun1184(kk_function_t _b_x556, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileIO_fun1184__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect_defaultFileIO_fun1184__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect_defaultFileIO_fun1184, kk_context());
  _self->_b_x556 = _b_x556;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_unit_t kk_nagare_io_file__effect_defaultFileIO_fun1184(kk_function_t _fself, kk_box_t _b_x558, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileIO_fun1184__t* _self = kk_function_as(struct kk_nagare_io_file__effect_defaultFileIO_fun1184__t*, _fself, _ctx);
  kk_function_t _b_x556 = _self->_b_x556; /* (10003) -> 10001 10000 */
  kk_drop_match(_self, {kk_function_dup(_b_x556, _ctx);}, {}, _ctx)
  kk_box_t _x_x1185 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _b_x556, (_b_x556, _b_x558, _ctx), _ctx); /*10000*/
  kk_unit_unbox(_x_x1185); return kk_Unit;
}


// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileIO_fun1186__t {
  struct kk_function_s _base;
  kk_function_t _b_x552_690;
};
static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1186(kk_function_t _fself, kk_box_t _b_x554, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileIO_fun1186(kk_function_t _b_x552_690, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileIO_fun1186__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect_defaultFileIO_fun1186__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect_defaultFileIO_fun1186, kk_context());
  _self->_b_x552_690 = _b_x552_690;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1186(kk_function_t _fself, kk_box_t _b_x554, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileIO_fun1186__t* _self = kk_function_as(struct kk_nagare_io_file__effect_defaultFileIO_fun1186__t*, _fself, _ctx);
  kk_function_t _b_x552_690 = _self->_b_x552_690; /* (10011) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>,nagare/io/file_effect/fileRead> () */
  kk_drop_match(_self, {kk_function_dup(_b_x552_690, _ctx);}, {}, _ctx)
  kk_unit_t _x_x1187 = kk_Unit;
  kk_function_call(kk_unit_t, (kk_function_t, kk_box_t, kk_context_t*), _b_x552_690, (_b_x552_690, _b_x554, _ctx), _ctx);
  return kk_unit_box(_x_x1187);
}
static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1183(kk_function_t _fself, kk_function_t _b_x556, kk_box_t _b_x557, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileIO_fun1183__t* _self = kk_function_as(struct kk_nagare_io_file__effect_defaultFileIO_fun1183__t*, _fself, _ctx);
  kk_ssize_t i_10567 = _self->i_10567; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_10567, _ctx);}, {}, _ctx)
  kk_function_t cont_732 = kk_nagare_io_file__effect_new_defaultFileIO_fun1184(_b_x556, _ctx); /*(10011) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>,nagare/io/file_effect/fileRead> ()*/;
  kk_box_t res_733 = _b_x557; /*10011*/;
  kk_ssize_t _b_x551_689 = i_10567; /*hnd/ev-index*/;
  kk_function_t _b_x552_690 = cont_732; /*(10011) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>,nagare/io/file_effect/fileRead> ()*/;
  kk_box_t _b_x553_691 = res_733; /*10011*/;
  return kk_std_core_hnd_open_at1(_b_x551_689, kk_nagare_io_file__effect_new_defaultFileIO_fun1186(_b_x552_690, _ctx), _b_x553_691, _ctx);
}
static kk_unit_t kk_nagare_io_file__effect_defaultFileIO_fun1180(kk_function_t _fself, kk_nagare_io_file__effect__write_handle h_2, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_evv_t w_2 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>,nagare/io/file_effect/fileRead>>*/;
  kk_unit_t keep_2 = kk_Unit;
  kk_evv_set(w_2,kk_context());
  kk_ssize_t i_10567 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_evv_t w_3 = kk_evv_swap_create1(i_10567,kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>,nagare/io/file_effect/fileRead>>*/;
  kk_unit_t y = kk_Unit;
  intptr_t _x_x1181;
  {
    intptr_t _x_2 = h_2.fd;
    _x_x1181 = _x_2; /*intptr_t*/
  }
  kk_nagare_io_file__effect_nagare_fclose(_x_x1181, _ctx);
  kk_evv_set(w_3,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1182 = kk_std_core_hnd_yield_cont(kk_nagare_io_file__effect_new_defaultFileIO_fun1183(i_10567, _ctx), _ctx); /*10002*/
    kk_unit_unbox(_x_x1182); return kk_Unit;
  }
  {
    y; return kk_Unit;
  }
}


// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileIO_fun1188__t {
  struct kk_function_s _base;
};
static kk_nagare_io_file__effect__write_handle kk_nagare_io_file__effect_defaultFileIO_fun1188(kk_function_t _fself, kk_string_t p_1, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileIO_fun1188(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file__effect_defaultFileIO_fun1188, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileIO_fun1190__t {
  struct kk_function_s _base;
  kk_ssize_t i_0_10572;
};
static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1190(kk_function_t _fself, kk_function_t _b_x566, kk_box_t _b_x567, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileIO_fun1190(kk_ssize_t i_0_10572, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileIO_fun1190__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect_defaultFileIO_fun1190__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect_defaultFileIO_fun1190, kk_context());
  _self->i_0_10572 = i_0_10572;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1190(kk_function_t _fself, kk_function_t _b_x566, kk_box_t _b_x567, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileIO_fun1190__t* _self = kk_function_as(struct kk_nagare_io_file__effect_defaultFileIO_fun1190__t*, _fself, _ctx);
  kk_ssize_t i_0_10572 = _self->i_0_10572; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_0_10572, _ctx);}, {}, _ctx)
  return kk_std_core_hnd_open_at1(i_0_10572, _b_x566, _b_x567, _ctx);
}


// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileIO_fun1192__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1192(kk_function_t _fself, kk_box_t _b_x576, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileIO_fun1192(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file__effect_defaultFileIO_fun1192, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1192(kk_function_t _fself, kk_box_t _b_x576, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_nagare_io_file__effect__write_handle _x_x1193;
  intptr_t _x_x1194 = kk_intptr_unbox(_b_x576, KK_OWNED, _ctx); /*intptr_t*/
  _x_x1193 = kk_nagare_io_file__effect__mlift_defaultFileIO_10402(_x_x1194, _ctx); /*nagare/io/file_effect/write-handle*/
  return kk_nagare_io_file__effect__write_handle_box(_x_x1193, _ctx);
}
static kk_nagare_io_file__effect__write_handle kk_nagare_io_file__effect_defaultFileIO_fun1188(kk_function_t _fself, kk_string_t p_1, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_ssize_t i_0_10572 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_evv_t w_4 = kk_evv_swap_create1(i_0_10572,kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>,nagare/io/file_effect/fileRead>>*/;
  intptr_t y_0 = kk_nagare_io_file__effect_nagare_fopen_write(p_1, _ctx); /*intptr_t*/;
  kk_evv_set(w_4,kk_context());
  intptr_t x_5_10570;
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1189 = kk_std_core_hnd_yield_cont(kk_nagare_io_file__effect_new_defaultFileIO_fun1190(i_0_10572, _ctx), _ctx); /*10002*/
    x_5_10570 = kk_intptr_unbox(_x_x1189, KK_OWNED, _ctx); /*intptr_t*/
  }
  else {
    x_5_10570 = y_0; /*intptr_t*/
  }
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1191 = kk_std_core_hnd_yield_extend(kk_nagare_io_file__effect_new_defaultFileIO_fun1192(_ctx), _ctx); /*10001*/
    return kk_nagare_io_file__effect__write_handle_unbox(_x_x1191, KK_OWNED, _ctx);
  }
  {
    return kk_nagare_io_file__effect__new_WriteHandle(x_5_10570, _ctx);
  }
}


// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileIO_fun1195__t {
  struct kk_function_s _base;
};
static kk_integer_t kk_nagare_io_file__effect_defaultFileIO_fun1195(kk_function_t _fself, int32_t m_1, kk_std_core_hnd__ev ev_1, kk_nagare_io_file__effect__write_handle x1_5, kk_string_t x2_1, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileIO_fun1195(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file__effect_defaultFileIO_fun1195, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileIO_fun1197__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1197(kk_function_t _fself, kk_box_t _b_x591, kk_box_t _b_x592, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileIO_fun1197(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file__effect_defaultFileIO_fun1197, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileIO_fun1201__t {
  struct kk_function_s _base;
  kk_ssize_t i_1_10578;
};
static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1201(kk_function_t _fself, kk_function_t _b_x584, kk_box_t _b_x585, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileIO_fun1201(kk_ssize_t i_1_10578, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileIO_fun1201__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect_defaultFileIO_fun1201__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect_defaultFileIO_fun1201, kk_context());
  _self->i_1_10578 = i_1_10578;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileIO_fun1202__t {
  struct kk_function_s _base;
  kk_function_t _b_x584;
};
static kk_integer_t kk_nagare_io_file__effect_defaultFileIO_fun1202(kk_function_t _fself, kk_box_t _b_x586, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileIO_fun1202(kk_function_t _b_x584, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileIO_fun1202__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect_defaultFileIO_fun1202__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect_defaultFileIO_fun1202, kk_context());
  _self->_b_x584 = _b_x584;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_integer_t kk_nagare_io_file__effect_defaultFileIO_fun1202(kk_function_t _fself, kk_box_t _b_x586, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileIO_fun1202__t* _self = kk_function_as(struct kk_nagare_io_file__effect_defaultFileIO_fun1202__t*, _fself, _ctx);
  kk_function_t _b_x584 = _self->_b_x584; /* (10003) -> 10001 10000 */
  kk_drop_match(_self, {kk_function_dup(_b_x584, _ctx);}, {}, _ctx)
  kk_box_t _x_x1203 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _b_x584, (_b_x584, _b_x586, _ctx), _ctx); /*10000*/
  return kk_integer_unbox(_x_x1203, _ctx);
}


// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileIO_fun1204__t {
  struct kk_function_s _base;
  kk_function_t _b_x580_702;
};
static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1204(kk_function_t _fself, kk_box_t _b_x582, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileIO_fun1204(kk_function_t _b_x580_702, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileIO_fun1204__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect_defaultFileIO_fun1204__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect_defaultFileIO_fun1204, kk_context());
  _self->_b_x580_702 = _b_x580_702;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1204(kk_function_t _fself, kk_box_t _b_x582, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileIO_fun1204__t* _self = kk_function_as(struct kk_nagare_io_file__effect_defaultFileIO_fun1204__t*, _fself, _ctx);
  kk_function_t _b_x580_702 = _self->_b_x580_702; /* (10013) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>,nagare/io/file_effect/fileRead> int */
  kk_drop_match(_self, {kk_function_dup(_b_x580_702, _ctx);}, {}, _ctx)
  kk_integer_t _x_x1205 = kk_function_call(kk_integer_t, (kk_function_t, kk_box_t, kk_context_t*), _b_x580_702, (_b_x580_702, _b_x582, _ctx), _ctx); /*int*/
  return kk_integer_box(_x_x1205, _ctx);
}
static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1201(kk_function_t _fself, kk_function_t _b_x584, kk_box_t _b_x585, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileIO_fun1201__t* _self = kk_function_as(struct kk_nagare_io_file__effect_defaultFileIO_fun1201__t*, _fself, _ctx);
  kk_ssize_t i_1_10578 = _self->i_1_10578; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_1_10578, _ctx);}, {}, _ctx)
  kk_function_t cont_1_736 = kk_nagare_io_file__effect_new_defaultFileIO_fun1202(_b_x584, _ctx); /*(10013) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>,nagare/io/file_effect/fileRead> int*/;
  kk_box_t res_1_737 = _b_x585; /*10013*/;
  kk_ssize_t _b_x579_701 = i_1_10578; /*hnd/ev-index*/;
  kk_function_t _b_x580_702 = cont_1_736; /*(10013) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>,nagare/io/file_effect/fileRead> int*/;
  kk_box_t _b_x581_703 = res_1_737; /*10013*/;
  return kk_std_core_hnd_open_at1(_b_x579_701, kk_nagare_io_file__effect_new_defaultFileIO_fun1204(_b_x580_702, _ctx), _b_x581_703, _ctx);
}
static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1197(kk_function_t _fself, kk_box_t _b_x591, kk_box_t _b_x592, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_nagare_io_file__effect__write_handle h_3_734 = kk_nagare_io_file__effect__write_handle_unbox(_b_x591, KK_OWNED, _ctx); /*nagare/io/file_effect/write-handle*/;
  kk_string_t content_735 = kk_string_unbox(_b_x592); /*string*/;
  kk_evv_t w_5 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>,nagare/io/file_effect/fileRead>>*/;
  kk_unit_t keep_3 = kk_Unit;
  kk_evv_set(w_5,kk_context());
  kk_ssize_t i_1_10578 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_evv_t w_6 = kk_evv_swap_create1(i_1_10578,kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>,nagare/io/file_effect/fileRead>>*/;
  kk_integer_t y_1;
  intptr_t _x_x1198;
  {
    intptr_t _x_3 = h_3_734.fd;
    _x_x1198 = _x_3; /*intptr_t*/
  }
  y_1 = kk_nagare_io_file__effect_nagare_fwrite_chunk(_x_x1198, content_735, _ctx); /*int*/
  kk_evv_set(w_6,kk_context());
  kk_integer_t _x_x1199;
  if (kk_yielding(kk_context())) {
    kk_integer_drop(y_1, _ctx);
    kk_box_t _x_x1200 = kk_std_core_hnd_yield_cont(kk_nagare_io_file__effect_new_defaultFileIO_fun1201(i_1_10578, _ctx), _ctx); /*10002*/
    _x_x1199 = kk_integer_unbox(_x_x1200, _ctx); /*int*/
  }
  else {
    _x_x1199 = y_1; /*int*/
  }
  return kk_integer_box(_x_x1199, _ctx);
}
static kk_integer_t kk_nagare_io_file__effect_defaultFileIO_fun1195(kk_function_t _fself, int32_t m_1, kk_std_core_hnd__ev ev_1, kk_nagare_io_file__effect__write_handle x1_5, kk_string_t x2_1, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_box_t _x_x1196 = kk_std_core_hnd_under2(ev_1, kk_nagare_io_file__effect_new_defaultFileIO_fun1197(_ctx), kk_nagare_io_file__effect__write_handle_box(x1_5, _ctx), kk_string_box(x2_1), _ctx); /*10002*/
  return kk_integer_unbox(_x_x1196, _ctx);
}


// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileIO_fun1206__t {
  struct kk_function_s _base;
};
static kk_integer_t kk_nagare_io_file__effect_defaultFileIO_fun1206(kk_function_t _fself, int32_t m_2, kk_std_core_hnd__ev ev_2, kk_nagare_io_file__effect__write_handle x1_8, kk_vector_t x2_3, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileIO_fun1206(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file__effect_defaultFileIO_fun1206, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileIO_fun1208__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1208(kk_function_t _fself, kk_box_t _b_x610, kk_box_t _b_x611, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileIO_fun1208(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file__effect_defaultFileIO_fun1208, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileIO_fun1212__t {
  struct kk_function_s _base;
  kk_ssize_t i_2_10585;
};
static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1212(kk_function_t _fself, kk_function_t _b_x603, kk_box_t _b_x604, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileIO_fun1212(kk_ssize_t i_2_10585, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileIO_fun1212__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect_defaultFileIO_fun1212__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect_defaultFileIO_fun1212, kk_context());
  _self->i_2_10585 = i_2_10585;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileIO_fun1213__t {
  struct kk_function_s _base;
  kk_function_t _b_x603;
};
static kk_integer_t kk_nagare_io_file__effect_defaultFileIO_fun1213(kk_function_t _fself, kk_box_t _b_x605, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileIO_fun1213(kk_function_t _b_x603, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileIO_fun1213__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect_defaultFileIO_fun1213__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect_defaultFileIO_fun1213, kk_context());
  _self->_b_x603 = _b_x603;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_integer_t kk_nagare_io_file__effect_defaultFileIO_fun1213(kk_function_t _fself, kk_box_t _b_x605, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileIO_fun1213__t* _self = kk_function_as(struct kk_nagare_io_file__effect_defaultFileIO_fun1213__t*, _fself, _ctx);
  kk_function_t _b_x603 = _self->_b_x603; /* (10003) -> 10001 10000 */
  kk_drop_match(_self, {kk_function_dup(_b_x603, _ctx);}, {}, _ctx)
  kk_box_t _x_x1214 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _b_x603, (_b_x603, _b_x605, _ctx), _ctx); /*10000*/
  return kk_integer_unbox(_x_x1214, _ctx);
}


// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileIO_fun1215__t {
  struct kk_function_s _base;
  kk_function_t _b_x599_711;
};
static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1215(kk_function_t _fself, kk_box_t _b_x601, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileIO_fun1215(kk_function_t _b_x599_711, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileIO_fun1215__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect_defaultFileIO_fun1215__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect_defaultFileIO_fun1215, kk_context());
  _self->_b_x599_711 = _b_x599_711;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1215(kk_function_t _fself, kk_box_t _b_x601, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileIO_fun1215__t* _self = kk_function_as(struct kk_nagare_io_file__effect_defaultFileIO_fun1215__t*, _fself, _ctx);
  kk_function_t _b_x599_711 = _self->_b_x599_711; /* (10013) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>,nagare/io/file_effect/fileRead> int */
  kk_drop_match(_self, {kk_function_dup(_b_x599_711, _ctx);}, {}, _ctx)
  kk_integer_t _x_x1216 = kk_function_call(kk_integer_t, (kk_function_t, kk_box_t, kk_context_t*), _b_x599_711, (_b_x599_711, _b_x601, _ctx), _ctx); /*int*/
  return kk_integer_box(_x_x1216, _ctx);
}
static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1212(kk_function_t _fself, kk_function_t _b_x603, kk_box_t _b_x604, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileIO_fun1212__t* _self = kk_function_as(struct kk_nagare_io_file__effect_defaultFileIO_fun1212__t*, _fself, _ctx);
  kk_ssize_t i_2_10585 = _self->i_2_10585; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_2_10585, _ctx);}, {}, _ctx)
  kk_function_t cont_2_740 = kk_nagare_io_file__effect_new_defaultFileIO_fun1213(_b_x603, _ctx); /*(10013) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>,nagare/io/file_effect/fileRead> int*/;
  kk_box_t res_2_741 = _b_x604; /*10013*/;
  kk_ssize_t _b_x598_710 = i_2_10585; /*hnd/ev-index*/;
  kk_function_t _b_x599_711 = cont_2_740; /*(10013) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>,nagare/io/file_effect/fileRead> int*/;
  kk_box_t _b_x600_712 = res_2_741; /*10013*/;
  return kk_std_core_hnd_open_at1(_b_x598_710, kk_nagare_io_file__effect_new_defaultFileIO_fun1215(_b_x599_711, _ctx), _b_x600_712, _ctx);
}
static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1208(kk_function_t _fself, kk_box_t _b_x610, kk_box_t _b_x611, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_nagare_io_file__effect__write_handle h_4_738 = kk_nagare_io_file__effect__write_handle_unbox(_b_x610, KK_OWNED, _ctx); /*nagare/io/file_effect/write-handle*/;
  kk_vector_t content_0_739 = kk_vector_unbox(_b_x611, _ctx); /*vector<int8>*/;
  kk_evv_t w_7 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>,nagare/io/file_effect/fileRead>>*/;
  kk_unit_t keep_4 = kk_Unit;
  kk_evv_set(w_7,kk_context());
  kk_ssize_t i_2_10585 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_evv_t w_8 = kk_evv_swap_create1(i_2_10585,kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>,nagare/io/file_effect/fileRead>>*/;
  kk_integer_t y_2;
  intptr_t _x_x1209;
  {
    intptr_t _x_4 = h_4_738.fd;
    _x_x1209 = _x_4; /*intptr_t*/
  }
  y_2 = kk_nagare_io_file__effect_nagare_fwrite_chunk_bytes(_x_x1209, content_0_739, _ctx); /*int*/
  kk_evv_set(w_8,kk_context());
  kk_integer_t _x_x1210;
  if (kk_yielding(kk_context())) {
    kk_integer_drop(y_2, _ctx);
    kk_box_t _x_x1211 = kk_std_core_hnd_yield_cont(kk_nagare_io_file__effect_new_defaultFileIO_fun1212(i_2_10585, _ctx), _ctx); /*10002*/
    _x_x1210 = kk_integer_unbox(_x_x1211, _ctx); /*int*/
  }
  else {
    _x_x1210 = y_2; /*int*/
  }
  return kk_integer_box(_x_x1210, _ctx);
}
static kk_integer_t kk_nagare_io_file__effect_defaultFileIO_fun1206(kk_function_t _fself, int32_t m_2, kk_std_core_hnd__ev ev_2, kk_nagare_io_file__effect__write_handle x1_8, kk_vector_t x2_3, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_box_t _x_x1207 = kk_std_core_hnd_under2(ev_2, kk_nagare_io_file__effect_new_defaultFileIO_fun1208(_ctx), kk_nagare_io_file__effect__write_handle_box(x1_8, _ctx), kk_vector_box(x2_3, _ctx), _ctx); /*10002*/
  return kk_integer_unbox(_x_x1207, _ctx);
}


// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileIO_fun1219__t {
  struct kk_function_s _base;
  kk_function_t _b_x559_687;
};
static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1219(kk_function_t _fself, kk_box_t _b_x560, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileIO_fun1219(kk_function_t _b_x559_687, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileIO_fun1219__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect_defaultFileIO_fun1219__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect_defaultFileIO_fun1219, kk_context());
  _self->_b_x559_687 = _b_x559_687;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1219(kk_function_t _fself, kk_box_t _b_x560, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileIO_fun1219__t* _self = kk_function_as(struct kk_nagare_io_file__effect_defaultFileIO_fun1219__t*, _fself, _ctx);
  kk_function_t _b_x559_687 = _self->_b_x559_687; /* (h@2 : nagare/io/file_effect/write-handle) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>,nagare/io/file_effect/fileRead> () */
  kk_drop_match(_self, {kk_function_dup(_b_x559_687, _ctx);}, {}, _ctx)
  kk_unit_t _x_x1220 = kk_Unit;
  kk_nagare_io_file__effect__write_handle _x_x1221 = kk_nagare_io_file__effect__write_handle_unbox(_b_x560, KK_OWNED, _ctx); /*nagare/io/file_effect/write-handle*/
  kk_function_call(kk_unit_t, (kk_function_t, kk_nagare_io_file__effect__write_handle, kk_context_t*), _b_x559_687, (_b_x559_687, _x_x1221, _ctx), _ctx);
  return kk_unit_box(_x_x1220);
}


// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileIO_fun1223__t {
  struct kk_function_s _base;
  kk_function_t _b_x577_692;
};
static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1223(kk_function_t _fself, kk_box_t _b_x578, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileIO_fun1223(kk_function_t _b_x577_692, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileIO_fun1223__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect_defaultFileIO_fun1223__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect_defaultFileIO_fun1223, kk_context());
  _self->_b_x577_692 = _b_x577_692;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1223(kk_function_t _fself, kk_box_t _b_x578, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileIO_fun1223__t* _self = kk_function_as(struct kk_nagare_io_file__effect_defaultFileIO_fun1223__t*, _fself, _ctx);
  kk_function_t _b_x577_692 = _self->_b_x577_692; /* (p@1 : string) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>,nagare/io/file_effect/fileRead> nagare/io/file_effect/write-handle */
  kk_drop_match(_self, {kk_function_dup(_b_x577_692, _ctx);}, {}, _ctx)
  kk_nagare_io_file__effect__write_handle _x_x1224;
  kk_string_t _x_x1225 = kk_string_unbox(_b_x578); /*string*/
  _x_x1224 = kk_function_call(kk_nagare_io_file__effect__write_handle, (kk_function_t, kk_string_t, kk_context_t*), _b_x577_692, (_b_x577_692, _x_x1225, _ctx), _ctx); /*nagare/io/file_effect/write-handle*/
  return kk_nagare_io_file__effect__write_handle_box(_x_x1224, _ctx);
}


// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileIO_fun1227__t {
  struct kk_function_s _base;
  kk_function_t _b_x593_695;
};
static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1227(kk_function_t _fself, int32_t _b_x594, kk_std_core_hnd__ev _b_x595, kk_box_t _b_x596, kk_box_t _b_x597, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileIO_fun1227(kk_function_t _b_x593_695, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileIO_fun1227__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect_defaultFileIO_fun1227__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect_defaultFileIO_fun1227, kk_context());
  _self->_b_x593_695 = _b_x593_695;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1227(kk_function_t _fself, int32_t _b_x594, kk_std_core_hnd__ev _b_x595, kk_box_t _b_x596, kk_box_t _b_x597, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileIO_fun1227__t* _self = kk_function_as(struct kk_nagare_io_file__effect_defaultFileIO_fun1227__t*, _fself, _ctx);
  kk_function_t _b_x593_695 = _self->_b_x593_695; /* (m@1 : hnd/marker<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>,nagare/io/file_effect/fileRead>,3358>, ev@1 : hnd/ev<nagare/io/file_effect/fileWrite>, x1@5 : nagare/io/file_effect/write-handle, x2@1 : string) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>,nagare/io/file_effect/fileRead> int */
  kk_drop_match(_self, {kk_function_dup(_b_x593_695, _ctx);}, {}, _ctx)
  kk_integer_t _x_x1228;
  kk_nagare_io_file__effect__write_handle _x_x1229 = kk_nagare_io_file__effect__write_handle_unbox(_b_x596, KK_OWNED, _ctx); /*nagare/io/file_effect/write-handle*/
  kk_string_t _x_x1230 = kk_string_unbox(_b_x597); /*string*/
  _x_x1228 = kk_function_call(kk_integer_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_nagare_io_file__effect__write_handle, kk_string_t, kk_context_t*), _b_x593_695, (_b_x593_695, _b_x594, _b_x595, _x_x1229, _x_x1230, _ctx), _ctx); /*int*/
  return kk_integer_box(_x_x1228, _ctx);
}


// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileIO_fun1232__t {
  struct kk_function_s _base;
  kk_function_t _b_x612_704;
};
static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1232(kk_function_t _fself, int32_t _b_x613, kk_std_core_hnd__ev _b_x614, kk_box_t _b_x615, kk_box_t _b_x616, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileIO_fun1232(kk_function_t _b_x612_704, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileIO_fun1232__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect_defaultFileIO_fun1232__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect_defaultFileIO_fun1232, kk_context());
  _self->_b_x612_704 = _b_x612_704;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1232(kk_function_t _fself, int32_t _b_x613, kk_std_core_hnd__ev _b_x614, kk_box_t _b_x615, kk_box_t _b_x616, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileIO_fun1232__t* _self = kk_function_as(struct kk_nagare_io_file__effect_defaultFileIO_fun1232__t*, _fself, _ctx);
  kk_function_t _b_x612_704 = _self->_b_x612_704; /* (m@2 : hnd/marker<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>,nagare/io/file_effect/fileRead>,3358>, ev@2 : hnd/ev<nagare/io/file_effect/fileWrite>, x1@8 : nagare/io/file_effect/write-handle, x2@3 : vector<int8>) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>,nagare/io/file_effect/fileRead> int */
  kk_drop_match(_self, {kk_function_dup(_b_x612_704, _ctx);}, {}, _ctx)
  kk_integer_t _x_x1233;
  kk_nagare_io_file__effect__write_handle _x_x1234 = kk_nagare_io_file__effect__write_handle_unbox(_b_x615, KK_OWNED, _ctx); /*nagare/io/file_effect/write-handle*/
  kk_vector_t _x_x1235 = kk_vector_unbox(_b_x616, _ctx); /*vector<int8>*/
  _x_x1233 = kk_function_call(kk_integer_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_nagare_io_file__effect__write_handle, kk_vector_t, kk_context_t*), _b_x612_704, (_b_x612_704, _b_x613, _b_x614, _x_x1234, _x_x1235, _ctx), _ctx); /*int*/
  return kk_integer_box(_x_x1233, _ctx);
}


// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileIO_fun1236__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1236(kk_function_t _fself, kk_box_t _res_0, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileIO_fun1236(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file__effect_defaultFileIO_fun1236, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1236(kk_function_t _fself, kk_box_t _res_0, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return _res_0;
}


// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileIO_fun1237__t {
  struct kk_function_s _base;
  kk_function_t action;
};
static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1237(kk_function_t _fself, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileIO_fun1237(kk_function_t action, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileIO_fun1237__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect_defaultFileIO_fun1237__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect_defaultFileIO_fun1237, kk_context());
  _self->action = action;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileIO_fun1238__t {
  struct kk_function_s _base;
};
static bool kk_nagare_io_file__effect_defaultFileIO_fun1238(kk_function_t _fself, kk_string_t p_2, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileIO_fun1238(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file__effect_defaultFileIO_fun1238, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileIO_fun1240__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1240(kk_function_t _fself, kk_box_t _b_x619, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileIO_fun1240(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file__effect_defaultFileIO_fun1240, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1240(kk_function_t _fself, kk_box_t _b_x619, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_os_path__path _x_x1241;
  kk_string_t _x_x1242 = kk_string_unbox(_b_x619); /*string*/
  _x_x1241 = kk_std_os_path_path(_x_x1242, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x_x1241, _ctx);
}


// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileIO_fun1247__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1247(kk_function_t _fself, kk_box_t _b_x624, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileIO_fun1247(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file__effect_defaultFileIO_fun1247, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1247(kk_function_t _fself, kk_box_t _b_x624, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_os_path__path _x_x1248;
  kk_string_t _x_x1249 = kk_string_unbox(_b_x624); /*string*/
  _x_x1248 = kk_std_os_path_path(_x_x1249, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x_x1248, _ctx);
}
static bool kk_nagare_io_file__effect_defaultFileIO_fun1238(kk_function_t _fself, kk_string_t p_2, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_os_path__path _x_x1_10_10383;
  kk_box_t _x_x1239;
  kk_box_t _x_x1243;
  kk_string_t _x_x1244 = kk_string_dup(p_2, _ctx); /*string*/
  _x_x1243 = kk_string_box(_x_x1244); /*10000*/
  _x_x1239 = kk_std_core_hnd__open_none1(kk_nagare_io_file__effect_new_defaultFileIO_fun1240(_ctx), _x_x1243, _ctx); /*10001*/
  _x_x1_10_10383 = kk_std_os_path__path_unbox(_x_x1239, KK_OWNED, _ctx); /*std/os/path/path*/
  kk_evv_t w_9 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<fsys,div,exn,alloc<global>,console/console,ndet,net,read<global>,ui,write<global>,nagare/io/file_effect/fileRead,nagare/io/file_effect/fileWrite>>*/;
  bool x_9;
  kk_string_t _x_x1245 = kk_std_os_path_string(_x_x1_10_10383, _ctx); /*string*/
  x_9 = kk_std_os_dir_prim_is_file(_x_x1245, _ctx); /*bool*/
  kk_unit_t keep_5 = kk_Unit;
  kk_evv_set(w_9,kk_context());
  if (x_9) {
    kk_string_drop(p_2, _ctx);
    return true;
  }
  {
    kk_std_os_path__path _x_x1_12_10385;
    kk_box_t _x_x1246 = kk_std_core_hnd__open_none1(kk_nagare_io_file__effect_new_defaultFileIO_fun1247(_ctx), kk_string_box(p_2), _ctx); /*10001*/
    _x_x1_12_10385 = kk_std_os_path__path_unbox(_x_x1246, KK_OWNED, _ctx); /*std/os/path/path*/
    kk_evv_t w_10 = kk_evv_swap_create0(kk_context()); /*hnd/evv<<fsys,div,exn,alloc<global>,console/console,ndet,net,read<global>,ui,write<global>,nagare/io/file_effect/fileRead,nagare/io/file_effect/fileWrite>>*/;
    bool x_10;
    kk_string_t _x_x1250 = kk_std_os_path_string(_x_x1_12_10385, _ctx); /*string*/
    x_10 = kk_std_os_dir_prim_is_dir(_x_x1250, _ctx); /*bool*/
    kk_unit_t keep_6 = kk_Unit;
    kk_evv_set(w_10,kk_context());
    return x_10;
  }
}


// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileIO_fun1251__t {
  struct kk_function_s _base;
};
static kk_std_core_types__list kk_nagare_io_file__effect_defaultFileIO_fun1251(kk_function_t _fself, kk_string_t p_3, bool recursive, kk_integer_t maxDepth, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileIO_fun1251(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file__effect_defaultFileIO_fun1251, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileIO_fun1253__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1253(kk_function_t _fself, kk_box_t _b_x631, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileIO_fun1253(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file__effect_defaultFileIO_fun1253, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1253(kk_function_t _fself, kk_box_t _b_x631, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_os_path__path _x_x1254;
  kk_string_t _x_x1255 = kk_string_unbox(_b_x631); /*string*/
  _x_x1254 = kk_std_os_path_path(_x_x1255, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x_x1254, _ctx);
}


// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileIO_fun1258__t {
  struct kk_function_s _base;
  kk_ssize_t i_3_10593;
};
static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1258(kk_function_t _fself, kk_function_t _b_x641, kk_box_t _b_x642, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileIO_fun1258(kk_ssize_t i_3_10593, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileIO_fun1258__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect_defaultFileIO_fun1258__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect_defaultFileIO_fun1258, kk_context());
  _self->i_3_10593 = i_3_10593;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileIO_fun1259__t {
  struct kk_function_s _base;
  kk_function_t _b_x641;
};
static kk_std_core_types__list kk_nagare_io_file__effect_defaultFileIO_fun1259(kk_function_t _fself, kk_box_t _b_x643, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileIO_fun1259(kk_function_t _b_x641, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileIO_fun1259__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect_defaultFileIO_fun1259__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect_defaultFileIO_fun1259, kk_context());
  _self->_b_x641 = _b_x641;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_core_types__list kk_nagare_io_file__effect_defaultFileIO_fun1259(kk_function_t _fself, kk_box_t _b_x643, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileIO_fun1259__t* _self = kk_function_as(struct kk_nagare_io_file__effect_defaultFileIO_fun1259__t*, _fself, _ctx);
  kk_function_t _b_x641 = _self->_b_x641; /* (10003) -> 10001 10000 */
  kk_drop_match(_self, {kk_function_dup(_b_x641, _ctx);}, {}, _ctx)
  kk_box_t _x_x1260 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _b_x641, (_b_x641, _b_x643, _ctx), _ctx); /*10000*/
  return kk_std_core_types__list_unbox(_x_x1260, KK_OWNED, _ctx);
}


// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileIO_fun1261__t {
  struct kk_function_s _base;
  kk_function_t _b_x637_717;
};
static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1261(kk_function_t _fself, kk_box_t _b_x639, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileIO_fun1261(kk_function_t _b_x637_717, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileIO_fun1261__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect_defaultFileIO_fun1261__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect_defaultFileIO_fun1261, kk_context());
  _self->_b_x637_717 = _b_x637_717;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1261(kk_function_t _fself, kk_box_t _b_x639, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileIO_fun1261__t* _self = kk_function_as(struct kk_nagare_io_file__effect_defaultFileIO_fun1261__t*, _fself, _ctx);
  kk_function_t _b_x637_717 = _self->_b_x637_717; /* (10013) -> <div,exn,fsys,alloc<global>,console/console,ndet,net,read<global>,ui,write<global>,nagare/io/file_effect/fileRead,nagare/io/file_effect/fileWrite> list<std/os/path/path> */
  kk_drop_match(_self, {kk_function_dup(_b_x637_717, _ctx);}, {}, _ctx)
  kk_std_core_types__list _x_x1262 = kk_function_call(kk_std_core_types__list, (kk_function_t, kk_box_t, kk_context_t*), _b_x637_717, (_b_x637_717, _b_x639, _ctx), _ctx); /*list<std/os/path/path>*/
  return kk_std_core_types__list_box(_x_x1262, _ctx);
}
static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1258(kk_function_t _fself, kk_function_t _b_x641, kk_box_t _b_x642, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileIO_fun1258__t* _self = kk_function_as(struct kk_nagare_io_file__effect_defaultFileIO_fun1258__t*, _fself, _ctx);
  kk_ssize_t i_3_10593 = _self->i_3_10593; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_3_10593, _ctx);}, {}, _ctx)
  kk_function_t cont_3_742 = kk_nagare_io_file__effect_new_defaultFileIO_fun1259(_b_x641, _ctx); /*(10013) -> <div,exn,fsys,alloc<global>,console/console,ndet,net,read<global>,ui,write<global>,nagare/io/file_effect/fileRead,nagare/io/file_effect/fileWrite> list<std/os/path/path>*/;
  kk_box_t res_3_743 = _b_x642; /*10013*/;
  kk_ssize_t _b_x636_716 = i_3_10593; /*hnd/ev-index*/;
  kk_function_t _b_x637_717 = cont_3_742; /*(10013) -> <div,exn,fsys,alloc<global>,console/console,ndet,net,read<global>,ui,write<global>,nagare/io/file_effect/fileRead,nagare/io/file_effect/fileWrite> list<std/os/path/path>*/;
  kk_box_t _b_x638_718 = res_3_743; /*10013*/;
  return kk_std_core_hnd_open_at1(_b_x636_716, kk_nagare_io_file__effect_new_defaultFileIO_fun1261(_b_x637_717, _ctx), _b_x638_718, _ctx);
}


// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileIO_fun1264__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1264(kk_function_t _fself, kk_box_t _b_x646, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileIO_fun1264(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file__effect_defaultFileIO_fun1264, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1264(kk_function_t _fself, kk_box_t _b_x646, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_std_os_path__path _x_x1265;
  kk_string_t _x_x1266 = kk_string_unbox(_b_x646); /*string*/
  _x_x1265 = kk_std_os_path_path(_x_x1266, _ctx); /*std/os/path/path*/
  return kk_std_os_path__path_box(_x_x1265, _ctx);
}


// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileIO_fun1268__t {
  struct kk_function_s _base;
  kk_ssize_t i_4_10597;
};
static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1268(kk_function_t _fself, kk_function_t _b_x654, kk_box_t _b_x655, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileIO_fun1268(kk_ssize_t i_4_10597, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileIO_fun1268__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect_defaultFileIO_fun1268__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect_defaultFileIO_fun1268, kk_context());
  _self->i_4_10597 = i_4_10597;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileIO_fun1269__t {
  struct kk_function_s _base;
  kk_function_t _b_x654;
};
static kk_std_core_types__list kk_nagare_io_file__effect_defaultFileIO_fun1269(kk_function_t _fself, kk_box_t _b_x656, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileIO_fun1269(kk_function_t _b_x654, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileIO_fun1269__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect_defaultFileIO_fun1269__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect_defaultFileIO_fun1269, kk_context());
  _self->_b_x654 = _b_x654;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_std_core_types__list kk_nagare_io_file__effect_defaultFileIO_fun1269(kk_function_t _fself, kk_box_t _b_x656, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileIO_fun1269__t* _self = kk_function_as(struct kk_nagare_io_file__effect_defaultFileIO_fun1269__t*, _fself, _ctx);
  kk_function_t _b_x654 = _self->_b_x654; /* (10003) -> 10001 10000 */
  kk_drop_match(_self, {kk_function_dup(_b_x654, _ctx);}, {}, _ctx)
  kk_box_t _x_x1270 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _b_x654, (_b_x654, _b_x656, _ctx), _ctx); /*10000*/
  return kk_std_core_types__list_unbox(_x_x1270, KK_OWNED, _ctx);
}


// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileIO_fun1271__t {
  struct kk_function_s _base;
  kk_function_t _b_x650_721;
};
static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1271(kk_function_t _fself, kk_box_t _b_x652, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileIO_fun1271(kk_function_t _b_x650_721, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileIO_fun1271__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect_defaultFileIO_fun1271__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect_defaultFileIO_fun1271, kk_context());
  _self->_b_x650_721 = _b_x650_721;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1271(kk_function_t _fself, kk_box_t _b_x652, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileIO_fun1271__t* _self = kk_function_as(struct kk_nagare_io_file__effect_defaultFileIO_fun1271__t*, _fself, _ctx);
  kk_function_t _b_x650_721 = _self->_b_x650_721; /* (10011) -> <exn,fsys,div,alloc<global>,console/console,ndet,net,read<global>,ui,write<global>,nagare/io/file_effect/fileRead,nagare/io/file_effect/fileWrite> list<std/os/path/path> */
  kk_drop_match(_self, {kk_function_dup(_b_x650_721, _ctx);}, {}, _ctx)
  kk_std_core_types__list _x_x1272 = kk_function_call(kk_std_core_types__list, (kk_function_t, kk_box_t, kk_context_t*), _b_x650_721, (_b_x650_721, _b_x652, _ctx), _ctx); /*list<std/os/path/path>*/
  return kk_std_core_types__list_box(_x_x1272, _ctx);
}
static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1268(kk_function_t _fself, kk_function_t _b_x654, kk_box_t _b_x655, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileIO_fun1268__t* _self = kk_function_as(struct kk_nagare_io_file__effect_defaultFileIO_fun1268__t*, _fself, _ctx);
  kk_ssize_t i_4_10597 = _self->i_4_10597; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_4_10597, _ctx);}, {}, _ctx)
  kk_function_t cont_4_744 = kk_nagare_io_file__effect_new_defaultFileIO_fun1269(_b_x654, _ctx); /*(10011) -> <exn,fsys,div,alloc<global>,console/console,ndet,net,read<global>,ui,write<global>,nagare/io/file_effect/fileRead,nagare/io/file_effect/fileWrite> list<std/os/path/path>*/;
  kk_box_t res_4_745 = _b_x655; /*10011*/;
  kk_ssize_t _b_x649_720 = i_4_10597; /*hnd/ev-index*/;
  kk_function_t _b_x650_721 = cont_4_744; /*(10011) -> <exn,fsys,div,alloc<global>,console/console,ndet,net,read<global>,ui,write<global>,nagare/io/file_effect/fileRead,nagare/io/file_effect/fileWrite> list<std/os/path/path>*/;
  kk_box_t _b_x651_722 = res_4_745; /*10011*/;
  return kk_std_core_hnd_open_at1(_b_x649_720, kk_nagare_io_file__effect_new_defaultFileIO_fun1271(_b_x650_721, _ctx), _b_x651_722, _ctx);
}
static kk_std_core_types__list kk_nagare_io_file__effect_defaultFileIO_fun1251(kk_function_t _fself, kk_string_t p_3, bool recursive, kk_integer_t maxDepth, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  if (recursive) {
    kk_std_os_path__path _x_x1_14_10387;
    kk_box_t _x_x1252 = kk_std_core_hnd__open_none1(kk_nagare_io_file__effect_new_defaultFileIO_fun1253(_ctx), kk_string_box(p_3), _ctx); /*10001*/
    _x_x1_14_10387 = kk_std_os_path__path_unbox(_x_x1252, KK_OWNED, _ctx); /*std/os/path/path*/
    kk_ssize_t i_3_10593 = (KK_IZ(0)); /*hnd/ev-index*/;
    kk_evv_t w_11 = kk_evv_swap_create1(i_3_10593,kk_context()); /*hnd/evv<<div,exn,fsys,alloc<global>,console/console,ndet,net,read<global>,ui,write<global>,nagare/io/file_effect/fileRead,nagare/io/file_effect/fileWrite>>*/;
    kk_std_core_types__list y_3;
    kk_std_core_types__optional _x_x1256 = kk_std_core_types__new_Optional(kk_integer_box(maxDepth, _ctx), _ctx); /*? 10003*/
    y_3 = kk_std_os_dir_list_directory_recursive(_x_x1_14_10387, _x_x1256, _ctx); /*list<std/os/path/path>*/
    kk_evv_set(w_11,kk_context());
    if (kk_yielding(kk_context())) {
      kk_std_core_types__list_drop(y_3, _ctx);
      kk_box_t _x_x1257 = kk_std_core_hnd_yield_cont(kk_nagare_io_file__effect_new_defaultFileIO_fun1258(i_3_10593, _ctx), _ctx); /*10002*/
      return kk_std_core_types__list_unbox(_x_x1257, KK_OWNED, _ctx);
    }
    {
      return y_3;
    }
  }
  {
    kk_integer_drop(maxDepth, _ctx);
    kk_std_os_path__path _x_x1_16_10390;
    kk_box_t _x_x1263 = kk_std_core_hnd__open_none1(kk_nagare_io_file__effect_new_defaultFileIO_fun1264(_ctx), kk_string_box(p_3), _ctx); /*10001*/
    _x_x1_16_10390 = kk_std_os_path__path_unbox(_x_x1263, KK_OWNED, _ctx); /*std/os/path/path*/
    kk_ssize_t i_4_10597 = (KK_IZ(0)); /*hnd/ev-index*/;
    kk_evv_t w_12 = kk_evv_swap_create1(i_4_10597,kk_context()); /*hnd/evv<<exn,fsys,div,alloc<global>,console/console,ndet,net,read<global>,ui,write<global>,nagare/io/file_effect/fileRead,nagare/io/file_effect/fileWrite>>*/;
    kk_std_core_types__list y_4 = kk_std_os_dir_list_directory(_x_x1_16_10390, _ctx); /*list<std/os/path/path>*/;
    kk_evv_set(w_12,kk_context());
    if (kk_yielding(kk_context())) {
      kk_std_core_types__list_drop(y_4, _ctx);
      kk_box_t _x_x1267 = kk_std_core_hnd_yield_cont(kk_nagare_io_file__effect_new_defaultFileIO_fun1268(i_4_10597, _ctx), _ctx); /*10002*/
      return kk_std_core_types__list_unbox(_x_x1267, KK_OWNED, _ctx);
    }
    {
      return y_4;
    }
  }
}


// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileIO_fun1273__t {
  struct kk_function_s _base;
};
static kk_unit_t kk_nagare_io_file__effect_defaultFileIO_fun1273(kk_function_t _fself, kk_string_t p_4, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileIO_fun1273(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file__effect_defaultFileIO_fun1273, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}



// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileIO_fun1275__t {
  struct kk_function_s _base;
  kk_ssize_t i_5_10600;
};
static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1275(kk_function_t _fself, kk_function_t _b_x666, kk_box_t _b_x667, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileIO_fun1275(kk_ssize_t i_5_10600, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileIO_fun1275__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect_defaultFileIO_fun1275__t, 1, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect_defaultFileIO_fun1275, kk_context());
  _self->i_5_10600 = i_5_10600;
  return kk_datatype_from_base(&_self->_base, kk_context());
}



// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileIO_fun1276__t {
  struct kk_function_s _base;
  kk_function_t _b_x666;
};
static kk_unit_t kk_nagare_io_file__effect_defaultFileIO_fun1276(kk_function_t _fself, kk_box_t _b_x668, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileIO_fun1276(kk_function_t _b_x666, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileIO_fun1276__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect_defaultFileIO_fun1276__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect_defaultFileIO_fun1276, kk_context());
  _self->_b_x666 = _b_x666;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_unit_t kk_nagare_io_file__effect_defaultFileIO_fun1276(kk_function_t _fself, kk_box_t _b_x668, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileIO_fun1276__t* _self = kk_function_as(struct kk_nagare_io_file__effect_defaultFileIO_fun1276__t*, _fself, _ctx);
  kk_function_t _b_x666 = _self->_b_x666; /* (10003) -> 10001 10000 */
  kk_drop_match(_self, {kk_function_dup(_b_x666, _ctx);}, {}, _ctx)
  kk_box_t _x_x1277 = kk_function_call(kk_box_t, (kk_function_t, kk_box_t, kk_context_t*), _b_x666, (_b_x666, _b_x668, _ctx), _ctx); /*10000*/
  kk_unit_unbox(_x_x1277); return kk_Unit;
}


// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileIO_fun1278__t {
  struct kk_function_s _base;
  kk_function_t _b_x662_726;
};
static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1278(kk_function_t _fself, kk_box_t _b_x664, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileIO_fun1278(kk_function_t _b_x662_726, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileIO_fun1278__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect_defaultFileIO_fun1278__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect_defaultFileIO_fun1278, kk_context());
  _self->_b_x662_726 = _b_x662_726;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1278(kk_function_t _fself, kk_box_t _b_x664, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileIO_fun1278__t* _self = kk_function_as(struct kk_nagare_io_file__effect_defaultFileIO_fun1278__t*, _fself, _ctx);
  kk_function_t _b_x662_726 = _self->_b_x662_726; /* (10011) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>,nagare/io/file_effect/fileRead,nagare/io/file_effect/fileWrite> () */
  kk_drop_match(_self, {kk_function_dup(_b_x662_726, _ctx);}, {}, _ctx)
  kk_unit_t _x_x1279 = kk_Unit;
  kk_function_call(kk_unit_t, (kk_function_t, kk_box_t, kk_context_t*), _b_x662_726, (_b_x662_726, _b_x664, _ctx), _ctx);
  return kk_unit_box(_x_x1279);
}
static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1275(kk_function_t _fself, kk_function_t _b_x666, kk_box_t _b_x667, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileIO_fun1275__t* _self = kk_function_as(struct kk_nagare_io_file__effect_defaultFileIO_fun1275__t*, _fself, _ctx);
  kk_ssize_t i_5_10600 = _self->i_5_10600; /* hnd/ev-index */
  kk_drop_match(_self, {kk_skip_dup(i_5_10600, _ctx);}, {}, _ctx)
  kk_function_t cont_5_746 = kk_nagare_io_file__effect_new_defaultFileIO_fun1276(_b_x666, _ctx); /*(10011) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>,nagare/io/file_effect/fileRead,nagare/io/file_effect/fileWrite> ()*/;
  kk_box_t res_5_747 = _b_x667; /*10011*/;
  kk_ssize_t _b_x661_725 = i_5_10600; /*hnd/ev-index*/;
  kk_function_t _b_x662_726 = cont_5_746; /*(10011) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>,nagare/io/file_effect/fileRead,nagare/io/file_effect/fileWrite> ()*/;
  kk_box_t _b_x663_727 = res_5_747; /*10011*/;
  return kk_std_core_hnd_open_at1(_b_x661_725, kk_nagare_io_file__effect_new_defaultFileIO_fun1278(_b_x662_726, _ctx), _b_x663_727, _ctx);
}
static kk_unit_t kk_nagare_io_file__effect_defaultFileIO_fun1273(kk_function_t _fself, kk_string_t p_4, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  kk_ssize_t i_5_10600 = (KK_IZ(0)); /*hnd/ev-index*/;
  kk_evv_t w_13 = kk_evv_swap_create1(i_5_10600,kk_context()); /*hnd/evv<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>,nagare/io/file_effect/fileRead,nagare/io/file_effect/fileWrite>>*/;
  kk_unit_t y_5 = kk_Unit;
  kk_nagare_io_file__effect_nagare_remove(p_4, _ctx);
  kk_evv_set(w_13,kk_context());
  if (kk_yielding(kk_context())) {
    kk_box_t _x_x1274 = kk_std_core_hnd_yield_cont(kk_nagare_io_file__effect_new_defaultFileIO_fun1275(i_5_10600, _ctx), _ctx); /*10002*/
    kk_unit_unbox(_x_x1274); return kk_Unit;
  }
  {
    y_5; return kk_Unit;
  }
}


// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileIO_fun1282__t {
  struct kk_function_s _base;
  kk_function_t _b_x627_713;
};
static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1282(kk_function_t _fself, kk_box_t _b_x628, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileIO_fun1282(kk_function_t _b_x627_713, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileIO_fun1282__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect_defaultFileIO_fun1282__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect_defaultFileIO_fun1282, kk_context());
  _self->_b_x627_713 = _b_x627_713;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1282(kk_function_t _fself, kk_box_t _b_x628, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileIO_fun1282__t* _self = kk_function_as(struct kk_nagare_io_file__effect_defaultFileIO_fun1282__t*, _fself, _ctx);
  kk_function_t _b_x627_713 = _self->_b_x627_713; /* (p@2 : string) -> <fsys,div,exn,alloc<global>,console/console,ndet,net,read<global>,ui,write<global>,nagare/io/file_effect/fileRead,nagare/io/file_effect/fileWrite> bool */
  kk_drop_match(_self, {kk_function_dup(_b_x627_713, _ctx);}, {}, _ctx)
  bool _x_x1283;
  kk_string_t _x_x1284 = kk_string_unbox(_b_x628); /*string*/
  _x_x1283 = kk_function_call(bool, (kk_function_t, kk_string_t, kk_context_t*), _b_x627_713, (_b_x627_713, _x_x1284, _ctx), _ctx); /*bool*/
  return kk_bool_box(_x_x1283);
}


// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileIO_fun1286__t {
  struct kk_function_s _base;
  kk_function_t _b_x657_714;
};
static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1286(kk_function_t _fself, kk_box_t _b_x658, kk_box_t _b_x659, kk_box_t _b_x660, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileIO_fun1286(kk_function_t _b_x657_714, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileIO_fun1286__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect_defaultFileIO_fun1286__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect_defaultFileIO_fun1286, kk_context());
  _self->_b_x657_714 = _b_x657_714;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1286(kk_function_t _fself, kk_box_t _b_x658, kk_box_t _b_x659, kk_box_t _b_x660, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileIO_fun1286__t* _self = kk_function_as(struct kk_nagare_io_file__effect_defaultFileIO_fun1286__t*, _fself, _ctx);
  kk_function_t _b_x657_714 = _self->_b_x657_714; /* (p@3 : string, recursive : bool, maxDepth : int) -> <fsys,div,exn,alloc<global>,console/console,ndet,net,read<global>,ui,write<global>,nagare/io/file_effect/fileRead,nagare/io/file_effect/fileWrite> list<std/os/path/path> */
  kk_drop_match(_self, {kk_function_dup(_b_x657_714, _ctx);}, {}, _ctx)
  kk_std_core_types__list _x_x1287;
  kk_string_t _x_x1288 = kk_string_unbox(_b_x658); /*string*/
  bool _x_x1289 = kk_bool_unbox(_b_x659); /*bool*/
  kk_integer_t _x_x1290 = kk_integer_unbox(_b_x660, _ctx); /*int*/
  _x_x1287 = kk_function_call(kk_std_core_types__list, (kk_function_t, kk_string_t, bool, kk_integer_t, kk_context_t*), _b_x657_714, (_b_x657_714, _x_x1288, _x_x1289, _x_x1290, _ctx), _ctx); /*list<std/os/path/path>*/
  return kk_std_core_types__list_box(_x_x1287, _ctx);
}


// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileIO_fun1292__t {
  struct kk_function_s _base;
  kk_function_t _b_x669_723;
};
static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1292(kk_function_t _fself, kk_box_t _b_x670, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileIO_fun1292(kk_function_t _b_x669_723, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileIO_fun1292__t* _self = kk_function_alloc_as(struct kk_nagare_io_file__effect_defaultFileIO_fun1292__t, 2, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file__effect_defaultFileIO_fun1292, kk_context());
  _self->_b_x669_723 = _b_x669_723;
  return kk_datatype_from_base(&_self->_base, kk_context());
}

static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1292(kk_function_t _fself, kk_box_t _b_x670, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileIO_fun1292__t* _self = kk_function_as(struct kk_nagare_io_file__effect_defaultFileIO_fun1292__t*, _fself, _ctx);
  kk_function_t _b_x669_723 = _self->_b_x669_723; /* (p@4 : string) -> <div,exn,fsys,alloc<global>,console/console,ndet,net,read<global>,ui,write<global>,nagare/io/file_effect/fileRead,nagare/io/file_effect/fileWrite> () */
  kk_drop_match(_self, {kk_function_dup(_b_x669_723, _ctx);}, {}, _ctx)
  kk_unit_t _x_x1293 = kk_Unit;
  kk_string_t _x_x1294 = kk_string_unbox(_b_x670); /*string*/
  kk_function_call(kk_unit_t, (kk_function_t, kk_string_t, kk_context_t*), _b_x669_723, (_b_x669_723, _x_x1294, _ctx), _ctx);
  return kk_unit_box(_x_x1293);
}


// lift anonymous function
struct kk_nagare_io_file__effect_defaultFileIO_fun1295__t {
  struct kk_function_s _base;
};
static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1295(kk_function_t _fself, kk_box_t _res_1, kk_context_t* _ctx);
static kk_function_t kk_nagare_io_file__effect_new_defaultFileIO_fun1295(kk_context_t* _ctx) {
  kk_define_static_function(_fself, kk_nagare_io_file__effect_defaultFileIO_fun1295, _ctx)
  return kk_function_static_dup(_fself,kk_context());
}

static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1295(kk_function_t _fself, kk_box_t _res_1, kk_context_t* _ctx) {
  kk_function_static_drop(_fself,kk_context());
  return _res_1;
}
static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1237(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileIO_fun1237__t* _self = kk_function_as(struct kk_nagare_io_file__effect_defaultFileIO_fun1237__t*, _fself, _ctx);
  kk_function_t action = _self->action; /* () -> <nagare/io/file_effect/fileIO|io> 3358 */
  kk_drop_match(_self, {kk_function_dup(action, _ctx);}, {}, _ctx)
  kk_function_t _b_x627_713 = kk_nagare_io_file__effect_new_defaultFileIO_fun1238(_ctx); /*(p@2 : string) -> <fsys,div,exn,alloc<global>,console/console,ndet,net,read<global>,ui,write<global>,nagare/io/file_effect/fileRead,nagare/io/file_effect/fileWrite> bool*/;
  kk_function_t _b_x657_714 = kk_nagare_io_file__effect_new_defaultFileIO_fun1251(_ctx); /*(p@3 : string, recursive : bool, maxDepth : int) -> <fsys,div,exn,alloc<global>,console/console,ndet,net,read<global>,ui,write<global>,nagare/io/file_effect/fileRead,nagare/io/file_effect/fileWrite> list<std/os/path/path>*/;
  kk_function_t _b_x669_723 = kk_nagare_io_file__effect_new_defaultFileIO_fun1273(_ctx); /*(p@4 : string) -> <div,exn,fsys,alloc<global>,console/console,ndet,net,read<global>,ui,write<global>,nagare/io/file_effect/fileRead,nagare/io/file_effect/fileWrite> ()*/;
  kk_nagare_io_file__effect__fileSystem _x_x1280;
  kk_std_core_hnd__clause1 _x_x1281 = kk_std_core_hnd_clause_tail1(kk_nagare_io_file__effect_new_defaultFileIO_fun1282(_b_x627_713, _ctx), _ctx); /*hnd/clause1<10003,10004,10002,10000,10001>*/
  kk_std_core_hnd__clause1 _x_x1285 = kk_std_core_hnd_clause_tail3(kk_nagare_io_file__effect_new_defaultFileIO_fun1286(_b_x657_714, _ctx), _ctx); /*hnd/clause1<(10003, 10004, 10005),10006,10002,10000,10001>*/
  kk_std_core_hnd__clause1 _x_x1291 = kk_std_core_hnd_clause_tail1(kk_nagare_io_file__effect_new_defaultFileIO_fun1292(_b_x669_723, _ctx), _ctx); /*hnd/clause1<10003,10004,10002,10000,10001>*/
  _x_x1280 = kk_nagare_io_file__effect__new_Hnd_fileSystem(kk_reuse_null, 0, kk_integer_from_small(1), _x_x1281, _x_x1285, _x_x1291, _ctx); /*nagare/io/file_effect/fileSystem<53,54>*/
  return kk_nagare_io_file__effect_fileSystem_fs__handle(_x_x1280, kk_nagare_io_file__effect_new_defaultFileIO_fun1295(_ctx), action, _ctx);
}
static kk_box_t kk_nagare_io_file__effect_defaultFileIO_fun1179(kk_function_t _fself, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect_defaultFileIO_fun1179__t* _self = kk_function_as(struct kk_nagare_io_file__effect_defaultFileIO_fun1179__t*, _fself, _ctx);
  kk_function_t action = _self->action; /* () -> <nagare/io/file_effect/fileIO|io> 3358 */
  kk_drop_match(_self, {kk_function_dup(action, _ctx);}, {}, _ctx)
  kk_function_t _b_x559_687 = kk_nagare_io_file__effect_new_defaultFileIO_fun1180(_ctx); /*(h@2 : nagare/io/file_effect/write-handle) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>,nagare/io/file_effect/fileRead> ()*/;
  kk_function_t _b_x577_692 = kk_nagare_io_file__effect_new_defaultFileIO_fun1188(_ctx); /*(p@1 : string) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>,nagare/io/file_effect/fileRead> nagare/io/file_effect/write-handle*/;
  kk_function_t _b_x593_695 = kk_nagare_io_file__effect_new_defaultFileIO_fun1195(_ctx); /*(m@1 : hnd/marker<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>,nagare/io/file_effect/fileRead>,3358>, ev@1 : hnd/ev<nagare/io/file_effect/fileWrite>, x1@5 : nagare/io/file_effect/write-handle, x2@1 : string) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>,nagare/io/file_effect/fileRead> int*/;
  kk_function_t _b_x612_704 = kk_nagare_io_file__effect_new_defaultFileIO_fun1206(_ctx); /*(m@2 : hnd/marker<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>,nagare/io/file_effect/fileRead>,3358>, ev@2 : hnd/ev<nagare/io/file_effect/fileWrite>, x1@8 : nagare/io/file_effect/write-handle, x2@3 : vector<int8>) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>,nagare/io/file_effect/fileRead> int*/;
  kk_nagare_io_file__effect__fileWrite _x_x1217;
  kk_std_core_hnd__clause1 _x_x1218 = kk_std_core_hnd_clause_tail1(kk_nagare_io_file__effect_new_defaultFileIO_fun1219(_b_x559_687, _ctx), _ctx); /*hnd/clause1<10003,10004,10002,10000,10001>*/
  kk_std_core_hnd__clause1 _x_x1222 = kk_std_core_hnd_clause_tail1(kk_nagare_io_file__effect_new_defaultFileIO_fun1223(_b_x577_692, _ctx), _ctx); /*hnd/clause1<10003,10004,10002,10000,10001>*/
  kk_std_core_hnd__clause2 _x_x1226 = kk_std_core_hnd__new_Clause2(kk_nagare_io_file__effect_new_defaultFileIO_fun1227(_b_x593_695, _ctx), _ctx); /*hnd/clause2<10021,10022,10023,10024,10025,10026>*/
  kk_std_core_hnd__clause2 _x_x1231 = kk_std_core_hnd__new_Clause2(kk_nagare_io_file__effect_new_defaultFileIO_fun1232(_b_x612_704, _ctx), _ctx); /*hnd/clause2<10021,10022,10023,10024,10025,10026>*/
  _x_x1217 = kk_nagare_io_file__effect__new_Hnd_fileWrite(kk_reuse_null, 0, kk_integer_from_small(1), _x_x1218, _x_x1222, _x_x1226, _x_x1231, _ctx); /*nagare/io/file_effect/fileWrite<81,82>*/
  return kk_nagare_io_file__effect_fileWrite_fs__handle(_x_x1217, kk_nagare_io_file__effect_new_defaultFileIO_fun1236(_ctx), kk_nagare_io_file__effect_new_defaultFileIO_fun1237(action, _ctx), _ctx);
}

kk_box_t kk_nagare_io_file__effect_defaultFileIO(kk_function_t action, kk_context_t* _ctx) { /* forall<a> (action : () -> <fileIO|io> a) -> io a */ 
  kk_function_t _b_x518_671 = kk_nagare_io_file__effect_new_defaultFileIO_fun1132(_ctx); /*(h : nagare/io/file_effect/read-handle) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> ()*/;
  kk_function_t _b_x522_672 = kk_nagare_io_file__effect_new_defaultFileIO_fun1134(_ctx); /*(p : string) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> nagare/io/file_effect/read-handle*/;
  kk_function_t _b_x530_674 = kk_nagare_io_file__effect_new_defaultFileIO_fun1139(_ctx); /*(m : hnd/marker<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>,3358>, ev : hnd/ev<nagare/io/file_effect/fileRead>, x1@0 : nagare/io/file_effect/read-handle, x2 : int) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> string*/;
  kk_function_t _b_x541_679 = kk_nagare_io_file__effect_new_defaultFileIO_fun1144(_ctx); /*(m@0 : hnd/marker<<alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>>,3358>, ev@0 : hnd/ev<nagare/io/file_effect/fileRead>, x1@2 : nagare/io/file_effect/read-handle, x2@0 : int) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> vector<int8>*/;
  kk_function_t _b_x549_684 = kk_nagare_io_file__effect_new_defaultFileIO_fun1149(_ctx); /*(p@0 : string) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> string*/;
  kk_nagare_io_file__effect__fileRead _x_x1155;
  kk_std_core_hnd__clause1 _x_x1156 = kk_std_core_hnd_clause_tail1(kk_nagare_io_file__effect_new_defaultFileIO_fun1157(_b_x518_671, _ctx), _ctx); /*hnd/clause1<10003,10004,10002,10000,10001>*/
  kk_std_core_hnd__clause1 _x_x1160 = kk_std_core_hnd_clause_tail1(kk_nagare_io_file__effect_new_defaultFileIO_fun1161(_b_x522_672, _ctx), _ctx); /*hnd/clause1<10003,10004,10002,10000,10001>*/
  kk_std_core_hnd__clause2 _x_x1164 = kk_std_core_hnd__new_Clause2(kk_nagare_io_file__effect_new_defaultFileIO_fun1165(_b_x530_674, _ctx), _ctx); /*hnd/clause2<10021,10022,10023,10024,10025,10026>*/
  kk_std_core_hnd__clause2 _x_x1169 = kk_std_core_hnd__new_Clause2(kk_nagare_io_file__effect_new_defaultFileIO_fun1170(_b_x541_679, _ctx), _ctx); /*hnd/clause2<10021,10022,10023,10024,10025,10026>*/
  kk_std_core_hnd__clause1 _x_x1174 = kk_std_core_hnd_clause_tail1(kk_nagare_io_file__effect_new_defaultFileIO_fun1175(_b_x549_684, _ctx), _ctx); /*hnd/clause1<10003,10004,10002,10000,10001>*/
  _x_x1155 = kk_nagare_io_file__effect__new_Hnd_fileRead(kk_reuse_null, 0, kk_integer_from_small(1), _x_x1156, _x_x1160, _x_x1164, _x_x1169, _x_x1174, _ctx); /*nagare/io/file_effect/fileRead<31,32>*/
  return kk_nagare_io_file__effect_fileRead_fs__handle(_x_x1155, kk_nagare_io_file__effect_new_defaultFileIO_fun1178(_ctx), kk_nagare_io_file__effect_new_defaultFileIO_fun1179(action, _ctx), _ctx);
}

// initialization
void kk_nagare_io_file__effect__init(kk_context_t* _ctx){
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
  #if defined(KK_CUSTOM_INIT)
    KK_CUSTOM_INIT (_ctx);
  #endif
  {
    kk_string_t _x_x811;
    kk_define_string_literal(static, _s_x812, 20, "fileRead@file_effect", _ctx)
    _x_x811 = kk_string_dup(_s_x812, _ctx); /*string*/
    kk_nagare_io_file__effect_fileRead_fs__tag = kk_std_core_hnd__new_Htag(_x_x811, _ctx); /*hnd/htag<nagare/io/file_effect/fileRead>*/
  }
  {
    kk_string_t _x_x840;
    kk_define_string_literal(static, _s_x841, 21, "fileWrite@file_effect", _ctx)
    _x_x840 = kk_string_dup(_s_x841, _ctx); /*string*/
    kk_nagare_io_file__effect_fileWrite_fs__tag = kk_std_core_hnd__new_Htag(_x_x840, _ctx); /*hnd/htag<nagare/io/file_effect/fileWrite>*/
  }
  {
    kk_string_t _x_x864;
    kk_define_string_literal(static, _s_x865, 22, "fileSystem@file_effect", _ctx)
    _x_x864 = kk_string_dup(_s_x865, _ctx); /*string*/
    kk_nagare_io_file__effect_fileSystem_fs__tag = kk_std_core_hnd__new_Htag(_x_x864, _ctx); /*hnd/htag<nagare/io/file_effect/fileSystem>*/
  }
}

// termination
void kk_nagare_io_file__effect__done(kk_context_t* _ctx){
  static bool _kk_done = false;
  if (_kk_done) return;
  _kk_done = true;
  #if defined(KK_CUSTOM_DONE)
    KK_CUSTOM_DONE (_ctx);
  #endif
  kk_std_core_hnd__htag_drop(kk_nagare_io_file__effect_fileSystem_fs__tag, _ctx);
  kk_std_core_hnd__htag_drop(kk_nagare_io_file__effect_fileWrite_fs__tag, _ctx);
  kk_std_core_hnd__htag_drop(kk_nagare_io_file__effect_fileRead_fs__tag, _ctx);
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
