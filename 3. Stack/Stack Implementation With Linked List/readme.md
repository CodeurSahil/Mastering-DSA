## Linked List Stack: A Truly Dynamic Stack ⛓️

A **Linked List Stack** is an implementation of the stack data structure that uses a linked list as its underlying container. It is a naturally dynamic solution that grows and shrinks one element at a time, completely avoiding the limitations of fixed-size arrays and the resizing overhead of dynamic arrays.

In this implementation, the **head** of the linked list serves as the **top** of the stack. All operations—pushing, popping, and peeking—are performed at this single point.

***Note: Understand Flow via Code in `linkedStack.c`***

---

## How It Works: The Core Components

The structure is simple and elegant, relying on two key ideas:

* **The Nodes:** Each element is stored in a `Node` object. A node contains two parts: the `data` (the actual value) and a `next` pointer that references the next node in the stack.
* **The `top` Pointer:** A single pointer, often called `top` or `head`, always points to the first node in the list. This node is the top of the stack. An empty stack is simply represented by the `top` pointer being `NULL`.

---

## Operations and Algorithms

All stack operations translate directly to simple manipulations of the head of the linked list.

* **Push(value)**
    * **Goal:** Add an element to the top of the stack. This is equivalent to **adding a node to the head** of the linked list.
    * **Algorithm:**
        1.  Create a `newNode` with the given `value`.
        2.  Set the `newNode.next` pointer to the current `top`.
        3.  Update the `top` pointer to point to this `newNode`.

* **Pop()**
    * **Goal:** Remove the top element from the stack. This is equivalent to **removing the head node** of the linked list.
    * **Algorithm:**
        1.  First, check if the stack is empty (`top == NULL`). If so, throw a **Stack Underflow** error.
        2.  Store the data from the `top` node.
        3.  Move the `top` pointer to the next node (`top = top.next`).
        4.  Return the stored data.

* **Peek()**
    * **Goal:** View the top element without removing it.
    * **Algorithm:**
        1.  Check if the stack is empty.
        2.  If not, return the data from the `top` node.

* **IsEmpty()**
    * **Goal:** Check if the stack is empty.
    * **Algorithm:** Returns `true` if `top == NULL`.

---

## Key Properties

* **LIFO Principle:** Follows the Last-In, First-Out rule.
* **Truly Dynamic Size:** The stack's capacity is only limited by the available system memory.
* **Node-Based Storage:** Elements are stored in individual nodes that can be located anywhere in memory.
* **Pointer-Based Access:** All operations are managed through the single `top` pointer.

---

## Advantages 👍

* **No Stack Overflow:** The stack grows as needed, so it won't overflow unless the computer runs out of memory.
* **Efficient Memory Usage:** Memory is allocated one node at a time, so there is no wasted, pre-allocated space.
* **No Resizing Overhead:** Unlike a dynamic array, there are no slow `$O(n)` resizing operations. Every `push` and `pop` operation has a consistent, fast performance.

---

## Disadvantages 👎

* **Memory Overhead per Element:** Each node requires extra memory to store the `next` pointer. This can be significant if you're storing a large number of small items.
* **Poor Cache Performance:** Because nodes are not stored contiguously in memory, traversing a linked list can be slower than iterating through a contiguous array due to CPU cache misses.

---

## Applications

A linked list implementation is the ideal choice when the stack size is unpredictable or when consistent performance for every operation is critical.

* **Recursive Algorithm Simulation:** Perfect for handling recursion where the depth is unknown and could be very large.
* **Systems with Fluctuating Memory Demands:** Useful in environments where allocating a large, fixed block of memory is not practical.
* **General-Purpose Stacks:** Often used when the occasional performance hiccup of a resizing dynamic array is unacceptable.

---

## Time Complexity

The performance of a linked list stack is one of its greatest strengths due to its consistency.

| Operation         | Complexity | Explanation                                      |
| :---------------- | :--------: | :----------------------------------------------- |
| **Push** |   `$O(1)$`   | Always a constant-time operation.                |
| **Pop** |   `$O(1)`   | Always a constant-time operation.                |
| **Peek / Top** |   `$O(1)`   | Always a constant-time operation.                |
| **IsEmpty** |   `$O(1)`   | A simple `NULL` check.                             |
| **Search (by value)** |   `$O(n)`   | Requires traversing the list from the `top`. |