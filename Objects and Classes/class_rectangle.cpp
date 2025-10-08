#include <iostream>
using namespace std;

class Rectangle
{
    float length;
    float width;

public:
    Rectangle() {}

    void set_width(float w) { width = w; }
    void set_length(float l) { length = l; }

    float get_length() { return length; }
    float get_width() { return width; }
    float get_area() { return width * length; }
    float get_perimeter() { return 2 * (width + length); }
};

int main()
{
    Rectangle rec;
    rec.set_length(100);
    rec.set_width(100);

    cout << "Length: " << rec.get_length();
    cout << "\nWidth: " << rec.get_width();
    cout << "\nArea: " << rec.get_area();
    cout << "\nPerimeter: " << rec.get_perimeter();

    return 0;
}