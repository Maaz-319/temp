#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

const int N = 4096;

int main()
{
    vector<int> matrix(N * N, 1);

    volatile long long sum = 0;

    auto start1 = high_resolution_clock::now();
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            sum += matrix[i * N + j];
    auto end1 = high_resolution_clock::now();

    auto start2 = high_resolution_clock::now();
    for (int j = 0; j < N; j++)
        for (int i = 0; i < N; i++)
            sum += matrix[i * N + j];
    auto end2 = high_resolution_clock::now();

    auto rowTime = duration_cast<milliseconds>(end1 - start1);
    auto colTime = duration_cast<milliseconds>(end2 - start2);

    cout << "Row-major time: " << rowTime.count() << " ms\n";
    cout << "Column-major time: " << colTime.count() << " ms\n";
    return 0;
}