#ifndef USERAVL_H
#define USERAVL_H

using namespace std;

#include <string>

struct User {
    int id;
    string name;
    string email;
    string creationDate;
};

struct Node {
    User* user;
    Node* left;
    Node* right;
    int height;
    Node(User* user) : user(user), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
public:
    Node* root;

    AVLTree();

    int height(Node* node);
    int getBalance(Node* node);

    Node* rightRotate(Node* y);
    Node* leftRotate(Node* x);
    Node* insert(Node* node, User* user);
    User* search(Node* node, int id);
    Node* remove(Node* root, int id);
    Node* minValueNode(Node* node);

    void inOrderTraversal(Node* node);
    void preOrderTraversal(Node* node);
    void postOrderTraversal(Node* node);
    void printTree(Node* root, string indent = "", bool last = true);
};

#endif // USERAVL_H