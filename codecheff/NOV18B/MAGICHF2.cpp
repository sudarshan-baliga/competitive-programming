#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

ll t, n, k, half1, half2;

double  find(ll n, ll k)
{
	if(k>=n)
		return 1.0;
	if(k == 0)
		return 1.0 / (double)n;
	half1 = n / 2;
	half2 = n - half1;
	return find(max(half1, half2), k - 1);
}

int main()
{
    cin >> t;
    for (int i = 0; i < t; i++)
    {
			cin >> n >> k;
			if(n == 1)
				cout << 1.0 << endl;
			else if(n == 2)
				cout << 0.5 << endl;
			else if(k == 1)
			{
				half1 = n / 2;
				half2 = n - half1;
				if(half1 % 2 && half2 % 2)
					cout << 1.0 /( max(half1, half2) + 1) << endl;
				else
					cout << 1.0 / max(half1, half2) << endl;
			}
			else
				cout << find(n, k) << endl;
    }
}
