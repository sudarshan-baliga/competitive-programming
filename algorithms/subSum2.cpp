#include <iostream>
#include <cstring>
using namespace std;

int printCount(int n, int a[], int sum)
{
    int dp[sum + 1][n + 1];
    for (int i = 1; i <= n; i++)
        dp[0][i] = 1; //it is always empty set where sum is 0;
    for (int i = 1; i <= sum; i++)
        dp[i][0] = 0; //empty set cannot give any other sum than 0
    for (int i = 1; i <= sum; i++)
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = dp[i][j - 1];
            if (a[j] <= i)
                dp[i][j] += dp[i - a[j]][j - 1];
        }
    return dp[sum][n];
}

int main()
{
    int t, n, a[100001], sum;
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        cin >> sum;
        cout << printCount(n, a, sum) << endl;
    }
}