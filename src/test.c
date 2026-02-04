#define CONTAINERS_FOR_C
#include "da.h"

NewDAType(VecInt, int);

int main() {
	VecInt vec;
	da_with_capacity(vec, 2);

	da_push(vec, 3);
	da_push(vec, 4);

	for (size_t i = 0; i != vec.size; ++i) {
		printf("elem #%ld = %d\n", i, vec.data[i]);
	}

	da_pop(vec);
}
