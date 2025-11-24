#pragma once
#include <iostream>
using namespace std;

class Course{
    public:
    string title;
    string code;
    Course() = default;
    Course(const string& t, const string& c) {
        title = t; code = c;
    }
    void showCourse() {
        cout << "Course: " << title << ", Code: " << code << " ";
    }
};