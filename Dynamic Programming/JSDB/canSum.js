/**
 * Naive Solution
 * @runtime O(n ^ m)
 * @space O(m) 
 */

const canSum = (target , numbers) => {
    if (target < 0) return false;
    if(target == 0) return true;
    for (let num of numbers) {
        if(canSum(target - num , numbers)) return true;
    }
    return false;
}
/**
 * Memoization
 * @runtime O(n ^ m)
 * @space O(m) 
 */

 const canSumDPM = (target , numbers , memo = {}) => {
    if (target in memo) return memo[target];
    if (target < 0) return false;
    if(target == 0) return true;
    for (let num of numbers) {
        if(canSum(target - num , numbers)) {
            memo[target] = true;
            return true;
        } 
    }
    memo[target] = false;
    return false;
}

/**
 * Tabulation
 * @runtime O(n * m)
 * @space O(m) 
 */

const canSumDPT = (target , numbers) => {
    const table = Array(target + 1).fill(false);
    table[0] = true;
    for (let i = 0; i <= target; i++) {
        if(table[i] === true) {
            for (num of numbers) {
                if(i + num <= table.length) table[i + num] = true;    
            }
        }
    }
    return table[target]
}

console.log(canSumDPT(4,[2]));