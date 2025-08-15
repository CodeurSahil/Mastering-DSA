## Singly Linked List: The One-Way Chain ➡️

A **Singly Linked List (SLL)** is the most fundamental type of linked list. It's a linear data structure composed of a sequence of **nodes**. Each node is a simple container with two parts:

1.  **Data**: The actual information or value being stored.
2.  **Next Pointer**: A reference that points to the next node in the sequence.

The list has a single entry point, called the **head**, which points to the first node. The chain continues until the final node, whose `next` pointer is set to `NULL`, indicating the end of the list. Because each node only points forward, traversal is strictly a one-way street.

***Note: Understand Flow via Code in `linkedList.c`***

---

## Representation of Singly Linked List:-
![Repesentaion of Singly Linked List](/assets/representationOfLinkedList.png)

---

## Operations and Algorithms

Here are the standard operations performed on a Singly Linked List. Let's assume `head` is the pointer to the first node.

* **Traversal**
    * **Goal:** To visit every node in the list, usually to read or display its data.
    * **Algorithm:**
        1.  Create a temporary pointer (`current`) and initialize it with `head`.
        2.  While `current` is not `NULL`:
        3.  Process the data in `current`.
        4.  Move to the next node by updating `current = current.next`.
    * **Complexity:** `$O(n)$`

* **Insertion**
    * **Goal:** To add a new node to the list.
    * **Algorithm (At the Beginning):**
        1.  Create a `newNode`.
        2.  Set `newNode.next` to point to the current `head`.
        3.  Update `head` to point to the `newNode`.
        *This is the most efficient insertion.*
    * **Algorithm (At the End):**
        1.  Create a `newNode`.
        2.  Traverse the list until you find the last node (where `node.next` is `NULL`).
        3.  Set the last node's `next` pointer to the `newNode`.
        *Requires traversing the entire list first.*

* **Deletion**
    * **Goal:** To remove a node from the list.
    * **Algorithm (From the Beginning):**
        1.  Create a temporary pointer to the `head`.
        2.  Update the `head` to point to the second node (`head = head.next`).
        3.  Free the memory of the original head node.
    * **Algorithm (From the End):**
        1.  Traverse the list until you reach the *second-to-last* node.
        2.  Set the `next` pointer of the second-to-last node to `NULL`.
        3.  Free the memory of the original last node.
        *Requires traversing the entire list first.*

* **Search**
    * **Goal:** To find if a value exists in the list and return a reference to its node.
    * **Algorithm:**
        1.  Traverse the list from the `head`.
        2.  At each node, compare its data with the target value.
        3.  If a match is found, return the node.
        4.  If the end of the list is reached without a match, return `NULL`.
    * **Complexity:** `$O(n)$`

---

## Key Properties

* **Linear Structure:** Nodes are arranged one after another in a single sequence.
* **Unidirectional:** You can only traverse the list forward, from head to tail. There's no going back.
* **Dynamic Size:** The list can easily grow or shrink at runtime by adding or removing nodes.
* **Head Pointer:** The entire list is accessed through a single reference to the first node, the `head`.

---

## Advantages 👍

* **Efficient Head Operations:** Insertion and deletion at the beginning of the list are extremely fast, taking constant time `$O(1)$`.
* **Dynamic Memory Use:** Memory is allocated only when a new node is created, which avoids the wasted space common in static arrays.
* **Simple to Implement:** Its straightforward structure makes it one of the easiest data structures to code from scratch.

---

## Disadvantages 👎

* **No Backward Traversal:** The biggest limitation. You cannot navigate to a previous node without starting over from the head.
* **Slow Random Access:** To access the $k^{th}$ node, you must traverse the first $k-1$ nodes. This makes access an `$O(n)` operation, compared to an array's `$O(1)$` access.
* **Inefficient End Operations:** Inserting or deleting a node at the end of the list requires traversing the entire list, making it an `$O(n)` operation.

---

## Applications

Singly Linked Lists are ideal for scenarios where operations are mostly focused on the start of the list.
* **Implementing Stacks:** The LIFO (Last-In, First-Out) nature of a stack maps perfectly to the `$O(1)` insertion and deletion at the head of an SLL.
* **Implementing Queues:** Can be used, but requires an additional `tail` pointer for efficiency.
* **Collision Resolution in Hash Tables:** In a method called *chaining*, elements that hash to the same bucket are stored in a linked list.
* **Representing Adjacency Lists for Graphs:** Each vertex in a graph can have a linked list of its adjacent vertices.

---

## Time Complexity Summary ⏱️

| Operation | Best Case | Worst Case | Explanation |
| :--- | :--- | :--- | :--- |
| **Access (by position)** | `$O(1)$` | `$O(n)` | `$O(1)` for the head, `$O(n)` for all others. |
| **Search (by value)** | `$O(1)` | `$O(n)` | `$O(1)` if found at head, `$O(n)` if at the end or not present. |
| **Insertion (at beginning)** | `$O(1)$` | `$O(1)$` | Always a constant time operation. |
| **Insertion (at end)** | `$O(n)$` | `$O(n)` | Always requires traversal to the last node. |
| **Deletion (from beginning)** | `$O(1)$` | `$O(1)$` | Always a constant time operation. |
| **Deletion (from end)** | `$O(n)$` | `$O(n)` | Always requires traversal to the second-to-last node. |

---

## Important Additional Information

### The Tail Pointer Optimization

A common and highly effective improvement to the SLL is to maintain an extra pointer called `tail` that always points to the last node in the list.

* **What it is:** A separate pointer, alongside `head`, that is updated whenever a node is added to or removed from the end.
* **Benefit:** With a `tail` pointer, **insertion at the end becomes an `$O(1)` operation**. You no longer need to traverse the list to find the last node; you can just jump to it directly using `tail`.
* **Trade-off:** Deletion from the end remains `$O(n)` because even with a `tail` pointer, you still need to find the *second-to-last* node to update its `next` reference. This is a key reason why Doubly Linked Lists are often preferred.