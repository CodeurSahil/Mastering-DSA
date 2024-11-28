import java.util.Scanner;

public class Array {
    private int[] arr;
    private int size;

    public Array() {
        arr = new int[10]; // Initial capacity
        size = 0;
    }

    private void ensureCapacity() {
        if (size == arr.length) {
            int[] newArr = new int[arr.length * 2];
            System.arraycopy(arr, 0, newArr, 0, size);
            arr = newArr;
        }
    }

    public void print() {
        if (size == 0) {
            System.out.println("\n~~ Array is Empty! ~~");
        } else {
            System.out.print("\nData: ");
            for (int i = 0; i < size; i++) {
                System.out.print(arr[i] + (i < size - 1 ? ", " : "\n"));
            }
        }
    }

    public void reversePrint() {
        if (size == 0) {
            System.out.println("\n~~ Array is Empty! ~~");
        } else {
            System.out.print("\nData (Reverse): ");
            for (int i = size - 1; i >= 0; i--) {
                System.out.print(arr[i] + (i > 0 ? ", " : "\n"));
            }
        }
    }

    public void push(int val) { // Insert At Last
        ensureCapacity();
        arr[size] = val;
        size++;
        System.out.println("Insertion Successful. Value: " + val);
    }

    public void pop() { // Remove From Last
        if (size == 0) {
            System.out.println("\n~~ Array is Empty! Cannot Remove ~~");
        } else {
            int delVal = arr[size - 1];
            size--;
            System.out.println("\nRemoved Value: " + delVal);
        }
    }

    public void insertInPlace(int val, int pos) { // Insert at Specific Position
        if (pos <= 0 || pos > size + 1) {
            System.out.println("Invalid Position: " + pos);
        } else {
            ensureCapacity();
            for (int i = size; i >= pos; i--) {
                arr[i] = arr[i - 1];
            }
            arr[pos - 1] = val;
            size++;
            System.out.println("Insertion Successful at Position " + pos + ". Value: " + val);
        }
    }

    public void deleteInPlace(int pos) { // Remove From Specific Position
        if (pos <= 0 || pos > size) {
            System.out.println("Invalid Position: " + pos);
        } else {
            int delVal = arr[pos - 1];
            for (int i = pos - 1; i < size - 1; i++) {
                arr[i] = arr[i + 1];
            }
            size--;
            System.out.println("Removed Value: " + delVal);
        }
    }

    public static void main(String[] args) {
        Scanner myObj = new Scanner(System.in);
        Array A1 = new Array();

        int choice, val, pos;
        System.out.println("Hello! Here You Can Perform Following Array Operations!");
        while (true) {
            System.out.println("1. Show Data\n2. Show in Reverse\n3. Insert At Last");
            System.out.println("4. Insert at Specific Position\n5. Remove From Last");
            System.out.println("6. Remove From Specific Position\n7. Length of Data\n8. Exit");
            System.out.print("Enter Your Choice: ");
            choice = myObj.nextInt();

            switch (choice) {
                case 1:
                    A1.print();
                    break;
                case 2:
                    A1.reversePrint();
                    break;
                case 3:
                    System.out.print("\nEnter Value to Insert: ");
                    val = myObj.nextInt();
                    A1.push(val);
                    break;
                case 4:
                    System.out.print("\nEnter Value and Position to Insert: ");
                    val = myObj.nextInt();
                    pos = myObj.nextInt();
                    A1.insertInPlace(val, pos);
                    break;
                case 5:
                    A1.pop();
                    break;
                case 6:
                    System.out.print("\nEnter Position to Remove: ");
                    pos = myObj.nextInt();
                    A1.deleteInPlace(pos);
                    break;
                case 7:
                    System.out.println("\nData Length: " + A1.size);
                    break;
                case 8:
                    System.out.println("\nThanks for Using! Have a Great Day!");
                    myObj.close();
                    return;
                default:
                    System.out.println("\nPlease Enter a Valid Input!");
            }
        }
    }
}
