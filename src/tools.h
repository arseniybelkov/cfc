#pragma once
#include <stdio.h>

#define TODO(msg) fprintf(stderr, "TODO: %s", msg, __FILE__, __LINE__)

#ifdef _DEBUG
	#define debug_assert(expr) assert(expr)
#else
	#define debug_assert(expr)
#endif

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

static inline size_t _get_type_alignment(void* ptr1, void* ptr2) {
  debug_assert(ptr1 > ptr2);
  return (size_t) ptr1 - (size_t) ptr2;
}