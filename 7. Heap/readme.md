# Heap Data Structure Explained

A **Heap** is a specialized tree-based data structure that satisfies the **heap property**:

* **Min-Heap Property:** For every node `i` other than the root, `parent(i) <= A[i]`, where `A` is the array representing the heap. The root node contains the smallest element.
* **Max-Heap Property:** For every node `i` other than the root, `parent(i) >= A[i]`. The root node contains the largest element.

Heaps are typically implemented using an array, which makes them very efficient in terms of both time and space complexity.

---

## Types of Heaps

There are two main types of heaps:

* **Min-Heap:** The smallest element is always at the root.
* **Max-Heap:** The largest element is always at the root.

---

## Basic Operations

### 🔹 Insertion

1.  Append the new element at the end of the heap array.
2.  **Heapify Up (or Bubble Up):** Compare the new element with its parent.
    * If it violates the heap property (e.g., in a min-heap, if the element is smaller than its parent), swap them.
    * Repeat this process until the heap property is satisfied or the element reaches the root.

### 🔹 Extraction (Remove Min/Max)

1.  Replace the root element (min or max) with the last element of the heap array.
2.  Remove the last element (which was the original root).
3.  **Heapify Down (or Bubble Down):** Compare the new root element with its children.
    * In a min-heap, if the root is larger than either child, swap it with the smaller child. If it's larger than both, swap with the smaller of the two.
    * In a max-heap, if the root is smaller than either child, swap it with the larger child. If it's smaller than both, swap with the larger of the two.
    * Repeat this process until the heap property is satisfied or the element becomes a leaf.

### 🔹 Peek (Get Min/Max)

* For a min-heap, the root element (at index 0 in the array) is the minimum.
* For a max-heap, the root element (at index 0 in the array) is the maximum.
* This operation takes **O(1)** time as the root is directly accessible.

### 🔹 Heapify (Build Heap)

* This operation converts an array into a heap.
* One common approach is to iterate through the array from the first non-leaf node up to the root and apply the `heapify down` operation on each node.
* The first non-leaf node is typically at index `n/2 - 1` (for a 0-indexed array of size `n`).
* The time complexity of building a heap is **O(n)**.

---

## Array Representation of a Heap

For a node at index `i` (0-indexed array):

* **Parent(i):** `floor((i - 1) / 2)`
* **Left Child(i):** `2 * i + 1`
* **Right Child(i):** `2 * i + 2`

---

## Properties

* It's a **complete binary tree** (all levels are completely filled except possibly the last level, which is filled from left to right).
* Satisfies the **heap property** (min-heap or max-heap).
* The root always contains the minimum (in a min-heap) or maximum (in a max-heap) element.

---

## Advantages

* **Efficient Extraction of Min/Max:** O(log n) time complexity.
* **Efficient Insertion:** O(log n) time complexity.
* **Efficient Building:** O(n) time complexity to build a heap from an array.
* **Space Efficiency:** Can be efficiently implemented using an array.

---

## Disadvantages

* **Inefficient Search for Arbitrary Elements:** Searching for an element that is not the minimum or maximum can take O(n) time as the heap structure doesn't maintain a sorted order for non-root elements.
* **Not Inherently Sorted:** Unlike a Binary Search Tree, a heap does not provide a sorted traversal of its elements without extra effort.

---

## Applications

* **Heap Sort:** An efficient sorting algorithm with O(n log n) time complexity.
* **Priority Queues:** Heaps are the underlying data structure for implementing priority queues, which are used in various algorithms like Dijkstra's algorithm and task scheduling.
* **Graph Algorithms:** Used in algorithms like Prim's algorithm and Dijkstra's algorithm for finding minimum spanning trees and shortest paths.
* **Median Maintenance:** Heaps can be used to efficiently track the median of a stream of numbers.
* **K Largest/Smallest Elements:** Heaps can efficiently find the k largest or smallest elements in an array.

---

## Time Complexity

| Operation        | Time Complexity |
| ---------------- | --------------- |
| Insertion        | O(log n)      |
| Extraction (Min/Max) | O(log n)      |
| Peek (Min/Max)   | O(1)          |
| Heapify (Build)  | O(n)          |
| Search           | O(n)          |

*Where n is the number of elements in the heap.*