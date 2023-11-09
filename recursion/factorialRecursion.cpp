#include<iostream>

using namespace std;

int factorial(int n) {

    if(n == 0) {
        return 1;
    }
    else {
        return factorial(n - 1) * n;
    }
}

int main()
{
    int n = 5;
    int fact = 1;
    for(int i = 2; i <= n; i++){

        fact *=i;
    }
    cout << "factorial using loop :" << fact << endl;
    fact = factorial(n);
    cout << "factorial using recursion :" << fact << endl;
    return 0;
}