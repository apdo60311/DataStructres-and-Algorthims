const buildAdjList = function(n, edges){
    const adjList = new Array(n).fill(0).map(()=>[]);
    for(let edge of edges){
        let node1 = edge[0];
        let node2 = edge[1];
        adjList[node1].push(node2);
        adjList[node2].push(node1);
    }
    return adjList;
}

const DFS = function(graph,vertex,visited){
    visited[vertex] = true;
    const neighbours = graph[vertex];
    for(let i = 0;i < neighbours.length;i++){
        const neighbour = neighbours[i];
        if(!visited[neighbour]){
            DFS(graph, neighbour, visited);
        }
    }
}

const countComponents = function(n, edges){
    const graph = buildAdjList(n, edges);
    const visited = {};
    let count = 0;
    for(let vertex = 0;vertex < n;vertex++){
        if(!visited[vertex]){
            count++;
            DFS(graph, vertex, visited);
        }
    }
    return count;
}

const n = 7;
const edges = [[0,1],[1,2],[3,4],[5,6]];

console.log(`COUNT: ${countComponents(n, edges)}`);