#pragma once
#ifndef kk_examples_image__pipeline_H
#define kk_examples_image__pipeline_H
// Koka generated module: examples/image_pipeline, koka version: 3.2.3, platform: 64-bit
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
#include "nagare_core_interpreter.h"
#include "nagare_io_file.h"
#include "nagare_io_file__effect.h"
#include "nagare_io_image.h"
#include "nagare_io_image__effect.h"
#include "nagare_core_pull.h"

// type declarations

// value declarations

kk_std_core_types__list kk_examples_image__pipeline__trmc_lift_flattenBytes_10186(kk_std_core_types__list _uniq_ys_10129, kk_std_core_types__list _uniq_zs_10130, kk_std_core_types__cctx _acc, kk_context_t* _ctx); /* (list<int8>, list<nagare/io/file/bytes>, ctx<list<int8>>) -> list<int8> */ 

kk_std_core_types__list kk_examples_image__pipeline__lift_flattenBytes_10186(kk_std_core_types__list _uniq_ys_10129_0, kk_std_core_types__list _uniq_zs_10130_0, kk_context_t* _ctx); /* (list<int8>, list<nagare/io/file/bytes>) -> list<int8> */ 

kk_std_core_types__list kk_examples_image__pipeline__lift_flattenBytes_10185(kk_std_core_types__list _uniq_xs_10125, kk_context_t* _ctx); /* (list<nagare/io/file/bytes>) -> list<int8> */ 
 
// Flatten a list of byte chunks into one vector — done once, at the end of
// the read phase, so the cost is O(total bytes) rather than O(n²) from
// repeatedly concatenating into a growing accumulator inside `fold`.

static inline kk_vector_t kk_examples_image__pipeline_flattenBytes(kk_std_core_types__list chunks, kk_context_t* _ctx) { /* (chunks : list<nagare/io/file/bytes>) -> nagare/io/file/bytes */ 
  kk_std_core_types__list xs_10000 = kk_examples_image__pipeline__lift_flattenBytes_10185(chunks, _ctx); /*list<int8>*/;
  return kk_std_core_vector_unvlist(xs_10000, _ctx);
}

kk_std_core_types__list kk_examples_image__pipeline__trmc_lift_decodeOne_10188(kk_std_core_types__list _uniq_ys_10146, kk_std_core_types__list _uniq_zs_10147, kk_std_core_types__cctx _acc, kk_context_t* _ctx); /* (list<int8>, list<nagare/io/file/bytes>, ctx<list<int8>>) -> list<int8> */ 

kk_std_core_types__list kk_examples_image__pipeline__lift_decodeOne_10188(kk_std_core_types__list _uniq_ys_10146_0, kk_std_core_types__list _uniq_zs_10147_0, kk_context_t* _ctx); /* (list<int8>, list<nagare/io/file/bytes>) -> list<int8> */ 

kk_std_core_types__list kk_examples_image__pipeline__lift_decodeOne_10187(kk_std_core_types__list _uniq_xs_10142, kk_context_t* _ctx); /* (list<nagare/io/file/bytes>) -> list<int8> */ 
 
// monadic lift

static inline kk_nagare_io_image__effect__image kk_examples_image__pipeline__mlift_decodeOne_10301(kk_integer_t h, kk_vector_t px, kk_integer_t w, kk_integer_t c_1, kk_context_t* _ctx) { /* (h : int, px : vector<int8>, w : int, c@1 : int) -> io nagare/io/image_effect/image */ 
  return kk_nagare_io_image__effect__new_Image(w, h, c_1, px, _ctx);
}

kk_nagare_io_image__effect__image kk_examples_image__pipeline__mlift_decodeOne_10302(kk_vector_t px, kk_integer_t w, kk_integer_t h, kk_context_t* _ctx); /* (px : vector<int8>, w : int, h : int) -> io nagare/io/image_effect/image */ 

