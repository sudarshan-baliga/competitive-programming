#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    long long n, a[200000], gcd, maxi = -1, ans;
    vector<long long> changes;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        maxi = max(maxi, a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] != maxi)
        {
            changes.push_back(maxi - a[i]);
        }
    }
    if (changes.size() == 1)
    {
        cout << 1 << " " << changes[0] << endl;;
        exit(0);
    }
    gcd = changes[0];
    for (int i = 1; i < changes.size(); i++)
        gcd = __gcd(changes[i], gcd);
    ans = 0;
    for (int i = 0; i < changes.size(); i++)
        ans += changes[i] / gcd;
    cout << ans << " " << gcd << endl;
}