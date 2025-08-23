## Fixed-Array Stack: A Stack with Limits 📦

A **Fixed-Array Stack** is the most straightforward implementation of the stack data structure. It uses a static array of a pre-defined size to store its elements, meaning its **capacity is determined when it's created and cannot change** during runtime.

Think of it like a Pringles can—it can only hold a specific number of chips. Once it's full, you can't add any more, and if it's only half-full, the empty space remains. This makes it suitable for situations where the maximum number of items you need to store is known in advance.

***Note: Understand Flow via Code in `fixedStack.c`***

---

## How It Works: The Core Components

A fixed-array stack is managed by two simple components:

* **The Array:** A contiguous block of memory of a specific size (e.g., `MAX_SIZE`) that holds the elements of the stack.
* **The `top` Pointer:** An integer variable that keeps track of the *index* of the last element added. It is typically initialized to `-1` to indicate that the stack is empty.

---

## Operations and Algorithms

All operations are simple checks and manipulations of the `top` pointer and the array.

* **Push(value)**
    * **Goal:** Add an element to the top.
    * **Algorithm:**
        1.  First, check if the stack is full (`top == MAX_SIZE - 1`). If so, throw a **Stack Overflow** error.
        2.  Increment `top`.
        3.  Set `array[top] = value`.

* **Pop()**
    * **Goal:** Remove the top element.
    * **Algorithm:**
        1.  First, check if the stack is empty (`top == -1`). If so, throw a **Stack Underflow** error.
        2.  Retrieve the value from `array[top]`.
        3.  Decrement `top`.
        4.  Return the retrieved value.

* **Peek()**
    * **Goal:** View the top element without removing it.
    * **Algorithm:**
        1.  Check if the stack is empty.
        2.  If not, return the value at `array[top]`.

* **IsEmpty()** and **IsFull()**
    * These are simple checks:
        * `IsEmpty()` returns `true` if `top == -1`.
        * `IsFull()` returns `true` if `top == MAX_SIZE - 1`.

---

## Key Properties

* **LIFO Principle:** Follows the Last-In, First-Out rule.
* **Fixed Capacity:** The maximum number of elements it can hold is immutable.
* **Contiguous Memory:** Elements are stored side-by-side, which is efficient for CPU caching.
* **Direct Indexing:** The `top` pointer allows for direct access to the topmost element.

---

## Advantages 👍

* **Simple Implementation:** It's extremely easy to code and understand.
* **Very Fast Operations:** `Push`, `pop`, and `peek` are all `$O(1)` and have minimal overhead, making them exceptionally fast.
* **Memory Efficient:** There is no extra memory used for pointers or other metadata; the memory usage is exactly the size of the array.

---

## Disadvantages 👎

* **Risk of Stack Overflow:** This is the primary drawback. If the number of elements exceeds the pre-defined capacity, the stack cannot grow, and the program will fail.
* **Memory Waste:** If you allocate a large stack but only use a small portion, the unused memory is wasted and cannot be used by other parts of your program.
* **Inflexible:** It is not suitable for problems where the required stack size is unknown or varies significantly.

---

## Applications

A fixed-array stack is best used in resource-constrained environments or when the maximum number of items is predictable.

* **Embedded Systems:** Where memory is limited and must be allocated statically and managed carefully.
* **Function Call Stack:** The operating system typically allocates a fixed-size stack for each program thread. If a program has infinitely deep recursion, it will cause a real-world "stack overflow" error.
* **Static Code Analysis:** Used by compilers and tools where the maximum depth of operations can be determined before runtime.
* **Hardware-level Buffers:** Where a buffer of a fixed size is used to handle data.

---

## Time Complexity

The performance of a fixed-array stack is its greatest strength.

| Operation            | Complexity |
| :------------------- | :--------: |
| **Push** |   `$O(1)$`   |
| **Pop** |   `$O(1)`   |
| **Peek / Top** |   `$O(1)`   |
| **IsEmpty / IsFull** |   `$O(1)`   |
| **Search (by value)**|   `$O(n)`   |