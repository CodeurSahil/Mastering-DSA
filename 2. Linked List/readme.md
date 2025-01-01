# Linked List
Linked Lists are a fundamental data structure used in computer science to store and manage collections of data. They provide a dynamic way to store data, allowing for efficient insertion and deletion operations.

A Linked List is a linear data structure where elements, called **nodes**, are linked using pointers. 

Each node consists of:
1. **Data**: The value or information stored in the node.
2. **Pointer** (or Reference or next): A reference to the next node in the sequence.
    ![Repesentaion of Linked List](/assets/representationOfLinkedList.png)

There are three types of Linked List:-
1. Singly Linked List
1. Doubly Linked List
1. Circular Linked List

## Key Operations

1. Traversal
    - Traversal means visiting every node of a LL.
    - In Singly LL, wwe traverse using the next pointer, starting from the head.
    - In Double LL, we can traverse in both forward and backward directions.
    - Complexity: O(n)

2. Insertion
    - Insertion can be beginning, end, or any specific position.
    - In DLL, both prev and next pointers need to be updated.
    - Complexity:
        - At the beginning: O(1)
        - At the end or specific position: O(n)
3. Deletion
    - Removal of a node from the beginning, end, or a specific position.
    - Complexity:
        - At the beginning: O(1)
        - At the end or specific position: O(n)
4. Search
    - Search for an element in the list by traversing.
    - Complexity: O(n)

## Advantages
1. **Dynamic Size:** No need to predefine the size of the list; it grows and shrinks dynamically.
2. **Efficient Insertions/Deletions:** Especially useful for operations where the size or position of data frequently changes.
3. **No Memory Waste:** Unlike arrays, there’s no need for contiguous memory allocation.

## Dis-Advantages
1. **Sequential Access:** To access a node, you must traverse from the head (or tail in DLL).
2. **Higher Memory Overhead:** Additional memory is required for storing pointers.
3. **Complexity:** More complex to implement and manage compared to arrays.

## Applications of Linked Lists
1. **Dynamic Memory Allocation:** Used in operating systems.
2. **Implementation of Data Structures:** Stacks, queues, and graphs.
3. **Navigation Systems:** Used in undo/redo functionality.
4. **Polynomial Representation:** Representing and manipulating polynomials.

