#pragma once
#ifndef kk_nagare_io_image__effect_H
#define kk_nagare_io_image__effect_H
// Koka generated module: nagare/io/image_effect, koka version: 3.2.3, platform: 64-bit
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
#include "nagare_core_types.h"

// type declarations

// value type nagare/io/image_effect/image
struct kk_nagare_io_image__effect_Image {
  kk_integer_t width;
  kk_integer_t height;
  kk_integer_t channels;
  kk_vector_t pixels;
};
typedef struct kk_nagare_io_image__effect_Image kk_nagare_io_image__effect__image;
static inline kk_nagare_io_image__effect__image kk_nagare_io_image__effect__new_Image(kk_integer_t width, kk_integer_t height, kk_integer_t channels, kk_vector_t pixels, kk_context_t* _ctx) {
  kk_nagare_io_image__effect__image _con;
  _con.width = width;
  _con.height = height;
  _con.channels = channels;
  _con.pixels = pixels;
  return _con;
}
static inline bool kk_nagare_io_image__effect__is_Image(kk_nagare_io_image__effect__image x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_nagare_io_image__effect__image kk_nagare_io_image__effect__image_dup(kk_nagare_io_image__effect__image _x, kk_context_t* _ctx) {
  kk_integer_dup(_x.width, _ctx);
  kk_integer_dup(_x.height, _ctx);
  kk_integer_dup(_x.channels, _ctx);
  kk_vector_dup(_x.pixels, _ctx);
  return _x;
}
static inline void kk_nagare_io_image__effect__image_drop(kk_nagare_io_image__effect__image _x, kk_context_t* _ctx) {
  kk_integer_drop(_x.width, _ctx);
  kk_integer_drop(_x.height, _ctx);
  kk_integer_drop(_x.channels, _ctx);
  kk_vector_drop(_x.pixels, _ctx);
}
static inline kk_box_t kk_nagare_io_image__effect__image_box(kk_nagare_io_image__effect__image _x, kk_context_t* _ctx) {
  kk_box_t _box;
  kk_valuetype_box(kk_nagare_io_image__effect__image, _box, _x, 4 /* scan count */, _ctx);
  return _box;
}
static inline kk_nagare_io_image__effect__image kk_nagare_io_image__effect__image_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  kk_nagare_io_image__effect__image _unbox;
  kk_valuetype_unbox(kk_nagare_io_image__effect__image, _unbox, _x, _borrow, _ctx);
  return _unbox;
}

// type nagare/io/image_effect/imageDecode
struct kk_nagare_io_image__effect__imageDecode_s {
  kk_block_t _block;
};
typedef kk_datatype_ptr_t kk_nagare_io_image__effect__imageDecode;
struct kk_nagare_io_image__effect__Hnd_imageDecode {
  struct kk_nagare_io_image__effect__imageDecode_s _base;
  kk_integer_t _cfc;
  kk_std_core_hnd__clause1 _fun_decodeImageBytes;
};
static inline kk_nagare_io_image__effect__imageDecode kk_nagare_io_image__effect__base_Hnd_imageDecode(struct kk_nagare_io_image__effect__Hnd_imageDecode* _x, kk_context_t* _ctx) {
  return kk_datatype_from_base(&_x->_base, _ctx);
}
static inline kk_nagare_io_image__effect__imageDecode kk_nagare_io_image__effect__new_Hnd_imageDecode(kk_reuse_t _at, int32_t _cpath, kk_integer_t _cfc, kk_std_core_hnd__clause1 _fun_decodeImageBytes, kk_context_t* _ctx) {
  struct kk_nagare_io_image__effect__Hnd_imageDecode* _con = kk_block_alloc_at_as(struct kk_nagare_io_image__effect__Hnd_imageDecode, _at, 2 /* scan count */, _cpath, (kk_tag_t)(1), _ctx);
  _con->_cfc = _cfc;
  _con->_fun_decodeImageBytes = _fun_decodeImageBytes;
  return kk_nagare_io_image__effect__base_Hnd_imageDecode(_con, _ctx);
}
static inline struct kk_nagare_io_image__effect__Hnd_imageDecode* kk_nagare_io_image__effect__as_Hnd_imageDecode(kk_nagare_io_image__effect__imageDecode x, kk_context_t* _ctx) {
  return kk_datatype_as_assert(struct kk_nagare_io_image__effect__Hnd_imageDecode*, x, (kk_tag_t)(1), _ctx);
}
static inline bool kk_nagare_io_image__effect__is_Hnd_imageDecode(kk_nagare_io_image__effect__imageDecode x, kk_context_t* _ctx) {
  return (true);
}
static inline kk_nagare_io_image__effect__imageDecode kk_nagare_io_image__effect__imageDecode_dup(kk_nagare_io_image__effect__imageDecode _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_dup(_x, _ctx);
}
static inline void kk_nagare_io_image__effect__imageDecode_drop(kk_nagare_io_image__effect__imageDecode _x, kk_context_t* _ctx) {
  kk_datatype_ptr_drop(_x, _ctx);
}
static inline kk_box_t kk_nagare_io_image__effect__imageDecode_box(kk_nagare_io_image__effect__imageDecode _x, kk_context_t* _ctx) {
  return kk_datatype_ptr_box(_x);
}
static inline kk_nagare_io_image__effect__imageDecode kk_nagare_io_image__effect__imageDecode_unbox(kk_box_t _x, kk_borrow_t _borrow, kk_context_t* _ctx) {
  return kk_datatype_ptr_unbox(_x);
}

