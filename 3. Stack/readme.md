## Stack: The Last-In, First-Out Pile 🥞

A **Stack** is a fundamental linear data structure that follows the **LIFO (Last-In, First-Out)** principle. This means the last element added to the stack is the very first one to be removed.

A great real-world analogy is a stack of plates. You place a new plate on the **top**, and when you need a plate, you take one from the **top**. You can't easily access the plates at the bottom without first removing the ones above them. All operations happen at this single entry/exit point called the `top`.

---

![Repesentaion of Stack](/assets/representationOfStack.png)

---

## How a Stack is Implemented

A Stack is an abstract data type, which means it's defined by its behavior (LIFO) rather than a specific structure. It's typically implemented using an underlying data structure like an array or a linked list.

### 1. [Using a Fixed-Size Array](Stack%20Implementation%20With%20Fixed%20Array/readme.md)

This is the simplest implementation. It uses a static array with a fixed capacity and an integer variable (e.g., `top`) to keep track of the index of the last element inserted.

### 2. [Using a Dynamic Array](Stack%20Implementation%20With%20Dynamic%20Array/readme.md)

This implementation uses a resizable array (like Java's `ArrayList` or C++'s `vector`) that automatically grows when it runs out of space.

### 3. [Using a Linked List](Stack%20Implementation%20With%20Linked%20List/readme.md)

This is a truly dynamic implementation where each element is a node in a linked list. The `head` of the list acts as the `top` of the stack.

---

## Core Stack Operations

The primary operations for a stack are simple, intuitive, and extremely fast.

* **Push**
    * **Goal:** To add a new element to the top of the stack.
    * **Algorithm:**
        1.  Increment the `top` pointer.
        2.  Place the new element at the position indicated by `top`.
    * **Note:** If the stack has a fixed size and is full, this operation can cause a **Stack Overflow** error.

* **Pop**
    * **Goal:** To remove the topmost element from the stack and return it.
    * **Algorithm:**
        1.  Retrieve the element at the `top` pointer.
        2.  Decrement the `top` pointer.
    * **Note:** If the stack is empty, attempting to pop an element will cause a **Stack Underflow** error.

* **Peek (or Top)**
    * **Goal:** To look at the topmost element without removing it from the stack.
    * **Algorithm:** Return the element at the `top` pointer.

* **IsEmpty**
    * **Goal:** To check if the stack contains any elements.
    * **Algorithm:** Return `true` if the `top` pointer is at its initial position (e.g., -1), otherwise return `false`.

---

## Key Properties

* **LIFO Principle:** Last element pushed is the first element popped.
* **Single Point of Access:** All operations are performed only at the `top` of the stack.
* **Linear Data Structure:** Elements are stored in a sequential order.
* **Implementation:** Can be implemented using either a static array or a dynamic data structure like a linked list.

---

## Advantages 👍

* **Fast Operations:** All core operations (`push`, `pop`, `peek`) are performed in constant time, `$O(1)$` (or amortized `$O(1)$` for dynamic arrays).
* **Simple to Implement:** The logic for a stack is straightforward and easy to code.
* **Automatic Memory Management:** Stacks are used by processors to manage function calls (the "call stack"), automatically allocating and deallocating memory for local variables.

---

## Disadvantages 👎

* **Limited Access:** You can only access the topmost element of the stack. You cannot access or modify other elements without first popping the ones above them.
* **Potential for Overflow:** If implemented with a fixed-size array, the stack can run out of space, which can crash a program.

---

## Common Applications

Stacks are used extensively in computer science to solve a variety of problems.
* **Function Call Management:** The **call stack** keeps track of active functions. When a function is called, it's pushed onto the stack; when it returns, it's popped off.
* **Undo/Redo Functionality:** In text editors or software, each action can be pushed onto a stack. The "undo" operation simply pops the last action.
* **Expression Evaluation:** Used to convert expressions from infix notation (e.g., `3 + 4`) to postfix (`3 4 +`) and then evaluate them.
* **Backtracking Algorithms:** Essential for solving problems that require exploring paths, such as navigating a maze or in algorithms like Depth-First Search (DFS).
* **Browser History:** The "back" button in a web browser works like a stack, where each new page visited is pushed onto it.

---

## Time Complexity Summary ⏱️

| Operation | Array / Linked List | Dynamic Array (Amortized) |
| :--- | :---: | :---: |
| **Push** | `$O(1)` | `$O(1)` |
| **Pop** | `$O(1)` | `$O(1)` |
| **Peek (Top)** | `$O(1)` | `$O(1)` |
| **Search (by value)** | `$O(n)` | `$O(n)` |