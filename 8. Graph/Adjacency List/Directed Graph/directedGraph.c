#include <stdio.h>
#include <stdlib.h>

// Structure for an adjacency list node
struct Node {
    int data;
    struct Node* next;
};

// Structure for an adjacency list
struct AdjList {
    struct Node* head;
};

// Structure for the graph
struct Graph {
    int vertex;
    struct AdjList* array;
};

int pointer = 0;

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

// Function to create a new adjacency list node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph
struct Graph* createGraph(int vertex) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->vertex = vertex;

    // Create an array of adjacency lists
    graph->array = (struct AdjList*) malloc(vertex * sizeof(struct AdjList));

    // Initialize each adjacency list as empty
    for (int i = 0; i < vertex; ++i) {
        if (graph->array[i].head) {
            printf("\nVertex %d Already Exists!", i);
        } else {
            graph->array[i].head = NULL;
            printf("\nVertex %d Added!", i);
        }
    }

    return graph;
}

// Add a directed edge from src to data
// void addEdge(struct Graph* graph, int src, int data) {
//     struct Node* newNode = createNode(data);
//     newNode->next = graph->array[src].head;
//     graph->array[src].head = newNode;
// }

void addEdge(struct Graph* graph, int src, int data) {
    struct Node* newNode = createNode(data);

    struct Node *temp = graph->array[src].head;
    struct Node *prev = temp;

    if (temp == NULL || temp->data >= data) {
        newNode->next = temp;
        graph->array[src].head = newNode;
        return;
    }

    while (temp != NULL && temp->data < data) {
        prev = temp;
        temp = temp->next;
    }
    
    newNode->next = temp;
    prev->next = newNode;
}

// Print the graph
// void printGraph(struct Graph* graph) {
//     for (int v = 0; v < graph->vertex; ++v) {
//         struct Node* temp = graph->array[v].head;
//         printf("\n Adjacency List of vertex %d\n head", v);
//         while (temp) {
//             printf(" -> %d", temp->data);
//             temp = temp->next;
//         }
//         printf("\n");
//     }
// }

// void deleteNode(struct Graph* graph, int toBeDeletedVertex) {
//     if (toBeDeletedVertex >= graph->vertex) {
//         printf("\n~Vertex Not Present~\n");
//     }
    
//     for (int v = 0; v < graph->vertex; ++v) {
//         struct Node* temp = graph->array[v].head;

//         if (temp->data == toBeDeletedVertex) {
//             graph->array[v].head = temp->next;
//             printf("\nEdge Deleted %d to %d", v, toBeDeletedVertex);
//             continue;
//         }
        
//         struct Node* prev = graph->array[v].head;

//         while (temp) {
//             if (temp->data == toBeDeletedVertex) {
//                 printf("\nEdge Deleted %d to %d", v, toBeDeletedVertex);
//                 prev->next = temp->next;
//                 break;
//             }
//             prev = temp;
//             temp = temp->next;
//         }
//     }

//     graph->array[toBeDeletedVertex].head = NULL;

//     return;
// }

void bfsTraversal(struct Graph* graph, int startVertex, int *visited) {
    struct Node* queue = createNode(startVertex);
    struct Node* lastQueueNode = queue;

    while (queue != NULL) {
        struct Node *temp = queue;

        if (!visited[queue->data]) {
            printf("%d ", queue->data);
            visited[queue->data] = 1; //TRUE
        }

        struct Node* mainNode = graph->array[queue->data].head;
        while (mainNode) {
            struct Node *node = createNode(mainNode->data);
            lastQueueNode->next = node;
            lastQueueNode = lastQueueNode->next;
            mainNode = mainNode->next;
        }

        queue = queue->next;
        free(temp);
    }
}

void dfsTraversal(struct Graph* graph, int startVertex, int *visited) {
    if (visited[startVertex]) {
        return;
    }

    printf("%d ", startVertex);
    visited[startVertex] = 1;

    struct Node* mainNode = graph->array[startVertex].head;
    while (mainNode) {
        dfsTraversal(graph, mainNode->data, visited);
        mainNode = mainNode->next;
    }
}

