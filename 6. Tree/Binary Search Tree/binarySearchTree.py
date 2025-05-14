class Node:
    def __init__(self, data):
        self.data = data;
        self.right = None;
        self.left = None;

root = None;
isDeleted = False;

def getInOrderSuccessor(node):
    while (node != None and node.left != None):
            node = node.left;
    return node;

def createNode(data):
    temp = Node(data);
    return temp;

def insert():
    global root;

    val = int(input("Enter Value:- "));

    newNode = createNode(val);

    if (root == None):
        root = newNode;
        print("\nInsertion Successfull!");
        return;

    temp = root;

    while True:
        if (temp.data == val):
                print("Value already exists in the tree.\n");
                return;
        elif (temp.data > val):
            if (temp.left == None):
                temp.left = newNode;
                break;
            temp = temp.left;
        elif (temp.data < val):
            if (temp.right == None):
                    temp.right = newNode;
                    break;
            temp = temp.right;

    print("\nInsertion Successfull!");

def deleteNode(root, key):
    global isDeleted;
    if (root == None):
        return None;

    if (key < root.data):
        root.left = deleteNode(root.left, key);
    elif (key > root.data):
        root.right = deleteNode(root.right, key);
    else:
        isDeleted = True;

        # Case 1: No child or Case 2: One child
        if (root.left == None):
            temp = root.right;
            return temp;
        elif (root.right == None):
            temp = root.left;
            return temp;

        # Case 3: Two children
        succ = getInOrderSuccessor(root.right);
        root.data = succ.data;
        root.right = deleteNode(root.right, succ.data);

    return root;

def search():
    global root;

    if (root == None):
        print("\n~~Tree is Empty~~");
        return;

    val = int(input("Enter Value:- "));

    temp = root;

    while True:
        if (temp.data == val):
            print("Element Found: ", temp.data);
            return;
        elif (temp.data > val):
            temp = temp.left;
        elif (temp.data < val):
            temp = temp.right;

        if (temp == None):
            print("Element Not Found!");
            return;

def inOrderTraversal(node):
    if (node != None):
        inOrderTraversal(node.left);
        print(node.data, " ", end="");
        inOrderTraversal(node.right);
    return;

def preOrderTraversal(node):
    if (node != None):
        print(node.data, " ", end="");
        preOrderTraversal(node.left);
        preOrderTraversal(node.right);
    return;

def postOrderTraversal(node):
    if (node != None):
        postOrderTraversal(node.left);
        postOrderTraversal(node.right);
        print(node.data, " ", end="");
    return;

def levelOrderTraversal():
    queue = [];
    front = 0;
    rear = 0;

    queue.insert(rear, root);
    rear += 1;

    temp = None;

    while (front < rear):
        temp = queue[front];
        front += 1;

        print(temp.data, " ", end="");

        if (temp.left):
            queue.insert(rear, temp.left);
            rear += 1;
        if (temp.right):
            queue.insert(rear, temp.right);
            rear += 1;

    return;

print("Hello! Here You Can Perform Following Binary Tree Operation!");
while (True):
    print("\n1. Show Data\n2. Insert\n3. Delete\n4. Search\n5. Exit");
    choice = int(input("Enter Your Choice:- "));
    if(choice == 1):
        if (root == None):
            print("\n~~Tree is Empty~~");
            continue;
        
        print("\n1. In-Order Traversal(DFS)\n2. Pre-Order Traversal(DFS)\n3. Post-Order Traversal(DFS)\n4. Level-Order Traversal(BFS)");
        choice2 = int(input("Enter Your Choice:- "));
        if(choice2 == 1):
            print();
            inOrderTraversal(root);
            print();
            continue;
        elif(choice2 == 2):
            print();
            preOrderTraversal(root);
            print();
            continue;
        elif(choice2 == 3):
            print();
            postOrderTraversal(root);
            print();
            continue;
        elif(choice2 == 4):
            print();
            levelOrderTraversal();
            print();
            continue;
        else:
            print("\n~~ Please Enter a Vaild Input! ~~\n");
            continue;
    elif(choice == 2):
        insert();
        continue;
    elif(choice == 3):
        if (root == None):
            print("\n~~Tree is Empty~~");
            continue;

        val = int(input("Enter Value:- "));

        isDeleted = False;

        root = deleteNode(root, val);

        if not isDeleted:
            print("Element not found!\n");
        else:
            print("Element Deleted: %d\n", val);

        continue;
    elif(choice == 4):
        search();
        continue;
    elif(choice == 5):
        print("\n~~ Thanks For Using! Have a Great Day! ~~\n");
        break;
    else:
        print("\n~~ Please Enter a Vaild Input! ~~\n");
        continue;