//http://codeforces.com/problemset/problem/510/B
#include <iostream>
using namespace std;

int n, m;
string a[51];
bool visited[51][51], ans;

bool checkValid(int x, int y) {
	if(x >= 0 && x < n && y >= 0 && y < m)	return true;
	return false;
}

void detectCycle(int x, int y, int preX, int preY) {
	if (a[x][y] != a[preX][preY]) return;
	if(visited[x][y]) {
		ans = true;
		return;
	}
	visited[x][y] = true;
	if (checkValid(x + 1, y) && x + 1 != preX) detectCycle(x + 1, y, x, y);
	if (checkValid(x - 1, y) && x - 1 != preX) detectCycle(x - 1, y, x, y);
	if (checkValid(x , y - 1) && y - 1 != preY) detectCycle(x, y - 1,x , y);
	if (checkValid(x , y + 1) && y + 1 != preY) detectCycle(x, y + 1, x, y);
}

int main() {
	cin >> n >> m;
	for(int i = 0; i < n; i++)
			cin >> a[i];
	ans = false;
	for(int i = 0; i < n; i++)
		for(int j = 0;j < m; j++)
			if(!visited[i][j])
				{
				 	detectCycle(i, j, i, j);
					if(ans) {
						cout << "Yes" << endl;
						return 0;
				 }
				}
	cout << "No" << endl;
}
