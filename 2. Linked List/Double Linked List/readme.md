## Doubly Linked List: The Two-Way Street ↔️

A **Doubly Linked List (DLL)** is an advanced version of a linked list that allows for traversal in both forward and backward directions. This is possible because each **node** in the list contains three essential parts:

1.  **Data**: The information or value stored in the node.
2.  **Next Pointer**: A reference pointing to the **next** node in the sequence.
3.  **Previous Pointer (Prev)**: A reference pointing to the **previous** node in the sequence.

The list is typically managed using two pointers: a `head` pointing to the first node (whose `prev` is `NULL`) and a `tail` pointing to the last node (whose `next` is `NULL`). This two-way structure makes a DLL more flexible and powerful than its singly linked counterpart.

***Note: Understand Flow via Code in `doublyLinkedList.c`***

---

Representation of DLL:
    ![Repesentaion of Linked List](/assets/representationOfDoublyLinkedList.png)

---

## Core Operations & Algorithms

Managing a DLL involves careful manipulation of both `next` and `prev` pointers.

* **Traversal**
    * **Goal:** To visit the nodes in sequence.
    * **Forward Algorithm:** Start at the `head` and follow the `next` pointers until you reach `NULL`.
    * **Backward Algorithm:** Start at the `tail` and follow the `prev` pointers until you reach `NULL`.
    * **Complexity:** `$O(n)$` for a full traversal.

* **Insertion**
    * **Goal:** To add a new node.
    * **Algorithm (At the Beginning):**
        1.  Create a `newNode`.
        2.  Set `newNode.next` to the current `head`.
        3.  If the list isn't empty, set the current `head.prev` to `newNode`.
        4.  Update `head` to be `newNode`.
    * **Algorithm (At the End):**
        1.  Create a `newNode`.
        2.  Set `newNode.prev` to the current `tail`.
        3.  If the list isn't empty, set the current `tail.next` to `newNode`.
        4.  Update `tail` to be `newNode`.
        *This is `$O(1)` because of the `tail` pointer.*

* **Deletion**
    * **Goal:** To remove a node.
    * **Algorithm (From the Beginning):**
        1.  Update `head` to point to `head.next`.
        2.  If the new `head` exists, set its `prev` pointer to `NULL`.
        3.  Free the memory of the original head node.
    * **Algorithm (From the End):**
        1.  Update `tail` to point to `tail.prev`.
        2.  If the new `tail` exists, set its `next` pointer to `NULL`.
        3.  Free the memory of the original tail node.

* **Search**
    * **Goal:** To find a node with a specific value.
    * **Algorithm:** Traverse the list from the `head` (or `tail`) and compare the data at each node with the target value.
    * **Complexity:** `$O(n)$`

---

## Key Properties

* **Bidirectional:** Nodes can be traversed both forwards (using `next`) and backwards (using `prev`).
* **Complex Nodes:** Each node holds data and two pointers, increasing its size.
* **Dynamic Size:** The list can grow and shrink at runtime without needing to be resized.
* **Efficient End Operations:** Maintaining `head` and `tail` pointers allows for `$O(1)` insertions and deletions at both ends.

---

## Advantages 👍

* **Flexible Traversal:** The ability to move in both directions makes many algorithms simpler and more efficient.
* **Efficient Deletion:** If you have a pointer to a specific node, you can delete it in `$O(1)` time. This is a major advantage over a Singly Linked List, where you would first need to find the previous node (`$O(n)`).
* **Efficient End Operations:** Adding or removing from the tail is just as fast as at the head (`$O(1)`).

---

## Disadvantages 👎

* **Higher Memory Usage:** Each node requires extra memory for the `prev` pointer, making a DLL larger than an SLL with the same data.
* **More Complex Implementation:** Insertions and deletions are more complex because four pointers need to be updated (the `next` and `prev` of the adjacent nodes), which increases the risk of programming errors.

---

## Applications

The bidirectional nature of DLLs makes them perfect for a variety of applications:
* **Navigation Systems:** Used to implement the "back" and "forward" functionality in web browsers.
* **Undo/Redo Features:** Software like text editors and photo editors use DLLs to keep a history of user actions, allowing for easy undoing and redoing.
* **Implementing Deques:** A double-ended queue, which supports adding and removing elements from both ends, is a natural fit for a DLL.
* **Music and Video Playlists:** Enabling "previous track" and "next track" features.

---

## Time Complexity Summary ⏱️

| Operation | Best Case | Worst Case | Explanation |
| :--- | :--- | :--- | :--- |
| **Access (by position)** | `$O(1)` | `$O(n)` | `$O(1)` for head/tail, `$O(n)` for others. |
| **Search (by value)** | `$O(1)` | `$O(n)` | `$O(1)` if near an end, `$O(n)` if in the middle or absent. |
| **Insertion (Beginning/End)** | `$O(1)` | `$O(1)` | Always a constant time operation. |
| **Insertion (Middle)** | `$O(n)` | `$O(n)` | Requires traversal to find the position first. |
| **Deletion (Beginning/End)** | `$O(1)` | `$O(1)` | Always a constant time operation. |
| **Deletion (Middle)** | `$O(n)` | `$O(n)` | Requires traversal. However, if a pointer to the node is given, it is `$O(1)$`. |

---

## Important Additional Information

### The Key Advantage: O(1) Deletion with a Given Node

The most significant advantage of a DLL over an SLL is the ability to delete any node in constant time if you already have a pointer to it.

* **In a Singly Linked List (SLL):** If you are given a pointer `node_to_delete`, you can't delete it immediately. You first have to traverse from the `head` to find the node *before* it to update its `next` pointer. This takes `$O(n)` time.
* **In a Doubly Linked List (DLL):** If you are given `node_to_delete`, you can find its neighbors instantly:
    * The previous node is `node_to_delete.prev`.
    * The next node is `node_to_delete.next`.

    You can then update their pointers to bypass the current node (`prev_node.next = next_node` and `next_node.prev = prev_node`) all in `$O(1)` time. This efficiency is critical in many advanced algorithms and data structures.