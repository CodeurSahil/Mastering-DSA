#include <stdio.h>
#include <stdlib.h>

// Global pointer for the dynamic array that will represent the heap.
int *arr = NULL;
// Global variable to store the current number of elements in the heap.
int arrayLength = 0;

/**
 * @brief Manages the size of the heap's underlying dynamic array.
 * @param len The new desired number of elements for the array.
 */
void manageArray(int len) {
    // Only reallocate if the requested length is positive.
    if (len > 0) {
        int* temp = (int *)realloc(arr, len * sizeof(int));
        if (temp == NULL) {
            printf("Memory allocation failed.\n");
            free(arr); // Free the old block if realloc fails
            exit(1); // Exit the program on allocation failure
        }
        arr = temp;
    } else {
        // If length is 0, free the memory.
        free(arr);
        arr = NULL;
    }
}

/**
 * @brief Returns the index of the parent of a node at index i.
 * @param i The index of the child node.
 * @return The index of the parent node.
 */
int getParent(int i) {
    return (i - 1) / 2;
}

/**
 * @brief Returns the index of the left child of a node at index i.
 * @param i The index of the parent node.
 * @return The index of the left child.
 */
int getLeftChild(int i) {
    return (2 * i + 1);
}

/**
 * @brief Returns the index of the right child of a node at index i.
 * @param i The index of the parent node.
 * @return The index of the right child.
 */
int getRightChild(int i) {
    return (2 * i + 2);
}

/**
 * @brief Swaps two elements in the heap array.
 * @param index1 The index of the first element.
 * @param index2 The index of the second element.
 */
void swap(int index1, int index2) {
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

/**
 * @brief Maintains the min-heap property for a subtree rooted at a given index.
 * It assumes that the subtrees are already heapified.
 * @param index The root index of the subtree to heapify.
 */
void heapify(int index) {
    int leftChild = getLeftChild(index);
    int rightChild = getRightChild(index);
    int smallest = index; // Assume the root is the smallest initially.

    // If the left child exists and is smaller than the current smallest, update smallest.
    if (leftChild < arrayLength && arr[leftChild] < arr[smallest])
        smallest = leftChild;
    
    // If the right child exists and is smaller than the current smallest, update smallest.
    if (rightChild < arrayLength && arr[rightChild] < arr[smallest])
        smallest = rightChild;

    // If the smallest element is not the root, swap them and recursively heapify the affected subtree.
    if (smallest != index) {
        swap(index, smallest);
        heapify(smallest);
    }
}

/**
 * @brief Shows the minimum element in the heap (the root) without removing it.
 */
void peek() {
    if (arrayLength == 0) {
        printf("\n~~ Heap is Empty! ~~\n");
        return;
    }
    printf("Minimum Value (Root): %d\n", arr[0]);
}

/**
 * @brief Inserts a new value into the min heap.
 */
void insert() {
    int val;
    printf("\nEnter Value:- ");
    scanf("%d", &val);

    // Increase the array size by 1.
    manageArray(arrayLength + 1);
    
    // Insert the new element at the end.
    int index = arrayLength;
    arr[arrayLength++] = val;

    // "Bubble up" the new element to its correct position to maintain the min-heap property.
    // Keep swapping with the parent as long as the child is smaller than the parent.
    while (index != 0 && arr[getParent(index)] > arr[index]) {
        swap(index, getParent(index));
        index = getParent(index);
    }

    printf("Insertion Successful, Value: %d\n", val);
}

/**
 * @brief Extracts (removes) an element at a specific index.
 * This is a generalized version of extracting the minimum.
 * @param index The index of the element to extract.
 */
void extract(int index) {
    if (index >= arrayLength) {
        printf("\n~~ Index out of bounds! ~~\n");
        return;
    }

    printf("Extracted Value: %d\n", arr[index]);

    // Replace the element to be removed with the last element in the heap.
    arr[index] = arr[arrayLength - 1];
    
    // Decrease the size of the heap.
    arrayLength--;
    manageArray(arrayLength);

    // Call heapify on the replaced element's index to restore the heap property.
    if(arrayLength > 0) {
       heapify(index);
    }
}

/**
 * @brief The main function that drives the program.
 */
int main() {
    int choice;
    printf("Hello! Here You Can Perform Following Min Heap Operation!");
    while (1) {
        printf("\n1. View(In Array)\n2. Insert\n3. Extraction of Minimum\n4. Delete at Index\n5. Peek (Get Minimum)\n6. Exit\nEnter Your Choice:- ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: // View Heap
            if (arrayLength == 0) {
                printf("\n~~ Heap is Empty! ~~\n");
                break;
            }
            printf("\nHeap: ");
            for (int i = 0; i < arrayLength; i++) {
                printf("%d ", arr[i]);
            }
            printf("\n");
            break;
        case 2: // Insert
            insert();
            break;
        case 3: // Extract Minimum
            if (arrayLength == 0) {
                printf("\n~~ Heap is Empty! ~~\n");
                break;
            }
            extract(0); // The minimum element is always at the root (index 0).
            break;
        case 4: // Delete at specific index
            if (arrayLength == 0) {
                printf("\n~~ Heap is Empty! ~~\n");
                break;
            }
            int index;
            printf("\nEnter Index to delete (Starts with 0):- ");
            scanf("%d", &index);
            extract(index);
            break;
        case 5: // Peek
            peek();
            break;
        case 6: // Exit
            printf("\nThanks For Using! Have a Great Day!\n");
            free(arr); // Free the dynamically allocated memory.
            return 0;
        default:
            printf("\nPlease Enter a Vaild Input!\n");
            break;
        }
    }
    return 0;
}
