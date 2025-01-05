#include <stdio.h>

int stack[10], stackPointer = -1, stackSize = 10;

void push() {
    if (stackPointer + 1 == stackSize) {
        printf("\n~~ Stack is Full~~\n");
        return;
    }

    int val;
    printf("\nEnter Value:- ");
    scanf("%d", &val);
    stackPointer++;
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
}

int main() {
    int choice;
    printf("Hello! Here You Can Perform Following Stack Operation!");
    while (1) {
        printf("\n1. Push(Insert)\n2. Pop(Delete)\n3. Peek(See Last Element)\n4. Is Empty(Checks weather Stack is Empty)\n5. Is Full(Checks weather Stack is Full)\n6. Exit\nEnter Your Choice:- ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            printf("\nTop Element:- %d\n", stack[stackPointer]);
            break;
        case 4:
            if (stackPointer == -1) {
                printf("\n~~ Stack is Empty~~\n");
            } else {
                printf("\n~~ Stack is Not Empty~~\n");
            }
            break;
        case 5:
            if (stackPointer + 1 == stackSize) {
                printf("\n~~ Stack is Full~~\n");
            } else {
                printf("\n~~ Stack is Not Full~~\n");
            }
            break;
        case 6:
            printf("\n~~Thanks For Using! Have a Great Day!~~\n");
            return 0;
        default:
            printf("\n~~Please Enter a Vaild Input!~~\n");
            break;
        }
    }
    return 0;
}