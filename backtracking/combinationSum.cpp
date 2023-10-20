#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> result;

void combinationSum(vector<int> nums ,int target ,vector<int> current = {} , int total = 0 , int i = 0) {
    if(target == total) {
        result.push_back(current);
        return;
    }

    if(i>=nums.size() or total > target) return;

    current.push_back(nums[i]);
    combinationSum(nums ,target ,current, total + nums[i] , i);
    current.pop_back();
    combinationSum(nums ,target ,current, total , i + 1);
}

void combinationSum2(vector<int> nums ,int target ,vector<int> current = {} , int total = 0 , int i = 0) {
    if(target == total) {
        result.push_back(current);
        return;
    }

    if(i>=nums.size() or total > target) return;

    current.push_back(nums[i]);
    combinationSum2(nums ,target ,current, total + nums[i] , i+1);
    current.pop_back();
    combinationSum2(nums ,target ,current, total , i + 1);
}

int main(int argc, char const *argv[]) {
    // vector<int> nums = {2,3,6,7};
    // int target = 7;
    vector<int> nums = {10,1,2,7,6,1,5};
    int target = 8;
    combinationSum2(nums , target);
    for (size_t i = 0; i < result.size(); i++) {
        for (size_t j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
