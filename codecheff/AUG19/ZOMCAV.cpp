#include <iostream>
#include <cstring>
#include <map>
using namespace std;

int main()
{
    long long t, n, rad[100005], c, h;
    map<long long, long long> avail;
    bool fail;
    cin >> t;
    while (t--)
    {
        cin >> n;
        memset(rad, 0, sizeof(long long) * (n + 2));
        avail.clear();
        fail = false;
        for (int i = 1; i <= n; i++)
        {
            cin >> c;
            if (i - c >= 0)
                rad[i - c] += 1;
            else
                rad[0] += 1;
            if (i + c + 1 <= n)
                rad[i + c + 1] -= 1;
        }
        for (int i = 1; i <= n; i++)
        {
            rad[i] = rad[i] + rad[i - 1];
            // cout << rad[i] << " ";
            avail[rad[i]] += 1;
        }
        // cout << endl;
        for (int i = 0; i < n; i++)
        {
            cin >> h;
            if (fail)
                continue;
            if (avail[h])
            {
                avail[h] -= 1;
                continue;
            }
            fail = true;
        }
        if (!fail)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}