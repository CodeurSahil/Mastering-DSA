#include <stdio.h>

int queue[5], front = -1, rear = -1, capacity = 5;

void enQueue() {
    if ((rear + 1) % capacity == front) { //Checking if the Queue is full
        printf("\n~~ Queue is Full! ~~\n");
        return;
    }

    if (front == -1) {
        front = 0;
    }

    int val;
    printf("\nEnter Value:- ");
    scanf("%d", &val);

    rear = (rear + 1) % capacity;

    queue[rear] = val;

    printf("Insertion Successfull. Value:- %d\n", val);
    return;
}

void deQueue() {
    if (front == -1) { //Checking if the Queue is Empty
        printf("\n~~ Queue is Empty! ~~\n");
        return;
    }

    printf("\nData Removed:- %d\n", queue[front]);

    if (front == rear) {
        rear = -1;
        front = -1;
    } else {
        front = (front + 1) % capacity;
    }
    return;
}

int main() {
    int choice;
    printf("Hello! Here You Can Perform Following Queue Operation!");
    while (1) {
        printf("\n1. En-Queue(Insert a Element at rear)\n2. De-Queue(Delete a Element at front)\n3. Peek(Show's Element in the Front)\n4. Is Empty(Checks Queue is Empty)\n5. Is Full(Checks Queue is Full)\n6. Exit\nEnter Your Choice:- ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            enQueue();
            break;
        case 2:
            deQueue();
            break;
        case 3:
            if (front == -1) {
                printf("\n~~ Queue is Empty! ~~\n");
                break;
            }
            printf("\nData:- %d\n", queue[front]);
            break;
        case 4:
            if (front == -1) {
                printf("\n~~ Queue is Empty! ~~\n");
            } else {
                printf("\n~~ Queue is Not Empty! ~~\n");
            }
            break;
        case 5:
            if ((rear + 1) % capacity == front) {
                printf("\n~~ Queue is Full! ~~\n");
            } else {
                printf("\n~~ Queue is Not Full! ~~\n");
            }
            break;
        case 6:
            printf("\n~~ Thanks For Using! Have a Great Day! ~~\n");
            return 0;
        default:
            printf("Please Enter a Vaild Input!\n");
            break;
        }
    }
    return 0;
}