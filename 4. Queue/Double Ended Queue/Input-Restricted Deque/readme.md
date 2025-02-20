# Input-Restricted Deque

An **Input-Restricted Deque (Double-Ended Queue)** is a special type of deque where insertion is allowed at only one end, but deletion is permitted from both ends.

---

## Key Characteristics
1. **Insertion Constraint**:
   - Elements can only be inserted at the **rear**.
2. **Deletion Flexibility**:
   - Elements can be deleted from **both front and rear**.
3. **Linear or Circular Implementation**:
   - Can be implemented using **arrays** or **linked lists**.

---

## Key Operations

### **1. Insert at Rear** (Enqueue)
**Algorithm:**
1. Check if the deque is full.
2. If the deque is empty, initialize `front` and `rear` to `0`.
3. If `rear` is at the last position, move it to `0` (circular behavior).
4. Otherwise, increment `rear`.
5. Insert the new element at `rear`.

**Time Complexity:**
- **Array Implementation**: \( O(1) \)
- **Linked List Implementation**: \( O(1) \)

---

### **2. Delete from Front** (Dequeue)
**Algorithm:**
1. Check if the deque is empty.
2. Retrieve the element at `front`.
3. If `front` equals `rear`, reset both to `-1` (deque becomes empty).
4. If `front` is at the last position, move it to the first position (circular behavior).
5. Otherwise, increment `front`.

**Time Complexity:**
- **Array Implementation**: \( O(1) \)
- **Linked List Implementation**: \( O(1) \)

---

### **3. Delete from Rear**
**Algorithm:**
1. Check if the deque is empty.
2. Retrieve the element at `rear`.
3. If `front` equals `rear`, reset both to `-1` (deque becomes empty).
4. If `rear` is at the first position, move it to the last position (circular behavior).
5. Otherwise, decrement `rear`.

**Time Complexity:**
- **Array Implementation**: \( O(1) \)
- **Linked List Implementation**: \( O(1) \)

---

### **4. Peek at Front**
Retrieves the element at the front without removing it.

**Algorithm:**
1. Check if the deque is empty.
2. Return the element at `front`.

**Time Complexity:** \( O(1) \)

---

### **5. Peek at Rear**
Retrieves the element at the rear without removing it.

**Algorithm:**
1. Check if the deque is empty.
2. Return the element at `rear`.

**Time Complexity:** \( O(1) \)

---

### **6. IsEmpty**
Checks whether the deque is empty.

**Algorithm:**
1. If `front == -1`, return `true`.
2. Otherwise, return `false`.

**Time Complexity:** \( O(1) \)

---

### **7. IsFull**
Checks whether the deque is full (for a fixed-size implementation).

**Algorithm:**
1. If `(front == 0 && rear == size-1)` or `(front == rear + 1)`, return `true`.
2. Otherwise, return `false`.

**Time Complexity:** \( O(1) \)

---

## Advantages
- **Efficient Deletions**: Deletion can be performed from both ends.
- **Faster Operations**: Insertions and deletions take constant time.

## Disadvantages
- **Limited Insertion Flexibility**: Elements can only be added at the rear.
- **Space Overhead**: For array implementation, unused spaces can exist due to fixed size.

---

## Applications
1. **Job Scheduling**: Managing jobs in priority order while allowing quick removals.
2. **Sliding Window Algorithms**: Used in scenarios where elements need to be removed dynamically.
3. **Data Buffers**: Used in real-time streaming applications where elements are processed in order.

---

## Summary

| Operation         | Array Implementation | Linked List Implementation |
|-------------------|----------------------|-----------------------------|
| Insert at Rear   | \( O(1) \)          | \( O(1) \)                 |
| Delete from Front | \( O(1) \)          | \( O(1) \)                 |
| Delete from Rear  | \( O(1) \)          | \( O(1) \)                 |
| Peek at Front     | \( O(1) \)          | \( O(1) \)                 |
| Peek at Rear      | \( O(1) \)          | \( O(1) \)                 |
| IsEmpty           | \( O(1) \)          | \( O(1) \)                 |
| IsFull            | \( O(1) \)          | \( O(1) \)                 |

---

