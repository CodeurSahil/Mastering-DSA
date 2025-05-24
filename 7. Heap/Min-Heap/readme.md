# Min-Heap Data Structure Explained

A **Min-Heap** is a specialized tree-based data structure that satisfies the **min-heap property**: for every node `i` other than the root, the value of the parent node is less than or equal to the value of the current node (`parent(i) <= A[i]`). This property ensures that the root node always contains the smallest element in the heap. Min-heaps are a fundamental data structure for implementing priority queues and are used in various algorithms.

---

## Properties of a Min-Heap

1.  **Min-Heap Property:** For any node `i`, `A[parent(i)] <= A[i]`.
2.  **Complete Binary Tree:** A min-heap is a complete binary tree, meaning all levels are fully filled except possibly the last level, which is filled from left to right. This structure allows for efficient array-based implementation.

---

## Array Representation

A min-heap is typically implemented using an array. For a node at index `i` (0-indexed):

* **Parent(i):** `floor((i - 1) / 2)`
* **Left Child(i):** `2 * i + 1`
* **Right Child(i):** `2 * i + 2`

---

## Basic Operations

### 🔹 Insertion

1.  Add the new element to the end of the array (which corresponds to the last level of the complete binary tree).
2.  **Heapify Up (Bubble Up):** Compare the new element with its parent.
    * If the new element is smaller than its parent, swap them.
    * Repeat this process, moving up the tree, until the min-heap property is satisfied or the element becomes the root.

    **Example:** Inserting `3` into the min-heap `[5, 6, 7, 8, 9]`:

    1.  Heap becomes `[5, 6, 7, 8, 9, 3]`
    2.  Compare `3` with parent `9`. `3 < 9`, so swap: `[5, 6, 7, 8, 3, 9]`
    3.  Compare `3` with parent `8`. `3 < 8`, so swap: `[5, 6, 7, 3, 8, 9]`
    4.  Compare `3` with parent `7`. `3 < 7`, so swap: `[5, 6, 3, 7, 8, 9]`
    5.  Compare `3` with parent `6`. `3 < 6`, so swap: `[5, 3, 6, 7, 8, 9]`
    6.  Compare `3` with parent `5`. `3 < 5`, so swap: `[3, 5, 6, 7, 8, 9]`

    The time complexity of insertion is **O(log n)**, where `n` is the number of elements in the heap.

### 🔹 Extraction of Minimum (Remove Root)

1.  Replace the root element (the minimum) with the last element of the array.
2.  Remove the last element from the array, effectively reducing the heap size by one.
3.  **Heapify Down (Bubble Down):** Compare the new root element with its children.
    * If the root is larger than either of its children, swap it with the smaller child.
    * If the root is larger than both children, swap it with the smaller of the two children.
    * Repeat this process, moving down the tree, until the min-heap property is satisfied or the element becomes a leaf.

    **Example:** Extracting the minimum from the min-heap `[3, 5, 6, 7, 8, 9]`:

    1.  Swap root `3` with last element `9`: `[9, 5, 6, 7, 8, 3]`
    2.  Remove the last element: Heap is now conceptually `[9, 5, 6, 7, 8]`
    3.  Heapify down `9`:
        * Compare `9` with children `5` and `6`. Smaller child is `5`. Swap: `[5, 9, 6, 7, 8]`
        * Compare `9` with children `7` and `8`. Smaller child is `7`. Swap: `[5, 7, 6, 9, 8]`
        * `9` is now a leaf, heapify down complete.

    The time complexity of extracting the minimum is **O(log n)**.

### 🔹 Peek (Get Minimum)

* The minimum element in a min-heap is always at the root of the tree, which corresponds to the first element in the array (index 0).
* This operation takes **O(1)** time.

### 🔹 Heapify (Build Min-Heap)

* This process converts an arbitrary array into a min-heap.
* One efficient method is to iterate through the array from the first non-leaf node (index `floor(n/2) - 1` for a 0-indexed array of size `n`) up to the root (index 0) and apply the `heapify down` operation on each of these nodes.
* The time complexity of building a min-heap using this method is **O(n)**.

---

## Applications of Min-Heaps

Min-heaps are crucial in various applications:

* **Priority Queues:** Implementing priority queues where elements with lower priority values are served before elements with higher priority values.
* **Heap Sort:** As part of the heap sort algorithm, a min-heap (or max-heap) can be used to efficiently sort elements in O(n log n) time.
* **Graph Algorithms:** Used in algorithms like Dijkstra's algorithm for finding the shortest paths in a graph and Prim's algorithm for finding the minimum spanning tree.
* **Median Maintenance:** Maintaining the median of a stream of numbers efficiently. A combination of a min-heap and a max-heap can be used.
* **K Smallest Elements:** Efficiently finding the k smallest elements in a large dataset.

---

## Advantages of Min-Heaps

* **Efficient Retrieval of Minimum:** The smallest element can be accessed in O(1) time.
* **Efficient Insertion and Extraction:** Insertion and extraction of the minimum element take O(log n) time.
* **Efficient Building:** A min-heap can be built from an array in O(n) time.
* **Space Efficiency:** Can be efficiently implemented using an array, minimizing overhead.

---

## Disadvantages of Min-Heaps

* **Inefficient Search for Arbitrary Elements:** Searching for an element other than the minimum can take O(n) time as the heap structure does not maintain a sorted order for non-root elements.
* **Not Inherently Sorted:** A min-heap does not provide a sorted traversal of its elements directly. To get sorted output, the elements need to be extracted one by one, which takes O(n log n) time.

---

## Time Complexity

| Operation             | Time Complexity |
| --------------------- | --------------- |
| Insertion             | O(log n)      |
| Extraction of Minimum | O(log n)      |
| Peek (Get Minimum)    | O(1)          |
| Heapify (Build)       | O(n)          |
| Search                | O(n)          |

*Where n is the number of elements in the min-heap.*