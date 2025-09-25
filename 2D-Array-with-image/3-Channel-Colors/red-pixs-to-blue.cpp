#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream file("img.ppm");

    int h, w, maxVal;

    // ignoring the first 2 lines
    for (int i = 0; i <= 1; i++)
    {
        string a;
        getline(file, a);
    }

    // reading width, height, maximum value
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
            r = r_s[i][j];
            g = g_s[i][j];
            b = b_s[i][j];

            if (r == 255 && g == 0 && b == 0)
            {
                outputFile << "0 0 255 ";
            }
            else
            {
                outputFile << r << " " << g << " " << b << " ";
            }
        }
        outputFile << "\n";
    }
    outputFile.close();

    return 0;
}
