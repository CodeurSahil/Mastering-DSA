## Binary Search Tree (BST): The Ordered Binary Tree 🌲

A **Binary Search Tree (BST)** is a special type of binary tree that maintains a crucial ordering property. This property allows for highly efficient searching, insertion, and deletion of elements.

The structure is governed by a simple set of rules for every node `N` in the tree, known as the **BST Invariant**:
* All keys in `N`'s **left subtree** must be **less than** `N`'s key.
* All keys in `N`'s **right subtree** must be **greater than** `N`'s key.
* Both the left and right subtrees must also be binary search trees.

This ordering allows you to discard half of the remaining tree at every step of a search, making it incredibly fast on average.

***Note: Understand Flow via Code in `binarySearchTree.c`***

---

## The Worst-Case Scenario: The Unbalanced Tree

The biggest weakness of a simple BST is its vulnerability to becoming unbalanced.

* **The Problem:** If you insert elements in a sorted or nearly-sorted order (e.g., 10, 20, 30, 40), the BST property forces all new nodes to be added to one side of the tree.
* **The Result:** The tree degenerates into a "skewed" shape, which is structurally identical to a linked list.
* **The Consequence:** In this state, the "discard half" advantage is lost. The performance of search, insert, and delete operations degrades from the desired `$O(\log n)` all the way down to `$O(n)`, which is no better than searching an unsorted list.
* **The Solution:** This critical flaw is the motivation for creating **self-balancing BSTs**, such as AVL Trees and Red-Black Trees, which automatically restructure themselves to prevent this worst-case scenario.

---

## Operations and Algorithms

The algorithms for a BST are elegant and naturally recursive, leveraging the ordering property at every step.

* **Search(value)**
    * **Goal:** Find if a value exists in the tree.
    * **Algorithm (starting at the root):**
        1.  If the current node is `null`, the value is not found.
        2.  If the `value` matches the current node's key, it has been found.
        3.  If the `value` is less than the current node's key, recursively search the **left subtree**.
        4.  If the `value` is greater than the current node's key, recursively search the **right subtree**.

* **Insert(value)**
    * **Goal:** Add a new value to the tree while maintaining the BST property.
    * **Algorithm:**
        1.  Follow the exact same path as the `Search` algorithm to find where the value *should* be.
        2.  When a `null` position is reached, insert a new node with the given value there.

* **Delete(value)**
    * **Goal:** Remove a node from the tree while preserving the BST property.
    * **Algorithm:**
        1.  First, use the `Search` logic to find the node to be deleted.
        2.  Once found, there are three possible cases:
            * **Case 1: The node is a leaf (no children).** Simply remove it.
            * **Case 2: The node has one child.** Replace the node with its single child.
            * **Case 3: The node has two children.** This is the most complex case. Find its **in-order successor** (the smallest node in the right subtree), copy the successor's value to the node you want to delete, and then recursively delete that successor node.

---

## Tree Traversal Algorithms

Traversal is the process of visiting every node in the tree exactly once. The three main Depth-First Search (DFS) traversals are:

* **In-order Traversal (Left, Root, Right)**
    * **Goal:** To visit nodes in their sorted, ascending order.
    * **Algorithm:**
        1.  Recursively traverse the left subtree.
        2.  Visit (e.g., print) the data in the current node.
        3.  Recursively traverse the right subtree.
    * **Use Case:** This is the most important traversal for a BST as it retrieves all elements in sorted order.

* **Pre-order Traversal (Root, Left, Right)**
    * **Goal:** To process the root node before its descendants.
    * **Algorithm:**
        1.  Visit the data in the current node.
        2.  Recursively traverse the left subtree.
        3.  Recursively traverse the right subtree.
    * **Use Case:** Useful for creating a copy of the tree, as it replicates the structure from the top down.

* **Post-order Traversal (Left, Right, Root)**
    * **Goal:** To process the root node after its descendants.
    * **Algorithm:**
        1.  Recursively traverse the left subtree.
        2.  Recursively traverse the right subtree.
        3.  Visit the data in the current node.
    * **Use Case:** Useful for deleting a tree, as it ensures all children are deleted before their parent.

---

## Key Properties

* **BST Invariant:** The fundamental rule: `left < root < right`.
* **No Duplicates:** A standard BST does not allow duplicate keys.
* **In-order Traversal Yields Sorted Data:** This is a key property. Traversing the tree in-order (Left-Root-Right) will visit all the nodes in their sorted, ascending order.

---

## Advantages 👍

* **Efficient on Average:** For a reasonably balanced tree, search, insertion, and deletion operations are very fast, taking `$O(\log n)` time.
* **Keeps Data Sorted:** The structure inherently maintains a sorted order, which is useful for many applications, such as easily finding the min/max values or performing range queries.
* **Dynamic:** The tree can grow and shrink efficiently as data is added or removed.

---

## Disadvantages 👎

* **Vulnerable to Unbalancing:** This is the main drawback. The performance guarantees are completely lost if the tree becomes skewed, with operations degrading to slow `$O(n)` time.
* **No Self-Balancing:** A simple BST has no built-in mechanism to prevent or fix an unbalanced state. It relies on the input data being somewhat random.

---

## Applications

* **Implementing Dictionaries and Maps:** Often used as the underlying structure for key-value stores that need to keep their keys in a sorted order.
* **Symbol Tables:** Used in compilers and interpreters to store information about variables, functions, etc.
* **Foundation for More Advanced Trees:** It is the conceptual basis for almost all advanced tree structures, including self-balancing trees (AVL, Red-Black) and multi-way trees (B-Trees).

---

## Time Complexity Summary

The performance of a BST is a tale of two scenarios: the average (balanced) case and the worst (unbalanced) case.

| Operation | Average Case (Balanced Tree) | Worst Case (Unbalanced Tree) |
| :-------- | :--------------------------: | :--------------------------: |
| **Search**|          `$O(\log n)`        |            `$O(n)`           |
| **Insert**|          `$O(\log n)`        |            `$O(n)`           |
| **Delete**|          `$O(\log n)`        |            `$O(n)`           |