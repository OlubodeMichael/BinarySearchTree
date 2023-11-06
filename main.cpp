#include <iostream>
#include "BinarySearchTree.hpp"
using namespace std;

using namespace std;

int main() {
    BinarySearchTree bst;

    srand(static_cast<unsigned>(time(nullptr)));
    // Create and insert 35 random natural numbers (less than 100) into the BST
    for (int i = 0; i < 35; ++i) {
        int value = rand() % 100; // Generate a random number less than 100
        bst.insert(value);
    }
    cout << "In-order traversal: ";
    bst.inOrderTraversal();

    cout << "Pre-order traversal: ";
    bst.preOrderTraversal();

    cout << "Post-order traversal: ";
    bst.postOrderTraversal();

    bst.remove(30);

    cout << "In-order traversal after removing 30: ";
    bst.inOrderTraversal();

    return 0;
}
