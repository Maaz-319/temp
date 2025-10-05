#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    string to_store = "Pakistan\0";
    char *str = new char[to_store.size() + 1];

    for (int i = 0; i < to_store.size(); i++)
    {
        str[i] = to_store[i];
    }
    str[to_store.size()] = '\0';

    // ~~~~~~~~~~~~ Writing to a Binary File ~~~~~~~~~~~
    ofstream file("binary_file.mz", ios::binary);
    file.write(str, to_store.size());
    file.close();
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    // ~~~~~~~~~~~~ Reading to a Binary File ~~~~~~~~~~~
    char *read_str = new char[to_store.size() + 1];
    ifstream read_file("binary_file.mz", ios::binary);
    read_file.read(read_str, to_store.size());
    read_file.close();
    // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

    read_str[to_store.size()] = '\0';
    cout << read_str;

    delete[] str;
    delete[] read_str;

    return 0;
}