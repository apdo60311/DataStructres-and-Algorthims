#include<iostream>

using namespace std;

int power(int m , int n) {
    if(n == 0) {
        return 1;
    }
    else
    {
        return power(m , n - 1) * m;
    } 
}

int POWER(int m , int n) {
    if (n == 0)
    {
        return 1;
    }
    if (n % 2 == 0)
    {
        return POWER(m * m , n / 2);
    }
    else
    {
        return POWER(m * m , (n - 1) / 2) * m; 
    }
    
}

int main()
{
    int result;
    result = POWER(2, 9);
    cout << result << endl;
    return 0;
}