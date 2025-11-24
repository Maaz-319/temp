#pragma once
#include <iostream>

using namespace std;

class Engine{
    public:
    int power;
    string type;
    Engine(int p, const string& t){
        power = p;
        type = t;
    }
};