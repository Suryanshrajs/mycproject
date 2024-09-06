#include "graph.h"
#include <stdio.h>
#include <stdlib.h>

// Helper function to create a new adjacency list node
AdjListNode* new_adj_list_node(int dest) {
    AdjListNode* new_node = (AdjListNode*)malloc(sizeof(AdjListNode));
    if (new_node) {
        new_node->dest = dest;
        new_node->next = NULL;
    }
    return new_node;
}

// Function to create a graph with V vertices
Graph* create_graph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    if (graph) {
        graph->V = V;
        graph->array = (AdjList*)malloc(V * sizeof(AdjList));

        for (int i = 0; i < V; ++i) {
            graph->array[i].head = NULL;
        }
    }
    return graph;
}

// Function to add an edge to the graph
void add_edge(Graph* graph, int src, int dest) {
    AdjListNode* new_node = new_adj_list_node(dest);
    new_node->next = graph->array[src].head;
    graph->array[src].head = new_node;

    // For an undirected graph, add an edge from dest to src as well
    new_node = new_adj_list_node(src);
    new_node->next = graph->array[dest].head;
    graph->array[dest].head = new_node;
}

// Function to print the graph
void print_graph(Graph* graph) {
    for (int v = 0; v < graph->V; ++v) {
        AdjListNode* pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl) {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

// Function to free the graph
void free_graph(Graph* graph) {
    for (int v = 0; v < graph->V; ++v) {
        AdjListNode* pCrawl = graph->array[v].head;
        while (pCrawl) {
            AdjListNode* temp = pCrawl;
            pCrawl = pCrawl->next;
            free(temp);
        }
    }
    free(graph->array);
    free(graph);
}
