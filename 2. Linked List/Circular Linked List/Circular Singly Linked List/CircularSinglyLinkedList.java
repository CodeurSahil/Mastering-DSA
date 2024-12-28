import java.util.Scanner;

public class CircularSinglyLinkedList {
    private int data;
    private CircularSinglyLinkedList next;

    private CircularSinglyLinkedList head = null;
    private CircularSinglyLinkedList last = null;
    private int listLenght = 0;

    private CircularSinglyLinkedList createLinkedListNode(int val) {
        try{
            CircularSinglyLinkedList node = new CircularSinglyLinkedList();
            node.data = val;
            node.next = null;
            return node;
        } catch(Exception e) {
            System.out.println("Failed");
        }
        return null;
    }

    private void insert(int val, int pos) {
        if(pos <= 0 | pos > listLenght + 1){
            System.out.println("~~ Invalid Position ~~");
        }
        
        CircularSinglyLinkedList newNode = createLinkedListNode(val);
// 4 -> 6 -> 9 -> 0 -> 12 -> 3 -> 3 -> NULL / 7
        if(pos == 1){
            newNode.next = head;
            head = newNode;

            if (head.next == null) {
                head.next = head;
            }

            if (last == null) {
                last = head;
            }

            last.next = head;
        } else {
            CircularSinglyLinkedList pre = head;
            int i = 1;
            while(i < pos - 1){
                i++;
                pre = pre.next;
            }
            newNode.next = pre.next;
            pre.next = newNode;
            if (pre == last) {
                last = newNode;
            }
        }
        listLenght++;
        System.out.printf("Insertion Successful at Position:- %d. Value:- %d\n\n", pos, val);
    }

    public void delete(int pos) {
        if(pos <= 0 | pos > listLenght){
            System.out.println("~~ Invalid Position ~~");
        }

        int toBeDeletedValue;
        // 3 -> 2 -> 12 -> 0 -> NULL
        if(pos == 1){
            toBeDeletedValue = head.data;
            head = head.next;
            last.next = head;
        } else {
            CircularSinglyLinkedList pre = head;
            int i = 1;
            while(i < pos - 1){ // 0
                i++;
                pre = pre.next;
            }
            toBeDeletedValue = pre.next.data;

            if (pre.next == last) {
                last = pre;
            }

            pre.next = pre.next.next;
        }
        listLenght--;
        System.out.printf("\nDeletion Successful at Position:- %d. Value:- %d\n\n", pos, toBeDeletedValue);
    }

    public static void main(String[] args) {
        Scanner myObj = new Scanner(System.in);
        CircularSinglyLinkedList list = new CircularSinglyLinkedList();

        int choice, val, pos;
        System.out.println("Hello! Here You Can Perform Following Linked List Operations!");
        while (true) {
            System.out.println("1. Show Data\n2. Insert at First\n3. Insert At Last");
            System.out.println("4. Insert at Specific Position\n5. Remove From First\n6. Remove From Last");
            System.out.println("7. Remove From Specific Position\n8. Length of Data\n9. Exit");
            System.out.print("Enter Your Choice: ");
            choice = myObj.nextInt();
            
            switch (choice) {
                case 1:
                    if(list.listLenght == 0){
                        System.out.println("\n~~Linked List is Empty~~\n");
                        break;
                    }
                    String listStr = "";
                    CircularSinglyLinkedList dum = list.head;
                    do {
                        listStr = listStr + Integer.toString(dum.data) + " -> ";
                        dum = dum.next;
                    } while(dum != list.head);
                    System.out.printf("\nLinked List:- %s%d(HEAD)\n\n", listStr, list.head.data);
                    break;
                case 2:
                    System.out.print("\nEnter Number: ");
                    val = myObj.nextInt();
                    list.insert(val, 1);
                    break;
                case 3:
                    System.out.print("\nEnter Number: ");
                    val = myObj.nextInt();
                    list.insert(val, list.listLenght + 1);
                    break;
                case 4:
                    System.out.print("\nEnter Number: ");
                    val = myObj.nextInt();
                    System.out.print("Enter Position(Greater than 0): ");
                    pos = myObj.nextInt();
                    list.insert(val, pos);
                    break;
                case 5:
                    if(list.listLenght == 0){
                        System.out.println("\n~~Linked List is Empty~~\n");
                        break;
                    }
                    list.delete(1);
                    break;
                case 6:
                    if(list.listLenght == 0){
                        System.out.println("\n~~Linked List is Empty~~\n");
                        break;
                    }
                    list.delete(list.listLenght);
                    break;
                case 7:
                    if(list.listLenght == 0){
                        System.out.println("\n~~Linked List is Empty~~\n");
                        break;
                    }
                    System.out.print("\nEnter Position(Greater than 0): ");
                    pos = myObj.nextInt();
                    list.delete(pos);
                    break;
                case 8:
                    System.out.printf("\nLinked List Length: %d\n\n", list.listLenght);
                    break;
                case 9:
                    System.out.println("\n~~Thanks for Using! Have a Great Day!~~");
                    myObj.close();
                    return;
                default:
                    System.out.println("\n~~Please Enter a Valid Input!~~\n");
            }
        }
    }
}
