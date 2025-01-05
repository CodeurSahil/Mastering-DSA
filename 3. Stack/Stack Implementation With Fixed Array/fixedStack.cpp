#include <iostream>
using namespace std;

int stack[10], stackPointer = -1, stackSize = 10;

void push() {
    if (stackPointer + 1 == stackSize) {
        cout << "\n~~ Stack is Full~~\n";
        return;
    }

    int val;
    cout <<"\nEnter Value:- ";
    cin >> val;
    stackPointer++;
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
}

int main() {
    int choice;
    cout << "Hello! Here You Can Perform Following Stack Operation!";
    while (1) {
        cout <<"\n1. Push(Insert)\n2. Pop(Delete)\n3. Peek(See Last Element)\n4. Is Empty(Checks weather Stack is Empty)\n5. Is Full(Checks weather Stack is Full)\n6. Exit\nEnter Your Choice:- ";
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
            if (stackPointer + 1 == stackSize) {
                cout <<"\n~~ Stack is Full~~\n";
            } else {
                cout <<"\n~~ Stack is Not Full~~\n";
            }
            break;
        case 6:
            cout <<"\n~~Thanks For Using! Have a Great Day!~~\n";
            return 0;
        default:
            cout <<"\n~~Please Enter a Vaild Input!~~\n";
            break;
        }
    }
    return 0;
}