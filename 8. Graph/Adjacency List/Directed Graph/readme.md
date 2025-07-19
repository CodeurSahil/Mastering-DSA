# Directed Graph (Digraph) Explained

A **Directed Graph**, often referred to as a **Digraph**, is a type of graph where each edge has a specific direction. This direction indicates a one-way relationship from one vertex to another. Unlike undirected graphs where edges are bidirectional, in a directed graph, an edge from vertex `A` to vertex `B` does not imply an edge from `B` to `A`.

---

## Basic Terminology (Specific to Directed Graphs)

* **Directed Edge (Arc):** An edge $(u, v)$ goes from vertex `u` (the **tail** or **source**) to vertex `v` (the **head** or **destination**).
    * Example: A -> B. This means you can go from A to B, but not necessarily from B to A.
* **In-degree of a Vertex:** The number of incoming edges to a vertex.
    * Example: If edges are (A, C), (B, C), (D, C), then the in-degree of C is 3.
* **Out-degree of a Vertex:** The number of outgoing edges from a vertex.
    * Example: If edges are (C, E), (C, F), then the out-degree of C is 2.
* **Source Vertex:** A vertex with an in-degree of 0.
* **Sink Vertex:** A vertex with an out-degree of 0.
* **Directed Path:** A sequence of vertices $v_0, v_1, \dots, v_k$ such that there is a directed edge $(v_i, v_{i+1})$ for all $0 \le i < k$.
* **Directed Cycle:** A directed path that starts and ends at the same vertex, visiting other vertices only once.
* **Strongly Connected Graph:** A directed graph in which there is a path from each vertex to every other vertex.
* **Strongly Connected Component (SCC):** A maximal strongly connected subgraph. This means it's a subgraph where every vertex is reachable from every other vertex within that subgraph, and it cannot be extended by adding more vertices from the original graph and still maintain strong connectivity.
* **Weakly Connected Graph:** A directed graph is weakly connected if, when you ignore the direction of edges, the underlying undirected graph is connected.

---

## Types of Directed Graphs

* **Directed Acyclic Graph (DAG):** A directed graph that contains no directed cycles. DAGs are extremely important for representing dependencies, scheduling tasks, and many other applications.
    * **Example:** Task dependencies in a project (Task A must complete before Task B), course prerequisites.
* **Directed Cyclic Graph:** A directed graph that contains at least one directed cycle.
* **Weighted Directed Graph:** Each directed edge has an associated numerical value (weight or cost).
    * **Example:** Flight routes with associated travel times or costs.

---

## Representation of Directed Graphs

Similar to undirected graphs, directed graphs can be represented using:

1.  **Adjacency Matrix:**
    * A $V \times V$ matrix.
    * `matrix[i][j] = 1` (or weight) if there's a directed edge from vertex `i` to vertex `j`.
    * `matrix[j][i]` would be `0` (or `infinity`) if there's no edge from `j` to `i`.
    * Space: $O(V^2)$.
    * Time to check edge `(i, j)`: $O(1)$.
    * Time to find all outgoing neighbors of `i`: $O(V)$.
    * Time to find all incoming neighbors of `i`: $O(V)$.

2.  **Adjacency List:**
    * An array (or hash map) where each index `i` stores a list of vertices `j` for which a directed edge `(i, j)` exists.
    * For incoming edges, you might need a reverse adjacency list.
    * Space: $O(V + E)$ (where `E` is the number of edges).
    * Time to check edge `(i, j)`: $O(\text{out-degree of } i)$.
    * Time to find all outgoing neighbors of `i`: $O(\text{out-degree of } i)$.
    * Time to find all incoming neighbors of `i`: $O(\text{in-degree of } i)$ if a reverse adjacency list is maintained, otherwise $O(V+E)$ or $O(V^2)$ to iterate through all edges.

3.  **Edge List:**
    * A list of tuples, where each tuple `(u, v)` represents a directed edge from `u` to `v`.
    * Space: $O(E)$.
    * Pros: Simple to store, useful for algorithms that iterate over all edges.
    * Cons: Inefficient for checking adjacency or finding neighbors.

---

## Graph Traversal Algorithms (Applied to Directed Graphs)

BFS and DFS work on directed graphs, but their properties change due to direction:

1. Here’s a corrected and structured version of your **Breadth-First Search (BFS)** algorithm description:

---

1. ✅ **Breadth-First Search (BFS) Algorithm**

    **Parameters Required:**

    * `visited[]`: An array to track whether a vertex has been visited.
    * `Queue`: A queue data structure to hold vertices to explore.

    ---

    ### **Steps:**

    1. **Initialize**:
       Add the starting vertex `start` to the queue.
       Mark `visited[start] = true`.

    2. **Loop Until Queue is Empty**:

       * Dequeue the front element, call it `current`.
       * Print or process `current`.
       * For each **neighbor** of `current`:

         * If `visited[neighbor] == false`:

           * Enqueue `neighbor`.
           * Mark `visited[neighbor] = true`.

