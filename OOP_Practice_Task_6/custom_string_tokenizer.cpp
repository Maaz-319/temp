#include <iostream>
#include <cstring>

using namespace std;

char **myStrTok(const char *str, const char *delim, int *N)
{
    int tokens = 1;
    for (int i = 0; *(str + i) != '\0'; i++) if (*(str + i) == *delim) tokens++;
    char **tok_str = new char *[tokens];
    *N = tokens;

    int counter = 0, reset = 0;
    for (int i = 0; *(str + i) != '\0'; i++)
    {
        if (*(str + i) == *delim)
        {
            int len = i - reset;
            char *token = new char[len + 1];
            for (int j = 0; j < len; j++) *(token + j) = *(str + reset + j);
            *(token + len) = '\0';

            *(tok_str + counter) = token;
            counter++;
            reset = i + 1;
        }
    }
    int len = strlen(str) - reset;
    char *token = new char[len + 1];
    for (int j = 0; j < len; j++) *(token + j) = *(str + reset + j);
    *(token + len) = '\0';
    *(tok_str + counter) = token;
    counter++;

    return tok_str;
}

int main()
{
    char text[] = "C++*is*awesome";
    int N;
    char **tokens = myStrTok(text, "*", &N);

    cout << "N = " << N << endl;
    for (int i = 0; i < N; i++) cout << *(tokens + i) << endl;
}