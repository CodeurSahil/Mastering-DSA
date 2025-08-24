#include <stdio.h>
#include <stdlib.h>

// Defines the structure for a node in the binary tree.
// Each node has data, a pointer to a left child, and a pointer to a right child.
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
 * @brief Finds and detaches the deepest, rightmost node in the tree.
 * This is used in the deletion process to find a replacement node.
 * @return A pointer to the detached deepest node.
 */
struct Node* getDeepestNode() {
    if (root == NULL) return NULL;

    struct Node* queue[counter]; 
    int front = 0, rear = 0;
    queue[rear++] = root;
    struct Node* temp = NULL;
    struct Node* parent = NULL;

    // Level order traversal to find the last node
    while (front < rear) {
        temp = queue[front++];
        if (temp->left) {
            parent = temp;
            queue[rear++] = temp->left;
        }
        if (temp->right) {
            parent = temp;
            queue[rear++] = temp->right;
        }
    }

    // Detach the deepest node from its parent
    if (parent) {
        if (parent->right == temp) {
            parent->right = NULL;
        } else {
            parent->left = NULL;
        }
    }
    
    return temp;
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
 * @brief Inserts a new node at the first available position (level order).
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

    // Use a queue (implemented as an array) for level order traversal to find an empty spot.
    struct Node* queue[counter]; 
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        struct Node* temp = queue[front++];
        
        // If the left child is missing, insert the new node here.
        if (temp->left == NULL) {
            temp->left = newNode;
            break;
        } else {
            queue[rear++] = temp->left;
        }

        // If the right child is missing, insert the new node here.
        if (temp->right == NULL) {
            temp->right = newNode;
            break;
        } else {
            queue[rear++] = temp->right;
        }
    }

    printf("Insertion Successful. Value: %d\n", val);
}

/**
 * @brief Deletes a node with a specific value from the tree.
 * The deleted node is replaced by the deepest, rightmost node.
 */
void delete() {
    if (root == NULL) {
        printf("\n~~Tree is Empty~~\n");
        return;
    }

    int val;
    printf("\nEnter Value to delete: ");
    scanf("%d", &val);

    // Find the node to be deleted (keyNode) and its parent.
    struct Node* queue[counter]; 
    int front = 0, rear = 0;
    queue[rear++] = root;

    struct Node* keyNode = NULL;
    struct Node* temp = NULL;

    while (front < rear) {
        temp = queue[front++];
        if (temp->data == val) {
            keyNode = temp; // Found the node to delete.
        }
        if (temp->left) queue[rear++] = temp->left;
        if (temp->right) queue[rear++] = temp->right;
    }

    if (keyNode) {
        // Find the deepest node to use as a replacement.
        struct Node* deepestNode = getDeepestNode();
        
        // If the tree becomes empty after getting the deepest node (i.e., we are deleting the root and it's the only node)
        if (deepestNode == keyNode) {
             free(keyNode);
             root = NULL;
        } else {
            // Replace the data of the node to be deleted with the deepest node's data.
            keyNode->data = deepestNode->data;
            free(deepestNode); // Free the original deepest node.
        }

        printf("Deletion Successful for value: %d\n", val);
        counter--;
    } else {
        printf("Element not found!\n");
    }
}


/**
 * @brief Searches for a value in the tree using level order traversal.
 */
void search() {
    if (root == NULL) {
        printf("\n~~Tree is Empty~~\n");
        return;
    }

    int val;
    printf("\nEnter Value to search: ");
    scanf("%d", &val);

    struct Node* queue[counter]; 
    int front = 0, rear = 0;
    queue[rear++] = root;

    bool found = false;
    while (front < rear) {
        struct Node* temp = queue[front++];
        if (temp->data == val) {
            found = true;
            break;
        }
        if (temp->left) queue[rear++] = temp->left;
        if (temp->right) queue[rear++] = temp->right;
    }

    if (found) {
        printf("Element %d Found in the tree.\n", val);
    } else {
        printf("Element %d not found!\n", val);
    }
}

/**
 * @brief Performs an in-order traversal (Left, Root, Right) of the tree.
 * @param node The starting node for the traversal (usually the root).
 */
void inOrderTraversal(struct Node* node) {
    if (node != NULL){
        inOrderTraversal(node->left);
        printf("%d ", node->data);
        inOrderTraversal(node->right);
    }
}

/**
 * @brief Performs a pre-order traversal (Root, Left, Right) of the tree.
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
 * @brief Performs a post-order traversal (Left, Right, Root) of the tree.
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
    struct Node* queue[counter]; 
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

    printf("Hello! Here You Can Perform Following Binary Tree Operations!\n");
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
            delete();
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
