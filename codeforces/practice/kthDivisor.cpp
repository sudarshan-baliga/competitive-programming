//http://codeforces.com/problemset/problem/762/A
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;


int main() {
	long long n, k, root;
	vector<long long> divisors;
	cin >> n >> k;
	root = (long long) pow(n , 0.5) + 1;
	for(long long i  = 1; i < root; i++) {
		if(n % i == 0) {
				if(i != n / i) {
					divisors.push_back(i);
					divisors.push_back(n / i);
				}
				else
					divisors.push_back(i);
		}
	}
	if(k > divisors.size()) {
		cout << -1 << endl;
		return 0;
	}
	sort(divisors.begin(), divisors.end());
	cout << divisors[k - 1] << endl;
}
