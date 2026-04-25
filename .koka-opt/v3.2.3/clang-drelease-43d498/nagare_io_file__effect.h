#pragma once
#ifndef kk_nagare_io_file__effect_H
#define kk_nagare_io_file__effect_H
// Koka generated module: nagare/io/file_effect, koka version: 3.2.3, platform: 64-bit
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
#include "std_os_path.h"
#include "std_os_dir.h"
#include "std_os_file.h"
#include "nagare_core_types.h"

// type declarations

// value type nagare/io/file_effect/read-handle
struct kk_nagare_io_file__effect_ReadHandle {
  intptr_t fd;
};
typedef struct kk_nagare_io_file__effect_ReadHandle kk_nagare_io_file__effect__read_handle;
static inline kk_nagare_io_file__effect__read_handle kk_nagare_io_file__effect__new_ReadHandle(intptr_t fd, kk_context_t* _ctx) {
  kk_nagare_io_file__effect__read_handle _con = { fd };
  return _con;
}
static inline bool kk_nagare_io_file__effect__is_ReadHandle(kk_nagare_io_file__effect__read_handle x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_nagare_io_file__effect__read_handle kk_nagare_io_file__effect__read_handle_dup(kk_nagare_io_file__effect__read_handle _x, kk_context_t* _ctx) {
  kk_skip_dup(_x.fd, _ctx);
  return _x;
}
static inline void kk_nagare_io_file__effect__read_handle_drop(kk_nagare_io_file__effect__read_handle _x, kk_context_t* _ctx) {
  kk_skip_drop(_x.fd, _ctx);
}
static inline kk_box_t kk_nagare_io_file__effect__read_handle_box(kk_nagare_io_file__effect__read_handle _x, kk_context_t* _ctx) {
  return kk_intptr_box(_x.fd, _ctx);
}
static inline kk_nagare_io_file__effect__read_handle kk_nagare_io_file__effect__read_handle_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_nagare_io_file__effect__new_ReadHandle(kk_intptr_unbox(_x, _borrow, _ctx), _ctx);
}

// type nagare/io/file_effect/fileRead
struct kk_nagare_io_file__effect__fileRead_s {
  kk_block_t _block;
};
typedef kk_datatype_ptr_t kk_nagare_io_file__effect__fileRead;
struct kk_nagare_io_file__effect__Hnd_fileRead {
  struct kk_nagare_io_file__effect__fileRead_s _base;
  kk_integer_t _cfc;
  kk_std_core_hnd__clause1 _fun_closeRead;
  kk_std_core_hnd__clause1 _fun_openRead;
  kk_std_core_hnd__clause2 _fun_readChunk;
  kk_std_core_hnd__clause2 _fun_readChunkBytes;
  kk_std_core_hnd__clause1 _fun_readTextFileOp;
};
static inline kk_nagare_io_file__effect__fileRead kk_nagare_io_file__effect__base_Hnd_fileRead(struct kk_nagare_io_file__effect__Hnd_fileRead* _x, kk_context_t* _ctx) {
  return kk_datatype_from_base(&_x->_base, _ctx);
}
static inline kk_nagare_io_file__effect__fileRead kk_nagare_io_file__effect__new_Hnd_fileRead(kk_reuse_t _at, int32_t _cpath, kk_integer_t _cfc, kk_std_core_hnd__clause1 _fun_closeRead, kk_std_core_hnd__clause1 _fun_openRead, kk_std_core_hnd__clause2 _fun_readChunk, kk_std_core_hnd__clause2 _fun_readChunkBytes, kk_std_core_hnd__clause1 _fun_readTextFileOp, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect__Hnd_fileRead* _con = kk_block_alloc_at_as(struct kk_nagare_io_file__effect__Hnd_fileRead, _at, 6 /* scan count */, _cpath, (kk_tag_t)(1), _ctx);
  _con->_cfc = _cfc;
  _con->_fun_closeRead = _fun_closeRead;
  _con->_fun_openRead = _fun_openRead;
  _con->_fun_readChunk = _fun_readChunk;
  _con->_fun_readChunkBytes = _fun_readChunkBytes;
  _con->_fun_readTextFileOp = _fun_readTextFileOp;
  return kk_nagare_io_file__effect__base_Hnd_fileRead(_con, _ctx);
}
static inline struct kk_nagare_io_file__effect__Hnd_fileRead* kk_nagare_io_file__effect__as_Hnd_fileRead(kk_nagare_io_file__effect__fileRead x, kk_context_t* _ctx) {
  return kk_datatype_as_assert(struct kk_nagare_io_file__effect__Hnd_fileRead*, x, (kk_tag_t)(1), _ctx);
}
static inline bool kk_nagare_io_file__effect__is_Hnd_fileRead(kk_nagare_io_file__effect__fileRead x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_nagare_io_file__effect__fileRead kk_nagare_io_file__effect__fileRead_dup(kk_nagare_io_file__effect__fileRead _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_dup(_x, _ctx);
}
static inline void kk_nagare_io_file__effect__fileRead_drop(kk_nagare_io_file__effect__fileRead _x, kk_context_t* _ctx) {
  kk_datatype_ptr_drop(_x, _ctx);
}
static inline kk_box_t kk_nagare_io_file__effect__fileRead_box(kk_nagare_io_file__effect__fileRead _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_box(_x);
}
static inline kk_nagare_io_file__effect__fileRead kk_nagare_io_file__effect__fileRead_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_datatype_ptr_unbox(_x);
}

// type nagare/io/file_effect/fileSystem
struct kk_nagare_io_file__effect__fileSystem_s {
  kk_block_t _block;
};
typedef kk_datatype_ptr_t kk_nagare_io_file__effect__fileSystem;
struct kk_nagare_io_file__effect__Hnd_fileSystem {
  struct kk_nagare_io_file__effect__fileSystem_s _base;
  kk_integer_t _cfc;
  kk_std_core_hnd__clause1 _fun_fileExistsOp;
  kk_std_core_hnd__clause1 _fun_listChildren;
  kk_std_core_hnd__clause1 _fun_removeFileOp;
};
static inline kk_nagare_io_file__effect__fileSystem kk_nagare_io_file__effect__base_Hnd_fileSystem(struct kk_nagare_io_file__effect__Hnd_fileSystem* _x, kk_context_t* _ctx) {
  return kk_datatype_from_base(&_x->_base, _ctx);
}
static inline kk_nagare_io_file__effect__fileSystem kk_nagare_io_file__effect__new_Hnd_fileSystem(kk_reuse_t _at, int32_t _cpath, kk_integer_t _cfc, kk_std_core_hnd__clause1 _fun_fileExistsOp, kk_std_core_hnd__clause1 _fun_listChildren, kk_std_core_hnd__clause1 _fun_removeFileOp, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect__Hnd_fileSystem* _con = kk_block_alloc_at_as(struct kk_nagare_io_file__effect__Hnd_fileSystem, _at, 4 /* scan count */, _cpath, (kk_tag_t)(1), _ctx);
  _con->_cfc = _cfc;
  _con->_fun_fileExistsOp = _fun_fileExistsOp;
  _con->_fun_listChildren = _fun_listChildren;
  _con->_fun_removeFileOp = _fun_removeFileOp;
  return kk_nagare_io_file__effect__base_Hnd_fileSystem(_con, _ctx);
}
static inline struct kk_nagare_io_file__effect__Hnd_fileSystem* kk_nagare_io_file__effect__as_Hnd_fileSystem(kk_nagare_io_file__effect__fileSystem x, kk_context_t* _ctx) {
  return kk_datatype_as_assert(struct kk_nagare_io_file__effect__Hnd_fileSystem*, x, (kk_tag_t)(1), _ctx);
}
static inline bool kk_nagare_io_file__effect__is_Hnd_fileSystem(kk_nagare_io_file__effect__fileSystem x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_nagare_io_file__effect__fileSystem kk_nagare_io_file__effect__fileSystem_dup(kk_nagare_io_file__effect__fileSystem _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_dup(_x, _ctx);
}
static inline void kk_nagare_io_file__effect__fileSystem_drop(kk_nagare_io_file__effect__fileSystem _x, kk_context_t* _ctx) {
  kk_datatype_ptr_drop(_x, _ctx);
}
static inline kk_box_t kk_nagare_io_file__effect__fileSystem_box(kk_nagare_io_file__effect__fileSystem _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_box(_x);
}
static inline kk_nagare_io_file__effect__fileSystem kk_nagare_io_file__effect__fileSystem_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_datatype_ptr_unbox(_x);
}

// value type nagare/io/file_effect/write-handle
struct kk_nagare_io_file__effect_WriteHandle {
  intptr_t fd;
};
typedef struct kk_nagare_io_file__effect_WriteHandle kk_nagare_io_file__effect__write_handle;
static inline kk_nagare_io_file__effect__write_handle kk_nagare_io_file__effect__new_WriteHandle(intptr_t fd, kk_context_t* _ctx) {
  kk_nagare_io_file__effect__write_handle _con = { fd };
  return _con;
}
static inline bool kk_nagare_io_file__effect__is_WriteHandle(kk_nagare_io_file__effect__write_handle x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_nagare_io_file__effect__write_handle kk_nagare_io_file__effect__write_handle_dup(kk_nagare_io_file__effect__write_handle _x, kk_context_t* _ctx) {
  kk_skip_dup(_x.fd, _ctx);
  return _x;
}
static inline void kk_nagare_io_file__effect__write_handle_drop(kk_nagare_io_file__effect__write_handle _x, kk_context_t* _ctx) {
  kk_skip_drop(_x.fd, _ctx);
}
static inline kk_box_t kk_nagare_io_file__effect__write_handle_box(kk_nagare_io_file__effect__write_handle _x, kk_context_t* _ctx) {
  return kk_intptr_box(_x.fd, _ctx);
}
static inline kk_nagare_io_file__effect__write_handle kk_nagare_io_file__effect__write_handle_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_nagare_io_file__effect__new_WriteHandle(kk_intptr_unbox(_x, _borrow, _ctx), _ctx);
}

