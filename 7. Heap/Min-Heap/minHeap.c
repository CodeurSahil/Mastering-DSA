#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int *arr = NULL, arrayLength = 0;

void manageArray(int len) {
    if (len > 0) {
        arr = (int *)realloc(arr, len * sizeof(int));
        if (arr == NULL) {
            printf("Memory allocation failed.\n");
            exit(1); // Exit the program on allocation failure
        }
    }
}

// Returns the index of the Parent.
int getParent(int i) {
    return (i - 1) / 2;
}

// Returns the index of the left child.
int getLeftChild(int i) {
    return (2 * i + 1);
}

// Returns the index of the right child.
int getRightChild(int i) {
    return (2 * i + 2);
}

void swap(int childIndex, int parentIndex) {
    int temp = arr[childIndex];
    arr[childIndex] = arr[parentIndex];
    arr[parentIndex] = temp;
    return;
}

void heapify(int index) {
    int leftChild = getLeftChild(index);
    int rightChild = getRightChild(index);

    int largest = index;

    if (leftChild < arrayLength && arr[leftChild] < arr[index])
        largest = leftChild;
    if (rightChild < arrayLength && arr[rightChild] < arr[largest])
        largest = rightChild;

    if (largest != index) {
        swap(index, largest);
        heapify(largest);
    }
}

void peek() {
    if (arrayLength == 0) {
        printf("\n~~ Heap is Empty! ~~\n");
        return;
    }

    int val = arr[0];
    printf("Value: %d\n", val);
}

void insert() { // Insert
    int val;
    printf("\nEnter Value:- ");
    scanf("%d", &val);

    manageArray(arrayLength + 1);
    
    int index = arrayLength;
    
    arr[arrayLength++] = val;

    while (index != 0 && arr[getParent(index)] > arr[index]) {
        printf("minHeap.c:79 %d %d", arr[index], arr[getParent(index)]);
        
        swap(index, getParent(index));

        printf("minHeap.c:79 %d %d", arr[index], arr[getParent(index)]);
        index = getParent(index);
    }

    for (int i = 0; i < arrayLength; i++)
    {
        printf(", %d", arr[i]);
    }

    printf("Insertion Successful, Value: %d\n", val);
}

void extract(int index) {
    if (arrayLength < index) {
        printf("\n~~ Index Value Not Present! ~~\n");
        return;
    }

    int val = arr[index];
    printf("Extracted Value: %d\n", val);

    arr[index] = arr[arrayLength - 1];

    manageArray(--arrayLength);

    heapify(index);
    return;
}

int main() {
    int choice;
    printf("Hello! Here You Can Perform Following Min Heap Operation!");
    while (1) {
        printf("\n1. Insert\n2. Extraction of Minimum\n3. Delete at Index\n4. Peek (Get Minimum)\n5. Exit\nEnter Your Choice:- ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            insert();
            break;
        case 2:
            if (arrayLength == 0) {
                printf("\n~~ Heap is Empty! ~~\n");
                break;
            }
            extract(0);
            break;
        case 3:
            if (arrayLength == 0) {
                printf("\n~~ Heap is Empty! ~~\n");
                break;
            }

            int index;
            printf("\nInsert Index(Starts with 0):- ");
            scanf("%d", &index);
            extract(index);
            break;
        case 4:
            peek();
            break;
        case 5:
            printf("Thanks For Using! Have a Great Day!");
            free(arr);
            return 0;
        default:
            printf("Please Enter a Vaild Input!\n");
            break;
        }
    }
    return 0;
}