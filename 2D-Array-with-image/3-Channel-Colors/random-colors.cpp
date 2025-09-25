#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;
int main()
{
    int h = 300, w = 300;

    ofstream file("output.ppm");
    file << "P3\n" << "# nothing....\n";
    file << w << " " << h << "\n" << 255 << endl;

    for(int i = 0; i < w*h; i++) file << rand() % 256 << " " << rand() % 256 << " " << rand() % 256 << " ";
    
    file.close();
    return 0;
}