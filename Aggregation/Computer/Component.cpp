#pragma once

#include <iostream>
using namespace std;

class Component{
    string name;
    string capacity;
    public:
    Component() = default;
    Component(const string& n, const string& c) {
        name = n;
        capacity = c;
    }
    void showComponent(){
        cout << "Component: " << name << ", Capacity: " << capacity<< " ";
    }
};