#include <stdio.h>
#include <stdlib.h>

struct node {  
    int data;   
    struct node *next;  
}; 

struct node *top = NULL;

struct node * createNode(int val) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        exit(1); // Exit the program on allocation failure
    }
    temp -> data = val;
    temp -> next = NULL;
    return temp;
}

void push() {
    int val;
    printf("\nEnter Value:- ");
    scanf("%d", &val);
    struct node *newNode;
    newNode = createNode(val);
    newNode -> next = top;
    top = newNode;
    printf("Insertion Successfull. Value:- %d\n", val);
}

void pop() {
    if (top == NULL) {
        printf("\n~~ Stack is Empty~~\n");
        return;
    }

    struct node *toBeDeletedNode = top;
    printf("\nRemoved Value: %d\n", toBeDeletedNode -> data);
    top = top -> next;
    free(toBeDeletedNode);
}

void print() {
    if (top == NULL) {
        printf("\n~~ Stack is Empty~~\n");
        return;
    }
    struct node *current = top;
    printf("\nStack Elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
    return;
}

int main() {
    int choice;
    printf("Hello! Here You Can Perform Following Stack Operation!");
    while (1) {
        printf("\n1. Push(Insert)\n2. Pop(Delete)\n3. Peek(See Last Element)\n4. Is Empty(Checks weather Stack is Empty)\n5. Display All Elements\n6. Exit\nEnter Your Choice:- ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            if (top == NULL) {
                printf("\n~~ Stack is Empty~~\n");
            } else {
                printf("\nTop Element:- %d\n", top -> data);
            }
            break;
        case 4:
            if (top == NULL) {
                printf("\n~~ Stack is Empty~~\n");
            } else {
                printf("\n~~ Stack is Not Empty~~\n");
            }
            break;
        case 5:
            print();
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