## Binary Tree: The Two-Child Hierarchy

A **Binary Tree** is a fundamental hierarchical data structure where each node has **at most two children**. These children are referred to as the **left child** and the **right child**.

This simple, elegant structure is the foundation for many of the most important and efficient data structures in computer science, including Binary Search Trees, Heaps, and various self-balancing trees.

***Note: Understand Flow via Code in `binaryTree.c`***

---

## Types of Binary Trees

Binary trees can be classified into several categories based on their structure.

* **Full Binary Tree:** A tree in which every node has either **0 or 2 children**. There are no nodes with only one child.
  - Every node has **0 or 2 children**.
  - Example:
    ```plaintext
          10
         /  \
        20   30
       / \   / \
      40 50 60 70
    ```

* **Complete Binary Tree:** A tree in which all levels are completely filled, except possibly the last level. The last level must be filled from **left to right**. This structure is a requirement for Binary Heaps.
  - All levels are filled **except possibly the last**, which is filled from **left to right**.
  - Example:
    ```plaintext
          10
         /  \
        20   30
       / \   /
      40 50 60
    ```

* **Perfect Binary Tree:** A tree that is both **full** and **complete**. All internal nodes have two children, and all leaf nodes are at the same level.
  - All internal nodes have **two children**, and all leaf nodes are at the **same level**.
  - Example:
    ```plaintext
          10
         /  \
        20   30
       / \   / \
      40 50 60 70
    ```

* **Balanced Binary Tree:** A tree where the height of the left and right subtrees of any node differ by at most 1. This property is key to ensuring efficient operations in structures like AVL trees.
* **Degenerate (or Pathological) Tree:** A tree where each parent node has only one child. It essentially behaves like a linked list and represents the worst-case scenario for tree performance.
* **Skewed Binary Tree**
  - **Left-Skewed**: All nodes have **only left children**.
  - **Right-Skewed**: All nodes have **only right children**.
  - Example:
    ```plaintext
      Left-Skewed      Right-Skewed
          10                 10
         /                   \
        20                   20
       /                      \
      30                       30
    ```

---

## Traversal Algorithms

Traversal is the process of visiting every node in the tree exactly once.

* **Depth-First Search (DFS):** This strategy goes as deep as possible down one path before backtracking.
    * **In-order (Left, Root, Right):** Visits the left subtree, then the root, then the right subtree.
    * **Pre-order (Root, Left, Right):** Visits the root, then the left subtree, then the right subtree.
    * **Post-order (Left, Right, Root):** Visits the left subtree, then the right subtree, then the root.

* **Breadth-First Search (BFS) / Level-Order Traversal:**
    * This strategy explores the tree level by level, from top to bottom and left to right. It uses a **queue** to manage which nodes to visit next.

---

## Operations and Algorithms

For a general binary tree (unlike a Binary Search Tree), there are no ordering rules, so operations often require a full traversal.

* **Insert(value)**
    * **Goal:** Add a new node to the tree.
    * **Algorithm:** Since there's no fixed rule, a common method is to insert the new node at the first available position. This is typically done using a level-order traversal (BFS) to find the first parent node with an empty left or right child slot.

* **Search(value)**
    * **Goal:** Find a node with a specific value.
    * **Algorithm:** Because there is no order, you must potentially visit every node. This requires a full tree traversal (either DFS or BFS).
        1.  Start at the root.
        2.  If the current node's value matches, the search is successful.
        3.  Otherwise, recursively search the left and right subtrees until the value is found or all nodes have been visited.

* **Delete(node)**
    * **Goal:** Remove a node from the tree.
    * **Algorithm:** This is a complex operation in a general binary tree. A common approach is:
        1.  Find the node to be deleted.
        2.  Find the deepest, rightmost node in the tree.
        3.  Copy the data from the deepest node to the node you want to delete.
        4.  Delete the deepest node.

---

## Key Properties

* **Maximum Two Children:** Each node can have a left child, a right child, both, or neither.
* **Hierarchical:** Represents parent-child relationships.
* **Recursive Structure:** A binary tree can be defined recursively as a root node connected to a left binary subtree and a right binary subtree.

---

## Advantages 👍

* **Foundation for Advanced Structures:** It serves as the fundamental building block for many of the most efficient data structures, including Binary Search Trees, Heaps, and Expression Trees.
* **Naturally Models Binary Decisions:** The structure is a perfect fit for processes that involve a series of binary (yes/no, true/false) choices, like in decision trees.

---

## Disadvantages 👎

* **Inefficient Search (in general form):** Without the ordering property of a Binary Search Tree, finding an element requires a full traversal, which takes `$O(n)` time.
* **No Strict Rules for Insertion:** There is no single "correct" place to insert a new node, which can lead to unbalanced trees and poor performance if not managed carefully.

---

## Applications

* **Expression Trees:** Used by compilers to parse and evaluate mathematical expressions (e.g., `(a + b) * c`).
* **Huffman Coding Trees:** Used in data compression algorithms to generate optimal prefix codes.
* **Binary Space Partitioning (BSP) Trees:** Used in computer graphics and video games to efficiently determine which objects in a scene are visible.
* **Foundation for BSTs and Heaps:** It is the underlying structure upon which these more powerful data structures are built.

---

## Time Complexity Summary

For a general, potentially unbalanced binary tree:

| Operation | Time Complexity | Explanation                                          |
| :-------- | :-------------: | :--------------------------------------------------- |
| **Search**|     `$O(n)`     | Must potentially visit every node.                   |
| **Insert**|     `$O(n)`     | Dominated by the search for an insertion spot.       |
| **Delete**|     `$O(n)`     | Dominated by finding the node and its replacement. |
| **Traversal**|     `$O(n)`     | Must visit every node once.                          |