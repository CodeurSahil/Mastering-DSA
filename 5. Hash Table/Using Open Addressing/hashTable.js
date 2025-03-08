const prompt = require('prompt-sync')({ sigint: true });

let TABLE_SIZE = 10;
let valueHash = [];
let keyHash = [];

function hashFunction(key) {
    return key % TABLE_SIZE;
}

function insert() {
    console.log("");
    let key = Number.parseInt(prompt("Enter Key:- "));

    if (key < 1) {
        console.log("\nInvalid Key!");
        return;
    }

    let value = Number.parseInt(prompt("Enter Value:- "));

    let index = hashFunction(key);
    let originalIndex = index;

    while (true) {
        if (keyHash[index] == key) {
            console.log("\nDuplicate Key Already Exists!\n1. Update\n2. Skip");
            let choice = Number.parseInt(prompt("Enter Your Choice:- "));
            if (choice == 1) {
                valueHash[index] = value;
                console.log("\nUpdate Successful!");
            }
            return;
        }
        index = (index + 1) % TABLE_SIZE;
        if (index == originalIndex) {
            break;
        }
    }

    while (keyHash[index]) {
        index = (index + 1) % TABLE_SIZE;
        if (index == originalIndex) {
            console.log("\nHash table is full!");
            return;
        }
    }

    keyHash[index] = key;
    valueHash[index] = value;

    console.log("\nInsertion Successful!");
}

function search() {
    console.log("");
    let key = Number.parseInt(prompt("Enter Key:- "));

    if (key < 1) {
        console.log("\nInvalid Key!");
        return;
    }

    let index = hashFunction(key);
    let originalIndex = index;

    while (true) {
        if (keyHash[index] == key) {
            console.log("Value: " + valueHash[index]);
            return;
        }
        index = (index + 1) % TABLE_SIZE;
        if (index == originalIndex) {
            break;
        }
    }

    console.log("\n~~ Key Not Found ~~");
}

function deleteKey() {
    console.log("");
    let key = Number.parseInt(prompt("Enter Key:- "));

    if (key < 1) {
        console.log("\nInvalid Key!");
        return;
    }

    let index = hashFunction(key);
    let originalIndex = index;

    while (true) {
        if (keyHash[index] == key) {
            valueHash[index] = null;
            keyHash[index] = null;
            console.log("Deletion Successful!");
            return;
        }
        index = (index + 1) % TABLE_SIZE;
        if (index == originalIndex) {
            break;
        }
    }

    console.log("\n~~ Key Not Found ~~");
}

function display() {
    console.log("");
    let str = "";
    for (let i = 0; i < TABLE_SIZE; i++) {
        if(keyHash[i]) {
            str = str + "(" + keyHash[i] + ", " + valueHash[i] + ")";
        } else {
            str = str + "NULL";
        }

        if (i != TABLE_SIZE - 1) {
            str = str +  " , ";
        }
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
