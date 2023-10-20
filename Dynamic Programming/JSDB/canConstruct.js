/**
 * Naive Solution
 * @runtime O((n ^ m) * m)
 * @space   O(m)
 */

const canConstruct = (target , words)  => {
    if (target === "") return true;
    for(let word of words) {
        if (target.indexOf(word) == 0) { // check if the word is prefix of the target
            let suffix = target.substring(word.length); // .slice() can be used
            if (canConstruct(suffix , words) === true) {
                return true; 
            }
        }
    }
    return false;
};  

/**
 * Memoization
 * @runtime   O(n * (m ^ 2))
 * @space     O(m ^ 2)
 */

 const canConstructDPM = (target , words , memo = {})  => {
    if (target in memo) return memo[target];
    if (target === "") return true;

    for(let word of words) {
        if (target.indexOf(word) == 0) { // check if the word is prefix of the target
            let suffix = target.substring(word.length); // .slice() can be used
            if (canConstruct(suffix , words) === true) {
                memo[target] = true;
                return true; 
            }
        }
    }
    memo[target] = false;
    return false;
};  


/**
 * Tabulation
 * @runtime   O(n * (m ^ 2))
 * @space     O(m)
 */

const canConstructDPT = (target , words) => {
    const table = Array(target.length + 1).fill(false);
    table[0] = true; // the empty string is always possible to generate

    for (let i = 0; i <= target; i++) {
        if(table[i] === true) {
            for (let word of words) {
                if (target.slice(i , i + word.length) === word) {
                    table[i + word.length] = true;
                }
            }
        }       
    }
    return table[target.length];
};


console.log(canConstruct("abcdef" , ['ab','abc','cd','def','abcd']));