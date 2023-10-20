#include <iostream>
#include <vector>
#include <cmath>
using namespace std; 

void radixSort(vector<int>& data) {
    // find the greatest element
    int greatest_element = data[0];  
    
    for (int i = 1; i < data.size(); i++) {
        if(data[i] > greatest_element) {
            greatest_element = data[i];
        }
    }
    
    //count length of greatest element
    int greatest_element_length = 0;
    while(greatest_element != 0) {
        greatest_element /= 10;
        greatest_element_length++;
    }
    vector<int> b_array[10]; // array of buckets
    for(int i = 1; i <= greatest_element_length; i++) {
        for(int j = 0; j < data.size(); j++) {
            int power = pow(10,i);
            b_array[data[j]%power].push_back(data[j]);
        }
        /**
         * @bug segemntation fault (core dumped)
         */
        
    }    

}


int main(int argc, char const *argv[]) {
    
    vector<int> data = {3,4,654,32,546,2324,464};
    radixSort(data);

    return 0;
}
