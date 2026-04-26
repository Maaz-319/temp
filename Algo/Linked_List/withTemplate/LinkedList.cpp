#include "Node.cpp"
#include <iostream>

using namespace std;

template <typename T>
class LinkedList
{
    Node<T> *start;
    Node<T> *end;

public:
    LinkedList() : start(nullptr), end(nullptr) {}

    void push_back(T value)
    {
        Node<T> *temp = new Node<T>(value);
        if (!start)
        {
            start = end = temp;
        }
        else
        {
            end->next = temp;
            end = temp;
        }
    }

    void pop_back()
    {
        if (!start)
            return;

        if (start == end)
        {
            delete start;
            start = end = nullptr;
            return;
        }

        Node<T> *temp = start;
        while (temp->next != end)
        {
            temp = temp->next;
        }
        delete end;
        end = temp;
        end->next = nullptr;
    }

    void clear()
    {
        while (start)
        {
            Node<T> *temp = start;
            start = start->next;
            delete temp;
        }
        end = nullptr;
    }

    friend ostream &operator<<(ostream &os, const LinkedList &l)
    {
        Node<T> *temp = l.start;
        while (temp)
        {
            os << temp->data.first << " ";
            temp = temp->next;
        }
        return os;
    }

    ~LinkedList()
    {
        clear();
    }

    void bubble_sort(){
        
    }
};

int main()
{
    LinkedList<int> list;
    list.push_back(2);
    list.push_back(30);
    list.push_back(4);
    list.pop_back();
    list.push_back(5);
    list.push_back(6);

    cout << list;

    return 0;
}