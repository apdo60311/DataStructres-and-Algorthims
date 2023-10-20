#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

class W_Graph { // weighted graph for implementing bell-man ford algorithm
private:
    struct Edge {
        double cost; // weight of the edge 
        int from , to; 
        Edge(int from , int to , double cost) {
            this->from = from;
            this->to = to;
            this->cost = cost;
        }
    };
    int n = 0;
    vector<vector<Edge>> edges; // array of edges
    priority_queue<Edge ,vector<Edge>> pq;
    map<int , bool> visited;
    vector<Edge> mst;

public:
    W_Graph(int n) {
        this->n = n; // number of nodes in the graph
    }
    void addEdgeD(int from , int to , double cost) { // function to insert a new edge
        Edge edge(from , to , cost);
        edges[from].push_back(edge);
    }

    void addEdgeUND(int from , int to , double cost) { // function to insert a new edge
        this->addEdgeD(from , to , cost);
        this->addEdgeD(to , from , cost);
    }


    void mstGenerator(int start = 0) {
        int m = n - 1; // number of edges in MST
        int edgeCount = 0, mstCount = 0;

        int minCost = 0;

        visited[start] = true;
        for (auto &&edge : edges[0]) {
            if(visited.count(edge.to)) {
                pq.push(edge);
            }      
        }
        
        while (!pq.empty() && edgeCount != m) {
            Edge edge = pq.top(); pq.pop();
            int currentNodeIndex = edge.to;
        
            if(visited.count(currentNodeIndex)) continue;
            mst.push_back(edge);
            edgeCount++;
            minCost += edge.cost;


            visited[currentNodeIndex] = true;
            
            vector<Edge>::iterator it = edges[currentNodeIndex].begin();

            for (; it != edges[currentNodeIndex].end(); it++){
                if(visited.count(it->to)) {
                    pq.push(*it);
                }                      
            }
        }
    }

    void printMst() {
        for (size_t i = 0; i < mst.size(); i++) {
            cout << mst[i].from << mst[i].to << endl;
        }
        
    }
    ~W_Graph() = default;
};


int main(int argc, char const *argv[]) {
    
    W_Graph graph(7);

    // graph.addEdgeUND(0, 1, 9);
    // graph.addEdgeUND(0, 2, 0);
    // graph.addEdgeUND(0, 3, 5);
    // graph.addEdgeUND(0, 5, 7);
    // graph.addEdgeUND(1, 3, -2);
    // graph.addEdgeUND(1, 4, 3);
    // graph.addEdgeUND(1, 6, 4);
    // graph.addEdgeUND(2, 5, 6);
    // graph.addEdgeUND(3, 5, 2);
    // graph.addEdgeUND(3, 6, 3);
    // graph.addEdgeUND(4, 6, 6);
    // graph.addEdgeUND(5, 6, 1);

    // graph.mstGenerator();
    // graph.printMst();
    return 0;
}
