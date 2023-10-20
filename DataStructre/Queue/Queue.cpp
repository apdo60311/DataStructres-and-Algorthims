#include <iostream>
#include <vector>
// #include "DoublyLinkedList"

using namespace std;


/// @brief Queue using Dynamic Array
 
template<typename T>
class Queue {
private:
    int Front;
    int End;
    int size;
    vector<T> data;
public:
    Queue() {this->Front = 0; this->End = 0; this->size = 0;};
    Queue(int size , T value) {
        this->Front = 0; 
        this->End = 0; 
        this->size = size;
        data.resize(size , value);
    };

    ~Queue() = default;

    bool isEmpty() const {return this->size == 0;}
    int getSize() const {return size;}

    void enqueue(const T& value) {
        data.push_back(value);
        size++;
        End++;
    }

    T dequeue() {
        if(isEmpty()) throw range_error("Empty queue"); 
        else this->size--; return data[Front++];
    }

};

// class LinkdedQueue {
//     private:

//     public:

// };

int main(int argc, char const *argv[]) {


    Queue<int> q;

    q.enqueue(100);
    q.enqueue(200);
    q.enqueue(300);
    q.enqueue(400);

    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    // cout << q.dequeue() << endl;
    // cout << q.dequeue() << endl;


    return 0;
}

