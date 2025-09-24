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

    int border = 5;
    int new_h = h + 2 * border;
    int new_w = w + 2 * border;

    int mat[new_h][new_w] = {};

    // reading the pixel values in matrix
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (i <= border || j <= border || i >= h - border || j >= w - border)
                mat[i][j] = 255;
            file >> mat[i + border][j + border];
        }
    }
    file.close();

    ofstream outputFile("output.pgm");
    outputFile << "P2\n"
               << "# Created by IrfanView\n"; // writing the same 2 lines

    outputFile << w << " " << h << "\n";
    outputFile << maxVal << "\n";

    // writing back the pixel values
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            outputFile << mat[i][j] << " ";
        }
        outputFile << "\n";
    }
    outputFile.close();

    return 0;
}