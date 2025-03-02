#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

typedef struct Node {
    int key;
    int value;
    struct Node * next;
} Node;

Node * hashTable[TABLE_SIZE];

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
    Node* temp = hashTable[index];

    // Check if the key already exists and update its value
    while (temp) {
        if (temp->key == key) {
            int choice;
            printf("\nDuplicate Key Already Exist!\n1. Update\n2. Skip\nEnter Choice:- ");
            scanf("%d", &choice);
            if (choice == 1) {
                temp->value = value; // Update existing key"s value
                printf("\nUpdation Successfull!\n");
            }
            return;
        }
        temp = temp->next;
    }

    // If key doesn"t exist, insert a new node
    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->key = key;
    newNode->value = value;
    newNode->next = hashTable[index]; // Insert at head

    hashTable[index] = newNode;

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

    Node* temp = hashTable[index];

    while (temp) {
        if (temp->key == key)
            val = temp->value;
        temp = temp->next;
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
    int key;
    printf("\nEnter Key: ");
    scanf("%d", &key);

    if (key < 1) {
        printf("\nInvalid Key!");
    }

    int index = hashFunction(key);

    Node* temp = hashTable[index];

    Node* prev = NULL;

    while (temp && temp->key != key) {
        prev = temp;
        temp = temp->next;
    }

    if (!temp) {
        printf("\n~~Key Not Found~~\n");
        return;
    }; // Key not found

    if (!prev)
        hashTable[index] = temp->next; // Remove head
    else
        prev->next = temp->next;

    printf("Deletion Successfull!\n");

    free(temp);
}

// Display hash table
void display() {
    printf("\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d: ", i);
        Node* temp = hashTable[i];
        while (temp) {
            printf("(%d, %d) -> ", temp->key, temp->value);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

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
            printf("\n~~Thanks for using! Have a great day!~~");
            return 0;
        default:
            printf("\n~~Please Enter a Valid Input!~~\n");
        }
    }

    return 0;
}
