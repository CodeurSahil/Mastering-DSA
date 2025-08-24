## Hash Table: The Ultimate Key-Value Store 🔑

A **Hash Table**, also known as a **Hash Map**, is a data structure that stores **key-value pairs**. Its primary goal is to provide incredibly fast average-case performance for inserting, deleting, and looking up values.

It achieves this speed by using a special **hash function** to calculate an index in an array where a value should be stored. Think of it like a magical filing cabinet: you give it a key (like a person's name), and the hash function instantly tells you which drawer (the index) to open to find their file (the value), eliminating the need to search.

---

### Representation
![HT](/assets/hashTable.png)

## How It Works: The Core Components

A hash table is a combination of three essential parts that work together.

* **1. The Array (The "Table" or "Buckets")**
    * The underlying storage is a simple array. Each slot in this array is often called a **bucket**. The size of this array is crucial for the hash function's calculations.

* **2. The Hash Function**
    * This is a special function whose job is to take a key (which can be a string, number, or object) and convert it into an integer that corresponds to an index in the array.
    * **`index = hash_function(key) % array_size`**
    * A good hash function is critical and should be:
        * **Deterministic:** Always produces the same index for the same key.
        * **Uniform:** Distributes keys evenly across all buckets to avoid clustering.
        * **Fast:** Computes the index quickly.

* **3. The Collision Resolution Strategy**
    * **The Problem (Collisions):** It's possible for two different keys to produce the same hash index. For example, `hash("John Smith") = 2` and `hash("Sandra Dee") = 2`. This is called a **collision**.
    * **The Solution:** A strategy is needed to store both key-value pairs in the same bucket at index 2. This is handled by a collision resolution technique.

---

## Collision Resolution Techniques

How a hash table handles collisions is fundamental to its design and performance.

* **Method 1: [Separate Chaining (Most Common)](Using%20Linked%20List/readme.md)**
    * **Logic:** Instead of storing a single value, each bucket in the array holds a pointer to another data structure, usually a **linked list**.
    * **Process:** When a collision occurs, the new key-value pair is simply added as a new node to the linked list at that index. To find an element, you hash the key to find the correct bucket and then traverse the small linked list within it.
    * 

* **Method 2: [Open Addressing (Probing)](Using%20Open%20Addressing/readme.md)**
    * **Logic:** If a collision occurs at an index, the table "probes" or searches for the next available empty slot in the array itself to place the item.
    * **Types of Probing:**
        * **Linear Probing:** Checks the next slot (`index + 1`, `index + 2`, ...).
        * **Quadratic Probing:** Checks slots at increasing intervals (`index + 1²`, `index + 2²`, ...).
        * **Double Hashing:** Uses a second hash function to determine the step size for the next probe.

---

## Load Factor and Rehashing

* **Load Factor:** A measure of how full the hash table is.
    * **`Load Factor = (Number of Elements) / (Number of Buckets)`**
* **Rehashing:** If the load factor exceeds a certain threshold (typically around 0.75), performance starts to degrade because collisions become more frequent. To fix this, the table is **rehashed**:
    1.  A new, larger array is created (usually double the size).
    2.  The algorithm iterates through every key-value pair in the old table.
    3.  Each key is re-hashed for the new, larger array size, and the pair is inserted into the new table.
    4.  This is an expensive, one-time `$O(n)` operation that keeps future operations fast.

---

## Operations and Algorithms (Using Separate Chaining)

* **Insert(key, value)**
    * **Goal:** Add a new key-value pair or update an existing one.
    * **Algorithm:**
        1.  Calculate the index: `index = hash(key) % array_size`.
        2.  Go to the linked list at `array[index]`.
        3.  Traverse the list. If the key is found, update its value.
        4.  If the key is not found, add a new node with the key-value pair to the end of the list.

* **Search(key)**
    * **Goal:** Find the value associated with a given key.
    * **Algorithm:**
        1.  Calculate the index: `index = hash(key) % array_size`.
        2.  Go to the linked list at `array[index]`.
        3.  Traverse the list, comparing the key in each node. If a match is found, return its value.
        4.  If the end of the list is reached, the key does not exist.

* **Delete(key)**
    * **Goal:** Remove a key-value pair.
    * **Algorithm:**
        1.  Calculate the index: `index = hash(key) % array_size`.
        2.  Go to the linked list at `array[index]`.
        3.  Search for the node with the matching key and remove it from the linked list.

---

## Key Properties

* **Key-Value Association:** Stores data in pairs, mapping unique keys to values.
* **Unordered:** The elements are not stored in any predictable or sorted order.
* **Fast on Average:** Its defining property is its `$O(1)` average time complexity for core operations.
* **Collision-Dependent Performance:** Its real-world speed is heavily influenced by the quality of the hash function and the collision resolution strategy.

---

## Advantages 👍

* **Incredibly Fast:** The average-case `$O(1)` time for lookups, insertions, and deletions is faster than almost any other data structure.
* **Flexible Keys:** Can use a wide variety of data types as keys (strings, numbers, objects), as long as a consistent hash value can be generated for them.

---

## Disadvantages 👎

* **Worst-Case Performance:** In the rare case of extreme collisions (e.g., all keys hash to the same index), performance degrades to that of a linked list: `$O(n)`.
* **Unordered:** Not suitable for applications that require sorted data or finding the minimum/maximum key.
* **Memory Overhead:** Can use more memory than a simple array to store pointers for chaining or to keep the load factor low (i.e., having empty buckets).

---

## Applications

Hash tables are one of the most widely used data structures in computer science.

* **Associative Arrays:** They are the foundation of Python's `dict`, Java's `HashMap`, and JavaScript's `Objects`.
* **Database Indexing:** Used to quickly locate data records on disk without scanning the entire database.
* **Caching:** Used to provide extremely fast lookups for frequently accessed data, such as in web servers or CPUs.
* **Symbol Tables:** Used by compilers and interpreters to keep track of variables and functions in a program.

---

## Time Complexity Summary

| Operation | Average Case | Worst Case (Many Collisions) |
| :-------- | :----------: | :--------------------------: |
| **Insert** |    `$O(1)$`   |            `$O(n)`           |
| **Delete** |    `$O(1)`   |            `$O(n)`           |
| **Search** |    `$O(1)`   |            `$O(n)`           |