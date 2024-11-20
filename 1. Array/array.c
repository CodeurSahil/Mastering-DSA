#include <stdio.h>
#include <stdlib.h>

int *ptr = NULL, arrayLength = 0;

void generateArray(int len) {
    if (len > 0) {
        arrayLength = len;
        ptr = (int *)realloc(ptr, arrayLength * sizeof(int));
        if (ptr == NULL) {
            printf("Memory allocation failed.\n");
            exit(1); // Exit the program on allocation failure
        }
    }
}

void print() { // Show Data
    if (arrayLength == 0) {
        printf("\n~~ Array is Empty! ~~\n");
    }
    else {
        printf("\nData:- %d", ptr[0]);
        for (int i = 1; i < arrayLength; i++) {
            printf(", %d", ptr[i]);
        }
        printf("\n");
    }
}

void reversePrint() { // Show in Reverse
    if (arrayLength == 0) {
        printf("\n~~ Array is Empty! ~~\n");
    }
    else {
        printf("\nData(Reverse):- %d", ptr[arrayLength - 1]);
        for (int i = arrayLength - 1; i > 0; i--) {
            printf(", %d", ptr[i - 1]);
        }
        printf("\n");
    }
}

int length() { // Length of Data
    printf("\nData Length: %d\n", arrayLength);
    return arrayLength;
}

void push() { // Insert At Last
    generateArray(arrayLength + 1);
    int val;
    printf("\nEnter Value:- ");
    scanf("%d", &val);
    ptr[arrayLength - 1] = val;
    printf("Insertion Successfull. Value:- %d\n", val);
}

void pop() { // Remove From Last
    if (arrayLength == 0) {
        printf("\n~~ Array is Empty! Cannot Remove ~~\n");
        return;
    }
    printf("\nRemoved Value: %d\n", ptr[arrayLength - 1]);
    generateArray(arrayLength - 1);
}

void insertInPlace() { // Insert at Specific Position
    int val, pos;
    printf("\nEnter Value:- ");
    scanf("%d", &val);
    printf("Enter Position Number to Insert(Greater than 0):- ");
    scanf("%d", &pos);

    if (pos <= 0 || pos > arrayLength + 1) {
        printf("Invalid Position: %d\n", pos);
        return;
    }

    generateArray(arrayLength + 1);

    for (int i = arrayLength - 1; i >= pos - 1; i--) {
        ptr[i] = ptr[i - 1]; // Shift elements to the right
    }
    ptr[pos - 1] = val;
    printf("Insertion Successful at Position %d. Value: %d\n", pos, val);
}

void deleteInPlace() { // Remove From Specific Position
    int pos;
    printf("\nEnter Position to Remove(Greater than 0):- ");
    scanf("%d", &pos);

    if (pos <= 0 || pos > arrayLength) {
        printf("Invalid Position: %d\n", pos);
        return;
    }

    printf("Removed Value: %d\n", ptr[pos - 1]);

    for (int i = pos - 1; i < arrayLength - 1; i++) {
        ptr[i] = ptr[i + 1]; // Shift elements to the left
    }

    generateArray(arrayLength - 1);
}

int main() {
    int choice;
    printf("Hello! Here You Can Perform Following Array Operation!");
    while (1) {
        printf("\n1. Show Data\n2. Show in Reverse\n3. Insert At Last\n4. Insert at Specific Position\n5. Remove From Last\n6. Remove From Specific Position\n7. Lenght of Data\n8. Exit\nEnter Your Choice:- ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            print();
            break;
        case 2:
            reversePrint();
            break;
        case 3:
            push();
            break;
        case 4:
            insertInPlace();
            break;
        case 5:
            pop();
            break;
        case 6:
            deleteInPlace();
            break;
        case 7:
            length();
            break;
        case 8:
            free(ptr);
            printf("Thanks For Using! Have a Great Day!");
            return 0;
        default:
            printf("Please Enter a Vaild Input!\n");
            break;
        }
    }
    return 0;
}