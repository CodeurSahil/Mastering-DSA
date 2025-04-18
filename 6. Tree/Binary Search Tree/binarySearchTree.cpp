#include <iostream>
using namespace std;

struct Node {  
    int data;   
    struct Node *right;  
    struct Node *left;  
};  

struct Node *root = NULL;
int counter = 0;

struct Node* getInOrderSuccessor(struct Node* node) {
    while (node && node->left != NULL)
        node = node->left;
    return node;
}

struct Node * createNode(int data) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

    if (temp == NULL) {
        cout << "Memory allocation failed.\n";
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

    cout << "\nEnter Value: ";
    cin >> val;

    struct Node *newNode = createNode(val);

    if (root == NULL) {
        root = newNode;
        cout << "Insertion Successful. Value: " << val << "\n";
        return;
    }

    struct Node* temp = root; 
    
    while (1) {
        if (temp->data == val) {
            cout << "Value already exists in the tree.\n";
            free(newNode); // Free the allocated memory for the new node
            counter--;
            return;
        } else if (temp->data > val) {
            if(temp->left == NULL) {
                temp->left = newNode;
                break;
            }
            temp = temp->left;
        } else if (temp->data < val) {
            if(temp->right == NULL) {
                temp->right = newNode;
                break;
            }
            temp = temp->right;
        }
    }

    cout << "Insertion Successful. Value: " << val << "\n";
}

struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) return NULL;

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node to be deleted found
        counter--;

        // Case 1: No child or Case 2: One child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Two children
        struct Node* succ = getInOrderSuccessor(root->right);
        root->data = succ->data;
        root->right = deleteNode(root->right, succ->data);
    }

    return root;
}

void search() { // Search 
    if (root == NULL) {
        cout << "\n~~Tree is Empty~~\n";
        return;
    }

    int val;

    cout << "\nEnter Value: ";
    cin >> val;

    struct Node* temp = root;

    while (1) {
        if (temp->data == val) {
            cout << "Element Found: " << temp->data << "\n";
            return;
        } else if (val < temp->data) {
            temp = temp->left;
        } else if (val > temp->data) {
            temp = temp->right;
        }

        if (temp == NULL) {
            cout << "Element not found!\n";
            return;
        }
    }

    return;
}

void inOrderTraversal(struct Node* node) {
    if (node != NULL){
        inOrderTraversal(node->left);
        cout << node->data << " ";
        inOrderTraversal(node->right);
    }
    return;
}

void preOrderTraversal(struct Node* node) {
    if (node != NULL){
        cout << node->data << " ";
        preOrderTraversal(node->left);
        preOrderTraversal(node->right);
    }
    return;
}

void postOrderTraversal(struct Node* node) {
    if (node != NULL){
        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        cout << node->data << " ";
    }
    return;
}

void levelOrderTraversal() {
    cout << "\n";
    struct Node* queue[counter]; 
    int front = 0, rear = 0;

    queue[rear++] = root;

    struct Node* temp;

    while (front < rear) {
        temp = queue[front++];

        cout << temp->data << " ";

        if (temp->left) queue[rear++] = temp->left;
        if (temp->right) queue[rear++] = temp->right;
    }
    cout << "\n";

    return;
}

int main() {
    int choice;

    cout << "Hello! Here You Can Perform Following Binary Search Tree Operations!\n";
    while (1) {
        cout << "\n1. Show Data\n2. Insert\n3. Delete\n4. Search\n5. Exit\nEnter Your Choice: ";
        cin >> choice;

        int val, pos;
        switch (choice) {
        case 1:
            if (root == NULL) {
                cout << "\n~~Tree is Empty~~\n";
                break;
            }

            int choice2;
            cout << "\n1. In-Order Traversal(DFS)\n2. Pre-Order Traversal(DFS)\n3. Post-Order Traversal(DFS)\n4. Level-Order Traversal(BFS)\nEnter Your Choice: ";
            cin >> choice2;
            switch (choice2) {
            case 1:
                cout << "\n";
                inOrderTraversal(root);
                cout << "\n";
                break;
            case 2:
                cout << "\n";
                preOrderTraversal(root);
                cout << "\n";
                break;
            case 3:
                cout << "\n";
                postOrderTraversal(root);
                cout << "\n";
                break;
            case 4:
                levelOrderTraversal();
                break;
            default:
                cout << "\n~~Please Enter a Valid Input!~~\n";
            }

            break;
        case 2:
            insert();
            break;
        case 3:
            { // Braces were added to counter Error: jump bypasses variable initialization
                if (root == NULL) {
                    cout << "\n~~Tree is Empty~~\n";
                    break;
                }

                int val;
                cout << "\nEnter Value: ";
                cin >> val;

                int orignalCounter = counter;

                root = deleteNode(root, val);

                if (orignalCounter == counter) {
                    cout << "\n~~Element Not Found!~~\n";
                } else {
                    cout << "Element Deleted: " << val << "\n";
                }

                break;
            }
        case 4:
            search();
            break;
        case 5:
            cout << "\n~~Thanks for using! Have a great day!~~";
            return 0;
        default:
            cout << "\n~~Please Enter a Valid Input!~~\n";
        }
    }

    return 0;
}
