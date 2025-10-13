#include <iostream>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        std::cout << "\n[Invalid Number of Arguments]\n[SYNTAX]: concate_two_str str1 str2\n\te.g: concate_two_str hello world";
        return 1;
    }
    std::string s1 = argv[1];
    std::string s2 = argv[2];
    std::cout << "Concatenated: " << s1 + s2 << std::endl;

    return 0;
}