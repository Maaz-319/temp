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

    cout << "Enter no. of Students: ";
    cin >> n;

    Student *students = new Student[n];

    for (int i = 0; i < n; i++)
    {
        students[i].id = i;
        cout << "GPA For Student ID - " << i << " : ";
        cin >> students[i].gpa;
    }

    ofstream file("students.mz", ios::binary);
    file << n;
    file.write((char *)students, sizeof(students) * n);
    file.close();

    return 0;
}