#include<iostream>
#include<map>
using namespace std;

int gridTraverser(int n , int m) {// grid traverser [naive solution]
    if (n == 0 || m == 0) return 0;
    if (n == 1 && m == 1) return 1;
    return gridTraverser(n-1 ,m) + gridTraverser(n , m-1);
}
/**
 * SYNTAXERROR:
 * ? Pair With map doesn't work well
*/
int gridTraverserDB(int n, int m , map<string, int> memo = {}) {
    
    if(n ==0 || m ==0) { return 0;}
    if(n == 1 && m == 1) { return 1;}
    
    string key = to_string(n) + "-" + to_string(m);

    if(memo.count(key) > 0) {
        return memo[key];
    }
    memo[key] = gridTraverserDB(n-1,m) + gridTraverserDB(n,m-1);
    return memo[key];
} 

int main(int argc, char const *argv[]) {

    cout << gridTraverserDB(18, 18) << endl;  
    return 0;
}
