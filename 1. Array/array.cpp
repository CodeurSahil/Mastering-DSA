#include <iostream>
using namespace std;
#include <stdlib.h>

int *ptr = NULL, arrayLength = 0;

void generateArray(int len) {
    if (len > 0) {
        arrayLength = len;
        ptr = (int *)realloc(ptr, arrayLength * sizeof(int));
        if (ptr == NULL) {
            cout << "Memory allocation failed.\n";
            exit(1); // Exit the program on allocation failure
        }
    }
}

void print() { // Show Data
    if (arrayLength == 0) {
        cout << "\n~~ Array is Empty! ~~\n";
    }
    else {
        cout << "\nData:- " << ptr[0];
        for (int i = 1; i < arrayLength; i++) {
            cout << ", " << ptr[i];
        }
        cout << "\n";
    }
}

void reversePrint() { // Show in Reverse
    if (arrayLength == 0) {
        cout << "\n~~ Array is Empty! ~~\n";
    }
    else {
        cout << "\nData(Reverse):- " << ptr[arrayLength - 1];
        for (int i = arrayLength - 1; i > 0; i--) {
            cout << ", " << ptr[i - 1];
        }
        cout << "\n";
    }
}

int length() { // Length of Data
    cout << "\nData Length: " << arrayLength  << "\n";
    return arrayLength;
}

void push() { // Insert At Last
    generateArray(arrayLength + 1);
    int val;
    cout << "\nEnter Value:- ";
    cin >> val;
    ptr[arrayLength - 1] = val;
    cout << "Insertion Successfull. Value:- " << val << "\n";
}

void pop() { // Remove From Last
    if (arrayLength == 0) {
        cout << "\n~~ Array is Empty! Cannot Remove ~~\n";
        return;
    }
    cout << "\nRemoved Value: " << ptr[arrayLength - 1] << "\n";
    generateArray(arrayLength - 1);
}

void insertInPlace() { // Insert at Specific Position
    int val, pos;
    cout << "\nEnter Value:- ";
    cin >> val;
    cout << "Enter Position Number to Insert(Greater than 0):- ";
    cin >> pos;

    if (pos <= 0 || pos > arrayLength + 1) {
        cout << "Invalid Position: " << pos << "\n";
        return;
    }

    generateArray(arrayLength + 1);

    for (int i = arrayLength - 1; i >= pos - 1; i--) {
        ptr[i] = ptr[i - 1]; // Shift elements to the right
    }
    ptr[pos - 1] = val;
    cout << "Insertion Successful at Position " << pos  << ". Value: " << val << "\n";
}

void deleteInPlace() { // Remove From Specific Position
    int pos;
    cout << "\nEnter Position Number to Insert(Greater than 0):- ";
    cin >> pos;

    if (pos <= 0 || pos > arrayLength) {
        cout << "Invalid Position: " << pos << "\n";
        return;
    }

    cout << "Removed Value: " << ptr[pos - 1] << "\n";

    for (int i = pos - 1; i < arrayLength - 1; i++) {
        ptr[i] = ptr[i + 1]; // Shift elements to the left
    }

    generateArray(arrayLength - 1);
}

int main() {
    int choice;
    cout << "Hello! Here You Can Perform Following Array Operation!";
    while (1) {
        cout << "\n1. Show Data\n2. Show in Reverse\n3. Insert At Last\n4. Insert at Specific Position\n5. Remove From Last\n6. Remove From Specific Position\n7. Lenght of Data\n8. Exit\nEnter Your Choice:- ";
        cin >> choice;

        switch (choice) {
        case 1:
            print();
            break;
        case 2:
            reversePrint();
            break;
        case 3:
            push();
            break;
        case 4:
            insertInPlace();
            break;
        case 5:
            pop();
            break;
        case 6:
            deleteInPlace();
            break;
        case 7:
            length();
            break;
        case 8:
            free(ptr);
            cout << "\n ~~ Thanks For Using! Have a Great Day! ~~";
            return 0;
        default:
            cout << "Please Enter a Vaild Input!\n";
            break;
        }
    }
    return 0;
}