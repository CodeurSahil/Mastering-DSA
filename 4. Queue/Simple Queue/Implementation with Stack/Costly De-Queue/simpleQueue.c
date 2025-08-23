#include <stdio.h>
#include <stdlib.h>

// Define a constant for the maximum size of the stacks.
#define MAX 100

// Defines the structure for a stack using a static array.
struct stack {
    int top;
    int data[MAX];
};

// Defines the structure for a queue, which is composed of two stacks.
struct queue {
    struct stack *primaryStack;   // Stack for enQueue operations (s1).
    struct stack *secondaryStack; // Stack for deQueue operations (s2).
};

// Global pointer to our queue structure.
struct queue *Queue = NULL;

/**
 * @brief Initializes the queue and its underlying stacks.
 */
void initQueue() {
    // Allocate memory for the queue structure itself.
    Queue = (struct queue *)malloc(sizeof(struct queue));

    // Allocate memory for the two stacks within the queue structure.
    Queue->primaryStack = (struct stack *)malloc(sizeof(struct stack));
    Queue->secondaryStack = (struct stack *)malloc(sizeof(struct stack));

    // Initialize the 'top' of both stacks to -1, indicating they are empty.
    Queue->primaryStack->top = -1;
    Queue->secondaryStack->top = -1;
}

/**
 * @brief A standard push operation for a stack.
 * @param source The stack to push the value onto.
 * @param val The integer value to be pushed.
 */
void push(struct stack *source, int val) {
    // Increment 'top' and then add the value at that new position.
    source->data[++source->top] = val;
}

/**
 * @brief A standard pop operation for a stack.
 * @param source The stack to pop the value from.
 * @return The integer value popped from the top of the stack.
 */
int pop(struct stack *source) {
    // Return the value at the current 'top' and then decrement 'top'.
    return source->data[source->top--];
}

/**
 * @brief Adds an element to the queue (En-Queue).
 * This implementation makes the enQueue operation efficient (O(1)).
 */
void enQueue() {
    // Check if both stacks combined are full. This is a simplification.
    // A more robust check would consider the total number of elements.
    if (Queue->primaryStack->top + Queue->secondaryStack->top >= MAX - 2) {
        printf("\n~~ Queue is potentially Full! ~~\n");
        return;
    }

    int val;
    printf("\nEnter Value:- ");
    scanf("%d", &val);

    // Simply push the new element onto the primary stack.
    push(Queue->primaryStack, val);

    printf("Insertion Successfull. Value:- %d\n", val);
}

/**
 * @brief Removes an element from the queue (De-Queue).
 * This implementation makes the deQueue operation costly only when the secondary stack is empty.
 * The cost is amortized to O(1) over many operations.
 */
void deQueue() {
    // Step 1: If the secondary stack (for de-queuing) is empty...
    if (Queue->secondaryStack->top == -1) {
        // ...transfer all elements from the primary stack to the secondary stack.
        // This reverses the order, so the oldest element is now at the top of the secondary stack.
        while (Queue->primaryStack->top != -1) {
            push(Queue->secondaryStack, pop(Queue->primaryStack));
        }
    }

    // Step 2: Check if the secondary stack is still empty.
    // This means the entire queue was empty to begin with.
    if (Queue->secondaryStack->top == -1) {
        printf("\n~~ Queue is Empty! ~~\n");
        return;
    }

    // Step 3: Pop the top element from the secondary stack. This is the front of the queue.
    int removedVal = pop(Queue->secondaryStack);

    printf("\nData Removed:- %d\n", removedVal);
}

/**
 * @brief The main function that drives the program.
 */
int main() {
    int choice;
    // Initialize the queue before starting the menu.
    initQueue();
    printf("Hello! Here You Can Perform Following Queue Operation (using 2 Stacks)!");
    
    // Infinite loop to keep the menu running.
    while (1) {
        printf("\n1. En-Queue(Insert)\n2. De-Queue(Delete)\n3. Peek(Show Front)\n4. Is Empty\n5. Exit\nEnter Your Choice:- ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: // En-Queue
            enQueue();
            break;
        case 2: // De-Queue
            deQueue();
            break;
        case 3: // Peek
            // The front of the queue is the top of the secondary stack if it's not empty.
            if (Queue->secondaryStack->top != -1) {
                printf("\nFront Element:- %d\n", Queue->secondaryStack->data[Queue->secondaryStack->top]);
            } 
            // Otherwise, it's the bottom element of the primary stack.
            else if (Queue->primaryStack->top != -1) {
                printf("\nFront Element:- %d\n", Queue->primaryStack->data[0]);
            } else {
                printf("\n~~ Queue is Empty! ~~\n");
            }
            break;
        case 4: // Is Empty
            // The queue is empty only if both stacks are empty.
            if (Queue->primaryStack->top == -1 && Queue->secondaryStack->top == -1) {
                printf("\n~~ Queue is Empty! ~~\n");
            } else {
                printf("\n~~ Queue is Not Empty! ~~\n");
            }
            break;
        case 5: // Exit
            // Free the allocated memory for the stacks and the queue itself.
            free(Queue->primaryStack);
            free(Queue->secondaryStack);
            free(Queue);
            printf("\n~~ Thanks For Using! Have a Great Day! ~~\n");
            return 0; // Exit the program successfully.
        default:
            printf("Please Enter a Vaild Input!\n");
            break;
        }
    }
    return 0;
}
