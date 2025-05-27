const prompt = require('prompt-sync')({ sigint: true });

let arr = [], arrayLength = 0;

function getParent(i) {
    return (i - 1) / 2;
}

function getLeftChild(i) {
    return (2 * i + 1);
}

function getRightChild(i) {
    return (2 * i + 2);
}

function swap(childIndex, parentIndex) {
    let temp = arr[childIndex];
    arr[childIndex] = arr[parentIndex];
    arr[parentIndex] = temp;
    return;
}

function heapify(index) {
    let leftChild = getLeftChild(index);
    let rightChild = getRightChild(index);

    let smallest = index;

    if (leftChild < arrayLength && arr[leftChild] > arr[index])
        smallest = leftChild;
    if (rightChild < arrayLength && arr[rightChild] > arr[smallest])
        smallest = rightChild;

    if (smallest != index) {
        swap(index, smallest);
        heapify(smallest);
    }
}

function peek() {
    if (arrayLength == 0) {
        console.log("\n~~ Heap is Empty! ~~\n");
        return;
    }

    let val = arr[0];
    console.log(`Value: ${val}\n`);
}

function insert() {
    console.log("");
    let val =  Number.parseInt(prompt("Enter Number:- "));

    let index = arrayLength;
    
    arr[arrayLength++] = val;

    while (index != 0 && arr[getParent(index)] < arr[index]) {
        
        swap(index, getParent(index));

        index = getParent(index);
    }

    console.log(`Insertion Successful, Value: ${val}\n`);
}

function extract(index) {
    if (arrayLength < index) {
        console.log("\n~~ Index Value Not Present! ~~\n");
        return;
    }

    let val = arr[index];
    console.log(`Extracted Value: ${val}\n`);

    arr[index] = arr[arrayLength - 1];

    arrayLength--;

    heapify(index);
    return;
}

(() => {
    let choice;
    console.log("Hello! Here You Can Perform Following Max Heap Operation!");
    while (1) {
        console.log("\n1. View(In Array)\n2. Insert\n3. Extraction of Maximum\n4. Delete at Index\n5. Peek (Get Maximum)\n6. Exit");
        choice = Number.parseInt(prompt("Enter Your Choice:- "));
        switch (choice) {
            case 1:
                if (arrayLength == 0) {
                    console.log(`\n~~ Heap is Empty ~~`);
                    break;
                }
                console.log(`Heap - ${arr.join(', ')}`);
                break;
            case 2:
                insert();
                break;
            case 3:
                if (arrayLength == 0) {
                    console.log(`\n~~ Heap is Empty ~~`);
                    break;
                }

                extract(0);
                break;
            case 4:
                if (arrayLength == 0) {
                    console.log(`\n~~ Heap is Empty ~~`);
                    break;
                }

                let index = Number.parseInt(prompt("Insert Index(Starts with 0):-  "));

                extract(index);
                break;
            case 5:
                peek();
                break;
            case 6:
                console.log(`~~ Thanks For Using! Have a Great Day! ~~`);
                return;
            default:
                console.log(`~~ Please Enter a Vaild Input! ~~`);
                break;
        }
    }
    return;
})();