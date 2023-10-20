#include <iostream>
#include <vector>
using namespace std;

void countingSort(vector<int> &data) {
    // finding the greatest element 
    int greatest = data[0];
    for (int i = 0; i < data.size();i++) {
        if(greatest < data[i]) {
            greatest = data[i];
        }
    }

    // intilaizing the count array
    vector<int> count(greatest + 1);
    for(int i = 0; i < data.size();i++) {
        count[data[i]]++;
    }

    // find the cumulative sum 
    for (int i = 1; i < count.size(); i++) {
        count[i] += count[i - 1];
    }
    vector<int> output(data.size());
    // --------------- // 
    for (int i = 0; i < data.size(); i++) {
        output[count[data[i]]] = data[i];
        count[data[i]]--;
    }
    data = output;
    // free memory
    count.clear();
}

int main(int argc, char const *argv[]) {
    
    vector<int> data = {4 ,10 ,12 ,9,0,4,5,5,4,4,10,10};
    countingSort(data);
    for (int i = 0; i < data.size();i++)
        cout << data[i] << " ";
    cout << endl;    
    return 0;
}
