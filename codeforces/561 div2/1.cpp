#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int main() {
	int alph[26], n, ans = 0, class1, class2;
	string s;
	memset(alph, 0, 26 * sizeof(int));
	cin >> n;
	while(n--) {
		cin >> s;
		alph[s[0] - 97]++;
	}
	for(int i = 0; i < 26; i++) {
		class1 = ceil(alph[i] / 2.0);
		class2 = alph[i] / 2;
		ans += (class1 * (class1 - 1)) / 2 + (class2 * (class2 - 1) ) / 2;		
	}
	cout << ans << endl;
	
}


