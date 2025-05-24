#include <iostream>
using namespace std;
#include <math.h>

int *arr = NULL, arrayLength = 0;

void manageArray(int len) {
    if (len > 0) {
        arr = (int *)realloc(arr, len * sizeof(int));
        if (arr == NULL) {
            cout << "Memory allocation failed.\n";
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
        cout << "\n~~ Heap is Empty! ~~\n";
        return;
    }

    int val = arr[0];
    cout << "Value: " << val << endl;
}

void insert() { // Insert
    int val;
    cout << "\nEnter Value:- ";
    cin >> val;

    manageArray(arrayLength + 1);
    
    int index = arrayLength;
    
    arr[arrayLength++] = val;

    while (index != 0 && arr[getParent(index)] > arr[index]) {
        
        swap(index, getParent(index));

        index = getParent(index);
    }

    cout << "Insertion Successful, Value: " << val << endl;
}

void extract(int index) {
    if (arrayLength < index) {
        cout << "\n~~ Index Value Not Present! ~~\n";
        return;
    }

    int val = arr[index];
    cout << "Extracted Value: " << val << endl;

    arr[index] = arr[arrayLength - 1];

    manageArray(--arrayLength);

    heapify(index);
    return;
}

int main() {
    int choice;
    cout << "Hello! Here You Can Perform Following Min Heap Operation!";
    while (1) {
        cout << "\n1. View(In Array)\n2. Insert\n3. Extraction of Minimum\n4. Delete at Index\n5. Peek (Get Minimum)\n6. Exit\nEnter Your Choice:- ";
        cin >> choice;

        switch (choice) {
        case 1:
            if (arrayLength == 0) {
                cout << "\n~~ Heap is Empty! ~~\n";
                break;
            }

            for (int i = 0; i < arrayLength; i++) {
                if (i == 0)
                    cout << "\nHeap: " << arr[i];
                else
                    cout << ", " << arr[i];
            }
            break;
        case 2:
            insert();
            break;
        case 3:
            if (arrayLength == 0) {
                cout << "\n~~ Heap is Empty! ~~\n";
                break;
            }
            extract(0);
            break;
        case 4:
            if (arrayLength == 0) {
                cout << "\n~~ Heap is Empty! ~~\n";
                break;
            }

            int index;
            cout << "\nInsert Index(Starts with 0):- ";
            cin >> index;

            extract(index);
            break;
        case 5:
            peek();
            break;
        case 6:
            cout << "Thanks For Using! Have a Great Day!";
            free(arr);
            return 0;
        default:
            cout << "Please Enter a Vaild Input!\n";
            break;
        }
    }
    return 0;
}