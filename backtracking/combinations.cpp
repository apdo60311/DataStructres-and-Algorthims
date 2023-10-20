#include <iostream>
#include <vector>

using namespace std;

void combinations(int n, int k, int i = 1 , vector<int> v = {}) {
    if (v.size() == k) {
        for (int i : v) {
            cout << i << " ";
        }
        cout << "\n";
        return;
    }
    if(i>n)return;
    v.push_back(i);
    combinations(n, k, i+1,v);
    v.pop_back();
    combinations(n, k, i+1,v);
}

void combinations2(int n, int k, int i = 1 , vector<int> v = {}) {
    if (v.size() == k) {
        for (int i : v) {
            cout << i << " ";
        }
        cout << "\n";
        return;
    }
    if(i>n)return;
    for (int index = i; index < n;index++) {
        v.push_back(i);
        combinations2(n, k, index+1,v);
        v.pop_back();
    }
    
}


int main(int argc, char const *argv[]) {
    combinations2(20,16);
    return 0;
}
