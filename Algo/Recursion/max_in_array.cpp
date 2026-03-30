#include <iostream>

using namespace std;

int max(int arr[], int n)
{
    if (n == 1)
        return arr[0];
    int mx = max(arr, n - 1);
    return (mx > arr[n - 1]) ? mx : arr[n - 1];
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    cout << max(arr, 5);
    return 0;
}