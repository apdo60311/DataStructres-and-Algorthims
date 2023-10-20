#include <iostream>
#include <vector>
using namespace std;

/*using first element as pivot*/
int partition(vector<int> &data,int start,int end) {
    int i = start - 1 , j = end + 1;
    int pivot = data[start];
    while (true) {
        do {
            i++;
        }while (data[i] < pivot);

        do {
            j--;
        }while(data[j] > pivot);

        if (i >= j) {
            return j;
        }
        swap(data[i],data[j]);
    }
}
void quickSort(vector<int> &data,int start,int end) {
    if(start < end) {
        int pivot = partition(data , start , end);
        quickSort(data, start , pivot);
        quickSort(data, pivot + 1 ,end);
    }
}
int main(int argc, char const *argv[]) {   
    vector<int> data = {4,2,5,1,7,3};
    quickSort(data,0,data.size()-1);
    for(int i = 0; i < data.size();i++) {
        cout << data[i] << " ";
    }
    cout << endl;
    return 0;
}
