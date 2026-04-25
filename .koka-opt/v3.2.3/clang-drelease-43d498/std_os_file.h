#pragma once
#ifndef kk_std_os_file_H
#define kk_std_os_file_H
// Koka generated module: std/os/file, koka version: 3.2.3, platform: 64-bit
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

// type declarations

// value declarations

kk_std_core_exn__error kk_std_os_file_read_text_file_err(kk_string_t path, kk_context_t* _ctx); /* (path : string) -> fsys error<string> */ 

kk_string_t kk_std_os_file_read_text_file(kk_std_os_path__path path, kk_context_t* _ctx); /* (path : std/os/path/path) -> <exn,fsys> string */ 

kk_std_core_exn__error kk_std_os_file_write_text_file_err(kk_string_t path, kk_string_t content, kk_context_t* _ctx); /* (path : string, content : string) -> fsys error<()> */ 

kk_unit_t kk_std_os_file__mlift_write_text_file_10133(kk_string_t content, kk_std_os_path__path path, kk_unit_t _c_x10107, kk_context_t* _ctx); /* (content : string, path : std/os/path/path, ()) -> () */ 

kk_unit_t kk_std_os_file_write_text_file(kk_std_os_path__path path, kk_string_t content, kk_std_core_types__optional create_dir, kk_context_t* _ctx); /* (path : std/os/path/path, content : string, create-dir : ? bool) -> <exn,fsys> () */ 

void kk_std_os_file__init(kk_context_t* _ctx);


void kk_std_os_file__done(kk_context_t* _ctx);

#endif // header
