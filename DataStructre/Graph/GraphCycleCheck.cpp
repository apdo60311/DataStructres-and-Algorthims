#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class GraphCycleCheck {

private:
    vector<vector<int>> adjList;
    int n = 0;
public:
    GraphCycleCheck(int n) : n(n) {
        adjList.assign(n,{});
    }

    GraphCycleCheck(int n , vector<vector<int>> arr) : n(n){
        adjList.assign(n,{});
        for (auto &&i : arr) {
            adjList[i[1]].push_back(i[0]);
        }

    }
    bool checkUsingBfs(int vertex) {
        queue<int> q;
        unordered_map<int, bool> visited;
        // push all vertex neighbors to the queue
        for (size_t i = 0; i < adjList[vertex].size(); i++) {
            q.push(adjList[vertex][i]);
        }
        while (q.size()) {
            int current = q.front();
            q.pop();
            visited[current] = true;
            if(current == vertex) return true;
            for(int i = 0; i < adjList[current].size(); i++) {
                if(visited.count(adjList[current][i]) == 0){
                    q.push(adjList[current][i]);
                }
            }
        }
        return false;
    }
    bool containsCycles() {
        bool hasCycles = false;
        for (size_t vertex = 0; vertex < n; vertex++) {
            hasCycles = checkUsingBfs(vertex);
            if (hasCycles) { return false; }
        }
        return true;
    }
    void to_string() const {
        for (size_t i = 0; i < adjList.size(); i++) {
            for (size_t j = 0; j < adjList[i].size(); j++) {
                cout << adjList[i][j] << " ";
            }
            cout << endl;
        }
        
    }
    ~GraphCycleCheck();
};

GraphCycleCheck::~GraphCycleCheck(){}



int main(int argc, char const *argv[]) {
    vector<vector<int>> arr = {{1,0} , {0,1}};
    GraphCycleCheck check(2,arr);
    cout << check.containsCycles() << endl;
    // check.to_string();

    return 0;
}
