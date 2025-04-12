import java.util.Scanner;

class Node {
    int data;
    Node left;
    Node right;

    public Node(int data) {
        this.data = data;
        left = null;
        right = null;
    }
}

public class BinaryTree {
    private Node root = null;
    private int counter = 0;

    private Node getInOrderSuccessor() {
        Node tempParent = null;
        Node temp = this.root;

        while(true) {
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
                if(tempParent != null) {
                    if(tempParent.right != null) {
                        tempParent.right = null;
                    } else if(tempParent.left != null) {
                        tempParent.left = null;
                    }
                }
                break;
            }
        }

        return temp;
    }

    private Node createNode(int data) {
        Node newNode = new Node(data);
        counter++;
        return newNode;
    }

    public void insert(Scanner scanner) {
        System.out.print("Enter Value: ");
        int value = scanner.nextInt();

        Node newNode = createNode(value);

        if (root == null) {
            root = newNode;
            System.out.println("\nInsertion Successful! Value: " + Integer.toString(value));
            return;
        }

        Node[] queue = new Node[counter]; 
        int front = 0, rear = 0;

        queue[rear++] = root;

        while (front < rear) {
            Node currentNode = queue[front++];
            if (currentNode.left == null) {
                currentNode.left = newNode;
                return;
            } else {
                queue[rear++] = currentNode.left;
            }
            
            if (currentNode.right == null) {
                currentNode.right = newNode;
                return;
            } else {
                queue[rear++] = currentNode.right;
            }
        }
        
        System.out.println("\nInsertion Successful! Value: " + Integer.toString(value));
    }

    public void search(Scanner scanner) {
        if (root == null) {
            System.out.print("\n~~Tree is Empty~~\n");
            return;
        }

        System.out.print("Enter Value: ");
        int value = scanner.nextInt();
        
        Node[] queue = new Node[counter]; 
        int front = 0, rear = 0;

        queue[rear++] = root;

        Node keyNode = null;
        Node temp = null;

        while (front < rear) {
            temp = queue[front++];
    
            if (temp.data == value) {
                keyNode = temp;  // Store the node to be deleted
            }
    
            if (temp.left != null) queue[rear++] = temp.left;
            if (temp.right != null) queue[rear++] = temp.right;
        }

        if (keyNode != null) {
            System.out.println("Element Found: " + Integer.toString(keyNode.data));
        } else {
            System.out.println("\n~~ Key Not Found ~~");
        }
    }
    
    public void delete(Scanner scanner) {
        if (root == null) {
            System.out.print("\n~~Tree is Empty~~\n");
            return;
        }

        System.out.print("Enter Value: ");
        int value = scanner.nextInt();
        
        Node[] queue = new Node[counter]; 
        int front = 0, rear = 0;

        queue[rear++] = root;

        Node keyNode = null;
        Node temp = null;
        
        while (front < rear) {
            temp = queue[front++];
    
            if (temp.data == value) {
                keyNode = temp;  // Store the node to be deleted
            }
    
            if (temp.left != null) queue[rear++] = temp.left;
            if (temp.right != null) queue[rear++] = temp.right;
        }

        if (keyNode != null) {
            System.out.println("Deleted node: " + Integer.toString(keyNode.data));
            counter--;
            Node deepestNode = getInOrderSuccessor();
    
            /**
            * For Deletion of leaf node, we can use a different approach such that we will delete requried node and then again call the same function to delete the deepest node but there is a issue that is duplicate values, so we will use this approach
            */
    
            if (deepestNode == null) {
                root = null;
                return;
            }
            keyNode.data = deepestNode.data; // Replace with deepest node data
        } else {
            System.out.println("\n~~ Key Not Found ~~");
        }

    }

    public void inOrderTraversal(Node node) {
        if (node != null){
            inOrderTraversal(node.left);
            System.out.print(Integer.toString(node.data) + " ");
            inOrderTraversal(node.right);
        }
        return;
    }

    public void preOrderTraversal(Node node) {
        if (node != null){
            System.out.print(Integer.toString(node.data) + " ");
            preOrderTraversal(node.left);
            preOrderTraversal(node.right);
        }
        return;
    }
    
    public void postOrderTraversal(Node node) {
        if (node != null){
            postOrderTraversal(node.left);
            postOrderTraversal(node.right);
            System.out.print(Integer.toString(node.data) + " ");
        }
        return;
    }

    public void levelOrderTraversal() {
        Node[] queue = new Node[counter]; 
        int front = 0, rear = 0;
    
        queue[rear++] = root;
    
        Node temp = null;
    
        while (front < rear) {
            temp = queue[front++];
    
            System.out.print(Integer.toString(temp.data) + " ");
    
            if (temp.left != null) queue[rear++] = temp.left;
            if (temp.right != null) queue[rear++] = temp.right;
        }
        return;
    }
    
    

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        BinaryTree tree = new BinaryTree();
        int choice;

        System.out.println("Hello! Here You Can Perform Following Binary Tree Operations!");
        while (true) {
            System.out.println("\n1. Show Data\n2. Insert\n3. Delete\n4. Search\n5. Exit");
            System.out.print("Enter Your Choice: ");
            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    if (tree.root == null) {
                        System.out.print("\n~~Tree is Empty~~\n");
                        break;
                    }

                    int choice2;

                    System.out.println("\n1. In-Order Traversal(DFS)\n2. Pre-Order Traversal(DFS)\n3. Post-Order Traversal(DFS)\n4. Level-Order Traversal(BFS)");
                    System.out.print("Enter Your Choice: ");
                    choice2 = scanner.nextInt();

                    switch (choice2) {
                        case 1:
                            System.out.print("\n");
                            tree.inOrderTraversal(tree.root);
                            System.out.print("\n");
                            break;
                        case 2:
                            System.out.print("\n");
                            tree.preOrderTraversal(tree.root);
                            System.out.print("\n");
                            break;
                        case 3:
                            System.out.print("\n");
                            tree.postOrderTraversal(tree.root);
                            System.out.print("\n");
                            break;
                        case 4:
                            System.out.print("\n");
                            tree.levelOrderTraversal();
                            System.out.print("\n");
                            break;
                        default:
                            System.out.println("\nPlease Enter a Valid Input!");
                        }
                    break;
                case 2:
                    tree.insert(scanner);
                    break;
                case 3:
                    tree.delete(scanner);
                    break;
                case 4:
                    tree.search(scanner);
                    break;
                case 5:
                    System.out.println("\n~~ Thanks for Using! Have a Great Day! ~~");
                    scanner.close();
                    return;
                default:
                    System.out.println("\nPlease Enter a Valid Input!");
            }
        }
    }
}
