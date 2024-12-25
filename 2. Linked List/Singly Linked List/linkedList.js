const prompt = require('prompt-sync')({ sigint: true });    

let linkedList = {}, listLength = 0;

function insert(val, pos) {
    if(pos <= 0 | pos > listLength + 1){
        console.log("\n~~ Invalid Position ~~\n");
        return;
    }
    
    newNode = { data: val, next: null};
// 4 -> 6 -> 9 -> 0 -> 12 -> 3 -> 3 -> NULL / 7
    if(pos == 1){
        if(Object.keys(linkedList)!= 0){
            newNode.next = linkedList;
        }
        linkedList = newNode;
    } else {
        pre = linkedList;
        i = 1;
        while(i < pos - 1){
            i++;
            pre = pre.next;
        }
        newNode.next = pre.next;
        pre.next = newNode;
    }
    listLength++;
    console.log(`Insertion Successful at Position:- ${pos}. Value:- ${val}\n`);
}

function deleteNode(pos) {
    if(pos <= 0 | pos > listLength){
        console.log("\n~~ Invalid Position ~~\n");
        return;
    }

    let toBeDeletedValue;
    // 3 -> 2 -> 12 -> 0 -> NULL
    if(pos == 1){
        toBeDeletedValue = linkedList.data;
        linkedList = linkedList.next;
    } else {
        pre = linkedList;
        i = 1;
        while(i < pos - 1){ // 0
            i++;
            pre = pre.next;
        }
        toBeDeletedValue = pre.next.data;
        pre.next = pre.next.next;
    }
    listLength--;
    console.log(`\nDeletion Successful at Position:- ${pos}. Value:- ${toBeDeletedValue}\n`);
}

(() => {
    let choice;
    console.log("Hello! Here You Can Perform Following Linked List Operation!");
    while (1) {
        console.log("1. Show Data\n2. Insert at First\n3. Insert At Last\n4. Insert at Specific Position\n5. Remove From First\n6. Remove From Last\n7. Remove From Specific Position\n8. Lenght of Data\n9. Exit");
        choice = Number.parseInt(prompt("Enter Your Choice:- "));
        switch (choice) {
            case 1:
                if (listLength == 0) {
                    console.log(`\n~~ Linked List is Empty ~~\n`);
                    break;
                }console.log('listStr',linkedList);
                let listStr = linkedList.data;
                let dumList = Object.assign({}, linkedList);
                while (dumList.next != null) {
                    dumList = dumList.next;
                    listStr = listStr + ` -> ${dumList.data}`;
                }
                console.log(`\nLinked List:- ${listStr} -> NULL\n`);
                break;
            case 2:
                console.log('\n');
                var num = Number.parseInt(prompt("Enter Your Number:- "));
                insert(num, 1); 
                break;
            case 3:
                console.log('\n');
                var num = Number.parseInt(prompt("Enter Your Number:- "));
                insert(num, listLength + 1); 
                break;
            case 4:
                console.log('\n');
                var num = Number.parseInt(prompt("Enter Your Number:- "));
                var pos = Number.parseInt(prompt("Enter Your Position:- "));
                insert(num, pos); 
                break;
            case 5:
                if (listLength == 0) {
                    console.log(`\n~~ Linked List is Empty ~~\n`);
                    break;
                }
                deleteNode(1);
                break;
            case 6:
                if (listLength == 0) {
                    console.log(`\n~~ Linked List is Empty ~~\n`);
                    break;
                }
                deleteNode(listLength);
                break;
            case 7:
                if (listLength == 0) {
                    console.log(`\n~~ Linked List is Empty ~~\n`);
                    break;
                }
                console.log('\n');
                var pos = Number.parseInt(prompt("Enter Your Position:- "));
                deleteNode(pos);
                break;
            case 8:
                console.log(`\nLinked List Lenght - ${listLength}\n`);
                break;
            case 9:
                console.log(`\n~~ Thanks For Using! Have a Great Day! ~~`);
                return;
            default:
                console.log(`\n~~ Please Enter a Vaild Input! ~~\n`);
                break;
        }
    }
    return;
})();