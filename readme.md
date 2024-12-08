# My Mastering DSA Journey

#### GPT Link - https://chatgpt.com/share/67284d13-f970-800e-bf2e-58a16971730a

> **Data Structures** is a way to organise and store data in a computer system so that it can be accessed, processed, and retrieved quickly and efficiently for various uses.
> - They provide a structured way to arrange data so that algorithms can work efficiently, which is especially important for large or complex data sets. 
> - They are a fundamental concept in computer science and are essential for solving various computational problems effectively.

### Types of Data Structures:-
1. **Primitive Data Structures**
    - **Integers, Floats, Characters, Booleans**: These are the basic types that store single pieces of data, like a number or a letter. They’re the building blocks for more complex structures.
2. **Non-Primitive Data Structures**
    - These data structures can store multiple values and are generally more complex. They can be further divided into two main categories: **Linear and Non-Linear Data Structures**.

## Linear Data Structures
	- In LDS, Data Elements are arranged in Linear Order i.e. in single line, where each and every elements are attached to its previous & next adjacent element 
    - Single level is Involved 
    - Easy Implementation 
    - Data Elements can be traversed in single run 
    - Memory is utilised efficiently 

### Types of **Linear Data Structures**
1. **Array** - Fixed-size, sequential collection of elements.
	Can be Accessed by index, making them efficient for random access.
    ![Repesentaion of Array](/assets/representationOfArray.png)
2. **Linked List** - A Linked List is a linear data structure where elements, called nodes, are linked using pointers i.e. address to the next node. Each node consists of:
    ```
    Repesentation of Linked List
     ------------------          --------------------  
    |  Data  | Pointer |  --->  |  Data2  | Pointer2 |  
     ------------------          --------------------     
     Pointer - Consist Address of Data 2 Block 
     Pointer2 - It Null states no nodes ahead
    ```
    - Data: The value or information stored in the node.
    - Pointer (or Reference): A reference to the next node in the sequence.


        **Key Operations**

        1. Traversal
            - Traversal means visiting every node of a LL.
            - In Singly LL, wwe traverse using the next pointer, starting from the head.
            - In Double LL, we can traverse in both forward and backward directions.
            - Complexity: O(n)

        2. Insertion
            - Insertion can be beginning, end, or any specific position.
            - In DLL, both prev and next pointers need to be updated.
            - Complexity:
                - At the beginning: O(1)
                - At the end or specific position: O(n)
        3. Deletion
            - Removal of a node from the beginning, end, or a specific position.
            - Complexity:
                - At the beginning: O(1)
                - At the end or specific position: O(n)
        4. Search
            - Search for an element in the list by traversing.
            - Complexity: O(n)

        **Advantages**
        1. **Dynamic Size:** No need to predefine the size of the list; it grows and shrinks dynamically.
        2. **Efficient Insertions/Deletions:** Especially useful for operations where the size or position of data frequently changes.
        3. **No Memory Waste:** Unlike arrays, there’s no need for contiguous memory allocation.

        **Disadvantages**
        1. **Sequential Access:** To access a node, you must traverse from the head (or tail in DLL).
        2. **Higher Memory Overhead:** Additional memory is required for storing pointers.
        3. **Complexity:** More complex to implement and manage compared to arrays.

        **Applications of Linked Lists**
        1. **Dynamic Memory Allocation:** Used in operating systems.
        2. **Implementation of Data Structures:** Stacks, queues, and graphs.
        3. **Navigation Systems:** Used in undo/redo functionality.
        4. **Polynomial Representation:** Representing and manipulating polynomials.

