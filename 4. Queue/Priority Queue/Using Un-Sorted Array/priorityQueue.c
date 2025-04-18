#include <stdio.h>
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

int findHighestPriority(PriorityQueue *pq) {
    int highestPriorityIndex = 0;
    for (int i = 1; i < pq->size; i++) {
        if (pq->priorities[i] > pq->priorities[highestPriorityIndex]) {
            highestPriorityIndex = i;
        }
    }
    return highestPriorityIndex;
}

void enQueue(PriorityQueue *pq) {
    if (pq->size == MAX_SIZE) {
        printf("\n~~ Queue is Full! ~~\n");
        return;
    }
    
    int val, priority;
    printf("\nEnter Value:- ");
    scanf("%d", &val);

    printf("Enter Priority:- ");
    scanf("%d", &priority);

    pq->data[pq->size] = val;
    pq->priorities[pq->size] = priority;
    pq->size++;

    printf("Insertion Successfull. Value:- %d\n", val);
    return;
}

void deQueue(PriorityQueue *pq) {
    if (isEmpty(pq)) { //Checking if the Queue is Empty
        printf("\n~~ Queue is Empty! ~~\n");
        return;
    }

    int highestPriorityIndex = findHighestPriority(pq);
    int value = pq->data[highestPriorityIndex];

    for (int i = highestPriorityIndex; i < pq->size - 1; i++) {
        pq->data[i] = pq->data[i + 1];
        pq->priorities[i] = pq->priorities[i + 1];
    }
    pq->size--;

    printf("\nData Removed:- %d\n", value);
    return;
}

void peek(PriorityQueue *pq) {
    if (isEmpty(pq)) { //Checking if the Queue is Empty
        printf("\n~~ Queue is Empty! ~~\n");
        return;
    }

    int highestPriorityIndex = findHighestPriority(pq);

    printf("\nData Element:- %d\n", pq -> data[highestPriorityIndex]);
    return;
}

int main() {
    int choice;
    PriorityQueue *pq;
    initializeQueue(pq);
    printf("Hello! Here You Can Perform Following Queue Operation!");
    while (1) {
        printf("\n1. En-Queue(Insert a Element at rear)\n2. De-Queue(Delete a Element at front)\n3. Peek(Show's Element in the Front)\n4. Is Empty(Checks Queue is Empty)\n5. Exit\nEnter Your Choice:- ");
        scanf("%d", &choice);

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
                printf("\n~~ Queue is Empty! ~~\n");
            } else {
                printf("\n~~ Queue is Not Empty! ~~\n");
            }
            break;
        case 5:
            printf("\n~~ Thanks For Using! Have a Great Day! ~~\n");
            return 0;
        default:
            printf("Please Enter a Vaild Input!\n");
            break;
        }
    }
    return 0;
}