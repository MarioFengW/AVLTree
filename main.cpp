#include <iostream>
#include "AVL.h"

using namespace std;

int main() {
    AVLTree tree;
    User user1 = {1, "Clairo", "clairo@example.com", "2023-01-01"};
    User user2 = {2, "Cuco", "cuco@example.com", "2023-01-02"};
    User user3 = {3, "Johnson", "johnson@example.com", "2023-01-03"};
    User user4 = {4, "David", "david@example.com", "2023-01-04"};
    User user5 = {5, "Eve", "eve@example.com", "2023-01-05"};
    User user6 = {6, "Frank", "frank@example.com", "2023-01-06"};
    User user7 = {7, "Grace", "grace@example.com", "2023-01-07"};

    tree.root = tree.insert(tree.root, &user1);
    tree.root = tree.insert(tree.root, &user2);
    tree.root = tree.insert(tree.root, &user3);
    tree.root = tree.insert(tree.root, &user4);
    tree.root = tree.insert(tree.root, &user5);
    tree.root = tree.insert(tree.root, &user6);
    tree.root = tree.insert(tree.root, &user7);

    cout << "\nIn-order Traversal:" << endl;
    tree.inOrderTraversal(tree.root);

    cout << "\nPre-order Traversal:" << endl;
    tree.preOrderTraversal(tree.root);

    cout << "\nPost-order Traversal:" << endl;
    tree.postOrderTraversal(tree.root);

    cout << "\nTree Structure:" << endl;
    tree.printTree(tree.root);

    return 0;
}