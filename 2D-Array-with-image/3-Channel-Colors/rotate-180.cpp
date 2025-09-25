#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
    ifstream file("img.ppm");
    if (!file) {
        cerr << "Error: could not open img.pgm\n";
        return 1;
    }

    // skip first two lines
    string tmp;
    getline(file, tmp);
    getline(file, tmp);

    int w, h, maxVal;
    file >> w >> h >> maxVal;

    unsigned char r_s[h][w];
    unsigned char g_s[h][w];
    unsigned char b_s[h][w];

    int r, g, b;

    // reading the pixel values in matrix
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            file >> r >> g >> b;
            r_s[i][j] = r;
            g_s[i][j] = g;
            b_s[i][j] = b;
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
            r = r_s[h - i - 1][w - j - 1];
            g = g_s[h - i - 1][w - j - 1];
            b = b_s[h - i - 1][w - j - 1];

            outputFile << r << " " << g << " " << b << " ";
        }
    }
    outputFile.close();

    return 0;
}
