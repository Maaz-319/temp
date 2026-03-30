#include <iostream>

using namespace std;

int sum(int arr[], int n)
{
    if (n == 1)
        return arr[0];
    return sum(arr, n - 1) + arr[n - 1];
}
int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    cout << sum(arr, 5);
    return 0;
}