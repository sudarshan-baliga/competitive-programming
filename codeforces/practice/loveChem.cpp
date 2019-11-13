// https://codeforces.com/problemset/problem/445/B
#include <iostream>
#include <vector>
using namespace std;

bool visited[51];
vector<int> edges[51];
long long ans;
void dfs(int src)
{
    visited[src] = true;
    for (auto dst : edges[src])
    {
        if (!visited[dst]) {
            dfs(dst);
            ans *= 2;
        }
    }
}

int main()
{
    int n, m, a, b;
    cin >> n >> m;

    fill(visited, visited + n + 1, false);
    while (m--)
    {
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    int numComp = 0;
    ans = 1;
    for (int i = 1; i <= n; i++)
        if (!visited[i])
        {
            dfs(i);
        }
    cout << ans << endl;
}