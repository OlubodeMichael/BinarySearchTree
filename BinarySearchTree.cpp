#include "BinarySearchTree.hpp"
#include <iostream>
using namespace std;

Node* BinarySearchTree::createNode(int value) {
    return new Node(value);
}

Node* BinarySearchTree::insertNode(Node* node, int value) {
    if (node == nullptr) {
        return createNode(value);
    }
    
    if (value < node->data) {
        node->left = insertNode(node->left, value);
    } else if (value > node->data) {
        node->right = insertNode(node->right, value);
    }
    
    return node;
}

Node* BinarySearchTree::findMin(Node* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

Node* BinarySearchTree::removeNode(Node* node, int value) {
    if (node == nullptr) {
        return node;
    }
    
    if (value < node->data) {
        node->left = removeNode(node->left, value);
    } else if (value > node->data) {
        node->right = removeNode(node->right, value);
    } else {
        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        } else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        Node* temp = findMin(node->right);
        node->data = temp->data;
        node->right = removeNode(node->right, temp->data);
    }
    
    return node;
}

void BinarySearchTree::inOrderTraversal(Node* node) {
    if (node != nullptr) {
        inOrderTraversal(node->left);
        std::cout << node->data << " ";
        inOrderTraversal(node->right);
    }
}

void BinarySearchTree::preOrderTraversal(Node* node) {
    if (node != nullptr) {
        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        std::cout << node->data << " ";
    }
}

void BinarySearchTree::postOrderTraversal(Node* node) {
    if (node != nullptr) {
        postOrderTraversal(node->left);
        postOrderTraversal(node->right);
        std::cout << node->data << " ";
    }
}

void BinarySearchTree::clearTree(Node* node) {
    if (node == nullptr) {
        return; // Base case: If the node is null, nothing to clear
    }
    clearTree(node->left); // Recursively clear the left subtree
    clearTree(node->right); // Recursively clear the right subtree
    
    delete node; // Delete the current node
}

