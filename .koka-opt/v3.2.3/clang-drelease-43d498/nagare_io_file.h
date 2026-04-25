#pragma once
#ifndef kk_nagare_io_file_H
#define kk_nagare_io_file_H
// Koka generated module: nagare/io/file, koka version: 3.2.3, platform: 64-bit
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
#include "nagare_core_stream.h"
#include "nagare_io_file__effect.h"
#include "nagare_core_pull.h"

// type declarations

// value declarations

kk_nagare_core_types__pull kk_nagare_io_file__mlift_readPullBytes_10655(kk_integer_t chunkSize, kk_nagare_io_file__effect__read_handle h, kk_vector_t chunk, kk_context_t* _ctx); /* (chunkSize : int, h : nagare/io/file_effect/read-handle, chunk : vector<int8>) -> <nagare/io/file_effect/fileRead,div,alloc<global>,console/console,exn,fsys,ndet,net,read<global>,ui,write<global>> nagare/core/types/pull<bytes,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileRead,fsys,ndet,net,read<global>,ui,write<global>>> */ 

kk_nagare_core_types__pull kk_nagare_io_file_readPullBytes(kk_nagare_io_file__effect__read_handle h_0, kk_integer_t chunkSize_0, kk_context_t* _ctx); /* (h : nagare/io/file_effect/read-handle, chunkSize : int) -> div nagare/core/types/pull<bytes,<nagare/io/file_effect/fileRead|io>> */ 
 
// monadic lift

static inline kk_unit_t kk_nagare_io_file__mlift_readAllStreamingBytes_10656(kk_ref_t hRef, kk_nagare_io_file__effect__read_handle _y_x10422, kk_context_t* _ctx) { /* (hRef : ref<global,maybe<nagare/io/file_effect/read-handle>>, nagare/io/file_effect/read-handle) -> <nagare/io/file_effect/fileRead,write<global>,alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui> () */ 
  kk_unit_t _brw_x1078 = kk_Unit;
  kk_box_t _x_x1163;
  kk_std_core_types__maybe _x_x1164 = kk_std_core_types__new_Just(kk_nagare_io_file__effect__read_handle_box(_y_x10422, _ctx), _ctx); /*maybe<10024>*/
  _x_x1163 = kk_std_core_types__maybe_box(_x_x1164, _ctx); /*10000*/
  kk_ref_set_borrow(hRef,_x_x1163,kk_context());
  kk_ref_drop(hRef, _ctx);
  _brw_x1078; return kk_Unit;
}

kk_nagare_core_types__nstream kk_nagare_io_file_readAllStreamingBytes(kk_std_os_path__path filepath, kk_std_core_types__optional chunkSize, kk_context_t* _ctx); /* (filepath : std/os/path/path, chunkSize : ? int) -> nagare/io/file_effect/readStream<bytes> */ 

kk_std_core_types__list kk_nagare_io_file__mlift_readAllChunksBytes_10657(kk_std_core_types__list acc, kk_integer_t chunkSize, kk_nagare_io_file__effect__read_handle h, kk_vector_t chunk, kk_context_t* _ctx); /* (acc : list<bytes>, chunkSize : int, h : nagare/io/file_effect/read-handle, chunk : vector<int8>) -> <nagare/io/file_effect/fileRead,alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> list<bytes> */ 

kk_std_core_types__list kk_nagare_io_file_readAllChunksBytes(kk_nagare_io_file__effect__read_handle h_0, kk_integer_t chunkSize_0, kk_std_core_types__list acc_0, kk_context_t* _ctx); /* (h : nagare/io/file_effect/read-handle, chunkSize : int, acc : list<bytes>) -> <io,nagare/io/file_effect/fileRead> list<bytes> */ 
 
// monadic lift

static inline kk_nagare_core_types__pull kk_nagare_io_file__mlift_readAllBytes_10658(kk_std_core_types__list chunks, kk_context_t* _ctx) { /* (chunks : list<bytes>) -> <io,nagare/io/file_effect/fileRead> nagare/core/types/pull<bytes,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileRead,fsys,ndet,net,read<global>,ui,write<global>>> */ 
  kk_nagare_core_types__chunk _x_x1212 = kk_nagare_core_types__new_Chunk(chunks, _ctx); /*nagare/core/types/chunk<4>*/
  return kk_nagare_core_types__new_POutput(kk_reuse_null, 0, _x_x1212, kk_nagare_core_types__new_PDone(_ctx), _ctx);
}

kk_nagare_core_types__nstream kk_nagare_io_file_readAllBytes(kk_std_os_path__path filepath, kk_std_core_types__optional chunkSize, kk_context_t* _ctx); /* (filepath : std/os/path/path, chunkSize : ? int) -> nagare/io/file_effect/readStream<bytes> */ 

kk_unit_t kk_nagare_io_file__mlift_lift_unroll_writeAllChunksBytes_10000_10368_10659(kk_std_core_types__list _uniq_xx_10154, kk_nagare_io_file__effect__write_handle h, kk_integer_t wild__, kk_context_t* _ctx); /* (list<bytes>, h : nagare/io/file_effect/write-handle, wild_ : int) -> <nagare/io/file_effect/fileWrite,alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> () */ 

kk_unit_t kk_nagare_io_file__lift_unroll_writeAllChunksBytes_10000_10368(kk_nagare_io_file__effect__write_handle h_0, kk_std_core_types__list _uniq_xs_10150, kk_context_t* _ctx); /* (h : nagare/io/file_effect/write-handle, list<bytes>) -> <nagare/io/file_effect/fileWrite,alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> () */ 

kk_unit_t kk_nagare_io_file__lift_unroll_writeAllChunksBytes_10000_10367(kk_nagare_io_file__effect__write_handle h, kk_std_core_types__list _uniq_xs_10145, kk_context_t* _ctx); /* (h : nagare/io/file_effect/write-handle, list<bytes>) -> <nagare/io/file_effect/fileWrite,alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> () */ 

