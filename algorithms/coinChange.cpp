#include <iostream>
#include <map>
using namespace std;

int t, n, m, a[300];
int coinChange(int cur, int idx)
{
    int inc, exc;
    int dp[n + 1][m];
    for (int i = 0; i < m; i++)
        dp[0][i] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < m; j++)
        {
            inc = (i - a[j]) > -1 ? dp[i - a[j]][j] : 0;
            exc = (j != 0) ? dp[i][j - 1] : 0;
            dp[i][j] = inc + exc;
        }
    return dp[n][m - 1];
}

int main()
{

    cin >> t;
    while (t--)
    {
        cin >> m;
        for (int i = 0; i < m; i++)
            cin >> a[i];
        cin >> n;
        cout << coinChange(n, 0) << endl;
    }
}