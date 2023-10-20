function powSum(array , pow = 1) {
    let sum = 0;
    for (let i = 0; i < array.length; i++) {
        if(Array.isArray(array[i])) {
            sum += powSum(array[i],pow + 1);
        }
        else {
            sum += array[i];            
        }
    }
    return Math.pow(sum,pow);
}
``

console.log(powSum([1,3,[1,2]])); // 13
console.log(powSum([1,2,[3,4],[[2]]])); //116