kk_unit_t kk_nagare_io_file__mlift_unroll_writeAllChunksBytes_10000_10660(kk_nagare_io_file__effect__write_handle h, kk_nagare_core_types__pull tail, kk_unit_t wild___0, kk_context_t* _ctx); /* (h : nagare/io/file_effect/write-handle, tail : nagare/core/types/pull<bytes,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>>>, wild_@0 : ()) -> <nagare/io/file_effect/fileWrite,alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> () */ 

kk_unit_t kk_nagare_io_file__mlift_unroll_writeAllChunksBytes_10000_10661(kk_nagare_io_file__effect__write_handle h_0, kk_nagare_core_types__pull _y_x10442, kk_context_t* _ctx); /* (h : nagare/io/file_effect/write-handle, nagare/core/types/pull<bytes,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>>>) -> <alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>> () */ 

kk_unit_t kk_nagare_io_file__mlift_unroll_writeAllChunksBytes_10000_10662(kk_nagare_io_file__effect__write_handle h_1, kk_function_t release, kk_nagare_core_types__pull tail_0, kk_unit_t wild___1, kk_context_t* _ctx); /* (h : nagare/io/file_effect/write-handle, release : () -> <alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>> (), tail@0 : nagare/core/types/pull<bytes,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>>>, wild_@1 : ()) -> <alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>> () */ 

kk_unit_t kk_nagare_io_file__unroll_writeAllChunksBytes_10000(kk_nagare_core_types__pull source, kk_nagare_io_file__effect__write_handle h_2, kk_context_t* _ctx); /* (source : nagare/core/types/pull<bytes,<nagare/io/file_effect/fileWrite|io>>, h : nagare/io/file_effect/write-handle) -> <io,nagare/io/file_effect/fileWrite> () */ 
 
// unrolling of singleton matches of nagare/io/file/@unroll-writeAllChunksBytes@10000

static inline kk_unit_t kk_nagare_io_file_writeAllChunksBytes(kk_nagare_core_types__pull source, kk_nagare_io_file__effect__write_handle h, kk_context_t* _ctx) { /* (source : nagare/core/types/pull<bytes,<nagare/io/file_effect/fileWrite|io>>, h : nagare/io/file_effect/write-handle) -> <io,nagare/io/file_effect/fileWrite> () */ 
  if (kk_nagare_core_types__is_PDone(source, _ctx)) {
    kk_Unit; return kk_Unit;
  }
  {
    kk_nagare_io_file__unroll_writeAllChunksBytes_10000(source, h, _ctx); return kk_Unit;
  }
}
 
// monadic lift

static inline kk_nagare_core_types__pull kk_nagare_io_file__mlift_writeAllBytes_10663(kk_unit_t _c_x10451, kk_context_t* _ctx) { /* (()) -> nagare/core/types/pull<(),<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>>> */ 
  kk_unit_t _b_x221_223 = kk_Unit;
  kk_std_core_types__list _b_x222_224 = kk_std_core_types__new_Nil(_ctx); /*list<()>*/;
  kk_nagare_core_types__chunk _x_x1250;
  kk_std_core_types__list _x_x1251 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_unit_box(_b_x221_223), _b_x222_224, _ctx); /*list<10021>*/
  _x_x1250 = kk_nagare_core_types__new_Chunk(_x_x1251, _ctx); /*nagare/core/types/chunk<4>*/
  return kk_nagare_core_types__new_POutput(kk_reuse_null, 0, _x_x1250, kk_nagare_core_types__new_PDone(_ctx), _ctx);
}

kk_function_t kk_nagare_io_file_writeAllBytes(kk_std_os_path__path filepath, kk_context_t* _ctx); /* (filepath : std/os/path/path) -> nagare/io/file_effect/writePipe<bytes,()> */ 

kk_std_core_types__tuple2 kk_nagare_io_file_trydecode_utf8_partial(kk_std_core_types__list buf, kk_context_t* _ctx); /* (buf : list<int8>) -> (string, list<int8>) */ 

kk_std_core_types__list kk_nagare_io_file__lift_unroll_decodeUtf8Pull_10001_10370(kk_std_core_types__list _uniq_xs_10164, kk_std_core_types__list _uniq_z_10165, kk_context_t* _ctx); /* (list<bytes>, list<int8>) -> list<int8> */ 

kk_std_core_types__list kk_nagare_io_file__lift_unroll_decodeUtf8Pull_10001_10369(kk_std_core_types__list _uniq_xs_10158, kk_std_core_types__list _uniq_z_10159, kk_context_t* _ctx); /* (list<bytes>, list<int8>) -> list<int8> */ 

kk_nagare_core_types__pull kk_nagare_io_file__mlift_trmc_unroll_decodeUtf8Pull_10001_10664(kk_std_core_types__list leftover, kk_nagare_core_types__pull _y_x10457, kk_context_t* _ctx); /* forall<e> (leftover : list<int8>, nagare/core/types/pull<bytes,e>) -> e nagare/core/types/pull<string,e> */ 

kk_nagare_core_types__pull kk_nagare_io_file__trmc_unroll_decodeUtf8Pull_10001(kk_nagare_core_types__pull source, kk_std_core_types__list leftover_0, kk_std_core_types__cctx _acc, kk_context_t* _ctx); /* forall<e> (source : nagare/core/types/pull<bytes,e>, leftover : list<int8>, ctx<nagare/core/types/pull<string,e>>) -> nagare/core/types/pull<string,e> */ 

kk_nagare_core_types__pull kk_nagare_io_file__unroll_decodeUtf8Pull_10001(kk_nagare_core_types__pull source_0, kk_std_core_types__list leftover_1, kk_context_t* _ctx); /* forall<e> (source : nagare/core/types/pull<bytes,e>, leftover : list<int8>) -> nagare/core/types/pull<string,e> */ 
 
