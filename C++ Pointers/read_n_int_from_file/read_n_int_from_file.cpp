#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int n;

    ifstream file("numbers.txt");
    file >> n;

    int *arr = new int[n];
    int sum = 0;
    for (int i = 0; i < n; i++) {   file >> *(arr + i); cout << *(arr + i) << " "; sum += *(arr + i);  }
    file.close();

    cout << "\nSum = " << sum;

    delete[] arr;

    return 0;
}