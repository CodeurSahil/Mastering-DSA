# Directed Graph using Adjacency Matrix

A **Directed Graph**, or **Digraph**, is a graph where edges have a specific direction, representing a one-way relationship. When represented by an **Adjacency Matrix**, a V x V grid, this directionality is key.

Unlike an undirected graph, the matrix for a directed graph is **not necessarily symmetric**. An entry `matrix[u][v] = 1` signifies an edge from `u` to `v`, but this does not imply an edge from `v` to `u`.

**How it works:**
* A cell `matrix[u][v]` indicates if there's a directed edge from the row vertex `u` to the column vertex `v`.
* For an **unweighted digraph**, `matrix[u][v] = 1` if an edge `u -> v` exists, and `0` otherwise.
* For a **weighted digraph**, `matrix[u][v] = w` (the edge's weight) if an edge `u -> v` exists.

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

---
## Operations and Algorithms

* ### **Add Edge**
    * **Description:** Creates a directed edge from vertex `u` to `v`.
    * **Algorithm:** Set `matrix[u][v] = 1` (or the weight). The cell `matrix[v][u]` is not changed.

* ### **Remove Edge**
    * **Description:** Deletes the directed edge from `u` to `v`.
    * **Algorithm:** Set `matrix[u][v] = 0`.

* ### **Check for Edge**
    * **Description:** Determines if a directed edge exists from `u` to `v`.
    * **Algorithm:** Check if `matrix[u][v] == 1`.

* ### **Find Outgoing Neighbors (Successors)**
    * **Description:** Finds all vertices that `u` has an edge *to*.
    * **Algorithm:** Iterate through the row `matrix[u]`. If `matrix[u][j] == 1`, then `j` is a successor.

* ### **Find Incoming Neighbors (Predecessors)**
    * **Description:** Finds all vertices that have an edge *to* `u`.
    * **Algorithm:** Iterate through the column `matrix[][u]`. If `matrix[j][u] == 1`, then `j` is a predecessor.

* ### Breadth-First Search (BFS)
    BFS explores the graph layer by layer, starting from a source vertex.   

    * **Description:** Visits all neighbors of a node before moving on to the neighbors' neighbors.
    * **Data Structures:** A `queue` to manage nodes to visit and a `visited` array.
    * **Algorithm:**
        1.  Choose a `startVertex`. Add it to the `queue` and mark `visited[startVertex] = true`.
        2.  While the `queue` is not empty:
            * Dequeue a vertex, `current`.
            * Process `current`.
            * **Find Neighbors:** Iterate through the row for `current` (from `j = 0` to `V-1`):
                * If `matrix[current][j] == 1` and `visited[j]` is `false`:
                    * Mark `visited[j] = true`.
                    * Enqueue `j`.

* ### Depth-First Search (DFS)
    DFS explores as far as possible down each branch before backtracking.

    * **Description:** Uses recursion (or a stack) to go deep into the graph's paths.
    * **Data Structures:** A `visited` array and the system's call stack for recursion.
    * **Algorithm (Recursive):**
        1.  Define a function `DFS(currentVertex, visited)`.
        2.  Mark `visited[currentVertex] = true` and process the node.
        3.  **Find Neighbors:** Iterate through the row for `currentVertex` (from `j = 0` to `V-1`):
            * If `matrix[currentVertex][j] == 1` and `visited[j]` is `false`:
                * Recursively call `DFS(j, visited)`.

* ### Find All Paths
    This algorithm uses backtracking (a form of DFS) to find all possible paths from a `source` to a `destination`.

    * **Description:** Explores every possible route from `source` to `destination` without repeating vertices in a single path.
    * **Data Structures:** A `visited` array and a list to store the `currentPath`.
    * **Algorithm (Recursive):**
        1.  Define `findAllPaths(u, destination, visited, path)`.
        2.  Mark `visited[u] = true` and add `u` to the `path`.
        3.  If `u` is the `destination`, print the `path`.
        4.  Else, iterate through `u`'s row (from `j = 0` to `V-1`):
            * If `matrix[u][j] == 1` and `visited[j]` is `false`:
                * Recursively call `findAllPaths(j, destination, visited, path)`.
        5.  **Backtrack:** Remove `u` from the `path` and set `visited[u] = false`. This is the crucial step that allows the node to be used in other paths.

* ### Cycle Detection
    A cycle in a directed graph is found by identifying a "back edge" during DFS, which is an edge leading to a node currently in the recursion stack.
    
    * **Description:** Uses a modified DFS to track the nodes being explored in the current path.
    * **Data Structures:**
        * `visited[]`: Tracks nodes visited in the entire traversal.
        * `recursionStack[]`: Tracks nodes in the *current* recursion path.
    * **Algorithm (DFS-based):**
        1.  Define `isCycle(u, visited, recursionStack)`.
        2.  Mark `visited[u] = true` and `recursionStack[u] = true`.
        3.  Iterate through `u`'s row (from `j = 0` to `V-1`):
            * If `matrix[u][j] == 1`:
                * If `visited[j]` is `false` and a recursive call `isCycle(j, visited, recursionStack)` returns `true`, then a cycle is found. Return `true`.
                * Else if `recursionStack[j]` is `true`, you've found a back edge to a node in the current path. A cycle exists. Return `true`.
        4.  **Backtrack:** Set `recursionStack[u] = false` before the function returns.
        5.  Return `false` if no cycles were found from this vertex.

---
## Properties

* **Asymmetry:** The matrix `A` is generally not equal to its transpose ($A \neq A^T$).
* **Out-Degree:** The sum of all values in a **row `i`** gives the out-degree of vertex `i` (the number of edges leaving it).
* **In-Degree:** The sum of all values in a **column `j`** gives the in-degree of vertex `j` (the number of edges entering it).
* **Walks of Length k:** The entry `(i, j)` in the matrix `A^k` gives the number of different directed walks of length `k` from vertex `i` to `j`.
* **Transpose Graph ($G^T$):** The graph with all edge directions reversed can be found by simply taking the transpose of the adjacency matrix ($A^T$). This is useful in algorithms like Kosaraju's for finding strongly connected components.

---
## Advantages 👍

* **Fast Edge Lookup:** Checking for an edge `u -> v` is a very fast $O(1)$ operation.
* **Simple Structure:** The representation is simple, especially for dense graphs where the number of edges is high.
* **Degree Calculation:** Calculating in-degree and out-degree is straightforward by summing a column or row.
* **Good for Linear Algebra:** Its structure is ideal for algorithms leveraging matrix operations.

---
## Disadvantages 👎

* **High Space Cost:** The $O(V^2)$ space complexity is highly inefficient for **sparse graphs**.
* **Slow Neighbor Finding:** Finding all successors (or predecessors) always takes $O(V)$ time, regardless of the actual out-degree (or in-degree).
* **Costly Vertex Operations:** Adding or removing a vertex requires rebuilding the entire matrix, an $O(V^2)$ operation.

---
## Application

The adjacency matrix for a directed graph is most useful when:
* The graph is **dense** or the number of vertices is small.
* You need to perform **frequent edge lookups**.
* Analyzing state transitions, such as in **Finite Automata** or **Markov Chains**.
* Modeling dependencies, like in a task graph for a build system or in a compiler.
* Implementing algorithms like **PageRank**, which models the web as a massive directed graph.

---
## Time Complexity

| Operation                       | Time Complexity | Notes                                       |
| :------------------------------ | :-------------- | :------------------------------------------ |
| **Space** | $O(V^2)$        | Main disadvantage for sparse graphs.        |
| **Add/Remove Edge** | $O(1)$          | A key advantage.                            |
| **Check for Edge** | $O(1)$          | A key advantage.                            |
| **Find Out-degree / In-degree** | $O(V)$          | Must scan an entire row/column.             |
| **BFS / DFS Traversal** | $O(V^2)$        | Each node visit requires an $O(V)$ scan.    |
| **Add/Remove Vertex** | $O(V^2)$        | Requires rebuilding the entire matrix.      |
