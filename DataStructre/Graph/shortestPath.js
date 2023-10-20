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

const BFSshortest = (graph , src, dist, visited) => {
    if(visited.has(src)) return 0;
    let queue = [];
    queue.unshift(src);
    let path = 0;
    while (queue.length > 0) {
        let current = queue.shift();
        for (let neighbor of graph[current]) {
            queue.push(neighbor);
        }
        if(current === dist) return path;
        path++;
    }
    return -1;
};

const shortestPath = (src , dist , edges) => {
    let graph = buildAdjList(edges);
    let visited = new Set();
    return BFSshortest(graph , src, dist, visited);
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
console.log(shortestPath('A' , 'K',

    [
        ['B' , 'A'] , ['C' , 'B'] , ['D' , 'C'] , ['K' , 'C'] ,
        ['F' , 'Z'] , ['F' , 'L'] , ['G' , 'L']
    ]
     ));
