#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>
#include <stdlib.h>

typedef struct {
    void** items;
    size_t size;
    size_t capacity;
} Vector;

void vector_init(Vector* v, size_t initial_capacity);
void vector_resize(Vector* v, size_t new_capacity);

void vector_push(Vector* v, void* item);
void* vector_pop(Vector* v);

void* vector_get(Vector* v, size_t index);
void vector_set(Vector* v, size_t index, void* item);

void vector_free(Vector* v);
void vector_freeAll(Vector* v);

#endif // !VECTOR_H