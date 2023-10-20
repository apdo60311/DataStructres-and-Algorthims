#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int> & data) {
    for (int i = 0; i < data.size(); i++) {
        for (int j = 0; j < data.size() - i; j++) {
            if(data[j] > data[j + 1]) {
                swap(data[j], data[j +1]);
            }
        }
    }
    
}

int main(int argc, char const *argv[]) {
    vector<int> data = {8,2,5,1,6,0};
    bubbleSort(data);
        for (int i = 0; i < data.size();i++) {
        cout << data[i] << " ";
    }
    cout << endl;

    return 0;
}
