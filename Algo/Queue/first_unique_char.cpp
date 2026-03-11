#include <iostream>
#include <queue>
#include <vector>

using namespace std;
int firstUniqChar(string s)
{
    vector<int> frq(26, 0);
    queue<int> q;
    for (int i = 0; i < s.size(); i++)
    {
        frq[s[i] - 'a']++;
        q.push(i);
        while (!q.empty() && frq[s[q.front()] - 'a'] > 1)
            q.pop();
    }
    return (q.empty() ? -1 : q.front());
}