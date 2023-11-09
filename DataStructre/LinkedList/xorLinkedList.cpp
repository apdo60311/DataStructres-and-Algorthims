#include <iostream>

using namespace std;


template <typename T>
class xorLinkedList {

private:
    struct Node {
        T value;
        Node *both;
        Node() = default;
        Node(T value) {
            this->value = value;
        }
    };

    Node *head = new Node();
    Node *tail;

public:
    xorLinkedList(/* args */);
    ~xorLinkedList();

    Node* XOR(Node *first_pointer , Node *second_pointer) {
        return (Node*) ((uintptr_t) (first_pointer) ^ (uintptr_t) (second_pointer));
    };
    void insert_at_head(T value) {

        Node *new_node = new Node(value);
        new_node->both = XOR(nullptr , head);
        if (this->head) {
            head->both = XOR(new_node, XOR(head->both, nullptr));
        } else {
            tail = new_node;
        }
        head = new_node;
    };
    void insert_at_tail(T value) {
        Node *new_node = new Node(value);
        new_node->both = XOR(tail, nullptr);
        if (tail) {
            tail->both = XOR(new_node, XOR(tail->both, nullptr));
        }else {
            head = new_node;
        }
        tail = new_node;
    };



    Node* delete_from_head() {};
    Node* delete_from_tail() {};

    void print() {
        Node *current = head;
        Node *prev = nullptr;
        Node *next = nullptr;
        while (current) {
            cout << current->value << endl;
            next = XOR(prev , current->both);
            prev = current;
            current = next;

        }
        delete current;
        delete prev;
        delete next;
    }
};

template <typename T>
xorLinkedList<T>::xorLinkedList() {}

template <typename T>
xorLinkedList<T>::~xorLinkedList(){}


int main() {

    xorLinkedList<int> xl;

    xl.insert_at_head(10);
    // xl.insert_at_tail(11);
    // xl.insert_at_tail(12);
    // xl.insert_at_tail(13);

    xl.print();


    return 0;
}
