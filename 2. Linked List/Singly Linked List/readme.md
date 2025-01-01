# Singly Linked List
A **Singly Linked List**(SLL) is a linear data structure in which each element (called a node) contains data and a pointer/reference to the next node in the sequence. The last node in the list points to null (or None in Python), indicating the end of the list.

Structure of a Singly Linked List, Each node in an SLL contains two components:
1. Data: The actual information stored in the node.
2. Next: A reference (pointer) to the next node in the list.

Representation of Singly Linked List:-
    ![Repesentaion of Singly Linked List](/assets/representationOfLinkedList.png)

## Basic Properties
1. Linear Structure:
    - The nodes are arranged in a linear sequence.
    - Traversal is one-way: from the head to the tail.
1. Dynamic Size:
    - Can grow or shrink dynamically by adding/removing nodes.
1. No Backtracking:
    - Since there is no reference to the previous node, backtracking is not possible.
1. Head:
    - The first node of the list is called the head. It is the entry point to the list.

## Operations on Singly Linked List

1. Traversal
    - Traversal means visiting each node in the list to access or display the data.
    - Algorithm:
        1. Start at the head.
        1. Visit the current node.
        1. Move to the next node using the next pointer.
        1. Repeat until you reach null.
    - Complexity: 𝑂(𝑛)

1. Insertion
    - Insertion can happen in three ways:
    1. At the Beginning:
        - Create a new node.
        - Point its next to the current head.
        - Update the head to this new node.

        Complexity: 𝑂(1)

    1. At the End:
        - Traverse the list to find the last node.
        - Point its next to the new node.

        Complexity: 𝑂(𝑛)

    1. At a Specific Position:

        - Traverse to the node just before the desired position.
        - Update pointers to insert the new node.

        Complexity: 𝑂(𝑛)

1. Deletion
    - Deletion can happen in three ways:
    1. From the Beginning:
        - Update the head to point to the second node.
        - Delete the original head.

        Complexity: 𝑂(1)

    1. From the End:
        - Traverse to the second-last node.
        - Set its next to null.

        Complexity: 𝑂(𝑛)

    1. From a Specific Position:
        - Traverse to the node just before the one to be deleted.
        - Update its next pointer to skip the node to be deleted.

        Complexity: 𝑂(𝑛)

1. Search
    - Search for a specific value by traversing the list and comparing each node's data.

        Complexity: 𝑂(𝑛)

## Advantages of Singly Linked List
- Dynamic Size: Can grow or shrink dynamically, unlike arrays.
- Efficient Insertions/Deletions: Easy to insert or delete nodes, especially at the beginning.
- Memory Efficiency: Uses memory for only the elements, not for a fixed-size structure.

## Disadvantages of Singly Linked List
- No Backtracking: Cannot traverse backward due to the lack of a prev pointer.
- Linear Access Time: Accessing elements takes 𝑂(𝑛), unlike arrays where it takes 𝑂(1).
- Extra Memory: Requires extra memory for the next pointer in each node.

## Applications of Singly Linked List
1. Dynamic Memory Allocation:
    - Used in stacks and queues.
1. Hash Chaining:
    - For collision resolution in hash tables.
1. Graph Representation:
    - Adjacency lists in graph theory.
1. Real-World Applications:
    - Music playlists, image viewers, and undo functionality in text editors.
