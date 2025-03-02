#include <iostream>
using namespace std;
// #include <stdlib.h>

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
    cout << "\nEnter Key: ";
    cin >> key;

    if (key < 1) {
        cout << "\nInvalid Key!";
        return;
    }

    cout << "Enter Value: ";
    cin >> value;

    int index = hashFunction(key);
    Node* temp = hashTable[index];

    // Check if the key already exists and update its value
    while (temp) {
        if (temp->key == key) {
            int choice;
            cout << "\nDuplicate Key Already Exist!\n1. Update\n2. Skip\nEnter Choice:- ";
            cin >> choice;
            if (choice == 1) {
                temp->value = value; // Update existing key"s value
                cout << "\nUpdation Successfull!\n";
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

    cout << "\nInsertion Successfull!\n";
}

// Search for a key
void search() {
    int key, val = 0;
    cout << "\nEnter Key: ";
    cin >> key;

    if (key < 1) {
        cout << "\nInvalid Key!";
    }

    int index = hashFunction(key);

    Node* temp = hashTable[index];

    while (temp) {
        if (temp->key == key)
            val = temp->value;
        temp = temp->next;
    }
    if (val) {
        cout << "Value:- " << val << "\n";
    } else {
        cout << "\n~~Key Not Found~~\n";
    }

    return;
}

// Delete a key
void deleteKey() {
    int key;
    cout << "\nEnter Key: ";
    cin >> key;

    if (key < 1) {
        cout << "\nInvalid Key!";
    }

    int index = hashFunction(key);

    Node* temp = hashTable[index];

    Node* prev = NULL;

    while (temp && temp->key != key) {
        prev = temp;
        temp = temp->next;
    }

    if (!temp) {
        cout << "\n~~Key Not Found~~\n";
        return;
    }; // Key not found

    if (!prev)
        hashTable[index] = temp->next; // Remove head
    else
        prev->next = temp->next;

    cout << "Deletion Successfull!\n";

    free(temp);
}

// Display hash table
void display() {
    cout << "\n";
    for (int i = 0; i < TABLE_SIZE; i++) {
        cout << "Index " << i << ":";
        Node* temp = hashTable[i];
        while (temp) {
            cout << "(" << temp->key << ", " << temp->value << ") ->";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
}

int main() {
    int choice;

    cout << "Hello! Here You Can Perform Following Hash Table/Maps Operations!\n";
    while (1) {
        cout << "\n1. Show Data\n2. Insert\n3. Delete With Key\n4. Check Value at a Key\n5. Exit\nEnter Your Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            display();
            break;
        case 2:
            insert();
            break;
        case 3:
            deleteKey();
            break;
        case 4:
            search();
            break;
        case 5:
            cout << "\n~~Thanks for using! Have a great day!~~";
            return 0;
        default:
            cout << "\n~~Please Enter a Valid Input!~~\n";
        }
    }

    return 0;
}
