#include "Matrix.h"

int main()
{
    Matrix a(2, 2), c(0, 0);
    a(0, 0) = 1; a(0, 1) = 2;
    a(1, 0) = 3; a(1, 1) = 4;

    Matrix b(2, 2);
    b(0, 0) = 5; b(0, 1) = 6;
    b(1, 0) = 7; b(1, 1) = 8;

    std::cout << a << "\n";
    std::cout << b << "\n";

    c = a + b;
    std::cout << c << "\n";
    c = a - b;
    std::cout << c << "\n";
    c = a * b;
    std::cout << c << "\n";

    a = a * 2;
    std::cout << a << "\n";
    a *= 3;
    std::cout << a << "\n";

    std::cout << a(0, 0) << "\n";
    std::cout << a(9, 9) << "\n";

    return 0;
}