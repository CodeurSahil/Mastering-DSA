## Heap: The Priority Queue's Engine ▲

A **Heap** is a specialized tree-based data structure that satisfies the **heap property**. It is structured as a **complete binary tree**, which allows it to be efficiently stored and manipulated in an array.

Its primary purpose is to always keep the element with the highest priority (either the largest or smallest value) at the root of the tree. This makes it the perfect underlying structure for implementing a Priority Queue.

---

## The Two Types of Heaps

A heap is defined by the relationship between a parent node and its children.

* **[Max-Heap](Max-Heap/readme.md):** The value of each parent node is **greater than or equal to** the values of its children. The **largest** element in the dataset is always at the root.
* **[Min-Heap](Min-Heap/readme.md):** The value of each parent node is **less than or equal to** the values of its children. The **smallest** element in the dataset is always at the root.

---

## The Array Representation

The key to a heap's efficiency is that it's a **complete binary tree**. This means all levels of the tree are filled, except possibly the last level, which is filled from left to right. This "no gaps" structure allows the entire tree to be represented compactly in an array without needing pointers.

For a node at a given index `i` in a 0-indexed array:
* Its parent is at index: **`floor((i - 1) / 2)`**
* Its left child is at index: **`2 * i + 1`**
* Its right child is at index: **`2 * i + 2`**

---

## Operations and Algorithms

The core of a heap is the "heapify" process, which restores the heap property after a modification.

* **Insert**
    * **Goal:** Add a new element to the heap while maintaining the heap property.
    * **Algorithm (Heapify-Up / Bubble-Up):**
        1.  Add the new element to the first available spot in the array (the bottom-left of the tree).
        2.  Compare the new element with its parent.
        3.  If it violates the heap property (e.g., it's larger than its parent in a max-heap), swap them.
        4.  Repeat this process, "bubbling up" the element until the heap property is restored or the root is reached.

* **Extract-Max / Extract-Min**
    * **Goal:** Remove the root element (the highest priority) and restore the heap property.
    * **Algorithm (Heapify-Down / Sift-Down):**
        1.  Swap the root element with the *last* element in the array.
        2.  Remove the last element from the array (this is the value you want to return).
        3.  The element that was previously at the end is now the new root, and it's likely in the wrong place.
        4.  Compare this new root with its children. If it violates the heap property, swap it with its larger (for max-heap) or smaller (for min-heap) child.
        5.  Repeat this process, "sifting down" the element until the heap property is restored.

* **Peek**
    * **Goal:** View the highest priority element without removing it.
    * **Algorithm:** Simply return the element at index 0 of the array.

---

## Key Properties

* **Heap Property:** It must satisfy either the Max-Heap or Min-Heap property throughout the tree.
* **Complete Binary Tree Structure:** This is a strict structural requirement that enables the efficient array implementation.
* **Partial Ordering:** A heap is not fully sorted, but it is ordered in a specific way that ensures the root is always the max/min element.

---

## Advantages 👍

* **Fast Access to Max/Min:** Getting the highest priority element (`peek`) is an extremely fast `$O(1)` operation.
* **Efficient Insertions/Deletions:** Both `insert` and `extract` are efficient logarithmic operations (`$O(\log n)`), as the "heapify" process only needs to traverse the height of the tree.
* **Space Efficient:** The array implementation has no overhead for pointers, making it very compact.
* **Fast Construction:** A heap can be built from an unsorted array in optimal linear time (`$O(n)`).

---

## Disadvantages 👎

* **Slow Search:** A heap is not designed for searching. Finding an element other than the root requires a linear scan of the array, which takes `$O(n)` time. For searching, a Binary Search Tree is far superior.
* **Not Sorted:** Traversing a heap from index 0 to `n` will not yield the elements in sorted order.

---

## Applications

* **Priority Queues:** This is the most common use case. Heaps are the standard, most efficient way to implement a priority queue.
* **Heap Sort:** An efficient, in-place sorting algorithm that uses a heap to sort elements in `$O(n \log n)` time.
* **Graph Algorithms:** Crucial for algorithms like **Dijkstra's** (for shortest path) and **Prim's** (for minimum spanning tree), which use a priority queue to efficiently manage which vertex to process next.
* **Finding the Kth Largest/Smallest Element:** A heap is an excellent tool for solving this common problem in `$O(n \log k)` time.

---

## Time Complexity Summary

| Operation          | Time Complexity |
| :----------------- | :-------------: |
| **Peek (Get Max/Min)** |     `$O(1)`     |
| **Insert** |   `$O(\log n)`  |
| **Extract-Max/Min**|   `$O(\log n)`  |
| **Build Heap (from array)**|     `$O(n)`     |
| **Search (for any element)** |     `$O(n)`     |