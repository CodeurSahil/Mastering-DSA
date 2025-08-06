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

public class UnDirectedGraph {

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

    public void findAllPaths(Graph graph, int[] path, int startVertex, int endVertex, int index, boolean[] visitedPath) {
        visitedPath[startVertex] = true;
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
            if (!visitedPath[mainNode.data]) {
                visitedPath[mainNode.data] = true;
                findAllPaths(graph, path, mainNode.data, endVertex, index, visitedPath);
                visitedPath[mainNode.data] = false;
            }
            mainNode = mainNode.next;
        }

        return;
    }

    public boolean isCycleExistsUitls(Graph graph, int startVertex, boolean[] visited, int parent) {
        visited[startVertex] = true;

        Node mainNode = graph.array[startVertex].head;
        while (mainNode != null) {
            if (!visited[mainNode.data]) {
                if (isCycleExistsUitls(graph, mainNode.data, visited, startVertex)) {
                    return true;
                }
            } else if (mainNode.data != parent) {
                return true;
            }

            mainNode = mainNode.next;
        }

        return false;
    }

    public boolean isCyclic(Graph graph) {
        boolean cycleExists = false;
        boolean[] visited = new boolean[graph.vertex];

        for (int j = 0; j < graph.vertex; j++) {
            if (!visited[j]) {
                if (isCycleExistsUitls(graph, j, visited, -1)) {
                    cycleExists = true;
                    break;
                }
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
        UnDirectedGraph unDirectedGraph = new UnDirectedGraph();
        System.out.println("Hello! Here You Can Perform Following Directed Graph Operation!\n");

        Scanner scanObj = new Scanner(System.in);

        System.out.print("Enter the Number of Vertices(Node): ");
        int vertex = scanObj.nextInt();

        Graph graph = new Graph(vertex);

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

            unDirectedGraph.addEdge(graph, src, dest);
            unDirectedGraph.addEdge(graph, dest, src);
        }

        while (true) {
            System.out.print(
                    "\n1. Breadth First Search\n2. Depth First Search\n3. Find All Path's\n4. Is Cycle Exists\n5. Exit\nEnter Your Choice:- ");
            int choice = scanObj.nextInt();

            switch (choice) {
                case 1:
                    boolean[] visited = new boolean[vertex];

                    System.out.print("\n");

                    for (int j = 0; j < vertex; j++) {
                        if (!visited[j]) {
                            unDirectedGraph.bfs(graph, j, visited);
                        }
                    }

                    System.out.print("\n");

                    continue;

                case 2:
                    boolean[] visitedDfs = new boolean[vertex];

                    System.out.print("\n");

                    for (int j = 0; j < vertex; j++) {
                        if (!visitedDfs[j]) {
                            unDirectedGraph.dfs(graph, j, visitedDfs);
                        }
                    }

                    System.out.print("\n");

                    continue;

                case 3:
                    int index = 0;
                    int[] path = new int[vertex];
                    boolean[] visitedPath = new boolean[vertex];

                    System.out.print("\nEnter Start Vertex: ");
                    int startVertex = scanObj.nextInt();

                    System.out.print("Enter End Vertex: ");
                    int endVertex = scanObj.nextInt();

                    System.out.print("\nPaths: \n");

                    unDirectedGraph.findAllPaths(graph, path, startVertex, endVertex, index, visitedPath);

                    continue;

                case 4:
                    boolean isCycleExists = unDirectedGraph.isCyclic(graph);

                    if (isCycleExists) {
                        System.out.print("\nCycle Exists\n");
                    } else {
                        System.out.print("\nCycle Does Not Exists\n");
                    }

                    break;

                case 5:
                    System.out.print("Thanks For Using! Have a Great Day!");
                    return;
                default:
                    System.out.print("Please Enter a Vaild Input!\n");
                    continue;
            }
        }

    }
}