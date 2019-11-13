#include <iostream>
#include <vector>
using namespace std;
#define MAX 200001

vector<int> edges[MAX];
bool visited[MAX];


bool dfs(int u)
{
    bool ans = true;
    visited[u] = true;
    if(edges[u].size() != 2)    
        ans = false;
    for(auto v : edges[u])
        if(!visited[v])
            ans = ans & dfs(v);
    return ans;
}

int main()
{
    int n, m, a, b;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    int ans = 0;
    for(int u = 1; u <= n; u++)
    {
        if(!visited[u])
            ans += dfs(u);
    }
    cout << ans << endl;
}