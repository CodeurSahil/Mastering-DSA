# Implementation of Queue Using Stack (Costly Enqueue)

This approach simulates a **queue** using two **stacks**, where the **enqueue operation** is made **costly** to ensure the **FIFO (First In, First Out)** behavior of a queue.

---

## Key Components

1. **Two Stacks**:
   - `stack1`: Used for temporary storage during enqueue operations.
   - `stack2`: Maintains the elements in the correct order for dequeuing.

2. **Stack Properties**:
   - **Push**: Adds an element to the top of the stack.
   - **Pop**: Removes and returns the top element.

---

## Steps for Operations

### **1. Enqueue (Costly)**

When adding a new element to the queue, we ensure that the order in `stack2` is maintained so that the oldest element is always at the top.

#### Steps:
1. Pop all elements from `stack2` and push them into `stack1`.
2. Push the new element into `stack2`.
3. Transfer all elements back from `stack1` to `stack2`.

This ensures that the oldest element is at the top of `stack2`.

#### Time Complexity:
- **Enqueue**: \( O(n) \), where \( n \) is the number of elements in the queue.

---

### **2. Dequeue (Efficient)**

Simply remove the top element from `stack2`, as it already maintains the correct FIFO order.

#### Steps:
1. If `stack2` is empty, the queue is underflowed.
2. Otherwise, pop and return the top element of `stack2`.

#### Time Complexity:
- **Dequeue**: \( O(1) \)

---

### **3. Peek (Front)**

Returns the element at the front of the queue without removing it. The front element is always at the top of `stack2`.

#### Steps:
1. If `stack2` is empty, the queue is underflowed.
2. Otherwise, return the top element of `stack2`.

#### Time Complexity:
- **Peek**: \( O(1) \)

---

### **4. IsEmpty**

Checks whether the queue is empty by verifying if `stack2` is empty.

#### Steps:
1. If `stack2` is empty, return `true`.
2. Otherwise, return `false`.

#### Time Complexity:
- **IsEmpty**: \( O(1) \)

---

## Advantages

1. **FIFO Behavior**:
   - The costly enqueue operation ensures that the dequeue operation is efficient and follows the FIFO principle.
2. **Dynamic Size**:
   - Memory usage grows dynamically with the number of elements.

---

## Disadvantages

1. **Costly Enqueue**:
   - Enqueue operation requires transferring all elements between the two stacks, making it inefficient for frequent insertions.
2. **Memory Overhead**:
   - Two stacks are required, doubling the memory usage compared to a standard queue.

---

## Applications

1. **Algorithm Demonstrations**:
   - Useful for teaching stack-to-queue transformations.
2. **Limited Use Cases**:
   - Suitable for scenarios where enqueue operations are infrequent compared to dequeues.

---

## Summary

| Operation  | Time Complexity |
|------------|-----------------|
| Enqueue    | \( O(n) \)      |
| Dequeue    | \( O(1) \)      |
| Peek       | \( O(1) \)      |
| IsEmpty    | \( O(1) \)      |

---
