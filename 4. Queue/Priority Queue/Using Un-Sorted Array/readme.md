## Priority Queue with an Unsorted Array: Fast Insert, Slow Retrieve

Implementing a **Priority Queue** using an **unsorted array** is the most straightforward approach. The core idea is to add new elements quickly without maintaining any specific order, and only perform the work of finding the highest-priority item when it needs to be retrieved.

Think of it like a disorganized pile of tasks on your desk. Adding a new task is easy—you just toss it on the pile. However, when you need to work on the *most important* task, you have to sift through every single paper on the desk to find it.

***Note: Understand Flow via Code in `priorityQueue.c`***

---

## How It Works: The Logic

The implementation is managed by a simple array and logic that separates the work of insertion from retrieval.

* **The Array:** A standard array (either fixed-size or dynamic) is used to store the elements. The elements are kept in the order they were inserted, **not** in priority order.
* **Insertion Logic:** To insert a new element, it is simply appended to the end of the array. This is a very fast operation.
* **Retrieval Logic:** To find the element with the highest priority (for `peek` or `delete`), a loop must iterate through the entire array from beginning to end, keeping track of the highest-priority element found so far.

---

## Operations and Algorithms

The performance of this implementation is defined by a trade-off: `insert` is fast, while `peek` and `delete` are slow.

* **Insert(element, priority)**
    * **Goal:** Add a new element to the queue.
    * **Algorithm:** Add the new element to the next available position at the end of the array.
    * **Complexity:** `$O(1)` (or amortized `$O(1)` if using a dynamic array that might need to resize).

* **Delete-Highest-Priority()**
    * **Goal:** Find and remove the element with the highest priority.
    * **Algorithm:**
        1.  Linearly scan the entire array to find the *index* of the element with the highest priority. This takes `$O(n)` time.
        2.  Store the element at that index to be returned.
        3.  To remove it, swap this element with the last element in the array and then decrease the array's effective size by one. This removal step is `$O(1)`.
    * **Complexity:** `$O(n)` (dominated by the search).

* **Peek()**
    * **Goal:** Find and return the highest-priority element without removing it.
    * **Algorithm:** Linearly scan the entire array to find the element with the highest priority and return it.
    * **Complexity:** `$O(n)`.

* **IsEmpty()**
    * **Goal:** Check if the queue is empty.
    * **Algorithm:** Check if the array's size is zero.
    * **Complexity:** `$O(1)`.

---

## Key Properties

* **Unordered Storage:** The defining characteristic. Elements are not stored in priority order.
* **Linear Scan for Retrieval:** Finding the highest-priority item always requires a full search of the array.
* **Fast Insertion:** Appending an element to the end of the array is a constant-time operation.

---

## Advantages 👍

* **Extremely Fast Insertions:** The `$O(1)` insertion time is the primary and only significant advantage of this implementation.
* **Simple Implementation:** The logic is very easy to understand and code.

---

## Disadvantages 👎

* **Very Slow Retrieval and Deletion:** The `$O(n)` complexity for `peek` and `delete` makes this implementation impractical for most priority queue use cases, as retrieving the highest-priority element is a core function.
* **Poor Scalability:** Performance degrades linearly as the number of elements grows, making it unsuitable for large datasets.

---

## Applications

This implementation is rarely used in production environments due to its poor retrieval performance.

* **Educational Tool:** It serves as an excellent baseline to demonstrate the performance trade-offs and to motivate the need for more efficient implementations like heaps.
* **Niche Scenarios:** It is only viable in situations where insertions vastly outnumber retrievals. For example, if you need to collect a large number of items quickly and then process the single highest-priority item only once at the very end.

---

## Time Complexity Summary

| Operation          | Complexity | Explanation                                      |
| :----------------- | :--------: | :----------------------------------------------- |
| **Insert** |   `$O(1)`  | A simple append operation.                       |
| **Delete-Highest** |   `$O(n)`  | Dominated by the linear search.                  |
| **Peek** |   `$O(n)`  | Requires a full scan to find the best element.   |
| **IsEmpty** |   `$O(1)`  | A simple size check.                             |