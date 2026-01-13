#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

class Dice
{
    int sides;
    int value;

public:
    void initialize_sides(int size = 6)
    {
        sides = size;
        value = 1 + rand() % sides;
    }
    void roll()
    {
        value = 1 + rand() % sides;
        cout << "\nRolled\n";
    }

    int get_sides() { return sides; }
    int get_value() { return value; }
};

int main()
{
    srand(time(NULL));
    Dice d1, d2, d3;
    d1.initialize_sides();
    d2.initialize_sides();
    d3.initialize_sides();

    cout << d1.get_value() << endl;
    cout << d2.get_value() << endl;
    cout << d3.get_value() << endl;
    d2.roll();
    cout << d1.get_value() << endl;
    cout << d2.get_value() << endl;
    cout << d3.get_value() << endl;
    return 0;
}