// unrolling of singleton matches of nagare/io/file/@unroll-decodeUtf8Pull@10001

static inline kk_nagare_core_types__pull kk_nagare_io_file_decodeUtf8Pull(kk_nagare_core_types__pull source, kk_std_core_types__list leftover, kk_context_t* _ctx) { /* forall<e> (source : nagare/core/types/pull<bytes,e>, leftover : list<int8>) -> nagare/core/types/pull<string,e> */ 
  if (kk_nagare_core_types__is_PDone(source, _ctx)) {
    if (kk_std_core_types__is_Nil(leftover, _ctx)) {
      return kk_nagare_core_types__new_PDone(_ctx);
    }
    {
      kk_std_core_types__list_drop(leftover, _ctx);
      kk_string_t _b_x302_304;
      kk_define_string_literal(static, _s_x1301, 3, "" "\xEF\xBF\xBD" "", _ctx)
      _b_x302_304 = kk_string_dup(_s_x1301, _ctx); /*string*/
      kk_std_core_types__list _b_x303_305 = kk_std_core_types__new_Nil(_ctx); /*list<string>*/;
      kk_nagare_core_types__chunk _x_x1302;
      kk_std_core_types__list _x_x1303 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_string_box(_b_x302_304), _b_x303_305, _ctx); /*list<10021>*/
      _x_x1302 = kk_nagare_core_types__new_Chunk(_x_x1303, _ctx); /*nagare/core/types/chunk<4>*/
      return kk_nagare_core_types__new_POutput(kk_reuse_null, 0, _x_x1302, kk_nagare_core_types__new_PDone(_ctx), _ctx);
    }
  }
  {
    kk_std_core_types__cctx _x_x1304 = kk_cctx_empty(kk_context()); /*ctx<0>*/
    return kk_nagare_io_file__trmc_unroll_decodeUtf8Pull_10001(source, leftover, _x_x1304, _ctx);
  }
}
 
// monadic lift

static inline kk_nagare_core_types__nstream kk_nagare_io_file__mlift_decodeUtf8_10665(kk_nagare_core_types__pull _c_x10462, kk_context_t* _ctx) { /* forall<e> (nagare/core/types/pull<string,e>) -> nagare/core/types/nstream<string,e> */ 
  return kk_nagare_core_types__new_Stream(_c_x10462, _ctx);
}

kk_nagare_core_types__nstream kk_nagare_io_file_decodeUtf8(kk_nagare_core_types__nstream source, kk_context_t* _ctx); /* forall<e> (source : nagare/core/types/nstream<bytes,e>) -> nagare/core/types/nstream<string,e> */ 

kk_nagare_core_types__pull kk_nagare_io_file__mlift_readPull_10666(kk_integer_t chunkSize, kk_nagare_io_file__effect__read_handle h, kk_string_t chunk, kk_context_t* _ctx); /* (chunkSize : int, h : nagare/io/file_effect/read-handle, chunk : string) -> <nagare/io/file_effect/fileRead,div,alloc<global>,console/console,exn,fsys,ndet,net,read<global>,ui,write<global>> nagare/core/types/pull<string,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileRead,fsys,ndet,net,read<global>,ui,write<global>>> */ 

kk_nagare_core_types__pull kk_nagare_io_file_readPull(kk_nagare_io_file__effect__read_handle h_0, kk_integer_t chunkSize_0, kk_context_t* _ctx); /* (h : nagare/io/file_effect/read-handle, chunkSize : int) -> div nagare/core/types/pull<string,<nagare/io/file_effect/fileRead|io>> */ 

kk_std_core_types__tuple2 kk_nagare_io_file_splitByNewline(kk_string_t s, kk_context_t* _ctx); /* (s : string) -> (list<string>, string) */ 

kk_nagare_core_types__pull kk_nagare_io_file__mlift_trmc_unroll_splitLinesPull_10002_10667(kk_string_t buffer, kk_nagare_core_types__pull _y_x10471, kk_context_t* _ctx); /* forall<e> (buffer : string, nagare/core/types/pull<string,e>) -> e nagare/core/types/pull<string,e> */ 

kk_nagare_core_types__pull kk_nagare_io_file__trmc_unroll_splitLinesPull_10002(kk_nagare_core_types__pull source, kk_string_t buffer_0, kk_std_core_types__cctx _acc, kk_context_t* _ctx); /* forall<e> (source : nagare/core/types/pull<string,e>, buffer : string, ctx<nagare/core/types/pull<string,e>>) -> nagare/core/types/pull<string,e> */ 

kk_nagare_core_types__pull kk_nagare_io_file__unroll_splitLinesPull_10002(kk_nagare_core_types__pull source_0, kk_string_t buffer_1, kk_context_t* _ctx); /* forall<e> (source : nagare/core/types/pull<string,e>, buffer : string) -> nagare/core/types/pull<string,e> */ 
 
// unrolling of singleton matches of nagare/io/file/@unroll-splitLinesPull@10002

static inline kk_nagare_core_types__pull kk_nagare_io_file_splitLinesPull(kk_nagare_core_types__pull source, kk_string_t buffer, kk_context_t* _ctx) { /* forall<e> (source : nagare/core/types/pull<string,e>, buffer : string) -> nagare/core/types/pull<string,e> */ 
  if (kk_nagare_core_types__is_PDone(source, _ctx)) {
    bool _match_x1036;
    kk_string_t _x_x1375 = kk_string_dup(buffer, _ctx); /*string*/
    kk_string_t _x_x1376 = kk_string_empty(); /*string*/
    _match_x1036 = kk_string_is_eq(_x_x1375,_x_x1376,kk_context()); /*bool*/
    if (_match_x1036) {
      kk_string_drop(buffer, _ctx);
      return kk_nagare_core_types__new_PDone(_ctx);
    }
    {
      kk_string_t _b_x418_420 = buffer; /*string*/;
      kk_std_core_types__list _b_x419_421 = kk_std_core_types__new_Nil(_ctx); /*list<string>*/;
      kk_nagare_core_types__chunk _x_x1378;
      kk_std_core_types__list _x_x1379 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_string_box(_b_x418_420), _b_x419_421, _ctx); /*list<10021>*/
      _x_x1378 = kk_nagare_core_types__new_Chunk(_x_x1379, _ctx); /*nagare/core/types/chunk<4>*/
      return kk_nagare_core_types__new_POutput(kk_reuse_null, 0, _x_x1378, kk_nagare_core_types__new_PDone(_ctx), _ctx);
    }
  }
  {
    kk_std_core_types__cctx _x_x1380 = kk_cctx_empty(kk_context()); /*ctx<0>*/
    return kk_nagare_io_file__trmc_unroll_splitLinesPull_10002(source, buffer, _x_x1380, _ctx);
  }
}

