#ifndef HEAP_H
#define HEAP_H

#include <stdbool.h>
#include <stddef.h>

// Define the structure for a heap
typedef struct {
    int *data;
    size_t size;
    size_t capacity;
    bool is_min_heap;
} Heap;

// Function declarations
void heap_init(Heap *heap, size_t capacity, bool is_min_heap);
void heap_insert(Heap *heap, int value);
int heap_extract(Heap *heap);
int heap_peek(Heap *heap);
bool heap_is_empty(Heap *heap);
void heap_free(Heap *heap);

#endif