kk_nagare_io_image__effect__image kk_examples_image__pipeline__mlift_decodeOne_10303(kk_vector_t px, kk_integer_t w, kk_context_t* _ctx); /* (px : vector<int8>, w : int) -> io nagare/io/image_effect/image */ 

kk_nagare_io_image__effect__image kk_examples_image__pipeline__mlift_decodeOne_10304(kk_vector_t px, kk_context_t* _ctx); /* (px : vector<int8>) -> io nagare/io/image_effect/image */ 
 
// monadic lift

static inline kk_std_core_types__maybe kk_examples_image__pipeline__mlift_decodeOne_10305(kk_nagare_io_image__effect__image _y_x10208, kk_context_t* _ctx) { /* (nagare/io/image_effect/image) -> <nagare/io/image_effect/imageDecode,alloc<global>,console/console,div,exn,fsys,ndet,net,read<global>,ui,write<global>> maybe<nagare/io/image_effect/image> */ 
  return kk_std_core_types__new_Just(kk_nagare_io_image__effect__image_box(_y_x10208, _ctx), _ctx);
}

kk_std_core_types__list kk_examples_image__pipeline__mlift_decodeOne_10306(kk_nagare_core_interpreter__runtime state, kk_context_t* _ctx); /* (state : nagare/core/interpreter/runtime<nagare/io/file/bytes,nagare/io/file_effect/fileRead>) -> <io,nagare/io/file_effect/fileRead> list<nagare/io/file/bytes> */ 

kk_std_core_types__maybe kk_examples_image__pipeline__mlift_decodeOne_10307(kk_std_core_types__list chunks, kk_context_t* _ctx); /* (chunks : list<nagare/io/file/bytes>) -> io maybe<nagare/io/image_effect/image> */ 

kk_std_core_types__maybe kk_examples_image__pipeline_decodeOne(kk_std_os_path__path p, kk_context_t* _ctx); /* (p : std/os/path/path) -> io maybe<nagare/io/image_effect/image> */ 

kk_string_t kk_examples_image__pipeline_describe(kk_std_os_path__path p, kk_nagare_io_image__effect__image img, kk_context_t* _ctx); /* (p : std/os/path/path, img : nagare/io/image_effect/image) -> string */ 

kk_unit_t kk_examples_image__pipeline__lift_main_10190(kk_std_core_types__list _uniq_xs_10164, kk_context_t* _ctx); /* (list<string>) -> <console/console,alloc<global>,div,exn,fsys,ndet,net,read<global>,ui,write<global>> () */ 

kk_unit_t kk_examples_image__pipeline__lift_main_10189(kk_std_core_types__list _uniq_xs_10159, kk_context_t* _ctx); /* (list<string>) -> <console/console,alloc<global>,div,exn,fsys,ndet,net,read<global>,ui,write<global>> () */ 

kk_unit_t kk_examples_image__pipeline__lift_main_10192(kk_std_core_types__list _uniq_xs_10177, kk_context_t* _ctx); /* (list<string>) -> <console/console,alloc<global>,div,exn,fsys,ndet,net,read<global>,ui,write<global>> () */ 

kk_unit_t kk_examples_image__pipeline__lift_main_10191(kk_std_core_types__list _uniq_xs_10172, kk_context_t* _ctx); /* (list<string>) -> <console/console,alloc<global>,div,exn,fsys,ndet,net,read<global>,ui,write<global>> () */ 

kk_string_t kk_examples_image__pipeline__mlift_main_10308(kk_std_os_path__path p_0, kk_std_core_types__maybe _y_x10225, kk_context_t* _ctx); /* (p@0 : std/os/path/path, maybe<nagare/io/image_effect/image>) -> io string */ 

kk_std_core_types__list kk_examples_image__pipeline__mlift_main_10309(kk_nagare_core_interpreter__runtime state_0, kk_context_t* _ctx); /* (state@0 : nagare/core/interpreter/runtime<string,total>) -> io list<string> */ 

