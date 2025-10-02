#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int h, w, maxval;
    string temp;

    ifstream file("img.pgm", ios::binary);

    getline(file, temp);
    getline(file, temp);

    file >> w >> h >> maxval;

    unsigned char arr[w * h];

    file.read((char *)arr, sizeof(arr));
    file.close();

    for (int i = h / 2 - 50; i < h / 2 + 50; i++)
    {
        for (int j = w / 2 - 50; j < w / 2 + 50; j++)
        {
            arr[i * w + j] = 255;
        }
    }

    ofstream output_file("output.pgm", ios::binary);

    output_file << "P5\n" << w << " " << h << "\n" << maxval << "\n";

    output_file.write((char *) arr, sizeof(arr));

    output_file.close();

    return 0;
}