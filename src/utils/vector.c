#include "vector.h"

// Initializes a Vector with a specified initial capacity
void vector_init(Vector* v, size_t initial_capacity) {
    v->items = malloc(initial_capacity * sizeof(void*));
    v->size = 0;
    v->capacity = initial_capacity;
}

// Resizes the Vector to a new capacity
void vector_resize(Vector* v, size_t new_capacity) {
    void** items = realloc(v->items, new_capacity * sizeof(void*));
    if(items) {
        v->items = items;
        v->capacity = new_capacity;
    }

    // TODO: Implement error handling in case resize fails.
}

// Adds an item to the end of the Vector
void vector_push(Vector* v, void* item) {
    if(v->size == v->capacity) {
        vector_resize(v, v->capacity * 2);
    }
    v->items[v->size++] = item;
}

// Removes and returns the last item of the Vector
void* vector_pop(Vector* v) {
    if(v->size <= 1) {
        return NULL;
    }
    void* item = v->items[v->size - 1];
    v->size--;
    return item;
}

// Retrieves an item at a specific index in the Vector
void* vector_get(Vector* v, size_t index) {
    if(index >= 0 && index < v->size) {
        return v->items[index];
    }

    // TODO: Implement error handling in case index is out of bounds.
    return NULL;
}

// Sets an item at a specific index in the Vector
void vector_set(Vector* v, size_t index, void* item) {
    if(index >= 0 && index < v->size) {
        v->items[index] = item;
    }

    // TODO: Implement error handling in case index is out of bounds.
}

// Frees the memory allocated for the Vector's items
void vector_free(Vector* v) {
    free(v->items);
}

// Frees the memory allocated for the Vector's items and the Vector itself
void vector_freeAll(Vector* v) {
    for(size_t i = 0; i < v->size; i++) {
        free(v->items[i]);
    }
    free(v->items);
}