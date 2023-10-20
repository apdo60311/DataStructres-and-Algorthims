#include <iostream>
#include <vector>
using namespace std;


int main(int argc, char const *argv[])
{
    cout << "Number of Values: ";
    int n = 0;
    cin >> n;
    cout << "Enter Values: ";
    vector<int> values(n);
    for(int i = 0; i < n;i++) {
        cin >> values[i];
    }
    cout << "\nEnter Value: ";
    int val = 0;
    cin >> val;

    for(int i = 0; i < n;i++) {
        if (values[i] == val) {
            cout << "\nFounded At Index: [" << i << "]\n";
            break;
        }
        else if(i == n - 1) {
            cout << "Not Founded!\n";
            break;
        }
    }


    return 0;
}
