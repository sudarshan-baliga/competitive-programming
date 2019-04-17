#include <iostream>
#include <vector>
#include <cstring>
#define MAX 1000000000
using namespace std;


int main()
{
	int n, t;
	long long second;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> n;	
		if(n % 2 )
			cout << "YES" << endl;
		else
		{
			second = (n + 1);
			for(int j = (n + 1) / 2; j >= 2; )
			{
				if( second % j == 0)
				{
						//cout << j << endl;
						second = 1;
						break;
				}
				j--;
			}
			if(second == 1)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}
}
