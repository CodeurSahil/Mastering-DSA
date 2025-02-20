data = [];
front = -1; 
rear = -1; 

MAX_SIZE = 5;

def isEmpty():
    global front;

    return front == -1;

def isFull():
    global front, rear, MAX_SIZE;

    return (front == 0 & rear == MAX_SIZE - 1) | front == rear + 1;

def enqueue(type):
    global data, front, rear, MAX_SIZE;

    if(isFull()):
        print("\n~~ Queue is Full ~~\n");
        return;

    val = int(input("\nEnter Your Number:- "));

    if (isEmpty()):
        front = rear = 0;
        data.insert(front, val);
    elif (type == "FRONT"):
        if (front == 0):
            front = MAX_SIZE - 1;
        else:
            front -= 1;
        data.insert(front, val);
    elif (type == "REAR"):
        if (rear == MAX_SIZE - 1):
            rear = 0;
        else:
            rear += 1;
        data.insert(rear, val);

    print("Insertion Successfull:- ", val, "\n");

def dequeue(type):
    global data, front, rear;

    if(isEmpty()):
        print("\n~~ Queue is Empty ~~\n");
        return;

    toBeDeletedVal = data[front];

    if (front == rear):
        front = rear = -1; # Reset queue
    else:
        if (front == MAX_SIZE - 1):
            front = 0;
        else:
            front += 1;

    print("Deletion Successfull:- ", toBeDeletedVal, "\n");

def peek(type):
    global queue, size;

    if(isEmpty()):
        print("\n~~ Queue is Empty ~~\n");
        return;

    peekVal = 0;

    if (type == "FRONT"):
        peekVal = data[front];
    elif (type == "REAR"):
        peekVal = data[rear];

    print("\nData Element:- ", queue[0], "\n");


print("Hello! Here You Can Perform Following Queue Operation!");
while (True) :
    print("1. En-Queue Front\n2. En-Queue Rear\n3. De-Queue(Front)\n4. Peek Front\n5. Peek Rear\n6. Is Empty(Checks Queue is Empty)\n7. Is Full(Checks Queue is Full)\n8. Exit");
    choice = int(input("Enter Your Choice:- "));
    if(choice == 1):
        enqueue("FRONT");
        continue;
    if(choice == 2):
        enqueue("REAR");
        continue;
    elif(choice == 3):
        dequeue();
        continue;
    elif(choice == 4):
        peek("FRONT");
        continue;
    elif(choice == 5):
        peek("REAR");
        continue;
    elif(choice == 6):
        if (isEmpty()):
            print("\n~~ Queue is Empty ~~\n");
        else: 
            print("\n~~ Queue is Not Empty ~~\n");
        continue;
    elif(choice == 7):
        if (isFull()):
            print("\n~~ Queue is Full ~~\n");
        else: 
            print("\n~~ Queue is Not Full ~~\n");
        continue;
    elif(choice == 8):
        print("\n~~ Thanks For Using! Have a Great Day! ~~\n");
        break;
    else:
        print("\n~~ Please Enter a Vaild Input! ~~\n");
        continue;