#pragma once
#include <iostream>
using namespace std;
class Book{
    public:
    string title;
    string author;
    Book() = default;
    Book(const string& t, const string& a) {
        title = t;
        author = a;
    }
};