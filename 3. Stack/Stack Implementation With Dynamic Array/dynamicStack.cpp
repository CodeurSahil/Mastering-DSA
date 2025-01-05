#include <iostream>
using namespace std;
#include <stdlib.h>

int *stack = NULL, stackPointer = -1;

void handleStackSize(int len) {
    if (len > 0) {
        stack = (int *)realloc(stack, len * sizeof(int));
        if (stack == NULL) {
            printf("Memory allocation failed.\n");
            exit(1); // Exit the program on allocation failure
        }
    }
}


void push() {
    int val;
    cout <<"\nEnter Value:- ";
    cin >> val;
    stackPointer++;
    handleStackSize(stackPointer + 1);
    stack[stackPointer] = val;
    cout <<"Insertion Successfull. Value:- " << val << "\n";
}

void pop() {
    if (stackPointer == -1) {
        cout <<"\n~~ Stack is Empty~~\n";
        return;
    }

    cout <<"\nRemoved Value: " << stack[stackPointer] << "\n";
    stackPointer--;
    handleStackSize(stackPointer + 1);
}

int main() {
    int choice;
    cout << "Hello! Here You Can Perform Following Stack Operation!";
    while (1) {
        cout <<"\n1. Push(Insert)\n2. Pop(Delete)\n3. Peek(See Last Element)\n4. Is Empty(Checks weather Stack is Empty)\n5. Exit\nEnter Your Choice:- ";
        cin >> choice;

        switch (choice) {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            if (stackPointer == -1) {
                cout <<"\n~~ Stack is Empty~~\n";
            } else {
                cout <<"\nTop Element:- " << stack[stackPointer] << "\n";
            }
            break;
        case 4:
            if (stackPointer == -1) {
                cout <<"\n~~ Stack is Empty~~\n";
            } else {
                cout <<"\n~~ Stack is Not Empty~~\n";
            }
            break;
        case 5:
            cout <<"\n~~Thanks For Using! Have a Great Day!~~\n";
            return 0;
        default:
            cout <<"\n~~Please Enter a Vaild Input!~~\n";
            break;
        }
    }
    return 0;
}