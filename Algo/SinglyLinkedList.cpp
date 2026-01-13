#include <iostream>
#include <utility>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int v, Node *ptr = nullptr)
    {
        val = v;
        next = ptr;
    }
};

class LinkedList
{
    Node *head;

public:
    LinkedList()
    {
        head = nullptr;
    }

    LinkedList &addTail(int val)
    {
        Node *temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = new Node(val);
        temp = temp->next;
        return *this;
    }

    LinkedList &addHead(int val)
    {
        head = new Node(val, head);
        return *this;
    }

    void print()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
    }

    void bubble_sort()
    {
        if (!head) return;

        bool swapped;
        do
        {
            swapped = false;
            for (Node *i = head; i && i->next; i = i->next)
            {
                for (Node *j = i->next; j; j = j->next)
                {
                    if (i->val > j->val)
                    {
                        swap(i->val, j->val);
                        swapped = true;
                    }
                }
            }
        } while (swapped);
    }

    ~LinkedList()
    {
        while (head)
        {
            Node *temp = head->next;
            delete head;
            head = temp;
        }
    }
};

int main()
{
    LinkedList list;
    list.addHead(3).addHead(8).addHead(7).addHead(2).addHead(9).addHead(5).addHead(4).addHead(6).addHead(10).addHead(1);
    list.print();
    list.bubble_sort();
    cout << endl;
    list.print();
}