# Circular Queue

A **Circular Queue** is a linear data structure that operates in a circular manner, overcoming the limitations of a standard queue by reusing empty spaces. Unlike a linear queue, a circular queue wraps around when it reaches the end of the underlying storage (array).

---

## Key Characteristics

1. **Fixed Size**: Typically implemented using a fixed-size array.
2. **Circular Behavior**: The last position connects back to the first, creating a circle.
3. **Front and Rear Pointers**:
   - `front`: Points to the first element of the queue.
   - `rear`: Points to the last element of the queue.
4. **Efficient Space Utilization**: Prevents memory wastage by reusing empty spaces created by dequeuing.

---

## Key Operations

### **1. Enqueue (Insert Element)**

Adds an element to the rear of the queue.

#### Steps:
1. Check if the queue is full:
   - If `(rear + 1) % size == front`, the queue is full.
2. If not full, update the `rear` pointer to `(rear + 1) % size`.
3. Insert the new element at the position pointed by `rear`.

#### Time Complexity:
- **Enqueue**: \( O(1) \)

---

### **2. Dequeue (Remove Element)**

Removes an element from the front of the queue.

#### Steps:
1. Check if the queue is empty:
   - If `front == -1`, the queue is empty.
2. Retrieve the element at the position pointed by `front`.
3. Update the `front` pointer:
   - If `front == rear`, set both `front` and `rear` to `-1` (queue becomes empty).
   - Otherwise, update `front` to `(front + 1) % size`.

#### Time Complexity:
- **Dequeue**: \( O(1) \)

---

### **3. Peek (Front Element)**

Returns the element at the front of the queue without removing it.

#### Steps:
1. Check if the queue is empty:
   - If `front == -1`, the queue is underflowed.
2. Return the element at the position pointed by `front`.

#### Time Complexity:
- **Peek**: \( O(1) \)

---

### **4. IsEmpty**

Checks whether the queue is empty.

#### Steps:
1. If `front == -1`, return `true`.
2. Otherwise, return `false`.

#### Time Complexity:
- **IsEmpty**: \( O(1) \)

---

### **5. IsFull**

Checks whether the queue is full.

#### Steps:
1. If `(rear + 1) % size == front`, return `true`.
2. Otherwise, return `false`.

#### Time Complexity:
- **IsFull**: \( O(1) \)

---

## Advantages

1. **Efficient Space Utilization**:
   - Reuses memory by overwriting empty spaces.
2. **Fast Operations**:
   - Both enqueue and dequeue operations are \( O(1) \).

---

## Disadvantages

1. **Fixed Size**:
   - The size of the queue is predefined, limiting scalability.
2. **Complex Implementation**:
   - Requires careful pointer management to avoid errors.

---

## Applications

1. **Resource Scheduling**:
   - Used in operating systems for scheduling processes.
2. **Data Buffers**:
   - Circular queues are used in network traffic management, I/O buffers, and multimedia streaming.
3. **Simulation Systems**:
   - Circular queues are ideal for scenarios involving repeated operations.

---

## Summary

| Operation  | Time Complexity |
|------------|-----------------|
| Enqueue    | \( O(1) \)      |
| Dequeue    | \( O(1) \)      |
| Peek       | \( O(1) \)      |
| IsEmpty    | \( O(1) \)      |
| IsFull     | \( O(1) \)

---

## Code Implementation

Let me know if you'd like the implementation in a specific programming language!
