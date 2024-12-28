#include <iostream>
#include <stdlib.h>
using namespace std;


struct node {  
    int data;   
    struct node *next;  
};  

struct node *head, *last;
int listLength = 0;

struct node * createLinkedListNode() {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        cout << "Memory allocation failed.\n";
        exit(1); // Exit the program on allocation failure
    }
    listLength ++;
    return temp;
}

void print() { // Show Data
    if (listLength == 0) {
        cout << "\n~~ Linked List is Empty! ~~\n";
        return;
    }
    struct node *current = head;
    cout << "\nLinked List: ";
    do{
        cout << current->data <<" -> ";
        current = current->next;
    } while (current != head);
    cout << head -> data <<"(HEAD)\n";
}

void insert(int val, int pos) { // Insert
    if (pos <= 0 || pos > listLength + 1) {
        cout << "\n~~Invalid Position: " << pos << "~~\n";
        return;
    }

    struct node *newNode = createLinkedListNode();
    newNode->data = val;

    if (pos == 1) {
        newNode->next = head;
        head = newNode;

        if (head -> next == NULL) {
            head -> next = head;
        }
        
        if (last == NULL) {
            last = head;
        }
        
        last -> next = head;
    } else {
        struct node *prev = head;
        for (int i = 1; i < pos - 1; i++) {
            prev = prev->next;
        }
        newNode->next = prev->next;
        prev->next = newNode;

        if (prev == last) {
            last = newNode;
        }
    }
    cout << "Insertion Successful at Position:- " << pos << ". Value:- " << val << "\n";
}

void deleteNode(int pos) { // Remove 
    if (pos <= 0 || pos > listLength) {
        cout << "\n~~Invalid Position: " << pos << "~~\n";
        return;
    }

    int deletedValue;
    struct node *temp = head, *deletedNode;

    if(pos == 1){
        head = head -> next;
        deletedValue = temp -> data;;
        last -> next = head;
        free(temp);
    } else {
        for (int i = 1; i < pos - 1; i++) {
            temp = temp -> next;
        }
        
        deletedNode = temp -> next;
        temp -> next = deletedNode -> next;
        deletedValue = deletedNode -> data;

        if (deletedNode == last) {
            last = temp;
        }

        free(deletedNode);
    }

    listLength--;
    cout << "\nRemoved Value: " << deletedValue << "\n";
}

int main() {
    int choice;

    cout << "Hello! Here You Can Perform Following Linked List Operations!\n";
    while (1) {
        cout << "\n1. Show Data\n2. Insert at First\n3. Insert at Last\n4. Insert at Specific Position\n";
        cout << "5. Remove from First\n6. Remove from Last\n7. Remove from Specific Position\n";
        cout << "8. Length of Data\n9. Exit\nEnter Your Choice: ";
        cin >> choice;

        int val, pos;
        switch (choice) {
        case 1:
            print();
            break;
        case 2:
            cout << "\nEnter Value: ";
            cin >> val;
            insert(val, 1);
            break;
        case 3:
            cout << "\nEnter Value: ";
            cin  >> val;
            insert(val, listLength + 1);
            break;
        case 4:
            cout << "\nEnter Value: ";
            cin >> val;
            cout << "Enter Position: ";
            cin >> pos;
            insert(val, pos);
            break;
        case 5:
            if (listLength == 0) {
                cout << "\n~~ Linked List is Empty! Cannot Remove ~~\n";
            } else {
                deleteNode(1);
            }
            break;
        case 6:
            if (listLength == 0) {
                cout << "\n~~ Linked List is Empty! Cannot Remove ~~\n";
            } else {
                deleteNode(listLength);
            }
            break;
        case 7:
            if (listLength == 0) {
                cout << "\n~~ Linked List is Empty! Cannot Remove ~~\n";
            } else {
                cout << "\nEnter Position: ";
                cin >> pos;
                deleteNode(pos);
            }
            break;
        case 8:
            cout << "\nList Length: " << listLength << "\n";
            break;
        case 9:
            cout << "\n~~Thanks for using! Have a great day!~~";
            return 0;
        default:
            cout << "\n~~Please Enter a Valid Input!~~\n";
        }
    }

    return 0;
}
