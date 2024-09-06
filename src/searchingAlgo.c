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

