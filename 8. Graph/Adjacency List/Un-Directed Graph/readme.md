# Undirected Graph using Adjacency List

An **Undirected Graph** is a type of graph where edges have no direction; the connection between two vertices is always bidirectional. When using an **Adjacency List** to represent this, if there's an edge between `u` and `v`, then `v` is added to `u`'s list, and `u` is added to `v`'s list.

**Example:**
Consider this undirected graph:
* A --- B
* A --- C
* B --- C

The Adjacency List representation would be:
* **A**: [B, C]
* **B**: [A, C]
* **C**: [A, B]

---

## Operations and Algorithms with Adjacency List

Here are the algorithms for common operations on an undirected graph represented by an adjacency list.

### 1. Breadth-First Search (BFS)
BFS explores the graph level by level and is used to find the shortest path in unweighted graphs.

* **Algorithm:** The steps are identical to BFS in a directed graph.
    1.  Add a `startVertex` to a `queue` and mark it as `visited`.
    2.  While the `queue` is not empty:
        * Dequeue a vertex, `current`.
        * Process `current`.
        * For each `neighbor` in the adjacency list of `current`:
            * If the `neighbor` has not been visited, mark it as `visited` and enqueue it.

### 2. Depth-First Search (DFS)
DFS explores as far as possible along each branch before backtracking.

* **Algorithm:** The steps are identical to DFS in a directed graph.
    1.  Mark the `currentVertex` as `visited`.
    2.  Process the `currentVertex`.
    3.  For each `neighbor` in the adjacency list of `currentVertex`:
        * If the `neighbor` has not been visited, recursively call `DFS` on the `neighbor`.

### 3. Find All Paths
This algorithm finds all unique paths from a `source` to a `destination` vertex using backtracking.

* **Algorithm (Recursive):**
    1.  Add the `source` vertex to a `currentPath` list.
    2.  If `source` is the `destination`, a path has been found. Store or print the `currentPath`.
    3.  If not the destination:
        * For each `neighbor` in the adjacency list of `source`:
            * If the `neighbor` is not already in the `currentPath` (to avoid cycles and immediate backtracking):
                * Recursively call the function for the `neighbor`.
    4.  **Backtrack:** Remove `source` from the `currentPath` before returning, allowing it to be part of other potential paths.

### 4. Cycle Detection
Detecting a cycle in an undirected graph can be done with DFS by checking for "back edges." A back edge is an edge connecting a vertex to one of its ancestors in the DFS tree that is not its direct parent.

* **Parameters:** `graph`, `currentVertex`, `visited` set, `parent`.
* **Algorithm (DFS-based):**
    1.  Mark `currentVertex` as `visited`.
    2.  For each `neighbor` in the adjacency list of `currentVertex`:
        * If the `neighbor` has **not** been `visited`:
            * Recursively call the function: `isCycle(graph, neighbor, visited, currentVertex)`. If this call returns `true`, it means a cycle was found deeper in the traversal, so return `true`.
        * Else if the `neighbor` **is not** the `parent` of the `currentVertex`:
            * This means we have found a back edge to an already visited node that isn't our direct parent. A cycle exists. Return `true`.
    3.  If the loop finishes without finding a cycle, return `false`.

---

## Time Complexity Summary (Adjacency List)

| Operation/Algorithm | Time Complexity | Notes |
| :--- | :--- | :--- |
| **Space Complexity** | $O(V + E)$ | Highly efficient for sparse graphs. |
| **Add Edge** | $O(1)$ | Adds an element to two lists. |
| **Check for Edge** | $O(\text{degree}(u))$ | Requires searching one vertex's list. |
| **BFS Traversal** | $O(V + E)$ | Visits each vertex and edge once. |
| **DFS Traversal** | $O(V + E)$ | Visits each vertex and edge once. |
| **Cycle Detection** | $O(V + E)$ | Based on a single DFS traversal. |