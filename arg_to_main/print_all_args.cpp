#include <iostream>

int main(int argc, char* argv[])
{
    for (int i = 1; i < argc; ++i)
    {
        std::cout << "Arg - " << i << ": " << argv[i] << '\n';
    }

    return 0;
}