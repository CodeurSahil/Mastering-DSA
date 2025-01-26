#include <iostream>
using namespace std;
#include <stdlib.h>

#define MAX 5

struct stack {
    int top;
    int data[MAX];
};

struct queue {
    struct stack * primaryStack;
    struct stack * secondaryStack;
};

struct queue * Queue = NULL;

void initQueue() {
    // Allocate memory for the Queue
    Queue = (struct queue *)malloc(sizeof(struct queue));

    // Allocate memory for the stacks
    Queue->primaryStack = (struct stack *)malloc(sizeof(struct stack));
    Queue->secondaryStack = (struct stack *)malloc(sizeof(struct stack));

    // Initialize the stacks
    Queue->primaryStack->top = -1;
    Queue->secondaryStack->top = -1;
}

void push(struct stack * souce, int val) {
    souce -> data[++souce -> top] = val;
    return;
}

int pop(struct stack * souce) {
    return souce->data[souce->top--];
}

void enQueue() {
    if (Queue -> primaryStack -> top == MAX - 1) {
        cout << "\n~~ Stack Overflow! ~~\n";
        return;
    }

    int val;
    cout << "\nEnter Value:- ";
    cin >> val;

    push(Queue->primaryStack, val);

    cout << "Insertion Successfull. Value:- " << val << "\n";
    return;
}

void deQueue() {
    if (Queue -> secondaryStack -> top == -1) {
        while (Queue->primaryStack->top != -1) {
            push(Queue->secondaryStack, pop(Queue->primaryStack));
        }
    }

    if (Queue -> secondaryStack -> top == -1) { //Checking if the Queue is Empty
        cout << "\n~~ Queue is Empty! ~~\n";
        return;
    }

    int removedVal = pop(Queue -> secondaryStack);

    cout << "\nData Removed:- " << removedVal << "\n";
    return;
}

int main() {
    int choice;
    initQueue();
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
            if (Queue -> primaryStack -> top == -1 && Queue -> secondaryStack -> top == -1) {
                cout << "\n~~ Queue is Empty! ~~\n";
                break;
            }

            if (Queue -> secondaryStack -> top != -1) {
                cout << "\nData:- " << Queue->secondaryStack->data[Queue->secondaryStack->top] << "\n";
            } else {
                cout << "\nData:- " << Queue->primaryStack->data[0] << "\n";
            }

            break;
        case 4:
            if (Queue -> primaryStack -> top == -1 && Queue -> secondaryStack -> top == -1) {
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