// type nagare/io/file_effect/fileWrite
struct kk_nagare_io_file__effect__fileWrite_s {
  kk_block_t _block;
};
typedef kk_datatype_ptr_t kk_nagare_io_file__effect__fileWrite;
struct kk_nagare_io_file__effect__Hnd_fileWrite {
  struct kk_nagare_io_file__effect__fileWrite_s _base;
  kk_integer_t _cfc;
  kk_std_core_hnd__clause1 _fun_closeWrite;
  kk_std_core_hnd__clause1 _fun_openWrite;
  kk_std_core_hnd__clause2 _fun_writeChunk;
  kk_std_core_hnd__clause2 _fun_writeChunkBytes;
};
static inline kk_nagare_io_file__effect__fileWrite kk_nagare_io_file__effect__base_Hnd_fileWrite(struct kk_nagare_io_file__effect__Hnd_fileWrite* _x, kk_context_t* _ctx) {
  return kk_datatype_from_base(&_x->_base, _ctx);
}
static inline kk_nagare_io_file__effect__fileWrite kk_nagare_io_file__effect__new_Hnd_fileWrite(kk_reuse_t _at, int32_t _cpath, kk_integer_t _cfc, kk_std_core_hnd__clause1 _fun_closeWrite, kk_std_core_hnd__clause1 _fun_openWrite, kk_std_core_hnd__clause2 _fun_writeChunk, kk_std_core_hnd__clause2 _fun_writeChunkBytes, kk_context_t* _ctx) {
  struct kk_nagare_io_file__effect__Hnd_fileWrite* _con = kk_block_alloc_at_as(struct kk_nagare_io_file__effect__Hnd_fileWrite, _at, 5 /* scan count */, _cpath, (kk_tag_t)(1), _ctx);
  _con->_cfc = _cfc;
  _con->_fun_closeWrite = _fun_closeWrite;
  _con->_fun_openWrite = _fun_openWrite;
  _con->_fun_writeChunk = _fun_writeChunk;
  _con->_fun_writeChunkBytes = _fun_writeChunkBytes;
  return kk_nagare_io_file__effect__base_Hnd_fileWrite(_con, _ctx);
}
static inline struct kk_nagare_io_file__effect__Hnd_fileWrite* kk_nagare_io_file__effect__as_Hnd_fileWrite(kk_nagare_io_file__effect__fileWrite x, kk_context_t* _ctx) {
  return kk_datatype_as_assert(struct kk_nagare_io_file__effect__Hnd_fileWrite*, x, (kk_tag_t)(1), _ctx);
}
static inline bool kk_nagare_io_file__effect__is_Hnd_fileWrite(kk_nagare_io_file__effect__fileWrite x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_nagare_io_file__effect__fileWrite kk_nagare_io_file__effect__fileWrite_dup(kk_nagare_io_file__effect__fileWrite _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_dup(_x, _ctx);
}
static inline void kk_nagare_io_file__effect__fileWrite_drop(kk_nagare_io_file__effect__fileWrite _x, kk_context_t* _ctx) {
  kk_datatype_ptr_drop(_x, _ctx);
}
static inline kk_box_t kk_nagare_io_file__effect__fileWrite_box(kk_nagare_io_file__effect__fileWrite _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_box(_x);
}
static inline kk_nagare_io_file__effect__fileWrite kk_nagare_io_file__effect__fileWrite_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_datatype_ptr_unbox(_x);
}

// value declarations

intptr_t kk_nagare_io_file__effect_nagare_fopen_read(kk_string_t p, kk_context_t* _ctx); /* (p : string) -> io intptr_t */ 

intptr_t kk_nagare_io_file__effect_nagare_fopen_write(kk_string_t p, kk_context_t* _ctx); /* (p : string) -> io intptr_t */ 

kk_string_t kk_nagare_io_file__effect_nagare_fread_chunk(intptr_t h, kk_integer_t size, kk_context_t* _ctx); /* (h : intptr_t, size : int) -> io string */ 

kk_vector_t kk_nagare_io_file__effect_nagare_fread_chunk_bytes(intptr_t h, kk_integer_t size, kk_context_t* _ctx); /* (h : intptr_t, size : int) -> io vector<int8> */ 

kk_integer_t kk_nagare_io_file__effect_nagare_fwrite_chunk(intptr_t h, kk_string_t content, kk_context_t* _ctx); /* (h : intptr_t, content : string) -> io int */ 

kk_integer_t kk_nagare_io_file__effect_nagare_fwrite_chunk_bytes(intptr_t h, kk_vector_t content, kk_context_t* _ctx); /* (h : intptr_t, content : vector<int8>) -> io int */ 

kk_unit_t kk_nagare_io_file__effect_nagare_fclose(intptr_t h, kk_context_t* _ctx); /* (h : intptr_t) -> io () */ 

kk_unit_t kk_nagare_io_file__effect_nagare_remove(kk_string_t p, kk_context_t* _ctx); /* (p : string) -> io () */ 

kk_string_t kk_nagare_io_file__effect_nagare_bytes_to_string(kk_vector_t v, kk_context_t* _ctx); /* (v : vector<int8>) -> string */ 

kk_vector_t kk_nagare_io_file__effect_nagare_string_to_bytes(kk_string_t s, kk_context_t* _ctx); /* (s : string) -> vector<int8> */ 
 
// Automatically generated. Retrieves the `fd` constructor field of the `:read-handle` type.

static inline intptr_t kk_nagare_io_file__effect_read_handle_fs_fd(kk_nagare_io_file__effect__read_handle _this, kk_context_t* _ctx) { /* (read-handle) -> intptr_t */ 
  {
    intptr_t _x = _this.fd;
    return _x;
  }
}

static inline kk_nagare_io_file__effect__read_handle kk_nagare_io_file__effect_read_handle_fs__copy(kk_nagare_io_file__effect__read_handle _this, kk_std_core_types__optional fd, kk_context_t* _ctx) { /* (read-handle, fd : ? intptr_t) -> read-handle */ 
  intptr_t _x_x808;
  if (kk_std_core_types__is_Optional(fd, _ctx)) {
    kk_box_t _box_x0 = fd._cons._Optional.value;
    intptr_t _uniq_fd_521 = kk_intptr_unbox(_box_x0, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(fd, _ctx);
    _x_x808 = _uniq_fd_521; /*intptr_t*/
  }
  else {
    kk_std_core_types__optional_drop(fd, _ctx);
    {
      intptr_t _x = _this.fd;
      _x_x808 = _x; /*intptr_t*/
    }
  }
  return kk_nagare_io_file__effect__new_ReadHandle(_x_x808, _ctx);
}
 
// Automatically generated. Retrieves the `fd` constructor field of the `:write-handle` type.

static inline intptr_t kk_nagare_io_file__effect_write_handle_fs_fd(kk_nagare_io_file__effect__write_handle _this, kk_context_t* _ctx) { /* (write-handle) -> intptr_t */ 
  {
    intptr_t _x = _this.fd;
    return _x;
  }
}

static inline kk_nagare_io_file__effect__write_handle kk_nagare_io_file__effect_write_handle_fs__copy(kk_nagare_io_file__effect__write_handle _this, kk_std_core_types__optional fd, kk_context_t* _ctx) { /* (write-handle, fd : ? intptr_t) -> write-handle */ 
  intptr_t _x_x809;
  if (kk_std_core_types__is_Optional(fd, _ctx)) {
    kk_box_t _box_x1 = fd._cons._Optional.value;
    intptr_t _uniq_fd_545 = kk_intptr_unbox(_box_x1, KK_BORROWED, _ctx);
    kk_std_core_types__optional_drop(fd, _ctx);
    _x_x809 = _uniq_fd_545; /*intptr_t*/
  }
  else {
    kk_std_core_types__optional_drop(fd, _ctx);
    {
      intptr_t _x = _this.fd;
      _x_x809 = _x; /*intptr_t*/
    }
  }
  return kk_nagare_io_file__effect__new_WriteHandle(_x_x809, _ctx);
}
 
// Automatically generated. Retrieves the `@cfc` constructor field of the `:fileRead` type.

static inline kk_integer_t kk_nagare_io_file__effect_fileRead_fs__cfc(kk_nagare_io_file__effect__fileRead fileRead, kk_context_t* _ctx) { /* forall<e,a> (fileRead : fileRead<e,a>) -> int */ 
  {
    struct kk_nagare_io_file__effect__Hnd_fileRead* _con_x810 = kk_nagare_io_file__effect__as_Hnd_fileRead(fileRead, _ctx);
    kk_integer_t _x = _con_x810->_cfc;
    return kk_integer_dup(_x, _ctx);
  }
}

extern kk_std_core_hnd__htag kk_nagare_io_file__effect_fileRead_fs__tag;

kk_box_t kk_nagare_io_file__effect_fileRead_fs__handle(kk_nagare_io_file__effect__fileRead hnd, kk_function_t ret, kk_function_t action, kk_context_t* _ctx); /* forall<a,e,b> (hnd : fileRead<e,b>, ret : (res : a) -> e b, action : () -> <fileRead|e> a) -> e b */ 
 
// Automatically generated. Retrieves the `@fun-openRead` constructor field of the `:fileRead` type.

static inline kk_std_core_hnd__clause1 kk_nagare_io_file__effect_fileRead_fs__fun_openRead(kk_nagare_io_file__effect__fileRead fileRead, kk_context_t* _ctx) { /* forall<e,a> (fileRead : fileRead<e,a>) -> hnd/clause1<string,read-handle,fileRead,e,a> */ 
  {
    struct kk_nagare_io_file__effect__Hnd_fileRead* _con_x814 = kk_nagare_io_file__effect__as_Hnd_fileRead(fileRead, _ctx);
    kk_std_core_hnd__clause1 _x = _con_x814->_fun_openRead;
    return kk_std_core_hnd__clause1_dup(_x, _ctx);
  }
}
 
// select `openRead` operation out of effect `:fileRead`

static inline kk_std_core_hnd__clause1 kk_nagare_io_file__effect_openRead_fs__select(kk_nagare_io_file__effect__fileRead hnd, kk_context_t* _ctx) { /* forall<e,a> (hnd : fileRead<e,a>) -> hnd/clause1<string,read-handle,fileRead,e,a> */ 
  {
    struct kk_nagare_io_file__effect__Hnd_fileRead* _con_x815 = kk_nagare_io_file__effect__as_Hnd_fileRead(hnd, _ctx);
    kk_std_core_hnd__clause1 _fun_openRead = _con_x815->_fun_openRead;
    return kk_std_core_hnd__clause1_dup(_fun_openRead, _ctx);
  }
}
 
// Call the `fun openRead` operation of the effect `:fileRead`

static inline kk_nagare_io_file__effect__read_handle kk_nagare_io_file__effect_openRead(kk_string_t path, kk_context_t* _ctx) { /* (path : string) -> fileRead read-handle */ 
  kk_std_core_hnd__ev ev_10404 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<nagare/io/file_effect/fileRead>*/;
  kk_box_t _x_x816;
  {
    struct kk_std_core_hnd_Ev* _con_x817 = kk_std_core_hnd__as_Ev(ev_10404, _ctx);
    kk_box_t _box_x10 = _con_x817->hnd;
    int32_t m = _con_x817->marker;
    kk_nagare_io_file__effect__fileRead h = kk_nagare_io_file__effect__fileRead_unbox(_box_x10, KK_BORROWED, _ctx);
    kk_nagare_io_file__effect__fileRead_dup(h, _ctx);
    {
      struct kk_nagare_io_file__effect__Hnd_fileRead* _con_x818 = kk_nagare_io_file__effect__as_Hnd_fileRead(h, _ctx);
      kk_integer_t _pat_0_0 = _con_x818->_cfc;
      kk_std_core_hnd__clause1 _pat_1_0 = _con_x818->_fun_closeRead;
      kk_std_core_hnd__clause1 _fun_openRead = _con_x818->_fun_openRead;
      kk_std_core_hnd__clause2 _pat_2_0 = _con_x818->_fun_readChunk;
      kk_std_core_hnd__clause2 _pat_3 = _con_x818->_fun_readChunkBytes;
      kk_std_core_hnd__clause1 _pat_4 = _con_x818->_fun_readTextFileOp;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause1_drop(_pat_4, _ctx);
        kk_std_core_hnd__clause2_drop(_pat_3, _ctx);
        kk_std_core_hnd__clause2_drop(_pat_2_0, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_1_0, _ctx);
        kk_integer_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_fun_openRead, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x14 = _fun_openRead.clause;
        _x_x816 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x14, (_fun_unbox_x14, m, ev_10404, kk_string_box(path), _ctx), _ctx); /*10010*/
      }
    }
  }
  return kk_nagare_io_file__effect__read_handle_unbox(_x_x816, KK_OWNED, _ctx);
}
 
