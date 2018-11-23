#include <iostream>
using namespace std;

int main()
{
	int t, A, B, nim;
	string s;
	cin >> t;
	while(t--)
	{
		cin >> s;
		nim = A = B = 0;
		int i = -1,j;
		for (j = 0; j < s.size(); j++)
		{
			if (s[j] == '.')
				continue;
			if (i == -1)
				i = j;
			else
			{
				if (s[j] == s[i])
				{
					if (s[j] == 'A')
						A += j - i - 1;
					else
						B += j - i - 1;
				}
				else
					nim ^= (j - i - 1);
				i = -1;
			}
		}
		if (i != -1) //case like A... which is bonus moves
			if (s[i] == 'A')
				A += j - i - 1;
			else
				B += j - i - 1;
		//if no extra moves check for nim condition
		if (A == B)
			cout << (nim != 0 ? "A\n" : "B\n");
		else
			cout << (A > B ? "A\n" : "B\n");
	}
}
