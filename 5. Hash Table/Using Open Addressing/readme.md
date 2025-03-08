# Hash Tables Using Open Addressing

## Introduction
A **Hash Table using Open Addressing** is an implementation of a hash table where all elements are stored directly in the array itself, without using linked lists. When a collision occurs, the algorithm searches for an alternative location within the table using a probing method.

---

## Key Characteristics
- **No External Data Structures**: Unlike separate chaining, all elements are stored in the table.
- **Handles Collisions with Probing**: Uses various probing techniques to resolve collisions.
- **Better Cache Performance**: Since data is stored in a contiguous array, lookups are faster.
- **Cannot Grow Beyond Table Size**: Since elements must be stored within the table, resizing is necessary when the table is nearly full.

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

## Collision Handling Techniques in Open Addressing
Since elements are stored directly in the array, Open Addressing uses **probing** to find alternative locations when a collision occurs.

### **1️⃣ Linear Probing**
- If a collision occurs, check the next available slot sequentially.
- **Index Calculation:**  
  \[ index = (hash(key) + i) \mod table\_size \]
  (where `i` is the number of probes)
- ✅ **Pros**: Simple and efficient for small tables.
- ❌ **Cons**: Causes **primary clustering**, where consecutive slots fill up.

### **2️⃣ Quadratic Probing**
- Instead of checking the next slot, check slots at increasing intervals (e.g., `1², 2², 3²`).
- **Index Calculation:**  
  \[ index = (hash(key) + i²) \mod table\_size \]
- ✅ **Pros**: Reduces clustering compared to linear probing.
- ❌ **Cons**: Still susceptible to **secondary clustering**.

### **3️⃣ Double Hashing**
- Uses a **second hash function** to determine the probe sequence.
- **Index Calculation:**  
  \[ index = (hash1(key) + i \times hash2(key)) \mod table\_size \]
- ✅ **Pros**: Reduces clustering significantly.
- ❌ **Cons**: More computationally expensive.

---

## Operations in Hash Table Using Open Addressing

### **Insertion**
1. Compute the index using the primary hash function.
2. If the slot is empty, store the key-value pair.
3. If occupied, use the probing technique to find the next available slot.

**Time Complexity:**
- **Best Case**: O(1) (no collisions)
- **Worst Case**: O(n) (when table is nearly full)

---

### **Search (Lookup)**
1. Compute the index using the hash function.
2. If the key matches, return the value.
3. If not, use probing to check alternative locations.

**Time Complexity:**
- **Best Case**: O(1)
- **Worst Case**: O(n)

---

### **Deletion**
1. Compute the index using the hash function.
2. If the key is found, mark it as **deleted** using a special flag (lazy deletion).
3. If not, continue probing to find the key.

**Time Complexity:**
- **Best Case**: O(1)
- **Worst Case**: O(n)

**Why Use Lazy Deletion?**
- Removing an element by simply setting it to `null` can **break search operations**.
- Instead, use a **special marker** (e.g., `-1`) to indicate a deleted entry.

---

## Load Factor & Resizing
The **Load Factor (LF)** determines when to resize the hash table.

\[ LF = \frac{Number\ of\ elements}{Table\ size} \]

- If LF exceeds a threshold (e.g., 0.7), the table is resized (usually doubled).
- A new hash function is applied to redistribute elements.

---

## Advantages of Open Addressing
- **Better Cache Performance**: Data is stored in a contiguous array.
- **No Extra Memory for Pointers**: Unlike separate chaining, no linked lists are used.
- **Simpler Implementation**: Only requires an array and a probing mechanism.

## Disadvantages of Open Addressing
- **Performance Degrades When Full**: As the table fills up, insertion and lookup slow down.
- **Resizing Overhead**: Requires rehashing all elements when the table grows.
- **Deletion Issues**: Requires special handling (lazy deletion).

---

## Applications of Hash Table Using Open Addressing
- **Memory-Constrained Environments**: Since no extra memory is needed for pointers.
- **Database Indexing**: Fast lookups and efficient space usage.
- **Caching Mechanisms**: Used in CPU caches and associative memory.
- **Routing Tables**: Stores network routes efficiently.

---

## Summary Table

| Probing Method       | Collision Handling | Clustering Issue | Best Use Case |
|----------------------|-------------------|----------------|--------------|
| **Linear Probing**   | Next available slot | High (Primary) | Small Tables |
| **Quadratic Probing**| Gaps between probes | Medium (Secondary) | Moderate Load |
| **Double Hashing**   | Second hash function | Low | Large Datasets |

---

## Conclusion
A Hash Table using Open Addressing is an efficient way to manage key-value pairs **without external structures**. The choice of probing method significantly impacts performance. To maintain efficiency, **proper resizing and a good hash function** are essential.

