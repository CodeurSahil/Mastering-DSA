# 🌳 AVL Tree (Adelson-Velsky and Landis Tree)

## 📘 Introduction
An **AVL Tree** is a self-balancing **Binary Search Tree (BST)** where the difference between the heights of the left and right subtrees (called the **balance factor**) of any node is at most **1**. Named after its inventors **G.M. Adelson-Velsky and E.M. Landis**.

---

## 🧠 Properties

- It follows all rules of a **Binary Search Tree**.
- For every node:
    Balance Factor = Height(Left Subtree) - Height(Right Subtree)

- The **balance factor** must be in the range: `-1, 0, or 1`.

---

## 🔁 Rotations in AVL Tree

To restore balance, AVL Tree uses **rotations**:

### 🔹 1. **Left Rotation (LL Rotation)**
Occurs when a node is inserted in the **right subtree** of the right child.

### 🔹 2. **Right Rotation (RR Rotation)**
Occurs when a node is inserted in the **left subtree** of the left child.

### 🔹 3. **Left-Right Rotation (LR Rotation)**
Occurs when a node is inserted in the **right subtree** of the left child.

### 🔹 4. **Right-Left Rotation (RL Rotation)**
Occurs when a node is inserted in the **left subtree** of the right child.

---

## ⚙️ Basic Operations

### 🔹 Insertion
1. Insert like in a normal BST.
2. Check balance factor.
3. If unbalanced, perform suitable rotation.

### 🔹 Deletion
1. Delete like in a normal BST.
2. Update height and check balance factor.
3. If unbalanced, perform rotations to restore balance.

### 🔹 Searching
Same as BST; time complexity is `O(log n)` due to height-balanced nature.

---

## ⏱️ Time Complexity

| Operation  | Time Complexity |
|------------|------------------|
| Search     | O(log n)         |
| Insertion  | O(log n)         |
| Deletion   | O(log n)         |

---

## ✅ Advantages

- Guaranteed `O(log n)` operations due to strict balancing.
- Efficient for dynamic datasets with frequent insertions/deletions.
- Better performance than regular BSTs in worst-case scenarios.

---

## ❌ Disadvantages

- More complex to implement due to balancing logic.
- Rotation operations increase overhead in insertions/deletions.
- Slightly slower than unbalanced BSTs for search-only use cases.

---

## 🛠️ Applications

- Databases and file systems (e.g., **in-memory indexes**).
- Real-time applications where quick insertion/deletion is crucial.
- Applications where **sorted data** with guaranteed balance is needed.

---

## 📌 Example AVL Tree
       30
     /    \
    20    40
   /
  10

This tree is balanced because the difference in height of every node is ≤ 1.

---

## 📚 Summary

- AVL Tree is a **balanced BST** that uses **rotations** to maintain performance.
- Ensures operations like search, insert, and delete are all **logarithmic time**.
- Ideal when **data changes frequently** and **balance must be preserved**.