// Automatically generated. Retrieves the `@fun-closeRead` constructor field of the `:fileRead` type.

static inline kk_std_core_hnd__clause1 kk_nagare_io_file__effect_fileRead_fs__fun_closeRead(kk_nagare_io_file__effect__fileRead fileRead, kk_context_t* _ctx) { /* forall<e,a> (fileRead : fileRead<e,a>) -> hnd/clause1<read-handle,(),fileRead,e,a> */ 
  {
    struct kk_nagare_io_file__effect__Hnd_fileRead* _con_x819 = kk_nagare_io_file__effect__as_Hnd_fileRead(fileRead, _ctx);
    kk_std_core_hnd__clause1 _x = _con_x819->_fun_closeRead;
    return kk_std_core_hnd__clause1_dup(_x, _ctx);
  }
}
 
// select `closeRead` operation out of effect `:fileRead`

static inline kk_std_core_hnd__clause1 kk_nagare_io_file__effect_closeRead_fs__select(kk_nagare_io_file__effect__fileRead hnd, kk_context_t* _ctx) { /* forall<e,a> (hnd : fileRead<e,a>) -> hnd/clause1<read-handle,(),fileRead,e,a> */ 
  {
    struct kk_nagare_io_file__effect__Hnd_fileRead* _con_x820 = kk_nagare_io_file__effect__as_Hnd_fileRead(hnd, _ctx);
    kk_std_core_hnd__clause1 _fun_closeRead = _con_x820->_fun_closeRead;
    return kk_std_core_hnd__clause1_dup(_fun_closeRead, _ctx);
  }
}
 
// Call the `fun closeRead` operation of the effect `:fileRead`

static inline kk_unit_t kk_nagare_io_file__effect_closeRead(kk_nagare_io_file__effect__read_handle h, kk_context_t* _ctx) { /* (h : read-handle) -> fileRead () */ 
  kk_std_core_hnd__ev ev_10407 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<nagare/io/file_effect/fileRead>*/;
  kk_box_t _x_x821;
  {
    struct kk_std_core_hnd_Ev* _con_x822 = kk_std_core_hnd__as_Ev(ev_10407, _ctx);
    kk_box_t _box_x18 = _con_x822->hnd;
    int32_t m = _con_x822->marker;
    kk_nagare_io_file__effect__fileRead h_0 = kk_nagare_io_file__effect__fileRead_unbox(_box_x18, KK_BORROWED, _ctx);
    kk_nagare_io_file__effect__fileRead_dup(h_0, _ctx);
    {
      struct kk_nagare_io_file__effect__Hnd_fileRead* _con_x823 = kk_nagare_io_file__effect__as_Hnd_fileRead(h_0, _ctx);
      kk_integer_t _pat_0_0 = _con_x823->_cfc;
      kk_std_core_hnd__clause1 _fun_closeRead = _con_x823->_fun_closeRead;
      kk_std_core_hnd__clause1 _pat_1_0 = _con_x823->_fun_openRead;
      kk_std_core_hnd__clause2 _pat_2_0 = _con_x823->_fun_readChunk;
      kk_std_core_hnd__clause2 _pat_3 = _con_x823->_fun_readChunkBytes;
      kk_std_core_hnd__clause1 _pat_4 = _con_x823->_fun_readTextFileOp;
      if kk_likely(kk_datatype_ptr_is_unique(h_0, _ctx)) {
        kk_std_core_hnd__clause1_drop(_pat_4, _ctx);
        kk_std_core_hnd__clause2_drop(_pat_3, _ctx);
        kk_std_core_hnd__clause2_drop(_pat_2_0, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_1_0, _ctx);
        kk_integer_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(h_0, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_fun_closeRead, _ctx);
        kk_datatype_ptr_decref(h_0, _ctx);
      }
      {
        kk_function_t _fun_unbox_x22 = _fun_closeRead.clause;
        _x_x821 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x22, (_fun_unbox_x22, m, ev_10407, kk_nagare_io_file__effect__read_handle_box(h, _ctx), _ctx), _ctx); /*10010*/
      }
    }
  }
  kk_unit_unbox(_x_x821); return kk_Unit;
}
 
// Automatically generated. Retrieves the `@fun-readChunk` constructor field of the `:fileRead` type.

static inline kk_std_core_hnd__clause2 kk_nagare_io_file__effect_fileRead_fs__fun_readChunk(kk_nagare_io_file__effect__fileRead fileRead, kk_context_t* _ctx) { /* forall<e,a> (fileRead : fileRead<e,a>) -> hnd/clause2<read-handle,int,string,fileRead,e,a> */ 
  {
    struct kk_nagare_io_file__effect__Hnd_fileRead* _con_x824 = kk_nagare_io_file__effect__as_Hnd_fileRead(fileRead, _ctx);
    kk_std_core_hnd__clause2 _x = _con_x824->_fun_readChunk;
    return kk_std_core_hnd__clause2_dup(_x, _ctx);
  }
}
 
// select `readChunk` operation out of effect `:fileRead`

static inline kk_std_core_hnd__clause2 kk_nagare_io_file__effect_readChunk_fs__select(kk_nagare_io_file__effect__fileRead hnd, kk_context_t* _ctx) { /* forall<e,a> (hnd : fileRead<e,a>) -> hnd/clause2<read-handle,int,string,fileRead,e,a> */ 
  {
    struct kk_nagare_io_file__effect__Hnd_fileRead* _con_x825 = kk_nagare_io_file__effect__as_Hnd_fileRead(hnd, _ctx);
    kk_std_core_hnd__clause2 _fun_readChunk = _con_x825->_fun_readChunk;
    return kk_std_core_hnd__clause2_dup(_fun_readChunk, _ctx);
  }
}
 
// Call the `fun readChunk` operation of the effect `:fileRead`

