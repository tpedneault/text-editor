#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "utils/vector.h"

int main(int argc, char** argv) {
    int numberOne = 1;
    int numberTwo = 2;
    int numberThree = 3;

    Vector* v = malloc(sizeof(Vector));
    vector_init(v, 2);

    vector_push(v, &numberOne);
    vector_push(v, &numberTwo);

    // Check the size of the vector after two pushes
    assert(v->size == 2);
    assert(*(int*)vector_get(v, 0) == numberOne);
    assert(*(int*)vector_get(v, 1) == numberTwo);

    vector_push(v, &numberThree);

    // Check the size and elements after another push
    assert(v->size == 3);
    assert(*(int*)vector_get(v, 2) == numberThree);

    vector_pop(v);
    vector_pop(v);

    // Check the size after two pops
    assert(v->size == 1);
    assert(*(int*)vector_get(v, 0) == numberOne);

    vector_set(v, 0, &numberThree);

    // Check if set operation worked correctly
    assert(*(int*)vector_get(v, 0) == numberThree);

    // Clean up
    vector_free(v);
    free(v);
    
    printf("All tests passed.\n");
    return 0;
}
