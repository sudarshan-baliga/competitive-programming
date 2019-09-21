#include <iostream>
#include <algorithm>
using namespace std;

long long findSubSeq(int a[], int idx, int n, int req, int sz)
{
    long long dp[n + 1][req + 1][sz + 1];

    //we cant get any sum with 0 element (except for 0 sum and 0 len)
    for (int rq = 0; rq <= req; rq++)
        for (int len = 0; len <= sz; len++)
                dp[0][rq][len] = 0;
    //cant get 0 sum with len >= 1
    for(int idx = 0; idx <= n; idx++)
        for(int len = 1; len <= sz; len++)
            dp[idx][0][len] = 0;
    //0 len and no sum except 0 is possible
    for(int idx = 0; idx <= n; idx++)
        for(int rq = 1; rq   <= req; rq++)
            dp[idx][rq][0] = 0;

     //0 sum and 0 len
    for(int idx = 0; idx <= n; idx++)
        dp[idx][0][0] = 1;

    //general case
    for (int idx = 1; idx <= n; idx++)
        for (int rq = 1; rq <= req; rq++)
            for (int len = 1; len <= sz; len++)
            {
                //exclude
                dp[idx][rq][len] = dp[idx - 1][rq][len];
                //include
                if (rq - a[idx - 1] >= 0)
                    dp[idx][rq][len] += dp[idx - 1][rq - a[idx - 1]][len - 1];
            }
    return dp[n][req][sz];
}

int main()
{
    int t, k, n, a[50], req;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a + n);
        req = 0;
        for (int i = 0; i < k; i++)
            req += a[i];
        cout << findSubSeq(a, 0, n, req, k) << endl;
    }
}