#pragma once

#include <iostream>
#include <vector>
#include <queue>

//! queue

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

//! stack

template<typename T>
class Stack {
private:
    int Top = -1;
    int size = 0;
    std::vector<T> data;
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

//! Linked List 

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


//! Dynamic Array

template<typename T>
class Darray {
    private:
        int size;
        int capacity;
        T* data = new T[capacity];
        T* temp_array;

        void merge(T* data, int start, int mid, int end) {
            int i = start , j = mid + 1 , k = 0;
            T* temp = new T[end - start +1];
            
            while (i <= mid && j <= end) {
                if(data[i] <= data[j]) {
                    temp[k] = data[i];
                    k++;
                    i++;
                }
                else{
                    temp[k] = data[j];
                    k++;
                    j++;
                }
            }
            
            while(i <= mid) {
                temp[k] = data[i];
                i++;
                k++;
            }
            while(j <= end) {
                temp[k] = data[j];
                j++;
                k++;
            }

            for(i=start; i <= end; i++) 
                data[i] = temp[i - start];
        }

        void mergeSort(T* data , int start, int end) {
            if(start < end) {
                int mid = (start + end) / 2;
                mergeSort(data, start, mid);
                mergeSort(data, mid + 1, end);
            
                merge(data ,start , mid, end);
            }
        }


    public:
        Darray() {
            size = 0;
            capacity = 0;
        }
        Darray(int size , int capacity = 0) {
            this->size = size;
            this->capacity = capacity;
        }
        ~Darray() {
            delete[] temp_array;
        }
        // checks if the array is empty
        bool isEmpty() {
            return size == 0;
        }
        // checks if the array is not empty
        bool isNotEmpty() {
            return size != 0;
        }
        bool enshure_capacity() {
            // checks if the capacity is inefficient
            return capacity >= size;     
        }
        void capacity_grow() {
            // capacity growth : size * 2
            capacity = size * 2;
            temp_array = new T[capacity]; // create new temp array 
            temp_array = data;
            
            data = new T[capacity];
            data = temp_array;



        }
        // add elements to the Dynamic Array
        void push_back(const T& value) {
            if (!enshure_capacity()) {
                capacity_grow();
            }
            data[size++] = value;
        }

        bool insertAt(const T& value , int index) {
            if (!enshure_capacity()) {
                capacity_grow();
            }
            if(index == size) {
                push_back(value);
            }
            else if (index > size) {
                throw runtime_error("Index out of bounds");
            }
            else {
                temp_array = new T[size + 1];
                for (int i = 0 , j = 0; i <= size;i++ , j++) {
                    if(i == index) {
                        temp_array[i] = value; 
                        j--;
                    }
                    else {
                        temp_array[i] = data[j];
                    }
                }
                size++;
                // data = new T[size];
                data = temp_array;
            }
            return true;
        }

        bool replace(const T& value , int index) {
            if(index < size && index >= 0){
                data[index] = value;
                return true;
            } 
            else {
                throw runtime_error("Index out of bounds");
            }
        }

        void pop_back() {
            if(isEmpty()) {
                throw runtime_error("Dynamic Array is empty");
            }
            else {
                data[--size] = NULL;
            }
        }
        void swap(int index1 , int index2 ) {
            T temp;
            temp = data[index1];
            data[index1] = data[index2];
            data[index2] = temp;
        }
        bool deleteAt(int index) {
            if(isEmpty()) {
                throw runtime_error("Dynamic Array is empty");
            }
            else {
                temp_array = new T[size--];
                for (int i = 0 , j = 0; i <= size;i++ , j++) {
                    if(i == index) {
                        j--;
                        continue;
                    }
                    else {
                        temp_array[j] = data[i];
                    }
                }
                data = temp_array;
            }
        }

        bool contains(const T& value) {
            for (int i = 0; i < size; i++) {
                if(data[i] == value) {
                    return true;
                }
            }            
            return false;
        }
        void clear() {
            size = 0;
            capacity = 0;
        }
        // sort elements using merge sort
        void sort() {
            mergeSort(data,0, size - 1);
        }
        
