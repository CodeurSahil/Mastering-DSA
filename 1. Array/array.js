const prompt = require('prompt-sync');    

(() => {
    let arr = [], choice;
    console.log("Hello! Here You Can Perform Following Array Operation!");
    while (1) {
        console.log("1. Show Data\n2. Show in Reverse\n3. Insert At Last\n4. Insert at Specific Position\n5. Remove From Last\n6. Remove From Specific Position\n7. Lenght of Data\n8. Exit");
        choice = Number.parseInt(prompt("Enter Your Choice:- "));
        switch (choice) {
            case 1:
                if (arr.length == 0) {
                    console.log(`~~ Array is Empty ~~`);
                    break;
                }
                console.log(`Data - ${arr.join(', ')}`);
                break;
            case 2:
                if (arr.length == 0) {
                    console.log(`~~ Array is Empty ~~`);
                    break;
                }
                console.log(`Data - ${arr.reverse().join(', ')}`);
                break;
            case 3:
                var num = Number.parseInt(prompt("Enter Your Number:- "));
                arr.push(num);
                console.log(`Insertion Successfull - ${num}`);
                break;
            case 4:
                var num = Number.parseInt(prompt("Enter Your Number:- "));
                var pos = Number.parseInt(prompt("Enter Your Position(Greater Than 0):- "));
                if (pos <= 0 || pos > arr.length) {
                    console.log(`~~ Invalid Position ~~`);
                    break;
                }
                arr = [...arr.slice(0, pos - 1), num, ...arr.slice(pos -  1)];
                console.log(`Insertion Successfull at ${pos} with value ${num}`);
                break;
            case 5:
                if (arr.length == 0) {
                    console.log(`~~ Array is Empty ~~`);
                    break;
                }
                console.log(`Deletion Successfull - ${arr.pop()}`);
                break;
            case 6:
                var pos = Number.parseInt(prompt("Enter Your Position(Greater Than 0):- "));
                if (pos <= 0 || pos > arr.length) {
                    console.log(`~~ Invalid Position ~~`);
                    break;
                }
                let delVal = arr[pos - 1];
                arr = [...arr.slice(0, pos - 1), ...arr.slice(pos)];
                console.log(`Deletion Successfull at ${pos} with value ${delVal}`);
                break;
            case 7:
                console.log(`Array Lenght - ${arr.length}`);
                break;
            case 8:
                console.log(`~~ Thanks For Using! Have a Great Day! ~~`);
                return;
            default:
                console.log(`~~ Please Enter a Vaild Input! ~~`);
                break;
        }
    }
    return;
})();