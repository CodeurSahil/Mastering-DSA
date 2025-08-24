#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // For using boolean types

/**
 * Graph Visualization
 *          Graph
 *          /   \
 *      vertex   array (AdjList[])
 *                  |
 *                head
 *              /      \
 *      data = index  next
 */

// Structure for a node in the adjacency list.
struct Node {
    int data;
    struct Node* next;
};

// Structure for an adjacency list (contains a head pointer).
struct AdjList {
    struct Node* head;
};

// Structure for the graph itself.
struct Graph {
    int vertex;
    struct AdjList* array;
};

// Global variable for the topological sort stack pointer.
int pointer = 0;

/**
 * @brief Creates a new node for the adjacency list.
 * @param data The vertex this node will represent.
 * @return A pointer to the newly created node.
 */
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/**
 * @brief Creates a graph with a specified number of vertices.
 * @param vertex The number of vertices in the graph.
 * @return A pointer to the newly created graph.
 */
struct Graph* createGraph(int vertex) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->vertex = vertex;

    // Create an array of adjacency lists, one for each vertex.
    graph->array = (struct AdjList*) malloc(vertex * sizeof(struct AdjList));

    // Initialize each adjacency list's head to NULL.
    for (int i = 0; i < vertex; ++i) {
        graph->array[i].head = NULL;
    }
    printf("\nGraph with %d vertices created!\n", vertex);
    return graph;
}

/**
 * @brief Adds a directed edge from a source to a destination vertex.
 * @param graph A pointer to the graph.
 * @param src The source vertex.
 * @param data The destination vertex.
 */
void addEdge(struct Graph* graph, int src, int data) {
    struct Node* newNode = createNode(data);
    // Insert at the head for simplicity (O(1) insertion).
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
}

/**
 * @brief Performs a Breadth-First Search (BFS) traversal.
 * @param graph A pointer to the graph.
 * @param startVertex The vertex to start the traversal from.
 * @param visited An array to keep track of visited vertices.
 */
void bfsTraversal(struct Graph* graph, int startVertex, int* visited) {
    if (visited[startVertex]) return;

    // Create a simple array-based queue for BFS.
    int* queue = (int*)malloc(graph->vertex * sizeof(int));
    int front = 0, rear = 0;

    // Mark the start node as visited and enqueue it.
    visited[startVertex] = 1;
    queue[rear++] = startVertex;

    while (front < rear) {
        // Dequeue a vertex and print it.
        int currentVertex = queue[front++];
        printf("%d ", currentVertex);

        // Enqueue all adjacent vertices that haven't been visited.
        struct Node* adjNode = graph->array[currentVertex].head;
        while (adjNode) {
            if (!visited[adjNode->data]) {
                visited[adjNode->data] = 1;
                queue[rear++] = adjNode->data;
            }
            adjNode = adjNode->next;
        }
    }
    free(queue);
}

/**
 * @brief Performs a Depth-First Search (DFS) traversal.
 * @param graph A pointer to the graph.
 * @param startVertex The vertex to start the traversal from.
 * @param visited An array to keep track of visited vertices.
 */
void dfsTraversal(struct Graph* graph, int startVertex, int* visited) {
    if (visited[startVertex]) {
        return;
    }
    printf("%d ", startVertex);
    visited[startVertex] = 1;

    // Recursively visit all adjacent vertices.
    struct Node* mainNode = graph->array[startVertex].head;
    while (mainNode) {
        dfsTraversal(graph, mainNode->data, visited);
        mainNode = mainNode->next;
    }
}

/**
 * @brief Recursively finds and prints all paths from a start to an end vertex.
 * @param graph A pointer to the graph.
 * @param path An array to store the current path.
 * @param startVertex The current vertex in the path.
 * @param endVertex The target destination vertex.
 * @param index The current position in the path array.
 * @param visited An array to prevent cycles in the current path.
 */
void findAllPaths(struct Graph* graph, int* path, int startVertex, int endVertex, int index, int* visited) {
    path[index++] = startVertex;
    visited[startVertex] = 1;

    if (startVertex == endVertex) {
        for (int i = 0; i < index; i++) {
            printf("%d%s", path[i], (i == index - 1) ? "" : " -> ");
        }
        printf("\n");
    } else {
        struct Node* mainNode = graph->array[startVertex].head;
        while (mainNode) {
            if (!visited[mainNode->data]) {
                findAllPaths(graph, path, mainNode->data, endVertex, index, visited);
            }
            mainNode = mainNode->next;
        }
    }
    // Backtrack: unmark the current vertex to explore other paths.
    visited[startVertex] = 0;
}

