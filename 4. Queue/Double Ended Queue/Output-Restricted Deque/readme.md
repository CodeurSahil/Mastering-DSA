## Output-Restricted Deque: Add from Both Ends, Remove from One

An **Output-Restricted Deque** is a specialized version of a Double-Ended Queue (Deque). It follows a specific rule: elements can be **inserted** at both the `front` and the `rear`, but can only be **deleted** from the `front`.

Think of it like a special ticket line. Regular customers can join at the back of the line, while VIP customers can be added directly to the front. However, the ticket agent only ever serves the person at the very front of the line.

***Note: Understand Flow via Code in `deQueue.c`***

---

## How It Works: Hybrid Behavior

This structure is a hybrid that combines the functionalities of a standard queue and a stack.

* By using **`addRear`** and **`removeFront`**, it behaves exactly like a **standard FIFO Queue**.
* By using **`addFront`** and **`removeFront`**, it behaves exactly like a **LIFO Stack**.

The Output-Restricted Deque allows you to use both types of insertions, but because removal is only from the front, it enforces a strict, ordered processing of elements.

---

## Operations and Algorithms

Here are the detailed algorithms for the allowed operations, assuming an implementation with a circular array of size `MAX_SIZE`. The pointers `front` and `rear` are initialized to -1.

* **addFront(value)**
    * **Goal:** Add a new element to the front of the deque.
    * **Algorithm:**
        1.  Check if the deque is full (`(front == 0 && rear == MAX_SIZE - 1)` or `(front == rear + 1)`). If so, throw an overflow error.
        2.  If the deque is empty (`front == -1`), set `front = 0` and `rear = 0`.
        3.  Else if `front` is at the beginning (`front == 0`), wrap it around to the end: `front = MAX_SIZE - 1`.
        4.  Otherwise, decrement `front`: `front = front - 1`.
        5.  Insert the new element: `array[front] = value`.

* **addRear(value)**
    * **Goal:** Add a new element to the rear of the deque.
    * **Algorithm:**
        1.  Check if the deque is full (`(front == 0 && rear == MAX_SIZE - 1)` or `(front == rear + 1)`). If so, throw an overflow error.
        2.  If the deque is empty (`front == -1`), set `front = 0` and `rear = 0`.
        3.  Else if `rear` is at the end (`rear == MAX_SIZE - 1`), wrap it around to the start: `rear = 0`.
        4.  Otherwise, increment `rear`: `rear = rear + 1`.
        5.  Insert the new element: `array[rear] = value`.

* **removeFront()**
    * **Goal:** Remove an element from the front (the only allowed deletion).
    * **Algorithm:**
        1.  Check if the deque is empty (`front == -1`). If so, throw an underflow error.
        2.  Store the data to be returned: `data_to_return = array[front]`.
        3.  If this is the last element (`front == rear`), reset the deque: `front = -1`, `rear = -1`.
        4.  Else if `front` is at the end (`front == MAX_SIZE - 1`), wrap it around to the start: `front = 0`.
        5.  Otherwise, increment `front`: `front = front + 1`.
        6.  Return the stored data.

* **peekFront()**
    * **Goal:** View the element at the front of the deque without removing it.
    * **Algorithm:**
        1.  Check if the deque is empty (`front == -1`). If so, indicate an error.
        2.  Return the element at `array[front]`.

* **isEmpty()**
    * **Goal:** Check if the deque contains any elements.
    * **Algorithm:**
        1.  Return `true` if `front == -1`, otherwise return `false`.

* **isFull()**
    * **Goal:** Check if the deque has reached its maximum capacity.
    * **Algorithm:**
        1.  Return `true` if `(front == 0 && rear == MAX_SIZE - 1)` or if `(front == rear + 1)`. Otherwise, return `false`.

---

## Key Properties

* **Restricted Output:** The defining characteristic. Deletion (output) is only possible from the `front`.
* **Flexible Input:** Insertion (input) is allowed at both the `front` and `rear`.
* **Hybrid Functionality:** Blends the behaviors of a stack and a queue.
* **Implementation:** Can be implemented efficiently using a **Doubly Linked List** or a **Circular Array**. The only difference from a full deque implementation is that the `removeRear` method is not exposed.

---

## Advantages 👍

* **More Flexible than a Queue:** The ability to add high-priority items to the front (`addFront`) is a significant advantage over a standard queue that only allows adding to the rear.
* **Maintains FIFO Integrity for Removal:** While insertions are flexible, the removal process is strictly ordered from the front, which is crucial for many scheduling and processing algorithms.

---

## Disadvantages 👎

* **Less Flexible than a Full Deque:** The restriction on output makes it less versatile than a standard deque, which allows removal from both ends.
* **Niche Use Case:** It's a specialized tool and not as generally applicable as a full deque, stack, or queue.

---

## Applications

This data structure is perfect for scenarios that require a primary FIFO processing order but also need a way to inject high-priority items at the front.

* **Priority Job Schedulers:** This is a classic use case.
    * Normal-priority jobs are added to the rear using `addRear`.
    * High-priority or urgent jobs are added to the front using `addFront`.
    * The scheduler always processes the next available job from the front using `removeFront`.
* **Buffer Management:** Can be used in systems where data arrives from two different sources (e.g., a normal channel and a high-priority channel) but is consumed by a single process in a strict sequential order.

---

## Time Complexity

For both efficient Doubly Linked List and Circular Array implementations:

| Operation | Complexity |
| :--- | :---: |
| **addFront** | `$O(1)` |
| **addRear** | `$O(1)` |
| **removeFront** | `$O(1)` |
| **peekFront** | `$O(1)` |
| **isEmpty / isFull** | `$O(1)` |