#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // For using boolean types

// Defines the structure for a node in the binary search tree.
struct Node {  
    int data;   
    struct Node *right;  
    struct Node *left;  
};  

// Global pointer to the root of the tree.
struct Node *root = NULL;
// Global counter for the number of nodes in the tree.
int counter = 0;

/**
 * @brief Finds the in-order successor (the smallest node in the right subtree).
 * @param node The root of the subtree to search (usually the right child of the node to be deleted).
 * @return A pointer to the in-order successor node.
 */
struct Node* getInOrderSuccessor(struct Node* node) {
    // The successor is the leftmost node in the given subtree.
    while (node && node->left != NULL)
        node = node->left;
    return node;
}

/**
 * @brief Allocates memory for a new node and initializes it.
 * @param data The integer value for the new node.
 * @return A pointer to the newly created node.
 */
struct Node * createNode(int data) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        exit(1); // Exit the program on allocation failure
    }

    temp->data = data;
    temp->right = NULL;
    temp->left = NULL;

    counter++;

    return temp;
}

/**
 * @brief Inserts a new node into the BST, maintaining the BST property.
 */
void insert() {
    int val;
    printf("\nEnter Value: ");
    scanf("%d", &val);

    struct Node *newNode = createNode(val);

    // If the tree is empty, the new node becomes the root.
    if (root == NULL) {
        root = newNode;
        printf("Insertion Successful. Value: %d\n", val);
        return;
    }

    struct Node* temp = root;
    while (1) {
        // If value is less than the current node's data, go left.
        if (val < temp->data) {
            if (temp->left == NULL) {
                temp->left = newNode;
                break;
            }
            temp = temp->left;
        } 
        // If value is greater, go right.
        else if (val > temp->data) {
            if (temp->right == NULL) {
                temp->right = newNode;
                break;
            }
            temp = temp->right;
        } 
        // If value is the same, duplicates are not allowed.
        else {
            printf("Value already exists in the tree.\n");
            free(newNode); // Free the unused new node.
            counter--;     // Decrement the counter as the node was not added.
            return;
        }
    }

    printf("Insertion Successful. Value: %d\n", val);
}

/**
 * @brief Recursively deletes a node with a given key from the BST.
 * @param root The root of the current subtree.
 * @param key The value of the node to delete.
 * @return The new root of the subtree after deletion.
 */
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) return NULL;

    // Traverse the tree to find the node to delete.
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node to be deleted is found.
        counter--;

        // Case 1: Node has no left child.
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } 
        // Case 2: Node has no right child.
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Node has two children.
        // Get the in-order successor (smallest in the right subtree).
        struct Node* succ = getInOrderSuccessor(root->right);
        // Copy the successor's data to this node.
        root->data = succ->data;
        // Delete the in-order successor from the right subtree.
        root->right = deleteNode(root->right, succ->data);
    }

    return root;
}

/**
 * @brief Searches for a value in the BST efficiently.
 */
void search() {
    if (root == NULL) {
        printf("\n~~Tree is Empty~~\n");
        return;
    }

    int val;
    printf("\nEnter Value to search: ");
    scanf("%d", &val);

    struct Node* temp = root;
    while (temp != NULL) {
        // If found, print and exit.
        if (temp->data == val) {
            printf("Element %d Found in the tree.\n", val);
            return;
        } 
        // If search value is smaller, go left.
        else if (val < temp->data) {
            temp = temp->left;
        } 
        // If search value is larger, go right.
        else {
            temp = temp->right;
        }
    }

    // If the loop finishes, the element was not found.
    printf("Element %d not found!\n", val);
}

/**
 * @brief Performs an in-order traversal (Left, Root, Right). For a BST, this prints elements in sorted order.
 * @param node The starting node for the traversal.
 */
void inOrderTraversal(struct Node* node) {
    if (node != NULL){
        inOrderTraversal(node->left);
        printf("%d ", node->data);
        inOrderTraversal(node->right);
    }
}

/**
 * @brief Performs a pre-order traversal (Root, Left, Right).
 * @param node The starting node for the traversal.
 */
void preOrderTraversal(struct Node* node) {
    if (node != NULL){
        printf("%d ", node->data);
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);
    }
}

/**
 * @brief Performs a post-order traversal (Left, Right, Root).
 * @param node The starting node for the traversal.
 */
void postOrderTraversal(struct Node* node) {
    if (node != NULL){
        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        printf("%d ", node->data);
    }
}

/**
 * @brief Performs a level-order (BFS) traversal of the tree.
 */
void levelOrderTraversal() {
    if (root == NULL) return;
    
    printf("\n");
    // The queue size should be based on the number of nodes.
    struct Node* queue[counter > 0 ? counter : 1]; 
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        struct Node* temp = queue[front++];
        printf("%d ", temp->data);
        if (temp->left) queue[rear++] = temp->left;
        if (temp->right) queue[rear++] = temp->right;
    }
    printf("\n");
}

/**
 * @brief The main function that drives the program.
 */
int main() {
    int choice;

    printf("Hello! Here You Can Perform Following Binary Search Tree Operations!\n");
    while (1) {
        printf("\n1. Show Data\n2. Insert\n3. Delete\n4. Search\n5. Exit\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: // Show Data
            if (root == NULL) {
                printf("\n~~Tree is Empty~~\n");
                break;
            }
            int choice2;
            printf("\n1. In-Order Traversal(DFS)\n2. Pre-Order Traversal(DFS)\n3. Post-Order Traversal(DFS)\n4. Level-Order Traversal(BFS)\nEnter Your Choice: ");
            scanf("%d", &choice2);
            switch (choice2) {
            case 1:
                printf("\nIn-Order: ");
                inOrderTraversal(root);
                printf("\n");
                break;
            case 2:
                printf("\nPre-Order: ");
                preOrderTraversal(root);
                printf("\n");
                break;
            case 3:
                printf("\nPost-Order: ");
                postOrderTraversal(root);
                printf("\n");
                break;
            case 4:
                printf("\nLevel-Order: ");
                levelOrderTraversal();
                break;
            default:
                printf("\n~~Please Enter a Valid Input!~~\n");
            }
            break;
        case 2: // Insert
            insert();
            break;
        case 3: // Delete
            if (root == NULL) {
                printf("\n~~Tree is Empty~~\n");
                break;
            }
            int val;
            printf("\nEnter Value to delete: ");
            scanf("%d", &val);
            int originalCount = counter;
            root = deleteNode(root, val);
            if (counter < originalCount) {
                printf("Deletion Successful for value: %d\n", val);
            } else {
                printf("Element not found!\n");
            }
            break;
        case 4: // Search
            search();
            break;
        case 5: // Exit
            // Note: A complete program should free all allocated nodes before exiting.
            printf("\n~~Thanks for using! Have a great day!~~");
            return 0;
        default:
            printf("\n~~Please Enter a Valid Input!~~\n");
        }
    }

    return 0;
}
