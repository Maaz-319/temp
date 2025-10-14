#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

class Rational
{
    int numerator;
    int denomenator;

    int get_numerator() { return numerator; }
    int get_denominator() { return denomenator; }

    void normalize()
    {
        int d = denomenator;
        int n = numerator;

        int gcd_val = __gcd(n, d);

        n /= gcd_val;
        d /= gcd_val;

        if (d < 0)
        {
            n = -n;
            d = -d;
        }

        numerator = n;
        denomenator = d;
    }

public:
    Rational()
    {
        set_numerator(rand() % 500);
        set_denominator(1 + rand() % 500);
    }

    Rational(int n, int d)
    {
        set_numerator(n);
        set_denominator(d);
    }

    void set_numerator(int n)
    {
        numerator = n;
        normalize();
    }
    void set_denominator(int n)
    {
        if (n != 0) denomenator = n; else denomenator = 1;
        normalize();
    }

    void show()
    {
        cout << "\n"
             << get_numerator() << "/" << get_denominator() << "\n";
    }
};

int main()
{
    srand(time(NULL));
    Rational r1(4, 8);
    r1.show();
    r1.set_numerator(0);
    r1.show();
    r1.set_numerator(3);
    r1.set_denominator(-5);
    r1.show();
    return 0;
}