# Hash Tables Using Linked List

## Introduction
A **Hash Table using a Linked List** is an implementation of a hash table where each bucket (index in the array) contains a **linked list** to handle collisions. This method is known as **separate chaining**.

---

## Key Characteristics
- **Uses Linked Lists**: Each bucket contains a linked list of key-value pairs.
- **Efficient Collision Handling**: Multiple keys mapping to the same index are stored in a list.
- **Dynamic Storage**: Can handle an arbitrary number of elements per bucket.
- **Slower than Open Addressing for Lookups**: If chains grow long, lookup time increases.

---

## Hash Function
A **hash function** converts a key into an index within the array.

### Properties of a Good Hash Function:
- **Deterministic**: Produces the same output for the same input.
- **Uniform Distribution**: Spreads keys evenly across the table.
- **Minimal Collisions**: Reduces the chance of two keys mapping to the same index.
- **Fast Computation**: Should be efficient for large inputs.

Common hash functions include:
- **Modulo Method**: `hash(key) = key % table_size`
- **Multiplication Method**: Uses a fractional constant to ensure even distribution.
- **Universal Hashing**: Uses randomization for security and uniformity.

---

## Structure of Hash Table Using Linked List
A hash table with separate chaining consists of:
1. **An array of linked lists**: Each index in the array stores a pointer to a linked list.
2. **Nodes containing key-value pairs**: Each node in the linked list holds a key, value, and a pointer to the next node.
3. **A hash function**: Determines which linked list a key belongs to.

### Example Structure:
```plaintext
Index | Linked List (Chained Elements)
-------------------------------------
  0   | (key1, value1) -> (key2, value2) -> NULL
  1   | (key3, value3) -> NULL
  2   | (key4, value4) -> (key5, value5) -> NULL
```

---

## Operations in Hash Table Using Linked List

### **Insertion**
1. Compute the index using the hash function.
2. Traverse the linked list at that index to check if the key already exists.
3. If the key exists, update the value.
4. If the key does not exist, create a new node and insert it at the head or tail of the linked list.

**Time Complexity:**
- **Best Case**: O(1) (empty bucket or minimal collisions)
- **Worst Case**: O(n) (all elements hashed to the same bucket)

---

### **Search (Lookup)**
1. Compute the index using the hash function.
2. Traverse the linked list at that index to find the key.
3. If found, return the value; otherwise, return `null`.

**Time Complexity:**
- **Best Case**: O(1)
- **Worst Case**: O(n)

---

### **Deletion**
1. Compute the index using the hash function.
2. Traverse the linked list at that index to find the key.
3. If found, remove the node from the list.

**Time Complexity:**
- **Best Case**: O(1)
- **Worst Case**: O(n)

---

## Load Factor & Resizing
The **Load Factor (LF)** determines when to resize the hash table.

\[ LF = \frac{Number\ of\ elements}{Table\ size} \]

- If LF exceeds a threshold (e.g., 0.7), the table is resized (usually doubled).
- A new hash function is applied to redistribute elements.

---

## Advantages of Hash Table Using Linked List
- **Handles High Collision Cases**: Suitable when many elements map to the same index.
- **Dynamic Bucket Growth**: No wasted space as buckets grow dynamically.
- **Simple Implementation**: Easier to implement than open addressing.

## Disadvantages of Hash Table Using Linked List
- **Increased Memory Usage**: Each element stores a pointer, adding overhead.
- **Slower Lookups in Worst Case**: If many keys hash to the same bucket, performance degrades.
- **Cache Inefficiency**: Linked lists are not contiguous in memory, leading to slower access.

---

## Applications of Hash Table Using Linked List
- **Symbol Tables**: Used in compilers for storing variables and function names.
- **Database Indexing**: Efficiently stores and retrieves records.
- **Caching Mechanisms**: Stores frequently accessed data for quick retrieval.
- **Counting Frequencies**: Useful in applications like word count in documents.

---

## Summary Table

| Operation  | Average Case | Worst Case (with poor hash function) |
|------------|--------------|------------------------------------|
| Insertion  | O(1)         | O(n)                               |
| Deletion   | O(1)         | O(n)                               |
| Search     | O(1)         | O(n)                               |

---

## Conclusion
A Hash Table using a Linked List is an effective method to handle collisions while maintaining dynamic bucket storage. However, it can suffer from slower lookups if chains grow too long. Choosing an optimal hash function and maintaining a balanced load factor is key to efficient performance.

