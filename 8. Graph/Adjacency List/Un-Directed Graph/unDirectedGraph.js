const prompt = require('prompt-sync')({ sigint: true });

class Node {
    constructor(val) {
        this.data = val;
        this.next = null;
    }
}


class AdjList {
    constructor() {
        this.head = null;
    }
}

class Graph {
    constructor(vertex) {
        this.vertex = vertex;
        this.array = [];
        for (let i = 0; i < vertex; i++) {
            this.array[i] = new AdjList();
        }
    }
}

function addEdge(graph, src, dest) {
    let newNode = new Node(dest);

    let temp = graph.array[src].head;

    let prev = temp;

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

function bfs(graph, startVertex, visited, printArr) {
    let queue = new Node(startVertex);
    let lastNode = queue;

    while (queue != null) {
        let temp = queue;

        if (!visited[temp.data]) {
            printArr.push(temp.data);
            visited[temp.data] = true;
        }

        let mainNode = graph.array[temp.data].head;

        while (mainNode != null) {
            if (!visited[mainNode.data]) {
                let newNode = new Node(mainNode.data);
                lastNode.next = newNode;
                lastNode = lastNode.next;
            }
            mainNode = mainNode.next;
        }

        queue = queue.next;
    }

    return;
}

function dfs(graph, startVertex, visited, printArr) {
    if (visited[startVertex]) {
        return;
    }

    printArr.push(startVertex);
    visited[startVertex] = true;

    let mainNode = graph.array[startVertex].head;
    while (mainNode != null) {
        dfs(graph, mainNode.data, visited, printArr);
        mainNode = mainNode.next;
    }

    return;
}

function findAllPaths(graph, path, startVertex, endVertex, index, visited) {
    visited[startVertex] = true;
    path[index] = startVertex;

    index += 1;

    if (startVertex == endVertex) {
        console.log(path.join(" -> "));
        path.pop();
        return;
    }

    let mainNode = graph.array[startVertex].head;

    while (mainNode != null) {
        if (!visited[mainNode.data]) {
            visited[startVertex] = true;
            findAllPaths(graph, path, mainNode.data, endVertex, index, visited);
            visited[mainNode.data] = false;
        }
        mainNode = mainNode.next;
    }

    path.pop();
}

function isCycleExistsUitls(graph, startVertex, visited, parent) {
    visited[startVertex] = true;

    let mainNode = graph.array[startVertex].head;
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

function isCyclic(graph) {
    let cycleExists = false;
    let visited = Array.from({ length: graph.vertex }, () => false);

    for (let j = 0; j < graph.vertex; j++) {
        if (!visited[j]) {
            if (isCycleExistsUitls(graph, j, visited, -1)) {
                cycleExists = true;
                break;
            }
        }
    }

    return cycleExists;
}

(() => {
    let choice;
    console.log("Hello! Here You Can Perform Following Directed Graph Operation!\n");

    const vertex = Number.parseInt(prompt("Enter the Number of Vertices(Node): "));

    let graph = new Graph(vertex);

    const edges = Number.parseInt(prompt("Enter the Number of Edges: "));

    for (let i = 0; i < edges; i++) {
        console.log();
        let src = Number.parseInt(prompt(`Enter the Source of Edge ${i + 1}: `));
        let dest = Number.parseInt(prompt(`Enter the Source of Target ${i + 1}: `));

        if (src > graph.vertex - 1) {
            console.log(`~~ ${src} Source Vertex Not Present ~~\n`);
            i -= 1;
            continue;
        }

        if (dest > graph.vertex - 1) {
            console.log(`~~ ${dest} Target Vertex Not Present ~~\n`);
            i -= 1;
            continue;
        }

        if (src == dest) {
            console.log(`~~ Source & Target Can't Be Same ~~\n`);
            i -= 1;
            continue;
        }

        addEdge(graph, src, dest);
        addEdge(graph, dest, src);
    }

    while (true) {
        console.log("\n1. Breadth First Search\n2. Depth First Search\n3. Find All Path's\n4. Is Cycle Exists\n5. Exit");
        choice = Number.parseInt(prompt("Enter Your Choice:- "));

        switch (choice) {
            case 1:
                var visited = Array.from({ length: vertex }, () => false);
                var printArr = [];

                console.log();

                for (let j = 0; j < vertex; j++) {
                    if (!visited[j]) {
                        bfs(graph, j, visited, printArr);
                    }
                }

                console.log(printArr.join(" -> "));

                continue;

            case 2:
                var visited = Array.from({ length: vertex }, () => false);
                var printArr = [];

                console.log();

                for (let j = 0; j < vertex; j++) {
                    if (!visited[j]) {
                        dfs(graph, j, visited, printArr);
                    }
                }

                console.log(printArr.join(" -> "));

                continue;

            case 3:
                let index = 0;
                let path = [];

                console.log();

                var visited = Array.from({ length: vertex }, () => false);
                let startVertex = Number.parseInt(prompt("Enter Start Vertex: "));
                let endVertex = Number.parseInt(prompt("Enter End Vertex: "));

                console.log("\nPaths: ");

                findAllPaths(graph, path, startVertex, endVertex, index, visited);

                continue;

            case 4:
                let isCycleExists = isCyclic(graph);

                if (isCycleExists) {
                    console.log("\nCycle Exists");
                } else {
                    console.log("\nCycle Does Not Exists");
                }

                break;

            case 5:
                console.log("Thanks For Using! Have a Great Day!");
                return;

            default:
                console.log("Please Enter a Vaild Input!\n");
                continue;
        }
    }
    return;
})();