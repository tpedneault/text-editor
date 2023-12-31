/*
 * vector.h
 *
 * This header file defines the data structure and functions for a dynamic array, known as Vector.
 * It provides an implementation similar to C++'s std::vector, allowing dynamic resizing and
 * management of elements. The Vector can store pointers to any type of data, offering flexibility
 * for various uses.
 *
 * Functions include initialization, resizing, adding/removing elements, and cleanup operations.
 * This implementation is useful in scenarios where the size of the array needs to change dynamically
 * at runtime.
 */

#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>
#include <stdlib.h>

typedef struct {
    void** items;
    size_t size;
    size_t capacity;
} Vector;

// Initializes a Vector with a specified initial capacity
void vector_init(Vector* v, size_t initial_capacity);

// Resizes the Vector to a new capacity
void vector_resize(Vector* v, size_t new_capacity);

// Adds an item to the end of the Vector
void vector_push(Vector* v, void* item);

// Removes and returns the last item of the Vector
void* vector_pop(Vector* v);

// Retrieves an item at a specific index in the Vector
void* vector_get(Vector* v, size_t index);

// Sets an item at a specific index in the Vector
void vector_set(Vector* v, size_t index, void* item);

// Frees the memory allocated for the Vector's items
void vector_free(Vector* v);

// Frees the memory allocated for the Vector's items and the Vector itself
void vector_freeAll(Vector* v);

#endif // VECTOR_H