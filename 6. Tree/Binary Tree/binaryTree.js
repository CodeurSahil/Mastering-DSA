const prompt = require('prompt-sync')({ sigint: true });

class Node {
    constructor(val) {
        this.data = val;
        this.right = null;
        this.left = null;
    }
}

let root = null;

function getInOrderSuccessor() {
    let tempParent = null;
    let temp = root;

    while (true) {
        if (temp.right != null) {
            tempParent = temp;
            temp = temp.right;
        } else if (temp.left != null) {
            tempParent = temp;
            temp = temp.left;
        } else {
            temp = null;
            break;
        }

        if (temp.left == null && temp.right == null) {
            if (tempParent != null) {
                if (tempParent.right) {
                    tempParent.right = null;
                } else if (tempParent.left) {
                    tempParent.left = null;
                }
            }
            break;
        }
    }

    return temp;
}

function createNode(data) {
    let temp = new Node(data);
    return temp;
}

function insert() { // Insert
    let val = prompt("Enter Value:- ");

    let newNode = createNode(val);

    if (root == null) {
        root = newNode;
        console.log("Insertion Successful. Value: ", val);
        return;
    }

    queue = [];
    let front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {

        let temp = queue[front++];

        // If left child is missing, insert here
        if (temp.left == null) {
            temp.left = newNode;
            break;
        } else {
            queue[rear++] = temp.left;
        }

        // If right child is missing, insert here
        if (temp.right == null) {
            temp.right = newNode;
            break;
        } else {
            queue[rear++] = temp.right;
        }
    }

    console.log("Insertion Successful. Value: %d\n", val);
}

function deleteNode() { // Remove 
    if (root == null) {
        console.log("\n~~Tree is Empty~~");
        return;
    }

    let val = prompt("Enter Value:- ");

    let queue = [];
    let front = 0, rear = 0;

    queue[rear++] = root;

    let keyNode = null;
    let temp;

    while (front < rear) {
        temp = queue[front++];

        if (temp.data == val) {
            keyNode = temp;  // Store the node to be deleted
        }

        if (temp.left) queue[rear++] = temp.left;
        if (temp.right) queue[rear++] = temp.right;
    }

    if (keyNode) {
        console.log(`Deleted node: ${keyNode.data}\n`);
        let deepestNode = getInOrderSuccessor();

        /**
        * For Deletion of leaf node, we can use a different approach such that we will delete requried node and then again call the same function to delete the deepest node but there is a issue that is duplicate values, so we will use this approach
        */

        if (deepestNode == null) {
            root = null;
            return;
        }
        keyNode.data = deepestNode.data; // Replace with deepest node data
    } else {
        console.log("Element not found!\n");
    }
    return;
}

function search() { // Search 
    if (root == null) {
        console.log("\n~~Tree is Empty~~");
        return;
    }

    let val = prompt("Enter Value:- ");

    let queue = [];
    let front = 0, rear = 0;

    queue[rear++] = root;

    let keyNode = null;
    let temp;

    while (front < rear) {
        temp = queue[front++];

        if (temp.data == val) {
            keyNode = temp;  // Store the node to be deleted
        }

        if (temp.left) queue[rear++] = temp.left;
        if (temp.right) queue[rear++] = temp.right;
    }

    if (keyNode) {
        console.log(`Element Found: ${keyNode.data}\n`);
    } else {
        console.log("Element not found!\n");
    }
}

function inOrderTraversal(node) {
    if (node != null) {
        inOrderTraversal(node.left);
        console.log(`${node.data} `);
        inOrderTraversal(node.right);
    }
    return;
}

function preOrderTraversal(node) {
    if (node != null) {
        console.log(`${node.data} `);
        preOrderTraversal(node.left);
        preOrderTraversal(node.right);
    }
    return;
}

function postOrderTraversal(node) {
    if (node != null) {
        postOrderTraversal(node.left);
        postOrderTraversal(node.right);
        console.log(`${node.data} `);
    }
    return;
}

function levelOrderTraversal() {
    let queue = [];
    let front = 0, rear = 0;

    queue[rear++] = root;

    let temp;

    while (front < rear) {
        temp = queue[front++];

        console.log("%d ", temp.data);

        if (temp.left) queue[rear++] = temp.left;
        if (temp.right) queue[rear++] = temp.right;
    }

    return;
}

(() => {
    let choice, choice2;
    console.log("Hello! Here You Can Perform Following Binary Tree Operation!");
    while (true) {
        console.log("\n1. Show Data\n2. Insert\n3. Delete\n4. Search\n5. Exit");
        choice = Number.parseInt(prompt("Enter Your Choice:- "));
        switch (choice) {
            case 1:
                if (root == null) {
                    console.log("\n~~Tree is Empty~~");
                    break;
                }

                console.log("\n1. In-Order Traversal(DFS)\n2. Pre-Order Traversal(DFS)\n3. Post-Order Traversal(DFS)\n4. Level-Order Traversal(BFS)");
                choice2 = Number.parseInt(prompt("Enter Your Choice:- "));
                switch (choice2) {
                    case 1:
                        console.log("\nIn-Order Traversal(DFS): ");
                        inOrderTraversal(root);
                        break;
                    case 2:
                        console.log("\nPre-Order Traversal(DFS): ");
                        preOrderTraversal(root);
                        break;
                    case 3:
                        console.log("\nPost-Order Traversal(DFS): ");
                        postOrderTraversal(root);
                        break;
                    case 4:
                        console.log("\nLevel-Order Traversal(BFS): ");
                        levelOrderTraversal();
                        break;
                    default:
                        console.log(`\n~~ Please Enter a Vaild Input! ~~\n`);
                        break;
                }
                break;
            case 2:
                insert();
                break;
            case 3:
                deleteNode();
                break;
            case 4:
                search();
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