const prompt = require('prompt-sync')({ sigint: true });

let TABLE_SIZE = 10;
let hashTable = [];

class Node {
    constructor(key, value) {
        this.key = key;
        this.value = value;
        this.next = null;
    }
}

function hashFunction(key) {
    return key % TABLE_SIZE;
}

function insert() {
    let key = Number.parseInt(prompt("Enter Key:- "));

    if (key < 1) {
        console.log("\nInvalid Key!");
        return;
    }

    let value = Number.parseInt(prompt("Enter Value:- "));

    let index = hashFunction(key);

    let temp = hashTable[index];

    while (temp != null) {
        if (temp.key == key) {
            console.log("\nDuplicate Key Already Exists!\n1. Update\n2. Skip\nEnter Choice: ");
            let choice = Number.parseInt(prompt("Enter Your Choice:- "));
            if (choice == 1) {
                temp.value = value;
                console.log("\nUpdate Successful!");
            }
            return;
        }
        temp = temp.next;
    }

    let newNode = new Node(key, value);
    newNode.next = hashTable[index]; // Insert at head
    hashTable[index] = newNode;

    console.log("\nInsertion Successful!");
}

function search() {
    let key = Number.parseInt(prompt("Enter Key:- "));

    if (key < 1) {
        console.log("\nInvalid Key!");
        return;
    }

    let index = hashFunction(key);

    let temp = hashTable[index];

    while (temp != null) {
        if (temp.key == key) {
            console.log("Value: " + temp.value);
            return;
        }
        temp = temp.next;
    }

    console.log("\n~~ Key Not Found ~~");
}

function deleteKey() {
    let key = Number.parseInt(prompt("Enter Key:- "));

    if (key < 1) {
        console.log("\nInvalid Key!");
        return;
    }

    let index = hashFunction(key);

    let temp = hashTable[index];

    let prev = null;

    while (temp != null && temp.key != key) {
        prev = temp;
        temp = temp.next;
    }

    if (temp == null) {
        console.log("\n~~ Key Not Found ~~");
        return;
    }

    if (prev == null) {
        hashTable[index] = temp.next;
    } else {
        prev.next = temp.next;
    }

    console.log("Deletion Successful!");
}

function display() {
    console.log("");
    let str = "";
    for (let i = 0; i < TABLE_SIZE; i++) {
        str = str + "Index " + i + ": "
        let temp = hashTable[i];
        while (temp != null) {
            str = str + "(" + temp.key + ", " + temp.value + ") -> ";
            temp = temp.next;
        }
        str = str + "NULL\n";
    }
    console.log(str);
}

(() => {
    let choice;
    console.log("Hello! Here You Can Perform Following Hash Table/Maps Operations!");
    while (1) {
        console.log("\n1. Show Data\n2. Insert\n3. Delete With Key\n4. Check Value at a Key\n5. Exit");
        choice = Number.parseInt(prompt("Enter Your Choice:- "));
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
                console.log("\n~~ Thanks for Using! Have a Great Day! ~~");
                return;
            default:
                console.log("\nPlease Enter a Valid Input!");
        }
    }
    return;
})();
