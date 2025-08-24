## Graph Representation: The Adjacency Matrix 🔳

An **Adjacency Matrix** is a straightforward way to represent a graph using a **V x V square matrix**, where `V` is the number of vertices. The core idea is that the cell at the intersection of a row and column, `matrix[i][j]`, indicates whether an edge exists between vertex `i` and vertex `j`.

Think of it like a mileage chart between cities. To find the distance between City A and City B, you find the row for A, the column for B, and the cell where they intersect tells you the distance (or simply if a direct road exists).

#### Example:
Consider this undirected graph:
```
A --- B
|  \  /
|   \/
C -- D
```

---

## How It Works

For a graph with `V` vertices (typically labeled 0 to V-1), the `V x V` matrix is populated based on the type of graph.

* **Unweighted Graph:** `matrix[i][j] = 1` if an edge exists from `i` to `j`, and `0` otherwise.
* **Weighted Graph:** `matrix[i][j] = weight` if an edge exists. An empty cell is represented by `0` or `infinity` (using infinity is often safer to avoid confusion with a zero-weight edge).
* **[Undirected Graph](Un-Directed%20Graph/readme.md):** The matrix is always **symmetric**. An edge between `i` and `j` means `matrix[i][j] = 1` and `matrix[j][i] = 1`.
* **[Directed Graph](Directed%20Graph/readme.md):** The matrix is **not necessarily symmetric**. An edge `i → j` means `matrix[i][j] = 1`, but `matrix[j][i]` can be `0`.

---

## Operations and Algorithms

### Basic Operations

* **Add Edge(u, v)**
    * **Goal:** Create a connection between two vertices.
    * **Algorithm:**
        1.  Set `matrix[u][v] = 1` (or the edge `weight`).
        2.  If the graph is undirected, also set `matrix[v][u] = 1`.

* **Remove Edge(u, v)**
    * **Goal:** Delete the connection between two vertices.
    * **Algorithm:**
        1.  Set `matrix[u][v] = 0` (or `infinity`).
        2.  If the graph is undirected, also set `matrix[v][u] = 0`.

* **Check for Edge (isAdjacent)**
    * **Goal:** Determine if a direct edge exists between two vertices.
    * **Algorithm:** Return `true` if `matrix[u][v]` is not 0 (or not infinity), otherwise return `false`.

* **Find Neighbors(v)**
    * **Goal:** Get a list of all vertices directly connected to a given vertex `v`.
    * **Algorithm:**
        1.  Initialize an empty list for the neighbors.
        2.  Iterate through the entire row `v` of the matrix (from column `j = 0` to `V-1`).
        3.  If `matrix[v][j]` indicates an edge, add `j` to the neighbors list.
        4.  Return the list.

### Graph Traversal Algorithms

* **Breadth-First Search (BFS)**
    * **Goal:** Explore neighbor nodes first, level by level, starting from a given vertex.
    * **Algorithm:**
        1.  Create a `queue` and a `visited` array.
        2.  Add the `startVertex` to the queue and mark it as visited.
        3.  While the queue is not empty:
            * Dequeue a vertex `u`. Process it.
            * Iterate from `v = 0` to `V-1`. If `matrix[u][v]` shows an edge and `v` has not been visited, mark `v` as visited and enqueue it.

* **Depth-First Search (DFS)**
    * **Goal:** Explore as far as possible down each branch before backtracking.
    * **Algorithm (Recursive):**
        1.  Mark the `currentVertex` as visited and process it.
        2.  Iterate from `v = 0` to `V-1`.
        3.  If `matrix[currentVertex][v]` shows an edge and `v` has not been visited, recursively call DFS on `v`.

---

## Key Properties

* **Matrix Representation:** The graph is stored as a `V x V` grid.
* **Space Complexity:** Always uses `$O(V^2)` space, regardless of the number of edges.
* **Symmetry:** For undirected graphs, the matrix is symmetric across its main diagonal.
* **Fast Edge Lookup:** The defining property is the ability to check for an edge in constant time.

---

## Advantages 👍

* **Extremely Fast Edge Lookup:** Checking for the existence of an edge between any two vertices is an `$O(1)` operation. This is its single biggest advantage.
* **Simple Implementation:** The logic is straightforward and easy to code.
* **Good for Dense Graphs:** For graphs with a large number of edges (where the number of edges `E` is close to `V^2`), the space is used efficiently.

---

## Disadvantages 👎

* **High Space Consumption:** The `$O(V^2)` space requirement is the primary drawback. It is extremely wasteful for **sparse graphs** (graphs with few edges), which are very common in the real world.
* **Slow to Iterate Over Neighbors:** Finding all neighbors of a vertex always takes `$O(V)` time, even if the vertex has only one neighbor.
* **Slow to Add/Remove Vertices:** Adding or removing a vertex requires creating a new, larger (or smaller) matrix and copying all existing edge information, an expensive `$O(V^2)` operation.

---

## Applications

The adjacency matrix is best suited for **small or dense graphs** where the number of vertices is manageable and fast edge lookups are a priority.

* **Dense Graphs:** When the number of edges is a significant fraction of the maximum possible.
* **Algorithms Requiring Frequent Edge Checks:** Can be beneficial for algorithms that repeatedly query the existence of edges between pairs of vertices.
* **Educational Purposes:** Often used to introduce graph representations due to its simplicity.

---

## Time Complexity Summary

Let `V` be the number of vertices.

| Operation                 | Time Complexity |
| :------------------------ | :-------------: |
| **Space Complexity** |   `$O(V^2)`   |
| **Add Edge** |     `$O(1)`     |
| **Remove Edge** |     `$O(1)`     |
| **Check Adjacency** |     `$O(1)`     |
| **Find Neighbors** |     `$O(V)`     |
| **Add/Remove Vertex** |   `$O(V^2)`   |
| **Graph Traversal (BFS/DFS)**|   `$O(V^2)`   |