static inline kk_string_t kk_nagare_io_file__effect_readChunk(kk_nagare_io_file__effect__read_handle h, kk_integer_t size, kk_context_t* _ctx) { /* (h : read-handle, size : int) -> fileRead string */ 
  kk_std_core_hnd__ev evx_10410 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<nagare/io/file_effect/fileRead>*/;
  kk_box_t _x_x826;
  {
    struct kk_std_core_hnd_Ev* _con_x827 = kk_std_core_hnd__as_Ev(evx_10410, _ctx);
    kk_box_t _box_x26 = _con_x827->hnd;
    int32_t m = _con_x827->marker;
    kk_nagare_io_file__effect__fileRead h_0 = kk_nagare_io_file__effect__fileRead_unbox(_box_x26, KK_BORROWED, _ctx);
    kk_nagare_io_file__effect__fileRead_dup(h_0, _ctx);
    {
      struct kk_nagare_io_file__effect__Hnd_fileRead* _con_x828 = kk_nagare_io_file__effect__as_Hnd_fileRead(h_0, _ctx);
      kk_integer_t _pat_0_0 = _con_x828->_cfc;
      kk_std_core_hnd__clause1 _pat_1_0 = _con_x828->_fun_closeRead;
      kk_std_core_hnd__clause1 _pat_2_0 = _con_x828->_fun_openRead;
      kk_std_core_hnd__clause2 _fun_readChunk = _con_x828->_fun_readChunk;
      kk_std_core_hnd__clause2 _pat_3 = _con_x828->_fun_readChunkBytes;
      kk_std_core_hnd__clause1 _pat_4 = _con_x828->_fun_readTextFileOp;
      if kk_likely(kk_datatype_ptr_is_unique(h_0, _ctx)) {
        kk_std_core_hnd__clause1_drop(_pat_4, _ctx);
        kk_std_core_hnd__clause2_drop(_pat_3, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_2_0, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_1_0, _ctx);
        kk_integer_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(h_0, _ctx);
      }
      else {
        kk_std_core_hnd__clause2_dup(_fun_readChunk, _ctx);
        kk_datatype_ptr_decref(h_0, _ctx);
      }
      {
        kk_function_t _fun_unbox_x31 = _fun_readChunk.clause;
        _x_x826 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_box_t, kk_context_t*), _fun_unbox_x31, (_fun_unbox_x31, m, evx_10410, kk_nagare_io_file__effect__read_handle_box(h, _ctx), kk_integer_box(size, _ctx), _ctx), _ctx); /*10016*/
      }
    }
  }
  return kk_string_unbox(_x_x826);
}
 
// Automatically generated. Retrieves the `@fun-readChunkBytes` constructor field of the `:fileRead` type.

static inline kk_std_core_hnd__clause2 kk_nagare_io_file__effect_fileRead_fs__fun_readChunkBytes(kk_nagare_io_file__effect__fileRead fileRead, kk_context_t* _ctx) { /* forall<e,a> (fileRead : fileRead<e,a>) -> hnd/clause2<read-handle,int,vector<int8>,fileRead,e,a> */ 
  {
    struct kk_nagare_io_file__effect__Hnd_fileRead* _con_x829 = kk_nagare_io_file__effect__as_Hnd_fileRead(fileRead, _ctx);
    kk_std_core_hnd__clause2 _x = _con_x829->_fun_readChunkBytes;
    return kk_std_core_hnd__clause2_dup(_x, _ctx);
  }
}
 
// select `readChunkBytes` operation out of effect `:fileRead`

static inline kk_std_core_hnd__clause2 kk_nagare_io_file__effect_readChunkBytes_fs__select(kk_nagare_io_file__effect__fileRead hnd, kk_context_t* _ctx) { /* forall<e,a> (hnd : fileRead<e,a>) -> hnd/clause2<read-handle,int,vector<int8>,fileRead,e,a> */ 
  {
    struct kk_nagare_io_file__effect__Hnd_fileRead* _con_x830 = kk_nagare_io_file__effect__as_Hnd_fileRead(hnd, _ctx);
    kk_std_core_hnd__clause2 _fun_readChunkBytes = _con_x830->_fun_readChunkBytes;
    return kk_std_core_hnd__clause2_dup(_fun_readChunkBytes, _ctx);
  }
}
 
// Call the `fun readChunkBytes` operation of the effect `:fileRead`

static inline kk_vector_t kk_nagare_io_file__effect_readChunkBytes(kk_nagare_io_file__effect__read_handle h, kk_integer_t size, kk_context_t* _ctx) { /* (h : read-handle, size : int) -> fileRead vector<int8> */ 
  kk_std_core_hnd__ev evx_10414 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<nagare/io/file_effect/fileRead>*/;
  kk_box_t _x_x831;
  {
    struct kk_std_core_hnd_Ev* _con_x832 = kk_std_core_hnd__as_Ev(evx_10414, _ctx);
    kk_box_t _box_x36 = _con_x832->hnd;
    int32_t m = _con_x832->marker;
    kk_nagare_io_file__effect__fileRead h_0 = kk_nagare_io_file__effect__fileRead_unbox(_box_x36, KK_BORROWED, _ctx);
    kk_nagare_io_file__effect__fileRead_dup(h_0, _ctx);
    {
      struct kk_nagare_io_file__effect__Hnd_fileRead* _con_x833 = kk_nagare_io_file__effect__as_Hnd_fileRead(h_0, _ctx);
      kk_integer_t _pat_0_0 = _con_x833->_cfc;
      kk_std_core_hnd__clause1 _pat_1_0 = _con_x833->_fun_closeRead;
      kk_std_core_hnd__clause1 _pat_2_0 = _con_x833->_fun_openRead;
      kk_std_core_hnd__clause2 _pat_3 = _con_x833->_fun_readChunk;
      kk_std_core_hnd__clause2 _fun_readChunkBytes = _con_x833->_fun_readChunkBytes;
      kk_std_core_hnd__clause1 _pat_4 = _con_x833->_fun_readTextFileOp;
      if kk_likely(kk_datatype_ptr_is_unique(h_0, _ctx)) {
        kk_std_core_hnd__clause1_drop(_pat_4, _ctx);
        kk_std_core_hnd__clause2_drop(_pat_3, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_2_0, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_1_0, _ctx);
        kk_integer_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(h_0, _ctx);
      }
      else {
        kk_std_core_hnd__clause2_dup(_fun_readChunkBytes, _ctx);
        kk_datatype_ptr_decref(h_0, _ctx);
      }
      {
        kk_function_t _fun_unbox_x41 = _fun_readChunkBytes.clause;
        _x_x831 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_box_t, kk_context_t*), _fun_unbox_x41, (_fun_unbox_x41, m, evx_10414, kk_nagare_io_file__effect__read_handle_box(h, _ctx), kk_integer_box(size, _ctx), _ctx), _ctx); /*10016*/
      }
    }
  }
  return kk_vector_unbox(_x_x831, _ctx);
}
 
// Automatically generated. Retrieves the `@fun-readTextFileOp` constructor field of the `:fileRead` type.

static inline kk_std_core_hnd__clause1 kk_nagare_io_file__effect_fileRead_fs__fun_readTextFileOp(kk_nagare_io_file__effect__fileRead fileRead, kk_context_t* _ctx) { /* forall<e,a> (fileRead : fileRead<e,a>) -> hnd/clause1<string,string,fileRead,e,a> */ 
  {
    struct kk_nagare_io_file__effect__Hnd_fileRead* _con_x834 = kk_nagare_io_file__effect__as_Hnd_fileRead(fileRead, _ctx);
    kk_std_core_hnd__clause1 _x = _con_x834->_fun_readTextFileOp;
    return kk_std_core_hnd__clause1_dup(_x, _ctx);
  }
}
 
// select `readTextFileOp` operation out of effect `:fileRead`

static inline kk_std_core_hnd__clause1 kk_nagare_io_file__effect_readTextFileOp_fs__select(kk_nagare_io_file__effect__fileRead hnd, kk_context_t* _ctx) { /* forall<e,a> (hnd : fileRead<e,a>) -> hnd/clause1<string,string,fileRead,e,a> */ 
  {
    struct kk_nagare_io_file__effect__Hnd_fileRead* _con_x835 = kk_nagare_io_file__effect__as_Hnd_fileRead(hnd, _ctx);
    kk_std_core_hnd__clause1 _fun_readTextFileOp = _con_x835->_fun_readTextFileOp;
    return kk_std_core_hnd__clause1_dup(_fun_readTextFileOp, _ctx);
  }
}
 
// Call the `fun readTextFileOp` operation of the effect `:fileRead`

static inline kk_string_t kk_nagare_io_file__effect_readTextFileOp(kk_string_t p, kk_context_t* _ctx) { /* (p : string) -> fileRead string */ 
  kk_std_core_hnd__ev ev_10418 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<nagare/io/file_effect/fileRead>*/;
  kk_box_t _x_x836;
  {
    struct kk_std_core_hnd_Ev* _con_x837 = kk_std_core_hnd__as_Ev(ev_10418, _ctx);
    kk_box_t _box_x46 = _con_x837->hnd;
    int32_t m = _con_x837->marker;
    kk_nagare_io_file__effect__fileRead h = kk_nagare_io_file__effect__fileRead_unbox(_box_x46, KK_BORROWED, _ctx);
    kk_nagare_io_file__effect__fileRead_dup(h, _ctx);
    {
      struct kk_nagare_io_file__effect__Hnd_fileRead* _con_x838 = kk_nagare_io_file__effect__as_Hnd_fileRead(h, _ctx);
      kk_integer_t _pat_0_0 = _con_x838->_cfc;
      kk_std_core_hnd__clause1 _pat_1_0 = _con_x838->_fun_closeRead;
      kk_std_core_hnd__clause1 _pat_2_0 = _con_x838->_fun_openRead;
      kk_std_core_hnd__clause2 _pat_3 = _con_x838->_fun_readChunk;
      kk_std_core_hnd__clause2 _pat_4 = _con_x838->_fun_readChunkBytes;
      kk_std_core_hnd__clause1 _fun_readTextFileOp = _con_x838->_fun_readTextFileOp;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause2_drop(_pat_4, _ctx);
        kk_std_core_hnd__clause2_drop(_pat_3, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_2_0, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_1_0, _ctx);
        kk_integer_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_fun_readTextFileOp, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x50 = _fun_readTextFileOp.clause;
        _x_x836 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x50, (_fun_unbox_x50, m, ev_10418, kk_string_box(p), _ctx), _ctx); /*10010*/
      }
    }
  }
  return kk_string_unbox(_x_x836);
}
 
