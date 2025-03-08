#include <iostream>
using namespace std;
#include <stdlib.h>

#define TABLE_SIZE 10
#define EMPTY -1

int * keyHash, * valueHash;

void initiateHash() {
    keyHash = (int *)realloc(keyHash, TABLE_SIZE * sizeof(int));
    valueHash = (int *)realloc(valueHash, TABLE_SIZE * sizeof(int));
    if (keyHash == NULL || valueHash == NULL) {
        cout << "Memory allocation failed.\n";
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
    cout << "\nEnter Key: ";
    cin >> key;

    if (key < 1) {
        cout << "\nInvalid Key!";
        return;
    }

    cout << "Enter Value: ";
    cin >> value;

    if (value < 1) {
        cout << "\nValue Should be Greater than 0!";
    }

    int index = hashFunction(key);
    int originalIndex = index;

    while (true) {
        if (keyHash[index] == key) {
            int choice;
            cout << "\nDuplicate Key Already Exist!\n1. Update\n2. Skip\nEnter Choice:- ";
            cin >> choice;
            if (choice == 1) {
                valueHash[index] = value; // Update existing key"s value
                cout << "\nUpdation Successfull!\n";
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
            cout << "\nHash Table is full!\n";
            return;
        }
    }

    keyHash[index] = key;
    valueHash[index] = value;

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
        cout << "Value:- " << val << "\n";
    } else {
        cout << "\n~~Key Not Found~~\n";
    }

    return;
}

// Delete a key
void deleteKey() {
    int key, val = 0;
    cout << "\nEnter Key: ";
    cin >> key;

    if (key < 1) {
        cout << "\nInvalid Key!";
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
        cout << "\n~~Key Not Found~~\n";
        return;
    }; // Key not found

    keyHash[index] = -1;
    valueHash[index] = -1;

    cout << "Deletion Successfull!\n";
}

// Display hash table
void display() {
    cout << "\n";
    for (int i = 0; i < TABLE_SIZE; i++) {
        if(keyHash[i] != EMPTY) {
            cout << "(" << keyHash[i] << ", " << valueHash[i] << ")";
        } else {
            cout << "NULL";
        }

        if (i != TABLE_SIZE - 1) {
            cout << " , ";
        }
    }
    cout << "\n";
}

int main() {
    initiateHash();

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
