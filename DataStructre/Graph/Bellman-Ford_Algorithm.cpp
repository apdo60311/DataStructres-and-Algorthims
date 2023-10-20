#include <iostream>
#include <vector>
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

vector<Edge> edges; // array of edges

public:
    W_Graph() {

    }
    void addEdge(int from , int to , double cost) { // function to insert a new edge
        Edge edge(from , to , cost);
        edges.push_back(edge);
    }

    vector<int> bellManShortestPath() {
        // create distance array & intilaize it with positive infinity
        vector<int> dist(edges.size() , 999999999); // INFINITY
        dist[0] = 0; // intilaize the start with zero
        int v = edges.size() - 1; // number of vertcies
        for (size_t i = 0; i < v; i++) {
            for (auto edge : edges) {
                if(dist[edge.from] + edge.cost < dist[edge.to]) {
                    dist[edge.to] = dist[edge.from] + edge.cost;
                }
            }
        }

        for (size_t i = 0; i < v - 1; i++) {
            for (auto edge : edges) {
                if(dist[edge.from] + edge.cost < dist[edge.to]) {
                    dist[edge.to] = -999999999; // -INFINITY
                }
            }
        }
        
        return dist;
    }
    ~W_Graph() = default;
};




int main(int argc, char const *argv[]) {
    
    W_Graph Wg;
    Wg.addEdge(0,1,1);
    Wg.addEdge(1,2,1);
    Wg.addEdge(2,4,1);
    Wg.addEdge(4,3,-3);
    Wg.addEdge(3,2,1);
    Wg.addEdge(1,5,4);
    Wg.addEdge(1,6,4);
    Wg.addEdge(5,6,5);
    Wg.addEdge(6,7,4);
    Wg.addEdge(5,7,3);

    /*
        (0)--[1]-->(1)--[1]-->(2)<---\
            /   \              |      \
           [4]  [4]           [1]     [1]
           /      \            |        \
          V        V           |         \
         (6)<--[5]--(5)        V          \
          |         /         (4)--[-3]--(3)
         [4]      / 
          |     [3]
          V   /
         (7)<
    */

    vector<int> v = Wg.bellManShortestPath();

    for (auto &&i : v) {
        if(i == -999999999) {
            cout << "-INFINITY" << " ";
        }
        else if(i == 999999999) {
            cout << "INFINITY" << " ";
        }
        else {
            cout  << i << " ";
        }
    }
    cout << endl;

    return 0;
}
