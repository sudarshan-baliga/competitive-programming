#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll t, n, q, x, y, s[100001], diff[100001], ans;
vector<int> pos[100001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cout << "Case " << i << ":" << endl;
        cin >> n >> q;
        for (int j = 1; j <= n; j++)
        {
            cin >> s[j];
            pos[s[j]].push_back(j);
        }
        ans = 0;
        //update the diff
        for (int j = 1; j < n; j++)
        {
            diff[j] = abs(s[j] - s[j + 1]);
            ans += diff[j];
        }

        for (int j = 1; j <= q; j++)
        {
            cin >> x >> y;
            //append all x pos to y
            pos[y].insert(pos[y].end(), pos[x].begin(), pos[x].end());
            //update the diff
            for (auto idx = pos[x].begin(); idx != pos[x].end(); idx++)
            {
                s[*idx] = y;
                if (*idx == 1)
                {
                    ans -= diff[1];
                    diff[1] = abs(s[2] - y);
                    ans += diff[1];
                    continue;
                }
                if (*idx == n)
                {
                    ans -= diff[n - 1];
                    diff[n - 1] = abs(s[n - 1] - y);
                    ans += diff[n - 1];
                    continue;
                }
                ans -= diff[*idx - 1];
                ans -= diff[*idx];
                diff[*idx - 1] = abs(s[*idx - 1] - y);
                diff[*idx] = abs(s[*idx + 1] - y);
                ans += diff[*idx - 1];
                ans += diff[*idx];
            }
            pos[x].clear();
            cout << ans << endl;
        }
        for (int j = 1; j <= 100001; j++)
            pos[j].clear();
    }
}