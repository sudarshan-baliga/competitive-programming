// http://codeforces.com/problemset/problem/115/A
#include <iostream>
#include <vector>
using namespace std;

int n, temp, depth[2001],finalAns;
vector<int> boss;
vector<vector<int>> tree(2001);

int dfs(int src, int depth)
{
    int ans = depth;
    for(auto i = tree[src].begin(); i < tree[src].end(); i++){
        // cout << " parent and child " << src << ": " << *i << endl;
        ans = max(ans, dfs(*i, depth+1));
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        if (temp == -1)
            boss.push_back(i);
        else
            tree[temp].push_back(i);
    }
    for (auto i = boss.begin(); i < boss.end(); i++)
    {
        finalAns = max(dfs(*i, 1), finalAns);
    }
    cout << finalAns;
}