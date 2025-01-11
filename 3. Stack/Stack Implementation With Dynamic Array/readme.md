# Dynamic Stack with Array
A **Dynamic Stack** is a variation of the stack where the size of the stack grows and shrinks dynamically during runtime, depending on the number of elements. It addresses the limitations of a fixed stack by using an array that resizes itself as needed.

## Key Characteristics of a Dynamic Stack
1. Dynamic Size:
    - The stack automatically resizes (expands or shrinks) based on the number of elements.
    - Eliminates stack overflow for practical purposes.
1. Array-Based:
    - Internally uses an array to store elements.
1. Resizing Logic:
    - Expand: When the stack is full, the array size is doubled.
    - Shrink: Optionally, when the stack is underutilized (e.g., less than half full), the array size can be halved.

## Key Operations on a Dynamic Stack
1. Push
    - Adds an element to the top of the stack.
    - If the stack is full, the array is resized to accommodate more elements.
    - Algorithm:
        1. Check if the stack is full (top == capacity - 1).
        1. If full:
        1. Increase the size of the array.
        1. Increment the top pointer.
        1. Insert the new element at the position top.
    - Complexity: O(1): Most push operations run in constant time. Resizing happens infrequently.

2. Pop
    - Removes the top element from the stack.
    - Optionally, reduces the array size when the stack is significantly underutilized.
    - Algorithm:
        1. Check if the stack is empty (top == -1).
        1. Retrieve the element at top.
        1. Decrement the top pointer.
        1. Optionally, shrink the array if the size is less than half the capacity.
    - Complexity:
        - O(1) for most operations.
        - Occasional resizing makes it 𝑂(𝑛) in rare cases.

3. Peek
    - Returns the top element without removing it.
    - Complexity: 𝑂(1)

4. IsEmpty
    - Checks if the stack is empty.
    - Condition: top == -1
    - Complexity: 𝑂(1)

5. Size
    - Returns the current number of elements in the stack.
    - Complexity: 𝑂(1)

# Applications of Dynamic Stack
1. Dynamic Workloads:
    - Applications with unpredictable or varying stack sizes.
1. Memory-Constrained Environments:
    - Allocates memory only as needed, optimizing usage.
1. Recursive Algorithms:
    - Can handle deep recursions without fixed size limitations.
1. Expression Evaluation and Parsing:
    - Suitable for complex mathematical or logical evaluations.

## Advantages of Dynamic Stack
1. Dynamic Resizing:
    - Automatically adjusts size, reducing memory waste and avoiding stack overflow.
1. Efficient Memory Usage:
    - Allocates memory only as needed.
1. Amortized Efficiency:
    - Most operations are 𝑂(1) due to infrequent resizing.

## Disadvantages of Dynamic Stack
1. Resizing Overhead:
    - Resizing involves copying elements, which is 𝑂(𝑛) and can cause a performance hit.
1. Complex Implementation:
    - Requires more logic compared to a fixed stack.
1. Memory Fragmentation:
    - Frequent resizing can lead to fragmentation in memory-intensive environments.
