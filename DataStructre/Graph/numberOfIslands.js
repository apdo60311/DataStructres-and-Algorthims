const BFScounter = (grid , i , j) => {
    // bounds checking
    const columnsBounds = j >= 0 && j < grid[0].length;
    const rowsBounds =  i >= 0 && i < grid.length;

    if(!columnsBounds || !rowsBounds) return false;
    if(grid[i][j] !== 'L') return false;

    grid[i][j] = 'V';

    BFScounter(grid , i - 1 , j);
    BFScounter(grid , i + 1, j);
    BFScounter(grid , i , j - 1);
    BFScounter(grid , i , j + 1);

    return true;
};

const countIslands = (grid) => {
    let counter = 0;
    for (let i = 0; i < grid.length; i++) {
        for (let j = 0; j < grid[0].length; j++) {
            if(grid[i][j] === 'L') {
                if(BFScounter(grid , i , j)) {
                    counter++;
                }
            }            
        }
    }
    return counter;
};


console.log(countIslands([
    ['W' , 'W' , 'W' , 'W' , 'w'],
    ['W' , 'W' , 'L' , 'W' , 'w'],
    ['L' , 'W' , 'L' , 'W' , 'L'],
    ['W' , 'W' , 'W' , 'W' , 'w'],
    ['W' , 'W' , 'W' , 'W' , 'w']

]));