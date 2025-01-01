# Circular Singly Linked List (CSLL)
A **Circular Singly Linked List (CSLL)** is a variation of the singly linked list where the last node points back to the first node, forming a circular loop. This allows traversal to continue indefinitely through the list.

In a CSLL, each node contains:
1. Data: The actual information stored in the node.
1. Next: A reference to the next node.

![Repesentaion of Circular Singly Linked List](/assets/representationOfCircularSinglyLinkedList.webp)

## Key Features
1. Circular Nature:
    - The Next pointer of the last node points to the head, creating a circular structure.
1. No Null Pointers:
    - Unlike a standard singly linked list, there is no null in the Next pointer of any node.
1. Dynamic Size:
    - Can grow or shrink dynamically as nodes are added or removed.
1. Traversal:
    - Starts from any node and continues indefinitely in the loop.


## Operations on Circular Singly Linked List
1. Traversal

    Traversal in a CSLL involves visiting each node starting from the head.

    Algorithm:

    - Start at the head.
    - Print or process the data in the current node.
    - Move to the next node using the Next pointer.
    - Stop when you reach the head again.

    Complexity: 𝑂(𝑛)

2. Insertion

    Insertion can happen in three ways:

    1. At the Beginning:
        - Create a new node.
        - Make its Next point to the current head.
        - Traverse the list to the last node and update its Next to the new     node.
        - Update the head to the new node.

        Complexity: 𝑂(𝑛)

    1. At the End:
        - Create a new node.
        - Traverse to the last node.
        - Make the Next of the last node point to the new node.
        - Make the Next of the new node point to the head.

        Complexity: 𝑂(𝑛)

    1. At a Specific Position:
        - Traverse to the desired position.
        - Update the Next pointers to include the new node.

        Complexity: 𝑂(𝑛)

3. Deletion

    Deletion can happen in three ways:

    1. From the Beginning:

        - Update the head to the second node.
        - Traverse to the last node and update its Next to the new head.

        Complexity: 𝑂(𝑛)

    1. From the End:

        - Traverse to the second-last node.
        - Update its Next to point to the head.

        Complexity: 𝑂(𝑛)

    1. From a Specific Position:

        - Traverse to the node just before the one to be deleted.
        - Update its Next pointer to skip the node to be deleted.

        Complexity: 𝑂(𝑛)

4. Search

    Search for a specific value by traversing the list and comparing each node's data.

    Complexity: 𝑂(𝑛)

## Advantages of CSLL
1. Efficient Traversal:
    - Since the list is circular, you can traverse all nodes starting from any node without needing a special end condition.
1. Constant Access to All Nodes:
    - The circular nature ensures you can always get back to the starting point.
1. Suitable for Round-Robin Algorithms:
    - Used in scheduling algorithms like CPU time-sharing.

## Disadvantages of CSLL
1. Complex Traversal:
    - Care is required to avoid infinite loops while traversing.
1. Complex Implementation:
    - Requires additional checks to handle circular references, especially during insertion and deletion.
1. No Backtracking:
    - Like a singly linked list, it only allows forward traversal.

## Applications of CSLL
1. Round-Robin Scheduling:
    - Used in CPU scheduling algorithms to cycle through processes.
1. Buffer Management:
    - Used in buffering mechanisms like streaming.
1. Data Structures:
    - Forms the basis for other structures like circular queues.
