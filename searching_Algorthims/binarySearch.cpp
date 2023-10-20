#include <iostream>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

int binarySearch(int start,int end , long val ,vector<long long> data) {
    int mid =  (start + end) / 2;
    
    if(start > end) {
        return -1;
        // return "Not founded!";
    }
    
    if(data[mid] == val){
        return mid;
        // return "Founded At Index: [" + to_string(mid) +']'; 
    }
    else if(data[mid] < val) {
        return binarySearch(mid+1,end,val,data);   
    }
    else {
        return binarySearch(start,mid-1,val,data);
    }

}

long long binarySearchIterative(int start,int end , int val ,vector<long long> data) {
    int  mid = 0;
    while(true) {
        mid = (start + end) / 2;
        if(start > end) {
            return -1;
            // cout << "Not founded!\n";
            break;
        }
        if(data[mid] == val) {
            // cout << "Founded At Index: [" << mid << "]" << endl;
            return mid;
            break;
        }
        else if(data[mid] < val) {
            start = mid+1;
        }
        else if(data[mid] > val) {
            end = mid-1;
        }
    }
}
// find the first occurence of the value
long long binarySearchIterativeDuplicate(int start,int end , int val ,vector<long long> data) {
    int  mid = 0;
    long long result = -1;
    while(true) {
        mid = (start + end) / 2;
        if(start > end) {
            return result;
            // cout << "Not founded!\n";
            break;
        }
        if(data[mid] == val) {
            // cout << "Founded At Index: [" << mid << "]" << endl;
            result = mid;
            end = mid - 1;
        }
        else if(data[mid] < val) {
            start = mid+1;
        }
        else if(data[mid] > val) {
            end = mid-1;
        }
    }

}


int main(int argc, char const *argv[]) {
    
    int n = 0;
    cin >> n;
    vector<long long> data(n);
    for(int i=0; i<n;i++) {
        cin >> data[i];
    }

    int N = 0;
    cin >> N;
    vector<long long> vals(N,-1);
    for (int i=0; i<N; i++) {
        cin >> vals[i];
    }

    for(int i=0; i< N; i++) {
        vals[i] = binarySearchIterativeDuplicate(0,data.size() , vals[i],data);
    }

    for(int i=0; i<N; i++) { 
        cout << vals[i]  << " ";
    }

    return 0;
}
