#include<iostream>

using namespace std;

int sum(int n) {
    if(n == 0) {
        return 0;
    }
    else {
        return sum(n - 1) + n;
    }
}

int main()
{
    int n = 5;
    int result = 0;
    for(int i = 0;i <= n;i++) {
        result += i;
    }
    cout << result << endl;
    result = sum(5);
    cout << result << endl;
    
    return 0;
}