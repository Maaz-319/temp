#include "Node.h"
#include <iostream>

template <typename dataType>
class doubly_list
{
    Node<dataType> *head;

public:
    doubly_list() { head = nullptr; }

    void insertAtHead(dataType value)
    {
        head = new Node<dataType>(value, head);
        if (head->next)
            head->next->prev = head;
    }

    void insertAtTail(dataType value)
    {
        if (!head)
        {
            head = new Node<dataType>(value);
            return;
        }
        Node<dataType> *temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = new Node<dataType>(value, nullptr, temp);
    }

    dataType deleteAtHead()
    {
        if (!head)
            throw "Empty List";

        dataType value = head->val;

        if (!head->next)
        {
            delete head;
            head = nullptr;
            return value;
        }

        head = head->next;
        delete head->prev;
        head->prev = nullptr;

        return value;
    }

    dataType deleteAtTail()
    {
        if (!head)
            throw "Empty List";

        Node<dataType> *temp = head;

        while (temp->next)
            temp = temp->next;

        dataType value = temp->val;

        if (temp->prev)
            temp->prev->next = nullptr;
        else
            head = nullptr;

        delete temp;

        return value;
    }

    void insertAt(dataType value, int pos)
    {
        if (pos < 0)
            throw "Invalid pos";
        if (pos == 0)
        {
            insertAtHead(value);
            return;
        }

        Node<dataType> *temp = head;
        int i;
        for (i = 0; i < pos - 1 && temp->next; i++)
            temp = temp->next;

        if (i != pos - 1)
            throw "Out of Range";

        Node<dataType> *newNode = new Node<dataType>(value, temp->next, temp);

        if (temp->next)
            temp->next->prev = newNode;

        temp->next = newNode;
    }

    void print()
    {
        Node<dataType> *temp = head;
        while (temp)
        {
            std::cout << temp->val << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL";
    }

    ~doubly_list()
    {
        while (head)
            deleteAtHead();
    }
};

int main()
{
    doubly_list<int> dl;
    dl.insertAtHead(1);
    dl.insertAtHead(2);
    dl.insertAtHead(3);
    dl.insertAtHead(4);
    dl.insertAtHead(5);

    dl.insertAtTail(1);
    dl.insertAtTail(2);
    dl.insertAtTail(3);
    dl.insertAtTail(4);
    dl.insertAtTail(5);

    dl.print();
    return 0;
}