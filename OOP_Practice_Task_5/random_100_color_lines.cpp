#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int w = 200, h = 200, no_of_lines = 100;
    srand(time(NULL));
    ofstream file("colourful_lines.ppm", ios::binary);
    file << "P6\n"
         << w << " " << h << "\n255\n";

    unsigned char r_s[w * h * 3] = {0};

    for (int i = 0; i < no_of_lines; i++)
    {
        int start_pos_x = rand() % w;
        int start_pos_y = rand() % h;
        int length_of_line = rand() % (w / 2) + 50;
        int c1 = rand() % 256;
        int c2 = rand() % 256;
        int c3 = rand() % 256;

        int direction = rand() % 4;
        for (int j = 0; j < length_of_line; j++)
        {
            if (start_pos_x >= 0 && start_pos_x < w && start_pos_y >= 0 && start_pos_y < h)
            {
                int idx = (start_pos_y * w + start_pos_x) * 3;
                r_s[idx] = c1;
                r_s[idx + 1] = c2;
                r_s[idx + 2] = c3;
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

    file.write((char *)r_s, sizeof(r_s));

    file.close();
    return 0;
}