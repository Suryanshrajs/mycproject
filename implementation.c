#include<stdio.h>
#include<stdlib.h>
// Implementation of vector 



		// Define a structure to represent the vector
		typedef struct {
		    int *data;
		    int size;
		    int capacity;
		} Vector;

		// Function to initialize the vector
		void initVector(Vector *v) {
		    v->size = 0;
		    v->capacity = 2;
		    v->data = (int *)malloc(v->capacity * sizeof(int));
		}

		// Function to add an element to the vector
		void addElement(Vector *v, int element) {
		    // Check if we need to resize the vector (if it's full)
		    if (v->size == v->capacity) {
		        v->capacity *= 2;
		        v->data = (int *)realloc(v->data, v->capacity * sizeof(int));
		    }
		    v->data[v->size] = element; 
		    v->size++;
		}

		// Function to print the elements of the vector
		void printVector(Vector *v) {
		    for (int i = 0; i < v->size; i++) {
		        printf("%d ", v->data[i]);
		    }
		    printf("\n");
		}

		// Function to free the vector memory
		void freeVector(Vector *v) {
		    free(v->data);  // Free the dynamically allocated memory
		    v->data = NULL;
		    v->size = 0;
		    v->capacity = 0;
		}
















//Searching  Algorithm
	//Binary Search

		int binarySearch(int arr[], int size, int target) {
		    int low = 0;
		    int high = size - 1;

		    while (low <= high) {
		        int mid = (low + high) / 2;  // Find the middle index 
		        // Check if the target is at the mid
		        if (arr[mid] == target) {
		            return mid;  // Return the index if target is found
		        }
		        // If target is greater, ignore the left half
		        else if (arr[mid] < target) {
		            low = mid + 1;
		        }
		        // If target is smaller, ignore the right half
		        else {
		            high = mid - 1;
		        }
		    }

		    // Target is not present in the array
		    return -1;
		}






	//Linear Search

		int linearSearch(int arr[], int size, int target) {
		    for (int i = 0; i < size; i++) {
		        // Check if the current element is the target
		        if (arr[i] == target) {
		            return i;  // Return the index if the target is found
		        }
		    }
		    return -1;  // Return -1 if the target is not found
                 }










//Sorting Algorithim
	//Merge Sort

		// Function to merge two subarrays into a single sorted array
		void merge(int arr[], int left, int mid, int right) {
		    int n1 = mid - left + 1;
		    int n2 = right - mid;

		    // Temporary arrays to store the two halves
		    int leftArr[n1], rightArr[n2];

		    // Copy data to temp arrays leftArr[] and rightArr[]
		    for (int i = 0; i < n1; i++) {
		        leftArr[i] = arr[left + i];
		    }
		    for (int i = 0; i < n2; i++) {
		        rightArr[i] = arr[mid + 1 + i];
		    }

		    // Merge the two temporary arrays back into the original array
		    int i = 0; // Initial index of the first half
		    int j = 0; // Initial index of the second half
		    int k = left; // Initial index of the merged array

		    while (i < n1 && j < n2) {
		        if (leftArr[i] <= rightArr[j]) {
		            arr[k] = leftArr[i];
		            i++;
		        } else {
		            arr[k] = rightArr[j];
		            j++;
		        }
		        k++;
		    }

		    // Copy the remaining elements of leftArr[], if any
		    while (i < n1) {
		        arr[k] = leftArr[i];
		        i++;
		        k++;
		    }

		    // Copy the remaining elements of rightArr[], if any
		    while (j < n2) {
		        arr[k] = rightArr[j];
		        j++;
		        k++;
		    }
		}

		// Function to implement merge sort
		void mergeSort(int arr[], int left, int right) {
		    if (left < right) {
		        // Calculate the middle point
		        int mid = left + (right - left) / 2;

		        // Recursively sort the first half
		        mergeSort(arr, left, mid);

		        // Recursively sort the second half
		        mergeSort(arr, mid + 1, right);

		        // Merge the two sorted halves
		        merge(arr, left, mid, right);
		    }
		}





	//Bubble Sort

		void bubbleSort(int arr[], int size) {
		    for (int i = 0; i < size - 1; i++) {
		        // Last i elements are already sorted
		        for (int j = 0; j < size - i - 1; j++) {
		            // Swap if the element is greater than the next
		            if (arr[j] > arr[j + 1]) {
		                int temp = arr[j];
		                arr[j] = arr[j + 1];
		                arr[j + 1] = temp;
		            }
		        }
		    }
		}





	//Insertion Sort

		void insertionSort(int arr[], int size) {
		    for (int i = 1; i < size; i++) {
		        int key = arr[i];  // The element to be inserted
		        int j = i - 1;

		        // Move elements of arr[0..i-1], that are greater than key,
		        // to one position ahead of their current position
		        while (j >= 0 && arr[j] > key) {
		            arr[j + 1] = arr[j];
		            j--;
		        }
		        arr[j + 1] = key;  // Insert the key at the correct position
		    }
		}





	//Selection Sort

		void selectionSort(int arr[], int size) {
		    for (int i = 0; i < size - 1; i++) {
		        // Find the index of the minimum element in the unsorted part
		        int minIndex = i;
		        for (int j = i + 1; j < size; j++) {
		            if (arr[j] < arr[minIndex]) {
		                minIndex = j;
		            }
		        }

		        // Swap the found minimum element with the first unsorted element
		        if (minIndex != i) {
		            int temp = arr[i];
		            arr[i] = arr[minIndex];
		            arr[minIndex] = temp;
		        }
		    }
		}











