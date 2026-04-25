#pragma once
#ifndef kk_nagare_io_image_H
#define kk_nagare_io_image_H
// Koka generated module: nagare/io/image, koka version: 3.2.3, platform: 64-bit
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
#include "nagare_core_types.h"
#include "nagare_core_stream.h"
#include "nagare_io_file__effect.h"
#include "nagare_io_file.h"
#include "nagare_io_image__effect.h"

// type declarations

// value declarations
 
// Concatenate two byte vectors. Used to accumulate chunks before decoding.

static inline kk_vector_t kk_nagare_io_image_concatBytes(kk_vector_t a, kk_vector_t b, kk_context_t* _ctx) { /* (a : nagare/io/file/bytes, b : nagare/io/file/bytes) -> nagare/io/file/bytes */ 
  kk_std_core_types__list xs_0_10002 = kk_std_core_vector_vlist(a, kk_std_core_types__new_None(_ctx), _ctx); /*list<int8>*/;
  kk_std_core_types__list ys_10003 = kk_std_core_vector_vlist(b, kk_std_core_types__new_None(_ctx), _ctx); /*list<int8>*/;
  kk_std_core_types__list xs_10001;
  if (kk_std_core_types__is_Nil(xs_0_10002, _ctx)) {
    xs_10001 = ys_10003; /*list<int8>*/
  }
  else {
    xs_10001 = kk_std_core_list__unroll_append_10004(xs_0_10002, ys_10003, _ctx); /*list<int8>*/
  }
  return kk_std_core_vector_unvlist(xs_10001, _ctx);
}

kk_vector_t kk_nagare_io_image__lift_unroll_collectBytesPull_10000_10123(kk_std_core_types__list _uniq_xs_10112, kk_vector_t _uniq_z_10113, kk_context_t* _ctx); /* forall<e> (list<nagare/io/file/bytes>, nagare/io/file/bytes) -> <nagare/io/image_effect/imageDecode|e> nagare/io/file/bytes */ 

kk_vector_t kk_nagare_io_image__lift_unroll_collectBytesPull_10000_10122(kk_std_core_types__list _uniq_xs_10106, kk_vector_t _uniq_z_10107, kk_context_t* _ctx); /* forall<e> (list<nagare/io/file/bytes>, nagare/io/file/bytes) -> <nagare/io/image_effect/imageDecode|e> nagare/io/file/bytes */ 

kk_vector_t kk_nagare_io_image__mlift_unroll_collectBytesPull_10000_10182(kk_nagare_core_types__pull tail, kk_vector_t next, kk_context_t* _ctx); /* forall<e> (tail : nagare/core/types/pull<nagare/io/file/bytes,<nagare/io/image_effect/imageDecode|e>>, next : nagare/io/file/bytes) -> <nagare/io/image_effect/imageDecode|e> nagare/io/file/bytes */ 

kk_vector_t kk_nagare_io_image__mlift_unroll_collectBytesPull_10000_10183(kk_vector_t acc, kk_nagare_core_types__pull _y_x10135, kk_context_t* _ctx); /* forall<e> (acc : nagare/io/file/bytes, nagare/core/types/pull<nagare/io/file/bytes,<nagare/io/image_effect/imageDecode|e>>) -> <nagare/io/image_effect/imageDecode|e> nagare/io/file/bytes */ 

kk_vector_t kk_nagare_io_image__mlift_unroll_collectBytesPull_10000_10184(kk_vector_t acc_0, kk_function_t release, kk_nagare_core_types__pull tail_0, kk_unit_t wild__, kk_context_t* _ctx); /* forall<e> (acc : nagare/io/file/bytes, release : () -> <nagare/io/image_effect/imageDecode|e> (), tail@0 : nagare/core/types/pull<nagare/io/file/bytes,<nagare/io/image_effect/imageDecode|e>>, wild_ : ()) -> <nagare/io/image_effect/imageDecode|e> nagare/io/file/bytes */ 

kk_vector_t kk_nagare_io_image__unroll_collectBytesPull_10000(kk_nagare_core_types__pull source, kk_vector_t acc_1, kk_context_t* _ctx); /* forall<e> (source : nagare/core/types/pull<nagare/io/file/bytes,<nagare/io/image_effect/imageDecode|e>>, acc : nagare/io/file/bytes) -> <nagare/io/image_effect/imageDecode|e> nagare/io/file/bytes */ 
 
// unrolling of singleton matches of nagare/io/image/@unroll-collectBytesPull@10000

static inline kk_vector_t kk_nagare_io_image_collectBytesPull(kk_nagare_core_types__pull source, kk_vector_t acc, kk_context_t* _ctx) { /* forall<e> (source : nagare/core/types/pull<nagare/io/file/bytes,<nagare/io/image_effect/imageDecode|e>>, acc : nagare/io/file/bytes) -> <nagare/io/image_effect/imageDecode|e> nagare/io/file/bytes */ 
  if (kk_nagare_core_types__is_PDone(source, _ctx)) {
    return acc;
  }
  {
    return kk_nagare_io_image__unroll_collectBytesPull_10000(source, acc, _ctx);
  }
}
 
// monadic lift

