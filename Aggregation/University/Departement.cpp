#include "Course.cpp"

class Departement{
    string name;
    int count;
    Course *courses;
public:
Departement(){
    count = 0;
    courses = nullptr;
}
Departement(const string& n){
    name = n;
    count = 0;
    courses = new Course[10];
}
    void addCourse(const Course& c) {
        if (count < 10) {
            courses[count++] = c;
        }
    }

    void showDepartement(){
        cout << "Departement: " << name << " ";
        for (int i=0; i<count; i++) courses[i].showCourse();
    }
    ~Departement() {
        if (courses)
            delete[] courses;
    }
};