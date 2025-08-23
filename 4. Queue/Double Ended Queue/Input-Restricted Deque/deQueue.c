#include <stdio.h>
#include <stdbool.h> // For using boolean types (true/false)

// Define a constant for the maximum size of the DEQueue.
#define MAX_SIZE 5

// Defines the structure for an Input-Restricted Double-Ended Queue.
// Insertion is restricted to the rear, but deletion is allowed at both ends.
typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} DEQueue;

/**
 * @brief Initializes the DEQueue by setting front and rear to -1.
 * @param dq A pointer to the DEQueue structure.
 */
void initializeQueue(DEQueue *dq) {
    dq->front = -1;
    dq->rear = -1;
}

/**
 * @brief Checks if the DEQueue is empty.
 * @param dq A pointer to the DEQueue structure.
 * @return True if the queue is empty, false otherwise.
 */
bool isEmpty(DEQueue *dq) {
    return dq->front == -1;
}

/**
 * @brief Checks if the DEQueue is full.
 * @param dq A pointer to the DEQueue structure.
 * @return True if the queue is full, false otherwise.
 */
bool isFull(DEQueue *dq) {
    // The queue is full in two scenarios in a circular array:
    // 1. Front is at the beginning (0) and rear is at the end.
    // 2. Rear is just behind the front (circularly).
    return (dq->front == 0 && dq->rear == MAX_SIZE - 1) || (dq->front == dq->rear + 1);
}

/**
 * @brief Adds an element to the rear of the DEQueue.
 * @param dq A pointer to the DEQueue structure.
 */
void enQueue(DEQueue *dq) {
    if (isFull(dq)) {
        printf("\n~~ Queue is Full! ~~\n");
        return;
    }

    int val;
    printf("\nEnter Value:- ");
    scanf("%d", &val);

    // If this is the first element, initialize both front and rear to 0.
    if (isEmpty(dq)) {
        dq->front = 0;
        dq->rear = 0;
    } else {
        // Move the rear pointer forward, wrapping around if necessary.
        if (dq->rear == MAX_SIZE - 1) {
            dq->rear = 0;
        } else {
            dq->rear++;
        }
    }

    // Place the new value at the rear.
    dq->data[dq->rear] = val;

    printf("Insertion Successfull. Value:- %d\n", val);
}

/**
 * @brief Removes an element from either the front or the rear of the DEQueue.
 * @param dq A pointer to the DEQueue structure.
 * @param type 1 to remove from the front, 2 to remove from the rear.
 */
void deQueue(DEQueue *dq, int type) {
    if (isEmpty(dq)) {
        printf("\n~~ Queue is Empty! ~~\n");
        return;
    }

    int toBeDeletedValue;

    // If this is the last element in the queue.
    if (dq->front == dq->rear) {
        toBeDeletedValue = dq->data[dq->front];
        initializeQueue(dq); // Reset the queue to empty.
    } 
    // Remove from the front (type 1).
    else if (type == 1) {
        toBeDeletedValue = dq->data[dq->front];
        // If front is at the end, wrap around to the beginning.
        if (dq->front == MAX_SIZE - 1) {
            dq->front = 0;
        } else {
            // Otherwise, just increment front.
            dq->front++;
        }
    } 
    // Remove from the rear (type 2).
    else if (type == 2) {
        toBeDeletedValue = dq->data[dq->rear];
        // If rear is at the beginning, wrap around to the end.
        if (dq->rear == 0) {
            dq->rear = MAX_SIZE - 1;
        } else {
            // Otherwise, just decrement rear.
            dq->rear--;
        }
    }

    printf("\nData Removed:- %d\n", toBeDeletedValue);
}

/**
 * @brief Shows the element at the front or rear without removing it.
 * @param dq A pointer to the DEQueue structure.
 * @param type 1 for the front element, 2 for the rear element.
 */
void peek(DEQueue *dq, int type) {
    if (isEmpty(dq)) {
        printf("\n~~ Queue is Empty! ~~\n");
        return;
    }

    int peekVal;
    if (type == 1) {
        peekVal = dq->data[dq->front];
        printf("\nFront Element:- %d\n", peekVal);
    } else if (type == 2) {
        peekVal = dq->data[dq->rear];
        printf("\nRear Element:- %d\n", peekVal);
    }
}

/**
 * @brief The main function that drives the program.
 */
int main() {
    int choice;
    // Declare a DEQueue variable (not a pointer).
    DEQueue dq;
    // Pass its address to the functions.
    initializeQueue(&dq);
    printf("Hello! Here You Can Perform Following Input-Restricted DEQueue Operation!");
    while (1) {
        printf("\n1. En-Queue(Rear)\n2. De-Queue Front\n3. De-Queue Rear\n4. Peek Front\n5. Peek Rear\n6. Is Empty\n7. Is Full\n8. Exit\nEnter Your Choice:- ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            enQueue(&dq);
            break;
        case 2:
            deQueue(&dq, 1);
            break;
        case 3:
            deQueue(&dq, 2);
            break;
        case 4:
            peek(&dq, 1);
            break;
        case 5:
            peek(&dq, 2);
            break;
        case 6:
            if (isEmpty(&dq)) {
                printf("\n~~ Queue is Empty! ~~\n");
            } else {
                printf("\n~~ Queue is Not Empty! ~~\n");
            }
            break;
        case 7:
            if (isFull(&dq)) {
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
