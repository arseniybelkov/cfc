#ifdef CONTAINERS_FOR_C

#pragma once
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*

All the functions da_* expect passed structure
to have fields `size_t size`, `size_t capacity` and `T* data`

*/

const size_t DEFAULT_DA_CAPACITY = 8;
const size_t CAPACITY_MUL = 2;

#define NewDAType(NAME, DATA_TYPE)\
	typedef struct NAME {\
		DATA_TYPE* data;\
		size_t size;\
		size_t capacity;\
	} NAME;

#define da_new(da) da_with_capacity(da, DEFAULT_DA_CAPACITY)

#define da_with_capacity(da, _capacity) do {\
		size_t ptr1 = (size_t) (da.data + 1);\
		size_t ptr2 = (size_t) da.data;\
		size_t type_size = ptr1 - ptr2;\
		da.data = malloc(type_size * _capacity);\
		da.capacity = _capacity;\
		da.size = 0;\
	} while (0)\

#define _da_reallocate(da) do {\
		size_t ptr1 = (size_t) (da.data + 1);\
		size_t ptr2 = (size_t) da.data;\
		size_t type_size = ptr1 - ptr2;\
		size_t new_capacity = da.capacity * CAPACITY_MUL;\
		da.data = realloc(da.data, type_size * new_capacity);\
		da.capacity = new_capacity;\
	} while (0)\

#define da_push(da, value) do {\
		if (da.size == da.capacity) {\
			_da_reallocate(da);\
		}\
		da.data[da.size] = value;\
		da.size++;\
	} while (0);\

#define da_pop(da) do {\
		da.size--;\
	} while (0);\

#define da_clone(da_src, da_dst) do {\
		size_t ptr1 = (size_t) (da_src.data + 1);\
		size_t ptr2 = (size_t) da_src.data;\
		size_t type_size = ptr1 - ptr2;\
		da_dst.data = malloc(type_size * da_src.capacity);\
		assert(\
			memcpy(da_dst.data, da_src.data, da_src.capacity * type_size)\
		);\
		da_dst.size = da_src.size;\
		da_dst.capacity = da_src.capacity;\
	} while (0)\

#define da_free(da) do {\
		if (da.data) {\
			free(da.data);\
		}\
	} while (0);\

#endif
