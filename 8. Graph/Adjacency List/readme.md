## Adjacency Matrix: Representing Graphs with a Grid 🔳

An **Adjacency Matrix** is a straightforward way to represent a graph using a **2D array** (a matrix) of size `V x V`, where `V` is the number of vertices in the graph.

The core idea is simple: the cell at `matrix[i][j]` stores information about the edge between vertex `i` and vertex `j`. This method is easy to understand and provides extremely fast lookups to check if two vertices are connected.

Think of it like a mileage chart between cities. To find the distance between city `i` and city `j`, you find the row for `i`, the column for `j`, and the cell where they intersect tells you the distance (the edge weight).

---

## How It Works: The Structure

The `V x V` grid is populated based on the type of graph. We assume the vertices are numbered from 0 to `V-1`.

* **Unweighted Graphs:** `matrix[i][j] = 1` if an edge exists from vertex `i` to `j`, and `0` otherwise.
* **Weighted Graphs:** `matrix[i][j] = weight` if an edge exists, and `0` or `infinity` otherwise.
* **[Undirected Graphs](Un-Directed%20Graph/readme.md):** The matrix is **symmetric**. An edge between `i` and `j` means `matrix[i][j] = 1` and `matrix[j][i] = 1`.
* **[Directed Graphs](Directed%20Graph/readme.md):** The matrix is not necessarily symmetric. An edge from `i` to `j` (`i -> j`) means `matrix[i][j] = 1`, but `matrix[j][i]` could be `0`.

---

## Operations and Algorithms

* **Add Edge(from_vertex, to_vertex)**
    * **Goal:** Create a connection between two vertices.
    * **Algorithm:**
        1.  Set `matrix[from_vertex][to_vertex] = 1` (or the edge `weight`).
        2.  If the graph is undirected, also set `matrix[to_vertex][from_vertex] = 1`.

* **Remove Edge(from_vertex, to_vertex)**
    * **Goal:** Remove the connection between two vertices.
    * **Algorithm:**
        1.  Set `matrix[from_vertex][to_vertex] = 0` (or `infinity`).
        2.  If the graph is undirected, also set `matrix[to_vertex][from_vertex] = 0`.

* **Check for Edge (isAdjacent)**
    * **Goal:** See if two vertices are directly connected.
    * **Algorithm:** Check the value of `matrix[from_vertex][to_vertex]`. If it's not `0` (or `infinity`), an edge exists.

* **Find all Neighbors (of a vertex `v`)**
    * **Goal:** Get a list of all vertices connected to a given vertex.
    * **Algorithm:**
        1.  Iterate through the entire row for vertex `v` in the matrix (from column `j = 0` to `V-1`).
        2.  If `matrix[v][j]` has a value indicating an edge, then vertex `j` is a neighbor.

---

## Key Properties

* **Matrix Representation:** The graph is stored as a `V x V` grid.
* **Space Complexity:** Always uses `$O(V^2)` space, regardless of how many or how few edges the graph has.
* **Symmetry:** For undirected graphs, the matrix is symmetric across its main diagonal (`matrix[i][j] == matrix[j][i]`).
* **Fast Edge Lookup:** Checking for an edge is a direct array access.

---

## Advantages 👍

* **Extremely Fast Edge Lookup:** Checking for the existence of an edge between any two vertices is a constant time (`$O(1)`) operation. This is the primary advantage.
* **Simple Implementation:** The concept of a 2D array is easy to understand and code.
* **Efficient for Dense Graphs:** If the graph has a large number of edges (is "dense," meaning the number of edges `E` is close to `V^2`), the `$O(V^2)` space is well-utilized, and this representation can be very efficient.

---

## Disadvantages 👎

* **High Space Consumption:** The `$O(V^2)` space requirement is the main drawback. It is extremely wasteful for **sparse graphs** (graphs with few edges), which are very common. A graph with 10,000 vertices would require a matrix with 100 million entries, even if it only had 10,000 edges.
* **Slow to Add/Remove Vertices:** Adding or removing a vertex is a very expensive operation, as it requires creating a new `(V+1) x (V+1)` matrix and copying all the old data.
* **Slow to Find Neighbors:** Finding all neighbors of a vertex always requires iterating through an entire row of `V` elements, even if a vertex only has one or two neighbors.

---

## Applications

The adjacency matrix is best suited for **small or dense graphs** where the number of vertices is manageable and fast edge lookups are critical.

* **Dense Graphs:** When the number of edges is a significant fraction of the maximum possible (`V^2`).
* **Algorithms Requiring Frequent Edge Checks:** Certain algorithms that repeatedly check for the existence of edges between pairs of vertices can benefit from the `$O(1)` lookup time.
* **Educational Purposes:** It is often the first graph representation taught due to its simplicity.

---

## Time Complexity Summary

Let `V` be the number of vertices.

| Operation                 | Time Complexity | Explanation                                          |
| :------------------------ | :-------------: | :--------------------------------------------------- |
| **Add Edge** |     `$O(1)`     | A single write to the 2D array.                      |
| **Remove Edge** |     `$O(1)`     | A single write to the 2D array.                      |
| **Check Adjacency** |     `$O(1)`     | A single read from the 2D array.                     |
| **Find Neighbors** |     `$O(V)`     | Must iterate through an entire row of `V` elements. |
| **Add Vertex** |   `$O(V^2)`   | Requires creating a new, larger matrix.              |
| **Graph Traversal (BFS/DFS)**|   `$O(V^2)`   | Traversal requires checking every potential edge.    |