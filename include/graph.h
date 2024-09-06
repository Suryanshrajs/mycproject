#ifndef GRAPH_H
#define GRAPH_H

#include <stdbool.h>
#include <stddef.h>

// Structure for an adjacency list node
typedef struct AdjListNode {
    int dest;
    struct AdjListNode* next;
} AdjListNode;

// Structure for an adjacency list
typedef struct {
    AdjListNode* head;
} AdjList;

// Structure for the graph
typedef struct {
    int V; // Number of vertices
    AdjList* array;
} Graph;

// Function declarations
Graph* create_graph(int V);
void add_edge(Graph* graph, int src, int dest);
void print_graph(Graph* graph);
void free_graph(Graph* graph);

#endif

