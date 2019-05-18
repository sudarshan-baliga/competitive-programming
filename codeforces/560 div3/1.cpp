#include <iostream>
using namespace std;

int main() {
	int x, y, n, ans = 0;
	string d;
	cin >> n >> x >> y >> d;
	if(d[n - y - 1]  != '1') 
		ans++;
	else
		d[n - y - 1] = '0';
	for(int i = n  - x; i < n ; i++)
		if( d[i] != '0')
			ans++;
	cout << ans << endl;
}
