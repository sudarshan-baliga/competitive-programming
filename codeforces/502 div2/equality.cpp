#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int n, k, alp[26] = {0}, minima = INT_MAX, ans = 0;
    bool noChar = false;
    cin >> n >> k;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        alp[int(s[i]) % 65]++;
    }

    for (int j = 0; j < k; j++)
    {
        if (alp[j] <= minima)
            minima = alp[j];
        if (alp[j] == 0)
        {
            noChar = true;
            break;
        }
    }
    if (noChar)
        cout << 0;
    else
    {
        cout << minima * k;
    }
}