#include <iostream>
using namespace std;

int main()
{
    long long t, n, a, ans;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        ans = 0;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            cin >> a;
            ans += a;
        }
        ans -= n;
        ans++;
        cout << ans << endl;
    }
}