kk_std_core_types__list kk_nagare_io_file__mlift_readAllChunks_10668(kk_std_core_types__list acc, kk_integer_t chunkSize, kk_nagare_io_file__effect__read_handle h, kk_string_t chunk, kk_context_t* _ctx); /* (acc : list<string>, chunkSize : int, h : nagare/io/file_effect/read-handle, chunk : string) -> <nagare/io/file_effect/fileRead,alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> list<string> */ 

kk_std_core_types__list kk_nagare_io_file_readAllChunks(kk_nagare_io_file__effect__read_handle h_0, kk_integer_t chunkSize_0, kk_std_core_types__list acc_0, kk_context_t* _ctx); /* (h : nagare/io/file_effect/read-handle, chunkSize : int, acc : list<string>) -> <io,nagare/io/file_effect/fileRead> list<string> */ 
 
// monadic lift

static inline kk_nagare_core_types__pull kk_nagare_io_file__mlift_readAll_10669(kk_std_core_types__list chunks, kk_context_t* _ctx) { /* (chunks : list<string>) -> <io,nagare/io/file_effect/fileRead> nagare/core/types/pull<string,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileRead,fsys,ndet,net,read<global>,ui,write<global>>> */ 
  kk_nagare_core_types__chunk _x_x1398 = kk_nagare_core_types__new_Chunk(chunks, _ctx); /*nagare/core/types/chunk<4>*/
  return kk_nagare_core_types__new_POutput(kk_reuse_null, 0, _x_x1398, kk_nagare_core_types__new_PDone(_ctx), _ctx);
}

kk_nagare_core_types__nstream kk_nagare_io_file_readAll(kk_std_os_path__path filepath, kk_std_core_types__optional chunkSize, kk_context_t* _ctx); /* (filepath : std/os/path/path, chunkSize : ? int) -> nagare/io/file_effect/readStream<string> */ 
 
// monadic lift

static inline kk_nagare_core_types__nstream kk_nagare_io_file__mlift_splitLines_10670(kk_nagare_core_types__pull _c_x10482, kk_context_t* _ctx) { /* forall<e> (nagare/core/types/pull<string,e>) -> nagare/core/types/nstream<string,e> */ 
  return kk_nagare_core_types__new_Stream(_c_x10482, _ctx);
}

kk_nagare_core_types__nstream kk_nagare_io_file_splitLines(kk_nagare_core_types__nstream source, kk_context_t* _ctx); /* forall<e> (source : nagare/core/types/nstream<string,e>) -> nagare/core/types/nstream<string,e> */ 
 
// monadic lift

static inline kk_unit_t kk_nagare_io_file__mlift_readAllStreaming_10671(kk_ref_t hRef, kk_nagare_io_file__effect__read_handle _y_x10485, kk_context_t* _ctx) { /* (hRef : ref<global,maybe<nagare/io/file_effect/read-handle>>, nagare/io/file_effect/read-handle) -> <nagare/io/file_effect/fileRead,write<global>,alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui> () */ 
  kk_unit_t _brw_x1026 = kk_Unit;
  kk_box_t _x_x1429;
  kk_std_core_types__maybe _x_x1430 = kk_std_core_types__new_Just(kk_nagare_io_file__effect__read_handle_box(_y_x10485, _ctx), _ctx); /*maybe<10024>*/
  _x_x1429 = kk_std_core_types__maybe_box(_x_x1430, _ctx); /*10000*/
  kk_ref_set_borrow(hRef,_x_x1429,kk_context());
  kk_ref_drop(hRef, _ctx);
  _brw_x1026; return kk_Unit;
}

kk_nagare_core_types__nstream kk_nagare_io_file_readAllStreaming(kk_std_os_path__path filepath, kk_std_core_types__optional chunkSize, kk_context_t* _ctx); /* (filepath : std/os/path/path, chunkSize : ? int) -> nagare/io/file_effect/readStream<string> */ 

kk_nagare_core_types__nstream kk_nagare_io_file_readLines(kk_std_os_path__path filepath, kk_std_core_types__optional chunkSize, kk_context_t* _ctx); /* (filepath : std/os/path/path, chunkSize : ? int) -> nagare/io/file_effect/readStream<string> */ 
 
// monadic lift

static inline kk_nagare_core_types__pull kk_nagare_io_file__mlift_readUtf8_10672(kk_string_t _y_x10491, kk_context_t* _ctx) { /* (string) -> <nagare/io/file_effect/fileRead,alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> nagare/core/types/pull<string,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileRead,fsys,ndet,net,read<global>,ui,write<global>>> */ 
  kk_string_t _b_x563_565 = _y_x10491; /*string*/;
  kk_std_core_types__list _b_x564_566 = kk_std_core_types__new_Nil(_ctx); /*list<string>*/;
  kk_nagare_core_types__chunk _x_x1468;
  kk_std_core_types__list _x_x1469 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_string_box(_b_x563_565), _b_x564_566, _ctx); /*list<10021>*/
  _x_x1468 = kk_nagare_core_types__new_Chunk(_x_x1469, _ctx); /*nagare/core/types/chunk<4>*/
  return kk_nagare_core_types__new_POutput(kk_reuse_null, 0, _x_x1468, kk_nagare_core_types__new_PDone(_ctx), _ctx);
}

