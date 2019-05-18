#include <iostream>
using namespace std;

int main() {
	int n, cur, init;
	string s;
	cin >> n >> s;
	cur = 0;
	init = 0;
	for(char ch : s) {
		if(ch == '+')
			cur++;
		if(ch == '-') {
			cur--;
			if(cur < 1) {
				cur = 0;
				init++;
			}
		}
	}
	cout << cur << endl;
}
