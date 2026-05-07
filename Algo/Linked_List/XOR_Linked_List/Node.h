#pragma once

class Node
{
public:
    int data;
    Node *npx;
    Node(int val, Node *next = nullptr) : data(val), npx(next) {}
};