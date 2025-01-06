top = None;

class linkedStack:
    def __init__(self, data, next):
        self.data = data;
        self.next = next;

def createNode(val):
    newNode = linkedStack(val, None);
    return newNode;

print("Hello! Here You Can Perform Following tack Operation!");
while (True) :
    print("1. Push(Insert)\n2. Pop(Delete)\n3. Peek(See Last Element)\n4. Is Empty(Checks weather Stack is Empty)\n5. Display All Elements\n6. Exit");
    choice = int(input("Enter Your Choice:- "));
    if(choice == 1):
        val = int(input("\nEnter Your Number:-"));
        newNode = createNode(val);
        newNode.next = top;
        top = newNode;
        print("Insertion Successfull:- ", val, "\n");
        continue;
    elif(choice == 2):
        if (top == None):
            print("\n~~ Stack is Empty ~~\n");
            continue;
        print("\nDeletion Successfull:- ", top.data, "\n");
        top = top.next;
        continue;
    elif(choice == 3):
        if (top == None):
            print("\n~~ Stack is Empty ~~\n");
        else: 
            print("\nData Element:- ", top.data, "\n");
        continue;
    elif(choice == 4):
        if (top == None):
            print("\n~~ Stack is Empty ~~\n");
        else: 
            print("\n~~ Stack is Not Empty ~~\n");
        continue;
    elif(choice == 5):
        if (top == None):
            print("\n~~ Stack is Empty ~~\n");
            continue;
        current = top;
        print("\nLinked Stack: ");
        while(current != None):
            print(current.data, " ");
            current = current.next;
        print("\n");
        continue;
    elif(choice == 6):
        print("\n~~ Thanks For Using! Have a Great Day! ~~\n");
        break;
    else:
        print("\n~~ Please Enter a Vaild Input! ~~\n");
        continue;