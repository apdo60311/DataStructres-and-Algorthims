#include <iostream>

using namespace std;

template<typename T>
class LinkedList {
private:
    struct Node {
        T value;
        Node * next;
    };
    Node * head;
    Node * tail;
    Node * current;
    Node * new_node;
    int size = 0;
public:
    LinkedList() {

    }
    ~LinkedList() {

    }
    void add(const T& value) {
        if (size == 0) {
            new_node = new Node;
            new_node->value = value;
            head = new_node;
            tail = new_node;
            size++;
        }
        else {
            new_node = new Node;
            new_node->value = value;
            tail->next = new_node;
            tail = new_node;
            size++;
        }
    }
    void insertAt(const T& value , int index) {
        current = head;     // 4 13 3 3
        new_node = new Node;
        new_node->value = value;
        for (int i = 0; i < size; i++) {
            if(index - 1 == i) {
                new_node->next = current->next;
                current->next = new_node;
            }
            current = current->next;
        }
        size++;
    }

    void remove() {
        current = head;
        while(current->next != tail) {
            current = current->next;
        }

        current->next = nullptr;
        tail = current;
        size--;
    }

    void removeAt(int index) {
        current = head;     // 4 13 3 9
        for (int i = 0; i < size; i++) {
            if(index - 1 == i) {
                current->next = current->next->next;
                break;
            }
            current = current->next;
        }
        size--;
    }

    void reverse() {
        Node* prev = NULL , *Curr = head , *Next = NULL;
        while(Curr != NULL) {
            Next = Curr->next;// move Next ptr to the next of current ptr
            Curr->next = prev; // make current ptr point to its previous
            prev = Curr;
            Curr = Next;
        }
        head = prev;
    }

    void printALL() {
        current = head;
        while (current != NULL) {
            cout << current->value << endl;
            current = current->next;
        }
        
    } 
};





int main(int argc, char const *argv[]) {

    LinkedList<int> ls;
    
    ls.add(5);
    ls.add(4);
    ls.add(2);
    
    ls.insertAt(10, 1);
    // ls.remove();
    ls.add(50);
    // ls.removeAt(1);
    // ls.reverse();
    ls.printALL();

    return 0;
}
