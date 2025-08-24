## Directed Graph (Digraph): Where Relationships Have Direction →

A **Directed Graph**, or **Digraph**, is a type of graph where every edge has a specific **direction**. It consists of a set of vertices connected by edges, where each edge represents a one-way path from a `source` vertex to a `destination` vertex.

This is fundamentally different from an undirected graph. An edge from vertex `A` to `B` (`A → B`) does not imply a path exists from `B` to `A`. Think of a city with one-way streets or following someone on Twitter—the relationship is not automatically mutual.

***Note: Understand Flow via Code in `directedGraph.c`***

---

## Specialized Terminology for Digraphs

Directed graphs introduce some specific terminology:

* **Directed Edge (or Arc):** A connection from a `source` (tail) vertex to a `destination` (head) vertex.
* **In-Degree:** The number of edges pointing **into** a vertex.
* **Out-Degree:** The number of edges pointing **out of** a vertex.
* **Source Vertex:** A vertex with an in-degree of 0 (a natural starting point).
* **Sink Vertex:** A vertex with an out-degree of 0 (a natural ending point).

---

## Key Types of Directed Graphs

The most important classification for directed graphs is whether they contain cycles.

* **Directed Acyclic Graph (DAG):**
    * **Definition:** A directed graph that contains **no directed cycles**.
    * **Importance:** This is an extremely important structure for modeling any process with a defined order, such as dependencies or schedules. You can't have a situation where Task A must happen before Task B, and Task B must happen before Task A.
    * **Example:** Course prerequisites (you must take Calculus I before Calculus II).

* **Directed Cyclic Graph:** A directed graph that contains at least one cycle.

---

## How to Represent a Digraph in Code

* **Adjacency Matrix:** The `V x V` matrix is **not necessarily symmetric**. An edge `i → j` is represented by setting `matrix[i][j] = 1`, but `matrix[j][i]` remains `0` unless there is also an edge `j → i`.
* **Adjacency List:** The list at index `i` contains all the vertices that vertex `i` has an **outgoing** edge to. To efficiently find all incoming edges, a second, "reverse" adjacency list is sometimes maintained.

---

## Operations and Algorithms

While basic operations are similar to undirected graphs, many algorithms are unique to or have special significance for digraphs.

* **Add Edge(source, destination)**
    * **Goal:** Create a one-way connection between two vertices.
    * **Algorithm:** In an adjacency list, add `destination` to the list for `source`. In a matrix, set `matrix[source][destination] = 1`.

* **Traversal (BFS and DFS)**
    * **Goal:** Visit all *reachable* nodes from a starting vertex.
    * **Algorithm:** The same as for an undirected graph, but you can only follow edges in their specified forward direction.

* **Topological Sort**
    * **Goal:** For a **DAG**, produce a linear ordering of its vertices such that for every directed edge `u → v`, vertex `u` comes before vertex `v` in the ordering.
    * **Algorithm (Kahn's Algorithm - BFS based):**
        1.  Compute the in-degree for every vertex.
        2.  Initialize a queue with all vertices that have an in-degree of 0.
        3.  While the queue is not empty, dequeue a vertex `u`, add it to the sorted list, and for each of `u`'s neighbors `v`:
        4.  Decrement the in-degree of `v`. If `v`'s in-degree becomes 0, enqueue it.

* **Cycle Detection**
    * **Goal:** Determine if the graph contains a cycle.
    * **Algorithm (DFS based):**
        1.  Perform a DFS traversal. Maintain two sets of visited nodes: one for the overall traversal, and one for the nodes in the *current recursion path*.
        2.  If the DFS encounters a node that is already in the current recursion path, a back edge has been found, and the graph has a cycle.

---

## Key Properties

* **Directed Edges:** The defining characteristic. All relationships are one-way.
* **Asymmetric Relationships:** The adjacency property is not symmetric; `A` being adjacent to `B` does not mean `B` is adjacent to `A`.
* **Complex Connectivity:** The concept of connectivity is more nuanced, splitting into **weakly connected** (connected if you ignore directions) and **strongly connected** (every node is reachable from every other node).

---

## Advantages 👍

* **Accurate Modeling of Asymmetric Relationships:** Essential for representing real-world scenarios where direction matters, such as dependencies, web links, or one-way traffic.
* **Enables Specific Algorithms:** Allows for powerful, directed-only algorithms like Topological Sort, which are critical for scheduling and dependency analysis.

---

## Disadvantages 👎

* **Increased Complexity:** Algorithms for concepts like connectivity become more nuanced (strong vs. weak).
* **Cycles Can Cause Problems:** Directed cycles can lead to infinite loops or invalid states in algorithms that expect a defined order (like topological sort).

---

## Applications

Directed graphs are foundational in countless domains.

* **Dependency Graphs:** Used in project management (task dependencies), build systems (Makefiles), and resolving software package dependencies.
* **The World Wide Web:** Web pages are vertices, and hyperlinks are directed edges. This is the basis for ranking algorithms like Google's PageRank.
* **State Machines:** Representing states and the transitions between them in software and hardware design.
* **Navigation and Flow Networks:** Modeling one-way streets, the flow of water in pipes, or data in a computer network.

---

## Time Complexity Summary

Let `V` be the number of vertices and `E` be the number of edges.

| Operation/Algorithm       | Adjacency List (Sparse Graphs) | Adjacency Matrix (Dense Graphs) |
| :------------------------ | :----------------------------: | :-----------------------------: |
| **Add Edge** |             `$O(1)`              |              `$O(1)`              |
| **Check Edge (u → v)** |       `$O(\text{out-degree}(u))$`       |              `$O(1)`              |
| **BFS / DFS Traversal** |           `$O(V + E)`           |             `$O(V^2)`            |
| **Topological Sort (DAG)** |           `$O(V + E)`           |             `$O(V^2)`            |