#include <stdio.h>
#include <stdlib.h>

// Defines the structure for a circular doubly linked list node.
// It contains the data, a pointer to the next node, and a pointer to the previous node.
struct node {  
    int data;   
    struct node *next;  
    struct node *prev;  
};  

// Global pointers for the head (first node) and tail (last node) of the list.
struct node *head = NULL, *tail = NULL;
// Global variable to keep track of the list's length.
int listLength = 0;

/**
 * @brief Allocates memory for a new node and initializes its pointers.
 * @return A pointer to the newly created node.
 */
struct node * createLinkedListNode() {
    // Allocate memory for the new node.
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        exit(1); // Exit if memory allocation fails.
    }
    // Initialize both next and prev pointers to NULL for the new standalone node.
    temp->next = NULL;
    temp->prev = NULL;
    listLength++; // Increment the total length of the list.
    return temp;
}

/**
 * @brief Prints the linked list either in forward or reverse order.
 * @param reverse A flag to determine the print direction (0 for forward, 1 for reverse).
 */
void print(int reverse) { // Show Data
    if (listLength == 0) {
        printf("\n~~ Linked List is Empty! ~~\n");
        return;
    }

    // If reverse is true, print from tail to head using 'prev' pointers.
    if (reverse) {
        printf("\nLinked List(Reverse): ");
        struct node *current = tail;
        // Use a do-while loop to handle single-node lists correctly.
        do {
            printf("%d -> ", current->data);
            current = current->prev;
        } while (current != tail); // Loop until we circle back to the tail.
        printf("%d(TAIL)\n", tail->data);
    }
    // Otherwise, print from head to tail using 'next' pointers.
    else {
        printf("\nLinked List: ");
        struct node *current = head;
        do {
            printf("%d -> ", current->data);
            current = current->next;
        } while (current != head); // Loop until we circle back to the head.
        printf("%d(HEAD)\n", head->data);
    }
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

    // Case 1: Inserting into an empty list.
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        head->next = head; // Points to itself.
        head->prev = head; // Points to itself.
    }
    // Case 2: Inserting at the beginning of a non-empty list.
    else if (pos == 1) {
        newNode->next = head;       // New node's next points to old head.
        newNode->prev = tail;       // New node's prev points to tail.
        head->prev = newNode;       // Old head's prev points to new node.
        tail->next = newNode;       // Tail's next points to new node.
        head = newNode;             // New node becomes the new head.
    }
    // Case 3: Inserting at the end of a non-empty list.
    else if (pos == listLength) {
        newNode->next = head;       // New node's next points to head.
        newNode->prev = tail;       // New node's prev points to old tail.
        tail->next = newNode;       // Old tail's next points to new node.
        head->prev = newNode;       // Head's prev points to new node.
        tail = newNode;             // New node becomes the new tail.
    }
    // Case 4: Inserting in the middle.
    else {
        struct node *temp = head;
        // Traverse to the node just before the insertion point.
        for (int i = 1; i < pos - 1; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next; // New node's next points to the node after temp.
        newNode->prev = temp;       // New node's prev points to temp.
        temp->next->prev = newNode; // The node after temp now has its 'prev' point to the new node.
        temp->next = newNode;       // Temp's 'next' now points to the new node.
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
    struct node *temp;

    // Case 1: Deleting the only node in the list.
    if (listLength == 1) {
        temp = head;
        deletedValue = temp->data;
        head = NULL;
        tail = NULL;
        free(temp);
    }
    // Case 2: Deleting the head node from a multi-node list.
    else if (pos == 1) {
        temp = head;
        deletedValue = temp->data;
        head = head->next;    // Second node becomes the new head.
        head->prev = tail;    // New head's prev points to the tail.
        tail->next = head;    // Tail's next points to the new head.
        free(temp);
    }
    // Case 3: Deleting the tail node from a multi-node list.
    else if (pos == listLength) {
        temp = tail;
        deletedValue = temp->data;
        tail = tail->prev;    // Second-to-last node becomes the new tail.
        tail->next = head;    // New tail's next points to the head.
        head->prev = tail;    // Head's prev points to the new tail.
        free(temp);
    }
    // Case 4: Deleting from the middle.
    else {
        temp = head;
        // Traverse to the node to be deleted.
        for (int i = 1; i < pos; i++) {
            temp = temp->next;
        }
        deletedValue = temp->data;
        temp->prev->next = temp->next; // The previous node's 'next' bypasses the deleted node.
        temp->next->prev = temp->prev; // The next node's 'prev' bypasses the deleted node.
        free(temp);
    }

    listLength--; // Decrement the list length.
    printf("\nRemoved Value: %d\n", deletedValue);
}

/**
 * @brief The main function that drives the program.
 */
int main() {
    int choice;

    printf("Hello! Here You Can Perform Following Circular Doubly Linked List Operations!\n");
    // Main menu loop.
    while (1) {
        printf("\n1. Show Data\n2. Show Data(Reverse)\n3. Insert at First\n4. Insert at Last\n5. Insert at Specific Position\n");
        printf("6. Remove from First\n7. Remove from Last\n8. Remove from Specific Position\n");
        printf("9. Length of Data\n10. Exit\nEnter Your Choice: ");
        scanf("%d", &choice);

        int val, pos;
        switch (choice) {
        case 1:
            print(0); // 0 for forward print
            break;
        case 2:
            print(1); // 1 for reverse print
            break;
        case 3: // Insert at First
            printf("\nEnter Value: ");
            scanf("%d", &val);
            insert(val, 1);
            break;
        case 4: // Insert at Last
            printf("\nEnter Value: ");
            scanf("%d", &val);
            insert(val, listLength + 1);
            break;
        case 5: // Insert at Specific Position
            printf("\nEnter Value: ");
            scanf("%d", &val);
            printf("Enter Position: ");
            scanf("%d", &pos);
            insert(val, pos);
            break;
        case 6: // Remove from First
            if (listLength == 0) {
                printf("\n~~ Linked List is Empty! Cannot Remove ~~\n");
            } else {
                delete(1);
            }
            break;
        case 7: // Remove from Last
            if (listLength == 0) {
                printf("\n~~ Linked List is Empty! Cannot Remove ~~\n");
            } else {
                delete(listLength);
            }
            break;
        case 8: // Remove from Specific Position
            if (listLength == 0) {
                printf("\n~~ Linked List is Empty! Cannot Remove ~~\n");
            } else {
                printf("\nEnter Position: ");
                scanf("%d", &pos);
                delete(pos);
            }
            break;
        case 9: // Length of Data
            printf("\nData Length: %d\n", listLength);
            break;
        case 10: // Exit
            // Note: A complete program should free all nodes before exiting.
            printf("\n~~Thanks for using! Have a great day!~~\n");
            return 0;
        default:
            printf("\n~~Please Enter a Valid Input!~~\n");
        }
    }

    return 0;
}