kk_string_t kk_examples_image__pipeline__mlift_main_10310(kk_std_os_path__path p_1, kk_std_core_types__maybe _y_x10234, kk_context_t* _ctx); /* (p@1 : std/os/path/path, maybe<nagare/io/image_effect/image>) -> io string */ 

kk_std_core_types__list kk_examples_image__pipeline__mlift_main_10311(kk_nagare_core_interpreter__runtime state_1, kk_context_t* _ctx); /* (state@1 : nagare/core/interpreter/runtime<string,total>) -> io list<string> */ 

kk_integer_t kk_examples_image__pipeline__mlift_main_10312(kk_integer_t init_0, kk_function_t step_0_0, kk_nagare_core_interpreter__runtime state_2, kk_context_t* _ctx); /* (init@0 : int, step@0@0 : (int, maybe<nagare/io/image_effect/image>) -> int, state@2 : nagare/core/interpreter/runtime<maybe<nagare/io/image_effect/image>,total>) -> io int */ 
 
// monadic lift

static inline kk_unit_t kk_examples_image__pipeline__mlift_main_10313(kk_integer_t totalPixels, kk_context_t* _ctx) { /* (totalPixels : int) -> io () */ 
  kk_string_t _x_x656;
  kk_string_t _x_x657;
  kk_define_string_literal(static, _s_x658, 32, "total pixels across all images: ", _ctx)
  _x_x657 = kk_string_dup(_s_x658, _ctx); /*string*/
  kk_string_t _x_x659 = kk_std_core_int_show(totalPixels, _ctx); /*string*/
  _x_x656 = kk_std_core_types__lp__plus__plus__rp_(_x_x657, _x_x659, _ctx); /*string*/
  kk_std_core_console_printsln(_x_x656, _ctx); return kk_Unit;
}

kk_unit_t kk_examples_image__pipeline__mlift_main_10314(kk_std_core_types__list pics, kk_unit_t wild___4, kk_context_t* _ctx); /* (pics : list<std/os/path/path>, wild_@4 : ()) -> <console/console,alloc<global>,div,exn,fsys,ndet,net,read<global>,ui,write<global>> () */ 

kk_unit_t kk_examples_image__pipeline__mlift_main_10315(kk_std_core_types__list pics, kk_std_core_types__list firstTwo, kk_context_t* _ctx); /* (pics : list<std/os/path/path>, firstTwo : list<string>) -> io () */ 

kk_unit_t kk_examples_image__pipeline__mlift_main_10316(kk_std_core_types__list pics, kk_std_core_types__list summaries, kk_unit_t wild___0, kk_context_t* _ctx); /* (pics : list<std/os/path/path>, summaries : list<string>, wild_@0 : ()) -> <console/console,alloc<global>,div,exn,fsys,ndet,net,read<global>,ui,write<global>> () */ 

kk_unit_t kk_examples_image__pipeline__mlift_main_10317(kk_std_core_types__list pics, kk_std_core_types__list summaries, kk_context_t* _ctx); /* (pics : list<std/os/path/path>, summaries : list<string>) -> io () */ 

kk_std_core_types__list kk_examples_image__pipeline__mlift_main_10318(kk_nagare_core_interpreter__runtime state, kk_context_t* _ctx); /* (state : nagare/core/interpreter/runtime<std/os/path/path,nagare/io/file_effect/fileSystem>) -> <io,nagare/io/file_effect/fileSystem> list<std/os/path/path> */ 

kk_unit_t kk_examples_image__pipeline__mlift_main_10319(kk_std_core_types__list pics, kk_context_t* _ctx); /* (pics : list<std/os/path/path>) -> io () */ 

kk_unit_t kk_examples_image__pipeline_main(kk_context_t* _ctx); /* () -> io () */ 

void kk_examples_image__pipeline__init(kk_context_t* _ctx);


void kk_examples_image__pipeline__done(kk_context_t* _ctx);

#endif // header
