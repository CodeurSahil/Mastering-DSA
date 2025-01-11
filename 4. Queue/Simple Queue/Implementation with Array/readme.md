# Implementation of Queue Using Array
A Queue implemented using an array is a simple and efficient approach to realize the FIFO (First In, First Out) principle.

## Key Components of Array-Based Queue
1. Array:
    - Used to store the elements of the queue.
    - Fixed size, determined at the time of queue creation.
1. Front Pointer:
    - Points to the element at the front of the queue (the one to be dequeued next).
1. Rear Pointer:
    - Points to the last element of the queue (the most recently added element).
1. Size:
    - The capacity of the array determines the maximum number of elements the queue can hold.

## Operations on Queue Using Array
1. Enqueue (Insertion)
    - Adds an element at the rear of the queue.
    - Algorithm
        1. Check if the queue is full (rear == capacity - 1).
        1. If not full, increment the rear pointer.
        1. Insert the new element at the position indicated by rear.
    - Time Complexity: 𝑂(1)

2. Dequeue (Deletion)
    - Removes the element at the front of the queue.
    - Algorithm:
        1. Check if the queue is empty (front > rear).
        1. If not empty, retrieve the element at the front pointer.
        1. Increment the front pointer.
    - Time Complexity: 𝑂(1)

**NOTE**(Problem): After several enqueue and dequeue operations, unused space accumulates at the beginning of the array. `Circular Queue to Address Space Wastage`.

3. Peek/Front
    - Returns the value of the element at the front without removing it.
    - Algorithm:
        1. Check if the queue is empty (front > rear).
        1. Return the element at the front pointer.
    - Time Complexity: 𝑂(1)

4. IsEmpty
    - Checks whether the queue is empty.
    - Algorithm:
        1. If front > rear, the queue is empty.
    - Time Complexity: 𝑂(1)

5. IsFull
    - Checks whether the queue has reached its maximum capacity.
    - Algorithm:
        1. If rear == capacity - 1, the queue is full.
    - Time Complexity: 𝑂(1)

## Applications of Array-Based Queue
1. Task Scheduling:
    - Jobs are processed in the order they arrive.
1. Breadth-First Search (BFS):
    - Queues are used to traverse graphs or trees.
1. Data Transmission:
    - Buffering and network packet management.
1. Resource Sharing:
    - Shared resources like printers, CPUs, etc.

## Advantages of Array-Based Queue
1. Simplicity:
    - Easy to implement with direct memory access.
1. Efficient Operations:
    - Both enqueue and dequeue operations are 𝑂(1).
1. Predictable Memory Use:
    - Fixed size ensures no dynamic allocation overhead.

## Disadvantages of Array-Based Queue
1. Fixed Size:
    - The maximum capacity must be predefined, which can lead to memory wastage or overflow.
1. Wastage of Space:
    - In the simple queue (non-circular), space at the beginning of the array is wasted after multiple dequeues.
1. No Dynamic Growth:
    - It does not automatically adjust to the workload like a linked-list-based queue.
