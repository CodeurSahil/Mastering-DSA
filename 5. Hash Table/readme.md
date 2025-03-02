# Hash Tables / Hash Maps

## Introduction
A **Hash Table (Hash Map)** is a data structure that stores key-value pairs and provides efficient insertion, deletion, and lookup operations. It utilizes a **hash function** to compute an index where the value is stored.

---

## Key Characteristics
- **Fast access time**: Average time complexity of O(1) for insert, delete, and lookup operations.
- **Collision Handling**: Uses techniques like chaining or open addressing.
- **Unordered Storage**: Does not maintain order like arrays or linked lists.
- **Dynamic Resizing**: Expands or contracts based on load factor.
- **Multiple Implementation Methods**: Different ways to implement based on collision handling and data structure.

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

## Collision Handling Techniques
Collisions occur when two different keys map to the same index. To resolve this, we use:

### **1. Chaining**
- Each index in the table stores a linked list of key-value pairs.
- If a collision occurs, the new key-value pair is appended to the linked list.
- **Pros**: Simple and efficient for handling multiple collisions.
- **Cons**: Performance degrades if chains become too long.

### **2. Open Addressing**
Instead of using linked lists, elements are stored in empty slots within the table.

#### Open Addressing Strategies:
- **Linear Probing**: If a collision occurs, look for the next available slot sequentially.
- **Quadratic Probing**: Checks slots at increasing intervals (e.g., 1², 2², 3²).
- **Double Hashing**: Uses a second hash function to determine the probe sequence.

---

## Ways to Implement Hash Tables

### **1. Using Arrays**
- Stores key-value pairs in an array.
- The index is determined using a **hash function**.
- Handles **collisions** using **chaining** or **open addressing**.

### **2. Using Linked Lists (Chaining)**
- Each array index stores a linked list of key-value pairs.
- If a collision occurs, elements are appended to the linked list.

### **3. Using Open Addressing**
- **Linear Probing**: If a collision occurs, check the next available slot sequentially.
- **Quadratic Probing**: Checks slots at increasing intervals (e.g., `1², 2², 3²`).
- **Double Hashing**: Uses a **second hash function** to determine the probe sequence.

### **4. Using Balanced Trees (e.g., Red-Black Tree)**
- Instead of a linked list for chaining, we store **colliding elements in a balanced binary search tree**.

### **5. Using Dynamic Resizing (Rehashing)**
- When the **load factor** exceeds a threshold (e.g., 0.7), the table is resized (usually doubled).

### **6. Using Cuckoo Hashing**
- Uses **two hash functions** and stores an element in one of two possible positions.
- If a collision occurs, the existing element is **relocated** to its alternate position.

### **7. Using Perfect Hashing**
- Uses a **two-level hashing scheme** to ensure **zero collisions**.

---

## Operations in a Hash Table

### **Insertion**
1. Compute the index using the hash function.
2. If the slot is empty, store the key-value pair.
3. If occupied, handle collision using chaining or open addressing.

### **Search (Lookup)**
1. Compute the index using the hash function.
2. If the slot contains the key, return the value.
3. If not, follow the collision resolution strategy to find the key.

### **Deletion**
1. Compute the index using the hash function.
2. If found, remove the key-value pair.
3. If chaining is used, remove it from the linked list.
4. If open addressing is used, mark the slot as deleted (lazy deletion).

---

## Load Factor & Resizing
The **Load Factor (LF)** determines when to resize the hash table.

\[ LF = \frac{Number\ of\ elements}{Table\ size} \]

- If LF exceeds a threshold (e.g., 0.7), the table is resized (usually doubled).
- A new hash function is applied to redistribute elements.

---

## Advantages of Hash Tables
- **Fast Lookups**: O(1) average time complexity.
- **Efficient Inserts & Deletes**: O(1) on average.
- **Flexible Key Types**: Can store various data types as keys.

## Disadvantages of Hash Tables
- **Collisions**: Can degrade performance.
- **Memory Overhead**: Uses extra space for collision handling.
- **Unordered Data**: Cannot maintain the order of insertion.

---

## Applications of Hash Tables
- **Database Indexing**: Efficiently retrieves records.
- **Caching**: Stores frequently accessed data.
- **Symbol Tables**: Used in compilers for variable storage.
- **Password Storage**: Hash functions are used to store passwords securely.
- **Routing Tables**: Stores network routes efficiently.

---

## Summary Table

| Implementation Method | Collision Handling | Time Complexity (Avg) | Space Efficiency | Use Case |
|------------------|----------------------|-----------------|-----------------|------------|
| **Array**         | None                 | O(1)            | High            | Basic Hashing |
| **Chaining**      | Linked List          | O(1) (avg) / O(n) (worst) | Moderate | General Purpose |
| **Linear Probing**| Open Addressing      | O(1) (avg) / O(n) (worst) | High | Small datasets |
| **Quadratic Probing** | Open Addressing  | O(1) (avg) / O(n) (worst) | High | Avoids clustering |
| **Double Hashing**| Open Addressing      | O(1) (avg) / O(n) (worst) | High | Reduces clustering |
| **Balanced Tree** | Chaining with Trees  | O(log n)        | Moderate        | Large datasets |
| **Rehashing**     | Resizing             | O(n) (rehash) / O(1) (lookup) | High | Dynamic Load |
| **Cuckoo Hashing**| Multiple Hashing     | O(1) (avg) / O(n) (worst) | Moderate | High Performance |
| **Perfect Hashing** | Precomputed Hash   | O(1)            | Moderate | Static Datasets |

---

## Conclusion
Hash tables are one of the most powerful and efficient data structures for key-value storage. Choosing an appropriate hash function and collision resolution method is essential for optimal performance.

