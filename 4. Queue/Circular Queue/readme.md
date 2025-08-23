## Circular Queue: The Space-Saving FIFO Loop 🔄

A **Circular Queue** is an efficient implementation of the queue data structure that uses a fixed-size array as if it were connected end-to-end, forming a circle. Its primary purpose is to solve the major flaw of a simple array queue: **wasted space**.

By allowing the queue to "wrap around" the end of the array, a circular queue can reuse the empty slots left by dequeued elements, making it a highly space-efficient FIFO structure.

***Note: Understand Flow via Code in `circularQueue.c`***

---

![Repesentaion of Circular Queue](/assets/circularQueue.png)

---

## How It Works: The Wrap-Around Logic

The elegance of the circular queue lies in its simple solution to a significant problem.

* **The Problem It Solves:** In a simple (linear) array queue, dequeuing an element leaves an empty, unusable slot at the beginning of the array. The queue drifts towards the end, and the queue can report as "full" even if it's mostly empty.

* **The Circular Solution:** A circular queue treats the last index of the array as being adjacent to the first index. When the `rear` pointer reaches the end and needs to add a new element, it wraps around to the beginning of the array (if there's space).

* **The Modulo Operator (`%`):** This wrap-around logic is easily implemented using the modulo operator. By calculating the next position as `(index + 1) % MAX_SIZE`, the pointer will automatically loop back to 0 after reaching the last index.

---

## Operations and Algorithms

All operations use modulo arithmetic to manage the `front` and `rear` pointers within the circular array.

* **Enqueue(value)**
    * **Goal:** Add an element to the rear of the queue.
    * **Algorithm:**
        1.  First, check if the queue is full. The standard condition is `(rear + 1) % MAX_SIZE == front`. If it is, throw a **Queue Overflow** error.
        2.  If the queue is empty (`front == -1`), set `front` to 0.
        3.  Calculate the new rear position: `rear = (rear + 1) % MAX_SIZE`.
        4.  Insert the `value` at `array[rear]`.

* **Dequeue()**
    * **Goal:** Remove an element from the front of the queue.
    * **Algorithm:**
        1.  First, check if the queue is empty (`front == -1`). If so, throw a **Queue Underflow** error.
        2.  Retrieve the element at `array[front]`.
        3.  If `front == rear` (it's the last element), reset the queue by setting both `front` and `rear` to -1.
        4.  Otherwise, calculate the new front position: `front = (front + 1) % MAX_SIZE`.
        5.  Return the retrieved value.

* **Peek()**, **IsEmpty()**, and **IsFull()**
    * These are simple checks based on the pointers:
        * `IsEmpty()` returns `true` if `front == -1`.
        * `IsFull()` returns `true` if `(rear + 1) % MAX_SIZE == front`.

---

## Key Properties

* **FIFO Principle:** The First-In, First-Out rule is strictly maintained.
* **Circular Behavior:** The last and first positions of the array are treated as adjacent.
* **Efficient Space Utilization:** This is its defining property. Dequeued slots are immediately available for reuse.
* **Fixed Capacity:** The maximum size is determined by the underlying array and does not change.

---

## Advantages 👍

* **Highly Space-Efficient:** It utilizes the fixed array space to its full potential, preventing the waste seen in simple array queues.
* **Fast and Consistent Performance:** All core operations (`enqueue`, `dequeue`, `peek`) are performed in constant time, `$O(1)`.
* **Simple Logic:** The modulo arithmetic provides an elegant and relatively simple solution to the space wastage problem.

---

## Disadvantages 👎

* **Fixed Size:** The primary limitation is its static capacity. It cannot grow dynamically, which can lead to overflow if the size is underestimated.
* **Slightly More Complex Implementation:** The logic for the boundary conditions (`IsEmpty`, `IsFull`) is more nuanced than in a linear queue.

---

## Applications

A circular queue is the standard and preferred method for implementing a bounded (fixed-size) queue.

* **CPU Scheduling:** Operating systems use circular queues to manage processes in a round-robin fashion, cycling through them continuously.
* **Data Buffers:** Widely used for I/O buffers, network packet queues, and media streaming, where data is continuously being written and read.
* **Traffic Light Control Systems:** Managing the cyclical pattern of traffic lights.
* **Memory Management:** Used in memory buffers where a fixed block of memory is shared and reused by different processes.

---

## Time Complexity

| Operation          | Complexity |
| :----------------- | :--------: |
| **Enqueue** |   `$O(1)`  |
| **Dequeue** |   `$O(1)`  |
| **Peek / Front** |   `$O(1)`  |
| **IsEmpty / IsFull**|   `$O(1)`  |