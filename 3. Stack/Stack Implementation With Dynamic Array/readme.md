## Dynamic Array Stack: A Stack That Grows 🌿

A **Dynamic Array Stack** is a flexible implementation of the stack data structure that uses a resizable array as its underlying container. It solves the biggest problem of a fixed-size array stack—the dreaded **stack overflow**—by automatically growing or shrinking its capacity as needed.

This means you get the speed benefits of array-based storage without the limitation of a predefined size. It's the standard approach used in many modern programming language libraries.

***Note: Understand Flow via Code in `dynamicStack.c`***

---

## How It Works: The Resizing Logic

The "magic" of a dynamic stack lies in its ability to resize. This process is triggered when the stack becomes full or too empty.

* **Expansion (Growing)**
    * **When does it happen?** When a `push` operation is attempted on an array that is already full.
    * **What is the process?**
        1.  A new, larger array is created (typically **double** the size of the old one).
        2.  All elements from the old array are copied over to the new array.
        3.  The old array is discarded, and the stack continues using the new, expanded array.
    

* **Shrinking (Optional)**
    * **When does it happen?** When a `pop` operation leaves the array significantly underutilized (e.g., less than 25% full).
    * **What is the process?**
        1.  A new, smaller array is created (typically **half** the size of the old one).
        2.  The remaining elements are copied to the new, smaller array.
    * **Why is it optional?** Shrinking reclaims unused memory but adds computational overhead. It's a trade-off between memory usage and performance.

---

## Operations and Algorithms

The core stack operations are the same, but `push` and `pop` include the resizing logic.

* **Push(value)**
    * **Algorithm:**
        1.  Check if the array is full (`top == capacity - 1`).
        2.  If it is full, trigger the **Expansion** logic.
        3.  Increment `top`.
        4.  Insert the `value` at the `top` index.

* **Pop()**
    * **Algorithm:**
        1.  Check for stack underflow (if `top == -1`).
        2.  Retrieve the element at the `top` index.
        3.  Decrement `top`.
        4.  Optionally, check if the shrinking condition is met (e.g., `size < capacity / 4`). If so, trigger the **Shrinking** logic.
        5.  Return the retrieved element.

* **Peek()**, **IsEmpty()**, and **Size()**
    * These operations are identical to a fixed-array stack and have a complexity of `$O(1)`. They are not affected by resizing.

---

## Key Properties

* **LIFO Principle:** It fundamentally follows the Last-In, First-Out rule.
* **Dynamic Size:** Its capacity is not fixed and adapts to the number of elements.
* **Contiguous Storage:** At any point in time, the elements are stored in a contiguous block of memory.
* **Amortized Constant Time:** While some operations can be slow, the average time complexity for `push` and `pop` is constant.

---

## Advantages 👍

* **Avoids Stack Overflow:** The ability to grow on demand makes it robust for workloads of any size.
* **Efficient Memory Usage:** It avoids the need to pre-allocate a huge array, thus saving memory. It only uses what it needs (plus some extra capacity).
* **Fast Average Performance:** The cost of resizing is spread out over many fast `$O(1)` operations, making it highly efficient on average.

---

## Disadvantages 👎

* **Resizing Overhead:** The process of creating a new array and copying all elements is slow (`$O(n)`) and can cause a temporary performance lag.
* **Unpredictable Latency:** A `push` operation is usually instantaneous, but the one that triggers a resize will be noticeably slower. This can be an issue in real-time systems.
* **Slightly More Complex:** The implementation requires additional logic to handle the resizing process.

---

## Applications

Because of its flexibility and efficiency, the dynamic array stack is the default choice for most general-purpose applications.
* **General Programming:** Most standard library stack implementations in languages like Java, C++, and Python are dynamic.
* **Recursive Algorithms:** Safely handles deep recursion where the required stack depth is unknown beforehand.
* **Parsers and Compilers:** Used for parsing source code or evaluating complex expressions where the nesting level can vary greatly.
* **Applications with Unpredictable Workloads:** Ideal for any scenario where the number of items to be stored is not known in advance.

---

## Time Complexity

The concept of **amortized analysis** is crucial here. While a single operation can be slow, the average cost over a long sequence of operations is very low.

| Operation       | Worst-Case Complexity | Amortized (Average) Complexity |
| :-------------- | :-------------------: | :----------------------------: |
| **Push** |        `$O(n)$`        |             `$O(1)`             |
| **Pop** |        `$O(n)$`        |             `$O(1)`             |
| **Peek / Top** |        `$O(1)$`        |             `$O(1)`             |
| **IsEmpty / Size**|        `$O(1)$`        |             `$O(1)`             |