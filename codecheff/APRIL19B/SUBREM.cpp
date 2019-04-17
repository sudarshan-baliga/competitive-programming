#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

long long t, n, x, u, v, a[100001], belowCost[100001];
bool visited[100001];

long long removeSubTree(long long node, vector<long long> tree[])
{
    long long cost;
    belowCost[node] = a[node];
    visited[node] = true;
    for (long long adjacent:tree[node])
    { 
        if(!visited[adjacent])
        {
            cost = removeSubTree(adjacent, tree);
            belowCost[node] += cost;
            visited[adjacent] = true;
        }
        // cout << "step " << node << " " <<  adjacent << " " << cost <<  " " << belowCost[node] << endl;
    }
    return max(x, belowCost[node]);
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    for(long long i  = 0; i < t; i++)
    {
        cin >> n >> x;
        x = -1 * x;
        vector<long long> tree[n + 1];
        for(long long j = 1; j <= n; j++){
            cin >> a[j];
            visited[j] = false;
            belowCost[j] = 0;
        }
        for(long long j = 0; j < n - 1; j++)
        {
            cin >> u >> v;
            tree[v].push_back(u);
            tree[u].push_back(v);
        }
        cout << removeSubTree(1, tree) << endl;
    }
}