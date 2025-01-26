# Implementation of Queue Using Stacks

A **Queue** implemented using **stacks** demonstrates how we can simulate the **FIFO (First In, First Out)** behavior of a queue using the **LIFO (Last In, First Out)** property of stacks. This implementation is an excellent example of algorithmic transformation.

---

## Key Components

1. **Two Stacks**:
   - Use two stacks (`stack1` and `stack2`) to manage the elements.
   - These stacks can either be implemented using arrays or linked lists.

2. **Stack Properties**:
   - Stacks operate using the LIFO principle:
     - **Push**: Adds an element to the top of the stack.
     - **Pop**: Removes and returns the top element.

---

## Approaches to Implement Queue Using Stacks

### 1. Enqueue Costly Approach

In this method, the **enqueue (add)** operation is made **costly**, while the **dequeue (remove)** operation is efficient.

#### Steps:

1. **Enqueue (Costly)**:
   - When adding an element:
     1. Pop all elements from `stack1` and push them into `stack2`.
     2. Push the new element into `stack1`.
     3. Transfer all elements back from `stack2` to `stack1`.
   - This ensures that the oldest element remains at the top of `stack1`.

2. **Dequeue (Efficient)**:
   - Simply pop the top element from `stack1`.

#### Time Complexity:
- **Enqueue**: \( O(n) \) (due to the repeated transfer of elements).
- **Dequeue**: \( O(1) \) (direct pop from `stack1`).

---

### 2. Dequeue Costly Approach

In this method, the **dequeue (remove)** operation is made **costly**, while the **enqueue (add)** operation is efficient.

#### Steps:

1. **Enqueue (Efficient)**:
   - Push the new element directly into `stack1`.

2. **Dequeue (Costly)**:
   - When removing an element:
     1. If `stack2` is empty:
        - Pop all elements from `stack1` and push them into `stack2`.
     2. Pop the top element from `stack2`.

#### Time Complexity:
- **Enqueue**: \( O(1) \) (direct push into `stack1`).
- **Dequeue**: \( O(n) \) (only when `stack2` is empty, requiring a transfer).

---

## Key Differences Between the Two Approaches

| Aspect              | Enqueue Costly            | Dequeue Costly             |
|---------------------|---------------------------|----------------------------|
| **Enqueue Time**    | \( O(n) \)               | \( O(1) \)                |
| **Dequeue Time**    | \( O(1) \)               | \( O(n) \)                |
| **When to Use**     | Dequeue operations dominate | Enqueue operations dominate |

---

## Steps for Common Operations

1. **IsEmpty**:
   - Check if both `stack1` and `stack2` are empty.

2. **Peek (Front)**:
   - The element at the **front** is always:
     - Top of `stack1` (Enqueue Costly).
     - Top of `stack2` (Dequeue Costly).

3. **Size**:
   - The total size of the queue is the combined size of `stack1` and `stack2`.

---

## Advantages

1. **Efficient Use of Memory**:
   - Dynamically uses memory as required by the stacks.
2. **Algorithmic Flexibility**:
   - Demonstrates how a queue's properties can be implemented using stacks.

---

## Disadvantages

1. **Higher Time Complexity**:
   - One of the operations (enqueue or dequeue) is always costly, making it less efficient than direct queue implementations.
2. **Extra Memory Overhead**:
   - Requires two stacks to simulate a single queue.

---

## Applications

1. **Algorithm Design**:
   - Understanding data structure transformations and alternative implementations.
2. **Simulation**:
   - Situations where stack operations are more accessible than queue operations.

---

## Comparison with Other Queue Implementations

| Feature            | Array-Based Queue         | Linked-List Queue          | Queue Using Stacks         |
|--------------------|---------------------------|----------------------------|----------------------------|
| **Dynamic Size**   | No (unless dynamic array) | Yes                        | Yes                        |
| **Time Complexity**| \( O(1) \) (enqueue/dequeue) | \( O(1) \)                | \( O(1) \) or \( O(n) \)   |
| **Memory Overhead**| Moderate (array size)     | High (node pointers)       | High (two stacks)          |

---
