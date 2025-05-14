# Red-Black Tree

A Red-Black Tree is a self-balancing Binary Search Tree (BST) where each node has an extra bit of information representing its color, either red or black. This coloring helps ensure that the tree remains balanced during insertions and deletions, maintaining efficient search, insertion, and deletion operations with a time complexity of $O(\log n)$, where $n$ is the number of nodes in the tree.

## Properties of a Red-Black Tree

A Red-Black Tree must satisfy the following properties:

1.  **Node Color:** Each node is either red or black.
2.  **Root Property:** The root of the tree is always black.
3.  **Leaf Property:** All leaves (NIL or null nodes) are considered black.
4.  **Red Property:** If a node is red, then both its children must be black. This implies that there are no two adjacent red nodes on any path.
5.  **Black Property:** Every simple path from a node to any of its descendant leaf nodes contains the same number of black nodes. This number is called the black-height of the node.

These properties collectively enforce a crucial invariant: the path from the root to the farthest leaf is no more than twice as long as the path from the root to the nearest leaf. This ensures that the tree remains reasonably balanced.

## Basic Structure of a Red-Black Tree Node

A typical node in a Red-Black Tree contains the following attributes:

* `key`: The value stored in the node.
* `color`: Either red or black.
* `left`: A pointer to the left child.
* `right`: A pointer to the right child.
* `parent`: A pointer to the parent node.

## Operations on a Red-Black Tree

The primary operations performed on a Red-Black Tree are:

### 1. Insertion

The insertion operation in a Red-Black Tree involves the following steps:

1.  **Standard BST Insertion:** Insert the new node using the standard Binary Search Tree insertion procedure.
2.  **Coloring:** Color the newly inserted node red.
3.  **Restoring Properties:** If the parent of the new node is black, no Red-Black properties are violated. However, if the parent is red, it might violate the red property (no two adjacent red nodes). To fix this, we use a series of recoloring and rotation operations.

    There are several cases to consider during the fix-up process after insertion, based on the color of the new node's parent and uncle (parent's sibling). These cases involve recoloring nodes and performing left or right rotations to maintain the Red-Black properties.

### 2. Deletion

The deletion operation is more complex than insertion and involves these steps:

1.  **Standard BST Deletion:** Perform the standard Binary Search Tree deletion to remove the node.
2.  **Restoring Properties:** If the deleted node was red, the Red-Black properties are preserved. However, if the deleted node was black, it might violate the black property (paths might have fewer black nodes). To restore the properties, we again use recoloring and rotation operations.

    The fix-up process after deletion involves several cases based on the color of the deleted node's sibling and the sibling's children. These cases aim to redistribute black nodes and perform rotations to ensure that all paths from the root to the leaves have the same number of black nodes. The concept of a "double-black" node is often used to handle the temporary violation of the black property.

### 3. Searching

The search operation in a Red-Black Tree is identical to searching in a standard Binary Search Tree. Starting from the root, we compare the target value with the current node's key and move to the left child if the target is smaller, or to the right child if it's larger. We continue this process until the target value is found or a leaf node (NIL) is reached. The time complexity for searching is $O(\log n)$ because the tree is balanced.

## Rotations

Rotations are fundamental operations used in Red-Black Trees to change the tree's structure while maintaining the BST property. There are two types of rotations:

* **Left Rotation:** A left rotation on a node `x` pivots around the edge from `x` to its right child `y`. It makes `y` the new root of the subtree and `x` the left child of `y`. The left child of `y` becomes the right child of `x`.

    ```
        x                 y
       / \               / \
      α   y      =>     x   γ
         / \           / \
        β   γ         α   β
    ```

* **Right Rotation:** A right rotation on a node `y` pivots around the edge from `y` to its left child `x`. It makes `x` the new root of the subtree and `y` the right child of `x`. The right child of `x` becomes the left child of `y`.

    ```
          y                 x
         / \               / \
        x   γ      =>     α   y
       / \                   / \
      α   β                 β   γ
    ```

These rotations, along with recoloring, are crucial for maintaining the balance of the Red-Black Tree after insertion and deletion operations.

## Applications of Red-Black Trees

Red-Black Trees are widely used in various applications due to their guaranteed logarithmic time complexity for essential operations:

* **Implementation of ordered data structures:** Many standard library implementations of sets and maps (e.g., `std::set`, `std::map` in C++, `java.util.TreeSet`, `java.util.TreeMap` in Java) use Red-Black Trees.
* **Kernel data structures:** Linux kernel uses Red-Black Trees for managing virtual memory areas, scheduling tasks, etc.
* **Database systems:** Some database systems use Red-Black Trees for indexing.
* **Computational geometry:** Used in algorithms for tasks like finding intersections.

## Advantages and Disadvantages

**Advantages:**

* **Guaranteed logarithmic time complexity:** Search, insertion, and deletion operations have a worst-case time complexity of $O(\log n)$.
* **Relatively efficient for both insertion and deletion:** Compared to other balanced trees like AVL trees, Red-Black Trees might involve fewer rotations during insertions and deletions, making them more efficient in scenarios with frequent modifications.

**Disadvantages:**

* **More complex implementation:** The logic for insertion and deletion, especially the fix-up process, is more intricate than that of a standard Binary Search Tree.
* **Slightly less balanced than AVL trees:** Red-Black Trees maintain a looser balance compared to AVL trees, which might result in slightly higher trees in some cases, potentially leading to slower searches in those specific scenarios (though still $O(\log n)$).

## Conclusion

Red-Black Trees are a valuable data structure that provides a good balance between search efficiency and the cost of maintaining balance during modifications. Their logarithmic time complexity for fundamental operations makes them suitable for a wide range of applications where efficient management of ordered data is required.