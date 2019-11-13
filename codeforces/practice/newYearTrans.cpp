// https://codeforces.com/problemset/problem/500/B
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 1050;

int group[MAX], n, a[MAX];
string adjacency;
vector<int> pos[MAX];
int cnt[MAX];

int getGroup(int x)
{
    if(group[x] == x)   return x;
    return group[x] = getGroup(group[x]);
}

void merge(int x, int y)
{
    int a = getGroup(x);
    int b = getGroup(y);
    if(a != b)  group[a] = group[b];
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        group[i] = i;
    for(int i = 1; i <= n; i++)
    {
        cin >> adjacency;
        for(int j = 0; j < n; j++)
        {
            if(adjacency[j] == '1')
                merge(i, j + 1);
        }
    }

    for(int i = 1; i <= n; i++) pos[getGroup(i)].push_back(a[i]);
    for (int i = 1; i <= n; i++) sort(pos[i].begin(), pos[i].end());
    for(int i = 1; i <= n; i++)
    {
        int g = getGroup(i);
		printf("%d%c", pos[g][cnt[g]++], (i == n) ? '\n' : ' ');
    }
}