// https://codeforces.com/problemset/problem/771/A
#include <iostream>
#include <vector>
#define MAX 150001
using namespace std;

vector<int> edges[MAX];
bool visited[MAX];

void dfs(int source, int &edgeCount, int &vertextCount)
{
    vertextCount++;
    edgeCount += edges[source].size();
    visited[source] = true;
    for (auto dest : edges[source])
    {
        if (!visited[dest])
            dfs(dest, edgeCount, vertextCount);
    }
}
int main()
{
    int n, m, a, b;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            int edgeCount = 0, vertexCount = 0;
            dfs(i, edgeCount, vertexCount);
            if (edgeCount != (long long)vertexCount * (vertexCount - 1))
            {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
}