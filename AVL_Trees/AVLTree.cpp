#include "Node.h"
#include <iostream>
using namespace std;

class AVLTree
{
    int height(Node *node) { return node ? node->h : 0; }
    int balance(Node *node) { return node ? height(node->left) - height(node->right) : 0; }
    void updateHeight(Node *node) { node->h = 1 + max(height(node->left), height(node->right)); }

    Node *rotate_right(Node *x)
    {
        Node *y = x->left;
        Node *temp = y->right;

        y->right = x;
        x->left = temp;

        updateHeight(x);
        updateHeight(y);

        return y;
    }

    Node *rotate_left(Node *x)
    {
        Node *y = x->right;
        Node *temp = y->left;

        y->left = x;
        x->right = temp;

        updateHeight(x);
        updateHeight(y);

        return y;
    }

public:
    Node *root;

    AVLTree() { root = nullptr; }
};