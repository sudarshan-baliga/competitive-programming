//http://codeforces.com/problemset/problem/126/B
#include <iostream>
using  namespace std;

void kmp(string s, int *lsp) {
	lsp[0] = 0;
	int i, j, len = s.length();
	i = 0, j = 1;
	while(j < len) {
		if(s[i] == s[j]) {
			i++;
			lsp[j] = i;
		//	cout << lsp[j] << "c "  << endl ;
			j++;
		}
		else {
			if(i != 0) {
				i = lsp[i - 1];
			}
			else {
				lsp[j] = 0;
				//cout << lsp[j] << "nc " << i << endl;
				j++;
			}
		}
	}
	
}

int main() {
	string s;
	cin >> s;
	int lsp[s.length()], n = s.length();
	kmp(s,lsp);
	if(lsp[n - 1] == 0)
	{
		cout << "Just a legend" << endl;
		return 0;
	}
	int len = n - 2;
	while(len-- > -1)
		if(lsp[len] == lsp[n - 1]) {
			cout << s.substr(0, lsp[len]) << endl;
			return 0;
		}
	if(lsp[lsp[n -1] - 1] != 0)
	{
		cout << s.substr(0, lsp[lsp[n - 1] - 1]) << endl;
		return 0;
	}
	cout << "Just a legend" << endl;
}
