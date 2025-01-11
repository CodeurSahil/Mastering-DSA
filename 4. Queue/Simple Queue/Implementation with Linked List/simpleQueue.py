class node:
    def __init__(self, data):
        self.data = data;
        self.next = None;

front = None;
rear = None;

print("Hello! Here You Can Perform Following Queue Operation!");
while (True) :
    print("1. En-Queue(Insert a Element at rear)\n2. De-Queue(Delete a Element at front)\n3. Peek(Show's Element in the Front)\n4. Is Empty(Checks Queue is Empty)\n5. Exit");
    choice = int(input("Enter Your Choice:- "));
    if(choice == 1):
        val = int(input("\nEnter Your Number:-"));
        newNode = node(val);
        if (front == None):
            front = newNode;
            rear = newNode;
        else:
            rear.next = newNode;
            rear = newNode;
        print("Insertion Successfull:- ", val, "\n");
        continue;
    elif(choice == 2):
        if (front == None):
            print("\n~~ Queue is Empty ~~\n");
            continue;

        print("\nDeletion Successfull:- ", front.data, "\n");

        front = front.next;

        if (front == None):
            rear = None;

        continue;
    elif(choice == 3):
        if (front == None):
            print("\n~~ Queue is Empty ~~\n");
        else: 
            print("\nData Element:- ", front.data, "\n");
        continue;
    elif(choice == 4):
        if (front == None):
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