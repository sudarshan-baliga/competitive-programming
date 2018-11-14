#include <iostream>
#include <vector>
using namespace std;

int t, n, u, v, g, k;
vector <vector<int>> tree(100001);
int  guesses[100001], count, ans;
bool flag;


bool dfs(int src){
    vector<int>::iterator i;
    count = 0;
    for(i = tree[src].begin(); i < tree[src].end(); i++){
        if(guesses[*i] == src)
            count++;
    }
    if(count > 0)
        return true;
    return false;
}

int main()
{
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        for (int j = 0; j < n - 1; j++)
        {
            cin >> u >> v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        cin >> g >> k;
        for (int j = 0; j < g; j++)
        {
            cin >> u >> v;
            guesses[v] = u;
        }
        ans = 0;
        for(int j = 1; j <= n; j++){
            flag = dfs(j);
            if(dfs(j) >= k)
                ans++;
        }
        cout << ans << endl;
        for(int j = 1; j <= n; j++)
            tree[j].clear();
    }
}