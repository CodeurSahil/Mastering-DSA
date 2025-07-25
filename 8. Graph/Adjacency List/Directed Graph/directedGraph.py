class Node:
    def __init__(self, data):
        self.data = data;
        self.next = None;


class AdjList:
    def __init__(self):
        self.head = None;

class Graph:
    def __init__(self, vertex):
        self.vertex = vertex;
        self.array = [AdjList() for _ in range(vertex)];

pointer = 0;

# Graph Visualization
#         Graph
#         /   \
#     vertex   array (AdjList[])
#                 |
#               head
#             /      \
#     data = index  next
#

def createNode(data):
    return Node(data);

def createGraph(vertex):
    graph = Graph(vertex);

    for i in range(vertex):
        graph.array[i] = AdjList();
        print("Vertex", i, "Added!")

    return graph;

def addEdge(graph, src, data):
    newNode = createNode(data);

    temp = graph.array[src].head;

    prev = temp;

    if (temp == None or temp.data >= data):
        newNode.next = temp;
        graph.array[src].head = newNode;
        return;

    while (temp != None and temp.data < data):
        prev = temp;
        temp = temp.next;
    
    newNode.next = temp;
    prev.next = newNode;

def bfsTraversal(graph, startVertex, visited):
    queue = [];
    queue.insert(0, startVertex);

    while (len(queue) != 0):
        queueLen = len(queue);
        
        if (not visited[queue[queueLen - 1]]):
            print(queue[queueLen - 1], " ", end="");
            visited[queue[queueLen - 1]] = True;

        mainNode = graph.array[queue[queueLen - 1]].head;

        while (mainNode):
            if (not visited[queue[queueLen - 1]]):
                queue.insert(0, mainNode.data);
            mainNode = mainNode.next;

        queue.pop();

def dfsTraversal(graph, startVertex, visited):
    if (visited[startVertex]):
        return;

    print(startVertex, " ", end="");
    visited[startVertex] = True;

    mainNode = graph.array[startVertex].head;
    while (mainNode):
        dfsTraversal(graph, mainNode.data, visited);
        mainNode = mainNode.next;

def findAllPaths(graph, path, startVertex, endVertex, index):
    path[index] = startVertex;
    
    index += 1;

    if (startVertex == endVertex):
        for i in range(index):
            if (i == index - 1):
                print(path[i]);
            else:
                print(path[i], " -> ", end="");
        return;

    mainNode = graph.array[startVertex].head;

    while (mainNode):
        findAllPaths(graph, path, mainNode.data, endVertex, index);
        mainNode = mainNode.next;

def isCycleExistsUitls(graph, startVertex, visited, recursion):
    visited[startVertex] = True;
    recursion[startVertex] = True;

    mainNode = graph.array[startVertex].head;
    while (mainNode):
        if (recursion[mainNode.data]):
            return True;
        
        if (not visited[mainNode.data] and isCycleExistsUitls(graph, mainNode.data, visited, recursion)):
            return True;

        mainNode = mainNode.next;

    recursion[startVertex] = False;

    return False;

def isCyclic(graph):
    cycleExists = False;
    visited = [False for _ in range(graph.vertex)];
    recusion = [False for _ in range(graph.vertex)];

    for i in range(graph.vertex):

        if (isCycleExistsUitls(graph, i, visited, recusion)):
            cycleExists = True;
            break;

    return cycleExists;

def topologicalSort(graph, startVertex, visited, stack):
    visited[startVertex] = True;

    mainNode = graph.array[startVertex].head;
    while (mainNode):
        if (not visited[mainNode.data]):
            topologicalSort(graph, mainNode.data, visited, stack);
        mainNode = mainNode.next;

    stack.insert(0, str(startVertex));
    
    return;


print("Hello! Here You Can Perform Following Directed Graph Operation!\n");

vertex = int(input("Enter the Number of Vertices(Node): "));
    
graph = createGraph(vertex);

edges = int(input("\nEnter the Number of Edges: "));


for i in range(edges):
    src = int(input(f"\nEnter the Source of Edge {i + 1}: "));
    dest = int(input(f"Enter the Target of Edge {i + 1}: "));

    if (src > graph.vertex - 1):
        print(f"~~ {src} Source Vertex Not Present ~~\n");
        i -= 1;
        continue;
        
    if (dest > graph.vertex - 1):
        print(f"~~ {dest} Target Vertex Not Present ~~\n");
        i -= 1;
        continue;
        
    if (src == dest):
        print(f"~~ Source & Target Can't Be Same ~~\n")
            # cout << "\n~~ Source & Target Can't Be Same ~~\n\n";
        i -= 1;
        continue;

    addEdge(graph, src, dest);


while True:
    print("\n1. Breadth First Search\n2. Depth First Search\n3. Find All Path's\n4. Is Cycle Exists\n5. Topological Sort\n6. Exit");
    choice = int(input("Enter Your Choice:- "));

    if(choice == 1):
        visited = [False for _ in range(graph.vertex)];

        print();

        for i in range(graph.vertex):
            bfsTraversal(graph, i, visited);
    
        print();

        continue;

    elif(choice == 2):
        visited = [False for _ in range(graph.vertex)];

        print();

        for i in range(graph.vertex):
            dfsTraversal(graph, i, visited);

        print();

        continue;
    
    elif(choice == 3):
        index = 0;
        path = [None for _ in range(vertex)];

        startVertex = int(input("\nEnter Start Vertex: "));
        endVertex = int(input("Enter End Vertex: "));
            
        print("\nPaths: ");

        findAllPaths(graph, path, startVertex, endVertex, index);
    
        continue;
    
    elif(choice == 4):
        if (isCyclic(graph)):
            print("\nCycle Exists");
        else:
            print("\nCycle Does Not Exists!");

        continue;

    elif(choice == 5):
        if (isCyclic(graph)):
            print("Cycle Exists! Can't Perform Topological Sort\n");
            continue;

        visited = [False for _ in range(graph.vertex)];
        stack = [];

        pointer = 0;

        for i in range(graph.vertex):
            if (not visited[i]):
                topologicalSort(graph, i, visited, stack);
        
        str = " -> ".join(stack);

        print(str);
        
        continue;
    
    elif(choice == 6):
        print("Thanks For Using! Have a Great Day!");
        break;

    else:
        print("Please Enter a Vaild Input!\n");
        continue;
