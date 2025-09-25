#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    int h = 400, w = 400;
    int box_size = h / 8;

    ofstream file("output.pgm");
    file << "P2\n" << "# nothing....\n";
    file << w << " " << h << "\n" << 255 << endl;

    int pix = 255;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if ((j % box_size == 0))
            {
                if (pix == 255) pix = 127;
                else pix = 255;
            }
            file << pix << " ";
        }
        if ((i % box_size == 0))
        {
            if (pix == 255) pix = 127;
            else pix = 255;
        }
    }
    return 0;
}