kk_nagare_core_types__nstream kk_nagare_io_file_readUtf8(kk_std_os_path__path filepath, kk_context_t* _ctx); /* (filepath : std/os/path/path) -> nagare/io/file_effect/readStream<string> */ 

kk_unit_t kk_nagare_io_file__mlift_lift_unroll_writeAllChunks_10003_10372_10673(kk_std_core_types__list _uniq_xx_10183, kk_nagare_io_file__effect__write_handle h, kk_integer_t wild__, kk_context_t* _ctx); /* (list<string>, h : nagare/io/file_effect/write-handle, wild_ : int) -> <nagare/io/file_effect/fileWrite,alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> () */ 

kk_unit_t kk_nagare_io_file__lift_unroll_writeAllChunks_10003_10372(kk_nagare_io_file__effect__write_handle h_0, kk_std_core_types__list _uniq_xs_10179, kk_context_t* _ctx); /* (h : nagare/io/file_effect/write-handle, list<string>) -> <nagare/io/file_effect/fileWrite,alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> () */ 

kk_unit_t kk_nagare_io_file__lift_unroll_writeAllChunks_10003_10371(kk_nagare_io_file__effect__write_handle h, kk_std_core_types__list _uniq_xs_10174, kk_context_t* _ctx); /* (h : nagare/io/file_effect/write-handle, list<string>) -> <nagare/io/file_effect/fileWrite,alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> () */ 

kk_unit_t kk_nagare_io_file__mlift_unroll_writeAllChunks_10003_10674(kk_nagare_io_file__effect__write_handle h, kk_nagare_core_types__pull tail, kk_unit_t wild___0, kk_context_t* _ctx); /* (h : nagare/io/file_effect/write-handle, tail : nagare/core/types/pull<string,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>>>, wild_@0 : ()) -> <nagare/io/file_effect/fileWrite,alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> () */ 

kk_unit_t kk_nagare_io_file__mlift_unroll_writeAllChunks_10003_10675(kk_nagare_io_file__effect__write_handle h_0, kk_nagare_core_types__pull _y_x10501, kk_context_t* _ctx); /* (h : nagare/io/file_effect/write-handle, nagare/core/types/pull<string,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>>>) -> <alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>> () */ 

kk_unit_t kk_nagare_io_file__mlift_unroll_writeAllChunks_10003_10676(kk_nagare_io_file__effect__write_handle h_1, kk_function_t release, kk_nagare_core_types__pull tail_0, kk_unit_t wild___1, kk_context_t* _ctx); /* (h : nagare/io/file_effect/write-handle, release : () -> <alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>> (), tail@0 : nagare/core/types/pull<string,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>>>, wild_@1 : ()) -> <alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>> () */ 

kk_unit_t kk_nagare_io_file__unroll_writeAllChunks_10003(kk_nagare_core_types__pull source, kk_nagare_io_file__effect__write_handle h_2, kk_context_t* _ctx); /* (source : nagare/core/types/pull<string,<nagare/io/file_effect/fileWrite|io>>, h : nagare/io/file_effect/write-handle) -> <io,nagare/io/file_effect/fileWrite> () */ 
 
// unrolling of singleton matches of nagare/io/file/@unroll-writeAllChunks@10003

static inline kk_unit_t kk_nagare_io_file_writeAllChunks(kk_nagare_core_types__pull source, kk_nagare_io_file__effect__write_handle h, kk_context_t* _ctx) { /* (source : nagare/core/types/pull<string,<nagare/io/file_effect/fileWrite|io>>, h : nagare/io/file_effect/write-handle) -> <io,nagare/io/file_effect/fileWrite> () */ 
  if (kk_nagare_core_types__is_PDone(source, _ctx)) {
    kk_Unit; return kk_Unit;
  }
  {
    kk_nagare_io_file__unroll_writeAllChunks_10003(source, h, _ctx); return kk_Unit;
  }
}
 
// monadic lift

static inline kk_nagare_core_types__pull kk_nagare_io_file__mlift_writeAll_10677(kk_unit_t _c_x10510, kk_context_t* _ctx) { /* (()) -> nagare/core/types/pull<(),<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>>> */ 
  kk_unit_t _b_x652_654 = kk_Unit;
  kk_std_core_types__list _b_x653_655 = kk_std_core_types__new_Nil(_ctx); /*list<()>*/;
  kk_nagare_core_types__chunk _x_x1508;
  kk_std_core_types__list _x_x1509 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_unit_box(_b_x652_654), _b_x653_655, _ctx); /*list<10021>*/
  _x_x1508 = kk_nagare_core_types__new_Chunk(_x_x1509, _ctx); /*nagare/core/types/chunk<4>*/
  return kk_nagare_core_types__new_POutput(kk_reuse_null, 0, _x_x1508, kk_nagare_core_types__new_PDone(_ctx), _ctx);
}

kk_function_t kk_nagare_io_file_writeAll(kk_std_os_path__path filepath, kk_context_t* _ctx); /* (filepath : std/os/path/path) -> nagare/io/file_effect/writePipe<string,()> */ 

kk_std_core_types__list kk_nagare_io_file__trmc_lift_writeLines_10377(kk_std_core_types__list _uniq_xs_10217, kk_std_core_types__cctx _acc, kk_context_t* _ctx); /* (list<string>, ctx<list<string>>) -> list<string> */ 

kk_std_core_types__list kk_nagare_io_file__lift_writeLines_10377(kk_std_core_types__list _uniq_xs_10217_0, kk_context_t* _ctx); /* (list<string>) -> list<string> */ 

kk_std_core_types__list kk_nagare_io_file__lift_writeLines_10376(kk_std_core_types__list _uniq_xs_10212, kk_context_t* _ctx); /* (list<string>) -> list<string> */ 

