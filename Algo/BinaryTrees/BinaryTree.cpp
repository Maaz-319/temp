#include <iostream>
#include <climits>
#include <utility>
#include <queue>
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

    int height_recursive(Node *node)
    {
        if (node == NULL)
            return -1;
        return max(height_recursive(node->leftChild), height_recursive(node->rightChild)) + 1;
    }

    void preorder_recursive(Node *node)
    {
        if (node == NULL)
            return;
        cout << node->data << " ";
        preorder_recursive(node->leftChild);
        preorder_recursive(node->rightChild);
    }

    void inorder_recursive(Node *node)
    {
        if (node == NULL)
            return;
        inorder_recursive(node->leftChild);
        cout << node->data << " ";
        inorder_recursive(node->rightChild);
    }

    void postorder_recursive(Node *node)
    {
        if (node == NULL)
            return;
        postorder_recursive(node->leftChild);
        postorder_recursive(node->rightChild);
        cout << node->data << " ";
    }

    bool isSubTreeLesser(Node *node, int val)
    {
        if (node == NULL)
            return true;
        if (node->data <= val && isSubTreeLesser(node->leftChild, val) && isSubTreeLesser(node->rightChild, val))
            return true;
        else
            return false;
    }

    bool isSubTreeGreater(Node *node, int val)
    {
        if (node == NULL)
            return true;
        if (node->data > val && isSubTreeGreater(node->leftChild, val) && isSubTreeGreater(node->rightChild, val))
            return true;
        else
            return false;
    }

    bool is_BST_recursive(Node *root, int min_val, int max_val)
    {
        if (root == NULL)
            return true;

        if (root->data <= min_val || root->data >= max_val)
            return false;

        return is_BST_recursive(root->leftChild, min_val, root->data) &&
               is_BST_recursive(root->rightChild, root->data, max_val);
    }

    Node* find_min_util(Node* node)
    {
        if (node == NULL)
            return NULL;
        Node *curr = node;
        while (curr->leftChild != NULL)
            curr = curr->leftChild;
        return curr;
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
        Node* result = find_min_util(root);
        return (result == NULL) ? INT_MIN : result->data;
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

    int get_height()
    {
        return height_recursive(root);
    }

    void preorder_traversal()
    {
        preorder_recursive(root);
    }

    void inorder_traversal()
    {
        inorder_recursive(root);
    }

    void postorder_traversal()
    {
        postorder_recursive(root);
    }

    void levelorder_traversal()
    {
        if (root == NULL)
            return;
        queue<Node *> q;
        q.push(root);

        while (!q.empty())
        {
            Node *curr = q.front();
            q.pop();
            cout << curr->data << " ";
            if (curr->leftChild != NULL)
                q.push(curr->leftChild);
            if (curr->rightChild != NULL)
                q.push(curr->rightChild);
        }
    }

    Node *delete_node(Node *node, int val)
    {
        if (node == NULL)
            return NULL;
        if (val < node->data)
            node->leftChild = delete_node(node->leftChild, val);
        else if (val > node->data)
            node->rightChild = delete_node(node->rightChild, val);
        else
        {
            if (node->leftChild == NULL && node->rightChild == NULL)
            {
                delete node;
                node = NULL;
            }
            else if (node->leftChild == NULL)
            {
                Node *curr = node;
                node = node->rightChild;
                delete curr;
            }
            else if (node->rightChild == NULL)
            {
                Node *curr = node;
                node = node->leftChild;
                delete curr;
            }
            else
            {
                Node* temp = find_min_util(node->rightChild);
                node->data = temp->data;
                node->rightChild = delete_node(node->rightChild, temp->data);
            }
        }
        return node;
    }

    bool is_BST()
    {
        return is_BST_recursive(root, INT_MIN, INT_MAX);
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
