queue = [];
front = 0;
rear = -1;
capacity = 5;

print("Hello! Here You Can Perform Following Queue Operation!");
while (True) :
    print("1. En-Queue(Insert a Element at rear)\n2. De-Queue(Delete a Element at front)\n3. Peek(Show's Element in the Front)\n4. Is Empty(Checks Queue is Empty)\n5. Is Full(Checks Queue is Full)\n6. Exit");
    choice = int(input("Enter Your Choice:- "));
    if(choice == 1):
        if (rear == capacity - 1):
            print("\n~~ Queue is Full ~~\n");
            continue;
        rear += 1;
        val = int(input("\nEnter Your Number:-"));
        queue.insert(rear, val);
        print("Insertion Successfull:- ", val, "\n");
        continue;
    elif(choice == 2):
        if (front > rear):
            print("\n~~ Queue is Empty ~~\n");
            continue;
        print("\nDeletion Successfull:- ", queue[front], "\n");
        front += 1;
        if(rear == capacity - 1 and front > rear):
            front = 0;
            rear = -1;
            print("^^Resetting Queue\n");
        continue;
    elif(choice == 3):
        if (front > rear):
            print("\n~~ Queue is Empty ~~\n");
        else: 
            print("\nData Element:- ", queue[front], "\n");
        continue;
    elif(choice == 4):
        if (front > rear):
            print("\n~~ Queue is Empty ~~\n");
        else: 
            print("\n~~ Queue is Not Empty ~~\n");
        continue;
    elif(choice == 5):
        if (rear == capacity - 1):
            print("\n~~ Queue is Full ~~\n");
        else: 
            print("\n~~ Queue is Not Full ~~\n");
        continue;
    elif(choice == 6):
        print("\n~~ Thanks For Using! Have a Great Day! ~~\n");
        break;
    else:
        print("\n~~ Please Enter a Vaild Input! ~~\n");
        continue;