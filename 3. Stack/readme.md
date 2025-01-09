# Stack
A **Stack** is a linear data structure that operates on the principle of **LIFO** (Last In, First Out) or **FILO** (First In, Last Out). This means the last item added to the stack is the first one to be removed.

### Types of Stacks
1. Simple Stack:
    - Basic LIFO structure.
1. Bounded Stack:
    - Has a fixed size, leading to overflow when full.
1. Dynamic Stack:
    - Resizable stack implemented using dynamic memory allocation.

### Structure of a Stack
A stack consists of:
1. **Container**: A structure (like an array or linked list) to hold elements.
2. **Top Pointer**: Points to the last added element in the stack.
    ![Repesentaion of Stack](/assets/representationOfStack.png)

## Key Operations on a Stack
1. Push
    - Adds an element to the top of the stack.
    - If the stack is full (in a fixed-size implementation), an overflow error occurs.
    - Algorithm:
        1. Increment the top pointer.
        1. Insert the element at the position indicated by top.
    - Complexity: 𝑂(1)

2. Pop
    - Removes the top element from the stack.
    - If the stack is empty, an underflow error occurs.
    - Algorithm:
        1. Retrieve the element at the top pointer.
        1. Decrement the top pointer.
    - Complexity: 𝑂(1)

3. Peek/Top

    - Returns the top element without removing it.
    - Complexity: 𝑂(1)

4. IsEmpty

    - Checks whether the stack is empty.
    - Complexity: 𝑂(1)

5. IsFull:

    - Checks whether the stack is full (for fixed-size stacks).
    - Complexity: 𝑂(1)

### Implementation of a Stack
1. Array-Based Implementation
2. Linked List-Based Implementation


## Applications of Stacks
1. Expression Evaluation:
    - Used in converting and evaluating infix, postfix, and prefix expressions.
1. Backtracking:
    - Helps in problems like navigating mazes or recursive algorithms.
1. Function Calls:
    - Maintains the call stack for function execution.
1. Undo/Redo Operations:
    - Used in text editors and software applications.
1. Parenthesis Matching:
    - Validates expressions with nested parentheses.
1. Browser History:
    - Implements the "back" and "forward" navigation functionality.

## Advantages of Stacks
1. Efficient Operations:
    - Push and pop operations have 𝑂(1) complexity.
1. Memory Efficiency:
    - Utilizes memory for only the required elements.

## Disadvantages of Stacks
1. Limited Access:
    - Can only access the top element.
1. Fixed Size (for Array Implementation):
    - Requires pre-allocation of space, which may lead to overflow or wasted memory.
