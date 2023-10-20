/**
 * @runtime O(2 ^ n)
 * @space   O(n) 
 */

function fib(n) {
    if(n <= 2) return 1;
    return fib(n - 1) + fib(n - 2);    
}

/**
* Memoization
* @runtime O(n)
* @space O(n)
*/

const fibDPM = (n,  memo = {}) => {
    if (n in memo) return memo[n];
    if(n <= 2) return 1;
    memo[n] = fib(n - 1 , memo) + fib(n - 2 , memo);
    return memo[n];    
};


/**
* Tabulation
* @runtime O(n)
* @space O(n)
*/

const fibDPT = (n) => {
    const table = Array(n + 1).fill(0); // Intialize Array with zeros
    table[1] = 1; // table[0] = 0 , table[1] = 1

    for (let index = 0; index < n; index++) {
        table[index + 1] += table[index];
        table[index + 2] += table[index];
    }
    return table[n];
}

console.log(fibDPT(50));