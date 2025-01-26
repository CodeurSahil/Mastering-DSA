queue = [];
priorities = [];
size = 0;

MAX_SIZE = 5;

def isEmpty():
    global size;

    return size == 0;

def findHigestPrriorityIndex():
    global priorities, size;

    highestPriorityIndex = 0;
    for i in range(0, size, 1):
        if (priorities[i] > priorities[highestPriorityIndex]):
            highestPriorityIndex = i;
    return highestPriorityIndex;

def enqueue():
    global queue, priorities, size, MAX_SIZE;

    if(size == MAX_SIZE):
        print("\n~~ Queue is Full ~~\n");
        return;

    val = int(input("\nEnter Your Number:- "));
    priority = int(input("Enter Priority:- "));

    queue.insert(size, val);
    priorities.insert(size, priority);
    size += 1;

    print("Insertion Successfull:- ", val, "\n");

def dequeue():
    global queue, size;

    if(isEmpty()):
        print("\n~~ Queue is Empty ~~\n");
        return;

    highestPriorityIndex = findHigestPrriorityIndex();
    toBeDeletedVal = queue[highestPriorityIndex];

    for i in range(highestPriorityIndex, size - 1, 1):
        queue[i] = queue[i + 1];

    size -= 1;

    print("Deletion Successfull:- ", toBeDeletedVal, "\n");

def peek():
    global queue, size;

    if(isEmpty()):
        print("\n~~ Queue is Empty ~~\n");
        return;

    highestPriorityIndex = findHigestPrriorityIndex();

    print("\nData Element:- ", queue[highestPriorityIndex], "\n");


print("Hello! Here You Can Perform Following Queue Operation!");
while (True) :
    print("1. En-Queue(Insert a Element at rear)\n2. De-Queue(Delete a Element at front)\n3. Peek(Show's Element in the Front)\n4. Is Empty(Checks Queue is Empty)\n5. Exit");
    choice = int(input("Enter Your Choice:- "));
    if(choice == 1):
        enqueue();
        continue;
    elif(choice == 2):
        dequeue();
        continue;
    elif(choice == 3):
        peek();
        continue;
    elif(choice == 4):
        if (isEmpty()):
            print("\n~~ Queue is Empty ~~\n");
        else: 
            print("\n~~ Queue is Not Empty ~~\n");
        continue;
    elif(choice == 5):
        print("\n~~ Thanks For Using! Have a Great Day! ~~\n");
        break;
    else:
        print("\n~~ Please Enter a Vaild Input! ~~\n");
        continue;