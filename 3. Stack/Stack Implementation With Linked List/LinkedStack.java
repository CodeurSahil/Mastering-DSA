
import java.util.Scanner;

public class LinkedStack {
    private int data;
    private LinkedStack next;
    private LinkedStack top = null;

    private LinkedStack createNode(int val) {
        try{
            LinkedStack node = new LinkedStack();
            node.data = val;
            node.next = null;
            return node;
        } catch(Exception e) {
            System.out.println("Failed");
        }
        return null;
    }

    // private void push() {
        // System.out.print("\nEnter Your Number:- ");
        // int val = myObj.nextInt();
    // struct node *newNode;
    // newNode = createNode(val);
    // newNode -> next = top;
    // top = newNode;
    // cout <<"Insertion Successfull. Value:- " << val << "\n";
    // }

    public static void main(String[] args) {
        Scanner myObj = new Scanner(System.in);
        LinkedStack stack = new LinkedStack();

        int choice;
        System.out.println("Hello! Here You Can Perform Following Stack Operations!");
        while (true) {
            System.out.println("1. Push(Insert)\n2. Pop(Delete)\n3. Peek(See Last Element)\n4. Is Empty(Checks weather Stack is Empty)\n5. Display All Elements\n6. Exit");
            System.out.print("Enter Your Choice:- ");
            choice = myObj.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("\nEnter Your Number:- ");
                    int val = myObj.nextInt();
                    LinkedStack newNode = stack.createNode(val);
                    newNode.next = stack.top;
                    stack.top = newNode;
                    System.out.format("\nInsertion Successfull:- %d\n", val);
                    break;
                case 2:
                    if (stack.top == null) {
                        System.out.println("\n~~Stack is Empty~~\n");
                        break;
                    }
                    System.out.format("\nDeletion Successfull:- %d\n", stack.top.data);
                    stack.top = stack.top.next;
                    break;
                case 3:
                    if (stack.top == null) {
                        System.out.println("\n~~Stack is Empty~~\n");
                    } else {
                        System.out.format("\nData Element:- %d\n", stack.top.data);
                    }
                    break;
                case 4:
                    if (stack.top == null) {
                        System.out.println("\n~~Stack is Empty~~\n");
                    } else {
                        System.out.println("\n~~Stack is Not Empty~~\n");
                    }
                    break;
                case 5:
                    if (stack.top == null) {
                        System.out.println("\n~~Stack is Empty~~\n");
                        break;
                    }

                    LinkedStack current = stack.top;
                    System.out.print("\nLinked Stack: ");
                    while (current != null) {
                        System.out.format("%d ", current.data);
                        current = current.next;
                    }
                    System.out.print("\n\n");
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
