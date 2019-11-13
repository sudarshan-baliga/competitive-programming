#include <iostream>
#include <vector>
#include <cstring>
#define MAX 100001
using namespace std;

bool foundLoop, visited[MAX];
vector<pair<int, int>> loopEdges;
vector<int> edges[MAX];
vector<int> setNumber(MAX);

void dfs(int parent, int source)
{
    visited[source] = true;
    for (auto dest : edges[source])
    {
        if (!visited[dest])
            dfs(source, dest);
        else if (!foundLoop && dest != parent)
        {
            foundLoop = true;
            loopEdges.push_back({source, dest});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, n, m, u, v, culprit;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 0; i <= n; i++)
            edges[i].clear();
        for (int i = 0; i < m; i++)
        {
            cin >> u >> v;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        culprit = -1;
        if (m % 2)
        {
            for (int i = 1; i <= n; i++)
                if (edges[i].size() % 2)
                {
                    culprit = i;
                    break;
                }
        }
        if ((m % 2 && culprit != -1) || !(m % 2))
        {
            if (culprit == -1)
                cout << 1 << endl;
            else
                cout << 2 << endl;
            for (int i = 1; i <= n; i++)
            {
                if (i != culprit)
                    cout << 1 << " ";
                else
                    cout << 2 << " ";
            }
            cout << endl;
            continue;
        }
        // odd edges but there are some loops and no odd edge
        foundLoop = false;
        memset(visited, false, (n + 1));
        loopEdges.clear();
        for (int u = 1; u <= n; u++)
        {
            if (!visited[u])
                dfs(-1, u);
            foundLoop = false;
        }
        fill(setNumber.begin(), setNumber.end(), 1);
        if (loopEdges.size() % 2 == 0)
        {
            cout << 2 << endl;
            for (int i = 0; i < loopEdges.size(); i++)
            {
                setNumber[loopEdges[i].first] = 2;
                setNumber[loopEdges[i].second] = 2;
            }
        }
        else
        {
            cout << 3 << endl;
            for (int i = 0; i < loopEdges.size() - 1; i++)
            {
                setNumber[loopEdges[i].first] = 2;
                setNumber[loopEdges[i].second] = 2;
            }
            setNumber[loopEdges[loopEdges.size() - 1].first] = 2;
            setNumber[loopEdges[loopEdges.size() - 1].second] = 3;
        }
        for (int i = 1; i <= n; i++)
            cout << setNumber[i] << " ";
        cout << endl;
    }
}