# Binary Tree

## Introduction
A **Binary Tree** is a hierarchical data structure in which each node has at most **two children**: a **left child** and a **right child**. It is widely used in computer science for efficient data organization and retrieval.

---

## Key Characteristics
- **Hierarchical Structure**: Nodes are connected in a parent-child relationship.
- **Maximum Two Children**: Each node has at most **two** children.
- **Root Node**: The topmost node in the tree.
- **Leaf Nodes**: Nodes with no children.
- **Height**: The longest path from the root to a leaf.

---

## Types of Binary Trees

### **1️⃣ Full Binary Tree**
- Every node has **0 or 2 children**.
- Example:
  ```plaintext
        10
       /  \
      20   30
     / \   / \
    40 50 60 70
  ```

### **2️⃣ Complete Binary Tree**
- All levels are filled **except possibly the last**, which is filled from **left to right**.
- Example:
  ```plaintext
        10
       /  \
      20   30
     / \   /
    40 50 60
  ```

### **3️⃣ Perfect Binary Tree**
- All internal nodes have **two children**, and all leaf nodes are at the **same level**.
- Example:
  ```plaintext
        10
       /  \
      20   30
     / \   / \
    40 50 60 70
  ```

### **4️⃣ Skewed Binary Tree**
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

### **5️⃣ Degenerate (Pathological) Tree**
- Each parent has **only one child**, making it similar to a **linked list**.

---

## Binary Tree Operations Algorithms

### **Insertion Algorithm**
1. If the tree is empty, create a new node as the root.
2. Else, traverse the tree using BFS or DFS to find an empty spot.
3. Insert the new node as the left or right child of an appropriate parent.

### **Deletion Algorithm**
1. Find the node to be deleted.
2. Find the Inorder Successor Of the Tree:
  - Move to the right subtree of the node.
  - Keep moving left until the leftmost node is found.
3. Copy the inorder successor’s value to the node.
4. Delete the inorder successor from its original position.

### **Search Algorithm**
1. Start from the root node.
2. Compare the target value with the current node.
3. If found, return the node.
4. If smaller, search in the left subtree; if larger, search in the right subtree.

### **Inorder Traversal Algorithm (DFS) |O**
1. Recursively traverse the left subtree.
2. Visit the root node.
3. Recursively traverse the right subtree.

### **Preorder Traversal Algorithm (DFS) -O**
1. Visit the root node.
2. Recursively traverse the left subtree.
3. Recursively traverse the right subtree.

### **Postorder Traversal Algorithm (DFS) O-**
1. Recursively traverse the left subtree.
2. Recursively traverse the right subtree.
3. Visit the root node.

### **Level Order Traversal Algorithm (BFS)**
1. Create a queue and enqueue the root.
2. While the queue is not empty:
   - Dequeue a node.
   - Visit the node.
   - Enqueue its left and right children (if any).

### **Find Height of a Binary Tree**
1. If the tree is empty, return -1.
2. Compute the height of the left and right subtrees recursively.
3. Return the maximum of the two heights plus one.

## Conclusion
Binary Trees are fundamental data structures used in various fields of computing. Understanding their types, traversal methods, and applications helps in solving complex computational problems efficiently.

