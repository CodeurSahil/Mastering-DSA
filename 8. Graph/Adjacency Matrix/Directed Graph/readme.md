## Directed Graph with an Adjacency Matrix

A **Directed Graph (Digraph)** is a graph where edges have a specific direction, representing a one-way relationship. When this is represented by an **Adjacency Matrix**, the `V x V` grid's structure directly reflects this directionality.

The key feature is that the matrix is **not necessarily symmetric**. An entry at `matrix[u][v] = 1` signifies a one-way edge `u → v`, but this does not imply an edge exists from `v` back to `u`.

Think of it like a "who follows whom" chart on a social media platform. A checkmark at the intersection of row "Alice" and column "Bob" means Alice follows Bob, but the reverse isn't automatically true.

**Example:**
Consider this simple directed graph:

A -> B
^    |
|    v
C <- B

The corresponding adjacency matrix is not symmetric:

|         | **A** | **B** | **C** |
| :-----: | :---: | :---: | :---: |
| **A** |   0   |   1   |   0   |
| **B** |   0   |   0   |   1   |
| **C** |   1   |   0   |   0   |

* `matrix[A][B]` is 1 because of the edge `A -> B`.
* However, `matrix[B][A]` is 0 because there is no edge `B -> A`.

***Note: Understand Flow via Code in `directedGraph.c`***

---

## How It Works

For a graph with `V` vertices (labeled 0 to V-1), the `V x V` matrix is populated as follows:

* **Unweighted Digraph:** `matrix[u][v] = 1` if an edge `u → v` exists, and `0` otherwise.
* **Weighted Digraph:** `matrix[u][v] = weight` if an edge `u → v` exists, and `0` or `infinity` otherwise.
* **Asymmetry:** The cell `matrix[u][v]` is independent of `matrix[v][u]`.

---

## Operations and Algorithms

### Basic Operations

* **Add Edge(u, v)**
    * **Goal:** Create a directed edge from vertex `u` to `v`.
    * **Algorithm:** Set `matrix[u][v] = 1` (or the `weight`). The cell `matrix[v][u]` remains unchanged.

* **Remove Edge(u, v)**
    * **Goal:** Delete the directed edge from `u` to `v`.
    * **Algorithm:** Set `matrix[u][v] = 0` (or `infinity`).

* **Check for Edge(u, v)**
    * **Goal:** Determine if a directed edge exists from `u` to `v`.
    * **Algorithm:** Return `true` if `matrix[u][v]` indicates an edge, otherwise `false`.

* **Find Outgoing Neighbors (Successors of `u`)**
    * **Goal:** Find all vertices that `u` has an edge *to*.
    * **Algorithm:** Iterate through the entire row `u`. If `matrix[u][j]` indicates an edge, then `j` is a successor.

* **Find Incoming Neighbors (Predecessors of `u`)**
    * **Goal:** Find all vertices that have an edge *to* `u`.
    * **Algorithm:** Iterate through the entire column `u`. If `matrix[j][u]` indicates an edge, then `j` is a predecessor.

### Graph Algorithms

* **Breadth-First Search (BFS)**
    * **Goal:** Explore neighbor nodes first, level by level, following edge directions.
    * **Algorithm:**
        1.  Create a `queue` and a `visited` array.
        2.  Add a `startVertex` to the queue and mark it as visited.
        3.  While the queue is not empty:
            * Dequeue a vertex `u`. Process it.
            * Iterate through row `u` (from `v = 0` to `V-1`). If `matrix[u][v]` shows an edge and `v` has not been visited, mark `v` as visited and enqueue it.

* **Depth-First Search (DFS)**
    * **Goal:** Explore as far as possible down each directed path before backtracking.
    * **Algorithm (Recursive):**
        1.  Mark the `currentVertex` as visited and process it.
        2.  Iterate through the row for `currentVertex` (from `v = 0` to `V-1`).
        3.  If `matrix[currentVertex][v]` shows an edge and `v` has not been visited, recursively call DFS on `v`.

* **Cycle Detection**
    * **Goal:** Determine if the digraph contains a directed cycle.
    * **Algorithm (DFS-based):**
        1.  Perform a DFS traversal. Maintain two boolean arrays: `visited` (for the overall traversal) and `recursionStack` (for the current path).
        2.  When visiting a node `u`, mark it as true in both `visited` and `recursionStack`.
        3.  For each neighbor `v` of `u`:
            * If `v` is already in the `recursionStack`, a back edge has been found, and a cycle exists.
            * If `v` is not visited, recursively call the cycle detection on `v`.
        4.  Before returning, remove `u` from the `recursionStack` (backtracking).

---

## Key Properties

* **Asymmetry:** The matrix `A` is generally not equal to its transpose (`$A \neq A^T$`).
* **Out-Degree:** The sum of all values in a **row `i`** gives the out-degree of vertex `i`.
* **In-Degree:** The sum of all values in a **column `j`** gives the in-degree of vertex `j`.
* **Transpose Graph:** The graph with all edge directions reversed can be found by simply taking the transpose of the adjacency matrix (`$A^T$`).

---

## Advantages 👍

* **Extremely Fast Edge Lookup:** Checking for an edge `u → v` is an `$O(1)` operation.
* **Simple Structure:** The representation is easy to implement, especially for dense graphs.
* **Easy Degree Calculation:** Finding the in-degree and out-degree is straightforward by summing a column or row, respectively.

---

## Disadvantages 👎

* **High Space Cost:** The `$O(V^2)` space complexity is highly inefficient for **sparse graphs**.
* **Slow Neighbor Finding:** Finding all outgoing or incoming neighbors always takes `$O(V)` time, which is slow for sparse graphs.
* **Costly Vertex Operations:** Adding or removing a vertex requires rebuilding the entire matrix, an expensive `$O(V^2)` operation.

---

## Applications

The adjacency matrix for a directed graph is most useful when the graph is **dense** or the number of vertices is small.

* **State Machines and Markov Chains:** The transition matrix is a natural fit for this representation.
* **Dependency Analysis:** Useful when you need to frequently and quickly check for direct dependencies between a pair of items.
* **PageRank Algorithm:** The conceptual model of the web graph for this algorithm is a massive adjacency matrix.

---

## Time Complexity Summary

Let `V` be the number of vertices.

| Operation                 | Time Complexity |
| :------------------------ | :-------------: |
| **Space Complexity** |   `$O(V^2)`   |
| **Add/Remove Edge** |     `$O(1)`     |
| **Check Adjacency (u → v)**|     `$O(1)`     |
| **Find In/Out-Degree** |     `$O(V)`     |
| **Find Neighbors** |     `$O(V)`     |
| **Add/Remove Vertex** |   `$O(V^2)`   |
| **Graph Traversal (BFS/DFS)**|   `$O(V^2)`   |