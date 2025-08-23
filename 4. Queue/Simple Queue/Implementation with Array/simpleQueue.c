#include <stdio.h>

// Global array to serve as the queue with a fixed size.
int queue[5];
// Global integer to point to the front of the queue. Initialized to 0.
int front = 0;
// Global integer to point to the rear of the queue. Initialized to -1 to indicate an empty queue.
int rear = -1;
// Global integer to store the maximum capacity of the queue.
int capacity = 5;

/**
 * @brief Adds an element to the rear of the queue (En-Queue).
 */
void enQueue() {
    // Check if the rear pointer has reached the end of the array.
    // This is the condition for a full queue in this simple linear implementation.
    if (rear == capacity - 1) {
        printf("\n~~ Queue is Full! ~~\n");
        return;
    }

    int val;
    printf("\nEnter Value:- ");
    scanf("%d", &val);

    // Move the rear pointer to the next available spot.
    rear++;
    // Add the new element at the rear of the queue.
    queue[rear] = val;

    printf("Insertion Successfull. Value:- %d\n", val);
}

/**
 * @brief Removes an element from the front of the queue (De-Queue).
 */
void deQueue() {
    // Check if the queue is empty. This condition is true when 'front' has moved past 'rear'.
    if (front > rear) {
        printf("\n~~ Queue is Empty! ~~\n");
        return;
    }

    // Announce the data being removed from the front.
    printf("\nData Removed:- %d\n", queue[front]);

    // "Remove" the element by simply advancing the front pointer.
    // The old data remains in the array but is now considered outside the queue.
    front++;

    // This is a special condition to reset the queue. If the array has been filled
    // and then completely emptied, this resets the pointers to their initial state,
    // allowing the array space to be reused from the beginning.
    if (front > rear) {
        rear = -1;
        front = 0;
        printf("\n~~ Queue has been emptied and reset ~~\n");
    }
}

/**
 * @brief The main function that drives the program.
 */
int main() {
    int choice;
    printf("Hello! Here You Can Perform Following Queue Operation!");
    
    // Infinite loop to keep the menu running until the user chooses to exit.
    while (1) {
        printf("\n1. En-Queue(Insert a Element at rear)\n2. De-Queue(Delete a Element at front)\n3. Peek(Show's Element in the Front)\n4. Is Empty(Checks Queue is Empty)\n5. Is Full(Checks Queue is Full)\n6. Exit\nEnter Your Choice:- ");
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
            // Check if the queue is empty.
            if (front > rear) {
                printf("\n~~ Queue is Empty! ~~\n");
            } else {
                // Display the element at the front without removing it.
                printf("\nFront Element:- %d\n", queue[front]);
            }
            break;
        case 4: // Is Empty
            if (front > rear) {
                printf("\n~~ Queue is Empty! ~~\n");
            } else {
                printf("\n~~ Queue is Not Empty! ~~\n");
            }
            break;
        case 5: // Is Full
            if (rear == capacity - 1) {
                printf("\n~~ Queue is Full! ~~\n");
            } else {
                printf("\n~~ Queue is Not Full! ~~\n");
            }
            break;
        case 6: // Exit
            printf("\n~~ Thanks For Using! Have a Great Day! ~~\n");
            return 0; // Exit the program successfully.
        default:
            printf("Please Enter a Vaild Input!\n");
            break;
        }
    }
    return 0;
}