// Automatically generated. Retrieves the `@cfc` constructor field of the `:fileWrite` type.

static inline kk_integer_t kk_nagare_io_file__effect_fileWrite_fs__cfc(kk_nagare_io_file__effect__fileWrite fileWrite, kk_context_t* _ctx) { /* forall<e,a> (fileWrite : fileWrite<e,a>) -> int */ 
  {
    struct kk_nagare_io_file__effect__Hnd_fileWrite* _con_x839 = kk_nagare_io_file__effect__as_Hnd_fileWrite(fileWrite, _ctx);
    kk_integer_t _x = _con_x839->_cfc;
    return kk_integer_dup(_x, _ctx);
  }
}

extern kk_std_core_hnd__htag kk_nagare_io_file__effect_fileWrite_fs__tag;

kk_box_t kk_nagare_io_file__effect_fileWrite_fs__handle(kk_nagare_io_file__effect__fileWrite hnd, kk_function_t ret, kk_function_t action, kk_context_t* _ctx); /* forall<a,e,b> (hnd : fileWrite<e,b>, ret : (res : a) -> e b, action : () -> <fileWrite|e> a) -> e b */ 
 
// Automatically generated. Retrieves the `@fun-openWrite` constructor field of the `:fileWrite` type.

static inline kk_std_core_hnd__clause1 kk_nagare_io_file__effect_fileWrite_fs__fun_openWrite(kk_nagare_io_file__effect__fileWrite fileWrite, kk_context_t* _ctx) { /* forall<e,a> (fileWrite : fileWrite<e,a>) -> hnd/clause1<string,write-handle,fileWrite,e,a> */ 
  {
    struct kk_nagare_io_file__effect__Hnd_fileWrite* _con_x843 = kk_nagare_io_file__effect__as_Hnd_fileWrite(fileWrite, _ctx);
    kk_std_core_hnd__clause1 _x = _con_x843->_fun_openWrite;
    return kk_std_core_hnd__clause1_dup(_x, _ctx);
  }
}
 
// select `openWrite` operation out of effect `:fileWrite`

static inline kk_std_core_hnd__clause1 kk_nagare_io_file__effect_openWrite_fs__select(kk_nagare_io_file__effect__fileWrite hnd, kk_context_t* _ctx) { /* forall<e,a> (hnd : fileWrite<e,a>) -> hnd/clause1<string,write-handle,fileWrite,e,a> */ 
  {
    struct kk_nagare_io_file__effect__Hnd_fileWrite* _con_x844 = kk_nagare_io_file__effect__as_Hnd_fileWrite(hnd, _ctx);
    kk_std_core_hnd__clause1 _fun_openWrite = _con_x844->_fun_openWrite;
    return kk_std_core_hnd__clause1_dup(_fun_openWrite, _ctx);
  }
}
 
// Call the `fun openWrite` operation of the effect `:fileWrite`

static inline kk_nagare_io_file__effect__write_handle kk_nagare_io_file__effect_openWrite(kk_string_t path, kk_context_t* _ctx) { /* (path : string) -> fileWrite write-handle */ 
  kk_std_core_hnd__ev ev_10422 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<nagare/io/file_effect/fileWrite>*/;
  kk_box_t _x_x845;
  {
    struct kk_std_core_hnd_Ev* _con_x846 = kk_std_core_hnd__as_Ev(ev_10422, _ctx);
    kk_box_t _box_x62 = _con_x846->hnd;
    int32_t m = _con_x846->marker;
    kk_nagare_io_file__effect__fileWrite h = kk_nagare_io_file__effect__fileWrite_unbox(_box_x62, KK_BORROWED, _ctx);
    kk_nagare_io_file__effect__fileWrite_dup(h, _ctx);
    {
      struct kk_nagare_io_file__effect__Hnd_fileWrite* _con_x847 = kk_nagare_io_file__effect__as_Hnd_fileWrite(h, _ctx);
      kk_integer_t _pat_0_0 = _con_x847->_cfc;
      kk_std_core_hnd__clause1 _pat_1_0 = _con_x847->_fun_closeWrite;
      kk_std_core_hnd__clause1 _fun_openWrite = _con_x847->_fun_openWrite;
      kk_std_core_hnd__clause2 _pat_2_0 = _con_x847->_fun_writeChunk;
      kk_std_core_hnd__clause2 _pat_3 = _con_x847->_fun_writeChunkBytes;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause2_drop(_pat_3, _ctx);
        kk_std_core_hnd__clause2_drop(_pat_2_0, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_1_0, _ctx);
        kk_integer_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_fun_openWrite, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x66 = _fun_openWrite.clause;
        _x_x845 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x66, (_fun_unbox_x66, m, ev_10422, kk_string_box(path), _ctx), _ctx); /*10010*/
      }
    }
  }
  return kk_nagare_io_file__effect__write_handle_unbox(_x_x845, KK_OWNED, _ctx);
}
 
// Automatically generated. Retrieves the `@fun-closeWrite` constructor field of the `:fileWrite` type.

static inline kk_std_core_hnd__clause1 kk_nagare_io_file__effect_fileWrite_fs__fun_closeWrite(kk_nagare_io_file__effect__fileWrite fileWrite, kk_context_t* _ctx) { /* forall<e,a> (fileWrite : fileWrite<e,a>) -> hnd/clause1<write-handle,(),fileWrite,e,a> */ 
  {
    struct kk_nagare_io_file__effect__Hnd_fileWrite* _con_x848 = kk_nagare_io_file__effect__as_Hnd_fileWrite(fileWrite, _ctx);
    kk_std_core_hnd__clause1 _x = _con_x848->_fun_closeWrite;
    return kk_std_core_hnd__clause1_dup(_x, _ctx);
  }
}
 
// select `closeWrite` operation out of effect `:fileWrite`

static inline kk_std_core_hnd__clause1 kk_nagare_io_file__effect_closeWrite_fs__select(kk_nagare_io_file__effect__fileWrite hnd, kk_context_t* _ctx) { /* forall<e,a> (hnd : fileWrite<e,a>) -> hnd/clause1<write-handle,(),fileWrite,e,a> */ 
  {
    struct kk_nagare_io_file__effect__Hnd_fileWrite* _con_x849 = kk_nagare_io_file__effect__as_Hnd_fileWrite(hnd, _ctx);
    kk_std_core_hnd__clause1 _fun_closeWrite = _con_x849->_fun_closeWrite;
    return kk_std_core_hnd__clause1_dup(_fun_closeWrite, _ctx);
  }
}
 
// Call the `fun closeWrite` operation of the effect `:fileWrite`

static inline kk_unit_t kk_nagare_io_file__effect_closeWrite(kk_nagare_io_file__effect__write_handle h, kk_context_t* _ctx) { /* (h : write-handle) -> fileWrite () */ 
  kk_std_core_hnd__ev ev_10425 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<nagare/io/file_effect/fileWrite>*/;
  kk_box_t _x_x850;
  {
    struct kk_std_core_hnd_Ev* _con_x851 = kk_std_core_hnd__as_Ev(ev_10425, _ctx);
    kk_box_t _box_x70 = _con_x851->hnd;
    int32_t m = _con_x851->marker;
    kk_nagare_io_file__effect__fileWrite h_0 = kk_nagare_io_file__effect__fileWrite_unbox(_box_x70, KK_BORROWED, _ctx);
    kk_nagare_io_file__effect__fileWrite_dup(h_0, _ctx);
    {
      struct kk_nagare_io_file__effect__Hnd_fileWrite* _con_x852 = kk_nagare_io_file__effect__as_Hnd_fileWrite(h_0, _ctx);
      kk_integer_t _pat_0_0 = _con_x852->_cfc;
      kk_std_core_hnd__clause1 _fun_closeWrite = _con_x852->_fun_closeWrite;
      kk_std_core_hnd__clause1 _pat_1_0 = _con_x852->_fun_openWrite;
      kk_std_core_hnd__clause2 _pat_2_0 = _con_x852->_fun_writeChunk;
      kk_std_core_hnd__clause2 _pat_3 = _con_x852->_fun_writeChunkBytes;
      if kk_likely(kk_datatype_ptr_is_unique(h_0, _ctx)) {
        kk_std_core_hnd__clause2_drop(_pat_3, _ctx);
        kk_std_core_hnd__clause2_drop(_pat_2_0, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_1_0, _ctx);
        kk_integer_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(h_0, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_fun_closeWrite, _ctx);
        kk_datatype_ptr_decref(h_0, _ctx);
      }
      {
        kk_function_t _fun_unbox_x74 = _fun_closeWrite.clause;
        _x_x850 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x74, (_fun_unbox_x74, m, ev_10425, kk_nagare_io_file__effect__write_handle_box(h, _ctx), _ctx), _ctx); /*10010*/
      }
    }
  }
  kk_unit_unbox(_x_x850); return kk_Unit;
}
 
// Automatically generated. Retrieves the `@fun-writeChunk` constructor field of the `:fileWrite` type.

