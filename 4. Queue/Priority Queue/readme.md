## Priority Queue: Not First-In, First-Out, but First-in-Importance 🏆

A **Priority Queue** is an abstract data structure similar to a regular queue, but with a crucial difference: it does not follow the FIFO (First-In, First-Out) principle. Instead, every element is assigned a **priority**, and elements are served in order of importance. The element with the **highest priority** is removed first, regardless of when it was added.

A perfect analogy is an emergency room waiting area. Patients are treated based on the severity of their condition (their priority), not just their arrival time. A critical patient who just arrived will be seen before a stable patient who has been waiting longer.

---

### Implementation

![PQ](/assets/priorityQueue.png)
![PQ2](/assets/priorityQueue2.png)

---

## How It Works: The Priority Rule

A priority queue can be configured in one of two ways, depending on what "highest priority" means for a given problem:

* **Min-Priority Queue:** Lower values indicate a higher priority. The `dequeue` operation removes the element with the **minimum** value. This is used in algorithms like Dijkstra's, where you want to find the path with the smallest distance.
* **Max-Priority Queue:** Higher values indicate a higher priority. The `dequeue` operation removes the element with the **maximum** value. This is used in task schedulers where jobs with a higher importance score should be run first.

---

## Implementation Methods

A Priority Queue is an abstract concept; its performance depends entirely on the underlying data structure used to build it. Here are the common methods and their trade-offs:

* **1. [Using an Unsorted Array or List](Using%20Un-Sorted%20Array/readme.md)**

* **2. [Using a Sorted Array or List](Using%20Sorted%20Array/readme.md)**

* **3. Using a Heap (The Standard and Most Efficient Method)**
    * A **Heap** is a specialized tree-based data structure that perfectly suits the needs of a priority queue.
    * **Insert:** Efficient (`$O(\log n)`). The new element is added to the end, then "bubbles up" to its correct position.
    * **Delete Highest Priority:** Efficient (`$O(\log n)`). The top element is removed, the last element takes its place, and then "bubbles down" to its correct position.
    * **Peek Highest Priority:** Very fast (`$O(1)`). The most important element is always at the root of the heap.
    * **Conclusion:** **This is the best implementation**, offering an excellent and efficient balance for all core operations.

---

## Core Operations

The abstract operations for a priority queue are:

* **Insert(element, priority):** Adds an element to the queue with its associated priority.
* **Delete-Highest-Priority():** Removes and returns the element with the highest priority.
* **Peek():** Returns the element with the highest priority without removing it.
* **IsEmpty():** Checks if the queue contains any elements.

---

## Key Properties

* **Priority-Based Ordering:** This is its defining characteristic. The logical order is determined by priority, not insertion time.
* **Not FIFO:** It explicitly violates the First-In, First-Out rule.
* **Implementation-Dependent Performance:** The efficiency of its operations is a direct result of the underlying data structure (e.g., array vs. heap).
* **Abstract Data Type:** It is a set of rules and operations, not a single concrete structure.

---

## Advantages 👍

* **Efficiently Manages Priorities:** It is specifically designed to always provide quick access to the most important item in a collection.
* **Simplifies Complex Algorithms:** Many powerful algorithms, such as Dijkstra's for shortest paths and Prim's for minimum spanning trees, are made much simpler and more efficient by using a priority queue.

---

## Disadvantages 👎

* **Slower than Simple Queues:** The overhead of maintaining the priority order makes its operations slower than the guaranteed `$O(1)` enqueue/dequeue of a simple FIFO queue.
* **Implementation Complexity:** A proper, efficient implementation (like a binary heap) is significantly more complex to code from scratch than a basic queue or stack.

---

## Applications

Priority queues are essential in many algorithms and systems that deal with scheduling and optimization.
* **Graph Algorithms:**
    * **Dijkstra's Shortest Path Algorithm:** To always select the unvisited vertex with the smallest known distance from the source.
    * **Prim's Algorithm:** To find a minimum spanning tree by always adding the cheapest edge to the growing tree.
* **Operating Systems:** Used in process schedulers to decide which task to run next based on priority levels.
* **Data Compression:** Used in Huffman coding algorithms to build the optimal prefix code tree.
* **A* Search Algorithm:** A popular pathfinding algorithm used in AI and video games to explore the most promising routes first.

---

## Time Complexity Summary

This table clearly shows why the Heap is the preferred implementation.

| Operation         | Unsorted Array | Sorted Array | **Heap (Standard)** |
| :---------------- | :------------: | :----------: | :-----------------: |
| **Insert** |     `$O(1)`      |    `$O(n)`   |    **`$O(\log n)`** |
| **Delete-Highest**|     `$O(n)`      |    `$O(1)`   |    **`$O(\log n)`** |
| **Peek** |     `$O(n)`      |    `$O(1)`   |      **`$O(1)`** |