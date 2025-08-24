## Trees: Organizing Data Hierarchically 🌳

A **Tree** is a non-linear, hierarchical data structure that consists of **nodes** connected by **edges**. Unlike linear structures like arrays or linked lists, trees are used to represent relationships and hierarchies, where each element has a parent-child relationship with other elements.

The best analogy is a family tree or an organizational chart. There is a single ancestor or CEO at the top (the **root**), who has children or subordinates, who in turn have their own children, and so on, branching downwards.

---

### Representation
![Tree](/assets/tree.png)

---

## Essential Tree Terminology

To understand trees, you need to know their vocabulary.

* **Node:** The fundamental part of a tree that contains data and pointers to its children.
* **Edge:** The connection or link between two nodes.
* **Root:** The topmost node of the tree. It is the only node with no parent.
* **Parent:** A node that has at least one child node.
* **Child:** A node that has a parent node.
* **Leaf Node:** A node that has no children. These are the "ends" of the tree.
* **Internal Node:** Any node that has at least one child (i.e., any node that is not a leaf).
* **Height:** The length of the longest path from the root to a leaf node.
* **Depth:** The length of the path from the root to a specific node.
* **Subtree:** A tree consisting of a node and all of its descendants.

---

## Common Types of Trees

"Tree" is a broad category. Here are some of the most important specific types:

* **[Binary Tree](Binary%20Tree/readme.md):** The most common type of tree, where each node has **at most two children**, referred to as the `left` child and the `right` child.
* **[Binary Search Tree (BST)](Binary%20Search%20Tree/readme.md):** A sorted binary tree with a special property: for any given node, all values in its **left subtree are smaller**, and all values in its **right subtree are larger**. This property enables very fast searching.
* **[Heap](../7.%20Heap/readme.md):** A specialized tree (usually a complete binary tree) used to implement **Priority Queues**. In a **Min-Heap**, the parent is always smaller than its children; in a **Max-Heap**, the parent is always larger.
* **[B-Tree](B-Trees/readme.md):** A multi-way tree where nodes can have many children. They are heavily used in **databases and filesystems** because they are optimized for systems that read and write large blocks of data.
* **[Trie (Prefix Tree)](Trie/readme.md):** A specialized tree for storing and searching for strings. Each edge represents a character, making it extremely efficient for tasks like autocomplete and spell-checking.
* **[AVL Tree](AVL%20Tree/readme.md):** A self-balancing Binary Search Tree. It maintains a strict balance by ensuring the height difference between the left and right subtrees of any node is at most 1. It uses "rotations" to rebalance itself after insertions or deletions, guaranteeing `$O(\log n)` performance.
* **[Red-Black Tree](Red-Black%20Tree/readme.md):** Another, more common type of self-balancing BST. Each node is colored "red" or "black," and a set of rules involving these colors ensures the tree remains approximately balanced. It's less strictly balanced than an AVL tree but often faster in practice because it requires fewer rotations on insertions and deletions.
* **[Segment Tree](Segment%20Tree/readme.md):** A specialized tree used primarily to answer **range queries** over an array (e.g., find the sum, minimum, or maximum of elements in a range `[i, j]`). It allows these queries to be answered in efficient `$O(\log n)` time.
* **[N-ary Tree](N-ary%20Tree/readme.md):** A general tree where a node can have **any number of children** (N children). This is in contrast to a binary tree, which can have at most two. File systems and organizational charts are good examples of N-ary trees.

---

## Tree Traversal Algorithms

Traversal is the process of visiting (or processing) every node in the tree exactly once.

* **Depth-First Search (DFS):** This strategy goes as deep as possible down one path before backtracking.
    * **In-order (Left, Root, Right):** For a BST, this traversal visits nodes in sorted ascending order.
    * **Pre-order (Root, Left, Right):** Useful for creating a copy of a tree.
    * **Post-order (Left, Right, Root):** Useful for deleting nodes from a tree (as you delete children before the parent).

