//http://codeforces.com/problemset/problem/431/C
#include <iostream>
using namespace std;
const int mod = 1e9 + 7;


int main() {
	int n, k, d;
	cin >> n >> k >> d;
	long long dp[n + 1][2];
	dp[0][0] = 1;
	dp[0][1] = 0;
	for(int tot = 1; tot <= n; tot++) {
		dp[tot][0] = dp[tot][1] = 0;
		for(int weight = 1; weight <= k; weight++) {
			if(tot - weight < 0)
				break;
			if(weight < d) {
				dp[tot][0] = (dp[tot][0] + dp[tot - weight][0]) % mod;
				dp[tot][1] = (dp[tot][1] + dp[tot - weight][1]) % mod;
			} else {
				dp[tot][1] = (dp[tot][1] + dp[tot - weight][0] + dp[tot - weight][1] ) % mod;
			}
		}
	}
	cout << dp[n][1] << endl;
}
