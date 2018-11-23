#include <iostream>
#include <string.h>
using namespace std;

int main() {
	string s, t;
	cin >> s;
	t = s.substr(0, sizeof(s));
	cout << t;
}
