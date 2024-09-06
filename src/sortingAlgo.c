






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




















