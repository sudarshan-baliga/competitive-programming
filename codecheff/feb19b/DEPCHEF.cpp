#include <iostream>
using namespace std;

int main()
{
	int t, n, a[100], d[100], prev, next, bestDef, curDef;
	bool found;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;
		for (int j = 0; j < n; j++)
			cin >> a[j];
		for (int j = 0; j < n; j++)
			cin >> d[j];
		prev = n - 1;
		next = 1;
		bestDef = -1;
		found = false;
		for (int j = 0; j < n; j++)
		{
			curDef = d[j] - a[prev] - a[next];
			if (curDef > 0 && d[j] >= bestDef)
			{
				bestDef = d[j];
				found = true;
			}
			next = (next + 1) % n;
			prev = j;
		}
		if (found)
			cout << bestDef<< endl;
		else
			cout << -1 << endl;
	}
}