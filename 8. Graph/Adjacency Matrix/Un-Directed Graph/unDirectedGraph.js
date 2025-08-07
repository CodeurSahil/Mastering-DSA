const prompt = require('prompt-sync')({ sigint: true });

class Node {
    constructor(data) {
        this.data = data;
        this.next = null;
    }
};

function addEdge(graph, src, data) {
    graph[src][data] = 1;
    return;
}

function bfsTraversal(graph, startVertex, visited, vertex, printArr) {
    let queue = new Node(startVertex);
    let lastQueueNode = queue;

    if (visited[startVertex]) {
        return;
    }

    while (queue != null) {
        let current = queue.data;

        printArr.push(current)
        visited[startVertex] = true;

        for (let neighbour = 0; neighbour < vertex; neighbour++) {
            let value = graph[current][neighbour];

            if (value == 1 && !visited[neighbour]) {
                let node = new Node(neighbour);
                visited[neighbour] = true;
                lastQueueNode.next = node;
                lastQueueNode = lastQueueNode.next;
            }

        }

        queue = queue.next;
    }

    return;
}

function dfsTraversal(graph, startVertex, visited, vertex, printArr) {
    if (visited[startVertex]) {
        return;
    }

    printArr.push(startVertex);
    visited[startVertex] = true;

    for (let neighbour = 0; neighbour < vertex; neighbour++) {
        let value = graph[startVertex][neighbour];

        if (value == 1 && !visited[neighbour]) {
            dfsTraversal(graph, neighbour, visited, vertex, printArr);
        }
    }

    return;
}

function findAllPaths(graph, path, startVertex, endVertex, vertex, visited) {
    visited[startVertex] = true;
    path.push(startVertex);

    if (startVertex == endVertex) {
        console.log(path.join(" -> "));
        path.pop();
        return;
    }

    for (let neighbour = 0; neighbour < vertex; neighbour++) {
        let value = graph[startVertex][neighbour];

        if (value == 1) {
            if (!visited[neighbour]) {
                visited[neighbour] = true;
                findAllPaths(graph, path, neighbour, endVertex, vertex, visited);
                visited[neighbour] = false;
            }
        }
    }

    path.pop();

    return;
}

function isCycleExistsUtils(graph, startVertex, visited, parent, vertex) {
    visited[startVertex] = true;

    for (let neighbour = 0; neighbour < vertex; neighbour++) {
        let value = graph[startVertex][neighbour];

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

function isCycleExists(graph, vertex) {
    let cycleExists = false;
    let visited = Array.from({ length: vertex }, () => false);

    for (let i = 0; i < vertex; i++) {
        if (!visited[i]) {
            if (isCycleExistsUtils(graph, i, visited, -1, vertex)) {
                cycleExists = true;
                break;
            }
        }
    }

    return cycleExists;
}

(() => {
    console.log("Hello! Here You Can Perform Following Directed Graph Operation!\n");
    let vertex = prompt("Enter the Number of Vertices(Node): ");

    let graph = Array.from({ length: vertex }, () => []);

    let edges = prompt("Enter the Number of Edges: ");

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
                        bfsTraversal(graph, j, visited, vertex, printArr);
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
                        dfsTraversal(graph, j, visited, vertex, printArr);
                    }
                }

                console.log(printArr.join(" -> "));

                continue;

            case 3:
                let path = [];
                var visited = Array.from({ length: vertex }, () => false);

                console.log();

                let startVertex = Number.parseInt(prompt("Enter Start Vertex: "));
                let endVertex = Number.parseInt(prompt("Enter End Vertex: "));

                console.log("\nPaths: ");

                findAllPaths(graph, path, startVertex, endVertex, vertex, visited);

                continue;

            case 4: 
                if (isCycleExists(graph, vertex)) {
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