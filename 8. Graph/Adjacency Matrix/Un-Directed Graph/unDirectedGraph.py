class Node:
    def __init__(self, data):
        self.data = data;
        self.next = None;

def addEdge(graph, src, data):
    graph[src][data] = 1;
    return;

def bfsTraversal(graph, startVertex, visited, vertex):
    queue = Node(startVertex);
    lastQueueNode = queue;

    if (visited[startVertex]):
        return;

    while (queue != None):
        current = queue.data;

        print(current, " ",  end="");
        visited[startVertex] = True;

        for neighbour in range(0, vertex):
            value = graph[current][neighbour];

            if (value == 1 and (not visited[neighbour])):
                node = Node(neighbour);

                visited[neighbour] = True;
                lastQueueNode.next = node;
                lastQueueNode = lastQueueNode.next;

        queue = queue.next;

    return;

def dfsTraversal(graph, startVertex, visited, vertex):
    if (visited[startVertex]):
        return;

    print(startVertex, " ", end="");
    visited[startVertex] = True

    for neighbour in range(0, vertex):
        value = graph[startVertex][neighbour];

        if (value == 1 and (not visited[neighbour])):
            dfsTraversal(graph, neighbour, visited, vertex);

    return;

def findAllPaths(graph, path, startVertex, endVertex, vertex, index, visited):
    visited[startVertex] = True;
    path[index] = startVertex;
    
    index += 1;

    if (startVertex == endVertex):
        for i in range(index):
            if (i == index - 1):
                print(path[i]);
            else:
                print(path[i], "-> ", end="");
        return;

    for neighbour in range(0, vertex):
        value = graph[startVertex][neighbour];

        if (value == 1):
            if (not visited[neighbour]):
                visited[neighbour] = True;
                findAllPaths(graph, path, neighbour, endVertex, vertex, index, visited);
                visited[neighbour] = False;

    return;

def isCycleExistsUtils(graph, startVertex, visited, parent, vertex):
    visited[startVertex] = True;

    for neighbour in range(0, vertex):
        value = graph[startVertex][neighbour];

        if (value == 1 and (not visited[neighbour])):
            if (isCycleExistsUtils(graph, neighbour, visited, startVertex, vertex)):
                return True;
        elif (value == 1 and neighbour != parent):
            return True;

    return False;

def isCycleExists(graph, vertex):
    cycleExists = False;
    visited = [False for _ in range(vertex)];

    for i in range(0, vertex):
        if (not visited[i]):
            if (isCycleExistsUtils(graph, i, visited, -1, vertex)):
                cycleExists = True;
                break;

    return cycleExists;

print("Hello! Here You Can Perform Following Un-Directed Graph Operation!\n");

vertex = int(input("Enter the Number of Vertices(Node): "));
    
graph = [[0 for _ in range(vertex)] for _ in range(vertex)];

edges = int(input("\nEnter the Number of Edges: "));


for i in range(edges):
    src = int(input(f"\nEnter the Source of Edge {i + 1}: "));
    dest = int(input(f"Enter the Target of Edge {i + 1}: "));

    if (src > vertex - 1):
        print(f"~~ {src} Source Vertex Not Present ~~\n");
        i -= 1;
        continue;
        
    if (dest > vertex - 1):
        print(f"~~ {dest} Target Vertex Not Present ~~\n");
        i -= 1;
        continue;
        
    if (src == dest):
        print(f"~~ Source & Target Can't Be Same ~~\n")
        i -= 1;
        continue;

    addEdge(graph, src, dest);
    addEdge(graph, dest, src);


while True:
    print("\n1. Breadth First Search\n2. Depth First Search\n3. Find All Path's\n4. Is Cycle Exists\n5. Exit");
    choice = int(input("Enter Your Choice:- "));

    if(choice == 1):
        visited = [False for _ in range(vertex)];

        print();

        for i in range(vertex):
            bfsTraversal(graph, i, visited, vertex);
    
        print();

        continue;

    elif(choice == 2):
        visited = [False for _ in range(vertex)];

        print();

        for i in range(vertex):
            dfsTraversal(graph, i, visited, vertex);

        print();

        continue;
    
    elif(choice == 3):
        index = 0;
        path = [None for _ in range(vertex)];
        visited = [False for _ in range(vertex)];

        startVertex = int(input("\nEnter Start Vertex: "));
        endVertex = int(input("Enter End Vertex: "));
            
        print("\nPaths: ");

        findAllPaths(graph, path, startVertex, endVertex, vertex, index, visited);
    
        continue;
    
    elif(choice == 4):
        if (isCycleExists(graph, vertex)):
            print("\nCycle Exists");
        else:
            print("\nCycle Does Not Exists!");

        continue;

    elif(choice == 5):
        print("Thanks For Using! Have a Great Day!");
        break;

    else:
        print("Please Enter a Vaild Input!\n");
        continue;
