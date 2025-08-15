#include <stdio.h>
#include <stdlib.h>

// Global pointer to store the base address of the dynamic array. Initialized to NULL.
int *ptr = NULL; 
// Global variable to store the current length of the array.
int arrayLength = 0;

/**
 * @brief Reallocates memory for the array to a new size.
 * * @param len The new desired length of the array.
 */
void generateArray(int len) {
    // Only proceed if the requested length is non-negative.
    if (len >= 0) {
        arrayLength = len;
        // If the new length is 0, free the memory.
        if (len == 0) {
            free(ptr);
            ptr = NULL;
        } else {
            // Reallocate the memory for the array to the new size.
            // realloc can handle ptr being NULL initially.
            int *tempPtr = (int *)realloc(ptr, arrayLength * sizeof(int));
            if (tempPtr == NULL && arrayLength > 0) {
                // If realloc fails, print an error and exit.
                printf("Memory allocation failed.\n");
                free(ptr); // Free the original block if it exists.
                exit(1);
            }
            ptr = tempPtr; // Update the global pointer to the new memory block.
        }
    }
}

/**
 * @brief Prints all the elements of the array from start to end.
 */
void print() { // Show Data
    if (arrayLength == 0) {
        printf("\n~~ Array is Empty! ~~\n");
    } else {
        // Print the first element.
        printf("\nData:- %d", ptr[0]);
        // Loop through the rest of the array and print each element.
        for (int i = 1; i < arrayLength; i++) {
            printf(", %d", ptr[i]);
        }
        printf("\n");
    }
}

/**
 * @brief Prints all the elements of the array in reverse order.
 */
void reversePrint() { // Show in Reverse
    if (arrayLength == 0) {
        printf("\n~~ Array is Empty! ~~\n");
    }
    else {
        // Print the last element first.
        printf("\nData(Reverse):- %d", ptr[arrayLength - 1]);
        // Loop backwards from the second-to-last element to the first.
        for (int i = arrayLength - 2; i >= 0; i--) {
            printf(", %d", ptr[i]);
        }
        printf("\n");
    }
}

/**
 * @brief Prints the current length of the array.
 * * @return The length of the array.
 */
int length() { // Length of Data
    printf("\nData Length: %d\n", arrayLength);
    return arrayLength;
}

/**
 * @brief Adds a new element to the end of the array (like a stack push).
 */
void push() { // Insert At Last
    // Increase the array size by 1.
    generateArray(arrayLength + 1);
    
    int val;
    printf("\nEnter Value:- ");
    scanf("%d", &val);
    
    // Add the new value to the last position of the resized array.
    ptr[arrayLength - 1] = val;
    printf("Insertion Successfull. Value:- %d\n", val);
}

/**
 * @brief Removes the last element from the array (like a stack pop).
 */
void pop() { // Remove From Last
    if (arrayLength == 0) {
        printf("\n~~ Array is Empty! Cannot Remove ~~\n");
        return;
    }
    // Announce the value being removed.
    printf("\nRemoved Value: %d\n", ptr[arrayLength - 1]);
    // Decrease the array size by 1, effectively removing the last element.
    generateArray(arrayLength - 1);
}

/**
 * @brief Inserts an element at a specific position in the array.
 */
void insertInPlace() { // Insert at Specific Position
    int val, pos;
    printf("\nEnter Value:- ");
    scanf("%d", &val);
    printf("Enter Position Number to Insert(1 to %d):- ", arrayLength + 1);
    scanf("%d", &pos);

    // Validate the position. It should be between 1 and arrayLength + 1.
    if (pos <= 0 || pos > arrayLength + 1) {
        printf("Invalid Position: %d\n", pos);
        return;
    }

    // Increase the array size by 1.
    generateArray(arrayLength + 1);

    // Shift elements to the right to make space for the new element.
    // Start from the end and move towards the target position.
    for (int i = arrayLength - 1; i > pos - 1; i--) {
        ptr[i] = ptr[i - 1]; 
    }
    // Insert the new value at the specified position (adjusting for 0-based index).
    ptr[pos - 1] = val;
    printf("Insertion Successful at Position %d. Value: %d\n", pos, val);
}

/**
 * @brief Deletes an element from a specific position in the array.
 */
void deleteInPlace() { // Remove From Specific Position
    if (arrayLength == 0) {
        printf("\n~~ Array is Empty! Cannot Remove ~~\n");
        return;
    }
    
    int pos;
    printf("\nEnter Position to Remove(1 to %d):- ", arrayLength);
    scanf("%d", &pos);

    // Validate the position. It must be within the current bounds of the array.
    if (pos <= 0 || pos > arrayLength) {
        printf("Invalid Position: %d\n", pos);
        return;
    }

    // Announce the value being removed.
    printf("Removed Value: %d\n", ptr[pos - 1]);

    // Shift elements to the left to fill the gap left by the removed element.
    // Start from the removed element's position.
    for (int i = pos - 1; i < arrayLength - 1; i++) {
        ptr[i] = ptr[i + 1]; 
    }

    // Decrease the array size by 1.
    generateArray(arrayLength - 1);
}

/**
 * @brief The main function that drives the program.
 */
int main() {
    int choice;
    printf("Hello! Here You Can Perform Following Array Operation!");
    
    // Infinite loop to keep the menu running until the user chooses to exit.
    while (1) {
        printf("\n1. Show Data\n2. Show in Reverse\n3. Insert At Last\n4. Insert at Specific Position\n5. Remove From Last\n6. Remove From Specific Position\n7. Length of Data\n8. Exit\nEnter Your Choice:- ");
        scanf("%d", &choice);

        // Switch statement to handle the user's choice.
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
            // Free the dynamically allocated memory before exiting.
            free(ptr);
            ptr = NULL; // Good practice to set pointer to NULL after freeing.
            printf("Thanks For Using! Have a Great Day!\n");
            return 0; // Exit the program successfully.
        default:
            printf("Please Enter a Valid Input!\n");
            break;
        }
    }
}
