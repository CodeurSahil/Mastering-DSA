# Implementation of Queue Using Stack (Costly Dequeue)

This approach simulates a **Queue** using two **stacks**, where the **dequeue operation** is made **costly** to ensure the **FIFO (First In, First Out)** behavior of a queue.

---

## Key Components

1. **Two Stacks**:
   - `stack1`: Used for enqueue operations.
   - `stack2`: Used for dequeue operations.

2. **Stack Properties**:
   - **Push**: Adds an element to the top of the stack.
   - **Pop**: Removes and returns the top element.

---

## Steps for Operations

### **1. Enqueue (Efficient)**

In this implementation, the enqueue operation is straightforward, as elements are simply pushed onto `stack1`.

#### Steps:
1. Push the new element onto `stack1`.

#### Time Complexity:
- **Enqueue**: \( O(1) \)

---

### **2. Dequeue (Costly)**

When removing an element from the queue, we ensure that the oldest element is returned. To achieve this, we use `stack2` to reverse the order of elements in `stack1`.

#### Steps:
1. If `stack2` is empty:
   - Pop all elements from `stack1` and push them into `stack2`.
   - This reverses the order, so the oldest element is at the top of `stack2`.
2. If `stack2` is still empty after the transfer, the queue is underflowed.
3. Otherwise, pop and return the top element of `stack2`.

#### Time Complexity:
- **Dequeue**: \( O(n) \), where \( n \) is the number of elements in the queue.

---

### **3. Peek (Front)**

Returns the element at the front of the queue without removing it. The front element is always at the top of `stack2`.

#### Steps:
1. If `stack2` is empty:
   - Pop all elements from `stack1` and push them into `stack2`.
2. If `stack2` is still empty after the transfer, the queue is underflowed.
3. Otherwise, return the top element of `stack2`.

#### Time Complexity:
- **Peek**: \( O(n) \)

---

### **4. IsEmpty**

Checks whether the queue is empty by verifying if both `stack1` and `stack2` are empty.

#### Steps:
1. If both `stack1` and `stack2` are empty, return `true`.
2. Otherwise, return `false`.

#### Time Complexity:
- **IsEmpty**: \( O(1) \)

---

## Advantages

1. **Efficient Enqueue**:
   - Suitable for scenarios where enqueue operations are more frequent than dequeues.
2. **FIFO Behavior**:
   - The costly dequeue operation ensures that the oldest element is always dequeued first.

---

## Disadvantages

1. **Costly Dequeue**:
   - Dequeue operation requires transferring all elements between the two stacks, making it inefficient for frequent deletions.
2. **Memory Overhead**:
   - Two stacks are required, doubling the memory usage compared to a standard queue.

---

## Applications

1. **Algorithm Demonstrations**:
   - Useful for teaching stack-to-queue transformations.
2. **Limited Use Cases**:
   - Suitable for scenarios where enqueue operations are frequent compared to dequeues.

---

## Summary

| Operation  | Time Complexity |
|------------|-----------------|
| Enqueue    | \( O(1) \)      |
| Dequeue    | \( O(n) \)      |
| Peek       | \( O(n) \)      |
| IsEmpty    | \( O(1) \)

---
