# Implementation of Queue Using Linked List
Implementing a queue using a linked list provides a dynamic and flexible structure that avoids the limitations of fixed size present in array-based queues.

## Key Components of Linked-List-Based Queue
1. Nodes:
    
    - Each node contains:
        1. Data: The value stored in the node.
        1. Next Pointer: A reference to the next node in the sequence.
1. Front Pointer:
    - Points to the first node in the queue (the element to be dequeued next).
1. Rear Pointer:
    - Points to the last node in the queue (the most recently added element).

## Operations on Queue Using Linked List
1. Enqueue (Insertion)
    - Adds a new element to the rear of the queue.
    - Steps:
        1. Create a new node with the given data.
        1. If the queue is empty (front == null), both front and rear point to the new node.
        1. Otherwise:
        1. Set the next pointer of the current rear to the new node.
        1. Update the rear pointer to the new node.
    - Time Complexity: 𝑂(1)

2. Dequeue (Deletion)
    - Removes the element from the front of the queue.
    - Steps:
        1. Check if the queue is empty (front == null).
        1. If empty, report underflow.
        1. Otherwise:
        1. Store the data of the front node for return.
        1. Update front to point to the next node in the sequence.
        1. If front == null after update, set rear = null (queue is now empty).
    - Time Complexity: 𝑂(1)

3. Peek/Front
    - Returns the value of the element at the front of the queue without removing it.
    - Steps:
        1. Check if the queue is empty.
        1. If not empty, return the data of the node pointed to by front.
    - Time Complexity: 𝑂(1)

4. IsEmpty
    - Checks whether the queue is empty.
    - Steps:
        1. If front == null, the queue is empty.
    - Time Complexity: 𝑂(1)

## Applications of Linked-List-Based Queue
1. Dynamic Task Scheduling:
    - Jobs with varying arrival rates.
1. Breadth-First Search (BFS):
    - Used for graph and tree traversal.
1. Resource Sharing:
    - Shared resource queues like printers, network routers.
1. Dynamic Buffering:
    - Handles dynamically changing workloads without fixed size limitations.

## Special Cases
1. Empty Queue:
    - Both front and rear pointers are null.
1. Single Element Queue:
    - Both front and rear point to the same node.
    - Enqueue creates a new node, and dequeue sets both pointers back to null.

## Advantages of Linked-List-Based Queue
1. Dynamic Size:
    - No need to define a fixed size; memory is allocated as needed.
1. Efficient Memory Usage:
    - No wastage of space as in fixed-size arrays.
1. Consistent 𝑂(1) Operations:
    - Both enqueue and dequeue operations take constant time.
1. Flexible Growth:
    - Can handle large data without reallocation or resizing overhead.

## Disadvantages of Linked-List-Based Queue
1. Memory Overhead:
    - Each node requires extra memory for the pointer, increasing memory usage compared to arrays.
1. Cache Performance:
    - Poorer cache locality compared to arrays, as linked list nodes are scattered in memory.
1. Complexity:
    - Slightly more complex to implement and manage compared to arrays.
