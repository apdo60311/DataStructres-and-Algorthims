#include <iostream>
#include <vector>
#include <map>
using namespace std;

bool wordSearch(vector<vector<char>>& grid , string target ,int i = 0, int j = 0 , int counter = 0 , map<string, int>db = {}) {
    if(counter == target.length()) return true;
    if(i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size()) return false;
    string key = to_string(i) + "-" + to_string(j);
    if(db.count(key) != 0) return false;
    if(target[counter] != grid[i][j]) return false;

    db[key]++;

    bool result = 
        wordSearch(grid ,target, i , j + 1 , counter + 1 , db) 
    || wordSearch(grid ,target, i , j - 1 , counter + 1 , db)
    ||  wordSearch(grid ,target, i + 1, j , counter + 1 , db)
    ||  wordSearch(grid ,target, i - 1, j , counter + 1 , db);

    db.erase(key);
    return result;
}
// ABCCED
int main(int argc, char const *argv[]) {
    vector<vector<char>> grid = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    cout << wordSearch(grid,"SEE") << endl;
    cout << wordSearch(grid,"ABCB") << endl;

    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[i].size(); j++) {
            cout << wordSearch(grid,"SE24E", i , j) << endl;
        }        
    }
    

    return 0;
}
