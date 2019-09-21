#include <iostream>
using namespace std;
const long long  MOD = 1e9 + 7;
long long t, n, dp[101];
void calculate()
{
    for (int i = 0; i <= 100; i++)
    {
        if (i <= 2)
            dp[i] = i;
        else
        {
            dp[i] = (dp[i - 1] % MOD+ ((i - 1) * dp[i - 2]) % MOD) % MOD;
        }
    }
}

int main()
{
    calculate();
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << dp[n] << endl;
    }
}