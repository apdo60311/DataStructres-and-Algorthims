#include<iostream>

using namespace std;

/* 

    e power (x) = 1 + (x / 1) + (x2 / 2!) + (x3 + 3!) + (x4 + 4!)

*/

/* Taylor series (1) */
double e (int x , int n) {
    static double factorial = 1;
    static double power = 1;
    double result = 0;

    if (n == 0)
    {
        return 1;
    }
    result = e(x , n - 1);
    power *= x;
    factorial *= n;
    return result + power / factorial;
}

/* Taylor series (2) */
double e2(int x , int n) {
    static double result = 1;
    if(n == 0) {
        return result;
    }
    else
    {
        result = 1 + x  * result / n;
        return e2(x , n - 1);
    }
    
}
int main(int argc, char const *argv[])
{
    cout << e(1, 10) << endl;
    cout << e2(1, 10) << endl;

    return 0;
}
