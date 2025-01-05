stack = [];
stackPointer = -1;
stackLength = 10;

print("Hello! Here You Can Perform Following tack Operation!");
while (True) :
    print("1. Push(Insert)\n2. Pop(Delete)\n3. Peek(See Last Element)\n4. Is Empty(Checks weather Stack is Empty)\n5. Is Full(Checks weather Stack is Full)\n6. Exit");
    choice = int(input("Enter Your Choice:- "));
    if(choice == 1):
        if (stackPointer + 1 == stackLength):
            print("\n~~ Stack is Full ~~\n");
            continue;
        stackPointer += 1;
        val = int(input("\nEnter Your Number:-"));
        stack.append(val);
        print("Insertion Successfull:- ", val, "\n");
        continue;
    elif(choice == 2):
        if (stackPointer == -1):
            print("\n~~ Stack is Empty ~~\n");
            continue;
        print("\nDeletion Successfull:- ", stack[stackPointer], "\n");
        stackPointer -= 1;
        continue;
    elif(choice == 3):
        if (stackPointer == -1):
            print("\n~~ Stack is Empty ~~\n");
        else: 
            print("\nData Element:- ", stack[stackPointer], "\n");
        continue;
    elif(choice == 4):
        if (stackPointer == -1):
            print("\n~~ Stack is Empty ~~\n");
        else: 
            print("\n~~ Stack is Not Empty ~~\n");
        continue;
    elif(choice == 5):
        if (stackPointer + 1 == stackLength):
            print("\n~~ Stack is Full ~~\n");
        else: 
            print("\n~~ Stack is Not Full ~~\n");
        continue;
    elif(choice == 6):
        print("\n~~ Thanks For Using! Have a Great Day! ~~\n");
        break;
    else:
        print("\n~~ Please Enter a Vaild Input! ~~\n");
        continue;