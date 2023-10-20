#include <iostream>
#include <vector>
using namespace std;

void insertionSort(vector<int> & data) {
    int key = 0 , j = 0;
    for (int i = 1; i < data.size() ;i++) {
        key = data[i];
        j = i - 1;
        while (key < data[j]) {
            swap(data[j + 1],data[j]);
            j--;
        }
    }
}

void insertionSort2(vector<int> & data) {
    int key = 0 , j = 0;
    for (int i = 1; i < data.size() ;i++) {
        key = data[i];
        j = i - 1;
        while (key < data[j]) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = key;
    }
}

int main(int argc, char const *argv[]) {
    
    vector<int> data = {6,3,2,0,1};
    insertionSort2(data);
    
    for (int i = 0; i < data.size();i++) {
        cout << data[i] << " ";
    }
    cout << endl;
    return 0;
}
