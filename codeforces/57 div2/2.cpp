#include <iostream>
#define MOD 998244353;
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n;
    cin >> s;
    int beg = 0, end = 0, i = 0;
    while (i < n - 1 && s[i] == s[0])
    {
        i++;
        beg++;
    }
    i = n - 1;
    while (i > 0 && s[i] == s[n - 1])
    {
        i--;
        end++;
    }
    if (s[0] == s[n - 1])
    {
        cout << ((beg + 1) * 1ll * (end + 1)) % MOD;
    }
    else
        cout << (beg + end + 1) % 998244353;
}