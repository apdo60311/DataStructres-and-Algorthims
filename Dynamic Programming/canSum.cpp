#include <iostream>
#include <vector>
#include <map>
using namespace std;

/* Brute Force Version */
bool canSumBF(int targetSum , vector<int>& numbers) {
    if(targetSum == 0) return true; // return true if the leaf node is equal to zero 
    if(targetSum < 0) return false; 

    for (int num : numbers) {
        if(canSumBF(targetSum -  num, numbers) == true) { 
            return true;
        }
    }
    return false;
}
/* Dynamic Programming Version */

bool canSumDB(int targetSum , vector<int>& numbers , map<int , int> memo = {}) {
    if(memo.count(targetSum) > 0) return memo[targetSum];
    if(targetSum == 0) return true; // return true if the leaf node is equal to zero 
    if(targetSum < 0) return false; 

    for (int num : numbers) {
        if(canSumBF(targetSum -  num, numbers) == true) { 
            memo[targetSum - num] = true;
            return true;
        }
    }
    memo[targetSum] = false;
    return false;
}

vector<int> howSum(int targetSum , vector<int>& numbers) {
    if (targetSum == 0) return {};
    if (targetSum < 0) return {NULL};

    for (int num : numbers) { 
        int reminder = targetSum - num;
        vector<int> reminder_result = howSum(reminder,numbers);
        /**
         * \bug cannot check if the vector is NULL 
        */
        if (reminder_result[0] != NULL)
            reminder_result.push_back(num);
            return reminder_result;
    }
    return {NULL};
}

int main(int argc, char const *argv[]) {
    
    vector<int> numbers={2,3};

    vector<int>  vect = howSum(7,numbers);

    for(int i=0;i<vect.size();i++) {
        cout << vect[i] << " ";
    }


    return 0;
}
