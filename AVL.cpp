#include "AVL.h"
#include <algorithm>
#include <iostream>

using namespace std;

AVLTree::AVLTree() : root(nullptr) {}

int AVLTree::height(Node* node) {
    return node ? node->height : 0;
}

int AVLTree::getBalance(Node* node) {
    return node ? height(node->left) - height(node->right) : 0;
}

Node* AVLTree::rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

Node* AVLTree::leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

Node* AVLTree::insert(Node* node, User* user) {
    if (!node)
        return new Node(user);

    if (user->id < node->user->id)
        node->left = insert(node->left, user);
    else if (user->id > node->user->id)
        node->right = insert(node->right, user);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && user->id < node->left->user->id)
        return rightRotate(node);

    if (balance < -1 && user->id > node->right->user->id)
        return leftRotate(node);

    if (balance > 1 && user->id > node->left->user->id) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && user->id < node->right->user->id) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

User* AVLTree::search(Node* node, int id) {
    if (!node)
        return nullptr;

    if (node->user->id == id)
        return node->user;

    if (id < node->user->id)
        return search(node->left, id);

    return search(node->right, id);
}

Node* AVLTree::minValueNode(Node* node) {
    Node* current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}

Node* AVLTree::remove(Node* root, int id) {
    if (!root)
        return root;

    if (id < root->user->id)
        root->left = remove(root->left, id);
    else if (id > root->user->id)
        root->right = remove(root->right, id);
    else {
        if ((root->left == nullptr) || (root->right == nullptr)) {
            Node* temp = root->left ? root->left : root->right;
            if (!temp) {
                temp = root;
                root = nullptr;
            } else
                *root = *temp;
            delete temp;
        } else {
            Node* temp = minValueNode(root->right);
            root->user = temp->user;
            root->right = remove(root->right, temp->user->id);
        }
    }

    if (!root)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void AVLTree::inOrderTraversal(Node* root) {
    if (!root)
        return;

    inOrderTraversal(root->left);
    cout << "ID: " << root->user->id << ", Nombre: " << root->user->name
              << ", Email: " << root->user->email
              << ", Fecha de creacion: " << root->user->creationDate << endl;
    inOrderTraversal(root->right);
}

void AVLTree::preOrderTraversal(Node* root) {
    if (!root)
        return;

    cout << "ID: " << root->user->id << ", Nombre: " << root->user->name
              << ", Email: " << root->user->email
              << ", Fecha de creacion: " << root->user->creationDate << endl;
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void AVLTree::postOrderTraversal(Node* root) {
    if (!root)
        return;

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << "ID: " << root->user->id << ", Nombre: " << root->user->name
              << ", Email: " << root->user->email
              << ", Fecha de creacion: " << root->user->creationDate << endl;
}

void AVLTree::printTree(Node* root, string indent, bool last) {
    if (root != nullptr) {
        cout << indent;
        if (last) {
            cout << "R----";
            indent += "   ";
        } else {
            cout << "L----";
            indent += "|  ";
        }
        cout << root->user->id << " (" << root->user->name << ")" << endl;
        printTree(root->left, indent, false);
        printTree(root->right, indent, true);
    }
}