kk_nagare_core_types__pull kk_nagare_io_file__mlift_trmc_lift_writeLines_10375_10678(kk_nagare_core_types__pull _y_x10512, kk_context_t* _ctx); /* (nagare/core/types/pull<string,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>>>) -> <alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>> nagare/core/types/pull<string,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>>> */ 

kk_nagare_core_types__pull kk_nagare_io_file__trmc_lift_writeLines_10375(kk_nagare_core_types__pull _uniq_source_10197, kk_std_core_types__cctx _acc, kk_context_t* _ctx); /* (nagare/core/types/pull<string,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>>>, ctx<nagare/core/types/pull<string,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>>>>) -> nagare/core/types/pull<string,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>>> */ 

kk_nagare_core_types__pull kk_nagare_io_file__lift_writeLines_10375(kk_nagare_core_types__pull _uniq_source_10197_0, kk_context_t* _ctx); /* (nagare/core/types/pull<string,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>>>) -> nagare/core/types/pull<string,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>>> */ 

kk_nagare_core_types__pull kk_nagare_io_file__lift_writeLines_10374(kk_nagare_core_types__pull _uniq_source_10192, kk_context_t* _ctx); /* (nagare/core/types/pull<string,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>>>) -> nagare/core/types/pull<string,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>>> */ 

kk_nagare_core_types__nstream kk_nagare_io_file__lift_writeLines_10373(kk_nagare_core_types__nstream _uniq_source_10187, kk_context_t* _ctx); /* (nagare/core/types/nstream<string,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>>>) -> nagare/core/types/nstream<string,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileWrite,fsys,ndet,net,read<global>,ui,write<global>>> */ 
 
// Write a stream of strings as lines (appends newline to each element).


// lift anonymous function
struct kk_nagare_io_file_writeLines_fun1556__t {
  struct kk_function_s _base;
  kk_std_os_path__path filepath;
};
extern kk_nagare_core_types__nstream kk_nagare_io_file_writeLines_fun1556(kk_function_t _fself, kk_nagare_core_types__nstream source, kk_context_t* _ctx);
static inline kk_function_t kk_nagare_io_file_new_writeLines_fun1556(kk_std_os_path__path filepath, kk_context_t* _ctx) {
  struct kk_nagare_io_file_writeLines_fun1556__t* _self = kk_function_alloc_as(struct kk_nagare_io_file_writeLines_fun1556__t, 3, _ctx);
  _self->_base.fun = kk_kkfun_ptr_box(&kk_nagare_io_file_writeLines_fun1556, kk_context());
  _self->filepath = filepath;
  return kk_datatype_from_base(&_self->_base, kk_context());
}


static inline kk_function_t kk_nagare_io_file_writeLines(kk_std_os_path__path filepath, kk_context_t* _ctx) { /* (filepath : std/os/path/path) -> nagare/io/file_effect/writePipe<string,()> */ 
  return kk_nagare_io_file_new_writeLines_fun1556(filepath, _ctx);
}
 
// Alias for writeAll (Koka strings are UTF-8).

static inline kk_function_t kk_nagare_io_file_writeUtf8(kk_std_os_path__path filepath, kk_context_t* _ctx) { /* (filepath : std/os/path/path) -> nagare/io/file_effect/writePipe<string,()> */ 
  return kk_nagare_io_file_writeAll(filepath, _ctx);
}

kk_nagare_core_types__pull kk_nagare_io_file__mlift_lift_listDir_10382_10679(kk_std_core_types__list _uniq_xt_10264, kk_nagare_core_types__pull _y_x10516, kk_context_t* _ctx); /* (list<list<std/os/path/path>>, nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>) -> <alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>> nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>> */ 

kk_nagare_core_types__pull kk_nagare_io_file__lift_listDir_10382(kk_std_core_types__list _uniq_xt_10264_0, kk_nagare_core_types__pull _uniq_left_10270, kk_context_t* _ctx); /* (list<list<std/os/path/path>>, nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>) -> nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>> */ 

kk_nagare_core_types__pull kk_nagare_io_file__lift_listDir_10381(kk_std_core_types__list _uniq_values_10259, kk_context_t* _ctx); /* (list<list<std/os/path/path>>) -> nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>> */ 

kk_nagare_core_types__pull kk_nagare_io_file__mlift_lift_listDir_10383_10680(kk_nagare_core_types__pull _uniq_tail_10244, kk_nagare_core_types__pull _y_x10519, kk_context_t* _ctx); /* (nagare/core/types/pull<list<std/os/path/path>,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>, nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>) -> <alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>> nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>> */ 

kk_nagare_core_types__pull kk_nagare_io_file__mlift_lift_listDir_10380_10681(kk_nagare_core_types__pull _uniq_tail_10244_0, kk_nagare_core_types__pull _c_x10521, kk_context_t* _ctx); /* (nagare/core/types/pull<list<std/os/path/path>,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>, nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>) -> nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>> */ 

kk_nagare_core_types__pull kk_nagare_io_file__mlift_lift_listDir_10380_10682(kk_nagare_core_types__pull _y_x10523, kk_context_t* _ctx); /* (nagare/core/types/pull<list<std/os/path/path>,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>) -> <alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>> nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>> */ 

kk_nagare_core_types__pull kk_nagare_io_file__lift_listDir_10383(kk_nagare_core_types__pull _uniq_tail_10244_1, kk_nagare_core_types__pull _uniq_left_10283, kk_context_t* _ctx); /* (nagare/core/types/pull<list<std/os/path/path>,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>, nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>) -> nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>> */ 

kk_nagare_core_types__pull kk_nagare_io_file__lift_listDir_10380(kk_nagare_core_types__pull _uniq_source_10239, kk_context_t* _ctx); /* (nagare/core/types/pull<list<std/os/path/path>,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>) -> nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>> */ 

