#include <stdio.h>
#include <stdlib.h>

// Define the size of the hash table.
#define TABLE_SIZE 10

// Define the structure for a node in the hash table.
// Each node stores a key-value pair and a pointer to the next node in case of collisions.
typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

// The hash table is an array of Node pointers. Each element can be the head of a linked list.
Node* hashTable[TABLE_SIZE];

/**
 * @brief A simple hash function that maps a key to an index in the hash table.
 * @param key The key to be hashed.
 * @return The calculated index in the hash table.
 */
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

/**
 * @brief Inserts a key-value pair into the hash table.
 * Handles collisions using chaining (linked lists).
 */
void insert() {
    int value, key;
    printf("\nEnter Key: ");
    scanf("%d", &key);

    if (key < 1) {
        printf("\nInvalid Key!");
        return;
    }

    printf("Enter Value: ");
    scanf("%d", &value);

    // Calculate the index for the key.
    int index = hashFunction(key);
    Node* temp = hashTable[index];

    // Traverse the linked list at the calculated index to check for duplicate keys.
    while (temp) {
        if (temp->key == key) {
            int choice;
            printf("\nDuplicate Key Already Exists!\n1. Update\n2. Skip\nEnter Choice:- ");
            scanf("%d", &choice);
            if (choice == 1) {
                temp->value = value; // Update the value of the existing key.
                printf("\nUpdation Successfull!\n");
            }
            return; // Exit the function whether updated or skipped.
        }
        temp = temp->next;
    }

    // If the key doesn't exist, create and insert a new node at the beginning of the list.
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = hashTable[index]; // The new node points to the old head.
    hashTable[index] = newNode;       // The new node becomes the new head.

    printf("\nInsertion Successfull!\n");
}

/**
 * @brief Searches for a key in the hash table and prints its value if found.
 */
void search() {
    int key, val = 0;
    printf("\nEnter Key: ");
    scanf("%d", &key);

    if (key < 1) {
        printf("\nInvalid Key!");
        return;
    }

    // Calculate the index for the key.
    int index = hashFunction(key);
    Node* temp = hashTable[index];

    // Traverse the linked list at the index.
    while (temp) {
        if (temp->key == key) {
            val = temp->value; // Key found, store its value.
            break; // Exit the loop once the key is found.
        }
        temp = temp->next;
    }

    if (val) {
        printf("Value:- %d\n", val);
    } else {
        printf("\n~~Key Not Found~~\n");
    }
}

/**
 * @brief Deletes a key-value pair from the hash table.
 */
void delete() {
    int key;
    printf("\nEnter Key: ");
    scanf("%d", &key);

    if (key < 1) {
        printf("\nInvalid Key!");
        return;
    }

    // Calculate the index for the key.
    int index = hashFunction(key);
    Node* temp = hashTable[index];
    Node* prev = NULL;

    // Traverse the list to find the node with the matching key.
    while (temp && temp->key != key) {
        prev = temp;
        temp = temp->next;
    }

    // If temp is NULL, the key was not found in the list.
    if (!temp) {
        printf("\n~~Key Not Found~~\n");
        return;
    }

    // Case 1: The node to be deleted is the head of the list.
    if (!prev) {
        hashTable[index] = temp->next;
    } 
    // Case 2: The node is in the middle or at the end of the list.
    else {
        prev->next = temp->next;
    }

    printf("Deletion Successfull!\n");
    free(temp); // Free the memory of the deleted node.
}

/**
 * @brief Displays the entire hash table, including all linked lists.
 */
void display() {
    printf("\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d: ", i);
        Node* temp = hashTable[i];
        // Traverse and print each node in the linked list at the current index.
        while (temp) {
            printf("(%d, %d) -> ", temp->key, temp->value);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

/**
 * @brief The main function that drives the program.
 */
int main() {
    int choice;

    printf("Hello! Here You Can Perform Following Hash Table/Maps Operations!\n");
    while (1) {
        printf("\n1. Show Data\n2. Insert\n3. Delete With Key\n4. Check Value at a Key\n5. Exit\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            display();
            break;
        case 2:
            insert();
            break;
        case 3:
            delete();
            break;
        case 4:
            search();
            break;
        case 5:
            // Note: A complete program should free all allocated nodes before exiting.
            printf("\n~~Thanks for using! Have a great day!~~");
            return 0;
        default:
            printf("\n~~Please Enter a Valid Input!~~\n");
        }
    }

    return 0;
}
