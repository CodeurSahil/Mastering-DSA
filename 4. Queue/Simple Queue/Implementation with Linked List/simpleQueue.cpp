#include <iostream>
using namespace std;
#include <stdlib.h>

struct queueNode {
    int data;
    struct queueNode *next;
};

struct queueNode *front = NULL, *rear = NULL;

struct queueNode * createNode(int val){
    struct queueNode *newNode = (struct queueNode *)malloc(sizeof(struct queueNode));
    if (newNode == NULL) {
        cout << "\nMemory Allocation Failed";
        exit(1);
    }
    newNode -> data = val;
    newNode -> next = NULL;
    return newNode;
}

void enQueue() {
    int val;
    cout << "\nEnter Value:- ";
    cin >> val;

    struct queueNode *newNode = createNode(val);

    if (front == NULL) {
        front = newNode;
        rear = newNode;
    } else {
        rear -> next = newNode;
        rear = newNode;
    }

    cout << "Insertion Successfull. Value:- " << val << "\n";
    return;
}

void deQueue() {
    if (front == NULL) { //Checking if the Queue is Empty
        cout << "\n~~ Queue is Empty! ~~\n";
        return;
    }

    struct queueNode *toBeDeletedNode = front;

    front = front -> next;

    if (front == NULL) {
        rear = NULL;
    }

    cout << "\nData Removed:- " << toBeDeletedNode -> data << "\n";
    free(toBeDeletedNode);
    return;
}

int main() {
    int choice;
    cout << "Hello! Here You Can Perform Following Queue Operation!";
    while (1) {
        cout << "\n1. En-Queue(Insert a Element at rear)\n2. De-Queue(Delete a Element at front)\n3. Peek(Show's Element in the Front)\n4. Is Empty(Checks Queue is Empty)\n5. Exit\nEnter Your Choice:- ";
        cin >> choice;

        switch (choice) {
        case 1:
            enQueue();
            break;
        case 2:
            deQueue();
            break;
        case 3:
            if (front == NULL) {
                cout << "\n~~ Queue is Empty! ~~\n";
                break;
            }
            cout << "\nData:- " << front -> data << "\n";
            break;
        case 4:
            if (front == NULL) {
                cout << "\n~~ Queue is Empty! ~~\n";
            } else {
                cout << "\n~~ Queue is Not Empty! ~~\n";
            }
            break;
        case 5:
            cout << "\n~~ Thanks For Using! Have a Great Day! ~~\n";
            return 0;
        default:
            cout << "Please Enter a Vaild Input!\n";
            break;
        }
    }
    return 0;
}