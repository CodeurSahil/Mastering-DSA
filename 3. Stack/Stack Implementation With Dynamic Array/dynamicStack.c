#include <stdio.h>
#include <stdlib.h>

int *stack = NULL, stackPointer = -1;

void handleStackSize(int len) {
    if (len > 0) {
        stack = (int *)realloc(stack, len * sizeof(int));
        if (stack == NULL) {
            printf("Memory allocation failed.\n");
            exit(1); // Exit the program on allocation failure
        }
    }
}

void push() {
    int val;
    printf("\nEnter Value:- ");
    scanf("%d", &val);
    stackPointer++;
    handleStackSize(stackPointer + 1);
    stack[stackPointer] = val;
    printf("Insertion Successfull. Value:- %d\n", val);
}

void pop() {
    if (stackPointer == -1) {
        printf("\n~~ Stack is Empty~~\n");
        return;
    }

    printf("\nRemoved Value: %d\n", stack[stackPointer]);
    stackPointer--;
    handleStackSize(stackPointer + 1);
}

int main() {
    int choice;
    printf("Hello! Here You Can Perform Following Stack Operation!");
    while (1) {
        printf("\n1. Push(Insert)\n2. Pop(Delete)\n3. Peek(See Last Element)\n4. Is Empty(Checks weather Stack is Empty)\n5. Exit\nEnter Your Choice:- ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            if (stackPointer == -1) {
                printf("\n~~ Stack is Empty~~\n");
            } else {
                printf("\nTop Element:- %d\n", stack[stackPointer]);
            }
            break;
        case 4:
            if (stackPointer == -1) {
                printf("\n~~ Stack is Empty~~\n");
            } else {
                printf("\n~~ Stack is Not Empty~~\n");
            }
            break;
        case 5:
            printf("\n~~Thanks For Using! Have a Great Day!~~\n");
            return 0;
        default:
            printf("\n~~Please Enter a Vaild Input!~~\n");
            break;
        }
    }
    return 0;
}