## Simple Queue: The Basic FIFO Line

A **Simple Queue** is the most fundamental implementation of the queue data structure. It operates as a linear list that strictly follows the **FIFO (First-In, First-Out)** principle, where elements are added at one end (the **rear**) and removed from the other (the **front**).

Think of it as a one-way street. Cars enter at one end and exit from the other. Once a car has passed a spot, that spot on the street is left empty and isn't reused by a car behind it. This highlights the primary characteristic—and flaw—of the simple array-based queue.

---

## How a Simple Queue is Implemented

A Simple Queue is an abstract concept, but it's most often discussed in the context of its linear array implementation, which reveals its limitations.

* **[Using a Linear Array (The Classic Example)](Implementation%20with%20Array/readme.md)**
* **[Using a Linked List](Implementation%20with%20Linked%20List/readme.md)**
* **[Using Stack](Implementation%20with%20Stack/readme.md)**

---

## Operations and Algorithms (Array-Based)

The operations are straightforward manipulations of the `front` and `rear` indices.

* **Enqueue(value)**
    * **Goal:** Add an element to the rear of the queue.

* **Dequeue()**
    * **Goal:** Remove an element from the front of the queue.

* **Peek()**, **IsEmpty()**, and **IsFull()**
    * These are simple index checks.

---

## Key Properties

* **FIFO Principle:** The first element added is the first to be removed.
* **Linear Movement:** The `front` and `rear` indices only move in one direction (forward).
* **Fixed Capacity (Array-Based):** The size is pre-defined and cannot change.
* **Wasted Space:** In the array implementation, dequeued slots are not reused.

---

## Advantages 👍

* **Simple Logic:** It is the easiest type of queue to understand and implement.
* **Fast Operations:** The core `enqueue` and `dequeue` operations are simple index increments and are therefore very fast (`$O(1)`).

---

## Disadvantages 👎

* **Massive Space Inefficiency (The Critical Flaw):** The array-based implementation is extremely wasteful. As elements are dequeued, the space at the beginning of the array becomes unusable. Eventually, the queue will report as full because `rear` has reached the end, even if the queue contains few or no elements.
* **Fixed Size:** The array implementation cannot adapt to workloads that exceed its pre-defined capacity.

---

## Applications

Due to its significant inefficiency, the simple array-based queue is rarely used in real-world software. Its primary role is educational.

* **Learning Tool:** It serves as a perfect introduction to the concept of queues.
* **Demonstrating a Problem:** It clearly illustrates the wasted-space problem, which provides the motivation for using a **Circular Queue**.
* **Short-Lived Queues:** It could be used in scenarios where the total number of enqueue operations is guaranteed to be less than the array's capacity and the queue is discarded quickly.

---

## Time Complexity

| Operation       | Complexity |
| :-------------- | :--------: |
| **Enqueue** |   `$O(1)`   |
| **Dequeue** |   `$O(1)`   |
| **Peek / Front**|   `$O(1)`   |
| **IsEmpty / IsFull**|   `$O(1)`   |
| **Search** |   `$O(n)`   |