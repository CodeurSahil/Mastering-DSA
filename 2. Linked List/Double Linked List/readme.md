# Doubly Linked List (DLL)
**A Doubly Linked List (DLL)** is a type of linked list in which each node contains three parts:
1. Data: The actual information stored in the node.
1. Prev: A pointer/reference to the previous node.
1. Next: A pointer/reference to the next node.

This structure allows traversal in both directions (forward and backward), making it more flexible than a singly linked list.

Representation of DLL:
    ![Repesentaion of Linked List](/assets/representationOfDoublyLinkedList.png)
- Head(A): Points to the first node of the list, where Prev is null.
- Tail(D): Points to the last node of the list, where Next is null.

## Features of DLL
1. Bidirectional Traversal:
    - Can traverse the list both forwards and backwards.
1. Dynamic Size:
    - Can grow or shrink dynamically without the need for resizing.
1. More Memory:
    - Requires extra memory for the Prev pointer.

## Basic Operations on DLL
1. **Traversal**

    1. Forward Traversal:
        - Start at the head.
        - Visit the current node.
        - Move to the next node using the Next pointer.
        - Stop when Next is null.

    1. Backward Traversal:
        - Start at the tail.
        - Visit the current node.
        - Move to the previous node using the Prev pointer.
        - Stop when Prev is null.
        
        Complexity: 𝑂(𝑛)

2. **Insertion**

    Insertion can happen in several ways:

    1. At the Beginning:
        - Create a new node.
        - Set its Next to the current head.
        - Update the Prev of the current head to the new node.
        - Update head to the new node.

        Complexity: 𝑂(1)

    1. At the End:
        - Create a new node.
        - Set its Prev to the current tail.
        - Update the Next of the current tail to the new node.
        - Update tail to the new node.

        Complexity: 𝑂(1)

    1. At a Specific Position:
        - Traverse to the desired position.
        - Update the Prev and Next pointers of adjacent nodes to include the new node.

        Complexity: 𝑂(𝑛)

3. **Deletion**

    Deletion can happen in several ways:
    1. From the Beginning:
        - Update the head to point to head.Next.
        - Set Prev of the new head to null.

        Complexity: 𝑂(1)

    1. From the End:
        - Update the tail to point to tail.Prev.
        - Set Next of the new tail to null.

        Complexity: 𝑂(1)

    1. From a Specific Position:
        - Traverse to the node to be deleted.
        - Update the Prev and Next pointers of adjacent nodes to bypass the node.

        Complexity: 𝑂(𝑛)

4. **Search**

    Search for a specific value by traversing the list and comparing each node's data.

    Complexity: 𝑂(𝑛)

5. **Reverse**

    Reverse the direction of traversal by swapping the Prev and Next pointers for all nodes.

    Algorithm:
    - Start with the head.
    - For each node, swap Prev and Next.
    - Update head to the last node after reversal.

        Complexity: 𝑂(𝑛)

## Advantages of Doubly Linked List
1. Bidirectional Traversal: Can move both forward and backward in the list.
1. Efficient Deletions:
    - Can delete a node in 𝑂(1)if the pointer to the node is given.
1. Dynamic Size: Can grow or shrink dynamically.

## Disadvantages of Doubly Linked List
1. More Memory: Each node requires extra memory for the Prev pointer.
1. Complex Implementation: More pointers to manage during insertion and deletion.

## Applications of Doubly Linked List
1. Navigation Systems:
    - Forward and backward navigation in browsers or playlists.
1. Undo/Redo Functionality:
    - Maintaining a history of actions in software.
1. Deque Implementation:
    - Efficient double-ended queues.