#pragma once
#include <stdlib.h>

#include "ll.h"
#include "tools.h"

/*

Hash-Table C implementation.
All the functions named ht_* are related to
hasttable manipulations.

*/

#define NewHTType(NAME, V)\
	NewLLType(NAME__Bucket_, V);

	typedef struct Name {\
		NAME__Bucket_* buckets;\
		size_t size;\
		size_t capacity;\
	} Name;\

#define ht_insert(ht, key, value) do {\
		size_t idx = _ht_hash_func(key);\
		TODO("todo ht_insert");\
	} while (0)\

#define _ht_hash_func(key) do { TODO("define ht_hash_func func"); } while (0)
