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
    struct stack *primaryStack;   // This stack will hold the queue elements.
    struct stack *secondaryStack; // This is a helper stack used during the enQueue operation.
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
 * This implementation makes the enQueue operation costly.
 */
void enQueue() {
    // Check for stack overflow in the primary stack.
    if (Queue->primaryStack->top == MAX - 1) {
        printf("\n~~ Queue is Full (Stack Overflow)! ~~\n");
        return;
    }

    // Step 1: Transfer all elements from the primary stack to the secondary stack.
    // This effectively reverses the order of elements.
    while (Queue->primaryStack->top != -1) {
        push(Queue->secondaryStack, pop(Queue->primaryStack));
    }

    // Step 2: Push the new element onto the now-empty primary stack.
    // It becomes the single element at the bottom.
    int val;
    printf("\nEnter Value:- ");
    scanf("%d", &val);
    push(Queue->primaryStack, val);

    // Step 3: Transfer all elements back from the secondary stack to the primary stack.
    // This reverses the order again, placing the old elements on top of the new one.
    // The new element is now at the bottom (rear of the queue), and the oldest is at the top (front).
    while (Queue->secondaryStack->top != -1) {
        push(Queue->primaryStack, pop(Queue->secondaryStack));
    }

    printf("Insertion Successfull. Value:- %d\n", val);
}

/**
 * @brief Removes an element from the queue (De-Queue).
 * This implementation makes the deQueue operation efficient (O(1)).
 */
void deQueue() {
    // Check if the queue is empty (i.e., the primary stack is empty).
    if (Queue->primaryStack->top == -1) {
        printf("\n~~ Queue is Empty! ~~\n");
        return;
    }

    // The element at the top of the primary stack is the front of the queue.
    // Popping it is equivalent to de-queuing.
    int removedVal = pop(Queue->primaryStack);

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
            if (Queue->primaryStack->top == -1) {
                printf("\n~~ Queue is Empty! ~~\n");
            } else {
                // The top of the primary stack is always the front of the queue.
                printf("\nFront Element:- %d\n", Queue->primaryStack->data[Queue->primaryStack->top]);
            }
            break;
        case 4: // Is Empty
            if (Queue->primaryStack->top == -1) {
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
