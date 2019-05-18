#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


void printPad(int k, string s) {
	int times = k / 5;
	while(times--) {
		cout << s;
	}
	cout << s.substr(0, k % 5);
}


int main() {
	int k, pad, limit;
	string s = "aeiou";
	cin >> k;
	if(k < 25) {
		cout << -1 << endl;
		return 0;
	}
	bool found = false;
	int n = 5, m = -1;
	while(n <= k) {
		if(k % n == 0) {
			if(k / n > 4) {
				found = true;
				m = k / n;
				break;
			}
		}
		n++;
	}
	if(!found) {
		cout << - 1  << endl;
		return 0;
	}
	while(n--) {
		printPad(m, s);
		rotate(s.begin(), s.begin() + 1, s.end());
	}
}
