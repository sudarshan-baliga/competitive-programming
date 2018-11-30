//https://codeforces.com/contest/520/problem/B
#include <iostream>
#include <queue>
using namespace std;

int bfs(int n, int m)
{
    int visited[1000000];
    fill_n(visited, 1000000, 0);
    queue<int> q;
    q.push(n);
    visited[n] = 0;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        if (cur == m)
            break;
        if (!visited[cur - 1] && cur - 1 > 0)
        {
            visited[cur - 1] = visited[cur] + 1;
            q.push(cur - 1);
        }
        if (2 * cur <= 2 * m && !visited[2 * cur])
        {
            visited[cur * 2] = visited[cur] + 1;
            q.push(2 * cur);
        }
    }
    return visited[m];
}

int main()
{
    int n, m;
    cin >> n >> m;
    cout << bfs(n, m) << endl;
}