#include <iostream>
using namespace std;
#include <stdbool.h>
#define MAX_SIZE 5

typedef struct {
    int data[MAX_SIZE];
    int priorities[MAX_SIZE];
    int size;
} PriorityQueue;

void initializeQueue(PriorityQueue *pq) {
    pq->size = 0;
}

bool isEmpty(PriorityQueue *pq) {
    return pq->size == 0;
}

void enQueue(PriorityQueue *pq) {
    if (pq->size == MAX_SIZE) {
        cout << "\n~~ Queue is Full! ~~\n";
        return;
    }
    
    int val, priority, i;
    cout << "\nEnter Value:- ";
    cin >> val;

    cout << "Enter Priority:- ";
    cin >> priority;

    for (i = pq->size - 1; i >= 0 && pq->priorities[i] < priority; i--) {
        pq->data[i + 1] = pq->data[i];
        pq->priorities[i + 1] = pq->priorities[i];
    }

    pq->data[i + 1] = val;
    pq->priorities[i + 1] = priority;
    pq->size++;

    cout << "Insertion Successfull. Value:- " << val << "\n";
    return;
}

void deQueue(PriorityQueue *pq) {
    if (isEmpty(pq)) { //Checking if the Queue is Empty
        cout << "\n~~ Queue is Empty! ~~\n";
        return;
    }

    int value = pq->data[0];

    for (int i = 0; i < pq->size - 1; i++) {
        pq->data[i] = pq->data[i + 1];
        pq->priorities[i] = pq->priorities[i + 1];
    }
    pq->size--;

    cout << "\nData Removed:- " << value << "\n";
    return;
}

void peek(PriorityQueue *pq) {
    if (isEmpty(pq)) { //Checking if the Queue is Empty
        cout << "\n~~ Queue is Empty! ~~\n";
        return;
    }

    cout << "\nData Element:- " << pq -> data[0] << "\n";
    return;
}

int main() {
    int choice;
    PriorityQueue *pq;
    initializeQueue(pq);
    cout << "Hello! Here You Can Perform Following Queue Operation!";
    while (1) {
        cout << "\n1. En-Queue(Insert a Element at rear)\n2. De-Queue(Delete a Element at front)\n3. Peek(Show's Element in the Front)\n4. Is Empty(Checks Queue is Empty)\n5. Exit\nEnter Your Choice:- ";
        cin >> choice;

        switch (choice) {
        case 1:
            enQueue(pq);
            break;
        case 2:
            deQueue(pq);
            break;
        case 3:
            peek(pq);
            break;
        case 4:
            if (isEmpty(pq)) {
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