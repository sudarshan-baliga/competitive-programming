#include <iostream>
#include <set>
#include <cmath>
using namespace std;

int t, n, a[1000], k;
long long m;
multiset<int> b;

void solve()
{
    int eleCount, extraEle, totalEle, kthPos, kthElePos, kthEle, ans = 0;
    kthElePos = k - 1;
    multiset<int>::iterator itr;
    for (int i = 0; i < n; i++)
    {
        b.clear();
        for (int j = i; j < n; j++)
        {
            for (int l = i; l <= j; l++)
                b.insert(a[l]);
            itr = b.begin();
            eleCount = (j - i + 1);
            m = ceil((double)k / eleCount);
            extraEle = k % eleCount;
            // totalEle = k + (extraEle);
            kthPos = kthElePos / m;
            kthEle = (*itr + kthPos);
            if(kthEle >= k)
            {
                ans++;
                cout << kthEle << " " << eleCount << endl;
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    char ch;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n >> k;
        for (int j = 0; j < n; j++)
            cin >> a[j];
        solve();
        cin >> ch;
    }
}
