#include "queue.h"
#include <stdlib.h>

// Initialize the queue
void queue_init(Queue *queue) {
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
}

// Add an element to the rear of the queue
void queue_enqueue(Queue *queue, int value) {
    QueueNode *new_node = (QueueNode*)malloc(sizeof(QueueNode));
    if (!new_node) {
        // Handle memory allocation failure if needed
        return;
    }

    new_node->data = value;
    new_node->next = NULL;

    if (queue->rear == NULL) {
        queue->front = new_node;
        queue->rear = new_node;
    } else {
        queue->rear->next = new_node;
        queue->rear = new_node;
    }

    queue->size++;
}

// Remove and return the element from the front of the queue
int queue_dequeue(Queue *queue) {
    if (queue->front == NULL) {
        return -1; // Queue is empty, handle underflow appropriately
    }

    QueueNode *temp = queue->front;
    int value = temp->data;
    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
    queue->size--;
    return value;
}

// Check if the queue is empty
bool queue_is_empty(Queue *queue) {
    return queue->size == 0;
}

// Get the size of the queue
size_t queue_size(Queue *queue) {
    return queue->size;
}

// Free the queue and its nodes
void queue_free(Queue *queue) {
    while (!queue_is_empty(queue)) {
        queue_dequeue(queue);
    }
}
int queue_peek(Queue *queue){
    return queue->front->data;
}
 
