#include <stdio.h>

#include "utils/vector.h"

void print_vector(Vector* v) {
    for(size_t i = 0; i < v->size; i++) {
        int number = (*(int*)vector_get(v, i));
        printf("Number: %d\n", number);
    }
}

int main(int argc, char** argv) {
    int numberOne = 1;
    int numberTwo = 2;
    int numberThree = 3;

    Vector* v = malloc(sizeof(Vector));
    vector_init(v, 2);

    vector_push(v, &numberOne);
    vector_push(v, &numberTwo);
    print_vector(v);

    vector_push(v, &numberThree);
    print_vector(v);

    vector_pop(v);
    vector_pop(v);
    print_vector(v);

    vector_set(v, 0, &numberThree);
    print_vector(v);
    
    return 0;
}