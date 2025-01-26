queue = [];
priorities = [];
size = 0;

MAX_SIZE = 5;

def isEmpty():
    global size;

    return size == 0;

def enqueue():
    global queue, priorities, size, MAX_SIZE;

    if(size == MAX_SIZE):
        print("\n~~ Queue is Full ~~\n");
        return;

    val = int(input("\nEnter Your Number:- "));
    priority = int(input("Enter Priority:- "));

    index = size - 1;

    while (True):
        if (index >= 0 and priorities[index] < priority):
            queue.insert(index + 1, queue[index]);
            priorities.insert(index + 1, priorities[index]);
            index -= 1;
        else:
            break;

    queue.insert(index + 1, val);
    priorities.insert(index + 1, priority);
    size += 1;

    print("Insertion Successfull:- ", val, "\n");

def dequeue():
    global queue, size;

    if(isEmpty()):
        print("\n~~ Queue is Empty ~~\n");
        return;

    toBeDeletedVal = queue[0];

    for i in range(0, size - 1, 1):
        queue[i] = queue[i + 1];

    size -= 1;

    print("Deletion Successfull:- ", toBeDeletedVal, "\n");

def peek():
    global queue, size;

    if(isEmpty()):
        print("\n~~ Queue is Empty ~~\n");
        return;

    print("\nData Element:- ", queue[0], "\n");


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