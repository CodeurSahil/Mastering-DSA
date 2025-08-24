## AVL Tree: The Strictly Balanced Search Tree ⚖️

An **AVL Tree** is a self-balancing **Binary Search Tree (BST)** named after its inventors, Adelson-Velsky and Landis. Its defining feature is a strict balancing rule that keeps the tree's height as low as possible, guaranteeing that all major operations remain incredibly fast.

The core idea is simple: for every node in the tree, the height of its left and right subtrees can differ by at most **1**. If an insertion or deletion violates this rule, the tree automatically performs "rotations" to restore the balance.



---

## The Balance Factor: The Heart of an AVL Tree

The entire AVL mechanism revolves around a single property called the **Balance Factor**.

* **Definition:** `Balance Factor = height(left subtree) - height(right subtree)`
* **The Rule:** For a tree to be considered an AVL tree, the balance factor of **every single node** must be `-1`, `0`, or `1`.
* **Imbalance:** If an insertion or deletion causes any node's balance factor to become `-2` (right-heavy) or `2` (left-heavy), the tree is temporarily "unbalanced." This is the trigger for a rebalancing operation.

---

## Rotations: How AVL Trees Rebalance

Rotations are simple, localized operations that restructure a small part of the tree to restore its balance without violating the fundamental BST property (left < root < right). There are four cases that an imbalance can fall into.

* **1. Left-Left (LL) Case:** The imbalance is caused by an insertion into the left subtree of the left child.
    * **Solution:** A single **Right Rotation** on the unbalanced node.

* **2. Right-Right (RR) Case:** The imbalance is caused by an insertion into the right subtree of the right child.
    * **Solution:** A single **Left Rotation** on the unbalanced node.

* **3. Left-Right (LR) Case:** The imbalance is caused by an insertion into the right subtree of the left child.
    * **Solution:** A **Left Rotation** on the left child, followed by a **Right Rotation** on the main unbalanced node.

* **4. Right-Left (RL) Case:** The imbalance is caused by an insertion into the left subtree of the right child.
    * **Solution:** A **Right Rotation** on the right child, followed by a **Left Rotation** on the main unbalanced node.



---

## Operations and Algorithms

AVL operations build upon standard BST logic, with an added rebalancing step.

* **Search(value)**
    * **Goal:** Find a node with a specific value.
    * **Algorithm:** Exactly the same as a standard Binary Search Tree. The AVL's balance guarantees this search is always efficient.

* **Insert(value)**
    * **Goal:** Add a new node and rebalance the tree if necessary.
    * **Algorithm:**
        1.  Perform a standard BST insertion to place the new node.
        2.  Travel back up the tree from the new node's parent to the root.
        3.  For each node on this path, update its height and check its balance factor.
        4.  If a node is found to be unbalanced (balance factor of 2 or -2), perform the single appropriate rotation (LL, RR, LR, or RL) to fix it. Once one rotation is done, the entire tree is guaranteed to be balanced again.

* **Delete(value)**
    * **Goal:** Remove a node and rebalance the tree if necessary.
    * **Algorithm:**
        1.  Perform a standard BST deletion.
        2.  Travel back up the tree from the parent of the removed node.
        3.  For each node on this path, update its height and check its balance factor.
        4.  If a node is unbalanced, perform the appropriate rotation(s) to fix it. *Note: Unlike insertion, deletion may require multiple rotations as you travel up the tree.*

---

## Key Properties

* **BST Property:** For every node, all keys in the left subtree are smaller, and all keys in the right subtree are larger.
* **Strict Balance Property:** The balance factor of every node is always `-1`, `0`, or `1`.
* **Guaranteed Logarithmic Height:** Because of the strict balance, the height of an AVL tree with `n` nodes is always mathematically guaranteed to be `$O(\log n)`.

---

## Advantages 👍

* **Guaranteed Fast Performance:** It provides a hard guarantee that search, insert, and delete operations will **always** be efficient (`$O(\log n)`), even in the worst-case scenario. This makes its performance highly predictable.
* **Faster Lookups:** Because it is more strictly balanced than other self-balancing trees (like Red-Black Trees), search operations are often slightly faster.

---

## Disadvantages 👎

* **Complex Implementation:** The logic for tracking node heights and correctly performing the four different rotation cases is complex and can be difficult to implement and debug.
* **Higher Overhead on Insertion/Deletion:** The strict balancing rule means that rotations might be needed frequently. This adds a constant but significant overhead to every modification, potentially making it slower than less-strict trees in write-heavy applications.

---

## Applications

AVL trees are best suited for applications where lookups are the most frequent operation, but the data still changes often enough that a simple BST would become unbalanced.

* **Database Indexing:** Used where fast and predictable query times are critical, and the overhead of rebalancing is acceptable.
* **In-memory Dictionaries or Sets:** When a sorted collection with guaranteed worst-case performance is needed.
* **Any scenario requiring a balanced BST where lookups are more frequent than modifications.**

---

## Time Complexity Summary

The strict balancing of an AVL tree ensures there is no difference between average-case and worst-case performance.

| Operation | Time Complexity (Average & Worst) |
| :-------- | :-------------------------------: |
| **Search** |             `$O(\log n)`              |
| **Insert** |             `$O(\log n)`              |
| **Delete** |             `$O(\log n)`              |