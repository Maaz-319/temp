#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

int main()
{
    srand(time(NULL));
    ofstream file("colorful_diagnols.ppm");

    file << "P3\n200 200\n255\n";
    int diagnols = 200 + 200 - 1;
    int R[diagnols], G[diagnols], B[diagnols];
    for (int d = 0; d < diagnols; ++d)
    {
        R[d] = rand() % 256;
        G[d] = rand() % 256;
        B[d] = rand() % 256;
    }

    for (int i = 0; i < 200; i++)
    {
        for (int j = 0; j < 200; j++)
        {
            int idx = j - i + (199);
            file << R[idx] << " " << G[idx] << " " << B[idx] << " ";
        }
    }
    file.close();
}