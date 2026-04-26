template <typename dataType>
class Node
{
public:
    dataType val;
    Node *next;
    Node *prev;

    Node(dataType value, Node *nxt = nullptr, Node *prv = nullptr) : val(value), next(nxt), prev(prv) {}
};