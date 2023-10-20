#include <iostream>
#include<vector>
using namespace std;

void heapify(vector<int> & array , int n ,int i) {
    int greatest , left, right;
    greatest = i;                          
    left = 2 * i + 1;                                        
    right = 2 * i + 2;
    // check if the left child is greater than the root
    if(array[left] > array[greatest] &&left < n) {
        greatest = left;
    }
    // check if the right child is greater than the left
    if(array[right] > array[greatest] && right < n) {
        greatest = right;
    }

    // swap the greatest child with root & heapify the swaped node again
    if(greatest != i) {
        swap(array[greatest], array[i]);
        heapify(array , n ,greatest);
    }

}

void buildHeap(vector<int> &array) {
    for(int i = array.size() / 2 -1; i >= 0;i--) {
        heapify(array,array.size() ,i);
    }
}

void heapSort(vector<int> & array) {
    // build the max-heap first
    buildHeap(array);
    for(int i = array.size()-1; i >= 0; i--) {
        swap(array[i],array[0]);
        heapify(array,i,0);
    }

}

int main(int argc, char const *argv[]) {
    vector<int> array =  {1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17};
    heapSort(array);
    for(int i = 0; i < array.size();i++){
        cout << array[i] << " ";
    }
    cout << endl;
    return 0;
}
