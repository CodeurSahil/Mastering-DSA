#include <stdio.h>
#include <stdlib.h>

// Global pointer for the dynamic array that will function as our stack.
int *stack = NULL;
// Global integer to keep track of the top of the stack. -1 indicates an empty stack.
int stackPointer = -1;

/**
 * @brief Manages the size of the stack's underlying dynamic array.
 * @param len The new desired number of elements for the stack array.
 */
void handleStackSize(int len) {
    // A length of 0 means the stack is empty, so we free the memory.
    if (len == 0) {
        free(stack);
        stack = NULL;
        return;
    }
    // Reallocate the memory for the stack to the new size.
    // realloc can handle the initial case where 'stack' is NULL.
    int *tempPtr = (int *)realloc(stack, len * sizeof(int));
    if (tempPtr == NULL) {
        printf("Memory allocation failed.\n");
        free(stack); // Free the original block if it exists.
        exit(1); // Exit the program on allocation failure.
    }
    stack = tempPtr; // Update the global pointer to the new memory block.
}

/**
 * @brief Pushes a new element onto the top of the stack.
 */
void push() {
    int val;
    printf("\nEnter Value:- ");
    scanf("%d", &val);
    
    // Increment the stack pointer to the new top position.
    stackPointer++;
    // Resize the array to accommodate the new element.
    handleStackSize(stackPointer + 1);
    // Place the new value at the top of the stack.
    stack[stackPointer] = val;
    printf("Insertion Successfull. Value:- %d\n", val);
}

/**
 * @brief Pops (removes) the top element from the stack.
 */
void pop() {
    // Check if the stack is empty before trying to pop.
    if (stackPointer == -1) {
        printf("\n~~ Stack is Empty~~\n");
        return;
    }

    // Announce the value being removed from the top.
    printf("\nRemoved Value: %d\n", stack[stackPointer]);
    // Decrement the stack pointer to remove the element.
    stackPointer--;
    // Resize the array to shrink its size, or free it if the stack is now empty.
    handleStackSize(stackPointer + 1);
}

/**
 * @brief The main function that drives the program.
 */
int main() {
    int choice;
    printf("Hello! Here You Can Perform Following Stack Operation!");
    
    // Infinite loop to keep the menu running until the user chooses to exit.
    while (1) {
        printf("\n1. Push(Insert)\n2. Pop(Delete)\n3. Peek(See Last Element)\n4. Is Empty(Checks weather Stack is Empty)\n5. Exit\nEnter Your Choice:- ");
        scanf("%d", &choice);

        // Switch statement to handle the user's choice.
        switch (choice) {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3: // Peek operation
            if (stackPointer == -1) {
                printf("\n~~ Stack is Empty~~\n");
            } else {
                // Display the element at the top of the stack without removing it.
                printf("\nTop Element:- %d\n", stack[stackPointer]);
            }
            break;
        case 4: // IsEmpty check
            if (stackPointer == -1) {
                printf("\n~~ Stack is Empty~~\n");
            } else {
                printf("\n~~ Stack is Not Empty~~\n");
            }
            break;
        case 5: // Exit
            free(stack); // Free any remaining allocated memory before exiting.
            stack = NULL;
            printf("\n~~Thanks For Using! Have a Great Day!~~\n");
            return 0; // Exit the program successfully.
        default:
            printf("\n~~Please Enter a Vaild Input!~~\n");
            break;
        }
    }
    return 0;
}
