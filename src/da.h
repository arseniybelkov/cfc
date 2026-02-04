#ifdef CONTAINERS_FOR_C

#pragma once
#include <stdlib.h>
#include <stdio.h>

/*

All the functions da_* expect passed structure
to have fields `size_t size`, `size_t capacity` and `T* data`

*/

// #define da_new(DA_TYPE)

#define NewDAType(NAME, DATA_TYPE)\
	typedef struct NAME {\
		DATA_TYPE* data;\
		size_t size;\
		size_t capacity;\
	} NAME;

#define TODO(msg) do {\
		printf(msg);\
		exit(1);\
	} while (0);\

#define da_push(da, value) do {\
		if (da.size == da.capacity) {\
			TODO("reallocate");\
		}\
		da.data[da.size] = value;\
		da.size++;\
	} while (0);\

#define da_pop(da, value) do {\
		da.size--;\
	} while (0);\

#endif
