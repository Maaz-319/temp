#include <iostream>
#include <string>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        std::cout << "\n[Invalid Number of Arguments]\n[SYNTAX]: print_file_extension filename.ext ....\n\te.g: print_file_extension data.txt";
        return 1;
    }

    std::string s = argv[1];
    if (s.find_last_of('.') == std::string::npos) std::cout << "\nNo Extension\n";
    std::cout << "\nExtension: " << s.substr(s.find_last_of('.') + 1) << "\n";
}