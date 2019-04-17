#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int n, rightJoker, leftJoker;
unordered_map<char, int> rightBootMap;
vector<vector<int>> rightIndex(26), leftIndex(26);
string rightBoots, leftBoots;

int solve()
{
    int ans = 0, notFound = 0;
    vector<pair<int, int>> ansPairs;
    for (char color : leftBoots)
    {
        if (color != '?')
        {
            if (rightBootMap[color] != 0)
            {
                rightBootMap[color]--;
                rightBoots[color - 97][1];
                ans++;
            }
            else if (rightJoker)
            {
                ans++;
                rightJoker--;
            }
        }
    }
    notFound = n - ans;
    if (notFound > 0 && leftJoker > 0)
    {
        if (notFound < leftJoker)
            ans += notFound;
        else
            ans += leftJoker;
    }
    return ans;
}

int main()
{
    char r, l;
    cin >> n;
    cin >> leftBoots >> rightBoots;
    for (int i = 0; i < n; i++)
    {
        l = leftBoots[i];
        if (l == '?')
            leftJoker++;
        else
            leftIndex[l - 97].push_back(i);
    }
    for (int i = 0; i < n; i++)
    {
        r = rightBoots[i];
        if (r == '?')
            rightJoker++;
        else
        {
            rightIndex[r - 97].push_back(i);
            rightBootMap[r]++;
        }
    }
    cout << solve() << endl;
}