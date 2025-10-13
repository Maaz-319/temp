#include <iostream>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << "\n[Invalid Number of Arguments]\n[SYNTAX]: multiply_n_nums num1 num2 ....\n\te.g: multiply_n_nums 2 3 5";
        return 1;
    }

    long long mul = 1;
    for (int i = 1; i < argc; i++) mul *= atoll(argv[i]);

    std::cout << "Product = " << mul << std::endl;


    return 0;
}