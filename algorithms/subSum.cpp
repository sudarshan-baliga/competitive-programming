// https://practice.geeksforgeeks.org/problems/subset-sum-problem/0
#include <iostream>
using namespace std;

bool findSum(int sum, int n, int a[])
{
    bool dp[sum + 1][n + 1];
    for (int i = 0; i <= n; i++)
        dp[0][i] = true;
    for (int i = 1; i <= sum; i++)
        dp[i][0] = false;

    for (int i = 1; i <= sum; i++)
        for (int j = 1; j <= n; j++)
        {
            if(a[j] > i)
                dp[i][j] = dp[i][j - 1];
            if(i >= a[j])
                dp[i][j] = dp[i - a[j]][j - 1] || dp[i][j - 1];
        }
    return dp[sum][n];
}

int main()
{
    int t, n, a[101], total;
    cin >> t;
    while (t--)
    {
        cin >> n;
        total = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            total += a[i];
        }
        if (total % 2)
        {
            cout << "NO" << endl;
            continue;
        }
        if(findSum(total / 2, n, a))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}