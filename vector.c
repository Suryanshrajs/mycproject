#include "vector.h"
#include <stdlib.h>

void vector_init(Vector *vec) {
    vec->size = 0;
    vec->capacity = 4;
    vec->data = (int*)malloc(sizeof(int) * vec->capacity);
}

void vector_push_back(Vector *vec, int value) {
    if (vec->size >= vec->capacity) {
        vec->capacity *= 2;
        vec->data = (int*)realloc(vec->data, sizeof(int) * vec->capacity);
    }
    vec->data[vec->size++] = value;
}

void vector_free(Vector *vec) {
    free(vec->data);
    vec->data = NULL;
    vec->size = 0;
    vec->capacity = 0;
}
