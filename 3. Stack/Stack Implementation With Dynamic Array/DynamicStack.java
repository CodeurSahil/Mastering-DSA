
import java.util.Scanner;

public class DynamicStack {
    private static int[] stack = new int[5];
    private static int stackPointer = -1;

    private static void ensureCapacity() {
        if (stackPointer + 1 == stack.length) {
            int[] newArr = new int[stack.length * 2];
            System.arraycopy(stack, 0, newArr, 0, stackPointer + 1);
            stack = newArr;
        }
    }

    public static void main(String[] args) {
        Scanner myObj = new Scanner(System.in);

        int choice;
        System.out.println("Hello! Here You Can Perform Following Stack Operations!");
        while (true) {
            System.out.println("1. Push(Insert)\n2. Pop(Delete)\n3. Peek(See Last Element)\n4. Is Empty(Checks weather Stack is Empty)\n5. Exit");
            System.out.print("Enter Your Choice:- ");
            choice = myObj.nextInt();

            switch (choice) {
                case 1:
                    ensureCapacity();
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
                    System.out.println("\n~~Thanks for Using! Have a Great Day!~~\n");
                    myObj.close();
                    return;
                default:
                    System.out.println("\n~~Please Enter a Valid Input!~~\n");
            }
        }
    }
}
