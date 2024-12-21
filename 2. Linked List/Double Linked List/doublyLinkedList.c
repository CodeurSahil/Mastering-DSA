
#include <stdio.h>
#include <stdlib.h>


struct node {  
    int data;   
    struct node *next;  
    struct node *prev;  
};  

struct node *head, *tail;
int listLength = 0;

struct node * createLinkedListNode() {
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory allocation failed.\n");
        exit(1); // Exit the program on allocation failure
    }
    temp -> next = NULL;
    temp -> prev = NULL;
    listLength++;
    return temp;
}

void print(int reverse) { // Show Data
    if (listLength == 0) {
        printf("\n~~ Linked List is Empty! ~~\n");
        return;
    }
    if (reverse) {
        printf("\nLinked List(Reverse): %d -> ", tail -> data);
        struct node *current = tail;
        while (current -> prev != NULL) {
            current = current->prev;
            printf("%d -> ", current->data);
        }
        printf("NULL\n");
        current = tail;
    }
    else {
        printf("\nLinked List: %d -> ", head -> data);
        struct node *current = head;
        while (current -> next != NULL) {
            current = current -> next;
            printf("%d -> ", current->data);
        }
        printf("NULL\n");
    }
}

void insert(int val, int pos) { // Insert
    if (pos <= 0 || pos > listLength + 1) {
        printf("\n~~Invalid Position: %d~~\n", pos);
        return;
    }

    struct node *newNode = createLinkedListNode();
    newNode -> data = val;

    if (pos == 1) {
        if(head){
            head->prev = newNode;
            newNode->next = head;
        }

        head = newNode;
        
        if(!tail){
            tail = newNode;
        } else if(tail -> prev == NULL){
            tail -> prev = head;
        }
    } 
    else if(pos == listLength){
        printf("120p");
        tail -> next = newNode;
        newNode -> prev = tail;
        newNode -> next = NULL;
        tail = newNode;
        if(head -> next == NULL){
            head -> next = tail;
        }
    }
    else {
        // 1 -> 2 -> n -> 3 -> 4 -> 5 // 3
        // 1 <- 2 <- n <- 3 <- 4 <- 5 // 3
        struct node *dum = head;
        for (int i = 1; i < pos - 1; i++) {
            dum = dum -> next;
        }
        newNode -> next = dum -> next;
        newNode -> prev = dum;
        dum -> next -> prev = newNode;
        dum -> next = newNode;
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
        head -> prev = NULL;
        deletedValue = temp -> data;;
        free(temp);
    } 
    else if(pos == listLength){
        temp = tail;
        tail = tail -> prev;
        tail -> next = NULL;
        deletedValue = temp -> data;;
        free(temp);
    }
    else {
        // 1 -> 2 -> n -> 3 -> 4 -> 5 // 3
        // 1 <- 2 <- n <- 3 <- 4 <- 5 // 3
        for (int i = 1; i < pos - 1; i++) {
            temp = temp -> next;
        }
        deletedNode = temp -> next;
        temp -> next = deletedNode -> next;
        deletedNode -> next -> prev = temp;
        deletedValue = deletedNode -> data;;
        free(deletedNode);
    }

    listLength--;
    printf("\nRemoved Value: %d\n", deletedValue);
}

int main() {
    int choice;

    printf("Hello! Here You Can Perform Following Linked List Operations!\n");
    while (1) {
        printf("\n1. Show Data\n2. Show Data(Reverse)\n3. Insert at First\n4. Insert at Last\n5. Insert at Specific Position\n");
        printf("6. Remove from First\n7. Remove from Last\n8. Remove from Specific Position\n");
        printf("9. Length of Data\n10. Exit\nEnter Your Choice: ");
        scanf("%d", &choice);

        int val, pos;
        switch (choice) {
        case 1:
            print(0);
            break;
        case 2:
            print(1);
            break;
        case 3:
            printf("\nEnter Value: ");
            scanf("%d", &val);
            insert(val, 1);
            break;
        case 4:
            printf("\nEnter Value: ");
            scanf("%d", &val);
            insert(val, listLength + 1);
            break;
        case 5:
            printf("\nEnter Value: ");
            scanf("%d", &val);
            printf("Enter Position: ");
            scanf("%d", &pos);
            insert(val, pos);
            break;
        case 6:
            if (listLength == 0) {
                printf("\n~~ Linked List is Empty! Cannot Remove ~~\n");
            } else {
                delete(1);
            }
            break;
        case 7:
            if (listLength == 0) {
                printf("\n~~ Linked List is Empty! Cannot Remove ~~\n");
            } else {
                delete(listLength);
            }
            break;
        case 8:
            if (listLength == 0) {
                printf("\n~~ Linked List is Empty! Cannot Remove ~~\n");
            } else {
                printf("\nEnter Position: ");
                scanf("%d", &pos);
                delete(pos);
            }
            break;
        case 9:
            printf("\nData Length: %d\n", listLength);
            break;
        case 10:
            printf("\n~~Thanks for using! Have a great day!~~");
            return 0;
        default:
            printf("\n~~Please Enter a Valid Input!~~\n");
        }
    }

    return 0;
}
