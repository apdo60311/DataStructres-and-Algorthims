#include<iostream>
#include<vector>
#include<queue>

using namespace std;

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

    Node* trimHelper(Node* rootNode , T low , T high) {
        if (rootNode == NULL) return NULL;

        if (rootNode->value > high) return trimHelper(rootNode->left , low , high);
        if (rootNode->value < low) return trimHelper(rootNode->right , low , high);

        rootNode->left = trimHelper(rootNode->left , low , high);
        rootNode->right = trimHelper(rootNode->right , low , high);
        return rootNode;
    }

    int maxPathSumHelper(Node* root , int& maxSum) {
        if (root == NULL) { return 0; }

        int leftMaxSum = maxPathSumHelper(root->left , maxSum);
        int rightMaxSum = maxPathSumHelper(root->right , maxSum);

        // handle negative numbers case 
        leftMaxSum = max(leftMaxSum, 0);
        rightMaxSum = max(rightMaxSum, 0);

        maxSum = max(maxSum, root->value + leftMaxSum + rightMaxSum);

        return root->value + max(leftMaxSum, rightMaxSum);
    }


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
    void trim(T low, T high) {
        this->trimHelper(this->root, low , high);
    }
    
    int maxPathSum (Node *root = NULL) {
        if (root == NULL) root = this->root;
        int maxSum = -9999999999;
        this->maxPathSumHelper(root, maxSum);
        return maxSum;
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


int main(int argc, char const *argv[]) {
    // vector<int> v = {10 ,5 ,17 ,4 ,12 ,20 ,11 ,13 ,14 ,15};
    tree<int> tr;
    tr.insert(10);
    tr.insert(5);
    tr.insert(17);
    tr.insert(20);
    tr.insert(12);
    tr.insert(11);
    tr.insert(13);
    tr.insert(4);
    tr.insert(14);
    tr.insert(15);


    // tr.remove(tr.find_Node(10),tr.find_Node(13));
    // tr.inOrder(tr.find_Node(10));
    // cout << tr.find(13) << endl;
    // cout << tr.getSucsessor(tr.find_Node(15))->value << endl;
    // cout << tr.getDepth(tr.find_Node(20)) << endl;
    
    //? TESTING: get Leaf Nodes 
    // auto v = tr.getLeafNodes(tr.find_Node(10));
    // for(auto i : v) {
    //     cout << i->value << endl;
    // }
    
    //? TESTING: bradth first search
    // auto bfs = tr.BFS();
    // for(auto i : bfs) {
    //     cout << i->value << " "; //10 5 17 4 12 20 11 13 14 15
    // }
    // cout << endl;

    //? TESTING: level order traversal
    // auto vv = tr.levelOrderTraversal();
    // for(int i = 0; i < vv.size(); i++) {
    //     for(int j = 0; j < vv[i].size(); j++) {
    //         cout << vv[i][j]->value << " ";
    //     }
    //     cout << endl;
    // }

    //? TESTING: right view
    // auto rv = tr.rightView();    
    // for(auto i : rv) {
    //     cout << i->value << endl;
    // }

    //? TESTING: left view

    // auto lv = tr.leftView();    
    // for(auto i : lv) {
    //     cout << i->value << endl;
    // }


    //? TESTING: tree trim function
    // tr.trim(4,15);
    // auto vv = tr.levelOrderTraversal();
    // for(int i = 0; i < vv.size(); i++) {
    //     for(int j = 0; j < vv[i].size(); j++) {
    //         cout << vv[i][j]->value << " ";
    //     }
    //     cout << endl;
    // }


    cout << tr.maxPathSum() << endl;

    //? TESTING: tree invertion
    // auto vv = tr.levelOrderTraversal();
    // for(int i = 0; i < vv.size(); i++) {
    //     for(int j = 0; j < vv[i].size(); j++) {
    //         cout << vv[i][j]->value << " ";
    //     }
    //     cout << endl;
    // }

    // tr.invert(tr.find_Node(10));
    // cout << "_________________________________" << endl;

    // auto vv1 = tr.levelOrderTraversal();
    // for(int i = 0; i < vv1.size(); i++) {
    //     for(int j = 0; j < vv1[i].size(); j++) {
    //         cout << vv1[i][j]->value << " ";
    //     }
    //     cout << endl;
    // }

    // cout << tr.diameter() << endl;
    
    return 0;
}
