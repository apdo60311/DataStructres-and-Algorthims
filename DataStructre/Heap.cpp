#include <iostream>
#include <vector>
using namespace std;

class Heap {
private:
    vector<int> heap;
    int get_left(int node_index) {
        int position = 2 * node_index + 1;
        return (position >= this->heap.size())? -1 : position;
    }
    int get_right(int node_index) {
        int position = 2 * node_index + 2;
        return (position >= this->heap.size())? -1 : position;
    }
    int get_parent(int node_index) {
        return (node_index == 0)? -1 : (node_index - 1) / 2;
    }
    void bubble_up(int node_index) {
        // stops if root is reached or parent is smaller
        if(node_index == 0 || this->heap[this->get_parent(node_index)] < this->heap[node_index]) {
            return;
        }
        // swap node with its parent [in case it is smaller than its parent] 
        swap(this->heap[this->get_parent(node_index)] , this->heap[node_index]);
        // heapify up the parent
        bubble_up(this->get_parent(node_index));
    }
    void bubble_down(int node_index) {
        int left_child_index = this->get_left(node_index);
        if(left_child_index == -1) return; // return if the node is leaf [has no children]
        int right_child_index = this->get_right(node_index);

        // make left_child_index = right index if right child < left child
        if(right_child_index != -1 && this->heap[right_child_index] < this->heap[left_child_index]) {
            left_child_index = right_child_index; 
        }

        if(this->heap[node_index] > this->heap[left_child_index]) {
            swap(this->heap[node_index] , this->heap[left_child_index]); // swap 
            bubble_down(left_child_index); // heapify again
        }
    }


public:
    Heap(vector<int>& heap){
        this->heap = heap;
    }

    void push(int value);
    void pop();
    int get_top();
    int get_size();
    void print();
    ~Heap() = default;
};

int Heap::get_size() {
    return this->heap.size();
}

int Heap::get_top() {
    return this->heap.front();
}

void Heap::push(int value) {
    this->heap.push_back(value);
    this->bubble_up(this->heap.size() - 1);
}

void Heap::pop() {
    if(this->get_size() != 0) {
        this->heap[0] = this->heap.back(); // swap last element with root 
        heap.pop_back(); // pop up last element
        this->bubble_down(0); // heapify again from the root [last deleted element]
    }
}

void Heap::print() {
    for (int i : this->heap) {
        cout << i << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[]) {
    vector<int> heap;
    Heap h(heap);

    h.push(10);
    h.push(5);
    h.push(20);
    h.push(15);
    h.push(2);

    while (h.get_size()) { // heapsort mechanism
        cout << h.get_top() << endl;
        h.pop();
    }
    

    return 0;
}