        int length() {
            return this->size;
        }

        void printALL() {
            for (int i = 0; i < size; i++) {
                cout << data[i] << endl;
            }
        }
        T& operator [] (int i) {return data[i];}

};


//! Heap

class Heap {
private:
    std::vector<int> heap;
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
        std::swap(this->heap[this->get_parent(node_index)] , this->heap[node_index]);
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
            std::swap(this->heap[node_index] , this->heap[left_child_index]); // swap 
            bubble_down(left_child_index); // heapify again
        }
    }


public:
    Heap(std::vector<int>& heap){
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
        std::cout << i << " ";
    }
    std::cout << std::endl;
}



//! Priority queue

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


//! TREE
template<typename T>//using generic type
class tree {
private:
    struct Node { //? tree node
        T value;
        Node* left;
        Node* right;
    };
    Node* root = nullptr;
    Node* current; //? temp Node* pointer used for traversing
    Node* newNode; //? temp Node used for inserting new node to the tree
public:
    tree() = default;
    tree(vector<T> nodes) {
        int ptr = 0;
        queue<Node*> queue;
        if (nodes.size() == 0) {throw length_error("Cannot insert Empty Array!");}
        else {
            if(this->root == NULL) {
                if(nodes.at(0) == 0) {throw logic_error("Null element cannot be inserted!"); } 
                else {
                    newNode = new Node();
                    newNode->value = nodes[0];
                    this->root = newNode;
                    ptr++;
                    queue.push(this->root);

                    while (queue.size()) { // while queue is not empty
                        current = queue.front();
                        queue.pop();
                        // left child
                        if(current->left != NULL) { 
                            newNode = new Node();
                            newNode->value = nodes[ptr];
                        }
                        else {
                            newNode = new Node();
                            newNode->value = nodes[ptr];
                            current->left = newNode;
                            queue.push(newNode);
                        }
                        ptr++;
                        if(ptr == nodes.size()) break;
                        // right child
                        if(current->right != NULL) { 
                            newNode = new Node();
                            newNode->value = nodes[ptr];
                        }
                        else {
                            newNode = new Node();
                            newNode->value = nodes[ptr];
                            current->right = newNode;
                            queue.push(newNode);
                        }
                        ptr++;
                        if(ptr == nodes.size()) break;

                    }
                }
            }

        }
    }
    //! freeup allocated memory
    ~tree() {
        delete current;
        // delete newNode;
    };
    void insert(T val) {
        newNode = new Node();
        newNode->value = val;
        if(root == nullptr) {
            root = newNode;
        }
        else {
            current = root;
            while (true) {
                if(current->value > val) {
                    if(current->left == NULL) {
                        current->left = newNode;
                        break;
                    }
                    current = current->left;
                }
                else {
                    if(current->right == NULL) {
                        current->right = newNode;
                        break;
                    }
                    current = current->right;
                }
            }
            
        }
    }

    bool find(T val) {
        if(root == NULL) return false;
        else {
            current = root; 
            while (true) {
                if(current->value == val and current != NULL) return true;
                if(current->value > val) {
                    if(current->left == NULL && current->value != val) return false;
                    current = current->left;
                }
                else {
                    if(current->right == NULL && current->value != val) return false;
                    current = current->right;
                }
           }
        }
            
    }

    Node* find_Node(T val) {
        if(root == NULL) return NULL;
        else {
            current = root; 
            while (true) {
                if(current->value == val) return current;
                if(current->value > val) {
                    if(current->left == NULL && current->value != val) return NULL;
                    current = current->left;
                }
                else {
                    if(current->right == NULL && current->value != val) return NULL;
                    current = current->right;
                }
           }
        }
            
    }

    void inOrder(Node *root) {
        if (root != NULL) {
            inOrder(root->left);
            cout << root->value << " ";
            inOrder(root->right);
        }
    }

    Node* getParent(Node* root , Node* node) {
        if (root != NULL) {
            getParent(root->left , node);
            if(root->right == node || root->left == node) {
                return root;
            }
            getParent(root->right , node);
        }
        return NULL;
    }