* **Breadth-First Search (BFS):** Also known as **Level-Order Traversal**, this strategy explores the tree level by level, from top to bottom. It uses a **queue** to manage which node to visit next.

---

## Core Operations and Algorithms (for a BST)

The specific algorithms vary by tree type. Here are brief, recursive algorithms for a **Binary Search Tree (BST)**, which is the foundational type.

* **Search(value)**
    * **Goal:** Find if a value exists in the tree.
    * **Algorithm (starting at the root):**
        1.  If the current node is `null`, the value is not found.
        2.  If the `value` matches the current node's data, it's found.
        3.  If the `value` is less than the current node's data, search in the left child.
        4.  If the `value` is greater than the current node's data, search in the right child.

* **Insert(value)**
    * **Goal:** Add a new value to the tree while maintaining the BST property.
    * **Algorithm (starting at the root):**
        1.  If the current node is `null`, create a new node here with the given value.
        2.  If the `value` is less than the current node's data, recursively try to insert it in the left subtree.
        3.  If the `value` is greater than the current node's data, recursively try to insert it in the right subtree.

* **Delete(value)**
    * **Goal:** Remove a node with a specific value, preserving the BST property.
    * **Algorithm:**
        1.  First, search for the node to be deleted.
        2.  Once found, there are three cases:
            * **Case 1: The node is a leaf (no children).** Simply remove it.
            * **Case 2: The node has one child.** Replace the node with its single child.
            * **Case 3: The node has two children.** Find the *in-order successor* (the smallest value in the right subtree), copy its value to the current node, and then recursively delete the successor node.

---

## Key Properties

* **Hierarchical Structure:** Data is organized in parent-child relationships.
* **Non-linear:** Unlike arrays or linked lists, data is not stored sequentially.
* **Recursive Nature:** A tree can be defined recursively: it is a root node where each of its children is the root of its own smaller subtree.
* **Acyclic Graph:** A tree is a type of connected graph that has no cycles.

---

## Advantages 👍

* **Efficient Searching:** Balanced trees (like BSTs) provide very fast search, insertion, and deletion times, typically `$O(\log n)`.
* **Represents Hierarchical Data Naturally:** Perfect for modeling real-world structures like file systems, organizational charts, or XML/JSON data.
* **Dynamic and Flexible:** Trees can grow and shrink as needed, and their structure can be easily modified.

---

## Disadvantages 👎

* **Memory Overhead:** Each node in a tree requires extra memory to store pointers to its children (and sometimes its parent).
* **Complexity:** Implementing and managing trees, especially self-balancing ones, can be complex and prone to errors.
* **Risk of Unbalanced Trees:** A simple (non-balancing) BST can become "unbalanced" if data is inserted in a sorted or near-sorted order. This degrades its performance to that of a linked list (`$O(n)`).

---

## Applications

Trees are a fundamental data structure used in almost every area of computer science.
* **File Systems:** The directory and file structure on your computer is a tree.
* **Databases:** **B-Trees** are the foundation for almost all modern database indexing systems, allowing for incredibly fast data retrieval.
* **Compilers:** **Abstract Syntax Trees (ASTs)** are used to represent the structure of source code for analysis and compilation.
* **Artificial Intelligence:** **Decision trees** are a popular model for machine learning and classification tasks.
* **Computer Networks:** Used in routing algorithms (e.g., **spanning trees**) to find efficient paths and prevent loops.
* **GUI Toolkits:** The hierarchy of UI elements (windows, panels, buttons) is often represented as a tree.

---

## Time Complexity Summary

This table shows the performance for a **Binary Search Tree (BST)**, which is a common reference point.

| Operation | Average Case (Balanced Tree) | Worst Case (Unbalanced Tree) |
| :-------- | :--------------------------: | :--------------------------: |
| **Insert** |          `$O(\log n)`        |            `$O(n)`           |
| **Delete** |          `$O(\log n)`        |            `$O(n)`           |
| **Search** |          `$O(\log n)`        |            `$O(n)`           |
| **Traversal**|            `$O(n)`             |            `$O(n)`           |