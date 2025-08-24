## Deque: The Ultimate Hybrid Queue ↔️

A **Deque** (pronounced "deck"), short for **Double-Ended Queue**, is a linear data structure that generalizes the queue. Unlike a standard queue where elements are added at one end and removed from the other, a deque allows elements to be **added and removed from both the front and the rear**.

This hybrid nature means a deque can behave like a queue, a stack, or a combination of both, making it a highly versatile "Swiss Army knife" data structure.

***Note: Understand Flow via Code in `deQueue.c`***

---

### Representation
![DE Queue](/assets/deQueue.png)

---

## How It's Implemented

A deque's performance depends entirely on its underlying implementation. The two standard approaches offer excellent performance.

* **1. Using a Doubly Linked List**
    * **Structure:** A doubly linked list is used with `head` and `tail` pointers.
    * **Logic:** Adding/removing from the front manipulates the `head` pointer, and adding/removing from the rear manipulates the `tail` pointer. Because it's a *doubly* linked list, all four operations can be done in constant time.
    * **Conclusion:** This is a very flexible, dynamic implementation where all end operations are a guaranteed `$O(1)`.

* **2. Using a Circular Array**
    * **Structure:** A fixed-size array is treated as a circle with `front` and `rear` indices.
    * **Logic:** This implementation uses modulo arithmetic to "wrap around" the array's ends.
        * `addRear`: Increments `rear`.
        * `removeFront`: Increments `front`.
        * `addFront`: **Decrements** `front` (with wrap-around).
        * `removeRear`: **Decrements** `rear` (with wrap-around).
    * **Conclusion:** This is an extremely fast and cache-friendly implementation for a fixed-size deque. All end operations are `$O(1)`.

---

## Types of Deques

There are also two specialized, restricted versions of a deque:

* **[Input-Restricted Deque](Input-Restricted%20Deque/readme.md):** You can add elements at only one end but can remove from both ends.
* **[Output-Restricted Deque](Output-Restricted%20Deque/readme.md):** You can remove elements from only one end but can add at both ends.

---

## Core Operations

A deque is defined by four main operations for adding and removing elements, plus helpers.

* **`addFront(value)`:** Adds an element to the front of the deque.
* **`addRear(value)`:** Adds an element to the rear of the deque (like a queue's `enqueue`).
* **`removeFront()`:** Removes and returns the element from the front (like a queue's `dequeue`).
* **`removeRear()`:** Removes and returns the element from the rear.
* **`peekFront()` & `peekRear()`:** Views the element at the front or rear without removing it.
* **`isEmpty()` & `isFull()`:** Checks if the deque is empty or at capacity.

---

## Key Properties

* **Double-Ended Access:** The defining characteristic. Operations can occur at both ends.
* **Hybrid Nature:** Can function as a stack (using `addFront`/`removeFront`) or a queue (using `addRear`/`removeFront`).
* **Linear Structure:** Elements are stored sequentially.
* **Implementation-Dependent:** Can be a fixed-size (circular array) or dynamic (doubly linked list) structure.

---

## Advantages 👍

* **Maximum Flexibility:** It can be used to efficiently implement both stacks and queues.
* **Efficient Operations:** When implemented correctly (with a doubly linked list or circular array), all additions and removals from either end are performed in constant time, `$O(1)`.

---

## Disadvantages 👎

* **Implementation Complexity:** A correct circular array implementation requires careful management of pointers and wrap-around logic, making it more complex than a simple queue or stack.
* **Memory Overhead (Linked List):** The doubly linked list implementation requires two pointers per node, which can be less space-efficient than an array.

---

## Applications

Deques are powerful tools for specific types of algorithms.

* **Sliding Window Problems:** A deque is the go-to data structure for finding the maximum or minimum element in a sliding window over an array in linear (`$O(n)`) time.
* **Palindrome Checking:** A classic example where you add characters to a deque and then repeatedly remove and compare the characters from the front and rear.
* **Job Scheduling:** Can be used to implement schedulers where some high-priority jobs can be added to the front of the queue.
* **Undo/Redo History:** Can store a limited-size history of actions where new actions are added to one end and old ones fall off the other.

---

## Time Complexity Summary

For both standard, efficient implementations:

| Operation       | Doubly Linked List | Circular Array |
| :-------------- | :----------------: | :------------: |
| **addFront** |       `$O(1)`        |     `$O(1)`    |
| **addRear** |       `$O(1)`        |     `$O(1)`    |
| **removeFront** |       `$O(1)`        |     `$O(1)`    |
| **removeRear** |       `$O(1)`        |     `$O(1)`    |
| **Peek (Front/Rear)** |       `$O(1)`        |     `$O(1)`    |