# Priority Queue

A **Priority Queue** is a specialized type of queue in which each element is associated with a priority, and the element with the highest priority is served before the others. If two elements have the same priority, they are served according to their order in the queue (depending on the implementation).

---

## Key Characteristics

1. **Priority-Based Ordering**:
   - Elements are dequeued based on their priority rather than their order of arrival.
   - Higher-priority elements are served first.
2. **Dynamic Behavior**:
   - Elements can be inserted with varying priorities, altering the queue's behavior dynamically.
3. **Implementation Options**:
   - Can be implemented using arrays, linked lists, heaps, or binary search trees.
4. **Priority Rules**:
   - Min-Priority Queue: Lower values indicate higher priority.
   - Max-Priority Queue: Higher values indicate higher priority.

---

## Key Operations

### **1. Insertion**

Adds an element to the priority queue with a specific priority.

#### Steps:
1. Insert the element into the queue.
2. Maintain the priority order by arranging elements accordingly.

#### Time Complexity:
- Depends on the implementation:
  - **Array (unsorted)**: \( O(1) \)
  - **Array (sorted)**: \( O(n) \)
  - **Heap**: \( O(\log n) \)

---

### **2. Deletion (Remove Highest Priority Element)**

Removes the element with the highest priority from the queue.

#### Steps:
1. Identify the element with the highest priority.
2. Remove it from the queue.
3. Rearrange the remaining elements to maintain the priority order.

#### Time Complexity:
- Depends on the implementation:
  - **Array (unsorted)**: \( O(n) \)
  - **Array (sorted)**: \( O(1) \)
  - **Heap**: \( O(\log n) \)

---

### **3. Peek (Retrieve Highest Priority Element)**

Retrieves the element with the highest priority without removing it.

#### Steps:
1. Identify the element with the highest priority.
2. Return the element.

#### Time Complexity:
- Depends on the implementation:
  - **Array (unsorted)**: \( O(n) \)
  - **Array (sorted)**: \( O(1) \)
  - **Heap**: \( O(1) \)

---

### **4. IsEmpty**

Checks whether the priority queue is empty.

#### Steps:
1. If the queue has no elements, return `true`.
2. Otherwise, return `false`.

#### Time Complexity:
- **IsEmpty**: \( O(1) \)

---

## Advantages

1. **Efficient Task Scheduling**:
   - Tasks can be processed based on their importance.
2. **Dynamic Adjustments**:
   - Priorities can be adjusted dynamically to reflect changing requirements.
3. **Flexible Implementations**:
   - Can be tailored using different data structures to optimize specific operations.

---

## Disadvantages

1. **Complexity**:
   - Maintaining the priority order can be computationally expensive in some implementations.
2. **Overhead**:
   - Additional storage and computation are required to manage priorities.

---

## Applications

1. **Operating Systems**:
   - Task scheduling, where high-priority processes are executed first.
2. **Networking**:
   - Packet routing based on priority levels.
3. **Dijkstra's Algorithm**:
   - Finding the shortest path in a graph.
4. **Event Simulation**:
   - Managing events in simulations where some events must occur before others.

---

## Implementation Options

### **1. Using an Unsorted Array**
- Enqueue is fast, but finding and removing the highest-priority element is slow.

### **2. Using a Sorted Array**
- Enqueue is slow, but finding and removing the highest-priority element is fast.

### **3. Using a Heap (Binary Heap)**
- Offers a balanced approach with \( O(\log n) \) for both insertion and deletion.
- Commonly used for efficient priority queue implementation.

---

## Summary

| Operation        | Unsorted Array | Sorted Array | Heap         |
|------------------|----------------|--------------|--------------|
| Insertion        | \( O(1) \)     | \( O(n) \)   | \( O(\log n) \) |
| Deletion         | \( O(n) \)     | \( O(1) \)   | \( O(\log n) \) |
| Peek             | \( O(n) \)     | \( O(1) \)   | \( O(1) \)      |

---
