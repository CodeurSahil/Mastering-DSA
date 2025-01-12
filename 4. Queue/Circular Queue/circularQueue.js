const prompt = require('prompt-sync')({ sigint: true });    

(() => {
    let queue = [], rear = -1, front = -1, capacity = 5, choice;
    console.log("Hello! Here You Can Perform Following Queue Operation!");
    while (1) {
        console.log("1. En-Queue(Insert a Element at rear)\n2. De-Queue(Delete a Element at front)\n3. Peek(Show's Element in the Front)\n4. Is Empty(Checks Queue is Empty)\n5. Is Full(Checks Queue is Full)\n6. Exit");
        choice = Number.parseInt(prompt("Enter Your Choice:- "));
        switch (choice) {
            case 1:
                if ((rear + 1) % capacity == front) {
                    console.log(`\n~~ Queue is Full ~~\n`);
                    break;
                }

                if (front == -1) {
                    front = 0;
                }

                console.log("\n");
                var num = Number.parseInt(prompt("Enter Your Number:- "));

                rear = (rear + 1) % capacity;
                queue[rear] = num;

                console.log(`Insertion Successfull:- ${num}\n`);
                break;
            case 2:
                if (front == -1) {
                    console.log(`\n~~ Queue is Empty ~~\n`);
                    break;
                }
                console.log(`\nDeletion Successfull:- ${queue[front]}\n`);

                if (front == rear) {
                    rear = -1;
                    front = -1;
                } else {
                    front = (front + 1) % capacity;
                }

                break;
            case 3:
                if (front == -1) {
                    console.log(`\n~~ Queue is Empty ~~\n`);
                } else {
                    console.log(`\nData Element:- ${queue[front]}\n`);
                }
                break;
            case 4:
                if (front == -1) {
                    console.log(`\n~~ Queue is Empty ~~\n`);
                } else {
                    console.log(`\n~~ Queue is Not Empty ~~\n`);
                }
                break;
            case 5:
                if ((rear + 1) % capacity == front) {
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