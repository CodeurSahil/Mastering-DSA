## Queue from Stacks: A LIFO to FIFO Transformation 🔄

Implementing a **Queue** using two **Stacks** is a classic computer science problem that demonstrates how to simulate **FIFO (First-In, First-Out)** behavior using only **LIFO (Last-In, First-Out)** structures.

This is less of a practical, high-performance solution and more of a conceptual exercise. It's a popular technical interview question designed to test your understanding of how data structures work fundamentally. The goal is to build a queue when you are only given stacks to work with.

---

## The Core Idea: Reversing a Stack Creates a Queue

The entire implementation relies on a single, clever trick: **moving all elements from one stack to another reverses their order.**

A stack stores elements in LIFO order. If you push `A`, then `B`, then `C` onto `stack1`, the order from top to bottom is `C, B, A`. If you then pop every element from `stack1` and push it onto `stack2`, the new order in `stack2` from top to bottom will be `A, B, C`.

Now, if you pop from `stack2`, you get `A`, then `B`, then `C`—exactly FIFO order! The two implementation methods are just different strategies for deciding *when* to perform this reversal.

---

## Implementation Methods and Algorithms

There are two primary approaches to building a queue from two stacks.

### [Making Enqueue Costly](Costly%20En-Queue/readme.md)
### [Making Dequeue Costly (The Standard Approach)](Costly%20De-Queue/readme.md)

---

## Key Properties

* **FIFO Behavior:** Despite being built from LIFO components, the final structure correctly adheres to the FIFO principle.
* **Dynamic Size:** The queue's capacity is determined by the underlying stack implementations, which are typically dynamic.
* **Composed Structure:** It is not a fundamental data structure but one composed of others.

---

## Advantages 👍

* **Algorithmic Insight:** It's an excellent exercise for deepening your understanding of data structures and how their properties can be transformed.
* **Problem-Solving:** It demonstrates how to achieve a desired behavior with a constrained set of tools, a common scenario in software development.

---

## Disadvantages 👎

* **Inefficient Performance:** It is significantly slower than a native queue implementation (using an array or linked list). At least one of its core operations is not a true, consistent `$O(1)`.
* **Higher Memory Usage:** It requires the memory overhead of two stacks to simulate a single queue.

---

## Applications

The primary application for this implementation is **educational**.

* **Technical Interviews:** A very common question used to evaluate a candidate's problem-solving skills and grasp of data structure mechanics.
* **Algorithm Design:** Serves as a conceptual tool for proving that certain operations are possible or for building more complex algorithms.
* **Constrained Environments:** In a theoretical scenario where a system or language only provides a stack API, this technique could be used to create a queue.

---

## Time Complexity Summary

| Method                | Enqueue Complexity | Dequeue Complexity             |
| :-------------------- | :----------------: | :----------------------------- |
| **Enqueue Costly** |       `$O(n)$`      | `$O(1)`                        |
| **Dequeue Costly** |       `$O(1)``      | **Amortized `$O(1)`** (Worst-Case `$O(n)`) |