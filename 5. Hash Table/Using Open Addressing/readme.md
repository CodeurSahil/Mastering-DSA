## Hash Table with Open Addressing: Probing for Empty Slots

A **Hash Table with Open Addressing** is a collision resolution strategy where all key-value pairs are stored directly inside the main array. When a **collision** occurs (i.e., the target slot calculated by the hash function is already occupied), the algorithm "probes" or searches for the next available empty slot within the array to place the new element.

Think of it like finding a parking spot in a single-row lot. If your assigned spot (the hash index) is taken, you have to drive down the row (probe) to find the next empty one.

***Note: Understand Flow via Code in `hashTable.c`***

---

## Probing Strategies: How to Find the Next Slot

The method used to find the next empty slot is called a probing strategy. The choice of strategy is critical to the hash table's performance.

* **1. Linear Probing**
    * **Logic:** If `index` is occupied, try `index + 1`, then `index + 2`, and so on, wrapping around the array if necessary.
    * **Problem:** This is the simplest method but suffers from **primary clustering**, where long runs of occupied slots build up, slowing down future insertions and searches in that area.

* **2. Quadratic Probing**
    * **Logic:** If `index` is occupied, it checks slots at increasing quadratic intervals: `index + 1²`, then `index + 2²`, `index + 3²`, etc.
    * **Benefit:** By "jumping" over adjacent slots, it helps break up the long clusters formed by linear probing.
    * **Problem:** It can lead to **secondary clustering**, where keys that hash to the same initial index will follow the exact same probe sequence.

* **3. Double Hashing**
    * **Logic:** This is the most effective method. It uses a **second, independent hash function** to determine the fixed "step size" for the probe. If `index` is occupied, it tries `index + step_size`, then `index + 2 * step_size`, etc.
    * **Benefit:** Keys that hash to the same initial index will likely have a different step size, causing them to follow different probe paths and effectively eliminating clustering.

---

## The Deletion Problem: "Lazy Deletion"

Deletion is tricky in open addressing. You cannot simply find an element and set its slot to `NULL`.

* **The Problem:** Doing so would break the "probe chain." A later search for an element that was inserted *after* the deleted item might hit the new `NULL` spot and incorrectly conclude the element isn't in the table.
* **The Solution (Lazy Deletion):** Instead of truly deleting the element, the slot is marked with a special **"deleted"** or **"tombstone"** marker.
    * During a **search**, the algorithm treats this slot as occupied and continues probing.
    * During an **insertion**, it treats this slot as empty and can place a new element there.

---

## Operations and Algorithms

* **Insert(key, value)**
    * **Goal:** Add a new key-value pair.
    * **Algorithm:**
        1.  Calculate the initial `index` using the hash function.
        2.  Begin probing from that `index` using the chosen strategy (linear, quadratic, etc.).
        3.  Continue probing until an empty (`NULL`) or "deleted" slot is found.
        4.  Insert the `(key, value)` pair into that slot.

* **Search(key)**
    * **Goal:** Find the value for a given key.
    * **Algorithm:**
        1.  Calculate the initial `index` using the hash function.
        2.  Begin probing from that `index`.
        3.  If a slot with the matching `key` is found, return its `value`.
        4.  If an **empty (`NULL`) slot** is found, the key does not exist. Stop the search.
        5.  If a "deleted" slot or a non-matching key is found, **continue probing**.

* **Delete(key)**
    * **Goal:** Remove a key-value pair.
    * **Algorithm:**
        1.  Use the `Search` logic to find the slot containing the key.
        2.  If the key is found, replace the entry with the special **"deleted"** marker. Do not set it to `NULL`.

---

## Key Properties

* **In-Table Collision Resolution:** All elements reside within the main array itself.
* **Probe-Based Search:** Finding an element may require checking multiple array slots.
* **Clustering Tendency:** Performance is sensitive to clustering, which varies by probing strategy.
* **Load Factor Limit:** Performance degrades sharply as the table fills up. The load factor **must** be kept below 1.0.

---

## Advantages 👍

* **Excellent Cache Performance:** Storing all data contiguously in an array is very CPU-cache-friendly. This can make open addressing faster in practice than chaining when the load factor is low.
* **No Pointer Overhead:** It saves the memory that would have been used for `next` pointers in a separate chaining implementation.

---

## Disadvantages 👎

* **Clustering:** Performance can degrade significantly if clustering occurs, turning `$O(1)` operations into `$O(n)`.
* **Complex Deletion:** Requires a special "lazy deletion" mechanism, which adds complexity and means the table can fill up with "deleted" markers.
* **Sensitive to High Load Factors:** Performance drops off dramatically as the table gets close to being full.

---

## Applications

Open addressing is best suited for scenarios where memory is tight, and deletions are infrequent.

* **Performance-Critical Systems:** When cache performance is paramount and the load factor can be kept low (e.g., in the implementation of CPU caches).
* **Memory-Constrained Environments:** The lack of pointer overhead makes it more space-efficient.
* **Hardware Implementations:** Often used in hardware-based hash tables.

---

## Time Complexity Summary

The average case is highly dependent on the load factor—as the table fills, performance approaches the worst case.

| Operation | Average Case (Low Load Factor) | Worst Case (Clustering / Full Table) |
| :-------- | :----------------------------: | :----------------------------------: |
| **Insert** |             `$O(1)`              |                `$O(n)`                 |
| **Delete** |             `$O(1)`              |                `$O(n)`                 |
| **Search** |             `$O(1)`              |                `$O(n)`                 |