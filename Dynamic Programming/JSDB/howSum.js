/**
 * Naive solution
 * @runtime O((n ^ m) * m)
 * @space O(m) 
 */

function howSum(target , numbers) {
    if(target === 0) return [];
    if (target < 0) return null;

    for (let num of numbers) {
        let reminder = target - num;
        let reminder_result = howSum(reminder,numbers);
        if(reminder_result !== null) return [...reminder_result,num];
    }
    return null;
}

/**
 * Memoization
 * @runtime O((n * (m ^ 2))
 * @space O(m ^ 2) 
 */

const howSumDPM = (target , numbers , memo = {}) =>{
    if (target in memo) return memo[target];
    if(target === 0) return [];
    if (target < 0) return null;

    for (let num of numbers) {
        let reminder = target - num;
        let reminder_result = howSum(reminder,numbers);
        if(reminder_result !== null) {
            memo[target] = [...reminder_result,num]
            return memo[target];
        } 
    }
    memo[target] = null;
    return null;    
}

/**
 * Tabulation
 * @runtime O((n * (m ^ 2))
 * @space O(m ^ 2) 
 */

const howSumDPT = (target ,numbers) => {
    const table = Array(target + 1).fill(null);
    table[0] = [];
    for (let i = 0; i <= target; i++) {
        if(table[i] !== null) {
            for (let num of numbers) {
                table[i + num] = [...table[i],num];
            }
        }
    }
    return table[target];
};
console.log(howSum(8,[10,1,2,7,6,1,5]));