// https://codeforces.com/problemset/problem/687/A
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
vector<vector<int>> edges(10001);
int n, m, u, v;
bool colors[100001];

int markColor(int src, int color)
{
    queue<int> q;
    colors[src] = color;
    q.push(src);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << "source  color " << u << " " << colors[u] << endl;
        for (int v : edges[u])
        {
            if (colors[v] == 0)
            {
                if (colors[u] == 1)
                    colors[v] = 2;
                else
                    colors[v] = 1;
                cout << "marked " << u << " " << v << " " << colors[v] << endl;
                q.push(v);
            }
            else if (colors[v] == colors[u])
            {
                cout << u << " " << v << " " << colors[u] << endl;
                return -1;
            }
        }
    }
    return 1;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (colors[i] == 0)
        {
            int res = markColor(i, 1);
            if (res == -1)
            {
                cout << -1 << endl;
                return 0;
            }
        }
    }
}