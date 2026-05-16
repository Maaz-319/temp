#pragma once

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    int h;
    Node(int v, Node *l = nullptr, Node *r = nullptr, int ht = 1) : val(v), left(l), right(r), h(ht) {}
};