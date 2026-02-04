#define CONTAINERS_FOR_C
#include "./da.h"

NewDAType(VecInt, int);

int main() {
	int* data = malloc(2 * sizeof(int));

	VecInt vec = {data, 2, 0};

	da_push(vec, 3);
	da_push(vec, 4);
}
