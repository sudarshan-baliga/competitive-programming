// http://codeforces.com/problemset/problem/698/A
# include <iostream>
# include <algorithm>
using namespace std;

int n, a[101], dp[101][3];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        //if he takes rest
        dp[i][0] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
        //contest
        if(a[i] == 1 || a[i] == 3){
            dp[i][1] = max(dp[i - 1][0] + 1, dp[i - 1][2] + 1);
        }
        //gym
        if(a[i] == 2 || a[i] == 3){
            dp[i][2] = max(dp[i - 1][0] + 1, dp[i - 1][1] + 1);
        }
    }
    cout << n - max({dp[n][0], dp[n][1], dp[n][2]});
}