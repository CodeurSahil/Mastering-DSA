#include <iostream>
using namespace std;
#include <stdlib.h>

struct node {  
    int data;   
    struct node *next;  
}; 

struct node *top = NULL;

struct node * createNode(int val) {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        cout << "Memory allocation failed.\n";
        exit(1); // Exit the program on allocation failure
    }
    temp -> data = val;
    temp -> next = NULL;
    return temp;
}

void push() {
    int val;
    cout <<"\nEnter Value:- ";
    cin >> val;
    struct node *newNode;
    newNode = createNode(val);
    newNode -> next = top;
    top = newNode;
    cout <<"Insertion Successfull. Value:- " << val << "\n";
}

void pop() {
    if (top == NULL) {
        cout <<"\n~~ Stack is Empty~~\n";
        return;
    }

    struct node *toBeDeletedNode = top;
    cout <<"\nRemoved Value: " << toBeDeletedNode -> data << "\n";
    top = top -> next;
    free(toBeDeletedNode);
}

void print() {
    if (top == NULL) {
        cout << "\n~~ Stack is Empty~~\n";
        return;
    }
    struct node *current = top;
    cout << "\nStack Elements: ";
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << "\n";
    return;
}

int main() {
    int choice;
    cout << "Hello! Here You Can Perform Following Stack Operation!";
    while (1) {
        cout <<"\n1. Push(Insert)\n2. Pop(Delete)\n3. Peek(See Last Element)\n4. Is Empty(Checks weather Stack is Empty)\n5. Display All Elements\n6. Exit\nEnter Your Choice:- ";
        cin >> choice;

        switch (choice) {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            if (top == NULL) {
                cout <<"\n~~ Stack is Empty~~\n";
            } else {
                cout <<"\nTop Element:- " << top -> data << "\n";
            }
            break;
        case 4:
            if (top == NULL) {
                cout <<"\n~~ Stack is Empty~~\n";
            } else {
                cout <<"\n~~ Stack is Not Empty~~\n";
            }
            break;
        case 5:
            print();
            break;
        case 6:
            cout <<"\n~~Thanks For Using! Have a Great Day!~~\n";
            return 0;
        default:
            cout <<"\n~~Please Enter a Vaild Input!~~\n";
            break;
        }
    }
    return 0;
}