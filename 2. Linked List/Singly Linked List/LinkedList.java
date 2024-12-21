import java.util.Scanner;

public class LinkedList {
    private int data;
    private LinkedList next;

    private LinkedList head = null;
    private int listLenght = 0;

    private LinkedList createLinkedListNode(int val) {
        try{
            LinkedList node = new LinkedList();
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
        
        LinkedList newNode = createLinkedListNode(val);
// 4 -> 6 -> 9 -> 0 -> 12 -> 3 -> 3 -> NULL / 7
        if(pos == 1){
            newNode.next = head;
            head = newNode;
        } else {
            LinkedList pre = head;
            int i = 1;
            while(i < pos - 1){
                i++;
                pre = pre.next;
            }
            newNode.next = pre.next;
            pre.next = newNode;
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
        } else {
            LinkedList pre = head;
            int i = 1;
            while(i < pos - 1){ // 0
                i++;
                pre = pre.next;
            }
            toBeDeletedValue = pre.next.data;
            pre.next = pre.next.next;
        }
        listLenght--;
        System.out.printf("\nDeletion Successful at Position:- %d. Value:- %d\n\n", pos, toBeDeletedValue);
    }

    public static void main(String[] args) {
        Scanner myObj = new Scanner(System.in);
        LinkedList list = new LinkedList();

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
                    String listStr = Integer.toString(list.head.data);
                    LinkedList dum = list.head;
                    while(dum.next != null){
                        dum = dum.next;
                        listStr = listStr + " -> " + Integer.toString(dum.data);
                    }
                    System.out.printf("\nLinked List:- %s -> NULL\n\n", listStr);
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
                    System.out.println("\nPlease Enter a Valid Input!");
            }
        }
    }
}
