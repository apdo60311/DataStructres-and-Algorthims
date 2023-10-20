function subSets(nums) {
    helper(nums);
}

function helper(nums , result = [] ,i = 0) {
    if(i >= 3) {
        console.log(result);
        return;
    }
    helper(nums,result,i + 1);
    helper(nums,[...result , nums[i]],i + 1);
}

subSets([1,2,3]);