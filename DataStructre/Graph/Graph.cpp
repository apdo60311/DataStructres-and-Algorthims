#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Graph {
private:
    // unorderd map to store graph as adjacency list
    unordered_map<char, vector<char>> data; // key = vertix , value = vector of neighbors 
public:
    Graph(unordered_map<char, vector<char>>& data) : data(data) {}
    void DFS(char source) { // source : the first vertex of the graph
        stack<char> s;
        s.push(source);
        while (s.size()) {
            char current = s.top(); // get the top vertex in the stack
            s.pop();
            cout << current << " ";
            for (auto neighbor : data[current]) { // push neighbors of the current vertex to the stack
                s.push(neighbor);
            }
        }
    }   
    // Recursive Method
    void DFSREC(char source) { // source : the first vertex of the graph
        cout << source << " ";
        for (auto &&neighbor : data[source]) {
            DFSREC(neighbor);
        }
    }   


    void BFS(char source) { // source : the first vertex of the graph
        queue<char> q;
        q.push(source);
        while (q.size()) {
            char current = q.front();
            q.pop();
            cout << current << " ";
            for (auto &&neighbor : data[current]) {
                q.push(neighbor);
            }
            
        }
        cout << endl;
    }

    bool hasPath(char source , char dist) { // using DFS starting from source till destination
        stack<char> s;
        s.push(source);
        while (s.size()) {
            char current = s.top(); // get the top vertex in the stack
            s.pop();
            if(current == dist) {
                return true;
            }
            for (auto neighbor : data[current]) { // push neighbors of the current vertex to the stack
                s.push(neighbor);
            }
        }
        return false;
    }

    ~Graph(){}
};

/*
    (a)------>(c)------->(e)
     |         
     |         
     |         
     V         
    (b)------>(d)------->(f)

    (K)------>(N)
*/
//acbedf

int main(int argc, char const *argv[]) {
    unordered_map<char, vector<char>> data; 
    data['a'] = {'c','b'};
    data['b'] = {'d'};
    data['c'] = {'e'};
    data['d'] = {'f'};
    data['e'] = {};
    data['f'] = {};
    data['k'] = {'N'};
    
    Graph graph(data);
    // graph.DFS('a');
    // cout << endl;
    // graph.DFSREC('a'); 
    // cout << endl;
    // graph.BFS('a');
    cout << graph.hasPath('a' , 'k')  << endl;
    return 0;
}
