//http://codeforces.com/problemset/problem/446/A
#include <iostream>
using namespace std;

int main() {
	int n, a[100000], l[100000], r[100000], ans;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	if(n<=2)
	{
		cout<<n<<'\n';
		return 0;
	}

	l[0] = 1;
	ans = 1;
	//find length of strictly increaing sequences
	for(int i = 1; i < n; i++)
		l[i] = (a[i] > a[i - 1] ? l[i-1] + 1 : 1),  ans = max(ans , l[i-1] + 1);
	//find length of strictly incresing sequences from end
	r[n - 1] = 1;
	for(int i = n - 2; i > -1; i--)
		r[i] = (a[i] < a[i + 1] ? r[i + 1] + 1 : 1), ans = max(ans, r[i + 1] + 1);
	//ans for current element is sum of strictly increasing sequences just before and after it
	for(int i = 1; i < n - 1; i++)
		if (a[i + 1] - a[i - 1] >= 2)
			ans = max(ans, l[i - 1] + 1 + r[i + 1]);
	cout << ans << endl;
}
