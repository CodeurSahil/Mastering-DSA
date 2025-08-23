#include <stdio.h>
#include <stdlib.h>

// Defines the structure for a node in the linked list.
// Each node stores an integer and a pointer to the next node.
struct queueNode {
    int data;
    struct queueNode *next;
};

// Global pointers for the front and rear of the queue.
// Both are NULL when the queue is empty.
struct queueNode *front = NULL, *rear = NULL;

/**
 * @brief Allocates memory for a new node and initializes it.
 * @param val The integer value to be stored in the new node.
 * @return A pointer to the newly created node.
 */
struct queueNode * createNode(int val){
    // Allocate memory space for one 'struct queueNode'.
    struct queueNode *newNode = (struct queueNode *)malloc(sizeof(struct queueNode));
    // If malloc fails, print an error and exit.
    if (newNode == NULL) {
        printf("\nMemory Allocation Failed");
        exit(1);
    }
    // Assign the given value to the node's data field.
    newNode->data = val;
    // Initialize the next pointer to NULL.
    newNode->next = NULL;
    return newNode;
}

/**
 * @brief Adds an element to the rear of the queue (En-Queue).
 */
void enQueue() {
    int val;
    printf("\nEnter Value:- ");
    scanf("%d", &val);

    // Create a new node with the entered value.
    struct queueNode *newNode = createNode(val);

    // Case 1: If the queue is empty, the new node is both the front and the rear.
    if (front == NULL) {
        front = newNode;
        rear = newNode;
    } 
    // Case 2: If the queue is not empty, add the new node after the current rear.
    else {
        rear->next = newNode; // Link the old rear to the new node.
        rear = newNode;       // The new node becomes the new rear.
    }

    printf("Insertion Successfull. Value:- %d\n", val);
}

/**
 * @brief Removes an element from the front of the queue (De-Queue).
 */
void deQueue() {
    // Check if the queue is empty.
    if (front == NULL) {
        printf("\n~~ Queue is Empty! ~~\n");
        return;
    }

    // Create a temporary pointer to the node that is about to be deleted.
    struct queueNode *toBeDeletedNode = front;

    // "Remove" the element by advancing the front pointer to the next node.
    front = front->next;

    // Special case: If 'front' becomes NULL, it means the queue is now empty.
    // We must also update 'rear' to be NULL.
    if (front == NULL) {
        rear = NULL;
    }
    
    // Announce the data being removed.
    printf("\nData Removed:- %d\n", toBeDeletedNode->data);
    // Free the memory of the old front node.
    free(toBeDeletedNode);
}

/**
 * @brief The main function that drives the program.
 */
int main() {
    int choice;
    printf("Hello! Here You Can Perform Following Queue Operation!");
    
    // Infinite loop to keep the menu running.
    while (1) {
        printf("\n1. En-Queue(Insert)\n2. De-Queue(Delete)\n3. Peek(Show Front)\n4. Is Empty\n5. Exit\nEnter Your Choice:- ");
        scanf("%d", &choice);

        // Switch statement to handle the user's choice.
        switch (choice) {
        case 1: // En-Queue
            enQueue();
            break;
        case 2: // De-Queue
            deQueue();
            break;
        case 3: // Peek
            if (front == NULL) {
                printf("\n~~ Queue is Empty! ~~\n");
            } else {
                // Display the element at the front without removing it.
                printf("\nFront Element:- %d\n", front->data);
            }
            break;
        case 4: // Is Empty
            if (front == NULL) {
                printf("\n~~ Queue is Empty! ~~\n");
            } else {
                printf("\n~~ Queue is Not Empty! ~~\n");
            }
            break;
        case 5: // Exit
            // Note: A complete program should free all remaining nodes before exiting.
            printf("\n~~ Thanks For Using! Have a Great Day! ~~\n");
            return 0; // Exit the program successfully.
        default:
            printf("Please Enter a Vaild Input!\n");
            break;
        }
    }
    return 0;
}
