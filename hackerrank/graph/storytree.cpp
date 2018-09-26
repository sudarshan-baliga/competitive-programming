#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;

int t, n, u, v, g, k, gu, gv;
vi tree[100000+7];
vector<pair<int, int>> guesses;


int dfs(int src, bool visited[]){
    visited[src] = true;
    parent
    for(i = 1; i < )
}

int main()
{
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        int parent[n + 1];
        for (int j = 0; j < n - 1; j++)
        {
            cin >> u >> v;
            tree[u].push_back(v);
            parent[v] = u;
        }
        cin >> g >> k;
        for (int j = 0; j < g; j++)
        {
            cin >> u >> v;
            guesses.push_back(make_pair(u, v));
        }
        bool visited[n+1] = {false};
        cout << dfs(1, visited) << endl;
        for(int j = 1; j <= n; j++)
            tree[j].clear();
    }
}