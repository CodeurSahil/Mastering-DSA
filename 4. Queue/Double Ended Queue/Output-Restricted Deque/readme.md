# Output-Restricted Deque (Deque)

An **Output-Restricted Deque** is a type of double-ended queue where insertion is allowed at both ends, but deletion is restricted to only one end.

---

## Key Characteristics

1. **Insertion at Both Ends**:
   - New elements can be added at both the front and rear of the deque.
2. **Deletion at One End**:
   - Elements can only be removed from a single fixed end, typically the front.
3. **Flexible Storage**:
   - Can be implemented using arrays or linked lists.

---

## Key Operations

### **1. Insert at Front**

Adds an element to the front of the deque.

#### Algorithm:
1. Check if the deque is full.
2. If the deque is empty, initialize `front` and `rear` to 0.
3. If `front` is at the first position, move it to the last position (circular behavior).
4. Otherwise, decrement `front`.
5. Insert the element at the `front` position.

#### Time Complexity:
- **Array Implementation**: \( O(1) \)
- **Linked List Implementation**: \( O(1) \)

---

### **2. Insert at Rear**

Adds an element to the rear of the deque.

#### Algorithm:
1. Check if the deque is full.
2. If the deque is empty, initialize `front` and `rear` to 0.
3. If `rear` is at the last position, move it to the first position (circular behavior).
4. Otherwise, increment `rear`.
5. Insert the element at the `rear` position.

#### Time Complexity:
- **Array Implementation**: \( O(1) \)
- **Linked List Implementation**: \( O(1) \)

---

### **3. Delete from Front**

Removes an element from the front of the deque (only allowed deletion operation).

#### Algorithm:
1. Check if the deque is empty.
2. Retrieve the element at the `front` position.
3. If `front` equals `rear`, reset both to -1 (deque becomes empty).
4. If `front` is at the last position, move it to the first position (circular behavior).
5. Otherwise, increment `front`.

#### Time Complexity:
- **Array Implementation**: \( O(1) \)
- **Linked List Implementation**: \( O(1) \)

---

### **4. Peek at Front**

Retrieves the element at the front without removing it.

#### Algorithm:
1. Check if the deque is empty.
2. Return the element at the `front` position.

#### Time Complexity:
- **Array/Linked List Implementation**: \( O(1) \)

---

### **5. IsEmpty**

Checks whether the deque is empty.

#### Algorithm:
1. If `front == -1`, return `true`.
2. Otherwise, return `false`.

#### Time Complexity:
- **Array/Linked List Implementation**: \( O(1) \)

---

### **6. IsFull**

Checks whether the deque is full (for a fixed-size implementation).

#### Algorithm:
1. If `(front == 0 && rear == size-1)` or `(front == rear + 1)`, return `true`.
2. Otherwise, return `false`.

#### Time Complexity:
- **Array Implementation**: \( O(1) \)

---

## Advantages

1. **Efficient Insertions**:
   - Supports insertion at both ends, making it versatile.
2. **Fast Deletions**:
   - Deletion from the front is \( O(1) \).
3. **Optimized for Certain Applications**:
   - Useful when data needs frequent modifications at both ends.

---

## Disadvantages

1. **Limited Deletion Flexibility**:
   - Deletion can only happen at one end.
2. **Increased Complexity**:
   - Requires careful implementation to avoid overflow or underflow issues.

---

## Applications

1. **Task Scheduling**:
   - Helps in scenarios where tasks can be added from either end but only removed in FIFO order.
2. **Sliding Window Algorithms**:
   - Used in processing continuous data streams.
3. **Undo Mechanism in Editors**:
   - Allows reversing actions while keeping insertion flexible.

---

## Summary

| Operation         | Array Implementation | Linked List Implementation |
|-------------------|----------------------|-----------------------------|
| Insert at Front   | \( O(1) \)          | \( O(1) \)                 |
| Insert at Rear    | \( O(1) \)          | \( O(1) \)                 |
| Delete from Front | \( O(1) \)          | \( O(1) \)                 |
| Peek at Front     | \( O(1) \)          | \( O(1) \)                 |
| IsEmpty           | \( O(1) \)          | \( O(1) \)                 |
| IsFull            | \( O(1) \)          | \( O(1) \)                 |

---