#include <iostream>
#include <vector>
using namespace std;

vector<string> initializeGrid(int n) {
    vector<string> nq;
    for (int i = 0; i < n; i++) {
        string str = "";
        for (int j = 0; j < n; j++) {
            str += '.';
        }
        nq.push_back(str);
    }
    return nq;
}


bool isValid(vector<string>& grid , int row , int col , int n) {
    for (int i = 0; i < n; i++) {
        if(grid[row][i] == 'Q') return false;
    }
    for (int i = row , j = col; i >= 0 && j >= 0; i-- , j--) {
        if(grid[i][j] == 'Q') return false;
    }
    for (int i = row , j = col; i < n && j >= 0; i++ , j--) {
        if(grid[i][j] == 'Q') return false;
    }
    return true;
}

void NQueens(int n , int col, vector<string>& grid , vector<vector<string>>& result) {
    if(n == col) {
        result.push_back(grid);
        return;
    }

    for (int i = 0; i < n; i++) {
        if(isValid(grid , i, col ,n)) {
            grid[i][col] = 'Q';
            NQueens(n, col + 1, grid , result);
            grid[i][col] = '.';
        }
    }
}


int main(int argc, char const *argv[]) {
    int n = 4;
    vector<string> nq = initializeGrid(n);
    vector<vector<string>> vofstr;
    NQueens(n , 0, nq ,vofstr);
    
    for (int i = 0; i < vofstr.size(); i++) {
        for (int j = 0; j < n; j++) {
            cout << vofstr[i][j] << endl;
        }
        cout << endl;
    }
    

    return 0;
}
