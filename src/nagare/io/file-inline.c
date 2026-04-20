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

// Close a file handle.
static kk_unit_t nagare_fclose(intptr_t fh) {
  if (fh != 0) {
    fclose((FILE*)fh);
  }
  return kk_Unit;
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
