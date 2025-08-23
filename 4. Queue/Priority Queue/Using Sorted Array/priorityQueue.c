#include <stdio.h>
#include <stdbool.h>
// Define a constant for the maximum size of the priority queue.
#define MAX_SIZE 5

// Defines the structure for a Priority Queue.
// It uses two parallel arrays: one for the data and one for the corresponding priorities.
// This implementation keeps the elements sorted by priority.
typedef struct {
    int data[MAX_SIZE];
    int priorities[MAX_SIZE];
    int size; // Current number of elements in the queue.
} PriorityQueue;

/**
 * @brief Initializes the priority queue by setting its size to 0.
 * @param pq A pointer to the PriorityQueue structure.
 */
void initializeQueue(PriorityQueue *pq) {
    pq->size = 0;
}

/**
 * @brief Checks if the priority queue is empty.
 * @param pq A pointer to the PriorityQueue structure.
 * @return True if the queue is empty, false otherwise.
 */
bool isEmpty(PriorityQueue *pq) {
    return pq->size == 0;
}

/**
 * @brief Adds an element to the queue, maintaining sorted order by priority.
 * Higher priority elements are placed closer to the front of the array.
 * @param pq A pointer to the PriorityQueue structure.
 */
void enQueue(PriorityQueue *pq) {
    // Check if the queue has reached its maximum capacity.
    if (pq->size == MAX_SIZE) {
        printf("\n~~ Queue is Full! ~~\n");
        return;
    }
    
    int val, priority, i;
    printf("\nEnter Value:- ");
    scanf("%d", &val);

    printf("Enter Priority:- ");
    scanf("%d", &priority);

    // Find the correct position for the new element.
    // Start from the end and shift existing elements to the right
    // as long as they have a lower priority than the new element.
    for (i = pq->size - 1; i >= 0 && pq->priorities[i] < priority; i--) {
        pq->data[i + 1] = pq->data[i];
        pq->priorities[i + 1] = pq->priorities[i];
    }

    // Insert the new element at its correct sorted position.
    pq->data[i + 1] = val;
    pq->priorities[i + 1] = priority;
    pq->size++; // Increment the size of the queue.

    printf("Insertion Successfull. Value:- %d\n", val);
}

/**
 * @brief Removes the element with the highest priority from the queue.
 * Since the queue is sorted, this is always the element at the front (index 0).
 * @param pq A pointer to the PriorityQueue structure.
 */
void deQueue(PriorityQueue *pq) {
    if (isEmpty(pq)) { //Checking if the Queue is Empty
        printf("\n~~ Queue is Empty! ~~\n");
        return;
    }

    // The highest priority element is at the beginning of the array.
    int value = pq->data[0];

    // Shift all subsequent elements one position to the left to fill the gap.
    for (int i = 0; i < pq->size - 1; i++) {
        pq->data[i] = pq->data[i + 1];
        pq->priorities[i] = pq->priorities[i + 1];
    }
    pq->size--; // Decrement the size of the queue.

    printf("\nData Removed:- %d (highest priority)\n", value);
}

/**
 * @brief Shows the element with the highest priority without removing it (Peek).
 * @param pq A pointer to the PriorityQueue structure.
 */
void peek(PriorityQueue *pq) {
    if (isEmpty(pq)) { //Checking if the Queue is Empty
        printf("\n~~ Queue is Empty! ~~\n");
        return;
    }

    // Since the queue is sorted by priority, the highest priority element is always at index 0.
    printf("\nHighest Priority Element:- %d\n", pq->data[0]);
}

/**
 * @brief The main function that drives the program.
 */
int main() {
    int choice;
    // Declare a PriorityQueue variable (not a pointer).
    PriorityQueue pq;
    // Pass its address to the initialization function.
    initializeQueue(&pq);
    
    printf("Hello! Here You Can Perform Following Priority Queue Operation!");
    while (1) {
        printf("\n1. En-Queue(Insert)\n2. De-Queue(Delete Highest Priority)\n3. Peek(Show Highest Priority)\n4. Is Empty\n5. Exit\nEnter Your Choice:- ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            enQueue(&pq);
            break;
        case 2:
            deQueue(&pq);
            break;
        case 3:
            peek(&pq);
            break;
        case 4:
            if (isEmpty(&pq)) {
                printf("\n~~ Queue is Empty! ~~\n");
            } else {
                printf("\n~~ Queue is Not Empty! ~~\n");
            }
            break;
        case 5:
            printf("\n~~ Thanks For Using! Have a Great Day! ~~\n");
            return 0; // Exit the program successfully.
        default:
            printf("Please Enter a Vaild Input!\n");
            break;
        }
    }
    return 0;
}
