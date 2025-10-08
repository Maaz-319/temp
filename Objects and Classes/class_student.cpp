#include <iostream>

using namespace std;

class Student
{
    string name;
    string roll_no;
    int *grades = new int[6];

public:
    void set_name(string n) { name = n; }
    void set_roll_no(string rn) { roll_no = rn; }
    void set_grades(int gd[6])
    {
        for (int i = 0; i < 6; i++)
            *(grades + i) = gd[i];
    }

    string get_name() { return name; }
    string get_roll_no() { return roll_no; }
    int *get_grades() { return grades; }

    ~Student() { delete[] grades; }
};

int main()
{
    Student std;
    std.set_name("Ali");
    std.set_roll_no("roll_no_0");
    int gd[6] = {90, 80, 50, 60, 80, 99};
    std.set_grades(gd);

    cout << "NAME: " << std.get_name();
    cout << "\nROLL NO: " << std.get_roll_no();
    int *get_gd;
    get_gd = std.get_grades();
    cout << "\nGRADES: ";
    for (int i = 0; i < 6; i++)
    {
        cout << *(get_gd + i) << " ";
    }
    return 0;
}