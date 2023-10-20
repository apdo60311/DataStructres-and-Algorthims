#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>

using namespace std;

template <typename T>
class adjacencyMatrix{
private:
    vector<vector<int>> Matrix;
    unordered_map<T , int> vertexIndecies;
    vector<T> vetrecies;
public:
    adjacencyMatrix(
        vector<vector<int>>& Matrix , 
        unordered_map<T , int> vertexIndecies , 
        vector<T> vetrecies
        ) : 
    Matrix(Matrix) , vertexIndecies(vertexIndecies) , vetrecies(vetrecies) {}

    adjacencyMatrix(int size , unordered_map<T , int> vertexIndecies , vector<T> vetrecies) {
        Matrix.assign(size,{0});
        for (auto &&i : Matrix) { i.assign(size,{0}); }
        this->vertexIndecies = vertexIndecies;
        this->vetrecies = vetrecies;
    }
    void addEdge(int i, int j) {
        if(i < getSize().first && j < getSize().second){
            Matrix[i][j] = 1;
            Matrix[j][i] = 1;
        }
        else {
            throw out_of_range("I is greater than rows or j is greater than columns");
        }
    }
    void removeEdge(int i, int j) {
        if(i < getSize().first && j < getSize().second){
            Matrix[i][j] = 0;
            Matrix[j][i] = 0;
        }
        else {
            throw out_of_range("I is greater than rows or j is greater than columns");
        }
    }
    void BFS(T source) { // source : vertex to start from
        queue<T> s;
        s.push(source);
        unordered_map<T, bool> visited;
        while (s.size()) {
            T current = s.front();
            s.pop();
            visited[current] = true;
            cout << current << " ";
            for (int i = 0; i < Matrix[vertexIndecies[current]].size(); i++) {
                if (Matrix[vertexIndecies[current]][i] == 1 && visited.count(vetrecies[i]) == 0) {
                    s.push(vetrecies[i]);
                    visited[vetrecies[i]] = true;
                }
            }
        }
    }

    void DFS(T source) { // source : vertex to start from
        stack<T> s;
        s.push(source);
        unordered_map<T, bool> visited;
        while (s.size()) {
            T current = s.top();
            s.pop();
            visited[current] = true;
            cout << current << " ";
            for (int i = 0; i < Matrix[vertexIndecies[current]].size(); i++) {
                if (Matrix[vertexIndecies[current]][i] == 1 && visited.count(vetrecies[i]) == 0) {
                    s.push(vetrecies[i]);
                    visited[vetrecies[i]] = true;
                }
            }
        }
    }

    pair<int , int> getSize() { // pair.first = i , pair.second = j
        return make_pair(Matrix.size(), Matrix[0].size());
    }
    void toString() { 
        for (size_t i = 0; i < Matrix.size(); i++) {
            for (size_t j = 0; j < Matrix[i].size(); j++) {
                cout << Matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    ~adjacencyMatrix() {}
};


int main(int argc, char const *argv[]) {
    
    unordered_map<char , int> vertexIndecies;
    vertexIndecies['A'] = 0;
    vertexIndecies['B'] = 1;
    vertexIndecies['C'] = 2;
    vertexIndecies['D'] = 3;
    vertexIndecies['E'] = 4;
    vertexIndecies['F'] = 5;
    vector<char> vetrecies = {'A' , 'B' , 'C' , 'D' , 'E' , 'F'};
    vector<vector<int>> Matrix = 
    {
        {0,1,0,0,0,1},
        {1,0,1,0,0,1},
        {0,1,0,1,1,0},
        {0,0,1,0,1,0},
        {0,0,1,1,0,1},
        {1,1,0,0,1,0}
    };
    adjacencyMatrix<char> adjMatrix(Matrix,vertexIndecies , vetrecies);
    adjMatrix.DFS('A');
    // adjMatrix.toString();
    return 0;
}
