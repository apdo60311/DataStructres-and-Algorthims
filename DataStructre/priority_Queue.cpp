#include <iostream>
#include <vector>
using namespace std;


template<typename T>
class Pqueue {
private:
    struct Node{
        Node(T val , int p) : value(val) , priority(p) {
        }
        T value;
        int priority;
    };
    vector<Node> heap;
    int get_left(int node_index) {
        int position = 2 * node_index + 1;
        return (position >= heap.size())? -1 : position;
    }
    int get_right(int node_index) {
        int position = 2 * node_index + 2;
        return (position >= heap.size())? -1 : position;
    }
    int get_parent(int node_index) {
        return (node_index == 0)? -1 : (node_index - 1) / 2;
    }
public:
    Pqueue() {}

    void enqueue(T value , int priority) {
        Node newNode(value , priority);
        heap.push_back(newNode);
        bubbleUp(heap.size() - 1 , newNode.priority);
    
    }

    void bubbleUp(int node_index , int priority) {
        // stops if root is reached or parent is smaller
        if(node_index == 0 || heap[get_parent(node_index)].priority < heap[node_index].priority) {
            return;
        }
        // swap node with its parent [in case it is smaller than its parent] 
        swap(heap[get_parent(node_index)] , heap[node_index]);
        // heapify up the parent
        bubbleUp(get_parent(node_index) , heap[get_parent(node_index)].priority);

    }

    Node dequeue() {
        Node popedNode = heap.front();
        heap[0] = heap.back();
        heap.pop_back();
        bubbleDown(0 , heap.front().priority);
        return popedNode;
    }

 
    void bubbleDown(int node_index ,int priority) {
        int left_child_index = this->get_left(node_index);
        if(left_child_index == -1) return; // return if the node is leaf [has no children]
        int right_child_index = this->get_right(node_index);

        // make left_child_index = right index if right child < left child
        if(right_child_index != -1 && heap[right_child_index].priority < heap[left_child_index].priority) {
            left_child_index = right_child_index; 
        }

        if(heap[node_index].priority > heap[left_child_index].priority) {
            swap(heap[node_index] , heap[left_child_index]); // swap 
            bubbleDown(left_child_index , heap[left_child_index].priority); // heapify again
        }
    }


    ~Pqueue() {}
};


int main(int argc, char const *argv[]) {
    Pqueue<int> Pq;
    Pq.enqueue(10,12);
    Pq.enqueue(100,5);
    Pq.enqueue(1000,14);
    Pq.enqueue(1,2);

    cout << Pq.dequeue().value << endl;
    cout << Pq.dequeue().value << endl;
    cout << Pq.dequeue().value << endl;
    cout << Pq.dequeue().value << endl;

    
    return 0;
}
