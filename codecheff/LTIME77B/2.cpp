#include <iostream>
using namespace std;

int main()
{
    long long t, n, k, a[101], ans, greaterCountAhead[101], greaterCountBehind[101], count, summation;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            cin >> a[i];

        for (int i = 1; i <= n; i++)
        {
            greaterCountAhead[i] = 0;
            for (int j = i + 1; j <= n; j++)
                if (a[j] < a[i])
                {
                    greaterCountAhead[i]++;
                }
            greaterCountBehind[i] = 0;
            for (int j = i - 1; j > -1; j--)
                if (a[j] < a[i])
                    greaterCountBehind[i]++;
            // cout << greaterCountBehind[i] << " " << greaterCountAhead[i] << endl;
        }
        ans = 0;
        summation = (k * (k + 1)) / 2;
        for (int i = 1; i <= n; i++)
        {
            ans += (greaterCountAhead[i] * summation) + greaterCountBehind[i] * (summation - k);
        }
        cout << ans << endl;
    }
}