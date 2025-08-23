## Hash Table with Chaining: Using Linked Lists for Collisions

A **Hash Table with Chaining** is a specific and very common implementation of a hash table that resolves collisions by storing all key-value pairs that hash to the same index in a **linked list**. This popular technique is formally known as **Separate Chaining**.

Think of it like a building with numbered mailboxes (the array). If multiple people live in the same apartment (have the same hash index), their mail isn't crammed into one slot. Instead, all their letters are chained together in a list inside that single mailbox, making it easy to find the right one.

***Note: Understand Flow via Code in `hashTable.c`***

---

## How It Works: The Structure

The implementation combines the fast lookup of an array with the flexibility of a linked list.

* **The Array of "Buckets":** The primary structure is an array. Each element of this array is not a value, but a **pointer to the head of a linked list**. Initially, all these pointers are `NULL`.
* **The Linked Lists:** When a key-value pair needs to be inserted, it is added as a **node** to the linked list corresponding to its hash index. Each node in the list contains the key, the value, and a `next` pointer to the next node in the chain.

---

## Operations and Algorithms

Every operation is a two-step process: first, find the correct bucket (the linked list), and second, perform the operation on that list.

* **Insert(key, value)**
    * **Goal:** Add a new key-value pair or update the value if the key already exists.
    * **Algorithm:**
        1.  Calculate the bucket index using the hash function: `index = hash(key) % array_size`.
        2.  Go to the linked list at `array[index]`.
        3.  Traverse this list. If a node with the same `key` is found, update its `value` and stop.
        4.  If the key is not found after checking the whole list, create a new node containing the `(key, value)` pair and add it to the beginning of the linked list.

* **Search(key)**
    * **Goal:** Find the value associated with a given key.
    * **Algorithm:**
        1.  Calculate the bucket index: `index = hash(key) % array_size`.
        2.  Go to the linked list at that index.
        3.  Traverse the list, comparing the `key` of each node with the target key.
        4.  If a match is found, return the corresponding `value`.
        5.  If the end of the list is reached without a match, the key is not in the table.

* **Delete(key)**
    * **Goal:** Remove a key-value pair from the table.
    * **Algorithm:**
        1.  Calculate the bucket index: `index = hash(key) % array_size`.
        2.  Go to the linked list at that index.
        3.  Traverse the list to find the node with the matching `key`.
        4.  Once found, remove the node using standard linked list deletion logic (by updating the `next` pointer of the previous node).

---

## Key Properties

* **Collision Resolution via Chaining:** The defining characteristic. Collisions are handled "outside" the main array in separate linked lists.
* **Variable Bucket Size:** Each bucket can theoretically store an unlimited number of elements.
* **Performance Depends on Chain Length:** The real-world speed of all operations is directly tied to the length of the linked lists. A good hash function and a proper load factor keep these chains short.

---

## Advantages 👍

* **Simple to Implement:** The logic for handling collisions is very straightforward compared to other methods like open addressing.
* **Handles High Load Factors Gracefully:** The hash table continues to function correctly even when it's very full (`load factor > 1`). Performance degrades smoothly as chains get longer, rather than failing abruptly.
* **Easy Deletion:** Removing an element is a simple and efficient linked list node removal operation.

---

## Disadvantages 👎

* **Memory Overhead:** Every stored element requires extra memory for the `next` pointer in its linked list node.
* **Poor Cache Performance:** Linked list nodes can be scattered across memory. Traversing a long chain can lead to multiple CPU cache misses, which can be slower in practice than a cache-friendly array-based technique like open addressing.
* **Worst-Case Degeneration:** If a poor hash function is used, all keys could map to the same bucket. In this case, the hash table effectively becomes a single, slow linked list, and all operations become `$O(n)`.

---

## Applications

Separate chaining is a robust, all-purpose strategy, making it the **default implementation** for hash maps in many standard libraries.

* **General-Purpose Key-Value Stores:** Its reliability and simplicity make it an excellent choice for general use, such as in Python's `dict` or Java's `HashMap`.
* **Symbol Tables:** Used by compilers and interpreters to manage variables and function names.
* **Database Indexes:** A core component for building efficient database lookup systems.

---

## Time Complexity Summary

The average case assumes a good hash function that distributes keys evenly, keeping the length of the linked lists small and constant on average.

| Operation | Average Case | Worst Case (All Keys in One Bucket) |
| :-------- | :----------: | :---------------------------------: |
| **Insert** |    `$O(1)`   |                `$O(n)`                |
| **Delete** |    `$O(1)`   |                `$O(n)`                |
| **Search** |    `$O(1)`   |                `$O(n)`                |