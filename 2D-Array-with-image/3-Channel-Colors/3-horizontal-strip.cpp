#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    int h = 300, w = 300;

    ofstream file("output.ppm");
    file << "P3\n" << "# nothing....\n";
    file << w << " " << h << "\n" << 255 << endl;

    for (int j = 0; j < 30000; j++) file << "255 0 0 ";
    for (int j = 0; j < 30000; j++) file << "0 255 0 ";
    for (int j = 0; j < 30000; j++) file << "0 0 255 ";

    file.close();
    return 0;
}