## Queue: The First-In, First-Out Line 🚶‍♂️🚶‍♀️🚶

A **Queue** is a fundamental linear data structure that operates on the **FIFO (First-In, First-Out)** principle. This means the first element added to the queue is the very first one to be removed.

The best real-world analogy is a line of people waiting for tickets. The first person to get in line is the first person to be served. New people join the line at the **rear** (end), and people are served from the **front** (start).



---

## Types of Queues

While the simple queue is common, several specialized variations exist:

* **[Simple Queue](Simple%20Queue/readme.md):** An basic type of queue that operates on the First In, First Out (FIFO)
* **[Circular Queue](Circular%20Queue/readme.md):** An array-based queue where the rear pointer can "wrap around" to the beginning of the array, efficiently reusing empty space.
* **[Priority Queue](Priority%20Queue/readme.md):** An abstract data type where each element has an associated "priority." Elements with higher priority are dequeued before elements with lower priority, regardless of when they were added.
* **[Deque (Double-Ended Queue)](Double%20Ended%20Queue/readme.md):** A hybrid structure that allows elements to be added or removed from **both** the front and the rear.

---

## How Queues Are Implemented

A queue is an abstract data type and can be implemented in several ways:

* **Using an Array (often a Circular Array)**
    * Uses a fixed-size array with two integer indices: `front` and `rear`.
    * `Enqueue` increments the `rear` index; `dequeue` increments the `front` index.
    * A circular array is preferred to prevent wasted space at the beginning of the array after several dequeue operations.
* **Using a Linked List**
    * Uses a linked list with two pointers: `head` (for the front) and `tail` (for the rear).
    * `Enqueue` adds a new node at the `tail`.
    * `Dequeue` removes the `head` node.
    * This implementation is naturally dynamic and won't overflow.

---

## Core Queue Operations

The primary operations for a queue are focused on its two ends: the front and the rear.

* **Enqueue**
    * **Goal:** To add a new element to the **rear** of the queue.
    * **Note:** In a fixed-size queue, this can cause a **Queue Overflow** error if the queue is full.

* **Dequeue**
    * **Goal:** To remove the element from the **front** of the queue and return it.
    * **Note:** If the queue is empty, this can cause a **Queue Underflow** error.

* **Peek (or Front)**
    * **Goal:** To look at the front element of the queue without removing it.

* **IsEmpty**
    * **Goal:** To check if the queue contains any elements.

---

## Key Properties

* **FIFO Principle:** First element enqueued is the first element dequeued.
* **Two Access Points:** Elements are added at the `rear` and removed from the `front`.
* **Linear Data Structure:** Elements are organized in a sequential order.
* **Versatile Implementation:** Can be built using arrays, linked lists, or even other data structures.

---

## Advantages 👍

* **Orderly Processing:** Naturally handles tasks and data in the order they are received, ensuring fairness.
* **Fast Operations:** The core operations of `enqueue` and `dequeue` are very fast, typically `$O(1)`.
* **Flexibility:** Can be easily adapted for various scenarios, from simple data buffering to complex scheduling algorithms.

---

## Disadvantages 👎

* **Limited Access:** You can only access the front element. Accessing or searching for an element in the middle is inefficient (`$O(n)$) as it requires dequeuing everything before it.
* **Implementation Trade-offs:**
    * **Array-based queues** have a fixed size and can overflow.
    * **Linked-list-based queues** have a memory overhead due to pointers.

---

## Common Applications

Queues are essential in programming and computer systems for managing sequential processes.
* **CPU and Task Scheduling:** Operating systems use queues to manage the list of processes waiting for CPU time.
* **Data Buffering:** Used in streaming video or network communication, where data arrives at a variable rate but needs to be processed smoothly.
* **Breadth-First Search (BFS):** This graph traversal algorithm uses a queue to explore nodes level by level.
* **Print Spooling:** Print jobs are added to a queue and printed in the order they were received.
* **Customer Service Systems:** Managing call center queues or support ticket systems.

---

## Time Complexity Summary ⏱️

For both efficient array (circular) and linked list implementations:

| Operation       | Average Case | Worst Case |
| :-------------- | :----------: | :--------: |
| **Enqueue** |    `$O(1)$`   |   `$O(1)`   |
| **Dequeue** |    `$O(1)`   |   `$O(1)`   |
| **Peek (Front)**|    `$O(1)`   |   `$O(1)`   |
| **Search (by value)**|    `$O(n)`   |   `$O(n)`   |