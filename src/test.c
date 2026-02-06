#define CONTAINERS_FOR_C

#include "da.h"
// #include "ll.h"

NewDAType(VecInt, int);
// NewLLType(ListInt, int);

int main() {
	VecInt vec;
	da_with_capacity(vec, 2);

	da_push(vec, 3);
	da_push(vec, 4);

	for (size_t i = 0; i != vec.size; ++i) {
		printf("elem #%ld = %d\n", i, vec.data[i]);
	}

	VecInt vec2;
	da_clone(vec, vec2);

	for (size_t i = 0; i != vec.size; ++i) {
		assert(vec.data[i] == vec2.data[i]);
	}
	
	da_pop(vec);
	da_free(vec);
}
