arr = [];
arrayLength = 0;

def getParent(i):
    return int((i - 1) / 2);

def getLeftChild(i):
    return int((2 * i + 1));

def getRightChild(i):
    return int((2 * i + 2));

def swap(childIndex, parentIndex):
    global arr;

    temp = arr[childIndex];
    arr[childIndex] = arr[parentIndex];
    arr[parentIndex] = temp;
    return;

def heapify(index):
    leftChild = getLeftChild(index);
    rightChild = getRightChild(index);

    largest = index;

    if (leftChild < arrayLength and arr[leftChild] < arr[index]):
        
        largest = leftChild;
    if (rightChild < arrayLength and arr[rightChild] < arr[largest]):
        
        largest = rightChild;

    if (largest != index):
        swap(index, largest);
        heapify(largest);

def peek():
    global arr, arrayLength;
    if (arrayLength == 0):
        print("\n~~ Heap is Empty! ~~\n", end="");
        return;

    val = arr[0];
    print("Value: ", val);

def insert():
    global arr, arrayLength;
    val =  int(input("Enter Number:- "));
    
    arr.insert(arrayLength, val);

    index = arrayLength;

    arrayLength += 1;

    while (index != 0 and arr[getParent(index)] > arr[index]):
        
        swap(index, getParent(index));

        index = getParent(index);

    # heapify(0);

    print("Insertion Successful, Value: ", val);

def extract(index):
    global arr, arrayLength;
    if (arrayLength < index):
        print("\n~~ Index Value Not Present! ~~\n", end="");
        return;

    val = arr[index];
    print("Extracted Value: ", val);

    arr[index] = arr[arrayLength - 1];

    arrayLength -= 1;

    heapify(index);
    return;

print("Hello! Here You Can Perform Following Min Heap Operation!");
while (True) :
    print("\n1. View(In Array)\n2. Insert\n3. Extraction of Minimum\n4. Delete at Index\n5. Peek (Get Minimum)\n6. Exit");
    choice = int(input("Enter Your Choice:- "));
    if(choice == 1):
        if (arrayLength == 0):
            print("\n~~ Heap is Empty ~~\n");
            continue;

        arrstring = ''
        for i in range(0, arrayLength, 1):
            if (arrstring == ''):
                arrstring = str(arr[i]);
            else:
                arrstring = arrstring + ', ' + str(arr[i]);
        print("Heap - ", arrstring, "\n");

        continue;
    elif(choice == 2):
        insert();
        continue;
    elif(choice == 3):
        if (arrayLength == 0):
            print("\n~~ Heap is Empty ~~\n");
            continue;
        extract(0);
        continue;
    elif(choice == 4):
        if (arrayLength == 0):
            print("\n~~ Heap is Empty ~~\n");
            continue;
        index = int(input("\nInsert Index(Starts with 0):-  "));

        extract(index);

        continue;
    elif(choice == 5):
        if (arrayLength == 0):
            print("\n~~ Heap is Empty ~~\n");
            continue;
        peek();
        continue;
    elif(choice == 6):
        print("\n~~ Thanks For Using! Have a Great Day! ~~\n");
        break;
    else:
        print("\n~~ Please Enter a Vaild Input! ~~\n");
        continue;
    
