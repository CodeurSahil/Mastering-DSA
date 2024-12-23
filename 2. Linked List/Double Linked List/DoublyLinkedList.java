import java.util.Scanner;

public class DoublyLinkedList {
    private int data;
    private DoublyLinkedList next, prev;

    private int listLenght = 0;
    private DoublyLinkedList head = null, tail = null;

    private DoublyLinkedList createLinkedListNode(int val) {
        try {
            DoublyLinkedList node = new DoublyLinkedList();
            node.data = val;
            node.next = null;
            node.prev = null;
            return node;
        } catch (Exception e) {
            System.out.println("Failed Allocation");
        }
        return null;
    }

    private void insert(int val, int pos) {
        if (pos <= 0 | pos > listLenght + 1) {
            System.out.println("~~ Invalid Position ~~");
        }

        DoublyLinkedList newNode = createLinkedListNode(val);
        // 4 -> 6 -> 9 -> n -> 12 -> 3 -> 3 -> NULL / 7
        // NUll <- 4 <- 6 <- 9 <- n <- 12 <- 3 <- 3 / 7
        if (pos == 1) {
            if (head != null) {
                newNode.next = head;
                head.prev = newNode;
            }

            newNode.prev = null;
            head = newNode;

            if (tail == null) {
                tail = head;
            } else if (tail.prev == null) {
                tail.prev = head;
            }
        } else if (pos == listLenght + 1) {
            newNode.next = null;
            newNode.prev = tail;
            tail.next = newNode;
            tail = newNode;
        }  else {
            DoublyLinkedList dummy = head;
            int i = 1;
            while (i < pos - 1) {
                i++;
                dummy = dummy.next;
            }
            newNode.next = dummy.next;
            newNode.prev = dummy;
            dummy.next.prev = newNode;
            dummy.next = newNode;
        }
        listLenght++;
        System.out.printf("Insertion Successful at Position:- %d. Value:- %d\n\n", pos, val);
    }

    public void delete(int pos) {
        if (pos <= 0 | pos > listLenght) {
            System.out.println("~~ Invalid Position ~~");
        }

        int toBeDeletedValue;
        DoublyLinkedList toBeDeletedNode;
        // 4 -> 6 -> 9 -> n -> 12 -> 3 -> 3 -> NULL / 7
        // NUll <- 4 <- 6 <- 9 <- n <- 12 <- 3 <- 3 / 7
        if (pos == 1) {
            toBeDeletedNode = head;
            toBeDeletedValue = toBeDeletedNode.data;
            head = toBeDeletedNode.next;
            head.prev = null;
        } else if (pos == listLenght) {
            toBeDeletedNode = tail;
            toBeDeletedValue = toBeDeletedNode.data;
            tail = toBeDeletedNode.prev;
            tail.next = null;
        }  else {
            DoublyLinkedList dummy = head;
            int i = 1;
            while (i < pos - 1) {
                i++;
                dummy = dummy.next;
            }
            toBeDeletedNode = dummy.next;
            toBeDeletedValue = toBeDeletedNode.data;
            dummy.next = toBeDeletedNode.next;
            toBeDeletedNode.next.prev = toBeDeletedNode.prev;
        }

        listLenght--;
        System.out.printf("\nDeletion Successful at Position:- %d. Value:- %d\n\n", pos, toBeDeletedValue);
    }

    public void print(DoublyLinkedList list ,boolean reverse){
        if (reverse) {
            String listStr = Integer.toString(list.tail.data);
            DoublyLinkedList dum = list.tail;
            while (dum.prev != null) {
                dum = dum.prev;
                listStr = listStr + " -> " + Integer.toString(dum.data);
            }
            System.out.printf("\nLinked List(Reverse):- %s -> NULL\n\n", listStr);
        } else {
            String listStr = Integer.toString(list.head.data);
            DoublyLinkedList dum = list.head;
            while (dum.next != null) {
                dum = dum.next;
                listStr = listStr + " -> " + Integer.toString(dum.data);
            }
            System.out.printf("\nLinked List:- %s -> NULL\n\n", listStr);
        }
    }

    public static void main(String[] args) {
        Scanner myObj = new Scanner(System.in);
        DoublyLinkedList list = new DoublyLinkedList();

        int choice, val, pos;
        System.out.println("Hello! Here You Can Perform Following Linked List Operations!");
        while (true) {
            System.out.println("1. Show Data\n2. Show Data(Reverse)\n3. Insert at First\n4. Insert At Last");
            System.out.println("5. Insert at Specific Position\n6. Remove From First\n7. Remove From Last");
            System.out.println("8. Remove From Specific Position\n9. Length of Data\n10. Exit");
            System.out.print("Enter Your Choice: ");
            choice = myObj.nextInt();

            switch (choice) {
                case 1:
                    if (list.listLenght == 0) {
                        System.out.println("\n~~Linked List is Empty~~\n");
                        break;
                    }
                    list.print(list, false);
                    break;
                case 2:
                    if (list.listLenght == 0) {
                        System.out.println("\n~~Linked List is Empty~~\n");
                        break;
                    }
                    list.print(list, true);
                    break;
                case 3:
                    System.out.print("\nEnter Number: ");
                    val = myObj.nextInt();
                    list.insert(val, 1);
                    break;
                case 4:
                    System.out.print("\nEnter Number: ");
                    val = myObj.nextInt();
                    list.insert(val, list.listLenght + 1);
                    break;
                case 5:
                    System.out.print("\nEnter Number: ");
                    val = myObj.nextInt();
                    System.out.print("Enter Position(Greater than 0): ");
                    pos = myObj.nextInt();
                    list.insert(val, pos);
                    break;
                case 6:
                    if (list.listLenght == 0) {
                        System.out.println("\n~~Linked List is Empty~~\n");
                        break;
                    }
                    list.delete(1);
                    break;
                case 7:
                    if (list.listLenght == 0) {
                        System.out.println("\n~~Linked List is Empty~~\n");
                        break;
                    }
                    list.delete(list.listLenght);
                    break;
                case 8:
                    if (list.listLenght == 0) {
                        System.out.println("\n~~Linked List is Empty~~\n");
                        break;
                    }
                    System.out.print("\nEnter Position(Greater than 0): ");
                    pos = myObj.nextInt();
                    list.delete(pos);
                    break;
                case 9:
                    System.out.printf("\nLinked List Length: %d\n\n", list.listLenght);
                    break;
                case 10:
                    System.out.println("\n~~Thanks for Using! Have a Great Day!~~");
                    myObj.close();
                    return;
                default:
                    System.out.println("\nPlease Enter a Valid Input!");
            }
        }
    }
}
