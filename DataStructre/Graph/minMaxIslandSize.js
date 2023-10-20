const maxIslandSize = (grid) => {
    let minSize = -Infinity;
    for (let i = 0; i < grid.length; i++) { // rows
        for (let j = 0; j < grid[0].length; j++) { // columns
            let currentSize = BFSsize(grid , i , j);
            if(currentSize !== 0) { // to avoid the case in which the first size = 0
                minSize = Math.max(currentSize, minSize);            
            }
        }        
    }
    return minSize;
};


const minIslandSize = (grid) => {
    let minSize = Infinity;
    for (let i = 0; i < grid.length; i++) { // rows
        for (let j = 0; j < grid[0].length; j++) { // columns
            let currentSize = BFSsize(grid , i , j);
            if(currentSize !== 0) { // to avoid the case in which the first size = 0
                minSize = Math.min(currentSize, minSize);            
            }
        }        
    }
    return minSize;
};


const BFSsize = (grid , i , j) => {
    // bounds checking
    const columnsBounds = j >= 0 && j < grid[0].length;
    const rowsBounds =  i >= 0 && i < grid.length;

    if(!columnsBounds || !rowsBounds) return 0;
    if(grid[i][j] !== 'L') return 0;

    grid[i][j] = 'V';

    let size = 1;

    size += BFSsize(grid , i - 1 , j);
    size += BFSsize(grid , i + 1, j);
    size += BFSsize(grid , i , j - 1);
    size += BFSsize(grid , i , j + 1);

    return size;
    
};



console.log(`Max size: ${
    maxIslandSize([
        ['W' , 'W' , 'W' , 'W' , 'w'],
        ['W' , 'W' , 'L' , 'W' , 'w'],
        ['L' , 'W' , 'L' , 'W' , 'L'],
        ['L' , 'W' , 'L' , 'W' , 'W'],
        ['L' , 'W' , 'W' , 'W' , 'w'],
        ['L' , 'W' , 'W' , 'W' , 'w'],
        ['L' , 'W' , 'W' , 'W' , 'w'],
        ['L' , 'W' , 'W' , 'W' , 'w']
    
    ])
} 
Min Size: ${
    minIslandSize([
        ['W' , 'W' , 'W' , 'W' , 'w'],
        ['W' , 'W' , 'L' , 'W' , 'w'],
        ['L' , 'W' , 'L' , 'W' , 'L'],
        ['L' , 'W' , 'L' , 'W' , 'W'],
        ['L' , 'W' , 'W' , 'W' , 'w'],
        ['L' , 'W' , 'W' , 'W' , 'w'],
        ['L' , 'W' , 'W' , 'W' , 'w'],
        ['L' , 'W' , 'W' , 'W' , 'w']
    
    ])
}
`);