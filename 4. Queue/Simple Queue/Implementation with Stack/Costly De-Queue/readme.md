## Queue from Stacks: The Costly Dequeue (Amortized) Method

This is the more common and generally more efficient algorithm for simulating a **FIFO (First-In, First-Out)** queue using two **LIFO (Last-In, First-Out)** stacks. The core idea is to make the `enqueue` operation extremely fast and to delay the work of re-ordering elements until a `dequeue` is actually requested.

This approach is famous for its **amortized `$O(1)$`** dequeue time, making it a classic computer science problem and a favorite in technical interviews.

***Note: Understand Flow via Code in `simpleQueue.c`***

---

## How It Works: The Logic and Amortized Analysis

This method uses two stacks, often called `input_stack` and `output_stack`, to manage the queue.

* **`input_stack`:** New elements are quickly pushed here. It acts as the "inbox," storing elements in reverse (LIFO) order.
* **`output_stack`:** Elements are popped from here. It acts as the "outbox," storing elements in the correct FIFO order, ready for removal.

The key is that elements are only moved from `input_stack` to `output_stack` when the `output_stack` is empty.

**Walkthrough Example:**
1.  We `enqueue(A)`, `enqueue(B)`, and `enqueue(C)`. All are pushed to `input_stack`, which now holds `[C, B, A]` from top to bottom. `output_stack` is empty.
2.  A `dequeue()` operation is called.
3.  The algorithm checks `output_stack` and finds it's empty. Now, the **transfer** happens: all elements are popped from `input_stack` and pushed to `output_stack`.
4.  `output_stack` now holds `[A, B, C]`, which is the correct FIFO order. `input_stack` is empty.
5.  The top element, `A`, is popped from `output_stack` and returned.
6.  Another `dequeue()` is called. This time, `output_stack` is **not empty**, so the expensive transfer step is skipped. `B` is popped and returned immediately. This is an `$O(1)` operation.

**Amortized Analysis Explained**
The slow `$O(n)` transfer operation only happens occasionally. After a transfer, the next `n-1` dequeues are all very fast `$O(1)` operations. The high cost of the one slow operation is "paid for" by the many fast ones. Over a long sequence of operations, the average cost of a dequeue is constant, or **amortized `$O(1)$`**.

---

## Operations and Algorithms

* **Enqueue(value)**
    * **Goal:** Add a new element to the queue.
    * **Algorithm:** Simply push the `value` onto `input_stack`.

* **Dequeue()**
    * **Goal:** Remove the oldest element from the queue.
    * **Algorithm:**
        1.  If `output_stack` is empty, transfer all elements from `input_stack` to `output_stack`.
        2.  If `output_stack` is still empty (meaning the whole queue was empty), throw a **Queue Underflow** error.
        3.  Pop and return the element from `output_stack`.

* **Peek()**
    * **Goal:** View the oldest element.
    * **Algorithm:**
        1.  Follows the same logic as `dequeue`: if `output_stack` is empty, transfer elements from `input_stack`.
        2.  Return the top element of `output_stack` without popping it.

* **IsEmpty()**
    * **Goal:** Check if the queue is empty.
    * **Algorithm:** Returns `true` only if both `input_stack` and `output_stack` are empty.

---

## Key Properties

* **FIFO Behavior:** Successfully simulates the FIFO principle.
* **Lazy Reversal:** The expensive re-ordering of elements is deferred until it's absolutely necessary.
* **Amortized Efficiency:** This is the defining performance characteristic of the algorithm.

---

## Advantages 👍

* **Extremely Fast Enqueue:** The `$O(1)` enqueue operation makes this method ideal for scenarios where elements are added much more frequently than they are removed.
* **Efficient on Average:** The amortized `$O(1)` time for dequeue makes it far more practical than the costly enqueue method for most use cases.

---

## Disadvantages 👎

* **Unpredictable Dequeue Latency:** A single `dequeue` operation can be either very fast (`$O(1)`) or very slow (`$O(n)`). This unpredictability can be a problem in real-time systems where consistent performance is required.
* **Memory Overhead:** Requires space for two stacks to simulate a single queue.

---

## Applications

This algorithm is primarily used in educational and interview settings.

* **Technical Interviews:** This is often considered the "correct" and more optimized answer when asked to implement a queue from stacks.
* **Algorithm Design:** It's a useful pattern in system design, such as in message queues or task systems where items are added rapidly but processed in batches.

---

## Time Complexity

The distinction between worst-case and amortized time is critical.

| Operation | Worst-Case Complexity | Amortized (Average) Complexity |
| :-------- | :-------------------: | :----------------------------: |
| **Enqueue** |        `$O(1)$`        |             `$O(1)`             |
| **Dequeue** |        `$O(n)$`        |             `$O(1)`             |
| **Peek** |        `$O(n)$`        |             `$O(1)`             |
| **IsEmpty** |        `$O(1)$`        |             `$O(1)`             |