#include <iostream>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

    vector<int> arr = {1 ,2 ,3, 4 ,5 ,6 ,7 ,8 ,9, 10,
                        11, 12, 13, 14, 15 , 16 , 17, 18, 
                        19 , 20, 21, 22, 23, 24, 25, 26, 27 , 
                        28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 
                        38, 39 , 40, 41, 42, 43, 44, 45, 46, 47 , 
                        48, 49, 50, 51, 52, 53, 54, 55 , 56, 57, 
                        58, 59, 60, 61, 62, 63 , 63, 64, 65, 66, 
                        67, 68, 69, 70 , 71, 72, 73, 74, 75, 76, 
                        77, 78 , 79 , 80, 81, 82, 83, 84, 85, 86, 
                        87 , 88, 89, 90, 91, 92, 93, 94, 95 , 96, 
                        97, 98, 99 , 100, 101, 102, 103, 104, 105, 
                        106, 107, 108, 109, 110, 111, 112, 113, 114, 
                        115, 116, 117, 118, 119, 120, 121, 122, 123, 
                        124, 125, 126, 127, 128, 129, 130, 131, 132, 
                        133, 134, 135, 135, 136, 137, 138, 139, 140, 
                        141, 142, 143, 144, 145, 146, 147, 148, 149, 
                        150, 151, 152, 153, 154, 155, 156, 157, 158, 
                        159, 160, 161, 162, 163, 164 , 164 , 165, 166,
                        167, 168, 169 , 170, 171, 172, 173, 174, 175, 
                        176, 177, 178, 179, 180, 181, 182, 183, 184, 
                        185, 186, 187, 188, 189, 190, 191, 192, 193, 
                        194, 195, 196, 197, 198, 199, 200, 201, 202, 
                        203, 204, 205, 206, 207, 208, 209, 210, 211, 
                        212, 213, 214, 215, 216, 217, 218, 219, 220, 
                        221, 222, 223, 224, 225, 226, 227, 228, 229
                        };


void binary_string(string s , int n) {
    if(s.length() == 2 * n) {
        cout << s << endl;
        return;
    }
    binary_string(s+'0', n);
    binary_string(s+'1', n);
}

void print_all_stings_of_length_k(vector<char>& chars ,string s , int k) {
    if(s.length() == k) {
        cout << s << endl;
        return;
    }

    for (char c : chars) {
        print_all_stings_of_length_k(chars,s + c,k);
    }  
} 

void powerSum(int a ,int sum ,int num , int& counter) {
    if(a == 50) {
        if(sum == num) {
           counter++; 
        }
        return;
    }

    if(sum + pow(a,2) <= num) { 
        powerSum(a + 1, sum + pow(a , 2),num , counter);
    }
    powerSum(a + 1, sum,num , counter); 
}

// void generateParenthess(string str , int n , int r , int l) {
//     if(r == 0 && l == 0) {
//         cout << str << endl;
//         return;
//     }
//     if(l != 0) generateParenthess(str+'(' , n , r , l-1);
//     if(r > l) generateParenthess(str+')' , n , r-1 , l);
// }

void generateParenthess(int n , string str = "" ,int r = 0, int l = 0) {
    if(r == n && l == n) {
        cout << str << endl;
        return;
    }
    if(l <= n) generateParenthess(n , str+'(' , r , l+1);
    if(r < l) generateParenthess(n , str+')' , r+1 , l);
}

// int spoj_princess(vector<int> arr ,int i = 0 , map<int , int> dp = {}) {
//     if(i >= arr.size()) return 0;
//     return max(spoj_princess(arr ,i + 2 , dp) + arr[i] , spoj_princess(arr ,i + 1 , dp));
// }

int spoj_princess(vector<int> arr ,int i = 0 , map<int , int> dp = {}) {
    if(i >= arr.size()) return 0;
    if(dp.count(i) != 0) return dp[i];
    dp[i] = max(spoj_princess(arr ,i + 2 , dp) + arr[i] , spoj_princess(arr ,i + 1 , dp));
    return dp[i];
}

int frog(vector<int> h  , int n , int i = 0 , int cost = 0 , map<int , int> memo = {}) {
    if(i >= n - 1) return cost;
    if(memo.count(i) != 0) return memo[i];
    memo[i] = min(frog(h,n,i+1 , abs(h[i] - h[i + 1])) + cost , frog(h,n,i+2 , abs(h[i] - h[i + 2])) + cost); 
    return memo[i];

} 

int frogK(vector<int> h  , int n , int k ,int i = 0) {
    if(i >= n - 1) return 0;
    int minimum = 99999999;
    for (int j = 1; j <= k; j++) {
       if(i+j < n) minimum = min(frog(h,n,i+j) + abs(h[i] - h[i + j]) , minimum);
        // if(i+j+1 <= n - 1){
        //     minimum = min(frog(h,n,i+j+1 , abs(h[i] - h[i + j + 1])) + cost , minimum);
        // }
    }
    return minimum;
    
} 

int taro(vector<vector<int>> tasks , int days , int task = 0 ,int day = 0) {
    if(day >= days) {
        return 0;
    }
    int maximum = 0;
    if(task == 0) maximum = max(taro(tasks , days , 1 , day + 1) + tasks[day][1]  , taro(tasks , days , 2 , day + 1) + tasks[day][2]);
    if(task == 1) maximum = max(taro(tasks , days , 0 , day + 1) + tasks[day][0] , taro(tasks , days , 2 , day + 1) + tasks[day][2]);
    if(task == 2) maximum = max(taro(tasks , days , 0 , day + 1) + tasks[day][0] , taro(tasks , days , 1 , day + 1) + tasks[day][1]);
    
    return maximum;
}

int knapsack(vector<int> items , vector<int> values , int capacity ,int currentItem = 0) {
    if(currentItem == items.size()) return 0;
    int maxValue = 0;
    if(items[currentItem] <= capacity) {
        maxValue = max(knapsack(items, values, capacity - items[currentItem], currentItem + 1) + values[currentItem], maxValue);
        maxValue = max(knapsack(items, values, capacity, currentItem + 1) , maxValue);
    }
    return maxValue;
}


int main(int argc, char const *argv[]) {
    
    //! binary_string("",2);

    //? vector<char> chars = {'a' , 'b'};
    //? print_all_stings_of_length_k(chars , "" , 3);
    
    //* int counter = 0;
    //* powerSum(0,0,10 ,counter);
    //* cout << counter << endl;
    
    //? generateParenthess("" , 3 , 3 , 3);
    //? generateParenthess(3);

    //! cout << spoj_princess(arr) << "\n";

    //?  vector<int> steps = {10 , 30 , 40 , 20};
    //?  vector<int> steps2 = {10 , 10};
    //?  vector<int> steps3 = {10 , 30 , 40 , 50, 20}; 
    //?  cout << frog(steps , 4) << endl;
    //? cout << frogK(steps3 , 5 , 3) << endl;


    //! vector<vector<int>> tasks = {
    //!     {10,40 , 70},
    //!     {20,50 , 80},
    //!     {30,60 , 90}
    //! };
    //! cout << taro(tasks , 3) << endl;

    vector<int> items = {3 , 4 , 5};
    vector<int> values = {30 , 50 , 60};

    cout << knapsack(items , values ,8) << endl;

    return 0;
}
