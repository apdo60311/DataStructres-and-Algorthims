#include <iostream>
#include <vector>
using namespace std;


int main(int argc, char const *argv[]) {

    cout << "Number of Values: ";
    int n = 0;
    cin >> n;
    cout << "Enter Values: ";
    vector<int> values(n);
    for(int i = 0; i < n;i++) {
        cin >> values[i];
    }
    int temp = 0;
    for(int i = 0; i < n-1;i++) {
        int minIndex = i;
        for (int j = i+1; j < n;j++) {
            if(values[j] < values[minIndex]) {
               minIndex = j;
            }
        }

        // swaping
        temp = values[minIndex];
        values[minIndex] = values[i];
        values[i] = temp;
    }
    cout << "\n\n";
    for(int i = 0; i < n;i++) {
        cout << values[i] << " ";
    }
    cout << "\n";
 
    return 0;
}
