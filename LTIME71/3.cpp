#include <iostream>
#include <algorithm>
using namespace std;

int t, n;
long long ans, a[100001], b[100001], acopy[100001], aCount;

int main()
{
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        cin >> n;
        ans = 0;
        aCount = 0;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        for(int i = 0; i < n; i++)
            cin >> b[i];
        for(int j = n - 2; j > -1; j--)
        {
            b[j] = b[j + 1] + b[j];
            // cout << a[j] << " ";
        }
        // cout << endl;
        ans = b[0];
        for(int j = 0; j < n - 1; j++)
        {
            aCount += a[j];
            ans = max(ans, aCount + b[j + 1]);
        }
        ans = max({ans, aCount + a[n - 1]});
        cout << ans << endl;
    }
}