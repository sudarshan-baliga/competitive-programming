#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
int t, n, a, b;
ll dp[1000][1000], ndp[1000][1000], count = 0; //dp[currIndex][currAns], ndp for negative possibilities
map<int, bool> visited;
ll map[10000][10000];

ll solve(int currIndex, ll currAns)
{
    count++;
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
    //if we have already reched this stage before
    if ((currAns > 0 && (dp[currIndex][currAns] == 1)) || ((dp[currIndex][abs(currAns)] == 1))){
        // cout << "Yippe previously visited " << currIndex << " " << currAns << endl; 
        return 0;
    }
    else
    {
        ll temp = solve(currIndex + 1, currAns + a) + solve(currIndex + 1, currAns - b) + solve(currIndex + 1, currAns);
        if(temp > 0)
            return dp[currIndex][currAns] = temp;
        else
            return dp[currIndex][abs(currAns)] =  temp;
    }
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
        cout <<count;
    }
}