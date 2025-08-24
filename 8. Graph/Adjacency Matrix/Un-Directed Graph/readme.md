## Undirected Graph with an Adjacency Matrix

An **Adjacency Matrix** is a `V x V` square grid used to represent an **undirected graph** with `V` vertices. In an undirected graph, edges are bidirectional, meaning a connection from vertex `A` to `B` is identical to a connection from `B` to `A`.

This bidirectional nature gives the adjacency matrix for an undirected graph its most important characteristic: it is always **symmetric** across its main diagonal (from top-left to bottom-right).

**How it works:**

  * A cell `matrix[i][j]` holds a value indicating the connection between vertex `i` and `j`.
  * For an **unweighted graph**, `matrix[i][j] = 1` if an edge exists and `0` otherwise.
  * For a **weighted graph**, `matrix[i][j] = w` (the edge's weight).

**Example:**
Consider this simple undirected graph:

```
A --- B
|     |
C --- D
```

The corresponding adjacency matrix would be perfectly symmetric:

|         | **A** | **B** | **C** | **D** |
| :-----: | :---: | :---: | :---: | :---: |
| **A** |   0   |   1   |   1   |   0   |
| **B** |   1   |   0   |   0   |   1   |
| **C** |   1   |   0   |   0   |   1   |
| **D** |   0   |   1   |   1   |   0   |

***Note: Understand Flow via Code in `unDirectedGraph.c`***

-----

## Operations and Algorithms

### Basic Operations

  * **Add Edge(u, v)**

      * **Goal:** Create a connection between vertex `u` and `v`.
      * **Algorithm:** Set `matrix[u][v] = 1` and `matrix[v][u] = 1`. For weighted graphs, use the weight instead of 1.

  * **Remove Edge(u, v)**

      * **Goal:** Delete the connection between vertex `u` and `v`.
      * **Algorithm:** Set `matrix[u][v] = 0` and `matrix[v][u] = 0`.

  * **Check for Edge(u, v)**

      * **Goal:** Determine if an edge exists between `u` and `v`.
      * **Algorithm:** Simply check if `matrix[u][v]` is not 0. This is a primary strength of the matrix representation.

  * **Find Neighbors(u)**

      * **Goal:** Find all vertices connected to `u`.
      * **Algorithm:** Iterate through the entire row `matrix[u]`. If `matrix[u][j]` is not 0, then `j` is a neighbor.

### Graph Traversal and Pathfinding

  * **Breadth-First Search (BFS)**

      * **Goal:** Explore a graph level by level, finding the shortest path in an unweighted graph.
      * **Algorithm:**
        1.  Create a `queue` and a `visited` array.
        2.  Add a `startVertex` to the queue and mark it as visited.
        3.  While the queue is not empty:
              * Dequeue a vertex `u`. Process it.
              * Iterate through row `u` (from `v = 0` to `V-1`). If `matrix[u][v]` shows an edge and `v` has not been visited, mark `v` as visited and enqueue it.

  * **Depth-First Search (DFS)**

      * **Goal:** Explore as far as possible down each branch before backtracking.
      * **Algorithm (Recursive):**
        1.  Mark the `currentVertex` as visited and process it.
        2.  Iterate through the row for `currentVertex` (from `v = 0` to `V-1`).
        3.  If `matrix[currentVertex][v]` shows an edge and `v` has not been visited, recursively call DFS on `v`.

  * **Cycle Detection**

      * **Goal:** Determine if the undirected graph contains a cycle.
      * **Algorithm (DFS-based):**
        1.  Perform a DFS traversal, keeping track of visited nodes and the `parent` of each node in the traversal path.
        2.  For the current vertex `u`, when exploring its neighbor `v`:
        3.  If `v` has been visited and `v` is **not** the immediate `parent` of `u`, a "back edge" has been found, which confirms a cycle.

-----

## Key Properties

  * **Symmetry:** The matrix `A` is always equal to its transpose (`$A = A^T$`).
  * **Vertex Degree:** The sum of the values in any row `i` (or column `i`) gives the degree of vertex `i`.
  * **Walks of Length k:** A powerful property where the entry `(i, j)` in the matrix `A^k` (the matrix `A` multiplied by itself `k` times) gives the number of different paths of length `k` between vertex `i` and `j`.

-----

## Advantages 👍

  * **Fast Edge Operations:** Checking for, adding, or removing an edge between two vertices is extremely fast, taking `$O(1)` time.
  * **Good for Dense Graphs:** When a graph has many edges, the matrix representation is space-efficient as there are few wasted '0' entries.
  * **Simple Implementation:** The logic is straightforward to implement and debug.
  * **Mathematical Manipulation:** Its structure is well-suited for algorithms that use linear algebra.

-----

## Disadvantages 👎

  * **High Space Cost:** The `$O(V^2)` space complexity is very wasteful for **sparse graphs** (graphs with few edges), which are common in real-world applications.
  * **Slow Neighbor Finding:** Iterating through all neighbors of a vertex takes `$O(V)` time, even if the vertex has only one or two neighbors.
  * **Costly Vertex Operations:** Adding or removing a vertex is an expensive `$O(V^2)` operation, as it requires resizing and rebuilding the entire matrix.

-----

## Applications

The adjacency matrix is most practical in scenarios where:

  * The number of vertices is **small and fixed**.
  * The graph is **dense**.
  * You perform **frequent edge lookups**.
  * You need to leverage its mathematical properties, such as for network flow analysis or counting paths.

-----

## Time Complexity Summary

| Operation               | Time Complexity |
| :---------------------- | :-------------: |
| **Space Complexity** |   `$O(V^2)`   |
| **Add/Remove Edge** |     `$O(1)`     |
| **Check for Edge** |     `$O(1)`     |
| **Find Neighbors/Degree** |     `$O(V)`     |
| **Traversal (BFS / DFS)**|   `$O(V^2)`   |
| **Add/Remove Vertex** |   `$O(V^2)`   |