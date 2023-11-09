#include<iostream>

using namespace std;

int fib(int n) {
    if(n <= 1) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

void fibLoop(int n) {
    int first = 0;
    int second = 1;
    int nextTerm = 0;
    for(int i = 0; i < n; i++) {
        if(i == 0) {
            cout << first << endl;
        }
        if (i == 1) {
            cout << second << endl;
        }
        nextTerm = first + second;
        first = second;
        second = nextTerm;
        cout << nextTerm << endl;
    }
}

int main(int argc, char const *argv[])
{
    int n = 10;
    fibLoop(n);
    cout <<  "================================================" << endl;
    cout<< fib(n) << endl;
    return 0;
}
