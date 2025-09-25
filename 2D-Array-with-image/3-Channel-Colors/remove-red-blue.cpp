#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
    ifstream file("img.ppm");

    int h = 4, w = 4, maxVal;

    // ignoring the first 2 lines
    for (int i = 0; i <= 1; i++)
    {
        string a;
        getline(file, a);
    }

    // reading width, height, maximum value
    file >> w >> h >> maxVal;

    unsigned char g_s[h][w];
    int r, g, b;

    // reading the pixel values in matrix
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            file >> r >> g >> b;
            g_s[i][j] = g;
        }
    }
    file.close();

    ofstream outputFile("output.ppm");
    outputFile << "P3\n"
               << "# Created by IrfanView\n"; // writing the same 2 lines

    outputFile << w << " " << h << "\n";
    outputFile << maxVal << "\n";

    // writing back the pixel values
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            g = g_s[i][j];
            outputFile << "0 " << g << " 0 ";
        }
    }
    outputFile.close();

    return 0;
}