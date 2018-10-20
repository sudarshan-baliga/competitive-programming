#include <iostream>
#include <vector>
using namespace std;

int n, m, u, v;
bool cat[100001], visited[100001] = {false}, leaf;
vector<vector<int>> tree(100001);

int dfs(int src, int catCount)
{
    if (cat[src])
        catCount++;
    else
        catCount = 0;
    if (catCount > m || visited[src] == true)
        return 0;
    visited[src] = true;
    int ans = 0;
    if (src > 1 && tree[src].size() == 1)
        return 1;
    for (auto i = tree[src].begin(); i < tree[src].end(); i++)
        ans += dfs(*i, catCount);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> cat[i];
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    cout << dfs(1, 0);
}