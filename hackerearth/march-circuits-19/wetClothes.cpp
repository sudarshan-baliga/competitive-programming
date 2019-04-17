#include <iostream>
using namespace std;

int main()
{
	int n, m, g, t1, t2, diff, ans = 0, ai;
	cin >> n >> m >> g;
	cin >> t1;
	for(int i = 2; i <= n; i++)
	{
		cin >> t2;
		if(t2 - t1 > diff)
			diff = t2 - t1;
		t1 = t2;
	}
	for(int i = 0; i < m; i++)
	{
		cin >> ai;
		if(ai <= diff)
			ans++;
	}
	cout << ans << endl;
}
