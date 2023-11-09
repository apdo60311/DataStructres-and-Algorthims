#include<iostream>

using namespace std;

void func(int n) {
    if(n > 0) {
        cout << n << endl;
        func(n - 1);
    }
}

int main() {

    func(4); // time O(n) space O(n)

    // samiliar results using while loop
    // time O(n) space O(1)
    int n = 4;
    while(n > 0) {
        cout << n << endl;
        n--;
    }
    return 0;
}