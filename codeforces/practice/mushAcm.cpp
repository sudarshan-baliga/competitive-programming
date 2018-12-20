// http://codeforces.com/contest/414/problem/B
#include <iostream>
#include <vector>
#define MOD 1000000007;
using namespace std;

int main()
{
    long long n, k, dp[2001][2001];
    cin >> n >> k;
    vector<int> divisor[n + 1];
    for (int i = 1; i <= n; i++)
        for (int k = i; k <= n; k += i)
            divisor[k].push_back(i);
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= k; j++)
            dp[j][i] = 0;
    dp[0][1] = 1;
    for (int j = 1; j <= n; j++)
        for (int i = 1; i <= k; i++)
        {
            for (int divi : divisor[j])
                dp[i][j] = (dp[i][j] + dp[i - 1][divi]) % MOD;
        }
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += dp[k][i];
        ans %= MOD;
    }
    cout << ans << endl;
}