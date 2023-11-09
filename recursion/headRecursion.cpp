#include<iostream>

using namespace std;

void func(int n) {
    if(n > 0) {
        func(n - 1);
        cout << n << endl;
    }
}

int main() {

    func(4); // time O(n) space O(n)

    // samiliar results using while loop
    // time O(n) space O(1)
    int n = 4;
    int i = 1;
    while(i <= n) {
        cout << i << endl;
        i++;
    }
    return 0;
}