#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int jumpSearch(vector<int> & data , int key) {
    int n = sqrt(data.size());
    for (int i = 0; i < data.size(); i+=n) {
        if (data[i] > key) {
            for (int j = i; j >=0; j--) {
                if(data[j] == key){
                    return j;
                }
            }
            
        }
        else if(data[i] == key) {
            return i;
        }
    }
    return -1;
}


int main(int argc, char const *argv[]) {
    vector<int> data = {1,2,3,4,5,6,7,8,9};
    cout << jumpSearch(data ,7) << endl;

    return 0;
}
