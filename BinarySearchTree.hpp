#ifndef BinarySearchTree_hpp
#define BinarySearchTree_hpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
private:
    Node* root;
    
    Node* createNode(int value);
    Node* insertNode(Node* node, int value);
    Node* findMin(Node* node);
    Node* removeNode(Node* node, int value);
    void inOrderTraversal(Node* node);
    void preOrderTraversal(Node* node);
    void postOrderTraversal(Node* node);
    void clearTree(Node* node);
    
public:
    BinarySearchTree() : root(nullptr) {}
    ~BinarySearchTree() {
        clear();
    }
    
    void insert(int value) {
        root = insertNode(root, value);
    }
    
    void remove(int value) {
        root = removeNode(root, value);
    }
    
    void inOrderTraversal() {
        inOrderTraversal(root);
        cout << endl;
    }
    
    void preOrderTraversal() {
        preOrderTraversal(root);
        cout << endl;
    }
    
    void postOrderTraversal() {
        postOrderTraversal(root);
        cout << endl;
    }
    
    void clear() {
        clearTree(root);
        root = nullptr;
    }
    
    
};
#endif /* BinarySearchTree_hpp */
