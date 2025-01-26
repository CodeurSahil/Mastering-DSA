const prompt = require('prompt-sync')({ sigint: true });

class Stack {
    constructor() {
        this.top = -1;
        this.data = [];
    }
}

class Queue {
    constructor() {
        this.primaryStack = new Stack();
        this.secondaryStack = new Stack();
    }
}  

function enQueue(queue) {
    var num = Number.parseInt(prompt("Enter Your Number:- "));

    queue.primaryStack.data.push(num);
    queue.primaryStack.top++;

    console.log(`Insertion Successfull:- ${num}\n`);
    return;
}

function deQueue(queue) {
    if (queue.secondaryStack.top == -1) {
        while (queue.primaryStack.top != -1) {
            queue.secondaryStack.data.push(queue.primaryStack.data.pop());
            queue.secondaryStack.top++;
            queue.primaryStack.top--;
        }
    }

    if (queue.secondaryStack.top == -1) { //Checking if the Queue is Empty
        console.log("\n~~ Queue is Empty! ~~\n");
        return;
    }

    let removedVal = queue.secondaryStack.data.pop();
    queue.secondaryStack.top--;

    console.log("\nData Removed:- %d\n", removedVal);
    return;
}

(() => {
    let queue = new Queue(), choice;
    console.log("Hello! Here You Can Perform Following Queue Operation!");
    while (1) {
        console.log("1. En-Queue(Insert a Element at rear)\n2. De-Queue(Delete a Element at front)\n3. Peek(Show's Element in the Front)\n4. Is Empty(Checks Queue is Empty)\n5. Exit");
        choice = Number.parseInt(prompt("Enter Your Choice:- "));
        switch (choice) {
            case 1:
                enQueue(queue);
                break;
            case 2:
                deQueue(queue);
                break;
            case 3:
                if (queue.primaryStack.top == -1 && queue.secondaryStack.top == -1) {
                    console.log(`\n~~ Queue is Empty ~~\n`);
                    break;
                } 
                if (queue.secondaryStack.top != -1) {
                    console.log(`\nData Element:- ${queue.secondaryStack.data[queue.secondaryStack.top]}\n`);
                }
                else {
                    console.log(`\nData Element:- ${queue.primaryStack.data[0]}\n`);
                }
                break;
            case 4:
                if (queue.primaryStack.top == -1 && queue.secondaryStack.top == -1) {
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