#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>

using namespace std;
using namespace std::chrono;

int main()
{
    const int SIZE = 10000000;
    vector<unsigned char> data(SIZE);
    mt19937 rng(0);
    uniform_int_distribution<int> dist(0, 255);

    for (int i = 0; i < SIZE; i++) data[i] = dist(rng);

    volatile int sum = 0;

    // -------- UNSORTED --------
    auto start1 = high_resolution_clock::now();

    for (int i = 0; i < SIZE; i++)
        if (data[i] >= 128)
            sum += data[i];

    auto end1 = high_resolution_clock::now();

    cout << "==================================================================";
    cout << "\nUnsorted time: " << duration_cast<milliseconds>(end1 - start1).count() << " ms\n";

    sort(data.begin(), data.end());

    auto start2 = high_resolution_clock::now();

    for (int i = 0; i < SIZE; i++)
        if (data[i] >= 128)
            sum += data[i];

    auto end2 = high_resolution_clock::now();

    cout << "Sorted time: " << duration_cast<milliseconds>(end2 - start2).count() << " ms\n";
    cout << "==================================================================\n";
    cout << "SUM: " << sum << endl;
}