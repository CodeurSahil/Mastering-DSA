# Stack with Linked List
A **Stack** implemented using a linked list is a dynamic and efficient way to create a stack. Unlike array-based stacks, linked list stacks grow and shrink in size without the need for resizing operations, making them memory-efficient and avoiding the limitations of fixed-size arrays.

## Key Characteristics of Stack with Linked List
1. Dynamic Size:
    - The stack can grow or shrink dynamically, limited only by available memory.
1. No Resizing Overhead:
    - No need to resize an underlying array as with a dynamic stack.
1. Node-Based Storage:
    - Each element is stored in a node, which contains:
        - Data: The value of the element.
        - Next Pointer: A reference to the next node in the stack.
1. Top Reference:
    - A reference (pointer) to the topmost node is maintained for fast access.

## Key Operations on Stack with Linked List
1. Push
    - Adds a new element to the top of the stack.
    - Algorithm:
        1. Create a new node with the given data.
        1. Set the next pointer of the new node to point to the current top.
        1. Update the top pointer to the new node.
    - Complexity: 𝑂(1)

2. Pop
    - Removes the top element from the stack.
    - Algorithm:
        1. Check if the stack is empty (top == null).
        1. Retrieve the data from the top node.
        1. Update the top pointer to the next node.
        1. Free the memory of the removed node (optional in languages like C++/C).
    - Complexity: 𝑂(1)

3. Peek
    - Returns the value of the top element without removing it.
    - Algorithm:
        1. Check if the stack is empty.
        1. Return the data of the top node.
    - Complexity: 𝑂(1)

4. IsEmpty
    - Checks if the stack is empty.
    - Condition: top == null
    - Complexity: 𝑂(1)

## Applications of Stack with Linked List
1. Dynamic Workloads:
    - Suitable for applications where the size of the stack changes frequently.
1. Recursive Algorithms:
    - Used in depth-first search (DFS) and backtracking.
1. Expression Parsing:
    - Helps evaluate and convert expressions (e.g., infix to postfix).
1. Undo/Redo Functionality:
    - Tracks changes in applications like text editors.


## Advantages of Stack with Linked List
1. Dynamic Size:
    - No need to define the size of the stack at initialization.
1. Efficient Memory Usage:
    - Allocates memory only when required.
1. No Overflow:
    - Unlike an array-based stack, there’s no stack overflow unless system memory is exhausted.
## Disadvantages of Stack with Linked List
1. Extra Memory Overhead:
    - Each node requires additional memory for the pointer/reference.
1. Pointer Manipulation:
    - Requires careful handling of pointers, especially in low-level languages like C.
1. Potential Cache Unfriendliness:
    - Nodes are stored non-contiguously in memory, which may affect performance.