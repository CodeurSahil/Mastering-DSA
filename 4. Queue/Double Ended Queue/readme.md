# Double-Ended Queue (Deque)

A **Double-Ended Queue (Deque)** is a linear data structure where elements can be added or removed from both ends, making it more flexible than a regular queue. It combines the functionality of a queue and a stack.

---

## Key Characteristics

1. **Bi-Directional Operations**:
   - Supports insertion and deletion at both the front and rear ends.
2. **Flexible Storage**:
   - Can be implemented using arrays or linked lists.
3. **Variants**:
   - **Input-Restricted Deque**: Insertion is allowed at one end only.
   - **Output-Restricted Deque**: Deletion is allowed at one end only.

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
- **Array Implementation**: \( O(n) \) (due to shifting elements).
- **Linked List Implementation**: \( O(1) \).

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
- **Array Implementation**: \( O(1) \) (if space is available).
- **Linked List Implementation**: \( O(1) \).

---

### **3. Delete from Front**

Removes an element from the front of the deque.

#### Algorithm:
1. Check if the deque is empty.
2. Retrieve the element at the `front` position.
3. If `front` equals `rear`, reset both to -1 (deque becomes empty).
4. If `front` is at the last position, move it to the first position (circular behavior).
5. Otherwise, increment `front`.

#### Time Complexity:
- **Array Implementation**: \( O(n) \) (due to shifting elements).
- **Linked List Implementation**: \( O(1) \).

---

### **4. Delete from Rear**

Removes an element from the rear of the deque.

#### Algorithm:
1. Check if the deque is empty.
2. Retrieve the element at the `rear` position.
3. If `front` equals `rear`, reset both to -1 (deque becomes empty).
4. If `rear` is at the first position, move it to the last position (circular behavior).
5. Otherwise, decrement `rear`.

#### Time Complexity:
- **Array Implementation**: \( O(1) \).
- **Linked List Implementation**: \( O(1) \).

---

### **5. Peek at Front**

Retrieves the element at the front without removing it.

#### Algorithm:
1. Check if the deque is empty.
2. Return the element at the `front` position.

#### Time Complexity:
- **Array/Linked List Implementation**: \( O(1) \).

---

### **6. Peek at Rear**

Retrieves the element at the rear without removing it.

#### Algorithm:
1. Check if the deque is empty.
2. Return the element at the `rear` position.

#### Time Complexity:
- **Array/Linked List Implementation**: \( O(1) \).

---

### **7. IsEmpty**

Checks whether the deque is empty.

#### Algorithm:
1. If `front == -1`, return `true`.
2. Otherwise, return `false`.

#### Time Complexity:
- **Array/Linked List Implementation**: \( O(1) \).

---

### **8. IsFull**

Checks whether the deque is full (for a fixed-size implementation).

#### Algorithm:
1. If `(front == 0 && rear == size-1)` or `(front == rear + 1)`, return `true`.
2. Otherwise, return `false`.

#### Time Complexity:
- **Array Implementation**: \( O(1) \).

---

## Advantages

1. **Bi-Directional Access**:
   - Supports both stack and queue functionalities.
2. **Efficient Operations**:
   - Allows insertion and deletion at both ends efficiently in linked list implementation.

---

## Disadvantages

1. **Increased Complexity**:
   - Managing operations for both ends requires careful implementation.
2. **Space Overhead**:
   - For linked list implementation, additional memory is needed for pointers.

---

## Applications

1. **Palindrome Checking**:
   - Used to verify whether a string is a palindrome by comparing characters from both ends.
2. **Job Scheduling**:
   - Efficiently schedules jobs with varying priorities.
3. **Sliding Window Problems**:
   - Ideal for problems involving sliding windows in arrays.

---

## Summary

| Operation         | Array Implementation | Linked List Implementation |
|-------------------|----------------------|-----------------------------|
| Insert at Front   | \( O(n) \)          | \( O(1) \)                 |
| Insert at Rear    | \( O(1) \)          | \( O(1) \)                 |
| Delete from Front | \( O(n) \)          | \( O(1) \)                 |
| Delete from Rear  | \( O(1) \)          | \( O(1) \)                 |
| Peek at Front     | \( O(1) \)          | \( O(1) \)                 |
| Peek at Rear      | \( O(1) \)          | \( O(1) \)                 |
| IsEmpty           | \( O(1) \)          | \( O(1) \)                 |
| IsFull            | \( O(1) \)          | \( O(1) \)                 |

---