#include <iostream>
#include <fstream>
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
    file >> h >> w >> maxVal;

    // this matrix can be left empty, initializing like this is not necessary
    int mat[h][w] = {{1, 2, 3, 4},
                     {4, 5, 6, 7},
                     {1, 2, 3, 4},
                     {4, 5, 6, 7}};
    
    // reading the pixel values in matrix
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            file >> mat[i][j];
        }
    }
    file.close();

    
    if (h & w & 1)
    {
        cout << mat[h / 2][w / 2];
    }
    else if (h & 1)
    {
        cout << mat[h / 2][w / 2] << " " << mat[h / 2 - 1][w / 2];
    }
    else if (w & 1)
    {
        cout << mat[h / 2][w / 2] << " " << mat[h / 2][w / 2 - 1];
    }
    else
    {
        cout << mat[h / 2][w / 2] << " " << mat[h / 2 - 1][w / 2] << " " << mat[h / 2][w / 2 - 1] << " " << mat[h / 2 - 1][w / 2 - 1];
    }
    return 0;
}