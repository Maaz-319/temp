#include "Node.h"
#include <iostream>
using namespace std;

Node *Xor(Node *a, Node *b)
{
    return (Node *)((uintptr_t)(a) ^ (uintptr_t)(b));
}

class xor_list
{
    Node *head;

public:
    xor_list() { head = nullptr; }

    void insertAtHead(int val)
    {
        Node *newNode = new Node(val);

        if (!head)
        {
            head = newNode;
            return;
        }

        newNode->npx = Xor(nullptr, head);
        head->npx = Xor(newNode, Xor(nullptr, head->npx));
        head = newNode;
    }

    void insertAtTail(int val)
    {
        Node *newNode = new Node(val);

        if (!head)
        {
            head = newNode;
            return;
        }

        Node *temp = head;
        Node *par = nullptr;
        while (temp)
        {
            Node *next = Xor(par, temp->npx);
            par = temp;
            temp = next;
        }
        newNode->npx = Xor(par, nullptr);
        par->npx = Xor(newNode, Xor(par->npx, nullptr));
    }

    int removeAtHead()
    {
        if (!head)
            throw "Empty List";

        int val = head->data;

        Node *temp = head;
        Node *next = Xor(nullptr, head->npx);
        if (next)
            next->npx = Xor(nullptr, Xor(temp, next->npx));
        head = next;
        delete temp;

        return val;
    }

    int removeAtTail()
    {
        if (!head)
            throw "Empty List";

        Node *prev = nullptr;
        Node *curr = head;

        while (true)
        {
            Node *next = Xor(prev, curr->npx);

            if (!next)
                break;

            prev = curr;
            curr = next;
        }

        int val = curr->data;

        if (!prev)
        {
            head = nullptr;
            delete curr;
            return val;
        }

        prev->npx = Xor(Xor(curr, prev->npx), nullptr);

        delete curr;

        return val;
    }

    bool search(int key)
    {
        if (!head)
            return false;

        Node *par = nullptr;
        Node *temp = head;

        while (temp)
        {
            if (temp->data == key)
                return true;

            Node *next = Xor(par, temp->npx);
            par = temp;
            temp = next;
        }
        return false;
    }

    void print()
    {
        if (!head)
            return;
        Node *par = nullptr;
        Node *temp = head;
        while (temp)
        {
            Node *next = Xor(par, temp->npx);
            cout << temp->data << " -> ";
            par = temp;
            temp = next;
        }
        cout << "NULL";
    }

    ~xor_list()
    {
        if (!head)
            return;
        Node *par = nullptr;
        while (head)
        {
            Node *next = Xor(par, head->npx);
            delete head;
            par = head;
            head = next;
        }
    }
};

int main()
{
    xor_list ll;

    ll.insertAtHead(10);
    ll.insertAtHead(20);
    ll.insertAtHead(30);
    ll.insertAtHead(40);
    ll.insertAtHead(50);
    ll.insertAtTail(10);
    ll.insertAtTail(20);
    ll.insertAtTail(30);
    ll.insertAtTail(40);
    ll.insertAtTail(50);

    ll.print();

    ll.removeAtHead();
    ll.removeAtTail();

    cout << "\n";

    ll.print();
    cout << "\n";

    cout << ll.search(10) << "\n";
    cout << ll.search(50);
    return 0;
}