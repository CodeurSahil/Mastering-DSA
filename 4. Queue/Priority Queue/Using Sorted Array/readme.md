# Priority Queue Using a Sorted Array

A **Priority Queue** implemented using a **sorted array** ensures that elements are always stored in order based on their priority. While this approach requires additional effort during insertion, it allows efficient retrieval and deletion of the highest-priority element.

---

## Key Characteristics

1. **Storage**:
   - Elements are stored in a sorted array, where elements are ordered by their priority.
2. **Insertion**:
   - New elements are inserted into the array while maintaining the sorted order.
3. **Priority Determination**:
   - The highest-priority element is always at a fixed position (e.g., the start or end of the array).

---

## Key Operations

### **1. Insertion**

Adds an element to the priority queue while maintaining the sorted order.

#### Steps:
1. Locate the correct position for the new element based on its priority.
2. Shift all elements after this position to make space for the new element.
3. Insert the new element.

#### Time Complexity:
- **Insertion**: \( O(n) \), where \( n \) is the number of elements in the queue.

---

### **2. Deletion (Remove Highest Priority Element)**

Removes the element with the highest priority from the queue.

#### Steps:
1. The highest-priority element is directly available (e.g., at the start or end of the array).
2. Remove the element and shift the remaining elements to fill the gap.

#### Time Complexity:
- **Deletion**: \( O(1) \) for access, \( O(n) \) for shifting.

---

### **3. Peek (Retrieve Highest Priority Element)**

Retrieves the element with the highest priority without removing it.

#### Steps:
1. Directly access the element at the fixed position (e.g., the start or end of the array).

#### Time Complexity:
- **Peek**: \( O(1) \)

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

1. **Efficient Retrieval**:
   - The highest-priority element is always directly accessible.
2. **Simplified Deletion**:
   - Removing the highest-priority element is straightforward.

---

## Disadvantages

1. **Insertion Overhead**:
   - Inserting elements while maintaining sorted order requires shifting, which is \( O(n) \).
2. **Fixed Size**:
   - If implemented using a fixed-size array, it has limited capacity.

---

## Applications

1. **Task Scheduling**:
   - Suitable for scenarios where retrieving the highest-priority task is frequent.
2. **Simulation Systems**:
   - Useful in systems where priorities dynamically change but need to be processed in order.

---

## Summary

| Operation        | Time Complexity |
|------------------|-----------------|
| Insertion        | \( O(n) \)      |
| Deletion         | \( O(1) \) (access) / \( O(n) \) (shifting) |
| Peek             | \( O(1) \)      |
| IsEmpty          | \( O(1) \)      |

---