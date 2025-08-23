## Input-Restricted Deque: Add from One End, Remove from Both

An **Input-Restricted Deque** is a specialized version of a Double-Ended Queue (Deque). It follows a specific rule: elements can only be **inserted** at one end (typically the `rear`), but can be **deleted** from both the `front` and the `rear`.

Think of it like a conveyor belt in a factory. New items are only placed on the belt at the very beginning (`rear`). However, workers can pick items off the belt from either the end of the line (`front`) or right from the back, just after an item was placed (`rear`).

***Note: Understand Flow via Code in `deQueue.c`***

---

## How It Works: Hybrid Behavior

This structure is a hybrid that allows a single stream of incoming data to be processed in two different ways.

* By using **`addRear`** and **`removeFront`**, it behaves exactly like a **standard FIFO Queue**.
* By using **`addRear`** and **`removeRear`**, it behaves exactly like a **LIFO Stack**.

This allows an algorithm to choose whether to process an item in the order it arrived or to immediately process the most recently added item.

---

## Operations and Algorithms

Here are the detailed algorithms for the allowed operations, assuming an implementation with a circular array of size `MAX_SIZE`. The pointers `front` and `rear` are initialized to -1.

* **addRear(value)**
    * **Goal:** Add a new element to the rear of the deque (the only allowed insertion).
    * **Algorithm:**
        1.  Check if the deque is full (`(front == 0 && rear == MAX_SIZE - 1)` or `(front == rear + 1)`). If so, throw an overflow error.
        2.  If the deque is empty (`front == -1`), set `front = 0` and `rear = 0`.
        3.  Else if `rear` is at the end (`rear == MAX_SIZE - 1`), wrap it around to the start: `rear = 0`.
        4.  Otherwise, increment `rear`: `rear = rear + 1`.
        5.  Insert the new element: `array[rear] = value`.

* **removeFront()**
    * **Goal:** Remove an element from the front of the deque.
    * **Algorithm:**
        1.  Check if the deque is empty (`front == -1`). If so, throw an underflow error.
        2.  Store the data to be returned: `data_to_return = array[front]`.
        3.  If this is the last element (`front == rear`), reset the deque: `front = -1`, `rear = -1`.
        4.  Else if `front` is at the end (`front == MAX_SIZE - 1`), wrap it around to the start: `front = 0`.
        5.  Otherwise, increment `front`: `front = front + 1`.
        6.  Return the stored data.

* **removeRear()**
    * **Goal:** Remove an element from the rear of the deque.
    * **Algorithm:**
        1.  Check if the deque is empty (`front == -1`). If so, throw an underflow error.
        2.  Store the data to be returned: `data_to_return = array[rear]`.
        3.  If this is the last element (`front == rear`), reset the deque: `front = -1`, `rear = -1`.
        4.  Else if `rear` is at the beginning (`rear == 0`), wrap it around to the end: `rear = MAX_SIZE - 1`.
        5.  Otherwise, decrement `rear`: `rear = rear - 1`.
        6.  Return the stored data.

* **peekFront()**
    * **Goal:** View the element at the front of the deque without removing it.
    * **Algorithm:**
        1.  Check if the deque is empty (`front == -1`). If so, indicate an error.
        2.  Return the element at `array[front]`.

* **peekRear()**
    * **Goal:** View the element at the rear of the deque without removing it.
    * **Algorithm:**
        1.  Check if the deque is empty (`front == -1`). If so, indicate an error.
        2.  Return the element at `array[rear]`.

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

* **Restricted Input:** The defining characteristic. Insertion is only possible at the `rear`.
* **Flexible Output:** Deletion is allowed from both the `front` and the `rear`.
* **Hybrid Functionality:** Can simulate both a stack and a queue using the same input stream.
* **Implementation:** Can be implemented efficiently using a **Doubly Linked List** or a **Circular Array**.

---

## Advantages 👍

* **Flexible Processing:** Allows a single stream of incoming data to be processed in either a FIFO or LIFO manner, which is useful for certain algorithms.
* **More Powerful than a Queue or Stack:** It combines the capabilities of both structures into a single, more versatile tool.

---

## Disadvantages 👎

* **Less Flexible than a Full Deque:** The restriction on input makes it less versatile than a standard deque, which allows insertion at both ends.
* **Niche Use Case:** It's a specialized tool designed for specific algorithmic patterns rather than general-purpose use.

---

## Applications

This data structure, sometimes called a **Steque** (stack-ended queue), is useful in specific algorithmic contexts.

* **Sliding Window Algorithms:** Can be used in problems where you add elements to a window from one side and need to decide whether to discard old elements (from the front) or recently added, non-optimal elements (from the rear).
* **Algorithmic Puzzles:** Often appears in competitive programming and algorithm design problems that require a blend of stack and queue properties.

---

## Time Complexity

For both efficient Doubly Linked List and Circular Array implementations:

| Operation | Complexity |
| :--- | :---: |
| **addRear** | `$O(1)` |
| **removeFront**| `$O(1)` |
| **removeRear** | `$O(1)` |
| **peekFront / peekRear** | `$O(1)` |
| **isEmpty / isFull** | `$O(1)` |