#include <stdio.h>
#include <stdlib.h>

// Defines the structure for a node in the linked list.
// Each node will store an integer and a pointer to the next node in the stack.
struct node {  
    int data;   
    struct node *next;  
}; 

// Global pointer 'top' which will always point to the topmost node of the stack.
// Initialized to NULL to indicate an empty stack.
struct node *top = NULL;

/**
 * @brief Allocates memory for a new node and initializes it.
 * @param val The integer value to be stored in the new node.
 * @return A pointer to the newly created node.
 */
struct node * createNode(int val) {
    // Allocate memory space for one 'struct node'.
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    // If malloc fails, print an error and exit.
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        exit(1); // Exit the program on allocation failure.
    }
    // Assign the given value to the node's data field.
    temp->data = val;
    // Initialize the next pointer to NULL.
    temp->next = NULL;
    return temp;
}

/**
 * @brief Pushes a new element onto the top of the stack.
 */
void push() {
    int val;
    printf("\nEnter Value:- ");
    scanf("%d", &val);
    
    // Create a new node with the entered value.
    struct node *newNode = createNode(val);
    // The new node's 'next' pointer should point to the current top of the stack.
    newNode->next = top;
    // The new node now becomes the top of the stack.
    top = newNode;
    printf("Insertion Successfull. Value:- %d\n", val);
}

/**
 * @brief Pops (removes) the top element from the stack.
 */
void pop() {
    // Check for "stack underflow" condition. If top is NULL, the stack is empty.
    if (top == NULL) {
        printf("\n~~ Stack is Empty~~\n");
        return;
    }

    // Create a temporary pointer to the node that is about to be deleted.
    struct node *toBeDeletedNode = top;
    printf("\nRemoved Value: %d\n", toBeDeletedNode->data);
    // Move the 'top' pointer to the next node in the stack.
    top = top->next;
    // Free the memory of the original top node.
    free(toBeDeletedNode);
}

/**
 * @brief Displays all the elements currently in the stack from top to bottom.
 */
void print() {
    if (top == NULL) {
        printf("\n~~ Stack is Empty~~\n");
        return;
    }
    // Start from the top of the stack.
    struct node *current = top;
    printf("\nStack Elements (Top to Bottom): ");
    // Traverse the linked list until the end is reached.
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

/**
 * @brief The main function that drives the program.
 */
int main() {
    int choice;
    printf("Hello! Here You Can Perform Following Stack Operation!");
    
    // Infinite loop to keep the menu running until the user chooses to exit.
    while (1) {
        printf("\n1. Push(Insert)\n2. Pop(Delete)\n3. Peek(See Last Element)\n4. Is Empty(Checks weather Stack is Empty)\n5. Display All Elements\n6. Exit\nEnter Your Choice:- ");
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
            if (top == NULL) {
                printf("\n~~ Stack is Empty~~\n");
            } else {
                // Display the data of the top node without removing it.
                printf("\nTop Element:- %d\n", top->data);
            }
            break;
        case 4: // IsEmpty check
            if (top == NULL) {
                printf("\n~~ Stack is Empty~~\n");
            } else {
                printf("\n~~ Stack is Not Empty~~\n");
            }
            break;
        case 5: // Display all elements
            print();
            break;
        case 6: // Exit
            // Note: A complete program should free all remaining nodes before exiting.
            printf("\n~~Thanks For Using! Have a Great Day!~~\n");
            return 0; // Exit the program successfully.
        default:
            printf("\n~~Please Enter a Vaild Input!~~\n");
            break;
        }
    }
    return 0;
}
