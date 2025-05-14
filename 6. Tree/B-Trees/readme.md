# 🌳 B-Tree

## 🔹 Introduction

A **B-Tree** is a self-balancing search tree in which nodes can have more than two children. It is widely used in databases and file systems due to its efficient handling of large blocks of data.

---

## 🔹 Key Properties

- Each node can contain **multiple keys**.
- A node with `n` keys has `n+1` children.
- All **leaves appear on the same level**.
- B-Trees are generalized binary search trees where each node can have up to `m` children (order `m`).

---

## 🔹 Structure

For a B-Tree of order `m`:

- Each internal node can have at most `m` children.
- Each internal node (except root) has at least `⌈m/2⌉` children.
- The root has at least two children if it is not a leaf.
- A non-leaf node with `k` children contains `k−1` keys.

---

## 🔹 Operations

### 1. **Search**
- Similar to binary search within a node.
- Traverse child pointers based on key comparison.

### 2. **Insertion**
- Insert into the correct position in a leaf.
- If the node is full, split it and push the middle key up.

### 3. **Deletion**
- Remove key from leaf or internal node.
- If underflow occurs, borrow from siblings or merge nodes.

### 4. **Traversal**
- In-order traversal yields sorted keys.
- Traverse each subtree between the keys.

---

## 🔹 Time Complexity

| Operation | Time Complexity |
|-----------|------------------|
| Search    | O(log n)         |
| Insert    | O(log n)         |
| Delete    | O(log n)         |

---

## 🔹 Advantages

- Efficient disk read/writes.
- Balanced structure ensures optimal performance.
- Better suited for systems that read/write large blocks.

## 🔹 Disadvantages

- More complex implementation than binary trees.
- More memory usage due to multiple keys per node.

---

## 🔹 Applications

- Databases (e.g., MySQL, PostgreSQL)
- File systems (e.g., NTFS, HFS+)
- Indexing in large datasets
- Storage systems requiring balanced search trees

---

## 🔹 Summary

B-Trees are ideal for applications requiring frequent read/write operations on large datasets, especially from disk. Their balanced, multi-key node structure ensures consistent and efficient performance across various operations.
