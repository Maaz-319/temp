#include <iostream>
#include <fstream>
#include <algorithm>
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

    // reading the pixel values in matrix
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            file >> mat[i][j];
        }
    }
    file.close();

    ofstream outputFile("output.pgm");
    outputFile << "P2\n"
               << "# Created by IrfanView\n"; // writing the same 2 lines

    outputFile << (w * 2) << " " << (h * 2) << "\n";
    outputFile << maxVal << "\n";

    // writing back the pixel values
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            outputFile << mat[i][j] << " ";
        }
        for (int j = w - 1; j >= 0; j--)
        {
            outputFile << mat[i][j] << " ";
        }
        // outputFile << "\n";
        outputFile << "\n";
    }
    for (int i = h; i >= 0; i--)
    {
        for (int j = 0; j < w; j++)
        {
            outputFile << mat[i][j] << " ";
        }
        for (int j = w - 1; j >= 0; j--)
        {
            outputFile << mat[i][j] << " ";
        }
        // outputFile << "\n";
        outputFile << "\n";
    }
    outputFile.close();

    return 0;
}