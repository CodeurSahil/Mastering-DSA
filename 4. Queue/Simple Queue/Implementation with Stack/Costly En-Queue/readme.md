## Queue from Stacks: The Costly Enqueue Method

This is a specific algorithm for simulating a **FIFO (First-In, First-Out)** queue using two **LIFO (Last-In, First-Out)** stacks. The core idea is to make the **`enqueue` operation do all the hard work** of maintaining the correct FIFO order. This ensures that the oldest element is always at the top of the main stack, making the `dequeue` operation trivial and fast.

Think of it like adding a new book to the *bottom* of an existing stack. You must first take all the books off, place the new one down, and then carefully place all the old books back on top in their original order.

***Note: Understand Flow via Code in `simpleQueue.c`***

---

## How It Works: The Logic

This method uses two stacks, which we'll call `main_stack` and `temp_stack`, to manage the process.

* **`main_stack`:** This stack holds the final, correctly ordered queue elements. The element at the top is always the oldest one (the front of the queue).
* **`temp_stack`:** This is a helper stack used only during the `enqueue` process to temporarily hold elements.

Let's walk through an example. Imagine `main_stack` holds `[C, B, A]` from top to bottom. This represents a queue where `C` was added first.

**To `enqueue` a new element `D`:**
1.  **Transfer:** All elements (`C`, `B`, `A`) are popped from `main_stack` and pushed onto `temp_stack`. `temp_stack` now holds `[A, B, C]`.
2.  **Insert:** The new element `D` is pushed onto the now-empty `main_stack`. `main_stack` is now `[D]`.
3.  **Return:** All elements are popped from `temp_stack` and pushed back onto `main_stack`. `main_stack` now holds `[C, B, A, D]`.

The order is preserved, with the oldest element `C` still at the top, ready to be dequeued.

---

## Operations and Algorithms

The complexity is concentrated entirely within the `enqueue` operation.

* **Enqueue(value)**
    * **Goal:** Add a new element to the rear of the queue.
    * **Algorithm:**
        1.  While `main_stack` is not empty, pop each element and push it onto `temp_stack`.
        2.  Push the new `value` onto `main_stack`.
        3.  While `temp_stack` is not empty, pop each element and push it back onto `main_stack`.

* **Dequeue()**
    * **Goal:** Remove the element from the front of the queue.
    * **Algorithm:**
        1.  Check if `main_stack` is empty. If so, throw a **Queue Underflow** error.
        2.  Pop and return the element from `main_stack`.

* **Peek()** and **IsEmpty()**
    * `Peek()` returns the top element of `main_stack` without removing it.
    * `IsEmpty()` returns `true` if `main_stack` is empty.

---

## Key Properties

* **FIFO Behavior:** Successfully simulates the FIFO principle.
* **Order Maintenance:** The `main_stack` is always kept in a state where the top element is the oldest.
* **Expensive Insertion:** The defining property is that all the complex logic and performance cost is in the `enqueue` operation.

---

## Advantages 👍

* **Fast Dequeue and Peek:** The primary benefit is that `dequeue` and `peek` are guaranteed to be single-step, constant time (`$O(1)`) operations.

---

## Disadvantages 👎

* **Very Slow Enqueue:** The `$O(n)` complexity of the `enqueue` operation, which requires moving every single element twice, makes this method highly inefficient and impractical for most use cases.
* **High Memory Churn:** Constantly transferring all data between stacks for every insertion is computationally expensive.
* **Memory Overhead:** Requires space for two stacks instead of one.

---

## Applications

This algorithm is almost exclusively an **educational tool**.

* **Technical Interviews:** Used to test a candidate's ability to manipulate data structures and analyze algorithmic trade-offs.
* **Niche Scenarios:** Only theoretically suitable for a system where dequeues and peeks are extremely frequent and time-critical, while enqueues are exceptionally rare. In practice, other queue implementations are always preferred.

---

## Time Complexity

| Operation | Complexity | Explanation                                 |
| :-------- | :--------: | :------------------------------------------ |
| **Enqueue** |   `$O(n)`  | Must move all `n` elements twice.           |
| **Dequeue** |   `$O(1)`  | A single pop operation from the main stack. |
| **Peek** |   `$O(1)`  | A single peek operation on the main stack.  |
| **IsEmpty** |   `$O(1)`  | A single check on the main stack.         |