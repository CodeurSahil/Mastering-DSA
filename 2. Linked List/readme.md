## Linked Lists: A Chain of Data ⛓️

A **Linked List** is a fundamental linear data structure. Unlike an array, its elements aren't stored in contiguous memory locations. Instead, it's made up of individual objects called **nodes** that are "linked" together to form a sequence.

`Think of it like a treasure hunt: each clue (**node**) contains a piece of information (**data**) and tells you where to find the next clue (**pointer**).`

Each node consists of two main parts:
1.  **Data**: The actual value stored in the node (e.g., a number, a string).
2.  **Pointer (or Next)**: A reference that points to the memory address of the next node in the chain. The last node's pointer is typically set to `NULL` to signify the end of the list.

```
    Repesentation of Linked List
     ------------------          --------------------  
    |  Data  | Pointer |  --->  |  Data2  | Pointer2 |  
     ------------------          --------------------     
     Pointer - Consist Address of Data 2 Block 
     Pointer2 - It Null states no nodes ahead
```

---

## Types of Linked Lists

There are three primary types of linked lists, each with different pointer arrangements.

* **[Singly Linked List](Singly%20Linked%20List/readme.md):** This is the simplest type. Each node has only one pointer that points to the **next** node in the sequence. You can only traverse it in one direction (forward).
* **[Doubly Linked List (DLL)](Double%20Linked%20List/readme.md):** Each node has two pointers: one pointing to the **next** node and another pointing to the **previous** node. This allows for traversal in both forward and backward directions.
* **[Circular Linked List](Circular%20Linked%20List/readme.md):** A variation where the last node's pointer, instead of being `NULL`, points back to the **first node (head)**, forming a circle.

---

## Core Operations

Here are the key operations for a linked list and their typical time complexities.

* **Search**
    * **Goal:** Find a node with a specific data value.
    * **Process:** You must start at the head and check each node one by one.
    * **Complexity:** `$O(n)$` because in the worst case, you might have to visit every node.

* **Insertion**
    * **Goal:** Add a new node to the list.
    * **At the Beginning:** Extremely fast. You just create a new node and make its pointer point to the current head, then update the head to be the new node. **Complexity: `$O(1)$`**.
    * **At the End or a Specific Position:** You first have to traverse the list to find the correct position, which takes time. **Complexity: `$O(n)$`**.

* **Deletion**
    * **Goal:** Remove a node from the list.
    * **At the Beginning:** Also very fast. You just make the head pointer point to the second node in the list. **Complexity: `$O(1)$`**.
    * **At the End or a Specific Position:** Similar to insertion, you must first search for the node you want to delete. **Complexity: `$O(n)$`**.

* **Traversal**
    * **Goal:** Visit every node in the list in order.
    * **Process:** Start at the head and follow the `next` pointers until you reach `NULL`.
    * **Complexity:** `$O(n)$`.

---

## Advantages ✅

* **Dynamic Size:** Linked lists can grow and shrink during program execution. You don't need to specify their size beforehand.
* **Efficient Insertion/Deletion:** Adding or removing nodes from the beginning of the list is incredibly fast ($O(1)$). Unlike arrays, no elements need to be shifted.
* **Memory Flexibility:** Nodes can be stored anywhere in memory; they don't need a single, contiguous block. This can be a huge advantage when memory is fragmented.

---

## Disadvantages ❌

* **No Random Access:** You cannot directly access an element by its index like you can with an array (`my_array[5]`). To get to the 5th element, you must traverse through the first 4. This makes access time slow ($O(n)$).
* **Higher Memory Usage:** Each node requires extra memory to store its pointer(s), which means a linked list can take up more space than an array holding the same data.
* **Slower Traversal:** Even though traversal is `$O(n)` like in an array, it can be practically slower because nodes might be scattered in memory, leading to poor cache performance.

---

## Applications

Linked lists are the backbone for many other structures and features, including:
* **Implementing Stacks and Queues:** They are a natural fit for these "first-in, last-out" or "first-in, first-out" structures.
* **Music Player Playlists:** The "next" and "previous" song functionality is a perfect use case for a doubly linked list.
* **Web Browser History:** The "back" and "forward" buttons in a browser use a similar mechanism.
* **Undo/Redo Functionality:** In applications like text editors, each action can be stored as a node in a list.
* **Operating Systems:** Managing dynamic memory allocation and task scheduling.