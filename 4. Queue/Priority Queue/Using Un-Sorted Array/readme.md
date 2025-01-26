# Priority Queue Using an Unsorted Array

A **Priority Queue** implemented using an **unsorted array** is a straightforward approach where elements are stored in no particular order. Despite its simplicity, it has specific performance characteristics that make it suitable for certain applications.

---

## Key Characteristics

1. **Storage**:
   - Elements are stored in an array without any specific order.
2. **Insertion**:
   - New elements are appended to the array.
3. **Priority Determination**:
   - The highest-priority element is identified by scanning the entire array during deletion or retrieval operations.
4. **Flexibility**:
   - Can handle both min-priority and max-priority queues based on the priority selection criteria.

---

## Key Operations

### **1. Insertion**

Adds an element to the priority queue with a specific priority.

#### Steps:
1. Append the element to the end of the array.
2. No rearrangement is required as the array remains unsorted.

#### Time Complexity:
- **Insertion**: \( O(1) \)

---

### **2. Deletion (Remove Highest Priority Element)**

Removes the element with the highest priority from the queue.

#### Steps:
1. Traverse the array to find the element with the highest priority.
2. Remove the identified element by shifting the remaining elements to fill the gap.

#### Time Complexity:
- **Deletion**: \( O(n) \)

---

### **3. Peek (Retrieve Highest Priority Element)**

Retrieves the element with the highest priority without removing it.

#### Steps:
1. Traverse the array to find the element with the highest priority.
2. Return the identified element.

#### Time Complexity:
- **Peek**: \( O(n) \)

---

### **4. IsEmpty**

Checks whether the priority queue is empty.

#### Steps:
1. If the array has no elements, return `true`.
2. Otherwise, return `false`.

#### Time Complexity:
- **IsEmpty**: \( O(1) \)

---

## Advantages

1. **Simple Implementation**:
   - Easy to implement as no sorting or rearranging is needed during insertion.
2. **Efficient Insertion**:
   - Insertion is performed in constant time \( O(1) \).

---

## Disadvantages

1. **Slow Deletion and Peek**:
   - Finding the highest-priority element requires scanning the entire array, making these operations \( O(n) \).
2. **Inefficient for Large Data**:
   - Performance degrades as the size of the queue increases.

---

## Applications

1. **Simple Systems**:
   - Suitable for applications where insertion is frequent, and retrieval or deletion is rare.
2. **Learning Purposes**:
   - Provides an easy-to-understand example for teaching priority queues.

---

## Summary

| Operation        | Time Complexity |
|------------------|-----------------|
| Insertion        | \( O(1) \)      |
| Deletion         | \( O(n) \)      |
| Peek             | \( O(n) \)      |
| IsEmpty          | \( O(1) \)      |

---
