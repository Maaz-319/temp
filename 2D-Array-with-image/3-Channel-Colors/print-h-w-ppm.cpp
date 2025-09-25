#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main()
{
    ifstream file("img.ppm");

    int h, w, maxVal;

    // ignoring the first 2 lines
    for (int i = 0; i <= 1; i++)
    {
        string a;
        getline(file, a);
    }

    // reading width, height, maximum value
    file >> w >> h >> maxVal;
    file.close();

    cout << "HEIGHT: " << h << endl;
    cout << "WIDTH: " << w << endl;
}