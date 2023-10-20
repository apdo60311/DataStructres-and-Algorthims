#include <iostream>
#include <vector>

using namespace std;

int numOfways(vector<vector<char>>& grid ,int i = 0 , int j = 0) {
    if(grid[i][j] == 'E') return 1;
    if(grid[i][j] == '#') return 0;

    int count = 0;

    if(i+1 < grid.size() - 1) count += numOfways(grid, i + 1, j);
    if(j+1 < grid.size() - 1) count += numOfways(grid, i, j + 1);

    return count;

}

int main(int argc, char const *argv[]) {
    vector<vector<char>> grid = {
        {'S' , '.' , 'E' , '.'},
        {'.' , '.' , '.' , '.'},
        {'.' , '.' , '.' , '.'},
        {'.' , '.' , '.' , '.'},
    };
    int count = 0;
    
    cout << numOfways(grid , count) << endl;
    return 0;
}