static inline kk_nagare_core_types__pull kk_nagare_io_image__mlift_decodeImageAll_10185(kk_nagare_io_image__effect__image img, kk_context_t* _ctx) { /* forall<e> (img : nagare/io/image_effect/image) -> <nagare/io/image_effect/imageDecode|e> nagare/core/types/pull<nagare/io/image_effect/image,<nagare/io/image_effect/imageDecode|e>> */ 
  kk_nagare_io_image__effect__image _b_x29_31 = img; /*nagare/io/image_effect/image*/;
  kk_std_core_types__list _b_x30_32 = kk_std_core_types__new_Nil(_ctx); /*list<nagare/io/image_effect/image>*/;
  kk_nagare_core_types__chunk _x_x256;
  kk_std_core_types__list _x_x257 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_nagare_io_image__effect__image_box(_b_x29_31, _ctx), _b_x30_32, _ctx); /*list<10021>*/
  _x_x256 = kk_nagare_core_types__new_Chunk(_x_x257, _ctx); /*nagare/core/types/chunk<4>*/
  return kk_nagare_core_types__new_POutput(kk_reuse_null, 0, _x_x256, kk_nagare_core_types__new_PDone(_ctx), _ctx);
}

kk_nagare_core_types__pull kk_nagare_io_image__mlift_decodeImageAll_10186(kk_vector_t _c_x10144, kk_context_t* _ctx); /* forall<e> (nagare/io/file/bytes) -> nagare/core/types/pull<nagare/io/image_effect/image,<nagare/io/image_effect/imageDecode|e>> */ 

kk_nagare_core_types__nstream kk_nagare_io_image_decodeImageAll(kk_nagare_core_types__nstream source, kk_context_t* _ctx); /* forall<e> (source : nagare/core/types/nstream<nagare/io/file/bytes,<nagare/io/image_effect/imageDecode|e>>) -> nagare/core/types/nstream<nagare/io/image_effect/image,<nagare/io/image_effect/imageDecode|e>> */ 

kk_nagare_core_types__pull kk_nagare_io_image__mlift_readImageBytesPull_10187(kk_integer_t chunkSize, kk_nagare_io_file__effect__read_handle h, kk_vector_t chunk, kk_context_t* _ctx); /* (chunkSize : int, h : nagare/io/file_effect/read-handle, chunk : vector<int8>) -> <nagare/io/file_effect/fileRead,div,alloc<global>,console/console,exn,fsys,nagare/io/image_effect/imageDecode,ndet,net,read<global>,ui,write<global>> nagare/core/types/pull<nagare/io/file/bytes,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileRead,fsys,nagare/io/image_effect/imageDecode,ndet,net,read<global>,ui,write<global>>> */ 

kk_nagare_core_types__pull kk_nagare_io_image_readImageBytesPull(kk_nagare_io_file__effect__read_handle h_0, kk_integer_t chunkSize_0, kk_context_t* _ctx); /* (h : nagare/io/file_effect/read-handle, chunkSize : int) -> div nagare/core/types/pull<nagare/io/file/bytes,<nagare/io/file_effect/fileRead,nagare/io/image_effect/imageDecode|io>> */ 
 
// monadic lift

static inline kk_unit_t kk_nagare_io_image__mlift_readImageBytes_10188(kk_ref_t hRef, kk_nagare_io_file__effect__read_handle _y_x10153, kk_context_t* _ctx) { /* (hRef : ref<global,maybe<nagare/io/file_effect/read-handle>>, nagare/io/file_effect/read-handle) -> <nagare/io/file_effect/fileRead,write<global>,alloc<global>,console/console,div,exn,fsys,nagare/io/image_effect/imageDecode,ndet,net,read<global>,ui> () */ 
  kk_unit_t _brw_x209 = kk_Unit;
  kk_box_t _x_x295;
  kk_std_core_types__maybe _x_x296 = kk_std_core_types__new_Just(kk_nagare_io_file__effect__read_handle_box(_y_x10153, _ctx), _ctx); /*maybe<10024>*/
  _x_x295 = kk_std_core_types__maybe_box(_x_x296, _ctx); /*10000*/
  kk_ref_set_borrow(hRef,_x_x295,kk_context());
  kk_ref_drop(hRef, _ctx);
  _brw_x209; return kk_Unit;
}

kk_nagare_core_types__nstream kk_nagare_io_image_readImageBytes(kk_std_os_path__path filepath, kk_std_core_types__optional chunkSize, kk_context_t* _ctx); /* (filepath : std/os/path/path, chunkSize : ? int) -> nagare/core/types/nstream<nagare/io/file/bytes,<nagare/io/file_effect/fileRead,nagare/io/image_effect/imageDecode|io>> */ 

kk_nagare_core_types__nstream kk_nagare_io_image_readImage(kk_std_os_path__path filepath, kk_context_t* _ctx); /* (filepath : std/os/path/path) -> nagare/core/types/nstream<nagare/io/image_effect/image,<nagare/io/file_effect/fileRead,nagare/io/image_effect/imageDecode|io>> */ 

void kk_nagare_io_image__init(kk_context_t* _ctx);


void kk_nagare_io_image__done(kk_context_t* _ctx);

#endif // header
