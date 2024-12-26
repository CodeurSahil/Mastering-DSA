head = None;
tail = None;
listLength = 0;

class linkedList:
    def __init__(self, data, next, prev):
        self.data = data;
        self.next = next;
        self.prev = prev;

def createLinkedListNode(val, next, prev):
    node = linkedList(val, next, prev);
    global listLength;
    listLength += 1;
    return node;

def insert(val, pos):
    global listLength, head, tail;
    if pos <= 0 | pos > listLength + 1:
        print("\n~~Invalid Position: ", pos, "~~\n");
        return;

    newNode = createLinkedListNode(val, None, None);

    if (pos == 1):
        newNode.next = head;
        head = newNode;
        if (tail == None):
            tail = head;
        elif (tail.prev == None):
            tail.prev = head;
    elif (pos == listLength):
        tail.next = newNode;
        newNode.prev = tail;
        tail = newNode;
        if (head == None):
            head.next = newNode;
    else:
        prev = head;
        i = 1;
        while i < pos - 1:
            i += 1
            prev = prev.next;
        newNode.next = prev.next;
        newNode.prev = prev;
        prev.next.prev = newNode;
        prev.next = newNode;
    print("Insertion Successful at Position:- ", pos, ". Value:- ", val, "\n");

def delete(pos):
    global listLength, head, tail;
    if pos <= 0 | pos > listLength:
        print("\n~~Invalid Position: ", pos, "~~\n");
        return;

    toBeRemovedValue = None;
# 1 -> 7 -> 4 -> 9 -> 0 -> 1 -> N 
    if (pos == 1):
        toBeRemovedValue = head.data;
        head = head.next;
        head.prev = None;
    elif (pos == listLength):
        toBeRemovedValue = tail.data;
        tail = tail.prev;
        tail.next = None;
    else:
        prev = head;
        i = 1;
        while i < pos - 1:
            i += 1
            prev = prev.next;
        toBeRemovedValue = prev.next.data;
        prev.next.next.prev = prev;
        prev.next = prev.next.next;
    listLength -= 1;
    print("Deletion Successful at Position:- ", pos, ". Value:- ", toBeRemovedValue, "\n")

print("Hello! Here You Can Perform Following Linked List Operations!");
while (True) :
    print("1. Show Data\n2. Show Data(Reverse)\n3. Insert at First\n4. Insert at Last\n5. Insert at Specific Position\n6. Remove from First\n7. Remove from Last\n8. Remove from Specific Position\n9. Length of Data\n10. Exit\n");
    choice = int(input("Enter Your Choice:- "));
    if(choice == 1):
        if (head == None):
            print("\n~~ Linked List is Empty ~~\n");
            continue;
        listString = str(head.data);
        dum = head;
        while(dum.next != None):
            dum = dum.next
            listString = listString + ' -> ' + str(dum.data);
        print("\nLinked List:", listString, "-> NULL\n");
        continue;
    elif(choice == 2):
        if (tail == None):
            print("\n~~ Linked List is Empty ~~\n");
            continue;
        listString = str(tail.data);
        dum = tail;
        while(dum.prev != None):
            dum = dum.prev
            listString = listString + ' -> ' + str(dum.data);
        print("\nLinked List(Reverse):", listString, "-> NULL\n");
        continue;
    elif(choice == 3):
        num = int(input("\nEnter Your Number:- "));
        insert(num, 1);
        continue;
    elif(choice == 4):
        num = int(input("\nEnter Your Number:- "));
        insert(num, listLength + 1);
        continue;
    elif(choice == 5):
        num = int(input("\nEnter Your Number:- "));
        pos = int(input("Enter Your Position(Greater Than 0):- "));
        insert(num, pos);
        continue;
    elif(choice == 6):
        print('\n');
        delete(1);
        continue;
    elif(choice == 7):
        print('\n');
        delete(listLength);
        continue;
    elif(choice == 8):
        pos = int(input("\nEnter Your Position(Greater Than 0):- "));
        delete(pos);
        continue;
    elif(choice == 9):
        print("\nList Lenght:- ", listLength, "\n");
        continue;
    elif(choice == 10):
        print("\n~~ Thanks For Using! Have a Great Day! ~~\n");
        break;
    else:
        print("\n~~ Please Enter a Vaild Input! ~~\n");
        continue;
    
