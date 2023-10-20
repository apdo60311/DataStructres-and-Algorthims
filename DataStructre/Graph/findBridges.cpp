#include <iostream>
#include <vector>
#include<map>
using namespace std;

// finding bridges using Tarjan's algorithm

class Graph { 

private:

    vector<vector<int>> graph;
    vector<int> idx, lowLink; /*idx : track dfs time */ 
    vector<pair<int , int>> bridges;
    int dfsTimer = 0;
    void dfs(int node , int parent) { 
        idx[node] = lowLink[node] = ++dfsTimer;
        for (size_t i = 0; i < graph[node].size(); i++) {
            int v = graph[node][i];
            if(idx[v] == 0) { // means it's not visited yet
                dfs(v, node);
                lowLink[node] = min(lowLink[node],lowLink[v]);
            }
            else if(v != parent) {
                lowLink[node] = min(lowLink[node], idx[v]);
            }
        }
        if(lowLink[node] == idx[node] && parent != -1) {
            bridges.push_back(make_pair(node,parent));
        }
    }

public:
    Graph(int size) {
        graph.assign(size,{});
        idx.assign(size,0);
        lowLink.assign(size,0);
    }

    void addEdge(int from , int to) { // function to insert a new edge
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    
    void getBridges(int u , int p) {
        this->dfs(u , p);
        for (auto &&bridge : bridges) {
            cout << "("  << bridge.first << ") - (" << bridge.second << ")" << endl;
        }
    }

    ~Graph() = default;
};


int main(int argc, char const *argv[]) {

    Graph graph(11);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);
    graph.addEdge(2, 5);
    graph.addEdge(5, 6);
    graph.addEdge(6, 7);
    graph.addEdge(7, 8);
    graph.addEdge(8, 5);

    graph.getBridges(0,-1);
    
    return 0;
}
