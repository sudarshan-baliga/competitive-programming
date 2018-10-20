#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
  cin.tie(NULL);
	long long t, n, bits, bytes, nibbles, rem, sets, ans;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> n;
		n = n - 1; 
		sets = n / 26;
		rem = n % 26;
		if( sets > 0)
			ans = pow(2,sets);
		else 
			ans = 1;
		nibbles = bytes = bits =  0;
		if(rem <= 1)
			bits = ans;
		else 
			if(rem >= 2 && rem < 10)
				nibbles =  ans;
		else 
			bytes = ans;
		cout << bits << " " << nibbles << " " << bytes << "\n"; 
	}
}
