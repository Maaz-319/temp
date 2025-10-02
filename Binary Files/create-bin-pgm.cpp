#include <iostream>
#include <fstream>

using namespace std;

int main() {
    
    // 100 100, white 255

    int h = 100, w = 100, maxval = 255;

    ofstream file("output.pgm", ios::binary);

    file << "P5\n" << w << " " << h << "\n" << maxval << "\n";

    unsigned char arr[w * h];

    for (int i = 0; i < w * h; i++){
        arr[i] = 255;
    }

    file.write((char *) arr, sizeof(arr));

    file.close();

    return 0;
}