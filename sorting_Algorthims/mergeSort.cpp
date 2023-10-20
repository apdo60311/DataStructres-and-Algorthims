#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& data , int start, int mid, int end) {
    int i = start , j = mid + 1 , k = 0;
    vector<int> temp(end - start +1);
    
    while (i <= mid && j <= end) {
        if(data[i] <= data[j]) {
            temp[k] = data[i];
            k++;
            i++;
        }
        else{
            temp[k] = data[j];
            k++;
            j++;
        }
    }
    
    while(i <= mid) {
        temp[k] = data[i];
        i++;
        k++;
    }
    while(j <= end) {
        temp[k] = data[j];
        j++;
        k++;
    }

    for(i=start; i <= end; i++) 
        data[i] = temp[i - start];
}

void mergeSort(vector<int>& data , int start, int end) {
    if(start < end) {
        int mid = (start + end) / 2;

        mergeSort(data, start, mid);
        mergeSort(data, mid + 1, end);
    
        merge(data ,start , mid, end);
    }
}


int main(int argc, char const *argv[]) {

    vector<int> data = {12, 11, 13, 5, 6, 7 };
    mergeSort(data, 0 , data.size()-1);
    for(int i=0; i < data.size(); i++) {
        cout << data[i] << " ";
    }
    cout << endl;
    return 0;
}
