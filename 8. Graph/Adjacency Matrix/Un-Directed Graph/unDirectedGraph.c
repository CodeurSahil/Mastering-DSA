#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to create a graph
int** createGraph(int vertex) {
    int** graph = (int**) malloc(vertex * sizeof(int*));

    for (int i = 0; i < vertex; i++) {
        graph[i] = (int*)malloc(vertex * sizeof(int));
    }
    
    return graph;
}

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void addEdge(int** graph, int src, int data) {
    graph[src][data] = 1;
    return;
}

void bfsTraversal(int ** graph, int startVertex, int *visited, int vertex) {
    struct Node* queue = createNode(startVertex);
    struct Node* lastQueueNode = queue;

    if (visited[startVertex]) {
        return;
    }

    while (queue != NULL) {
        int current = queue->data;
        printf("%d ", current);
        visited[startVertex] = 1;
        

        for (int neighbour = 0; neighbour < vertex; neighbour++) {
            int value = graph[current][neighbour];

            if (value && !visited[neighbour]) {
                struct Node *node = createNode(neighbour);
                visited[neighbour] = 1;
                lastQueueNode->next = node;
                lastQueueNode = lastQueueNode->next;
            }
            
        }

        queue = queue->next;
    }

    return;
}

void dfsTraversal(int ** graph, int startVertex, int *visited, int vertex) {
    if (visited[startVertex]) {
        return;
    }
    
    printf("%d ", startVertex);
    visited[startVertex] = 1;

    for (int neighbour = 0; neighbour < vertex; neighbour++) {
        int value = graph[startVertex][neighbour];

        if (value && !visited[neighbour]) {
            dfsTraversal(graph, neighbour, visited, vertex);
        }
    }

    return;
}

void findAllPaths(int ** graph, int *path, int startVertex, int endVertex, int index, int vertex, int* visited) {
    visited[startVertex] = 1;
    path[index++] = startVertex;

    if (startVertex == endVertex) {
        for (int i = 0; i < index; i++) {
            if (i == index - 1) {
                printf("%d", path[i]);
            } else {
                printf("%d -> ", path[i]);
            }
            
        }
        printf("\n");
        return;
    }

    for (int neighbour = 0; neighbour < vertex; neighbour++) {
        int value = graph[startVertex][neighbour];

        if (value) {
            if (!visited[neighbour]) {
                visited[neighbour] = 1;
                findAllPaths(graph, path, neighbour, endVertex, index, vertex, visited);
                visited[neighbour] = 0;
            }
            
        }
    }

    return;
}

int isCycleExistsUtils(int ** graph, int startVertex, int* visited, int parent, int vertex) {
    visited[startVertex] = 1;

    for(int neighbour = 0; neighbour < vertex; neighbour++) {
        int value = graph[startVertex][neighbour];

        if (value && !visited[neighbour]) {
            if (isCycleExistsUtils(graph, neighbour, visited, startVertex, vertex)) {
                return 1;
            }
        } else if (value && neighbour != parent) {
            return 1;
        }
    }

    return 0;
}

int isCycleExists(int** graph, int vertex) {
    int cycleExists = 0;
    int *visited = (int *)malloc(vertex * sizeof(int));

    printf("\n");

    for (int i = 0; i < vertex; i++) {
        if (!visited[i]) {
            if (isCycleExistsUtils(graph, i, visited, -1, vertex)) {
                cycleExists = 1;
                break;
            }
        }
        
    }

    free(visited);
    return cycleExists;
}

int main() {
    printf("Hello! Here You Can Perform Following Directed Graph Operation!\n");
    
    int vertex;
    printf("\nEnter the Number of Vertices(Node): ");
    scanf("%d", &vertex);
    
    int** graph = createGraph(vertex);

    int edges;

    printf("\nEnter the Number of Edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        int src, dest;

        printf("\nEnter the Source of Edge %d: ", i + 1);
        scanf("%d", &src);
        printf("Enter the Destination of Edge %d: ", i + 1);
        scanf("%d", &dest);

        if (src > vertex - 1) {
            printf("\n~~ %d Source Vertex Not Present ~~\n\n", src);
            i--;
            continue;
        }

        if (dest > vertex - 1) {
            printf("\n~~ %d Target Vertex Not Present ~~\n\n", dest);
            i--;
            continue;
        }

        if (src == dest) {
            printf("\n~~ Source & Target Can't Be Same ~~\n\n");
            i--;
            continue;
        }

        addEdge(graph, src, dest);
        addEdge(graph, dest, src);
    }

    int choice;

    while (1) {
        printf("\n1. Breadth First Search\n2. Depth First Search\n3. Find All Path's\n4. Is Cycle Exists\n5. Exit\nEnter Your Choice:- ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: {
            int *visited = (int *)malloc(vertex * sizeof(int));

            printf("\n");

            for (int i = 0; i < vertex; i++) {
                bfsTraversal(graph, i, visited, vertex);
            }

            printf("\n");

            free(visited);

            break;
        }

        case 2: {
            int *visited = (int *)malloc(vertex * sizeof(int));

            printf("\n");

            for (int i = 0; i < vertex; i++) {
                dfsTraversal(graph, i, visited, vertex);
            }

            printf("\n");

            free(visited);

            break;
        }

        case 3: {
            int startVertex, endVertex, index = 0;
            int *path = (int *)malloc(2 * vertex * sizeof(int));
            int *visited = (int *)malloc(vertex * sizeof(int));

            printf("\nEnter Start Vertex: ");
            scanf("%d", &startVertex);

            printf("Enter End Vertex: ");
            scanf("%d", &endVertex);
            
            printf("\nPaths: \n");
            findAllPaths(graph, path, startVertex, endVertex, index, vertex, visited);
            break;
        }

        case 4: {
            if (isCycleExists(graph, vertex)) {
                printf("Cycle Exists!\n");
            } else {
                printf("Cycle Does Not Exists!\n");
            }

            break;
        }

        case 5:
            printf("Thanks For Using! Have a Great Day!");
            free(graph);
            return 0;
        default:
            printf("Please Enter a Vaild Input!\n");
            break;
        }
    }

    return 0;
}
