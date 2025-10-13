#include <iostream>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "\n[Invalid Number of Arguments]\n[SYNTAX]: even_odd num ....\n\te.g: even_odd 5";
        return 1;
    }

    int n = atoi(argv[1]);
    std::cout << ((n & 1) ? "\nOdd\n" : "\nEven\n");
    return 0;
}