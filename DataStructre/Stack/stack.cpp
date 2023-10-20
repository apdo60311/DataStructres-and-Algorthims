#include <iostream>
#include <vector>

/// @brief Stack using Dynamic Array

using namespace std;

template<typename T>
class Stack {
private:
    int Top = -1;
    int size = 0;
    vector<T> data;
public:
    Stack() = default;
    ~Stack() = default;
    Stack(int size) {
        //! TODO set max size to vector
    };
    bool isEmpty() const { return Top < 0; }
    int getSize() const { return this->size;}
    void push(const T& value) {
        data.push_back(value);
        // data[Top++] = value;
        Top++;
        this->size++;
    }

    T pop() {
        if(isEmpty()) throw range_error("Stack is empty");
        else size--; return data[Top--];
    }
    T getTop() {
        return data[Top];
    }

};


int main(int argc, char const *argv[]) {
    Stack<int> s;
    s.push(1000);
    s.push(800);
    s.push(400);

    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;

    cout << "Size = " << s.getSize() << endl;

    return 0;
}
