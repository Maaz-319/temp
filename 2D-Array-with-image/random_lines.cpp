#include <iostream>
#include <fstream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    ifstream file("img.pgm");

    int h = 4, w = 4, maxVal;

    // ignoring the first 2 lines
    for (int i = 0; i <= 1; i++)
    {
        string a;
        getline(file, a);
    }

    // reading width, height, maximum value
    file >> w >> h >> maxVal;

    // this matrix can be left empty, initializing like this is not necessary
    int mat[h][w] = {};

    srand(time(0));

    int numHLines = 1 + rand() % 3;
    int numVLines = 1 + rand() % 3;

    // reading the pixel values in matrix
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            file >> mat[i][j];
        }
    }
    file.close();

    for (int k = 0; k < numHLines; k++)
    {
        int row = rand() % h;
        for (int j = 0; j < w; j++)
        {
            mat[row][j] = maxVal; // white
        }
    }

    for (int k = 0; k < numVLines; k++)
    {
        int col = rand() % w;
        for (int i = 0; i < h; i++)
        {
            mat[i][col] = maxVal; // white
        }
    }

    ofstream outputFile("output.pgm");
    outputFile << "P2\n"
               << "# Created by IrfanView\n"; // writing the same 2 lines

    outputFile << w << " " << h << "\n";
    outputFile << maxVal << "\n";

    // writing back the pixel values
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
            outputFile << mat[i][j] << " ";
        outputFile << "\n";
    }
    outputFile.close();

    return 0;
}