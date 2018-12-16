#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define  maxn 1200000

int possible[maxn], n, mod = 1000000007;
vector<int> divisors[maxn];

int main()
{
	for(int i = 1; i < maxn; i++){
		for(int j = i; j < maxn; j += i)
				divisors[j].push_back(i);
		reverse(divisors[i].begin(), divisors[i].end());
	}
	cin >> n;
	possible[0] = 1;
	while(n--)
	{
		int a;
		cin >> a;
		for(int x : divisors[a])
		{
		possible[x] = (possible[x] + possible[x-1]) % mod;
// 		cout << x << " divof " << a << endl;
		}
	}
	int ans = 0;
	for(int i = 1; i < maxn; i++) 
          	ans = (ans + possible[i]) % mod;
	cout << ans;
	
}
