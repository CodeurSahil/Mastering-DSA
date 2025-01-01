# Circular Doubly Linked List (CDLL)
A **Circular Doubly Linked List (CDLL)** is a variation of the doubly linked list where:

- The last node’s Next pointer points to the first node.
- The first node’s Prev pointer points to the last node.

This circular structure allows traversal of the list in both directions infinitely.

In a CDLL, each node contains:

1. Data: The actual information stored in the node.
1. Prev: A pointer to the previous node.
1. Next: A pointer to the next node.

Representation of Doubly Linked List
    ![Repesentaion of Circular Doubly Linked List](/assets/representationOfCircularDoublyLinkedList.webp)
1. Head: Points to the first node.
1. Tail: The last node points back to the head.

## Key Features
1. Circular Structure:
    - The Prev of the first node points to the last node.
    - The Next of the last node points to the first node.
1. Bidirectional Traversal:
    - Can traverse forward and backward through the list.
1. Dynamic Size:
    - Can grow or shrink dynamically by adding or removing nodes.

## Operations on Circular Doubly Linked List
1. Traversal
    
    Traversal can be done in both directions:

    1. Forward Traversal:
        - Start at the head.
        - Print or process the data.
        - Move to the next node using the Next pointer.
        - Stop when the current node becomes the head again.
    1. Backward Traversal:
        - Start at the tail.
        - Print or process the data.
        - Move to the previous node using the Prev pointer.
        - Stop when the current node becomes the tail again.

        Complexity: 𝑂(𝑛)

2. Insertion

    Insertion can happen in three ways:

    1. At the Beginning:
        - Create a new node.
        - Set its Next to the current head.
        - Set its Prev to the last node.
        - Update the Prev of the current head and the Next of the last node.
        - Update the head pointer.

        Complexity: 𝑂(1)

    1. At the End:
        - Create a new node.
        - Set its Prev to the current tail.
        - Set its Next to the head.
        - Update the Next of the current tail and the Prev of the head.
        - Update the tail pointer.

        Complexity: 𝑂(1)

    1. At a Specific Position:
        - Traverse to the desired position.
        - Adjust the Prev and Next pointers of adjacent nodes to include the new node.

        Complexity: 𝑂(𝑛)

3. Deletion

    Deletion can happen in three ways:

    1. From the Beginning:
        - Update the Next pointer of the last node to point to the second node.
        - Update the Prev pointer of the second node to point to the last node.
        - Update the head pointer.

        Complexity: 𝑂(1)

    1. From the End:
        - Update the Next pointer of the second-last node to point to the head.
        - Update the Prev pointer of the head to point to the second-last node.
        - Update the tail pointer.

        Complexity: 𝑂(1)

    1. From a Specific Position:
        - Traverse to the node to be deleted.
        - Adjust the Prev and Next pointers of adjacent nodes to bypass the node.

        Complexity: 𝑂(n)

4. Search

    Search for a specific value by traversing the list and comparing each node’s data.

    Complexity: 𝑂(𝑛)

5. Reverse

    Reversing the direction of the list:

    - Swap the Prev and Next pointers for each node.
    - Update the head and tail pointers.

    Complexity: 𝑂(𝑛)

## Advantages of CDLL
1. Efficient Bidirectional Traversal:
    - Can traverse both forward and backward without extra logic.
1. No Null Pointers:
    - All Prev and Next pointers are always valid, making it easier to handle boundary cases.
1. Circular Continuity:
    - Good for algorithms requiring continuous iteration, such as resource management or round-robin scheduling.

## Disadvantages of CDLL
1. Increased Complexity:
    - More pointers to manage compared to a singly linked list or a circular singly linked list.
1. More Memory:
    - Each node requires extra space for the Prev pointer.

## Applications of Circular Doubly Linked List
1. Round-Robin Scheduling:
    - Efficient for CPU or process scheduling.
1. Data Buffers:
    - Used in scenarios requiring continuous access to data, like audio or video buffering.
1. Deque Implementation:
    - Useful for implementing double-ended queues.
1. Resource Management:
    - Can manage resources in a circular, fair-access manner.
