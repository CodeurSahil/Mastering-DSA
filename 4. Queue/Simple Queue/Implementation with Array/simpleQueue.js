const prompt = require('prompt-sync')({ sigint: true });    

(() => {
    let queue = [], rear = -1, front = 0, capacity = 5, choice;
    console.log("Hello! Here You Can Perform Following Queue Operation!");
    while (1) {
        console.log("1. En-Queue(Insert a Element at rear)\n2. De-Queue(Delete a Element at front)\n3. Peek(Show's Element in the Front)\n4. Is Empty(Checks Queue is Empty)\n5. Is Full(Checks Queue is Full)\n6. Exit");
        choice = Number.parseInt(prompt("Enter Your Choice:- "));
        switch (choice) {
            case 1:
                if (rear == capacity - 1) {
                    console.log(`\n~~ Queue is Full ~~\n`);
                    break;
                }
                console.log("\n");
                var num = Number.parseInt(prompt("Enter Your Number:- "));
                rear++;
                queue[rear] = num;
                console.log(`Insertion Successfull:- ${num}\n`);
                break;
            case 2:
                if (front > rear) {
                    console.log(`\n~~ Queue is Empty ~~\n`);
                    break;
                }
                console.log(`\nDeletion Successfull:- ${queue[front]}\n`);
                front++;
                if (rear == capacity - 1 && front > rear) {
                    front = 0;
                    rear = -1;
                    console.log("^^Resetting Queue\n");
                }
                break;
            case 3:
                if (front > rear) {
                    console.log(`\n~~ Queue is Empty ~~\n`);
                } else {
                    console.log(`\nData Element:- ${queue[front]}\n`);
                }
                break;
            case 4:
                if (front > rear) {
                    console.log(`\n~~ Queue is Empty ~~\n`);
                } else {
                    console.log(`\n~~ Queue is Not Empty ~~\n`);
                }
                break;
            case 5:
                if (rear == capacity - 1) {
                    console.log(`\n~~ Queue is Full ~~\n`);
                } else {
                    console.log(`\n~~ Queue is Not Full ~~\n`);
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