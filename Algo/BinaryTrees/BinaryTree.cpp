#include <iostream>
#include <climits>
#include <utility>
using namespace std;

class Node
{
public:
    int data;
    Node *leftChild;
    Node *rightChild;

    Node(int data)
        : data(data), leftChild(NULL), rightChild(NULL) {}
};

class BTree
{
private:
    Node *root;

    Node *insert(Node *node, int data)
    {
        if (node == NULL)
            return new Node(data);

        if (data <= node->data)
            node->leftChild = insert(node->leftChild, data);
        else
            node->rightChild = insert(node->rightChild, data);

        return node;
    }

    bool search(Node *node, int val)
    {
        if (node == NULL)
            return false;
        if (node->data == val)
            return true;

        if (val < node->data)
            return search(node->leftChild, val);
        else
            return search(node->rightChild, val);
    }

    void destroy_recursive(Node *node)
    {
        if (node == NULL)
            return;

        destroy_recursive(node->leftChild);
        destroy_recursive(node->rightChild);
        delete node;
    }

    

public:
    BTree() : root(NULL) {}

    void insert_recursive(int data)
    {
        root = insert(root, data);
    }

    void insert_iterative(int data)
    {
        if (root == NULL)
        {
            root = new Node(data);
            return;
        }
        Node *curr = root;
        Node *parent = NULL;
        while (curr != NULL)
        {
            parent = curr;
            if (data <= curr->data)
                curr = curr->leftChild;
            else
                curr = curr->rightChild;
        }
        if (data <= parent->data)
            parent->leftChild = new Node(data);
        else
            parent->rightChild = new Node(data);
    }

    bool search_recursive(int val)
    {
        return search(root, val);
    }

    bool search_iterative(int val)
    {
        if (root == NULL)
            return false;
        Node *curr = root;
        while (curr != NULL)
        {
            if (curr->data == val)
                return true;
            if (val < curr->data)
                curr = curr->leftChild;
            else
                curr = curr->rightChild;
        }
        return false;
    }

    int find_min()
    {
        if (root == NULL)
            return INT_MIN;
        Node *curr = root;
        while (curr->leftChild != NULL)
            curr = curr->leftChild;
        return curr->data;
    }

    int find_max()
    {
        if (root == NULL)
            return INT_MIN;
        Node *curr = root;
        while (curr->rightChild != NULL)
            curr = curr->rightChild;
        return curr->data;
    }

    ~BTree()
    {
        destroy_recursive(root);
        root = NULL;
    }
};

int main()
{
    BTree b;
    b.insert_recursive(10);
    b.insert_recursive(5);
    b.insert_recursive(15);
    b.insert_recursive(3);
    b.insert_recursive(7);
    b.search_recursive(10);
    return 0;
}
