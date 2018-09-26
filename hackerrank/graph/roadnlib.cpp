#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long long _count;

class graph
{
  public:
    int v;
    list<int> *adj;
    graph(int v)
    {
        this->v = v;
        adj = new list<int>[v];
    }
    void dfs(int v, bool visited[])
    {
        _count++;
        visited[v] = 1;
        list<int>::iterator i;
        for (i = adj[v].begin(); i != adj[v].end(); i++)
        {
            if (!visited[*i])
            {
                dfs(*i, visited);
            }
        }
    }
    void addEdge(int v, int w)
    {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }
};

int main()
{
    long long t, n, m, lib, road, city1, city2, ans;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n >> m >> lib >> road;
        if (lib > road)
        {
            bool visited[n];
            for (int j = 0; j < n; j++)
                visited[j] = 0;
            graph g(n);
            ans = 0;
            for (int j = 0; j < m; j++)
            {
                cin >> city1 >> city2;
                g.addEdge(city1 - 1, city2 - 1);
            }
            for (int j = 0; j < n; j++)
            {
                _count = 0;
                if (!visited[j])
                {
                    g.dfs(j, visited);
                    ans += ((_count - 1) * road + lib); //in each component one library
                    //and all roads are sufficient && count - 1 because 2 cities 1 road
                }
            }
            cout << ans << endl;
        }
        else
        {
            for (int j = 0; j < m; j++) //temporary no use
                cin >> city1 >> city2;
            cout << n * lib << endl;
        }
    }
}
