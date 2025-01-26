import java.util.Scanner;

public class PriorityQueue {
    private int MAX_SIZE = 5;

    private int[] queue = new int[MAX_SIZE];
    private int[] priorities = new int[MAX_SIZE];
    private int size = 0;

    private void enQueue(PriorityQueue pq, Scanner myObj) {
        if (pq.size == pq.MAX_SIZE) {
            System.err.println("\n~~ Queue is Full ~~\n");
            return;
        }

        System.err.print("\n");
        System.err.print("Enter Value:- ");
        int val = myObj.nextInt();

        System.err.print("Enter Priority:- ");
        int priority = myObj.nextInt();

        int i;
        for (i = pq.size - 1; i >= 0 && pq.priorities[i] < priority; i--) {
            pq.queue[i + 1] = pq.queue[i];
            pq.priorities[i + 1] = pq.priorities[i];
        }

        pq.queue[i + 1] = val;
        pq.priorities[i + 1] = priority;
        pq.size++;

        System.out.format("Insertion Successsfull:- %d\n", val);
        return;
    }

    private void deQueue(PriorityQueue pq) {
        if (isEmpty(pq)) {
            System.err.println("\n~~ Queue is Empty ~~\n");
            return;
        }

        int toBeDeletedData = pq.queue[0];

        for (int i = 0; i < pq.size - 1; i++) {
            pq.queue[i] = pq.queue[i + 1];
            pq.priorities[i] = pq.priorities[i + 1];
        }
        pq.size--;

        System.out.format("\nDeletion Successsfull:- %d\n", toBeDeletedData);
        return;
    }

    private boolean isEmpty(PriorityQueue pq) {
        return pq.size == 0;
    }

    private void peek(PriorityQueue pq) {
        if (isEmpty(pq)) {
            System.err.println("\n~~ Queue is Empty ~~\n");
            return;
        }

        System.out.format("\nData Element:- %d\n", pq.queue[0]);
        return;
    }

    public static void main(String[] args) {
        Scanner myObj = new Scanner(System.in);
        PriorityQueue Q = new PriorityQueue();

        int choice;
        System.out.println("Hello! Here You Can Perform Following Queue Operations!");
        while (true) {
            System.out.println(
                    "\n1. En-Queue(Insert a Element at rear)\n2. De-Queue(Delete a Element at front)\n3. Peek(Show's Element in the Front)\n4. Is Empty(Checks Queue is Empty)\n5. Exit");
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
                    Q.peek(Q);
                    break;
                case 4:
                    if (Q.isEmpty(Q)) {
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
