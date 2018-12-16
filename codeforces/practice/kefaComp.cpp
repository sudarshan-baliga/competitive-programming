// https://codeforces.com/problemset/problem/580/B
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    long long n, d, cur, opti, beg, temp1, temp2;
    vector<pair<int, int>> frd;
    cin >> n >> d;
    for (int i = 0; i < n; i++)
    {
        cin >> temp1 >> temp2;
        frd.push_back(make_pair(temp1, temp2));
    }
    sort(frd.begin(), frd.end());
    beg = 0;
    cur = opti = frd[0].second;
    for (int i = 1; i < n; i++)
    {
        // cout << frd[i].first << " " << frd[beg].first << endl;
        if (frd[i].first - frd[beg].first >= d)
        {
            while (frd[i].first - frd[beg].first >= d)
            {
                cur -= frd[beg].second;
                beg++;
                // cout << beg;
            }
        }
        // cout << cur << endl;
        cur += frd[i].second;
        if (cur > opti)
            opti = cur;
    }
    cout << opti;
}