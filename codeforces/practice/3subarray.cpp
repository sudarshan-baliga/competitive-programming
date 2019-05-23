//http://codeforces.com/problemset/problem/466/C
#include <iostream>
#include <cstring>
using namespace std;

int main() {
	long long n, a[500000], cnt[500000], sum, req, ans;
	cin >> n;
	sum = 0;
	memset(cnt, 0, n * sizeof(long long));
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	ans = 0;
	if(sum % 3 == 0) {
		req = sum / 3;
		sum = 0;
		//find all the third part from back
		for(int j = n - 1; j > -1; j--) {
			sum += a[j];
			if(sum == req)
				cnt[j] = 1;
		}
		//mark number of third part after j
		for(int j = n - 2; j > -1; j--)
			cnt[j] += cnt[j + 1];
		//for(int j = 0; j < n; j++)
		//	cout << cnt[j] << " ";
		sum = 0;
		for(int j = 0; j < n - 2; j++)
		{
			sum += a[j];
			if(sum == req)
				ans += cnt[j + 2];
		}
	}
	cout << ans << endl;
	
}