void findAllPaths(struct Graph* graph, int *path, int startVertex, int endVertex, int index) {
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

    struct Node* mainNode = graph->array[startVertex].head;
    while (mainNode) {
        // if (mainNode)
        // {
        //     /* code */
        // }
        findAllPaths(graph, path, mainNode->data, endVertex, index);
        mainNode = mainNode->next;
        
    }
}

int isCycleExistsUitls(struct Graph* graph, int startVertex, int *visited, int *recursion) {
    visited[startVertex] = 1;
    recursion[startVertex] = 1;

    struct Node* mainNode = graph->array[startVertex].head;
    while (mainNode) {
        if (recursion[mainNode->data]) {
            return 1;
        }
        
        if (!visited[mainNode->data] && isCycleExistsUitls(graph, mainNode->data, visited, recursion)) {
            return 1;
        }

        mainNode = mainNode->next;
    }

    recursion[startVertex] = 0;

    return 0;
}

int isCyclic(struct Graph* graph) {
    int cycleExists = 0;
    int *visited = (int *)malloc(graph->vertex * sizeof(int));
    int *recusion = (int *)malloc(graph->vertex * sizeof(int));

    printf("\n");

    for (int i = 0; i < graph->vertex; i++) {

        if (isCycleExistsUitls(graph, i, visited, recusion)) {
            cycleExists = 1;
            break;
        }
    }

    free(visited);

    return cycleExists;
}

void stackPush(int *stack, int data) {
    stack[pointer] = data;
    pointer += 1;
    return;
}

void topologicalSort(struct Graph* graph, int startVertex, int *visited, int *stack) {
    visited[startVertex] = 1;

    struct Node* mainNode = graph->array[startVertex].head;
    while (mainNode) {
        if (!visited[mainNode->data]) {
            topologicalSort(graph, mainNode->data, visited, stack);
        }
        mainNode = mainNode->next;
    }

    // printf("startVertex %d", startVertex);
    // stack[index++] = startVertex;
    stackPush(stack, startVertex);
    
    return;
}


int main() {
    printf("Hello! Here You Can Perform Following Directed Graph Operation!\n");
    
    int vertex;
    printf("\nEnter the Number of Vertices(Node): ");
    scanf("%d", &vertex);
    
    struct Graph* graph = createGraph(vertex);

    int edges;

    printf("\n\nEnter the Number of Edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        int src, dest;

        printf("Enter the Source of Edge %d: ", i + 1);
        scanf("%d", &src);
        printf("Enter the Destination of Edge %d: ", i + 1);
        scanf("%d", &dest);

        if (src > graph->vertex - 1) {
            printf("\n~~ %d Source Vertex Not Present ~~\n\n", src);
            i--;
            continue;
        }

        if (dest > graph->vertex - 1) {
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
        printf("\n");
    }

    int choice, choice2;

    while (1) {
        printf("\n1. Breadth First Search\n2. Depth First Search\n3. Find All Path's\n4. Is Cycle Exists\n5. Topological Sort\n6. Exit\nEnter Your Choice:- ");
        scanf("%d", &choice);

        switch (choice) {
        case 1: {
            int *visited = (int *)malloc(graph->vertex * sizeof(int));

            printf("\n");

            for (int i = 0; i < graph->vertex; i++) {
                bfsTraversal(graph, i, visited);
            }

            printf("\n");

            free(visited);

            break;
        }
        case 2: {
            int *visited = (int *)malloc(graph->vertex * sizeof(int));

            printf("\n");

            for (int i = 0; i < graph->vertex; i++) {
                dfsTraversal(graph, i, visited);
            }

            printf("\n");

            free(visited);

            break;
        }
        case 3: {
            int startVertex, endVertex, index = 0;
            int *path = (int *)malloc(2 * graph->vertex * sizeof(int));

            printf("\nEnter Start Vertex: ");
            scanf("%d", &startVertex);

            printf("\nEnter End Vertex: ");
            scanf("%d", &endVertex);
            
            printf("\nPaths: \n");
            findAllPaths(graph, path, startVertex, endVertex, index);

            free(path);

            break;
        }
        case 4: {

            if (isCyclic(graph)) {
                printf("Cycle Exists\n");
            } else {
                printf("Cycle Does Not Exists\n");
            }

            break;
        }  
        case 5: {
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
        case 6:
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
