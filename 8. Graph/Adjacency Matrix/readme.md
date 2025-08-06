# Graph Representation: Adjacency Matrix

An **Adjacency Matrix** is a square matrix used to represent a finite graph. The elements of the matrix indicate whether pairs of vertices are adjacent or not in the graph. It's a straightforward way to represent a graph's structure in a computer's memory.

---

## How It Works

For a graph with 'V' vertices, an adjacency matrix is a V x V matrix, let's call it `adj`, where:

* The **rows and columns** of the matrix are labeled by the graph's vertices (e.g., from 0 to V-1, or A, B, C...).
* The value stored at `adj[i][j]` indicates the relationship between vertex `i` and vertex `j`.

### For an Unweighted Graph:
* `adj[i][j] = 1` if there is an edge from vertex `i` to vertex `j`.
* `adj[i][j] = 0` if there is no edge from vertex `i` to vertex `j`.

### For a Weighted Graph:
* `adj[i][j] = w` if there is an edge from vertex `i` to vertex `j` with weight `w`.
* `adj[i][j] = 0` or `infinity` if there is no edge. Using `0` can be ambiguous if an edge can have a weight of 0, so `infinity` is often preferred for algorithms like finding the shortest path.

---

## Undirected vs. Directed Graphs

The nature of the adjacency matrix changes slightly depending on whether the graph is directed or undirected.

### 1. Undirected Graph Representation

In an undirected graph, an edge between vertex `i` and `j` is bidirectional. This means if `i` is connected to `j`, then `j` is also connected to `i`.

* **Key Property:** The adjacency matrix of an undirected graph is always **symmetric**.
* **Rule:** If `adj[i][j] = 1`, then `adj[j][i] = 1`.

#### Example:
Consider this undirected graph:
```
A --- B
|  \  /
|   \/
C -- D
```
The vertices are {A, B, C, D}. The Adjacency Matrix would be:

| | A | B | C | D |
|---|---|---|---|---|
|**A**| 0 | 1 | 1 | 1 |
|**B**| 1 | 0 | 0 | 1 |
|**C**| 1 | 0 | 0 | 1 |
|**D**| 1 | 1 | 1 | 0 |

*Notice the symmetry across the diagonal (from top-left to bottom-right).*

---

### 2. Directed Graph (Digraph) Representation

In a directed graph, edges have a specific direction. An edge from `i` to `j` does not imply an edge from `j` to `i`.

* **Key Property:** The adjacency matrix is **not necessarily symmetric**.
* **Rule:** `adj[i][j] = 1` indicates a directed edge from `i` to `j`. `adj[j][i]` will be 1 only if there is a separate edge from `j` back to `i`.

#### Example:
Consider this directed graph:
```
A -> B
|   /
v  /
C <- D
```
The vertices are {A, B, C, D}. The Adjacency Matrix would be:

| | A | B | C | D |
|---|---|---|---|---|
|**A**| 0 | 1 | 1 | 0 |
|**B**| 0 | 0 | 0 | 0 |
|**C**| 0 | 0 | 0 | 0 |
|**D**| 0 | 1 | 1 | 0 |

*For instance, `adj[A][B] = 1` because of the A -> B edge, but `adj[B][A] = 0` because there is no edge from B to A.*

---

## Graph Operations and Algorithms with Adjacency Matrix

Here’s how to perform key graph operations using a `V x V` adjacency matrix named `matrix`.

---

## 1. Basic Operations

These are the fundamental building blocks for more complex algorithms.

* ### **Add Edge**
    * **Description:** Creates a connection from vertex `u` to vertex `v`.
    * **Algorithm:**
        1.  To add an edge from `u` to `v` with a specific `weight` (for weighted graphs) or `1` (for unweighted graphs):
            * `matrix[u][v] = weight` (or 1)
        2.  If the graph is **undirected**, the connection is mutual. You must also set:
            * `matrix[v][u] = weight` (or 1)
    * **Complexity:** $O(1)$

* ### **Remove Edge**
    * **Description:** Deletes the connection from vertex `u` to `v`.
    * **Algorithm:**
        1.  To remove the edge from `u` to `v`, set its value to indicate absence.
            * `matrix[u][v] = 0` (or `infinity` for weighted graphs).
        2.  If the graph is **undirected**, you must also remove the reverse edge:
            * `matrix[v][u] = 0` (or `infinity`).
    * **Complexity:** $O(1)$

* ### **Check for Edge (Adjacency Check)**
    * **Description:** Determines if a direct edge exists from vertex `u` to `v`.
    * **Algorithm:**
        1.  Access the cell `matrix[u][v]`.
        2.  If `matrix[u][v]` is not `0` (or not `infinity`), an edge exists. Return `true`.
        3.  Otherwise, return `false`.
    * **Complexity:** $O(1)$

