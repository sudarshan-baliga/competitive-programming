#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, a[200001], ans = 0;
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	int k = 1, idx = 0;
	while(idx < n) {
		if(a[idx] >= k) {
				ans++;
				k++;
		}
		idx++;
		continue;
	}
	cout << ans<< endl;
}
