/**
 * Naive Solution
 * @runtime O(2 ^ (n+m))
 * @space O(n + m)
 */
function gridTraveler(n,m) {
    if(n == 0 || m == 0) return 0;
    if(n == 1 && m == 1) return 1
    return gridTraveler(n-1,m) + gridTraveler(n,m-1);
}
/**
 * Memoization
 * @runtime O(n * m)
 * @space O(n + m)
 */
const gridTravelerDPM = (n,m , memo = {}) => {
    const key = n + ' ' + m;
    if(key in memo) return memo[key];
    if(n == 0 || m == 0) return 0;
    if(n == 1 && m == 1) return 1;
    memo[key] = gridTraveler(n-1,m , memo) + gridTraveler(n,m-1,memo);
    return memo[key];

}
/**
* Tabulation 
* @runtime O(n * m) 
* @space O(n * m)
*/
function gridTravelerDPT(n,m) {
    const table = Array(m + 1).fill().map(() => Array(n + 1).fill(0));
    table[1][1] = 1;
    for (let i = 0; i <= m; i++) {
        for (let j = 0; j <= n; j++) {
            if(j + 1 <= n) table[i][j + 1] += table[i][j];
            if(i + 1 <= m) table[i + 1][j] += table[i][j];    
        }
    }
    return table[m][n];
}


console.log(gridTravelerDPT(18,18));