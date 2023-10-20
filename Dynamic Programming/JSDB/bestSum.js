/**
 * Naive Solution
 * @runtime O((n ^ m) * m)
 * @space O(m ^ 2) 
 */

function bestSum(target , numbers) {
    if(target === 0) return [];
    if (target < 0) return null;
    let shortest_combination = null;
    for (let num of numbers) {
        let reminder = target - num;
        let reminder_result = bestSum(reminder,numbers);
        if(reminder_result !== null) {
            const current_combination = [...reminder_result,num];
            if(shortest_combination === null || current_combination.length < shortest_combination.length) { 
                shortest_combination = current_combination;
            }
        } 
    }
    return shortest_combination;
}

/**
 * Memoization
 * @runtime O(n * (m ^ 2))
 * @space O(m ^ 2) 
 */

 function bestSumDPM(target , numbers , memo = {}) {
    if(target in memo) return memo[target];
    if(target === 0) return [];
    if (target < 0) return null;
    let shortest_combination = null;
    for (let num of numbers) {
        let reminder = target - num;
        let reminder_result = bestSum(reminder,numbers ,memo);
        if(reminder_result !== null) {
            const current_combination = [...reminder_result,num];
            if(shortest_combination === null || current_combination.length < shortest_combination.length) { 
                shortest_combination = current_combination;
            }
        } 
    }
    memo[target] = shortest_combination;
    return shortest_combination;
}

/**
 * Tabulation
 * @runtime O((m ^ 2) * n)
 * @space O(m ^ 2) 
 */

const bestSumDPT = (target, numbers) => {
    const table = Array(target + 1).fill(null);
    table[0] = [];

    for (let i = 0; i <= target; i++) {
        if(table[i] !== null) {
            for (let num of numbers) {
                let combination = [...table[i],num]; 
                if(table[i + num] == null || combination.length < table[i+num].length) {
                    table[i + num] = combination;
                }
            }
        }
    }
    return table[target];
}


console.log(bestSumDPT(100,[1,2,5,25,50]));