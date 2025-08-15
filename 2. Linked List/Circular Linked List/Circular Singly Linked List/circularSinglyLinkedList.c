#include <stdio.h>
#include <stdlib.h>

// Defines the structure for a circular singly linked list node.
// It contains the data and a pointer to the next node in the circle.
struct node {  
    int data;   
    struct node *next;  
};  

// Global pointers for the head (first node) and last (last node) of the list.
// 'last' is needed to efficiently add to the end and maintain the circular link.
struct node *head = NULL, *last = NULL;
// Global variable to keep track of the list's length.
int listLength = 0;

/**
 * @brief Allocates memory for a new node.
 * @return A pointer to the newly created node.
 */
struct node * createLinkedListNode() {
    // Allocate memory for the new node.
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        exit(1); // Exit if memory allocation fails.
    }
    listLength++; // Increment the total length of the list.
    return temp;
}

/**
 * @brief Prints all the elements of the circular linked list.
 */
void print() { // Show Data
    if (listLength == 0) {
        printf("\n~~ Linked List is Empty! ~~\n");
        return;
    }
    struct node *current = head;
    printf("\nLinked List: ");
    // Use a do-while loop to ensure the first node is printed even if it's the only one.
    // The loop continues as long as we haven't circled back to the head.
    do{
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    // Indicate the circular nature by showing the head's data again.
    printf("%d(Head)\n", head->data);
}

/**
 * @brief Inserts a new node with a given value at a specific position.
 * @param val The integer value for the new node.
 * @param pos The position (1-based) for insertion.
 */
void insert(int val, int pos) { // Insert
    // Validate the insertion position.
    if (pos <= 0 || pos > listLength + 1) {
        printf("\n~~Invalid Position: %d~~\n", pos);
        return;
    }

    struct node *newNode = createLinkedListNode();
    newNode->data = val;

    // Case 1: Insert at the beginning. This also covers insertion into an empty list.
    if (pos == 1) {
        newNode->next = head; // New node points to the old head.
        head = newNode;       // New node becomes the new head.

        // If this is the first node ever, it points to itself.
        if (last == NULL) {
            last = head;
        }
        // Crucially, the last node must now point to the new head to maintain the circle.
        last->next = head;
    } else {
    // Case 2: Insert in the middle or at the end.
        struct node *prev = head;
        // Traverse to the node just before the insertion point.
        for (int i = 1; i < pos - 1; i++) {
            prev = prev->next;
        }
        newNode->next = prev->next; // New node inherits the next link from the previous node.
        prev->next = newNode;       // Previous node now points to the new node.

        // If we inserted after the old last node, the new node becomes the new last.
        if (prev == last) {
            last = newNode;
        }
    }
    printf("Insertion Successful at Position %d. Value: %d\n", pos, val);
}

/**
 * @brief Deletes a node from a specific position.
 * @param pos The position (1-based) of the node to delete.
 */
void delete(int pos) { // Remove 
    // Validate the deletion position.
    if (pos <= 0 || pos > listLength) {
        printf("\n~~Invalid Position: %d~~\n", pos);
        return;
    }

    int deletedValue;
    struct node *temp = head;

    // Case 1: Delete the head node.
    if(pos == 1){
        deletedValue = temp->data;
        // If it's the only node, reset the list.
        if (head == last) {
            head = NULL;
            last = NULL;
        } else {
            head = head->next; // The second node becomes the new head.
            last->next = head; // The last node must point to the new head.
        }
        free(temp);
    } else {
    // Case 2: Delete from the middle or end.
        // Traverse to the node just before the one to be deleted.
        for (int i = 1; i < pos - 1; i++) {
            temp = temp->next;
        }
        
        struct node *deletedNode = temp->next;
        temp->next = deletedNode->next; // Bypass the deleted node.
        deletedValue = deletedNode->data;

        // If the deleted node was the last one, update the 'last' pointer.
        if (deletedNode == last) {
            last = temp;
        }
        
        free(deletedNode);
    }

    listLength--; // Decrement the list length.
    printf("Removed Value: %d\n", deletedValue);
}

/**
 * @brief The main function that drives the program.
 */
int main() {
    int choice;

    printf("Hello! Here You Can Perform Following Circular Linked List Operations!\n");
    // Main menu loop.
    while (1) {
        printf("\n1. Show Data\n2. Insert at First\n3. Insert at Last\n4. Insert at Specific Position\n");
        printf("5. Remove from First\n6. Remove from Last\n7. Remove from Specific Position\n");
        printf("8. Length of Data\n9. Exit\nEnter Your Choice: ");
        scanf("%d", &choice);

        int val, pos;
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
            // Note: A complete program should free all nodes before exiting.
            printf("\n~~Thanks for using! Have a great day!~~\n");
            return 0;
        default:
            printf("\n~~Please Enter a Valid Input!~~\n");
        }
    }

    return 0;
}
