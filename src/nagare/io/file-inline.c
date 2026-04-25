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
