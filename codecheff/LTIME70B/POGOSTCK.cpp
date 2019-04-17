#include <iostream>
using namespace std;

int t, n, k, a[100001], maxi;

int main()
{
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n >> k;
        for (int j = 1; j <= n; j++)
            cin >> a[j];
        for (int j = n - k; j >= 1; j--)
            a[j] += a[j + k];
        maxi = a[1];
        for (int j = 2; j <= n; j++)
            if (a[j] > maxi)
                maxi = a[j];
        cout << maxi << endl;
    }
}