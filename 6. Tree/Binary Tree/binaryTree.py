class Node:
    def __init__(self, data):
        self.data = data;
        self.right = None;
        self.left = None;

root = None;

def getInOrderSuccessor():
    global root;

    tempParent = None;
    temp = root;

    while (True):
        if (temp.right != None):
            tempParent = temp;
            temp = temp.right;
        elif (temp.left != None):
            tempParent = temp;
            temp = temp.left;
        else:
            temp = None;
            break;

        if (temp.left == None and temp.right == None):
            if (tempParent != None):
                if (tempParent.right):
                    tempParent.right = None;
                elif (tempParent.left):
                    tempParent.left = None;
            break;

    return temp;

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

    queue = [];
    front = 0;
    rear = 0;


    queue.insert(rear, root);
    rear += 1;

    while (front < rear):

        temp = queue[front];
        front += 1;

        if (temp.left == None):
            temp.left = newNode;
            break;
        else:
            queue.insert(rear, temp.left);
            rear += 1;

        if (temp.right == None):
            temp.right = newNode;
            break;
        else:
            queue.insert(rear, temp.right);
            rear += 1;

    print("\nInsertion Successfull!");

def deleteNode():
    global root;

    if (root == None):
        print("\n~~Tree is Empty~~");
        return;

    val = int(input("Enter Value:- "));

    queue = [];
    front = 0;
    rear = 0;

    queue.insert(rear, root);
    rear += 1;

    keyNode = None;
    temp = None;

    while (front < rear):
        temp = queue[front];
        front += 1;

        if (temp.data == val):
            keyNode = temp;

        if (temp.left): 
            queue.insert(rear, temp.left);
            rear += 1;

        if (temp.right):
            queue.insert(rear, temp.right);
            rear += 1;

    if (keyNode):
        print("Deleted node: ", keyNode.data);
        deepestNode = getInOrderSuccessor();

        if (deepestNode == None):
            root = None;
            return;

        keyNode.data = deepestNode.data;
    else:
        print("Element not found!");

    return;

def search():
    global root;

    if (root == None):
        print("\n~~Tree is Empty~~");
        return;

    val = int(input("Enter Value:- "));

    queue = [];
    front = 0;
    rear = 0;

    queue.insert(rear, root);
    rear += 1;

    keyNode = None;
    temp = None;

    while (front < rear):
        temp = queue[front];
        front += 1;

        if (temp.data == val):
            keyNode = temp;

        if (temp.left): 
            queue.insert(rear, temp.left);
            rear += 1; 
        if (temp.right):
            queue.insert(rear, temp.right);
            rear += 1;

    if (keyNode):
        print("Element Found: ", keyNode.data);
    else:
        print("Element Not Found!");

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
        deleteNode();
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