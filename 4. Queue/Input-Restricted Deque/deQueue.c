#include <stdio.h>
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

void enQueue(DEQueue *dq) {
    if (isFull(dq)) {
        printf("\n~~ Queue is Full! ~~\n");
        return;
    }

    int val;
    printf("\nEnter Value:- ");
    scanf("%d", &val);

    if (isEmpty(dq)) {
        dq->front = dq->rear = 0;
    } else {
        if (dq->rear == MAX_SIZE - 1) {
            dq->rear = 0;
        } else {
            dq->rear++;
        }
    }

    dq->data[dq->rear] = val;

    printf("Insertion Successfull. Value:- %d\n", val);
    return;
}

void deQueue(DEQueue *dq, int type) {
    if (isEmpty(dq)) { //Checking if the Queue is Empty
        printf("\n~~ Queue is Empty! ~~\n");
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

    printf("\nData Removed:- %d\n", toBeDeletedValue);
    return;
}

void peek(DEQueue *dq, int type) {
    if (isEmpty(dq)) { //Checking if the Queue is Empty
        printf("\n~~ Queue is Empty! ~~\n");
        return;
    }

    int peekVal;
    if (type == 1) {
        peekVal = dq->data[dq->front];
    } else if (type == 2) {
        peekVal = dq->data[dq->rear];
    }

    printf("\nData Element:- %d\n", peekVal);
    return;
}

int main() {
    int choice;
    DEQueue *dq;
    initializeQueue(dq);
    printf("Hello! Here You Can Perform Following Queue Operation!");
    while (1) {
        printf("\n1. En-Queue(Rear)\n2. De-Queue Front \n3. De-Queue Rear\n4. Peek Front\n5. Peek Rear\n6. Is Empty(Checks Queue is Empty)\n7. Is Full(Checks Queue is Full)\n8. Exit\nEnter Your Choice:- ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            enQueue(dq);
            break;
        case 2:
            deQueue(dq, 1);
            break;
        case 3:
            deQueue(dq, 2);
            break;
        case 4:
            peek(dq, 1);
            break;
        case 5:
            peek(dq, 2);
            break;
        case 6:
            if (isEmpty(dq)) {
                printf("\n~~ Queue is Empty! ~~\n");
            } else {
                printf("\n~~ Queue is Not Empty! ~~\n");
            }
            break;
        case 7:
            if (isFull(dq)) {
                printf("\n~~ Queue is Full! ~~\n");
            } else {
                printf("\n~~ Queue is Not Full! ~~\n");
            }
            break;
        case 8:
            printf("\n~~ Thanks For Using! Have a Great Day! ~~\n");
            return 0;
        default:
            printf("Please Enter a Vaild Input!\n");
            break;
        }
    }
    return 0;
}