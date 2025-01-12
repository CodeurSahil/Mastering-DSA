import java.util.Scanner;

class Stack {
    int top;
    int[] data;
}

public class SimpleQueue {
    private Stack primaryStack = new Stack();
    private Stack secondaryStack = new Stack();
    int MAX = 5;

    public SimpleQueue(){
        // Initialize the stacks
        primaryStack.top = -1;
        primaryStack.data = new int[MAX];

        secondaryStack.top = -1;
        secondaryStack.data = new int[MAX];
    }

    private void push(Stack souce, int val) {
        souce.data[++souce.top] = val;
        return;
    }

    private int pop(Stack souce) {
        return souce.data[souce.top--];
    }

    private void enQueue(SimpleQueue Queue, Scanner myObj) {
        if (Queue.primaryStack.top == MAX - 1) {
            System.out.print("\n~~ Stack Overflow! ~~\n");
            return;
        }

        while (Queue.primaryStack.top != -1) {
            push(Queue.secondaryStack, pop(Queue.primaryStack));
        }
    
        System.out.print("\nEnter Value:- ");
        int val = myObj.nextInt();
    
        push(Queue.primaryStack, val);
    
        while (Queue.secondaryStack.top != -1) {
            push(Queue.primaryStack, pop(Queue.secondaryStack));
        }

        System.out.format("Insertion Successsfull:- %d\n", val);

        return;
    }

    private void deQueue(SimpleQueue Queue) {
        if (Queue.primaryStack.top == -1) {
            System.err.println("\n~~ Queue is Empty ~~\n");
            return;
        }

        int removedVal = pop(Queue.primaryStack);

        System.out.format("\nDeletion Successsfull:- %d\n", removedVal);
        return;
    }

    public static void main(String[] args) {
        Scanner myObj = new Scanner(System.in);
        SimpleQueue Q = new SimpleQueue();

        int choice;
        System.out.println("Hello! Here You Can Perform Following Queue Operations!");
        while (true) {
            System.out.println("\n1. En-Queue(Insert a Element at rear)\n2. De-Queue(Delete a Element at front)\n3. Peek(Show's Element in the Front)\n4. Is Empty(Checks Queue is Empty)\n5. Exit");
            System.out.print("Enter Your Choice:- ");
            choice = myObj.nextInt();

            switch (choice) {
                case 1:
                    Q.enQueue(Q, myObj);
                    break;
                case 2:
                    Q.deQueue(Q);
                    break;
                case 3:
                    if (Q.primaryStack.top == -1) {
                        System.err.println("\n~~ Queue is Empty ~~\n");
                    } else {
                        System.out.format("\nData Element:- %d\n", Q.primaryStack.data[Q.primaryStack.top]);
                    }
                    break;
                case 4:
                    if (Q.primaryStack.top == -1) {
                        System.err.println("\n~~ Queue is Empty ~~\n");
                    } else {
                        System.err.println("\n~~ Queue is Not Empty ~~\n");
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
