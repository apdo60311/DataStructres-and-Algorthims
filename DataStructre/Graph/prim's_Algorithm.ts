class Edge {
    public from:number;
    public to:number;
    public cost:number;

    constructor(from:number, to:number , cost:number) {
        this.from = from;
        this.to = to;
        this.cost = cost;
    }
}

let Edges:Edge[][] = [[]];
let visited = {};

function mstGenerator(Edges:Edge[][] , start:number = 0 , n:number) {
    let m = n - 1;
    let edgeCount = 0;
    let mstCount = 0;
    let minCount = 0;

    visited[start] = true;
    for (let edge of Edges[start]) {
        if(!visited[edge.to]) {
            
        }
    }

}

function addEdge(Edges:Edge[][] , from:number, to:number , cost:number) {
    let edge:Edge = new Edge(from, to, cost);
    Edges[from].push(edge);
}

function addEdgeUND(Edges:Edge[][] , from:number, to:number, cost:number) {
    addEdge(Edges , from, to, cost);
    addEdge(Edges , to, from, cost);
}

addEdgeUND(Edges ,0, 1, 9);
addEdgeUND(Edges ,0, 2, 0);
addEdgeUND(Edges ,0, 3, 5);
addEdgeUND(Edges ,0, 5, 7);
addEdgeUND(Edges ,1, 3, -2);
addEdgeUND(Edges ,1, 4, 3);
addEdgeUND(Edges ,1, 6, 4);
addEdgeUND(Edges ,2, 5, 6);
addEdgeUND(Edges ,3, 5, 2);
addEdgeUND(Edges ,3, 6, 3);
addEdgeUND(Edges ,4, 6, 6);
addEdgeUND(Edges ,5, 6, 1);


