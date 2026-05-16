#include "Node.h"
#include <iostream>
using namespace std;

class AVLTree
{
    Node *root;

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

    Node *insert(Node *root, int val)
    {
        if (!root)
            return new Node(val);

        if (val < root->val)
            root->left = insert(root->left, val);
        else if (val > root->val)
            root->right = insert(root->right, val);
        else
            return root;

        updateHeight(root);

        int balanceFactor = balance(root);

        if (balanceFactor > 1 && val < root->left->val)
            return rotate_right(root);

        if (balanceFactor < -1 && val > root->right->val)
            return rotate_left(root);

        if (balanceFactor > 1 && val > root->left->val)
        {
            root->left = rotate_left(root->left);
            return rotate_right(root);
        }

        if (balanceFactor < -1 && val < root->right->val)
        {
            root->right = rotate_right(root->right);
            return rotate_left(root);
        }

        return root;
    }

    void destroy(Node *root)
    {
        if (!root)
            return;

        destroy(root->left);
        destroy(root->right);

        delete root;
    }

    void preorder(Node *root)
    {
        if (!root)
            return;
        cout << root->val << " ";
        preorder(root->left);
        preorder(root->right);
    }

public:
    AVLTree() { root = nullptr; }
    void insert(int val) { root = insert(root, val); }
    ~AVLTree() { destroy(root); }

    void preorder()
    {
        preorder(root);
        cout << endl;
    }
};

int main()
{
    AVLTree tree;

    tree.insert(10);
    tree.preorder();

    tree.insert(20);
    tree.preorder();

    tree.insert(30);
    tree.preorder();

    tree.insert(40);
    tree.preorder();

    tree.insert(50);
    tree.preorder();

    tree.insert(60);
    tree.preorder();

    return 0;
}