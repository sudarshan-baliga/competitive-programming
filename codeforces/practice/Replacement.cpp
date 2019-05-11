//http://codeforces.com/contest/570/problem/C
#include <iostream>
using namespace std;

int main() {
	int n, m, tempAns, ans;
	string s;
	cin >> n >> m >> s;
	tempAns = ans = 0;
	for(char ch : s) {
		if(ch == '.')
			tempAns++;
		else {
			if(tempAns != 0)
				ans += tempAns - 1;
			tempAns = 0;
		}
	}
	if(tempAns != 0)
		ans += tempAns - 1;
	int x;
	char ch;
	while(m--) {
		cin >> x >> ch;
		x--;
		if(s[x] != '.') {
			if(ch != '.') ;
			else {
				if(x != 0 && s[x - 1] == '.')
					ans++;
				if(x + 1 != n && s[x + 1] == '.')
					ans++;
			}
		}
		else {
			if(ch == '.') ;
			else {
				if(x != 0 && s[x - 1] == '.')
					ans--;
				if(x + 1 != n && s[x + 1] == '.')
					ans--;
			}
		}
		s[x] = ch;
		cout <<ans << endl;
	}
}
