const prompt = require('prompt-sync')({ sigint: true }); 

class LinkedStack {
    constructor(val) {
        this.data = val;
        this.next = null;
    }
}

function createNode(val) {
    let newNode = new LinkedStack(val);
    return newNode;
}

(() => {
    let top = null, choice;
    console.log("Hello! Here You Can Perform Following Stack Operation!");
    while (1) {
        console.log("1. Push(Insert)\n2. Pop(Delete)\n3. Peek(See Last Element)\n4. Is Empty(Checks weather Stack is Empty)\n5. Display All Elements\n6. Exit");
        choice = Number.parseInt(prompt("Enter Your Choice:- "));
        switch (choice) {
            case 1:
                console.log("\n");
                var num = Number.parseInt(prompt("Enter Your Number:- "));
                let newNode = createNode(num);
                newNode.next = top;
                top = newNode;
                console.log(`Insertion Successfull:- ${num}\n`);
                break;
            case 2:
                if (top == null) {
                    console.log(`\n~~ Stack is Empty ~~\n`);
                    break;
                }
                console.log(`\nDeletion Successfull:- ${top.data}\n`);
                top= top.next;
                break;
            case 3:
                if (top == null) {
                    console.log(`\n~~ Stack is Empty ~~\n`);
                } else {
                    console.log(`\nData Element:- ${top.data}\n`);
                }
                break;
            case 4:
                if (top == null) {
                    console.log(`\n~~ Stack is Empty ~~\n`);
                } else {
                    console.log(`\n~~ Stack is Not Empty ~~\n`);
                }
                break;
            case 5:
                if (top == null) {
                    console.log(`\n~~ Stack is Empty ~~\n`);
                    break;
                }

                let listStr = '';
                let dumList = Object.assign({}, top);
                do {
                    listStr = listStr + `${dumList.data} `;
                    dumList = dumList.next;
                } while (dumList != null);
                console.log(`\nLinked Stack:- ${listStr}\n`);
                
                break;
            case 6:
                console.log(`\n~~ Thanks For Using! Have a Great Day! ~~\n`);
                return;
            default:
                console.log(`\n~~ Please Enter a Vaild Input! ~~\n`);
                break;
        }
    }
    return;
})();