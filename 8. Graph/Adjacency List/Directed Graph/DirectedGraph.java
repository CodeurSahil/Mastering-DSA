import java.util.Scanner;

class Node {
    public int data;
    public Node next;

    public Node(int data) {
        this.data = data;
    }
}

class AdjList {
    public Node head;
}

class Graph {
    public int vertex;
    public AdjList[] array;

    public Graph(int vertex) {
        this.vertex = vertex;
        this.array = new AdjList[vertex];

        for (int i = 0; i < vertex; i++) {
            this.array[i] = new AdjList();
        }
    }
}

class Stack {
    public int top = 0;
    public int[] stack;

    public Stack(int size) {
        this.stack = new int[size];
    }

    public void push(int data) {
        this.stack[this.top] = data;
        this.top++;
        return;
    }

    public int pop() {
        this.top--;

        if (this.top == -1) {
            return -1;
        }

        return this.stack[this.top];
    }
}

public class DirectedGraph {

    public void addEdge(Graph graph, int src, int dest) {
        Node newNode = new Node(dest);

        Node temp = graph.array[src].head;

        Node prev = temp;

        if (temp == null || temp.data >= dest) {
            newNode.next = temp;
            graph.array[src].head = newNode;
            return;
        }

        while (temp != null && temp.data < dest) {
            prev = temp;
            temp = temp.next;
        }
    
        newNode.next = temp;
        prev.next = newNode;

        return;
    }

    public void bfs(Graph graph, int startVertex, boolean[] visited) {
        Node queue = new Node(startVertex);
        Node lastNode = queue;

        while (queue != null) {
            Node temp = queue;

            if (!visited[temp.data]) {
                System.out.format("%d ", temp.data);
                visited[temp.data] = true;
            }

            Node mainNode = graph.array[temp.data].head;

            while (mainNode != null) {
                if (!visited[mainNode.data]) {
                    Node newNode = new Node(mainNode.data);
                    lastNode.next = newNode;
                    lastNode = lastNode.next;
                }
                mainNode = mainNode.next;
            }

            queue = queue.next;
        }

        return;
    }

    public void dfs(Graph graph, int startVertex, boolean[] visited) {
        if (visited[startVertex]) {
            return;
        }

        System.err.format("%d ", startVertex);
        visited[startVertex] = true;

        Node mainNode = graph.array[startVertex].head;
        while (mainNode != null) {
            dfs(graph, mainNode.data, visited);
            mainNode = mainNode.next;
        }

        return;
    }

    public void findAllPaths(Graph graph, int[] path, int startVertex, int endVertex, int index) {
        path[index] = startVertex;

        index += 1;

        if (startVertex == endVertex) {
            for (int i = 0; i < index; i++) {
                if (i == index - 1) {
                    System.out.format("%d\n", path[i]);
                } else {
                    System.out.format("%d -> ", path[i]);
                }
            }
            return;
        }

        Node mainNode = graph.array[startVertex].head;

        while (mainNode != null) {
            findAllPaths(graph, path, mainNode.data, endVertex, index);
            mainNode = mainNode.next;
        }
    }

    public boolean isCycleExistsUitls(Graph graph, int startVertex, boolean[] visited, boolean[] recursion) {
        visited[startVertex] = true;
        recursion[startVertex] = true;

        Node mainNode = graph.array[startVertex].head;
        while (mainNode != null) {
            if (recursion[mainNode.data]) {
                return true;
            }

            if (!visited[mainNode.data] && isCycleExistsUitls(graph, mainNode.data, visited, recursion)) {
                return true;
            }

            mainNode = mainNode.next;
        }

        recursion[startVertex] = false;

        return false;
    }

    public boolean isCyclic(Graph graph) {
        boolean cycleExists = false;
        boolean[] visited = new boolean[graph.vertex];
        boolean[] recusion = new boolean[graph.vertex];

        for (int j = 0; j < graph.vertex; j++) {
            if (isCycleExistsUitls(graph, j, visited, recusion)) {
                cycleExists = true;
                break;
            }
        }

        return cycleExists;
    }

