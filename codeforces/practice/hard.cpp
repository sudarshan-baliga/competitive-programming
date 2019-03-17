// http://codeforces.com/problemset/problem/706/C
#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;
const long long INF 1e15; 
struct Element
{
    string a, b;
    int cost;
} ele[100001];

long long n, dp[100001][2];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> ele[i].cost;
    for (int i = 1; i <= n; i++)
    {
        cin >> ele[i].a;
        ele[i].b = ele[i].a;
        reverse(ele[i].b.begin(), ele[i].b.end());
        dp[i][0] = dp[i][1] = INF;
    }
    dp[1][0] = 0, dp[1][1] = ele[1].cost;
    for (int i = 2; i <= n; i++)
    {
        if (ele[i].a >= ele[i - 1].a)
            dp[i][0] = min(dp[i][0], dp[i - 1][0]);
        if (ele[i].a >= ele[i - 1].b)
            dp[i][0] = min(dp[i][0], dp[i - 1][1]);
        if (ele[i].b >= ele[i - 1].a)
            dp[i][1] = min(dp[i][1], dp[i - 1][0] + ele[i].cost);
        if (ele[i].b >= ele[i - 1].b)
            dp[i][1] = min(dp[i][1], dp[i - 1][1] + ele[i].cost);
        ;
    }
    long long ans = min(dp[n][0], dp[n][1]);
    if (ans == INF)
        cout << -1 << endl;
    else
        cout << ans << endl;
}