#include "vector.h"

void vector_init(Vector* v, size_t initial_capacity) {
    v->items = malloc(initial_capacity * sizeof(void*));
    v->size = 0;
    v->capacity = initial_capacity;
}

void vector_resize(Vector* v, size_t new_capacity) {
    void** items = realloc(v->items, new_capacity * sizeof(void*));
    if(items) {
        v->items = items;
        v->capacity = new_capacity;
    }

    // TODO: Implement error handling in case resize fails.
}

void vector_push(Vector* v, void* item) {
    if(v->size == v->capacity) {
        vector_resize(v, v->capacity * 2);
    }
    v->items[v->size++] = item;
}

void* vector_pop(Vector* v) {
    if(v->size <= 1) {
        return NULL;
    }
    void* item = v->items[v->size - 1];
    v->size--;
    return item;
}

void* vector_get(Vector* v, size_t index) {
    if(index >= 0 && index < v->size) {
        return v->items[index];
    }

    // TODO: Implement error handling in case index is out of bounds.
    return NULL;
}

void vector_set(Vector* v, size_t index, void* item) {
    if(index >= 0 && index < v->size) {
        v->items[index] = item;
    }

    // TODO: Implement error handling in case index is out of bounds.
}

/// @brief Frees the vector, not its contents.
void vector_free(Vector* v) {
    free(v->items);
}

/// @brief Frees both the vector and its contents.
void vector_freeAll(Vector* v) {
    for(size_t i = 0; i < v->size; i++) {
        free(v->items[i]);
    }
    free(v->items);
}