const buildAdjList = (edges) => {
    let Graph = {};
    for (let edge of edges) {
        const [start , end] = edge;
        if(!(start in Graph)) Graph[start] = [];
        if(!(end in Graph)) Graph[end] = [];
        Graph[start].push(end);
        Graph[end].push(start);

    }
    return Graph;
};


const countMaxSize = (list) => {
    let graph = buildAdjList(list);
    let visited = new Set();
    let size = 0;
    for (let edge in graph) {
        size = Math.max(size , DFScount(edge , graph , visited));
    }
    return size;
};
const DFScount = (edge , graph , visited) => {
    if(visited.has(edge)) return 0;
    visited.add(edge);
    let count = 1;
    for (let neighbor of graph[edge]) {
        count +=  DFScount(neighbor, graph, visited);
    }
    return count;
};

/**
   (A)-->(B)-->(C)-->(D)
                |
                V
               (K)


    (F)--->(Z)
     |
     V
    (L)--->(G)
*/
console.log(countMaxSize(
    [
        ['B' , 'A'] , ['C' , 'B'] , ['D' , 'C'] , ['K' , 'C'] ,
        ['F' , 'Z'] , ['F' , 'L'] , ['G' , 'L']
    ]
));
