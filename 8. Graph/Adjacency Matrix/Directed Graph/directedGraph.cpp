#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

int pointer = 0;

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
        cout << current << " ";
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
    
    cout << startVertex << " ";
    visited[startVertex] = 1;

    for (int neighbour = 0; neighbour < vertex; neighbour++) {
        int value = graph[startVertex][neighbour];

        if (value && !visited[neighbour]) {
            dfsTraversal(graph, neighbour, visited, vertex);
        }
    }

    return;
}

void findAllPaths(int ** graph, int *path, int startVertex, int endVertex, int index, int vertex) {
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

    for (int neighbour = 0; neighbour < vertex; neighbour++) {
        int value = graph[startVertex][neighbour];

        if (value) {
            findAllPaths(graph, path, neighbour, endVertex, index, vertex);
        }
    }

    return;
}

int isCycleExistsUtils(int ** graph, int startVertex, int* visited, int* recursion, int vertex) {
    visited[startVertex] = 1;
    recursion[startVertex] = 1;

    for(int neighbour = 0; neighbour < vertex; neighbour++) {
        int value = graph[startVertex][neighbour];

        if (value && recursion[neighbour]) {
            return 1;
        } else if (value && !visited[neighbour] && isCycleExistsUtils(graph, neighbour, visited, recursion, vertex)) {
            return 1;
        }
    }

    recursion[startVertex] = 0;

    return 0;
}

int isCycleExists(int** graph, int vertex) {
    int cycleExists = 0;
    int *visited = (int *)malloc(vertex * sizeof(int));

    cout << "\n";

    for (int i = 0; i < vertex; i++) {
        int *recursion = (int *)malloc(vertex * sizeof(int));
        if (isCycleExistsUtils(graph, i, visited, recursion, vertex)) {
            free(recursion);
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

void topologicalSort(int** graph, int startVertex, int* visited, int* stack, int vertex) {
    if (visited[startVertex]) {
        return;
    }

    visited[startVertex] = 1;

    for (int neighbour = 0; neighbour < vertex; neighbour++) {
        int value = graph[startVertex][neighbour];

        if (value && !visited[neighbour] && neighbour != startVertex) {
            topologicalSort(graph, neighbour, visited, stack, vertex);
        }
    }

    stackPush(stack, startVertex);
    
    return;
}

int main() {

    cout << "Hello! Here You Can Perform Following Directed Graph Operation!\n";
    
    int vertex;
    cout << "\nEnter the Number of Vertices(Node): ";
    cin >> vertex;
    
    int** graph = createGraph(vertex);

    int edges;

    cout << "\nEnter the Number of Edges: ";
    cin >> edges;

    for (int i = 0; i < edges; i++) {
        int src, dest;

        cout << "\nEnter the Source of Edge " << i + 1 << ": ";
        cin >> src;

        cout << "Enter the Destination of Edge " << i + 1 << ": ";
        cin >> dest;

        if (src > vertex - 1) {
            cout << "\n~~ " << src << " Source Vertex Not Present ~~\n\n";
            i--;
            continue;
        }
        
        if (dest > vertex - 1) {
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
    }

    int choice;

    while (1) {
        cout << "\n1. Breadth First Search\n2. Depth First Search\n3. Find All Path's\n4. Is Cycle Exists\n5. Topological Sort\n6. Exit\nEnter Your Choice:- ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int *visited = (int *)malloc(vertex * sizeof(int));

            cout << "\n";

            for (int i = 0; i < vertex; i++) {
                bfsTraversal(graph, i, visited, vertex);
            }

            cout << "\n";

            free(visited);

            break;
        }

        case 2: {
            int *visited = (int *)malloc(vertex * sizeof(int));

            cout << "\n";

            for (int i = 0; i < vertex; i++) {
                dfsTraversal(graph, i, visited, vertex);
            }

            cout << "\n";

            free(visited);

            break;
        }

        case 3: {
            int startVertex, endVertex, index = 0;
            int *path = (int *)malloc(2 * vertex * sizeof(int));

            cout << "\nEnter Start Vertex: ";
            cin >> startVertex;
            
            cout << "Enter End Vertex: ";
            cin >> endVertex;
            
            cout << "\nPaths: \n";
            findAllPaths(graph, path, startVertex, endVertex, index, vertex);
            break;
        }

        case 4: {
            if (isCycleExists(graph, vertex)) {
                cout << "Cycle Exists!\n";
            } else {
                cout << "Cycle Does Not Exists!\n";
            }

            break;
        }

        case 5: {
            if (isCycleExists(graph, vertex)) {
                cout << "Cycle Exists! Can't Perform Topological Sort\n";
            }
            
            int *visited = (int *)malloc(vertex * sizeof(int));
            int *stack = (int *)malloc(vertex * sizeof(int));

            pointer = 0;

            cout << "\n";

            for (int i = 0; i < vertex; i++) {
                if (!visited[i]) {
                    topologicalSort(graph, i, visited, stack, vertex);
                }
            }

            for (int i = vertex - 1; i >= 0; i--) {
                cout << stack[i] << " ";
            }

            cout << "\n";

            free(visited);

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
