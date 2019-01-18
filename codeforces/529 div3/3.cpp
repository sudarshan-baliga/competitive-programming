#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

ll n, k, bin[32], count;

void binRep(ll x)
{
    ll rem, i = 0;
    while (x != 0)
    {
        bin[i++] = x & 1;
        x = x >> 1;
    }
}

int main()
{
    cin >> n >> k;
    binRep(n);
    for (int i = 0; i < 32; i++)
    {
        // cout << bin[i];
        if (bin[i])
            count++;
    }
    if (count > k || k > n)
    {
        cout << "NO" << endl;
        return 0;
    }

    for (int i = 31; i > 0;)
    {
        while (i > -1 && bin[i] == 0)
            i--;
        if (count == k || i < 1)
            break;
        if (bin[i] > 0)
        {
            bin[i]--;
            bin[i - 1] += 2;
            count++;
        }
    }

    if (count != k)
    {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    for(int i = 0; i < 32 ;i++)
        // cout << bin[i];
            while(bin[i] != 0)
            {
                cout << (1 << i) << " ";
                bin[i]--;
            }
}