    /**
     * @name getHeight
     * @param root the node from which traverse the tree
     * @return the height of the root node //! 1-indexed [leaf node height = 1]
     * @note  root can be any node 
     * 
    */


    int getHeight(Node* root) {
        int height = 0;
        if (root != NULL) {
            height = max(getHeight(root->left) , getHeight(root->right));
            height++;
        }
        return height;
    }

    /**
     * @name getDepth
     * @param node The node which we want to get its depth
     * @return the depth of the node  //! 0-indexed [root depth = 0]
     * 
    */


    int getDepth(Node* node) {
        int depth = 0;
        if(root == NULL) return -99;
        else {
            current = this->root; 
            while (true) {
                if(current == node) return depth;
                else if(current->value > node->value) {
                    if(current->left == NULL && current->value != node->value) return -99;
                    current = current->left;
                    depth++;
                }
                else {
                    if(current->right == NULL && current->value != node->value) return -99;
                    current = current->right;
                    depth++;
                }
           }
        } 
        return depth;
    }

    /**
     * @name getLeafNodes
     * @param root the node from which traverse the tree
     * @return vector of all leaf nodes
     * 
    */

    vector<Node*> getLeafNodes(Node* root) {
        static vector<Node*> vect;
        if (root != NULL) {
            getLeafNodes(root->left);
            if(getHeight(root) == 1) {
                vect.push_back(root);
            }
            getLeafNodes(root->right);
        }
        return vect;        
    }

    vector<Node*> BFS() {
        vector<Node*> array;
        if (this->root == NULL) return array;
        queue<Node*> queue;
        current = this->root;
        queue.push(current);
        while (queue.size() != 0) {
            current = queue.front();
            array.push_back(current);
            queue.pop();
            if(current->left != NULL) queue.push(current->left);
            if(current->right != NULL) queue.push(current->right);
        }
        return array;
    }

    vector<vector<Node*>> levelOrderTraversal() {
        vector<vector<Node*>> result;
        if (this->root == NULL) return result;
        
        queue<Node*> Queue;

        current = this->root;
        Queue.push(current);
        while (Queue.size() != 0) {
            vector<Node*> array; // array to store current level nodes
            int queue_length = Queue.size();            
            int ptr = 0;
            while(ptr < queue_length) { // to push each level as an array
                current = Queue.front();
                Queue.pop();
                array.push_back(current); 
                if(current->left != NULL) Queue.push(current->left);
                if(current->right != NULL) Queue.push(current->right);
                ptr++;
            }
            result.push_back(array);
        }

        return result;
    }

    /**
     * @brief print the nodes which will appear if you look to the tree from right
     * @return vector of these nodes
    */

    vector<Node*> rightView() {
        vector<Node*> result;
        if (this->root == NULL) return result;
        
        queue<Node*> Queue;

        current = this->root;
        Queue.push(current);
        while (Queue.size() != 0) {
            int queue_length = Queue.size();            
            int ptr = 0;
            while(ptr < queue_length) { // to push each level as an array
                current = Queue.front();
                Queue.pop();
                if(current->left != NULL) Queue.push(current->left);
                if(current->right != NULL) Queue.push(current->right);
                ptr++;
                if(ptr == queue_length) cout << current->value << endl;
            }
        }

        return result;
    }

    /**
     * @brief print the nodes which will appear if you look to the tree from left
     * @return vector of these nodes
    */

    vector<Node*> leftView() {
        vector<Node*> result;
        if (this->root == NULL) return result;
        
        queue<Node*> Queue;

        current = this->root;
        Queue.push(current);
        while (Queue.size() != 0) {
            int queue_length = Queue.size();            
            int ptr = 0;
            while(ptr < queue_length) { // to push each level as an array
                current = Queue.front();
                Queue.pop();
                if(current->left != NULL) Queue.push(current->left);
                if(current->right != NULL) Queue.push(current->right);
                ptr++;
                if(ptr == 1) cout << current->value << endl;
            }
        }

        return result;
    }

