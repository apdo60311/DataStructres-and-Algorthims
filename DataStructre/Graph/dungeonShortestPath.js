const shortestPath = (grid) => {
    let shortestPath = bfs(grid , 0 , 0);
    return shortestPath;
};

const bfs = (grid , row , col) => {
    let colQueue = []; // Queue of columns indecies
    let rowQueue = []; // Queue of rows indecies
    
    colQueue.push(col); // push start column
    rowQueue.push(row); // push start row

    let pathLength = 0; // counter for shortest path

    let leftCounter = 1;
    let nextCounter = 0;

    while (colQueue.length > 0) {
        let r = rowQueue.shift();
        let c = colQueue.shift();
        // console.log(`${r} - ${c}`);

        if(grid[r][c] === '.') grid[r][c] = 'V'; // mark nodes as visited

        // check for bounds and grid[row][column] not equal to (#) and not visited
        if (r - 1 >= 0 && r - 1 < grid.length && c >=0 && c < grid[0].length && 
            grid[r - 1][c] != '#' && grid[r - 1][c] != 'V') {
            rowQueue.push(r - 1); 
            colQueue.push(c); 
            nextCounter++; 
        }
        if (c - 1 >= 0 && c - 1 < grid[0].length && r >=0 && r < grid.length && 
            grid[r][c-1] != '#' && grid[r][c-1] != 'V'){
            rowQueue.push(r); 
            colQueue.push(c - 1); 
            nextCounter++;
        } 
        if (r + 1 >= 0 && r + 1 < grid.length && c >=0 &&
            c < grid[0].length && grid[r + 1][c] != '#' && grid[r + 1][c] != 'V') {
            rowQueue.push(r + 1); 
            colQueue.push(c); 
            nextCounter++;
        } 
        if (c + 1 >= 0 && c + 1 < grid[0].length && r >=0 &&
            r < grid.length && grid[r][c + 1] != '#' && grid[r][c + 1] != 'V') {
            rowQueue.push(r); 
            colQueue.push(c + 1); 
            nextCounter++;
        } 
                

        if (grid[r][c] === 'E') return pathLength; // if End is reached
        
    
        //! what's is this? 
        leftCounter--;
        if(leftCounter === 0) {
            leftCounter = nextCounter;
            nextCounter = 0;
            pathLength++;
        }
    
    }
    // otherwise return -1 indicating that there is no path
    return -1;
};

console.log(shortestPath( // path with 9 steps includeing the end
    [
        ['S' , '.' , '.' , '#' , '.' , '.' , '.'],
        ['.' , '#' , '.' , '.' , '.' , '#' , '.'],
        ['.' , '#' , '.' , '.' , '.' , '.' , '.'],
        ['.' , '.' , '.' , '#' , '.' , '.' , '.'],
        ['#' , '.' , '#' , 'E' , '.' , '#' , '.'],
    ]
));

console.log(shortestPath( // no path (-1)
    [
        ['S' , '#' , '.' , '#' , '.' , '.' , '.'],
        ['.' , '#' , '.' , '.' , '.' , '#' , '.'],
        ['#' , '#' , '.' , 'E' , '.' , '.' , '.'],
        ['.' , '.' , '.' , '.' , '.' , '.' , '.'],
        ['#' , '.' , '#' , '.' , '.' , '#' , '.'],
    ]
));