#include <iostream>

using namespace std;

template<typename T>

class DoublyLinkedList {
private:
    struct Node {
        T value;
        Node * next;
        Node * prev;
    };
    Node * Head;
    Node * Tail;
    Node * current;
    Node * newNode;
    bool circle = false;
    int size = 0;
    
public:
    DoublyLinkedList(/* args */) = default;
    ~DoublyLinkedList() {
        free(newNode);
        free(current);
    };

    bool isEmpty() const { return size == 0; }
    bool isCircle() const { return circle;}
    int getSize() const { return size; }
    
    void addFromTail(const T& value) {
        if (isEmpty()) {
            newNode = new Node();
            newNode->value = value;
            Head = newNode;
            Tail = newNode;
            size++;
        }
        else {
            newNode = new Node();
            newNode->value = value;
            newNode->prev = Tail;
            Tail->next = newNode;
            Tail = newNode;
            size++;
        }
    }

    void addFromHead(const T& value) {
        if (isEmpty()) {
            newNode = new Node();
            newNode->value = value;
            Head = newNode;
            Tail = newNode;
            size++;
        }
        else {
            newNode = new Node();
            newNode->value = value;
            newNode->next = Head;
            Head->prev = newNode;
            Head = newNode;
        }
    }

    void addAt(const T& value , int index) {
        if (index > size) throw range_error("index out of range");
        else if (index == 0)  addFromHead(value); 
        else if (index == size) addFromTail(value);
        else {
            current = Head;
            newNode = new Node();
            newNode->value = value;
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }        
            newNode->next = current->next;
            current->next->prev = newNode;
            current->next = newNode;
            newNode->prev = current;
        }
    }

    void removeFromTail() {
        if (isEmpty()) throw runtime_error("List is empty");
        else {
            current = Tail->prev;
            current->next = NULL;
            Tail->prev = NULL;
            Tail = current;
            size--;
        }
    }

    void removeFromHead() {
        if (isEmpty()) throw runtime_error("List is empty");
        else {
            current = Head->next;
            current->prev = NULL;
            Head->next = NULL;
            Head = current;
            size--;
        }
    }

    void print() {
        current = Head;
        while (current != Tail) {
            cout << current->value << " ";
            current = current->next;            
        }
        cout << Tail->value << endl;
    }
    void printReversed() {
        current = Tail;
        while (current != Head->prev) {
            cout << current->value << " ";
            current = current->prev;            
        }
        cout << endl;        
    }
    void makeCircly() {
        circle = true;
        Head->prev = Tail;
        Tail->next = Head;
    }
};

int main(int argc, char const *argv[]) {

    DoublyLinkedList<int> l;

    l.addFromTail(21);
    l.addFromTail(41);
    l.addFromTail(31);

    l.addFromHead(210);
    // l.removeFromTail();
    // l.removeFromTail();
    // l.removeFromHead();
    // l.removeFromHead();
    l.makeCircly();
    l.addAt(444,0);
    l.printReversed();

    return 0;
}
