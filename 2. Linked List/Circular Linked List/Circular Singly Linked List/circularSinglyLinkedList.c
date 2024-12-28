#include <stdio.h>
#include <stdlib.h>

struct node {  
    int data;   
    struct node *next;  
};  

struct node *head, *last;
int listLength = 0;

struct node * createLinkedListNode() {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        exit(1); // Exit the program on allocation failure
    }
    listLength ++;
    return temp;
}

void print() { // Show Data
    if (listLength == 0) {
        printf("\n~~ Linked List is Empty! ~~\n");
        return;
    }
    struct node *current = head;
    printf("\nLinked List: ");
    do{
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    printf("%d(Head)\n", head -> data);
}

void insert(int val, int pos) { // Insert
    if (pos <= 0 || pos > listLength + 1) {
        printf("\n~~Invalid Position: %d~~\n", pos);
        return;
    }

    struct node *newNode = createLinkedListNode();
    newNode->data = val;
//  7 -> 1 -> 0 -> N
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
    printf("Insertion Successful at Position %d. Value: %d\n", pos, val);
}

void delete(int pos) { // Remove 
    if (pos <= 0 || pos > listLength) {
        printf("\n~~Invalid Position: %d~~\n", pos);
        return;
    }

    int deletedValue;
    struct node *temp = head, *deletedNode;

    if(pos == 1){
        head = head -> next;
        deletedValue = temp -> data;
        last -> next = head;
        free(temp);
    } else {
        for (int i = 1; i < pos - 1; i++) {
            temp = temp -> next;
        }
        // 1 -> 2 -> 3
        deletedNode = temp -> next;
        temp -> next = deletedNode -> next;
        deletedValue = deletedNode -> data;

        if (deletedNode == last) {
            last = temp;
        }
        
        free(deletedNode);
    }

    listLength--;
    printf("Removed Value: %d\n", deletedValue);
}

int main() {
    int choice;

    printf("Hello! Here You Can Perform Following Linked List Operations!\n");
    while (1) {
        printf("\n1. Show Data\n2. Insert at First\n3. Insert at Last\n4. Insert at Specific Position\n");
        printf("5. Remove from First\n6. Remove from Last\n7. Remove from Specific Position\n");
        printf("8. Length of Data\n9. Exit\nEnter Your Choice: ");
        scanf("%d", &choice);

        int val, pos;
        switch (choice) {
        case 1:
            print();
            break;
        case 2:
            printf("\nEnter Value: ");
            scanf("%d", &val);
            insert(val, 1);
            break;
        case 3:
            printf("\nEnter Value: ");
            scanf("%d", &val);
            insert(val, listLength + 1);
            break;
        case 4:
            printf("\nEnter Value: ");
            scanf("%d", &val);
            printf("Enter Position: ");
            scanf("%d", &pos);
            insert(val, pos);
            break;
        case 5:
            if (listLength == 0) {
                printf("\n~~ Linked List is Empty! Cannot Remove ~~\n");
            } else {
                delete(1);
            }
            break;
        case 6:
            if (listLength == 0) {
                printf("\n~~ Linked List is Empty! Cannot Remove ~~\n");
            } else {
                delete(listLength);
            }
            break;
        case 7:
            if (listLength == 0) {
                printf("\n~~ Linked List is Empty! Cannot Remove ~~\n");
            } else {
                printf("\nEnter Position: ");
                scanf("%d", &pos);
                delete(pos);
            }
            break;
        case 8:
            printf("\nData Length: %d\n", listLength);
            break;
        case 9:
            printf("\n~~Thanks for using! Have a great day!~~");
            return 0;
        default:
            printf("\n~~Please Enter a Valid Input!~~\n");
        }
    }

    return 0;
}
