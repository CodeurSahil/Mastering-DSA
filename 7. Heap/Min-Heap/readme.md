## Min-Heap: Keeping the Smallest Element on Top ▼

A **Min-Heap** is a specialized tree-based data structure that satisfies the **min-heap property**. Its structure is a **complete binary tree** where for every node, its value is **less than or equal to** the values of its children.

This simple rule has a powerful consequence: the **smallest element** in the entire collection is always located at the root of the tree. This makes the min-heap a fundamental tool for implementing priority queues and is essential for many famous graph algorithms.

***Note: Understand Flow via Code in `minHeap.c`***

---

## The Array Representation

The key to a heap's efficiency is that its complete binary tree structure can be represented compactly in an array without needing any pointers. The parent-child relationships are calculated mathematically.

For a node at a given index `i` in a 0-indexed array:
* Its parent is at index: **`floor((i - 1) / 2)`**
* Its left child is at index: **`2 * i + 1`**
* Its right child is at index: **`2 * i + 2`**

---

## Operations and Algorithms

The core of a min-heap's functionality lies in its "heapify" procedures, which restore the min-heap property after any changes.

* **Insert**
    * **Goal:** Add a new element to the heap while maintaining the min-heap property.
    * **Algorithm (Heapify-Up / Bubble-Up):**
        1.  Add the new element to the first available spot in the array (the bottom-most, left-most position in the tree).
        2.  Compare the new element with its parent. If the new element is smaller, swap them.
        3.  Continue this "bubbling up" process, swapping with the parent until the element is no longer smaller than its parent or it has reached the root.

* **Extract-Min**
    * **Goal:** Remove the smallest element (the root) and restore the min-heap property.
    * **Algorithm (Heapify-Down / Sift-Down):**
        1.  Swap the root element (at index 0) with the *last* element in the array.
        2.  Remove and return the last element (which is the original minimum value).
        3.  The element that was previously at the end is now the new root and is likely too large for its position.
        4.  "Sift down" this element: compare it with its children. If it is larger than either child, swap it with its **smaller** child.
        5.  Repeat this process of moving down the tree until the element is smaller than both its children or it becomes a leaf node.

* **Peek (Get-Min)**
    * **Goal:** View the smallest element without removing it.
    * **Algorithm:** Simply return the element at index 0 of the array.

* **Build-Min-Heap**
    * **Goal:** Convert an unsorted array into a valid min-heap efficiently.
    * **Algorithm:** Start from the last non-leaf node in the array (`floor(n/2) - 1`) and move backwards up to the root (index 0). Apply the `Heapify-Down` operation to each of these nodes. This is more efficient than inserting elements one by one.

---

## Key Properties

* **Min-Heap Property:** The value of a parent node is always less than or equal to the values of its children.
* **Complete Binary Tree Structure:** All levels are full except possibly the last, which is filled strictly from left to right.
* **Array Implementation:** It is almost always implemented using an array for superior space and cache efficiency.
* **Smallest Element at Root:** The minimum value in the entire collection is always at index 0.

---

## Advantages 👍

* **Fastest Access to Minimum:** Getting the smallest element (`peek`) is a constant-time (`$O(1)`) operation.
* **Efficient Insertions and Extractions:** Both operations are logarithmic (`$O(\log n)`) because the "heapify" process only needs to traverse the height of the tree.
* **Space Efficient:** The array implementation has no extra memory overhead for pointers.
* **Fast Construction:** A min-heap can be built from an unsorted array in optimal linear time (`$O(n)`).

---

## Disadvantages 👎

* **Slow Search:** A min-heap is not designed for searching. Finding an element other than the minimum requires a linear scan of the entire array, which takes `$O(n)` time.
* **Not Sorted:** The structure is only partially ordered. Traversing the array from start to finish will not yield the elements in sorted order.

---

## Applications

* **Priority Queues:** This is the primary use case. Min-heaps are the standard implementation for min-priority queues, where the item with the smallest value is processed first.
* **Graph Algorithms:** It is the cornerstone of **Dijkstra's shortest path algorithm** (to always pick the unvisited node with the smallest distance) and **Prim's algorithm for minimum spanning trees** (to always pick the cheapest edge).
* **Finding the "K" Smallest Elements:** A min-heap is an excellent tool for efficiently finding the bottom K items in a large, unsorted dataset.

---

## Time Complexity Summary

| Operation                  | Time Complexity |
| :------------------------- | :-------------: |
| **Peek (Get Minimum)** |     `$O(1)`     |
| **Insert** |   `$O(\log n)`  |
| **Extract-Min** |   `$O(\log n)`  |
| **Build Heap (from array)**|     `$O(n)`     |
| **Search (for any element)** |     `$O(n)`     |