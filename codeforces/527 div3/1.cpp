#include <iostream>
using namespace std;

int main()
{
    int t, n, k, rem, sz, temp, r;
    string ans = "";
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n >> k;
        rem = n % k;
        sz = n / k;
        for (int i = 0, r = 1; i < n; i++)
        {
            ans += (char)(96 + r);
            r = (r + 1) % (k + 1);
            if (r == 0)
                r = 1;
        }
        cout << ans << endl;
        ans = "";
    }
}