#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int w = 200, h = 200, no_of_lines = 100;
    srand(time(NULL));
    ofstream file("lines.pgm");
    file << "P5\n"
         << w << " " << h << "\n255\n";

    unsigned char arr[w * h] = {0};

    for (int i = 0; i < no_of_lines; i++)
    {
        int start_pos_x = rand() % w;
        int start_pos_y = rand() % h;
        int length_of_line = rand() % (w / 2) + 50;

        int direction = rand() % 4;
        for (int j = 0; j < length_of_line; j++)
        {
            if (start_pos_x >= 0 && start_pos_x < w && start_pos_y >= 0 && start_pos_y < h)
            {
                arr[start_pos_y * w + start_pos_x] = 255;
            }
            else
            {
                break;
            }
            if (!direction)
            {
                start_pos_y--;
            }
            else if (direction == 1)
            {
                start_pos_y++;
            }
            else if (direction == 2)
            {
                start_pos_x++;
            }
            else if (direction == 3)
            {
                start_pos_x--;
            }
        }
    }

    file.write((char *)arr, sizeof(arr));
    file.close();
    return 0;
}