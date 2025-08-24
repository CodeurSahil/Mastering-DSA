## Graph: The Ultimate Network Data Structure 🕸️

A **Graph** is a non-linear data structure consisting of a set of **vertices** (or nodes) and a set of **edges** that connect pairs of these vertices. Graphs are the ultimate tool for modeling **relationships** and networks.

Unlike a tree, a graph is a more general structure: it can have cycles, multiple paths between nodes, and can even be composed of several disconnected parts. Think of a social network, where people are vertices and their friendships are edges, or a city map, where intersections are vertices and roads are edges.

---

### Representation
![Graph](/assets/graph.png)

---

## Essential Graph Terminology

To speak the language of graphs, you need to know these key terms:

* **Vertex (or Node):** An individual entity or point in the graph.
* **Edge:** A connection between two vertices.
* **Adjacency:** Two vertices are **adjacent** if they are connected by an edge.
* **Path:** A sequence of edges that allows you to travel from one vertex to another.
* **Cycle:** A path that starts and ends at the same vertex.
* **Degree:** (For undirected graphs) The number of edges connected to a vertex.
* **In-Degree / Out-Degree:** (For directed graphs) The number of incoming and outgoing edges for a vertex, respectively.

---

## Types of Graphs

Graphs can be categorized based on the properties of their edges.

* **Undirected vs. Directed Graph:**
    * **Undirected:** Edges have no direction. The connection is two-way (e.g., a Facebook friendship).
    * **Directed (Digraph):** Edges have a direction. The connection is one-way (e.g., a Twitter follow).

* **Unweighted vs. Weighted Graph:**
    * **Unweighted:** Edges are all uniform; there is no cost to travel between vertices.
    * **Weighted:** Each edge has a "weight" or "cost" associated with it, representing something like distance, time, or capacity.

* **Cyclic vs. Acyclic Graph:**
    * **Cyclic:** The graph contains at least one cycle.
    * **Acyclic:** The graph has no cycles. A **Directed Acyclic Graph (DAG)** is a particularly important type used to model dependencies and schedules.

---

## How to Represent a Graph in Code

The way you store a graph in memory has a major impact on performance.

* **1. [Adjacency List](Adjacency%20List/readme.md)**
    * **Structure:** An array of linked lists. The list at index `i` stores all the vertices that vertex `i` is connected to.
    * **Pros:** Very space-efficient for **sparse graphs** (graphs with few edges), which are common in the real world.
    * **Cons:** Checking for a specific edge between two vertices can be slower.
    * **Best for:** Most real-world problems.

* **2. [Adjacency Matrix](Adjacency%20Matrix/readme.md)**
    * **Structure:** A 2D array (matrix) of size `V x V`, where `V` is the number of vertices. `matrix[i][j] = 1` (or the weight) if there's an edge from `i` to `j`.
    * **Pros:** Extremely fast to check if an edge exists between two vertices (`$O(1)`).
    * **Cons:** Uses a lot of memory (`$O(V^2)`), making it impractical for large, sparse graphs.
    * **Best for:** **Dense graphs** where the number of edges is close to the maximum possible.

---

## Graph Traversal Algorithms

Traversal is the process of visiting every vertex in the graph.

* **Breadth-First Search (BFS)**
    * **Logic:** Explores the graph level by level, like ripples in a pond. It uses a **queue** to manage which nodes to visit next.
    * **Best Use Case:** Finding the **shortest path** in an **unweighted** graph.

* **Depth-First Search (DFS)**
    * **Logic:** Explores as far as possible down one path before backtracking. It uses a **stack** (often managed implicitly through recursion).
    * **Best Use Cases:** Detecting cycles, topological sorting (for DAGs), and pathfinding in mazes.

---

## Operations and Algorithms

* **addVertex()**: Add a new, isolated vertex to the graph.
* **addEdge(v1, v2)**: Create a connection (edge) between two existing vertices.
* **removeEdge(v1, v2)**: Remove the connection between two vertices.
* **removeVertex(v)**: Remove a vertex and all edges connected to it.
* **Traversal (BFS, DFS)**: Visiting all vertices in a systematic order.

Many powerful algorithms are designed specifically for graphs, such as:
* **Dijkstra's Algorithm:** Finds the shortest path in a weighted graph.
* **Prim's & Kruskal's Algorithms:** Find a Minimum Spanning Tree in a graph.
* **Topological Sort:** Creates a linear ordering of vertices in a DAG.

---

## Key Properties

* **Non-linear:** Data is organized in a network structure without a clear start, end, or simple sequence.
* **Can be Cyclic:** Unlike trees, graphs can and often do contain cycles.
* **Can be Disconnected:** A graph can be made up of multiple separate "islands" of connected vertices.
* **Represents Many-to-Many Relationships:** This is the core strength of the graph model, allowing for complex interconnections.

---

## Advantages 👍

* **Extremely Versatile:** Can model almost any kind of real-world network or relationship, from social networks and road maps to the internet and molecular structures.
* **Powerful Problem-Solving Tool:** A vast number of complex problems can be simplified and solved by modeling them as a graph and applying well-known graph algorithms.

---

## Disadvantages 👎

* **Implementation Complexity:** Can be more complex to set up and manage than linear structures or trees.
* **High Algorithmic Complexity:** Many graph algorithms are computationally expensive, especially on very large or dense graphs.

---

## Applications

Graphs are everywhere in modern technology and science.

* **Social Networks:** Modeling users (vertices) and their connections (edges) on platforms like Facebook, LinkedIn, and Instagram.
* **Navigation and GPS:** Finding the shortest and fastest routes in a road network (e.g., Google Maps, Waze).
* **The World Wide Web:** Representing web pages as vertices and hyperlinks as directed edges, which is fundamental to how search engines like Google work.
* **Recommendation Engines:** Suggesting friends, products, or movies based on the connections in a graph (e.g., "people you may know" or "customers who bought this also bought...").
* **Logistics and Supply Chains:** Optimizing delivery routes and managing the flow of goods.
* **Biology:** Modeling protein-protein interactions and metabolic pathways.

---

## Time Complexity Summary

The performance of graph algorithms depends heavily on the chosen representation. Let `V` be the number of vertices and `E` be the number of edges.

| Operation/Algorithm | Adjacency List (Sparse Graphs) | Adjacency Matrix (Dense Graphs) |
| :------------------ | :----------------------------: | :-----------------------------: |
| **Add Edge** |             `$O(1)`              |              `$O(1)`              |
| **Check Adjacency** |             `$O(V)$`              |              `$O(1)`              |
| **BFS Traversal** |           `$O(V + E)`           |             `$O(V^2)`            |
| **DFS Traversal** |           `$O(V + E)`           |             `$O(V^2)`            |