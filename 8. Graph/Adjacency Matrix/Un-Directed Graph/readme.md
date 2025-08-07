# Undirected Graph using Adjacency Matrix

An **Adjacency Matrix** is a square, V x V grid used to represent an **undirected graph** with 'V' vertices. In an undirected graph, edges are bidirectional, meaning a connection from vertex `A` to `B` is identical to a connection from `B` to `A`.

This bidirectional nature gives the adjacency matrix for an undirected graph its most important characteristic: it is always **symmetric** across its main diagonal (from top-left to bottom-right).

**How it works:**
* A cell `matrix[i][j]` holds a value indicating the connection between vertex `i` and vertex `j`.
* For an **unweighted graph**, `matrix[i][j] = 1` if an edge exists and `0` otherwise.
* For a **weighted graph**, `matrix[i][j] = w` (the edge's weight) if an edge exists and `0` or `∞` otherwise.

**Example:**
Consider this simple undirected graph:



A --- B
|     |
C --- D

The corresponding adjacency matrix would be perfectly symmetric:

|         | **A** | **B** | **C** | **D** |
| :-----: | :---: | :---: | :---: | :---: |
| **A** |   0   |   1   |   1   |   0   |
| **B** |   1   |   0   |   0   |   1   |
| **C** |   1   |   0   |   0   |   1   |
| **D** |   0   |   1   |   1   |   0   |

---
## Operations and Algorithms

* ### **Add Edge**
    * **Description:** Creates a connection between vertex `u` and `v`.
    * **Algorithm:** Set `matrix[u][v] = 1` and `matrix[v][u] = 1`. For weighted graphs, use the weight instead of 1.

* ### **Remove Edge**
    * **Description:** Deletes the connection between vertex `u` and `v`.
    * **Algorithm:** Set `matrix[u][v] = 0` and `matrix[v][u] = 0`.

* ### **Check for Edge**
    * **Description:** Determines if an edge exists between `u` and `v`.
    * **Algorithm:** Simply check if `matrix[u][v] == 1`. This is a primary strength of the matrix representation.

* ### **Find Neighbors / Degree**
    * **Description:** Finds all vertices connected to `u`. The count of neighbors is the vertex's degree.
    * **Algorithm:** Iterate through the entire row `matrix[u]` from column 0 to V-1. If `matrix[u][j] == 1`, then `j` is a neighbor. The degree is the sum of all values in the row.

* ### Breadth-First Search (BFS)
    BFS explores a graph level by level, making it ideal for finding the shortest path in an unweighted graph.

    * **Description:** Starts at a source vertex and explores all of its immediate neighbors. Then, for each of those neighbors, it explores their unexplored neighbors, and so on.
    * **Data Structures:** A `queue` to hold vertices for the next visit and a `visited` set or array to avoid reprocessing nodes.
    * **Algorithm:**
        1.  Choose a `startVertex`.
        2.  Add `startVertex` to the `queue` and mark it as `visited`.
        3.  While the `queue` is not empty:
            * Dequeue a vertex, let's call it `current`.
            * Process `current` (e.g., print it).
            * For each `neighbor` in the adjacency list of `current`:
                * If the `neighbor` has **not** been visited:
                    * Mark the `neighbor` as `visited`.
                    * Enqueue the `neighbor`.

* ### Depth-First Search (DFS)
    DFS explores a graph by going as deep as possible down one path before backtracking. It's often used for pathfinding and cycle detection.

    * **Description:** Starts at a source vertex and explores as far as possible along each branch before backtracking. It's naturally implemented using recursion.
    * **Data Structures:** A `visited` set or array to track visited nodes. The call stack implicitly manages the traversal path.
    * **Algorithm (Recursive):**
        1.  Define a function `DFS(currentVertex, visited)`.
        2.  Mark `currentVertex` as `visited`.
        3.  Process `currentVertex`.
        4.  For each `neighbor` in the adjacency list of `currentVertex`:
            * If the `neighbor` has **not** been visited:
                * Recursively call `DFS(neighbor, visited)`.

* ### 3. Find All Paths
    This algorithm uses backtracking, a form of DFS, to find every possible simple path between a source and a destination.

    * **Description:** Explores every possible route from a `source` to a `destination` without visiting the same vertex twice in a single path.
    * **Data Structures:** A `visited` array to track nodes in the *current path* and a list to store the path itself.
    * **Algorithm (Recursive):**
        1.  Define a function `findAllPaths(source, destination, visited, path)`.
        2.  Mark `source` as `visited` and add it to the `path`.
        3.  If `source` equals `destination`, you've found a valid path. Print the current `path` and return.
        4.  For each `neighbor` in the adjacency list of `source`:
            * If the `neighbor` is **not** `visited`:
                * Recursively call `findAllPaths(neighbor, destination, visited, path)`.
        5.  **Backtrack:** After exploring all neighbors, remove `source` from the `path` and unmark it as `visited`. This is the most crucial step, as it allows the node to be part of other potential paths.

* ### Cycle Detection
    In an undirected graph, a cycle exists if a DFS traversal encounters an already visited vertex that is not its immediate parent.
    
    * **Description:** Traverses the graph while keeping track of the parent of each node in the traversal tree to distinguish between a legitimate back-edge (a cycle) and the edge back to the parent.
    * **Data Structures:** A `visited` set and a `parent` tracker for each recursive call.
    * **Algorithm (DFS-based):**
        1.  Define a function `isCycle(currentVertex, visited, parent)`.
        2.  Mark `currentVertex` as `visited`.
        3.  For each `neighbor` in the adjacency list of `currentVertex`:
            * If the `neighbor` is **not** `visited`:
                * Recursively call `isCycle(neighbor, visited, currentVertex)`. If this call returns `true`, it means a cycle was found, so propagate `true` up the call stack.
            * Else if the `neighbor` is **not** the `parent`:
                * This means the neighbor is already visited and isn't the node we just came from. You have found a back-edge, which confirms a cycle. Return `true`.
        4.  If the loop finishes without finding a cycle from this vertex, return `false`.

---
## Properties

* **Symmetry:** The matrix `A` is always equal to its transpose ($A = A^T$).
* **Diagonal:** The diagonal elements `A[i][i]` are typically 0, indicating no self-loops.
* **Vertex Degree:** The sum of the values in any row `i` (or column `i`) gives the degree of vertex `i`.
* **Walks of Length k:** This is a powerful property. The entry `(i, j)` in the matrix `A^k` (the matrix `A` multiplied by itself `k` times) gives the exact number of different walks of length `k` between vertex `i` and vertex `j`.

---
## Advantages 👍

* **Fast Edge Operations:** Checking for, adding, or removing an edge between two vertices is extremely fast, taking $O(1)$ time.
* **Good for Dense Graphs:** When a graph has many edges (approaching $V^2$), the matrix representation is space-efficient as there are few wasted '0' entries.
* **Simple Implementation:** The logic is straightforward to implement and debug.
* **Mathematical Manipulation:** Its structure is well-suited for algorithms that use linear algebra, like finding paths of a specific length.

---
## Disadvantages 👎

* **High Space Cost:** The $O(V^2)$ space complexity is very wasteful for **sparse graphs** (graphs with few edges), which are common in real-world applications.
* **Slow Neighbor Finding:** Iterating through all neighbors of a vertex takes $O(V)$ time, even if the vertex has only one or two neighbors.
* **Costly Vertex Operations:** Adding or removing a vertex is an expensive $O(V^2)$ operation, as it requires resizing and rebuilding the entire matrix.

---
## Application

The adjacency matrix is most practical in scenarios where:
* The number of vertices is **small and fixed**.
* The graph is **dense**.
* You perform **frequent edge lookups**.
* You need to leverage its mathematical properties, such as for network flow analysis or counting paths.

---
## Time Complexity

| Operation               | Time Complexity | Notes                                       |
| :---------------------- | :-------------- | :------------------------------------------ |
| **Space** | $O(V^2)$        | Main disadvantage for sparse graphs.        |
| **Add/Remove Edge** | $O(1)$          | A key advantage.                            |
| **Check for Edge** | $O(1)$          | A key advantage.                            |
| **Find Neighbors/Degree** | $O(V)$          | Must scan an entire row.                    |
| **BFS / DFS Traversal** | $O(V^2)$        | Each node visit requires an $O(V)$ scan.    |
| **Add/Remove Vertex** | $O(V^2)$        | Requires rebuilding the entire matrix.      |
