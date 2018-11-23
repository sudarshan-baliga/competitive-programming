#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    long long n, m, b[100000], pre, ans, maxi;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    if (n == 1)
    {
        cout << 0;
        return 0;
    }
    sort(b, b + n);
    maxi = b[n - 1];
    pre = ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (pre != maxi)
        {
            ans += b[i] - 1;
            if ((pre + 1) <= b[i])
                pre++;
            // cout << b[i] << " hh" << pre << " " << ans << endl;
        }
        else
        {
            // cout << "max" << maxi << " " << pre << endl;
            ans += maxi - 1;
        }
    }
    if (pre != maxi)
        ans -=  b[n-1] - pre;
    cout << ans;
}