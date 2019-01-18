#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long ans, temp, t, n, p, diff;
    cin >> t;
    for (int l = 0; l < t; l++)
    {
        cin >> n >> p;
        if(n == 1 || n == 2)
        {
            cout << p * p * p << endl;
            continue;
        }
        if(n == p)
        {
            temp = n / 2 + 1;
            cout << 1LL * temp * temp << endl;
            continue;
        }
        else
        {
            diff = p - n;
            temp = n / 2 + 1 + diff;
            ans = (temp * (temp + 1)) + (diff * diff) + (diff - 1) * temp;
            cout << ans << endl;
        }
    }
}
