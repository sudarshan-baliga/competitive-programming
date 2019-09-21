#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t, n, a[100001], xors[100001], ans, idx, sz;
    map<long long, vector<long long>> prev;
    cin >> t;
    while (t--)
    {
        cin >> n;
        ans = 0;
        prev.clear();
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        xors[0] = 0;
        for (int i = 1; i <= n; i++)
            xors[i] = xors[i - 1] ^ a[i];
        for (int i = 1; i <= n; i++)
        {
            // // check if previously occured
            // if (prev[xors[i]].size() != 0)
            // {
            //     // cout << i << endl;
            //     for (auto ele : prev[xors[i]])
            //     // if(i - ele > )
            //     {
            //         ans += i - ele;
            //     }
            // }

            //check if current xor is zero
            if (xors[i] == 0)
            {
                // cout << i << endl;
                if (i > 1)
                    ans += i - 1;
            }
            // add current xor to prev
            prev[xors[i]].push_back(i);
        }
        for (auto preState : prev)
        {
            // if(preState.second.size < 2)
            //     continue;
            idx = 1;
            sz = preState.second.size();
            for (auto itr = preState.second.begin(); itr != preState.second.end(); itr++)
            {
                ans += (idx - 1) * *itr - (sz - idx) * *itr -  (sz - idx);
                idx++;
            }
        }
        cout << ans << endl;
    }
}