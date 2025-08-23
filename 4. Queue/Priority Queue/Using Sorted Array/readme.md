## Priority Queue with a Sorted Array: Slow Insert, Fast Retrieve

Implementing a **Priority Queue** using a **sorted array** is an approach that prioritizes fast retrieval. The core idea is to do the hard work during insertion, ensuring the array is **always kept in sorted order** based on priority. This makes finding the highest-priority element trivial, as it will always be in a predictable location.

Think of it like a meticulously organized file cabinet, sorted by importance. Filing a new document is slow because you have to find the exact right spot and shift other files around. However, retrieving the most important document is instant—it's always right at the front.

***Note: Understand Flow via Code in `priorityQueue.c`***

---

## How It Works: The Logic

This implementation's performance is a direct result of its commitment to maintaining order at all times.

* **The Array:** A standard array (fixed-size or dynamic) stores the elements. The key is that this array is always kept sorted by priority (e.g., from lowest to highest).
* **Insertion Logic:** To add a new element, the algorithm must first find the correct position in the array to maintain the sorted order. After finding the spot, it must shift all subsequent elements one position to the right to make space, and then insert the new element.
* **Retrieval Logic:** Because the array is always sorted, the highest-priority element is always at a known location. For example, in an array sorted in ascending order of priority, the highest-priority element (the minimum value) is always at index 0.

---

## Operations and Algorithms

The performance trade-off is clear: `insert` is slow, while `peek` and `delete` are fast.

* **Insert(element, priority)**
    * **Goal:** Add a new element while keeping the array sorted.
    * **Algorithm:**
        1.  Search for the correct insertion point to maintain the sorted order. This can take up to `$O(n)` time with a linear scan.
        2.  Shift all elements from that point to the end one position to the right to create a gap. This is an `$O(n)` operation.
        3.  Insert the new element into the created space.
    * **Complexity:** `$O(n)`.

* **Delete-Highest-Priority()**
    * **Goal:** Remove the element with the highest priority.
    * **Algorithm:**
        1.  Access the highest-priority element, which is at a known end of the array (e.g., the last element if sorted descendingly). This is an `$O(1)` access.
        2.  Remove it by simply decrementing the array's effective size.
        3.  *Note: If the element is removed from the beginning, it would require shifting all other elements, making it an `$O(n)` operation.*
    * **Complexity:** `$O(1)` (if removing from the end).

* **Peek()**
    * **Goal:** Find and return the highest-priority element without removing it.
    * **Algorithm:** Simply access and return the element at the known highest-priority position (e.g., `array[0]` or `array[size-1]`).
    * **Complexity:** `$O(1)`.

* **IsEmpty()**
    * **Goal:** Check if the queue is empty.
    * **Algorithm:** Check if the array's size is zero.
    * **Complexity:** `$O(1)`.

---

## Key Properties

* **Sorted Storage:** The defining characteristic. The array is always maintained in priority order.
* **Direct Access to Best Element:** The highest-priority item is always at a fixed, known index, enabling `$O(1)` peeks.
* **Expensive Insertion:** Maintaining the sorted order makes insertion the primary performance bottleneck.

---

## Advantages 👍

* **Extremely Fast Retrieval (`Peek`):** The `$O(1)` time to access the highest-priority item is the main advantage.
* **Fast Deletion (from one end):** If the implementation is designed to remove from the end of the array, the `delete` operation is also `$O(1)`.

---

## Disadvantages 👎

* **Very Slow Insertions:** The `$O(n)` complexity for insertion, caused by searching and shifting, is the primary drawback. This makes the implementation impractical for any use case with frequent insertions.
* **Fixed Size:** If implemented with a static array, it is subject to the usual limitations of overflow or wasted memory.

---

## Applications

This implementation is rarely used in production environments due to its poor insertion performance.

* **Educational Tool:** It serves as a clear contrast to the unsorted array implementation and helps motivate the need for a more balanced solution like a heap.
* **Niche Scenarios:** It is only viable in situations where retrievals (`peek`/`delete`) are extremely frequent, and insertions are very rare.

---

## Time Complexity Summary

| Operation        | Complexity                 | Explanation                                                        |
| :--------------- | :------------------------- | :----------------------------------------------------------------- |
| **Insert** | `$O(n)`                    | Dominated by searching for position and shifting elements.         |
| **Delete-Highest** | `$O(1)`* or `$O(n)`        | *`$O(1)` if removing from the end, `$O(n)` if removing from the front (due to shifting). |
| **Peek** | `$O(1)`                    | The best element is at a known index.                              |
| **IsEmpty** | `$O(1)`                    | A simple size check.                                               |