static inline kk_std_core_hnd__clause2 kk_nagare_io_file__effect_fileWrite_fs__fun_writeChunk(kk_nagare_io_file__effect__fileWrite fileWrite, kk_context_t* _ctx) { /* forall<e,a> (fileWrite : fileWrite<e,a>) -> hnd/clause2<write-handle,string,int,fileWrite,e,a> */ 
  {
    struct kk_nagare_io_file__effect__Hnd_fileWrite* _con_x853 = kk_nagare_io_file__effect__as_Hnd_fileWrite(fileWrite, _ctx);
    kk_std_core_hnd__clause2 _x = _con_x853->_fun_writeChunk;
    return kk_std_core_hnd__clause2_dup(_x, _ctx);
  }
}
 
// select `writeChunk` operation out of effect `:fileWrite`

static inline kk_std_core_hnd__clause2 kk_nagare_io_file__effect_writeChunk_fs__select(kk_nagare_io_file__effect__fileWrite hnd, kk_context_t* _ctx) { /* forall<e,a> (hnd : fileWrite<e,a>) -> hnd/clause2<write-handle,string,int,fileWrite,e,a> */ 
  {
    struct kk_nagare_io_file__effect__Hnd_fileWrite* _con_x854 = kk_nagare_io_file__effect__as_Hnd_fileWrite(hnd, _ctx);
    kk_std_core_hnd__clause2 _fun_writeChunk = _con_x854->_fun_writeChunk;
    return kk_std_core_hnd__clause2_dup(_fun_writeChunk, _ctx);
  }
}
 
// Call the `fun writeChunk` operation of the effect `:fileWrite`

static inline kk_integer_t kk_nagare_io_file__effect_writeChunk(kk_nagare_io_file__effect__write_handle h, kk_string_t content, kk_context_t* _ctx) { /* (h : write-handle, content : string) -> fileWrite int */ 
  kk_std_core_hnd__ev evx_10428 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<nagare/io/file_effect/fileWrite>*/;
  kk_box_t _x_x855;
  {
    struct kk_std_core_hnd_Ev* _con_x856 = kk_std_core_hnd__as_Ev(evx_10428, _ctx);
    kk_box_t _box_x78 = _con_x856->hnd;
    int32_t m = _con_x856->marker;
    kk_nagare_io_file__effect__fileWrite h_0 = kk_nagare_io_file__effect__fileWrite_unbox(_box_x78, KK_BORROWED, _ctx);
    kk_nagare_io_file__effect__fileWrite_dup(h_0, _ctx);
    {
      struct kk_nagare_io_file__effect__Hnd_fileWrite* _con_x857 = kk_nagare_io_file__effect__as_Hnd_fileWrite(h_0, _ctx);
      kk_integer_t _pat_0_0 = _con_x857->_cfc;
      kk_std_core_hnd__clause1 _pat_1_0 = _con_x857->_fun_closeWrite;
      kk_std_core_hnd__clause1 _pat_2_0 = _con_x857->_fun_openWrite;
      kk_std_core_hnd__clause2 _fun_writeChunk = _con_x857->_fun_writeChunk;
      kk_std_core_hnd__clause2 _pat_3 = _con_x857->_fun_writeChunkBytes;
      if kk_likely(kk_datatype_ptr_is_unique(h_0, _ctx)) {
        kk_std_core_hnd__clause2_drop(_pat_3, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_2_0, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_1_0, _ctx);
        kk_integer_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(h_0, _ctx);
      }
      else {
        kk_std_core_hnd__clause2_dup(_fun_writeChunk, _ctx);
        kk_datatype_ptr_decref(h_0, _ctx);
      }
      {
        kk_function_t _fun_unbox_x83 = _fun_writeChunk.clause;
        _x_x855 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_box_t, kk_context_t*), _fun_unbox_x83, (_fun_unbox_x83, m, evx_10428, kk_nagare_io_file__effect__write_handle_box(h, _ctx), kk_string_box(content), _ctx), _ctx); /*10016*/
      }
    }
  }
  return kk_integer_unbox(_x_x855, _ctx);
}
 
// Automatically generated. Retrieves the `@fun-writeChunkBytes` constructor field of the `:fileWrite` type.

static inline kk_std_core_hnd__clause2 kk_nagare_io_file__effect_fileWrite_fs__fun_writeChunkBytes(kk_nagare_io_file__effect__fileWrite fileWrite, kk_context_t* _ctx) { /* forall<e,a> (fileWrite : fileWrite<e,a>) -> hnd/clause2<write-handle,vector<int8>,int,fileWrite,e,a> */ 
  {
    struct kk_nagare_io_file__effect__Hnd_fileWrite* _con_x858 = kk_nagare_io_file__effect__as_Hnd_fileWrite(fileWrite, _ctx);
    kk_std_core_hnd__clause2 _x = _con_x858->_fun_writeChunkBytes;
    return kk_std_core_hnd__clause2_dup(_x, _ctx);
  }
}
 
// select `writeChunkBytes` operation out of effect `:fileWrite`

static inline kk_std_core_hnd__clause2 kk_nagare_io_file__effect_writeChunkBytes_fs__select(kk_nagare_io_file__effect__fileWrite hnd, kk_context_t* _ctx) { /* forall<e,a> (hnd : fileWrite<e,a>) -> hnd/clause2<write-handle,vector<int8>,int,fileWrite,e,a> */ 
  {
    struct kk_nagare_io_file__effect__Hnd_fileWrite* _con_x859 = kk_nagare_io_file__effect__as_Hnd_fileWrite(hnd, _ctx);
    kk_std_core_hnd__clause2 _fun_writeChunkBytes = _con_x859->_fun_writeChunkBytes;
    return kk_std_core_hnd__clause2_dup(_fun_writeChunkBytes, _ctx);
  }
}
 
// Call the `fun writeChunkBytes` operation of the effect `:fileWrite`

static inline kk_integer_t kk_nagare_io_file__effect_writeChunkBytes(kk_nagare_io_file__effect__write_handle h, kk_vector_t content, kk_context_t* _ctx) { /* (h : write-handle, content : vector<int8>) -> fileWrite int */ 
  kk_std_core_hnd__ev evx_10432 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<nagare/io/file_effect/fileWrite>*/;
  kk_box_t _x_x860;
  {
    struct kk_std_core_hnd_Ev* _con_x861 = kk_std_core_hnd__as_Ev(evx_10432, _ctx);
    kk_box_t _box_x88 = _con_x861->hnd;
    int32_t m = _con_x861->marker;
    kk_nagare_io_file__effect__fileWrite h_0 = kk_nagare_io_file__effect__fileWrite_unbox(_box_x88, KK_BORROWED, _ctx);
    kk_nagare_io_file__effect__fileWrite_dup(h_0, _ctx);
    {
      struct kk_nagare_io_file__effect__Hnd_fileWrite* _con_x862 = kk_nagare_io_file__effect__as_Hnd_fileWrite(h_0, _ctx);
      kk_integer_t _pat_0_0 = _con_x862->_cfc;
      kk_std_core_hnd__clause1 _pat_1_0 = _con_x862->_fun_closeWrite;
      kk_std_core_hnd__clause1 _pat_2_0 = _con_x862->_fun_openWrite;
      kk_std_core_hnd__clause2 _pat_3 = _con_x862->_fun_writeChunk;
      kk_std_core_hnd__clause2 _fun_writeChunkBytes = _con_x862->_fun_writeChunkBytes;
      if kk_likely(kk_datatype_ptr_is_unique(h_0, _ctx)) {
        kk_std_core_hnd__clause2_drop(_pat_3, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_2_0, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_1_0, _ctx);
        kk_integer_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(h_0, _ctx);
      }
      else {
        kk_std_core_hnd__clause2_dup(_fun_writeChunkBytes, _ctx);
        kk_datatype_ptr_decref(h_0, _ctx);
      }
      {
        kk_function_t _fun_unbox_x93 = _fun_writeChunkBytes.clause;
        _x_x860 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_box_t, kk_context_t*), _fun_unbox_x93, (_fun_unbox_x93, m, evx_10432, kk_nagare_io_file__effect__write_handle_box(h, _ctx), kk_vector_box(content, _ctx), _ctx), _ctx); /*10016*/
      }
    }
  }
  return kk_integer_unbox(_x_x860, _ctx);
}
 
// Automatically generated. Retrieves the `@cfc` constructor field of the `:fileSystem` type.

static inline kk_integer_t kk_nagare_io_file__effect_fileSystem_fs__cfc(kk_nagare_io_file__effect__fileSystem fileSystem, kk_context_t* _ctx) { /* forall<e,a> (fileSystem : fileSystem<e,a>) -> int */ 
  {
    struct kk_nagare_io_file__effect__Hnd_fileSystem* _con_x863 = kk_nagare_io_file__effect__as_Hnd_fileSystem(fileSystem, _ctx);
    kk_integer_t _x = _con_x863->_cfc;
    return kk_integer_dup(_x, _ctx);
  }
}

extern kk_std_core_hnd__htag kk_nagare_io_file__effect_fileSystem_fs__tag;

kk_box_t kk_nagare_io_file__effect_fileSystem_fs__handle(kk_nagare_io_file__effect__fileSystem hnd, kk_function_t ret, kk_function_t action, kk_context_t* _ctx); /* forall<a,e,b> (hnd : fileSystem<e,b>, ret : (res : a) -> e b, action : () -> <fileSystem|e> a) -> e b */ 
 
// Automatically generated. Retrieves the `@fun-fileExistsOp` constructor field of the `:fileSystem` type.

