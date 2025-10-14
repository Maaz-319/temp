#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

class Complex
{
    int real;
    int imaginary;

    void set_real(int r) { real = r; }
    void set_imaginary(int i) { imaginary = i; }

    int get_real() { return real; }
    int get_imaginary() { return imaginary; }

public:
    Complex()
    {
        set_real(rand() % 500);
        set_imaginary(rand() % 500);
    }

    Complex(int r, int i)
    {
        set_real(r);
        set_imaginary(i);
    }

    void show()
    {
        int r = get_real();
        int i = get_imaginary();
        
        cout << "\n" << (r ? to_string(r) : "");
        cout << ((i!=0) ? ((i < 0) ? " - " : " + "): "");
        cout << (i ? to_string(abs(i)) + "i" : "");
    }
};

int main() {
    Complex c1(3, 4);
    c1.show();
    Complex c2(0, -5);
    c2.show();
    Complex c3(7, 0);
    c3.show();
}