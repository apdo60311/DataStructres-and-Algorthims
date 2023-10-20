#include <iostream>
#include <vector>
#include <map>
using namespace std;


double calcProb(string ht , vector<double>& pb) {
    double result = 1;
    int i = 0;
    for (char c : ht) {
        if(c == 'H') result *= pb[i++];
        else result *= (1 - pb[i++]);
    }
    return result;
}

double coins(vector<double> pb , int n, string ht = "", int h = 0, int t = 0) {
    if(ht.length() == n) {
        if(h > t) return calcProb(ht , pb);
        return 0;
    }
    return coins(pb, n, ht+'H' , h + 1 , t) + coins(pb, n, ht+'T' , h, t + 1);
}

// double coins(int n , vector<double> pb ,int i = 0 , int heads = 0) {
//     if(i == n) return heads > n/2;
//     return coins(n, pb ,i + 1, heads + 1) * pb[i] + coins(n, pb ,i + 1, heads) * (1-pb[i]);
// }

double coins(int n , vector<double> pb ,int i = 0 , int heads = 0 , map<string , double> dp = {}) {
    if(i == n) return heads > n/2;
    string key = to_string(i) + "-" + to_string(heads);
    if(dp.count(key) != 0) return dp[key];

    dp[key] = coins(n, pb ,i + 1, heads + 1) * pb[i] + coins(n, pb ,i + 1, heads) * (1-pb[i]);
    return dp[key];
}

int main(int argc, char const *argv[]) {
    vector<double> pb = {0.30 , 0.6 , 0.8 , 0.30 , 0.6 , 0.8 , 0.30 , 0.6 , 0.8 , 0.30 , 0.6 , 0.8 , 0.30 , 0.6 , 0.8 , 0.30 , 0.6 , 0.8 , 0.30 , 0.6 , 0.8 , 0.30}; //22
    // cout << coins(pb , 22) << endl; // 0.631884
    
    // vector<double> pb = {0.30 , 0.6 , 0.8};
    cout << coins(22 , pb) << endl; // 0.612
    cout << coins(pb , 22) << endl; // 0.612

    
    return 0;
}