* ### **Find Neighbors**
    * **Description:** Gets a list of all vertices directly reachable from a given vertex `u`.
    * **Algorithm:**
        1.  Initialize an empty list called `neighbors`.
        2.  Iterate through the row corresponding to `u` from the first column to the last (i.e., for `j` from 0 to V-1).
        3.  If `matrix[u][j]` is not `0` (or not `infinity`), it means `j` is a neighbor. Add `j` to the `neighbors` list.
        4.  Return the `neighbors` list.
    * **Complexity:** $O(V)$, as it always requires scanning the entire row.

---

## 2. Graph Traversal Algorithms

Traversal algorithms visit every vertex and edge in a systematic way.

* ### ✅ **Breadth-First Search (BFS) Algorithm**
    * **Description:** Explores neighbor nodes first before moving to the next level of neighbors. It uses a queue.
    * **Parameters Required:**
        * `matrix[][]`: The V x V adjacency matrix.
        * `startVertex`: The vertex where the traversal begins.
        * `visited[]`: A boolean array to track visited vertices.
        * `queue`: A queue data structure.
    * **Steps:**
        1.  **Initialize**:
            * Add the `startVertex` to the `queue`.
            * Mark `visited[startVertex] = true`.
        2.  **Loop Until Queue is Empty**:
            * Dequeue the front vertex, let's call it `current`.
            * Process or print `current`.
            * **Find Neighbors**: Iterate through the row for `current` (from `neighbor = 0` to `V-1`):
                * If an edge exists (`matrix[current][neighbor] == 1`) AND the neighbor has not been visited (`visited[neighbor] == false`):
                    * Enqueue the `neighbor`.
                    * Mark `visited[neighbor] = true`.
    * **Complexity:** $O(V^2)$ because for each vertex, you scan a full row of `V` elements to find its neighbors.

* ### **Depth-First Search (DFS) Algorithm**
    * **Description:** Explores as far as possible along each branch before backtracking. It typically uses recursion (which internally uses a stack).
    * **Parameters Required:**
        * `matrix[][]`: The V x V adjacency matrix.
        * `currentVertex`: The vertex being visited.
        * `visited[]`: A boolean array to track visited vertices.
    * **Recursive Function `dfsUtil(currentVertex, visited)`:**
        1.  **Mark as Visited**: Mark `visited[currentVertex] = true`.
        2.  **Process Node**: Print or process `currentVertex`.
        3.  **Recurse for Neighbors**: Iterate through the row for `currentVertex` (from `neighbor = 0` to `V-1`):
            * If an edge exists (`matrix[currentVertex][neighbor] == 1`) AND the neighbor has not been visited (`visited[neighbor] == false`):
                * Recursively call `dfsUtil(neighbor, visited)`.
    * **Main Driver:** To handle disconnected graphs, you need a loop to start the traversal from every vertex if it hasn't been visited yet.
    * **Complexity:** $O(V^2)$ because the algorithm must check every potential edge in the matrix.

## Advantages of Adjacency Matrix

* **Fast Edge Lookup:** Checking if an edge exists between two vertices `i` and `j` is extremely efficient. It's a constant time operation, **O(1)**.
* **Simple to Implement:** The logic for creating and using an adjacency matrix is straightforward.
* **Easy to Modify:** Adding or removing an edge is also an **O(1)** operation.
* **Good for Dense Graphs:** It is very efficient in terms of space and performance for dense graphs, where the number of edges is close to the maximum possible number of edges ($V^2$).

---

## Disadvantages of Adjacency Matrix

* **High Space Consumption:** The biggest drawback is its space complexity of **$O(V^2)$**, where V is the number of vertices. This is highly inefficient for **sparse graphs** (graphs with few edges), as it stores a lot of zeros for non-existent edges. For a graph with 10,000 vertices, it would require a 10,000 x 10,000 matrix, regardless of the number of edges.
* **Slow to Iterate Over Neighbors:** Finding all neighbors of a given vertex requires iterating through its entire row (or column), which takes **O(V)** time, even if the vertex has very few neighbors. In contrast, an adjacency list can do this in time proportional to the number of actual neighbors.

---

## Time Complexity Summary (Using Adjacency Matrix)

| Operation | Time Complexity | Notes |
| :--- | :--- | :--- |
| **Space** | $O(V^2)$ | Main disadvantage, especially for sparse graphs. |
| **Add Vertex** | $O(V^2)$ | Requires rebuilding the entire matrix. |
| **Remove Vertex** | $O(V^2)$ | Requires rebuilding the entire matrix. |
| **Add Edge** | $O(1)$ | Simple update of a single matrix cell. |
| **Remove Edge** | $O(1)$ | Simple update of a single matrix cell. |
| **Check Adjacency (Edge)** | $O(1)$ | Main advantage. |
| **Find Neighbors of a Vertex** | $O(V)$ | Must scan an entire row or column. |
| **Graph Traversal (BFS, DFS)**| $O(V^2)$ | Since visiting each vertex requires checking all other V vertices for edges. |