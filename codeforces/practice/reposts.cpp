//http://codeforces.com/problemset/problem/762/A
#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int best = 1;
map<string, vector<string>> tree;
map<string, string> parent;

void convertLower(string&  str)
{
	transform(str.begin(), str.end(), str.begin(), ::tolower);
}

void dfs(string whose,int len) {
	if(tree[whose].size() == 0) {
		best = max(best, len);
		return;
	}
	for(string who: tree[whose])
	{
		dfs(who, len + 1);
		//cout << who << " " <<tree[who].size() << endl;
	}	
}

int main() {
	int n;
	string who, temp, whose;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> who >> temp >> whose;
		//if(parent[whose] == "" && whose != "Polycarp")
		//	tree["Polycarp"].push_back(whose);
		convertLower(who);
		convertLower(whose);
		tree[whose].push_back(who);
	}
 	dfs("polycarp", 1);
	cout << best << endl;
}	
