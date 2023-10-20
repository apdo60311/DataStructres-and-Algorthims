/**
 * Naive solution
 * @runtime  
 * @space    
 */

const allConstruct = (target , words) => {
    if (target === "") return [[]];

    let totalCombinations  = [];
    for(let word of words) {
        if (target.indexOf(word) == 0) { // check if the word is prefix of the target
            let suffix = target.slice(word.length); // remove prefix from the target
            let suffix_word = allConstruct(suffix , words); // call allConstruct recursively with suffix
            const target_ways = suffix_word.map(way => [word,...way]); 
            totalCombinations.push(...target_ways)             
        }
    }
    return totalCombinations;
};

/**
 * Memoization
 * @runtime  
 * @space    
 */


const allConstructDPM = function(target , words , memo = {}) {
    if (target in memo) return memo[target];
    if (target === "") return [[]];

    let totalCombinations  = [];
    for(let word of words) {
        if (target.indexOf(word) == 0) { // check if the word is prefix of the target
            let suffix = target.slice(word.length); // remove prefix from the target
            let suffix_word = allConstruct(suffix , words); // call allConstruct recursively with suffix
            const target_ways = suffix_word.map(way => [word,...way]); 
            totalCombinations.push(...target_ways)             
        }
    }
    memo[target] = totalCombinations;
    return totalCombinations;
};


/**
 * Tabulation
 * @runtime  
 * @space    
 */

const allConstructDPT = (target , words) => {
    let table = Array(target.length + 1).fill().map(() => []);
    table[0] = [[]];

    for (let i = 0; i <= target.length; i++) {
        for (let word of words) {
            if(target.slice(i, word.length + i) === word ) {
                const newCombination = table[i].map(sub => [...sub, word]);
                table[i + word.length].push(...newCombination);
            }
        }
        
    }
    return table[target.length];
};

console.log(allConstructDPT('purple' , ['purp','p','ur','le','purpl']));
