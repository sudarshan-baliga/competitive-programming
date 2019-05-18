#include <iostream>
#include <stack>
using namespace std;

int main()
{
	int n, even = 1, idx = 0, ans = 0;
	string s;
	stack<char> stk, stk2;
	cin >> n >> s;
	while (n--)
	{
		if (even)
			stk.push(s[idx++]);
		else
		{
			if (!stk.empty() && stk.top() == s[idx])
			{
				idx++;
				ans++;
				even = (even + 1) % 2;
			}
			else
				stk.push(s[idx++]);
		}
		even = (even + 1) % 2;
	}
	if (stk.size() % 2)
	{
		ans++;
		stk.pop();
	}
	while (!stk.empty())
	{
		stk2.push(stk.top());
		stk.pop();
	}
	cout << ans << endl;
	while (!stk2.empty())
	{
		cout << stk2.top();
		stk2.pop();
	}
	cout << endl;
}