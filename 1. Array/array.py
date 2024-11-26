arr = [];

print("Hello! Here You Can Perform Following Array Operation!");
while (True) :
    print("1. Show Data\n2. Show in Reverse\n3. Insert At Last\n4. Insert at Specific Position\n5. Remove From Last\n6. Remove From Specific Position\n7. Lenght of Data\n8. Exit");
    choice = int(input("Enter Your Choice:- "));
    if(choice == 1):
        if (len(arr) == 0):
            print("\n~~ Array is Empty ~~\n");
            continue;
        arrstring = ''
        for x in arr:
            if (arrstring == ''):
                arrstring = str(x);
            else:
                arrstring = arrstring + ', ' + str(x);
        print("\nData - ", arrstring, "\n");
        continue;
    elif(choice == 2):
        if (len(arr) == 0):
            print("\n~~ Array is Empty ~~\n");
            continue;
        reverseArr = arr[::-1];
        arrstring = ''
        for x in reverseArr:
            if (arrstring == ''):
                arrstring = str(x);
            else:
                arrstring = arrstring + ', ' + str(x);
        print("\nData(Reverse) - ", arrstring, "\n");
        continue;
    elif(choice == 3):
        num = int(input("\nEnter Your Number:- "));
        arr.append(num);
        print("Insertion Successfull - ", num, "\n");
        continue;
    elif(choice == 4):
        num = int(input("\nEnter Your Number:- "));
        pos = int(input("Enter Your Position(Greater Than 0):- "));
        if (pos <= 0 or pos > len(arr)):
            print("\n~~ Invalid Position ~~\n");
            continue;
        arr.insert(pos - 1, num);
        print("Insertion Successfull at ", pos," with value ", num, "\n");
        continue;
    elif(choice == 5):
        if (len(arr) == 0):
            print("\n~~ Array is Empty ~~\n");
            continue;
        print("\nDeletion Successfull - ", arr.pop(), "\n");
        continue;
    elif(choice == 6):
        pos = int(input("\nEnter Your Position(Greater Than 0):- "));
        if (pos <= 0 or pos > len(arr)):
            print("\n~~ Invalid Position ~~\n");
            continue;
        print("Deletion Successfull - ", arr.pop(pos - 1), "\n");
        continue;
    elif(choice == 7):
        print("\nArray Lenght - ", len(arr), "\n");
        continue;
    elif(choice == 8):
        print("\n~~ Thanks For Using! Have a Great Day! ~~\n");
        break;
    else:
        print("\n~~ Please Enter a Vaild Input! ~~\n");
        continue;
    
