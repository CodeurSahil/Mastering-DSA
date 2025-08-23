## Linked List Queue: A Dynamic FIFO Line 🔗

Implementing a **Queue** using a **Linked List** provides a naturally dynamic and flexible structure. It overcomes the primary limitation of array-based queues—their fixed size—by allocating memory one node at a time, allowing the queue to grow and shrink as needed.

In this implementation, two pointers, `front` and `rear`, are used to keep track of the head and tail of the linked list, which correspond to the front and rear of the queue.

***Note: Understand Flow via Code in `simpleQueue.c`***

---

## How It Works: The Core Components

The structure is managed by a few key components:

* **The Nodes:** Each element is stored in a `Node`. A node contains two parts: the `data` (the actual value) and a `next` pointer that references the next node in the line.
* **The `front` Pointer:** This pointer always points to the **first** node in the linked list. This is where elements are removed (dequeued).
* **The `rear` Pointer:** This pointer always points to the **last** node in the linked list. This is where new elements are added (enqueued).
* **Empty State:** An empty queue is indicated when both `front` and `rear` pointers are `NULL`.

---

## Operations and Algorithms

All queue operations are achieved through simple and efficient manipulations of the `front` and `rear` pointers.

* **Enqueue(value)**
    * **Goal:** Add an element to the rear of the queue.
    * **Algorithm:**
        1.  Create a `newNode` with the given `value`.
        2.  If the queue is empty (`rear == NULL`), set both `front` and `rear` to point to the `newNode`.
        3.  Otherwise, link the new node to the end of the list: `rear.next = newNode`.
        4.  Update the `rear` pointer to be the `newNode`.

* **Dequeue()**
    * **Goal:** Remove an element from the front of the queue.
    * **Algorithm:**
        1.  First, check if the queue is empty (`front == NULL`). If so, throw a **Queue Underflow** error.
        2.  Store the data from the `front` node.
        3.  Move the `front` pointer to the next node (`front = front.next`).
        4.  **Crucial Step:** If the queue is now empty (the new `front` is `NULL`), you must also set the `rear` pointer to `NULL`.
        5.  Return the stored data.

* **Peek()** and **IsEmpty()**
    * `Peek()` returns the data from the `front` node without modifying any pointers.
    * `IsEmpty()` returns `true` if the `front` pointer is `NULL`.

---

## Key Properties

* **FIFO Principle:** The First-In, First-Out rule is strictly maintained.
* **Dynamic Size:** The queue's capacity is limited only by the available system memory.
* **Node-Based Storage:** Elements are stored in individual, non-contiguous nodes.
* **Pointer-Based Management:** The entire queue is managed by the `front` and `rear` pointers.

---

## Advantages 👍

* **Truly Dynamic:** The queue can handle any number of elements without the risk of overflow.
* **Efficient Memory Usage:** Memory is allocated only when an element is added, so there is no pre-allocated wasted space.
* **No Resizing Overhead:** Unlike dynamic arrays, there are no slow `$O(n)` resizing operations. `Enqueue` and `dequeue` have consistently fast `$O(1)` performance.

---

## Disadvantages 👎

* **Memory Overhead per Element:** Each node requires extra memory to store a `next` pointer, which can be less space-efficient than an array for a large number of elements.
* **Poor Cache Performance:** Because nodes can be scattered throughout memory, it can be slower for the CPU to access them compared to the contiguous block of an array.

---

## Applications

The linked-list-based queue is the ideal choice when the number of items to be queued is unknown, highly variable, or when the overhead of resizing a dynamic array is unacceptable.

* **Operating System Schedulers:** For managing processes, threads, or I/O requests where the workload fluctuates.
* **Network Buffers:** Handling incoming data packets where the traffic volume is unpredictable.
* **Breadth-First Search (BFS):** Used on large or complex graphs where the queue size can change dramatically during traversal.
* **Event-Driven Systems:** Managing queues of events or messages.

---

## Time Complexity

The performance of a linked-list queue is one of its greatest strengths due to its consistency.

| Operation       | Complexity | Explanation                                  |
| :-------------- | :--------: | :------------------------------------------- |
| **Enqueue** |   `$O(1)`  | Always a constant-time operation.            |
| **Dequeue** |   `$O(1)`  | Always a constant-time operation.            |
| **Peek / Front**|   `$O(1)`  | Always a constant-time operation.            |
| **IsEmpty** |   `$O(1)`  | A simple `NULL` check.                         |
| **Search** |   `$O(n)`  | Requires traversing the list from the `front`. |