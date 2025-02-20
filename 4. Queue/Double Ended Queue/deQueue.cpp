#include <iostream>
using namespace std;
#include <stdbool.h>
#define MAX_SIZE 5

typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} DEQueue;

void initializeQueue(DEQueue *dq) {
    dq->front = -1;
    dq->rear = -1;
}

bool isEmpty(DEQueue *dq) {
    return dq->front == -1;
}

bool isFull(DEQueue *dq) {
    return (dq->front == 0 && dq->rear == MAX_SIZE - 1) || (dq->front == dq->rear + 1);
}

void enQueue(DEQueue *dq, int type) {
    if (isFull(dq)) {
        cout << "\n~~ Queue is Full! ~~\n";
        return;
    }
    
    int val;
    cout << "\nEnter Value:- ";
    cin >> val;

    if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
        dq->data[dq->front] = val;
    } else if (type == 1) {
        if (dq->front == 0) {
            dq->front = MAX_SIZE - 1;
        } else {
            dq->front--;
        }
        dq->data[dq->front] = val;
    } else if (type == 2) {
        if (dq->rear == MAX_SIZE - 1) {
            dq->rear = 0;
        } else {
            dq->rear++;
        }
        dq->data[dq->rear] = val;
    }

    cout << "Insertion Successfull. Value:- " << val << "\n";
    return;
}

void deQueue(DEQueue *dq, int type) {
    if (isEmpty(dq)) { //Checking if the Queue is Empty
        cout << "\n~~ Queue is Empty! ~~\n";
        return;
    }

    int toBeDeletedValue;

    if (dq->front == dq->rear) {
        toBeDeletedValue = dq->data[dq->front];
        dq->front = dq->rear = -1; // Reset queue
    } else if (type == 1) {
        
        toBeDeletedValue = dq->data[dq->front];

        if (dq->front == MAX_SIZE - 1) {
            dq->front = 0;
        } else {
            dq->front++;//2 -> 3 -> 4
        }
    } else if (type == 2) {
        toBeDeletedValue = dq->data[dq->rear];

        if (dq->rear == 0) {
            dq->rear = MAX_SIZE - 1;
        } else {
            dq->rear--;//1 -> 0 -> 4
        }
    }

    cout << "\nData Removed:- " << toBeDeletedValue << "\n";
    return;
}

void peek(DEQueue *dq, int type) {
    if (isEmpty(dq)) { //Checking if the Queue is Empty
        cout << "\n~~ Queue is Empty! ~~\n";
        return;
    }

    int peekVal;

    if (type == 1) {
        peekVal = dq->data[dq->front];
    } else if (type == 2) {
        peekVal = dq->data[dq->rear];
    }

    cout << "\nData Element:- " << peekVal << "\n";
    return;
}

int main() {
    int choice;
    DEQueue *dq;
    initializeQueue(dq);
    cout << "Hello! Here You Can Perform Following Queue Operation!";
    while (1) {
        cout << "\n1. En-Queue Front\n2. En-Queue Rear\n3. De-Queue Front \n4. De-Queue Rear\n5. Peek Front\n6. Peek Rear\n7. Is Empty(Checks Queue is Empty)\n8. Is Full(Checks Queue is Full)\n9. Exit\nEnter Your Choice:- ";
        cin >> choice;

        switch (choice) {
        case 1:
            enQueue(dq, 1);
            break;
        case 2:
            enQueue(dq, 2);
            break;
        case 3:
            deQueue(dq, 1);
            break;
        case 4:
            deQueue(dq, 2);
            break;
        case 5:
            peek(dq, 1);
            break;
        case 6:
            peek(dq, 2);
            break;
        case 7:
            if (isEmpty(dq)) {
                cout << "\n~~ Queue is Empty! ~~\n";
            } else {
                cout << "\n~~ Queue is Not Empty! ~~\n";
            }
            break;
        case 8:
            if (isFull(dq)) {
                cout << "\n~~ Queue is Full! ~~\n";
            } else {
                cout << "\n~~ Queue is Not Full! ~~\n";
            }
            break;
        case 9:
            cout << "\n~~ Thanks For Using! Have a Great Day! ~~\n";
            return 0;
        default:
            cout << "Please Enter a Vaild Input!\n";
            break;
        }
    }
    return 0;
}