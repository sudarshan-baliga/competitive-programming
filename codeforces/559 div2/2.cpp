#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int n, a[300001], beg, end, least, ans;

int findBestIdx(int x) {
	int beg = x, end = x;
	for(int i = 1;i <= n; i++)
		if(a[i] >= a[x]) {
			beg = i;
			break;
		}
	for(int i = n ; i > 0; i--)
		if(a[i] >= a[x]) {
			end = i;
			break;
		}
	cout << x <<  " x " <<   beg << "beg" << end << endl;
	return max(abs(x - beg), abs(x - end));
}

int main() {
	vector<int> leastIdx;
	cin >> n;
	least = INT_MAX;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(a[i] < least)
			least = a[i];
	}
	for(int i = 1; i <= n; i++)
		if(a[i] == least)
			leastIdx.push_back(i);
	int leftSide;
	ans = 0;
	for(int ele : leastIdx)
	{

		leftSide = findBestIdx(ele);
		cout << ele << " " << leftSide << endl;
		if(leftSide > least) ;
		else
			ans = max( ans, least / leftSide);
	}
	cout << ans << endl;
}
