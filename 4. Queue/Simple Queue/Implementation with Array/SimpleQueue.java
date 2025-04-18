
import java.util.Scanner;

public class SimpleQueue {
    private int[] queue = new int[5];
    private int front = 0;
    private int rear = -1;
    private int capacity = 5;

    private void enQueue(int val) {
        rear++;
        queue[rear] = val;

        System.out.format("Insertion Successsfull:- %d\n", val);

        return;
    }

    private void deQueue() {
        if (front > rear) {
            System.err.println("\n~~ Queue is Empty ~~\n");
            return;
        }

        System.out.format("\nDeletion Successsfull:- %d\n", queue[front]);
        front++;

        if (rear == capacity - 1 & front > rear) {
            front = 0;
            rear = -1;
            System.err.println("\n*Resetting Queue\n");
        }

        return;
    }

    public static void main(String[] args) {
        Scanner myObj = new Scanner(System.in);
        SimpleQueue Q = new SimpleQueue();

        int choice;
        System.out.println("Hello! Here You Can Perform Following Queue Operations!");
        while (true) {
            System.out.println("\n1. En-Queue(Insert a Element at rear)\n2. De-Queue(Delete a Element at front)\n3. Peek(Show's Element in the Front)\n4. Is Empty(Checks Queue is Empty)\n5. Is Full(Checks Queue is Full)\n6. Exit");
            System.out.print("Enter Your Choice:- ");
            choice = myObj.nextInt();

            switch (choice) {
                case 1:
                    if (Q.rear == Q.capacity - 1) {
                        System.err.println("\n~~ Queue is Full ~~\n");
                        break;
                    }
                    System.err.print("\n");
                    System.err.print("Enter Value:- ");
                    int val = myObj.nextInt();
                    Q.enQueue(val);
                    break;
                case 2:
                    Q.deQueue();
                    break;
                case 3:
                    if (Q.front > Q.rear) {
                        System.err.println("\n~~ Queue is Empty ~~\n");
                    } else {
                        System.out.format("\nData Element:- %d\n", Q.queue[Q.front]);
                    }
                    break;
                case 4:
                    if (Q.front > Q.rear) {
                        System.err.println("\n~~ Queue is Empty ~~\n");
                    } else {
                        System.err.println("\n~~ Queue is Not Empty ~~\n");
                    }
                    break;
                case 5:
                    if (Q.rear == Q.capacity - 1) {
                        System.err.println("\n~~ Queue is Full ~~\n");
                    } else {
                        System.err.println("\n~~ Queue is Not Full ~~\n");
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
