import java.util.Scanner;

class Node {
    int data;
    Node left;
    Node right;

    public Node(int data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

public class BinarySearchTree {
    public Node root = null;
    public int counter = 0;
    public boolean isDeleted = false;

    private Node getInOrderSuccessor(Node node) {
        while (node != null && node.left != null)
            node = node.left;
        return node;
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

        Node temp = root;

        while (true) {
            if (temp.data == value) {
                System.out.println("Value already exists in the tree.\n");
                counter--;
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

        System.out.println("\nInsertion Successful. Value: " + Integer.toString(value));
    }

    public void search(Scanner scanner) {
        if (root == null) {
            System.out.print("\n~~Tree is Empty~~\n");
            return;
        }

        System.out.print("Enter Value: ");
        int value = scanner.nextInt();

        Node temp = root;

        while (true) {
            if (temp.data == value) {
                System.out.println("Element Found: " + Integer.toString(temp.data));
                counter--;
                return;
            } else if (temp.data > value) {
                temp = temp.left;
            } else if (temp.data < value) {
                temp = temp.right;
            }

            if (temp == null) {
                System.out.println("\n~~ Key Not Found ~~");
                return;
            }
        }

    }

    public Node delete(Node root, int key) {
        if (root == null)
            return null;

        if (key < root.data) {
            root.left = delete(root.left, key);
        } else if (key > root.data) {
            root.right = delete(root.right, key);
        } else {
            isDeleted = true;
            // Case 1: No child or Case 2: One child
            if (root.left == null) {
                Node temp = root.right;
                return temp;
            } else if (root.right == null) {
                Node temp = root.left;
                return temp;
            }

            // Case 3: Two children
            Node succ = getInOrderSuccessor(root.right);
            root.data = succ.data;
            root.right = delete(root.right, succ.data);
        }

        return root;
    }

    public void inOrderTraversal(Node node) {
        if (node != null) {
            inOrderTraversal(node.left);
            System.out.print(Integer.toString(node.data) + " ");
            inOrderTraversal(node.right);
        }
        return;
    }

    public void preOrderTraversal(Node node) {
        if (node != null) {
            System.out.print(Integer.toString(node.data) + " ");
            preOrderTraversal(node.left);
            preOrderTraversal(node.right);
        }
        return;
    }

    public void postOrderTraversal(Node node) {
        if (node != null) {
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

            if (temp.left != null)
                queue[rear++] = temp.left;
            if (temp.right != null)
                queue[rear++] = temp.right;
        }
        return;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        BinarySearchTree tree = new BinarySearchTree();
        int choice;

        System.out.println("Hello! Here You Can Perform Following Binary Search Tree Operations!");
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

                    System.out.println(
                            "\n1. In-Order Traversal(DFS)\n2. Pre-Order Traversal(DFS)\n3. Post-Order Traversal(DFS)\n4. Level-Order Traversal(BFS)");
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
                    if (tree.root == null) {
                        System.out.print("\n~~Tree is Empty~~\n");
                        break;
                    }

                    System.out.print("\nEnter Value: ");
                    int val = scanner.nextInt();

                    tree.isDeleted = false;

                    tree.root = tree.delete(tree.root, val);

                    // Check if anything changed
                    if (!tree.isDeleted) {
                        System.out.print("Element not found!\n");
                    } else {
                        System.out.format("Element Deleted: %d\n", val);
                    }
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