// value declarations

kk_vector_t kk_nagare_io_image__effect_nagare_image_decode_bytes(kk_vector_t input, kk_context_t* _ctx); /* (input : vector<int8>) -> io vector<int8> */ 

kk_integer_t kk_nagare_io_image__effect_nagare_image_last_width(kk_unit_t unit, kk_context_t* _ctx); /* (unit : ()) -> io int */ 

kk_integer_t kk_nagare_io_image__effect_nagare_image_last_height(kk_unit_t unit, kk_context_t* _ctx); /* (unit : ()) -> io int */ 

kk_integer_t kk_nagare_io_image__effect_nagare_image_last_channels(kk_unit_t unit, kk_context_t* _ctx); /* (unit : ()) -> io int */ 
 
// Automatically generated. Retrieves the `width` constructor field of the `:image` type.

static inline kk_integer_t kk_nagare_io_image__effect_image_fs_width(kk_nagare_io_image__effect__image image, kk_context_t* _ctx) { /* (image : image) -> int */ 
  {
    kk_integer_t _x = image.width;
    return kk_integer_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `height` constructor field of the `:image` type.

static inline kk_integer_t kk_nagare_io_image__effect_image_fs_height(kk_nagare_io_image__effect__image image, kk_context_t* _ctx) { /* (image : image) -> int */ 
  {
    kk_integer_t _x = image.height;
    return kk_integer_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `channels` constructor field of the `:image` type.

static inline kk_integer_t kk_nagare_io_image__effect_image_fs_channels(kk_nagare_io_image__effect__image image, kk_context_t* _ctx) { /* (image : image) -> int */ 
  {
    kk_integer_t _x = image.channels;
    return kk_integer_dup(_x, _ctx);
  }
}
 
// Automatically generated. Retrieves the `pixels` constructor field of the `:image` type.

static inline kk_vector_t kk_nagare_io_image__effect_image_fs_pixels(kk_nagare_io_image__effect__image image, kk_context_t* _ctx) { /* (image : image) -> vector<int8> */ 
  {
    kk_vector_t _x = image.pixels;
    return kk_vector_dup(_x, _ctx);
  }
}

kk_nagare_io_image__effect__image kk_nagare_io_image__effect_image_fs__copy(kk_nagare_io_image__effect__image _this, kk_std_core_types__optional width, kk_std_core_types__optional height, kk_std_core_types__optional channels, kk_std_core_types__optional pixels, kk_context_t* _ctx); /* (image, width : ? int, height : ? int, channels : ? int, pixels : ? (vector<int8>)) -> image */ 

bool kk_nagare_io_image__effect_is_valid(kk_nagare_io_image__effect__image img, kk_context_t* _ctx); /* (img : image) -> bool */ 
 
// Automatically generated. Retrieves the `@cfc` constructor field of the `:imageDecode` type.

static inline kk_integer_t kk_nagare_io_image__effect_imageDecode_fs__cfc(kk_nagare_io_image__effect__imageDecode imageDecode, kk_context_t* _ctx) { /* forall<e,a> (imageDecode : imageDecode<e,a>) -> int */ 
  {
    struct kk_nagare_io_image__effect__Hnd_imageDecode* _con_x58 = kk_nagare_io_image__effect__as_Hnd_imageDecode(imageDecode, _ctx);
    kk_integer_t _x = _con_x58->_cfc;
    return kk_integer_dup(_x, _ctx);
  }
}

extern kk_std_core_hnd__htag kk_nagare_io_image__effect_imageDecode_fs__tag;

kk_box_t kk_nagare_io_image__effect_imageDecode_fs__handle(kk_nagare_io_image__effect__imageDecode hnd, kk_function_t ret, kk_function_t action, kk_context_t* _ctx); /* forall<a,e,b> (hnd : imageDecode<e,b>, ret : (res : a) -> e b, action : () -> <imageDecode|e> a) -> e b */ 
 
// Automatically generated. Retrieves the `@fun-decodeImageBytes` constructor field of the `:imageDecode` type.

static inline kk_std_core_hnd__clause1 kk_nagare_io_image__effect_imageDecode_fs__fun_decodeImageBytes(kk_nagare_io_image__effect__imageDecode imageDecode, kk_context_t* _ctx) { /* forall<e,a> (imageDecode : imageDecode<e,a>) -> hnd/clause1<vector<int8>,image,imageDecode,e,a> */ 
  {
    struct kk_nagare_io_image__effect__Hnd_imageDecode* _con_x62 = kk_nagare_io_image__effect__as_Hnd_imageDecode(imageDecode, _ctx);
    kk_std_core_hnd__clause1 _x = _con_x62->_fun_decodeImageBytes;
    return kk_std_core_hnd__clause1_dup(_x, _ctx);
  }
}
 
// select `decodeImageBytes` operation out of effect `:imageDecode`

static inline kk_std_core_hnd__clause1 kk_nagare_io_image__effect_decodeImageBytes_fs__select(kk_nagare_io_image__effect__imageDecode hnd, kk_context_t* _ctx) { /* forall<e,a> (hnd : imageDecode<e,a>) -> hnd/clause1<vector<int8>,image,imageDecode,e,a> */ 
  {
    struct kk_nagare_io_image__effect__Hnd_imageDecode* _con_x63 = kk_nagare_io_image__effect__as_Hnd_imageDecode(hnd, _ctx);
    kk_std_core_hnd__clause1 _fun_decodeImageBytes = _con_x63->_fun_decodeImageBytes;
    return kk_std_core_hnd__clause1_dup(_fun_decodeImageBytes, _ctx);
  }
}
 
// Call the `fun decodeImageBytes` operation of the effect `:imageDecode`

static inline kk_nagare_io_image__effect__image kk_nagare_io_image__effect_decodeImageBytes(kk_vector_t input, kk_context_t* _ctx) { /* (input : vector<int8>) -> imageDecode image */ 
  kk_std_core_hnd__ev ev_10124 = kk_evv_at(((KK_IZ(0))),kk_context()); /*hnd/ev<nagare/io/image_effect/imageDecode>*/;
  kk_box_t _x_x64;
  {
    struct kk_std_core_hnd_Ev* _con_x65 = kk_std_core_hnd__as_Ev(ev_10124, _ctx);
    kk_box_t _box_x12 = _con_x65->hnd;
    int32_t m = _con_x65->marker;
    kk_nagare_io_image__effect__imageDecode h = kk_nagare_io_image__effect__imageDecode_unbox(_box_x12, KK_BORROWED, _ctx);
    kk_nagare_io_image__effect__imageDecode_dup(h, _ctx);
    {
      struct kk_nagare_io_image__effect__Hnd_imageDecode* _con_x66 = kk_nagare_io_image__effect__as_Hnd_imageDecode(h, _ctx);
      kk_integer_t _pat_0_0 = _con_x66->_cfc;
      kk_std_core_hnd__clause1 _fun_decodeImageBytes = _con_x66->_fun_decodeImageBytes;
      if kk_likely(kk_datatype_ptr_is_unique(h, _ctx)) {
        kk_integer_drop(_pat_0_0, _ctx);
        kk_datatype_ptr_free(h, _ctx);
      }
      else {
        kk_std_core_hnd__clause1_dup(_fun_decodeImageBytes, _ctx);
        kk_datatype_ptr_decref(h, _ctx);
      }
      {
        kk_function_t _fun_unbox_x16 = _fun_decodeImageBytes.clause;
        _x_x64 = kk_function_call(kk_box_t, (kk_function_t, int32_t, kk_std_core_hnd__ev, kk_box_t, kk_context_t*), _fun_unbox_x16, (_fun_unbox_x16, m, ev_10124, kk_vector_box(input, _ctx), _ctx), _ctx); /*10010*/
      }
    }
  }
  return kk_nagare_io_image__effect__image_unbox(_x_x64, KK_OWNED, _ctx);
}
 
// monadic lift

static inline kk_nagare_io_image__effect__image kk_nagare_io_image__effect__mlift_defaultImageDecode_10119(kk_integer_t h, kk_vector_t px, kk_integer_t w, kk_integer_t c, kk_context_t* _ctx) { /* (h : int, px : vector<int8>, w : int, c : int) -> io image */ 
  return kk_nagare_io_image__effect__new_Image(w, h, c, px, _ctx);
}

kk_nagare_io_image__effect__image kk_nagare_io_image__effect__mlift_defaultImageDecode_10120(kk_vector_t px, kk_integer_t w, kk_integer_t h, kk_context_t* _ctx); /* (px : vector<int8>, w : int, h : int) -> io image */ 

kk_nagare_io_image__effect__image kk_nagare_io_image__effect__mlift_defaultImageDecode_10121(kk_vector_t px, kk_integer_t w, kk_context_t* _ctx); /* (px : vector<int8>, w : int) -> io image */ 

kk_nagare_io_image__effect__image kk_nagare_io_image__effect__mlift_defaultImageDecode_10122(kk_vector_t px, kk_context_t* _ctx); /* (px : vector<int8>) -> io image */ 

kk_box_t kk_nagare_io_image__effect_defaultImageDecode(kk_function_t action, kk_context_t* _ctx); /* forall<a> (action : () -> <imageDecode|io> a) -> io a */ 

void kk_nagare_io_image__effect__init(kk_context_t* _ctx);


void kk_nagare_io_image__effect__done(kk_context_t* _ctx);

#endif // header