    public void topologicalSort(Graph graph, int startVertex, boolean[] visited, Stack stack, int pointer) {
        visited[startVertex] = true;
    
        Node mainNode = graph.array[startVertex].head;
        while (mainNode != null) {
            if (!visited[mainNode.data]) {
                topologicalSort(graph, mainNode.data, visited, stack, pointer);
            }
            mainNode = mainNode.next;
        }
    
        stack.push(startVertex);
        pointer++;
        
        return;
    }

    public static void main(String[] args) {
        DirectedGraph directedGraph = new DirectedGraph();
        System.out.println("Hello! Here You Can Perform Following Directed Graph Operation!\n");

        Scanner scanObj = new Scanner(System.in);

        System.out.print("Enter the Number of Vertices(Node): ");
        int vertex = scanObj.nextInt();

        Graph graph = new Graph(vertex);
        System.out.println("🛢️ ~ DirectedGraph.java:182 -> graph: " + graph);

        System.out.print("\nEnter the Number of Edges: ");
        int edges = scanObj.nextInt();

        for (int i = 0; i < edges; i++) {
            System.out.format("\nEnter the Source of Edge %d: ", i + 1);
            int src = scanObj.nextInt();

            System.out.format("Enter the Target of Edge %d: ", i + 1);
            int dest = scanObj.nextInt();

            if (src > graph.vertex - 1) {
                System.out.format("~~ %d Source Vertex Not Present ~~\n", src);
                i -= 1;
                continue;
            }

            if (dest > graph.vertex - 1) {
                System.out.format("~~ %d Target Vertex Not Present ~~\n", dest);
                i -= 1;
                continue;
            }

            if (src == dest) {
                System.out.format("~~ Source & Target Can't Be Same ~~\n");
                i -= 1;
                continue;
            }

            directedGraph.addEdge(graph, src, dest);
        }

        while (true) {
            System.out.print(
                    "\n1. Breadth First Search\n2. Depth First Search\n3. Find All Path's\n4. Is Cycle Exists\n5. Topological Sort\n6. Exit\nEnter Your Choice:- ");
            int choice = scanObj.nextInt();

            switch (choice) {
                case 1:
                    boolean[] visited = new boolean[vertex];

                    System.out.print("\n");

                    for (int j = 0; j < vertex; j++) {
                        if (!visited[j]) {
                            directedGraph.bfs(graph, j, visited);
                        }
                    }

                    System.out.print("\n");

                    continue;

                case 2:
                    boolean[] visitedDfs = new boolean[vertex];

                    System.out.print("\n");

                    for (int j = 0; j < vertex; j++) {
                        if (!visitedDfs[j]) {
                            directedGraph.dfs(graph, j, visitedDfs);
                        }
                    }

                    System.out.print("\n");

                    continue;

                case 3:
                    int index = 0;
                    int[] path = new int[vertex];

                    System.out.print("\nEnter Start Vertex: ");
                    int startVertex = scanObj.nextInt();

                    System.out.print("Enter End Vertex: ");
                    int endVertex = scanObj.nextInt();

                    System.out.print("\nPaths: \n");

                    directedGraph.findAllPaths(graph, path, startVertex, endVertex, index);

                    continue;

                case 4:
                    boolean isCycleExists = directedGraph.isCyclic(graph);

                    if (isCycleExists) {
                        System.out.print("\nCycle Exists\n");
                    } else {
                        System.out.print("\nCycle Does Not Exists\n");
                    }

                    break;

                case 5:
                    if (directedGraph.isCyclic(graph)) {
                        System.out.print("Cycle Exists! Can't Perform Topological Sort\n");
                        continue;
                    }

                    boolean[] visitedTopo = new boolean[vertex];
                    Stack stack = new Stack(vertex);

                    System.out.print("\n");
                    int pointer = 0;
                    for (int i = 0; i < graph.vertex; i++) {
                        if (!visitedTopo[i]) {
                            directedGraph.topologicalSort(graph, i, visitedTopo, stack, pointer);
                        }
                    }

                    int val;

                    while (true) {
                        val = stack.pop();

                        if (val == -1) {
                            break;
                        }

                        System.out.format("%d ", val);
                    }

                    System.out.print("\n");

                    continue;

                case 6:
                    System.out.print("Thanks For Using! Have a Great Day!");
                    return;
                default:
                    System.out.print("Please Enter a Vaild Input!\n");
                    continue;
            }
        }

    }
}