#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // For using the 'true' keyword

// Define the size of the hash table and a value to represent an empty slot.
#define TABLE_SIZE 10
#define EMPTY -1

// Use two parallel arrays to store keys and values.
int *keyHash, *valueHash;

/**
 * @brief Allocates memory for the hash table arrays and initializes them.
 */
void initiateHash() {
    // Allocate memory for the key and value arrays.
    keyHash = (int*)malloc(TABLE_SIZE * sizeof(int));
    valueHash = (int*)malloc(TABLE_SIZE * sizeof(int));
    if (keyHash == NULL || valueHash == NULL) {
        printf("Memory allocation failed.\n");
        exit(1); // Exit the program on allocation failure.
    }

    // Initialize all slots in the hash table to EMPTY.
    for (int i = 0; i < TABLE_SIZE; i++) {
        keyHash[i] = EMPTY;
        valueHash[i] = EMPTY;
    }
}

/**
 * @brief A simple hash function that maps a key to an initial index.
 * @param key The key to be hashed.
 * @return The calculated index.
 */
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

/**
 * @brief Inserts a key-value pair using linear probing for collision resolution.
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

    int index = hashFunction(key);
    int originalIndex = index;

    // First, probe to see if the key already exists to update it.
    while (keyHash[index] != EMPTY) {
        if (keyHash[index] == key) {
            int choice;
            printf("\nDuplicate Key Already Exists!\n1. Update\n2. Skip\nEnter Choice:- ");
            scanf("%d", &choice);
            if (choice == 1) {
                valueHash[index] = value; // Update existing key's value.
                printf("\nUpdation Successfull!\n");
            }
            return;
        }
        index = (index + 1) % TABLE_SIZE; // Move to the next slot (wrap around if needed).
        if (index == originalIndex) break; // Stop if we've checked the whole table.
    }

    // If the key doesn't exist, find the next empty slot to insert.
    index = originalIndex; // Reset index to start probing for an empty slot.
    while (keyHash[index] != EMPTY) {
        index = (index + 1) % TABLE_SIZE; // Move to the next slot.
        // If we circle back to the start, the table is full.
        if (index == originalIndex) {
            printf("\nHash table is full!\n");
            return;
        }
    }

    // Insert the key and value at the found empty slot.
    keyHash[index] = key;
    valueHash[index] = value;

    printf("\nInsertion Successfull!\n");
}

/**
 * @brief Searches for a key using linear probing and prints its value.
 */
void search() {
    int key;
    printf("\nEnter Key: ");
    scanf("%d", &key);

    if (key < 1) {
        printf("\nInvalid Key!");
        return;
    }

    int index = hashFunction(key);
    int originalIndex = index;

    // Probe through the table to find the key.
    while (keyHash[index] != EMPTY) {
        if (keyHash[index] == key) {
            printf("Value:- %d\n", valueHash[index]);
            return; // Key found, print value and exit.
        }
        index = (index + 1) % TABLE_SIZE; // Move to the next slot.
        if (index == originalIndex) break; // Stop if we've checked the whole table.
    }

    // If the loop finishes without finding the key.
    printf("\n~~Key Not Found~~\n");
}

/**
 * @brief Deletes a key-value pair using linear probing.
 * Note: This simple deletion can disrupt future searches in a probing sequence.
 * A more robust implementation might use a special marker for deleted slots.
 */
void delete() {
    int key;
    printf("\nEnter Key: ");
    scanf("%d", &key);

    if (key < 1) {
        printf("\nInvalid Key!");
        return;
    }

    int index = hashFunction(key);
    int originalIndex = index;

    // Probe to find the key.
    while (keyHash[index] != EMPTY) {
        if (keyHash[index] == key) {
            keyHash[index] = EMPTY;   // Mark the slot as empty.
            valueHash[index] = EMPTY;
            printf("Deletion Successfull!\n");
            return; // Key found and deleted, exit.
        }
        index = (index + 1) % TABLE_SIZE; // Move to the next slot.
        if (index == originalIndex) break; // Stop if we've checked the whole table.
    }

    // If the loop finishes, the key was not found.
    printf("\n~~Key Not Found~~\n");
}

/**
 * @brief Displays the contents of the hash table.
 */
void display() {
    printf("\nIndex | Key | Value\n");
    printf("-------------------\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (keyHash[i] != EMPTY) {
            printf("%-5d | %-3d | %d\n", i, keyHash[i], valueHash[i]);
        } else {
            printf("%-5d | EMPTY\n", i);
        }
    }
    printf("\n");
}

/**
 * @brief The main function that drives the program.
 */
int main() {
    // Initialize the hash table arrays.
    initiateHash();

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
            free(keyHash);   // Free the allocated memory.
            free(valueHash);
            printf("\n~~Thanks for using! Have a great day!~~");
            return 0;
        default:
            printf("\n~~Please Enter a Valid Input!~~\n");
        }
    }

    return 0;
}
