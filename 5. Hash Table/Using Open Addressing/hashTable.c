#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10
#define EMPTY -1

int * keyHash, * valueHash;

void initiateHash() {
    keyHash = (int *)realloc(keyHash, TABLE_SIZE * sizeof(int));
    valueHash = (int *)realloc(valueHash, TABLE_SIZE * sizeof(int));
    if (keyHash == NULL || valueHash == NULL) {
        printf("Memory allocation failed.\n");
        exit(1); // Exit the program on allocation failure
    }

    for (int i = 0; i < TABLE_SIZE; i++) {
        keyHash[i] = -1;
        valueHash[i] = -1;
    }

    return;
}

// Hash function
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Insert a key-value pair
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

    while (true) {
        if (keyHash[index] == key) {
            int choice;
            printf("\nDuplicate Key Already Exist!\n1. Update\n2. Skip\nEnter Choice:- ");
            scanf("%d", &choice);
            if (choice == 1) {
                valueHash[index] = value; // Update existing key"s value
                printf("\nUpdation Successfull!\n");
            }
            return;
        }
        index = (index + 1) % TABLE_SIZE;
        if (index == originalIndex)
            break;
    }

    while (keyHash[index] != EMPTY) {
        index = (index + 1) % TABLE_SIZE;
        if (index == originalIndex) {
            printf("\nHash table is full!\n");
            return;
        }
    }

    keyHash[index] = key;
    valueHash[index] = value;

    printf("\nInsertion Successfull!\n");
}

// Search for a key
void search() {
    int key, val = 0;
    printf("\nEnter Key: ");
    scanf("%d", &key);

    if (key < 1) {
        printf("\nInvalid Key!");
    }

    int index = hashFunction(key);
    int originalIndex = index;

    while (true) {
        if (keyHash[index] == key) {
            val = valueHash[index];
            break;
        }
        index = (index + 1) % TABLE_SIZE;
        if (index == originalIndex)
            break;
    }

    if (val) {
        printf("Value:- %d\n", val);
    } else {
        printf("\n~~Key Not Found~~\n");
    }

    return;
}

// Delete a key
void delete() {
    int key, val = 0;
    printf("\nEnter Key: ");
    scanf("%d", &key);

    if (key < 1) {
        printf("\nInvalid Key!");
    }

    int index = hashFunction(key);
    int originalIndex = index;

    while (true) {
        if (keyHash[index] == key) {
            val = valueHash[index];
            break;
        }
        index = (index + 1) % TABLE_SIZE;
        if (index == originalIndex) {
            break;;
        }
    }

    if (!val) {
        printf("\n~~Key Not Found~~\n");
        return;
    }; // Key not found

    keyHash[index] = -1;
    valueHash[index] = -1;

    printf("Deletion Successfull!\n");
}

// Display hash table
void display() {
    printf("\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if(keyHash[i] != EMPTY) {
            printf("(%d, %d)", keyHash[i], valueHash[i]);
        } else {
            printf("NULL");
        }

        if (i != TABLE_SIZE - 1) {
            printf(" , ");
        }
    }
    printf("\n");
}

int main() {
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
            printf("\n~~Thanks for using! Have a great day!~~");
            return 0;
        default:
            printf("\n~~Please Enter a Valid Input!~~\n");
        }
    }

    return 0;
}
