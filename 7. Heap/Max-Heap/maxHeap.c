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

    int smallest = index;

    if (leftChild < arrayLength && arr[leftChild] > arr[index])
        smallest = leftChild;
    if (rightChild < arrayLength && arr[rightChild] > arr[smallest])
        smallest = rightChild;

    if (smallest != index) {
        swap(index, smallest);
        heapify(smallest);
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

    while (index != 0 && arr[getParent(index)] < arr[index]) {
        
        swap(index, getParent(index));

        index = getParent(index);
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
    printf("Hello! Here You Can Perform Following Max Heap Operation!");
    while (1) {
        printf("\n1. View(In Array)\n2. Insert\n3. Extraction of Maximum\n4. Delete at Index\n5. Peek (Get Maximum)\n6. Exit\nEnter Your Choice:- ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (arrayLength == 0) {
                printf("\n~~ Heap is Empty! ~~\n");
                break;
            }
            for (int i = 0; i < arrayLength; i++) {
                if (i == 0)
                    printf("\nHeap: %d", arr[i]);
                else
                    printf(", %d", arr[i]);
            }
            break;
        case 2:
            insert();
            break;
        case 3:
            if (arrayLength == 0) {
                printf("\n~~ Heap is Empty! ~~\n");
                break;
            }
            extract(0);
            break;
        case 4:
            if (arrayLength == 0) {
                printf("\n~~ Heap is Empty! ~~\n");
                break;
            }

            int index;
            printf("\nInsert Index(Starts with 0):- ");
            scanf("%d", &index);

            extract(index);
            break;
        case 5:
            peek();
            break;
        case 6:
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