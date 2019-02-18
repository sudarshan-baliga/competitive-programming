#include <iostream>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int main()
{
    ll t, k, n, a, b, lcm, acount, bcount, ans;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n >> a >> b >> k;
        if (gcd(a, b) == 1)
        {
            lcm = a * b;
            acount = n / a;
            bcount = n / b;
            ans = acount + bcount - 2 * (n / lcm);
        }
        else
            ans = n / min(a, b) - (n / max(a, b));
        if (ans >= k)
            cout << "Win" << endl;
        else
            cout << "Lose" << endl;
    }
}