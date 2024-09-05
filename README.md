Custom STL-like Library in C
Welcome to the Custom STL-like Library in C! This repository contains a collection of implementations for various data structures and algorithms, inspired by the Standard Template Library (STL) found in C++. The goal of this project is to provide foundational components that can be used and extended for various applications.

Features
Data Structures
Vector

A dynamic array that automatically resizes as elements are added. Provides random access and efficient appends.
Stack

A Last-In-First-Out (LIFO) data structure. Supports standard operations like push, pop, and peek.
Queue

A First-In-First-Out (FIFO) data structure. Supports enqueue and dequeue operations.
Algorithms
Searching Algorithms

Linear Search: A straightforward search algorithm that checks each element sequentially.
Binary Search: An efficient search algorithm for sorted arrays, dividing the search interval in half repeatedly.
Sorting Algorithms

Bubble Sort: A simple comparison-based algorithm that repeatedly steps through the list.
Selection Sort: An in-place comparison-based algorithm that repeatedly selects the smallest element.
Insertion Sort: Builds the final sorted array one item at a time.
Merge Sort: A divide-and-conquer algorithm that divides the array into halves and merges them.
Quick Sort: An efficient, in-place sorting algorithm based on partitioning.
Installation
To use this library, clone the repository and compile the individual components as needed:

bash
Copy code
git clone https://github.com/yourusername/yourrepo.git
cd yourrepo
Usage
Each component of the library can be used independently or together. Here are examples of how to use the various data structures and algorithms:

Vector Example
c
Copy code
#include "vector.h"

int main() {
    Vector vec;
    vector_init(&vec);

    vector_add(&vec, 10);
    vector_add(&vec, 20);
    vector_add(&vec, 30);

    printf("Vector contents:\n");
    for (int i = 0; i < vec.size; i++) {
        printf("%d ", vector_get(&vec, i));
    }
    printf("\n");

    vector_free(&vec);  // Clean up the vector memory
    return 0;
}
Stack Example
c
Copy code
#include "stack.h"

int main() {
    Stack stack;
    initStack(&stack);

    push(&stack, 5);
    push(&stack, 10);

    printf("Top element: %d\n", peek(&stack));
    printf("Popped element: %d\n", pop(&stack));

    return 0;
}
Queue Example
c
Copy code
#include "queue.h"

int main() {
    Queue queue;
    initQueue(&queue);

    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);

    printf("Dequeued element: %d\n", dequeue(&queue));
    printf("Front element: %d\n", peek(&queue));

    return 0;
}
Searching Algorithms Example
c
Copy code
#include "searching.h"

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    int searchResult = linear_search(arr, size, 3);
    printf("Linear Search Result: %d\n", searchResult);

    searchResult = binary_search(arr, size, 4);
    printf("Binary Search Result: %d\n", searchResult);

    return 0;
}
Sorting Algorithms Example
c
Copy code
#include "sorting.h"

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int size = sizeof(arr) / sizeof(arr[0]);

    bubble_sort(arr, size);
    printf("Sorted array (Bubble Sort): ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int arr2[] = {64, 25, 12, 22, 11};
    selection_sort(arr2, size);
    printf("Sorted array (Selection Sort): ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    return 0;
}
Documentation
Detailed documentation for each component and algorithm is available in the respective header files. Please refer to these files for additional information on function signatures and usage.

Contributing
Contributions are welcome! If you find any bugs or have suggestions for improvement, please open an issue or submit a pull request. When contributing, please follow these guidelines:

Ensure that your code adheres to the existing style.
Write clear and concise commit messages.
Provide tests and documentation for new features.
License
This project is licensed under the MIT License. See the LICENSE file for more details.

Contact
For any questions or feedback, please contact your-email@example.com.
