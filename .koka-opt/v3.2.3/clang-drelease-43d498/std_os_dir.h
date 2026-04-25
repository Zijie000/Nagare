#pragma once
#ifndef kk_std_os_dir_H
#define kk_std_os_dir_H
// Koka generated module: std/os/dir, koka version: 3.2.3, platform: 64-bit
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

// type declarations

// value declarations

kk_std_core_exn__error kk_std_os_dir_prim_copy_file(kk_string_t from, kk_string_t to, bool preserve_mtime, kk_context_t* _ctx); /* (from : string, to : string, preserve-mtime : bool) -> fsys error<()> */ 

kk_unit_t kk_std_os_dir_copy_file(kk_std_os_path__path from, kk_std_os_path__path to, kk_std_core_types__optional preserve_mtime, kk_context_t* _ctx); /* (from : std/os/path/path, to : std/os/path/path, preserve-mtime : ? bool) -> <exn,fsys> () */ 

kk_std_core_exn__error kk_std_os_dir_ensure_dir_err(kk_string_t path, kk_integer_t mode, kk_context_t* _ctx); /* (path : string, mode : int) -> fsys error<()> */ 

kk_unit_t kk_std_os_dir_ensure_dir(kk_std_os_path__path dir, kk_context_t* _ctx); /* (dir : std/os/path/path) -> <exn,fsys> () */ 

bool kk_std_os_dir_prim_is_dir(kk_string_t dir, kk_context_t* _ctx); /* (dir : string) -> fsys bool */ 
 
// Is the path a valid directory?

static inline bool kk_std_os_dir_is_directory(kk_std_os_path__path dir, kk_context_t* _ctx) { /* (dir : std/os/path/path) -> fsys bool */ 
  kk_string_t _x_x316 = kk_std_os_path_string(dir, _ctx); /*string*/
  return kk_std_os_dir_prim_is_dir(_x_x316, _ctx);
}

kk_std_core_exn__error kk_std_os_dir_prim_list_dir(kk_string_t dir, kk_context_t* _ctx); /* (dir : string) -> fsys error<vector<string>> */ 

kk_std_core_types__list kk_std_os_dir__trmc_lift_list_directory_10174(kk_std_os_path__path dir, kk_std_core_types__list _uniq_xs_10108, kk_std_core_types__cctx _acc, kk_context_t* _ctx); /* (dir : std/os/path/path, list<string>, ctx<list<std/os/path/path>>) -> <exn,fsys> list<std/os/path/path> */ 

kk_std_core_types__list kk_std_os_dir__lift_list_directory_10174(kk_std_os_path__path dir_0, kk_std_core_types__list _uniq_xs_10108_0, kk_context_t* _ctx); /* (dir : std/os/path/path, list<string>) -> <exn,fsys> list<std/os/path/path> */ 

kk_std_core_types__list kk_std_os_dir__lift_list_directory_10173(kk_std_os_path__path dir, kk_std_core_types__list _uniq_xs_10103, kk_context_t* _ctx); /* (dir : std/os/path/path, list<string>) -> <exn,fsys> list<std/os/path/path> */ 

kk_std_core_types__list kk_std_os_dir_list_directory(kk_std_os_path__path dir, kk_context_t* _ctx); /* (dir : std/os/path/path) -> <exn,fsys> list<std/os/path/path> */ 

kk_std_core_types__list kk_std_os_dir__lift_list_directory_recursive_10175(kk_std_core_types__list _uniq_xs_10116, kk_context_t* _ctx); /* (list<std/os/path/path>) -> <fsys,div,exn> list<std/os/path/path> */ 

kk_std_core_types__list kk_std_os_dir__lift_list_directory_recursive_10176(kk_std_core_types__optional max_depth, kk_std_core_types__list _uniq_xs_10121, kk_context_t* _ctx); /* (max-depth : ? int, list<std/os/path/path>) -> <div,exn,fsys> list<std/os/path/path> */ 

kk_std_core_types__list kk_std_os_dir__mlift_lift_list_directory_recursive_10177_10296(kk_std_os_path__path _uniq_y_10128, kk_std_core_types__list _y_x10211, kk_context_t* _ctx); /* (std/os/path/path, list<std/os/path/path>) -> <div,exn,fsys> list<std/os/path/path> */ 

kk_std_core_types__list kk_std_os_dir__mlift_lift_list_directory_recursive_10177_10297(kk_std_core_types__list _uniq_zz_10133, kk_std_core_types__optional max_depth, kk_std_core_types__list _uniq_ys_1_10132_10134, kk_context_t* _ctx); /* (list<std/os/path/path>, max-depth : ? int, list<std/os/path/path>) -> <pure,fsys> list<std/os/path/path> */ 

kk_std_core_types__list kk_std_os_dir__mlift_list_directory_recursive_10298(kk_std_core_types__list all, kk_std_core_types__list _y_x10218, kk_context_t* _ctx); /* (all : list<std/os/path/path>, list<std/os/path/path>) -> <div,exn,fsys> list<std/os/path/path> */ 

kk_std_core_types__list kk_std_os_dir__mlift_list_directory_recursive_10299(kk_std_core_types__list all_0, kk_std_core_types__optional max_depth_0, kk_std_core_types__list dirs, kk_context_t* _ctx); /* (all : list<std/os/path/path>, max-depth : ? int, dirs : list<std/os/path/path>) -> <fsys,div,exn> list<std/os/path/path> */ 

