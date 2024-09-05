// Function to create a new adjacency list node
struct AdjListNode* createNode(int dest) ;

// Function to create a graph with V vertices
struct Graph* createGraph(int V);

// Function to add an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest) ;

// Function to print the adjacency list representation of the graph
void printGraph(struct Graph* graph);

// Function to free memory allocated for the graph
void freeGraph(struct Graph* graph);
