#include <iostream>
using namespace std;

int n;
string s;

void solve()
{
    int cost = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            cost++;
            if (i + 2 < n && s[i + 2] == s[i + 1])
            {
                if (s[i + 1] == 'R')
                    s[i + 1] = 'G';
                else if (s[i + 1] == 'G')
                    s[i + 1] = 'B';
                else
                    s[i + 1] = 'R';
                continue;
            }
            else if (i + 2 < n)
            {
                if (s[i + 1] == 'R' && s[i + 2] != 'G')
                {
                    s[i + 1] = 'G';
                    continue;
                }
                else if (s[i + 1] == 'R')
                {
                    s[i + 1] = 'B';
                    continue;
                }
                if (s[i + 1] == 'G' && s[i + 2] != 'R')
                {
                    s[i + 1] = 'R';
                    continue;
                }
                else if (s[i + 1] == 'G')
                {
                    s[i + 1] = 'B';
                    continue;
                }
                if (s[i + 1] == 'B' && s[i + 2] != 'G')
                    s[i + 1] = 'G';
                else if (s[i + 1] == 'B')
                    s[i + 1] = 'R';
                continue;
            }
            else
            {
                if (s[i + 1] == 'R')
                    s[i + 1] = 'B';
                else if (s[i + 1] == 'G')
                    s[i + 1] = 'B';
                else
                    s[i + 1] = 'R';
            }
        }
    }
    cout << cost << endl
         << s;
}

int main()
{
    cin >> n >> s;
    solve();
}