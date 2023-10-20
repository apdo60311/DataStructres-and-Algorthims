#include <iostream>
#include <vector>

using namespace std;

void four_sum(vector<int>& nums, int target , vector<int> result = {} , int currentSum = 0) {
    if(currentSum == target) {
        for (auto &&i : result) {
            cout << i << " ";
        }
        cout << endl;
        return;
    }
    for (auto &&num : nums) {
        result.push_back(num);
        four_sum(nums , target , result , currentSum + num);
        result.pop_back();
    }
    
}


int main(int argc, char const *argv[]) {
    vector<int> nums = {1,0,-1,0,-2,2};
    four_sum(nums , 0);

    return 0;
}
