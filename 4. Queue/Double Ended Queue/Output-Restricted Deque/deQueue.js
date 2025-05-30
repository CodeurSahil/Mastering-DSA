const prompt = require('prompt-sync')({ sigint: true });

let data = [], front = -1, rear = -1, MAX_SIZE = 5;

function enQueue(type) {
    if (isFull()) {
        console.log(`\n~~ Queue is Full ~~\n`);
        return;
    }

    console.log("\n");
    let val = Number.parseInt(prompt("Enter Your Number:- "));

    if (isEmpty()) {
        front = rear = 0;
        data[front] = val;
    } else if (type == "FRONT") {
        if (front == 0) {
            front = MAX_SIZE - 1;
        } else {
            front--;
        }
        data[front] = val;
    } else if (type == "REAR") {
        if (rear == MAX_SIZE - 1) {
            rear = 0;
        } else {
            rear++;
        }
        data[rear] = val;
    }

    console.log(`Insertion Successfull:- ${val}\n`);
    return;
}

function deQueue() {
    if (isEmpty()) {
        console.log(`\n~~ Queue is Empty ~~\n`);
        return;
    }

    let toBeDeletedData = data[front];

    if (front == rear) {
        front = rear = -1; // Reset queue
    } else {
        if (front == MAX_SIZE - 1) {
            front = 0;
        } else {
            front++;
        }
    }

    console.log(`\nDeletion Successfull:- ${toBeDeletedData}\n`);
    return;
}

function isEmpty() {
    return front == -1;
}

function isFull() {
    return (front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1);
}

function peek(type) {
    if (isEmpty()) {
        console.log(`\n~~ Queue is Empty ~~\n`);
        return;
    }

    let peekVal = 0;

    if (type == "FRONT") {
        peekVal = dq.data[dq.front];
    } else if (type == "REAR") {
        peekVal = dq.data[dq.rear];
    }

    console.log(`\nData Element:- ${peekVal}\n`);
    return;
}

(() => {
    let choice;
    console.log("Hello! Here You Can Perform Following Queue Operation!");
    while (1) {
        console.log("1. En-Queue Front\n2. En-Queue Rear\n3. De-Queue(Front)\n4. Peek Front\n5. Peek Rear\n6. Is Empty(Checks Queue is Empty)\n7. Is Full(Checks Queue is Full)\n8. Exit");
        choice = Number.parseInt(prompt("Enter Your Choice:- "));
        switch (choice) {
            case 1:
                enQueue("FRONT");
                break;
            case 2:
                enQueue("REAR");
                break;
            case 3:
                deQueue();
                break;
            case 4:
                peek("FRONT");
                break;
            case 5:
                peek("REAR");
                break;
            case 6:
                if (isEmpty()) {
                    console.log(`\n~~ Queue is Empty ~~\n`);
                } else {
                    console.log(`\n~~ Queue is Not Empty ~~\n`);
                }
                break;
            case 7:
                if (isFull()) {
                    console.log(`\n~~ Queue is Full ~~\n`);
                } else {
                    console.log(`\n~~ Queue is Not Full ~~\n`);
                }
                break;
            case 8:
                console.log(`\n~~ Thanks For Using! Have a Great Day! ~~\n`);
                return;
            default:
                console.log(`\n~~ Please Enter a Vaild Input! ~~\n`);
                break;
        }
    }
    return;
})();