static inline kk_std_core_hnd__clause1 kk_nagare_io_file__effect_fileSystem_fs__fun_fileExistsOp(kk_nagare_io_file__effect__fileSystem fileSystem, kk_context_t* _ctx) { /* forall<e,a> (fileSystem : fileSystem<e,a>) -> hnd/clause1<string,bool,fileSystem,e,a> */ 
  {
    struct kk_nagare_io_file__effect__Hnd_fileSystem* _con_x867 = kk_nagare_io_file__effect__as_Hnd_fileSystem(fileSystem, _ctx);
    kk_std_core_hnd__clause1 _x = _con_x867->_fun_fileExistsOp;
    return kk_std_core_hnd__clause1_dup(_x, _ctx);
  }
}
 
// select `fileExistsOp` operation out of effect `:fileSystem`

static inline kk_std_core_hnd__clause1 kk_nagare_io_file__effect_fileExistsOp_fs__select(kk_nagare_io_file__effect__fileSystem hnd, kk_context_t* _ctx) { /* forall<e,a> (hnd : fileSystem<e,a>) -> hnd/clause1<string,bool,fileSystem,e,a> */ 
  {
    struct kk_nagare_io_file__effect__Hnd_fileSystem* _con_x868 = kk_nagare_io_file__effect__as_Hnd_fileSystem(hnd, _ctx);
    kk_std_core_hnd__clause1 _fun_fileExistsOp = _con_x868->_fun_fileExistsOp;
    return kk_std_core_hnd__clause1_dup(_fun_fileExistsOp, _ctx);
  }
}
 
// Call the `fun fileExistsOp` operation of the effect `:fileSystem`

static inline bool kk_nagare_io_file__effect_fileExistsOp(kk_string_t p, kk_context_t* _ctx) { /* (p : string) -> fileSystem bool */ 
  kk_std_core_hnd__ev ev_10437 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<nagare/io/file_effect/fileSystem>*/;
  kk_box_t _x_x869;
  {
    struct kk_std_core_hnd_Ev* _con_x870 = kk_std_core_hnd__as_Ev(ev_10437, _ctx);
    kk_box_t _box_x106 = _con_x870->hnd;
    int32_t m = _con_x870->marker;
    kk_nagare_io_file__effect__fileSystem h = kk_nagare_io_file__effect__fileSystem_unbox(_box_x106, KK_BORROWED, _ctx);
    kk_nagare_io_file__effect__fileSystem_dup(h, _ctx);
    {
      struct kk_nagare_io_file__effect__Hnd_fileSystem* _con_x871 = kk_nagare_io_file__effect__as_Hnd_fileSystem(h, _ctx);
      kk_integer_t _pat_0_0 = _con_x871->_cfc;
      kk_std_core_hnd__clause1 _fun_fileExistsOp = _con_x871->_fun_fileExistsOp;
      kk_std_core_hnd__clause1 _pat_1_0 = _con_x871->_fun_listChildren;
      kk_std_core_hnd__clause1 _pat_2_0 = _con_x871->_fun_removeFileOp;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause1_drop(_pat_2_0, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_1_0, _ctx);
        kk_integer_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_fun_fileExistsOp, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x110 = _fun_fileExistsOp.clause;
        _x_x869 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x110, (_fun_unbox_x110, m, ev_10437, kk_string_box(p), _ctx), _ctx); /*10010*/
      }
    }
  }
  return kk_bool_unbox(_x_x869);
}
 
// Automatically generated. Retrieves the `@fun-removeFileOp` constructor field of the `:fileSystem` type.

static inline kk_std_core_hnd__clause1 kk_nagare_io_file__effect_fileSystem_fs__fun_removeFileOp(kk_nagare_io_file__effect__fileSystem fileSystem, kk_context_t* _ctx) { /* forall<e,a> (fileSystem : fileSystem<e,a>) -> hnd/clause1<string,(),fileSystem,e,a> */ 
  {
    struct kk_nagare_io_file__effect__Hnd_fileSystem* _con_x872 = kk_nagare_io_file__effect__as_Hnd_fileSystem(fileSystem, _ctx);
    kk_std_core_hnd__clause1 _x = _con_x872->_fun_removeFileOp;
    return kk_std_core_hnd__clause1_dup(_x, _ctx);
  }
}
 
// select `removeFileOp` operation out of effect `:fileSystem`

static inline kk_std_core_hnd__clause1 kk_nagare_io_file__effect_removeFileOp_fs__select(kk_nagare_io_file__effect__fileSystem hnd, kk_context_t* _ctx) { /* forall<e,a> (hnd : fileSystem<e,a>) -> hnd/clause1<string,(),fileSystem,e,a> */ 
  {
    struct kk_nagare_io_file__effect__Hnd_fileSystem* _con_x873 = kk_nagare_io_file__effect__as_Hnd_fileSystem(hnd, _ctx);
    kk_std_core_hnd__clause1 _fun_removeFileOp = _con_x873->_fun_removeFileOp;
    return kk_std_core_hnd__clause1_dup(_fun_removeFileOp, _ctx);
  }
}
 
// Call the `fun removeFileOp` operation of the effect `:fileSystem`

static inline kk_unit_t kk_nagare_io_file__effect_removeFileOp(kk_string_t p, kk_context_t* _ctx) { /* (p : string) -> fileSystem () */ 
  kk_std_core_hnd__ev ev_10440 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<nagare/io/file_effect/fileSystem>*/;
  kk_box_t _x_x874;
  {
    struct kk_std_core_hnd_Ev* _con_x875 = kk_std_core_hnd__as_Ev(ev_10440, _ctx);
    kk_box_t _box_x114 = _con_x875->hnd;
    int32_t m = _con_x875->marker;
    kk_nagare_io_file__effect__fileSystem h = kk_nagare_io_file__effect__fileSystem_unbox(_box_x114, KK_BORROWED, _ctx);
    kk_nagare_io_file__effect__fileSystem_dup(h, _ctx);
    {
      struct kk_nagare_io_file__effect__Hnd_fileSystem* _con_x876 = kk_nagare_io_file__effect__as_Hnd_fileSystem(h, _ctx);
      kk_integer_t _pat_0_0 = _con_x876->_cfc;
      kk_std_core_hnd__clause1 _pat_1_0 = _con_x876->_fun_fileExistsOp;
      kk_std_core_hnd__clause1 _pat_2_0 = _con_x876->_fun_listChildren;
      kk_std_core_hnd__clause1 _fun_removeFileOp = _con_x876->_fun_removeFileOp;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause1_drop(_pat_2_0, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_1_0, _ctx);
        kk_integer_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_fun_removeFileOp, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x118 = _fun_removeFileOp.clause;
        _x_x874 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x118, (_fun_unbox_x118, m, ev_10440, kk_string_box(p), _ctx), _ctx); /*10010*/
      }
    }
  }
  kk_unit_unbox(_x_x874); return kk_Unit;
}
 
// Automatically generated. Retrieves the `@fun-listChildren` constructor field of the `:fileSystem` type.

static inline kk_std_core_hnd__clause1 kk_nagare_io_file__effect_fileSystem_fs__fun_listChildren(kk_nagare_io_file__effect__fileSystem fileSystem, kk_context_t* _ctx) { /* forall<e,a> (fileSystem : fileSystem<e,a>) -> hnd/clause1<(string, bool, int),list<std/os/path/path>,fileSystem,e,a> */ 
  {
    struct kk_nagare_io_file__effect__Hnd_fileSystem* _con_x877 = kk_nagare_io_file__effect__as_Hnd_fileSystem(fileSystem, _ctx);
    kk_std_core_hnd__clause1 _x = _con_x877->_fun_listChildren;
    return kk_std_core_hnd__clause1_dup(_x, _ctx);
  }
}
 
// select `listChildren` operation out of effect `:fileSystem`

static inline kk_std_core_hnd__clause1 kk_nagare_io_file__effect_listChildren_fs__select(kk_nagare_io_file__effect__fileSystem hnd, kk_context_t* _ctx) { /* forall<e,a> (hnd : fileSystem<e,a>) -> hnd/clause1<(string, bool, int),list<std/os/path/path>,fileSystem,e,a> */ 
  {
    struct kk_nagare_io_file__effect__Hnd_fileSystem* _con_x878 = kk_nagare_io_file__effect__as_Hnd_fileSystem(hnd, _ctx);
    kk_std_core_hnd__clause1 _fun_listChildren = _con_x878->_fun_listChildren;
    return kk_std_core_hnd__clause1_dup(_fun_listChildren, _ctx);
  }
}
 
// Call the `fun listChildren` operation of the effect `:fileSystem`

static inline kk_std_core_types__list kk_nagare_io_file__effect_listChildren(kk_string_t p, bool recursive, kk_integer_t maxDepth, kk_context_t* _ctx) { /* (p : string, recursive : bool, maxDepth : int) -> fileSystem list<std/os/path/path> */ 
  kk_std_core_hnd__ev ev_10443 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<nagare/io/file_effect/fileSystem>*/;
  kk_box_t _x_x879;
  {
    struct kk_std_core_hnd_Ev* _con_x880 = kk_std_core_hnd__as_Ev(ev_10443, _ctx);
    kk_box_t _box_x122 = _con_x880->hnd;
    int32_t m = _con_x880->marker;
    kk_nagare_io_file__effect__fileSystem h = kk_nagare_io_file__effect__fileSystem_unbox(_box_x122, KK_BORROWED, _ctx);
    kk_nagare_io_file__effect__fileSystem_dup(h, _ctx);
    {
      struct kk_nagare_io_file__effect__Hnd_fileSystem* _con_x881 = kk_nagare_io_file__effect__as_Hnd_fileSystem(h, _ctx);
      kk_integer_t _pat_0_0 = _con_x881->_cfc;
      kk_std_core_hnd__clause1 _pat_1_0 = _con_x881->_fun_fileExistsOp;
      kk_std_core_hnd__clause1 _fun_listChildren = _con_x881->_fun_listChildren;
      kk_std_core_hnd__clause1 _pat_2_0 = _con_x881->_fun_removeFileOp;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_std_core_hnd__clause1_drop(_pat_2_0, _ctx);
        kk_std_core_hnd__clause1_drop(_pat_1_0, _ctx);
        kk_integer_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_fun_listChildren, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x126 = _fun_listChildren.clause;
        kk_box_t _x_x882;
        kk_std_core_types__tuple3 _x_x883 = kk_std_core_types__new_Tuple3(kk_string_box(p), kk_bool_box(recursive), kk_integer_box(maxDepth, _ctx), _ctx); /*(10041, 10042, 10043)*/
        _x_x882 = kk_std_core_types__tuple3_box(_x_x883, _ctx); /*10009*/
        _x_x879 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x126, (_fun_unbox_x126, m, ev_10443, _x_x882, _ctx), _ctx); /*10010*/
      }
    }
  }
  return kk_std_core_types__list_unbox(_x_x879, KK_OWNED, _ctx);
}

