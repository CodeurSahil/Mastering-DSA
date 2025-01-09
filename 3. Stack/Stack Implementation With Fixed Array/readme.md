# Fixed Stack with Array
A **Fixed Stack** implemented using an array is a stack where the size is pre-defined and cannot grow dynamically. This type of stack is suitable for scenarios where the maximum number of elements is known in advance.

## Key Characteristics of a Fixed Stack
1. Array-Based Structure:
    - Uses an array to store the elements of the stack.
1. Fixed Size:
    - The size of the stack is determined during initialization and remains constant.
1. Top Pointer:
    - Tracks the index of the topmost element in the stack.

## Key Operations on a Fixed Stack
1. Push
    - Adds an element to the top of the stack.
    - If the stack is full, a stack overflow error occurs.
    - Algorithm:
        1. Check if the stack is full (top == capacity - 1).
        1. If not full:
        1. Increment the top pointer.
        1. Insert the new element at the index top.
    - Complexity: 𝑂(1)

2. Pop
    - Removes the top element from the stack.
    - If the stack is empty, a stack underflow error occurs.
    - Algorithm:
        1. Check if the stack is empty (top == -1).
        1. If not empty:
        1. Retrieve the element at top.
        1. Decrement the top pointer.
    - Complexity: 𝑂(1)

3. Peek
    - Returns the top element of the stack without removing it.
    - Algorithm:
        1. Check if the stack is empty.
        1. If not empty, return the element at top.
    - Complexity: 𝑂(1)

4. IsEmpty
    - Checks if the stack is empty.
    - Condition: top == -1
    - Complexity: 𝑂(1)

5. IsFull
    - Checks if the stack is full.
    - Condition: top == capacity - 1
    - Complexity: 𝑂(1)

## Applications of Fixed Stack
1. Expression Evaluation:
    - Used in parsing and evaluating expressions (e.g., postfix).
1. Undo/Redo Operations:
    - Maintains a history of operations in text editors or software applications.
1. Function Call Stack:
    - Tracks active function calls during program execution.
1. Parenthesis Matching:
    - Validates expressions with nested parentheses.

## Advantages of Fixed Stack
1. Simple Implementation:
    - Easy to implement using arrays.
1. Fast Operations:
    - Push, pop, and peek operations are performed in constant time (1)
1. Memory Efficiency:
    - Uses a contiguous block of memory, which reduces overhead compared to dynamic memory allocation.

## Disadvantages of Fixed Stack
1. Fixed Size:
    - Cannot grow dynamically, leading to stack overflow if more elements are pushed than its capacity.
    - Wastes memory if the stack is underutilized.
1. Limited Flexibility:
    - Not suitable for applications where the maximum size is unknown or variable.