//stack implementattion

	#define MAX 100  // Maximum size of the stack

	// Stack structure
	struct Stack {
	    int arr[MAX];
	    int top;
	};

	// Function to initialize the stack
	void initStack(struct Stack* stack) {
	    stack->top = -1;
	}

	// Function to check if the stack is full
	int isFull(struct Stack* stack) {
	    return stack->top == MAX - 1;
	}

	// Function to check if the stack is empty
	int isEmpty(struct Stack* stack) {
	    return stack->top == -1;
	}

	// Function to push an element onto the stack
	void push(struct Stack* stack, int value) {
	    if (isFull(stack)) {
	        printf("Stack Overflow! Cannot push %d\n", value);
	    } else {
	        stack->arr[++(stack->top)] = value;
	        printf("Pushed %d onto the stack.\n", value);
	    }
	}

	// Function to pop an element from the stack
	int pop(struct Stack* stack) {
	    if (isEmpty(stack)) {
	        printf("Stack Underflow! Cannot pop.\n");
	        return -1;
	    } else {
	        return stack->arr[(stack->top)--];
	    }
	}

	// Function to peek at the top element of the stack
	int top(struct Stack* stack) {
	    if (isEmpty(stack)) {
	        printf("Stack is empty!\n");
	        return -1;
	    } else {
	        return stack->arr[stack->top];
	    }
	}











//queue implementation


	// Queue structure
	struct Queue {
	    int arr[MAX];
	    int front;
	    int rear;
	};

	// Function to initialize the queue
	void initQueue(struct Queue* queue) {
	    queue->front = -1;
	    queue->rear = -1;
	}

	// Function to check if the queue is full
	int isFull(struct Queue* queue) {
	    return (queue->rear + 1) % MAX == queue->front;
	}

	// Function to check if the queue is empty
	int isEmpty(struct Queue* queue) {
	    return queue->front == -1;
	}

	// Function to enqueue (add) an element to the queue
	void enqueue(struct Queue* queue, int value) {
	    if (isFull(queue)) {
	        printf("Queue Overflow! Cannot enqueue %d\n", value);
	    } else {
	        if (queue->front == -1) {
	            queue->front = 0;  // First element
	        }
	        queue->rear = (queue->rear + 1) % MAX;
	        queue->arr[queue->rear] = value;
	        printf("Enqueued %d into the queue.\n", value);
	    }
	}

	// Function to dequeue (remove) an element from the queue
	int dequeue(struct Queue* queue) {
	    if (isEmpty(queue)) {
	        printf("Queue Underflow! Cannot dequeue.\n");
	        return -1;
	    } else {
	        int value = queue->arr[queue->front];
	        if (queue->front == queue->rear) {
	            // Queue is now empty after the dequeue
	            queue->front = -1;
	            queue->rear = -1;
	        } else {
	            queue->front = (queue->front + 1) % MAX;
	        }
	        return value;
	    }
	}

	// Function to peek at the front element of the queue
	int peek(struct Queue* queue) {
	    if (isEmpty(queue)) {
	        printf("Queue is empty!\n");
	        return -1;
	    } else {
	        return queue->arr[queue->front];
	    }
	}
