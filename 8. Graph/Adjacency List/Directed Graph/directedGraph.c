#include <stdio.h>
#include <stdlib.h>

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
 * The adjacency list is kept sorted for consistency.
 * @param graph A pointer to the graph.
 * @param src The source vertex.
 * @param data The destination vertex.
 */
void addEdge(struct Graph* graph, int src, int data) {
    struct Node* newNode = createNode(data);

    // If the list is empty or the new node should be the new head.
    if (graph->array[src].head == NULL || graph->array[src].head->data >= data) {
        newNode->next = graph->array[src].head;
        graph->array[src].head = newNode;
    } else {
        // Find the correct sorted position to insert the new node.
        struct Node* temp = graph->array[src].head;
        while (temp->next != NULL && temp->next->data < data) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

/**
 * @brief Performs a Breadth-First Search (BFS) traversal.
 * @param graph A pointer to the graph.
 * @param startVertex The vertex to start the traversal from.
 * @param visited An array to keep track of visited vertices.
 */
void bfsTraversal(struct Graph* graph, int startVertex, int* visited) {
    if (visited[startVertex]) return; // Don't traverse if already visited.

    // Create a queue for BFS (implemented with a linked list).
    struct Node* queue = createNode(startVertex);
    struct Node* rear = queue;
    visited[startVertex] = 1;

    while (queue != NULL) {
        int currentVertex = queue->data;
        printf("%d ", currentVertex);

        // Dequeue the current vertex.
        struct Node* temp = queue;
        queue = queue->next;
        free(temp);

        // Enqueue all adjacent vertices that haven't been visited.
        struct Node* adjNode = graph->array[currentVertex].head;
        while (adjNode) {
            if (!visited[adjNode->data]) {
                visited[adjNode->data] = 1;
                struct Node* newNode = createNode(adjNode->data);
                if (queue == NULL) {
                    queue = rear = newNode;
                } else {
                    rear->next = newNode;
                    rear = newNode;
                }
            }
            adjNode = adjNode->next;
        }
    }
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

    // If the destination is reached, print the current path.
    if (startVertex == endVertex) {
        for (int i = 0; i < index; i++) {
            printf("%d%s", path[i], (i == index - 1) ? "" : " -> ");
        }
        printf("\n");
    } else {
        // Explore all adjacent vertices.
        struct Node* mainNode = graph->array[startVertex].head;
        while (mainNode) {
            if (!visited[mainNode->data]) {
                findAllPaths(graph, path, mainNode->data, endVertex, index, visited);
            }
            mainNode = mainNode->next;
        }
    }

    // Backtrack: unmark the current vertex as visited to explore other paths.
    visited[startVertex] = 0;
}

/**
 * @brief A utility function for cycle detection in an undirected graph.
 * @param graph A pointer to the graph.
 * @param startVertex The current vertex.
 * @param visited An array to track visited vertices.
 * @param parent The parent of the current vertex in the DFS tree.
 * @return 1 if a cycle is detected, 0 otherwise.
 */
int isCycleExistsUtils(struct Graph* graph, int startVertex, int* visited, int parent) {
    visited[startVertex] = 1;

    struct Node* mainNode = graph->array[startVertex].head;
    while (mainNode) {  
        if (!visited[mainNode->data]) {
            if (isCycleExistsUtils(graph, mainNode->data, visited, startVertex)) {
                return 1; // Cycle found in a deeper recursive call.
            }
        } 
        // If an adjacent vertex is visited and is not the parent, a back edge is found, hence a cycle.
        else if (mainNode->data != parent) {
            return 1;
        }
        mainNode = mainNode->next;
    }
    return 0;
}

/**
 * @brief Checks if a cycle exists in the graph.
 * @param graph A pointer to the graph.
 * @return 1 if a cycle exists, 0 otherwise.
 */
int isCyclic(struct Graph* graph) {
    int* visited = (int*)calloc(graph->vertex, sizeof(int));
    if (visited == NULL) return 0;

    // Check for cycles in all disconnected components of the graph.
    for (int i = 0; i < graph->vertex; i++) {
        if (!visited[i]) {
            if (isCycleExistsUtils(graph, i, visited, -1)) {
                free(visited);
                return 1; // Cycle found.
            }
        }
    }
    free(visited);
    return 0; // No cycles found.
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
 * @param graph A pointer to the graph.
 * @param startVertex The current vertex.
 * @param visited An array to track visited vertices.
 * @param stack The stack to store the sorted vertices.
 */
void topologicalSort(struct Graph* graph, int startVertex, int* visited, int* stack) {
    visited[startVertex] = 1;

    struct Node* mainNode = graph->array[startVertex].head;
    while (mainNode) {
        if (!visited[mainNode->data]) {
            topologicalSort(graph, mainNode->data, visited, stack);
        }
        mainNode = mainNode->next;
    }

    // After visiting all dependencies, push the current vertex to the stack.
    stackPush(stack, startVertex);
}

/**
 * @brief The main function that drives the program.
 */
int main() {
    printf("Hello! Here You Can Perform Following Undirected Graph Operations!\n");
    
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

        // Add edges for an undirected graph.
        addEdge(graph, src, dest);
        addEdge(graph, dest, src);
        printf("\n");
    }

    int choice;
    while (1) {
        printf("\n1. Breadth First Search\n2. Depth First Search\n3. Find All Paths\n4. Check for Cycle\n5. Topological Sort\n6. Exit\nEnter Your Choice:- ");
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
        case 5: {
            // Checking Is Graph is Cyclic, as Toplogical Sort Can't Be Performed on Cyclic Graph
            if (isCyclic(graph)) {
                printf("Cycle Exists! Can't Perform Topological Sort\n");
                break;
            }

            int *visited = (int *) malloc(graph->vertex * sizeof(int));
            int *stack = (int *) malloc(graph->vertex * sizeof(int));
            
            printf("\n");
            pointer = 0;
            for (int i = 0; i < graph->vertex; i++) {
                if (!visited[i]) {
                    topologicalSort(graph, i, visited, stack);
                }
            }

            for (int i = graph->vertex - 1; i >= 0; i--) {
                printf("%d ", stack[i]);
            }
            
            free(visited);
            free(stack);
            break;
        }
        case 6: // Exit
            printf("\nThanks For Using! Have a Great Day!\n");
            // A complete program should free all allocated memory (nodes, lists, graph).
            free(graph->array);
            free(graph);
            return 0;
        default:
            printf("\nPlease Enter a Valid Input!\n");
            break;
        }
    }
    return 0;
}
