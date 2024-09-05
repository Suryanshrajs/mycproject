#include <stdio.h>
#include "vector.h"
#include "linkedlist.h"
#include "stack.h"
#include "hashtable.h"
#include "queue.h"
#include "bst.h"
#include "graph.h"
#include "heap.h"

int main() {
    // Vector Example
    printf("----- Vector Example -----\n");
    Vector vec;
    vector_init(&vec);
    vector_push_back(&vec, 10);
    vector_push_back(&vec, 20);
    printf("Vector Element: %d\n", vector_get(&vec, 0));
    vector_free(&vec);

    // Linked List Example
    printf("\n----- Linked List Example -----\n");
    LinkedList list;
    linkedlist_init(&list);
    linkedlist_insert(&list, 10);
    linkedlist_insert(&list, 20);
    linkedlist_print(&list);
    linkedlist_free(&list);

    // Stack Example
    printf("\n----- Stack Example -----\n");
    Stack stack;
    stack_init(&stack);
    stack_push(&stack, 10);
    stack_push(&stack, 20);
    printf("Stack Top Element: %d\n", stack_peek(&stack));
    stack_pop(&stack);
    stack_free(&stack);

    // Hashtable Example
    printf("\n----- Hashtable Example -----\n");
    Hashtable table;
    hashtable_init(&table, 10);
    hashtable_insert(&table, "key1", 10);
    printf("Hashtable Element: %d\n", hashtable_get(&table, "key1"));
    hashtable_free(&table);

    // Queue Example
    printf("\n----- Queue Example -----\n");
    Queue queue;
    queue_init(&queue);
    queue_enqueue(&queue, 10);
    queue_enqueue(&queue, 20);
    printf("Queue Front Element: %d\n", queue_peek(&queue));
    queue_dequeue(&queue);
    queue_free(&queue);

    // Binary Search Tree Example
    printf("\n----- Binary Search Tree (BST) Example -----\n");
    BST bst;
    bst_init(&bst);
    bst_insert(&bst, 10);
    bst_insert(&bst, 20);
    bst_insert(&bst, 5);
    bst_in_order_traversal(&bst);
    bst_free(&bst);

    // Graph Example
    printf("\n----- Graph Example -----\n");
    int V = 5;
    Graph* graph = create_graph(V);
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 4);
    add_edge(graph, 1, 2);
    print_graph(graph);
    free_graph(graph);

    // Heap Example
    printf("\n----- Heap Example -----\n");
    Heap heap;
    heap_init(&heap, 10, true); // Min-heap
    heap_insert(&heap, 3);
    heap_insert(&heap, 2);
    heap_insert(&heap, 15);
    printf("Heap Root Element: %d\n", heap_peek(&heap));
    heap_extract(&heap);
    heap_free(&heap);

    return 0;
}
