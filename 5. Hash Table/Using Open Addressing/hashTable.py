TABLE_SIZE = 10;
valueHash = [];
keyHash = [];

def initilizeHash():
    global TABLE_SIZE, valueHash, keyHash;
    for i in range (0, TABLE_SIZE):
        valueHash.insert(i, None);
        keyHash.insert(i, None);
    return;

# Hash function
def hashFunction(key):
    global TABLE_SIZE;
    return key % TABLE_SIZE;

# Insert a key-value pair
def insert():
    global valueHash, keyHash, TABLE_SIZE;
    key = int(input("\nEnter Key: "));

    if (key < 1):
        print("\nInvalid Key!");
        return;

    value = int(input("Enter Value: "));

    index = hashFunction(key);
    originalIndex = index;

    while (True):
        if (keyHash[index] == key):
            print("\nDuplicate Key Already Exists!\n1. Update\n2. Skip");
            choice = choice = int(input("Enter Choice: "));
            if (choice == 1):
                valueHash.insert(index, value);
                print("\nUpdate Successful!");
            return;
        index = (index + 1) % TABLE_SIZE;
        if (index == originalIndex):
            break;

    while (keyHash[index]):
        index = (index + 1) % TABLE_SIZE;
        if (index == originalIndex):
            print("\nHash table is full!");
            return;

    keyHash.insert(index, key);
    valueHash.insert(index, value);

    print("\nInsertion Successfull!");

# Search for a key
def search():
    global valueHash, keyHash, TABLE_SIZE;
    key = int(input("\nEnter Key: "));

    if (key < 1):
        print("\nInvalid Key!");
        return;

    index = hashFunction(key);
    originalIndex = index;

    while (True):
        if (keyHash[index] == key):
            print("Value: ", valueHash[index], sep="");
            return;
        index = (index + 1) % TABLE_SIZE;
        if (index == originalIndex):
            break;

    print("\n~~Key Not Found~~");
    return;

# Delete a key
def deleteKey():
    global valueHash, keyHash, TABLE_SIZE;
    key = int(input("\nEnter Key: "));

    if (key < 1):
        print("\nInvalid Key!");
        return;

    index = hashFunction(key);
    originalIndex = index;

    while (True):
        if (keyHash[index] == key):
            keyHash[index] = None;
            valueHash[index] = None;
            print("Deletion Successfull!");
            return;
        index = (index + 1) % TABLE_SIZE;
        if (index == originalIndex):
            break;

    print("\n~~Key Not Found~~");
    return;

# Display hash table
def display():
    global valueHash, TABLE_SIZE;
    print("");
    for i in range (0, TABLE_SIZE):
        if (valueHash[i]):
            print("(", keyHash[i], ", ", valueHash[i], ")", sep="", end="");
        else:
            print("NULL", sep="", end="");
        if (i != TABLE_SIZE - 1):
            print(" , ", sep="", end="")
    print("");
    return;


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