#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char seq_1[100];
    char seq_2[100];

    cout << "dna(MAX 100): ";
    cin >> seq_1;
    cout << "pattern(MAX 100): ";
    cin >> seq_2;

    int s1 = strlen(seq_1);
    int s2 = strlen(seq_2);
    
    if (s2 > s1)
    {
        cout << "NOT MATCHED";
        return 0;
    }

    bool got_it = true;
    for (int i = 0; i <= s1 - s2; i++)
    {
        got_it = true;
        for (int j = 0; j < s2; j++)
        {
            if (*(seq_1 + i + j) != *(seq_2 + j))
            {
                got_it = false;
                break;
            }
        }
        if (got_it)
            break;
    }

    if (got_it)
        cout << "GOT IT";
    else
        cout << "NOT MATCHED";

    return 0;
}