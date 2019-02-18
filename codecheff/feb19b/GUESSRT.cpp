#include <iostream>
using namespace std;
typedef long long ll;
#define MOD 1000000007
ll getGcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return getGcd(b % a, a);
}

ll findInverse(int a)
{
    int m = MOD, m0 = m, y = 0, x = 1;
    if (m == 1)
        return 0;
    while (a > 1)
    {
        int q = a / m;
        int t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
        x += m0;

    return x;
}

int main()
{
    ll t, n, k, m, times, p, q, temp, gcd;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n >> k >> m;
        //first move make a guess
        p = 1, q = n;
        times = 0;
        m--; //first guess
        if (m != 0)
        {
            // remove and guess every times
            times += m / 2;
            //simplified equations
            temp = (n * n);
            p = p * temp + (n - 1) * q * times;
            q = q * temp;
            cout << p << " " << q << endl;
        }
        //if last move is remaining make a guess
        if (m % 2)
        {
            temp = (n * n + n * k);
            p = p * temp + (n + k - 1) * q;
            q = q * temp;
        }
        gcd = getGcd(p, q);
        p /= gcd, q /= gcd;
        cout << "inver " << findInverse(q) << endl;
        cout << ((p % MOD) * (findInverse(q) % MOD)) % MOD << endl;
    }
}