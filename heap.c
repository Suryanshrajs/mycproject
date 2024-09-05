#include "heap.h"
#include <stdlib.h>
#include <stdio.h>

// Helper function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Initialize the heap
void heap_init(Heap *heap, size_t capacity, bool is_min_heap) {
    heap->data = (int*)malloc(sizeof(int) * capacity);
    heap->size = 0;
    heap->capacity = capacity;
    heap->is_min_heap = is_min_heap;
}

// Helper functions to get parent and child indices
size_t parent(size_t i) { return (i - 1) / 2; }
size_t left_child(size_t i) { return 2 * i + 1; }
size_t right_child(size_t i) { return 2 * i + 2; }

// Insert a value into the heap
void heap_insert(Heap *heap, int value) {
    if (heap->size >= heap->capacity) {
        heap->capacity *= 2;
        heap->data = (int*)realloc(heap->data, sizeof(int) * heap->capacity);
    }

    heap->data[heap->size] = value;
    size_t i = heap->size++;
    while (i != 0 && 
           (heap->is_min_heap ? heap->data[i] < heap->data[parent(i)] 
                              : heap->data[i] > heap->data[parent(i)])) {
        swap(&heap->data[i], &heap->data[parent(i)]);
        i = parent(i);
    }
}

// Extract the root element from the heap
int heap_extract(Heap *heap) {
    if (heap->size == 0) {
        return -1; // Heap is empty
    }

    int root = heap->data[0];
    heap->data[0] = heap->data[--heap->size];

    size_t i = 0;
    while (true) {
        size_t left = left_child(i);
        size_t right = right_child(i);
        size_t largest_or_smallest = i;

        if (left < heap->size && 
            (heap->is_min_heap ? heap->data[left] < heap->data[largest_or_smallest]
                               : heap->data[left] > heap->data[largest_or_smallest])) {
            largest_or_smallest = left;
        }

        if (right < heap->size && 
            (heap->is_min_heap ? heap->data[right] < heap->data[largest_or_smallest]
                               : heap->data[right] > heap->data[largest_or_smallest])) {
            largest_or_smallest = right;
        }

        if (largest_or_smallest == i) {
            break;
        }

        swap(&heap->data[i], &heap->data[largest_or_smallest]);
        i = largest_or_smallest;
    }

    return root;
}

// Peek the root element without extracting it
int heap_peek(Heap *heap) {
    return heap->size == 0 ? -1 : heap->data[0];
}

// Check if the heap is empty
bool heap_is_empty(Heap *heap) {
    return heap->size == 0;
}

// Free the heap memory
void heap_free(Heap *heap) {
    free(heap->data);
    heap->data = NULL;
    heap->size = 0;
    heap->capacity = 0;
}
