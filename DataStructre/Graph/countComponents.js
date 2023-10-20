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

const countComponents = (edges) => {
    let graph = buildAdjList(edges);
    let visited = new Set();
    let componentsCounter = 0
    for (let edge in graph) {
        if(DFScount(edge , graph ,visited)) componentsCounter++;
    }
    return componentsCounter;
};


const DFScount = (edge , graph , visited) => {
    if(visited.has(edge)) return false;
    visited.add(edge);
    for (let neighbor of graph[edge]) {
        DFScount(neighbor, graph, visited);
    }
    return true;
};

/**
   
    (A)-->(B)-->(C)-->(D)    //! Frist Component
                | 
                V 
               (K)

 
    (F)--->(Z)               //! Second Component
     |                      
     V
    (L)--->(G)

    (J)--->(P)--->(I)        //! Third Component

    (Y)-->(S)-->(O)          //! Fourth Component

*/

console.log(countComponents(
    [
        ['B' , 'A'] , ['C' , 'B'] , ['D' , 'C'] , ['K' , 'C'] ,
        ['F' , 'Z'] , ['F' , 'L'] , ['G' , 'L'] ,
        ['J' , 'P'] , ['P' , 'I'] ,
        ['Y' , 'S'] , ['S' , 'O'] 
    ]
));