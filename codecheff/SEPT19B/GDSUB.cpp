#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#define MOD 1000000007
using namespace std;

long long findAns(vector<int> a, int freq[], int k)
{
    long long n = a.size();
    if (n < k)
        k = n;
    long long dp[n + 1][k + 1];

    //case where len is 0
    for (int idx = 0; idx <= n; idx++)
        dp[idx][0] = 1;

    //case where number of elements are zero
    for (int len = 1; len <= k; len++)
        dp[0][len] = 0;

    // general case
    for (int idx = 1; idx <= n; idx++)
        for (int len = 1; len <= k; len++)
        {
            // exclude current index
            dp[idx][len] = dp[idx - 1][len];
            // include current index
            dp[idx][len] = (dp[idx][len] + dp[idx - 1][len - 1] * freq[a[idx - 1]])% MOD;
        }
    //number of subseq with len <= k is
    long long ans = 0;
    for (int len = 1; len <= k; len++)
        ans =  (ans + dp[n][len]) % MOD;
    //subseq with len 0
    ans++;
    return ans;
}

int main()
{
    int k, n, freq[8001], temp;
    vector<int> a;
    cin >> n >> k;
    memset(freq, 0, sizeof(int) * 8001);
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        if (freq[temp] == 0)
        {
            a.push_back(temp);
        }
        freq[temp]++;
    }
    cout << findAns(a, freq, k) << endl;
}