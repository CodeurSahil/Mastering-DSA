# Simple Queue
A **Simple Queue** is the most basic type of queue that operates on the First In, First Out (FIFO) principle. It is linear, meaning that elements are added at one end (rear) and removed from the other (front). This structure ensures that the first element added to the queue is the first one to be removed.

## Key Characteristics of a Simple Queue
1. FIFO Order:
    - Elements are processed in the order they are added.
1. Two Pointers:
    - Front: Points to the element at the front of the queue (to be dequeued).
    - Rear: Points to the last element of the queue (where the next element is added).
1. Fixed Size or Dynamic:
    - Can be implemented with a fixed size using arrays or dynamically using linked lists.
1. Sequential Memory Use:
    - Array-based implementations require contiguous memory, while linked list implementations do not.

## Basic Operations on a Simple Queue
1. Enqueue
    - Adds an element to the rear of the queue.
1. Dequeue
    - Removes an element from the front of the queue.
1. Peek/Front
    - Returns the value at the front without removing it.
1. IsEmpty
    - Checks if the queue is empty.
1. IsFull (for array-based queues)
    - Checks if the queue is at full capacity.

## Simple Queue Implementation
1. Using Array
    - Algorithm:
        1. Maintain front and rear pointers.
        1. Increment rear when adding an element.
        1. Increment front when removing an element.
        1. Check for underflow (front > rear) and overflow (rear == size - 1).
1. Using Linked List
    - Algorithm:
        1. Maintain front and rear pointers to the first and last nodes.
        1. Add a new node at rear during enqueue.
        1. Remove the node at front during dequeue.

1. Using Stack
    - Enqueue Costly
        - In this method, the enqueue operation is made costly, while dequeue is efficient.
    - Dequeue Costly
        - In this method, the dequeue operation is made costly, while enqueue is efficient.

## Applications of Simple Queue
1. Task Scheduling:
    - CPU scheduling, printer spooling.
1. Data Transmission:
    - Network packet management.
1. Breadth-First Search (BFS):
    - Traversing graphs or trees.
1. Buffering:
    - Keyboard input, IO buffers.

## Advantages of a Simple Queue
1. FIFO Order:
    - Ensures fair processing order.
1. Simple Logic:
    - Easy to implement and understand.
1. Efficiency:
    - Basic enqueue and dequeue operations are 𝑂(1).

## Disadvantages of a Simple Queue
1. Wastage of Space (Array-Based):
    - Dequeued elements leave unused space that cannot be reclaimed.
1. Fixed Size:
    - Array-based queues require a predefined size, which might not suit dynamic workloads.
1. Limited Operations:
    - Lacks flexibility (cannot insert or delete from arbitrary positions).