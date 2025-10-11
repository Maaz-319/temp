#include <iostream>
#include <cstring>
using namespace std;

class Roman_Number
{
    char roman[100];
    int decimal;

    int r_to_d_mapper(const char &ch)
    {
        switch (toupper(ch))
        {
            case 'I': return 1; break;
            case 'V': return 5; break;
            case 'X': return 10; break;
            case 'L': return 50; break;
            case 'C': return 100; break;
            case 'D': return 500; break;
            case 'M': return 1000; break;
            default: break; 
        }
        return -1;
    }

    void roman_to_decimal()
    {
        int total = r_to_d_mapper(roman[strlen(roman) - 1]);
        int largest = r_to_d_mapper(roman[strlen(roman) - 1]);
        for (int i = strlen(roman) - 2; i >= 0; i--)
        {
            int curr_value = r_to_d_mapper(roman[i]);
            if (curr_value >= largest)
            {
                largest = curr_value;
                total += curr_value;
            }
            else total -= curr_value;
        }
        decimal = total;
    }

    void decimal_to_roman()
    {
        int dec = decimal;
        char rm[100];
        int counter = 0;

        while (dec > 0)
        {
            if (dec >= 1000) { rm[counter++] = 'M'; dec -= 1000; continue;}
            else if (dec >= 900) { rm[counter++] = 'C'; rm[counter++] = 'M'; dec -= 900; continue; }
            else if (dec >= 500) { rm[counter++] = 'D'; dec -= 500; continue; }
            else if (dec >= 400) { rm[counter++] = 'C'; rm[counter++] = 'D'; dec -= 400; continue; }
            else if (dec >= 100) { rm[counter++] = 'C'; dec -= 100; continue; }
            else if (dec >= 90) { rm[counter++] = 'X'; rm[counter++] = 'C'; dec -= 90; continue; }
            else if (dec >= 50) { rm[counter++] = 'L'; dec -= 50; continue; }
            else if (dec >= 40) { rm[counter++] = 'X'; rm[counter++] = 'L'; dec -= 40; continue; }
            else if (dec >= 10) { rm[counter++] = 'X'; dec -= 10; continue; }
            else if (dec >= 9) { rm[counter++] = 'I'; rm[counter++] = 'X'; dec -= 9; continue; }
            else if (dec >= 5) { rm[counter++] = 'V'; dec -= 5; continue; }
            else if (dec >= 4) { rm[counter++] = 'I'; rm[counter++] = 'V'; dec -= 4; continue; }
            else if (dec >= 1) { rm[counter++] = 'I'; dec -= 1; continue; }
        }
        rm[counter] = '\0';
        strcpy(roman, rm);
    }

public:
    void set_decimal(int dec)
    {
        decimal = dec;
        decimal_to_roman();
    }

    void set_roman(const char *rm)
    {
        strcpy(roman, rm);
        roman_to_decimal();
    }

    int get_decimal() { return decimal; }
    const char *get_roman() { return roman; }
};

int main()
{
    Roman_Number rm;
    rm.set_decimal(1110);
    cout << "\nDECIMAL: " << rm.get_decimal() << endl;
    cout << "ROMAN: " << rm.get_roman();
}