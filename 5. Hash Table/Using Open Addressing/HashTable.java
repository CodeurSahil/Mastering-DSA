import java.util.Scanner;

public class HashTable {
    private static final int EMPTY = -1;
    private static final int TABLE_SIZE = 10;
    private int[] valueHash;
    private int[] keyHash;

    public HashTable() {
        valueHash = new int[TABLE_SIZE];
        keyHash = new int[TABLE_SIZE];

        for (int i = 0; i < TABLE_SIZE; i++) {
            keyHash[i] = -1;
            valueHash[i] = -1;
        }
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
        int originalIndex = index;

        while (true) {
            if (keyHash[index] == key) {
                System.out.print("\nDuplicate Key Already Exists!\n1. Update\n2. Skip\nEnter Choice: ");
                int choice = scanner.nextInt();
                if (choice == 1) {
                    valueHash[index] = value;
                    System.out.println("\nUpdate Successful!");
                }
                return;
            }
            index = (index + 1) % TABLE_SIZE;
            if (index == originalIndex) {
                break;
            }
        }

        while (keyHash[index] != EMPTY) {
            index = (index + 1) % TABLE_SIZE;
            if (index == originalIndex) {
                System.out.print("\nHash table is full!\n");
                return;
            }
        }

        keyHash[index] = key;
        valueHash[index] = value;

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
        int originalIndex = index;

        while (true) {
            if (keyHash[index] == key) {
                System.out.println("Value: " + valueHash[index]);
                return;
            }
            index = (index + 1) % TABLE_SIZE;
            if (index == originalIndex) {
                break;
            }
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
        int originalIndex = index;
        
        while (true) {
            if (keyHash[index] == key) {
                valueHash[index] = -1;
                keyHash[index] = -1;
                System.out.println("Deletion Successful!");
                return;
            }
            index = (index + 1) % TABLE_SIZE;
            if (index == originalIndex) {
                break;
            }
        }

        System.out.println("\n~~ Key Not Found ~~");
    }

    public void display() {
        System.out.print("\n");
        for (int i = 0; i < TABLE_SIZE; i++) {
            if(keyHash[i] != EMPTY) {
                System.out.format("(%d, %d)", keyHash[i], valueHash[i]);
            } else {
                System.out.print("NULL");
            }
    
            if (i != TABLE_SIZE - 1) {
                System.out.print(" , ");
            }
        }
        System.out.print("\n");
        return;
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
