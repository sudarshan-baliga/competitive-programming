#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
int t, n, a, b;
ll ans1, ans2, ans3;
map<int, bool> visited;

ll solve(int currIndex, ll currAns)
{
    // count++;
    if (currIndex == n)
    {
        if (visited.find(currAns) == visited.end())
        {
            visited.insert(make_pair(currAns, true));
            // cout << currAns << " end " << endl;
            return 1;
        }
        return 0;
    }
    else if (visited.find(currAns) == visited.end())
    {
        visited.insert(make_pair(currAns, true));
        return 1 + solve(currIndex + 1, currAns + a) + solve(currIndex + 1, currAns - b) + solve(currIndex + 1, currAns);
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n >> a >> b;
        if (a == b)
            cout << n * 2 + 1 << endl;
        else
            cout << solve(0, 0) << endl;
        visited.clear();
        // cout << count;
    }
}