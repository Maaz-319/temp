#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
    int h = 100, w = 100, col = 0;
    
    ofstream file("output.ppm");
    file << "P3\n" << "# nothing....\n";
    file << w << " " << h << "\n" << 255 << endl;

    string colors[16] = {
        "255, 0, 0 ", "0, 255, 0 ", "0, 0, 255 ", "255, 255, 0 ", "255, 0, 255 ", "0, 255, 255 ", "128, 0, 0 ", "0, 128, 0 ", "0, 0, 128 ", "128, 128, 0 ", "128, 0, 128 ", "0, 128, 128 ", "192, 192, 192 ", "128, 128, 128 ", "255, 165, 0 ", "255, 255, 255 "};

    int block_size = 25;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            int row = i / block_size;
            int col = j / block_size;
            int col_index = row * 4 + col;
            file << colors[col_index] << " ";
        }
    }

    file.close();
}