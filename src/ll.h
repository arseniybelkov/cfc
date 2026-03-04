#pragma once
#include <stdlib.h>

#include "tools.h"

#define NewLLType(NAME, T)\
	typedef struct NAME_Node {\
		T data;\
		struct NAME_Node* next;\
	} NAME_Node;\
	\
	typedef struct NAME {\
		T* head;\
		T* tail;\
	} NAME;\

#define ll_new(ll) do {\
		TODO("ll_new is not done yet\n");\
	} while (0)\

#define ll_append(ll, value) do {\
		ll.next = malloc(sizeof(ll));\
		ll.next->data = value;\
	} while (0)\
