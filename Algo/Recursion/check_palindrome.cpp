#include <iostream>

using namespace std;

string reverse(string s) {
    if (s.length() <=1 ) return s;
    return reverse(s.substr(1)) + s[0];
}

int main()
{
    string str = "never reven";
    cout << (str == reverse(str));
    return 0;
}