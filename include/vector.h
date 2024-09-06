#ifndef VECTOR_H
#define VECTOR_H

#include <stddef.h>

typedef struct {
    int *data;
    size_t size;
    size_t capacity;
} Vector;

void vector_init(Vector *vec);
void vector_push_back(Vector *vec, int value);
void vector_free(Vector *vec);
int vector_get(Vector *vec,int ind);
#endif
