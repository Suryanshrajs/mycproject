# C Standard Template Library (STL) - Data Structures and Algorithms

Welcome to the **C Standard Template Library (STL)**! This library is a comprehensive collection of fundamental data structures and algorithms implemented in pure C, inspired by the C++ STL. Whether you are building a small project or working on a larger software system, this library is designed to provide reusable, efficient, and modular components for various computational needs.

## 📚 Features Overview

### Data Structures
This library includes the following core data structures:
- **Binary Search Tree (BST)**: Efficient for sorted data storage and retrieval.
- **Graph**: Represent and manipulate networks, supporting both directed and undirected graphs.
- **Hash Table**: Fast key-value mapping with collision handling via chaining or open addressing.
- **Heap**: Min-Heap and Max-Heap for priority queues and efficient sorting.
- **Linked List**: Includes singly, doubly, and circular variants for flexible dynamic storage.
- **Queue**: FIFO (First-In-First-Out) structure for task scheduling and processing, includes circular queue.
- **Stack**: LIFO (Last-In-First-Out) structure for expression evaluation and backtracking.
- **Vector**: Dynamic array offering automatic resizing, with fast access and modification.

### Algorithms
In addition to data structures, the library implements various classical algorithms:
- **Sorting Algorithms**:
  - Bubble Sort
  - Selection Sort
  - Insertion Sort
  - Merge Sort
  
- **Searching Algorithms**:
  - Linear Search
  - Binary Search

### Key Highlights
- **Modularity**: Each data structure and algorithm is implemented in its own module, allowing you to use only what you need.
- **Efficiency**: Designed to minimize overhead and provide high performance, with constant-time operations for hash table lookups, logarithmic time for BST searches, and more.
- **Robust Error Handling**: Ensures safe memory usage with error handling for edge cases like memory allocation failure.

## 💻 Installation and Setup

### Cloning the Repository
To get started with this library, clone the repository from GitHub:
```bash
git clone https://github.com/suryanshrajs/mycproject.git
cd mycproject
```

### Compiling the Library
This library is designed to be compiled using `gcc` or any other C compiler. Simply include the `.c` and `.h` files for the data structures and algorithms you wish to use in your project.

Example of compiling a program that uses the vector and sorting algorithm:
```bash
gcc -c graph.c hashtable.c heap.c linkedlist.c queue.c stack.c bst.c vector.c searching.c sorting.c
ar rcs myLibrary.a graph.o hashtable.o heap.o linkedlist.o queue.o stack.o bst.o vector.o searching.o sorting.o
gcc -o program program.c -L. myLibrary.a
./program

```

## 🔍 How to Use


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
    list_init(&list);
    list_append(&list, 10);
    list_append(&list, 20);
    list_print(&list);
    list_free(&list);

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
    HashTable table;
    hash_table_init(&table, 10);
    hash_table_insert(&table, "key1", 10);
    printf("Hashtable Element: %d\n", hash_table_get(&table, "key1"));
    hash_table_free(&table);

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
    //printf("\n----- Binary Search Tree (BST) Example -----\n");
    //BST bst;
    //bst_init(&bst);
    //bst_insert(&bst, 10);
    //bst_insert(&bst, 20);
    //bst_insert(&bst, 5);
    //bst_in_order_traversal(&bst);
    //bst_free(&bst);

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

## 📂 Project Structure
The repository is organized as follows:
```
/src
    bst.c, bst.h          # Binary Search Tree
    graph.c, graph.h      # Graph
    hashtable.c, hashtable.h # Hash Table
    heap.c, heap.h        # Heap
    linkedlist.c, linkedlist.h # Linked List
    queue.c, queue.h      # Queue
    stack.c, stack.h      # Stack
    vector.c, vector.h    # Vector
    searching.c, searching.h # Searching Algorithms
    sorting.c, sorting.h     # Sorting Algorithms

/program.c                   # Example usage
/README.md                # Project documentation
```

## 🌟 Contributions
Contributions to this library are highly encouraged! If you have any ideas for improving the library, implementing additional data structures or algorithms, or fixing bugs, feel free to open an issue or create a pull request.

### How to Contribute
1. Fork the repository.
2. Create a new branch for your feature or bug fix:
   ```bash
   git checkout -b feature/new-feature
   ```
3. Commit your changes:
   ```bash
   git commit -m "Added a new feature"
   ```
4. Push to the branch:
   ```bash
   git push origin feature/new-feature
   ```
5. Open a pull request on GitHub.


## 📧 Contact
If you have any questions, suggestions, or feedback, please feel free to contact me:
- **Email**: suryansh.rajs96@gmail.com
- **GitHub**: [suryanshrajs](https://github.com/suryanshrajs)

## 👨‍💻 Authors
- **Suryansh Singh** - Main Developer

Thank you for using this C STL library! I hope it proves to be useful in your projects. Happy coding!
