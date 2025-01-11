
import java.util.Scanner;

public class SimpleQueue {
    private int data;
    private SimpleQueue next;

    private SimpleQueue front = null;
    private SimpleQueue rear = null;

    private SimpleQueue createNode(int val) {
        try{
            SimpleQueue node = new SimpleQueue();
            node.data = val;
            node.next = null;
            return node;
        } catch(Exception e) {
            System.out.println("Failed");
        }
        return null;
    }

    private void enQueue(int val) {
        SimpleQueue newNode = createNode(val);

        if (front == null) {
            front = newNode;
            rear = newNode;
        } else {
            rear.next = newNode;
            rear = newNode;
        }

        System.out.format("Insertion Successsfull:- %d\n", val);
        return;
    }

    private void deQueue() {
        if (front == null) {
            System.err.println("\n~~ Queue is Empty ~~\n");
            return;
        }

        System.out.format("\nDeletion Successsfull:- %d\n", front.data);

        front = front.next;

        if (front == null) {
            rear = null;
        }

        return;
    }

    public static void main(String[] args) {
        Scanner myObj = new Scanner(System.in);
        SimpleQueue Q = new SimpleQueue();

        int choice;
        System.out.println("Hello! Here You Can Perform Following Queue Operations!");
        while (true) {
            System.out.println("1. En-Queue(Insert a Element at rear)\n2. De-Queue(Delete a Element at front)\n3. Peek(Show's Element in the Front)\n4. Is Empty(Checks Queue is Empty)\n5. Exit");
            System.out.print("Enter Your Choice:- ");
            choice = myObj.nextInt();

            switch (choice) {
                case 1:
                    System.err.print("\n");
                    System.err.print("Enter Value:- ");
                    int val = myObj.nextInt();
                    Q.enQueue(val);
                    break;
                case 2:
                    Q.deQueue();
                    break;
                case 3:
                    if (Q.front == null) {
                        System.err.println("\n~~ Queue is Empty ~~\n");
                    } else {
                        System.out.format("\nData Element:- %d\n", Q.front.data);
                    }
                    break;
                case 4:
                    if (Q.front == null) {
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