    void swap(Node* n1, Node* n2) { //! Not Working...
        if(n1 == NULL || n2 == NULL) return;
        current  = n1;
        n1 = n2;
        n2 = current;
    }

    /**
     * @name invert
     * @brief this function act like a mirror to the tree [sawp left and right of each node]
     * @param cur -> root from which to start invertion [recursive version only]
     * @param noparams -> itrative version [start from root]
    */

    void invert(Node* cur) {
        if (cur != NULL) {
            current = cur->left;
            cur->left = cur->right;
            cur->right = current;
            invert(cur->left);
            invert(cur->right);
        }
        
    }

    void invert() {
        if (this->root == NULL) return;
        
        queue<Node*> Queue;
        current = this->root;
        Queue.push(current);

        while (Queue.size() != 0) {
            int queue_length = Queue.size();            
            int ptr = 0;
            while(ptr < queue_length) { // to push each level as an array
                current = Queue.front();
                Queue.pop();
                if(current->left != NULL) Queue.push(current->left);
                if(current->right != NULL) Queue.push(current->right);
                ptr++;
                // swapping
                Node* temp = current->left;
                current->left = current->right;
                current->right = temp;
            }
        }
    }

    int diameter(Node* root) {
        int max_height = 0;
        if (root != NULL) {
            diameter(root->left);
            max_height = max(getHeight(root->left) + getHeight(root->right) , max_height); 
            diameter(root->right);
        }
        return max_height;
    }

    int diameter() {
        return this->diameter(this->root);
    }

    Node* sortedArrayToTree(vector<T>& Array) {
        return this->SATT(Array , 0 , Array.size() - 1);
    } 

    Node* SATT(vector<T>& Array , int start, int end) {
        if(start > end) return NULL;     
        int middle = (start + end) / 2;
        Node* node = new Node();
        node->value = Array[middle];
        node->left = SATT(Array, start, middle - 1);
        node->right = SATT(Array, middle + 1 , end);
        return node;
    }

    Node* getPredessucor(Node* node) {

    }

    Node* getSucsessor(Node* node) {
        if(node->right == NULL) return node;
        current = node->right;
        while (current->left != NULL) {
            current = current->left;
        }
        return current;
    }

    Node* remove(Node* root,Node* node) {
        if(root == NULL) return root; // return NULL if root is NULL

        if(node->value > root->value) {
            root->right = remove(root->right ,node);
        }
        else if (node->value < root->value) {
            root->left = remove(root->left ,node);
        }
        else { // when desired node is founded
            // leaf nodes' case
            if(root->left == NULL && root->right == NULL) {
                return NULL; // root's left or right will be NULL 
            }
            // one child cases
            else if (root->right == NULL) {
                Node* child = root->left;
                delete root;
                return child;
            }
            else if(root->left == NULL) {
                Node* child = root->right;
                delete root;
                return child;
            }
            // two children case
            else {
                Node* sucss = this->getSucsessor(root);
                root->value = sucss->value;
                root->right = this->remove(root->right,sucss);
            }
        }
        return root;
    }
    //! for testing purposes only
    void test() {
        cout << "root = " << root->value << endl;
        cout << "root rigth = " << root->right->value << endl;
        cout << "root left = " << root->left->value << endl;
    
    }
};

/*
            (10) h = 5                                        (10)
            /  \                                              /  \ 
          (5)  (17) h = 4                                  (17)  (5)
          /    /   \                                       /  \   / \ 
         /    /     \                                     /   (4) /   \
       (4)   (12)   (20) h=3            invert         null     (20)  (12)
            /  \                        ----->                         / \
          (11) (13) h=2                                             (13) (11)
                  \                                                      /
                 (14) h=1                                              (14)
                   \                                                   /
                   (15) h=0                                          (15)
*/              
   // INORDER:  4 5 10 11 12 13 15 20
   // BFS: 10 5 17 4 12 20 11 13 14 15                 10 17 5 4 20 12 13 11 14 15

