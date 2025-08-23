#include <stdio.h>

// Global array to serve as the circular queue.
int queue[5];
// Pointers for front and rear. Both are -1 when the queue is initially empty.
int front = -1, rear = -1;
// Global integer to store the maximum capacity of the queue.
int capacity = 5;

/**
 * @brief Adds an element to the rear of the circular queue (En-Queue).
 */
void enQueue() {
    // Check if the queue is full. This happens when the position after 'rear' is 'front'.
    // The modulo operator (%) ensures the wrap-around check.
    if ((rear + 1) % capacity == front) {
        printf("\n~~ Queue is Full! ~~\n");
        return;
    }

    // If this is the first element being inserted, initialize 'front' to 0.
    if (front == -1) {
        front = 0;
    }

    int val;
    printf("\nEnter Value:- ");
    scanf("%d", &val);

    // Increment 'rear' in a circular manner. When it reaches the end, it wraps back to 0.
    rear = (rear + 1) % capacity;
    // Add the new element at the new rear position.
    queue[rear] = val;

    printf("Insertion Successfull. Value:- %d\n", val);
}

/**
 * @brief Removes an element from the front of the circular queue (De-Queue).
 */
void deQueue() {
    // Check if the queue is empty.
    if (front == -1) {
        printf("\n~~ Queue is Empty! ~~\n");
        return;
    }

    // Announce the data being removed from the front.
    printf("\nData Removed:- %d\n", queue[front]);

    // Check if this is the last element in the queue.
    if (front == rear) {
        // If so, reset the queue to its initial empty state.
        rear = -1;
        front = -1;
    } else {
        // Otherwise, increment 'front' in a circular manner to "remove" the element.
        front = (front + 1) % capacity;
    }
}

/**
 * @brief The main function that drives the program.
 */
int main() {
    int choice;
    printf("Hello! Here You Can Perform Following Circular Queue Operation!");
    
    // Infinite loop to keep the menu running.
    while (1) {
        printf("\n1. En-Queue(Insert)\n2. De-Queue(Delete)\n3. Peek(Show Front)\n4. Is Empty\n5. Is Full\n6. Exit\nEnter Your Choice:- ");
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
            // Check for an empty queue.
            if (front == -1) {
                printf("\n~~ Queue is Empty! ~~\n");
            } else {
                // Display the element at the front without removing it.
                printf("\nFront Element:- %d\n", queue[front]);
            }
            break;
        case 4: // Is Empty
            if (front == -1) {
                printf("\n~~ Queue is Empty! ~~\n");
            } else {
                printf("\n~~ Queue is Not Empty! ~~\n");
            }
            break;
        case 5: // Is Full
            if ((rear + 1) % capacity == front) {
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
