#include <stdio.h>
#include <stdlib.h>

// Defines the structure for a doubly linked list node.
// It includes a pointer to the next node and a new pointer 'prev' to the previous node.
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
    // Initialize both next and prev pointers to NULL for the standalone new node.
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
    
    // If reverse is true, print from tail to head.
    if (reverse) {
        printf("\nLinked List(Reverse): ");
        struct node *current = tail;
        // Traverse backwards using the 'prev' pointer.
        while (current != NULL) {
            printf("%d -> ", current->data);
            current = current->prev;
        }
        printf("NULL\n");
    }
    // Otherwise, print from head to tail.
    else {
        printf("\nLinked List: ");
        struct node *current = head;
        // Traverse forwards using the 'next' pointer.
        while (current != NULL) {
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
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

    // Create a new node and assign its data.
    struct node *newNode = createLinkedListNode();
    newNode->data = val;

    // Case 1: Insert at the beginning (pos == 1).
    if (pos == 1) {
        // If the list is not empty, the old head's 'prev' must point to the new node.
        if(head){
            head->prev = newNode;
        }
        newNode->next = head; // New node's 'next' points to the old head.
        head = newNode;       // New node becomes the new head.
        // If the list was empty, the new node is also the tail.
        if(!tail){
            tail = newNode;
        }
    } 
    // Case 2: Insert at the end (pos == listLength, which is now one greater than the original length).
    else if(pos == listLength){
        tail->next = newNode;   // Old tail's 'next' points to the new node.
        newNode->prev = tail;   // New node's 'prev' points to the old tail.
        tail = newNode;         // New node becomes the new tail.
    }
    // Case 3: Insert in the middle.
    else {
        struct node *temp = head;
        // Traverse to the node just before the insertion point.
        for (int i = 1; i < pos - 1; i++) {
            temp = temp->next;
        }
        // Update all four pointers to link the new node correctly.
        newNode->next = temp->next;     // New node's 'next' points to the node after temp.
        newNode->prev = temp;           // New node's 'prev' points to temp.
        temp->next->prev = newNode;     // The node after temp now has its 'prev' point to the new node.
        temp->next = newNode;           // Temp's 'next' now points to the new node.
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

    // Case 1: Delete the head node.
    if(pos == 1){
        temp = head;
        head = head->next; // The second node becomes the new head.
        // If the list is not empty after deletion, set the new head's 'prev' to NULL.
        if (head) {
            head->prev = NULL;
        } else {
            // If the list is now empty, also set tail to NULL.
            tail = NULL;
        }
        deletedValue = temp->data;
        free(temp);
    } 
    // Case 2: Delete the tail node.
    else if(pos == listLength){
        temp = tail;
        tail = tail->prev; // The second-to-last node becomes the new tail.
        tail->next = NULL; // The new tail's 'next' is set to NULL.
        deletedValue = temp->data;
        free(temp);
    }
    // Case 3: Delete from the middle.
    else {
        temp = head;
        // Traverse to the node to be deleted.
        for (int i = 1; i < pos; i++) {
            temp = temp->next;
        }
        // The previous node's 'next' now bypasses the deleted node.
        temp->prev->next = temp->next;
        // The next node's 'prev' now bypasses the deleted node.
        temp->next->prev = temp->prev;
        deletedValue = temp->data;
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

    printf("Hello! Here You Can Perform Following Doubly Linked List Operations!\n");
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
