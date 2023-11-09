#include<iostream>

using namespace std;

int func(int n) {
    if(n > 100) {
        return n - 10;
    }
    return func(func(n + 11));
}

int main()
{
    int r = func(44);

    cout << r << endl;

    return 0;
}