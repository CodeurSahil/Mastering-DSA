const prompt = require('prompt-sync')({ sigint: true }); 

class Node {
    constructor(val) {
        this.data = val;
        this.next = null;
    }
}

(() => {
    let rear = null, front = null, choice;
    console.log("Hello! Here You Can Perform Following Queue Operation!");
    while (1) {
        console.log("1. En-Queue(Insert a Element at rear)\n2. De-Queue(Delete a Element at front)\n3. Peek(Show's Element in the Front)\n4. Is Empty(Checks Queue is Empty)\n5. Exit");
        choice = Number.parseInt(prompt("Enter Your Choice:- "));
        switch (choice) {
            case 1:
                var num = Number.parseInt(prompt("Enter Your Number:- "));

                let newNode = new Node(num);

                if (front == null) {
                    front = newNode;
                    rear = newNode;
                } else {
                    rear.next = newNode;
                    rear = newNode;
                }

                console.log(`Insertion Successfull:- ${num}\n`);
                break;
            case 2:
                if (front == null) {
                    console.log(`\n~~ Queue is Empty ~~\n`);
                    break;
                }
                console.log(`\nDeletion Successfull:- ${front.data}\n`);
                front = front.next;

                if (front == null) {
                    rear = null;
                }
                break;
            case 3:
                if (front == null) {
                    console.log(`\n~~ Queue is Empty ~~\n`);
                } else {
                    console.log(`\nData Element:- ${front.data}\n`);
                }
                break;
            case 4:
                if (front == null) {
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