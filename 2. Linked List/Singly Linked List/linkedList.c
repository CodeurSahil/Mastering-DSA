#include <stdio.h>
#include <stdlib.h>

// Defines the structure of a single node in the linked list.
// Each node contains an integer 'data' and a pointer 'next' to the subsequent node.
struct node {  
    int data;   
    struct node *next;  
};  

// Global pointer to the first node (head) of the linked list. Initialized to NULL for an empty list.
struct node *head = NULL;
// Global variable to keep track of the number of nodes in the list.
int listLength = 0;

/**
 * @brief Allocates memory for a new node.
 * @return A pointer to the newly allocated node.
 */
struct node* createLinkedListNode() {
    // Allocate memory space for one 'struct node'.
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    // If malloc fails, it returns NULL. Handle this by printing an error and exiting.
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        exit(1); // Exit the program on allocation failure.
    }
    // Increment the length of the list since a new node is being created.
    listLength++;
    return temp;
}

/**
 * @brief Prints all the elements of the linked list.
 */
void print() { // Show Data
    if (listLength == 0) {
        printf("\n~~ Linked List is Empty! ~~\n");
        return;
    }
    // Start from the head of the list.
    struct node *current = head;
    printf("\nLinked List: ");
    // Traverse the list until the end (NULL) is reached.
    while (current != NULL) {
        printf("%d -> ", current->data);
        // Move to the next node.
        current = current->next;
    }
    printf("NULL\n");
}

/**
 * @brief Inserts a new node with a given value at a specific position.
 * @param val The integer value to be stored in the new node.
 * @param pos The position (1-based) where the new node should be inserted.
 */
void insert(int val, int pos) { // Insert
    // Validate the position. It must be between 1 and listLength + 1.
    if (pos <= 0 || pos > listLength + 1) {
        printf("\n~~Invalid Position: %d~~\n", pos);
        return;
    }

    // Create a new node and set its data.
    struct node *newNode = createLinkedListNode();
    newNode->data = val;

    // Case 1: Insert at the beginning of the list.
    if (pos == 1) {
        newNode->next = head; // The new node points to the old head.
        head = newNode;       // The new node becomes the new head.
    } else {
    // Case 2: Insert at a middle or end position.
        struct node *prev = head;
        // Traverse to the node just before the target insertion position.
        for (int i = 1; i < pos - 1; i++) {
            prev = prev->next;
        }
        newNode->next = prev->next; // New node points to the node that was originally at the target position.
        prev->next = newNode;       // The previous node now points to the new node.
    }
    printf("Insertion Successful at Position %d. Value: %d\n", pos, val);
}

/**
 * @brief Deletes a node from a specific position.
 * @param pos The position (1-based) of the node to be deleted.
 */
void delete(int pos) { // Remove 
    // Validate the position. It must be within the current bounds of the list.
    if (pos <= 0 || pos > listLength) {
        printf("\n~~Invalid Position: %d~~\n", pos);
        return;
    }

    int deletedValue;
    struct node *temp = head, *deletedNode;

    // Case 1: Delete the head node.
    if(pos == 1){
        head = head->next; // The second node becomes the new head.
        deletedValue = temp->data;
        free(temp); // Free the memory of the old head.
    } else {
    // Case 2: Delete a node from the middle or end.
        // Traverse to the node just before the one to be deleted.
        for (int i = 1; i < pos - 1; i++) {
            temp = temp->next;
        }
        
        deletedNode = temp->next; // This is the node to be deleted.
        temp->next = deletedNode->next; // Link the previous node to the one after the deleted node.
        deletedValue = deletedNode->data;
        free(deletedNode); // Free the memory of the deleted node.
    }

    listLength--; // Decrement the list length.
    printf("Removed Value: %d\n", deletedValue);
}

/**
 * @brief The main function that drives the program.
 */
int main() {
    int choice;

    printf("Hello! Here You Can Perform Following Linked List Operations!\n");
    // Infinite loop to keep the menu running until the user chooses to exit.
    while (1) {
        printf("\n1. Show Data\n2. Insert at First\n3. Insert at Last\n4. Insert at Specific Position\n");
        printf("5. Remove from First\n6. Remove from Last\n7. Remove from Specific Position\n");
        printf("8. Length of Data\n9. Exit\nEnter Your Choice: ");
        scanf("%d", &choice);

        int val, pos;
        // Switch statement to handle the user's choice.
        switch (choice) {
        case 1:
            print();
            break;
        case 2: // Insert at First
            printf("\nEnter Value: ");
            scanf("%d", &val);
            insert(val, 1);
            break;
        case 3: // Insert at Last
            printf("\nEnter Value: ");
            scanf("%d", &val);
            insert(val, listLength + 1);
            break;
        case 4: // Insert at Specific Position
            printf("\nEnter Value: ");
            scanf("%d", &val);
            printf("Enter Position: ");
            scanf("%d", &pos);
            insert(val, pos);
            break;
        case 5: // Remove from First
            if (listLength == 0) {
                printf("\n~~ Linked List is Empty! Cannot Remove ~~\n");
            } else {
                delete(1);
            }
            break;
        case 6: // Remove from Last
            if (listLength == 0) {
                printf("\n~~ Linked List is Empty! Cannot Remove ~~\n");
            } else {
                delete(listLength);
            }
            break;
        case 7: // Remove from Specific Position
            if (listLength == 0) {
                printf("\n~~ Linked List is Empty! Cannot Remove ~~\n");
            } else {
                printf("\nEnter Position: ");
                scanf("%d", &pos);
                delete(pos);
            }
            break;
        case 8: // Length of Data
            printf("\nData Length: %d\n", listLength);
            break;
        case 9: // Exit
            // Note: A complete program should free all nodes in the list before exiting
            // to prevent memory leaks. This is omitted for simplicity in this example.
            printf("\n~~Thanks for using! Have a great day!~~\n");
            return 0;
        default:
            printf("\n~~Please Enter a Valid Input!~~\n");
        }
    }

    return 0;
}
