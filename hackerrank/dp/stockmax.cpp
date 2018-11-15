#include<iostream>
using namespace std;
long long t, n, price[100000];
int starting[100000];

void findStartings()
{
	starting[0] = -1;
	for(int i = 1; i < n; i++)
	{
		int j = i - 1;
		while(price[j] < price[i] && starting[j] != -1)
			j = starting[j];
		if(price[j] > price[i])
			starting[i] = j;
		else
			starting[i] = starting[j];
	}
	for(int j = 0; j < n; j++)
		cout << starting[j] << " ";
}


long long solve()
{
	findStartings();
	long long profit = 0;
	for(int i = n - 1; i > 0;)
	{
		int end  = i;
		int start = starting[i] + 1;
		for( int j = start; j < end;j++)
		{
			profit += price[end] - price[j];
		}
		i = starting[i];
	}
	return profit;
}

int main()
{
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> n;
		for(int j = 0; j < n; j++)
			cin >> price[j];
		cout << solve() << endl;
	}
}
