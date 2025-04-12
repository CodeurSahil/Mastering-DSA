# Trees

## Introduction
A **Tree** is a hierarchical data structure that consists of nodes connected by edges. It is widely used in computer science for organizing data efficiently.

### **Key Characteristics**
- **Hierarchical Structure**: Nodes are arranged in a parent-child relationship.
- **Root Node**: The topmost node of a tree.
- **Edges**: Connections between nodes.
- **Leaf Nodes**: Nodes with no children.
- **Height**: The longest path from the root to a leaf.
- **Degree**: The number of children a node has.

---

## Types of Trees

### **1️⃣ Binary Tree**
- Each node has **at most two children**.
- Common types:
  - **Full Binary Tree**: Every node has 0 or 2 children.
  - **Complete Binary Tree**: All levels are filled except possibly the last.
  - **Perfect Binary Tree**: All internal nodes have two children, and all leaf nodes are at the same level.
  - **Skewed Binary Tree**: All nodes have only one child (left or right).

### **2️⃣ Binary Search Tree (BST)**
- Left subtree contains **smaller** values.
- Right subtree contains **greater** values.
- Provides efficient searching (O(log n)).

### **3️⃣ AVL Tree**
- A self-balancing **BST**.
- Height difference between left and right subtrees is at most 1.
- **Rotations (LL, RR, LR, RL)** maintain balance.

### **4️⃣ Red-Black Tree**
- A **self-balancing BST** where each node has a color (red or black).
- Guarantees **O(log n) operations**.
- Follows specific rules to maintain balance.

### **5️⃣ B-Trees**
- Used in databases and file systems.
- Generalization of a BST with **multiple children**.
- Balances itself after insertions and deletions.

### **6️⃣ Heap (Binary Heap)**
- A **complete binary tree** used for priority queues.
- **Min Heap**: Parent is smaller than children.
- **Max Heap**: Parent is larger than children.

### **7️⃣ Trie (Prefix Tree)**
- Used for **string searching**.
- Each edge represents a character.
- Efficient for autocomplete and dictionary applications.

### **8️⃣ Segment Tree**
- Used for **range queries** (sum, min, max) in logarithmic time.
- Built recursively.

### **9️⃣ N-ary Tree**
- Each node can have **more than two children**.
- Used in **XML parsing, file systems, and AI**.

---

## Tree Traversal Techniques
Traversal is the process of visiting nodes in a tree.

### **1️⃣ Depth-First Search (DFS)**
- **Inorder (Left, Root, Right)** – Used in BST for sorted order.
- **Preorder (Root, Left, Right)** – Used for copying a tree.
- **Postorder (Left, Right, Root)** – Used for deleting nodes.

### **2️⃣ Breadth-First Search (BFS)**
- Also called **Level Order Traversal**.
- Uses a **queue** to process nodes level by level.

---

## Operations on Trees

| Operation      | Time Complexity |
|---------------|----------------|
| Insertion     | O(log n) (BST) / O(1) (Trie) |
| Deletion      | O(log n) (BST) / O(1) (Trie) |
| Searching     | O(log n) (BST) / O(1) (Trie) |
| Traversal     | O(n) |

---

## Applications of Trees
- **Databases**: B-Trees and B+ Trees are used in indexing.
- **Compilers**: Abstract Syntax Trees (AST) represent expressions.
- **Networking**: Spanning trees are used in network routing.
- **Artificial Intelligence**: Decision Trees are used in ML models.
- **File Systems**: Hierarchical storage structures.
- **Compression**: Huffman Trees are used in data compression.

---

## Conclusion
Trees are a fundamental data structure used across various domains in computer science. Understanding different types and operations is crucial for efficient algorithm design and problem-solving.

