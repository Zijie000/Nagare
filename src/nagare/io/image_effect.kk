module nagare/io/image_effect

import nagare/core/types

extern import
  c file "image-inline.c"

// ---------------------------------------------------------------------------
// Raw C FFI. The decode call populates a thread-local "last decode" slot;
// the three getters retrieve width/height/channels from that slot. This
// avoids returning a struct across the FFI boundary.
// ---------------------------------------------------------------------------

extern nagare-image-decode-bytes(input : vector<int8>) : io vector<int8>
  c "nagare_image_decode_bytes"

extern nagare-image-last-width( unit : () ) : io int
  c "nagare_image_last_width"

extern nagare-image-last-height( unit : () ) : io int
  c "nagare_image_last_height"

extern nagare-image-last-channels( unit : () ) : io int
  c "nagare_image_last_channels"

// ---------------------------------------------------------------------------
// The decoded image type.
//
// `pixels` is always 8-bit RGBA in row-major order; length = width*height*4.
// `channels` is the *original* channel count from the source file (1=gray,
// 2=gray+alpha, 3=RGB, 4=RGBA), preserved for callers who care, even though
// the buffer itself is normalised to RGBA.
// ---------------------------------------------------------------------------

pub value struct image
  width    : int
  height   : int
  channels : int
  pixels   : vector<int8>

// Convenience: True iff decoding produced a non-empty image.
pub fun is-valid( img : image ) : bool
  img.width > 0 && img.height > 0 && img.pixels.length > 0

// ---------------------------------------------------------------------------
// Capability effect.
//
// `imageDecode` is intentionally narrow — a single op that takes the full
// file bytes and returns a decoded image. The op is "all-at-once" by design;
// the API surface in `image.kk` advertises this with the `decodeImageAll`
// naming convention borrowed from fs2 (see `readAll` vs `readAllStreaming`).
// ---------------------------------------------------------------------------

pub effect imageDecode
  fun decodeImageBytes( input : vector<int8> ) : image

// Row alias for streams that decode images. Combine with `fileRead` to
// describe a "read-and-decode" pipeline:  <fileRead, imageDecode | io>
pub alias imageStream<a> = nstream<a, <imageDecode|io>>

// ---------------------------------------------------------------------------
// Default handler. Calls into stb_image via the FFI and bundles the metadata
// from the last-decode slot into the returned `image`.
// ---------------------------------------------------------------------------

pub fun defaultImageDecode( action : () -> <imageDecode|io> a ) : io a
  with handler
    fun decodeImageBytes(input)
      val px = nagare-image-decode-bytes(input)
      val w  = nagare-image-last-width(())
      val h  = nagare-image-last-height(())
      val c  = nagare-image-last-channels(())
      Image(w, h, c, px)
  action()
