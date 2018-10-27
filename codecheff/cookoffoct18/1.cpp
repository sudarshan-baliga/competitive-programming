#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int t, n, k, ans;
    float diff, h[129];
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n >> k;
        for (int j = 0; j < n; j++)
            cin >> h[j];
        ans = 0;
        if (h[0] > k)
            ans += ceil(h[0] / k) - 1;
        for (int j = 1; j < n; j++)
        {
            diff = h[j] - h[j - 1];
            if (diff > k)
            {
                ans += ceil(diff / k) - 1;
                // cout << diff << " " << h[j] << " " << ceil(diff / k) - 1 << endl;
            }
        }
        cout << ans << endl;
    }
}