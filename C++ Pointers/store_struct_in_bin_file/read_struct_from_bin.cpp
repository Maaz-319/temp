#include <iostream>
#include <fstream>

using namespace std;

struct Student
{
    int id;
    float gpa;
};

int main()
{
    int n;

    ifstream file("students.mz", ios::binary);
    file >> n;

    Student *students = new Student[n];

    file.read((char *)students, sizeof(students) * n);
    file.close();

    for (int i = 0; i < n; i++)
    {
        cout << "Student - " << students[i].id << ", GPA: " << students[i].gpa << "\n";
    }
    return 0;
}