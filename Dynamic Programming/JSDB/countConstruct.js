/**
 * Naive solution
 * @runtime  O((n ^ m) * m)
 * @space    O(m ^ 2)
 */

const countConstruct = (target ,words) => {
    if (target === "") return 1;

    let totalCount = 0;

    for(let word of words) {
        if (target.indexOf(word) == 0) { // check if the word is prefix of the target
            let suffix = target.slice(word.length); // .slice() can be used
            let count = countConstruct(suffix , words);
            totalCount += count;
        }
    }
    return totalCount;
};

/**
 * Memoization
 * @runtime O(n * (m ^ 2)) 
 * @space   O(m ^ 2)
 */

const countConstructDPM = (target ,words , memo = {}) => {
    if (target in memo) return memo[target];
    if (target === "") return 1;

    let totalCount = 0;

    for(let word of words) {
        if (target.indexOf(word) == 0) { // check if the word is prefix of the target
            let suffix = target.slice(word.length); // .slice() can be used
            let count = countConstruct(suffix , words);
            totalCount += count;
        }
    }
    memo[target] = totalCount;
    return totalCount;
};

/**
 * Tabulation
 * @runtime O(n * (m ^ 2)) 
 * @space   O(m ^ 2)
 */

const countConstructDPT = (target ,words) => {
    let table = Array(target.length + 1).fill(0);
    table[0] = 1;

    for (let i = 0; i <= target.length; i++) {
        if (table[i] !== 0) {
            for (let word of words) {
                if (target.slice(i, word.length + i) === word) {
                    table[i + word.length] += table[i];
                }
            }
        }
    }
    return table[target.length];
};

console.log(countConstructDPT('purple' , ['purp','p','ur','le','purpl']));