2.  **Depth-First Search (DFS):** Uses Recurssion Approach

    **Parameters Required:**
    * `visited[]`: An array to track whether a vertex has been visited.

    ---

    ### **Steps:**

    1. If `visited[neighbor] == True`: return;

    2. Mark the Node a Visited i.e. `visited[startVertex] = True`;

    3. DFS its Neighbour i.e. `dfsTraversal(graph, neighbourData, visited);`
    
    ### Details
    * Explores as far as possible along each directed path before backtracking.
    * Crucial for many directed graph algorithms.
    * **Applications:**
        * **Cycle Detection:** A directed graph has a cycle if and only if a DFS traversal finds a back edge (an edge from a vertex to an ancestor in the DFS tree).
        * **Topological Sorting:** Only applicable to DAGs. Provides a linear ordering of vertices such that for every directed edge $(u, v)$, $u$ comes before $v$ in the ordering.
        * **Finding Strongly Connected Components (SCCs):** Algorithms like Kosaraju's Algorithm or Tarjan's Algorithm use DFS (often two passes) to find SCCs.

---

## Key Algorithms for Directed Graphs

Many graph algorithms are specifically designed or primarily used for directed graphs:

* **Topological Sort:**
    * **Kahn's Algorithm (BFS-based):** Uses in-degrees of nodes.
    * **DFS-based Algorithm:** Uses finish times of nodes in DFS.
    * **Applications:** Task scheduling, dependency resolution, course prerequisites, build systems.

* **Strongly Connected Components (SCCs):**
    * **Kosaraju's Algorithm:** Two DFS passes, one on the original graph and one on its transpose.
    * **Tarjan's Algorithm:** A single DFS pass using discovery times and low-link values.
    * **Applications:** Analyzing network robustness, identifying groups of mutually reachable pages on the web, software module dependency analysis.

* **Shortest Path Algorithms:**
    * **Dijkstra's Algorithm:** Works on directed graphs with non-negative edge weights.
    * **Bellman-Ford Algorithm:** Works on directed graphs with potentially negative edge weights and can detect negative cycles.
    * **DAG Shortest Path:** For DAGs, a linear time ($O(V+E)$) algorithm exists by first performing a topological sort and then relaxing edges in that order. This is faster than Dijkstra's or Bellman-Ford for DAGs.

* **Reachability Analysis:** Determining if one vertex can reach another. Often solved using BFS or DFS.

* **Transitive Closure:** For every pair of vertices (u, v), determine if v is reachable from u. Can be computed using repeated BFS/DFS or Floyd-Warshall.

---

## Advantages of Directed Graphs

* **Accurate Modeling of Asymmetric Relationships:** Essential for representing relationships where direction matters (e.g., "A follows B" is different from "B follows A").
* **Dependency Representation:** Perfect for showing prerequisites, task order, and causal relationships.
* **Network Flow:** Directed graphs with capacities are fundamental for network flow problems.

---

## Disadvantages of Directed Graphs

* **Increased Complexity in Some Algorithms:** Algorithms like finding connected components become more nuanced (strong vs. weak connectivity).
* **Cycles Can Cause Issues:** Directed cycles can lead to infinite loops in naive traversals and complicate algorithms that expect a defined order (like topological sort).
* **Bidirectional Relationship Requires Two Edges:** If a relationship is truly bidirectional (e.g., A and B are friends), it must be explicitly represented by two directed edges (A -> B and B -> A), or the graph should be modeled as undirected.

---

## Applications of Directed Graphs

Directed graphs are foundational in countless domains:

* **Social Networks:** Representing "follows," "subscribes to," or "sends messages to" relationships.
* **The World Wide Web:** Web pages are vertices, and hyperlinks are directed edges. Used by search engines for ranking (e.g., PageRank).
* **Flow Networks:** Modeling water flow, traffic flow, supply chains, electrical circuits.
* **Dependency Graphs:** Compilers (call graphs, dependency analysis), build systems (Makefiles), project management (task dependencies).
* **State Machines/Finite Automata:** Representing states and transitions in systems.
* **Decision-Making:** Modeling decision trees or flowcharts.
* **Biological Networks:** Gene regulatory networks, metabolic pathways.
* **Computer Networks:** Routing protocols, data flow.

---

## Time Complexity (Summary for Directed Graphs)

The complexities are generally the same as for general graphs, but the specific definitions (e.g., in-degree vs. out-degree) become relevant. `V` is the number of vertices, `E` is the number of edges.

| Operation/Algorithm       | Adjacency List (Sparse) | Adjacency Matrix (Dense) |
| :------------------------ | :---------------------- | :----------------------- |
| Add Edge                  | O(1)                    | O(1)                     |
| Check Edge (u, v)         | O(out-degree of u)      | O(1)                     |
| DFS Traversal             | O(V + E)                | O($V^2$)                 |
| BFS Traversal             | O(V + E)                | O($V^2$)                 |
| Topological Sort          | O(V + E)                | O($V^2$)                 |
| Bellman-Ford              | O(V * E)                | O($V^3$)                 |
| Dijkstra's (with PQ)      | O(E log V)              | O($V^2$)                 |
| SCC (Kosaraju/Tarjan)     | O(V + E)                | O($V^2$)                 |

---