kk_box_t kk_nagare_io_file__effect__mlift_with_read_file_10393(kk_function_t body, kk_nagare_io_file__effect__read_handle h, kk_context_t* _ctx); /* forall<a,e> (body : (read-handle) -> <fileRead|e> a, h : read-handle) -> <fileRead|e> a */ 

kk_box_t kk_nagare_io_file__effect_with_read_file(kk_string_t path, kk_function_t body, kk_context_t* _ctx); /* forall<a,e> (path : string, body : (read-handle) -> <fileRead|e> a) -> <fileRead|e> a */ 

kk_box_t kk_nagare_io_file__effect__mlift_with_write_file_10394(kk_function_t body, kk_nagare_io_file__effect__write_handle h, kk_context_t* _ctx); /* forall<a,e> (body : (write-handle) -> <fileWrite|e> a, h : write-handle) -> <fileWrite|e> a */ 

kk_box_t kk_nagare_io_file__effect_with_write_file(kk_string_t path, kk_function_t body, kk_context_t* _ctx); /* forall<a,e> (path : string, body : (write-handle) -> <fileWrite|e> a) -> <fileWrite|e> a */ 
 
// monadic lift

static inline kk_nagare_io_file__effect__read_handle kk_nagare_io_file__effect__mlift_defaultFileRead_10395(intptr_t _y_x10247, kk_context_t* _ctx) { /* (intptr_t) -> io read-handle */ 
  return kk_nagare_io_file__effect__new_ReadHandle(_y_x10247, _ctx);
}

kk_box_t kk_nagare_io_file__effect_defaultFileRead(kk_function_t action, kk_context_t* _ctx); /* forall<a> (action : () -> <fileRead|io> a) -> io a */ 
 
// monadic lift

static inline kk_nagare_io_file__effect__write_handle kk_nagare_io_file__effect__mlift_defaultFileWrite_10396(intptr_t _y_x10253, kk_context_t* _ctx) { /* (intptr_t) -> io write-handle */ 
  return kk_nagare_io_file__effect__new_WriteHandle(_y_x10253, _ctx);
}

kk_box_t kk_nagare_io_file__effect_defaultFileWrite(kk_function_t action, kk_context_t* _ctx); /* forall<a> (action : () -> <fileWrite|io> a) -> io a */ 

kk_std_core_types__list kk_nagare_io_file__effect__lift_defaultFileSystem_10194(kk_std_core_types__list _uniq_xs_10122, kk_context_t* _ctx); /* (list<std/os/path/path>) -> <fsys,div,exn> list<std/os/path/path> */ 

kk_std_core_types__list kk_nagare_io_file__effect__mlift_trmc_lift_defaultFileSystem_10196_10397(kk_std_core_types__cctx _acc, kk_std_core_types__optional _uniq_max_depth_10103, kk_std_core_types__list _uniq_zz_10139, kk_std_core_types__list _uniq_ys_1_10132_10140, kk_context_t* _ctx); /* (ctx<list<std/os/path/path>>, ? int, list<std/os/path/path>, list<std/os/path/path>) -> <pure,fsys> list<std/os/path/path> */ 

kk_std_core_types__list kk_nagare_io_file__effect__trmc_lift_defaultFileSystem_10196(kk_std_core_types__optional _uniq_max_depth_10103_0, kk_std_core_types__list _uniq_ys_10131, kk_std_core_types__list _uniq_zs_10132, kk_std_core_types__cctx _acc_0, kk_context_t* _ctx); /* (? int, list<std/os/path/path>, list<std/os/path/path>, ctx<list<std/os/path/path>>) -> <div,exn,fsys> list<std/os/path/path> */ 

kk_std_core_types__list kk_nagare_io_file__effect__lift_defaultFileSystem_10196(kk_std_core_types__optional _uniq_max_depth_10103_1, kk_std_core_types__list _uniq_ys_10131_0, kk_std_core_types__list _uniq_zs_10132_0, kk_context_t* _ctx); /* (? int, list<std/os/path/path>, list<std/os/path/path>) -> <div,exn,fsys> list<std/os/path/path> */ 

kk_std_core_types__list kk_nagare_io_file__effect__lift_defaultFileSystem_10195(kk_std_core_types__optional _uniq_max_depth_10103, kk_std_core_types__list _uniq_xs_10127, kk_context_t* _ctx); /* (? int, list<std/os/path/path>) -> <div,exn,fsys> list<std/os/path/path> */ 

kk_std_core_types__list kk_nagare_io_file__effect__mlift_lift_defaultFileSystem_10193_10398(kk_std_core_types__list _uniq_all_10109, kk_std_core_types__list _y_x10268, kk_context_t* _ctx); /* (list<std/os/path/path>, list<std/os/path/path>) -> <div,exn,fsys> list<std/os/path/path> */ 

kk_std_core_types__list kk_nagare_io_file__effect__mlift_lift_defaultFileSystem_10193_10399(kk_std_core_types__list _uniq_all_10109_0, kk_std_core_types__optional _uniq_max_depth_10103, kk_std_core_types__list _uniq_dirs_10110, kk_context_t* _ctx); /* (list<std/os/path/path>, ? int, list<std/os/path/path>) -> <fsys,div,exn> list<std/os/path/path> */ 

kk_std_core_types__list kk_nagare_io_file__effect__mlift_lift_defaultFileSystem_10193_10400(kk_std_core_types__optional _uniq_max_depth_10103_0, kk_std_core_types__list _uniq_all_10109_1, kk_context_t* _ctx); /* (? int, list<std/os/path/path>) -> <exn,fsys> list<std/os/path/path> */ 

kk_std_core_types__list kk_nagare_io_file__effect__lift_defaultFileSystem_10193(kk_string_t p_0, kk_std_core_types__optional _uniq_max_depth_10103_1, kk_context_t* _ctx); /* (p@0 : string, ? int) -> <fsys,pure> list<std/os/path/path> */ 

kk_std_core_types__list kk_nagare_io_file__effect__trmc_lift_defaultFileSystem_10199(kk_std_os_path__path _uniq_dir_10144, kk_std_core_types__list _uniq_xs_10185, kk_std_core_types__cctx _acc, kk_context_t* _ctx); /* (std/os/path/path, list<string>, ctx<list<std/os/path/path>>) -> <exn,fsys> list<std/os/path/path> */ 

kk_std_core_types__list kk_nagare_io_file__effect__lift_defaultFileSystem_10199(kk_std_os_path__path _uniq_dir_10144_0, kk_std_core_types__list _uniq_xs_10185_0, kk_context_t* _ctx); /* (std/os/path/path, list<string>) -> <exn,fsys> list<std/os/path/path> */ 

kk_std_core_types__list kk_nagare_io_file__effect__lift_defaultFileSystem_10198(kk_std_os_path__path _uniq_dir_10144, kk_std_core_types__list _uniq_xs_10180, kk_context_t* _ctx); /* (std/os/path/path, list<string>) -> <exn,fsys> list<std/os/path/path> */ 

kk_std_core_types__list kk_nagare_io_file__effect__lift_defaultFileSystem_10197(kk_string_t p_0, kk_context_t* _ctx); /* (p@0 : string) -> <fsys,exn> list<std/os/path/path> */ 

kk_box_t kk_nagare_io_file__effect_defaultFileSystem(kk_function_t action, kk_context_t* _ctx); /* forall<a> (action : () -> <fileSystem|io> a) -> io a */ 
 
// monadic lift

static inline kk_nagare_io_file__effect__read_handle kk_nagare_io_file__effect__mlift_defaultFileIO_10401(intptr_t _y_x10284, kk_context_t* _ctx) { /* (intptr_t) -> io read-handle */ 
  return kk_nagare_io_file__effect__new_ReadHandle(_y_x10284, _ctx);
}
 
// monadic lift

static inline kk_nagare_io_file__effect__write_handle kk_nagare_io_file__effect__mlift_defaultFileIO_10402(intptr_t _y_x10289, kk_context_t* _ctx) { /* (intptr_t) -> <alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>,fileRead> write-handle */ 
  return kk_nagare_io_file__effect__new_WriteHandle(_y_x10289, _ctx);
}

kk_box_t kk_nagare_io_file__effect_defaultFileIO(kk_function_t action, kk_context_t* _ctx); /* forall<a> (action : () -> <fileIO|io> a) -> io a */ 

void kk_nagare_io_file__effect__init(kk_context_t* _ctx);


void kk_nagare_io_file__effect__done(kk_context_t* _ctx);

#endif // header
