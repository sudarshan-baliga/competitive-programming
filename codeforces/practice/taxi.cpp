//http://codeforces.com/problemset/problem/158/B
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

int main() {
	int n, f[5], s, ans, count;
	cin >> n;
	memset(f, 0, 5 * sizeof(int));
	while(n--) {
		cin >> s;
		f[s]++;
	}
	//send groups of 4
	ans = 0;
	ans += f[4];
	f[4] = 0;
	//combile 3 and 1
	//cout << f[1] << " " << f[2] << " " << f[3] << " " << f[4] << " " << ans << endl;
	count = min(f[3], f[1]);
	ans += count;
	f[3] -= count;
	f[1] -= count;
	//cout << f[1] << " " << f[2] << " " << f[3] << " " << f[4] << " " << ans << endl;
 //combine 2 and 1
	count = f[1] / 2;
	count = min(count, f[2]);
	ans += count;
	f[1] -= count * 2;
	f[2] -= count;
	if(f[1] > 0 && f[2] > 0) {
		f[2]--;
		f[1]--;
		ans++;
	}
	//cout << f[1] << " " << f[2] << " " << f[3] << " " << f[4] << " " << ans << endl;
	//send remaining 1s 2s and threes
	ans += ceil(f[1] / 4.0);
	ans += ceil(f[2] / 2.0);
	ans += f[3];
	//cout << f[1] << " " << f[2] << " " << f[3] << " " << f[4] << " " << ans << endl;
	cout << ans << endl;
}
