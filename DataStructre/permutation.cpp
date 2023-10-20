#include <iostream>
#include <vector>
#include <map>

using namespace std;


void permHelperUniq(vector<int> elements , int i , map<vector<int> , int> &all) {
    if(i == elements.size()){ 
        all[elements]++;
        return;    
    }
    for(int j = i; j < elements.size();j++) {
        swap(elements[i], elements[j]);
        permHelperUniq(elements, i+1, all);
        swap(elements[i], elements[j]);
    }
}


void permHelper(vector<int> elements , int i , vector<vector<int>>& all) {
    if(i == elements.size()){ 
        all.push_back(elements);
        return;    
    }
    for(int j = i; j < elements.size();j++) {
        swap(elements[i], elements[j]);
        permHelper(elements, i+1, all);
        swap(elements[i], elements[j]);
    }
}

vector<vector<int>> permutation(vector<int> elements) {
    vector<vector<int>> allPermutations;
    permHelper(elements, 0 ,allPermutations);
    return allPermutations;
}

int main(int argc, char const *argv[]) {
    vector<int> v= {1, 2, 3};
    vector<vector<int>> vv = permutation(v);

    for (int i = 0; i < vv.size(); i++){
        for (int j = 0; j < vv[i].size();j++) {
            cout << vv[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
