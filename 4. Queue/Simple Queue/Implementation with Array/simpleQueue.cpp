#include <iostream>
using namespace std;

int queue[5], front = 0, rear = -1, capacity = 5;

void enQueue() {
    if (rear == capacity - 1) { //Checking if the Queue is full
        cout << "\n~~ Queue is Full! ~~\n";
        return;
    }

    int val;
    cout << "\nEnter Value:- ";
    cin >> val;

    rear++;

    queue[rear] = val;

    cout << "Insertion Successfull. Value:- " << val << "\n";
    return;
}

void deQueue() {
    if (front > rear) { //Checking if the Queue is Empty
        cout << "\n~~ Queue is Empty! ~~\n";
        return;
    }

    cout << "\nData Removed:- " << queue[front] << "\n";

    front++;

    if (rear == capacity - 1 && front > rear) {
        rear = -1;
        front = 0;
        cout << "\n~~ Resetting Queue ~~\n";
    }
    return;
}

int main() {
    int choice;
    cout << "Hello! Here You Can Perform Following Queue Operation!";
    while (1) {
        cout << "\n1. En-Queue(Insert a Element at rear)\n2. De-Queue(Delete a Element at front)\n3. Peek(Show's Element in the Front)\n4. Is Empty(Checks Queue is Empty)\n5. Is Full(Checks Queue is Full)\n6. Exit\nEnter Your Choice:- ";
        cin >> choice;

        switch (choice) {
        case 1:
            enQueue();
            break;
        case 2:
            deQueue();
            break;
        case 3:
            if (front > rear) {
                cout << "\n~~ Queue is Empty! ~~\n";
                break;
            }
            cout << "\nData:- " << queue[front] << "\n";
            break;
        case 4:
            if (front > rear) {
                cout << "\n~~ Queue is Empty! ~~\n";
            } else {
                cout << "\n~~ Queue is Not Empty! ~~\n";
            }
            break;
        case 5:
            if (rear == capacity - 1) {
                cout << "\n~~ Queue is Full! ~~\n";
            } else {
                cout << "\n~~ Queue is Not Full! ~~\n";
            }
            break;
        case 6:
            cout << "\n~~ Thanks For Using! Have a Great Day! ~~\n";
            return 0;
        default:
            cout << "Please Enter a Vaild Input!\n";
            break;
        }
    }
    return 0;
}