kk_std_core_types__list kk_std_os_dir__mlift_list_directory_recursive_10300(kk_std_core_types__optional max_depth_1, kk_std_core_types__list all_1, kk_context_t* _ctx); /* (max-depth : ? int, all : list<std/os/path/path>) -> <exn,fsys> list<std/os/path/path> */ 

kk_std_core_types__list kk_std_os_dir__lift_list_directory_recursive_10177(kk_std_core_types__optional max_depth_2, kk_std_core_types__list _uniq_ys_10125, kk_std_core_types__list _uniq_zs_10126, kk_context_t* _ctx); /* (max-depth : ? int, list<std/os/path/path>, list<std/os/path/path>) -> <div,exn,fsys> list<std/os/path/path> */ 

kk_std_core_types__list kk_std_os_dir_list_directory_recursive(kk_std_os_path__path dir, kk_std_core_types__optional max_depth_3, kk_context_t* _ctx); /* (dir : std/os/path/path, max-depth : ? int) -> <pure,fsys> list<std/os/path/path> */ 

kk_std_core_types__tuple2 kk_std_os_dir__lift_copy_directory_10178(kk_std_core_types__list _uniq_xs_10138, kk_context_t* _ctx); /* (list<std/os/path/path>) -> <fsys,div,exn> (list<std/os/path/path>, list<std/os/path/path>) */ 

kk_unit_t kk_std_os_dir__mlift_lift_copy_directory_10180_10301(kk_std_core_types__list _uniq_xx_10154, kk_std_os_path__path to, kk_unit_t _uniq_x___10155, kk_context_t* _ctx); /* (list<std/os/path/path>, to : std/os/path/path, ()) -> <exn,fsys> () */ 

kk_unit_t kk_std_os_dir__lift_copy_directory_10180(kk_std_os_path__path to_0, kk_std_core_types__list _uniq_xs_10150, kk_context_t* _ctx); /* (to : std/os/path/path, list<std/os/path/path>) -> <exn,fsys,div> () */ 

kk_unit_t kk_std_os_dir__lift_copy_directory_10179(kk_std_os_path__path to, kk_std_core_types__list _uniq_xs_10145, kk_context_t* _ctx); /* (to : std/os/path/path, list<std/os/path/path>) -> <exn,fsys,div> () */ 

kk_unit_t kk_std_os_dir__lift_copy_directory_10181(kk_std_os_path__path to, kk_std_core_types__list _uniq_xs_10159, kk_context_t* _ctx); /* (to : std/os/path/path, list<std/os/path/path>) -> <div,exn,fsys> () */ 

kk_unit_t kk_std_os_dir__mlift_lift_copy_directory_10182_10302(kk_std_core_types__list _uniq_xx_10168, kk_std_os_path__path to, kk_unit_t _uniq_x___10169, kk_context_t* _ctx); /* (list<std/os/path/path>, to : std/os/path/path, ()) -> <pure,fsys> () */ 

kk_unit_t kk_std_os_dir__mlift_copy_directory_10303(kk_std_core_types__list dirs, kk_std_os_path__path to_0, kk_unit_t wild___0, kk_context_t* _ctx); /* (dirs : list<std/os/path/path>, to : std/os/path/path, wild_@0 : ()) -> <exn,fsys,div> () */ 

kk_unit_t kk_std_os_dir__mlift_copy_directory_10304(kk_std_os_path__path to_1, kk_std_core_types__tuple2 _y_x10234, kk_context_t* _ctx); /* (to : std/os/path/path, (list<std/os/path/path>, list<std/os/path/path>)) -> <fsys,div,exn> () */ 

kk_unit_t kk_std_os_dir__mlift_copy_directory_10305(kk_std_os_path__path to_2, kk_std_core_types__list all, kk_context_t* _ctx); /* (to : std/os/path/path, all : list<std/os/path/path>) -> <exn,fsys> () */ 

kk_unit_t kk_std_os_dir__mlift_copy_directory_10306(kk_std_os_path__path dir, kk_std_os_path__path to_3, kk_unit_t wild__, kk_context_t* _ctx); /* (dir : std/os/path/path, to : std/os/path/path, wild_ : ()) -> <exn,fsys> () */ 

kk_unit_t kk_std_os_dir__lift_copy_directory_10182(kk_std_os_path__path to_4, kk_std_core_types__list _uniq_xs_10164, kk_context_t* _ctx); /* (to : std/os/path/path, list<std/os/path/path>) -> <div,exn,fsys> () */ 

kk_unit_t kk_std_os_dir_copy_directory(kk_std_os_path__path dir_0, kk_std_os_path__path to_5, kk_context_t* _ctx); /* (dir : std/os/path/path, to : std/os/path/path) -> <pure,fsys> () */ 

kk_unit_t kk_std_os_dir_copy_file_to_dir(kk_std_os_path__path from, kk_std_os_path__path dir, kk_context_t* _ctx); /* (from : std/os/path/path, dir : std/os/path/path) -> <exn,fsys> () */ 

bool kk_std_os_dir_prim_is_file(kk_string_t path, kk_context_t* _ctx); /* (path : string) -> fsys bool */ 
 
// Is the path a valid file?

static inline bool kk_std_os_dir_is_file(kk_std_os_path__path path, kk_context_t* _ctx) { /* (path : std/os/path/path) -> fsys bool */ 
  kk_string_t _x_x441 = kk_std_os_path_string(path, _ctx); /*string*/
  return kk_std_os_dir_prim_is_file(_x_x441, _ctx);
}

void kk_std_os_dir__init(kk_context_t* _ctx);


void kk_std_os_dir__done(kk_context_t* _ctx);

#endif // header
