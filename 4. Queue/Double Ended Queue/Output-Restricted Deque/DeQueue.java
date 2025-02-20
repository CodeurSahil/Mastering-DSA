import java.util.Scanner;

public class DeQueue {
    private int MAX_SIZE = 5;

    private int[] data = new int[MAX_SIZE];
    private int front = -1;
    private int rear = -1;

    private boolean isEmpty(DeQueue dq) {
        return dq.front == -1;
    }
    
    private boolean isFull(DeQueue dq) {
        return (dq.front == 0 && dq.rear == MAX_SIZE - 1) || (dq.front == dq.rear + 1);
    }

    private void enQueue(DeQueue dq, Scanner myObj, String type) {
        if (isFull(dq)) {
            System.err.println("\n~~ Queue is Full ~~\n");
            return;
        }

        System.err.print("\n");
        System.err.print("Enter Value:- ");
        int val = myObj.nextInt();

        if (isEmpty(dq)) {
            dq.front = dq.rear = 0;
            dq.data[dq.front] = val;
        } else if (type == "FRONT") {
            if (dq.front == 0) {
                dq.front = MAX_SIZE - 1;
            } else {
                dq.front--;
            }
            dq.data[dq.front] = val;
        } else if (type == "REAR") {
            if (dq.rear == MAX_SIZE - 1) {
                dq.rear = 0;
            } else {
                dq.rear++;
            }
            dq.data[dq.rear] = val;
        }

        System.out.format("Insertion Successsfull:- %d\n", val);
        return;
    }

    private void deQueue(DeQueue dq) {
        if (isEmpty(dq)) {
            System.err.println("\n~~ Queue is Empty ~~\n");
            return;
        }

        int toBeDeletedData = dq.data[dq.front];

        if (dq.front == dq.rear) {
            dq.front = dq.rear = -1; // Reset queue
        } else {
            if (dq.front == MAX_SIZE - 1) {
                dq.front = 0;
            } else {
                dq.front++;
            }
        }

        System.out.format("\nDeletion Successsfull:- %d\n", toBeDeletedData);
        return;
    }

    private void peek(DeQueue dq, String type) {
        if (isEmpty(dq)) {
            System.err.println("\n~~ Queue is Empty ~~\n");
            return;
        }

        int peekVal = 0;

        if (type == "FRONT") {
            peekVal = dq.data[dq.front];
        } else if (type == "REAR") {
            peekVal = dq.data[dq.rear];
        }

        System.out.format("\nData Element:- %d\n", peekVal);
        return;
    }

    public static void main(String[] args) {
        Scanner myObj = new Scanner(System.in);
        DeQueue Q = new DeQueue();

        int choice;
        System.out.println("Hello! Here You Can Perform Following Queue Operations!");
        while (true) {
            System.out.println("1. En-Queue Front\n2. En-Queue Rear\n3. De-Queue(Front)\n4. Peek Front\n5. Peek Rear\n6. Is Empty(Checks Queue is Empty)\n7. Is Full(Checks Queue is Full)\n8. Exit");
            System.out.print("Enter Your Choice:- ");
            choice = myObj.nextInt();

            switch (choice) {
                case 1:
                    Q.enQueue(Q, myObj,"FRONT");
                    break;
                case 2:
                    Q.enQueue(Q, myObj, "REAR");
                    break;
                case 3:
                    Q.deQueue(Q);
                    break;
                case 4:
                    Q.peek(Q, "FRONT");
                    break;
                case 5:
                    Q.peek(Q, "REAR");
                    break;
                case 6:
                    if (Q.isEmpty(Q)) {
                        System.err.println("\n~~ Queue is Empty ~~\n");
                    } else {
                        System.err.println("\n~~ Queue is Not Empty ~~\n");
                    }
                    break;
                case 7:
                    if (Q.isFull(Q)) {
                        System.err.println("\n~~ Queue is Full ~~\n");
                    } else {
                        System.err.println("\n~~ Queue is Not Full ~~\n");
                    }
                    break;
                case 8:
                    System.out.println("\n~~Thanks for Using! Have a Great Day!~~\n");
                    myObj.close();
                    return;
                default:
                    System.out.println("\n~~Please Enter a Valid Input!~~\n");
            }
        }
    }
}
