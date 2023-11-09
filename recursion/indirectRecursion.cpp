#include<iostream>

using namespace std;

void funB(int n);
void funC(int n);


void funA(int n) {
    if(n > 0) {
        cout << n << endl;
        funB(n - 1);
    }
}

void funB(int n) {
    if(n > 0) {
        cout << n << endl;
        funC(n - 1);
    } 
}

void funC(int n) {
    if(n > 0) {
        cout << n << endl;
        funA(n - 1);
    } 
}

int main()
{
    funA(55);
    return 0;
}
