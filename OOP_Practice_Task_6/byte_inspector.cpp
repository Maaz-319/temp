#include <iostream>

using namespace std;

void inspectBytes(void *data, size_t size)
{
    char *ptr = (char *)data;
    for (size_t i = 0; i < size; i++)
        cout << std::hex << (int)(unsigned char)ptr[i] << " ";
}

int main()
{
    int x = 305419896;
    inspectBytes(&x, sizeof(x));
}