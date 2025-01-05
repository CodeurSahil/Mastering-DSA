
import java.util.Scanner;

public class FixedStack {
    private static int[] stack = new int[5];
    private static int stackPointer = -1;
    private static int stackSize = 5;

    public static void main(String[] args) {
        Scanner myObj = new Scanner(System.in);

        int choice;
        System.out.println("Hello! Here You Can Perform Following Array Operations!");
        while (true) {
            System.out.println("1. Push(Insert)\n2. Pop(Delete)\n3. Peek(See Last Element)\n4. Is Empty(Checks weather Stack is Empty)\n5. Is Full(Checks weather Stack is Full)\n6. Exit");
            System.out.print("Enter Your Choice:- ");
            choice = myObj.nextInt();

            switch (choice) {
                case 1:
                System.out.println("~ FixedStack.java:25 -> stackPointer: " + stackPointer);
                    if (stackPointer + 1 == stackSize) {
                        System.out.println("\n~~Stack is Full~~\n");
                        break;
                    }
                    stackPointer++;
                    System.out.print("\nEnter Your Number:- ");
                    int val = myObj.nextInt();
                    
                    stack[stackPointer] = val;
                    System.out.format("\nInsertion Successfull:- %d\n", val);
                    break;
                case 2:
                    if (stackPointer == -1) {
                        System.out.println("\n~~Stack is Empty~~\n");
                        break;
                    }
                    System.out.format("\nDeletion Successfull:- %d\n", stack[stackPointer]);
                    stackPointer--;
                    break;
                case 3:
                    if (stackPointer == -1) {
                        System.out.println("\n~~Stack is Empty~~\n");
                    } else {
                        System.out.format("\nData Element:- %d\n", stack[stackPointer]);
                    }
                    break;
                case 4:
                    if (stackPointer == -1) {
                        System.out.println("\n~~Stack is Empty~~\n");
                    } else {
                        System.out.println("\n~~Stack is Not Empty~~\n");
                    }
                    break;
                case 5:
                    if (stackPointer + 1 == stackSize) {
                        System.out.println("\n~~Stack is Full~~\n");
                    } else {
                        System.out.println("\n~~Stack is Not Full~~\n");
                    }
                    break;
                case 6:
                    System.out.println("\n~~Thanks for Using! Have a Great Day!~~\n");
                    myObj.close();
                    return;
                default:
                    System.out.println("\n~~Please Enter a Valid Input!~~\n");
            }
        }
    }
}
