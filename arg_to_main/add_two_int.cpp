#include <iostream>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        std::cout << "\n[Invalid Number of Arguments]\n[SYNTAX]: add_two_int num1 num2\n\te.g: add_two_int 2 3";
        return 1;
    }
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    std::cout << "Sum = " << a + b << std::endl;

    return 0;
}