#include <iostream>

using namespace std;

int main()
{
    int size = 5;
    int arr[size] = {10, 20, 30, 40, 50};
    int *integer_pointer = arr;

    for (int i = 0; i < size; i++, integer_pointer++)
    {
        *integer_pointer = i;
    }

    integer_pointer -= size;

    for (int i = 0; i < size; i++, integer_pointer++)
    {
        cout << *integer_pointer << " ";
    }

    return 0;
}