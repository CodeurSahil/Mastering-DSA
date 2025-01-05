const prompt = require('prompt-sync')({ sigint: true });    

(() => {
    let stack = [], stackPointer = -1, stackSize = 5, choice;
    console.log("Hello! Here You Can Perform Following Stack Operation!");
    while (1) {
        console.log("1. Push(Insert)\n2. Pop(Delete)\n3. Peek(See Last Element)\n4. Is Empty(Checks weather Stack is Empty)\n5. Is Full(Checks weather Stack is Full)\n6. Exit");
        choice = Number.parseInt(prompt("Enter Your Choice:- "));
        switch (choice) {
            case 1:
                if (stackPointer + 1 == stackSize) {
                    console.log(`\n~~ Stack is Full ~~\n`);
                    break;
                }
                console.log("\n");
                var num = Number.parseInt(prompt("Enter Your Number:- "));
                stackPointer++;
                stack[stackPointer] = num;
                console.log(`Insertion Successfull:- ${num}\n`);
                break;
            case 2:
                if (stackPointer == -1) {
                    console.log(`\n~~ Stack is Empty ~~\n`);
                    break;
                }
                console.log(`\nDeletion Successfull:- ${stack[stackPointer]}\n`);
                stackPointer--;
                break;
            case 3:
                if (stackPointer == -1) {
                    console.log(`\n~~ Stack is Empty ~~\n`);
                } else {
                    console.log(`\nData Element:- ${stack[stackPointer]}\n`);
                }
                break;
            case 4:
                if (stackPointer == -1) {
                    console.log(`\n~~ Stack is Empty ~~\n`);
                } else {
                    console.log(`\n~~ Stack is Not Empty ~~\n`);
                }
                break;
            case 5:
                if (stackPointer + 1 == stackSize) {
                    console.log(`\n~~ Stack is Full ~~\n`);
                } else {
                    console.log(`\n~~ Stack is Not Full ~~\n`);
                }
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