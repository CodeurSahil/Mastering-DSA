const prompt = require('prompt-sync')({ sigint: true });

let queue = [], priorities = [], size = 0, MAX_SIZE = 5;

function getHighestPriority() {
    let highestPriorityIndex = 0;
    for (let i = 0; i < size; i++) {
        if (priorities[i] > priorities[highestPriorityIndex]) {
            highestPriorityIndex = i;
        }
    }
    return highestPriorityIndex;
}

function enQueue() {
    if (size == MAX_SIZE) {
        console.log(`\n~~ Queue is Full ~~\n`);
        return;
    }

    console.log("\n");
    let val = Number.parseInt(prompt("Enter Your Number:- "));
    let priority = Number.parseInt(prompt("Enter Priority:- "));

    queue[size] = val;
    priorities[size] = priority;
    size++;

    console.log(`Insertion Successfull:- ${val}\n`);
    return;
}

function deQueue() {
    if (isEmpty()) {
        console.log(`\n~~ Queue is Empty ~~\n`);
        return;
    }

    let highestPriorityIndex = getHighestPriority();
    let toBeDeletedData = queue[highestPriorityIndex];

    for (let i = highestPriorityIndex; i < size - 1; i++) {
        queue[i] = queue[i + 1];
        priorities[i] = priorities[i + 1];
    }
    size--;

    console.log(`\nDeletion Successfull:- ${toBeDeletedData}\n`);
    return;
}

function isEmpty() {
    return size == 0;
}

function peek() {
    if (isEmpty()) {
        console.log(`\n~~ Queue is Empty ~~\n`);
        return;
    }

    let highestPriorityIndex = getHighestPriority();

    console.log(`\nData Element:- ${queue[highestPriorityIndex]}\n`);
    return;
}


(() => {
    let choice;
    console.log("Hello! Here You Can Perform Following Queue Operation!");
    while (1) {
        console.log("1. En-Queue(Insert a Element at rear)\n2. De-Queue(Delete a Element at front)\n3. Peek(Show's Element in the Front)\n4. Is Empty(Checks Queue is Empty)\n5. Exit");
        choice = Number.parseInt(prompt("Enter Your Choice:- "));
        switch (choice) {
            case 1:
                enQueue();
                break;
            case 2:
                deQueue();
                break;
            case 3:
                peek();
                break;
            case 4:
                if (isEmpty()) {
                    console.log(`\n~~ Queue is Empty ~~\n`);
                } else {
                    console.log(`\n~~ Queue is Not Empty ~~\n`);
                }
                break;
            case 5:
                console.log(`\n~~ Thanks For Using! Have a Great Day! ~~\n`);
                return;
            default:
                console.log(`\n~~ Please Enter a Vaild Input! ~~\n`);
                break;
        }
    }
    return;
})();