kk_nagare_core_types__pull kk_nagare_io_file__lift_listDir_10379(kk_nagare_core_types__pull _uniq_source_10234, kk_context_t* _ctx); /* (nagare/core/types/pull<list<std/os/path/path>,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>) -> nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>> */ 

kk_nagare_core_types__nstream kk_nagare_io_file__lift_listDir_10378(kk_nagare_core_types__nstream _uniq_source_10225, kk_context_t* _ctx); /* (nagare/core/types/nstream<list<std/os/path/path>,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>) -> nagare/core/types/nstream<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>> */ 
 
// monadic lift

static inline kk_nagare_core_types__pull kk_nagare_io_file__mlift_listDir_10683(kk_std_core_types__list _y_x10528, kk_context_t* _ctx) { /* (list<std/os/path/path>) -> <nagare/io/file_effect/fileSystem,alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> nagare/core/types/pull<list<std/os/path/path>,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>> */ 
  kk_std_core_types__list _b_x758_760 = _y_x10528; /*list<std/os/path/path>*/;
  kk_std_core_types__list _b_x759_761 = kk_std_core_types__new_Nil(_ctx); /*list<list<std/os/path/path>>*/;
  kk_nagare_core_types__chunk _x_x1595;
  kk_std_core_types__list _x_x1596 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_std_core_types__list_box(_b_x758_760, _ctx), _b_x759_761, _ctx); /*list<10021>*/
  _x_x1595 = kk_nagare_core_types__new_Chunk(_x_x1596, _ctx); /*nagare/core/types/chunk<4>*/
  return kk_nagare_core_types__new_POutput(kk_reuse_null, 0, _x_x1595, kk_nagare_core_types__new_PDone(_ctx), _ctx);
}

kk_nagare_core_types__nstream kk_nagare_io_file_listDir(kk_std_os_path__path dir, kk_context_t* _ctx); /* (dir : std/os/path/path) -> nagare/io/file_effect/fsStream<std/os/path/path> */ 

kk_nagare_core_types__pull kk_nagare_io_file__mlift_lift_walk_10388_10684(kk_std_core_types__list _uniq_xt_10335, kk_nagare_core_types__pull _y_x10529, kk_context_t* _ctx); /* (list<list<std/os/path/path>>, nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>) -> <alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>> nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>> */ 

kk_nagare_core_types__pull kk_nagare_io_file__lift_walk_10388(kk_std_core_types__list _uniq_xt_10335_0, kk_nagare_core_types__pull _uniq_left_10341, kk_context_t* _ctx); /* (list<list<std/os/path/path>>, nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>) -> nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>> */ 

kk_nagare_core_types__pull kk_nagare_io_file__lift_walk_10387(kk_std_core_types__list _uniq_values_10330, kk_context_t* _ctx); /* (list<list<std/os/path/path>>) -> nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>> */ 

kk_nagare_core_types__pull kk_nagare_io_file__mlift_lift_walk_10389_10685(kk_nagare_core_types__pull _uniq_tail_10315, kk_nagare_core_types__pull _y_x10532, kk_context_t* _ctx); /* (nagare/core/types/pull<list<std/os/path/path>,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>, nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>) -> <alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>> nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>> */ 

kk_nagare_core_types__pull kk_nagare_io_file__mlift_lift_walk_10386_10686(kk_nagare_core_types__pull _uniq_tail_10315_0, kk_nagare_core_types__pull _c_x10534, kk_context_t* _ctx); /* (nagare/core/types/pull<list<std/os/path/path>,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>, nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>) -> nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>> */ 

kk_nagare_core_types__pull kk_nagare_io_file__mlift_lift_walk_10386_10687(kk_nagare_core_types__pull _y_x10536, kk_context_t* _ctx); /* (nagare/core/types/pull<list<std/os/path/path>,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>) -> <alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>> nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>> */ 

kk_nagare_core_types__pull kk_nagare_io_file__lift_walk_10389(kk_nagare_core_types__pull _uniq_tail_10315_1, kk_nagare_core_types__pull _uniq_left_10354, kk_context_t* _ctx); /* (nagare/core/types/pull<list<std/os/path/path>,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>, nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>) -> nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>> */ 

kk_nagare_core_types__pull kk_nagare_io_file__lift_walk_10386(kk_nagare_core_types__pull _uniq_source_10310, kk_context_t* _ctx); /* (nagare/core/types/pull<list<std/os/path/path>,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>) -> nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>> */ 

kk_nagare_core_types__pull kk_nagare_io_file__lift_walk_10385(kk_nagare_core_types__pull _uniq_source_10305, kk_context_t* _ctx); /* (nagare/core/types/pull<list<std/os/path/path>,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>) -> nagare/core/types/pull<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>> */ 

kk_nagare_core_types__nstream kk_nagare_io_file__lift_walk_10384(kk_nagare_core_types__nstream _uniq_source_10296, kk_context_t* _ctx); /* (nagare/core/types/nstream<list<std/os/path/path>,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>>) -> nagare/core/types/nstream<std/os/path/path,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>> */ 
 
// monadic lift

static inline kk_nagare_core_types__pull kk_nagare_io_file__mlift_walk_10688(kk_std_core_types__list _y_x10541, kk_context_t* _ctx) { /* (list<std/os/path/path>) -> <nagare/io/file_effect/fileSystem,alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> nagare/core/types/pull<list<std/os/path/path>,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>> */ 
  kk_std_core_types__list _b_x825_827 = _y_x10541; /*list<std/os/path/path>*/;
  kk_std_core_types__list _b_x826_828 = kk_std_core_types__new_Nil(_ctx); /*list<list<std/os/path/path>>*/;
  kk_nagare_core_types__chunk _x_x1654;
  kk_std_core_types__list _x_x1655 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_std_core_types__list_box(_b_x825_827, _ctx), _b_x826_828, _ctx); /*list<10021>*/
  _x_x1654 = kk_nagare_core_types__new_Chunk(_x_x1655, _ctx); /*nagare/core/types/chunk<4>*/
  return kk_nagare_core_types__new_POutput(kk_reuse_null, 0, _x_x1654, kk_nagare_core_types__new_PDone(_ctx), _ctx);
}

