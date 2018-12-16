// http://codeforces.com/problemset/problem/377/A
#include <iostream>
using namespace std;

int n, m, k;
string maze[501];
bool visited[501][501];

void dfs(int i, int j)
{
    if (visited[i][j])
        return;
    if (i < 0 || j < 0 || i >= n || j >= m)
        return;
    if (maze[i][j] != '.')
        return;
    visited[i][j] = true;
    dfs(i + 1, j);
    dfs(i - 1, j);
    dfs(i, j + 1);
    dfs(i, j - 1);
    if (k) maze[i][j] = 'X', k--;
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        cin >> maze[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (maze[i][j] == '.')
                dfs(i, j);
    for (int i = 0; i < n; i++)
        cout << maze[i] << endl;
}