#include <stdio.h>

// Global array to serve as the stack with a fixed size of 10.
int stack[10];
// Global integer to keep track of the top of the stack. -1 indicates an empty stack.
int stackPointer = -1;
// Global integer to store the maximum size of the stack.
int stackSize = 10;

/**
 * @brief Pushes a new element onto the top of the stack if it's not full.
 */
void push() {
    // Check for "stack overflow" condition. If the next position is equal to the size, the stack is full.
    if (stackPointer + 1 == stackSize) {
        printf("\n~~ Stack is Full~~\n");
        return;
    }

    int val;
    printf("\nEnter Value:- ");
    scanf("%d", &val);
    
    // Increment the pointer to the new top position.
    stackPointer++;
    // Place the new value at the top of the stack.
    stack[stackPointer] = val;
    printf("Insertion Successfull. Value:- %d\n", val);
}

/**
 * @brief Pops (removes) the top element from the stack if it's not empty.
 */
void pop() {
    // Check for "stack underflow" condition. If the pointer is -1, the stack is empty.
    if (stackPointer == -1) {
        printf("\n~~ Stack is Empty~~\n");
        return;
    }

    // Announce the value being removed from the top.
    printf("\nRemoved Value: %d\n", stack[stackPointer]);
    // Decrement the pointer. The value is not actually erased, but it is no longer accessible.
    stackPointer--;
}

/**
 * @brief The main function that drives the program.
 */
int main() {
    int choice;
    printf("Hello! Here You Can Perform Following Stack Operation!");
    
    // Infinite loop to keep the menu running until the user chooses to exit.
    while (1) {
        printf("\n1. Push(Insert)\n2. Pop(Delete)\n3. Peek(See Last Element)\n4. Is Empty(Checks weather Stack is Empty)\n5. Is Full(Checks weather Stack is Full)\n6. Exit\nEnter Your Choice:- ");
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
        case 5: // IsFull check
            if (stackPointer + 1 == stackSize) {
                printf("\n~~ Stack is Full~~\n");
            } else {
                printf("\n~~ Stack is Not Full~~\n");
            }
            break;
        case 6: // Exit
            printf("\n~~Thanks For Using! Have a Great Day!~~\n");
            return 0; // Exit the program successfully.
        default:
            printf("\n~~Please Enter a Vaild Input!~~\n");
            break;
        }
    }
    return 0;
}
