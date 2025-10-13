#include <iostream>

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        std::cout << "\n[Invalid Number of Arguments]\n[SYNTAX]: calc num1 operator num2\n\te.g: calc 2 + 3";
        return 1;
    }
    float result;
    switch (*argv[2])
    {
        case '+': result = atof(argv[1]) + atof(argv[3]); break;
        case '-': result = atof(argv[1]) - atof(argv[3]); break;
        case '/':
            if (atof(argv[3]) == 0) { std::cout << "\nUNDEFINED\n"; return 1; }
            result = atof(argv[1]) / atof(argv[3]);
            break;
        case '*': result = atof(argv[1]) * atof(argv[3]); break;
        default: std::cout << "\nINVALID OPERATOR\n"; return 1;
    }

    std::cout << "\n" << result << "\n";

    return 0;
}