#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // For using boolean types

// Global variable for the topological sort stack pointer.
int pointer = 0;

/**
 * @brief Creates and initializes a graph represented by an adjacency matrix.
 * @param vertex The number of vertices in the graph.
 * @return A 2D integer array (int**) representing the graph.
 */
int** createGraph(int vertex) {
    // Allocate memory for the rows of the matrix.
    int** graph = (int**) malloc(vertex * sizeof(int*));
    if (graph == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    // Allocate memory for the columns of each row and initialize to 0.
    for (int i = 0; i < vertex; i++) {
        graph[i] = (int*) calloc(vertex, sizeof(int)); // calloc initializes memory to 0.
        if (graph[i] == NULL) {
            printf("Memory allocation failed.\n");
            exit(1);
        }
    }
    printf("\nGraph with %d vertices created!\n", vertex);
    return graph;
}

/**
 * @brief Adds a directed edge from a source to a destination vertex.
 * @param graph The adjacency matrix.
 * @param src The source vertex.
 * @param dest The destination vertex.
 */
void addEdge(int** graph, int src, int dest) {
    // Set the value at [src][dest] to 1 to represent a directed edge.
    graph[src][dest] = 1;
}

/**
 * @brief Prints the adjacency matrix representation of the graph.
 * @param graph The adjacency matrix.
 * @param vertex The number of vertices.
 */
void printGraph(int** graph, int vertex) {
    printf("\nAdjacency Matrix:\n  ");
    for (int i = 0; i < vertex; i++) {
        printf("%d ", i);
    }
    printf("\n--|----------\n");
    for (int i = 0; i < vertex; i++) {
        printf("%d | ", i);
        for (int j = 0; j < vertex; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

/**
 * @brief Performs a Breadth-First Search (BFS) traversal.
 * @param graph The adjacency matrix.
 * @param startVertex The vertex to start the traversal from.
 * @param visited An array to keep track of visited vertices.
 * @param vertex The total number of vertices.
 */
void bfsTraversal(int** graph, int startVertex, int* visited, int vertex) {
    if (visited[startVertex]) return;

    // Create a simple array-based queue for BFS.
    int* queue = (int*)malloc(vertex * sizeof(int));
    int front = 0, rear = 0;

    // Mark the start node as visited and enqueue it.
    visited[startVertex] = 1;
    queue[rear++] = startVertex;

    while (front < rear) {
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        // Find all adjacent vertices (neighbors) and enqueue them if not visited.
        for (int neighbor = 0; neighbor < vertex; neighbor++) {
            if (graph[currentVertex][neighbor] == 1 && !visited[neighbor]) {
                visited[neighbor] = 1;
                queue[rear++] = neighbor;
            }
        }
    }
    free(queue);
}

/**
 * @brief Performs a Depth-First Search (DFS) traversal.
 * @param graph The adjacency matrix.
 * @param startVertex The vertex to start the traversal from.
 * @param visited An array to keep track of visited vertices.
 * @param vertex The total number of vertices.
 */
void dfsTraversal(int** graph, int startVertex, int* visited, int vertex) {
    if (visited[startVertex]) {
        return;
    }
    printf("%d ", startVertex);
    visited[startVertex] = 1;

    // Recursively visit all adjacent vertices.
    for (int neighbor = 0; neighbor < vertex; neighbor++) {
        if (graph[startVertex][neighbor] == 1 && !visited[neighbor]) {
            dfsTraversal(graph, neighbor, visited, vertex);
        }
    }
}

/**
 * @brief Recursively finds and prints all paths from a start to an end vertex.
 * @param graph The adjacency matrix.
 * @param path An array to store the current path.
 * @param visited An array to prevent cycles in the current path.
 * @param startVertex The current vertex in the path.
 * @param endVertex The target destination vertex.
 * @param index The current position in the path array.
 * @param vertex The total number of vertices.
 */
void findAllPaths(int** graph, int* path, int* visited, int startVertex, int endVertex, int index, int vertex) {
    path[index++] = startVertex;
    visited[startVertex] = 1;

    if (startVertex == endVertex) {
        for (int i = 0; i < index; i++) {
            printf("%d%s", path[i], (i == index - 1) ? "" : " -> ");
        }
        printf("\n");
    } else {
        for (int neighbor = 0; neighbor < vertex; neighbor++) {
            if (graph[startVertex][neighbor] == 1 && !visited[neighbor]) {
                findAllPaths(graph, path, visited, neighbor, endVertex, index, vertex);
            }
        }
    }
    // Backtrack: unmark the current vertex to explore other paths.
    visited[startVertex] = 0;
}

/**
 * @brief A utility function for cycle detection in a directed graph.
 * @param graph The adjacency matrix.
 * @param v The current vertex.
 * @param visited An array to track visited vertices.
 * @param recursionStack An array to track vertices in the current recursion path.
 * @param vertex The total number of vertices.
 * @return true if a cycle is detected, false otherwise.
 */
bool isCycleExistsUtils(int** graph, int v, int* visited, int* recursionStack, int vertex) {
    if (!visited[v]) {
        visited[v] = true;
        recursionStack[v] = true;

        for (int neighbor = 0; neighbor < vertex; neighbor++) {
            if (graph[v][neighbor]) { // If there is an edge
                if (!visited[neighbor] && isCycleExistsUtils(graph, neighbor, visited, recursionStack, vertex))
                    return true;
                else if (recursionStack[neighbor])
                    return true;
            }
        }
    }
    recursionStack[v] = false; // Pop from recursion stack before returning.
    return false;
}

/**
 * @brief Checks if a cycle exists in the directed graph.
 * @param graph The adjacency matrix.
 * @param vertex The total number of vertices.
 * @return true if a cycle exists, false otherwise.
 */
bool isCycleExists(int** graph, int vertex) {
    int* visited = (int*)calloc(vertex, sizeof(int));
    int* recursionStack = (int*)calloc(vertex, sizeof(int));
    if (visited == NULL || recursionStack == NULL) return false;

    for (int i = 0; i < vertex; i++) {
        if (!visited[i]) {
            if (isCycleExistsUtils(graph, i, visited, recursionStack, vertex)) {
                free(visited);
                free(recursionStack);
                return true;
            }
        }
    }
    free(visited);
    free(recursionStack);
    return false;
}

/**
 * @brief Pushes an item onto the topological sort stack.
 * @param stack The stack array.
 * @param data The data to push.
 */
void stackPush(int* stack, int data) {
    stack[pointer++] = data;
}

/**
 * @brief A recursive helper for topological sorting.
 * @param graph The adjacency matrix.
 * @param startVertex The current vertex.
 * @param visited An array to track visited vertices.
 * @param stack The stack to store the sorted vertices.
 * @param vertex The total number of vertices.
 */
void topologicalSortUtil(int** graph, int startVertex, int* visited, int* stack, int vertex) {
    visited[startVertex] = 1;

    for (int neighbor = 0; neighbor < vertex; neighbor++) {
        if (graph[startVertex][neighbor] == 1 && !visited[neighbor]) {
            topologicalSortUtil(graph, neighbor, visited, stack, vertex);
        }
    }
    stackPush(stack, startVertex);
}

/**
 * @brief The main function that drives the program.
 */
int main() {
    printf("Hello! Here You Can Perform Following Directed Graph Operations (Adjacency Matrix)!\n");
    
    int vertex;
    printf("\nEnter the Number of Vertices(Nodes): ");
    scanf("%d", &vertex);
    
    int** graph = createGraph(vertex);

    int edges;
    printf("\nEnter the Number of Edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        int src, dest;
        printf("Enter Edge %d (Source Destination): ", i + 1);
        scanf("%d %d", &src, &dest);

        if (src >= vertex || dest >= vertex || src < 0 || dest < 0) {
            printf("\n~~ Invalid Vertex! Please enter vertices between 0 and %d. ~~\n\n", vertex - 1);
            i--; continue;
        }
        if (src == dest) {
            printf("\n~~ Self-loops are not allowed. ~~\n\n");
            i--; continue;
        }
        addEdge(graph, src, dest);
    }

    int choice;
    while (1) {
        printf("\n1. Display Graph\n2. Breadth First Search\n3. Depth First Search\n4. Find All Paths\n5. Check for Cycle\n6. Topological Sort\n7. Exit\nEnter Your Choice:- ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: { // Display Graph
            printGraph(graph, vertex);
            break;
        }
        case 2: { // BFS
            int startVertex;
            printf("\nEnter start vertex for BFS: ");
            scanf("%d", &startVertex);
            int* visited = (int*)calloc(vertex, sizeof(int));
            printf("\nBFS Traversal: ");
            bfsTraversal(graph, startVertex, visited, vertex);
            printf("\n");
            free(visited);
            break;
        }
        case 3: { // DFS
            int startVertex;
            printf("\nEnter start vertex for DFS: ");
            scanf("%d", &startVertex);
            int* visited = (int*)calloc(vertex, sizeof(int));
            printf("\nDFS Traversal: ");
            dfsTraversal(graph, startVertex, visited, vertex);
            printf("\n");
            free(visited);
            break;
        }
        case 4: { // Find All Paths
            int startVertex, endVertex;
            printf("\nEnter Start Vertex: ");
            scanf("%d", &startVertex);
            printf("Enter End Vertex: ");
            scanf("%d", &endVertex);
            
            int* path = (int*)malloc(vertex * sizeof(int));
            int* visited = (int*)calloc(vertex, sizeof(int));
            printf("\nPaths from %d to %d:\n", startVertex, endVertex);
            findAllPaths(graph, path, visited, startVertex, endVertex, 0, vertex);
            free(path);
            free(visited);
            break;
        }
        case 5: { // Check for Cycle
            if (isCycleExists(graph, vertex)) {
                printf("\nCycle Exists in the graph.\n");
            } else {
                printf("\nNo Cycle Exists in the graph.\n");
            }
            break;
        }  
        case 6: { // Topological Sort
            if (isCycleExists(graph, vertex)) {
                printf("\nCycle Exists! Can't Perform Topological Sort on a cyclic graph.\n");
                break;
            }
            int* visited = (int*)calloc(vertex, sizeof(int));
            int* stack = (int*)malloc(vertex * sizeof(int));
            pointer = 0;
            for (int i = 0; i < vertex; i++) {
                if (!visited[i]) {
                    topologicalSortUtil(graph, i, visited, stack, vertex);
                }
            }
            printf("\nTopological Sort: ");
            for (int i = vertex - 1; i >= 0; i--) {
                printf("%d ", stack[i]);
            }
            printf("\n");
            free(visited);
            free(stack);
            break;
        }
        case 7: // Exit
            printf("\nThanks For Using! Have a Great Day!\n");
            for(int i=0; i<vertex; i++) free(graph[i]);
            free(graph);
            return 0;
        default:
            printf("\nPlease Enter a Valid Input!\n");
            break;
        }
    }
    return 0;
}
