// https://practice.geeksforgeeks.org/problems/subset-with-sum-divisible-by-m/0
#include <iostream>
#include <cstring>
using namespace std;

bool checkAns(int n, int m, int a[])
{

    if (n > m)
        return true;
    bool dp[m], temp[m];
    memset(dp, 0, m);
    for (int i = 1; i <= n; i++)
    {
        if (dp[0])
            return true;
        memset(temp, 0, m);
        for (int j = 0; j < m; j++)
        {
            if (dp[j] == true)
                if (dp[(j + a[i]) % m] == false)
                {
                    temp[(j + a[i]) % m] = true;
                }
        }
        for (int j = 0; j < m; j++)
            if (temp[j])
                dp[j] = true;
        dp[a[i] % m] = true;
    }
    return dp[0];
}

int main()
{
    int t, n, m, a[1001];
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        cout << checkAns(n, m, a) << endl;
    }
}