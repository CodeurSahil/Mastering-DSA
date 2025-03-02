TABLE_SIZE = 10;

class Node:
    def __init__(self):
        self.key = None;
        self.value = None;
        self.next = None;

hashTable = [];

# Hash function
def initilizeHash():
    global TABLE_SIZE, hashTable;
    for i in range (0, TABLE_SIZE):
        hashTable.insert(i, None);
    return;


# Hash function
def hashFunction(key):
    global TABLE_SIZE;
    return key % TABLE_SIZE;

# Insert a key-value pair
def insert():
    global hashTable;
    key = int(input("\nEnter Key: "));

    if (key < 1):
        print("\nInvalid Key!");
        return;

    value = int(input("Enter Value: "));

    index = hashFunction(key);

    temp = hashTable[index];

    # Check if the key already exists and update its value
    while (temp):
        if (temp.key == key):
            print("\nDuplicate Key Already Exist!\n1. Update\n2. Skip\nEnter Choice:- ");
            choice = int(input("Enter Choice: "));
            if (choice == 1):
                temp.value = value; # Update existing key"s value
                print("\nUpdation Successfull!\n");
            return;
        temp = temp.next;

    # If key doesn"t exist, insert a new node
    newNode = Node();

    newNode.key = key;
    newNode.value = value;
    newNode.next = hashTable[index]; # Insert at head

    hashTable[index] = newNode;

    print("\nInsertion Successfull!\n");

# Search for a key
def search():
    global hashTable;
    key = int(input("\nEnter Key: "));

    if (key < 1):
        print("\nInvalid Key!");
        return;

    index = hashFunction(key);

    temp = hashTable[index];
    val = None;
    while (temp):
        if (temp.key == key):
            val = temp.value;
        temp = temp.next;
    if (val):
        print("Value:- ", val, sep="");
    else:
        print("\n~~Key Not Found~~");

    return;

# Delete a key
def deleteKey():
    global hashTable;
    key = int(input("\nEnter Key: "));

    if (key < 1):
        print("\nInvalid Key!");
        return;

    index = hashFunction(key);

    temp = hashTable[index];

    prev = None;

    while (temp and temp.key != key):
        prev = temp;
        temp = temp.next;

    if (not temp):
        print("\n~~Key Not Found~~");
        return; # Key not found

    if (not prev):
        hashTable[index] = temp.next; # Remove head
    else:
        prev.next = temp.next;

    print("Deletion Successfull!\n");

# Display hash table
def display():
    global hashTable, TABLE_SIZE;
    print("");
    for i in range (0, TABLE_SIZE):
        print("Index ", i, ":", sep="", end="");
        temp = hashTable[i];
        while (temp):
            print("(", temp.key, ", ", temp.value, ") ->", sep="", end="");
            temp = temp.next;
        print(" NULL");

print("Hello! Here You Can Perform Following Hash Table/Maps Operations!");
initilizeHash();
while (1):
    print("\n1. Show Data\n2. Insert\n3. Delete With Key\n4. Check Value at a Key\n5. Exit");
    choice = int(input("Enter Choice: "));
    if(choice == 1):
        display();
        continue;
    elif(choice == 2):
        insert();
        continue;
    elif(choice == 3):
        deleteKey();
        continue;
    elif(choice == 4):
        search();
        continue;
    elif(choice == 5):
        print("\n~~Thanks for using! Have a great day!~~");
        break;
    else:
        print("\n~~Please Enter a Valid Input!~~\n");
        continue;