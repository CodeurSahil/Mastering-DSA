#include <stdio.h>
#include <stdbool.h> // For using boolean types (true/false)

// Define a constant for the maximum size of the priority queue.
#define MAX_SIZE 5

// Defines the structure for a Priority Queue.
// It uses two parallel arrays: one for the data and one for the corresponding priorities.
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
 * @brief Finds the index of the element with the highest priority.
 * In this implementation, a higher integer value means higher priority.
 * @param pq A pointer to the PriorityQueue structure.
 * @return The index of the element with the highest priority.
 */
int findHighestPriority(PriorityQueue *pq) {
    int highestPriorityIndex = 0;
    // Iterate through the queue starting from the second element.
    for (int i = 1; i < pq->size; i++) {
        // If the current element's priority is greater than the highest found so far...
        if (pq->priorities[i] > pq->priorities[highestPriorityIndex]) {
            // ...update the index of the highest priority element.
            highestPriorityIndex = i;
        }
    }
    return highestPriorityIndex;
}

/**
 * @brief Adds an element and its priority to the queue (En-Queue).
 * Note: This implementation adds the new element to the end, regardless of priority.
 * The priority is only considered during de-queue.
 * @param pq A pointer to the PriorityQueue structure.
 */
void enQueue(PriorityQueue *pq) {
    // Check if the queue has reached its maximum capacity.
    if (pq->size == MAX_SIZE) {
        printf("\n~~ Queue is Full! ~~\n");
        return;
    }
    
    int val, priority;
    printf("\nEnter Value:- ");
    scanf("%d", &val);

    printf("Enter Priority:- ");
    scanf("%d", &priority);

    // Add the new data and its priority to the end of their respective arrays.
    pq->data[pq->size] = val;
    pq->priorities[pq->size] = priority;
    // Increment the size of the queue.
    pq->size++;

    printf("Insertion Successfull. Value:- %d\n", val);
}

/**
 * @brief Removes the element with the highest priority from the queue (De-Queue).
 * @param pq A pointer to the PriorityQueue structure.
 */
void deQueue(PriorityQueue *pq) {
    // Check if the queue is empty.
    if (isEmpty(pq)) {
        printf("\n~~ Queue is Empty! ~~\n");
        return;
    }

    // Find the location of the highest priority element.
    int highestPriorityIndex = findHighestPriority(pq);
    int value = pq->data[highestPriorityIndex];

    // Shift all elements after the removed element one position to the left.
    for (int i = highestPriorityIndex; i < pq->size - 1; i++) {
        pq->data[i] = pq->data[i + 1];
        pq->priorities[i] = pq->priorities[i + 1];
    }
    // Decrement the size of the queue.
    pq->size--;

    printf("\nData Removed:- %d (with highest priority)\n", value);
}

/**
 * @brief Shows the element with the highest priority without removing it (Peek).
 * @param pq A pointer to the PriorityQueue structure.
 */
void peek(PriorityQueue *pq) {
    if (isEmpty(pq)) {
        printf("\n~~ Queue is Empty! ~~\n");
        return;
    }

    // Find the location of the highest priority element.
    int highestPriorityIndex = findHighestPriority(pq);

    // Print the data of the highest priority element.
    printf("\nHighest Priority Element:- %d\n", pq->data[highestPriorityIndex]);
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
