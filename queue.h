#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include <stddef.h>

// Define the structure for a Queue node
typedef struct QueueNode {
    int data;
    struct QueueNode *next;
} QueueNode;

// Define the structure for the Queue itself
typedef struct {
    QueueNode *front;
    QueueNode *rear;
    size_t size;
} Queue;

// Function declarations
void queue_init(Queue *queue);
void queue_enqueue(Queue *queue, int value);
int queue_dequeue(Queue *queue);
bool queue_is_empty(Queue *queue);
size_t queue_size(Queue *queue);
void queue_free(Queue *queue);

#endif
