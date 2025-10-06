#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream file("diagnol_gradient.pgm");
    file << "P2\n200 200\n255\n";

    for (int i = 0; i < 200; i++)
    {
        for (int j = 0; j < 200; j++)
        {
            double distance = abs(i - j);
            int intensity = (int)(255.0 * (1.0 - distance / 199.0));

            if (intensity < 0) intensity = 0;
            if (intensity > 255) intensity = 255;

            file << intensity << " ";
        }
    }
    file.close();
    return 0;
}