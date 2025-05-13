const prompt = require('prompt-sync')({ sigint: true });

class Node {
    constructor(val) {
        this.data = val;
        this.right = null;
        this.left = null;
    }
}

let root = null;

function getInOrderSuccessor(node) {
    while (node != null && node.left != null)
        node = node.left;
    return node;
}

function createNode(data) {
    let temp = new Node(data);
    return temp;
}

function insert() { // Insert
    let value = Number.parseInt(prompt("Enter Value:- "));

    let newNode = createNode(value);

    if (root == null) {
        root = newNode;
        console.log("Insertion Successful. Value: ", value);
        return;
    }

    let temp = root;

    while (true) {
        if (temp.data == value) {
            System.out.println("Value already exists in the tree.\n");
            return;
        } else if (temp.data > value) {
            if (temp.left == null) {
                temp.left = newNode;
                break;
            }
            temp = temp.left;
        } else if (temp.data < value) {
            if (temp.right == null) {
                temp.right = newNode;
                break;
            }
            temp = temp.right;
        }
    }

    console.log("Insertion Successful. Value: %d\n", value);
}

function deleteNode(root, key, isDeleted) { // Remove 
    if (root == null)
        return null;

    if (key < root.data) {
        root.left = deleteNode(root.left, key, isDeleted);
    } else if (key > root.data) {
        root.right = deleteNode(root.right, key, isDeleted);
    } else {
        isDeleted.bool = true;
        // Case 1: No child or Case 2: One child
        if (root.left == null) {
            let temp = root.right;
            return temp;
        } else if (root.right == null) {
            let temp = root.left;
            return temp;
        }

        // Case 3: Two children
        let succ = getInOrderSuccessor(root.right);
        root.data = succ.data;
        root.right = deleteNode(root.right, succ.data, isDeleted);
    }

    return root;
}

function search() { // Search 
    if (root == null) {
        console.log("\n~~Tree is Empty~~");
        return;
    }

    let val = prompt("Enter Value:- ");

    temp = root;

    while (true) {
        if (temp.data == val) {
            console.log(`Element Found: ${temp.data}\n`);
            return;
        } else if (temp.data > val) {
            temp = temp.left;
        } else if (temp.data < val) {
            temp = temp.right;
        }

        if (temp == null) {
            console.log("Element not found!\n");
            return;
        }
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
    console.log("Hello! Here You Can Perform Following Binary Search Tree Operation!");
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
                if (root == null) {
                    console.log("\n~~Tree is Empty~~\n");
                    break;
                }

                let val = prompt("Enter Value:- ");

                /**
                 * Used Object, Because as we passes it into Func the reference is Pass. Help to easily track deletion
                 */
                let isDeleted = { bool: false };
                
                root = deleteNode(root, val, isDeleted);
                
                if (!isDeleted.bool) {
                    console.log("Element not found!\n");
                } else {
                    console.log("Element Deleted: %d\n", val);
                }

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