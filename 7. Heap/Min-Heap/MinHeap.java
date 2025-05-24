import java.util.Scanner;

public class MinHeap {
    private int[] arr;
    private int arrayLength;

    public MinHeap() {
        arr = new int[10]; // Initial capacity
        arrayLength = 0;
    }

    private void ensureCapacity() {
        if (arrayLength == arr.length) {
            int[] newArr = new int[arr.length * 2];
            System.arraycopy(arr, 0, newArr, 0, arrayLength);
            arr = newArr;
        }
    }

    public int getParent(int i) {
        return (i - 1) / 2;
    }

    // Returns the index of the left child.
    public int getLeftChild(int i) {
        return (2 * i + 1);
    }

    // Returns the index of the right child.
    public int getRightChild(int i) {
        return (2 * i + 2);
    }

    public void swap(int childIndex, int parentIndex) {
        int temp = arr[childIndex];
        arr[childIndex] = arr[parentIndex];
        arr[parentIndex] = temp;
        return;
    }

    public void heapify(int index) {
        int leftChild = getLeftChild(index);
        int rightChild = getRightChild(index);

        int largest = index;

        if (leftChild < arrayLength && arr[leftChild] < arr[index])
            largest = leftChild;
        if (rightChild < arrayLength && arr[rightChild] < arr[largest])
            largest = rightChild;

        if (largest != index) {
            swap(index, largest);
            heapify(largest);
        }
    }

    public void reversePrint() {
        if (arrayLength == 0) {
            System.out.println("\n~~ Array is Empty! ~~");
        } else {
            System.out.print("\nData (Reverse): ");
            for (int i = arrayLength - 1; i >= 0; i--) {
                System.out.print(arr[i] + (i > 0 ? ", " : "\n"));
            }
        }
    }

    public void peek() {
        if (arrayLength == 0) {
            System.out.print("\n~~ Heap is Empty! ~~\n");
            return;
        }

        int val = arr[0];
        System.out.println("Value: " + val);
    }

    public void insert(Scanner scanner) { // Insert
        ensureCapacity();

        System.out.print("\nEnter Value:- ");

        int val = scanner.nextInt();

        arr[arrayLength++] = val;

        heapify(0);

        System.out.println("Insertion Successful, Value: " + val);
    }

    public void extract(int index) {
        if (arrayLength < index) {
            System.out.print("\n~~ Index Value Not Present! ~~\n");
            return;
        }

        int val = arr[index];
        System.out.println("Extracted Value: " + val);

        arr[index] = arr[arrayLength - 1];

        arrayLength--;
    
        heapify(index);
        return;
    }

   
    public static void main(String[] args) {
        Scanner myObj = new Scanner(System.in);
        MinHeap heap = new MinHeap();

        int choice;
        System.out.println("Hello! Here You Can Perform Following Min Heap Operations!");
        while (true) {
            System.out.print("\n1. View(In Array)\n2. Insert\n3. Extraction of Minimum\n4. Delete at Index\n5. Peek (Get Minimum)\n6. Exit\nEnter Your Choice:-");
            choice = myObj.nextInt();

            switch (choice) {
                case 1:
                    if (heap.arrayLength == 0) {
                        System.out.print("\n~~ Heap is Empty! ~~\n");
                        break;
                    }

                    for (int i = 0; i < heap.arrayLength; i++) {
                        if (i == 0)
                            System.out.print("\nHeap: " + heap.arr[i]);
                        else
                            System.out.print(", " + heap.arr[i]);
                    }
                    break;
                case 2:
                    heap.insert(myObj);
                    break;
                case 3:
                    if (heap.arrayLength == 0) {
                        System.out.print("\n~~ Heap is Empty! ~~\n");
                        break;
                    }

                    heap.extract(0);
                    break;
                case 4:
                    if (heap.arrayLength == 0) {
                        System.out.print("\n~~ Heap is Empty! ~~\n");
                        break;
                    }

                    System.out.print("\nInsert Index(Starts with 0):- ");
                    int index = myObj.nextInt();
                    heap.extract(index);
                    break;
                case 5:
                    heap.peek();
                    break;
                case 6:
                    System.out.println("\nThanks for Using! Have a Great Day!");
                    myObj.close();
                    return;
                default:
                    System.out.println("\nPlease Enter a Valid Input!");
            }
        }
    }
}
