class Stack:
    def __init__(self, top):
        self.top = top;
        self.data = [];

class Queue:
    def __init__(self):
        self.primaryStack = Stack(-1);
        self.secondaryStack = Stack(-1);

mainQueue = Queue();

def enQueue(queue):
    num = int(input("\nEnter Your Number:- "));

    queue.primaryStack.data.append(num);
    queue.primaryStack.top += 1;

    print("Insertion Successfull:- " + str(num) + "\n");
    return;

def deQueue(queue):
    if(queue.secondaryStack.top == -1):
        while (queue.primaryStack.top != -1):
            queue.secondaryStack.data.append(queue.primaryStack.data.pop());
            queue.secondaryStack.top += 1;
            queue.primaryStack.top -= 1;

    if (queue.secondaryStack.top == -1):
        print("\n~~ Queue is Empty! ~~\n");
        return;

    removedVal = queue.secondaryStack.data.pop();
    queue.secondaryStack.top -= 1;

    print("\nData Removed:- " + str(removedVal) + "\n");
    return;

print("Hello! Here You Can Perform Following Queue Operation!");
while (True) :
    print("1. En-Queue(Insert a Element at rear)\n2. De-Queue(Delete a Element at front)\n3. Peek(Show's Element in the Front)\n4. Is Empty(Checks Queue is Empty)\n5. Exit");
    choice = int(input("Enter Your Choice:- "));
    if(choice == 1):
        enQueue(mainQueue);
        continue;
    elif(choice == 2):
        deQueue(mainQueue);
        continue;
    elif(choice == 3):
        if (mainQueue.primaryStack.top == -1 and mainQueue.secondaryStack.top == -1):
            print("\n~~ Queue is Empty ~~\n");
            continue;
        if(mainQueue.secondaryStack.top != -1):
            print("\nData Element:- ", str(mainQueue.secondaryStack.data[mainQueue.secondaryStack.top]), "\n");
        else: 
            print("\nData Element:- ", str(mainQueue.primaryStack.data[0]), "\n");
        continue;
    elif(choice == 4):
        if (mainQueue.primaryStack.top == -1 and mainQueue.secondaryStack.top == -1):
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