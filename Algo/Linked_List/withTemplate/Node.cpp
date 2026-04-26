#include <utility>

using namespace std;

template <typename T>
class Node
{
private:
    static int count;

public:
    pair<T, int> data;
    Node *next;

    static int get_count() { return Node::count; }

    Node(T value, Node *next = nullptr)
    {
        this->data.first = value;
        this->data.second = count++;

        this->next = next;
    }
    ~Node()
    {
        this->count--;
    }
};
template <typename T>
int Node<T>::count = 0;