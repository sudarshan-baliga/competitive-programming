//http://codeforces.com/problemset/problem/707/C
#include <iostream>
using namespace std;

int main() {
	long long n, a, b;
	cin >> n;
	if(n  <= 2) {
		cout << -1 << endl;
		return 0;
	}
	if(n % 2) {
		a = (n * n + 1) / 2;
		b = (n * n - 1) / 2;
	} 
	else {
		a = (n * n / 4) + 1;
		b = (n * n / 4) - 1;
	}
	cout << a << " " << b <<  endl;
}
