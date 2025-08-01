#include <iostream>
using namespace std;

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
            cout << "\nVertex " << i << " Already Exists!";
        } else {
            graph->array[i].head = NULL;
            cout << "\nVertex " << i << " Added!";
        }
    }

    return graph;
}

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

void bfsTraversal(struct Graph* graph, int startVertex, int *visited) {
    struct Node* queue = createNode(startVertex);
    struct Node* lastQueueNode = queue;

    while (queue != NULL) {
        struct Node *temp = queue;

        if (!visited[queue->data]) {
            cout << queue->data << " ";
            visited[queue->data] = 1; //TRUE
        }

        struct Node* mainNode = graph->array[queue->data].head;
        while (mainNode) {
            if (!visited[queue->data]) {
                struct Node *node = createNode(mainNode->data);
                lastQueueNode->next = node;
                lastQueueNode = lastQueueNode->next;
            }
            
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

    cout << startVertex << " ";
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
                cout << path[i];
            } else {
                cout << path[i] << " -> ";
            }
            
        }
        cout << "\n";
        return;
    }

    struct Node* mainNode = graph->array[startVertex].head;
    while (mainNode) {
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

    cout << "\n";

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

    stackPush(stack, startVertex);
    
    return;
}


int main() {
    cout << "Hello! Here You Can Perform Following Directed Graph Operation!\n";
    
    int vertex;
    cout << "\nEnter the Number of Vertices(Node): ";
    cin >> vertex;
    
    struct Graph* graph = createGraph(vertex);

    int edges;

    cout << "\n\nEnter the Number of Edges: ";
    cin >> edges;

    for (int i = 0; i < edges; i++) {
        int src, dest;

        cout << "Enter the Source of Edge " << i + 1 << ": ";
        cin >> src;
        cout << "Enter the Destination of Edge " << i + 1 << ": ";
        cin >> dest;

        if (src > graph->vertex - 1) {
            cout << "\n~~ " << src << " Source Vertex Not Present ~~\n\n";
            i--;
            continue;
        }
        
        if (dest > graph->vertex - 1) {
            cout << "\n~~ " << dest << " Target Vertex Not Present ~~\n\n";
            i--;
            continue;
        }
        
        if (src == dest) {
            cout << "\n~~ Source & Target Can't Be Same ~~\n\n";
            i--;
            continue;
        }

        addEdge(graph, src, dest);
        cout << "\n";
    }

    int choice, choice2;

    while (1) {
        cout << "\n1. Breadth First Search\n2. Depth First Search\n3. Find All Path's\n4. Is Cycle Exists\n5. Topological Sort\n6. Exit\nEnter Your Choice:- ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int *visited = (int *)malloc(graph->vertex * sizeof(int));

            cout << "\n";

            for (int i = 0; i < graph->vertex; i++) {
                bfsTraversal(graph, i, visited);
            }

            cout << "\n";

            free(visited);

            break;
        }
        case 2: {
            int *visited = (int *)malloc(graph->vertex * sizeof(int));

            cout << "\n";

            for (int i = 0; i < graph->vertex; i++) {
                dfsTraversal(graph, i, visited);
            }

            cout << "\n";

            free(visited);

            break;
        }
        case 3: {
            int startVertex, endVertex, index = 0;
            int *path = (int *)malloc(2 * graph->vertex * sizeof(int));

            cout << "\nEnter Start Vertex: ";
            cin >> startVertex;

            cout << "\nEnter End Vertex: ";
            cin >> endVertex;
            
            cout << "\nPaths: \n";
            findAllPaths(graph, path, startVertex, endVertex, index);

            free(path);

            break;
        }
        case 4: {

            if (isCyclic(graph)) {
                cout << "Cycle Exists\n";
            } else {
                cout << "Cycle Does Not Exists\n";
            }

            break;
        }  
        case 5: {
            if (isCyclic(graph)) {
                cout << "Cycle Exists! Can't Perform Topological Sort\n";
                break;
            }

            int *visited = (int *) malloc(graph->vertex * sizeof(int));
            int *stack = (int *) malloc(graph->vertex * sizeof(int));

            cout << "\n";
            pointer = 0;
            for (int i = 0; i < graph->vertex; i++) {
                if (!visited[i]) {
                    topologicalSort(graph, i, visited, stack);
                }
            }
            
            for (int i = graph->vertex - 1; i >= 0; i--) {
                cout << stack[i] << " ";
            }
            
            cout << "\n";

            free(visited);
            free(stack);
            break;
        }
        case 6:
            cout << "Thanks For Using! Have a Great Day!";
            free(graph);
            return 0;
        default:
            cout << "Please Enter a Vaild Input!\n";
            break;
        }
    }

    return 0;
}