kk_nagare_core_types__nstream kk_nagare_io_file_walk(kk_std_os_path__path dir, kk_std_core_types__optional maxDepth, kk_context_t* _ctx); /* (dir : std/os/path/path, maxDepth : ? int) -> nagare/io/file_effect/fsStream<std/os/path/path> */ 
 
// monadic lift

static inline kk_nagare_core_types__pull kk_nagare_io_file__mlift_pathExists_10689(bool _y_x10543, kk_context_t* _ctx) { /* (bool) -> <nagare/io/file_effect/fileSystem,alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> nagare/core/types/pull<bool,<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>> */ 
  bool _b_x871_873 = _y_x10543; /*bool*/;
  kk_std_core_types__list _b_x872_874 = kk_std_core_types__new_Nil(_ctx); /*list<bool>*/;
  kk_nagare_core_types__chunk _x_x1677;
  kk_std_core_types__list _x_x1678 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_bool_box(_b_x871_873), _b_x872_874, _ctx); /*list<10021>*/
  _x_x1677 = kk_nagare_core_types__new_Chunk(_x_x1678, _ctx); /*nagare/core/types/chunk<4>*/
  return kk_nagare_core_types__new_POutput(kk_reuse_null, 0, _x_x1677, kk_nagare_core_types__new_PDone(_ctx), _ctx);
}

kk_nagare_core_types__nstream kk_nagare_io_file_pathExists(kk_std_os_path__path filepath, kk_context_t* _ctx); /* (filepath : std/os/path/path) -> nagare/io/file_effect/fsStream<bool> */ 
 
// monadic lift

static inline kk_nagare_core_types__pull kk_nagare_io_file__mlift_createDir_10690(kk_unit_t _y_x10544, kk_context_t* _ctx) { /* (()) -> <exn,fsys> nagare/core/types/pull<(),io> */ 
  kk_unit_t _b_x910_912 = kk_Unit;
  _y_x10544;
  kk_std_core_types__list _b_x911_913 = kk_std_core_types__new_Nil(_ctx); /*list<()>*/;
  kk_nagare_core_types__chunk _x_x1695;
  kk_std_core_types__list _x_x1696 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_unit_box(_b_x910_912), _b_x911_913, _ctx); /*list<10021>*/
  _x_x1695 = kk_nagare_core_types__new_Chunk(_x_x1696, _ctx); /*nagare/core/types/chunk<4>*/
  return kk_nagare_core_types__new_POutput(kk_reuse_null, 0, _x_x1695, kk_nagare_core_types__new_PDone(_ctx), _ctx);
}

kk_nagare_core_types__nstream kk_nagare_io_file_createDir(kk_std_os_path__path dir, kk_context_t* _ctx); /* (dir : std/os/path/path) -> nagare/core/types/iostream<()> */ 
 
// monadic lift

static inline kk_nagare_core_types__pull kk_nagare_io_file__mlift_fileCopy_10691(kk_unit_t _y_x10545, kk_context_t* _ctx) { /* (()) -> <exn,fsys> nagare/core/types/pull<(),io> */ 
  kk_unit_t _b_x921_923 = kk_Unit;
  _y_x10545;
  kk_std_core_types__list _b_x922_924 = kk_std_core_types__new_Nil(_ctx); /*list<()>*/;
  kk_nagare_core_types__chunk _x_x1705;
  kk_std_core_types__list _x_x1706 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_unit_box(_b_x921_923), _b_x922_924, _ctx); /*list<10021>*/
  _x_x1705 = kk_nagare_core_types__new_Chunk(_x_x1706, _ctx); /*nagare/core/types/chunk<4>*/
  return kk_nagare_core_types__new_POutput(kk_reuse_null, 0, _x_x1705, kk_nagare_core_types__new_PDone(_ctx), _ctx);
}

kk_nagare_core_types__nstream kk_nagare_io_file_fileCopy(kk_std_os_path__path from, kk_std_os_path__path to, kk_context_t* _ctx); /* (from : std/os/path/path, to : std/os/path/path) -> nagare/core/types/iostream<()> */ 
 
// monadic lift

static inline kk_nagare_core_types__pull kk_nagare_io_file__mlift_deleteFile_10692(kk_unit_t _y_x10547, kk_context_t* _ctx) { /* (()) -> <nagare/io/file_effect/fileSystem,alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> nagare/core/types/pull<(),<alloc<global>,console/console,div,exn,nagare/io/file_effect/fileSystem,fsys,ndet,net,read<global>,ui,write<global>>> */ 
  kk_unit_t _b_x932_934 = kk_Unit;
  _y_x10547;
  kk_std_core_types__list _b_x933_935 = kk_std_core_types__new_Nil(_ctx); /*list<()>*/;
  kk_nagare_core_types__chunk _x_x1715;
  kk_std_core_types__list _x_x1716 = kk_std_core_types__new_Cons(kk_reuse_null, 0, kk_unit_box(_b_x932_934), _b_x933_935, _ctx); /*list<10021>*/
  _x_x1715 = kk_nagare_core_types__new_Chunk(_x_x1716, _ctx); /*nagare/core/types/chunk<4>*/
  return kk_nagare_core_types__new_POutput(kk_reuse_null, 0, _x_x1715, kk_nagare_core_types__new_PDone(_ctx), _ctx);
}

kk_nagare_core_types__nstream kk_nagare_io_file_deleteFile(kk_std_os_path__path filepath, kk_context_t* _ctx); /* (filepath : std/os/path/path) -> nagare/io/file_effect/fsStream<()> */ 

void kk_nagare_io_file__init(kk_context_t* _ctx);


void kk_nagare_io_file__done(kk_context_t* _ctx);

#endif // header
