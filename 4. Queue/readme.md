# Queue
A **Queue** is a linear data structure that follows the FIFO principle: First In, First Out. This means that the element added first to the queue is the one removed first. Queues are widely used in computer science for task scheduling, buffering, and managing resources.

![Repesentaion of Queue](/assets/representationOfQueue.png)

## Characteristics of a Queue
1. Order:
    - Maintains the order of elements; the first element added is the first to be removed.
1. Two Ends:
    - Front: The end where elements are removed.
    - Rear: The end where elements are added.
1. Dynamic Size:
    - Can grow dynamically (if implemented with linked lists) or have a fixed size (if implemented with arrays).
1. Operations:
    - **Enqueue**: Add an element to the rear.
    - **Dequeue**: Remove an element from the front.

### Types of Queues
1. Simple Queue:
    - Basic queue implementation with FIFO behavior.
1. Circular Queue:
    - A queue where the last position connects back to the first position, making it circular.
1. Priority Queue:
    - Each element is associated with a priority. The element with the highest priority is dequeued first, regardless of the order.
1. Deque (Double-Ended Queue):
    - Allows insertion and deletion from both ends.
1. Input-Restricted Deque:
    - Insertion allowed only at one end, deletion from both ends.
1. Output-Restricted Deque:
    - Deletion allowed only at one end, insertion at both ends.

## Common Queue Operations
1. Enqueue
    - Adds an element to the rear of the queue.
2. Dequeue
    - Removes an element from the front of the queue.
3. Peek/Front
    - Retrieves the front element without removing it.
4. IsEmpty
    - Checks if the queue is empty.
5. IsFull (for fixed-size queues)
    - Checks if the queue has reached its maximum capacity.

## Queue Implementation
Queues can be implemented using:
1. Arrays:
    - Fixed size, simple to implement.
    - May lead to the "wastage of space" problem, resolved using a circular queue.
1. Linked List:
    - Dynamic size, no need to predefine capacity.
1. Stacks:
    - Two stacks can be used to implement a queue.

## Applications of Queue
1. Resource Management:
    - CPU scheduling, disk scheduling.
1. Data Buffering:
    - I/O Buffers, file IO.
1. Breadth-First Search:
    - Used in graph traversal.
1. Print Job Management:
    - Printer queues.

## Advantages of Queue
1. Efficient Task Management:
    - Handles processes in the order they arrive (FIFO).
1. Dynamic:
    - Linked list implementation provides dynamic sizing.

## Disadvantages of Queue
1. Fixed Size Limitation:
    - Array-based queues have a predefined size.
1. Memory Overhead:
    - Linked list queues use extra memory for pointers.
1. Circular Implementation Complexity:
    - Circular queues require additional logic to manage wrapping.
