#include "Departement.cpp"

class University{
    string name;
    Departement* departements;
    int count;
    public:
    
    University(const string& n) {
        name = n;
        count  = 0;
        departements = new Departement[10];
    }
    void addDeparetement(const Departement& d){
        if (count < 10) {
            departements[count++] = d;
        }
    }

    void showUniversity() {
        cout << "University: " << name << " ";
        for (int i=0; i<count; i++) departements[i].showDepartement();
    }

    ~University() {
        if (departements)
            delete[] departements;
    }
};

int main() {
    University uni("National University");
    Departement cs("Computer Science");
    cs.addCourse(Course("Data Structures", "CS201"));
    cs.addCourse(Course("Operating Systems", "CS301"));
    Departement ee("Electrical Engineering");
    ee.addCourse(Course("Circuits", "EE101"));
    ee.addCourse(Course("Electromagnets", "EE201"));
    uni.addDeparetement(cs);
    uni.addDeparetement(ee);
    uni.showUniversity();
    return 0;
}