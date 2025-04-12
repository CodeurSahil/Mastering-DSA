#include <stdio.h>
#include <stdlib.h>

struct Node {  
    int data;   
    struct Node *right;  
    struct Node *left;  
};  

struct Node *root = NULL;
int counter = 0;

struct Node* getInOrderSuccessor() {
    struct Node* tempParent = NULL;
    struct Node* temp = root;

    while(1) {
        if (temp->right != NULL) {
            tempParent = temp;
            temp = temp->right;
        } else if (temp->left != NULL) {
            tempParent = temp;
            temp = temp->left;
        } else {
            temp = NULL;
            break;
        }

        if (temp->left == NULL && temp->right == NULL) {
            if(tempParent != NULL) {
                if(tempParent->right) {
                    tempParent->right = NULL;
                } else if(tempParent->left) {
                    tempParent->left = NULL;
                }
            }
            break;
        }
    }

    return temp;
}

struct Node * createNode(int data) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        exit(1); // Exit the program on allocation failure
    }

    temp -> data = data;
    temp -> right = NULL;
    temp -> left = NULL;

    counter++;

    return temp;
}

void insert() { // Insert
    int val;

    printf("\nEnter Value: ");
    scanf("%d", &val);

    struct Node *newNode = createNode(val);

    if (root == NULL) {
        root = newNode;
        printf("Insertion Successful. Value: %d\n", val);
        return;
    }

    struct Node* queue[counter]; 
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {

        struct Node* temp = queue[front++];
        
        // If left child is missing, insert here
        if (temp->left == NULL) {
            temp->left = newNode;
            break;
        } else {
            queue[rear++] = temp->left;
        }

        // If right child is missing, insert here
        if (temp->right == NULL) {
            temp->right = newNode;
            break;
        } else {
            queue[rear++] = temp->right;
        }
    }

    printf("Insertion Successful. Value: %d\n", val);
}

void delete() { // Remove 
    if (root == NULL) {
        printf("\n~~Tree is Empty~~\n");
        return;
    }

    int val;

    printf("\nEnter Value: ");
    scanf("%d", &val);

    struct Node* queue[counter]; 
    int front = 0, rear = 0;

    queue[rear++] = root;

    struct Node* keyNode = NULL;
    struct Node* temp;

    while (front < rear) {
        temp = queue[front++];

        if (temp->data == val) {
            keyNode = temp;  // Store the node to be deleted
        }

        if (temp->left) queue[rear++] = temp->left;
        if (temp->right) queue[rear++] = temp->right;
    }

    if (keyNode) {
        printf("Deleted node: %d\n", keyNode->data);
        counter--;
        struct Node* deepestNode = getInOrderSuccessor();

        /**
        * For Deletion of leaf node, we can use a different approach such that we will delete requried node and then again call the same function to delete the deepest node but there is a issue that is duplicate values, so we will use this approach
        */

        if (deepestNode == NULL) {
            free(keyNode);
            root = NULL;
            return;
        }
        keyNode->data = deepestNode->data; // Replace with deepest node data
        free(deepestNode);
    } else {
        printf("Element not found!\n");
    }
    return;
}

void search() { // Search 
    if (root == NULL) {
        printf("\n~~Tree is Empty~~\n");
        return;
    }

    int val;

    printf("\nEnter Value: ");
    scanf("%d", &val);

    struct Node* queue[counter]; 
    int front = 0, rear = 0;

    queue[rear++] = root;

    struct Node* keyNode = NULL;
    struct Node* temp;

    while (front < rear) {
        temp = queue[front++];

        if (temp->data == val) {
            keyNode = temp;  // Store the node to be deleted
        }

        if (temp->left) queue[rear++] = temp->left;
        if (temp->right) queue[rear++] = temp->right;
    }

    if (keyNode) {
        printf("Element Found: %d\n", keyNode->data);
    } else {
        printf("Element not found!\n");
    }
}

void inOrderTraversal(struct Node* node) {
    if (node != NULL){
        inOrderTraversal(node->left);
        printf("%d ", node->data);
        inOrderTraversal(node->right);
    }
    return;
}

void preOrderTraversal(struct Node* node) {
    if (node != NULL){
        printf("%d ", node->data);
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);
    }
    return;
}

void postOrderTraversal(struct Node* node) {
    if (node != NULL){
        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        printf("%d ", node->data);
    }
    return;
}

void levelOrderTraversal() {
    printf("\n");
    struct Node* queue[counter]; 
    int front = 0, rear = 0;

    queue[rear++] = root;

    struct Node* temp;

    while (front < rear) {
        temp = queue[front++];

        printf("%d ", temp->data);

        if (temp->left) queue[rear++] = temp->left;
        if (temp->right) queue[rear++] = temp->right;
    }
    printf("\n");

    return;
}

int main() {
    int choice;

    printf("Hello! Here You Can Perform Following Binary Tree Operations!\n");
    while (1) {
        printf("\n1. Show Data\n2. Insert\n3. Delete\n4. Search\n5. Exit\nEnter Your Choice: ");
        scanf("%d", &choice);

        int val, pos;
        switch (choice) {
        case 1:
            if (root == NULL) {
                printf("\n~~Tree is Empty~~\n");
                break;
            }

            int choice2;
            printf("\n1. In-Order Traversal(DFS)\n2. Pre-Order Traversal(DFS)\n3. Post-Order Traversal(DFS)\n4. Level-Order Traversal(BFS)\nEnter Your Choice: ");
            scanf("%d", &choice2);
            switch (choice2) {
            case 1:
                printf("\n");
                inOrderTraversal(root);
                printf("\n");
                break;
            case 2:
                printf("\n");
                preOrderTraversal(root);
                printf("\n");
                break;
            case 3:
                printf("\n");
                postOrderTraversal(root);
                printf("\n");
                break;
            case 4:
                levelOrderTraversal();
                break;
            default:
                printf("\n~~Please Enter a Valid Input!~~\n");
            }

            break;
        case 2:
            insert();
            break;
        case 3:
            delete ();
            break;
        case 4:
            search();
            break;
        case 5:
            printf("\n~~Thanks for using! Have a great day!~~");
            return 0;
        default:
            printf("\n~~Please Enter a Valid Input!~~\n");
        }
    }

    return 0;
}

