#include<iostream>
#include<cmath>
using namespace std;

int main(){
	long long t, k, p1, p2;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		cin >> p1 >> p2 >> k;
		if((int) ceil( (p1 + p2) / k) % 2 == 0)
			cout << "CHEF\n";
		else
			cout << "COOK\n";
	}
}
