#include<stdio.h>
#include<stdlib.h>

int* ptr, arrayLenght = 0;

void generateArray(){
    if (arrayLenght == 0){
        arrayLenght++;
        ptr = (int*)calloc(arrayLenght, sizeof(int));
        if (ptr == NULL) {
            printf("memory cannot be allocated");
        }
    }
    else {
        arrayLenght++;
        ptr = (int*)realloc(ptr, arrayLenght * sizeof(int));
        if (ptr == NULL) {
            printf("memory cannot be allocated");
        }
    }
}

void print(){ // Show Data
    if (arrayLenght == 0){
        printf("\n~~ Array is Empty! ~~\n");
    }
    else {
        printf("\nData:- %d",ptr[0]);
        for (int i = 1; i < arrayLenght; i++){
            printf(", %d", ptr[i]);
        }
    }
}

void reversePrint(){ // Show in Reverse
    if (arrayLenght == 0){
        printf("\nArray is Empty!");
    }
    else {
        printf("\nData:- %d",ptr[arrayLenght - 1]);
        for (int i = arrayLenght - 1; i > 0; i--){
            printf(", %d", ptr[i - 1]);
        }
    }
}

int length(){ // Lenght of Data
    return arrayLenght;
}

void push(){ // Insert At Last
    generateArray();
    int val;
    printf("\nEnter Value:- ");
    scanf("%d", &val);
    ptr[arrayLenght - 1] = val;
    printf("Insertion success Value:- %d\n", val);
}

void pop(){ // Remove From Last

}

void insertInPlace(){ // Insert at Specific Position
    int val, pos;
    printf("\nEnter Value:- ");
    scanf("%d", &val);
    printf("Enter Position Number to Insert(Greater than 0):- ");
    scanf("%d", &pos);
    if(pos < 0){
        printf("Invalid Position:- %d", pos);
        return;
    }

    if(pos <= arrayLenght){
        generateArray();
        int dum = arrayLenght;
        while (dum > pos){
            ptr[arrayLenght - 1] = ptr[arrayLenght - 2];
            dum--;
        }
        ptr[pos - 1] = val;
        printf("Insertion Successfull at %d, Value:- %d", pos, val);
    } 
    else if(pos > arrayLenght){

    }
    ptr[arrayLenght] = val;
    printf("\nInsertion success Value:- %d", val);
}

void deleteInPlace(){ // Remove From Specific Position

}

int main(){
    int i = 0, choice;
    printf("Hello! Here You Can Perform Following Array Operation!");
    while(i == 0){
        printf("\n1. Show Data\n2. Show in Reverse\n3. Insert At Last\n4. Insert at Specific Position\n5. Remove From Last\n6. Remove From Specific Position\n7. Lenght of Data\n8. Exit\nEnter Your Choice:- ");
        scanf("%d", &choice);

        switch(choice) {
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
                i = 1;
                break;
            default:
                printf("Please Enter a Vaild Input!\n");
                break;
        }
        
    }
    return 0;
}