#include<iostream>

using namespace std;

int fact(int n) {
    if(n == 0) {
        return 1;
    }
    return fact(n - 1) * n;
}
// time complicity O(n) * O(n) * O(n) = O(3n) ==> O(n)
int ncR(int n , int r) {
    int temp1 = 0;
    int temp2 = 0;
    int temp3 = 0;

    temp1 = fact(n);
    temp2 = fact(r);
    temp3 = fact(n - r);

    return temp1 / (temp2 * temp3);
}

int main(int argc, char const *argv[])
{
    cout << ncR(5 , 1) << endl;
    return 0;
}