/**
 * @brief A utility function for cycle detection in a directed graph.
 * @param graph A pointer to the graph.
 * @param v The current vertex.
 * @param visited An array to track visited vertices.
 * @param recursionStack An array to track vertices in the current recursion path.
 * @return true if a cycle is detected, false otherwise.
 */
bool isCycleDirectedUtil(struct Graph* graph, int v, int* visited, int* recursionStack) {
    if (!visited[v]) {
        visited[v] = true;
        recursionStack[v] = true;

        struct Node* mainNode = graph->array[v].head;
        while (mainNode) {
            if (!visited[mainNode->data] && isCycleDirectedUtil(graph, mainNode->data, visited, recursionStack))
                return true;
            else if (recursionStack[mainNode->data]) // If neighbor is in recursion stack, a back edge is found.
                return true;
            mainNode = mainNode->next;
        }
    }
    recursionStack[v] = false; // Pop from recursion stack before returning.
    return false;
}

/**
 * @brief Checks if a cycle exists in the directed graph.
 * @param graph A pointer to the graph.
 * @return true if a cycle exists, false otherwise.
 */
bool isCyclic(struct Graph* graph) {
    int* visited = (int*)calloc(graph->vertex, sizeof(int));
    int* recursionStack = (int*)calloc(graph->vertex, sizeof(int));
    if (visited == NULL || recursionStack == NULL) return false;

    for (int i = 0; i < graph->vertex; i++) {
        if (isCycleDirectedUtil(graph, i, visited, recursionStack)) {
            free(visited);
            free(recursionStack);
            return true;
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
 * @brief The main function that drives the program.
 */
int main() {
    printf("Hello! Here You Can Perform Following Directed Graph Operations!\n");
    
    int vertex;
    printf("\nEnter the Number of Vertices(Nodes): ");
    scanf("%d", &vertex);
    
    struct Graph* graph = createGraph(vertex);

    int edges;
    printf("\nEnter the Number of Edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        int src, dest;
        printf("Enter Edge %d (Source Destination): ", i + 1);
        scanf("%d %d", &src, &dest);

        if (src >= graph->vertex || dest >= graph->vertex || src < 0 || dest < 0) {
            printf("\n~~ Invalid Vertex! Please enter vertices between 0 and %d. ~~\n\n", graph->vertex - 1);
            i--; continue;
        }
        if (src == dest) {
            printf("\n~~ Self-loops are not allowed. ~~\n\n");
            i--; continue;
        }

        // Add a single directed edge.
        addEdge(graph, src, dest);
        printf("\n");
    }

    int choice;
    while (1) {
        printf("\n1. Breadth First Search\n2. Depth First Search\n3. Find All Path's\n4. Is Cycle Exists\n5. Exit\nEnter Your Choice:- ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: { // BFS
            int startVertex;
            printf("\nEnter start vertex for BFS: ");
            scanf("%d", &startVertex);
            int* visited = (int*)calloc(graph->vertex, sizeof(int));
            printf("\nBFS Traversal: ");
            bfsTraversal(graph, startVertex, visited);
            printf("\n");
            free(visited);
            break;
        }
        case 2: { // DFS
            int startVertex;
            printf("\nEnter start vertex for DFS: ");
            scanf("%d", &startVertex);
            int* visited = (int*)calloc(graph->vertex, sizeof(int));
            printf("\nDFS Traversal: ");
            dfsTraversal(graph, startVertex, visited);
            printf("\n");
            free(visited);
            break;
        }
        case 3: { // Find All Paths
            int startVertex, endVertex;
            printf("\nEnter Start Vertex: ");
            scanf("%d", &startVertex);
            printf("Enter End Vertex: ");
            scanf("%d", &endVertex);
            
            int* path = (int*)malloc(graph->vertex * sizeof(int));
            int* visited = (int*)calloc(graph->vertex, sizeof(int));
            printf("\nPaths from %d to %d:\n", startVertex, endVertex);
            findAllPaths(graph, path, startVertex, endVertex, 0, visited);
            free(path);
            free(visited);
            break;
        }
        case 4: { // Check for Cycle
            if (isCyclic(graph)) {
                printf("\nCycle Exists in the graph.\n");
            } else {
                printf("\nNo Cycle Exists in the graph.\n");
            }
            break;
        }  
        case 5:
            printf("Thanks For Using! Have a Great Day!");
            free(graph);
            return 0;
        default:
            printf("\nPlease Enter a Valid Input!\n");
            break;
        }
    }
    return 0;
}
