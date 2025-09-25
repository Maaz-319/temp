#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    int h = 100, w = 100;

    ofstream file("output.ppm");
    file << "P3\n" << "# nothing....\n";
    file << w << " " << h << "\n" << 255 << endl;

    for(int i = 0; i < h / 2; i++){
        for(int j = 0; j < w / 2; j++) file << "255 255 255 ";
        for(int j = w / 2; j < w; j++) file << "0 0 255 ";
    }

    for(int i = h / 2; i < h; i++){
        for(int j = 0; j < w / 2; j++) file << "0 255 0 ";
        for(int j = w / 2; j < w; j++) file << "255 0 0 ";
    }


    file.close();
    return 0;
}