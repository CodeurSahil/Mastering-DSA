
# Binary Search Tree (BST)

## Introduction

A **Binary Search Tree (BST)** is a special type of binary tree in which each node contains a key greater than all the keys in its left subtree and less than those in its right subtree.

---

## Operations

### 🔹 Insertion
1. Start at the Root node.
2. Compare the value to be inserted with the current node:
   - If smaller, go to the left subtree.
   - If greater, go to the right subtree.
3. Repeat the process until a NULL position is found.
4. Insert the new node at that position.

### 🔹 Search
1. Start at root.
2. Compare target with current node:
   - If equal → found
   - If less → go to left subtree
   - If greater → go to right subtree

### 🔹 Deletion
1. Find the node to be deleted.
2. Handle one of the three cases:
   - No children: Simply delete the node.
   - One child: Replace the node with its child.
   - Two children:
      - Find the inorder successor (leftmost node in the right subtree).
      - Copy its value to the current node.
      - Delete the inorder successor.

### 🔹 Inorder Traversal (DFS)
- Traverse Left → Visit Root → Traverse Right

### 🔹 Preorder Traversal (DFS)
- Visit Root → Traverse Left → Traverse Right

### 🔹 Postorder Traversal (DFS)
- Traverse Left → Traverse Right → Visit Root

### 🔹 Level Order Traversal (BFS)
- Use a queue.
- Enqueue root → loop until queue empty:
  - Dequeue → visit → enqueue children

### 🔹 Find Height
- Height = max(height of left, height of right) + 1

---

## Properties

- Each node has **at most two children**.
- The **left subtree** contains only nodes with values **less than the parent node**.
- The **right subtree** contains only nodes with values **greater than the parent node**.
- No duplicate nodes are allowed.

---

## Advantages

- **Efficient Search**: Average time complexity is **O(log n)**.
- **Dynamic Size**: Unlike arrays, the size can grow or shrink dynamically.
- **Sorted Output**: Inorder traversal gives elements in sorted order.

---

## Disadvantages

- **Unbalanced Trees**: In the worst case (e.g., sorted input), BST becomes a skewed tree with **O(n)** operations.
- **Complex Rebalancing**: No self-balancing in normal BST; requires additional logic (e.g., AVL, Red-Black).

---

## Applications

- **Search Operations**: Efficient search operations for dynamic data sets.
- **Databases**: Indexing structures use variations of BST.
- **Memory Allocation**: Used in managing memory (heaps use tree structure).
- **Auto-complete / Spell Check**: Modified BSTs like Tries.

---

## Time Complexity

| Operation | Average Case | Worst Case |
|-----------|---------------|-------------|
| Search    | O(log n)      | O(n)        |
| Insert    | O(log n)      | O(n)        |
| Delete    | O(log n)      | O(n)        |

*Worst case occurs when BST becomes unbalanced.*
