import java.util.Scanner;

class Node {
    int data;
    Node next;

     Node(int data) {
        this.data = data;
        this.next = null;
    }
};

public class UnDirectedGraph {

    public void addEdge(int[][] graph, int src, int data) {
        graph[src][data] = 1;
        return;
    }

    public void bfsTraversal(int[][] graph, int startVertex, boolean[] visited, int vertex) {
        Node queue = new Node(startVertex);
        Node lastQueueNode = queue;

        if (visited[startVertex]) {
            return;
        }

        while (queue != null) {
            int current = queue.data;

            System.out.format("%d ", current);
            visited[startVertex] = true;

            for (int neighbour = 0; neighbour < vertex; neighbour++) {
                int value = graph[current][neighbour];

                if (value == 1 && !visited[neighbour]) {
                    Node node = new Node(neighbour);
                    visited[neighbour] = true;
                    lastQueueNode.next = node;
                    lastQueueNode = lastQueueNode.next;
                }

            }

            queue = queue.next;
        }

        return;
    }

    public void dfsTraversal(int[][] graph, int startVertex, boolean[] visited, int vertex) {
        if (visited[startVertex]) {
            return;
        }

        System.out.format("%d ", startVertex);
        visited[startVertex] = true;

        for (int neighbour = 0; neighbour < vertex; neighbour++) {
            int value = graph[startVertex][neighbour];

            if (value == 1 && !visited[neighbour]) {
                dfsTraversal(graph, neighbour, visited, vertex);
            }
        }

        return;
    }

    public void findAllPaths(int[][] graph, int[] path, int startVertex, int endVertex, int index, int vertex, boolean[] visited) {
        visited[startVertex] = true;
        path[index++] = startVertex;

        if (startVertex == endVertex) {
            for (int i = 0; i < index; i++) {
                if (i == index - 1) {
                    System.out.format("%d", path[i]);
                } else {
                    System.out.format("%d -> ", path[i]);
                }

            }
            System.out.format("\n");
            return;
        }

        for (int neighbour = 0; neighbour < vertex; neighbour++) {
            int value = graph[startVertex][neighbour];

            if (value == 1) {
                if (!visited[neighbour]) {
                    visited[neighbour] = true;
                    findAllPaths(graph, path, neighbour, endVertex, index, vertex, visited);
                    visited[neighbour] = false;
                }
            }
        }

        return;
    }

    public boolean isCycleExistsUtils(int[][] graph, int startVertex, boolean[] visited, int parent, int vertex) {
        visited[startVertex] = true;

        for (int neighbour = 0; neighbour < vertex; neighbour++) {
            int value = graph[startVertex][neighbour];

            if (value == 1 && !visited[neighbour]) {
                if (isCycleExistsUtils(graph, neighbour, visited, startVertex, vertex)) {
                    return true;
                }
            } else if (value == 1 && neighbour != parent) {
                return true;
            }
        }

        return false;
    }

    public boolean isCycleExists(int[][] graph, int vertex) {
        boolean cycleExists = false;
        boolean[] visited = new boolean[vertex];

        System.out.format("\n");

        for (int i = 0; i < vertex; i++) {
            if (!visited[i]) {
                if (isCycleExistsUtils(graph, i, visited, -1, vertex)) {
                    cycleExists = true;
                    break;
                }
            }
        }

        return cycleExists;
    }

    public static void main(String[] args) {
        UnDirectedGraph UDG = new UnDirectedGraph();
        System.out.format("Hello! Here You Can Perform Following Directed Graph Operation!\n");

        Scanner scanObj = new Scanner(System.in);

        System.out.format("\nEnter the Number of Vertices(Node): ");
        int vertex = scanObj.nextInt();

        int[][] graph = new int[vertex][vertex];

        System.out.format("\nEnter the Number of Edges: ");
        int edges = scanObj.nextInt();

        for (int i = 0; i < edges; i++) {

            System.out.format("\nEnter the Source of Edge %d: ", i + 1);
            int src = scanObj.nextInt();
            System.out.format("Enter the Destination of Edge %d: ", i + 1);
            int dest = scanObj.nextInt();

            if (src > vertex - 1) {
                System.out.format("\n~~ %d Source Vertex Not Present ~~\n\n", src);
                i--;
                continue;
            }

            if (dest > vertex - 1) {
                System.out.format("\n~~ %d Target Vertex Not Present ~~\n\n", dest);
                i--;
                continue;
            }

            if (src == dest) {
                System.out.format("\n~~ Source & Target Can't Be Same ~~\n\n");
                i--;
                continue;
            }

            UDG.addEdge(graph, src, dest);
            UDG.addEdge(graph, dest, src);
        }

        int choice;

        while (true) {
            System.out.format(
                    "\n1. Breadth First Search\n2. Depth First Search\n3. Find All Path's\n4. Is Cycle Exists\n5. Exit\nEnter Your Choice:- ");
            choice = scanObj.nextInt();

            switch (choice) {
                case 1: {
                    boolean[] visited = new boolean[vertex];

                    System.out.format("\n");

                    for (int i = 0; i < vertex; i++) {
                        UDG.bfsTraversal(graph, i, visited, vertex);
                    }

                    System.out.format("\n");

                    break;
                }

                case 2: {
                    boolean[] visited = new boolean[vertex];

                    System.out.format("\n");

                    for (int i = 0; i < vertex; i++) {
                        UDG.dfsTraversal(graph, i, visited, vertex);
                    }

                    System.out.format("\n");

                    break;
                }

                case 3: {
                    int startVertex, endVertex, index = 0;
                    int[] path = new int[vertex];
                    boolean[] visited = new boolean[vertex];

                    System.out.format("\nEnter Start Vertex: ");
                    startVertex = scanObj.nextInt();

                    System.out.format("Enter End Vertex: ");
                    endVertex = scanObj.nextInt();

                    System.out.format("\nPaths: \n");
                    UDG.findAllPaths(graph, path, startVertex, endVertex, index, vertex, visited);

                    break;
                }

                case 4: {
                    if (UDG.isCycleExists(graph, vertex)) {
                        System.out.format("Cycle Exists!\n");
                    } else {
                        System.out.format("Cycle Does Not Exists!\n");
                    }

                    break;
                }

                case 5:
                    System.out.format("Thanks For Using! Have a Great Day!");
                    return;
                default:
                    System.out.format("Please Enter a Vaild Input!\n");
                    break;
            }
        }
    }
}