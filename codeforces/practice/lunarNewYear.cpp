// https://codeforces.com/problemset/problem/1106/D
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define N 300010

bool visited[N];
priority_queue<int, vector<int>, greater<int> > Q;

int main()
{
    int n, m, a, b;
    cin >> n >> m;
    vector<int> edges[n + 1];
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    visited[1] = true;
    Q.push(1);
    while(!Q.empty())
    {
        int u = Q.top();
        Q.pop();
        cout << u << " ";
        for(auto v : edges[u])
        {
            if(!visited[v])
            {
                visited[v] = true;
                Q.push(v);
            }
        }
    }
    cout << endl;
}