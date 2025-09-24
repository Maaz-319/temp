#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
    ifstream file("img.pgm");
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

    // read matrix
    vector<vector<int>> mat(h, vector<int>(w));
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            file >> mat[i][j];
    file.close();

    // rotated matrix
    vector<vector<int>> rotated(w, vector<int>(h));
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            rotated[j][h - 1 - i] = mat[i][j];

    ofstream outputFile("output.pgm");
    if (!outputFile) {
        cerr << "Error: could not create output.pgm\n";
        return 1;
    }

    outputFile << "P2\n";
    outputFile << "# Rotated 90 degrees clockwise\n";
    outputFile << h << " " << w << "\n";   // width first, then height
    outputFile << maxVal << "\n";

    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++)
            outputFile << rotated[i][j] << " ";
        outputFile << "\n";
    }

    outputFile.close();
    return 0;
}
