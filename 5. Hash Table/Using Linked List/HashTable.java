import java.util.Scanner;

class Node {
    int key;
    int value;
    Node next;

    public Node(int key, int value) {
        this.key = key;
        this.value = value;
        this.next = null;
    }
}

public class HashTable {
    private static final int TABLE_SIZE = 10;
    private Node[] hashTable;

    public HashTable() {
        hashTable = new Node[TABLE_SIZE];
    }

    private int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

    public void insert(Scanner scanner) {
        System.out.print("\nEnter Key: ");
        int key = scanner.nextInt();

        if (key < 1) {
            System.out.println("\nInvalid Key!");
            return;
        }

        System.out.print("Enter Value: ");
        int value = scanner.nextInt();

        int index = hashFunction(key);
        Node temp = hashTable[index];

        while (temp != null) {
            if (temp.key == key) {
                System.out.print("\nDuplicate Key Already Exists!\n1. Update\n2. Skip\nEnter Choice: ");
                int choice = scanner.nextInt();
                if (choice == 1) {
                    temp.value = value;
                    System.out.println("\nUpdate Successful!");
                }
                return;
            }
            temp = temp.next;
        }

        Node newNode = new Node(key, value);
        newNode.next = hashTable[index]; // Insert at head
        hashTable[index] = newNode;

        System.out.println("\nInsertion Successful!");
    }

    public void search(Scanner scanner) {
        System.out.print("\nEnter Key: ");
        int key = scanner.nextInt();

        if (key < 1) {
            System.out.println("\nInvalid Key!");
            return;
        }

        int index = hashFunction(key);
        Node temp = hashTable[index];

        while (temp != null) {
            if (temp.key == key) {
                System.out.println("Value: " + temp.value);
                return;
            }
            temp = temp.next;
        }

        System.out.println("\n~~ Key Not Found ~~");
    }

    public void delete(Scanner scanner) {
        System.out.print("\nEnter Key: ");
        int key = scanner.nextInt();

        if (key < 1) {
            System.out.println("\nInvalid Key!");
            return;
        }

        int index = hashFunction(key);
        Node temp = hashTable[index];
        Node prev = null;

        while (temp != null && temp.key != key) {
            prev = temp;
            temp = temp.next;
        }

        if (temp == null) {
            System.out.println("\n~~ Key Not Found ~~");
            return;
        }

        if (prev == null) {
            hashTable[index] = temp.next;
        } else {
            prev.next = temp.next;
        }

        System.out.println("Deletion Successful!");
    }

    public void display() {
        System.out.print("");
        for (int i = 0; i < TABLE_SIZE; i++) {
            System.out.print("Index " + i + ": ");
            Node temp = hashTable[i];
            while (temp != null) {
                System.out.print("(" + temp.key + ", " + temp.value + ") -> ");
                temp = temp.next;
            }
            System.out.println("NULL");
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        HashTable hash = new HashTable();
        int choice;

        System.out.println("Hello! Here You Can Perform Following Hash Table/Maps Operations!");
        while (true) {
            System.out.println("\n1. Show Data\n2. Insert\n3. Delete With Key\n4. Check Value at a Key\n5. Exit");
            System.out.print("Enter Your Choice: ");
            choice = scanner.nextInt();

            switch (choice) {
                case 1:
                    hash.display();
                    break;
                case 2:
                    hash.insert(scanner);
                    break;
                case 3:
                    hash.delete(scanner);
                    break;
                case 4:
                    hash.search(scanner);
                    break;
                case 5:
                    System.out.println("\n~~ Thanks for Using! Have a Great Day! ~~");
                    scanner.close();
                    return;
                default:
                    System.out.println("\nPlease Enter a Valid Input!");
            }
        }
    }
}
