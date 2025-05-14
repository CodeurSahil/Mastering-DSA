
# N-ary Tree

## 🔹 Introduction

An **N-ary Tree** is a tree data structure in which each node can have **at most N children**. It generalizes the concept of binary trees by allowing more than two children per node.

---

## 🔹 Key Characteristics

- **Flexible Number of Children**: Each node can have up to N children.
- **Hierarchical Structure**: Similar to other trees, it represents a hierarchy.
- **Root Node**: The topmost node.
- **Leaf Nodes**: Nodes without children.

---

## 🔹 Types of N-ary Trees

1. **Ternary Tree** – Each node can have up to 3 children.
2. **Quaternary Tree** – Each node can have up to 4 children.
3. **M-ary Tree** – General form where each node has up to M children.

---

## 🔹 Traversals

### 1. **Preorder Traversal** (Node → Children)
- Visit the node.
- Recursively traverse each child from left to right.

### 2. **Postorder Traversal** (Children → Node)
- Recursively traverse each child.
- Visit the node after all children are visited.

### 3. **Level Order Traversal**
- Traverse nodes level by level using a queue (BFS).

---

## 🔹 Basic Operations

- **Insert**: Add a new node as a child of a given node.
- **Delete**: Remove a node and restructure the children appropriately.
- **Search**: Traverse the tree to find a specific value.
- **Traversal**: Access all nodes in a defined order (preorder, postorder, level-order).

---

## 🔹 Advantages

- Useful for representing hierarchical data where nodes may have many children.
- More natural modeling of many real-world hierarchies (like file systems, organization charts).

---

## 🔹 Disadvantages

- More complex to manage and traverse compared to binary trees.
- Operations like insertion, deletion, and search may take more time than binary trees.

---

## 🔹 Applications

- File systems
- Organizational hierarchies
- Game trees (e.g., for chess or tic-tac-toe)
- Compilers (syntax trees)
- Trie-based data structures

---

## 🔹 Conclusion

N-ary Trees are powerful for representing hierarchical relationships where nodes can have multiple children. Their flexibility makes them ideal for modeling complex data structures in both theoretical and practical applications.
