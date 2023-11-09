#include<iostream>

using namespace std;

int rev(int arr[] , int n) {
    if (n > 0) {
        cout << arr[n - 1] << endl;
        // assending - > when going 
        rev(arr, n - 1); // recurtion
        // desending - > when returning
    }
    return 0;
}

void func(int n) {
    static int i = 0;
    if(n > 0) {
        i++;
        func(n - 1);
        cout << i << endl;
    }
}

void recursion (int n) {
    if(n > 0) {
        cout << "assending : " << n << endl;
        recursion (n - 1);
        cout << "returning : " << n << endl;
    }
}


int main()
{
    // int arr[4] = {1,2,3,4};
    // int n = sizeof(arr) / sizeof(arr[0]);
    // rev(arr , n);
    
    func(4);

    return 0;
}